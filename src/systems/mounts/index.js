// Mounts system: riding (mounts / vehicles), pets, wings and costumes, with their original windows.
// docs/MOUNTS.md has the rules, data and decisions; gamedata/mounts*.json is built by tools/build-mounts.mjs.
//
// Public API: game.mounts.
import { MountsData, TEXT, TEXT_REF, EQUIP_SLOT, optionText } from './data.js';
import { Riding } from './riding.js';
import { WingVisual } from './wings.js';
import { CostumeLook } from './costume.js';
import { PetManager } from './pet.js';
import { statProviders } from '../../game/progression.js';
import { strings } from '../../ui/uiwin/strings.js';
import { registerWindows } from './windows.js';
import { itemsUiReady } from './ui-util.js';
import {optionDisplayValue} from '../items/native-option-values.js';
import { ownBattleLook, battleLookSignature } from './battle-look.js';

let SYS = null;

class MountsSystem {
  constructor(game) {
    this.game = game;
    this.data = new MountsData();
    this.riding = null;
    this.wings = null;
    this.costume = null;
    this.pet = null;
    this.testVehicle = null;     // GM / quick-play overrides when no item system is present
    this.testWing = null;
    this.testCostume = null;
    this.testPet = null;
    this._delay = null;          // active casting bar { resolve, t, ms }
    this._msgT = {};
  }

  async install() {
    const g = this.game;
    await this.data.load();
    this.riding = new Riding(this);
    this.wings = new WingVisual(this);
    this.costume = new CostumeLook(this);
    this.pet = new PetManager(this);
    // the own body inside a DK Square / Draco battle: the squad's projected costume / wings / insignia / weapon look
    // (battle-look.js) for CostumeLook, the wing and, through game.items.battleLook, the items system's equipment view
    this.battleLook = (save = g.save) => (save === g.save ? ownBattleLook(g) : null);
    const ownWing = this.wings.equipped.bind(this.wings);
    this.wings.equipped = () => { const team = this.battleLook()?.wing; return team && this.data.wing(team) ? team : ownWing(); };
    this.data.loadUI();                                     // window tables in the background
    strings.need(Object.values(TEXT_REF).map(([group, cate, code]) => ({ group, cate, code }))).catch(() => {});
    this._provider = () => this.statEntries();
    statProviders.push(this._provider);
    this._events();
    await itemsUiReady;                                      // the items system's slot machinery (ui-util.js)
    registerWindows(this);
    // Ian's weapon appearance window (npc job 110) and its run-out notices; loaded like the other items-system windows
    try { this.weaponLook = (await import('../items/ui/weapon-look.js')).installWeaponLook(g); } catch (err) { console.warn('[mounts] weapon appearance window', err); }
    this._exposeApi();
    // the items system computed the worn-item stats before game.mounts existed: recount (mount options only while riding)
    if (g.items?.ready) Promise.resolve(g.items.ready).then(() => this.onStatsChanged()).catch(() => {});
  }

  // ------------------------------------------------------------------ text / messages
  /** Client string of a TEXT key (script/string tables), else the built-in English fallback. */
  text(key) {
    const r = TEXT_REF[key];
    const v = r ? strings.get({ group: r[0], cate: r[1], code: r[2] }) : null;
    return String(v ?? TEXT[key] ?? key);
  }
  /** System message (chat log, red), rate limited per key. */
  say(key, fallback) {
    const now = this.game.time || 0;
    if (this._msgT[key] != null && now - this._msgT[key] < 1.5) return;
    this._msgT[key] = now;
    this.log(TEXT[key] || TEXT_REF[key] ? this.text(key) : (fallback || key), 'err');
  }
  log(text, kind = 'sys') {
    const plain = String(text).replace(/<[^>]+>/g, '').replace(/\s*\n\s*/g, ' ').trim();
    try { this.game.hud?.log?.(plain, kind); } catch { /* ignore */ }
  }

