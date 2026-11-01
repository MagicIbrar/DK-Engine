// ENGINE-CHOSEN authored identities and behavioral pacing, not native balance rules.
export {npcUsername} from './npc-usernames.mjs';
import {archetypesEnabled,npcArchetypeThinkMs} from './npc-archetypes.mjs';
const ARCHETYPE_PACING=archetypesEnabled();
export function npcWantsParty(p){return !p.profile.npcTraits||p.profile.npcTraits.social==='social';}
// Existing saved bots keep their personality, while their effective combat
// experience follows the level they have actually earned. This is a decision
// policy only; native skill ranks, damage and cooldowns remain authoritative.
export function npcCompetenceTier(p){
 const raw=p?.profile?.npcTraits?.pvpSkill;
 const tier=['novice','regular','expert','elite'].includes(raw)?raw:'regular';
 const level=Number(p?.profile?.level)||1;
 if(level<40&&['expert','elite'].includes(tier))return 'regular';
 if(level>=150&&['novice','regular'].includes(tier))return 'expert';
 if(level>=100&&tier==='novice')return 'regular';
 return tier;
}
// Combat polling is independent of native skill animation/cooldown and the
// tier's skillReady cadence. Only a real cast or a recent reachable fight
// requests faster decisions; ordinary idle/follow pacing remains unchanged.
export function npcDecisionDelay(p,b,policy,now=0){
 // ENGINE-CHOSEN close-follow polling matches the ordinary 150ms movement
 // command gate. This changes responsiveness, never native class run speed.
 if(b.closeFollow&&b.follow&&b.mode==='follow')return Math.min(150,policy.thinkMs);
 const engaged=!!p._skills?.engine?.casting||!!p._skills?.engine?.active||Number(b.combatDecisionUntil)>Number(now);
 if(engaged){const tier=npcCompetenceTier(p),poll={novice:350,regular:250,expert:150,elite:100}[tier];return Math.min(policy.thinkMs,poll);}
 if(b.follow&&b.mode!=='wait')return Math.min(250,policy.thinkMs);
 // Idle/strategic cadence only: a per-archetype lognormal reaction/think interval
 // (deterministic per bot and draw), scaled by the configured base thinkMs so
 // fixtures that shorten thinkMs keep their proportion. Combat polling above and
 // follow cadence are unchanged. DEKARON_NPC_ARCHETYPES=0 restores the legacy rule.
 if(ARCHETYPE_PACING&&p.profile){const ms=npcArchetypeThinkMs(p.profile,b.thinkDraw=(b.thinkDraw||0)+1,{active:!!b.questId||['farm','quest','dungeon','event'].includes(b.taskGoal?.kind)});if(ms!=null)return Math.max(1,Math.round(ms*policy.thinkMs/650));}
 return policy.thinkMs+((p.profile.npcSeed?.slot||0)%4)*90;
}
export function npcCombatSkillReady(b,now){return now>=(b.skillReady||0);}
export function npcSkillPace(b,now,random){b.skillReady=now+1800+Math.floor(random()*1400);}
export function npcFollowPoint(p,leader,b,distance=2.4){
 const slot=p.profile.npcSeed?.slot||0,angle=(slot%7)*Math.PI*2/7;
 return {x:leader.x+Math.cos(angle)*distance,z:leader.z+Math.sin(angle)*distance};
}
