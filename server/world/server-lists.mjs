// Runtime view of gamedata/server-lists.json (FEATURE-CENSUS D11). Read-only lookups; absent file = empty lists (older generations).
import { toolIpInRange } from '../../src/formats/server-lists.js';
export function createServerLists(json) {
  const l = json?.lists || {};
  const arrange = new Map((l.arrange || []).map(r => [r.index, r])), sync = new Map((l.sync || []).map(r => [r.index, r.name]));
  const ipGrade = new Map((l.iplist || []).map(r => [r.ip, r.grade])), grades = new Map((l.gradelist?.accounts || []).map(a => [a.id.toLowerCase(), a]));
  return Object.freeze({
    available: !!json, missing: json?.missing || [],
    /** Ornament/RandomEffect: effect indices for an item, or null. (build-boxes uses the same table as diceEffects.) */
    randomEffects: (itemIndex) => l.randomeffect?.[itemIndex] ? [...l.randomeffect[itemIndex]] : null,
    /** Arrange: { monster, npc } arrangement table paths for a map index (null when the row is empty). */
    arrangeForMap: (index) => { const r = arrange.get(Number(index)); return r ? { monster: r.monster, npc: r.npc } : null; },
    /** sync.csv: map attribute (.mal) path for a map index. Consumer in Global unknown. */
    syncMalForMap: (index) => sync.get(Number(index)) ?? null,
    /** ToolIPList: is this address inside the per-octet tool ranges (tooliplist.csv classA..D)? */
    toolIpInRange: (ip) => toolIpInRange(l.tooliplist, ip),
    /** iplist.csv grade for an exact address, or null. */
    ipGrade: (ip) => ipGrade.has(ip) ? ipGrade.get(ip) : null,
    /** gradelist.csv GM tool account (no password is ever loaded). */
    toolGrade: (id) => grades.get(String(id || '').toLowerCase()) || null,
  });
}
