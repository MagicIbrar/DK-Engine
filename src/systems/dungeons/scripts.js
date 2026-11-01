// Per-map plans for the director (the server map scripts are not in the client; docs/formats/dungeons.md "Gaps").
//
// 1. Unbound call files: share/map/<n>/callmonster_<n>*.csv files that maplist does not bind (Karon's Fragments_S
//    122-124, Braiken's Defense Battle 707 ...) are in monsters.json callSpawns: a map without waves uses its own
//    file, else the file of a map with the same .map terrain whose monsters fit the level range (Karon's Fragments
//    76/85/86/87 <- 122 (Lv132-138 for 131+), Karon's Transport Ship B/A/S/F <- 226/605, Helion's Sanctuary <- 614 ...).
// 2. Magic Field of Crack C/B/A (24/30/31): ten rounds ("Magic Field of Crevice Round 1..Final", codes 10-19,
//    1000-1009 round start, 1115-1125 round EXP) of the Magic Field monster families (Dark / Beyond / Inferno sets,
//    Laiden as the final round), treasure boxes from round 6, the Golden Treasure Box after the final round.
// 3. Everything else without monster data is synthesized from the map's own texts: monsters NAMED in its messages
//    (English or Korean name, the variant closest to the dungeon level: "Talos" -> Born Talos Lv79 for Karon's
//    Transport Ship C, Blood Talos for B ...), their family (same-prefix neighbours in monster.dat order), else the
//    script-only monsters of the level band; stages placed along the reachable floor (flood fill from the start),
//    played in order, the strongest named monster last.
// Every synthesized stage is marked `synth: true`; the director plays them like the inferred ones.

import { mapInfo, dungeonById, messageText } from './data.js';
import {deadIslandPlan} from './dead-island-plan.js';
import {phantomCastlePlan} from './phantom-plan.js';

// ------------------------------------------------------------------------------------------ helpers
const mons = (d) => d.game.data?.monsters?.monsters || {};
const monDef = (d, i) => mons(d)[i] || null;

function band(d) {
  const lv = d.info.levels || d.dungeon.entry?.levels || [1, 250];
  const min = Math.max(1, Number(lv[0]) || 1);
  let max = Number(lv[1]) || 250;
  if (max < min) max = Math.min(250, min + 30);
  return { min, max, target: Math.min(max, min + 6) };
}

/** Waves of a monsters.json callSpawns entry: [{call, rows:[[monster, x, y, cell, count]]}]. */
function callWaves(entry) {
  const by = new Map();
  for (const r of entry.rows || []) {
    const [ci, mon, x, y, cell, count] = r;
    if (!by.has(ci)) by.set(ci, []);
    by.get(ci).push([mon, x, y, cell, count]);
  }
  return [...by.entries()].sort((a, b) => a[0] - b[0]).map(([call, rows]) => ({ call, rows }));
}

function medianLevel(d, waves) {
  const lv = [];
  for (const w of waves) for (const r of w.rows) { const m = monDef(d, r[0]); if (m && m.role !== 'object') lv.push(Number(m.level) || 0); }
  lv.sort((a, b) => a - b);
  return lv.length ? lv[lv.length >> 1] : 0;
}

/** Own or same-terrain unbound call file whose monsters suit the level range. */
function borrowedWaves(d) {
  const all = d.game.data?.monsters?.callSpawns || {};
  const file = d.info.files?.map;
  const b = band(d);
  const own = [], sib = [];
  for (const [key, e] of Object.entries(all)) {
    if (Number(e.map) === d.map) own.push({ key, e });
    else if (file && mapInfo(e.map)?.files?.map === file) sib.push({ key, e });
  }
  if (own.length) return { from: own[0].key, waves: callWaves(own[0].e) };
  let best = null;
  for (const s of sib) {
    const waves = callWaves(s.e);
    const med = medianLevel(d, waves);
    const diff = med < b.min - 12 ? b.min - med : med > b.max + 40 ? med - b.max : Math.abs(med - b.target) / 10;
    if (med >= b.min - 12 && med <= b.max + 40 && (!best || diff < best.diff)) best = { from: s.key, waves, diff };
  }
  return best;
}

function addWaves(d, waves, tag) {
  let n = 1000;
  for (const w of waves) {
    const xs = w.rows.map(r => r[1]), ys = w.rows.map(r => r[2]);
    const center = [xs.reduce((a, b) => a + b, 0) / xs.length, ys.reduce((a, b) => a + b, 0) / ys.length];
    d.stages.push({ n: n++, call: w.call, kind: 'wave', objective: w.rows.some(r => (monDef(d, r[0])?.rank || 0) >= 3) ? 'kill-boss' : 'kill-all', rows: w.rows, center,
      opens: [], bosses: [], group: 0, spawned: false, done: false, recs: [], synth: tag });
  }
}

