// Per-TARGET follower cap, shared by the offline brain (src/game/ai.js) and the authoritative server (server/world/core.mjs,
// monster-hit.mjs).
//
// DATA: share/ai/info.csv dwFollowTarget (monsters.json ai.followTarget). The packed game executable is the only place that says
// what the column does, and it cannot be read, so the MEANING below is an ENGINE-CHOSEN reading (no file states it), taken from the
// column name plus a play report from the original (Global) game (a limit on how many non-aggro monsters can follow you, about 5 or 6, and about
// 10 or 12 with a pet):
//   * a monster may FOLLOW (chase / attack) a target only while the number of monsters already following THAT target is below the
//     monster's OWN dwFollowTarget;
//   * every target is counted separately: a player, the player's servant (pet) and each party member are different targets, so
//     the "x2 with a pet" of that report falls out of per-target counting (6 + 6, 5 + 5) with no special multiplier;
//   * a value of 0 / missing (objects and three monsters without an info.csv row) and every value >= noCapFrom (50, 100, 150,
//     200, 1000: 2,020 of 5,171 rows) count as "no practical cap".
// What a monster does that is OVER the cap is NOT in the data either. The most conservative choice (ENGINE-CHOSEN): it does not
// chase or attack that target, it stays in its current state (idle / explore), it still takes damage (a hit does NOT exempt it),
// it keeps its hostility / pending target and takes a free slot the moment a follower dies, drops the chase or the target goes.
//
// Cost: the book keeps one Set of follower monsters per target. Claim / release are O(1); the only scan is a validation of the
// (at most dwFollowTarget < 50) members of a target that is AT its cap, which also heals a missed release (a monster that was
// deleted, a scene that was disposed). No pass over all monsters is ever made.
import { MONSTER_AI_ENGINE_CHOSEN as C } from '../config/engine-chosen-monster-ai.js';
import { hateSettings } from './hate.js';

/** The follower cap of a monster definition: a whole number of followers, or Infinity (no practical cap). */
export function followLimit(def, noCapFrom = C.followCap.noCapFrom) {
  const v = Number(def?.ai?.followTarget);
  if (!Number.isFinite(v) || v <= 0 || v >= noCapFrom) return Infinity;
  return Math.max(1, Math.floor(v));
}

/** Bound on the other hated targets a refused monster tries (a performance bound only; the same size as the aggrosetting.csv hostility list, 36). */
export const ALT_TARGET_TRIES = 36;

/**
 * Fix: a monster whose most hated target has no free follower slot tries the OTHER targets it hates (most hated first) before it
 * idles, so every party member / servant it has hostility on is a separate target in practice (a party AoE that hits one monster pack with
 * all members gives 3 + 3, not 3). Pure: returns the keys of `record.hate` other than `exceptKey` that are not expired (dwAggroKeepingTick)
 * and pass `isValid`, ordered by hostility (ties keep insertion order), at most `max`; null when there are none. Never deletes an entry.
 */
export function hatedAlternatives(record, exceptKey, aggro, nowMs, isValid, max = ALT_TARGET_TRIES) {
  const hate = record?.hate;
  if (!(hate instanceof Map) || !hate.size || (hate.size === 1 && hate.has(exceptKey))) return null;
  const keep = hateSettings(aggro).keepMs, out = [];
  for (const [who, h] of hate) { if (who === exceptKey || nowMs - h.t > keep || !isValid(who)) continue; out.push([who, h.v]); }
  if (!out.length) return null;
  out.sort((a, b) => b[1] - a[1]);
  if (out.length > max) out.length = max;
  return out.map(e => e[0]);
}

const OFF = /^(0|off|false|no)$/i;
/** Kill switch: DEKARON_FOLLOW_CAP=off (server / node) or ?followcap=off (client page), else the engine-chosen default. */
export function followCapDefaultEnabled() {
  try { const e = globalThis.process?.env?.DEKARON_FOLLOW_CAP; if (e != null && e !== '') return !OFF.test(String(e)); } catch { /* no process */ }
  try { const q = new URLSearchParams(globalThis.location?.search || '').get('followcap'); if (q != null && q !== '') return !OFF.test(q); } catch { /* no location */ }
  return C.followCap.enabled !== false;
}

export class FollowBook {
  constructor({ enabled = followCapDefaultEnabled() } = {}) {
    this.enabled = !!enabled;
    this.slots = new Map();   // target key -> Set of following monsters
    this.stats = { granted: 0, refused: 0, healed: 0 };
  }

  /**
   * Make `m` a follower of `key` (the target's identity: a player id online, the target actor offline) if the monster's own cap
   * allows it. `valid(o, key)` tells whether a member `o` still follows `key` (used only to heal a full target). Returns true when
   * `m` follows `key` afterwards. A refusal leaves a slot `m` holds on another target untouched. Disabled book: always true.
   */
  claim(m, key, limit, valid) {
    if (!this.enabled) return true;
    if (m._fk === key) { const own = this.slots.get(key); if (own && own.has(m)) return true; }
    let s = this.slots.get(key);
    if (limit !== Infinity && s && s.size >= limit) {
      if (valid) for (const o of s) if (o !== m && !valid(o, key)) { s.delete(o); if (o._fk === key) o._fk = null; this.stats.healed++; }
      if (s.size >= limit) { this.stats.refused++; return false; }
    }
    if (m._fk != null && m._fk !== key) this.release(m);
    if (!s) this.slots.set(key, s = new Set());
    s.add(m); m._fk = key;
    this.stats.granted++;
    // a crowd of uncapped followers is never validated at claim time: sweep a growing set at 64, 128, 256 ... members (amortised O(1) per claim),
    // so followers of a scene that was disposed cannot pile up behind a player forever
    if (valid && s.size >= 64 && (s.size & (s.size - 1)) === 0) this._prune(s, key, valid, m);
    return true;
  }

  _prune(s, key, valid, keep) { for (const o of s) if (o !== keep && !valid(o, key)) { s.delete(o); if (o._fk === key) o._fk = null; this.stats.healed++; } }

  /** Non-mutating (apart from healing) preview of claim(): would `m` get a slot on `key`? */
  available(m, key, limit, valid) {
    if (!this.enabled || limit === Infinity) return true;
    const s = this.slots.get(key);
    if (!s || s.has(m)) return true;
    if (s.size < limit) return true;
    if (valid) for (const o of s) if (!valid(o, key)) { s.delete(o); if (o._fk === key) o._fk = null; this.stats.healed++; }
    return s.size < limit;
  }

  /** `m` stops following whatever it follows (death, leash, target gone / switched, disconnect, map change, disposal). */
  release(m) {
    const k = m._fk;
    if (k == null) return;
    const s = this.slots.get(k);
    if (s) { s.delete(m); if (!s.size) this.slots.delete(k); }
    m._fk = null;
  }

  /** Followers currently registered on `key` (a stale entry is only dropped when the target is at its cap). */
  count(key) { return this.slots.get(key)?.size || 0; }
  clear() { for (const s of this.slots.values()) for (const m of s) m._fk = null; this.slots.clear(); }
}
