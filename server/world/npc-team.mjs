// LANE3 team behaviour for bot-only parties of server-owned NPC players.
// Pure decision helpers: nothing here moves an actor, deals damage, creates
// aggro or bypasses validation. Every choice becomes an ordinary world.action
// (move/attack/cast/stop) that the authority rechecks. Kill switch:
// world.npcTeam=false or DEKARON_NPC_TEAM=0 restores the lane2 decisions
// exactly (every hook in npc-players.mjs is bypassed).
//
// Shared observations are range-limited: a member only learns about a monster
// that some party member in the same scene, within NPC_TEAM_POLICY.shareRange
// of it, can see (within observeRange and native line of sight). No monster
// from another map, instance or channel is ever returned (lookup goes through
// the caller's own scene map, plus an explicit scene check).
import {sameScene} from './scene.mjs';
import {aggroRadius,canAttack,isNonCombatant} from '../../src/game/monster-rules.js';
import {npcCombatRole,npcThreatLedger} from './npc-combat-intel.mjs';
import {npcLearnedSkills} from './npc-tactics.mjs';

export const NPC_TEAM_POLICY=Object.freeze({
 observeRange:22,     // a member sees monsters this close with native line of sight
 shareRange:36,       // and tells party members this close (party callouts, not omniscience)
 assistLeash:16,      // followers assist the shared focus only this close to the leader
 regroupRadius:7,     // "together": every live member this close to the leader
 spreadRadius:12,     // after combat, regroup if anyone is farther than this
 readyHp:.5,readyMp:.3,healerMp:.35,
 regroupMaxMs:12000,  // never wait longer than this for stragglers (bounded, no deadlock)
 recoverMaxMs:20000,  // nor for HP/MP
 budget:{novice:.75,regular:1,expert:1.5,elite:2},  // per-member pull capacity (equal-level-normal equivalents)
 vulnerableHp:.45,
 combatSettle:3.5,
 holdStuckMs:2500,     // a held follower with a path but no movement this long is re-pathed
 holdLoopMs:8000,      // ... or with a path that has not brought it closer to its slot this long     // in combat a follower re-slots only beyond this distance
 minSpacing:1.3,      // soft separation between members' goals
 slotSettle:1.4,      // a follower within this of its slot does not repath
 formationMs:900,     // at most one formation re-target per follower per this (unless far)
 fallbackRange:10,    // a non-tank attacked this far from the leader falls back to the party
});
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const maxHp=q=>Number(q.maxHp||q.stats?.maxHp)||1;
const maxMp=q=>Number(q.stats?.maxMp||q.maxMp)||0;
const npc=p=>p?.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile?.authority==='server';
const live=p=>p&&!p.dead&&!p.leaving&&!p.sceneTransition;
const TIERS=['novice','regular','expert','elite'];

export function npcTeamEnabled(world){
 if(typeof world?.npcTeam==='boolean')return world.npcTeam;
 return process.env.DEKARON_NPC_TEAM!=='0';
}
// Component switches for bench ablations only (both true in production).
export const NPC_TEAM_ABLATION={peel:true,assist:true};
export const npcTeamStats=world=>world._npcTeamStats||(world._npcTeamStats={peels:0,assists:0,pullWaits:0,budgetWaits:0,regroupWaits:0,formationMoves:0,fallbacks:0,corridorTrail:0,sidesteps:0,staleFocus:0,crossScene:0,hotAvoided:0,hotSkips:0,unsticks:0});

// ---------------------------------------------------------------- roles
// healer: the lane2 role test (a party-targetable heal is learned).
// tank: melee reach and the party's sturdiest melee (class base CON or the
// actor's own con allocation decides "sturdy"; maxHp breaks ties).
// support: ranged with party-targetable helpful statuses and no heal.
// dps: everyone else. Roles are a pure function of class, learned skills and
// build; they never change stats.
function baseRole(world,p){
 const key=p.profile?.skills,n=key?Object.keys(key).length:0,c=p._npcTeamRole;
 if(c&&c.key===key&&c.n===n&&c.level===p.profile?.level)return c;
 const rows=npcLearnedSkills(world,p)||[];
 const healer=npcCombatRole(world,p,rows)==='healer';
 const reach=Number(p.stats?.attackRange)||5,melee=reach<=3.5;
 const buffs=rows.some(row=>(Number(row.skill.targetMask)&2)&&(row.level?.steps||row.skill.steps||[]).some(s=>Number(s?.result?.statusIndex)>0&&Number(world.data.skillStatuses?.[s.result.statusIndex]?.property)===1));
 const st=p.profile?.stats||{},sturdy=(Number(st.con)||0)/Math.max(1,(Number(st.str)||0)+(Number(st.dex)||0)+(Number(st.con)||0)+(Number(st.spr)||0));
 const r={key,n,level:p.profile?.level,role:healer?'healer':melee?'melee':buffs?'support':'dps',melee,sturdy};
 p._npcTeamRole=r;return r;
}
/** Party roles for one scene's live members: {id -> 'tank'|'dps'|'healer'|'support'}. */
export function npcPartyRoles(world,members){
 const out=new Map();let tank=null,best=-Infinity;
 for(const q of members){const r=baseRole(world,q);if(r.role==='melee'){const s=r.sturdy*10+maxHp(q)/1e4+(Number(q.profile?.classIndex)===0?5:0);if(s>best){best=s;tank=q;}}}
 for(const q of members){const r=baseRole(world,q).role;out.set(q.id,q===tank?'tank':r==='melee'?'dps':r);}
 return out;
}
export const npcTeamMelee=(world,p)=>baseRole(world,p).melee;

