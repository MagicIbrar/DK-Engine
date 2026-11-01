// UI-MAPITEMLIST: the "Main Reward Item List" content derived from the client's monster spawn and drop tables (pure; the window is
// src/systems/extras/mapitemlist.js). Every grouping, filter and ordering rule here is ENGINE-CHOSEN (src/config/engine-chosen-
// mapitemlist.js, docs/UI-MAPITEMLIST.md): the original list is server data the client does not carry.
//   pool(map)  = items of every drop set (gamedata/monsters.json monsters[i].drops.sets -> itemSets[s].items) of every monster the
//                map spawns (spawns[map].rows, MON_*.csv) or calls (callSpawns whose maps list the map, incl. random calls);
//                a set or an item with drop ratio 0 cannot drop and is skipped; only items the item database knows are kept.
//   region     = maplist.csv TerritoryIndex.
import { MAPITEMLIST_CONFIG } from '../../config/engine-chosen-mapitemlist.js';

const num = (v) => Number(v);
/** Monster indexes a map spawns or calls. */
export function mapMonsters(monsters, mapIndex) {
  const out = new Set(), m = num(mapIndex);
  for (const r of monsters?.spawns?.[m]?.rows || []) out.add(num(r[0]));
  for (const c of Object.values(monsters?.callSpawns || {})) {
    const maps = Array.isArray(c.maps) ? c.maps : c.map != null ? [c.map] : [];
    if (!maps.map(num).includes(m)) continue;
    for (const r of c.rows || []) out.add(num(r[1]));
    for (const rc of c.randomCalls || []) for (const x of (Array.isArray(rc) ? rc : [])) if (monsters.monsters?.[x]) out.add(num(x));
  }
  return [...out].filter((i) => monsters?.monsters?.[i]);
}
/** Item indexes the given monsters can drop. */
export function dropItems(monsters, monsterIndexes, has = () => true) {
  const out = new Set();
  for (const mi of monsterIndexes) for (const [set, ratio] of monsters.monsters?.[mi]?.drops?.sets || []) {
    if (!(num(ratio) > 0)) continue;
    for (const [item, r] of monsters.itemSets?.[set]?.items || []) if (num(r) > 0 && has(num(item))) out.add(num(item));
  }
  return out;
}
/**
 * The whole list: { all, common, regions: [{territory, name, maps: [{name, maps:[index], items}]}] } with items as
 * [{index, name, reqLv}] sorted (reqLv desc, name). db: {has(i), name(i), def(i)}; maplist: rows {Index, Name, TerritoryIndex}.
 */
export function buildMapItemList({ monsters, maplist, db, config = MAPITEMLIST_CONFIG }) {
  const has = (i) => (db?.has ? db.has(i) : true);
  const info = new Map();
  const item = (i) => { if (!info.has(i)) { const d = db?.def?.(i); info.set(i, { index: i, name: String(db?.name?.(i) ?? d?.name ?? `Item #${i}`).trim(), reqLv: num(d?.reqLv) || 0 }); } return info.get(i); };
  const sortItems = (set) => [...set].map(item).sort((a, b) => b.reqLv - a.reqLv || a.name.localeCompare(b.name) || a.index - b.index);
  const rows = (maplist || []).filter((r) => r && r.Index !== '' && Number.isFinite(num(r.Index))).map((r) => ({ index: num(r.Index), name: String(r.Name || '').trim(), territory: num(r.TerritoryIndex) || 0 }));
  const pools = new Map();
  for (const r of rows) { const p = dropItems(monsters, mapMonsters(monsters, r.index), has); if (p.size) pools.set(r.index, p); }
  // regions with drops, and in how many of them each item drops
  const territoryOf = new Map(rows.map((r) => [r.index, r.territory]));
  const itemRegions = new Map();
  for (const [m, p] of pools) for (const i of p) (itemRegions.get(i) || itemRegions.set(i, new Set()).get(i)).add(territoryOf.get(m));
  const regionsWithDrops = new Set([...pools.keys()].map((m) => territoryOf.get(m)));
  const need = Math.max(2, Math.ceil(regionsWithDrops.size * config.commonRegionShare));
  const common = new Set([...itemRegions].filter(([, s]) => s.size >= need).map(([i]) => i));
  const all = new Set();
  for (const p of pools.values()) for (const i of p) all.add(i);
  const regions = [];
  for (const t of [...regionsWithDrops].sort((a, b) => (a === 0) - (b === 0) || a - b)) {
    const inT = rows.filter((r) => r.territory === t);
    const name = t === 0 ? config.otherRegionName : (inT.slice().sort((a, b) => a.index - b.index)[0]?.name || config.otherRegionName);
    const groups = new Map();
    for (const r of inT) {
      if (!pools.has(r.index)) continue;
      const key = config.mergeSameName ? r.name.toLowerCase() : String(r.index);
      const g = groups.get(key) || groups.set(key, { name: r.name, maps: [], set: new Set() }).get(key);
      g.maps.push(r.index);
      for (const i of pools.get(r.index)) if (!(config.commonOutOfMaps && common.has(i))) g.set.add(i);
    }
    const maps = [...groups.values()].filter((g) => g.set.size).sort((a, b) => a.maps[0] - b.maps[0]).map((g) => ({ name: g.name, maps: g.maps, items: sortItems(g.set) }));
    if (maps.length) regions.push({ territory: t, name, maps });
  }
  return { all: sortItems(all), common: sortItems(common), regions, commonRegions: need, regionCount: regionsWithDrops.size };
}
/** Case-insensitive part-of-name filter (empty text = everything). */
export function filterItems(items, text) {
  const q = String(text ?? '').trim().toLowerCase();
  return q ? items.filter((i) => i.name.toLowerCase().includes(q)) : items.slice();
}
/** The entry of a map index (or null). */
export function entryForMap(list, mapIndex) {
  for (const r of list?.regions || []) for (const m of r.maps) if (m.maps.includes(num(mapIndex))) return { region: r, map: m };
  return null;
}