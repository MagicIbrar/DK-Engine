// Drop tables for the GM panel (docs/formats/gmcommands.md §3.6, §4.4, §6.12): what a monster drops, exactly.
//   layer 'monster'  the monster's own monsterdropitemtable row (gmcommands_monsters.json drops: chance per kill
//                    = slot ratio/100000 x item ratio/set total, combined over slots as 1 - prod(1 - p); fixed = 1)
//   layer 'map'      monsterdropitem_map.csv of the map of the kill (every monster unless excluded): item sets,
//                    fixed items, fixed item sets, money
//   layer 'class'    monsterdropitem_class.csv rows of that map (level range, monster 0 = any): Rate/100000 fires,
//                    then the killer's class list with ClassRate/100000 (else a random class), one set of the list
// Chances are per kill, before GM rate events and formula multipliers (those are shown separately).
// simulate() rolls with the loot system's own rollMonsterDrops (the function every real kill uses).
import { gmData } from './data.js';

const P = v => Math.max(0, Math.min(1, Number(v) || 0));

function combine(map, item, p, extra) {
  const e = map.get(item) || { item, p: 0, layers: new Set(), min: null, max: null, via: [] };
  e.p = 1 - (1 - e.p) * (1 - P(p));
  e.layers.add(extra.layer);
  if (extra.min != null) e.min = e.min == null ? extra.min : Math.min(e.min, extra.min);
  if (extra.max != null) e.max = e.max == null ? extra.max : Math.max(e.max, extra.max);
  if (extra.via && e.via.length < 6) e.via.push(extra.via);
  map.set(item, e);
}

/** Per-item chance of one pick from an item set (weights over total). */
function setShares(set) {
  const items = set?.items || [];
  // one pick by weight over the listed items (loot.js pickFromSet, the roller every kill uses)
  const total = items.reduce((s, x) => s + Math.max(0, Number(x[1]) || 0), 0) || Number(set?.total) || 1;
  return items.map(x => ({ item: Number(x[0]), share: (Number(x[1]) || 0) / total, a: x[2], b: x[3], c: x[4] }));
}

/**
 * Full drop table of a monster.
 * opts: { map (default: current map), classIndex (killer class), level (monster level override) }
 * Returns { monster (row), money:[{min,max,p,layer}], items:[{item, name, p, layers, min, max, via}], notes:[] }.
 */
export async function dropTable(monsterId, opts = {}) {
  const [mons, file, items] = await Promise.all([gmData.list('monsters'), gmData.monstersFile(), gmData.list('items')]);
  const m = mons.byId.get(String(monsterId));
  if (!m) return null;
  const r = m.raw;
  const out = new Map();
  const money = [];
  const notes = [];
  // own table
  for (const d of r.drops || []) combine(out, Number(d[0]), d[1], { layer: 'monster', min: d[2] ?? null, max: d[3] ?? null });
  if (Array.isArray(r.money) && r.money[2] > 0) money.push({ min: r.money[0], max: r.money[1], p: r.money[2], layer: 'monster' });
  for (const g of r.moneyGroups || []) if (Array.isArray(g) && g[4] > 0) money.push({ min: g[2], max: g[3], count: [g[0], g[1]], p: g[4] / 100000, layer: 'monster' });
  // map layer
  const map = opts.map ?? null;
  const md = map != null ? file.mapDrops?.[String(map)] : null;
  if (md) {
    if ((md.exclude || []).map(Number).includes(Number(m.id))) notes.push(`excluded from the map ${map} drop layer`);
    else {
      for (const [set, ratio] of md.sets || []) {
        for (const s of setShares(file.itemSets?.[set])) combine(out, s.item, (ratio / 100000) * s.share, { layer: 'map', via: `map set ${set}` });
      }
      for (const [item, , cmin, cmax, ratio] of md.fixed || []) combine(out, Number(item), (Number(ratio) || 0) / 100000, { layer: 'map', min: cmin, max: cmax, via: 'map fixed' });
      for (const [set, cmin, cmax, ratio] of md.fixedSets || []) {
        const fire = ratio > 0 ? ratio / 100000 : 1;
        const n = Math.max(1, (Number(cmin) + Number(cmax)) / 2 || 1);
        for (const s of setShares(file.itemSets?.[set])) combine(out, s.item, 1 - Math.pow(1 - fire * s.share, n), { layer: 'map', via: `map fixed set ${set}` });
      }
      if (md.money?.[4] > 0) money.push({ min: md.money[2], max: md.money[3], count: [md.money[0], md.money[1]], p: md.money[4] / 100000, layer: 'map' });
      // class layer (only on maps whose row has Class_Check)
      if (md.classCheck) {
        const lv = Number(opts.level ?? r.level) || 0;
        const ci = Number(opts.classIndex ?? 0);
        const plv = opts.playerLevel != null ? Number(opts.playerLevel) : null;
        for (const row of file.classDrops || []) {
          const [cmap, lmin, lmax, cap, , mon, rate, classRate, byClass] = row;
          if (Number(cmap) !== Number(map) || lv < lmin || lv > lmax || (Number(mon) && Number(mon) !== Number(m.id))) continue;
          // LevelCap: the largest player-over-monster level gap that still drops (the loot roller's rule)
          if (plv != null && Number(cap) > 0 && plv - lv > Number(cap)) { if (!notes.includes('class layer: your level is too far above the monster')) notes.push('class layer: your level is too far above the monster'); continue; }
          const nClasses = Object.keys(byClass || {}).length || 15;
          const own = (Number(classRate) || 0) / 100000;
          const pClass = own + (1 - own) / nClasses;
          const list = byClass?.[String(ci)] || [];
          for (const set of list) {
            const pSet = (Number(rate) || 0) / 100000 * pClass / (list.length || 1);
            for (const s of setShares(file.itemSets?.[set])) combine(out, s.item, pSet * s.share, { layer: 'class', via: `class ${ci} set ${set}` });
          }
        }
      }
    }
  }
  const list = [...out.values()].map(e => ({ ...e, layers: [...e.layers], name: items.byId.get(String(e.item))?.name || `Item #${e.item}` }));
  list.sort((a, b) => b.p - a.p || a.item - b.item);
  return { monster: m, money, items: list, notes, map };
}