/** Reachable walkable cells from the start (BFS), with their step distance. */
function reachable(d, maxCells = 250000) {
  const col = d.game.world?.collision;
  const s = d.info.spawn;
  const p = d.game.player;
  const sx = Math.floor(s?.snap?.[0] ?? (s ? s.x + 0.5 : p?.x ?? 0)), sz = Math.floor(s?.snap?.[1] ?? (s ? s.y + 0.5 : p?.z ?? 0));
  if (!col || !col.walkableCell(sx, sz)) {
    const n = col?.nearestWalkable(sx + 0.5, sz + 0.5, 12);
    if (!n) return [];
    return reachableFrom(col, Math.floor(n.x), Math.floor(n.z), maxCells);
  }
  return reachableFrom(col, sx, sz, maxCells);
}
function reachableFrom(col, sx, sz, maxCells) {
  const W = col.width, H = col.height;
  const dist = new Int32Array(W * H).fill(-1);
  const q = new Int32Array(Math.min(W * H, maxCells + 8));
  let h = 0, t = 0;
  dist[sz * W + sx] = 0; q[t++] = sz * W + sx;
  const out = [];
  while (h < t && t < q.length - 4) {
    const c = q[h++]; const cx = c % W, cz = (c / W) | 0;
    out.push([cx + 0.5, cz + 0.5, dist[c]]);
    for (const [dx, dz] of [[1, 0], [-1, 0], [0, 1], [0, -1]]) {
      const nx = cx + dx, nz = cz + dz;
      if (nx < 0 || nz < 0 || nx >= W || nz >= H) continue;
      const n = nz * W + nx;
      if (dist[n] >= 0 || col.cells[n]) continue;
      dist[n] = dist[c] + 1; q[t++] = n;
    }
  }
  return out;
}

/** k anchor points spread along the reachable floor (by path distance from the start). */
function anchors(d, k) {
  const cells = reachable(d);
  if (!cells.length) return [];
  const maxD = cells[cells.length - 1][2] || 1;
  const out = [];
  for (let i = 0; i < k; i++) {
    const f = k === 1 ? 0.8 : 0.2 + (0.78 * i) / (k - 1);
    const want = f * maxD;
    // the cell at that distance with the most open neighbourhood (rooms, not corridors)
    let best = null;
    for (let j = 0; j < cells.length; j += 7) {
      const c = cells[j];
      if (Math.abs(c[2] - want) > Math.max(6, maxD * 0.04)) continue;
      const open = d.game.world.collision.walkableCell(Math.floor(c[0]) + 2, Math.floor(c[1])) + d.game.world.collision.walkableCell(Math.floor(c[0]) - 2, Math.floor(c[1]))
        + d.game.world.collision.walkableCell(Math.floor(c[0]), Math.floor(c[1]) + 2) + d.game.world.collision.walkableCell(Math.floor(c[0]), Math.floor(c[1]) - 2);
      const score = open * 10 - Math.abs(c[2] - want);
      if (!best || score > best.score) best = { x: c[0], z: c[1], score };
    }
    if (best) out.push([best.x, best.z]);
  }
  return out;
}

// ------------------------------------------------------------------------------------------ name matching
const HANGUL = /[\uAC00-\uD7A3]/;