// ---------------------------------------------------------------- team view
// One view per party+scene per world time stamp; every member of that party in
// that scene shares it (cheap: one monster scan per party per tick instead of
// one per member).
const views=new WeakMap();
function viewsOf(world){let v=views.get(world);if(!v){v=new Map();views.set(world,v);}return v;}
function partyMembers(world,party,lookup){
 const out=[];for(const id of party.members){const q=lookup(id);if(q&&!q.leaving&&q.partyId===party.id)out.push(q);}return out;
}
function monsterOk(m){return m&&!m.dead&&!m.isBrick&&!m.eventObject&&m.def?.role==='creature'&&!isNonCombatant(m.def);}
function los(map,a,b){return !map.collision?.lineOfSight||map.collision.lineOfSight(a.x,a.z,b.x,b.z);}
export function npcTeamView(world,p,{party,lookup,map}){
 if(!party||!map||!party.members?.includes(p.id))return null;
 const now=world.now(),key=party.id+'|'+(p.map)+'|'+(p.instanceId||'')+'|'+(p.channel||0),cache=viewsOf(world),hit=cache.get(key);
 if(hit&&hit.at===now&&hit.map===map&&hit.size===party.members.length&&hit.leaderId===party.leader)return hit;
 const all=partyMembers(world,party,lookup),scene=all.filter(q=>sameScene(q,p)),alive=scene.filter(live),ids=new Set(all.map(q=>q.id));
 const R=NPC_TEAM_POLICY.observeRange,seen=new Map(),engaged=[];
 for(const m of map.monsters.values()){
  if(!monsterOk(m))continue;
  if(m.instanceId!==undefined&&(m.instanceId||null)!==(p.instanceId||null)||m.map!=null&&Number(m.map)!==Number(p.map)||!p.instanceId&&m.channel!=null&&(m.channel||0)!==(p.channel||0)){npcTeamStats(world).crossScene++;continue;}
  let observers=null;
  for(const q of alive)if(Math.abs(q.x-m.x)<=R&&Math.abs(q.z-m.z)<=R&&distance(q,m)<=R&&los(map,q,m)){(observers||(observers=[])).push(q.id);}
  if(!observers)continue;
  const e={m,observers,engaged:ids.has(m.targetId)};seen.set(m.id,e);if(e.engaged)engaged.push(e);
 }
 const leader=lookup(party.leader),roles=npcPartyRoles(world,alive);
 const view={at:now,map,key,size:party.members.length,leaderId:party.leader,party,allBots:all.length===party.members.length&&all.every(npc),leader:leader&&sameScene(leader,p)&&!leader.leaving?leader:null,all,scene,alive,ids,seen,engaged,roles,assign:null};
 cache.set(key,view);if(cache.size>512)cache.delete(cache.keys().next().value);
 return view;
}
/** Monsters p knows about: seen by a live same-scene member within shareRange of p. */
export function npcTeamKnown(view,p,id){
 const e=view.seen.get(id);if(!e)return null;
 for(const oid of e.observers){if(oid===p.id)return e;const o=view.alive.find(q=>q.id===oid);if(o&&distance(o,p)<=NPC_TEAM_POLICY.shareRange)return e;}
 return null;
}

