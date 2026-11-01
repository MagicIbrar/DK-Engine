import {Bloom,bloomFromEnvironment,BLOOM_LEVELS} from '../../systems/graphics/bloom.js';
import {DEFAULTS} from '../../systems/hud-options/settings.js';
import {SPEC,setEnvironment,currentEnvironment,loadEnvironmentCube} from '../../engine/matfx.js';

/** Read-only frontend options: explicit saved off always wins over migration. */
export function frontPresentationOptions(storage=globalThis.localStorage){
 let saved={},migrated=false;try{const raw=JSON.parse(storage?.getItem('dekaron-solo:options:v1')||'null');if(raw&&typeof raw==='object'&&!Array.isArray(raw))saved=raw;migrated=!!storage?.getItem('dekaron-solo:gfx:v1');}catch{}
 const options={...DEFAULTS,...saved};
 if(!Object.hasOwn(saved,'bloom')&&!migrated&&options.quality!=='poor')options.bloom=true;
 return options;
}

/** Same native quarter-resolution bloom as Game; no renderer wrapping survives handoff. */
export class FrontPresentation{
 constructor(stage,{BloomClass=Bloom,loadEnvironment=loadEnvironmentCube,storage=globalThis.localStorage}={}){
  this.stage=stage;this.BloomClass=BloomClass;this.loadEnvironment=loadEnvironment;this.options=frontPresentationOptions(storage);this.previousGain=SPEC.gain.value;this.previousEnvironment=currentEnvironment();this.disposed=false;
 }
 async setWorld(world){
  this.world=world;const generation=this.generation=(this.generation||0)+1;
  // BoneAnimEnv samples the authored cube, never the map water/sky 2D strip.
  const texture=await this.loadEnvironment(this.stage.textures);
  if(!texture?.isCubeTexture)throw new Error('The native character reflection cube could not finish loading. Retry the scene.');
  if(!this.disposed&&generation===this.generation&&this.stage.world===world)setEnvironment(texture);
 }
 render(){
  if(this.disposed)return;
  const stage=this.stage,options=this.options;
  SPEC.gain.value=options.specular?1:0;
  stage.renderer.render(stage.scene,stage.camera);
  const env=bloomFromEnvironment(stage.world?.environment?.current);
  if(!options.bloom||!env.enabled||this.broken)return;
  const bloom=this.bloom||=new this.BloomClass(stage.renderer);bloom.scale=4;
  const level=Number(options.bloomLevel);bloom.params.pow=env.pow;bloom.params.weight=env.weight;bloom.params.intensity=env.strength*BLOOM_LEVELS[Math.max(0,Math.min(2,Number.isFinite(level)?Math.round(level):1))];
  try{bloom.apply();}catch(error){this.broken=true;bloom.dispose();this.bloom=null;console.warn('[frontend] bloom unavailable; direct rendering retained',error);}
 }
 dispose(){if(this.disposed)return;this.disposed=true;this.generation=(this.generation||0)+1;this.bloom?.dispose();this.bloom=null;SPEC.gain.value=this.previousGain;setEnvironment(this.previousEnvironment);}
}
