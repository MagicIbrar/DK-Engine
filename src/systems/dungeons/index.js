// Dungeons, instances and world travel (docs/formats/dungeons.md; gamedata/dungeons.json + dungeons_travel.json).
//
//   entry        entry NPCs (job 19 DUNGEON / 45 TROOP / 58 MINI / 34 RANDOM, JobIndex = dungeon index) and the entry
//                gates this system places for the 85 dungeons whose entry NPC the client does not place (at
//                entry.fallback = the KickTo point in front of the original entrance, unplacedNpcs[0] or the instance
//                portal "potal_enter"): "[Mission] I want to receive a mission." -> "Enter Dungeon" box (dungeonsend)
//                -> checks (missing floors, PvP-only arenas, level range, admission ticket, mounted) -> floor 0
//   instance     director.js plays each floor (countdown, time limit, waves, bricks, triggers, script NPCs, bosses,
//                clear / fail, transfer, next floor, KickTo); ui.js the original dungeon windows; uifx.js the UI flashes
//   travel       travel.js (teleport / return / portal / sky / siege NPCs, smart warp, return point, scripted warps)
//   zones        zones.js (mapredcell cell attributes + maplist flags, game.zones)
//   auto-find    findauto.js (game.findAuto click-to-travel; the dormant anti-macro check)
//   rewards      mapDrops (monsterdropitem_map.csv) on every kill of a map, trigger chests, Forbidden Fetters clear
//                EXP, Forgotten Shipwreck win / lose rewards, time-attack records
//
// Public API: game.dungeons = { ready, director, enter(id), enterFloor(id, floor), leave(), claim(map), release(map),
//   info(id), list(), current(), notice(text), travel, ui, uifx }.
// Hooks (runtime, no shared-file edits): game.windows.openNpc (dungeon / script / trigger NPCs), game.respawnTarget
// (death inside an instance respawns inside it), game.enterMap (instance teardown before the world changes),
// game.npcServices handlers (the quest system's NPC dialog; installed once every system is in).
import { loadData, D, dungeonOfMap, dungeonById, mapInfo, FOREIGN_KEEPERS, sysText, plain, location, startPos } from './data.js';
import { Director } from './director.js';
import { DungeonUI } from './ui.js';
import { DungeonDialog } from './dialog.js';
import { UIEffects } from './uifx.js';
import { Travel } from './travel.js';
import { Zones } from './zones.js';
import { FindAuto } from './findauto.js';
import { planFor } from './scripts.js';
import { pickRewardSlot } from './reward-slot.js';
import { Captcha } from './captcha.js';
import { loadStringTable, NPC_CONV, NPC_JOBTYPE } from '../../ui/strings.js';
import { fetchJSON } from '../../engine/assets.js';
import { dungeonGatePlacement } from '../../config/engine-chosen-karin-dungeon-gates.js';
import { dungeonEntranceCosts, selectDungeonRequirements } from '../../game/dungeon-admission-rules.js';
import { premiumDungeonFee } from '../../game/premium-dungeon-fees.js';
import { saveCharacter } from '../../game/save.js';
import { ItemDB } from '../items/db.js';
import { loadQuests, loadDialogs } from '../quests/data.js';
import { T as shopTables, loadDshop } from '../shops/common.js';

export const ENTRY_JOBS = new Set([19, 45, 58, 34]);
export const SCRIPT_JOBS = new Set([31, 80]);
export const TRAVEL_JOBS = new Map([[2, 'teleport'], [4, 'return'], [16, 'portal'], [21, 'siege'], [42, 'sky'], [127, 'siege'], [128, 'siege']]);
const GATE_NPC = 4001;           // "Tower of Spell" entry portal (shape potal_enter): the look of a generic entry gate
const RECORDS_KEY = 'dekaron-solo:dungeon-records';

const sys = {
  game: null, director: null, pending: null, ready: null, claimed: new Set(),
  ui: null, dialog: null, uifx: null, travel: null, zones: null, findauto: null, sound: null,
  gates: [], strings: { conv: null, jobtype: null },
  entryBusy: false, admission: null, admissionError: null,
};

