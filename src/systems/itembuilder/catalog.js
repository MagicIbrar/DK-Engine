// Picker catalogues of the item builder (built lazily from the loaded items database and the data folders):
//   kinds()          every item kind (type*256+code) the data uses, labelled like the tooltip "Type:" line
//   items(q, kind)   search of every item (name / index), optionally one kind
//   models(q, f)     the equipped-model library: every unique mesh+texture set of items-looks.json (5,550), with the
//                    slots / weapon types / classes that use it, filterable by the draft's kind and class
//   invModels(q)     the inventory-model ("icon") library: every unique shapes[].inv model of items-visual.json
//   textures(q, dir) texture files of texture/item and texture/character (server /api/ls)
import { listDir } from '../../engine/assets.js';
import { isCustomIndex } from './registry.js';

const base = (k) => String(k || '').split('/').pop();
const CLASS_CODES = ['swd', 'arc', 'sor', 'sum', 'hil', 'war', 'alo', 'drg', 'sht', 'bwz', 'wsu', 'mse', 'hwa', 'mal', 'tri'];

export class Catalog {
  constructor(db) {
    this.db = db;
    this._kinds = null;
    this._models = null;
    this._inv = null;
    this._tex = new Map();
  }

  /** [{value: kind, type, code, text, count, slot}] sorted equippable first. */
  kinds() {
    if (this._kinds) return this._kinds;
    const db = this.db;
    const count = new Map();
    for (const k in db.items) {
      const it = db.items[k];
      const kind = (Number(it.type) || 0) * 256 + (Number(it.code) || 0);
      count.set(kind, (count.get(kind) || 0) + 1);
    }
    const names = db.enums.kindNames || {};
    for (const k of Object.keys(names)) if (!count.has(Number(k))) count.set(Number(k), 0);
    const T = db.enums.types || {};
    const out = [...count].map(([kind, n]) => {
      const type = Math.floor(kind / 256), code = kind % 256;
      const label = names[kind] || `${T[type] || 'type ' + type} ${code}`;
      const wr = type === 4 ? db.equipment.weaponRules?.[code] : null;
      const text = wr?.label && wr.label !== label ? `${label} (${wr.label})` : label;
      return { value: kind, type, code, text: `${text} [${type}/${code}]`, count: n };
    });
    const order = { 4: 0, 5: 1, 2: 2, 6: 3, 11: 4, 10: 5, 0: 6, 1: 7, 3: 8 };
    out.sort((a, b) => (order[a.type] ?? 9) - (order[b.type] ?? 9) || a.type - b.type || a.code - b.code);
    this._kinds = out.filter(k => k.count > 0 || names[k.value]);
    return this._kinds;
  }

  /** Items matching `q` (name substring or index), at most `limit` (capped at 500). kind = type*256+code or null. */
  items(q, kind = null, limit = 400) {
    const db = this.db;
    const s = String(q || '').trim().toLowerCase();
    const num = /^\d+$/.test(s) ? Number(s) : null;
    const out = [];
    limit = Math.max(0, Math.min(500, Math.floor(Number(limit) || 0)));
    if (!limit) return out;
    if (num != null) {
      const it = db.items[num];
      if (!it || num === 900999999 || (kind != null && (Number(it.type) || 0) * 256 + (Number(it.code) || 0) !== kind)) return out;
      return [num];
    }
    for (const k in db.items) {
      if (out.length >= limit) break;
      const it = db.items[k];
      if (isCustomIndex(k) && Number(k) === 900999999) continue;
      if (kind != null && (Number(it.type) || 0) * 256 + (Number(it.code) || 0) !== kind) continue;
      if (s && num == null && !(it.name || '').toLowerCase().includes(s)) continue;
      if (Number(k) === num) continue;
      out.push(Number(k));
    }
    return out;
  }