// ---------------------------------------------------------------- focus and peel
function leaderFocus(world,view,brainOf){
 const leader=view.leader;if(!leader||leader.dead)return null;
 if(view.focus!==undefined)return view.focus;view.focus=null;
 const dealt=npcThreatLedger(world).dealt.get(leader.id),now=world.now();
 for(let i=(dealt?.length||0)-1;i>=0;i--){const e=dealt[i];if(now-e.at>3000)break;const s=view.seen.get(e.target);if(s&&!s.m.dead)return view.focus=s;}
 // Leader has chosen a target (its own brain) that is already fighting the party but has not taken leader damage yet.
 const lb=brainOf?.(leader),hint=lb&&(lb.intelFocus??lb.target),t=hint!=null?view.seen.get(hint):null;
 if(t&&!t.m.dead&&t.engaged)return view.focus=t;
 return null;
}
// Greedy deterministic peel assignment, once per view: each monster attacking a
// vulnerable member (healer, or HP under vulnerableHp) gets one peeler, the tank
// first, then melee dps, then anyone else not a healer; nearest wins ties.
function assignments(world,view){
 // Peel: monsters on a vulnerable member (healer, or under vulnerableHp). The
 // tank takes the threat nearest to it (pulls it off); with no tank the nearest
 // melee member takes the weakest threat. Everyone else is left to lane2.
 if(view.assign)return view.assign;
 const assign=new Map();
 const vulnerable=q=>view.roles.get(q.id)==='healer'||q.hp/maxHp(q)<NPC_TEAM_POLICY.vulnerableHp;
 const frac=m=>m.hp/Math.max(1,Number(m.maxHp)||1);
 const threats=view.engaged.filter(e=>!e.m.dead&&view.alive.some(q=>q.id===e.m.targetId&&vulnerable(q))).map(e=>e.m)
  .sort((a,b)=>frac(a)-frac(b)||String(a.id).localeCompare(String(b.id)));
 if(!threats.length){view.assign=assign;return assign;}
 const victims=new Set(threats.map(m=>m.targetId));
 const pool=view.alive.filter(q=>!victims.has(q.id)&&view.roles.get(q.id)!=='healer').sort((a,b)=>String(a.id).localeCompare(String(b.id)));
 const tank=pool.find(q=>view.roles.get(q.id)==='tank');
 if(tank)assign.set(tank.id,[...threats].sort((a,b)=>distance(tank,a)-distance(tank,b)||String(a.id).localeCompare(String(b.id)))[0]);
 // Non-tanks keep lane2's own threat answer / the leader's focus (lane2's npcImmediateThreat
 // already covers monsters on party members); a dps-wide peel measured worse in healer-focus.
 if(!tank&&pool.length&&NPC_TEAM_ABLATION.dpsPeel!==false){const q=pool.filter(q=>npcTeamMelee(world,q)).sort((a,b)=>distance(a,threats[0])-distance(b,threats[0]))[0];if(q)assign.set(q.id,threats[0]);}
 view.assign=assign;return assign;
}
// Leader's choice among monsters already fighting the party: keep the committed
// target, finish weakened ones, and do not chase a monster that is about to
// exceed its native pursuit range from home (it would reset to full HP and the
// party would drag the fight across the map). Returns null to keep lane2's pick.
function leashMargin(m){const pursuit=Number(m.def?.ai?.pursuit);if(!Number.isFinite(pursuit)||!m.home)return Infinity;return pursuit-distance(m,m.home);}
function leaderEngagedTarget(world,p,b,view){
 const list=view.engaged.filter(e=>!e.m.dead&&distance(p,e.m)<25&&npcTeamKnown(view,p,e.m.id)).map(e=>e.m);
 if(!list.length)return null;
 const st=b.teamPull||(b.teamPull={waitFrom:null,reason:null,commit:null});
 let best=null,bs=-Infinity;const hot=pt=>npcTeamHot(view,pt,p);
 for(const m of list){
  let sc=-distance(p,m)/10+(1-m.hp/Math.max(1,Number(m.maxHp)||1));
  if(distance(p,m)>(Number(p.stats?.attackRange)||5)+1&&hot(m))sc-=2.5;
  if(st.commit===m.id)sc+=2;
  if(leashMargin(m)<3)sc-=3;
  if(m.targetId&&m.targetId!==p.id){const v=view.alive.find(q=>q.id===m.targetId);if(v&&view.roles.get(v.id)==='healer')sc+=1.5;}
  if(sc>bs){bs=sc;best=m;}
 }
 st.commit=best.id;return {kind:'lead',target:best};
}
/** A combat target for p chosen by party role, or null (caller keeps its own choice).
 * kind: 'peel' (protect a vulnerable member) | 'assist' (the leader's focus). */
