import fs from 'node:fs/promises';
import path from 'node:path';
import { randomUUID } from 'node:crypto';
import { createItem } from '../../src/systems/items/model.js';
import { AuthoritativeInventory, inventoryDestination, receiveAt } from './inventory.mjs';
import {isCustomScene,nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import { withWingShop } from '../../src/content/wing-items.js';
import { withNativeWingShop, nativeWingPurchasePrice } from '../../src/content/native-wing-shop.js';
import { purchasePasswordRequired, checkPurchasePassword, PURCHASE_PASSWORD_TEXT } from '../../src/systems/shops/shop-windows-rules.js';
import { COIN_SHOP_ACTION_SCHEMAS, coinShopAction } from './coin-shops.mjs';
import { recordSiegeTax } from './siege.mjs';
import { premiumStoreShop,checkPremiumItem,startPremium } from './premium-service.mjs';
import {almightyOf} from '../../src/systems/shops/premium-rules.js';
import {assertNieteService} from './niete-services.mjs';
import {GIFT_ACTION_SCHEMAS,giftCommand} from './dshop-gifts.mjs';
import {EXCHANGE_ACTION_SCHEMAS,exchangeAction} from './exchanges.mjs';
import {canNpcSell} from './item-flags.mjs';
import { dshopCurrencyKey, dshopVariantPrice, dshopPurchaseUnits, dshopPurchasePeriod, cashInventoryCanAccept, DSHOP_CART_MAX } from '../../src/systems/shops/dshop-rules.js';

const NPC_SHOP_RANGE=6.2;
// Guide stringtable_helper Shop Trade (Repurchase): Max 10; oldest dropped from top. UI grid 10x8 is layout only.
const SHOP_REBUY_MAX=10;
/** Session reset: guide Caution — close client / character select clears repurchase list. */
export function clearShopRebuy(profile){if(profile&&Array.isArray(profile.shopRebuy)&&profile.shopRebuy.length)profile.shopRebuy=[];}

export const SHOP_ACTION_SCHEMAS = {
  shopbuy: ['token','type','npcIndex','shop','tab','itemIndex','stockX','stockY','count'],
  shopsell: ['token','type','npcIndex','shop','uid'],
  shoprebuy: ['token','type','npcIndex','shop','receipt'],
  dshopbuy: ['token','type','cart','vip','password'],
  cashclaim: ['token','type','uid','page','x','y'],
  ...COIN_SHOP_ACTION_SCHEMAS,   // COIN-SHOPS: job 164 / 165 windows (server/world/coin-shops.mjs)
  ...GIFT_ACTION_SCHEMAS,        // D-Shop Send as Gift / accept into the Cash Inventory (server/world/dshop-gifts.mjs)
  ...EXCHANGE_ACTION_SCHEMAS,
};
export async function loadWorldShopData(gamedataRoot) {
  const [shops,dshop] = await Promise.all(['shops.json','dshop.json'].map(name=>fs.readFile(path.join(gamedataRoot,name),'utf8').then(JSON.parse)));
  const [core,looks,visual,mounts]=await Promise.all(['items.json','items-looks.json','items-visual.json','mounts.json'].map(name=>fs.readFile(path.join(gamedataRoot,name),'utf8').then(JSON.parse)));
  return { shops, dshop: withNativeWingShop(withWingShop(dshop),{core,looks,visual,mounts}) };
}
function fail(message,status=400){throw Object.assign(new Error(message),{status});}
function integer(value,min=0,max=100000){if(!Number.isInteger(value)||value<min||value>max)fail('Invalid purchase quantity or index.');return value;}
// Catalog identifiers are not quantities: original cash item 1171289 exceeds the stack/count bound.
function catalogIndex(value){return integer(value,0,Number.MAX_SAFE_INTEGER);}
function nearShop(world,p,input) {
  const data=world.data.shopData||world.data;
  const shop=data.shops?.shops?.[input.shop], npc=data.shops?.npcs?.[input.npcIndex];
  if(!shop||!npc||!npc.jobs?.some(j=>Number(j.shop??j.jobIndex)===input.shop&&[0,33,43,51,83,102].includes(Number(j.jobType))))fail('This NPC does not offer that shop.');
  if(isCustomScene(world,p.map)){
    const placed=nearbyNpc(world,p,{npcIndex:input.npcIndex,radius:NPC_SHOP_RANGE});
    if(!placed||!npc.jobs.some(j=>Number(j.shop??j.jobIndex)===input.shop&&[0,33,43,51,83,102].includes(Number(j.jobType))&&offersOriginalJob(world,placed,j.jobType,input.shop)))fail('Walk near an NPC offering this original shop.',403);
  }else if(!npc.at?.some(([map,x,z])=>Number(map)===p.map&&Math.hypot(p.x-x,p.z-z)<=NPC_SHOP_RANGE))fail('Walk near the shop NPC before trading.',403);
  return {shop,data};
}
function remoteShop(world,input){
  const data=world.data.shopData||world.data,shop=data.shops?.shops?.[input.shop];
  if(!shop)fail('This shop is unavailable.');
  return {shop,data};
}
// SHOP-WINDOWS: every D-Shop / VIP order asks for the account password (cashshop/ui_buypasswordwnd.txt, rule in
// src/systems/shops/shop-windows-rules.js); checked against the account store BEFORE anything is staged, so a missing or wrong
// password changes nothing (171:30 'Your order has been cancelled.'). Worlds built without an account store (unit fixtures) and
// the owner-launcher account have no password to check.
async function purchasePassword(world,p,password){
  if(typeof world.verifyAccountPassword!=='function'||!purchasePasswordRequired(p.account))return;
  const checked=checkPurchasePassword(password);
  if(checked.error==='enter')fail(PURCHASE_PASSWORD_TEXT.enter);
  if(checked.error||await world.verifyAccountPassword(p.account,checked.password)!==true)fail(PURCHASE_PASSWORD_TEXT.wrong,403);
}
function cost(profile,key,amount){if(!Number.isSafeInteger(amount)||amount<0)fail('Invalid catalog price.');if((Number(profile[key])||0)<amount)fail(key==='dil'?'You do not have enough dil.':`Not enough ${key==='dil'?'DIL':key==='dkc'?'DKC':'points'}.`);profile[key]=(Number(profile[key])||0)-amount;}
function salePrice(def,inst,shop,data) {
  if(!canNpcSell(def,inst))fail(Number(def?.period)>0||inst?.expiresAt?'Limited-Time items cannot be sold to shops.':'Cannot sell items.'); // Global 340:8 / 340:9
  const sockets=Math.min(4,(inst.sockets||[]).filter(Boolean).length), grade=String(inst.grade||'normal').toUpperCase();
  const gradeKey=grade==='NOBLE'?'NORBLE':grade==='MAGIC'?(inst.rnd?.length>=2?'MAGIC2':'MAGIC1'):grade;
  const pct=data.shops.sellPriceTable?.[sockets]?.[gradeKey]??100;
  const unit=def.sell>0?def.sell:Math.floor((def.price||0)*(shop.sellRatio||3)/10*pct/100);
  const price=Math.min(unit*(inst.count||1),shop.maxSellCost||500000);
  if(!Number.isSafeInteger(price)||price<=0)fail('This item has no sell price.');return price;
}
export async function dispatchShopAction(world,p,input) {
  if(!Object.hasOwn(SHOP_ACTION_SCHEMAS,input.type))return false;
  if(input.type==='exchangebuy')return exchangeAction(world,p,input);
  if(['shopbuy','shopsell','shoprebuy','coinshop'].includes(input.type))assertNieteService(world,p);
  if(input.type==='coinshop')return coinShopAction(world,p,input);
  if(p.dead)fail('You cannot trade while dead.');
  // A gift is a D-Shop order: the same account password is checked before anything is staged (171:31 / 171:30).
  if(input.type==='dshopgift'){if(input.operation==='send')await purchasePassword(world,p,input.password);await giftCommand(world,p,input);return true;}
  if(input.type==='dshopbuy')await purchasePassword(world,p,input.password);
  const db=world.data.itemDB;if(!db)fail('Item catalog is unavailable.',503);
  const profile=structuredClone(p.profile), inventory=new AuthoritativeInventory(profile,db,{now:world.now,random:world.random});
  let detail={},siegeTax=null;   // SIEGE: NPC shop DIL trades in the castle territory feed the owner's tax ledger
  if(input.type==='dshopbuy') {
    const data=world.data.shopData||world.data, catalog=data.dshop;
    if(!catalog)fail('D-Shop catalog is unavailable.',503);
    if(!Array.isArray(input.cart)||input.cart.length<1||input.cart.length>DSHOP_CART_MAX||typeof input.vip!=='boolean')fail('Choose between one and 28 catalog products.');
    const products=input.vip?catalog.vipShop?.products:catalog.products;
    profile.dshopBought||={};profile.cashInv||=[];let total=0;
    const buys=input.cart.map(row=>{
      if(!row||Object.keys(row).some(k=>!['product','itemIndex'].includes(k)))fail('Send catalog product identifiers only.');
      catalogIndex(row.product);catalogIndex(row.itemIndex);
      const product=products?.find(product=>product.id===row.product&&product.items.includes(row.itemIndex));
      const def=db.def(row.itemIndex), record={...def,...catalog.items?.[row.itemIndex]};
      if(!product||!def)fail('This product is not in the selected shop.');
      if((record.purchaseLimitLv||0)>(profile.level||1))fail('Your level cannot purchase this product.');
      const bought=profile.dshopBought[row.itemIndex]||0;
      if(record.purchaseLimit>0&&bought>=record.purchaseLimit)fail('The product purchase limit has been reached.');
      const price=dshopVariantPrice(record,{vip:input.vip,nativeWingPrice:product.nativeWing?nativeWingPurchasePrice(catalog.items?.[row.itemIndex]):null});integer(price,0,1000000000);
      const units=integer(dshopPurchaseUnits(catalog.items?.[row.itemIndex]),1,100000);
      profile.dshopBought[row.itemIndex]=bought+1;total+=price;
      return {itemIndex:row.itemIndex,price,units,period:dshopPurchasePeriod(record),product:row.product};
    });
    const unlimited=!input.vip&&p.capabilities?.includes('gm:commands');
    if(!unlimited)cost(profile,dshopCurrencyKey(input.vip),total);
    const cash=[];
    for(const buy of buys){if(almightyOf(catalog,buy.itemIndex)){if(buy.units!==1)fail('Choose one Premium Holy Water service.');checkPremiumItem(world,profile,buy.itemIndex);startPremium(world,profile,buy.itemIndex);}let left=buy.units;while(left>0){const count=Math.min(left,db.stackSize(db.def(buy.itemIndex)));const item=createItem(db,buy.itemIndex,{count,now:world.now(),rng:world.random});if(almightyOf(catalog,buy.itemIndex))item.premiumActivatedAt=world.now();if(buy.period>0)item.expiresAt=world.now()+buy.period*1000;Object.assign(item,{boughtAt:world.now(),purchaser:profile.name,shop:input.vip?'vip':'dshop'});delete item.page;delete item.x;delete item.y;cash.push(item);left-=count;}}
    if(!cashInventoryCanAccept(profile.cashInv,cash.length))fail('Receive existing cash items before purchasing more.');
    profile.cashInv.push(...cash);const receipt={id:randomUUID(),at:world.now(),shop:input.vip?'vip':'dshop',total,items:buys};
    profile.purchaseReceipts=[...(profile.purchaseReceipts||[]),receipt].slice(-100);profile.dshopSpent=(profile.dshopSpent||0)+(input.vip?0:total);detail={receipt};
  } else if(input.type==='cashclaim') {
    const rows=profile.cashInv||[],at=rows.findIndex(item=>item.uid===input.uid);
    if(at<0)fail('That cash item was already received or does not exist.');
    const item=rows[at];if(item.expiresAt&&item.expiresAt<=world.now())fail('That cash item has expired.');
    const target=inventoryDestination(input,inventory.bag),taken=structuredClone(item),placed=receiveAt(inventory.bag,taken,target);
    if(!placed)fail('The requested inventory destination is unavailable or full.');
    if(placed==='partial')item.count=taken.count;else rows.splice(at,1);
  } else {
    catalogIndex(input.shop);
    // Holy Water "Remote shop": no NPC (npcIndex null) and the shop is the StoreIndex of a running premium service (server-owned
    // state, never a client flag); catalog / price / stock / inventory checks below are the same as at the NPC
    const remote=input.npcIndex==null&&premiumStoreShop(world,p.profile,input.shop);
    if(!remote)catalogIndex(input.npcIndex);
    const {shop,data}=remote?remoteShop(world,input):nearShop(world,p,input);
    if(input.type==='shopbuy') {
      catalogIndex(input.itemIndex);
      const tab=shop.tabs?.[integer(input.tab,0,4)], set=tab&&data.shops.sets[tab.set];
      // Native sets can offer the same item in multiple sale quantities at different cells.
      // Coordinate-free legacy requests retain the first authored offer, never a client-supplied count/price.
      const specified=input.stockX!=null||input.stockY!=null;
      if(specified){integer(input.stockX,0,9999);integer(input.stockY,0,9999);}
      const row=set?.items?.find(row=>Number(row[0])===input.itemIndex&&(!specified||
        Number(row[2])===input.stockX&&Number(row[3])===input.stockY)),def=db.def(input.itemIndex);
      if(!row||!def)fail('The requested item is not offered on this shop tab.');
      const count=integer(input.count,1,9999),units=count*Math.max(1,Number(row[1])||1);
      const materials=set.costs?.[input.itemIndex];
      if(materials?.length){if(count!==1)fail('This item can only be purchased one at a time.');for(const [index,n]of materials){if(!inventory.remove(Number(index),Number(n)*count))fail('[message] You do not have enough material items.');}}
      else if(shop.kind==='ARENA_SHOP'&&def.purchasePoint>0)cost(profile,'battlePoints',def.purchasePoint*count);
      // Scan fix A: price 0 = free is Global data, not a bug: def.price is item.dat Price (offset 194, the client's compiled table).
      // 289 shop items have Price 0 there (181 also 0 in share CSV, 103 have no CSV row). 5 differ (CSV Price>0, dat 0):
      // 6231/6229/6170/4000521 (CSV 1) and 3200 Dice (CSV 100) -- left on item.dat for owner to decide.
      else if(def.price>0){const dil=Math.floor(def.price*(tab.buyRatio||10)/10)*count;cost(profile,'dil',dil);siegeTax={kind:'buy',amount:dil};}
      if(!inventory.add(input.itemIndex,units,{period:def.period}))fail(materials?.length?'[message] You do not have enough space in your bag.':'You do not have enough Inventory space.'); // Global 340:37 (exchange) / 40:77
    } else if(input.type==='shopsell') {
      const entry=inventory.bag.list.find(item=>item.uid===input.uid),def=entry&&db.def(entry.itemIndex);
      if(!entry||!def)fail('That inventory item does not exist.');
      const price=salePrice(def,entry,shop,data);if(inventory.dil+price>10000000000)fail('Your dil is reaching the maximum limit; you cannot sell items.');
      inventory.bag.take(entry);inventory.addDil(price);siegeTax={kind:'sell',amount:price};
      profile.shopRebuy=[...(profile.shopRebuy||[]),{id:randomUUID(),shop:input.shop,price,entry}].slice(-SHOP_REBUY_MAX);
    } else {
      const rows=profile.shopRebuy||[],at=rows.findIndex(row=>row.id===input.receipt&&row.shop===input.shop);if(at<0)fail('[message]There are no items to repurchase.');
      const receipt=rows[at];if((Number(profile.dil)||0)<receipt.price)fail("[message]You don't have enough DIL");cost(profile,'dil',receipt.price); // Global 340:23if(!inventory.bag.add(structuredClone(receipt.entry)).ok)fail("[message]You don't have enough Inventory to repurchase.");rows.splice(at,1);
    }
  }
  // Keep uncommitted purchases/claims out of snapshots. A failed durable write
  // must leave both the balance and item ownership exactly as they were.
  const previousTransition=p.sceneTransition;p.sceneTransition=true;
  try {
    const candidate={...p,profile};world.changed(candidate);await world.persist(candidate);
    p.profile=profile;world.changed(p);p.dirty=false;p.saveError=null;
  } finally {p.sceneTransition=previousTransition;}
  world.emit(p.map,{type:'inventory',actorId:p.id,reason:input.type,...detail});
  if(siegeTax)recordSiegeTax(world,p,siegeTax.kind,siegeTax.amount);
  return true;
}
