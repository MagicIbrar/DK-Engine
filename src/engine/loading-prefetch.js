import {fetchJSON} from './assets.js';
import {STARTUP_JSON, DEFERRED_JSON, JSON_PREFETCH_LANES} from '../config/engine-chosen-loading.js';
export async function prefetchGameJSON({classIndex = 0, authority, deferred = false} = {}, read = fetchJSON) {
 const names = deferred ? [...DEFERRED_JSON] : [...STARTUP_JSON, `skills/class_${Number(classIndex) || 0}`,
   ...(authority === 'server' ? [] : ['dungeons','events'])];
 let cursor=0;const failures=[];
 await Promise.all(Array.from({length:JSON_PREFETCH_LANES},async()=>{
  while(cursor<names.length){const name=names[cursor++];try{await read(`/gamedata/${name}.json`);}catch(error){failures.push({name,error:String(error?.message||error)});}}
 }));
 return {requested:names.length, failures};
}
