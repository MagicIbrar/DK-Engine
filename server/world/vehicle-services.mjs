import {AuthoritativeInventory} from './inventory.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {createQuestContext} from './quests.mjs';
import {serializeLife,validateLife,commitLife,lifeError as fail} from './life-transactions.mjs';

export const VEHICLE_SERVICE_SCHEMAS={vehicleservice:['token','type','operation','revision','requestId','uid','uids','gear']};
const FIELDS={crystallize:['uids'],evolve:['uid'],enchant:['uid','gear'],enhance:['uid']};
const RECEIPTS=128;
function integer(value,min=0,max=Number.MAX_SAFE_INTEGER){if(!Number.isSafeInteger(value)||value<min||value>max)fail('The original vehicle-service value is unavailable.');return value;}
function uid(value){if(typeof value!=='string'||!value.length||value.length>100)fail('Choose an owned bag item.');return value;}
function intent(input){
  validateLife(input,VEHICLE_SERVICE_SCHEMAS);
  const fields=FIELDS[input.operation];
  if(!fields||Object.keys(input).some(k=>!['token','type','operation','revision','requestId',...fields].includes(k)))fail('Send only the selected vehicle-service intent.');
  if(typeof input.requestId!=='string'||!/^[a-zA-Z0-9_-]{8,80}$/.test(input.requestId))fail('Invalid vehicle-service request identifier.');
  const value={operation:input.operation,revision:integer(input.revision)};
  if(input.operation==='crystallize'){
    if(!Array.isArray(input.uids)||!input.uids.length||input.uids.length>10||new Set(input.uids).size!==input.uids.length)fail('Choose one to ten different bag vehicles.');
    value.uids=input.uids.map(uid).sort();
  }else{value.uid=uid(input.uid);if(input.operation==='enchant')value.gear=uid(input.gear);}
  return value;
}
function owned(inv,id){
  const matches=inv.bag.list.filter(item=>item.uid===id),item=matches[0];
  if(matches.length!==1||!inv.db.def(item.itemIndex)||!Number.isSafeInteger(item.count??1)||(item.count??1)<1||
    item.expiresAt!=null&&(!Number.isFinite(item.expiresAt)||item.expiresAt<=inv.now()))fail('Choose an owned, unexpired bag item.');
  return item;
}
function vehicle(world,p,inv,id){
  const item=owned(inv,id),row=world.data.mountData.vehicles?.[item.itemIndex];
  if(!row||(item.count??1)!==1||inv.db.stackSize(inv.db.def(item.itemIndex))!==1)fail('Choose an original individual vehicle item.');
  if(p.profile.equip?.items?.[id]||p.mount?.uid===id)fail('Unequip and dismiss the selected vehicle first.');
  return {item,row};
}
function cost(inv,n){integer(n,0,10_000_000_000);if(inv.dil<n)fail('Insufficient DIL for the original vehicle service.');inv.addDil(-n);}
function materials(inv,index,count){integer(index,1);integer(count,1,100000);if(!inv.db.def(index)||!inv.remove(index,count))fail('Insufficient original vehicle-service materials.');}
function optionRows(world,inv){
  const rows=world.data.mountData.vehicleOptions;
  if(!Array.isArray(rows)||!rows.length||new Set(rows.map(r=>r.index)).size!==rows.length)fail('The original vehicle-option pool is unavailable.');
  for(const row of rows){
    integer(row.index,1);integer(row.addCost,0,10_000_000_000);integer(row.needItem,1);
    if(!inv.db.def(row.needItem)||!Array.isArray(row.addItems)||!row.addItems.length||row.addItems.some(id=>!Number.isSafeInteger(id)||id<1||!inv.db.def(id))||
      !Array.isArray(row.values)||row.values.length!==11||row.values.some(v=>!Number.isFinite(v))||
      !Array.isArray(row.need)||row.need.length!==10||!Array.isArray(row.cost)||row.cost.length!==10)fail('An original vehicle-option rule is unavailable.');
    row.need.forEach(n=>integer(n,1,100000));row.cost.forEach(n=>integer(n,0,10_000_000_000));
  }
  return rows;
}
function assigned(item,rows){
  const option=item.vehicleOpt;
  if(!option||Object.keys(option).some(k=>!['index','level'].includes(k))||!Number.isSafeInteger(option.index)||!Number.isSafeInteger(option.level)||option.level<0||option.level>10)fail('Choose a vehicle with a valid original option.');
  const row=rows.find(row=>row.index===option.index);if(!row)fail('This vehicle option has no confirmed original rule.');return {row,level:option.level};
}
function apply(world,p,profile,inv,input){
  if(input.operation==='crystallize'){
    const sources=input.uids.map(id=>vehicle(world,p,inv,id)),outputs=new Map();
    for(const {row} of sources){const [index,count]=row.csv?.dis||[];integer(index,1);integer(count,1,100000);if(!inv.db.def(index))fail('The original crystallization output is unavailable.');outputs.set(index,(outputs.get(index)||0)+count);}
    for(const {item} of sources)if(!inv.consumeEntry(item,1))fail('A registered vehicle is no longer owned.');
    for(const [index,count] of outputs)if(!inv.add(index,count,{roll:false}))fail('Your bag cannot fit the original crystallization result.');
    return {consumed:[...input.uids],outputs:[...outputs].map(([itemIndex,count])=>({itemIndex,count})),cost:0};
  }
  const {item,row}=vehicle(world,p,inv,input.uid);
  if(input.operation==='evolve'){
    const [index,count]=row.csv?.need||[],next=integer(row.next,1);
    if(!world.data.mountData.vehicles[next]||!inv.db.def(next))fail('The original next-tier vehicle is unavailable.');
    materials(inv,index,count);if(!inv.consumeEntry(item,1))fail('The selected vehicle is no longer owned.');
    if(!inv.add(next,1,{roll:false}))fail('Your bag cannot fit the original evolved vehicle.');
    return {consumed:[item.uid],outputs:[{itemIndex:next,count:1}],materials:[{itemIndex:index,count}],cost:0};
  }
  if(!nearbyNpc(world,p,{role:'VEHICLE_CYCLE'}))fail('Walk near the original vehicle option NPC.');
  const rows=optionRows(world,inv);
  if(input.operation==='enchant'){
    if(item.vehicleOpt)assigned(item,rows);
    const first=rows[0],gears=JSON.stringify([...first.addItems].sort((a,b)=>a-b));
    if(rows.some(row=>row.addCost!==first.addCost||JSON.stringify([...row.addItems].sort((a,b)=>a-b))!==gears))fail('The original enchantment cost or materials are ambiguous.');
    const gear=owned(inv,input.gear);if(!first.addItems.includes(gear.itemIndex)||gear===item)fail('Choose an original gearwheel from your bag.');
    cost(inv,first.addCost);if(!inv.consumeEntry(gear,1))fail('The selected gearwheel is unavailable.');
    const roll=world.random();if(!Number.isFinite(roll)||roll<0||roll>=1)fail('Vehicle enchantment randomness is unavailable.');
    // Preserve the existing engine's uniform selection policy across the complete source pool.
    // The CSV supplies outcomes, not recovered official probability weights.
    const chosen=rows[Math.floor(roll*rows.length)];item.vehicleOpt={index:chosen.index,level:0};
    return {uid:item.uid,option:{...item.vehicleOpt},materials:[{itemIndex:gear.itemIndex,count:1}],cost:first.addCost};
  }
  const current=assigned(item,rows);if(current.level===10)fail('This vehicle option is already at its original maximum level.');
  const n=current.row.need[current.level],dil=current.row.cost[current.level];
  cost(inv,dil);materials(inv,current.row.needItem,n);item.vehicleOpt.level=current.level+1;
  return {uid:item.uid,option:{...item.vehicleOpt},materials:[{itemIndex:current.row.needItem,count:n}],cost:dil};
}
export function vehicleServiceCommand(world,p,input){return serializeLife(p,async()=>{
  const selected=intent(input),signature=JSON.stringify(selected),life=p.profile.life;
  if(life!=null&&(typeof life!=='object'||Array.isArray(life)))fail('This legacy life-service state is unsupported.');
  const revision=integer(life?.vehicleServiceRevision??0),receipts=life?.vehicleServiceReceipts??[];
  if(!Array.isArray(receipts)||receipts.length>RECEIPTS||receipts.some(r=>!r||typeof r.id!=='string'||typeof r.signature!=='string'||!Number.isSafeInteger(r.revision)||!r.result))fail('This vehicle receipt state is unsupported.');
  const receipt=receipts.find(r=>r.id===input.requestId);
  if(receipt){if(receipt.signature!==signature)fail('That vehicle request identifier belongs to a different intent.');return {receipt:structuredClone(receipt),replayed:true};}
  if(selected.revision!==revision)fail('Vehicle service state changed. Refresh before choosing another action.');
  if(p.dead||p.leaving||p.sceneTransition)fail('Vehicle services are unavailable while dead or changing maps.');
  if(!world.data.mountData?.vehicles||!world.data.itemDB)fail('The original vehicle-service tables are unavailable.');
  const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
  const result=apply(world,p,profile,inv,selected),next=integer(revision+1,1);
  const passSub={enhance:4,enchant:11,crystallize:26}[selected.operation];
  if(passSub)for(const id of selected.operation==='crystallize'?selected.uids:[selected.uid]){
    const item=p.profile.inventory.find(item=>item.uid===id);
    progressDekaPass({...world,changed(){}},{...p,profile},28,passSub,item.itemIndex,1);
  }
  const record={id:input.requestId,revision:next,signature,at:world.now(),operation:selected.operation,result};
  profile.life||={};profile.life.vehicleServiceRevision=next;profile.life.vehicleServiceReceipts=[...receipts.slice(-(RECEIPTS-1)),record];
  const quests=createQuestContext(world,p,{profile,inventory:inv,commitToPlayer:false});quests?.engine.recountCollect(null,true);
  const stats=world.data.stats?.(profile,p,world.now())||null;
  await commitLife(world,p,profile,{stats,rewardProgress:true});
  quests?.commit();world.emit(p.map,{type:'vehicleservice',actorId:p.id,operation:selected.operation});
  return {receipt:structuredClone(record),replayed:false};
});}
