// Shift option ranges (original stringtable_itemdesc 910:17 "Press SHIFT key to view range of possible Rank & Brand
// Option values.", headers 701:2 / 901:2). A saved pair gets a bound pair only when the original tables prove it:
// never an envelope over differing rows or levels, never an inferred Soul Stone level, never a custom (900000000+) item.
//  Rank: rnd[i] was rolled from authored pool [0,0,1,2][i] (MinOption1..3/MaxOption1..3 = def.optionPools; model.js
//   rollOptions, server craft 'option'). Every itemoption row of that type in that pool must carry the same
//   MinData/MaxData. A pool that can drop a roll (a 0 value, an empty level) makes every later ordinal ambiguous.
//  Brand: brand[i] keeps [type,value] but not its Soul Stone level (any stone 1..250 can brand). Every
//   itemincuseoption.csv level offering the type must agree after the incuseoption.csv MaxCapacityLimit cap that
//   branding applies, e.g. ANTI_ANTI_RATE 1~3 at all 71 levels; DEFENSE_MIN_ADD 1~9 (level 1) vs 1~10 (level 2) never.
const poolCache = new WeakMap(), brandCache = new WeakMap();
const ORDINAL_POOL = [0, 0, 1, 2];
const NONE = Object.freeze({ rank: null, brand: null, complete: false });
const bounds = (min, max) => Number.isSafeInteger(min) && Number.isSafeInteger(max) && min <= max ? Object.freeze([min, max]) : null;
const same = (a, b) => !!a && !!b && a[0] === b[0] && a[1] === b[1];
const owned = (pair, b) => Array.isArray(pair) && pair.length === 2 && Number.isSafeInteger(pair[0]) && Number.isSafeInteger(pair[1]) && !!b && pair[1] >= b[0] && pair[1] <= b[1] ? b : null;
// The engine's branding eligibility (ui/enchant.js brandable, used by server/world/enhancement.mjs). Kept here because
// enchant.js reaches tooltip.js through craft.js; tools/test-item-shift-ranges.mjs pins the two equal for every item.
const brandable = def => { const t = Number(def?.type), c = Number(def?.code); return (t === 4 && ![15, 16, 19, 30, 31, 33].includes(c)) || (t === 5 && (c <= 4 || [11, 12, 15, 16].includes(c))); };

/** One authored pool [lo, hi] of a pools table: {types: Map(type -> unanimous bounds | null), skips}, cached. */
function poolInfo(pools, pool) {
  let byPool = poolCache.get(pools);
  if (!byPool) poolCache.set(pools, byPool = new Map());
  const [first, last] = Array.isArray(pool) ? pool : [], lo = first || last, key = `${lo}:${last}`;
  if (byPool.has(key)) return byPool.get(key);
  let info = null;
  if (Number.isSafeInteger(lo) && Number.isSafeInteger(last) && lo > 0 && last >= lo && last - lo <= 4096) {
    const types = new Map();
    let skips = false;
    for (let level = lo; level <= last; level++) {
      const rows = pools[level];
      if (!Array.isArray(rows) || !rows.length) { skips = true; continue; }
      for (const row of rows) {
        const type = Number(row?.[1]), next = bounds(Number(row?.[2]), Number(row?.[3]));
        if (next && next[0] <= 0 && next[1] >= 0) skips = true;   // a rolled 0 is dropped, shifting later ordinals
        if (!Number.isSafeInteger(type)) continue;
        if (!types.has(type)) types.set(type, next);
        else if (!same(types.get(type), next)) types.set(type, null);
      }
    }
    info = { types, skips };
  }
  byPool.set(key, info);
  return info;
}

function rankRanges(db, def, rnd) {
  const pools = db.options?.pools, authored = def.optionPools;
  if (!pools || !Array.isArray(authored) || rnd.length > ORDINAL_POOL.length) return null;
  const out = [];
  for (let i = 0; i < rnd.length; i++) {
    for (let j = 0; j < i; j++) { const prior = poolInfo(pools, authored[ORDINAL_POOL[j]]); if (!prior || prior.skips) return null; }
    const info = poolInfo(pools, authored[ORDINAL_POOL[i]]), pair = rnd[i];
    const b = info && Array.isArray(pair) ? owned(pair, info.types.get(pair[0]) ?? null) : null;
    if (!b) return null;
    out.push(b);
  }
  return out;
}

/** Map(type -> bounds shared by every brand level offering it | null), cached per loaded tables object. */
function brandTable(db) {
  const T = db.T, levels = T?.incuseOptionLevels?.rows, options = T?.incuseOption?.rows, types = db.options?.optionTypes;
  if (!Array.isArray(levels) || !Array.isArray(options)) return null;
  const prior = brandCache.get(T);
  if (prior && prior.levels === levels && prior.options === options && prior.types === types) return prior.ranges;
  const byNo = new Map(options.map(row => [Number(row.No), row])), ranges = new Map();
  for (const row of levels) for (let k = 1; k <= Number(row.count || 0); k++) {
    const option = byNo.get(Number(row[`Value${k}`])), type = option ? db.optionCode?.(option.Option) : null;
    if (!Number.isSafeInteger(type)) continue;   // the symbolic SIZEDAMAGERATE_BOSS_MUL has no numeric pair to match
    const next = bounds(Number(row[`DataMin${k}`]), Math.min(Number(row[`DataMax${k}`]), Number(option.MaxCapacityLimit) || Infinity));
    if (!ranges.has(type)) ranges.set(type, next);
    else if (!same(ranges.get(type), next)) ranges.set(type, null);
  }
  brandCache.set(T, { levels, options, types, ranges });
  return ranges;
}

/** {rank, brand, complete}: a section is an array of [min, max] per stored pair only when every pair resolves. */
export function itemOptionRanges(db, inst) {
  const def = db?.def?.(inst?.itemIndex);
  if (!def || !(Number(def.index) < 900000000)) return NONE;
  const rnd = Array.isArray(inst.rnd) && inst.rnd.length ? inst.rnd : null;
  const pairs = Array.isArray(inst.brand) && inst.brand.length ? inst.brand : null;
  const rank = rnd ? rankRanges(db, def, rnd) : null;
  let brand = null;
  if (pairs && pairs.length <= 4 && brandable(def)) {
    const table = brandTable(db);
    const out = table ? pairs.map(pair => owned(pair, Array.isArray(pair) ? table.get(pair[0]) ?? null : null)) : [];
    brand = out.length && out.every(Boolean) ? out : null;
  }
  return { rank, brand, complete: !!(rnd || pairs) && (!rnd || !!rank) && (!pairs || !!brand) };
}
export { brandable as rangeBrandable };
