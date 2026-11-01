// Dead Island (map551) in-run host mechanics: ancient abilities, totem
// resonance/combinations, boss vitality and Triforce, the native attack curses,
// Recollapse self-destruction, Midas recovery crystals, interior gates and
// title14. Native rows and every ENGINE-CHOSEN rule: src/config/engine-chosen-dead-island.js.
import {randomUUID} from 'node:crypto';
import {
 DEAD_ISLAND_ABILITIES,DEAD_ISLAND_TIMING,DEAD_ISLAND_TOTEMS,DEAD_ISLAND_COMBOS,DEAD_ISLAND_TOTEM_TIMING,DEAD_ISLAND_IGNITER,
 DEAD_ISLAND_IGNITER_SET,DEAD_ISLAND_WAVE_MONSTERS,DEAD_ISLAND_BOSSES,DEAD_ISLAND_TRIFORCE,DEAD_ISLAND_ABSORB_UPGRADE,
 DEAD_ISLAND_ABSORB_WEAKEN,DEAD_ISLAND_RECOLLAPSE,DEAD_ISLAND_RECOVERY_GEM,DEAD_ISLAND_GATES,DEAD_ISLAND_ARENA_CENTRE,DEAD_ISLAND_TITLE,
} from '../../src/config/engine-chosen-dead-island.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {ensureSkills,actorFor,incomingSkillDamage} from './skills.mjs';
import {grantTitle,refreshTitleStats} from './titles.mjs';
import {stageInstanceMembers} from './instances.mjs';
import {partyLootOwner} from './party.mjs';
import {lootOwnershipMs} from './loot.mjs';
import {rollMonsterDrops} from '../../src/game/loot.js';
import {serializeLife} from './life-transactions.mjs';

const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
const plain=text=>String(text||'').replace(/^\[message\]\s*/,'').replace(/@<[^>]*>/g,'').replace(/<[^>]*>/g,'').trim();
export const deadIslandText=(world,code)=>plain(world.data.dungeonData?.dg?.maps?.[551]?.messages?.[code]?.t);
const refuse=(world,code)=>fail(deadIslandText(world,code)||`Dead Island refused (${code}).`);
const ABILITY_BY_MENU=new Map(DEAD_ISLAND_ABILITIES.map(a=>[a.menu,a])),ABILITY_BY_ITEM=new Map(DEAD_ISLAND_ABILITIES.map(a=>[a.item,a]));
const BOSS=new Map(DEAD_ISLAND_BOSSES.map(b=>[b.monster,b])),TOTEM=new Map(DEAD_ISLAND_TOTEMS.map(t=>[t.npc,t]));
const CURSES=new Set(DEAD_ISLAND_BOSSES.map(b=>b.curse));
export const DEAD_ISLAND_ABILITY_MENUS=Object.freeze([...ABILITY_BY_MENU.keys()]);
export const isAncientStone=index=>ABILITY_BY_ITEM.has(Number(index));
export const isDeadIslandTotem=npc=>TOTEM.has(Number(npc));

