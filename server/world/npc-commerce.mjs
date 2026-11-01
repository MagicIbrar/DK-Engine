import {npcGearWants} from './npc-commerce-wants.mjs';
import {itemRequirements} from './npc-chat-knowledge.mjs';
import {npcMerchantOffers} from './npc-merchant.mjs';
import {protectedNpcEquipmentUids} from './npc-equipment-ownership.mjs';
import {npcEquipmentBenefit} from './npc-builds.mjs';
import {Equipment} from '../../src/systems/items/equip.js';
import {upgradeRow} from '../../src/systems/items/ui/upgrade.js';
import {beltEligible} from '../../src/systems/items/belt.js';
import {sameScene} from './scene.mjs';
import {tradeSnapshot} from './trade.mjs';
import {pcshopSnapshot} from './pcshop.mjs';
import {commitLife,serializeLife} from './life-transactions.mjs';
import {commerceHash,commerceAskPrice,commerceBuyBudget,commerceWealth,nativeCommerceAnchor,NPC_COMMERCE_VALUE_POLICY,npcPublicHighTierGear} from './npc-commerce-value.mjs';
import {serverScope} from '../../src/systems/hud-options/superchat-rules.js';
import {npcOutgoingGiftStep} from './npc-generosity.mjs';

// ENGINE-CHOSEN slow advertising, utility, reserve and decision policies.
// Ordinary chat scope/cooldowns and trade/grid/UID/atomic storage stay authoritative.
export const NPC_COMMERCE_POLICY=Object.freeze({adMinMs:180000,adJitterMs:180000,globalAdMs:60000,offerWaitMs:30000,retryMs:2000,maxWanted:3,minPublicWantedDil:500000000,minPublicGearDil:10000000});
const flights=new WeakMap(),globalAds=new WeakMap();
const own=p=>p?.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile.authority==='server';
const human=p=>p&&p.npcPlayer!==true&&p.profile?.npcPlayer!==true;
const live=(world,p)=>world.players.get(p.account)===p&&!p.dead&&!p.leaving&&!p.sceneTransition;
const count=(p,index)=>(p.profile.inventory||[]).reduce((n,i)=>n+(i.itemIndex===index?(i.count||1):0),0);
// A saved listing can outlive its exact bag signature. Only native validated
// escrow may block an item or a direct trade.
const listed=(world,p)=>new Set((pcshopSnapshot(world,p)?.listings||[]).map(i=>i.uid));
const equipped=p=>new Set(Object.values(p.profile.equip?.presets?.[p.profile.equip?.active||0]||{}).filter(Boolean));
function questItem(world,p,index){const d=world.data.itemDB.def(index);if(world.data.itemDB.category(d)==='quest')return true;return Object.keys(p.profile.quests?.active||{}).some(id=>{const q=world.data.progression?.quests?.quests?.[id];return q&&((q.objectives||[]).some(o=>['collect','item','useItem'].includes(o.kind)&&(o.targets||[]).some(t=>Number(t.id)===index))||[...(q.requiredItems||q.require?.items||[]),...(q.rewards?.take||[])].some(r=>[].concat(r.itemIndex??r.item??r[0]).map(Number).includes(index)));});}
function eligible(world,p,item,{allowListed=false}={}){const d=world.data.itemDB?.def(item?.itemIndex);return !!d&&typeof item?.uid==='string'&&!item.bound&&!item.npcStartingStock&&!p.profile.npcSeed?.stock?.uids?.includes(item.uid)&&!equipped(p).has(item.uid)&&!protectedNpcEquipmentUids(world,p).has(item.uid)&&(allowListed||!listed(world,p).has(item.uid))&&Number(d.trade)!==0&&!d.period&&!d.eventType&&!/^event/.test(String(d.src||''))&&!(item.expiresAt&&item.expiresAt<=world.now())&&!item.pet?.active&&!item.pet?.inv?.length&&!questItem(world,p,item.itemIndex)&&Number.isInteger(item.count??1)&&(item.count??1)>0;}
/** Current owned gear's authored next-upgrade materials; missing only, native fee affordable.
 * Belt needs use actual native potion effects/requirements. No tickets or arbitrary wishlist.
 */
