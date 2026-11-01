import {fishingBusy} from './fishing.mjs';
import {sameScene,mapFor} from './scene.mjs';
import {npcReachableApproach} from './npc-navigation.mjs';
import {PCSHOP_ARDECA,PCSHOP_MAX_DIL,pcshopSnapshot} from './pcshop.mjs';
import {Equipment} from '../../src/systems/items/equip.js';
import {commitLife,serializeLife} from './life-transactions.mjs';
import {commerceAskPrice,commerceHash} from './npc-commerce-value.mjs';
import {npcTownStallPlan} from './npc-town-layout.mjs';
import {protectedNpcEquipmentUids} from './npc-equipment-ownership.mjs';
import {npcEquipmentBenefit} from './npc-builds.mjs';
import {npcNativeRoute} from './npc-routing.mjs';
// ENGINE-CHOSEN NPC objective and sale-price preferences. Every listing/open/close/collection
// uses ordinary Personal Shop validation; this helper creates no items, stock, DIL or permissions.
export const NPC_MERCHANT_POLICY=Object.freeze({dwellMs:600000,dwellJitterMs:600000,absenceMs:300000,cooldownMs:300000,humanRadius:40,maxOffers:3,retryMs:2000});
const flights=new WeakMap();
const ownNpc=p=>p?.profile?.authority==='server'&&p.profile.npcPlayer===true&&p.npcPlayer===true;
const dist=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const nativeMap=(world,p)=>p.map===PCSHOP_ARDECA&&!p.instanceId&&Number(world.data.dungeonData?.dg?.maps?.[p.map]?.raw?.PcStore)===1;
// ENGINE-CHOSEN city audience: a real human occupies this native Ardeca scene;
// distant market districts may remain seated without a forty-unit pile-up.
const presentHuman=(world,p,policy)=>nativeMap(world,p)&&[...world.players.values()].some(h=>h!==p&&h.profile?.npcPlayer!==true&&h.npcPlayer!==true&&!h.dead&&!h.leaving&&sameScene(h,p));
const taskOf=p=>{const t=p.profile?.npcMerchant;return t?.version===1&&t.policy==='ENGINE-CHOSEN'&&['listing','open','closing','cooldown'].includes(t.phase)&&Number.isFinite(t.closesAt)&&Array.isArray(t.uids)?t:null;};
function questItems(world){const out=new Set();for(const q of Object.values(world.data.progression?.quests?.quests||{})){
 for(const o of q.objectives||[])if(['collect','item','useItem'].includes(o.kind))for(const t of o.targets||[])out.add(Number(t.id));
 for(const r of [...(q.requiredItems||[]),...(q.require?.items||[])])for(const id of [].concat(r.itemIndex??r.item??r[0]))out.add(Number(id));
 for(const reward of [q.rewards,...(q.rewardVariants?.list||[]).map(v=>v.reward||v.rewards||v)])for(const r of reward?.take||[])for(const id of [].concat(r.item))out.add(Number(id));
 }return out;}
const protectedQuestItems=new WeakMap();
function protectedItems(world){const key=world.data;if(!protectedQuestItems.has(key))protectedQuestItems.set(key,questItems(world));return protectedQuestItems.get(key);}
const gearSlots=new Set(['weapon','offhand','helmet','armor','pants','glove','boots','accessory']);
// ENGINE-CHOSEN recovery reserve matches the ordinary supply target. All other
// ETC remains held unless its authored service/quest need is proven absent.
function recoveryKinds(db,p,d){if(!d)return [];return ['hp','mp'].filter(k=>beltEligible(d)&&d.reqLv<=p.profile.level&&(!d.maxLv||p.profile.level<=d.maxLv)&&((Number(d.classMask)>>>p.profile.classIndex)&1)&&(Number(d.use?.[k])>0||Number(d.use?.[k+'Pct'])>0));}
function recoveryReserve(db,p){const totals={hp:0,mp:0};for(const i of [...(p.profile.inventory||[]),...(p.profile.potionBelt||[])])if(!i.expiresAt)for(const k of recoveryKinds(db,p,db.def(i.itemIndex)))totals[k]+=i.count||1;return totals;}
/** Owned surplus gear only. Seeded gear is excluded by BOTH instance marker and permanent seed UID ledger.
 * Non-kit goods are ordinary earned/transferred surplus or explicitly labeled finite NEW merchant world inventory.
 * Compatible gear is retained unless it duplicates worn gear or is a verified
 * non-improvement with every compatible ordinary slot filled. Seller preference
 * reuses the existing ENGINE-CHOSEN build utility; unknown/future gear stays held.
 */
