import {npcSupport} from './npc-tactics.mjs';
// ENGINE-CHOSEN preparation opportunities; native event clocks and casts remain authoritative.
export const NPC_EVENT_SUPPORT_POLICY=Object.freeze({preGateSeconds:15,refreshMs:210000,windowMs:15000,pollMs:5000});
export async function npcEventSupport(world,p,b,act,goal,{support=npcSupport}={}){
 const instance=world.instances?.get(p.instanceId),run=instance?.run,party=p.partyId&&world.parties?.get(p.partyId),now=world.now(),P=NPC_EVENT_SUPPORT_POLICY;
 if(!['deadFront','iceCastle'].includes(instance?.kind)||!run||run.ended||run.won!=null||instance.closeRequested||!instance.members?.has(p.id)||!instance.admitted?.has(p.characterId)||!party?.members.includes(p.id)||p.dead||p.leaving||p.sceneTransition||p.tradeId||p.progressCommitting||p.commandActive)return false;
 if(!['waitStart','fortress'].includes(run.phase)||goal?.waiting&&goal.stage!=='preparing during event countdown')return false;
 let state=b.eventSupport;
 if(!state||state.run!==run||state.instance!==instance||state.session!==p.token||state.partyId!==p.partyId)state=b.eventSupport={run,instance,session:p.token,partyId:p.partyId,nextAt:0,nextBuffAt:0,windowUntil:0,preStarted:false,battleSeen:false};
 if(run.phase==='waitStart'&&Number.isFinite(run.phaseT)&&run.phaseT>0&&run.phaseT<=P.preGateSeconds&&!state.preStarted){state.preStarted=true;state.windowUntil=now+Math.min(P.windowMs,run.phaseT*1000);}
 if(run.phase==='fortress'){
  if(!state.battleSeen){state.battleSeen=true;state.nextBuffAt=now+P.refreshMs;if(!state.preStarted)state.windowUntil=now+P.windowMs;}
  else if(now>=state.nextBuffAt){state.windowUntil=now+P.windowMs;state.nextBuffAt=now+P.refreshMs;}
 }
 if(now<state.nextAt||p._skills?.engine?.active||p._skills?.engine?.casting)return false;
 state.nextAt=now+P.pollMs;
 // Ordinary support prioritizes resurrection/healing. Refresh opportunities
 // fill missing native effects, never replace useful stronger/long-lived buffs.
 return support(world,p,act,{buff:now<state.windowUntil});
}
