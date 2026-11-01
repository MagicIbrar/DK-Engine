// Read-only helpers shared by the HUD, windows and audio: they look things up on the live `game`
// object defensively (other modules fill it in; the UI must never crash on a missing field).

let progressionMod = null;
let progressionLoad = null;
/** progression.js (gameplay module) loaded lazily so the UI imports cleanly without it. */
export function loadProgression() {
  if (!progressionLoad) {
    progressionLoad = import('../game/progression.js')
      .then(m => (progressionMod = m))
      .catch(() => null);
  }
  return progressionLoad;
}
export function progression() { return progressionMod; }

export function classDefOf(game) {
  return game?.classDef || game?.data?.classByIndex?.get?.(Number(game?.save?.classIndex)) || null;
}

const skillMaps = new WeakMap();
/** Map skillIndex -> skill record of the player's class (classes.json skills[]). */
export function skillMap(game) {
  const c = classDefOf(game);
  if (!c) return new Map();
  let m = skillMaps.get(c);
  if (!m) { m = new Map((c.skills || []).map(s => [Number(s.index), s])); skillMaps.set(c, m); }
  return m;
}

/** Learned level of a skill (save.skills[index] may be a number or {level}); level-1 skills are innate once reqLevel is met. */
export function skillLevel(game, skill) {
  if (!skill) return 0;
  if (typeof game?.skills?.skillLevel === 'function') {
    try { const lv = Number(game.skills.skillLevel(skill.index)); if (Number.isFinite(lv)) return lv; } catch { /* fall back */ }
  }
  const v = game?.save?.skills?.[skill.index];
  const lv = typeof v === 'object' && v ? Number(v.level) : Number(v);
  if (Number.isFinite(lv) && lv > 0) return lv;
  const plv = game?.save?.level || game?.player?.level || 1;
  return plv >= (skill.reqLevel || 1) ? 1 : 0;
}

function levelRow(skill, lv) {
  const L = skill?.levels;
  if (!Array.isArray(L) || !L.length) return null;
  return L.find(r => r.level === lv) || L[Math.max(0, Math.min(L.length - 1, lv - 1))] || null;
}
export function skillMpCost(skill, lv = 1) {
  const r = levelRow(skill, Math.max(1, lv));
  return Number(r?.mp ?? skill?.mpCost ?? 0) || 0;
}
export function skillCooldownMs(skill, lv = 1) {
  const r = levelRow(skill, Math.max(1, lv));
  return Number(r?.cooldownMs ?? skill?.cooldownMs ?? 0) || 0;
}
export function skillDamage(skill, lv = 1) {
  const r = levelRow(skill, Math.max(1, lv));
  const d = r?.addDamage;
  return Array.isArray(d) ? d[0] : (d ?? skill?.addDamage ?? null);
}

/** EXP needed for the next level (progression.expToNext when available, else exp.json). */
export function expToNext(game, level) {
  const p = progressionMod;
  if (p?.expToNext) {
    try { const v = Number(p.expToNext(level, game.data)); if (Number.isFinite(v) && v > 0) return v; } catch { /* fall back */ }
  }
  const v = Number(game?.data?.expNeeded?.(level));
  if (Number.isFinite(v) && v > 0) return v;
  const row = game?.data?.exp?.levels?.find?.(r => r.level === level);
  return row ? Number(row.exp) : Infinity;
}

/**
 * Progress through the current level. save.exp is taken as exp INTO the current level; if it looks
 * cumulative (>= exp.json totalAtLevel of this level and >= need), the level's start total is subtracted.
 */
export function expProgress(game) {
  const s = game?.save || {};
  const level = s.level || game?.player?.level || 1;
  const need = expToNext(game, level);
  let cur = Number(s.exp) || 0;
  if (cur >= need) {
    const row = game?.data?.exp?.levels?.find?.(r => r.level === level);
    if (row && Number.isFinite(row.totalAtLevel) && cur >= row.totalAtLevel) cur -= row.totalAtLevel;
  }
  const frac = Number.isFinite(need) && need > 0 ? Math.max(0, Math.min(1, cur / need)) : 1;
  return { level, cur, need, frac };
}

/** Monster definition (monsters.json record) behind an actor, if any. */
export function monsterDef(a) {
  return a?.def || a?.monsterDef || a?.data || null;
}
export function isAggressive(a) {
  if (!a || a.kind !== 'monster') return false;
  if (typeof a.aggressive === 'boolean') return a.aggressive;
  return !!monsterDef(a)?.ai?.aggressive;
}
export function isBoss(a) {
  const d = monsterDef(a);
  // monster.dat rank: 0/1/2 normal, 3 boss, 5-7 raid/world boss (docs/formats/monsters.md)
  return !!(a?.boss || (d && Number(d.rank) >= 3));
}

/**
 * Name colour by level difference (share/pc/levelcap.csv via exp.json levelDifference):
 * diff = other - player; bands [diffFrom, diffTo). White fallback.
 */
export function levelDiffColor(game, otherLevel) {
  const bands = game?.data?.exp?.levelDifference;
  const pl = game?.save?.level || game?.player?.level || 1;
  const d = Number(otherLevel) - pl;
  if (Array.isArray(bands)) {
    for (const b of bands) {
      if (d >= b.diffFrom && d < b.diffTo && Array.isArray(b.color)) return `rgb(${b.color[0]},${b.color[1]},${b.color[2]})`;
    }
    if (d >= 200) return 'rgb(255,51,0)';
    if (d < -200) return 'rgb(0,255,0)';
  }
  return d >= 3 ? 'rgb(255,51,0)' : d < -8 ? 'rgb(0,255,0)' : 'rgb(255,255,255)';
}

/** NPC definition (npcs.json record, with .index) behind an NPC actor. */
export function npcDef(game, npc) {
  const d = npc?.def || npc?.npcDef || null;
  const idx = d?.index ?? npc?.npcIndex ?? npc?.index;
  const fromData = idx != null ? game?.data?.npcs?.npcs?.[idx] : null;
  return { ...(fromData || {}), ...(d || {}), index: idx != null ? Number(idx) : undefined };
}

/** The player's weapon sound family (sound.json hit.swing/impact keys) from classes.json weapon.type. */
const WEAPON_SOUND = {
  SHORT_SWORD: 'dag', SWORD: 'swd', LONG_SWORD: 'lsw', GREAT_SWORD: 'lsw', SPEAR: 'lsw', POLEARM: 'laxe',
  MACE: 'mac', GREAT_MACE: 'mac', AX: 'axe', GREAT_AX: 'laxe', BOW: 'bow', CROSS_BOW: 'cbs', STAFF: 'sta',
  WAND: 'wan', TWIN_SWORD: 'dag', BLOODWHIP: 'whip', GAUNTLET: 'gtl', ALOKEN_SPEAR: 'lsw', DUALBLADE: 'swd',
  SCYTHE: 'laxe', ORB: 'wan', GREAT_FALCHION: 'lsw', SEALFORCE: 'mac', GUN: 'cbs', RAPIER: 'swd', LILY: 'wan',
};
export function weaponSound(classDef) {
  return WEAPON_SOUND[classDef?.weapon?.type] || 'fist';
}
