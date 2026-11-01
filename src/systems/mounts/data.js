// Data access for the mounts system (mounts, pets, wings, costumes): gamedata/mounts.json (core, loaded at install)
// and gamedata/mounts-ui.json (window tables, English names and inventory models of the items these windows show;
// loaded on first use). Built by tools/build-mounts.mjs from the item builder's outputs (docs/formats/items.md) and
// the client tables share/vehicle, share/creature/pet, script/ridingheightcorrection, share/action/action/{vehicle,
// rider,wingrider,pet}. See docs/MOUNTS.md.
import { fetchJSON } from '../../engine/assets.js';
import { wingDesignForItem, wingAssetKey } from '../../content/wings-catalog.js';

export const EQUIP_SLOT = { wing: 7, costume: 18, pet: 19, vehicle: 20, reserveCostume: 114 };
/** Action ids (items-actions.json actionIds) used here. */
export const ACT = { STAND: 1, MOVE: 2, DEFEAT: 7, BLOCKING: 12, BLOCKED: 13, GUARDING: 14, SM_STAND: 26, SM_MOVE: 28 };
/** pcclass order -> column of the ridingheightcorrection tables (13 columns; Alokes / Trie Muse fall back). */
const HEIGHT_COLUMN = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 6, 4];
/** script/string NORMAL cate 2005 (StringTable_Vehicle.txt) and PET cate 330 (stringtable_petui.txt) fallbacks. */
export const TEXT = {
  noMount: 'You do not currently have a mount.',
  notAllowed: 'Action not permitted while mounted.',
  noArea: 'You cannot use a mount in this area.',
  summoning: 'Summoning Transport System',
  deactivating: 'Deactivating Transport System',
  already: 'You are already mounted.',
  moving: 'You cannot get mount while moving.',
  noSkill: 'You cannot use skills while mounted.',
  fishing: 'You cannot use your mount while fishing.',
  busy: 'You may not summon or unsummon a\nmount while doing other activities.',
  transform: 'You cannot summon any transportation during\na transformation.',
  ground: 'Ground mounts cannot be used here.',
  skillBusy: 'You cannot summon your mount while using\na skill.',
  canceled: 'User has canceled it.',
  noTeleport: 'You cannot use teleportation while riding a creature.',
  petSummoning: 'Waiting for the pet to be summoned',
  petUnsummoning: 'Waiting for pet to be unsummoned',
  petSleeping: '[message] You cannot summon a pet that is sleeping.',
  petMap: 'You cannot summon a pet on this map.',
  petNone: 'Pet items are not installed.',
  petBusy: 'You cannot summon or unsummon while doing\nother activities.',
  petCanceled: 'Pet Summoning cancelled',
  petExpired: 'Expired pet can’t be summoned.',
};
/** String refs of TEXT entries (resolved through the client's string tables when loaded). */
export const TEXT_REF = {
  noMount: ['NORMAL', 2005, 1], notAllowed: ['NORMAL', 2005, 4], noArea: ['NORMAL', 2005, 12], summoning: ['NORMAL', 2005, 7],
  deactivating: ['NORMAL', 2005, 8], already: ['NORMAL', 2005, 13], moving: ['NORMAL', 2005, 22], noSkill: ['NORMAL', 2005, 23],
  fishing: ['NORMAL', 2005, 24], busy: ['NORMAL', 2005, 26], transform: ['NORMAL', 2005, 27], ground: ['NORMAL', 2005, 28],
  skillBusy: ['NORMAL', 2005, 36], canceled: ['NORMAL', 2005, 37],
  petSummoning: ['PET', 330, 55], petUnsummoning: ['PET', 330, 56], petSleeping: ['PET', 330, 57], petMap: ['PET', 330, 60],
  petNone: ['PET', 330, 61], petBusy: ['PET', 330, 65], petCanceled: ['PET', 330, 160], petExpired: ['PET', 330, 153],
};

export class MountsData {
  constructor() {
    this.core = null;
    this.ui = null;
    this._ui = null;
  }

  /** Load the core table (mounts.json). */
  async load(url = '/gamedata/mounts.json') {
    this.core = await fetchJSON(url);
    return this;
  }

  /** Load the window tables (mounts-ui.json), once. */
  loadUI(url = '/gamedata/mounts-ui.json') {
    if (!this._ui) this._ui = fetchJSON(url).then(j => (this.ui = j)).catch(err => { console.warn('[mounts] mounts-ui.json', err); this.ui = { names: {}, shapes: {}, itemShape: {} }; return this.ui; });
    return this._ui;
  }

  get sys() { return this.core?.sys || { petSummonMs: 3000, petUnsummonMs: 1000, vehicleSummonMs: 3000, vehicleUnsummonMs: 1000 }; }
  anim(id) { return this.core?.anims?.[id] || null; }

