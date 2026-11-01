// SIEGE RENEW host controller for the active castles 193 / 194 / 195. Rules and provenance:
// src/game/siege-renew-controller-rules.js (+ the native data shape of src/game/siege-renew-rules.js, read-only here).
// core.mjs owns tick / dispatch / snapshot / revive and authoritative per-hit hooks;
// siege.mjs delegates original Renew entrances before touching the classic castle.
// Round 3: the native weekly Lord's Treasure Chest (server/world/siege-renew-chest.mjs), the owner guild's
// peace-time castle (native 100:10 / 100:11), the native UTC+1 schedule zone, and native refusal ladders for guards,
// observers and defender skills. Native defender skills and brokerage tax are active.
// Guard deployment, gate upgrades and Renew spectators are active, with bounded
// adaptation choices documented in their rules/config modules. Per-hit hooks below must be wired before
// public admission: tick-time HP repair cannot authorize combat or undo rewards safely.
//   Durable (social document, one atomic system write each): state.siegeRenew.castles[map] = {owner {guild,name,since} | null,
//     history [{at, kind:'capture'|'end'|'chest', ...}], chest {guild,name,startAt,regeneratedAt,claimed} | null}
//   Live (world.siegeRenewLive): weekly cycle, per-castle battle {instanceId, scene, crystal, participants, prepUntil} and
//     per-castle peace scene of the owner guild {instanceId, scene, participants} outside the battle.
import {randomUUID} from 'node:crypto';
import {registerPvpMode} from './pvp.mjs';
import {sameScene,sceneKey} from './scene.mjs';
import {trackForcedDisplacement} from './movement-authority.mjs';
import {socialRef,socialError} from './social-state.mjs';
import {siegeSystemWrite} from './siege.mjs';
import {nearbyNpc,offersOriginalJob,npcPlacements} from './npc-services.mjs';
import {allianceOfGuild} from './alliance.mjs';
import {initializePets} from './pets.mjs';
import {stageInstanceMembers} from './instances.mjs';
import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';
import {mergeRewardProgress} from './reward-progress.mjs';
import {footprintCells} from '../../src/systems/events/bricks.js';
import {brickDamage} from '../../src/game/siege-rules.js';
import {siegeRenewCastles} from '../../src/game/siege-renew-rules.js';
import {RENEW as R,renewLocation,renewStrongholds,renewGuildRefusal,renewSide,renewNextStart,renewPhaseAt,RENEW_COUNTDOWN} from '../../src/game/siege-renew-controller-rules.js';
import {renewScheduleZone,renewGuardWindow,renewGuardRefusal,renewObserverRefusal} from '../../src/game/siege-renew-service-rules.js';
import {renewChestAfterEnd} from '../../src/game/siege-renew-chest-rules.js';
import {siegeRenewChestData,siegeRenewChestView,siegeRenewChestDistance,claimSiegeRenewChest,SIEGE_RENEW_CHEST_RADIUS} from './siege-renew-chest.mjs';
import {siegeRenewDefenderSkillCommand,siegeRenewDefenderSkillData} from './siege-renew-defender-skills.mjs';
import {observerInfo} from './observer.mjs';
import {enterRenewObserver,pruneRenewObservers,forgetRenewObserver} from './siege-renew-observer.mjs';
import {deploySiegeRenewGuard,siegeRenewGuardDataReady} from './siege-renew-guards.mjs';
import {syncSiegeRenewGuards} from './siege-renew-sentries.mjs';
import {siegeRenewProposedEnabled} from '../../src/config/engine-chosen-siege-renew.js';
import {SERVER_TIME_OFFSET_MINUTES} from '../../src/game/server-time.js';
import {resetRenewTax} from '../../src/game/siege-renew-tax-rules.js';
import {siegeRenewTaxCommand,siegeRenewTaxView} from './siege-renew-tax.mjs';
import {siegeRenewGateDataReady,syncSiegeRenewGates,clearSiegeRenewGates,rewardSiegeRenewGate,siegeRenewGateView,siegeRenewGateCommand} from './siege-renew-gates.mjs';

// selection: defender-skill menu row; trigger: native chest trigger index;
// sentry / x / z: native guard type and transposed native map cell.
export const SIEGE_RENEW_SCHEMAS={siegerenew:['token','type','operation','npcIndex','location','selection','trigger','sentry','x','z','day','group','targetLevel']};
export const SIEGE_RENEW_OPERATIONS=['enter','leave','warpstone','stronghold','castellan','jegarr','tax','sentry','skill','observer','chest','gate'];
const fail=(message,status=400)=>{try{socialError(message,status);}catch(error){if(status===409)error.code='SIEGE_RENEW_REFUSED';throw error;}};
const native=([cate,code],status=409)=>fail(`siege:${cate}:${code}`,status);   // the client already shows `siege:<cate>:<code>` texts
const TICK_MS=250,HIT_RING=2;   // HIT_RING: the same engine choice as the classic objects (src/config/engine-chosen-siege.js)

