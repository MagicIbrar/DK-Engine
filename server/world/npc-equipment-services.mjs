import {Equipment} from '../../src/systems/items/equip.js';
import {isStone,socketable,stoneFits} from '../../src/systems/items/ui/socket.js';
import {brandable,optCode} from '../../src/systems/items/ui/enchant.js';
import {upgradeRow} from '../../src/systems/items/ui/upgrade.js';
import {documentedSocketLimit} from '../../src/systems/items/socket-capacity.js';
import {npcPlacements,offersOriginalJob} from './npc-services.mjs';
import {npcReachableApproach} from './npc-navigation.mjs';
import {mapFor} from './scene.mjs';
import {commitLife,serializeLife} from './life-transactions.mjs';
import {npcEquipmentBenefit} from './npc-builds.mjs';
import {protectedNpcEquipmentUids as reservedEquipmentUids} from './npc-equipment-ownership.mjs';

// ENGINE-CHOSEN finite objectives. Native catalog rows, owned inputs, prices,
// requirements, success/failure and durable ordinary actions remain authoritative.
export const NPC_EQUIPMENT_POLICY=Object.freeze({deadlineMs:60000,cooldownMs:15000,retryMs:2000});
const own=p=>p?.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile.authority==='server';
const gear=d=>!!d?.slot&&!['pet','vehicle','costume'].includes(d.slot);
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const active=(i,now)=>!i.expiresAt||i.expiresAt>now;
const taskOf=p=>{const t=p.profile.npcEquipment;return t?.version===1&&t.policy==='ENGINE-CHOSEN'&&((t.phase==='cooldown'&&Number.isFinite(t.retryAt))||(t.phase==='working'&&Number.isFinite(t.deadline)&&t.plan?.action&&Array.isArray(t.plan.inputs)))?t:null;};
const flights=new WeakMap();
function context(world,p){const db=world.data.itemDB;if(!db||!world.data.itemUseData?.tables)return null;db.T=world.data.itemUseData.tables;
 const eq=new Equipment({db,game:{save:structuredClone(p.profile)}}),bag=(p.profile.inventory||[]).filter(i=>active(i,world.now()));
 const targets=[...eq.worn().map(r=>({item:r.inst,slot:r.slot})),...bag.map(item=>({item,slot:null}))].filter(({item,slot:wornSlot})=>{const d=db.def(item.itemIndex),benefit=npcEquipmentBenefit(world,p,item);return gear(d)&&!d.customId&&!d.custom&&d.index<900000000&&active(item,world.now())&&benefit&&(wornSlot!==null||benefit.benefit>0)&&eq.slotsFor(d).some(slot=>eq.check(item,slot,p.stats).ok);});
 return {db,eq,bag,targets};}
function location(world,p,role){const map=mapFor(world,p);return npcPlacements(world,p.map).filter(n=>n.roles.includes(role)).sort((a,b)=>distance(p,a)-distance(p,b)).map(n=>{const endpoint=npcReachableApproach(map,p,n,12);return endpoint&&{at:{map:p.map,...endpoint},serviceAt:{map:p.map,x:n.x,z:n.z,npc:n.npcIndex},near:distance(p,n)<=12};}).find(Boolean)||null;}
function local(p){return {at:{map:p.map,x:p.x,z:p.z},serviceAt:{map:p.map,x:p.x,z:p.z},near:true};}
function make(kind,target,action,at,inputs=[],cost=0){return {kind,uid:target?.item.uid||null,slot:target?.slot??null,action,...at,inputs,cost,provenance:'native owned target/input/table; ordinary authority',policy:'ENGINE-CHOSEN objective priority'};}
function count(p,index){return (p.profile.inventory||[]).reduce((n,i)=>n+(i.itemIndex===index?(i.count||1):0),0);}
function fingerprint(p,plan){const all=[...(p.profile.inventory||[]),...Object.values(p.profile.equip?.items||{})],target=all.find(i=>i.uid===plan.uid);
 return JSON.stringify({target:target&&[target.itemIndex,target.rnd,target.brand,target.sockets],inputs:plan.inputs.map(uid=>{const i=all.find(i=>i.uid===uid);return [uid,i?.itemIndex,i?.count??(i?1:0)];}),payment:plan.cost>0?p.profile.dil:null,purchase:plan.action.type==='shopbuy'?count(p,plan.action.itemIndex):null});}
export function protectedNpcEquipmentUids(world,p){return reservedEquipmentUids(world,p);}

