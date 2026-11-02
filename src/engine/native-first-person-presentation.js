import {awaitLoadingStage} from './loading-deadline.js';
// Native source rigs; explicit bounded first-person presentation only.
const NATIVE_FP_POSE={
  "0": {
    "headIndex": 5,
    "shoulders": [
      8,
      16
    ]
  },
  "1": {
    "headIndex": 5,
    "shoulders": [
      17,
      25
    ]
  },
  "2": {
    "headIndex": 22,
    "shoulders": [
      16,
      28
    ]
  },
  "3": {
    "headIndex": 5,
    "shoulders": [
      10,
      18
    ]
  },
  "4": {
    "headIndex": 5,
    "shoulders": [
      13,
      21
    ]
  },
  "5": {
    "headIndex": 5,
    "shoulders": [
      7,
      15
    ]
  },
  "6": {
    "headIndex": 5,
    "shoulders": [
      7,
      14
    ]
  },
  "7": {
    "headIndex": 5,
    "shoulders": [
      11,
      16
    ]
  },
  "8": {
    "headIndex": 5,
    "shoulders": [
      7,
      27
    ]
  },
  "9": {
    "headIndex": 5,
    "shoulders": [
      14,
      20
    ]
  },
  "10": {
    "headIndex": 5,
    "shoulders": [
      10,
      17
    ]
  },
  "11": {
    "headIndex": 5,
    "shoulders": [
      7,
      13
    ]
  },
  "12": {
    "headIndex": 5,
    "shoulders": [
      9,
      15
    ]
  },
  "13": {
    "headIndex": 5,
    "shoulders": [
      7,
      13
    ]
  },
  "14": {
    "headIndex": 5,
    "shoulders": [
      14,
      22
    ]
  }
};
import * as THREE from 'three';
import {fpFraming,fpWeaponClamp,fpWeaponAreaScale,FP_FRAMING_IDENTITY,FP_ARM_NEAR} from '../config/engine-chosen-first-person.js';
import {queueWarmDraw,drawWithWorldLights} from './warm-draw.js';

