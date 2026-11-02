// Native placed map visuals from .mel and the original effectscene/effectdata catalogs.
// Keep authored placement, full orientation, scale, scene controls and period.
// Sound invocation and actor-only meshstatus are deliberately not inferred. Cate-9 local lights are inventoried via mel-local-lights.js (Global geometry.fx PointLight call is commented out; no invented THREE.PointLight).
import {parseMel} from '../formats/mel.js';
import {nativeLightPlacements} from './mel-local-lights.js';
export {nativeLightPlacements, resolveMelLocalLights, isMelLocalLightEntry, MEL_LIGHT_CATEGORY} from './mel-local-lights.js';
import {parseEffectScenes,describeControl,describeUnit,gamePathToData} from '../systems/items/native-effect-parser.js';
import {parseTpack,textureCandidates} from '../formats/tpack.js';
import {parseMesh} from '../formats/mesh.js';
import {fetchBuffer} from '../engine/assets.js';
import {AuthoredEffectsData} from '../systems/items/authored-effects-data.js';
import {EffectPlayer} from '../systems/skills/effects.js';
import {supportsPlacedSnowWeather} from '../systems/skills/map-weather-unit.js';
import {awaitLoadingStage} from '../engine/loading-deadline.js';
import {warmWholeScene} from '../engine/warm-draw.js';

