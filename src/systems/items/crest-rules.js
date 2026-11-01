export const CREST_SOURCE_FILES=['share/item/itemmunzang_option.csv','share/item/itemmunzang_incuse.csv'];
/** The second English header carries item identity and group; the first localized header leaves them blank. */
export function parseCrestSource(rows,source) {
  const start=rows.findIndex(row=>row.includes('Item_Index')&&row.includes('Munzang_group'));
  if(start<0)return [];
  const header=rows[start];return rows.slice(start+1).flatMap(values=>{
    const row=Object.fromEntries(header.map((key,index)=>[key,String(values[index]??'').trim()]));
    if(['Item_Index','Munzang_group','Type','MinData','MaxData'].some(key=>!row[key]))return [];
    return [{itemIndex:Number(row.Item_Index),group:Number(row.Munzang_group),type:row.Type,min:Number(row.MinData),max:Number(row.MaxData),source}];
  }).filter(row=>Number.isSafeInteger(row.itemIndex)&&row.itemIndex>0&&Number.isInteger(row.group)&&row.group>=1&&row.group<=4&&row.type&&Number.isSafeInteger(row.min)&&Number.isSafeInteger(row.max)&&row.max>=row.min);
}
export async function loadCrestSources(readRows) {
  return (await Promise.all(CREST_SOURCE_FILES.map(async source=>parseCrestSource(await readRows(source),source)))).flat();
}
// Native option identities with live stat/combat/skill/reward consumers. The four
// generic Group prototypes have no concrete original option and remain refused.
// Native factors/caps are used by the declared engine combat reconstruction;
// admitting an authored crest never substitutes a caption for its native enum.
export const CREST_SUPPORTED_EFFECTS=new Set([
  'STAT_STR_ADD','STAT_DEX_ADD','STAT_CON_ADD','STAT_SPR_ADD','HP_MAX_ADD','MP_MAX_ADD','RATING_ATTACK_ADD','BALANCE_MARK_ADD','DEFENSE_MIN_ADD','ARMOR_ADD',
  'DAMAGE_PHYSICAL_MUL','DAMAGE_PHYSICAL_SUB','RANGE_DAMAGE_RANGECAL_MUL','RANGE_DAMAGE_RANGECAL_SUB','DAMAGE_MAGICAL_MUL','DAMAGE_MAGICAL_SUB','DAMAGE_MINPHYSICAL_ADD',
  'DEFENSE_MUL','DEFENSE_SUB','DEFENSE_ADD','BALANCE_GUARD_ADD','SPEED_ATTACK_MUL','SPEED_ATTACK_SUB','SPEED_MOVE_MUL','SPEED_MOVE_SUB','HP_RECOVERY_ADD','MP_RECOVERY_ADD',
  'DAMAGE_MAXPHYSICAL_ADD','DAMAGE_MINMAGICAL_ADD','DAMAGE_MAXMAGICAL_ADD','RANGE_DAMAGE_MINRANGECAL_ADD','RANGE_DAMAGE_MAXRANGECAL_ADD',
  'HP_MAX_MUL','MP_MAX_MUL','RATING_BLOCKING_ADD','BALANCE_BLOCKING_ADD','RATING_CRITICAL_ADD','BALANCE_DEATHBLOW_ADD','DAMAGERATE_CRITICAL_ADD','BALANCE_MAGIC_REGIST_ADD','RESIST_MAGIC_ADD','BALANCE_VITALITY_ADD',
  'POSITIVE_FIRERESIST_ADD','POSITIVE_ICERESIST_ADD','POSITIVE_LIGHTNINHRESIST_ADD','POSITIVE_POISONRESIST_ADD','POSITIVE_CURSERESIST_ADD','POSITIVE_DARKRESIST_ADD','POSITIVE_ALLRESIST_ADD',
  'DAMAGEADD_FIRE_ADD','DAMAGEADD_ICE_ADD','DAMAGEADD_LIGHTNING_ADD','DAMAGEADD_POISON_ADD','DAMAGEADD_CURSE_ADD','DAMAGEADD_DARK_ADD','RESULT_EXP_MUL',
  'SPEED_COOLTIME_MUL','SPEED_CASTING_MUL','MP_RESERVED_6','SIZEDAMAGERATE_BOSS_ADD','SIZEDAMAGERATE_RESERVED_5',
  'MP_DECREASE_SPENDRESOURCE','SHIELD_MAX_ADD','SHIELD_MAX_MUL','SHIELD_RECOVERY_ADD','RATING_GUARD_ADD',
  'COMBINE_OPTION_COMBINE_ADD','COMBINE_OPTION_COMBINE_MUL','COMBINE_OPTION_COMBINE_SUB',
  'DAMAGERATE_FIRE_ADD','DAMAGERATE_ICE_ADD','DAMAGERATE_LIGHTNING_ADD','DAMAGERATE_POISON_ADD','DAMAGERATE_CURSE_ADD','DAMAGERATE_DARK_ADD',
  'RESIST_DISTANCE_MELEEDAMAGE','RESIST_DISTANCE_RANGEDAMAGE','RATING_CRITICAL_SUB','DAMAGERATE_EX_CRITICAL_SUB',
  'DAMAGERATE_DAMAGEHP_MUL','DAMAGE_OWNERSHIP','HP_FLUCTUATE_PLUSE_MUL','KNIGHT_SPECIAL_MONSTER_TOLERANCE','KNIGHT_SPECIAL_PC_TOLERANCE',
  'PC_DAMAGE_DAMAGE_ADD','PC_DAMAGE_DAMAGE_MUL','PC_DAMAGE_ARMOR_ADD','PC_DAMAGE_ALLMAGICRESIST_ADD','PC_DAMAGE_ALLMAGICRESIST_MUL',
  'PVPDAMAGE_PVP_DAMAGE_ADD','PVPDAMAGE_PVP_DAMAGERATE_ADD','RATING_ANTI_STATUS_ADD','ANTI_ANTI_RATE',
  'PENETRATE_PHYSICAL','PENETRATE_MAGICAL','SIZEDAMAGERATE_BOSS_MUL','SPELL_ADD_RATE',
  'STATUS_EX_CRITICAL_RESIST_DOWN','STATUS_EX_SPEED_SKILL_MUL','STATUS_EX_COMPETENCE','DEFENSE_DEFEATRATE_MUL',
]);

