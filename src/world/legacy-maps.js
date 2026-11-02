// Maps absent from the shipped client maplist but still shipped as Global files under map/, share/mapredcell/,
// light_*.txt and share/map/<dir>/. Shared by the client (world.js) and the host (server/world/data.mjs) so both
// sides load the same synthesised row. Every NAME below is a Global file or folder name (or the dungeonlist Name for
// index 120). The few fill VALUES in legacyMapRow with no Global row behind them are ENGINE-CHOSEN and marked there
// (scan fix A): EnvironmentMap, the Clip_Far '75' fallback, Reflect_Height and LimitMin/MaxLevel.
//
// LEGACY_MAPS: original 2005 field maps (1 North Ares, 2 Norak, 4 East Ares, 8 North Morte, 9 West Morte).
// ABSENT_MAPLIST_MAPS: later maps Global still ships without a client maplist row (conscript 27/28; dungeonlist
// MapIndex_0=120 "Karon's Fragments_S"). Folder MON_/NPC_ reconcile remains Lane 7 map-folder-bindings.
export const LEGACY_MAPS = {
  1: { Name: 'North Ares', file: 'ares_n', light: 'light_ares.txt', dir: '01_North_Ares' },
  2: { Name: 'Norak', file: 'norak', light: 'light_norak.txt', dir: '02_Norak' },
  4: { Name: 'East Ares', file: 'ares_e', light: 'light_ares.txt', dir: '04_East_Ares' },
  8: { Name: 'North Morte', file: 'morte_n', light: 'light_morte.txt', dir: '08_North_Morte' },
  9: { Name: 'West Morte', file: 'morte_w', light: 'light_morte.txt', dir: '09_West_Morte' },
};

/** Later maps with Global map/.mac/light files but no client maplist row (evidence: share/map folders + dungeonlist). */
export const ABSENT_MAPLIST_MAPS = {
  27: { Name: 'Conscript A', file: 'conscript_a', light: 'light_conscript_a_01.txt', dir: '27_conscript_a' },
  28: { Name: 'Conscript M', file: 'conscript_m', light: 'light_conscript_m_01.txt', dir: '28_conscript_m' },
  // dungeonlist.csv Dungeon_Name "Karon's Fragments_S" MapIndex_0=120; assets match map 122 Fragments_S file stem.
  120: { Name: "Karon's Fragments_S", file: 'under_crespo_indun', light: 'light_under_crespo_indun.txt', dir: '120_under_crespo_indun', dungeonIndex: '120' },
};

/** Combined lookup used by legacyMapRow / host registration / GM teleport lists. */
export function synthesisedMapDef(index) {
  const i = Number(index);
  return LEGACY_MAPS[i] || ABSENT_MAPLIST_MAPS[i] || null;
}

/** Every synthesised map def (legacy + absent-maplist), keyed by numeric index string. */
export function allSynthesisedMaps() {
  return { ...LEGACY_MAPS, ...ABSENT_MAPLIST_MAPS };
}

/** maplist-style row for a synthesised map (null if unknown). baseRow = a real maplist row to copy defaults from. */
export function legacyMapRow(index, baseRow = null) {
  const L = synthesisedMapDef(index);
  if (!L) return null;
  const malPad = String(index).padStart(3, '0');
  const dungeon = L.dungeonIndex != null ? String(L.dungeonIndex) : '0';
  return {
    ...(baseRow || {}),
    Index: String(index), Name: L.Name,
    MapFile: `${L.file}.map`, MapObject: `${L.file}.mol`, MapEffect: `${L.file}.mel`, MapAttribute: `${L.file}.mac`,
    // ENGINE-CHOSEN (no Global maplist row for 1/2/4/8/9/27/28/120): 'water/skyCube=.dds' is what the Norak siblings 14/600 use;
    // '75' is only the fallback when no baseRow exists; -1000 = no water plane (siblings 14 -0.3 and 600 -0.9 disagree).
    EnvironmentFile: L.light, EnvironmentMap: 'water/skyCube=.dds', Clip_Far: baseRow?.Clip_Far || '75',
    Reflect_Height: '-1000', Preloading: '',
    MapPath: `..\\Share\\Map\\${L.dir}\\m${malPad}.mal`,
    MonsterLocatePath: `..\\Share\\Map\\${L.dir}\\MON_${L.dir}.csv`,
    NPCLocatePath: `..\\Share\\Map\\${L.dir}\\NPC_${L.dir}.csv`, PosFile: `Map\\${L.dir}\\NPC_${L.dir}.csv`,
    // Braiken's own scripted/brick/trigger/callmonster rows are not part of the 2005 fields; conscript/120 keep brick
    // paths empty here (folder CSVs still load via Lane 7 reconcile / mapDataPaths when present on disk).
    BrickLocatePath: '', TriggerLocatePath: '', CallMonsterPath: '', ScriptName: '', DungeonIndex: dungeon, IsSiege: '0',
    LimitMinLevel: '0', LimitMaxLevel: '0', // ENGINE-CHOSEN: 0/0 = unrestricted (no Global row)
    legacy: true,
  };
}

/** First NPC position (Location_X/Location_Y columns of NPC_<dir>.csv), the same rule build-gmcommands uses for landings. */
export function firstNpcLanding(text) {
  const rows = String(text || '').split(/\r?\n/).map(l => l.split(','));
  const get = k => rows.find(r => r[0]?.trim().toLowerCase() === k);
  const xs = get('location_x'), zs = get('location_y'), dir = get('direction');
  if (!xs || !zs) return null;
  for (let i = 1; i < xs.length; i++) { const x = Number(xs[i]), z = Number(zs[i]); if (x > 1 && z > 1) return [x, z, Number(dir?.[i]) || 0]; }
  return null;
}
/** MON_<dir>.csv rows: monsterIndex, respawnSec, x, z (same shape as monsters.json spawns rows). */
export function parseLegacySpawns(text) {
  return String(text || '').split(/\r?\n/).map(l => l.split(',').map(Number)).filter(r => r.length >= 4 && r.slice(0, 4).every(Number.isFinite));
}
