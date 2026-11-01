import {sameScene,sceneKey} from './scene.mjs';

// ENGINE-CHOSEN authored request preferences, not native game rules, a model,
// or unrestricted autonomy. This pure helper never sends chat or executes an
// action; ordinary party/travel/skill/PvP authority must still approve it.
export const NPC_AGENCY_POLICY=Object.freeze({requestDistance:24,threatDistance:15,recentHitMs:10000,lowHp:.2,lureHp:.35,aggressiveLureHp:.2,prepareMp:.15});
const actions=new Set(['follow','stop','roam','lure','party','prepare','pvp']);
const movement=new Set(['follow','stop','roam','lure']);
const disruptive=new Set(['follow','lure','party','pvp']);
const human=p=>p&&p.npcPlayer!==true&&p.profile?.npcPlayer!==true;
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const live=(world,p)=>p&&world?.players?.get(p.account)===p&&!p.leaving;
const actor=(world,id)=>[...(world.players?.values()||[])].find(p=>p.id===id&&!p.leaving);
const actualParty=(world,p)=>{const party=world.parties?.get(p.partyId);return party?.members?.includes(p.id)?party:null;};
const answer=(accept,reason,text='')=>({accept,reason,text});
const agreed={follow:'I can come along.',stop:'I can wait here.',roam:'I can get back to my own route.',lure:'I can help with a careful pull.',party:'I am open to a party.',prepare:'I can get ready with you.',pvp:'I am up for a duel if the area allows it.'};

/** Stable for the same current context. `buff` is the language parser's
 * `prepare` request; informational topics remain ordinary conversation.
 * Uses existing brain.follow/taskGoal and profile.npcTraits/npcFriends fields.
 */
