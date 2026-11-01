// Original life/craft.js rules and life.json catalog; client submits recipe/job IDs only.
import {randomUUID} from 'node:crypto';
import {AuthoritativeInventory} from './inventory.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {lifeError as deny,validateLife,serializeLife,commitLife} from './life-transactions.mjs';
export const CRAFTING_SCHEMAS={production:['token','type','operation','recipe','count','jobId','mastery','item']};
export function initializeCrafting(world,p) {
  if(!world.data.craft)return;
  p.profile.life||={};p.profile.life.craft||={type:null,exp:0,resets:0,slots:world.data.craft.slots?.base||1,jobs:[]};
  // Old trusted persisted jobs receive stable identifiers once. Client slot indexes never authorize jobs.
  for(const job of p.profile.life.craft.jobs)job.id||=randomUUID();
}
export function craftLevel(C,st) {let lv=1;for(const r of C.exp||[])if(r.level===lv&&st.exp>=r.exp)lv=r.level+1;return Math.min(lv,C.exp?.length||10);}
const integer=(n,min,max)=>{if(!Number.isSafeInteger(n)||n<min||n>max)deny('Invalid production quantity or identifier.');return n;};
export async function craftingCommand(world,p,input) {
  validateLife(input,CRAFTING_SCHEMAS);
  return serializeLife(p,async()=>{
    const C=world.data.craft;if(!C||!world.data.itemDB)deny('Production catalog is unavailable.');
    if(p.dead||p.leaving)deny('Production requires a living connected character.');
    initializeCrafting(world,p);
    const profile=structuredClone(p.profile),st=profile.life.craft;
    const inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
    const now=world.now();let result={operation:input.operation,accepted:true};
    const permitted={make:['recipe','count'],receive:['jobId'],receiveAll:[],cancel:['jobId'],mastery:['mastery'],slot:[],catalyst:['jobId','item']}[input.operation];
    if(!permitted||Object.keys(input).some(k=>!['token','type','operation',...permitted].includes(k)))deny('Invalid production operation fields.');
    const recipe=id=>{const r=C.recipes?.[id];if(!r||!world.data.itemDB.def(r.item))deny('Unknown production recipe.');return r;};
    const findJob=()=>{if(typeof input.jobId!=='string')deny('Choose a production job.');const j=st.jobs.find(j=>j.id===input.jobId);if(!j)deny('This job was already received or does not exist.');return j;};
    const grant=(list)=>{if(!inv.canFit(list))return false;for(const e of list)if(!inv.add(e.item,e.count))deny('Production item insertion failed.');return true;};
    const received=[];
    const receive=j=>{
      if(now<j.end)deny('This production job is not complete.');
      const r=recipe(j.recipe);
      // Persist the first roll even if the bag is full: retrying cannot reroll failures.
      if(j.success==null){j.success=0;for(let k=0;k<j.count;k++)if(world.random()*100<r.prob)j.success++;}
      if(j.success>0&&!grant([{item:r.item,count:r.count*j.success}]))return {accepted:false,reason:'space',jobId:j.id};
      st.exp=(st.exp||0)+r.rewardPoint*j.success;st.jobs.splice(st.jobs.indexOf(j),1);
      const detail={accepted:true,jobId:j.id,recipe:j.recipe,count:j.count,success:j.success,item:r.item,craftType:r.type};received.push(detail);return detail;
    };
    if(input.operation==='make'){
      integer(input.recipe,1,Number.MAX_SAFE_INTEGER);const r=recipe(input.recipe),count=integer(input.count??1,1,r.max||1);
      if(r.type!==11&&r.type!==st.type)deny('Choose the recipe’s profession first.');
      if(craftLevel(C,st)<(r.needPoint||1))deny('Production mastery level is too low.');
      if(st.jobs.length>=st.slots)deny('All production slots are occupied.');
      const cost=r.dil*count;integer(cost,0,10_000_000_000);
      if(inv.dil<cost)deny('Not enough DIL for production.');
      // Aggregate identical ingredients before checking or consuming them.
      const mats=new Map();for(const [item,n]of r.mats)mats.set(item,(mats.get(item)||0)+n*count);
      for(const [item,n]of mats)if(inv.count(item)<n)deny('Not enough production materials.');
      for(const [item,n]of mats)if(!inv.remove(item,n))deny('Production material consumption failed.');
      inv.addDil(-cost);const total=Math.max(0,r.time*count)*1000;
      const job={id:randomUUID(),recipe:input.recipe,count,start:now,end:now+total,total};st.jobs.push(job);result.jobId=job.id;
    }else if(input.operation==='receive')Object.assign(result,receive(findJob()));
    else if(input.operation==='receiveAll'){
      const ready=st.jobs.filter(j=>j.end<=now);if(!ready.length)deny('No production job is complete.');
      result.jobs=ready.map(receive);result.accepted=result.jobs.some(j=>j.accepted);
    }else if(input.operation==='cancel'){
      const j=findJob(),left=(j.end-now)/1000;
      if(left<=0)Object.assign(result,receive(j));
      else{if(left<60)deny('Jobs with less than a minute remaining cannot be cancelled.');const r=recipe(j.recipe);
        if(!grant(r.mats.map(([item,n])=>({item,count:n*j.count}))))deny('Make bag space for returned production materials.');
        if(inv.dil+r.dil*j.count>10_000_000_000)deny('Make room for the DIL refund.');inv.addDil(r.dil*j.count);st.jobs.splice(st.jobs.indexOf(j),1);
      }
    }else if(input.operation==='mastery'){
      const type=integer(input.mastery,1,3);if(type===st.type)deny('That profession is already selected.');if(st.jobs.length)deny('Finish production jobs before changing profession.');
      const n=st.type?(st.resets||0)+1:0,cost=st.type?(C.resetCost?.[Math.min(n,C.resetCost.length)-1]??10000000):0;
      if(inv.dil<cost)deny('Not enough DIL to change profession.');inv.addDil(-cost);
      if(st.type){st.resets=n;st.exp=0;}st.type=type;
    }else if(input.operation==='slot'){
      if(st.slots>=(C.slots?.max||3))deny('All production slots are unlocked.');const item=(C.workshops||[]).find(i=>inv.count(i)>0);
      if(!item||!inv.remove(item,1))deny('A Dora’s Workshop item is required.');st.slots++;
    }else if(input.operation==='catalyst'){
      const j=findJob();integer(input.item,1,Number.MAX_SAFE_INTEGER);const seconds=C.catalysts?.[input.item];
      if(!(seconds>0)||j.end<=now||!inv.remove(input.item,1))deny('An owned catalyst and unfinished job are required.');j.end=Math.max(now,j.end-seconds*1000);
    }
    // Mission hooks operate on the transactional clone before the same durable commit.
    const actor={...p,profile};for(const r of received)if(r.success>0)progressDekaPass({...world,changed(){}},actor,0,23,r.item,r.success);
    await commitLife(world,p,profile,{rewardProgress:true});
    world.emit(p.map,{type:'production',actorId:p.id,...result,instanceId:p.instanceId||null});return result;
  });
}
