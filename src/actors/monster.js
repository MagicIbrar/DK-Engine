// Monsters (docs/ARCHITECTURE.md §3.5, docs/formats/monsters.md "Engine recipe").
//
//   def   = monsters.json monsters[idx] (+ index, as GameData.monster() returns it)
//   shape = monsters.json shapes[def.shape]         {mesh, tpack, textures{diffuse[slot]}}
//   set   = monsters.json actionSets[def.act]       {skel, clips[[anim, timeLength, startInter, endInter, timing, split,
//                                                    ...]], actions{ATTACK:[...], ...}, states{idle, idleCombat, walk,
//                                                    run, die, attack[], hit[], ...}, unboundClips?}
// One SkinnedModel per (skel, mesh) is shared by every monster of that shape (ModelCache caches it); each Monster has
// its own SkinnedInstance + Animator. A missing skeleton renders the mesh in bind pose; a mesh without geometry (the
// invisible trap types) gives an empty body with default height/radius; a missing mesh leaves the actor invisible but
// fully functional for gameplay.
//
// States: 'idle' (STAND 0), 'idleCombat' (STAND 1), 'walk', 'run', 'hit' (DEFEAT, variant = direction index), 'die',
// 'attack' / 'skill' / 'cast' with opts.variant = the ATTACK action index (monsters.json attackActionIndex: 0 melee,
// 1 powerMelee, ... 4 range, 10-13 aggro1-4) -> actions.ATTACK[variant], skipping -1 and unboundClips, falling back to
// states.attack[0]; opts.timeLength stretches it. Any other states key ('block', 'guard', 'revive', 'appear', ...) by
// name. Missing clips fall back along actor.js FALLBACKS (walk <-> run, idleCombat -> idle, attack -> idleCombat).
// There is no per-monster scale in the client (monsters.md §5); def.scale / shape.scale are honoured if a later data
// build adds one.
// Effect-body monsters (def.body 'effect', src/game/effect-body.js: Ghostman_knight 3810 / Ghostman_archer 3813) keep
// the empty native body for picking, nameplate and combat, and each clip plays its authored body effect
// (def.bodyEffects[clip effect id], monster-effect-body.js), so they are seen only while they attack, block, guard, take a
// hit or die, as in the original client.
import { Actor, actionSetSpec, bodyRadius, LOOP_STATES } from './actor.js';
import { bodyEffectRef } from '../game/effect-body.js';
import { monsterBodyEffects } from './monster-effect-body.js';
import {authoredActionEffects,stopActionEffects} from './authored-action-effects.js';

const EMPTY_HEIGHT = 1.6;   // body height for models without geometry (nameplates, picking)

export class Monster extends Actor {
  /**
   * @param {object} game
   * @param {object} def    monsters.json monsters[idx] (+ index)
   * @param {{monsterIndex?:number, x:number, z:number, respawnSec?:number}} [spawn]  FILE frame
   */
  constructor(game, def = {}, spawn = null) {
    super(game, { kind: 'monster', name: def?.name || `Monster ${def?.index ?? spawn?.monsterIndex ?? ''}`.trim(), level: Number(def?.level) || 1 });
    this.def = def || {};
    if (this.def.index == null && spawn?.monsterIndex != null) this.def = { index: Number(spawn.monsterIndex), ...this.def };
    this.monsterIndex = this.def.index ?? spawn?.monsterIndex ?? null;
    this.spawn = spawn || null;
    this.maxHp = this.hp = Math.max(1, Number(this.def.hp) || 1);
    this.maxMp = this.mp = 0;
    this.fadeOnDeath = true;
    this.role = this.def.role || 'creature';
    this.shape = null;
    this.actionSet = null;
    this._unbound = new Set();
    const sc = Number(this.def.scale ?? 1);
    this.scale = sc > 0 ? sc : 1;
    this.yaw = Math.random() * Math.PI * 2 - Math.PI;       // spawn rows carry no direction
    if (spawn && Number.isFinite(Number(spawn.x)) && Number.isFinite(Number(spawn.z))) this.setPosition(Number(spawn.x), Number(spawn.z));
  }

  get db() { return this.game?.data?.monsters || null; }

  /** Aggressive ring colour for monsters that attack on sight. */
  _ringColor() { return this.def?.ai?.aggressive ? 0xff5a3c : 0xffd257; }

