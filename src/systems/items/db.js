// Item database of the items system: the gamedata/items*.json tables built by tools/build-items.mjs
// (docs/formats/items.md) plus gamedata/items-styles.json (tools/build-item-styles.mjs).
//
//   const db = await ItemDB.load();         // items.json (+ visual/looks/options/styles); tables lazily (db.tables())
//   db.def(810035)                          // {index, ...itemDefaults, ...items[810035]} (cached)
//   db.kindName(def) / db.rankName(def) / db.category(def) / db.shape(def) / db.look(index) / db.optionType(code)
import { fetchJSON } from '../../engine/assets.js';
import { installWingItems } from '../../content/wing-items.js';
import { normalizeOptionTypes, canonicalOptionCode, canonicalOptionName } from './option-identities.js';

const cacheDefs = new Map();

export class ItemDB {
  constructor(parts) {
    Object.assign(this, parts);
    this.options = {...this.options, optionTypes: normalizeOptionTypes(this.options?.optionTypes)};
    this.items = this.core.items;
    this.defaults = this.core.itemDefaults;
    this.enums = this.core.enums;
    this.equipment = this.core.equipment;
    this.tooltip = this.core.tooltip;
    this.descriptions = this.core.descriptions || {};
    this._tables = null;
    this._defs = cacheDefs;
    this._byName = null;
    installWingItems(this);
  }

  /** Load the tables (shared promise). */
  static load() {
    if (!ItemDB._p) {
      ItemDB._p = (async () => {
        const [core, visual, looks, options, styles] = await Promise.all([
          fetchJSON('/gamedata/items.json'),
          fetchJSON('/gamedata/items-visual.json').catch(() => null),
          fetchJSON('/gamedata/items-looks.json').catch(() => null),
          fetchJSON('/gamedata/items-options.json').catch(() => null),
          fetchJSON('/gamedata/items-styles.json').catch(() => null),
        ]);
        const db = new ItemDB({ core, visual, looks, options, styles });
        // custom items of the item builder (src/systems/itembuilder/registry.js): applied before any save is read
        try { (await import('../itembuilder/registry.js')).applyStoredCustomItems(db); } catch (err) { console.warn('[items] custom items', err); }
        return db;
      })();
    }
    return ItemDB._p;
  }

  /** items-tables.json (upgrade / socket / crest / ... tables), loaded on first use. */
  tables() {
    if (!this._tables) this._tables = fetchJSON('/gamedata/items-tables.json').then(t => { this.T = t; return t; }).catch(() => { this.T = {}; return {}; });
    return this._tables;
  }
  /** items-actions.json (wing / animated weapon / pet / vehicle action tables), loaded on first use. */
  actions() {
    if (!this._actions) this._actions = fetchJSON('/gamedata/items-actions.json').catch(() => null);
    return this._actions;
  }

  has(index) { return !!this.items[index]; }

  /** Merged item record ({index, ...defaults, ...row}) or null. */
  def(index) {
    index = Number(index);
    if (!Number.isFinite(index)) return null;
    let d = this._defs.get(index);
    if (d !== undefined) return d;
    const row = this.items[index];
    d = row ? Object.freeze({ index, ...this.defaults, ...row }) : null;
    this._defs.set(index, d);
    return d;
  }

  name(index) { return this.def(index)?.name || `Item #${index}`; }
  kind(def) { return (Number(def?.type) || 0) * 256 + (Number(def?.code) || 0); }
  kindName(def) { return this.enums.kindNames?.[this.kind(def)] || ''; }
  rankName(def) { return this.enums.rankNames?.[def?.rank] ?? ''; }
  category(def) { return this.enums.categoryByKind?.[this.kind(def)] || ''; }
  description(def) { return def?.desc ? this.descriptions[def.desc] || '' : ''; }
  shape(def) { return def?.shape ? this.visual?.shapes?.[def.shape] || null : null; }
  look(index) { return this.looks?.looks?.[index] || null; }
  asset(id) { return id == null ? null : this.looks?.assets?.[id] || null; }
  optionType(code) { return this.options?.optionTypes?.[code] || null; }
  optionName(code) { return canonicalOptionName(code, this.options?.optionTypes); }
  optionCode(name) { return canonicalOptionCode(name, this.options?.optionTypes); }
  weaponRule(def) { return def && Number(def.type) === 4 ? this.equipment.weaponRules?.[def.code] || null : null; }
  tooltipLayout(def) { return this.tooltip?.layout?.[this.kind(def)] || null; }
  str(cate, code) { const v = this.tooltip?.strings?.[cate]?.[code]; return Array.isArray(v) ? v[0] : v ?? ''; }
  classStyles(ci) { return this.equipment.classStyles?.[ci] || []; }
  styleAnims(ci, style) { return this.styles?.classes?.[ci]?.styles?.[style] || null; }
  styleCombo(ci, style) { return this.styles?.classes?.[ci]?.combos?.[style] || null; }
  /** Weapon bone row for a class and weaponType (1024 + code), falling back to class 0 / any class that lists it. */
  weaponBones(ci, weaponType) {
    const B = this.equipment.weaponBones || {};
    return B[ci]?.[weaponType] || B[0]?.[weaponType] || Object.values(B).find(r => r?.[weaponType])?.[weaponType] || null;
  }
  /** Stack size (1 = does not stack). */
  stackSize(def) { const s = Number(def?.stack) || 0; return s > 1 ? s : 1; }

  /** Items whose name matches (lower-case substring). */
  search(text, limit = 50) {
    const q = String(text || '').toLowerCase();
    const out = [];
    if (!q) return out;
    for (const k in this.items) {
      const n = this.items[k].name;
      if (n && n.toLowerCase().includes(q)) { out.push(Number(k)); if (out.length >= limit) break; }
    }
    return out;
  }
}
