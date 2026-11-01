// LANE3 navigation lease for server-owned NPC players: path reuse, cheap step
// validation and bounded stuck recovery. Advisory only: it decides whether the
// bot's director should issue an ordinary {type:'move'} (the native authority
// still pathfinds, validates walkability/LOS on every step and rate-limits);
// it never writes an actor position, so it cannot teleport or pass a wall.
//
// Walkable cells are mutated in place by several systems without a signal, so
// a long-lived path cache is not trusted: before reusing the actor's current
// native path we re-check the next two path cells (walkable + line of sight).
// Kill switch: world.npcNav=false or DEKARON_NPC_NAV=0 (or DEKARON_NPC_TEAM=0).
import {sceneKey} from './scene.mjs';
import {skillControls} from './skills.mjs';

export const NPC_NAV_POLICY=Object.freeze({
 reuseFraction:.25,reuseMin:.7,reuseMax:4,  // a goal drift under max(min, fraction*remaining) keeps the path
 progress:.5,stuckMs:2500,arrive:1.1,       // < progress units in stuckMs while a path is wanted = stuck
 noCloserMs:8000,                           // moving but never closer to the same goal this long = oscillating (stuck)
 ring:[1.6,2.6,3.6],crumbBack:[3,6],        // alternative approach radii; backtrack distance
 backoffMs:2000,backoffMaxMs:30000,         // give-up cool-down doubles per failure on the same goal
 crumbs:24,log:64,samples:256,
});
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
export function npcNavEnabled(world){
 if(typeof world?.npcNav==='boolean')return world.npcNav;
 if(typeof world?.npcTeam==='boolean'&&!world.npcTeam)return false;
 return process.env.DEKARON_NPC_NAV!=='0'&&process.env.DEKARON_NPC_TEAM!=='0';
}
export function npcNavStats(world){
 return world._npcNavStats||(world._npcNavStats={calls:0,reuse:0,issued:0,refused:0,invalidScene:0,invalidTarget:0,invalidDest:0,stepInvalid:0,pathDropped:0,stuck:0,recoveryIssued:0,recovered:0,gaveUp:0,blockedByGiveUp:0,recoveryMs:[]});
}
function log(world,p,reason,extra){const l=world._npcNavLog||(world._npcNavLog=[]);l.push({at:world.now(),id:p.id,reason,...extra});if(l.length>NPC_NAV_POLICY.log)l.splice(0,l.length-NPC_NAV_POLICY.log);}
const walk=(map,a)=>!!map.isWalkable?.(a.x,a.z);
const los=(map,a,b)=>!map.collision?.lineOfSight||map.collision.lineOfSight(a.x,a.z,b.x,b.z);
function nextStepValid(map,p){
 const a=p.path[0],b=p.path[1];
 if(!a||!walk(map,a)||!los(map,p,a))return false;
 return !b||walk(map,b)&&los(map,a,b);
}
function immobile(p){if(p._skills?.engine?.casting)return true;try{return !!skillControls(p).move;}catch{return false;}}

function lease(b){return b.navLease||(b.navLease={scene:null,goal:null,at:null,targetId:null,issuedAt:0,lastPos:null,lastProgressAt:0,lastCallAt:0,stage:0,stuckAt:null,recover:null,crumbs:[],giveUp:null,fails:0});}
function resetProgress(L,p,now){L.lastPos={x:p.x,z:p.z};L.lastProgressAt=now;}
function resetRoute(L){L.goal=null;L.at=null;L.stage=0;L.recover=null;L.bestD=null;}

/** Before the director issues a move toward `goal` (already snapped walkable).
 * Returns {reuse:true} (keep the current native path), {blocked:true,reason}
 * (bounded give-up cool-down), or {at,force} (issue an ordinary move to `at`;
 * force = drop the caller's own "same intent" shortcut). */