export function npcMerchantOffers(world,p,{limit=NPC_MERCHANT_POLICY.maxOffers,onlyUids=null}={}){
 if(!ownNpc(p)||!world.data.itemDB||!Array.isArray(p.profile.npcSeed?.stock?.uids))return [];
 const db=world.data.itemDB,stock=new Set(p.profile.npcSeed.stock.uids),showcase=new Set(p.profile.npcMarketShowcase?.version===1?p.profile.npcMarketShowcase.uids:[]),protectedIds=protectedItems(world),reserved=protectedNpcEquipmentUids(world,p);
 for(const preset of Object.values(p.profile.equip?.presets||{}))for(const uid of Object.values(preset||{}))if(uid)reserved.add(uid);
 const eq=new Equipment({db,game:{save:structuredClone(p.profile)}}),worn=eq.worn().map(r=>r.inst);
 const copyKey=i=>JSON.stringify([i.itemIndex,i.grade||'normal',i.rnd||[],i.sockets||[],i.brand||[],i.crest||null]);
 const seen=new Set(),out=[],recovery=recoveryReserve(db,p);
 for(const item of p.profile.inventory||[]){const d=db.def(item.itemIndex);
  if(onlyUids&&!onlyUids.has(item.uid)||!item.uid||seen.has(item.uid)||stock.has(item.uid)||reserved.has(item.uid)||item.npcStartingStock||item.bound||item.expiresAt||!d||
    (!gearSlots.has(d.slot)&&db.category(d)!=='potion')||db.category(d)==='quest'||/^event/.test(String(d.src||''))||d.eventType||Number(d.trade)===0||d.period||protectedIds.has(item.itemIndex)||item.pet?.active||item.pet?.inv?.length)continue;
  if(!Number.isInteger(item.count??1)||(item.count??1)<1)continue;
  let quantity=1;if(gearSlots.has(d.slot)){const otherClass=!((Number(d.classMask)>>>p.profile.classIndex)&1);
   if(!showcase.has(item.uid)&&!otherClass&&!worn.some(held=>held.uid!==item.uid&&copyKey(held)===copyKey(item))){
    const slots=eq.slotsFor(d).filter(s=>s<100);
    if(!slots.length||slots.some(s=>!eq.get(s))||d.reqLv>p.profile.level||d.maxLv>0&&p.profile.level>d.maxLv)continue;
    const candidate=npcEquipmentBenefit(world,p,item);
    if(!candidate||!Number.isFinite(candidate.benefit)||candidate.benefit>0)continue;
   }
  }else{const kinds=recoveryKinds(db,p,d);if(!kinds.length)continue;quantity=Math.min(item.count||1,...kinds.map(k=>Math.max(0,recovery[k]-10)));if(quantity<1)continue;for(const k of kinds)recovery[k]-=quantity;}
  const price=commerceAskPrice(db,item,{owner:p.characterId||p.profile.id});
  if(!Number.isSafeInteger(price)||price<1||price>PCSHOP_MAX_DIL)continue;
  seen.add(item.uid);out.push({uid:item.uid,itemIndex:item.itemIndex,count:quantity,price,
    provenance:item.npcInitialMarketStock==='ENGINE-CHOSEN'&&p.profile.npcInitialMarketStock?.version===1&&p.profile.npcInitialMarketStock.uids?.includes(item.uid)?'finite NEW merchant initial world inventory; not earned loot; no refill':showcase.has(item.uid)?'one-time native private-bot market stock; equipped/quest goods protected':'owned native surplus; seed/equipment/service/quest protected; recovery reserve retained',pricePolicy:'ENGINE-CHOSEN native base-price anchor; deterministic occasional15% discount'});
  if(out.length>=Math.max(1,Math.min(3,Math.floor(limit)||1)))break;
 }return out;
}
// ENGINE-CHOSEN minority opportunity: owned surplus gets a market attempt before
// generic vendor disposal. Accepted quests, work, combat and human plans retain priority.
export function npcMerchantOpportunity(world,p,brain={}, {allowQuestPause=false}={}){
 if(!ownNpc(p)||world.players.get(p.account)!==p||p.dead||p.leaving||!nativeMap(world,p)||!presentHuman(world,p,NPC_MERCHANT_POLICY)||p.pcShopOpen||p.partyId||p.instanceId||p.sceneTransition||p.commandActive||p.progressCommitting||p.tradeCommitting||p.tradeId||p.duelId||p.mount?.phase==='on'||fishingBusy(p)||p.attackTarget||p._skills?.engine.casting||brain.follow||brain.lure||(!allowQuestPause&&brain.questId)||brain.objectiveFlight||brain.refineUid||brain.refineRestore||brain.prepareUntil>world.now()||(!allowQuestPause&&Object.keys(p.profile.quests?.active||{}).length)||p.profile.npcEquipment?.phase==='working'||['prepared','invited','confirming'].includes(p.profile.npcGift?.phase)||p.path?.length&&!brain.merchantApproach)return false;
 const routine=brain.taskGoal||p.profile.npcRoutine;if(routine?.until>world.now()&&(!allowQuestPause||!['quest','farm'].includes(routine.kind))&&!['rest','merchant'].includes(routine.kind))return false;
 const task=taskOf(p);if(task&&task.phase!=='cooldown'||task?.retryAt>world.now())return false;
 const residents=[...world.players.values()].filter(q=>ownNpc(q)&&!q.dead&&!q.leaving&&sameScene(p,q)),busy=residents.filter(q=>q.pcShopOpen||taskOf(q)&&taskOf(q).phase!=='cooldown').length;
 if(busy>=Math.max(1,Math.floor(residents.length/4)))return false;
 return npcMerchantOffers(world,p).length>0;
}
/** Pure advisory only: normal saved-profile admission/reuse stays root-owned.
 * No identity, location, class, resource or bound-stock edits. */
