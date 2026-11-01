// ENGINE-CHOSEN initial position for NEW unpersisted quiet-city identities.
// This is neither movement nor a service transaction. Saved actors are never moved.
const reservations=new WeakMap();
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const stamp=s=>{let h=2166136261;for(const c of String(s))h=Math.imul(h^c.charCodeAt(0),16777619)>>>0;return h;};
const services=(data,map)=>(data.progression?.npcs?.placements?.[map]?.rows||[]).filter(([id,x,z])=>[x,z].every(Number.isFinite)&&data.progression.npcs.npcs?.[id]?.jobs?.some(([type])=>[2,4,13,16,42,96,102].includes(Number(type)))).sort((a,b)=>Number(a[0])-Number(b[0])||a[1]-b[1]||a[2]-b[2]);
export function npcCityBirthSeat(data,map,identity){
 const row=data.mapRow?.(150);if(identity.map!==150||!['merchant','rest'].includes(identity.activity?.kind)||map?.index!==150||Number(row?.PeaceZone)!==1||Number(row?.PcStore)!==1||data.requiresInstance?.(150)||data.eventData?.modeOf?.(150)||Number(row?.IsSiege)||!/^r[a-f0-9]{24}$/.test(identity.npcRosterId)||typeof map.isWalkable!=='function')return null;
 const anchors=services(data,150);if(!anchors.length)return null;
 let seats=reservations.get(map);if(!seats){seats=new Map();reservations.set(map,seats);}if(seats.has(identity.npcRosterId))return seats.get(identity.npcRosterId);
 const hash=stamp(identity.npcRosterId),gates=data.gates?.(150)||[];
 for(let a=0;a<anchors.length;a++){const [npc,x,z]=anchors[(hash+a)%anchors.length];for(let n=0;n<96;n++){
  const angle=(hash%360)*Math.PI/180+n*2.399963229728653,radius=9+Math.floor(n/16)*3.5,wanted={x:x+Math.cos(angle)*radius,z:z+Math.sin(angle)*radius};
  if(!map.isWalkable(wanted.x,wanted.z))continue;const point=map.nearest?map.nearest(wanted.x,wanted.z):wanted;if(!point||distance(point,wanted)>2)continue;
  if(!map.isWalkable(point.x,point.z)||anchors.some(([,x,z])=>distance(point,{x,z})<7)||gates.some(g=>g.box&&point.x>=g.box[0]-4&&point.x<=g.box[2]+4&&point.z>=g.box[1]-4&&point.z<=g.box[3]+4)||[...seats.values()].some(s=>distance(point,s.at)<3.5))continue;
  const seat={version:1,map:150,npc:Number(npc),anchor:{x,z},at:point,policy:'ENGINE-CHOSEN new quiet city birth; native placed service/collision/spacing validated'};seats.set(identity.npcRosterId,seat);return seat;
 }}return null;
}
export function npcRetainedCityBirthSeat(world,p){
 const s=p?.profile?.npcSeed?.initialTownSeat,map=world.maps?.get(p.map),row=s&&services(world.data,150).find(([id,x,z])=>Number(id)===s.npc&&x===s.anchor?.x&&z===s.anchor?.z);
 if(s?.version!==1||p.map!==150||p.instanceId||p.channel||!row||!s.at||![s.at.x,s.at.z].every(Number.isFinite)||!map?.isWalkable?.(s.at.x,s.at.z)||distance(p,s.at)>1.1||p.path?.length)return null;
 if([...world.players.values()].some(q=>q!==p&&!q.leaving&&!q.dead&&q.map===150&&!q.instanceId&&!q.channel&&(!q.path?.length||q.pcShopOpen)&&distance(q,s.at)<3.5))return null;
 if((world.data.gates?.(150)||[]).some(g=>g.box&&s.at.x>=g.box[0]-4&&s.at.x<=g.box[2]+4&&s.at.z>=g.box[1]-4&&s.at.z<=g.box[3]+4))return null;
 return {at:{map:150,...s.at},near:true,key:'native-born-rest:'+s.npc,source:{kind:'rest',npc:s.npc,placement:'native useful town service',policy:s.policy}};
}
