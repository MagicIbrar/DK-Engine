// LANE2 combat intelligence. Pure decision helpers for server-owned NPC players.
// Nothing here changes stats, costs, cooldowns, ranges or validation: every
// choice still becomes an ordinary world.action that the authority rechecks.
// Kill switch: world.npcCombatIntel=false or DEKARON_NPC_COMBAT_INTEL=0 restores
// the lane1-perf decisions exactly (every hook below is bypassed).
import {npcCompetenceTier} from './npc-personality.mjs';
import {flagsOf} from '../../src/systems/skills/statuses.js';
import {npcRecovery,npcSupport,npcLearnedSkills,npcHasStatus} from './npc-tactics.mjs';
import {ensureSkills} from './skills.mjs';
import {npcArchetypeCombatInput} from './npc-archetype-combat.mjs';

const TIERS=['novice','regular','expert','elite'];
const TIER_REACTION_MS={novice:1800,regular:900,expert:450,elite:300};   // = NPC_COMBAT_POLICY.decisionMs
const TIER_RISK={novice:.35,regular:.5,expert:.6,elite:.7};
const DAMAGE=new Set(['damage','remote','projectile','servant_explode']);
const HEALS=new Set(['heal','heal_area','heal_party']);
const CONTROL=new Set(['ACTION_DISALLOW_MOVE','ACTION_DISALLOW_ALL','ACTION_DISALLOW_ATTACK','ACTION_SLEEP','ACTION_PURGE','ADD_ACTION_SECOND_SURRENDER','ADD_ACTION_MENTAL_BREAKDOWN','ADD_ACTION_PANIC']);
const DEFENSIVE=new Set(['SHIELD_MAX_ADD','SHIELD_MAX_MUL','SHIELD_RECOVERY_ADD','DAMAGERATE_DAMAGEHP_MUL','SUFFER_DAMAGE_REGRESSION_RATE','RESIST_ALL_ADD','DEFENSE_MUL','REFLECT_DAMAGEHP_MUL']);
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const clamp=(v,lo,hi)=>Math.min(hi,Math.max(lo,v));
const finite=(v,d)=>Number.isFinite(Number(v))&&v!==null&&v!==''?Number(v):d;
const results=row=>(row.level?.steps||row.skill.steps||[]).map(s=>s.result).filter(Boolean);
const maxHp=q=>Number(q.maxHp||q.stats?.maxHp)||1;

export function npcCombatIntelEnabled(world){
 if(typeof world?.npcCombatIntel==='boolean')return world.npcCombatIntel;
 return process.env.DEKARON_NPC_COMBAT_INTEL!=='0';
}

// ---------------------------------------------------------------- parameters
// Inputs for other workers (archetypes): p.profile.npcCombat or brain.combatParams
// = {skill, reactionMs, risk, potionHp, potionMp, retreatHp, role}. Missing values
// derive from the existing competence tier, so default bots keep their tier pacing.
export function npcCombatRole(world,p,rows){
 const key=p.profile?.skills,n=key?Object.keys(key).length:0,cached=p._npcCombatRole;if(cached&&cached.key===key&&cached.n===n)return cached.role;
 const role=rows?.some(row=>(Number(row.skill.targetMask)&2)&&results(row).some(r=>HEALS.has(r.family)))?'healer':'fighter';
 p._npcCombatRole={key,n,role};return role;
}
export function npcCombatSkillTier(p){const s=p?.profile?.npcCombat?.skill;return TIERS.includes(s)?s:npcCompetenceTier(p);}
export function npcCombatParams(p,b,{role='fighter'}={}){
 const input={...(npcArchetypeCombatInput(p,{tierRisk:TIER_RISK,tierReactionMs:TIER_REACTION_MS})||{}),...(p?.profile?.npcCombat||{}),...(b?.combatParams||{})}; // archetype defaults (integration glue) under explicit inputs
 const skill=TIERS.includes(input.skill)?input.skill:npcCompetenceTier(p);
 const risk=clamp(finite(input.risk,TIER_RISK[skill]),0,1),r=input.role||role;
 return {skill,role:r,risk,
  reactionMs:clamp(finite(input.reactionMs,TIER_REACTION_MS[skill]),150,5000),
  potionHp:clamp(finite(input.potionHp,.6-.3*risk+(r==='healer'?.05:0)),.1,.9),
  potionMp:clamp(finite(input.potionMp,r==='healer'?.35:.25),.05,.9),
  retreatHp:clamp(finite(input.retreatHp,.3-.15*risk),.05,.6),
  aoeReadyHp:clamp(.75-.3*risk,.3,.95)};
}
export function npcCombatReactionMs(p,b){const v=b?.combatParams?.reactionMs??p?.profile?.npcCombat?.reactionMs;return v==null?null:clamp(finite(v,900),150,5000);}