function buy(world,p,c,{needed,uid=null,targetByItem,gearOnly=false,offer}={}){const catalog=world.data.shopData?.shops;if(!catalog)return null;const candidates=[];
 for(const placed of npcPlacements(world,p.map))for(const job of catalog.npcs?.[placed.npcIndex]?.jobs||[]){const type=Number(job.jobType),shop=Number(job.shop??job.jobIndex),store=catalog.shops?.[shop];if(![0,33,43,51,83,102].includes(type)||!store||!offersOriginalJob(world,placed,type,shop))continue;
  const authored=catalog.npcs[placed.npcIndex].at?.find(([map])=>Number(map)===p.map);if(!placed.custom&&!authored)continue;const at={map:p.map,x:placed.custom?placed.x:Number(authored[1]),z:placed.custom?placed.z:Number(authored[2]),npc:placed.npcIndex};
  store.tabs.forEach((page,tab)=>{const set=catalog.sets[page.set];for(const row of set?.items||[]){const itemIndex=Number(row[0]),d=c.db.def(itemIndex);if(!d||d.custom||d.customId||itemIndex>=900000000||d.period||d.eventType||d.reqLv>p.profile.level||d.maxLv&&p.profile.level>d.maxLv||!((Number(d.classMask)>>>p.profile.classIndex)&1))continue;
   if(offer&&(offer.npcIndex!==placed.npcIndex||offer.shop!==shop||offer.tab!==tab||offer.itemIndex!==itemIndex||offer.stockX!==Number(row[2])||offer.stockY!==Number(row[3])))continue;
   if(needed&&!needed.has(itemIndex)||gearOnly&&!gear(d))continue;
   const materials=set.costs?.[itemIndex],price=Math.floor(Number(d.price||0)*(page.buyRatio||10)/10),inputs=[];
   // Never turn a zero-price unresolved offer into free NPC stock.
   if(materials?.length){if(!materials.every(([index,n])=>Number.isSafeInteger(Number(n))&&Number(n)>0&&count(p,Number(index))>=Number(n)))continue;for(const [index]of materials)inputs.push(...c.bag.filter(i=>i.itemIndex===Number(index)).map(i=>i.uid));}
   else if(store.kind==='ARENA_SHOP'&&d.purchasePoint>0||!Number.isSafeInteger(price)||price<1||Number(p.profile.dil||0)<price)continue;
   // Reject unchanged native payment requirements before cloning profiles and
   // evaluating candidate stats. Unaffordable rows cannot become proposals.
   let benefit=0;if(gearOnly){const probe={itemIndex,count:1,grade:'normal',rnd:[],sockets:[]},candidate=npcEquipmentBenefit(world,p,probe);if(!candidate||!c.eq.check(probe,candidate.slot,p.stats).ok)continue;benefit=candidate.benefit;if(!(benefit>0))continue;}
   candidates.push({kind:gearOnly?'buy-gear':'buy-material',uid:targetByItem?.get(itemIndex)||uid,slot:null,at,serviceAt:at,near:distance(p,at)<=12,inputs,cost:materials?.length?0:price,benefit,action:{type:'shopbuy',npcIndex:placed.npcIndex,shop,tab,itemIndex,stockX:Number(row[2]),stockY:Number(row[3]),count:1},provenance:'authored native NPC/set/cell/sale quantity and owned payment',policy:'ENGINE-CHOSEN one sale-unit purchase'});
  }});
 }
 const reachable=new Map();for(const plan of candidates.sort((a,b)=>b.benefit-a.benefit||distance(p,a.at)-distance(p,b.at))){const key=plan.action.npcIndex;if(!reachable.has(key))reachable.set(key,npcReachableApproach(mapFor(world,p),p,plan.serviceAt,12));const endpoint=reachable.get(key);if(endpoint)return {...plan,at:{map:p.map,...endpoint}};}return null;
}

