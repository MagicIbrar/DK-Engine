// SIEGE: the classic Zenoa Castle siege war (map 23, Territory 7), host side. Rules + data: src/game/siege-rules.js; values the
// data does not define: src/config/engine-chosen-siege.js (ENGINE-CHOSEN (not in Global data)).
//   Durable (state.siege, committed with the guild social transaction or a host system transaction):
//     owner {guild, name, since} | null, announced {startAt, hour, at} | null, seals [{guild, name, at, fee}],
//     fortify {gateBrick: addedHp}, tax {days {utcDay: dil}, collected {utcDay: true}}, history [{startAt, endAt, owner, result}]
//   Live (world.siegeLive): the running battle (objects in the map-23 scene, pendants, empathy, downs), queued tax.
//   Guild operations (server/world/guilds.mjs): siegeRegister (Bastian SIEGE_ENTRY 22), siegeAnnounce {hour} (Lorenzo
//     SIEGE_STARTTIME 24), siegeFortify {gate, amount} (Lorenzo SIEGE_UPGRADEGATE1..3 27..29), siegeTax {day} (owner master),
//     live: siegeEnter {npcIndex} (SIEGE_TELEPORT 21), siegeEmpathy (Juto REIGN_SYSOP 25), siegeLeave.
//   PvP: registerPvpMode (server/world/pvp.mjs) - participants of different guilds hit each other on map 23 during the battle with
//     the src/game/pvp-rules.js damage; a down respawns after REVIVALTICK.
// tickSiege runs from the core tick (server/world/core.mjs) and from guild snapshots / commands, throttled by ENGINE-CHOSEN TICK_MS.
import {randomUUID} from 'node:crypto';
import {requireGuildSiegeMember} from './guild-siege-roster.mjs';
import {registerPvpMode} from './pvp.mjs';
import {sameScene} from './scene.mjs';
import {socialError as fail,socialRef,socialState,initializeSocial} from './social-state.mjs';
import {nearbyNpc,npcPlacements,offersOriginalJob} from './npc-services.mjs';
import {assertSiegeRenewAdmissionAvailable} from './siege-renew.mjs';
import {commitFieldTravel,boundReturnTarget} from './travel.mjs';
import {initializePets} from './pets.mjs';
import {allianceOfGuild} from './alliance.mjs';
import {footprintCells} from '../../src/systems/events/bricks.js';
import {SIEGE_CHOSEN as C} from '../../src/config/engine-chosen-siege.js';
import {S,SIEGE_MAP,GATES,STONES,GATE_JOBS,JOBS,STONE_LOCATION,siegeConfig,siegeLocations,siegeObjects,gateHp,fortifyQuote,brickDamage,taxOf,nextStart,
  phaseAt,COUNTDOWN,registrationError,empathyError} from '../../src/game/siege-rules.js';

export const SIEGE_FIELDS=['hour','gate','day','npcIndex'];
export const SIEGE_OPERATIONS={siegeRegister:[],siegeAnnounce:['hour'],siegeFortify:['gate','amount'],siegeTax:['day']};
export const SIEGE_LIVE_OPERATIONS={siegeEnter:['npcIndex'],siegeEmpathy:[],siegeLeave:[]};
export const isSiegeOperation=op=>Object.hasOwn(SIEGE_OPERATIONS,op);
export const isSiegeLiveOperation=op=>Object.hasOwn(SIEGE_LIVE_OPERATIONS,op);
/** Error messages are the original string codes; the client shows the original text for them. */
export const siegeError=key=>`siege:${S[key]?S[key].join(':'):key}`;
const refuse=(key,status=400)=>fail(siegeError(key),status);
const CHANNEL=C.CHANNEL,DAY=86400000;