// Equipped roots are tagged by WingVisual; authored wing dust lives in the
// world FX root and carries its emitting wing's UUID. Never infer from names.
export function isOwnedWingObject(player,object){
 const group=player?.group;if(!group)return false;
 let wing=false;for(let node=object;node;node=node.parent){
  if(node===group)return wing;
  wing ||= !!(node.userData?.mountsWing||node.userData?.wingMotion);
 }
 const uuid=object?.userData?.wingOwnerRoot;
 return !!uuid&&isOwnedWingObject(player,group.getObjectByProperty('uuid',uuid));
}
export function armBoneIndices(instance, distalOnly=false){
 const raw=instance?.model?.skel?.bones||[],pattern=distalOnly?/\b[LR]\s+(?:Forearm|Hand)(?:\s|$)/i:/\b[LR]\s+(?:Clavicle|UpperArm|Forearm|Hand)(?:\s|$)/i,ids=new Set(raw.filter(b=>pattern.test(b.name+' '+b.alias)).map(b=>b.index));let grew=true;
 while(grew){grew=false;for(const b of raw)if(ids.has(b.parent)&&!ids.has(b.index)){ids.add(b.index);grew=true;}}return [...ids];
}
/** The upper-body bones the first-person body pass cuts away (head, neck, spine and below them, minus the legs). */
function bodyHeadIndices(source){
 const head=source.model.skel.bones.filter(b=>/\b(?:Head|Neck|Spine\d*)(?:\s|$)/i.test(b.name+' '+b.alias)).map(b=>b.index),raw=source.model.skel.bones;let grew=true;while(grew){grew=false;for(const b of raw)if(head.includes(b.parent)&&!head.includes(b.index)){head.push(b.index);grew=true;}}
 const lower=new Set(raw.filter(b=>/\b[LR]\s+(?:Thigh|Calf|Foot|Toe\d*)(?:\s|$)/i.test(b.name+' '+b.alias)).map(b=>b.index));let added=true;while(added){added=false;for(const b of raw)if(lower.has(b.parent)&&!lower.has(b.index)){lower.add(b.index);added=true;}}for(let i=head.length-1;i>=0;i--)if(lower.has(head[i]))head.splice(i,1);
 return head;
}
export class NativeFirstPersonRig{
 constructor(player){
  this.player=player;this.config=player.model?.instantiate?NATIVE_FP_POSE[player.classIndex]:null;this.scene=new THREE.Scene();this.group=new THREE.Group();this.group.name='native additive first-person rig';this.group.matrixAutoUpdate=false;this.scene.add(this.group);this.records=[];this.signature=[];this.lights=new Map();this.dimsCache=new WeakMap();
  const raw=player.model?.skel?.bones||[];if(this.config&&(!/\bHead(?:\s|$)/i.test(raw[this.config.headIndex]?.name||'')||this.config.shoulders.some(i=>!/\b[LR]\s+UpperArm(?:\s|$)/i.test(raw[i]?.name||'')||player.model.boneIndex(raw[i].name.replace('UpperArm','Hand'))<0)))this.config=null;
  this.bodyScene=new THREE.Scene();this.bodyGroup=new THREE.Group();this.bodyGroup.matrixAutoUpdate=false;this.bodyScene.add(this.bodyGroup);this.bodyRecords=[];this.bodyLights=new Map();
  if(this.config){this.instance=player.model.instantiate();for(const mesh of this.instance.meshes)mesh.removeFromParent();this.group.add(this.instance.root);this.bodyInstance=player.model.instantiate();for(const mesh of this.bodyInstance.meshes)mesh.removeFromParent();this.bodyGroup.add(this.bodyInstance.root);}
 }
 dispose(){this.group.removeFromParent();this.instance?.skeleton.dispose();this.bodyInstance?.skeleton.dispose();this.records.length=0;this.bodyRecords.length=0;this.signature.length=0;this.scene.clear();this.bodyScene.clear();this.lights.clear();this.bodyLights.clear();}
 prepare(game,material){
  const p=this.player,source=p.instance,inst=this.instance;if(!inst||p.dead||p.state==='die'||!game.scene||!game.camera)return false;
  p.group.updateWorldMatrix(true,true);game.camera.updateMatrixWorld(true);this.group.matrix.identity();this.scene.updateMatrixWorld(true);
  // Sample the LIVE native animation, including its authored shear/scale, into
  // independent bones. No second clock/mixer, and no edits to world skeletons.
  for(let i=0;i<inst.bones.length;i++){const a=source.bones[i],b=inst.bones[i];b.position.copy(a.position);b.quaternion.copy(a.quaternion);b.scale.copy(a.scale);if(b.shear&&a.shear)b.shear.copy(a.shear);}
  inst.staticBone.position.copy(source.staticBone.position);inst.staticBone.quaternion.copy(source.staticBone.quaternion);inst.staticBone.scale.copy(source.staticBone.scale);
  inst.root.position.copy(source.root.position);inst.root.quaternion.copy(source.root.quaternion);inst.root.scale.copy(source.root.scale);
  inst.root.updateMatrixWorld(true);
  // Stabilize the two native shoulder pivots below the viewport. This changes
  // camera presentation placement, never source bone lengths or vertex weights.
  // Per-class / per-style framing (engine-chosen-first-person.js FP_FRAMING; identity when untabulated and when riding).
  const framing=localNativeRiding(game)?null:fpFraming(p.classIndex,Number(p.classDef?.style));this.framing=framing;
  const rig=framing?.rig||FP_FRAMING_IDENTITY;
  const scale=Number(p.scale)>0?Number(p.scale):1,mirror=new THREE.Matrix4().makeScale(-scale*rig.scale,scale*rig.scale,scale*rig.scale),center=new THREE.Vector3();
  for(const index of this.config.shoulders)center.add(new THREE.Vector3().setFromMatrixPosition(inst.bones[index].matrixWorld).applyMatrix4(mirror));center.multiplyScalar(1/this.config.shoulders.length);
  const target=new THREE.Vector3(rig.dx,-.28+rig.dy,-.10+rig.dz).multiplyScalar(scale),mount=new THREE.Matrix4().makeTranslation(target.x-center.x,target.y-center.y,target.z-center.z).multiply(mirror);
  // Native animated transforms remain exact; framing applies to the entire rig.
  // No upper-arm aim, IK, calibrated hand target or displacement amplification.
  this.additiveOffsets={};
  // Fixed bounded presentation bias only; preserve every native animation delta.
  if(!localNativeRiding(game))for(const index of this.config.shoulders){const parent=new THREE.Quaternion(),position=new THREE.Vector3(),stretch=new THREE.Vector3();inst.bones[index].parent.matrixWorld.decompose(position,parent,stretch);const bias=new THREE.Quaternion().setFromAxisAngle(new THREE.Vector3(1,0,0),40*Math.PI/180),local=parent.clone().invert().multiply(bias).multiply(parent);inst.bones[index].quaternion.premultiply(local);this.additiveOffsets[index]=local.toArray();}
  // Tab weapon swap (first-person-swap.js, ENGINE-CHOSEN): a camera-space offset that lowers the whole arm rig + weapons.
  const swap=game.fpSwap?.matrix();this.group.matrix.copy(game.camera.matrixWorld);if(swap)this.group.matrix.multiply(swap);this.frameInverse=this.group.matrix.clone().invert();this.frameQuat=new THREE.Quaternion().setFromRotationMatrix(this.group.matrix);this.group.matrix.multiply(mount);this.scene.updateMatrixWorld(true);inst.skeleton.update();
  // TransUp whole-body armor carries oversized shoulder plates; keep its native
  // forearms/hands in the camera pass while the full arm mask still hides world arms.
  const ids=armBoneIndices(source,!!p.transformLook?.mesh),sources=[];
  for(const mesh of source.meshes)if(!isOwnedWingObject(p,mesh))sources.push({source:mesh,ids,gear:false});
  const known=new Set(source.meshes);p.group.traverse(mesh=>{if(mesh.isSkinnedMesh&&mesh.skeleton===source.skeleton&&!known.has(mesh)&&!isOwnedWingObject(p,mesh))sources.push({source:mesh,ids,gear:false,overlay:true});});
  for(const w of p._weaponObjs)w.obj.traverse(mesh=>{if(mesh.isMesh)sources.push({source:mesh,ids:[],gear:true,weapon:w});});
  if(sources.length!==this.signature.length||sources.some((r,i)=>r.source!==this.signature[i])){
   for(const r of this.records)r.copy.removeFromParent();for(const r of this.bodyRecords)r.copy.removeFromParent();this.signature=sources.map(r=>r.source);
   this.records=sources.map(record=>{const copy=record.source.clone(false);copy.castShadow=false;copy.receiveShadow=false;copy.frustumCulled=false;copy.matrixAutoUpdate=false;copy.userData.c22NativeRole=record.gear?'gear':record.overlay?'buff-arms':'arms';
    if(record.gear){if(copy.isSkinnedMesh)copy.updateMatrixWorld=function(force){THREE.Mesh.prototype.updateMatrixWorld.call(this,force);};this.group.add(copy);}
    else{copy.skeleton=inst.skeleton;inst.root.add(copy);}return {...record,copy};});
   this.bodyRecords=sources.filter(r=>!r.gear).map(record=>{const copy=record.source.clone(false);copy.skeleton=this.bodyInstance.skeleton;copy.castShadow=false;copy.receiveShadow=true;copy.frustumCulled=false;copy.matrixAutoUpdate=false;copy.userData.c22NativeRole=record.overlay?'buff-body':'body';this.bodyInstance.root.add(copy);return {...record,copy};});
  }
  const groupInverse=this.group.matrixWorld.clone().invert();
  for(const record of this.records){const {source:mesh,copy,gear,ids}=record;copy.visible=p.group.visible&&mesh.visible&&(!gear||!localNativeRiding(game));for(let node=mesh.parent;node&&node!==p.group;node=node.parent)copy.visible&&=node.visible;
   copy.bindMatrix?.copy(mesh.bindMatrix);if(gear){copy.bindMatrixInverse?.copy(mesh.bindMatrixInverse);copy.matrix.copy(groupInverse).multiply(this.weaponFrame(record.weapon)).multiply(mesh.matrixWorld);}else copy.matrix.copy(mesh.matrix);
   copy.renderOrder=mesh.renderOrder;copy.material=Array.isArray(mesh.material)?mesh.material.map(m=>material(m,ids,gear?'gear':'arms')):material(mesh.material,ids,gear?'gear':'arms');
  }
  this.prepareBody(game,material);
  this.scene.fog=game.scene.fog;this.scene.environment=game.scene.environment;
  const activeLights=new Set();for(const light of game.scene.children){if(!light.isLight)continue;activeLights.add(light);let copy=this.lights.get(light);if(!copy){copy=light.clone();copy.castShadow=false;copy.matrixAutoUpdate=false;this.scene.add(copy);this.lights.set(light,copy);if(copy.target)this.scene.add(copy.target);}copy.color.copy(light.color);copy.groundColor?.copy(light.groundColor);copy.intensity=light.intensity;for(const key of['distance','decay','angle','penumbra'])if(light[key]!==undefined)copy[key]=light[key];copy.matrix.copy(light.matrixWorld);if(copy.target&&light.target){copy.target.position.setFromMatrixPosition(light.target.matrixWorld);copy.target.updateMatrixWorld(true);}let bodyLight=this.bodyLights.get(light);if(!bodyLight){bodyLight=copy.clone();bodyLight.matrixAutoUpdate=false;this.bodyScene.add(bodyLight);this.bodyLights.set(light,bodyLight);if(bodyLight.target)this.bodyScene.add(bodyLight.target);}bodyLight.color.copy(copy.color);bodyLight.groundColor?.copy(copy.groundColor);bodyLight.intensity=copy.intensity;bodyLight.matrix.copy(copy.matrix);if(bodyLight.target&&copy.target){bodyLight.target.position.copy(copy.target.position);bodyLight.target.updateMatrixWorld(true);}}
  for(const[light,copy]of this.lights)if(!activeLights.has(light)){copy.removeFromParent();copy.target?.removeFromParent();this.lights.delete(light);const bodyLight=this.bodyLights.get(light);bodyLight?.removeFromParent();bodyLight?.target?.removeFromParent();this.bodyLights.delete(light);}
  this.scene.updateMatrixWorld(true);inst.skeleton.update();return true;
 }
 prepareBody(game,material){
  const source=this.player.instance,inst=this.bodyInstance,scale=Number(this.player.scale)>0?Number(this.player.scale):1;
  for(let i=0;i<inst.bones.length;i++){const a=source.bones[i],b=inst.bones[i];b.position.copy(a.position);b.quaternion.copy(a.quaternion);b.scale.copy(a.scale);if(b.shear&&a.shear)b.shear.copy(a.shear);}
  inst.staticBone.position.copy(source.staticBone.position);inst.staticBone.quaternion.copy(source.staticBone.quaternion);inst.staticBone.scale.copy(source.staticBone.scale);inst.root.position.copy(source.root.position);inst.root.quaternion.copy(source.root.quaternion);inst.root.scale.copy(source.root.scale);
  // Match the physical actor, including native yaw, scale and world mirror.
  // Camera orientation affects visibility only; it cannot translate the body.
  this.bodyGroup.matrix.copy(this.player.group.matrixWorld);
  if(game.cam?.mode==='first-person'&&!localNativeRiding(game)&&!game.mounts?.isMounted?.()&&Number.isFinite(game.cam.yaw)){
   const forward=new THREE.Vector3(0,0,-1).transformDirection(this.bodyGroup.matrix);
   const delta=Math.atan2(-Math.sin(game.cam.yaw),-Math.cos(game.cam.yaw))-Math.atan2(forward.x,forward.z);
   const position=new THREE.Vector3().setFromMatrixPosition(this.bodyGroup.matrix);
   const turn=new THREE.Matrix4().makeRotationY(delta);
   turn.setPosition(position.clone().sub(position.clone().applyMatrix4(turn)));
   this.bodyGroup.matrix.premultiply(turn);
  }
  const head=bodyHeadIndices(source);
  const pitch=Number(game.cam?.pitch)||0;this.bodyVisible=pitch>.65;this.bodyFade=THREE.MathUtils.smoothstep(pitch,.65,.95);this.bodyGroup.visible=this.bodyVisible;
  for(const r of this.bodyRecords){r.copy.visible=r.source.visible&&this.player.group.visible;for(let node=r.source.parent;node&&node!==this.player.group;node=node.parent)r.copy.visible&&=node.visible;r.copy.matrix.copy(r.source.matrix);r.copy.bindMatrix.copy(r.source.bindMatrix);r.copy.renderOrder=r.source.renderOrder;r.copy.material=Array.isArray(r.source.material)?r.source.material.map(m=>material(m,head,'body')):material(r.source.material,head,'body');}
  this.bodyScene.fog=game.scene.fog;this.bodyScene.environment=game.scene.environment;this.bodyScene.updateMatrixWorld(true);inst.skeleton.update();
 }
 weaponFrame(weapon){
  const p=this.player,source=p.instance,hand=this.weaponHandIndex(weapon);
  if(hand<0)return new THREE.Matrix4();const base=this.instance.bones[hand].matrixWorld.clone().multiply(source.bones[hand].matrixWorld.clone().invert());
  // Per-weapon framing (main hand / off-hand): the keep-in-view clamp of the grip (the rig hand bone) + the tabulated static offset, then the
  // tabulated scale about the grip. All in the camera x swap frame, so the Tab weapon swap still carries the weapon with the arms. Weapon
  // meshes and their effect anchors both go through here, so they stay together.
  const f=this.framing?.[weapon.hand];if(!f)return base;
  const k=Number(this.player.scale)>0?Number(this.player.scale):1,grip=new THREE.Vector3().setFromMatrixPosition(this.instance.bones[hand].matrixWorld),local=grip.clone().applyMatrix4(this.frameInverse||new THREE.Matrix4()),
   side=this.handSide(hand),clamp=fpWeaponClamp([local.x,local.y,local.z],k,f,side),move=new THREE.Vector3(clamp[0]+f.dx*k,clamp[1]+f.dy*k,clamp[2]+f.dz*k).applyQuaternion(this.frameQuat||new THREE.Quaternion());
  const s=f.scale*fpWeaponAreaScale(this.weaponDims(weapon),f.area);
  if(s===1&&move.lengthSq()<1e-12)return base;
  return new THREE.Matrix4().makeTranslation(grip.x+move.x,grip.y+move.y,grip.z+move.z).multiply(new THREE.Matrix4().makeScale(s,s,s)).multiply(new THREE.Matrix4().makeTranslation(-grip.x,-grip.y,-grip.z)).multiply(base);
 }
 /** 'L' | 'R': which hand bone (index into the native skeleton) holds a weapon. */
 handSide(index){const b=this.player.instance.model.skel.bones[index];return /\bL\s+Hand(?:\s|$)/i.test((b?.name||'')+' '+(b?.alias||''))?'L':'R';}
 /** Bounding-box sides of a weapon in metres (sorted, largest first): its meshes' geometry boxes in the weapon's own frame x its world scale (cached). */
 weaponDims(weapon){
  let d=this.dimsCache.get(weapon.obj);if(d)return d;
  const obj=weapon.obj,box=new THREE.Box3(),tmp=new THREE.Box3();obj.updateWorldMatrix(true,true);const inv=obj.matrixWorld.clone().invert();
  obj.traverse(m=>{if(!m.isMesh||!m.geometry)return;if(!m.geometry.boundingBox)m.geometry.computeBoundingBox();tmp.copy(m.geometry.boundingBox).applyMatrix4(inv.clone().multiply(m.matrixWorld));box.union(tmp);});
  const size=box.getSize(new THREE.Vector3()),k=new THREE.Vector3().setFromMatrixScale(obj.matrixWorld);
  d=box.isEmpty()?[0,0,0]:[size.x*k.x,size.y*k.y,size.z*k.z].sort((a,b)=>b-a);this.dimsCache.set(weapon.obj,d);return d;
 }
 weaponHandIndex(weapon){
  const source=this.player.instance,raw=source.model.skel.bones,handIds=raw.filter(b=>/\b[LR]\s+Hand(?:\s|$)/i.test(b.name+' '+b.alias)).map(b=>b.index);let helper=source.bones.indexOf(weapon.obj.parent),ancestor=helper;
  while(ancestor>=0&&!handIds.includes(ancestor))ancestor=raw[ancestor]?.parent??-1;
  if(ancestor>=0)return ancestor;if(helper<0||!handIds.length)return -1;
  const at=new THREE.Vector3().fromArray(Array.from(raw[helper].bindMatrix).slice(12,15));return handIds.reduce((best,i)=>{const next=new THREE.Vector3().fromArray(Array.from(raw[i].bindMatrix).slice(12,15)),previous=new THREE.Vector3().fromArray(Array.from(raw[best].bindMatrix).slice(12,15));return next.distanceToSquared(at)<previous.distanceToSquared(at)?i:best;},handIds[0]);
 }
 rebaseEffects(game){
  const p=this.player,source=p.instance,arms=new Set(armBoneIndices(source)),helpers=new Map(),restore=[],spanRestore=[];
  for(const weapon of p._weaponObjs){const index=source.bones.indexOf(weapon.obj.parent);if(index>=0)helpers.set(index,weapon);}
  const cleanup=()=>{for(const fn of spanRestore.reverse())fn();for(const r of restore){r.parent.add(r.anchor);const index=r.parent.children.indexOf(r.anchor);r.parent.children.splice(index,1);r.parent.children.splice(r.order,0,r.anchor);r.anchor.matrix.copy(r.matrix);r.anchor.matrixAutoUpdate=r.auto;r.anchor.updateWorldMatrix(false,true);}};
  const within=(node,root)=>{for(;node;node=node.parent)if(node===root)return true;return false;};
  try { for(const fx of new Set([game.effects,game.items?.authoredEffects?.fx]))for(const play of fx?.active||[]){
   const owner=play.owner,weapon=p._weaponObjs.find(w=>within(owner?.group,w.obj));
   if(weapon&&localNativeRiding(game))continue;
   if(!play.ownerIsActor||isOwnedWingObject(p,owner?.group)||(owner!==p&&!weapon&&owner?.group!==p.group))continue;
   for(const control of play.controls||[]){
    if(control.frozen||!['mesh','sprite'].includes(control.unitDef?.type)||!control.anchor?.parent||isOwnedWingObject(p,control.anchor))continue;
    const index=source.model.boneIndex(control.def.bone??play.bone),nativeBody=index>=0&&!arms.has(index)&&!helpers.has(index)&&/\b(?:Head|Spine\d*|Pelvis|[LR]\s+(?:Thigh|Calf|Foot|Toe\d*))(?:\s|$)/i.test(source.model.skel.bones[index].name+' '+source.model.skel.bones[index].alias);
    if(!weapon&&!arms.has(index)&&!helpers.has(index)&&!nativeBody)continue;
    const frame=weapon?this.weaponFrame(weapon):helpers.has(index)?this.weaponFrame(helpers.get(index)):(nativeBody?this.bodyInstance:this.instance).bones[index].matrixWorld.clone().multiply(source.bones[index].matrixWorld.clone().invert());
    const anchor=control.anchor;anchor.updateWorldMatrix(true,true);const parent=anchor.parent,order=parent.children.indexOf(anchor),desired=frame.clone().multiply(anchor.matrixWorld);
    restore.push({anchor,parent,order,matrix:anchor.matrix.clone(),auto:anchor.matrixAutoUpdate});anchor.matrixAutoUpdate=false;(nativeBody&&!weapon?this.bodyScene:this.scene).add(anchor);anchor.matrix.copy(desired);anchor.updateWorldMatrix(false,true);
   }
  }
  return cleanup; } catch(error) { cleanup(); throw error; }
 }}

