import {randomUUID} from 'node:crypto';
import {socialRef} from './social-state.mjs';
import {npcPlacements,nearbyNpc} from './npc-services.mjs';
import {sameScene} from './scene.mjs';
import {guildWarOpponents} from './guild-war-pvp.mjs';
import {warState,WAR_DAYS} from '../../src/systems/extras/guildextras-rules.js';
import {GUILD_WAR_CHOSEN as W} from '../../src/config/engine-chosen-guild.js';

// ENGINE-CHOSEN occasional, voluntary social decisions. Native guild commands
// retain all costs, memberships, permissions, CAS, admission and combat rules.
export const NPC_GUILD_LIFE_POLICY=Object.freeze({intervalMs:60000,targetRange:24,founderModulo:6});
const dist=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const memberGuild=(world,p)=>Object.values(world.socialState?.guilds||{}).find(g=>g.members?.some(m=>m.ref===socialRef(p)));
function seed(profile){let n=0;for(const c of String(profile.id||profile.name||''))n=(Math.imul(n,31)+c.charCodeAt(0))>>>0;return n;}
export function npcGuildPreference(profile){
 const explicit=profile.npcGuildLife||{},social=profile.npcTraits?.social==='social';
 return {willing:explicit.enabled!==false&&social,founder:explicit.founder??seed(profile)%NPC_GUILD_LIFE_POLICY.founderModulo===0,war:explicit.war??['expert','elite'].includes(profile.npcTraits?.pvpSkill)};
}
function available(world,p,b,isNpc){
 if(!p||!isNpc(p)||p.profile?.authority!=='server'||world.players.get(p.account)!==p||p.leaving||p.dead||p.sceneTransition||p.instanceId||p.duelId||p.tradeId||p.tradeCommitting||p.pcShopOpen||p.path?.length||p._skills?.engine.casting||p.attackTarget||p.commandActive||b.follow||b.lure||b.questId||b.refineUid||b.equipmentService||b.prepareUntil>world.now()||p.profile.npcEquipment?.phase==='working')return false;
 if(Object.keys(p.profile.quests?.active||{}).length)return false;
 const task=b.taskGoal||p.profile.npcRoutine;
 if(task&&task.until>world.now()&&task.kind!=='rest')return false;
 const party=world.parties?.get(p.partyId);
 if(party?.members?.some(id=>[...world.players.values()].some(q=>q.id===id&&!isNpc(q))))return false;
 if(p.pvpLastHit&&world.now()-p.pvpLastHit.at<10000)return false;
 return npcGuildPreference(p.profile).willing;
}
function allBots(g,isNpcRef){return !!g?.members?.length&&g.members.every(m=>isNpcRef(m.ref))&&isNpcRef(g.master);}
const blocked=reason=>({blockedReason:reason,policy:'ENGINE-CHOSEN'});
function service(world,p,action){const row=npcPlacements(world,p.map).filter(r=>r.roles.includes('GUILD')).sort((a,b)=>dist(p,a)-dist(p,b))[0];return row?{action,at:{map:p.map,x:row.x,z:row.z,npc:row.npcIndex},near:!!nearbyNpc(world,p,{npcIndex:row.npcIndex,role:'GUILD'}),policy:'ENGINE-CHOSEN'}:blocked('native-guild-service-unavailable');}

/** Pure current-context plan. isNpcRef must resolve durable NPC ownership;
 * disconnected unknown members conservatively prevent bot-only decisions.
 * Paid profile changes require the SAME atomic social/NPC store transaction. */
