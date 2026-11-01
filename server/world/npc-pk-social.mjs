import {sameScene} from './scene.mjs';
import {pkRefusal} from './field-pk.mjs';
import {npcPersona} from './npc-persona.mjs';

// ENGINE-CHOSEN speech only: level differences, willingness and quiet periods
// are personality policy, never native PK authority or evidence of a murder.
export const NPC_PK_SOCIAL_POLICY=Object.freeze({repeatMs:60000,targetRepeatMs:300000,hitFreshMs:5000,levelGap:20,attackerGap:10,near:24,maxTargets:16});
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const live=(world,p)=>!!p&&world.players.get(p.account)===p&&!p.leaving&&!p.dead&&!(p.gmAuthorized&&p.profile.gm?.hide);

/** Pure decision. Root applies memory only after ordinary chat is accepted. */
export function npcPkSocialDecision(world,p,brain,{hit=null,visiblePlayers=[]}={}){
 if(!live(world,p)||p.profile?.npcPlayer!==true||p.profile.authority!=='server'||brain?.pkSocialEnabled===false)return null;
 const now=world.now(),policy=NPC_PK_SOCIAL_POLICY,memory=brain?.pkSocial||{},persona=npcPersona(p.profile);
 if(now<Number(memory.nextAt||0))return null;
 const prior=Array.isArray(memory.targets)?memory.targets:[],ready=q=>!prior.some(row=>row.id===q.id&&now-Number(row.at)<policy.targetRepeatMs);
 const result=(q,text,topic,provenance,partyId)=>({text,topic,targetId:q.id,...(partyId?{partyId}:{}),cooldownUntil:now+policy.repeatMs,memory:{nextAt:now+policy.repeatMs,targets:[...prior.filter(row=>row.id!==q.id&&now-Number(row.at)<policy.targetRepeatMs),{id:q.id,at:now}].slice(-policy.maxTargets)},provenance});
 // A caller's packet is insufficient: use the actual retained host event and
 // current native hit/battle markers, excluding duel/guild-war/cosmetic claims.
 const event=hit&&(world.events||[]).find(e=>e===hit);
 const party=p.partyId&&world.parties?.get(p.partyId);
 if(event?.type==='damage'&&Number(event.amount)>0&&party?.members.includes(p.id)&&persona.social==='social'&&persona.chat!=='quiet'&&['expert','elite'].includes(persona.combatSkill)){
  const source=[...world.players.values()].find(q=>q.id===event.sourceId),victim=[...world.players.values()].find(q=>q.id===event.targetId),age=now-Number(victim?.pvpLastHit?.at),battleAge=now-Number(source?.pkBattleAt);
  if(live(world,source)&&victim&&world.players.get(victim.account)===victim&&!victim.leaving&&victim!==p&&sameScene(p,source)&&sameScene(p,victim)&&victim.partyId===p.partyId&&party.members.includes(victim.id)&&victim.pvpLastHit?.by===source.id&&age>=0&&age<=policy.hitFreshMs&&source.pkBattleVictim===victim.id&&battleAge>=0&&battleAge<=policy.hitFreshMs&&!source.duelId&&!victim.duelId&&pkRefusal(world,p,source)===null&&distance(p,source)<=policy.near&&distance(p,victim)<=policy.near&&Number(p.profile.level)-Number(victim.profile.level)>=policy.levelGap&&Number(source.profile.level)-Number(victim.profile.level)>=policy.attackerGap&&ready(source))return result(source,persona.tone==='direct'?'Pick on someone your own level.':'Leave the lowbie alone.','pk-party-defense','Actual retained positive field-PK hit against a current nearby party ally; ENGINE-CHOSEN level-gap/personality speech.',p.partyId);
 }
 if(persona.social==='outlaw'||persona.confidence==='confident')return null;
 for(const visible of visiblePlayers){
  const q=[...world.players.values()].find(a=>a.id===visible?.id);
  if(!live(world,q)||q===p||!sameScene(p,q)||distance(p,q)>policy.near||!ready(q)||visible.nameplate?.nameColor!=='wanted2'||!(Number(visible.nameplate?.wanted)>0)||!(Number(q.profile.life?.grade?.chaotic)>0))continue;
  return result(q,persona.confidence==='tentative'?'You are not going to PK us too, right?':'We good, or should I keep my distance?','niete-caution','Actual visible native wanted/red projection corroborated by current positive Niete state; question only, including safe maps.');
 }
 return null;
}
