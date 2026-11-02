// Pets: the pet item equipped in slot 19 is summoned (casting bar, share/system_variable.csv 13/14: 3000 / 1000 ms) as a
// companion that follows the character, plays its own action table (share/action/action/pet/<item>.act.<shape>.dat:
// STAND / MOVE index 0 walk, 1 run / SM_STAND / SM_MOVE under water), picks up drops for its master when the "Auto Item
// Pickup" setting is on (the pet management window's filters: equipment by grade / accessories / enhancement items /
// misc / socket items; dil always, quest items never), stores them in the PET INVENTORY, and grants its random options
// (petoption.csv group of the pet: N 1 option, R 2, U 3 - the count is not in the data, see docs/MOUNTS.md) and its
// unique skill (petskill.csv -> petoption group 100) to the character while summoned.
// Legacy pets (share/creature/pet.csv: Woody, Wiki ...) use their monster models and anims (pet01 ... pet10).
import { Actor, LOOP_STATES } from '../../actors/actor.js';
import { ACT, EQUIP_SLOT } from './data.js';
import { equippedItem } from './riding.js';
import { nativeMountEffects, nativeVehicleEffect } from './native-effects.js';
import {canDiscardDef} from '../items/flags.js';

const FOLLOW_DIST = 1.8;          // units behind / beside the master
const TELEPORT_DIST = 22;         // farther than this: the pet reappears next to the master
const PICK_RADIUS = 9;            // drops within this range of the master are collected
const PICK_REACH = 0.7;
const normKey = k => String(k || '').trim().replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();

// ============================================================================================ PetActor
export class PetActor extends Actor {
  constructor(game, def, state, data, {deferEffects=false}={}) {
    super(game, { kind: 'pet', name: state?.name || def.n || 'Pet', level: 0 });
    this.def = def;
    this.data = data;
    this.petState = state || {};
    this.cullable = false;
    this.radius = 0.3;
    this.hp = this.maxHp = 1;
    this.invulnerable = true;
    this.turnRate = 10;
    this.actionEffectToken = {};
    this.enterEffectToken = {}; this.leaveEffectToken = {};
    this.deferEffects = deferEffects; this._effectsReady = false;
  }

  async _load() {
    const d = this.def, models = this.game?.models;
    const skel = d.kind === 'pet' ? d.table?.skel : d.skel;
    if (!models || !d.mesh) return;
    const part = { meshKey: d.mesh, tpackKey: d.tpack || null, textures: d.textures || null };
    if (skel) {
      const model = await models.loadSkinned({ skelKey: skel, parts: [part] });
      if (this.disposed) return;
      if (model) this._setSkinned(model);
    }
    if (!this.model) {
      const sm = await models.loadStatic(d.mesh, { tpackKey: part.tpackKey, textures: part.textures });
      if (this.disposed) return;
      if (sm) this._setStatic(sm);
    }
    const bb = this.model?.bbox;
    this.height = bb && !bb.isEmpty() ? Math.max(0.3, bb.max.y) : 0.8;
    await this._preload([['idle'], ['run'], ['walk']]);
    if (this.disposed) return;
    this.nativeEffects = nativeMountEffects(this.game);
    try {
      this.effectSource = await this.nativeEffects.petSource(d);
      if (!this.disposed && !this.deferEffects) this._activateEffects();
    } catch (error) { this.nativeEffects.warn(`pet:${d.shape}`, error); }
  }

  get swimming() {
    const f = Number(this.game?.world?.info?.row?.MoveSpeedFactor);
    return f > 0 && f < 1;
  }

