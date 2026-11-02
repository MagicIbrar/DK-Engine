// Map-folder convention bindings for MON_/NPC_ tables.
// Global ships share/map/<index>_<name>/MON_*.csv and NPC_*.csv. Client maplist sometimes omits
// MonsterLocatePath (e.g. 201 Honeymoon Island) or omits the map entirely (legacy 4/9; conscript 27/28).
// A prior server-maplist merge also bound 27/28 to Aquarius (26) files. Folder-index wins over a
// binding whose file lives under a different map index. Evidence: Global share/map disks +
// tools/build-monsters mapBindings; see docs/global-parity-420/lanes/LANE-07.log.
import fs from 'node:fs';
import path from 'node:path';
import { decodeText } from '../formats/binreader.js';
import { parseSpawnCSV, parseNpcCSV } from '../formats/spawn.js';
import { parseMapList } from '../formats/environment.js';
import { allSynthesisedMaps } from './legacy-maps.js';

// Global loads a share/map/<folder>/ table only when a maplist row (any path column) or a synthesised
// legacy/absent-maplist map names that folder. Unreferenced ("orphan") folders such as 30_infinitehunt_b
// (row 30 uses 24_Infinitehunt), 202-205 dravis_domain_field_*, 536-539 mitera_*, 238_karon_ship are never
// loaded (evidence: LANE-50-REPORT.md orphan audit; tools/test-lane50-maps-orphans-reachability.mjs).
const MAPLIST_PATH_COLS = ['MapPath', 'MonsterLocatePath', 'NPCLocatePath', 'BrickLocatePath', 'CallMonsterPath',
  'TriggerLocatePath', 'StrLevelCapPath', 'StrGradeCapPath', 'StrAbilityCapPath', 'PosFile'];
const FOLDER_RE = /share[\\/]map[\\/]([^\\/]+)[\\/]/i;

/** Lower-case share/map folder names that Global's maplist(s) or a synthesised map reference; null if no maplist. */
export function referencedMapFolders(dataRoot, io = fs) {
  const out = new Set();
  let any = false;
  for (const rel of [['share', 'maplist.csv'], ['share', 'server', 'maplist.csv']]) {
    const p = path.join(dataRoot, ...rel);
    if (!io.existsSync(p)) continue;
    any = true;
    for (const r of parseMapList(io.readFileSync(p))) {
      for (const c of MAPLIST_PATH_COLS) {
        const m = FOLDER_RE.exec(String(r[c] ?? ''));
        if (m) out.add(m[1].toLowerCase());
      }
    }
  }
  if (!any) return null;
  for (const def of Object.values(allSynthesisedMaps())) {
    const m = FOLDER_RE.exec(String(def.MapPath || ''));
    if (m) out.add(m[1].toLowerCase());
    if (def.dir) out.add(String(def.dir).toLowerCase());
  }
  return out;
}

