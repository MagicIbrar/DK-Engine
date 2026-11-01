import fs from 'node:fs/promises';
import {cursorOwnedItems} from './item-ownership.mjs';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {randomUUID} from 'node:crypto';
import {applyItem,nextIndex,isCustomIndex,DRAFT_INDEX,FORMAT} from '../../src/systems/itembuilder/registry.js';
import {validateCustomItem as validate} from './custom-item-schema.mjs';
import {gmItemIntent} from './gm-items.mjs';
import {dispatchItemAction} from './items.mjs';
const DEFAULT_FILE=fileURLToPath(new URL('../custom-items.json',import.meta.url));
const fail=message=>{throw Object.assign(new Error(message),{status:400});};
async function unlinked(file){let current=path.resolve(file);for(;;){try{const stat=await fs.lstat(current);if(stat.isSymbolicLink()||current===path.resolve(file)&&stat.isFile()&&stat.nlink>1)fail('Custom library refuses linked paths.');}catch(error){if(error.code!=='ENOENT')throw error;}const parent=path.dirname(current);if(parent===current)break;current=parent;}}
export async function loadCustomItems(db,{file=process.env.DEKARON_CUSTOM_ITEM_STORE||DEFAULT_FILE}={}){
 file=path.resolve(file);await unlinked(file);let state={format:FORMAT,version:1,revision:0,items:[]};try{state=JSON.parse(await fs.readFile(file,'utf8'));}catch(error){if(error.code!=='ENOENT')throw error;}
 if(!state||state.format!==FORMAT||state.version!==1||!Number.isSafeInteger(state.revision)||state.revision<0||!Array.isArray(state.items)||state.items.length>500)fail('Invalid custom item library; original file preserved.');
 const indices=new Set(),validated=[];
 for(const row of state.items){if(!row||!Number.isInteger(row.index)||!isCustomIndex(row.index)||row.index===DRAFT_INDEX||indices.has(row.index)||row.deleted!=null&&typeof row.deleted!=='boolean')fail('Invalid custom item index or archive flag.');indices.add(row.index);const raw={...row};delete raw.deleted;validated.push({...validate(raw,db),...(row.deleted?{deleted:true}:{})});}
 state.items=validated;for(const row of validated)applyItem(db,row);
 let queue=Promise.resolve();
 const api={get revision(){return Number(state.revision)||0;},list:()=>structuredClone(state.items),async run(world,p,input){const task=queue.catch(()=>{}).then(async()=>{
   if(world.lease(p.account??p.id,input.token)!==p)fail('The editor session changed. Reopen it before saving.');
   const allowed={customSave:['token','operation','record','editingIndex','expectedRevision'],customDelete:['token','operation','index','expectedRevision'],customSpawn:['token','operation','index','count','equip'],customImport:['token','operation','records','expectedRevision']};
   if(!Object.hasOwn(allowed,input.operation)||Object.keys(input).some(k=>!allowed[input.operation].includes(k)))fail('Invalid custom item operation.');
   if(input.expectedRevision!=null&&(!Number.isSafeInteger(input.expectedRevision)||input.expectedRevision!==api.revision))throw Object.assign(new Error('The server custom library changed. Review the current library before saving this draft.'),{status:409});
   if(input.operation==='customSpawn'){
    const record=state.items.find(r=>r.index===input.index&&!r.deleted);if(!record)fail('Choose a saved server custom item.');if(input.equip!=null&&typeof input.equip!=='boolean')fail('Invalid equip flag.');
    const old=new Set(p.profile.inventory.map(i=>i.uid));const result=await gmItemIntent(world,p,{token:input.token,operation:'makeItem',spec:{item:record.index,count:input.count??1,grade:record.grade,sockets:record.sockets,roll:record.roll,to:'bag'}});
    let equipped=false;const item=p.profile.inventory.find(i=>!old.has(i.uid));if(input.equip&&item){try{equipped=await dispatchItemAction(world,p,{type:'equip',uid:item.uid});}catch(error){result.message+=` Equipment unchanged: ${error.message}`;}}
    return {...result,state:world.snapshot(p),equipped,placed:item?[item]:[],inst:item||null};
   }
   const next=structuredClone(state),changed=[];let deleted=null;
   const save=(record,index)=>{const existing=index==null?null:next.items.find(r=>r.index===index&&!r.deleted);if(index!=null&&!existing)fail('The edited custom item no longer exists.');if(!record||typeof record!=='object'||Array.isArray(record))fail('Invalid custom item record.');const row=validate({...record,index:existing?.index??nextIndex(next)},db);
    if(existing){
     if(['w','h','type','code','stack','maxStack','autoStack'].some(key=>(row[key]??0)!==(existing[key]??0)))fail('Use Save As for a new kind, footprint or stack size; existing saved copies retain their structure.');
     if((row.classMask&existing.classMask)!==existing.classMask||['reqLv','reqStr','reqDex','reqSpr','reqGrade'].some(key=>(row[key]??0)>(existing[key]??0))||row.maxLv>0&&(!existing.maxLv||row.maxLv<existing.maxLv))fail('Use Save As for stricter equipment requirements; existing worn copies must remain valid.');
    }
    row.created=existing?.created||world.now();row.updated=world.now();const at=next.items.findIndex(r=>r.index===row.index);if(at<0)next.items.push(row);else next.items[at]=row;changed.push(row);};
   if(input.operation==='customSave')save(input.record,input.editingIndex??null);
   else if(input.operation==='customImport'){if(!Array.isArray(input.records)||input.records.length>100)fail('Import at most100 custom items at a time.');for(const row of input.records)save(row,null);}
   else{const row=next.items.find(r=>r.index===input.index&&!r.deleted);if(!row)fail('This custom item no longer exists.');if(cursorOwnedItems(p.profile).some(item=>item.itemIndex===row.index))fail('Place the held custom item before deleting it.');row.deleted=true;deleted=row.index;}
   if(next.items.length>500)fail('The server custom library is full.');next.revision=(Number(next.revision)||0)+1;
   await unlinked(file);await fs.mkdir(path.dirname(file),{recursive:true});const temporary=file+'.'+randomUUID()+'.tmp';let handle;try{handle=await fs.open(temporary,'wx',0o600);await handle.writeFile(JSON.stringify(next));await handle.sync();await handle.close();handle=null;await fs.rename(temporary,file);}finally{await handle?.close().catch(()=>{});await fs.rm(temporary,{force:true}).catch(()=>{});}state=next;
   for(const row of changed)applyItem(db,row);
   let removed=0;if(deleted){for(const name of ['inventory','storage','costumeBag','cashInv']){const list=p.profile[name]||[];removed+=list.filter(i=>i.itemIndex===deleted).length;p.profile[name]=list.filter(i=>i.itemIndex!==deleted);}for(const[uid,item]of Object.entries(p.profile.equip?.items||{}))if(item.itemIndex===deleted){removed++;delete p.profile.equip.items[uid];for(const preset of p.profile.equip.presets)for(const[slot,id]of Object.entries(preset))if(id===uid)delete preset[slot];}}
   for(const actor of world.players?.values?.()||[p]){actor.stats=world.data.stats(actor.profile,actor,world.now());actor.maxHp=actor.stats.maxHp;actor.hp=Math.min(actor.hp,actor.maxHp);world.changed(actor);}world.sequence++;world.emit(p.map,{type:'itembuilder:changed',actorId:p.id});
   // Definitions are committed independently of account saves. Report the committed archive explicitly if copy cleanup cannot persist.
   if(deleted){try{await world.persist(p);}catch(error){throw Object.assign(new Error(`Custom item archived at library revision ${api.revision}; character copy cleanup is pending because saving failed. ${error.message}`),{status:503});}}
   return {ok:true,record:changed[0]||null,records:changed,removed,library:api.list(),revision:api.revision,message:deleted?'Custom item removed from this character and archived for existing copies.':'Custom item library saved by the server.',state:world.snapshot(p)};
  });queue=task;return task;}};return api;
}
