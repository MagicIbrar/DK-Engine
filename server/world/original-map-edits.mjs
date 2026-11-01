import {fishingBusy} from './fishing.mjs';
import {randomUUID,createHash} from 'node:crypto';
import fs from 'node:fs/promises';
import path from 'node:path';
import {MapDoc,writeMac} from '../../src/systems/mapbuilder/format.js';
import {Collision} from '../../src/world/collision.js';
import {PathFinder} from '../../src/world/pathfind.js';
import {validateScopedChanges} from './original-map-scope.mjs';
import {ORIGINAL_EDIT_LIMITS as LIMITS,mergeOriginalChanges,originalPatchEntries,applyOriginalChanges,validateOriginalOverlay} from '../../src/systems/mapbuilder/original-overlay.js';
const fail=(message,status=409)=>{throw Object.assign(Error(message),{status,code:'ORIGINAL_MAP_EDIT'});};
const digest=files=>createHash('sha256').update(new Uint8Array(files.map)).update(new Uint8Array(files.mac)).digest('hex');
const occupants=(world,index)=>[...world.players.values()].filter(p=>Number(p.map)===index&&!p.instanceId&&!p.leaving);
function safePoint(map,actor){if(map.isWalkable(actor.x,actor.z))return {x:actor.x,z:actor.z};const at=map.nearest(actor.x,actor.z);if(!at||!map.isWalkable(at.x,at.z))fail('An actor has no safe cell within the existing 32-cell relocation policy.');return {x:at.x,z:at.z};}
function collisionFor(doc){const collision=Collision.fromBuffer(writeMac(doc.width,doc.height,doc.attrs));for(let i=0;i<doc.C;i++)if(doc.holes[i]&&!collision.cells[i]){collision.cells[i]=1;collision.walkableCount--;}const finder=new PathFinder(collision,{maxNodes:20000,snapRadius:8});return {collision,isWalkable:(x,z)=>collision.isWalkable(x,z),nearest:(x,z)=>collision.nearestWalkable(x,z,32),path:(x,z,tx,tz)=>finder.findPath(x,z,tx,tz)};}

// Explicit private sidecar root. Never writes the original .map/.mac/.mol.
export function originalOverlayStore(root){
 if(!root||!path.isAbsolute(root))throw Error('An explicit absolute original-overlay root is required.');
 const filename=index=>{if(!Number.isInteger(index)||index<0||index>=90000)fail('Invalid original index.',400);return path.join(root,`${index}.json`);};
 return {
  async load(index){try{const file=filename(index);if((await fs.stat(file)).size>8*1024*1024)fail('Original overlay sidecar exceeds 8 MiB.',413);return JSON.parse(await fs.readFile(file,'utf8'));}catch(error){if(error.code==='ENOENT')return null;throw error;}},
  async save(index,value,authorize){await fs.mkdir(root,{recursive:true});const target=filename(index),temp=`${target}.${randomUUID()}.tmp`;try{await fs.writeFile(temp,JSON.stringify(value),{flag:'wx',mode:0o600});await authorize();await fs.rename(temp,target);}finally{await fs.unlink(temp).catch(error=>{if(error.code!=='ENOENT')throw error;});}},
 };
}

/** Caller serializes every mutation with the existing world command barrier.
 * Default allowlist empty. Eligibility is an explicit engine deployment policy,
 * not inferred from an original map name. Native actors/tables remain intact. */