export function npcMerchantResidentPriority(world,profile,{map=150,channel=0,allowQuestPause=false}={}){
 if(profile?.authority!=='server'||profile.npcPlayer!==true||Number(profile.map)!==Number(map)||map!==PCSHOP_ARDECA||profile.instanceId||profile.partyId||(profile.channel||0)!==channel||profile.npcMerchant?.retryAt>world.now()||!allowQuestPause&&Object.keys(profile.quests?.active||{}).length)return 0;
 return npcMerchantOffers(world,{profile,npcPlayer:true,characterId:profile.id}).length?1:0;
}
// ENGINE-CHOSEN finite vendor deferral for an actual merchant intention. This
// private profile field is not public roster/online metadata. One released key
// is retained; reconnects/repeated decisions cannot renew that same intention.
export const NPC_MERCHANT_RESERVATION_MS=180000;
const reservationKey=key=>typeof key==='string'&&/^[A-Za-z0-9_.:-]{1,96}$/.test(key);
const reservationNonce=(p,key,startedAt)=>`${p.characterId}:${key}:${startedAt}`;
const reservationCancellations=new WeakMap();
const pendingReservationCancellation=p=>{const pending=reservationCancellations.get(p),t=reservationOf(p);return pending&&t&&pending.account===p.account&&pending.characterId===p.characterId&&pending.nonce===t.nonce?pending:null;};
function reservationOf(p){const t=p.profile.npcMerchantReservation;
 return t?.version===1&&t.policy==='ENGINE-CHOSEN'&&['held','released'].includes(t.phase)&&
  t.account===p.account&&t.characterId===p.characterId&&p.characterId===p.profile.id&&reservationKey(t.intentKey)&&
  Number.isSafeInteger(t.startedAt)&&Number.isSafeInteger(t.expiresAt)&&t.expiresAt>t.startedAt&&t.expiresAt-t.startedAt<=NPC_MERCHANT_RESERVATION_MS&&
  t.nonce===reservationNonce(p,t.intentKey,t.startedAt)&&Array.isArray(t.uids)&&t.uids.length<=3&&new Set(t.uids).size===t.uids.length&&t.uids.every(uid=>typeof uid==='string'&&uid.length>0)?t:null;
}
function reservationActor(world,p){
 if(!ownNpc(p)||world.players.get(p.account)!==p||p.characterId!==p.profile.id||p.dead||p.leaving||p.instanceId||p.tradeId||p.tradeCommitting||p.progressCommitting||p.pcShopOpen)return false;
 const party=p.partyId&&world.parties?.get(p.partyId);if(p.partyId&&!party)return false;
 return !party?.members.some(id=>[...world.players.values()].some(q=>q.id===id&&q.profile?.npcPlayer!==true&&q.npcPlayer!==true));
}
function reservationRoute(world,p){
 if(p.mount||p.sceneTransition)return false;
 if(Number(world.data.dungeonData?.dg?.maps?.[PCSHOP_ARDECA]?.raw?.PcStore)!==1)return false;
 const placements=world.data.progression?.npcs,rows=placements?.placements?.[PCSHOP_ARDECA]?.rows||[];
 const row=rows.find(([id,x,z])=>Number.isFinite(x)&&Number.isFinite(z)&&placements.npcs?.[id]?.jobs?.some(([job])=>Number(job)===4));
 if(!row)return false;
 if(p.map===PCSHOP_ARDECA)return true;
 const route=npcNativeRoute(world.data,p.map,PCSHOP_ARDECA,{level:p.profile.level,dil:p.profile.dil,channel:p.channel||0,origin:p});
 return !!route?.length&&(!(Number(p.profile.life?.grade?.chaotic)>0)||!['npctravel','channel'].includes(route[0].action.type));
}
/** Pure exact-UID vendor exclusion. Caller must supply its CURRENT stable
 * merchant intent key; absence/human priority never inherits old reservations.
 * Walking/admission failure is cancelled through the asynchronous step below. */
