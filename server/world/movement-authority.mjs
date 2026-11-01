// MOVE-NO-RUBBERBAND host side: accept the client's own (predicted) position when it is physically possible, echo it
// without correction, and bump posRev only for real forced displacements or impossible reports.
// Thresholds: src/systems/network/movement-config.js (all ENGINE-CHOSEN, the Global data defines none).
// Movement speed is the unchanged canonical host speed (movement-speed.mjs).
import {MOVEMENT_SYNC as C} from '../../src/systems/network/movement-config.js';
import {canonicalMovementSpeed} from './movement-speed.mjs';

/** Extra intent fields of a client-predicted movement report (move + stop). */
export const MOVEMENT_REPORT_FIELDS=Object.freeze(['px','pz','mseq','prev','mt','qx','qz','qt']);
const bad=text=>{throw Object.assign(new Error(text),{status:400});};
const sceneKey=p=>`${p.map}:${p.instanceId||''}:${p.channel??0}`;
const now=world=>typeof world.now==='function'?world.now():Date.now();

export function hasMovementReport(input){return input&&['px','pz','mseq','prev','mt'].some(key=>input[key]!==undefined);}

/** Per-player movement authority state, created on first use (join, first tick or first snapshot). */
export function movementState(world,p){
  if(!p.mv)p.mv={posRev:0,rejects:0,forced:0,accepted:0,mseq:-1,ackX:p.x,ackZ:p.z,repX:p.x,repZ:p.z,scene:sceneKey(p),budget:Infinity,budgetAt:now(world),
    peakSpeed:0,peakAt:-Infinity,reporting:false,lastReportAt:-Infinity,pt:null,lastMt:null,blockedSince:null};
  return p.mv;
}

/** Anything other than an accepted report or a host path step that moved the player is a forced displacement
 *  (travel, gate, revive, dungeon/event placement, GM summon, knockback): the client must adopt that pose. */
export function trackForcedDisplacement(world,p){
  const mv=movementState(world,p),scene=sceneKey(p);
  if(scene===mv.scene&&Math.abs(p.x-mv.ackX)<=1e-9&&Math.abs(p.z-mv.ackZ)<=1e-9)return false;
  mv.posRev++;mv.forced++;mv.ackX=p.x;mv.ackZ=p.z;mv.repX=p.x;mv.repZ=p.z;mv.scene=scene;mv.pt=null;mv.lastMt=null;mv.via=null;mv.intentMoving=false;mv.budgetAt=Math.max(mv.budgetAt,now(world));
  return true;
}

/** A host path step (legacy intent, or extrapolating a reporter between reports) is ordinary movement, not a forced
 *  displacement. It never moves the reporter's acknowledged pose (repX/repZ). */
export function noteHostStep(world,p){const mv=movementState(world,p);mv.ackX=p.x;mv.ackZ=p.z;mv.scene=sceneKey(p);}

/** SKILL ROOT MOTION (src/systems/skills/root-motion.js): the accepted cast's own clip moved the player by (dx, dz) during
 *  this tick. It is the host's canonical motion, which the caster's client plays from the same curve, not a forced
 *  displacement: posRev stays, the acknowledged/reported pose follows it (the next report is measured from the moved
 *  pose and the curve never spends the client's movement budget), and observers get a time-stamped moving pose. Any
 *  other displacement mixed into the same tick is left to trackForcedDisplacement. Call after the skill tick. */
export function noteSkillRootMotion(world,p,delta){
  const mv=movementState(world,p),t=now(world);
  const dx=Number(delta?.x)||0,dz=Number(delta?.z)||0;
  if(!(Math.abs(dx)>1e-9||Math.abs(dz)>1e-9)){
    // the curve stopped: one still pose at the stop point, so observers end on it instead of extrapolating past it
    if(mv.rootMoving){mv.rootMoving=false;if(mv.reporting){mv.via=null;mv.pt=Math.max(t,Number.isFinite(mv.pt)?mv.pt:-Infinity);}}
    return false;
  }
  if(sceneKey(p)!==mv.scene||Math.abs(p.x-(mv.ackX+dx))>1e-6||Math.abs(p.z-(mv.ackZ+dz))>1e-6){mv.rootMoving=false;return false;}
  const prevX=mv.repX,prevZ=mv.repZ,prevPt=mv.pt;
  mv.ackX=p.x;mv.ackZ=p.z;mv.repX=p.x;mv.repZ=p.z;mv.budgetAt=Math.max(mv.budgetAt,t);mv.rootMoving=true;
  if(mv.reporting){const pt=Math.max(t,Number.isFinite(prevPt)?prevPt:-Infinity);mv.via=Number.isFinite(prevPt)&&pt>prevPt?{t:prevPt,x:prevX,z:prevZ}:null;mv.pt=pt;}
  world.changed?.(p);
  return true;
}