export function npcTeamCombatTarget(world,p,b,{party,lookup,map,current=null,brainOf=null}={}){
 if(!npcTeamEnabled(world)||!npc(p)||!live(p))return null;
 const view=npcTeamView(world,p,{party,lookup,map});if(!view||!view.allBots||view.alive.length<2)return null;
 const role=view.roles.get(p.id);if(role==='healer')return null;
 const peel=NPC_TEAM_ABLATION.peel?assignments(world,view).get(p.id):null;
 // lane2's own immediate threat already protects a vulnerable member: keep it
 // (overriding it with the assignment measured worse: healer-focus ablation).
 const protects=m=>m&&!m.dead&&view.alive.some(q=>q.id===m.targetId&&q!==p&&(view.roles.get(q.id)==='healer'||q.hp/maxHp(q)<NPC_TEAM_POLICY.vulnerableHp));
 if(peel&&protects(current))return null;
 if(peel&&!peel.dead&&npcTeamKnown(view,p,peel.id)){npcTeamStats(world).peels++;return {kind:'peel',target:peel};}
 if(view.leader===p)return leaderEngagedTarget(world,p,b,view);
 const focus=NPC_TEAM_ABLATION.assist?leaderFocus(world,view,brainOf):null;
 if(!focus||focus.m.dead)return null;
 if(!npcTeamKnown(view,p,focus.m.id)){npcTeamStats(world).staleFocus++;return null;}
 if(view.leader&&distance(focus.m,view.leader)>NPC_TEAM_POLICY.assistLeash)return null;
 // No target thrash: a monster already on p, or one p can already hit while the
 // focus is out of p's reach, stays p's answer (no walk across the pack).
 const reach=(Number(p.stats?.attackRange)||5)+1;
 if(current&&current!==focus.m&&!current.dead){
  if(current.targetId===p.id&&role!=='tank')return null;
  if(distance(p,current)<=reach&&distance(p,focus.m)>reach)return null;
 }
 if(distance(p,focus.m)>reach&&hotLine(view,p,focus.m,view.leader)){npcTeamStats(world).hotSkips++;return null;}
 npcTeamStats(world).assists++;return {kind:'assist',target:focus.m};
}

