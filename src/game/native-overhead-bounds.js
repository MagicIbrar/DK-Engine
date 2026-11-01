import * as THREE from 'three';

// Screen envelope of the actual live native emblem units. Sprite quads use the
// same camera-space centre/scale/roll as THREE.Sprite. Particle pools are bounded
// (160 per unit): inspect their centres/sizes, never their vertex buffers. Native
// mesh geometry and per-bone skin bounds are cached once; live bone transforms
// cover animation without a per-frame vertex scan.
// This is presentation clearance, not a change to native attachment or artwork.
//
// Held extremes (ENGINE CHOICE, presentation only; round 3). A looping
// native aura's live particle/sprite envelope changes every frame as authored
// particles spawn and die, so a plate that follows it alone jumped up to 50-101px
// per frame while the wearer stood still (Snowflake V / Aquanic V / Karon Bell V,
// default native camera). Every live envelope item (sprite/mesh corner, particle
// centre with its circumscribed radius) is therefore also folded, in the wearer's
// own frame (actor.group), into the most extreme observed items along 26 fixed
// directions, kept over the current and the previous authored loop window
// (handle.timeMs, clamped 0.5-4 s). The unbounded measurement covers those observed
// items projected like the live envelope, never less than this frame's live
// envelope. They move with the wearer and the
// camera, reset on emblem change/unequip/expiry, and drop only after a whole loop
// window without them. The caller separately caps nameplate spacing to keep large
// transparent quads and particle trails from detaching labels from their wearer.
// Held items are actual native unit positions (no synthetic
// box corners), so a close camera is not pushed further than by real aura geometry.
// No native artwork/scale/attachment/playback changes.
const HOLD_MIN_S=.5,HOLD_MAX_S=4;
const DIRECTIONS=[];for(let x=-1;x<=1;x++)for(let y=-1;y<=1;y++)for(let z=-1;z<=1;z++)if(x||y||z){const n=Math.hypot(x,y,z);DIRECTIONS.push(x/n,y/n,z/n);}
const SUPPORTS=DIRECTIONS.length/3;
const point=new THREE.Vector3(),centre=new THREE.Vector3(),scale=new THREE.Vector3(),corner=new THREE.Vector3(),local=new THREE.Vector3(),heldCentre=new THREE.Vector3();
const matrix=new THREE.Matrix4(),skinMatrix=new THREE.Matrix4(),toLocal=new THREE.Matrix4(),geometryBounds=new WeakMap(),skinBounds=new WeakMap(),holds=new WeakMap();
const visible=object=>{for(let o=object;o;o=o.parent)if(o.visible===false)return false;return !!object?.parent;};
const materialVisible=object=>{const mats=Array.isArray(object.material)?object.material:[object.material];return mats.some(m=>m&&m.visible!==false&&(!m.transparent||m.opacity>0));};
const extremes=()=>({value:new Float64Array(SUPPORTS).fill(-Infinity),points:new Float64Array(SUPPORTS*4)});
const clearExtremes=e=>{e.value.fill(-Infinity);return e;};
// Fold one live native envelope item - a wearer-frame centre and its world radius (0 for
// a sprite/mesh corner, the particle's circumscribed radius otherwise) - into the
// window's extreme items. It is later projected exactly as the live envelope projects it.
const foldItem=(e,x,y,z,localRadius,radius)=>{
 for(let k=0,d=0,p=0;k<SUPPORTS;k++,d+=3,p+=4){
  const v=DIRECTIONS[d]*x+DIRECTIONS[d+1]*y+DIRECTIONS[d+2]*z+localRadius;
  if(v>e.value[k]){e.value[k]=v;e.points[p]=x;e.points[p+1]=y;e.points[p+2]=z;e.points[p+3]=radius;}
 }
};

