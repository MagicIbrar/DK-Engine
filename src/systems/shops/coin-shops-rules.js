// COIN-SHOPS shared rules (client windows + host transaction, no DOM, no I/O).
//   coin exchange   job 164 EXCHANGE_RANKUP_EXP_COIN (Karin)  title 2006:24 "Coin Exchange Shop"
//     rankup        game2/exchangeshop/ui_rankupcoinexchangeshopwnd.txt  Rank-Up Coin (Bind) -> Grade (DK Rank) points
//     expup         game2/exchangeshop/ui_expupcoinexchangeshopwnd.txt   the six EXP coins -> character EXP
//   currency trade  job 165 EXCHANGE_GOLDITEM (Sinan)         title 2006:25 "Currency Exchange Shop"
//     sale          game2/exchangeshop/ui_cointradesalewnd.txt           gold items -> DIL (minus the fee)
//     purchase      game2/exchangeshop/ui_cointradepurchasewnd.txt       DIL -> gold items (plus the fee)
// The EXP and DIL amounts are the ones the item descriptions state (stringtable_item, cited per row); the rank points,
// the fees and the tab choices are engine choices in coin-shops-config.js.
import { COIN_SHOP_CONFIG as C } from './coin-shops-config.js';

export const COIN_SHOP_SCRIPTS = Object.freeze({
  rankup: 'game2/exchangeshop/ui_rankupcoinexchangeshopwnd.txt',
  expup: 'game2/exchangeshop/ui_expupcoinexchangeshopwnd.txt',
  sale: 'game2/exchangeshop/ui_cointradesalewnd.txt',
  purchase: 'game2/exchangeshop/ui_cointradepurchasewnd.txt',
});
export const COIN_SHOP_KINDS = Object.freeze(Object.keys(COIN_SHOP_SCRIPTS));
/** The NPC job each window belongs to (share/creature/jobtypeconfig.csv). */
export const COIN_SHOP_JOB = Object.freeze({ rankup: 164, expup: 164, sale: 165, purchase: 165 });
/** Tab buttons of each pair (both windows of a pair carry both buttons). */
export const COIN_SHOP_TABS = Object.freeze({
  rankup: { btn_showRankUpCoinWnd: 'rankup', btn_showExpUpCoinWnd: 'expup' },
  expup: { btn_showRankUpCoinWnd: 'rankup', btn_showExpUpCoinWnd: 'expup' },
  sale: { btn_showSaleWnd: 'sale', btn_showPurchaseWnd: 'purchase' },
  purchase: { btn_showSaleWnd: 'sale', btn_showPurchaseWnd: 'purchase' },
});
export const COIN_SHOP_ROWS = 5;   // coinitem_0..4 in every one of the four scripts
/** [itemIndex, value, item description code] - value = EXP (expup), DIL (sale / purchase). */
export const EXP_COINS = Object.freeze([
  [8718, 18750000, 553],    // Recruit EXP Coin       "18,750,000 points of experience ... NPC Karin"
  [8717, 28125000, 552],    // Regulars EXP Coin      "28,125,000 points"
  [8716, 37500000, 551],    // Guardsmen EXP Coin     "37,500,000 points"
  [8715, 56250000, 550],    // Guard Knight EXP Coin  "56,250,000 points"
  [8714, 75000000, 549],    // Knight EXP Coin        "75,000,000 points"
  [8713, 375000000, 548],   // Blue Knight EXP Coin   "375,000,000 points"
].map(Object.freeze));
export const RANK_COINS = Object.freeze([Object.freeze([8285, C.rankPointsPerCoin, 498])]);   // "exchange for DK Rank point at Karin"
export const GOLD_ITEMS = Object.freeze([
  [1750568, 10000000, 345],      // Gold Coin          "Exchange for 10,000,000 DIL at Sinan NPC in Ardeca."
  [1200027, 100000000, 260],     // Gold Bullion       "Sinan ... can exchange it for 100,000,000 DIL."
  [1200030, 1000000000, 1630],   // 1Billion Gold Bar  "Sinan will exchange this item for 1,000,000,000 DIL."
].map(Object.freeze));
export function coinRows(kind) {
  if (kind === 'rankup') return RANK_COINS;
  if (kind === 'expup') return EXP_COINS;
  if (kind === 'sale') return GOLD_ITEMS;
  if (kind === 'purchase') return C.purchaseSameAsSale ? GOLD_ITEMS : [];
  return [];
}
/** The strings the windows set themselves (the static captions come from the scripts). */
export const COIN_SHOP_STRINGS = Object.freeze({
  coinTitle: [2006, 24], tradeTitle: [2006, 25], material: [1001, 260], noDil: [340, 1], dilFull: [340, 7],
  bagFull: [340, 37], exchanged: [2006, 27],
});
export const MAX_HOST_DIL = 10_000_000_000;   // the host balance cap (server/world/inventory.mjs addDil)
/** Refusal texts: material / dil / dilFull / bagFull are the original strings (1001:260, 340:1, 340:7, 340:37). */
export const COIN_SHOP_ERRORS = Object.freeze({
  material: 'You do not have enough material items.',
  dil: 'You do not have enough dil.',
  dilFull: 'Your dil is reaching the maximum limit; you cannot sell items.',
  bagFull: 'You do not have enough space in your bag.',
  empty: C.emptyText,
  maxLevel: C.maxLevelText,
  invalid: 'Send a coin shop window and item counts only.',
});