  async _load() {
    const db = this.db || {};
    const def = this.def;
    const shape = (this.shape = db.shapes?.[def.shape] || null);
    const set = (this.actionSet = db.actionSets?.[def.act] || null);
    this._unbound = new Set(set?.unboundClips || []);
    const shapeScale = Number(shape?.scale);
    if (def.scale == null && shapeScale > 0) this.scale = shapeScale;
    const models = this.game?.models;
    if (shape?.mesh && models) {
      const model = await models.loadSkinned({
        skelKey: set?.skel || null,
        parts: [{ meshKey: shape.mesh, tpackKey: shape.tpack || null, textures: shape.textures || null }],
      });
      if (this.disposed) return;
      if (model) this._setSkinned(model);
    }
    this._measure();
    if (def.body === 'effect') await this._measureEffectBody(shape);
    // the clips the AI will ask for, so they switch on the frame they are requested
    const variants = new Set([0]);
    const idx = db.attackActionIndex || {};
    for (const k of Object.keys(def.attacks || {})) if (idx[k] != null) variants.add(idx[k]);
    await this._preload([['idle'], ['idleCombat'], ['walk'], ['run'], ['die'], ['hit', { variant: 0 }],
      ...[...variants].map(v => ['attack', { variant: v }])]);
    // the authored body scenes load in the background so the first swing / hit already shows its body
    if (def.body === 'effect') { const fx = monsterBodyEffects(this.game); for (const ref of Object.values(def.bodyEffects || {})) void fx?.load(ref); }
    else {const fx=authoredActionEffects(this.game);await fx.preload(this).catch(error=>console.warn('[monsters] action effect preload failed',error));if(!this.disposed)fx.startShape(this);}
  }

  /** Any action first ends the previous body effect, then plays the new clip's own authored body effect. */
  play(state, opts = {}) {
    stopActionEffects(this);
    if (this.def?.body !== 'effect') return super.play(state, opts);
    this._cutBodyEffect();
    const result = super.play(state, opts);
    // not built yet: Actor keeps the request in _pendingPlay and replays play() once loaded (the effect starts then, once).
    // A resumed clip (startAt / startPhase: the desynchronised first pose, a corpse already lying there) is no new action.
    if (this.loaded && !this.disposed && !(Number(opts?.startAt) > 0) && !(Number(opts?.startPhase) > 0)) {
      const spec = this._specFor(state, opts), ref = bodyEffectRef(this.def, this.actionSet, spec?.clipIndex);
      const fx = ref ? monsterBodyEffects(this.game) : null;
      if (fx) { try { this._bodyFx = fx.play(this, ref) || null; } catch (error) { console.warn('[monsters] body effect failed', error); } }
    }
    return result;
  }

  _cutBodyEffect() {
    const h = this._bodyFx;
    this._bodyFx = null;
    if (h) { try { h.stop?.(true); } catch { /* ignore */ } }
  }

  update(dt) {
    super.update(dt);
    if (this.def?.body === 'effect' && !this.disposed) monsterBodyEffects(this.game)?.tick(dt);
    this.game.authoredActionEffects?.tick(dt,this);
  }

  dispose() {
    stopActionEffects(this,true);
    this._cutBodyEffect();
    super.dispose();
  }

  _onClipStart(spec,clip,opts){
    super._onClipStart(spec,clip,opts);
    if(this.def?.body!=='effect')authoredActionEffects(this.game).start(this,spec,clip,opts);
  }

  _measure() {
    const m = this.model;
    if (!m || m.empty || !m.bbox || m.bbox.isEmpty()) {
      this.height = EMPTY_HEIGHT;
      this.radius = Math.max(0.4, Number(this.def.width) > 0 ? Number(this.def.width) * 0.45 : 0.5);
      return;
    }
    this.height = Math.max(0.5, m.height || m.bbox.max.y || EMPTY_HEIGHT);
    this.radius = bodyRadius(m.bbox, this.def.width);
  }

  /**
   * An effect body keeps its empty native model, but picking and the nameplate use the authored 'picking' helper of the
   * real body mesh the effects draw (def.bodyMesh beside the *_none shape mesh; Ghostman_knight: 4.56 high), not the
   * default empty-body size. The *_none mesh's own helper repeats those X/Z bounds with an unusable Y range.
   */
  async _measureEffectBody(shape) {
    const models = this.game?.models;
    if (!this.def?.bodyMesh || !shape?.mesh || typeof models?.mesh !== 'function') return;
    try {
      const parsed = await models.mesh(String(shape.mesh).replace(/[^/]*$/, '') + this.def.bodyMesh);
      const pick = (parsed?.helpers || []).find(h => /^picking$/i.test(h.name))?.bbox;
      if (!pick || !(pick.max?.[1] > 0) || this.disposed) return;
      const [x0, y0, z0] = pick.min, [x1, y1, z1] = pick.max;
      this.height = Math.max(0.5, y1);
      this.radius = bodyRadius({ isEmpty: () => false, min: { x: x0, y: Math.max(0, y0), z: z0 }, max: { x: x1, y: y1, z: z1 } }, this.def.width);
    } catch { /* keep the default empty-body size */ }
  }

  _specFor(state, opts) {
    return actionSetSpec(this.actionSet, this._unbound, state, opts || {});
  }

  /** {len, hitAt} of the clip an ATTACK index plays (same resolution as play('attack', {variant})). */
  attackTiming(variant = 0) {
    const s = actionSetSpec(this.actionSet, this._unbound, 'attack', { variant });
    if (!s) return { len: 1, hitAt: 0.5 };
    const len = s.duration > 0 ? s.duration : 1;
    const t = s.timing > 0 ? Math.min(1, s.timing) : 0.5;
    return { len, hitAt: len * t };
  }

  _restState() {
    if (this.dead) return null;
    if (LOOP_STATES.has(this.state)) return this.state;
    return 'idleCombat';
  }
}
