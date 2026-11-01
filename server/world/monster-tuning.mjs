// GM runtime tuning. Original source tables and saved accounts are untouched;
// a server restart restores the authored monster definitions and drop tables.
function tuning(world,index){
 world.monsterTuning ||= new Map();
 let row=world.monsterTuning.get(index);
 if(!row){row={hp:1,attack:1,drop:1,items:new Map()};world.monsterTuning.set(index,row);}
 return row;
}

function ensureDefinitions(world){
 if(world._monsterTuningSource)return;
 const source=world.data,original=source.monsterDef.bind(source);
 world._monsterTuningSource=source;
 world.data=Object.create(source);
 world.data.monsterDef=index=>{
  const base=original(index),row=world.monsterTuning?.get(Number(index));
  if(!base||!row||row.hp===1&&row.attack===1)return base;
  if(row.cachedBase===base&&row.cachedDef)return row.cachedDef;
  row.cachedBase=base;
  row.cachedDef={...base,hp:Math.max(1,Math.round(Number(base.hp)*row.hp)),
   attacks:Object.fromEntries(Object.entries(base.attacks||{}).map(([key,block])=>[key,Array.isArray(block)?block.map((value,i)=>i<2?Math.max(0,Math.round(Number(value)*row.attack)):value):block]))};
  return row.cachedDef;
 };
}

export function setMonsterFactor(world,index,kind,factor){
 if(!Number.isSafeInteger(index)||index<=0||!world.data.monsterDef(index))throw Error('Choose an original monster ID.');
 if(!['hp','attack','drop'].includes(kind)||!Number.isFinite(factor)||factor<.1||factor>10)throw Error('Choose hp, attack or drop and a factor from 0.1 to 10.');
 ensureDefinitions(world);
 const row=tuning(world,index);row[kind]=factor;row.cachedBase=null;row.cachedDef=null;
 if(kind!=='drop')for(const scene of world.maps.values())for(const monster of scene.monsters?.values()||[]){
  if(monster.monsterIndex!==index||monster.isBrick)continue;
  const fraction=monster.maxHp>0?monster.hp/monster.maxHp:0;
  monster.def=world.data.monsterDef(index);monster.maxHp=monster.def.hp;
  monster.hp=monster.dead?0:Math.max(1,Math.min(monster.maxHp,Math.round(monster.maxHp*fraction)));
 }
 return row;
}

export function setMonsterDropItem(world,index,itemIndex,chance,count=1){
 if(!Number.isSafeInteger(index)||index<=0||!world.data.monsterDef(index))throw Error('Choose an original monster ID.');
 if(!Number.isSafeInteger(itemIndex)||!world.data.itemDB?.def(itemIndex))throw Error('Choose an original item ID.');
 if(!Number.isSafeInteger(chance)||chance<0||chance>100000||!Number.isSafeInteger(count)||count<1||count>99)throw Error('Chance must be 0–100000 and count 1–99.');
 ensureDefinitions(world);
 const row=tuning(world,index);
 if(chance===0)row.items.delete(itemIndex);else row.items.set(itemIndex,{chance,count});
 return row;
}