/** Grade rows as the client Grade system (src/systems/life/grade.js) sees them: sorted, each with its cumulative cost. */
export function gradeRowsOf(list) {
  let cum = 0;
  return (list || []).slice().sort((a, b) => a.division - b.division || a.grade - b.grade)
    .map((r, i) => { cum += Math.max(0, Number(r.gradeExp) || 0); return { ...r, key: `${r.division}.${r.grade}`, cum, i }; });
}
/** Highest grade row reached with `total` Grade EXP at `level` (Grade.current). */
export function gradeAt(rows, total, level) {
  let cur = rows[0] || null;
  for (const r of rows) { if (total >= r.cum && level >= (r.levelLimit || 0)) cur = r; else break; }
  return cur;
}
/** {cur, need, frac} toward the next row (Grade.progress). */
export function gradeProgress(rows, total, level) {
  const cur = gradeAt(rows, total, level), next = cur ? rows[cur.i + 1] : rows[0];
  if (!next) return { cur: 1, need: 1, frac: 1 };
  const base = cur?.cum || 0, need = Math.max(1, next.cum - base);
  return { cur: total - base, need: next.cum - base, frac: Math.max(0, Math.min(1, (total - base) / need)) };
}
/** Rows reached by going from `before` to `after` Grade EXP (their one-time stat / skill gifts are granted once). */
export function gradeRowsReached(rows, before, after, level) {
  const a = gradeAt(rows, before, level)?.i ?? -1, b = gradeAt(rows, after, level)?.i ?? -1;
  return rows.filter(r => r.i > a && r.i <= b);
}
/** Level / EXP after gaining `gain` EXP (the host grantProgress loop). */
export function levelAfter(level, exp, gain, expNeeded, maxLevel) {
  let L = Math.max(1, Number(level) || 1), E = Math.max(0, Number(exp) || 0) + Math.max(0, gain);
  while (L < maxLevel) { const need = expNeeded(L); if (!(need > 0) || !Number.isFinite(need) || E < need) break; E -= need; L++; }
  return { level: L, exp: E, frac: L >= maxLevel ? 1 : Math.max(0, Math.min(1, E / Math.max(1, expNeeded(L) || 1))) };
}
export const feeOf = (dil, percent) => Math.floor(Math.max(0, dil) * Math.max(0, Number(percent) || 0) / 100);

/** Validate a counts list [[itemIndex, count], ...] against the window kind: zero rows dropped, duplicates merged. */
export function cleanCounts(kind, counts) {
  const allowed = new Map(coinRows(kind).map(r => [r[0], r]));
  if (!Array.isArray(counts) || counts.length > COIN_SHOP_ROWS * 4) return { error: 'invalid' };
  const out = new Map();
  for (const row of counts) {
    if (!Array.isArray(row) || row.length !== 2 || !Number.isInteger(row[0]) || !Number.isInteger(row[1]) || row[1] < 0 || row[1] > C.maxPerRow) return { error: 'invalid' };
    if (!allowed.has(row[0])) return { error: 'invalid' };
    if (row[1] > 0) out.set(row[0], (out.get(row[0]) || 0) + row[1]);
  }
  for (const n of out.values()) if (n > C.maxPerRow) return { error: 'invalid' };
  const rows = [...out].map(([index, n]) => ({ index, n, value: allowed.get(index)[1] }));
  return rows.length ? { rows } : { error: 'empty' };
}

