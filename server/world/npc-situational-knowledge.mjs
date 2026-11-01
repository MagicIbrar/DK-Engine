import {normalizeNpcText,npcPartyRecruitment,npcEventRunQuestion} from './npc-language.mjs';
import {npcPersona} from './npc-persona.mjs';
import {npcQuestTalkGoal} from './npc-chat-knowledge.mjs';
import {mapFor,sameScene,sceneKey} from './scene.mjs';

// ENGINE-CHOSEN finite speech breadth, not AI, combat bonuses or admission rules.
export const NPC_SITUATION_POLICY=Object.freeze({memoryMs:60000,quests:8,objectives:16,hostiles:64,range:24,breadth:{bad:1,mid:2,good:3,insane:4}});
const clean=v=>String(v??'').replace(/<[^>]*>|\[[^\]]*\]|[\u0000-\u001f\u007f]/g,'').replace(/\s+/g,' ').trim();
const number=v=>Number.isFinite(Number(v))?Number(v):0;
const live=(world,p)=>p?.account&&world.players?.get(p.account)===p&&!p.leaving;
const distance=(a,b)=>Math.hypot(number(a.x)-number(b.x),number(a.z)-number(b.z));
export function npcSituationIntent(text){
 if(typeof text!=='string'||text.length>500)return null;
 const q=normalizeNpcText(text).replace(/[.!?]+$/,'').trim();
 if(npcEventRunQuestion(text))return 'event-question';
 if(/^(?:what|huh|wdym|what do you mean)$/.test(q))return 'clarify';
 if(/^with my quest$/.test(q))return 'help-quest';
 if(/^please$/.test(q))return 'help-please';
 if(/^how many do you need$/.test(q))return 'count';
 if(/^(?:ready|are (?:you|we) ready|ready for (?:the fight|a pull|the next pull))$/.test(q))return 'ready';
 if(npcPartyRecruitment(q)||/\b(?:follow|invite|join|come|buff|heal|pull|lure|stop|stay|trade|buy|sell|give|cast|attack)\b/.test(q))return null;
 if(/^(?:what(?:'s| is) (?:the|your|our) plan|what (?:are we|are you) doing|what next|what should we do|plan)$/.test(q))return 'plan';
 if(/^(?:help|help me|can you help me|i need help|what can i do to help)$/.test(q))return 'help';
 if(/^(?:why|where|where next|what about now|and now)$/.test(q))return q.startsWith('where')?'where':q==='why'?'why':'refresh';
 return null;
}
function partyFor(world,p){const party=world.parties?.get(p.partyId);return party?.members?.includes(p.id)?party:null;}
function quests(world,p){return Object.entries(p.profile.quests?.active||{}).slice(0,NPC_SITUATION_POLICY.quests).map(([id,state])=>({q:world.data.progression?.quests?.quests?.[id],state})).filter(r=>r.q&&Array.isArray(r.state?.s));}
function taskFor(world,brain){const t=brain.taskGoal;return t&&Number(t.until)>world.now()?t:null;}
function fingerprint(world,p,requester,brain){
 const task=taskFor(world,brain),party=partyFor(world,p),otherParty=partyFor(world,requester);
 return JSON.stringify([[p.account,p.characterId,p.token,requester.account,requester.characterId,requester.token],sceneKey(p.map,p.instanceId,p.channel),sceneKey(requester.map,requester.instanceId,requester.channel),task&&[task.kind,task.map,task.questId,task.started,task.until],brain.questId,quests(world,p).map(r=>[r.q.id,r.state.s]),quests(world,requester).map(r=>[r.q.id,r.state.s]),party&&[party.id,party.leader,party.members],otherParty&&[otherParty.id,otherParty.leader,otherParty.members],p.attackTarget||null,brain.target||brain.farmTarget||null]);
}
function objective(world,row,subject){
 if(!row)return null;
 const fallback={text:'Not sure what next; check the quest window.',complete:null};
 if(!Number.isSafeInteger(Number(row.q.id))||!(row.q.objectives||[]).length||(row.q.objectives||[]).length>NPC_SITUATION_POLICY.objectives)return fallback;
 const known=new Set(['talk','kill','collect','useSkill','fish','killOnMap','clearMap']);
 if(row.q.objectives.some(o=>!known.has(o.kind)||!Number.isSafeInteger(o.slot)||o.slot<0||!Number.isFinite(o.count)||o.count<=0||!Number.isFinite(row.state.s[o.slot])||row.state.s[o.slot]<0))return fallback;
 const os=(row.q.objectives||[]).slice(0,NPC_SITUATION_POLICY.objectives),done=o=>number(row.state.s[o.slot])>=Math.max(1,number(o.count));
 const complete=row.q.require?.completeAny?os.some(done):os.length>0&&os.every(done),o=complete?null:os.find(o=>!done(o));
 const talk=npcQuestTalkGoal(world.data,subject,{questId:Number(row.q.id)});
 if(!talk||talk.questId!==Number(row.q.id))return fallback;
 if(!o)return{complete,text:talk.text+'.'};
 const target=o.targets?.[0],id=target?.id,catalog=world.data.progression;
 const name=clean(target?.name||(o.kind==='talk'?catalog?.npcs?.npcs?.[id]?.name:o.kind==='kill'?catalog?.monsters?.monsters?.[id]?.name:o.kind==='collect'?world.data.itemDB?.def(Number(id))?.name:o.kind==='useSkill'?world.data.skillFull?.skills?.[id]?.name:''));
 const placements=o.kind==='talk'?catalog?.npcs?.placements?.[row.map]?.rows:[];
 const local=(placements||[]).some(r=>Number(r[0])===Number(id));
 return{text:talk.text+'.',name,local,complete:false};
}
function mapName(world,p){return clean(mapFor(world,p)?.name||world.data.dungeonCatalog?.maps?.[p.map]?.name)||`map ${Number(p.map)}`;}
function observed(world,p,brain){
 const map=mapFor(world,p),preferred=map?.monsters?.get(p.attackTarget||brain.target||brain.farmTarget),valid=m=>m&&!m.dead&&distance(p,m)<=NPC_SITUATION_POLICY.range;
 let attacker;let seen=0;for(const m of map?.monsters?.values()||[]){if(seen++>=NPC_SITUATION_POLICY.hostiles)break;if(valid(m)&&m.targetId===p.id){attacker=m;break;}}
 return{target:valid(preferred)?preferred:null,attacker};
}
function learned(world,p){const pack=world.data.skillPacks?.[p.profile.classIndex]?.skills;for(const [id,value]of Object.entries(p.profile.skills||{}).slice(0,64)){const rank=Number(value),s=pack?.[id];if(s&&!s.hidden&&Number.isInteger(rank)&&rank>0&&rank<=s.levels?.length&&s.kind==='active')return{s,rank,r:s.levels[rank-1]};}return null;}
function fit(parts,max){let result='';for(const part of parts){if(part&&result.length+part.length+(result?1:0)<=max)result+=(result?' ':'')+part;}return result||'Which bit?';}

/** Speech only. Root owns addressed selection, typing, consent and chat routing.
 * Only current colocated subjects are visible. Memory never approves a trade,
 * party, cast or movement and is invalidated by objective/map/party changes.
 */
export function npcSituationReply({world,player:p,requester,brain={},text,memory={},maxLength=250,directed=false,channel}={}){
 if(!directed||!world?.data||!live(world,p)||!live(world,requester)||p===requester||p.npcPlayer!==true||p.profile?.npcPlayer!==true||p.profile.authority!=='server'||requester.npcPlayer===true||requester.profile?.npcPlayer===true)return null;
 if(!sameScene(p,requester)){if(memory.situation?.actor===p.id&&memory.situation?.requester===requester.id)delete memory.situation;if(['clarify','help-quest','help-please'].includes(npcSituationIntent(text)))return {handled:true,text:'Which quest or subject did you mean? Tell me what you need.',topic:'situation',factual:false};return null;}
 let intent=npcSituationIntent(text);if(!intent)return null;
 if(intent==='event-question')return {handled:true,text:'DF? Not sure about a run yet.',topic:'situation',factual:false};
 const now=world.now(),key=fingerprint(world,p,requester,brain),saved=memory.situation;
 const bound=saved?.version===1&&saved.actor===p.id&&saved.requester===requester.id&&now<saved.until&&saved.fingerprint===key?saved:null;
 const followup=['clarify','help-quest','help-please'].includes(intent);
 const clarify=()=>({handled:true,text:intent==='clarify'?'Which bit did you mean? Ask about my current work or your quest.':'Which quest do you need help with? Tell me what you still need.',topic:'situation',factual:false});
 if(followup&&(!bound||bound.delivered!==true||!['normal','party','whisper','messenger'].includes(channel)||bound.channel!==channel||!Number.isInteger(bound.turn)||memory.followupTurn!==bound.turn+1||intent!=='clarify'&&bound.mode!=='help')){delete memory.situation;return clarify();}
 if(intent==='count'&&(!bound||!['normal','party','whisper','messenger'].includes(channel)||bound.channel!==channel))return null;
 if(['why','where','refresh'].includes(intent)&&!bound){delete memory.situation;return null;}
 const mode=['why','where','refresh','count','clarify','help-quest','help-please'].includes(intent)?bound.mode:intent,tier=npcPersona(p.profile).knowledgeTier,breadth=NPC_SITUATION_POLICY.breadth[tier],subject=mode==='help'?requester:p;
 const task=taskFor(world,brain),rows=quests(world,subject),selected=mode==='help'?rows[0]:rows.find(r=>Number(r.q.id)===Number(brain.questId))||rows[0],goal=objective(world,selected&&{...selected,map:subject.map},subject),party=partyFor(world,p),facts=observed(world,p,brain);
 if(followup&&(bound.subjectId!==subject.id||bound.questId!==(selected?Number(selected.q.id):null))){delete memory.situation;return clarify();}
 if(intent==='count'&&(!goal||goal.complete===null||bound.subjectId!==subject.id||bound.questId!==Number(selected?.q.id)))return null;
 const parts=[];const max=Math.max(25,Math.min(250,Math.floor(number(maxLength)||250)));
 if(intent==='count')parts.push(goal.text);
 else if(intent==='where')parts.push(goal?.local?`Need to talk to ${goal.name||'the quest NPC'} here in ${mapName(world,subject)}.`:`I'm in ${mapName(world,p)}. Not sure where next.`);
 else if(mode==='help')parts.push(goal?goal.text:'Got a quest picked up? What do you need?');
 else if(mode==='ready')parts.push(p.dead?'Dead rn.':facts.attacker?'Got a mob on me.':"Let's check HP and MP.");
 else if(facts.target)parts.push(`Looking at ${clean(facts.target.name)||'a nearby mob'}.`);
 else if(goal)parts.push(goal.text);
 else if(task){const activities={farm:'Farming rn.',merchant:'Doing a shop run.',rest:'Taking a break.',dungeon:'Working toward a dungeon run.',event:'Working toward an event.',quest:'Checking quest stuff.'};parts.push(activities[task.kind]||'Not sure what next yet.');}
 else parts.push('Not sure what next yet.');
 if(goal&&(mode==='help'||mode==='ready')&&intent!=='where'&&!parts.includes(goal.text))parts.push(goal.text);
 if(intent==='why')parts.unshift(goal?.complete===false?'Still got some of the quest left.':goal?.complete===true?'Still need to turn it in.':facts.attacker?'Got a mob on me.':task&&!goal?"Just sticking with what I'm doing.":'Not sure yet.');
 if(mode==='ready'&&intent!=='where'&&intent!=='count')parts.push(`HP ${Math.round(number(subject.hp))}/${Math.round(number(subject.maxHp))}; MP ${Math.round(number(subject.mp))}/${Math.round(number(subject.stats?.maxMp??subject.maxMp))}.`);
 const answer=fit(parts.slice(0,breadth+1),max);memory.situation={version:1,actor:p.id,requester:requester.id,subjectId:subject.id,questId:selected?Number(selected.q.id):null,channel,turn:memory.followupTurn,until:now+NPC_SITUATION_POLICY.memoryMs,fingerprint:key,mode};
 return{handled:true,text:answer,topic:'situation',factual:true,tier,subjectId:subject.id,requesterId:requester.id,policy:'ENGINE-CHOSEN finite advice; current native facts',...(goal&&!goal.complete&&mode==='help'?{helpNeed:{verified:true,current:true,kind:'quest'}}:{})};
}
