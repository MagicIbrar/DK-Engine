// ZUTO'S BATTLEFIELD (map 650) host battle controller. Rules and provenance: src/game/urban-warfare-rules.js.
// Native factions are source servers (World_Index 1 / 2); this host is one server. The OWNER-DIRECTED single-server
// adaptation (ZUTO_ADAPTATION, ENGINE CHOICE) replaces only that identity: a character registers at the Ardeca
// Jerome, the host assigns its side and stores it durably (one atomic social-document transaction with the
// profile), and the native Checkpoint (Entrance) teleport 133 then admits it through a one-shot permit of the closed
// boundary (server/world/urban-warfare.mjs). Other generic routes stay closed;
// Phantom Castle 653 uses the separate authoritative phantom-castle.mjs service.
// Dispatch, tick, snapshot and revive are wired in core.mjs; the GM `partywar "Zuto's battlefield"` route in gm.mjs.
//   Live (world.zutoLive, host memory): {battle:{id, phase, startAt, endAt, stones, members, kills, lastCaptor, hold, outcome}}
//   Durable: social.zuto season registry + profile.zuto.registration (registration), entry fee/travel (one profile
//   save), reward grants (one atomic profile save per member with a battle-id receipt, profile.zuto.receipts).
import {randomUUID,randomBytes} from 'node:crypto';
import {registerPvpMode} from './pvp.mjs';
import {sameScene} from './scene.mjs';
import {nearbyNpc,offersOriginalJob,npcPlacements} from './npc-services.mjs';
import {commitFieldTravel,boundReturnTarget} from './travel.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {channelData} from './channels.mjs';
import {leaveParty} from './party.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {assertNieteService,assertCombatService} from './niete-services.mjs';
import {socialTransaction,socialState,socialRef} from './social-state.mjs';
import {withUrbanWarfareTravelPermit} from './urban-warfare.mjs';
import {plain} from '../../src/systems/events/text.js';
import {urbanWarfareUnavailableText} from '../../src/systems/events/urban-warfare-routes.js';
import {dkLocates,dkMap,isDkChannel} from '../../src/systems/channels/channel-rules.js';
import {ZUTO as Z,zutoConfig,zutoStones,zutoHoldingSide,zutoTimeoutOutcome,zutoRewardRows,zutoPhaseAt,zutoSideOfWorld,zutoSeasonAt,zutoAssignSide,zutoLobbyOf,zutoScheduledStart} from '../../src/game/urban-warfare-rules.js';

export const ZUTO_SCHEMAS={zuto:['token','type','operation','npcIndex']};
// ENGINE CHOICE anchors of the adaptation (ZUTO_ADAPTATION): registration NPC/job, native entry teleport, post-battle return.
const REGISTER={npc:121,job:[31,65000],map:150},ENTRY_TABLE=133,POST_BATTLE_RETURN_MS=60000,REGISTER_ATTEMPTS=3;
const SEIZE_RANGE=3,SEIZE_KEY='zutoSeize',REVIVE_EXIT_MS=60000,BASE_EXIT_MS=120000,COUNTDOWN_MS=5000,RECEIPTS=32;   // 160:636 1 minute; help art 2 minutes
const fail=(message,status=400,code)=>{throw Object.assign(Error(message),{status,...(code?{code}:{})});};
const ui=(code,status=403)=>fail(`zuto:${Z.ui.cate}:${code}`,status,'ZUTO_REFUSED');

// ------------------------------------------------------------------ original data (fail closed)
const cache=new WeakMap();
export function zutoData(world){
  const host=world?.data;if(!host||typeof host!=='object')return null;
  if(cache.has(host))return cache.get(host);
  let out=null;
  try{
    const ev=host.eventData,info=ev?.map?.(Z.battlefield),cfg=zutoConfig(ev?.modes?.urbanWarfare);
    // Owner rule: keep the in-game map value. maplist 650 is 170-250; respawn.csv 150-250 stays as tableLevels evidence.
    const mapLevels=info?.level;if(cfg&&Array.isArray(mapLevels)&&mapLevels.length===2&&mapLevels.every(Number.isInteger)&&mapLevels[0]>0&&mapLevels[1]>=mapLevels[0]){cfg.tableLevels=cfg.levels;cfg.levels=[mapLevels[0],mapLevels[1]];}
    const npcs=host.progression?.npcs,stones=zutoStones(npcPlacements(world,Z.battlefield).map(r=>[r.npcIndex,r.x,r.z]),npcs?.npcs);
    const locates=dkLocates(channelData(world),Z.battlefield),status=host.itemUseData?.statuses?.[cfg?.seizeStatus];
    const rewardsKnown=cfg&&Object.values(cfg.rewards).every(([item])=>!!host.itemDB?.def?.(item));
    if(info?.mode==='urbanWarfare'&&Number(info.flags?.isUseMap)===1&&cfg&&stones?.length===5&&locates.length===1&&status&&rewardsKnown)
      out={cfg,stones,channel:locates[0].channel,status};
  }catch{out=null;}
  cache.set(host,out);return out;
}
export const zutoLive=world=>world.zutoLive||={battle:null,history:[]};
const present=(world,q)=>!!q&&world.players.get(q.account)===q&&!q.leaving;
const onField=(world,data,q)=>present(world,q)&&q.map===Z.battlefield&&!q.instanceId&&(q.channel??0)===data.channel;
const playerById=(world,id)=>{for(const q of world.players.values())if(q.id===id&&!q.leaving)return q;return null;};
const running=b=>!!b&&b.phase==='battle';
function memberOf(world,p){const b=zutoLive(world).battle,m=b?.members.get(p?.id);return m&&!m.left&&!m.evicted?{b,m}:null;}
function send(world,data,ids,event){if(ids.length)world.emit(Z.battlefield,{...event,channel:data.channel,recipients:ids});}
function fieldIds(world,data){return [...world.players.values()].filter(q=>onField(world,data,q)).map(q=>q.id);}