// ------------------------------------------------------------------ original data (fail closed)
const cache=new WeakMap();
export function siegeRenewControllerData(world){
  const host=world?.data;if(!host||typeof host!=='object')return null;
  if(cache.has(host))return cache.get(host);
  let out=null;
  try{out=readData(world);}catch{out=null;}
  cache.set(host,out);return out;
}
function readData(world){
  const castles=siegeRenewCastles(world.data.eventData),npcs=world.data.progression?.npcs,quests=world.data.progression?.quests?.quests;
  if(castles.length!==3||!castles.every(c=>R.castles.includes(c.map)&&c.active))return null;
  const cfg=castles[0].cfg;if(!(cfg.capacity>0&&cfg.durationMs>0&&cfg.guildLevel>0&&cfg.members>0))return null;
  const questById=id=>Array.isArray(quests)?quests.find(q=>q.id===id):quests?.[id];
  const warpTo=from=>{const w=(world.data.travelData?.warps||[]).find(x=>Number(x.from)===Number(from));const r=w&&world.data.travelData.locations?.[w.to];return r?{map:Number(r[0]),x:Number(r[1])+.5,z:Number(r[2])+.5,dirDeg:Number(r[3])||0}:null;};
  const questWarp=id=>{const loc=questById(id)?.rewards?.warp?.loc;return loc?warpTo(loc):null;};
  const placedAnywhere=id=>Object.entries(npcs?.placements||{}).flatMap(([map,p])=>(p.rows||[]).filter(r=>Number(r[0])===id).map(r=>({map:Number(map),x:Number(r[1]),z:Number(r[2])})));
  // Native entrance text 100:10 states the zone of START_HOUR (UTC+1); without it the controller keeps the UTC fallback.
  const zone=renewScheduleZone(world.data.eventData?.txt?.('stringtable_siege.txt',100,10),cfg);
  const out={cfg,castles:new Map(),zoneOffsetMin:SERVER_TIME_OFFSET_MINUTES,zoneSource:'native 100:10 / shared server time'};
  for(const c of castles){
    const crystal=c.placements.find(pl=>Number(pl.uid)===R.guardian[c.map]?.[0]&&Number(pl.brick)===R.guardian[c.map]?.[1]&&Number(pl.isCreate)===1&&pl.def&&Number(pl.def.maxHP)>0);
    const defend=renewLocation(c,1),attack=renewLocation(c,2),back=renewLocation(c,3);
    const entrance=Object.entries(npcs?.npcs||{}).find(([,d])=>d.jobs?.some(([t,i])=>Number(t)===R.entranceJob&&Number(i)===c.map));
    const lorenzo=npcPlacements(world,c.map).find(r=>r.jobs.some(([t,i])=>Number(t)===R.defenderTeleportJob&&Number(i)===c.map));
    if(!crystal||!defend||!attack||!back||back.map!==150||!entrance||!placedAnywhere(Number(entrance[0])).length||!lorenzo)return null;
    out.castles.set(c.map,{...c,crystal,defend,attack,back,castellan:renewLocation(c,5),strongholds:renewStrongholds(c),entranceNpc:Number(entrance[0]),lorenzo:lorenzo.npcIndex,
      warpStone:{npc:R.warpStones[c.map],to:questWarp(R.warpStoneQuest[c.map])},jegarr:{npc:R.jegarr[c.map],to:questWarp(R.jegarrQuest[c.map])}});
  }
  return out;
}

// ------------------------------------------------------------------ durable state and guild helpers
const emptyCastle=()=>({owner:null,history:[]});
const renewOf=state=>{state.siegeRenew||={castles:{}};for(const m of R.castles)state.siegeRenew.castles[m]||=emptyCastle();return state.siegeRenew;};
const castleView=(state,map)=>state?.siegeRenew?.castles?.[map]||emptyCastle();
const guildOfRef=(state,ref)=>Object.values(state?.guilds||{}).find(g=>g.members?.some(m=>m.ref===ref))||null;
// same reading as server/world/guilds.mjs level(): an explicit level, else the LEVELSTEP thresholds of the guild point
function guildLevel(world,g){if(Number.isInteger(g?.level))return g.level;let n=1;for(let i=1;i<=15;i++)if(Number(g?.gpoint)>=Number(world.data.guild?.config?.[`LEVELSTEP${i}`]))n=i;return n;}
const allied=(state,a,b)=>{const x=allianceOfGuild(state,a);return !!x&&x.guilds.includes(b);};

// ------------------------------------------------------------------ live state
export const siegeRenewLive=world=>{const L=world.siegeRenewLive||={startAt:null,forcedStart:null,announced:new Set(),battles:new Map(),lastTick:0,running:false};L.peace||=new Map();L.peaceLoading||=new Map();return L;};
const present=(world,q)=>!!q&&world.players.get(q.account)===q&&!q.leaving;
const playerById=(world,id)=>{for(const q of world.players.values())if(q.id===id&&!q.leaving)return q;return null;};
const inCastle=(b,q)=>!!q&&q.instanceId===b.instanceId&&q.map===b.map;
const castlePlayers=(world,b)=>[...world.players.values()].filter(q=>present(world,q)&&inCastle(b,q));
function battleOf(world,p){for(const b of siegeRenewLive(world).battles.values())if(inCastle(b,p))return b;return null;}
function peaceOf(world,p){for(const k of siegeRenewLive(world).peace.values())if(inCastle(k,p))return k;return null;}
/** The castle scene record holding p: the running battle, else the owner guild's peace scene, else null. */
const sceneOf=(world,p)=>battleOf(world,p)||peaceOf(world,p);
function participant(world,b,p){
  if(!present(world,p)||!inCastle(b,p))return null;
  const r=b.participants.get(p.id),guild=guildOfRef(world.socialState,socialRef(p));
  return r&&guild?.id===r.guild?r:null;
}
function notice(world,players,[cate,code],args=[]){for(const q of players)world.emit(q.map,{type:'siegeNotice',mode:'siegeRenew',code:[cate,code],args,recipients:[q.id]});}
const everyone=world=>[...world.players.values()].filter(q=>!q.leaving);

