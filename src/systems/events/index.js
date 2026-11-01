// EVENTS system: Colosseum and Dead Front, plus Ice Castle (party war 2), the arena / party war / siege / guild
// tournament / guild war hunting / battle royal / DK square / DKR PvP battle / Forgotten Shipwreck / Forbidden Shackles /
// field boss content, the contents timetable and "start any event now". docs/formats/events.md, docs/EVENTS.md.
//
// Solo ruleset (user order: NO AI opponents): everything the data defines as PvE runs exactly; phases that only exist
// to fight other players are skipped / resolved by forfeit; pure PvP modes keep their NPCs and windows and answer with
// the original "no match" texts (events.json soloRules).
//
// Public API: game.eventsSystem = {
//   ownsMap(m)            the events system runs this map (other systems, e.g. a dungeon director, should skip it)
//   run                   the current EventRun (or null)
//   enter(map, opts)      enter an event map now (entry rules checked by the caller: officer / NPC / timetable)
//   start(kind)           start an event on demand ('deadFront' | 'iceCastle' | 'colosseumArena' | 'fieldBoss' | ...)
//   openTimetable()       the contents timetable window
// }
// Hooks (runtime wraps, no shared file edits): windows.openNpc (event NPCs get the event dialog), game.respawnTarget
// (event maps send the dead to their own respawn), npcServices (game.npcServices, quests system) for the event job types.
import { loadEventData } from './data.js';
import { Messenger } from './text.js';
import { EventUI } from './windows.js';
import { EventDialog } from './dialog.js';
import { EffectBanners } from './effectui.js';
import { installServices, EVENT_JOBS } from './services.js';
import { Schedule } from './schedule.js';
import { Brick } from './bricks.js';
import { installAbilityCap } from './abilitycap.js';

const RUNS = {
  deadFront: () => import('./deadfront.js').then(m => m.DeadFrontRun),
  iceCastle: () => import('./icecastle.js').then(m => m.IceCastleRun),
  colosseumArena: () => import('./arena.js').then(m => m.ArenaRun),
  infiniteBattle: () => import('./infinite.js').then(m => m.InfiniteRun),
  infiniteBattle2: () => import('./staged.js').then(m => m.Infinite2Run),
  forgottenShipwreck: () => import('./staged.js').then(m => m.ShipwreckRun),
  forbiddenShackles: () => import('./staged.js').then(m => m.FettersRun),
  guildWarHunting: () => import('./defense.js').then(m => m.DefenseRun),
  fieldBoss: () => import('./fieldboss.js').then(m => m.FieldBossRun),
};
/** Modes whose maps the events system owns (runs, bricks, NPC scripts). */
const OWNED_MODES = new Set([
  'deadFront', 'iceCastle', 'colosseumArena', 'infiniteBattle', 'infiniteBattle2', 'forgottenShipwreck',
  'forbiddenShackles', 'guildWarHunting', 'battleRoyal', 'partyMatch', 'guildMatch', 'pvp3v3', 'partyPvpArena',
  'arenaBattlefield', 'arenaBattlefieldBase', 'siege', 'siegeRenew', 'urbanWarfare', 'huntingChallenge', 'oxQuiz',
]);

class EventsSystem {
  constructor(game) {
    this.game = game;
    this.data = null;
    this.run = null;
    this.pending = null;
    this.owned = new Set();
    this.ready = null;
  }

  async init() {
    const game = this.game;
    this.data = await loadEventData();
    for (const [m, info] of Object.entries(this.data.maps)) if (OWNED_MODES.has(info.mode)) this.owned.add(Number(m));
    this.owned.add(260);
    this.msg = new Messenger(game, this);
    this.ui = new EventUI(game, this);
    this.dialog = new EventDialog(game);
    this.banners = new EffectBanners(game, this);
    this.schedule = new Schedule(game, this);
    this._hooks();
    this._abilityCapOff = installAbilityCap(game, this);
    installServices(game, this);
    game.events.on('map', ({ index }) => this._onMap(index));
    game.events.on('death', (e) => this._onDeath(e));
    game.events.on('damage', (e) => { try { this.run?.onDamage?.(e); } catch (err) { console.error('[events] onDamage', err); } });
    game.events.emit('events:claim', { maps: [...this.owned] });
    // the dungeon system (director of the instance maps) skips the maps the events run
    const claim = () => { if (typeof game.dungeons?.claim === 'function') for (const m of this.owned) game.dungeons.claim(m); };
    claim();
    game.events.on('systems', claim);
  }

  ownsMap(m) { return this.owned.has(Number(m)); }

  // ------------------------------------------------------------------------------------------ hooks
  _hooks() {
    const game = this.game;
    // 1) event NPCs open the event dialog (officers, depots, levers, slates, Reezena...), everything else as before
    const W = game.windows;
    if (W && typeof W.openNpc === 'function' && !W._eventsWrapped) {
      const orig = W.openNpc.bind(W);
      W.openNpc = (npc) => { try { if (this.openNpc(npc)) return null; } catch (err) { console.error('[events] npc', err); } return orig(npc); };
      W._eventsWrapped = true;
    }
    // 2) "Revive in town" on an event map goes to the event's own respawn / exit
    if (typeof game.respawnTarget === 'function' && !game._eventsRespawn) {
      const orig = game.respawnTarget.bind(game);
      game.respawnTarget = (mapIndex) => {
        const cur = mapIndex ?? game.world?.info?.index;
        if (this.run && Number(cur) === this.run.map) { const r = this.run.respawnTarget?.(); if (r) return r; }
        return orig(mapIndex);
      };
      game._eventsRespawn = true;
    }
  }

