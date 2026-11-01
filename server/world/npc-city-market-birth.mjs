import {AuthoritativeInventory} from './inventory.mjs';
import {gearGemChoices,maximumGearOptions} from '../../src/systems/gm/gear-set.js';
import {socketable} from '../../src/systems/items/ui/socket.js';
import {documentedSocketLimit} from '../../src/systems/items/socket-capacity.js';

// ENGINE-CHOSEN finite initial world inventory, not earned drops or a refill.
// Separate tradable surplus never unbinds or replaces the character's own kit.
const catalogs=new WeakMap();
export function seedNpcCityMarketBirth(profile,data,{newUnpersistedProfile=false,serial=0,now=Date.now,random=Math.random}={}){
 if(newUnpersistedProfile!==true||profile?.authority!=='server'||profile.npcPlayer!==true||profile.map!==150||profile.npcSeed?.initialGoal?.kind!=='merchant')return [];
 if(profile.npcInitialMarketStock)throw Error('Initial merchant stock cannot be reseeded.');
 const row=data.mapRow?.(150),db=data.itemDB;
 if(!db||Number(row?.PeaceZone)!==1||Number(row?.PcStore)!==1||data.requiresInstance?.(150)||data.eventData?.modeOf?.(150)||Number(row?.IsSiege))return [];
 if(!catalogs.has(db))catalogs.set(db,Object.keys(db.items).map(id=>db.def(id)).filter(Boolean));
 const grade=profile.npcTraits?.gear==='insane'?'divine':profile.npcTraits?.gear==='strong'?'noble':'magic';
 const ranks=profile.npcTraits?.gear==='insane'?[0,10,12,13,14,15]:[0],ownClass=1<<profile.classIndex;
 const candidates=catalogs.get(db).filter(d=>['weapon','helmet','armor','pants','glove','boots'].includes(d.slot)&&ranks.includes(d.rank)&&!d.cash&&!d.period&&!d.eventType&&!/^event/.test(String(d.src||''))&&Number(d.trade)!==0&&Number(d.price)>0&&Number.isSafeInteger(Number(d.price))&&d.reqLv<=profile.level&&d.reqLv>=Math.max(1,profile.level-40)&&(!d.maxLv||profile.level<=d.maxLv)&&Number(d.itemLv||0)<=9&&Number(d.classMask)>0&&!(Number(d.classMask)&ownClass)).sort((a,b)=>b.reqLv-a.reqLv||Number(b.itemLv)-Number(a.itemLv)||Number(b.price)-Number(a.price)||a.index-b.index);
 const inv=new AuthoritativeInventory(profile,db,{now,random}),uids=[],slots=new Set();
 for(const d of candidates){
  if(uids.length>=3)break;if(slots.has(d.slot)||d.slot==='weapon'&&slots.has('weapon'))continue;
  // One weapon and two distinct armor pieces, all for actual other classes.
  if(d.slot!=='weapon'&&[...slots].filter(s=>s!=='weapon').length>=2)continue;
  const gems=socketable(d)?gearGemChoices(db,d.index,'monster'):[],capacity=documentedSocketLimit(db,d)??(d.socketRates||[]).reduce((n,v,i)=>Number(v)>0?i+1:n,0),sockets=gems.length?Array(Math.min(4,grade==='divine'?4:grade==='noble'?2:1,Math.max(0,capacity))).fill(gems[0].index):[];
  const before=new Set(profile.inventory.map(i=>i.uid));
  if(!inv.add(d.index,1,{grade,bound:false,roll:grade!=='divine',...(grade==='divine'?{rnd:maximumGearOptions(db,d,'monster',grade)}:{}),sockets}))continue;
  const item=profile.inventory.find(i=>!before.has(i.uid));if(!item)throw Error('Native merchant birth inventory receipt missing.');
  item.npcInitialMarketStock='ENGINE-CHOSEN';uids.push(item.uid);slots.add(d.slot);
 }
 profile.npcInitialMarketStock={version:1,policy:'ENGINE-CHOSEN finite NEW merchant initial world inventory; not earned loot; no refill or saved-profile grant',uids,serial};
 return uids;
}
