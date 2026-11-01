import {randomUUID} from 'node:crypto';
import {sameScene} from './scene.mjs';
import {socialRef} from './social-state.mjs';
import {tradeSnapshot} from './trade.mjs';
import {serializeLife,commitLife} from './life-transactions.mjs';
import {npcMerchantOffers} from './npc-merchant.mjs';
import {protectedNpcEquipmentUids} from './npc-equipment-ownership.mjs';
import {npcEquipmentBenefit} from './npc-builds.mjs';
import {commerceHash} from './npc-commerce-value.mjs';

// ENGINE-CHOSEN generosity, quality preference and rarity; never Global prices,
// native rewards, perfect-item claims or permission to grant resources.
export const NPC_GENEROSITY_POLICY=Object.freeze({initialDelayMs:600000,opportunityMs:43200000,chanceModulo:16,cooldownMs:86400000,waitMs:120000,wealthDil:100000000,dilPercent:5,maxDil:25000000,minDil:1000000});
const flights=new WeakMap(),own=p=>p?.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile.authority==='server';
const human=p=>p&&p.npcPlayer!==true&&p.profile?.npcPlayer!==true;
const live=(world,p)=>p&&world.players.get(p.account)===p&&!p.leaving&&!p.dead&&!p.sceneTransition;
const dist=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
const receipt=p=>{const t=p.profile.npcGift;return t?.version===1&&t.policy==='ENGINE-CHOSEN'&&typeof t.id==='string'&&Number.isFinite(t.nextAt)?t:null;};
const fingerprint=item=>JSON.stringify(item);
const wear=p=>new Set(Object.values(p.profile.equip?.presets||{}).flatMap(preset=>Object.values(preset||{})).filter(Boolean));
function spare(world,p,item){return !!item&&!wear(p).has(item.uid)&&!protectedNpcEquipmentUids(world,p).has(item.uid)&&!(p.profile.pcShop?.listings||[]).some(i=>i.uid===item.uid)&&npcMerchantOffers(world,p,{limit:3}).some(o=>o.uid===item.uid);}
function idle(world,p,b){const task=b.taskGoal||p.profile.npcRoutine;return live(world,p)&&!p.instanceId&&!p.duelId&&!p.pcShopOpen&&!(p.profile.pcShop?.listings||[]).length&&!p.tradeId&&!p.tradeCommitting&&!p.path?.length&&!p.commandActive&&!p.attackTarget&&!p._skills?.engine.casting&&!b.follow&&!b.lure&&!b.questId&&!b.refineUid&&!(b.prepareUntil>world.now())&&!Object.keys(p.profile.quests?.active||{}).length&&p.profile.npcEquipment?.phase!=='working'&&(!task||task.until<=world.now()||task.kind==='rest')&&!(p.pvpLastHit&&world.now()-p.pvpLastHit.at<10000);}
export function npcGenerous(profile){const t=profile.npcTraits||{};return t.social==='social'&&t.generous!==false&&(t.generous===true||['relaxed','playful','funny'].includes(t.chat)&&commerceHash(profile.id||profile.name)%4===0);}
function giftDil(world,p,policy){const funds=p.profile.dil,reserve=Math.max(Number(world.data.guild?.config?.MONEY)||0,Number(world.data.guild?.config?.DILTOCON)||0);if(!Number.isSafeInteger(funds)||funds<policy.wealthDil)return 0;const gift=Math.min(policy.maxDil,Math.floor(funds*policy.dilPercent/100),funds-reserve);return Number.isSafeInteger(gift)&&gift>=policy.minDil?gift:0;}

/** Actual owned spare gear with native eligible benefit for the real recipient.
 * Modest/strong quality gate is a declared preference, not a market appraisal. */
