// Original 2005 field maps (1 North Ares, 2 Norak, 4 East Ares, 8 North Morte, 9 West Morte). The shipped client maplist no
// longer lists them, but Global still ships every file: map/<file>.map/.mol/.mel/.mal (pack.d01), share/mapredcell/<file>.mac,
// light_<x>.txt and share/map/<dir>/ (m0NN.mal, MON_/NPC_ csv). Shared by the client (world.js) and the host (server/world/data.mjs)
// so both sides load the same synthesised row. Nothing here is invented: every name below is a Global file or folder name.
export const LEGACY_MAPS = {
  1: { Name: 'North Ares', file: 'ares_n', light: 'light_ares.txt', dir: '01_North_Ares' },
  2: { Name: 'Norak', file: 'norak', light: 'light_norak.txt', dir: '02_Norak' },
  4: { Name: 'East Ares', file: 'ares_e', light: 'light_ares.txt', dir: '04_East_Ares' },
  8: { Name: 'North Morte', file: 'morte_n', light: 'light_morte.txt', dir: '08_North_Morte' },
  9: { Name: 'West Morte', file: 'morte_w', light: 'light_morte.txt', dir: '09_West_Morte' },
};

/** maplist-style row for a legacy field map (null if unknown). baseRow = a real maplist row to copy defaults from. */
export function legacyMapRow(index, baseRow = null) {
  const L = LEGACY_MAPS[Number(index)];
  if (!L) return null;
  const pad = String(index).padStart(2, '0');
  return {
    ...(baseRow || {}),
    Index: String(index), Name: L.Name,
    MapFile: `${L.file}.map`, MapObject: `${L.file}.mol`, MapEffect: `${L.file}.mel`, MapAttribute: `${L.file}.mac`,
    EnvironmentFile: L.light, EnvironmentMap: 'water/skyCube=.dds', Clip_Far: baseRow?.Clip_Far || '75',
    Reflect_Height: '-1000', Preloading: '',
    MapPath: `..\\Share\\Map\\${L.dir}\\m0${pad}.mal`,
    MonsterLocatePath: `..\\Share\\Map\\${L.dir}\\MON_${L.dir}.csv`,
    NPCLocatePath: `..\\Share\\Map\\${L.dir}\\NPC_${L.dir}.csv`, PosFile: `Map\\${L.dir}\\NPC_${L.dir}.csv`,
    // Braiken's own scripted/brick/trigger/callmonster/level-cap rows are not part of these maps.
    BrickLocatePath: '', TriggerLocatePath: '', CallMonsterPath: '', ScriptName: '', DungeonIndex: '0', IsSiege: '0',
    LimitMinLevel: '0', LimitMaxLevel: '0',
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