export const GATE_SCENE = Object.freeze({cate:5,id:20007,scene:1});
// gate_02 is the client's authored pink counterpart of the blue gate_01:
// the same nine animated meshes with their original *_red# texture packs.
export const RETURN_GATE_SCENE = Object.freeze({cate:5,id:20242,scene:1,timeMs:27000});
const GATE_RANGE = 85;
export const MAP_EFFECT_LIMIT = Number.MAX_SAFE_INTEGER; // compatibility export: no count-based omission of visible scenes
const VISUAL_TYPES=new Set(['sprite','decal','mesh','particle','weather']);
export class MapEffectsData extends AuthoredEffectsData {
 /** First absent skeleton/animation of a control's bone_animation path, or null when it has none or both exist. */
 async absentPathAsset(control){
  for(const key of [control.boneAnim?.skel,control.boneAnim?.anim]){
   if(!key)continue;
   try{await this.buffer(key);}catch(error){if(error?.missing!==true&&error?.code!=='ENOENT')throw error;return key;}
  }
  return null;
 }
 async load(ref){const key=ref.cate+':'+ref.id;if(this.scenes.has(key))return;if(this.pending.has(key))return this.pending.get(key);const job=this._load(ref).finally(()=>this.pending.delete(key));this.pending.set(key,job);return job;}
 async _load(ref){
  for(const file of ['map','com','01','02','03']){
   const block=(await this.index('property/effect/effectscene.'+file+'.txt',true)).get(ref.cate+':'+ref.id);if(!block)continue;
   const scene=parseEffectScenes(block,file)[0],selected={...scene,scenes:{},res:{},unresolved:[]};
   const active=new Set(scene.scenes.flatMap(s=>s.controls.map(describeControl)).filter(c=>c.active!==false).map(c=>c.unit));
   for(const [id,name]of Object.entries(scene.res)){
    if(!active.has(Number(id)))continue;const resolved=await this.resolveUnit(name,file),unit=resolved.unit;
    if(!unit||!VISUAL_TYPES.has(unit.unittype)){selected.unresolved.push({res:Number(id),name,reason:unit?'unsupported:'+unit.unittype:resolved.reason||'unit',...(resolved.files?{files:resolved.files}:{})});continue;}
    const packs=new Map();if(unit.fields.texturepack){const key=gamePathToData('texturepack',unit.fields.texturepack);let bytes;try{bytes=await this.buffer(key);}catch(error){if(error?.missing!==true&&error?.code!=='ENOENT')throw error;selected.unresolved.push({res:Number(id),name,reason:'tpack',key});continue;}const tp=parseTpack(bytes),resolve=t=>textureCandidates(tp.texpath,t)[0]||null;packs.set(key,{key,frames:tp.slots.map(slot=>resolve(tp.diffuse[slot])),textures:tp.slots.map(slot=>({material:slot,diffuse:resolve(tp.diffuse[slot])}))});}
    const typed=describeUnit(unit,{path:gamePathToData,texture:p=>gamePathToData('texture',p),tpack:p=>packs.get(gamePathToData('texturepack',p))});
    if(typed.type==='weather'&&!supportsPlacedSnowWeather(typed)){selected.unresolved.push({res:Number(id),name,reason:'unsupported:weather-form'});continue;}
    const assets=[...new Set([typed.mesh,typed.skel,typed.anim,typed.texture,...(typed.frames||[]),...(typed.textures||[]).map(t=>t.diffuse)].filter(Boolean))];let absent=false;
    for(const asset of assets){try{await this.buffer(asset);}catch(error){if(error?.missing!==true&&error?.code!=='ENOENT')throw error;selected.unresolved.push({res:Number(id),name,reason:'asset',key:asset});absent=true;}}
    if(absent)continue;
    const key='map:'+unit.file+':'+name.toLowerCase();this.units.set(key,typed);selected.res[id]=key;
   }
   // A control whose bone_animation skeleton/animation file is absent from the client cannot be played (the Global data itself
   // lacks effect/back/fly_01.skel + .anim for scene 5:20127). Leave only that control off and record it, like an absent unit
   // asset above, so one authored hole cannot fail the whole "nearby map effects" loading stage.
   for(const part of scene.scenes){
    const controls=[];
    for(const raw of part.controls){
     const control=describeControl(raw);
     const absent=control.active===false?null:await this.absentPathAsset(control);
     if(absent){control.active=false;selected.unresolved.push({res:control.unit,name:part.name,reason:'path-asset',key:absent});}
     controls.push(control);
    }
    selected.scenes[part.sceneId]={name:part.name,controls};
   }
   const live=new Set(Object.values(selected.scenes).flatMap(s=>s.controls).filter(c=>c.active!==false).map(c=>String(c.unit)));
   for(const id of Object.keys(selected.res))if(!live.has(id))delete selected.res[id];
   this.scenes.set(ref.cate+':'+ref.id,selected);return;
  }
 }
}
export function nativeVisualPlacements(mel){return parseMel(mel).entries.filter(e=>![0,3,4,9].includes(e.category)&&e.effectId>0&&e.period>0&&[e.x,e.z,e.y,e.scale,e.qx,e.qy,e.qz,e.qw].every(Number.isFinite)&&e.scale>0).map(e=>({...e,ref:{cate:e.category,id:e.effectId,scene:1},handle:null}));}

export function nativeGatePlacements(mel) {
  return parseMel(mel).entries.filter(e=>e.category===GATE_SCENE.cate&&e.effectId===GATE_SCENE.id&&
    Number.isFinite(e.x)&&Number.isFinite(e.z)&&Number.isFinite(e.y)&&Number.isFinite(e.scale)&&e.scale>0);
}

export function returnPortalPlacements(world, catalog) {
  const defs = catalog?.npcs || {};
  return (world.npcPlacements || []).filter(p => {
    const d = defs[p.npcIndex];
    return d?.shape === 'portal_deka' && d?.name === 'Return Portal';
  }).map(p => ({
    x:p.x,z:p.z,y:world.heightAt?.(p.x,p.z)??world.terrainHeightAt(p.x,p.z),yaw:(p.dirDeg||0)*Math.PI/180,
    scale:1,period:27000,ref:RETURN_GATE_SCENE,npcIndex:p.npcIndex,handle:null,
  }));
}

