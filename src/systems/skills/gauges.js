// Class gauges of share/action/pc/pcclass.csv and their HUD windows (script/ui/game2/mainbar):
//
//   Aloken (class 6) charge gauge   CHARGE_POINT_MAX 1000, CHARGE_POINT_ADD 20 per landed hit, CHARGE_POINT_DPS 5 lost
//                                   per second, CHARGE_POINT_MAX_TIME 10000 ms held at full. Window chargewnd
//                                   (ui_chargewnd.txt: pcpop 124 icon, 125 base, 126 bar, 127 handle; tooltip 150 1).
//   Half Bagi (class 12) fury       FURY_POINT_DPS 0.2, FURY_POINT_MAX_TIME 10000 ms: "When the Fury gauge reaches 100%,
//                                   it stays full for 10 seconds without decreasing automatically, until you use a Fury
//                                   skill" (stringtable_skill 150 2). Fury skills pay ResourceFury (skill .dat offset
//                                   74) from it. Window furywnd (ui_furywnd.txt: pcpop 75 icon; tooltip 150 2).
// The icon hides / shows the gauge bar (the tooltips' "Click this icon to hide or show the gauge bar").
//
// ENGINE-CHOSEN fury readings (pcclass has no FURY_POINT_MAX / gain rows), one line each in src/config/engine-chosen-fury.js:
// the maximum is the Half Bagi's maximum MP (costs 5 at Lv 10 .. 2,093 at Lv 170 follow the MP scale; fury skills cost no MP);
// a landed hit adds 2 % of the maximum (the Aloken rate: 20 / 1000), a monster hit taken adds 3 %; FURY_POINT_DPS 0.2 is
// 0.2 % of the maximum lost per second, scaled by the active statuses' native FURY_DPS_CORRECTION_MUL (Fury Control /
// Self Injury). The pcclass value columns are: class 0 1 2 3 4 5 6 7 9 10 11 12.
import { fetchCSV } from '../../engine/assets.js';
import { FURY_HIT_GAIN, FURY_HURT_GAIN, furyLossScale } from './fury-rules.js';   // the rules the shared-world host uses too (server/world/fury.mjs)

const num = v => (Number.isFinite(+v) ? +v : 0);

export async function installGauges(game, sys) {
  const ci = Number(game.save?.classIndex ?? game.classDef?.index ?? 0);
  const P = {};
  try {
    const rows = await fetchCSV('share/action/pc/pcclass.csv');
    const head = rows.find(r => r[0] === 'class') || [];
    const col = head.findIndex((h, i) => i > 0 && Number(h) === ci);
    for (const r of rows) if (col > 0 && r[0]) P[r[0].trim()] = num(r[col]);
  } catch (err) { console.warn('[skills] pcclass.csv', err); }

  const kind = num(P.CHARGE_POINT_MAX) > 0 ? 'charge' : num(P.FURY_POINT_MAX_TIME) > 0 || num(P.FURY_POINT_DPS) > 0 ? 'fury' : null;
  if (!kind) return null;
  const g = { kind, cur: 0, fullAt: null, visible: true };
  const player = () => game.player;
  const max = () => (kind === 'charge' ? num(P.CHARGE_POINT_MAX) : Math.max(1, num(player()?.maxMp)));
  const holdSec = (kind === 'charge' ? num(P.CHARGE_POINT_MAX_TIME) : num(P.FURY_POINT_MAX_TIME)) / 1000 || 10;
  const set = (v) => {
    const m = max();
    const before = g.cur;
    g.cur = Math.max(0, Math.min(m, v));
    if (g.cur >= m && before < m) g.fullAt = game.time || 0;
    if (g.cur < m) g.fullAt = null;
    const p = player();
    if (p && kind === 'fury') p.fury = g.cur;
    if (p && kind === 'charge') p.charge = g.cur;
  };
  const gain = (frac, abs = 0) => set(g.cur + (abs || max() * frac));

  game.events?.on('damage', e => {
    const p = player();
    if (!p || p.dead || !e || e.miss || !(e.amount > 0) || e.dot) return;
    if (e.source === p && e.target?.kind === 'monster') gain(FURY_HIT_GAIN, kind === 'charge' ? num(P.CHARGE_POINT_ADD) : 0);
    else if (kind === 'fury' && e.target === p && e.source?.kind === 'monster') gain(FURY_HURT_GAIN);
  });
  // the engine pays fury skills from player.fury
  game.events?.on('skill', ({ actor } = {}) => { const p = player(); if (actor === p && kind === 'fury') set(num(p.fury)); });

  sys.gauge = {
    kind, get value() { return g.cur; }, get max() { return max(); }, set, gain,
    update(dt) {
      const p = player();
      if (!p) return;
      if (kind === 'fury' && Math.abs(num(p.fury) - g.cur) > 1e-6) set(num(p.fury));   // paid by a skill
      const m = max();
      if (g.cur >= m && g.fullAt != null && (game.time || 0) - g.fullAt < holdSec) return;
      const loss = kind === 'charge' ? num(P.CHARGE_POINT_DPS) : m * num(P.FURY_POINT_DPS) / 100 * furyLossScale(game.save?.buffs);
      if ((g.cur > 0 && loss > 0) || loss < 0) set(g.cur - loss * dt);   // a negative fury loss is the Self Injury recharge
    },
  };

  // ---- HUD window
  const ui = game.uiwin;
  if (!ui?.registerWindow) return sys.gauge;
  const name = kind === 'charge' ? 'chargewnd' : 'furywnd';
  ui.registerWindow(name, {
    script: kind === 'charge' ? 'game2/mainbar/ui_chargewnd.txt' : 'game2/mainbar/ui_furywnd.txt',
    hud: true,
    escClose: false,
    create(win) {
      win.control('btn_icon').onClick(() => { g.visible = !g.visible; win.control('pan_base').setVisible(g.visible); win.control('pan_handle').setVisible(g.visible); game.audio?.ui?.('buttonCommon'); });
    },
    update(win) {
      const m = max();
      win.control('processbar').setGauge?.(m > 0 ? g.cur / m : 0);
      const txt = kind === 'charge' ? `${Math.floor(g.cur * 100 / (m || 1))}%` : `${Math.floor(g.cur)} / ${Math.floor(m)}`;
      if (win.data.txt !== txt) { win.data.txt = txt; win.control(kind === 'charge' ? 'lbl_charge' : 'lbl_fury').setText(txt); }
    },
  });
  game.events?.on('map', () => { if (!ui.window(name)?.isOpen) ui.open(name); });
  return sys.gauge;
}