// ------------------------------------------------------------------ crystal (the castle's Guardian Stone)
function spawnCrystal(world,b,castle){
  const scene=b.scene,obj=castle.crystal,def=obj.def,hp=Number(def.defaultHP)||Number(def.maxHP);
  const cells=footprintCells(obj.x,obj.z,obj.dir,def.widthSize||1,def.heightSize||1).filter(([x,z])=>x>=0&&z>=0&&x<scene.width&&z<scene.height).map(([x,z])=>({i:z*scene.width+x,x,z}));
  const col=scene.collision,own=new Set(cells.map(c=>c.i));
  for(let ring=0;ring<HIT_RING&&col?.walkableCell;ring++)for(const c of [...cells])for(let dz=-1;dz<=1;dz++)for(let dx=-1;dx<=1;dx++){const x=c.x+dx,z=c.z+dz,i=z*scene.width+x;if(x<0||z<0||x>=scene.width||z>=scene.height||own.has(i)||col.walkableCell(x,z))continue;own.add(i);cells.push({i,x,z});}
  const id=`renew:${b.id}:${obj.uid}`,old=new Map(cells.map(c=>[c.i,col?.cells?.[c.i]]));
  const m={id,uid:obj.uid,renewObject:true,isBrick:true,brickIndex:obj.brick,map:b.map,instanceId:b.instanceId,channel:0,x:obj.x,z:obj.z,dir:obj.dir,name:def.name,
    hp,maxHp:Number(def.maxHP)||hp,_hp:hp,dead:false,targetId:null,respawnAt:Infinity,respawnSec:Infinity,home:{x:obj.x,z:obj.z},brickDef:def,
    def:{level:Number(def.level)||1,exp:0,def:[0],money:[0,0,0],name:def.name,role:'object',attackable:true},objectFootprint:cells,_cells:old};
  scene.monsters.set(id,m);block(scene,m,true);return m;
}
function block(scene,m,on){if(!scene.collision?.cells)return;for(const c of m.objectFootprint)scene.collision.cells[c.i]=on?1:(m._cells.get(c.i)??scene.collision.cells[c.i]);}
function canDamage(world,b,p){
  if(!p||p.dead||b.phase!=='battle'||b.capturing||world.now()>=b.endAt||world.now()<b.prepUntil)return false;
  const r=participant(world,b,p),state=world.socialState,owner=castleView(state,b.map).owner?.guild||null;
  return !!r&&r.side==='attacker'&&r.guild!==owner&&!(owner&&allied(state,r.guild,owner));
}
const oneHit=p=>!!(p?.gmAuthorized&&p.profile?.gm?.onehit);
export const isSiegeRenewObject=m=>!!m?.renewObject&&([36995,36996,36997].includes(Number(m.brickIndex))||m.renewGate===true&&Number(m.brickIndex)>=36998&&Number(m.brickIndex)<=37012);
/** Authority before HP mutation, also for delayed skill/proc/servant hits. */
export function siegeRenewObjectActive(world,p,m){
  const b=world.siegeRenewLive?.battles.get(Number(m?.map));
  return !!b&&isSiegeRenewObject(m)&&(b.crystal===m||m.renewGate&&b.gates?.get(m.uid)===m)&&b.scene.monsters.get(m.id)===m&&!m.dead&&sameScene(p,m)&&canDamage(world,b,p);
}
/** Native brick resistance once, before HP mutation. Unrelated targets pass through. */
export function siegeRenewObjectDamage(world,p,m,amount,kind='melee'){
  if(!isSiegeRenewObject(m))return amount;
  if(!siegeRenewObjectActive(world,p,m))return 0;
  const damage=oneHit(p)?m.hp:brickDamage(m.brickDef,amount,kind);
  if(damage>0)m._acceptedHit={source:p.id,guild:participant(world,world.siegeRenewLive.battles.get(m.map),p).guild,hp:m.hp,at:world.now()};
  return damage;
}
/** Original brick elemental fields are percentages, with no ordinary90% cap. */
export function siegeRenewObjectElementDamage(m,amount,element,elementPct){
  const key={fire:'FireResist',ice:'IceResist',lightning:'LightResist',poison:'PoisonResist',curse:'CurseResist',dark:'DarkResist','dark?':'DarkResist'}[element];
  if(!isSiegeRenewObject(m)||!key)return amount;
  const pct=v=>Math.max(0,Math.min(100,Number(v)||0));
  return Math.max(0,Math.round(amount*(1-pct(elementPct||100)/100*pct(m.brickDef.raw?.[key])/100)));
}
/** Reward routing must call this before ordinary monster quests/kills/loot. */
export function rewardSiegeRenewObject(world,p,m){
  if(!isSiegeRenewObject(m))return false;
  const b=world.siegeRenewLive?.battles.get(Number(m.map)),hit=m._acceptedHit;
  if(m.renewGate)return rewardSiegeRenewGate(world,p,m,!!b&&canDamage(world,b,p));
  if(!b||b.crystal!==m||b.scene.monsters.get(m.id)!==m||b.capturing||m.hp>0)return true;
  // A lethal hit must be the same accepted attacker; never infer attribution
  // from the latest damage event or a monster's mutable targetId.
  if(!hit||hit.source!==p?.id||!canDamage(world,b,p)||participant(world,b,p)?.guild!==hit.guild){m.dead=false;m.hp=hit?.hp||m.maxHp;return true;}
  m.dead=true;m.respawnAt=Infinity;b.capturing=true;
  b.takeover=takeover(world,b,m,p,hit).catch(error=>{b.lastError=error.message;}).finally(()=>{b.capturing=false;});
  return true;
}
async function takeover(world,b,m,p,hit){
  const r=b.participants.get(p.id),now=world.now(),castle=siegeRenewControllerData(world).castles.get(b.map);
  const before=hit.hp;
  try{
    await siegeSystemWrite(world,state=>{
      const g=state.guilds?.[r?.guild];if(!g||guildOfRef(state,socialRef(p))?.id!==g.id||b.phase!=='battle')return false;
      const s=renewOf(state).castles[b.map],old=s.owner;
      s.owner={guild:g.id,name:g.name,since:now};
      s.history=[{at:now,kind:'capture',guild:g.id,name:g.name,from:old?.guild||null},...(s.history||[])].slice(0,20);
      // AUTHENTICATED (guide32): deployed guards reset when the defending guild changes.
      if(old?.guild!==g.id){if(s.guards?.length)s.guards=[];delete s.gateLevels;}
      return true;
    });
  }catch(error){m.dead=false;m.hp=Math.max(1,before);m._hp=m.hp;throw error;}   // failed save: ownership and the stone stay as they were
  if(castleView(world.socialState,b.map).owner?.guild!==r?.guild){m.dead=false;m.hp=Math.max(1,before);m._hp=m.hp;return;}
  if(siegeRenewProposedEnabled(world))syncSiegeRenewGuards(world,b);
  m.dead=false;m.hp=m.maxHp;m._hp=m.hp;delete m._acceptedHit;block(b.scene,m,true);
  b.prepUntil=now+R.preparationMs;b.log.push({at:now,kind:'capture',guild:r.guild});syncSiegeRenewGates(world,b,castle);
  for(const q of castlePlayers(world,b)){const x=b.participants.get(q.id);if(x)x.side=renewSide(r.guild,x.guild);}
  const name=castleView(world.socialState,b.map).owner.name,players=castlePlayers(world,b);
  notice(world,players,R.text.destroyed,[name]);
  for(const q of players){if(b.spectators?.has(q.id))continue;if(q.sceneTransition){(b.relocations||=new Set()).add(q.id);continue;}placeAt(world,b,q,b.participants.get(q.id)?.side==='defender'?castle.defend:castle.attack);}
}