// ---------------------------------------------------------------- pull gate (leader)
// The leader of a bot-only party engages a NEW (not yet engaged) monster only
// when the party is together, healthy and under its party-level pull budget.
// Waits are bounded (regroupMaxMs / recoverMaxMs); an engaged monster is always
// allowed (finishing a fight is never gated).
export function npcTeamPullBudget(view,p){
 // Capacity in equal-level-normal equivalents: per-member capacity by tier,
 // plus one for a live healer. Compared against npcTeamThreat sums.
 const tier=TIERS.includes(p.profile?.npcTraits?.pvpSkill)?p.profile.npcTraits.pvpSkill:'regular';
 const healer=view.alive.some(q=>view.roles.get(q.id)==='healer');
 return Math.max(1,NPC_TEAM_POLICY.budget[tier]*view.alive.length+(healer?1:0));
}
function hostileNear(view,m,point){
 // Unengaged aggressive monsters (other than m) whose native sight covers point.
 let n=0;for(const e of view.seen.values()){const o=e.m;if(o===m||e.engaged||!o.def?.ai?.aggressive||!canAttack(o.def))continue;if(distance(o,point)<=aggroRadius(o.def)+.5)n++;}return n;
}
// Idle aggro: an alive, aggressive, unengaged monster the party currently sees
// (range-limited view, no omniscience) whose native sight covers pt. Monsters
// whose sight already covers `anchor` (the leader's spot: the current pull) are
// exempt, so this only flags drifting into a *different* pack.
export function npcTeamHot(view,pt,anchor=null){
 if(!view||!pt)return false;
 for(const e of view.seen.values()){const o=e.m;if(o.dead||e.engaged||o.targetId||!o.def?.ai?.aggressive||!canAttack(o.def))continue;
  const r=aggroRadius(o.def)+1;if(anchor&&distance(o,anchor)<=r)continue;if(distance(o,pt)<=r)return true;}
 return false;
}
// The walk p -> m (sampled every 2 units) crosses another idle pack's sight.
function hotLine(view,p,m,anchor){const d=distance(p,m),n=Math.max(1,Math.ceil(d/2));for(let i=1;i<=n;i++){const t=i/n;if(npcTeamHot(view,{x:p.x+(m.x-p.x)*t,z:p.z+(m.z-p.z)*t},anchor))return true;}return false;}
function hotFor(world,view,b){const anchor=view.leader;const fn=pt=>npcTeamHot(view,pt,anchor);if(b)b.navAvoid={at:world.now(),fn};return fn;}
// Threat in equal-level-normal equivalents: level gap (x1.12 per level, clamped)
// times rank (elite/boss rows weigh 2.5x/5.5x). Native def fields only.
export function npcTeamThreat(m,partyLevel){
 const lvl=Number(m?.def?.level),dl=Number.isFinite(lvl)&&Number.isFinite(partyLevel)?lvl-partyLevel:0;
 return Math.min(4,Math.max(.4,1.12**dl))*(1+1.5*Math.max(0,Number(m?.def?.rank)||0));
}
function partyLevel(view){const l=view.alive.map(q=>Number(q.profile?.level)||0).filter(x=>x>0);return l.length?l.reduce((a,b)=>a+b,0)/l.length:null;}
function expectedThreat(view,m,point){
 const L=partyLevel(view);let t=npcTeamThreat(m,L);
 for(const e of view.seen.values()){const o=e.m;if(o===m||o.dead||e.engaged||!o.def?.ai?.aggressive||!canAttack(o.def))continue;if(distance(o,point)<=aggroRadius(o.def)+.5||distance(o,m)<=aggroRadius(o.def)*.5)t+=npcTeamThreat(o,L);}
 return t;
}
// One leader decision: {fight:m, approach?} or {wait:reason}. `candidate` is
// the director's own objective choice. The leader commits to one target until
// it dies or leaves the shared view, finishes engaged monsters before any new
// pull, and starts a new pull only when the party is ready; a pull expected to
// exceed the party budget (target plus unengaged aggressive monsters whose
// sight covers the approach cell) additionally needs full readiness.
export function npcTeamLeaderTarget(world,p,b,{party,lookup,map,candidate,reach=5}={}){
 if(!npcTeamEnabled(world)||!npc(p)||!candidate)return candidate?{fight:candidate}:null;
 const view=npcTeamView(world,p,{party,lookup,map});if(!view||!view.allBots||view.alive.length<2||view.leader!==p)return {fight:candidate};
 const now=world.now(),st=b.teamPull||(b.teamPull={waitFrom:null,reason:null,commit:null});
 const engaged=view.engaged.filter(e=>!e.m.dead).map(e=>e.m);
 let commit=st.commit!=null?map.monsters.get(st.commit):null;
 if(commit&&(commit.dead||!view.seen.has(commit.id)))commit=st.commit=null;
 if(engaged.length){
  st.waitFrom=null;st.reason=null;
  const pick=commit&&engaged.includes(commit)?commit:engaged.includes(candidate)?candidate:engaged.sort((a,c)=>distance(p,a)-distance(p,c)||String(a.id).localeCompare(String(c.id)))[0];
  st.commit=pick.id;if(pick!==candidate)npcTeamStats(world).budgetWaits++;return {fight:pick,kind:'engaged'};
 }
 const target=commit||candidate;
 // Readiness: together, HP, MP (healers need more), bounded by a wait clock.
 const far=view.alive.filter(q=>q!==p&&distance(q,p)>NPC_TEAM_POLICY.regroupRadius);
 const hpLine=q=>q.hp/maxHp(q),mpLine=q=>maxMp(q)>0?q.mp/maxMp(q):1;
 const approach=approachPoint(world,view,p,target,reach,map),at=approach.approach||target;
 const expected=expectedThreat(view,target,at),capacity=npcTeamPullBudget(view,p),ratio=expected/capacity,big=ratio>1;
 // Readiness scales with how far the expected pull exceeds capacity: within
 // capacity the normal line; up to 2x a moderate line; beyond that (genuinely
 // dangerous: elites/bosses, big level gaps, many adds) a full top-off.
 const extra=ratio<=1?0:ratio<=2?.1:.25;
 const needHp=NPC_TEAM_POLICY.readyHp+extra,needMp=q=>(view.roles.get(q.id)==='healer'?NPC_TEAM_POLICY.healerMp:NPC_TEAM_POLICY.readyMp)+extra;
 const reason=far.length?'regroup':view.alive.some(q=>hpLine(q)<needHp)?'health':view.alive.some(q=>mpLine(q)<needMp(q))?'mana':null;
 if(reason){
  // One wait clock for the whole readiness wait (a reason flipping between
  // regroup/health/mana does not restart it): total wait stays bounded.
  if(st.waitFrom==null)st.waitFrom=now;st.reason=reason;
  const limit=reason==='regroup'?NPC_TEAM_POLICY.regroupMaxMs:NPC_TEAM_POLICY.recoverMaxMs;
  if(now-st.waitFrom<limit){npcTeamStats(world)[reason==='regroup'?'regroupWaits':'pullWaits']++;return {wait:reason,big,ratio:+ratio.toFixed(2)};}
 }
 st.waitFrom=null;st.reason=null;st.commit=target.id;
 return {fight:target,kind:'pull',big,expected,capacity,...approach};
}
/** Compatibility wrapper: {ok:true,...} when the leader may engage `target` now. */
export function npcTeamPullGate(world,p,b,{party,lookup,map,target,reach=5}={}){
 const r=npcTeamLeaderTarget(world,p,b,{party,lookup,map,candidate:target,reach});
 if(!r)return {ok:true};if(r.wait)return {ok:false,reason:r.wait};
 return r.fight===target?{ok:true,approach:r.approach}:{ok:false,reason:'engaged',alternative:r.fight};
}
// Approach cell for the leader: within reach of the target with line of sight,
// walkable, preferring cells outside other unengaged aggressive monsters' sight.
function approachPoint(world,view,p,m,reach,map){
 if(distance(p,m)<=reach+.3)return {};
 const here=hostileNear(view,m,{x:m.x+(p.x-m.x)/distance(p,m)*reach*.9,z:m.z+(p.z-m.z)/distance(p,m)*reach*.9});
 if(!here)return {};
 const base=Math.atan2(p.z-m.z,p.x-m.x);let best=null,bs=Infinity;
 for(let k=0;k<12;k++){
  const a=base+(k%2?1:-1)*Math.ceil(k/2)*Math.PI/6,r=Math.max(1.2,reach*.85),pt={x:m.x+Math.cos(a)*r,z:m.z+Math.sin(a)*r};
  if(!map.isWalkable?.(pt.x,pt.z)||!los(map,pt,m))continue;
  const s=hostileNear(view,m,pt)*100+distance(p,pt);if(s<bs){bs=s;best=pt;}
 }
 return best&&bs<here*100?{approach:best}:{};
}