export function npcMerchantReservedSaleUids(world,p,{intentKey=null}={}){
 const t=reservationOf(p),now=world.now();
 if(pendingReservationCancellation(p)||!reservationKey(intentKey)||!t||t.phase!=='held'||t.intentKey!==intentKey||!Number.isSafeInteger(now)||now<t.startedAt||now>=t.expiresAt||!reservationActor(world,p)||!reservationRoute(world,p))return new Set();
 const eligible=new Set(npcMerchantOffers(world,p).map(o=>o.uid));return new Set(t.uids.filter(uid=>eligible.has(uid)));
}
/** Trusted director-only intention metadata, never grants or inventory edits.
 * Root cancels on accepted human plans and failed ordinary walking/admission.
 * Returns an empty set on checkpoint failure; generic sales are not held up. */
export async function npcMerchantReservationStep({world,player:p,intentKey=null,cancel=false}){
 if(!ownNpc(p)||world.players.get(p.account)!==p)return {status:'unavailable',uids:new Set(),expiresAt:null};
 try{return await serializeLife(p,async()=>{
  const now=world.now(),old=reservationOf(p),validKey=reservationKey(intentKey);
  const release=async reason=>{if(old?.phase==='held'){
   const pending={account:p.account,characterId:p.characterId,nonce:old.nonce,reason};reservationCancellations.set(p,pending);
   await save({...old,phase:'released',uids:[],reason});
   if(reservationCancellations.get(p)===pending)reservationCancellations.delete(p);
  }return {status:reason,uids:new Set(),expiresAt:old?.expiresAt??null};};
  const save=async task=>{if(JSON.stringify(p.profile.npcMerchantReservation)===JSON.stringify(task))return;const profile=structuredClone(p.profile);profile.npcMerchantReservation=task;await commitLife(world,p,profile);};
  const pending=pendingReservationCancellation(p);if(pending)return release(pending.reason);
  reservationCancellations.delete(p);
  if(cancel||!validKey||!reservationActor(world,p))return release(cancel?'cancelled':!validKey?'no current merchant intent':'actor priority');
  if(!Number.isSafeInteger(now)||old&&now<old.startedAt)return release('clock rollback');
  if(old?.intentKey===intentKey&&(old.phase==='released'||now>=old.expiresAt))return release(old.phase==='released'?'finished intent':'expired');
  if(!reservationRoute(world,p))return release('native route unavailable');
  const offers=npcMerchantOffers(world,p),eligible=new Set(offers.map(o=>o.uid));
  const uids=old?.intentKey===intentKey?old.uids.filter(uid=>eligible.has(uid)):offers.map(o=>o.uid);
  if(!uids.length)return release('no eligible owned stock');
  const task=old?.intentKey===intentKey?{...old,uids}:{version:1,policy:'ENGINE-CHOSEN',phase:'held',account:p.account,characterId:p.characterId,intentKey,startedAt:now,expiresAt:now+NPC_MERCHANT_RESERVATION_MS,nonce:reservationNonce(p,intentKey,now),originMap:p.map,uids,reason:null};
  await save(task);return {status:'reserved',uids:new Set(uids),expiresAt:task.expiresAt};
 });}catch{return {status:'checkpoint failed',uids:new Set(),expiresAt:null};}
}
export function npcMerchantSnapshot(world,p){const t=taskOf(p);return t?{...structuredClone(t),open:!!p.pcShopOpen,
 listings:pcshopSnapshot(world,p)?.listings.length||0,income:pcshopSnapshot(world,p)?.income||0}:null;}