function members(world,i){return [...world.players.values()].filter(p=>!p.leaving&&p.instanceId===i.id&&p.map===551);}
function living(world,i){return members(world,i).filter(p=>!p.dead&&p.hp>0);}
function runMonsters(i){return [...i.scene.monsters.values()].filter(m=>!m.dead&&!m.isBrick&&m.kind==='monster');}
function say(world,i,p,text){if(text)world.emit(i.map,{type:'event:message',text,recipients:[p.id],actorId:p.id,instanceId:i.id});}
function run(i){return i.deadIslandRun||=fresh();}
function fresh(){return {choices:new Map(),stoneStage:new Map(),cooldown:new Map(),slaughter:new Map(),totems:new Map(DEAD_ISLAND_TOTEMS.map(t=>[t.key,{releasedUntil:0,rechargeUntil:0,recharged:true}])),bosses:new Map(),gems:new Map(),recollapse:{next:0,count:0,stage:0},gateLanding:new Map(),stage:0};}
export function resetDeadIslandBattle(i){const r=run(i);r.totems=fresh().totems;r.bosses.clear();r.gems.clear();r.recollapse={next:0,count:0,stage:0};r.slaughter.clear();r.stoneStage.clear();r.stage=0;}
/** Each player's own skill runtime owns that player's buffs (stat refresh, saves). */
function buff(world,p,index,ms){const sys=ensureSkills(world,p),entry=sys.statuses.add(sys.game.player,index,ms,{source:sys.game.player,noEffects:false});if(entry)world.changed(p);return !!entry;}
function unbuff(world,p,pred){const sys=ensureSkills(world,p),n=sys.statuses.remove(sys.game.player,pred,'cancel');if(n)world.changed(p);return n;}
function monsterSystem(world,i){const p=i.acting&&world.players.get(i.acting.account)===i.acting&&i.acting.instanceId===i.id?i.acting:living(world,i)[0]||members(world,i)[0];return p?ensureSkills(world,p).statuses:null;}
function monsterStatus(world,i,m,index,ms){const s=monsterSystem(world,i);return !!s?.add(actorFor(world,m,'monster'),index,ms,{noEffects:true});}
function monsterUnstatus(world,i,m,pred){const s=monsterSystem(world,i);return s?s.remove(actorFor(world,m,'monster'),pred,'cancel'):0;}
const has=(list,index)=>(list||[]).some(s=>Number(s.statusIndex)===index&&!(Number(s.remaining)<=0));
const remainingMs=(world,i)=>Math.max(1000,Math.min(7200000,i.expiresAt-world.now()));

/** Durable one-player inventory change with the reset() staging pattern,
 * serialized per player so overlapping stage-stone/Igniter writes never interleave. */
function commitProfile(world,p,mutate){
 return serializeLife(p,async()=>{
  const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
  const result=mutate(inv,profile);
  const staged=stageInstanceMembers(world,[p],[profile]),q=staged.candidates[0],old=p.sceneTransition;p.sceneTransition=true;
  try{world.changed(q);await world.persist(q);await staged.commit();}finally{p.sceneTransition=old;}
  return result;
 });
}
function actingMember(world,i){const p=i.acting;if(!p||world.players.get(p.account)!==p||p.leaving||p.dead||p.instanceId!==i.id)fail('This Dead Island action is no longer available.',409);return p;}

