// Dekaron engine, website, accounts and authoritative shared-world server.
// Private loopback listener by default; original client assets are served at /data/.
import http from 'node:http';
import {requestOwnerGuildPreparation} from './server/admin-guild-readiness.mjs';
import {handleSkillRootMotion} from './server/skill-root-motion.mjs';
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { exec } from 'node:child_process';
import {monitorEventLoopDelay} from 'node:perf_hooks';
import os from 'node:os';
import net from 'node:net';
import { handleForumApi } from './server/forum/api.mjs';
import { createAccountsApi } from './server/accounts/api.mjs';
import { createLoginVersionGate } from './server/login-version-gate.mjs';
import {createFreshOwnerRoster} from './server/accounts/owner-roster.mjs';
import { createOwnerGMGrants, ownerAccountForHost } from './server/accounts/owner-gm-grants.mjs';
import { initializeLocalDemo, localDemoInfo, isLoopbackHost } from './server/accounts/bootstrap.mjs';
import { createWorldApi } from './server/world/api.mjs';
import {createRateSettings} from './server/world/rate-settings.mjs';
import { clientSource } from './server/client-source.mjs';
import { clientStatus, handleClientStatus, accountCookieName } from './server/client-identity.mjs';
import { createGameShutdown } from './server/game-shutdown.mjs';
import { createLauncherControl, launcherControlFile } from './server/launcher-control.mjs';
import { watchLauncherProcess } from './server/launcher-watch.mjs';
import { isPublicEngineAsset } from './server/public-assets.mjs';
import { createFriendsGate, readFriendsConfig } from './server/friends-gate.mjs';
import { createServerSettings } from './server/server-settings.mjs';
import { playerPopulation } from './server/player-population.mjs';
import { authenticateRelayRequest } from './server/relay-gateway.mjs';
import { sendAssetFile } from './server/asset-response.mjs';
import { initializeWorldStorage } from './server/world-storage.mjs';
import {pinPrivateAccountDirectory} from './server/accounts/private-directory.mjs';
import { hostedAssetAccess } from './server/hosted-asset-access.mjs';
import { capacityFile, readCapacitySettings, writeCapacitySettings, memoryRange } from './server/capacity-settings.mjs';
import {applySandboxEnvironment} from './server/npc-sandbox.mjs';
import {phonePreview} from './server/phone-preview.mjs';
import {createDedicatedSqlServices} from './server/sql/dedicated-sql.mjs';
import {configureDedicatedHost} from './server/dedicated-config.mjs';
import {assertNoInstallUpdate} from './server/update-guard.mjs';
import {createNpcProfiles} from './server/world/npc-profiles.mjs';
import {createGlobalUpdateWatch} from './server/global-update-watch.mjs';
import {createLogger} from './server/logger.mjs';
import {startPingWorker} from './server/ping-worker.mjs';
import {pipelineClient} from './server/pipeline/client.mjs'; // PIPELINE-SPLIT: null unless started by server/pipeline/serveron.mjs
const log=createLogger({context:{component:'server'}}); // structured JSON-lines (DEKARON_LOG_LEVEL, opt-in DEKARON_LOG_FILE)
import {prepareNpcNamesBeforeWorld,assertNpcStartupPortAvailable} from './server/world/npc-name-startup.mjs';
import {npcCapacityPolicy} from './server/world/npc-capacity-policy.mjs';
import {createNpcAutoPopulation,createNpcHostSampler,npcInterestMode,npcEventLoopDelay} from './server/world/npc-auto-population.mjs';
import {reconcileMapFolderBindings} from './src/world/map-folder-bindings.js';

const HERE = path.dirname(fileURLToPath(import.meta.url));
assertNoInstallUpdate(HERE);
configureDedicatedHost({engine:HERE});
const SQL=process.env.DEKARON_DEDICATED_STORAGE==='sqlserver'?await createDedicatedSqlServices():null;


const PHONE_PREVIEW=phonePreview(HERE);
const SANDBOX=PHONE_PREVIEW?null:applySandboxEnvironment(HERE);
const GAME_ROOT = path.resolve(HERE, '..');
const CLIENT_SOURCE = clientSource(HERE);
// Global update detection (detect/parse only; apply is POST /api/global-update/apply from loopback). Same source rule as
// tools/prepare-client.mjs discoverSource: DEKARON_DATA, else <engine>/../data (DEKARON_GLOBAL_WATCH_ROOT overrides the watch target only). DEKARON_GLOBAL_WATCH=0 disables it.
const GLOBAL_WATCH_ROOT = process.env.DEKARON_GLOBAL_WATCH === '0' ? null : path.resolve(process.env.DEKARON_GLOBAL_WATCH_ROOT || process.env.DEKARON_DATA || path.join(HERE, '..', 'data'));
const globalUpdate = createGlobalUpdateWatch({ root: GLOBAL_WATCH_ROOT && fs.existsSync(GLOBAL_WATCH_ROOT) ? GLOBAL_WATCH_ROOT : null, appliedDataRoot: CLIENT_SOURCE.dataRoot,
  intervalMs: Number(process.env.DEKARON_GLOBAL_WATCH_MS) || 5000, debounceMs: Number(process.env.DEKARON_GLOBAL_WATCH_DEBOUNCE_MS) || 15000, log: m => log.child({subsystem:'global-update-watch'}).info(String(m)) });
