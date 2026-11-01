import {npcKnowledgeReply} from './npc-chat-knowledge.mjs';
import {npcPersona} from './npc-persona.mjs';
import {normalizeNpcText} from './npc-language.mjs';

// ENGINE-CHOSEN teaching breadth and conversation memory, never game actions.
export const NPC_COACHING_POLICY=Object.freeze({followupMs:60000,topics:['quest','skills','gear','party'],breadth:{bad:1,mid:2,good:3,insane:4}});
const live=(world,p)=>p?.account&&world.players?.get(p.account)===p&&!p.leaving;
const action=q=>/\b(?:follow|invite|join|come|buff|heal|pull|lure|stop|stay|trade|buy|sell|give)\b.{0,18}\b(?:me|us|please|now|here)\b|^(?:follow|stop|wait|roam|buff|party|pt|heal|pull|lure)[!? .]*$/.test(q);
const explicit=q=>/\bteach\s+(?:me|us)\b|\bhow\s+(?:do\s+i|to)\s+(?:play|get\s+started)\b|^(?:help|help me|can you help me|i need help)[!? .]*$/.test(q);
const follow=q=>/^(?:and )?(?:what next|more|tell me more|next|how much|mana|mp|cooldown|requirements|level)[!? .]*$/.test(q);
function learnerText(text){return String(text||'').replace(/(^|[.!?]\s+)My /g,'$1Your ').replace(/(^|[.!?]\s+)I wear /g,'$1You wear ').replace(/(^|[.!?]\s+)I have /g,'$1You have ').replace(/(^|[.!?]\s+)I am /g,'$1You are ').replace(/\bI have not claimed it yet\b/g,'You have not claimed it yet').replace(/; waiting for a clear goal\./g,'.');}
function topicOf(q){if(/\b(?:skill|skills|combo|rotation|cooldown|mana|mp)\b/.test(q))return 'skills';if(/\b(?:gear|armor|armour|weapon|equipment|equip)\b/.test(q))return 'gear';if(/\b(?:party|hp|health|resources)\b/.test(q))return 'party';if(/\b(?:shop|merchant|potion|price|travel|teleport)\b/.test(q))return 'services';if(/\b(?:quest|objective|reward)\b/.test(q))return 'quest';return null;}
/** Pure explicit teaching. The teacher supplies breadth, the requester supplies
 * ALL factual character state. Actor/requester memory cannot leak to another
 * teacher, another learner, or a later expired conversation. Root owns consent,
 * audience, typing and ordinary chat scheduling. No goal is stopped or changed.
 */
export function npcCoachingReply({world,player:teacher,requester,brain={},text,memory={},maxLength=250}={}){
 if(!world?.data||!live(world,teacher)||!live(world,requester)||teacher===requester||teacher.npcPlayer!==true||teacher.profile?.npcPlayer!==true||teacher.profile.authority!=='server'||requester.npcPlayer===true||requester.profile?.npcPlayer===true||typeof text!=='string')return null;
 const q=normalizeNpcText(text),now=world.now(),saved=memory.coaching,bound=saved?.version===1&&saved.teacher===teacher.id&&saved.learner===requester.id&&now<saved.until?saved:null;
 if(action(q)||!explicit(q)&&!(bound&&follow(q)))return null;
 const tier=npcPersona(teacher.profile).knowledgeTier,breadth=NPC_COACHING_POLICY.breadth[tier],max=Math.max(25,Math.min(250,Math.floor(Number(maxLength)||250)));
 const named=topicOf(q),phase=explicit(q)?0:Math.min(breadth-1,(bound.phase||0)+(/what next|more|next/.test(q)?1:0)),topic=named||(!explicit(q)&&bound&&!/what next|more|next/.test(q)?bound.topic:null)||NPC_COACHING_POLICY.topics[phase];
 // Pass no teacher goals, follow IDs, or quest selections into the learner's
 // factual context. npcKnowledgeReply only mutates this separate local memory.
 const local={knowledge:bound?.knowledge&&structuredClone(bound.knowledge)},query=named?q.replace(/\bteach\s+(?:me|us)\b/,''):topic==='skills'?'learned skills':topic==='party'?'health mana and party size':topic;
 const fact=npcKnowledgeReply({world,player:requester,requester,brain:{},text:query,memory:local,maxLength:max,tier});if(!fact?.text)return null;
 const response=learnerText(fact.text),prefix=max>=100?'For your character: ':'';let answer=prefix+response;if(answer.length>max)answer=response;if(answer.length>max)answer=answer.slice(0,max-1).trimEnd()+'…';
 memory.coaching={version:1,teacher:teacher.id,learner:requester.id,until:now+NPC_COACHING_POLICY.followupMs,phase,topic,knowledge:local.knowledge};
 return {handled:true,text:answer,topic,tier,factual:true,subjectId:requester.id,teacherId:teacher.id,policy:'ENGINE-CHOSEN teaching breadth; native/current learner facts'};
}
