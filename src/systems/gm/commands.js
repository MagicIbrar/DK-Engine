// Every GM command of gamedata/gmcommands.json (85: the GM Tool privileges, the GM NPC functions, the console, the
// capabilities the data proves and the solo tools) plus the panel extras, implemented against the game's systems.
// Each handler: async (a /* coerced args */, c /* context: {game, gm, say, fail, line} */) -> string | void.
// Returning a string prints it; throwing / c.fail(...) prints the client's 160:62 "Failed to execute the command.".
import { grantExp, allocateStat, maxLevelOf, expToNext, formulaOf } from '../../game/progression.js';
import { kill } from '../../game/combat.js';
import { gmData } from './data.js';
import { spawnMonsterNow, spawnNpcNow, scatter, teleport, killAll, respawnAll, applySky } from './worldtools.js';
import { makeItem, ownedItems, GRADES } from './itemgen.js';
import { dropTable, whoDrops, simulate, pct } from './drops.js';
import {openBuilder} from './builders.js';

const num = (v, d = 0) => { const x = Number(v); return Number.isFinite(x) ? x : d; };
const onOff = (v, cur) => (v === 'on' ? true : v === 'off' ? false : !cur);
const fmt = n => Number(n || 0).toLocaleString('en-US');
// weather effect 100 scenes of the light files (life/weather.js): none = the map's own weather keys, clear = forced off
const WEATHER = { none: null, off: null, clear: 0, rain: 1, snow: 2, sandstorm: 3, sand: 3, shower: 4, blossom: 5, pollen: 6, festival: 6 };
export const WEATHER_NAMES = ['none', 'clear', 'rain', 'snow', 'sandstorm', 'shower', 'blossom', 'pollen'];

/** Player cell position helpers. */
const here = g => ({ map: g.world?.info?.index, x: g.player?.x, z: g.player?.z });

// The event scheduler often opens a lobby/NPC instead of starting a run. Reject names it cannot route.
async function requestEvent(c, name) {
  const ev = c.game.eventsSystem;
  if (!ev?.start) return c.fail('The events system is not installed.');
  name = String(name || '').trim();
  if (/draco|zuto|dk ?square|battle ?royal|guild|3v3|terra/i.test(name)) return c.fail(`${name}: multiplayer matches are unavailable in solo mode.`);
  const known = /dead ?front|ice ?castle|field ?boss|mitera|colosseum ?arena|infinite/i.test(name);
  const words = s => String(s || '').toLowerCase().replace(/[^a-z0-9 ]/g, ' ').split(/\s+/).filter(w => w && !['the', 'of'].includes(w));
  const A = words(name);
  const map = [...(c.game.data?.maps?.values?.() || [])].find(row => {
    const B = words(row.Name);
    return A.length && B.length && !/test/i.test(row.Name) && (A.join('') === B.join('') || [...A].sort().join() === [...B].sort().join() || B.join(' ').includes(A.join(' ')));
  });
  if (!known && !map) return c.fail(`No event or map matches "${name}".`);
  await ev.start(name, { entry: 'gm' });
  return `${name}: entry requested (follow the lobby or NPC options to begin).`;
}