// ----------------------------------------------------------------------------------------- abilities
export async function chooseAbility(world,i,menu){
 const p=actingMember(world,i),r=run(i),a=ABILITY_BY_MENU.get(Number(menu));if(!a)refuse(world,302);
 if(i.director.phase!=='waiting')refuse(world,242);
 if(r.choices.has(p.characterId))refuse(world,205);
 if([...r.choices.values()].includes(a.menu))refuse(world,204);
 await commitProfile(world,p,inv=>{if(!inv.canFit([{item:a.item,count:1}])||!inv.add(a.item,1,{reason:'dead-island'}))refuse(world,206);});
 r.choices.set(p.characterId,a.menu);r.stoneStage.set(p.characterId,0);say(world,i,p,deadIslandText(world,218));return {ability:a.menu,item:a.item};
}
export async function releaseAbility(world,i){
 const p=actingMember(world,i),r=run(i);if(i.director.phase==='running')refuse(world,224);
 const menu=r.choices.get(p.characterId);if(!menu)refuse(world,223);const a=ABILITY_BY_MENU.get(menu);
 await commitProfile(world,p,inv=>{if(inv.count(a.item)>0)inv.remove(a.item,1);});
 r.choices.delete(p.characterId);r.stoneStage.delete(p.characterId);say(world,i,p,deadIslandText(world,222));return {released:menu};
}
/** One stone per chosen ability at each battle-stage start (ENGINE-CHOSEN; config). */
export async function issueStageStones(world,i,stage){
 const r=run(i);r.stage=stage;
 for(const p of members(world,i)){
  const menu=r.choices.get(p.characterId);if(!menu||(r.stoneStage.get(p.characterId)||0)>=stage)continue;
  const a=ABILITY_BY_MENU.get(menu);
  try{await commitProfile(world,p,inv=>{if(!inv.canFit([{item:a.item,count:DEAD_ISLAND_TIMING.stonesPerStage}])||!inv.add(a.item,DEAD_ISLAND_TIMING.stonesPerStage,{reason:'dead-island'}))refuse(world,206);});r.stoneStage.set(p.characterId,stage);say(world,i,p,deadIslandText(world,218));}
  catch(error){say(world,i,p,error.message);}
 }
}
/** Item-use path for Ancient Stones 7499..7508 (consumable, native cooldown). */
export function ancientStoneUse(world,p,c,entry,def){
 const a=ABILITY_BY_ITEM.get(Number(entry.itemIndex));if(!a)return false;
 const i=world.instances?.get(p.instanceId);
 if(!i||i.map!==551||!i.director||i.director.disposed||p.map!==551)fail('Ancient Stones can be used only on the Island of Deads.');
 if(i.director.phase!=='running')fail('Ancient Stones can be used only during battle.');
 const r=run(i),now=world.now(),key=`${p.characterId}:${a.item}`,ready=r.cooldown.get(key)||0;
 if(now<ready)fail('This item cannot be used now.');
 c.sys.consume(entry,1);r.cooldown.set(key,now+Math.max(0,Number(def.appraisal)||0));
 return {apply:()=>applyAbility(world,i,p,a)};
}
function applyAbility(world,i,p,a){
 const T=DEAD_ISLAND_TIMING;say(world,i,p,deadIslandText(world,217));
 if(a.kind==='self'){buff(world,p,a.status,T.abilityMs);if(a.status===7226)run(i).slaughter.set(p.characterId,world.now()+T.abilityMs);return;}
 if(a.kind==='guild'){for(const q of living(world,i))buff(world,q,a.status,T.abilityMs);return;}
 if(a.kind==='monsters'){for(const m of runMonsters(i))monsterStatus(world,i,m,a.status,T.shackleMs);return;}
 if(a.kind==='midas')midas(world,i);
}
function midas(world,i){
 const def=world.data.monsterDef(DEAD_ISLAND_RECOVERY_GEM);if(!def)return;const r=run(i),now=world.now();
 for(const m of runMonsters(i)){
  if(BOSS.has(m.monsterIndex)||m.monsterIndex===DEAD_ISLAND_RECOVERY_GEM||m.monsterIndex===DEAD_ISLAND_RECOLLAPSE.monster||m.def?.role==='object')continue;
  i.scene.monsters.delete(m.id);world.emit(551,{type:'leave',actorId:m.id,instanceId:i.id});
  const gem={id:`dungeon:${i.id}:${randomUUID()}`,map:551,instanceId:i.id,monsterIndex:DEAD_ISLAND_RECOVERY_GEM,name:def.name,x:m.x,z:m.z,hp:def.hp,maxHp:def.hp,home:{x:m.x,z:m.z},dead:false,targetId:null,attackAt:0,respawnSec:Infinity,respawnAt:Infinity,def,kind:'monster',spawnRecord:m.spawnRecord,deadIslandGem:true,setPosition(x,z){this.x=x;this.z=z;},play(){}};
  if(gem.spawnRecord)gem.spawnRecord.monster=gem;
  gem.onKilled=killer=>gemKilled(world,i,gem,killer);
  i.scene.monsters.set(gem.id,gem);r.gems.set(gem.id,now+DEAD_ISLAND_TIMING.midasCrystalMs);
 }
 i.director.effect(260);
}
function gemKilled(world,i,gem,killer){
 run(i).gems.delete(gem.id);
 // ENGINE-CHOSEN recovery: the crystal's name; its native object has no result row.
 if(killer&&!killer.dead&&killer.instanceId===i.id){killer.hp=killer.maxHp;killer.mp=killer.stats?.maxMp||killer.mp;world.changed(killer);}
}