export function npcGuildLifePlan(world,p,b={},options={}){
 const isNpc=options.isNpc||(()=>false),isNpcRef=options.isNpcRef||(ref=>[...world.players.values()].some(q=>isNpc(q)&&socialRef(q)===ref));
 if(!available(world,p,b,isNpc))return null;
 if(!world.socialState||typeof world.saveSocialTransaction!=='function')return blocked('durable-social-storage-unavailable');
 const pref=npcGuildPreference(p.profile),g=memberGuild(world,p),ref=socialRef(p),now=world.now(),cfg=world.data.guild?.config;
 const others=[...world.players.values()].filter(q=>q!==p&&available(world,q,options.brainFor?.(q)||{},isNpc)&&sameScene(p,q)&&dist(p,q)<=12);
 if(!g){
  const invitation=Object.values(world.socialState.guilds).filter(row=>allBots(row,isNpcRef)).flatMap(row=>(row.invites||[]).filter(i=>i.to===ref&&others.some(q=>socialRef(q)===i.from)).map(i=>({row,i}))).sort((a,b)=>a.i.expiresAt-b.i.expiresAt)[0];
  if(invitation)return {action:{type:'guild',operation:'accept',id:invitation.i.id},policy:'ENGINE-CHOSEN'};
  if(!pref.founder||!cfg||Number(cfg.ADV)||Number(cfg.PEERAGE)||p.profile.level<Number(cfg.LEVEL)||!Number.isSafeInteger(Number(cfg.MONEY))||Number(cfg.MONEY)<0||p.profile.dil<Number(cfg.MONEY))return null;
  if(!options.socialProfileSupported)return blocked('atomic-npc-social-unavailable');
  // Alphabetic stable name; a conflict never renames/deletes another guild.
  let v=seed(p.profile),suffix='';for(let i=0;i<7;i++){suffix+=String.fromCharCode(65+v%26);v=Math.floor(v/26);}
  const name='Wayfarers'+suffix;if(Object.values(world.socialState.guilds).some(row=>row.name.toLowerCase()===name.toLowerCase()))return blocked('guild-name-conflict');
  return service(world,p,{type:'guild',operation:'create',name});
 }
 if(g.master!==ref||!allBots(g,isNpcRef))return null;
 const wars=(world.socialState.guildWars||[]).filter(w=>['pending','active'].includes(warState(w,now,W.PENDING_TIMEOUT_MS)));
 if(pref.war){
  const incoming=wars.find(w=>w.status==='pending'&&w.to===g.id&&allBots(world.socialState.guilds[w.from],isNpcRef)&&others.some(q=>socialRef(q)===world.socialState.guilds[w.from]?.master&&npcGuildPreference(q.profile).war));
  if(incoming)return {action:{type:'guild',operation:'warAccept',id:incoming.id},policy:'ENGINE-CHOSEN'};
 }
 const cap=Number(cfg?.[`LEVEL${g.level??1}_MEMBER`]);
 if(Number.isInteger(cap)&&g.members.length<cap){
  const candidate=others.find(q=>!memberGuild(world,q)&&!(g.invites||[]).some(i=>i.to===socialRef(q)));   // invitations have no timeout (LANE-61: none in any source)
  if(candidate)return {action:{type:'guild',operation:'invite',targetId:candidate.id},policy:'ENGINE-CHOSEN'};
 }
 if(!pref.war||wars.some(w=>w.from===g.id||w.to===g.id))return null;
 const target=others.find(q=>{const other=memberGuild(world,q);return other&&other.id!==g.id&&other.master===socialRef(q)&&allBots(other,isNpcRef)&&npcGuildPreference(q.profile).war&&!Object.values(world.socialState.alliances||{}).some(a=>a.guilds?.includes(g.id)&&a.guilds.includes(other.id))&&!wars.some(w=>w.from===other.id||w.to===other.id);});
 if(!target)return null;
 const days=WAR_DAYS[0],needDil=W.COST_BY_DAYS[days].dil,needPoints=W.COST_BY_DAYS[days].guildPoints;   // ONLINE cost table (LANE-61)
 if((g.dil||0)<needDil){
  const unit=Number(cfg?.DILTOCON),gap=needDil-(g.dil||0),amount=Math.ceil(gap/unit)*unit;
  if(!Number.isSafeInteger(unit)||unit<1||!Number.isSafeInteger(amount)||p.profile.dil-amount<Number(cfg.MONEY))return blocked('earned-guild-dil-insufficient');
  if(!options.socialProfileSupported)return blocked('atomic-npc-social-unavailable');
  return service(world,p,{type:'guild',operation:'deposit',amount});
 }
 if((g.gpoint||0)<needPoints){
  const unit=Number(cfg?.ADVPOINTRATIO),amount=(needPoints-(g.gpoint||0))*unit;
  if(!Number.isSafeInteger(unit)||unit<1||unit!==Number(cfg.ADVTOCON)||!Number.isSafeInteger(amount)||(p.profile.quests?.points?.adv||0)<amount)return blocked('earned-adventure-points-insufficient');
  if(!options.socialProfileSupported)return blocked('atomic-npc-social-unavailable');
  return {action:{type:'guild',operation:'donateAdv',amount},policy:'ENGINE-CHOSEN'};
 }
 return {action:{type:'guild',operation:'warDeclare',targetId:target.id,days},policy:'ENGINE-CHOSEN'};
}

export async function npcGuildLifeStep(world,p,b,{act,move,...options}={}){
 if(world.now()<(b.guildLifeAt||0))return {handled:false};
 const plan=npcGuildLifePlan(world,p,b,options);if(!plan)return {handled:false};
 b.guildLifeAt=world.now()+NPC_GUILD_LIFE_POLICY.intervalMs;
 if(plan.blockedReason)return {handled:false,...plan};
 if(plan.at&&!plan.near){if(move)await move(p,plan.at);return {handled:!!move,plan};}
 if(typeof act!=='function')return {handled:false,blockedReason:'ordinary-action-unavailable'};
 try{await act(p,{...plan.action,revision:world.socialState.revision,requestId:randomUUID()});return {handled:true,plan};}
 catch(error){if(!error.status)throw error;return {handled:false,blockedReason:error.message,status:error.status};}
}

/** Native registered war opponents only; never forced PK or safe-map attacks. */
export function npcGuildWarTarget(world,p,b={},options={}){
 if(!available(world,p,b,options.isNpc||(()=>false))||!npcGuildPreference(p.profile).war)return null;
 return guildWarOpponents(world,p).filter(q=>dist(p,q)<=NPC_GUILD_LIFE_POLICY.targetRange).sort((a,c)=>dist(p,a)-dist(p,c)||String(a.id).localeCompare(String(c.id)))[0]||null;
}
