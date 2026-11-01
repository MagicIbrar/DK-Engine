// MOVE-NO-RUBBERBAND client side. The local player is client-predicted: it moves at the host's canonical speed with
// local collision and reports where it is; host echoes of those reports are acknowledged WITHOUT moving the body.
// Only a host posRev bump (forced displacement / impossible report) moves the body to the host pose.
// Remote client-predicted players render from a time-stamped buffer (smooth interpolation, short extrapolation).
// Tunables: ./movement-config.js (ENGINE-CHOSEN).
import {MOVEMENT_SYNC as C} from './movement-config.js';
import {REMOTE_LOCOMOTION_CHOSEN as L} from '../../config/engine-chosen-anim-loop.js';

/** Clip state of a remote body from its shown motion. A body that was walking / running keeps its walk / run clip for L.stopHoldMs
 *  after the shown position stops changing: a host pose that is a frame or two late (jitter, a 200 ms tween that ran out) must not
 *  drop it to the stand clip and restart the stride a moment later. A real stop still ends in `rest` (ENGINE-CHOSEN hold). */
export function remoteLocomotionState(actor,moving,walk,now,rest){
  if(moving){actor._shownMovingAt=now;return walk?'walk':'run';}
  const held=actor.state==='walk'||actor.state==='run';
  return held&&Number.isFinite(actor._shownMovingAt)&&now>=actor._shownMovingAt&&now-actor._shownMovingAt<L.stopHoldMs?actor.state:rest;
}

/** Put a remote body on its shown pose. PERF: a remote that has not moved since the last frame (most monsters, every frame) used to be
 *  re-placed anyway: Actor.setPosition re-ran the terrain height lookup, rewrote the group transform and un-froze the animation-LOD
 *  freeze (actors/actor.js "it moves again"), which Actor.update then froze again in the same frame. When the shown x / z are bit-equal to
 *  the body's, the body is already grounded and no knockback owns it, setPosition could only repeat what the previous frame did: skip it.
 *  What changes: the ground height of a body that stands still is re-checked by Actor.update's own 0.5 s timer instead of every frame
 *  (ENGINE-CHOSEN: a terrain / bridge change under a motionless remote shows up <= 0.5 s later; nothing else differs).
 *  `globalThis.__dekaronLegacyRemotePlacement = true` restores the call every frame (A/B measurement, tools/test-remote-placement-skip.mjs). */
export function placeRemote(actor,x,z){
  if(x===actor.x&&z===actor.z&&actor._grounded===true&&!actor._knockback&&!globalThis.__dekaronLegacyRemotePlacement)return;
  actor.setPosition(x,z);
}

/** Smoothed host clock: the least-delayed snapshot defines the offset (max filter, slow decay), so network jitter
 *  never makes the remote render clock run backwards. */
export class ServerClockFilter {
  constructor(){this.offset=null;this.at=null;}
  sample(serverTime,local){
    if(!Number.isFinite(serverTime)||!Number.isFinite(local))return;
    const offset=serverTime-local;
    if(this.offset==null||Math.abs(offset-this.offset)>5000){this.offset=offset;this.at=local;return;}
    const decayed=this.offset-Math.max(0,local-this.at)*0.001;   // follows clock drift of up to 1 ms/s
    this.offset=Math.max(offset,decayed);this.at=local;
  }
  ready(){return this.offset!=null;}
  now(local){return this.offset==null?local:local+this.offset;}
}

/** How long before its first moving pose a remote that stood still is assumed to have set off (ms). */
function startLead(d){return Math.max(C.SEND_INTERVAL_MS/4,Math.min(C.SEND_INTERVAL_MS*2,d/C.REMOTE_START_SPEED*1000));}