// Private host capability, never a profile/network field. Production installs no
// resolver: an authenticated native source-world backend does not exist. Without
// one, zutoOriginFor uses the owner-directed durable registration (zutoRegistration).
const originResolvers=new WeakMap();
export function installZutoOriginResolver(world,resolver){
  if(!world||typeof resolver!=='function'||originResolvers.has(world))fail('Zuto source-world resolver is unavailable or already installed.',503);
  originResolvers.set(world,resolver);
}
// ------------------------------------------------------------------ owner-directed registration (ENGINE CHOICE)
const guildIdOf=(state,ref)=>{for(const [id,g] of Object.entries(state?.guilds||{}))if((g?.members||[]).some(m=>m?.ref===ref))return String(g.id??id);return null;};
// ENGINE-CHOSEN season anchor (ZUTO_RULE_STATUS season-boundary): an open battle window keeps its initialization's season.
const currentSeason=world=>zutoSeasonAt(world.now(),world.zutoLive?.battle);
/**
 * The host-assigned side of a live character for the current season, or null. Both durable halves written by the same
 * registration transaction must agree: the social registry row and profile.zuto.registration. Nothing else is read.
 */
export function zutoRegistration(world,p){
  if(!present(world,p)||p.profile?.authority!=='server'||p.profile.id!==p.characterId)return null;
  const state=world.socialState,season=currentSeason(world);if(!state||state.zuto?.season!==season)return null;
  const ref=socialRef(p),row=state.zuto.members?.[ref],mine=p.profile.zuto?.registration;
  if(!row||!['red','blue'].includes(row.side)||!mine||mine.season!==season||mine.side!==row.side)return null;
  return {season,side:row.side,guild:row.guild??null,ref};
}
function nativeText(world,cate,code,fallback=''){
  const ev=world.data?.eventData;let text=null;
  try{text=ev?.mapTxt?.(cate,code)||ev?.txt?.('stringtable_map_string_02.txt',cate,code)||ev?.txt?.('stringtable_dksquare.txt',cate,code);}catch{text=null;}
  return plain(text||'').trim()||fallback;
}
const identityText=world=>plain(String(world.data?.progression?.dialogs?.strings?.[Z.identity.cate]?.[Z.identity.unknown]||'')).trim()||'Server cannot be identified.';
const refuse=(world,cate,code,status=403,fallback='')=>fail(nativeText(world,cate,code,fallback||`Zuto's Battlefield refused entry (${cate}:${code}).`),status,'ZUTO_REFUSED');
// 403, not 503: a player-facing 'not now' must not read as a broken connection (client.js expires/reconnects on 409/503).
const closed=world=>fail(urbanWarfareUnavailableText(world.data?.eventData),403,'URBAN_WARFARE_UNAVAILABLE');
const yawDeg=p=>-(Number(p.yaw)||0)*180/Math.PI||0;
function levelAllowed(cfg,p,minimum=0){const level=Number(p.profile?.level)||1;return level>=Math.max(cfg.levels[0],minimum)&&level<=cfg.levels[1];}

/**
 * Register at the Ardeca Jerome and move to the side's Zuto's Road lobby on the DK channel. The side is chosen
 * by zutoAssignSide from host state only and committed with the profile in one social transaction; a later lobby move
 * failure leaves the (idempotent) registration in place and changes nothing else.
 */
export async function zutoRegister(world,p){
  const data=zutoData(world);if(!data)closed(world);
  if(world.players.get(p.account)!==p||p.leaving||p.dead||p.mount||p.sceneTransition||p.progressCommitting||p.tradeId||p.charTradeId)fail('Zuto registration is unavailable while disconnected, dead, mounted, travelling or trading.',403);
  if(p.instanceId||isDkChannel(p.channel))fail('Leave the current run or DK server first.',403);
  assertNieteService(world,p);assertCombatService(world,p);
  const [type,index]=REGISTER.job,row=p.map===REGISTER.map?nearbyNpc(world,p,{npcIndex:REGISTER.npc,jobType:type,jobIndex:index,radius:8}):null;
  if(!row||!offersOriginalJob(world,row,type,index))fail('Stand near Jerome in Ardeca.',403);
  if(!levelAllowed(data.cfg,p))refuse(world,650,Z.mapText.level,403);
  let reg=zutoRegistration(world,p);
  for(let attempt=0;!reg&&attempt<REGISTER_ATTEMPTS;attempt++){
    const season=currentSeason(world),battleSide=zutoLive(world).battle?.members.get(p.id)?.side||null;
    try{
      await socialTransaction(world,p,{revision:socialState(world).revision,requestId:randomBytes(16).toString('hex')},(state,profile,ref)=>{
        if(state.zuto?.season!==season)state.zuto={season,members:{},guilds:{}};
        const r=state.zuto;r.members||={};r.guilds||={};
        const guild=guildIdOf(state,ref),pick=zutoAssignSide({registry:r,ref,guildId:guild,battleSide});
        if(!r.members[ref])r.members[ref]={side:pick.side,guild,at:world.now(),reason:pick.reason};
        if(guild!=null&&!r.guilds[guild])r.guilds[guild]=r.members[ref].side;
        profile.zuto={...(profile.zuto||{}),registration:{season,side:r.members[ref].side,guild:r.members[ref].guild??null}};
        return r.members[ref].side;
      });
    }catch(error){if(error.status!==409||attempt===REGISTER_ATTEMPTS-1)throw error;}
    reg=zutoRegistration(world,p);
  }
  if(!reg)fail('Zuto registration could not be confirmed.',503);
  const lobby=zutoLobbyOf(reg.side),channels=channelData(world),locate=dkLocates(channels,lobby)[0],lobbyRow=dkMap(channels,lobby);
  if(!locate||!Array.isArray(lobbyRow?.locate))fail('The original Zuto lobby is unavailable.',503);
  const profile=structuredClone(p.profile);
  profile.dkReturn={map:p.map,x:p.x,z:p.z,dirDeg:yawDeg(p),channel:p.channel??0,dk:locate.channel};
  await commitFieldTravel(world,p,{map:lobby,x:lobbyRow.locate[0]+.5,z:lobbyRow.locate[1]+.5,dirDeg:0,channel:locate.channel},profile);
  // Current Global Party guide 4: a field party ends when its member enters a DK server (channels.mjs dkEnter).
  if(p.partyId)leaveParty(world,p);
  return {registered:true,season:reg.season,side:reg.side,lobby,channel:locate.channel};
}

