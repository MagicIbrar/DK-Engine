// Skill data for the running character (docs/formats/skills.md, effects.md).
//
// Loads the runtime packs written by tools/build-skills-runtime.mjs:
//   gamedata/skills/common.json      option codes, aggro, random buffs, weapon statuses, status groups + icons, damage
//                                    text, model effects, condition/hit/game effect scenes, force + group skills
//   gamedata/skills/class_<c>.json   the class record (tabs, clips, skillActions), its skills and the remotes,
//                                    servants, totems, statuses and effect scenes they use
// Anything a pack lacks (another table's status, an effect of another class) comes from the full files
// (gamedata/skills_status.json / skills_effects.json) are required before class readiness;
// the full skills table remains a lazy fallback. All tables share the generation-aware asset cache.
import { fetchJSON } from '../../engine/assets.js';
import { requiredCatalog, awaitCatalog } from './catalog-readiness.js';
import { rootMotionCurves } from './root-motion.js';

const PACK_URL = '/gamedata/skills/';
const ROOT_MOTION_URL = '/gamedata/engine-root-motion/';
const n = v => (Number.isFinite(+v) ? +v : 0);

export class SkillData {
  constructor() {
    this.common = null;
    this.pack = null;            // class pack
    this.classIndex = -1;
    this.skills = new Map();     // index -> skill record
    this.statuses = new Map();   // index -> status def
    this.remotes = new Map();
    this.servants = new Map();
    this.totems = new Map();
    this.scenes = new Map();     // "cate:id" -> scene
    this.units = new Map();      // "file:name" -> unit
    this._full = { status: null, effects: null, skills: null };
    this._fullWanted = new Set();
    this.statusLoadFailure = null; // Bounded transient full-table recovery; unknown IDs stay cached.
    this.onLate = null;          // callback(kind) when a lazy table arrived
  }

  async load(classIndex, { signal } = {}) {
    if (signal?.aborted) throw signal.reason || new DOMException('Cancelled', 'AbortError');
    this.classIndex = Number(classIndex) || 0;
    const [common, pack] = await Promise.all([
      fetchJSON(`${PACK_URL}common.json`),
      fetchJSON(`${PACK_URL}class_${this.classIndex}.json`),
      SkillData.loadRootMotion(this.classIndex),
    ]);
    this.common = common;
    this.pack = pack;
    const put = (map, obj) => { for (const [k, v] of Object.entries(obj || {})) map.set(Number(k), v); };
    put(this.skills, pack.skills);
    put(this.statuses, common.statuses);
    put(this.statuses, pack.statuses);
    put(this.remotes, common.remotes);
    put(this.remotes, pack.remotes);
    put(this.servants, pack.servants);
    put(this.totems, pack.totems);
    for (const src of [common.effects, pack.effects]) {
      for (const [k, v] of Object.entries(src?.scenes || {})) this.scenes.set(k, v);
      for (const [k, v] of Object.entries(src?.units || {})) this.units.set(k, v);
    }
    await awaitCatalog(Promise.all([this._loadFull('effects'), this._loadFull('status')]), signal);
    return this;
  }

  get classRec() { return this.pack?.class || null; }
  /** Basic-attack combo rows of a weapon style (share/combo/combo.csv, result decoded). */
  comboRow(style, step) {
    const rows = this.pack?.combos?.[style] || this.pack?.combos?.[1];
    return rows ? rows[Number(step) % rows.length] || null : null;
  }
  get clips() { return this.pack?.class?.clips || []; }
  get optionCodes() { return this.common?.optionCodes || {}; }

  skill(i) { return this.skills.get(Number(i)) || null; }
  /** Level record L (1-based) of a skill. */
  level(skill, L) { return skill?.levels?.[Math.max(0, (Number(L) || 1) - 1)] || null; }
  remote(i) { return this.remotes.get(Number(i)) || null; }
  servant(i) { return this.servants.get(Number(i)) || null; }
  totem(i) { return this.totems.get(Number(i)) || null; }

  /** Status definition; unknown indices trigger a background load of the full status table (null until then). */
  status(i) {
    const k = Number(i);
    const d = this.statuses.get(k);
    if (d || !(k > 0)) return d || null;
    this._wantFull('status');
    return null;
  }
  /** Promise of a status definition (waits for the full table when the pack lacks it). */
  async statusAsync(i) {
    const d = this.status(i);
    if (d) return d;
    try { await this._loadFull('status'); } catch { return null; }
    return this.statuses.get(Number(i)) || null;
  }
  statusIcon(iconIndex) { return this.common?.icons?.[iconIndex] || null; }
  statusGroup(g) { return this.common?.statusGroups?.[g] || null; }

  /** Effect scene "cate:id" (lazy full-library fallback). */
  scene(key) {
    const s = this.scenes.get(key);
    if (s) return s;
    if (this.common?.missingEffects?.[key]) return null;
    this._wantFull('effects');
    return null;
  }
  unit(key) { return this.units.get(key) || null; }