// Held extremes for this live record, in the wearer's frame; null when the wearer has
// no scene frame or the game has no clock (isolated callers keep the live envelope).
function heldFor(actor,game,record){
 const frame=actor?.group?.isObject3D?actor.group:null,now=Number(game?.time);
 if(!frame||!Number.isFinite(now))return null;
 let first=null,period=0;
 for(const handle of record.handles||[])if(handle.equipmentSlot==='emblem'&&!handle.done){first||=handle;period=Math.max(period,Number(handle.timeMs)/1000||0);}
 if(!first)return null;
 let hold=holds.get(record);
 if(!hold||hold.handle!==first||now<hold.start){hold={handle:first,start:now,current:extremes(),previous:extremes()};holds.set(record,hold);}
 hold.period=Math.min(HOLD_MAX_S,Math.max(HOLD_MIN_S,period||1));
 const age=now-hold.start;
 if(age>=2*hold.period){clearExtremes(hold.current);clearExtremes(hold.previous);hold.start=now;}
 else if(age>=hold.period){const old=hold.previous;hold.previous=hold.current;hold.current=clearExtremes(old);hold.start=now;}
 frame.updateWorldMatrix(true,false);toLocal.copy(frame.matrixWorld).invert();hold.frame=frame;hold.scale=frame.matrixWorld.getMaxScaleOnAxis()||1;
 return hold;
}

