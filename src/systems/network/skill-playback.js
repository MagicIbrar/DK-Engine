import { SkillData } from '../skills/data.js';
import { EffectPlayer } from '../skills/effects.js';
import { playOnce } from '../../game/combat.js';
import { Equipment } from '../items/equip.js';
import { ApprovedGroundEffects } from './skill-ground-effects.js';
import { INSTANT_STEP, castVisualRef, skillPhases } from '../skills/engine.js';

const num = value => Number.isFinite(Number(value)) ? Number(value) : 0;
const stop = handle => { try { handle?.stop?.(true); } catch (error) { console.warn('[skills] remote effect stop failed', error); } };

/** Approved native cosmetics only; result markers select visual scenes, never gameplay. */
export class RemoteSkillPlayback {
  constructor(game, { load = async index => new SkillData().load(index), effects = data => new EffectPlayer(game,data) } = {}) {
    this.game=game;this.load=load;this.effects=effects;this.packs=new Map();this.loaded=new Map();this.active=new Map();this.requests=new Map();this.transforms=new Map();this.generation=0;this.impactSeen=new Set();
  }
  pack(index) {
    if(!this.packs.has(index))this.packs.set(index,Promise.resolve(this.load(index)).then(data=>{const pack={data,fx:this.disposed?null:this.effects(data)};if(!this.disposed){pack.ground=new ApprovedGroundEffects(this.game,data,pack.fx);this.loaded.set(index,pack);}return pack;}).catch(error=>{this.packs.delete(index);throw error;}));
    return this.packs.get(index);
  }
  clearTransform(actor,request) {
    if(this.transforms.get(actor)!==request)return;
    this.transforms.delete(actor);
    if(actor.transUpStage===request.stage)actor.transUpStage=0;
    if(request.look&&actor.transformLook===request.look){
      actor.transformLook=null;
      if(!actor.disposed){
        try { void Promise.resolve(actor.refreshAppearance?.()).catch(error=>console.warn('[skills] remote transform reset failed',error)); }
        catch(error){console.warn('[skills] remote transform reset failed',error);}
      }
    }
  }
  async transform(actor,state) {
    if(this.disposed||!actor||actor.disposed)return;
    if(actor.dead)state=null;
    const signature=JSON.stringify(state),previous=this.transforms.get(actor);
    if(previous?.signature===signature)return;
    if(!state){if(previous)this.clearTransform(actor,previous);return;}
    const request={signature,stage:Number(state.stage)||0,look:previous?.look||null};this.transforms.set(actor,request);
    actor.transUpStage=request.stage;
    const generation=this.generation,index=Number(actor.save?.classIndex??actor.classDef?.index);
    try {
      const pack=await this.pack(index);
      if(this.disposed||generation!==this.generation||this.transforms.get(actor)!==request||actor.dead||actor.disposed)return;
      const row=pack.data.skill(Number(state.skill))?.transform?.find(row=>Number(row.level)===Number(state.level));
      const look=row?.shapeshift||null;
      request.look=look;
      if(JSON.stringify(actor.transformLook||null)!==JSON.stringify(look)){actor.transformLook=look;actor.refreshAppearance?.();}
      else request.look=actor.transformLook||null;
    }catch(error){this.clearTransform(actor,request);console.warn('[skills] remote transform failed',error);}
  }
  async impact(event,actor,clock=null) {
    if(this.disposed||!actor||actor.disposed)return false;
    const sequence=Number(event.sequence);if(!Number.isInteger(sequence)||sequence<=0||this.impactSeen.has(sequence))return false;
    const index=Number(event.classIndex),ref=event.effect;if(!Number.isInteger(index)||index<0||index>14||!ref||!Number.isInteger(ref.id)||ref.id<=0||!Number.isInteger(ref.scene)||ref.scene<0||!Number.isInteger(ref.cate)||ref.cate<0||!(ref.timeMs>0&&ref.timeMs<=120000))return false;
    const queuedAt=performance.now(),generation=this.generation;this.impactSeen.add(sequence);if(this.impactSeen.size>256)this.impactSeen.delete(this.impactSeen.values().next().value);
    try {const pack=await this.pack(index);const now=performance.now(),elapsed=clock&&Number.isFinite(Number(event.issuedAt))?Math.max(0,Number(clock.time)+now-Number(clock.at)-Number(event.issuedAt)):now-queuedAt;
      if(this.disposed||generation!==this.generation||actor.disposed||elapsed>=ref.timeMs||!pack.data.scene(ref.cate+':'+ref.id)?.scenes?.[ref.scene])return false;
      const handle=pack.fx.play(actor,ref,{loop:false});if(handle?.then)void Promise.resolve(handle).then(h=>{if(this.disposed||generation!==this.generation||actor.disposed)stop(h);}).catch(error=>console.warn('[skills] canonical impact failed',error));return !!handle;
    }catch(error){console.warn('[skills] canonical impact failed',error);return false;}
  }
  async cast(event,actor,target=null) {
    if(this.disposed||!actor||actor.dead||actor.disposed)return false;
    const index=Number(actor.save?.classIndex??actor.classDef?.index),generation=this.generation,request={};
    if(!Number.isInteger(index)||index<0)return false;
    this.end(actor);this.requests.set(actor,request);
    try {
      const pack=await this.pack(index);
      if(this.disposed||generation!==this.generation||this.requests.get(actor)!==request||actor.dead||actor.disposed)return false;
      const skill=pack.data.skill(event.skillId),level=Number(event.level)||1,L=pack.data.level(skill,level);
      if(!skill||!L){this.requests.delete(actor);return false;}
      const phases=skillPhases(skill,L).map(p=>({...p,step:p.st,dur:Math.max(0,p.durationMs)/1000}));
      if(!phases.length){this.requests.delete(actor);return false;}
      let style=Number(actor.classDef?.style??1);
      if(this.game.items?.db&&actor.save?.equip)style=new Equipment({db:this.game.items.db,game:{save:structuredClone(actor.save),settings:this.game.settings}}).style();
      const run={actor,pack,skill,phases,i:0,t:0,handles:[],style,target,point:event.point};
      this.active.set(actor,run);run.holdUntil=performance.now()+phases.reduce((n,p)=>n+p.dur,0)*1000;actor._networkAnimHold=run.holdUntil;
      this.phase(run);return true;
    } catch(error) { if(this.requests.get(actor)===request)this.end(actor);console.warn('[skills] remote cosmetic playback failed',event.skillId,error);return false; }
  }
  phase(run) {
    this.endLoops(run,run.i);
    const {actor,pack,skill,style}=run,p=run.phases[run.i];
    let clip=p.kind==='step'?pack.data.clipFor(skill,p.step,style):pack.data.clipForAction(skill,p.act,style);
    if(p.kind==='cast'&&!p.act){const first=run.phases.find(p=>p.kind==='step');clip=first&&pack.data.clipFor(skill,first.step,style);}
    // Same clip rule as the caster's own SkillEngine._next (cast/charge always; ready/step from INSTANT_STEP 4 ms),
    // so 4-9 ms marker steps play on the observer exactly as on the caster.
    if(clip?.anim&&(p.kind==='cast'||p.dur>=INSTANT_STEP)){
      actor._skillStyles?.set?.(String(clip.anim).trim().replace(/\\/g,'/').replace(/^\/+/, '').toLowerCase(),Number(clip.style??1));
      const cycle=p.kind==='cast'&&p.act?Math.max(.05,Number(p.act.durationMs??p.act.timeTick)/1000||p.dur):p.dur;
      playOnce(actor,'skill',{anim:clip.anim,timeLength:cycle,loop:p.kind==='cast',variant:clip.clipIndex},this.game.time||0,p.dur);
    }
    run.hitAt=p.kind==='step'&&p.step.result?(p.dur<.004?0:(clip?.timing>0&&clip.timing<=1?clip.timing:.5)*p.dur):null;run.resultPlayed=false;
    if(run.hitAt===0)this.land(run);
    const effect=p.kind==='step'?p.step.effect:p.act?.effect;
    if(effect){const ref=castVisualRef(skill,run.phases,run.i,effect);if(ref)this.effect(run,{...ref,timeMs:ref.timeMs||p.dur*1000});}
    if(p.kind==='step'&&clip?.actionEffect&&Number(clip.actionEffect.id)!==Number(effect?.id)){
      const ref=castVisualRef(skill,run.phases,run.i,clip.actionEffect);if(ref)this.effect(run,{...ref,timeMs:ref.timeMs||p.dur*1000});
    }
  }
  /** The observer-side twin of SkillEngine.busy (ready / cast phase or a non-ACTION combo step running, or the
   *  accepted cast still loading its pack): while true a hit does not interrupt the caster's skill body, as on its own screen. */
  busy(actor) {
    if(this.requests.has(actor)&&!this.active.has(actor))return true;
    const run=this.active.get(actor),p=run?.phases[run.i];
    return !!p&&(p.kind!=='step'||p.step?.type!=='ACTION');
  }
  land(run) {
    if(run.resultPlayed)return;run.resultPlayed=true;
    run.pack.ground?.play({caster:run.actor,skill:run.skill,target:run.target,point:run.point},run.phases[run.i].step?.result);
  }
  effect(run,ref) {
    try {
      const handle=run.pack.fx.play(run.actor,ref,{}),phase=run.i;
      if(handle?.then)void Promise.resolve(handle).then(h=>{if(this.disposed||(this.active.get(run.actor)!==run&&run.ended!=='finished'))stop(h);else if(run.ended==='finished'){if(h?.loop){try{h.stop?.(false);}catch(error){console.warn('[skills] remote effect stop failed',error);}}}else this.keep(run,h,phase);}).catch(error=>console.warn('[skills] remote effect failed',error));
      else this.keep(run,handle,phase);
    } catch(error) { console.warn('[skills] remote effect failed',error); }
  }
  keep(run,handle,phase) {
    run.handles.push(handle);
    if(!handle?.loop)return;
    if(phase<run.i){try{handle.stop?.(false);}catch(error){console.warn('[skills] remote effect stop failed',error);}return;}
    (run.loops||=[]).push({handle,phase});
  }
  /** FXLIFE: an action effect the data marks `loop 0` (the charge circle of the summon skills) lives while its phase runs and is
   *  stopped softly at the next phase boundary, exactly as SkillEngine._endLoops does on the caster's own screen. ENGINE-CHOSEN. */
  endLoops(run,upto) {
    if(!run.loops?.length)return;
    run.loops=run.loops.filter(entry=>{
      if(entry.phase>=upto)return true;
      try{entry.handle.stop?.(false);}catch(error){console.warn('[skills] remote effect stop failed',error);}
      return false;
    });
  }
  update(dt) {
    for(const [actor,request]of this.transforms)if(actor.dead||actor.disposed)this.clearTransform(actor,request);
    for(const actor of this.requests.keys())if(actor.dead||actor.disposed){this.requests.delete(actor);this.end(actor);}
    for(const [actor,run]of this.active){
      if(actor.dead||actor.disposed){this.end(actor);continue;}
      run.t+=Math.max(0,num(dt));
      try { if(run.hitAt!=null&&run.t>=run.hitAt)this.land(run);while(run.t>=run.phases[run.i].dur){run.t-=run.phases[run.i].dur;if(++run.i>=run.phases.length){this.end(actor,true);break;}this.phase(run);if(run.hitAt!=null&&run.t>=run.hitAt)this.land(run);} }
      catch(error){this.end(actor);console.warn('[skills] remote cosmetic phase failed',error);}
    }
    for(const [index,pack] of this.loaded){
      try { pack.ground?.update(Math.max(0,num(dt)));pack.fx.update(Math.max(0,num(dt))); }
      catch(error){this.dropPack(index,pack);console.warn('[skills] remote effect update failed',error);}
    }
  }
  /** finished = the last phase ran out (FXLIFE: the one-shot effects keep their authored length, exactly as on the caster's own client, whose
   *  finished skill never stopped them; only a loop of the last phase is stopped, softly). Anything else (a new cast, death, map change,
   *  clear, an error) removes every effect of the run at once. */
  end(actor,finished=false) {
    this.requests.delete(actor);
    const run=this.active.get(actor);if(!run)return;
    this.active.delete(actor);if(actor._networkAnimHold===run.holdUntil)actor._networkAnimHold=0;
    if(actor._gpState==='skill'){actor._gpState=null;actor._gpHold=0;}
    run.ended=finished?'finished':'aborted';
    if(finished)this.endLoops(run,Infinity);
    else for(const handle of run.handles)stop(handle);
    run.handles=[];run.loops=[];
  }
  dropPack(index,pack) {
    this.loaded.delete(index);this.packs.delete(index);
    for(const [actor,run] of this.active)if(run.pack===pack)this.end(actor);
    try { pack.ground?.clear();pack.fx?.dispose(); } catch(error) { console.warn('[skills] remote effects dispose failed',error); }
  }
  clear() {
    this.generation++;this.requests.clear();this.impactSeen.clear();
    for(const [actor,request]of this.transforms)this.clearTransform(actor,request);
    for(const actor of this.active.keys())this.end(actor);
    for(const [index,pack] of this.loaded){
      try { pack.ground?.clear();pack.fx.clear(); } catch(error) { this.dropPack(index,pack);console.warn('[skills] remote effects clear failed',error); }
    }
  }
  dispose() {
    this.disposed=true;this.clear();
    for(const [index,pack] of this.loaded)this.dropPack(index,pack);
    this.loaded.clear();this.packs.clear();
  }
}