// ----------------------------------------------------------------------------------------- monsters
const igniterDropped=new WeakSet();
function waveKilled(world,i,m,killer){
 if(!killer||i.director.phase!=='running'||igniterDropped.has(m))return;igniterDropped.add(m);
 // ENGINE-CHOSEN: native itemset4852 (its own 100000/100000 ratio) once per authored wave kill.
 const rolled=rollMonsterDrops({drops:{money:[],sets:[[DEAD_ISLAND_IGNITER_SET,100000,0]],fixed:[],fixedSets:[],maxSets:1}},world.data.progression?.monsters,{rng:world.random,itemRate:1,moneyRate:1});
 const ownership=partyLootOwner(world,killer,{x:m.x,z:m.z}),owner=ownership.player||killer;world.groundLoot||=new Map();
 for(const entry of rolled){if(entry.kind!=='item'||!world.data.itemDB.def(entry.itemIndex))continue;const uid=randomUUID();
  world.groundLoot.set(uid,{id:uid,map:551,instanceId:i.id,x:m.x,z:m.z,entry,ownerId:owner.id,protectedUntil:ownership.free?0:world.now()+lootOwnershipMs(world),expiresAt:world.now()+180000});}
}
function slaughterKill(world,i,killer){
 const until=run(i).slaughter.get(killer?.characterId);if(!until||world.now()>until||killer.dead)return;
 buff(world,killer,7226,Math.max(1000,until-world.now()));   // native MaxStackCount10 stacks per kill
}
/** Tag each run monster once: kill hooks and the boss native rows. */
function adopt(world,i,m){
 if(m.deadIslandRun)return;m.deadIslandRun=i.id;
 const previous=m.onKilled;
 m.onKilled=killer=>{previous?.(killer);slaughterKill(world,i,killer);if(DEAD_ISLAND_WAVE_MONSTERS.includes(m.monsterIndex))waveKilled(world,i,m,killer);};
 const b=BOSS.get(m.monsterIndex);if(!b)return;
 run(i).bosses.set(m.id,{absorb:0,weaken:0,neutralizedUntil:0,triforceDownUntil:0});
 monsterStatus(world,i,m,b.vitality,remainingMs(world,i));monsterStatus(world,i,m,DEAD_ISLAND_TRIFORCE,remainingMs(world,i));
}
const runOf=(world,m,target)=>{const i=m?.deadIslandRun&&world.instances?.get(m.deadIslandRun);return i&&target&&target.instanceId===i.id?i:null;};
/** A11 Explosion@Single@Suicidal 4100100 [radius,chance,percent]: percent of the
 * target's max HP (the A11 OX analysis reads Explosion HP from block0 = max), then
 * the source dies once. Replaces the ordinary swing; returns true when handled. */
export function deadIslandSuicide(world,m,target,key){
 const i=runOf(world,m,target),block=m?.def?.attacks?.[key];if(!i||!Array.isArray(block)||Number(block[7])!==4100100)return false;
 const args=block.slice(8);
 if(!target.dead&&world.random()*100<Number(args[1]||0)){const hp=incomingSkillDamage(world,target,m,Math.round(target.maxHp*Number(args[2]||0)/100),'melee');target.hp=Math.max(0,target.hp-hp);target.dead=target.hp===0;if(target.dead){target.path=[];target.profile.deaths=(target.profile.deaths||0)+1;}world.changed(target);world.emit(551,{type:'damage',sourceId:m.id,targetId:target.id,amount:hp,dead:target.dead,instanceId:i.id});}
 m.hp=0;m.dead=true;m.targetId=null;m.respawnAt=Infinity;world.emit(551,{type:'damage',sourceId:m.id,targetId:m.id,amount:0,dead:true,instanceId:i.id});
 return true;
}
/** Native attack result statuses of Dead Island monsters (core attacks are otherwise damage only). */
const STATUS_TAIL={1000101:3,1000202:3,1000201:3,3000001:4,3000005:4};
export function deadIslandMonsterAttack(world,m,target,key){
 const i=runOf(world,m,target);if(!i||target.dead)return;
 const block=m.def?.attacks?.[key];if(!Array.isArray(block))return;const code=Number(block[7]),args=block.slice(8);
 const at=STATUS_TAIL[code];if(at==null)return;const chance=Number(args[at]),status=Number(args[at+1]),ms=Number(args[at+2]);
 if(!(status>0&&ms>0&&chance>0))return;
 // The struck target was in reach when the swing fired; an area row also reaches the others.
 const area=code===1000202?Number(args[0])/128:0,targets=[target,...(area?living(world,i).filter(q=>q!==target&&Math.hypot(q.x-m.x,q.z-m.z)<=area):[])];
 for(const q of targets)if(!q.dead&&world.random()*100<chance)buff(world,q,status,ms);
}

