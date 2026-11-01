// Client string tables used by the UI (script/string/**/*.txt).
//   <cate> N [#comment]
//   code N [#comment]
//   {
//   text lines...
//   }
// NPC ids (npcs.json, share/creature/npc.csv): `desc` -> npc/stringtable_job.txt ("Berks (Fortress Captain,
// Return Master)"), `comm` (CommTableIndex) -> npc/stringtable_conv.txt (the greeting), JobType ->
// npc/stringtable_jobtype.txt ("[Shop] I want to trade.").
import { fetchText } from '../engine/assets.js';

export const NPC_CONV = 'script/string/npc/stringtable_conv.txt';
export const NPC_JOB = 'script/string/npc/stringtable_job.txt';
export const NPC_JOBTYPE = 'script/string/npc/stringtable_jobtype.txt';

/** Parse a string table -> Map<code:number, text:string> (later duplicates win). */
export function parseStringTable(text) {
  const out = new Map();
  const lines = String(text).split(/\r?\n/);
  let code = null, buf = null;
  for (const raw of lines) {
    const line = raw.replace(/\s+$/, '');
    if (buf) {
      if (line.trim() === '}') {
        // trim leading/trailing blank lines, keep inner line breaks
        while (buf.length && !buf[0].trim()) buf.shift();
        while (buf.length && !buf[buf.length - 1].trim()) buf.pop();
        if (code != null) out.set(code, buf.join('\n'));
        buf = null; code = null;
      } else buf.push(line);
      continue;
    }
    const m = /^\s*code\s+(-?\d+)/i.exec(line);
    if (m) { code = Number(m[1]); continue; }
    if (line.trim() === '{' && code != null) buf = [];
  }
  return out;
}

const cache = new Map();
/** Load (once) and parse a string table; resolves an empty Map when unavailable. */
export function loadStringTable(key) {
  if (!cache.has(key)) {
    cache.set(key, fetchText(key, false).then(parseStringTable).catch(() => new Map()));
  }
  return cache.get(key);
}

/** "Berks (Fortress Captain, Return Master)" -> { name: 'Berks', title: 'Fortress Captain, Return Master' } */
export function splitNameTitle(s) {
  const text=String(s || '').trim();
  // The native job table uses both parentheses and square brackets for NPC
  // roles. Keep the role as its own line, without displaying those delimiters.
  const m=/^(.+?)\s*(?:\(([^()]*)\)|\[([^\[\]]*)\]|<([^<>]*)>)\s*$/.exec(text);
  return m ? {name:m[1].trim(),title:(m[2]??m[3]??m[4]).trim()} : {name:text,title:''};
}

/** Generated dungeon gates inherit a native NPC's desc, but own their displayed dungeon name. */
export function npcJobNameTitle(npc, jobString) {
  const generated = npc?.sharedDungeonIds?.length || npc?.entryGate || npc?.def?.entryGate;
  const name = npc?.name || npc?.def?.name;
  if (generated && name) return { name: String(name), title: '' };
  return jobString ? splitNameTitle(jobString) : null;
}

/** Human names for npcs.json roles when the jobtype string is missing. */
export const ROLE_LABELS = {
  SHOP: 'Shop', QUEST: 'Quest', TELEPORT: 'Teleport', STORAGE: 'Stash', RETURN: 'Return Point',
  SKILLMASTER: 'Skill Master', REPAIR: 'Repair', SKILLCLEAR: 'Skill Reset', GUARD: 'Guard', MAIL: 'Mail',
  ITEMUPGRADE: 'Reinforcement', STATCLEAR: 'Stat Reset', MULTISHOP: 'Shop', QUEST_MAIN: 'Quest',
  DUNGEON: 'Dungeon', PORTAL: 'Portal', REQUEST_QUEST: 'Request Quest',
};

/**
 * Everything the NPC dialog shows, resolved from npcs.json + the string tables.
 * @returns {Promise<{ name, title, greeting, options: Array<{jobType:number, jobIndex:number, role:string, label:string}> }>}
 */
export async function npcDialogInfo(def, jobTypes = {}) {
  const [conv, job, jobtype] = await Promise.all([loadStringTable(NPC_CONV), loadStringTable(NPC_JOB), loadStringTable(NPC_JOBTYPE)]);
  const jobStr = def?.desc != null ? job.get(Number(def.desc)) : null;
  const nt = splitNameTitle(jobStr || def?.name || 'Stranger');
  const roles = def?.roles || [];
  const title = nt.title || roles.map(r => ROLE_LABELS[r] || r).join(', ');
  const greeting = (def?.comm != null && conv.get(Number(def.comm))) || conv.get(0) || 'What do you want?';
  const options = [];
  // job types without their own line in stringtable_jobtype borrow the closest one
  const BORROW = { MULTISHOP: 0, QUEST_MAIN: 1, REQUEST_QUEST: 1, DAILY_QUEST_STD: 1 };
  const FALLBACK = { QUEST: '[Quest] Let us talk about your quests.', QUEST_MAIN: '[Quest] Let us talk about your quests.' };
  for (const [jt, ji] of def?.jobs || []) {
    const role = jobTypes?.[jt]?.name || roles[options.length] || String(jt);
    if (role === 'GUARD') continue; // guards have no menu entry
    const label = jobtype.get(Number(jt)) || (BORROW[role] != null && jobtype.get(BORROW[role])) || FALLBACK[role] || `[${ROLE_LABELS[role] || role}]`;
    options.push({ jobType: Number(jt), jobIndex: Number(ji), role, label: label.split('\n')[0] });
  }
  return { name: def?.name || nt.name, title, greeting, options };
}
