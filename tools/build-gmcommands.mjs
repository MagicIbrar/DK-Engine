#!/usr/bin/env node
// Dekaron Solo — GM / admin command database builder.
//
//   node tools/build-gmcommands.mjs [--data <unpacked data root>] [--out <dir>] [--pretty] [--quiet] [--spot] [--scan]
//
//   --spot  print 10 JSON entries next to their raw source lines (hand check)
//   --scan  byte-scan the WHOLE client (ascii + utf-16le) for GM command tokens and store the result in report.clientScan
//           (~2 min; without it the last recorded scan is kept)
//
// Reads the user's own unpacked client (default ../data/unpacked/data next to the engine) and writes
//   gamedata/gmcommands.json           the command registry (syntax, typed args, dropdown sources, evidence) +
//                                      every GM-related table found in the client (GM tool privileges, GM tool windows,
//                                      GM NPC menus, GM buffs, OX quiz, GM event strings, GM items/monsters/NPCs/quests,
//                                      console, map-tool console commands, chat/emote commands, system variables, formula)
//   gamedata/gmcommands_lists.json     dropdown data: maps, locations, dungeons, npcs, skills, quests, statuses, classes,
//                                      emotes, chat types, call groups, skies, scheduled contents
//   gamedata/gmcommands_items.json     every item of every item table (EU names) + item options + socket kinds
//   gamedata/gmcommands_monsters.json  every monster with level/HP/rank, where it spawns and exactly what it drops
//
// The executables are not in the client, so the literal chat syntax the original server parsed is NOT shipped. The
// builder records, per command, whether it is `original` (the operation, its UI and its strings are in the data),
// `original-inferred` (the capability is proven by the data, the spelling is ours), `player`/`maptool` (commands whose
// spelling IS in the data) or `solo` (tools the original never had). Every evidence reference is verified here.
//
// Joins with gamedata/monsters.json + npcs.json + classes.json (built from the same client by tools/build-monsters.mjs
// and tools/build-characters.mjs) for spawns / placements / drops / classes. Everything else is read raw.
// Format documentation: docs/formats/gmcommands.md

import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { BinReader, stripBOM } from '../src/formats/binreader.js';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const argv = process.argv.slice(2);
const argVal = (k, d) => { const i = argv.indexOf(k); return i >= 0 && argv[i + 1] ? argv[i + 1] : d; };
const DATA = path.resolve(argVal('--data', path.join(HERE, '..', '..', 'data', 'unpacked', 'data')));
const OUT = path.resolve(argVal('--out', path.join(HERE, '..', 'gamedata')));
const GAMEDATA = process.env.DEKARON_GAMEDATA || path.resolve(HERE, '..', 'gamedata');
const PRETTY = argv.includes('--pretty');
const QUIET = argv.includes('--quiet');
const SPOT = argv.includes('--spot');
const SCAN = argv.includes('--scan');
const log = (...a) => { if (!QUIET) console.log(...a); };

const hardFails = [], softWarns = [];
const hard = (m) => { hardFails.push(m); };
const soft = (m) => { softWarns.push(m); };

// ------------------------------------------------------------------------------------------------
// file helpers — every path handed around is a data key: lower case, '/' separated, relative to DATA
// ------------------------------------------------------------------------------------------------
const abs = (key) => path.join(DATA, ...key.split('/'));
const exists = (key) => { try { return fs.statSync(abs(key)).isFile(); } catch { return false; } };
const readKey = (key) => fs.readFileSync(abs(key));
const usedKeys = new Set();          // every data key referenced by the JSON (validated at the end)
const K = (key) => { const k = String(key).toLowerCase().replace(/\\/g, '/'); usedKeys.add(k); return k; };

const utf16 = new TextDecoder('utf-16le');
let krDec; try { krDec = new TextDecoder('euc-kr'); } catch { krDec = new TextDecoder('latin1'); }
/** client text file -> JS string (UTF-16LE with BOM, else CP949/EUC-KR which is a superset of ASCII) */
function decodeText(buf) {
  if (buf.length >= 2 && buf[0] === 0xff && buf[1] === 0xfe) return utf16.decode(buf.subarray(2));
  return krDec.decode(stripBOM(buf));   // a UTF-8 BOM (Global edit) must not become part of the first header cell
}
const hasHangul = (s) => /[ㄱ-힝]/.test(s);
const num = (v, d = 0) => { const x = Number(String(v ?? '').trim()); return Number.isFinite(x) ? x : d; };
const round = (x, k = 6) => (Number.isFinite(x) ? Math.round(x * 10 ** k) / 10 ** k : x);
const stripTags = (s) => String(s ?? '').replace(/<\/?(color|font|center|set|img|effectui|sound)[^>]*>/gi, '').replace(/\[\/?(elink|nlink|mlink)\]/gi, '').replace(/\s+/g, ' ').trim();

/**
 * Dekaron csv -> array of rows, one per PHYSICAL line (blank lines kept as []), fields trimmed, surrounding quotes
 * removed. The client's tables are not RFC-4180 (names contain stray quotes), and lines_eu addresses rows by physical
 * line number (row k = line k, the header being line 0), so a line-based split is the faithful reader.
 */
function readCsvLines(key) {
  const text = decodeText(readKey(key));
  const lines = text.split(/\r\n|\n|\r/);
  if (lines.length && lines[lines.length - 1] === '') lines.pop();
  return lines.map((ln) => (ln.trim() === '' ? [] : ln.split(',').map((f) => f.trim().replace(/^"(.*)"$/s, '$1'))));
}
const headerIndex = (hdr, ...names) => {
  const H = hdr.map((h) => String(h).trim().toLowerCase().replace(/\s+/g, ' '));
  for (const n of names) { const i = H.indexOf(n.toLowerCase()); if (i >= 0) return i; }
  return -1;
};

// ------------------------------------------------------------------------------------------------
// script/lines_eu (UTF-16LE localisation database), full parse incl. txt keys
//   u32 nTxt { u32 len, wchar name[len], u32 n, n x (i32,i32) }   u32 nCsv { same }
//   u32 nStr { u32 id, u32 len, wchar text[len] }
//   u32 nKeyT { u32 len, wchar "00|file.txt#cate|code", u32 id }   u32 nKeyC { u32 len, wchar "grp#file.csv#col|row", u32 id }
// csv keys address a cell by column and PHYSICAL data row (row 1 = first line after the header line).
// ------------------------------------------------------------------------------------------------
export function parseLinesEu(buf) {
  const r = new BinReader(buf);
  const wstr = (n) => utf16.decode(r.bytes(n * 2));
  const readIndex = () => { const n = r.u32(); const out = []; for (let i = 0; i < n; i++) { const name = wstr(r.u32()); const c = r.u32(); for (let k = 0; k < c; k++) { r.i32(); r.i32(); } out.push(name); } return out; };
  const txtFiles = readIndex(), csvFiles = readIndex();
  const nStr = r.u32(); const strings = new Map();
  for (let i = 0; i < nStr; i++) { const id = r.u32(); strings.set(id, wstr(r.u32())); }
  const readKeys = (norm) => { const n = r.u32(); const m = new Map(); for (let i = 0; i < n; i++) { const k = norm(wstr(r.u32())); const id = r.u32(); if (!m.has(k)) m.set(k, id); } return m; };
  const txt = readKeys((k) => k.slice(k.indexOf('|') + 1).toLowerCase());   // "file.txt#cate|code"
  const csv = readKeys((k) => k.toLowerCase());                              // "grp#file.csv#col|row"
  return { txtFiles, csvFiles, strings, txt, csv, trailingBytes: r.remaining };
}

// ------------------------------------------------------------------------------------------------
// script/string/*.txt string tables:  <cate> N [#c] / code M [#c] / { lines } / </cate>
// ------------------------------------------------------------------------------------------------
export function parseStringTable(text) {
  const out = new Map(); let cate = null, code = null, acc = null;
  for (const raw of text.split(/\r\n|\n|\r/)) {
    const s = raw.trim();
    if (acc) { if (s === '}') { out.set(`${cate}:${code}`, acc.join('\n')); acc = null; } else acc.push(raw.replace(/\s+$/, '')); continue; }
    let m;
    if ((m = /^<cate>\s*(\d+)/i.exec(s))) { cate = +m[1]; continue; }
    if ((m = /^code\s+(\d+)/i.exec(s))) { code = +m[1]; continue; }
    if (s.startsWith('{')) {
      const rest = s.slice(1).trim();
      if (rest.endsWith('}')) { out.set(`${cate}:${code}`, rest.slice(0, -1).trim()); continue; }
      acc = rest ? [rest] : [];
    }
  }
  return out;
}

/** script/ui/*.txt window description -> flat control list (id, kind, rect, text2, text, maxlength, input…) */
export function parseUiWindow(text) {
  const root = { kind: 'root', attrs: {}, children: [] }; const stack = [root];
  for (const raw of text.split(/\r\n|\n|\r/)) {
    const s = raw.trim(); if (!s || s.startsWith('//')) continue;
    let m;
    if ((m = /^<\/(\w+)>/.exec(s))) { if (stack.length > 1) stack.pop(); continue; }
    if ((m = /^<(\w+)>/.exec(s))) { const n = { kind: m[1].toLowerCase(), attrs: {}, children: [] }; stack[stack.length - 1].children.push(n); stack.push(n); continue; }
    const kv = /^(\S+)\s*(.*)$/.exec(s); if (!kv) continue;
    const cur = stack[stack.length - 1]; const key = kv[1].toLowerCase();
    if (!(key in cur.attrs)) cur.attrs[key] = kv[2].replace(/\s+/g, ' ').trim();
  }
  const win = root.children.find((c) => c.kind === 'window') || root;
  const controls = [];
  const walk = (n) => {
    for (const c of n.children) {
      if (c.attrs.id && !['title', 'image', 'vscroll'].includes(c.kind) || (c.kind === 'vscroll' && c.attrs.id)) {
        const titles = c.children.filter((t) => t.kind === 'title');
        const t2 = titles.map((t) => t.attrs.text2).find(Boolean); const tx = titles.map((t) => t.attrs.text).find(Boolean);
        const ctl = { id: c.attrs.id, kind: c.kind };
        if (c.attrs.rect) ctl.rect = c.attrs.rect.split(/\s+/).map(Number);
        if (t2) ctl.text2 = t2.split(/\s+/).map(Number);
        if (tx) ctl.text = tx.replace(/^"|"$/g, '');
        for (const k of ['maxlength', 'maxline', 'inputmode', 'input_type', 'color', 'multiline', 'visible', 'modal']) if (c.attrs[k] !== undefined) ctl[k] = /^-?\d+$/.test(c.attrs[k]) ? +c.attrs[k] : c.attrs[k];
        controls.push(ctl);
      }
      walk(c);
    }
  };
  walk(win);
  const w = { name: win.attrs.name, rect: win.attrs.rect ? win.attrs.rect.split(/\s+/).map(Number) : undefined, controls };
  for (const k of ['position', 'layertype', 'alwaysontop', 'modal']) if (win.attrs[k] !== undefined) w[k] = win.attrs[k];
  return w;
}

/** 'a  ,1' style ini used by share/formula*.ini */
function parseCommaIni(text) {
  const out = [];
  for (const raw of text.split(/\r\n|\n|\r/)) {
    const s = raw.trim(); if (!s || s.startsWith(';') || s.startsWith('//')) continue;
    const i = s.indexOf(','); if (i < 0) continue;
    const k = s.slice(0, i).trim(); const v = s.slice(i + 1).trim();
    out.push([k, /^-?\d+(\.\d+)?f?$/.test(v) ? Number(v.replace(/f$/, '')) : v]);
  }
  return out;
}

// ================================================================================================
// Hand-authored knowledge (translations / interpretations the data cannot state itself)
// ================================================================================================

/** share/server/gradelist.csv privilege columns -> meaning. Names are the client's; meaning = name + matching strings. */
const PRIVILEGE_MEANING = {
  CHANGESCRIPT: ['Reload / switch server scripts (quest + dungeon script tables) without a restart', 'medium'],
  RESETMAXCOUNT: ['Reset the server-side max/limit counters (per-day entry & usage counts, max-user record)', 'low'],
  ITEMDROPRATIO: ['Run an item drop-rate event (string 178:2 "Drop x%d EVENT"; formula fMonItemDropRatio)', 'high'],
  MONEYDROPRATIO: ['Run a DIL drop-rate event (string 178:3 "DIL Drop x%d EVENT"; formula fMonMoneyDropRatio)', 'high'],
  REGISTRYCHANGE: ['Change server registry / tunables (share/system_variable.csv, share/formula.ini)', 'medium'],
  ALLNOTIFY: ['Server-wide notice (GM tool notice window: "Send to All")', 'high'],
  FINISHGAME: ['Shut the game server down with a countdown (string 1002:5 "The server closes in %d minute(s).")', 'high'],
  TOTALUSERCOUNT: ['Query the total number of connected users', 'high'],
  MONSTEREXPRATIO: ['Run a monster EXP-rate event (string 178:1 "EXP x%d EVENT"; exppolicy source GMTOOL)', 'high'],
  PCROOMEXPRATIO: ['Set the Internet-cafe EXP bonus (string 1002:4 "+20%"; share/period*.csv)', 'medium'],
  CHANGESIEGE: ['Change siege-war state / schedule', 'medium'],
  GUILDWARTELEPORT: ['Teleport guilds into / out of a guild war', 'medium'],
  CHANGEPARTYWAR: ['Change party-war (Dead Front / Ice Castle) state', 'medium'],
  AIREGIST: ['Register / reload monster AI (share/ai tables)', 'low'],
  PARTYWAREVENT: ['Start a party-war event', 'medium'],
  USERLOG: ['Read user logs', 'medium'],
  APPLIEDALLVALUE: ['Apply changed values to all servers / channels', 'low'],
  MAPUSERCOUNT: ['Query users per map', 'high'],
  USERMONITOR: ['Monitor a user', 'medium'],
  MONITORSIEGE: ['Observe a siege war (observer mode)', 'medium'],
};

/** share/system_variable.csv descriptions (Korean in the client) — English glosses + what the value refers to. */
const SYSVAR_EN = {
  1: ['Result item index when a socket stone is dismantled', 'item'], 2: ['Socket-stone dismantle jackpot chance (per 1,000,000)'],
  3: ['Extra items granted on a socket-stone dismantle jackpot'], 4: ['D-Shop item icon size (120 = 1.2x)'],
  5: ['Amplification formula MIN constant 1 (hundredths: 5 = 0.05)'], 6: ['Amplification formula MIN constant 2'],
  7: ['Amplification formula MAX constant 1 (hundredths: 15 = 0.15)'], 8: ['Amplification formula MAX constant 2'],
  9: ['Engraving base success rate'], 10: ['Engraving success constant 1 (soul stone value below the gear level)'],
  11: ['Engraving success constant 2 (soul stone value equal to the gear level)'], 12: ['Engraving success constant 3 (soul stone value above the gear level)'],
  13: ['Pet summon cast time (ms)'], 14: ['Pet dismiss cast time (ms)'], 15: ['Mount summon cast time (ms)'], 16: ['Mount dismiss cast time (ms)'],
  17: ['Highest level that may be a disciple (mentor system)'], 18: ['Lowest level that may be a mentor'], 19: ['Mentor request answer timeout'],
  20: ['Growth Blessing warp cast time (ms; NPC warp and party warp)'], 21: ['DIL cost of an appearance change (cash items)'],
  22: ['DIL cost of an appearance change (normal items)'], 23: ['D-Shop banner time per page (ms)'], 24: ['Consignment shop gold-bar item index', 'item'],
  25: ['Consignment shop (unspecified)'], 26: ['Consignment shop (unspecified)'],
  27: ['Upgrade-rate correction level: gear at or above this level uses "Upgrade Rate2" of itemupgrade.csv'],
  28: ['Smart Warp gauge time (ms)'], 29: ['Smart Warp required item type'], 30: ['EXP donation unit'], 31: ['DIL donation unit'], 32: ['Maximum donation'],
  33: ['Upgrade-fee discount level: items at or below it pay a reduced fee'], 34: ['Upgrade-fee reduction (%) for items at or below variable 33'],
  35: ['Upgrade-fee increase (%) for Legend rank (RANK = 3) items'], 36: ['Option craft / socket add / socket remove fee discount tier 1 (levels 1-130)'],
  37: ['Option craft / socket add / socket remove fee discount tier 2 (levels 131-149)'], 38: ['Tier-1 fee multiplier = 1 - value/100'],
  39: ['Tier-2 fee multiplier = 1 - value/100'], 40: ['HP/MP restored to this percentage after a duel'],
  41: ['Next-monster-target hotkey search range (x10 for precision: 50 = 5 cells)'], 42: ['Next-monster-target re-search time (ms)'],
  43: ['Emblem (munzang) rank-1 extraction chance (%)'], 44: ['Emblem rank-2 extraction chance (%)'], 45: ['Emblem rank-3 extraction chance (%)'],
  46: ['Emblem rank-4 extraction chance (%)'], 47: ['Emblem rank-1 extraction fee (DIL)'], 48: ['Emblem rank-2 extraction fee (DIL)'],
  49: ['Emblem rank-3 extraction fee (DIL)'], 50: ['Emblem rank-4 extraction fee (DIL)'], 51: ['Frontier dungeon entry item index', 'item'],
  52: ['Broker search delay after results (ms)'], 53: ['Craft mastery change fee, 2nd attempt (DIL)'], 54: ['Craft mastery change fee, 3rd attempt (DIL)'],
  55: ['Craft mastery change fee, 4th attempt (DIL)'], 56: ['Craft mastery change fee, 5th and later attempts (DIL)'],
  57: ['Ego item: satisfaction % lost on dissolution'], 58: ['Ego item: boss monster index', 'monster'], 59: ['Ego item: boss spawn map index', 'map'],
  60: ['Ego item: daily natural satisfaction decrease'], 61: ['Ego item: destroyed after this many days at 0 satisfaction'],
  62: ['Personal supply machine: uses per day'], 63: ['Personal supply machine: ticket item 1 (free ticket)', 'item'], 64: ['Personal supply machine: ticket 1 count per use'],
  65: ['Personal supply machine: ticket item 2 (paid ticket)', 'item'], 66: ['Personal supply machine: ticket 2 count per use'],
  67: ['Personal supply machine: shuffle cost (DIL)'], 68: ['Personal supply machine: grade-2 correction chance (%)'],
  69: ['Personal supply machine: grade-3 correction chance (%)'], 70: ['Lost Horizon: maximum combo count shown'],
  71: ['Personal supply machine: usable channel number'], 72: ['Personal supply machine: uses before the reward item is granted'],
  73: ['Personal supply machine: reward item index', 'item'], 74: ['Territory war: ownership expiry time before the war starts'], 75: ['Internet-cafe premium item', 'item'],
};

/** script/string/tool/mapbuilder.txt cate 20000 (Korean) — English. The map tool the original developers used. */
const MAPBUILDER_EN = {
  1: 'Same as Menu > File > New Map', 2: 'Same as Menu > File > MapList', 3: 'Same as Menu > File > Save All', 4: 'Left-click + drag: camera zoom',
  5: 'Left-click + drag: camera rotate', 6: 'Left-click + drag: camera pan', 7: 'Tile Property: tile list viewer',
  8: 'Set the mouse to the empty brush (does nothing; use it when you want no edit)', 9: 'Switch to the water brush', 10: 'Switch to the blocked-cell (no-walk) brush',
  11: 'Raise terrain (Ctrl+click raises only up to a fixed height)', 12: 'Shift+click raises / lowers vertices', 13: 'Multi-select (Alt: set height 0) (Shift: raise / lower)',
  14: 'Brush view on/off', 15: 'Combo box to choose an object / effect / creature; the chosen entry is placed on the map', 16: 'Switch to the object-insert brush',
  17: '4-way arrow: move a placed object', 18: 'Leave 4-way arrow mode', 19: 'Rotate a placed object around Y', 20: 'Rotate a placed object around X',
  21: 'Rotate a placed object around Z', 22: 'Scale a placed object', 23: 'Delete a placed object', 24: 'Creatures (NPC, monster, BRICK) show/hide',
  25: 'Blocked cells view/hide', 26: 'Water tile animation on/off', 27: 'Objects show/hide', 28: 'Terrain show/hide', 29: 'Effects show/hide', 30: 'Grid show/hide',
  31: 'Place a PC character on screen', 32: 'Remove the PC character from screen',
};