// ------------------------------------------------------------------ data + state
export function siegeData(world){
  const ev=world.data.eventData?.ev||world.data.eventData;const mode=ev?.modes?.siege;if(!mode)return null;
  const cfg=siegeConfig(mode,ev.modes.siegeRenew);
  // Current native activation is authoritative, including before cached data.
  const map=ev.maps?.[cfg.map]||ev.maps?.[String(cfg.map)],nativeMap=world.data.mapRow?.(cfg.map);
  if(Number(map?.flags?.isUseMap??nativeMap?.isUseMap)!==1 || (nativeMap?.isUseMap!=null&&Number(nativeMap.isUseMap)!==1))return null;
  if(world._siegeData)return world._siegeData;
  const locations=siegeLocations(mode),objects=siegeObjects(ev.maps?.[cfg.map]||ev.maps?.[String(cfg.map)],ev.bricks);
  const territory=Number(world.data.mapRow?.(cfg.map)?.TerritoryIndex);
  return world._siegeData={cfg,locations,objects,territory,mode};
}
const siegeOf=state=>state.siege||={owner:null,announced:null,seals:[],fortify:{},tax:{days:{},collected:{}},history:[]};
const viewOf=state=>state?.siege||{owner:null,announced:null,seals:[],fortify:{},tax:{days:{},collected:{}},history:[]};
export const liveOf=world=>world.siegeLive||={battle:null,forcedStart:null,taxPending:new Map(),lastTick:0,running:false,announced:new Set(),flushAt:0};
const guildOfRef=(state,ref)=>Object.values(state?.guilds||{}).find(g=>g.members.some(m=>m.ref===ref))||null;
const playerById=(world,id)=>[...world.players.values()].find(q=>q.id===id&&!q.leaving)||null;
const onCastle=(world,p,d)=>!!p&&!p.leaving&&p.map===d.cfg.map&&!p.instanceId&&(p.channel??0)===CHANNEL;
const utcDay=ms=>Math.floor(ms/DAY);
/** Start of the current battle cycle: a test start, the announced time, or the next weekly start. */
export function cycleStart(world,now=world.now()){
  const d=siegeData(world),live=liveOf(world),s=viewOf(world.socialState);
  if(live.forcedStart!=null)return live.forcedStart;
  if(s.announced?.startAt&&s.announced.startAt+d.cfg.warMs>now)return s.announced.startAt;
  return nextStart(now,d.cfg,null,C.ZONE_OFFSET_MIN);
}
/** 'defender' | 'attacker' | null for a guild id. */
export function sideOf(world,guildId,state=world.socialState){
  const s=viewOf(state);if(!guildId)return null;
  if(s.owner?.guild===guildId)return 'defender';
  return s.seals.some(r=>r.guild===guildId)?'attacker':null;
}
function allied(state,a,b){const x=allianceOfGuild(state,a);return !!x&&x.guilds.includes(b);}
function emitTo(world,players,event){for(const q of players)world.emit(q.map,{...event,recipients:[q.id]});}
function castlePlayers(world){const d=siegeData(world);return [...world.players.values()].filter(q=>onCastle(world,q,d));}
function notice(world,players,code,args=[]){emitTo(world,players,{type:'siegeNotice',code,args});}
function guildPlayers(world,guildIds){const ids=new Set(guildIds),state=world.socialState;return [...world.players.values()].filter(q=>!q.leaving&&ids.has(guildOfRef(state,socialRef(q))?.id));}

/** A host system write of the social document (no character update). mutate(state) -> result | false (nothing to write). */
export async function siegeSystemWrite(world,mutate){
  const task=(world.saveQueue||Promise.resolve()).catch(()=>{}).then(async()=>{
    const current=socialState(world),state=structuredClone(current),out=mutate(state);
    if(out===false)return false;
    state.revision++;
    if(await world.saveSocialTransaction({expectedRevision:current.revision,state,updates:[]})===false)fail('The siege transaction could not be saved.',503);
    world.socialState=state;return out;
  });
  world.saveQueue=task.catch(()=>{});
  try{return await task;}catch(error){if(error.status===409&&world.getSocialState)await initializeSocial(world);throw error;}
}

// ------------------------------------------------------------------ PvP mode
export function siegeEnemy(world,p,q){
  const live=world.siegeLive,b=live?.battle,d=b&&siegeData(world);
  if(!b||!d||b.phase!=='battle'||!q||q===p||p.dead||q.dead||!onCastle(world,p,d)||!onCastle(world,q,d)||!sameScene(p,q))return false;
  const state=world.socialState,a=guildOfRef(state,socialRef(p))?.id,c=guildOfRef(state,socialRef(q))?.id;
  if(!a||!c||a===c||!sideOf(world,a)||!sideOf(world,c)||allied(state,a,c))return false;
  return true;
}
function siegeOpponents(world,p){return [...world.players.values()].filter(q=>siegeEnemy(world,p,q));}
function markDown(world,q){
  const b=world.siegeLive?.battle,d=siegeData(world);if(!b||!onCastle(world,q,d)||b.downs.has(q.id))return;
  const state=world.socialState,g=guildOfRef(state,socialRef(q));if(!sideOf(world,g?.id))return;
  if(!q.dead){q.hp=0;q.dead=true;q.path=[];q.profile.deaths=(q.profile.deaths||0)+1;void world.persist(q).catch(()=>{});}
  b.downs.set(q.id,world.now()+d.cfg.revivalMs);world.changed(q);
  if(b.empathy?.playerId===q.id)failEmpathy(world,b,'died');
}
registerPvpMode({enemy:siegeEnemy,opponents:siegeOpponents,onDown:(world,attacker,target)=>markDown(world,target)});

