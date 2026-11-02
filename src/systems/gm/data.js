// GM data: the command registry (gamedata/gmcommands.json, docs/formats/gmcommands.md) and the dropdown lists it
// names (gmcommands_lists.json 3.5 MB, gmcommands_items.json 9.8 MB, gmcommands_monsters.json 1.7 MB), loaded
// lazily on first use and normalised to row objects:
//   { id, name, sub, search (lower-case haystack), raw (the record as an object), row (the source row) }
// A list argument accepts an id or a name: find(listId, token) -> exact id, exact name, unique prefix, substring.
import { fetchJSON } from '../../engine/assets.js';
import { LEGACY_MAPS, allSynthesisedMaps } from '../../world/legacy-maps.js';
import { landingOverride } from '../../world/map-landing.js';

const REG = '/gamedata/gmcommands.json';
const FILE_URL = f => `/${String(f).replace(/^\/+/, '')}`;

const num = v => { const x = Number(v); return Number.isFinite(x) ? x : 0; };
const base = p => String(p || '').split('/').pop();

/** Synthesised maps (world/legacy-maps.js LEGACY_MAPS + ABSENT_MAPLIST_MAPS) are GM teleport destinations even when maplist omitted them. */
export function withLegacyMaps(rows) {
  if (!Array.isArray(rows) || !rows.length || Array.isArray(rows[0])) return rows;
  const synth = allSynthesisedMaps();
  const out = rows.map(r => synth[r.index] && !r.file ? { ...r, name: synth[r.index].Name, file: `map/${synth[r.index].file}.map`, serverOnly: undefined, legacy: true } : r);
  for (const [k, L] of Object.entries(synth)) if (!out.some(r => r.index === Number(k))) out.push({ index: Number(k), name: L.Name, file: `map/${L.file}.map`, legacy: true });
  for (let i = 0; i < out.length; i++) { const o = landingOverride(out[i].index); if (o) out[i] = { ...out[i], landing: o.landing, landingFrom: o.landingFrom }; }
  return out.sort((a, b) => a.index - b.index);
}