/** Korean chat-type shortcuts of script/lua/chattype_macro.lua -> English (translation, for the solo console aliases) */
const CHATTYPE_EN = { 0: 'normal', 1: 'shout', 3: 'whisper', 4: 'party', 7: 'guild', 10: 'officer', 15: 'invite', 16: 'alliance', 20: 'match' };
const KR_SHORTCUT_EN = { '/일반': '/normal', '/일': '/n', '/외치기': '/shout', '/외': '/s', '/귓속말': '/whisper', '/귓': '/w', '/파티': '/party', '/파': '/p',
  '/원정대': '/expedition', '/원': '/e', '/길드': '/guild', '/길': '/g', '/임원': '/officer', '/임': '/o', '/초대': '/invite', '/초': '/i', '/연합': '/alliance', '/연': '/a', '/매칭': '/match', '/매': '/m' };

/** GM-related reserved words of script/filter/* (Korean ones glossed) */
const RESERVED_KR_EN = { '게임하이운영자': 'GameHi operator', '관리자': 'administrator', '데카론운영자': 'Dekaron operator', '운영': 'operation', '운영자': 'operator (GM)',
  '운영자도우미': 'operator helper (GM assistant)', '운영팀': 'operations team' };

/** Result of the full-client byte scan (`--scan` re-runs it; this is the last recorded run, 2026-09-28). */
const CLIENT_SCAN_LAST = {
  ran: '2026-09-29', files: 190246, scanned: 146382, bytes: 5560864877, skipped: 'media (.dds .tga .bmp .jpg .png .wav .ogg .mp3 .x)', encodings: ['ascii (case-insensitive)', 'utf-16le'],
  hits: { '/gm': 88, gmcmd: 0, gm_cmd: 0, gmcommand: 0, makeitem: 0, createitem: 0, callmonster: 283, call_monster: 0, summonmonster: 0, '/call ': 0, '/move ': 14, '/warp': 2, '/level': 34, '/item ': 29,
    cheat: 41, '/notice': 1, gmtool: 1, 'gm tool': 1, '/kick': 0, '/ban': 2, '/mute': 0, '/invisible': 1, '/invincible': 0, '/goto': 0, '/recall': 0, '/summon': 18, admincommand: 0, '/admin': 0,
    setlevel: 0, addexp: 6, '/exp ': 77, '/money': 0, '/dil ': 10 },
  result: 'No GM command vocabulary anywhere in the client. Every hit is unrelated: "/gm" only inside binary float data of .anim/.mesh files; "callmonster" only as the maplist CallMonsterPath column / file names; "/move", "/item", "/exp", "/level", "/dil" only inside item/status descriptions ("Move Speed +5%", "Item Drop Rate"); "/warp" only in CVS metadata (share/arrange/cvs: an old Warp.csv); "cheat" only the Shooter skill "impactcheating"; "gmtool" only the exppolicy source GMTOOL; "gm tool" only the title string 100:44 comment "Write GM Tool Notice UI"; "/ban", "/invisible", "/summon" only inside mesh/texture-pack paths and "Knight/Summoner" shop labels; "/notice" a closing </noticectrl> tag; "addexp" the formula key byAddExpPlus / AddExpRate columns / a string comment. Zero hits for gmcmd, gm_cmd, gmcommand, makeitem, createitem, call_monster, summonmonster, /call, /kick, /mute, /invincible, /goto, /recall, /admin, admincommand, setlevel, /money.',
};

/** single-character chat prefixes documented by stringtable_chat.txt cate 230 (help texts) */
const CHAT_PREFIXES = [
  { prefix: '"', chatType: 3, name: 'whisper', syntax: '"<character name> <message>', string: '230:48' },
  { prefix: ';', chatType: 4, name: 'party', syntax: ';<message>', string: '230:50' },
  { prefix: '!', chatType: 1, name: 'shout (map-wide)', syntax: '!<message>', string: '230:52' },
  { prefix: '#', chatType: 7, name: 'guild', syntax: '#<message>', string: '230:55' },
  { prefix: "'", chatType: 7, name: 'guild whisper', syntax: "'<guildsman name> <message>", string: '230:56' },
  { prefix: '&', chatType: 10, name: 'officer', syntax: '&<message>', string: '230:26' },
  { prefix: '$', chatType: 16, name: 'alliance', syntax: '$<message>', string: '230:73' },
  { prefix: '@', chatType: 20, name: 'matching', syntax: '@<message>', string: '230:80' },
  { prefix: '%', chatType: 21, name: 'world', syntax: '%<message>', string: '230:86' },
];

