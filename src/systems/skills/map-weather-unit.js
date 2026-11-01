import * as THREE from 'three';
import {ParticleUnit} from './fx-units.js';

// MEL fireflies are weather/snow sprite volumes, not radial skill emitters.
// Other weather (rain/splashes/mesh leaves) retains an explicit unsupported result.
export function supportsPlacedSnowWeather(unit){
 const e=unit?.emitter;
 return unit?.type==='weather'&&unit.leaf==='sprite'&&e?.state==='snow'&&
  !Object.keys(e).some(k=>k.startsWith('flat'))&&!unit.tail?.on&&
  Number.isInteger(e.max)&&e.max>0&&e.max<=16384&&Number.isFinite(e.rate)&&e.rate>=0&&
  [e.startRange,e.lifetimeMs,e.velocity].every(a=>Array.isArray(a)&&a.length===2&&a.every(Number.isFinite))&&
  e.lifetimeMs.every(n=>n>0)&&[e.spawnDir,e.gravity].every(a=>Array.isArray(a)&&a.length===3&&a.every(Number.isFinite));
}

// Reuse the shared texture flipbook, authored control keys, gravity/lifetime,
// bounded particle pool, loading barrier and disposal. The snow spawn box and
// unnormalised direction match the existing native-weather path. Here the
// anchor is the authored MEL placement, never the moving viewer. Emission keeps
// the shared renderer's authored-rate policy; native tick-unit parity is unproven.
export class MapSnowWeatherUnit extends ParticleUnit {
 constructor(ctx,unit,parent){
  if(!supportsPlacedSnowWeather(unit))throw Error('Unsupported placed weather unit');
  super(ctx,unit,parent);
 }
 _spawn(count){
  const e=this.em,u=this.unit,M=this._anchorFrame(),origin=new THREE.Vector3().setFromMatrixPosition(M);
  const rotation=new THREE.Quaternion().setFromRotationMatrix(new THREE.Matrix4().extractRotation(M));
  const range=e.startRange,lo=Math.min(...range),hi=Math.max(...range),half=lo===hi?Math.abs(hi):null;
  const spread=()=>half===null?lo+Math.random()*(hi-lo):(Math.random()*2-1)*half;
  const sample=a=>a[0]+Math.random()*Math.max(0,a[1]-a[0]);
  const placementScale=Number(this.ctx.play?.owner?.mapPlacementScale)>0?Number(this.ctx.play.owner.mapPlacementScale):1;
  for(let i=0;i<count&&this.parts.length<this.max;i++){
   const offset=new THREE.Vector3(spread(),0,spread()).multiplyScalar(placementScale).applyQuaternion(rotation);
   const velocity=new THREE.Vector3(...e.spawnDir).multiplyScalar(sample(e.velocity));
   if(!e.spawnDirAbs)velocity.applyQuaternion(rotation);
   const sizes=e.particleSize||[0,0],size=(Number(u.size)||1)*(sizes.some(Boolean)?sample(sizes):1),cr=(Number(e.colorRange)||0)/100;
   this.parts.push({p:origin.clone().add(offset),v:velocity,t:0,life:sample(e.lifetimeMs)/1000,size,
    rot:(Math.random()*2-1)*THREE.MathUtils.degToRad(Number(e.addRotate)||0),frameSeed:Math.random(),trail:null,
    tint:cr>0?[1-Math.random()*cr,1-Math.random()*cr,1-Math.random()*cr]:null});
   this.spawned=(this.spawned||0)+1;
  }
 }
}