  // ------------------------------------------------------------------ vehicles
  vehicle(item) { return this.core?.vehicles?.[item] || null; }
  isVehicle(item) { return !!this.vehicle(item); }
  /** {mesh, tpack, textures} of a mount for a class (vehicle_shape.csv column of the class, or the shared mesh). */
  vehicleLook(item, classIndex) {
    const v = this.vehicle(item);
    if (!v) return null;
    const id = v.byClass ? (v.byClass[classIndex] ?? v.byClass[0]) : v.all;
    return id != null ? this.core.vlooks[id] || null : null;
  }
  vehicleTable(item) { const v = this.vehicle(item); return v ? this.core.vehicleActions?.[v.act] || null : null; }
  riderTable(item, classIndex) {
    const v = this.vehicle(item);
    const code = this.core?.riderCodes?.[classIndex];
    if (!v || !code) return null;
    return this.core.riderActions?.[`${code}${v.fs}`] || this.core.riderActions?.[`${code}0`] || null;
  }
  /** Mount speed bonus %: SPEED_MOVE_MUL (option 43) of the mount's fixed (riding) options. */
  vehicleSpeed(item) {
    const v = this.vehicle(item);
    let s = 0;
    for (const [t, val] of v?.o || []) if (t === 43) s += Number(val) || 0;
    return s;
  }
  /** Summon / dismiss casting times (ms): the mount's vehicle.csv row, else share/system_variable.csv 15/16. */
  vehicleDelays(item) {
    const c = this.vehicle(item)?.csv;
    return { start: c?.sd > 0 ? c.sd : this.sys.vehicleSummonMs, end: c?.ed > 0 ? c.ed : this.sys.vehicleUnsummonMs };
  }
  /** Mount mesh base name ('grani', 'sylphid2' ...), the key of the riding height tables. */
  vehicleMeshName(item, classIndex = 0) {
    const m = this.vehicleLook(item, classIndex)?.mesh;
    return m ? m.split('/').pop().replace(/\.mesh$/i, '') : null;
  }
  /** Absolute height of the rider's emblem / name tag above the ground (script/ridingheightcorrection/emblemheight.csv). */
  emblemHeight(item, classIndex) {
    const t = this.core?.ridingHeight?.emblem?.byMesh?.[this.vehicleMeshName(item, classIndex)];
    const v = t ? t[HEIGHT_COLUMN[classIndex] ?? 0] : null;
    return Number.isFinite(v) ? v : null;
  }
  /** Extra chat-bubble height while riding (charbubbleheight.csv). */
  bubbleHeight(item, classIndex) {
    const t = this.core?.ridingHeight?.bubble?.byMesh?.[this.vehicleMeshName(item, classIndex)];
    const v = t ? t[HEIGHT_COLUMN[classIndex] ?? 0] : null;
    return Number.isFinite(v) ? v : null;
  }
  vehicleOptions() { return this.core?.vehicleOptions || []; }

  // ------------------------------------------------------------------ action rows
  /**
   * Row of an action table: [style, action, index, anim, timeLength] matched on (style, action, index), falling back
   * to style 0, then any style, then index 0.
   * @returns {{anim:string, timeLength:number, style:number}|null}
   */
  row(table, action, index = 0, style = 0) {
    const rows = table?.rows;
    if (!rows?.length) return null;
    const hit = rows.find(r => r[1] === action && r[2] === index && r[0] === style)
      || rows.find(r => r[1] === action && r[2] === index && r[0] === 0)
      || rows.find(r => r[1] === action && r[2] === index)
      || rows.find(r => r[1] === action && r[2] === 0 && r[0] === style)
      || rows.find(r => r[1] === action && r[2] === 0)
      || rows.find(r => r[1] === action);
    if (!hit) return null;
    const anim = this.anim(hit[3]);
    return anim ? { anim, timeLength: hit[4] > 0 ? hit[4] : null, style: hit[0], action: hit[1], index: hit[2], effect: hit.length > 5 ? Number(hit[5]) || 0 : null } : null;
  }

  // ------------------------------------------------------------------ wings / costumes
  wing(item) {
    const design = wingDesignForItem(item);
    if (design) return { asset: { mesh: wingAssetKey(design.id) }, table: null, action: null, design };
    const w = this.core?.wings?.[item];
    if (!w) return null;
    const asset = this.core.assets[w[0]];
    const table = w[1] != null ? this.core.wingActions?.[w[1]] || null : null;
    return asset ? { asset, table, action: w[1] ?? null } : null;
  }
  costume(item, classIndex) {
    const c = this.core?.costumes?.[item];
    if (!c) return null;
    const id = c.c ? (c.c[classIndex] ?? null) : c.a;
    const asset = id != null ? this.core.assets[id] : null;
    return asset ? { parts: c.p || [], asset } : null;
  }

  // ------------------------------------------------------------------ pets
  pet(item) {
    const p = this.core?.pets?.[item];
    if (p) return { kind: 'pet', item: Number(item), ...p, table: this.core.petActions?.[p.act] || null };
    const l = this.core?.legacyPets?.[item];
    return l ? { kind: 'legacy', item: Number(item), ...l } : null;
  }
  isPet(item) { return !!(this.core?.pets?.[item] || this.core?.legacyPets?.[item]); }

  // ------------------------------------------------------------------ names / icons (mounts-ui.json)
  name(item) {
    return wingDesignForItem(item)?.name || this.ui?.names?.[item] || this.core?.vehicles?.[item]?.n || this.core?.pets?.[item]?.n || this.core?.legacyPets?.[item]?.n || '';
  }
  invModel(item) { const s = this.ui?.itemShape?.[item]; return s != null ? this.ui.shapes[s] || null : null; }
  table(group, name) { return this.ui?.[group]?.[name] || null; }
  /** Rows of a compact window table as objects. */
  rows(group, name) {
    const t = this.table(group, name);
    if (!t) return [];
    if (t._obj) return t._obj;
    t._obj = t.rows.map(r => Object.fromEntries(t.cols.map((c, i) => [c, r[i]])));
    return t._obj;
  }
  optionLabel(type) { return this.core?.optionLabels?.[type] || null; }
}

/** Format an option [type, value] as its tooltip line ("Movement Speed +28%"). */
export function optionText(data, type, value) {
  const o = data.optionLabel(type);
  if (!o) return `Option ${type} ${value}`;
  if (o.text) return String(o.text).replace(/<set=VALUE2>/g, ' ').replace(/<VALUE>/g, String(value)).replace(/<[^>]+>/g, '').trim();
  return `${o.label || o.name} ${value}`;
}