// PIPELINE-SPLIT: under ServerOn the launcher-visible process is the hub; it owns the public port and stops with this process.
const CLIENT_STATUS = clientStatus(HERE, CLIENT_SOURCE.version, Number(process.env.DEKARON_PIPELINE_HUB_PID)||process.pid);
const DATA_ROOT = CLIENT_SOURCE.dataRoot;
const GAMEDATA_ROOT = CLIENT_SOURCE.gamedataRoot;
// Lane 34: /gamedata/monsters.json and npcs.json must match host folder-reconcile (maps 27/28/4/9/201...).
// Portable baked tables still mis-bind conscript to Aquarius and omit folder-only maps; loadWorldData already
// reconciles for authority. Serving the same reconcile here keeps the browser GameData offline/online tables aligned.
let _reconciledSpawnNpcTables = null;
function reconciledSpawnNpcTables() {
  if (_reconciledSpawnNpcTables) return _reconciledSpawnNpcTables;
  const monsters = JSON.parse(fs.readFileSync(path.join(GAMEDATA_ROOT, 'monsters.json'), 'utf8'));
  const npcs = JSON.parse(fs.readFileSync(path.join(GAMEDATA_ROOT, 'npcs.json'), 'utf8'));
  reconcileMapFolderBindings(monsters, npcs, DATA_ROOT);
  _reconciledSpawnNpcTables = { monsters, npcs };
  return _reconciledSpawnNpcTables;
}