// ---------------------------------------------------------------- formation
// Role slots relative to the leader and the party's facing (towards the shared
// focus when fighting, else the leader's recent motion). Slots are soft goals:
// a slot is used only if its cell is walkable, has line of sight from the leader
// (never through a wall) and keeps minSpacing from other members; otherwise it
// shrinks, and in a corridor followers trail on the leader's own recent cells
// (they yield the passage instead of standing beside the leader).
const SLOT={tank:[[2,0]],dps:[[.5,-2],[.5,2],[-1,-2.6],[-1,2.6]],support:[[-2.8,-1.2],[-2.8,1.2]],healer:[[-3.4,0],[-3.4,-1.6]]};
const trails=new WeakMap();
function trailOf(world,leader){let t=trails.get(leader);if(!t){t={pts:[],key:null};trails.set(leader,t);}const key=leader.map+'|'+(leader.instanceId||'')+'|'+(leader.channel||0);if(t.key!==key){t.key=key;t.pts=[];}const last=t.pts.at(-1);if(!last||distance(last,leader)>=1){t.pts.push({x:leader.x,z:leader.z});if(t.pts.length>32)t.pts.shift();}return t;}
function rawHeading(world,view,leader,brainOf){
 const focus=leaderFocus(world,view,brainOf);if(focus){const d=distance(leader,focus.m);if(d>.5)return {x:(focus.m.x-leader.x)/d,z:(focus.m.z-leader.z)/d};}
 const t=trailOf(world,leader).pts;if(t.length>=2){const a=t[Math.max(0,t.length-4)],d=distance(a,leader);if(d>.5)return {x:(leader.x-a.x)/d,z:(leader.z-a.z)/d};}
 return null;
}
// Facing is quantised to 45 degrees with 30-degree hysteresis so small focus or
// leader wiggles do not rotate every slot (and re-path every follower).
function heading(world,view,leader,brainOf){
 const t=trailOf(world,leader),r=rawHeading(world,view,leader,brainOf);
 if(r){const a=Math.atan2(r.z,r.x);if(t.facing==null||Math.abs(Math.atan2(Math.sin(a-t.facing),Math.cos(a-t.facing)))>Math.PI/6*1.5)t.facing=Math.round(a/(Math.PI/4))*(Math.PI/4);}
 if(t.facing==null){const y=Number(leader.yaw)||0;t.facing=Math.atan2(-Math.cos(y),-Math.sin(y));}
 return {x:Math.cos(t.facing),z:Math.sin(t.facing)};
}
export function npcTeamFormationGoal(world,p,b,{party,lookup,map,brainOf=null}={}){
 if(!npcTeamEnabled(world)||!npc(p)||!live(p))return null;
 const view=npcTeamView(world,p,{party,lookup,map});const leader=view?.leader;
 if(!view||!view.allBots||!leader||leader===p||!live(leader)||!sameScene(leader,p))return null;
 const role=view.roles.get(p.id)||'dps',same=view.alive.filter(q=>q!==leader&&(view.roles.get(q.id)||'dps')===role).sort((a,c)=>(Number(a.profile?.npcSeed?.slot)||0)-(Number(c.profile?.npcSeed?.slot)||0)||String(a.id).localeCompare(String(c.id)));
 const ord=Math.max(0,same.indexOf(p)),slots=SLOT[role]||SLOT.dps,[fw,lat]=slots[ord%slots.length],row=Math.floor(ord/slots.length);
 const h=heading(world,view,leader,brainOf),others=view.alive.filter(q=>q!==p&&q!==leader);
 const claimed=b=>others.some(q=>distance(q,b)<NPC_TEAM_POLICY.minSpacing)||distance(leader,b)<NPC_TEAM_POLICY.minSpacing*.8;
 // Idle-aggro avoidance only while travelling (no engaged monsters): in a fight
 // the monsters move every tick and the slot choice would flip (measured as
 // formation churn / no-progress windows in party-pack).
 const hotFn=hotFor(world,view,b),hot=view.engaged.length?()=>false:hotFn;let hotSlot=null;
 for(const scale of [1,.65,.4])for(const side of [1,-1]){
  if(side<0&&!lat)continue;
  const f=(fw-row*1.2)*scale,l=lat*scale*side,pt={x:leader.x+h.x*f-h.z*l,z:leader.z+h.z*f+h.x*l};
  if(!(map.isWalkable?.(pt.x,pt.z)&&los(map,leader,pt)&&!claimed(pt)))continue;
  const g={kind:'slot',at:pt,role,near:distance(p,pt)<=NPC_TEAM_POLICY.slotSettle};
  if(!hot(pt)){if(side<0||scale<1&&hotSlot)npcTeamStats(world).hotAvoided++;return g;}
  hotSlot??=g;
 }
 // Corridor (or every slot inside another pack's aggro): trail on the leader's
 // own recent cells (cells the leader already crossed), spaced by ordinal.
 const t=trailOf(world,leader).pts,all=view.alive.filter(q=>q!==leader).sort((a,c)=>(Number(a.profile?.npcSeed?.slot)||0)-(Number(c.profile?.npcSeed?.slot)||0)||String(a.id).localeCompare(String(c.id)));
 const back=Math.min(t.length-1,2+all.indexOf(p)*1);const pt=t.length>1?t[t.length-1-Math.max(1,back)]:null;
 const trail=pt&&map.isWalkable?.(pt.x,pt.z)?{kind:'trail',at:{x:pt.x,z:pt.z},role,near:distance(p,pt)<=NPC_TEAM_POLICY.slotSettle}:null;
 if(trail&&(!hotSlot||!hot(trail.at))){npcTeamStats(world)[hotSlot?'hotAvoided':'corridorTrail']++;return trail;}
 return hotSlot||trail;
}
/** A follower standing on the leader's next path cells steps aside (yield), else null. */
export function npcTeamYield(world,p,{leader,map}){
 if(!leader?.path?.length||!map)return null;
 const ahead=leader.path.slice(0,3);if(!ahead.some(pt=>distance(pt,p)<1))return null;
 const d=leader.path[0],dx=d.x-leader.x,dz=d.z-leader.z,len=Math.hypot(dx,dz)||1;
 for(const s of [1.6,-1.6,2.4,-2.4]){const pt={x:p.x-dz/len*s,z:p.z+dx/len*s};if(map.isWalkable?.(pt.x,pt.z)&&los(map,p,pt)){npcTeamStats(world).sidesteps++;return pt;}}
 return null;
}

