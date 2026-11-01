// Exact native joins: vehicle action/shape Effect -> modeleffect 36/0/2/id;
// pet shape Effect -> modeleffect 40/7/1/id. No animation-name or adjacent-ID guesses.
import {fetchJSON} from '../../engine/assets.js';
import {parseCSV} from '../../formats/binreader.js';
import {parseActionDat} from '../../formats/modeldef.js';
import {AuthoredEffectsData} from '../items/authored-effects-data.js';
import {EffectPlayer} from '../skills/effects.js';
import {NATIVE_PET_SOURCE_ALIASES} from './native-pet-sources.js';
import * as THREE from 'three';
const norm=p=>String(p||'').trim().replace(/\\/g,'/').toLowerCase();
export function mountEffectRows(text){
 const rows=new Map();for(const r of parseCSV(text)){
  const kind=Number(r[0])===36&&Number(r[1])===0&&Number(r[2])===2?'vehicle':Number(r[0])===40&&Number(r[1])===7&&Number(r[2])===1?'pet':null;
  if(!kind||!(Number(r[3])>0)||!(Number(r[5])>0)||[0,3,4].includes(Number(r[4])))continue;
  const key=`${kind}:${Number(r[3])}`,ref={cate:Number(r[4]),id:Number(r[5]),scene:Number(r[6]),timeMs:Number(r[7]),loop:Number(r[8])};
  const old=rows.get(key);if(!old)rows.set(key,{ref});else if(JSON.stringify(old.ref)!==JSON.stringify(ref))rows.set(key,{ambiguous:true});
 }return rows;
}
export function vehicleShapeEffects(text){
 const rows=parseCSV(text),head=rows.shift()||[],columns=[];
 for(let c=3;c<head.length;c+=3){if(String(head[c]).trim().toLowerCase()!=='effect')break;columns.push(c);}
 return new Map(rows.filter(r=>Number(r[0])>0).map(r=>[Number(r[0]),columns.map(c=>Number(r[c])||0)]));
}
export function nativeVehicleEffect(native,row){
 if(!native||!row)return 0;
 const hits=native.actions.filter(r=>r.style===row.style&&r.actionId===row.action&&r.index===row.index&&norm(r.animKey)===norm(row.anim));
 const ids=[...new Set(hits.map(r=>Number(r.effect)||0))];return ids.length===1?ids[0]:0;
}
// Network observers use a game facade. Share the real world's clock, culling target and effect cache.
export function mountEffectGame(game){while(!Object.hasOwn(game,'worldRoot')&&Object.getPrototypeOf(game)?.worldRoot===game.worldRoot)game=Object.getPrototypeOf(game);return game;}
class NativeMountEffects{
 constructor(game){
  this.game=game;const shared=game.items?.authoredEffects?.data;
  this.data=new AuthoredEffectsData({...shared?{text:p=>shared.file(p),buffer:p=>shared.buffer(p)}:{},unitTypes:['sprite','decal','mesh','particle','meshstatus','sound','quake']});
  // These selected mount/pet scenes own their audio too (for example the
  // motorcycle stand/run WAVs). No basic actor-audio lane plays these cues.
  // ScenePlay keeps sound handles with the binding, including late cancellation.
  this.fx=new EffectPlayer(game,this.data);this.fx.soundOn=true;this.bindings=new Map();this.warned=new Set();this.native=new Map();this.frame=null;
 }
 warn(key,e){if(this.warned.has(key))return;this.warned.add(key);console.warn('[mounts] native effect unavailable',key,e?.message||e);}
 rows(){return this._rows||=(this.data.file('script/effect/modeleffect.csv').then(mountEffectRows).catch(e=>{this._rows=null;throw e;}));}
 async preload(kind,id){const ref=(await this.rows()).get(`${kind}:${id}`)?.ref;if(ref)await this.data.load(ref);}
 async vehicleSource(item,table,look,classIndex,actionIndex){
  let shape=look?.effect;
  if(shape==null){this._vehicleShapes||=this.data.file('script/shape/vehicle_shape.csv').then(vehicleShapeEffects);shape=(await this._vehicleShapes).get(Number(item))?.[classIndex]||0;}
  let native=null;
  if(table?.rows?.some(r=>r.length<6)){
   let file=table.file;
   if(!file){this._itemsActions||=fetchJSON('/gamedata/items-actions.json');file=(await this._itemsActions).vehicle?.[actionIndex]?.file;}
   file=norm(file);
   if(/^share\/action\/action\/vehicle\/[^/]+\.dat$/.test(file)){
    if(!this.native.has(file))this.native.set(file,Promise.resolve(this.data.buffer(file)).then(parseActionDat));
    native=await this.native.get(file);
    if(native.creature!=='VEHICLE'||native.index!==Number(actionIndex)||norm(native.skelKey)!==norm(table.skel))throw Error('vehicle action source identity mismatch');
   }
  }
  const ids=new Set([Number(shape)||0,...table.rows.map(r=>Number(r[5])||0),...(native?.actions||[]).map(r=>Number(r.effect)||0)]);
  await Promise.all([...ids].filter(Boolean).map(id=>this.preload('vehicle',id).catch(e=>this.warn(`vehicle:${id}`,e))));
  return {shape:Number(shape)||0,native};
 }
 async petEffect(def){
  let id=def.eff;
  if(id==null){this._petShapes||=this.data.file('script/shape/pet_shape.csv').then(text=>new Map(parseCSV(text).slice(1).map(r=>[norm(r[1]),Number(r[4])||0])));id=(await this._petShapes).get(norm(def.shape))||0;}
  if(id>0)await this.preload('pet',id);return Number(id)||0;
 }
 async petSource(def){
  const shape=await this.petEffect(def),table=def.table;let native=null;
  if(table?.rows?.some(r=>r.length<6)){
   try {
    this._itemsActions||=fetchJSON('/gamedata/items-actions.json');
    // Legacy caches omitted the source file. The native pet table naming convention
    // is only a candidate: header, skeleton and every retained action must match.
    const file=norm(table.file||(await this._itemsActions).pet?.[def.act]?.file||NATIVE_PET_SOURCE_ALIASES[def.act]||`share/action/action/pet/${def.act}.act.${norm(def.shape)}.dat`);
    if(!/^share\/action\/action\/pet\/[^/]+\.dat$/.test(file))throw Error('invalid pet action source path');
    if(!this.native.has(file))this.native.set(file,Promise.resolve(this.data.buffer(file)).then(parseActionDat));
    const parsed=await this.native.get(file),anims=(await this._itemsActions).anims;
    if(parsed.creature!=='PET'||parsed.index!==Number(def.act)||norm(parsed.skelKey)!==norm(table.skel)||table.rows.some(r=>!parsed.actions.some(n=>n.style===r[0]&&n.actionId===r[1]&&n.index===r[2]&&norm(n.animKey)===norm(anims[r[3]]))))throw Error('pet action source identity mismatch');
    native=parsed;
   }catch(error){this.warn(`pet-action-source:${def.act}`,error);}
  }
  const ids=new Set([...(table?.rows||[]).map(r=>Number(r[5])||0),...(native?.actions||[]).map(r=>Number(r.effect)||0)]);
  await Promise.all([...ids].filter(Boolean).map(id=>this.preload('pet',id).catch(e=>this.warn(`pet:${id}`,e))));
  const transitions={};
  for(const phase of ['enter','leave']){
   const id=Number(def.cr?.[phase]??def[phase]);if(!(id>0))continue;
   const refs=[...(await this.rows())].filter(([key,row])=>key.startsWith('pet:')&&row.ref?.id===id).map(([,row])=>row.ref);
   const unique=new Map(refs.map(ref=>[JSON.stringify(ref),ref]));
   if(unique.size!==1){this.warn(`pet-${phase}:${id}`,'missing or conflicting native pet scene mapping');continue;}
   const ref={...[...unique.values()][0]};
   if(phase==='leave'){
    const raw=def.cr?.raw||def.raw;
    if(raw?.LeaveSceneID!=null)ref.scene=Number(raw.LeaveSceneID);
    if(raw?.LeaveEffectTime!=null)ref.timeMs=Number(raw.LeaveEffectTime);
   }
   if(ref.loop===0||!(ref.timeMs>0)||!Number.isFinite(ref.scene)) {this.warn(`pet-${phase}:${id}`,'native transition is not finite');continue;}
   await this.data.load(ref);transitions[phase]=ref;
  }
  return {shape,native,transitions};
 }
 transition(token,owner,ref){
  this.stop(token);if(!ref||owner.disposed||owner.dead)return;
  const run={token,owner,key:`pet-transition:${ref.id}`,world:this.game.world,at:Number(this.game.time)||0,attached:false,ref,handle:null};
  this.bindings.set(token,run);
  void this.data.load(ref).then(()=>{if(this.bindings.get(token)!==run||!this.valid(run))return;this.spawn(run);}).catch(e=>{if(this.bindings.get(token)===run)this.stop(token);this.warn(run.key,e);});
 }
 snapshot(owner,ref){
  // Finite dismissal effects outlive the model. Retain only the authored bone
  // frames, never a skinned mesh/material or a live actor after its disposal.
  const names=new Set(['Bip01','Bip01 Spine1']);
  for(const scene of Object.values(this.data.scene(`${ref.cate}:${ref.id}`)?.scenes||{}))for(const c of scene.controls||[])if(c.bone)names.add(c.bone);
  const bones=new Map();
  for(const name of names){const bone=owner.instance?.getBone?.(name);if(!bone)continue;bone.updateWorldMatrix(true,false);const copy=new THREE.Object3D();copy.matrixWorld.copy(bone.matrixWorld);copy.updateWorldMatrix=()=>{};bones.set(norm(name),copy);}
  return {kind:'pet-transition',x:owner.x,y:owner.y,z:owner.z,yaw:owner.yaw,height:owner.height,scale:owner.scale,instance:{getBone:name=>bones.get(norm(name))||null},disposed:false};
 }
 stop(token){const old=this.bindings.get(token);this.bindings.delete(token);old?.handle?.stop(true);}
 bind(token,owner,kind,id,{attached=true}={}){
  this.stop(token);if(!(id>0)||owner.disposed||owner.dead)return;
  const run={token,owner,key:`${kind}:${id}`,world:this.game.world,at:Number(this.game.time)||0,attached,handle:null};this.bindings.set(token,run);
  void this.rows().then(async rows=>{
   const entry=rows.get(run.key);if(!entry?.ref){if(entry?.ambiguous)this.warn(run.key,'conflicting native rows');return;}
   await this.data.load(entry.ref);if(this.bindings.get(token)!==run||!this.valid(run))return;
   run.ref=entry.ref;this.spawn(run);
  }).catch(e=>this.warn(run.key,e));
 }
 valid(run){return !run.owner.disposed&&!run.owner.dead&&!run.owner.faded&&this.game.world===run.world;}
 spawn(run){
  const {ref,owner}=run,elapsed=Math.max(0,(Number(this.game.time)||0)-run.at),period=ref.timeMs/1000;
  if(ref.loop!==0&&period>0&&elapsed>=period)return;
  this.fx.enabled=this.game.effects?.enabled!==false;
  run.handle=this.fx.play(owner,ref,{loop:ref.loop===0,...run.attached?{particleSpace:'attachment'}:{}});run.retryAt=(Number(this.game.time)||0)+.5;
  if(run.handle&&elapsed>0)run.handle.update(ref.loop===0&&period>0?elapsed%period:elapsed);
 }
 tick(dt){
  const t=this.game.time;if(t!=null&&t===this.frame)return;this.frame=t;
  for(const [token,run]of this.bindings){const expired=!run.handle&&run.ref?.loop!==0&&run.ref?.timeMs>0&&(Number(t)||0)-run.at>=run.ref.timeMs/1000;if(!this.valid(run)||run.handle?.done||expired){this.stop(token);continue;}if(!run.handle&&run.ref?.loop===0&&(Number(t)||0)>=run.retryAt)this.spawn(run);}
  this.fx.enabled=this.game.effects?.enabled!==false;this.fx.update(dt);
 }
 dispose(){for(const token of this.bindings.keys())this.stop(token);this.fx.dispose();if(this.game.nativeMountEffects===this)delete this.game.nativeMountEffects;}
}
export function nativeMountEffects(game){const root=mountEffectGame(game);return root.nativeMountEffects||=new NativeMountEffects(root);}