async function saveTask(world,p,task){if(JSON.stringify(p.profile.npcMerchant)===JSON.stringify(task))return;
 await serializeLife(p,async()=>{const profile=structuredClone(p.profile);profile.npcMerchant=structuredClone(task);await commitLife(world,p,profile);});}
/** Root calls this before other objectives for active tasks. `requested` only initiates a new task;
 * `cancel` explicitly interrupts it. Active stall holds are handled even without further requests.
 * act has root's ordinary (player,input) signature and MUST await accepted server commands.
 */
export async function npcMerchantStep({world,player:p,brain={},act=(player,input)=>world.action(player.account,{...input,token:player.token}),requested=false,cancel=false,policy=NPC_MERCHANT_POLICY}){
 if(!ownNpc(p)||world.players.get(p.account)!==p||p.leaving||p.dead)return {handled:false,status:'unavailable'};
 if(flights.has(p))return flights.get(p);
 const operation=advance();flights.set(p,operation);
 try{return await operation;}finally{if(flights.get(p)===operation)flights.delete(p);}
 async function advance(){
  const now=world.now();let task=taskOf(p);
  const result=(handled,status)=>({handled,status,task:npcMerchantSnapshot(world,p)});
  const changed=async updates=>{task={...task,...updates};await saveTask(world,p,task);};
  const ordinary=async input=>{const response=await act(p,{type:'pcshop',...input});if(!response)throw Object.assign(Error('NPC merchant command was not accepted.'),{status:503});return response;};
  try{
   if(p.sceneTransition||p.tradeCommitting||p.progressCommitting||p.commandActive)return result(!!task&&task.phase!=='cooldown','busy');
   if(now<(brain.merchantRetryAt||0))return result(!!task&&task.phase!=='cooldown','retry');
   if(task?.phase==='cooldown'){
    const state=pcshopSnapshot(world,p);if(state?.income>0&&(Number(p.profile.dil)||0)+state.income<=PCSHOP_MAX_DIL){await ordinary({operation:'collect'});return result(true,'collecting saved sales');}
    if(now<(task.retryAt||0)||!requested)return result(false,'cooldown');task=null;
   }
   if(!task){
    const approach=brain.merchantApproach,continuing=approach&&approach.map===p.map&&approach.channel===(p.channel||0)&&now<approach.expires;
    if(cancel||!nativeMap(world,p)||!presentHuman(world,p,policy)||p.tradeId||p.duelId||p.mount?.phase==='on'||fishingBusy(p)){delete brain.merchantApproach;return result(false,'not seeking a stall');}
    if(!requested&&!continuing){delete brain.merchantApproach;return result(false,'not seeking a stall');}
    const offers=npcMerchantOffers(world,p,{limit:policy.maxOffers});if(!offers.length){delete brain.merchantApproach;return result(false,'no owned surplus');}
    const stall=npcTownStallPlan(world,p);if(!stall)return result(true,'waiting for safe stall space');
    if(!stall.near){brain.merchantApproach={map:p.map,channel:p.channel||0,expires:continuing?approach.expires:now+120000};return {...result(true,'walking to allocated stall'),plan:stall};}
    delete brain.merchantApproach;
    task={version:1,policy:'ENGINE-CHOSEN',phase:'listing',startedAt:now,closesAt:now+policy.dwellMs+(policy.dwellJitterMs?commerceHash(p.account)%policy.dwellJitterMs:0),absenceSince:null,
      map:p.map,channel:p.channel||0,uids:offers.map(o=>o.uid),reason:null};await saveTask(world,p,task);
   }
   const human=presentHuman(world,p,policy),moved=!nativeMap(world,p)||p.map!==task.map||(p.channel||0)!==task.channel;
   if(!human&&task.absenceSince==null)await changed({absenceSince:now});else if(human&&task.absenceSince!=null)await changed({absenceSince:null});
   const reason=cancel?'interrupted':moved?'left native stall scene':now>=task.closesAt?'dwell complete':task.absenceSince!=null&&now-task.absenceSince>=policy.absenceMs?'no nearby human':null;
   if(reason&&task.phase!=='closing')await changed({phase:'closing',reason});
   if(task.phase==='closing'){
    if(p.pcShopOpen){await ordinary({operation:'close'});return result(true,'closing stall');}
    const state=pcshopSnapshot(world,p);
    if(state?.income>0&&(Number(p.profile.dil)||0)+state.income<=PCSHOP_MAX_DIL){await ordinary({operation:'collect'});return result(true,'collecting sales');}
    // Income which cannot fit the native DIL cap stays in the ordinary durable shop ledger.
    await changed({phase:'cooldown',retryAt:now+policy.cooldownMs,finishedAt:now});return result(false,'stall complete');
   }
   const offers=npcMerchantOffers(world,p,{limit:3,onlyUids:new Set(task.uids)}),available=new Map(offers.map(o=>[o.uid,o])),state=pcshopSnapshot(world,p),listed=state?.listings||[];
   // Listings not selected by this task, including bound seed stock left by legacy code, must never open.
   const unsafe=listed.find(l=>!task.uids.includes(l.uid)||!available.has(l.uid)||l.count>available.get(l.uid).count);
   if(unsafe){
    if(p.pcShopOpen){await changed({phase:'closing',reason:'listing eligibility changed'});await ordinary({operation:'close'});return result(true,'closing changed listings');}
    await ordinary({operation:'withdraw',uid:unsafe.uid});return result(true,'removing unrelated listing');
   }
   if(p.pcShopOpen){
    if(task.phase!=='open')await changed({phase:'open'});
    if(!listed.length){await changed({phase:'closing',reason:'sold out'});await ordinary({operation:'close'});return result(true,'sold out');}
    if(state.income>0&&(Number(p.profile.dil)||0)+state.income<=PCSHOP_MAX_DIL){await ordinary({operation:'collect'});return result(true,'collecting partial sale');}
    if(state.income+Math.min(...listed.map(l=>l.price))>PCSHOP_MAX_DIL){await changed({phase:'closing',reason:'native income cap'});await ordinary({operation:'close'});return result(true,'income cap');}
    brain.activity='selling owned drops in Ardeca';return result(true,'holding native stall');
   }
   // Runtime open state is session-only. A restart resumes the existing durable task/deadline.
   const next=task.uids.map(uid=>available.get(uid)).find(o=>o&&!listed.some(l=>l.uid===o.uid));
   if(next){await ordinary({operation:'register',uid:next.uid,count:next.count,price:next.price});return result(true,'listing owned gear');}
   if(!listed.length){await changed({phase:'closing',reason:'no owned stock remains'});return result(true,'finishing empty stall');}
   if(p.sitting){const response=await act(p,{type:'emote',motion:'stand'});if(!response)throw Object.assign(Error('NPC merchant stand was not accepted.'),{status:503});return result(true,'standing for shop');}
   // A durable task can resume at a legacy shared position after restart.
   // Revalidate only CLOSED pre-open seats; never relocate an actually open stall.
   // Keep its original UID selections and deadline; caller uses ordinary movement.
   if(!p.tradeId&&!p.duelId&&p.mount?.phase!=='on'&&!fishingBusy(p)){
    const stall=npcTownStallPlan(world,p);
    if(!stall)return result(true,'waiting for safe stall space');
    if(!stall.near)return {...result(true,'walking to revalidated stall'),plan:stall};
   }
   if(p.path?.length){const response=await act(p,{type:'stop'});if(!response)throw Object.assign(Error('NPC merchant stop was not accepted.'),{status:503});return result(true,'standing for shop');}
   if(p.tradeId||p.duelId||p.mount?.phase==='on'||fishingBusy(p)){await changed({phase:'closing',reason:'actor occupied'});return result(true,'finishing interrupted stall');}
   await ordinary({operation:'open'});if(!p.pcShopOpen)throw Object.assign(Error('NPC merchant stall did not open.'),{status:503});
   await changed({phase:'open'});brain.activity='selling owned drops in Ardeca';return result(true,'opened native stall');
  }catch(error){brain.merchantRetryAt=now+policy.retryMs;brain.merchantError=String(error?.message||'Merchant task failed.');return result(!!task&&task.phase!=='cooldown','blocked');}
 }
}
import {beltEligible} from '../../src/systems/items/belt.js';
import {npcPlacements,offersOriginalJob} from './npc-services.mjs';
import {assertNieteService} from './niete-services.mjs';
// ENGINE-CHOSEN reserve/deadline policy. Native potion effects, requirements, belt
// ownership, shop rows/prices/proximity and durable payment remain ordinary authority.
export const NPC_SUPPLY_POLICY=Object.freeze({lowStock:3,targetStock:10,deadlineMs:60000,cooldownMs:15000,maxSales:10,retryMs:2000});
const supplyFlights=new WeakMap();
const supplyTask=p=>{const t=p.profile?.npcSupply;return t?.version===1&&t.policy==='ENGINE-CHOSEN'&&['walking','cooldown'].includes(t.phase)&&Number.isFinite(t.deadline)?t:null;};
function supplyOwned(world,p,kind){return [...(p.profile.inventory||[]),...(p.profile.potionBelt||[])].reduce((n,i)=>{
 const d=world.data.itemDB.def(i.itemIndex),u=d?.use;return n+(!(i.expiresAt&&i.expiresAt<=world.now())&&beltEligible(d)&&!(d.reqLv>p.profile.level)&&!(d.maxLv&&p.profile.level>d.maxLv)&&((Number(d.classMask)>>>p.profile.classIndex)&1)&&(Number(u?.[kind])>0||Number(u?.[kind+'Pct'])>0)?Number(i.count)||1:0);
 },0);}