  /** Tooltip line of a petoption.csv option index ("Blocking Rate: 3%"). */
  optionLine(optionIndex) {
    const row = (this.data.ui?.petTables?.option || []).find(r => r.index === Number(optionIndex));
    if (!row) return '';
    const v = row.min === row.max ? row.max : `${row.min}~${row.max}`;
    return String(row.text || row.type).replace(/<set=VALUE2>/g, ' ').replace(/<VALUE>/g, String(v)).replace(/<[^>]+>/g, '').trim();
  }

  // ------------------------------------------------------------------ state checks used by the rules
  isFishing() { return !!(this.game.fishing?.active || this.game.systems?.get?.('fishing')?.isFishing?.()); }
  /**
   * Transformed so that mounting is refused (NORMAL 2005:27). Trans Up (the skills system's player.transUpStage) is
   * allowed with the class's "Boarding mastery" passive (share/vehicle/vehicleskill.csv: KNIGHT 191 K_vehicle ...:
   * "You can board during Trans Up transformation."); other transformations never.
   */
  isTransformed() {
    const p = this.game.player;
    if (!p) return false;
    if (Number(p.transUpStage) > 0) return !this.boardingMastery();
    return !!(p.transformLook || p.transformed || p.transform);
  }
  boardingMastery() {
    const sk = this.game.skills;
    if (typeof sk?.skillLevel !== 'function') return false;
    for (const idx of Object.values(this.data.core?.vehicleSkill || {})) if (sk.skillLevel(Number(idx)) > 0) return true;
    return false;
  }

  // ------------------------------------------------------------------ casting bar (vehicle_delay_wnd)
  /**
   * The original summon casting bar (game2/vehicle/ui_delaywnd.txt: pan_waittime, lbl_waittime, processbar).
   * Resolves true when it completes, false when cancelled (Esc, death, map change).
   */
  async castDelay(text, ms) {
    ms = Math.max(0, Number(ms) || 0);
    if (this._delay) this._finishDelay(false);
    if (ms <= 0) return true;
    const mgr = this.game.uiwin;
    let win = null;
    try { win = mgr ? await mgr.get('mount_delay') : null; } catch (err) { console.warn('[mounts] delay window', err); }
    return new Promise(resolve => {
      this._delay = { resolve, t: 0, ms: ms / 1000, win };
      if (win) {
        win.control('pan_waittime').show();
        win.control('lbl_waittime').setText(text);
        win.control('processbar').setGauge(0);
        mgr.openWindow(win);
      }
    });
  }
  _finishDelay(ok) {
    const d = this._delay;
    if (!d) return;
    this._delay = null;
    if (d.win?.isOpen) d.win.close(ok ? 'done' : 'cancel');
    d.resolve(ok);
  }
  _tickDelay(dt) {
    const d = this._delay;
    if (!d) return;
    const p = this.game.player;
    if (!p || p.dead) { this._finishDelay(false); return; }
    d.t += dt;
    d.win?.control('processbar').setGauge(Math.min(1, d.t / d.ms));
    if (d.t >= d.ms) this._finishDelay(true);
  }

  // ------------------------------------------------------------------ menu buttons' check sprite
  setMenuChecked(id, on) {
    const mgr = this.game.uiwin;
    for (const w of mgr?.wins?.values?.() || []) w.find?.(id)?.setChecked?.(!!on);
    try {
      const b = globalThis.document?.querySelector?.(`.dk-menu-btn[data-id="${id.replace(/^btn_/, '')}"]`);
      if (b) b.classList.toggle('on', !!on);
    } catch { /* no DOM */ }
  }

