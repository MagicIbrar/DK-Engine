import {Equipment,S} from '../items/equip.js';
import {upgradeChain} from './itemgen.js';
import {isStone,socketable,stoneFits} from '../items/ui/socket.js';
import {documentedSocketLimit} from '../items/socket-capacity.js';
export const GEAR_SET_SLOTS=Object.freeze([S.weapon,S.offhand,S.helmet,S.armor,S.pants,S.glove,S.boots,S.acc1,S.acc2,S.acc3,S.acc4,S.earL,S.earR,S.brace1,S.brace2,S.belt,S.wing,S.emblem,S.force1,S.force2,S.talisman]);
const preferred=mode=>mode==='pvp'?/PVP|PC_DAMAGE|PC_DEFENSE|PLAYER/:/MONSTER|BOSS|PVE/;
const gearScore=(db,d,mode)=>Number(d.reqLv||0)*100000+Number(d.itemLv||0)*1000+Math.max(...(d.melee||[0]),...(d.ranged||[0]),...(d.magic||[0]))+Number(d.def?.[1]||0)+(d.options||[]).reduce((n,[c,v])=>n+(preferred(mode).test(db.optionName(c)||'')?Math.abs(v)*100:0),0);
const nativeSockets=(db,d)=>socketable(d)?Math.min(4,Math.max(0,documentedSocketLimit(db,d)??(d.socketRates||[]).reduce((max,v,i)=>Number(v)>0?i+1:max,0))):0;
const stoneIds=new WeakMap();
function socketStoneIds(db){if(!db.T?.socketStones?.rows?.length)return [];if(!stoneIds.has(db))stoneIds.set(db,[...new Set(db.T.socketStones.rows.map(r=>Number(r.SocketIndex)).filter(Number.isSafeInteger))]);return stoneIds.get(db);}
function gemScore(db,d,mode,target){
 const magic=Number(target.magic?.[1]||target.magic?.[0]||0)>Math.max(Number(target.melee?.[1]||target.melee?.[0]||0),Number(target.ranged?.[1]||target.ranged?.[0]||0));
 return [...(d.options||[]),...(d.exOptions||[])].reduce((sum,[code,value])=>{
  const name=String(db.optionName(code)||'').toUpperCase(),v=Math.abs(Number(value)||0);
  const relevant=preferred(mode).test(name)?100000:0;
  const offense=/DAMAGE|ATTACK|CRITICAL|RATE/.test(name)?10000:0;
  const classFit=(magic?/MAGICAL|MAGIC|SPR/:/MELEE|RANGED|PHYSICAL|STR|DEX/).test(name)?1000:0;
  const defense=/DEFENSE|HP_MAX|RESIST|GUARD/.test(name)?500:0;
  return sum+relevant+offense+classFit+defense+Math.log1p(v)*100;
 },0);
}
/** Every native socket stone legal for this item, strongest mode-relevant authored options first. */
export function gearGemChoices(db,itemIndex,mode='monster'){
 const target=db.def(itemIndex);if(!target||!socketable(target))return [];
 return socketStoneIds(db).map(index=>db.def(index)).filter(d=>isStone(d)&&stoneFits(db,d,target)).map(d=>({index:d.index,name:d.name,score:gemScore(db,d,mode,target)})).sort((a,b)=>b.score-a.score||b.index-a.index);
}
/** Class-compatible native equipment at the chosen reinforcement ceiling; used by both preview and dropdowns. */
export function gearSlotChoices(db,{classIndex,level=250,mode='monster',upgrade=40,weaponStyle=null,slot=S.weapon,weaponItem=null}={}){
 const eq=new Equipment({db,game:{save:{classIndex,level}}});
 if(slot===S.offhand&&weaponItem){const main=db.def(weaponItem);if(!main||!eq.check({itemIndex:main.index},S.weapon).ok)return [];eq.place({uid:'gear-choice-main',itemIndex:main.index},S.weapon);}
 const found=new Map();
 for(const key of Object.keys(db.items)){
  const d=db.def(Number(key));if(!d?.slot||d.period||d.reqLv>level||d.maxLv&&level>d.maxLv||!((Number(d.classMask)>>>classIndex)&1)||d.prev)continue;
  const rule=db.weaponRule(d);if(d.slot==='weapon'&&(!eq.canStyle(rule?.style)||weaponStyle!=null&&Number(rule?.style)!==Number(weaponStyle)))continue;
  const refined=upgradeChain(db,d.index).filter(r=>r.lv<=upgrade).at(-1),def=db.def(refined?.index||d.index);
  if(!def||def.reqLv>level||!((Number(def.classMask)>>>classIndex)&1)||!eq.slotsFor(def).includes(slot)||!eq.check({itemIndex:def.index},slot).ok)continue;
  found.set(def.index,{index:def.index,name:def.name,score:gearScore(db,def,mode),kind:db.kindName(def),level:def.reqLv||0});
 }
 return [...found.values()].sort((a,b)=>b.score-a.score||a.index-b.index);
}
export function maximumGearOptions(db,def,mode='monster',grade='divine'){
 const count={normal:0,magic:2,noble:3,divine:4}[grade],out=[];
 for(let k=0;k<count;k++){
  const range=def.optionPools?.[Math.min([0,0,1,2][k],(def.optionPools?.length||0)-1)];if(!range)continue;
  const rows=[];for(let n=range[0]||range[1];n>0&&n<=range[1];n++)rows.push(...(db.options?.pools?.[n]||[]));
  const score=row=>{const name=db.optionName(Number(row[1]))||'';const preferred=mode==='pvp'?/PVP|PC_DAMAGE|PC_DEFENSE/:/MONSTER|BOSS|PVE/;return (preferred.test(name)?10000:0)+(/DAMAGE|DEFENSE|HP_MAX|CRITICAL|ATTACK/.test(name)?1000:0)+Math.abs(Number(row[3])||0);};
  rows.sort((a,b)=>score(b)-score(a)||Number(a[1])-Number(b[1]));const row=rows.find(r=>db.optionType(Number(r[1]))&&Number.isFinite(Number(r[3])));
  if(row)out.push([Number(row[1]),Number(row[3])]);
 }
 return out;
}
// ENGINE-CHOSEN preset ranking; native class/style, item chains and roll limits
// remain authoritative. "Maximum" describes rolls/refinement, not an optimal build.
export function planGearSet(db,{classIndex,level=250,mode='monster',upgrade=40,grade='divine',sockets=4,bound=true,weaponStyle=null,overrides={},gems={}}={}){
 if(!overrides||typeof overrides!=='object'||Array.isArray(overrides)||Object.entries(overrides).some(([slot,item])=>!GEAR_SET_SLOTS.includes(Number(slot))||!Number.isSafeInteger(item)||item<=0))throw Error('Choose valid native item overrides.');
 if(weaponStyle!=null&&(!Number.isInteger(weaponStyle)||weaponStyle<0))throw Error('Choose a valid native weapon style.');
 if(!gems||typeof gems!=='object'||Array.isArray(gems)||Object.entries(gems).some(([slot,index])=>!GEAR_SET_SLOTS.includes(Number(slot))||!Number.isSafeInteger(index)||index<=0))throw Error('Choose valid native gemstone overrides.');
 if(!Number.isInteger(classIndex)||classIndex<0||classIndex>14||!Number.isInteger(level)||level<1||level>250||!['pvp','monster'].includes(mode)||!Number.isInteger(upgrade)||upgrade<0||upgrade>40||!['normal','magic','noble','divine'].includes(grade)||!Number.isInteger(sockets)||sockets<0||sockets>4||typeof bound!=='boolean')throw Error('Choose valid gear-set settings.');
 const eq=new Equipment({db,game:{save:{classIndex,level}}}),bySlot=new Map(GEAR_SET_SLOTS.map(s=>[s,[]]));
 for(const key of Object.keys(db.items)){
  const d=db.def(Number(key));if(!d?.slot||d.period||d.reqLv>level||d.maxLv&&level>d.maxLv||!((Number(d.classMask)>>>classIndex)&1)||d.prev)continue;
  const rule=db.weaponRule(d);if(d.slot==='weapon'&&(!eq.canStyle(rule?.style)||weaponStyle!=null&&Number(rule?.style)!==Number(weaponStyle)))continue;
  const chain=upgradeChain(db,d.index),refined=chain.filter(r=>r.lv<=upgrade).at(-1),def=db.def(refined?.index||d.index);
  if(def.reqLv>level||!((Number(def.classMask)>>>classIndex)&1))continue;
  for(const slot of eq.slotsFor(def))if(bySlot.has(slot))bySlot.get(slot).push(def);
 }
 const items=[],missing=[];
 for(const slot of GEAR_SET_SLOTS){
  let d;if(overrides[slot]!=null){d=db.def(Number(overrides[slot]));if(!d||!bySlot.get(slot).some(x=>x.index===d.index))throw Error(`Override for slot ${slot} must match the class, level and refinement settings.`);}
  else d=bySlot.get(slot).sort((a,b)=>gearScore(db,b,mode)-gearScore(db,a,mode)||a.index-b.index).find(candidate=>eq.check({itemIndex:candidate.index},slot).ok);
  if(d&&!eq.check({itemIndex:d.index},slot).ok)throw Error(`Override for slot ${slot} conflicts with the selected equipment.`);
  if(!d){missing.push(slot);continue;}
  // Two-handed weapons cannot coexist with an offhand.
  if(slot===S.offhand&&db.weaponRule(db.def(items.find(i=>i.slot===S.weapon)?.item))?.hands>=2)continue;
  const count=Math.min(sockets,nativeSockets(db,d)),choices=count?gearGemChoices(db,d.index,mode):[];
  if(gems[slot]!=null&&!choices.some(g=>g.index===gems[slot]))throw Error(`Gemstone for slot ${slot} does not fit the selected native item.`);
  const stone=gems[slot]??choices[0]?.index??0;
  items.push({slot,item:d.index,name:d.name,count:1,grade,options:maximumGearOptions(db,d,mode,grade),sockets:Array(count).fill(stone),bound,roll:false,to:'bag'});
  eq.place({uid:`gear-preview-${slot}`,itemIndex:d.index},slot);
 }
 for(const slot of Object.keys(gems))if(!items.some(item=>item.slot===Number(slot)))throw Error(`Gemstone slot ${slot} is unavailable for this set.`);
 return {classIndex,level,mode,items,missing};
}