// ------------------------------------------------------------------ battle objects
async function castleScene(world){const d=siegeData(world);return world.map(d.cfg.map,null,CHANNEL);}
function spawnObject(world,scene,b,obj,hp){
  const cells=footprintCells(obj.x,obj.z,obj.dir,obj.def.widthSize||1,obj.def.heightSize||1).filter(([x,z])=>x>=0&&z>=0&&x<scene.width&&z<scene.height).map(([x,z])=>({i:z*scene.width+x,x,z}));
  // the stone pedestals are baked into the map-23 collision (5 x 5 cells around a 2 x 2 brick): the unwalkable cells touching the
  // brick footprint belong to the object, so its hit points are the walkable cells around the whole pedestal (C.HIT_RING)
  const col=scene.collision,own=new Set(cells.map(c=>c.i));
  for(let ring=0;ring<C.HIT_RING&&col?.walkableCell;ring++)for(const c of [...cells])for(let dz=-1;dz<=1;dz++)for(let dx=-1;dx<=1;dx++){const x=c.x+dx,z=c.z+dz,i=z*scene.width+x;
    if(x<0||z<0||x>=scene.width||z>=scene.height||own.has(i)||col.walkableCell(x,z))continue;own.add(i);cells.push({i,x,z});}
  const id=`siege:${b.id}:${obj.uid}`,old=new Map(cells.map(c=>[c.i,scene.collision?.cells?.[c.i]]));
  const m={id,uid:obj.uid,siegeObject:true,isBrick:true,brickIndex:obj.brick,kind:obj.kind,map:scene.index,instanceId:null,channel:CHANNEL,x:obj.x,z:obj.z,dir:obj.dir,
    name:obj.name,hp,maxHp:hp,_hp:hp,dead:false,targetId:null,respawnAt:Infinity,respawnSec:Infinity,home:{x:obj.x,z:obj.z},brickDef:obj.def,
    def:{level:Number(obj.def.level)||1,exp:0,def:[0],money:[0,0,0],name:obj.name},objectFootprint:cells,_cells:old};
  m.onKilled=p=>onObjectKilled(world,m,p);
  scene.monsters.set(id,m);block(scene,m,true);return m;
}
function block(scene,m,on){if(!scene.collision?.cells)return;for(const c of m.objectFootprint)scene.collision.cells[c.i]=on?1:(m._cells.get(c.i)??scene.collision.cells[c.i]);}
/** May p damage siege objects now? (ENGINE-CHOSEN OBJECT_ATTACKERS) */
function canHitObjects(world,b,p){
  if(!p||b.phase!=='battle'||world.now()<b.prepUntil)return false;
  return sideOf(world,guildOfRef(world.socialState,socialRef(p))?.id)==='attacker';
}
const oneHit=p=>!!(p?.gmAuthorized&&p.profile.gm?.onehit);
/** Apply the brick resists to the damage dealt since the last look; undo hits of non-attackers. Returns the new HP.
 * The dealt amount is the larger of the HP lost and the uncapped amounts of the host's damage events (watchObjectDamage):
 * a lethal hit lowers hp only to 0, so its full amount comes from the event. */
function settleObjectHp(world,b,m,by){
  const lost=m._hp-m.hp,raw=m._raw||0;m._raw=0;
  if(lost<=0&&raw<=0){m._hp=m.hp;return m.hp;}
  if(!canHitObjects(world,b,by)){m.hp=m._hp;return m.hp;}
  const taken=oneHit(by)?m._hp:brickDamage(m.brickDef,Math.max(lost,raw),by.stats?.attackType||'melee');
  m.hp=Math.max(0,m._hp-taken);m._hp=m.hp;return m.hp;
}
/** Remember the uncapped amount of each host damage event on a siege object (no core hook needed). */
function watchObjectDamage(world){
  if(world._siegeEmitWatch)return;world._siegeEmitWatch=true;
  const emit=world.emit.bind(world);
  world.emit=(map,event)=>{
    if(event?.type==='damage'&&!event.miss&&typeof event.targetId==='string'&&event.targetId.startsWith('siege:')){const m=world.siegeLive?.battle?.objectsById?.get(event.targetId);if(m)m._raw=(m._raw||0)+(Number(event.amount)||0);}
    return emit(map,event);
  };
}
function onObjectKilled(world,m,p){
  const b=world.siegeLive?.battle;if(!b||!b.objects.has(m.uid)){return;}
  m.hp=0;const hp=settleObjectHp(world,b,m,p);
  if(hp>0){m.dead=false;m.hp=hp;m._hp=hp;m.respawnAt=Infinity;return;}
  m.hp=0;m._hp=0;m.dead=true;m.respawnAt=Infinity;
  const d=siegeData(world),state=world.socialState,g=guildOfRef(state,socialRef(p));
  if(m.kind==='gate'){releaseObject(world,m);b.log.push({at:world.now(),kind:'gate',brick:m.brickIndex,guild:g?.id});return;}
  const obj=d.objects.find(o=>o.uid===m.uid);
  m.reviveAt=world.now()+(obj?.lifeTimeMs||d.cfg.stoneNonPkMs);releaseObject(world,m);
  b.pendants[m.brickIndex]=g?.id||null;b.log.push({at:world.now(),kind:'stone',brick:m.brickIndex,guild:g?.id});
  const all=castlePlayers(world);
  notice(world,all,S.guardianDestroyed,[g?.name||'',p.profile.name]);notice(world,all,S.stoneDestroyed,[m.name]);
}
function releaseObject(world,m){const scene=sceneOf(world,m);if(scene)block(scene,m,false);}
function sceneOf(world,m){for(const s of world.maps.values())if(s.monsters?.get(m.id)===m)return s;return null;}