/** The native Checkpoint (Entrance) teleport 133 row whose destination is the battlefield. */
export function isZutoBattlefieldTeleport(world,input){
  if(input?.type!=='npctravel'||input.operation!=='teleport'||Number(input.table)!==ENTRY_TABLE)return false;
  const row=world.data.travelData?.teleports?.[ENTRY_TABLE]?.units?.find(u=>u.unit===input.unit);
  return Number(row?.map)===Z.battlefield;
}
/**
 * Native teleport 133 for a registered member: original NPC/level/fee, native refusals (10001 initializing, 10003 level,
 * 10005/10006 side full, 10008 party, 10000 closed), reserved capacity, one durable fee+travel commit to the side's own
 * Ally base through the boundary permit, then battle membership. A failed save changes nothing and frees the reservation.
 */
export async function zutoEnterBattlefield(world,p,input){
  const data=zutoData(world);if(!data)closed(world);
  if(world.players.get(p.account)!==p||p.leaving||p.dead||p.mount||p.sceneTransition||p.progressCommitting||p.tradeId||p.charTradeId)fail('Travel is unavailable while dead, mounted or changing maps.');
  assertCombatService(world,p);assertNieteService(world,p);
  const row=world.data.travelData?.teleports?.[ENTRY_TABLE]?.units?.find(u=>u.unit===input.unit);if(!row)fail('Invalid original teleport destination.');
  const npc=Number(input.npcIndex),def=world.data.progression?.npcs?.npcs?.[npc];
  if(!def?.jobs?.some(j=>Number(j[0])===2&&Number(j[1])===ENTRY_TABLE))fail('That NPC does not offer this travel service.');
  const placed=nearbyNpc(world,p,{npcIndex:npc,jobType:2,jobIndex:ENTRY_TABLE,radius:8});
  if(p.instanceId||!placed||!offersOriginalJob(world,placed,2,ENTRY_TABLE))fail('Stand near the original travel NPC.');
  const b=zutoLive(world).battle,now=world.now();
  if(b?.phase==='init')refuse(world,650,Z.mapText.initializing);
  if(!b||!['entry','battle'].includes(b.phase)||now>=b.endAt)closed(world);
  const reg=zutoRegistration(world,p);if(!reg)fail(identityText(world),403,'ZUTO_REFUSED');
  if(!Z.lobbies.includes(p.map)||(p.channel??0)!==data.channel)fail('Use the Checkpoint on your Zuto\'s Road lobby.',403);
  if(!levelAllowed(data.cfg,p,Number(row.level)||0))refuse(world,650,Z.mapText.level,403);
  if(p.partyId)refuse(world,650,Z.mapText.inParty);
  const old=b.members.get(p.id);
  if(old?.evicted)fail('This character was expelled from this battle.',403);
  if(old&&old.side!==reg.side)fail('This character already fought for the other side.',403);
  const reserved=b.reserved||=new Map();if(reserved.has(p.id))fail('A battlefield entry is already in progress.',403);
  if(!old||old.left){
    const n=[...b.members.values()].filter(m=>m.side===reg.side&&!m.left&&!m.evicted).length+[...reserved.values()].filter(s=>s===reg.side).length;
    if(n>=data.cfg.capacity)refuse(world,650,reg.side==='red'?10006:10005);
  }
  const cost=Number(row.cost)||0,profile=structuredClone(p.profile);
  if(!Number.isFinite(cost)||cost<0||Number(profile.dil||0)<cost)fail('You do not have enough DIL.');
  profile.dil=Number(profile.dil||0)-cost;
  const base=data.cfg.sides[reg.side].base;
  reserved.set(p.id,reg.side);
  try{await withUrbanWarfareTravelPermit(world,Z.battlefield,()=>commitFieldTravel(world,p,{map:Z.battlefield,x:base.x,z:base.z,dirDeg:base.dirDeg,channel:data.channel},profile));}
  finally{reserved.delete(p.id);}
  let m;
  try{m=admitZutoMember(world,p);}
  catch(error){await moveHome(world,p).catch(()=>{});throw error;}   // never leave an unadmitted character on the battlefield
  m.viaEntry=true;
  return {entered:true,side:m.side,battle:b.id};
}