// ----------------------------------------------------------------------------------------- totems
export async function resonate(world,i,npc){
 const t=TOTEM.get(Number(npc));if(!t)refuse(world,300);
 const p=actingMember(world,i),r=run(i),state=r.totems.get(t.key),now=world.now(),d=i.director;
 const check=()=>{if(d.phase!=='running')refuse(world,244);if(state.releasedUntil>world.now())refuse(world,246);if(state.rechargeUntil>world.now())refuse(world,232);if(new AuthoritativeInventory(p.profile,world.data.itemDB,{now:world.now}).count(DEAD_ISLAND_IGNITER)<1)refuse(world,245);};
 check();
 const ok=await d.sys.dialog.gauge('Resonating with the Ancient Totem',DEAD_ISLAND_TOTEM_TIMING.gaugeMs,{sound:[22,1028,25,29]});
 if(!ok)return {resonated:false};
 check();
 await commitProfile(world,p,inv=>{if(!inv.remove(DEAD_ISLAND_IGNITER,1))refuse(world,245);});
 state.releasedUntil=world.now()+DEAD_ISLAND_TOTEM_TIMING.releaseMs;state.rechargeUntil=world.now()+DEAD_ISLAND_TOTEM_TIMING.rechargeMs;state.recharged=false;
 d.effect(t.released);combine(world,i);return {resonated:true,totem:t.npc,at:now};
}
function combine(world,i){
 const r=run(i),now=world.now(),released=DEAD_ISLAND_TOTEMS.filter(t=>r.totems.get(t.key).releasedUntil>now).map(t=>t.key);
 if(released.length<5)return null;
 const missing=DEAD_ISLAND_TOTEMS.map(t=>t.key).find(k=>!released.includes(k)),combo=DEAD_ISLAND_COMBOS.find(c=>c.missing===missing);
 for(const k of released)r.totems.get(k).releasedUntil=0;
 if(!combo)return null;
 const T=DEAD_ISLAND_TOTEM_TIMING,d=i.director;d.effect(combo.message);
 if(combo.effect==='weaken')for(const m of runMonsters(i))monsterStatus(world,i,m,combo.status,T.comboMs);
 if(combo.effect==='overclock')for(const q of living(world,i))buff(world,q,combo.status,T.comboMs);
 if(combo.effect==='invincible')for(const q of living(world,i))buff(world,q,combo.status,T.invincibleMs);
 if(combo.effect==='liftCurse'){for(const q of living(world,i)){unbuff(world,q,s=>CURSES.has(Number(s.statusIndex)));buff(world,q,combo.status,T.comboMs);}absorbCurse(world,i);}
 if(combo.effect==='neutralize')for(const m of runMonsters(i)){const b=BOSS.get(m.monsterIndex),s=r.bosses.get(m.id);if(!b||!s)continue;monsterUnstatus(world,i,m,e=>Number(e.statusIndex)===b.vitality);monsterStatus(world,i,m,b.neutralize,T.comboMs);s.neutralizedUntil=now+T.comboMs;}
 if(combo.effect==='triforce')for(const m of runMonsters(i)){const s=r.bosses.get(m.id);if(!s)continue;monsterUnstatus(world,i,m,e=>Number(e.statusIndex)===DEAD_ISLAND_TRIFORCE);s.triforceDownUntil=now+T.comboMs;}
 return combo;
}
function absorbCurse(world,i){
 const r=run(i),now=world.now();let any=false;
 for(const m of runMonsters(i)){
  const b=BOSS.get(m.monsterIndex),s=r.bosses.get(m.id);if(!b||!s)continue;any=true;
  const neutral=s.neutralizedUntil>now,level=neutral?(s.weaken=Math.min(15,s.weaken+1)):(s.absorb=Math.min(15,s.absorb+1)),base=neutral?DEAD_ISLAND_ABSORB_WEAKEN:DEAD_ISLAND_ABSORB_UPGRADE;
  monsterUnstatus(world,i,m,e=>{const n=Number(e.statusIndex);return n>=base&&n<base+15;});monsterStatus(world,i,m,base+level-1,remainingMs(world,i));
  i.director.effect(neutral?b.defDown:b.attUp);
 }
 if(any)i.director.effect(262);
}

