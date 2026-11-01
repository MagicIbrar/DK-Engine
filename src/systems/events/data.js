// Event data (docs/formats/events.md): gamedata/events.json + events_text.json + events_caps.json, plus the
// dungeon-builder sections the events own (dungeons.json forbiddenShackles / forgottenShipwreck / fieldBosses /
// fieldBossSummons / bossMemento). Loaded once, lazily shared by every event module.
import { fetchJSON } from '../../engine/assets.js';

let _p = null;

/** Load (once) every table. Resolves an EventData. */
export function loadEventData() {
  if (!_p) _p = (async () => {
    const [ev, text, caps, effectui] = await Promise.all([
      fetchJSON('/gamedata/events.json'),
      fetchJSON('/gamedata/events_text.json').catch(() => null),
      fetchJSON('/gamedata/events_caps.json').catch(() => null),
      fetchJSON('/gamedata/events_effectui.json').catch(() => null),
    ]);
    const d = new EventData(ev, text, caps, null, effectui);
    d.ensureDungeons();       // 5.9 MB, shared with the dungeon system (fetchJSON cache): loaded in the background
    return d;
  })();
  return _p;
}

const num = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };

export class EventData {
  constructor(ev, text, caps, dg, effectui) {
    this.ev = ev || {};
    this.text = text || { tables: {}, mapTables: {} };
    this.caps = caps || {};
    this.dg = dg || {};
    this.effectui = effectui || null;
    this.modes = this.ev.modes || {};
    this.maps = this.ev.maps || {};
    this.solo = this.ev.soloRules || {};
    // extra maps owned by the events system that events.json does not list (Forbidden Fetters)
    this.extraMaps = new Set([260]);
    // officer npc -> { mode, map, tier }
    this.officerByNpc = new Map();
    for (const mode of ['deadFront', 'iceCastle']) {
      for (const t of this.modes[mode]?.tiers || []) {
        for (const m of t.maps || []) for (const o of m.officers || []) this.officerByNpc.set(Number(o), { mode, map: Number(m.map), tier: t.tier });
      }
    }
  }

  /** dungeons.json (stages, waves, messages of the instance events; Fetters / Shipwreck / field boss tables). */
  ensureDungeons() {
    if (!this._dgP) this._dgP = fetchJSON('/gamedata/dungeons.json').then(dg => { this.dg = dg || {}; return this.dg; }).catch(() => this.dg);
    return this._dgP;
  }

  /** Every map the events system owns. */
  ownedMaps() {
    const s = new Set(Object.keys(this.maps).map(Number));
    for (const m of this.extraMaps) s.add(m);
    return s;
  }

  map(m) { return this.maps[m] || this.maps[String(m)] || null; }
  modeOf(m) { return this.map(m)?.mode || (Number(m) === 260 ? 'forbiddenShackles' : null); }

  /** Parsed string {text, kind, effectUi, sound, effectSound, gauge} of a table (file), cate, code; or null. */
  str(file, cate, code) {
    const t = this.text.tables?.[file];
    const c = t?.[cate] ?? t?.[String(cate)];
    return c?.[code] ?? c?.[String(code)] ?? null;
  }
  /** Map-scoped string of an event map (table = mapTables[m], cate = m). */
  mapStr(m, code) {
    const file = this.text.mapTables?.[m] ?? this.text.mapTables?.[String(m)];
    return file ? this.str(file, m, code) : null;
  }
  /** Plain text of a string (or ''). */
  txt(file, cate, code, dflt = '') { const s = this.str(file, cate, code); return s?.text ?? dflt; }
  mapTxt(m, code, dflt = '') { const s = this.mapStr(m, code); return s?.text ?? dflt; }

  npc(id) { return this.ev.npcs?.[id] || this.ev.npcs?.[String(id)] || null; }
  brick(id) { return this.ev.bricks?.[id] || this.ev.bricks?.[String(id)] || null; }
  item(id) { return this.ev.items?.[id] || this.ev.items?.[String(id)] || null; }
  itemName(id) { const it = this.item(id); return it?.name || it?.nameEn || `Item ${id}`; }
  monsterInfo(id) { return this.ev.monsters?.[id] || this.ev.monsters?.[String(id)] || null; }

  /** Dead Front / Ice Castle tier object and map row for a field map. */
  tierOf(mode, m) {
    for (const t of this.modes[mode]?.tiers || []) {
      const row = (t.maps || []).find(x => Number(x.map) === Number(m));
      if (row) return { tier: t, row };
    }
    return null;
  }
  field(mode, m) { return this.modes[mode]?.fields?.[m] || this.modes[mode]?.fields?.[String(m)] || null; }
  result(mode, m) { return this.modes[mode]?.result?.[m] || this.modes[mode]?.result?.[String(m)] || null; }

  /** A partywar field point with the copy-paste quirk fixed (a point naming another field map -> this field). */
  fieldPoint(mode, m, p) {
    if (!p) return null;
    let map = num(p.map, m);
    const fields = this.modes[mode]?.fields || {};
    // respawn points that name another FIELD of the same mode are the copy-paste quirk: use this field
    if (map !== Number(m) && fields[map] && !(this.modes[mode]?.lobbies || []).includes(map)) map = Number(m);
    return { map, x: num(p.x) + 0.5, z: num(p.y) + 0.5 };
  }

  levelCapTable(m) {
    const key = this.map(m)?.files?.levelCap;
    return key ? this.caps.levelCaps?.[key] || null : null;
  }
  abilityCapTable(m) {
    const key = this.map(m)?.files?.abilityCap;
    return key ? this.caps.abilityCaps?.[key] || null : null;
  }
}

export { num };