/** GM `partywar "Zuto's battlefield" open|start|end` (gm.mjs): open entry now (T+10 min), start now, or end now (time-out order). */
export function gmZutoControl(world,state){
  const data=zutoData(world);if(!data)fail('The original Zuto battlefield data is unavailable.',503);
  const L=zutoLive(world),b=L.battle,now=world.now();
  if(state==='end'){if(!b||['end','closed'].includes(b.phase))return "Zuto's Battlefield: no battle is running.";b.endAt=Math.min(b.endAt,now);if(b.phase!=='battle'){b.startAt=Math.min(b.startAt,now);b.phase='battle';}return "Zuto's Battlefield: GM ended the battle; the native time-out order decides it.";}
  if(!['open','start'].includes(state))fail('Use open, start, or end for this event.');
  if(b&&b.phase!=='closed')fail('A Zuto battle already exists.',400);
  const battle=beginZutoBattle(world,{startAt:state==='open'?now+10*60000:now});battle.gm=true;
  return `Zuto's Battlefield: ${state==='open'?'entry open; the battle starts in 10 minutes':'battle started'} (native ${data.cfg.fightMs/60000}-minute fight).`;
}

export function zutoOriginFor(world,p){
  if(!present(world,p)||p.profile?.authority!=='server'||p.profile.id!==p.characterId)return null;
  const resolve=originResolvers.get(world);
  if(!resolve){const reg=zutoRegistration(world,p),cfg=zutoData(world)?.cfg;return reg&&cfg?{account:p.account,characterId:p.characterId,worldIndex:cfg.sides[reg.side].world,side:reg.side,registered:true}:null;}
  let origin;try{origin=resolve(p.account,p.characterId);}catch{return null;}
  if(!origin||origin.account!==p.account||origin.characterId!==p.characterId||!Number.isInteger(origin.worldIndex))return null;
  const side=zutoSideOfWorld(zutoData(world)?.cfg,origin.worldIndex);
  return side?{account:p.account,characterId:p.characterId,worldIndex:origin.worldIndex,side}:null;
}

// ------------------------------------------------------------------ battle lifecycle (host code only)
/** Create the battle for a scheduled start T (phases init T-30 min, entry T-10 min, battle FightTime). */
export function beginZutoBattle(world,{startAt}){
  const data=zutoData(world);if(!data)fail('The original Zuto battlefield data is unavailable.',503);
  const L=zutoLive(world);if(L.battle&&L.battle.phase!=='closed')fail('A Zuto battle already exists.',409);
  if(!Number.isFinite(startAt))fail('A battle start time is required.');
  L.battle={id:randomUUID(),phase:zutoPhaseAt(data.cfg,world.now(),startAt),startAt,endAt:startAt+data.cfg.fightMs,announced:new Set(),
    stones:new Map(data.stones.map(s=>[s.index,{...s,owner:null,seizing:null,capturedAt:null}])),members:new Map(),kills:{red:0,blue:0},lastCaptor:null,lastCaptureAt:null,lastCaptureSequence:0,captureSequence:0,hold:{side:null,since:null},outcome:null,rewards:new Map()};
  return L.battle;
}
/**
 * Admit a member through the private account-bound origin resolver (native: world 1 -> red, 2 -> blue). No production caller
 * exists while admission is closed. Native refusals: 10008 in a party, 10003 level, 10005/10006 side full (cate 650).
 */
export function admitZutoMember(world,p){
  const data=zutoData(world);if(!data)fail('The original Zuto battlefield data is unavailable.',503);
  const b=zutoLive(world).battle;if(!b||!['entry','battle'].includes(b.phase))fail(`zuto:650:${Z.mapText.initializing}`,409,'ZUTO_REFUSED');
  if(arguments.length>2)fail('Zuto admission cannot choose a side.',403,'ZUTO_ORIGIN_REQUIRED');
  const origin=zutoOriginFor(world,p),side=origin?.side;
  if(!side)fail(`zuto:${Z.identity.cate}:${Z.identity.unknown}`,403,'ZUTO_REFUSED');   // "Server cannot be identified."
  if(world.now()>=b.endAt||p.dead||p.sceneTransition||p.progressCommitting||p.tradeId||p.charTradeId)fail('Zuto admission is unavailable in the current state.',409);
  if(p.partyId)fail(`zuto:650:${Z.mapText.inParty}`,409,'ZUTO_REFUSED');
  const level=Number(p.profile?.level)||1;if(level<data.cfg.levels[0]||level>data.cfg.levels[1])fail(`zuto:650:${Z.mapText.level}`,403,'ZUTO_REFUSED');
  const old=b.members.get(p.id);if(old&&old.side!==side)fail('This character already fought for the other side.',409);
  if(old?.evicted)fail('This character was expelled from this battle.',409);
  if(!old&&[...b.members.values()].filter(m=>m.side===side&&!m.left&&!m.evicted).length>=data.cfg.capacity)fail(`zuto:650:${side==='red'?10006:10005}`,409,'ZUTO_REFUSED');
  if(!onField(world,data,p))fail('The member must be on the battlefield.',409);
  const m=old||{id:p.id,account:p.account,characterId:p.characterId,name:p.profile.name,classIndex:p.profile.classIndex,level:p.profile.level,side,worldIndex:origin.worldIndex,kills:0,deaths:0,captures:0,deadAt:null,baseSince:null,left:false,evicted:null};
  m.left=false;b.members.set(p.id,m);return m;
}