  /** Model effects (modeleffect.csv groups): status {iconIndex:{start,keep,end}}, spell, pcActionEffects, combat, game, quest (code1=18 overhead marks). */
  get modelEffects() { return this.common?.modelEffects || {}; }
  get damageText() { return this.common?.damageText || null; }
  get aggro() { return this.common?.aggro || null; }
  get forceSkills() { return this.common?.forceSkills || {}; }
  get groupSkills() { return this.common?.groupSkills || {}; }
  get randomBuff() { return this.common?.randomBuff || {}; }
  get weaponStatus() { return this.common?.weaponStatus || {}; }
  get statusDelete() { return this.common?.statusDelete || []; }

  /**
   * SKILL clip of a combo step for the equipped weapon style (skills.md §6): step.style (255 = equipped) resolved
   * through classes[c].skillActions[actionIndex][style], trying the equipped style, the skill's first allowed style,
   * then 1 (BAREHANDS) and 0 (COMMON).
   */
  clipFor(skill, step, equippedStyle) {
    const acts = this.classRec?.skillActions?.[step?.actionIndex];
    const want = Number(step?.style) === 255 ? Number(equippedStyle) : Number(step?.style);
    const order = [want, Number(equippedStyle), ...(skill?.styles || []).map(Number), 1, 0];
    if (acts) {
      for (const st of order) {
        const ci = acts[st];
        if (ci != null && this.clips[ci]?.anim) return { ...this.clips[ci], style: st, clipIndex: ci };
      }
      for (const [st, ci] of Object.entries(acts)) if (this.clips[ci]?.anim) return { ...this.clips[ci], style: Number(st), clipIndex: ci };
    }
    // Native SKILL record whose anim file is absent from Global: its timing and action effect still apply (anim null).
    const native = this.classRec?.animlessActions?.[step?.actionIndex];
    if (native) for (const st of [...order, ...Object.keys(native).map(Number)]) if (native[st]) return { ...native[st], style: st, clipIndex: null };
    return null;
  }

  /** Clip of a ready / charge header action ({effect, actionType, style, actionIndex, timeTick}). */
  clipForAction(skill, act, equippedStyle) {
    if (!act || !(n(act.actionIndex) > 0 || act.actionIndex === 0)) return null;
    return this.clipFor(skill, { actionIndex: act.actionIndex, style: act.style ?? 255 }, equippedStyle);
  }

  // ------------------------------------------------------------------------------------------ lazy full tables
  _wantFull(kind) {
    if (this._fullWanted.has(kind)) return;
    this._fullWanted.add(kind);
    this._loadFull(kind).then(() => { try { this.onLate?.(kind); } catch { /* ignore */ } }).catch(() => { this._fullWanted.delete(kind); });
  }

  _loadFull(kind) {
    if (this._full[kind]) return this._full[kind];
    const url = kind === 'status' ? '/gamedata/skills_status.json' : kind === 'effects' ? '/gamedata/skills_effects.json' : kind === 'skills' ? '/gamedata/skills.json' : null;
    if (!url) return Promise.reject(new Error('Unknown skill catalog '+kind));
    this._full[kind] = requiredCatalog(url, kind).then(j => {
      if (!j) return;
      if (kind === 'status') {
        this.statusLoadFailure = null;
        for (const [k, v] of Object.entries(j.statuses || {})) if (!this.statuses.has(Number(k))) this.statuses.set(Number(k), v);
        if (this.common && j.icons) this.common.icons = { ...j.icons, ...this.common.icons };
      } else if (kind === 'effects') {
        for (const [k, v] of Object.entries(j.scenes || {})) if (!this.scenes.has(k)) this.scenes.set(k, v);
        for (const [k, v] of Object.entries(j.units || {})) if (!this.units.has(k)) this.units.set(k, v);
      } else {
        for (const [k, v] of Object.entries(j.skills || {})) if (!this.skills.has(Number(k))) this.skills.set(Number(k), v);
        for (const [k, v] of Object.entries(j.remotes || {})) if (!this.remotes.has(Number(k))) this.remotes.set(Number(k), v);
      }
    }).catch(err => {
      this._full[kind] = null;
      this._fullWanted.delete(kind);
      if (kind === 'status') this.statusLoadFailure = { retryable: false, status: err.status || null };
      throw err;
    });
    return this._full[kind];
  }

  /** The class's skill-clip root curves (root-motion.js), prepared by the host; once per class, never fatal. */
  static loadRootMotion(classIndex) {
    const c = Number(classIndex) || 0;
    const cache = SkillData._rootMotion ||= new Map();
    if (!cache.has(c)) {
      cache.set(c, Promise.resolve().then(() => fetchJSON(`${ROOT_MOTION_URL}class_${c}.json`)).then(table => {
        rootMotionCurves.load(table?.curves);
        return true;
      }).catch(error => {
        cache.delete(c);
        console.warn('[skills] skill root motion unavailable for class', c, error?.message || error);
        return false;
      }));
    }
    return cache.get(c);
  }

  /** Every skill of another class (GM tools, previews): loads that class pack. */
  static async classPack(classIndex) {
    return fetchJSON(`${PACK_URL}class_${Number(classIndex) || 0}.json`);
  }
}
