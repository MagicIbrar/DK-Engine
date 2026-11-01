import {ensureSkills,activeRemaining} from './skills.mjs';
import {npcLearnedSkills,npcSupport} from './npc-tactics.mjs';
import {npcCompanionSupport} from './npc-companions.mjs';
import {mapFor,sameScene} from './scene.mjs';
import {isPvpTarget} from './pvp.mjs';
import {pkRefusal} from './field-pk.mjs';
import {nativeStatusFamily} from '../../src/systems/skills/statuses.js';
import {skillPhases} from '../../src/systems/skills/engine.js';
import {npcRepertoireOrder} from './npc-combat-repertoire.mjs';
import {npcCompetenceTier} from './npc-personality.mjs';
import {npcCombatIntelEnabled,npcCombatSkillTier,npcCombatReactionMs,npcIntelOrderSkills,npcCombatRole,npcRefusalBackoffMs} from './npc-combat-intel.mjs';

// ENGINE-CHOSEN behavioral policy and inferred effect sequences, not certified
// Global combos or balance changes. Every action retains native validation.
export const NPC_COMBAT_TIERS=Object.freeze(['novice','regular','expert','elite']);
export const NPC_COMBAT_POLICY=Object.freeze({novice:{decisionMs:1800,preparations:2},regular:{decisionMs:900,preparations:2},expert:{decisionMs:450,preparations:3},elite:{decisionMs:300,preparations:3},preparationMs:12000});
export const NPC_COMBAT_ATTEMPTS=2;
const tier=npcCombatSkillTier; // = npcCompetenceTier unless profile.npcCombat.skill is supplied
const own=p=>p?.profile?.authority==='server'&&p.profile.npcPlayer===true&&!p.dead&&!p.leaving;
const results=row=>(row.level?.steps||row.skill.steps||[]).map(step=>step.result).filter(Boolean);
const damaging=row=>results(row).some(r=>['damage','remote','projectile','servant_explode'].includes(r.family));
function validTarget(world,p,target,isPlayer,forced=true){
 if(!target||target.dead||target.leaving||!sameScene(p,target))return false;
 if(isPlayer)return world.players.get(target.account)===target&&(isPvpTarget(world,p,target)||forced&&pkRefusal(world,p,target)===null);
 return mapFor(world,p)?.monsters.get(target.id)===target&&!target.isBrick&&!target.eventObject;
}
export function npcCombatCadence(p,b,now){return npcCombatReactionMs(p,b)??NPC_COMBAT_POLICY[tier(p)].decisionMs;}
export async function npcCombatPreparation(world,p,b,act,{target,isPlayer=false}={}){
 if(!own(p)||!validTarget(world,p,target,isPlayer))return false;
 const engine=ensureSkills(world,p).engine;
 if(engine.active||engine.casting)return true;
 const now=world.now();let state=b.combatPreparation;
 if(!state||state.target!==target.id||now-state.at>30000)state=b.combatPreparation={target:target.id,at:now,used:0,done:false};
 if(state.done||state.used>=NPC_COMBAT_POLICY[tier(p)].preparations||now-state.at>=NPC_COMBAT_POLICY.preparationMs){state.done=true;return false;}
 if(await npcSupport(world,p,act,{buff:true})||await npcCompanionSupport(world,p,act,{prepare:true,target})){state.used++;return true;}
 state.done=true;return false;
}
function harmful(world,row){return results(row).filter(r=>Number(r.statusIndex)>0&&Number(world.data.skillStatuses?.[r.statusIndex]?.property)===0&&Number(r.durationMs)>0);}
function missing(world,target,row,effects){
 const statuses=target.profile?.buffs||target.statuses||[],rank=row.engine.skillLevel(row.skill.index);
 return effects.some(effect=>!statuses.some(s=>{
  if(!(Number(s.remaining)>2))return false;
  if(Number(s.statusIndex)===Number(effect.statusIndex))return true;
  // ENGINE-CHOSEN avoid redundant pure-debuff setup. The native engine merges
  // one skill's icon across ranks; retain an equal/higher known application.
  // No cross-skill equivalence or universal option-value strength is inferred.
  const candidate=world.data.skillStatuses?.[effect.statusIndex],active=world.data.skillStatuses?.[s.statusIndex];
  return Number(s.skillIndex)===Number(row.skill.index)&&Number(s.level)>=rank&&candidate&&active&&Number(candidate.maxStack)===0&&Number(active.maxStack)===0&&Number(candidate.iconIndex)>0&&nativeStatusFamily(candidate,row.skill)===nativeStatusFamily(active,row.skill);
 }));
}
function needReady(engine,skill,target,at=null){
 // Read the native NeedType predicate against this target without changing the
 // actor's target or history. This includes native timed follow-up windows.
 const context=Object.create(engine),game=Object.create(engine.game);
 if(at!=null)game.time=at;
 game.player=new Proxy(engine.game.player,{get:(p,key)=>key==='target'?(target._skillActor||target):Reflect.get(p,key)});context.game=game;
 return context._needType(skill)===true;
}

// Read future cooldown eligibility without advancing the real engine clock or
// bypassing present weapon/resources/control checks. Authority rechecks at start.
function usableAt(engine,id,at){
 if(at==null)return engine.usability(id).ok;
 const context=Object.create(engine),game=Object.create(engine.game);game.time=at;context.game=game;
 return context.usability(id).ok;
}

