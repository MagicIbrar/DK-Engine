import {randomUUID} from './web-crypto.js';
import {unpackDkmap} from '../mapbuilder/pack.js';
import {validateMapFiles} from '../mapbuilder/validate.js';
import {isCustomIndex} from '../mapbuilder/format.js';
// The embedded builder creates its archive in another window's JS realm.
const archiveLength=value=>{try{return Object.getOwnPropertyDescriptor(ArrayBuffer.prototype,'byteLength').get.call(value);}catch{return -1;}};

export async function installSharedCustomMaps(game,network){
 let catalog={revision:-1,maps:[]},pending=null;const sources=new Map(),rendered=new WeakMap();
 async function refresh(){
  if(pending)return pending;
  pending=(async()=>{const result=await network._request('custom-maps');
   if(!Number.isSafeInteger(result.revision)||result.revision<0||!Array.isArray(result.maps)||result.maps.some(e=>!Number.isInteger(e.index)||!isCustomIndex(e.index)||!Number.isInteger(e.revision)||e.revision<1))throw Error('Invalid server map catalog.');
   if(result.revision<catalog.revision)return catalog;
   catalog={revision:result.revision,maps:result.maps.map(e=>({...e,server:true}))};
   for(const [index,source]of sources)if(!catalog.maps.some(e=>e.index===index&&e.revision===source.revision))sources.delete(index);
   game.serverCustomMaps=catalog;await game.customMaps?.refresh?.();game.events?.emit?.('server:custommaps',catalog);return catalog;
  })().finally(()=>{pending=null;});return pending;
 }
 const api=game.serverMaps={
  list:()=>structuredClone(catalog.maps),get revision(){return catalog.revision;},refresh,
  async source(index){
   const entry=catalog.maps.find(e=>e.index===Number(index));if(!entry)throw Error('Published server map not found.');
   const cached=sources.get(entry.index);if(cached?.revision===entry.revision)return structuredClone(await cached.task);
   const task=(async()=>{
    const res=await network.request(`/api/world/custom-maps/${entry.index}.dkmap?revision=${entry.revision}`,{credentials:'same-origin'});
    if(!res.ok){const error=await res.json();throw Object.assign(Error(error.error||'Server map unavailable.'),{status:res.status});}
    if(Number(res.headers.get('content-length'))>16*1024*1024)throw Error('Server map exceeds16MiB.');
    const bytes=await res.arrayBuffer();if(bytes.byteLength>16*1024*1024)throw Error('Server map exceeds16MiB.');
    const files=unpackDkmap(bytes);if(!files||files.meta.index!==entry.index)throw Error('Server map archive does not match its catalog.');validateMapFiles(files);
    // Transient source metadata identifies the geometry actually loaded, even
    // if another publication arrives while enterMap is still awaiting assets.
    files.meta.serverRevision=entry.revision;return files;
   })();sources.set(entry.index,{revision:entry.revision,task});while(sources.size>2)sources.delete(sources.keys().next().value);
   try{return structuredClone(await task);}catch(error){if(sources.get(entry.index)?.task===task)sources.delete(entry.index);throw error;}
  },
  async publish(bytes,{editingIndex=null,expectedRevision=catalog.revision,requestId=randomUUID()}={}){
   if(!network.ready||!network.token)throw Error('Connect to the shared world before publishing a map.');
   if(!game.accountPermissions?.capabilities?.includes('gm:commands'))throw Error('GM permission is required to publish maps.');
   const length=archiveLength(bytes);if(length<0||length>16*1024*1024)throw Error('Upload an exported .dkmap of at most16MiB.');
   const headers={'Content-Type':'application/x-dekaron-map','X-Dekaron-Map-Revision':String(expectedRevision),'X-Dekaron-Map-Request':requestId,'X-Dekaron-World-Token':network.token};if(editingIndex!=null)headers['X-Dekaron-Map-Index']=String(editingIndex);
   const response=await network.request('/api/world/custom-maps',{method:'POST',credentials:'same-origin',headers,body:bytes}),result=await response.json();
   if(!response.ok)throw Object.assign(Error(result.error||'Map publication failed.'),{status:response.status});
   await refresh();return result;
  },
 };
 const snapshot=network._snapshot.bind(network);
 let syncing=false,queued=null,queuedLease=null,retryAt=0,heldPause=null,reloadMap=null,retryTimer=null,retryDelay=1000,refreshRequired=false;
 const errorNotice=error=>{network._lastCommandError={message:error.message,at:Date.now()};};
 const loadedRevision=world=>Number(world?.source?.meta?.serverRevision)||rendered.get(world)||0;
 function scheduleRetry(){
  if(retryTimer)clearTimeout(retryTimer);
  // Game._frame stops updateSystems while paused. Polling-only clients need
  // an independent retry when a resource or readiness request fails.
  retryTimer=setTimeout(()=>{
   retryTimer=null;
   if(network.disposed){queued=null;return;}
   void Promise.resolve(network.poll?.()).catch(errorNotice).finally(()=>{void sync();});
  },Math.max(100,retryAt-Date.now()));
 }
 async function sync(){
  if(network.disposed||queued&&queuedLease!==network.token){queued=null;if(heldPause!==null&&!game._loadingMap){game.paused=heldPause;heldPause=null;}return;}
  if(syncing||!queued)return;
  // Timers may fire slightly early, and the wall clock can move. Never lose
  // the only paused-client retry simply because the deadline is not reached.
  if(Date.now()<retryAt){scheduleRetry();return;}
  syncing=true;const lease=network.token;let paused=heldPause!==null;
  try{
   if(isCustomIndex(game.world?.info?.index)){if(heldPause===null)heldPause=!!game.paused;game.paused=true;paused=true;}
   while(queued&&!network.disposed&&network.token===lease){
    const current=queued;
    if(Number(current.sequence)<Number(network.sequence)){queued=null;break;}
    if(refreshRequired||Number(current.customMapsRevision)>catalog.revision||!catalog.maps.some(e=>e.index===Number(current.self.map))){await refresh();refreshRequired=false;}
    if(network.disposed||network.token!==lease){if(network.disposed||queuedLease===lease)queued=null;break;}
    // Newer snapshots received during refresh supersede the stale pose.
    if(queued!==current)continue;
    const entry=catalog.maps.find(e=>e.index===Number(current.self.map)),world=game.world;
    const reload=entry&&(Number(world?.info?.index)===entry.index&&loadedRevision(world)!==entry.revision||reloadMap===entry.index&&!world);
    if(reload){
     if(game._loadingMap||network._transferring){retryAt=Date.now()+100;break;}
     if(heldPause===null)heldPause=!!game.paused;game.paused=true;paused=true;network._clearActors?.();
     reloadMap=entry.index;
     // Production enterMap calls joinMap before returning; it places the
     // avatar from network.self. Give it the relocated canonical pose so an
     // old self record cannot put the rebuilt avatar back inside a new wall.
     network.self=current.self;
     await game.enterMap(entry.index,{x:current.self.x,z:current.self.z,dirDeg:(current.self.yaw||0)*180/Math.PI},null,{serverTransfer:true});
     if(network.disposed||network.token!==lease){if(network.disposed||queuedLease===lease)queued=null;break;}
     game.paused=true;
     if(!game.world||Number(game.world.info?.index)!==entry.index)throw Error('Updated server map did not finish loading.');
     reloadMap=null;
     // Real sources carry their own marker. Fixtures/older integrations use
     // the requested revision only after a successful complete enterMap.
     if(!Number(game.world.source?.meta?.serverRevision))rendered.set(game.world,entry.revision);
     if(queued!==current)continue;
     if(loadedRevision(game.world)!==entry.revision)continue;
    }
    if(current.self.customMapPending){
     const notice=current.self.customMapPending;
     // A slow/failed renderer remains protected on the server. Acknowledge
     // only geometry loaded from the exact canonical archive and live lease.
     if(!entry||Number(game.world?.info?.index)!==entry.index||loadedRevision(game.world)!==notice.revision)throw Error('The current server map is still loading.');
     await network._request('custom-maps/ready',{token:lease,index:entry.index,revision:notice.revision,generation:notice.generation});
     if(network.disposed||network.token!==lease){if(network.disposed||queuedLease===lease)queued=null;break;}
     if(queued!==current)continue;
    }
    queued=null;snapshot(current);retryAt=0;retryDelay=1000;
   }
  }catch(error){errorNotice(error);refreshRequired=true;retryAt=Date.now()+retryDelay;retryDelay=Math.min(5000,retryDelay*2);}
  finally{
   syncing=false;
   if(queued&&(network.disposed||queuedLease!==network.token))queued=null;
   // On failed fetch/reload keep stale geometry paused until a later snapshot
   // can retry. Commands cannot run against the old movement mask meanwhile.
   if(paused&&!queued&&!game._loadingMap){game.paused=heldPause||false;heldPause=null;}
   else if(paused&&queued&&!game._loadingMap)game.paused=true;
   if(retryTimer){clearTimeout(retryTimer);retryTimer=null;}
   if(queued&&!network.disposed)scheduleRetry();
   if(queued&&!network.disposed&&network.token!==lease){retryAt=0;void sync();}
  }
 }
 const action=network.action?.bind(network);
 if(action)network.action=(...args)=>syncing||queued?Promise.resolve(null):action(...args);
 network._snapshot=state=>{
  if(network.disposed||!state?.self||Number(state.sequence)<Number(network.sequence))return;
  const wanted=Number.isSafeInteger(state?.customMapsRevision)&&state.customMapsRevision>catalog.revision;
  const unknown=isCustomIndex(state?.self?.map)&&!catalog.maps.some(e=>e.index===Number(state.self.map));
  const entry=catalog.maps.find(e=>e.index===Number(state.self.map));
  const changed=entry&&Number(game.world?.info?.index)===entry.index&&loadedRevision(game.world)!==entry.revision;
  if(syncing||queued||unknown||changed||state.self.customMapPending||wanted&&isCustomIndex(state.self.map)){
   if(!queued||queuedLease!==network.token||Number(state.sequence)>=Number(queued.sequence)){queued=state;queuedLease=network.token;}
   void sync();return;
  }
  snapshot(state);if(wanted)void refresh().catch(errorNotice);
 };
 try{await refresh();}catch(error){if(error.status!==503)throw error;catalog={revision:0,maps:[]};game.serverCustomMaps=catalog;await game.customMaps?.refresh?.();}
 if(game.world){const entry=catalog.maps.find(e=>e.index===Number(game.world.info?.index));if(entry&&!loadedRevision(game.world))rendered.set(game.world,entry.revision);}
 return api;
}