// ---------------------------------------------------------------- threat ledger
// Recent damage events (who is hitting whom), kept 5 s, observed from the ordinary
// world event stream. Installed lazily on first use by an NPC decision.
const LEDGER_MS=5000;
export function npcThreatLedger(world){
 if(world._npcThreat)return world._npcThreat;
 const ledger={incoming:new Map(),dealt:new Map(),healed:new Map()};world._npcThreat=ledger;
 const push=(m,k,e)=>{let a=m.get(k);if(!a)m.set(k,a=[]);a.push(e);if(a.length>48)a.splice(0,a.length-48);};
 const emit=world.emit.bind(world);
 world.emit=function(map,event){
  if(event&&event.type==='damage'&&event.amount>0&&event.sourceId!==event.targetId){const at=world.now();push(ledger.incoming,event.targetId,{at,amount:event.amount,source:event.sourceId});push(ledger.dealt,event.sourceId,{at,amount:event.amount,target:event.targetId});}
  return emit(map,event);
 };
 return ledger;
}
function recent(list,now,ms=LEDGER_MS){if(!list)return [];let i=0;while(i<list.length&&now-list[i].at>LEDGER_MS)i++;if(i)list.splice(0,i);return ms>=LEDGER_MS?list:list.filter(e=>now-e.at<=ms);}
export function npcIncomingDps(world,id,ms=3000){const now=world.now(),l=recent(npcThreatLedger(world).incoming.get(id),now,ms);let s=0;for(const e of l)s+=e.amount;return s/(ms/1000);}

// ---------------------------------------------------------------- recovery
export function npcRecoveryThresholds(world,p,b,params){
 const dps=npcIncomingDps(world,p.id,2000),hp=maxHp(p);
 // Predictive: if 1.5 s of the observed incoming damage would cross the potion line, drink now.
 const predicted=Math.min(.9,params.potionHp+1.5*dps/hp);
 return {hpRatio:Math.max(params.potionHp,predicted),mpRatio:params.potionMp,dropping:dps*2>=hp*Math.max(.05,p.hp/hp-params.retreatHp)};
}
export function npcDefensiveRow(world,p,rows,hasStatus){
 for(const row of rows){const mask=Number(row.skill.targetMask)||0;if(!(mask&16))continue;
  const helpful=results(row).filter(r=>Number(r.statusIndex)>0&&Number(world.data.skillStatuses?.[r.statusIndex]?.property)===1);
  if(results(row).some(r=>r.family==='shield_heal')||helpful.some(r=>(world.data.skillStatuses[r.statusIndex].options||[]).some(o=>DEFENSIVE.has(o.code))&&!hasStatus(world,p,r.statusIndex)))if(row.engine.usability(row.skill.index).ok)return row;}
 return null;
}

// ---------------------------------------------------------------- spatial index
// One bucket grid per scene map, rebuilt at most every 200 ms of world time.
const GRID=8;
function grid(world,map){
 const now=world.now(),g=map._npcIntelGrid;if(g&&now-g.at<200)return g;
 const cells=new Map();for(const m of map.monsters.values()){if(m.dead||m.isBrick||m.eventObject||m.def?.role!=='creature')continue;const k=Math.floor(m.x/GRID)*65536+Math.floor(m.z/GRID);let c=cells.get(k);if(!c)cells.set(k,c=[]);c.push(m);}
 return map._npcIntelGrid={at:now,cells};
}
export function npcMonstersNear(world,map,pt,radius,sameScene=()=>true){
 const g=grid(world,map),out=[],x0=Math.floor((pt.x-radius)/GRID),x1=Math.floor((pt.x+radius)/GRID),z0=Math.floor((pt.z-radius)/GRID),z1=Math.floor((pt.z+radius)/GRID);
 for(let x=x0;x<=x1;x++)for(let z=z0;z<=z1;z++){const c=g.cells.get(x*65536+z);if(c)for(const m of c)if(!m.dead&&distance(m,pt)<=radius&&sameScene(m))out.push(m);}
 return out;
}