/** Remember when a skill lock / mount cast started, so reports already in flight are not punished. */
export function trackMovementBlock(world,p,blocked){const mv=movementState(world,p);if(!blocked)mv.blockedSince=null;else if(mv.blockedSince==null)mv.blockedSince=now(world);}

/** A client-predicted player is moved only by its reports; the host does not step its path. */
export function reportingMovement(p){return !!p.mv?.reporting;}

/** Reporting player that went quiet is no longer moving for remote viewers (the client stops sending when stopped). */
export function expireIdleReport(world,p){if(p.mv?.reporting&&(p.path.length||p.mv.intentMoving)&&now(world)-p.mv.lastReportAt>idleWindow(p.mv)){p.path=[];p.mv.intentMoving=false;}}
/** Quiet time after which a reporter counts as stopped: REPORT_IDLE_MS, stretched with its own report spacing. */
function idleWindow(mv){return Math.min(C.REPORT_IDLE_MAX_MS,Math.max(C.REPORT_IDLE_MS,C.REPORT_IDLE_SPACING_FACTOR*(Number(mv.spacing)||0)));}

function legitSpeed(world,p,mv,t){
  const speed=Math.max(0,Number(canonicalMovementSpeed(world,p))||0);
  if(speed>=mv.peakSpeed||t-mv.peakAt>C.SPEED_MEMORY_MS){mv.peakSpeed=speed;mv.peakAt=t;}
  return Math.max(speed,mv.peakSpeed);
}
function refill(mv,speed,t){
  const rate=speed*C.SPEED_TOLERANCE,cap=rate*C.BURST_SECONDS;
  // A host wall-clock correction must not credit the same interval twice.
  mv.budget=Math.min(cap,mv.budget+rate*Math.max(0,t-mv.budgetAt)/1000);mv.budgetAt=Math.max(mv.budgetAt,t);
  return mv.budget+C.SLACK_CELLS;
}
function walkableNear(map,x,z){
  if(map.isWalkable(x,z))return true;
  const near=map.collision?.nearestWalkable?.(x,z,3)??map.nearest?.(x,z);
  return !!near&&Number.isFinite(near.x)&&Number.isFinite(near.z)&&Math.hypot(near.x-x,near.z-z)<=C.COLLISION_TOLERANCE_CELLS&&map.isWalkable(near.x,near.z);
}
function travelDistance(map,origin,x,z,limit){
  const p=origin;
  const direct=Math.hypot(x-p.x,z-p.z);
  if(!map.collision?.lineOfSight||map.collision.lineOfSight(p.x,p.z,x,z))return direct;
  // Client wall slides between two reports can bend around a corner: accept a short real path, never a wall pass.
  const path=typeof map.path==='function'?map.path(p.x,p.z,x,z):null;
  if(!Array.isArray(path)||!path.length)return Infinity;
  let length=0,ax=p.x,az=p.z;for(const point of path){length+=Math.hypot(point.x-ax,point.z-az);ax=point.x;az=point.z;if(length>limit)return Infinity;}
  return Math.hypot(ax-x,az-z)<=C.COLLISION_TOLERANCE_CELLS?length+Math.hypot(ax-x,az-z):Infinity;
}

/** Validate and apply one movement report. Returns 'accepted' | 'stale' | 'rejected'. Never throws for physics;
 *  throws 400 only for malformed fields. A rejection bumps posRev so the client adopts the host pose. */
