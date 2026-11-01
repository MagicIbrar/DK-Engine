// Skill inputs cross the trust boundary; the existing engine only plays approved
// animation/combo FX. Damage, costs, learning and status timers stay on the server.
import { RemoteSkillPlayback } from './skill-playback.js';
import { ApprovedGroundEffects } from './skill-ground-effects.js';
import { SharedStatusPlayback } from './status-playback.js';
import { installSharedServants } from './servants.js';
import { INSTANT_STEP } from '../skills/engine.js';
import { isDamageShareSkill } from '../skills/damage-share.js';
import { isPartyRecallSkill } from '../skills/party-recall.js';
// CAST - ENGINE-CHOSEN limits; none of them changes a damage, cost, cooldown, range or cast-time value.
const CAST_MAX_IN_FLIGHT = 4;          // different skills whose command still awaits its answer (the host allows 30 commands / s in all)
const CAST_ANNOUNCE_GRACE_MS = 750;    // a cast the host answered but did not announce (cast event) within this is taken back
const CAST_ANSWER_LIMIT_MS = 6000;     // no answer at all (the request itself gives up after 15 s)
const CAST_SNAPSHOT_MS = 100;          // host snapshot cadence (server/world/api.mjs tickMs)
const CAST_REFUSAL_REPEAT_MS = 1500;   // the same refusal text shows at most this often beside the character
// Use decoded results at the usable learned level, never distance or skill type.
function rangedTargetSkill(engine,skill,level) {
  const steps=engine.levelData?.(skill,level)?.steps;
  if(!(level>0)||!Array.isArray(steps))return false;
  let ranged=false;
  for(const step of steps){
    const r=step.result;if(!r)continue;
    if(r.family==='damage'){
      if(r.damageClass!=='range')return false;
      ranged=true;
    }else if(r.family==='projectile'){
      const native=engine.data?.remote?.(r.remoteIndex),impact=r.impact||native?.impact;
      // Only native targeted flyers have an unambiguous hostile impact.
      if(r.remoteMissing||!native||Number(r.launch)!==1||impact?.family!=='damage'||!['range','magic'].includes(r.damageClass||impact.damageClass))return false;
      ranged=true;
    }else if(r.kind==='damage'||['dash','teleport','servant_explode'].includes(r.family))return false;
  }
  return ranged;
}
// CAST. The early animation is taken back with engine.cancel() when the host refuses (a clip's root-motion distance is
// moved back with engine.undoRootMotion), and cancel() cannot
// undo what the first moments of some skills already did: a dash step moves the body (engine._startDash; the 5 classes with a dash
// skill are 0, 5, 7, 12, 13 in gamedata/skills/class_*.json; meister move skills too, engine._moveSkillDir), a teleport step
// displaces it, and a projectile step shorter than INSTANT_STEP is launched inside _begin (ApprovedGroundEffects.play) and flies on
// after a rollback. A host refusal the client cannot foresee (line of sight, mana spent meanwhile) would leave the body displaced or
// a stray projectile in the air, so these skills are not predicted: they start from the host's cast event as before.
// Measured on gamedata: of Incar Magician only 583 Gravity Ruin and 587 Energy Flare (instant projectile) lose the early start;
// the 40 other skills of that loop keep it.
export function movesOrLaunchesAtOnce(engine,skill,L) {
  if(engine._moveSkillDir?.(skill)!=null)return true;
  for(const st of L?.steps||skill?.steps||[]){
    const family=st?.result?.family;
    if(family==='dash'||family==='teleport')return true;
    if(family==='projectile'&&(Number(st.durationMs)||0)/1000<INSTANT_STEP)return true;
  }
  return false;
}
export function installSharedSkills(game, network) {
  const engine=game.skills;if(!engine)return;
  const disposeServants=installSharedServants(game,network);
  let disposed=false,generation=0;
  // CAST. A press used to be dropped silently while ANY cast command was awaiting its reply (one global `pending`
  // flag), and a cast showed nothing until the host's cast event came back (round trip + the ~100 ms snapshot cadence).
  // Now: one command in flight per skill (a repeat of the same skill waits for its own answer), a few different skills at once
  // (the host queues a press made during a running skill, like the original engine), the local cast animation starts on the
  // press when the client's own checks pass (`predicted`), and it is dropped again if the host refuses or never announces it.
  const inflight=new Map(),refusalAt=new Map();let predicted=null;
  // ms the host's clock is ahead of what this client shows: one way over the link + one ~100 ms snapshot (ENGINE-CHOSEN).
  engine.castLeadMs=()=>(Number(network._linkRtt)||0)/2+CAST_SNAPSHOT_MS;
  const refuse=text=>{ // visible beside the character, not only as a chat line
    const now=performance.now();if(now-(refusalAt.get(text)??-1e9)<CAST_REFUSAL_REPEAT_MS)return;refusalAt.set(text,now);
    try{game.hud?.floater?.(game.player,String(text),'miss');}catch(error){console.warn('[skills] refusal text failed',error);}
  };
  const rollback=()=>{
    const q=predicted;if(!q)return;predicted=null;
    if(engine.active&&engine.active.id===q.activeId)engine.cancel();
    // the clip's root curve already carried the body (engine._advanceRootMotion): the host never moved it, so take it back
    engine.undoRootMotion?.(q.activeId);
    if(q.prior)engine.cooldowns.set(q.skillId,q.prior);else engine.cooldowns.delete(q.skillId);
  };
  // The cast event reports the cooldown as it stood when the host started the skill; by the time it arrives that much of it has
  // already run on the host. Subtract the delivery delay (host clock estimate vs the event's host time) so the sweep and the
  // hotbar grey-out end when the host's cooldown ends (measured before: the client's ran 35 ms (median) to 100 ms longer).
  const applyCooldown=event=>{
    const ms=Number(event.cooldownMs);if(!(ms>0))return;
    const clock=network._serverClock;let late=0;
    if(clock&&Number.isFinite(Number(event.at)))late=Math.min(1000,Math.max(0,clock.time+performance.now()-clock.at-Number(event.at)));
    const left=Math.max(0,ms-late)/1000;
    engine.cooldowns.set(Number(event.skillId),{start:game.time+left-ms/1000,end:game.time+left});
  };
  // A press on a target that has just died (common in a field full of monsters) used to do nothing at all. The original engine
  // answers it with message code 50 (SkillEngine._pickTarget -> _msg; stringtable_skill.txt <cate> 60 code 50 reads
  // "No Skill Information."); say that, and let the press go no further.
  const targetGone=target=>{
    if(!target||!(target.dead||target.disposed||!(target.hp>0)))return false;
    refuse(engine.msg?.(50)??'Invalid target.');
    return true;
  };
  // Face the aim point exactly like the approved playback does.
  const faceAim=aim=>{
    const p=game.player;
    if(aim&&Number.isFinite(aim.x)&&Number.isFinite(aim.z)&&Math.hypot(aim.x-p.x,aim.z-p.z)>1e-6){p.faceTowards?.(aim.x,aim.z);if(Number.isFinite(p.targetYaw))p.yaw=p.targetYaw;}
  };
  // Start the cast animation now, with the same pure checks the original engine runs before it starts a cast. Everything
  // that decides the cast (cost, cooldown, range, line of sight, damage) stays on the host; nothing is spent or damaged here.
  const startPredicted=(id,target,point)=>{
    const p=game.player;
    if(!p||p.dead||engine.active||predicted||(game.mounts?.isMounted?.()))return null;
    const skill=engine.skillDef(id),level=engine.skillLevel?.(id);
    if(!skill||!(level>0)||engine.isPassive?.(skill)||engine._needType?.(skill)!==true)return null;
    const check=engine.usability?.(id);
    if(!check?.ok&&!(check?.reason==='cooldown'&&engine.cooldownRemaining(id)*1000<=engine.castLeadMs()))return null; // ready by the time the host sees it
    const mask=Number(skill.targetMask)||0;
    if(!target&&(mask&4))return null; // "nearest enemy" is the host's choice
    const L=engine.levelData(skill,level);if(!L)return null;
    if(movesOrLaunchesAtOnce(engine,skill,L))return null; // its first moments cannot be taken back: the host's cast event starts it
    const pick=engine._pickTarget(skill,{target,point});if(!pick||pick.error)return null;
    if(pick.target&&pick.target!==p){
      const reach=Math.max(1.5,Number(skill.range)||3)+(pick.target.radius||.5)+.3;
      if(Math.hypot(p.x-pick.target.x,p.z-pick.target.z)>reach)return null;
    }
    const prior=engine.cooldowns.get(id);
    try{
      faceAim(pick.target&&pick.target!==p?pick.target:pick.point);
      engine._begin(skill,level,L,pick.target,pick.point,engine.equippedStyle(),{free:true,predicted:true});
    }catch(error){engine.cancel();console.warn('[skills] predicted playback failed',id,error);return null;}
    const a=engine.active;if(!a)return null;
    a.predicted=true;engine._startCooldown?.(skill,L);
    return predicted={skillId:id,activeId:a.id,at:performance.now(),ackAt:0,prior,skill,level};
  };
  // One cast command. `via` wraps the send (movement settling for the walk-into-range path).
  const sendCast=(input,target,point,via)=>{
    // FIELD-PK: Ctrl on a PK field arms the cast (the host decides whom it may hit); a player target needs the key too
    if(target?.kind==='player'?network.fieldPk?.forcedFor?.(target):network.fieldPk?.armedNow?.())input={...input,forced:true};
    const id=input.skillId;
    if(inflight.size>=CAST_MAX_IN_FLIGHT)return false;
    const epoch=generation,sentAt=performance.now(),wall=Date.now();
    inflight.set(id,sentAt);
    startPredicted(id,target,point);
    const send=()=>disposed?false:network.action('cast',input);
    // the walk-into-range path must start settling the arrival stop in this very call (before this frame's network upkeep can flush it)
    let started;try{started=via?Promise.resolve(via(send)):Promise.resolve().then(send);}catch(error){started=Promise.reject(error);}
    void started.then(result=>{
      if(disposed||epoch!==generation)return;
      if(result){if(predicted?.skillId===id)predicted.ackAt=performance.now();return;}
      if(result===false){if(predicted?.skillId===id)rollback();return;} // the walk-into-range guard cancelled it: nothing was sent
      // refused or never delivered: take the early animation back and say why
      const err=network._lastCommandError;
      if(predicted?.skillId===id)rollback();
      refuse(err&&err.at>=wall-50&&err.message?err.message:'The skill could not be cast.');
    }).catch(error=>console.warn('[skills] cast request failed',error)).finally(()=>{if(inflight.get(id)===sentAt)inflight.delete(id);});
    return true;
  };
  const remote=new RemoteSkillPlayback(game),statusPlayback=new SharedStatusPlayback(game,network);
  const ground=new ApprovedGroundEffects(game,engine.data,engine.fx);
  const clearCosmetics=()=>{rollback();generation++;if(game.controller?.order?.networkSkill)game.controller.stop();ground.clear();remote.clear();statusPlayback.clear();};
  network.remoteSkillBusy=actor=>remote.busy(actor); // Observers keep a NO_CANCEL skill body like the caster does
  // Fetch a visible player's class skill pack once, so its first cast starts on the observer when the event
  // arrives (measured live: +110-130 ms late on the first cast of a class without this, 0-15 ms after).
  const preloaded=new Set();
  network.actorSkillState=(actor,row)=>{actor._skillStatusVisuals=row.statusVisuals||[];void remote.transform(actor,row.transUp||null);
    const ci=Number(actor.save?.classIndex??actor.classDef?.index);
    if(actor.kind==='player'&&actor!==game.player&&Number.isInteger(ci)&&ci>=0&&ci<=14&&!preloaded.has(ci)){preloaded.add(ci);void remote.pack(ci).catch(error=>console.warn('[skills] remote skill pack preload failed',ci,error));}
  };
  const remoteOff=[game.events?.on?.('map',clearCosmetics),game.events?.on?.('teleport',clearCosmetics),game.events?.on?.('network',({state}={})=>{if(['connecting','disconnected','expired'].includes(state))clearCosmetics();})];
  const update=network.update?.bind(network);
  if(update)network.update=dt=>{
    if(!network.ready)clearCosmetics();else {remote.update(dt);ground.update(dt);}
    if(predicted){const now=performance.now();if(predicted.ackAt?now-predicted.ackAt>CAST_ANNOUNCE_GRACE_MS:now-predicted.at>CAST_ANSWER_LIMIT_MS)rollback();}
    const result=update(dt);
    if(network.ready&&(!network.self||Number(network.self.map)===Number(game.world?.info?.index)))statusPlayback.update();
    return result;
  };
  const leave=network.leave?.bind(network);
  if(leave)network.leave=opts=>{disposed=true;offProfile?.();for(const off of remoteOff)off?.();ground.clear();remote.dispose();statusPlayback.dispose();disposeServants?.();engine.cancel?.();engine.cooldowns?.clear();return leave(opts);};
  // Approved combo playback reaches result markers; their authoritative results
  // already ran on the host. Read-only cosmetic remotes and canonical impact
  // events may render; damage/status calculations remain disabled here.
  engine.applyResult=(ctx,result)=>ground.play(ctx,result);engine.applyImpact=()=>false;
  engine._updateTransUp=()=>{}; // Canonical snapshots alone own transform expiry.
  if(engine.spells)engine.spells.restore=()=>{}; // SharedStatusPlayback owns restored auras.
  engine.useSkill=(id,opts={})=>{
    id=Number(id);if(disposed||!network.ready||!engine.skillDef(id))return false;
    if(inflight.has(id))return true; // this skill's command is already on its way (the press is consumed, not lost)
    // Wait before prediction/host dispatch, never pause an approved combat timeline.
    if(engine.effectResources?.defer(id,opts,next=>engine.useSkill(id,next)))return true;
    const target=opts.target||game.player?.target||game.controller?.target,point=opts.point;
    const mask=Number(engine.skillDef(id).targetMask)||0,selfOnly=(mask&16)!==0&&(mask&(2|4|8|32|64))===0;
    // Divide Pain and Recall use mask 64 for a selected party member; preserve that target id for the host.
    const ownServantOnly=(mask&64)!==0&&(mask&(2|4|8|16|32))===0&&!isDamageShareSkill(engine.skillDef(id))&&!isPartyRecallSkill(engine.skillDef(id));
    const skill=engine.skillDef(id),level=engine.skillLevel?.(id);
    if(network.active&&Number.isInteger(network.self?.posRev)&&!point&&target?.networkId&&game.controller?.approach&&!selfOnly&&!ownServantOnly&&(mask&4)&&rangedTargetSkill(engine,skill,level)){
      const player=game.player,controller=game.controller,lease=network.token,leaseGeneration=network._leaseGeneration,targetId=target.networkId,epoch=generation,intent=controller._inputIntentRevision||0;
      const map=network.self?.map,instance=network.self?.instanceId,channel=network.self?.channel;
      const targetMap=target.map,targetInstance=target.instanceId,targetChannel=target.channel;
      const valid=()=>!disposed&&generation===epoch&&game.controller===controller&&network.token===lease&&network._leaseGeneration===leaseGeneration&&(controller._inputIntentRevision||0)===intent&&network.ready&&network.active&&Number.isInteger(network.self?.posRev)&&game.player===player&&player?.hp>0&&!player.dead&&!player.disposed&&
        network.self?.map===map&&network.self?.instanceId===instance&&network.self?.channel===channel&&
        target.networkId===targetId&&target.map===targetMap&&target.instanceId===targetInstance&&target.channel===targetChannel&&
        !target.dead&&!target.disposed&&target.hp>0&&engine.skillLevel?.(id)===level&&
        (target.kind==='monster'||(target.kind==='player'&&target!==player&&!!game.isPvpHostile?.(target)));
      if(targetGone(target))return false;
      if(!valid())return false;
      const range=Math.max(1.5,Number(skill.range)||3),reach=range+(target.radius||.5)+.3;
      const inRange=()=>{const aim=game.controller._sharedAttackTarget?.(target)||target;return Math.hypot(player.x-aim.x,player.z-aim.z)<=reach;};
      const cast=()=>{
        if(!valid())return false;
        // A ranged cast settles movement like mounting, but does not cancel an
        // already-running attack. Never revive an approach or superseded input.
        const attack=controller.order?.type==='attack'?controller.order:null;
        const restoreAttack=()=>{if(attack&&valid()&&!controller.order&&player.target===attack.target&&controller._validEnemy(attack.target))controller.order=attack;};
        // Own the arrival stop before this frame's network maintenance can flush it.
        return sendCast({skillId:id,targetId},target,undefined,send=>{
          if(!valid())return false;
          const guarded=()=>{if(!valid())return false;restoreAttack();return inRange()?send():false;};
          try{return Promise.resolve(typeof network.settleMovement==='function'?network.settleMovement(guarded):guarded()).catch(error=>{restoreAttack();throw error;});}
          catch(error){restoreAttack();throw error;}
        });
      };
      if(!inRange()){
        const old=game.controller.order;if(old?.networkSkill===id&&old.target===target&&old.predictedRangedSkill&&old.valid?.())return true;
        game.controller.approach(target,range,()=>valid()?cast():false,{networkSkill:id,predictedRangedSkill:true,authoritativeRange:reach,valid});return true;
      }
      return cast();
    }
    // Shared skill input reconstructs the existing walk-into-range UX; authority stays on the host.
    if (!selfOnly && !ownServantOnly && (mask&4) && target?.kind==='monster' && target.networkId && game.controller?.approach) {
      if (targetGone(target)) return false;
      const canonical=network.self||game.player,reach=Math.max(1.5,Number(engine.skillDef(id).range)||3)+(target.radius||.5)+.3;
      if (Math.hypot(canonical.x-target.x,canonical.z-target.z)>reach) {
        const old=game.controller.order;if(old?.networkSkill===id&&old.target===target)return true;
        const map=network.self?.map,instance=network.self?.instanceId,player=game.player;
        game.controller.approach(target,Math.max(1.5,Number(engine.skillDef(id).range)||3),()=>engine.useSkill(id,{...opts,target}),{
          networkSkill:id,authoritativeRange:reach,valid:()=>!disposed&&network.ready&&game.player===player&&network.self?.map===map&&network.self?.instanceId===instance
        });return true;
      }
    }
    const input={skillId:id};if(!selfOnly&&!ownServantOnly&&target?.networkId)input.targetId=target.networkId;
    if(point&&Number.isFinite(point.x)&&Number.isFinite(point.z)){input.x=point.x;input.z=point.z;}
    return sendCast(input,input.targetId?target:undefined,point);
  };
  // Original HUD passes an entry object; older controls pass a numeric slot or
  // skill ID. Preserve all three input forms instead of coercing objects to NaN.
  const useEntry=entry=>entry?.type==='item'?game.items?.useRef?.(entry)??false:entry?engine.useSkill(entry.skillIndex??entry.index):false;
  engine.use=value=>{
    if(value&&typeof value==='object')return useEntry(value);
    const n=Number(value);
    return Number.isInteger(n)&&n>=0&&n<12?useEntry(game.save.hotbar?.[n]):engine.useSkill(n);
  };
  engine.useSlot=slot=>useEntry(game.save.hotbar?.[Number(slot)]);
  engine.learn=id=>network.action('learn',{skillId:Number(id)});
  engine.chooseMeisterPath=path=>network.action('meisterPath',{path});
  engine.reinforceMeister=(skillId,uid)=>network.action('meisterReinforce',{skillId:Number(skillId),uid});
  // Keep the original combo timeline, but never advance local gameplay statuses.
  if(game.statuses){game.statuses.update=()=>{};game.statuses.onMapChange=()=>{};}
  if(engine.statuses){engine.statuses.update=()=>{};engine.statuses.onMapChange=()=>{};}
  network.skillEvent=(event,actor,target)=>{
    if(disposed||!actor)return;
    if(event.type==='skillimpact'){void remote.impact(event,actor,network._serverClock);return;}
    if(event.type==='status'){statusPlayback.event(event,actor);return;}
    // The host parked this press behind the running skill: the early animation is taken back, the real one comes with its cast event.
    if(event.type==='skillqueued'){if(actor===game.player&&predicted?.skillId===Number(event.skillId))rollback();return;}
    // A queued press that could not start when the running skill ended.
    if(event.type==='skillrefuse'){if(actor===game.player&&event.message){game.chat?.system?.(String(event.message),'err');refuse(event.message);}return;}
    if(event.type!=='cast')return;
    if(actor!==game.player){void remote.cast(event,actor,target);return;}
    const skill=engine.skillDef(event.skillId),level=Number(event.level)||1,L=skill&&engine.levelData(skill,level);
    if(!skill||!L)return;
    // The animation already runs from the press: confirm it instead of restarting it (cooldown + the skill event only).
    if(predicted&&predicted.skillId===Number(event.skillId)&&engine.active?.id===predicted.activeId){
      engine.active.predicted=false;predicted=null;
      applyCooldown(event);
      game.events?.emit?.('skill',{actor,skill,level,target,server:true});
      return;
    }
    rollback(); // a different skill started: the early one is not the host's
    engine.cancel();
    // Approved playback bypasses useSkill's facing path. Aim only from the
    // canonical event target/point, not a newer cursor or unapproved input.
    const p = game.player, aim = target && target !== p ? target : event.point;
    if (aim && Number.isFinite(aim.x) && Number.isFinite(aim.z) && Math.hypot(aim.x-p.x,aim.z-p.z)>1e-6) {
      p.faceTowards?.(aim.x, aim.z);
      if (Number.isFinite(p.targetYaw)) p.yaw = p.targetYaw;
    }
    try { engine._begin(skill,level,L,target,event.point,engine.equippedStyle(),{free:true}); }
    catch(error) { engine.cancel();console.warn('[skills] approved playback failed',event.skillId,error); }
    applyCooldown(event);
    game.events?.emit?.('skill',{actor,skill,level,target,server:true});
  };
  let baseline=null,desired=null,flushing=false;
  const ref=entry=>entry?.type==='item'?{type:'item',itemIndex:Number(entry.itemIndex)}:entry?.type==='skill'?{type:'skill',index:Number(entry.index)}:null;
  const copy=()=>{
    const q=game.save.quickslot||{},sets=q.sets||[game.save.hotbar||[]];
    return {sets:Array.from({length:3},(_,r)=>Array.from({length:12},(_,s)=>ref(sets[r]?.[s]))),belt:Array.from({length:10},(_,i)=>ref(q.belt?.[i])),rows:q.rows??1,rowSet:[...(q.rowSet||[0,1,2])],fixed:[...(q.fixed||[false,false,false])],locked:q.locked??true};
  };
  const show=layout=>{game.save.quickslot=structuredClone(layout);game.save.hotbar=game.save.quickslot.sets[layout.rowSet[0]];};
  const flush=async()=>{
    if(flushing)return;flushing=true;
    try{while(desired){const sending=desired;await network.action('quickslots',{layout:sending});if(desired===sending){desired=null;if(baseline)show(baseline);}}}
    finally{flushing=false;}
  };
  let skillsSignature=null;
  const offProfile=game.events?.on?.('server:profile',()=>{
    if(disposed)return;
    const trans=game.save.transUp;
    const clock=network._serverClock,now=clock?clock.time+performance.now()-clock.at:Date.now();
    if(game.player){game.player.transUpStage=trans&&Number(trans.until)>now?Number(trans.stage)||0:0;game.player.transUpUntil=game.time+Math.max(0,(Number(trans?.until)||0)-now)/1000;}
    if(game.player){
      const rows=game.player.transUpStage?engine.skillDef(Number(trans?.skill))?.transform:[];
      const look=rows?.find(row=>Number(row.level)===Number(trans?.level))?.shapeshift||null;
      const signature=JSON.stringify(look);
      if(signature!==game.player._serverTransformLook){game.player._serverTransformLook=signature;game.player.transformLook=look;game.player.refreshAppearance?.();}
    }
    baseline=copy();if(desired)show(desired);const next=JSON.stringify(game.save.skills||{});
    if(next!==skillsSignature){skillsSignature=next;game.events?.emit?.('skilllearn',{server:true});}
    const deadlines=game.save.skillCooldowns||{};
    for(const id of engine.cooldowns.keys())if(!(Number(deadlines[id])>now)&&!(predicted&&predicted.skillId===Number(id)))engine.cooldowns.delete(id); // a cast started on the press has no host deadline yet
    for(const [id,end]of Object.entries(deadlines)){
      const remaining=(Number(end)-now)/1000,key=Number(id);
      if(remaining>0&&engine.skillDef(key)){
        const until=game.time+remaining,current=engine.cooldowns.get(key);
        engine.cooldowns.set(key,{start:current?.start??game.time,end:until});
      }
    }
  });
  if(game.quickslot){
    const changed=game.quickslot.changed.bind(game.quickslot);
    game.quickslot.changed=()=>{
      changed();if(disposed||!network.ready||!baseline)return;
      const next=copy();if(JSON.stringify(next)===JSON.stringify(desired||baseline))return;
      desired=next;void flush();
    };
  }
}