// ------------------------------------------------------------------ scenes and movement
function placeAt(world,b,q,at){const point=at&&b.scene.nearest?.(at.x,at.z);if(!point){b.lastError='Native castle destination has no walkable point.';return false;}q.x=point.x;q.z=point.z;q.path=[];q.yaw=-(Number(at.dirDeg)||0)*Math.PI/180;trackForcedDisplacement(world,q);world.changed(q);world.emit(q.map,{type:'siegeMove',actorId:q.id,x:q.x,z:q.z,instanceId:b.instanceId,recipients:[q.id]});return true;}
async function enterCastle(world,b,castle,p,at){
  const before={map:p.map,channel:p.channel??0,instanceId:p.instanceId||null};p.sceneTransition=true;
  try{
    const point=b.scene.nearest(at.x,at.z);if(!point)native(R.text.cannotEnter,503);
    const profile=structuredClone(p.profile);initializePets(profile);
    // the saved instance resolves to the castle return point in Ardeca on reconnect (instances.mjs restoreInstance)
    profile.instance={id:b.instanceId,kind:'siegeRenew',map:b.map,exit:{map:castle.back.map,x:castle.back.x,z:castle.back.z}};
    const staged=stageInstanceMembers(world,[p],[profile]),candidate=staged.candidates[0];
    Object.assign(candidate,{map:b.map,channel:0,instanceId:b.instanceId,x:point.x,z:point.z,path:[],mount:null,pet:null,smartWarp:null});
    world.changed(candidate);await world.persist(candidate);
    await staged.commit();p.channel=0;p.yaw=-(Number(at.dirDeg)||0)*Math.PI/180;p.smartWarp=null;
  }finally{p.sceneTransition=false;}
  world.emit(before.map,{type:'leave',actorId:p.id,channel:before.channel??0,instanceId:before.instanceId||null});world.emit(p.map,{type:'join',actorId:p.id});
}
async function exitCastle(world,b,castle,p){
  const at=castle.back;p.sceneTransition=true;
  try{
    const scene=await world.map(at.map,null,0),point=scene.nearest(at.x,at.z);if(!point)fail('No safe castle return point is available.',503);
    const profile=structuredClone(p.profile);delete profile.instance;
    const staged=stageInstanceMembers(world,[p],[profile]),candidate=staged.candidates[0];
    Object.assign(candidate,{map:at.map,channel:0,instanceId:null,x:point.x,z:point.z,path:[],mount:null,pet:null});
    world.changed(candidate);await world.persist(candidate);
    await staged.commit();p.channel=0;p.yaw=0;
  }finally{p.sceneTransition=false;}
  b.participants.delete(p.id);
  if(b.spectators?.has(p.id))forgetRenewObserver(world,b,p);
  world.emit(b.map,{type:'leave',actorId:p.id,instanceId:b.instanceId});world.emit(p.map,{type:'join',actorId:p.id});
}

// ------------------------------------------------------------------ battle lifecycle
async function beginBattles(world,data,startAt){
  const L=siegeRenewLive(world);
  const prepared=[];
  try{for(const castle of data.castles.values()){
      if(L.battles.has(castle.map))continue;
      if(!siegeRenewGateDataReady(world,castle))native(R.text.noInfo,503);
      // ENGINE CHOICE: an owner-guild peace scene becomes this castle's battle scene; its occupants stay inside as
      // defenders (their saved instance already names this scene and resolves to Ardeca on reconnect).
      const peace=L.peace.get(castle.map)||null,id=randomUUID().slice(0,8),instanceId=peace?peace.instanceId:`renew-${castle.map}-${id}`,scene=peace?peace.scene:await world.map(castle.map,instanceId);
      const b={kind:'battle',id,map:castle.map,instanceId,scene,startAt,endAt:startAt+data.cfg.durationMs,phase:'battle',prepUntil:0,participants:new Map(),log:[],crystal:null,capturing:false,fromPeace:!!peace};prepared.push({castle,b,peace});
      for(const at of [castle.defend,castle.attack])if(!scene.nearest(at.x,at.z))native(R.text.noInfo,503);
    }
    if(prepared.length)await siegeSystemWrite(world,state=>resetRenewTax(state,startAt));
    for(const{castle,b,peace}of prepared){
      b.crystal=spawnCrystal(world,b,castle);
      if(peace){const owner=castleView(world.socialState,castle.map).owner?.guild||null;for(const [id,r]of peace.participants)b.participants.set(id,{...r,side:renewSide(owner,r.guild)});L.peace.delete(castle.map);}
      L.battles.set(castle.map,b);
      if(siegeRenewProposedEnabled(world))syncSiegeRenewGuards(world,b);
      syncSiegeRenewGates(world,b,castle);
    }
  }catch(error){for(const{castle,b,peace}of prepared){clearSiegeRenewGates(b);if(b.crystal){block(b.scene,b.crystal,false);b.scene.monsters.delete(b.crystal.id);}L.battles.delete(b.map);if(peace){L.peace.set(b.map,peace);syncSiegeRenewGates(world,peace,castle);}else world.maps.delete(sceneKey(b.map,b.instanceId));}throw error;}
  notice(world,everyone(world),R.text.startNow);
}
/** The owner guild's peace scene of a castle (created on first entry; one per castle). */
async function peaceScene(world,castle){
  const L=siegeRenewLive(world),known=L.peace.get(castle.map);if(known)return known;
  if(!siegeRenewGateDataReady(world,castle))native(R.text.noInfo,503);
  const loading=L.peaceLoading.get(castle.map);if(loading)return loading;
  const id=randomUUID().slice(0,8),instanceId=`renew-${castle.map}-${id}`;
  const task=(async()=>{
    const scene=await world.map(castle.map,instanceId);
    if(L.battles.has(castle.map)||!scene.nearest(castle.defend.x,castle.defend.z)){world.maps.delete(sceneKey(castle.map,instanceId));native(L.battles.has(castle.map)?R.text.cannotEnter:R.text.noInfo,L.battles.has(castle.map)?409:503);}
    const k={kind:'peace',id,map:castle.map,instanceId,scene,phase:'peace',startAt:null,endAt:Infinity,prepUntil:0,participants:new Map(),log:[],crystal:null,capturing:false};
    L.peace.set(castle.map,k);if(siegeRenewProposedEnabled(world))syncSiegeRenewGuards(world,k);syncSiegeRenewGates(world,k,castle);return k;
  })();
  L.peaceLoading.set(castle.map,task);
  try{return await task;}finally{if(L.peaceLoading.get(castle.map)===task)L.peaceLoading.delete(castle.map);}
}
/** Peace upkeep: drop stale reservations, return non-owner-guild occupants to Ardeca (native 100:10: only the defending
 * guild is inside outside the battle), release an empty scene. */