// ------------------------------------------------------------------ battle lifecycle
export async function beginBattle(world,startAt){
  const d=siegeData(world),live=liveOf(world);if(live.battle&&!live.battle.closed)return live.battle;
  const scene=await castleScene(world),s=viewOf(world.socialState);
  const b={id:randomUUID().slice(0,8),startAt,endAt:startAt+d.cfg.warMs,phase:'battle',prepUntil:0,objects:new Map(),objectsById:new Map(),pendants:{},empathy:null,downs:new Map(),log:[],endMoveAt:null,closed:false,scene};
  watchObjectDamage(world);
  for(const obj of d.objects){const hp=obj.kind==='gate'?gateHp(obj,s.fortify?.[obj.brick]||0):obj.defaultHp,m=spawnObject(world,scene,b,obj,hp);b.objects.set(obj.uid,m);b.objectsById.set(m.id,m);}
  live.battle=b;
  const all=[...world.players.values()].filter(q=>!q.leaving);
  notice(world,all,S.startNow);notice(world,castlePlayers(world),S.started);
  return b;
}
function removeObjects(world,b){for(const m of b.objects.values()){releaseObject(world,m);sceneOf(world,m)?.monsters.delete(m.id);}b.objects.clear();b.objectsById?.clear();}
function failEmpathy(world,b,reason){
  const e=b.empathy;if(!e)return;b.empathy=null;
  const all=castlePlayers(world),code={died:S.died,far:S.tooFar,left:S.leftMap}[reason]||S.failed;
  notice(world,all,code,[e.name]);notice(world,all,S.empathyFailed,[e.guildName]);
}
async function capture(world,b,e){
  const d=siegeData(world),now=world.now();b.empathy=null;
  await siegeSystemWrite(world,state=>{
    const s=siegeOf(state),old=s.owner;const g=state.guilds[e.guild];if(!g)return false;
    s.owner={guild:g.id,name:g.name,since:now};s.fortify={};
    s.seals=s.seals.filter(r=>r.guild!==g.id);if(old&&state.guilds[old.guild]&&!s.seals.some(r=>r.guild===old.guild))s.seals.push({guild:old.guild,name:old.name,at:now,fee:0,former:true});
    s.history=[{at:now,kind:'capture',guild:g.id,name:g.name},...(s.history||[])].slice(0,20);return true;
  });
  b.pendants={};b.prepUntil=now+120000;   // 100:12: the new defending guild receives 2 minutes of preparation
  for(const m of b.objects.values()){const obj=d.objects.find(o=>o.uid===m.uid);const hp=obj.kind==='gate'?gateHp(obj,0):obj.defaultHp;
    m.dead=false;m.hp=hp;m.maxHp=hp;m._hp=hp;m.reviveAt=null;const scene=sceneOf(world,m);if(scene)block(scene,m,true);}
  const all=castlePlayers(world);
  notice(world,[...world.players.values()].filter(q=>!q.leaving),S.won,[e.guildName,'1']);notice(world,all,S.victorious,[e.guildName,'Zenoa Castle']);
  for(const q of all){const side=sideOf(world,guildOfRef(world.socialState,socialRef(q))?.id);placeAt(world,q,side==='defender'?1:2);}
}
function placeAt(world,q,index){
  const d=siegeData(world),at=d.locations[index],scene=[...world.maps.values()].find(s=>s.index===d.cfg.map&&!s.instanceId&&(s.channel??0)===CHANNEL);
  const point=scene?.nearest?.(at.x,at.z)||at;q.x=point.x;q.z=point.z;q.path=[];q.yaw=-(at.dirDeg||0)*Math.PI/180;world.changed(q);
  world.emit(q.map,{type:'siegeMove',actorId:q.id,x:q.x,z:q.z,location:index,recipients:[q.id]});
}
function respawn(world,b,q){
  const rules=world.data.pvpRules||{reviveHpRatio:100,reviveMpRatio:100},side=sideOf(world,guildOfRef(world.socialState,socialRef(q))?.id);
  q.dead=false;q.hp=Math.max(1,Math.round(q.maxHp*(rules.reviveHpRatio??100)/100));q.mp=Math.round((q.stats?.maxMp||0)*(rules.reviveMpRatio??100)/100);delete q.pvpLastHit;
  placeAt(world,q,side==='defender'?1:2);world.emit(q.map,{type:'revive',actorId:q.id});void world.persist(q).catch(()=>{});
}
async function endBattle(world,b){
  const now=world.now(),d=siegeData(world);b.phase='end';b.empathy=null;removeObjects(world,b);
  const owner=viewOf(world.socialState).owner,all=castlePlayers(world);
  notice(world,[...world.players.values()].filter(q=>!q.leaving),S.ended);
  for(const q of all){const gid=guildOfRef(world.socialState,socialRef(q))?.id,side=sideOf(world,gid);if(side==='defender')notice(world,[q],S.youWon);else if(side==='attacker')notice(world,[q],S.youLost);}
  b.endMoveAt=now+d.cfg.endActionMs;
  await siegeSystemWrite(world,state=>{const s=siegeOf(state);s.history=[{at:now,kind:'end',startAt:b.startAt,owner:owner?.guild||null,name:owner?.name||null,seals:s.seals.map(r=>r.name)},...(s.history||[])].slice(0,20);s.seals=[];s.announced=null;return true;}).catch(()=>{});
  if(liveOf(world).forcedStart===b.startAt)liveOf(world).forcedStart=null;
}
async function finishEnd(world,b){
  const d=siegeData(world),live=liveOf(world),owner=viewOf(world.socialState).owner;b.closed=true;live.battle=null;
  for(const q of castlePlayers(world)){
    if(q.dead){q.dead=false;q.hp=Math.max(1,q.maxHp);world.emit(q.map,{type:'revive',actorId:q.id});}
    const gid=guildOfRef(world.socialState,socialRef(q))?.id;
    if(owner&&gid===owner.guild){placeAt(world,q,d.cfg.endLocation);continue;}
    try{await commitFieldTravel(world,q,boundReturnTarget(world,q.profile));}catch{placeAt(world,q,2);}
  }
}

