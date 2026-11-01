// Server-authoritative Consignment / Agency (Middleman JobType 46, store/ui_storeconsignment_2 + ui_new_storesearch_2 +
// ui_receiptwnd_2). Listings, escrowed items and seller receipts live in the durable social state (state.consign), so a
// buyer, a cancel, an expiry and a receipt commit atomically with the acting character's bag and DIL through
// socialTransaction (one CAS write of users + social). An offline seller's profile is never written: sales wait in
// the seller's receipts until the seller receives them.
// Rules and their sources (share/formula.ini unless noted):
//   deposit   i64AuctionRegCost 1000000 (help text 2009:104 "[ 1,000,000 DIL ] deposit")
//   fee       fConsignmentCommissionRatio 5.0 % of the sale (registration window 2010:17 "Fee (<COUNT>%)"), kept from the sales
//   period    byAuctionRegDay 7 days, then the item waits in the receipts (2010:72 "Registered Sales have expired")
//   max       nAuctionMaxRegItem 5 registrations (the class "Consignment Shop" mastery: "Up to 5 items", 2010:67)
//   skill     the class Consignment Shop mastery is required to register (2010:71; gamedata/shops_search.json consignmentSkills)
//   deposit refund (2009:104): sold -> with the sales; expired -> on item retrieval; seller cancels -> no refund (2010:69)
//   receipts  sold-DIL receipts are deleted after 15 days (2010:34); expired items stay until received
// Not in the data (documented, not invented): what nAuctionDelaySec 30 delays; a buyer-side tax (buyconfirm shows a Tax row
// but no buyer rate exists, so the buyer pays the listed price); a separate unit-price cap (the total is capped at the
// 10 000 000 000 DIL balance limit).
import fs from 'node:fs/promises';
import path from 'node:path';
import {randomUUID} from 'node:crypto';
import {recordRenewBrokerage} from '../../src/game/siege-renew-tax-rules.js';
import {siegeRenewConfig} from '../../src/game/siege-renew-rules.js';
import {decodeText} from '../../src/formats/binreader.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {nearbyNpc} from './npc-services.mjs';
import {premiumHas} from './premium-service.mjs';
import {socialError as fail,socialRef,socialIntent,socialTransaction,socialLive} from './social-state.mjs';
import {progressDekaPass} from './dekapass.mjs';

export const CONSIGN_SCHEMAS={consign:['token','type','operation','revision','requestId','uid','count','unit','id','all']};
const MAX_DIL=10_000_000_000,DAY=86_400_000,RECEIPT_DAYS=15,MIDDLEMAN_JOB=46;

/** Read the consignment keys of share/formula.ini and the class mastery skills; a missing key leaves the service off. */
export async function loadConsignmentPolicy(dataRoot,gamedataRoot){
  let ini='',skills={};
  try{ini=decodeText(await fs.readFile(path.join(dataRoot,'share/formula.ini')));}catch{return null;}
  try{skills=JSON.parse(await fs.readFile(path.join(gamedataRoot,'shops_search.json'),'utf8')).consignmentSkills||{};}catch{skills={};}
  return consignmentPolicyFromIni(ini,skills);
}
export function consignmentPolicyFromIni(text,skills={}){
  const keys={};
  for(const line of String(text).split(/\r?\n/)){const m=/^\s*([A-Za-z0-9_]+)\s*,\s*([-0-9.]+)/.exec(line);if(m)keys[m[1]]=Number(m[2]);}
  const need=['i64AuctionRegCost','fConsignmentCommissionRatio','byAuctionRegDay','nAuctionMaxRegItem'];
  if(need.some(k=>!Number.isFinite(keys[k])))return null;
  return {deposit:keys.i64AuctionRegCost,fee:keys.fConsignmentCommissionRatio,days:keys.byAuctionRegDay,max:keys.nAuctionMaxRegItem,
    receiptDays:RECEIPT_DAYS,skills:Object.values(skills).map(Number).filter(Number.isInteger)};
}
const policyOf=world=>world.data.consignment||null;
const market=state=>(state.consign||={listings:[],receipts:{}});
const salesOf=(policy,gross)=>Math.floor(gross*(100-policy.fee)/100);