// ---------------------------------------------------------------- skill geometry
// The authority's reach (server/world/skills.mjs): max(1.5,range||3)+targetRadius+0.3.
export function npcSkillReach(row,target){return Math.max(1.5,Number(row.skill.range)||3)+(Number(target?._skillActor?.radius)||.5)+.3;}
const ROW_KIND=new WeakMap();
function rowKey(row){let m=ROW_KIND.get(row.skill);if(!m)ROW_KIND.set(row.skill,m=new Map());return m;}
export function npcSkillRadius(row){const m=rowKey(row),k='r'+(row.level?.reqLevel??'')+':'+(row.engine?.skillLevel?.(row.skill.index)??'');if(m.has(k))return m.get(k);let r=0;for(const x of results(row))if(DAMAGE.has(x.family))r=Math.max(r,Number(x.radius)||0);m.set(k,r);return r;}
export function npcControlRow(world,row){
 const cache=rowKey(row),ck='k'+(row.level?.reqLevel??'')+':'+(row.engine?.skillLevel?.(row.skill.index)??'');if(cache.has(ck))return cache.get(ck);
 let control=false,damaging=false;
 for(const r of results(row)){if(DAMAGE.has(r.family))damaging=true;if(r.family==='sleep_shock')control=true;const s=Number(r.statusIndex)>0&&world.data.skillStatuses?.[r.statusIndex];if(s&&Number(s.property)===0&&(s.options||[]).some(o=>CONTROL.has(o.code)))control=true;}
 const kind={control,damaging,durationMs:Math.max(0,...results(row).map(r=>Number(r.durationMs)||0))};cache.set(ck,kind);return kind;
}
export function npcTargetControlled(target){
 const list=target.profile?.buffs||target.statuses;if(!list?.length)return false;
 const live=list.filter(s=>!(Number.isFinite(Number(s.remaining))&&Number(s.remaining)<=1));
 const f=flagsOf(live);return f.move||f.attack||f.sleep||f.lock;
}

// ---------------------------------------------------------------- party coordination
function partyOf(world,p){return p.partyId&&world.parties?.get(p.partyId)||null;}
function claims(world){return world._npcCcClaims||(world._npcCcClaims=new Map());}
export function npcCcClaimed(world,p,targetId){const party=partyOf(world,p),key=(party?p.partyId:p.id)+':'+targetId,c=claims(world).get(key);return !!c&&c.until>world.now()&&c.by!==p.id;}
export function npcCcClaim(world,p,targetId,ms){const party=partyOf(world,p),key=(party?p.partyId:p.id)+':'+targetId,map=claims(world);map.set(key,{by:p.id,until:world.now()+Math.max(1500,ms)});if(map.size>256)for(const [k,c]of map)if(c.until<=world.now())map.delete(k);}

