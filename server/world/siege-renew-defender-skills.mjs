// Native defender service. Owner explicitly approved the documented recipient
// scope on 2026-10-13; carried lord DIL is the wallet. Castle-owned durable cooldown
// custody is ENGINE-CHOSEN. Unbound marker statuses 50175–50177 are never applied.
import {randomUUID} from 'node:crypto';
import {characterRef} from '../accounts/character-ref.mjs';
import {nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {sceneKey} from './scene.mjs';
import {socialTransaction} from './social-state.mjs';
import {siegeRenewDefenderSkillCatalog,SIEGE_RENEW_DEFENDER_SKILL_DEPENDENCIES} from '../../src/game/siege-renew-defender-skill-rules.js';
import {defenderSkillRecipients,skillCooldownLeft} from '../../src/game/siege-renew-proposed-rules.js';
const castles=[193,194,195],lorenzo={193:6008,194:6009,195:6010};
const refuse=(cate,code,status=409)=>{throw Object.assign(Error(`siege:${cate}:${code}`),{status,code:'SIEGE_RENEW_REFUSED'});};
const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
export function siegeRenewDefenderSkillData(world){return siegeRenewDefenderSkillCatalog(world.data.eventData,world.data.skillStatuses);}
export function siegeRenewDefenderSkillSnapshot(world){
 const catalog=siegeRenewDefenderSkillData(world);
 return {available:!!catalog,activation:catalog?'native-menu':'closed',sourcePresent:!!catalog,dependencies:catalog?[]:[...SIEGE_RENEW_DEFENDER_SKILL_DEPENDENCIES],skills:(catalog||[]).map(s=>({selection:s.selection,name:s.name,guildLevel:s.guildLevel,dil:s.dil,durationMs:s.durationMs,cooldownMs:s.cooldownMs,statusIndex:s.statusIndex,markerIndex:s.markerIndex,association:s.association}))};
}
/** The host accepts only the native menu selection, never caller-provided effects. */
export async function siegeRenewDefenderSkillCommand(world,p,input){
 if(!input||input.type!=='siegerenew'||input.operation!=='skill'||Object.keys(input).some(k=>!['token','type','operation','npcIndex','selection'].includes(k)))fail('Send original defender skill intent only.');
 if(input.selection!==undefined&&(!Number.isInteger(input.selection)||input.selection<0||input.selection>2))fail('Choose an original defender skill.');
 if(world.players.get(p.account)!==p||p.leaving||p.dead||p.sceneTransition||p.tradeId)fail('This service is unavailable while disconnected, dead, travelling or trading.',409);
 const map=Number(p.map),b=world.siegeRenewLive?.battles.get(map),record=b?.participants.get(p.id);
 if(!castles.includes(map)||!b||b.phase!=='battle'||b.capturing||world.now()>=b.endAt||p.instanceId!==b.instanceId||p.profile.instance?.id!==b.instanceId||world.maps.get(sceneKey(map,b.instanceId))!==b.scene||!record||record.account!==p.account||record.characterId!==p.characterId)refuse(castles.includes(map)?map:193,118);
 const npc=Number(input.npcIndex),row=Number.isInteger(npc)&&npc===lorenzo[map]&&nearbyNpc(world,p,{npcIndex:npc,jobType:129,jobIndex:map,radius:8});
 if(!row||!offersOriginalJob(world,row,129,map))fail('Stand near the original castle Lorenzo.',403);
 const ref=characterRef(p.account,p.characterId),guild=Object.values(world.socialState?.guilds||{}).find(g=>g.members?.some(m=>m.ref===ref));
 if(!guild)refuse(map,115,403);
 if(world.socialState?.siegeRenew?.castles?.[map]?.owner?.guild!==guild.id||record.guild!==guild.id||record.side!=='defender')refuse(map,115,403);
 if(guild.master!==ref)refuse(map,112,403);
 if(!siegeRenewDefenderSkillData(world))refuse(701,214,503);
 return activateNative(world,p,{map,b,record,guild,ref,input});
}
// Native requirements and castle dungeon refusals; the approved scope and
// ENGINE-CHOSEN durable cooldown are tested separately from guard deployment.
// same reading as server/world/guilds.mjs level(): an explicit level, else the LEVELSTEP thresholds of the guild point
function guildLevel(world,g){if(Number.isInteger(g?.level))return g.level;let n=1;for(let i=1;i<=15;i++)if(Number(g?.gpoint)>=Number(world.data.guild?.config?.[`LEVELSTEP${i}`]))n=i;return n;}
async function activateNative(world,p,{map,b,record,guild,ref,input}){
 if(!Number.isInteger(input.selection))fail('Choose an original defender skill.');
 const skill=siegeRenewDefenderSkillData(world)[input.selection];
 if(guildLevel(world,guild)<skill.guildLevel)refuse(map,114,403);
 const verdict=(state,refNow,dil)=>{
  const s=state?.siegeRenew?.castles?.[map],g=Object.values(state?.guilds||{}).find(x=>x.members?.some(m=>m.ref===refNow));
  if(!g||s?.owner?.guild!==g.id)refuse(map,115,403);if(g.master!==refNow)refuse(map,112,403);
  if(guildLevel(world,g)<skill.guildLevel)refuse(map,114,403);
  if(skillCooldownLeft(s,input.selection,world.now())>0)refuse(map,117);
  if(!(Number(dil)>=skill.dil))refuse(map,116);
  return s;
 };
 verdict(world.socialState,ref,p.profile.dil);
 const live=()=>{if(world.siegeRenewLive?.battles.get(map)!==b||b.phase!=='battle'||b.capturing||world.now()>=b.endAt||p.instanceId!==b.instanceId||b.participants.get(p.id)!==record||world.maps.get(sceneKey(map,b.instanceId))!==b.scene)refuse(map,118);};
 const intent={get revision(){return world.socialState?.revision;},requestId:`renew-skill-${randomUUID()}`};
 const committed=await socialTransaction(world,p,intent,(state,profile,refNow)=>{
  live();const s=verdict(state,refNow,profile.dil),now=world.now(),readyAt=now+skill.cooldownMs;
  profile.dil-=skill.dil;s.skills={...(s.skills||{}),[input.selection]:{readyAt,at:now,ref:refNow,guild:guild.id,durationMs:skill.durationMs}};
  return {readyAt};
 });
 // Statuses are applied only after the debit and the cooldown are durable.
 const owner=world.socialState?.siegeRenew?.castles?.[map]?.owner?.guild||null,players=new Map([...world.players.values()].filter(q=>!q.leaving&&q.map===map&&q.instanceId===b.instanceId).map(q=>[q.id,q]));
 const ownerRefs=new Set((world.socialState?.guilds?.[owner]?.members||[]).map(m=>m.ref));
 const ownerMembers=[...world.players.values()].filter(q=>!q.leaving&&!q.sceneTransition&&ownerRefs.has(characterRef(q.account,q.characterId)));
 const recipients=defenderSkillRecipients({selection:input.selection,participants:[...b.participants].map(([id,r])=>({player:players.get(id)||null,record:r})),ownerGuild:owner,ownerMembers});
 const {ensureSkills}=await import('./skills.mjs');
 for(const q of recipients){const sys=ensureSkills(world,q);if(sys.statuses.add(sys.game.player,skill.statusIndex,skill.durationMs,{noEffects:true}))world.changed(q);}
 return {skill:skill.name,selection:input.selection,statusIndex:skill.statusIndex,recipients:recipients.map(q=>q.id),readyAt:committed.readyAt,dil:skill.dil};
}
/** Explicit hook for integration: closure owns no effect/cooldown clocks. */
export function tickSiegeRenewDefenderSkills(world){return {active:false,sourcePresent:!!siegeRenewDefenderSkillData(world),effects:0,cooldowns:0};}
