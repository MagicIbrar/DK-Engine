// Action-table Effect -> modeleffect25/<creature>/1/<Effect> -> authored scene.
// Ordinary monsters/NPCs previously retained Effect in clip[7] but never dispatched it.
// ENGINE-CHOSEN ownership: the selected clip owns its effect; replacing it, removing the actor or changing world ends it.
// Audio remains owned by game/audio.js (monsterSfx/actionEffectSfx); this player is deliberately silent.
import {parseCSV} from '../formats/binreader.js';
import {AuthoredEffectsData} from '../systems/items/authored-effects-data.js';
import {EffectPlayer} from '../systems/skills/effects.js';

export function actionEffectRows(text){
 const rows=new Map();
 for(const r of parseCSV(text)){
  if(Number(r[0])!==25||![1,4].includes(Number(r[1]))||Number(r[2])!==1||!(Number(r[3])>0)||!(Number(r[5])>0)||[0,3,4].includes(Number(r[4])))continue;
  const key=`${Number(r[1])}:${Number(r[3])}`,ref={cate:Number(r[4]),id:Number(r[5]),scene:Number(r[6]),timeMs:Number(r[7]),loop:Number(r[8])};
  const prior=rows.get(key);if(!prior)rows.set(key,{ref});else if(JSON.stringify(prior.ref)!==JSON.stringify(ref))rows.set(key,{ambiguous:true});
 }
 return rows;
}
export function actionEffectKey(actor,spec){
 const set=actor.actionSet,clip=set?.clips?.[spec?.clipIndex],id=Number(clip?.[7]);
 if(!(id>0)||actor.def?.body==='effect')return null;
 // An NPC may explicitly borrow a monster action table. Follow its source namespace, not its interaction role.
 // The builder records the source table when a missing NPC state is explicitly filled from a matching monster table.
 const derived=Object.entries(set.derived||{}).filter(([state,source])=>source!=='convention'&&[set.states?.[state]].flat().includes(spec.clipIndex));
 const src=String((derived.find(([state])=>state===spec.state)||derived[0])?.[1]||set.src||'').replace(/\\/g,'/').toLowerCase();
 const kind=/(?:^|\/)monster\//.test(src)?1:/(?:^|\/)npc\//.test(src)?4:actor.kind==='monster'?1:actor.kind==='npc'?4:null;
 return kind?`${kind}:${id}`:null;
}
export function shapeEffectKey(actor){
 const id=Number(actor.shape?.effect);if(!(id>0)||actor.def?.body==='effect')return null;
 // A borrowed monster action table is explicit provenance. Do not infer a namespace from an NPC's model/name.
 const source=String(actor.actionSet?.src||'').replace(/\\/g,'/').toLowerCase();
 const kind=actor.kind==='monster'||/(?:^|\/)monster\//.test(source)?1:actor.kind==='npc'?4:null;
 return kind?`${kind}:${id}`:null;
}
class ActionEffects {
 constructor(game){
  this.game=game;const shared=game.items?.authoredEffects?.data;
  this.data=new AuthoredEffectsData({...shared?{text:key=>shared.file(key),buffer:key=>shared.buffer(key)}:{},unitTypes:['sprite','decal','mesh','particle','meshstatus','sound','quake']});
  this.fx=new EffectPlayer(game,this.data);this.fx.soundOn=false;this.runs=new Map();this.shapes=new Map();this.warned=new Set();this.frame=null;
 }
 rows(){if(!this._rows)this._rows=this.data.file('script/effect/modeleffect.csv').then(actionEffectRows).catch(e=>{this._rows=null;throw e;});return this._rows;}
 async preload(actor){
  const rows=await this.rows(),refs=new Map();
  for(let i=0;i<(actor.actionSet?.clips?.length||0);i++){const row=rows.get(actionEffectKey(actor,{clipIndex:i}));if(row?.ref)refs.set(`${row.ref.cate}:${row.ref.id}`,row.ref);}
  const shape=rows.get(shapeEffectKey(actor));if(shape?.ref)refs.set(`${shape.ref.cate}:${shape.ref.id}`,shape.ref);
  await Promise.all([...refs.values()].map(ref=>this.data.load(ref).catch(e=>this.warn(`${ref.cate}:${ref.id}`,e))));
 }
 warn(key,error){if(this.warned.has(key))return;this.warned.add(key);console.warn('[actors] authored action effect unavailable',key,error?.message||error);}
 stop(actor,all=false){const run=this.runs.get(actor);this.runs.delete(actor);run?.handle?.stop(true);if(all){const shape=this.shapes.get(actor);this.shapes.delete(actor);shape?.handle?.stop(true);}}
 startShape(actor){
  const key=shapeEffectKey(actor),previous=this.shapes.get(actor);if(previous&&previous.key===key&&this.valid(previous))return;
  if(previous){this.shapes.delete(actor);previous.handle?.stop(true);}
  if(!key||actor.dead||actor.disposed||actor.faded)return;
  const run={actor,key,world:this.game.world,persistent:true,at:Number(this.game.time)||0,phase:0,handle:null};this.shapes.set(actor,run);this.resolve(run,this.shapes);
 }
 start(actor,spec,clip,opts={}){
  this.stop(actor);this.startShape(actor);const key=actionEffectKey(actor,spec);if(!key||actor.disposed||actor.def?.body==='effect'||key===this.shapes.get(actor)?.key)return;
  const phase=Number(opts.startAt)>0?Number(opts.startAt):Number(opts.startPhase)>0?Number(opts.startPhase)*clip.duration:0;
  const run={actor,key,world:this.game.world,seq:actor._playSeq,state:spec.state,at:Number(this.game.time)||0,phase,handle:null};this.runs.set(actor,run);
  this.resolve(run,this.runs);
 }
 resolve(run,registry){
  const {actor,key,phase}=run;
  void this.rows().then(async rows=>{
   const row=rows.get(key);if(!row?.ref){if(row?.ambiguous)this.warn(key,'conflicting native modeleffect rows');return;}
   const ref=row.ref;await this.data.load(ref);
   if(registry.get(actor)!==run||!this.valid(run))return;
   run.ref=ref;this.spawn(run);
  }).catch(error=>this.warn(key,error));
 }
 spawn(run){
  const {actor,ref,phase}=run,elapsed=Math.max(0,(Number(this.game.time)||0)-run.at)+phase,period=ref.timeMs/1000;
  if(ref.loop!==0&&period>0&&elapsed>=period)return;
  this.fx.enabled=this.game.effects?.enabled!==false;
  const handle=this.fx.play(actor,ref,{loop:ref.loop===0,...run.persistent?{particleSpace:'attachment'}:{}});run.handle=handle;
  // ENGINE-CHOSEN retry cadence: a persistent aura first loaded out of range/with effects disabled must appear on return.
  run.retryAt=(Number(this.game.time)||0)+.5;
  if(handle&&elapsed>0)handle.update(ref.loop===0&&period>0?elapsed%period:elapsed);
 }
 valid(run){const actor=run.actor;return !actor.disposed&&!actor.faded&&(run.persistent||actor._playSeq===run.seq)&&this.game.world===run.world&&(!actor.dead||run.state==='die');}
 tick(dt,actor=null){
  // An actor can become invalid after this frame's shared sweep. Clean its
  // own bindings immediately without rescanning the world's other actors.
  const current=actor&&this.runs.get(actor);
  if(current&&(!this.valid(current)||current.handle?.done))this.stop(actor);
  const shape=actor&&this.shapes.get(actor);
  if(shape&&!this.valid(shape)){this.shapes.delete(actor);shape.handle?.stop(true);}
  const stamp=this.game.time;if(stamp!=null&&stamp===this.frame)return;this.frame=stamp;
  for(const [actor,run]of this.runs)if(!this.valid(run)||run.handle?.done)this.stop(actor);
  for(const [actor,run]of this.shapes)if(!this.valid(run)){this.shapes.delete(actor);run.handle?.stop(true);}
  for(const run of [...this.runs.values(),...this.shapes.values()])if(!run.handle&&run.ref?.loop===0&&(Number(stamp)||0)>=run.retryAt)this.spawn(run);
  this.fx.enabled=this.game.effects?.enabled!==false;this.fx.update(dt);
 }
}
export function authoredActionEffects(game){return game.authoredActionEffects||=new ActionEffects(game);}
export function stopActionEffects(actor,all=false){actor.game?.authoredActionEffects?.stop(actor,all);}