// ---------------------------------------------------------------- regroup (leader)
/** After combat, a leader whose live party is spread waits (bounded) instead of walking on. */
export function npcTeamRegroup(world,p,b,{party,lookup,map}={}){
 if(!npcTeamEnabled(world)||!npc(p)||!live(p))return null;
 const view=npcTeamView(world,p,{party,lookup,map});if(!view||!view.allBots||view.leader!==p||view.alive.length<2){if(b)delete b.teamRegroup;return null;}
 if(view.engaged.length){delete b.teamRegroup;return null;}
 const far=view.alive.filter(q=>q!==p&&distance(q,p)>NPC_TEAM_POLICY.spreadRadius);
 if(!far.length){delete b.teamRegroup;return null;}
 const now=world.now(),st=b.teamRegroup||(b.teamRegroup={from:now});
 if(now-st.from>NPC_TEAM_POLICY.regroupMaxMs)return null;
 npcTeamStats(world).regroupWaits++;return {kind:'regroup',waiting:far.length};
}

// ---------------------------------------------------------------- director entry points
// Town = PeaceZone && PcStore (as npc-activities.mjs); towns keep npc-town-layout's spacing.
const peaceZone=(world,p)=>{const r=world.data?.mapRow?.(p.map);return Number(r?.PeaceZone)===1&&Number(r?.PcStore)===1;};
/** Is p a member of a bot-only party this lane governs (field scene, same scene as a live bot leader)? */
export function npcTeamGoverns(world,p,{party,lookup,map}={}){
 // Instances (dungeons/events) keep their own objective planners (lane4); towns keep npc-town-layout.
 if(!npcTeamEnabled(world)||!npc(p)||!live(p)||!party||!map||p.instanceId||peaceZone(world,p))return false;
 const view=npcTeamView(world,p,{party,lookup,map});return !!(view&&view.allBots&&view.alive.length>=2&&view.leader&&npc(view.leader));
}
/** One member decision: {fight,kind} | {move,kind} | {hold,kind} | null (caller keeps lane2 behaviour).
 * The leader only ever gets {fight} (peel / committed engaged target); followers also get formation moves. */