function stopSeize(world,data,b,stone,reason){
  const s=stone.seizing;if(!s)return;stone.seizing=null;
  const q=playerById(world,s.playerId);if(q)clearSeizeStatus(world,q);
  if(reason!=='captured'&&q)send(world,data,[q.id],{type:'zutoNotice',cate:Z.ui.cate,code:Z.ui.stopped,stone:stone.index});
}
function applySeizeStatus(world,data,p,until){
  delete p._zutoSeizeClear;
  const buffs=p.profile.buffs||=[],def=data.status;
  for(let i=buffs.length-1;i>=0;i--)if(buffs[i]?.key===SEIZE_KEY)buffs.splice(i,1);
  buffs.push({key:SEIZE_KEY,statusIndex:data.cfg.seizeStatus,name:def.description||'Seizing',description:def.description||'',iconIndex:def.iconIndex??def.icon??null,options:(def.options||[]).map(o=>Array.isArray(o)?{code:o[0],value:o[1]}:{code:o.code,value:o.value}),duration:data.cfg.seizeStatusMs/1000,remaining:(until-world.now())/1000,tick:0,group:def.group,expiresAt:until});
  restat(world,p);
}
function clearSeizeStatus(world,p){
  // A staged inventory/travel save owns the profile while it waits. Defer this
  // cleanup instead of changing that transaction's source behind its clone.
  if(p.sceneTransition||p.progressCommitting||p.commandActive){p._zutoSeizeClear=true;return;}
  delete p._zutoSeizeClear;const buffs=p.profile?.buffs;if(!buffs)return;const n=buffs.length;
  for(let i=buffs.length-1;i>=0;i--)if(buffs[i]?.key===SEIZE_KEY)buffs.splice(i,1);
  if(buffs.length!==n)restat(world,p);
}
function restat(world,p){if(typeof world.data.stats==='function'){p.stats=world.data.stats(p.profile,p,world.now());p.maxHp=p.stats.maxHp;p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp||0,p.stats.maxMp||0);}world.changed(p);}

async function moveHome(world,q){
  // 160:636 "Moving to the saved place.": the DK return point (where the member came from), else its bound return point
  const back=q.profile?.dkReturn;
  const at=back&&[back.map,back.x,back.z].every(Number.isFinite)?{map:back.map,x:back.x,z:back.z,dirDeg:back.dirDeg||0,channel:isDkChannel(back.channel)?0:back.channel??0}:{...boundReturnTarget(world,q.profile),channel:0};
  return commitFieldTravel(world,q,at);
}
async function evict(world,data,b,m,q,reason){
  m.evicted=reason;m.at=world.now();
  for(const stone of b.stones.values())if(stone.seizing?.playerId===m.id)stopSeize(world,data,b,stone,'evicted');
  // a dead member is moved as it is (revive then happens at the saved place); a failed save keeps it here and retries
  if(q){send(world,data,[q.id],{type:'zutoNotice',cate:Z.ui.cate,code:Z.ui.reviveExit,reason});await returnMember(world,m,q);}
}
async function returnMember(world,m,q){
  m.moveFailed=true;if(typeof world.serializeAccount!=='function')return;
  await world.serializeAccount(m.account,async()=>{
    if(!present(world,q)||q.account!==m.account||q.characterId!==m.characterId||q.sceneTransition||q.progressCommitting||q.commandActive)return;
    try{await moveHome(world,q);m.moveFailed=false;}catch{m.moveFailed=true;}
  });
}
function finish(world,data,b,outcome){
  b.phase='end';b.outcome={...outcome,at:world.now(),stones:{red:[...b.stones.values()].filter(s=>s.owner==='red').length,blue:[...b.stones.values()].filter(s=>s.owner==='blue').length}};
  for(const stone of b.stones.values())stopSeize(world,data,b,stone,'end');
  const ids=[...world.players.values()].filter(q=>present(world,q)&&[650,651,652].includes(q.map)&&(q.channel??0)===data.channel).map(q=>q.id);
  send(world,data,ids,outcome.winner?{type:'zutoNotice',cate:160,code:outcome.winner==='red'?638:637}:{type:'zutoNotice',cate:Z.ui.cate,code:Z.ui.draw});
  const achievements={slayer:topOf(b,'kills'),ruler:topOf(b,'captures')};b.outcome.nominees=achievements;b.outcome.achievements=achievements;
  for(const m of b.members.values())if(!m.left&&!m.evicted){
    const rows=zutoRewardRows(data.cfg,b.outcome,m.side);
    for(const [kind,row]of Object.entries(achievements))if(row?.id===m.id)rows.push({kind,item:data.cfg.rewards.achieve[0],count:data.cfg.rewards.achieve[1]});
    b.rewards.set(m.id,{rows,state:'pending',reason:null});
  }
}
// Literal-reading criteria (most kills / most captures, >0, both sides); ENGINE-CHOSEN eligibility and ties: present at the
// end, earliest attainment of the final score, then the earlier accepted kill / capture intent (ZUTO_RULE_STATUS).
function topOf(b,key){const at=key==='kills'?'killAt':'captureAt',seq=key==='kills'?'killSequence':'captureSequence';let best=null;for(const m of b.members.values())if(!m.left&&!m.evicted&&(m[key]||0)>0&&(!best||m[key]>best[key]||m[key]===best[key]&&((m[at]??Infinity)<(best[at]??Infinity)||(m[at]??Infinity)===(best[at]??Infinity)&&(m[seq]??Infinity)<(best[seq]??Infinity))))best=m;return best?{id:best.id,name:best.name,side:best.side,[key]:best[key]}:null;}

/** One atomic save per member; a receipt prevents a second grant for the same battle. */
async function grantRewards(world,b){
  for(const [id,r] of b.rewards){
    if(r.state!=='pending')continue;
    const settle=async()=>{
    const q=playerById(world,id),m=b.members.get(id);
    if(!q||!m||q.account!==m.account||q.characterId!==m.characterId||q.profile?.id!==m.characterId||q.profile?.authority!=='server'||q.sceneTransition||q.progressCommitting||q.tradeCommitting||q.commandActive||q.leaving) return;
    const receipts=q.profile.zuto?.receipts||[];if(receipts.includes(b.id)){r.state='granted';return;}
    const candidate={...q,profile:structuredClone(q.profile)},inv=new AuthoritativeInventory(candidate.profile,world.data.itemDB,{now:world.now,random:world.random});
    if(!r.rows.every(row=>inv.add(row.item,row.count))){r.reason='bag';return;}
    progressDekaPass(world,candidate,2,16,Z.battlefield,1);
    candidate.profile.zuto={...(candidate.profile.zuto||{}),receipts:[...receipts.slice(-(RECEIPTS-1)),b.id]};
    world.changed(candidate);q.sceneTransition=true;q.progressCommitting=true;
    try{await world.persist(candidate);if(present(world,q)&&world.players.get(q.account)===q)for(const key of ['profile','revision','dirty','saveError'])q[key]=candidate[key];r.state='granted';r.reason=null;}
    catch{r.reason='save';}
    finally{q.sceneTransition=false;q.progressCommitting=false;}
    };
    const m=b.members.get(id);if(!m)continue;
    if(typeof world.serializeAccount!=='function'){r.reason='custody';continue;}
    await world.serializeAccount(m.account,settle);
  }
}