function supplyOffer(world,p,{kind,shop,tab,itemIndex,stockX,stockY,npcIndex,at},policy){
 const catalog=world.data.shopData?.shops,store=catalog?.shops?.[shop],page=store?.tabs?.[tab],set=catalog?.sets?.[page?.set];
 const row=set?.items.find(r=>Number(r[0])===itemIndex&&Number(r[2])===stockX&&Number(r[3])===stockY),d=world.data.itemDB.def(itemIndex),u=d?.use;
 if(!row||!d||!beltEligible(d)||!(Number(u?.[kind])>0||Number(u?.[kind+'Pct'])>0)||d.reqLv>p.profile.level||d.maxLv&&p.profile.level>d.maxLv||!((Number(d.classMask)>>>p.profile.classIndex)&1)||d.period||set.costs?.[itemIndex]?.length||store.kind==='ARENA_SHOP'&&d.purchasePoint>0||!(d.price>0))return null;
 const owned=supplyOwned(world,p,kind);if(owned>=policy.lowStock)return null;
 const price=Math.floor(d.price*(page.buyRatio||10)/10),per=Math.max(1,Number(row[1])||1),count=Math.min(policy.maxSales,9999,Math.ceil((policy.targetStock-owned)/per),Math.floor((Number(p.profile.dil)||0)/price));
 if(!Number.isSafeInteger(price)||price<1||count<1)return null;
 return {kind,npcIndex,at,shop,tab,itemIndex,stockX,stockY,price,saleQuantity:per,count,owned,
  near:dist(p,at)<=12,action:{type:'shopbuy',npcIndex,shop,tab,itemIndex,stockX,stockY,count},
  provenance:'actual current-map native NPC job/stock row and owned DIL',policy:'ENGINE-CHOSEN reserve and selection'};
}
/** Pure stable destination and exact native purchase intent. Counts both bag AND owned potion belt. */
export function npcSupplyPlan(world,p,{policy=NPC_SUPPLY_POLICY}={}){
 if(!ownNpc(p)||!world.data.itemDB||p.dead||p.leaving||p.instanceId||p.pcShopOpen)return null;
 if(Number(p.profile.life?.grade?.chaotic)>0)return null;
 const saved=supplyTask(p);if(saved?.phase==='cooldown'&&world.now()<(saved.retryAt||0))return null;
 const catalog=world.data.shopData?.shops;if(!catalog)return null;
 const kinds=['hp','mp'].filter(k=>supplyOwned(world,p,k)<policy.lowStock);
 const candidates=[];
 for(const placed of npcPlacements(world,p.map))for(const job of catalog.npcs?.[placed.npcIndex]?.jobs||[]){
  const type=Number(job.jobType),shop=Number(job.shop??job.jobIndex),store=catalog.shops?.[shop];if(![0,33,43,51,83,102].includes(type)||!store||!offersOriginalJob(world,placed,type,shop))continue;
  const authored=catalog.npcs[placed.npcIndex].at?.find(([map])=>Number(map)===p.map);
  if(!placed.custom&&!authored)continue;const at={map:p.map,x:placed.custom?placed.x:Number(authored[1]),z:placed.custom?placed.z:Number(authored[2])};
  store.tabs.forEach((page,tab)=>{for(const row of catalog.sets[page.set]?.items||[])for(const kind of kinds){const option=supplyOffer(world,p,{kind,shop,tab,itemIndex:Number(row[0]),stockX:Number(row[2]),stockY:Number(row[3]),npcIndex:placed.npcIndex,at},policy);if(option)candidates.push(option);}});
 }
 // Choose native potency the actor can actually afford; prefer missing HP, then MP,
 // then stronger native recovery, then closest NPC. This is a strategy, not Global pricing.
 const reachable=new Map();return candidates.filter(option=>{const key=option.npcIndex+':'+option.at.x+':'+option.at.z;if(!reachable.has(key))reachable.set(key,!!npcReachableApproach(mapFor(world,p),p,option.at,12));return reachable.get(key);}).sort((a,b)=>kinds.indexOf(a.kind)-kinds.indexOf(b.kind)||Number(world.data.itemDB.def(b.itemIndex).use[b.kind]||0)-Number(world.data.itemDB.def(a.itemIndex).use[a.kind]||0)||dist(p,a.at)-dist(p,b.at)||a.itemIndex-b.itemIndex)[0]||null;
}
/** Return `plan.at` to root's ordinary movement adapter while handled=true. The
 * stored target is retained until purchase, explicit cancel, scene change or deadline.
 */
