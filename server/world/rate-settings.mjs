import fs from 'node:fs/promises';
import path from 'node:path';
import {writeAtomicStore} from '../accounts/atomic-store.mjs';
import {readWorldRates,readEffectiveRates} from './rates.mjs';

const KINDS=['exp','dil','drop'];
async function ordinary(file){
 if(!path.isAbsolute(file)||file.includes('\0'))throw Error('Invalid server rate settings path.');
 let current=path.parse(file).root;
 const parts=path.relative(current,file).split(path.sep);
 for(let i=0;i<parts.length;i++){
  if(process.platform==='win32'&&/[:\x00-\x1f]/.test(parts[i]))throw Error('Invalid server rate settings path.');
  current=path.join(current,parts[i]);
  const stat=await fs.lstat(current).catch(e=>{if(e.code==='ENOENT')return null;throw e;});
  if(stat&&(stat.isSymbolicLink()||(i<parts.length-1?!stat.isDirectory():!stat.isFile()||stat.nlink>1)))throw Error('Server rate settings require unlinked ordinary paths.');
 }
}
function baseRates(value){
 if(!value||Object.keys(value).length!==3||KINDS.some(k=>!Object.hasOwn(value,k)))throw Error('Set EXP, DIL and drop base rates together.');
 return readWorldRates(Object.fromEntries(KINDS.map(k=>['DEKARON_'+k.toUpperCase()+'_RATE',value[k]])));
}
function eventValue(value){
 if(!value||typeof value!=='object'||Array.isArray(value)||Object.keys(value).some(k=>!['multiplier','expiresAt'].includes(k))||!Number.isFinite(value.multiplier)||value.multiplier<=0||value.multiplier>1000||!(value.expiresAt===null||Number.isSafeInteger(value.expiresAt)&&value.expiresAt>=0))throw Error('Invalid saved rate event.');
 return {multiplier:value.multiplier,expiresAt:value.expiresAt};
}
export async function createRateSettings({file,defaults=readWorldRates(),now=Date.now,write=writeAtomicStore}={}){
 if(typeof file!=='string')throw Error('Server rate settings require a file.');
 file=path.resolve(file);await ordinary(file);defaults=baseRates(defaults);let value={version:1,base:null,events:{}};
 try{
  if((await fs.stat(file)).size>8192)throw Error('Server rate settings file is too large.');
  const saved=JSON.parse(await fs.readFile(file,'utf8'));
  if(saved.version!==1||Object.keys(saved).some(k=>!['version','base','events'].includes(k))||!saved.events||Array.isArray(saved.events)||Object.keys(saved.events).some(k=>!KINDS.includes(k)))throw Error('Invalid saved server rates.');
  value={version:1,base:saved.base===null?null:{...baseRates(saved.base)},events:Object.fromEntries(Object.entries(saved.events).map(([k,v])=>[k,eventValue(v)]))};
 }catch(e){if(e.code!=='ENOENT')throw e;}
 let queue=Promise.resolve();
 const current=()=>readEffectiveRates(Object.fromEntries(KINDS.map(k=>{const event=value.events[k];return [k,(value.base||defaults)[k]*(event&&(event.expiresAt===null||event.expiresAt>now())?event.multiplier:1)];})));
 const update=change=>{
  const task=queue.then(async()=>{const next=structuredClone(value);change(next);await ordinary(file);await write(file,next);value=next;return current();});
  queue=task.catch(()=>{});return task;
 };
 return {current,read:()=>({base:{...(value.base||defaults)},effective:{...current()},events:structuredClone(value.events)}),
  setBase:rates=>{const valid=baseRates(rates);return update(next=>{next.base={...valid};});},
  setEvent(kind,multiplier,minutes=0){
   if(!KINDS.includes(kind)||!Number.isFinite(multiplier)||multiplier<0||multiplier>1000||!Number.isSafeInteger(minutes)||minutes<0||minutes>525600)throw Error('Use a multiplier from 0 to 1000 and 0 to 525600 whole minutes. 0 or 1 ends the event.');
   const expiresAt=minutes?now()+minutes*60000:null;
   if(expiresAt!==null&&!Number.isSafeInteger(expiresAt))throw Error('Invalid rate event expiry.');
   return update(next=>{if(multiplier===0||multiplier===1)delete next.events[kind];else next.events[kind]={multiplier,expiresAt};});
  }
 };
}
