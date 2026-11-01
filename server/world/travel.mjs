import {randomBytes} from 'node:crypto';
import {requirePersonalPortal,personalPortalState} from './personal-portal.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {nearbyNpc,offersOriginalJob,npcPlacements} from './npc-services.mjs';
import {initializePets} from './pets.mjs';
import {isDkChannel} from '../../src/systems/channels/channel-rules.js';
import {premiumHas} from './premium-service.mjs';
import {partyWarpMember} from './party.mjs';
import {PREMIUM_TEXT,NPC_WARP_TEXT} from '../../src/systems/shops/premium-rules.js';
import {TRAVEL_FREEZE_MS,TRAVEL_FREEZE_KINDS} from '../../src/config/owner-travel-freeze.js';
import {assertNieteService,assertCombatPremium} from './niete-services.mjs';
import {assertUrbanWarfareAdmissionAvailable} from './urban-warfare.mjs';
import {guildFrontierAccess,frontierSettlementPending} from './guild-frontier.mjs';
import {FRONTIER_MOVE,frontierMoveRoute,hideoutMoveRoute} from '../../src/systems/extras/guildrank-rules.js';
const fail=message=>{throw Object.assign(Error(message),{status:400});};
export const TRAVEL_SCHEMAS={mapnpcwarp:['token','type','operation','npcIndex','nonce'],npctravel:['token','type','npcIndex','operation','table','unit','map','portalId'],smartwarp:['token','type','operation','rowId','nonce']};
const STONES=[7447,1601022];
// A11 World::Provider, OnSky/OnExecute: SkyQuest1 requires an opened world-point
// goal with total >= target. ENGINE-CHOSEN error text binding: native system101:170
// (the protocol error2/6 text mapping was not shipped). No client input can open this gate.
// The World Point producer is the host. Its fed goal is the Genesis Sanctum
// Fortress Voucher donation (quests 15601/15611/15621). Global ships only the
// completed status text 15601:11000 ("the Holy Ground of Prayers is now
// complete"), offers no donation NPC (Naima
// 812 has JobCount0) and sells Space of Pilgrimage teleport scrolls, so Global's
// final state is a completed, open World Point. Read literally from that text;
// anything else stays closed.
export function nativeWorldPoint(world){
 const text=String(world.data.progression?.dialogs?.strings?.[15601]?.[11000]||'');
 const complete=/\bcomplete\b/i.test(text)&&!/<PERCENTAGE>/i.test(text);
 return Object.freeze(complete?{open:true,target:1,total:1,source:'15601:11000 completed'}:{open:false,target:0,total:0,source:'15601:11000 not completed'});
}
export function skyWorldPointOpen(world){const v=world.worldPoint??(world.nativeWorldPoint||=nativeWorldPoint(world));return v?.open===true&&Number.isFinite(v.target)&&Number.isFinite(v.total)&&v.target>=0&&v.total>=v.target;}
const SKY_TEXT={closed:'You have failed to teleport due to unknown reason.',level:'You are not in the right level to teleport.'};
const mapInfo=(world,map)=>world.data.dungeonCatalog?.maps?.[map]||world.data.dungeonData?.dg?.maps?.[map];
export function travelLocation(world,id){const r=world.data.travelData?.locations?.[id];return r?{map:Number(r[0]),x:Number(r[1])+.5,z:Number(r[2])+.5,dirDeg:Number(r[3])||0}:null;}
export function boundReturnTarget(world,profile){
 if(profile.returnLocation!=null){const at=travelLocation(world,profile.returnLocation);if(at)return at;}
 const row=world.data.travelData?.portalArrivals?.find(r=>r.map===150);
 return row?{map:150,x:row.x+.5,z:row.y+.5,dirDeg:row.dir||0}:world.data.respawn||world.data.start;
}
export function canReturnScroll(world,p){return !p.instanceId&&!p.dead&&!p.mount&&mapInfo(world,p.map)?.flags?.returnScroll!==0;}
function available(world,p,{teleport=true}={}){if(teleport)assertNieteService(world,p);if(p.dead||p.mount||p.sceneTransition)fail('Travel is unavailable while dead, mounted or changing maps.');}
/** "[Frontier Dungeon] Move" (guildrank-rules.js FRONTIER_MOVE): the native scripted warp of this Vascuda's map. Entering Harbor Town
 * needs the actor's durable guild to own the Frontier Dungeon now (guild-frontier.mjs frontierDungeonAward: settled rank 1-10 of the
 * period whose following week is running); returning to Ardeca is never gated. Nothing from the client decides membership or rank. */
