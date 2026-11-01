// Costumes: the equipped costume (equipment slot 18) replaces the character parts its shape covers
// (items.json equipment.costypeParts: 10000 = the head/helmet part only (hats), 11111 = all five parts; a full costume
// is ONE mesh that includes the head) with the costume mesh of the character's class (cos_shape.csv). The armour
// underneath keeps its stats. The character window's "show costume" toggle hides it again (game.settings.showCostume,
// shared with the items system). docs/MOUNTS.md.
//
// The items system's equipment view (save.equipment) already swaps the covered parts to the costume asset. This module
// (an instance-level, chained wrapper of Player.partDefs) makes the result exact and adds what the view does not do:
//   * a full costume is drawn ONCE (the view puts the same one-piece mesh into all five part slots),
//   * the appearance chosen in the costume shape change / transcendence windows (inst.appearance) replaces the look,
//   * inside a DK Square / Draco battle the squad's projected team costume replaces the worn one (battle-look.js),
//   * without the items system (quick play / GM test item) it applies the costume itself.
import { EQUIP_SLOT } from './data.js';
import { equippedItem } from './riding.js';

export class CostumeLook {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.data = sys.data;
    this._sig = '';
    this._player = null;
    this._refreshing = false;
  }

  get player() { return this.game.player; }
  get shown() { return this.game.settings?.showCostume !== false; }
  set shown(v) {
    v = !!v;
    if (typeof this.game.setSettings === 'function') this.game.setSettings({ showCostume: v });
    else if (this.game.settings) this.game.settings.showCostume = v;
    this.game.events?.emit('settings', { showCostume: v });
    this.game.items?.changed?.('costume');                   // the items system rebuilds its equipment view
    this.game.events?.emit('costume', { shown: v });
  }

  /** The costume that is worn and shown (or null): {item, parts, asset, appearance}. */
  active() {
    if (!this.shown) return null;
    const team = this.sys.battleLook?.()?.costume || null;
    const e = team ? null : equippedItem(this.game, EQUIP_SLOT.costume, 'costume');
    const idx = team ?? e?.index ?? this.sys.testCostume ?? null;
    if (idx == null) return null;
    const ci = Number(this.player?.classIndex ?? this.game.save?.classIndex ?? 0);
    const look = this.data.costume(idx, ci);
    if (!look) return null;
    const app = Number(e?.inst?.appearance) || null;
    const alook = app ? this.data.costume(app, ci) : null;
    return { item: idx, parts: look.parts, asset: (alook || look).asset, appearance: alook ? app : null };
  }

  ensureHooks(p) {
    if (!p || p.__mountsCostumeHook) return;
    p.__mountsCostumeHook = true;
    const self = this;
    const partDefs = p.partDefs;
    p.partDefs = function () {
      const list = partDefs.call(this);
      if (this !== self.player) return list;
      return self.apply(this, list);
    };
  }

  /** Remove the covered parts from a partDefs() list and add the costume mesh once. */
  apply(p, list) {
    const c = this.active();
    if (!c) return list;
    const eq = this.game.save?.equipment || {};
    const covered = new Set();
    for (const part of p.classDef?.parts || []) {
      if (!c.parts.includes(part.slot)) continue;
      const e = eq[part.slot];
      covered.add(String((e && e.mesh) || part.mesh || '').toLowerCase());
    }
    const out = list.filter(d => !covered.has(String(d.meshKey || '').toLowerCase()));
    out.push({ meshKey: c.asset.mesh, tpackKey: c.asset.tpack || null, textures: c.asset.textures || null });
    return out;
  }

  update() {
    const p = this.player;
    if (!p) return;
    this.ensureHooks(p);
    const c = this.active();
    const sig = c ? `${c.item}|${c.appearance || ''}` : '';
    // the player was built before this hook existed: its first look had no costume ('' applied)
    if (this._player !== p) { this._player = p; this._sig = ''; }
    if (sig === this._sig || this._refreshing || !p.loaded) return;
    const prev = this._sig;
    this._sig = sig;
    // the items system rebuilds the body itself when the costume is (un)equipped or toggled; only appearance
    // changes (and the no-items-system case) need a rebuild from here
    const itemsLook = !!this.game.items?.look?.apply;
    const sameItem = prev.split('|')[0] === sig.split('|')[0];
    if (itemsLook && !sameItem && prev !== '' && sig !== '') return;
    this._refreshing = true;
    Promise.resolve(p.refreshAppearance?.()).catch(err => console.warn('[mounts] costume refresh', err))
      .finally(() => { this._refreshing = false; this.game.events?.emit('appearance', { reason: 'costume' }); });
  }
}
