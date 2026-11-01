import {PHANTOM_CASTLE as C} from '../../src/config/engine-chosen-phantom-castle.js';
import {serverDayKey} from '../../src/game/server-time.js';
import {zutoRegistration} from './urban-warfare-controller.mjs';
import {nearbyNpc,isCustomScene} from './npc-services.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {serializeLife,commitLife} from './life-transactions.mjs';
import {createInstance,stageInstanceMembers} from './instances.mjs';
import {sceneKey} from './scene.mjs';
import {prepareDungeon} from './dungeons.mjs';
import {progressDekaPass} from './dekapass.mjs';

const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
function available(world,p,input) {
 if(world.players.get(p.account)!==p||p.leaving||p.dead||p.instanceId||p.sceneTransition||
    p.tradeId||p.charTradeId||p.mount||p.fishing||p.pcShopOpen||p.progressCommitting)
  fail('Finish your current activity before entering Phantom Castle.');
 const reg=zutoRegistration(world,p),lobby=reg?.side==='red'?651:reg?.side==='blue'?652:null;
 if(!lobby||p.map!==lobby||isCustomScene(world,p.map)||Number(input.npc)!==C.npc||
    !nearbyNpc(world,p,{npcIndex:C.npc,radius:C.radius}))
  fail('Talk to the Checkpoint in your registered Zuto lobby.');
 const d=world.data.dungeonData?.dg?.dungeons?.[String(C.map)];
 if(!d||d.keeper!=='SOLO'||d.floors?.length!==1||d.floors[0]!==C.map||
    d.expireTime*60!==C.durationSec||!world.data.monsterDef?.(C.boss)||
    !world.data.itemDB?.def?.(C.timedTicket))fail('Original Phantom Castle data is unavailable.',503);
 const [min,max]=d.entry.levels||[];
 if(p.profile.level<min||p.profile.level>max)fail('Phantom Castle requires level 170–250.');
 return {reg,lobby,d};
}
function state(world,profile) {
 const day=serverDayKey(world.now()),used=profile.phantomTickets?.day===day?Number(profile.phantomTickets.issued)||0:0;
 const inv=new AuthoritativeInventory(structuredClone(profile),world.data.itemDB,{now:world.now});
 return {day,used,remaining:Math.max(0,C.issuesPerDay-used),cost:C.cost,periodSec:C.periodSec,
  tickets:inv.count(C.timedTicket)+inv.count(C.rewardTicket)};
}
export function phantomCastleCommand(world,p,input) {
 return serializeLife(p,async()=>{
  const {reg,lobby,d}=available(world,p,input),s=state(world,p.profile);
  if(input.operation==='phantom-info')return {phantom:s};
  if(!['phantom-ticket','phantom-enter'].includes(input.operation))fail('Choose a Phantom Castle action.');
  const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
  if(input.operation==='phantom-ticket') {
   if(s.tickets)fail('You already have an Admission Ticket.');
   if(!s.remaining)fail('You have used today’s three ticket issuances.');
   if(inv.dil<C.cost)fail('You need 200,000 DIL.');
   if(!inv.add(C.timedTicket,1,{period:C.periodSec}))fail('Your inventory is full.');
   inv.addDil(-C.cost);profile.phantomTickets={day:s.day,issued:s.used+1};
   await commitLife(world,p,profile);
   return {phantom:{...state(world,p.profile),issued:true}};
  }
  const ticket=inv.count(C.timedTicket)?C.timedTicket:C.rewardTicket;
  if(!inv.remove(ticket,1))fail('You need an unexpired Phantom Castle Admission Ticket.');
  const exit=d.exit.to.find(row=>Number(row.map)===lobby);
  if(!exit)fail('The original Phantom Castle return destination is unavailable.',503);
  const transition=p.sceneTransition;p.sceneTransition=true;
  const staged=stageInstanceMembers(world,[p],[profile]);let instance;
  try {
   instance=await createInstance(staged.world,{map:C.map,members:staged.candidates,kind:'dungeon',
    exit:{map:lobby,x:Number(exit.x)+.5,z:Number(exit.y)+.5},durationMs:C.durationSec*1000});
   instance.admitting=true;
   await prepareDungeon(staged.world,instance,String(C.map),0,staged.candidates[0]);
   if(instance.director?.plan?.name!=='phantom-castle'||!instance.director.phantomPrepared||instance.director.stages.length!==1)
    fail('The Phantom Castle encounter could not be prepared.',503);
   if(world.players.get(p.account)!==p||p.leaving||zutoRegistration(world,p)?.side!==reg.side)
    fail('Your Zuto registration changed. Try entering again.',409);
   progressDekaPass(staged.world,staged.candidates[0],2,16,C.map,1);
   await world.persistMany(staged.candidates);await staged.commit();
   instance.acting=p;instance.admitting=false;
   return {phantom:{entered:true,map:C.map}};
  } catch(error) {
   if(instance){instance.director?.dispose();world.instances.delete(instance.id);world.maps.delete(sceneKey(C.map,instance.id));}
   throw error;
  } finally {p.sceneTransition=transition;}
 });
}
