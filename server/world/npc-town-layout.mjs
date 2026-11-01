import {npcRetainedCityBirthSeat} from './npc-city-birth-seat.mjs';
import {fishingBusy} from './fishing.mjs';
import {mapFor,sameScene,sceneKey} from './scene.mjs';
import {isDkChannel} from './channels.mjs';
import {PCSHOP_ARDECA} from './pcshop.mjs';
import {npcReachableApproach} from './npc-navigation.mjs';

// ENGINE-CHOSEN spacing, never a native spawn/teleport/collision change.
// Plans reserve stable goals; callers still issue ordinary movement commands.
export const NPC_TOWN_LAYOUT_POLICY=Object.freeze({separation:3.5,settle:1.1,pathBudget:2,candidates:37,retryMs:2000,maxRadius:20,reservationMs:10000,audienceRadius:40});
const stores=new WeakMap(),distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const npc=p=>p?.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile?.authority==='server';
const live=(world,p)=>world.players?.get(p.account)===p&&!p.leaving&&!p.revoked&&!p.dead;
/** Only an actual bot-only party's stationary leader may choose its own rest
 * space. Human crews and followers retain their existing escort/ring goals. */
export function npcTownMayPark(world,p){
 if(!npc(p)||!live(world,p))return false;
 if(!p.partyId)return true;
 const party=world.parties?.get(p.partyId);
 if(!party||party.leader!==p.id||!party.members.includes(p.id))return false;
 return party.members.every(id=>{const q=[...world.players.values()].find(q=>q.id===id);return npc(q)&&live(world,q)&&sameScene(p,q);});
}
const stamp=s=>{let h=2166136261;for(const c of String(s)){h^=c.charCodeAt(0);h=Math.imul(h,16777619);}return h>>>0;};
function records(world){let saved=stores.get(world);if(!saved){saved=new Map();stores.set(world,saved);}for(const [key,row]of saved){const end=row.player.path?.at(-1),walking=end&&row.at&&distance(end,row.at)<=1.1,parked=row.at&&distance(row.player,row.at)<=1.1;
 if(!live(world,row.player)||row.scene!==sceneKey(row.player.map,row.player.instanceId,row.player.channel)||row.kind==='party'&&(row.player.partyId!==row.partyId||world.parties?.get(row.partyId)?.leader===row.player.id)||world.now()-(row.touched??world.now())>NPC_TOWN_LAYOUT_POLICY.reservationMs&&!walking&&!parked&&!row.player.pcShopOpen)saved.delete(key);
 }return saved;}