/** Monsters named in the map's texts, the level-closest variant of each name: [{idx, def}]. */
function namedMonsters(d) {
  const texts = [];
  for (const m of Object.values(d.info.messages || {})) { if (m.t) texts.push(m.t); if (m.c) texts.push(m.c); }
  texts.push(d.dungeon.name || '', d.info.name || '', d.info.title || '');
  const text = ` ${texts.join(' \n ').toLowerCase().replace(/<[^>]+>/g, ' ')} `;
  const b = band(d);
  const byName = new Map();
  const norm = (s) => String(s || '').toLowerCase().replace(/'s\b/g, '').replace(/[^a-z0-9\uAC00-\uD7A3 ]+/g, ' ').replace(/\s+/g, ' ').trim();
  const T = ` ${norm(text)} `;
  for (const [k, m] of Object.entries(mons(d))) {
    if (!m?.name || m.role === 'invisible' || m.role === 'npc') continue;
    const en = norm(m.name), kr = String(m.nameKr || '').split('_')[0].trim();
    let hit = null;
    if (en.length >= 4 && !/^(monster|mana mon|treasure ?box|golden treasure box|treasurebox\d*)$/.test(en)) {
      if (T.includes(` ${en} `)) hit = en;
      else {
        // the last word of a prefixed family name ("Born Talos" <- "Talos")
        const words = en.split(' ');
        const tail = words.length > 1 ? words.slice(1).join(' ') : null;
        if (tail && tail.length >= 5 && T.includes(` ${tail} `)) hit = tail;
      }
    }
    if (!hit && kr.length >= 3 && HANGUL.test(kr) && text.includes(kr.toLowerCase())) hit = kr;
    if (!hit) continue;
    const lv = Number(m.level) || 1;
    const score = (lv >= b.min - 5 && lv <= b.max + 25 ? 0 : 1000) + Math.abs(lv - b.target) + (m.spawns ? 50 : 0);
    const cur = byName.get(hit);
    if (!cur || score < cur.score) byName.set(hit, { idx: Number(k), def: m, score, name: hit });
  }
  return [...byName.values()].filter(x => x.score < 1000);
}

/** Same-prefix neighbours of a monster in monster.dat order (the tier family: Born Talos -> Born *). */
function family(d, idx) {
  const m = monDef(d, idx);
  if (!m) return [];
  const first = String(m.name).split(' ')[0];
  const out = [];
  for (let i = idx - 14; i <= idx + 14; i++) {
    const x = monDef(d, i);
    if (!x || i === idx || x.role !== 'creature' || (x.rank || 0) > 2) continue;
    if (String(x.name).split(' ')[0] === first && Math.abs((x.level || 0) - (m.level || 0)) <= 25) out.push(i);
  }
  return out;
}

/** Script-only creatures of the level band (deterministic by map). */
function bandPool(d, count, boss) {
  const b = band(d);
  const list = [];
  for (const [k, m] of Object.entries(mons(d))) {
    if (m.role !== 'creature' || m.spawns) continue;
    const lv = Number(m.level) || 0;
    const r = Number(m.rank) || 0;
    if (boss ? r < 3 || r > 6 : r > 1) continue;
    if (lv < b.min || lv > b.min + (boss ? 20 : 10)) continue;
    list.push(Number(k));
  }
  list.sort((a, b2) => a - b2);
  const out = [];
  let s = (d.map * 2654435761) >>> 0;
  while (out.length < count && list.length) { s = (s * 1103515245 + 12345) >>> 0; out.push(list.splice(s % list.length, 1)[0]); }
  return out;
}

// ------------------------------------------------------------------------------------------ synthesized plan
function synthesize(d) {
  const named = namedMonsters(d);
  const trash = new Set(), bosses = [];
  for (const n of named) {
    if ((n.def.rank || 0) >= 3) bosses.push(n.idx);
    else trash.add(n.idx);
    for (const f of family(d, n.idx)) trash.add(f);
  }
  let pool = [...trash];
  if (!pool.length && !bosses.length) pool = bandPool(d, 3, false);
  if (!bosses.length && !named.length) bosses.push(...bandPool(d, 1, true));
  bosses.sort((a, b) => (monDef(d, a)?.level || 0) - (monDef(d, b)?.level || 0));
  const nTrash = pool.length ? Math.max(2, Math.min(6, (d.info.missions || []).length || 3)) : 0;
  const pts = anchors(d, nTrash + bosses.length);
  if (!pts.length) return false;
  const stages = [];
  for (let i = 0; i < nTrash && pool.length; i++) {
    const [x, z] = pts[Math.min(i, pts.length - 1)];
    const rows = [];
    for (let k = 0; k < 8; k++) rows.push([pool[(i + k) % pool.length], Math.floor(x), Math.floor(z), 4, 1]);
    stages.push(rows);
  }
  bosses.forEach((b, i) => {
    const [x, z] = pts[Math.min(nTrash + i, pts.length - 1)];
    stages.push([[b, Math.floor(x), Math.floor(z), 0, 1], ...(pool.length ? [[pool[i % pool.length], Math.floor(x), Math.floor(z), 4, 3]] : [])]);
  });
  addWaves(d, stages.map((rows, i) => ({ call: i + 1, rows })), 'synth');
  d.sequential = true;
  d.clearDef = { kind: 'all-waves' };
  d.synthesized = { named: named.map(n => `${n.idx} ${n.def.name}`), pool, bosses };
  return true;
}

// ------------------------------------------------------------------------------------------ Magic Field of Crack
// Round monster families (monster.dat order): Cerberus, Devil Worker, Zombie x2, Evelyn/Devilrun x3, Lasputin
// Sorcerer, Lupain, Fallen Bishop, Laiden Ego, Laiden (final); treasure boxes 2763-2773, golden 2774-2780.
const MAGIC_FIELD = {
  24: [2341, 2342, 2337, 2512, 2513, 2514, 2334],                            // Rank C: Dark / Soul / High / Laiden set
  30: [2700, 2701, 2702, 2703, 2704, 2705, 2706, 2707, 2708, 2709, 2710, 2711],  // Rank B: Beyond / Katan / Jolten / Torturous
  31: [2721, 2722, 2723, 2724, 2725, 2726, 2727, 2728, 2729, 2730, 2731, 2732],  // Rank A: Inferno / Karl / Half / Ivid
};
const MF_BOX = { 24: 2763, 30: 2765, 31: 2769 };
const MF_GOLD = { 24: 2775, 30: 2776, 31: 2774 };

function magicField(d) {
  const set = MAGIC_FIELD[d.map];
  const rounds = [];
  for (let c = 10; c <= 19; c++) if (d.info.messages?.[String(c)]) rounds.push(c);
  const n = rounds.length || 10;
  const center = d.info.spawn ? [d.info.spawn.x, d.info.spawn.y] : [Math.floor(d.game.player.x), Math.floor(d.game.player.z)];
  const pts = anchors(d, 3);
  const arena = pts[1] || center;
  const waves = [];
  for (let r = 0; r < n; r++) {
    const last = r === n - 1;
    const kind = set[Math.min(set.length - 1, Math.floor((r * (set.length - 1)) / Math.max(1, n - 1)))];
    const rows = [[last ? set[set.length - 1] : kind, arena[0], arena[1], 6, last ? 1 : 10 + r * 2]];
    if (!last && set[(r + 1) % set.length] !== kind) rows.push([set[(r + 1) % set.length], arena[0], arena[1], 6, 4 + r]);
    if (last) rows.push([set[Math.max(0, set.length - 2)], arena[0], arena[1], 6, 6]);
    waves.push({ call: r + 1, rows });
  }
  addWaves(d, waves, 'magicField');
  d.sequential = true;
  const scriptBox = d.stages.some(s => s.kind === 'boss');     // Rank A: the Golden Treasure Box is its script boss
  if (!scriptBox) d.clearDef = { kind: 'all-waves' };
  return {
    stageDone(dd, st) {
      const r = dd.stages.filter(s => s.synth === 'magicField').indexOf(st);
      if (r < 0) return;
      const code = 1115 + r;
      dd.alert(code);
      const m = /(\d[\d,]*)\s*Exp/i.exec(messageText(dd.map, code) || '');
      if (m) dd.sys.grantExp(Number(m[1].replace(/,/g, '')));
      // treasure boxes from round 6, the golden box after the final round
      if (r >= 5 && !(r === n - 1 && scriptBox)) spawnBoxes(dd, r === n - 1 ? MF_GOLD[dd.map] : MF_BOX[dd.map], arena);
      if (r + 1 < n) dd.later(3, () => { if (dd.running) dd.alert(1000 + r + 1); });
    },
    begin(dd) { dd.alert(1000); },
  };
}

function spawnBoxes(d, idx, at) {
  if (!idx || !monDef(d, idx)) return;
  const st = { n: 5000 + d._seq, kind: 'box', objective: 'none', rows: [[idx, at[0], at[1], 2, 1]], opens: [], bosses: [], group: 0, spawned: false, done: true, recs: [], synth: 'box' };
  d.stages.push(st);
  d._spawnStage(st);
  st.done = true;
}

// ------------------------------------------------------------------------------------------ entry point
/** The plan of a map (or null for the plain inferred flow). */
export function planFor(map, d) {
  map = Number(map);
  if(map===551)return deadIslandPlan();
  if(map===653)return phantomCastlePlan(anchors);
  const info = mapInfo(map) || {};
  const hasWaves = (info.waves || []).length > 0;
  const clearKind = info.stages?.clear?.kind;
  const plan = { name: 'inferred' };
  if (MAGIC_FIELD[map] && !hasWaves) {
    return { name: 'magicField', setup(dd) { Object.assign(this, magicField(dd)); } };
  }
  if (!hasWaves && !(info.static?.rows?.length) && (clearKind === 'script' || !clearKind || !(info.scriptSpawns || []).length)) {
    return {
      name: 'borrowed-or-synth',
      setup(dd) {
        // a boss dungeon with no texts at all (Agacion / Oread / Tritone): its name is the boss
        if (!Object.keys(info.messages || {}).length && synthesize(dd)) return;
        const b = borrowedWaves(dd);
        if (b?.waves?.length) {
          addWaves(dd, b.waves, 'borrowed');
          dd.borrowedFrom = b.from;
          dd.clearDef = clearKind === 'boss' ? dd.clearDef : { kind: 'all-waves' };
          const name = `${dd.dungeon.name || ''} ${info.name || ''}`;
          dd.sequential = /infinite|arena|fight|stadion|altar|summon/i.test(name);
          return;
        }
        synthesize(dd);
      },
    };
  }
  if (!hasWaves && clearKind === 'script') return { name: 'synth', setup(dd) { synthesize(dd); } };
  return clearKind ? null : plan;
}

export const _internals = { namedMonsters, family, bandPool, borrowedWaves, anchors, band };
