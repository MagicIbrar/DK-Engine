// Shared-play channels (DK-CHANNELS / MULTI-CHANNEL).
// Field channels = share/channellist.csv (group 15): every map runs one scene per Channel Index (scene.mjs sceneKey
// map#channel), so players, monsters, drops, summons and events of one channel are invisible to another.
// DK channels = share/dkmaplist.csv + NPC job 96 DK_CHANNEL_ENTER (jobIndex = DK map) / 97 DK_CHANNEL_LEAVE
// (jobIndex = home map, 0 = where the player came from). The original moves the client to another server; the host
// models each DK server as its own scene key `dk<DK_Index>` (names 9000|DK_Index) on the same map geometry.
// Readings: a reconnect never resumes a DK session (the client always logs
// into its home server), so a saved dkReturn sends the player home on join; leaving the DK map by any field travel
// leaves the DK channel. DK "PVP Channel" (DK 101) shares the same host PvP pipeline (server/world/pvp.mjs + field-pk); scene isolation is via sceneKey map#dk101. Field IsPvP / peace-zone gates still apply per map row.
import fs from 'node:fs';
import path from 'node:path';
import {nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {worldRoots} from './prepared-roots.mjs';
import {commitFieldTravel,boundReturnTarget,travelCastInterrupted} from './travel.mjs';
import {randomBytes} from 'node:crypto';
import {TRAVEL_FREEZE_MS} from '../../src/config/owner-travel-freeze.js';
import {PREMIUM_TEXT} from '../../src/systems/shops/premium-rules.js';
import {readChannelTables} from './channel-data.mjs';
import {assertNieteChannel,assertCombatChannel} from './niete-services.mjs';
import {leaveParty} from './party.mjs';
import {isDkChannel,validChannel,channelName,movedText,dkMap,dkLocates,dkRespawn,fieldChannel} from '../../src/systems/channels/channel-rules.js';
export {isDkChannel} from '../../src/systems/channels/channel-rules.js';
const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
export const CHANNEL_SCHEMAS={channel:['token','type','operation','channel','npcIndex','locate','nonce']};
// One table set per host (world.data) and per root pair: two hosts with different roots never share channel tables.
const byHost=new WeakMap(),byRoots=new Map();
export function channelData(world){
  if(world?.data?.channels)return world.data.channels;
  const host=world?.data&&typeof world.data==='object'?world.data:null;
  if(host&&byHost.has(host))return byHost.get(host);
  // this host's roots (loadWorldData: prepared generation / explicit / env), then the defaults (server/world/prepared-roots.mjs):
  // <gamedataRoot>/channels.json when prepared; otherwise the same original tables read directly from <dataRoot> (no file required)
  const {dataRoot,gamedataRoot}=worldRoots(world),key=`${path.resolve(gamedataRoot)}|${path.resolve(dataRoot)}`;
  let data=byRoots.get(key);
  if(!data){const file=path.join(gamedataRoot,'channels.json');data=fs.existsSync(file)?JSON.parse(fs.readFileSync(file,'utf8')):readChannelTables(dataRoot);byRoots.set(key,data);}
  if(host)byHost.set(host,data);
  return data;
}
const yawDeg=p=>-(Number(p.yaw)||0)*180/Math.PI||0;
const channelAvailable=row=>row&&row.enabled!==false&&row.available!==false&&row.locked!==true;
export function loginChannelCatalog(world){const field=channelData(world).field.map(row=>({index:row.index,name:row.name,available:!!channelAvailable(row)}));return {field,defaultChannel:field.find(row=>row.index===0&&row.available)?.index??field.find(row=>row.available)?.index??null};}
export function validateLoginChannel(world,target){
  if(target===undefined)return;
  if(!Number.isInteger(target))fail('Choose a field channel listed by this server.');
  const row=fieldChannel(channelData(world),target);if(!row)fail('That field channel is not available on this server.');
  if(!channelAvailable(row))fail('That field channel is locked or offline.',403);
}
export function loginChannel(world,player,target){
  validateLoginChannel(world,target);if(target===undefined||target===player.channel)return player.channel;
  if(player.instanceId||isDkChannel(player.channel))fail('Resume your current run before changing its channel.',403);
  assertNieteChannel(world,player);assertCombatChannel(world,player);return target;
}
function portalJob(world,p,input,type){
  const npcIndex=Number(input.npcIndex);
  const placed=Number.isInteger(npcIndex)?nearbyNpc(world,p,{npcIndex,jobType:type,radius:8}):null;
  const job=placed?.jobs.find(([t])=>Number(t)===type);
  if(!placed||!job||!offersOriginalJob(world,placed,type,job[1]))fail('Stand near the original DK portal.',403);
  return Number(job[1])||0;
}
/** Join: restore the scene channel. A pending dkReturn means the session ended on a DK server -> start at home. */
export function restoreChannel(world,p,instanceId){
  const back=p.dkReturn;
  if(!back)return {channel:0,where:null};
  if(instanceId)return {channel:isDkChannel(back.dk)?back.dk:0,where:null};
  delete p.dkReturn;
  const channel=validChannel(channelData(world),back.channel)&&!isDkChannel(back.channel)?back.channel:0;
  return {channel,where:[back.map,back.x,back.z].every(Number.isFinite)?{map:back.map,x:back.x,z:back.z}:null};
}
/** Revive: a DK map revives on its own DK channel by RespawnType; otherwise the player returns to the field channel. */
export function reviveScene(world,p,premiumAt){
  const channel=p.channel??0;
  if(!isDkChannel(channel))return {at:null,channel};
  const at=premiumAt?null:dkRespawn(channelData(world),p.map,p.x,p.z);
  return at?{at,channel}:{at:null,channel:p.profile.dkReturn?.channel??0,leftDk:true};
}
function moveAllowed(world,p,target){
  const data=channelData(world);
  if(!Number.isInteger(target)||!fieldChannel(data,target))fail('Choose an original channel.');
  if(!channelAvailable(fieldChannel(data,target)))fail('That field channel is locked or offline.',403);
  if(p.instanceId)fail('Leave the current run before changing channel.',403);
  if(isDkChannel(p.channel))fail('Use the original DK portal to return before changing channel.',403);
  if((p.channel??0)===target)fail('You are already on this channel.');
  return data;
}
// Global: changing channel is a 10 s frozen cast (src/config/owner-travel-freeze.js), not instant - a fight
// cannot be escaped by switching channel. 'move' starts the server-owned cast (the same record as the warps, so moving is
// refused meanwhile and damage interrupts it: travel.mjs travelFrozen / tickTravel), 'movefinish' completes it once.
async function move(world,p,input){
  const data=moveAllowed(world,p,input.channel),target=input.channel;
  if(p.smartWarp)fail('Another teleport is being prepared.');
  // a mounted character would see its cast dropped by the next tick (travel.mjs interrupted): refuse it up front, with the
  // original text 102 "You cannot use teleportation while riding a creature." (as the premium warps do). A character mid map
  // change never gets here: SharedWorld.action answers WORLD_BUSY while p.sceneTransition is set.
  if(p.mount)fail(PREMIUM_TEXT.riding);
  p.smartWarp={kind:'channel',channel:target,nonce:randomBytes(32).toString('hex'),readyAt:world.now()+TRAVEL_FREEZE_MS,expiresAt:world.now()+TRAVEL_FREEZE_MS+12000,map:p.map,instanceId:p.instanceId,x:p.x,z:p.z,hp:p.hp,sequence:world.sequence};
  p.path=[];
  return {operation:'cast',channel:target,name:channelName(data,target),nonce:p.smartWarp.nonce,readyAt:p.smartWarp.readyAt};
}
async function moveFinish(world,p,input){
  const cast=p.smartWarp;
  if(!cast||cast.kind!=='channel'||input.nonce!==cast.nonce)fail('That channel change is no longer active.');
  if(world.now()<cast.readyAt)fail('The channel change is not ready yet.');
  p.smartWarp=null;   // one use
  if(travelCastInterrupted(world,p,cast))fail('The channel change was interrupted.');
  const data=moveAllowed(world,p,cast.channel),target=cast.channel;
  await commitFieldTravel(world,p,{map:p.map,x:p.x,z:p.z,dirDeg:yawDeg(p),channel:target});
  return {operation:'move',channel:target,name:channelName(data,target),text:movedText(data,target)};
}
function moveCancel(world,p,input){const cast=p.smartWarp;if(cast&&(cast.kind!=='channel'||input.nonce!==cast.nonce))fail('That channel change is no longer active.');p.smartWarp=null;return {operation:'movecancel'};}
async function dkEnter(world,p,input){
  const data=channelData(world);
  if(p.instanceId)fail('Leave the current run first.',403);
  if(isDkChannel(p.channel))fail('You are already on a DK channel.',403);
  const map=portalJob(world,p,input,96),row=dkMap(data,map),locates=dkLocates(data,map);
  if(!row||!locates.length)fail('This DK portal has no original dkmaplist row.',503);
  if(row.costItems.length||row.cashCostItems.length)fail('This DK portal charges items that shared play does not model.',503);
  if(locates.length>1&&input.locate==null)fail('Choose a DK channel.');
  const index=input.locate==null?0:input.locate,pick=Number.isInteger(index)?locates[index]:null;
  if(!pick)fail('Choose an original DK channel.');
  const profile=structuredClone(p.profile);
  profile.dkReturn={map:p.map,x:p.x,z:p.z,dirDeg:yawDeg(p),channel:p.channel??0,dk:pick.channel};
  await commitFieldTravel(world,p,{map,x:row.locate[0]+.5,z:row.locate[1]+.5,dirDeg:0,channel:pick.channel},profile);
  // Current Global Party guide4: field party ends when its member enters a DK server.
  // Do this only after durable travel; a rejected entry must retain its entire party.
  if(p.partyId)leaveParty(world,p);
  return {operation:'dkenter',channel:pick.channel,name:pick.name,map,text:movedText(data,pick.channel)};
}
async function dkLeave(world,p,input){
  const data=channelData(world);
  if(p.instanceId)fail('Leave the current run first.',403);
  if(!isDkChannel(p.channel))fail('You are not on a DK channel.',403);
  const home=portalJob(world,p,input,97),back=p.profile.dkReturn,channel=back&&!isDkChannel(back.channel)?back.channel??0:0;
  let at=null;
  if(back&&(!home||Number(back.map)===home))at={map:back.map,x:back.x,z:back.z,dirDeg:back.dirDeg||0};
  else if(home){const r=world.data.travelData?.portalArrivals?.find(a=>a.map===home);if(r)at={map:home,x:r.x+.5,z:r.y+.5,dirDeg:r.dir||0};
    else{const scene=await world.map(home,null,channel);if(Number.isFinite(scene.start?.x))at={map:home,x:scene.start.x,z:scene.start.z,dirDeg:0};}}
  at||=boundReturnTarget(world,p.profile);
  await commitFieldTravel(world,p,{...at,channel});
  return {operation:'dkleave',channel,name:channelName(data,channel),map:p.map,text:movedText(data,channel)};
}
export async function channelCommand(world,p,input){
  if(['move','movefinish','dkenter','dkleave'].includes(input.operation)){assertNieteChannel(world,p);assertCombatChannel(world,p);}   // guide62 / 70:164
  if(input.operation==='list'){const data=channelData(world);return {operation:'list',channel:p.channel??0,field:data.field.map(c=>({index:c.index,name:c.name}))};}
  if(input.operation==='move')return move(world,p,input);
  if(input.operation==='movefinish')return moveFinish(world,p,input);
  if(input.operation==='movecancel')return moveCancel(world,p,input);
  if(input.operation==='dkenter')return dkEnter(world,p,input);
  if(input.operation==='dkleave')return dkLeave(world,p,input);
  fail('Unknown channel operation.');
}