  // ------------------------------------------------------------------ stats
  /**
   * Options these systems add on top of the worn items: the summoned pet's options and skill, and the mount's
   * enchanted option (vehicle cycle window) while riding. [[optionType, value]]. The items system folds them into its
   * item stats (src/systems/items/stats.js calls game.mounts.extraOptions()); it also counts the mount's own fixed
   * options only while game.mounts.isMounted().
   */
  extraOptions() {
    const out = [];
    if (this.riding?.active) {
      const opt = this.riding.equipped()?.inst?.vehicleOpt;
      if (opt) {
        const row = this.data.vehicleOptions().find(r => r.index === opt.index);
        if (row && row.optionType != null) out.push([row.optionType, row.values[opt.level || 0] || 0]);
      }
    }
    if (this.pet?.summoned) out.push(...this.pet.activeOptions());
    return out;
  }

  /** progression statProviders entry, used only without the items system (quick play / tests). */
  statEntries() {
    if (this.game.items?.itemStats) return [];
    const labels = this.data.core?.optionLabels || {};
    const conv = list => ({ options: (list || []).map(([t, v]) => ({ code: labels[t]?.name || String(t), value: Number(v) || 0 })) });
    const out = [];
    if (this.riding?.active) { const v = this.data.vehicle(this.riding.item); if (v?.o?.length) out.push({ source: 'mount', ...conv(v.o) }); }
    const extra = this.extraOptions();
    if (extra.length) out.push({ source: 'mounts', ...conv(extra) });
    return out;
  }

  onStatsChanged() {
    try {
      if (typeof this.game.items?.changed === 'function') this.game.items.changed('equip:mounts', null, { look: false });
      else this.game.refreshPlayerStats?.(false);
    } catch (err) { console.warn('[mounts] refresh stats', err); }
    this.game.events?.emit('stats');
  }

  // ------------------------------------------------------------------ rules hooks (wrapped lazily: other systems may replace these objects)
  _wrapRules() {
    const g = this.game, self = this;
    const sk = g.skills;
    if (sk && !sk.__mountsWrapped) {
      sk.__mountsWrapped = true;
      const isItemSlot = n => Number.isInteger(n) && n >= 0 && n <= 9 && g.save?.hotbar?.[n]?.type === 'item';
      for (const name of ['use', 'useSlot', 'useSkill']) {
        const fn = sk[name];
        if (typeof fn !== 'function') continue;
        sk[name] = function (arg, ...rest) {
          if (self.riding?.active) {
            const itemUse = (name !== 'useSkill' && isItemSlot(arg)) || (arg && typeof arg === 'object' && arg.type === 'item');
            if (!itemUse) { self.say('noSkill'); return false; }
          }
          return fn.call(this, arg, ...rest);
        };
      }
    }
    const c = g.controller;
    if (c && !c.__mountsWrapped) {
      c.__mountsWrapped = true;
      const attack = c.attack;
      if (typeof attack === 'function') {
        c.attack = function (target, opts) {
          if (self.riding?.active) { self.say('notAllowed'); return false; }
          return attack.call(this, target, opts);
        };
      }
      const approach = c.approach;
      if (typeof approach === 'function') {
        c.approach = function (...a) { if (self.riding?.active) { self.say('notAllowed'); return; } return approach.apply(this, a); };
      }
    }
  }

  _events() {
    const ev = this.game.events;
    ev.on('death', ({ actor }) => {
      if (actor !== this.game.player) return;
      if (this._delay) this._finishDelay(false);
      if (this.riding.state !== 'off') { this.riding._detach(); this.game.player?.play?.('die', { loop: false }); }
      if (this.pet.summoned) this.pet.despawn();
    });
    ev.on('map', () => {
      if (this._delay) this._finishDelay(false);
      if (this.riding.active && !this.riding.mapAllows()) { this.riding._detach(); this.say('noArea'); }
      if (this.riding.active && this.riding.underwater() && !this.riding.canSwim(this.riding.item)) { this.riding._detach(); this.say('ground'); }
      const row = this.game.world?.info?.row;
      if (this.pet.summoned && row && Number(row.IsPet) === 0 && String(row.IsPet ?? '').trim() !== '') { this.pet.despawn(); this.say('petMap'); }
    });
    // equipment changes: taking off the mount / pet ends riding / the summon
    const onEquip = () => {
      if (this.riding.active && this.riding.equipped()?.index !== this.riding.item) this.riding._detach();
      if (this.pet.summoned && this.pet.equipped()?.index !== this.pet.item) this.pet.despawn();
    };
    ev.on('equip', onEquip);
    ev.on('unequip', onEquip);
    ev.on('damage', ({ target }) => { if (target === this.game.player && this._delay && !this._delayUninterruptible) this._finishDelay(false); });
  }