// gate_02 meshes are centered on their origin, unlike the feet-grounded NPC
// they replace. Resolve their native size and bounds once before playback so
// the bottom of the pink gate rests on its supporting floor rather than below it.
export async function returnGateGroundOffset(library, meshSource) {
  const scene=library.scene(`${RETURN_GATE_SCENE.cate}:${RETURN_GATE_SCENE.id}`);
  const controls=scene?.scenes?.[RETURN_GATE_SCENE.scene]?.controls||[];
  const bottoms=await Promise.all(controls.filter(c=>c.active!==false).map(async c=>{
    const unit=library.unit(scene.res[c.unit]);
    if(unit?.type!=='mesh'||!unit.mesh)return 0;
    const mesh=await meshSource(unit.mesh), minY=mesh?.bbox?.min?.[1];
    if(!Number.isFinite(minY))throw new Error(`Missing native gate bounds: ${unit.mesh}`);
    return minY*(Number(unit.size)||1)+(Number(c.pos?.[1])||0);
  }));
  return Math.max(0,...bottoms.map(y=>-y));
}

export class PortalEffects {
  constructor(game,world,{source=fetchBuffer,library=new MapEffectsData()}={}) {
    this.game=game;this.world=world;this.source=source;this.library=library;
    this.entries=[];this.excluded=[];this.localLightPlacements=[];this.fx=null;this.disposed=false;this.ready=false;
  }
  async load(key) {
    const melBuf=key?await this.source(key):null;
    const gates=melBuf?nativeVisualPlacements(melBuf):[];
    // Cate-9 inventory only (no THREE.PointLight — Global terrain PointLight path is commented out).
    this.localLightPlacements=melBuf?nativeLightPlacements(melBuf):[];
    const returns=returnPortalPlacements(this.world,this.game.data?.npcs);
    if(this.disposed||!gates.length&&!returns.length)return;
    const refs=[...new Map([...gates.map(e=>e.ref),...returns.map(e=>e.ref)].map(ref=>[ref.cate+':'+ref.id,ref])).values()];
    await Promise.all(refs.map(ref=>this.library.load(ref)));
    if(returns.length){
      const lift=await returnGateGroundOffset(this.library,key=>this.game.models?.mesh
        ?this.game.models.mesh(key):Promise.resolve(this.source(key)).then(parseMesh));
      for(const entry of returns){entry.groundOffset=lift*entry.scale;entry.y+=entry.groundOffset;}
    }
    if(this.disposed)return;
    this.entries=[...gates,...returns].filter(e=>{const scene=this.library.scene(e.ref.cate+':'+e.ref.id);return scene&&Object.values(scene.res||{}).some(key=>VISUAL_TYPES.has(this.library.unit(key)?.type));});
    this.excluded=refs.filter(ref=>!this.entries.some(e=>e.ref.cate===ref.cate&&e.ref.id===ref.id)).map(ref=>({scene:ref.cate+':'+ref.id,reason:this.library.scene(ref.cate+':'+ref.id)?'no-supported-visual-controls':'missing-scene'}));
    if(!this.entries.length)return;
    this.fx=new EffectPlayer(this.game,this.library);this.fx.soundOn=false;
    this.ready=true;
  }
  async preloadAt(x,z){
    if(this.disposed||!this.ready)return {units:0,excluded:this.excluded};
    this.update(0,x,z);
    this.preloading=true;
    try{
    const controls=[...this.fx.active].flatMap(play=>play.controls).filter(c=>c.def.active!==false&&c.unitDef);
    for(const control of controls)control.prepare();
    const units=controls.map(c=>c.unit).filter(Boolean),current=()=>!this.disposed&&!this.world._disposed&&!this.game.renderer?.getContext?.()?.isContextLost?.();
    await awaitLoadingStage(()=>Promise.all(controls.flatMap(c=>[c.unit?.readyTask,c.path?.readyTask].filter(Boolean))),{current,stage:'Nearby map effect assets'});
    const failed=controls.filter(c=>!c.unit||c.unit.loadError||!c.unit.ready||c.path?.failed||(c.unitDef.skel&&!c.unit.inst)||(c.unitDef.anim&&!c.unit.action)||(c.path&&(!c.path.bone||!c.path.mixer))).map(c=>c.unitDef.mesh||c.unitDef.texture||c.unitDef.file||String(c.def.unit));
    if(failed.length)throw new Error('Nearby map effect assets failed: '+[...new Set(failed)].join(', '));
    for(const control of controls)control._pose(0);
    const restore=[],temporaryParticles=[];
    try{
      for(const control of controls){
        for(const object of [control.anchor,control.unit.object])if(object){restore.push([object,object.visible]);object.visible=true;}
        const unit=control.unit;
        // Warm one authored particle in a locked draw, restoring its untouched timeline.
        if(unit.parts&&!unit.parts.length){temporaryParticles.push([unit,unit.parts,unit.spawned]);unit.parts=[];unit._spawn(1);unit._build();}
      }
      const game=this.game;
      if(game.renderer){
        await awaitLoadingStage(()=>game.renderer.compileAsync?.(this.fx.root,game.camera,game.scene),{current,stage:'Nearby map effect graphics'});
        if(!current()||!warmWholeScene(game))throw new Error('Nearby map effect graphics could not finish their first draw.');
      }
    }finally{
      for(const [unit,parts,spawned]of temporaryParticles){unit.parts=parts;unit.spawned=spawned;unit._build();}
      for(const [object,visible]of restore.reverse())object.visible=visible;
    }
    const excluded=[...this.excluded,...[...this.library.scenes.values()].flatMap(s=>(s.unresolved||[]).map(row=>({scene:s.cate+':'+s.id,...row})))];
    this.preloaded={units:units.length,later:controls.filter(c=>c.prepared).length,excluded};return this.preloaded;
    }finally{this.preloading=false;}
  }
  update(dt,x,z) {
    if(this.disposed||!this.ready||this.preloading)return;
    const distance=Number(this.world.cullDistance),range=Number.isFinite(distance)&&distance>0?distance:GATE_RANGE,r2=range*range;
    const visible=new Set(this.entries.filter(e=>(e.x-x)**2+(e.z-z)**2<=r2).sort((a,b)=>((a.x-x)**2+(a.z-z)**2)-((b.x-x)**2+(b.z-z)**2)));
    for(const e of this.entries) {
      // Keep the NPC actor and its click volume, but replace the red-orb body
      // with the original pink gate animation once that scene is available.
      if(e.npcIndex!=null){
        // The original return point stands on an authored walkway, whose
        // ground helper may stream after the portal. Resnap to that floor;
        // these fixed scene anchors need a fresh handle when the floor rises.
        const floor=this.world.heightAt?.(e.x,e.z)??this.world.terrainHeightAt(e.x,e.z);
        const y=floor+(e.groundOffset||0);
        if(Number.isFinite(y)&&Math.abs(y-e.y)>1e-5){e.y=y;e.handle?.stop(true);e.handle=null;}
        const npc=this.game.npcs?.find(n=>n.npcIndex===e.npcIndex&&Math.hypot(n.x-e.x,n.z-e.z)<1);
        const body=npc?.instance?.root||npc?.object;
        if(body)body.visible=false;
      }
      const near=visible.has(e);
      if(!near){if(e.handle){e.handle.stop(true);e.handle=null;}continue;}
      if(e.handle?.done)e.handle=null;
      if(e.handle)continue;
      const yaw=e.yaw??2*Math.atan2(e.qy,e.qw);
      // Gate .mel Y is the authored world elevation. Adding the terrain height
      // again lifts the Deneb entrance several metres above its original spot.
      const owner={x:e.x,z:e.z,y:e.y,yaw,height:0,mapPlacementScale:e.scale,quaternion:e.qw!=null?[e.qx,e.qy,e.qz,e.qw]:undefined};
      e.handle=this.fx.play(owner,{...e.ref,timeMs:e.period},{loop:true,scale:e.scale,particleSpace:'world'});
    }
    this.fx.update(dt);
  }
  dispose() {
    this.disposed=true;
    this.fx?.dispose();this.fx=null;this.entries=[];this.ready=false;
  }
}