// ------------------------------------------------------------------ tick
/** Advance the siege. Called from the core tick and from guild snapshots / commands. */
export function tickSiege(world,{force=false}={}){
  const d=world.socialState&&siegeData(world);if(!d)return null;
  const live=liveOf(world),now=world.now();
  if(live.running||(!force&&now-live.lastTick<C.TICK_MS))return live.running||null;
  live.lastTick=now;live.running=runTick(world,d,live,now).catch(error=>{live.error=error.message;}).finally(()=>{live.running=false;});
  return live.running;
}
async function runTick(world,d,live,now){
  const startAt=cycleStart(world,now),phase=phaseAt(now,startAt,d.cfg);
  for(const [min,code] of COUNTDOWN){const at=startAt-min*60000,key=`${startAt}:${min}`;if(now>=at&&now<at+60000&&!live.announced.has(key)){live.announced.add(key);notice(world,[...world.players.values()].filter(q=>!q.leaving),code);}}
  let b=live.battle;
  if(!b&&phase==='battle')b=await beginBattle(world,startAt);
  if(b&&b.phase==='battle'){
    // objects: resists / attacker-only damage, stone revival
    for(const m of b.objects.values()){
      if(!m.dead){settleObjectHp(world,b,m,playerById(world,m.targetId));continue;}
      if(m.kind==='stone'&&m.reviveAt&&now>=m.reviveAt){m.dead=false;m.hp=m.maxHp;m._hp=m.hp;m.reviveAt=null;const scene=sceneOf(world,m);if(scene)block(scene,m,true);world.emit(m.map,{type:'respawn',actorId:m.id});}
    }
    // downs: skill kills / other deaths of participants on the castle map, then respawn
    for(const q of castlePlayers(world))if((q.dead||q.hp<=0)&&!b.downs.has(q.id))markDown(world,q);
    for(const [id,at] of [...b.downs]){const q=playerById(world,id);if(!q||!onCastle(world,q,d)||!q.dead){b.downs.delete(id);continue;}if(now>=at){b.downs.delete(id);respawn(world,b,q);}}
    // empathy
    const e=b.empathy;
    if(e){const q=playerById(world,e.playerId),juto=d.juto||(d.juto=nearJuto(world));
      if(!q||!onCastle(world,q,d))failEmpathy(world,b,'left');
      else if(q.dead)failEmpathy(world,b,'died');
      else if(juto&&Math.hypot(q.x-juto.x,q.z-juto.z)>d.cfg.reignDistance)failEmpathy(world,b,'far');
      else if(now>=e.endAt)await capture(world,b,e);
      else{const left=Math.ceil((e.endAt-now)/1000);for(const s of C.EMPATHY_ALARMS)if(left<=s&&!e.alarms.has(s)){e.alarms.add(s);notice(world,castlePlayers(world),S.empathyLeft,[s,e.guildName]);break;}}}
    if(now>=b.endAt)await endBattle(world,b);
  }else if(b&&b.phase==='end'&&now>=b.endMoveAt)await finishEnd(world,b);
  await flushTax(world,live,now);
}
function nearJuto(world){const d=siegeData(world);const row=npcPlacements(world,d.cfg.map).find(r=>r.npcIndex===2203);return row?{x:row.x,z:row.z}:null;}   // Juto (REIGN_SYSOP) in the castle placements

/** Test start: begin a battle now (WARTIME from now). */
export async function startSiegeNow(world,now=world.now()){const live=liveOf(world);live.forcedStart=now;live.lastTick=0;await tickSiege(world,{force:true});return live.battle;}
/** Test end: close the running battle now. */
export async function endSiegeNow(world){const b=liveOf(world).battle;if(b&&b.phase==='battle'){b.endAt=world.now();liveOf(world).lastTick=0;await tickSiege(world,{force:true});}return b;}

// ------------------------------------------------------------------ tax
/** A committed NPC shop trade (shops.mjs): the castle territory's tax.csv ratio of the DIL price joins the owner's ledger. */
export function recordSiegeTax(world,p,kind,amount){
  const d=world.socialState&&siegeData(world);if(!d||!viewOf(world.socialState).owner||p.instanceId)return 0;
  if(Number(world.data.mapRow?.(p.map)?.TerritoryIndex)!==d.territory)return 0;
  const tax=taxOf(amount,kind==='sell'?d.cfg.tax.sell:d.cfg.tax.buy);if(!tax)return 0;
  const live=liveOf(world),day=utcDay(world.now());live.taxPending.set(day,(live.taxPending.get(day)||0)+tax);return tax;
}
async function flushTax(world,live,now){
  if(!live.taxPending.size||now<live.flushAt)return;live.flushAt=now+C.TAX_FLUSH_MS;
  const batch=new Map(live.taxPending);live.taxPending.clear();
  try{await siegeSystemWrite(world,state=>{const s=siegeOf(state);if(!s.owner)return false;for(const [day,n] of batch)s.tax.days[day]=(s.tax.days[day]||0)+n;pruneTax(s,now);return true;});}
  catch{for(const [day,n] of batch)live.taxPending.set(day,(live.taxPending.get(day)||0)+n);}
}
function pruneTax(s,now){const min=utcDay(now)-C.TAX_DAYS+1;for(const k of Object.keys(s.tax.days))if(Number(k)<min)delete s.tax.days[k];for(const k of Object.keys(s.tax.collected))if(Number(k)<min)delete s.tax.collected[k];}