/** Time-stamped remote pose buffer (row.pt = host pose time of a client-predicted mover). */
export class RemoteMotion {
  constructor(){this.samples=[];this.lastPt=-Infinity;this.delay=C.INTERP_DELAY_START_MS;this.late=[];this.renderT=null;this.wall=null;this.pos=null;}
  push(row,clockNow,from=null){
    const t=Number(row.pt);if(!Number.isFinite(t)||!Number.isFinite(row.x)||!Number.isFinite(row.z))return;
    let last=this.samples.at(-1);
    if(t<this.lastPt)return;                                       // an older response/stream reordering
    const sample={t,x:row.x,z:row.z,moving:!!row.moving,walk:row.walk==='peace'||row.walk==='battle'};
    // Same pose re-published by a later tick: the host's own path may have ended (it only extrapolates between
    // reports), which says nothing about the mover; keep the moving state the pose was first published with.
    if(t===this.lastPt){if(last){last.walk=sample.walk;if(Math.hypot(last.x-row.x,last.z-row.z)>1e-9){last.x=row.x;last.z=row.z;}}return;}
    if(last){const d=Math.hypot(row.x-last.x,row.z-last.z);if(d>C.TELEPORT_CELLS&&d/Math.max(.001,(t-last.t)/1000)>80){this.samples=[];this.renderT=null;last=null;}}
    // Via point published by the host (the point before this pose, which observers may not have seen yet).
    const via=Array.isArray(row.via)&&row.via.length===3&&row.via.every(Number.isFinite)&&last&&row.via[0]>last.t&&row.via[0]<t?{t:row.via[0],x:row.via[1],z:row.via[2]}:null;
    // A mover that stood still (stop report) and starts again: keep it standing until shortly before its first new
    // point, instead of crawling across the whole pause.
    const first=via||{t,x:row.x,z:row.z};
    if(last&&!last.moving){const lead=startLead(Math.hypot(first.x-last.x,first.z-last.z));if(first.t-last.t>lead*1.5)this.samples.push({t:first.t-lead,x:last.x,z:last.z,moving:false,walk:last.walk});}
    if(via)this.samples.push({t:via.t,x:via.x,z:via.z,moving:true,walk:sample.walk});
    // Buffer sizing uses the previous pose time: the render clock must not pass it before this pose arrives
    // (covers report spacing, host tick wait, transport jitter and holes left by reordered reports).
    const prior=this.samples.at(-1);
    const prevT=prior?prior.t:null;
    // First buffered pose of an actor already on screen: start from where it is shown, one host tick earlier,
    // instead of jumping onto the first sample and waiting there.
    if(!this.samples.length&&from&&Number.isFinite(from.x)&&Number.isFinite(from.z)){const d=Math.hypot(from.x-row.x,from.z-row.z);
      if(d>1e-6&&d<C.TELEPORT_CELLS)this.samples.push({t:t-startLead(d),x:from.x,z:from.z,moving:false,walk:sample.walk});}
    this.samples.push(sample);this.lastPt=t;if(this.samples.length>40)this.samples.splice(0,this.samples.length-40);
    // adaptive buffer: how late (vs the smoothed host clock) poses arrive, worst of the last few seconds, plus a margin
    if(Number.isFinite(clockNow)){this.late.push({at:clockNow,v:clockNow-(prevT??t)});while(this.late.length&&clockNow-this.late[0].at>C.INTERP_MEMORY_MS)this.late.shift();
      // headroom grows with the observed spread, because the next spike can exceed the worst one seen so far
      let worst=-Infinity,best=Infinity;for(let i=0;i<this.late.length;i++){const v=this.late[i].v;if(v>worst)worst=v;if(v<best)best=v;}const spread=worst-best;   // lane-core: same max/min as before without two arrays per pose
      this.delay=Math.max(C.INTERP_DELAY_MIN_MS,this.late.length<C.INTERP_WARMUP_SAMPLES?C.INTERP_DELAY_START_MS:0,Math.min(C.INTERP_DELAY_MAX_MS,worst+C.INTERP_DELAY_MARGIN_MS+C.INTERP_SPREAD_HEADROOM*spread));}
  }
  active(){return this.samples.length>0;}
  /** Render clock slews toward clock-delay (slows by up to 25 %, catches up by up to 10 %), never moving a remote backwards. */
  _render(clockNow,wallNow){
    const desired=clockNow-this.delay;
    if(this.renderT==null||!Number.isFinite(this.wall)||Math.abs(desired-this.renderT)>1000)this.renderT=desired;
    else{const dt=Math.max(0,wallNow-this.wall),err=desired-(this.renderT+dt);this.renderT+=dt+Math.max(-C.RENDER_SLOW_RATE*dt,Math.min(C.RENDER_FAST_RATE*dt,err));}
    this.wall=wallNow;return this.renderT;
  }
  sample(clockNow,wallNow){
    const s=this.samples;if(!s.length)return null;
    const t=this._render(clockNow,wallNow);
    while(s.length>2&&s[1].t<=t-1000)s.shift();
    if(t<=s[0].t)return {x:s[0].x,z:s[0].z,moving:false,walk:s[0].walk};
    for(let i=0;i<s.length-1;i++){const a=s[i],b=s[i+1];if(t<=b.t){const u=(t-a.t)/Math.max(1e-6,b.t-a.t);return {x:a.x+(b.x-a.x)*u,z:a.z+(b.z-a.z)*u,moving:true,walk:b.walk};}}
    const last=s.at(-1),prev=s.at(-2),ahead=t-last.t;
    if(last.moving&&prev&&ahead<=C.EXTRAPOLATE_MS&&last.t>prev.t){const k=ahead/(last.t-prev.t);return {x:last.x+(last.x-prev.x)*k,z:last.z+(last.z-prev.z)*k,moving:true,walk:last.walk,extrapolated:true};}
    if(last.moving&&prev&&last.t>prev.t){const k=C.EXTRAPOLATE_MS/(last.t-prev.t);return {x:last.x+(last.x-prev.x)*k,z:last.z+(last.z-prev.z)*k,moving:false,walk:last.walk,extrapolated:true};}
    return {x:last.x,z:last.z,moving:false,walk:last.walk};
  }
  /** Place a remote actor at its buffered pose and keep its locomotion clip in step. */
  apply(actor,clockNow,wallNow,rest='idleCombat'){
    let pose=this.sample(clockNow,wallNow);if(!pose)return false;
    // Overshoot guard: after extrapolating past the newest pose, a late sample must not pull the remote back.
    // Hold still until the buffered path passes the shown point (bounded by OVERSHOOT_HOLD_MS).
    const out=this.out,dir=this.dir;
    if(out&&dir&&(this.extrapolated||this.holdSince!=null)&&!pose.extrapolated){
      const bx=pose.x-out.x,bz=pose.z-out.z,back=bx*dir.x+bz*dir.z;
      const gap=Math.hypot(bx,bz),approaching=this.holdGap==null||gap<this.holdGap+1e-6;
      if(back<-1e-6&&gap<C.TELEPORT_CELLS&&approaching){if(this.holdSince==null)this.holdSince=wallNow;if(wallNow-this.holdSince<C.OVERSHOOT_HOLD_MS){this.holdGap=gap;pose={x:out.x,z:out.z,moving:true,walk:pose.walk,held:true};}}
    }
    if(!pose.held){this.holdSince=null;this.holdGap=null;}
    this.extrapolated=!!pose.extrapolated;
    if(out){const mx=pose.x-out.x,mz=pose.z-out.z,ml=Math.hypot(mx,mz);if(ml>1e-6)this.dir={x:mx/ml,z:mz/ml};}
    this.out={x:pose.x,z:pose.z};
    const moving=Math.hypot(pose.x-actor.x,pose.z-actor.z)>0.001;
    if(!actor.dead&&moving&&!Number.isFinite(actor._serverYaw))actor.faceTowards?.(pose.x,pose.z);
    placeRemote(actor,pose.x,pose.z);
    if(!actor.dead&&(actor._networkAnimHold||0)<=wallNow){const state=remoteLocomotionState(actor,moving,pose.walk,wallNow,rest);if(actor.state!==state)actor.play(state);}
    return true;
  }
}