// ---------------------------------------------------------------- skill ordering
// rows: npcCombatSkills' native ordering. Returns a filtered/reordered copy whose
// entries may carry intelTarget (a better-placed AoE centre among engaged enemies).
export function npcIntelOrderSkills(world,p,b,target,rows,{map,isPlayer=false,role='fighter',sameScene}={}){
 if(!rows.length)return rows;
 const params=npcCombatParams(p,b,{role}),party=partyOf(world,p),members=new Set(party?.members||[p.id]);members.add(p.id);
 const d=distance(p,target),hpRatio=p.hp/maxHp(p),mpMax=Number(p.stats.maxMp)||1;
 const controlled=npcTargetControlled(target),claimed=npcCcClaimed(world,p,target.id);
 const keep=[],far=[];let approach=Infinity,crowd=null;const scores=new Map();
 for(const row of rows){
  const reach=npcSkillReach(row,target)-.15,mask=Number(row.skill.targetMask)||0;
  const kind=npcControlRow(world,row);
  // CC: never on an already-controlled target or one a party member just claimed.
  if(kind.control&&!kind.damaging&&(controlled||claimed))continue;
  // Healer mana reserve: keep enough MP for healing in a party.
  if(role==='healer'&&party&&kind.damaging){const cost=Number(row.level?.mp??row.skill.mpCost)||0;if(p.mp-cost<mpMax*params.potionMp)continue;}
  if(!(mask&16&&!(mask&(4|8)))&&d>reach){far.push(row);approach=Math.min(approach,reach);continue;}
  const radius=!isPlayer&&kind.damaging?npcSkillRadius(row):0;
  if(radius>0&&map){
   const inScene=sameScene||(()=>true);
   // Cheap exit: nothing else near the target -> plain single-target damage, no scoring.
   if(crowd==null)crowd=npcMonstersNear(world,map,target,radius+6.5,inScene).length>1;
   if(!crowd){keep.push({row,aoe:1,c:target,pull:0});continue;}
   const score=c=>{const key=c.id+'@'+radius;let v=scores.get(key);if(v)return v;let e=0,idle=0;for(const m of npcMonstersNear(world,map,c,radius+.5,inScene)){if(members.has(m.targetId))e++;else if(m.targetId==null)idle++;}v={e,idle};scores.set(key,v);return v;};
   let best={c:target,...score(target)};
   // Placement: among engaged enemies in reach whose blast still covers the chosen target, centre on the one that
   // hits most engaged and pulls fewest (the focus target keeps taking the hit).
   if(best.e<3)for(const m of npcMonstersNear(world,map,target,radius,inScene).slice(0,6)){if(m===target||!members.has(m.targetId)||distance(m,target)>radius||distance(p,m)>npcSkillReach(row,m)-.15)continue;const s=score(m);if(s.e-s.idle*2>best.e-best.idle*2)best={c:m,...s};}
   // Solo melee (a close-range AoE, reach <=4 u) stands inside the pack and has nobody to share an extra pull with:
   // only a high-risk profile (>=.75) accepts one. Ranged/solo casters keep the general line (measured: they gain from it).
   const soloMelee=!party&&npcSkillReach(row,target)<=4&&params.risk<.75;
   const ready=!soloMelee&&hpRatio>=params.aoeReadyHp&&p.mp>=mpMax*.4&&best.e+best.idle<=2+Math.round(4*params.risk);
   if(best.idle>0&&!ready)continue;                         // would pull extra mobs while not ready
   keep.push({row,aoe:best.e,c:best.c,pull:best.idle});continue;
  }
  keep.push({row,aoe:kind.damaging?1:0,c:target,pull:0});
 }
 b.combatApproach=keep.some(k=>k.aoe>0)||!far.length?null:{targetId:target.id,reach:approach,at:world.now()};
 // Several engaged enemies: an AoE that hits more of them precedes single-target damage (stable otherwise).
 // A ready bot keeps the native order for a pulling AoE: ordering it last (tried in 21db731) cost solo-mage TTK
 // 19.96 -> 30.09 s over 20 seeds with no pull reduction (10 -> 8 vs lane1 11), so only unready bots drop it (above).
 const out=keep.map((k,i)=>({k,i})).sort((a,q)=>(q.k.aoe>=2?q.k.aoe:0)-(a.k.aoe>=2?a.k.aoe:0)||a.i-q.i).map(({k})=>k.c===target?k.row:{...k.row,intelTarget:k.c});
 return out;
}
export function npcIntelNoteCast(world,p,row,target,b){if(b)b.intelFocus=target.id;const kind=npcControlRow(world,row);if(kind.control)npcCcClaim(world,p,target.id,kind.durationMs);}

// ---------------------------------------------------------------- refusal backoff
export function npcRefusalBackoffMs(state,skillId){const n=(state.count||(state.count={}))[skillId]=(state.count[skillId]||0)+1;return Math.min(4000,250*2**(n-1));}