// ------------------------------------------------------------------ PvP: members of opposite sides on the battlefield
export function zutoEnemy(world,p,q){
  const L=world.zutoLive,b=L?.battle;if(!running(b)||world.now()>=b.endAt||!p||!q||p===q||p.dead||q.dead)return false;
  const data=zutoData(world);if(!data||!onField(world,data,p)||!onField(world,data,q)||!sameScene(p,q))return false;
  const a=b.members.get(p.id),c=b.members.get(q.id);
  return !!a&&!!c&&!a.left&&!c.left&&!a.evicted&&!c.evicted&&a.side!==c.side;
}
registerPvpMode({enemy:zutoEnemy,opponents:(world,p)=>[...world.players.values()].filter(q=>zutoEnemy(world,p,q)),onDown:(world,attacker,target)=>{
  const b=world.zutoLive?.battle;if(!running(b))return;const a=b.members.get(attacker?.id),t=b.members.get(target?.id);
  const data=zutoData(world);
  if(!data||world.now()>=b.endAt||attacker?.dead||Number(target?.hp)>0||!onField(world,data,attacker)||!onField(world,data,target)||!sameScene(attacker,target)||!a||!t||a.side===t.side||t.downed||a.left||a.evicted||t.left||t.evicted)return;
  a.kills++;a.killAt=world.now();a.killSequence=b.killSequence=(b.killSequence||0)+1;t.deaths++;b.kills[a.side]++;t.downed=true;t.deadAt=world.now();   // one count per death; the tick clears it once the member is alive
}});

// ------------------------------------------------------------------ member command: seize a guardian stone (job 119)
export async function zutoCommand(world,p,input){
  if(!input||input.type!=='zuto'||Object.keys(input).some(k=>!ZUTO_SCHEMAS.zuto.includes(k)))fail('Send Zuto intent only.');
  if(!p||typeof input.token!=='string'||input.token!==p.token)fail('The current world lease is required.',409);
  if(input.operation==='register'){if(input.npcIndex!==undefined&&Number(input.npcIndex)!==REGISTER.npc)fail('Stand near Jerome in Ardeca.',403);return zutoRegister(world,p);}
  if(input.operation!=='seize')fail('Unknown Zuto operation.');
  const data=zutoData(world);if(!data)fail('The original Zuto battlefield data is unavailable.',503);
  if(world.players.get(p.account)!==p||p.leaving||p.dead||p.sceneTransition||p.progressCommitting||p.tradeId||p.charTradeId)fail('Seizing is unavailable while disconnected, dead, travelling or trading.',403);
  const own=memberOf(world,p);if(!own||!running(own.b)||!onField(world,data,p))fail(`zuto:650:${Z.mapText.unavailable}`,403,'ZUTO_REFUSED');
  const {b,m}=own,id=Number(input.npcIndex);
  if(world.now()>=b.endAt)fail(`zuto:650:${Z.mapText.unavailable}`,403,'ZUTO_REFUSED');
  const row=Number.isInteger(id)&&nearbyNpc(world,p,{npcIndex:id,jobType:Z.stoneJob,radius:SEIZE_RANGE});
  const job=row&&row.jobs.find(([t])=>Number(t)===Z.stoneJob);
  if(!row||!job||!offersOriginalJob(world,row,Z.stoneJob,job[1]))fail('Stand next to an original Guardian Stone.',403);
  const stone=b.stones.get(Number(job[1]));if(!stone)fail('Stand next to an original Guardian Stone.',403);
  if(stone.owner===m.side)ui(Z.ui.own);
  if(stone.seizing&&stone.seizing.playerId!==p.id)ui(Z.ui.others);
  if(stone.seizing?.playerId===p.id){
    if(stone.seizing.actor===p&&stone.seizing.token===p.token)return {seizing:stone.index,endAt:stone.seizing.endAt};
    stopSeize(world,data,b,stone,'rejoined');
  }
  for(const other of b.stones.values())if(other!==stone&&other.seizing?.playerId===p.id)stopSeize(world,data,b,other,'switch');
  const now=world.now();stone.seizing={playerId:p.id,side:m.side,startAt:now,endAt:now+data.cfg.captureMs,sequence:++b.captureSequence,actor:p,token:p.token};
  applySeizeStatus(world,data,p,now+data.cfg.seizeStatusMs);
  send(world,data,[p.id],{type:'zutoNotice',cate:Z.ui.cate,code:Z.ui.attempting,stone:stone.index});
  return {seizing:stone.index,endAt:stone.seizing.endAt};
}