/** Map index encoded in share/map/<index>_.../file.csv (null if not that layout). */
export function folderIndexFromDataKey(fileKey) {
  const m = String(fileKey || '').replace(/\\/g, '/').toLowerCase().match(/(?:^|\/)share\/map\/(\d+)_[^/]+\//);
  return m ? Number(m[1]) : null;
}

/** True when there is no binding, or its file belongs to a different map folder index. */
export function shouldReplaceMapFolderBinding(existingFile, mapIndex) {
  if (!existingFile) return true;
  const fi = folderIndexFromDataKey(existingFile);
  return fi == null || fi !== Number(mapIndex);
}

function toSpawnRows(parsed) {
  return parsed.spawns.map((s) => [s.monsterIndex, s.respawnSec, s.x, s.y]);
}

function toNpcPlacementRows(parsed) {
  return parsed.npcs.map((q) => [
    q.npcIndex,
    q.x, q.y, q.direction,
    q.warpX, q.warpY, q.isEvent,
    /^-?\d+$/.test(String(q.description ?? '')) ? +q.description : (q.description || ''),
  ]);
}

/**
 * Scan dataRoot/share/map for MON_/NPC_ CSVs keyed by folder index.
 * @returns {{ monsters: Map<number, {mapIndex:number, file:string, dirName:string, rows:any[], rowCount:number}>, npcs: Map<number, ...> }}
 */
export function scanMapFolderTables(dataRoot, io = fs, { referencedOnly = true } = {}) {
  const mapRoot = path.join(dataRoot, 'share', 'map');
  const monsters = new Map();
  const npcs = new Map();
  if (!io.existsSync(mapRoot)) return { monsters, npcs };
  const referenced = referencedOnly ? referencedMapFolders(dataRoot, io) : null;
  const dirs = io.readdirSync(mapRoot, { withFileTypes: true }).filter((d) => d.isDirectory());
  for (const d of dirs) {
    const mm = /^(\d+)_(.*)$/.exec(d.name);
    if (!mm) continue;
    if (referenced && !referenced.has(d.name.toLowerCase())) continue; // orphan folder: Global never loads it
    const mapIndex = Number(mm[1]);
    const dirPath = path.join(mapRoot, d.name);
    const files = io.readdirSync(dirPath);
    const monName = pickTableFile(files, mapIndex, 'mon');
    const npcName = pickTableFile(files, mapIndex, 'npc');
    if (monName) {
      const file = `share/map/${d.name}/${monName}`.toLowerCase();
      const text = decodeText(io.readFileSync(path.join(dirPath, monName)));
      const rows = toSpawnRows(parseSpawnCSV(text));
      const prev = monsters.get(mapIndex);
      if (!prev || preferTable(prev, { file, rows, mapIndex, name: monName })) {
        monsters.set(mapIndex, { mapIndex, file, dirName: mm[2].replace(/_/g, ' '), rows, rowCount: rows.length });
      }
    }
    if (npcName) {
      const file = `share/map/${d.name}/${npcName}`.toLowerCase();
      const text = decodeText(io.readFileSync(path.join(dirPath, npcName)));
      const rows = toNpcPlacementRows(parseNpcCSV(text));
      const prev = npcs.get(mapIndex);
      if (!prev || preferTable(prev, { file, rows, mapIndex, name: npcName })) {
        npcs.set(mapIndex, { mapIndex, file, dirName: mm[2].replace(/_/g, ' '), rows, rowCount: rows.length });
      }
    }
  }
  return { monsters, npcs };
}

/** Prefer basename that includes the map index; then more rows; then lexicographic file. */
function pickTableFile(files, mapIndex, kind) {
  const re = kind === 'mon'
    ? /^mon_.*\.csv$/i
    : /^npc_.*\.csv$/i;
  const skip = kind === 'mon' ? /_monster\.csv$/i : null;
  const pad = String(mapIndex).padStart(2, '0');
  const candidates = files.filter((f) => re.test(f) && !(skip && skip.test(f)));
  if (!candidates.length) return null;
  candidates.sort((a, b) => {
    const score = (n) => {
      const low = n.toLowerCase();
      let s = 0;
      if (low.includes(`_${mapIndex}_`) || low.startsWith(`${kind}_${mapIndex}_`) || low.startsWith(`${kind}_${pad}_`)) s += 2;
      return s;
    };
    const d = score(b) - score(a);
    return d || a.localeCompare(b);
  });
  return candidates[0];
}

function preferTable(prev, next) {
  if (next.rows.length !== prev.rowCount) return next.rows.length > prev.rowCount;
  return next.file < prev.file;
}

/**
 * Mutate monsters.spawns (or a plain spawns object): fill missing maps and replace
 * bindings whose file folder index disagrees with the map index.
 */
// Scan fix A: tower instances 95/99 have an empty maplist MonsterLocatePath (maplist.csv:90/94) and spawn only via
// callmonster_95/_99 wave scripts; their mon_ files share map 98's SHA. Never add a folder spawn table for them
// (mirrors tools/build-monsters.mjs SCRIPT_ONLY_SPAWN_MAPS; 201 stays folder-bound per LANE-07).
// Owner rule (never remove content): kept spawning by default; DEKARON_SCRIPT_ONLY_MAPS_STATIC=0 makes them script-only.
export const SCRIPT_ONLY_SPAWN_MAPS = (typeof process !== 'undefined' && process.env?.DEKARON_SCRIPT_ONLY_MAPS_STATIC === '0') ? new Set([95, 99]) : new Set();

export function reconcileSpawnsFromFolders(spawns, folderMonsters) {
  const report = { added: [], replaced: [], kept: 0 };
  if (!spawns || typeof spawns !== 'object') return report;
  for (const [mapIndex, table] of folderMonsters) {
    const cur = spawns[mapIndex] ?? spawns[String(mapIndex)];
    if (!cur && SCRIPT_ONLY_SPAWN_MAPS.has(Number(mapIndex))) continue;
    if (cur && !shouldReplaceMapFolderBinding(cur.file, mapIndex)) {
      report.kept++;
      continue;
    }
    const entry = {
      name: cur?.name || table.dirName || String(mapIndex),
      map: cur?.map ?? null,
      file: table.file,
      rows: table.rows,
      from: 'folder',
    };
    if (cur) report.replaced.push({ index: mapIndex, was: cur.file || null, now: table.file, wasRows: cur.rows?.length || 0, nowRows: table.rows.length });
    else report.added.push({ index: mapIndex, file: table.file, rows: table.rows.length });
    spawns[mapIndex] = entry;
    if (Object.prototype.hasOwnProperty.call(spawns, String(mapIndex)) && String(mapIndex) !== String(Number(mapIndex))) {
      // numeric key already set; drop duplicate string key if both existed as different refs
    }
  }
  return report;
}

/** Same rule for npcs.json placements. */
export function reconcilePlacementsFromFolders(placements, folderNpcs) {
  const report = { added: [], replaced: [], kept: 0 };
  if (!placements || typeof placements !== 'object') return report;
  for (const [mapIndex, table] of folderNpcs) {
    const cur = placements[mapIndex] ?? placements[String(mapIndex)];
    // Scan fix A: same table basename (e.g. map 31 maplist NPCLocatePath -> 24_infinitehunt/npc_24_infinitehunt.csv,
    // a byte copy in 31_infinitehunt_c) keeps the maplist-named file (mirrors tools/build-monsters.mjs).
    const base = (f) => String(f || '').replace(/\\/g, '/').split('/').pop().toLowerCase();
    if (cur && cur.file && base(cur.file) === base(table.file)) {
      report.kept++;
      continue;
    }
    if (cur && !shouldReplaceMapFolderBinding(cur.file, mapIndex)) {
      report.kept++;
      continue;
    }
    const entry = {
      name: cur?.name || table.dirName || String(mapIndex),
      map: cur?.map ?? null,
      file: table.file,
      rows: table.rows,
      from: 'folder',
    };
    if (cur) report.replaced.push({ index: mapIndex, was: cur.file || null, now: table.file, wasRows: cur.rows?.length || 0, nowRows: table.rows.length });
    else report.added.push({ index: mapIndex, file: table.file, rows: table.rows.length });
    placements[mapIndex] = entry;
  }
  return report;
}

/** Load + reconcile both tables from a Global data root. Mutates monstersFile / npcsFile. */
export function reconcileMapFolderBindings(monstersFile, npcsFile, dataRoot, io = fs) {
  const scanned = scanMapFolderTables(dataRoot, io);
  const spawns = reconcileSpawnsFromFolders(monstersFile?.spawns || (monstersFile.spawns = {}), scanned.monsters);
  const placements = reconcilePlacementsFromFolders(npcsFile?.placements || (npcsFile && (npcsFile.placements = {})), scanned.npcs);
  return { spawns, placements, scanned: { monsterMaps: scanned.monsters.size, npcMaps: scanned.npcs.size } };
}
