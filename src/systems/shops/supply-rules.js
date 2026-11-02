// Supply-machine rules shared by the client (shops/supply.js) and the authoritative server (server/world/supply.mjs).
// Source tables: share/supplymachine/single_supplymachine_base.csv + single_supplymachine_details.csv (Orbis of Destiny /
// Orbis of Fate), fieldboss_supplymachine.csv, supplymachine.csv + supplymachine_ui.csv (multi machine).
// Global strings: script cate 90/91 (multi) and 96 (Orbis). Multi-machine Enable/Usable are all 0 in prepared Global
// data -> every machine shows CLOSED (91/4); Start answers 90/32 ("It isn't a selling machine.").
// Orbis: Lv 80+ (96/5), 10 slots/day (96/105), midnight reset, mix costs 500,000 Dil (96/111), pay 1 Gear wheel
// (item indexes below). Do not invent rates/limits: plate weights and server_limit come from the CSV rows.

export const ORBIS_PAY_ITEMS = Object.freeze([1756038, 1192509, 1756037]);
export const ORBIS_SLOTS = 10;
export const ORBIS_DAILY = 10;
export const ORBIS_MIX_COST = 500000;
export const ORBIS_MIN_LEVEL = 80;

/** stringtable cate 90 codes used by the multi supply machine window. */
export const SUPPLY_MSG = Object.freeze({
  remainingInit: 4,   // Remaining Initialization : %d times
  needItems: 5,       // need items: %s X %d
  soldOut: 25,        // Sold out.
  noInfo: 28,         // There is no information of the requested machine.
  notSelling: 32,     // It isn't a selling machine.
  soldOutMachine: 33, // It is a sold-out machine.
});

/** stringtable cate 91: CLOSED tag on a disabled machine. */
export const SUPPLY_TAG_CLOSED = 4;

/** stringtable cate 96 (Orbis). */
export const ORBIS_MSG = Object.freeze({
  dilShort: 2,
  gearShort: 3,
  dailyCap: 4,
  levelGate: 5,
  gauge: 105,
  help: 108,
  mixConfirm: 111,
  mixTitle: 112,
});

/** True when every authored multi-machine row is closed (Enable 0 / Usable 0). */
export function multiMachinesClosed(supplyMachine) {
  const machines = supplyMachine?.machines || [];
  if (!machines.length) return true;
  // machinesEnabled is 0 in prepared Global data; also treat every Enable column (index 1) as closed.
  if (!supplyMachine.machinesEnabled) return true;
  return machines.every((m) => !m || !Number(m[1]));
}

/** Message code (cate 90) for Start on the multi machine window. */
export function multiMachineStartCode(supplyMachine, selectedIndex = null) {
  if (multiMachinesClosed(supplyMachine)) return SUPPLY_MSG.notSelling;
  const m = Number.isInteger(selectedIndex) ? supplyMachine?.machines?.[selectedIndex] : null;
  if (!m || !Number(m[1])) return SUPPLY_MSG.notSelling;
  return SUPPLY_MSG.soldOutMachine;
}

/** Tag text code (cate 91) for machine tab k: CLOSED when Usable is 0. */
export function multiMachineTagClosed(supplyMachine, k) {
  const ui = supplyMachine?.uiMachines?.[k];
  return !ui || !Number(ui[1]);
}

/** Build Orbis plate slots from supplyMachine.grades + entries (register_rate weighted). Pure. */
export function buildOrbisSlots(supplyMachine, random = Math.random) {
  const grades = supplyMachine?.grades || [];
  const entries = supplyMachine?.entries || [];
  const slots = [];
  const pickWeighted = (pool) => {
    const total = pool.reduce((n, e) => n + (Number(e[2]) || 0), 0);
    if (!(total > 0)) return null;
    let r = random() * total;
    for (const e of pool) {
      r -= Number(e[2]) || 0;
      if (r < 0) return e;
    }
    return pool[pool.length - 1];
  };
  for (const row of grades) {
    const grade = Number(row[0]);
    const min = Number(row[1]);
    const max = Number(row[2]);
    if (!Number.isInteger(min) || !Number.isInteger(max) || min < 0 || max < min) continue;
    const amount = min === max ? max : min + Math.floor(random() * (max - min + 1));
    const used = new Set();
    for (let k = 0; k < amount; k++) {
      const pool = entries.filter((e) => Number(e[0]) === grade && !used.has(e[1]) && Number(e[2]) > 0);
      const e = pickWeighted(pool);
      if (!e) {
        slots.push({ grade, item: 0, winRate: 0, count: 0, limit: 0, won: true });
        continue;
      }
      used.add(e[1]);
      slots.push({
        grade,
        item: Number(e[1]),
        winRate: Number(e[3]) || 0,
        limit: Number(e[4]) || 0,
        count: Number(e[5]) || 1,
        won: false,
      });
    }
  }
  while (slots.length < ORBIS_SLOTS) slots.push({ grade: 4, item: 0, winRate: 0, limit: 0, count: 0, won: true });
  return slots.slice(0, ORBIS_SLOTS);
}

/** Why an Orbis spin cannot run now, or null when it can. */
export function orbisSpinBlock({ level, used, payCount, daySlotsWon }, nowUsed = used) {
  if ((Number(level) || 1) < ORBIS_MIN_LEVEL) return 'level';
  if ((Number(nowUsed) || 0) >= ORBIS_DAILY) return 'daily';
  if ((Number(payCount) || 0) < 1) return 'gear';
  const left = (daySlotsWon || []).filter((s) => s && s.item && !s.won && (s.winRate || 0) > 0);
  if (!left.length) return 'empty';
  return null;
}

/** Pick a remaining Orbis slot index by win_rate. Pure. */
export function pickOrbisSlot(slots, random = Math.random) {
  const left = slots
    .map((s, i) => ({ s, i, weight: Number(s.winRate) || 0 }))
    .filter(({ s, weight }) => s && s.item && !s.won && weight > 0);
  if (!left.length) return null;
  const total = left.reduce((n, x) => n + x.weight, 0);
  let r = random() * total;
  for (const row of left) {
    r -= row.weight;
    if (r < 0) return row.i;
  }
  return left[left.length - 1].i;
}

/** Field-boss roulette weight sum must be 1_000_000 in Global data. */
export function fieldBossWeightSum(supplyMachine) {
  const items = supplyMachine?.fieldBossRoulette?.[0]?.items || [];
  return items.reduce((n, row) => n + (Number(row[1]) || 0), 0);
}
