import {normalizeNpcText,npcSentenceIntent} from './npc-language.mjs';
import {npcPersona} from './npc-persona.mjs';
import {sameScene,sceneKey} from './scene.mjs';

// ENGINE-CHOSEN original social speech. No external model, game action, promise
// of human identity, private-profile inspection or unrestricted English parser.
export const NPC_SOCIAL_POLICY=Object.freeze({memoryMs:45000,minReplyMs:1500,maxFollowups:3,maxInput:500,maxReply:250});
const live=(world,p)=>p?.account&&world?.players?.get(p.account)===p&&!p.leaving&&!p.revoked;
const actionWords=/\b(?:follow|come|join|invite|party|group|team|trade|gift|give|items?|gear|weapons?|sword|armor|armour|sell|buy|offer|free|price|dil|quest|mission|objective|farm|grind|hunt|pull|lure|attack|fight|combat|cast|buff|heal|stop|stay|wait|leave|move|go|dungeon|event|ticket|pk|pvp|duel|skills?|cooldown|mana|hp|mp|level|map|where|class|bot|human|real|name|consent|confirm|accept|decline)\b/;
const followups=/^(?:why|how so|really|what|huh|wdym|what do you mean|what was that|say that again|come again|what about you|and you|tell me more|go on|same|same lol|me too|fair|fair enough|i do not know)$/;
export function npcSocialIntent(value){
 if(typeof value!=='string'||value.length>NPC_SOCIAL_POLICY.maxInput)return null;
 const text=normalizeNpcText(value).replace(/[.!?]+$/,'').trim();
 // Action/consent or factual words win even inside a greeting or sentiment.
 // Pure social "go on" is the sole go-word exception, and needs bound memory.
 if((text!=='go on'&&actionWords.test(text))||/^(?:yes|yeah|yep|sure|ok|okay|no|nah|nope)$/.test(text))return null;
 const intent=npcSentenceIntent(text);if(intent&&!['hello','wellbeing','thanks','apology','friend','continue','joke'].includes(intent))return null;
 if(followups.test(text))return 'followup';
 if(/^(?:oof|rip|rough|feels bad|feelsbadman|unlucky)$/.test(text))return 'rough';
 if(/^(?:gg(?: wp)?|wp|good game|well played|gz|gratz|nice one)$/.test(text))return 'kind';
 if(/^(?:(?:hey|hi|yo|hello)[, ]+)?(?:how(?:'s| is) it going|how are you(?: all)?(?: doing| feeling)?|you(?: all)? good|are you(?: all)? good|what(?:'s| is) up|what's good|sup|how(?:'s| is) your day|how you(?: all)? doing)(?: right now)?$/.test(text))return 'wellbeing';
 if(/^(?:i(?:'m| am| feel| have been feeling) (?:really |so |kinda |pretty )?(?:sad|down|lonely|stressed|frustrated|annoyed|mad|pissed|tired|anxious|overwhelmed|bored)(?: (?:today|right now|lately))?|this (?:sucks|is rough|is frustrating)|today sucks|ugh|rough day|bad day|having a bad day|i had a bad day)$/.test(text))return 'rough';
 if(/^(?:i(?:'m| am| feel) (?:really |so |kinda |pretty )?(?:happy|excited|good|great|hyped)(?: (?:today|right now))?|good day|this is fun|having fun|i love this)$/.test(text))return 'good';
 if(/^(?:tell (?:me|us) (?:a )?joke|say something funny|make me laugh|got a joke)$/.test(text))return 'joke';
 if(/^(?:lol|lmao|rofl|xd|haha+|(?:ha){2,}|(?:ja){2,}|k{3,})$/.test(text))return 'laugh';
 if(/^(?:what do you like|what(?:'s| is) your vibe|what are you into|what do you enjoy|are you having fun|you having fun|want to chat|do you want to chat|trying to chat)$/.test(text))return 'vibe';
 if(/^(?:you(?:'re| are) (?:cool|nice|funny|chill|awesome)|nice talking to you|i like your vibe|good vibes|respect|you rock)$/.test(text))return 'kind';
 if(/^(?:you (?:suck|are annoying)|you(?:'re| are) trash|that was dumb)$/.test(text))return 'friction';
 if(/^(?:hey|hi|yo|hello|hiya)$/.test(text))return 'greeting';
 if(/^(?:thanks|thank you|ty|thx)$/.test(text))return 'thanks';
 if(/^(?:sorry|my bad|sry|mb)$/.test(text))return 'apology';
 return null;
}
const lines={
 greeting:{warm:['Hey. How is it going?','Yo, good to see you around.'],reserved:['Hey.','Hi there.'],playful:['Yo. Good vibes so far?','Hey hey.'],direct:['Hey, how is it going?','Yo.'],dry:['Hey. Keeping it low-key.','Hey there.']},
 wellbeing:{warm:['Pretty chill. How are you doing?','Doing alright. How about you?'],reserved:['Doing alright. You?','Keeping it quiet. How are you?'],playful:['Chilling, mostly. How is your day going?','Pretty good. What is the vibe?'],direct:['Focused, but doing fine. You good?','Doing alright. How about you?'],dry:['Keeping it low-key. How about you?','Could use a quieter minute. You doing alright?']},
 rough:{warm:['Oof, rough day. We can keep it chill.','Yeah, rough one. No rush.'],reserved:['Rough one. We can keep it quiet.','No rush. Can keep it chill.'],playful:['Oof. Can keep it chill for a bit.','Rough. No need to fake the good vibes.'],direct:['Yeah, rough one. Can keep it chill.','Fair. No need to force the good vibes.'],dry:['Oof. One of those days.','Rough one. Keeping it low-key is fine.']},
 good:{warm:['Glad you are having a good time. What has been the best bit?','Nice. Good to hear.'],reserved:['Nice. Glad to hear it.','Good to hear.'],playful:['Nice, that is the vibe.','Love the energy. What has been the best bit?'],direct:['Nice. Keep enjoying it.','Good to hear.'],dry:['Nice. A good day helps.','Glad it is going well.']},
 joke:{warm:['My inventory has a plan. Unfortunately, it is mostly clutter.','The hardest encounter is deciding what to keep in the bag.'],reserved:['My bag has too many plans and too little space.','Inventory management: the quiet final boss.'],playful:['My inventory has a plan. Unfortunately, it is mostly clutter.','My bag and I disagree about what counts as essential.'],direct:['The final boss is deciding what to keep in the bag.','My inventory strategy is a little too optimistic.'],dry:['My bag is organised. Just not in a useful way.','Inventory management: the quiet final boss.']},
 laugh:{warm:['Haha, fair.','Glad that landed.'],reserved:['Heh.','Fair.'],playful:['Lol, fair.','Haha, okay.'],direct:['Haha.','Fair enough.'],dry:['Heh. Fair.','At least that landed.']},
 vibe:{warm:['I like keeping things friendly. Happy to chat a little.','My vibe is pretty relaxed. How about yours?'],reserved:['Quiet and steady, mostly. What about you?','I prefer keeping it low-key.'],playful:['A little banter, no drama. What is your vibe?','Keeping it light when I can.'],direct:['I like keeping things focused, with a little chat between decisions.','Focused, mostly. What about you?'],dry:['Low-key. Less drama is good.','A little dry humour, mostly.']},
 kind:{warm:['Appreciate that. Nice talking with you too.','Thanks. Good vibes.'],reserved:['Thanks. Appreciate it.','Thanks.'],playful:['Aw, appreciate that.','Good vibes right back.'],direct:['Thanks. Appreciate it.','Nice of you to say.'],dry:['Thanks. That is kind of you.','Appreciate it.']},
 friction:{warm:['Sounds like I missed the mark. We can keep this civil.','Fair to be annoyed. No need to make it personal.'],reserved:['We can keep this civil.','Alright. Let us keep it civil.'],playful:['Oof. Let us keep it civil.','Okay, that did not land.'],direct:['Keep it civil. What bothered you?','We can disagree without making it personal.'],dry:['Alright. Keep it civil.','That did not land. Fair enough.']},
 thanks:{warm:['Anytime.','No problem.'],reserved:['No problem.','You are welcome.'],playful:['Glad to help.','No worries.'],direct:['You got it.','No problem.'],dry:['No worries.','No problem.']},
 apology:{warm:['All good.','No worries.'],reserved:['All good.','It happens.'],playful:['We are good.','No worries.'],direct:['All good.','No worries.'],dry:['No worries.','It happens.']}
};
const explanations={wellbeing:'Just keeping it relaxed. How has your day been?',rough:'Just keeping it chill. No need to fake a good mood.',good:'Nice when the day goes well. What was the best bit?',joke:'Mostly joking about overthinking a cluttered bag.',laugh:'Just sharing the joke. What is on your mind?',vibe:'That is my usual chat style. Yours can be different.',kind:'A little kindness goes a long way.',friction:'A little respect makes the chat easier.',greeting:'Just saying hi. What is on your mind?',thanks:'Glad it helped.',apology:'No need to dwell on it. We are good.'};
function audience(world,p,requester,channel,partyId){
 if(['whisper','messenger'].includes(channel))return true; // Root-selected private recipient, never a broadcast.
 if(channel==='party'){const party=world.parties?.get(partyId);return !!partyId&&p.partyId===partyId&&requester.partyId===partyId&&party?.members?.includes(p.id)&&party.members.includes(requester.id);}
 return channel==='normal'&&sameScene(p,requester);
}
function scope(p,r,channel,partyId){return JSON.stringify([p.id,r.id,sceneKey(p.map,p.instanceId,p.channel),sceneKey(r.map,r.instanceId,r.channel),p.partyId||null,r.partyId||null,channel,partyId||null]);}
/** Speech and bounded per-peer conversation memory only. Caller preserves
 * selected recipient, ordinary attention/typing and all gameplay decisions.
 */
export function npcSocialReply({world,player:p,requester,text,memory={},directed=false,channel='normal',partyId,context={},maxLength=250}={}){
 if(!directed||!live(world,p)||!live(world,requester)||p===requester||p.npcPlayer!==true||p.profile?.npcPlayer!==true||p.profile.authority!=='server'||requester.npcPlayer===true||requester.profile?.npcPlayer===true)return null;
 if(!audience(world,p,requester,channel,partyId)){if(memory.social?.actor===p.id&&memory.social?.requester===requester.id)delete memory.social;return null;}
 const topic=npcSocialIntent(text);if(!topic)return null;
 const now=world.now(),key=scope(p,requester,channel,partyId),saved=memory.social,bound=saved?.version===1&&saved.actor===p.id&&saved.requester===requester.id&&saved.scope===key&&Number.isInteger(saved.followups)&&saved.followups>=0&&Number.isInteger(saved.variant)&&saved.variant>=0&&saved.variant<2&&lines[saved.topic]&&now>=saved.at&&now<saved.until?saved:null;
 if(saved&&!bound)delete memory.social;
 if(topic==='followup'&&(!bound||bound.followups>=NPC_SOCIAL_POLICY.maxFollowups))return null;
 if(bound&&now<bound.nextAt)return null;
 const persona=npcPersona(p.profile),mode=topic==='followup'?bound.topic:topic,tone=context.mood==='frustrated'?'dry':persona.tone,turn=topic==='followup'?bound.followups+1:0;
 const rows=lines[mode]?.[tone];if(!rows)return null;
 let answer=topic==='followup'?explanations[mode]:rows[((bound?.variant??-1)+1)%rows.length];
 if(topic==='followup'&&turn>1)answer=mode==='rough'?'Fair. Can keep it chill for a bit.':'What is on your mind? No need to overthink it.';
 if(topic==='wellbeing'&&(p.attackTarget||p._skills?.engine.casting))answer='A little focused right now, but I can keep the chat brief. How are you doing?';
 const limit=Math.max(25,Math.min(NPC_SOCIAL_POLICY.maxReply,Math.floor(Number(maxLength)||250)));
 if(answer.length>limit)answer=mode==='rough'?'That sounds rough.':mode==='greeting'?'Hey.':mode==='wellbeing'?'Doing alright. You?':'I hear you.';
 memory.social={version:1,actor:p.id,requester:requester.id,scope:key,topic:mode,at:now,until:now+NPC_SOCIAL_POLICY.memoryMs,nextAt:now+NPC_SOCIAL_POLICY.minReplyMs,followups:turn,variant:topic==='followup'?(bound.variant??0):((bound?.variant??-1)+1)%rows.length};
 return{handled:true,text:answer,topic:'social',socialTopic:mode,requesterId:requester.id,policy:'ENGINE-CHOSEN authored speech'};
}
