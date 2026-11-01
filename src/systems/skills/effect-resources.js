// Prepare only the requested/learned native skill's reachable visual resources.
// Combat clocks are never paused: preparation happens before local dispatch.
import * as THREE from 'three';
import { skillPhases } from './engine.js';
import { playedSceneKey, canPlayBonePath } from './effects.js';
import { BILLBOARD_SAMPLER } from '../../engine/sampler-state.js';
import { SKILL_FX_QUALITY } from '../../config/engine-chosen-skill-fx.js';
import { SHEAR_INDICES } from '../../engine/models.js';
import { skillWeaponCompatible } from './skill-weapon.js';

const FX_KEYS=new Set(['effect','hitEffect','contactEffect','piercingEffect','warningEffect','actionEffect','enterEffect','statusEffect','leaveEffect','standEffect','dieEffect','endEffect','start','keep','end']);
const aborted=()=>Object.assign(new Error('Skill preparation changed.'),{name:'AbortError'});
// ENGINE-CHOSEN scheduling only; native data still supplies every resource and timeline.
const WORKERS=4,MAX_PLANS=64,DEADLINE_MS=30000;

export function skillResourcePlan(engine,id,{level:override}={}) {
  const data=engine.data,skill=engine.skillDef(id),level=Number(override)||engine.skillLevel(id),style=engine.equippedStyle();
  if(!skill||!(level>0))return null;
  const L=engine.levelData(skill,level),phases=skillPhases(skill,L),refs=new Map(),seen=new Set();
  const visit=value=>{
    if(!value||typeof value!=='object'||seen.has(value))return;seen.add(value);
    for(const [key,entry]of Object.entries(value)){
      if(FX_KEYS.has(key)&&entry&&Number(entry.id)>0)refs.set(`${entry.cate??100}:${entry.id}:${entry.scene??1}:${entry.timeMs??0}`,entry);
      if(/^statusIndex\d?$|^dotStatusIndex$/.test(key)&&Number(entry)>0){const def=data.status(Number(entry));if(def)visit({...(def.effects||data.modelEffects.status?.[def.iconIndex]||{}),definition:def});}
      if(key==='remoteIndex'&&Number(entry)>0)visit(data.remote(entry));
      if(key==='servantIndex'&&Number(entry)>0)visit(data.servant(entry));
      if(key==='totemIndex'&&Number(entry)>0)visit(data.totem(entry));
      if(!['raw','levels','args','statusGroups'].includes(key)&&entry&&typeof entry==='object')visit(entry);
    }
  };
  for(const phase of phases){visit(phase.st||phase.act);const clip=phase.kind==='step'?data.clipFor(skill,phase.st,style):data.clipForAction(skill,phase.act,style);visit(clip);}
  const units=new Map(),paths=new Map(),missing=[];
  for(const [key,ref]of refs){const scene=data.scene(`${ref.cate??100}:${ref.id}`),played=playedSceneKey(scene,ref.scene??1);if(!scene||played==null){missing.push({kind:'scene',key});continue;}
    for(const control of scene.scenes[played].controls||[]){if(control.active===false)continue;const unitKey=scene.res?.[control.unit],unit=data.unit(unitKey);if(unit)units.set(unitKey,unit);else missing.push({kind:'unit',key:unitKey});
      if(canPlayBonePath(control.boneAnim)){const spec=control.boneAnim,timeMs=Number(ref.timeMs)>0?Number(ref.timeMs):1000,life=Math.max(.001,(Number(control.life?.[1]??1000)-Number(control.life?.[0]||0))*timeMs/1e6);paths.set(JSON.stringify([spec,life]),{spec,life});}
    }
  }
  return {key:`${data.classIndex}:${id}:${level}:${style}`,id:Number(id),level,style,refs,units,paths,missing};
}