// ---------------------------------------------------------------- target choice
// Candidates = monsters already attacking this bot or its party (the director's
// immediate-threat set). Nearest stays the default; peel monsters off healers and
// low-HP allies, keep the party's shared focus, and finish weakened enemies.
export function npcThreatTarget(world,p,candidates,{healers,lookup,current}={}){
 if(candidates.length<2)return candidates[0];
 const party=partyOf(world,p),now=world.now(),ledger=npcThreatLedger(world);
 const focus=new Map();
 if(party)for(const id of party.members){for(const e of recent(ledger.dealt.get(id),now))focus.set(e.target,(focus.get(e.target)||0)+e.amount);}
 let top=null,topDmg=0;for(const [id,v]of focus)if(v>topDmg){topDmg=v;top=id;}
 let best=null,bs=-Infinity;
 for(const m of candidates){
  const victim=m.targetId&&m.targetId!==p.id&&lookup?lookup(m.targetId):null;
  let s=-distance(p,m)/25;
  if(victim&&(healers?.has(victim.id)||victim.hp/maxHp(victim)<.5))s+=1.5;
  if(top&&m.id===top)s+=1;
  if(current!=null&&m.id===current)s+=.75;                 // stickiness: do not spread damage
  s+=.5*(1-m.hp/Math.max(1,Number(m.maxHp)||1));
  if(s>bs){bs=s;best=m;}
 }
 return best;
}
export function npcHealPriority(world,team){const dps=new Map(team.map(q=>[q,npcIncomingDps(world,q.id,3000)]));return (a,q)=>((1-q.hp/maxHp(q))+dps.get(q)*2/maxHp(q))-((1-a.hp/maxHp(a))+dps.get(a)*2/maxHp(a));}

// ---------------------------------------------------------------- director hooks
// The director's immediate-threat set and choice. Intel off = the exact lane1 nearest expression.
export function npcImmediateThreat(world,p,map,party,{lookup,current}={}){
 const set=[...map.monsters.values()].filter(m=>!m.dead&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&(m.targetId===p.id||party?.members.includes(m.targetId))&&distance(p,m)<25);
 if(!npcCombatIntelEnabled(world)||set.length<2)return set.sort((a,q)=>distance(p,a)-distance(p,q))[0];
 const healers=new Set();if(party&&lookup)for(const id of party.members){const q=lookup(id);if(q?._npcCombatRole?.role==='healer')healers.add(id);}
 return npcThreatTarget(world,p,set,{healers,lookup,current});
}
// Potion thresholds by role/risk (+ predictive on fast HP loss) and a defensive self skill when HP drops fast.
export async function npcIntelSurvival(world,p,b,act){
 const rows=npcLearnedSkills(world,p),params=npcCombatParams(p,b,{role:npcCombatRole(world,p,rows)}),th=npcRecoveryThresholds(world,p,b,params);
 if(await npcRecovery(world,p,act,{hpRatio:th.hpRatio,mpRatio:th.mpRatio}))return 'potion';
 if(th.dropping&&world.now()>=(b.defensiveAt||0)){const engine=ensureSkills(world,p).engine;if(!engine.active&&!engine.casting){const row=npcDefensiveRow(world,p,rows,npcHasStatus);if(row){b.defensiveAt=world.now()+1500;try{await act(p,{type:'cast',skillId:Number(row.skill.index)});return 'defensive';}catch(e){if(!e.status)throw e;}}}}
 return null;
}
// Healers re-check urgent heals at their reaction cadence instead of only on the 5 s support timer,
// choosing the ally with the largest HP deficit plus recent incoming damage.
export async function npcIntelUrgentSupport(world,p,b,act,team){
 const now=world.now();if(now<(b.healAt||0))return false;
 const rows=npcLearnedSkills(world,p);if(npcCombatRole(world,p,rows)!=='healer')return false;
 const params=npcCombatParams(p,b,{role:'healer'});b.healAt=now+params.reactionMs;
 if(!team.some(q=>q.dead||q.hp<maxHp(q)*.65))return false;
 return npcSupport(world,p,act,{buff:false,priority:npcHealPriority(world,team)});
}
// Tried and reverted in the lane2 follow-up (no measurable gain, 20-seed A/B):
// - aggro-aware approach detour (npcIntelApproachPoint): party-pack pulls 78 -> 74, TTK 20.08 -> 20.13 s; no-op solo.
// - shared per-grid neighbour lists/tallies across bots: decision p50 0.144 vs 0.154 ms party-pack, 0.184 vs 0.179 ms
//   solo-mage, outcomes identical; monster-AoE p50 ranges overlapped lane2c.
