// Mainbar extras rules (pure, shared by the HUD and tools/test-mainbar-extras.mjs): monster transformation lookup
// (status option STATUS_CHANGE_MONSTER -> share/change_monster.csv), spell count (attack / defence buffs), upkeep
// statuses and the buff window overflow label. ENGINE-CHOSEN values: src/config/engine-chosen-mainbar.js.
import { MAINBAR_ENGINE_CHOSEN as CFG } from '../../config/engine-chosen-mainbar.js';

const num = v => (v === '' || v == null ? NaN : Number(v));
const finite = (v, d = 0) => (Number.isFinite(num(v)) ? num(v) : d);

/** share/change_monster.csv rows (header first, parseCSV arrays) -> Map INDEX -> row. Note columns are ignored. */
export function parseChangeMonster(rows) {
  const out = new Map();
  if (!Array.isArray(rows) || !rows.length) return out;
  const head = rows[0].map(h => String(h || '').trim().toUpperCase());
  const col = name => head.indexOf(name);
  const at = (r, name) => { const i = col(name); return i >= 0 ? r[i] : undefined; };
  for (const r of rows.slice(1)) {
    const index = num(at(r, 'INDEX'));
    if (!Number.isInteger(index) || index <= 0) continue;
    const skills = [1, 2, 3, 4, 5].map(k => finite(at(r, `SKILL_${k}`))).filter(v => v > 0);
    out.set(index, {
      index, type: finite(at(r, 'TYPE')), action: String(at(r, 'ACTION') || '').trim(),
      monsterIndex: finite(at(r, 'MONSTER_INDEX')), height: finite(at(r, 'MONSTER_HEIGHT')),
      scale: finite(at(r, 'MONSTER_SCALE')), combo: finite(at(r, 'MONSTER_COMBO')),
      comboStart: finite(at(r, 'COMBO_START')), buff: finite(at(r, 'BUFF')), skills,
    });
  }
  return out;
}

/** A status's option list: its own (item statuses carry them) or its skills_status.json definition's. */
export function statusOptions(s, defOf) {
  if (Array.isArray(s?.options) && s.options.length) return s.options;
  const def = s?.statusIndex != null && typeof defOf === 'function' ? defOf(Number(s.statusIndex)) : null;
  return Array.isArray(def?.options) ? def.options : [];
}

/** The active transformation: {status, row, index} for the first status with STATUS_CHANGE_MONSTER, else null. */
export function transformOf(statuses, defOf, table) {
  for (const s of Array.isArray(statuses) ? statuses : []) {
    if (!s || !(finite(s.remaining, 1) > 0)) continue;
    const o = statusOptions(s, defOf).find(x => x?.code === 'STATUS_CHANGE_MONSTER');
    if (!o) continue;
    const index = finite(o.value);
    const row = table?.get?.(index) || null;
    if (row && row.monsterIndex > 0) return { status: s, row, index };
  }
  return null;
}

/** Which locomotion state the monster body plays for the player's ground speed (cells/s). */
export function monsterFormState(actor, cfg = CFG.monsterForm) {
  if (actor?.dead) return 'die';
  const v = Number(actor?.moveVelocity ?? actor?._moveVel) || 0;
  if (v > cfg.runSpeed) return 'run';
  if (v > cfg.walkSpeed) return 'walk';
  const st = String(actor?.state || '');
  if (/^(attack|skill|cast)/i.test(st)) return 'attack';
  return 'idle';
}

/** 'attack' | 'defense' | null for one option code. */
export function optionSides(code, cfg = CFG.spellCount) {
  const c = String(code || '').toUpperCase();
  const sides = [];
  if (!cfg.attackExclude.includes(c) && cfg.attackPrefixes.some(p => c.startsWith(p))) sides.push('attack');
  if (cfg.defensePrefixes.some(p => c.startsWith(p))) sides.push('defense');
  return sides;
}

/** Counts of active non-harmful statuses raising an attack / defence value, with the counted statuses. */
export function spellCounts(statuses, defOf, isHarmful = () => false, cfg = CFG.spellCount) {
  const out = { attack: 0, defense: 0, attackList: [], defenseList: [] };
  for (const s of Array.isArray(statuses) ? statuses : []) {
    if (!s || !(finite(s.remaining, 1) > 0) || isHarmful(s)) continue;
    const sides = new Set();
    for (const o of statusOptions(s, defOf)) if (finite(o?.value) > 0) for (const k of optionSides(o.code, cfg)) sides.add(k);
    if (sides.has('attack')) { out.attack++; out.attackList.push(s); }
    if (sides.has('defense')) { out.defense++; out.defenseList.push(s); }
  }
  out.attack = Math.min(out.attack, cfg.maxShown); out.defense = Math.min(out.defense, cfg.maxShown);
  return out;
}

/** Long-running statuses for ui_upkeepstatuswnd (button order, at most maxIcons). */
export function upkeepStatuses(statuses, remainingOf = s => Number(s?.remaining), cfg = CFG.upkeep) {
  const out = [];
  for (const s of Array.isArray(statuses) ? statuses : []) {
    if (!s) continue;
    const left = Number(remainingOf(s));
    if (Number.isFinite(left) && left <= 0) continue;
    const total = Math.max(finite(s.duration), Number.isFinite(left) ? left : 0);
    if (s.premium != null || total >= cfg.minDurationSec) out.push(s);
    if (out.length >= cfg.maxIcons) break;
  }
  return out;
}

/** Statuses of a buff window with no drawn cell (rows: arrays of the statuses per row). */
export function overflowCount(rows, perRow = CFG.spellCountLabel.iconsPerRow) {
  return (Array.isArray(rows) ? rows : []).reduce((n, l) => n + Math.max(0, (l?.length || 0) - perRow), 0);
}
export function spellCountText(n, cfg = CFG.spellCountLabel) { return n > 0 ? `${cfg.prefix}${n}` : ''; }