async function warmUnit(game,unit){
  const results=[],textures=game.textures,models=game.models;
  const keys=unit.frames?.length?unit.frames:unit.texture?[unit.texture]:[];
  if(keys.length&&!textures?.load)throw new Error('Skill texture cache is unavailable.');
  for(const key of keys)if(textures?.load)results.push(await textures.load(key,['sprite','particle'].includes(unit.type)?{fixedSampler:BILLBOARD_SAMPLER}:{}));
  if((unit.type==='mesh'&&unit.mesh&&Number(unit.size??1)!==0||unit.type==='particle'&&unit.leaf==='mesh'&&unit.mesh)&&!models?.loadStatic)throw new Error('Skill model cache is unavailable.');
  if(unit.type==='mesh'&&unit.mesh&&Number(unit.size??1)!==0&&models){
    const part={meshKey:unit.mesh,tpackKey:unit.tpack||null,textures:unit.textures||null,twoSide:!!unit.twoSide};
    const model=unit.skel?await models.loadSkinned({skelKey:unit.skel,parts:[part]}):null;
    if(model&&!model.empty){results.push(model);if(unit.anim)results.push(await models.loadClip(unit.anim,model,{duration:Number(unit.animLengthMs)>0?Number(unit.animLengthMs)/1000:null}));}
    else results.push(await models.loadStatic(unit.mesh,{tpackKey:unit.tpack||null,textures:unit.textures||null,twoSide:!!unit.twoSide,effectSpecular:SKILL_FX_QUALITY.level!=='safe'&&(unit.textures||[]).some(t=>t?.specular)}));
  }else if(unit.type==='particle'&&unit.leaf==='mesh'&&unit.mesh&&models)results.push(await models.loadStatic(unit.mesh,{tpackKey:unit.tpack||null,textures:unit.textures||null,twoSide:!!unit.twoSide}));
  if(unit.type==='sound'&&unit.sound&&game.audio?._buffer)results.push(await game.audio._buffer(unit.sound));
  return {missing:results.some(value=>!value),resources:results.length};
}

async function warmPath(game,{spec,life}){
  const models=game.models;if(!models?.skeleton)throw new Error('Skill skeleton cache is unavailable.');const skel=await models.skeleton(spec.skel);if(!skel)return {missing:true};if(!spec.anim)return {missing:false};
  const facade={skelKey:spec.skel,skel,boneNames:skel.bones.map(b=>THREE.PropertyBinding.sanitizeNodeName(b.name)),supportsShear:true,_bones:skel.bones.map(b=>{const sh=b.scaleMatrix?SHEAR_INDICES.map(i=>b.scaleMatrix[i]):null;return {sh:sh?.some(v=>Math.abs(v)>1e-7)?sh:null};})};
  const ms=Number(spec.params?.[1])||0;return {missing:!await models.loadClip(spec.anim,facade,{duration:ms>0?ms/1000:life})};
}

