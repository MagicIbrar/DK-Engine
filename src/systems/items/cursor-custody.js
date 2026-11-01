// Durable owned item custody. No hidden bag cells and no client-authored item values.
// Callers transact a cloned profile and persist before publishing the result.
import {Container,canStack} from './model.js';
import {Equipment,emptyEquip,S} from './equip.js';
import {beltEligible} from './belt.js';

const fail=message=>{throw Object.assign(Error(message),{status:400});};
export const CURSOR_VERSION=1;
export const CURSOR_CONTAINERS=['bag','stash','shared','costume','belt','equip','cash','pet'];
export function cursorEntries(profile){const c=profile?.itemCursor;return c?[...(c.item?[{item:c.item,origin:c.origin}]:[]),...(Array.isArray(c.pending)?c.pending:[])]:[];}
export function cursorState(profile){
 const c=profile.itemCursor;
 if(c==null)return {version:1,revision:0,item:null,origin:null,pending:[]};
 if(c.version!==1||!Number.isSafeInteger(c.revision)||c.revision<0||!Array.isArray(c.pending)||c.pending.length>32)fail('Unsupported or invalid item cursor.');
 if(!c.item&&c.pending.length)fail('Invalid pending item cursor.');
 return c;
}
export function assertCursorOwnership(profile,db){
 const c=cursorState(profile),seen=new Set(),list=v=>Array.isArray(v)?v:[];
 const held=cursorEntries(profile);
 for(const entry of held){const i=entry?.item,d=db.def(i?.itemIndex);if(!i||typeof i.uid!=='string'||!i.uid||i.uid.length>160||!d||!Number.isInteger(i.count)||i.count<1||i.count>db.stackSize(d)||!entry.origin||!CURSOR_CONTAINERS.includes(entry.origin.container))fail('Invalid item cursor ownership.');}
 const visit=i=>{if(!i)return;if(typeof i.uid!=='string'||seen.has(i.uid))fail('Duplicate item ownership.');seen.add(i.uid);for(const nested of list(i.pet?.inv))visit(nested);};
 for(const i of [...list(profile.inventory),...list(profile.storage),...list(profile.cashInv),...list(profile.costumeBag),...list(profile.potionBelt),...list(profile.accountFeatures?.shared),...Object.values(profile.equip?.items||{}),...held.map(x=>x.item)])visit(i);
 return c;
}
function container(profile,db,name,parentUid=null){
 const spec={bag:['inventory',7,10,5,profile.bagsUnlocked||2],stash:['storage',4,10,10,profile.stashUnlocked||2],costume:['costumeBag',1,6,8,1],belt:['potionBelt',1,10,1,1]}[name];
 if(name==='shared'){profile.accountFeatures||={};profile.accountFeatures.shared||=[];return new Container(profile.accountFeatures.shared,db,{pages:1,cols:10,rows:10,name});}
 if(name==='pet'){
  const E=new Equipment({db,game:{save:profile}}),parent=E.get(S.pet);
  if(typeof parentUid!=='string'||!parentUid||parent?.uid!==parentUid||db.def(parent.itemIndex)?.slot!=='pet'||!parent.pet)fail('Equip the original pet before using its inventory.');
  parent.pet.inv||=[];for(const item of parent.pet.inv)item.page=0;
  return new Container(parent.pet.inv,db,{pages:1,cols:10,rows:4,name,accept:d=>d?.slot!=='pet'});
 }
 if(!spec)fail('Choose an owned item destination.');
 const [field,pages,cols,rows,unlocked]=spec;profile[field]||=[];
 const c=new Container(profile[field],db,{pages,cols,rows,unlocked:()=>unlocked,name,accept:d=>name==='costume'?d?.slot==='costume':name==='belt'?beltEligible(d):true});
 if(name==='belt')c.size=()=>[1,1];return c;
}
function origin(name,item,extra={}){return {container:name,page:item.page??0,x:item.x??0,y:item.y??0,...extra};}
function position(input,c){
 for(const [key,max]of [['page',c.unlocked],['x',c.cols],['y',c.rows]])if(!Number.isInteger(input[key])||input[key]<0||input[key]>=max)fail('Invalid item destination.');
 return {page:input.page,x:input.x,y:input.y};
}
function strip(item){delete item.page;delete item.x;delete item.y;return item;}
function detachEquipped(E,uid){
 const item=E.data.items[uid];if(!item)fail('That equipment is no longer owned.');
 const refs=[];for(let pi=0;pi<E.data.presets.length;pi++)for(const [slot,id]of Object.entries(E.preset(pi)))if(id===uid)refs.push({preset:pi,slot:Number(slot)});
 if(!refs.length)fail('That equipment is no longer equipped.');
 for(const {preset,slot}of refs)delete E.preset(preset)[slot];delete E.data.items[uid];
 if(refs.some(ref=>ref.slot===S.pet)&&item.pet)item.pet.active=false;
 const extras=[];
 for(const {preset,slot}of refs){if(![S.weapon,S.weapon2].includes(slot))continue;const off=slot===S.weapon?S.offhand:S.offhand2,other=E.get(off,preset),def=E.db.def(other?.itemIndex);if(!other||!(def.slot==='weapon'||E.db.weaponRule(def)?.ammoFor!=null))continue;
  delete E.preset(preset)[off];if(!E.isEquipped(other.uid)){delete E.data.items[other.uid];extras.push({item:strip(other),origin:{container:'equip',preset,slot:off,refs:[{preset,slot:off}]}});}
 }
 return [{item:strip(item),origin:{container:'equip',...refs[0],refs}},...extras];
}
function promote(c){if(!c.item&&c.pending.length){const next=c.pending.shift();c.item=next.item;c.origin=next.origin;}if(!c.item)c.origin=null;}
// ENGINE-CHOSEN recovery: retain ordinary legal bag parking where possible;
// otherwise the visible pending custody queue prevents dependent-item loss.
function retainExtras(profile,db,c,entries){const bag=container(profile,db,'bag');for(const entry of entries)if(!bag.add(entry.item,{noStack:true}).ok)c.pending.push(entry);}