/** Monsters whose own table drops an item (plus maps whose map layer drops it). */
export async function whoDrops(itemId) {
  const [mons, file] = await Promise.all([gmData.list('monsters'), gmData.monstersFile()]);
  const id = Number(itemId);
  const out = [];
  for (const m of mons) {
    const d = (m.raw.drops || []).find(x => Number(x[0]) === id);
    if (d) out.push({ monster: m, p: d[1] });
  }
  out.sort((a, b) => b.p - a.p);
  const maps = [];
  for (const [map, md] of Object.entries(file.mapDrops || {})) {
    let p = 0;
    for (const [set, ratio] of md.sets || []) for (const s of setShares(file.itemSets?.[set])) if (s.item === id) p = 1 - (1 - p) * (1 - (ratio / 100000) * s.share);
    for (const f of md.fixed || []) if (Number(f[0]) === id) p = 1 - (1 - p) * (1 - (Number(f[4]) || 0) / 100000);
    for (const [set, , , ratio] of md.fixedSets || []) for (const s of setShares(file.itemSets?.[set])) if (s.item === id) p = 1 - (1 - p) * (1 - (ratio > 0 ? ratio / 100000 : 1) * s.share);
    if (p > 0) maps.push({ map: Number(map), p });
  }
  maps.sort((a, b) => b.p - a.p);
  const sets = [];
  for (const [k, s] of Object.entries(file.itemSets || {})) if ((s.items || []).some(x => Number(x[0]) === id)) sets.push(Number(k));
  return { item: id, monsters: out, maps, sets };
}

/**
 * Simulate `kills` kills with the loot system's roller (own table + map layer as the dungeons system rolls it).
 * Returns { kills, dil, items: [{item, name, count, drops}] }.
 */
export async function simulate(game, monsterId, kills = 1000, opts = {}) {
  const { rollMonsterDrops } = await import('../../game/loot.js');
  const def = game.data?.monster?.(monsterId);
  if (!def) return null;
  const file = await gmData.monstersFile();
  const items = await gmData.list('items');
  const F = game.data?.classesFile?.formula || {};
  const itemRate = (Number(F.fMonItemDropRatio) || 1) * (game.settings?.dropRate ?? 1);
  const moneyRate = (Number(F.fMonMoneyDropRatio) || 1) * (game.settings?.moneyRate ?? 1);
  const map = opts.map ?? game.world?.info?.index;
  const md = file.mapDrops?.[String(map)];
  const mapLayer = md && !(md.exclude || []).map(Number).includes(Number(monsterId))
    ? { fixed: md.fixed || [], fixedSets: (md.fixedSets || []).map(([s, a, b, r]) => [s, a, b, 0, r]), sets: md.sets || [], money: md.money?.[4] ? [md.money] : [], maxSets: md.maxSets || 1 }
    : null;
  const count = new Map();
  let dil = 0;
  const add = (e) => {
    if (e.kind === 'dil') { dil += e.amount; return; }
    const c = count.get(e.itemIndex) || { item: e.itemIndex, count: 0, drops: 0, grades: {} };
    c.count += e.count || 1; c.drops++; c.grades[e.grade || 'normal'] = (c.grades[e.grade || 'normal'] || 0) + 1;
    count.set(e.itemIndex, c);
  };
  const n = Math.max(1, Math.min(100000, Math.floor(kills)));
  // the class-drop layer exactly as a real kill rolls it (loot.rollClassDrops: the current map, your level and class)
  const L = game.loot;
  const classLayer = map === game.world?.info?.index && typeof L?.rollClassDrops === 'function';
  if (classLayer) await L.loadClassDrops?.();
  const fake = { monsterIndex: Number(monsterId), level: def.level, def };
  for (let k = 0; k < n; k++) {
    for (const e of rollMonsterDrops(def, game.data.monsters, { itemRate, moneyRate })) add(e);
    if (classLayer) { try { for (const e of L.rollClassDrops(fake, def, { itemRate })) add(e); } catch { /* optional */ } }
    if (mapLayer) {
      const fixed = mapLayer.fixed.filter(f => Math.random() * 100000 < f[4] * itemRate).map(f => f.slice(0, 4));
      for (const e of rollMonsterDrops({ drops: { ...mapLayer, fixed } }, game.data.monsters, { itemRate, moneyRate })) add(e);
    }
  }
  const list = [...count.values()].map(c => ({ ...c, name: items.byId.get(String(c.item))?.name || `Item #${c.item}` }));
  list.sort((a, b) => b.drops - a.drops);
  return { kills: n, dil, items: list, map };
}

/** "0.105 %" style text of a probability. */
export function pct(p) {
  const v = P(p) * 100;
  if (v >= 10) return `${v.toFixed(1)} %`;
  if (v >= 1) return `${v.toFixed(2)} %`;
  if (v >= 0.01) return `${v.toFixed(3)} %`;
  return `${v.toPrecision(2)} %`;
}