// ================================================================================================
// COMMAND REGISTRY
//   origin: original          = operation + UI/strings are in the client data (GM tool, GM NPC functions, console)
//           original-inferred = capability proven by client data (GM-only monsters/items/statuses, exp policy GMTOOL…);
//                               the original chat spelling is not shipped (server exe absent) -> canonical syntax is ours
//           player / maptool  = the command spelling itself is in the data
//           solo              = tools the original never had (added for the solo GM panel)
//   evidence: [kind, ref] — kinds: file (data key), string ('<file>|cate:code'), item, monster, npc, status, quest,
//             map, privilege, sysvar, formula. All verified by the builder.
// ================================================================================================
const A = (n, t, extra = {}) => ({ n, t, ...extra });
const COMMANDS = [
  // ---------------------------------------------------------------- GM tool (share/server/gradelist.csv privileges)
  { id: 'notice', cat: 'gmtool', origin: 'original', conf: 'high', privilege: 'ALLNOTIFY',
    syntax: '/gm notice <all|map|clear> <text…>', aliases: ['/notice', '/gm announce'],
    args: [A('scope', 'enum', { enum: ['all', 'map', 'clear'], d: 'Send to All / Send to Map / Remove (the three buttons of the GM notice tool)' }), A('text', 'text', { opt: true, max: 511, d: 'notice text, <= 511 chars, up to 6 lines' })],
    desc: 'GM tool notice. The notice window (noticewnd) has a 511-char, 6-line textbox and the buttons Send to All / Send to Map / Remove; players see it in the gmmessage window (yellow ffedfc00 text, 13 lines).',
    solo: 'Show the text in the original gmmessage window (script/ui/game2/gmtool/ui_gmmessagewnd.txt) and the system chat; "map" scopes it to the current map (kept per map); "clear" closes it.',
    evidence: [['file', 'script/ui/game2/gmtool/ui_gmtoolwnd.txt'], ['file', 'script/ui/game2/gmtool/ui_gmmessagewnd.txt'], ['string', 'normal|100:44'], ['string', 'normal|1002:9'], ['string', 'normal|1002:10'], ['string', 'normal|1002:11'], ['privilege', 'ALLNOTIFY']] },
  { id: 'mute', cat: 'gmtool', origin: 'original', conf: 'high', multiplayerOnly: true,
    syntax: '/gm mute <player> <minutes>', aliases: ['/gm restrainchat'],
    args: [A('player', 'player'), A('minutes', 'int', { min: 0, max: 525600, d: 'the edit_time box of the Restrain Chat dialog' })],
    desc: 'Restrain Chat: blocks a character\'s chat until a time. Dialog "Restrain Chat" with a minutes field; the victim sees 700:2 "Chat use has been blocked until <date>".',
    solo: 'Only the player exists: implement as a chat lock on the player (useful to test the message), otherwise hidden.',
    evidence: [['file', 'script/ui/game2/gmtool/ui_shutoffwnd.txt'], ['string', 'normal|80:90'], ['string', 'system|700:2']] },
  { id: 'shutdown', cat: 'gmtool', origin: 'original', conf: 'high', privilege: 'FINISHGAME',
    syntax: '/gm shutdown <minutes>', aliases: ['/gm finishgame'],
    args: [A('minutes', 'int', { min: 0, max: 60, def: 5 })],
    desc: 'Close the server after a countdown; players get 1002:5 "The server closes in %d minute(s)."',
    solo: 'Broadcast the countdown each minute, then save and return to character select.',
    evidence: [['privilege', 'FINISHGAME'], ['string', 'normal|1002:5']] },
  { id: 'exprate', cat: 'gmtool', origin: 'original', conf: 'high', privilege: 'MONSTEREXPRATIO',
    syntax: '/gm exprate <multiplier> [minutes]', aliases: ['/gm expevent'],
    args: [A('multiplier', 'float', { min: 0, max: 1000, def: 2 }), A('minutes', 'int', { opt: true, min: 0, d: '0/absent = until turned off' })],
    desc: 'Monster-EXP event. The client shows 178:1 "EXP x%d EVENT" + 178:4 period + 178:5 disclaimer; share/server/exppolicy.csv lists GMTOOL as an EXP policy source.',
    solo: 'Multiply monster EXP (on top of formula.ini fMonEXPRatio); show the event banner with the period.',
    evidence: [['privilege', 'MONSTEREXPRATIO'], ['string', 'cashitem|178:1'], ['string', 'cashitem|178:4'], ['file', 'share/server/exppolicy.csv'], ['formula', 'fMonEXPRatio']] },
  { id: 'droprate', cat: 'gmtool', origin: 'original', conf: 'high', privilege: 'ITEMDROPRATIO',
    syntax: '/gm droprate <multiplier> [minutes]', aliases: ['/gm dropevent'],
    args: [A('multiplier', 'float', { min: 0, max: 1000, def: 2 }), A('minutes', 'int', { opt: true, min: 0 })],
    desc: 'Item drop-rate event (178:2 "Drop x%d EVENT").', solo: 'Multiply item-set drop ratios (formula fMonItemDropRatio / fItemSetDropRate).',
    evidence: [['privilege', 'ITEMDROPRATIO'], ['string', 'cashitem|178:2'], ['formula', 'fMonItemDropRatio']] },
  { id: 'dilrate', cat: 'gmtool', origin: 'original', conf: 'high', privilege: 'MONEYDROPRATIO',
    syntax: '/gm dilrate <multiplier> [minutes]', aliases: ['/gm moneyevent'],
    args: [A('multiplier', 'float', { min: 0, max: 1000, def: 2 }), A('minutes', 'int', { opt: true, min: 0 })],
    desc: 'DIL drop-rate event (178:3 "DIL Drop x%d EVENT").', solo: 'Multiply dropped DIL (formula fMonMoneyDropRatio / fDILDropRate).',
    evidence: [['privilege', 'MONEYDROPRATIO'], ['string', 'cashitem|178:3'], ['formula', 'fMonMoneyDropRatio']] },
  { id: 'pcroomexp', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'PCROOMEXPRATIO',
    syntax: '/gm pcroomexp <percent>', args: [A('percent', 'int', { min: 0, max: 1000, def: 20 })],
    desc: 'Internet-cafe EXP bonus (1002:4 "Internet Cafe additional EXP: +20%"; share/period.csv IPAMON Exp +10, share/server/periodstrategy.csv Exp +20).',
    solo: 'Toggle / set the PC-cafe EXP bonus for the player.', evidence: [['privilege', 'PCROOMEXPRATIO'], ['string', 'normal|1002:4'], ['file', 'share/server/periodstrategy.csv'], ['file', 'share/period.csv']] },
  { id: 'usercount', cat: 'gmtool', origin: 'original', conf: 'high', privilege: 'TOTALUSERCOUNT',
    syntax: '/gm usercount', args: [], desc: 'Total connected users.', solo: 'Print 1 plus live entity totals (monsters alive/dead, NPCs, drops on the ground).', evidence: [['privilege', 'TOTALUSERCOUNT']] },
  { id: 'mapusercount', cat: 'gmtool', origin: 'original', conf: 'high', privilege: 'MAPUSERCOUNT',
    syntax: '/gm mapusercount [map]', args: [A('map', 'map', { opt: true })], desc: 'Users on a map.', solo: 'Entities on the current (or given loaded) map, per monster index, versus maplist MonsterLimit.',
    evidence: [['privilege', 'MAPUSERCOUNT'], ['string', 'dungeon|3:3041']] },
  { id: 'usermonitor', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'USERMONITOR',
    syntax: '/gm monitor [player]', args: [A('player', 'player', { opt: true })], desc: 'Monitor a user.', solo: 'Live inspector of the player: map, cell, HP/MP, stats, buffs, target, quest states.', evidence: [['privilege', 'USERMONITOR']] },
  { id: 'userlog', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'USERLOG',
    syntax: '/gm userlog [count]', args: [A('count', 'int', { opt: true, def: 50 })], desc: 'Read user logs.', solo: 'Show the session event log (kills, EXP, loot, item use, quest steps, deaths, warps).', evidence: [['privilege', 'USERLOG']] },
  { id: 'changescript', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'CHANGESCRIPT',
    syntax: '/gm reload [all|quests|dungeons|shops|monsters]', aliases: ['/gm changescript'],
    args: [A('what', 'enum', { opt: true, enum: ['all', 'quests', 'dungeons', 'shops', 'monsters'], def: 'all' })],
    desc: 'Reload server scripts.', solo: 'Hot-reload the gamedata JSON (and re-read any user-edited custom data) without restarting.', evidence: [['privilege', 'CHANGESCRIPT']] },
  { id: 'resetmaxcount', cat: 'gmtool', origin: 'original', conf: 'low', privilege: 'RESETMAXCOUNT',
    syntax: '/gm resetcounts', aliases: ['/gm resetmaxcount'], args: [],
    desc: 'Reset max/limit counters.', solo: 'Reset every daily / per-period counter: dungeon entry counts, daily & weekly quests, personal supply machine uses (system variable 62), Colosseum/Dead Front entries, attendance.',
    evidence: [['privilege', 'RESETMAXCOUNT'], ['sysvar', 62]] },
  { id: 'sysvar', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'REGISTRYCHANGE',
    syntax: '/gm sysvar <variable> <value>', aliases: ['/gm registry'],
    args: [A('variable', 'sysvar'), A('value', 'float')],
    desc: 'Change a server tunable of share/system_variable.csv (75 variables: upgrade fees, cast times, supply machine, ego items, …).',
    solo: 'Override the value in the save file; systems read variables through one accessor.', evidence: [['privilege', 'REGISTRYCHANGE'], ['file', 'share/system_variable.csv']] },
  { id: 'formula', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'REGISTRYCHANGE',
    syntax: '/gm formula <key> <value>', args: [A('key', 'formulaKey'), A('value', 'float')],
    desc: 'Change a server formula constant (share/formula.ini, share/formulaex.ini: max level, rates, recovery, PK, party EXP…).',
    solo: 'Override the constant for the session / save.', evidence: [['privilege', 'REGISTRYCHANGE'], ['file', 'share/formula.ini'], ['file', 'share/formulaex.ini']] },
  { id: 'applyall', cat: 'gmtool', origin: 'original', conf: 'low', privilege: 'APPLIEDALLVALUE',
    syntax: '/gm applyall', args: [], desc: 'Apply changed values to all servers.', solo: 'Persist the current rate / variable / formula overrides into the save as the new defaults.', evidence: [['privilege', 'APPLIEDALLVALUE']] },
  { id: 'siege', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'CHANGESIEGE',
    syntax: '/gm siege <open|start|end|reset>', args: [A('state', 'enum', { enum: ['open', 'start', 'end', 'reset'] })],
    desc: 'Change the siege-war state.', solo: 'Siege needs opposing guilds; there are no AI opponents, so only open/close the siege maps and spawn their gates/objects for exploration.',
    evidence: [['privilege', 'CHANGESIEGE'], ['file', 'script/string/siege/stringtable_siege.txt']] },
  { id: 'siegemonitor', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'MONITORSIEGE',
    syntax: '/gm observe [map]', aliases: ['/gm siegemonitor'], args: [A('map', 'map', { opt: true })],
    desc: 'Observe a siege (observer mode; script/ui/game2/observer/*).', solo: 'Detached observer camera on the given map (see freecam).', evidence: [['privilege', 'MONITORSIEGE'], ['file', 'script/ui/game2/observer/ui_observer_areamovewnd.txt']] },
  { id: 'guildwarteleport', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'GUILDWARTELEPORT', multiplayerOnly: true,
    syntax: '/gm guildwarteleport <map>', args: [A('map', 'map')], desc: 'Teleport guilds for a guild war.', solo: 'Not applicable (no guilds); behaves like /gm move for the player.', evidence: [['privilege', 'GUILDWARTELEPORT']] },
  { id: 'partywar', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'CHANGEPARTYWAR',
    syntax: '/gm partywar <content> <open|start|end>', aliases: ['/gm deadfront', '/gm icecastle'],
    args: [A('content', 'content'), A('state', 'enum', { enum: ['open', 'start', 'end'] })],
    desc: 'Change the party-war state (Dead Front / Ice Castle entry windows of script/contents_timetable.csv).',
    solo: 'Open / start / end a Dead Front, Ice Castle, Elonohm, Deadlands or Colosseum session now instead of waiting for its timetable slot (no AI opponents).',
    evidence: [['privilege', 'CHANGEPARTYWAR'], ['file', 'script/contents_timetable.csv'], ['file', 'script/string/party/stringtable_partywar.txt']] },
  { id: 'partywarevent', cat: 'gmtool', origin: 'original', conf: 'medium', privilege: 'PARTYWAREVENT',
    syntax: '/gm partywarevent <content>', args: [A('content', 'content')], desc: 'Start a party-war event.', solo: 'Same as /gm partywar <content> start.', evidence: [['privilege', 'PARTYWAREVENT']] },
  { id: 'ai', cat: 'gmtool', origin: 'original', conf: 'low', privilege: 'AIREGIST',
    syntax: '/gm ai <on|off|reload>', aliases: ['/gm airegist'], args: [A('state', 'enum', { enum: ['on', 'off', 'reload'] })],
    desc: 'Register / reload monster AI.', solo: 'Toggle all monster AI (off = monsters stand idle and never aggro) or re-read the AI tables.', evidence: [['privilege', 'AIREGIST'], ['file', 'share/ai/patterninfo.csv']] },
  // ---------------------------------------------------------------- GM NPC functions (dungeon scripts, GM-only NPCs)
  { id: 'mapbuff', cat: 'gmnpc', origin: 'original', conf: 'high',
    syntax: '/gm mapbuff <buff>', aliases: ['/gm gmbuff'], args: [A('buff', 'gmBuff')],
    desc: 'Operation Assistant (NPC 5825, GM command menu "1. Grant Buff"): one of 10 buffs (EXP +30/50/80/100 %, All Attack +5/10/20 %, All Stats +30/50/100) to every player on the map for 30 minutes; one at a time, a new one overwrites (status group 125).',
    solo: 'Apply the mapped status (gmBuffs[].status) to the player for 30 minutes; it replaces any other group-125 status.',
    evidence: [['npc', 5825], ['file', 'share/dungeon/dungeon_654_oxquiz_dk.csv'], ['string', 'dungeon|654:9559'], ['string', 'dungeon|654:9560'], ['status', 7484], ['status', 7493]] },
  { id: 'oxentry', cat: 'gmnpc', origin: 'original', conf: 'high',
    syntax: '/gm oxentry <open|close>', args: [A('state', 'enum', { enum: ['open', 'close'] })],
    desc: 'Operation Assistant "2. OX Quiz": Entry Allowed / Entry Not Allowed for the OX quiz zone.',
    solo: 'Open / close the OX quiz entrance (map 22 Undo Stadion).', evidence: [['string', 'dungeon|654:9555'], ['string', 'dungeon|654:9553'], ['string', 'dungeon|654:9554']] },
  { id: 'ox', cat: 'gmnpc', origin: 'original', conf: 'high',
    syntax: '/gm ox <wall|unwall|killo|killx|auto|close|end|ask> [question]', aliases: ['/gm oxquiz'],
    args: [A('action', 'enum', { enum: ['wall', 'unwall', 'killo', 'killx', 'auto', 'close', 'end', 'ask'] }), A('question', 'oxQuestion', { opt: true, d: 'for ask' })],
    desc: 'OX quiz controls of the GM-only Start Stone (NPC 5830, map 22): Create wall / Remove wall / Eliminate incorrect responders (O) / (X) / Question set (Auto) / Not allowed enter / Export all (game over). Walls + eliminations are CallMonster groups of callmonster_22_undostadion.csv (monster 8134, rising spikes). Questions: share/event/oxlist.csv.',
    solo: 'Single-player quiz: ask a question (text + O/X zones), after the timer spawn the elimination call group on the wrong side; "end" warps out to Ardeca (string 22:4900).',
    evidence: [['npc', 5830], ['file', 'share/dungeon/dungeon_22_ox_quiz.csv'], ['string', 'dungeon|22:5110'], ['file', 'share/event/oxlist.csv'], ['file', 'share/map/22_undo_stadion/callmonster_22_undostadion.csv'], ['monster', 8134]] },
  { id: 'supply', cat: 'gmnpc', origin: 'original', conf: 'high',
    syntax: '/gm supply <voucher|material> <which>', args: [A('kind', 'enum', { enum: ['voucher', 'material'] }), A('which', 'gmSupply')],
    desc: 'NPC 3350 "Provide Item" (quest 10030 "[Item] Receive", requires the GM accessory 64997): 1000 x one Fortress Voucher rank (Rabble … Doom) or 1000 x one material (Magic Stone Piece, Naruke, Obsidian, Darham).',
    solo: 'Give 1000 of the chosen item (gmSupply list; stacks split by StackNumber).', evidence: [['npc', 3350], ['quest', 10030], ['file', 'share/quest/quest_10030_gm_change.csv'], ['item', 64997]] },
  { id: 'meister', cat: 'gmnpc', origin: 'original', conf: 'medium',
    syntax: '/gm meister <A|B>', args: [A('type', 'enum', { enum: ['A', 'B'] })],
    desc: 'Test quest 1621 "[For the test] Change Job" of Meister Gniar (NPC 5430 on Test Map 38): switch the Meister job type A / B.',
    solo: 'Switch the player\'s Meister (advanced job) type.', evidence: [['quest', 1621], ['npc', 5430], ['map', 38]] },
  // ---------------------------------------------------------------- developer console (script/ui/console)
  { id: 'console', cat: 'console', origin: 'original', conf: 'high',
    syntax: '/gm console', aliases: ['`'], args: [],
    desc: 'Developer console: an output text panel above a single-line command edit (200 chars) — the input for every command in this registry. Errors use 160:60 "This value is invalid." / 160:61 "No such mode exists." / 160:62 "Failed to execute the command."',
    solo: 'Toggle the console (script/ui/console/ui_main.txt layout); route input through the GM command parser.',
    evidence: [['file', 'script/ui/console/ui_main.txt'], ['string', 'normal|160:60'], ['string', 'normal|160:61'], ['string', 'normal|160:62']] },
  { id: 'sysinfo', cat: 'console', origin: 'original', conf: 'high',
    syntax: '/gm sysinfo', args: [], desc: 'SYSTEM INFOMATION window (600x400 text view with refresh).', solo: 'Show engine stats: FPS, draw calls, loaded maps/textures/meshes, memory, entity counts.',
    evidence: [['file', 'script/ui/console/ui_system.txt']] },
  // ---------------------------------------------------------------- capability proven by data, spelling ours
  { id: 'callmonster', cat: 'spawn', origin: 'original-inferred', conf: 'high',
    syntax: '/gm callmonster <monster> [count=1] [x y]', aliases: ['/call', '/callmonster', '/summon', '/monster', '/gm call'],
    args: [A('monster', 'monster'), A('count', 'int', { opt: true, def: 1, min: 1, max: 200 }), A('x', 'cell', { opt: true }), A('y', 'cell', { opt: true })],
    desc: 'Summon monsters next to the GM. Proof: monsters that exist only to be summoned by a GM (8522/8523 Rubisin(GM), 8524 Neo Deux Marble(GM): no spawn or call row anywhere), the server CallMonster mechanism (share/map/*/callmonster_*.csv), maplist MonsterLimit and "Reached Max number of monsters".',
    solo: 'Spawn with full AI, at the player (scatter 1-3 cells) or at x/y; drops and EXP as normal; respects nothing but a sanity cap.',
    evidence: [['monster', 8522], ['monster', 8524], ['file', 'share/map/12_crespo/callmonster_12_crespo.csv'], ['string', 'dungeon|3:3041']] },
  { id: 'callgroup', cat: 'spawn', origin: 'original-inferred', conf: 'high',
    syntax: '/gm callgroup <callGroup>', args: [A('group', 'callGroup')],
    desc: 'Fire one CallIndex group of a map\'s callmonster table (the mechanism dungeon scripts and the OX quiz "eliminate" button use).',
    solo: 'Spawn every row of that CallIndex (count x monster at x/y scattered by cell); random-call tables pick a random position list entry.',
    evidence: [['file', 'share/map/22_undo_stadion/callmonster_22_undostadion.csv']] },
  { id: 'makeitem', cat: 'item', origin: 'original-inferred', conf: 'high',
    syntax: '/gm makeitem <item> [count=1] [upgrade=0] [sockets=0] [option value]…', aliases: ['/item', '/makeitem', '/createitem', '/gm item'],
    args: [A('item', 'item'), A('count', 'int', { opt: true, def: 1, min: 1, max: 9999 }), A('upgrade', 'int', { opt: true, def: 0, min: 0, max: 15, d: 'upgrade level (+N); caps in share/item/itemupgrade.csv' }),
      A('sockets', 'int', { opt: true, def: 0, min: 0, max: 4 }), A('options', 'itemOption', { opt: true, repeat: 6, d: 'up to 6 option index + value pairs' })],
    desc: 'Create an item. Proof: GM-only items (GM weapons 63040-63063, GM accessories 64988-64999, GM costumes, GM gift boxes / packages) and the Provide Item NPC.',
    solo: 'Put the item in the inventory (or at the feet if full) with the chosen upgrade, sockets and options.',
    evidence: [['item', 63041], ['item', 64988], ['item', 1757142], ['npc', 3350]] },
  { id: 'move', cat: 'teleport', origin: 'original-inferred', conf: 'high',
    syntax: '/gm move <map> [x y]', aliases: ['/move', '/warp', '/teleport', '/tp', '/gm warp'],
    args: [A('map', 'map'), A('x', 'cell', { opt: true }), A('y', 'cell', { opt: true })],
    desc: 'Teleport. Proof: share/arrange/location.csv (1055 named teleport points used by warp NPCs / scrolls), maplist return points, teleport results 101:161 / 101:171.',
    solo: 'Load the map, place the player at x/y or at maps[].landing (snap to the nearest walkable cell).',
    evidence: [['file', 'share/arrange/location.csv'], ['string', 'system|101:161']] },
  { id: 'goloc', cat: 'teleport', origin: 'original-inferred', conf: 'high',
    syntax: '/gm goloc <location>', aliases: ['/gm location'], args: [A('location', 'location')],
    desc: 'Teleport to a named location of share/arrange/location.csv (what warp NPCs and return scrolls use).', solo: 'As move, using the location\'s map/x/y/direction.',
    evidence: [['file', 'share/arrange/location.csv']] },
  { id: 'gotonpc', cat: 'teleport', origin: 'original-inferred', conf: 'high',
    syntax: '/gm gotonpc <npc>', aliases: ['/gm npcwarp'], args: [A('npc', 'npc')],
    desc: 'NPC Warp (premium feature: share/item/premiereitem.csv NpcWarp; 101:171 "You have suceeded to teleport [NPC_NAME]\'s location").',
    solo: 'Teleport next to the first placement of the NPC.', evidence: [['string', 'system|101:171'], ['file', 'share/item/premiereitem.csv']] },
  { id: 'level', cat: 'character', origin: 'original-inferred', conf: 'high',
    syntax: '/gm level <level>', aliases: ['/level', '/gm lv'], args: [A('level', 'int', { min: 1, max: 250 })],
    desc: 'Set the level (formula.ini wMaxLevel = 250; the level-change item text 1002:56).', solo: 'Set level, recompute stat points (byStatPointPerLevel) and HP/MP.',
    evidence: [['formula', 'wMaxLevel'], ['string', 'normal|1002:56']] },
  { id: 'exp', cat: 'character', origin: 'original-inferred', conf: 'high',
    syntax: '/gm exp <amount>', args: [A('amount', 'int', { min: 0 })],
    desc: 'Grant EXP (share/server/exppolicy.csv lists "GMTOOL" as an EXP source).', solo: 'Add EXP through the normal level-up path (level-up boxes, skill points).', evidence: [['file', 'share/server/exppolicy.csv']] },
  { id: 'dil', cat: 'character', origin: 'original-inferred', conf: 'medium',
    syntax: '/gm dil <amount>', aliases: ['/dil', '/gm money'], args: [A('amount', 'int')], desc: 'Give / take DIL.', solo: 'Add (negative = remove) DIL.', evidence: [['formula', 'fDILDropRate']] },
  { id: 'buff', cat: 'character', origin: 'original-inferred', conf: 'high',
    syntax: '/gm buff <status> [minutes]', args: [A('status', 'status'), A('minutes', 'int', { opt: true, def: 30 })],
    desc: 'Apply any status of share/skill/status.csv (the GM buff menu proves GMs grant statuses).', solo: 'Apply the status with its options; group / MaxStackCount rules as normal.',
    evidence: [['file', 'share/skill/status.csv'], ['status', 7484]] },
  { id: 'god', cat: 'character', origin: 'original-inferred', conf: 'medium',
    syntax: '/gm god [on|off]', aliases: ['/gm invincible'], args: [A('state', 'enum', { opt: true, enum: ['on', 'off'] })],
    desc: 'Invincible mode (pc 40:126 "You cannot attack a character in the Invincible mode."; invincible status icons).', solo: 'No damage taken, no death.', evidence: [['string', 'normal|40:126']] },
  { id: 'hide', cat: 'character', origin: 'original-inferred', conf: 'low',
    syntax: '/gm hide [on|off]', aliases: ['/gm invisible'], args: [A('state', 'enum', { opt: true, enum: ['on', 'off'] })],
    desc: 'GM invisibility (the name filters reserve "GM"/"[GM]" names; Invisible Shadow statuses show the effect exists).', solo: 'Monsters ignore the player (no aggro, no targeting).', evidence: [['file', 'script/filter/namefilter.txt']] },
  { id: 'skill', cat: 'character', origin: 'original-inferred', conf: 'medium',
    syntax: '/gm skill <skill> [level]', args: [A('skill', 'skill'), A('level', 'int', { opt: true, d: 'default = max level' })],
    desc: 'Learn / set a skill level.', solo: 'Set the skill level ignoring requirements.', evidence: [['file', 'script/skilldesc/knight.csv']] },
  { id: 'skillreset', cat: 'character', origin: 'original-inferred', conf: 'medium',
    syntax: '/gm skillreset', args: [], desc: 'Skill reset (NPC job SKILLCLEAR 7, Reset Gems 101:22).', solo: 'Refund all skill points.', evidence: [['string', 'system|101:22']] },
  { id: 'statreset', cat: 'character', origin: 'original-inferred', conf: 'medium',
    syntax: '/gm statreset', args: [], desc: 'Stat reset (NPC job STATCLEAR 13).', solo: 'Refund all stat points.', evidence: [['npc', 101]] },
  { id: 'quest', cat: 'quest', origin: 'original-inferred', conf: 'medium',
    syntax: '/gm quest <start|complete|reset|abandon> <quest>', args: [A('action', 'enum', { enum: ['start', 'complete', 'reset', 'abandon'] }), A('quest', 'quest')],
    desc: 'Force a quest state (test quests such as 1621 "[For the test] Change Job" show GMs driving quest scripts).', solo: 'Set the quest state; complete grants its rewards.', evidence: [['quest', 1621]] },
  { id: 'speed', cat: 'character', origin: 'original-inferred', conf: 'medium',
    syntax: '/gm speed <factor>', args: [A('factor', 'float', { min: 0.1, max: 10, def: 1 })],
    desc: 'Movement speed (GM test accessories "Move SPD 1..3 (Test)" 64994-64996, "ATT SPD 1..3 (Test)" 64991-64993; maplist MoveSpeedFactor).', solo: 'Scale the player\'s run/walk speed.',
    evidence: [['item', 64994], ['item', 64991]] },
  // ---------------------------------------------------------------- player commands whose spelling is in the data
  { id: 'emote', cat: 'player', origin: 'player', conf: 'high',
    syntax: '/<emote>', aliases: [], args: [A('emote', 'emote')],
    desc: 'Emote slash commands (EU: stringtable_emoticon cate 51 + script/lua/motion_macro.csv; Korean: motion_macro.lua).',
    solo: 'Play the character MOTION action of the emote (motiontype 1 = sit, 2 = stand, 0 = one-shot; costume = motion 100).',
    evidence: [['file', 'script/lua/motion_macro.csv'], ['file', 'script/lua/motion_macro.lua'], ['string', 'normal|51:1']] },
  { id: 'chat', cat: 'player', origin: 'player', conf: 'high',
    syntax: '<prefix><message>  |  /<chattype> <message>', args: [A('chatType', 'chatType'), A('message', 'text')],
    desc: 'Chat channel prefixes (" whisper, ; party, ! shout, # guild, \' guild whisper, & officer, $ alliance, @ matching, % world) and the chat-type slash shortcuts of chattype_macro.lua.',
    solo: 'All channels echo locally; whisper/party/guild have no recipient.', evidence: [['file', 'script/lua/chattype_macro.lua'], ['string', 'normal|230:50']] },
  // ---------------------------------------------------------------- the original map tool console (script/ui/maptool)
  { id: 'maptool', cat: 'maptool', origin: 'maptool', conf: 'high',
    syntax: '<maptool command> …', args: [A('command', 'mapToolCommand'), A('args', 'text', { opt: true })],
    desc: 'The original map editor\'s console commands (create_map, load_*, save_*, maptexturepath) — see original.mapTool.',
    solo: 'Map-builder phase: same verbs over the custom-map store.', evidence: [['file', 'script/ui/maptool/ui_maptoolcommand.txt'], ['file', 'script/string/tool/mapbuilder.txt']] },
  // ---------------------------------------------------------------- solo extras (the original lacked these)
  { id: 'tpclick', cat: 'teleport', origin: 'solo', syntax: '/gm tpclick [on|off]', args: [A('state', 'enum', { opt: true, enum: ['on', 'off'] })], desc: 'Ctrl+click on the ground teleports the player there.' },
  { id: 'setstat', cat: 'character', origin: 'solo', syntax: '/gm setstat <str|dex|con|spr|points> <value>', args: [A('stat', 'enum', { enum: ['str', 'dex', 'con', 'spr', 'points'] }), A('value', 'int', { min: 0 })], desc: 'Set a base stat or the free stat points.' },
  { id: 'setclass', cat: 'character', origin: 'solo', syntax: '/gm setclass <class>', args: [A('class', 'class')], desc: 'Switch the character to another class (re-skin, re-skill).' },
  { id: 'heal', cat: 'character', origin: 'solo', syntax: '/gm heal', args: [], desc: 'Full HP/MP, clear debuffs.' },
  { id: 'revive', cat: 'character', origin: 'solo', syntax: '/gm revive', args: [], desc: 'Revive in place without EXP loss.' },
  { id: 'cooldowns', cat: 'character', origin: 'solo', syntax: '/gm cooldowns [off]', args: [A('mode', 'enum', { opt: true, enum: ['reset', 'off', 'on'] })], desc: 'Reset all skill/item cooldowns now; "off" disables cooldowns.' },
  { id: 'infinitemp', cat: 'character', origin: 'solo', syntax: '/gm infmp [on|off]', args: [A('state', 'enum', { opt: true, enum: ['on', 'off'] })], desc: 'Skills cost no MP/HP.' },
  { id: 'onehit', cat: 'character', origin: 'solo', syntax: '/gm onehit [on|off]', args: [A('state', 'enum', { opt: true, enum: ['on', 'off'] })], desc: 'Every hit kills.' },
  { id: 'noclip', cat: 'character', origin: 'solo', syntax: '/gm noclip [on|off]', args: [A('state', 'enum', { opt: true, enum: ['on', 'off'] })], desc: 'Ignore .mac collision / blocked cells.' },
  { id: 'freecam', cat: 'view', origin: 'solo', syntax: '/gm freecam [on|off]', args: [A('state', 'enum', { opt: true, enum: ['on', 'off'] })], desc: 'Detached fly camera (WASD + mouse), game keeps running.' },
  { id: 'time', cat: 'world', origin: 'solo', syntax: '/gm time <0-24|freeze|resume>', args: [A('hour', 'text')], desc: 'Set the time of day of the day/night cycle (maplist OnedayTime) or freeze it.' },
  { id: 'sky', cat: 'world', origin: 'solo', syntax: '/gm sky <sky>', aliases: ['/gm weather'], args: [A('sky', 'sky')], desc: 'Force a sky/weather preset of script/environment/sky_table.txt (dawn, noon, night, Dead Front, pilgrimage, Deadlands …).' },
  { id: 'spawnnpc', cat: 'spawn', origin: 'solo', syntax: '/gm spawnnpc <npc> [x y dir]', args: [A('npc', 'npc'), A('x', 'cell', { opt: true }), A('y', 'cell', { opt: true }), A('dir', 'int', { opt: true })], desc: 'Place a (functional) NPC next to the player — shop, storage, quest giver, GM NPCs 5825/5830/3350.' },
  { id: 'killall', cat: 'spawn', origin: 'solo', syntax: '/gm killall [radius] [drops]', args: [A('radius', 'float', { opt: true, d: 'cells; absent = whole map' }), A('drops', 'bool', { opt: true, def: true })], desc: 'Kill every monster in range (with or without loot/EXP).' },
  { id: 'respawn', cat: 'spawn', origin: 'solo', syntax: '/gm respawn', args: [], desc: 'Respawn every MON_ spawn row of the current map immediately.' },
  { id: 'freeze', cat: 'spawn', origin: 'solo', syntax: '/gm freeze [on|off]', args: [A('state', 'enum', { opt: true, enum: ['on', 'off'] })], desc: 'Freeze all monsters in place (animation + AI).' },
  { id: 'droptable', cat: 'info', origin: 'solo', syntax: '/gm droptable <monster|item>', args: [A('target', 'monsterOrItem')], desc: 'Drop-table viewer: what a monster drops (per-item chance, money) or which monsters drop an item.' },
  { id: 'simdrops', cat: 'info', origin: 'solo', syntax: '/gm simdrops <monster> <kills>', args: [A('monster', 'monster'), A('kills', 'int', { min: 1, max: 100000, def: 1000 })], desc: 'Roll the monster\'s drop table N times and show the totals.' },
  { id: 'queststate', cat: 'quest', origin: 'solo', syntax: '/gm queststate [quest]', args: [A('quest', 'quest', { opt: true })], desc: 'Quest state editor: list / edit every quest state, step and kill counter.' },
  { id: 'dkc', cat: 'item', origin: 'solo', syntax: '/gm dkc <amount|unlimited>', aliases: ['/gm dshopcoins'], args: [A('amount', 'text')], desc: 'D-Shop coin (DKC) editor; "unlimited" is accepted.' },
  { id: 'clearinv', cat: 'item', origin: 'solo', syntax: '/gm clearinv [bag]', args: [A('bag', 'int', { opt: true })], desc: 'Empty the inventory (or one bag).' },
  { id: 'repairall', cat: 'item', origin: 'solo', syntax: '/gm repairall', args: [], desc: 'Repair every equipped / carried item.' },
  { id: 'itemedit', cat: 'item', origin: 'solo', syntax: '/gm itemedit', args: [], desc: 'Edit the hovered / equipped item in place: upgrade, sockets, options (item generator with full dropdowns).' },
  { id: 'dropitem', cat: 'item', origin: 'solo', syntax: '/gm dropitem <item> [count]', args: [A('item', 'item'), A('count', 'int', { opt: true, def: 1 })], desc: 'Drop the item on the ground at the player (tests pickup / loot UI).' },
  { id: 'allskills', cat: 'character', origin: 'solo', syntax: '/gm allskills', args: [], desc: 'Learn every skill of the class at max level.' },
  { id: 'unlockmaps', cat: 'teleport', origin: 'solo', syntax: '/gm unlockmaps', args: [], desc: 'Ignore map level limits (maplist LimitMinLevel/LimitMaxLevel) and entry items/tickets.' },
  { id: 'showdebug', cat: 'view', origin: 'solo', syntax: '/gm show <collision|nav|spawns|npcs|grid|bounds|none>', args: [A('layer', 'enum', { enum: ['collision', 'nav', 'spawns', 'npcs', 'grid', 'bounds', 'none'] })], desc: 'Debug overlays: .mac collision, A* nav, MON_ spawn points, NPC placements, cell grid, bounding boxes.' },
  { id: 'timescale', cat: 'world', origin: 'solo', syntax: '/gm timescale <factor>', args: [A('factor', 'float', { min: 0.05, max: 10, def: 1 })], desc: 'Slow motion / fast forward.' },
  { id: 'inspect', cat: 'info', origin: 'solo', syntax: '/gm inspect', args: [], desc: 'Entity inspector for the current target (index, stats, AI state, action set, clip).' },
  { id: 'hideui', cat: 'view', origin: 'solo', syntax: '/gm hideui', args: [], desc: 'Screenshot mode (hide every window).' },
  { id: 'snapshot', cat: 'info', origin: 'solo', syntax: '/gm snapshot <save|load> <name>', args: [A('action', 'enum', { enum: ['save', 'load'] }), A('name', 'text')], desc: 'Save / restore the whole character + world state.' },
  { id: 'mapevent', cat: 'world', origin: 'solo', syntax: '/gm mapevent <map> <code>', args: [A('map', 'map'), A('code', 'int')], desc: 'Fire a scripted map/dungeon notice or event (field bosses, invasions, dungeon string codes of the DUNGEON string group).' },
  { id: 'fps', cat: 'view', origin: 'solo', syntax: '/gm fps', args: [], desc: 'Performance overlay.' },
  { id: 'effect', cat: 'view', origin: 'solo', syntax: '/gm effect <effectScene> [sceneId] [self|target|ground]', aliases: ['/gm fx'],
    args: [A('effect', 'effectScene'), A('sceneId', 'int', { opt: true, d: 'scene of the effect (effects[].scenes); default = first' }), A('on', 'enum', { opt: true, enum: ['self', 'target', 'ground'], def: 'self' })],
    desc: 'Play any effect scene of property/effect/effectscene.*.txt (monster, skill, hit, item, UI, weather, condition, event, map, sound scenes) on the player, the target or the ground. In-game stand-in for the original developers\' Effect Tool (script/ui/effecttool: Particle / Mesh / Decal / Effect editors, see original.devTools).',
    evidence: [['file', 'script/ui/effecttool/ui_effecttool_toolbar.txt'], ['file', 'property/effect/effectscene.01.txt']] },
  { id: 'enterdungeon', cat: 'teleport', origin: 'solo', syntax: '/gm dungeon <dungeon> [floor]', aliases: ['/gm enterdungeon'],
    args: [A('dungeon', 'dungeon'), A('floor', 'int', { opt: true, def: 0, d: 'index into dungeons[].maps' })],
    desc: 'Create and enter a dungeon instance directly, skipping the entry NPC, party size (RequestMember), level range, ticket and daily entry count of share/dungeonlist.csv. Unlike /gm move, the instance timer, keeper and kick-out rules run as normal.',
    evidence: [['file', 'share/dungeonlist.csv']] },
  { id: 'bgm', cat: 'world', origin: 'solo', syntax: '/gm bgm <map|off>', aliases: ['/gm music'], args: [A('map', 'map', { d: 'plays that map\'s BGM (gamedata/sound.json bgmByMapIndex); "off" stops music' })],
    desc: 'Music browser: play the background music of any map without going there.', evidence: [['file', 'share/maplist.csv']] },
];