// ------------------------------------------------------------------ tick
export async function tickZuto(world){
  for(const p of world.players.values())if(p._zutoSeizeClear&&!p.leaving&&!p.sceneTransition&&!p.progressCommitting&&!p.commandActive)clearSeizeStatus(world,p);
  const data=zutoData(world);if(!data)return;
  // Scheduled battles (time.csv, fixed server time UTC+1) run only where durable registration exists (production social storage).
  if(world.socialState&&!world.zutoLive?.ticking){
    const L0=zutoLive(world),startAt=zutoScheduledStart(data.cfg,world.now());
    if(startAt&&startAt!==L0.lastScheduled&&(!L0.battle||L0.battle.phase==='closed')){L0.lastScheduled=startAt;beginZutoBattle(world,{startAt});}
  }
  const L=world.zutoLive,b=L?.battle;if(!b)return;
  if(b.phase==='closed'){await returnAfterBattle(world,data,b);return;}
  if(L.ticking)return;L.ticking=true;
  try{
    const now=world.now(),cfg=data.cfg,ids=fieldIds(world,data),once=(key,fn)=>{if(!b.announced.has(key)){b.announced.add(key);fn();}};
    if(b.phase!=='end'){
      const phase=zutoPhaseAt(cfg,now,b.startAt);
      const online=[...world.players.values()].filter(q=>present(world,q)).map(q=>q.id);
      if(phase==='init')once('init',()=>send(world,data,online,{type:'zutoNotice',cate:650,code:Z.mapText.init}));
      if(phase==='entry'){once('entry',()=>send(world,data,online,{type:'zutoNotice',cate:650,code:Z.mapText.entry}));if(now>=b.startAt-COUNTDOWN_MS)once('countdown',()=>send(world,data,ids,{type:'zutoNotice',cate:650,code:Z.mapText.countdown}));}
      if(phase==='battle'||phase==='end')once('start',()=>{send(world,data,ids,{type:'zutoNotice',cate:650,code:Z.mapText.start});for(const map of Z.lobbies)send(world,data,[...world.players.values()].filter(q=>present(world,q)&&q.map===map&&(q.channel??0)===data.channel).map(q=>q.id),{type:'zutoNotice',cate:map,code:Z.mapText.start});});
      if(['init','entry','battle'].includes(phase))b.phase=phase;
      else if(phase==='end')b.phase='battle';   // the time-out below closes it, even when no tick ran during the battle
    }
    if(running(b)){
      // members: departures, delayed resurrection (1 minute), base camping (2 minutes)
      for(const m of b.members.values()){
        if(m.left)continue;
        const q=playerById(world,m.id);
        if(m.evicted){if(m.moveFailed&&onField(world,data,q)&&!q.sceneTransition)await returnMember(world,m,q);continue;}
        if(!onField(world,data,q)){if(!q?.sceneTransition){m.left=true;m.at=now;for(const stone of b.stones.values())if(stone.seizing?.playerId===m.id)stopSeize(world,data,b,stone,'left');}continue;}
        if(q.sceneTransition||q.progressCommitting||q.commandActive||q.tradeCommitting)continue;
        const cutoff=Math.min(now,b.endAt);
        if(q.dead){m.deadAt??=cutoff;m.baseSince=null;if(cutoff-m.deadAt>=REVIVE_EXIT_MS)await evict(world,data,b,m,q,'revive');continue;}
        m.deadAt=null;m.downed=false;
        const base=cfg.sides[m.side].base;
        if(Math.hypot(q.x-base.x,q.z-base.z)<=cfg.range){m.baseSince??=cutoff;if(cutoff-m.baseSince>BASE_EXIT_MS)await evict(world,data,b,m,q,'base');}else m.baseSince=null;
      }
      // seizing: 15 s next to the stone, alive, still a member
      for(const stone of b.stones.values()){
        const s=stone.seizing;if(!s)continue;
        const q=playerById(world,s.playerId),m=b.members.get(s.playerId);
        if(!q||q!==s.actor||q.token!==s.token||!m||m.left||m.evicted||q.dead||q.sceneTransition||q.progressCommitting||q.tradeId||q.charTradeId||!onField(world,data,q)||Math.hypot(q.x-stone.x,q.z-stone.z)>SEIZE_RANGE+.75){stopSeize(world,data,b,stone,'interrupted');continue;}
        if(now>=s.endAt){
          if(s.endAt>b.endAt){stopSeize(world,data,b,stone,'timeout');continue;}
          stone.owner=s.side;stone.capturedAt=s.endAt;m.captures++;m.captureAt=s.endAt;m.captureSequence=s.sequence;
          if(b.lastCaptureAt==null||s.endAt>b.lastCaptureAt||(s.endAt===b.lastCaptureAt&&s.sequence>b.lastCaptureSequence)){
            b.lastCaptor=s.side;b.lastCaptureAt=s.endAt;b.lastCaptureSequence=s.sequence;
          }
          stopSeize(world,data,b,stone,'captured');
          send(world,data,[q.id],{type:'zutoNotice',cate:Z.ui.cate,code:Z.ui.captured,stone:stone.index});
          send(world,data,fieldIds(world,data),{type:'zutoStone',stone:stone.index,owner:stone.owner});
        }
      }
      // five stones held for ConquestWinTime, or the time-out order
      const owners=[...b.stones.values()].map(s=>s.owner),side=zutoHoldingSide(cfg,owners);
      if(side!==b.hold.side){b.hold={side,since:side?Math.max(...[...b.stones.values()].filter(s=>s.owner===side).map(s=>s.capturedAt)):null};if(side){const all=fieldIds(world,data),own=all.filter(id=>b.members.get(id)?.side===side);for(const code of [Z.ui.five,Z.ui.almost])send(world,data,own,{type:'zutoNotice',cate:Z.ui.cate,code,side});send(world,data,all,{type:'zutoNotice',cate:Z.ui.cate,code:Z.ui.holdWarning,minutes:cfg.holdMs/60000});}}
      if(b.hold.side&&Math.min(now,b.endAt)-b.hold.since>=cfg.holdMs)finish(world,data,b,{winner:b.hold.side,reason:'conquest'});
      else if(now>=b.endAt)finish(world,data,b,zutoTimeoutOutcome({owners,kills:b.kills,lastCaptor:b.lastCaptor}));
    }
    if(b.phase==='end'){
      await grantRewards(world,b);
      if([...b.rewards.values()].every(r=>r.state==='granted')){b.phase='closed';b.closedAt=now;L.history=[{id:b.id,outcome:b.outcome,members:b.members.size},...L.history].slice(0,10);}
    }
  }finally{L.ticking=false;}
}

