import {normalizeNpcText,npcSentenceIntent} from './npc-language.mjs';
import {npcCommerceItemInterest,npcCommerceWants} from './npc-commerce.mjs';
import {sameScene,sceneKey} from './scene.mjs';
import {tradeSnapshot} from './trade.mjs';
import {itemRequirements} from './npc-chat-knowledge.mjs';

export const NPC_COMMERCE_CONVERSATION_POLICY=Object.freeze({contextMs:60000,maxLength:250});
const live=(w,p)=>p&&w?.players?.get(p.account)===p&&!p.leaving;
const noun=/\b(?:items?|gear|equipment|weapons?|armor|armour|swords?|bows?|staff|daggers?|axes?|potions?|pots?|argates?|materials?|this|these|it)\b/;
const free=q=>/\b(?:free|gift|give|giving|donate|donation)\b/.test(q)&&!/\b(?:not free|not a gift|do not give|no gift|not giving)\b/.test(q);
const followup=q=>/^(?:yes|yeah|yep|sure|okay|ok|nah|no|no thanks|never mind|nevermind|it is free|it's free|for free|a gift|what do you need|what would you need|what about this)[.!? ]*$/.test(q);
/** Bounded semantic families, layered over the existing normalizer/parser.
 * Root applies attention bypass only to directly addressed/focused speech.
 * Action requests and negative offers keep their original meaning.
 */
export function npcCommerceConversationIntent(text){
 const q=normalizeNpcText(text),intent=npcSentenceIntent(q);
 if(['follow','stop','roam','lure','party','prepare','pvp','decline'].includes(intent)||/\b(?:do not|cannot|never|not interested|no need|not giving)\b/.test(q))return null;
 if(/\b(?:what|which)\b.{0,22}\b(?:items?|gear|equipment|materials?)\b.{0,22}\b(?:want|need|use)|\bwhat (?:do|would) you (?:want|need)\b/.test(q))return 'item-needs';
 if((noun.test(q)||q.includes('{item:'))&&(/\b(?:want|need|like|interested in|could use|can use|(?:can|could|would) you use)\b/.test(q)||/\b(?:give|gift|donate|spare|take|for you)\b/.test(q)))return 'offer-items';
 if(/\b(?:would|could|will) (?:this|it|these) (?:help|work)|\bcan i (?:give|gift) you\b/.test(q))return 'offer-items';
 return null;
}

// ENGINE-CHOSEN speech continuation only. Exact current identities/scene,
// channel, goal, ownership, utility inputs and the immediately prior turn bind it.
function clarificationGoal(world,brain){
 const t=brain.taskGoal;if(!t)return null;
 const finite=['farm','merchant'].includes(t.kind)&&t.version===2,active=finite?Number(t.workedMs)<Number(t.durationMs):Number(t.until)>world.now();
 // Same identity as npcRoutineWork, plus selected quest and completion state.
 // Advancing work/sample counters and a recalculated deadline are not new goals.
 return [t.kind,t.map,t.cycle??null,t.started??null,t.questId??null,active];
}
function clarificationFingerprint(world,p,r,brain,uid){
 const item=(r.profile.inventory||[]).find(i=>i.uid===uid),party=id=>{const q=world.parties?.get(id);return q&&[q.id,q.leader,q.members];};
 return JSON.stringify([[p.id,p.account,p.characterId,p.token],[r.id,r.account,r.characterId,r.token],sceneKey(p.map,p.instanceId,p.channel),sceneKey(r.map,r.instanceId,r.channel),clarificationGoal(world,brain),brain.questId||null,p.profile.quests?.active||{},r.profile.quests?.active||{},party(p.partyId),party(r.partyId),p.profile.inventory||[],p.profile.potionBelt||[],p.profile.equip||{},p.profile.level,p.profile.classIndex,p.profile.dil,p.profile.stats||{},p.stats||{},p.pcShopOpen||false,p.profile.pcShop||null,item||null,item&&world.data.itemDB.def(item.itemIndex)]);
}
function context(world,p,r,memory){const c=memory?.commerceConversation;return c?.version===1&&c.teacher===p.id&&c.requester===r.id&&world.now()<c.until?c:null;}
function knownItem(world,p,r,q,saved,raw){
 const bag=r.profile.inventory||[],tokens=[...String(raw).matchAll(/\{item:([^}]{1,160})\}/g)].map(m=>m[1]);
 const trade=tradeSnapshot(world,p),offered=trade?.partner.id===r.id&&trade.other.items.length===1?trade.other.items[0]:null,resolve=(uid,source)=>({uid,count:offered?.uid===uid?offered.count:1,source});
 if(tokens.length===1)return resolve(tokens[0],'linked');if(tokens.length>1)return null;
 const named=bag.filter(i=>{const name=normalizeNpcText(world.data.itemDB.def(i.itemIndex)?.name);return name.length>2&&q.includes(name);});if(named.length===1)return resolve(named[0].uid,'named');if(named.length>1)return null;
 if(offered)return resolve(offered.uid,'ordinary-offer');
 if(saved?.uid&&followup(q)||saved?.uid&&/\b(?:this|it)\b/.test(q))return {uid:saved.uid,count:saved.count,source:'bound-context'};
 return null;
}
/** Speech only. All named/linked/continued items are checked in the requester's
 * current bag; private UIDs never appear in replies. No action, cast, trade
 * confirmation, goal interruption or optimistic item/price claim is produced.
 */