// ----------------------------------------------------------------------------------------- gates / title14
/** The arena collision region (flood fill from the arena centre), computed once per run scene. */
function arenaMask(i){
 if(i.deadIslandArena?.scene===i.scene)return i.deadIslandArena.mask;
 const col=i.scene.collision,W=col.width,H=col.height,c=i.scene.nearest(DEAD_ISLAND_ARENA_CENTRE.x,DEAD_ISLAND_ARENA_CENTRE.z),mask=new Uint8Array(W*H);
 if(c){const start=Math.floor(c.z)*W+Math.floor(c.x),q=[start];mask[start]=1;while(q.length){const v=q.pop(),x=v%W,z=(v/W)|0;for(const [dx,dz]of [[1,0],[-1,0],[0,1],[0,-1]]){const nx=x+dx,nz=z+dz,u=nz*W+nx;if(nx<0||nz<0||nx>=W||nz>=H||mask[u]||col.cells[u])continue;mask[u]=1;q.push(u);}}}
 i.deadIslandArena={scene:i.scene,mask};return mask;
}
export function inDeadIslandArena(i,x,z){const W=i.scene.collision.width;return !!arenaMask(i)[Math.floor(z)*W+Math.floor(x)];}
function gateLanding(world,i,npc){
 const r=run(i);if(r.gateLanding.has(npc))return r.gateLanding.get(npc);
 const sn=i.director.scriptNpc(npc),col=i.scene.collision,W=col.width,c=DEAD_ISLAND_ARENA_CENTRE;if(!sn)return null;
 const L=Math.hypot(c.x-sn.x,c.z-sn.y);let wall=false,landing=null;
 for(let t=0;t<=L;t+=.5){const x=sn.x+(c.x-sn.x)*t/L,z=sn.y+(c.z-sn.y)*t/L,cell=Math.floor(z)*W+Math.floor(x);if(col.cells[cell]){wall=true;continue;}if(wall){const at={x:Math.floor(x)+.5+(c.x-sn.x)/L*2,z:Math.floor(z)+.5+(c.z-sn.y)/L*2},safe=i.scene.nearest(at.x,at.z);if(safe&&inDeadIslandArena(i,safe.x,safe.z)){landing=safe;break;}}}
 r.gateLanding.set(npc,landing);return landing;
}
/** The landing and title14 are one staged profile, serialized per player: the save publishes both (with the 2802|3 message);
 * a failed save leaves the member at the gate with no title, stat change or message, and a retry grants it exactly once. */
export async function enterArena(world,i,npc){
 if(!DEAD_ISLAND_GATES.includes(Number(npc)))refuse(world,300);
 const p=actingMember(world,i),at=gateLanding(world,i,Number(npc));if(!at)fail('The original island gate has no safe arena landing.',503);
 return serializeLife(p,async()=>{
  if(world.players.get(p.account)!==p||p.leaving||p.dead||p.instanceId!==i.id||p.map!==551)fail('This Dead Island action is no longer available.',409);
  const staged=stageInstanceMembers(world,[p],[structuredClone(p.profile)]),q=staged.candidates[0],old=p.sceneTransition;
  q.x=at.x;q.z=at.z;q.path=[];
  const earned=grantTitle(staged.world,q,DEAD_ISLAND_TITLE);
  p.sceneTransition=true;
  try{world.changed(q);await world.persist(q);await staged.commit();}finally{p.sceneTransition=old;}
  // The earner's own skill refresh keeps its passive entries in the derivation; the plain title refresh is the fallback.
  p.attackTarget=null;if(earned){if(p._skills?.game?.refreshPlayerStats)p._skills.game.refreshPlayerStats();else refreshTitleStats(world,p);}world.changed(p);
  world.emit(551,{type:'move',actorId:p.id,x:p.x,z:p.z,instanceId:i.id});
  return {entered:true,x:at.x,z:at.z,title:earned?DEAD_ISLAND_TITLE:null};
 });
}