const SOUND_ROOTS = [path.join(DATA_ROOT, 'sound'), ...(CLIENT_SOURCE.looseSoundRoot?[CLIENT_SOURCE.looseSoundRoot]:[]), path.join(GAME_ROOT, 'data', 'sound')];
const SITE_ROOT = path.join(HERE, 'site');
const PORT = Number(process.env.PORT || 7777);
const HOST = process.env.DEKARON_HOST || '127.0.0.1';
const LAN_CONNECTOR=!isLoopbackHost(HOST);
const ACCOUNT_STORE = path.resolve(process.env.DEKARON_ACCOUNT_STORE || path.join(HERE, 'server/accounts/data.json'));
CLIENT_STATUS.privateAccountDirectory=false;
if(process.env.DEKARON_PRIVATE_ACCOUNT_DIR==='1'){await pinPrivateAccountDirectory({engine:HERE,store:ACCOUNT_STORE});CLIENT_STATUS.privateAccountDirectory=true;}
const WORLD_STORAGE = await initializeWorldStorage({engine:HERE,accountStore:ACCOUNT_STORE,customItemsFile:process.env.DEKARON_CUSTOM_ITEM_STORE});
const RELAY_SECRET = process.env.DEKARON_RELAY_SECRET || '';
const RELAY_ORIGIN = process.env.DEKARON_RELAY_ORIGIN || undefined;
if (RELAY_SECRET && (!/^[a-f0-9]{64}$/.test(RELAY_SECRET) || !isLoopbackHost(HOST) || process.env.DEKARON_LOCAL_DEMO !== '0' || process.env.DEKARON_FRIENDS_GATE !== '1')) throw new Error('Online relay requires a private loopback host and separately configured non-demo accounts.');
CLIENT_STATUS.listenHost = HOST;
CLIENT_STATUS.accountScope = process.env.DEKARON_SERVER_MODE === 'friends' ? 'friends' : 'local';
await initializeLocalDemo({host:HOST});
const friendsConfig = process.env.DEKARON_FRIENDS_GATE === '1' ? await readFriendsConfig({engine:HERE}) : null;
const ASSET_SESSION_REQUIRED=!!friendsConfig||!isLoopbackHost(HOST);
CLIENT_STATUS.relayEnabled = !!RELAY_SECRET;
CLIENT_STATUS.localDemo = (await localDemoInfo({file:ACCOUNT_STORE,host:HOST})).localDemo;
CLIENT_STATUS.hostMode = friendsConfig ? (friendsConfig.mode === 'open' ? 'open' : 'friends') : LAN_CONNECTOR?'open':'local';
// This is a requested launch mode, not server-verified anti-cheat attestation.
function readGameGuardRequest(){try{const preferred=path.join(HERE,'runtime','server-gameguard.enabled'),legacy=path.join(HERE,'runtime','gameguard.enabled'),p=fs.existsSync(preferred)?preferred:legacy;if(!fs.existsSync(p))return true;const v=String(fs.readFileSync(p,'utf8')).trim().toLowerCase();return v!=='0'&&v!=='false'&&v!=='off';}catch{return true;}}
CLIENT_STATUS.gameGuardRequired=readGameGuardRequest();
if (RELAY_SECRET && CLIENT_STATUS.localDemo) throw new Error('Demo credentials cannot be published through an online relay.');
for(const [key,variable]of [['exp','DEKARON_EXP_RATE'],['dil','DEKARON_DIL_RATE'],['drop','DEKARON_DROP_RATE']]) {
  if(process.env[variable]===undefined&&friendsConfig?.rates?.[key]!==undefined)process.env[variable]=String(friendsConfig.rates[key]);
}
const rateSettings=await createRateSettings({file:ACCOUNT_STORE+'.rates.json'});
const serverSettings = await createServerSettings({ accountStore:ACCOUNT_STORE, readRates:()=>rateSettings.current(), name:process.env.DEKARON_SERVER_NAME || friendsConfig?.name, engineVersion:JSON.parse(fs.readFileSync(path.join(HERE,'package.json'),'utf8')).version, contentVersion:CLIENT_SOURCE.version });
// ENGINE-CHOSEN opt-in native load tier; unset keeps the existing null policy.
// 1500/2500 live-load acceptance remains pending; no implied default or count.
const npcNativeCapacityTier=process.env.DEKARON_NPC_NATIVE_CAPACITY;
const npcNativeCapacity=npcNativeCapacityTier===undefined?null:npcCapacityPolicy({actorCap:Number(npcNativeCapacityTier),maxWorkerFields:128,maxTypedGeometryBytes:1024**3,maxDecisionsPerCycle:256,decisionBudgetMs:8,preloadAdmissionsPerTurn:16,preloadAdmissionBudgetMs:8,desiredDecisionMs:750});
// ENGINE-CHOSEN interest-managed bots: real actors only where a human is; the rest is background-simulated presence.
const npcInterest=npcInterestMode({interest:process.env.DEKARON_NPC_INTEREST,nativeCapacity:npcNativeCapacity});
let world;
// Player cap, upload budget and the memory limit the launcher starts this process with (dashboard > Settings > Server capacity)
const CAPACITY_FILE = PHONE_PREVIEW?.capacity??capacityFile(HERE);
let capacitySettings = await readCapacitySettings(CAPACITY_FILE);
const npcAutoPopulation=npcInterest?createNpcAutoPopulation({uploadMbps:capacitySettings.uploadMbps}):null;
const friendsGate = await createFriendsGate({ engine: HERE, enabled: process.env.DEKARON_FRIENDS_GATE === '1', lan:LAN_CONNECTOR, info:()=>({...serverSettings.metadata(),...playerPopulation(world?.world,{isNpc:p=>npcProfiles.own(p.account)}),gameGuardRequired:CLIENT_STATUS.gameGuardRequired}), players:()=>playerPopulation(world?.world,{isNpc:p=>npcProfiles.own(p.account)}).players });
const freshOwnerRoster=createFreshOwnerRoster({dataRoot:DATA_ROOT,gamedataRoot:GAMEDATA_ROOT,customItemsFile:WORLD_STORAGE.customItemsFile});
const LOGIN_VERSION_GATE = createLoginVersionGate({ dataRoots: [DATA_ROOT], appliedVersion: () => globalUpdate.getAppliedGlobalVersion() });
const accounts = createAccountsApi({ loginVersionGate: LOGIN_VERSION_GATE, engineSqlStore:SQL?.store, initialOwnerCharacters:freshOwnerRoster, onOwnerPrepared:()=>requestOwnerGuildPreparation(world), file: ACCOUNT_STORE, cookieName: accountCookieName(HERE, ACCOUNT_STORE), gamedataRoot: GAMEDATA_ROOT, launchAccess:req=>friendsGate.launchAccess(req), launchInvite:(req,proof)=>friendsGate.launchInvite(req,proof), isAccountOnline:id=>!!world?.world?.players?.has(id), onInvalidate:id=>world?.disconnectAccount(id), onAuthenticated:id=>launcher.authenticated(id) });
const npcProfiles=createNpcProfiles({atomicStore:accounts,getProfile:(id,cid)=>accounts.getWorldProfile(id,cid),saveProfile:(id,cid,p)=>accounts.saveWorldProfile(id,cid,p),saveProfiles:updates=>accounts.saveWorldProfiles(updates)});
const npcNameStartup=serverSettings.npcPlayers()?await prepareNpcNamesBeforeWorld({profiles:npcProfiles,accounts,rosterFile:PHONE_PREVIEW?.roster??path.join(HERE,'server','npc-dormant-roster.json'),authorized:true,hasWorld:()=>world!==undefined,hasListener:()=>false,assertListenerAvailable:()=>assertNpcStartupPortAvailable({host:HOST,port:PORT})}) :Object.freeze({migrated:0,repairedBindings:0,refreshGeneratedNames:false,deferred:true});
world = createWorldApi({ rateSettings, dataRoot: DATA_ROOT, gamedataRoot: GAMEDATA_ROOT, ...WORLD_STORAGE, adminGuildAccounts:accounts, onAuthenticated:id=>launcher.authenticated(id), launcherTools:(id,lease)=>launcher.drain(id,lease), onClientReady:(id,lease,ready,map,sequence)=>launcher.clientReady(id,lease,ready,map,sequence), resolveUser: req => accounts.user(req), getProfile: (id, cid) => npcProfiles.get(id, cid), saveProfile: (id, cid, profile) => npcProfiles.save(id, cid, profile), saveProfiles: updates => npcProfiles.saveMany(updates), npcProfiles, npcNativeCapacity, npcInterest, npcRosterFile:PHONE_PREVIEW?.roster??path.join(HERE,'server','npc-dormant-roster.json'), npcRefreshGeneratedNames:npcNameStartup.refreshGeneratedNames, npcPlayers:()=>serverSettings.npcPlayers(), npcPopulation:()=>npcAutoPopulation?.value()??100, npcOptionalWorkAllowed:()=>npcAutoPopulation?.optionalWorkAllowed()??true, npcLanguage:()=>serverSettings.npcLanguage(), getSocialState:()=>accounts.getSocialState(), saveSocialTransaction:transaction=>accounts.saveSocialTransaction(transaction), renameProfile: (id, cid, name, nameColor, profile, options) => accounts.renameWorldCharacter(id, cid, name, nameColor, profile, options), capacity: capacitySettings, starterPack: () => serverSettings.starterPack(), fieldPk: () => serverSettings.fieldPk(), verifyAccountPassword: (id, password) => accounts.verifyAccountPassword(id, password), listCharacters: () => accounts.listWorldCharacters(), inspectCharacter: ref => accounts.inspectWorldCharacter(ref), charTransferInfo:(id,exclude)=>accounts.charTransferInfo(id,exclude), transferCharacter:args=>accounts.transferCharacter(args), describeGMCharacter:ref=>accounts.describeGMCharacter(ref), readGMTransfer:key=>accounts.readGMTransfer(key), commitGMTransfer:(req,transaction)=>accounts.commitGMTransfer(req,transaction) });
const npcLoopResolutionMs=20;
const npcLoopDelay=npcAutoPopulation?monitorEventLoopDelay({resolution:npcLoopResolutionMs}):null;
npcLoopDelay?.enable();
const npcHostSample=npcAutoPopulation?createNpcHostSampler():null;
const npcAutoTimer=npcAutoPopulation?setInterval(()=>{
  try{
    const humans=serverSettings.npcPlayers()&&world.world?playerPopulation(world.world,{isNpc:p=>npcProfiles.own(p.account)}).realPlayers:0;
    const live=world.capacity();
    npcAutoPopulation.observe({...npcHostSample(live),preparing:live.preparing||live.npcActivity?.scenePreparations>0,canonicalPreparing:!!live.npcCanonicalPreparing,uploadMbps:live.uploadMbps,workMs:live.workMs,...npcEventLoopDelay(npcLoopDelay.percentile(95)/1e6,npcLoopResolutionMs),heapUsedMB:live.memory.heapUsedMB,heapLimitMB:live.memory.heapLimitMB,humans});
  }catch(error){console.warn('[bots] automatic host governor could not sample load:',error?.message||error);}
  finally{npcLoopDelay.reset();}
},1000):null;
npcAutoTimer?.unref?.();
const launcher = createLauncherControl({characters:async()=>Promise.all((await accounts.listWorldCharacters()).map(async row=>{const c=await accounts.inspectWorldCharacter(row.ref);return {...row,className:c?.className||String(row.classIndex)};})),engine:HERE,storageMode:SQL?'sqlserver':'json',storageDetails:SQL?{instance:SQL.sql.instance,database:SQL.database}:null,file:PHONE_PREVIEW?.launcher??launcherControlFile(HERE, Number(process.env.DEKARON_PUBLIC_PORT)||PORT),status:{...CLIENT_STATUS,get realPlayers(){return playerPopulation(world?.world,{isNpc:p=>npcProfiles.own(p.account)}).realPlayers},get botPlayers(){return playerPopulation(world?.world,{isNpc:p=>npcProfiles.own(p.account)}).botPlayers}},players:()=>playerPopulation(world?.world,{isNpc:p=>npcProfiles.own(p.account)}).players,
  settings:{...serverSettings,set:async input=>{const before={npcPlayers:serverSettings.npcPlayers(),npcPopulation:serverSettings.npcPopulation()},saved=await serverSettings.set(input);if(Object.hasOwn(input,'npcPlayers')||Object.hasOwn(input,'npcPopulation')){try{await world.syncNpcPlayers();}catch(error){for(const key of ['npcPlayers','npcPopulation'])if(Object.hasOwn(input,key))await serverSettings.set({[key]:before[key]});await world.syncNpcPlayers();throw error;}}return saved;}},
  capacity:{
    read:()=>({settings:capacitySettings,live:{...world.capacity(),botAuto:npcAutoPopulation?.state()||null},memoryRange:memoryRange()}),
    save:async input=>{capacitySettings=await writeCapacitySettings(CAPACITY_FILE,{...capacitySettings,...input});world.setCapacity(capacitySettings);return {settings:capacitySettings,live:{...world.capacity(),botAuto:npcAutoPopulation?.state()||null},memoryRange:memoryRange()};},
  },
  preparation:()=>world.preparationStatus(),
  ownerLaunch:(req,res)=>accounts.ownerLaunch(req,res),
  adminGuildStatus:()=>world.adminGuildReport,
  ownerAccounts:createOwnerGMGrants({accountStore:ACCOUNT_STORE,ownerAccount:ownerAccountForHost(friendsConfig),registeredAccounts:()=>accounts.listRegisteredAccountIds(),revokeLease:id=>world.disconnectAccount(id)}),
  publication:options=>friendsGate.setPublication(options),
  activePermissions:id=>accounts.activePermissions(id),actor:id=>world.world?.players.get(id),
  connections:()=>accounts.activeSessionCount(),
  stop:()=>shutdown.stopNow()});