export function applyMovementReport(world,p,map,input,{blocked=false,destination=null,walk=null,rootLocked=false}={}){
  const {px,pz,mseq,prev,mt,qx,qz,qt}=input;
  if(!Number.isFinite(px)||!Number.isFinite(pz))bad('Movement report needs a finite position.');
  if(!Number.isSafeInteger(mseq)||mseq<0)bad('Movement report needs a movement sequence.');
  if(!Number.isSafeInteger(prev)||prev<0)bad('Movement report needs the last correction revision.');
  if(mt!==undefined&&!Number.isFinite(mt))bad('Movement report time must be a number.');
  if([qx,qz,qt].some(v=>v!==undefined&&!Number.isFinite(v)))bad('Movement report previous point must be finite.');
  const t=now(world);
  trackForcedDisplacement(world,p);
  const mv=movementState(world,p);
  // Sent before the client saw a forced displacement, or overtaken by a newer report: ignore, never punish.
  if(prev!==mv.posRev||mseq<=mv.mseq)return 'stale';
  // A NO_CANCEL skill clip is carrying the body along its root curve: a report arriving now left the client before the
  // cast moved it (the caster's own client does not move during that phase). Ignored, never punished.
  if(rootLocked)return 'stale';
  mv.reporting=true;
  const speed=legitSpeed(world,p,mv,t),allowance=refill(mv,speed,t);
  // Distances are measured from the last ACCEPTED report, never from the host's extrapolated pose.
  const origin={x:mv.repX,z:mv.repZ},d=Math.hypot(px-origin.x,pz-origin.z);
  const reject=()=>{mv.posRev++;mv.rejects++;mv.mseq=mseq;mv.pt=null;mv.lastMt=null;mv.via=null;mv.intentMoving=false;p.path=[];p.x=mv.repX;p.z=mv.repZ;mv.ackX=p.x;mv.ackZ=p.z;return 'rejected';};
  let travel=0;
  if(d>1e-9){
    const graced=mv.blockedSince!=null&&t-mv.blockedSince<=C.BLOCK_GRACE_MS;
    if(p.dead||(blocked&&!graced))return reject();
    if(d>allowance||!walkableNear(map,px,pz))return reject();
    travel=travelDistance(map,origin,px,pz,allowance);
    if(!(travel<=allowance))return reject();
  }
  const face=destination&&Math.hypot(destination.x-px,destination.z-pz)>1e-3?destination:(d>1e-6?{x:px+(px-origin.x),z:pz+(pz-origin.z)}:null);
  if(face)p.yaw=Math.atan2(-(face.x-px),-(face.z-pz));
  // Pose time for remote interpolation: the mover's own send spacing, anchored to host arrival (bounded lead/lag).
  const gap=t-mv.lastReportAt;
  let pt=mv.pt==null||gap>Math.max(500,idleWindow(mv))||!Number.isFinite(mt)||!Number.isFinite(mv.lastMt)?t:mv.pt+Math.max(0,Math.min(1000,mt-mv.lastMt));
  pt=Math.max(Math.min(pt,t+C.POSE_TIME_MAX_LEAD_MS),t-C.POSE_TIME_MAX_LAG_MS);if(mv.pt!=null)pt=Math.max(pt,mv.pt);
  // Observers only see the newest report per host tick, and a report overtaken in transport is never applied, so
  // the published row also carries the point before it (via): the previous accepted report, or, when that report
  // is missing, the client's own previous point (qx,qz,qt) if it lies inside this report's movement allowance.
  let via=mv.pt!=null&&pt>mv.pt?{t:mv.pt,x:origin.x,z:origin.z}:null;
  if(mseq>mv.mseq+1&&mv.pt!=null&&[qx,qz,qt,mt,mv.lastMt].every(Number.isFinite)&&qt>mv.lastMt&&qt<mt){
    const vt=pt-(mt-qt);
    if(vt>mv.pt&&vt<pt&&Math.hypot(qx-origin.x,qz-origin.z)+Math.hypot(px-qx,pz-qz)<=allowance+C.SLACK_CELLS&&walkableNear(map,qx,qz))via={t:vt,x:qx,z:qz};
  }
  mv.via=via;
  // arrival spacing, peak-held with a slow decay: a slower cadence (slow link) widens the idle window at once
  if(gap>0&&gap<C.REPORT_IDLE_MAX_MS)mv.spacing=Math.max(gap,(Number(mv.spacing)||0)*0.9);
  mv.pt=pt;mv.lastMt=Number.isFinite(mt)?mt:null;mv.lastReportAt=t;mv.mseq=mseq;mv.accepted++;
  // Rounding slack is a bounded debt, not a fresh movement grant on every packet.
  // Clamping at zero lets many small reports repeatedly spend SLACK_CELLS without elapsed host time.
  mv.budget-=travel;
  const moved=Math.abs(p.x-px)>1e-9||Math.abs(p.z-pz)>1e-9;p.x=px;p.z=pz;if(moved)world.changed?.(p);
  mv.ackX=p.x;mv.ackZ=p.z;mv.repX=px;mv.repZ=pz;mv.scene=sceneKey(p);
  if(destination){p.walk=walk||null;p.path=blocked||p.dead?[]:[{x:destination.x,z:destination.z}];}
  // The reporter's own intent: still moving until its stop/arrival report (or idle), even when the host's path step
  // between reports already reached the destination, so observers never see a stop a report before the real one.
  mv.intentMoving=!!destination&&!blocked&&!p.dead&&Math.hypot(destination.x-px,destination.z-pz)>1e-3;
  return 'accepted';
}

/** Fields of the player's own row: correction revision, anti-cheat rejections, last applied sequence, host mode. */
export function movementSelf(world,p){
  const mv=movementState(world,p);
  return {posRev:mv.posRev,posRejects:mv.rejects,mseq:mv.mseq,reporting:mv.reporting};
}
/** Field of every published row: pose time of a client-predicted mover (remote buffered interpolation). */
export function movementPublic(p){
  if(!p.mv?.reporting||!Number.isFinite(p.mv.pt))return null;
  const row={pt:p.mv.pt,x:p.mv.repX,z:p.mv.repZ,moving:!p.dead&&(p.path.length>0||!!p.mv.intentMoving||!!p.mv.rootMoving)};if(p.mv.via)row.via=[p.mv.via.t,p.mv.via.x,p.mv.via.z];return row;
}