/** Move expired listings into their seller's receipts and drop sold receipts past the storage period (on a clone). */
export function sweepConsignment(state,policy,now){
  const m=market(state);
  for(const l of m.listings.filter(l=>now>=l.expires)){
    (m.receipts[l.sellerRef]||=[]).push({id:l.id,kind:'expired',itemIndex:l.itemIndex,count:l.count,sales:0,deposit:l.deposit,at:l.expires,item:l.item});
  }
  m.listings=m.listings.filter(l=>now<l.expires);
  for(const [ref,list] of Object.entries(m.receipts)){
    const kept=list.filter(r=>r.kind!=='sold'||now-r.at<policy.receiptDays*DAY);
    if(kept.length)m.receipts[ref]=kept;else delete m.receipts[ref];
  }
  return m;
}
const publicItem=item=>{const out=structuredClone(item||{});for(const k of ['uid','page','x','y'])delete out[k];return out;};
const listingRow=(l,ref)=>({id:l.id,itemIndex:l.itemIndex,count:l.count,unit:l.unit,sellerName:l.sellerName,listedAt:l.listedAt,expires:l.expires,mine:l.sellerRef===ref,item:publicItem(l.item)});
/** Private per-character view (the event stream): own listings, own receipts, the policy. Read-only. */
export function consignmentSnapshot(world,p){
  const policy=policyOf(world),state=world.socialState;
  if(!policy||!state)return {available:false,revision:state?.revision||0,listings:[],receipts:[]};
  const view=sweepConsignment(structuredClone({consign:state.consign||{listings:[],receipts:{}}}),policy,world.now()),ref=socialRef(p);
  return {available:true,revision:state.revision,policy:{deposit:policy.deposit,fee:policy.fee,days:policy.days,max:policy.max,receiptDays:policy.receiptDays},
    listings:view.listings.filter(l=>l.sellerRef===ref).map(l=>listingRow(l,ref)),
    receipts:(view.receipts[ref]||[]).map(({item,...r})=>({...r,item:publicItem(item)}))};
}
function access(world,p){
  if(!nearbyNpc(world,p,{jobType:MIDDLEMAN_JOB})&&!premiumHas(world,p.profile,'brokerage'))fail('Use a nearby Middleman (or the Almighty Agency service).',403);
}
function learned(profile,policy){
  return policy.skills.some(id=>{const v=profile.skills?.[id];return Number(typeof v==='object'?v?.level:v)>0;});
}
function amount(value,label){if(!Number.isSafeInteger(value)||value<1)fail(`Invalid ${label}.`);return value;}
export async function consignCommand(world,p,input){
  const policy=policyOf(world);
  if(!policy)fail('The original consignment rules (formula.ini) are unavailable.',503);
  if(!world.data.itemDB)fail('Consignment requires the original item catalog.',503);
  if(input.operation==='list'){
    socialLive(world,p);access(world,p);
    if(Object.keys(input).some(k=>!['token','type','operation'].includes(k)))fail('Send the search intent only.');
    const state=world.socialState;if(!state)fail('Durable social storage is unavailable.',503);
    const ref=socialRef(p),now=world.now();
    return {revision:state.revision,listings:(state.consign?.listings||[]).filter(l=>now<l.expires).slice(0,1000).map(l=>listingRow(l,ref))};
  }
  socialIntent(input,{register:['uid','count','unit'],cancel:['id'],buy:['id','count'],receive:['id','all']});
  return socialTransaction(world,p,input,async(state,profile,ref)=>{
    access(world,p);
    const now=world.now(),m=sweepConsignment(state,policy,now);
    const inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random}),bag=inv.bag;
    if(input.operation==='register'){
      if(!learned(profile,policy))fail('Consignment Skill is required.',403);
      if(m.listings.filter(l=>l.sellerRef===ref).length>=policy.max)fail('User has exceeded the maximum number of registrations');
      if(typeof input.uid!=='string')fail('Choose one owned bag item.');
      const count=amount(input.count,'quantity'),unit=amount(input.unit,'unit price');
      if(!Number.isSafeInteger(unit*count)||unit*count>MAX_DIL)fail('The desired amount has exceeded the limit.');
      const source=bag.byUid(input.uid),def=source&&world.data.itemDB.def(source.itemIndex);
      if(!def)fail('There are no item(s).');
      if(source.bound||Number(def.trade)===0)fail('Binded Items cannot be registered');
      if(source.expiresAt||Number(def.period)>0)fail('Periodical/Timed Items cannot be registered');
      if(source.pet?.active||source.pet?.inv?.length)fail('This item cannot be registered');
      if(count>(source.count||1))fail('That item quantity is unavailable.');
      if(!Number.isSafeInteger(profile.dil)||profile.dil<policy.deposit)fail('Insufficient Deposit');
      const item=bag.take(source,count);for(const k of ['page','x','y'])delete item[k];
      profile.dil-=policy.deposit;
      const id=randomUUID();
      m.listings.push({id,sellerRef:ref,sellerName:profile.name,itemIndex:item.itemIndex,count,unit,deposit:policy.deposit,listedAt:now,expires:now+policy.days*DAY,item});
      return {registered:id};
    }
    if(input.operation==='cancel'){
      if(typeof input.id!=='string')fail('Choose one of your registrations.');
      const l=m.listings.find(x=>x.id===input.id&&x.sellerRef===ref);if(!l)fail('That registration is unavailable.',404);
      if(bag.byUid(l.item.uid))fail('That item identity already exists.',409);
      if(!bag.add(structuredClone(l.item)).ok)fail('Insufficient inventory space');
      m.listings=m.listings.filter(x=>x!==l);   // the deposit is not refunded (2009:104, 2010:69)
      return {cancelled:l.id};
    }
    if(input.operation==='buy'){
      if(typeof input.id!=='string')fail('Choose a listed item.');
      const l=m.listings.find(x=>x.id===input.id);if(!l)fail('Seller has cancelled the sale.',404);
      if(l.sellerRef===ref)fail('Item selected is your registered item.');
      const count=amount(input.count,'quantity');if(count>l.count)fail('Seller does not have any items for sale.');
      const cost=l.unit*count;
      if(!Number.isSafeInteger(profile.dil)||profile.dil<cost)fail('You do not have enough DIL.');
      const piece=count===l.count?structuredClone(l.item):{...structuredClone(l.item),uid:randomUUID(),count};
      for(const k of ['page','x','y'])delete piece[k];
      if(bag.byUid(piece.uid))fail('That item identity already exists.',409);
      if(!bag.add(piece).ok)fail('Not enough space in the inventory.');
      profile.dil-=cost;
      const left=l.count-count,receipt={id:randomUUID(),kind:'sold',itemIndex:l.itemIndex,count,sales:salesOf(policy,cost),deposit:left?0:l.deposit,at:now};
      (m.receipts[l.sellerRef]||=[]).push(receipt);
      // User-approved literal native tax allocation: 40% of this commission per
      // castle. Ledger is atomic with the sale; buyer/seller prices do not change.
      const renew=(world.data.eventData?.ev||world.data.eventData)?.modes?.siegeRenew;
      if(renew)recordRenewBrokerage(state,now,siegeRenewConfig(renew),cost-receipt.sales);
      if(left){l.count=left;l.item.count=left;}else m.listings=m.listings.filter(x=>x!==l);
      // DekaPass ITEM 5 / BUY 33 season 32 "Purchase Items from Agency" (3202:32): one per purchase, staged on this transaction's profile.
      progressDekaPass({...world,changed(){}},{...p,profile},5,33,l.itemIndex,1);
      return {bought:l.id,count,cost};
    }
    // receive: one receipt, or all of them (btn_receivepage)
    const mine=m.receipts[ref]||[];
    if(input.all!==undefined&&input.all!==true)fail('Choose one receipt or all.');
    if(input.all!==true&&typeof input.id!=='string')fail('Choose one receipt.');
    const chosen=input.all===true?mine.slice():mine.filter(r=>r.id===input.id);
    if(!chosen.length)fail('There are no completed sales to be received',404);
    let received=0;
    for(const r of chosen){
      if(r.kind==='expired'){
        if(bag.byUid(r.item?.uid))fail('That item identity already exists.',409);
        if(!bag.add(structuredClone(r.item)).ok){if(input.all===true)break;fail('Insufficient inventory space');}
      }
      const balance=(profile.dil||0)+(r.sales||0)+(r.deposit||0);
      if(!Number.isSafeInteger(balance)||balance>MAX_DIL)fail('Your DIL balance would exceed its limit.');
      profile.dil=balance;received++;
      m.receipts[ref]=m.receipts[ref].filter(x=>x!==r);
    }
    if(!m.receipts[ref]?.length)delete m.receipts[ref];
    if(!received)fail('Insufficient inventory space');
    return {received};
  });
}