export function npcGenerosityPlan(world,p,b={},options={}){
 const policy=options.policy||NPC_GENEROSITY_POLICY,isHuman=options.isHuman||human,now=world.now(),saved=receipt(p);
 if(!own(p)||!npcGenerous(p.profile)||!idle(world,p,b)||saved&&now<saved.nextAt)return null;
 if(commerceHash((p.characterId||p.profile.id)+':'+Math.floor(now/policy.opportunityMs))%policy.chanceModulo!==0)return null;
 const people=[...world.players.values()].filter(q=>q!==p&&isHuman(q)&&live(world,q)&&!q.instanceId&&!q.tradeId&&!q.pcShopOpen&&!q.attackTarget&&!q._skills?.engine.casting&&sameScene(p,q)&&dist(p,q)<=12).sort((a,c)=>dist(p,a)-dist(p,c)||String(a.id).localeCompare(String(c.id)));
 const db=world.data.itemDB;if(!db||!people.length)return null;
 const candidates=[];
 for(const other of people)for(const offer of npcMerchantOffers(world,p,{limit:3})){const item=p.profile.inventory.find(i=>i.uid===offer.uid),d=db.def(item.itemIndex);if(!spare(world,p,item)||!(Number(d.itemLv)>=6||Number(d.rank)>0||Number(d.reqLv)>=100))continue;const benefit=npcEquipmentBenefit(world,other,item);if(!benefit?.benefit||benefit.benefit<=0)continue;candidates.push({other,item,benefit:benefit.benefit});}
 candidates.sort((a,c)=>c.benefit-a.benefit||dist(p,a.other)-dist(p,c.other)||a.item.uid.localeCompare(c.item.uid));
 const chosen=candidates[0];if(chosen)return {targetId:chosen.other.id,targetRef:socialRef(chosen.other),items:[{uid:chosen.item.uid,count:1}],fingerprints:{[chosen.item.uid]:fingerprint(chosen.item)},dil:0,text:`I have a spare {item:${chosen.item.uid}}. You can have it if you want; review the trade.`,topic:'gift',policy:'ENGINE-CHOSEN'};
 const dil=giftDil(world,p,policy);return dil?{targetId:people[0].id,targetRef:socialRef(people[0]),items:[],fingerprints:{},dil,text:`I can spare ${dil} DIL. You can have it if you want; review the trade.`,topic:'gift',policy:'ENGINE-CHOSEN'}:null;
}
async function save(world,p,task){await serializeLife(p,async()=>{const profile=structuredClone(p.profile);profile.npcGift=structuredClone(task);await commitLife(world,p,profile);});}
function exact(world,p,other,t){return live(world,p)&&live(world,other)&&human(other)&&sameScene(p,other)&&dist(p,other)<=12&&socialRef(other)===t.targetRef&&!p.pcShopOpen&&!p.instanceId&&p.profile.npcEquipment?.phase!=='working'&&Number.isSafeInteger(t.dil)&&t.dil>=0&&t.dil<=(p.profile.dil||0)&&(!t.dil||t.dil<=giftDil(world,p,NPC_GENEROSITY_POLICY))&&Array.isArray(t.items)&&t.items.every(row=>{const item=p.profile.inventory?.find(i=>i.uid===row.uid);return row.count===1&&item&&fingerprint(item)===t.fingerprints[row.uid]&&spare(world,p,item);});}
const rows=trade=>trade.self.items.map(i=>({uid:i.uid,count:i.count}));

/** Only the exact persisted outgoing gift bypasses normal barter assessment.
 * Native revision, fingerprints, human accept/confirm and atomic trade remain. */