/** Pure native proposal. No items, currency, stats or profile state are created. */
export function npcEquipmentServicePlan(world,p,{uid,kind,offer}={}){if(!own(p)||p.dead||p.leaving||p.instanceId||p.pcShopOpen||p.tradeId||p.duelId||Number(p.profile.life?.grade?.chaotic)>0)return null;const c=context(world,p);if(!c)return null;
 const locations=new Map(),service=role=>{if(!locations.has(role))locations.set(role,location(world,p,role));return locations.get(role);};
 const plans=[],missing=new Set(),targetByItem=new Map(),need=index=>{missing.add(index);if(!targetByItem.has(index))targetByItem.set(index,currentUid);};let currentUid;for(const target of c.targets){if(uid&&target.item.uid!==uid)continue;const {item}=target;currentUid=item.uid;const d=c.db.def(item.itemIndex),stones=c.bag.filter(i=>i.uid!==item.uid&&isStone(c.db.def(i.itemIndex))&&stoneFits(c.db,c.db.def(i.itemIndex),d));
  const limit=documentedSocketLimit(c.db,d),sockets=item.sockets||[];
  if(socketable(d)&&limit!==null&&limit>0&&sockets.length<=limit&&stones.length){if(sockets.includes(0))plans.push(make('socket-insert',target,{type:'socket',action:'insert',uid:item.uid,stone:stones[0].uid},local(p),[stones[0].uid]));
   else if(sockets.length<limit&&!(Number(d.type)===6&&Number(d.code)===1)&&![4,5,6].includes(Number(d.rank))){let row=c.db.T.addSocket.rows?.[0];for(const r of c.db.T.addSocket.rows||[])if(Number(r.ITEM_LEVEL)<=Number(d.reqLv||0))row=r;else break;const col={normal:'NORMAL',magic:'MAGIC',noble:'NOBLE',divine:'DIVIN'}[item.grade]||'NORMAL',cost=Number(row?.[col]),rate=Number(row?.[col+'_Rate']),at=service('ITEMADDSOCKET');if(at&&Number.isSafeInteger(cost)&&cost>=0&&cost<=p.profile.dil&&rate>0)plans.push(make('socket-create',target,{type:'socket',action:'add',uid:item.uid,materials:[]},at,[],cost));}
  }
  if(brandable(d)&&!(item.brand?.length)){const stone=c.bag.find(i=>i.uid!==item.uid&&Number(c.db.def(i.itemIndex)?.type)===1&&Number(c.db.def(i.itemIndex)?.code)===19&&Number(c.db.def(i.itemIndex)?.use?.brandLevel)>=Number(d.reqLv||1)),sd=stone&&c.db.def(stone.itemIndex),level=Math.max(1,Math.min(250,Number(sd?.use?.brandLevel)||0)),row=c.db.T.incuseOptionLevels.rows.find(r=>Number(r.Level)===level),difference=Math.max(-65,Math.min(100,(Number(sd?.use?.brandLevel)||0)-Number(d.reqLv||0))),dice=c.db.T.incuseDice.rows.find(r=>Number(r.ResultValue)===difference),pool=row&&Array.from({length:Number(row.count)||0},(_,i)=>c.db.T.incuseOption.rows.find(r=>Number(r.No)===Number(row['Value'+(i+1)]))).some(r=>r&&optCode(c.db,r.Option)!=null),at=stone&&pool&&Number(dice?.SuccessRate)>0&&service('ITEMINCUSE');if(at)plans.push(make('brand',target,{type:'brand',uid:item.uid,stone:stone.uid,locks:[]},at,[stone.uid]));}
  const k=item.rnd?.length||0,cap={magic:2,noble:3,divine:4}[item.grade]||0,row=c.db.T.optionUpgrade.rows.find(r=>Number(r.ITEM_OPTION)===Math.min(3,k)&&Number(r.ITEM_LEVEL)===Math.max(1,Math.min(250,Number(d.reqLv)||1)));
  if(brandable(d)&&k<cap&&row&&d.optionPools?.some(([lo,hi])=>hi>0)&&Number(row.ASK_DIL)<=p.profile.dil&&![5,6].includes(Number(d.rank))){const required=Number(row.STONE_COUNT)||1,index=Number(row.LOW_OPTION_STONE_INDEX),stone=c.bag.find(i=>i.itemIndex===index),at=service('ITEMOPTIONUPGRADE');if(at&&stone&&count(p,index)>=required)plans.push(make('option',target,{type:'craft',operation:'option',uid:item.uid,material:stone.uid},at,c.bag.filter(i=>i.itemIndex===index).map(i=>i.uid),Number(row.ASK_DIL)||0));else if(at&&count(p,index)<required)need(index);}
  const upgrade=upgradeRow(c.db,d);if(upgrade&&c.db.def(d.next)&&Number(upgrade.costDil)<=p.profile.dil&&!c.bag.some(i=>[Number(upgrade.stone1),Number(upgrade.stone2)].includes(i.itemIndex))){need(Number(upgrade.stone1));need(Number(upgrade.stone2));}
 }
 // Native amplification only when the next authored stone can brand owned equipment.
 if(!uid)for(const row of c.db.T.amplify.rows||[]){const index=Number(row.RESOURCE_INDEX),need=Number(row.RESOURCE_COUNT),cost=Number(row.COST_DIL),material=c.bag.find(i=>i.itemIndex===index),result=c.db.def(Number(row.TARGET_INDEX));if(material&&need>0&&count(p,index)>=need&&Number.isSafeInteger(cost)&&cost>=0&&cost<=p.profile.dil&&result?.use?.brandLevel&&c.targets.some(t=>brandable(c.db.def(t.item.itemIndex))&&!t.item.brand?.length)){const at=service('ITEMINCUSE');if(at)plans.push(make('amplify',null,{type:'craft',operation:'amplify',material:material.uid,count:1},at,c.bag.filter(i=>i.itemIndex===index).map(i=>i.uid),cost));}}
 const chosen=plans.find(plan=>!kind||plan.kind===kind);if(chosen)return chosen;
 if(missing.size&&(!kind||kind==='buy-material')){const plan=buy(world,p,c,{needed:missing,uid:uid||null,targetByItem,offer});if(plan)return plan;}
 if(!uid&&(!kind||kind==='buy-gear'))return buy(world,p,c,{gearOnly:true,offer});return null;
}

