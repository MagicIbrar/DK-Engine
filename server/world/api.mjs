import {createAdminGuildReadiness} from '../admin-guild-readiness.mjs';
import {loginChannelCatalog} from './channels.mjs';
import zlib from 'node:zlib';
import {atomicStoreDiagnostic} from '../accounts/atomic-store.mjs';
import {performance} from 'node:perf_hooks';
import {streamPressure} from './stream-pressure.mjs';
import {reserveHumanNpcSlot,canonicalNpc,npcSlotTarget} from './npc-human-slots.mjs';
import {createStreamBudget} from './stream-budget.mjs';
import {CAPACITY_DEFAULTS, runtimeMemory} from '../capacity-settings.mjs';
import {createOriginalMapEdits,originalOverlayStore} from './original-map-edits.mjs';
import {installOriginalMapWorld} from './original-map-world.mjs';
import {handleOriginalMapRequest,originalEditReadOnlyGM} from './original-map-api.mjs';
import {gmTransferAccounts} from './gm-transfer.mjs';
import {eventEntryMembers} from './events.mjs';
import {tradeAccounts} from './trade.mjs';import {charTradeAccounts} from './char-trade.mjs';
import {pcshopAccounts} from './pcshop.mjs';
import {characterRef} from '../accounts/character-ref.mjs';
import { SharedWorld, WorldError, npcOwnedEquipmentCounts } from './core.mjs';
import { loadWorldData } from './data.mjs';
import { CommandReceipts } from './replay.mjs';
import { createWorldGM } from './gm.mjs';
import { createCustomAssets } from '../custom-assets.mjs';
import {loadCustomMaps} from './custom-maps.mjs';
import {installCustomMapData} from './custom-map-data.mjs';
import {installCustomMapWorld} from './custom-map-live.mjs';
import {handleCustomMapRequest} from './custom-map-api.mjs';
import {initializeSocial} from './social-state.mjs';
import {createNpcPlayers} from './npc-players.mjs';
import {npcCapacityPolicy} from './npc-capacity-policy.mjs';
import {createNpcDormantRoster} from './npc-dormant-roster.mjs';
import {prepareNpcPopulation} from './npc-population-bootstrap.mjs';
import {createNpcSimulationDirectory} from './npc-simulation-directory.mjs';
import {npcBackgroundProfileEligible} from './npc-background-population.mjs';
import {bindAdminGuildHost} from '../admin-guild-host.mjs';
import {createAdminGuildJob} from '../admin-guild-job.mjs';
import {createNpcBackpressure} from './npc-backpressure.mjs';import {readNpcBackpressureSettings} from '../capacity-settings.mjs';

/** Whether this direct (not relayed) request accepts a gzip body (Accept-Encoding gzip with a non-zero q). */
export function acceptsGzip(req) {
  return !req.relay && /(^|[\s,])gzip(\s*;\s*q=(?!0(\.0+)?\s*(,|$))[\d.]+)?\s*(,|$)/i.test(String(req.headers['accept-encoding'] || ''));
}
/**
 * A JSON reply that carries a snapshot (join, every movement report / action, state) was a second full
 * uncompressed snapshot per command (tools/capacity-test.mjs: 106 KB/s per player beside the stream). Bodies over 1 KB are
 * gzipped off the main thread when the browser accepts it; small and relayed replies stay as they were.
 */
