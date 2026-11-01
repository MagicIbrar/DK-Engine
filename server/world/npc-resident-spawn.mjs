import {npcReachableApproach} from './npc-navigation.mjs';
import {isDkChannel} from './channels.mjs';
const nativeRows=new WeakMap();
function fieldRows(data,index){let maps=nativeRows.get(data);if(!maps){maps=new Map();nativeRows.set(data,maps);}if(!maps.has(index))maps.set(index,(data.spawns?.(index)||[]).map(s=>({s,d:data.monsterDef?.(s.monsterIndex)})).filter(({s,d})=>d?.role==='creature'&&!d.boss&&!d.ai?.boss&&Number(d.exp)>0&&[s.x,s.z,Number(d.level)].every(Number.isFinite)).map(({s,d})=>({...s,nativeLevel:Number(d.level)})));return maps.get(index);}
// ENGINE-CHOSEN initial placement for NEW actors only. Coordinates come from
// actual placed quest officers/native ordinary creature spawns, then a small
// collision-checked spacing offset. Saved positions never pass through here.
export function npcNativeResidentSpawn(data,map,{anchor,choice,serial=0,saved=false,occupied=[],pathBudget=2}={}){
 if(saved||!map||Number(anchor?.map)!==Number(map.index)||anchor.instanceId||isDkChannel(anchor.channel)||data.requiresInstance?.(map.index)||![anchor.x,anchor.z,choice?.level].every(Number.isFinite))return null;
 const budget=Math.min(2,Math.max(0,Number.isFinite(pathBudget)?Math.trunc(pathBudget):2)),ordinal=Number.isSafeInteger(serial)?Math.max(0,serial):0,candidates=[],goal=choice.goal;
 if(goal?.kind==='quest'&&Number(goal.officerMap)===Number(map.index)){
  const row=data.progression?.npcs?.placements?.[map.index]?.rows?.find(r=>Number(r[0])===Number(goal.officer)),q=data.progression?.quests?.quests?.[goal.questId];
  if(row&&q&&!q.hidden&&!q.isGroup&&Number(q.giver?.map)===Number(map.index)&&[q.giver.npc,...(q.giver.alt||[])].some(n=>Number(n)===Number(row[0]))&&choice.level>=Number(q.level?.[0]||1)&&(!Number(q.level?.[1])||choice.level<=Number(q.level[1])))candidates.push({x:Number(row[1]),z:Number(row[2]),source:{kind:'quest',questId:q.id,npc:Number(row[0])}});
 }
 // Cover actual work regions across the connected map, rather than repeatedly
 // choosing the nearest24 portal-adjacent spawns. Native path validation still
 // limits every call to two attempts; this is a chosen placement policy.
 const field=fieldRows(data,map.index).filter(s=>Math.abs(s.nativeLevel-choice.level)<=8&&Math.hypot(s.x-anchor.x,s.z-anchor.z)>=16),groups=new Map(),local=occupied.filter(p=>!p.leaving&&!p.instanceId&&Number(p.map)===Number(map.index)&&(p.channel||0)===(anchor.channel||0));
 for(const s of field){const key=`${Math.floor(s.x/96)}:${Math.floor(s.z/96)}`;if(!groups.has(key))groups.set(key,[]);groups.get(key).push(s);}
 const regions=[...groups].sort(([a],[b])=>a.localeCompare(b)),offset=regions.length?ordinal%regions.length:0;
 const ordered=regions.map((_,i)=>regions[(offset+i)%regions.length]).map(([key,rows],order)=>({rows,order,occupied:local.filter(p=>`${Math.floor(p.x/96)}:${Math.floor(p.z/96)}`===key).length})).sort((a,b)=>a.occupied-b.occupied||a.order-b.order);
 for(const {rows}of ordered){const start=Math.floor(ordinal/Math.max(1,regions.length))%rows.length;for(let i=0;i<rows.length;i++){const s=rows[(start+i)%rows.length];candidates.push({x:s.x,z:s.z,source:{kind:'farm',spawnId:s.id,monsterIndex:s.monsterIndex,monsterLevel:s.nativeLevel}});}}
 let checked=0;
 for(const candidate of candidates){if(checked>=budget)break;const angle=ordinal*2.399963229728653,radius=candidate.source.kind==='quest'?4+ordinal%3:4+ordinal%4,goalAt={x:candidate.x+Math.cos(angle)*radius,z:candidate.z+Math.sin(angle)*radius};
  if(!map.isWalkable?.(goalAt.x,goalAt.z))continue;const at=map.nearest?.(goalAt.x,goalAt.z),spacing=candidate.source.kind==='farm'?12:3.5;if(!at||Math.hypot(at.x-goalAt.x,at.z-goalAt.z)>1||local.some(p=>Math.hypot(at.x-p.x,at.z-p.z)<spacing))continue;
  checked++;if(!npcReachableApproach(map,anchor,at,1))continue;
  return {at:{map:Number(map.index),x:at.x,z:at.z},source:candidate.source,pathChecks:checked,provenance:{policy:'ENGINE-CHOSEN new resident initial objective/spacing; no saved relocation or progress',placement:candidate.source.kind==='quest'?'native placed ordinary quest giver':'native ordinary creature spawn',map:Number(map.index)}};
 }
 return null;
}
