import {AuthoritativeInventory} from './inventory.mjs';
import {commitLife,serializeLife,validateLife,lifeError as fail} from './life-transactions.mjs';
import {mapFor} from './scene.mjs';
import {createQuestContext} from './quests.mjs';
import {recordTitleKill} from './titles.mjs';
import {randomUUID} from 'node:crypto';
export const LIFE_EVENT_SCHEMAS={lifeevent:['token','type','event','uid','revision','requestId']};
const deaths=new WeakMap(),MAX_RECEIPTS=128;
const integer=n=>Number.isSafeInteger(n)&&n>=0;
function rows(world){const value=world.data.lifeEvents?.virus;return Array.isArray(value)?value:[];}
function validRow(r){return r&&integer(r.Index)&&r.Index>0&&[0,1].includes(r.Type)&&integer(r.ItemIndex)&&r.ItemIndex>0&&integer(r.Object_Value)&&r.Object_Value>0&&integer(r.LevelCap)&&r.LevelCap>0&&['Increase_Normal','Increase_Event_0','Increase_Event_1','Event_Monster_Min_0','Event_Monster_Max_0','Event_Monster_Min_1','Event_Monster_Max_1','RewardItem_Index','RewardMosnter_Index'].every(k=>integer(r[k]))&&[0,1].every(k=>r['Event_Monster_Min_'+k]<=r['Event_Monster_Max_'+k]);}
function active(world,profile){
  for(const r of rows(world)){if(!validRow(r))return null;const item=profile.inventory?.find(i=>i.itemIndex===r.ItemIndex&&Number.isSafeInteger(i.count)&&i.count>0&&(!i.expiresAt||Number.isFinite(i.expiresAt)&&i.expiresAt>world.now()));if(item)return {r,item};}return null;
}
function state(profile){const e=profile.life?.events;if(e!=null&&(typeof e!=='object'||Array.isArray(e)||!e.virus||typeof e.virus!=='object'||Array.isArray(e.virus)))fail('Unsupported event progress state.');return e||{virus:{},revision:0,receipts:[]};}
// Called only by the canonical death reward hook, before its same profile save.
export function recordLifeEventKill(world,p,m){
  if(p.leaving||p.sceneTransition||!m.dead||m.hp!==0||!Number.isFinite(m.respawnAt)||mapFor(world,p)?.monsters?.get(m.id)!==m)return false;
  recordTitleKill(world,p,m);   // EVENT-MODES: Type 1 mission titles (server/world/titles.mjs)
  const a=active(world,p.profile);if(!a)return false;
  let event;try{event=state(p.profile);}catch{return false;}const key=String(a.r.Index),before=event.virus[key]??0;
  if(!integer(before)||before>a.r.Object_Value||!integer(event.revision??0)||(event.revision??0)>=Number.MAX_SAFE_INTEGER)return false;
  let marker=deaths.get(m);if(!marker||marker.time!==m.respawnAt){marker={time:m.respawnAt,owners:new Set()};deaths.set(m,marker);}if(marker.owners.has(p.id))return false;marker.owners.add(p.id);
  const r=a.r,index=m.monsterIndex??m.def?.index,level=p.profile.level;
  if(!Number.isSafeInteger(index)||!Number.isSafeInteger(level))return false;
  const add=r.Event_Monster_Min_0&&index>=r.Event_Monster_Min_0&&index<=r.Event_Monster_Max_0?r.Increase_Event_0:r.Event_Monster_Min_1&&index>=r.Event_Monster_Min_1&&index<=r.Event_Monster_Max_1?r.Increase_Event_1:level<=r.LevelCap?r.Increase_Normal:0;
  const next=Math.min(r.Object_Value,before+add);if(next===before)return false;
  p.profile.life||={};p.profile.life.events={...event,virus:{...event.virus,[key]:next},revision:(event.revision??0)+1};world.changed(p);return true;
}
export function lifeEventCommand(world,p,input){return serializeLife(p,async()=>{
  validateLife(input,LIFE_EVENT_SCHEMAS);
  if(!integer(input.event)||!integer(input.revision)||typeof input.uid!=='string'||!input.uid.length||input.uid.length>100||typeof input.requestId!=='string'||!/^[a-zA-Z0-9_-]{8,80}$/.test(input.requestId))fail('Send the selected event item and durable intent only.');
  const current=state(p.profile),receipts=current.receipts??[],signature=JSON.stringify([input.event,input.uid,input.revision]);
  if(!integer(current.revision??0)||(current.revision??0)>=Number.MAX_SAFE_INTEGER||!Array.isArray(receipts)||receipts.length>MAX_RECEIPTS||receipts.some(r=>!r||typeof r.id!=='string'||typeof r.signature!=='string'||!integer(r.revision)))fail('Unsupported event receipt state.');
  const receipt=receipts.find(r=>r.id===input.requestId);if(receipt){if(receipt.signature!==signature)fail('That event request ID has another intent.');return {receipt:structuredClone(receipt),replayed:true};}
  if(p.dead||p.leaving||p.sceneTransition)fail('Event rewards are unavailable while dead or changing maps.');
  if(input.revision!==(current.revision??0))fail('Event progress changed. Refresh the reward first.');
  const a=active(world,p.profile);if(!a||a.r.Index!==input.event||a.item.uid!==input.uid)fail('Choose the currently active owned event item.');
  const r=a.r;
  // Type 0 = RewardItem_Index; Type 1 = summon RewardMosnter_Index next to the player
  // (Global client src/systems/life/events.js _reward Trace + string 2300:8).
  const type0=r.Type===0&&r.RewardItem_Index&&!r.RewardMosnter_Index&&!!world.data.itemDB?.def(r.RewardItem_Index);
  const type1=r.Type===1&&r.RewardMosnter_Index&&!r.RewardItem_Index&&!!world.data.monsterDef?.(r.RewardMosnter_Index);
  if(!type0&&!type1)fail('This event reward is not a recovered Type 0 item or Type 1 Trace spawn.');
  const value=current.virus[String(r.Index)]??0;if(!integer(value)||value!==r.Object_Value)fail('The original event objective is not complete.');
  if(p.profile.inventory.filter(i=>i.uid===input.uid).length!==1)fail('The selected event item is ambiguous.');
  const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random}),item=profile.inventory.find(i=>i.uid===input.uid);
  if(!inv.consumeEntry(item,1))fail('The selected event item could not be consumed.');
  let record,spawned=null;
  if(type0){
    if(!inv.add(r.RewardItem_Index,1))fail('Make bag space for the original event reward.');
    record={id:input.requestId,signature,event:r.Index,itemIndex:r.RewardItem_Index,count:1,revision:input.revision+1};
  }else{
    const def=world.data.monsterDef(r.RewardMosnter_Index);
    const map=mapFor(world,p);
    if(!map)fail('Event Trace spawn needs the player on a map.');
    const rnd=typeof world.random==='function'?world.random():Math.random();
    const ang=rnd*Math.PI*2;
    const hx=p.x+Math.cos(ang)*3,hz=p.z+Math.sin(ang)*3;
    const near=map.collision?.nearestWalkable?.(hx,hz,6)||(typeof map.nearest==='function'?map.nearest(hx,hz):null)||{x:p.x+1,z:p.z};
    if(!Number.isFinite(near.x)||!Number.isFinite(near.z))fail('Event Trace spawn found no walkable point near the player.');
    const id=`lifeevent:${p.id}:${randomUUID()}`;
    spawned={id,map:p.map,instanceId:p.instanceId||null,monsterIndex:r.RewardMosnter_Index,name:def.name,x:near.x,z:near.z,hp:def.hp,maxHp:def.hp,home:{x:near.x,z:near.z},dead:false,targetId:null,attackAt:0,respawnAt:0,respawnSec:Infinity,oneShot:true,lifeEventSpawn:true,def};
    map.monsters.set(id,spawned);
    record={id:input.requestId,signature,event:r.Index,monsterIndex:r.RewardMosnter_Index,spawnId:id,revision:input.revision+1};
  }
  profile.life||={};profile.life.events={...current,virus:{...current.virus,[String(r.Index)]:0},revision:record.revision,receipts:[...receipts.slice(-(MAX_RECEIPTS-1)),record]};
  const quests=createQuestContext(world,p,{profile,inventory:inv,commitToPlayer:false});quests?.engine.recountCollect(null,true);
  await commitLife(world,p,profile);quests?.commit();
  world.emit(p.map,{type:'lifeevent',actorId:p.id,event:r.Index,...(spawned?{monsterId:spawned.id,monsterIndex:spawned.monsterIndex,x:spawned.x,z:spawned.z}:{})});
  return {receipt:structuredClone(record),replayed:false};
});}
