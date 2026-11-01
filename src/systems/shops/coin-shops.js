// COIN-SHOPS client windows (rules: coin-shops-rules.js, engine choices: coin-shops-config.js):
//   coinrankup    game2/exchangeshop/ui_rankupcoinexchangeshopwnd.txt  job 164 (Karin) Rankup Coin tab
//   coinexpup     game2/exchangeshop/ui_expupcoinexchangeshopwnd.txt   job 164 Exp Coin tab
//   coinsale      game2/exchangeshop/ui_cointradesalewnd.txt           job 165 (Sinan) Sell tab
//   coinpurchase  game2/exchangeshop/ui_cointradepurchasewnd.txt       job 165 Buy tab
// Each window: pan_charinfo (class / name / level / rank, DIL), pan_exItemList (five rows: coinitem_N icon,
// lbl_coinitemName_N, edit_coinitemCnt_N with Reset / - / + / Max, body_scroll) and pan_resExchange (what the exchange
// gives, gauges or DIL lines) with btn_exchange. The two tab buttons swap to the pair window. Online the host
// (server/world/coin-shops.mjs, action 'coinshop') prices and commits the exchange; single-player applies the same quote.
import { itemInfo, itemInfoFull, itemIcon, itemTooltip, bag, dil, addDil, str, say, notice, confirmBox, fmtNum, MAX_DIL } from './common.js';
import { grantExp, expToNext, maxLevelOf, formulaOf } from '../../game/progression.js';
import { COIN_SHOP_SCRIPTS, COIN_SHOP_KINDS, COIN_SHOP_TABS, COIN_SHOP_ROWS as ROWS, COIN_SHOP_STRINGS as S, COIN_SHOP_ERRORS,
  coinRows, coinQuote, maxCount, feeOf, gradeAt, gradeProgress, levelAfter } from './coin-shops-rules.js';
import { COIN_SHOP_CONFIG as C } from './coin-shops-config.js';
import {atlas} from '../../ui/atlas.js';
import {repairNativeShopStateArt} from '../../ui/native-shop-state-art.js';

export const COIN_SHOP_WINDOWS = Object.freeze({ rankup: 'coinrankup', expup: 'coinexpup', sale: 'coinsale', purchase: 'coinpurchase' });
const PAIR_OF = { rankup: ['rankup', 'expup'], expup: ['rankup', 'expup'], sale: ['sale', 'purchase'], purchase: ['sale', 'purchase'] };
const pct = f => `${((Number(f) || 0) * 100).toFixed(2)}%`;
const strip = s => String(s || '').replace(/^\[message\]\s*/i, '');

