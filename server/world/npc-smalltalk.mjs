// Bounded, local conversation memory. Speech never authorizes a game action.
import {normalizeNpcText,npcSentenceIntent} from './npc-language.mjs';
const safe=v=>String(v||'').replace(/<[^>]*>/g,'').replace(/[\p{Cc}\p{Cf}]/gu,' ').replace(/\s+/g,' ').trim().slice(0,80);
const follow=/^(?:yeah|yes|yep|no|nah|not really|sometimes|same|me too|sure|okay|ok|why|how|tell me more|what about you|and you|you too|really|exactly|right|i agree)[.!? ]*$/;
export function smalltalkTopic(value,memory={}) {
 const t=normalizeNpcText(String(value||'').slice(0,500));
 // Ordinary requests retain their existing native action/consent paths.
 if(/^(?:follow|wait|stop|stay|pull|lure|buff|prepare|invite|party|group|duel|roam)\b|\b(?:can|could|would|will) you\b.{0,35}\b(?:follow|pull|lure|buff|invite|join)|\b(?:follow me|come with me|invite me|party up|group up|do not follow|stop following)\b/.test(t))return null;
 // A specific game question can mention "work" or "favorite" without being
 // small talk. Keep it on the factual native dialogue path.
 if(/^(?:what|how|where|which|who|when|can|could|do|does|is|are|why)\b/.test(t)&&/\b(?:quest|weapon|gear|armor|armour|skill|dungeon|trade|shop|guild|buff|level|class|inventory|party)\b/.test(t)&&! /\b(?:movie|music|real life|yesterday|birthday)\b/.test(t))return null;
 if(memory.smalltalk&&follow.test(t))return memory.smalltalk.topic;
 if(/\b(?:tired|exhausted|sleepy|stress(?:ed|ful)?|rough day|bad day|upset|lonely|sad|frustrated|annoyed|angry)\b/.test(t))return 'feelings';
 if(/\b(?:bored|boring|having fun|enjoy(?:ing)?|love this game|like this game|favorite game|favourite game|other games|what games|played before|been playing|new here|first time|just started)\b/.test(t))return 'gaming';
 if(/\b(?:work|job|school|college|homework|traffic|weekend|vacation|holiday|real life|irl|got home|my day|your day|today was|today has been|went out|went to)\b/.test(t))return 'day';
 if(/\b(?:music|song|songs|band|movie|movies|film|show|shows|anime|book|books|hobby|hobbies|listen to|watching|favorite|favourite)\b/.test(t))return 'interests';
 if(/\b(?:food|pizza|coffee|dinner|lunch|breakfast|hungry|cooking|ate|eating|snack)\b/.test(t))return 'food';
 if(/\b(?:raining|rainy|sunny|snowing|cold outside|hot outside|weather today)\b/.test(t))return 'weather';
 if(/\b(?:how was|how is|how's) (?:your )?day\b|\b(?:how are you doing|how have you been|you doing okay)\b/.test(t))return 'day';
 if(/\b(?:talk to me|just chatting|just talking|normal conversation|actual conversation|chat with me|let'?s chat|lets chat|tell me about yourself)\b/.test(t))return 'chat';
 // Narrative sentences and shared opinions are not commands just because they
 // contain "party", "wait", "pull" or "fight" somewhere in the story.
 if(/^(?:i (?:had|have been|was|went|think|feel|like|love|hate|wish|remember|met|saw)|my (?:friend|family|dog|cat|brother|sister)|we (?:had|were|went)|that (?:was|is)|it (?:was|is))\b/.test(t))return 'story';
 if(memory.smalltalk&&t&&!npcSentenceIntent(t)&&!/^\//.test(t)&&! /\b(?:quest|gear|weapon|armor|class|level|dungeon|invite|party|trade|shop|skill|buff|follow|stop|lure|pull|where|who are|commands|help)\b/.test(t))return memory.smalltalk.topic;
 return null;
}
const questions={feelings:'What has been making it rough?',gaming:'What do you enjoy most about it?',day:'How did the rest of your day go?',interests:'What would you recommend?',food:'What did you end up having?',weather:'Does that change your plans for today?',chat:'How has your day been?',story:'What happened next?'};
export function smalltalkReply(value,context={},memory={}) {
 const topic=smalltalkTopic(value,memory);if(!topic)return null;
 const t=normalizeNpcText(value),previous=memory.smalltalk,continuing=previous?.topic===topic;
 let text;
 if(continuing&&/^(?:why|how|tell me more|really)[.!? ]*$/.test(t))text=topic==='gaming'?'A good game gives you a reason to come back: a challenge, a goal, or good company. Which matters most to you?':topic==='feelings'?'Sometimes talking through the frustrating part makes it easier to decide what to do next. Want to tell me what happened?':topic==='interests'?'I do not have a personal music or movie history, but I can talk about what you like. What makes it your favorite?':'I was asking about '+previous.subject+'. You can tell me a little more, or we can change the subject.';
 else if(continuing&&/^(?:what about you|and you|you too)[.!? ]*$/.test(t))text='I am a scripted player, so I do not have an offline day. Here I am '+safe(context.activity||'taking a break')+'. What about you?';
 else if(continuing&&follow.test(t))text=/^(?:no|nah|not really)/.test(t)?'Fair enough. We can change the subject. What would you rather talk about?':'Got you. '+questions[topic];
 else if(topic==='feelings')text=/\b(?:tired|exhausted|sleepy)\b/.test(t)?'Sounds like you could use a breather. Long day, or have you been playing for a while?':'That sounds frustrating. Do you want to talk about what happened, or would a distraction help?';
 else if(topic==='gaming')text=/\b(?:bored|boring)\b/.test(t)?'The same routine can get boring. Is it the grind, or are you looking for something different to do?':/\b(?:new here|first time|just started)\b/.test(t)?'Welcome. How are you finding it so far? Anything confusing you?':'Glad we can talk about games. '+questions.gaming;
 else if(topic==='day')text=/\b(?:your day|you doing okay|how have you been)\b/.test(t)?'I am doing alright here, '+safe(context.activity||'taking a break')+'. How has your day been?':continuing?'Got it. Was that the good part of your day, or the part you were glad to finish?':'Sounds like you have had a day outside the game too. How did it go?';
 else if(topic==='interests')text=/\b(?:your favorite|your favourite|do you like|what do you)\b/.test(t)?'I do not have personal favorites, but I am happy to hear yours. What have you been into lately?':continuing?'What do you like about it? The story, the style, or something else?':'What have you been watching, reading, or listening to lately?';
 else if(topic==='food')text=/\bhungry\b/.test(t)?'Might be a good time for a food break. What sounds good?':continuing?'Was it good? Would you have it again?':'Food break sounds reasonable. '+questions.food;
 else if(topic==='weather')text='What is it like where you are? I only know the game map here.';
 else if(topic==='story')text=continuing?'Got it. How did you feel about that?':/\b(?:think|like|love|hate|wish)\b/.test(t)?'What makes you feel that way?':'How did that turn out?';
 else text='Sure, we can just talk. No need to pick a game command. How has your day been?';
 memory.smalltalk={topic,subject:({feelings:'how you are feeling',gaming:'what you enjoy playing',day:'your day',interests:'what you have been into',food:'your food break',weather:'the weather',chat:'your day',story:'what you were telling me'})[topic],turn:Math.min(20,(continuing?previous.turn:0)+1),until:Number(context.now||Date.now())+60000};
 memory.topic='smalltalk';memory.turns=(memory.turns||0)+1;
 return {intent:null,topic:'smalltalk',text:text.slice(0,250)};
}