// ============================================================================================ install
export async function install(game) {
  sys.game = game;
  sys.ui = new DungeonUI(sys);
  sys.dialog = new DungeonDialog(sys);
  sys.uifx = new UIEffects(game);
  sys.travel = new Travel(sys);
  sys.zones = new Zones(sys);
  sys.findauto = new FindAuto(sys);
  sys.captcha = new Captcha(sys);
  sys.ui.register();
  sys.travel.install();
  sys.zones.install();
  sys.findauto.install();
  sys.ready = loadData().catch(err => { console.error('[dungeons] data', err); return null; });
  fetchJSON('/gamedata/sound.json').then(s => { sys.sound = s; }).catch(() => {});
  Promise.all([loadStringTable(NPC_CONV), loadStringTable(NPC_JOBTYPE)]).then(([c, j]) => { sys.strings.conv = c; sys.strings.jobtype = j; }).catch(() => {});

  game.dungeons = {
    get ready() { return sys.ready; },
    get director() { return sys.director; },
    get admissionError() { return sys.admissionError; },
    current: () => (sys.director ? { map: sys.director.map, dungeon: sys.director.dungeonId, floor: sys.director.floor, phase: sys.director.phase } : null),
    enter: (id, opts) => requestEntry(String(id), null, opts),
    enterFloor: (id, floor) => enterFloor(String(id), Number(floor) || 0),
    leave: () => (sys.director ? leave(sys.director, 'leave') : null),
    claim: (map) => sys.claimed.add(Number(map)),
    release: (map) => sys.claimed.delete(Number(map)),
    info: (id) => dungeonById(id),
    list: () => Object.entries(D.dg?.dungeons || {}).map(([id, d]) => ({ id, name: d.name, keeper: d.keeper, floors: d.floors, levels: d.entry?.levels, playable: playable(id).ok })),
    notice: (t) => notice(t),
    travel: sys.travel, ui: sys.ui, uifx: sys.uifx, zonesSys: sys.zones, findAuto: sys.findauto,
    returnToBind: () => sys.travel.returnToBind(),
    canUseReturnScroll: () => game.zones?.canReturnScroll?.() !== false && !sys.director,
  };

  // --- hooks
  const win = game.windows;
  if (win?.openNpc && !win._dungeonsWrapped) {
    const orig = win.openNpc.bind(win);
    win._dungeonsWrapped = true;
    win.openNpc = (npc) => (handleNpc(npc) ? null : orig(npc));
  }
  if (typeof game.respawnTarget === 'function' && !game._dungeonsRespawn) {
    const orig = game.respawnTarget.bind(game);
    game._dungeonsRespawn = true;
    game.respawnTarget = (m) => (sys.director?.respawnPoint?.() || orig(m));
  }
  if (typeof game.enterMap === 'function' && !game._dungeonsEnterMap) {
    const orig = game.enterMap.bind(game);
    game._dungeonsEnterMap = true;
    game.enterMap = (...args) => { if (!game._loadingMap && sys.admission?.game !== game) teardown(); return orig(...args); };
  }
  game.events?.on?.('map', ({ index }) => { onMap(index).catch(err => console.error('[dungeons] map', err)); });
  game.events?.on?.('death', (e) => onDeath(e));
  game.events?.on?.('systems', () => { registerServices(); sys.zones._wrapSkills(); });
  registerServices();
}

export function update(dt, game) {
  if (!Number.isFinite(dt)) return;
  sys.uifx?.update(dt);
  sys._svcT = (sys._svcT || 0) - dt;
  if (sys._svcT <= 0) { sys._svcT = 2; if (game.npcServices && game.npcServices !== sys._servicesDone) registerServices(); }
  if (!game.world || game._loadingMap) return;
  try { sys.director?.update(dt); } catch (err) { console.error('[dungeons] director', err); }
  sys.ui?.update(dt);
  sys.zones?.update(dt);
  sys.findauto?.update(dt);
  sys.findauto?.tick(dt);
}

export function dispose() {
  teardown();
  sys.uifx?.dispose();
}

// ============================================================================================ map changes
function teardown() {
  if (sys.director) { try { sys.director.dispose(); } catch (err) { console.error(err); } sys.director = null; }
  sys.gates = [];
  sys.uifx?.clear();
  sys.dialog?.close();
}

const waitLoaded = async (g) => { for (let i = 0; i < 600 && g._loadingMap; i++) await new Promise(r => setTimeout(r, 50)); };

async function onMap(index) {
  const g = sys.game;
  await sys.ready;
  await waitLoaded(g);          // the 'map' event fires inside enterMap (before the warm-up); travel() needs it done
  const admission = sys.admission;
  // Loading emits 'map' before travel/storage finish. Do not publish a new
  // director or dispose the source entry gates for an uncommitted admission.
  if (admission?.game === g) {
    const accepted = await admission.settled;
    if (!accepted && index !== admission.origin.map) return;
  }
  if (!D.ready || g.world?.info?.index !== index) return;
  teardown();
  sys.zones.onMap(index);
  const pend = sys.pending;
  sys.pending = null;
  let dm = null;
  if (pend && Number(dungeonById(pend.id)?.floors?.[pend.floor]) === index) dm = { id: pend.id, floor: pend.floor };
  else {
    const own = dungeonOfMap(index);
    const kind = mapInfo(index)?.kind;
    if (own && kind === 'instance' && !FOREIGN_KEEPERS.has(own.dungeon.keeper) && !sys.claimed.has(index)) dm = { id: own.id, floor: own.floor };
  }
  if (dm && !sys.claimed.has(index)) {
    // enterMap falls back to the world's generic start point when the requested cell is blocked: re-place the
    // player at the floor start (same-map travel snaps to the nearest walkable cell)
    const want = pend?.pos || (g.save?.dungeon?.map !== index ? startPos(index) : null);
    if (want && g.player && Math.hypot(g.player.x - want.x, g.player.z - want.z) > 3) await g.travel(index, want);
    const d = new Director(sys, { map: index, dungeonId: dm.id, floor: dm.floor });
    sys.director = d;
    await d.start(planFor(index, d));
    if (sys.director !== d) return;
    save().dungeon = { id: dm.id, floor: dm.floor, map: index };
  } else {
    sys.ui.hideAll();
    if (save().dungeon) delete save().dungeon;
    await placeEntryGates(index);
  }
  // the smart-warp button on field / town maps (not inside instances)
  if (!sys.director && g.uiwin) g.uiwin.open('smartwarp_alarm'); else g.uiwin?.close('smartwarp_alarm');
  sys.findauto.onMap(index);
}

