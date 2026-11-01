// Original profession windows render canonical state; all resource/job mutations are intents.
import {box,fmt,strNow,msgRef,numText,itemInfo} from '../life/common.js';
export function installSharedProduction(game,network){
 const craft=game.life?.craft;if(!craft)return;
 const empty={type:null,exp:0,resets:0,slots:craft.C?.slots?.base||1,jobs:[]};
 Object.defineProperty(craft,'st',{get:()=>game.save.life?.craft||empty});
 const S=code=>strNow(game,2900,code);
 const send=async body=>{
  const response=await network.action('production',body);if(!response)return false;
  const result=response.productionResult;
  if(result?.accepted===false){await msgRef(game,2901,140,'NORMAL','err');return false;}
  if(body.operation==='make')await msgRef(game,2901,7,'NORMAL','sys');
  for(const r of result?.jobs||(result?.success!=null?[result]:[])){
   if(r.accepted===false){await msgRef(game,2901,140,'NORMAL','err');continue;}
   if(r.success>0){await msgRef(game,2901,16,'NORMAL','item');await msgRef(game,2900,138,'NORMAL','item');}
   if(r.success<r.count)await msgRef(game,2901,15,'NORMAL','err');
   game.events?.emit?.('life:craft',{phase:'receive',recipe:r.recipe,count:r.count,success:r.success,item:r.item,type:r.craftType,server:true});
  }
  craft._afterJobChange();return true;
 };
 craft.make=(recipe,count=1)=>send({operation:'make',recipe:Number(recipe),count});
 craft.receive=i=>{const job=craft.st.jobs[i];return job?send({operation:'receive',jobId:job.id}):Promise.resolve(false);};
 craft.receiveAll=()=>send({operation:'receiveAll'});
 craft.cancel=async i=>{
  const job=craft.st.jobs[i];if(!job)return false;if(Date.now()>=job.end)return craft.receive(i);
  const rec=craft.recipe(job.recipe),equipment=rec?.mats.some(([item])=>itemInfo(game,item)?.slot);
  if(await box(game,S(equipment?223:222),{title:S(221),kind:'yesno'})!=='yes')return false;
  return send({operation:'cancel',jobId:job.id});
 };
 craft.chooseMastery=async mastery=>{
  if(craft.st.type===mastery)return false;
  const n=craft.st.type?(craft.st.resets||0)+1:0,cost=craft.st.type?(craft.C.resetCost?.[Math.min(n,craft.C.resetCost.length)-1]??10000000):0;
  const text=fmt(S(210+mastery),craft.st.type?n:1)+(cost>0?`\n${numText(cost)} DIL`:'');
  if(await box(game,text,{title:S(210),kind:'yesno'})!=='yes')return false;
  const result=await send({operation:'mastery',mastery});
  if(result){await msgRef(game,2901,1,'NORMAL','sys');if(craft.win?.isOpen)craft._openMain(craft.win);}
  return result;
 };
 craft.addSlot=async()=>{if(await box(game,S(216),{title:S(215),kind:'yesno'})!=='yes')return false;return send({operation:'slot'});};
 craft._applyCatalyst=async win=>{
  const job=craft.st.jobs[win.data.slot];if(!job||!win.data.item)return false;
  const result=await send({operation:'catalyst',jobId:job.id,item:Number(win.data.item)});
  if(result){await msgRef(game,2901,25,'NORMAL','sys');win.close();}return result;
 };
 game.events?.on?.('server:profile',()=>{
  const signature=JSON.stringify(game.save.life?.craft||null);if(signature===craft._serverSignature)return;craft._serverSignature=signature;
  craft._afterJobChange();const win=game.uiwin?.window?.('craftmastery');if(win?.isOpen)craft._refreshMastery(win);
 });
}
