import {rejectsResurrection,attackPreferenceRefusal} from './gameplay-preferences.mjs';
import {offerResurrection,answerResurrection} from './resurrection-offer.mjs';
import {offerSharedTarget,answerSharedTarget,tickSharedTarget,noteSharedTargetIntent} from './shared-target.mjs';
import {serializeLife} from './life-transactions.mjs';
import {publishProfileChanges,persistInterveningProgress} from './profile-publication.mjs';
import {objectHitPoint} from './object-combat.mjs';
import {applyAbilityCap} from '../../src/game/ability-cap.js';
import {skillImpactEmitter} from './skill-cosmetic-events.mjs';
import {isEventObject,eventObjectActive,eventObjectDamage,eventObjectElementDamage} from './event-object-combat.mjs';
import {isSiegeRenewObject,siegeRenewObjectActive,siegeRenewObjectDamage,siegeRenewObjectElementDamage} from './siege-renew-controller.mjs';
import {isSiegeRenewGuard,siegeRenewGuardActive} from './siege-renew-sentries.mjs';
import {canClaimDeadFrontTreasure} from './dead-front-treasure.mjs';
import {mapFor,sameScene} from './scene.mjs';
import {isPvpTarget,isDuelTarget,pvpOpponents,pvpSkillAdjust,PVP_TEXT,noteForcedIntent} from './pvp.mjs';
import {seedStarterSlot} from '../../src/systems/skills/starter.js';
import {furyHit} from './fury.mjs';
import {quickslotEntry,quickslotLayout} from './quickslots.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {meisterRank,meisterRequirement} from '../../src/systems/skills/rank.js';
import { resolveAwakeningGrade, canSelectMeisterPath } from '../../src/systems/skills/trans-up-rules.js';
// Trusted headless adapter of the existing gameplay SkillEngine. Wire commands contain
// skill/target intent only; all levels, resources, timings and results come from server data.
import fs from 'node:fs/promises';
import path from 'node:path';
import * as THREE from 'three';
import { SkillEngine } from '../../src/systems/skills/engine.js';
import { SkillData } from '../../src/systems/skills/data.js';
import { StatusSystem, optionSum } from '../../src/systems/skills/statuses.js';
import { applyDamage, isAlive, resolveAttack } from '../../src/game/combat.js';
import { SummonSystem } from '../../src/systems/skills/summons.js';
import { parseServantGauges } from '../../src/systems/skills/servant-gauge-rules.js';
import {questSkill} from './quests.mjs';
import { decodeText, parseCSV } from '../../src/formats/binreader.js';
import { parseSkillMessages } from '../../src/systems/skills/messages.js';
import { noteMonsterHit } from './titles.mjs';
import { respawnDelayMs } from '../../src/game/monster-rules.js';
import { clearHate, plainHitHate } from '../../src/game/hate.js';
import { monsterHit } from './monster-hit.mjs';
import { divideShare } from './damage-share.mjs';
import { isDamageShareSkill, shareRadius } from '../../src/systems/skills/damage-share.js';
import { isPartyRecallSkill, withinRecallRange } from '../../src/systems/skills/party-recall.js';
import { movementState, trackForcedDisplacement } from './movement-authority.mjs';

