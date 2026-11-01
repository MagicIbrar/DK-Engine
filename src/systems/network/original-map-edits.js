import {applyNativeHeightPatch} from '../../world/original-height-patch.js';
import {MapDoc,writeMac} from '../mapbuilder/format.js';
import {applyOriginalChanges,validateOriginalOverlay,originalPatchEntries} from '../mapbuilder/original-overlay.js';
import {captureCurrentFieldView,captureCurrentFieldDetails} from '../mapbuilder/editor/current-field-view.js';
import {sha256Hex} from './web-crypto.js';
import {parseMac} from '../../formats/mac.js';
// sha256Hex also works on a friend's http://<LAN address> join, where the browser has no SubtleCrypto.
function assertNativeCollision(macBytes,parsed){
 if(!macBytes||!(macBytes.byteLength>0))throw Object.assign(Error('Map collision data did not finish loading. Retry loading.'),{transient:true});
 let grid=null;try{grid=parseMac(macBytes);}catch{grid=null;}
 const width=Number(parsed?.width),height=Number(parsed?.height);
 if(!grid||!(grid.width>0)||!(grid.height>0)||!(width>0)||!(height>0)||grid.width!==width||grid.height!==height)throw Error('The original map collision file is invalid for this map.');
}
export async function originalSourceHash(map,mac){const a=new Uint8Array(map),b=new Uint8Array(mac),bytes=new Uint8Array(a.length+b.length);bytes.set(a);bytes.set(b,a.length);return sha256Hex(bytes);}
export async function installOriginalMapEdits(game,network){
 let catalog={epoch:null,maps:[]},queued=null,queuedLease=null,syncing=false,disposed=false,timer=null,heldPause=null,editing=false,lastAck=null;
 const priorSnapshot=network._snapshot,priorAction=network.action;let wrappedSnapshot,wrappedAction;
 const request=(op,body)=>network._request(`original-map-edits${op?'/'+op:''}`,body);
 try{catalog=await request('');}catch(error){if(error.status!==503)throw error;}
 if(!Array.isArray(catalog.maps)||catalog.maps.some(i=>!Number.isInteger(i)||i<0||i>=90000))throw Error('Invalid original edit catalog.');
 // Authoring calls pin the lease before any await, including Begin's read.
 // A native adapter also supplies its editor-context guard. Never substitute
 // a replacement network token for a pending session's mutation or cleanup.
 function assertLease({lease=network.token,guard=()=>true}={}){if(disposed||network.disposed||network.token!==lease||!guard())throw Error('The original editor lease or context changed.');}
 async function leaseRequest(op,body,options={}){const pinned={...options,lease:options.lease??network.token};assertLease(pinned);const result=await request(op,body===undefined?undefined:{...body,token:pinned.lease});assertLease(pinned);return result;}
 const sources=new WeakMap();let awaitingInitialWorld=!game.world;
 const api=game.originalMapEdits={
  list:()=>[...catalog.maps],sourceHash:originalSourceHash,entryView:()=>captureCurrentFieldView(game),entryDetails:()=>captureCurrentFieldDetails(game),get currentIndex(){return Number(game.world?.info?.index);},
  read:(index,options)=>leaseRequest(String(index),undefined,options),
  async begin(index,options={}){const pinned={...options,lease:options.lease??network.token};assertLease(pinned);if(!game.accountPermissions?.capabilities?.includes('gm:commands'))throw Error('GM editing authority is required.');const current=await api.read(index,pinned);return leaseRequest('begin',{index,epoch:current.epoch,expectedVersion:current.version},pinned);},
  patch:(input,options)=>leaseRequest('patch',input,options),finish:(input,options)=>leaseRequest('finish',input,options),
  async loadSource(index,mapBytes,macBytes,parsed){
   if(!catalog.maps.includes(Number(index)))return null;
   // Collision first, on every branch: world.js swallows a failed .mac fetch and Collision.fromBuffer
   // falls back to walkable cells. A missing buffer is a transient load failure; a malformed or
   // wrong-size grid is refused. Neither may masquerade as an overlay mismatch or an unmodified map.
   assertNativeCollision(macBytes,parsed);
   const state=await api.read(index);
   // The host could not validate live editing for this client data and holds no committed
   // overlay: load the unmodified original map (editing stays refused on the host).
   if(state?.phase==='unavailable')return null;
   if(await originalSourceHash(mapBytes,macBytes)!==state.sourceHash)throw Error('The original map/collision files do not match this server overlay.');
   const doc=MapDoc.fromFiles({map:mapBytes,mac:macBytes}),baseHeights=doc.heights.slice();const patch=validateOriginalOverlay(doc,state.changes);applyOriginalChanges(doc,originalPatchEntries(patch));
   // Preserve parsed file fields, native placement tables and row/environment.
   const view=doc.mapView();for(const field of ['heights','colors','vertexTypes','normals','cellVariants','holes','water'])parsed[field]=view[field];
   sources.set(parsed,{baseHeights,patch,doc});return {state,mac:writeMac(doc.width,doc.height,doc.attrs)};
  },
  dispose(){disposed=true;if(timer)clearTimeout(timer);timer=null;queued=null;editing=false;if(network._snapshot===wrappedSnapshot)network._snapshot=priorSnapshot;if(network.action===wrappedAction)network.action=priorAction;if(heldPause!==null&&!game._loadingMap){game.paused=heldPause;heldPause=null;}if(game.originalMapEdits===api)game.originalMapEdits=null;},
 };
 const previous=network._snapshot.bind(network),action=network.action.bind(network);
 const errorNotice=error=>{network._lastCommandError={message:error.message,at:Date.now()};};
 function retry(){if(timer)clearTimeout(timer);timer=setTimeout(()=>{timer=null;if(disposed||network.disposed)return;void network.poll().catch(errorNotice).finally(()=>void sync());},500);}
 async function sync(){
  if(syncing||!queued||disposed||network.disposed)return;
  if(queuedLease!==network.token){queued=null;editing=false;if(heldPause!==null&&!game._loadingMap){game.paused=heldPause;heldPause=null;}return;}
  syncing=true;const lease=network.token;
  try{
   if(heldPause===null)heldPause=!!game.paused;game.paused=true;
   while(queued&&!disposed&&!network.disposed&&network.token===lease){
    const current=queued,notice=current.self.originalEditPending;
    if(!notice){queued=null;editing=false;previous(current);break;}
    // Game.start owns the first enterMap after system installation. A saved
    // overlay join can arrive earlier; keep it pending until that load ends.
    if(awaitingInitialWorld){if(!game.world||game._loadingMap){retry();break;}awaitingInitialWorld=false;}
    if(game._loadingMap||network._transferring){retry();break;}
    const loaded=game.world?.info?.originalEdit;
    if(Number(game.world?.info?.index)!==notice.index||loaded?.epoch!==notice.epoch||loaded?.version!==notice.version||loaded?.generation!==notice.generation){
     const world=game.world,source=sources.get(world?.map);let incremental=false;
     if(source&&Number(world.info?.index)===notice.index&&loaded?.epoch===notice.epoch){
      const next=await api.read(notice.index);
      if(next.epoch!==notice.epoch||next.version!==notice.version||next.generation!==notice.generation||next.sourceHash!==loaded.sourceHash)throw Error('The pending native height generation changed.');
      if(disposed||network.disposed||network.token!==lease||game.world!==world||game._loadingMap)throw Error('Native height scene or lease changed.');
      const patch=validateOriginalOverlay(source.doc,next.changes),changes=[];
      for(const key of new Set([...source.patch.keys(),...patch.keys()])){const before=source.patch.get(key),after=patch.get(key);if(before?.[2]===after?.[2])continue;const field=after?.[0]||before[0],index=after?.[1]??before[1];if(field!=='heights'){changes.push([field,index,after?.[2]??0]);continue;}changes.push(['heights',index,after?.[2]??source.baseHeights[index]]);}
      if(!changes.length)incremental=true;
      else {try{const result=applyNativeHeightPatch(world,changes,[game.player,...(game.npcs||[]),...(network.actors?.()||[])]);incremental=result.applied;if(!incremental)network._lastHeightFallback=result.reason;}catch(error){network._lastHeightFallback=error.message;incremental=false;}}
      if(incremental){source.patch=patch;world.info.originalEdit=next;}
     }
     if(!incremental){network.self=current.self;network._clearActors?.();await game.enterMap(notice.index,{x:current.self.x,z:current.self.z,dirDeg:(current.self.yaw||0)*180/Math.PI},null,{serverTransfer:true});}
     if(disposed||network.disposed||network.token!==lease)break;game.paused=true;
     if(queued!==current)continue;
     const actual=game.world?.info?.originalEdit;
     if(actual?.epoch!==notice.epoch||actual?.version!==notice.version||actual?.generation!==notice.generation)throw Error('The exact original edit generation is still loading.');
    }
    if(lastAck?.lease!==lease||lastAck.generation!==notice.generation){await request('ready',{token:lease,index:notice.index,epoch:notice.epoch,version:notice.version,generation:notice.generation});lastAck={lease,generation:notice.generation};}
    if(disposed||network.disposed||network.token!==lease)break;
    if(queued!==current)continue;
    queued=null;editing=notice.phase==='editing'&&!notice.heightOnly;previous(current);
   }
  }catch(error){errorNotice(error);retry();}
  finally{syncing=false;if(queuedLease!==network.token||disposed||network.disposed){queued=null;editing=false;}if(!queued&&!editing&&!game._loadingMap&&heldPause!==null){game.paused=heldPause;heldPause=null;}else if(heldPause!==null)game.paused=true;if(queued&&!timer&&!disposed&&!network.disposed)retry();}
 }
 network.action=wrappedAction=(...args)=>syncing||queued||editing?Promise.resolve(null):action(...args);
 network._snapshot=wrappedSnapshot=state=>{
  if(disposed||network.disposed||!state?.self||Number(state.sequence)<Number(network.sequence))return;
  if(state.self.originalEditPending||syncing||queued||editing){if(!queued||queuedLease!==network.token||Number(state.sequence)>=Number(queued.sequence)){queued=state;queuedLease=network.token;}void sync();return;}
  previous(state);
 };
 return api;
}