function clear(world,p,point,saved,own,policy,{positions=true}={}){
 for(const row of saved.values())if(row!==own&&row.at&&sameScene(p,row.player)&&distance(point,row.at)<policy.separation)return false;
 for(const other of world.players.values())if(other!==p&&live(world,other)&&sameScene(p,other)&&(positions||other.pcShopOpen||!other.path?.length)&&distance(point,other)<policy.separation)return false;
 return true;
}
function plan(world,p,{kind,anchor,identity,ordinal=0,policy=NPC_TOWN_LAYOUT_POLICY,allowDk=false}){
 if(!npc(p)||!live(world,p)||p.instanceId||isDkChannel(p.channel)&&!allowDk||p.sceneTransition||p.tradeId||p.tradeCommitting||p.progressCommitting||p.pcShopOpen)return null;
 const map=mapFor(world,p);if(!map||typeof map.isWalkable!=='function'||typeof map.nearest!=='function')return null;
 const saved=records(world),scene=sceneKey(p.map,p.instanceId,p.channel),key=p.account+':'+kind;
 for(const [otherKey,other]of saved)if(other.player===p&&otherKey!==key)saved.delete(otherKey);
 let row=saved.get(key);
 if(!row||row.scene!==scene||row.map!==map||row.identity!==identity||kind==='party'&&distance(row.anchor,anchor)>1.25){
  row={player:p,scene,map,identity,kind,touched:world.now(),partyId:p.partyId,anchor:{x:anchor.x,z:anchor.z},cursor:0,retry:0,at:null};saved.set(key,row);
 }
 row.touched=world.now();
 const answer=()=>({at:{map:p.map,...row.at},near:distance(p,row.at)<=policy.settle,key:kind+':'+scene+':'+identity});
 if(row.at){if(map.isWalkable(row.at.x,row.at.z)&&clear(world,p,row.at,saved,row,policy,{positions:false}))return answer();row.at=null;row.cursor=0;}
 if(world.now()<row.retry)return null;
 let checked=0;
 while(row.cursor<policy.candidates&&checked<policy.pathBudget){
  const i=row.cursor++,hash=stamp(p.account),rotation=(hash%360)*Math.PI/180;
  const radius=kind==='party'?4.8+Math.floor(i/12)*2:kind==='service'?2.8+Math.floor(i/12)*1.2:kind==='wait'?10+Math.floor(i/12)*4:kind==='yield'?4+Math.floor(i/12)*3:i===0?0:6+Math.floor((i-1)/12)*4;
  const angle=rotation+(kind==='party'?ordinal*Math.PI/3:0)+i*2.399963229728653;
  const goal={x:row.anchor.x+Math.cos(angle)*radius,z:row.anchor.z+Math.sin(angle)*radius};
  // Skip blocked candidates rather than repeatedly searching broad native
  // nearest-cell rings. A walkable candidate needs only its local grid snap.
  const point=map.isWalkable(goal.x,goal.z)?map.nearest(goal.x,goal.z):null;
  if(!point||![point.x,point.z].every(Number.isFinite)||distance(point,goal)>2||distance(point,row.anchor)>policy.maxRadius||!map.isWalkable(point.x,point.z)||!clear(world,p,point,saved,row,policy))continue;
  checked++;
  const at=npcReachableApproach(map,p,point,1);
  if(!at||!clear(world,p,at,saved,row,policy))continue;
  row.at={x:at.x,z:at.z};return answer();
 }
 if(row.cursor>=policy.candidates)row.cursor=0;
 row.retry=world.now()+policy.retryMs;return null;
}
/** Real Ardeca stalls only. The merchant checks native eligibility and owned
 * listings separately. An open shop is never relocated by this helper. */