/** Describe one list row: [id, name, sub]. */
const DESCRIBE = {
  monsters: r => [r.index, r.name || `Monster ${r.index}`, `Lv ${r.level} · HP ${num(r.hp).toLocaleString('en-US')}${r.rank ? ` · rank ${r.rank}` : ''}${r.role && r.role !== 'creature' ? ` · ${r.role}` : ''}`],
  items: r => [r.index, r.name || `Item ${r.index}`, `${r.table || ''} · Lv ${r.reqLv} · rank ${r.rank} · ${r.type}/${r.code}`],
  itemOptions: r => [r.index, `${r.desc || r.type} (${r.min}~${r.max})`, `${r.type} · ${r.table} · Lv ${r.level}`],
  sockets: r => [r.index, r.itemName || `Stone ${r.index}`, r.desc || ''],
  maps: r => [r.index, r.name || base(r.file) || `Map ${r.index}`, `Lv ${r.level?.[0] ?? '?'}-${r.level?.[1] ?? '?'}${r.dungeon ? ' · dungeon' : ''}${r.pvp ? '' : ''} · ${base(r.file)}`],
  locations: r => [r.index, r.name || `Location ${r.index}`, `map ${r.map} (${r.x}, ${r.y})`],
  dungeons: r => [r.index, r.name || `Dungeon ${r.index}`, `${r.keeper || ''} · maps ${(r.maps || []).join(',')} · ${r.expireMin || 0} min`],
  npcs: r => [r.index, r.name || `NPC ${r.index}`, `${(r.roles || []).join(', ') || 'npc'}${r.maps?.length ? ` · maps ${r.maps.slice(0, 6).join(',')}` : ''}`],
  skills: r => [r.index, r.name || `Skill ${r.index}`, `class ${r.class} · max ${r.maxLevel}${r.weapon ? ` · ${r.weapon}` : ''}`],
  quests: r => [r.index, r.title || `Quest ${r.index}`, `Lv ${r.level ?? '?'} · type ${r.type ?? '?'}`],
  effects: r => [r.key, r.name || r.key, `${r.key} · ${(r.scenes || []).map(s => `${s[0]}:${s[1]}`).slice(0, 4).join(' ')}`],
  statuses: r => [r.index, r.desc || `Status ${r.index}`, `group ${r.group} · ${(r.options || []).slice(0, 3).map(o => `${o[0]} ${o[1]}`).join(', ')}`],
  classes: r => [r.index, r.name, r.code],
  emotes: r => [String(r.slash?.[0] || `motion${r.motion}`).replace(/^\//, ''), r.name, `motion ${r.motion} · ${(r.slash || []).join(' ')}`],
  chatTypes: r => [r.name, r.name, r.prefix ? `prefix ${r.prefix}` : (r.shortcutsEn || []).join(' ')],
  callGroups: (r, i) => [i, `${base(r.file).replace(/\.csv$/i, '')} #${r.callIndex}`, `maps ${(r.maps || []).join(',')} · ${(r.monsters || []).length} kinds · ${r.monsterCount} monsters`],
  contents: r => [r.name, r.name, `${(r.maps || []).join(', ')} · ${(r.times || []).join(' ')}`],
  skies: r => [r.index, r.desc, base(r.sky)],
  gmBuffs: r => [r.menu, r.label, r.statusName || ''],
  gmSupply: r => [r.menu, r.label, `${r.itemName || ''} x${r.count}`],
  oxQuestions: r => [r.index, r.question, `answer ${r.answer}`],
  systemVariables: r => [r.index, r.desc || r.descKr, `= ${r.value}`],
  formula: r => [r.key, r.key, `= ${r.value}`],
  mapToolCommands: r => [r.name, r.name, r.usage],
};

export class GMData {
  constructor({ readJSON = fetchJSON } = {}) {
    this.readJSON = readJSON;
    this.reg = null;
    this._lists = new Map();     // listId -> Promise<rows>
    this._files = new Map();     // url -> Promise<json>
    this.byId = new Map();
    this.byAlias = new Map();    // '/call' -> cmd, 'call' (gm sub word) -> cmd
  }

  async load() {
    if (this.reg) return this;
    this.reg = await this.readJSON(REG);
    for (const c of this.reg.commands) {
      this.byId.set(c.id, c);
      this.byAlias.set(c.id.toLowerCase(), c);
      const m = /^\/gm\s+(\S+)/.exec(c.syntax || '');
      if (m) this.byAlias.set(m[1].toLowerCase(), c);
      for (const a of c.aliases || []) {
        const s = String(a).trim().toLowerCase();
        if (s.startsWith('/gm ')) this.byAlias.set(s.slice(4).trim(), c);
        else this.byAlias.set(s, c);
      }
    }
    return this;
  }

  get commands() { return this.reg?.commands || []; }
  command(idOrAlias) { return this.byId.get(idOrAlias) || this.byAlias.get(String(idOrAlias || '').toLowerCase()) || null; }
  /** Bare chat aliases (`/call`, `/item`, `/move` ...) -> command. */
  bareAlias(word) { const c = this.byAlias.get(String(word || '').toLowerCase()); return c && String(word).startsWith('/') ? c : null; }

  file(f) {
    const url = FILE_URL(f);
    if (!this._files.has(url)) this._files.set(url, this.readJSON(url));
    return this._files.get(url);
  }
  /** Raw JSON of the monsters file (itemSets / mapDrops / classDrops for the drop viewer). */
  monstersFile() { return this.file('gamedata/gmcommands_monsters.json'); }
  itemsFile() { return this.file('gamedata/gmcommands_items.json'); }

  /** Is a list already loaded (sync)? */
  loaded(id) { return this._lists.has(id) && this._lists.get(id)._done; }
  /** Rows of a list (normalised). */
  list(id) {
    if (this._lists.has(id)) return this._lists.get(id);
    const spec = this.reg?.lists?.[id];
    const p = (async () => {
      if (!spec) return [];
      const j = spec.file.endsWith('gmcommands.json') ? this.reg : await this.file(spec.file);
      let rows = j;
      for (const k of String(spec.path).split('.')) rows = rows?.[k];
      if (!Array.isArray(rows)) rows = rows && typeof rows === 'object' ? Object.values(rows) : [];
      if (id === 'maps') rows = withLegacyMaps(rows);
      let fields = null;
      if (Array.isArray(spec.fields)) fields = spec.fields;
      else if (typeof spec.fields === 'string') fields = j[spec.fields];
      if (Array.isArray(fields)) fields = fields.map(f => String(f).split(/[\s(]/)[0].replace(/\?$/, ''));
      const desc = DESCRIBE[id] || (r => [r.index ?? r.id ?? r.name, r.name ?? r.desc ?? String(r.index), '']);
      const out = rows.map((row, i) => {
        const raw = Array.isArray(row) && fields ? Object.fromEntries(fields.map((f, k) => [f, row[k]])) : row;
        // item rows carry the index of their source table (gmcommands_items.json tables[]): use its id
        if (id === 'items' && Array.isArray(j.tables) && typeof raw.table === 'number') raw.table = j.tables[raw.table]?.id ?? raw.table;
        const [rid, name, sub] = desc(raw, i);
        return { id: rid, name: String(name ?? ''), sub: String(sub ?? ''), search: `${rid} ${name} ${sub}`.toLowerCase(), raw, row };
      });
      out.byId = new Map(out.map(o => [String(o.id), o]));
      return out;
    })();
    p._done = false;
    p.then(() => { p._done = true; }, () => {});
    this._lists.set(id, p);
    return p;
  }
  /** One row by id (async). */
  async get(listId, id) { const rows = await this.list(listId); return rows.byId.get(String(id)) || null; }

  /**
   * Resolve a token of a list argument: id, exact name, unique prefix, then substring (case-insensitive).
   * Returns { row } | { many: [rows] } | { none: true }.
   */
  async find(listId, token) {
    const rows = await this.list(listId);
    const t = String(token ?? '').trim();
    if (!t) return { none: true };
    const byId = rows.byId.get(t) || rows.byId.get(String(Number(t)));
    if (byId) return { row: byId };
    const q = t.toLowerCase();
    const exact = rows.filter(r => r.name.toLowerCase() === q);
    if (exact.length === 1) return { row: exact[0] };
    if (exact.length > 1) return { row: exact[0], many: exact };
    const pre = rows.filter(r => r.name.toLowerCase().startsWith(q));
    if (pre.length === 1) return { row: pre[0] };
    const sub = pre.length ? pre : rows.filter(r => r.name.toLowerCase().includes(q));
    if (sub.length === 1) return { row: sub[0] };
    if (sub.length > 1) return { many: sub };
    return { none: true };
  }

  /** Search rows: every word must occur in the haystack. limit = max results. */
  static search(rows, text, limit = 400, filter = null) {
    const words = String(text || '').toLowerCase().split(/\s+/).filter(Boolean);
    const out = [];
    for (const r of rows) {
      if (filter && !filter(r)) continue;
      let ok = true;
      for (const w of words) if (!r.search.includes(w)) { ok = false; break; }
      if (ok) { out.push(r); if (out.length >= limit) break; }
    }
    return out;
  }
}

export const gmData = new GMData();

/** NPCs only GM characters saw in the original (gmcommands.md 2.2): Operation Assistant, OX Start Stone, Provide Item. */
export const GM_ONLY_NPCS = new Set([5825, 5830, 3350]);