export function reply(req, res, status, value, sent = () => {}) {
  const text = JSON.stringify(value), headers = { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store' };
  if (text.length < 1024 || !acceptsGzip(req)) { res.writeHead(status, headers); res.end(text); sent(Buffer.byteLength(text)); return Promise.resolve(); }
  return new Promise(resolve => zlib.gzip(text, { level: 1 }, (error, body) => {
    if (!res.headersSent) {
      if (error) { res.writeHead(status, headers); res.end(text); sent(Buffer.byteLength(text)); }
      else { res.writeHead(status, { ...headers, 'Content-Encoding': 'gzip', Vary: 'Accept-Encoding', 'Content-Length': body.length }); res.end(body); sent(body.length); }
    }
    resolve();
  }));
}
/** The event stream's writer: gzip (flushed per event) when the browser accepts it and the request is direct, else the response itself. */
export function streamEncoder(req, res, sent = () => {}) {
  if (!acceptsGzip(req)) return { encoding: null, write: text => { res.write(text); sent(Buffer.byteLength(text)); }, pending: () => 0, close() {} };
  const zip = zlib.createGzip({ level: 1, flush: zlib.constants.Z_SYNC_FLUSH });
  zip.on('error', () => res.destroy());
  zip.on('data', chunk => sent(chunk.length));
  zip.pipe(res);
  return { encoding: 'gzip', write: text => zip.write(text), pending: () => zip.writableLength, close() { zip.unpipe(res); zip.destroy(); } };
}
function json(res, status, value) { res.writeHead(status, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store' }); res.end(JSON.stringify(value)); }
// ENGINE-CHOSEN admission delivery deadline matches the ordinary15s HTTP request budget.
function observeAdmissionResponse(res) {
  let resolve,timer,settled=false;
  const promise=new Promise(done=>resolve=done);
  const settle=(phase,error)=>{
    if(settled)return;settled=true;clearTimeout(timer);
    res.removeListener('finish',finished);res.removeListener('close',closed);res.removeListener('error',failed);
    resolve({phase,error});
  };
  const finished=()=>settle(res.writableFinished?'finished':'closed');
  const closed=()=>settle(res.writableFinished?'finished':'closed');
  const failed=error=>settle('error',error);
  res.once('finish',finished);res.once('close',closed);res.once('error',failed);
  timer=setTimeout(()=>{settle('timeout');res.destroy();},15000);
  return {promise,fail:failed};
}
async function body(req,limit=4096) {
  let bytes = 0; const chunks = [];
  for await (const part of req) { bytes += part.length; if (bytes > limit) throw new WorldError(413, 'World command is too large.'); chunks.push(part); }
  try { const value = JSON.parse(Buffer.concat(chunks).toString() || '{}'); if (!value || typeof value !== 'object' || Array.isArray(value)) throw new Error(); return value; }
  catch { throw new WorldError(400, 'Expected a JSON command.'); }
}

// Global ui_secondpwwnd is server-checked (stringtable_loginmsg 30:114/117): no world entry until this session passed the
// 2nd password. Only accounts the account store marks secondPwRequired are gated (owner launcher and NPC accounts are not).
export function requireSecondPw(user){if(user?.secondPwRequired===true&&user.secondPwVerified!==true){const e=new WorldError(403,'Enter your 2nd Password at character select first.');e.code=104;throw e;}}
export function createWorldApi({ resolveUser, getProfile, saveProfile, saveProfiles, getSocialState, saveSocialTransaction, renameProfile, verifyAccountPassword, listCharacters, inspectCharacter, charTransferInfo, transferCharacter, describeGMCharacter, readGMTransfer, commitGMTransfer, customAssetsRoot, customItemsFile, customMapsRoot, originalEditRoot, originalEditMapIndices=[150], launcherTools=()=>[], onClientReady=()=>false, onAuthenticated=()=>{}, data, now, random, tickMs = 100, dataRoot, gamedataRoot, capacity = CAPACITY_DEFAULTS, starterPack = () => true, fieldPk = () => true, npcPlayers=()=>false, npcPopulation=()=>100, npcOptionalWorkAllowed=()=>true, npcLanguage=()=> 'en', npcProfiles, npcRosterFile, npcRefreshGeneratedNames=false, npcNativeCapacity=null, npcInterest=false, adminGuildAccounts, npcBackpressureSettings=null, rateSettings=null } = {}) {
  // LANE1-PERF backpressure hook: created lazily the first time bots are enabled.
  let npcBackpressure=null;const backpressure=()=>{if(!npcBackpressure){npcBackpressure=createNpcBackpressure(npcBackpressureSettings||readNpcBackpressureSettings());if(world)world.npcBackpressure=npcBackpressure;}return npcBackpressure;};
  if (!resolveUser || !getProfile || !saveProfile) throw new Error('World API requires authenticated account/profile callbacks.');
  const nativeNpcCapacity=npcCapacityPolicy(npcNativeCapacity);
  // Interest-managed bots: real actors only on maps a human occupies; everyone else is background-simulated presence.
  if(npcInterest===true&&nativeNpcCapacity)throw new Error('Interest-managed bots and the native capacity tier are mutually exclusive.');
  let world, loading, stopping=false,closing,npcDirector,preparePopulation,populationPreparing=null,npcPreloading=null;
  let preparationFailed=false,preparationRetryAt=0,preparationRecoveryBlocked=false;
  let retainedPreparation=null,preparationAttempts=0,preparationScheduled=false,npcSyncing=null,preparationEpoch=0;
  const requests=new Set();
  // Private aggregate only: fixed phase names, <=64 retained observations, no identities.
  const admissionPhases=new Set(['apiQueue','authentication','coreQueue','replacementCleanup','getProfile','nativeStage','durablePersist','durableStore','coreSnapshot','onAuthenticated','scenePopulation','snapshot','delivery']);
  const admissionObservations=new Map(),admissionCompleted=[];let admissionActive=0,admissionLast=null;
  const admissionNow=()=>{const value=performance.now();return Number.isFinite(value)?value:0;};
  function beginAdmissionObservation(){
    let record=null,finished=false,counted=false;
    const phase=name=>{try{if(finished||!record||!admissionPhases.has(name))return;const at=admissionNow();record.phases[record.phase]=(record.phases[record.phase]||0)+Math.max(0,at-record.phaseAt);record.phase=name;record.phaseAt=at;}catch{}};
    const finish=ok=>{try{if(finished)return;finished=true;if(counted)admissionActive--;if(!record)return;const at=admissionNow();record.phases[record.phase]=(record.phases[record.phase]||0)+Math.max(0,at-record.phaseAt);admissionLast={ok:ok===true,durationMs:Math.round(Math.max(0,at-record.started)),phases:Object.fromEntries(Object.entries(record.phases).map(([name,ms])=>[name,Math.round(ms)]))};admissionCompleted.push(admissionLast);if(admissionCompleted.length>8)admissionCompleted.shift();admissionObservations.delete(record);}catch{if(record)admissionObservations.delete(record);}};
    try{const at=admissionNow();admissionActive++;counted=true;if(admissionObservations.size<64){record={phase:'apiQueue',phaseAt:at,started:at,phases:{}};admissionObservations.set(record,record);}}catch{}
    return {phase,finish};
  }
  function admissionTimingSnapshot(){try{const at=admissionNow();let longest=null;for(const record of admissionObservations.values()){const elapsedMs=Math.round(Math.max(0,at-record.phaseAt));if(!longest||elapsedMs>longest.elapsedMs)longest={phase:record.phase,elapsedMs};}return {current:admissionActive,tracked:admissionObservations.size,untracked:Math.max(0,admissionActive-admissionObservations.size),longestCurrent:longest,lastCompleted:admissionLast?{...admissionLast,phases:{...admissionLast.phases}}:null,recentCompleted:admissionCompleted.map(record=>({...record,phases:{...record.phases}}))};}catch{return null;}}
  const customAssets=createCustomAssets({root:customAssetsRoot});
  const runGM = createWorldGM({ gamedataRoot });
  const commands = new Map(),receipts=new CommandReceipts();
  let worldInitialized=false,humanAdmissions=0,adminGuildSetup;
  const ownerGuildReadiness=createAdminGuildReadiness();
  const admissionReadiness=user=>{const base=preparationStatus();return user.id==='admin'&&adminGuildAccounts?ownerGuildReadiness.read(base,adminGuildJob.snapshot()):base;};
  const adminGuildJob=createAdminGuildJob({shouldYield:()=>stopping||humanAdmissions>0,retryMs:3000,prepare:async yielding=>{
    if(!adminGuildAccounts)return {complete:false,reason:'private-roster-unavailable'};
    if(!worldInitialized)return {complete:false,reason:'world-not-ready'};
    if(yielding())return {complete:false,reason:'human-admission-or-host-stopping'};
    adminGuildSetup ||= bindAdminGuildHost({world,accounts:adminGuildAccounts,serialize,shouldYield:yielding,runGM,runBudgetMs:60000});
    return adminGuildSetup.run();
  }});
  let mapPublication=Promise.resolve();
  function serialize(account, fn) {
    const task = Promise.all([mapPublication,(commands.get(account) || Promise.resolve()).catch(() => {})]).then(async()=>{
      const player=world?.players.get(account);if(player)player.commandActive=(player.commandActive||0)+1;
      try{return await fn()}finally{if(player)player.commandActive=Math.max(0,(player.commandActive||1)-1)}
    });
    commands.set(account, task);
    void task.finally(() => { if (commands.get(account) === task) commands.delete(account); }).catch(() => {});
    return task;
  }
  function serializeMany(accounts,fn){
    const keys=[...new Set(accounts)].sort(),previous=keys.map(key=>(commands.get(key)||Promise.resolve()).catch(()=>{}));
    const task=Promise.all([mapPublication,...previous]).then(async()=>{const participants=keys.map(key=>world?.players.get(key)).filter(Boolean);for(const p of participants)p.commandActive=(p.commandActive||0)+1;try{return await fn()}finally{for(const p of participants)p.commandActive=Math.max(0,(p.commandActive||1)-1)}});for(const key of keys)commands.set(key,task);
    void task.finally(()=>{for(const key of keys)if(commands.get(key)===task)commands.delete(key);}).catch(()=>{});return task;
  }
  function serializeMapPublication(_account,fn){
    // Drain in-flight travel before checking occupancy. Later join/action
    // requests wait for the manifest commit so they cannot enter stale geometry.
    const task=Promise.all([mapPublication,...[...commands.values()].map(p=>p.catch(()=>{}))]).then(fn);
    mapPublication=task.catch(()=>{});return task;
  }
  function permissions(shared, user) {
    const p = shared.players.get(user.id);
    if (p) { p.capabilities = user.capabilities || []; p.gmAuthorized = p.capabilities.includes('gm:commands'); p.permissions = { role: user.role || 'player', capabilities: p.capabilities }; }
  }
  const streams = new Set();
  let streamSlot = 0;
  const joinRates = new Map();
  async function ready() {
    if(stopping)throw new WorldError(503,'The server is saving progress and stopping.');
    if(worldInitialized)return world;
    if(preparationRecoveryBlocked||preparationFailed&&Date.now()<preparationRetryAt)throw new WorldError(503,'Shared world preparation is unavailable.');
    if (!loading) loading = (async () => {
      preparationFailed=false;
      if(retainedPreparation){
        if(world!==retainedPreparation.world||npcDirector!==retainedPreparation.director)throw new WorldError(503,'Shared world preparation ownership changed.');
        world.npcPreparationPending=true;
        await preparePopulation?.();await prepareNativePopulation();
        return finishPreparation(retainedPreparation.world,retainedPreparation.director);
      }
      preparationRecoveryBlocked=false;
      const tables=data || await loadWorldData({dataRoot,gamedataRoot,customItemsFile});
      if(customMapsRoot)installCustomMapData(tables,await loadCustomMaps({root:customMapsRoot,data:tables,now}));
      world = new SharedWorld({data:tables,getProfile,saveProfile,saveProfiles,now,random,rateSettings});
      world.npcOptionalWorkAllowed=npcOptionalWorkAllowed;
      if(npcBackpressure)world.npcBackpressure=npcBackpressure;
      world.shuttingDown=stopping;
      installCustomMapWorld(world);
      if(originalEditRoot&&originalEditMapIndices.length)installOriginalMapWorld(world,createOriginalMapEdits(world,{allowedMaps:originalEditMapIndices,readOriginal:index=>tables.originalMapFiles(index),store:originalOverlayStore(originalEditRoot)}));
      world.starterPackEnabled=starterPack;   // per-server dashboard switch (Settings): does a new character get the starter kit
      world.fieldPkEnabled=fieldPk;           // per-server dashboard switch (Settings): Ctrl forced attack (PK) on open PvP fields
      world.renameProfile=renameProfile; world.verifyAccountPassword=verifyAccountPassword; world.listCharacters=listCharacters; world.inspectCharacter=inspectCharacter;world.charTransferInfo=charTransferInfo;world.transferCharacter=transferCharacter;
      world.describeGMCharacter=describeGMCharacter;world.readGMTransfer=readGMTransfer;world.commitGMTransfer=commitGMTransfer;
      world.getSocialState=getSocialState;world.saveSocialTransaction=saveSocialTransaction&&(async(transaction)=>{const saved=await saveSocialTransaction(transaction);if(saved===true&&npcProfiles?.adoptCommitted)await npcProfiles.adoptCommitted(transaction.updates||[]);return saved;});
      world.npcSocialProfileSupported=!!(saveSocialTransaction&&npcProfiles?.adoptCommitted);
      world.retryDisconnect=p=>serialize(p.account,()=>world.finishDisconnect(p,{commandAllowance:1}));
      await initializeSocial(world);
      if(npcProfiles){let roster,rosterLoading;
        world.npcPeriodicAccount=id=>npcProfiles.own(id);
        world.npcAdmissionSnapshot=rows=>npcProfiles.admissionSnapshot(rows);
        world.npcAdmissionCommit=rows=>npcProfiles.admissionCommit(rows);
        world.npcAdmissionEnabled=()=>!stopping&&npcPlayers()===true;
        world.npcJoinWave=rows=>serializeMany(rows.map(r=>r.account),()=>world.joinNpcWave(rows));
        const ensureRoster=async()=>{if(!npcRosterFile)return null;await npcProfiles.load();if(roster)return roster;if(!rosterLoading)rosterLoading=(async()=>createNpcDormantRoster({data:tables,file:npcRosterFile,count:1250,existingProfiles:npcProfiles.profiles,usedNames:(await listCharacters?.()||[]).map(p=>p.name),refreshGeneratedNames:npcRefreshGeneratedNames,refreshUnanchoredAreas:true}))().then(value=>roster=value).catch(error=>{rosterLoading=null;throw error;});return rosterLoading;};
        // First-world setup precedes human admission. Canonical character
        // creation is distinct from earned progress and physical actor joins.
        // Atomic batches and initial sync make interrupted setup resumable.
        preparePopulation=()=>{
          if(!npcPlayers()||world.npcPopulationPreparation?.complete)return Promise.resolve(world.npcPopulationPreparation);
          if(populationPreparing)return populationPreparing;
          populationPreparing=(async()=>{await npcProfiles.load();await npcDirector?.settle();const directory=await ensureRoster();if(!directory)return null;
            const release=world.acquireSceneLease(null);
            try{const prepared=await prepareNpcPopulation({world,profiles:npcProfiles,roster:directory,enabled:()=>!stopping&&npcPlayers(),allowOccupied:true,onProgress:report=>{world.npcPopulationPreparation={...report,complete:false};}});
              return world.npcPopulationPreparation=prepared;}
            finally{release();}
          })().finally(()=>{populationPreparing=null;});return populationPreparing;
        };
        if(npcPlayers())await preparePopulation();
        const simulationDirectory=()=>{const state=npcDirector?.simulationState()||{};return createNpcSimulationDirectory({profiles:npcProfiles.profiles,actors:world.players,workerIds:state.workerIds,visibleIds:state.visibleIds,queuedIds:state.queuedIds,enabled:npcPlayers,eligibility:(p,{account})=>!!npcBackgroundProfileEligible(world,account,p)||{eligible:false,reason:'native-admission-unavailable'}});};
        let censusCache=null,censusAt=0,censusSize=-1;
        // ENGINE-CHOSEN10s census cache avoids scanning2500 canonical records
        // in every native command/snapshot. It is a scheduled queue, not2500
        // connected actors or a claim that queued characters earned rewards.
        world.npcPopulationCensus=()=>{if(!npcPlayers()){censusCache=null;return null;}const at=world.now();if(!censusCache||at<censusAt||at-censusAt>=10000||censusSize!==npcProfiles.profiles.size){censusCache={...simulationDirectory().snapshot(),...(npcInterest===true?{simulated:npcDirector?.simulation?.()?.dormant??null}:{})};censusAt=at;censusSize=npcProfiles.profiles.size;}let humans=0;for(const p of world.players.values())if(!p.leaving&&!npcProfiles.own(p.account))humans++;return {enabled:true,saved:censusCache.canonicalCharacters,queued:censusCache.counts.queued,...(npcInterest===true?{simulated:censusCache.simulated}:{}),materialized:censusCache.materializedCharacters,remoteWorkers:censusCache.remoteWorkers,humans};};
        world.npcRosterPage=async fields=>{if(!npcPlayers())return {enabled:false};const directory=await ensureRoster();if(!directory)return {enabled:false};await directory.syncEarned(npcProfiles.profiles);return simulationDirectory().page(directory.page(fields));};
        npcDirector=createNpcPlayers({world,profiles:npcProfiles,dormantRoster:ensureRoster,enabled:()=>!stopping&&npcPlayers(),population:npcPopulation,language:npcLanguage,capacity:nativeNpcCapacity,background:npcInterest===true?true:null,command:(account,input)=>{
        if(input.type!=='trade')return serialize(account,()=>(world.npcAction||world.action).call(world,account,input));
        const p=world.players.get(account),keys=p?tradeAccounts(world,p,input):[account];return serializeMany(keys,()=>{if(p&&tradeAccounts(world,p,input).some(key=>!keys.includes(key)))throw new WorldError(400,'Trade membership changed.');return (world.npcAction||world.action).call(world,account,input)});
      },onError:error=>fault('NPC players',error)});
        if(nativeNpcCapacity){retainedPreparation={world,director:npcDirector};world.npcPreparationPending=true;}
        await prepareNativePopulation();}
      return finishPreparation(world,npcDirector);
    })().catch(async err => {
      worldInitialized=false;preparationFailed=true;
      if(retainedPreparation){
        // Retain earned canonical actors after native preparation begins.
        // ENGINE-CHOSEN three automatic attempts, then explicit settings retry.
        preparationAttempts++;preparationRecoveryBlocked=preparationAttempts>=3;
        preparationRetryAt=preparationRecoveryBlocked?Infinity:Date.now()+3000;
        loading=null;fault('native preparation',err);
        throw new WorldError(503,'Shared world preparation is unavailable.');
      }
      const failedWorld=world,failedDirector=npcDirector;
      try{
        await failedDirector?.close();
        try{await failedWorld?.close();}catch(error){await failedWorld?.saveQueue?.catch(()=>{});throw error;}
      }catch(cleanup){
        // Keep the rejected loading fence and the exact unsaved world. No
        // automatic replacement may discard a failed durable checkpoint.
        preparationRecoveryBlocked=true;preparationRetryAt=Infinity;
        fault('preparation cleanup',cleanup);fault('preparation',err);throw err;
      }
      if(world===failedWorld){world=null;npcDirector=null;preparePopulation=null;}
      loading=null;preparationRetryAt=Date.now()+3000;fault('preparation',err);throw err;
    });
    return loading;
  }
  function nativePreparationComplete(activeWorld,activeDirector,report){
    const target=npcSlotTarget(activeWorld,nativeNpcCapacity.actorCap);
    if(!report||report.complete!==true||report.target!==target)return false;
    const state=activeDirector.status().population,fence=state?.admissionFence;
    if(!state||state.reservedAdmissions!==0||state.admissionWavePending!==false||!Array.isArray(state.reconciliationPending)||state.reconciliationPending.length||!fence||fence.pending!==0||fence.held!==0)return false;
    let physical=0;
    for(const [account,p]of activeWorld.players){const saved=npcProfiles.profiles.get(account);
      if(/^npc_[a-f0-9]{32}$/.test(account)&&p?.account===account&&!p.leaving&&p.profile?.authority==='server'&&p.profile.npcPlayer===true&&saved?.authority==='server'&&saved.npcPlayer===true&&typeof saved.id==='string'&&p.profile.id===saved.id&&p.characterId===saved.id&&p.id===account+':'+saved.id&&Number.isInteger(p.map))physical++;
    }
    return physical===target&&fence.physical===physical;
  }
  function finishPreparation(activeWorld,activeDirector){
    if(stopping||world!==activeWorld||npcDirector!==activeDirector)throw new WorldError(503,'Shared world preparation ownership changed.');
    if(nativeNpcCapacity&&npcProfiles&&npcPlayers()&&!nativePreparationComplete(activeWorld,activeDirector,activeWorld.npcNativePreparation))throw new WorldError(503,'Shared world preparation remains incomplete.');
    activeWorld.npcPreparationPending=false;worldInitialized=true;preparationFailed=false;preparationAttempts=0;preparationRetryAt=0;
    if(adminGuildAccounts&&adminGuildJob.snapshot().phase==='deferred')adminGuildJob.request();return activeWorld;
  }
  function prepareNativePopulation(){
    if(!npcDirector||!nativeNpcCapacity)return Promise.resolve(null);
    if(npcPreloading)return npcPreloading;
    const activeWorld=world,activeDirector=npcDirector;activeWorld.npcPreparationPending=true;
    npcPreloading=(async()=>{
      await activeDirector.settle();let previous=activeDirector.status().population?.admissionFence?.physical||0;
      while(true){
        if(stopping||world!==activeWorld||npcDirector!==activeDirector)throw new WorldError(503,'Shared world preparation ownership changed.');
        if(!npcPlayers()){
          // OFF admits humans only after ordinary durable NPC departure settles.
          await activeDirector.sync();
          if(stopping||world!==activeWorld||npcDirector!==activeDirector)throw new WorldError(503,'Shared world preparation ownership changed.');
          if(!npcPlayers())return null;
        }
        // ENGINE-CHOSEN 120s observation slices; accepted IO always settles.
        const report=await activeDirector.preloadNative({wallBudgetMs:120000});
        if(stopping||world!==activeWorld||npcDirector!==activeDirector)throw new WorldError(503,'Shared world preparation ownership changed.');
        activeWorld.npcNativePreparation=report;
        if(!npcPlayers())continue;
        if(nativePreparationComplete(activeWorld,activeDirector,report))return report;
        const physical=activeDirector.status().population?.admissionFence?.physical;
        if(report?.phase!=='deadline-incomplete'||!Number.isInteger(physical)||physical<=previous||physical<=0)throw new WorldError(503,'Shared world native preparation could not advance.');
        previous=physical;
        // ENGINE-CHOSEN 1s continuation yield. No zero-delay blocked retry.
        await new Promise(resolve=>setTimeout(resolve,1000));
      }
    })().finally(()=>{npcPreloading=null;});
    return npcPreloading;
  }
  function preparationStatus() {
    if(stopping)return {ready:false,phase:'failed',retryAfterMs:0,error:'The server is saving progress and stopping.'};
    if(worldInitialized)return {ready:true,phase:'ready',retryAfterMs:0,joinTimeoutMs:nativeNpcCapacity&&npcPlayers()===true?120000:15000};
    if(!loading&&!preparationScheduled&&!preparationRecoveryBlocked&&Date.now()>=preparationRetryAt){
      // GET schedules the one same-world fence; no actor lease or join here.
      preparationScheduled=true;
      void Promise.resolve().then(()=>stopping?null:ready()).finally(()=>{preparationScheduled=false;}).catch(()=>{});
    }
    return {ready:false,phase:preparationFailed?'failed':'preparing',retryAfterMs:1000,...(preparationFailed?{error:preparationRecoveryBlocked?'Shared world preparation needs an explicit settings retry.':'Shared world preparation failed. Retrying shortly.'}:{})};
  }
  // Upload budget + player cap (server/capacity-settings.mjs, stream-budget.mjs)
  const budget = createStreamBudget({ uploadMbps: capacity.uploadMbps, share: capacity.uploadShare, tickMs });
  let maxPlayers = Number(capacity.maxPlayers) > 0 ? Number(capacity.maxPlayers) : CAPACITY_DEFAULTS.maxPlayers, tickCount = 0;
  const sent = bytes => budget.count(bytes);
  // A moving client reports every 100 ms and every reply was one more full snapshot (as large as the stream itself;
  // tools/capacity-test.mjs --upload). While the upload budget already slows the stream, a movement report on a live event
  // stream is answered with a receipt only: the client applies snapshots only from replies that carry them
  // (src/systems/network/client.js action), and its movement acks come from the stream (movement-sync.js). At full rate, for
  // every other command, for polling / relay clients and for stop (client.js stop reads self) nothing changes.
  function lightMoveReply(command, result, account) {
    if (command?.type !== 'move' || budget.divisor === 1 || !result || typeof result !== 'object' || result.error) return result;
    const player = world?.players.get(account);
    if (!player || player.transport === 'polling' || ![...streams].some(s => s.account === account && s.token === player.token && !s.res.writableEnded)) return result;
    return { ok: true, receipt: true, sequence: result.sequence, serverTime: result.serverTime, ...(result.superseded ? { superseded: true } : {}), ...(result.replayed ? { replayed: true } : {}) };
  }
  // An exception thrown inside this timer used to end the whole server process for every player (found by
  // tools/capacity-test.mjs --dungeon all). A failing tick or one player's failing snapshot is now logged (at most once a
  // minute per message) and the world keeps running; that player's stream is closed so the client reconnects.
  const faults = new Map();
  const fault = (where, error) => { const key = where + ':' + (error?.message || error), at = Date.now(); if (at - (faults.get(key) || 0) < 60000) return; faults.set(key, at); if (faults.size > 200) faults.clear(); console.error(`[world] ${where} failed; the world keeps running:`, error?.stack || error); };
  // 2.2.1 server load: the tick and the snapshot broadcast no longer run as one block. Commands that arrived meanwhile are
  // answered between the tick and the broadcast and between broadcast slices of about BROADCAST_SLICE_MS, so a command waits at
  // most one slice instead of the whole tick + broadcast (44-60 ms with 100 players / 10,000 monsters, measured -
  // that wait was the ping's p95). Slices are timed, not counted: fixed 16-stream slices added event-loop turns to every reply
  // (dungeon ping p50 4 -> 12 ms). Each slice is its own snapshot scope (row caches); a new tick waits until the broadcast ended.
  const BROADCAST_SLICE_MS = 8;
  // lane-perf: SSE row deltas (unchanged players/monsters rows sent as their id; DK_ROWS_DELTA=1 enables).
  const ROWS_DELTA = process.env.DK_ROWS_DELTA === '1';   // default OFF until an idle-box CPU check shows no regression   // ENGINE-CHOSEN
  let broadcasting = false;
  const timer = setInterval(() => {
    if (!world||!worldInitialized||stopping||broadcasting) return;
    const began = performance.now(); tickCount++;
    try { world.tick(); } catch (error) { fault('tick', error); }
    if(npcDirector&&npcPlayers())backpressure().sample(); // LANE1-PERF backpressure hook
    if(npcDirector&&!populationPreparing&&!npcPreloading)void npcDirector.tick();
    let busy = performance.now() - began;
    const list = [...streams]; let next = 0; broadcasting = true;
    const slice = () => {
      if (!world || stopping) { broadcasting = false; return; }
      const at = performance.now();
      try { next = broadcastSlice(list, next, at + BROADCAST_SLICE_MS); } catch (error) { fault('broadcast', error); next = list.length; }
      busy += performance.now() - at;
      if (next < list.length) setImmediate(slice);
      else { broadcasting = false; budget.work(busy); budget.update(); }
    };
    setImmediate(slice);
  }, tickMs);
  /** Snapshots for list[from..] until the deadline (at least one stream per slice); returns the next index. */
  function broadcastSlice(list, from, deadline) {
    let i = from;
    world.withSnapshotBroadcast(()=>{for (; i < list.length && (i === from || performance.now() < deadline); i++) {
      const stream = list[i];
      if (!streams.has(stream)) continue;
      const player = world.players.get(stream.account);
      if (!player || player.leaving || player.token !== stream.token) { stream.res.end(); streams.delete(stream); continue; }
      // Slow clients cannot accumulate unlimited buffered snapshots.
      const pressure=streamPressure(stream,stream.res.writableLength+stream.out.pending(),performance.now());
      if(pressure==='close'){stream.res.destroy();streams.delete(stream);continue;}
      player.lastSeen = world.now();
      if(pressure==='wait')continue;
      if (!budget.due(tickCount, stream.slot)) continue;   // a slower snapshot rate while over the upload / work budget
      let text;
      try { text = `event: snapshot\ndata: ${world.snapshotText ? world.snapshotText(player, ROWS_DELTA ? (stream.rowCache ??= { key: `${stream.slot}`, rows: { players: new Map(), monsters: new Map() } }) : null) : JSON.stringify(world.snapshot(player))}\n\n`; } catch (error) { fault('snapshot', error); stream.res.end(); streams.delete(stream); continue; }
      stream.out.write(text);
    }});
    return i;
  }
  timer.unref?.();
  const sessionTimer = setInterval(() => {
    if(stopping)return;
    for (const stream of streams) if (!stream.checking) {
      stream.checking = true;
      void resolveUser(stream.req).then(user => {
        if (!user || user.id !== stream.account) {
          stream.res.end();streams.delete(stream);
          return disconnectAccount(stream.account,stream.token);
        }
        permissions(world, user);
      }).catch(() => { stream.res.end(); streams.delete(stream); }).finally(() => { stream.checking = false; });
    }
  }, 5000);
  sessionTimer.unref?.();
  async function disconnectAccount(account,token=null) {
    for (const stream of streams) if (stream.account === account&&(!token||stream.token===token)) { stream.res.end(); streams.delete(stream); }
    if(stopping)return; // The shutdown drain already saves and revokes every lease.
    const p=world?.players.get(account);if(!p||(token&&p.token!==token))return;
    // Revoke immediately, then drain accepted commands and retained earned work.
    // Capture this actor so a queued invalidation can never target a replacement.
    p.revoked=true;p.leaving=true;p.lastSave=world.now();
    return serialize(account,()=>world.finishDisconnect(p,{commandAllowance:1}));
  }
  return {
    ready,
    preparationStatus(){
      const state=preparationStatus();let progress=null;
      if(nativeNpcCapacity&&npcProfiles&&npcPlayers()&&world&&npcDirector){
        let admitted=0;
        for(const [account,p]of world.players){const saved=npcProfiles.profiles.get(account);
          if(/^npc_[a-f0-9]{32}$/.test(account)&&p?.account===account&&!p.leaving&&p.profile?.authority==='server'&&p.profile.npcPlayer===true&&saved?.authority==='server'&&saved.npcPlayer===true&&typeof saved.id==='string'&&p.profile.id===saved.id&&p.characterId===saved.id&&p.id===account+':'+saved.id&&Number.isInteger(p.map))admitted++;
        }
        if(admitted<=nativeNpcCapacity.actorCap)progress={admitted,target:nativeNpcCapacity.actorCap};
      }
      return {...state,progress};
    },

    requestAdminGuild(){ownerGuildReadiness.reset();return adminGuildJob.request();},
    get adminGuildReport(){return adminGuildJob.snapshot();},
    get world() { return world; },
    get npcDirector(){return npcDirector;},
    syncNpcPlayers(){
      if(npcSyncing)return npcSyncing;
      npcSyncing=(async()=>{
      if(stopping)throw new WorldError(503,'The server is saving progress and stopping.');
      if(!nativeNpcCapacity||!retainedPreparation){await ready();await preparePopulation?.();await prepareNativePopulation();return npcDirector?.sync();}
      if(world!==retainedPreparation.world||npcDirector!==retainedPreparation.director)throw new WorldError(503,'Shared world preparation ownership changed.');
      worldInitialized=false;world.npcPreparationPending=true;preparationEpoch++;
      // OFF wakes a running observation after accepted IO; never replace actors.
      if(loading)await loading.catch(()=>{});
      if(stopping||world!==retainedPreparation.world||npcDirector!==retainedPreparation.director)throw new WorldError(503,'Shared world preparation ownership changed.');
      worldInitialized=false;loading=null;preparationFailed=false;preparationRecoveryBlocked=false;preparationAttempts=0;preparationRetryAt=0;
      await ready();return npcDirector?.status();
      })().finally(()=>{npcSyncing=null;});return npcSyncing;
    },
    disconnectAccount,
    /** Live numbers for the dashboard: players, cap, upload budget / sent, snapshot rate, work per tick, memory. */
    capacity() {
      const players = world ? [...world.players.values()].filter(p => !p.leaving).length : 0, state = budget.state();
      return { players, maxPlayers, ...state, npcBackpressure:npcBackpressure?.state()||null, preparing:!worldInitialized||!!populationPreparing||!!npcPreloading||!!world?.npcHumanReservations?.size, npcCanonicalPreparing:!worldInitialized||!!populationPreparing, perPlayerKBps: players ? Math.round(state.sentKBps / players) : null, memory: runtimeMemory(), npcEquipment:npcOwnedEquipmentCounts(world,npcProfiles), npcActivity:npcDirector?.activity()||null, storeWriter:atomicStoreDiagnostic(), admission:admissionTimingSnapshot(), saveFlights:Number.isFinite(world?._saveFlights)?world._saveFlights:0 };
    },
    /** Apply new cap / upload settings to the running server (memory needs a restart: it is the process limit). */
    setCapacity(settings) {
      if (Number(settings?.maxPlayers) > 0) maxPlayers = Number(settings.maxPlayers);
      budget.configure(settings?.uploadMbps, settings?.uploadShare);
    },
    async evictCharacter(account, characterId) { if (world?.players.get(account)?.characterId === characterId) await disconnectAccount(account); },
    async close() {
      if(closing)return closing;
      stopping=true;
      npcBackpressure?.close();
      // Accepted dungeon dialogs can await a gauge that normally completes on
      // world ticks. Ticks stop during drain, so cancel the gauge through its
      // native false result; never manufacture completion or objective progress.
      if(world){world.shuttingDown=true;for(const instance of world.instances?.values()||[])for(const channel of [...(instance.channels||[])])channel.resolve(false);}
      closing=(async()=>{
        await adminGuildJob.close();
        await Promise.allSettled([...requests]);
        await Promise.allSettled([...commands.values()]);
        if(loading)await loading.catch(()=>{});
        if(npcSyncing)await npcSyncing.catch(()=>{});
        if(populationPreparing)await populationPreparing;
        if(npcPreloading)await npcPreloading;
        await npcDirector?.close();
        try{await world?.close();}catch(error){await world?.saveQueue?.catch(()=>{});throw error;}
        clearInterval(timer);clearInterval(sessionTimer);
        for(const stream of streams)stream.res.end();streams.clear();
      })().catch(error=>{stopping=false;if(world)world.shuttingDown=false;closing=null;throw error;});
      return closing;
    },
    async handle(req, res, pathname) {
      if (!pathname.startsWith('/api/world/')) return false;
      if(npcBackpressure&&pathname!=='/api/world/events'){const began=performance.now();res.once('finish',()=>npcBackpressure.recordHuman(performance.now()-began));} // LANE1-PERF backpressure hook
      if(stopping){json(res,503,{error:'The server is saving progress and stopping.'});return true;}
      let finished,admitting=false,joinIntent;const pending=new Promise(resolve=>{finished=resolve});requests.add(pending);
      const admissionCancelled=()=>req.aborted===true||res.destroyed===true;
      const requireAdmission=()=>{if(stopping)throw new WorldError(503,'The server is saving progress and stopping.');if(admissionCancelled())throw new WorldError(499,'The joining client disconnected.');};
      try {
        const origin = req.headers.origin;
        let originValid=true;if(origin){try{originValid=new URL(origin).host===req.headers.host;}catch{originValid=false;}}if(!originValid||req.headers['sec-fetch-site']==='cross-site')throw new WorldError(403,'Cross-origin world access is not allowed.');
        const user = await resolveUser(req);
        if (!user?.id) throw new WorldError(401, 'Log in before joining the shared world.');
        if(pathname==='/api/world/ready'){
          if(req.method!=='GET')throw new WorldError(405,'World readiness requires GET.');
          if(new URL(req.url,'http://localhost').search)throw new WorldError(400,'World readiness accepts no parameters.');
          json(res,200,admissionReadiness(user));return true;
        }
        if(pathname==='/api/world/channels'){
          if(req.method!=='GET')throw new WorldError(405,'Channel listing requires GET.');
          if(new URL(req.url,'http://localhost').search)throw new WorldError(400,'Channel listing accepts no parameters.');
          json(res,200,loginChannelCatalog(world||{data:data||{dataRoot,gamedataRoot}}));return true;
        }
        if(req.method==='POST'&&pathname==='/api/world/join'){
          requireAdmission();
          requireSecondPw(user);
          if(!String(req.headers['content-type']||'').startsWith('application/json'))throw new WorldError(415,'Use application/json.');
          joinIntent=await body(req,4096);
          if(Object.keys(joinIntent).some(k=>!['characterId','channel','cursorVersion'].includes(k)))throw new WorldError(400,'Join accepts a server character ID, optional field channel and cursor protocol version.');
          if(joinIntent.cursorVersion!==undefined&&joinIntent.cursorVersion!==1)throw new WorldError(400,'Unsupported inventory cursor protocol.');
          if(Object.hasOwn(joinIntent,'channel')&&!Number.isInteger(joinIntent.channel))throw new WorldError(400,'Choose a field channel listed by this server.');
          if(typeof joinIntent.characterId!=='string'||!/^[a-zA-Z0-9_-]{1,100}$/.test(joinIntent.characterId))throw new WorldError(400,'Choose a server character.');
          if(user.id==='admin'&&adminGuildAccounts){const readiness=admissionReadiness(user);if(!readiness.ready)throw Object.assign(new WorldError(503,readiness.error||'Preparing the owner guild before world admission. Retry readiness shortly.'),{code:'WORLD_BUSY'});}
          requireAdmission();humanAdmissions++;admitting=true;
        }
        if(joinIntent)requireAdmission();
        const shared = await ready(),preparedEpoch=preparationEpoch;
        if(joinIntent)requireAdmission();
        permissions(shared, user);
        if(await handleOriginalMapRequest({req,res,pathname,user,world:shared,resolveUser,serialize:serializeMapPublication}))return true;
        if(await handleCustomMapRequest({req,res,pathname,user,world:shared,library:shared.data.customMaps,resolveUser,serialize:serializeMapPublication}))return true;
        if(req.method==='POST'&&pathname==='/api/world/custom-assets'){
          if(!user.capabilities?.includes('gm:commands'))throw new WorldError(403,'GM permission is required to upload equipment models.');
          if(!/^model\/gltf-binary(?:;|$)/i.test(req.headers['content-type']||''))throw new WorldError(415,'Export Meshy equipment as GLB with embedded textures.');
          const chunks=[];let bytes=0;for await(const chunk of req){bytes+=chunk.length;if(bytes>32*1024*1024)throw new WorldError(413,'GLB exceeds32MiB.');chunks.push(chunk);}
          const result=await serialize(user.id,async()=>{const current=await resolveUser(req);if(!current||current.id!==user.id||!current.capabilities?.includes('gm:commands'))throw new WorldError(401,'Sign in again before uploading.');try{return await customAssets.put(Buffer.concat(chunks));}catch(error){throw new WorldError(400,error.message);}});
          json(res,200,result);
        }else if(req.method==='GET'&&/^\/api\/world\/custom-assets\/[a-f0-9]{64}\.glb$/.test(pathname)){
          const hash=pathname.split('/').at(-1).slice(0,-4);let bytes;try{bytes=await customAssets.get(hash);}catch(error){throw new WorldError(error.code==='ENOENT'?404:400,'Custom equipment asset unavailable.');}
          res.writeHead(200,{'Content-Type':'model/gltf-binary','Cache-Control':'private, max-age=31536000, immutable','X-Content-Type-Options':'nosniff'});res.end(bytes);
        }else if(req.method==='GET'&&pathname==='/api/world/launcher-tools'){
          const token=new URL(req.url,'http://localhost').searchParams.get('token');
          const p=shared.lease(user.id,token);
          if(!user.capabilities?.includes('gm:panel'))throw new WorldError(403,'GM builder permission is required.');
          json(res,200,{commands:launcherTools(user.id,p.token)});
        }else if(req.method==='GET'&&pathname==='/api/world/customitems'){
          const library=shared.data.customLibrary;json(res,200,{revision:library?.revision||0,items:library?.list()||[]});
        }else if (req.method === 'GET' && ['/api/world/events', '/api/world/state'].includes(pathname)) {
          const query = new URL(req.url, 'http://localhost'), token = query.searchParams.get('token');
          const p = shared.lease(user.id, token);
          if (pathname.endsWith('/state')) await reply(req, res, 200, shared.snapshot(p), sent);
          else {
            for (const other of streams) if (other.account === user.id) { other.res.end(); streams.delete(other); }
            req.socket?.setNoDelay?.(true); // MOVE-NO-RUBBERBAND: every 100ms snapshot leaves immediately (no Nagle)
            // A snapshot is repetitive JSON (field names, the same rows tick after tick) and was the host's whole upload
            // (tools/capacity-test.mjs: 684 KB/s per player, 280 Mbps for 50). One gzip stream per client, flushed after every
            // event, so each snapshot still leaves at once; the browser decompresses it in its network stack (no client change).
            // Not through the online relay (its own transport).
            const out = streamEncoder(req, res, sent);
            res.writeHead(200, { 'Content-Type': 'text/event-stream', 'Cache-Control': 'no-store', Connection: 'keep-alive', 'X-Accel-Buffering': 'no', ...(out.encoding ? { 'Content-Encoding': out.encoding, Vary: 'Accept-Encoding' } : {}) });
            out.write(`event: snapshot\ndata: ${JSON.stringify(shared.snapshot(p))}\n\n`);
            const stream = { req, res, out, account: user.id, token, checking: false, slot: streamSlot++ }; streams.add(stream);
            res.on('close', () => { streams.delete(stream); out.close(); });
          }
        } else if (req.method === 'POST') {
          if (!String(req.headers['content-type'] || '').startsWith('application/json')) throw new WorldError(415, 'Use application/json.');
          const command = joinIntent || await body(req,pathname==='/api/world/gm'&&user.capabilities?.includes('gm:commands')?256000:4096);
          if (pathname === '/api/world/client-ready') {
            if (!user.capabilities?.includes('gm:panel')) throw new WorldError(403, 'GM builder permission is required.');
            if (Object.keys(command).some(k => !['token','ready','map','sequence'].includes(k)) || typeof command.ready !== 'boolean' || !Number.isInteger(command.map) || command.map < 0 || command.map > 1000000 || !Number.isSafeInteger(command.sequence) || command.sequence < 1) throw new WorldError(400, 'Invalid game readiness notice.');
            const player=shared.lease(user.id,command.token),time=shared.now();
            if(time-(player.readyRateAt||0)>=1000){player.readyRateAt=time;player.readyNotices=0;}
            if((player.readyNotices=(player.readyNotices||0)+1)>5)throw new WorldError(429,'Too many readiness notices.');
            if(command.ready && (player.map !== command.map || player.sceneTransition)) throw new WorldError(409, 'Wait for the current map to load.');
            json(res,200,{ready:!!await onClientReady(user.id,player.token,command.ready,command.map,command.sequence)});
          } else if (pathname === '/api/world/join') {
            requireSecondPw(user);
            if (Object.keys(command).some(k => !['characterId','channel','cursorVersion'].includes(k))) throw new WorldError(400, 'Join accepts a server character ID, optional field channel and cursor protocol version.');
            if(command.cursorVersion!==undefined&&command.cursorVersion!==1)throw new WorldError(400,'Unsupported inventory cursor protocol.');
            const clock = Date.now(), rate = joinRates.get(user.id) || { at: clock, count: 0 };
            if (clock - rate.at > 60000) { rate.at = clock; rate.count = 0; }
            if (++rate.count > 20) throw new WorldError(429, 'Too many joins. Try again in a minute.');
            joinRates.set(user.id, rate);
            const admissionObservation=beginAdmissionObservation();let admissionCompleted=false;
            const admissionWorld=npcInterest===true&&npcPlayers()===true?shared:null;
            if(admissionWorld)admissionWorld.npcHumanJoining=(admissionWorld.npcHumanJoining||0)+1;
            try{await serialize(user.id, async () => {
              admissionObservation.phase('authentication');
              const requirePreparedAdmission=()=>{requireAdmission();if(!worldInitialized||world!==shared||shared.npcPreparationPending===true||preparationEpoch!==preparedEpoch)throw new WorldError(503,'Shared world preparation remains incomplete.');};
              requirePreparedAdmission();
              const current=await resolveUser(req);
              requirePreparedAdmission();
              if(!current||current.id!==user.id)throw new WorldError(401,'Your account session expired.');
              // One live client per account. A client is live while its event stream is open, while it is polling
              // (relay transport), or just after joining (before its stream opens). A closed tab, crash or page reload
              // leaves no live connection, so its reconnect replaces the stale actor (core _join saves it first).
              const existing=shared.players.get(current.id),now=shared.now();
              const live=existing&&!existing.leaving&&([...streams].some(s=>s.account===current.id&&s.token===existing.token&&!s.res.writableEnded)
                ||(existing.transport==='polling'&&now-(existing.lastSeen||0)<10000)||now-(existing.joinedAt??-Infinity)<4000);
              if(live) throw new WorldError(409, "This account already has a game client connected. Leave that game before joining again.");
              // The owner's player cap and the upload budget (players already inside keep playing; the owner / GM
              // accounts can always enter their own world)
              if(!current.capabilities?.includes('gm:commands')){
                const others=[...shared.players.values()].filter(q=>!q.leaving&&!canonicalNpc(q)&&q.account!==current.id).length;
                if(others>=maxPlayers)throw new WorldError(503,`This server is full (${others}/${maxPlayers} players). Try again soon.`);
                if(budget.full)throw new WorldError(503,'This server is at its upload limit right now. Try again in a minute.');
              }
              requirePreparedAdmission();
              admissionObservation.phase('coreQueue');
              if([...shared.players.values()].some(canonicalNpc)){
                const requestedProfile=await getProfile(current.id,command.characterId);
                if(requestedProfile?.id!==command.characterId||requestedProfile.authority!=='server')throw new WorldError(403,'Choose a server character before replacing a bot slot.');
                requirePreparedAdmission();
              }
              const releaseNpcSlot=await reserveHumanNpcSlot(shared,current.id,{maxHumans:current.capabilities?.includes('gm:commands')?Infinity:maxPlayers});
              let joined;
              try{requirePreparedAdmission();joined=await shared.join(current.id,command.characterId,admissionObservation.phase,command.channel,command.cursorVersion);}finally{releaseNpcSlot();}
              const actor=shared.players.get(current.id);
              let cancellationCleanupStarted=false;
              const releaseCancelledAdmission=async()=>{
                if(cancellationCleanupStarted)return;cancellationCleanupStarted=true;
                if(actor&&actor.token===joined.token&&shared.players.get(current.id)===actor){
                  actor.revoked=true;actor.leaving=true;actor.lastSave=shared.now();
                  // Core's separate account queue; never recursively enter API serialize.
                  await shared.finishDisconnect(actor,{commandAllowance:1});
                }
              };
              try{
                requirePreparedAdmission();permissions(shared,current);
                if(!actor||actor.token!==joined.token)throw new WorldError(409,'Your world lease changed before admission.');
                actor.joinedAt=shared.now();actor.transport=req.relay?.transport==='polling'?'polling':'sse';
                admissionObservation.phase('onAuthenticated');
                await onAuthenticated(current.id);requirePreparedAdmission();
                if(npcInterest===true&&npcPlayers()===true&&npcDirector&&shared.players.get(current.id)===actor){
                  admissionObservation.phase('scenePopulation');
                  await npcDirector.primeScene(actor);
                  requirePreparedAdmission();
                }
                admissionObservation.phase('snapshot');
                const result={...joined,transport:actor.transport,self:shared.publicPlayer(actor,true),state:shared.snapshot(actor)};
                // Register BEFORE end/gzip; reply() resolves before the transport actually finishes.
                admissionObservation.phase('delivery');
                const delivery=observeAdmissionResponse(res);
                const writing=Promise.resolve().then(()=>reply(req,res,200,result,sent)).catch(error=>delivery.fail(error));
                const outcome=await delivery.promise;
                if(outcome.phase!=='finished'){
                  await releaseCancelledAdmission();
                  if(outcome.error)throw outcome.error;
                  throw new WorldError(outcome.phase==='timeout'?503:499,outcome.phase==='timeout'?'World admission response timed out.':'The joining client disconnected.');
                }
                await writing;
              }catch(error){
                if(!res.writableFinished)await releaseCancelledAdmission();
                throw error;
              }
            });admissionCompleted=true;}finally{if(admissionWorld)admissionWorld.npcHumanJoining=Math.max(0,(admissionWorld.npcHumanJoining||1)-1);admissionObservation.finish(admissionCompleted);}
          } else if (pathname === '/api/world/action' || pathname === '/api/world/gm') {
            const selected=user.capabilities?.includes('gm:commands') && ['renamePlayer','playerCommand','inspectInventory','gearSet'].includes(command.operation) ? [...shared.players.values()].find(p=>!p.leaving&&(command.targetId ? p.id===command.targetId : command.operation==='inspectInventory'&&characterRef(p.account,p.characterId)===command.ref)) : null;
            const transferKeys=pathname.endsWith('/gm')&&command.operation==='takeInventoryItem'?await gmTransferAccounts(shared,user,command):null;
            const entryPlayer=['event','dungeon'].includes(command.type)&&command.operation==='enter'?shared.lease(user.id,command.token):null;
            const entryParticipants=entryPlayer?eventEntryMembers(shared,entryPlayer):null;
            const entryAccounts=entryParticipants?.map(p=>p.account)||null;
            const tradePlayer=pathname.endsWith('/action')&&['trade','cursor'].includes(command.type)?shared.lease(user.id,command.token):null;
            const tradeKeys=tradePlayer?tradeAccounts(shared,tradePlayer,command):null;
            // CHAR-TRADE: a character transfer writes both accounts in one store transaction; serialize both.
            const charTradePlayer=pathname.endsWith('/action')&&['chartrade','cursor'].includes(command.type)?shared.lease(user.id,command.token):null;
            const charTradeKeys=charTradePlayer?charTradeAccounts(shared,charTradePlayer,command):null;
            // A personal shop purchase commits buyer and seller together; serialize both accounts like a trade.
            const shopPlayer=pathname.endsWith('/action')&&command.type==='pcshop'&&command.operation==='buy'?shared.lease(user.id,command.token):null;
            const shopKeys=shopPlayer?pcshopAccounts(shared,shopPlayer,command):null;
            const cursorKeys=command.type==='cursor'?[...new Set([...(tradeKeys||[]),...(charTradeKeys||[])])].sort():null;
            const schedule=transferKeys?fn=>serializeMany(transferKeys,fn):cursorKeys?fn=>serializeMany(cursorKeys,fn):tradeKeys?fn=>serializeMany(tradeKeys,fn):charTradeKeys?fn=>serializeMany(charTradeKeys,fn):shopKeys?fn=>serializeMany(shopKeys,fn):entryAccounts?fn=>serializeMany(entryAccounts,fn):fn=>serialize(selected?.account||user.id,fn);
            const result = await schedule(async () => {
              const current = await resolveUser(req);
              if (!current || current.id !== user.id) throw new WorldError(401, 'Your account session expired.');
              permissions(shared, current);
              if(tradeKeys&&tradeAccounts(shared,tradePlayer,command).some(key=>!tradeKeys.includes(key)))throw new WorldError(400,'Trade membership changed. Review the current trade.');
              if(charTradeKeys&&charTradeAccounts(shared,charTradePlayer,command).some(key=>!charTradeKeys.includes(key)))throw new WorldError(400,'Character transfer membership changed. Review the current transfer.');
              if(shopKeys&&pcshopAccounts(shared,shopPlayer,command).some(key=>!shopKeys.includes(key)))throw new WorldError(400,'No such shop exists.');
              if(entryParticipants){const currentMembers=eventEntryMembers(shared,entryPlayer);if(currentMembers.length!==entryParticipants.length||currentMembers.some(p=>!entryParticipants.includes(p)||shared.players.get(p.account)!==p))throw new WorldError(409,'Party membership changed. Choose entry again.');}
              const player=shared.lease(current.id,command.token),alsoActor=selected&&selected!==player;if(alsoActor)player.commandActive=(player.commandActive||0)+1;
              try{return await receipts.execute({player,headers:req.headers,pathname,command,now:shared.now(),snapshot:()=>shared.snapshot(player),dispatch:async()=>{if(pathname.endsWith('/gm')&&!current.capabilities?.includes('gm:commands'))throw new WorldError(403,'This account does not have GM permission.');if(pathname.endsWith('/gm')&&shared.originalMapEdits?.active&&!originalEditReadOnlyGM(command))throw Object.assign(new WorldError(409,'Finish the shared original brush session before other GM mutations.'),{code:'WORLD_BUSY'});if(pathname.endsWith('/gm')&&!originalEditReadOnlyGM(command)&&[player,selected].filter(Boolean).some(p=>p.sceneTransition||p.progressCommitting))throw Object.assign(new WorldError(409,'Wait for the current map or reward save to finish.'),{code:'WORLD_BUSY'});
                const mapChanging=pathname.endsWith('/action')&&['travel','npctravel','revive','event','dungeon','channel'].includes(command.type),beforeScene=mapChanging?[player.map,player.instanceId||null,player.channel||0]:null;
                if(mapChanging&&npcInterest===true&&npcPlayers()===true)shared.npcHumanJoining=(shared.npcHumanJoining||0)+1;
                try{const result=await (pathname.endsWith('/gm')?runGM(shared,current,command,null,{req,revalidate:()=>resolveUser(req)}):shared.action(current.id,command));
                  if(mapChanging&&npcInterest===true&&npcPlayers()===true&&npcDirector&&shared.players.get(player.account)===player&&(player.map!==beforeScene[0]||(player.instanceId||null)!==beforeScene[1]||(player.channel||0)!==beforeScene[2])){
                    await npcDirector.primeScene(player);
                    return {...result,self:shared.publicPlayer(player,true),state:shared.snapshot(player)};
                  }
                  return result;
                }finally{if(mapChanging&&npcInterest===true&&npcPlayers()===true)shared.npcHumanJoining=Math.max(0,(shared.npcHumanJoining||1)-1);}
              }})}finally{if(alsoActor)player.commandActive=Math.max(0,(player.commandActive||1)-1)}
            });
            await reply(req, res, 200, lightMoveReply(command, result, user.id), sent);
          }
          else if (pathname === '/api/world/leave') { await serialize(user.id, () => shared.leave(user.id, command.token)); json(res, 200, { ok: true });if(adminGuildAccounts)adminGuildJob.request(); }
          else throw new WorldError(404, 'Unknown world endpoint.');
        } else throw new WorldError(405, 'World endpoint method is unavailable.');
      } catch (err) {
        if (!err.status) console.error('[world]', err);
        if (!res.headersSent) json(res, err.status || 503, { error: err.status ? err.message : 'Shared world is temporarily unavailable.',...(['WORLD_BUSY','OX_QUIZ_REFUSED','OX_QUIZ_REJECTED','SIEGE_RENEW_REFUSED'].includes(err.code)?{code:err.code}:{}) });
        else res.end();
      }
      finally{if(admitting){humanAdmissions--;if(worldInitialized&&!stopping&&humanAdmissions===0&&adminGuildAccounts&&adminGuildJob.snapshot().phase==='deferred')adminGuildJob.request();}requests.delete(pending);finished();}
      return true;
    },
  };
}
