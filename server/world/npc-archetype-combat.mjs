// INTEGRATION glue (ENGINE-CHOSEN): archetype -> lane-2 combat parameters.
// Lane 2 reads {skill, reactionMs, risk, potionHp, potionMp, retreatHp, role} from
// p.profile.npcCombat / brain.combatParams; this supplies archetype-derived DEFAULTS
// underneath those (explicit values always win). It only feeds the lane-2 intel
// decisions (potion/retreat/AoE-readiness lines from risk, healer re-check cadence),
// so DEKARON_NPC_COMBAT_INTEL=0 still restores the lane-1 decisions exactly, and
// DEKARON_NPC_ARCHETYPES=0 removes it. Combat polling cadence is NOT changed
// (npcCombatReactionMs ignores these defaults), matching the archetype lane's rule
// that combat keeps the competence-tier cadence. No stats, costs or validation change.
//   skill      = existing competence tier (npcCompetenceTier), unchanged
//   risk       = tier risk + 0.4 x (0.5 - archetype retreat tendency) + commitment shift
//                (archetype `risk` is caution: 1 = very cautious; lane-2 `risk` is boldness)
//   reactionMs = tier reaction x archetype reaction factor x commitment factor (mix.reaction),
//                factor clamped to [0.75, 1.5] so AFK-type bots aren't made helpless in a fight
//   potionHp / potionMp / retreatHp / role: left to lane 2, which derives them from risk/role
import {archetypesEnabled,npcArchetype,archetypeMix} from './npc-archetypes.mjs';
import {npcCompetenceTier} from './npc-personality.mjs';
export const ARCHETYPE_COMBAT=Object.freeze({riskGain:0.4,commitment:{hardcore:0.05,regular:0,casual:-0.05},riskClamp:[0.15,0.85],reactionFactorClamp:[0.75,1.5]});
const ON=archetypesEnabled();
const clamp=(v,lo,hi)=>Math.min(hi,Math.max(lo,v));
const memo=new WeakMap();
export function npcArchetypeCombatInput(p,{tierRisk,tierReactionMs,enabled=ON}={}){
 if(!enabled||!p?.profile)return null;
 const a=npcArchetype(p.profile);if(!a)return null;
 const skill=npcCompetenceTier(p),hit=memo.get(p.profile);if(hit&&hit.a===a&&hit.skill===skill)return hit.value;
 const C=ARCHETYPE_COMBAT,r=archetypeMix().mix.reaction||{};
 const baseRisk=tierRisk?.[skill]??0.5,baseReact=tierReactionMs?.[skill]??900;
 const risk=+clamp(baseRisk+C.riskGain*(0.5-(Number.isFinite(a.risk)?a.risk:0.5))+(C.commitment[a.commitment]||0),...C.riskClamp).toFixed(3);
 const factor=clamp((r.archetype?.[a.id]??1)*(r.commitment?.[a.commitment]??1),...C.reactionFactorClamp);
 const value=Object.freeze({skill,risk,reactionMs:Math.round(baseReact*factor),source:'archetype:'+a.id+'/'+a.commitment});
 memo.set(p.profile,{a,skill,value});return value;
}