async function save(world,p,task){await serializeLife(p,async()=>{const profile=structuredClone(p.profile);profile.npcEquipment=structuredClone(task);await commitLife(world,p,profile);});}
/** Start after build allocation; resume active tasks BEFORE build/merchant/selling. */
export async function npcEquipmentServiceStep({world,player:p,brain={},act=(q,input)=>world.action(q.account,{...input,token:q.token}),approachPlan,requested=true,cancel=false,policy=NPC_EQUIPMENT_POLICY}){
 if(!own(p)||world.players.get(p.account)!==p||p.dead||p.leaving)return {handled:false,status:'unavailable'};if(flights.has(p))return flights.get(p);const operation=run();flights.set(p,operation);try{return await operation;}finally{flights.delete(p);}
 async function run(){const now=world.now();let task=taskOf(p);const result=(handled,status,plan)=>({handled,status,plan,task});
  if(p.commandActive||p.sceneTransition||p.progressCommitting||p.tradeCommitting)return result(task?.phase==='working','busy');if(!cancel&&now<(brain.equipmentRetryAt||0))return result(task?.phase==='working','retry');
  const finish=async reason=>{task={version:1,policy:'ENGINE-CHOSEN',phase:'cooldown',finishedAt:now,retryAt:now+policy.cooldownMs,reason};await save(world,p,task);return result(false,reason);};
  try{if(task?.phase==='cooldown'&&now<task.retryAt)return result(false,'cooldown');if(task?.phase==='cooldown')task=null;
   if(task?.phase==='working'&&(cancel||task.map!==p.map||task.channel!==(p.channel||0)||now>=task.deadline))return await finish(cancel?'interrupted':'deadline or scene changed');
   if(!task){if(!requested||cancel)return result(false,'not requested');const plan=npcEquipmentServicePlan(world,p);if(!plan){brain.equipmentRetryAt=now+policy.cooldownMs;return result(false,'no owned affordable native service');}task={version:1,policy:'ENGINE-CHOSEN',phase:'working',map:p.map,channel:p.channel||0,startedAt:now,deadline:now+policy.deadlineMs,plan,before:fingerprint(p,plan)};await save(world,p,task);}
   if(fingerprint(p,task.plan)!==task.before)return await finish('owned inputs or result changed');
   // A durable attempt marker bounds ambiguous zero-cost/no-change failures on
   // restart. Retrying an uncertain ordinary action must never spend twice.
   if(task.attempting)return await finish('previous ordinary attempt is not repeated');
   let plan=npcEquipmentServicePlan(world,p,{uid:task.plan.uid||undefined,kind:task.plan.kind,offer:task.plan.action.type==='shopbuy'?task.plan.action:undefined});if(!plan||JSON.stringify(plan.action)!==JSON.stringify(task.plan.action))return await finish('native offer or requirements changed');
   if(approachPlan){plan=approachPlan({world,player:p,plan});if(!plan)return result(true,'waiting for a free native service approach');}
   if(!plan.near)return result(true,'walking to native equipment service',plan);
   if(plan.slot!==null){const response=await act(p,{type:'unequip',slot:plan.slot});if(!response)throw Error('Equipment removal was not accepted.');return result(true,'removed gear for native service');}
   task={...task,attempting:true};await save(world,p,task);
   const response=await act(p,plan.action);if(!response)throw Error('Equipment service was not accepted.');await finish('ordinary equipment service completed');return result(true,'ordinary equipment service completed');
  }catch(error){brain.equipmentRetryAt=now+policy.retryMs;brain.lastError=error.message;return result(taskOf(p)?.phase==='working','retry after failed service');}
 }
}



