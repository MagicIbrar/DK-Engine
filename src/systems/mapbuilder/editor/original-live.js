import {randomUUID} from '../../network/web-crypto.js';
import {MapDoc} from '../format.js';
import {mapDataPaths} from '../../../formats/spawn.js';
import {fetchBuffer,tryFetchBuffer} from '../../../engine/assets.js';
import {ORIGINAL_EDIT_FIELDS as FIELDS,ORIGINAL_EDIT_LIMITS as LIMITS,applyOriginalChanges} from '../original-overlay.js';
import {placeCurrentFieldView} from './current-field-view.js';
// Queues actual scalar results of existing Brushes, including Undo/Redo. No new
// falloff/noise/coordinate rules. Failed batches retain the SAME request ID.
export async function beginOriginalLive(editor,api,status=()=>{}){
 const pose=api.entryView(),details=api.entryDetails(),index=pose.index,paths=mapDataPaths(editor.game.data.mapByIndex(index));
 let state=await api.begin(index),closed=false,busy=false,failed=null,timer=null,inflight=null;
 let map,mac,mol;try{[map,mac,mol]=await Promise.all([fetchBuffer(paths.map),fetchBuffer(paths.mac),tryFetchBuffer(paths.mol).catch(()=>null)]);}catch(error){await api.finish({session:state.session,epoch:state.epoch,expectedVersion:state.version,save:false}).catch(()=>{});throw error;}
 if(await api.sourceHash(map,mac)!==state.sourceHash){await api.finish({session:state.session,epoch:state.epoch,expectedVersion:state.version,save:false});throw Error('The original field files do not match this server.');}
 const doc=MapDoc.fromFiles({map,mac,mol});applyOriginalChanges(doc,state.changes);doc.meta.name=`Original field #${index} (shared brush session)`;
 doc.meta.spawns=details.spawns.map((row,i)=>({...row,id:`original-spawn-${i}`}));doc.meta.npcs=details.npcs.map((row,i)=>({...row,id:`original-npc-${i}`}));if(details.start)doc.meta.start={...details.start};for(const [key,value]of Object.entries(details.env))if(value)doc.meta.env[key]=value;
 editor.doc=doc;editor.currentId=null;try{await editor._buildAll();editor.toolOpts.defName=doc.waterDefs[0];placeCurrentFieldView(editor,pose);}catch(error){await api.finish({session:state.session,epoch:state.epoch,expectedVersion:state.version,save:false}).catch(()=>{});throw error;}
 const observed=Object.fromEntries(FIELDS.map(field=>[field,doc[field].slice()])),pending=new Map();
 const allowedTools=state.scope?['raise','lower','smooth','flatten','noise']:['raise','lower','smooth','flatten','noise','vcolor','type','variant','hole','water','collision'];
 const protectedVertices=new Set();for(const [start,count]of state.scope?.protectedRuns||[])for(let i=start;i<start+count;i++)protectedVertices.add(i);
 let protectedNoticeAt=0;
 function capture(event={}){const fields=new Set(event.fields||FIELDS);if(fields.has('water')){fields.add('waterDef');fields.add('waterH');}for(const field of FIELDS){if(!fields.has(field))continue;const values=doc[field],old=observed[field],vertex=['heights','colors','vertexTypes'].includes(field),width=doc.width+(vertex?1:0),height=doc.height+(vertex?1:0),stride=field==='colors'?4:1,rect=event.rect||{x0:0,z0:0,x1:width-1,z1:height-1};for(let z=Math.max(0,Math.floor(rect.z0));z<=Math.min(height-1,Math.ceil(rect.z1));z++)for(let x=Math.max(0,Math.floor(rect.x0));x<=Math.min(width-1,Math.ceil(rect.x1));x++)for(let c=0;c<stride;c++){const i=(z*width+x)*stride+c;if(values[i]!==old[i]){old[i]=values[i];pending.set(`${field}:${i}`,[field,i,values[i]]);}}}if(pending.size+state.changes.length>LIMITS.total){failed=Error('Shared overlay reached its scalar bound. Cancel the session to discard pending edits.');status(failed.message);}}
 async function flush(){
  if(closed||busy||failed)return;if(!inflight&&!pending.size)return;
  busy=true;
  try{
   if(!inflight){const changes=[...pending.values()].slice(0,LIMITS.batch);inflight={session:state.session,epoch:state.epoch,expectedVersion:state.version,requestId:randomUUID(),changes};for(const row of changes)pending.delete(`${row[0]}:${row[1]}`);}
   state=await api.patch(inflight);inflight=null;status(`Original #${index} · unsaved shared revision ${state.version} · ${pending.size} queued scalars`);
  }catch(error){status(error.message);if(error.status!==409&&error.status!==429&&error.status!=null){failed=error;}}
  finally{busy=false;}
 }
 const off=editor.on('brush:changed',capture);
 timer=setInterval(()=>void flush(),LIMITS.interval);
 const live={
  allowedTools,
  allowsWrite(field,index){const allowed=!state.scope||(field==='heights'&&!protectedVertices.has(index));if(!allowed&&Date.now()-protectedNoticeAt>1000){protectedNoticeAt=Date.now();status(state.scope.reason);}return allowed;},
  get active(){return !closed;},get failed(){return failed;},
  async finish(save){
   editor.cancelInput();capture();if(save){if(failed)throw failed;await flush();if(busy||inflight||pending.size)throw Error('Wait for queued shared brush changes and all client loads before saving.');}if(busy)throw Error('Wait for the current shared request before finishing.');
   let result;
   try{result=await api.finish({session:state.session,epoch:state.epoch,expectedVersion:state.version,save:!!save});}
   catch(error){
    if(save||error.status!==409)throw error;
    // Idle expiry already cancels on the server. Release Return only after a
    // fresh read confirms that exact source has a newer saved generation.
    const restored=await api.read(index);
    if(restored.index!==index||restored.epoch!==state.epoch||restored.sourceHash!==state.sourceHash||restored.phase!=='saved'||restored.session!==null||!Number.isInteger(restored.version)||restored.version<=state.version||typeof restored.generation!=='string'||!restored.generation||restored.generation===state.generation)throw error;
    result=restored;
   }
   closed=true;clearInterval(timer);off();editor.originalLive=null;editor.dirty=false;status(`Original #${index} · ${save?'saved private overlay':'cancelled; saved field restored'}`);return result;
  },
  dispose(){closed=true;clearInterval(timer);off();editor.originalLive=null;},
 };
 editor.originalLive=live;status(`Original #${index} · shared brush session · ${state.scope?'play resumes after each loaded brush generation':'gameplay paused in this field'}${state.scope?' · '+state.scope.reason:''}`);return live;
}
