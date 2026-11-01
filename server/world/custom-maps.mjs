import fs from 'node:fs/promises';
import path from 'node:path';
import {createHash,randomUUID} from 'node:crypto';
import {unpackDkmap,packDkmap} from '../../src/systems/mapbuilder/pack.js';
import {validateMapFiles} from '../../src/systems/mapbuilder/validate.js';
import {MapDoc,CUSTOM_BASE,META_FORMAT,isCustomIndex} from '../../src/systems/mapbuilder/format.js';
import {Collision} from '../../src/world/collision.js';
import {PathFinder} from '../../src/world/pathfind.js';
import {prepareCustomMapUpdate} from './custom-map-live.mjs';

export const CUSTOM_MAP_LIMITS=Object.freeze({archiveBytes:16*1024*1024,libraryBytes:512*1024*1024,maps:100});
const FORMAT='dekaron-online/server-custommaps@1';
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};
const digest=bytes=>createHash('sha256').update(bytes).digest('hex');
const copy=v=>structuredClone(v);
async function ordinary(target){
 let current=path.resolve(target);for(;;){try{const stat=await fs.lstat(current);if(stat.isSymbolicLink()||!stat.isDirectory()&&(!stat.isFile()||stat.nlink!==1))fail('Map library refuses linked or special files.');}catch(error){if(error.code!=='ENOENT')throw error;}const parent=path.dirname(current);if(parent===current)break;current=parent;}
 return path.resolve(target);
}
async function writeAtomic(file,bytes){await ordinary(file);await fs.mkdir(path.dirname(file),{recursive:true});const temp=`${file}.${randomUUID()}.tmp`;let handle;try{handle=await fs.open(temp,'wx',0o600);await handle.writeFile(bytes);await handle.sync();await handle.close();handle=null;await ordinary(file);await fs.rename(temp,file);}finally{await handle?.close();await fs.rm(temp,{force:true}).catch(()=>{});}}
function mapState(files,index,revision){
 const parsed=validateMapFiles(files).map,collision=Collision.fromBuffer(files.mac);
 if(!collision.hasData)fail('A complete collision grid is required for server deployment.');
 // Terrain holes are impassable even when the author left their MAC cells clear.
 for(let i=0;i<parsed.holes.length;i++)if(parsed.holes[i]){if(!collision.cells[i])collision.walkableCount--;collision.cells[i]=1;collision.grid.cells[i]=1;}
 const meta=MapDoc.fromFiles(files).meta,start=meta.start;
 if(!collision.isWalkable(start.x,start.z))fail('The map start must be on a walkable terrain cell.');
 const finder=new PathFinder(collision,{maxNodes:20000,snapRadius:8});
 return {index,name:meta.name,width:parsed.width,height:parsed.height,level:[meta.env.minLevel||1,meta.env.maxLevel||250],custom:true,customRevision:revision,collision,row:{Index:String(index),Name:meta.name,LimitMinLevel:String(meta.env.minLevel||0),LimitMaxLevel:String(meta.env.maxLevel||0),IsReturnScroll:String(meta.env.returnScroll??1)},start:copy(start),isWalkable:(x,z)=>collision.isWalkable(x,z),path:(x,z,tx,tz)=>finder.findPath(x,z,tx,tz),nearest:(x,z)=>collision.nearestWalkable(x,z,32)};
}
function entryOf(row,files){const m=MapDoc.fromFiles(files).meta;return {index:row.index,id:m.id,name:m.name,desc:m.desc||'',size:m.size,width:row.width,height:row.height,basedOn:m.basedOn??null,start:copy(m.start),env:copy(m.env),minimap:m.minimap||null,created:row.created,modified:row.modified,revision:row.revision,digest:row.digest,bytes:row.bytes,counts:{objects:m.objects||0,spawns:m.spawns.length,npcs:m.npcs.length,portals:m.portals.length}};}