  /** The equipped-model library: [{id, asset, name, folder, slots:Set, wtypes:Set, classes:Set(codes), sample}]. */
  modelLib() {
    if (this._models) return this._models;
    const db = this.db;
    const A = db.looks?.assets || [];
    const lib = A.map((a, id) => a && a.mesh ? { id, asset: a, name: base(a.mesh).replace(/\.mesh$/, ''), folder: a.mesh.split('/').slice(-2, -1)[0] || '', slots: new Set(), wtypes: new Set(), sample: null } : null);
    const looks = db.looks?.looks || {};
    for (const k in looks) {
      if (isCustomIndex(k)) continue;
      const L = looks[k];
      const ids = [L.all, L.left, ...Object.values(L.byClass || {})].filter(v => v != null);
      for (const id of ids) {
        const e = lib[id];
        if (!e) continue;
        if (L.slot) e.slots.add(L.slot);
        if (L.weaponType) e.wtypes.add(L.weaponType);
        if (e.sample == null) e.sample = Number(k);
      }
    }
    for (const e of lib) if (e) { const cc = /^([a-z]{3})_/.exec(e.name)?.[1]; e.cls = CLASS_CODES.includes(cc) ? cc : null; }
    this._models = lib.filter(Boolean);
    return this._models;
  }

  /**
   * Models for the picker. f = {slot, weaponType, classIndex, all}: by default only models of the same slot (weapons:
   * the same weapon type; armour: the class's own meshes).
   */
  models(q, f = {}) {
    const s = String(q || '').trim().toLowerCase();
    const cc = f.classIndex != null ? CLASS_CODES[f.classIndex] : null;
    return this.modelLib().filter(e => {
      if (!f.all) {
        if (f.slot && !e.slots.has(f.slot)) return false;
        if (f.weaponType && (f.slot === 'weapon' || f.slot === 'offhand') && e.wtypes.size && !e.wtypes.has(f.weaponType)) return false;
        if (cc && e.cls && ['helmet', 'armor', 'pants', 'glove', 'boots'].includes(f.slot) && e.cls !== cc) return false;
      }
      if (s && !e.name.includes(s) && !e.asset.mesh.includes(s) && !(e.sample && (this.db.items[e.sample]?.name || '').toLowerCase().includes(s))) return false;
      return true;
    });
  }

  /** The inventory-model library: [{key, inv, invAnim, invSkel, invAnimTime, invTwoSide, name, sample}]. */
  invLib() {
    if (this._inv) return this._inv;
    const shapes = this.db.visual?.shapes || {};
    const seen = new Map();
    const sampleOf = new Map();
    for (const k in this.db.items) { const sh = this.db.items[k].shape; if (sh && !sampleOf.has(sh)) sampleOf.set(sh, Number(k)); }
    for (const id in shapes) {
      if (isCustomIndex(id)) continue;
      const sh = shapes[id];
      const inv = sh?.inv;
      if (!inv?.mesh) continue;
      const key = `${inv.mesh}|${JSON.stringify(inv.textures || [])}`;
      if (seen.has(key)) continue;
      seen.set(key, {
        key, inv: { mesh: inv.mesh, tpack: inv.tpack || null, textures: inv.textures || null },
        invAnim: inv.anim || sh.invAnim || null, invSkel: inv.skel || sh.invSkel || null, invAnimTime: sh.invAnimTime || null,
        invTwoSide: sh.invTwoSide !== false, name: base(inv.mesh).replace(/\.mesh$/, ''), sample: sampleOf.get(Number(id)) ?? null,
        folder: inv.mesh.split('/').slice(-2, -1)[0] || '',
      });
    }
    this._inv = [...seen.values()].sort((a, b) => a.name.localeCompare(b.name));
    return this._inv;
  }
  invModels(q) {
    const s = String(q || '').trim().toLowerCase();
    return this.invLib().filter(e => !s || e.name.includes(s) || e.inv.mesh.includes(s) || (e.sample && (this.db.items[e.sample]?.name || '').toLowerCase().includes(s)));
  }

  /** Texture files of a data folder (texture/item | texture/character), filtered by q. */
  async textures(q, dir = 'texture/item') {
    if (!this._tex.has(dir)) this._tex.set(dir, listDir(dir).then(l => (l || []).filter(e => !e.dir && /\.(dds|tga|bmp|png|jpg)$/i.test(e.name)).map(e => `${dir}/${e.name.toLowerCase()}`).sort()).catch(() => []));
    const all = await this._tex.get(dir);
    const s = String(q || '').trim().toLowerCase();
    return s ? all.filter(k => k.includes(s)) : all;
  }
}

export { CLASS_CODES };