/** ENGINE CHOICE: entrants admitted through teleport 133 return to their saved place 60 s after rewards settle. */
async function returnAfterBattle(world,data,b){
  const L=zutoLive(world);if(L.ticking||!Number.isFinite(b.closedAt)||world.now()<b.closedAt+POST_BATTLE_RETURN_MS)return;
  L.ticking=true;
  try{
    for(const m of b.members.values()){
      if(!m.viaEntry||m.returned)continue;
      const q=playerById(world,m.id);
      if(!onField(world,data,q)||q.account!==m.account||q.characterId!==m.characterId){m.returned=true;continue;}
      if(q.sceneTransition||q.progressCommitting||q.commandActive)continue;
      await returnMember(world,m,q);if(!m.moveFailed)m.returned=true;
    }
  }finally{L.ticking=false;}
}

/** Revive a current battle member at its own respawn.csv Ally base on the battlefield (native RespawnType DEFAULT otherwise). */
export async function reviveZuto(world,p,authorize=()=>{}){
  if(!p?.dead||!zutoReviveAt(world,p))return false;
  return world.serializeAccount(p.account,async()=>{
    authorize();
    const at=zutoReviveAt(world,p);if(!p.dead||!at)fail('The Zuto revival scope is no longer available.',403);
    const scene=await world.map(Z.battlefield,null,at.channel),point=scene.nearest(at.x,at.z);if(!point)fail('No safe revive point is available.',503);
    const beforeRevision=p.revision??0,transition=p.sceneTransition;
    const candidate={...p,x:point.x,z:point.z,path:[],dead:false,hp:p.maxHp,mp:p.stats?.maxMp||0};
    world.changed(candidate);p.sceneTransition=true;
    try{
      await world.persist(candidate);
      const intervening=(p.revision??0)-beforeRevision;
      for(const key of ['x','z','path','dead'])p[key]=candidate[key];
      p.revision=(candidate.revision??0)+intervening;p.dirty=!!candidate.dirty||intervening!==0;p.saveError=candidate.saveError||null;
      p.hp=p.maxHp;p.mp=p.stats?.maxMp||0;p.maxShield=Math.max(0,Number(p.stats?.maxShield)||0);p.shield=p.maxShield;delete p.respawnReadyAt;
      world.emit(p.map,{type:'revive',actorId:p.id});
    }finally{p.sceneTransition=transition;}
    return true;
  });
}

// ------------------------------------------------------------------ revive point and snapshot
/** A member's native revive point (respawn.csv Ally_X/Y of its side) while the battle runs; null otherwise. */
export function zutoReviveAt(world,p){const own=memberOf(world,p),data=zutoData(world);if(!own||!running(own.b)||world.now()>=own.b.endAt||!data||!onField(world,data,p))return null;const base=data.cfg.sides[own.m.side].base;return {map:Z.battlefield,x:base.x,z:base.z,dirDeg:base.dirDeg,channel:data.channel};}
export function zutoSnapshot(world,p){
  if(p&&Z.lobbies.includes(p.map)){
    // Zuto's Road lobby: the viewer's own host-assigned side and the battle clock (no other member data).
    const data=zutoData(world),b=world.zutoLive?.battle,reg=data?zutoRegistration(world,p):null;
    return data?{lobby:true,registration:reg?{side:reg.side,season:reg.season}:null,battle:b&&b.phase!=='closed'?{phase:b.phase,startAt:b.startAt,endAt:b.endAt}:null}:null;
  }
  if(!p||p.map!==Z.battlefield)return null;
  const data=zutoData(world),b=world.zutoLive?.battle;if(!data||!b||!onField(world,data,p))return null;
  const m=b.members.get(p.id)||null;
  if(b.phase==='closed'&&(!m||m.returned))return null;
  const publicAwards=Object.fromEntries(Object.entries(b.outcome?.achievements||{}).map(([kind,row])=>{if(!row)return [kind,null];const a=b.members.get(row.id);return [kind,{name:a.name,classIndex:a.classIndex,level:a.level,side:a.side,captures:a.captures,kills:a.kills}];}));
  return {id:b.id,phase:b.phase,startAt:b.startAt,endAt:b.endAt,returnAt:b.closedAt?b.closedAt+POST_BATTLE_RETURN_MS:null,kills:{...b.kills},lastCaptor:b.lastCaptor,hold:{...b.hold,holdMs:data.cfg.holdMs},
    stones:[...b.stones.values()].map(s=>({index:s.index,npc:s.npc,owner:s.owner,seizing:s.seizing?{side:s.seizing.side,endAt:s.seizing.endAt,mine:s.seizing.playerId===p.id}:null})),
    mine:m?{name:m.name,classIndex:m.classIndex,level:m.level,side:m.side,kills:m.kills,deaths:m.deaths,captures:m.captures,left:m.left,evicted:m.evicted,reward:b.rewards.get(m.id)?.state||null,rewardRows:b.rewards.get(m.id)?.rows||[],achievements:Object.entries(b.outcome?.achievements||{}).filter(([,r])=>r?.id===m.id).map(([kind])=>kind)}:null,outcome:b.outcome?{...b.outcome,nominees:publicAwards,achievements:publicAwards}:null};
}
