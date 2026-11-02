// Lane 53: dungeons whose monsters live only in Global's server script.
// Nothing here is synthesized or borrowed. Each plan replays exactly what the
// Global client data states, and leaves the floor empty where Global has nothing.
//
// 223 [EVENT] Lunar New Year's Event Dungeon (Global share/map/223_event_dungeon,
//   dungeons.json maps.223.messages): Reezena 5522 opens dialog 10000 with menu
//   10001-10005. "10 Gold/Silver/Bronze Monkey Coins: Summons Gold/Silver/Bronze
//   pouch", "You can only summon 5 monsters at a time." Messages 102 (no coins),
//   103 (summon cap), 104 (summoned), 105 (exit blocked while summons live),
//   107 (closing). Coins: items 1601417/1601418/1601419 Monkey Gold/Silver/Copper
//   Coin. Pouches: monsters 8479/8480/8481 Golden/Silver/Bronze Random Pocket.
//   Global has no clear condition and no time limit ("-"); the run ends at the
//   dungeonlist expiry.
//   Lane 65 (b): the pouch position is in no source - Global (callmonster_223_event_dungeon.csv header only,
//   223_event_dungeon.csv empty), the decompiles, the older server reference (no 223 class in ScriptProcess.dll)
//   and online (no official guide or wiki gives a spot or rule). Under the no-invention rule the summon is
//   REMOVED: Reezena keeps the Global dialog 10000 text and menu, the summon options take no coins and spawn
//   nothing, and the exit option (10004) still leaves.
// 229 / 544 / 611 / 612: Global ships no calls, mon or scriptmonster rows, so the
//   floors stay empty (no source - left empty: no reference class, no credible outside source).
// 653 Zuto's Phantom Castle: Global scriptmonster_653.csv lists one monster (8833 Acquirai Fanatic) with no
//   X/Y (mon_653 empty); the older server reference has no 653 class and no credible online source places it.
//   Lane 65 (b): the invented spawn-point placement is REMOVED - the floor carries no monster (removed / no
//   credible source).

const SUMMON_223 = { 10001: 1, 10002: 1, 10003: 1 };   // Global menu 10000 summon options (removed: no placement source)
const EXIT_223 = 10004, CANCEL_223 = 10005;

// Dungeon floors 2026-10-29: 544 left this list - meister-desacato-plan.js fills it from Global quest 1624 (souls
// 7742-7745 then Enigma 7746, Global stats; room positions ENGINE-DEFAULT). 229/611/612 stay empty (no source).
export const GLOBAL_EMPTY_MAPS = new Set([229, 611, 612]);

const plainText = (d, code) => String(d.text?.(code) ?? '').replace(/<[^>]*>/g, '');

function alive223(d) {
  let n = 0;
  for (const st of d.stages) if (st.kind === 'summon') for (const r of st.recs || []) if (!r.skip && !r.dg?.killed) n++;
  return n;
}

async function choose223(d, npc, sn, code) {
  d.sys.dialog.close?.();
  if (code === CANCEL_223) return;
  if (code === EXIT_223) {
    if (alive223(d)) { d.alert(105); return; }
    d._exit(npc, sn);
    return;
  }
  // 10001-10003 (summon): removed - no source gives where the pouch appears, so nothing is consumed or spawned.
  if (SUMMON_223[code]) d.removedNoSource = { what: '223 pouch summon', source: 'no Global/reference/online position' };
}

export function newYearSummonPlan() {
  return {
    name: 'global-223-summon',
    setup(d) { d.stages = []; d.clearDef = { kind: 'script' }; d.sequential = false; d.killTarget = 0; },
    clearMet() { return false; },
    talk(d, npc, sn) {
      if (Number(sn.npc) !== 5522) return false;
      const m = d.msg?.(10000);
      if (!m) return false;
      const menu = (m.m || []).map(code => ({ text: plainText(d, code) || 'OK', onClick: () => choose223(d, npc, sn, Number(code)) }));
      d.sys.dialog.open({ title: npc.name || sn.name, text: d.text(10000), menu, options: true });
      return true;
    },
  };
}

export function globalEmptyPlan() {
  return {
    name: 'global-empty',
    setup(d) { d.stages = []; d.clearDef = { kind: 'script' }; d.killTarget = 0; },
  };
}

export function globalRosterPlan() {
  return {
    name: 'global-roster',
    setup(d) {
      // Lane 65 (b): no credible position for the Global scriptmonster row -> no monster (removed / no credible source)
      d.stages = [];
      d.clearDef = { kind: 'script' };
      d.sequential = false;
      d.killTarget = 0;
      d.removedNoSource = { what: 'scriptmonster placement', rows: (d.info?.scriptSpawns || []).map(s => Number(s.monster)), source: 'no Global/reference/online position' };
    },
  };
}