// ------------------------------------------------------------------------------------------ extra commands
/** Commands the panel adds (registry shape; origin 'solo-extra'). */
export const EXTRA = [
  { id: 'help', category: 'console', origin: 'solo-extra', syntax: '/gm help [command]', args: [{ name: 'command', type: 'text', optional: true }], desc: 'List the GM commands or show one command\'s syntax.' },
  { id: 'panel', category: 'console', origin: 'solo-extra', syntax: '/gm panel [tab]', args: [{ name: 'tab', type: 'text', optional: true }], desc: 'Open the GM panel (F10 or Ctrl+`). Tabs: commands monsters items teleport npcs character quests world drops tools.' },
  { id: 'gmmode', category: 'console', origin: 'solo-extra', syntax: '/gm gmmode [on|off]', args: [{ name: 'state', type: 'enum', enum: ['on', 'off'], optional: true }], desc: 'GM mode: [GM] name tag and the GM-only NPCs (Operation Assistant, OX Start Stone, Provide Item).' },
  { id: 'weatherfx', category: 'world', origin: 'solo-extra', syntax: '/gm weatherfx <none|clear|rain|snow|sandstorm|shower|blossom|pollen>', aliases: ['/gm rain'], args: [{ name: 'weather', type: 'enum', enum: WEATHER_NAMES }], desc: 'Force the weather effect (effect 100 scenes 1-6 of the light files); clear = no weather, none = the map\'s own weather.' },
  { id: 'event', category: 'world', origin: 'solo-extra', syntax: '/gm event <name>', aliases: ['/gm startevent'], args: [{ name: 'name', type: 'text' }], desc: 'Start any event now (Dead Front, Ice Castle, Field Boss, Colosseum Arena, Infinite Battle, ... or a timetable row name).' },
  { id: 'viewer', category: 'view', origin: 'solo-extra', syntax: '/gm viewer [monster|npc|class|item] [id]', args: [{ name: 'kind', type: 'enum', enum: ['monster', 'npc', 'class', 'item', 'target'], optional: true }, { name: 'id', type: 'int', optional: true }], desc: 'Open the model viewer (tools/viewer.html) on a monster / NPC / class / item model, or the current target.' },
  { id: 'save', category: 'info', origin: 'solo-extra', syntax: '/gm save <export|import|edit|now>', args: [{ name: 'action', type: 'enum', enum: ['export', 'import', 'edit', 'now'] }], desc: 'Save tools: export the character as a .json file, import one, edit it as JSON, or save now.' },
  { id: 'pos', category: 'info', origin: 'solo-extra', syntax: '/gm pos', aliases: ['/gm where', '/gm loc'], args: [], desc: 'Print the map and cell position.' },
  { id: 'grade', category: 'character', origin: 'solo-extra', syntax: '/gm grade <points>', args: [{ name: 'points', type: 'int', min: 0 }], desc: 'Set the character\'s grade points (trans-up stage source).' },
  { id: 'vip', category: 'item', origin: 'solo-extra', syntax: '/gm vip <set|add> <amount>', args: [{ name: 'mode', type: 'enum', enum: ['set', 'add'] }, { name: 'amount', type: 'int', min: 0, max: 1000000000 }], desc: 'VIP Points editor (the VIP Shop currency). No game data grants VIP Points, so a GM sets or adds them; online the server keeps the balance.' },
  { id: 'monstertune', category: 'monsters', origin: 'solo-extra', syntax: '/gm monstertune <monster ID> <hp|attack|drop> <factor>', args: [{name:'monsterId',type:'int',min:1},{name:'stat',type:'enum',enum:['hp','attack','drop']},{name:'factor',type:'float',min:.1,max:10}], desc: 'Shared server: tune a monster type’s HP, attack or item-drop chance. Factor 1 restores the original value; restart clears runtime tuning.' },
  { id: 'monsterloot', category: 'drops', origin: 'solo-extra', syntax: '/gm monsterloot <monster ID> <item ID> <chance per 100000> [count]', args: [{name:'monsterId',type:'int',min:1},{name:'itemId',type:'int',min:1},{name:'chance',type:'int',min:0,max:100000},{name:'count',type:'int',min:1,max:99,optional:true}], desc: 'Shared server: add or replace one monster-specific item drop. Chance 0 removes it; restart restores original tables.' },
  // GM event prizes (src/config/engine-chosen-gm-prize.js): makeitem's arguments after one online character name.
  { id: 'giveitem', category: 'item', origin: 'solo-extra', syntax: '/gm giveitem <character> <item> [count=1] [upgrade=0] [sockets=0] [option value]…', args: [{name:'player',type:'player',desc:'online character name ("quotes" for spaces)'},{name:'item',type:'item',list:'items'},{name:'count',type:'int',optional:true,default:1,min:1,max:9999},{name:'upgrade',type:'int',optional:true,default:0,min:0,max:15,desc:'upgrade level (+N)'},{name:'sockets',type:'int',optional:true,default:0,min:0,max:4},{name:'options',type:'itemOption',list:'itemOptions',optional:true,repeat:6,desc:'up to 6 option index + value pairs'}], desc: 'Shared server: create an item straight in a connected player\'s bag, e.g. a GM event prize such as Camouflage [Frontier] (1755139, Dead Island runs 4-6). Untradeable prizes work because nothing is traded; the player is told who granted it and every grant is recorded.' },
  // Lane 47: Global GM event commands (syntax = the Global client GM help strings); the shared host runs them
  // (server/world/gm-global-events.mjs). Shared-server only (online-support.js GLOBAL_EVENT_GM).
  { id: 'dkrpvp_create', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_create', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_create' },
  { id: 'dkrpvp_delete', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_delete [code]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_delete [code]' },
  { id: 'dkrpvp_applystart', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_applystart [teamname] [teammark] [teammarkbg]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_applystart [teamname] [teammark] [teammarkbg]' },
  { id: 'dkrpvp_applymember', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_applymember [membername] [membercharno] [memberuserno] [class] [grade] [world] [level]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_applymember [membername] [membercharno] [memberuserno] [class] [grade] [world] [level]' },
  { id: 'dkrpvp_selectteam', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_selectteam', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_selectteam' },
  { id: 'dkrpvp_createleague', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_createleague', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_createleague' },
  { id: 'dkrpvp_open', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_open [type] [group] [order]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_open [type] [group] [order]' },
  { id: 'dkrpvp_finish', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_finish [type] [group] [order]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_finish [type] [group] [order]' },
  { id: 'dkrpvp_setstatus', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_setstatus [start|apply|league|tournament|end] [end time]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_setstatus [start|apply|league|tournament|end] [end time]' },
  { id: 'dkrpvp_createtournament', category: 'world', origin: 'solo-extra', syntax: '/gm dkrpvp_createtournament [league group1] [league order1] [league team1] [league group2] [league order2] [league team2] [tournament group] [tournament order] [match time]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): dkrpvp_createtournament [league group1] [league order1] [league team1] [league group2] [league order2] [league team2] [tournament group] [tournament order] [match time]' },
  { id: 'set_dksquareinfo', category: 'world', origin: 'solo-extra', syntax: '/gm set_dksquareInfo [mode] [rank] [fightTime] [startPcCount] [maxPcCount] [LobbyIndex]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): set_dksquareInfo [mode] [rank] [fightTime] [startPcCount] [maxPcCount] [LobbyIndex]' },
  { id: 'guildwarhunting_open', category: 'world', origin: 'solo-extra', syntax: '/gm guildwarhunting_open [world index]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): guildwarhunting_open [world index]' },
  { id: 'guildwarhunting_ready', category: 'world', origin: 'solo-extra', syntax: '/gm guildwarhunting_ready [world index]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): guildwarhunting_ready [world index]' },
  { id: 'guildwarhunting_start', category: 'world', origin: 'solo-extra', syntax: '/gm guildwarhunting_start [world index]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): guildwarhunting_start [world index]' },
  { id: 'guildwarhunting_finish', category: 'world', origin: 'solo-extra', syntax: '/gm guildwarhunting_finish [world index]', args: [{ name: 'args', type: 'text', optional: true }], desc: 'Global GM event command (shared server): guildwarhunting_finish [world index]' },
];

// ------------------------------------------------------------------------------------------ handlers
export const HANDLERS = {
  // ===================================================================================== GM Tool (original)
  async notice(a, c) {
    const g = c.game;
    if (a.scope === 'clear') { c.gm.windows.hideNotice(); delete c.gm.st.mapNotices?.[here(g).map]; return 'Notice removed.'; }
    const text = String(a.text || '').trim();
    if (!text) return c.gm.windows.openNoticeEditor(a.scope);
    if (a.scope === 'map') (c.gm.st.mapNotices ||= {})[here(g).map] = text;
    c.gm.windows.showNotice(text);
    return a.scope === 'map' ? `Notice sent to map ${here(g).map} (shown again whenever you enter it).` : 'Notice sent to all.';
  },
  async mute(a, c) {
    const me = c.game.save?.name || '';
    if (a.player && me && a.player.toLowerCase() !== me.toLowerCase() && !/^(me|self|@)$/i.test(a.player)) {
      return `[${a.player}] is not connected to the game (single player: only your own chat can be restrained).`;
    }
    const min = num(a.minutes);
    c.gm.st.muteUntil = min > 0 ? Date.now() + min * 60000 : 0;
    return min > 0 ? `Chat restrained for ${min} minute(s).` : 'Chat restraint lifted.';
  },
  async shutdown(a, c) {
    const min = num(a.minutes, 5);
    if (min <= 0 && c.gm.shutdown) { c.gm.shutdown = null; return 'Shutdown cancelled.'; }
    c.gm.shutdown = { at: c.game.time + min * 60, lastMin: null };
    c.gm.tickShutdown(true);
    return `Shutdown in ${min} minute(s): the character is saved and returns to character select ("/gm shutdown 0" cancels).`;
  },
  async exprate(a, c) { return c.gm.setRate('exp', a.multiplier, a.minutes); },
  async droprate(a, c) { return c.gm.setRate('drop', a.multiplier, a.minutes); },
  async dilrate(a, c) { return c.gm.setRate('dil', a.multiplier, a.minutes); },
  async pcroomexp(a, c) {
    c.gm.st.pcRoom = num(a.percent);
    c.say(c.gm.text('normal', 1002, 4, 'Internet Cafe additional EXP: +20%').replace(/\+20\s*%/, `+${c.gm.st.pcRoom}%`).split('\n')[0]);
    return `PC-cafe EXP bonus: +${c.gm.st.pcRoom}%`;
  },
  async usercount(a, c) { return `Total users: 1 (single player) · characters on this PC: ${c.gm.characterCount()}`; },
  async mapusercount(a, c) {
    const g = c.game, m = a.map ? Number(a.map.id) : here(g).map;
    const on = m === here(g).map;
    const mons = on ? (g.spawner?.monsters || []).filter(x => !x.dead).length : 0;
    return `Map ${m} ${a.map?.name || g.world?.info?.name || ''}: ${on ? 1 : 0} user(s)${on ? ` · ${mons} monsters live · ${g.npcs.length} NPCs` : ''}`;
  },
  async usermonitor(a, c) { c.gm.windows.openSysinfo('monitor'); return null; },
  async userlog(a, c) {
    const n = Math.max(1, num(a.count, 50));
    const list = c.gm.eventLog.slice(-n);
    if (!list.length) return 'The log is empty.';
    for (const e of list) c.say(`${new Date(e.t).toLocaleTimeString()}  ${e.text}`);
    return `${list.length} of ${c.gm.eventLog.length} log entries.`;
  },
  async changescript(a, c) {
    const g = c.game, what = a.what || 'all';
    if (what === 'monsters') { if (!g.spawner?.start) return c.fail('No monster spawner is installed.'); g.spawner.start(g.world?.spawns || []); return 'Monster spawns restarted.'; }
    if (what === 'quests') { if (!g.quests?.engine) return c.fail('No quest system is installed.'); g.quests.engine.checkReset?.(); g.quests.notify?.('collect'); g.events.emit('quest:changed', { ids: [] }); return 'Quest state refreshed (periods checked, objectives recounted).'; }
    if (what === 'shops') return c.fail('Shop definitions are cached for this session. Reload the client to read changed shop files.');
    if (what === 'dungeons' || what === 'all') {
      const p = g.player;
      await g.enterMap(here(g).map, { x: p.x, z: p.z, dirDeg: p.yaw * 180 / Math.PI });
      return what === 'all' ? 'All scripts reloaded (the map was re-entered).' : 'Dungeon scripts reloaded (the map was re-entered).';
    }
    return null;
  },
  async resetmaxcount(a, c) {
    const s = c.game.save;
    const st = c.game.quests?.state;
    if (st?.period) st.period.c = {};
    if (s.orbis) s.orbis.day = null;
    if (s.dekapass) s.dekapass.day = 0;
    for (const k of Object.keys(s)) if (/entries|entrycount|dailycount/i.test(k) && s[k] && typeof s[k] === 'object') s[k] = {};
    return 'Per-day and limit counters reset (quest periods, Orbis of Destiny spins, Deka Pass day, dungeon entry counts).';
  },
  async sysvar(a, c) {
    const r = a.variable.raw;
    const old = c.gm.sysvar(r.index);
    (c.gm.st.sysvar ||= {})[r.index] = num(a.value);
    return `System variable ${r.index} "${r.desc}": ${old} -> ${num(a.value)} (stored override; server-only variables have no solo runtime consumer).`;
  },
  async formula(a, c) {
    const key = a.key.raw.key;
    const old = formulaOf(c.game.data)[key];
    (c.gm.st.formula ||= {})[key] = num(a.value);
    c.gm.applyFormula();
    return `Formula ${key}: ${old} -> ${num(a.value)}`;
  },
  async applyall(a, c) {
    c.gm.applyFormula();
    c.game.refreshPlayerStats?.(false);
    c.game.persist?.();
    const n = Object.keys(c.gm.st.formula || {}).length + Object.keys(c.gm.st.sysvar || {}).length;
    return `${n} override(s) saved; formula values applied. Server-only system variables remain stored overrides.`;
  },
  async siege(a, c) {
    const st = (c.gm.st.siege ||= { state: 'closed' });
    st.state = a.state === 'reset' ? 'closed' : a.state;
    if (a.state === 'open' || a.state === 'start') {
      await teleport(c.game, 23, null, null);
      return `Siege war ${a.state === 'open' ? 'application opened' : 'started'} (Siege map 23). Solo: there are no other guilds; the siege NPCs answer with the original texts.`;
    }
    return `Siege war ${a.state === 'end' ? 'ended' : 'reset'}.`;
  },
  async siegemonitor(a, c) {
    if (a.map) await teleport(c.game, a.map.id);
    c.gm.freecam.set(true);
    return 'Observer mode: free camera on (WASD/QE, right-drag to look, Shift fast; /gm freecam off to leave).';
  },
  async guildwarteleport(a, c) { await teleport(c.game, a.map.id); return `Guild war teleport: ${a.map.name}.`; },
  async partywar(a, c) {
    const ev = c.game.eventsSystem;
    if (!ev) return c.fail('The events system is not installed.');
    const name = a.content.raw.name;
    if (a.state === 'end') { if (ev.run) { ev.run.end('gm'); return `${name}: ended.`; } return `${name}: no event is running.`; }
    if (a.state === 'open') { ev.openTimetable(); return `${name}: contents timetable opened.`; }
    return requestEvent(c, name);
  },
  async partywarevent(a, c) {
    const ev = c.game.eventsSystem;
    if (!ev) return c.fail('The events system is not installed.');
    return requestEvent(c, a.content.raw.name);
  },
  async ai(a, c) {
    if (a.state === 'off') { c.gm.st.freeze = true; return 'Monster AI off (every monster stops).'; }
    if (a.state === 'on') { c.gm.st.freeze = false; return 'Monster AI on.'; }
    const { MonsterBrain } = await import('../../game/ai.js');
    let n = 0;
    for (const m of c.game.spawner?.monsters || []) if (!m.dead) { m.brain = new MonsterBrain(c.game, m); n++; }
    c.gm.st.freeze = false;
    return `Monster AI reloaded for ${n} monsters.`;
  },

  // ===================================================================================== GM NPC functions
  async mapbuff(a, c) {
    const g = c.game, b = a.buff.raw;
    if (!g.statuses) return c.fail('The skills system (statuses) is not installed.');
    g.statuses.removeGroup?.(g.player, 125, 99);
    g.statuses.add(g.player, b.status, (b.minutes || 30) * 60000, { source: g.player });
    c.say(c.gm.dungeonText(654, 9700, '[message] A status effect has been granted.'));
    return `${b.label}: ${b.statusName} for ${b.minutes || 30} minutes.`;
  },
  async oxentry(a, c) {
    c.gm.st.oxEntry = a.state === 'open';
    return c.gm.dungeonText(654, a.state === 'open' ? 9553 : 9554, a.state === 'open' ? 'Entry Allowed' : 'Entry Not Allowed');
  },
  async ox(a, c) { return c.gm.ox(a.action, a.question?.raw || null); },
  async supply(a, c) {
    const e = a.which.raw;
    if (e.kind !== a.kind) return c.fail(`"${e.label}" is a ${e.kind} entry.`);
    if (!e.item) return c.fail(`${e.label}: the item has no EU record (Darham).`);
    const r = await makeItem(c.game, { item: e.item, count: e.count || 1000 });
    return r.ok ? `${e.label}: ${r.message}` : c.fail(r.message);
  },
  async meister(a, c) {
    const g = c.game, eng = g.skills;
    g.save.meister = { ...(g.save.meister || {}), path: a.type };
    let n = 0;
    for (const s of eng?.list || []) if (s.tree?.window === 'meister' && s.tree.path === a.type && s.meister?.autoLearn && !eng.learnedLevel(s.index)) { eng.setLevel(s.index, 1, { silent: true }); n++; }
    eng?.refreshPassives?.();
    return `Meister path ${a.type}${n ? ` (${n} skills learned)` : ''}.`;
  },

  // ===================================================================================== console
  async console(a, c) { c.gm.windows.toggleConsole(); return null; },
  async sysinfo(a, c) { c.gm.windows.openSysinfo('info'); return null; },

  // ===================================================================================== spawning
  async callmonster(a, c) {
    const g = c.game, p = g.player;
    const count = Math.max(1, Math.min(200, num(a.count, 1)));
    const x = a.x != null ? num(a.x) + 0.5 : null, z = a.y != null ? num(a.y) + 0.5 : null;
    const base = x != null && z != null ? { x, z } : null;
    const pts = base ? scatter(g, base.x, base.z, count) : scatter(g, p.x, p.z, count).map((q, i) => (count === 1 && i === 0 ? (() => { const ang = p.yaw; return { x: p.x - Math.sin(ang) * 3, z: p.z - Math.cos(ang) * 3 }; })() : q));
    const id = Number(a.monster.id);
    const res = await Promise.all(pts.map(q => spawnMonsterNow(g, id, q.x, q.z)));
    const ok = res.filter(Boolean).length;
    if (!ok) return c.fail(`${a.monster.name} could not be spawned (no body / not in monster.dat).`);
    c.gm.log(`callmonster ${a.monster.name} x${ok}`);
    return `${a.monster.name} (Lv ${a.monster.raw.level}) x${ok} called${base ? ` at ${Math.floor(base.x)}, ${Math.floor(base.z)}` : ''}.`;
  },
  async callgroup(a, c) {
    const g = c.game, gr = a.group.raw;
    const mons = await (await import('../../engine/assets.js')).fetchJSON('/gamedata/monsters.json');
    const cs = mons.callSpawns?.[gr.file];
    const idx = String(gr.callIndex);
    let rows = [];
    if (cs?.rows) rows = cs.rows.filter(r => String(r[0]) === idx);
    if (!rows.length && /^r/i.test(idx) && cs?.random) rows = (cs.random.rows || []).filter(r => `r${r[0]}` === idx.toLowerCase());
    const mapOk = (gr.maps || []).includes(here(g).map);
    if (!mapOk && gr.maps?.length) await teleport(g, gr.maps[0]);
    let n = 0;
    const jobs = [];
    if (rows.length && rows[0].length >= 6) {
      for (const [, mon, x, y, cell, count] of rows) {
        for (let k = 0; k < Math.max(1, num(count, 1)); k++) {
          const r = num(cell);
          jobs.push(spawnMonsterNow(g, mon, num(x) + 0.5 + (r ? (Math.random() * 2 - 1) * r : 0), num(y) + 0.5 + (r ? (Math.random() * 2 - 1) * r : 0)));
        }
      }
    } else {
      // no positional rows (random call groups): around the player
      const p = g.player;
      for (const mon of gr.monsters || []) for (const q of scatter(g, p.x, p.z, 1)) jobs.push(spawnMonsterNow(g, mon, q.x, q.z));
    }
    n = (await Promise.all(jobs)).filter(Boolean).length;
    return `Call group ${a.group.name}: ${n} monster(s) spawned.`;
  },
  async spawnnpc(a, c) {
    const g = c.game, p = g.player;
    const x = a.x != null ? num(a.x) : p.x - Math.sin(p.yaw) * 2.5;
    const z = a.y != null ? num(a.y) : p.z - Math.cos(p.yaw) * 2.5;
    const dir = a.dir != null ? num(a.dir) : ((p.yaw * 180 / Math.PI) + 180) % 360;
    const npc = await spawnNpcNow(g, a.npc.id, x, z, dir);
    if (!npc) return c.fail(`${a.npc.name}: no NPC record.`);
    return `${a.npc.name} spawned at ${x.toFixed(1)}, ${z.toFixed(1)} (click it to talk).`;
  },
  async killall(a, c) {
    const r = a.radius != null ? num(a.radius) : Infinity;
    const n = killAll(c.game, r, a.drops !== false);
    return `${n} monster(s) killed${Number.isFinite(r) ? ` within ${r} cells` : ''}${a.drops === false ? ' (no drops)' : ''}.`;
  },
  async respawn(a, c) { const n = respawnAll(c.game); return `${n} empty spawn row(s) reset: the monsters come back now (rows far away load when you get near).`; },
  async freeze(a, c) { c.gm.st.freeze = onOff(a.state, c.gm.st.freeze); return `Monsters ${c.gm.st.freeze ? 'frozen' : 'unfrozen'}.`; },

  // ===================================================================================== items
  async makeitem(a, c) {
    const r = await makeItem(c.game, { item: a.item.id, count: a.count, upgrade: a.upgrade || null, sockets: a.sockets, options: (a.options || []).map(([row, v]) => [row, v]) });
    if (!r.ok) return c.fail(r.message);
    c.gm.log(`makeitem ${r.message}`);
    return r.message;
  },
  async dropitem(a, c) {
    const r = await makeItem(c.game, { item: a.item.id, count: a.count, to: 'ground' });
    return r.ok ? r.message : c.fail(r.message);
  },
  async dkc(a, c) {
    const v = String(a.amount || '').toLowerCase();
    if (/^(unlimited|inf|infinite|max|∞)$/.test(v)) c.gm.setCoins('unlimited');
    else { const n = Number(v.replace(/[,_]/g, '')); if (!Number.isFinite(n) || n < 0) return c.fail(null, 'invalid'); c.gm.setCoins(Math.floor(n)); }
    return `D-Shop coins: ${c.gm.coinsText()}.`;
  },
  async clearinv(a, c) {
    const sys = c.game.items;
    if (!sys?.bag) return c.fail('The items system is not installed.');
    const page = a.bag != null ? num(a.bag) - 1 : null;
    const list = sys.bag.list.filter(i => page == null || (i.page | 0) === page);
    for (const inst of [...list]) sys.removeInst(inst);
    return `${list.length} item(s) removed from ${page == null ? 'every bag' : `bag ${page + 1}`}.`;
  },
  async repairall(a, c) {
    // stringtable_trade 110:69 "This item has no durability to repair." (the repair NPC's answer)
    const t = await c.game.uiwin?.strings?.resolve?.({ group: 'NORMAL', cate: 110, code: 69 }).catch(() => null);
    return `${String(t || 'This item has no durability to repair.').replace(/\[Message\]\s*/, '')} (the items of this client carry no durability: nothing to repair.)`;
  },
  async itemedit(a, c) { c.gm.openPanel('items', { edit: true }); return null; },

  // ===================================================================================== teleport
  async move(a, c) {
    const x = a.x != null ? num(a.x) + 0.5 : null, z = a.y != null ? num(a.y) + 0.5 : null;
    let px = x, pz = z;
    if (px == null) { const L = a.map.raw.landing; if (L) { px = L[0] + 0.5; pz = L[1] + 0.5; } }
    const r = await teleport(c.game, a.map.id, px, pz, x == null && a.map.raw.landing ? a.map.raw.landing[2] : null);
    c.gm.log(`move ${a.map.name}`);
    return `Moved to ${a.map.name} (${Math.floor(r.x)}, ${Math.floor(r.z)}).`;
  },
  async goloc(a, c) {
    const L = a.location.raw;
    const r = await teleport(c.game, L.map, num(L.x) + 0.5, num(L.y) + 0.5, num(L.dir));
    return `Moved to ${L.name} (map ${L.map}, ${Math.floor(r.x)}, ${Math.floor(r.z)}).`;
  },
  async gotonpc(a, c) {
    const g = c.game, id = Number(a.npc.id);
    // current map first
    const live = g.npcs.find(n => Number(n.npcIndex) === id);
    if (live) { const ip = live.interactPoint; await teleport(g, here(g).map, ip.x, ip.z); return `Moved to ${a.npc.name}.`; }
    const pl = await c.gm.npcPlacement(id);
    if (!pl) return c.fail(`${a.npc.name} is not placed on any map.`);
    const dir = num(pl.dirDeg) * Math.PI / 180;
    await teleport(g, pl.map, pl.x - Math.sin(dir) * 1.4, pl.z - Math.cos(dir) * 1.4);
    return `Moved to ${a.npc.name} (map ${pl.map}).`;
  },
  async tpclick(a, c) { c.gm.st.tpclick = onOff(a.state, c.gm.st.tpclick); return `Ctrl+click teleport ${c.gm.st.tpclick ? 'on (Ctrl+left click on the ground or the minimap)' : 'off'}.`; },
  async unlockmaps(a, c) { c.gm.st.unlock = !c.gm.st.unlock; return `Map level limits and entry tickets ${c.gm.st.unlock ? 'ignored' : 'enforced'}.`; },
  async enterdungeon(a, c) {
    const d = c.game.dungeons;
    const r = a.dungeon.raw;
    const floor = Math.max(0, num(a.floor));
    if (d?.enterFloor) { await d.enterFloor(r.index, floor); return `Entering ${r.name}${floor ? ` floor ${floor + 1}` : ''}.`; }
    const map = r.maps?.[floor] ?? r.maps?.[0];
    if (map == null) return c.fail('The dungeon has no map.');
    await teleport(c.game, map);
    return `Moved to ${r.name} (map ${map}).`;
  },

  // ===================================================================================== character
  async level(a, c) {
    const g = c.game, s = g.save;
    const max = maxLevelOf(g.data);
    const target = Math.max(1, Math.min(max, num(a.level)));
    const from = num(s.level, 1);
    if (target > from) {
      // through the normal level-up path (stat / skill points, level-up boxes, gifts)
      let need = 0;
      for (let L = from; L < target; L++) need += expToNext(L, g.data);
      need -= num(s.exp);
      // exactly the EXP of those levels: no formula / event / premium multipliers on this grant
      const F = formulaOf(g.data); const saved = F.fMonEXPRatio;
      const mods = g.expModifiers; g.expModifiers = [];
      const er = g.settings.expRate; g.settings.expRate = 1;
      try { F.fMonEXPRatio = 1; c.gm._rawExp = true; grantExp(g, Math.max(1, need)); } finally {
        F.fMonEXPRatio = saved; g.expModifiers = mods; if (er === undefined) delete g.settings.expRate; else g.settings.expRate = er; c.gm._rawExp = false;
      }
      if (s.level > target) { s.level = target; if (g.player) g.player.level = target; }
      s.exp = 0;
    } else if (target < from) {
      const per = num(g.data?.classesFile?.statPointsPerLevel, 0) || formulaOf(g.data).byStatPointPerLevel || 5;
      s.level = target; s.exp = 0;
      s.statPoints = Math.max(0, num(s.statPoints) - (from - target) * per);
      s.skillPoints = Math.max(0, num(s.skillPoints) - (from - target));
      if (g.player) g.player.level = target;
      g.refreshPlayerStats?.(true);
      g.events.emit('stats', { level: target });
    }
    g.refreshPlayerStats?.(true);
    return `Level ${from} -> ${s.level}.`;
  },
  async exp(a, c) { const g = c.game; const got = grantExp(g, num(a.amount)); return `+${fmt(got)} EXP (level ${g.save.level}).`; },
  async dil(a, c) {
    const g = c.game, sys = g.items;
    const n = Math.floor(num(a.amount));
    if (sys) { const before = sys.dil; sys.dil = before + n; } else g.save.dil = Math.max(0, num(g.save.dil) + n);
    g.events.emit('dil', { amount: n, total: g.save.dil });
    return `DIL ${n >= 0 ? '+' : ''}${fmt(n)} -> ${fmt(g.save.dil)}.`;
  },
  async buff(a, c) {
    const g = c.game;
    if (!g.statuses) return c.fail('The skills system (statuses) is not installed.');
    const min = a.minutes != null ? num(a.minutes, 30) : 30;
    g.statuses.add(g.player, Number(a.status.id), min * 60000, { source: g.player });
    return `${a.status.name} (${min} min).`;
  },
  async god(a, c) { c.gm.st.god = onOff(a.state, c.gm.st.god); return `Invincible mode ${c.gm.st.god ? 'on' : 'off'}.`; },
  async hide(a, c) {
    c.gm.st.hide = onOff(a.state, c.gm.st.hide);
    if (c.gm.st.hide) for (const m of c.game.spawner?.monsters || []) if (m.brain?.target === c.game.player) m.brain._leash?.();
    return `Hidden ${c.gm.st.hide ? 'on: monsters never aggro or target you' : 'off'}.`;
  },
  async skill(a, c) {
    const eng = c.game.skills;
    if (!eng?.setLevel) return c.fail('The skills system is not installed.');
    const id = Number(a.skill.id);
    const s = eng.skillDef(id);
    if (!s) return c.fail(`${a.skill.name} is not a skill of this class.`);
    const lv = a.level != null ? num(a.level) : (s.levels?.length || 1);
    const got = eng.setLevel(id, lv);
    c.game.skillsUI?.refresh?.();
    return `${a.skill.name}: level ${got}.`;
  },
  async skillreset(a, c) {
    const eng = c.game.skills;
    if (!eng?.resetPoints) return c.fail('The skills system is not installed.');
    const back = eng.resetPoints('skill') + (eng.resetPoints('attribute') || 0);
    c.game.skillsUI?.refresh?.();
    return `Skills reset (${back} point(s) returned).`;
  },
  async statreset(a, c) {
    const g = c.game, s = g.save;
    const base = g.classDef?._base?.stats?.base || g.classDef?.stats?.base || { str: 5, dex: 5, con: 5, spr: 5 };
    let spent = 0;
    for (const k of ['str', 'dex', 'con', 'spr']) { spent += Math.max(0, num(s.stats?.[k]) - num(base[k])); }
    s.stats = { ...base };
    s.statPoints = num(s.statPoints) + spent;
    g.refreshPlayerStats?.(false);
    g.events.emit('stats', { reset: true });
    return `Stats reset (${spent} point(s) returned).`;
  },
  async quest(a, c) {
    const Q = c.game.quests;
    if (!Q) return c.fail('The quest system is not installed.');
    const id = Number(a.quest.id);
    if (a.action === 'start') { const r = Q.accept(id, { silent: false }); if (!Q.isActive(id)) Q.engine.st.active[id] = { s: new Array(10).fill(0), t: Date.now() }, Q.engine._changed(id); return `${a.quest.name}: started${r === false ? ' (forced)' : ''}.`; }
    if (a.action === 'complete') {
      if (Q.isActive(id)) {
        const q = Q.db?.quest?.(id) || Q.db?.get?.(id);
        const s = Q.engine.slots(id);
        if (s && q?.objectives) for (const o of q.objectives) if (o.slot != null) s[o.slot] = Math.max(num(s[o.slot]), num(o.count) || 1);
        const r = Q.claim(id, { silent: false });
        if (Q.isActive(id)) Q.setDone(id, (Q.engine.doneCount(id) || 0) + 1);
        return `${a.quest.name}: completed${r ? ' (rewards granted)' : ''}.`;
      }
      Q.setDone(id, (Q.engine.doneCount(id) || 0) + 1);
      return `${a.quest.name}: marked done.`;
    }
    if (a.action === 'reset') { Q.reset(id); return `${a.quest.name}: reset.`; }
    if (a.action === 'abandon') { if (!Q.isActive(id)) return `${a.quest.name} is not in progress.`; Q.abandon(id); if (Q.isActive(id)) { delete Q.engine.st.active[id]; Q.engine._changed(id); } return `${a.quest.name}: abandoned.`; }
    return null;
  },
  async queststate(a, c) {
    const Q = c.game.quests;
    if (!Q) return c.fail('The quest system is not installed.');
    if (!a.quest) {
      const act = Q.engine.activeIds();
      if (!act.length) return 'No quest in progress.';
      for (const id of act) { const r = await gmData.get('quests', id); c.say(`${id} ${r?.name || ''}: ${Q.isComplete(id) ? 'ready' : 'in progress'} [${(Q.engine.slots(id) || []).join(',')}]`); }
      c.gm.openPanel('quests');
      return `${act.length} quest(s) in progress.`;
    }
    const id = Number(a.quest.id);
    const st = Q.isActive(id) ? (Q.isComplete(id) ? 'in progress, complete (ready to claim)' : 'in progress') : Q.isDone(id) ? `done x${Q.engine.doneCount(id)}` : 'not started';
    c.gm.openPanel('quests', { quest: id });
    return `${id} ${a.quest.name}: ${st}${Q.isActive(id) ? ` slots [${(Q.engine.slots(id) || []).join(',')}]` : ''}.`;
  },
  async speed(a, c) { c.gm.st.speed = Math.max(0.1, Math.min(10, num(a.factor, 1))); return `Move speed x${c.gm.st.speed}.`; },
  async setstat(a, c) {
    const g = c.game, s = g.save, v = Math.max(0, Math.floor(num(a.value)));
    if (a.stat === 'points') s.statPoints = v;
    else { s.stats = { ...(s.stats || {}) }; s.stats[a.stat] = v; }
    g.refreshPlayerStats?.(false);
    g.events.emit('stats', { stat: a.stat });
    return `${a.stat.toUpperCase()} = ${v}.`;
  },
  async setclass(a, c) {
    const g = c.game, ci = Number(a.class.id);
    if (!g.data.classByIndex.get(ci)) return c.fail('Unknown class.');
    g.save.classIndex = ci;
    g.save.className = a.class.raw.name;
    g.save.skills = {};
    g.save.hotbar = [];
    g.persist();
    c.gm.reloadSoon(`Class changed to ${a.class.raw.name}: reloading the character...`);
    return null;
  },
  async heal(a, c) { const p = c.game.player; p.hp = p.maxHp; p.mp = p.maxMp; if (p.shield != null && p.maxShield) p.shield = p.maxShield; return 'HP / MP restored.'; },
  async revive(a, c) {
    const g = c.game, p = g.player;
    if (!p.dead) { p.hp = p.maxHp; return 'You are not dead (HP restored).'; }
    p.dead = false; p.hp = p.maxHp; p.mp = p.maxMp; p.lastCombat = null;
    p.play?.('idle', { loop: true });
    g.hud?.hideDeath?.(); g.uiwin?.close?.('death');
    g.events.emit('revive', { actor: p, gm: true });
    return 'Revived on the spot.';
  },
  async cooldowns(a, c) {
    const mode = a.mode || 'reset';
    if (mode === 'reset') { c.game.skills?.resetCooldowns?.(); c.gm.resetItemCooldowns(); return 'Cooldowns reset.'; }
    c.gm.st.noCooldowns = mode === 'off';
    if (c.gm.st.noCooldowns) c.game.skills?.resetCooldowns?.();
    return `Cooldowns ${c.gm.st.noCooldowns ? 'off' : 'on'}.`;
  },
  async infinitemp(a, c) { c.gm.st.infmp = onOff(a.state, c.gm.st.infmp); return `Infinite MP ${c.gm.st.infmp ? 'on' : 'off'}.`; },
  async onehit(a, c) { c.gm.st.onehit = onOff(a.state, c.gm.st.onehit); return `One-hit kills ${c.gm.st.onehit ? 'on' : 'off'}.`; },
  async noclip(a, c) { c.gm.st.noclip = onOff(a.state, c.gm.st.noclip); c.gm.applyWorldWraps(); return `No-clip ${c.gm.st.noclip ? 'on (walk through walls and blocked cells)' : 'off'}.`; },
  async allskills(a, c) {
    const eng = c.game.skills;
    if (!eng?.setLevel) return c.fail('The skills system is not installed.');
    let n = 0;
    for (const s of eng.list || []) {
      const d = eng.skillDef(s.index);
      if (!d || d.hidden) continue;
      const max = eng.maxLevelFor ? eng.maxLevelFor(d) : (d.levels?.length || 1);
      const lv = Math.max(1, Math.min(d.levels?.length || max || 1, max || d.levels?.length || 1));
      eng.setLevel(d.index, lv, { silent: true }); n++;
    }
    eng.refreshPassives?.();
    c.game.skillsUI?.refresh?.();
    return `${n} skills learned at their maximum level.`;
  },
  async grade(a, c) { const s = c.game.save; s.gradePoints = num(a.points); s.grade = s.grade ?? 0; c.game.events.emit('grade', { points: s.gradePoints }); return `Grade points ${s.gradePoints}.`; },
  async vip(a, c) {
    const s = c.game.save, n = Math.max(0, Math.floor(num(a.amount)));
    s.vipPoints = Math.min(1e12, a.mode === 'add' ? (Number(s.vipPoints) || 0) + n : n);
    c.game.events?.emit?.('dshop:coins', { vip: s.vipPoints });
    return `VIP Points: ${s.vipPoints}.`;
  },

  // ===================================================================================== world / view
  async freecam(a, c) {
    const on = c.gm.freecam.set(onOff(a.state, c.gm.freecam.on));
    return `Free camera ${on ? 'on (WASD move, Q/E down/up, right-drag look, wheel speed, Shift fast)' : 'off'}.`;
  },
  async time(a, c) {
    const g = c.game, t = String(a.hour || '').toLowerCase();
    const clock = g.life?.clock;
    const env = g.world?.environment;
    if (!clock && !env) return c.fail('No world clock or environment is loaded.');
    if (t === 'show') return `Time of day ${clock?.text?.() ?? Number(env?.hour ?? 0).toFixed(1)}${clock?.frozen != null ? ' (frozen)' : ''} · a day lasts ${clock?.dayMinutes ?? '?'} real minutes on this map.`;
    if (t === 'freeze') { const h = clock ? clock.hour : env?.hour; if (clock) clock.freeze?.(h); else if (env) env.fixedTime = env.time; return `Time frozen at ${Number(h).toFixed(1)} h.`; }
    if (t === 'resume' || t === 'reset') { if (clock) { clock.freeze?.(null); if (t === 'reset') clock.reset?.(); } else if (env) env.fixedTime = null; return 'Time runs again.'; }
    const m = /^(\d{1,2})(?::(\d{2}))?$/.exec(t);
    if (!m) return c.fail(null, 'invalid');
    const h = Math.max(0, Math.min(24, Number(m[1]) + (m[2] ? Number(m[2]) / 60 : 0)));
    if (clock) { if (clock.frozen != null) clock.freeze(h); else clock.setHour(h); } else if (env) env.setHour(h);
    return `Time of day ${String(Math.floor(h)).padStart(2, '0')}:${String(Math.round((h % 1) * 60)).padStart(2, '0')}.`;
  },
  async sky(a, c) {
    applySky(c.game, a.sky.raw.index === 0 && /none/i.test(a.sky.raw.desc) ? null : a.sky.raw.index);
    c.gm.st.sky = a.sky.raw.index;
    return `Sky: ${a.sky.raw.desc}.`;
  },
  async weatherfx(a, c) {
    const w = c.game.life?.weather;
    if (!w?.force) return c.fail('The life system (weather) is not installed.');
    const scene = WEATHER[a.weather] ?? null;
    w.force(scene);
    c.gm.st.weather = scene;
    return `Weather: ${a.weather}${scene == null ? ' (the map\'s own light keys)' : ''}.`;
  },
  async timescale(a, c) { c.gm.timescale = Math.max(0.05, Math.min(10, num(a.factor, 1))); return `Game speed x${c.gm.timescale}.`; },
  async showdebug(a, c) {
    if (a.layer === 'none') { c.gm.debug.toggle('none'); return 'Debug layers off.'; }
    const on = c.gm.debug.toggle(a.layer);
    return `Debug layer ${a.layer} ${on ? 'on' : 'off'}.`;
  },
  async hideui(a, c) { c.gm.hideUI(); return null; },
  async fps(a, c) { const on = c.gm.perf.set(!c.gm.perf.on); return `Performance overlay ${on ? 'on' : 'off'}.`; },
  async inspect(a, c) {
    const g = c.game, t = g.player.target;
    const lines = c.gm.inspect(t || g.player);
    for (const l of lines) c.say(l);
    return null;
  },
  async snapshot(a, c) { return c.gm.snapshot(a.action, a.name); },
    async mapevent(a, c) {
    const map = Number(a.map.id), code = num(a.code);
    // When code is a mapevent.csv script index (1..5), also start the Global cinematic runner.
    // Lane 64 bound indices 1..5 to map 706 (map-event-rules MAP_EVENT_BINDING); the GM starts by index directly (Global 0x05260021 body).
    if (code >= 1 && code <= 5 && c.game.mapEvent?.start) {
      const ok = c.game.mapEvent.start(code);
      if (ok) return `Map-event cinematic index ${code} started (map ${map} is display-only; Global binding map 706).`;
    }
    const t = await c.gm.dungeonTextAsync(map, code);
    if (!t) return c.fail(`DUNGEON string ${map}:${code} does not exist.`);
    c.game.dungeons?.notice?.(t);
    c.game.eventsSystem?.notice?.(t);
    c.game.events.emit('dungeon:notice', { text: t, flash: true });
    return `Map ${map} event ${code}: ${t.replace(/\s+/g, ' ').slice(0, 140)}`;
  },

  async effect(a, c) {
    const g = c.game;
    if (!g.effects?.play) return c.fail('The effect player (skills system) is not installed.');
    const e = a.effect.raw;
    const scene = a.sceneId != null ? num(a.sceneId) : (e.scenes?.[0]?.[0] ?? 1);
    const on = a.on || 'self';
    let where = g.player;
    if (on === 'target') where = g.player.target || g.player;
    if (on === 'ground') { const gp = g.pickGround?.({ x: g.input.mouse.nx, y: g.input.mouse.ny }); where = gp ? { x: gp.x, y: gp.y, z: gp.z } : g.player; }
    const h = g.effects.play(where, { cate: e.cate, id: e.id, scene }, {});
    if (!h) return c.fail(`Effect ${e.key} scene ${scene} has no playable units.`);
    return `Effect ${e.key} "${e.name}" scene ${scene} on ${on}.`;
  },
  async bgm(a, c) {
    const g = c.game;
    if (!g.audio?.playBGM || !g.audio?.stopBGM) return c.fail('The audio system is not installed.');
    const w = String(a.map?.name || a.map || '').toLowerCase();
    if (w === 'off' || a.mapRaw === 'off') { g.audio?.stopBGM?.(); return 'Music off.'; }
    g.audio?.playBGM?.(Number(a.map.id));
    return `Music: ${a.map.name}.`;
  },

  // ===================================================================================== info
  async droptable(a, c) {
    if (a.targetList === 'items') {
      const w = await whoDrops(a.target.id);
      c.say(`${a.target.name} (${a.target.id}) drops from ${w.monsters.length} monster(s), ${w.maps.length} map layer(s), ${w.sets.length} item set(s):`);
      for (const r of w.monsters.slice(0, 15)) c.say(`  ${r.monster.name} (${r.monster.id}, Lv ${r.monster.raw.level}): ${pct(r.p)}`);
      for (const r of w.maps.slice(0, 5)) c.say(`  every monster on map ${r.map}: ${pct(r.p)}`);
    } else {
      const t = await dropTable(a.target.id, { map: here(c.game).map, classIndex: c.game.save.classIndex, playerLevel: c.game.save.level });
      c.say(`${t.monster.name} (${t.monster.id}, Lv ${t.monster.raw.level}) drops ${t.items.length} item(s) on map ${t.map}:`);
      for (const m of t.money) c.say(`  DIL ${fmt(m.min)}-${fmt(m.max)}: ${pct(m.p)} [${m.layer}]`);
      for (const r of t.items.slice(0, 20)) c.say(`  ${r.name} (${r.item}): ${pct(r.p)} [${r.layers.join('+')}]`);
    }
    c.gm.openPanel('drops', { target: a.target, list: a.targetList });
    return null;
  },
  async simdrops(a, c) {
    const r = await simulate(c.game, a.monster.id, num(a.kills, 1000));
    if (!r) return c.fail(`${a.monster.name}: no drop table.`);
    c.say(`${a.monster.name} x${r.kills} kills on map ${r.map}: ${fmt(r.dil)} DIL, ${r.items.length} item kinds.`);
    for (const it of r.items.slice(0, 20)) c.say(`  ${it.name} (${it.item}): ${it.drops} drop(s), ${it.count} item(s)`);
    return null;
  },

  // ===================================================================================== player / map tool
  async emote(a, c) {
    if (!c.game.emote) return c.fail('The emotes (hud-options / life systems) are not installed.');
    c.game.emote(Number(a.emote.raw.motion), Number(a.emote.raw.motionType) || 0);
    return `Emote: ${a.emote.raw.name} (motion ${a.emote.raw.motion}).`;
  },
  async chat(a, c) {
    const t = a.chatType.raw;
    const g = c.game;
    const line = t.prefix ? `${t.prefix}${a.message}` : `${(t.shortcutsEn || [])[0] || '/normal'} ${a.message}`;
    g.chat?.send ? g.chat.send(line) : g.hud?.log?.(line, 'sys');
    return null;
  },
  async maptool(a, c) {
    const cmd = a.command.raw;
    const hub = c.game.mapBuilder || c.game.systems?.get?.('mapbuilder');
    if (hub?.command) return hub.command(cmd.name, a.args || '');
    // the map builder system (game.customMaps): load_map plays a custom map, every editing verb opens the editor
    const cm = c.game.customMaps;
    if (!cm) return c.fail(`${cmd.usage} - the map tool commands need the map builder system.`);
    const arg = String(a.args || '').trim().split(/\s+/)[0] || '';
    if (/^load_map$/i.test(cmd.name) && arg) {
      const e = cm.entry?.(arg) || (cm.list?.() || []).find(m => String(m.name || '').toLowerCase() === arg.toLowerCase());
      if (!e) return c.fail(`No custom map "${arg}" (${(cm.list?.() || []).map(m => m.name).join(', ') || 'none saved'}).`);
      const played=await cm.play(e.id ?? e.index ?? arg);if(played===false)return c.fail('The custom map could not be entered.');
      if (c.game.save?.authority === 'server') return e.server?`Entered published custom map ${e.name || arg} on the shared server.`:`Opened ${e.name || arg} in an isolated local preview. Shared world state is unchanged.`;
      return `Custom map ${e.name || arg} loaded.`;
    }
    await openBuilder(c.game,'mapbuilder');
    if(c.game.originalSceneEditor?.active)return `Editing current native field #${c.game.world.info.index} from your character. Height changes are shared until Save or Cancel. ${cmd.usage}`;
    return `Map Builder opened in this game session. Drafts remain local until published. ${cmd.usage}`;
  },

  // ===================================================================================== extras
  async help(a, c) {
    const w = String(a.command || '').trim().toLowerCase();
    if (w) {
      const cmd = gmData.command(w) || gmData.extra.get(w);
      if (!cmd) return c.fail(null, 'mode');
      c.say(`${cmd.syntax}${cmd.aliases?.length ? `   (${cmd.aliases.join(', ')})` : ''}`);
      if (cmd.desc) c.say(cmd.desc);
      return null;
    }
    const cats = new Map();
    for (const cmd of new Set([...gmData.commands, ...gmData.extra.values()])) { if (!cats.has(cmd.category)) cats.set(cmd.category, []); cats.get(cmd.category).push(cmd.id); }
    for (const [k, ids] of cats) c.say(`[${k}] ${ids.join(' ')}`);
    return '"/gm help <command>" shows one command. F10 opens the GM panel, ` the GM console.';
  },
  async panel(a, c) { c.gm.openPanel(a.tab || null); return null; },
  async gmmode(a, c) { c.gm.setGmMode(onOff(a.state, c.gm.st.mode)); return `GM mode ${c.gm.st.mode ? 'on' : 'off'}.`; },
  async event(a, c) {
    const ev = c.game.eventsSystem;
    if (!ev) return c.fail('The events system is not installed.');
    return requestEvent(c, a.name);
  },
  async viewer(a, c) {
    const g = c.game;
    let kind = a.kind || 'target', id = a.id;
    if (kind === 'target') {
      const t = g.player.target;
      if (t?.kind === 'monster') { kind = 'monster'; id = t.monsterIndex; } else if (t?.kind === 'npc') { kind = 'npc'; id = t.npcIndex; } else { kind = 'class'; id = g.save.classIndex; }
    }
    const url = c.gm.viewerUrl(kind, id);
    if (!url) return c.fail(`${kind} ${id} has no model in the client.`);
    window.open(url, '_blank');
    return `Model viewer: ${url}`;
  },
  async save(a, c) {
    if (a.action === 'now') { c.game.persist(); return 'Character saved.'; }
    if (a.action === 'export') { c.gm.exportSave(); return 'Save exported (.json download).'; }
    c.gm.openPanel('tools', { save: a.action });
    return null;
  },
  async pos(a, c) {
    const g = c.game, p = g.player;
    return `Map ${here(g).map} ${g.world?.info?.name || ''} · cell ${Math.floor(p.x)}, ${Math.floor(p.z)} (x ${p.x.toFixed(2)}, z ${p.z.toFixed(2)}, y ${(p.y || 0).toFixed(2)}) · facing ${Math.round(((p.yaw * 180 / Math.PI) % 360 + 360) % 360)}°`;
  },
};

export { GRADES, fmt, here };