// ------------------------------------------------------------------ durable guild operations (inside socialTransaction)
/** One siege guild operation. ctx {state, profile, ref, g, input, level(row)}. Returns post-commit notices [{code,args,refs}]. */
export function siegeCommand(world,p,{state,profile,ref,g,input,level}){
  const d=siegeData(world);if(!d)fail('The original siege data is unavailable.',503);
  const s=siegeOf(state),now=world.now(),op=input.operation,live=liveOf(world),battle=live.battle&&live.battle.phase==='battle';
  const npc=(id,job,table)=>nearbyNpc(world,p,{npcIndex:id,jobType:job,...(table!=null?{jobIndex:table}:{}),radius:8});
  if(op==='siegeRegister'){
    if(!npc(753,JOBS.ENTRY))fail('Use the original siege registration NPC (Bastian).',403);
    const err=registrationError(d.cfg,{guild:g?.id,isMaster:!!g&&g.master===ref,phase:battle?'battle':'idle',owner:s.owner?.guild,registrations:s.seals.map(r=>r.guild),
      level:g?level(g):0,members:g?.members.length||0,hasMark:!!g?.mark,dil:profile.dil},C.MAX_SEALS);
    if(err)refuse(err,err==='noDil'?400:409);
    profile.dil-=d.cfg.fee;s.seals.push({guild:g.id,name:g.name,at:now,fee:d.cfg.fee});
    return [{code:S.feePaid,args:[d.cfg.fee],refs:[ref]},{code:S.registered,refs:[ref]},{code:S.confirmed,guilds:[g.id]}];
  }
  const ownerMaster=()=>{if(!g)refuse('notMember');if(s.owner?.guild!==g.id)refuse('notDefender',403);if(g.master!==ref)refuse('notMaster',403);};
  if(op==='siegeAnnounce'){
    if(!npc(2202,JOBS.STARTTIME))fail('Use Lorenzo in Zenoa Castle.',403);
    ownerMaster();if(battle)refuse('alreadyStarted',409);
    if(!Number.isInteger(input.hour)||!C.ANNOUNCE_HOURS.includes(input.hour))refuse('badTime');
    const next=nextStart(now,d.cfg,input.hour,C.ZONE_OFFSET_MIN);
    if(s.announced&&s.announced.startAt>now)refuse('alreadyAnnounced',409);
    if(next<=now)refuse('notAnnounceTime',409);
    s.announced={startAt:next,hour:input.hour,at:now};
    return [{code:S.timeChanged,refs:[ref]},{code:S.timeAnnounced,args:['Zenoa Castle'],all:true}];
  }
  if(op==='siegeFortify'){
    const gate=Number(input.gate),job=Number(Object.keys(GATE_JOBS).find(k=>GATE_JOBS[k]===gate));
    if(!GATES.includes(gate))fail('Choose an original castle gate.');
    if(!npc(2202,job))fail('Use Lorenzo in Zenoa Castle.',403);
    ownerMaster();if(battle)refuse('inBattle',409);
    const obj=d.objects.find(o=>o.brick===gate),q=fortifyQuote(d.cfg,obj,s.fortify[gate]||0,input.amount);
    if(q.error)fail(q.error==='max'?`siege:gateMax:${q.maxDil}`:`siege:gateAmount:${d.cfg.upgradeCost}`);
    if(!(profile.dil>=q.cost))refuse('insufficientDil');
    profile.dil-=q.cost;s.fortify[gate]=(s.fortify[gate]||0)+q.add;
    return [{text:`${obj.name}: +${q.add} (${q.hp} / ${obj.maxHp})`,refs:[ref]}];
  }
  if(op==='siegeTax'){
    if(!C.TAX_NPCS.some(id=>npc(id)))fail('Use Lorenzo or Bastian.',403);
    ownerMaster();if(battle)refuse('taxInBattle',409);
    pruneTax(s,now);const today=utcDay(now),days=input.day===-1?[...Array(C.TAX_DAYS).keys()]:[input.day];
    if(!days.every(i=>Number.isInteger(i)&&i>=0&&i<C.TAX_DAYS))fail('Choose an original tax day.');
    let total=0;const keys=[];
    for(const i of days){const k=today-(C.TAX_DAYS-1)+i;if(s.tax.collected[k]){if(input.day!==-1)refuse('taxAlready',409);continue;}const n=s.tax.days[k]||0;if(n>0){total+=n;keys.push(k);}}
    if(!total)refuse('taxNone');
    if(profile.dil+total>10_000_000_000)refuse('taxMax');
    profile.dil+=total;for(const k of keys)s.tax.collected[k]=true;
    return [{code:S.taxReceived,refs:[ref]}];
  }
  fail('Unknown siege operation.');
}
/** Post-commit notices: {type:'siegeNotice', code, args} (or a plain text line). */
export function emitSiegeNotices(world,notices){
  const state=world.socialState;if(!state||!notices)return;
  for(const n of notices){
    const targets=n.all?[...world.players.values()].filter(q=>!q.leaving):[...world.players.values()].filter(q=>!q.leaving&&((n.refs||[]).includes(socialRef(q))||(n.guilds||[]).includes(guildOfRef(state,socialRef(q))?.id)));
    emitTo(world,targets,{type:'siegeNotice',code:n.code||null,args:n.args||[],...(n.text?{text:n.text}:{})});
  }
}

