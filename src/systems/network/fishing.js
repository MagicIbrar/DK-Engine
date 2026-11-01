// Keep the authored windows/music/class motions; gauges/results come exclusively from the server.
import {itemInfo} from '../life/common.js';
export function installSharedFishing(game,network){
 const fishing=game.life?.fishing;if(!fishing)return;
 let opening=false,syncing=false,pulling=false,pullAt=0,syncAt=0,renderId=null,closedId=null;
 const send=(operation,extra={})=>network.action('fishing',{operation,...extra});
 fishing._useBait=()=>null;fishing._rollSet=()=>null;
 fishing._bite=fishing._autoCatch=fishing._fight=fishing._finish=()=>false;
 fishing.start=async()=>{
  if(opening)return false;opening=true;
  try{return !!await send('start');}finally{opening=false;}
 };
 if(game.skills?.useSkill){const useSkill=game.skills.useSkill.bind(game.skills);game.skills.useSkill=(id,opts)=>{
  if(fishing._isFishingSkill(id)){void fishing.start();return true;}return useSkill(id,opts);
 };}
 fishing.stop=()=>{const id=fishing.active?.id;if(id)void send('stop',{sessionId:id});};
 const previousActorVisual=network.actorMount;
 network.actorMount=(actor,row)=>{
  previousActorVisual?.(actor,row);
  if(actor.kind!=='player'||!actor.model)return;
  const A=row.fishing;
  if(!A){if(actor._sharedFishing){actor._sharedFishing=null;actor._networkAnimHold=0;}return;}
  if(A.phase==='close'&&!A.settled)return;
  const key=A.phase==='cast'?'OPENFISHING:0':A.phase==='fight'?(A.pulling?'FISHFIGHTING:0':'FISHFIGHTING:1'):
   A.result==='catch'||A.result==='full'?'CLOSEFISHING:0':A.result==='snap'?'CLOSEFISHING:1':'CLOSEFISHING:2';
  const signature=`${A.id}:${key}`,motions=game.life.data?.classMotions?.[row.classIndex]?.fishing;
  if(A.phase!=='close')actor._networkAnimHold=performance.now()+2000;
  if(actor._sharedFishing===signature)return;actor._sharedFishing=signature;
  const rec=motions?.[key];if(!rec)return;
  if(A.phase==='close')actor._networkAnimHold=performance.now()+(rec.t||3)*1000;
  actor.play(`fish:${key}`,{anim:rec.anim,timeLength:rec.t,loop:A.phase==='fight',fade:.12,onEnd:A.phase==='cast'?()=>{
   if(actor.disposed||actor._sharedFishing!==signature)return;const keep=motions['OPENFISHING:1'];if(keep)actor.play('fish:OPENFISHING:1',{anim:keep.anim,timeLength:keep.t,loop:true,fade:.12});
  }:undefined});
 };
 const paint=async()=>{
  const A=network.self?.fishing;
  if(!A){if(fishing.active)fishing._end();renderId=null;return;}
  if(A.id===closedId)return;
  const before=fishing.active;fishing.active={...A};
  if(A.phase==='close'){
   if(!A.settled)return;
   closedId=A.id;fishing._showPhase('none');
   if(A.item){await fishing._say(11,'item',itemInfo(game,A.item.item)?.name||'');void fishing._showCatch(A.item.item);
    game.events?.emit?.('fish',{count:1,fish:A.fishIndex,item:A.item.item,server:true});}
   else {const code={snap:0,escape:1,nothing:7,full:2,miss:14}[A.result];if(code!=null)await fishing._say(code);}
   const key=A.result==='catch'||A.result==='full'?'CLOSEFISHING:0':A.result==='snap'?'CLOSEFISHING:1':'CLOSEFISHING:2';
   fishing._anim(key,false,()=>{if(fishing.active?.id!==A.id)return;fishing._end();renderId=null;if(A.auto&&A.result==='catch')void fishing.start();});
   return;
  }
  if(renderId!==A.id){
   renderId=A.id;pulling=false;game.controller?.stop?.();fishing.life.emotes?.cancel();
   if(game.player){game.player.lastCombat=null;game.player._gpState='idle';game.player._gpHold=0;game.player.faceTowards?.(A.spot.x,A.spot.z);}
   fishing._anim('OPENFISHING:0',false,()=>{if(fishing.active?.id===A.id&&fishing.active.phase==='cast')fishing._anim('OPENFISHING:1',true);});
   fishing._music(1000);const win=await game.uiwin.open('fishing');
   if(fishing.active?.id!==A.id||fishing.active.phase==='close')return;fishing.win=win;
   if(fishing.active.phase!==A.phase){void paint();return;}
  }
  fishing._showPhase(A.phase);
  if(A.phase==='fight'&&before?.phase!=='fight'){
   fishing._music(1001);fishing.win?.control('pan_fish_rank').setImage('none','fishing_rank',Math.max(1,A.fish?.rank||1));
   fishing._anim(A.pulling?'FISHFIGHTING:0':'FISHFIGHTING:1',true);
  }else if(A.phase==='fight'&&before?.pulling!==A.pulling)fishing._anim(A.pulling?'FISHFIGHTING:0':'FISHFIGHTING:1',true);
 };
 game.events?.on?.('server:profile',()=>{void paint();});
 fishing.update=dt=>{
  const A=fishing.active;if(!A)return;
  const now=performance.now();
  if(game.player?.dead||game.player?.state&&!String(game.player.state).startsWith('fish:')&&A.phase!=='close'){
   if(!syncing&&now>=syncAt){syncAt=now+500;fishing.stop();}return;
  }
  if(A.phase==='fight'){
   const pull=!!(fishing._pull||fishing._mousePull);
   if(pull!==pulling&&now>=pullAt){pulling=pull;pullAt=now+100;void send('pull',{sessionId:A.id,pull});}
  }
  // Completion is settled through an authenticated serialized command, never a browser reward callback.
  if(!syncing&&now>=syncAt&&!A.settled){syncAt=now+500;syncing=true;void send('sync',{sessionId:A.id}).finally(()=>{syncing=false;});}
  const w=fishing.win;if(!w)return;
  if(A.phase==='cast')w.control('pro_casting').setGauge(Math.min(1,A.t/A.castMs));
  else if(A.phase==='fight'){
   const lf=Math.max(0,A.lineHp/A.rod.maxHp),ff=Math.max(0,A.fishHp/A.fish.maxHp);
   w.control('pro_line').setGauge(lf);w.control('pro_fish').setGauge(ff);
   w.control('pan_line').setRect(Math.round(lf*343),1,44,23);w.control('pan_fish').setRect(Math.round(ff*343),47,44,23);
   const shake=A.resisting?Math.random()*4-2:0;w.control('pan_fish').el.style.transform=shake?`translate(${shake}px, ${Math.random()*2-1}px)`:'';
   const reel=w.control('pan_reel');reel.data.rot=(reel.data.rot||0)+(A.pulling?dt*720:0);if(reel.bg)reel.bg.style.transform=`rotate(${reel.data.rot}deg)`;
  }
 };
}
