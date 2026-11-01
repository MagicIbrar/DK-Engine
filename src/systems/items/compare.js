import {instOptions} from './stats.js';
import {optionDisplayValue} from './native-option-values.js';
const brandNo=new WeakMap();
/** Tooltip template of an option type from the client data: stringtable_itemdesc 502; else the Item Branding line
 * (902) of the incuseoption.csv row with the same option name (PVPDAMAGE_* / ANTI_ANTI_RATE have no 502 entry);
 * else the prepared option text. null when the data defines no label (no name is invented). */
export function optionTemplate(db,type){
 const own=db.str?.(502,type);if(own)return own;
 const name=db.optionName?.(type),rows=db.T?.incuseOption?.rows;
 if(name&&rows){if(!brandNo.has(rows))brandNo.set(rows,new Map(rows.map(r=>[r.Option,Number(r.No)])));const no=brandNo.get(rows).get(name),line=no!=null&&db.str?.(902,no);if(line)return line;}
 return db.optionType?.(type)?.text||null;
}
/** {label, unit} of a template: the text before its value column (no trailing colon) and the suffix after <VALUE>. */
export function optionLabelParts(template){
 const text=String(template??''),at=text.search(/<set=[^>]*>|<VALUE>/i),head=at<0?text:text.slice(0,at),tail=text.includes('<VALUE>')?text.slice(text.lastIndexOf('<VALUE>')+7):'';
 const clean=s=>s.replace(/<[^>]*>/g,'').replace(/\\+/g,'');
 return {label:clean(head).replace(/[:：]\s*$/,'').trim(),unit:clean(tail).trim()};
}
/** Only the item's declared native slot group, including legal dual offhand. */
export function comparisonTargets(sys,inst){
 const def=sys.db.def(inst?.itemIndex);if(!def?.slot)return [];
 return [...new Set(sys.equip.slotsFor(def))].flatMap(slot=>{
  const worn=sys.equip.get(slot),other=sys.db.def(worn?.itemIndex);
  if(!worn||!other||other.slot!==def.slot)return [];
  if(slot===5&&def.slot==='weapon'&&(!sys.db.weaponRule(def)?.dual||other.code!==def.code))return [];
  return [{slot,worn}];
 });
}
/** Exact instance contributions, not a guessed aggregate best-item score. */
export function comparisonValues(db,inst){
 const d=db.def(inst?.itemIndex),out=new Map();if(!d)return out;
 // itemDefaults carry [0,0] for every damage family: only a real damage range is a base value (armour has none).
 for(const [field,label]of [['melee','Melee'],['ranged','Ranged'],['magic','Magic']])if(Number(d[field]?.[0])||Number(d[field]?.[1])){out.set('base:'+label+' minimum',Number(d[field][0])||0);out.set('base:'+label+' maximum',Number(d[field][1])||0);}
 for(const [key,value]of [['Defense',d.def?.[1]||d.def?.[0]],['Block',d.block],['Critical',d.crit]])if(value)out.set('base:'+key,Number(value));
 for(const [type,value]of instOptions(db,inst)){const name=db.optionName(type)||'Option '+type;out.set(name,(out.get(name)||0)+optionDisplayValue(type,value,db));}
 return out;
}
const BENEFICIAL=new Set(['STAT_STR_ADD','STAT_DEX_ADD','STAT_CON_ADD','STAT_SPR_ADD','HP_MAX_ADD','MP_MAX_ADD','RATING_ATTACK_ADD','BALANCE_MARK_ADD','DEFENSE_MIN_ADD','ARMOR_ADD','BALANCE_BLOCKING_ADD', 'BALANCE_DEATHBLOW_ADD', 'BALANCE_GUARD_ADD', 'BALANCE_MAGIC_REGIST_ADD', 'BALANCE_MARK_ADD', 'BALANCE_VITALITY_ADD', 'DAMAGEADD_CURSE_ADD', 'DAMAGEADD_DARK_ADD', 'DAMAGEADD_FIRE_ADD', 'DAMAGEADD_ICE_ADD', 'DAMAGEADD_LIGHTNING_ADD', 'DAMAGEADD_POISON_ADD', 'DAMAGERATE_CRITICAL_ADD', 'DAMAGE_MAGICAL_MUL', 'DAMAGE_MAXMAGICAL_ADD', 'DAMAGE_MAXPHYSICAL_ADD', 'DAMAGE_MINMAGICAL_ADD', 'DAMAGE_MINPHYSICAL_ADD', 'DAMAGE_PHYSICAL_MUL', 'DEFENSE_ADD', 'DEFENSE_MUL', 'HP_MAX_MUL', 'HP_RECOVERY_ADD', 'MP_MAX_MUL', 'MP_RECOVERY_ADD', 'POSITIVE_ALLRESIST_ADD', 'POSITIVE_CURSERESIST_ADD', 'POSITIVE_DARKRESIST_ADD', 'POSITIVE_FIRERESIST_ADD', 'POSITIVE_ICERESIST_ADD', 'POSITIVE_LIGHTNINHRESIST_ADD', 'POSITIVE_POISONRESIST_ADD', 'RANGE_DAMAGE_MAXRANGECAL_ADD', 'RANGE_DAMAGE_MINRANGECAL_ADD', 'RANGE_DAMAGE_RANGECAL_MUL', 'RATING_BLOCKING_ADD', 'RATING_CRITICAL_ADD', 'RATING_CRITICAL_SUB', 'RESIST_MAGIC_ADD', 'RESULT_EXP_MUL', 'SIZEDAMAGERATE_BOSS_ADD', 'SPEED_ATTACK_MUL', 'SPEED_CASTING_MUL', 'SPEED_COOLTIME_MUL', 'SPEED_MOVE_MUL']);
const PENALTIES=new Set(['DAMAGE_PHYSICAL_SUB','RANGE_DAMAGE_RANGECAL_SUB','DAMAGE_MAGICAL_SUB','DEFENSE_SUB','SPEED_ATTACK_SUB','SPEED_MOVE_SUB']);
export function comparisonSlotLabel(slot){return ({0:'Accessory 1',1:'Accessory 3',2:'Accessory 2',3:'Accessory 4',4:'Main weapon',5:'Offhand',6:'Growth',7:'Wings',8:'Helmet',9:'Armor',10:'Pants',11:'Gloves',12:'Boots',18:'Costume',19:'Pet',20:'Vehicle',24:'Left earring',25:'Right earring',26:'Bracelet 1',27:'Bracelet 2',28:'Belt',33:'Emblem',34:'Force 1',35:'Force 2',36:'Talisman'})[slot]||`Equipment ${slot}`;}
export function comparisonDeltas(db,item,worn){
 const a=comparisonValues(db,item),b=comparisonValues(db,worn),labels=new Map();
 // Label = the template text before its value column; its % suffix is kept as the unit (was left inside the label).
 for(const [type]of [...instOptions(db,item),...instOptions(db,worn)]){const name=db.optionName(type)||'Option '+type,parts=optionLabelParts(optionTemplate(db,type)||name);labels.set(name,{label:parts.label||name,unit:parts.unit});}
 return [...new Set([...a.keys(),...b.keys()])].map(name=>({name,label:labels.get(name)?.label||name.replace(/^base:/,''),unit:labels.get(name)?.unit||'',value:a.get(name)||0,equipped:b.get(name)||0,delta:(a.get(name)||0)-(b.get(name)||0),direction:PENALTIES.has(name)?-1:BENEFICIAL.has(name)||name.startsWith('base:')?1:0}));
}
