// Engine authoring protocol, not a recovered official server protocol.
// Original bytes/catalogs remain immutable. Only existing scalar brush arrays
// are accepted; object/NPC/service/script replacement is deliberately absent.
import {DEFAULT_CELL_TABLE} from '../../formats/mac.js';
export const ORIGINAL_EDIT_LIMITS=Object.freeze({batch:2048,total:100000,body:160000,interval:200,idle:60000,ready:30000});
export const ORIGINAL_EDIT_FIELDS=Object.freeze(['heights','colors','vertexTypes','cellVariants','attrs','holes','waterDef','waterH']);
const cells=new Set(DEFAULT_CELL_TABLE.keys());
const fail=message=>{throw Object.assign(Error(message),{status:400});};
export function validateOriginalChanges(doc,changes){
 if(!Array.isArray(changes)||!changes.length||changes.length>ORIGINAL_EDIT_LIMITS.batch)fail('Send 1–2048 brush scalar changes.');
 const seen=new Set();
 return changes.map(row=>{
  if(!Array.isArray(row)||row.length!==3)fail('Invalid brush change.');
  const [field,index,value]=row,key=`${field}:${index}`;
  if(!ORIGINAL_EDIT_FIELDS.includes(field)||!Number.isInteger(index)||index<0||index>=doc[field].length||!Number.isFinite(value)||seen.has(key))fail('Invalid or duplicate brush cell.');
  seen.add(key);
  if(field==='heights'||field==='waterH'){if(Math.abs(value)>10000||!Number.isFinite(Math.fround(value)))fail('Terrain height is outside the authoring bound.');}
  else if(!Number.isInteger(value)||value<0||value>(field==='colors'?255:field==='vertexTypes'?3:field==='cellVariants'?65535:field==='attrs'?65535:field==='holes'?1:doc.waterDefs.length))fail('Brush value is outside its original format.');
  if(field==='attrs'&&!cells.has(value))fail('Unknown original collision attribute.');
  return [field,index,field==='heights'||field==='waterH'?Math.fround(value):value];
 });
}
export function originalPatchEntries(patch){return [...patch.values()].map(row=>[...row]).sort((a,b)=>a[0].localeCompare(b[0])||a[1]-b[1]);}
export function applyOriginalChanges(doc,changes){for(const [field,index,value]of changes)doc[field][index]=value;doc.recomputeNormals();return doc;}
export function mergeOriginalChanges(doc,patch,changes){
 const next=new Map(patch);for(const row of validateOriginalChanges(doc,changes))next.set(`${row[0]}:${row[1]}`,row);
 if(next.size>ORIGINAL_EDIT_LIMITS.total)fail('This overlay exceeds 100000 scalar overrides.');return next;
}
export function validateOriginalOverlay(doc,entries){
 if(!Array.isArray(entries)||entries.length>ORIGINAL_EDIT_LIMITS.total)fail('Invalid original overlay.');
 const patch=new Map();for(let i=0;i<entries.length;i+=ORIGINAL_EDIT_LIMITS.batch)for(const row of validateOriginalChanges(doc,entries.slice(i,i+ORIGINAL_EDIT_LIMITS.batch))){const key=`${row[0]}:${row[1]}`;if(patch.has(key))fail('Duplicate overlay entry.');patch.set(key,row);}return patch;
}
