import {normalizeRecord,ROW_FIELDS} from '../../src/systems/itembuilder/registry.js';

const fail=message=>{throw Object.assign(new Error(message),{status:400});};
const object=(value,keys,label)=>{
  if(!value||typeof value!=='object'||Array.isArray(value)||Object.keys(value).some(k=>!keys.includes(k)))fail(`Invalid ${label} fields.`);
};
const number=(value,label,{min=0,max=1e9,integer=false}={})=>{
  if(typeof value!=='number'||!Number.isFinite(value)||value<min||value>max||integer&&!Number.isInteger(value))fail(`Invalid ${label} number.`);
};
const text=(value,label,max=4096)=>{if(typeof value!=='string'||value.length>max)fail(`Invalid ${label} text.`);};
const assetKey=value=>{
  text(value,'asset key');
  // Original assets contain #, =, @ and non-ASCII filenames. Validate paths, not an ASCII filename alphabet.
  if(!value||/[:\x00-\x1f\x7f?]/.test(value)||/^[\\/]/.test(value)||value.split(/[\\/]/).some(part=>part==='..'||part==='.'||!part))fail('Use relative game asset keys only.');
};
const vector=(value,length,label,min=-1e9)=>{if(!Array.isArray(value)||value.length!==length)fail(`Invalid ${label} array.`);for(const v of value)number(v,label,{min});};
function asset(value){
  object(value,['mesh','tpack','textures','anim','skel'],'asset');assetKey(value.mesh);
  if(/\.glb$/i.test(value.mesh)&&!/^custom\/glb\/[a-f0-9]{64}\.glb$/.test(value.mesh))fail('GLB assets must be uploaded through the verified custom asset store.');
  if(/\.glb$/i.test(value.mesh)&&(value.tpack||value.textures||value.anim||value.skel))fail('GLB preserves its embedded materials; native texture/animation overrides are not supported.');
  for(const key of ['tpack','anim','skel'])if(value[key]!=null)assetKey(value[key]);
  if(value.textures!=null){if(!Array.isArray(value.textures)||value.textures.length>64)fail('Invalid asset textures.');for(const row of value.textures){object(row,['material','diffuse','specular'],'texture');number(row.material,'material',{max:65535,integer:true});for(const key of ['diffuse','specular'])if(row[key]!=null)assetKey(row[key]);}}
}
export function validateCustomItem(record,db){
  object(record,['index','name','desc','base','slot','grade','sockets','roll','look','shape','created','updated',...ROW_FIELDS],'custom item record');
  if(JSON.stringify(record).length>32000)fail('Custom item record is too large.');
  for(const key of ['name','desc','slot','grade'])if(record[key]!=null)text(record[key],key,key==='name'?120:key==='desc'?2000:80);
  for(const key of ['created','updated'])if(record[key]!=null)number(record[key],key,{max:1e15});
  for(const key of ['base','index'])if(record[key]!=null)number(record[key],key,{integer:true,max:1e10});
  if(record.sockets!=null)number(record.sockets,'sockets',{integer:true,max:4});
  if(record.roll!=null&&typeof record.roll!=='boolean')fail('Invalid item roll flag.');
  const arrays=['melee','magic','ranged','def','options','exOptions','optionPools','socketRates','dropStack','dropRate'];
  for(const key of ROW_FIELDS)if(record[key]!=null&&!arrays.includes(key)&&key!=='use')number(record[key],key,{max:['price','sell'].includes(key)?1e10:1e9});
  for(const key of ['type','code','classMask','w','h','stack','maxStack','autoStack'])if(record[key]!=null)number(record[key],key,{integer:true});
  for(const key of ['melee','magic','ranged','def','dropStack'])if(record[key]!=null)vector(record[key],2,key,0);
  for(const [key,limit]of [['options',6],['exOptions',7],['optionPools',32]])if(record[key]!=null){
    if(!Array.isArray(record[key])||record[key].length>limit)fail(`Invalid ${key} list.`);
    for(const pair of record[key]){vector(pair,2,key);number(pair[0],key,{integer:true});if(key!=='optionPools'&&pair[0]!==0&&!db.optionType(pair[0]))fail('Unknown custom item option code.');}
  }
  for(const [key,length]of [['socketRates',4],['dropRate',3]])if(record[key]!=null)vector(record[key],length,key,0);
  if(record.use!=null){
    const numeric=['socketIcon','hp','mp','shield','hpPct','mpPct','shieldPct','stamina','itemStatus','teleport','skill','meisterSkill','brandLevel'];
    object(record.use,[...numeric,'randomBox','package','premiere'],'item use');
    for(const key of numeric)if(record.use[key]!=null)number(record.use[key],`use.${key}`);
    if(record.use.randomBox!=null)text(record.use.randomBox,'random box',120);
    for(const key of ['package','premiere'])if(record.use[key]!=null&&typeof record.use[key]!=='boolean')number(record.use[key],`use.${key}`,{integer:true});
  }
  if(record.look!=null){
    const look=record.look;object(look,['all','left','byClass','leftItem','action','leftAction','effect','leftEffect','bone','parts','costype'],'item look');
    for(const key of ['all','left'])if(look[key]!=null)asset(look[key]);
    if(look.byClass!=null){object(look.byClass,Array.from({length:15},(_,i)=>String(i)),'class look');for(const value of Object.values(look.byClass))asset(value);}
    for(const key of ['leftItem','action','leftAction','effect','leftEffect'])if(look[key]!=null)number(look[key],key,{integer:true});
    for(const key of ['bone','costype'])if(look[key]!=null)text(look[key],key,120);
    if(look.parts!=null){if(!Array.isArray(look.parts)||look.parts.length>32)fail('Invalid item parts.');for(const part of look.parts)text(part,'part',120);}
    if(Number(record.type)!==4&&[look.all,look.left,...Object.values(look.byClass||{})].some(value=>/\.glb$/i.test(value?.mesh||'')))fail('Equipped GLB is currently supported for rigid weapons/offhands. Armor requires verified native rig mapping.');
  }
  if(record.shape!=null){
    const shape=record.shape;object(shape,['game','inv','field','invAnim','invSkel','invAnimTime','invScale','invTwoSide','drop'],'item shape');
    for(const key of ['game','inv','field'])if(shape[key]!=null)asset(shape[key]);
    for(const key of ['invAnim','invSkel'])if(shape[key]!=null)assetKey(shape[key]);
    for(const key of ['invAnimTime','invScale'])if(shape[key]!=null)number(shape[key],key);
    if(shape.invTwoSide!=null&&typeof shape.invTwoSide!=='boolean')fail('Invalid inventory two-sided flag.');
    if(shape.drop!=null){const drop=shape.drop;object(drop,['pos','scale','rot','effect'],'drop appearance');if(drop.pos!=null)vector(drop.pos,3,'drop position');for(const key of ['scale','effect'])if(drop[key]!=null)number(drop[key],key);if(drop.rot!=null){if(!Array.isArray(drop.rot)||drop.rot.length!==2||!['x','y','z'].includes(drop.rot[0]))fail('Invalid drop rotation.');number(drop.rot[1],'drop rotation',{min:-1e9});}}
  }
  return normalizeRecord(record,db);
}
