// Spatial visual interest; NPC-player count is bounded, nearby monster bodies are never hidden by a count cap.
export function visibleActorRows(rows,viewer,{kind='player',required=new Set(),prior=new Set(),radius=64,exitRadius=80,npcLimit=70,monsterLimit=Infinity}={}){
 const mandatory=[],optional=[],range=radius*radius,exitRange=Math.max(radius,exitRadius)**2;
 for(const row of rows||[]){
  const distance=(Number(row.x)-Number(viewer.x))**2+(Number(row.z)-Number(viewer.z))**2;
  if(required.has(row.id)||kind==='player'&&row.npcPlayer!==true||kind==='player'&&row.pcShop&&distance<=range){mandatory.push(row);continue;}
  // Keep a body already shown until it leaves the wider exit radius. The
  // server still owns admission; this only prevents 32-nearest churn from
  // disposing and reloading real Ardeca residents every few snapshots.
  if(Number.isFinite(distance)&&(distance<=range||prior.has(row.id)&&distance<=exitRange))optional.push({row,distance,retained:prior.has(row.id)});
 }
 optional.sort((a,b)=>Number(b.retained)-Number(a.retained)||a.distance-b.distance||String(a.row.id).localeCompare(String(b.row.id)));
 return mandatory.concat(optional.slice(0,kind==='player'?npcLimit:monsterLimit).map(x=>x.row));
}

// Prepare this viewer's bounded player cohort before opening the map. The
// server's dormant roster is never a model-loading target. Monster actors here
// already passed visibleActorRows: prepare that exact admitted visual cohort,
// rather than opening the world while the rest of its visible bodies load.
export function initialSceneActors(actors,viewer,{radius=64,playerLimit=70,monsterRadius=Infinity,monsterLimit=Infinity}={}){
 const admitted=(actors||[]).map(actor=>({actor,distance:Math.hypot(Number(actor.x)-Number(viewer?.x),Number(actor.z)-Number(viewer?.z))}))
  .filter(row=>Number.isFinite(row.distance))
  .sort((a,b)=>a.distance-b.distance||String(a.actor.networkId).localeCompare(String(b.actor.networkId)));
 const near=admitted.filter(row=>row.distance<=radius);
 const players=near.filter(row=>row.actor.kind==='player').sort((a,b)=>Number(!!a.actor.npcPlayer)-Number(!!b.actor.npcPlayer)||a.distance-b.distance).slice(0,playerLimit);
 const monsters=admitted.filter(row=>row.actor.kind==='monster'&&row.distance<=monsterRadius).slice(0,monsterLimit);
 const servants=near.filter(row=>row.actor.kind==='servant').slice(0,playerLimit);
 return [...players,...monsters,...servants].map(row=>row.actor);
}