export function npcNavBeforeMove(world,p,b,goal,{map,targetId=null,tight=false}={}){
 if(!b||!map||!npcNavEnabled(world))return {at:goal};
 const S=npcNavStats(world),L=lease(b),now=world.now(),scene=sceneKey(p.map,p.instanceId,p.channel||0);S.calls++;
 if(L.scene!==scene){if(L.scene!=null)S.invalidScene++;L.scene=scene;resetRoute(L);L.stage=0;L.crumbs=[];L.giveUp=null;L.targetId=targetId;resetProgress(L,p,now);}
 // A different target is a different route: new progress window and ladder.
 if((L.targetId??null)!==(targetId??null)){if(L.goal)S.invalidTarget++;resetRoute(L);L.stage=0;L.targetId=targetId;resetProgress(L,p,now);}
 // Progress is judged only over continuous demand: a bot that stopped asking to
 // move (fighting in reach, waiting) restarts its window when it asks again.
 if(now-L.lastCallAt>1000)resetProgress(L,p,now);L.lastCallAt=now;
 // breadcrumbs of real (authority-stepped) progress, for backtracking
 const c=L.crumbs.at(-1);if(!c||distance(c,p)>=1){L.crumbs.push({x:p.x,z:p.z});if(L.crumbs.length>NPC_NAV_POLICY.crumbs)L.crumbs.shift();}
 if(L.giveUp&&now<L.giveUp.until&&distance(L.giveUp.goal,goal)<2&&(L.giveUp.targetId??null)===(targetId??null)){S.blockedByGiveUp++;return {blocked:true,reason:'gave-up'};}
 // A destination that moved too far invalidates the path (the ladder stage of
 // this same target is kept, so a chase behind a wall still escalates).
 if(L.goal){const remaining=distance(p,L.goal),tol=tight?.2:Math.min(NPC_NAV_POLICY.reuseMax,Math.max(NPC_NAV_POLICY.reuseMin,NPC_NAV_POLICY.reuseFraction*remaining));if(distance(goal,L.goal)>tol&&!L.recover){S.invalidDest++;L.goal=null;L.at=null;L.bestD=null;}}
 // progress / stuck detection over the same target
 const moved=distance(p,L.lastPos)>=NPC_NAV_POLICY.progress;
 if(moved||immobile(p)){
  if(moved&&L.stuckAt!=null){S.recovered++;S.recoveryMs.push(now-L.stuckAt);if(S.recoveryMs.length>NPC_NAV_POLICY.samples)S.recoveryMs.shift();L.stuckAt=null;}
  resetProgress(L,p,now);
 }
 if(distance(p,goal)<=NPC_NAV_POLICY.arrive){resetRoute(L);L.stage=0;L.fails=0;resetProgress(L,p,now);return {at:goal};}

 const target=L.recover||L.at;
 if(L.recover&&distance(p,L.recover)<=NPC_NAV_POLICY.arrive){L.recover=null;L.goal=null;L.at=null;return {at:goal,force:true};}   // recovery point reached: retry the real goal
 if(!p.path.length&&target&&!L.recover&&distance(p,target)<=NPC_NAV_POLICY.arrive){resetProgress(L,p,now);return {at:goal};}      // reached the issued (snapped) point
 const dropped=!!(L.goal&&!p.path.length&&target&&now-L.issuedAt>400);
 // Net progress: walking back and forth (a path loop the server keeps
 // re-issuing, e.g. towards a goal in a disconnected area) moves the actor but
 // never brings it closer; that is stuck too.
 const dg=distance(p,goal);if(L.bestD==null||dg<L.bestD-NPC_NAV_POLICY.progress||immobile(p)){L.bestD=Math.min(dg,L.bestD??dg);L.bestAt=now;}
 const looping=dg>NPC_NAV_POLICY.arrive*2&&now-L.bestAt>=NPC_NAV_POLICY.noCloserMs;
 if(looping){S.looping=(S.looping||0)+1;L.bestAt=now;L.bestD=dg;}
 const stalled=looping||now-L.lastProgressAt>=NPC_NAV_POLICY.stuckMs;
 if(stalled||dropped){
  if(stalled){S.stuck++;L.stuckAt??=now;}else S.pathDropped++;
  L.lastProgressAt=now;L.lastPos={x:p.x,z:p.z};
  const avoid=b.navAvoid&&world.now()-b.navAvoid.at<1000?b.navAvoid.fn:null;
  return recover(world,p,L,goal,map,targetId,stalled?'no-progress':'path-dropped',avoid);
 }
 if(!L.goal)return {at:goal,fresh:true};
 // reuse the active native path while its next cells are still valid
 if(p.path.length){
  if(!nextStepValid(map,p)){S.stepInvalid++;log(world,p,'step-invalid',{});return {at:L.recover||goal,force:true};}
  if(!L.recover&&!tight){S.reuse++;return {reuse:true};}
 }
 return {at:L.recover||goal};
}
function recover(world,p,L,goal,map,targetId,reason,avoid=null){
 const S=npcNavStats(world);L.stage++;
 if(L.stage===1){S.recoveryIssued++;log(world,p,reason,{stage:1,action:'repath'});return {at:goal,force:true};}
 if(L.stage===2){
  // alternative approach cell around the goal, approaching from another side
  const from=Math.atan2(p.z-goal.z,p.x-goal.x);
  // first pass skips cells inside a different idle pack's aggro (team view, when fresh); second pass takes any
  for(const pass of avoid?[0,1]:[1])for(const r of NPC_NAV_POLICY.ring)for(let k=1;k<=6;k++){const a=from+(k%2?1:-1)*Math.ceil(k/2)*Math.PI/3.5,pt={x:goal.x+Math.cos(a)*r,z:goal.z+Math.sin(a)*r};if(walk(map,pt)&&los(map,pt,goal)&&distance(pt,p)>.8&&(pass||!avoid(pt))){L.recover=pt;S.recoveryIssued++;log(world,p,reason,{stage:2,action:'alternate'});return {at:pt,force:true};}}
  L.stage=3;
 }
 if(L.stage===3){
  for(const pass of avoid?[0,1]:[1])for(let i=L.crumbs.length-1;i>=0;i--){const c=L.crumbs[i],d=distance(c,p);if(d>=NPC_NAV_POLICY.crumbBack[0]&&d<=NPC_NAV_POLICY.crumbBack[1]&&walk(map,c)&&(pass||!avoid(c))){L.recover={x:c.x,z:c.z};S.recoveryIssued++;log(world,p,reason,{stage:3,action:'backtrack'});return {at:L.recover,force:true};}}
  L.stage=4;
 }
 // give up on this goal for a bounded, growing cool-down
 L.fails++;const ms=Math.min(NPC_NAV_POLICY.backoffMaxMs,NPC_NAV_POLICY.backoffMs*2**(L.fails-1));
 L.giveUp={goal:{x:goal.x,z:goal.z},targetId,until:world.now()+ms};S.gaveUp++;L.stuckAt=null;log(world,p,reason,{stage:4,action:'give-up',ms});
 resetRoute(L);return {blocked:true,reason:'gave-up',stop:true};
}
/** After the director's ordinary move was accepted (ok) or refused. */
export function npcNavAfterMove(world,p,b,{goal,at,ok,targetId=null}={}){
 if(!b||!npcNavEnabled(world))return;
 const S=npcNavStats(world),L=lease(b),now=world.now();
 if(!ok){S.refused++;return;}
 S.issued++;
 if(!L.recover||distance(L.recover,at)>.05)L.goal={x:goal.x,z:goal.z};
 L.at={x:at.x,z:at.z};L.issuedAt=now;
}
/** Drop the route (membership/scene change, death, explicit stop). */
export function npcNavForget(b){if(b?.navLease)resetRoute(b.navLease);}