export function npcTeamMemberStep(world,p,b,{party,lookup,map,brainOf=null,immediateThreat=null}={}){
 if(!npcTeamGoverns(world,p,{party,lookup,map}))return null;
 const view=npcTeamView(world,p,{party,lookup,map}),leader=view.leader;
 const t=npcTeamCombatTarget(world,p,b,{party,lookup,map,current:immediateThreat,brainOf});
 if(t||immediateThreat)b.teamCombatAt=world.now();
 if(t)return {fight:t.target,kind:t.kind};
 if(leader===p)return null;
 // A straggler under attack falls back to the party (the monster follows it into
 // the group's reach) instead of fighting alone; tanks and nearby members hold.
 if(immediateThreat){
  const role=view.roles.get(p.id);
  // Healers never fall back (a walking healer is not healing: measured in
  // healer-focus), and nobody runs while a peeler is already assigned to the
  // monster on them (the tank is coming; running drags the fight away from it).
  const peeled=[...(assignments(world,view)?.values()||[])].includes(immediateThreat);
  if(role!=='tank'&&role!=='healer'&&!peeled&&live(leader)&&distance(p,leader)>NPC_TEAM_POLICY.fallbackRange&&immediateThreat.targetId===p.id){
   const f=npcTeamFormationGoal(world,p,b,{party,lookup,map,brainOf});npcTeamStats(world).fallbacks++;
   return {move:f?.at||{x:leader.x,z:leader.z},kind:'fallback',urgent:true};
  }
  return null;
 }
 if(!live(leader))return {hold:true,kind:'leader-down'};
 const y=npcTeamYield(world,p,{leader,map});if(y)return {move:y,kind:'yield'};
 const f=npcTeamFormationGoal(world,p,b,{party,lookup,map,brainOf});
 if(f){
  // Hysteresis: near the slot, or already walking to a point near it, is a hold (no new move request).
  const end=p.path?.at(-1),now=world.now(),d=distance(p,f.at);
  // A hold must not hide a dead path: a follower that has had a path but no
  // movement for stuckMs is sent to the leader's cell (a different, walkable
  // goal: the server re-paths it; nav's ladder takes over if that fails too).
  // Also a path that keeps the follower walking but never brings it closer to
  // its slot (a loop, e.g. the slot is in an area the server path cannot reach).
  if(!p.path?.length){b.teamHoldPos=null;}
  else{
   const hp=b.teamHoldPos||(b.teamHoldPos={x:p.x,z:p.z,at:now,d,dAt:now});
   if(distance(hp,p)>.3){hp.x=p.x;hp.z=p.z;hp.at=now;}
   if(d<hp.d-.5){hp.d=d;hp.dAt=now;}
   if(live(leader)&&(now-hp.at>=NPC_TEAM_POLICY.holdStuckMs||now-hp.dAt>=NPC_TEAM_POLICY.holdLoopMs)){
    b.teamHoldPos=null;npcTeamStats(world).unsticks++;return {move:{x:leader.x,z:leader.z},kind:'unstick'};
   }
  }
  if(f.near||end&&distance(end,f.at)<=NPC_TEAM_POLICY.slotSettle+.4)return {hold:true,kind:f.kind};
  // In a fight the leader shuffles and slots move with it: re-slot only when clearly out of place.
  if((view.engaged.length||now-(b.teamCombatAt||-Infinity)<2000)&&d<=NPC_TEAM_POLICY.combatSettle)return {hold:true,kind:f.kind};
  // Bounded re-slotting: one formation re-target per formationMs while the
  // follower is still close (< 2x settle) or already walking; far ones go now.
  if(now<(b.teamMoveAt||0)&&(p.path?.length||d<NPC_TEAM_POLICY.slotSettle*2))return {hold:true,kind:f.kind};
  b.teamMoveAt=now+NPC_TEAM_POLICY.formationMs;
  npcTeamStats(world).formationMoves++;return {move:f.at,kind:f.kind};
 }
 return null;
}

/** Clears team state on brain when p is no longer in a usable party. */
export const npcTeamFollowerStep=npcTeamMemberStep;
export function npcTeamForget(b){if(!b)return;delete b.teamPull;delete b.teamRegroup;}