export function npcTownStallPlan(world,p,options={}){
 if(p?.map!==PCSHOP_ARDECA||Number(world.data?.dungeonData?.dg?.maps?.[p.map]?.raw?.PcStore)!==1)return null;
 if(!npc(p)||!live(world,p)||p.instanceId||isDkChannel(p.channel)||p.sceneTransition||p.tradeId||p.tradeCommitting||p.progressCommitting||p.pcShopOpen)return null;
 const map=mapFor(world,p);if(!map?.isWalkable||!map.nearest)return null;
 const catalog=world.data.progression?.npcs,placed=catalog?.placements?.[p.map]?.rows||[],gates=world.data.gates?.(p.map)||[],saved=records(world),scene=sceneKey(p.map,p.instanceId,p.channel),key=p.account+':stall',policy={...NPC_TOWN_LAYOUT_POLICY,...options.policy};
 for(const [otherKey,other]of saved)if(other.player===p&&otherKey!==key)saved.delete(otherKey);
 const safe=at=>!placed.some(([id,x,z])=>distance(at,{x,z})<(catalog.npcs?.[id]?.jobs?.some(([type])=>[2,16,42,96].includes(Number(type)))?8:5))&&!gates.some(g=>g.box&&at.x>=g.box[0]-4&&at.x<=g.box[2]+4&&at.z>=g.box[1]-4&&at.z<=g.box[3]+4);
 let row=saved.get(key);if(!row||row.scene!==scene||row.map!==map||row.kind!=='stall'){
  // Only authored town-service districts, with collision/path checked market
  // space around them. The current actor/home point is not the market centre.
  const regions=new Map();for(const [id,x,z]of placed){if(![x,z].every(Number.isFinite)||!catalog.npcs?.[id]?.jobs?.some(([type])=>[2,4,13,16,42,96,102].includes(Number(type))))continue;const cell=`${Math.floor(x/96)}:${Math.floor(z/96)}`;if(!regions.has(cell))regions.set(cell,[]);regions.get(cell).push({x,z,npc:Number(id)});}
  const groups=[...regions].sort(([a],[b])=>a.localeCompare(b)),offset=groups.length?stamp(p.account)%groups.length:0;
  // ENGINE-CHOSEN load balancing of NEW seats around authored services.
  // Existing reserved seats/open shops stay put; equal loads retain identity
  // preference. Count a seller once, even when its open shop has a reservation.
  const loads=new Map(groups.map(([cell])=>[cell,0])),counted=new Set();
  const district=at=>{let cell=null,best=Infinity;for(const [key,anchors]of groups)for(const anchor of anchors){const d=distance(at,anchor);if(d<best){best=d;cell=key;}}return cell;};
  const add=(at,cell)=>{const key=loads.has(cell)?cell:district(at);if(key!==null)loads.set(key,loads.get(key)+1);};
  for(const other of saved.values())if(other.player!==p&&other.kind==='stall'&&other.at&&sameScene(p,other.player)){add(other.player.pcShopOpen?other.player:other.at,other.player.pcShopOpen?null:other.district);counted.add(other.player);}
  for(const other of world.players.values())if(other!==p&&live(world,other)&&sameScene(p,other)&&other.pcShopOpen&&!counted.has(other))add(other,null);
  const ordered=groups.map((_,i)=>groups[(offset+i)%groups.length]).sort(([a],[b])=>loads.get(a)-loads.get(b));
  // ENGINE-CHOSEN identity distribution across authored city districts.
  // Native collision and reservations choose space; the human's location does
  // not collapse every seller into the same market ring.
  const anchors=ordered.flatMap(([district,rows])=>{const start=stamp(p.account)%rows.length;return [...rows.slice(start),...rows.slice(0,start)].map(anchor=>({...anchor,district}));});if(!anchors.length)return null;
  row={player:p,scene,map,kind:'stall',identity:p.id,touched:world.now(),anchors,anchorCursor:0,cursor:0,retry:0,at:null};saved.set(key,row);
 }
 row.touched=world.now();
 // A fresh merchant already occupies its native collision-checked birth seat.
 // Reuse only this current position under ALL ordinary stall clearance rules.
 // Saved travelers and accepted paths never move back to a birth coordinate.
 if(!row.at&&p.profile.npcSeed?.initialGoal?.kind==='merchant'){
  const born=npcRetainedCityBirthSeat(world,p);
  if(born&&safe(born.at)&&clear(world,p,born.at,saved,row,policy))row.at={x:born.at.x,z:born.at.z};
 }
 const answer=()=>({at:{map:p.map,...row.at},near:distance(p,row.at)<=policy.settle,key:'stall:'+scene+':'+p.id});
 if(row.at&&map.isWalkable(row.at.x,row.at.z)&&safe(row.at)&&clear(world,p,row.at,saved,row,policy,{positions:false}))return answer();row.at=null;if(world.now()<row.retry)return null;
 let paths=0;for(let cheap=0;cheap<37&&paths<2;cheap++){
  if(row.cursor>=37){row.cursor=0;row.anchorCursor=(row.anchorCursor+1)%row.anchors.length;}const anchor=row.anchors[row.anchorCursor],i=row.cursor++,angle=stamp(p.account)%360*Math.PI/180+i*2.399963229728653,radius=9+Math.floor(i/12)*4,goal={x:anchor.x+Math.cos(angle)*radius,z:anchor.z+Math.sin(angle)*radius};
  const point=map.isWalkable(goal.x,goal.z)?map.nearest(goal.x,goal.z):null;if(!point||distance(point,goal)>2||!safe(point)||!clear(world,p,point,saved,row,policy))continue;
  paths++;const at=npcReachableApproach(map,p,point,1);if(!at||!safe(at)||!clear(world,p,at,saved,row,policy)){row.anchorCursor=(row.anchorCursor+1)%row.anchors.length;continue;}row.district=anchor.district;row.at={x:at.x,z:at.z};return answer();
 }
 row.retry=world.now()+Math.max(2000,Number(policy.retryMs)||2000);return null;
}
/** Only stationary bot-only public parties. Humans/private/DK admission,
 * combat, service commits and open shops keep their existing authority. */