async function tickPeace(world,data,L,k){
  const castle=data.castles.get(k.map),state=world.socialState,owner=castleView(state,k.map).owner?.guild||null;
  for(const [id]of k.participants){const q=playerById(world,id);if(!q||!inCastle(k,q))if(!q?.sceneTransition)k.participants.delete(id);}
  for(const q of castlePlayers(world,k)){if(q.sceneTransition||(owner&&guildOfRef(state,socialRef(q))?.id===owner))continue;try{await exitCastle(world,k,castle,q);}catch{k.exitRetry=true;}}
  if(L.peace.get(k.map)===k&&!k.participants.size&&!castlePlayers(world,k).length){world.maps.delete(sceneKey(k.map,k.instanceId));L.peace.delete(k.map);}
}
async function endBattle(world,data,b){
  b.phase='ending';const castle=data.castles.get(b.map),now=world.now(),owner=castleView(world.socialState,b.map).owner;
  // AUTHENTICATED NATIVE RULE (guide 32): the Lord's Treasure Chest regenerates at the end of every siege, for the guild
  // holding the castle at the end; written in the same durable end record.
  await siegeSystemWrite(world,state=>{const s=renewOf(state).castles[b.map];s.history=[{at:now,kind:'end',startAt:b.startAt,owner:s.owner?.guild||null,name:s.owner?.name||null,participants:b.participants.size},...(s.history||[])].slice(0,20);s.chest=renewChestAfterEnd(s.owner,{startAt:b.startAt,endedAt:now});if(s.skills)delete s.skills;   /* proposed cooldown default: cleared by the end record */return true;});
  b.phase='end';b.historyError=null;
  clearSiegeRenewGates(b);
  if(b.crystal){block(b.scene,b.crystal,false);b.scene.monsters.delete(b.crystal.id);b.crystal=null;}
  if(owner)notice(world,everyone(world),R.text.victorious,[owner.name,castle.name]);
  notice(world,castlePlayers(world,b),R.text.ended);
}
async function drainEnded(world,data,b){
  const castle=data.castles.get(b.map);
  for(const q of castlePlayers(world,b)){if(q.sceneTransition)continue;try{await exitCastle(world,b,castle,q);}catch{b.exitRetry=true;}}
  if(!castlePlayers(world,b).length&&!b.spectators?.size){world.maps.delete(sceneKey(b.map,b.instanceId));siegeRenewLive(world).battles.delete(b.map);}
}

/** Advance the weekly cycle and the running castles (proposed core tick hook). */
export function tickSiegeRenew(world,{force=false}={}){
  const data=world.socialState&&siegeRenewControllerData(world);if(!data)return null;
  const L=siegeRenewLive(world),now=world.now();
  if(L.running||(!force&&now-L.lastTick<TICK_MS))return L.running||null;
  L.lastTick=now;L.running=run(world,data,L,now).catch(error=>{L.error=error.message;}).finally(()=>{L.running=false;});
  return L.running;
}
async function run(world,data,L,now){
  const running=[...L.battles.values()][0];
  const startAt=running?.startAt??L.forcedStart??renewNextStart(now,data.cfg,data.zoneOffsetMin);L.startAt=startAt;
  for(const [min,code] of RENEW_COUNTDOWN){const at=startAt-min*60000,key=`${startAt}:${min}`;if(now>=at&&now<at+60000&&!L.announced.has(key)){L.announced.add(key);notice(world,everyone(world),code);}}
  if(!L.battles.size&&renewPhaseAt(now,startAt,data.cfg)==='battle')await beginBattles(world,data,startAt);
  for(const k of [...L.peace.values()])if(!L.battles.has(k.map))await tickPeace(world,data,L,k);
  for(const b of [...L.battles.values()]){
    pruneRenewObservers(world,b);
    if(b.phase==='battle'){
      for(const id of b.relocations||[]){const q=playerById(world,id);if(!q||!inCastle(b,q)){b.relocations.delete(id);continue;}if(q.sceneTransition)continue;const castle=data.castles.get(b.map);placeAt(world,b,q,b.participants.get(id)?.side==='defender'?castle.defend:castle.attack);b.relocations.delete(id);}
      for(const [id] of b.participants){const q=playerById(world,id);if(!q||!inCastle(b,q))if(!q?.sceneTransition)b.participants.delete(id);}
      if(now>=b.endAt&&!b.capturing)try{await endBattle(world,data,b);}catch(error){b.historyError=error.message;}
    }
    else if(b.phase==='ending')try{await endBattle(world,data,b);}catch(error){b.historyError=error.message;}
    if(b.phase==='end')await drainEnded(world,data,b);
  }
  if(L.forcedStart!=null&&!L.battles.size&&now>=L.forcedStart+data.cfg.durationMs)L.forcedStart=null;
}
/** Test/GM start: begin a cycle now. */
export async function startSiegeRenewNow(world){const L=siegeRenewLive(world);L.forcedStart=world.now();L.lastTick=0;await tickSiegeRenew(world,{force:true});if(!L.battles.size&&L.error)throw Object.assign(Error(L.error),{status:503});return [...L.battles.values()];}

// ------------------------------------------------------------------ PvP: participants of different, non-allied guilds in one castle
export function siegeRenewEnemy(world,p,q){
  const b=p&&battleOf(world,p);if(!b||b.phase!=='battle'||world.now()>=b.endAt||!q||p===q||p.dead||q.dead||!inCastle(b,q)||!sameScene(p,q))return false;
  const a=participant(world,b,p),c=participant(world,b,q),state=world.socialState;
  return !!a&&!!c&&a.guild!==c.guild&&!allied(state,a.guild,c.guild);
}
registerPvpMode({enemy:siegeRenewEnemy,opponents:(world,p)=>[...world.players.values()].filter(q=>siegeRenewEnemy(world,p,q))});

