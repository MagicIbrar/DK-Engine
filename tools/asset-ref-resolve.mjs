// Global-evidence resolution for asset/data references whose authored path does not exist (PARITY-DIFF "PATH WIRING").
// A reference is re-pointed only when Global ships exactly ONE file with the same name in an allowed root; otherwise it stays
// missing and is reported. Nothing is renamed or synthesised.
//   - action-table anims/skels (Global brick .act rows name anim/brick/brick_gelsmark/brick/gelsmark_die.anim, the file is
//     anim/monster/gelsmark/gelsmark_die.anim; the trigger act names folder hr_fence_doorr, the file is in hr_fence_door/)
//   - map server tables: maplist names m126.mal under 125_..._indun_a (Global: 126_..._indun_s/m126.mal) and
//     callmonster_550_guild_port.csv (Global: callmon_550_guild_port.csv in the same folder)
export function makeNameIndex(keys) {
  const by = new Map();
  for (const k of keys) { const b = k.slice(k.lastIndexOf('/') + 1); if (!by.has(b)) by.set(b, []); by.get(b).push(k); }
  return by;
}
/** @returns {{key:string|null, how:'exact'|'basename'|'map-folder'|'callmon'|null, want:string}} */
export function resolveRef(want, has, byName, { roots = [] } = {}) {
  want = String(want || '').toLowerCase();
  if (!want) return { key: null, how: null, want };
  if (has(want)) return { key: want, how: 'exact', want };
  const b = want.slice(want.lastIndexOf('/') + 1), top = want.split('/')[0];
  // share/map/<n>_x/m<k>.mal with k != n: the mal of map k lives in map k's own folder
  const mal = /^share\/map\/[^/]+\/m(\d+)\.mal$/.exec(want);
  if (mal) { const alts = (byName.get(b) || []).filter(k => new RegExp(`^share/map/0*${Number(mal[1])}_[^/]+/m${mal[1]}\\.mal$`).test(k)); return alts.length === 1 ? { key: alts[0], how: 'map-folder', want } : { key: null, how: null, want }; }
  // callmonster_<x>.csv authored, Global folder ships callmon_<x>.csv
  const cm = /^(share\/map\/[^/]+\/)callmonster_([^/]+)$/.exec(want);
  if (cm) { const alt = `${cm[1]}callmon_${cm[2]}`; return has(alt) ? { key: alt, how: 'callmon', want } : { key: null, how: null, want }; }
  const allow = roots.length ? roots : [top];
  const alts = (byName.get(b) || []).filter(k => allow.some(r => k.startsWith(r + '/')));
  return alts.length === 1 ? { key: alts[0], how: 'basename', want } : { key: null, how: null, want };
}
