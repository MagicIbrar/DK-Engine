// Town / field NPCs (docs/ARCHITECTURE.md §3.5, docs/formats/monsters.md §4).
//
//   def       = { index, ...npcs.json npcs[index] }   {name, shape, desc, comm, jobs[[JobType, JobIndex]], roles[], act,
//                                                      static?, minimapColor, ...}
//   placement = world.npcPlacements[i]                 {npcIndex, x, z, dirDeg, warpX, warpZ, isEvent, desc} (FILE frame)
// Body: npcs.json shapes[def.shape] + actionSets[def.act] (skinned, STAND loop: one long idle clip, 12.66 s for Berks).
// NPCs flagged `static` (mailboxes, notice boards, gates, corpses: 974 of them) or without a skeleton are drawn with
// the StaticModel in bind pose.
// Facing: rotation.y = dirDeg * PI / 180 (ARCHITECTURE.md §1; coords.md verified warp = position + 1.4 * facing on
// 77 NPCs). The original NPCs keep that facing when you talk to them, so faceTowards() is a no-op unless
// npc.turnToTalk is set to true (then it turns, and turns back to its placement facing after TURN_BACK_SECONDS).
import { Actor, actionSetSpec, bodyRadius } from './actor.js';
import { npcPresentation } from './npc-presentation.js';
import {authoredActionEffects,stopActionEffects} from './authored-action-effects.js';

const TURN_BACK_SECONDS = 8;

export class NPC extends Actor {
  /**
   * @param {object} game
   * @param {object} def        { index, ...npcs.json entry }
   * @param {{npcIndex?:number, x:number, z:number, dirDeg?:number, warpX?:number, warpZ?:number}} [placement]
   */
  constructor(game, def = {}, placement = null) {
    super(game, { kind: 'npc', name: def?.name || `NPC ${def?.index ?? placement?.npcIndex ?? ''}`.trim(), level: 0 });
    this.def = def || {};
    if (this.def.index == null && placement?.npcIndex != null) this.def = { index: Number(placement.npcIndex), ...this.def };
    this.npcIndex = this.def.index ?? placement?.npcIndex ?? null;
    this.index = this.npcIndex;
    this.placement = placement || null;
    this.roles = Array.isArray(this.def.roles) ? this.def.roles : [];
    this.jobs = Array.isArray(this.def.jobs) ? this.def.jobs : [];
    this.hp = this.maxHp = 1;
    this.invulnerable = true;
    this.turnToTalk = false;
    this._turnBackT = 0;
    this.homeYaw = ((Number(placement?.dirDeg) || 0) * Math.PI) / 180;
    this.yaw = this.homeYaw;
    if (placement && Number.isFinite(Number(placement.x)) && Number.isFinite(Number(placement.z))) {
      this.setPosition(Number(placement.x), Number(placement.z));
    }
  }

  get db() { return this.game?.data?.npcs || null; }

  /** First service of the NPC ('SHOP', 'TELEPORT', 'RETURN', 'QUEST', ...), or null. */
  get role() { return this.roles[0] || null; }

  /** Where the client puts a player talking to / warped by this NPC (placement warp point, FILE frame). */
  get interactPoint() {
    const p = this.placement;
    if (p && Number(p.warpX) > 0 && Number(p.warpZ) > 0) return { x: Number(p.warpX), z: Number(p.warpZ) };
    const f = this.facing();
    return { x: this.x + f.x * 1.4, z: this.z + f.z * 1.4 };
  }

  hasRole(name) { return this.roles.includes(name); }

  _ringColor() { return 0x7fd8ff; }

  async _load() {
    const db = this.db || {};
    const presentation = npcPresentation(this, db);
    const models = this.game?.models;
    this.shape = presentation.shape;
    this.actionSet = presentation.actionSet;
    this.presentationSourceNpc = null;
    this.presentationFallbackReason = null;
    for (const body of [presentation, presentation.fallback].filter(Boolean)) {
      const shape = body.shape, set = body.actionSet;
      if (!shape?.mesh || !models) continue;
      const part = { meshKey: shape.mesh, tpackKey: shape.tpack || null, textures: shape.textures || null };
      const skinned = set?.skel && !body.static;
      let model;
      try {
        model = skinned
          ? await models.loadSkinned({ skelKey: set.skel, parts: [part] })
          : await models.loadStatic(shape.mesh, { tpackKey: part.tpackKey, textures: part.textures });
      } catch (error) {
        // Only the optional generated appearance can recover with a native body.
        // Original body errors still reach Actor.load's existing diagnostic.
        if (!body.sourceNpc || !presentation.fallback) throw error;
        if (this.disposed) return;
        console.warn('[npc] optional dungeon entrance appearance failed; using native placeholder', error);
        continue;
      }
      if (this.disposed) return;
      // Optional entrance appearance may be absent/empty in a partial client.
      // Keep the source placeholder's geometry and selection capsule available.
      if (!model || (body.sourceNpc && (model.empty || !model.parts?.length))) continue;
      this.shape = shape;
      this.actionSet = set;
      this.presentationSourceNpc = body.sourceNpc || null;
      if (body !== presentation) this.presentationFallbackReason = 'native-entrance-model-unavailable';
      if (skinned) this._setSkinned(model); else this._setStatic(model);
      break;
    }
    this._unbound = new Set(this.actionSet?.unboundClips || []);
    this._measure();
    await this._preload([['idle']]);
    await authoredActionEffects(this.game).preload(this).catch(error=>console.warn('[npc] action effect preload failed',error));
    if(!this.disposed)authoredActionEffects(this.game).startShape(this);
  }

  _measure() {
    const m = this.model;
    if (!m || !m.bbox || m.bbox.isEmpty()) { this.height = 1.8; this.radius = 0.45; return; }
    this.height = Math.max(0.5, m.height || m.bbox.max.y || 1.8);
    this.radius = bodyRadius(m.bbox);
  }

  _specFor(state, opts) {
    return actionSetSpec(this.actionSet, this._unbound, state, opts || {});
  }

  _restState() { return 'idle'; }

  play(state,opts={}){stopActionEffects(this);return super.play(state,opts);}
  _onClipStart(spec,clip,opts){super._onClipStart(spec,clip,opts);authoredActionEffects(this.game).start(this,spec,clip,opts);}
  dispose(){stopActionEffects(this,true);super.dispose();}

  _snapY() {
    // Authored NPCs stand on their placement's supporting surface. Object ground helpers may
    // arrive after spawning; a walking actor's step limit would keep these NPCs below a pedestal.
    super._snapY(true);
  }

  faceTowards(x, z) {
    if (!this.turnToTalk) return;
    super.faceTowards(x, z);
    this._turnBackT = TURN_BACK_SECONDS;
  }

  update(dt) {
    if (this._turnBackT > 0 && dt > 0) {
      this._turnBackT -= dt;
      if (this._turnBackT <= 0) this._yawGoal = this.homeYaw;
    }
    super.update(dt);
    this.game.authoredActionEffects?.tick(dt,this);
  }
}