// ------------------------------------------------------------------ commands
export async function siegeRenewCommand(world,p,input){
  if(!input||input.type!=='siegerenew'||Object.keys(input).some(k=>!SIEGE_RENEW_SCHEMAS.siegerenew.includes(k)))fail('Send siege intent only.');
  const op=input.operation;if(!SIEGE_RENEW_OPERATIONS.includes(op))fail('Unknown siege operation.');
  const data=siegeRenewControllerData(world);if(!data||!world.socialState)native(R.text.noInfo,503);
  if(world.players.get(p.account)!==p||p.leaving||p.dead||p.sceneTransition||p.tradeId)fail('This service is unavailable while disconnected, dead, travelling or trading.',409);
  await tickSiegeRenew(world,{force:true});
  const L=siegeRenewLive(world),state=world.socialState,ref=socialRef(p),g=guildOfRef(state,ref);
  const near=(id,type,index,radius=8)=>{const row=Number.isInteger(id)&&nearbyNpc(world,p,{npcIndex:id,jobType:type,...(index!=null?{jobIndex:index}:{}),radius});if(!row||!offersOriginalJob(world,row,type,index??row.jobs.find(([t])=>Number(t)===type)?.[1]))fail('Stand near the original castle NPC.',403);return row;};
  if(op==='enter'){
    const id=Number(input.npcIndex),row=Number.isInteger(id)&&nearbyNpc(world,p,{npcIndex:id,jobType:R.entranceJob,radius:8});
    const map=row&&Number(row.jobs.find(([t])=>Number(t)===R.entranceJob)?.[1]),castle=data.castles.get(map);
    if(!row||!castle||!offersOriginalJob(world,row,R.entranceJob,map))fail('Stand near the original castle entrance.',403);
    if(p.instanceId||p.mount)native(R.text.cannotEnter,403);
    const b=L.battles.get(map);
    // AUTHENTICATED NATIVE RULE 100:10 / 100:11: "Only the defending guild can enter outside Siege battle."
    if(!b){
      const owner=castleView(state,map).owner?.guild||null;if(!g||!owner||owner!==g.id)native(R.text.notInProgress);
      const k=await peaceScene(world,castle);
      if(L.battles.has(map)||L.peace.get(map)!==k||k.participants.size>=data.cfg.capacity)native(R.text.cannotEnter);
      const record={id:p.id,account:p.account,characterId:p.characterId,name:p.profile.name,guild:g.id,side:'defender',joinedAt:world.now()};
      k.participants.set(p.id,record);
      try{await enterCastle(world,k,castle,p,castle.defend);}
      catch(error){if(k.participants.get(p.id)===record)k.participants.delete(p.id);throw error;}
      return {entered:map,side:'defender',peace:true};
    }
    if(b.phase!=='battle')native(R.text.notInProgress);
    const refusal=renewGuildRefusal(data.cfg,{guild:g?.id,level:g?guildLevel(world,g):0,members:g?.members?.length||0});if(refusal)native(refusal,403);
    const owner=castleView(state,map).owner?.guild||null,side=renewSide(owner,g.id);
    if(side==='attacker'&&world.now()<b.prepUntil)native(R.text.cannotEnter);
    // Reservations include an accepted member whose durable scene save has not
    // yet published. Concurrent accounts must not exceed the native300 limit.
    if(b.participants.size>=data.cfg.capacity)native(R.text.cannotEnter);
    const record={id:p.id,account:p.account,characterId:p.characterId,name:p.profile.name,guild:g.id,side,joinedAt:world.now()};
    b.participants.set(p.id,record);
    try{await enterCastle(world,b,castle,p,side==='defender'?castle.defend:castle.attack);}
    catch(error){if(b.participants.get(p.id)===record)b.participants.delete(p.id);throw error;}
    return {entered:map,side};
  }
  const b=sceneOf(world,p),castle=b&&data.castles.get(b.map);
  if(op==='tax'){
    const check=()=>{near(Number(input.npcIndex),R.taxJob,0);if(L.battles.size)native(R.text.taxInBattle);if(!b||!castle||sceneOf(world,p)!==b)native(R.text.siegeMapOnly,403);};
    check();return siegeRenewTaxCommand(world,p,{map:b.map,cfg:data.cfg,day:input.day,check});
  }
  if(op==='skill')return siegeRenewDefenderSkillCommand(world,p,input);
  if(op==='gate'){
    near(Number(input.npcIndex),R.sentryJob,0);if(!b||!castle)native(R.text.siegeMapOnly,403);
    // socialTransaction owns sceneTransition while it stages the durable debit;
    // its lease check rejects a pre-existing transition before this callback.
    const check=()=>{if(p.leaving||!inCastle(b,p)||world.maps.get(sceneKey(b.map,b.instanceId))!==b.scene||(b.kind==='peace'?L.peace.get(b.map)!==b||L.battles.has(b.map):L.battles.get(b.map)!==b))native(R.text.noInfo);near(Number(input.npcIndex),R.sentryJob,0);};
    return siegeRenewGateCommand(world,p,{b,castle,input,check});
  }
  if(op==='sentry'){
    near(Number(input.npcIndex),R.sentryJob,0);if(!b||!castle)native(R.text.siegeMapOnly,403);
    const refusal=renewGuardRefusal({window:renewGuardWindow({battle:b.kind==='battle'?b:null,now:world.now()}),guild:g?.id||null,owner:castleView(state,b.map).owner?.guild||null,master:!!g&&g.master===ref});
    if(refusal)native(refusal,refusal[1]===213?409:403);
    // Readiness / emergency-disable gate follows the native permission ladder.
    if(!siegeRenewProposedEnabled(world))native(R.text.notYet);
    // Recheck scene/window within the same transaction as the guard row and DIL.
    const check=()=>{const open=b.kind==='peace'?L.peace.get(b.map)===b&&!L.battles.has(b.map):L.battles.get(b.map)===b&&renewGuardWindow({battle:b,now:world.now()})==='preparation';if(!open||!inCastle(b,p)||world.maps.get(sceneKey(b.map,b.instanceId))!==b.scene)native(R.text.guardPrep);};
    check();
    const result=await deploySiegeRenewGuard(world,p,{scene:b.scene,castle,cfg:data.cfg,input,check});syncSiegeRenewGuards(world,b);return result;
  }
  if(op==='observer'){
    const id=Number(input.npcIndex),row=Number.isInteger(id)&&nearbyNpc(world,p,{npcIndex:id,jobType:R.observerJob,radius:8}),map=row&&Number(row.jobs.find(([t])=>Number(t)===R.observerJob)?.[1]);
    if(!row||!data.castles.has(map)||!offersOriginalJob(world,row,R.observerJob,map))fail('Stand near the original castle entrance.',403);
    await enterRenewObserver(world,p,{venue:`renew-${map}`,npcIndex:id});
    return {observerResult:{operation:'enter',...await observerInfo(world,p)}};
  }
  if(!b||!castle)fail('You are not in a castle.',403);
  // Leaving is always possible for anyone standing in a castle scene (reservation or not).
  if(op==='leave'){await exitCastle(world,b,castle,p);return {left:b.map};}
  const r=b.participants.get(p.id);if(!r)fail('You are not a participant of this castle.',403);
  if(op==='chest'){
    const entry=siegeRenewChestData(world)?.get(b.map);if(!entry)native(R.text.noInfo,503);
    if(Number(input.trigger)!==entry.trigger)fail('Choose the original castle chest.');
    if(siegeRenewChestDistance(world,p,b.map)>SIEGE_RENEW_CHEST_RADIUS)fail('Stand near the original castle chest.',403);
    if(b.kind!=='peace')native(R.text.inBattle);   // guide 32: from the end of the siege until the next siege begins
    const token=p.token;
    const check=()=>{
      if(L.battles.has(b.map))native(R.text.inBattle);
      if(!present(world,p)||p.token!==token||p.dead||L.peace.get(b.map)!==b||!inCastle(b,p)||b.participants.get(p.id)!==r||world.maps.get(sceneKey(b.map,b.instanceId))!==b.scene||siegeRenewChestDistance(world,p,b.map)>SIEGE_RENEW_CHEST_RADIUS)fail('The castle chest is no longer available.',409);
    };
    check();
    return {chest:await claimSiegeRenewChest(world,p,{map:b.map,check,text:R.text})};
  }
  if(op==='warpstone'){
    near(castle.warpStone.npc,1,R.warpStoneQuest[b.map]);if(!castle.warpStone.to||castle.warpStone.to.map!==b.map)native(R.text.noInfo,503);
    const {durableQuestCommand}=await import('./quest-transactions.mjs');
    await durableQuestCommand(world,p,{type:'quest',operation:'instant',questId:R.warpStoneQuest[b.map],npc:castle.warpStone.npc});return {moved:'warpstone'};
  }
  if(op==='stronghold'){
    near(castle.lorenzo,R.defenderTeleportJob,b.map);if(r.side!=='defender'||castleView(state,b.map).owner?.guild!==r.guild)native([700,86],403);
    const at=castle.strongholds.find(l=>l.index===Number(input.location));if(!at)native([700,48]);   // "Cannot move to selected location."
    placeAt(world,b,p,at);return {moved:at.index};
  }
  if(op==='castellan'){
    near(castle.lorenzo,R.masterTeleportJob,b.map);const owner=castleView(state,b.map).owner;
    if(!owner||owner.guild!==r.guild||state.guilds?.[owner.guild]?.master!==ref)native([700,85],403);   // "You are not the guild master of defending guild."
    if(!castle.castellan)native(R.text.noInfo,503);placeAt(world,b,p,castle.castellan);return {moved:'castellan'};
  }
  if(op==='jegarr'){near(castle.jegarr.npc,1,R.jegarrQuest[b.map]);if(!castle.jegarr.to||castle.jegarr.to.map!==b.map)native(R.text.noInfo,503);const {durableQuestCommand}=await import('./quest-transactions.mjs');await durableQuestCommand(world,p,{type:'quest',operation:'instant',questId:R.jegarrQuest[b.map],npc:castle.jegarr.npc});return {moved:'hall'};}
  fail('Unknown siege operation.');
}

