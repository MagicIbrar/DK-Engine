// Per-map plans for the director (the server map scripts are not in the client; docs/formats/dungeons.md "Gaps").
//
// Lane 52 (waves pass, 2026-10-29): every floor plays only its OWN Global monster data. Nothing is borrowed from a
// sibling floor and nothing is synthesized:
// 1. The director builds stages from the floor's own Global pack rows (maplist-bound callmonster waves, MON_ static
//    rows, scriptmonster rows).
// 2. A floor without bound waves whose own share/map/<n>/callmonster_<n>*.csv file is unbound by maplist (Karon's
//    Fragments_S 122-124, Defense Battle 707) plays that own file (monsters.json callSpawns entry with map === n).
// 3. Anything else gets no added monsters (plan 'global-only'). Removed: the same-terrain sibling borrow (56/240
//    <- 613, 58/242 <- 153, 76/85/86/87/120 <- 122 ...) and the synthesized waves (monsters named in the texts,
//    their family, level-band pools, flood-fill anchors). Those were 4.2.0 stand-ins, not Global values.
//    Floors left without monsters have no source (no reference class, no credible outside source) - left empty.
//
// The first-half floors that Global ships with no monster rows (Lane 52 GLOBAL_ONLY_MAPS) and the Lane 53
// GLOBAL_EMPTY_MAPS / special plans keep their dedicated entries below.

import { mapInfo } from './data.js';
import {deadIslandPlan} from './dead-island-plan.js';
// Lane 53: 223/229/544/611/612/653 no longer synthesize or use an engine-built script (global-script-plans.js).
import {GLOBAL_EMPTY_MAPS, newYearSummonPlan, globalEmptyPlan, globalRosterPlan} from './global-script-plans.js';
// Lane 65: floors Global ships no script for, wired from the older server reference (labelled; server-ref-plans.js).
import {SERVER_REF_MAPS, serverRefPlan} from './server-ref-plans.js';
// Dungeon floors 2026-10-29: 544 [Meister]Desacato filled from Global quest 1624 / monsters 7742-7746 (meister-desacato-plan.js).
import {MEISTER_MAP, meisterDesacatoPlan} from './meister-desacato-plan.js';

const mons = (d) => d.game.data?.monsters?.monsters || {};
const monDef = (d, i) => mons(d)[i] || null;

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

/** The floor's OWN unbound Global call file (callSpawns entry whose map is this floor), or null. Never a sibling's. */
function ownCallWaves(callSpawns, map) {
  for (const [key, e] of Object.entries(callSpawns || {})) if (Number(e.map) === Number(map)) return { from: key, waves: callWaves(e) };
  return null;
}

function addWaves(d, waves, tag) {
  let n = 1000;
  for (const w of waves) {
    const xs = w.rows.map(r => r[1]), ys = w.rows.map(r => r[2]);
    const center = [xs.reduce((a, b) => a + b, 0) / xs.length, ys.reduce((a, b) => a + b, 0) / ys.length];
    d.stages.push({ n: n++, call: w.call, kind: 'wave', objective: w.rows.some(r => (monDef(d, r[0])?.rank || 0) >= 3) ? 'kill-boss' : 'kill-all', rows: w.rows, center,
      opens: [], bosses: [], group: 0, spawned: false, done: false, recs: [], source: tag });
  }
}

// ------------------------------------------------------------------------------------------ Global-only floors (Lane 52)
// First-half floors that Global ships with no monster rows at all: no client waves, no MON_ static rows, no
// scriptmonster list beyond what the pack already turns into stages, and no callmonster file of their own
// (share/map/<n>/ holds only m<n>.mal / npc_<n>.csv / brick_<n>.csv, or there is no folder: 175/178/179).
// Lane 65: 48, 52-55 and 76/85/86/87 stay listed (Global has no rows) but are routed first to the older server
// reference plans (server-ref-plans.js). The rest have no reference class and no credible outside source for their
// monsters, so they keep no monsters at all (nothing invented; labelled 'no source - left empty').
// The director keeps only the stages it builds from the Global pack: 31 keeps its scriptmonster_31.csv row 2774
// Golden Treasure Box (boss clear). The others stay empty (no source - left empty).
const GLOBAL_ONLY_MAPS = new Set([24, 30, 31, 48, 52, 53, 54, 55, 76, 85, 86, 87, 120, 175, 178, 179]);
export function globalOnlyPlan() { return { name: 'global-only', setup() {} }; }

/** A floor without bound waves that ships its own unbound Global callmonster file: play exactly that file. */
function ownCallFilePlan(info) {
  const clearKind = info.stages?.clear?.kind;
  return {
    name: 'global-own-callfile',
    setup(dd) {
      const own = ownCallWaves(dd.game.data?.monsters?.callSpawns, dd.map);
      if (!own?.waves?.length) return;
      addWaves(dd, own.waves, 'global-own-callfile');
      dd.ownCallFile = own.from;
      dd.clearDef = clearKind === 'boss' ? dd.clearDef : { kind: 'all-waves' };
      const name = `${dd.dungeon.name || ''} ${info.name || ''}`;
      dd.sequential = /infinite|arena|fight|stadion|altar|summon/i.test(name);
    },
  };
}

// ------------------------------------------------------------------------------------------ entry point
/** The plan of a map (or null for the plain inferred flow). */
export function planFor(map, d) {
  map = Number(map);
  if(map===551)return deadIslandPlan();
  if(map===223)return newYearSummonPlan();
  if(map===653)return globalRosterPlan();
  if(map===MEISTER_MAP)return meisterDesacatoPlan();   // Global quest 1624 souls -> Enigma; positions ENGINE-DEFAULT
  if(GLOBAL_EMPTY_MAPS.has(map))return globalEmptyPlan();
  if (SERVER_REF_MAPS.has(map)) return serverRefPlan(map);   // Lane 65: 'older server reference' (76/85/86/87, 48, 52-55)
  if (GLOBAL_ONLY_MAPS.has(map)) return globalOnlyPlan();   // Lane 52: no stand-in monsters
  const info = mapInfo(map) || {};
  const hasWaves = (info.waves || []).length > 0;
  const clearKind = info.stages?.clear?.kind;
  if (!hasWaves && !(info.static?.rows?.length) && (clearKind === 'script' || !clearKind || !(info.scriptSpawns || []).length)) {
    const cs = d?.game?.data?.monsters?.callSpawns;
    // own unbound Global call file only (no sibling borrow, no synthesis)
    if (!cs || ownCallWaves(cs, map)) return ownCallFilePlan(info);
    return globalOnlyPlan();
  }
  if (!hasWaves && clearKind === 'script') return globalOnlyPlan();   // was: synthesized waves (removed, Lane 52)
  return clearKind ? null : { name: 'inferred' };
}

export const _internals = { callWaves, ownCallWaves, GLOBAL_ONLY_MAPS, SERVER_REF_MAPS };
