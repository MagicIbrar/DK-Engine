import {ownedItems} from './item-ownership.mjs';
// D-Shop "Send as Gift" on the shared host (rules and sources: src/systems/shops/gift-rules.js).
//
// One social transaction may write the actor's profile plus the shared social document, never two profiles
// (social-state.mjs saveSocialTransaction). A gift therefore follows the mail escrow pattern:
//   send    the buyer's DKC debit, purchase counters and receipt commit TOGETHER with the gift rows placed in
//           social.gifts[recipientRef] (already created item instances: purchaser = sender, period counted from purchase)
//   accept  the recipient moves its pending rows into its own Cash Inventory (profile.cashInv) in its own transaction;
//           the existing cashclaim path then moves them into the bag
// A failed durable write leaves the buyer's balance, counters and every mailbox exactly as they were (socialTransaction
// keeps live state untouched until the write succeeds); requestId receipts make a replayed send fail once-only.
import {randomUUID} from 'node:crypto';
import {createItem} from '../../src/systems/items/model.js';
import {nativeWingPurchasePrice} from '../../src/content/native-wing-shop.js';
import {almightyOf} from '../../src/systems/shops/premium-rules.js';
import {GIFT_TEXT,GIFT_PENDING_MAX,giftRecipient,giftExpiry} from '../../src/systems/shops/gift-rules.js';
import {socialError as fail,socialIntent,socialTransaction} from './social-state.mjs';

export const GIFT_ACTION_SCHEMAS={dshopgift:['token','type','operation','cart','recipient','password','revision','requestId']};
const CASH_INVENTORY_MAX=1000;   // the existing D-Shop Cash Inventory bound (shops.mjs dshopbuy)
const index=value=>{if(!Number.isSafeInteger(value)||value<0)fail('Invalid purchase quantity or index.');return value;};

/** Same catalog/limit/price rules as shops.mjs dshopbuy for the regular D-Shop (never the VIP shop). */
function stageCart(world,profile,cart){
  const catalog=(world.data.shopData||world.data).dshop,db=world.data.itemDB;
  if(!catalog||!db)fail('D-Shop catalog is unavailable.',503);
  if(!Array.isArray(cart)||cart.length<1||cart.length>28)fail('Choose between one and 28 catalog products.');
  profile.dshopBought||={};let total=0;
  const buys=cart.map(row=>{
    if(!row||Object.keys(row).some(k=>!['product','itemIndex'].includes(k)))fail('Send catalog product identifiers only.');
    index(row.product);index(row.itemIndex);
    const product=catalog.products?.find(product=>product.id===row.product&&product.items.includes(row.itemIndex));
    const def=db.def(row.itemIndex),record={...def,...catalog.items?.[row.itemIndex]};
    if(!product||!def)fail('This product is not in the selected shop.');
    if(almightyOf(catalog,row.itemIndex))fail(GIFT_TEXT.premium);
    if((record.purchaseLimitLv||0)>(profile.level||1))fail('Your level cannot purchase this product.');
    const bought=profile.dshopBought[row.itemIndex]||0;
    if(record.purchaseLimit>0&&bought>=record.purchaseLimit)fail('The product purchase limit has been reached.');
    const price=Number(product.nativeWing?nativeWingPurchasePrice(catalog.items?.[row.itemIndex]):(record.cash||0));
    if(!Number.isSafeInteger(price)||price<0||price>1_000_000_000)fail('Invalid catalog price.');
    const units=Number(catalog.items?.[row.itemIndex]?.stack??1);
    if(!Number.isSafeInteger(units)||units<1||units>100000)fail('Invalid purchase quantity or index.');
    profile.dshopBought[row.itemIndex]=bought+1;total+=price;
    return {itemIndex:row.itemIndex,price,units,period:Number(record.period)||0,product:row.product};
  });
  return {buys,total,db};
}

export async function giftCommand(world,p,input){
  socialIntent(input,{send:['cart','recipient','password'],accept:[]});
  return socialTransaction(world,p,input,async(state,profile,ref)=>{
    state.gifts||={};
    if(input.operation==='accept'){
      const pending=state.gifts[ref]||[];
      if(!pending.length)fail(GIFT_TEXT.none,404);
      profile.cashInv||=[];
      if(profile.cashInv.length+pending.length>CASH_INVENTORY_MAX)fail('Receive existing cash items before accepting more gifts.');
      const owned=new Set(ownedItems(profile).map(item=>item?.uid).filter(Boolean));
      for(const row of pending){if(!row?.item?.uid||owned.has(row.item.uid))fail('That gift item identity already exists.',409);owned.add(row.item.uid);}
      profile.cashInv.push(...pending.map(row=>structuredClone(row.item)));
      delete state.gifts[ref];
      return {received:pending.length};
    }
    const named=giftRecipient(input.recipient);if(named.error)fail(named.error);
    if(typeof world.listCharacters!=='function')fail('The character directory is unavailable.',503);
    const {buys,total,db}=stageCart(world,profile,input.cart);
    const matches=(await world.listCharacters()).filter(c=>String(c.name).toLowerCase()===named.name.toLowerCase());
    if(matches.length!==1)fail(GIFT_TEXT.noCharacter,404);
    const target=matches[0];if(target.ref===ref)fail(GIFT_TEXT.self);
    // GM accounts buy without a D-Shop balance (shops.mjs dshopbuy); everyone else pays DKC before anything is staged.
    if(!p.capabilities?.includes('gm:commands')){
      const dkc=Number(profile.dkc)||0;if(dkc<total)fail('Not enough DKC.');profile.dkc=dkc-total;
    }
    const time=world.now(),rows=[];
    for(const buy of buys){
      let left=buy.units;
      while(left>0){
        const count=Math.min(left,db.stackSize(db.def(buy.itemIndex)));
        const item=createItem(db,buy.itemIndex,{count,now:time,rng:world.random});
        const expiresAt=giftExpiry(time,buy.period);if(expiresAt)item.expiresAt=expiresAt;   // 171:28
        Object.assign(item,{boughtAt:time,purchaser:profile.name,gift:profile.name,shop:'dshop'});
        delete item.page;delete item.x;delete item.y;
        rows.push({id:randomUUID(),from:profile.name,time,item});left-=count;
      }
    }
    const pending=state.gifts[target.ref]||=[];
    if(pending.length+rows.length>GIFT_PENDING_MAX)fail(GIFT_TEXT.pending);
    pending.push(...rows);
    const receipt={id:randomUUID(),at:time,shop:'dshop',total,items:buys,gift:{to:target.name}};
    profile.purchaseReceipts=[...(profile.purchaseReceipts||[]),receipt].slice(-100);profile.dshopSpent=(profile.dshopSpent||0)+total;
    return {to:target.name,rows:rows.length,total};
  });
}
/** Header-only view of the gifts waiting for this character (rides the private mail snapshot). */
export function pendingGifts(world,ref){
  return (world.socialState?.gifts?.[ref]||[]).map(row=>({id:row.id,from:row.from,time:row.time,itemIndex:row.item?.itemIndex||0,count:row.item?.count||0}));
}