export class SkillEffectResources {
  constructor(engine,{deadlineMs=DEADLINE_MS}={}){this.engine=engine;this.game=engine.game;this.deadlineMs=deadlineMs;this.plans=new Map();this.queue=[];this.running=0;this.revision=0;this.warmRevision=0;this.pending=null;this.disposed=false;this.lastReport=null;}
  _run(work,owner){return new Promise((resolve,reject)=>{this.queue.push({work,owner,resolve,reject});this._drain();});}
  _cancelOwner(owner,error){
    owner.cancelled=true;
    const retained=[];for(const job of this.queue){if(job.owner===owner)job.reject(error);else retained.push(job);}this.queue=retained;
  }
  _drain(){
    while(!this.disposed&&this.running<WORKERS&&this.queue.length){
      const job=this.queue.shift();if(job.owner.cancelled){job.reject(aborted());continue;}
      this.running++;
      // A timed-out waiter does not release the physical resource-load slot.
      // Shared cache requests may still settle; never start unbounded replacements.
      Promise.resolve().then(job.work).then(job.resolve,error=>{this._cancelOwner(job.owner,error);job.reject(error);}).finally(()=>{this.running--;this._drain();});
    }
  }
  prepare(plan){
    if(this.disposed)return Promise.reject(aborted());if(!plan)return Promise.resolve(null);
    const old=this.plans.get(plan.key);if(old){this.plans.delete(plan.key);this.plans.set(plan.key,old);return old.promise;}
    if([...this.plans.values()].filter(row=>!row.ready).length>=WORKERS)return Promise.reject(new Error('Skill preparation is busy. Retry the skill.'));
    const record={ready:false,promise:null},owner={cancelled:false};this.plans.set(plan.key,record);
    while(this.plans.size>MAX_PLANS){const entry=[...this.plans].find(([,value])=>value.ready);if(!entry)break;this.plans.delete(entry[0]);}
    const report={key:plan.key,scenes:plan.refs.size,units:plan.units.size,paths:plan.paths.size,unavailable:[...plan.missing]};
    const jobs=[...plan.units].map(([key,unit])=>this._run(()=>warmUnit(this.game,unit),owner).then(result=>{if(result.missing)report.unavailable.push({kind:'resource',key});}));
    jobs.push(...[...plan.paths].map(([key,spec])=>this._run(()=>warmPath(this.game,spec),owner).then(result=>{if(result.missing)report.unavailable.push({kind:'bonePath',key});})));
    let timer;const deadline=new Promise((_,reject)=>{timer=setTimeout(()=>{const error=Object.assign(new Error('Skill resources did not finish. Retry the skill.'),{skillResourceTimeout:true});this._cancelOwner(owner,error);reject(error);},this.deadlineMs);});
    record.promise=Promise.race([Promise.all(jobs),deadline]).then(()=>{if(this.disposed)throw aborted();record.ready=true;this.lastReport=report;return report;}).catch(error=>{if(this.plans.get(plan.key)===record)this.plans.delete(plan.key);throw error;}).finally(()=>clearTimeout(timer));
    return record.promise;
  }
  async warmKnown(){
    const revision=++this.warmRevision;let expired=false,timer;
    const work=(async()=>{for(const skill of this.engine.list||[]){
      if(this.disposed||expired||this.warmRevision!==revision)throw aborted();
      if(this.engine.isPassive(skill)||!skillWeaponCompatible(skill,this.engine.equippedStyle())||!(this.engine.skillLevel(skill.index)>0))continue;
      await this.prepare(skillResourcePlan(this.engine,skill.index));
    }})();
    const deadline=new Promise((_,reject)=>{timer=setTimeout(()=>{expired=true;reject(Object.assign(new Error('Skill resource preparation did not finish. Retry loading.'),{skillResourceTimeout:true}));},this.deadlineMs);});
    try{return await Promise.race([work,deadline]);}finally{clearTimeout(timer);}
  }
  cancel(){this.revision++;this.pending=null;}
  /** true means this press is pending; no gameplay or host command has run. */
  defer(id,opts,resume){
    // Already-triggered gameplay procs are not new user intent and cannot be delayed.
    if(opts.fromProc)return false;
    opts={...opts};
    const plan=skillResourcePlan(this.engine,id,opts);if(!plan||this.plans.get(plan.key)?.ready){this.cancel();return false;}
    const g=this.game,p=g.player,ctl=g.controller,network=g.network,target=opts.target||p?.target||ctl?.target,point=opts.point?{...opts.point}:undefined;
    if(this.pending?.key===plan.key&&this.pending.target===target&&JSON.stringify(this.pending.point)===JSON.stringify(point))return true;
    const snapshot={player:p,world:g.world,map:g._mapLoadGeneration,intent:ctl?._inputIntentRevision,controller:ctl,token:network?.token,lease:network?._leaseGeneration,effects:this.engine._effectGeneration,style:plan.style,level:plan.level,classIndex:g.classDef?.index};
    const request={key:plan.key,target,point,revision:++this.revision};this.pending=request;
    const valid=()=>!this.disposed&&this.pending===request&&this.revision===request.revision&&g.player===snapshot.player&&!p?.dead&&!p?.disposed&&g.world===snapshot.world&&g._mapLoadGeneration===snapshot.map&&g.classDef?.index===snapshot.classIndex&&g.controller===snapshot.controller&&ctl?._inputIntentRevision===snapshot.intent&&g.network===network&&network?.token===snapshot.token&&network?._leaseGeneration===snapshot.lease&&this.engine._effectGeneration===snapshot.effects&&this.engine.equippedStyle()===snapshot.style&&(Number(opts.level)||this.engine.skillLevel(id))===snapshot.level&&(!target||!target.disposed&&!target.dead)&&(opts.target||(p?.target||ctl?.target)===target)&&(!network||network.ready);
    void this.prepare(plan).then(()=>{if(!valid())return;this.pending=null;resume({...opts,...(target?{target}:{}),...(point?{point}:{})});}).catch(error=>{if(this.pending===request){this.pending=null;if(error.name!=='AbortError')this.engine._msg?.('Skill graphics are still loading. Please retry.');}if(error.name!=='AbortError')console.warn('[skills] resource preparation',error);});
    return true;
  }
  dispose(){this.disposed=true;this.cancel();for(const job of this.queue.splice(0))job.reject(aborted());this.plans.clear();}
}