/** These original instant quests are same-castle services, never public-map
 * admission. The normal quest engine still checks level, journal and rewards. */
export function prepareSiegeRenewQuestWarp(world,p,input){
  if(input?.type!=='quest'||!['instant','claim'].includes(input.operation)||![...Object.values(R.warpStoneQuest),...Object.values(R.jegarrQuest)].includes(input.questId))return null;
  const b=sceneOf(world,p),data=world.socialState&&siegeRenewControllerData(world),castle=b&&data?.castles.get(b.map),record=b&&participant(world,b,p),token=p.token;
  const stone=castle&&input.questId===R.warpStoneQuest[b.map],hall=castle&&input.questId===R.jegarrQuest[b.map],service=stone?castle.warpStone:hall?castle.jegarr:null;
  if(!service||!record||Number(input.npc)!==service.npc||!nearbyNpc(world,p,{npcIndex:service.npc,jobType:1,jobIndex:input.questId,radius:8}))fail('Stand near your original castle service.',403);
  // A battle scene must still be fighting; the owner's peace scene must still be the castle's live peace scene.
  const live=()=>b.kind==='peace'?world.siegeRenewLive?.peace?.get(b.map)===b&&!world.siegeRenewLive?.battles.has(b.map):world.siegeRenewLive?.battles.get(b.map)===b&&b.phase==='battle'&&!b.capturing&&world.now()<b.endAt;
  const check=()=>{if(!present(world,p)||p.token!==token||p.dead||!inCastle(b,p)||participant(world,b,p)!==record||!live()||world.maps.get(sceneKey(b.map,b.instanceId))!==b.scene)fail('The castle quest route is no longer available.',409);};
  check();if(!service.to||service.to.map!==b.map)native(R.text.noInfo,503);
  const point=b.scene.nearest(service.to.x,service.to.z);if(!point)native(R.text.noInfo,503);
  return {check,scene:{map:b.map,instanceId:b.instanceId,channel:0,x:point.x,z:point.z,yaw:-(Number(service.to.dirDeg)||0)*Math.PI/180}};
}

// ------------------------------------------------------------------ revive point and snapshot
/** A participant's revive point (defending / attacking position) while its castle battle runs; null otherwise. */
export function siegeRenewReviveAt(world,p){
  const b=battleOf(world,p),data=siegeRenewControllerData(world);if(!b||b.phase!=='battle'||!data)return null;
  const r=b.participants.get(p.id),castle=data.castles.get(b.map);if(!r)return null;
  const at=r.side==='defender'?castle.defend:castle.attack;return {map:b.map,instanceId:b.instanceId,x:at.x,z:at.z,dirDeg:at.dirDeg};
}
/** Same-castle revival. Core retains its ordinary10-second readiness gate.
 * The side checkpoint comes from original location types1/2; using it for
 * revival is the declared engine choice in the rules file. */
