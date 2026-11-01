// Exact SERVANT action rows -> modeleffect25/2/1/Effect. The selected clip owns
// this lane; summon entry/status/leave effects remain separately owned.
import {parseCSV} from '../../formats/binreader.js';
import {parseActionDat} from '../../formats/modeldef.js';
import {AuthoredEffectsData} from '../items/authored-effects-data.js';
import {EffectPlayer,playedSceneKey,soundSceneKey} from './effects.js';
const norm=p=>String(p||'').replace(/\\/g,'/').toLowerCase();
export function servantEffectRows(text){
 const out=new Map();for(const r of parseCSV(text)){
  if(Number(r[0])!==25||Number(r[1])!==2||Number(r[2])!==1||!(Number(r[3])>0)||!(Number(r[5])>0))continue;
  const ref={cate:Number(r[4]),id:Number(r[5]),scene:Number(r[6]),timeMs:Number(r[7]),loop:Number(r[8])},id=Number(r[3]),old=out.get(id);
  if(!old)out.set(id,{ref});else if(JSON.stringify(old.ref)!==JSON.stringify(ref))out.set(id,{ambiguous:true});
 }return out;
}
export function servantActionEffect(spec,native){
 const row=spec?.servantAction;if(!row)return 0;
 if(Object.hasOwn(row,'effect'))return Number(row.effect)||0;
 let choices=(native?.actions||[]).filter(r=>r.actionId===spec.servantActionId&&norm(r.animKey)===norm(row.anim));
 if(row.index!=null)choices=choices.filter(r=>r.index===Number(row.index));
 else {const preferred=choices.filter(r=>r.index===0);if(preferred.length)choices=preferred;}
 const ids=[...new Set(choices.map(r=>Number(r.effect)||0))];return ids.length===1?ids[0]:0;
}
class ServantEffects{
 constructor(game){
  this.game=game;const shared=game.items?.authoredEffects?.data;
  this.data=new AuthoredEffectsData({...shared?{text:p=>shared.file(p),buffer:p=>shared.buffer(p)}:{},unitTypes:['sprite','decal','mesh','particle','meshstatus','sound','quake']});
  this.fx=new EffectPlayer(game,this.data);this.fx.soundOn=true;this.runs=new Map();this.sources=new Map();this.warned=new Set();
 }
 warn(key,e){if(this.warned.has(key))return;this.warned.add(key);console.warn('[servants] authored effect unavailable',key,e?.message||e);}
 rows(){return this._rows||=(this.data.file('script/effect/modeleffect.csv').then(servantEffectRows).catch(e=>{this._rows=null;throw e;}));}
 async prepare(actor){
  const d=actor.def,clips=[...Object.values(d.anims||{}),...(d.attacks||[])];let native=null;
  if(clips.some(r=>!Object.hasOwn(r,'effect'))&&d.actionFile){
   const file=norm(d.actionFile);if(!/^share\/action\/action\/servant\/[^/]+\.dat$/.test(file))throw Error('invalid servant action path');
   if(!this.sources.has(file))this.sources.set(file,Promise.resolve(this.data.buffer(file)).then(parseActionDat));
   native=await this.sources.get(file);
   if(native.creature!=='SERVANT'||native.index!==Number(d.index)||norm(native.skelKey)!==norm(d.skeleton))throw Error('servant native action identity mismatch');
  }
  actor.nativeServantActions=native;
  const rows=await this.rows(),ids=new Set([...clips.map(r=>Number(r.effect)||0),...(native?.actions||[]).map(r=>Number(r.effect)||0)]);
  await Promise.all([...ids].filter(Boolean).map(async id=>{const r=rows.get(id);if(r?.ambiguous)this.warn(id,'conflicting modeleffect rows');else if(r?.ref)await this.data.load(r.ref).catch(e=>this.warn(id,e));else this.warn(id,'missing modeleffect row');}));
 }
 stop(actor){const run=this.runs.get(actor);this.runs.delete(actor);run?.handle?.stop(true);for(const h of run?.sounds||[])h?.stop?.();}
 valid(run){return this.runs.get(run.actor)===run&&!run.actor.disposed&&!run.actor.faded&&run.actor._playSeq===run.seq&&this.game.world===run.world&&(!run.actor.dead||run.state==='die');}
 start(actor,spec,clip,opts={}){
  this.stop(actor);if(actor.disposed)return;
  const phase=Number(opts.startAt)>0?Number(opts.startAt):Number(opts.startPhase)>0?Number(opts.startPhase)*clip.duration:0;
  const run={actor,seq:actor._playSeq,state:spec.state,world:this.game.world,at:Number(this.game.time)||0,phase,sounds:[],handle:null};this.runs.set(actor,run);
  const id=servantActionEffect(spec,actor.nativeServantActions);
  void this.rows().then(async rows=>{
   const ref=rows.get(id)?.ref;if(ref)await this.data.load(ref);if(!this.valid(run))return;
   const elapsed=Math.max(0,(Number(this.game.time)||0)-run.at)+phase;
   if(ref&&!(ref.loop!==0&&ref.timeMs>0&&elapsed>=ref.timeMs/1000)){
    this.fx.enabled=this.game.effects?.enabled!==false;run.handle=this.fx.play(actor,ref,{loop:ref.loop===0});
    if(run.handle&&elapsed>0)run.handle.update(ref.loop===0&&ref.timeMs>0?elapsed%(ref.timeMs/1000):elapsed);
   }
   // A resumed observer animation is not a new sound event. Do not double a
   // basic creature voice whose exact path is already in the authored scene.
   if(phase>0)return;
   const excluded=new Set(),scene=ref&&this.data.scene(`${ref.cate}:${ref.id}`),sceneKey=playedSceneKey(scene,ref?.scene);
   if(ref){const S=this.game.audio?.S,book=ref.cate===100?S?.skill?.[ref.id]:S?.effectSound?.[ref.cate]?.[ref.id];
    for(const r of book?.scenes?.[String(soundSceneKey(ref.scene,sceneKey))]||[])excluded.add(norm(r.path).replace(/^sound\//,''));
    for(const c of scene?.scenes?.[sceneKey]?.controls||[]){if(c.active===false)continue;const u=this.data.unit(scene.res[c.unit]);if(u?.type==='sound')excluded.add(norm(u.sound).replace(/^sound\//,''));}
   }
   const retain=h=>{if(!h)return;if(!this.valid(run))h.stop?.();else run.sounds.push(h);};
   await this.game.audio?.servantClip?.(actor,spec.state,{excluded,isCurrent:()=>this.valid(run),onHandle:retain});
  }).catch(e=>this.warn(`action:${actor.servantIndex}:${id}`,e));
 }
 tick(dt,actor){
  const own=this.runs.get(actor);if(own&&!this.valid(own))this.stop(actor);
  if(this.frame===this.game.time)return;this.frame=this.game.time;
  for(const [a,r]of this.runs)if(!this.valid(r))this.stop(a);
  this.fx.enabled=this.game.effects?.enabled!==false;this.fx.update(dt);
 }
}
export function servantEffects(game){return game.servantEffects||=new ServantEffects(game);}
