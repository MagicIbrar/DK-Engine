// Per-map level caps (MAP-CAPS): share/maplist.csv StrLevelCapPath names the map's level-difference table
// (share/pc/levelcap/<name>.csv: Index, Level Cap Start, Level Cap End, Exp Rate, Chaotic Rate, BLOCKING, BLOCKED, Color_R/G/B;
// 55 tables over 301 maps - Default for the fields, own tables for Mitera, Dead Front, the Karon ship, Tower ...).
// The difference is monster level minus player level; the band [Start, End) gives the % of the monster's EXP a player
// gets (the client uses the same rule for share/pc/levelcap.csv, progression.expRateFor), and the name colour.
import fs from 'node:fs/promises';
import path from 'node:path';
import { decodeText, parseCSV } from '../../src/formats/binreader.js';
import { abilityCapTable } from '../../src/game/ability-cap.js';

const num = v => { const n = Number(String(v ?? '').trim()); return Number.isFinite(n) ? n : 0; };

/** Map index -> [{from, to, expRate, chaoticRate, blocking, blocked, color:[r,g,b]}] for every map that names a table. */
export async function loadLevelCaps(dataRoot, rawMaps) {
  const files = new Map(), byMap = new Map();
  const read = async rel => {
    const key = String(rel).replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
    if (!files.has(key)) files.set(key, (async () => {
      const target = path.resolve(dataRoot, 'share', key);
      if (!target.startsWith(path.resolve(dataRoot, 'share') + path.sep)) return null;
      const rows = parseCSV(decodeText(await fs.readFile(target)));
      const header = rows.shift().map(h => String(h).trim());
      const col = name => header.indexOf(name);
      const c = ['Level Cap Start', 'Level Cap End', 'Exp Rate', 'Chaotic Rate', 'BLOCKING', 'BLOCKED', 'Color_R', 'Color_G', 'Color_B'].map(col);
      if (c.slice(0, 3).some(i => i < 0)) return null;
      return rows.filter(r => r.length > c[2] && String(r[c[0]] ?? '').trim() !== '').map(r => ({ from: num(r[c[0]]), to: num(r[c[1]]), expRate: num(r[c[2]]),
        chaoticRate: num(r[c[3]]), blocking: num(r[c[4]]), blocked: num(r[c[5]]), color: [num(r[c[6]]), num(r[c[7]]), num(r[c[8]])] }));
    })().catch(() => null));
    return files.get(key);
  };
  for (const [index, row] of rawMaps) {
    const rel = String(row?.StrLevelCapPath || '').trim();
    if (!rel || rel === '0') continue;
    const rows = await read(rel);
    if (rows?.length) byMap.set(Number(index), rows);
  }
  return byMap;
}

/** Map index -> ability cap table (maplist StrAbilityCapPath -> share/pc/abilitycap*.csv; src/game/ability-cap.js). */
export async function loadAbilityCaps(dataRoot, rawMaps) {
  const files = new Map(), byMap = new Map();
  const share = path.resolve(dataRoot, 'share');
  const read = rel => {
    const key = String(rel).replace(/\\/g, '/').replace(/^\/+/, '').toLowerCase();
    if (!files.has(key)) files.set(key, (async () => {
      const target = path.resolve(share, key);
      if (!target.startsWith(share + path.sep)) return null;
      const rows = parseCSV(decodeText(await fs.readFile(target)));
      rows.shift();
      return abilityCapTable(rows);
    })().catch(() => null));
    return files.get(key);
  };
  for (const [index, row] of rawMaps) {
    const rel = String(row?.StrAbilityCapPath || '').trim();
    if (!rel || rel === '0') continue;
    const table = await read(rel);
    if (table) byMap.set(Number(index), table);
  }
  return byMap;
}

/** EXP % for a level difference (monster - player) in a level-cap table; outside every band the extreme band applies. */
export function levelCapRate(rows, diff) {
  if (!Array.isArray(rows) || !rows.length) return 100;
  const d = Math.round(Number(diff) || 0);
  for (const r of rows) if (d >= r.from && d < r.to) return r.expRate;
  let lo = rows[0], hi = rows[0];
  for (const r of rows) { if (r.from < lo.from) lo = r; if (r.to > hi.to) hi = r; }
  return d >= hi.to ? hi.expRate : lo.expRate;
}