export const SKILL_SCHEMAS = {
 cast: ['token','type','skillId','targetId','x','z','forced','castRequestId'], learn: ['token','type','skillId'],
 shareTarget:['token','type','operation','id'],
 meisterPath: ['token','type','path'], meisterReinforce: ['token','type','skillId','uid'],
 hotbar: ['token','type','set','slot','entry'], quickslots: ['token','type','layout'],
 summonOrder: ['token','type','order','targetId'], summonGreat: ['token','type','targetId'],
 // MAINBAR: cancel one of the player's own non-harmful statuses (buff window right click, monster transformation
 // cancel button, upkeep icons). Premium service entries are grouped server state and stay.
 statusCancel: ['token','type','key'],
 resurrection:['token','type','id','accept'],
};
function refuse(message) { const error = new Error(message); error.status = 400; throw error; }
// D6 / WA4: Global stringtable_skill cate 60 code 42 "You cannot use the skill at the moment."
// (MATH-VERIFY row 18 / TODO D6). engine.msg(N) returns "(N)" when the prepared stringtable lacks the code,
// so never treat a parenthetical code as the player-facing text.
const GLOBAL_SKILL_REFUSAL_42 = 'You cannot use the skill at the moment.';
function skillMsg(engine, code, fallback) {
  const text = engine?.msg?.(code);
  if (typeof text === 'string' && text && text !== `(${code})`) return text;
  return fallback;
}
function usabilityRefusal(engine, reason) {
  // Client useSkill already _msg(42) for cooldown / silenced / out-of-range; map usability() string reasons
  // onto the same Global cate-60 codes where they exist.
  if (reason === 'cooldown' || reason === 'silenced' || reason === 'unknown' || reason === 'mounted' || reason === 'unsupported')
    return skillMsg(engine, 42, GLOBAL_SKILL_REFUSAL_42);
  if (reason === 'mp') return skillMsg(engine, 20, 'You do not have enough MP.');
  if (reason === 'hp') return skillMsg(engine, 21, 'You do not have enough HP.');
  if (reason === 'fury') return skillMsg(engine, 41, "You don't have enough rage.");
  if (reason === 'weapon') return skillMsg(engine, 23, '[Message] The current weapon type is not appropriate.');
  if (reason === 'unlearned') return skillMsg(engine, 45, "You don't have the Skill.");
  if (reason === 'dead') return skillMsg(engine, 19, 'You are dead; the skill has been cancelled.');
  if (reason === 'stage') return skillMsg(engine, 54, 'You are not in the Trans-Up mode; this skill cannot be used.');
  return skillMsg(engine, 42, GLOBAL_SKILL_REFUSAL_42);
}
const fixedObject=m=>isEventObject(m)||isSiegeRenewObject(m);
const availableObject=(world,p,m)=>(!isEventObject(m)||eventObjectActive(world,p,m))&&(!isSiegeRenewObject(m)||siegeRenewObjectActive(world,p,m))&&(!isSiegeRenewGuard(m)||siegeRenewGuardActive(world,p,m));
export async function loadSkillPacks(gamedataRoot, dataRoot) {
 const read = async name => JSON.parse(await fs.readFile(path.join(gamedataRoot,name),'utf8'));
 const [common,packs,full,status] = await Promise.all([read('skills/common.json'),
  Promise.all(Array.from({length:15},(_,i)=>read(`skills/class_${i}.json`))),read('skills.json'),read('skills_status.json')]);
 const spellRows = parseCSV(decodeText(await fs.readFile(path.join(dataRoot,'share/article/spell.csv'))));
 const header=spellRows.shift();
 const spells=spellRows.map(row=>Object.fromEntries(header.map((key,i)=>[key.trim(),Number(row[i])||0])));
 let skillGauges=new Map();
 try { const rows=parseCSV(decodeText(await fs.readFile(path.join(dataRoot,'share/article/gage.csv'))));
  const head=rows.shift();skillGauges=parseServantGauges(rows.map(row=>Object.fromEntries(head.map((key,i)=>[key.trim(),row[i]])))); }
 catch(error){console.warn('[skills] servant gauge table unavailable on the host; Great attacks disabled',error?.code||error?.message);}
 // The engine's own message texts (<cate> 60). Without them SkillEngine.msg(code) answers "(code)", and that bare code was what a
 // player saw for a queued press that could not start or a refused cast. Same file and parser as the client.
 let skillMessages={};
 try{skillMessages=parseSkillMessages(decodeText(await fs.readFile(path.join(dataRoot,'script/string/normal/stringtable_skill.txt')),true));}
 catch(error){console.warn('[skills] stringtable_skill.txt unavailable on the host; engine messages will show as codes',error?.code||error?.message);}
 return {skillCommon:common,skillPacks:packs,skillFull:full,skillStatuses:status.statuses||{},skillSpells:spells,skillGauges,skillMessages};
}
function dataFor(world,p) {
 const data=new SkillData(),pack=world.data.skillPacks?.[p.profile.classIndex];
 data.rootMotionCurves=world.data.skillRootMotion?.table;
 if(!pack) refuse('Skill runtime data is unavailable.');
 data.classIndex=p.profile.classIndex;data.pack=pack;data.common=world.data.skillCommon||{};
 const put=(map,object)=>{for(const [key,value]of Object.entries(object||{}))map.set(Number(key),value)};
 put(data.skills,pack.skills);put(data.statuses,world.data.skillStatuses);put(data.statuses,data.common.statuses);put(data.statuses,pack.statuses);
 put(data.remotes,world.data.skillFull?.remotes);put(data.remotes,data.common.remotes);put(data.remotes,pack.remotes);
 put(data.servants,world.data.skillFull?.servants);put(data.servants,pack.servants);put(data.totems,world.data.skillFull?.totems);put(data.totems,pack.totems);
 // Headless execution never fetches relative browser URLs or loads visual asset scenes.
 data._wantFull=()=>{};return data;
}
export function actorFor(world,record,kind) {
 if(record._skillActor)return record._skillActor;
 const isPlayer=kind==='player';
 const actor=new Proxy(record,{get(target,key){
  if(key==='_record')return target;
  if(key==='game')return target._skills?.game;
  if(key==='kind')return kind;
  if(key==='mounted')return target.mount?.phase==='on';
  if(key==='def')return isPlayer?null:{...target.def,exp:0,dil:0}; // World.reward is the sole reward path.
  if(key==='level')return isPlayer?target.profile.level:target.def?.level||1;
  if(key==='maxMp')return target.stats?.maxMp||0;
  if(key==='statuses')return isPlayer?(target.profile.buffs ||= []):(target.statuses ||= []);
  if(key==='radius')return Number(target.radius)||0.5;
  if(key==='scale')return 1;
  if(key==='height')return 1.8;
  if(key==='y')return 0;
  if(key==='name')return target.profile?.name||target.name;
  if(key==='id')return target.id;
  if(key==='play')return (state)=>{target.state=state;return true};
  if(key==='faceTowards')return (x,z)=>{target.yaw=Math.atan2(-(x-target.x),-(z-target.z))};
  if(key==='setOpacity'||key==='setHighlight')return ()=>{};
  if(key==='revive')return fraction=>{if(fixedObject(target)||rejectsResurrection(target))return;if(isPlayer&&!target.npcPlayer&&!target.profile?.npcPlayer)return offerResurrection(world,target,fraction);target.dead=false;target.hp=Math.max(1,target.maxHp*fraction);world.changed(target);world.emit(target.map,{type:'revive',actorId:target.id})};
  if(key==='setPosition')return (x,z,source)=>{
   if(fixedObject(target)&&Number(target.brickDef.raw?.AntiKnockBackRate)>=100)return;
   const map=mapFor(world,target);if(!Number.isFinite(x)||!Number.isFinite(z)||!map?.isWalkable(x,z))return;
   // PING-FLAT / ROUND2: knockback/teleport pose is forced displacement for clients, not a durable SQL dirty.
   target.x=x;target.z=z;if(isPlayer){if(source!=='skill-root')trackForcedDisplacement(world,target);if(typeof world.poseChanged==='function')world.poseChanged(target);else world.changed(target);}
  };
  return Reflect.get(target,key);
 },set(target,key,value){
  if((key==='x'||key==='z')&&fixedObject(target)&&Number(target.brickDef.raw?.AntiKnockBackRate)>=100)return true;
  if(key==='statuses'&&isPlayer){target.profile.buffs=value;return true}
  if(key==='level'&&isPlayer){target.profile.level=value;return true}
  if(key==='maxMp'){return true}
  Reflect.set(target,key,value);return true;
 }});
 Object.defineProperty(record,'_skillActor',{value:actor,writable:true,configurable:true});return actor;
}
function monstersFor(world,p){return [...(mapFor(world,p)?.monsters.values()||[])].filter(m=>availableObject(world,p,m)).map(m=>actorFor(world,m,'monster'))}
function playersFor(world,p){return [...world.players.values()].filter(q=>!q.leaving&&!q.customMapPending&&sameScene(q,p)).map(q=>actorFor(world,q,'player'))}
function skillAlly(world,p,q){
 if(q===p)return true;
 const party=p.partyId&&world.parties?.get(p.partyId);
 return !!q&&!q.leaving&&sameScene(p,q)&&!!party&&q.partyId===p.partyId&&party.members.includes(p.id)&&party.members.includes(q.id);
}
// JUDGMENT (lane 51 g; Global has no player bots, see npc-pvp.mjs): automated players support only themselves/current
// party. Native ordinary human single-ally targeting retains its existing mask.
function npcBeneficiary(world,p,q){return !(p?.npcPlayer||p?.profile?.npcPlayer)||skillAlly(world,p,q);}
// A queued explicit command retains the same host geometry/scene authority as
// its initial acceptance. Native target masks, recipient selection and costs
// still run in useSkill; this does not add LOS tests to area recipients or procs.
function queuedSkillCommandGuard(world,p,engine,queued,map,target,point){
 const session=p.token,scene={map:p.map,channel:p.channel??0,instance:p.instanceId||null},
  opts=queued.opts,index=queued.index,record=target?._record,targetId=target?.id;
 return ()=>{
  if(engine.queued!==queued||queued.opts!==opts||queued.index!==index||opts.target!==target||opts.point!==point||
   world.players.get(p.account)!==p||p.token!==session||p.leaving||p.sceneTransition||p.customMapPending||p._skills?.engine!==engine||
   p.map!==scene.map||(p.channel??0)!==scene.channel||(p.instanceId||null)!==scene.instance||!map||mapFor(world,p)!==map)return false;
  if(target){
   if(!record||target.id!==targetId)return false;
   if(target.kind==='monster'){
    if(map.monsters.get(targetId)!==record||!availableObject(world,p,record)||!canClaimDeadFrontTreasure(world,p,record))return false;
   }else if(target.kind==='player'){
    if(world.players.get(record.account)!==record||record.leaving||record.customMapPending||!sameScene(record,p))return false;
   }else return false;
   if(map.collision?.lineOfSight&&!(target.isBrick?objectHitPoint(map,p,target):map.collision.lineOfSight(p.x,p.z,target.x,target.z)))return false;
  }
  if(point&&(!Number.isFinite(point.x)||!Number.isFinite(point.z)||!map.isWalkable(point.x,point.z)||
   map.collision?.lineOfSight&&!map.collision.lineOfSight(p.x,p.z,point.x,point.z)))return false;
  return true;
 };
}
// Divide Pain1126 and Recall702/1502 use mask64 for a selected party member, not the generic own-servant target.
// Divide has separate damage-share admission: a living player of the caster's party in the same scene, never the caster itself (nothing to transfer).
const divideTargetOnly=skill=>isDamageShareSkill(skill)&&(Number(skill.targetMask)&64)!==0&&(Number(skill.targetMask)&(2|4|8|16|32))===0;
class ServerSkillEngine extends SkillEngine {
 _validRecallTarget(skill,target){
  const p=this.game._playerRecord,world=this.game._world,q=target?._record,map=mapFor(world,p);
  return !!q&&q!==p&&target.kind==='player'&&world.players.get(p.account)===p&&world.players.get(q.account)===q
   &&!p.leaving&&!p.sceneTransition&&!p.customMapPending&&!q.leaving&&!q.sceneTransition&&!q.customMapPending
   &&isAlive(this.game.player)&&isAlive(target)&&!target.disposed&&!this.statuses.flags(target).target
   &&sameScene(p,q)&&skillAlly(world,p,q)&&!isPvpTarget(world,p,q)&&!isDuelTarget(world,p,q)&&withinRecallRange(skill,this.game.player,target)
   &&!!map?.isWalkable(p.x,p.z)&&(!map.collision?.lineOfSight||map.collision.lineOfSight(p.x,p.z,q.x,q.z));
 }
 _recallPartyMember(ctx){
  if(!this._validRecallTarget(ctx.skill,ctx.target))return false;
  const world=this.game._world,p=this.game._playerRecord,q=ctx.target._record;
  // Capture the pre-move authority pose before changing either coordinate, then publish one forced revision.
  movementState(world,q);q.x=p.x;q.z=p.z;q.path=[];
  trackForcedDisplacement(world,q);if(typeof world.poseChanged==='function')world.poseChanged(q);else{world.snapshotPublicRows?.delete(q);world.changed(q);} // PING-FLAT / ROUND2: same-map party recall is forced pose, not durable SQL
  return true;
 }
 _pickTarget(skill,opts){
  const target=opts.target,p=this.game._playerRecord,world=this.game._world;
  if(divideTargetOnly(skill)){
   const record=target?._record;
   if(!target||target.kind!=='player'||!record||record===p||!isAlive(target)||!sameScene(record,p)||!skillAlly(world,p,record)||isPvpTarget(world,p,record))return {error:50};
   return {target,point:null};
  }
  if(target?.kind==='player'&&(Number(skill.targetMask)&32)&&rejectsResurrection(target._record))return {error:223};
  if(target?.kind==='monster'&&!availableObject(world,p,target._record))return {error:50};
  if(target?.kind==='monster'&&!canClaimDeadFrontTreasure(world,p,target._record))return {error:50};
  if(target?.kind==='player'&&(Number(skill.targetMask)&(2|32))&&!npcBeneficiary(world,p,target._record)&&!((Number(skill.targetMask)&4)&&this._hostile(target)))return {error:50};
  return super._pickTarget(skill,opts);
 }
 applyImpact(ctx,r,unit,point,extra={}){
  const target=ctx.target;
  // Both the 3s protective status and the later recall revalidate the same selected member.
  if(isPartyRecallSkill(ctx.skill)&&!this._validRecallTarget(ctx.skill,target))return false;
  if(target?.kind==='monster'&&!availableObject(this.game._world,this.game._playerRecord,target._record))return;
  // Party membership can change between acceptance, a queued cast and impact.
  if(target?.kind==='player'&&(Number(ctx.skill?.targetMask)&(2|32))&&!npcBeneficiary(this.game._world,this.game._playerRecord,target._record)&&!((Number(ctx.skill.targetMask)&4)&&this._hostile(target)))return;
  // Divide Pain (cast row 2000502, radius args[0] = 0): the status goes to the selected party member only, re-checked now
  // because party, scene and life can change during the 1.4 s cast. The caster gets no 8401 entry: the row names one
  // recipient, and a self entry would replace (status group 104) another Warrior's protection on the caster.
  // Force (2000501, args[0] = 2560 = 20 m) keeps the base engine's party-area recipients, the caster included (O2).
  if(r?.family==='damage_share'&&shareRadius(r)===0){
   const caster=ctx.caster,owner=this.game._playerRecord,t=ctx.target;
   if(!(t&&t!==caster&&t.kind==='player'&&isAlive(t)&&sameScene(t._record,owner)&&skillAlly(this.game._world,owner,t._record)&&!isPvpTarget(this.game._world,owner,t._record)))return;   // fizzles: nothing applied without a protected member
   this._applyStatusResult(ctx,{...r,chance:r.chance||100,durationMs:r.durationMs||this._statusDefaultMs(r)},t,()=>{});   // the missing hit-effect visual stays undrawn
   return;
  }
  const previous=this._partyRecipients;this._partyRecipients=r?.target==='party'||['area_status_party','spell_party','damage_share'].includes(r?.family);
  if(ctx.target&&ctx.target!==ctx.caster)noteSharedTargetIntent(this.game._world,this.game._playerRecord,ctx.target.id);
  try{return super.applyImpact(ctx,r,unit,point,extra);}finally{this._partyRecipients=previous;}
 }
 _playCastEffect() {} // Client approved phases already own caster FX.
 // QUEUE: a cast pressed during a running skill waits in the original engine's single `queued` slot (engine.js header:
 // "One skill pressed during another is queued") and starts when the running skill ends, through the same useSkill checks
 // (cooldown, cost, target, range) at that moment. When it cannot start then, the player is told (skillrefuse event) instead of
 // the press vanishing. The validated target is bound here because the command no longer runs at start time.
 useSkill(index,opts={}) {
  const p=this.game.player,skill=this.skillDef(index);
  if(this.active&&!opts.fromProc&&skill&&this.active.skill===skill){this.queued={index:skill.index,opts};return false;}   // same skill: queued too (see the cast command)
  if(!this.active&&opts.target&&opts.target!==p&&skill&&(Number(skill.targetMask)&(2|4|8|32)))p.target=opts.target;
  const started=super.useSkill(index,opts);
  if(!started&&!this.active&&this._startingQueued===Number(index))this.game._queuedSkillRefused?.(Number(index),opts.castRequestId);
  return started;
 }
 _finish() {
  if(this.queued){
   const queued=this.queued;let valid=true;
   for(const key of ['commandStartGuard','npcStartGuard'])if(Object.hasOwn(queued,key)){
    try{valid=queued[key]()===true;}catch{valid=false;}if(!valid)break;
   }
   if(!valid){const id=queued.index;this.queued=null;this.game._queuedSkillRefused?.(id,queued.opts?.castRequestId);}
  }
  const q=this.queued;this._startingQueued=q?Number(q.index):null;if(q&&this.game._playerRecord)this.game._playerRecord._skillMessage=null;
  try{super._finish();}finally{this._startingQueued=null;}
 }
 skillDamage(ctx,t,r){
  if(isSiegeRenewObject(t)){
   const kind=['melee','range','magic'].includes(r.damageClass)?r.damageClass:['melee','range','magic'].includes(ctx.skill?.type)?ctx.skill.type:undefined;
   const result=resolveAttack(ctx.caster,t,{skill:ctx.skill,kind,addDamage:Number(r.addDamage)||0,multiplier:Number(r.damagePct)>0?Number(r.damagePct)/100:1,data:this.game.data,nativeBrick:true});
   result.skill=ctx.skill;result.amount=siegeRenewObjectElementDamage(t,result.amount,r.element,r.elementPct);return result;
  }
  if(!isEventObject(t))return super.skillDamage(ctx,t,r);
  const result=super.skillDamage(ctx,t,{...r,element:null});
  result.amount=eventObjectElementDamage(t,result.amount,r.element,r.elementPct);return result;
 }
 unitsNear(point,radius,ref,side='enemy') {
  const world=this.game._world,p=this.game._playerRecord;
  const foes=side==='enemy'?pvpOpponents(world,p):[];
  const requireParty=this._partyRecipients||p.npcPlayer||p.profile.npcPlayer;
  const pool=side==='enemy'?monstersFor(world,p).concat(foes.map(q=>actorFor(world,q,'player'))):playersFor(world,p).filter(a=>(!requireParty||skillAlly(world,p,a._record))&&!isPvpTarget(world,p,a._record)).concat(this.summons?.all()||[]);
  return pool.filter(a=>!a.dead&&!a.disposed&&(a.kind!=='monster'||canClaimDeadFrontTreasure(world,p,a._record))&&Math.hypot(a.x-point.x,a.z-point.z)<=radius+(a.radius||0.5)*0.5)
   .sort((a,b)=>Math.hypot(a.x-point.x,a.z-point.z)-Math.hypot(b.x-point.x,b.z-point.z));
 }
}
function refresh(world,p,engine) {
 const buffs=p.profile.buffs||[],passives=engine?.passiveEntries()||[];
 p.stats=world.data.stats({...p.profile,buffs:buffs.concat(passives)},p,world.now());
 p.maxHp=p.stats.maxHp;p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp,p.stats.maxMp||0);
 // A lower maximum (an expired max HP or shield status) clamps the current shield too, as the local stat hook does.
 p.maxShield=Math.max(0,Number(p.stats.maxShield)||0);p.shield=Math.min(Number(p.shield)||0,p.maxShield);world.changed(p);
}
// Seconds left of the running skill's own timeline (current phase remainder + every later phase), from the data durations.
export function activeRemaining(engine) {
 const a=engine?.active;if(!a)return 0;
 let seconds=Math.max(0,(Number(a.cur?.dur)||0)-(Number(a.cur?.t)||0));
 for(let i=Math.max(0,a.i+1);i<a.phases.length;i++)seconds+=(Number(a.phases[i].durationMs)||0)/1000;
 return seconds;
}
function saveCooldowns(p,engine) {
 // Headless skill times use the authoritative world clock in seconds. Results
 // may reset timers after cast acceptance, so snapshot/save state must follow.
 p.profile.skillCooldowns=Object.fromEntries([...engine.cooldowns].map(([id,c])=>[id,Math.round(c.end*1000)]));
}
// STEP10-LANE51 Blow (ActivePoint subtype 0xf) - older server reference (DekaronServer.exe, static read): after a landed hit
// (0x5e0ae0 pipeline: 0x585838, 0x596779, 0x5a1db2, 0x5a2b37, 0x5a2d33, 0x5a2fc3, 0x5a4e6d) the senders 0x5e0350 (PC) /
// 0x5e0880 (non-PC) read the HIT actor's status option 0xab = KNIGHT_SPECIAL_OTHER_DEATHBLOW (registered at 0x524ce3);
// with value V > 0: damage = V when HP > V, else HP - 1 (never lethal); bricks (actor type 5) are excluded; the status is
// not consumed, so it drains on every hit while it lasts. Global share/skill/status.csv carries the option on 122 rows
// (e.g. 6168 "Shock\Blow" 2750, 6181 3500). The client draws the Blow word (render 0xb, floaters.js e.blow).
export function blowDamage(hp,v){hp=Math.floor(Number(hp)||0);v=Math.floor(Number(v)||0);if(!(v>0)||hp<=0)return 0;return hp>v?v:Math.max(0,hp-1);}
/** Blow after a plain (basic) hit - same rule; the hit record's own statuses (a character's profile.buffs, a monster's statuses). */
export function basicHitBlow(world,sourceId,rec){
 if(!rec||rec.dead||!(rec.hp>0)||fixedObject(rec)||isEventObject(rec)||isSiegeRenewObject(rec))return 0;
 const list=rec.profile?(rec.profile.buffs||rec.statuses):rec.statuses;
 const dmg=blowDamage(rec.hp,optionSum(list||[],'KNIGHT_SPECIAL_OTHER_DEATHBLOW'));if(!(dmg>0))return 0;
 rec.hp=Math.max(1,rec.hp-dmg);if(rec.profile)world.changed(rec);
 world.emit(rec.map,{type:'damage',sourceId,targetId:rec.id,amount:dmg,dead:false,blow:true,...(rec.instanceId?{instanceId:rec.instanceId}:{})});
 return dmg;
}
function blowDrain(world,p,target,source){
 const rec=target._record;if(!rec||fixedObject(rec)||isEventObject(rec)||isSiegeRenewObject(rec))return;
 const dmg=blowDamage(target.hp,p._skills?.statuses.value(target,'KNIGHT_SPECIAL_OTHER_DEATHBLOW'));if(!(dmg>0))return;
 target.hp=Math.max(1,(Number(target.hp)||0)-dmg);if(rec.profile)world.changed(rec);
 world.emit(p.map,{type:'damage',sourceId:source?.id||p.id,targetId:target.id,amount:dmg,dead:false,blow:true});
}
function skillEvent(world,p,type,event) {
 const actor=event.actor||event.target,source=event.source||event.killer;
 if(type==='damage'){
  const target=event.target?._record;
  // A monster hit by this player's skill / servant / DoT: engagement, call-team and plain-hit hostility (SharedWorld.monsterHit).
  // Skill results add their own aggroaccount.csv hostility through SkillEngine._aggro (src/game/hate.js); DoT ticks and
  // results without a skill are valued like plain hits (the class damage code); a servant's swing is valued by summons.js.
  if(target&&!target.profile&&!isSiegeRenewObject(target)){const plain=(event.dot||!event.skill)&&source?.kind!=='servant';monsterHit(world,target,p,mapFor(world,p),world.now(),{hate:plain?plainHitHate(event.amount,p.profile.classIndex,world.data.skillCommon?.aggro):0});}
  world.emit(p.map,{type:'damage',sourceId:source?.id||p.id,targetId:event.target?.id,amount:event.amount+(Number(event.shieldDamage)||0),shieldDamage:Number(event.shieldDamage)||0,dead:event.target?.hp<=0,skillId:event.skill?.index??event.status?.skillIndex,statusIndex:event.status?.statusIndex,miss:!!event.miss,crit:!!event.crit,guard:!!event.guard,block:!!event.block,dot:!!event.dot,...(event.immune?{immune:true}:{})});   // STEP12-LANE51: SkillEngine damage carries resolveAttack's block (src/game/combat.js); additive field, old clients ignore it
  if(event.amount>0&&!event.dot)p._skills?.statuses.onDamaged(event.target,event.amount);
  if(event.amount>0&&!event.miss&&!event.dot&&event.target)blowDrain(world,p,event.target,source);
  // Half Bagi fury: a landed skill hit on a monster fills the gauge (a plain attack does it in core.mjs)
  if(event.amount>0&&!event.miss&&!event.dot&&event.target?.kind==='monster'&&source===p._skills?.game.player&&!fixedObject(event.target._record))furyHit(world,p);
  if(event.amount>0&&!event.miss&&!event.dot&&event.target?.kind==='monster'&&source&&
    (source===p._skills?.game.player||source.kind==='servant')&&!['force','spell','reflect'].includes(event.attackKey))
    p._skills?.engine.spells.onAttack(source,event.target);
 }else if(type==='death'){
  const record=actor?._record,owner=source?._record?.profile?source._record:source?.owner?._record;
  if(record&&!record.profile){record.targetId=null;clearHate(record);record.called=false;record.respawnAt=fixedObject(record)?Infinity:world.now()+respawnDelayMs(record.respawnSec);if(owner)world.reward(owner,record)}
 }else if(type==='skill'){
  questSkill(world,p,Number(event.skill.index));
  // QUEUE: a queued skill starts from the tick, outside the cast command, so its cooldown is saved here.
  if(p._skills)saveCooldowns(p,p._skills.engine);
  const active=p._skills?.engine.active,castRequestId=active?.skill?.index===event.skill.index?active.opts?.castRequestId:undefined;
  world.emit(p.map,{type:'cast',actorId:p.id,skillId:event.skill.index,level:p.profile.skills?.[event.skill.index],targetId:event.target?.kind==='servant'?`summon:${p.id}:${event.target.id}`:event.target?.id,...(castRequestId?{castRequestId}:{}),
   point:p._skills?.engine.active?.point||null,cooldownMs:Math.round((p._skills?.engine.cooldownRemaining(event.skill.index)||0)*1000),
   at:world.now()});   // host time of the start: the client subtracts the delivery delay from cooldownMs (cooldown skew measured 35-100 ms)
 }else if(type==='heal')world.emit(p.map,{type:'heal',actorId:source?.id||p.id,targetId:actor?.id,amount:event.amount});
 else if(type==='status'){
  const record=actor?._record;
  // The caster's StatusSystem refreshes only its own player. A shared recipient
  // also needs the same stat/formula pipeline on application and removal.
  if(record?.profile&&record!==p)refresh(world,record,record._skills?.engine);
  world.emit(p.map,{type:'status',actorId:actor?.id,statusIndex:event.status?.statusIndex,key:event.status?.key,family:event.status?.family,on:event.on,reason:event.reason});
 }
 else if(type==='summon')world.emit(p.map,{type:'summon',actorId:p.id,servantIndex:event.servant?.servantIndex,on:event.on});
 world.changed(p);
 if(actor?._record?.profile&&actor._record!==p)world.changed(actor._record);
}
function syncSkillScene(p,sys){
 if(sys.map===p.map&&sys.instanceId===(p.instanceId||null)&&sys.channel===(p.channel??0))return;
 sys.channel=p.channel??0;sys.engine.cancel();sys.game.player.target=null;sys.game.controller.target=null;sys.engine.remotes.clear();sys.statuses.onMapChange();sys.summons.onMapChange();sys.map=p.map;sys.instanceId=p.instanceId||null;sys.summons.afterMapLoad();
}
export function ensureSkills(world,p) {
 // Buff Mode consumes every arena buff on exit, including item buffs acquired
 // there. A reconnect/server restart must not retain the saved arena grant.
 const scope=p.profile.partyPvpBuffScope;
 if(scope){
  const match=world.partyMatches?.get(scope.id);
  if(!match||p.instanceId!==scope.instanceId||!match.sides.some(s=>s.ids.includes(p.id))){
   p._skills?.statuses.remove(p._skills.game.player,()=>true,'silent');
   p.profile.buffs=[];delete p.profile.partyPvpBuffScope;world.changed(p);
  }
 }
 // Synchronize before accepting the first command after travel. Waiting until
 // the next tick cancels that newly accepted cast as if it belonged to the old map.
 if(p._skills){syncSkillScene(p,p._skills);return p._skills;}
 const data=dataFor(world,p),base=world.data.classDef(p.profile.classIndex);
 const cls={...base,skills:(data.classRec?.skills||[]).map(id=>data.skill(id)).filter(Boolean)};
 // This private proxy permits the original pure gameplay code to write the verified
 // server record. It is never exposed to requests or sent as a client authority bypass.
 const save=new Proxy({}, {
  get:(_,key)=>key==='authority'?undefined:key==='gm'?(p.gmAuthorized?p.profile.gm||{}:{}):Reflect.get(p.profile,key),
  set:(_,key,value)=>{p.profile[key]=value;return true;},
  ownKeys:()=>Reflect.ownKeys(p.profile),
  getOwnPropertyDescriptor:(_,key)=>Object.hasOwn(p.profile,key)?{configurable:true,enumerable:true,writable:true,value:p.profile[key]}:undefined,
 });
 const game={_world:world,_playerRecord:p,save,classDef:cls,data:{classes:[cls],formula:world.data.formula||{},expNeeded:()=>Infinity},
  time:world.now()/1000,worldRoot:new THREE.Group(),settings:{},camera:null,
  hud:{log:message=>{p._skillMessage=String(message)}},controller:{target:null},models:null,
  events:{emit:(type,event)=>skillEvent(world,p,type,event||{})}};
 game.player=actorFor(world,p,'player');
 game.shareTarget=(ctx,result,target)=>{
  if(!target||!engine._hostile(target)||!availableObject(world,p,target._record))return;
  return offerSharedTarget(world,p,target._record,result,ctx.skill);
 };
 game.skillTargetPoint=(target,source)=>target?.isBrick?objectHitPoint(mapFor(world,p),source,target):target;
 // QUEUE: a queued cast that could not start when the running skill ended is reported to its caster only.
 game._queuedSkillRefused=(skillId,castRequestId)=>world.emit(p.map,{type:'skillrefuse',actorId:p.id,skillId,...(castRequestId?{castRequestId}:{}),message:p._skillMessage||'Skill cannot start now.',recipients:[p.id]});
 // PVP-DUEL: the duel opponent is the only player this character's skills treat as an enemy (server/world/pvp.mjs).
 game.isPvpHostile=t=>!!t?._record&&isPvpTarget(world,p,t._record);
 game.combatHooks={beforeDamage:[(source,target,result)=>{if(source&&source.kind!=='monster'&&target?.kind==='player'&&attackPreferenceRefusal(world,source._record||source.owner?._record||p,target._record)){result.miss=true;result.amount=0;result.shieldDamage=0;}if(!result.miss&&source?.kind==='player'&&target?.kind==='player'&&source._record&&target._record&&isPvpTarget(world,source._record,target._record))pvpSkillAdjust(world,source._record,target._record,result);},(_source,target,result)=>{if(isEventObject(target))result.amount=eventObjectDamage(world,p,target._record,result.amount,result.kind||'melee');if(isSiegeRenewObject(target))result.amount=siegeRenewObjectDamage(world,p,target._record,result.amount,result.kind||'melee');},
  // MAP-CAPS: the map's level-difference ability caps (src/game/ability-cap.js): block 1 = a character's skill on a monster,
  // block 2 = a monster's hit on a character. Event objects keep their own resistances.
  (source,target,result)=>{if(result.miss||!source||!target||fixedObject(target))return;const toMonster=source.kind==='player'&&target.kind==='monster',toPlayer=source.kind==='monster'&&target.kind==='player';if(!toMonster&&!toPlayer)return;
   const c=applyAbilityCap(world.data.abilityCap?.(p.map),{attackerLevel:source.level,defenderLevel:target.level,attackerIsPlayer:toMonster,kind:result.kind==='magic'?'magic':'melee'},result.amount,()=>world.random());if(c.miss){result.miss=true;result.amount=0;result.crit=false;if(c.immune)result.immune=true;}else result.amount=c.amount;}]};
 game.mounts={isMounted:()=>p.mount?.phase==='on'};
 game.actors=()=>playersFor(world,p).concat(monstersFor(world,p),game.summons?.all()||[]);
 Object.defineProperty(game,'world',{get:()=>{const map=mapFor(world,p);return {info:{index:p.map},isWalkable:(x,z)=>map?.isWalkable(x,z),heightAt:()=>0}}});
 Object.defineProperty(game,'spawner',{get:()=>({monsters:monstersFor(world,p)})});
 const statuses=new StatusSystem(game,data,null),engine=new ServerSkillEngine(game,{data,fx:skillImpactEmitter(world,p),statuses});
 engine.messages=world.data.skillMessages||null;   // engine.msg(code) -> the player's text instead of "(code)" (see loadSkillPacks)
 const addStatus=statuses.add.bind(statuses);statuses.add=(actor,index,duration,opts={})=>{
  if(fixedObject(actor)&&Number(actor.brickDef.raw?.AntiStatusRate)>=100)return null;
  // Also protects delayed spells/aura ticks that no longer pass a cast command.
  if(actor?.kind==='player'&&opts.source?.kind==='player'&&Number(data.status(index)?.property)===1&&!npcBeneficiary(world,opts.source._record,actor._record))return null;
  return addStatus(actor,index,duration,opts);
 };
 const summons=new SummonSystem(engine);engine.summons=summons;game.skills=engine;game.summons=summons;game.statuses=statuses;
 summons.gauges=world.data.skillGauges||new Map();
 const resetCooldowns=engine.resetCooldowns.bind(engine);
 engine.resetCooldowns=index=>{resetCooldowns(index);saveCooldowns(p,engine);world.changed(p);};
 game.refreshPlayerStats=()=>refresh(world,p,engine);
 engine.equippedStyle=()=>world.data.itemDB&&world.data.equipmentStyle?world.data.equipmentStyle(p.profile):Number(p.profile.equipment?.weapon?.style??base.style??1);
 // Each player's buffs and each map's monster buffs tick exactly once, even when
 // several casters have touched the same target (solo StatusSystem tracks every ally).
 statuses.update=dt=>{
  statuses._tickActor(game.player,dt);
  // keyed on the tick's start time (lastTick, fixed for the whole tick), not the clock: world.now() moves on during one slow tick,
  // so the scene's monster statuses were ticked again for later players of the same tick (durations ran out several times faster
  // on a busy map). Only monsters that carry statuses are visited (_tickActor returns at once for the rest); stub worlds
  // without a tick fall back to the clock.
  const map=mapFor(world,p),stamp=world.lastTick??world.now();
  if(map&&map._skillStatusAt!==stamp){map._skillStatusAt=stamp;for(const m of map.monsters.values())if(m.statuses?.length&&availableObject(world,p,m))statuses._tickActor(actorFor(world,m,'monster'),dt)}
 };
 for(const row of world.data.skillSpells||[]){const n=key=>Number(row[key])||0;engine.spells.rows.set(n('INDEX'),{index:n('INDEX'),status:n('STATUSINDEX'),count:n('COUNT'),rate:n('RATE'),des:n('DES'),result:n('RESULTCODE'),icon:n('SPELLICON'),statusTime:n('STATUSTIME'),targetType:n('TARGETTYPE')})}
 p._skills={data,game,statuses,engine,summons,map:p.map,instanceId:p.instanceId||null,channel:p.channel??0,level:p.profile.level};
 statuses.reconcile(game.player);
 const trans=p.profile.transUp;
 const transRow=trans&&data.skill(Number(trans.skill))?.transform?.find(row=>Number(row.level)===Number(trans.level));
 p.transUpStage=transRow&&Number(trans.until)>world.now()?Number(transRow.transType)||1:0;
 p.transUpUntil=p.transUpStage?Number(trans.until)/1000:0;
 if(trans&&!p.transUpStage)p.profile.transUp=null;
 for(const [id,end]of Object.entries(p.profile.skillCooldowns||{})){
  const remaining=(Number(end)-world.now())/1000;
  if(remaining>0&&engine.skillDef(Number(id)))engine.cooldowns.set(Number(id),{start:game.time,end:game.time+remaining});
 }
 unlockSkills(world,p);return p._skills;
}
export function initializeStarterSkills(world,p){
 if(!world.data.skillPacks)return;
 const {game}=ensureSkills(world,p);
 if(seedStarterSlot(p.profile,game.classDef.skills))world.changed(p);
}
export function unlockSkills(world,p) {
 const sys=p._skills;if(!sys)return;
 const {engine}=sys,level=p.profile.level,grade=resolveAwakeningGrade(p.profile,world);
 const paidReset=new Set(Array.isArray(p.profile.normalSkillResetSuppressed)?p.profile.normalSkillResetSuppressed:[]);
 p.profile.skills ||= {};p.profile.hotbar ||= [];
 let changed=true,guard=0;
 while(changed&&guard++<24){changed=false;for(const skill of sys.game.classDef.skills){
  const first=skill.levels?.[0];if(skill.hidden||engine.learnedLevel(skill.index)>0||skill.tree?.window!=='skill'||!first||first.reqLevel>level||(Number(first.grade)||0)>grade)continue;
  if(Number(first.spCost)>0&&paidReset.has(skill.index))continue;
  if(first.availability&&first.availability!=='all'||(first.prereqs||[]).some(pr=>engine.learnedLevel(pr.skill)<Number(pr.level)))continue;
  engine.setLevel(skill.index,1,{silent:true});changed=true;
 }}
 for(const skill of sys.game.classDef.skills){
  const levels=skill.levels||[];
  if(skill.hidden||!engine.isPassive(skill)||skill.tree?.window!=='skill'||levels.length<2||levels.some(l=>Number(l.spCost)>0||(l.prereqs||[]).length)||Number(levels[1].reqLevel)!==Number(levels[0].reqLevel)+1)continue;
  const target=Math.min(engine.maxLevelFor(skill),levels.filter(l=>Number(l.reqLevel)<=level).length);
  if(target>engine.learnedLevel(skill.index))engine.setLevel(skill.index,target,{silent:true});
 }
 for(const skill of sys.game.classDef.skills){
  const L=skill.levels?.[0];
  if(skill.hidden||skill.tree?.window!=='meister'||!skill.meister?.autoLearn||engine.learnedLevel(skill.index)>0||!L||skill.tree.path!==engine.meisterPath()||meisterRank(p.profile)<meisterRequirement(skill)||Number(L.reqLevel)>level||(L.prereqs||[]).some(pr=>engine.learnedLevel(pr.skill)<Number(pr.level)))continue;
  engine.setLevel(skill.index,1,{silent:true});
 }
 refresh(world,p,engine);world.changed(p);
}
export function learnSkill(world,p,id,{book=false,def=null}={}) {
 const {engine}=ensureSkills(world,p);
 if(!Number.isInteger(id)||!engine.skillDef(id))refuse('Unknown skill for this character class.');
 const result=book?engine.learnFromBook(id,def):engine.learn(id,{silent:true});
 if(!result)refuse(p._skillMessage||'Skill prerequisites, level or points are not satisfied.');
 world.changed(p);return result;
}
export function itemSkillFacade(world,p,profile) {
 const isolated={...p,profile,_skills:null,_skillActor:null};
 // Transaction-local adapter: effects/dirty marks stay isolated until ItemUse
 // commits its validated inventory/profile transaction.
 const sandbox=Object.create(world);sandbox.changed=()=>{};sandbox.emit=()=>{};
 let refreshPending=false;
 return {get list(){const data=dataFor(sandbox,isolated);return (data.classRec?.skills||[]).map(id=>data.skill(id)).filter(Boolean);},
  refreshPassives(){refreshPending=true;},
  publish(){if(refreshPending){refreshPending=false;p._skills?.engine.refreshPassives();}},
  learnFromBook:(id,def)=>learnSkill(sandbox,isolated,Number(id),{book:true,def})};
}
export async function skillCommand(world,p,input) {
 if(input.type==='resurrection')return answerResurrection(world,p,input);
 if(input.type==='shareTarget')return answerSharedTarget(world,p,input,(offer,source,target)=>{
  const sys=ensureSkills(world,p),caster=ensureSkills(world,source);
  sys.game.time=world.now()/1000;
  const skill=caster.engine.skillDef(offer.skillId);
  if(!skill||!sys.data.status(offer.statusIndex))return null;
  sys.game.player.target=actorFor(world,target,target.profile?'player':'monster');
  return sys.statuses.add(sys.game.player,offer.statusIndex,offer.duration,{source:caster.game.player,skill});
 });
 const {engine,game,summons}=ensureSkills(world,p);game.time=world.now()/1000;
 if(input.type==='cast')noteForcedIntent(world,p,input.forced===true);   // FIELD-PK: Ctrl + skill arms the caster, a cast without it disarms (Force::State::PK; field-pk.mjs decides who may be hit)
 if(input.type==='meisterPath'||input.type==='meisterReinforce'){
  const next=structuredClone(p.profile);
  if(input.type==='meisterPath'){
   if(!['A','B'].includes(input.path)||!canSelectMeisterPath(next))refuse('Meister path requires level 170.');
   if(next.meister?.path)refuse('A Meister path is already selected.');
   const list=engine.list.filter(s=>s.tree?.window==='meister'&&s.tree.path===input.path);
   if(!list.length)refuse('This class has no selected Meister path.');
   next.meister={...(next.meister||{}),path:input.path,grade:Math.max(1,meisterRank(next))};next.skills ||= {};
   for(const s of list)if(s.meister?.autoLearn&&!next.skills[s.index]){
    const L=s.levels?.[0];if(L&&meisterRank(next)>=meisterRequirement(s)&&Number(L.reqLevel)<=Number(next.level)&&(Number(L.grade)||0)<=resolveAwakeningGrade(next,world)&&(L.prereqs||[]).every(pr=>(next.skills[pr.skill]||0)>=Number(pr.level)))next.skills[s.index]=1;
   }
  }else{
   const s=engine.skillDef(input.skillId),lv=engine.learnedLevel(input.skillId);
   if(!s||s.tree?.window!=='meister'||!next.meister?.path||(s.tree.path&&s.tree.path!==next.meister.path)||lv<1||lv>=engine.maxLevelFor(s))refuse('Meister reinforcement is unavailable.');
   const L=s.levels?.[lv],up=(s.upgrade||[]).find(row=>Number(row.level)===lv)||(s.upgrade||[])[lv-1];
   if(!up||!L||Number(L.reqLevel)>Number(next.level)||(Number(L.grade)||0)>resolveAwakeningGrade(next,world)||(L.prereqs||[]).some(pr=>engine.learnedLevel(pr.skill)<Number(pr.level)))refuse('Reinforcement level or prerequisites are not satisfied.');
   const inv=new AuthoritativeInventory(next,world.data.itemDB,{now:()=>world.now()}),book=inv.bag.list.find(e=>e.uid===input.uid);
   if(!book||Number(world.data.itemDB.def(book.itemIndex)?.use?.meisterSkill)!==s.index||book.expiresAt&&book.expiresAt<=world.now())refuse('A matching owned Meister book is required.');
   const price=Number(up.priceDil),rate=Number(up.ratePct);
   if(!Number.isFinite(price)||price<0||!Number.isFinite(rate)||rate<0||rate>100||inv.dil<price)refuse('Insufficient DIL or invalid reinforcement rule.');
   inv.addDil(-price);
   if((world.random?.()??Math.random())*100<rate){if(!inv.consumeEntry(book,1))refuse('Book could not be consumed.');next.skills[s.index]=lv+1;}
  }
  const before=p.profile;p.profile=next;
  try{await world.persist(p);}catch(error){p.profile=before;throw error;}
  refresh(world,p,engine);world.changed(p);return;
 }
 if(input.type==='statusCancel'){
  const key=String(input.key??''),s=key?(p.profile.buffs||[]).find(b=>b&&String(b.key)===key):null;
  if(!s)refuse('That status is not active.');
  const def=world.data.skillStatuses?.[s.statusIndex];
  if(s.debuff||s.harmful||(!s.item&&s.buff==null&&def&&Number(def.property)!==1))refuse('Harmful statuses cannot be cancelled.');
  if(s.premium!=null)refuse('This status cannot be cancelled.');
  ensureSkills(world,p).statuses.remove(game.player,b=>b===s,'cancel');
  world.changed(p);await world.persist(p);return;
 }
 if(input.type==='learn')return serializeLife(p,async()=>{
  const before=structuredClone(p.profile),revision=p.revision??0,transition=p.sceneTransition;
  const pointsBefore={skill:engine.points('skill'),attribute:engine.points('attribute')};
  const staged={...p,profile:structuredClone(before)},stagedWorld=Object.create(world),events=[];
  stagedWorld.changed=()=>{};stagedWorld.emit=()=>{};
  const learner=Object.create(engine);learner._passives=null;
  const save=new Proxy({}, {
   get:(_,key)=>key==='authority'?undefined:key==='gm'?(staged.gmAuthorized?staged.profile.gm||{}:{}):Reflect.get(staged.profile,key),
   set:(_,key,value)=>{staged.profile[key]=value;return true;},
   ownKeys:()=>Reflect.ownKeys(staged.profile),
   getOwnPropertyDescriptor:(_,key)=>Object.hasOwn(staged.profile,key)?{configurable:true,enumerable:true,writable:true,value:staged.profile[key]}:undefined,
  });
  const stagedGame={...game,save,events:{emit:(type,event)=>events.push([type,event])},
   refreshPlayerStats:()=>refresh(stagedWorld,staged,learner)};
  learner.game=stagedGame;staged._skills={...p._skills,engine:learner,game:stagedGame};
  learnSkill(stagedWorld,staged,input.skillId);
  const pointDeltas={skill:learner.points('skill')-pointsBefore.skill,attribute:learner.points('attribute')-pointsBefore.attribute};
  p.sceneTransition=true;
  try{
   let npcCheckpoint;
   if(p.npcPlayer===true&&world.npcPeriodicAccount?.(p.account)===true&&typeof world.persistNpcSkillCheckpoint==='function')npcCheckpoint=await world.persistNpcSkillCheckpoint(p,staged);
   else await world.persist(staged);
   const intervening=(p.revision??0)-revision;
   // Publish only the paid skill delta, retaining other skills granted while
   // storage was pending. Apply costs to CURRENT points, preserving earned SP.
   publishProfileChanges(p.profile,{skills:before.skills||{}},{skills:staged.profile.skills||{}});
   for(const type of ['skill','attribute'])if(pointDeltas[type])p.profile[type==='attribute'?'attrPoints':'skillPoints']=engine.points(type)+pointDeltas[type];
   // Publication happens before invalidation/derivation: a cache warmed during
   // the await cannot omit the new passive or overwrite the current level/buffs.
   engine.refreshPassives();
   for(const [type,event]of events)game.events?.emit(type,event);
   world.changed(p);
   const queuedSuccessor=npcCheckpoint?.hasQueuedSuccessor()===true;
   p.dirty=!!staged.dirty||intervening!==0||queuedSuccessor;p.saveError=staged.saveError;
   if(intervening!==0||queuedSuccessor)await persistInterveningProgress(world,[p]);
  }finally{p.sceneTransition=transition;}
 });
 if(input.type==='quickslots'){
  const layout=quickslotLayout(world,p,engine,input.layout);
  p.profile.quickslot=layout;p.profile.hotbar=layout.sets[layout.rowSet[0]];
  p.profile.starterSkillSeeded=true;delete p.profile.starterSkillPending;
  world.changed(p);await world.persist(p);return;
 }
 if(input.type==='hotbar'){
  const set=input.set??0,slot=input.slot,entry=quickslotEntry(world,p,engine,input.entry);
  if(!Number.isInteger(set)||set<0||set>2||!Number.isInteger(slot)||slot<0||slot>11)refuse('Unknown quick slot.');
  if(p.profile.quickslot?.sets){p.profile.quickslot.sets[set] ||= [];p.profile.quickslot.sets[set][slot]=entry;if(set===(p.profile.quickslot.rowSet?.[0]??0))p.profile.hotbar=p.profile.quickslot.sets[set]}
  else {if(set!==0)refuse('This quick slot set is unavailable.');p.profile.hotbar ||= [];p.profile.hotbar[slot]=entry}
  p.profile.starterSkillSeeded=true;delete p.profile.starterSkillPending;
  world.changed(p);await world.persist(p);return;
 }
 if(input.type==='summonOrder'||input.type==='summonGreat'){
  const sv=summons.servantOf(game.player),map=mapFor(world,p);
  if(!sv||p.dead||p.hp<=0)refuse('Summon control is unavailable.');
  if(input.type==='summonOrder'&&!['assist','attack','free','call','stop','destroy'].includes(input.order))refuse('Summon order is unavailable.');
  const currentEnemy=a=>a?._record&&map?.monsters.get(a.id)===a._record&&availableObject(world,p,a._record)&&summons._enemyOk(a);
  if(input.targetId!=null){
   if(input.type==='summonOrder'&&input.order!=='attack')refuse('This summon order does not take a target.');
   const record=map?.monsters.get(input.targetId),target=record&&actorFor(world,record,'monster');
   if(!currentEnemy(target))refuse('Summon target is outside the shared map or unavailable.');
   game.player.target=target;
  }else if(!currentEnemy(game.player.target))game.player.target=null;
  if(!currentEnemy(sv.target))sv.target=null;
  const accepted=input.type==='summonGreat'?summons.useGreat():summons.command(input.order);
  if(!accepted)refuse(p._skillMessage||'Summon control is unavailable.');
  world.changed(p);return;
 }
 if(input.type!=='cast')return;
 if(!Number.isInteger(input.skillId)||!engine.skillDef(input.skillId))refuse('Unknown skill for this character class.');
 const npcRequest=p.profile?.authority==='server'&&p.profile.npcPlayer===true?engine._npcQueueRequest:null;
 const boundRequest=npcRequest&&npcRequest.index===input.skillId&&npcRequest.targetId===input.targetId?npcRequest:null;
 if(boundRequest&&boundRequest.validate()!==true)refuse('Queued combat intent is no longer current.');
 // QUEUE: a press while a skill is running is queued below instead of being refused as "busy". The original engine
 // ignores the SAME skill pressed again; here it queues too, because its cooldown is checked against the end of the running
 // animation below (Energy zap: cooldown 1000 ms, animation 1110 ms - holding the key repeats it at the animation rate).
 const running=!!engine.active;
 const skill=engine.skillDef(input.skillId),mask=Number(skill.targetMask)||0;
 const selfOnly=(mask&16)!==0 && (mask&(2|4|8|32|64))===0;
 let target=selfOnly?game.player:null,point=null,targetPlayer=false;const map=mapFor(world,p);
 if(!selfOnly&&input.targetId!=null){
  const monster=map?.monsters.get(input.targetId),player=[...world.players.values()].find(q=>q.id===input.targetId&&!q.leaving&&!q.customMapPending&&sameScene(q,p));
  if(!monster&&!player)refuse('Target is outside the shared map.');
  if(!availableObject(world,p,monster))refuse('This event object is not available for combat.');target=actorFor(world,monster||player,monster?'monster':'player');targetPlayer=!monster;
  if(map.collision?.lineOfSight&&!(target.isBrick?objectHitPoint(map,p,target):map.collision.lineOfSight(p.x,p.z,target.x,target.z)))refuse('An obstacle blocks this skill.');
 }
 if(input.x!=null||input.z!=null){if(typeof input.x!=='number'||typeof input.z!=='number'||!Number.isFinite(input.x)||!Number.isFinite(input.z)||!map.isWalkable(input.x,input.z))refuse('Skill point is outside the walkable map.');point={x:input.x,z:input.z}}
 if(point&&map.collision?.lineOfSight&&!map.collision.lineOfSight(p.x,p.z,point.x,point.z))refuse('An obstacle blocks this skill point.');
 // ENGINE-DEFAULT (configurable): network range tolerance (min 1.5, + target radius default 0.5, + 0.3); Global Distance is .dat only.
 const range=Math.max(1.5,Number(skill.range)||3)+(target?.radius||0.5)+0.3;
 // a player target out of reach: the original PvP line 1008:9 (the data has no skill-specific range string)
  const contact=target?.isBrick?objectHitPoint(map,p,target):target;
  if(target&&(!contact||Math.hypot(p.x-contact.x,p.z-contact.z)>range))refuse(targetPlayer?PVP_TEXT.reach:'Target is outside skill range.');
 // A cooldown that ends before the running skill does is not a refusal: the queued cast is checked again when it starts.
 const check=engine.usability(input.skillId);if(!check.ok&&!(running&&check.reason==='cooldown'&&engine.cooldownRemaining(input.skillId)<=activeRemaining(engine)))refuse(usabilityRefusal(engine,check.reason));
 // NeedType and implicit engine selection read player.target. Bind the already
 // validated intent so neither can borrow a stale actor from a previous cast/map.
 if(!running&&!selfOnly&&(mask&(2|4|8|32)))game.player.target=target;
 game.controller.target=target;p.path=[];p._skillMessage=null;
 const queuedBefore=engine.queued;
 const castRequestId=typeof input.castRequestId==='string'&&/^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}:[1-9][0-9]{0,15}$/i.test(input.castRequestId)?input.castRequestId:undefined;
 if(!engine.useSkill(input.skillId,{target,point,...(castRequestId?{castRequestId}:{})})){
  // the engine parked it in its single queue slot (newest press wins, as in the original): tell the caster, nothing else changes
  if(running&&engine.queued&&engine.queued!==queuedBefore&&engine.queued.index===input.skillId){
   if(!selfOnly&&(target||point)){const queued=engine.queued;queued.commandStartGuard=queuedSkillCommandGuard(world,p,engine,queued,map,target,point);}
   if(boundRequest){const queued=engine.queued;queued.npcStartGuard=()=>boundRequest.startGuard(queued);boundRequest.accepted();}
   world.emit(p.map,{type:'skillqueued',actorId:p.id,skillId:input.skillId,...(castRequestId?{castRequestId}:{}),recipients:[p.id]});
   // the press that held the slot is gone: say so instead of letting it vanish
   if(queuedBefore&&queuedBefore.index!==input.skillId)world.emit(p.map,{type:'skillrefuse',actorId:p.id,skillId:queuedBefore.index,...(queuedBefore.opts?.castRequestId?{castRequestId:queuedBefore.opts.castRequestId}:{}),message:'Replaced by a newer skill press.',recipients:[p.id]});
   p.lastCombat=world.now();world.changed(p);return;}
  refuse(p._skillMessage||'Skill cannot start now.');
 }
 saveCooldowns(p,engine);
 p.lastCombat=world.now();world.changed(p);
 // SAVE: the reply no longer waits for the account-store write. Every cast used to await a full rewrite + fsync of the
 // whole account store (measured 44 ms for 300 characters, one queue shared by all players) while holding this account's command
 // lock, so the player's next commands (the next cast, movement) stood behind everybody's saves. persistLatest starts the same
 // write now, coalesces casts that arrive while one waits, and on failure marks the profile dirty so the 5 s save retries it.
 void (world.persistLatest||world.persist).call(world,p).catch(()=>{});
}
export function tickSkills(world,p,dt) {
 if(!world.data.skillPacks)return;
 const sys=ensureSkills(world,p);sys.game.time=world.now()/1000;
 tickSharedTarget(world,p);
 syncSkillScene(p,sys);
 const rankSignature=JSON.stringify([p.profile.grade,p.profile.transGrade,p.profile.meister]);
 if(sys.level!==p.profile.level||sys.rankSignature!==rankSignature){sys.level=p.profile.level;sys.rankSignature=rankSignature;unlockSkills(world,p)}
 const before=`${p.hp}:${p.mp}:${p.profile.buffs?.length||0}`;
 sys.engine.update(dt);sys.summons.update(dt);
 if(before!==`${p.hp}:${p.mp}:${p.profile.buffs?.length||0}`)world.changed(p); // PING-FLAT / ROUND2: only dirty when hp/mp/buff-count changes � prior `||buffs.length` SQL-dirtied every tick while buffed
}
export function skillControls(p, nowMs){
 // AUTOATTACK-SKILL-PRIORITY / HIT-MOVE-INTERRUPT: Global Skill state owns the body until start + summed combo
 // TimeTick (engine.holdsBody / attackHoldUntil). Callers pass host time in ms so a mid-tick check sees the same clock
 // tickSkills writes into game.time. casting stays NO_CANCEL/cast-only (busy); skillMotion covers every phase + hold.
 const sys=p._skills;if(!sys)return{};
 if(Number.isFinite(nowMs))sys.game.time=nowMs/1000;
 const engine=sys.engine;
 return{...sys.statuses.flags(sys.game.player),casting:!!engine.busy,skillMotion:!!engine.holdsBody};
}
/** HIT-MOVE-INTERRUPT: cut the player's running skill to Idle and clear that cast's cooldown keys (engine.interruptByHit). */
export function interruptSkillByHit(p){
 const eng=p._skills?.engine;if(!eng?.active)return null;return eng.interruptByHit();
}
// Same defensive option rules as skills/hooks.js, without its browser prototype patches.
export function incomingSkillDamage(world,p,monster,amount,kind='melee'){
 noteMonsterHit(world,p,monster);   // EVENT-MODES: Type 7 mission titles (server/world/titles.mjs)
 if(!world.data.skillPacks)return amount;
 const sys=ensureSkills(world,p),defender=sys.game.player,attacker=actorFor(world,monster,'monster');
 sys.engine.spells.onHurt(defender,attacker);
 const list=sys.statuses.listOf(defender,false)||[],all=list.concat(sys.engine.passiveEntries());
 const v=code=>{const item=Number(p.stats?.itemOptions?.[code]);return optionSum(all,code)+(Number.isFinite(item)?item:0)};
 // Every native row carrying STATUS_EX2_ALL_TOLERANCE (132 rows: Protection,
 // Upgrade, Qune Crystal, Dekaron's Blessing, Ancient Totem, Triforce) describes
 // invincibility / all-damage resistance; the value 1 is a flag, not 1%.
 if(v('STATUS_EX2_ALL_TOLERANCE')>0)return 0;
 let value=amount;
 // Global share/pc/statmaxvalue.csv caps the item part and the skill/status part separately: rows 176/177 melee/ranged
 // resist 75/75, row 63 damage reduction 75 (equipment) / 90 (skills) (scan-fix 2026-10-29; was a single unlabelled 90).
 const capped=(code,eMax,sMax)=>{const item=Number(p.stats?.itemOptions?.[code]);return Math.max(0,Math.min(eMax,Number.isFinite(item)?item:0))+Math.max(0,Math.min(sMax,optionSum(all,code)))};
 if(kind==='melee')value*=Math.max(0,1-capped('RESIST_DISTANCE_MELEEDAMAGE',75,75)/100);
 if(kind==='range')value*=Math.max(0,1-capped('RESIST_DISTANCE_RANGEDAMAGE',75,75)/100);
 // ENGINE-DEFAULT (configurable): caps of 90 on KNIGHT_SPECIAL_MONSTER_TOLERANCE, DAMAGE_OWNERSHIP and DAMAGE_TRANSITION_MP_MUL;
 // statmaxvalue.csv has no row for these options (Global sets no cap); 90 keeps a hit from being fully absorbed.
 value*=1-Math.min(90,v('KNIGHT_SPECIAL_MONSTER_TOLERANCE'))/100;
 value*=Math.max(0,1-capped('DAMAGERATE_DAMAGEHP_MUL',75,90)/100);
 const share=v('DAMAGE_OWNERSHIP'),servant=sys.summons.servantOf(defender);
 if(share>0&&servant&&isAlive(servant)){const part=Math.round(value*Math.min(90,share)/100);value-=part;servant.hp=Math.max(1,servant.hp-part);}
 // Divide Pain / Force: SHARE_DAMAGE_PARTY protects its holder and moves sharePct of the hit to the caster (damage-share.mjs).
 // It is not the summon share above; no summon ever receives it.
 if(value>0)value=divideShare(world,p,{amount:value,attacker:monster}).kept;
 const mp=Math.min(90,v('DAMAGE_TRANSITION_MP_MUL'));
 if(mp>0&&p.mp>0){const part=Math.min(p.mp,Math.round(value*mp/100));p.mp-=part;value-=part;}
 // Native tooltip 23:37: this is the PvP shield. Monster damage reaches HP;
 // player-versus-player hits retain the shield-first path in pvp.mjs.
 const reflected=value*v('REFLECT_DAMAGEHP_MUL')/100+v('REFLECT_DAMAGEHP_ADD');
 if(reflected>=1&&isAlive(attacker))queueMicrotask(()=>{if(isAlive(attacker))applyDamage(sys.game,defender,attacker,{amount:Math.round(reflected),miss:false,kind:'magic',reflected:true,attackKey:'reflect'})});
 if(value>0)sys.statuses.onDamaged(defender,value);
 return Math.max(0,Math.round(value));
}
export function summonSnapshot(world,map,instanceId=null,channel=0){
 // lane-perf: the same list for every viewer of a scene within one broadcast (core.mjs broadcastMemo)
 if(world?._broadcastMemo&&world.broadcastMemo)return world.broadcastMemo(`summons:${map}:${instanceId}:${channel}`,()=>computeSummonSnapshot(world,map,instanceId,channel));
 return computeSummonSnapshot(world,map,instanceId,channel);
}
function computeSummonSnapshot(world,map,instanceId=null,channel=0){
 return [...world.players.values()].filter(p=>!p.leaving&&sameScene(p,{map,instanceId,channel})).flatMap(p=>(p._skills?.summons.all()||[]).filter(a=>!a.disposed).map(a=>({
  id:`summon:${p.id}:${a.id}`,ownerId:p.id,servantIndex:a.servantIndex,name:a.name,map:p.map,instanceId:p.instanceId||null,channel:p.channel??0,x:a.x,z:a.z,yaw:a._yawGoal||0,hp:a.hp,maxHp:a.maxHp,dead:a.dead,level:a.level,state:a.state,
  order:p._skills.summons.mode,charge:p._skills.summons.greatCharge(a),targetId:a.target?._record?.id||null
 })));
}
// Public cosmetics contain no options, source account, resources or learned skills.
export function skillStatusVisuals(world,record) {
 const list=record.profile?.buffs||record.statuses||[];
 return list.filter(s=>{
  if(!(Number(s.remaining)>0))return false;
  if(s.spell)return !!world.data.skillCommon?.modelEffects?.spell?.[s.spellIcon];
  const def=world.data.skillStatuses?.[s.statusIndex]||world.data.skillCommon?.statuses?.[s.statusIndex];
  return Number(def?.sendToOthers)===1;
 }).map(s=>({key:s.key,family:s.family,statusIndex:s.statusIndex,spell:s.spell,spellIcon:s.spellIcon,at:s.at,remaining:s.remaining}));
}
export function skillTransformVisual(world,p) {
 const state=p.profile?.transUp;
 if(!state||!(Number(state.until)>world.now())||!p.transUpStage)return null;
 const skill=world.data.skillPacks?.[p.profile.classIndex]?.skills?.[state.skill];
 if(!skill?.transform?.some(row=>Number(row.level)===Number(state.level)))return null;
 return {skill:state.skill,level:state.level,stage:p.transUpStage,until:state.until};
}
export function disposeSkills(p){p._skills?.engine.clear();p._skills?.summons.clear?.();p._skills=null}
export function executeSkillGM(world,p,id,args=[]) {
 if(!p.gmAuthorized)refuse('GM skill commands require server authorization.');
 const {engine,statuses,game}=ensureSkills(world,p);
 if(id==='skill'){const index=Number(args[0]),level=Number(args[1]??1);if(!engine.skillDef(index)||!Number.isInteger(level))refuse('Unknown skill or level.');engine.setLevel(index,level,{silent:true})}
 else if(id==='allskills'){for(const skill of game.classDef.skills)engine.setLevel(skill.index,engine.maxLevelFor(skill),{silent:true})}
 else if(id==='skillreset'){engine.resetPoints(args[0]==='attribute'?'attribute':'skill')}
 else if(id==='cooldowns'){engine.resetCooldowns();p.profile.skillCooldowns={}}
 else if(id==='buff'){const index=Number(args[0]),ms=Number(args[1]??60000);if(!sysFinite(ms)||ms<=0||ms>86400000||!statuses.add(game.player,index,ms,{source:game.player}))refuse('Unknown status or duration.')}
 else return false;
 world.changed(p);return true;
}
const sysFinite=Number.isFinite;

/** Trusted server event status grant. Caller owns authorization and durable profile staging. */
export function grantTimedStatus(world,p,index,ms){
 if(!Number.isInteger(index)||!Number.isFinite(ms)||ms<=0||ms>86400000)refuse('Unknown status or duration.');
 const {statuses,game}=ensureSkills(world,p);
 if(!statuses.add(game.player,index,ms,{source:game.player}))refuse('Unknown status or duration.');
 world.changed(p);return true;
}
