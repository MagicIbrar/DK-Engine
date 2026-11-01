import {types} from 'node:util';
// Private transaction-owned native JSON fragments, published only after durable save.
export function createNpcRecordCache(){
 const stringify=JSON.stringify;let committed=new Map();
 const safe=()=>JSON.stringify===stringify&&Object.getPrototypeOf(Object.prototype)===null&&Object.getPrototypeOf(Array.prototype)===Object.prototype&&!('toJSON' in Object.prototype)&&!('toJSON' in Array.prototype);
 function plain(value){
  const pending=[{value,exit:false}],ancestors=new Set();let steps=0;
  while(pending.length){if(++steps>32768)return false;const frame=pending.pop(),item=frame.value;
   if(frame.exit){ancestors.delete(item);continue;}
   if(item===null||item===undefined||typeof item==='string'||typeof item==='boolean'||typeof item==='number'&&Number.isFinite(item))continue;
   if(typeof item!=='object'||types.isProxy(item)||ancestors.has(item))return false;
   const array=Array.isArray(item),prototype=Object.getPrototypeOf(item);
   if(prototype!==(array?Array.prototype:Object.prototype)&&!(prototype===null&&!array)||Object.getOwnPropertySymbols(item).length||Object.hasOwn(item,'toJSON'))return false;
   const keys=array?null:Object.keys(item),length=array?item.length:keys.length;if(!Number.isSafeInteger(length)||length>32768-steps)return false;
   ancestors.add(item);pending.push({value:item,exit:true});
   for(let n=0;n<length;n++){const descriptor=Object.getOwnPropertyDescriptor(item,array?String(n):keys[n]);if(!descriptor||!Object.hasOwn(descriptor,'value'))return false;pending.push({value:descriptor.value,exit:false});}
  }return true;
 }
 return {prepare(next,{reuse=false,touched=new Set()}={}){
  const entries=new Map(),records=next.npcProfiles;let chars=0;
  return {lookup(key,record){
   if(!safe()||!records||typeof records!=='object'||Array.isArray(records)||types.isProxy(records))return null;
   const descriptor=Object.getOwnPropertyDescriptor(records,key);if(!descriptor||!Object.hasOwn(descriptor,'value')||descriptor.value!==record)return null;
   let entry=entries.get(key);if(entry)return entry.record===record?entry.fragment:null;
   if(entries.size>=2500)return null;
   const prior=reuse&&!touched.has(key)?committed.get(key):null;
   if(prior&&prior.record===record)entry=prior;
   else{if(!plain(record))return null;const wrapper=Object.create(null);wrapper[key]=record;const text=stringify(wrapper);if(text==='{}')return null;entry={record,fragment:text.slice(1,-1)};}
   if(entry.fragment.length>256*1024||chars+entry.fragment.length>32*1024*1024)return null;
   chars+=entry.fragment.length;entries.set(key,entry);return entry.fragment;
  },commit(){committed=safe()?entries:new Map();}};
 }};
}