const shutdown=createGameShutdown({resolveUser:req=>accounts.user(req),save:async()=>{await world.close();await accounts.checkpoint();if(SQL)await SQL.close();},clean:()=>launcher.clean(),close:()=>{if(controlServer){controlServer.close();controlServer.closeAllConnections();}if(npcAutoTimer)clearInterval(npcAutoTimer);npcLoopDelay?.disable();server.close(()=>process.exit(0));server.closeAllConnections();}});

function safeJoin(root, rel) {
  let clean;
  try { clean = decodeURIComponent(rel).replace(/\\/g, '/').replace(/^\/+/, ''); } catch { return null; }
  if (clean.includes('\0')) return null;
  const full = path.resolve(root, clean);
  if (full !== root && !full.startsWith(root + path.sep)) return null;
  // Resolve existing links before both containment and private-file allowlist checks.
  try {
    const actual = fs.realpathSync.native(full), actualRoot = fs.realpathSync.native(root);
    const normalize = p => process.platform === 'win32' ? p.toLowerCase() : p;
    if (normalize(actual) !== normalize(actualRoot) && !normalize(actual).startsWith(normalize(actualRoot) + path.sep)) return null;
    return actual;
  } catch (err) { if (!['ENOENT', 'ENOTDIR'].includes(err.code)) return null; }
  return full;
}