// ------------------------------------------------------------------ live operations (outside the social transaction)
async function enterCastle(world,p,index){
  const d=siegeData(world),at=d.locations[index],keys=['map','channel','x','z','yaw','path','instanceId','mount','pet','smartWarp','stats','maxHp','hp','mp'];
  const before=Object.fromEntries(keys.map(k=>[k,p[k]]));p.sceneTransition=true;
  try{
    const scene=await world.map(d.cfg.map,null,CHANNEL),point=scene.nearest(at.x,at.z);if(!point)refuse('cannotMove');
    const profile=structuredClone(p.profile);initializePets(profile);
    const stats=world.data.stats?.(profile,{...p,mount:null},world.now())||p.stats;
    const candidate={...p,profile,map:d.cfg.map,channel:CHANNEL,x:point.x,z:point.z,yaw:-(at.dirDeg||0)*Math.PI/180,path:[],mount:null,pet:null,smartWarp:null,stats,maxHp:stats?.maxHp??p.maxHp,hp:Math.min(p.hp,stats?.maxHp??p.maxHp),mp:Math.min(p.mp||0,stats?.maxMp??p.mp??0)};
    world.changed(candidate);await world.persist(candidate);
    for(const key of [...keys,'profile','dirty','revision','saveError'])p[key]=candidate[key];
  }catch(error){Object.assign(p,before);throw error;}finally{p.sceneTransition=false;}
  world.emit(before.map,{type:'leave',actorId:p.id,channel:before.channel??0});world.emit(p.map,{type:'join',actorId:p.id});
}
export async function siegeLiveCommand(world,p,input){
  const fields=SIEGE_LIVE_OPERATIONS[input.operation];
  if(!fields||Object.keys(input).some(k=>!['token','type','operation','revision','requestId',...fields].includes(k)))fail('Send siege intent only.');
  if(world.players.get(p.account)!==p||p.leaving||p.dead||p.sceneTransition||p.tradeId)fail('This service is unavailable while disconnected, dead, travelling or trading.',409);
  // Validate the authored entrance and its destination before the classic tick
  // can load map23 or write its social state. Renew indices193..195 belong to
  // different active castles even when this guild owns/registers for Zenoa.
  if(input.operation==='siegeEnter'){
    const id=Number(input.npcIndex),placement=Number.isInteger(id)&&nearbyNpc(world,p,{npcIndex:id,jobType:JOBS.TELEPORT,radius:8});
    if(!placement)fail('Stand near an original siege tunnel.',403);
    const jobs=placement.jobs.filter(([type,index])=>Number(type)===JOBS.TELEPORT&&offersOriginalJob(world,placement,JOBS.TELEPORT,index));
    const renew=jobs.find(([,map])=>[193,194,195].includes(Number(map)));
    if(renew){
      const {siegeRenewCommand}=await import('./siege-renew-controller.mjs');
      return siegeRenewCommand(world,p,{type:'siegerenew',operation:'enter',npcIndex:id});
    }
    for(const [,map]of jobs)assertSiegeRenewAdmissionAvailable(world,map);
    if(!jobs.some(([,map])=>Number(map)===0||Number(map)===SIEGE_MAP))fail('This siege entrance has no supported original destination.',503);
  }
  const d=siegeData(world);
  // Retained profiles may predate native deactivation. Leaving remains a safe
  // return operation without reviving the disabled battle or its economy.
  if(!d&&input.operation==='siegeLeave'&&p.map===SIEGE_MAP&&!p.instanceId){
    await commitFieldTravel(world,p,boundReturnTarget(world,p.profile));return {left:true};
  }
  if(!d)fail('The original siege data is unavailable.',503);
  await tickSiege(world,{force:true});
  const live=liveOf(world),b=live.battle,state=world.socialState,g=guildOfRef(state,socialRef(p)),side=sideOf(world,g?.id),now=world.now();
  if(input.operation==='siegeEnter'){
    const id=Number(input.npcIndex);
    if(!Number.isInteger(id)||!nearbyNpc(world,p,{npcIndex:id,jobType:JOBS.TELEPORT,radius:8}))fail('Stand near an original siege tunnel.',403);
    if(p.instanceId)refuse('cannotEnter',403);

    if(side==='defender'){requireGuildSiegeMember(world,g,socialRef(p));await enterCastle(world,p,1);return {entered:1};}
    if(side!=='attacker')refuse(b?'notAuthorized':'noTunnel',403);
    if(!b||b.phase!=='battle')refuse('waitStart',403);
    if(now<b.prepUntil)refuse('cannotEnter',403);
    requireGuildSiegeMember(world,g,socialRef(p));
    await enterCastle(world,p,2);return {entered:2};
  }
  if(input.operation==='siegeLeave'){
    if(!onCastle(world,p,d))refuse('notInSiege');
    await commitFieldTravel(world,p,boundReturnTarget(world,p.profile));return {left:true};
  }
  // siegeEmpathy at Juto
  if(!nearbyNpc(world,p,{npcIndex:2203,jobType:JOBS.REIGN,radius:d.cfg.reignDistance}))fail('Stand next to Juto.',403);
  const pendants=g&&b?Object.values(b.pendants).filter(x=>x===g.id).length:0;
  const err=empathyError({battle:!!b&&b.phase==='battle'&&onCastle(world,p,d)&&now>=b.prepUntil,guild:g?.id,attacker:side==='attacker',isMaster:!!g&&g.master===socialRef(p),other:b?.empathy&&b.empathy.guild!==g?.id?b.empathy:null,pendants});
  if(err)refuse(err,409);
  if(b.empathy?.guild===g.id)refuse('empathizing',409);
  b.empathy={guild:g.id,guildName:g.name,playerId:p.id,name:p.profile.name,startAt:now,endAt:now+d.cfg.reignMs,alarms:new Set()};
  notice(world,castlePlayers(world),S.empathyStart,[g.name]);
  return {empathy:b.empathy.endAt};
}