const save = () => sys.game.save || (sys.game.save = {});

// ============================================================================================ entry
/** Dungeons without a placed entry NPC get a gate at their fallback point (grouped per point). */
async function placeEntryGates(map) {
  const g = sys.game;
  const { NPC } = await import('../../actors/npc.js');
  const byPoint = new Map();
  for (const [id, d] of Object.entries(D.dg?.dungeons || {})) {
    const f = d.entry?.fallback;
    if (!f || Number(f.map) !== map || String(id).startsWith('m')) continue;
    // PvP-only arenas / siege castles have no solo content (their own NPCs answer with the client's texts)
    if (!playable(id).ok) continue;
    const target = dungeonGatePlacement(f, id);
    const k = `${target.x},${target.y}`;
    if (!byPoint.has(k)) byPoint.set(k, { x: target.x, y: target.y, relocated: target.relocated, ids: [], npc: null });
    const p = byPoint.get(k);
    p.ids.push(id);
    if (!p.npc && d.entry.unplacedNpcs?.length) p.npc = d.entry.unplacedNpcs[0].npc;
  }
  const defs = g.data?.npcs?.npcs || {};
  let k = 0;
  for (const p of byPoint.values()) {
    const base = defs[p.npc] || defs[GATE_NPC];
    if (!base) continue;
    const col = g.world?.collision;
    // stand beside the point (the point itself is where the player arrives when kicked out)
    const target=p;
    let x = target.x + 0.5 + (target.relocated ? 0 : 2), z = target.y + 0.5;
    if (col && !col.isWalkable(x, z)) { const s = col.nearestWalkable(x, z, 6); if (s) { x = s.x; z = s.z; } }
    const first = dungeonById(p.ids[0]);
    const named = p.npc && base.name && !/^[?\s]*$/.test(base.name);
    // a gate without its own NPC text introduces its dungeons in the style of the entry NPCs' texts
    const gateText = p.npc && defs[p.npc]?.comm != null ? null : gateGreeting(p.ids);
    const def = { ...base, gateText, index: base.index ?? (p.npc || GATE_NPC), name: named ? base.name : (first?.title || first?.name || base.name), jobs: p.ids.map(id => [19, Number(id)]), roles: ['DUNGEON'], entryGate: true };
    const npc = new NPC(g, def, { npcIndex: def.index, x, z, dirDeg: 0, warpX: p.x, warpZ: p.y });
    npc.entryGate = true;
    try { await npc.load(); } catch (err) { console.warn('[dungeons] gate', err); }
    if (g.world?.info?.index !== map) { npc.dispose(); return; }
    g.npcs.push(npc);
    sys.gates.push(npc);
    k++;
  }
  return k;
}

/**
 * Entry text of a placed gate (the client's own entry NPC texts use this layout, e.g. stringtable_conv 51000):
 * "-Instance Dungeon-", the name, the mission, the inventory warning, then <Entry Condition> level / time / item.
 */
