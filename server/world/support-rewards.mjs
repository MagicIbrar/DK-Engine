// Reward Event ("Connect Reward") and Attendance Rewards on the host.
// Rules and their data sources: src/systems/extras/connectreward-rules.js and attendance-rules.js (shared with the client).
// Server-authoritative: clients send intent only ({type:'connectreward', event} / {type:'attendance', set, no}); progress
// comes from the host tick (connected seconds) and the canonical monster death hook (core.mjs reward()); a claim puts the
// original reward item straight into the bag (no mail: server/world/mail-policies.mjs refuses attendance mail) in one
// durable profile commit. Reward Event state is per character (profile.life.connectReward); Attendance state is per
// account (profile.accountFeatures.attendance, saved to the account like shared storage).
import {AuthoritativeInventory} from './inventory.mjs';
import {commitLife,serializeLife,validateLife,lifeError} from './life-transactions.mjs';
import {createQuestContext} from './quests.mjs';
import * as CR from '../../src/systems/extras/connectreward-rules.js';
import * as AT from '../../src/systems/extras/attendance-rules.js';

export const SUPPORT_REWARD_SCHEMAS={connectreward:['token','type','event'],attendance:['token','type','set','no']};
const FLUSH_SECONDS=5;
const cache=new WeakMap(),deaths=new WeakMap();
/** Parsed tables of the loaded gamedata (boxes.json connectReward / attendance, built from the original CSVs). */
export function supportRewardTables(world){
 const data=world.data;if(!data)return null;
 if(!cache.has(data)){const boxes=data.progression?.boxes||{};cache.set(data,{events:CR.connectRewardEvents(boxes.connectReward),attendance:AT.attendanceTables(boxes.attendance)});}
 return cache.get(data);
}
const message=key=>(CR.REWARD_MESSAGES[key]||CR.REWARD_MESSAGES.unknown).text;

/** Host tick: connected seconds for the Reward Event (Type 1) and today's attendance mission, flushed every 5 s. */
export function tickSupportRewards(world,p,dt){
 if(p.leaving||p.commandActive||p.sceneTransition||!Number.isFinite(dt)||dt<=0)return;
 const t=supportRewardTables(world);if(!t)return;
 p._supportSeconds=(p._supportSeconds||0)+dt;
 if(p._supportSeconds<FLUSH_SECONDS)return;
 const seconds=Math.floor(p._supportSeconds);p._supportSeconds-=seconds;
 const now=world.now();let changed=false;
 if(t.events.length){
  const raw=p.profile.life?.connectReward,st=CR.normalizeState(raw,now);
  if(CR.addOnline(st,t.events,seconds)||JSON.stringify(st)!==JSON.stringify(raw)){p.profile.life||={};p.profile.life.connectReward=st;changed=true;}
 }
 if(AT.activeSet(t.attendance,now)){
  const raw=p.profile.accountFeatures?.attendance,st=AT.normalizeState(raw,now);
  if(AT.addSeconds(t.attendance,st,now,seconds)||JSON.stringify(st)!==JSON.stringify(raw)){p.profile.accountFeatures||={};p.profile.accountFeatures.attendance=st;changed=true;}
 }
 if(changed)world.changed(p);
}

/** Canonical death hook (core.mjs reward(), basic attacks and skills): one Type 2 kill per monster death. */
export function recordSupportRewardKill(world,p,m){
 if(p.leaving||!m?.dead)return false;
 const t=supportRewardTables(world);if(!t?.events.length)return false;
 if(deaths.has(m)&&deaths.get(m)===m.respawnAt)return false;deaths.set(m,m.respawnAt);
 const raw=p.profile.life?.connectReward,st=CR.normalizeState(raw,world.now());
 if(!CR.countKill(st,t.events,Number(p.profile.level),Number(m.def?.level)))return false;
 p.profile.life||={};p.profile.life.connectReward=st;world.changed(p);return true;
}

/** Claim the current stage of a Reward Event line, or today's Attendance Rewards cell. */
export function supportRewardCommand(world,p,input){return serializeLife(p,async()=>{
 validateLife(input,SUPPORT_REWARD_SCHEMAS);
 const t=supportRewardTables(world),db=world.data.itemDB;
 if(!t||!db)lifeError(message('noItem'));
 if(p.dead||p.leaving||p.sceneTransition)lifeError('Rewards are unavailable while dead or changing maps.');
 const now=world.now(),profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
 const hasItem=i=>!!db.def(i);
 let reward;
 if(input.type==='connectreward'){
  if(!Number.isSafeInteger(input.event))lifeError(message('unknown'));
  const st=CR.normalizeState(profile.life?.connectReward,now);
  const check=CR.checkClaim(t.events,st,input.event,{countItem:i=>inv.count(i),hasItem});
  if(!check.ok)lifeError(message(check.error));
  if(!inv.add(check.step.item,check.step.stack))lifeError(message('bagFull'));
  CR.markClaimed(st,check.event);profile.life||={};profile.life.connectReward=st;
  reward={kind:'connectreward',event:check.event.index,stage:check.stage+1,itemIndex:check.step.item,count:check.step.stack};
 }else{
  if(!Number.isSafeInteger(input.set)||!Number.isSafeInteger(input.no))lifeError(message('unknown'));
  const st=AT.normalizeState(profile.accountFeatures?.attendance,now);
  const check=AT.checkClaim(t.attendance,st,now,input.set,input.no,{hasItem});
  if(!check.ok)lifeError(message(check.error));
  if(!inv.add(check.day.item,check.day.count))lifeError(message('bagFull'));
  AT.markClaimed(st,check.set,now);profile.accountFeatures={...(profile.accountFeatures||{}),attendance:st};
  reward={kind:'attendance',set:check.set.index,no:check.day.no,itemIndex:check.day.item,count:check.day.count};
 }
 // Carried collect objectives are recounted on the staged profile before the same durable write (as life events do).
 const quests=world.data.progression?.quests?createQuestContext(world,p,{profile,inventory:inv,commitToPlayer:false}):null;quests?.engine.recountCollect(null,true);
 await commitLife(world,p,profile);quests?.commit();
 return reward;
});}