export function createOriginalMapEdits(world,{allowedMaps=[],readOriginal,store,now=()=>world.now()}={}){
 if(typeof readOriginal!=='function'||!store)throw Error('Original editing requires a source reader and private sidecar store.');
 const allowed=new Set(allowedMaps),loaded=new Map(),epoch=randomUUID();let active=null,locked=false;const finished=new Map();
 async function base(index){
  if(!allowed.has(index)||!Number.isInteger(index)||index<0||index>=90000||world.data.requiresInstance?.(index)||world.data.customMaps?.has?.(index))fail('This original field is not approved for live editing.',403);
  if(!loaded.has(index))loaded.set(index,(async()=>{const files=await readOriginal(index);if(!files?.map||!files.mac)fail('Original terrain and collision bytes are required.',503);const source=MapDoc.fromFiles(files),sourceHash=digest(files);if(!source.width||source.width>512||!source.height||source.height>512)fail('Unsupported original terrain dimensions.',400);const initialCollision=Collision.fromBuffer(files.mac);if(!initialCollision.hasData||initialCollision.width!==source.width||initialCollision.height!==source.height)fail('Original terrain/collision dimensions disagree.',400);const saved=await store.load(index);if(saved&&(saved.format!=='dekaron-original-overlay@1'||saved.index!==index||saved.sourceHash!==sourceHash))fail('The original client changed or the sidecar is invalid. Review it before editing.',409);const patch=validateOriginalOverlay(source,saved?.changes||[]);validateScopedChanges(files.scope,source,originalPatchEntries(patch),{batch:false});return {index,files,source,sourceHash,patch,version:0,phase:'saved',generation:randomUUID()};})().catch(error=>{loaded.delete(index);throw error;}));return loaded.get(index);
 }
 // Ordinary entry/scene loading. The live-edit eligibility audit (exact audited source scope,
 // e.g. server/world/original-map-scope.mjs for Ardeca) is GM-only: when it fails and no committed
 // overlay sidecar exists there is nothing to apply, so players get the unmodified original map
 // and begin() keeps refusing with the original reason. A committed sidecar keeps the strict
 // review policy (its source must still validate).
 const unavailable=new Map();
 async function entryRow(index){
  try{const row=await base(index);unavailable.delete(index);return row;}
  catch(error){
   if(!allowed.has(index)||await store.load(index))throw error;
   const reason=String(error?.message||error).slice(0,200);
   if(unavailable.get(index)!==reason){unavailable.set(index,reason);console.warn(`[original-map-edits] Live height editing of original map ${index} is unavailable for this client data (${reason}). Players enter the unmodified original map.`);}
   return null;
  }
 }
 function document(row,patch=row.patch){const doc=MapDoc.fromFiles(row.files);applyOriginalChanges(doc,originalPatchEntries(patch));return doc;}
 function view(row){return {epoch,index:row.index,version:row.version,generation:row.generation,phase:row.phase,sourceHash:row.sourceHash,scope:row.files.scope||null,session:active?.row===row?active.id:null,changes:originalPatchEntries(active?.row===row?active.patch:row.patch)};}
 function notice(row,p){p.originalEditPending={epoch,index:row.index,version:row.version,generation:row.generation,phase:row.phase,heightOnly:!!row.files.scope,deadline:now()+LIMITS.ready};p.sceneTransition=true;if(!row.files.scope)p.path=[];}
 function notify(row){for(const p of occupants(world,row.index))notice(row,p);}
 function changed(row,phase){row.version++;row.phase=phase;row.generation=randomUUID();notify(row);}
 function busy(index){const scene=world.maps.get(index);if([...world.maps.values()].some(m=>Number(m.index)===index&&(m.instanceId||m.channel)))fail('An instance of this original map is active.');for(const p of occupants(world,index)){const s=p._skills;if(p.sceneTransition||p.progressCommitting||p.tradeCommitting||p.commandActive>1||p.tradeId||fishingBusy(p)||p.smartWarp||p.pet||p.mount||s?.engine?.casting||s?.engine?.active||s?.engine?.queued||s?.engine?.remotes?.list?.length||s?.summons?.all?.().length||s?.summons?.totems?.length||s?.summons?._respawn?.length)fail('Finish active player services before original-map editing.');}for(const m of scene?.monsters.values()||[])if(m.isBrick||m.eventMarch||m.boxOwner)fail('A scripted actor prevents original-map editing.');}
 async function authority(account,token,authorize){const user=await authorize();if(user?.id!==account||!user.capabilities?.includes('gm:commands'))fail('Fresh GM authority is required.',403);const p=world.lease(account,token);if(p.leaving||p.revoked||p.instanceId)fail('The publisher lease is unavailable.',403);return p;}
 function checkSession(account,token,input){const s=active;if(!s||s.owner!==account||s.token!==token||input.session!==s.id||input.epoch!==epoch||input.expectedVersion!==s.row.version)fail('The original edit session or revision changed.');if(Number(world.players.get(account)?.map)!==s.row.index)fail('The original editor owner left this field.');if(now()>=s.expires)fail('The original edit session expired.');return s;}
 function planned(row,patch){const doc=document(row,patch),map=collisionFor(doc),scene=world.maps.get(row.index),players=occupants(world,row.index).map(p=>({p,at:safePoint(map,p)})),monsters=[...(scene?.monsters.values()||[])].map(m=>({m,at:safePoint(map,m),home:safePoint(map,m.home||m)})),drops=[...(world.groundLoot?.values()||[])].filter(d=>Number(d.map)===row.index&&!d.instanceId).map(d=>({d,at:safePoint(map,d)}));return {map,scene,players,monsters,drops};}
 function commitScene(row,plan){if(plan.scene)Object.assign(plan.scene,plan.map);for(const {p,at}of plan.players){p.x=at.x;p.z=at.z;p.dirty=true;p.revision++;}for(const {m,at,home}of plan.monsters){m.x=at.x;m.z=at.z;m.home=home;m.anchor=null;m.targetId=null;}for(const {d,at}of plan.drops){d.x=at.x;d.z=at.z;}}
 const api={
  epoch,get isCommitting(){return locked;},allowedMaps:[...allowed],isFrozen:index=>(active?.row.index===Number(index)&&!active.row.files.scope)||occupants(world,Number(index)).some(p=>!!p.originalEditPending),
  async read(index){index=Number(index);const row=await entryRow(index);return row?view(row):{epoch,index,version:0,generation:null,phase:'unavailable',sourceHash:null,scope:null,session:null,changes:[],unavailable:unavailable.get(index)||null};},
  async committed(index){if(!allowed.has(Number(index)))return null;const row=await entryRow(Number(index));if(!row)return null;return {...view(row),phase:'saved',session:null,changes:originalPatchEntries(row.patch)};},
  async onJoin(p){if(allowed.has(Number(p.map))){const row=await entryRow(Number(p.map));if(row&&(row.patch.size||active?.row===row))notice(row,p);}},
  async map(index,map){if(!allowed.has(Number(index)))return map;const row=await entryRow(Number(index));return row?{...map,...collisionFor(document(row))}:map;},
  async begin(account,token,input,authorize){if(locked)fail('An original map mutation is committing.');locked=true;try{const p=await authority(account,token,authorize);if(active)fail('Another original edit session is active.');if(Number(p.map)!==input.index)fail('Enter the original field before editing.');const row=await base(input.index);await authority(account,token,authorize);if(active||input.epoch!==epoch||input.expectedVersion!==row.version)fail('The original map revision changed.');busy(row.index);await world.saveQueue;await authority(account,token,authorize);busy(row.index);active={id:randomUUID(),owner:account,token,row,patch:new Map(row.patch),expires:now()+LIMITS.idle,lastBatch:-Infinity,receipts:new Map()};changed(row,'editing');return view(row);}finally{locked=false;}},
  async patch(account,token,input,authorize){await authority(account,token,authorize);const s=active;if(!s||s.owner!==account||s.token!==token||input.session!==s.id||input.epoch!==epoch)fail('The edit session changed.');if(!/^[a-zA-Z0-9_-]{1,100}$/.test(input.requestId||''))fail('A bounded brush request ID is required.',400);const hash=createHash('sha256').update(JSON.stringify(input)).digest('hex'),receipt=s.receipts.get(input.requestId);if(receipt){if(receipt.hash!==hash)fail('Brush request ID was reused with different content.');return structuredClone(receipt.result);}checkSession(account,token,input);if(occupants(world,s.row.index).some(p=>p.originalEditReady?.generation!==s.row.generation))fail('Wait for all current clients to load the previous brush generation.');if(now()-s.lastBatch<LIMITS.interval)fail('Brush batches must be at least 200 ms apart.',429);const next=mergeOriginalChanges(s.row.source,s.patch,input.changes);validateScopedChanges(s.row.files.scope,s.row.source,input.changes);if(!s.row.files.scope)planned(s.row,next);s.patch=next;s.lastBatch=now();s.expires=now()+LIMITS.idle;changed(s.row,'editing');const result=view(s.row);s.receipts.set(input.requestId,{hash,result});while(s.receipts.size>32)s.receipts.delete(s.receipts.keys().next().value);return result;},
  async finish(account,token,input,authorize){if(locked)fail('An original map mutation is committing.');locked=true;try{await authority(account,token,authorize);const hash=createHash('sha256').update(JSON.stringify(input)).digest('hex'),receipt=finished.get(input.session);if(receipt){if(receipt.owner!==account||receipt.token!==token||receipt.hash!==hash)fail('Finished session was replayed with different content or authority.');return structuredClone(receipt.result);}const s=checkSession(account,token,input),row=s.row,plan=row.files.scope?null:planned(row,s.patch);if(input.save!==true&&input.save!==false)fail('Choose save or cancel.',400);if(input.save){await store.save(row.index,{format:'dekaron-original-overlay@1',index:row.index,sourceHash:row.sourceHash,changes:originalPatchEntries(s.patch)},async()=>{await authority(account,token,authorize);checkSession(account,token,input);});row.patch=s.patch;if(plan)commitScene(row,plan);}active=null;changed(row,'saved');const result=view(row);finished.set(input.session,{owner:account,token,hash,result});while(finished.size>32)finished.delete(finished.keys().next().value);return result;}finally{locked=false;}},
  ready(account,token,input){const p=world.lease(account,token),pending=p.originalEditPending;if(!pending||Number(p.map)!==input.index||input.epoch!==epoch||pending.version!==input.version||pending.generation!==input.generation||pending.index!==input.index||now()>=pending.deadline)fail('The loaded original edit generation changed.');p.originalEditReady={...pending};if(pending.phase!=='editing'||pending.heightOnly){p.originalEditPending=null;p.sceneTransition=false;}return {ok:true};},
  // Called before normal tick. Preview has no durable effect; rollback requires
  // clients to load the saved geometry before gameplay resumes. Deadline stays
  // absolute for a pending generation; polling/duplicate ready cannot extend it.
  tick(){if(locked)return;if(active){const owner=world.players.get(active.owner);if(now()>=active.expires||!owner||Number(owner.map)!==active.row.index||owner.leaving||owner.revoked||owner.token!==active.token||!owner.gmAuthorized){const row=active.row;active=null;changed(row,'saved');}}for(const p of world.players.values())if(p.originalEditPending&&!(p.originalEditPending.phase==='editing'&&p.originalEditReady?.generation===p.originalEditPending.generation)&&now()>=p.originalEditPending.deadline){p.originalEditPending=null;p.sceneTransition=false;p.revoked=true;p.leaving=true;p.lastSave=now()-5000;}},
  get active(){return active?{index:active.row.index,owner:active.owner,session:active.id}:null;},
 };
 return api;
}