export async function reviveSiegeRenew(world,p,authorize=()=>{}){
  const initial=battleOf(world,p);if(!initial||initial.phase!=='battle')return false;
  return world.serializeAccount(p.account,async()=>{
    const b=battleOf(world,p),record=b?.participants.get(p.id),data=siegeRenewControllerData(world),castle=b&&data?.castles.get(b.map),token=p.token;
    const check=()=>{
      authorize();
      if(!b||!castle||!record||world.siegeRenewLive?.battles.get(b.map)!==b||world.maps.get(sceneKey(b.map,b.instanceId))!==b.scene||b.phase!=='battle'||b.capturing||world.now()>=b.endAt||!p.dead||p.token!==token||!inCastle(b,p)||participant(world,b,p)!==record||p.profile.instance?.id!==b.instanceId)fail('The castle revival scope is no longer available.',409);
    };
    check();
    const checkpoint=record.side==='defender'?castle.defend:castle.attack,at=b.scene.nearest(checkpoint.x,checkpoint.z);
    if(!at)native(R.text.noInfo,503);
    const before={profile:structuredClone(p.profile),revision:p.revision},transition=p.sceneTransition;
    const candidate={...p,profile:structuredClone(p.profile),stats:{...p.stats},x:at.x,z:at.z,path:[],attackTarget:null,dead:false,hp:p.maxHp,mp:p.stats.maxMp||0,maxShield:Math.max(0,Number(p.stats.maxShield)||0),shield:Math.max(0,Number(p.stats.maxShield)||0)};
    world.changed(candidate);p.sceneTransition=true;
    try{
      check();await world.persist(candidate);
      // Reconnect is queued behind this same account fence. A timer reaching
      // the end after the accepted write must drain this committed actor; it
      // cannot turn it back into a corpse with a live/saved disagreement.
      const intervening=p.revision-before.revision,merged=mergeRewardProgress(world,p,before.profile,candidate,{dil:candidate.profile.dil});
      publishProfileChanges(p.profile,before.profile,candidate.profile);
      if(merged.levelChanged){p.stats=candidate.stats;p.maxHp=candidate.maxHp;}
      for(const key of ['x','z','path','attackTarget','dead'])p[key]=candidate[key];
      p.revision=candidate.revision+intervening;p.dirty=!!candidate.dirty||intervening!==0;p.saveError=candidate.saveError||null;
      refreshConcurrentBuffStats(world,p,before.profile);
      p.hp=p.maxHp;p.mp=p.stats.maxMp||0;p.maxShield=Math.max(0,Number(p.stats.maxShield)||0);p.shield=p.maxShield;delete p.respawnReadyAt;
      world.snapshotPublicRows?.delete(p);for(const[m,event]of merged.notices)world.emit(m,event);
      world.emit(p.map,{type:'revive',actorId:p.id,instanceId:b.instanceId});
      await persistInterveningProgress(world,[p]);
    }finally{p.sceneTransition=transition;}
    return true;
  });
}
export function siegeRenewSnapshot(world,p){
  const data=world.socialState&&siegeRenewControllerData(world);if(!data)return null;
  const L=siegeRenewLive(world),state=world.socialState,now=world.now(),b=sceneOf(world,p);
  const owners=Object.fromEntries([...data.castles.keys()].map(m=>{const o=castleView(state,m).owner;return [m,o?{guild:o.guild,name:o.name,since:o.since}:null];}));
  const out={startAt:L.startAt??renewNextStart(now,data.cfg,data.zoneOffsetMin),durationMs:data.cfg.durationMs,zoneOffsetMin:data.zoneOffsetMin,running:[...L.battles.values()].some(x=>x.phase==='battle'),owners,
    capabilities:{guardianCapture:true,gateUpgrade:[...data.castles.values()].every(c=>siegeRenewGateDataReady(world,c)),sentryDeployment:siegeRenewProposedEnabled(world)&&data.cfg.sentryIndexes.every(id=>siegeRenewGuardDataReady(world,id)),defenderSkills:!!siegeRenewDefenderSkillData(world),tax:true,weeklyChest:!!siegeRenewChestData(world),observer:true,peaceEntry:true}};
  if(b){const r=b.participants.get(p.id),peace=b.kind==='peace';out.castle={map:b.map,instanceId:b.instanceId,phase:peace?'peace':b.phase,endAt:peace?null:b.endAt,prepUntil:b.prepUntil||0,side:r?.side||null,participants:b.participants.size,capacity:data.cfg.capacity,
    crystal:b.crystal?{id:b.crystal.id,uid:b.crystal.uid,brickIndex:b.crystal.brickIndex,x:b.crystal.x,z:b.crystal.z,dir:b.crystal.dir,hp:b.crystal.hp,maxHp:b.crystal.maxHp,breakable:canDamage(world,b,p)}:null,foes:peace?[]:[...world.players.values()].filter(q=>siegeRenewEnemy(world,p,q)).map(q=>q.id),
    chest:siegeRenewChestView(world,b.map,{inBattle:!peace}),tax:peace?siegeRenewTaxView(world,p,b.map,data.cfg):null};
    out.castle.gates=[...(b.gates?.values()||[])].map(m=>({id:m.id,uid:m.uid,brickIndex:m.brickIndex,x:m.x,z:m.z,dir:m.dir,hp:m.hp,maxHp:m.maxHp,dead:!!m.dead,closed:!!m.gateClosed,breakable:!m.dead&&canDamage(world,b,p),group:m.group,level:m.gateLevel}));
    out.castle.gateUpgrade=siegeRenewGateView(world,p,b,data.castles.get(b.map));
    const s=castleView(state,b.map);if(s.guards?.length)out.castle.guards=s.guards.map(g=>({id:g.id,sentry:g.sentry,x:g.x,z:g.z}));
    if(s.skills)out.castle.skillReadyAt=Object.fromEntries(Object.entries(s.skills).map(([k,v])=>[k,v.readyAt]));}
  return out;
}
// Trusted observer service reuses the durable castle exit and same-scene move.
export {exitCastle as exitSiegeRenewScene,placeAt as placeSiegeRenewActor};