/** Intent schema: operation, revision, uid, container, optional page/x/y/slot/preset/targetUid.
 * access(container, operation, item, origin) validates host storage/lock/fee rules on candidate only.
 */
export function applyCursorOperation(profile,db,input,{stats=null,access=()=>{},now=Date.now()}={}){
 const prior=assertCursorOwnership(profile,db);
 if(!Number.isSafeInteger(input.revision)||input.revision!==prior.revision)fail('The item cursor changed. Try again.');
 if(!['pickup','place','cancel','discard'].includes(input.operation))fail('Invalid item cursor action.');
 profile.equip||=emptyEquip();
 const sys={db,game:{save:profile,player:{stats}},changed(){}},E=new Equipment(sys),c=profile.itemCursor=structuredClone(prior);
 if(input.operation==='pickup'){
  if(c.item)fail('Place the held item first.');
  if(!CURSOR_CONTAINERS.includes(input.container)||typeof input.uid!=='string')fail('Choose an owned item.');
  if(input.container==='equip'){
   if(E.data.locked)fail('Equipment is locked.');
   if(!Number.isInteger(input.preset)||input.preset<0||input.preset>=5||!Object.values(S).includes(input.slot)||E.get(input.slot,input.preset)?.uid!==input.uid)fail('That equipment slot changed.');
   access('equip','pickup',E.get(input.slot,input.preset));
   const [first,...extra]=detachEquipped(E,input.uid);c.item=first.item;c.origin=first.origin;retainExtras(profile,db,c,extra);
  }else{
   if(input.container==='cash'){
    const rows=profile.cashInv||[],at=rows.findIndex(i=>i.uid===input.uid),item=rows[at];if(!item)fail('That cash item is no longer owned.');if(item.expiresAt&&item.expiresAt<=now)fail('That cash item has expired.');
    access('cash','pickup',item);c.origin={container:'cash'};c.item=strip(rows.splice(at,1)[0]);
   }else{
    const from=container(profile,db,input.container,input.parentUid),item=from.byUid(input.uid);if(!item)fail('That item is no longer owned there.');
    access(input.container,'pickup',item);c.origin=origin(input.container,item,input.container==='pet'?{parentUid:input.parentUid}:{});from.take(item);c.item=strip(item);
   }
  }
 }else if(input.operation==='discard'){
  if(!c.item||input.uid!==c.item.uid)fail('That item is not held.');
  if(c.origin.container==='cash')fail('Receive this cash item into your inventory before discarding it.');
  const def=db.def(c.item.itemIndex);if(def?.type===0&&def.code===4)fail('This item cannot be discarded.');
  access('cursor','discard',c.item,c.origin);c.item=null;c.origin=null;promote(c);
 }else{
  if(!c.item||input.uid!==c.item.uid)fail('That item is not held.');
  const to=input.operation==='cancel'?c.origin.container:input.container;
  const at=input.operation==='cancel'?c.origin:input;
  if(!CURSOR_CONTAINERS.includes(to))fail('Choose an owned item destination.');
  const held=c.item,oldOrigin=c.origin;
  // Cash is a one-way receipt queue. Moving it onto the mouse is reversible
  // selection; the first bag placement follows cashclaim without resetting time.
  if(oldOrigin.container==='cash'&&input.operation!=='cancel'&&to!=='bag')fail('Receive this cash item into your inventory first.');
  if(oldOrigin.container==='cash'&&input.operation!=='cancel'&&held.expiresAt&&held.expiresAt<=now)fail('That cash item has expired.');
  access(to,'place',held,oldOrigin);
  if(to==='cash'){
   if(input.operation!=='cancel'||oldOrigin.container!=='cash')fail('Only an unreceived cash item can return to Cash Inventory.');
   profile.cashInv||=[];if(profile.cashInv.length>=1000)fail('Cash Inventory is full. Place this held item in your bag.');profile.cashInv.push(held);c.item=null;c.origin=null;
  }else if(to==='equip'){
   if(E.data.locked)fail('Equipment is locked.');
   if(!Number.isInteger(at.preset)||at.preset<0||at.preset>=5||!Object.values(S).includes(at.slot))fail('Invalid equipment slot.');
   const check=E.check(held,at.slot,stats,at.preset);if(!check.ok)fail('Choose matching equipment slots and requirements.');
   if(held.expiresAt&&held.expiresAt<=now)fail('That item expired.');
   const old=E.get(at.slot,at.preset);
   if(input.operation==='cancel'&&old)fail('The original slot is occupied. Place the held item elsewhere.');
   if(input.operation==='place'&&(input.targetUid??null)!==(old?.uid??null))fail('The equipment destination changed.');
   const displaced=old?detachEquipped(E,old.uid):[];
   if(db.def(held.itemIndex).belong===1)held.bound=true;
   const result=E.place(held,at.slot,at.preset);for(const item of result.displaced)displaced.push({item:strip(item),origin:{container:'equip',slot:at.slot===S.weapon2?S.offhand2:S.offhand,preset:at.preset}});
   c.item=null;c.origin=null;
   if(input.operation==='cancel'&&Array.isArray(oldOrigin.refs))for(const ref of oldOrigin.refs){if(E.preset(ref.preset)[ref.slot]&&E.preset(ref.preset)[ref.slot]!==held.uid)continue;if(E.check(held,ref.slot,stats,ref.preset).ok)E.preset(ref.preset)[ref.slot]=held.uid;}
   if(displaced.length){const first=displaced.shift();c.item=first.item;c.origin=first.origin;retainExtras(profile,db,c,displaced);}
  }else{
   const dest=container(profile,db,to,at.parentUid),point=position(at,dest),[w,h]=dest.size(held);
   if(!dest.accept(db.def(held.itemIndex))||!dest.inside(point.x,point.y,w,h))fail('That item does not fit this destination.');
   const occ=dest.occupants(point.page,point.x,point.y,w,h);if(occ.length>1)fail('The destination overlaps more than one item.');
   const target=occ[0]||null;
   if(input.operation==='cancel'&&target)fail('The original position is occupied. Place the held item elsewhere.');
   if(input.operation==='place'&&(input.targetUid??null)!==(target?.uid??null))fail('The item destination changed.');
   if(target&&canStack(held,target,db)){
    const amount=Math.min(held.count,db.stackSize(db.def(held.itemIndex))-target.count);if(amount<=0)fail('That stack is full.');target.count+=amount;held.count-=amount;if(!held.count){c.item=null;c.origin=null;}
   }else{
    let targetOrigin=null;if(target){access(to,'pickup',target);targetOrigin=origin(to,target,to==='pet'?{parentUid:at.parentUid}:{});dest.take(target);}
    Object.assign(held,point);if(to==='pet')Object.assign(held,{w,h});dest.list.push(held);c.item=target?strip(target):null;c.origin=targetOrigin;
   }
  }
  promote(c);
 }
 c.revision++;assertCursorOwnership(profile,db);return c;
}
