import fs from 'node:fs/promises';
import path from 'node:path';
import {randomBytes} from 'node:crypto';
import {assertPrivateAccountDirectory} from './private-directory.mjs';
import {setImmediate as yieldTurn} from 'node:timers/promises';
import {types} from 'node:util';

// Aggregate-only diagnostic; retain no file, record, account or serialized value.
const writerDiagnostics=new Set();let writerActive=0,writerCompleted=0,writerFailed=0,writerLast=null;
const diagnosticAdd=(value,amount)=>Math.min(Number.MAX_SAFE_INTEGER,value+Math.max(0,amount));
function writerView(d){return {phase:d.phase,elapsedMs:Math.max(0,performance.now()-d.started),serializedChars:d.serializedChars,chunks:d.chunks,serializeMs:d.serializeMs,writeCalls:d.writeCalls,writeMs:d.writeMs,yieldMs:d.yieldMs,syncMs:d.syncMs};}
export function atomicStoreDiagnostic(){let current=null;for(const d of writerDiagnostics)if(!current||d.started<current.started)current=d;return {active:writerActive,tracked:writerDiagnostics.size,completed:writerCompleted,failed:writerFailed,current:current?writerView(current):null,lastCompleted:writerLast?{...writerLast}:null};}
function writerBegin(){const d={phase:'validation',started:performance.now(),serializedChars:0,chunks:0,serializeMs:0,writeCalls:0,writeMs:0,yieldMs:0,syncMs:0};writerActive++;if(writerDiagnostics.size<4)writerDiagnostics.add(d);return d;}
function writerEnd(d,ok){writerLast={...writerView(d),ok};writerActive--;writerDiagnostics.delete(d);if(ok)writerCompleted=diagnosticAdd(writerCompleted,1);else writerFailed=diagnosticAdd(writerFailed,1);}
async function writerWrite(handle,text,d,direct=false){
  d.phase='write';const started=performance.now();
  try{
    if(direct&&typeof handle.write==='function'){
      const buffer=Buffer.from(text,'utf8');let offset=0;
      while(offset<buffer.length){
        d.writeCalls=diagnosticAdd(d.writeCalls,1);
        const result=await handle.write(buffer,offset,buffer.length-offset,null),written=result?.bytesWritten;
        if(!Number.isSafeInteger(written)||written<=0||written>buffer.length-offset)throw Object.assign(new Error('Atomic account write made invalid progress.'),{code:'EIO'});
        offset+=written;
      }
    }else{d.writeCalls=diagnosticAdd(d.writeCalls,1);await handle.writeFile(text,'utf8');}
  }finally{d.writeMs=diagnosticAdd(d.writeMs,performance.now()-started);d.phase='serialize';}
}
// Windows scanners and indexers can briefly hold the destination directory
// during replacement. Keep the same fully synced temporary file and retry
// only that rename; a permanent denial still leaves the old store intact.
async function renameAtomicStore(io,temporary,file){
  for(let attempt=0;;attempt++)try{return await io.rename(temporary,file);}
  catch(error){
    if(process.platform!=='win32'||attempt>=3||!['EPERM','EACCES','EBUSY'].includes(error?.code))throw error;
    await new Promise(resolve=>setTimeout(resolve,50*2**attempt));
  }
}
// ENGINE-CHOSEN write pacing. Small stores keep the original native stringify.
const LARGE_RECORDS=128,STRING_SLICE=8192,CHUNK_CHARS=16384,SLICE_STEPS=512,SLICE_MS=4;
function largeStore(value){return value&&typeof value==='object'&&['users','sessions','npcProfiles'].reduce((n,key)=>{const entry=Object.getOwnPropertyDescriptor(value,key);return n+(entry&&Object.hasOwn(entry,'value')?Object.keys(entry.value||{}).length:0);},0)>=LARGE_RECORDS;}
const omitted=value=>value===undefined||typeof value==='function'||typeof value==='symbol';
function jsonValue(value,key){
  const kind=typeof value;
  if(value!==null&&(kind==='object'||kind==='function'||kind==='bigint')){const toJSON=value.toJSON;if(typeof toJSON==='function')value=toJSON.call(value,key);}
  // Native slot tests handle cross-realm and altered-prototype wrappers without
  // throwing four exceptions for each ordinary inventory/quest object.
  if(types.isBoxedPrimitive(value)){
    if(types.isNumberObject(value))return +value;
    if(types.isStringObject(value))return String(value);
    if(types.isBooleanObject(value))return Boolean.prototype.valueOf.call(value);
    if(types.isBigIntObject(value))return BigInt.prototype.valueOf.call(value);
  }
  return value;
}
function* stringFragments(value){
  yield '"';
  for(let at=0;at<value.length;){let end=Math.min(value.length,at+STRING_SLICE);
    // Native stringify escapes lone surrogates; never manufacture a lone half
    // by cutting an authored pair or encode separate UTF-8 replacement chars.
    if(end<value.length&&value.charCodeAt(end-1)>=0xd800&&value.charCodeAt(end-1)<=0xdbff&&value.charCodeAt(end)>=0xdc00&&value.charCodeAt(end)<=0xdfff)end--;
    yield JSON.stringify(value.slice(at,end)).slice(1,-1);at=end;
  }
  yield '"';
}
// Most saved records are small JSON-only objects. Native stringify is much
// faster than emitting every inventory property separately. Bound a read-only
// descriptor scan before using it; accessors, hooks, exotic objects, sparse
// arrays, cycles and large records stay on the incremental traversal below.
function boundedJsonRecord(value){
  const pending=[value],seen=new Set();let steps=0,chars=0;
  while(pending.length){if(++steps>1024||chars>CHUNK_CHARS)return false;const item=pending.pop();
    if(item===null){chars+=4;continue;}
    const kind=typeof item;
    if(kind==='string'){chars+=2+item.length*(/["\\\u0000-\u001f\ud800-\udfff]/.test(item)?6:1);continue;}
    if(kind==='number'){chars+=32;continue;}if(kind==='boolean'){chars+=5;continue;}
    if(kind!=='object'||types.isProxy(item)||seen.has(item))return false;seen.add(item);
    const array=Array.isArray(item),prototype=Object.getPrototypeOf(item);
    if(!array&&prototype!==Object.prototype&&prototype!==null)return false;
    if(Object.hasOwn(item,'toJSON')||Object.hasOwn(Object.prototype,'toJSON')||array&&Object.hasOwn(Array.prototype,'toJSON'))return false;
    const keys=array?null:Object.keys(item),length=array?item.length:keys.length;if(length>1024-steps)return false;chars+=2+length;
    for(let n=0;n<length;n++){const key=array?String(n):keys[n],descriptor=Object.getOwnPropertyDescriptor(item,key);if(!descriptor||!Object.hasOwn(descriptor,'value'))return false;
      if(!array)chars+=3+key.length*(/["\\\u0000-\u001f\ud800-\udfff]/.test(key)?6:1);pending.push(descriptor.value);
    }
  }
  return chars<=CHUNK_CHARS;
}
function* jsonFragments(value,accountNpcProfiles=false,recordFragment=null){
  const root=jsonValue(value,''),ancestors=new Set(),stack=[{kind:'value',value:root,root:true}];
  if(omitted(root))throw new TypeError('Account store must have a JSON value.');
  while(stack.length){const frame=stack.pop();
    if(frame.kind==='array'){
      if(frame.index===frame.length){ancestors.delete(frame.value);yield ']';continue;}
      const index=frame.index++;stack.push(frame);if(index)yield ',';
      const child=jsonValue(frame.value[index],String(index));stack.push({kind:'value',value:omitted(child)?null:child});continue;
    }
    if(frame.kind==='object'){
      // Account-only native record serialization; no cache/freeze or record scan.
      // Wrapper preserves each record's native toJSON key and omission semantics.
      // Replacer refuses outer ancestor references before native recursion.
      if(frame.npcProfiles){
        let fragment=null;
        while(frame.index<frame.keys.length){const key=frame.keys[frame.index++],record=frame.value[key],wrapper=Object.create(null);wrapper[key]=record;
          let cached=null;if(typeof recordFragment==='function')try{cached=recordFragment(key,record);}catch{}
          if(typeof cached==='string'){fragment=cached;break;}
          const text=JSON.stringify(wrapper,(_key,item)=>{if(ancestors.has(item))throw new TypeError('Converting circular structure to JSON');return item;});
          if(text!=='{}'){fragment=text.slice(1,-1);break;}
        }
        if(fragment===null){ancestors.delete(frame.value);yield '}';continue;}
        stack.push(frame);if(frame.written++)yield ',';yield fragment;continue;
      }
      let key,child,found=false;
      while(frame.index<frame.keys.length){key=frame.keys[frame.index++];child=jsonValue(frame.value[key],key);if(!omitted(child)){found=true;break;}yield '';}
      if(!found){ancestors.delete(frame.value);yield '}';continue;}
      stack.push(frame);if(frame.written++)yield ',';yield* stringFragments(key);yield ':';stack.push({kind:'value',value:child,npcProfiles:accountNpcProfiles&&frame.root&&key==='npcProfiles'});continue;
    }
    const item=frame.value;
    if(typeof item==='string'){yield* stringFragments(item);continue;}
    if(item===null||typeof item!=='object'){yield JSON.stringify(item);continue;}
    if(ancestors.has(item))throw new TypeError('Converting circular structure to JSON');ancestors.add(item);
    if(boundedJsonRecord(item)){ancestors.delete(item);yield JSON.stringify(item);continue;}
    if(Array.isArray(item)){yield '[';stack.push({kind:'array',value:item,index:0,length:item.length});}
    else{yield '{';stack.push({kind:'object',value:item,keys:Object.keys(item),index:0,written:0,root:frame.root,npcProfiles:frame.npcProfiles});}
  }
}
/** Exact native JSON ordering/escaping, with bounded traversal and string slices. */
export async function* serializeStoreChunks(value,diagnostic=null,accountNpcProfiles=false,recordFragment=null){
  if(accountNpcProfiles===true){
    // ENGINE-CHOSEN existing 4ms/512-step soft CPU budget, independent of chunk emission.
    // Consumer IO suspension is excluded; one native record remains non-preemptible.
    const iterator=jsonFragments(value,true,recordFragment);let chunks=[],chars=0,steps=0,cpuMs=0;
    const emit=()=>{const started=performance.now(),text=chunks.join('');const elapsed=performance.now()-started;cpuMs+=elapsed;if(diagnostic)diagnostic.serializeMs=diagnosticAdd(diagnostic.serializeMs,elapsed);chunks=[];chars=0;return text;};
    while(true){
      const started=performance.now(),next=iterator.next();
      if(!next.done){chunks.push(next.value);chars+=next.value.length;steps++;}
      const elapsed=performance.now()-started;cpuMs+=elapsed;if(diagnostic)diagnostic.serializeMs=diagnosticAdd(diagnostic.serializeMs,elapsed);
      if(next.done){if(chars)yield emit();return;}
      if(chars>=65536)yield emit();
      if(cpuMs>=SLICE_MS||steps>=SLICE_STEPS){
        if(chars)yield emit();
        const started=performance.now();if(diagnostic)diagnostic.phase='yield';
        await yieldTurn();
        if(diagnostic){diagnostic.yieldMs=diagnosticAdd(diagnostic.yieldMs,performance.now()-started);diagnostic.phase='serialize';}
        cpuMs=0;steps=0;
      }
    }
  }
  let chunks=[],chars=0,steps=0,started=performance.now(),diagnosticStart=performance.now();
  for(const fragment of jsonFragments(value,accountNpcProfiles)){
    chunks.push(fragment);chars+=fragment.length;steps++;
    if(chars>=(accountNpcProfiles?65536:CHUNK_CHARS)||steps>=SLICE_STEPS||performance.now()-started>=SLICE_MS){if(diagnostic)diagnostic.serializeMs=diagnosticAdd(diagnostic.serializeMs,performance.now()-diagnosticStart);if(chars)yield chunks.join('');chunks=[];chars=0;steps=0;const yielded=performance.now();if(diagnostic)diagnostic.phase='yield';await yieldTurn();if(diagnostic){diagnostic.yieldMs=diagnosticAdd(diagnostic.yieldMs,performance.now()-yielded);diagnostic.phase='serialize';}started=performance.now();diagnosticStart=started;}
  }
  if(diagnostic)diagnostic.serializeMs=diagnosticAdd(diagnostic.serializeMs,performance.now()-diagnosticStart);if(chars)yield chunks.join('');
}

/** Flush complete bytes before the atomic rename. The old file survives any pre-rename failure. */
export async function writeAtomicStore(file,value,{io=fs,accountNpcProfiles=false,accountNpcRecordFragment=null}={}){
  const diagnostic=writerBegin();let completed=false;
  try{
  assertPrivateAccountDirectory(file);diagnostic.phase='mkdir';
  await io.mkdir(path.dirname(file),{recursive:true});
  const temporary=`${file}.${randomBytes(6).toString('hex')}.tmp`;
  let handle;
  try{
    diagnostic.phase='open';handle=await io.open(temporary,'wx',0o600);diagnostic.phase='serialize';
    if(largeStore(value)){
      // ENGINE-CHOSEN account-only 4Mi character flush; at most 12MiB UTF-8 per buffer.
      const IO_CHARS=accountNpcProfiles===true?4*1024*1024:65536,IO_PARTS=128;let parts=[],chars=0;
      const flush=async()=>{if(chars){await writerWrite(handle,parts.join(''),diagnostic,accountNpcProfiles===true);parts=[];chars=0;}};
      for await(const chunk of serializeStoreChunks(value,diagnostic,accountNpcProfiles===true,accountNpcRecordFragment)){diagnostic.serializedChars=diagnosticAdd(diagnostic.serializedChars,chunk.length);diagnostic.chunks=diagnosticAdd(diagnostic.chunks,1);
        for(let at=0;at<chunk.length;){
          let end=Math.min(chunk.length,at+IO_CHARS-chars);
          // UTF-8 encodes each write independently; keep authored pairs together.
          if(end<chunk.length&&chunk.charCodeAt(end-1)>=0xd800&&chunk.charCodeAt(end-1)<=0xdbff&&chunk.charCodeAt(end)>=0xdc00&&chunk.charCodeAt(end)<=0xdfff)end--;
          if(end===at){await flush();continue;}
          parts.push(chunk.slice(at,end));chars+=end-at;at=end;
          if(chars===IO_CHARS||parts.length>=IO_PARTS)await flush();
        }
      }
      await flush();
    }
    else{const started=performance.now(),text=JSON.stringify(value);diagnostic.serializeMs=diagnosticAdd(diagnostic.serializeMs,performance.now()-started);diagnostic.serializedChars=typeof text==='string'?text.length:0;diagnostic.chunks=1;await writerWrite(handle,text,diagnostic);}
    diagnostic.phase='sync';const synced=performance.now();try{await handle.sync();}finally{diagnostic.syncMs=diagnosticAdd(diagnostic.syncMs,performance.now()-synced);}diagnostic.phase='close';await handle.close();handle=null;
    diagnostic.phase='rename';await renameAtomicStore(io,temporary,file);completed=true;
  }finally{
    diagnostic.phase='cleanup';
    if(handle)await handle.close().catch(()=>{});
    await io.rm(temporary,{force:true}).catch(()=>{});
  }
  }finally{writerEnd(diagnostic,completed);}
}