export function npcCommerceReply({world,player:p,requester:r,text,memory={},maxLength=250,channel,brain={}}={}){
 if(!world?.data?.itemDB||!live(world,p)||!live(world,r)||p===r||p.npcPlayer!==true||p.profile?.npcPlayer!==true||p.profile.authority!=='server'||r.npcPlayer===true||r.profile?.npcPlayer===true||typeof text!=='string')return null;
 if(!sameScene(p,r)){if(/^is (?:it|this|that) useful[.!? ]*$/.test(normalizeNpcText(text))){delete memory.commerceFollowup;return {handled:true,text:'Which item? Show it near me so I can check.',topic:'commerce',intent:null,requiresTrade:true};}return null;}
 const q=normalizeNpcText(text),saved=context(world,p,r,memory),intent=npcCommerceConversationIntent(q),usefulness=/^is (?:it|this|that) useful[.!? ]*$/.test(q);if(!intent&&!(saved&&followup(q))&&!usefulness)return null;
 const max=Math.max(25,Math.min(NPC_COMMERCE_CONVERSATION_POLICY.maxLength,Math.floor(Number(maxLength)||250))),finish=(answer,extra={})=>({handled:true,text:answer.length>max?answer.slice(0,max-1).trimEnd()+'…':answer,topic:'commerce',intent:null,requiresTrade:true,...extra});
 if(usefulness){
  const bound=memory.commerceFollowup,valid=bound?.actor===p.id&&bound.requester===r.id&&bound.subjectId===r.id&&bound.delivered===true&&['normal','party','whisper','messenger'].includes(channel)&&bound.channel===channel&&world.now()<bound.until&&Number.isInteger(bound.turn)&&memory.followupTurn===bound.turn+1&&bound.fingerprint===clarificationFingerprint(world,p,r,brain,bound.uid);
  if(!valid||!bound.uid||(r.profile.inventory||[]).filter(i=>i.uid===bound.uid).length!==1){delete memory.commerceFollowup;return finish('Which item? Link it or show it in trade so I can check.');}
  const interest=npcCommerceItemInterest(world,p,r,bound.uid,{count:bound.count||1});
  bound.turn=memory.followupTurn;bound.delivered=false;
  const d=world.data.itemDB.def(interest.itemIndex),req=d?.slot?` Needs ${itemRequirements(world.data,d)}.`:'';
  return finish(interest.needed?'Yeah, I could use '+interest.name+'.'+req+' Trade me?':interest.reason==='not-needed'?"I'll pass; I don't need it right now.":'I cannot use that one right now.'+req,{interested:interest.needed,reason:interest.reason});
 }
 if(/^(?:nah|no|no thanks|never mind|nevermind)[.!? ]*$/.test(q)){delete memory.commerceConversation;return finish('No problem. I have not taken or sent anything.');}
 const resolve=knownItem(world,p,r,q,saved,text),isFree=!!resolve&&(free(q)||!!saved?.free&&saved.uid===resolve.uid&&followup(q));
 memory.commerceConversation={version:1,teacher:p.id,requester:r.id,until:world.now()+NPC_COMMERCE_CONVERSATION_POLICY.contextMs,...(resolve?{uid:resolve.uid,count:resolve.count||1}:{}),free:isFree};
 if(['normal','party','whisper','messenger'].includes(channel))memory.commerceFollowup={actor:p.id,requester:r.id,subjectId:r.id,channel,turn:memory.followupTurn,until:world.now()+NPC_COMMERCE_CONVERSATION_POLICY.contextMs,...(resolve?{uid:resolve.uid,count:resolve.count||1}:{}),fingerprint:clarificationFingerprint(world,p,r,brain,resolve?.uid)};
 
 if(intent==='item-needs'){
  const need=npcCommerceWants(world,p)[0],name=need&&world.data.itemDB.def(need.itemIndex)?.name;
  const request=name?`WTB ${name} x1; up to ${need.maxPrice} DIL.${need.kind==='gear'?' Needs '+itemRequirements(world.data,world.data.itemDB.def(need.itemIndex))+'.':''} Both sides confirm.`:null;
  return finish(request&&request.length<=max?request:'Show me an actual item in trade so I can check its full requirements and my current budget.');
 }
 if(!resolve)return finish(max<100?'Which item? Link it or show it in trade.':'Which item do you mean? Link its item name or put it in the trade window. I will check whether I can use it.');
 const interest=npcCommerceItemInterest(world,p,r,resolve.uid,{count:resolve.count||1});
 const itemDef=world.data.itemDB.def(interest.itemIndex),req=itemDef?.slot?` It needs ${itemRequirements(world.data,itemDef)}.`:'';
 if(!interest.needed){const reason=interest.reason==='native-requirements'?'My class, level or stats do not meet it.':interest.reason==='not-tradeable'?'That item cannot be offered from your bag.':interest.reason==='not-needed'?'It does not improve my current equipment or fill a supply need.':'I cannot verify that exact item in your current bag.';return finish('Thanks, but I will pass. '+reason+(interest.reason==='native-requirements'?req:''),{interested:false,reason:interest.reason});}
 if(p.pcShopOpen||p.profile.pcShop?.listings?.length)return finish(`I could use ${interest.name}, but my shop stock is reserved. Ask after I close the stall.`,{interested:true,reason:'shop-reserved'});
 if(isFree){const trade=tradeSnapshot(world,p),item=r.profile.inventory.find(i=>i.uid===resolve.uid);if(trade?.partner.id===r.id&&trade.other.items.length===1&&trade.other.items[0].uid===resolve.uid&&trade.other.items[0].count===(resolve.count||1)&&trade.other.dil===0)memory.commerceConversation.offer={id:trade.id,revision:trade.revision,uid:resolve.uid,count:resolve.count||1,fingerprint:JSON.stringify(item)};
  return finish(max<100?'Useful to me. Show it in trade; say free, then confirm.':`I could use ${interest.name}.${req} Put it in trade and tell me it is free. Your final confirmation is still required; this conversation transfers nothing.`,{interested:true,giftDiscussed:true});}
 if(!interest.funded)return finish(`I could use ${interest.name}, but I have no funded buying budget right now. I will not promise payment I cannot make.`,{interested:true,reason:'unfunded'});
 return finish(`I could use ${interest.name}.${req} My buying budget allows up to ${interest.maxPayment} DIL. Show it in trade; we both confirm.`,{interested:true,maxPayment:interest.maxPayment});
}
/** Trusted director callback, never an HTTP flag. The spoken gift must refer
 * to this exact current native offer, and the human must already have confirmed.
 * Vague/other-person/expired/revised offers cannot authorize a zero-return gift.
 */
export function npcCommerceGiftConsent({world,player:p,requester:r,memory,trade=tradeSnapshot(world,p)}={}){
 if(!world||!live(world,p)||!live(world,r)||!sameScene(p,r)||p.npcPlayer!==true||r.npcPlayer===true)return false;
 const current=tradeSnapshot(world,p);if(!current||JSON.stringify(current)!==JSON.stringify(trade))return false;
 const c=context(world,p,r,memory),o=c?.offer;if(!c?.free||!o||!trade||trade.partner.id!==r.id||trade.id!==o.id||trade.revision!==o.revision||trade.self.items.length||trade.self.dil||trade.other.dil||trade.other.items.length!==1)return false;
 const row=trade.other.items[0],item=r.profile.inventory?.find(i=>i.uid===o.uid);if(row.uid!==o.uid||row.count!==o.count||JSON.stringify(item)!==o.fingerprint)return false;
 const interest=npcCommerceItemInterest(world,p,r,o.uid,{count:o.count});if(!interest.needed||interest.count!==o.count)return false;return trade.other.confirmed?true:'await-confirmation';
}