function retryMatches(state,p,target){return state?.targetId===target.id&&state.map===p.map&&state.instanceId===(p.instanceId||null)&&state.channel===(p.channel||0);}
export function npcCombatAttemptReady(world,p,b,target){return !retryMatches(b.combatRefusals,p,target)||world.now()>=(b.combatRefusals.rateUntil||0);}
export function npcCombatRefusal(world,p,b,target,skillId,error){
 const now=world.now();let state=b.combatRefusals;
 if(!retryMatches(state,p,target))state=b.combatRefusals={targetId:target.id,map:p.map,instanceId:p.instanceId||null,channel:p.channel||0,rateUntil:0,refused:{}};
 if(error?.status===429){const rateAt=Number(p.rateAt);state.rateUntil=Math.max(now+100,(Number.isFinite(rateAt)?rateAt:now)+1000);return true;}
 // LANE2: repeated refusals of one skill back off exponentially (250 ms .. 4 s) instead of retrying every 250 ms;
 // an out-of-range refusal asks fight() to approach through ordinary navigation.
 const intel=npcCombatIntelEnabled(world);
 state.refused[skillId]=now+(intel?npcRefusalBackoffMs(state,skillId):250);
 if(intel&&/outside skill range|out of reach|too far/i.test(String(error?.message)))b.combatApproach={targetId:target.id,reach:null,at:now};
 for(const [id,until]of Object.entries(state.refused))if(until<=now)delete state.refused[id];
 while(Object.keys(state.refused).length>32)delete state.refused[Object.keys(state.refused)[0]];
 return false;
}
function targetReady(world,p,engine,skill,target,{isPlayer,forced}){
 const actor=target._skillActor;if(!actor)return true; // Original host creates and validates an unknown wrapper.
 const context=Object.create(engine),game=Object.create(engine.game);context.game=game;
 // A forced request arms ordinary field hostility at dispatch. Predict only
 // this already validated target; no marker, native state or action is changed.
 if(isPlayer&&forced&&pkRefusal(world,p,target)===null)game.isPvpHostile=a=>a===actor||!!engine.game.isPvpHostile?.(a);
 return !context._pickTarget(skill,{target:actor,point:{x:target.x,z:target.z}}).error;
}

export function npcCombatSkills(world,p,b,target,{isPlayer=false,forced=false,queueNext=false}={}){
 if(!own(p)||!validTarget(world,p,target,isPlayer,forced))return [];
 const sys=ensureSkills(world,p),engine=sys.engine;if(!npcCombatAttemptReady(world,p,b,target)||(engine.active||engine.casting)&&(!queueNext||engine.queued))return [];
 if(queueNext&&(!engine.active||engine.queued))return [];
 sys.game.time=world.now()/1000;
 const dispatchAt=queueNext?sys.game.time+activeRemaining(engine):null;
 const ability=tier(p),lowMana=p.mp<Number(p.stats.maxMp||1)*.35;
 const known=npcLearnedSkills(world,p);
 const scored=known.filter(row=>{
  const mask=Number(row.skill.targetMask)||0;
  if(queueNext&&(row.skill.index===engine.active.skill.index||!(mask&(4|8))))return false;
  if(mask&(2|32|64)||!usableAt(engine,row.skill.index,dispatchAt)||!needReady(engine,row.skill,target)||queueNext&&!needReady(engine,row.skill,target,dispatchAt)||!targetReady(world,p,engine,row.skill,target,{isPlayer,forced}))return false;
  if(retryMatches(b.combatRefusals,p,target)&&Number(b.combatRefusals.refused[row.skill.index])>world.now())return false;
  if(damaging(row))return true;
  return ability!=='novice'&&!!(mask&4)&&harmful(world,row).length>0&&missing(world,target,row,harmful(world,row));
 }).map(row=>{
  const effects=harmful(world,row),setup=ability!=='novice'&&!lowMana&&effects.length&&missing(world,target,row,effects);
  // Prioritize an eligible native timed follow-up, then missing enemy effects.
  // Resource conservation and learning tier alter choices, never native damage.
  const follow=[101,104].includes(Number(row.skill.needType)),cost=Number(row.level?.mp??row.skill.mpCost)||0;
  return {row,group:follow?3:setup?2:damaging(row)?1:0,cost,level:Number(row.level?.reqLevel)||0};
 });
 // Only native-authored, actually learned timed follow-ups establish an
 // opener. Its full native animation must fit the authored follow-up window;
 // the follow-up still passes _needType and every normal cast gate later.
 const openings=new Set();
 if((ability==='expert'||ability==='elite')&&!lowMana)for(const row of known){
  if(Number(row.skill.targetMask)&(2|32|64)||!damaging(row)&&!harmful(world,row).length||![101,104].includes(Number(row.skill.needType))||!engine.usability(row.skill.index).ok||!targetReady(world,p,engine,row.skill,target,{isPlayer,forced}))continue;
  const [id,window]=(row.skill.needVars||[]).map(Number),opener=scored.find(s=>Number(s.row.skill.index)===id);
  if(opener&&Number(window)>0&&skillPhases(opener.row.skill,opener.row.level).reduce((sum,phase)=>sum+phase.durationMs,0)<window)openings.add(opener.row.skill.index);
 }
 const ordered=npcRepertoireOrder(scored,{ability,lowMana,engine,now:world.now(),openings}).map(s=>s.row);
 if(!npcCombatIntelEnabled(world))return ordered;
 return npcIntelOrderSkills(world,p,b,target,ordered,{map:mapFor(world,p),isPlayer,role:npcCombatRole(world,p,known)});
}