function sendFile(req, res, file, optional = false) {
  return sendAssetFile(req,res,file,{optional,generation:`${CLIENT_STATUS.runtimeVersion}:${CLIENT_SOURCE.version}`,privateCache:ASSET_SESSION_REQUIRED,contentVersion:CLIENT_SOURCE.version,contentAsset:/^\/(data|gamedata)\//.test(new URL(req.url, 'http://localhost').pathname)});
}

function listDir(res, dir) {
  fs.readdir(dir, { withFileTypes: true }, (err, ents) => {
    if (err) { res.writeHead(404); return res.end('[]'); }
    res.writeHead(200, { 'Content-Type': 'application/json', 'Cache-Control':'private, no-store', ...(ASSET_SESSION_REQUIRED?{'Vary':'Cookie'}:{'Access-Control-Allow-Origin': '*'}) });
    res.end(JSON.stringify(ents.map(e => ({ name: e.name, dir: e.isDirectory() }))));
  });
}

const server = http.createServer({ noDelay: true }, (req, res) => {
  // PERF-NET ping fast path: answered synchronously before URL parsing and every awaited gate (launcher/friends/asset/world).
  // Same 204 no-store reply as /api/world/ping in server/world/api.mjs.
  if (req.method === 'GET' && (req.url === '/api/world/ping' || req.url.startsWith('/api/world/ping?'))) { res.writeHead(204, { 'Cache-Control': 'no-store' }); res.end(); return; }
 
  // PING-SRV: answer the HUD ping synchronously in the request callback, before URL parsing and the awaited handler chain,
  // so it never waits extra microtask/handler turns behind other work. It does no game work and returns no data.
  if ((req.url === '/api/world/ping' || req.url.startsWith('/api/world/ping?')) && (req.method === 'GET' || req.method === 'HEAD') && req.headers['sec-fetch-site'] !== 'cross-site') { res.writeHead(204, { 'Cache-Control': 'no-store' }); res.end(); return; }
  let releaseMutation;void (async () => {
  const url = new URL(req.url, 'http://localhost');
  const p = url.pathname;
  if (req.headers['x-dekaron-relay-secret'] || req.headers['x-dekaron-relay-client']) {
    req.relay = authenticateRelayRequest(req,{secret:RELAY_SECRET,origin:RELAY_ORIGIN});
    if (!req.relay) {res.writeHead(403,{'Content-Type':'application/json','Cache-Control':'no-store'});res.end(JSON.stringify({error:'Relay verification failed.'}));return;}
  }
  if(req.relay && (p.startsWith('/api/launcher/') || ['/api/client/status','/api/auth/demo'].includes(p))) {res.writeHead(404);res.end('not found');return;}
  if(shutdown.saving&&['POST','PUT','PATCH','DELETE'].includes(req.method)&&!['/api/world/server-control','/api/launcher/stop','/api/auth/logout'].includes(p)){res.writeHead(503,{'Content-Type':'application/json','Cache-Control':'no-store'});res.end(JSON.stringify({error:'The server is saving progress and stopping.'}));return;}
  releaseMutation=shutdown.track(req,res,p);
  if(LAN_CONNECTOR&&p.startsWith('/api/launcher/')&&!(HOST==='0.0.0.0'&&isLoopbackHost(String(req.socket.remoteAddress||'').replace(/^::ffff:/i,'')))){res.writeHead(404);res.end('not found');return;}
  if (await launcher.handle(req,res,p)) return;
  if (await friendsGate.handle(req,res,p)) return;
  if (await hostedAssetAccess(req,res,p,{enabled:ASSET_SESSION_REQUIRED,canReadAssets:req=>accounts.canReadAssets(req)})) return;
  if (p === '/launch' && ['GET','HEAD'].includes(req.method)) {
    const page = await fs.promises.readFile(path.join(HERE,'launch.html'));
    res.writeHead(200,{'Content-Type':'text/html; charset=utf-8','Content-Length':page.length,'Cache-Control':'no-store','Referrer-Policy':'no-referrer','X-Content-Type-Options':'nosniff','X-Frame-Options':'DENY','Content-Security-Policy':"default-src 'none'; script-src 'unsafe-inline'; style-src 'unsafe-inline'; connect-src 'self'; base-uri 'none'; form-action 'none'; frame-ancestors 'none'"});
    res.end(req.method === 'HEAD' ? undefined : page);return;
  }
  if (p === '/join' && ['GET','HEAD'].includes(req.method)) return sendFile(req,res,path.join(HERE,'join.html'));
  if (p === '/api/server/info' && req.method === 'GET') { res.writeHead(200,{'Content-Type':'application/json; charset=utf-8','Cache-Control':'no-store'});res.end(JSON.stringify(serverSettings.metadata()));return; }
if (p === '/api/client/status') return handleClientStatus(req, res, CLIENT_STATUS);
  if (await globalUpdate.handle(req, res, p, { isLocal: isLoopbackHost(String(req.socket.remoteAddress||'').replace(/^::ffff:/i,'')) })) return;
  if (await shutdown.handle(req,res,p)) return;
  if (await world.handle(req, res, p)) return;
  if (await accounts.handle(req, res, p)) return;
  // Loopback-only: client fatal dump -> run/crashes + optional notepad open (load/crash UX).
  if (p === '/api/client-crash' && req.method === 'POST') {
    const remote = String(req.socket.remoteAddress || '').replace(/^::ffff:/i, '');
    if (!isLoopbackHost(remote)) { res.writeHead(403, {'Content-Type':'application/json','Cache-Control':'no-store'}); res.end(JSON.stringify({error:'loopback only'})); return; }
    const chunks = [];
    for await (const c of req) chunks.push(c);
    let body = {};
    try { body = JSON.parse(Buffer.concat(chunks).toString('utf8') || '{}'); } catch { res.writeHead(400, {'Content-Type':'application/json'}); res.end(JSON.stringify({error:'bad json'})); return; }
    const rawName = String(body.filename || 'dk-crash.txt').replace(/[^a-zA-Z0-9._-]/g, '_').slice(0, 120) || 'dk-crash.txt';
    const text = String(body.text || '').slice(0, 512 * 1024);
    if (!text) { res.writeHead(400, {'Content-Type':'application/json'}); res.end(JSON.stringify({error:'empty'})); return; }
    const crashDir = path.join(HERE, 'run', 'crashes');
    await fs.promises.mkdir(crashDir, { recursive: true });
    const outPath = path.join(crashDir, rawName.endsWith('.txt') ? rawName : rawName + '.txt');
    await fs.promises.writeFile(outPath, text, 'utf8');
    let opened = false;
    if (body.open !== false && process.platform === 'win32') {
      try { exec('notepad.exe "' + outPath.replace(/"/g, '') + '"', { windowsHide: false }); opened = true; } catch (e) { console.error('[client-crash] open failed', e); }
    }
    res.writeHead(200, {'Content-Type':'application/json; charset=utf-8','Cache-Control':'no-store'});
    res.end(JSON.stringify({ ok: true, path: outPath, opened }));
    return;
  }
  if (!['GET', 'HEAD'].includes(req.method) && !p.startsWith('/api/forum/')) {
    res.writeHead(405, { Allow: 'GET, HEAD' }); return res.end();
  }
  if (p === '/api/ls') {
    const dir = safeJoin(DATA_ROOT, url.searchParams.get('dir') || '');
    return dir ? listDir(res, dir) : (res.writeHead(400), res.end());
  }
  if (p.startsWith('/api/forum/')) {
    if (req.method !== 'GET') {
      let badOrigin = req.headers['sec-fetch-site'] === 'cross-site';
      try { if (req.headers.origin && new URL(req.headers.origin).host !== req.headers.host) badOrigin = true; } catch { badOrigin = true; }
      if (badOrigin) { res.writeHead(403); return res.end('cross-origin writes are not allowed'); }
    }
    handleForumApi(req, res, p, req.method, accounts.user).then((handled) => {
      if (!handled) { res.writeHead(404, { 'Access-Control-Allow-Origin': '*' }); res.end('not found'); }
    }).catch((err) => {
      console.error('[forum]', err);
      if (!res.headersSent) { res.writeHead(500, { 'Access-Control-Allow-Origin': '*' }); res.end('forum error'); }
    });
    return;
  }
  if (p === '/site' || p.startsWith('/site/')) {
    if (/^\/site\/assets\/loading-\d+\.png$/.test(p)) {
      res.writeHead(404);return res.end('not found');
    }
    let rel = p.slice('/site'.length); // '' or '/...'
    if (rel === '' || rel === '/') rel = '/index.html';
    const f = safeJoin(SITE_ROOT, rel.replace(/^\/+/, ''));
    return f ? sendFile(req, res, f) : (res.writeHead(404), res.end('not found'));
  }
  if (p.startsWith('/data/')) {
    const f = safeJoin(DATA_ROOT, p.slice(6));
    return f ? sendFile(req, res, f, url.searchParams.get('opt') === '1') : (res.writeHead(400), res.end());
  }
  if (await handleSkillRootMotion(req, res, p, { dataRoot: DATA_ROOT, gamedataRoot: GAMEDATA_ROOT })) return;
  if (p.startsWith('/gamedata/')) {
    if (p === '/gamedata/monsters.json' || p === '/gamedata/npcs.json') {
      try {
        const tables = reconciledSpawnNpcTables();
        const body = Buffer.from(JSON.stringify(p === '/gamedata/monsters.json' ? tables.monsters : tables.npcs));
        res.writeHead(200, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'private, no-store', 'Content-Length': body.length });
        return res.end(body);
      } catch (err) {
        log.error('[server] reconciled gamedata serve failed; falling back to disk', { err });
      }
    }
    const data = safeJoin(GAMEDATA_ROOT, p.slice('/gamedata/'.length));
    return data ? sendFile(req, res, data) : (res.writeHead(404), res.end('not found'));
  }
  if (p.startsWith('/sound/')) {
    const rel = p.slice(7);
    const f = SOUND_ROOTS.map(r => safeJoin(r, rel)).find(c => c && fs.existsSync(c));
    return f ? sendFile(req, res, f) : (res.writeHead(404), res.end('not found'));
  }
  const f = safeJoin(HERE, p === '/' ? 'index.html' : p.slice(1));
  // Server-side passwords, sessions, forums and temporary files are never static assets.
  const rel = f && path.relative(HERE, f).replace(/\\/g, '/');
  if (rel && !isPublicEngineAsset(rel)) {
    res.writeHead(404); return res.end('not found');
  }
  return f ? sendFile(req, res, f) : (res.writeHead(400), res.end());
})().catch(err => {
  log.error('[server] request failed',{err});
  if (!res.headersSent) res.writeHead(503, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store' });
  if (!res.writableEnded) res.end(JSON.stringify({ error: 'The server could not complete this request. Your saved files are preserved.' }));
}).finally(()=>releaseMutation?.()); });

for (const signal of ['SIGINT', 'SIGTERM']) process.on(signal, () => {
  shutdown.stopNow().catch(error=>log.error('[server] shutdown save failed; process remains running',{err:error}));
});
// STABILITY crash guard: a stray exception or promise rejection is logged and the server keeps serving (before: any one of
// them killed the process and every connected player). A storm (20 within 60 s) means the state is no longer trustworthy:
// save and stop through the normal shutdown, exit code 1, so the launcher/supervisor starts a clean process.
{
  const recent=[];let storm=false;
  const guard=(kind,error)=>{
    try{log.error(`[crash-guard] ${kind}; server kept running`,{err:error});}catch{try{console.error('[crash-guard]',kind,error);}catch{}}
    const now=Date.now();recent.push(now);while(recent.length&&now-recent[0]>60000)recent.shift();
    if(recent.length>=20&&!storm){storm=true;process.exitCode=1;try{log.error('[crash-guard] error storm; saving and stopping',{count:recent.length});}catch{}
      Promise.resolve().then(()=>shutdown.stopNow()).catch(error=>{try{log.error('[crash-guard] shutdown save failed',{err:error});}catch{}});}
  };
  process.on('uncaughtException',(error,origin)=>guard(origin==='unhandledRejection'?'unhandled rejection':'uncaught exception',error));
  process.on('unhandledRejection',reason=>guard('unhandled rejection',reason));
}


// Network game traffic and private administration use separate listeners.
const controlServer=LAN_CONNECTOR?http.createServer((req,res)=>{
  void(async()=>{
    const p=new URL(req.url,'http://localhost').pathname;
    if(await launcher.handle(req,res,p))return;
    res.writeHead(404);res.end('not found');
  })().catch(error=>{log.error('[launcher] request failed',{err:error});if(!res.headersSent)res.writeHead(503);if(!res.writableEnded)res.end('control unavailable');});
}):null;
try{
  if(controlServer)await new Promise((resolve,reject)=>{controlServer.once('error',reject);controlServer.listen(0,'127.0.0.1',resolve);});
  await new Promise((resolve,reject)=>{server.once('error',reject);server.listen(PORT,HOST,resolve);});
  if(process.env.DEKARON_PING_WORKER!=='0'){const pw=await startPingWorker({host:HOST,port:Number(process.env.DEKARON_PING_PORT)||PORT+1});if(!pw.ok)log.warn('ping worker unavailable; HUD ping uses /api/world/ping',{error:pw.error});}
  globalUpdate.start();
  const url=process.env.DEKARON_PUBLIC_URL||('http://'+(HOST==='0.0.0.0'?'localhost':HOST)+':'+PORT+'/'); // PIPELINE-SPLIT: gateway URL under ServerOn
  {const pc=pipelineClient();if(pc){ // PIPELINE-SPLIT: stats -> hub (coalesced), save+stop on request, stop if the hub disappears
    const eld=monitorEventLoopDelay({resolution:10});eld.enable();const ms=v=>Math.round(v/1e4)/100;
    setInterval(()=>{let cap={};try{for(const [k,v] of Object.entries(world.capacity()||{}))if(v===null||['number','boolean','string'].includes(typeof v))cap[k]=v;}catch{}pc.stats('stats.realm',{at:Date.now(),pid:process.pid,loop:{p50:ms(eld.percentile(50)),p99:ms(eld.percentile(99)),max:ms(eld.max)},capacity:cap,heapMB:Math.round(process.memoryUsage().heapUsed/1048576)});eld.reset();},1000).unref();
    pc.on('ctl.Realm',d=>{if(d?.op==='stop')shutdown.stopNow().catch(error=>log.error('[pipeline] stop failed',{err:error}));});
    pc.onHubLost=()=>{log.warn('[pipeline] hub disconnected; saving and stopping');shutdown.stopNow().catch(()=>{});};}}
  const controlUrl=controlServer?'http://127.0.0.1:'+controlServer.address().port+'/':url;
  await launcher.publish(url,controlUrl);
  console.log('Dekaron Online running at '+url);
  console.log('Game data: '+DATA_ROOT);
  console.log('Prepared indexes: '+GAMEDATA_ROOT+' ('+CLIENT_SOURCE.version.slice(0,12)+')');
  log.info('server started',{url,dataRoot:DATA_ROOT,gamedataRoot:GAMEDATA_ROOT,clientVersion:CLIENT_SOURCE.version.slice(0,12)});
  if(process.argv.includes('--open'))exec(process.platform==='win32'?'start "" "'+url+'"':'open "'+url+'"');
  watchLauncherProcess({stop:()=>shutdown.stopNow(),log:(...message)=>console.error(...message)});
}catch(error){log.error('[dedicated] startup failed',{err:error});await shutdown.stopNow();process.exitCode=1;}