// ------------------------------------------------------------------------------------------- local player helpers
/** Client-predicted mode is on when the host publishes the movement sync revision for our own row. */
export function syncActive(net){return Number.isInteger(net?.self?.posRev);}
function state(net){
  if(!net._moveSync)net._moveSync={seq:0,posRev:Number(net.self?.posRev)||0,rejects:Number(net.self?.posRejects)||0,sent:new Map(),ackedSeq:-1,ackedSentAt:performance.now(),
    corrections:0,forced:0,acks:0,moving:false,holdUntil:0,lastSendAt:-Infinity,lastSent:null,lastHeading:null};
  return net._moveSync;
}
export function moveSyncState(net){return state(net);}
/** The host says a skill lock or a mount summon/dismiss cast holds the body: do not predict or send movement. */
export function syncMoveBlocked(net){const self=net.self;return !!(net._settling||self?.moveBlocked||['summoning','dismissing'].includes(self?.mount?.phase));}
/** Report fields of a move/stop intent: where the body really is, in which order, after which correction. */
export function movementReport(net,now=performance.now()){
  const ms=state(net),p=net.game.player,mseq=++ms.seq;
  ms.sent.set(mseq,now);if(ms.sent.size>64)for(const key of ms.sent.keys()){if(ms.sent.size<=64)break;ms.sent.delete(key);}
  // mt: the client's own monotonic clock. The host only uses differences between reports to stamp pose times,
  // so snapshot arrival jitter can never bend the published motion timeline.
  const clock=now;
  // The previous report's point rides along, so the host can fill the gap if that report is overtaken in transport.
  const q=ms.lastSent&&Number.isFinite(ms.lastSentMt)?{qx:ms.lastSent.x,qz:ms.lastSent.z,qt:ms.lastSentMt}:null;
  const mt=Math.floor(clock);
  ms.lastSendAt=now;ms.lastSent={x:p.x,z:p.z};ms.lastSentMt=mt;
  return q?{px:p.x,pz:p.z,mseq,prev:ms.posRev,mt,...q}:{px:p.x,pz:p.z,mseq,prev:ms.posRev,mt};
}
/** Should a (possibly identical-destination) move be sent now? Periodic while the body moves, early on a turn. */
export function syncShouldSend(net,x,z,now,walk){
  const ms=state(net),p=net.game.player;
  const sinceSend=now-ms.lastSendAt,heading=Math.atan2(x-p.x,z-p.z);
  const moved=!ms.lastSent||Math.hypot(p.x-ms.lastSent.x,p.z-ms.lastSent.z)>0.01;
  const sameDest=net._lastMove&&Math.hypot(x-net._lastMove.x,z-net._lastMove.z)<0.03&&(net._lastMove.walk||null)===walk;
  let turn=false;if(ms.lastHeading!=null&&Math.hypot(x-p.x,z-p.z)>0.05){let d=Math.abs(heading-ms.lastHeading);if(d>Math.PI)d=2*Math.PI-d;turn=d>0.35;}
  // Round trip: the slower of the movement answers and the link's other requests, and at least the age of the oldest
  // report still in flight, so a link that just slowed down spaces its reports at once instead of bunching them on a
  // stale fast-link estimate (live check 0 -> 300 ms: three reports in 230 ms, then a 600 ms gap the observers saw).
  let rtt=Math.max(Number.isFinite(ms.rtt)?ms.rtt:-1,Number.isFinite(Number(net._linkRtt))?Number(net._linkRtt):-1);
  if(ms.flights?.size){let oldest=Infinity;for(const f of ms.flights)oldest=Math.min(oldest,f.t0);rtt=Math.max(rtt,performance.now()-oldest);}
  if(!(rtt>=0))rtt=NaN;
  const interval=Math.max(C.SEND_INTERVAL_MS,Number.isFinite(rtt)?rtt/C.SEND_INTERVAL_RTT_DIVISOR:0);
  // A saturated link gets no further report (the next one carries the newer pose), except that a turn may use one
  // extra slot, so observers get the corner instead of a cut chord.
  const inflight=ms.inflight||0;
  if(turn&&sinceSend>=C.MIN_SEND_SPACING_MS&&inflight<=C.MAX_INFLIGHT_REPORTS){ms.lastHeading=heading;return true;}
  if(inflight>=C.MAX_INFLIGHT_REPORTS)return false;
  if(sinceSend>=interval&&(moved||!sameDest)){ms.lastHeading=heading;return true;}
  return false;
}
/** Physically possible lead over the last acknowledged report (never reached by legit movement). */
export function syncLeadAllows(net,nx,nz,now=performance.now()){
  const ms=state(net),p=net.game.player,self=net.self;
  // Speed can drop (buff expiry, dismount) while reports sent at the old speed are still in flight: remember the
  // peak for SPEED_MEMORY_MS, exactly like the host's budget does.
  const current=Math.max(Number(p?.groundSpeed?.('run'))||0,Number(self?.moveSpeed)||0,0.1);
  if(!(current<(ms.peakSpeed||0))||now-(ms.peakAt??-Infinity)>C.SPEED_MEMORY_MS){ms.peakSpeed=current;ms.peakAt=now;}
  const speed=Math.max(current,ms.peakSpeed);
  const since=Math.max(0,now-ms.ackedSentAt)/1000;
  // Measured from the pose that came with the newest acknowledgement: an older action response that arrives after a
  // newer stream snapshot must not shrink the allowance.
  const base=ms.ackPos||self;
  return Math.hypot(nx-base.x,nz-base.z)<=speed*C.LEAD_SPEED_FACTOR*since+C.LEAD_BASE_CELLS;
}
/** Own-row snapshot in client-predicted mode. Returns true when handled (acknowledged or corrected). */
export function syncSelfSnapshot(net,self,now,setServerPose){
  if(!Number.isInteger(self?.posRev))return false;
  const ms=state(net),p=net.game.player;
  if(Number.isInteger(self.mseq)&&self.mseq>ms.ackedSeq){ms.ackedSeq=self.mseq;ms.ackPos={x:self.x,z:self.z};const sent=ms.sent.get(self.mseq);if(Number.isFinite(sent))ms.ackedSentAt=sent;for(const key of [...ms.sent.keys()])if(key<=self.mseq)ms.sent.delete(key);}
  if(self.posRev!==ms.posRev){
    const rejected=(Number(self.posRejects)||0)>ms.rejects;
    ms.posRev=self.posRev;ms.rejects=Number(self.posRejects)||0;ms.corrections++;if(!rejected)ms.forced++;ms.ackedSentAt=now;ms.ackPos={x:self.x,z:self.z};   // the displaced host pose is the new lead base (revive, travel, knockback)
    net._lastMove=null;net._localStopped=false;net._stopServer=null;net._predictionAt=-Infinity;net._predictionIntentAt=-Infinity;
    if(rejected){setServerPose(p,self,now,true);p.setPosition(self.x,self.z);p._serverPose=null;}   // impossible report: the host pose wins now
    else{setServerPose(p,self,now,false);ms.holdUntil=now+((p._serverPose&&Math.hypot(self.x-p.x,self.z-p.z)>1e-6)?200:0);}  // forced displacement: shown (tween <=10 cells, else placed)
    return true;
  }
  // Echo of our reports, or a host snapshot taken before our in-flight reports arrived: never pull the body back.
  if((self.reporting||ms.seq>0&&ms.seq>(Number.isInteger(self.mseq)?self.mseq:-1))&&!self.dead&&!p.dead){
    // our own report echoed back: acknowledged. Vitals/level/name still sync; position and facing stay local.
    const yaw=p._yawGoal;setServerPose(p,self,now,true);p._serverPose=null;p._yawGoal=yaw;ms.acks++;return true;
  }
  return false;                                                                       // host-driven intent: legacy reconciliation
}
/** A stop report that never got through (transport error) is re-sent once the body is still, so the host pose
 *  cannot stay behind the client. Returns true when a resync report should go out now. */