  /** Event dialog for an NPC; returns true when handled. */
  openNpc(npc) {
    const id = Number(npc?.npcIndex ?? npc?.def?.index);
    if (!Number.isFinite(id)) return false;
    // the current run's scripted NPCs
    const page = this.run?.npcPage?.(npc);
    if (page) { this.dialog.open(npc, page); return true; }
    // officers (37/38, 98/99) and other NPCs whose every job is an event job
    const jobs = npc.def?.jobs || npc.jobs || [];
    if (jobs.length && jobs.every(([t, i]) => this.services?.isEventJob?.(Number(t), Number(i)) ?? EVENT_JOBS.has(Number(t)))) {
      const p = this.services?.pageFor?.(npc);
      if (p) { this.dialog.open(npc, p); return true; }
    }
    return false;
  }

  // ------------------------------------------------------------------------------------------ runs
  /** Travel into an event map; the run starts when the map is loaded. opts: {x, z, mode, carry, entry}. */
  async enter(map, opts = {}) {
    this.pending = { map: Number(map), ...opts };
    const p = opts.x != null ? { x: opts.x, z: opts.z, dirDeg: opts.dirDeg || 0 } : null;
    const same = Number(this.game.world?.info?.index) === Number(map);
    await this.game.travel(Number(map), p);
    if (same) await this._onMap(Number(map));      // a same-map travel is a teleport (no 'map' event)
  }

  async _onMap(index) {
    const m = Number(index);
    const pend = this.pending && this.pending.map === m ? this.pending : null;
    this.pending = null;
    if (this.run && (this.run.map !== m || pend)) { this.run.end('left'); this.run = null; }
    if (this.run) return;
    this._levelCap(m);
    const mode = pend?.mode || this.data?.modeOf(m);
    if (!mode || !RUNS[mode]) return;
    if (mode === 'fieldBoss' && !pend) return;          // Mitera is a normal field until the boss is called
    if (!this.ownsMap(m) && mode !== 'fieldBoss') return;
    try {
      const [Cls] = await Promise.all([RUNS[mode](), this.data.ensureDungeons()]);
      if (Number(this.game.world?.info?.index) !== m) return;
      const run = new Cls(this, m, pend || { entry: 'direct' });
      this.run = run;
      await run.start();
      this.game.events.emit('event:start', { map: m, mode });
      // event maps have no smart warp (the dungeon system opens its button on every map without an instance)
      if (mode !== 'fieldBoss') setTimeout(() => { if (this.run === run) this.game.uiwin?.close('smartwarp_alarm'); }, 500);
    } catch (err) { console.error('[events] run failed to start', mode, m, err); }
  }

  /** The map's EXP-by-level-difference table (share/pc/levelcap/*.csv) while on an event map. */
  _levelCap(m) {
    const exp = this.game.data?.exp;
    if (!exp) return;
    if (this._savedLD !== undefined) { exp.levelDifference = this._savedLD; this._savedLD = undefined; }
    if (!this.ownsMap(m)) return;
    const t = this.data.levelCapTable(m);
    if (!t?.rows?.length) return;
    this._savedLD = exp.levelDifference;
    exp.levelDifference = t.rows.map(r => ({ diffFrom: r[0], diffTo: r[1], expRate: r[2], chaoticRate: r[3], blocking: r[4], blocked: r[5] }));
  }

  _onDeath(e) {
    const a = e?.actor;
    if (a instanceof Brick && this.run) {
      this.run.bricks.onDeath(a);
      try { this.run.onBrickDestroyed?.(a); } catch (err) { console.error('[events] brick', err); }
    }
    try { this.run?.onDeath?.(e); } catch (err) { console.error('[events] onDeath', err); }
  }

  /** Centre event message (Messenger) and UI effect banners (Messenger). */
  notice(text) { return this.ui?.notice(text); }
  banner(id, ms) { return this.banners?.show(id, ms); }

  /** Start an event on demand (timetable / GM). */
  start(kind, opts = {}) { return this.schedule.startNow(kind, opts); }
  openTimetable() { return this.schedule.open(); }

  update(dt) {
    this.ui?.update(dt);
    this.banners?.update(dt);
    this.schedule?.update(dt);
    if (this.run?.ended) this.run = null;
    try { this.run?.update(dt); } catch (err) { console.error('[events] run update', err); this.run?.end('error'); this.run = null; }
  }

  dispose() { this.run?.end('dispose'); this.run = null; this._abilityCapOff?.(); }
}

let SYS = null;

export async function install(game) {
  SYS = new EventsSystem(game);
  game.eventsSystem = SYS;
  SYS.ready = SYS.init().catch(err => { console.error('[events] init failed', err); });
  await SYS.ready;
}

export function update(dt) { SYS?.update(dt); }
export function dispose() { SYS?.dispose(); }