export async function npcSupplyStep({world,player:p,brain={},act=(player,input)=>world.action(player.account,{...input,token:player.token}),approachPlan,requested=false,cancel=false,policy=NPC_SUPPLY_POLICY}){
 if(!ownNpc(p)||world.players.get(p.account)!==p||p.leaving||p.dead)return {handled:false,status:'unavailable',plan:null};
 if(supplyFlights.has(p))return supplyFlights.get(p);const operation=advance();supplyFlights.set(p,operation);
 try{return await operation;}finally{if(supplyFlights.get(p)===operation)supplyFlights.delete(p);}
 async function advance(){let task=supplyTask(p);const now=world.now(),answer=(handled,status,plan=null)=>({handled,status,plan,task:task?structuredClone(task):null});
  const save=async t=>{await serializeLife(p,async()=>{const profile=structuredClone(p.profile);profile.npcSupply=structuredClone(t);await commitLife(world,p,profile);});task=t;};
  const finish=async reason=>{await save({...task,phase:'cooldown',reason,finishedAt:now,retryAt:now+policy.cooldownMs});return answer(false,reason);};
  try{
   if(p.pcShopOpen||p.sceneTransition||p.commandActive||p.tradeCommitting||p.progressCommitting)return answer(!!task&&task.phase==='walking','busy');
   if(now<(brain.supplyRetryAt||0))return answer(!!task&&task.phase==='walking','retry');
   if(task?.phase==='cooldown'){if(now<task.retryAt||!requested)return answer(false,'cooldown');task=null;}
   if(!task){if(!requested||cancel)return answer(false,'not seeking supplies');const plan=npcSupplyPlan(world,p,{policy});if(!plan){brain.supplyRetryAt=now+policy.cooldownMs;return answer(false,'no affordable native supply');}task={version:1,policy:'ENGINE-CHOSEN',phase:'walking',startedAt:now,deadline:now+policy.deadlineMs,map:p.map,channel:p.channel||0,offer:plan};await save(task);}
   if(cancel)return finish('interrupted');if(p.map!==task.map||(p.channel||0)!==task.channel||p.instanceId)return finish('left supply scene');if(now>=task.deadline)return finish('supply deadline');
   try{assertNieteService(world,p);}catch{return finish('NPC store unavailable');}
   // The saved destination/row stays fixed. Live money, owned stock and native offer are rechecked at arrival.
   let plan=supplyOffer(world,p,task.offer,policy);if(!plan)return finish('supplies no longer needed or affordable');
   if(approachPlan){plan=approachPlan({world,player:p,plan});if(!plan)return answer(true,'waiting for a free native store approach');if(!plan.near){brain.activity='walking to buy native potions';return answer(true,'walking to native store',plan);}}
   else{const approach=npcReachableApproach(mapFor(world,p),p,plan.at,12);if(!approach)return finish('native supply store is unreachable');if(!plan.near){brain.activity='walking to buy native potions';return answer(true,'walking to native store',{...plan,at:{...plan.at,...approach}});}}
   const response=await act(p,plan.action);if(!response)throw Object.assign(Error('NPC supply purchase was not accepted.'),{status:503});
   const done=await finish('bought native supplies');brain.activity='bought native potions with owned DIL';return {...done,handled:true,plan};
  }catch(error){brain.supplyRetryAt=now+policy.retryMs;brain.supplyError=String(error?.message||'Supply objective failed.');return answer(!!task&&task.phase==='walking','blocked');}
 }
}