export function npcCommerceWants(world,p){if(!own(p)||!world.data.itemDB)return [];const db=world.data.itemDB,budget=commerceBuyBudget(p.profile);if(!budget)return [];db.T=world.data.itemUseData?.tables||db.T;
 const eq=new Equipment({db,game:{save:structuredClone(p.profile)}}),wanted=new Map();
 for(const {inst} of eq.worn()){const d=db.def(inst.itemIndex),next=d&&db.def(d.next),row=next&&upgradeRow(db,d);if(!row||!(Number(row.costDil)>0)||Number(row.costDil)>=p.profile.dil||!eq.slotsFor(next).some(slot=>eq.check({itemIndex:next.index},slot,p.stats).ok))continue;const choices=[Number(row.stone1),Number(row.stone2)].filter(i=>i>0&&db.def(i));if(!choices.some(i=>count(p,i)>0))for(const i of choices)wanted.set(i,Number(row.costDil));const special={5:9908,6:9913}[Number(d.rank)];if(special&&db.def(special)&&!count(p,special))wanted.set(special,Number(row.costDil));}
 const materials=[...wanted].filter(([index])=>Number(db.def(index)?.trade)!==0&&!db.def(index)?.period&&!questItem(world,p,index)).map(([itemIndex,fee])=>{const anchor=nativeCommerceAnchor(db,{itemIndex});
  // Zero-vendor-price Argates remain zero in the catalog. Ten percent of the
  // actual owned target's native fee is a declared local bid preference only.
  const maxPrice=Math.min(budget,p.profile.dil-fee,Math.max(1,Math.floor(Math.max(fee/10,anchor===null?0:anchor*NPC_COMMERCE_VALUE_POLICY.buyPercent/100))));
  return {itemIndex,count:1,maxPrice,provenance:'ENGINE-CHOSEN bid: max(10% authored refinement fee,70% native vendor anchor), capped by owned budget'};}).slice(0,NPC_COMMERCE_POLICY.maxWanted);return [...npcGearWants(world,p),...materials].slice(0,NPC_COMMERCE_POLICY.maxWanted);}
export function npcCommerceStock(world,p){return npcMerchantOffers(world,p).filter(o=>eligible(world,p,p.profile.inventory.find(i=>i.uid===o.uid))).map(o=>({...o,price:commerceAskPrice(world.data.itemDB,p.profile.inventory.find(i=>i.uid===o.uid),{owner:p.characterId||p.profile.id})})).filter(o=>o.price>0);}
function publicHighTierGear(world,item,price){return npcPublicHighTierGear(world.data.itemDB,item,price,NPC_COMMERCE_POLICY.minPublicGearDil);}
function useful(world,p,item,wants){const d=world.data.itemDB.def(item.itemIndex);if(wants.some(w=>w.itemIndex===item.itemIndex&&w.kind!=='gear'))return 1;
 if(beltEligible(d)&&d.reqLv<=p.profile.level&&(!d.maxLv||p.profile.level<=d.maxLv)&&((Number(d.classMask)>>>p.profile.classIndex)&1)){for(const kind of ['hp','mp'])if(Number(d.use?.[kind])>0||Number(d.use?.[kind+'Pct'])>0){const held=[...(p.profile.inventory||[]),...(p.profile.potionBelt||[])].reduce((n,i)=>{const u=world.data.itemDB.def(i.itemIndex)?.use;return n+(Number(u?.[kind])>0||Number(u?.[kind+'Pct'])>0?(i.count||1):0);},0);if(held<3)return Math.min(10-held,item.count||1);}}
 if(d.slot){const eq=new Equipment({db:world.data.itemDB,game:{save:structuredClone(p.profile)}});if(!eq.slotsFor(d).some(slot=>eq.check(item,slot,p.stats).ok))return 0;}
 const benefit=d.slot&&npcEquipmentBenefit(world,p,item);return benefit?.benefit>0?1:0;}
/** Speech/offer assessment of ONE actual requester-owned instance. It never
 * grants, removes, equips, spends or confirms anything. Native class/level/stat
 * and current equipment utility checks are the same as ordinary deal review.
 */