export function createCoinShops(game, api = {}) {
  const st = { kind: null, npc: null, counts: {}, top: {}, wins: {}, tok: 0 };
  for (const k of COIN_SHOP_KINDS) { st.counts[k] = {}; st.top[k] = 0; }
  const online = () => game.save?.authority === 'server';
  const s = () => game.save || {};
  const gradeSys = () => game.life?.grade || null;
  const gradeRows = () => { try { return gradeSys()?.rows || []; } catch { return []; } };
  const gradeTotal = () => Number(s().life?.grade?.totalExp) || 0;
  const list = kind => coinRows(kind);
  const ctx = () => ({ have: i => bag.count(game, i), dil: dil(game), level: Number(s().level) || 1, exp: Number(s().exp) || 0,
    maxLevel: maxLevelOf(game.data) || 250, expNeeded: l => expToNext(l, game.data), grades: gradeRows(), gradeExp: gradeTotal(),
    dilCap: online() ? undefined : MAX_DIL });
  const countsOf = kind => Object.entries(st.counts[kind]).map(([i, n]) => [Number(i), n]).filter(([, n]) => n > 0);
  const rowAt = (kind, r) => list(kind)[st.top[kind] + r] || null;
  const errText = e => ({ material: str(game, ...S.material, COIN_SHOP_ERRORS.material), dil: str(game, ...S.noDil, COIN_SHOP_ERRORS.dil),
    dilFull: str(game, ...S.dilFull, COIN_SHOP_ERRORS.dilFull), bagFull: strip(str(game, ...S.bagFull, COIN_SHOP_ERRORS.bagFull)) })[e] || COIN_SHOP_ERRORS[e] || COIN_SHOP_ERRORS.invalid;
  const titleOf = kind => str(game, ...(kind === 'sale' || kind === 'purchase' ? S.tradeTitle : S.coinTitle), '');

  for (const kind of COIN_SHOP_KINDS) {
    game.uiwin.registerWindow(COIN_SHOP_WINDOWS[kind], {
      script: COIN_SHOP_SCRIPTS[kind],
      create(win) { setup(kind, win); },
      async onOpen(win, arg) {
        st.kind = kind; if (arg?.npc !== undefined) st.npc = arg.npc;
        st.counts[kind] = {}; st.top[kind] = 0;
        await Promise.all(list(kind).map(r => itemInfoFull(game, r[0]).catch(() => null)));
        render(kind);
      },
      onClose() { game.uiwin.tooltips?.hide?.(); if (st.kind === kind) st.kind = null; },
    });
  }

  function setup(kind, win) {
    st.wins[kind] = win;
    if(kind==='rankup')repairNativeShopStateArt(win.find('btn_plus_2'),'coinPlus',atlas.table);
    win.find('btn_close')?.onClick?.(() => win.close());
    for (const [btn, to] of Object.entries(COIN_SHOP_TABS[kind])) win.find(btn)?.onClick?.(() => (to !== kind ? open(to, st.npc) : null));
    for (let r = 0; r < ROWS; r++) {
      const edit = win.find(`edit_coinitemCnt_${r}`);
      edit?.on?.('change', () => setCount(kind, r, Number(String(edit.getValue?.() ?? '').replace(/\D/g, '')) || 0, false));
      win.find(`btn_init_${r}`)?.onClick?.(() => setCount(kind, r, 0));
      win.find(`btn_minus_${r}`)?.onClick?.(() => setCount(kind, r, countAt(kind, r) - 1));
      win.find(`btn_plus_${r}`)?.onClick?.(() => setCount(kind, r, countAt(kind, r) + 1));
      win.find(`btn_max_${r}`)?.onClick?.(() => setCount(kind, r, maxAt(kind, r)));
      const slot = win.find(`coinitem_${r}`);
      slot?.el?.addEventListener?.('pointerenter', ev => { const row = rowAt(kind, r); if (row) game.uiwin.tooltips?.show?.(itemTooltip(game, row[0]), ev.clientX, ev.clientY); });
      slot?.el?.addEventListener?.('pointerleave', () => game.uiwin.tooltips?.hide?.());
    }
    win.find('body_scroll')?.on?.('change', v => { st.top[kind] = Math.max(0, Math.min(Math.max(0, list(kind).length - ROWS), Number(v) || 0)); render(kind); });
    win.find('btn_exchange')?.onClick?.(() => exchange(kind));
    // coinitem_5..9 are stray item slots stacked on row 0 (same rect, no name / count controls): never shown
    for (let r = ROWS; r < 10; r++) win.find(`coinitem_${r}`)?.setVisible?.(false);
    if (kind === 'expup' && !str(game, 1001, 241, '')) win.find('lbl_tagDil')?.setText?.(C.dilTagText);
  }
  const countAt = (kind, r) => { const row = rowAt(kind, r); return row ? st.counts[kind][row[0]] || 0 : 0; };
  const maxAt = (kind, r) => { const row = rowAt(kind, r); return row ? maxCount(kind, row[0], countsOf(kind), ctx()) : 0; };
  function setCount(kind, r, n, rewrite = true) {
    const row = rowAt(kind, r); if (!row) return 0;
    const v = Math.max(0, Math.min(maxAt(kind, r), Math.floor(Number(n) || 0)));
    st.counts[kind][row[0]] = v;
    const edit = st.wins[kind]?.find(`edit_coinitemCnt_${r}`);
    if (rewrite || String(edit?.getValue?.() ?? '') !== String(v)) edit?.setValue?.(String(v));
    summary(kind);
    return v;
  }

  // ------------------------------------------------------------------------------------------ painting
  function render(kind) {
    const w = st.wins[kind]; if (!w) return;
    const tok = ++st.tok, sv = s();
    const cls = game.classDef || game.data?.classByIndex?.get?.(Number(sv.classIndex)) || null;
    w.find('lbl_class')?.setText?.(cls?.name || sv.className || '');
    w.find('lbl_name')?.setText?.(sv.name || game.player?.name || '');
    w.find('lbl_level')?.setText?.(fmtNum(sv.level || 1));
    let gname = ''; try { gname = gradeSys()?.current?.()?.name || ''; } catch { /* no grade system */ }
    w.find('lbl_grade')?.setText?.(gname);
    const rows = list(kind), sc = w.find('body_scroll');
    sc?.setRange?.(Math.max(0, rows.length - ROWS), ROWS);
    for (let r = 0; r < ROWS; r++) {
      const row = rowAt(kind, r), on = !!row;
      for (const id of [`coinitem_${r}`, `lbl_coinitemName_${r}`, `edit_coinitemCnt_${r}`, `btn_init_${r}`, `btn_minus_${r}`, `lbl_cntbg_${r}`, `btn_plus_${r}`, `btn_max_${r}`]) w.find(id)?.setVisible?.(on);
      if (!on) continue;
      const name = itemInfo(game, row[0])?.name || '';
      w.find(`lbl_coinitemName_${r}`)?.setText?.(kind === 'purchase' ? `${name} (${fmtNum(row[1])})` : `${name} (${fmtNum(bag.count(game, row[0]))})`);
      w.find(`edit_coinitemCnt_${r}`)?.setValue?.(String(st.counts[kind][row[0]] || 0));
      const slot = w.find(`coinitem_${r}`);
      slot?.setIcon?.(null);
      Promise.resolve(itemIcon(game, row[0], 32, 32)).then(ic => { if (tok === st.tok && rowAt(kind, r) === row) slot?.setIcon?.(ic); }).catch(() => {});
    }
    summary(kind);
  }
  /** The right panel: what the current counts would give (shown even when the exchange would be refused). */
  function preview(kind) {
    const c = ctx(), counts = countsOf(kind), values = new Map(list(kind).map(r => [r[0], r[1]]));
    const gross = counts.reduce((a, [i, n]) => a + n * (values.get(i) || 0), 0);
    if (kind === 'rankup') {
      const rows = c.grades, total = c.gradeExp;
      return { gross, cur: gradeProgress(rows, total, c.level), after: gradeProgress(rows, total + gross, c.level), grade: gradeAt(rows, total + gross, c.level) };
    }
    if (kind === 'expup') {
      const need = c.expNeeded(c.level), cur = c.level >= c.maxLevel ? 1 : Math.max(0, Math.min(1, c.exp / Math.max(1, need || 1)));
      return { gross, cur: { frac: cur }, after: levelAfter(c.level, c.exp, gross, c.expNeeded, c.maxLevel) };
    }
    const fee = feeOf(gross, kind === 'sale' ? C.saleFeePercent : C.purchaseFeePercent);
    return { gross, fee, dil: c.dil, left: kind === 'sale' ? c.dil + gross - fee : c.dil - gross - fee };
  }
  function summary(kind) {
    const w = st.wins[kind]; if (!w) return null;
    const p = preview(kind);
    if (kind === 'rankup') {
      w.find('lbl_getGradeDesc')?.setText?.(p.grade?.name || '');
      w.find('lbl_getGradeExpPoint')?.setText?.(fmtNum(p.gross));
      w.find('lbl_GradeExp')?.setText?.(`${fmtNum(Math.max(0, p.after.cur))} / ${fmtNum(p.after.need)} (${pct(p.after.frac)})`);
      w.find('pro_curGradeExp')?.setGauge?.(p.cur.frac || 0);
      w.find('pro_getGradeExp')?.setGauge?.(p.after.frac || 0);
    } else if (kind === 'expup') {
      w.find('lbl_dil')?.setText?.(fmtNum(dil(game)));
      w.find('lbl_getGradeDesc')?.setText?.(fmtNum(p.after.level));
      w.find('lbl_getExpPoint')?.setText?.(fmtNum(p.gross));
      w.find('lbl_GradeExp')?.setText?.(pct(p.after.frac));
      w.find('pro_curGradeExp')?.setGauge?.(p.cur.frac || 0);
      w.find('pro_getGradeExp')?.setGauge?.(p.after.frac || 0);
    } else {
      w.find('lbl_dil')?.setText?.(fmtNum(p.dil));
      w.find(kind === 'sale' ? 'lbl_saleDil' : 'lbl_purchaseDil')?.setText?.(fmtNum(p.gross));
      w.find('lbl_saleFee')?.setText?.(fmtNum(p.fee));
      w.find('lbl_getDil')?.setText?.(p.left < 0 ? `-${fmtNum(-p.left)}` : fmtNum(p.left));
    }
    return p;
  }

  // ------------------------------------------------------------------------------------------ exchange
  function rawExp(amount) {
    // exactly the coin's EXP: no formula / event / premium multipliers (the same guard as the GM level command)
    const F = formulaOf(game.data), saved = F.fMonEXPRatio, mods = game.expModifiers, settings = game.settings || (game.settings = {}), er = settings.expRate;
    game.expModifiers = []; settings.expRate = 1;
    try { F.fMonEXPRatio = 1; return grantExp(game, amount); }
    finally { F.fMonEXPRatio = saved; game.expModifiers = mods; if (er === undefined) delete settings.expRate; else settings.expRate = er; }
  }
  async function exchange(kind) {
    const counts = countsOf(kind), q = coinQuote(kind, counts, ctx());
    if (!q.ok) { await notice(game, errText(q.error), titleOf(kind)); return false; }
    if (kind === 'purchase' && !(typeof bag.canAddAll === 'function' ? bag.canAddAll(game, q.give) : q.give.every(([i, n]) => bag.canAdd(game, i, n)))) { await notice(game, errText('bagFull'), titleOf(kind)); return false; }
    if (await confirmBox(game, C.confirmText, titleOf(kind)) !== 'yes') return false;
    if (online()) {
      const result = await game.network?.action?.('coinshop', { operation: kind, rows: counts });
      if (!result) return false;
    } else {
      for (const [i, n] of q.spend) if (!bag.remove(game, i, n)) { await notice(game, errText('material'), titleOf(kind)); return false; }
      for (const [i, n] of q.give) bag.add(game, i, n, { from: 'coinshop' });
      if (q.dilIn || q.dilOut) addDil(game, q.dilIn - q.dilOut);
      if (q.exp > 0) rawExp(q.exp);
      if (q.points > 0) gradeSys()?.addExp?.(q.points);
      game.persist?.();
    }
    for (const [i, n] of [...q.spend, ...q.give]) say(game, str(game, ...S.exchanged, 'You have exchanged %s [%s] items.').replace('%s', itemInfo(game, i)?.name || '').replace('%s', fmtNum(n)), 'item');
    game.events?.emit?.('shop:coinexchange', { kind, rows: counts, exp: q.exp, points: q.points, dil: q.dilIn - q.dilOut, fee: q.fee });
    st.counts[kind] = {};
    render(kind);
    return true;
  }

  // ------------------------------------------------------------------------------------------ open
  async function open(kind, npc = null) {
    if (!COIN_SHOP_KINDS.includes(kind)) return null;
    for (const other of PAIR_OF[kind]) if (other !== kind && st.wins[other]?.isOpen) st.wins[other].close();
    st.npc = npc ?? st.npc;
    return game.uiwin.open(COIN_SHOP_WINDOWS[kind], { npc: st.npc });
  }
  game.events?.on?.('inventory', () => { if (st.kind) render(st.kind); });
  return {
    open,
    openJob: (jobType, npc = null) => open(Number(jobType) === 165 ? C.goldJobFirstTab : C.rankJobFirstTab, npc),
    get kind() { return st.kind; },
    counts: kind => countsOf(kind),
    setCount: (kind, r, n) => setCount(kind, r, n),
    preview: kind => preview(kind),
    exchange: kind => exchange(kind),
    render: kind => render(kind),
  };
}
