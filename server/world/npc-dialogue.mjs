// ENGINE-CHOSEN: authored conversation rules for the optional NPC players, without a model/API.
// Complete authored sentences with optional presentation styles. Native game
// facts are supplied by the director, never inferred from a player's request.
import {npcSentenceIntent,normalizeNpcText} from './npc-language.mjs';
import {NPC_AUTHORED_EXPANSION} from './npc-dialogue-lines.mjs';
import {npcDialogueOffer} from './npc-social-dialogue.mjs';
import {npcConversationCue} from './npc-conversation-cues.mjs';
import {smalltalkTopic,smalltalkReply} from './npc-smalltalk.mjs';
const topics={
 "hello": [
  "Hey, you questing?",
  "Yo, what's up?",
  "Hey, what are you up to?",
  "Hi, need a party?",
  "Hey, how is the grind?"
 ],
 "farewell": [
  "Cya around {map}.",
  "Gl on the drops.",
  "Later, good luck out there.",
  "Take care.",
  "Cya, good run."
 ],
 "wellbeing": [
  "Doing good. How about you?",
  "Doing alright. You?",
  "Still here grinding.",
  "Pretty good, how about you?",
  "All good here."
 ],
 "identity": [
  "I am {name}, a {class} NPC.",
  "I am {name}, one of the NPC players here.",
  "I am one of this server's NPC players.",
  "Name is {name}. I play {class} as an NPC.",
  "I am an NPC player, not a human player.",
  "{name} here. I am a {class} NPC.",
  "You can call me {name}. I am an NPC.",
  "My character is {name}, a {class} NPC.",
  "I am {name}. You can whisper this NPC if you need something.",
  "I am an NPC. What did you want to ask?",
  "I am {name}, an NPC in {map}.",
  "{name}, the {class} NPC. What is up?",
  "Yes, I am an NPC player here.",
  "This is {name}. I am one of the NPCs.",
  "I play a {class} NPC called {name}.",
  "I am an NPC, so I may misunderstand. What do you need?",
  "{name} here, one of this world's NPC players."
 ],
 "level": [
  "Level {level}. You?",
  "I am {level} atm.",
  "Currently {level}.",
  "Level {level}, still working on it.",
  "I am level {level}."
 ],
 "location": [
  "I am in {map}.",
  "Around {map} atm.",
  "Still in {map}.",
  "I am over in {map}.",
  "We are in {map}."
 ],
 "quest": [
  "I am on {quest}.",
  "Doing {quest} atm.",
  "Still working on {quest}.",
  "Trying to finish {quest}.",
  "My active quest is {quest}."
 ],
 "follow": [
  "K, following.",
  "Lead the way.",
  "I am coming with you.",
  "Give me a sec, on my way.",
  "Got you, I will follow."
 ],
 "stop": [
  "K, waiting here.",
  "Stopping here.",
  "I will stay here.",
  "Taking a breather here.",
  "Waiting, tell me when to move."
 ],
 "roam": [
  "K, back to my run.",
  "Going back to farming.",
  "I will do my own thing for a bit.",
  "Back to my route.",
  "I am heading back to my tasks."
 ],
 "party": [
  "Got room for one?",
  "I can send you a party invite.",
  "Want to party up?",
  "We can team up.",
  "Room in your party?"
 ],
 "lure": [
  "I will pull one back.",
  "K, one pull at a time.",
  "Stay there, I will bring one over.",
  "I will lure it back to you.",
  "Got it, ready for the pull?"
 ],
 "dungeon": [
  "Got your ticket and pots?",
  "We need to get the party together first.",
  "Meet the party at the entrance.",
  "I will stick with the leader inside.",
  "Ready for a dungeon run?"
 ],
 "help": [
  "Whisper me if you need a hand.",
  "Say follow me if you want me to come along.",
  "Want to party or farm?",
  "You can ask me to wait or follow.",
  "Ask about my gear, level or current run."
 ],
 "thanks": [
  "Np.",
  "Anytime.",
  "You are welcome.",
  "Glad that helped.",
  "Np, happy to help."
 ],
 "apology": [
  "All good.",
  "No worries.",
  "It happens, regroup.",
  "No big deal.",
  "We can reset and try again."
 ],
 "death": [
  "That pull hurt.",
  "Regroup before we go back in.",
  "Do not rush the same pack again.",
  "Need to recover first.",
  "We should slow down that pull."
 ],
 "combat": [
  "Focus one first.",
  "Watch the extra mobs.",
  "Save a bit of mana for the next pull.",
  "Keep the party together.",
  "We should not overpull."
 ],
 "loot": [
  "Check the party loot setting.",
  "Make some room in your bag.",
  "Wait until the drop is free.",
  "That drop might still be reserved.",
  "Keep an eye on the drops."
 ],
 "gear": [
  "I am using {weapon}.",
  "My weapon is {weapon}.",
  "Mostly building around {build}.",
  "I have {weapon} equipped.",
  "I am working on my {build} build."
 ],
 "skills": [
  "Watch the cooldown before pulling.",
  "Save the big skills for the pull.",
  "Try not to burn all your mana.",
  "Buff before the fight.",
  "We should time the skills with the pull."
 ],
 "class": [
  "I play {class}.",
  "I am a {class}.",
  "My class is {class}. Yours?",
  "Playing {class} here.",
  "I am on my {class}."
 ],
 "status": [
  "I am {activity}.",
  "Currently {activity}.",
  "Just {activity} atm.",
  "I am {activity} around {map}.",
  "Mostly {activity} right now."
 ],
 "joke": [
  "That is how you donate pots to the floor.",
  "The real boss is a full inventory.",
  "One more run, famous last words.",
  "The drops always know when you need them.",
  "This is why we bring extra pots."
 ],
 "weather": [
  "I like this map.",
  "This spot is pretty nice.",
  "I know this corner of {map}.",
  "Good place to regroup.",
  "I like the look of {map}."
 ],
 "grind": [
  "I am {activity} atm.",
  "Just working on some exp.",
  "I am looking for a decent pull.",
  "I am keeping to this farming spot.",
  "We can farm together if you want."
 ],
 "boss": [
  "Get buffs up before the boss.",
  "Wait for the party before pulling it.",
  "Keep some pots for the boss.",
  "Focus it when everyone is ready.",
  "Do not pull the boss alone."
 ],
 "potion": [
  "Check your pots before the next run.",
  "Keep some mana pots on your bar.",
  "We should not overpull with low HP.",
  "Take a sec to recover.",
  "Better to pot early than die with a full bag."
 ],
 "time": [
  "No rush, finish the pull first.",
  "I can wait a bit.",
  "Give the party a minute to get ready.",
  "Take your time.",
  "Wait for everyone before starting."
 ],
 "friend": [
  "Gg.",
  "Nice one.",
  "Good run.",
  "That went well.",
  "Gg, nice run."
 ],
 "trade": [
  "Use the trade window.",
  "What are you looking for?",
  "I only sell items I actually have.",
  "Got an offer?",
  "We can trade after the pull."
 ],
 "prepare": [
  "K, getting ready.",
  "Give me a sec for buffs.",
  "Wait for buffs before pulling.",
  "We should buff before it starts.",
  "Getting the party ready."
 ],
 "pvp": [
  "Want a duel?",
  "Ready for a duel?",
  "We can duel if you want.",
  "Get ready before we start.",
  "Want to test your combo?"
 ],
 "retry": [
  "We can try again.",
  "Another run?",
  "Reset and regroup.",
  "Try a smaller pull this time.",
  "K, one more try."
 ],
 "continue": [
  "Yeah?",
  "K, what do you need?",
  "I am listening.",
  "Go on.",
  "What is up?"
 ],
 "unknown": [
  "Hey, what is going on?",
  "I am busy {activity}.",
  "You need a party?",
  "Hey, what do you need?",
  "Want to farm or run a dungeon?"
 ]
};
const styles=[line=>line,line=>line.toLowerCase(),line=>"Well, "+line[0].toLowerCase()+line.slice(1),line=>line.replace(/[.!?]$/,"")+" :)"];
export const NPC_DIALOGUE_SENTENCES=Object.entries(topics).flatMap(([topic,lines])=>[...new Set([...lines,...(topic==='identity'?[]:NPC_AUTHORED_EXPANSION[topic]||[])])].map(text=>({topic,text})));
const selectedTexts=new Set();
export const NPC_DIALOGUE_CATALOG=NPC_DIALOGUE_SENTENCES.flatMap(({topic,text})=>styles.map((style,styleIndex)=>({topic,text:style(text),style:styleIndex}))).filter(row=>{if(selectedTexts.has(row.text))return false;selectedTexts.add(row.text);return true;});
const replyRows=new Map();for(const row of NPC_DIALOGUE_CATALOG){if(!replyRows.has(row.topic))replyRows.set(row.topic,[]);replyRows.get(row.topic).push(row);}
const rules=[['prepare',/\b(buff up|buff me|prebuff|pre buff|buff before|prepare|ready up)\b/i],['stop',/\b(wait|stop|stay|hold position)\b/i],['lure',/\b(lure|pull|aggro).*(for me|to me|here|please)?\b/i],['follow',/\b(follow|come with|come here|come along)\b/i],['roam',/\b(roam|go back|do your thing|dismiss|free roam)\b/i],['party',/\b(party|group|team|invite)\b/i],['dungeon',/\b(dungeon|instance|crespo|abyss|tower|dead front)\b/i],['level',/\b(level|lvl|lv)\b/i],['identity',/\b(who are you|your name|are you a bot|are you real|npc)\b/i],['quest',/\b(quest|objective|mission)\b/i],['class',/\b(class|magician|knight|summy|segnale|hunter)\b/i],['location',/\b(where|map|location)\b/i],['wellbeing',/\b(how are|how r|how is it going|sup|whats up)\b/i],['status',/\b(doing|status|busy)\b/i],['help',/\b(help|commands|what can)\b/i],['thanks',/\b(thank|thanks|ty|thx)\b/i],['apology',/\b(sorry|my bad|mb)\b/i],['farewell',/\b(bye|later|cya|see you|gtg)\b/i],['death',/\b(dead|death|died|revive)\b/i],['gear',/\b(gear|weapon|armor|armour|equip)\b/i],['skills',/\b(skill|cast|spell|cooldown)\b/i],['loot',/\b(loot|drop|dil|bag|inventory)\b/i],['combat',/\b(fight|attack|damage|combat|hit)\b/i],['joke',/\b(joke|funny|lol|lmao|haha)\b/i],['weather',/\b(weather|view|scenery|beautiful)\b/i],['grind',/\b(grind|exp|experience|farm)\b/i],['boss',/\b(boss|elite)\b/i],['potion',/\b(potion|mana|health|heal|hp|mp)\b/i],['time',/\b(time|long|rush|minute)\b/i],['friend',/\b(friend|nice|cool|good job|gg)\b/i],['trade',/\b(trade|sell|buy|price)\b/i],['pvp',/\b(pvp|pk|duel)\b/i],['retry',/\b(again|retry|another try)\b/i],['continue',/^(yes|yeah|yep|ok|okay|tell me more|why|how|sure)[!.? ]*$/i],['hello',/\b(hello|hi|hey|yo|hiya|greetings)\b/i]];
const explicitDungeon=text=>/\b(?:dungeon|instance|crespo|abyss|tower|dead front)\b/i.test(text);
export function dialogueIntent(text){return npcConversationCue(text)?.intent||(!explicitDungeon(text)&&smalltalkTopic(text)?'smalltalk':null)||npcSentenceIntent(text)||rules.find(([,rx])=>rx.test(normalizeNpcText(text)))?.[0]||'unknown';}
// Context selects authored speech only; it never approves a party invitation,
// movement or native entry. Explicit dungeon questions remain discussion.
export function npcDialogueContextFits(text,context={},topic=''){
 if(context.canPull===false&&/\b(?:farm(?:ing)?|grind(?:ing)?|exp|pull(?:s|ing)?|mobs?|packs?)\b/i.test(text))return false;
 if(context.canDungeon===false&&topic!=='dungeon'&&/\b(?:dungeon|instance|entrance|inside|crespo|abyss|tower|dead front)\b/i.test(text))return false;
 return true;
}
export function npcReply({text,context,memory={},random=Math.random}){
 if(text==='attention')return {intent:'continue',text:'Yeah?'};
 if(memory.smalltalk&&Number(context.now||Date.now())>=memory.smalltalk.until)delete memory.smalltalk;
 const earlyCue=npcConversationCue(text);
 if(earlyCue?.reply){delete memory.smalltalk;return {intent:null,topic:earlyCue.kind==='item-offer'?'trade':'continue',text:earlyCue.reply};}
 const social=explicitDungeon(text)?null:smalltalkReply(text,context,memory);if(social)return social;
 if(memory.smalltalk)delete memory.smalltalk;
 const cue=npcConversationCue(text);
 if(cue?.reply)return {intent:null,topic:cue.kind==='item-offer'?'trade':'continue',text:cue.reply};
 if(cue?.kind==='clarify'&&!replyRows.has(memory.topic))return {intent:null,topic:'continue',text:'Which bit did you mean: the gear, the quest, or what I am doing?'};
 const intent=dialogueIntent(text),topic=intent==='continue'?(replyRows.has(memory.topic)?memory.topic:'status'):intent;
 if(topic==='lure'&&context.canPull===false)return {intent:null,topic:'lure',text:'I do not see a safe monster pull nearby. Let us move to a hunting area or an active kill quest first.'};
 if(intent==='decline'){memory.partyAskedAt=Number(context.now||Date.now())+600000;memory.topic='party';memory.turns=(memory.turns||0)+1;return {intent,text:'All good, I will leave the party invite alone. Have a good run.'};}
 const factKey={level:'level',location:'map',class:'class',quest:'quest',gear:'weapon'}[topic];
 if(factKey&&context[factKey]==null)return {intent:null,topic,text:''};
 const rows=replyRows.get(topic).filter(row=>(context.style==null||row.style===Math.abs(Math.trunc(context.style))%4)&&npcDialogueContextFits(row.text,context,topic)&&[...row.text.matchAll(/\{(\w+)\}/g)].every(([,key])=>context[key]!=null&&String(context[key]).trim()!==''));
 if(!rows.length){
  const known=topic==='quest'&&context.quest===''?'No active quest right now.':topic==='gear'&&context.weapon===''?'No weapon equipped right now.':'';
  return {intent:null,topic,text:known};
 }
 let pick=Math.min(rows.length-1,Math.max(0,Math.floor(random()*rows.length)));
 const recent=Array.isArray(memory.recent)?memory.recent:[];for(let n=0;n<rows.length-1&&recent.includes(topic+':'+pick);n++)pick=(pick+1)%rows.length;
 const values={...context,topic:memory.topic||''};let reply=rows[pick].text.replace(/\{(\w+)\}/g,(_,key)=>String(values[key]??''));
 if(topic==='quest'&&!context.quest)reply='No active quest atm. I am '+(context.activity||'taking a break')+'.';
 if(topic==='quest'&&context.questObjective){
  const objective=String(context.questObjective).replace(/[.!?]+$/,'');
  const choices=[objective+'.',objective+'. How about you?'];
  reply=choices.find(line=>line!==memory.lastFactReply)||choices[0];
 }
 if(topic==='gear'&&context.weapon==='')reply='I have not got a weapon equipped right now. I am still sorting out my gear.';
 if(topic==='gear'&&context.weapon&&!context.build&&/\{build\}/.test(rows[pick].text))reply='I am using '+context.weapon+'. I am still working out my build.';
 if(topic==='class'&&!context.class)reply='I have not got my class details ready. What run did you have in mind?';
 if(topic==='location'&&!context.map)reply='I am here nearby. Which meeting spot did you mean?';
 // A follow-up explains the same current fact instead of issuing a second
 // movement/invitation command or claiming an unaccepted quest.
 if(intent==='continue'&&memory.topic==='gear'&&context.weapon)reply='I am using '+context.weapon+'. '+(context.build?'The build is mainly '+context.build+'.':'I am still working out the build.');
 if(intent==='continue'&&memory.topic==='status')reply='What did you have in mind?';
 if(topic==='status'&&/\b(?:party size|how many)\b/i.test(text))reply=context.isParty===true&&Number.isInteger(context.partyCount)?'My party currently has '+context.partyCount+' members.':context.isParty===false?'I am not currently in a party.':'We can check the actual party window for the current members.';
 if(intent==='continue'&&memory.topic==='party'&&context.partyInvitePending===true)reply='K, accept the party invite when you are ready. I will wait here.';
 if(intent==='hello'&&memory.greetedAt&&Number(context.now)-memory.greetedAt<20000)reply='Still here. What do you need?';
 if(intent==='hello')memory.greetedAt=Number(context.now)||1;
 if(context.mood==='frustrated'&&['death','combat'].includes(topic))reply='Ugh, '+reply[0].toLowerCase()+reply.slice(1);
 memory.topic=topic;memory.last=pick;memory.recent=[...recent,topic+':'+pick].slice(-12);memory.turns=(memory.turns||0)+1;
 memory.lastFactReply=reply;
 const textOut=reply.slice(0,250),offer=npcDialogueOffer(textOut,topic);
 return {intent,text:textOut,...(offer?{offer}:{})};
}