export function npcCommerceItemInterest(world,p,other,uid,{count:quantity=1}={}){
 if(!own(p)||!human(other)||!live(world,p)||!live(world,other)||!sameScene(p,other))return {needed:false,reason:'unavailable'};
 const rows=(other.profile.inventory||[]).filter(i=>i.uid===uid),item=rows.length===1&&rows[0],d=world.data.itemDB.def(item?.itemIndex);
 if(!item||!d||!Number.isInteger(quantity)||quantity<1||quantity>(item.count||1))return {needed:false,reason:'not-owned'};
 if(!eligible(world,other,item))return {needed:false,reason:'not-tradeable',itemIndex:d.index,name:d.name};
 if(d.slot){const eq=new Equipment({db:world.data.itemDB,game:{save:structuredClone(p.profile)}});if(!eq.slotsFor(d).some(s=>eq.check(item,s,p.stats).ok))return {needed:false,reason:'native-requirements',itemIndex:d.index,name:d.name};}
 const wants=npcCommerceWants(world,p),needed=useful(world,p,{...item,count:quantity},wants);if(!needed)return {needed:false,reason:'not-needed',itemIndex:d.index,name:d.name};
 const wanted=wants.find(w=>w.itemIndex===d.index),anchor=nativeCommerceAnchor(world.data.itemDB,item),maxPrice=wanted?wanted.maxPrice:anchor===null?0:Math.floor(anchor*NPC_COMMERCE_VALUE_POLICY.buyPercent/100),payment=Math.min(commerceBuyBudget(p.profile),maxPrice*Math.min(quantity,needed));
 return {needed:true,reason:'useful-owned-item',itemIndex:d.index,name:d.name,count:Math.min(quantity,needed),maxPayment:Math.max(0,payment),funded:payment>0,provenance:'actual requester-owned UID; native eligibility/effects and ENGINE-CHOSEN utility/budget'};
}
/** Recomputes the human's exact live bag items, quantity and useful native effects at every revision.
 * It never treats a linked chat name, stale snapshot, unneeded expensive item, or claimed price as value.
 */
export function npcCommerceDeal(world,p,other,trade,{allowPartyGift=false,allowUsefulGift=false}={}){if(!human(other)||!live(world,other)||!sameScene(p,other)||p.pcShopOpen||listed(world,p).size)return {accept:false,reason:'occupied or unavailable'};
 const partyGift=allowPartyGift&&p.partyId&&p.partyId===other.partyId,gift=(partyGift||allowUsefulGift)&&trade.other.confirmed&&!trade.self.items.length&&!trade.self.dil;
 const wants=npcCommerceWants(world,p);let credit=trade.other.dil,hasItems=false;
 for(const offered of trade.other.items){const actual=other.profile.inventory?.find(i=>i.uid===offered.uid);if(!actual||!eligible(world,other,actual)||actual.itemIndex!==offered.itemIndex||!Number.isInteger(offered.count)||offered.count<1||offered.count>(actual.count||1))return {accept:false,reason:'invalid owned item'};hasItems=true;if(gift){if(!partyGift&&useful(world,p,{...actual,count:offered.count},wants)<offered.count)return {accept:false,reason:'item not needed'};continue;}const quantity=useful(world,p,{...actual,count:offered.count},wants),anchor=nativeCommerceAnchor(world.data.itemDB,actual),wanted=wants.find(w=>w.itemIndex===actual.itemIndex);if(!quantity||anchor===null&&!wanted)return {accept:false,reason:'item not needed'};credit+=(wanted?wanted.maxPrice:Math.floor(anchor*NPC_COMMERCE_VALUE_POLICY.buyPercent/100))*Math.min(quantity,offered.count);}
 if(!Number.isSafeInteger(credit)||trade.other.dil>other.profile.dil)return {accept:false,reason:'unavailable payment'};
 if(gift&&(credit>0||hasItems))return {accept:true,items:[],dil:0,reason:partyGift?'explicit confirmed party gift':'explicit confirmed useful gift'};
 const stock=npcCommerceStock(world,p);
 if(trade.self.items.length||trade.self.dil){let ask=trade.self.dil;for(const offered of trade.self.items){const held=stock.find(i=>i.uid===offered.uid);if(!held||offered.count!==1)return {accept:false,reason:'offered stock changed'};ask+=held.price;}return {accept:credit>=ask&&trade.self.dil<=commerceBuyBudget(p.profile),items:trade.self.items.map(i=>({uid:i.uid,count:i.count})),dil:trade.self.dil,reason:credit>=ask?'reviewed exchange':'deal below asking value'};}
 const sale=stock.filter(i=>i.price<=credit).sort((a,b)=>b.price-a.price||a.uid.localeCompare(b.uid))[0];if(sale)return {accept:true,items:[{uid:sale.uid,count:1}],dil:0,reason:hasItems?'useful item exchange':'paid owned surplus'};
 if(hasItems&&trade.other.dil===0){const payment=Math.min(credit,commerceBuyBudget(p.profile));if(payment>0)return {accept:true,items:[],dil:payment,reason:'buying useful owned items'};}
 return {accept:false,reason:credit?'deal below asking value':'waiting for offer',waiting:credit===0};}