export function syncNeedsResync(net,now=performance.now()){
  if(!syncActive(net)||!net._moveSync)return false;
  const ms=net._moveSync,p=net.game?.player;
  // The host refuses every movement report while the body is dead ("Revive before acting."): death drops the
  // pending reports, nothing is re-sent until revive, then a single resync pins the host to the revived body.
  if(syncDead(net)){if(!ms.dead){ms.dead=true;ms.reviveResync=false;syncForgetPending(ms);}return false;}
  if(ms.dead){ms.dead=false;ms.reviveResync=true;}
  if(ms.reviveResync){
    if(ms.moving){ms.reviveResync=false;return false;}                     // the first move report already resyncs
    if(net._settling||p?._serverPose||now<(ms.holdUntil||0))return false;  // wait until a revive displacement is shown
    ms.reviveResync=false;return ms.seq>0;
  }
  // only when nothing is in flight: an answer still on its way would ack it, and a resync must not overtake it
  return !ms.moving&&ms.seq>ms.ackedSeq&&!(ms.inflight>0)&&now-ms.lastSendAt>500&&!net._settling;
}
/** Count one movement request in flight until it settles (answer, refusal or transport error). */
export function syncTrack(net,promise){const ms=state(net),t0=performance.now(),flight={t0};ms.inflight=(ms.inflight||0)+1;(ms.flights||=new Set()).add(flight);
  return Promise.resolve(promise).finally(()=>{ms.inflight=Math.max(0,ms.inflight-1);ms.flights.delete(flight);const rtt=performance.now()-t0;
    if(rtt>=0&&rtt<15000)ms.rtt=Number.isFinite(ms.rtt)?ms.rtt*0.8+rtt*0.2:rtt;});}   // smoothed movement round trip
/** Dead on the host or locally: no movement report may go out. */
export function syncDead(net){return !!(net?.self?.dead||net?.game?.player?.dead);}
function syncForgetPending(ms){ms.moving=false;ms.lastHeading=null;ms.stillPos=null;ms.ackedSeq=Math.max(ms.ackedSeq,ms.seq);ms.sent.clear();}
/** A click-move or chase that reached its goal leaves the body still while the last periodic report was sent
 *  before arrival: true on the first still frame, so a final report pins the host pose without a visible pause. */
export function syncArrived(net,now=performance.now()){
  const ms=net._moveSync,p=net.game?.player;
  if(!syncActive(net)||!ms?.moving||!p||net._settling||syncDead(net))return false;
  if(!ms.stillPos||Math.hypot(p.x-ms.stillPos.x,p.z-ms.stillPos.z)>1e-4){ms.stillPos={x:p.x,z:p.z};ms.stillAt=now;return false;}
  return now>ms.stillAt&&now-ms.lastSendAt>=C.MIN_SEND_SPACING_MS;
}
