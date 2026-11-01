// Native single_supplymachine grades/weights/counts and fieldboss_supplymachine.
// The multi machine remains closed when its native Enable/Usable are zero.
import {randomUUID} from 'node:crypto';
import {AuthoritativeInventory} from './inventory.mjs';
import {serializeLife,validateLife,lifeError as deny} from './life-transactions.mjs';
import {socialState,socialTransaction} from './social-state.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {assertNieteService,assertCombatService} from './niete-services.mjs';
import {serverDayKey} from '../../src/game/server-time.js';

export const SUPPLY_SCHEMAS={supply:['token','type','operation','kind','plateId','requestId']};
const PAY=[1756038,1192509,1756037],DAILY=10,MIX_COST=500000;
const pick=(world,rows)=>{const total=rows.reduce((n,r)=>n+r.weight,0);if(!(total>0))deny('No original supply rewards remain.');let r=world.random()*total;for(const row of rows){r-=row.weight;if(r<0)return row;}return rows.at(-1);};
function globalState(state,day){
 // ENGINE-CHOSEN: server_limit shares the native plate's midnight reset. The
 // tables name a server limit but supply no independent reset schedule.
 if(state.supply?.day!==day)state.supply={day,counts:{}};
 return state.supply;
}
function makePlate(world,M,day,global){
 const slots=[];
 for(const [grade,min,max]of M.grades||[]){
  if(!Number.isInteger(min)||!Number.isInteger(max)||min<0||max<min)deny('Invalid native supply grade counts.');
  const amount=min+Math.floor(world.random()*(max-min+1)),used=new Set();
  for(let k=0;k<amount;k++){
   const pool=(M.entries||[]).filter(e=>e[0]===grade&&!used.has(e[1])&&world.data.itemDB.def(e[1])&&e[2]>0&&(e[4]<=0||(global.counts[e[1]]||0)<e[4]));
   if(!pool.length){slots.push({item:0,count:0,won:true});continue;}
   const e=pick(world,pool.map(e=>({weight:e[2],e}))).e;used.add(e[1]);slots.push({grade,item:e[1],count:e[5]||1,winRate:e[3],limit:e[4],won:false});
  }
 }
 if(slots.length!==10)deny('Original supply plate must have ten slots.');
 return {id:randomUUID(),day,usedDay:day,used:0,slots};
}
function plateView(plate,global){return {...structuredClone(plate),slots:plate.slots.map(s=>({...s,won:s.won||s.limit>0&&(global.counts[s.item]||0)>=s.limit}))};}
function fieldPlate(M){const row=M.fieldBossRoulette?.[0];if(!row?.items?.length||!row.payItems?.length||!Number.isInteger(row.payCount)||row.payCount<1)deny('Original field-boss supply data is unavailable.');return {id:'fieldboss',slots:row.items.map(([item,weight,count])=>({item,weight,count,won:false})),pay:row.payItems,need:row.payCount};}
export async function supplyCommand(world,p,input){
 validateLife(input,SUPPLY_SCHEMAS);
 const {kind,operation}=input;
 if(!['orbis','fieldboss'].includes(kind)||!['state','spin','mix'].includes(operation)||kind!=='orbis'&&operation==='mix')deny('Choose an original supply operation.');
 if(typeof input.requestId!=='string'||!/^[a-zA-Z0-9_-]{16,100}$/.test(input.requestId))deny('A unique supply request is required.');
 return serializeLife(p,async()=>{
  const M=world.data.shopData?.shops?.supplyMachine;if(!M||!world.data.itemDB)deny('Original supply catalog is unavailable.');
  if(p.dead||p.leaving||p.sceneTransition||p.tradeId||p.charTradeId||p.pcShopOpen)deny('Supply is unavailable while dead, travelling or trading.');
  assertNieteService(world,p);assertCombatService(world,p);
  if(kind==='orbis'&&(p.profile.level||1)<80)deny('Available for those above Level 80.');
  const day=serverDayKey(world.now()),current=socialState(world);
  if(operation==='state'&&kind==='fieldboss')return {kind,plate:fieldPlate(M)};
  if(operation==='state'&&p.profile.orbis?.day===day&&current.supply?.day===day&&p.profile.orbis?.id&&p.profile.orbis.slots?.length===10)return {kind,plate:plateView(p.profile.orbis,current.supply)};
  return socialTransaction(world,p,{revision:current.revision,requestId:input.requestId},(state,profile)=>{
   const global=globalState(state,day);
   let plate=kind==='orbis'?profile.orbis:fieldPlate(M);
   if(kind==='orbis'&&(!plate?.id||plate.day!==day||plate.slots?.length!==10))plate=profile.orbis=makePlate(world,M,day,global);
   if(operation==='state')return {kind,plate:plateView(plate,global)};
   if(input.plateId!==plate.id)deny('The supply plate changed. Reopen it before playing.');
   const inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
   if(operation==='mix'){
    if(inv.dil<MIX_COST)deny('DIL is not enough.');inv.addDil(-MIX_COST);
    for(let i=plate.slots.length-1;i>0;i--){const j=Math.floor(world.random()*(i+1));[plate.slots[i],plate.slots[j]]=[plate.slots[j],plate.slots[i]];}
    plate.id=randomUUID();return {kind,plate:plateView(plate,global)};
   }
   if(kind==='orbis'&&(plate.used||0)>=DAILY)deny('Further use of the Orbis of Destiny is unavailable.');
   const left=plate.slots.map((s,i)=>({s,i,weight:kind==='orbis'?s.winRate:s.weight})).filter(({s,weight})=>s.item&&!s.won&&weight>0&&world.data.itemDB.def(s.item)&&(kind!=='orbis'||s.limit<=0||(global.counts[s.item]||0)<s.limit));
   const chosen=pick(world,left),won=chosen.s,pay=kind==='orbis'?PAY:plate.pay,need=kind==='orbis'?1:plate.need;
   if(pay.reduce((n,id)=>n+inv.count(id),0)<need)deny('Gearwheel is not enough.');
   let remaining=need;const paid=[];
   for(const id of pay){const n=Math.min(remaining,inv.count(id));if(n){if(!inv.remove(id,n))deny('Gearwheel consumption failed.');paid.push({item:id,count:n});remaining-=n;}}
   if(remaining||!inv.canFit([{item:won.item,count:won.count}])||!inv.add(won.item,won.count,{reason:kind}))deny('There is not enough space in inventory.');
   if(kind==='orbis'){
    plate.used=(plate.used||0)+1;won.won=true;global.counts[won.item]=(global.counts[won.item]||0)+1;
    if(paid.some(x=>x.item===1756037))progressDekaPass({...world,changed(){}},{...p,profile},5,22,1756037,1);
   }
   return {kind,plate:kind==='orbis'?plateView(plate,global):plate,pick:chosen.i,reward:{item:won.item,count:won.count},paid};
  });
 });
}