// ------------------------------------------------------------------ snapshot
/** The `siege` field of the guild snapshot extras. helpers {guildMark(mark)}. */
export function siegeSnapshot(world,p,helpers){
  const d=world.socialState&&siegeData(world);if(!d)return null;
  // the core tick runs the siege; a snapshot must not emit events while it is being built (they would carry a higher sequence than the
  // snapshot itself and the client would replay them), so a host without a tick hook only starts it after the snapshot is done
  void Promise.resolve().then(()=>tickSiege(world)).catch(()=>{});
  const state=world.socialState,s=viewOf(state),live=liveOf(world),b=live.battle,now=world.now(),ref=socialRef(p),g=guildOfRef(state,ref),side=sideOf(world,g?.id);
  const startAt=b?b.startAt:cycleStart(world,now),mark=id=>helpers?.guildMark?.(state.guilds[id]?.mark)||null;
  const out={map:d.cfg.map,owner:s.owner?{id:s.owner.guild,name:s.owner.name,since:s.owner.since,mark:mark(s.owner.guild),master:state.guilds[s.owner.guild]?.master===ref,masterName:(g0=>g0?.members.find(m=>m.ref===g0.master)?.name||null)(state.guilds[s.owner.guild])}:null,
    phase:b?(b.phase==='battle'&&now<b.prepUntil?'prep':b.phase):'idle',startAt,endAt:b?b.endAt:startAt+d.cfg.warMs,prepUntil:b?.prepUntil||0,announced:!!s.announced,
    seals:s.seals.map(r=>({id:r.guild,name:r.name,mark:mark(r.guild)})),side,guildId:g?.id||null,isMaster:!!g&&g.master===ref,
    gates:d.objects.filter(o=>o.kind==='gate').map(o=>{const m=b&&[...b.objects.values()].find(x=>x.brickIndex===o.brick);return {brick:o.brick,name:o.name,base:o.defaultHp,max:o.maxHp,fortified:s.fortify?.[o.brick]||0,hp:m?m.hp:gateHp(o,s.fortify?.[o.brick]||0),dead:!!m?.dead};}),
    cfg:{fee:d.cfg.fee,guildLevel:d.cfg.guildLevel,members:d.cfg.members,upgradeCost:d.cfg.upgradeCost,upgradeHp:d.cfg.upgradeHp,revivalMs:d.cfg.revivalMs,reignMs:d.cfg.reignMs,announceHours:C.ANNOUNCE_HOURS,maxSeals:C.MAX_SEALS},
    history:(s.history||[]).slice(0,5)};
  if(b&&onCastle(world,p,d)){
    out.objects=[...b.objects.values()].map(m=>({id:m.id,uid:m.uid,brick:m.brickIndex,kind:m.kind,x:m.x,z:m.z,dir:m.dir,hp:m.hp,maxHp:m.maxHp,dead:!!m.dead,owner:m.kind==='stone'?(b.pendants[m.brickIndex]??null):null,breakable:canHitObjects(world,b,p)}));
    out.pendants=STONES.map(brick=>({brick,location:STONE_LOCATION[brick],guild:b.pendants[brick]??null,name:state.guilds[b.pendants[brick]]?.name||null,mine:!!g&&b.pendants[brick]===g.id}));
    out.empathy=b.empathy?{guild:b.empathy.guild,guildName:b.empathy.guildName,name:b.empathy.name,startAt:b.empathy.startAt,endAt:b.empathy.endAt,mine:b.empathy.playerId===p.id}:null;
    out.respawn=b.downs.has(p.id)?{at:b.downs.get(p.id),location:side==='defender'?1:2}:null;
    out.foes=siegeOpponents(world,p).map(q=>q.id);
  }
  if(out.owner?.master){const days=[],today=utcDay(now);for(let i=0;i<C.TAX_DAYS;i++){const k=today-(C.TAX_DAYS-1)+i;days.push({day:i,utcDay:k,amount:(s.tax?.days?.[k]||0)+(live.taxPending.get(k)||0),collected:!!s.tax?.collected?.[k]});}out.tax={days};}
  return out;
}