// argument types -> dropdown list ids (lists are defined in gmcommands.json `lists`)
const ARG_TYPES = {
  monster: { list: 'monsters', search: ['name', 'index'], show: ['level', 'hp', 'rank', 'maps', 'drops'] },
  item: { list: 'items', search: ['name', 'index'], show: ['table', 'rank', 'reqLv', 'type', 'code'], preview: 'gamedata/boxes.json#boxes (contents of box / package items, keyed by item index; tools/build-boxes.mjs)' },
  itemOption: { list: 'itemOptions', search: ['desc', 'type', 'index'], show: ['min', 'max'], pair: 'int' },
  map: { list: 'maps', search: ['name', 'index', 'file'], show: ['level', 'type'] },
  location: { list: 'locations', search: ['name', 'index'], show: ['map'] },
  dungeon: { list: 'dungeons', search: ['name', 'index'] },
  npc: { list: 'npcs', search: ['name', 'index', 'roles'], show: ['maps'] },
  skill: { list: 'skills', search: ['name', 'index', 'class'], show: ['maxLevel', 'weapon'] },
  quest: { list: 'quests', search: ['title', 'index'], show: ['level', 'type'] },
  status: { list: 'statuses', search: ['desc', 'index'], show: ['group', 'options'] },
  class: { list: 'classes', search: ['name', 'code'] },
  emote: { list: 'emotes', search: ['name', 'slash'] },
  chatType: { list: 'chatTypes', search: ['name', 'prefix'] },
  gmBuff: { list: 'gmBuffs', search: ['label'] },
  gmSupply: { list: 'gmSupply', search: ['label'] },
  oxQuestion: { list: 'oxQuestions', search: ['question'] },
  sysvar: { list: 'systemVariables', search: ['desc', 'index'], show: ['value'] },
  formulaKey: { list: 'formula', search: ['key'], show: ['value'] },
  callGroup: { list: 'callGroups', search: ['file', 'maps'], show: ['monsters'] },
  content: { list: 'contents', search: ['name', 'map'] },
  sky: { list: 'skies', search: ['desc'] },
  mapToolCommand: { list: 'mapToolCommands', search: ['name'] },
  effectScene: { list: 'effects', search: ['name', 'key'], show: ['category', 'scenes'] },
  monsterOrItem: { list: ['monsters', 'items'] },
  int: {}, float: {}, text: {}, bool: {}, enum: {}, player: { note: 'solo: always the player' }, cell: { note: 'map cell coordinate (file frame: x = column, y = row); float allowed' },
};

