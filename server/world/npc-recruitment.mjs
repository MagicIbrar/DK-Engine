import {npcRequestDecision} from './npc-agency.mjs';
// ENGINE-CHOSEN volunteers prefer a useful class mix, then compatible earned
// levels. This is selection only: normal party commands still own every invite.
export function npcRecruitmentCandidates(world,candidates,human){
 const party=human.partyId&&world.parties.get(human.partyId),classes=new Set((party?.members||[human.id]).map(id=>[...world.players.values()].find(p=>p.id===id)?.profile.classIndex));
 return candidates.filter(({p,b})=>{
  if(!npcRequestDecision({world,player:p,brain:b||{},requester:human,intent:'party'}).accept||p.dead||p.leaving||p.sceneTransition)return false;
  const pending=world.partyInvites?.get(p.id);if(pending&&pending.expires>world.now())return false;
  if(!p.partyId)return true;
  const crew=world.parties.get(p.partyId);return crew?.id!==party?.id&&crew?.leader===p.id&&crew.members.length<7&&!world.partyInvites?.has(human.id);
 }).sort((a,b)=>Number(classes.has(a.p.profile.classIndex))-Number(classes.has(b.p.profile.classIndex))||Math.abs(a.p.profile.level-human.profile.level)-Math.abs(b.p.profile.level-human.profile.level)||Math.hypot(a.p.x-human.x,a.p.z-human.z)-Math.hypot(b.p.x-human.x,b.p.z-human.z));
}
