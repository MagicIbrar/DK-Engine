import {sameScene} from './scene.mjs';
import {normalizeNpcText} from './npc-language.mjs';

// ENGINE-CHOSEN conversational consent, not party/dungeon admission. Offers
// enter memory only after the director verifies actual delivery to this human.
export const NPC_CONVERSATION_OFFER_MS=45000;
const types=new Set(['party','dungeon','quest-help']),live=(world,p)=>p&&world.players.get(p.account)===p&&!p.leaving&&!p.revoked&&p.characterId===p.profile?.id;
const npc=p=>/^npc_[a-f0-9]{32}$/.test(p?.account||'')&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true;
const negative=/^(?:(?:no|nope|nah|no thanks|no thank you|not now|not right now|maybe later|another time|rather not|i(?:'d| would) rather not|i do not want to|i do not want to (?:join|go|run)|not interested|pass|i(?:'ll| will) pass))(?:[, ]+(?:thanks|thank you|ty|sorry|please))?[.!?]*$/;
const positive=/^(?:yes|yeah|yep|sure|ok|okay|sounds good|i can help|i am in|let's do it)[.!?]*$/;
function validAudience(world,player,requester,channel,partyId){
 if(channel==='party'){const party=world.parties?.get(partyId);return !!party&&player.partyId===partyId&&requester.partyId===partyId&&party.members.includes(player.id)&&party.members.includes(requester.id);}
 if(channel==='normal')return sameScene(player,requester);
 return ['whisper','messenger'].includes(channel);
}
export function npcRememberConversationOffer({world,player,requester,memory,offer,channel='normal',partyId,delivered=false}={}){
 if(delivered!==true||!memory||!live(world,player)||!live(world,requester)||!npc(player)||npc(requester)||!types.has(offer?.type)||!validAudience(world,player,requester,channel,partyId))return false;
 if(offer.type==='quest-help'&&(!Number.isSafeInteger(offer.questId)||!player.profile.quests?.active?.[offer.questId]))return false;
 const now=world.now();memory.conversationOffer={type:offer.type,actorId:player.id,actorAccount:player.account,actorCharacter:player.characterId,actorToken:player.token,requesterId:requester.id,requesterAccount:requester.account,requesterCharacter:requester.characterId,requesterToken:requester.token,channel,partyId:channel==='party'?partyId:null,created:now,until:now+NPC_CONVERSATION_OFFER_MS,...(offer.type==='quest-help'?{questId:offer.questId}:{})};return true;
}
export function npcConversationConsent({world,player,requester,memory,text,channel='normal',partyId}={}){
 const offer=memory?.conversationOffer;if(!offer)return null;
 if(!live(world,player)||!live(world,requester)||!npc(player)||npc(requester)||offer.actorId!==player.id||offer.actorAccount!==player.account||offer.actorCharacter!==player.characterId||offer.actorToken!==player.token||offer.requesterId!==requester.id||offer.requesterAccount!==requester.account||offer.requesterCharacter!==requester.characterId||offer.requesterToken!==requester.token)return null;
 if(world.now()>=offer.until||offer.type==='quest-help'&&!player.profile.quests?.active?.[offer.questId]){delete memory.conversationOffer;return null;}
 if(channel!==offer.channel||!validAudience(world,player,requester,channel,partyId)||channel==='party'&&partyId!==offer.partyId)return null;
 const value=normalizeNpcText(text).replace(/\s+/g,' ').trim(),declined=negative.test(value),accepted=positive.test(value);if(!declined&&!accepted)return null;
 delete memory.conversationOffer;
 if(declined){memory.partyAskedAt=world.now()+600000;if(offer.type==='quest-help'&&memory.questHelpOffer?.questId===offer.questId)delete memory.questHelpOffer;}
 // Speech only. Even "yes" cannot accept a native invitation for the human.
 return {intent:null,topic:'offer-consent',handled:true,decision:declined?'decline':'accept',type:offer.type,...(offer.questId?{questId:offer.questId}:{}),text:declined?'No worries, maybe another time.':offer.type==='quest-help'?'Sure, we can use the normal party invite.':'Sounds good. Accept the party invite when you are ready.'};
}
// Only explicit authored invitation questions get a descriptor; factual
// requirements/questions about a plan are not pending consent offers.
export function npcDialogueOffer(text,topic){
 const value=normalizeNpcText(text).replace(/^well,\s+/,'').replace(/ :\)$/,'?');
 if(['dungeon','help','hello','status','unknown'].includes(topic)&&/^(?:ready for a dungeon run|(?:do you )?want to (?:run|do) (?:a |the )?dungeon|up for a dungeon run|want to farm or run a dungeon)\?/.test(value))return {type:'dungeon'};
 if(['party','hello','grind','help','status'].includes(topic)&&/\b(?:want to party(?: up)?|need (?:a party|company)|want to (?:do|share) a few pulls|want to group(?: afterward)?|do you want company for this run|want to party or farm)\?/.test(value))return {type:'party'};
 return null;
}
