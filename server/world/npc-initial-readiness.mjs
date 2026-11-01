// Only the new-profile factory calls this before its first canonical storage.
// This is ENGINE-CHOSEN initial construction, not earned progress or a live action.
import {Equipment,S} from '../../src/systems/items/equip.js';
import {AuthoritativeInventory} from '../../server/world/inventory.mjs';
import {npcSpareStatPlan} from './npc-builds.mjs';
const keys=['str','dex','con','spr'];
const slots=[S.weapon,S.offhand,S.helmet,S.armor,S.pants,S.glove,S.boots,S.acc1,S.acc2,S.acc3,S.acc4,S.wing,S.earL,S.earR,S.brace1,S.brace2,S.belt,S.emblem,S.force1,S.force2,S.talisman,S.costume];
export function prepareNewNpcEquipment(profile,data,{newUnpersistedProfile=false}={}){
 if(!newUnpersistedProfile||profile?.authority!=='server'||profile.npcPlayer!==true||profile.npcSeed?.readiness||
   ['exp','dil','kills','deaths','playSeconds'].some(k=>profile[k]!==0)||profile.hp!==null||profile.mp!==null||
   !Number.isInteger(profile.statPoints)||profile.statPoints<0||!keys.every(k=>Number.isFinite(profile.stats?.[k])))throw Error('Only fresh unpersisted birth profiles');
 const stock=profile.npcSeed?.stock,db=data.itemDB;
 if(!db||stock?.policy!=='ENGINE-CHOSEN'||stock.level!==profile.level||!Array.isArray(stock.uids)||stock.uids.length>slots.length||new Set(stock.uids).size!==stock.uids.length||
   Object.keys(profile.equip?.items||{}).length||profile.equip?.presets?.some(p=>Object.keys(p).length))throw Error('Invalid initial stock ownership');
 const next=structuredClone(profile),inv=new AuthoritativeInventory(next,db),eq=new Equipment({db,game:{save:next}}),items=stock.uids.map(uid=>next.inventory.find(i=>i.uid===uid));
 if(items.some(i=>!i||next.inventory.filter(j=>j.uid===i.uid).length!==1||i.bound!==true||i.npcStartingStock!=='ENGINE-CHOSEN'||i.expiresAt||i.count!==1))throw Error('Invalid birth UID');
 const planned={...next.stats};
 for(const item of items){const def=db.def(item.itemIndex);if(!def)throw Error('Missing native definition');
  for(const stat of ['str','dex','spr']){const requirement=Number(def['req'+stat[0].toUpperCase()+stat.slice(1)]||0);if(!Number.isFinite(requirement)||requirement<0)throw Error('Invalid native requirement');planned[stat]=Math.max(planned[stat],requirement);}}
 const cost=keys.reduce((sum,k)=>sum+planned[k]-next.stats[k],0);
 if(!Number.isInteger(cost)||cost<0||cost>next.statPoints||keys.some(k=>planned[k]>data.statCap(next.classIndex,k)))throw Error('Native point budget exceeded');
 next.stats=planned;next.statPoints-=cost;
 for(const slot of slots){const item=items.find(i=>inv.bag.byUid(i.uid)&&eq.slotsFor(db.def(i.itemIndex)).includes(slot));if(!item)continue;
  const def=db.def(item.itemIndex);
  if(def.slot==='weapon'&&slot===S.weapon){const rule=db.weaponRule(def);if(!rule||!eq.canStyle(rule.style)&&!eq.canStyle(rule.altStyle))throw Error('Native style unavailable');}
  if(['weapon','helmet','armor','pants','glove','boots','wing','costume'].includes(def.slot)&&!eq.assetFor(def.index))throw Error('Native model unavailable');
  if(!eq.check(item,slot,next.stats).ok)throw Error('Native equipment eligibility refused');
  const taken=inv.bag.take(item);if(!taken)throw Error('Birth UID transfer refused');delete taken.page;delete taken.x;delete taken.y;
  const result=eq.place(taken,slot);if(!result.ok||result.displaced?.length)throw Error('Unexpected birth displacement');
 }
 if(items.some(i=>inv.bag.byUid(i.uid)))throw Error('Initial stock has no supported ordinary slot');
 next.npcSeed.readiness={policy:'ENGINE-CHOSEN initial construction; never earned progress',statPointCost:cost,equippedUids:items.map(i=>i.uid)};
 // Finish only this new unpersisted cohort's existing chosen spare-point build.
 // At most CON then role main; cap-blocked points remain unspent, as in npcBuildStep.
 for(let pass=0;pass<2;pass++){
  const plan=npcSpareStatPlan(data,next);if(!plan)break;
  if(!keys.includes(plan.stat)||!Number.isInteger(plan.count)||plan.count<=0||plan.count>next.statPoints||next.stats[plan.stat]+plan.count>data.statCap(next.classIndex,plan.stat))throw Error('Native spare point allocation refused');
  next.stats[plan.stat]+=plan.count;next.statPoints-=plan.count;
 }
 return next;
}