/**
 * The whole exchange as numbers. ctx: {have(index), dil, level, exp, maxLevel, expNeeded(level), grades (gradeRowsOf),
 * gradeExp, dilCap}. Returns {ok:false, error} (invalid / empty / material / dil / dilFull / maxLevel) or
 * {ok:true, kind, spend:[[i,n]], give:[[i,n]], exp, points, dilIn, dilOut, fee, before, after}.
 */
export function coinQuote(kind, counts, ctx) {
  if (!COIN_SHOP_KINDS.includes(kind)) return { ok: false, error: 'invalid' };
  const clean = cleanCounts(kind, counts);
  if (clean.error) return { ok: false, error: clean.error };
  const dil = Math.max(0, Number(ctx.dil) || 0), cap = ctx.dilCap ?? MAX_HOST_DIL;
  const level = Math.max(1, Number(ctx.level) || 1), exp = Math.max(0, Number(ctx.exp) || 0), total = Math.max(0, Number(ctx.gradeExp) || 0);
  const sum = clean.rows.reduce((a, r) => a + r.n * r.value, 0);
  const q = { ok: true, kind, spend: [], give: [], exp: 0, points: 0, dilIn: 0, dilOut: 0, fee: 0, before: { dil, level, exp, gradeExp: total } };
  if (kind !== 'purchase') {
    for (const r of clean.rows) if ((Number(ctx.have(r.index)) || 0) < r.n) return { ok: false, error: 'material' };
    q.spend = clean.rows.map(r => [r.index, r.n]);
  }
  if (kind === 'expup') {
    const maxLevel = Number(ctx.maxLevel) || 250;
    if (level >= maxLevel) return { ok: false, error: 'maxLevel' };
    q.exp = sum;
    const after = levelAfter(level, exp, sum, ctx.expNeeded, maxLevel);
    q.after = { dil, level: after.level, exp: after.exp, frac: after.frac, gradeExp: total };
  } else if (kind === 'rankup') {
    q.points = sum;
    const rows = ctx.grades || [];
    const row = gradeAt(rows, total + sum, level);
    q.after = { dil, level, exp, gradeExp: total + sum, grade: row, progress: gradeProgress(rows, total + sum, level), reached: gradeRowsReached(rows, total, total + sum, level) };
  } else if (kind === 'sale') {
    q.fee = feeOf(sum, C.saleFeePercent); q.dilIn = sum - q.fee;
    if (dil + q.dilIn > cap) return { ok: false, error: 'dilFull' };
    q.after = { dil: dil + q.dilIn, level, exp, gradeExp: total };
  } else {
    q.fee = feeOf(sum, C.purchaseFeePercent); q.dilOut = sum + q.fee;
    if (q.dilOut > dil) return { ok: false, error: 'dil' };
    q.give = clean.rows.map(r => [r.index, r.n]);
    q.after = { dil: dil - q.dilOut, level, exp, gradeExp: total };
  }
  q.gross = sum;
  return q;
}
/** Largest count for one row with the other rows' counts kept (Max button). */
export function maxCount(kind, index, counts, ctx) {
  const row = coinRows(kind).find(r => r[0] === index);
  if (!row) return 0;
  if (kind !== 'purchase') return Math.max(0, Math.min(C.maxPerRow, Number(ctx.have(index)) || 0));
  const others = (counts || []).filter(r => r[0] !== index).reduce((a, [i, n]) => a + n * (coinRows(kind).find(x => x[0] === i)?.[1] || 0), 0);
  const dil = Math.max(0, Number(ctx.dil) || 0);
  const cost = n => { const s = others + n * row[1]; return s + feeOf(s, C.purchaseFeePercent); };
  let n = Math.min(C.maxPerRow, Math.floor(Math.max(0, dil - others) / row[1]));
  while (n > 0 && cost(n) > dil) n--;
  return n;
}