function gateGreeting(ids) {
  const C = (c, t) => `<color=${c}>${t}</color>`;
  const out = [`<color=c1c1ff><font=4>-Instance Dungeon-</color></font>`];
  const seen = new Set();
  for (const id of ids) {
    const d = dungeonById(id);
    const title = d?.title || d?.name || '';
    if (!d || seen.has(title)) continue;
    seen.add(title);
    const [min, max] = d.entry?.levels || [0, 0];
    out.push('', C('fdb602', title));
    const mission = plain(d.mission || '');
    if (mission) out.push(mission);
    out.push(C('c1c1ff', '[You will not be rewarded if your Inventory is full.]'), '', C('fdb602', '<Entry Condition>'));
    out.push(C('fdb602', `Entry Level: Lv. ${min || 1}~${max && max < 250 ? max : ''}`));
    if (d.timeLimit?.text) out.push(C('fdb602', `Time Limit: ${d.timeLimit.text}`));
    if (d.entry?.ticket?.item) out.push(C('fdb602', `Entry Item: ${D.dg?.itemNames?.[d.entry.ticket.item] || `#${d.entry.ticket.item}`}`));
  }
  return out.join('\n');
}

/** Can this dungeon be entered solo? {ok, code} (code = system text of the refusal). */
function floorHasMapFile(m) {
  // ABSENT_MAPLIST floors (Lane 25/23): loadData.enrichAbsentMaplistDungeonMaps sets files.map from synthesised stem.
  return !!mapInfo(m)?.files?.map;
}
function playable(id) {
  const d = dungeonById(id);
  if (!d) return { ok: false, code: 3 };
  if (d.missingFloors?.length || !(d.floors || []).every(floorHasMapFile)) return { ok: false, code: 8 };
  const f0 = mapInfo(d.floors?.[0])?.flags || {};
  // PvP arenas / DK-square battlefields need other players: "Due to a shortage of people, the dungeon can't be
  // created now." (no AI opponents, per the user)
  if (d.keeper === 'PARTYMATCH' || d.solo?.pvpOnly || d.keeper === 'SQUARE') return { ok: false, code: 26 };
  // siege castles belong to the siege war: "Only the defending guild can enter." (a siege system may claim them)
  if (f0.siege && !sys.claimed.has(Number(d.floors[0]))) return { ok: false, code: 17 };
  if (FOREIGN_KEEPERS.has(d.keeper)) return { ok: false, code: 8 };
  return { ok: true };
}

async function requestEntry(id, npc = null, opts = {}) {
  if (sys.entryBusy) return false;
  sys.entryBusy = true;
  try { return await admitLocalDungeon(id, npc, opts); }
  catch (error) { sys.admissionError = String(error?.message || error); await sys.ui.result(sysText(8)); return false; }
  finally { sys.entryBusy = false; }
}

async function localEntranceCosts(g, id, npc, free) {
  if (free) return { fee: 0, requirements: [] };
  await g.items?.ready;
  const [db, dialogs, quests, dshop] = await Promise.all([
    g.items?.db || g.itemDB || ItemDB.load(),
    g.quests?.db?.D || loadDialogs(),
    g.quests?.db?.Q || loadQuests(),
    shopTables.dshop || loadDshop(),
  ]);
  if (!db || !dialogs || !quests || !dshop) throw Error('The original dungeon entrance cost is unavailable.');
  const context = { data: { dungeonData: { dg: D.dg, dialogs }, itemDB: db, progression: { quests }, shopData: { dshop } }, now: Date.now };
  const costs = dungeonEntranceCosts(context, id, npc?.npcIndex ?? npc?.def?.index);
  return { ...costs, fee: premiumDungeonFee(context, g.save, costs.fee) };
}

// Stage only admission costs. References identify the actual bag stacks, so a
// later refund adds only what this admission consumed, preserving other gains.
function localCostPlan(g, costs) {
  const profile = g.save, list = profile.inventory || (profile.inventory = []), now = Date.now();
  const usable = item => item && !(item.expiresAt && item.expiresAt <= now);
  const left = new Map(list.filter(usable).map(item => [item, Number(item.count) || 1])), removals = [];
  // The local player is the first (only) entrant; a ticket comes before its Super Pass alternative.
  const held = id => [...left].reduce((sum, [item, n]) => sum + (Number(item.itemIndex ?? item.index) === id ? n : 0), 0);
  const picks = selectDungeonRequirements(held, costs.requirements, { first: true });
  if (!picks) return { code: 40 };
  for (const requirement of picks) {
    let needed = requirement.count;
    for (const id of requirement.items) {
      const stacks = [...left.keys()].filter(item => Number(item.itemIndex ?? item.index) === id).sort((a, b) => left.get(a) - left.get(b));
      for (const item of stacks) {
        const count = Math.min(needed, left.get(item));
        if (count) { removals.push({ item, count, original: structuredClone(item) }); left.set(item, left.get(item) - count); needed -= count; }
        if (!needed) break;
      }
      if (!needed) break;
    }
    if (needed) return { code: 40 };
  }
  if ((Number(profile.dil) || 0) < costs.fee) return { code: 13 };
  return { profile, list, removals, fee: costs.fee, applied: false };
}

function applyLocalCosts(plan) {
  for (const removal of plan.removals) {
    const item = removal.item; item.count = (Number(item.count) || 1) - removal.count;
    if (item.count <= 0) plan.list.splice(plan.list.indexOf(item), 1);
  }
  plan.profile.dil = (Number(plan.profile.dil) || 0) - plan.fee;
  plan.applied = true;
}

function refundLocalCosts(g, plan) {
  if (!plan?.applied) return;
  plan.applied = false;
  plan.profile.dil = Math.min(10_000_000_000, (Number(plan.profile.dil) || 0) + plan.fee);
  for (const removal of plan.removals) {
    const original = removal.original;
    const item = plan.list.find(item => item === removal.item || original.uid && item.uid === original.uid && Number(item.itemIndex ?? item.index) === Number(original.itemIndex ?? original.index));
    if (item) item.count = (Number(item.count) || 1) + removal.count;
    else {
      const restored = { ...original, count: removal.count };
      const bag = g.save === plan.profile && g.items?.bag?.list === plan.list && g.items.bag;
      if (bag) { if (!bag.add(restored).ok) throw Error('The admission item refund has no inventory space.'); }
      else plan.list.push(restored);
    }
  }
}

function notifyAdmissionCosts(g, reason) {
  if (g.items?.changed) g.items.changed(reason, null, { look: false });
  else g.events?.emit?.('inventory', { reason });
  g.events?.emit?.('dil', { total: Number(g.save?.dil) || 0, reason });
}

function localEntryUnavailable(g) {
  return sys.director || mapInfo(g.world?.info?.index)?.kind === 'instance' || g._loadingMap
    || !g.world || g.world._disposed || !Number.isFinite(Number(g.world.info?.index))
    || !Number.isFinite(g.player?.x) || !Number.isFinite(g.player?.z) || g.save?.authority === 'server';
}

async function admitLocalDungeon(id, npc, opts) {
  await sys.ready;
  const g = sys.game;
  const d = dungeonById(id);
  sys.admissionError = null;
  // New admissions begin at a field entrance. An active run owns its separate
  // native stairs/exit paths; its disposed actors cannot be restored by reentry.
  if (localEntryUnavailable(g)) { await sys.ui.result(sysText(8)); return false; }
  const chk = playable(id);
  if (!chk.ok) { await sys.ui.result(sysText(chk.code)); return false; }
  // GM /gm unlockmaps: no level range, admission ticket or entry fee
  if (g.gm?.st?.unlock) opts = { ...opts, free: true };
  const lv = g.gm?.st?.unlock ? Math.max(1, Number(d.entry?.levels?.[0]) || 1) : Number(g.save?.level) || 1;
  const [min, max] = d.entry?.levels || [0, 0];
  if (min > 0 && lv < min) { await sys.ui.result(sysText(15)); return false; }
  if (max > 0 && max >= min && lv > max) { await sys.ui.result(sysText(16)); return false; }
  if (!d.entry?.vehicle && (g.player?.mounted || g.mounts?.mounted)) { await sys.ui.result(sysText(25)); return false; }
  // the Clean Campaign captcha (CaptchaRate %) and its 5-minute failure penalty
  if (sys.captcha.blockedFor() > 0) { await sys.ui.result(sys.captcha.penaltyText()); return false; }
  if (!opts.skipCaptcha && sys.captcha.rolls(d) && !(await sys.captcha.ask())) return false;
  let costs, plan;
  try { costs = await localEntranceCosts(g, id, npc, opts.free); plan = localCostPlan(g, costs); }
  catch (error) { sys.admissionError = error.message; await sys.ui.result(sysText(8)); return false; }
  if (plan.code) { await sys.ui.result(sysText(plan.code)); return false; }
  const name = d.title || d.name;
  if (!opts.skipConfirm) { const ok = await sys.ui.confirmEnter(name); if (!ok) return false; }
  // Confirmation is asynchronous: recheck the live profile, expiry, Premium and
  // mount/level state before charging, rather than retaining a stale candidate.
  if (sys.game !== g || g.save !== plan.profile || localEntryUnavailable(g)) return false;
  const profile = plan.profile;
  costs = await localEntranceCosts(g, id, npc, opts.free); plan = localCostPlan(g, costs);
  if (sys.game !== g || g.save !== profile || localEntryUnavailable(g)) return false;
  const currentLevel = g.gm?.st?.unlock ? Math.max(1, Number(min) || 1) : Number(g.save.level) || 1;
  if (min > 0 && currentLevel < min || max > 0 && max >= min && currentLevel > max) { await sys.ui.result(sysText(currentLevel < min ? 15 : 16)); return false; }
  if (!d.entry?.vehicle && (g.player?.mounted || g.mounts?.mounted)) { await sys.ui.result(sysText(25)); return false; }
  if (plan.code) { await sys.ui.result(sysText(plan.code)); return false; }
  const origin = { map: Number(g.world?.info?.index ?? g.save.map), x: g.player?.x ?? g.save.pos?.x, z: g.player?.z ?? g.save.pos?.z, dirDeg: (g.player?.yaw || 0) * 180 / Math.PI };
  let settle;const admission = { game: g, origin, settled: new Promise(resolve => { settle = resolve; }) };
  const oldPending = sys.pending, oldDungeon = g.save.dungeon;
  sys.admission = admission;
  try {
    applyLocalCosts(plan);
    if (!await enterFloor(id, 0, { awaitTravel: true })) throw Error('Dungeon map transfer did not complete.');
    if (sys.game !== g || g.save !== plan.profile || Number(g.world?.info?.index) !== Number(d.floors[0])) throw Error('Dungeon admission changed during transfer.');
    g.persist?.();
    if (!saveCharacter(g.save)) throw Error('Dungeon admission could not be saved.');
    notifyAdmissionCosts(g, 'dungeon-admission');
    settle(true);return true;
  } catch (error) {
    let recoveryError;
    try { refundLocalCosts(g, plan); } catch (refundError) { recoveryError = refundError; }
    sys.pending = oldPending;
    // Never replace the previous profile wholesale: keep unrelated EXP, loot,
    // DIL and quest gains made while the transfer was pending.
    if (sys.game === g && g.save === plan.profile) {
      if (oldDungeon === undefined) delete g.save.dungeon; else g.save.dungeon = oldDungeon;
      try {
        if (g.world?._disposed && typeof g.enterMap === 'function') await g.enterMap(origin.map, origin);
        else await g.travel(origin.map, origin);
      }
      catch (restoreError) { recoveryError ||= restoreError; }
      notifyAdmissionCosts(g, 'dungeon-admission-refund');
      if (Number(g.world?.info?.index) !== origin.map) recoveryError ||= Error('The source map could not be recovered.');
      try { g.persist?.(); if (!saveCharacter(g.save)) throw Error('The admission refund is not durably saved.'); }
      catch (saveError) { recoveryError ||= saveError; }
    } else recoveryError ||= Error('The local character changed before admission recovery.');
    sys.admissionError = recoveryError ? `${error.message} ${recoveryError.message}` : error.message;
    if (g.items) g.items._dirty = true;
    settle(false);await sys.ui.result(sysText(8));return false;
  } finally {
    if (sys.admission === admission) sys.admission = null;
  }
}

function enterFloor(id, floor, { awaitTravel = false } = {}) {
  const g = sys.game;
  const d = dungeonById(id);
  const map = Number(d?.floors?.[floor]);
  if (!d || !Number.isFinite(map)) return false;
  let pos = startPos(map);
  if (!pos && floor === 0 && d.entry?.spawn) { const s = d.entry.spawn; const [x, z] = s.snap || [s.x + 0.5, s.y + 0.5]; pos = { x, z, dirDeg: s.dir || 0 }; }
  sys.pending = { id: String(id), floor, pos };
  g.controller?.stop?.();
  g.events?.emit?.('dungeon:transfer', { dungeon: id, floor, map });
  if (awaitTravel) return new Promise((resolve, reject) => setTimeout(() => { Promise.resolve().then(() => g.travel(map, pos)).then(() => resolve(true), reject); }, 0));
  setTimeout(() => { Promise.resolve(g.travel(map, pos)).catch(err => console.error('[dungeons] enter', err)); }, 0);
  return true;
}

/** Leave the instance: KickTo point (dungeonlist KickToMap/X/Y) or the event respawn point. */
function leave(director, reason) {
  const g = sys.game;
  const d = director.dungeon || {};
  const info = director.info || {};
  let to = d.exit?.to?.[0];
  if ((!to || !to.map) && info.dk?.points?.length) to = info.dk.points[0];
  director.phase = 'left';
  sys.ui.hideAll();
  g.events?.emit?.('dungeon:leave', { map: director.map, dungeon: director.dungeonId, reason });
  const r = to && g.mapRow?.(to.map) ? { mapIndex: Number(to.map), x: Number(to.x) + 0.5, z: Number(to.y) + 0.5, dirDeg: 0 } : null;
  const target = r || (sys.director = null, g.respawnTarget());
  sys.director = null;
  setTimeout(() => { Promise.resolve(g.travel(target.mapIndex, target)).catch(err => console.error('[dungeons] leave', err)); }, 0);
}

// ============================================================================================ NPCs
/** openNpc hook: triggers, bricks, script NPCs, dungeon-only NPCs and entry gates. True when handled here. */
function handleNpc(npc) {
  if (!npc) return false;
  if (npc.isTrigger) { sys.director?.useTrigger(npc); return true; }
  if (npc.isBrick) return true;
  const services = !!sys.game.npcServices;
  // an NPC with quests talks through the quest system's dialog (it calls our job handlers for the menu lines)
  const quests = services && !npc.entryGate && npcHasQuests(npc);
  if (sys.director?.scriptNpc(npc.npcIndex) && !quests) { sys.game.quests?.notify?.('talk', { npc }); return sys.director.talk(npc); }
  const jobs = (npc.jobs || npc.def?.jobs || []).map(j => [Number(j[0]), Number(j[1])]);
  if (!jobs.length || quests) return false;
  const dungeonOnly = jobs.every(([jt]) => ENTRY_JOBS.has(jt) || SCRIPT_JOBS.has(jt));
  const travelOnly = jobs.every(([jt]) => TRAVEL_JOBS.has(jt) || ENTRY_JOBS.has(jt));
  if (dungeonOnly || npc.entryGate || (!services && travelOnly)) { sys.game.quests?.notify?.('talk', { npc }); npcDialog(npc, jobs); return true; }
  return false;
}

function npcHasQuests(npc) {
  const db = sys.game.quests?.db;
  const k = Number(npc?.npcIndex);
  return !!db && (db.byGiver?.has(k) || db.byTurnIn?.has(k) || db.byTalk?.has(k));
}

function npcGreeting(npc) {
  if (npc?.def?.gateText) return npc.def.gateText;
  const c = sys.strings.conv;
  const comm = npc?.def?.comm;
  return (comm != null && c?.get(Number(comm))) || '';
}
sys.npcGreeting = npcGreeting;

function jobLabel(jt) { return String(sys.strings.jobtype?.get(Number(jt)) || '').split('\n')[0]; }

/** The NPC talk page of this system: greeting + one entry per dungeon / travel job. */
function npcDialog(npc, jobs) {
  const menu = [];
  const entries = jobs.filter(([jt]) => ENTRY_JOBS.has(jt));
  // several dungeons behind one gate: name each (the client's NPCs list identical lines when the names match)
  const titles = new Set(entries.map(([, ji]) => dungeonById(ji)?.title || dungeonById(ji)?.name || ''));
  for (const [jt, ji] of jobs) {
    if (ENTRY_JOBS.has(jt)) {
      const d = dungeonById(ji);
      if (!d) continue;
      const lbl = jobLabel(jt) || '[Mission] I want to receive a mission.';
      menu.push({ text: titles.size > 1 ? `${lbl} [${d.title || d.name}]` : lbl, onClick: () => { requestEntry(String(ji), npc); } });
    } else if (SCRIPT_JOBS.has(jt)) {
      menu.push({ text: plain(sys.director?.text?.(ji)) || jobLabel(jt) || 'OK', onClick: () => null });
    } else if (TRAVEL_JOBS.has(jt)) {
      menu.push({ text: jobLabel(jt) || `[${TRAVEL_JOBS.get(jt)}]`, onClick: () => { travelService(npc, jt, ji); return 'keep'; } });
    }
  }
  sys.dialog.open({ title: npc.name || npc.def?.name || '', text: npcGreeting(npc), menu });
}

function travelService(npc, jt, ji) {
  const t = sys.travel;
  switch (TRAVEL_JOBS.get(jt)) {
    case 'teleport': return t.teleportMenu(npc, ji);
    case 'return': return t.setReturn(npc, ji);
    case 'portal': return t.portalMenu(npc);
    case 'sky': return t.skyTeleport(npc, ji);
    case 'siege': return t.siegeTeleport(npc, ji);
    default: return false;
  }
}

/** Handlers on the quest system's NPC dialog (game.npcServices), when it exists. */
function registerServices() {
  const S = sys.game.npcServices;
  if (!S?.register || sys._servicesDone === S) return;
  sys._servicesDone = S;
  for (const jt of ENTRY_JOBS) S.register(jt, (npc, j) => { requestEntry(String(j.jobIndex), npc); return true; });
  for (const jt of SCRIPT_JOBS) S.register(jt, (npc) => (sys.director?.talk(npc) ? true : false));
  for (const [jt] of TRAVEL_JOBS) S.register(jt, (npc, j) => { sys.game.uiwin?.close('npc'); return travelService(npc, jt, j.jobIndex) ? true : false; });
}

// ============================================================================================ events
function onDeath({ actor, killer }) {
  const g = sys.game;
  try { sys.director?.onDeath(actor, killer); } catch (err) { console.error('[dungeons] death', err); }
  if (actor?.kind === 'monster' && !actor.isBrick && killer && (killer === g.player || killer.owner === g.player)) mapDrop(actor);
}

/** monsterdropitem_map.csv: extra drops of every kill on a map. */
function mapDrop(actor) {
  const g = sys.game;
  const md = D.dg?.mapDrops?.[String(g.world?.info?.index)];
  if (!md || !g.loot || sys.mapDropsDisabled) return;
  if (!md._parsed) {
    const raw = md.raw || {};
    const fixed = [], fixedSets = [];
    for (let k = 1; k <= 20; k++) {
      if (raw[`Fix_ItemIndex_${k}`]) fixed.push([Number(raw[`Fix_ItemIndex_${k}`]), Number(raw[`Fix_ItemStack_${k}`]) || 0, Number(raw[`Fix_ItemCountMin_${k}`]) || 1, Number(raw[`Fix_ItemCountMax_${k}`]) || 1, Number(raw[`FixItemRatio_${k}`]) || 0]);
      if (raw[`Fix_ItemSet_${k}`]) fixedSets.push([Number(raw[`Fix_ItemSet_${k}`]), Number(raw[`Fix_ItemSetCountMin_${k}`]) || 1, Number(raw[`Fix_ItemSetCountMax_${k}`]) || 1, 0, Number(raw[`FixItemSetRatio_${k}`]) || 0]);
    }
    md._parsed = { fixed, fixedSets, sets: md.sets || [], money: md.money?.[4] ? [md.money] : [], maxSets: md.maxItemSet || 1 };
  }
  const p = md._parsed;
  if (!p.fixed.length && !p.fixedSets.length && !p.sets.length && !p.money.length) return;
  import('../../game/loot.js').then(({ rollMonsterDrops }) => {
    const rate = g.settings?.dropRate ?? 1;
    const fixed = p.fixed.filter(f => Math.random() * 100000 < f[4] * rate).map(f => f.slice(0, 4));
    const list = rollMonsterDrops({ drops: { fixed, fixedSets: p.fixedSets, sets: p.sets, money: p.money, maxSets: p.maxSets } }, g.data?.monsters, { itemRate: rate, moneyRate: g.settings?.moneyRate ?? 1 });
    list.forEach((e, i) => g.loot.spawnDrop(e, actor.x + Math.cos(i * 2.1) * 0.8, actor.z + Math.sin(i * 2.1) * 0.8));
  }).catch(() => {});
}

// ============================================================================================ services
function notice(text, flash = false) {
  const t = plain(text);
  if (!t) return;
  sys.game.hud?.log?.(t, 'sys');
  sys.game.events?.emit?.('dungeon:notice', { text: t, flash });
}
sys.notice = notice;
sys.leave = leave;
sys.enterFloor = enterFloor;

/** effectsound [cate, id, vol, x] -> sound.json system["id:vol:x"] (22 = system / dungeon sounds). */
sys.playEffectSound = (s) => {
  const a = sys.game.audio, snd = sys.sound;
  if (!a || !snd || !Array.isArray(s)) return;
  const [cate, id, vol, x] = s.map(Number);
  const rec = snd.system?.[`${id}:${vol}:${x}`] || snd.effectSound?.[cate]?.[id]?.scenes?.['1'] || null;
  const list = rec?.sfx || rec;
  if (Array.isArray(list)) { try { a.playOne?.(list, {}); } catch { /* optional */ } }
};

/** <sound>0,id = start the jingle / BGM id (sound.json bgmByMapIndex), 1,id = stop it (back to the map music). */
sys.playJingle = ([mode, id]) => {
  const a = sys.game.audio;
  if (!a?.playBGM) return;
  try { if (Number(mode) === 0) a.playBGM(Number(id)); else a.playBGM(sys.game.world?.info?.index); } catch { /* optional */ }
};

sys.grantExp = (amount) => {
  import('../../game/progression.js').then(({ grantExp }) => grantExp(sys.game, Number(amount) || 0)).catch(() => {});
};

/** [[item, count, rate]] reward lists (Forgotten Shipwreck roulette): ONE slot is picked, weighted by rate (reward-slot.js). */
sys.rollRewardList = (list) => {
  const g = sys.game;
  if (!Array.isArray(list) || !g.loot || !g.player) return;
  const names = g.data?.monsters?.itemNames || D.dg?.itemNames || {};
  const slot = pickRewardSlot(list);
  if (!slot) return;
  const [item, count] = slot;
  const e = { kind: 'item', itemIndex: item, name: names[item] || `Item #${item}`, count, stack: count > 1, grade: 'normal' };
  g.loot.spawnDrop(e, g.player.x + 1.2, g.player.z);
};

/** Local run records (the time-attack ranking of a solo player is their own best runs). */
sys.recordRun = (d, success) => {
  if (!success) return;
  try {
    const all = JSON.parse(globalThis.localStorage?.getItem(RECORDS_KEY) || '{}');
    const k = `${d.dungeonId}:${d.floor}`;
    const s = sys.game.save || {};
    const list = all[k] || [];
    list.push({ name: s.name || '', level: s.level || 1, cls: sys.game.classDef?.name || '', time: Math.round(d.elapsed), at: Date.now() });
    list.sort((a, b) => a.time - b.time);
    all[k] = list.slice(0, 10);
    globalThis.localStorage?.setItem(RECORDS_KEY, JSON.stringify(all));
    if (/time attack/i.test(`${d.name} ${d.info?.name}`) || d.info?.messages?.['110']) {
      const fmtT = (t) => `${String(Math.floor(t / 60)).padStart(2, '0')}:${String(t % 60).padStart(2, '0')}`;
      const rows = all[k].map((r, i) => ({ rank: i + 1, name: r.name, level: r.level, cls: r.cls, time: fmtT(r.time) }));
      const mineI = all[k].findIndex(r => r.at === list.find(x => x.time === Math.round(d.elapsed))?.at);
      sys.ui.timeAttackResult(d.mapName, rows, rows[mineI] || null);
    }
  } catch { /* storage off */ }
};

// ---------------------------------------------------------------------------------------------- items
/** Count of items (any of `ids`) in the bag (items system API when present, else save.inventory). */
export function itemCount(ids) {
  const g = sys.game;
  const set = new Set(ids.map(Number));
  const inv = typeof g.items?.count === 'function' ? g.items : typeof g.inventory?.count === 'function' ? g.inventory : null;
  if (inv) { let n = 0; for (const i of set) n += Number(inv.count(i)) || 0; return n; }
  let n = 0;
  for (const e of g.save?.inventory || []) if (e && set.has(Number(e.itemIndex ?? e.index))) n += Number(e.count) || 1;
  return n;
}
/** Remove `count` of the first matching item. */
export function consumeItem(ids, count = 1) {
  const g = sys.game;
  const api = typeof g.items?.remove === 'function' ? g.items : typeof g.inventory?.remove === 'function' ? g.inventory : null;
  if (api) {
    for (const i of ids) if ((Number(api.count?.(i)) || 0) >= count) return !!api.remove(i, count);
    return false;
  }
  const inv = g.save?.inventory || [];
  for (const id of ids) {
    const e = inv.find(x => x && Number(x.itemIndex ?? x.index) === Number(id));
    if (!e) continue;
    e.count = (Number(e.count) || 1) - count;
    if (e.count <= 0) inv.splice(inv.indexOf(e), 1);
    g.events?.emit?.('inventory', { removed: id, count });
    return true;
  }
  return false;
}
sys.itemCount = itemCount;
sys.consumeItem = consumeItem;

export { sys as _dungeonSystem };
