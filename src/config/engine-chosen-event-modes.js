// EVENT-MODES: the values Global data leaves open for the Server Whole Competition (Race) and the Mission titles.
// Global parity: every number that IS in the data comes from it (share/race/list.csv + playtime.csv,
// share/pc/title/title_base.csv via gamedata/events.json / life.json) and every PvP hit runs src/game/pvp-rules.js
// through server/world/pvp.mjs. Nothing is scaled and no modifier is added; where the data is silent the original's
// default behaviour is preferred, and each gap is one tagged line below.
// Egutt (job 130 EGUTT_ENTER = Draco Desert Battlefield) is hosted by the arena module (server/world/arena.mjs,
// src/config/engine-chosen-arena.js venueJobs[130]); it is not duplicated here.
// Forgotten Shipwreck: its reward roulette (share/forgottenshipwreck/rewardslot.csv, one weighted slot) is verified through the
// host dungeon path by tools/test-event-modes.mjs. The BLUE / RED team mode of game2/forgottenshipwreck (startcondition.csv: 10
// players at 6 weekly windows; ui_matchingwait / ui_scorewnd / team, buff and target skill windows; string cate 161 = the
// "Monster Carnival" strings) has no rule, CP or score data in the shipped files; it is hosted by server/world/monster-carnival.mjs
// with its own choices in src/config/engine-chosen-monster-carnival.js.

export const RACE_CHOSEN = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): this host plays the list.csv rows of WorldIndex 1; the WorldIndex 10/20 rows belong to other game servers of the live cross-server directory and are not listed.
  worldIndex: 1,
  // ENGINE-CHOSEN (not in Global data): English texts of game2/race/ui_entreeinfo text2 210|1..7 (no shipped string table has the race codes; 210|1..5 are cash-shop tabs).
  labels: Object.freeze({ server: 'Server', rank: 'Rank', level: 'Level', users: 'Users', status: 'Status', entry: 'Entry', refresh: 'Refresh' }),
  // ENGINE-CHOSEN (not in Global data): playtime.csv DayOfWeek uses 0 = Sunday .. 6 = Saturday and fixed UTC+1 server time.
  dayOfWeek: '0 = Sunday, UTC+1 server time',
  // ENGINE-CHOSEN (not in Global data): entry opens at WaitingHour:WaitingMinute and stays open until EndHour (late entry joins the running competition) while fewer than LimitedCount are in.
  entryWindow: 'Waiting .. EndHour, under LimitedCount',
  // ENGINE-CHOSEN (not in Global data): the band = the WorldIndex row whose MinLevel..MaxLevel holds the character level.
  band: 'MinLevel..MaxLevel of the character',
  // ENGINE-CHOSEN (not in Global data): entrants wait at DefaultPosX/Y; at StartHour the n-th entrant (entry order) goes to the first bracket k with MinCount_k <= n <= MaxCount_k (PosX_k/PosY_k).
  spawnRule: 'entry order -> first matching count bracket',
  // ENGINE-CHOSEN (not in Global data): the competition is a free-for-all among the band's entrants from StartHour to EndHour.
  combat: 'free-for-all of the band',
  // ENGINE-CHOSEN (not in Global data): score = player kills; rank = kills high to low, then fewer deaths, then the earlier last kill, then name.
  ranking: 'kills desc, deaths asc, earlier last kill, name',
  // ENGINE-CHOSEN (not in Global data): a downed entrant returns at its bracket position after the PvP rules' reviveTick, with reviveHpRatio / reviveMpRatio.
  respawn: 'pvp-rules reviveTick, own bracket',
  // ENGINE-CHOSEN (not in Global data): no reward item, EXP or title is given (none is in the data); the result is the ranking.
  reward: 'none (ranking only)',
  // ENGINE-CHOSEN (not in Global data): seconds between the result and moving everyone back to where they entered.
  finishWaitSec: 30,
  // ENGINE-CHOSEN (not in Global data): the exit point = where each entrant entered (map kickTo 150 is not on every entry route).
  exitPoint: 'entry point',
  // ENGINE-CHOSEN (not in Global data): the Status column texts.
  status: Object.freeze({ closed: 'Closed', entry: 'Entry', race: 'In Progress', full: 'Full', over: 'Finished' }),
  // ENGINE-CHOSEN (not in Global data): no NPC opens the window in the data; the chat command /race opens it and the host announces the entry opening once.
  opener: '/race + entry notice',
  // ENGINE-CHOSEN (not in Global data): the client refreshes an open race window every refreshMs (the entered player's own state arrives with every state snapshot).
  refreshMs: 1000,
  // ENGINE-CHOSEN (not in Global data): the imagetable sprites race 2 / 3 / 4 (dashboard plate, entry-capacity title plate and row) point at regions of war_01.dds that are fully transparent in the shipped texture, so the plates are drawn as a dark panel with a bronze border.
  plateArt: Object.freeze({ background: 'linear-gradient(#2c261d, #15120d)', border: '1px solid #8a7544' }),
  // ENGINE-CHOSEN (not in Global data): English texts of the competition's refusals and notices (no shipped string covers them; only the window titles 100|128 / 100|129 are shipped).
  text: Object.freeze({
    closed: 'The Server Whole Competition is not open for entry now.',
    band: 'Your level is not eligible for this competition.',
    full: 'The competition is full.',
    already: 'You have already entered the competition.',
    busy: 'You cannot enter the competition right now. Finish your current activity first.',
    dead: 'Dead characters cannot enter the competition.',
    noEntry: 'You are not in the competition.',
    cannotLeave: 'You cannot leave the competition right now.',
    revive: 'You return to the competition automatically.',
    open: 'The Server Whole Competition is open for entry. Type /race to enter.',
  }),
});

export const TITLE_CHOSEN = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): Type 1 = kill monster Type_Value1 Type_Value2 times (credited to the killing character).
  type1: 'kill Type_Value1 x Type_Value2',
  // ENGINE-CHOSEN (not in Global data): Type 7 = be knocked down by monster Type_Value1 Type_Value2 times (title 12 text 2803|12 'He welcomed me with his slap, and I'm laying on the ground').
  type7: 'downed by Type_Value1 x Type_Value2',
  // ENGINE-CHOSEN (not in Global data): Type 9 rows have no condition data (server script achievements, text 2803|<Index>); they stay locked until a host grant (grantTitle) - none is invented.
  type9: 'locked, host grant only',
  // ENGINE-CHOSEN (not in Global data): a Type 9 row whose 2803 text names a dungeon clear (20 Solo Champion = Colosseum Arena (Solo), dungeon 615 SOLO) is granted inside the host's durable last-floor clear transaction of that dungeon for its one runner (src/systems/life/title-rules.js TITLE_DUNGEON_CLEARS).
  clearTitle: 'durable last-floor clear of the named dungeon, one runner',
  // ENGINE-CHOSEN (not in Global data): the list shows an owned title by name and an unowned one with its script default 2801|6 "Unacquired Title"; selecting a row shows its 2803 text; only an owned title can be applied.
  window: 'owned by name, others "Unacquired Title", owned selectable',
  // ENGINE-CHOSEN (not in Global data): the original "in progress" message 2802|9 is shown for each counted kill / down that does not finish a title yet (the cadence is not in the data).
  progressNotice: 'each counted event below the goal',
});

const list = o => Object.entries(o).map(([k, v]) => `${k}=${typeof v === 'object' ? JSON.stringify(v) : v}`);
export function eventModesChosenList() { return [...list(RACE_CHOSEN).map(s => 'race.' + s), ...list(TITLE_CHOSEN).map(s => 'title.' + s)]; }
