// Route accepted quest work only to monsters present in the shipped native
// spawn tables. An event-only or scripted target has no ordinary field route.
const indexes=new WeakMap();
function indexFor(monsters){
 if(!monsters||typeof monsters!=='object')return new Map();
 let found=indexes.get(monsters);if(found)return found;
 found=new Map();
 for(const [map,entry] of Object.entries(monsters.spawns||{})){
  const mapIndex=Number(map);if(!Number.isInteger(mapIndex))continue;
  for(const row of entry?.rows||[]){const id=Number(row[0]);if(!Number.isInteger(id))continue;
   let maps=found.get(id);if(!maps){maps=new Set();found.set(id,maps);}maps.add(mapIndex);
  }
 }
 indexes.set(monsters,found);return found;
}
export function npcQuestSpawnMap(world,quest,objective,currentMap){
 if(!objective||!['kill','killOnMap','collect'].includes(objective.kind))return null;
 if(objective.kind==='killOnMap'){
  const maps=(objective.targets||[]).map(row=>Number(row.id)).filter(Number.isInteger);
  return maps.includes(Number(currentMap))?Number(currentMap):maps.find(map=>!world.data.requiresInstance?.(map))??null;
 }
 const ids=objective.kind==='kill'
  ?(objective.targets||[]).map(row=>Number(row.id))
  :[...(quest.drops||[]).filter(drop=>(objective.targets||[]).some(target=>Number(target.id)===Number(drop.item))).flatMap(drop=>drop.monsters||[]),...(objective.sources?.monsters||[]).map(row=>row[0])].map(Number);
 const index=indexFor(world.data.progression?.monsters),maps=new Set();
 for(const id of ids)for(const map of index.get(id)||[])if(!world.data.requiresInstance?.(map))maps.add(map);
 if(maps.has(Number(currentMap)))return Number(currentMap);
 const giver=Number(quest.giver?.map);if(maps.has(giver))return giver;
 const turnIn=Number(quest.turnIn?.map);if(maps.has(turnIn))return turnIn;
 return [...maps].sort((a,b)=>a-b)[0]??null;
}
