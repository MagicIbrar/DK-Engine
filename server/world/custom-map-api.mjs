import {CUSTOM_MAP_LIMITS} from './custom-maps.mjs';
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
const json=(res,status,value)=>{res.writeHead(status,{'Content-Type':'application/json; charset=utf-8','Cache-Control':'no-store','X-Content-Type-Options':'nosniff'});res.end(JSON.stringify(value));};
const revision=value=>{if(!/^(0|[1-9]\d*)$/.test(String(value??''))||!Number.isSafeInteger(Number(value)))fail('Expected a valid map library revision.');return Number(value);};

// Caller performs same-origin validation and initial account authentication.
// Publication re-authenticates after reading the bounded body and serializing.
export async function handleCustomMapRequest({req,res,pathname,user,world,library,resolveUser,serialize}){
 if(!/^\/api\/world\/custom-maps(?:\/|$)/.test(pathname))return false;
 if(!user?.id)fail('Sign in to read server maps.',401);
 if(!library)fail('The server map library is unavailable.',503);
 if(req.method==='POST'&&pathname==='/api/world/custom-maps/ready'){
  if(!/^application\/json(?:;|$)/i.test(req.headers['content-type']||''))fail('Expected a map readiness notice.',415);
  const chunks=[];let length=0;for await(const chunk of req){length+=chunk.length;if(length>1024)fail('Map readiness notice is too large.',413);chunks.push(chunk);}
  let input;try{input=JSON.parse(Buffer.concat(chunks).toString());}catch{fail('Invalid map readiness notice.');}
  if(!input||Array.isArray(input)||typeof input!=='object'||Object.keys(input).some(k=>!['token','index','revision','generation'].includes(k))||typeof input.token!=='string'||!Number.isInteger(input.index)||!Number.isSafeInteger(input.revision)||input.revision<1||!/^[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}$/i.test(input.generation||''))fail('Invalid map readiness notice.');
  const result=await serialize(user.id,async()=>{
   const current=await resolveUser(req);if(!current||current.id!==user.id)fail('Your account session expired before map readiness.',401);
   const player=world.lease(user.id,input.token),entry=library.entry(input.index);
   if(Number(player.map)!==input.index||!entry||entry.revision!==input.revision)fail('The loaded map revision changed. Reload it before playing.',409);
   const pending=player.customMapPending;
   if(pending){
    if(pending.index!==input.index||pending.revision!==input.revision||pending.generation!==input.generation)fail('The pending map revision changed.',409);
    if(world.now()>=pending.deadline)fail('Map readiness timed out. Rejoin to continue.',409);
    player.customMapReady={index:input.index,revision:input.revision,generation:input.generation};player.customMapPending=null;player.sceneTransition=false;
   }else if(!player.customMapReady||player.customMapReady.index!==input.index||player.customMapReady.revision!==input.revision||player.customMapReady.generation!==input.generation)fail('That map readiness generation is no longer active.',409);
   return {ok:true,index:input.index,revision:input.revision};
  });json(res,200,result);return true;
 }
 if(req.method==='GET'&&pathname==='/api/world/custom-maps'){json(res,200,{revision:library.revision,maps:library.list()});return true;}
 if(req.method==='GET'&&/^\/api\/world\/custom-maps\/\d+\.dkmap$/.test(pathname)){
  const index=Number(pathname.split('/').at(-1).slice(0,-6)),entry=library.entry(index),query=new URL(req.url,'http://localhost').searchParams;
  if(!entry)fail('Server map not found.',404);
  if(query.has('revision')&&revision(query.get('revision'))!==entry.revision)fail('The server map changed. Refresh its catalog.',409);
  const bytes=await library.archive(index);res.writeHead(200,{'Content-Type':'application/x-dekaron-map','Cache-Control':'private, no-store','X-Dekaron-Map-Revision':String(entry.revision),'X-Content-Type-Options':'nosniff'});res.end(bytes);return true;
 }
 if(req.method!=='POST'||pathname!=='/api/world/custom-maps')fail('Unknown map-library operation.',404);
 if(!user.capabilities?.includes('gm:commands'))fail('GM permission is required to publish maps.',403);
 if(!/^application\/x-dekaron-map(?:;|$)/i.test(req.headers['content-type']||''))fail('Upload an exported .dkmap archive.',415);
 const limit=CUSTOM_MAP_LIMITS.archiveBytes,declared=req.headers['content-length'];if(declared!=null&&(!/^\d+$/.test(String(declared))||Number(declared)>limit))fail('Map archive exceeds16MiB.',413);
 const expectedRevision=revision(req.headers['x-dekaron-map-revision']),rawIndex=req.headers['x-dekaron-map-index'],editingIndex=rawIndex==null?null:revision(rawIndex);
 const token=req.headers['x-dekaron-world-token'],requestId=req.headers['x-dekaron-map-request'];
 const chunks=[];let bytes=0;for await(const chunk of req){bytes+=chunk.length;if(bytes>limit)fail('Map archive exceeds16MiB.',413);chunks.push(chunk);}
 const result=await serialize(user.id,async()=>{
  const current=await resolveUser(req);if(!current||current.id!==user.id)fail('Your account session expired before publication.',401);
  if(!current.capabilities?.includes('gm:commands'))fail('GM publication permission was revoked.',403);
  const player=world.lease(user.id,token);player.capabilities=current.capabilities;
  return library.publish(world,player,{bytes:Buffer.concat(chunks),expectedRevision,editingIndex,token,requestId});
 });json(res,200,result);return true;
}
