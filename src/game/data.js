// Loads the pre-built game tables (gamedata/*.json) plus the map list from the client.
import { fetchJSON, fetchCSVObjects } from '../engine/assets.js';
import { SWIM_FALLBACK } from './swim-fallback.js';

export const ARDECA_MAP = 150;
// Server rules:
// - a NEW character first appears at Ardeca 203,247, between Iron Blood Kale (180,248: giver of the story line's first
//   quest 9414) and Fionelle (209,239), where the main quest line begins; facing west towards Kale (dirDeg 90).
// - death / "revive in town" returns to the middle of Ardeca, the town portal circle (location.csv 107 /
//   portallocation "Ardeca" 349,129).
export const ARDECA_START = { mapIndex: ARDECA_MAP, x: 203.5, z: 247.5, dirDeg: 90 };
export const ARDECA_RESPAWN = { mapIndex: ARDECA_MAP, x: 349.5, z: 129.5, dirDeg: 0 };

export class GameData {
  async load(onProgress = () => {}) {
    const steps = [
      ['classes', () => fetchJSON('/gamedata/classes.json')],
      ['exp', () => fetchJSON('/gamedata/exp.json')],
      ['monsters', () => fetchJSON('/gamedata/monsters.json')],
      ['npcs', () => fetchJSON('/gamedata/npcs.json')],
      ['sound', () => fetchJSON('/gamedata/sound.json').catch(() => null)],
      ['maplist', () => fetchCSVObjects('share/maplist.csv')],
    ];
    let done = 0;
    await Promise.all(steps.map(async ([k, fn]) => {
      this[k === 'classes' ? 'classesFile' : k] = await fn();
      onProgress(++done / steps.length, k);
    }));

    this.classes = this.classesFile.classes || [];
    // Older prepared caches predate the swim rows. Keep their character tables
    // otherwise untouched; freshly prepared data already contains these rows.
    for (const cls of this.classes) {
      const native = SWIM_FALLBACK[String(cls.index)]?.base;
      if (!native) continue;
      cls.anims ||= {};
      for (const [key, value] of Object.entries(native)) cls.anims[key] ||= value;
    }
    this.classByIndex = new Map(this.classes.map(c => [Number(c.index), c]));
    this.maps = new Map();
    for (const row of this.maplist) {
      const idx = Number(row.Index);
      if (Number.isFinite(idx) && row.MapFile) this.maps.set(idx, row);
    }
    return this;
  }

  mapByIndex(i) { return this.maps.get(Number(i)) || null; }

  /** Monster definition with its index attached, or null. */
  monster(index) {
    const m = this.monsters?.monsters?.[index];
    return m ? { index: Number(index), ...m } : null;
  }

  /** Where a brand-new character of this class appears. */
  startFor(classIndex) {
    // New characters start in Ardeca (map 150), as on the user's original server. The world picks the town's
    // start/respawn point, since pc/startpoint.csv in this client still lists the legacy Braiken/Loa starts.
    if (this.maps.has(ARDECA_MAP)) return { ...ARDECA_START };
    const s = this.classesFile.startLocations?.[0]?.start || this.classesFile.defaultStart;
    return s ? { mapIndex: s.mapIndex, x: s.x + 0.5, z: s.y + 0.5, dirDeg: s.directionDeg ?? 0 } : { mapIndex: 0, x: 256, z: 256, dirDeg: 0 };
  }

  /** Respawn point for a map (its maplist return entry, else the class start). */
  respawnFor(mapIndex) {
    const row = this.mapByIndex(mapIndex);
    const ret = row && Number(row.RetMapIndex);
    const rx = row && Number(row.RetX), ry = row && Number(row.RetY);
    if (row && rx > 0 && ry > 0 && this.maps.has(ret)) return { mapIndex: ret, x: rx + 0.5, z: ry + 0.5, dirDeg: 0 };
    if (this.maps.has(ARDECA_MAP)) return { ...ARDECA_RESPAWN };
    const s = this.classesFile.startLocations?.[0]?.respawn || this.classesFile.defaultStart;
    return s ? { mapIndex: s.mapIndex, x: s.x + 0.5, z: s.y + 0.5, dirDeg: s.directionDeg ?? 0 } : this.startFor(0);
  }

  expNeeded(level) {
    const L = this.exp?.levels;
    // No authored exp.json levels: never invent a quadratic curve (Global uses share/pc/exp.csv).
    if (!L) return Infinity;
    const row = Array.isArray(L) ? L.find(r => r.level === level) || L[level] : L[level];
    return row ? Number(row.exp) : Infinity;
  }
}
