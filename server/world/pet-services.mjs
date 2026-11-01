import {randomUUID} from 'node:crypto';
import {MountsData} from '../../src/systems/mounts/data.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {commitLife,serializeLife,validateLife,lifeError as fail} from './life-transactions.mjs';

export const PET_SERVICE_SCHEMAS={petcombine:['token','type','operation','uids','jobId'],pettransform:['token','type','operation','uid','shape']};
function petData(world){const data=new MountsData();data.core=world.data.mountData;data.ui=world.data.mountUI;return data;}
function combineSources(world,p,profile,uids){
  if(!Array.isArray(uids)||uids.length!==3||new Set(uids).size!==3||uids.some(uid=>typeof uid!=='string'))fail('Choose three different owned pet items.');
  const data=petData(world);
  return uids.map(uid=>{
    const item=profile.inventory?.find(i=>i.uid===uid);
    if(!item||!data.isPet(item.itemIndex)||item.pet?.sleep||item.expiresAt&&item.expiresAt<=world.now()&&!item.pet?.eternal)fail('Choose living, unexpired pet items in your bag.');
    if(profile.equip?.items?.[uid]||item.pet?.active||p.pet?.uid===uid||item.pet?.inv?.length)fail('Dismiss the pet and empty its inventory first.');
    return item;
  });
}
function recipeFor(world,items){
  const data=petData(world),points=items.reduce((n,item)=>n+Number(data.pet(item.itemIndex)?.cr?.raw?.PetMakingPoint||0),0);
  return (world.data.mountUI.petTables?.making||[]).filter(row=>row.point<=points).sort((a,b)=>b.point-a.point)[0]||null;
}
function cost(inv,value){if(!Number.isSafeInteger(value)||value<0||inv.dil<value)fail('Insufficient DIL for the original pet service.');inv.addDil(-value);}
function material(inv,item,count){if(!Number.isSafeInteger(item)||!Number.isInteger(count)||count<0||count>100000||count&&!inv.remove(item,count))fail('Missing original pet-service materials.');}
function outcome(world,row){
  if(!Number.isFinite(row.range)||row.range<=0)fail('The original combination probability table is unavailable.');
  let dice=world.random()*row.range,egg=row.normal?.[0];
  for(const [index,weight]of [row.unique,row.rare,row.normal]){if(weight>0&&dice<weight&&index){egg=index;break;}dice-=weight;}
  if(row.useLegend&&row.legendEgg&&egg===row.unique[0])egg=row.legendEgg;
  return egg;
}
export function petServiceCommand(world,p,input){return serializeLife(p,async()=>{
  validateLife(input,PET_SERVICE_SCHEMAS);
  if(p.dead||p.leaving||p.sceneTransition)fail('Pet services are unavailable while dead or changing maps.');
  if(!world.data.mountData||!world.data.mountUI||!world.data.itemDB)fail('Original pet-service tables are unavailable.');
  const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
  let result={};
  if(input.type==='petcombine'){
    const fields={start:['uids'],finish:['jobId'],cancel:['jobId']};
    if(!fields[input.operation]||Object.keys(input).some(k=>!['token','type','operation',...fields[input.operation]].includes(k)))fail('Invalid pet combination operation.');
    profile.life||={};const job=profile.life.petCombination;
    if(input.operation==='start'){
      if(job)fail('A pet combination is already pending.');
      const sources=combineSources(world,p,profile,input.uids),row=recipeFor(world,sources);if(!row)fail('No original combination tier matches those pets.');
      if(inv.dil<row.dil)fail('Insufficient DIL for combination.');
      profile.life.petCombination={id:randomUUID(),uids:[...input.uids],fingerprints:sources.map(i=>JSON.stringify(i)),recipe:row.index,readyAt:world.now()+Math.max(0,Number(row.timeMs)||0)};
      result={jobId:profile.life.petCombination.id};
    }else{
      if(!job||input.jobId!==job.id)fail('That pet combination is no longer pending.');
      if(input.operation==='finish'){
        if(world.now()<job.readyAt)fail('Pet combination processing is not finished.');
        const sources=combineSources(world,p,profile,job.uids);if(sources.some((item,i)=>JSON.stringify(item)!==job.fingerprints[i]))fail('A registered pet changed. Cancel and register the pets again.');
        const row=recipeFor(world,sources);if(!row||row.index!==job.recipe)fail('The original combination tier changed.');
        const egg=outcome(world,row);if(!world.data.itemDB.def(egg))fail('The original pet egg is unavailable.');
        cost(inv,row.dil);for(const source of sources)if(!inv.consumeEntry(source,1))fail('A registered pet is no longer owned.');
        if(!inv.add(egg,1))fail('The pet egg does not fit in your inventory.');result={itemIndex:egg};
      }
      delete profile.life.petCombination;
    }
  }else{
    const fields={shape:['shape'],restore:[],disassemble:[]};
    if(!fields[input.operation]||Object.keys(input).some(k=>!['token','type','operation','uid',...fields[input.operation]].includes(k)))fail('Invalid pet transform operation.');
    if(!nearbyNpc(world,p,{role:'PET_TRANSFORM'}))fail('Walk near the original pet transformation NPC.');
    const item=profile.inventory.find(i=>i.uid===input.uid)||Object.values(profile.equip?.items||{}).find(i=>i.uid===input.uid);
    if(!item)fail('Choose an owned pet item.');
    if(item.pet?.active||p.pet?.uid===item.uid||item.pet?.inv?.length)fail('Dismiss the pet and empty its inventory first.');
    const tables=world.data.mountUI.petTables;
    if(input.operation==='disassemble'){
      const row=tables.disassemble?.find(row=>row.item===item.itemIndex);if(!row||!inv.bag.list.includes(item))fail('Choose a disassemblable pet item in your bag.');
      cost(inv,row.dil);if(!inv.consumeEntry(item,1))fail('The selected pet item is unavailable or expired.');if(!inv.add(row.out,row.count))fail('Disassembly materials do not fit in your inventory.');result={itemIndex:row.out,count:row.count};
    }else{
      const row=tables.shapeChange?.find(row=>row.item===item.itemIndex);if(!row||!petData(world).isPet(item.itemIndex))fail('This pet has no original appearance-change rule.');
      item.pet||={};
      if(input.operation==='shape'){
        const shape=tables.shapeChange?.find(shape=>shape.item===input.shape&&shape.grade===row.grade&&shape.item!==row.item);if(!shape||!petData(world).isPet(shape.item))fail('Choose an original appearance of the same pet grade.');
        cost(inv,row.dil);material(inv,row.needItem,row.needCount);item.pet.shape=shape.item;
      }else{if(!item.pet.shape)fail('This pet has no changed appearance to restore.');cost(inv,row.resetDil);material(inv,row.resetItem,row.resetCount);delete item.pet.shape;}
    }
  }
  await commitLife(world,p,profile,{rewardProgress:true});world.emit(p.map,{type:'petservice',actorId:p.id,operation:input.operation,...result});return result;
});}