  _specFor(state) {
    const d = this.def, swim = this.swimming;
    if (d.kind === 'pet') {
      const t = d.table;
      if (!t) return null;
      let action = swim ? ACT.SM_STAND : ACT.STAND, index = 0;
      if (state === 'run') { action = swim ? ACT.SM_MOVE : ACT.MOVE; index = 1; }
      else if (state === 'walk') { action = swim ? ACT.SM_MOVE : ACT.MOVE; index = 0; }
      else if (state !== 'idle' && state !== 'idleCombat') return null;
      const rows = t.rows || [];
      const r = rows.find(x => x[1] === action && x[2] === index) || rows.find(x => x[1] === action)
        || (swim ? rows.find(x => x[1] === (action === ACT.SM_MOVE ? ACT.MOVE : ACT.STAND) && x[2] === index) : null);
      const anim = r ? this.data?.anim(r[3]) : null;
      return anim ? { key: anim, duration: r[4] > 0 ? r[4] : null, loop: true,
        nativeEffect: r.length > 5 ? Number(r[5]) || 0 : nativeVehicleEffect(this.effectSource?.native, {anim, style:r[0], action:r[1], index:r[2]}) } : null;
    }
    // legacy pets: [anim, seconds]
    const pick = state === 'run' ? (swim ? d.swimRun : d.run) || d.run || d.walkA
      : state === 'walk' ? (swim ? d.swimWalk : d.walkA) || d.walkA || d.run
        : state === 'idle' || state === 'idleCombat' ? (swim ? d.swimStand : d.stand) || d.stand : null;
    return pick ? { key: pick[0], duration: pick[1] || null, loop: LOOP_STATES.has(state) || true } : null;
  }

  _restState() { return 'idle'; }
  _activateEffects() {
    if(this.disposed||this._effectsReady)return;
    this._effectsReady=true;this._effectWorld=this.game.world;
    this.nativeEffects?.bind(this,this,'pet',this.effectSource?.shape);
  }
  appear() {
    if(this.disposed||this._entered)return;
    this._activateEffects();this._entered=true;
    const ref=this.effectSource?.transitions?.enter;
    if(!ref)return;
    // Some native shape IDs are the same finite summon scene. That shape lane
    // already plays it once, so never double the same appearance.
    const rows=this.nativeEffects._rows;
    void Promise.resolve(rows).then(map=>{
      if(this.disposed||!this._entered||this.game.world!==this._effectWorld)return;
      const shape=map?.get(`pet:${this.effectSource?.shape}`)?.ref;
      if(JSON.stringify(shape)===JSON.stringify(ref))return;
      this.nativeEffects.transition(this.enterEffectToken,this,ref);
    });
  }
  depart() {
    if(this.disposed||!this._entered||this.game.world!==this._effectWorld)return;
    this._entered=false;this.nativeEffects?.stop(this.enterEffectToken);
    const ref=this.effectSource?.transitions?.leave;
    if(ref)this.nativeEffects.transition(this.leaveEffectToken,this.nativeEffects.snapshot(this,ref),ref);
  }
  play(state, opts) { this.nativeEffects?.stop(this.actionEffectToken); return super.play(state, opts); }
  _onClipStart(spec) { if(this._effectsReady)this.nativeEffects?.bind(this.actionEffectToken, this, 'pet', spec.nativeEffect === this.effectSource?.shape ? 0 : spec.nativeEffect); }
  update(dt) { super.update(dt); this.nativeEffects?.tick(dt); }
  dispose() { this._entered=false;this.nativeEffects?.stop(this); this.nativeEffects?.stop(this.actionEffectToken);this.nativeEffects?.stop(this.enterEffectToken); super.dispose(); }
}