// Eight authored green HP/MP/movement crests have no munzang_price.csv row.
// ENGINE-CHOSEN: use 100,000 DIL for those exact IDs, matching the ordinary
// green insertion price. Native exceptional prices on every other item win.
// This is not a claim that the source defines a price for the eight omissions.
export const ENGINE_CHOSEN_CREST_INSERT_DIL=Object.freeze(Object.fromEntries(
  Array.from({length:8},(_,i)=>[4501949+i,100000])));
export function crestInsertPrice(db,tables,def) {
  const rows=tables?.crestPrice?.rows?.filter(row=>Number(row.Index)===Number(def?.index))||[];
  if(!rows.length){
    const fallback=Number(def?.type)===1&&Number(def?.code)===23?ENGINE_CHOSEN_CREST_INSERT_DIL[def.index]:undefined;
    return fallback==null?{error:'missing'}:{dil:fallback,engineChosen:true};
  }
  const values=rows.map(row=>row.Price);
  if(values.some(value=>value==null||value===''||!Number.isSafeInteger(Number(value))||Number(value)<0||Number(value)>10000000000))return {error:'value'};
  const prices=new Set(values.map(Number));
  return prices.size===1?{dil:[...prices][0],engineChosen:false}:{error:'ambiguous'};
}

/**
 * Crest EXTRACTION price. The client ships no removal-price table (munzang_price.csv holds the INSERT prices: green 100,000 /
 * blue 200,000 / purple 500,000 / orange 1,000,000 for the authored crests), but its window refuses with 311:32 "The price of
 * removing this crest is unknown." and 311:33 "You don't have enough DIL.", so removal is priced. The official Global Crest
 * guide (webapi-dekaron.ubifungames.com GetGameGuidePost guideNo=16, "Using a crest extraction system") gives the price per
 * crest grade: Green 1,000,000 / Blue 2,000,000 / Purple 4,000,000 / Orange 5,000,000 DIL, and the Hot Plier ([Heated Flyer])
 * returns every crest "without consuming DIL". Keyed by the crest item code (type 1, codes 23-26 = green/blue/purple/orange).
 */
export const CREST_EXTRACT_DIL=Object.freeze({23:1_000_000,24:2_000_000,25:4_000_000,26:5_000_000});
export const CREST_EXTRACT_TEXT=Object.freeze({unknown:'The price of removing this crest is unknown.',dil:'You don’t have enough DIL.'}); // 311:32, 311:33
/** DIL for removing the crests whose item definitions are `defs`; 0 with a Hot Plier; null when a crest grade is unknown (311:32). */
export function crestExtractDil(defs,{hotPlier=false}={}) {
  let total=0;
  for(const def of defs) {
    const price=Number(def?.type)===1?CREST_EXTRACT_DIL[Number(def?.code)]:undefined;
    if(!Number.isSafeInteger(price))return null;
    total+=price;
  }
  return hotPlier?0:total;
}
/**
 * DELIBERATE ENGINE CHOICE (pre-existing value, now named): chance that an extraction WITHOUT a Plier returns the crest.
 * The guide only says extraction "is probability-based" (failure: the crest disappears, the slot is emptied) and 311:48 warns
 * "Unless a Plier is not used Crest may disappear"; no original rate is shipped or published. A Plier / Hot Plier returns 100 %.
 */
export const ENGINE_CHOSEN_UNPROTECTED_CREST_KEEP_RATE=0.5;

/** Prefer exact original Item_Index/group associations over offset or name-derived solo fallbacks. */
export function crestRule(db,tables,def) {
  if(Number(def?.type)!==1||![23,24,25,26].includes(Number(def?.code)))return null;
  const exact=db.crestSources?.filter(row=>row.itemIndex===Number(def?.index));
  if(exact?.length) {
    const row=exact[0];
    if(exact.some(other=>['group','type','min','max'].some(key=>other[key]!==row[key]))||Number(def.type)!==1||Number(def.code)!==row.group+22)return null;
    return row;
  }
  const row=tables?.crestOption?.rows?.find(row=>Number(row.index)===Number(def?.index)-4500000);
  if(row)return row;
  const match=/^(.*?)\s+(\d+)\s*(%)?$/.exec(def?.name||'');if(!match)return null;
  const label=match[1].trim().toLowerCase(),percent=!!match[3];
  const options=Object.values(db.options?.optionTypes||{}).filter(option=>String(option.label||'').toLowerCase()===label&&String(option.text||'').includes('%')===percent);
  if(options.length!==1)return null;
  return {type:options[0].name,min:Number(match[2]),max:Number(match[2])};
}
