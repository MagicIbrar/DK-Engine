// SKILL-MASTER rules (pure: no DOM, no game). Windows: index.js. ENGINE-CHOSEN values:
// src/config/engine-chosen-skill-master.js.
import { SKILL_MASTER_ENGINE_CHOSEN as C } from '../../config/engine-chosen-skill-master.js';
export { C as SKILL_MASTER_ENGINE_CHOSEN };

export const SKILL_MASTER_SCRIPTS = Object.freeze({
  master: 'game2/skill/ui_skillmasterwnd.txt',   // skillmasterwnd 181x167, title 100:4 "Learn Skill"
  blind: 'game2/skill/ui_skillblindwnd.txt',     // skill_blind_win (position inverse inverse = full screen)
});
export const WINDOW = Object.freeze({ master: 'skillmasterwnd', blind: 'skill_blind_win' });
export const CONTROLS = Object.freeze({
  title: 'lbl_title', close: 'btn_skillmaster_close', ok: 'btn_skillmaster_ok', icon: 'pan_skill_icon', label: 'lbl_skillmaster',
  hole: 'pan_clickable_area', blocks: ['pan_unclickable_area_0', 'pan_unclickable_area_1', 'pan_unclickable_area_2', 'pan_unclickable_area_3'],
  centre: 'pan_skillscreen_center',
});
export const TITLE = Object.freeze({ group: 'NORMAL', cate: 100, code: 4 });

const num = v => (Number.isFinite(Number(v)) ? Number(v) : 0);
const plain = s => String(s ?? '').replace(/<center>/gi, '').replace(/<[^>]+>/g, '');

/** lbl_skillmaster: the client's own learn line 60:25 ("You have learned the skill:  [") + name + "]". */
export function labelText(message, name) {
  const m = plain(message);
  const n = plain(name).trim();
  return n ? `${m}${n}]` : '';
}

/** Skill indexes learned (level 0 -> >= 1) between two save.skills maps, ascending. */
export function newLearns(prev, next) {
  const p = prev || {}, out = [];
  for (const [k, v] of Object.entries(next || {})) if (num(v) >= 1 && !(num(p[k]) >= 1)) out.push(Number(k));
  return out.filter(Number.isInteger).sort((a, b) => a - b);
}

/**
 * Baseline of learned skills per character. observe() returns the first learns since the last observation of the
 * same character; the first observation of a character (log in, character switch, reconnect) is only the baseline.
 */
export class LearnTracker {
  constructor() { this.id = undefined; this.skills = null; }
  reset() { this.id = undefined; this.skills = null; }
  has(id) { return this.skills != null && this.id === id; }
  sync(id, skills) { this.id = id; this.skills = { ...(skills || {}) }; }
  observe(id, skills) {
    const fresh = !this.has(id);
    const out = fresh ? [] : newLearns(this.skills, skills);
    this.sync(id, skills);
    return out;
  }
  /** previous level of a skill in the baseline (null = no baseline for this character) */
  before(id, index) { return this.has(id) ? num(this.skills[index]) : null; }
}

/**
 * A local skills-engine skilllearn event -> the skill index to announce, or null. Only an announced (not silent)
 * learn that reaches level 1 from unlearned (baseline level 0, or no baseline yet) counts.
 */
export function localLearn(event, previousLevel) {
  if (!event || event.server || event.reset || !event.skill) return null;
  if (event.announced === false && !C.popupOnSilent) return null;
  const level = num(event.level);
  if (level < 1) return null;
  const was = previousLevel == null ? (level === 1 ? 0 : 1) : num(previousLevel);
  if (was >= 1) return C.popupOnLevelUp ? Number(event.skill.index) : null;
  return Number.isInteger(Number(event.skill.index)) ? Number(event.skill.index) : null;
}

/** Push skill indexes onto the popup queue (no duplicates, the shown one included; capped). Returns the queue. */
export function enqueue(queue, indexes, showing = null) {
  for (const i of indexes) {
    if (i === showing || queue.includes(i)) continue;
    if (!C.queue && (queue.length || showing != null)) break;
    if (queue.length + (showing != null ? 1 : 0) >= C.maxQueue) break;
    queue.push(i);
  }
  return queue;
}

/**
 * The blind around a cut-out: pan_clickable_area on the hole, the four blocking panels above / below / left /
 * right of it, filling the screen. Rects are [x, y, w, h] in reference px; the hole is clamped to the screen.
 */
export function blindRects(hole, screen) {
  const W = Math.max(0, Math.round(num(screen?.w))), H = Math.max(0, Math.round(num(screen?.h)));
  const x = Math.min(W, Math.max(0, Math.round(num(hole?.x)))), y = Math.min(H, Math.max(0, Math.round(num(hole?.y))));
  const w = Math.min(W - x, Math.max(0, Math.round(num(hole?.w)))), h = Math.min(H - y, Math.max(0, Math.round(num(hole?.h))));
  return {
    hole: [x, y, w, h],
    blocks: [[0, 0, W, y], [0, y + h, W, H - y - h], [0, y, x, h], [x + w, y, W - x - w, h]],
  };
}