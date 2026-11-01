// Renew spectators share the controller's actual battle scene. They never enter
// its participant registry. Native data + explicit adaptation choices are kept
// separate in engine-chosen-siege-renew-observer.js.
import {RENEW_OBSERVER_CHOSEN as C} from '../../src/config/engine-chosen-siege-renew-observer.js';
import {siegeRenewControllerData,tickSiegeRenew,exitSiegeRenewScene,placeSiegeRenewActor} from './siege-renew-controller.mjs';
import {registerObserverMode,isObserver} from './observers.mjs';
import {nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {socialRef} from './social-state.mjs';
import {stageInstanceMembers} from './instances.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {initializePets} from './pets.mjs';
import {sceneKey} from './scene.mjs';
import {pvpOpponents} from './pvp.mjs';

const fail=(message,status=409)=>{throw Object.assign(Error(message),{status,code:'SIEGE_RENEW_REFUSED'});};
const key=p=>String(p.characterId??p.profile?.characterId??p.id);
export const isRenewObserverVenue=v=>/^renew-(193|194|195)$/.test(String(v));
const live=(world,map)=>world.siegeRenewLive?.battles.get(Number(map));
const active=(world,b)=>!!b&&b.phase==='battle'&&world.now()<b.endAt;
const present=(world,p)=>!!p&&world.players.get(p.account)===p&&!p.leaving;
export function renewObserverRecord(world,p){
  const b=live(world,p?.map),s=b?.spectators?.get(p?.id);
  return s&&s.account===p.account&&s.actor===p&&present(world,p)&&p.instanceId===b.instanceId?s:null;
}
registerObserverMode({is:(world,p)=>!!renewObserverRecord(world,p),actions:new Set(C.actions)});
export function renewObserverAreas(castle){
  if(!castle)return [];
  const rows=C.areaTypes.flatMap(type=>castle.locations.filter(a=>a.type===type&&a.map===castle.map));
  const out=rows.map((a,index)=>({index,x:a.x,z:a.z,dirDeg:a.dirDeg,name:a.name||`Area ${index+1}`}));
  if(C.includeGuardian&&castle.crystal)out.push({index:out.length,x:castle.crystal.x+.5,z:castle.crystal.z+.5,name:castle.crystal.def?.name||'Guardian Stone'});
  return out;
}
export function pruneRenewObservers(world,b){
  for(const[id,s]of b.spectators||[]){
    const p=world.players.get(s.account);
    if(p===s.actor&&!p.leaving&&(p.sceneTransition||p.map===b.map&&p.instanceId===b.instanceId))continue;
    b.spectators.delete(id);
    if(world.observerSeats?.get(s.key)===s)world.observerSeats.delete(s.key);
  }
}
export function forgetRenewObserver(world,b,p){
  const s=b.spectators?.get(p.id);if(s?.actor!==p)return false;
  b.spectators.delete(p.id);
  if(world.observerSeats?.get(key(p))===s)world.observerSeats.delete(key(p));
  (world.observerLeftAt||=new Map()).set(key(p),world.now());
  return true;
}
export function renewObserverInfo(world,p){
  const data=siegeRenewControllerData(world),venues={},waitMs={};
  for(const c of data?.castles.values()||[]){
    const b=live(world,c.map);if(b)pruneRenewObservers(world,b);
    const id=`renew-${c.map}`,areas=renewObserverAreas(c);
    venues[id]={key:id,name:c.name,map:c.map,npcIndex:c.entranceNpc,max:data.cfg.observerCapacity,count:b?.spectators?.size||0,
      available:active(world,b)&&areas.length>0,enterEnableMs:C.enterEnableMs,cameraSpeed:C.cameraSpeed,areas,ticket:C.ticket,endAt:b?.endAt||null};
    const left=world.observerLeftAt?.get(key(p));waitMs[id]=left==null?0:Math.max(0,left+C.enterEnableMs-world.now());
  }
  return {venues,waitMs};
}
function guildIsFighting(world,p,b){
  const ref=socialRef(p),guild=Object.values(world.socialState?.guilds||{}).find(g=>g.members?.some(m=>m.ref===ref));
  return !!guild&&(world.socialState?.siegeRenew?.castles?.[b.map]?.owner?.guild===guild.id||[...b.participants.values()].some(r=>r.guild===guild.id));
}
export function enterRenewObserver(world,p,input){return world.serializeAccount(p.account,()=>enterOwned(world,p,input));}
async function enterOwned(world,p,input){
  await tickSiegeRenew(world,{force:true});
  const map=Number(String(input.venue).slice(6)),data=siegeRenewControllerData(world),c=data?.castles.get(map),id=Number(input.npcIndex);
  const npc=Number.isInteger(id)&&nearbyNpc(world,p,{npcIndex:id,jobType:36,jobIndex:map,radius:C.npcRadius});
  if(!c||id!==c.entranceNpc||!npc||!offersOriginalJob(world,npc,36,map))fail('Stand near the original castle entrance.',403);
  const b=live(world,map);if(!active(world,b))fail('siege:290:132');
  if(p.mount)fail('siege:290:133');
  if(guildIsFighting(world,p,b)||b.participants.has(p.id))fail('siege:241:16',403);
  if(!present(world,p)||p.dead||p.sceneTransition||p.tradeId||p.tradeCommitting||p.instanceId||isObserver(world,p)||pvpOpponents(world,p).length)fail('siege:290:131');
  pruneRenewObservers(world,b);const registry=b.spectators||=new Map();
  if(registry.size>=data.cfg.observerCapacity)fail('siege:290:134');
  const left=world.observerLeftAt?.get(key(p));if(left!=null&&world.now()<left+C.enterEnableMs)fail('Please wait a moment before entering Observer mode again.',429);
  const areas=renewObserverAreas(c),point=areas[0]&&b.scene.nearest(areas[0].x,areas[0].z);
  if(!point||world.maps.get(sceneKey(map,b.instanceId))!==b.scene)fail('siege:290:129',503);
  const profile=structuredClone(p.profile);initializePets(profile);
  if(!new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now}).remove(C.ticket,1))fail('siege:241:12');
  // Restart/relogin must recover to the authored return, never a stale siege.
  profile.instance={id:b.instanceId,kind:'siegeRenew',map,exit:{map:c.back.map,x:c.back.x,z:c.back.z}};
  delete profile.observer;
  const from={map:c.back.map,x:c.back.x,z:c.back.z},s={actor:p,actorId:p.id,account:p.account,key:key(p),venue:input.venue,map,instanceId:b.instanceId,from,since:world.now(),camera:false};
  registry.set(p.id,s);const transition=p.sceneTransition,before={map:p.map,channel:p.channel??0,instanceId:p.instanceId||null};p.sceneTransition=true;
  let committed=false;
  try{
    const staged=stageInstanceMembers(world,[p],[profile]),q=staged.candidates[0];
    Object.assign(q,{map,channel:0,instanceId:b.instanceId,x:point.x,z:point.z,path:[],mount:null,pet:null});
    world.changed(q);await world.persist(q);p.channel=0;await staged.commit();committed=true;
    p.smartWarp=null;p.attackTarget=null;p.yaw=-(areas[0].dirDeg||0)*Math.PI/180;
    (world.observerSeats||=new Map()).set(s.key,s);
  }finally{
    p.sceneTransition=transition;
    // A secondary progress save may fail after scene publication. Preserve the
    // hidden seat in that case so the normal end/exit retry can recover safely.
    if(!committed&&p.instanceId!==b.instanceId)registry.delete(p.id);
    else (world.observerSeats||=new Map()).set(s.key,s);
  }
  world.emit(before.map,{type:'leave',actorId:p.id,channel:before.channel,instanceId:before.instanceId});
  world.emit(map,{type:'join',actorId:p.id,instanceId:b.instanceId});
}
export function warpRenewObserver(world,p,input){return world.serializeAccount(p.account,()=>warpOwned(world,p,input));}
async function warpOwned(world,p,input){
  const s=renewObserverRecord(world,p),b=live(world,p.map);if(!s)fail('You are not observing.');
  if(!active(world,b))fail('siege:290:132');if(!s.camera)fail('siege:241:9');
  const c=siegeRenewControllerData(world)?.castles.get(b.map),a=Number.isInteger(input.area)&&renewObserverAreas(c).find(a=>a.index===input.area);
  if(!a)fail('Choose an observer area.',400);
  const staged=stageInstanceMembers(world,[p],[structuredClone(p.profile)]),q=staged.candidates[0],transition=p.sceneTransition;
  // Forced movement revisions are mutable too; do not publish them when the
  // destination's profile write fails. A spectator remains in the same scene.
  q.mv=p.mv?structuredClone(p.mv):p.mv;p.sceneTransition=true;
  try{
    if(!placeSiegeRenewActor(staged.world,b,q,a))fail('siege:290:129',503);
    await world.persist(q);await staged.commit();
  }finally{
    // commit can report a secondary earned-progress write failure after the
    // durable destination was already published; retain its matching revision.
    if(p.map===q.map&&p.instanceId===q.instanceId&&p.x===q.x&&p.z===q.z){p.mv=q.mv;p.yaw=q.yaw;}
    p.sceneTransition=transition;
  }
}
export function exitRenewObserver(world,p){return world.serializeAccount(p.account,()=>exitOwned(world,p));}
async function exitOwned(world,p){
  const s=renewObserverRecord(world,p),b=live(world,p.map);if(!s||!b)fail('You are not observing.');
  const c=siegeRenewControllerData(world)?.castles.get(b.map);await exitSiegeRenewScene(world,b,c,p);
}