export function npcTownPartyPlan(world,p,leader,options={}){
 if(!npc(p)||!live(world,p)||!npc(leader)||!live(world,leader)||leader===p||!sameScene(p,leader)||leader.path?.length||leader.attackTarget||leader._skills?.engine.casting)return null;
 const party=world.parties?.get(p.partyId);
 if(!party||leader.partyId!==p.partyId||party.leader!==leader.id||!party.members.includes(p.id)||!party.members.includes(leader.id))return null;
 const members=party.members.map(id=>[...world.players.values()].find(q=>q.id===id));
 if(members.some(q=>!npc(q)||!live(world,q)))return null;
 return plan(world,p,{kind:'party',anchor:leader,identity:party.id??p.partyId,ordinal:party.members.indexOf(p.id),...options});
}

/** Approach a genuine placed NPC from a distinct point inside its ordinary
 * seven-unit interaction radius. Selection/acceptance remains native. */
export function npcTownServicePlan(world,p,service,options={}){
 if(Number(service?.map)!==p?.map||!Number.isFinite(Number(service?.npc)))return null;
 const row=world.data?.progression?.npcs?.placements?.[p.map]?.rows?.find(r=>Number(r[0])===Number(service.npc));
 if(!row||Math.hypot(Number(row[1])-service.x,Number(row[2])-service.z)>.01)return null;
 return plan(world,p,{kind:'service',anchor:service,identity:p.map+':'+service.npc,policy:{...NPC_TOWN_LAYOUT_POLICY,maxRadius:6.5},...options});
}

/** ENGINE-CHOSEN ordinary crowd yielding. Never teleport or move a human/shop/
 * combat actor. Caller preserves accepted plans and issues normal movement. */
export function npcTownYieldPlan(world,p,options={}){
 if(!npcTownMayPark(world,p)||p.path?.length||p.pcShopOpen||p.attackTarget||p._skills?.engine.casting||p.sceneTransition||p.tradeId||fishingBusy(p)||p.mount?.phase==='on'||p.commandActive||p.progressCommitting||p.tradeCommitting||Number(world.data.mapRow?.(p.map)?.PeaceZone)!==1)return null;
 if(![...world.players.values()].some(q=>q!==p&&live(world,q)&&sameScene(p,q)&&!q.path?.length&&distance(p,q)<NPC_TOWN_LAYOUT_POLICY.separation))return null;
 return plan(world,p,{kind:'yield',anchor:p,identity:'crowd:'+Math.floor(p.x/4)+':'+Math.floor(p.z/4),...options});
}
/** Native NPC's saturated interaction ring gets a distinct outer waiting
 * point. This is waiting only; it grants no native service/quest success. */
export function npcTownWaitPlan(world,p,service,options={}){
 const row=world.data?.progression?.npcs?.placements?.[p?.map]?.rows?.find(r=>Number(r[0])===Number(service?.npc));
 if(!row||Number(service.map)!==p.map||distance({x:Number(row[1]),z:Number(row[2])},service)>.01)return null;
 return plan(world,p,{kind:'wait',anchor:service,identity:p.map+':'+service.npc,...options});
}

/** Aggregate diagnostics only; no profile/account/character identifiers. */
export function npcTownLayoutSnapshot(world){const rows=[...records(world).values()],kinds={};for(const row of rows)kinds[row.kind]=(kinds[row.kind]||0)+1;return {reservations:rows.length,kinds};}