function frontierMove(world,p,input){
 if(['table','unit','map'].some(k=>input[k]!==undefined))fail('Invalid travel service.');
 const route=frontierMoveRoute(input.npcIndex,p.map);if(!route)fail('Stand near the original travel NPC.');
 npcJob(world,p,route.npc,1,FRONTIER_MOVE.quest);
 const warp=world.data.travelData?.warps?.find(w=>Number(w.id)===route.warp),at=warp&&travelLocation(world,warp.to);
 if(!warp||Number(warp.fromMap)!==route.map||Number(warp.toMap)!==route.toMap||at?.map!==route.toMap)fail('The original travel destination is unavailable.');
 if(route.needsAward&&!guildFrontierAccess(world,p).award){
  const text=String(world.data.progression?.dialogs?.strings?.[FRONTIER_MOVE.quest]?.[FRONTIER_MOVE.refusal]||'Frontier Dungeon can only be entered by Guild Members who own it.').replace(/^\s*\[[^\]]*\]\s*/,'').trim();
  throw Object.assign(Error(text),{status:403,code:'FRONTIER_NOT_OWNER'});   // 1641:100
 }
 return at;
}
function hideoutRefusal(world,cate,code,fallback){
 const raw=world.data.dungeonData?.dg?.maps?.[cate]?.messages?.[code]?.t||world.data.dungeonCatalog?.maps?.[cate]?.messages?.[code]?.t||world.data.progression?.dialogs?.strings?.[cate]?.[code]||fallback;
 throw Object.assign(Error(String(raw).replace(/^\s*\[[^\]]*\]\s*/,'').trim()),{status:403,code:'HIDEOUT_REFUSED'});
}
function hideoutMove(world,p,input){
 if(['table','unit','map','portalId'].some(k=>input[k]!==undefined))fail('Invalid hideout travel service.');
 const {guild,award}=guildFrontierAccess(world,p);
 if(p.map===150){
   npcJob(world,p,input.npcIndex,1,23);
   if(!guild)hideoutRefusal(world,552,107,'Only guild members can enter guild hideout.');
   if(frontierSettlementPending(world))hideoutRefusal(world,552,106,'Ranking is being calculated. You can enter after 01:00.');
   if(!award)hideoutRefusal(world,23,200,'You do not own a guild hideout.');
   if((p.channel??0)!==0)hideoutRefusal(world,552,103,'Channel qualification does not match.');
 }
 const route=hideoutMoveRoute(input.npcIndex,p.map,award?.dungeonGrade);if(!route)fail('Stand near the original hideout NPC.');
 npcJob(world,p,route.npc,1,route.quest);
 const at=travelLocation(world,route.location);
 if(at?.map!==route.toMap)fail('The original hideout destination is unavailable.');
 return at;
}
function npcJob(world,p,id,type,table){
 if(!Number.isInteger(id)||!Number.isInteger(table))fail('Invalid travel service.');
 const data=world.data.progression?.npcs,def=data?.npcs?.[id];
 if(!def?.jobs?.some(j=>Number(j[0])===type&&Number(j[1])===table))fail('That NPC does not offer this travel service.');
 const placed=nearbyNpc(world,p,{npcIndex:id,jobType:type,jobIndex:table,radius:8});
 if(p.instanceId||!placed||!offersOriginalJob(world,placed,type,table))fail('Stand near the original travel NPC.');
}
export function destinationAllowed(world,p,at,{smart=false}={}){
 if(!at||![at.map,at.x,at.z].every(Number.isFinite))fail('The original travel destination is unavailable.');
 assertUrbanWarfareAdmissionAvailable(world,at.map);
 if(at.map>=552&&at.map<=561){
   const access=guildFrontierAccess(world,p);
   if(frontierSettlementPending(world))hideoutRefusal(world,552,106,'Ranking is being calculated. You can enter after 01:00.');
   if(!access.guild)hideoutRefusal(world,552,107,'Only guild members can enter guild hideout.');
   if(access.award?.dungeonGrade!==at.map-551)hideoutRefusal(world,23,200,'You do not own this guild hideout.');
   if((at.channel??p.channel??0)!==0)hideoutRefusal(world,552,103,'Channel qualification does not match.');
 }
 const info=mapInfo(world,at.map),level=Number(p.profile.level)||1;
 if(info?.flags?.siege||info?.kind==='siege'||info?.kind==='arena')fail('This destination requires its own admission service.');
 if(info?.kind&&!['field','system','instance'].includes(info.kind))fail('This destination requires its own admission service.');
 if(info?.levels&&(level<info.levels[0]||level>info.levels[1]))fail('Your level does not meet the destination requirements.');
 // Never turn an arbitrary authored warp point into free dungeon admission.
 if(world.data.requiresInstance?.(at.map)){
  if(!world.admitTravelDestination)fail('Use the original dungeon admission service for this destination.');
  return 'instance';
 }
 return 'field';
}
/** Validated destinations only; cloned cost/inventory commit and rollback on failed storage. */
export async function commitFieldTravel(world,p,at,profile=structuredClone(p.profile),{validate}={}){
 destinationAllowed(world,p,at);
 if(world.data.requiresInstance?.(at.map))fail('Dungeon travel requires admission.');
 // Field travel keeps the field channel; leaving a DK map (any travel without an explicit DK channel) leaves the DK channel.
 const channel=at.channel!==undefined?at.channel:isDkChannel(p.channel)?(profile.dkReturn?.channel??0):(p.channel??0);
 if(isDkChannel(p.channel)&&!isDkChannel(channel))delete profile.dkReturn;
 const keys=['map','channel','x','z','yaw','path','profile','instanceId','dirty','revision','saveError','mount','pet','smartWarp','stats','maxHp','hp','mp'];
 const before=Object.fromEntries(keys.map(k=>[k,p[k]]));p.sceneTransition=true;
 try{
  const scene=await world.map(at.map,null,channel),point=scene.nearest(at.x,at.z);
  if(!point||!scene.isWalkable(point.x,point.z)||Math.hypot(point.x-at.x,point.z-at.z)>32)fail('No safe original arrival point is available.');
  initializePets(profile);
  const stats=world.data.stats?.(profile,{...p,mount:null},world.now())||p.stats;
  const candidate={...p,profile,map:at.map,channel,x:point.x,z:point.z,yaw:-(Number(at.dirDeg)||0)*Math.PI/180,path:[],mount:null,pet:null,smartWarp:null,stats,maxHp:stats?.maxHp??p.maxHp,hp:Math.min(p.hp,stats?.maxHp??p.maxHp),mp:Math.min(p.mp||0,stats?.maxMp??p.mp??0)};
  // Keep snapshots on the committed scene/profile while storage is pending.
  if(at.map>=552&&at.map<=561)destinationAllowed(world,p,at);
  validate?.();world.changed(candidate);await world.persist(candidate);
  for(const key of keys)p[key]=candidate[key];
 }catch(error){
  // Stop remains accepted while destination loading/storage holds the scene lock.
  // Restoring the old scene must not resume a path that the player cancelled.
  const stopped=Array.isArray(p.path)&&p.path.length===0&&p.path!==before.path;
  Object.assign(p,before);if(stopped)p.path=[];throw error;
 }finally{p.sceneTransition=false;}
 world.emit(before.map,{type:'leave',actorId:p.id,channel:before.channel??0});world.emit(p.map,{type:'join',actorId:p.id});
 return true;
}
function rowFor(world,p,id){
 const row=world.data.travelData?.smartWarp?.find(r=>r.id===id),level=Number(p.profile.level)||1;
 if(!row||![1,2,3,4].includes(row.type)||level<row.levels[0]||level>row.levels[1])fail('That Smart Warp is not available at your level.');
 const info=mapInfo(world,p.map);
 if(p.instanceId||info&&(info.kind!=='field'&&info.kind!=='system')||info?.flags?.portal===0)fail('Smart Warp is not permitted in this map.');
 return row;
}
function arrival(row){return{map:row.map,x:row.x+.5,z:row.y+.5,dirDeg:row.dirDeg||0};}
export function smartWarpState(p){const c=p.smartWarp;return c?{nonce:c.nonce,readyAt:c.readyAt,expiresAt:c.expiresAt,rowId:c.rowId,kind:c.kind,npcIndex:c.npcIndex}:null;}
function interrupted(world,p,c){return world.now()>c.expiresAt||p.dead||p.mount||p.map!==c.map||p.instanceId!==c.instanceId||Math.hypot(p.x-c.x,p.z-c.z)>.01||p.hp<c.hp||world.events?.some(e=>e.sequence>c.sequence&&e.type==='damage'&&e.targetId===p.id);}
export {interrupted as travelCastInterrupted};
/** A channel change / big-map teleport cast holds the character in place (src/config/owner-travel-freeze.js). */
export function travelFrozen(world,p){const c=p.smartWarp;return !!c&&TRAVEL_FREEZE_KINDS.includes(c.kind)&&world.now()<=c.expiresAt;}
export function tickTravel(world,p){if(p.smartWarp&&interrupted(world,p,p.smartWarp))p.smartWarp=null;}
async function smartCommand(world,p,input){
 if(input.operation==='cancel'){if(p.smartWarp&&input.nonce!==p.smartWarp.nonce)fail('That Smart Warp cast is no longer active.');p.smartWarp=null;return;}
 available(world,p);
 if(input.operation==='begin'){
  const row=rowFor(world,p,input.rowId);destinationAllowed(world,p,arrival(row),{smart:true});
  const inventory=new AuthoritativeInventory(structuredClone(p.profile),world.data.itemDB,{now:world.now});
  if(!STONES.some(id=>inventory.count(id)>0))fail('A Blessing Warp Stone is required.');
  p.smartWarp={nonce:randomBytes(32).toString('hex'),rowId:row.id,readyAt:world.now()+3000,expiresAt:world.now()+15000,map:p.map,instanceId:p.instanceId,x:p.x,z:p.z,hp:p.hp,sequence:world.sequence};p.path=[];return;
 }
 if(input.operation!=='finish')fail('Unknown Smart Warp operation.');
 const cast=p.smartWarp;
 if(!cast||cast.kind||input.nonce!==cast.nonce)fail('That Smart Warp cast is no longer active.');
 if(world.now()<cast.readyAt)fail('Smart Warp preparation is not complete.');
 // Invalidate before any async destination/storage work: completion cannot be replayed as a new command.
 p.smartWarp=null;
 if(interrupted(world,p,cast))fail('Smart Warp was interrupted.');
 const row=rowFor(world,p,cast.rowId),at=arrival(row),profile=structuredClone(p.profile);
 destinationAllowed(world,p,at,{smart:true});
 const inventory=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now});
 const item=profile.inventory.find(i=>STONES.includes(i.itemIndex)&&inventory.count(i.itemIndex)>0&&!(i.expiresAt&&i.expiresAt<=world.now()));
 if(!item||!inventory.consumeEntry(item,1))fail('A Blessing Warp Stone is required.');
 if(world.data.requiresInstance?.(at.map))return world.admitTravelDestination(p,{row,profile});
 await commitFieldTravel(world,p,at,profile);
}
function mapNpcDestination(world,p,id){
 if(!Number.isInteger(id)||p.instanceId||world.data.customMaps?.has?.(p.map))fail('Choose an original NPC in the current field.');
 const info=mapInfo(world,p.map);if(info?.kind&&!['field','system'].includes(info.kind)||info?.flags?.siege||info?.flags?.portal===0)fail('NPC map travel is unavailable here.');
 const def=world.data.progression?.npcs?.npcs?.[id],row=npcPlacements(world,p.map).find(r=>r.npcIndex===id&&!r.custom);
 if(!def||Number(def.mapVisible)===0||!row||![row.x,row.z].every(Number.isFinite))fail(NPC_WARP_TEXT.cannot);
 return {map:p.map,x:row.x,z:row.z};
}
// NPC Warp is the Holy Water of Almighty service (premiereitem.csv NpcWarp; 101:187 "Able to use NPC Warp"), refused inside an
// Expedition (101:172); checked at the start and again when the cast completes (the service can end during the cast).
function npcWarpAllowed(world,p){if(!premiumHas(world,p.profile,'npcWarp'))fail(PREMIUM_TEXT.noService);if(partyWarpMember(world,p,'').expedition)fail(NPC_WARP_TEXT.expedition);}
async function mapNpcCommand(world,p,input){
 if(input.operation==='cancel'){const cast=p.smartWarp;if(cast&&(cast.kind!=='mapnpc'||input.nonce!==cast.nonce))fail('That NPC teleport is no longer active.');p.smartWarp=null;return;}
 available(world,p);
 if(input.operation==='begin'){npcWarpAllowed(world,p);mapNpcDestination(world,p,input.npcIndex);p.smartWarp={kind:'mapnpc',npcIndex:input.npcIndex,nonce:randomBytes(32).toString('hex'),readyAt:world.now()+TRAVEL_FREEZE_MS,expiresAt:world.now()+TRAVEL_FREEZE_MS+12000,map:p.map,instanceId:p.instanceId,x:p.x,z:p.z,hp:p.hp,sequence:world.sequence};p.path=[];return;}
 if(input.operation!=='finish')fail('Unknown NPC teleport operation.');const cast=p.smartWarp;
 if(!cast||cast.kind!=='mapnpc'||input.nonce!==cast.nonce)fail('That NPC teleport is no longer active.');
 if(world.now()<cast.readyAt)fail('NPC teleport preparation is not complete.');p.smartWarp=null;
 if(interrupted(world,p,cast))fail('NPC teleport was interrupted.');npcWarpAllowed(world,p);const at=mapNpcDestination(world,p,cast.npcIndex);
 await commitFieldTravel(world,p,at);
}
export async function travelCommand(world,p,input){
 if(!Object.hasOwn(TRAVEL_SCHEMAS,input.type))return false;
 // Official Global guide 62 battle status: "During the Almighty Holy Water premium feature, NPCs and parties cannot be moved" (101:248).
 // Cancelling a running cast stays allowed. "using an NPC is not possible" (40:108) for the NPC travel services below is the central
 // guard (npc-service-guard.mjs, through npcJob -> nearbyNpc).
 if(input.type==='mapnpcwarp'){if(input.operation!=='cancel')assertCombatPremium(world,p);await mapNpcCommand(world,p,input);return true;}
 if(input.type==='smartwarp'){await smartCommand(world,p,input);return true;}
 available(world,p,{teleport:input.operation!=='bind'});
 const tr=world.data.travelData;if(!tr)fail('Original travel tables are unavailable.');
 if(input.operation==='personal-out'||input.operation==='personal-return'){
  if(input.map!==undefined||input.unit!==undefined)fail('Personal portal destinations are server owned.');
  const outward=input.operation==='personal-out',r=requirePersonalPortal(world,p,input.portalId,outward?'origin':'away');
  if(!outward)npcJob(world,p,input.npcIndex,16,input.table);
  const at=outward?boundReturnTarget(world,p.profile):{map:r.map,channel:r.channel,x:r.x,z:r.z};
  const profile=structuredClone(p.profile);profile.personalPortal.stage=outward?'away':'origin';
  const token=p.token,stage=r.stage;
  await commitFieldTravel(world,p,at,profile,{validate:()=>{const current=personalPortalState(world,p);if(world.players.get(p.account)!==p||p.token!==token||current?.id!==r.id||current.stage!==stage)fail('That personal portal is no longer available.');}});return true;
 }
 let at,cost=0,validate;
 if(input.operation==='frontier')at=frontierMove(world,p,input);
 else if(input.operation==='hideout')at=hideoutMove(world,p,input);
 else if(input.operation==='teleport'||input.operation==='sky'){
  const type=input.operation==='sky'?42:2;npcJob(world,p,input.npcIndex,type,input.table);
  const table=type===2?tr.teleports?.[input.table]:tr.skyTeleports?.find(r=>r.id===input.table);
  const row=table?.units?.find(r=>r.unit===input.unit);if(!row)fail('Invalid original teleport destination.');
  if(type===42&&(Number(table.skyQuest??0)!==0||Number(row.skyQuest??0)!==0)){
   validate=()=>{if([table.skyQuest,row.skyQuest].some(v=>Number(v||0)!==0&&Number(v)!==1)||!skyWorldPointOpen(world))fail(SKY_TEXT.closed);};validate();
  }
  if((Number(p.profile.level)||1)<(Number(row.level)||0))fail(type===42?SKY_TEXT.level:'Your level is too low to enter.');
  at=travelLocation(world,row.location);cost=Number(row.cost)||0;
 }else if(input.operation==='bind'){
  npcJob(world,p,input.npcIndex,4,input.table);at=travelLocation(world,input.table);
  if(!at)fail('The original return location is unavailable.');
  const profile=structuredClone(p.profile);profile.returnLocation=input.table;delete profile.returnPoint;p.sceneTransition=true;
  try{const candidate={...p,profile};world.changed(candidate);await world.persist(candidate);for(const key of ['profile','dirty','revision','saveError'])p[key]=candidate[key];}finally{p.sceneTransition=false;}return true;
 }else if(input.operation==='portal'){
  npcJob(world,p,input.npcIndex,16,input.table);
  if(mapInfo(world,p.map)?.flags?.portal===0)fail('Portals are disabled in this map.');
  if(input.map==null)at=boundReturnTarget(world,p.profile);
  else{const portal=tr.portals?.find(r=>r.map===input.map),r=tr.portalArrivals?.find(r=>r.map===input.map);if(!portal||!r)fail('Invalid original portal destination.');at={map:r.map,x:r.x+.5,z:r.y+.5,dirDeg:r.dir||0};}
 }else fail('Unknown NPC travel service.');
 const profile=structuredClone(p.profile);
 if(!Number.isFinite(cost)||cost<0||Number(profile.dil||0)<cost)fail('You do not have enough DIL.');
 destinationAllowed(world,p,at);profile.dil=Number(profile.dil||0)-cost;
 if(world.data.requiresInstance?.(at.map))return world.admitTravelDestination(p,{destination:at,profile,npcIndex:input.npcIndex});
 await commitFieldTravel(world,p,at,profile,{validate});return true;
}
