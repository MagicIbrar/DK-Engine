// Server clock drives the original fishing minigame; only pulling/cancel are browser intents.
import {randomUUID} from 'node:crypto';
import {AuthoritativeInventory} from './inventory.mjs';
import {mapFor,sameScene} from './scene.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {questFish} from './quests.mjs';
import {skillControls} from './skills.mjs';
import {lifeError as deny,validateLife,serializeLife,commitLife} from './life-transactions.mjs';
export const FISHING_SCHEMAS={fishing:['token','type','operation','sessionId','pull']};
export function fishingBusy(player){const A=player?.fishing;return !!A&&(A.phase!=='close'||A.settled!==true);}
export const FISHING_CAST_MS=8000;
const pick=(world,rows,total=null)=>{let r=world.random()*(total??rows.reduce((s,x)=>s+(Number(x[1])||0),0));for(const row of rows){r-=Number(row[1])||0;if(r<0)return row;}return null;};
const range=(world,lo,hi)=>lo+world.random()*Math.max(0,hi-lo);
function rod(world,p){const e=p.profile.equip,uid=e?.presets?.[e.active||0]?.[4],item=e?.items?.[uid];if(!item||item.expiresAt&&item.expiresAt<=world.now())return null;const index=world.data.fishing?.rodItems?.[item.itemIndex];const R=world.data.fishing?.rods?.[index];return R?{...R,index,item:item.itemIndex,uid}:null;}
function spot(world,p){
 const F=world.data.fishing,col=mapFor(world,p)?.collision;if(!col)return {error:4};
 const fx=-Math.sin(p.yaw),fz=-Math.cos(p.yaw);
 for(let d=0;d<=9;d+=.5)for(const a of [0,.35,-.35,.7,-.7]){
  const c=Math.cos(a),s=Math.sin(a),x=p.x+(fx*c-fz*s)*d,z=p.z+(fx*s+fz*c)*d,attr=col.attrAt(x,z),cell=F.cells?.[attr];
  if(cell?.fishing&&cell.fish?.length)return d>4.5?{error:5}:{x,z,attr,cell};
 }return {error:4};
}
function requirements(world,p){
 if(p.dead||p.leaving)deny('Cannot fish while dead or leaving.');if(p.mount)deny('Dismount before fishing.');
 if(skillControls(p).casting||p.sceneTransition||(p.lastCombat!=null&&world.now()-p.lastCombat<2000))deny('Cannot fish while busy or in combat.');
 const R=rod(world,p);if(!R)deny('Equip a fishing rod.');
 const si=world.data.fishing.skills?.[p.profile.classIndex],learned=p.profile.skills?.[si],level=Number(typeof learned==='object'?learned?.level:learned)||0;
 if(!si||level<1)deny('Learn Fishing Mastery first.');
 const S=spot(world,p);if(S.error)deny(S.error===5?'Fishing water is too far away.':'Face a fishing area.');
 const def=world.data.skillFull?.skills?.[si],cap=Number(def?.maxLevel?.normal)||1;
 if(S.cell.skillMin>level&&level<cap)deny('Fishing Mastery level is too low.');
 return {R,S};
}
function valid(world,p,A){return !p.dead&&!p.leaving&&!p.mount&&!p.sceneTransition&&sameScene(A,p)&&rod(world,p)?.uid===A.rod.uid&&Math.hypot(p.x-A.x,p.z-A.z)<.1&&!(p.path?.length)&&!skillControls(p).casting&&!(p.lastCombat!=null&&p.lastCombat>A.started);}
function terminal(world,p,result){const A=p.fishing;if(!A||A.phase==='close')return;A.phase='close';A.result=result;A.finishedAt=world.now();world.changed(p);}
export function cancelFishing(world,p,reason='miss'){terminal(world,p,reason);}
export function fishingPose(p){const A=p.fishing;return A?{id:A.id,phase:A.phase,pulling:!!A.pull,result:A.result||null,settled:!!A.settled}:null;}
export function fishingState(p){const A=p.fishing;if(!A)return null;return {id:A.id,phase:A.phase,auto:A.auto,t:A.t,castMs:FISHING_CAST_MS,rod:A.rod,spot:{x:A.spot.x,z:A.spot.z},fishIndex:A.fishIndex||null,fish:A.fish||null,fishHp:A.fishHp??0,lineHp:A.lineHp??A.rod.maxHp,resisting:!!A.resisting,pulling:!!A.pull,result:A.result||null,item:A.reward||null,exp:A.exp||0,settled:!!A.settled};}
export function tickFishing(world,p,dt){
 const A=p.fishing;if(!A||A.phase==='close'||p.commandActive||p.leaving)return;
 if(!valid(world,p,A)){terminal(world,p,'miss');return;}
 // Never derive elapsed time from client timestamps; clamp stalls as core movement does.
 dt=Math.min(.2,Math.max(0,dt));A.t+=dt*1000;
 if(A.phase==='cast'&&A.t>=FISHING_CAST_MS){
  const F=world.data.fishing;
  if(A.auto){const slot=Math.max(0,Math.min(2,(A.rod.index||7)-7));A.fishIndex=A.cell.auto?.[slot]||A.cell.auto?.[0];A.fish=F.fish[A.fishIndex];terminal(world,p,A.fish?'catch':'nothing');}
  else if(world.random()*100000>=A.cell.casting+(F.baits?.[A.bait]||0)*1000)terminal(world,p,'nothing');
  else{const row=pick(world,A.cell.fish);A.fishIndex=row?.[0];A.fish=F.fish[A.fishIndex];if(!A.fish)terminal(world,p,'nothing');
   else{A.phase='fight';A.fishHp=A.fish.startHp||A.fish.maxHp*.65;A.lineHp=A.rod.maxHp;A.resisting=false;A.timer=range(world,A.fish.delayMin,A.fish.delayMax);}}
 }else if(A.phase==='fight'){
  const F=A.fish,R=A.rod;A.timer-=dt*1000;
  if(A.timer<=0){if(A.resisting){A.resisting=false;A.timer=range(world,F.delayMin,F.delayMax);}else if(world.random()*100000<(F.resistRatio||0)){A.resisting=true;A.timer=range(world,F.resistMin,F.resistMax);}else A.timer=range(world,F.delayMin,F.delayMax);}
  if(A.pull){if(A.resisting)A.lineHp-=(F.strength||10)*dt;else A.fishHp-=(R.strength||4)*dt;}
  else{A.lineHp=Math.min(R.maxHp,A.lineHp+(R.recovery||1)*dt);A.fishHp=Math.min(F.maxHp,A.fishHp+(F.recovery||1)*dt);}
  if(A.lineHp<=0)terminal(world,p,'snap');else if(A.fishHp>=F.maxHp)terminal(world,p,'escape');else if(A.fishHp<=0)terminal(world,p,'catch');
 }
}
function rollReward(world,fish){
 const F=world.data.fishing,chosen=pick(world,fish?.sets||[],100000),set=F.sets?.[chosen?.[0]];if(!set?.items?.length)return null;
 const it=pick(world,set.items,Math.max(set.items.reduce((s,x)=>s+x[1],0),set.total||0));if(!it)return null;
 const lo=Math.max(1,it[2]||1),hi=Math.max(lo,it[3]||lo),def=world.data.itemDB.def(it[0]);if(!def)return null;
 return {item:it[0],count:world.data.itemDB.stackSize(def)>1?lo+Math.floor(world.random()*(hi-lo+1)):1};
}
async function settle(world,p,A){
 if(A.settled||A.phase!=='close')return;
 if(A.result!=='catch'){A.settled=true;return;}
 const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
 // Store the draw before awaiting persistence; a failed disk write cannot become a new roll.
 if(!A.rolled){A.draw=rollReward(world,A.fish);A.rolled=true;}
 let result='catch',reward=null;
 if(!A.draw)result='nothing';else if(!inv.canFit([A.draw]))result='full';else{if(!inv.add(A.draw.item,A.draw.count))deny('Fishing item insertion failed.');reward=A.draw;}
 const exp=A.auto?Number(world.data.exp?.levels?.[(profile.level||1)-1]?.autoFishExp)||0:Number(A.fish.exp)||0;
 // Use the core progression rules on an isolated actor so persistence can fail without duplicating EXP.
 const actor={...p,profile},events=[];if(exp>0)world.grantProgress.call({...world,changed(){},emit:(map,event)=>events.push([map,event])},actor,exp);
 if(reward)progressDekaPass({...world,changed(){}},actor,8,25,reward.item,1);
 const quest=result==='catch'?questFish(world,actor,1,{profile,emit:false,itemIndex:reward?.item}):null;
 const leveled=profile.level>p.profile.level;
 const committed=await commitLife(world,p,profile,{rewardProgress:true,...(leveled?{stats:actor.stats,hp:actor.hp,mp:actor.mp}:{})});
 for(const [map,event]of [...events.filter(([,e])=>e.type!=='levelup'||e.level>committed.concurrentLevel),...committed.notices])world.emit(map,event);
 quest?.commit();
 A.result=result;A.reward=reward;A.exp=exp;A.settled=true;
 world.emit(p.map,{type:'fishing',actorId:p.id,result,fish:A.fishIndex,item:reward?.item||null,exp,instanceId:p.instanceId||null});
}
export async function fishingCommand(world,p,input){
 validateLife(input,FISHING_SCHEMAS);
 return serializeLife(p,async()=>{
  if(!world.data.fishing||!world.data.itemDB)deny('Fishing catalog is unavailable.');
  const fields={start:[],pull:['sessionId','pull'],sync:['sessionId'],stop:['sessionId']}[input.operation];
  if(!fields||Object.keys(input).some(k=>!['token','type','operation',...fields].includes(k)))deny('Invalid fishing operation fields.');
  if(input.operation==='start'){
   if(p.fishing&&(!p.fishing.settled||p.fishing.phase!=='close'))deny('Already fishing.');
   const {R,S}=requirements(world,p),profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
   const bait=Object.entries(world.data.fishing.baits||{}).sort((a,b)=>b[1]-a[1]).find(([i])=>inv.count(i)>0)?.[0];
   if(bait&&!inv.remove(Number(bait),1))deny('Fishing bait consumption failed.');
   await commitLife(world,p,profile);p.path=[];p.yaw=Math.atan2(-(S.x-p.x),-(S.z-p.z));
   p.fishing={id:randomUUID(),phase:'cast',rod:R,spot:S,cell:S.cell,bait:Number(bait)||null,auto:!!R.auto,t:0,pull:false,map:p.map,instanceId:p.instanceId||null,channel:p.channel??0,x:p.x,z:p.z,started:world.now()};
  }else{
   const A=p.fishing;if(!A||typeof input.sessionId!=='string'||input.sessionId!==A.id)deny('This fishing cast expired.');
   if(!valid(world,p,A)&&A.phase!=='close')terminal(world,p,'miss');
   if(input.operation==='pull'){if(typeof input.pull!=='boolean'||A.phase!=='fight')deny('Pull only during a fishing fight.');A.pull=input.pull;}
   if(input.operation==='stop')terminal(world,p,'miss');
   await settle(world,p,A);
  }
  world.changed(p);return fishingState(p);
 });
}