/** All-or-nothing startup, globally serialized CAS publication, immutable archives. */
export async function loadCustomMaps({root,data,limits=CUSTOM_MAP_LIMITS,now=Date.now}={}){
 if(!root)throw new Error('Custom map library needs an explicit private storage root.');
 root=await ordinary(root);const manifest=path.join(root,'catalog.json');let state={format:FORMAT,version:1,revision:0,maps:[]};
 try{state=JSON.parse(await fs.readFile(await ordinary(manifest),'utf8'));}catch(error){if(error.code!=='ENOENT')throw error;}
 if(!state||state.format!==FORMAT||state.version!==1||!Number.isSafeInteger(state.revision)||state.revision<0||!Array.isArray(state.maps)||state.maps.length>limits.maps)fail('Invalid server map catalog; existing files preserved.');
 const records=new Map(),maps=new Map(),entries=new Map(),seen=new Set();let total=0;
 for(const row of state.maps){
  if(!row||!Number.isInteger(row.index)||!isCustomIndex(row.index)||seen.has(row.index)||!/^[a-f0-9]{64}$/.test(row.digest)||!Number.isSafeInteger(row.revision)||row.revision<1||!Number.isSafeInteger(row.bytes)||row.bytes<24||row.bytes>limits.archiveBytes)fail('Invalid server map record.');seen.add(row.index);total+=row.bytes;if(total>limits.libraryBytes)fail('Map catalog exceeds storage limit.');
  const bytes=await fs.readFile(await ordinary(path.join(root,`${row.digest}.dkmap`)));if(bytes.length!==row.bytes||digest(bytes)!==row.digest)fail('Stored map archive failed its integrity check.');
  const files=unpackDkmap(bytes);if(!files||files.meta.index!==row.index||files.meta.format!==META_FORMAT)fail('Stored map metadata does not match the catalog.');
  const map=mapState(files,row.index,row.revision);if(map.width!==row.width||map.height!==row.height)fail('Stored map dimensions do not match the catalog.');records.set(row.index,files);maps.set(row.index,map);entries.set(row.index,entryOf(row,files));
 }
 let queue=Promise.resolve();const deploying=new Set(),npcAt=new Map();
 const indexNpcLocations=()=>{npcAt.clear();for(const [index,files]of records)for(const n of files.meta.npcs||[]){if(!npcAt.has(n.npcIndex))npcAt.set(n.npcIndex,[]);npcAt.get(n.npcIndex).push([index,n.x,n.z]);}};indexNpcLocations();
 const api={
  get revision(){return state.revision;},get isPublishing(){return deploying.size>0;},isDeploying:index=>deploying.has(Number(index)),has:index=>maps.has(Number(index)),
  list:()=>copy([...entries.values()]),entry:index=>copy(entries.get(Number(index))||null),map:index=>maps.get(Number(index))||null,
  spawns:index=>(records.get(Number(index))?.meta.spawns||[]).map(s=>({...copy(s),id:`${index}:custom:${s.id}`})),
  gates:index=>(records.get(Number(index))?.meta.portals||[]).map(p=>({id:p.id,exclusive:true,box:[Math.min(p.x0,p.x1),Math.min(p.z0,p.z1),Math.max(p.x0,p.x1),Math.max(p.z0,p.z1)],to:copy(p.to)})),
  placements:index=>copy(records.get(Number(index))?.meta.npcs||[]),
  npcLocations:npcIndex=>copy(npcAt.get(Number(npcIndex))||[]),
  async archive(index){const row=state.maps.find(r=>r.index===Number(index));if(!row)fail('Server map not found.',404);const bytes=await fs.readFile(await ordinary(path.join(root,`${row.digest}.dkmap`)));if(bytes.length!==row.bytes||digest(bytes)!==row.digest)fail('Stored map archive failed its integrity check.',503);return bytes;},
  publish(world,player,input){
   const task=queue.catch(()=>{}).then(async()=>{
    if(!input||Object.keys(input).some(k=>!['bytes','expectedRevision','editingIndex','requestId','token'].includes(k)))fail('Invalid map publication command.');
    if(world.lease(player.account??player.id,input.token)!==player)fail('The world session changed.',409);
    if(!player.capabilities?.includes('gm:commands'))fail('GM permission is required to publish maps.',403);
    if(!Buffer.isBuffer(input.bytes)&&!(input.bytes instanceof Uint8Array))fail('Expected map archive bytes.');
    const bytes=Buffer.from(input.bytes);if(bytes.length>limits.archiveBytes)fail('Map archive exceeds16MiB.',413);
    if(!/^[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}$/i.test(input.requestId||''))fail('A publication request ID is required.');
    const sourceHash=digest(bytes),replayed=state.maps.find(r=>r.requestId===input.requestId);
    if(replayed){if(replayed.sourceHash!==sourceHash||replayed.publisher!==(player.account??player.id))fail('Publication request ID was reused for another draft.',409);return {ok:true,replayed:true,entry:api.entry(replayed.index),revision:state.revision};}
    if(!Number.isSafeInteger(input.expectedRevision)||input.expectedRevision!==state.revision)fail('The server map library changed. Refresh it before publishing.',409);
    if(input.editingIndex!=null&&(!Number.isInteger(input.editingIndex)||!maps.has(input.editingIndex)))fail('Choose an existing server map to update.');
    const index=input.editingIndex??Math.max(CUSTOM_BASE,...state.maps.map(r=>r.index))+1;if(!isCustomIndex(index))fail('Custom map indices are exhausted.');
    if(input.editingIndex==null&&state.maps.length>=limits.maps)fail('The server map library is full.');
    let files;try{files=unpackDkmap(bytes);if(!files)fail('Invalid .dkmap archive.');validateMapFiles(files);}catch(error){if(!error.status)error.status=400;throw error;}
    const doc=MapDoc.fromFiles(files),old=state.maps.find(r=>r.index===index),clientIndex=doc.meta.index;
    doc.meta={...doc.meta,id:`server-map-${index}`,index,created:old?.created||now(),modified:Math.max(now(),(old?.modified||0)+1)};
    for(const portal of doc.meta.portals){if(portal.to.custom)fail('Server portals must reference map indices, not local draft IDs.');if(clientIndex!=null&&portal.to.map===clientIndex)portal.to.map=index;}
    for(const npc of doc.meta.npcs)if(npc.jobs==null)delete npc.jobs;
    const canonical=doc.toFiles(),map=mapState(canonical,index,(old?.revision||0)+1);
    // Resolve authoritative table references, never accept a fake NPC or monster.
    for(const s of canonical.meta.spawns){if(!data?.monsterDef?.(s.monsterIndex))fail(`Unknown monster ${s.monsterIndex}.`);if(!map.isWalkable(s.x,s.z))fail('Monster spawns must be on walkable terrain.');}
    for(const n of canonical.meta.npcs){const npc=data?.progression?.npcs?.npcs?.[n.npcIndex];if(!npc)fail(`Unknown NPC ${n.npcIndex}.`);if(!map.isWalkable(n.x,n.z))fail('NPC placements must be on walkable terrain.');if(n.jobs?.some(([type,index])=>!npc.jobs?.some(([t,i])=>Number(t)===type&&Number(i)===index)))fail('Server NPCs support their original jobs only. Remove unsupported job overrides before publication.');}
    for(const p of canonical.meta.portals){const target=p.to.map===index?map:api.map(p.to.map)||await data.map(p.to.map);if(!target?.isWalkable(p.to.x,p.to.z))fail('Portal destination must be a walkable point on a supported map.');}
    const published=Buffer.from(packDkmap(canonical)),hash=digest(published);if(published.length>limits.archiveBytes)fail('Canonical map archive exceeds16MiB.',413);
    deploying.add(index);
    try{
     // Entry and commands are held by the API publication barrier. The explicit
     // live-world hook freezes tick; without it occupied updates still refuse.
     const live=await prepareCustomMapUpdate(world,index,map,(canonical.meta.spawns||[]).map(s=>({...copy(s),id:`${index}:custom:${s.id}`})));
     await ordinary(root);await fs.mkdir(root,{recursive:true});let diskBytes=0;
     for(const e of await fs.readdir(root,{withFileTypes:true})){if(e.name==='catalog.json'||e.name.endsWith('.tmp'))continue;if(!e.isFile()||!/^[a-f0-9]{64}\.dkmap$/.test(e.name))fail('Unexpected entry in the server map library.');diskBytes+=(await fs.stat(await ordinary(path.join(root,e.name)))).size;}
     const target=path.join(root,`${hash}.dkmap`);let exists=false;try{const stored=await fs.readFile(await ordinary(target));if(digest(stored)!==hash)fail('Existing archive digest mismatch.');exists=true;}catch(error){if(error.code!=='ENOENT')throw error;}
     if(diskBytes+(exists?0:published.length)>limits.libraryBytes)fail('Server map archives exceed the disk quota.');
     if(!exists)await writeAtomic(target,published);
     const row={index,digest:hash,bytes:published.length,width:map.width,height:map.height,revision:map.customRevision,created:doc.meta.created,modified:doc.meta.modified,requestId:input.requestId,sourceHash,publisher:player.account??player.id};
     const next={...state,revision:state.revision+1,maps:state.maps.filter(r=>r.index!==index).concat(row)};
     const entry=entryOf(row,canonical);
     if(world.lease(player.account??player.id,input.token)!==player)fail('The world session changed before publication.',409);
     if(!player.capabilities?.includes('gm:commands'))fail('GM publication permission was revoked.',403);
     await writeAtomic(manifest,JSON.stringify(next));
     // No relocated profile is saved ahead of the manifest. A crash immediately
     // after rename is recovered by the custom-map safe-spawn check on rejoin.
     state=next;records.set(index,canonical);maps.set(index,map);entries.set(index,entry);indexNpcLocations();
     if(live)live.commit();else for(const [key,scene]of world.maps||[])if(Number(scene.index)===index)world.maps.delete(key);
     world.sequence++;world.emit?.(null,{type:'mapbuilder:published',index,revision:api.revision,mapRevision:row.revision});
     return {ok:true,entry:api.entry(index),revision:api.revision,live:!!live?.occupants,relocated:live?.relocated||0,message:`Published server map #${index} at revision ${row.revision}.`};
    }finally{deploying.delete(index);}
   });queue=task;return task;
  },
 };
 return api;
}