export function npcRequestDecision({world,player:p,brain={},requester,intent,questHelpId,now=world?.now?.()??0}={}){
 const kind=intent==='buff'?'prepare':intent;
 if(!actions.has(kind))return answer(true,'conversation');
 if(!live(world,p)||p.profile?.authority!=='server'||p.npcPlayer!==true||p.profile?.npcPlayer!==true||!live(world,requester)||requester===p)return answer(false,'unavailable','I cannot take that request right now.');
 const party=actualParty(world,p),otherParty=actualParty(world,requester),sameParty=!!party&&party===otherParty;
 const explicit=actor(world,brain.follow),leader=party&&actor(world,party.leader),owner=human(explicit)?explicit:leader!==p&&human(leader)?leader:null;
 // Ending an existing escort is permission to release its owner, even while
 // casting, threatened, dead, distant, or holding a normal service transaction.
 if(owner?.id===requester.id&&['stop','roam'].includes(kind))return answer(true,'release-escort',agreed[kind]);
 if(owner&&owner!==requester&&(movement.has(kind)||!sameParty&&disruptive.has(kind)||!sameParty&&kind==='prepare'))return answer(false,'another-companion','I am staying with someone else right now. Please check with them.');
 const humanCrew=party?.members?.some(id=>human(actor(world,id)));
 if(humanCrew&&!sameParty&&(movement.has(kind)||disruptive.has(kind)||kind==='prepare'))return answer(false,'another-companion','I am staying with my current party. Please check with them.');
 if(p.dead)return answer(false,'recovering','I need to recover before I can help.');
 if(movement.has(kind)&&!sameParty&&(!sameScene(p,requester)||distance(p,requester)>NPC_AGENCY_POLICY.requestDistance))return answer(false,'out-of-reach','Come near me before we make a movement plan.');
 if(kind==='party'&&party&&otherParty&&party!==otherParty)return answer(false,'different-party','I am already with another party.');
 const run=p.instanceId&&world.instances?.get(p.instanceId);
 const channel=run?.channels?.some(c=>c.p===p&&Number(c.end)>now);
 if(channel||brain.objectiveFlight&&run)return answer(false,'native-objective','Let me finish this dungeon or event interaction first.');
 if(p.sceneTransition||p.commandActive||p.tradeCommitting||p.progressCommitting)return answer(false,'transaction','Give me a moment to finish the action already in progress.');
 if(p._skills?.engine.casting)return answer(false,'casting','Let me finish this skill first.');
 const trade=p.tradeId&&world.trades?.get(p.tradeId);
 if(trade?.players?.includes(p))return answer(false,'trade','I am finishing a trade right now.');
 // A planned/uncommitted equipment task is interruptible by a willing request.
 // Current native command/progress/transaction locks above protect commits.
 if(p.pcShopOpen&&disruptive.has(kind))return answer(false,'shop','I am keeping my shop open for now.');
 const map=world.maps?.get(sceneKey(p.map,p.instanceId,p.channel)),members=party?.members||[p.id];
 const threatened=[...(map?.monsters?.values()||[])].some(m=>!m.dead&&members.includes(m.targetId)&&distance(p,m)<NPC_AGENCY_POLICY.threatDistance);
 const hit=p.pvpLastHit,attacker=hit&&actor(world,hit.by),recentHit=attacker&&!attacker.dead&&sameScene(p,attacker)&&Number(hit.at)<=now&&now-Number(hit.at)<NPC_AGENCY_POLICY.recentHitMs;
 const duel=p.duelId&&world.duels?.get(p.duelId),dueling=duel?.phase==='fight'&&duel.players?.includes(p);
 if(threatened||recentHit||dueling)return answer(false,'combat','I need to deal with this fight first.');
 if(disruptive.has(kind)&&!(sameParty&&['follow','lure'].includes(kind))&&((run?.kind==='dungeon'&&run.director?.phase==='running')||(['deadFront','iceCastle'].includes(run?.kind)&&['fortress','boss','battle'].includes(run.run?.phase))))return answer(false,'active-run','I want to finish this dungeon or event section first.');
 const hp=Number(p.maxHp)>0?Number(p.hp)/Number(p.maxHp):null,mp=Number(p.stats?.maxMp??p.maxMp)>0?Number(p.mp)/Number(p.stats?.maxMp??p.maxMp):null,traits=p.profile.npcTraits||{},social=traits.social||'social';
 if(hp!=null&&hp<NPC_AGENCY_POLICY.lowHp)return answer(false,'low-health','I need to recover some health first.');
 if(['lure','pvp'].includes(kind)&&hp!=null&&hp<(traits.risk==='aggressive'?NPC_AGENCY_POLICY.aggressiveLureHp:NPC_AGENCY_POLICY.lureHp))return answer(false,'risk','I do not want to take that fight at this health.');
 if(kind==='prepare'&&mp!=null&&mp<NPC_AGENCY_POLICY.prepareMp)return answer(false,'low-mana','I need to recover some mana before preparing.');
 const friend=Array.isArray(requester.profile?.npcFriends)&&requester.profile.npcFriends.includes(String(p.profile.name||'').toLowerCase()),goal=brain.taskGoal||p.profile.npcRoutine,goalActive=!!(goal&&['quest','farm','merchant','dungeon','event'].includes(goal.kind)&&Number(goal.until)>now)||p.profile.npcEquipment?.phase==='working'||!!brain.refineRestore;
 if(!sameParty&&owner!==requester&&['solo','outlaw'].includes(social)&&['follow','lure','party','prepare'].includes(kind)){
  if(social==='solo'&&friend&&!goalActive&&(['follow','prepare'].includes(kind)||kind==='party'&&!otherParty))return answer(true,'friend-between-goals',agreed[kind]);
  return answer(false,social==='outlaw'?'outlaw-preference':'solo-preference',social==='outlaw'?'I am choosing my own route. I am not taking that request.':'Thanks, but I want to do this on my own for now.');
 }
 // A social preference is not blanket permission to abandon a current goal.
 // Planned gear work remains interruptible; native commit locks above win.
 const personalGoal=goal&&['quest','farm','merchant','dungeon','event'].includes(goal.kind)&&Number(goal.until)>now;
 const sameQuestHelp=kind==='party'&&goal?.kind==='quest'&&Number.isSafeInteger(questHelpId)&&questHelpId===Number(brain.questId)&&!!p.profile.quests?.active?.[questHelpId];
 if(!sameParty&&owner!==requester&&personalGoal&&disruptive.has(kind)&&!sameQuestHelp)return answer(false,'current-goal',goal.kind==='merchant'?'I am finishing my shop run. Maybe afterward.':goal.kind==='quest'?'I am finishing this quest first. Ask me after this step.':'I have a run going already. Check with me after it.');
 return answer(true,sameParty?'party-cooperation':owner===requester?'escort-cooperation':friend?'friend-cooperation':'willing',agreed[kind]);
}

// ENGINE-CHOSEN attention preferences. Silence consumes no native action and
// never clears a route, quest, cast, trade, party or shop. Stable time buckets
// prevent repeated messages from rerolling attention within the same fight.
export function npcConversationAttention({world,player:p,brain={},requester,intent,now=world?.now?.()??0}={}){
 if(!live(world,p)||!live(world,requester))return {respond:false,reason:'unavailable'};
 const kind=intent==='buff'?'prepare':intent;
 if(actions.has(kind))return {respond:true,reason:'action-request'};
 const party=actualParty(world,p),sameParty=party&&party===actualParty(world,requester);
 if(sameParty)return {respond:true,reason:'teammate'};
 const goal=brain.taskGoal||p.profile?.npcRoutine,grinding=!!p.attackTarget||!!p._skills?.engine.casting||goal?.kind==='farm'&&Number(goal.until)>now;
 if(!grinding)return {respond:true,reason:'available'};
 let hash=2166136261;for(const c of String(p.account||p.id)+':'+Math.floor(now/20000)){hash^=c.charCodeAt(0);hash=Math.imul(hash,16777619);}
 const threshold=p.profile?.npcTraits?.chat==='quiet'||p.profile?.npcTraits?.social==='solo'?3:1;
 return {respond:(hash>>>0)%4>=threshold,reason:'busy-grinding'};
}