// Revision 6: native world body plus an independent native arm presentation.
// Color-only head suppression leaves native torso/arms/gear and shadow geometry.


const passes=new WeakMap();
// Azure-only experimental stable eye placement; unsupported rigs retain baseline.
export function nativeEyeClearance(){return 0;}
const isHead=name=>/(?:^|\s)head(?:\s|$)/i.test(String(name||''));
export function headBoneIndices(instance){
 const raw=instance?.model?.skel?.bones||[],ids=new Set(raw.filter(b=>isHead(b.name)||isHead(b.alias)).map(b=>b.index));
 let grew=true;while(grew){grew=false;for(const b of raw)if(ids.has(b.parent)&&!ids.has(b.index)){ids.add(b.index);grew=true;}}
 return [...ids].sort((a,b)=>a-b);
}
// Stable bind-space eye; source attacks do not bob or rotate the gameplay camera.
export function nativeEyeHeight(player){
 const baseline=(Number(player?.instance?.root?.position.y)||0)+(Number(player?.height)||1.9)*(Number(player?.scale)||1)*.88;
 if(!NATIVE_FP_POSE[player?.classIndex]||!player?.model?.instantiate||!player.instance||player.disposed||player.dead||player.state==='die')return baseline;
 const riding=localNativeRiding(player.game);if(riding){
  // Do not drive the camera from the animated rider head. Mount idle/run clips
  // intentionally bob the head, which used to make first person pulse vertically
  // and briefly clip through the vehicle at speed. Cache one authored seat height
  // per mount while preserving the native rider pose for the visible body.
  const rideKey=String(riding.item ?? riding.mount?.item ?? 'default');
  const head=player.instance.getBone('Bip01 Head');
  if(head){
   if(player._nativeRideEyeKey===rideKey&&Number.isFinite(player._nativeRideEyeY))return player._nativeRideEyeY;
   player.group.updateWorldMatrix(true,true);
   const y=new THREE.Vector3().setFromMatrixPosition(head.matrixWorld).y-(Number(player.y)||0);
   if(Number.isFinite(y)){player._nativeRideEyeKey=rideKey;player._nativeRideEyeY=y;return y;}
  }
 }
 const head=player?.instance?.model?.skel?.bones?.find(b=>isHead(b.name)||isHead(b.alias)),y=Number(head?.bindMatrix?.[13]);
 const scale=Number(player?.scale)>0?Number(player.scale):1,rootY=Number(player?.instance?.root?.position.y)||0;
 return rootY+(Number.isFinite(y)&&y>0?y:(Number(player?.height)||1.9)*.88)*scale;
}
function patchMaterial(original,indices,rigidHead,radius,arms=[],mode='world',waist={value:1.2}){
 const mat=original.clone(),compile=original.onBeforeCompile,key=original.customProgramCacheKey;
 const match=indices.map(i=>`(1.0-step(0.5,abs(c22Index-${i}.0)))`).join('+')||'0.0';
 const armMatch=arms.map(i=>`(1.0-step(0.5,abs(c22Index-${i}.0)))`).join('+')||'0.0',discard=mode==='world-gear'?'discard;':mode==='arms'?'if(c22Arm<=0.5||length(c22View)<c22NearRadius)discard;':mode==='gear'?'if(length(c22View)<c22NearRadius)discard;':mode==='body'?'if(c22Head>0.5||c22Arm>0.5||length(c22View)<c22NearRadius)discard; vec3 capNormal=normalize(cross(dFdx(c22BodyPos),dFdy(c22BodyPos))); if(c22BodyPos.y>c22Waist-0.015 && abs(capNormal.y)>0.9)discard;':'if(c22Head>0.5||c22Arm>0.5||length(c22View)<c22NearRadius)discard;';
 mat.onBeforeCompile=function(shader,renderer){
  compile.call(this,shader,renderer);
  if(mode==='world-wing'){shader.fragmentShader=shader.fragmentShader.replace(/void\s+main\s*\(\s*\)\s*\{/,'$&\n discard;');return;}
  if(original.isShaderMaterial){if(rigidHead||mode==='world-gear')shader.fragmentShader=shader.fragmentShader.replace(/void\s+main\s*\(\s*\)\s*\{/,'$&\n discard;');return;}
  shader.uniforms.c22NearRadius=radius;shader.uniforms.c22Waist=waist;
  shader.vertexShader=shader.vertexShader
   .replace('#include <common>',`#include <common>\nvarying float c22Head;\nvarying float c22Arm;\nvarying vec3 c22View;\nvarying vec3 c22BodyPos;\nfloat c22HeadIndex(float c22Index){return ${match};}\nfloat c22ArmIndex(float c22Index){return ${armMatch};}`)
   .replace('#include <begin_vertex>',`#include <begin_vertex>\nc22Head=${rigidHead?'1.0':'0.0'};\nc22Arm=0.0;\n#ifdef USE_SKINNING\nc22Head+=dot(skinWeight,vec4(c22HeadIndex(skinIndex.x),c22HeadIndex(skinIndex.y),c22HeadIndex(skinIndex.z),c22HeadIndex(skinIndex.w)));\nc22Arm=dot(skinWeight,vec4(c22ArmIndex(skinIndex.x),c22ArmIndex(skinIndex.y),c22ArmIndex(skinIndex.z),c22ArmIndex(skinIndex.w)));\n#endif`)
   .replace('#include <skinning_vertex>','#include <skinning_vertex>\nc22BodyPos=transformed;')
   .replace('#include <project_vertex>','#include <project_vertex>\nc22View = mvPosition.xyz;');
  shader.fragmentShader=shader.fragmentShader
   .replace('#include <common>','#include <common>\nvarying float c22Head;\nvarying float c22Arm;\nvarying vec3 c22View;\nvarying vec3 c22BodyPos;\nuniform float c22NearRadius;\nuniform float c22Waist;')
   .replace('#include <clipping_planes_fragment>','#include <clipping_planes_fragment>\n'+discard);
 };
 mat.customProgramCacheKey=()=>`${key.call(original)}|c22-native-body-v7:${indices.join(',')}:${rigidHead?1:0}:${arms.join(',')}:${mode}`;return mat;
}
class BodyPass{
 constructor(instance,player){this.instance=instance;this.rig=new NativeFirstPersonRig(player);this.materials=new Map();this.radius={value:.08};this.viewRadius={value:.08};this.armRadius={value:FP_ARM_NEAR};this.depth=0;this.waist={value:Number(instance.model.skel.bones.find(b=>/\bPelvis(?:\s|$)/i.test(b.name))?.bindMatrix?.[13])+0.03};}
 dispose(){this.rig.dispose();for(const[src,entry]of this.materials){src.removeEventListener('dispose',entry.listener);for(const mat of entry.byKey.values())mat.dispose();}this.materials.clear();}
 material(src,ids,head,arms=[],mode='world'){
  let entry=this.materials.get(src);
  if(!entry){entry={byKey:new Map(),version:src.version};entry.listener=()=>{for(const mat of entry.byKey.values())mat.dispose();src.removeEventListener('dispose',entry.listener);this.materials.delete(src);};this.materials.set(src,entry);src.addEventListener('dispose',entry.listener);}
  if(entry.version!==src.version){for(const mat of entry.byKey.values())mat.dispose();entry.byKey.clear();entry.version=src.version;}
  const key=`${ids.join(',')}:${head?1:0}:${arms.join(',')}:${mode}`;let mat=entry.byKey.get(key);
  if(!mat){mat=patchMaterial(src,ids,head,mode==='arms'?this.armRadius:['gear','body'].includes(mode)?this.viewRadius:this.radius,arms,mode,this.waist);entry.byKey.set(key,mat);}mat.copy(src);if(mode==='body'){mat.opacity*=this.rig.bodyFade;mat.transparent=src.transparent||this.rig.bodyFade<.999;mat.depthWrite=src.depthWrite&&this.rig.bodyFade>=.999;}return mat;
 }
 render(game,render,{proofOnly=false}={}){
  if(this.depth)return render();this.depth++;
  const restore=[];let restoreEffects=()=>{};
  try{
   this.patch(game,restore);
   if(this.active)restoreEffects=this.rig.rebaseEffects(game);
   const result=render();
   if(this.active&&!proofOnly&&game.renderer){const renderer=game.renderer,clear=renderer.autoClear;try{renderer.autoClear=false;if(this.rig.bodyVisible)renderer.render(this.rig.bodyScene,game.camera);renderer.clearDepth();renderer.render(this.rig.scene,game.camera);}finally{renderer.autoClear=clear;}}
   return result;
  }finally{restoreEffects();for(const[mesh,original]of restore)mesh.material=original;this.depth--;}
 }
 // Two large spikes on the first switch to first person. Measured with the test client (frame timing + profiler):
 // one 865 ms frame, 760 ms of it in getProgramInfoLog = the driver building the new arm / gear / body shader variants (D3D11
 // HLSL) on their first draw. prewarm builds the same rig copies and patched materials in third person and hands their scenes to
 // renderer.compileAsync (parallel compile, KHR_parallel_shader_compile), so the programs are ready before the first switch.
 // The world copy of the avatar is hidden in that pass (camera.js withLocalAvatarHidden), so only the two first-person scenes
 // are compiled. Materials are restored at once. With `draw` (the map load, under the loading screen) also one warm draw of
 // both scenes in the next frame, colour / depth writes locked off (warm-draw.js): ANGLE builds the D3D11 shaders on the
 // first DRAW, not at compile (276 ms after the compile; and 355 ms when a gameplay re-warm drew right at a Trans Up,
 // test-client Trans Up run), so a drawn warm-up only happens where nobody is playing.
 async prewarm(game,{draw=false,current=()=>true,timeoutMs=6000}={}){
  const renderer=game.renderer;if(this.depth||this.warming||typeof renderer?.compileAsync!=='function')return false;
  const restore=[],tasks=[];this.depth++;this.warming=true;
  try{
   try{
    this.patch(game,restore);
    if(this.active)for(const scene of[this.rig.scene,this.rig.bodyScene])tasks.push(renderer.compileAsync(scene,game.camera));
   }finally{for(const[mesh,original]of restore)mesh.material=original;this.active=false;this.depth--;}
   await awaitLoadingStage(()=>Promise.all(tasks),{current,timeoutMs,stage:'First-person graphics'});
   if(tasks.length&&draw&&current())queueWarmDraw(game,()=>current()&&this.warmDraw(game));return tasks.length>0;
  }catch(error){void Promise.allSettled(tasks);throw error;}finally{this.warming=false;}
 }
 warmDraw(game){
  const renderer=game.renderer;if(this.depth||game.cam?.mode==='first-person'||!renderer||game.player?.instance!==this.instance)return false;
  const restore=[];this.depth++;
  try{
   this.patch(game,restore);if(!this.active)return false;
   const body=this.rig.bodyGroup.visible;this.rig.bodyGroup.visible=true;
   try{renderer.render(this.rig.bodyScene,game.camera);renderer.render(this.rig.scene,game.camera);}finally{this.rig.bodyGroup.visible=body;}
   return true;
  }finally{for(const[mesh,original]of restore)mesh.material=original;this.active=false;this.depth--;}
 }
 patch(game,restore){
  this.armRadius.value=Number(globalThis.__dekaronFpArmNear)||FP_ARM_NEAR;   // measurement override (for test-client measurements)
  const inst=this.instance,head=headBoneIndices(inst),bones=new Set(head.map(i=>inst.bones?.[i]).filter(Boolean));
  this.radius.value=Math.max(.055,Math.min(.12,.08*(Number(game.player?.scale)||1)));
  {
   this.viewRadius.value=this.radius.value;
   this.active=this.rig.prepare(game,(src,ids,mode)=>mode==='body'?this.material(src,ids,false,armBoneIndices(inst),mode):this.material(src,[],false,ids,mode));
   const arms=this.active?armBoneIndices(inst):[],gear=new Set(this.active&&!localNativeRiding(game)?this.rig.records.filter(r=>r.gear).map(r=>r.source):[]);
   this.hiddenWingDraws=0;const visited=new Set(),patchObject=mesh=>{
    if(visited.has(mesh)||!(mesh.isMesh||mesh.isSprite||mesh.isPoints)||!mesh.material)return;visited.add(mesh);
    const wing=isOwnedWingObject(game.player,mesh);if(!mesh.isMesh&&!wing)return;if(wing)this.hiddenWingDraws++;
    let rigidHead=false;for(let node=mesh.parent;node&&node!==game.player.group;node=node.parent)if(bones.has(node))rigidHead=true;
    const ids=mesh.isSkinnedMesh&&mesh.skeleton===inst.skeleton?head:[],original=mesh.material;restore.push([mesh,original]);
    const armIds=mesh.isSkinnedMesh&&mesh.skeleton===inst.skeleton?arms:[],nativeBody=mesh.isSkinnedMesh&&mesh.skeleton===inst.skeleton,mode=wing?'world-wing':this.active&&(nativeBody||gear.has(mesh)||rigidHead)?'world-gear':'world';
    mesh.material=Array.isArray(original)?original.map(m=>this.material(m,ids,rigidHead,armIds,mode)):this.material(original,ids,rigidHead,armIds,mode);
   };game.player.group.traverse(patchObject);
   // Only the emitting local wing's world dust is suppressed. Keep particle
   // simulation/state and all source shadow flags/depth materials unchanged.
   game.effects?.root?.traverse(mesh=>{if(isOwnedWingObject(game.player,mesh))patchObject(mesh);});
  }
 }
}
function bodyPassFor(game){
 const player=game.player;let pass=passes.get(game);if(!pass||pass.instance!==player.instance){pass?.dispose();pass=new BodyPass(player.instance,player);passes.set(game,pass);}return pass;
}
export function withLocalAvatarBody(game,render,options){
 const player=game.player;if(game.cam?.mode!=='first-person'||game.gm?.freecam?.on||!player?.group||!player.instance||player.disposed)return render();
 return bodyPassFor(game).render(game,render,options);
}
/** Compile the first-person shader variants of the current look in the background (see BodyPass.prewarm; `draw` only under the loading screen). Third person only. */
export function prewarmFirstPersonBody(game,options){
 const player=game.player;if(game.cam?.mode==='first-person'||game.gm?.freecam?.on||!player?.group||!player.instance||player.disposed||!player.model?.instantiate||!game.renderer||!game.camera||!game.scene)return Promise.resolve(false);
 return bodyPassFor(game).prewarm(game,options).then(ok=>{if(ok&&(!options?.current||options.current()))warmState(game).signature=lookSignature(player);return ok;});
}
// The look changes (gear, refine shells settling after the load, costume, a new character): re-warm in idle time. A cheap
// signature of the avatar's meshes and their materials, checked at most once a second while in third person (camera.js
// withLocalAvatarHidden calls this every frame). Drawn too (first switch 117-121 ms without it, 42-63 ms with it, test-client
// frame timing), except during a Trans Up: a transient body, and that draw cost 355 ms right at the transform (transspike.mjs).
// Kept programs make a re-warm of an already built look cheap.
export function transientLook(player){return !!(player?.transformLook||player?.transUpStage>0);}
const warmStates=new WeakMap();
const warmState=game=>{let s=warmStates.get(game);if(!s){s={at:0,busy:false,signature:null};warmStates.set(game,s);}return s;};
function lookSignature(player){const parts=[player.instance?.root?.uuid];player.group.traverse(o=>{if(o.isMesh&&o.material)parts.push(o.uuid,...(Array.isArray(o.material)?o.material:[o.material]).map(m=>m.uuid));});return parts.join(',');}
export function firstPersonLookSignature(player){return player?.group?lookSignature(player):null;}
export function scheduleFirstPersonPrewarm(game){
 const player=game.player,state=warmState(game),now=performance.now();
 if(state.busy||now-state.at<1000||game._loadingMap||!player?.group||!player.instance||player.disposed||!player.model?.instantiate)return;
 state.at=now;if(lookSignature(player)===state.signature)return;state.busy=true;
 const run=()=>prewarmFirstPersonBody(game,{draw:!transientLook(game.player)}).catch(error=>console.warn('[first-person] shader pre-build failed',error)).finally(()=>{state.busy=false;});
 if(typeof globalThis.requestIdleCallback==='function')globalThis.requestIdleCallback(()=>void run(),{timeout:2000});else setTimeout(()=>void run(),50);
}
// Riding in first person draws the mount and the weapons in the world pass with the 'world' variants of patch() (the weapons
// leave the arm rig while riding; exposeLocalNativeMount lifts them out of the hidden avatar), variants nothing else builds
// (seen in a test-client mount-summon run: grani1.dds / att_swd_02.dds |c22-native-body-v7::0::world appeared on the first summon).
// Compile them while still on foot; with `draw` (map load only, see BodyPass.prewarm) also draw them once, lit by the world
// lights, in the next frame (warm-draw.js).
const ridingVariant=(pass,mesh,material)=>pass.material(material,[],false,[],'world');
export async function prewarmFirstPersonRiding(game,mountRoot,{draw=false}={}){
 const player=game.player;if(!mountRoot||!player?.group||!player.instance||player.disposed||!player.model?.instantiate||typeof game.renderer?.compileAsync!=='function'||!game.camera||!game.scene)return false;
 const pass=bodyPassFor(game),roots=[mountRoot,...(player._weaponObjs||[]).map(w=>w.obj)].filter(Boolean),restore=[],tasks=[];
 try{
  for(const root of roots){root.traverse(mesh=>{if(!mesh.isMesh||!mesh.material)return;restore.push([mesh,mesh.material]);mesh.material=Array.isArray(mesh.material)?mesh.material.map(m=>ridingVariant(pass,mesh,m)):ridingVariant(pass,mesh,mesh.material);});tasks.push(game.renderer.compileAsync(root,game.camera,game.scene));}
 }finally{for(const[mesh,material]of restore)mesh.material=material;}
 await Promise.all(tasks);
 if(draw)queueWarmDraw(game,()=>{if(game.player!==player||player.disposed)return;drawWithWorldLights(game,[mountRoot]);drawWithWorldLights(game,roots,(mesh,material)=>ridingVariant(pass,mesh,material));});
 return true;
}
// A learned Trans Up body seen from first person: the transform keeps only the native forearms / hands in the arm pass
// (armBoneIndices distal), variants nothing builds before the first transform (test-client Trans Up run in first person: a 443 ms frame,
// the swd_awake arm programs). Its meshes are bound to the first-person rig skeletons for the compile (and, with `draw` - the
// map load - one locked draw of both first-person scenes), then removed again. Needs the rig of the current body (prewarm ran).
export async function prewarmFirstPersonLook(game,model,{draw=false}={}){
 const player=game.player;if(!model?.instantiate||!player?.group||!player.instance||player.disposed||!player.model?.instantiate||typeof game.renderer?.compileAsync!=='function'||!game.camera||!game.scene)return false;
 const pass=bodyPassFor(game),rig=pass.rig;if(!rig.instance||!rig.bodyInstance||!rig.lights.size)return false;
 const source=player.instance,distal=armBoneIndices(source,true),arms=armBoneIndices(source),head=bodyHeadIndices(source),look=model.instantiate();
 const variant=(mesh,fn)=>Array.isArray(mesh.material)?mesh.material.map(fn):fn(mesh.material);
 const bind=(mesh,instance,material)=>{const copy=mesh.clone(false);copy.skeleton=instance.skeleton;copy.bindMatrix.copy(mesh.bindMatrix);copy.bindMatrixInverse.copy(mesh.bindMatrixInverse);copy.castShadow=false;copy.frustumCulled=false;copy.matrixAutoUpdate=false;copy.material=material;return copy;};
 const copies=look.meshes.filter(m=>m.isSkinnedMesh).flatMap(mesh=>[[rig.instance.root,bind(mesh,rig.instance,variant(mesh,m=>pass.material(m,[],false,distal,'arms')))],[rig.bodyInstance.root,bind(mesh,rig.bodyInstance,variant(mesh,m=>pass.material(m,head,false,arms,'body')))]]);
 if(!copies.length){look.dispose();return false;}
 const attach=()=>{for(const[parent,copy]of copies)parent.add(copy);return()=>{for(const[,copy]of copies)copy.removeFromParent();};};
 let detach=attach(),tasks;
 try{tasks=[game.renderer.compileAsync(rig.scene,game.camera),game.renderer.compileAsync(rig.bodyScene,game.camera)];}finally{detach();}
 try{await Promise.all(tasks);}catch(error){look.dispose();throw error;}
 if(!draw){look.dispose();return true;}
 queueWarmDraw(game,()=>{
  if(game.player!==player||player.disposed||pass.depth||passes.get(game)!==pass){look.dispose();return;}
  const body=rig.bodyGroup.visible;detach=attach();rig.bodyGroup.visible=true;
  try{game.renderer.render(rig.bodyScene,game.camera);game.renderer.render(rig.scene,game.camera);}finally{rig.bodyGroup.visible=body;detach();look.dispose();}
 });
 return true;
}
export function suspendFirstPersonBody(game){const pass=passes.get(game);if(!pass)return;if(game.player?.disposed||pass.instance!==game.player?.instance){disposeFirstPersonBody(game);return;}pass.active=false;}
export function disposeFirstPersonBody(game){passes.get(game)?.dispose();passes.delete(game);}
export function firstPersonBodyDiagnostics(game){
 const pass=passes.get(game),p=game.player;return pass?{revision:11,presentation:'all15 native upright body with world depth + independent live native arms; zero eye query/shift',active:pass.active,nativeViewMeshes:pass.active?pass.rig.records.length:0,nativeBuffArmMeshes:pass.rig.records.filter(r=>r.overlay).length,nativeViewBodyMeshes:pass.rig.bodyRecords.length,bodyFade:pass.rig.bodyFade,bodyForward:pass.rig.config?.bodyForward,additiveOffsets:pass.rig.additiveOffsets,headIndices:headBoneIndices(p.instance),nearRadius:pass.radius.value,nativeBodyMeshes:p.instance.meshes?.length||0,nativeWeaponObjects:p._weaponObjs?.length||0,liveSkeletons:pass.rig.records.filter(r=>!r.gear).every(r=>r.copy.skeleton===pass.rig.instance.skeleton),noViewShadow:pass.rig.records.every(r=>!r.copy.castShadow),worldGroupVisible:p.group.visible}:null;
}
/** True when the live first-person arm rig is on screen on foot, so the Tab swap can be shown on it (first-person-swap.js). */
export function firstPersonSwapEligible(game){const pass=passes.get(game);return !!pass?.active&&game.cam?.mode==='first-person'&&!game.gm?.freecam?.on&&!localNativeRiding(game)&&!game.mounts?.isMounted?.()&&!game.player?.dead;}
export function nativeArmPresentation(game){const pass=passes.get(game);return pass?.active?{scene:pass.rig.scene,group:pass.rig.group,records:pass.rig.records,instance:pass.rig.instance,bodyInstance:pass.rig.bodyInstance,bodyScene:pass.rig.bodyScene,bodyRecords:pass.rig.bodyRecords,bodyFade:pass.rig.bodyFade,config:pass.rig.config,weaponHandIndex:weapon=>pass.rig.weaponHandIndex(weapon),weaponDims:weapon=>pass.rig.weaponDims(weapon),handSide:index=>pass.rig.handSide(index),weaponFrame:weapon=>pass.rig.weaponFrame(weapon)}:null;}


const idleFront = new WeakMap();
function localNativeRiding(game){const r=game?.mounts?.system?.riding;return r?.active&&r.player===game.player&&r.rig?.root?.parent===game.player?.group?r:null;}
/** Expose only the actual local mount during the avatar-hidden world draw. */
export function exposeLocalNativeMount(game){
 const riding=localNativeRiding(game),scene=game?.scene;if(!riding||!scene)return ()=>{};
 const roots=[riding.rig.root,...game.player._weaponObjs.filter(w=>w.obj.visible).map(w=>w.obj)],restore=[];
 scene.updateWorldMatrix(true,false);
 for(const root of roots){if(!root.parent)continue;const parent=root.parent,index=parent.children.indexOf(root),matrix=root.matrix.clone(),auto=root.matrixAutoUpdate;root.updateWorldMatrix(true,true);const world=root.matrixWorld.clone();restore.push({root,parent,index,matrix,auto});root.matrixAutoUpdate=false;scene.add(root);root.matrix.copy(scene.matrixWorld).invert().multiply(world);root.updateMatrixWorld(true);}
 return ()=>{for(const {root,parent,index,matrix,auto}of restore){parent.add(root);const at=parent.children.indexOf(root);parent.children.splice(at,1);parent.children.splice(index,0,root);root.matrix.copy(matrix);root.matrixAutoUpdate=auto;root.updateMatrixWorld(true);}};
}
export function nativeAvatarEyeOffset(p,yaw){if(localNativeRiding(p?.game)){p.group.updateWorldMatrix(true,true);const head=p.instance.getBone('Bip01 Head');if(head){const at=new THREE.Vector3().setFromMatrixPosition(head.matrixWorld),base=new THREE.Vector3().setFromMatrixPosition(p.group.matrixWorld),offset=new THREE.Vector3(at.x-base.x,0,at.z-base.z),nose=Math.min(.16,Number(p.model.radius)||.16)*(Number(p.scale)||1);offset.x-=Math.sin(Number(yaw)||0)*nose;offset.z-=Math.cos(Number(yaw)||0)*nose;const w=p.game?.world,tx=p.x+offset.x,tz=p.z-offset.z;if(w?.isWalkable&&!w.isWalkable(tx,tz)||w?.collision?.lineOfSight&&!w.collision.lineOfSight(p.x,p.z,tx,tz))return new THREE.Vector3();return offset;}}const h=p?.model?.skel?.bones?.find(b=>/\bHead(?:\s|$)/i.test(b.name+' '+b.alias));if(!h||!p.instance)return null;p.group.updateWorldMatrix(true,false);p.instance.root.updateMatrix();const at=new THREE.Vector3(h.bindMatrix[12],h.bindMatrix[13],h.bindMatrix[14]).applyMatrix4(p.instance.root.matrix).applyMatrix4(p.group.matrixWorld),base=new THREE.Vector3().setFromMatrixPosition(p.group.matrixWorld),offset=new THREE.Vector3(at.x-base.x,0,at.z-base.z);let clearance=idleFront.get(p.instance);if(clearance===undefined){p.instance.skeleton.update();const v=new THREE.Vector3(),waist=Number(p.model.skel.bones.find(b=>/\bPelvis(?:\s|$)/i.test(b.name))?.bindMatrix?.[13]);let front=.16,pantsTop=-Infinity;for(const m of p.instance.meshes)if(/_pat_/.test(m.name)||p.transformLook?.mesh){for(let i=0;i<m.geometry.attributes.position.count;i++){m.getVertexPosition(i,v);if(p.transformLook?.mesh&&v.y>waist)continue;if(Number.isFinite(v.z))front=Math.max(front,-v.z+.05);if(Number.isFinite(v.y))pantsTop=Math.max(pantsTop,v.y);}}const verticalHalfFov=THREE.MathUtils.degToRad(Number(p.game?.camera?.fov)||70)/2,backSlope=Math.max(0,Math.tan(1.45+verticalHalfFov-Math.PI/2)),eyeGap=Number.isFinite(pantsTop)?Math.max(0,Number(h.bindMatrix[13])-pantsTop):0;front+=eyeGap*backSlope;clearance=Math.min(front,Math.max(.16,Number(p.model.radius)||.16))*(Number(p.scale)||1);idleFront.set(p.instance,clearance);}offset.x-=Math.sin(Number(yaw)||0)*clearance;offset.z-=Math.cos(Number(yaw)||0)*clearance;const limit=(Number(p.model.radius)||.16)*(Number(p.scale)||1);if(offset.length()>limit)offset.setLength(limit);const w=p.game?.world,tx=p.x+offset.x,tz=p.z-offset.z;if(w?.isWalkable&&!w.isWalkable(tx,tz)||w?.collision?.lineOfSight&&!w.collision.lineOfSight(p.x,p.z,tx,tz))return new THREE.Vector3();return offset;}