export function nativeOverheadTop(actor,game,viewport){
 const record=game?.items?.authoredEffects?.records?.get(actor),camera=game?.camera;
 if(!record||record.expired||!camera||!(viewport?.height>0))return null;
 const hold=heldFor(actor,game,record);
 let top=Infinity;
 const fold=(world,radius=0)=>{if(hold){local.copy(world).applyMatrix4(toLocal);foldItem(hold.current,local.x,local.y,local.z,radius/hold.scale,radius);}};
 const reach=world=>{
  point.copy(world).applyMatrix4(camera.matrixWorldInverse);
  if(point.z>=-camera.near)return;
  point.applyMatrix4(camera.projectionMatrix);
  if(point.z>1)return;
  const y=(viewport.top||0)+(1-point.y)*.5*viewport.height;
  if(Number.isFinite(y))top=Math.min(top,y);
 };
 const project=world=>{fold(world);reach(world);};
 const cube=(world,radius)=>{
  if(!(radius>0)){reach(world);return;}
  for(let i=0;i<8;i++){
   corner.set(world.x+(i&1?radius:-radius),world.y+(i&2?radius:-radius),world.z+(i&4?radius:-radius));reach(corner);
  }
 };
 const envelope=(world,radius)=>{fold(world,radius);cube(world,radius);};
 const sprite=mesh=>{
  if(!visible(mesh)||!materialVisible(mesh))return;
  mesh.updateWorldMatrix(true,false);centre.setFromMatrixPosition(mesh.matrixWorld).applyMatrix4(camera.matrixWorldInverse);scale.setFromMatrixScale(mesh.matrixWorld);
  const front=centre.z<-camera.near;
  if(!front&&!hold)return;
  const c=Math.cos(mesh.material.rotation||0),s=Math.sin(mesh.material.rotation||0),origin=mesh.center||{x:.5,y:.5};
  for(let i=0;i<4;i++){
   const x=((i&1?1:0)-origin.x)*scale.x,y=((i&2?1:0)-origin.y)*scale.y;
   corner.set(centre.x+c*x-s*y,centre.y+s*x+c*y,centre.z);
   if(hold)fold(point.copy(corner).applyMatrix4(camera.matrixWorld));
   if(!front)continue;
   point.copy(corner).applyMatrix4(camera.projectionMatrix);
   if(point.z<=1&&Number.isFinite(point.y))top=Math.min(top,(viewport.top||0)+(1-point.y)*.5*viewport.height);
  }
 };
 const meshEnvelope=mesh=>{
  if(!mesh.isMesh||!visible(mesh)||!materialVisible(mesh)||!mesh.geometry)return;
  const box=(bound,transform)=>{
   for(let i=0;i<8;i++){corner.set(i&1?bound.max.x:bound.min.x,i&2?bound.max.y:bound.min.y,i&4?bound.max.z:bound.min.z).applyMatrix4(transform);project(corner);}
  };
  mesh.updateWorldMatrix(true,false);
  const {position,skinIndex,skinWeight}=mesh.geometry.attributes;
  if(mesh.isSkinnedMesh&&position&&skinIndex&&skinWeight){
   let boxes=skinBounds.get(mesh);
   if(!boxes){
    boxes=new Map();
    // A normalized weighted skin vertex lies inside the union's convex hull.
    // Cache each contributing bone's vertices in its native inverse-bind frame.
    for(let i=0;i<position.count;i++){
     centre.fromBufferAttribute(position,i).applyMatrix4(mesh.bindMatrix);
     for(let k=0;k<4;k++){
      if(skinWeight.getComponent(i,k)<=0)continue;
      const index=skinIndex.getComponent(i,k),inverse=mesh.skeleton.boneInverses[index];if(!inverse)continue;
      let bound=boxes.get(index);if(!bound){bound=new THREE.Box3();boxes.set(index,bound);}
      corner.copy(centre).applyMatrix4(inverse);bound.expandByPoint(corner);
     }
    }
    skinBounds.set(mesh,boxes);
   }
   // The renderer refreshes attached bindMatrixInverse only later. Its current
   // value can still describe last frame's actor position; world*inverse is
   // exactly identity for the attached mode in the upcoming native draw.
   if(mesh.bindMode===THREE.AttachedBindMode)skinMatrix.identity();
   else skinMatrix.multiplyMatrices(mesh.matrixWorld,mesh.bindMatrixInverse);
   for(const [index,bound]of boxes){const bone=mesh.skeleton.bones[index];if(!bone)continue;bone.updateWorldMatrix(true,false);matrix.multiplyMatrices(skinMatrix,bone.matrixWorld);box(bound,matrix);}
  }else{
   let bound=geometryBounds.get(mesh.geometry);
   if(!bound){if(!mesh.geometry.boundingBox)mesh.geometry.computeBoundingBox();bound=mesh.geometry.boundingBox?.clone();if(!bound)return;geometryBounds.set(mesh.geometry,bound);}
   box(bound,mesh.matrixWorld);
  }
 };
 for(const handle of record.handles||[]){
  if(handle.equipmentSlot!=='emblem'||handle.done)continue;
  for(const control of handle.controls||[]){
   const unit=control.unit;if(!unit?.ready||unit.disposed||!visible(unit.object))continue;
   if(unit.unit?.type==='particle'){
    if(!materialVisible(unit.object)||(unit.st?.alpha??1)<=0)continue;
    unit.object.updateWorldMatrix(true,false);
    const st=unit.st?.scale||[1,1,1],stretch=unit.em?.followDir?2:1;
    const gain=.5*Math.hypot(st[0]??1,(st[1]??st[0]??1)*stretch)*unit.object.matrixWorld.getMaxScaleOnAxis();
    for(const particle of unit.parts||[]){centre.copy(particle.p).applyMatrix4(unit.object.matrixWorld);envelope(centre,particle.size*gain);}
   }else if(unit.mesh?.isSprite)sprite(unit.mesh);
   else unit.object.traverse(meshEnvelope);
  }
 }
 // Project the held wearer-frame extreme items of both windows (this frame's are already folded in).
 if(hold)for(const e of [hold.current,hold.previous])for(let k=0,p=0;k<SUPPORTS;k++,p+=4){
  if(e.value[k]===-Infinity)continue;
  heldCentre.set(e.points[p],e.points[p+1],e.points[p+2]).applyMatrix4(hold.frame.matrixWorld);cube(heldCentre,e.points[p+3]);
 }
 return Number.isFinite(top)?top:null;
}