export async function npcOutgoingGiftStep({world,player:p,act,trade=tradeSnapshot(world,p)}){
 let t=receipt(p);if(!t||!['invited','offered','confirming'].includes(t.phase)||!trade||trade.id!==t.tradeId)return null;
 const other=[...world.players.values()].find(q=>q.id===trade.partner.id),cancel=async reason=>{await act(p,{type:'trade',operation:'cancel',id:trade.id});await save(world,p,{...t,phase:'cancelled',reason});return {handled:true,status:'gift '+reason};};
 if(trade.incoming||!exact(world,p,other,t)||world.now()>=t.expiresAt)return cancel('changed or unavailable');
 if(trade.other.items.length||trade.other.dil)return cancel('recipient offered payment');
 if(trade.phase==='invited')return {handled:true,status:'waiting for human gift acceptance'};
 const exactOffer=JSON.stringify(rows(trade))===JSON.stringify(t.items)&&trade.self.dil===t.dil;
 if(!exactOffer){if(t.phase==='confirming')return cancel('confirmed offer changed');await act(p,{type:'trade',operation:'offer',id:trade.id,revision:trade.revision,items:t.items,dil:t.dil});await save(world,p,{...t,phase:'offered'});return {handled:true,status:'offered owned gift'};}
 if(!trade.other.confirmed)return {handled:true,status:'waiting for human gift confirmation'};
 const operation=trade.phase==='open'&&!trade.self.confirmed?'confirm':trade.phase==='ready'&&trade.other.finalConfirmed&&!trade.self.finalConfirmed?'finalConfirm':null;
 if(!operation)return {handled:true,status:'gift confirmation pending'};
 // Durable receipt BEFORE confirmation travels inside the ordinary atomic
 // exchange. Ambiguous saves/restarts never initiate this gift a second time.
 t={...t,phase:'confirming',confirmedRevision:trade.revision};await save(world,p,t);
 const current=tradeSnapshot(world,p);if(!current||current.id!==t.tradeId||current.revision!==trade.revision||!current.other.confirmed||operation==='finalConfirm'&&(current.phase!=='ready'||!current.other.finalConfirmed)||current.other.items.length||current.other.dil||!exact(world,p,other,t))return {handled:true,status:'gift revision changed before confirmation'};
 await act(p,{type:'trade',operation,id:current.id,revision:current.revision});
 if(!tradeSnapshot(world,p))await save(world,p,{...t,phase:'settled',settledAt:world.now()});
 return {handled:true,status:'confirmed owned gift'};
}

export async function npcGenerosityStep({world,player:p,brain={},act=(player,input)=>world.action(player.account,{...input,token:player.token}),requested=true,...options}){
 if(!own(p)||!live(world,p))return {handled:false,status:'unavailable'};if(flights.has(p))return flights.get(p);const operation=advance();flights.set(p,operation);try{return await operation;}finally{if(flights.get(p)===operation)flights.delete(p);}
 async function advance(){let t=receipt(p);const trade=tradeSnapshot(world,p);
 if(trade){const result=await npcOutgoingGiftStep({world,player:p,act,trade});return result||{handled:false,status:'ordinary trade'};}
 if(t&&['prepared','invited','offered','confirming'].includes(t.phase)){await save(world,p,{...t,phase:'closed',closedAt:world.now()});return {handled:false,status:'closed old gift intent'};}
 const policy=options.policy||NPC_GENEROSITY_POLICY,now=world.now();if(!requested)return {handled:false,status:'not requested'};
 if(!brain.giftReadyAt){brain.giftReadyAt=now+policy.initialDelayMs;if(policy.initialDelayMs)return {handled:false,status:'initial gift delay'};}
 if(now<brain.giftReadyAt)return {handled:false,status:'gift delay'};
 const plan=npcGenerosityPlan(world,p,brain,{...options,policy});if(!plan){brain.giftReadyAt=now+60000;return {handled:false,status:'no eligible gift'};}
 t={version:1,policy:'ENGINE-CHOSEN',id:randomUUID(),phase:'prepared',targetRef:plan.targetRef,items:plan.items,fingerprints:plan.fingerprints,dil:plan.dil,expiresAt:now+policy.waitMs,nextAt:now+policy.cooldownMs};
 await save(world,p,t);
 const other=[...world.players.values()].find(q=>q.id===plan.targetId);if(!exact(world,p,other,t)||p.tradeId||other.tradeId)return {handled:false,status:'gift target changed'};
 try{await act(p,{type:'trade',operation:'request',targetId:other.id});const invited=tradeSnapshot(world,p);if(!invited||invited.incoming||invited.partner.id!==other.id)throw Error('Ordinary gift invitation unavailable');await save(world,p,{...t,phase:'invited',tradeId:invited.id});return {handled:true,status:'gift invitation sent',text:plan.text,topic:plan.topic};}
 catch(error){if(p.tradeId){const current=tradeSnapshot(world,p);if(current?.partner.id===other.id&&!current.incoming)await act(p,{type:'trade',operation:'cancel',id:current.id}).catch(()=>{});}if(!error.status)throw error;return {handled:false,status:'gift invitation refused',reason:error.message};}
 }
}