  // ------------------------------------------------------------------ frame
  update(dt) {
    // Finite departure effects can outlive their pet and the local player.
    this.game.nativeMountEffects?.tick(dt);
    const p = this.game.player;
    if (!p) return;
    this._wrapRules();
    this.riding.ensureHooks(p);
    this._tickDelay(dt);
    this.riding.update(dt);
    this._battleLookTick();
    this.costume.update(dt);
    this.wings.update(dt);
    this.pet.update(dt);
    this.weaponLook?.update?.(dt);
  }

  /** The projected own battle look started, changed or ended: the items system rebuilds its equipment view and the body. */
  _battleLookTick() {
    const items = this.game.items;
    if (items && items.battleLook !== this.battleLook) items.battleLook = this.battleLook;
    const sig = battleLookSignature(this.battleLook());
    if (sig === this._battleSig) return;
    const first = this._battleSig === undefined;
    this._battleSig = sig;
    if (!first || sig) items?.changed?.('equip:battlelook');
  }

  dispose() {
    this.riding?.dispose();
    this.wings?.dispose();
    this.pet?.dispose();
    this.game.nativeMountEffects?.dispose();
    const i = statProviders.indexOf(this._provider);
    if (i >= 0) statProviders.splice(i, 1);
  }

  _exposeApi() {
    const self = this;
    this.game.mounts = {
      system: this,
      get data() { return self.data; },
      isMounted: () => !!self.riding?.active,
      get state() { return self.riding?.state; },
      get vehicle() { const i = self.riding?.item ?? self.riding?.equipped()?.index; return i != null ? { index: i, ...self.data.vehicle(i) } : null; },
      mount: () => self.riding.mount(),
      dismount: (o) => self.riding.dismount(o),
      toggleMount: () => self.riding.toggle(),
      get pet() { return self.pet?.actor || null; },
      summonPet: () => self.pet.summon(),
      unsummonPet: (o) => self.pet.unsummon(o),
      togglePet: () => self.pet.toggle(),
      petState: () => self.pet.state(),
      get costumeShown() { return self.costume.shown; },
      setCostumeShown: (v) => { self.costume.shown = v; },
      /** GM / quick play: ride / wear / summon an item without the item system (null clears). */
      test: { vehicle: (i) => { self.testVehicle = i; }, wing: (i) => { self.testWing = i; }, costume: (i) => { self.testCostume = i; }, pet: (i) => { self.testPet = i; } },
      optionText: (t, v) => {
        // the items system's option table (the tooltip texts of every option type), else the mounts table
        const db=self.game.items?.db,ot = db?.optionType?.(t);
        if (ot?.text) return String(ot.text).replace(/<set=VALUE2>/g, ' ').replace(/<VALUE>/g, optionDisplayValue(t,v,db).toLocaleString('en-US')).replace(/<[^>]+>/g, '').trim();
        return optionText(self.data, t, v);
      },
      extraOptions: () => self.extraOptions(),
      EQUIP_SLOT,
    };
  }
}

// ------------------------------------------------------------------ system entry points (src/systems/index.js)
export async function install(game) {
  SYS = new MountsSystem(game);
  await SYS.install();
  return SYS;
}
export function update(dt) { SYS?.update(dt); }
export function dispose() { SYS?.dispose(); SYS = null; }
export function system() { return SYS; }