export async function npcCommerceStep({world,player:p,brain={},act=(player,input)=>world.action(player.account,{...input,token:player.token}),allowPartyGift=false,giftConsent}){if(!own(p)||!live(world,p))return {handled:false,status:'unavailable'};if(flights.has(p))return flights.get(p);const task=advance();flights.set(p,task);try{return await task;}finally{if(flights.get(p)===task)flights.delete(p);}
 async function advance(){const trade=tradeSnapshot(world,p);if(!trade)return {handled:false,status:'no trade'};if(brain.commerceTradeId!==trade.id){brain.commerceTradeId=trade.id;brain.commerceOpenedAt=world.now();}if(world.now()<(brain.commerceRetryAt||0))return {handled:true,status:'retry'};
 const action=async(operation,extra={})=>{const current=tradeSnapshot(world,p);if(!current)throw Error('Trade ended.');const response=await act(p,{type:'trade',operation,id:current.id,...(operation==='cancel'?{}:{revision:current.revision}),...extra});if(!response)throw Error('Ordinary trade was not accepted.');};
 try{const other=[...world.players.values()].find(q=>q.id===trade.partner.id);if(!human(other)||p.pcShopOpen||listed(world,p).size||p.profile.npcEquipment?.phase==='working'||brain.refineUid){await action('cancel');return {handled:true,status:'declined occupied trade'};}
 const outgoingGift=await npcOutgoingGiftStep({world,player:p,act,trade});if(outgoingGift)return outgoingGift;
 if(trade.incoming){await action('accept');brain.commerceOpenedAt=world.now();return {handled:true,status:'accepted trade invitation'};}
 const consent=typeof giftConsent==='function'?giftConsent(other,trade):false;
 if(consent==='await-confirmation')return {handled:true,status:'waiting for explicit gift confirmation'};
 const allowUsefulGift=consent===true;
 const deal=npcCommerceDeal(world,p,other,trade,{allowPartyGift,allowUsefulGift});if(deal.waiting&&world.now()-brain.commerceOpenedAt<NPC_COMMERCE_POLICY.offerWaitMs)return {handled:true,status:'waiting for owned offer'};
 if(!deal.accept){await action('cancel');return {handled:true,status:'declined '+deal.reason};}
 const rows=trade.self.items.map(i=>({uid:i.uid,count:i.count}));if(JSON.stringify(rows)!==JSON.stringify(deal.items)||trade.self.dil!==deal.dil){await action('offer',{items:deal.items,dil:deal.dil});return {handled:true,status:'offered '+deal.reason};}
 if(trade.phase==='open'&&trade.other.confirmed&&!trade.self.confirmed){await action('confirm');return {handled:true,status:'confirmed offer for review'};}
 if(trade.phase==='ready'&&trade.other.finalConfirmed&&!trade.self.finalConfirmed){await action('finalConfirm');return {handled:true,status:'confirmed reviewed exchange'};}return {handled:true,status:'holding reviewed offer'};
 }catch(error){brain.commerceRetryAt=world.now()+NPC_COMMERCE_POLICY.retryMs;brain.commerceError=String(error.message);return {handled:true,status:'blocked'};}}
}
/** Only factual WTS open-listing / WTT owned surplus+missing material / WTB funded missing-material ads.
 * No ad enters private chat, Megaphone, party chat, a different DK server, or an absent audience.
 */