// ================================================================================================
// main
// ================================================================================================
function main() {
  const t0 = Date.now();
  if (!fs.existsSync(DATA)) { console.error(`data root not found: ${DATA}`); process.exit(2); }
  log(`data: ${DATA}\nout:  ${OUT}`);

  // ---------------------------------------------------------------- lines_eu
  let LE = null;
  if (exists('script/lines_eu')) {
    LE = parseLinesEu(readKey('script/lines_eu'));
    if (LE.trailingBytes) hard(`lines_eu: ${LE.trailingBytes} trailing bytes`);
    log(`lines_eu: ${LE.strings.size} strings, ${LE.txt.size} txt keys, ${LE.csv.size} csv keys`);
  } else soft('script/lines_eu missing: EU names fall back to the csv name columns');
  const leCsv = (key) => { if (!LE) return null; const id = LE.csv.get(key.toLowerCase()); return id != null ? LE.strings.get(id) ?? null : null; };
  const leTxt = (file, cate, code) => { if (!LE) return null; const id = LE.txt.get(`${file.toLowerCase()}#${cate}|${code}`); return id != null ? LE.strings.get(id) ?? null : null; };

  // ---------------------------------------------------------------- string tables by list.txt group
  const groups = {};   // group -> [{key, table}]
  {
    const listKey = 'script/string/list.txt';
    if (!exists(listKey)) hard('script/string/list.txt missing');
    for (const raw of decodeText(readKey(listKey)).split(/\r\n|\n|\r/)) {
      const m = /^\s*([A-Z_0-9]+)\s*,\s*(\S+\.txt)/i.exec(raw); if (!m) continue;
      const key = ('script/' + m[2].replace(/\\/g, '/')).toLowerCase();
      if (!exists(key)) { soft(`string list names a missing file ${key}`); continue; }
      (groups[m[1].toUpperCase()] ||= []).push({ key, table: parseStringTable(decodeText(readKey(key))) });
    }
  }
  const GROUP_ALIASES = { normal: ['NORMAL', 'COMMON'], system: ['SYSTEM'], dungeon: ['DUNGEON'], quest: ['QUEST'], cashitem: ['NORMAL'], teleport: ['TELEPORT'] };
  /** S('normal', cate, code) -> {text, file} (string tables first, then lines_eu txt keys of the same files) */
  const S = (group, cate, code) => {
    const gs = GROUP_ALIASES[group] || [group.toUpperCase()];
    for (const g of gs) for (const f of groups[g] || []) { const t = f.table.get(`${cate}:${code}`); if (t !== undefined) return { text: t, file: f.key }; }
    for (const g of gs) for (const f of groups[g] || []) { const t = leTxt(path.posix.basename(f.key), cate, code); if (t != null) return { text: t, file: f.key, from: 'lines_eu' }; }
    return null;
  };
  const St = (group, cate, code) => S(group, cate, code)?.text ?? null;
  log(`string groups: ${Object.entries(groups).map(([g, a]) => `${g}:${a.length}`).join(' ')}`);

  // ---------------------------------------------------------------- items: share/item/item.dat + itemevent.dat (compiled, authoritative)
  // 565-byte records. The csv tables are an OLDER snapshot (20k items of the .dat are missing from them and their row
  // order no longer matches lines_eu), exactly like monster.dat vs monster.csv. Field offsets were derived by scanning
  // every offset against the csv columns of the 74k items present in both (docs/formats/gmcommands.md §3.1).
  const ITEM_TABLES = [
    ['share/item/itemweapon.csv', 'weapon'], ['share/item/itemarmor.csv', 'armor'], ['share/item/itemaccessory.csv', 'accessory'], ['share/item/itemetc.csv', 'etc'],
    ['share/item/itemetc_socket.csv', 'socket'], ['share/item/itemcash.csv', 'cash'], ['share/item/itemmileage.csv', 'mileage'],
    ['share/item/itemevent/accessoryevent.csv', 'accessoryEvent'], ['share/item/itemevent/cashevent.csv', 'cashEvent'], ['share/item/itemevent/etcevent.csv', 'etcEvent'],
  ];
  const ITEM_FIELDS = ['index', 'name', 'table', 'rank', 'type', 'code', 'reqLv', 'job', 'stack', 'price', 'quality', 'trade'];
  const items = [], itemByIndex = new Map(), itemTables = ITEM_TABLES.map(([key, id]) => ({ id, src: exists(key) ? K(key) : null, dat: 0, csvOnly: 0 }));
  const tableOfFile = new Map(ITEM_TABLES.map(([key], i) => [path.posix.basename(key), i]));
  // csv rows by index (for job mask / stack, and the names of the 197 csv-only items)
  const csvItem = new Map();
  for (const [key] of ITEM_TABLES) {
    if (!exists(key)) { hard(`item table missing ${key}`); continue; }
    const rows = readCsvLines(key); const hdr = rows[0];
    const ci = { index: headerIndex(hdr, 'itemindex', 'item index', 'index'), name: headerIndex(hdr, 'name'), rank: headerIndex(hdr, 'rank'), type: headerIndex(hdr, 'type'), code: headerIndex(hdr, 'code'),
      reqLv: headerIndex(hdr, 'reqlv'), job: headerIndex(hdr, 'job'), stack: headerIndex(hdr, 'stacknumber'), price: headerIndex(hdr, 'price'), quality: headerIndex(hdr, 'quality'), trade: headerIndex(hdr, 'trade') };
    for (const k of ['index', 'name', 'type', 'code', 'job']) if (ci[k] < 0) hard(`${key}: column ${k} not found`);
    for (let r = 1; r < rows.length; r++) { const row = rows[r]; if (row.length && /^\d+$/.test(row[ci.index] ?? '') && !csvItem.has(+row[ci.index])) csvItem.set(+row[ci.index], { key, row, ci }); }
  }
  const ITEM_DAT_RECORD = 565;
  const datStats = { records: 0, named: 0, nameFromCsv: 0, unnamed: 0, duplicate: 0 };
  for (const key of ['share/item/item.dat', 'share/item/itemevent/itemevent.dat']) {
    if (!exists(key)) { hard(`missing ${key}`); continue; }
    const b = readKey(K(key)); if (b.length % ITEM_DAT_RECORD) hard(`${key}: size ${b.length} not a multiple of ${ITEM_DAT_RECORD}`);
    const dv = new DataView(b.buffer, b.byteOffset, b.byteLength);
    for (let o = 0; o + ITEM_DAT_RECORD <= b.length; o += ITEM_DAT_RECORD) {
      datStats.records++;
      let e = o + 204; while (e < o + 460 && !(b[e] === 0 && b[e + 1] === 0)) e += 2;
      const nameKey = utf16.decode(b.subarray(o + 204, e));
      const index = dv.getUint32(o + 128, true);
      const file = (nameKey.split('#')[1] || '').toLowerCase(); const tIdx = tableOfFile.get(file) ?? -1;
      if (tIdx < 0) soft(`item.dat ${index}: name key of unknown table "${nameKey}"`);
      const c = csvItem.get(index);
      let name = leCsv(nameKey); name = name && name.trim();
      const csvName = c ? c.row[c.ci.name] ?? '' : '';
      if (name) datStats.named++; else if (csvName) { name = csvName; datStats.nameFromCsv++; } else { name = `item ${index}`; datStats.unnamed++; }
      const it = [index, name, tIdx, dv.getUint32(o + 137, true), dv.getUint32(o + 141, true), b[o + 145], dv.getUint16(o + 190, true),
        c ? c.row[c.ci.job] ?? '' : '', c && c.ci.stack >= 0 ? num(c.row[c.ci.stack]) : null, dv.getUint32(o + 194, true), dv.getUint32(o + 155, true), dv.getUint32(o + 186, true)];
      if (hasHangul(csvName) && csvName !== name) it.push(csvName);
      if (itemByIndex.has(index)) { datStats.duplicate++; continue; }
      itemByIndex.set(index, it); items.push(it); if (tIdx >= 0) itemTables[tIdx].dat++;
    }
  }
  for (const [index, c] of csvItem) {   // in the csv but not in the compiled tables (not loadable by the client)
    if (itemByIndex.has(index)) continue;
    const r = c.row, ci = c.ci; const tIdx = ITEM_TABLES.findIndex(([k]) => k === c.key);
    const it = [index, r[ci.name] ?? '', tIdx, num(r[ci.rank]), num(r[ci.type]), num(r[ci.code]), num(r[ci.reqLv]), r[ci.job] ?? '', num(r[ci.stack]), num(r[ci.price]), num(r[ci.quality]), num(r[ci.trade]), null, 1];
    itemByIndex.set(index, it); items.push(it); itemTables[tIdx].csvOnly++;
  }
  items.sort((a, b) => a[0] - b[0]);
  const itemName = (i) => itemByIndex.get(i)?.[1] ?? null;
  // csv/dat agreement on the fields read from the .dat (reported; the offsets are the best-matching ones)
  const agree = { type: [0, 0], code: [0, 0], reqLv: [0, 0], quality: [0, 0], rank: [0, 0], price: [0, 0] };
  for (const it of items) { const c = csvItem.get(it[0]); if (!c || it[13]) continue; const r = c.row, ci = c.ci;
    for (const [k, j] of [['rank', 3], ['type', 4], ['code', 5], ['reqLv', 6], ['price', 9], ['quality', 10]]) { if (ci[k] < 0) continue; agree[k][1]++; if (num(r[ci[k]]) === it[j]) agree[k][0]++; } }
  log(`items: ${items.length} from item.dat+itemevent.dat ${datStats.records} records (${datStats.named} EU-named via name key, ${datStats.nameFromCsv} csv-named, ${datStats.unnamed} unnamed, ${datStats.duplicate} dup) + ${items.filter((i) => i[13]).length} csv-only`);
  log(`  dat vs csv field agreement: ${Object.entries(agree).map(([k, [a, n]]) => `${k} ${a}/${n}`).join(', ')}`);
  if (agree.type[1] && agree.type[0] / agree.type[1] < 0.98) hard(`item.dat type offset disagrees with csv: ${agree.type.join('/')}`);
  if (agree.reqLv[1] && agree.reqLv[0] / agree.reqLv[1] < 0.98) hard(`item.dat reqLv offset disagrees with csv: ${agree.reqLv.join('/')}`);
  const nameCheck = { datRecords: datStats.records, euNamed: datStats.named, csvNamed: datStats.nameFromCsv, unnamed: datStats.unnamed, duplicates: datStats.duplicate, csvOnly: items.filter((i) => i[13]).length, fieldAgreement: agree };
  const dupItems = datStats.duplicate;

  const itemOptions = [];
  for (const [key, src] of [['share/item/itemoption_weapon.csv', 'weapon'], ['share/item/itemoption_armor.csv', 'armor'], ['share/item/itemoption_accessory.csv', 'accessory']]) {
    if (!exists(key)) { soft(`missing ${key}`); continue; }
    const rows = readCsvLines(key);
    for (let r = 2; r < rows.length; r++) {   // row 0 Korean header, row 1 English header
      const x = rows[r]; if (!x.length || !/^\d+$/.test(x[1] ?? '')) continue;
      itemOptions.push([+x[1], num(x[0]), x[2] ?? '', x[3] ?? '', num(x[4]), num(x[5]), num(x[6]), src]);
    }
    K(key);
  }
  const sockets = [];
  if (exists('share/item/itemsocket.csv')) {
    const rows = readCsvLines('share/item/itemsocket.csv');
    for (let r = 2; r < rows.length; r++) { const x = rows[r]; if (x.length && /^\d+$/.test(x[0] ?? '')) sockets.push([+x[0], x[1] ?? '', itemName(+x[0])]); }
    K('share/item/itemsocket.csv');
  }
  let upgradeMax = 0; const upgradeByCode = {};
  if (exists('share/item/itemupgrade.csv')) {
    const rows = readCsvLines('share/item/itemupgrade.csv');
    for (let r = 1; r < rows.length; r++) { const x = rows[r]; if (x.length < 3 || !/^\d+$/.test(x[2])) continue; const k = `${x[0]}/${x[1]}`; upgradeByCode[k] = Math.max(upgradeByCode[k] ?? 0, +x[2]); upgradeMax = Math.max(upgradeMax, +x[2]); }
    K('share/item/itemupgrade.csv');
  }

  // ---------------------------------------------------------------- joins with the other builders' outputs
  const loadGamedata = (f) => { const p = path.join(GAMEDATA, f); if (!fs.existsSync(p)) { soft(`gamedata/${f} not found (run its builder first); related joins are empty`); return null; } return JSON.parse(fs.readFileSync(p, 'utf8')); };
  const MON = loadGamedata('monsters.json');
  const NPC = loadGamedata('npcs.json');
  const CLS = loadGamedata('classes.json');

  // ---------------------------------------------------------------- maps
  const maps = []; const mapByIndex = new Map();
  {
    const key = 'share/maplist.csv'; const rows = readCsvLines(key); const h = rows[0]; K(key);
    const c = (n) => headerIndex(h, n);
    const col = {
      index: c('Index'), name: c('Name'), file: c('MapFile'), type: c('Map_Type'), pvp: c('IsPvP'), siege: c('IsSiege'), peace: c('PeaceZone'), portal: c('IsPortal'),
      ret: c('IsReturnScroll'), dungeon: c('DungeonIndex'), minLv: c('LimitMinLevel'), maxLv: c('LimitMaxLevel'), monLimit: c('MonsterLimit'), day: c('OnedayTime(Min)'),
      env: c('EnvironmentFile'), speed: c('MoveSpeedFactor'), respawn: c('MonsterRespawnFactor'), retMap: c('RetMapIndex'), retX: c('RetX'), retY: c('RetY'),
      script: c('ScriptName'), vehicle: c('IsVehicle'), pet: c('IsPet'), callPath: c('CallMonsterPath'),
    };
    for (const [k, v] of Object.entries(col)) if (v < 0) hard(`maplist.csv: column ${k} not found`);
    for (let r = 1; r < rows.length; r++) {
      const x = rows[r]; if (!x.length || !/^\d+$/.test(x[col.index] ?? '')) continue;
      const index = +x[col.index]; const csvName = x[col.name] ?? ''; const eu = leCsv(`share#maplist.csv#1|${r}`);
      const file = (x[col.file] || '').toLowerCase(); const fileKey = /\.map$/.test(file) ? `map/${file}` : null;   // "<< emtpy >>" rows have no map
      const m = { index, name: (eu && eu.trim()) || csvName, file: fileKey && exists(fileKey) ? K(fileKey) : null,
        type: num(x[col.type]), pvp: num(x[col.pvp]), siege: num(x[col.siege]), peace: num(x[col.peace]), portal: num(x[col.portal]), returnScroll: num(x[col.ret]),
        dungeon: num(x[col.dungeon]), level: [num(x[col.minLv]), num(x[col.maxLv])], monsterLimit: num(x[col.monLimit]), dayMinutes: num(x[col.day]),
        env: x[col.env] || null, speed: num(x[col.speed], 1), respawn: num(x[col.respawn], 100), ret: [num(x[col.retMap]), num(x[col.retX]), num(x[col.retY])],
        script: x[col.script] || null, vehicle: num(x[col.vehicle]), pet: num(x[col.pet]) };
      if (fileKey && !m.file) m.missingFile = fileKey;
      if (csvName && m.name !== csvName) m.nameCsv = csvName;
      if (mapByIndex.has(index)) { soft(`maplist duplicate index ${index}`); continue; }
      maps.push(m); mapByIndex.set(index, m);
    }
    // server-only maps (share/server/maplist.csv) — retired maps the server still knows (1 North Ares, 2 Norak …)
    if (exists('share/server/maplist.csv')) {
      const srows = readCsvLines(K('share/server/maplist.csv'));
      for (let r = 1; r < srows.length; r++) {
        const x = srows[r]; if (!x.length || !/^\d+$/.test(x[0] ?? '')) continue; const index = +x[0];
        if (!mapByIndex.has(index)) { const m = { index, name: (x[1] || '').split('\\').slice(-2, -1)[0]?.replace(/^\d+_/, '').replace(/_/g, ' ') || `map ${index}`, file: null, serverOnly: true }; maps.push(m); mapByIndex.set(index, m); }
      }
    }
    maps.sort((a, b) => a.index - b.index);
  }

  // ---------------------------------------------------------------- locations (named teleport points)
  const locations = [];
  {
    const key = 'share/arrange/location.csv'; const rows = readCsvLines(key); K(key);
    for (let r = 1; r < rows.length; r++) {
      const x = rows[r]; if (!x.length || !/^\d+$/.test(x[0] ?? '')) continue;
      const eu = leCsv(`arrange#location.csv#1|${r}`);
      locations.push([+x[0], (eu && eu.trim()) || x[1] || '', num(x[2]), num(x[3]), num(x[4]), num(x[5]), num(x[6]), num(x[7]), num(x[8])]);
    }
  }
  // landing point per map for "/gm move <map>" without coordinates
  const landingSrc = {};
  {
    const firstLoc = new Map(); for (const l of locations) if (!firstLoc.has(l[2]) && (l[3] || l[4])) firstLoc.set(l[2], l);
    const firstNpc = new Map(); if (NPC) for (const [mi, p] of Object.entries(NPC.placements || {})) { const row = (p.rows || []).find((q) => q[1] > 1 && q[2] > 1); if (row) firstNpc.set(+mi, row); }
    const firstSpawn = new Map(); if (MON) for (const [mi, p] of Object.entries(MON.spawns || {})) { const row = (p.rows || [])[0]; if (row) firstSpawn.set(+mi, row); }
    for (const m of maps) {
      let land = null, src = null;
      const loc = firstLoc.get(m.index);
      if (loc) { land = [loc[3], loc[4], loc[5]]; src = 'location'; }
      else if (m.ret && m.ret[0] === m.index && (m.ret[1] || m.ret[2])) { land = [m.ret[1], m.ret[2], 0]; src = 'maplistReturn'; }
      else if (firstNpc.has(m.index)) { const q = firstNpc.get(m.index); land = [round(q[1], 2), round(q[2], 2), q[3] || 0]; src = 'npc'; }
      else if (firstSpawn.has(m.index)) { const q = firstSpawn.get(m.index); land = [q[2] + 0.5, q[3] + 0.5, 0]; src = 'spawn'; }
      if (land) { m.landing = land; m.landingFrom = src; } else if (m.file) m.landing = null;
      landingSrc[src ?? 'none'] = (landingSrc[src ?? 'none'] || 0) + 1;
    }
  }
  // spawn / placement counts per map
  if (MON) for (const [mi, p] of Object.entries(MON.spawns || {})) { const m = mapByIndex.get(+mi); if (m) m.spawnRows = (p.rows || []).length; }
  if (NPC) for (const [mi, p] of Object.entries(NPC.placements || {})) { const m = mapByIndex.get(+mi); if (m) m.npcRows = (p.rows || []).length; }

  // ---------------------------------------------------------------- dungeons
  const dungeons = [];
  if (exists('share/dungeonlist.csv')) {
    const rows = readCsvLines(K('share/dungeonlist.csv')); const h = rows[0];
    const c = (n) => headerIndex(h, n);
    for (let r = 1; r < rows.length; r++) {
      const x = rows[r]; if (!x.length || !/^\d+$/.test(x[c('Dungeon_Index')] ?? '')) continue;
      const eu = leCsv(`share#dungeonlist.csv#0|${r}`); const mc = num(x[c('MapCount')]);
      const mapsOf = []; for (let k = 0; k < Math.max(1, mc); k++) { const v = x[c(`MapIndex_${k}`)]; if (v !== undefined && v !== '') mapsOf.push(num(v)); }
      dungeons.push({ index: num(x[c('Dungeon_Index')]), name: (eu && eu.trim()) || x[0], keeper: x[c('Keeper_Type')], expireMin: num(x[c('ExpireTime')]), members: [num(x[c('RequestMember')]), num(x[c('RequestMember_Max')])],
        maps: mapsOf.slice(0, Math.max(1, mc)), kick: [num(x[c('KickToMap_0')]), num(x[c('KickToX_0')]), num(x[c('KickToY_0')])], ticket: num(x[c('Ticket')]) });
    }
  }

  // ---------------------------------------------------------------- npcs (join npcs.json)
  const npcs = []; const npcByIndex = new Map();
  if (NPC) {
    const where = new Map();
    for (const [mi, p] of Object.entries(NPC.placements || {})) for (const row of p.rows || []) { if (!where.has(row[0])) where.set(row[0], []); const a = where.get(row[0]); if (!a.includes(+mi)) a.push(+mi); }
    for (const [k, v] of Object.entries(NPC.npcs || {})) {
      const n = [+k, v.name ?? '', v.roles || [], where.get(+k) || [], v.jobs || []];
      npcs.push(n); npcByIndex.set(+k, n);
    }
    npcs.sort((a, b) => a[0] - b[0]);
  }

  // ---------------------------------------------------------------- skills (script/skilldesc/*.csv, EU)
  const SKILL_FILES = { knight: 0, hunter: 1, magician: 2, summoner: 3, segnale: 4, warrior: 5, aloken: 6, dragonknight: 7, shooter: 8, wizard: 9, concerra: 10, segeuriper: 11, halfbagi: 12, aloken_m: 13, triemuse: 14 };
  const skills = []; const skillByIndex = new Map();
  for (const [file, cls] of Object.entries(SKILL_FILES)) {
    const key = `script/skilldesc/${file}.csv`; if (!exists(key)) { soft(`missing ${key}`); continue; } K(key);
    const rows = readCsvLines(key);
    for (let r = 1; r < rows.length; r++) {
      const x = rows[r]; if (!x.length || !/^\d+$/.test(x[0] ?? '')) continue;
      const idx = +x[0], lv = num(x[1]);
      let s = skillByIndex.get(idx);
      if (!s) { s = [idx, (leCsv(`skilldesc#${file}.csv#2|${r}`) || x[2] || '').trim(), cls, lv, (x[3] || '').trim(), stripTags(x[4] || '').replace(/\\/g, ' ').replace(/\s+/g, ' ').slice(0, 200)]; skillByIndex.set(idx, s); skills.push(s); }
      else { if (s[2] !== cls && !String(s[2]).split('|').includes(String(cls))) s[2] = `${s[2]}|${cls}`; s[3] = Math.max(s[3], lv); }
    }
  }
  // join gamedata/skills.json (tools/build-skills.mjs, share/skill tables): skills with no skilldesc row (hidden placeholders)
  const joins = {};
  const SKJ = loadGamedata('skills.json');
  if (SKJ) {
    let added = 0;
    for (const s of Object.values(SKJ.skills || {})) {
      if (skillByIndex.has(s.index)) continue;
      const row = [s.index, (s.name || '').trim() || `skill ${s.index}`, s.class ?? -1, s.maxLevel?.normal ?? 0, s.weaponReq || '', stripTags(s.description || '').slice(0, 200), s.hidden ? 'hidden' : 'skills.json'];
      skills.push(row); skillByIndex.set(s.index, row); added++;
    }
    joins.skills = { src: 'gamedata/skills.json#skills', added, total: Object.keys(SKJ.skills || {}).length };
  }
  skills.sort((a, b) => a[0] - b[0]);

  // ---------------------------------------------------------------- quests (share/quest + QUEST string group)
  const quests = []; const questByIndex = new Map();
  {
    const files = new Map();
    if (exists('share/quest/questfilelist.csv')) for (const x of readCsvLines(K('share/quest/questfilelist.csv')).slice(1)) if (x.length && /^\d+$/.test(x[0])) files.set(+x[0], x[1]);
    // questfilelist names are often stale (Quest_52_Ingot_To_Heart.csv vs quest_00052_lettertomilitia_sonia.csv on disk):
    // fall back to the zero-padded quest_<index>_*.csv file of that index
    const onDisk = new Map();
    for (const f of fs.readdirSync(abs('share/quest'))) { const m = /^quest_(\d+)_.*\.csv$/i.exec(f); if (m && !onDisk.has(+m[1])) onDisk.set(+m[1], `share/quest/${f.toLowerCase()}`); }
    const rows = exists('share/quest/questtable.csv') ? readCsvLines(K('share/quest/questtable.csv')) : [];
    const seen = new Set();
    const title = (c) => { for (const code of [1, 11, 12, 2, 13]) { const t = St('quest', c, code); if (t && stripTags(t)) return t; } return null; };
    const add = (idx, parent, type, level) => {
      if (seen.has(idx)) return; seen.add(idx);
      const t = title(idx) || (parent !== idx ? title(parent) : null);
      const f = files.get(idx); let fk = f ? `share/quest/${f.toLowerCase()}` : null;
      if (!fk || !exists(fk)) fk = onDisk.get(idx) ?? null;
      const q = [idx, stripTags(t || '').slice(0, 160), parent, type, level, fk && exists(fk) ? K(fk) : null];
      quests.push(q); questByIndex.set(idx, q);
    };
    for (const x of rows.slice(1)) if (x.length && /^\d+$/.test(x[0])) add(+x[0], num(x[1]), num(x[2]), num(x[3]));
    for (const [idx] of files) add(idx, idx, -1, 0);   // scripts with no questtable row (NPC dialog scripts)
    // join gamedata/quests.json (tools/build-quests.mjs): server-only / renewal quests + titles this builder cannot resolve
    const QJ = loadGamedata('quests.json');
    if (QJ) {
      let added = 0, titled = 0;
      for (const qq of Object.values(QJ.quests || {})) {
        const t = stripTags(qq.title || qq.name || '').slice(0, 160);
        const have = questByIndex.get(qq.id);
        if (have) { if (!have[1] && t) { have[1] = t; titled++; } continue; }
        const fk = qq.dialog?.file && exists(qq.dialog.file) ? K(qq.dialog.file) : null;
        const q = [qq.id, t, qq.parent ?? qq.id, qq.type ?? -1, Array.isArray(qq.level) ? qq.level[0] : (qq.level ?? 0), fk, `quests.json:${qq.src || '?'}`];
        quests.push(q); questByIndex.set(qq.id, q); added++;
      }
      joins.quests = { src: 'gamedata/quests.json#quests', added, titlesFilled: titled, total: Object.keys(QJ.quests || {}).length };
    }
    quests.sort((a, b) => a[0] - b[0]);
  }

  // ---------------------------------------------------------------- statuses (share/skill/status.csv)
  const statuses = []; const statusByIndex = new Map();
  {
    const key = 'share/skill/status.csv'; const rows = readCsvLines(key); K(key); const h = rows[0];
    const c = (n) => headerIndex(h, n);
    const iDesc = c('Description'), iType = c('Type'), iGroup = c('GroupIndex'), iIcon = c('IconIndex'), iMax = c('MaxStackCount'), iStyle = c('Style'), iMove = c('MapMoveDelete'), iOC = c('OptionCount');
    for (let r = 1; r < rows.length; r++) {
      const x = rows[r]; if (!x.length || !/^\d+$/.test(x[0] ?? '')) continue;
      const eu = leCsv(`skill#status.csv#6|${r}`);
      const opts = []; for (let k = iOC + 1; k + 1 < x.length; k += 2) { if (x[k] && x[k] !== 'NONE') opts.push([x[k], num(x[k + 1])]); }
      const s = [+x[0], ((eu && eu.trim()) || x[iDesc] || '').replace(/\\/g, ' / '), num(x[iType]), num(x[iGroup]), num(x[iIcon]), num(x[iMax]), num(x[iStyle]), num(x[iMove]), opts];
      statuses.push(s); statusByIndex.set(s[0], s);
    }
  }

  // ---------------------------------------------------------------- classes
  const classes = CLS ? (CLS.classes || []).map((c) => [c.index, c.code, c.name, c.playable ? 1 : 0, c.sex]) : [];

  // ---------------------------------------------------------------- emotes + chat types
  const emotes = []; const chatTypes = [];
  {
    const mm = new Map();   // motion -> emote
    const csvKey = 'script/lua/motion_macro.csv';
    // emote name = stringtable_emoticon cate 50 code: motions 10..26 -> codes 1..17, 27 -> 20 (Apology), 100 -> 21 (Costume),
    // motiontype 1 -> 18 (Sit loop), motiontype 2 -> 19 (Stand up). (Derived from the slash strings of cate 51 + motion_macro.)
    const nameCodeOf = (motion, mtype) => (mtype === 1 ? 18 : mtype === 2 ? 19 : motion === 100 ? 21 : motion === 27 ? 20 : motion - 9);
    const motionOfName = (code) => (code === 18 ? [1, 1] : code === 19 ? [1, 2] : code === 21 ? [100, 0] : code === 20 ? [27, 0] : [code + 9, 0]);
    const emoName = (motion, mtype) => St('normal', 50, nameCodeOf(motion, mtype));
    if (exists(csvKey)) for (const x of readCsvLines(K(csvKey)).slice(1)) {
      if (!x.length || !/^\d+$/.test(x[1] ?? '')) continue;
      const code = +x[1], motion = num(x[2]), mtype = num(x[3]); const slash = St('normal', num(x[0]), code);
      const k = `${motion}/${mtype}`; if (!mm.has(k)) mm.set(k, { motion, motionType: mtype, name: emoName(motion, mtype), slash: [], slashKr: [], codes: [] });
      const e = mm.get(k); e.codes.push(code); if (slash && !e.slash.includes(slash)) e.slash.push(slash);
    }
    // EU help lists 50:4001..4021 ("/hi /hello /greeting") -> extra aliases for emote name code (code-4000)
    for (let c = 4001; c <= 4030; c++) {
      const t = St('normal', 50, c); if (!t) continue;
      const [motion, mtype] = motionOfName(c - 4000);
      const e = mm.get(`${motion}/${mtype}`); if (!e) { soft(`emote help 50:${c} "${t}" has no motion ${motion}/${mtype}`); continue; }
      for (const s of t.split(/\s+/)) if (s.startsWith('/') && !e.slash.includes(s)) e.slash.push(s);
    }
    const luaKey = 'script/lua/motion_macro.lua';
    if (exists(luaKey)) {
      const lua = decodeText(readKey(K(luaKey)));
      const re = /shortcut\s*=\s*"([^"]+)"\s*,\s*motion\s*=\s*(\d+)\s*,\s*motiontype\s*=\s*(\d+)/g; let m;
      while ((m = re.exec(lua))) { const k = `${m[2]}/${m[3]}`; if (!mm.has(k)) mm.set(k, { motion: +m[2], motionType: +m[3], name: emoName(+m[2], +m[3]), slash: [], slashKr: [], codes: [] }); const e = mm.get(k); if (!e.slashKr.includes(m[1])) e.slashKr.push(m[1]); }
    }
    for (const e of [...mm.values()].sort((a, b) => a.motion - b.motion || a.motionType - b.motionType)) emotes.push([e.motion, e.motionType, e.name, e.slash, e.slashKr]);

    const ctKey = 'script/lua/chattype_macro.lua';
    const byType = new Map();
    if (exists(ctKey)) {
      const lua = decodeText(readKey(K(ctKey)));
      const re = /shortcut\s*=\s*"([^"]+)"\s*,\s*ChatType\s*=\s*(\d+)/g; let m;
      while ((m = re.exec(lua))) { const t = +m[2]; if (!byType.has(t)) byType.set(t, []); byType.get(t).push(m[1]); }
    }
    K('script/lua/chattype_macro.csv');
    for (const p of CHAT_PREFIXES) chatTypes.push({ name: p.name, chatType: p.chatType, prefix: p.prefix, syntax: p.syntax, help: St('normal', ...p.string.split(':').map(Number)), string: `normal|${p.string}` });
    for (const [t, sc] of byType) chatTypes.push({ name: CHATTYPE_EN[t] ?? `type ${t}`, chatType: t, shortcutsKr: sc, shortcutsEn: sc.map((s) => KR_SHORTCUT_EN[s]).filter(Boolean) });
  }

  // ---------------------------------------------------------------- call groups (callmonster tables) + contents + skies
  const callGroups = [];
  if (MON) for (const [file, cs] of Object.entries(MON.callSpawns || {})) {
    const groupsOf = new Map();
    for (const row of cs.rows || []) { const g = row[0]; if (!groupsOf.has(g)) groupsOf.set(g, { rows: 0, count: 0, monsters: new Set() }); const e = groupsOf.get(g); e.rows++; e.count += row[5] || 1; e.monsters.add(row[1]); }
    for (const rc of cs.randomCalls || []) { const g = `r${rc[0]}`; if (!groupsOf.has(g)) groupsOf.set(g, { rows: 0, count: 0, monsters: new Set() }); const e = groupsOf.get(g); e.rows++; e.count += rc[2] || 1; e.monsters.add(rc[1]); }
    for (const [g, e] of groupsOf) callGroups.push([file, g, cs.maps || (cs.map != null ? [cs.map] : []), e.rows, e.count, [...e.monsters]]);
  }
  const contents = [];
  if (exists('script/contents_timetable.csv')) for (const x of readCsvLines(K('script/contents_timetable.csv')).slice(1)) if (x.length && /^\d+$/.test(x[0])) contents.push({ no: +x[0], time: x[1], endTime: x[2] || null, name: x[3], map: x[4], level: x[5], week: x[6] || null, tab: num(x[7]) });
  const contentNames = [...new Set(contents.map((c) => c.name))].map((n) => ({ name: n, maps: [...new Set(contents.filter((c) => c.name === n).map((c) => c.map))], times: contents.filter((c) => c.name === n).map((c) => c.time) }));
  const skies = [];
  if (exists('script/environment/sky_table.txt')) for (const x of readCsvLines(K('script/environment/sky_table.txt')).slice(1)) if (x.length && /^\d+$/.test(x[0])) {
    const sk = `texture/${(x[1] || '').toLowerCase()}`, ck = `texture/${(x[2] || '').toLowerCase()}`;
    skies.push({ index: +x[0], desc: x[4], sky: exists(sk) ? K(sk) : null, cloud: exists(ck) ? K(ck) : null, flare: num(x[3]), ...(exists(sk) ? {} : { missingSky: sk }), ...(exists(ck) ? {} : { missingCloud: ck }) });
  }

  // ---------------------------------------------------------------- effect scenes (property/effect/effectscene.<file>.txt) for /gm effect
  //   "<cate> N name" / <effect> id N name X <list> res… </list> <scene> sceneid N name Y <control>…</control> </scene> </effect>
  //   Every effect of every file (the skills builder keeps only the skill/status-referenced ones, with full playback data).
  const effects = []; const effectCates = {}; const effectByKey = new Map(); let effectDup = 0;
  for (const f of ['01', '02', '03', 'com', 'map', 'snd']) {
    const key = `property/effect/effectscene.${f}.txt`; if (!exists(key)) { soft(`missing ${key}`); continue; } K(key);
    let cate = null, eff = null, sc = null, depth = 0;   // depth: 0 effect body, 1 inside <list>/<control>/other nested blocks
    for (const raw of decodeText(readKey(key)).split(/\r\n|\n|\r/)) {
      const s = raw.trim(); if (!s || s.startsWith('#') || s.startsWith('//')) continue;
      let m;
      if ((m = /^<cate>\s*(-?\d+)\s*(\S*)/i.exec(s))) { cate = +m[1]; if (m[2] && !effectCates[cate]) effectCates[cate] = m[2]; continue; }
      if (/^<\/cate>/i.test(s)) continue;
      if (/^<effect>/i.test(s)) { eff = { cate, id: null, name: '', scenes: [] }; sc = null; depth = 0; continue; }
      if (/^<\/effect>/i.test(s)) {
        if (eff && eff.id != null) {
          // the same cate:id is defined once per file that contributes to it: a visual file (01/02/03/com/map) and usually
          // a sound twin in effectscene.snd.txt — the runtime plays all of them together (see build-skills.mjs visualOf/soundSceneOf)
          const k = `${eff.cate}:${eff.id}`; const have = effectByKey.get(k);
          if (have) { effectDup++; if (!have[4].includes(f)) have[4].push(f); if (!have[3] && eff.name) have[3] = eff.name; for (const s of eff.scenes) if (!have[5].some((x) => x[0] === s[0])) have[5].push(s); }
          else { const row = [k, eff.cate, eff.id, eff.name, [f], eff.scenes]; effects.push(row); effectByKey.set(k, row); }
        }
        eff = null; sc = null; continue;
      }
      if (!eff) continue;
      if (/^<scene>/i.test(s)) { sc = [null, '']; depth = 0; continue; }
      if (/^<\/scene>/i.test(s)) { if (sc && sc[0] != null) eff.scenes.push(sc); sc = null; continue; }
      if (/^<\/\w+>/.test(s)) { depth = Math.max(0, depth - 1); continue; }
      if (/^<\w+>/.test(s)) { depth++; continue; }
      if (depth) continue;
      if ((m = /^id\s+(-?\d+)/i.exec(s)) && !sc) { eff.id = +m[1]; continue; }
      if ((m = /^sceneid\s+(-?\d+)/i.exec(s)) && sc) { sc[0] = +m[1]; continue; }
      if ((m = /^name\s+(.*)$/i.exec(s))) { const v = m[1].trim().replace(/^"|"$/g, ''); if (sc) sc[1] = v; else eff.name = v; }
    }
  }
  effects.sort((a, b) => a[1] - b[1] || a[2] - b[2]);
  const EFFECT_CATE_EN = { 0: 'none', 1: 'monster', 3: 'sound', 4: 'game_sound', 5: 'game', 6: 'hit', 7: 'item', 8: 'ui', 9: 'light', 10: 'weather', 11: 'condition', 12: 'event', 100: 'skill' };
  for (const c of Object.keys(effectCates)) if (!(c in EFFECT_CATE_EN)) soft(`effectscene category ${c} (${effectCates[c]}) has no English name`);
  const effectFileCombos = countBy(effects, (e) => e[4].join('+'));
  log(`effects: ${effects.length} effects in ${Object.keys(effectCates).length} categories (${effectDup} extra definitions merged: ${JSON.stringify(effectFileCombos)})`);

  // ---------------------------------------------------------------- every item set + map-wide and class drop layers (raw)
  // share/item/itemset.csv: Set Index, Name, Total Drop Ratio, Set Count, then Set Count x [ItemIndex, DropRatio,
  // MagicRatio|StackMin, NobleRatio|StackMax, DivineNobleRatio] (same layout monsters.json itemSets uses)
  const itemSets = {};
  {
    const key = 'share/item/itemset.csv'; const rows = readCsvLines(K(key));
    for (const x of rows.slice(1)) {
      if (!x.length || !/^\d+$/.test(x[0] ?? '')) continue;
      const n = num(x[3]); const its = [];
      for (let k = 0; k < n; k++) { const b = 4 + k * 5; const item = num(x[b]); if (!item) continue; const e = [item, num(x[b + 1]), num(x[b + 2]), num(x[b + 3]), num(x[b + 4])]; while (e.length > 2 && e[e.length - 1] === 0) e.pop(); its.push(e); }
      itemSets[+x[0]] = { name: x[1] || '', total: num(x[2], 100000), items: its };
    }
  }
  // share/item/monsterdropitem_map.csv: extra drops for EVERY monster killed on a map (except Exclude_Monster "a/b/c")
  const mapDrops = {};
  {
    const key = 'share/item/monsterdropitem_map.csv'; const rows = readCsvLines(K(key)); const h = rows[0]; const c = (n) => headerIndex(h, n);
    for (const x of rows.slice(1)) {
      if (!x.length || !/^\d+$/.test(x[0] ?? '')) continue;
      const sets = []; for (let k = 1; k <= 15; k++) { const s = num(x[c(`ItemSetIndex_${k}`)]); if (s) sets.push([s, num(x[c(`ItemSetDropRatio_${k}`)])]); }
      const fixed = []; for (let k = 1; k <= 10; k++) { const it = num(x[c(`Fix_ItemIndex_${k}`)]); if (it) fixed.push([it, num(x[c(`Fix_ItemStack_${k}`)]), num(x[c(`Fix_ItemCountMin_${k}`)]), num(x[c(`Fix_ItemCountMax_${k}`)]), num(x[c(`FixItemRatio_${k}`)])]); }
      const fixedSets = []; for (let k = 1; k <= 10; k++) { const s = num(x[c(`Fix_ItemSet_${k}`)]); if (s) fixedSets.push([s, num(x[c(`Fix_ItemSetCountMin_${k}`)]), num(x[c(`Fix_ItemSetCountMax_${k}`)]), num(x[c(`FixItemSetRatio_${k}`)])]); }
      const money = [c('MoneyCount_Min'), c('MoneyCount_Max'), c('Money_Min'), c('Money_Max'), c('Money_Rate')].map((i) => num(x[i]));
      const ex = String(x[c('Exclude_Monster')] ?? '0').split('/').map(Number).filter((v) => v > 0);
      if (!sets.length && !fixed.length && !fixedSets.length && !money[4] && !num(x[c('Class_Check')])) continue;
      mapDrops[+x[0]] = { nameKr: x[1], classCheck: num(x[c('Class_Check')]), exclude: ex, money, maxSets: num(x[c('MaxItemSet')]), sets, fixed, fixedSets };
    }
  }
  // share/item/monsterdropitem_class.csv: per map + monster level range, a class-specific item set (Class_<class>_<1..10>
  // are item-set indices: all 389 distinct values are itemset.csv indices)
  const classDrops = [];
  {
    const key = 'share/item/monsterdropitem_class.csv'; const rows = readCsvLines(K(key)); const h = rows[0];
    const classCols = {}; h.forEach((name, i) => { const m = /^Class_(\d+)_(\d+)$/.exec(String(name).trim()); if (m) (classCols[+m[1]] ||= []).push(i); });
    for (const x of rows.slice(1)) {
      if (!x.length || !/^\d+$/.test(x[0] ?? '')) continue;
      const byClass = {}; for (const [cl, cols] of Object.entries(classCols)) { const its = cols.map((i) => num(x[i])).filter((v) => v > 0); if (its.length) byClass[cl] = its; }
      if (!Object.keys(byClass).length) continue;
      classDrops.push([num(x[0]), num(x[1]), num(x[2]), num(x[3]), num(x[4]), num(x[5]), num(x[6]), num(x[7]), byClass]);
    }
  }

  // ---------------------------------------------------------------- monsters with drops (join monsters.json)
  const monsters = [];
  const dropMisses = new Set();
  if (MON) {
    const where = new Map(), calls = new Map();
    for (const [mi, p] of Object.entries(MON.spawns || {})) for (const row of p.rows || []) { if (!where.has(row[0])) where.set(row[0], new Set()); where.get(row[0]).add(+mi); }
    for (const cs of Object.values(MON.callSpawns || {})) { const ms = cs.maps || (cs.map != null ? [cs.map] : []); for (const row of cs.rows || []) { if (!calls.has(row[1])) calls.set(row[1], new Set()); for (const x of ms) calls.get(row[1]).add(x); } for (const rc of cs.randomCalls || []) { if (!calls.has(rc[1])) calls.set(rc[1], new Set()); for (const x of ms) calls.get(rc[1]).add(x); } }
    const sets = itemSets;   // all sets, raw (monsters.json only carries the referenced ones)
    for (const [k, m] of Object.entries(MON.monsters || {})) {
      const idx = +k; const drops = new Map();   // item -> [chance, min, max, via]
      const addDrop = (item, p, min = 1, max = 1) => { if (!itemByIndex.has(item)) dropMisses.add(item); const e = drops.get(item); if (e) { e[0] = 1 - (1 - e[0]) * (1 - p); e[1] = Math.min(e[1], min); e[2] = Math.max(e[2], max); } else drops.set(item, [p, min, max]); };
      // itemset item = [item, dropRatio, magicRatio|stackMin, nobleRatio|stackMax, divineRatio]: for stackable items
      // (csv StackNumber > 1) columns 3/4 are the stack count range, otherwise quality (magic/noble) ratios.
      const expandSet = (setIndex, pSet) => {
        const s = sets[setIndex]; if (!s) return false;
        const total = s.total || 100000;
        for (const it of s.items || []) {
          if (!it[0]) continue; const st = itemByIndex.get(it[0])?.[8] ?? 0;
          const stackable = st > 1 && it[2] > 0 && it[3] >= it[2];
          addDrop(it[0], pSet * (it[1] / total), stackable ? it[2] : 1, stackable ? it[3] : 1);
        }
        return true;
      };
      const d = m.drops || {};
      for (const [setIndex, ratio] of d.sets || []) if (!expandSet(setIndex, Math.min(1, ratio / 100000))) soft(`monster ${idx}: item set ${setIndex} not in share/item/itemset.csv`);
      for (const [item, stack, cmin, cmax] of d.fixed || []) addDrop(item, 1, cmin || stack || 1, cmax || stack || 1);
      for (const [setIndex, cmin, cmax, , ratio] of d.fixedSets || []) expandSet(setIndex, Math.min(1, (ratio || 100000) / 100000));
      const dl = [...drops.entries()].sort((a, b) => b[1][0] - a[1][0]).map(([item, [p, mn, mx]]) => (mn === 1 && mx === 1 ? [item, round(p, 7)] : [item, round(p, 7), mn, mx]));
      const money = m.money ? [m.money[0], m.money[1], round((m.money[2] || 0) / 100000, 6)] : null;
      monsters.push([idx, m.name ?? '', m.level ?? 0, m.hp ?? 0, m.rank ?? 0, m.role ?? 'creature', m.exp ?? 0, m.ai?.aggressive ? 1 : 0,
        [...(where.get(idx) || [])].sort((a, b) => a - b), [...(calls.get(idx) || [])].sort((a, b) => a - b), money, dl, (d.money || []).length ? d.money : null, d.sets || [], m.nameKr ?? null]);
    }
    monsters.sort((a, b) => a[0] - b[0]);
  }
  const monByIndex = new Map(monsters.map((m) => [m[0], m]));

  // ================================================================ GM-specific tables (all columns kept)
  const original = {};
  // ---- GM tool privilege table (credentials withheld)
  {
    const key = 'share/server/gradelist.csv'; const rows = readCsvLines(key); K(key); const h = rows[0];
    const privCols = h.slice(3);
    const accounts = rows.slice(1).filter((x) => x.length).map((x) => {
      const flags = {}; privCols.forEach((c, i) => { flags[c] = num(x[3 + i]); });
      return { account: x[0], password: '<withheld>', grade: num(x[2]), flags };
    });
    const tiers = {};
    for (const a of accounts) { const sig = privCols.map((c) => a.flags[c]).join(''); (tiers[sig] ||= { grade: a.grade, privileges: privCols.filter((c) => a.flags[c]), accounts: [] }).accounts.push(a.account); }
    original.privileges = {
      src: key, note: 'GM-tool privilege matrix of the live server. Passwords are present in the client file and deliberately NOT copied. GRADE 0 = server/super-admin, 1 = GM.',
      columns: h.slice(0, 3).concat(privCols), meaning: Object.fromEntries(privCols.map((c) => [c, { desc: PRIVILEGE_MEANING[c]?.[0] ?? null, confidence: PRIVILEGE_MEANING[c]?.[1] ?? 'low' }])),
      tiers: Object.values(tiers), accounts: accounts.map(({ account, grade, flags }) => ({ account, grade, flags })),
    };
    for (const c of privCols) if (!PRIVILEGE_MEANING[c]) soft(`gradelist privilege ${c} has no meaning entry`);
  }
  // ---- EXP policy, access lists (values withheld)
  original.expPolicy = { src: K('share/server/exppolicy.csv'), rows: readCsvLines('share/server/exppolicy.csv').slice(1).filter((x) => x.length).map((x) => ({ enabled: num(x[0]), source: x[1] })) };
  original.accessControl = {
    gmIpAllowlist: { src: K('share/server/iplist.csv'), entries: readCsvLines('share/server/iplist.csv').slice(1).filter((x) => x.length).length, grades: [...new Set(readCsvLines('share/server/iplist.csv').slice(1).filter((x) => x.length).map((x) => num(x[1])))] },
    toolIpClasses: { src: K('share/server/tooliplist.csv'), entries: readCsvLines('share/server/tooliplist.csv').slice(1).filter((x) => x.length).length },
    note: 'Server-side GM IP allow-lists; addresses are not copied. Irrelevant in solo play (the GM panel is always available).',
  };
  // ---- GM tool windows
  const uiWin = (key) => { const w = parseUiWindow(decodeText(readKey(K(key)))); for (const c of w.controls) if (c.text2) { const s = S('normal', c.text2[0], c.text2[1]); c.textResolved = s?.text ?? null; if (!s) soft(`${key}: text2 ${c.text2.join(' ')} unresolved`); } return { src: key, ...w }; };
  original.gmToolWindows = ['script/ui/game2/gmtool/ui_gmtoolwnd.txt', 'script/ui/game2/gmtool/ui_gmmessagewnd.txt', 'script/ui/game2/gmtool/ui_shutoffwnd.txt'].filter(exists).map(uiWin);
  original.console = {
    windows: ['script/ui/console/ui_main.txt', 'script/ui/console/ui_system.txt'].filter(exists).map(uiWin),
    errors: [60, 61, 62].map((c) => ({ string: `normal|160:${c}`, text: St('normal', 160, c) })),
  };
  // ---- GM event strings (cate 178)
  original.gmEvents = { strings: [1, 2, 3, 4, 5].map((c) => ({ string: `cashitem|178:${c}`, text: St('normal', 178, c) })), kinds: { exp: 'MONSTEREXPRATIO', drop: 'ITEMDROPRATIO', dil: 'MONEYDROPRATIO' },
    serverClose: { string: 'normal|1002:5', text: St('normal', 1002, 5) }, pcRoom: { string: 'normal|1002:4', text: St('normal', 1002, 4) } };
  // ---- GM NPC dungeon-script menus: the dungeon scripts of the maps where the GM NPCs stand
  //      5825 Operation Assistant -> messages 9553-9610 (GM command / buff / OX entry); 5830 Start Stone (map 22) -> 4900, 5100-5117
  const gmMapsBuff = new Set(npcByIndex.get(5825)?.[3] || []); gmMapsBuff.add(654);
  const gmMapsOx = new Set(npcByIndex.get(5830)?.[3] || []); gmMapsOx.add(22);
  const gmCodesFor = (di) => (c) => (gmMapsBuff.has(di) && c >= 9553 && c <= 9610) || (gmMapsOx.has(di) && ((c >= 5100 && c <= 5117) || c === 4900));
  const gmNpcMenus = [];
  {
    const dfl = new Map();
    for (const x of readCsvLines(K('share/dungeon/dungeonfilelist.csv')).slice(1)) if (x.length && /^\d+$/.test(x[0])) dfl.set(+x[0], `share/dungeon/${(x[1] || '').toLowerCase()}`);
    for (const [di, key] of dfl) {
      if (!exists(key) || !(gmMapsBuff.has(di) || gmMapsOx.has(di))) continue;
      const gmCodes = gmCodesFor(di);
      const rows = readCsvLines(key); const hIdx = rows.findIndex((x) => (x[0] || '').toLowerCase() === 'messageindex'); if (hIdx < 0) continue;
      const msgs = rows.slice(hIdx + 1).filter((x) => x.length && /^\d+$/.test(x[0]));
      const gm = msgs.filter((x) => gmCodes(+x[0])); if (!gm.length) continue;
      K(key);
      gmNpcMenus.push({ dungeon: di, map: di, mapName: mapByIndex.get(di)?.name ?? null, src: key,
        messages: gm.map((x) => ({ msg: +x[0], string: +x[1], text: St('dungeon', di, +x[1]), menu: x.slice(2).map(Number).filter((v) => v > 0), raw: x.slice(2).map(Number) })) });
    }
  }
  original.gmNpcs = [];
  for (const [idx, root, role] of [[5825, 9559, 'Operation Assistant: GM command menu (1. Grant Buff / 2. OX Quiz)'], [5830, 5100, 'OX quiz Start Stone (GM characters only: 61755)'], [5831, null, 'OX quiz Escape Stone'], [3350, null, 'Provide Item: GM supply (quest 10030)'], [5430, null, 'Meister Gniar: test job change (quest 1621)'],
    [5546, null, 'Test NPC "Testing"'], [5547, null, 'Test NPC "Guild dungeon testing"'], [5548, null, 'Test NPC "Function testing_C"'], [5549, null, 'Test NPC "Function testing_D"'], [5898, null, 'Atroforce (Test Administrator)'], [5903, null, 'Final Test Area portal']]) {
    const n = npcByIndex.get(idx); if (!n) { hard(`GM NPC ${idx} not in npcs`); continue; }
    original.gmNpcs.push({ npc: idx, name: n[1], role, jobs: n[4], maps: n[3], dialogRoot: root, conv: NPC?.npcs?.[idx]?.comm ?? null, convText: NPC?.npcs?.[idx]?.comm ? St('normal', 0, NPC.npcs[idx].comm) : null });
  }
  original.gmNpcMenus = gmNpcMenus;
  // ---- GM buffs: menu 9601..9610 <-> statuses with icon 7531 (imagetable "GM 버프추가") in group 125
  const gmBuffs = [];
  {
    const cand = statuses.filter((s) => s[4] === 7531 && s[3] === 125).sort((a, b) => a[0] - b[0]);
    const menuMap = gmNpcMenus.find((g) => g.dungeon === 654) || gmNpcMenus.find((g) => g.messages.some((m) => m.msg === 9601));
    for (let c = 9601; c <= 9610; c++) {
      const label = (menuMap && St('dungeon', menuMap.dungeon, c)) || St('dungeon', 150, c);
      const want = Number((/(\d+)\s*%?\s*$/.exec(label || '') || [])[1]);
      const kind = /exp/i.test(label || '') ? 'RESULT_EXP_MUL' : /attack|att/i.test(label || '') ? 'COMBINE_OPTION_COMBINE_MUL' : /stat/i.test(label || '') ? 'STAT_STR_ADD' : null;
      const st = cand.find((s) => s[8].some(([code, v]) => code === kind && v === want));
      if (!st) hard(`GM buff ${c} "${label}" has no matching status`);
      gmBuffs.push({ menu: c, label, status: st?.[0] ?? null, statusName: st?.[1] ?? null, options: st?.[8] ?? null, minutes: 30, group: 125, icon: 7531, inMenu: !!(menuMap?.messages.find((m) => m.msg === 9560)?.menu.includes(c)) });
    }
  }
  original.gmBuffs = { src: 'share/skill/status.csv (IconIndex 7531 "GM 버프추가", GroupIndex 125) + DUNGEON strings 9601-9610', note: 'The buff menu (9560) lists 9 slots (Menu0..Menu8): 9601-9609. 9610 (All Stats +100, status 7493) exists but does not fit the 9-slot menu.', buffs: gmBuffs };
  // ---- OX quiz
  {
    const ox = readCsvLines(K('share/event/oxlist.csv'));
    const q = ox.slice(1).filter((x) => x.length && /^\d+$/.test(x[0]));
    // oxlist questions contain commas inside [brackets]: re-join fields between the brackets
    const oxQuestions = q.map((x) => { const line = x.join(','); const m = /^(\d+),\[(.*?)\],\s*([OX])\s*,\[(.*)\]\s*$/.exec(line); return m ? [+m[1], m[2], m[3], m[4]] : [+x[0], x[1], x[2], x.slice(3).join(',')]; });
    const cs = MON?.callSpawns?.['share/map/22_undo_stadion/callmonster_22_undostadion.csv'];
    const oxGroups = {}; for (const row of cs?.rows || []) { (oxGroups[row[0]] ||= { rows: 0, monster: row[1], cells: [] }).rows++; oxGroups[row[0]].cells.push([row[2], row[3]]); }
    original.oxQuiz = {
      map: 22, mapName: mapByIndex.get(22)?.name ?? null, gmNpc: 5830, escapeNpc: 5831, entryNpcMap: 654,
      functions: [5111, 5112, 5113, 5114, 5115, 5116, 5117].map((c) => ({ msg: c, text: St('dungeon', 22, c) })),
      intro: St('dungeon', 22, 5110), exit: St('dungeon', 22, 4900),
      callTable: 'share/map/22_undo_stadion/callmonster_22_undostadion.csv', callGroups: oxGroups, callMonster: 8134, callMonsterName: monByIndex.get(8134)?.[14] ?? null,
      questions: oxQuestions, src: 'share/event/oxlist.csv',
    };
    const half = (gs) => { const cells = gs.flatMap((g) => oxGroups[g]?.cells || []); const ys = cells.map((c) => c[1]), xs = cells.map((c) => c[0]); return cells.length ? { groups: gs.map(Number), cells: cells.length, x: [Math.min(...xs), Math.max(...xs)], y: [Math.min(...ys), Math.max(...ys)] } : null; };
    const gNums = Object.keys(oxGroups).map(Number);
    original.oxQuiz.halves = { a: half(gNums.filter((g) => g < 10)), b: half(gNums.filter((g) => g >= 10)) };
    original.oxQuiz.note = 'callmonster_22 CallIndex groups (monster 8134, Korean name "가시 올리기" = rising spikes, an invisible trap) tile the two answer halves of the arena: groups 1-6 the y >= 257 half, 11-15 the y <= 253 half. Eliminate (O) / (X) fire the groups of the WRONG half. Which half is O is not stated in the data (the Start Stone stands on the dividing line at 238,256); "Create wall" has no call group (treat it as a blocking strip along y 254-256).';
  }
  // ---- GM supply (quest 10030 at NPC 3350)
  const gmSupply = [];
  {
    const byName = (re, pool) => items.filter((it) => re.test(it[1]) && (!pool || itemTables[it[2]].id === pool)).sort((a, b) => a[0] - b[0])[0] ?? null;
    for (let c = 20001; c <= 20007; c++) { const label = St('quest', 10030, c); const rank = (/Supply 1000 (\w+?)s?$/.exec(label || '') || [])[1]; const it = rank ? byName(new RegExp(`^Fortress Voucher \\[${rank}\\]$`, 'i')) : null; gmSupply.push({ menu: c, kind: 'voucher', label, item: it?.[0] ?? null, itemName: it?.[1] ?? null, count: 1000, confidence: it ? 'medium' : 'none' }); }
    for (let c = 30001; c <= 30004; c++) { const label = St('quest', 10030, c); const nm = (/Supply 1000 (.+?)s?$/.exec(label || '') || [])[1]; const it = nm ? byName(new RegExp(`^${nm.replace(/[.*+?^${}()|[\]\\]/g, '\\$&')}$`, 'i'), 'etc') : null; gmSupply.push({ menu: c, kind: 'material', label, item: it?.[0] ?? null, itemName: it?.[1] ?? null, count: 1000, confidence: it ? 'medium' : 'none' }); }
    original.gmSupply = { npc: 3350, quest: 10030, requiresItem: 64997, requiresItemName: itemName(64997), requireText: St('quest', 10030, 1000), menus: [10000, 20000, 30000].map((c) => ({ msg: c, text: St('quest', 10030, c) })), entries: gmSupply,
      note: 'The quest script only carries the menu texts; which item a line gives is server logic. Items are matched by name (Fortress Voucher [rank], material names); "Darham" has no item of that name in the EU tables.' };
  }
  // ---- test quest 1621
  original.testQuests = [{ quest: 1621, title: St('quest', 1621, 11), npc: 5430, map: 38, menus: [10000, 10001, 10002, 201, 202, 99].map((c) => ({ msg: c, text: St('quest', 1621, c) })) }];
  // ---- GM-only content: monsters, items, npcs (auto-detected by name)
  original.gmMonsters = monsters.filter((m) => /\bGM\b/.test(m[1]) || /GM/.test(m[14] || '')).map((m) => ({ index: m[0], name: m[1], nameKr: m[14], level: m[2], hp: m[3], rank: m[4], spawnMaps: m[8], callMaps: m[9] }));
  original.gmItems = items.filter((it) => /\bGM\b|\bGM'?s\b|\(GM\)/.test(it[1]) || /GM/.test(it[12] || '')).map((it) => ({ index: it[0], name: it[1], table: itemTables[it[2]].id, reqLv: it[6], nameKr: it[12] ?? undefined }));
  original.testItems = items.filter((it) => /\(Test\)|\bTest\b/.test(it[1])).map((it) => ({ index: it[0], name: it[1], table: itemTables[it[2]].id }));
  original.testMaps = maps.filter((m) => /test/i.test(m.name)).map((m) => ({ index: m.index, name: m.name, file: m.file }));
  // ---- map tool
  {
    const key = 'script/ui/maptool/ui_maptoolcommand.txt';
    const cmds = []; for (const raw of decodeText(readKey(K(key))).split(/\r\n|\n|\r/)) { const m = /^#maptoolcommand\s+(\S+)\s+(\d+)\s+"([^"]*)"?/.exec(raw.trim()); if (m) cmds.push({ name: m[1], argc: +m[2], usage: m[3].trim(), ...(m[1].startsWith('load_') && m[3].includes('save_') ? { note: 'usage text says save_… (copy-paste typo in the client)' } : {}) }); }
    const mb = groups.NORMAL?.find((f) => f.key.endsWith('tool/mapbuilder.txt'));
    const tools = []; if (mb) for (const [k, v] of mb.table) { const [cate, code] = k.split(':').map(Number); if (cate === 20000) tools.push({ code, kr: v, en: MAPBUILDER_EN[code] ?? null }); }
    original.mapTool = { src: key, commands: cmds, toolbarHelp: { src: 'script/string/tool/mapbuilder.txt', cate: 20000, entries: tools.sort((a, b) => a.code - b.code) },
      windows: ['script/ui/maptool/ui_maptoolbar.txt', 'script/ui/maptool/ui_toolbarwnd.txt', 'script/ui/maptool/ui_noticewnd.txt', 'script/ui/maptool/ui_noticepreviewwnd.txt', 'script/ui/maptool/ui_testwnd.txt'].filter(exists).map(K) };
  }
  // ---- chat / emotes / restriction / ban texts
  original.chat = { prefixesHelp: [21, 22, 23, 24, 25, 26, 27, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 73, 80, 86].map((c) => ({ code: c, text: St('normal', 230, c) })), restrain: { string: 'system|700:2', text: St('system', 700, 2) },
    antiSpam: [38, 57, 58, 60, 61, 69, 90].map((c) => ({ code: c, text: St('normal', 230, c) })) };
  original.accountSanctions = [6, 8, 11, 26].map((c) => ({ string: `system|600:${c}`, text: St('system', 600, c) }));
  // ---- GM name tags reserved by the client filters (players cannot use them: GM characters were tagged [GM] / [DEV])
  {
    const readWords = (key) => decodeText(readKey(K(key))).split(/\r\n|\n|\r/).map((s) => s.trim()).filter(Boolean);
    const slang = new Set(exists('script/filter/slang.txt') ? readWords('script/filter/slang.txt').map((w) => w.toLowerCase()) : []);
    const isGm = (w) => /\bgm\b|\[gm\]|gm online|admin|gamemaster|game master|\[dev\]|운영|관리자/i.test(w) && !slang.has(w.toLowerCase());
    const files = [];
    for (const [key, what] of [['script/filter/namefilter.txt', 'character / guild names'], ['script/filter/chatfilter.txt', 'chat text'], ['script/filter/proper_noun.txt', 'proper nouns']]) {
      if (!exists(key)) { soft(`missing ${key}`); continue; }
      const words = readWords(key);
      const seen = new Set(); const gm = [];
      for (const w of words) if (isGm(w) && !seen.has(w.toLowerCase())) { seen.add(w.toLowerCase()); gm.push(RESERVED_KR_EN[w] ? { word: w, en: RESERVED_KR_EN[w] } : w); }
      files.push({ src: key, filters: what, words: words.length, gmWords: gm });
    }
    original.reservedNames = { note: 'GM-related words the client refuses in character names / chat: GM characters carried a "[GM]" or "[DEV]" tag and ops staff were called 운영자 (operator). Case variants are collapsed here.', files,
      solo: 'When GM mode is on, show the player name with a [GM] tag (gmmessage colour ffedfc00); the name filter keeps rejecting these words for normal character creation.' };
  }
  // ---- developer tools shipped in the client UI (besides the console and the map tool)
  {
    const toolKeys = ['script/ui/effecttool/ui_effecttool_toolbar.txt', 'script/ui/effecttool/ui_effecttool_mainwnd.txt', 'script/ui/effecttool/ui_effecttool_particle_editwnd.txt',
      'script/ui/effecttool/ui_effecttool_mesh_editwnd.txt', 'script/ui/effecttool/ui_effecttool_decal_editwnd.txt', 'script/ui/effecttool/ui_effectviewwnd.txt'].filter(exists);
    const KR_LABEL = { '수정': 'Modify', '모델': 'Model' };
    const windows = toolKeys.map((key) => {
      // old-style UI script: create_control <type> <id> { control_text <x> <y> <label> … }
      let type = null, id = null; const controls = []; let title = null;
      for (const raw of decodeText(readKey(K(key))).split(/\r\n|\n|\r/)) {
        const s = raw.trim(); let m;
        if ((m = /^create_control\s+(\w+)\s+(\w+)/i.exec(s))) { type = m[1].toLowerCase(); id = m[2]; continue; }
        if ((m = /^control_text\s+-?\d+\s+-?\d+\s+(.*)$/i.exec(s))) {
          const label = m[1].trim().replace(/^"|"$/g, ''); if (!label) continue;
          if (type === 'title' && !title) { title = label; continue; }
          controls.push({ id, type, label, ...(KR_LABEL[label] ? { en: KR_LABEL[label] } : {}) });
        }
      }
      return { src: key, title, buttons: controls.filter((c) => c.type === 'button'), fields: controls.filter((c) => c.type !== 'button').map((c) => c.label) };
    });
    original.devTools = {
      effectTool: { note: 'The original in-client effect editor: toolbar Particle / Mesh / Decal / Effect, one editor window each (keyframed Size / Alpha / Color / Rotate with TimeType, Period, AnimTime), Open / Save of effect files and a VIEW window. It edits property/effect/effectdata + effectscene. Solo: /gm effect previews any scene; a full editor belongs to a later tools phase.', windows },
      testWindows: ['script/ui/game2/ui_testmanagewnd.txt', 'script/ui/game2/ui_testscene.txt', 'script/ui/game2/creditwnd/ui_testserverwnd.txt', 'script/ui/maptool/ui_testwnd.txt', 'script/ui/game2/ui_loginwnd_test_1.txt', 'script/ui/game2/ui_loginwnd_test_2.txt', 'script/lua/ui/common/loginwnd_test.lua'].filter(exists).map(K),
      testNote: 'Developer test windows: test_manWnd (a message box with Cancel), an empty 300x455 "test" scene window, a full-screen test-server splash, the map tool test window (8 guild-icon slots) and a test login with a "pantheon" test-server group selector (loginwnd_test.lua). No gameplay function; listed for completeness.',
    };
  }
  // ---- system variables + formula
  const systemVariables = [];
  for (const x of readCsvLines(K('share/system_variable.csv')).slice(1)) if (x.length && /^\d+$/.test(x[0])) {
    const i = +x[0]; const en = SYSVAR_EN[i];
    systemVariables.push({ index: i, value: num(x[1]), descKr: x.slice(2).join(','), desc: en?.[0] ?? null, ref: en?.[1] ?? null });
    if (!en) soft(`system variable ${i} has no English gloss`);
  }
  const formula = [];
  for (const key of ['share/formula.ini', 'share/formulaex.ini']) if (exists(key)) for (const [k, v] of parseCommaIni(decodeText(readKey(K(key))))) formula.push({ key: k, value: v, src: key });

  // ================================================================ validate the command registry
  const lists = {
    monsters: { file: 'gamedata/gmcommands_monsters.json', path: 'monsters', fields: 'monsterFields', count: monsters.length, alt: 'gamedata/monsters.json#monsters (full records)' },
    itemSets: { file: 'gamedata/gmcommands_monsters.json', path: 'itemSets', fields: 'itemSetFields', count: Object.keys(itemSets).length },
    mapDrops: { file: 'gamedata/gmcommands_monsters.json', path: 'mapDrops', fields: 'mapDropFields', count: Object.keys(mapDrops).length },
    classDrops: { file: 'gamedata/gmcommands_monsters.json', path: 'classDrops', fields: 'classDropFields', count: classDrops.length },
    items: { file: 'gamedata/gmcommands_items.json', path: 'items', fields: 'itemFields', count: items.length, alt: 'gamedata/items*.json when the items builder has run (full records)' },
    itemOptions: { file: 'gamedata/gmcommands_items.json', path: 'options', fields: 'optionFields', count: itemOptions.length },
    sockets: { file: 'gamedata/gmcommands_items.json', path: 'sockets', fields: 'socketFields', count: sockets.length },
    maps: { file: 'gamedata/gmcommands_lists.json', path: 'maps', count: maps.length },
    locations: { file: 'gamedata/gmcommands_lists.json', path: 'locations', fields: 'locationFields', count: locations.length },
    dungeons: { file: 'gamedata/gmcommands_lists.json', path: 'dungeons', count: dungeons.length, alt: 'gamedata/dungeons.json#dungeons (entry rules, floors, keepers, kick points)' },
    npcs: { file: 'gamedata/gmcommands_lists.json', path: 'npcs', fields: 'npcFields', count: npcs.length, alt: 'gamedata/npcs.json#npcs' },
    skills: { file: 'gamedata/gmcommands_lists.json', path: 'skills', fields: 'skillFields', count: skills.length, alt: 'gamedata/skills.json#skills (full records: costs, levels, effects)' },
    quests: { file: 'gamedata/gmcommands_lists.json', path: 'quests', fields: 'questFields', count: quests.length, alt: 'gamedata/quests.json#quests (steps, objectives, rewards) + gamedata/dialogs.json' },
    effects: { file: 'gamedata/gmcommands_lists.json', path: 'effects', fields: 'effectFields', count: effects.length, alt: 'gamedata/skills_effects.json#scenes (playback records of the skill/status-referenced scenes)' },
    statuses: { file: 'gamedata/gmcommands_lists.json', path: 'statuses', fields: 'statusFields', count: statuses.length },
    classes: { file: 'gamedata/gmcommands_lists.json', path: 'classes', fields: 'classFields', count: classes.length, alt: 'gamedata/classes.json#classes' },
    emotes: { file: 'gamedata/gmcommands_lists.json', path: 'emotes', fields: 'emoteFields', count: emotes.length },
    chatTypes: { file: 'gamedata/gmcommands_lists.json', path: 'chatTypes', count: chatTypes.length },
    callGroups: { file: 'gamedata/gmcommands_lists.json', path: 'callGroups', fields: 'callGroupFields', count: callGroups.length },
    contents: { file: 'gamedata/gmcommands_lists.json', path: 'contents', count: contentNames.length },
    skies: { file: 'gamedata/gmcommands_lists.json', path: 'skies', count: skies.length },
    gmBuffs: { file: 'gamedata/gmcommands.json', path: 'original.gmBuffs.buffs', count: gmBuffs.length },
    gmSupply: { file: 'gamedata/gmcommands.json', path: 'original.gmSupply.entries', count: gmSupply.length },
    oxQuestions: { file: 'gamedata/gmcommands.json', path: 'original.oxQuiz.questions', fields: ['index', 'question', 'answer', 'solution'], count: original.oxQuiz.questions.length },
    systemVariables: { file: 'gamedata/gmcommands.json', path: 'systemVariables', count: systemVariables.length },
    formula: { file: 'gamedata/gmcommands.json', path: 'formula', count: formula.length },
    mapToolCommands: { file: 'gamedata/gmcommands.json', path: 'original.mapTool.commands', count: original.mapTool.commands.length },
  };
  const evidenceCheck = { checked: 0, failed: [] };
  const formulaKeys = new Set(formula.map((f) => f.key));
  const privCols = new Set(original.privileges.columns);
  const checkEvidence = (cmd, [kind, ref]) => {
    evidenceCheck.checked++;
    let ok = false;
    switch (kind) {
      case 'file': ok = exists(ref); if (ok) K(ref); break;
      case 'string': { const [g, cc] = ref.split('|'); const [cate, code] = cc.split(':').map(Number); ok = St(g, cate, code) != null; break; }
      case 'item': ok = itemByIndex.has(ref); break;
      case 'monster': ok = monByIndex.has(ref); break;
      case 'npc': ok = npcByIndex.has(ref); break;
      case 'status': ok = statusByIndex.has(ref); break;
      case 'quest': ok = questByIndex.has(ref); break;
      case 'map': ok = mapByIndex.has(ref); break;
      case 'privilege': ok = privCols.has(ref); break;
      case 'sysvar': ok = systemVariables.some((v) => v.index === ref); break;
      case 'formula': ok = formulaKeys.has(ref); break;
      default: ok = false;
    }
    if (!ok) evidenceCheck.failed.push(`${cmd.id}: ${kind} ${ref}`);
    return ok;
  };
  const commands = COMMANDS.map((c) => {
    for (const a of c.args || []) {
      const t = ARG_TYPES[a.t]; if (!t) hard(`command ${c.id}: unknown arg type ${a.t}`);
      const ls = t?.list ? (Array.isArray(t.list) ? t.list : [t.list]) : [];
      for (const l of ls) if (!lists[l]) hard(`command ${c.id}: arg ${a.n} list ${l} undefined`); else if (!lists[l].count) soft(`command ${c.id}: list ${l} is empty`);
    }
    const evidence = (c.evidence || []).map((e) => ({ kind: e[0], ref: e[1], ok: checkEvidence(c, e) }));
    const out = { id: c.id, category: c.cat, origin: c.origin, syntax: c.syntax, aliases: c.aliases || [], args: (c.args || []).map((a) => ({ name: a.n, type: a.t, ...(ARG_TYPES[a.t]?.list ? { list: ARG_TYPES[a.t].list } : {}), ...(a.opt ? { optional: true } : {}), ...(a.def !== undefined ? { default: a.def } : {}), ...(a.min !== undefined ? { min: a.min } : {}), ...(a.max !== undefined ? { max: a.max } : {}), ...(a.enum ? { enum: a.enum } : {}), ...(a.repeat ? { repeat: a.repeat } : {}), ...(a.d ? { desc: a.d } : {}) })),
      desc: c.desc };
    if (c.conf) out.confidence = c.conf;
    if (c.privilege) out.privilege = c.privilege;
    if (c.multiplayerOnly) out.multiplayerOnly = true;
    if (c.solo) out.solo = c.solo;
    if (evidence.length) out.evidence = evidence;
    return out;
  });
  const idSeen = new Set(); for (const c of commands) { if (idSeen.has(c.id)) hard(`duplicate command id ${c.id}`); idSeen.add(c.id); }
  const aliasSeen = new Map(); for (const c of commands) for (const a of [c.syntax.split(' ')[0] === '/gm' ? `/gm ${c.syntax.split(' ')[1]}` : null, ...c.aliases].filter(Boolean)) { if (aliasSeen.has(a) && aliasSeen.get(a) !== c.id) soft(`alias ${a} used by ${aliasSeen.get(a)} and ${c.id}`); aliasSeen.set(a, c.id); }
  if (evidenceCheck.failed.length) for (const f of evidenceCheck.failed) hard(`evidence not found: ${f}`);
  // privileges without a command
  for (const p of original.privileges.columns.slice(3)) if (!commands.some((c) => c.privilege === p)) hard(`privilege ${p} has no command`);

  // ================================================================ cross-reference validation
  const xref = {};
  const chk = (name, total, bad, ex) => { xref[name] = { total, unresolved: bad.length, ...(bad.length ? { examples: bad.slice(0, 10) } : {}) }; };
  chk('locations.map -> maps', locations.length, locations.filter((l) => !mapByIndex.has(l[2])).map((l) => l[0]));
  chk('dungeons.maps -> maps', dungeons.length, dungeons.filter((d) => d.maps.some((m) => !mapByIndex.has(m))).map((d) => d.index));
  chk('npcs.maps -> maps', npcs.length, npcs.filter((n) => n[3].some((m) => !mapByIndex.has(m))).map((n) => n[0]));
  chk('monsters.spawnMaps -> maps', monsters.length, monsters.filter((m) => m[8].some((x) => !mapByIndex.has(x)) || m[9].some((x) => !mapByIndex.has(x))).map((m) => m[0]));
  chk('monster drops -> items', monsters.reduce((s, m) => s + m[11].length, 0), [...dropMisses]);
  chk('gmBuffs.status -> statuses', gmBuffs.length, gmBuffs.filter((b) => !statusByIndex.has(b.status)).map((b) => b.menu));
  chk('gmSupply.item -> items', gmSupply.length, gmSupply.filter((s) => !itemByIndex.has(s.item)).map((s) => s.label));
  chk('gmNpcs -> npcs', original.gmNpcs.length, original.gmNpcs.filter((n) => !npcByIndex.has(n.npc)).map((n) => n.npc));
  chk('gmNpcMenus.map -> maps', gmNpcMenus.length, gmNpcMenus.filter((g) => !mapByIndex.has(g.map)).map((g) => g.map));
  chk('gmNpcMenus.menu -> messages', gmNpcMenus.reduce((s, g) => s + g.messages.length, 0), gmNpcMenus.flatMap((g) => g.messages.flatMap((m) => m.menu.filter((x) => !g.messages.some((y) => y.msg === x)).map((x) => `${g.dungeon}:${m.msg}->${x}`))));
  chk('gmNpcMenus.text resolved', gmNpcMenus.reduce((s, g) => s + g.messages.length, 0), gmNpcMenus.flatMap((g) => g.messages.filter((m) => m.text == null).map((m) => `${g.dungeon}:${m.msg}`)));
  chk('oxQuiz.questions O/X', original.oxQuiz.questions.length, original.oxQuiz.questions.filter((q) => !/^[OX]$/.test(q[2])).map((q) => q[0]));
  chk('sysvar refs', systemVariables.filter((v) => v.ref).length, systemVariables.filter((v) => v.ref).filter((v) => (v.ref === 'item' && !itemByIndex.has(v.value)) || (v.ref === 'monster' && !monByIndex.has(v.value)) || (v.ref === 'map' && !mapByIndex.has(v.value))).map((v) => `${v.index}=${v.value}`));
  chk('quests titled', quests.length, quests.filter((q) => !q[1]).map((q) => q[0]));
  chk('maps with landing point', maps.filter((m) => m.file).length, maps.filter((m) => m.file && !m.landing).map((m) => m.index));
  chk('maps.file exists', maps.filter((m) => !m.serverOnly).length, maps.filter((m) => m.missingFile).map((m) => m.missingFile));
  chk('callGroups.monsters -> monsters', callGroups.length, callGroups.filter((g) => g[5].some((m) => !monByIndex.has(m))).map((g) => `${g[0]}#${g[1]}`));
  chk('skills named', skills.length, skills.filter((s) => !s[1]).map((s) => s[0]));
  chk('mapDrops.map -> maps', Object.keys(mapDrops).length, Object.keys(mapDrops).filter((m) => !mapByIndex.has(+m)));
  chk('mapDrops sets -> itemSets', Object.values(mapDrops).reduce((s, d) => s + d.sets.length + d.fixedSets.length, 0), Object.entries(mapDrops).flatMap(([m, d]) => d.sets.concat(d.fixedSets).filter((s) => !itemSets[s[0]]).map((s) => `${m}:${s[0]}`)));
  chk('mapDrops fixed -> items', Object.values(mapDrops).reduce((s, d) => s + d.fixed.length, 0), Object.entries(mapDrops).flatMap(([m, d]) => d.fixed.filter((f) => !itemByIndex.has(f[0])).map((f) => `${m}:${f[0]}`)));
  chk('classDrops sets -> itemSets', classDrops.reduce((s, r) => s + Object.values(r[8]).flat().length, 0), classDrops.flatMap((r) => Object.values(r[8]).flat().filter((i) => !itemSets[i])));
  chk('classDrops.map -> maps', classDrops.length, classDrops.filter((r) => !mapByIndex.has(r[0])).map((r) => r[0]));
  chk('itemSets items -> items', Object.values(itemSets).reduce((s, v) => s + v.items.length, 0), [...new Set(Object.values(itemSets).flatMap((v) => v.items.map((i) => i[0]).filter((i) => !itemByIndex.has(i))))]);
  chk('sockets -> items', sockets.length, sockets.filter((s) => !itemByIndex.has(s[0])).map((s) => s[0]));
  chk('effects named + have a scene', effects.length, effects.filter((e) => !e[3] || !e[5].length).map((e) => e[0]));
  chk('reservedNames files', (original.reservedNames?.files || []).length, (original.reservedNames?.files || []).filter((f) => !f.gmWords.length).map((f) => f.src));
  chk('devTools effectTool windows titled', original.devTools.effectTool.windows.length, original.devTools.effectTool.windows.filter((w) => !w.title && !w.buttons.length).map((w) => w.src));
  if (SKJ) { const sk = new Set(Object.values(SKJ.skills || {}).map((s) => s.index)); chk('skills.json skills -> skills list', sk.size, [...sk].filter((i) => !skillByIndex.has(i))); }
  for (const [k, v] of Object.entries(xref)) if (v.unresolved && ['gmBuffs.status -> statuses', 'gmNpcs -> npcs', 'gmNpcMenus.menu -> messages', 'oxQuiz.questions O/X'].includes(k)) hard(`xref ${k}: ${v.unresolved} unresolved`);
  // every used data key exists
  const missingKeys = [...usedKeys].filter((k) => !exists(k));
  for (const k of missingKeys) hard(`JSON references a missing data key ${k}`);
  for (const k of usedKeys) if (k !== k.toLowerCase()) hard(`non-lower-case key ${k}`);

  // ================================================================ write
  const report = {
    counts: { commands: commands.length, byOrigin: countBy(commands, (c) => c.origin), byCategory: countBy(commands, (c) => c.category), items: items.length, itemOptions: itemOptions.length, sockets: sockets.length,
      monsters: monsters.length, monstersWithDrops: monsters.filter((m) => m[11].length).length, dropEntries: monsters.reduce((s, m) => s + m[11].length, 0), maps: maps.length, locations: locations.length, dungeons: dungeons.length,
      npcs: npcs.length, skills: skills.length, quests: quests.length, statuses: statuses.length, classes: classes.length, emotes: emotes.length, chatTypes: chatTypes.length, callGroups: callGroups.length,
      contents: contentNames.length, skies: skies.length, effects: effects.length, gmBuffs: gmBuffs.length, oxQuestions: original.oxQuiz.questions.length, systemVariables: systemVariables.length, formula: formula.length,
      gmItems: original.gmItems.length, gmMonsters: original.gmMonsters.length, gmNpcMenus: gmNpcMenus.length, privileges: original.privileges.columns.length - 3 },
    itemNameCheck: nameCheck, duplicateItemIndices: dupItems, landingFrom: landingSrc, upgradeMax, evidence: { checked: evidenceCheck.checked, failed: evidenceCheck.failed.length }, xref,
    joins, effectFiles: { mergedDefinitions: effectDup, byFiles: effectFileCombos }, clientScan: SCAN ? clientScan() : { ...CLIENT_SCAN_LAST, note: 'last recorded run; rebuild with --scan to repeat it' },
    dataKeys: usedKeys.size, missingDataKeys: missingKeys.length, hardFailures: hardFails.length, softWarnings: softWarns.slice(0, 50), softWarningCount: softWarns.length,
  };
  const main = {
    format: 'dekaron-solo/gmcommands@1', generatedBy: 'tools/build-gmcommands.mjs', doc: 'docs/formats/gmcommands.md',
    syntax: { prefix: '/gm', note: 'Canonical form "/gm <command> <args…>"; every alias is accepted too. Tokens are space separated; quote text with spaces ("…"). A list argument accepts the index or a (case-insensitive, unique-prefix) name. Player chat prefixes and emotes are parsed first (see chatTypes / emotes).',
      originalSpelling: 'The original server executable is not in the client, so the literal GM chat spelling cannot be recovered from the data. Commands with origin "original" reproduce operations whose UI/strings/tables ship in the client; "original-inferred" are capabilities the data proves; "player"/"maptool" spellings come verbatim from the data; "solo" are additions.' },
    argTypes: ARG_TYPES, lists, commands,
    original,
    systemVariables, formula,
    upgrade: { maxIndex: upgradeMax, byCodeRank: upgradeByCode, formulaexMaxUpgrade: formula.find((f) => f.key === 'byCanMaxUpgrade')?.value ?? null },
    report,
  };
  const listsOut = {
    format: 'dekaron-solo/gmcommands-lists@1', generatedBy: 'tools/build-gmcommands.mjs',
    maps, locationFields: ['index', 'name', 'map', 'x', 'y', 'dir', 'x2', 'y2', 'dir2'], locations, dungeons,
    npcFields: ['index', 'name', 'roles', 'maps', 'jobs'], npcs,
    skillFields: ['index', 'name', 'class (index into classes; "a|b" if shared)', 'maxLevel', 'weapon', 'desc', 'from (only on rows joined from gamedata/skills.json: "hidden" = placeholder skill with no skilldesc row)'], skills,
    questFields: ['index', 'title', 'parent', 'type', 'level', 'script', 'from (only on rows joined from gamedata/quests.json: "quests.json:<src>")'], quests,
    effectFields: ['key ("<cate>:<id>")', 'cate', 'id', 'name', 'files (effectFiles ids defining this key: visual file(s) + "snd" sound twin; play all)', 'scenes [[sceneId, name]]'],
    effectFiles: Object.fromEntries(['01', '02', '03', 'com', 'map', 'snd'].filter((f) => exists(`property/effect/effectscene.${f}.txt`)).map((f) => [f, `property/effect/effectscene.${f}.txt`])), effectCategories: Object.fromEntries(Object.entries(effectCates).map(([c, n]) => [c, { name: n, en: ({ 0: 'none', 1: 'monster', 3: 'sound', 4: 'game_sound', 5: 'game', 6: 'hit', 7: 'item', 8: 'ui', 9: 'light', 10: 'weather', 11: 'condition', 12: 'event', 100: 'skill' })[c] ?? n, count: effects.filter((e) => e[1] === +c).length }])), effects,
    statusFields: ['index', 'desc', 'type', 'group', 'icon', 'maxStack', 'style', 'mapMoveDelete', 'options [[code,value]]'], statuses,
    classFields: ['index', 'code', 'name', 'playable', 'sex'], classes,
    emoteFields: ['motion', 'motionType', 'name', 'slash (EU)', 'slashKr'], emotes, chatTypes,
    callGroupFields: ['file', 'callIndex ("rN" = random call N)', 'maps', 'rows', 'monsterCount', 'monsters'], callGroups,
    contents: contentNames, contentSchedule: contents, skies,
  };
  const itemsOut = {
    format: 'dekaron-solo/gmcommands-items@1', generatedBy: 'tools/build-gmcommands.mjs',
    itemFields: ITEM_FIELDS.concat(['nameKr (only when the csv name is Korean and differs, else null/absent)', 'csvOnly (1 = in the csv tables but not in item.dat: not loadable by the client)']),
    src: 'share/item/item.dat + share/item/itemevent/itemevent.dat (565-byte records: u32 index @128, u32 rank @137, u32 type @141, u8 code @145, u32 quality @155, u32 trade @186, u16 reqLv @190, u32 price @194, wchar nameKey @204 -> script/lines_eu); job mask + stack from the csv row of the same index',
    tables: itemTables, items,
    optionFields: ['index', 'level', 'type', 'desc', 'min', 'max', 'limit', 'table'], options: itemOptions,
    socketFields: ['index', 'desc', 'itemName'], sockets,
  };
  const monOut = {
    format: 'dekaron-solo/gmcommands-monsters@1', generatedBy: 'tools/build-gmcommands.mjs', src: 'gamedata/monsters.json (tools/build-monsters.mjs) + gamedata/gmcommands_items.json names',
    monsterFields: ['index', 'name', 'level', 'hp', 'rank', 'role', 'exp', 'aggressive', 'spawnMaps', 'callMaps', 'money [min,max,chance]', 'drops [[item, chance(, min, max)]]', 'moneyGroups', 'dropSets [[set,ratio,socket]]', 'nameKr'],
    dropModel: 'Per kill each item-set slot rolls ratio/100000; a set that fires yields one item picked by DropRatio/TotalDropRatio. chance = P(item at least once per kill), combined over slots as 1-prod(1-p). Fixed items: chance 1. Rates before GM drop events / formula multipliers. The per-monster list is the monster\'s own table only: add mapDrops[<map of the kill>] (unless the monster is in its exclude list) and, when that map row has classCheck, the classDrops rows of that map whose level range contains the monster level.',
    monsters,
    itemSetFields: ['name (Korean designer label)', 'total (per 100000)', 'items [[item, dropRatio, magicRatio|stackMin, nobleRatio|stackMax, divineRatio]] (trailing zeros trimmed)'], itemSets,
    mapDropFields: { money: ['countMin', 'countMax', 'min', 'max', 'rate/100000'], sets: ['set', 'ratio/100000'], fixed: ['item', 'stack', 'countMin', 'countMax', 'ratio/100000'], fixedSets: ['set', 'countMin', 'countMax', 'ratio/100000'] }, mapDrops,
    classDropFields: ['map', 'levelMin', 'levelMax', 'levelCap', 'subNo', 'monster (0 = any)', 'rate/100000', 'classRate/100000 (share for the killer\'s own class)', 'byClass {classIndex: [itemSet indices]} (Class_<class>_<1..10> hold ITEM SET indices, e.g. "스마트무기" smart-weapon sets)'], classDrops,
  };
  fs.mkdirSync(OUT, { recursive: true });
  const w = (f, o) => { const s = PRETTY ? JSON.stringify(o, null, 1) : JSON.stringify(o); fs.writeFileSync(path.join(OUT, f), s); return s.length; };
  const sizes = { 'gmcommands.json': w('gmcommands.json', main), 'gmcommands_lists.json': w('gmcommands_lists.json', listsOut), 'gmcommands_items.json': w('gmcommands_items.json', itemsOut), 'gmcommands_monsters.json': w('gmcommands_monsters.json', monOut) };

  // ================================================================ summary
  log(`\ncommands ${commands.length}: ${Object.entries(report.counts.byOrigin).map(([k, v]) => `${k} ${v}`).join(', ')}`);
  log(`lists: ${Object.entries(lists).map(([k, v]) => `${k} ${v.count}`).join(', ')}`);
  log(`evidence refs ${evidenceCheck.checked} (${evidenceCheck.failed.length} failed); data keys ${usedKeys.size} (${missingKeys.length} missing)`);
  log(`landing points: ${JSON.stringify(landingSrc)}`);
  for (const [k, v] of Object.entries(xref)) log(`xref ${k.padEnd(34)} ${v.total - v.unresolved}/${v.total}${v.unresolved ? `  e.g. ${JSON.stringify(v.examples.slice(0, 5))}` : ''}`);
  log(`sizes: ${Object.entries(sizes).map(([k, v]) => `${k} ${(v / 1024).toFixed(0)} KB`).join(', ')}`);
  if (softWarns.length) { log(`soft warnings ${softWarns.length}:`); for (const s of softWarns.slice(0, 20)) log(`  - ${s}`); }
  if (SPOT) spotCheck({ items, itemTables, maps, locations, statuses, quests, skills, monsters, gmBuffs, systemVariables, original, effects });
  log(`done in ${((Date.now() - t0) / 1000).toFixed(1)} s`);
  if (hardFails.length) { console.error(`HARD FAILURES ${hardFails.length}:`); for (const h of hardFails.slice(0, 40)) console.error(`  ! ${h}`); process.exit(1); }
}

function countBy(a, f) { const o = {}; for (const x of a) { const k = f(x); o[k] = (o[k] || 0) + 1; } return o; }

/** --scan: byte-scan every non-media file of the client for GM command tokens (ascii case-insensitive + utf-16le). */
const SCAN_TOKENS = ['/gm', 'gmcmd', 'gm_cmd', 'gmcommand', 'makeitem', 'createitem', 'callmonster', 'call_monster', 'summonmonster', '/call ', '/move ', '/warp', '/level', '/item ',
  'cheat', '/notice', 'gmtool', 'gm tool', '/kick', '/ban', '/mute', '/invisible', '/invincible', '/goto', '/recall', '/summon', 'admincommand', '/admin', 'setlevel', 'addexp', '/exp ', '/money', '/dil '];
function clientScan() {
  const SKIP = new Set(['.dds', '.tga', '.bmp', '.jpg', '.png', '.wav', '.ogg', '.mp3', '.x']);
  const files = []; const walk = (d) => { for (const e of fs.readdirSync(d, { withFileTypes: true })) { const p = path.join(d, e.name); if (e.isDirectory()) walk(p); else files.push(p); } };
  walk(DATA);
  const needles = SCAN_TOKENS.map((t) => [t, Buffer.from(t, 'latin1'), Buffer.from(t, 'utf16le')]);
  const hits = Object.fromEntries(SCAN_TOKENS.map((t) => [t, { count: 0, files: [] }]));
  let scanned = 0, bytes = 0;
  for (const f of files) {
    if (SKIP.has(path.extname(f).toLowerCase())) continue;
    let b; try { b = fs.readFileSync(f); } catch { continue; }
    scanned++; bytes += b.length;
    const lb = Buffer.from(b); for (let i = 0; i < lb.length; i++) { const c = lb[i]; if (c >= 65 && c <= 90) lb[i] = c + 32; }
    const rel = path.relative(DATA, f).replace(/\\/g, '/').toLowerCase();
    for (const [t, a, u] of needles) {
      let n = 0; for (const nd of [a, u]) { let i = lb.indexOf(nd); while (i >= 0) { n++; i = lb.indexOf(nd, i + nd.length); } }
      if (n) { hits[t].count += n; if (hits[t].files.length < 8) hits[t].files.push(rel); }
    }
  }
  return { ran: new Date().toISOString().slice(0, 10), files: files.length, scanned, bytes, skipped: [...SKIP].join(' '), encodings: ['ascii (case-insensitive)', 'utf-16le'], hits,
    interpretation: `(hand review of the ${CLIENT_SCAN_LAST.ran} run; re-check the hit files if the counts changed) ${CLIENT_SCAN_LAST.result}` };
}

/** --spot: print 10 entries next to the raw source line they were built from, for a hand check. */
function spotCheck(D) {
  const rawLine = (key, pred) => { const rows = readCsvLines(key); const i = rows.findIndex(pred); return i >= 0 ? `line ${i}: ${rows[i].join(',').slice(0, 160)}` : 'not found'; };
  const pick = (a, f) => a.find(f);
  const out = [];
  const it1 = pick(D.items, (x) => x[0] === 63041); out.push(['item 63041', it1, rawLine('share/item/itemweapon.csv', (r) => r[0] === '63041')]);
  const it2 = pick(D.items, (x) => x[0] === 1757142); out.push(['item 1757142', it2, rawLine('share/item/itemcash.csv', (r) => r[0] === '1757142')]);
  const mp = pick(D.maps, (m) => m.index === 22); out.push(['map 22', mp, rawLine('share/maplist.csv', (r) => r[0] === '22')]);
  const lc = pick(D.locations, (l) => l[2] === 150); out.push([`location ${lc?.[0]}`, lc, rawLine('share/arrange/location.csv', (r) => r[0] === String(lc?.[0]))]);
  const st = pick(D.statuses, (s) => s[0] === 7487); out.push(['status 7487', st, rawLine('share/skill/status.csv', (r) => r[0] === '7487')]);
  const q = pick(D.quests, (s) => s[0] === 10030); out.push(['quest 10030', q, 'title from QUEST strings cate 10030 code 11']);
  const sk = pick(D.skills, (s) => s[0] === 1); out.push(['skill 1', sk, rawLine('script/skilldesc/knight.csv', (r) => r[0] === '1' && r[1] === '1')]);
  const mo = pick(D.monsters, (m) => m[0] === 102); out.push(['monster 102', mo && [...mo.slice(0, 11), `${mo[11].length} drops, top ${JSON.stringify(mo[11].slice(0, 3))}`], rawLine('share/item/monsterdropitemtable.csv', (r) => r[0] === '102')]);
  out.push(['gmBuff 9604', D.gmBuffs.find((b) => b.menu === 9604), rawLine('share/dungeon/dungeon_654_oxquiz_dk.csv', (r) => r[0] === '9560')]);
  out.push(['sysvar 58', D.systemVariables.find((v) => v.index === 58), rawLine('share/system_variable.csv', (r) => r[0] === '58')]);
  if (D.effects) { const ef = D.effects.find((e) => e[0] === '1:2'); const lines = decodeText(readKey('property/effect/effectscene.01.txt')).split(/\r\n|\n|\r/); const li = lines.findIndex((l) => /^\s*id\s+2\s*$/.test(l)); out.push(['effect 1:2', ef, li >= 0 ? `line ${li}: ${lines.slice(li - 1, li + 2).map((s) => s.trim()).join(' | ')}` : 'not found']); }
  console.log('\n--- spot check (JSON entry | raw source) ---');
  for (const [k, j, r] of out) console.log(`${k}\n   json: ${JSON.stringify(j)?.slice(0, 300)}\n   raw:  ${r}`);
}

if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) main();
