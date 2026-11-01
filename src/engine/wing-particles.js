// Original authored wing dust using the existing engine ParticleUnit, not native Favnil provenance.
import * as THREE from 'three';
import {ParticleUnit,cameraFrame} from '../systems/skills/fx-units.js';
export const WING_PARTICLE_LIMITS=Object.freeze({pairs:8,perEmitter:8,emitters:2,distance:60,nativeSceneLimit:220});
const budgets=new WeakMap();
function texture(){const n=16,data=new Uint8Array(n*n*4);for(let y=0;y<n;y++)for(let x=0;x<n;x++){const r=Math.hypot((x-7.5)/7.5,(y-7.5)/7.5),i=(y*n+x)*4;data[i]=data[i+1]=data[i+2]=255;data[i+3]=Math.round(Math.max(0,1-r)**2*255);}const t=new THREE.DataTexture(data,n,n);t.needsUpdate=true;t.minFilter=t.magFilter=THREE.LinearFilter;return t;}
export function wingParticleUsage(fx){return budgets.get(fx)?.count||0;}
export function bindWingParticles(game,wing,design){
 const fx=game?.effects;if(!fx?.root||!game.camera)return null;let budget=budgets.get(fx);if(!budget){budget={count:0,texture:null};budgets.set(fx,budget);}
 const at=new THREE.Vector3(),cam=new THREE.Vector3(),frame={},units=[];let disposed=false,registered=false;
 const release=()=>{for(const {unit,anchor}of units){unit.dispose();anchor.removeFromParent();}units.length=0;if(registered){registered=false;budget.count--;if(!budget.count){budget.texture?.dispose();budget.texture=null;}}};
 const hidden=()=>{for(let p=wing;p;p=p.parent)if(!p.visible)return true;return false;};
 const allocate=()=>{if(registered||budget.count>=WING_PARTICLE_LIMITS.pairs||(fx.active?.size||0)>=WING_PARTICLE_LIMITS.nativeSceneLimit)return;registered=true;budget.count++;budget.texture||=texture();const provider=Object.create(game);provider.textures={load:key=>key==='engine/wings/authored-dust'?Promise.resolve(budget.texture):game.textures?.load(key)||Promise.resolve(null)};
  for(const [i,parent]of wing.children.slice(0,2).entries()){const anchor=new THREE.Group();anchor.name='authored-wing-dust-anchor';anchor.position.set(i?.95:-.95,-.15,.24);parent.add(anchor);const def={unittype:'particle',texture:'engine/wings/authored-dust',blend:'add',billboard:'camera',size:.060,emitter:{max:WING_PARTICLE_LIMITS.perEmitter,state:'direct',lifetimeMs:[700,1100],velocity:[.03,.12],spawnDir:[0,-1,.2],startRange:[.03,.12],gravity:[0,-.012,0],particleSize:[.45,1],colorRange:10}},unit=new ParticleUnit({game:provider,fx:{root:fx.root,cam:frame}},def,anchor),color=new THREE.Color(design.palette[2]);unit.mesh.userData.wingOwnerRoot=wing.uuid;unit.mesh.material.forceSinglePass=true;unit.apply({scale:[1,1,1],alpha:.40,color:[color.r,color.g,color.b]});units.push({unit,anchor});}
 };
 return {update(dt,{visible=true}={}){if(disposed)return;wing.getWorldPosition(at);game.camera.getWorldPosition(cam);if(!visible||fx.enabled===false||!wing.parent||hidden()||at.distanceToSquared(cam)>WING_PARTICLE_LIMITS.distance**2){release();return;}allocate();if(!registered)return;cameraFrame(game.camera,frame);for(const {unit}of units)unit.update(Math.min(.05,Math.max(0,Number(dt)||0)));},dispose(){if(disposed)return;disposed=true;release();},get disposed(){return disposed;},get liveParticles(){return units.reduce((n,e)=>n+e.unit.parts.length,0);},get registered(){return registered;}};
}