// ----------------------------------------------------------------------------------------- tick
export function tickDeadIslandRun(world,i){
 const d=i.director;if(!d||d.disposed)return;const r=run(i),now=world.now();
 for(const m of i.scene.monsters.values())if(!m.dead&&!m.isBrick&&m.kind==='monster')adopt(world,i,m);
 for(const t of DEAD_ISLAND_TOTEMS){const s=r.totems.get(t.key);if(s.releasedUntil&&s.releasedUntil<=now){s.releasedUntil=0;d.effect(238);}if(!s.recharged&&s.rechargeUntil<=now){s.recharged=true;d.effect(239);}}
 for(const [id,until]of r.gems)if(until<=now){const gem=i.scene.monsters.get(id);r.gems.delete(id);if(gem&&!gem.dead){gem.dead=true;gem.hp=0;gem.respawnAt=Infinity;world.emit(551,{type:'damage',sourceId:gem.id,targetId:gem.id,amount:0,dead:true,instanceId:i.id});}}
 for(const m of runMonsters(i)){
  const b=BOSS.get(m.monsterIndex),s=r.bosses.get(m.id);if(!b||!s)continue;
  if(s.neutralizedUntil&&s.neutralizedUntil<=now){s.neutralizedUntil=0;monsterStatus(world,i,m,b.vitality,remainingMs(world,i));}
  if(s.triforceDownUntil&&s.triforceDownUntil<=now){s.triforceDownUntil=0;monsterStatus(world,i,m,DEAD_ISLAND_TRIFORCE,remainingMs(world,i));}
 }
 // ENGINE-CHOSEN Recollapse pressure from stage2 (config).
 const stage=d.stages?.filter(st=>st.spawned).length||0,R=DEAD_ISLAND_RECOLLAPSE;
 if(d.phase!=='running'||stage<R.firstStage){r.recollapse.next=0;return;}
 if(r.recollapse.stage!==stage){r.recollapse.stage=stage;r.recollapse.count=stage-R.firstStage+1;r.recollapse.next=now+R.everyMs;d.effect(225);return;}
 if(now<r.recollapse.next)return;r.recollapse.next=now+R.everyMs;
 const targets=living(world,i).filter(p=>inDeadIslandArena(i,p.x,p.z));if(!targets.length)return;
 const def=world.data.monsterDef(R.monster);if(!def)return;
 for(let n=0;n<r.recollapse.count;n++){const p=targets[Math.floor(world.random()*targets.length)],near=i.scene.nearest(p.x+2,p.z+2),at=near&&inDeadIslandArena(i,near.x,near.z)?near:{x:p.x,z:p.z};
  const m={id:`dungeon:${i.id}:${randomUUID()}`,map:551,instanceId:i.id,monsterIndex:R.monster,name:def.name,...at,hp:def.hp,maxHp:def.hp,home:{...at},dead:false,targetId:null,attackAt:0,respawnSec:Infinity,respawnAt:Infinity,def,kind:'monster',oneShot:true,setPosition(x,z){this.x=x;this.z=z;},play(){}};
  i.scene.monsters.set(m.id,m);adopt(world,i,m);}
 d.effect(226);
}
/** Native Triforce/"Invincible" option on a Dead Island boss blocks player damage. */
export function deadIslandBarrier(m){return !!m?.deadIslandRun&&BOSS.has(m.monsterIndex)&&has(m.statuses,DEAD_ISLAND_TRIFORCE);}
export function deadIslandRunState(i){const r=i.deadIslandRun;return r?{choices:Object.fromEntries(r.choices),totems:Object.fromEntries([...r.totems].map(([k,v])=>[k,{...v}])),bosses:[...r.bosses.values()].map(v=>({...v})),gems:r.gems.size}:null;}
