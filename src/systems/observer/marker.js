// Local observer position/facing marker. Native observer_shape.csv index1 binds
// exactly one animated plane and observer_02#.dds through observer_01.tpack.
// Local-only attachment and a2cm ground offset are engine presentation choices;
// the original table does not say to hide the player's body or stack other art.
import {fetchCSV} from '../../engine/assets.js';
import {gameKey} from '../../formats/modeldef.js';
import {Animator} from '../../engine/animator.js';

export const OBSERVER_MARKER_TABLE='script/shape/observer_shape.csv';
export function observerMarkerShape(rows){
 const row=rows?.find(r=>Number(r[0])===1);if(!row)return null;
 const shape={index:1,name:String(row[1]),anim:gameKey('anim',row[2]),mesh:gameKey('mesh',row[3]),skel:gameKey('skel',row[4]),tpack:gameKey('texturepack',row[5])};
 return Object.entries(shape).every(([k,v])=>k==='index'||typeof v==='string'&&v.length>0)?shape:null;
}
export function createObserverMarker(game,{loadRows=fetchCSV,onError=error=>console.warn('[observer] marker unavailable',error)}={}){
 let seat=null,instance=null,animator=null,pending=null,serial=0,disposed=false,failed=false,world=null;
 const matches=()=>!disposed&&seat&&game.player&&!game.player.disposed&&game.worldRoot&&Number(game.world?.info?.index)===Number(seat.map);
 const release=()=>{serial++;animator?.dispose();animator=null;instance?.dispose();instance=null;pending=null;world=null;};
 function sync(){
  if(!instance||!matches())return;
  const p=game.player,root=instance.root,x=Number(p.x),z=Number(p.z);if(!Number.isFinite(x)||!Number.isFinite(z)){root.visible=false;return;}
  let y=Number(p.y);try{const h=game.world?.heightAt?.(x,z,Number.isFinite(y)?y:undefined);if(Number.isFinite(h))y=h;}catch{}
  root.visible=Number.isFinite(y);if(!root.visible)return;
  root.position.set(x,y+.02,z);root.rotation.y=Number.isFinite(p.yaw)?p.yaw:0;
 }
 async function load(){
  if(pending||instance||failed||!matches())return pending;
  const generation=++serial,scene=game.world,worldRoot=game.worldRoot;
  const current=()=>generation===serial&&matches()&&game.world===scene&&game.worldRoot===worldRoot;
  const task=(async()=>{
   try{
    const shape=observerMarkerShape(await loadRows(OBSERVER_MARKER_TABLE,true));if(!shape)throw Error('Native observer shape1 is missing.');
    if(!current())return;
    const model=await game.models?.loadSkinned?.({skelKey:shape.skel,parts:[{meshKey:shape.mesh,tpackKey:shape.tpack,transparent:true,depthWrite:false,twoSide:true,maxDiffuse:true}]});
    if(!current())return;if(!model||model.empty||model.missingSkeleton)throw Error('Native observer model is unavailable.');
    let clip;
    try{clip=await game.models.loadClipWithStatus(shape.anim,model);}
    catch(error){if(error?.transient)return;throw error;}
    if(!current())return;
    if(!clip)throw Error('Native observer animation is unavailable.');
    instance=model.instantiate();instance.root.name='observer-local-marker';instance.root.userData.observerMarker={...shape};
    animator=new Animator(instance);animator.play(clip,{loop:true,fade:0});animator.update(0);
    // Shared native model resources remain cached; dispose only this skeleton and
    // mixer. The marker is not an Actor and cannot enter picking/network lists.
    world=scene;worldRoot.add(instance.root);sync();
   }catch(error){if(current()){if(error?.transient){release();return;}release();failed=true;onError(error);}}
   finally{if(generation===serial)pending=null;}
  })();pending=task;return task;
 }
 return {
  setSeat(next){
   if(disposed)return;
   const same=seat&&next&&['map','venue','instanceId','channel'].every(k=>(seat[k]??null)===(next[k]??null));
   if(!same){release();failed=false;}seat=next?{...next}:null;if(seat)void load();
  },
  update(dt){
   if(disposed)return;
   if(!matches()||world&&world!==game.world){if(instance||pending)release();return;}
   if(!instance){void load();return;}sync();animator?.update(Math.max(0,Number(dt)||0));
  },
  clear(){seat=null;failed=false;release();},
  dispose(){if(disposed)return;disposed=true;seat=null;release();},
  get root(){return instance?.root||null;},get pending(){return pending;},get disposed(){return disposed;},
 };
}
