// The original Personal Shop (script/ui/game2/auction/ui_auctionsellwnd_2.txt "Personal Shop" 100:34, the expanded
// ui_auctionincreasewnd_2.txt, price entry auction/ui_askpricewnd_2.txt, price check ui_pricemsgwnd_2.txt, the Wealth Merchant's
// Stall caution msgbox/ui_increasepcshop.txt) in shared play. The seller lists bag items with a unit price; listed items stay
// in the seller's bag (like a trade offer) until a buyer's purchase commits both profiles in ONE atomic save. Opening needs a
// maplist PcStore map and Ardeca (180:1 / 180:4, help text "Available only in Ardeca"), sits the seller down (OPENMARKET is
// the sit motion) and blocks every other action until the shop closes (180:3). Messages are the original stringtable_auction
// cate 180 text (verified by tools/test-world-pcshop.mjs); full rules and gaps: docs/PERSONAL-SHOP.md.
import {fishingBusy} from './fishing.mjs';
import {WorldError} from './core.mjs';
import {sameScene} from './scene.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {Container} from '../../src/systems/items/model.js';
import {publishProfileChanges,refreshConcurrentBuffStats,persistInterveningProgress} from './profile-publication.mjs';

export const PCSHOP_SCHEMAS={pcshop:['token','type','operation','uid','count','price','name','sellerId','revision','x','y']};
export const PCSHOP_MAX_DIL=10_000_000_000;                 // 180:24 / 180:29 "10 Billion"
export const PCSHOP_NAME_MAX=25;                            // edt_storename maxlength 25
export const PCSHOP_ARDECA=150;                             // 180:4 / help "Available only in Ardeca"
export const PCSHOP_RANGE=3.2;                              // browsing a stall requires standing beside its seller
export const PCSHOP_COLS=10,PCSHOP_ROWS=5,PCSHOP_ROWS_EXPANDED=10;   // itemlist 10x10, pan_lock covers rows 5-9 until expanded
/** Original text (stringtable_auction.txt cate 180, stringtable_trade.txt 110:313); "[Message]" is the original message-box tag. */
export const PCSHOP_TEXT={
  noMap:'Personal Shops cannot be opened in this map.',                 // 180:1
  inOperation:'The shop is in operation.',                              // 180:3
  pvp:'You cannot open a Personal Shop during PVP.',                    // 180:5
  ardecaOnly:'Can only be opened while in Ardeca.',                     // 180:4
  noSpace:'You do not have enough space in the Inventory.',             // 180:11
  noDil:'You do not have enough dil.',                                  // 180:12
  noUser:'No such user exists.',                                        // 180:13
  noItem:'No such item exists.',                                        // 180:14
  closed:'The shop is closed.',                                         // 180:15
  invalidItem:'The item information is not valid.',                              // 180:16
  noShop:'No such shop exists.',                                        // 180:17
  cannotOpen:'Cannot open a shop.',                                     // 180:19
  standing:'You can only open a shop while standing.',               // 180:20
  shopSuffix:"'s Shop",                                                 // 180:21
  priceRange:'Cannot register with 0 DIL or above 10 Billion DIL.',     // 180:24
  questEvent:'Quest or Event items cannot be registered.',       // 180:25
  binding:'Binding items cannot be registered.',                        // 180:26
  quantity:'The quantity of this item has exceeded the maximum limit.',                  // 180:27
  registerFailed:'Failed to register the item.',                        // 180:28
  totalLimit:'Total selling amount cannot exceed 10 Billion.',          // 180:29
  noSelection:'No item is selected.',                                   // 180:30
  removeFailed:'Failed to remove the item from the list.',                            // 180:31
  openFailed:'Failed to open the shop.',                                // 180:32
  alreadyOpen:'The shop is already opened.',                            // 180:33
  registerOpen:'You cannot register new items while the shop is in operation.',       // 180:34
  notOpen:'The shop is not open.',                                      // 180:35
  updated:"There was an update in Shop Info. The purchase didn't go through.", // 180:41
  personalShop:'You are currently running or using a Personal Shop.',  // 110:313
};
/** Original string of every PCSHOP_TEXT entry (cate:code); tools/test-world-pcshop.mjs compares them with the tables. */
export const PCSHOP_TEXT_REFS={noMap:'180:1',inOperation:'180:3',pvp:'180:5',ardecaOnly:'180:4',noSpace:'180:11',noDil:'180:12',noUser:'180:13',noItem:'180:14',closed:'180:15',invalidItem:'180:16',noShop:'180:17',cannotOpen:'180:19',standing:'180:20',shopSuffix:'180:21',priceRange:'180:24',questEvent:'180:25',binding:'180:26',quantity:'180:27',registerFailed:'180:28',totalLimit:'180:29',noSelection:'180:30',removeFailed:'180:31',openFailed:'180:32',alreadyOpen:'180:33',registerOpen:'180:34',notOpen:'180:35',updated:'180:41',personalShop:'110:313'};
// Actions a seller may still send while the shop is open (talking and party/guild management do not move the character).
const OPEN_ALLOWED=new Set(['chat','party','expedition','stop','guild','mail','pcshop']);
const fail=(message,status=400)=>{throw new WorldError(status,message);};
const pcStoreMap=(world,map)=>Number(world.data?.dungeonData?.dg?.maps?.[map]?.raw?.PcStore)===1;
function live(world,p){return !!p&&world.players.get(p.account)===p&&!p.leaving&&!p.dead&&!p.sceneTransition;}
function shopState(profile){const s=profile.pcShop;return s&&typeof s==='object'&&!Array.isArray(s)?s:null;}
function ensure(profile){profile.pcShop=shopState(profile)||{};const s=profile.pcShop;if(!Array.isArray(s.listings))s.listings=[];s.income=Number.isSafeInteger(s.income)&&s.income>0?s.income:0;s.expanded=!!s.expanded;return s;}
export const shopRows=state=>state?.expanded?PCSHOP_ROWS_EXPANDED:PCSHOP_ROWS;
export function defaultShopName(profile){return `${profile?.name||''}${PCSHOP_TEXT.shopSuffix}`;}
function cleanName(name,profile){
  if(name==null||name==='')return defaultShopName(profile);
  if(typeof name!=='string')fail(PCSHOP_TEXT.cannotOpen);
  const value=name.replace(/[\u0000-\u001f\u007f]/g,'').trim();
  if(!value)return defaultShopName(profile);
  if([...value].length>PCSHOP_NAME_MAX)fail(PCSHOP_TEXT.cannotOpen);
  return value;
}
/** What identifies a listed bag item apart from its count and bag position. */
function signature(item){const rest={...item};for(const key of ['count','page','x','y'])delete rest[key];return JSON.stringify(rest);}
function bagOf(world,profile){return new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random}).bag;}
/** Listings whose bag item still exists unchanged, with enough of it, and not expired. */
function validListings(world,profile){
  const state=shopState(profile);if(!state||!Array.isArray(state.listings))return [];
  const bag=profile.inventory||[];
  return state.listings.filter(l=>{const item=bag.find(i=>i.uid===l.uid);return item&&signature(item)===l.sig&&(item.count||1)>=l.count&&!(item.expiresAt&&item.expiresAt<=world.now());});
}
/** The 10 x 5 (or 10 x 10 expanded) shop grid built from the listings: each cell holds a copy of the bag item with the listed count. */
function shopGrid(world,profile,listings=validListings(world,profile)){
  const state=shopState(profile)||{},list=[],bag=profile.inventory||[];
  for(const l of listings){const item=bag.find(i=>i.uid===l.uid);if(item)list.push({...structuredClone(item),count:l.count,page:0,x:l.x,y:l.y,price:l.price});}
  return new Container(list,world.data.itemDB,{pages:1,cols:PCSHOP_COLS,rows:shopRows(state),name:'pcshop'});
}
export function isShopOpen(world,p){return !!p?.pcShopOpen&&live(world,p);}
/** Public row: the open shop's sign (name) for every viewer on the map. */
export function publicPcShop(world,p){return isShopOpen(world,p)?{name:p.pcShopOpen.name,revision:p.pcShopOpen.revision}:null;}
function closeShop(world,p,reason='closed'){
  if(!p.pcShopOpen)return false;
  p.pcShopOpen=null;if(p.sitting){p.sitting=false;world.emit(p.map,{type:'emote',actorId:p.id,motion:'stand',instanceId:p.instanceId||null});}
  world.emit(p.map,{type:'pcshop',reason,sellerId:p.id,instanceId:p.instanceId||null});world.changed(p);return true;
}
/** Runs before every shared-play command: an open shop holds the seller in place (180:3); nobody trades with a running shop (110:313). */
export function pcshopGuard(world,p,input){
  if(p.pcShopOpen&&p.dead)closeShop(world,p,'closed');
  if(input.type==='trade'&&input.operation==='request'){
    const target=[...world.players.values()].find(q=>q.id===input.targetId);
    if(isShopOpen(world,p)||isShopOpen(world,target))fail(PCSHOP_TEXT.personalShop);
  }
  if(isShopOpen(world,p)&&!OPEN_ALLOWED.has(input.type))fail(PCSHOP_TEXT.inOperation);
}
/** Accounts a purchase locks: the buyer and the seller (server/world/api.mjs serializes both). */
export function pcshopAccounts(world,p,input){
  const seller=input?.operation==='buy'?[...world.players.values()].find(q=>q.id===input.sellerId):null;
  return [...new Set([p.account,...(seller?[seller.account]:[])])].sort();
}
/** The seller's own shop view (window state); listings that no longer match the bag are reported as gone. */
export function pcshopSnapshot(world,p){
  const state=shopState(p.profile);if(!state&&!p.pcShopOpen)return null;
  const valid=validListings(world,p.profile);
  return {open:!!p.pcShopOpen,name:p.pcShopOpen?.name||state?.name||defaultShopName(p.profile),income:Number(state?.income)||0,expanded:!!state?.expanded,rows:shopRows(state),
    revision:p.pcShopOpen?.revision||0,listings:valid.map(l=>({uid:l.uid,count:l.count,price:l.price,x:l.x,y:l.y})),stale:(state?.listings?.length||0)-valid.length};
}
function viewOf(world,seller){
  const grid=shopGrid(world,seller.profile),state=shopState(seller.profile);
  return {sellerId:seller.id,sellerName:seller.profile.name,name:seller.pcShopOpen.name,revision:seller.pcShopOpen.revision,expanded:!!state?.expanded,rows:shopRows(state),items:structuredClone(grid.list)};
}
async function commit(world,p,profile){
  const before=structuredClone(p.profile),revision=p.revision??0,previous=p.sceneTransition;p.sceneTransition=true;
  try{
    const candidate={...p,profile};world.changed(candidate);await world.persist(candidate);
    // Publish only this ordinary shop transaction's fields; retain live party progress and status changes.
    // Collect credits its owned income in addition to the accepted live currency interval.
    if(profile.dil!==before.dil)profile.dil=(Number(profile.dil)||0)+(Number(p.profile.dil)||0)-(Number(before.dil)||0);
    publishProfileChanges(p.profile,before,profile);refreshConcurrentBuffStats(world,p,before);world.changed(p);
    p.dirty=(p.revision??0)-revision!==1;p.saveError=null;
    await persistInterveningProgress(world,[p]);
  }finally{p.sceneTransition=previous;}
}
function registerable(world,item,def){
  if(!item||!def)fail(PCSHOP_TEXT.noItem);
  if(world.data.itemDB.category(def)==='quest'||/^event/.test(String(def.src||''))||def.eventType)fail(PCSHOP_TEXT.questEvent);
  if(item.bound||Number(def.trade)===0)fail(PCSHOP_TEXT.binding);
  if(item.expiresAt&&item.expiresAt<=world.now())fail(PCSHOP_TEXT.invalidItem);
  if(item.pet?.active||item.pet?.inv?.length)fail(PCSHOP_TEXT.registerFailed);
}
function price(value){if(!Number.isSafeInteger(value)||value<1||value>PCSHOP_MAX_DIL)fail(PCSHOP_TEXT.priceRange);return value;}
function register(world,p,profile,input){
  const state=ensure(profile),bag=bagOf(world,profile),item=bag.byUid(input.uid),def=item&&world.data.itemDB.def(item.itemIndex);
  registerable(world,item,def);
  const count=input.count??(item.count||1);
  if(!Number.isInteger(count)||count<1||count>(item.count||1))fail(PCSHOP_TEXT.quantity);
  const unit=price(input.price),total=unit*count;
  if(!Number.isSafeInteger(total)||total>PCSHOP_MAX_DIL)fail(PCSHOP_TEXT.totalLimit);
  const kept=validListings(world,profile).filter(l=>l.uid!==item.uid);
  const sum=kept.reduce((n,l)=>n+l.price*l.count,0)+total;if(sum>PCSHOP_MAX_DIL)fail(PCSHOP_TEXT.totalLimit);
  const grid=shopGrid(world,profile,kept),entry={...structuredClone(item),count};delete entry.page;delete entry.x;delete entry.y;
  const at=Number.isInteger(input.x)&&Number.isInteger(input.y)?{page:0,x:input.x,y:input.y}:{};
  const placed=grid.add(entry,{noStack:true,...at});
  if(!placed.ok||placed.placed.length!==1)fail(PCSHOP_TEXT.registerFailed);
  const cell=placed.placed[0];
  state.listings=[...kept,{uid:item.uid,itemIndex:item.itemIndex,count,price:unit,x:cell.x,y:cell.y,sig:signature(item)}];
}
function withdraw(world,profile,input){
  const state=ensure(profile),kept=validListings(world,profile);
  if(typeof input.uid!=='string'||!kept.some(l=>l.uid===input.uid))fail(PCSHOP_TEXT.removeFailed);
  state.listings=kept.filter(l=>l.uid!==input.uid);
}
function expand(world,profile,input){
  const state=ensure(profile);
  if(state.expanded)fail('Your Personal Shop is already expanded.');
  const inventory=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random}),item=inventory.bag.byUid(input.uid),def=item&&world.data.itemDB.def(item.itemIndex);
  // kind type 0 code 26 "Expand Shop" (the 10 Wealth Merchant's Stall items, all desc 354): "Expand personal shop space by 50 slots."
  if(!def||Number(def.type)!==0||Number(def.code)!==26)fail(PCSHOP_TEXT.noItem);
  if(!inventory.consumeEntry(item,1))fail(PCSHOP_TEXT.invalidItem);
  state.expanded=true;
}
function opened(world,p,input){
  if(p.pcShopOpen)fail(PCSHOP_TEXT.alreadyOpen);
  if(!pcStoreMap(world,p.map)||p.instanceId)fail(PCSHOP_TEXT.noMap);
  if(p.map!==PCSHOP_ARDECA)fail(PCSHOP_TEXT.ardecaOnly);
  if(p.path?.length||p.mount?.phase==='on'||fishingBusy(p))fail(PCSHOP_TEXT.standing);
  // PvP status = a duel of server/world/pvp.mjs (rules src/game/pvp-rules.js) in any phase: countdown or fight (180:5)
  if(p.duelId&&world.duels?.get(p.duelId))fail(PCSHOP_TEXT.pvp);
  if(p.tradeId)fail(PCSHOP_TEXT.personalShop);
}
function seller(world,p,input){
  const q=[...world.players.values()].find(q=>q.id===input.sellerId);
  if(!q||!live(world,q)||q===p)fail(PCSHOP_TEXT.noUser);
  if(!isShopOpen(world,q))fail(PCSHOP_TEXT.noShop);
  if(!sameScene(p,q)||Math.hypot(p.x-q.x,p.z-q.z)>PCSHOP_RANGE)fail(PCSHOP_TEXT.noShop);
  return q;
}
/** Stage a purchase on cloned profiles; throws (nothing changes) unless every rule holds. */
function stagePurchase(world,buyer,shopOwner,input){
  const listing=validListings(world,shopOwner.profile).find(l=>l.uid===input.uid);
  if(!listing)fail(PCSHOP_TEXT.noItem);
  if(input.price!==listing.price||input.revision!==shopOwner.pcShopOpen.revision)fail(PCSHOP_TEXT.updated);
  const count=input.count;if(!Number.isInteger(count)||count<1||count>listing.count)fail(PCSHOP_TEXT.quantity);
  const total=listing.price*count;
  const profiles=[structuredClone(buyer.profile),structuredClone(shopOwner.profile)],[buyerProfile,sellerProfile]=profiles;
  if((Number(buyerProfile.dil)||0)<total)fail(PCSHOP_TEXT.noDil);
  const sellerState=ensure(sellerProfile);
  if(sellerState.income+total>PCSHOP_MAX_DIL)fail(PCSHOP_TEXT.totalLimit);
  const sellerBag=bagOf(world,sellerProfile),item=sellerBag.byUid(listing.uid);
  const sold=sellerBag.take(item,count);if(!sold)fail(PCSHOP_TEXT.invalidItem);
  for(const key of ['page','x','y','price'])delete sold[key];
  if(!bagOf(world,buyerProfile).add(sold).ok)fail(PCSHOP_TEXT.noSpace);
  buyerProfile.dil=(Number(buyerProfile.dil)||0)-total;sellerState.income+=total;
  const rest=sellerBag.byUid(listing.uid);
  sellerState.listings=validListings(world,shopOwner.profile).map(l=>l.uid!==listing.uid?l:(l.count>count&&rest?{...l,count:l.count-count,sig:signature(rest)}:null)).filter(Boolean);
  return {profiles,sold:{itemIndex:listing.itemIndex,count,price:listing.price,total}};
}
async function buy(world,p,input){
  const q=seller(world,p,input);
  if(isShopOpen(world,p))fail(PCSHOP_TEXT.personalShop);
  stagePurchase(world,p,q,input);                                       // fail fast before queueing
  if(!world.saveProfiles)fail('Atomic shop storage is unavailable.',503);
  const players=[p,q];for(const x of players)x.tradeCommitting=true;
  let result;
  const task=world.saveQueue.catch(()=>{}).then(async()=>{
    if(!live(world,p)||!isShopOpen(world,q))fail(PCSHOP_TEXT.closed);
    const before=players.map(x=>structuredClone(x.profile)),revisions=players.map(x=>x.revision??0);
    const staged=stagePurchase(world,p,q,input),updates=players.map((x,i)=>({accountId:x.account,characterId:x.characterId,profile:world.canonical({...x,profile:staged.profiles[i]})}));
    // Both inventories change only after the atomic store confirms durability.
    if(await world.saveProfiles(updates)===false)fail('The purchase could not be saved.',503);
    players.forEach((x,i)=>{publishProfileChanges(x.profile,before[i],staged.profiles[i]);refreshConcurrentBuffStats(world,x,before[i]);world.changed(x);x.dirty=(x.revision??0)-revisions[i]!==0;x.saveError=null;});
    q.pcShopOpen.revision++;result=staged.sold;
  });world.saveQueue=task.catch(()=>{});
  try{await task;await persistInterveningProgress(world,players);}finally{for(const x of players)x.tradeCommitting=false;}
  const def=world.data.itemDB.def(result.itemIndex),entry={...result,itemName:def?.name||'',buyer:p.profile.name,at:world.now()};
  q.pcShopLog=[...(q.pcShopLog||[]),entry].slice(-100);
  world.emit(q.map,{type:'pcshop',reason:'sold',sellerId:q.id,...entry,recipients:[q.id]});
  world.emit(q.map,{type:'pcshop',reason:'updated',sellerId:q.id,revision:q.pcShopOpen.revision,instanceId:q.instanceId||null});
  return {operation:'buy',...entry,shop:viewOf(world,q)};
}
export async function pcshopCommand(world,p,input){
  const allowed={register:['uid','count','price','x','y'],withdraw:['uid'],name:['name'],open:['name'],close:[],collect:[],expand:['uid'],view:['sellerId'],buy:['sellerId','uid','count','price','revision'],state:[]};
  if(!Object.hasOwn(allowed,input.operation)||Object.keys(input).some(k=>!['token','type','operation',...allowed[input.operation]].includes(k)))fail('Invalid personal shop operation.');
  if(!world.data.itemDB)fail('The Personal Shop requires the original item catalog.',503);
  const op=input.operation;
  if(op==='state')return {operation:op,shop:pcshopSnapshot(world,p)};
  if(op==='view'){if(isShopOpen(world,p))fail(PCSHOP_TEXT.personalShop);return {operation:op,shop:viewOf(world,seller(world,p,input))};}
  if(op==='buy')return buy(world,p,input);
  if(op==='close'){if(!p.pcShopOpen)fail(PCSHOP_TEXT.notOpen);closeShop(world,p,'closed');return {operation:op,shop:pcshopSnapshot(world,p)};}
  if(p.pcShopOpen&&op!=='collect')fail(op==='open'?PCSHOP_TEXT.alreadyOpen:PCSHOP_TEXT.registerOpen);
  const profile=structuredClone(p.profile);
  if(op==='register')register(world,p,profile,input);
  else if(op==='withdraw')withdraw(world,profile,input);
  else if(op==='expand')expand(world,profile,input);
  else if(op==='name'){ensure(profile).name=cleanName(input.name,profile);}
  else if(op==='collect'){
    const state=ensure(profile);if(!state.income)fail(PCSHOP_TEXT.noSelection);
    if((Number(profile.dil)||0)+state.income>PCSHOP_MAX_DIL)fail('Your DIL balance is full.');
    profile.dil=(Number(profile.dil)||0)+state.income;state.income=0;
  } else if(op==='open'){
    opened(world,p,input);
    const state=ensure(profile),listings=validListings(world,profile);
    if(!listings.length)fail(PCSHOP_TEXT.openFailed);
    state.listings=listings;state.name=cleanName(input.name??state.name,profile);
  }
  await commit(world,p,profile);
  if(op==='open'){
    p.path=[];p.pcShopOpen={name:ensure(p.profile).name,openedAt:world.now(),revision:1};
    p.sitting=true;world.emit(p.map,{type:'emote',actorId:p.id,motion:'sit',instanceId:p.instanceId||null});
    world.emit(p.map,{type:'pcshop',reason:'opened',sellerId:p.id,instanceId:p.instanceId||null});world.changed(p);
  }
  return {operation:op,shop:pcshopSnapshot(world,p)};
}