export function npcCommerceAdvertisement(world,p,{channel='shout',kind='WTS'}={}){if(!own(p)||!live(world,p)||p.instanceId||!['shout','world'].includes(channel))return null;const audience=[...world.players.values()].filter(q=>human(q)&&!q.leaving&&!q.dead&&(channel==='world'?serverScope(q.channel)===serverScope(p.channel):sameScene(q,p)));if(!audience.length)return null;
 const state=p.pcShopOpen&&pcshopSnapshot(world,p),stock=npcCommerceStock(world,p),wants=npcCommerceWants(world,p);let text,signature;
 if(kind==='WTS'){const row=state?.listings.find(l=>{const item=p.profile.inventory?.find(i=>i.uid===l.uid);return eligible(world,p,item,{allowListed:true})&&publicHighTierGear(world,item,l.price);});if(!row)return null;const item=p.profile.inventory.find(i=>i.uid===row.uid);text=`WTS {item:${item.uid}} x${row.count} ${row.price} DIL each. My shop is open in Ardeca.`;signature=[kind,row.uid,row.count,row.price];}
 else if(kind==='WTT'){const offer=stock.find(o=>publicHighTierGear(world,p.profile.inventory?.find(i=>i.uid===o.uid),o.price)),wanted=wants.find(w=>w.maxPrice>=NPC_COMMERCE_POLICY.minPublicWantedDil);if(!offer||!wanted||p.pcShopOpen)return null;const name=world.data.itemDB.def(wanted.itemIndex)?.name;if(!name)return null;text=`WTT {item:${offer.uid}} for ${name}${wanted.kind==='gear'?'; needs '+itemRequirements(world.data,world.data.itemDB.def(wanted.itemIndex)): '.'} Up to ${wanted.maxPrice} DIL value; trade nearby.`;signature=[kind,offer.uid,wanted.itemIndex];}
 else if(kind==='WTB'){const wanted=wants.find(w=>w.maxPrice>=NPC_COMMERCE_POLICY.minPublicWantedDil);if(!wanted||p.pcShopOpen)return null;const name=world.data.itemDB.def(wanted.itemIndex)?.name;if(!name)return null;text=`WTB ${name} x1, up to ${wanted.maxPrice} DIL.${wanted.kind==='gear'?' Needs '+itemRequirements(world.data,world.data.itemDB.def(wanted.itemIndex))+'.':''} Trade nearby.`;signature=[kind,wanted.itemIndex,wanted.maxPrice];}else return null;
 if(text.length>250)return null;return {text,channel,kind,signature:JSON.stringify(signature),wealth:commerceWealth(p.profile),provenance:'actual owned open listing/surplus/needed authored input and funded budget'};}
export async function npcCommerceAdvertise({world,player:p,brain={},act=(player,input)=>world.action(player.account,{...input,token:player.token}),enabled=true,channel='shout',kind}){if(!enabled||!own(p)||!live(world,p)||p.instanceId||p.tradeId||brain.queue?.length||p._skills?.engine.casting||p.profile.npcEquipment?.phase==='working')return {handled:false,status:'quiet'};const now=world.now(),saved=p.profile.npcCommerceAd;if(now<(brain.quietUntil||0)||now<(brain.chatReady||0)||now<(brain.commerceAdRetryAt||0)||now<(saved?.nextAt||0))return {handled:false,status:'paced'};
 let global=globalAds.get(world);if(!global){global={nextAt:0,busy:false};globalAds.set(world,global);}if(global.busy||now<global.nextAt)return {handled:false,status:'global pacing'};
 // Initial delay is brain-only: no save or native scan for a newly created idle actor.
 if(!saved&&!brain.commerceAdReadyAt){brain.commerceAdReadyAt=now+NPC_COMMERCE_POLICY.adMinMs+commerceHash(p.characterId)%NPC_COMMERCE_POLICY.adJitterMs;return {handled:false,status:'initial delay'};}if(!saved&&now<brain.commerceAdReadyAt)return {handled:false,status:'initial delay'};
 const ad=npcCommerceAdvertisement(world,p,{channel,kind:kind||(p.pcShopOpen?'WTS':['WTT','WTB'][Math.floor(now/NPC_COMMERCE_POLICY.adMinMs)%2])});if(!ad){brain.commerceAdRetryAt=now+15000;return {handled:false,status:'no factual offer'};}global.busy=true;
 try{const nextAt=now+NPC_COMMERCE_POLICY.adMinMs+commerceHash(ad.signature+now)%NPC_COMMERCE_POLICY.adJitterMs;
 // Save the pacing receipt BEFORE broadcasting: ambiguous failures cannot duplicate an ad after restart.
 await serializeLife(p,async()=>{const profile=structuredClone(p.profile);profile.npcCommerceAd={version:1,policy:'ENGINE-CHOSEN',signature:ad.signature,nextAt};await commitLife(world,p,profile);});global.nextAt=now+NPC_COMMERCE_POLICY.globalAdMs;brain.chatReady=now+2500;
 const current=live(world,p)&&npcCommerceAdvertisement(world,p,{channel,kind:ad.kind});if(!current||current.signature!==ad.signature)return {handled:false,status:'offer changed before broadcast'};
 const accepted=await act(p,{type:'chat',channel:ad.channel,text:ad.text});if(!accepted)throw Error('Ordinary commerce chat was not accepted.');return {handled:false,status:'advertised '+ad.kind};
 }catch(error){brain.commerceAdRetryAt=now+NPC_COMMERCE_POLICY.retryMs;brain.commerceError=String(error.message);return {handled:false,status:'blocked'};}finally{global.busy=false;}}