// ============================================================================================ PetManager
export class PetManager {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.data = sys.data;
    this.actor = null;
    this.item = null;
    this.busy = false;
    this._target = null;     // drop being collected
    this._repick = 0;
    this._blessT = 0;
  }

  get player() { return this.game.player; }
  get summoned() { return !!this.actor; }

  equipped() {
    const e = equippedItem(this.game, EQUIP_SLOT.pet, 'pet');
    if (e && this.data.isPet(e.index)) return e;
    return this.sys.testPet && this.data.isPet(this.sys.testPet) ? { index: this.sys.testPet, inst: null } : null;
  }

  /** Persistent state of a pet (name, options, soul chain count, inventory, settings). Stored on the item instance
   *  when the items system gives one, else in save.pets[item]. */
  state(eq = this.equipped()) {
    if (!eq) return null;
    const s = eq.inst ? (eq.inst.pet ||= {}) : ((this.game.save.pets ||= {})[eq.index] ||= {});
    const def = this.data.pet(eq.index);
    if (!s.init) {
      s.init = true;
      s.name = s.name || '';
      s.named = !!s.named;
      s.soulLeft = Number(def?.cr?.raw?.PetSoulChangeNum ?? 10);
      s.opts = s.opts || this.rollOptions(def);
      s.inv = s.inv || [];
      s.settings = s.settings || { auto: true, normal: true, accessory: true, magic: true, noble: true, divine: true, legend: true, enhance: true, etc: true, socket: true };
      s.born = s.born || Date.now();
      s.blessLeft = Number(def?.blessTime ?? def?.cr?.raw?.BlessTime ?? 0) || 0;
    }
    return s;
  }

  /** Grade of a pet: 0 normal (N), 1 rare (R), 2 unique (U) from its option group. */
  grade(def) { const g = Number(def?.cr?.og ?? def?.og ?? 1); return g >= 3 ? 2 : g === 2 ? 1 : 0; }

  /** Random options of a pet: one roll per slot in its option group (weights of petoption.csv Range, 1,000,000). */
  rollOptions(def) {
    const og = Number(def?.cr?.og ?? def?.og ?? 0);
    const rows = (this.sys.data.ui?.petTables?.option || []).filter(r => r.group === og && r.weight > 0);
    const n = this.grade(def) + 1;
    const out = [];
    if (!rows.length) return out;
    const total = rows.reduce((a, r) => a + r.weight, 0);
    for (let i = 0; i < n; i++) {
      let x = Math.random() * total, row = rows[rows.length - 1];
      for (const r of rows) { x -= r.weight; if (x <= 0) { row = r; break; } }
      const v = row.min + Math.floor(Math.random() * (row.max - row.min + 1));
      out.push([row.optionType, v, row.index]);
    }
    return out;
  }

  /** Options the summoned pet gives its master: random options + its unique skill options (group 100). */
  activeOptions() {
    if (!this.actor) return [];
    const eq = this.equipped();
    const s = this.state(eq);
    const def = this.data.pet(eq?.index);
    const out = (s?.opts || []).map(o => [o[0], o[1]]);
    const skill = (this.sys.data.ui?.petTables?.skill || []).find(r => r.index === Number(def?.cr?.skill ?? def?.skill ?? 0));
    for (const sk of skill?.skills || []) {
      const row = (this.sys.data.ui?.petTables?.option || []).find(r => r.index === sk.option);
      if (row && row.optionType >= 0) out.push([row.optionType, row.max]);
    }
    return out;
  }

  // ------------------------------------------------------------------ summon / unsummon
  async summon() {
    const g = this.game, sys = this.sys, p = this.player;
    if (this.actor || this.busy || !p || p.dead) return false;
    const eq = this.equipped();
    if (!eq) { sys.say('petNone'); return false; }
    const def = this.data.pet(eq.index);
    const row = g.world?.info?.row;
    if (row && String(row.IsPet ?? '1').trim() !== '' && Number(row.IsPet) === 0) { sys.say('petMap'); return false; }
    const s = this.state(eq);
    if (s.sleep) { sys.say('petSleeping'); return false; }
    if (eq.inst?.expiresAt && Date.now() > eq.inst.expiresAt && !s.eternal) { sys.say('petExpired'); return false; }
    if (g.skills?.busy) { sys.say('petBusy'); return false; }
    this.busy = true;
    await sys.data.loadUI();
    const ok = await sys.castDelay(sys.text('petSummoning'), sys.data.sys.petSummonMs);
    this.busy = false;
    if (!ok) { sys.say('petCanceled'); return false; }
    return this.spawn(eq, def, s);
  }

  async spawn(eq, def, s) {
    const p = this.player, world = this.game.world;
    if (!def || !p) return false;
    if (!s.opts?.length && this.sys.data.ui) s.opts = this.rollOptions(def);
    // an appearance change (pet shape change window, petshapechange.csv) shows another pet's model
    const look = (s.shape && this.data.pet(s.shape)) || def;
    const a = new PetActor(this.game, look, s, this.data, {deferEffects:true});
    const f = p.facing();
    a.setPosition(p.x - f.x * FOLLOW_DIST + f.z * 0.8, p.z - f.z * FOLLOW_DIST - f.x * 0.8);
    a.yaw = p.yaw;
    this.actor = a;
    this.item = eq.index;
    await a.load();
    if (this.actor !== a || this.game.world !== world || this.player !== p || p.disposed || p.dead) {
      if(this.actor===a){this.actor=null;this.item=null;}
      a.dispose(); return false;
    }
    a.appear();a.play('idle', { loop: true });
    this.sys.setMenuChecked('btn_petsummon', true);
    this.game.events?.emit('pet', { on: true, item: eq.index });
    this.sys.onStatsChanged();
    return true;
  }

  async unsummon({ instant = false } = {}) {
    if (!this.actor || this.busy) return false;
    if (!instant) {
      this.busy = true;
      const ok = await this.sys.castDelay(this.sys.text('petUnsummoning'), this.sys.data.sys.petUnsummonMs);
      this.busy = false;
      if (!ok) return false;
    }
    this.despawn();
    return true;
  }

  despawn({effects=true}={}) {
    const a = this.actor, item = this.item;
    this.actor = null;
    this.item = null;
    this._target = null;
    try { if(effects)a?.depart();a?.dispose(); } catch { /* ignore */ }
    this.sys.setMenuChecked('btn_petsummon', false);
    if (a) { this.game.events?.emit('pet', { on: false, item }); this.sys.onStatsChanged(); }
  }

  toggle() { return this.actor ? this.unsummon() : this.summon(); }

  // ------------------------------------------------------------------ per frame
  update(dt) {
    const a = this.actor, p = this.player;
    if (!a) return;
    const eq = this.equipped();
    if (!eq || eq.index !== this.item || !p || p.disposed) { this.despawn(); return; }
    if (a.disposed) { this.actor = null; return; }
    const s = this.state(eq);
    // reappear next to the master after a teleport / map change / when left far behind
    const far = Math.hypot(a.x - p.x, a.z - p.z);
    if (far > TELEPORT_DIST || (a.group.parent !== this.game.worldRoot)) {
      if (a.group.parent !== this.game.worldRoot) this.game.worldRoot.add(a.group);
      const f = p.facing();
      a.setPosition(p.x - f.x * FOLLOW_DIST, p.z - f.z * FOLLOW_DIST);
      this._target = null;
    }
    // auto pickup
    this._repick -= dt;
    if (s?.settings?.auto && this._repick <= 0 && !this._target) { this._repick = 0.4; this._target = this._findDrop(s.settings); }
    const drops = this.game.loot?.drops || [];
    if (this._target && !drops.includes(this._target)) this._target = null;
    let gx, gz, speedMul = 1;
    if (this._target) {
      gx = this._target.x; gz = this._target.z; speedMul = 1.25;
      if (Math.hypot(gx - a.x, gz - a.z) <= PICK_REACH) { this._collect(this._target, s); this._target = null; }
    } else {
      // follow: a spot behind the master, on his right
      const f = p.facing();
      gx = p.x - f.x * FOLLOW_DIST - f.z * 0.9;
      gz = p.z - f.z * FOLLOW_DIST + f.x * 0.9;
    }
    const d = Math.hypot(gx - a.x, gz - a.z);
    const masterSpeed = p.moveVelocity || 0;
    const walk = Number(this.data.pet(this.item)?.cr?.walk ?? this.data.pet(this.item)?.walk ?? 6) || 6;
    if (d > 0.35) {
      // pets run to keep up (never slower than the master), slow down into a walk when close
      const speed = Math.max(Math.min(walk, 6) * (d > 3 ? 1 : 0.5), masterSpeed * (d > 3 ? 1.15 : 0.95)) * speedMul;
      const step = Math.min(d, speed * dt);
      const nx = a.x + ((gx - a.x) / d) * step, nz = a.z + ((gz - a.z) / d) * step;
      a.faceTowards(gx, gz);
      a.setPosition(nx, nz);
      const st = speed > 2.2 ? 'run' : 'walk';
      if (a.state !== st) a.play(st, { loop: true, moveSpeed: speed });
    } else if (a.state !== 'idle') {
      a.faceTowards(p.x, p.z);
      a.play('idle', { loop: true });
    }
    a.update(dt);
    // pet blessing (petbless.csv): legacy pets give a blessing item every BlessTime ms while summoned
    if (s && s.blessLeft > 0) this._bless(dt, s);
  }

  /** Nearest drop around the master that the pet settings allow. */
  _findDrop(set) {
    const p = this.player, drops = this.game.loot?.drops || [];
    let best = null, bd = PICK_RADIUS;
    for (const dr of drops) {
      const d = Math.hypot(dr.x - p.x, dr.z - p.z);
      if (d > bd || !this.allows(dr, set)) continue;
      bd = d; best = dr;
    }
    return best;
  }

  /** Does a ground drop pass the pet pickup settings? (dil always; quest items never) */
  allows(drop, set) {
    const e = drop.entry || drop.inst || drop;
    if (e.kind === 'dil' || e.kind === 'DIL' || e.amount != null && !e.itemIndex && !e.index) return true;
    const idx = Number(e.itemIndex ?? e.index ?? 0);
    const def = this.game.items?.def?.(idx) || null;
    const type = Number(def?.type ?? e.type ?? -1), code = Number(def?.code ?? e.code ?? -1);
    const cat = this.game.items?.category?.(idx) || def?.category || null;
    if (cat === 'quest' || !canDiscardDef(def || { type, code })) return false;
    if (this.sys.data.ui?.petTables?.pickup?.length && this.sys.data.ui.petTables.pickup.some(r => r.item === idx)) return true;
    const grade = String(e.inst?.grade || e.grade || drop.grade || 'normal').toLowerCase();
    if (type === 2) return !!set.accessory;                                     // rings, necklaces, earrings
    if (type === 4 || type === 5) {                                             // wearable equipment by grade
      if (grade.startsWith('legend')) return !!set.legend;
      if (grade.startsWith('divine')) return !!set.divine;
      if (grade.startsWith('noble')) return !!set.noble;
      if (grade.startsWith('magic')) return !!set.magic;
      return !!set.normal;
    }
    if (type === 1) return !!set.socket;                                        // socket stones
    if (cat === 'upgradeMaterial' || cat === 'material' || (type === 0 && (code === 7 || code === 8))) return !!set.enhance;
    return !!set.etc;                                                           // potions, scrolls, misc
  }

  /** The pet collects a drop: dil to the master, items into the pet inventory. */
  _collect(drop, s) {
    const g = this.game, loot = g.loot;
    const e = drop.entry || drop.inst || {};
    const isDil = e.kind === 'dil' || e.kind === 'DIL' || (e.amount != null && !e.itemIndex && !e.index);
    if (isDil) {
      if (loot?.pickup?.(drop)) return true;
      return false;
    }
    const idx = Number(e.itemIndex ?? e.index ?? 0);
    if (!idx) return false;
    const inst = e.uid ? { ...e } : { index: idx, count: Number(e.count) || 1, grade: e.grade || 'normal', ...(e.inst || {}) };
    if (!this.addToInventory(s, inst)) { this.sys.say('petInvFull', 'You don\'t have enough Pet Inventory.'); this._repick = 5; return false; }
    if (typeof loot?._removeDrop === 'function') loot._removeDrop(drop);
    else if (Array.isArray(loot?.drops)) { const i = loot.drops.indexOf(drop); if (i >= 0) loot.drops.splice(i, 1); drop.object?.removeFromParent?.(); }
    g.events?.emit('loot', { name: e.name || this.game.items?.name?.(idx) || this.data.name(idx), count: inst.count, kind: 'item', itemIndex: idx, grade: inst.grade, pet: true });
    g.events?.emit('petinventory', { reason: 'pickup' });
    return true;
  }

  /** Footprint (cells) of an item in the pet inventory: the item's inventory size (items.json w x h). */
  size(inst) {
    const d = this.game.items?.def?.(Number(inst.itemIndex ?? inst.index));
    return [Math.max(1, Number(d?.w) || 1), Math.max(1, Number(d?.h) || 1)];
  }
  /** First free top-left cell for a w x h footprint in the pet inventory (PET_INV_W x PET_INV_H), or null. */
  freeSpot(s, w, h, ignore = null) {
    const inv = s.inv || [];
    const busy = (x, y) => inv.some(it => it !== ignore && x < it.x + it.w && x + w > it.x && y < it.y + it.h && y + h > it.y);
    for (let y = 0; y + h <= PET_INV_H; y++) for (let x = 0; x + w <= PET_INV_W; x++) if (!busy(x, y)) return { x, y };
    return null;
  }
  /** Put an item into the pet inventory (stacks merge; w x h footprints). Returns true when it all fit. */
  addToInventory(s, inst, at = null) {
    const inv = (s.inv ||= []);
    const index = Number(inst.itemIndex ?? inst.index);
    const def = this.game.items?.def?.(index);
    const max = Number(def?.stack ?? 0);
    inst = { ...inst, itemIndex: index, count: Number(inst.count) || 1 };
    delete inst.index;
    if (max > 1 && !at) {
      for (const x of inv) {
        if (x.itemIndex !== index || (x.grade || 'normal') !== (inst.grade || 'normal') || x.count >= max) continue;
        const n = Math.min(max - x.count, inst.count);
        x.count += n; inst.count -= n;
        if (inst.count <= 0) return true;
      }
    }
    const [w, h] = this.size(inst);
    const spot = at || this.freeSpot(s, w, h);
    if (!spot) return false;
    inv.push({ ...inst, x: spot.x, y: spot.y, w, h });
    return true;
  }

  _bless(dt, s) {
    const def = this.data.pet(this.item);
    const period = Number(def?.blessTime ?? def?.cr?.raw?.BlessTime ?? 0) / 1000;
    if (!(period > 0)) return;
    s.blessLeft = (s.blessLeft > period ? period : s.blessLeft) - dt;
    if (s.blessLeft > 0) return;
    s.blessLeft = period;
    const t = (this.sys.data.ui?.petTables?.bless || []).find(r => r.index === Number(def?.bless ?? def?.cr?.bless ?? 0));
    if (!t?.items?.length) return;
    let x = Math.random() * (t.dice || 1000000);
    for (const [item, w] of t.items) {
      x -= w;
      if (x <= 0) {
        const ok = this.game.items?.add ? this.game.items.add(item, 1, { source: 'petbless' })?.ok : false;
        this.sys.log(ok ? `[message] Pet Blessing item has been distributed.` : `[message] Distributing Pet Blessing has failed due to insufficient inventory space.`);
        break;
      }
    }
  }

  dispose() { this.despawn({effects:false}); }
}

export const PET_INV_W = 10, PET_INV_H = 4;   // ui_petinfownd.txt slotbag 330 x 132 at 33 px cells

