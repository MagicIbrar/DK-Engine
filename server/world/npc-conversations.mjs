import {sameScene as ordinarySameScene} from './scene.mjs';
import {dialogueIntent} from './npc-dialogue.mjs';
import {normalizeNpcText,npcPartyRecruitment} from './npc-language.mjs';

// ENGINE-CHOSEN bounded conversation scheduling. These are authored player-like
// exchanges, not original Global AI or a service. No chat event is recursively
// interpreted; root explicitly starts a session and sends every returned turn
// through ordinary server chat. This helper never admits/invites/trades/moves.
export function npcGroupDiscussion(value,{channel='normal',addressed=false}={}){
 if(!['normal','party'].includes(channel)||addressed)return false;
 const text=normalizeNpcText(value);
 if(['follow','stop','roam','lure','prepare','pvp'].includes(dialogueIntent(text)))return false;
 if(/^(?:hello|hi|hey|yo|sup|thanks|ty|bye)[!? .]*$/.test(text))return false;
 if(/\b(?:anyone|anybody|everyone|you guys|all of you|any of you)\b/.test(text))return true;
 if(npcPartyRecruitment(text))return true;
 return /\b(?:farm|farming|grind|grinding|gear|build|weapon|armor|armour)\b/.test(text)&&/\b(?:what|which|how|want|wanna|any|compare|using|wearing|together)\b/.test(text);
}
const dist=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const live=p=>p&&!p.leaving&&!p.dead&&!p.sceneTransition;
const clean=value=>String(value??'').replace(/<[^>]*>/g,'').replace(/[\x00-\x1f]/g,' ').replace(/\s+/g,' ').trim().slice(0,90);
function facts(raw){return Object.fromEntries(Object.entries(raw||{}).map(([key,value])=>[key,typeof value==='string'?clean(value):value]));}
// Each turn is a coherent question, current factual answer or acknowledgment.
// Never claim an invitation, item purchase, cast, ticket or entry has happened.
function line(topic,phase,c,other,{humanStarted,variant}){
 const who=clean(other?.name||'you'),weapon=clean(c.weapon),activity=clean(c.activity||'taking a break'),cls=clean(c.class),quest=clean(c.quest),enemy=clean(c.enemy);
 const canPull=c.canPull===true;
 const role=c.solo?'I am staying solo for now.':c.isParty?`I am already in a party${Number(c.partyCount)>1?' with '+Math.floor(c.partyCount)+' members':''}.`:'Got room for me?';
 const answers={party:role+' '+(cls?'I am playing '+cls+'.':'What run did you want?'),gear:weapon?'I am using '+weapon+'. '+(c.build?'Mostly '+clean(c.build)+' for the build.':'Still sorting the rest of my gear.'):'I am still sorting out my gear.',grind:'I am '+activity+'. '+(enemy?'I am after '+enemy+'.':'What spot did you have in mind?'),quest:quest?'I am working on '+quest+'.':'No active quest right now. I am '+activity+'.',prepare:canPull?'Let us check pots and finish buffs before the pull.':'Let us check the entry requirements and supplies first.',trade:c.hasShop===true?'My personal shop is open. Have a look.':c.hasShop===false?'I do not have a shop open. What item are you looking for?':'Have you checked the shops? What item are you looking for?',meetup:'Want to meet here before we go?',status:humanStarted?'I am '+activity+'.':'How is your run going?'};
 const questions={party:['Anyone up for a few pulls together?','Got room for one more?','Want to check the run before we group?'],gear:['What are you using for this run?','How is your current build working out?','Want to compare gear before we move?'],grind:['Want to farm a few pulls together?','Are we staying here or regrouping?','How is the grind going for you?'],quest:['What quest are you working on?','Are you finishing a quest before the next run?','Which quest are you on?'],prepare:['Ready for the next pull?','Do we need a minute for recovery and buffs?','Is everyone ready before we move?'],trade:['Anyone comparing gear or selling spare items?','What item did you have in mind?','Are you shopping or just checking prices?'],meetup:['Want to gather here for a minute?','Where should we regroup nearby?','Are we waiting for someone?'],status:['What are you up to?','What is the next plan?','How is your run going?']};
 const q=questions[topic]||questions.status,answer=answers[topic]||answers.status;
 if(phase===0&&!humanStarted){const prompt=q[variant%q.length],safe=!canPull&&/\b(?:pull|pulls|pack|mobs)\b/i.test(prompt)?{party:'Want to check the party before we group?',grind:'Where are you farming?',prepare:'Have you checked the entry requirements?'}[topic]||'What is your plan?':prompt;return `${who}, ${safe[0].toLowerCase()+safe.slice(1)}`;}
 if(phase===0||phase===1)return answer;
 if(phase===2)return topic==='party'?canPull?`${who}, are we farming here or planning a dungeon?`:`${who}, are you planning a quest or an event?`:topic==='gear'?`${who}, how is that setup working for you?`:topic==='trade'?`${who}, which item are you checking?`:topic==='prepare'?`${who}, do you need more recovery time?`:`${who}, do you want to keep going or take a break?`;
 if(phase===3)return topic==='party'?(c.solo?'I will keep to my solo route. You can group without me.':c.isParty?'I am staying with my current party. We can compare plans.':canPull?'A few nearby pulls sound reasonable. Send me an invite if you want to group.':'Send me an invite if you want to group.') : topic==='gear'?(weapon?'I am sticking with '+weapon+' for now.':'I will check the requirements before changing gear.'):topic==='trade'?'We should check the actual item and price before confirming anything.':topic==='prepare'?'Let us wait until everyone is ready rather than rush.':'What did you have in mind?';
 if(phase===4)return topic==='party'?'Let us check the party and entry requirements before moving.':topic==='trade'?'Let me know what you want for it.':topic==='prepare'?canPull?'Finish the cast and recovery first, then we can pull.':'Let us confirm the plan and supplies first.':'Alright. We can keep the next step simple.';
 return ['Sounds good. Good luck with the run.','Alright, I will get back to it.',canPull?'Thanks for the chat. We can talk after the next pull.':'Thanks for the chat. Talk later.'][variant%3];
}
export function createNpcConversations({now,isNpc,sameScene=ordinarySameScene,sameParty=(a,b,id)=>!!id&&a.partyId===id&&b.partyId===id,context,distance=24,maxActors=3,maxTurns=6,intervalMs=3000,sessionMs=45000,sceneCooldownMs=0,typingDelay=()=>0,present=(_p,{text})=>text}={}){
 if(typeof now!=='function'||typeof isNpc!=='function'||typeof context!=='function')throw Error('NPC conversations need clock, verified NPC and current context callbacks.');
 const sessions=new Map(),cooldowns=new Map(),sceneCooldowns=new Map();let serial=0;
 const near=(a,b)=>live(a)&&live(b)&&sameScene(a,b)&&dist(a,b)<=distance;
 const together=(s,a,b)=>s.channel==='party'?live(a)&&live(b)&&sameParty(a,b,s.partyId):near(a,b);
 function prepare(s){const p=s.members[s.turn%s.members.length],other=s.turn===0?(s.humanStarted?s.human:s.members[1]):s.members[(s.turn+s.members.length-1)%s.members.length],text=line(s.topic,s.turn,facts(context(p,other)),facts(context(other,p)),s);return {p,other,text,topic:s.topic,phase:s.turn,humanStarted:s.humanStarted};}
 function delay(s){const turn=prepare(s),ms=Number(typingDelay(turn.p,turn));return Number.isFinite(ms)?Math.max(0,Math.min(5000,ms)):0;}
 function cancel(id){sessions.delete(id);}
 const sceneKey=p=>[p.map,p.instanceId||'',p.channel||0].join(':');
 function prune(){const time=now();for(const[id,s]of sessions)if(time>=s.expires||!live(s.human)||isNpc(s.human)||!s.members.every(p=>isNpc(p)&&together(s,p,s.human))||!s.members.every(p=>together(s,p,s.members[0])))cancel(id);for(const[key,end]of cooldowns)if(time>=end)cooldowns.delete(key);for(const[key,end]of sceneCooldowns)if(time>=end)sceneCooldowns.delete(key);}
 function begin({speaker,targets,topic,human,humanStarted,channel='normal'}){
  const scope={channel,partyId:channel==='party'?human?.partyId:null};
  prune();if(!live(human)||isNpc(human)||!together(scope,speaker,human))return false;
  const members=[...new Map((humanStarted?targets:[speaker,...targets]).filter(p=>isNpc(p)&&together(scope,p,human)&&together(scope,p,speaker)).map(p=>[p.id,p])).values()].slice(0,Math.max(2,Math.min(3,maxActors)));
  if(members.length<2||sessions.size>=8)return false;
  const scene=channel==='party'?'party:'+scope.partyId:sceneKey(human);
  if([...sessions.values()].some(s=>s.members.some(p=>members.includes(p))||sceneCooldownMs>0&&sceneKey(s.human)===scene))return false;
  if(!humanStarted&&now()<(sceneCooldowns.get(scene)||0))return false;
  const key=human.id+':'+channel+':'+topic;if(now()<(cooldowns.get(key)||0))return false;
  const id='npc-conversation-'+(++serial),s={id,human,members,topic,humanStarted,...scope,turn:0,variant:serial-1,due:now(),expires:now()+Math.min(60000,Math.max(10000,sessionMs)),reservation:null};s.due+=delay(s);sessions.set(id,s);cooldowns.set(key,now()+15000);if(sceneCooldownMs>0)sceneCooldowns.set(scene,now()+sceneCooldownMs);return true;
 }
 return {
  receive({speaker,text,channel='normal',targets=[],addressed=false,recipients}={}){if(!live(speaker)||isNpc(speaker)||!npcGroupDiscussion(text,{channel,addressed}))return false;
   const topic=dialogueIntent(text),kind=topic==='dungeon'?'prepare':topic==='time'?'meetup':['party','gear','grind','quest','prepare','trade'].includes(topic)?topic:'status';
   return begin({speaker,targets:targets.filter(p=>!recipients||recipients.includes(p.id)),topic:kind,human:speaker,humanStarted:true,channel});
  },
  start({speaker,targets=[],topic='status',human}={}){if(!isNpc(speaker)||!['party','gear','grind','quest','prepare','trade','meetup','status'].includes(topic))return false;return begin({speaker,targets,topic,human,humanStarted:false});},
  take(p,{quietUntil=0,chatReady=0}={}){prune();const time=now();if(!isNpc(p)||!live(p)||time<chatReady)return null;
   for(const s of sessions.values()){if(s.reservation||time<s.due||s.members[s.turn%s.members.length]!==p||(!s.humanStarted&&time<quietUntil))continue;
    const prepared=prepare(s),other=prepared.other;
    const spoken=String(present(p,prepared)),who=isNpc(other)?clean(other?.profile?.name):'',text=who&&!spoken.toLowerCase().startsWith(who.toLowerCase()+',')?who+', '+spoken:spoken;
    const turn={token:s.id+':'+s.turn,sessionId:s.id,actorId:p.id,peerId:other.id,humanId:s.human.id,text:text.slice(0,250),channel:s.channel,...(s.channel==='party'?{partyId:s.partyId}:{}),topic:s.topic,humanStarted:s.humanStarted};s.reservation=turn;return turn;
   }return null;
  },
  finish(turn,sent=true){const s=sessions.get(turn?.sessionId);if(!s||s.reservation?.token!==turn.token)return false;s.reservation=null;if(!sent){cancel(s.id);return false;}s.turn++;if(s.turn>=Math.max(2,Math.min(6,maxTurns)))cancel(s.id);else s.due=now()+Math.max(2500,intervalMs,delay(s));return true;},
  cancelPlayer(p){for(const[id,s]of sessions)if(s.human===p||s.members.includes(p))cancel(id);},
  clear(){sessions.clear();cooldowns.clear();sceneCooldowns.clear();},
  snapshot(){prune();return [...sessions.values()].map(s=>({id:s.id,topic:s.topic,turn:s.turn,due:s.due,expires:s.expires,actors:s.members.map(p=>p.id),humanId:s.human.id,pending:!!s.reservation}));}
 };
}
