// Mode-specific UI and timed pop-ups (Lane 46 / step 29; Lane 72 / step 8 cross-cutting audit).
// Catalog of Global windows + timings. Presentation helpers open already-approved
// layout scripts only — no layout edits. Inventory: docs/global-parity-420/MODE-UI-POPUPS.md.
//
// Global timed windows (decompile 32-bit decompiled-named.c; 64-bit Chat::UIHandler):
//   SiegeMessageWnd (FUN_00b82a40 init default +0xc = 10000 ms, SIEGE_MESSAGE_INIT_MS) is always shown by
//     SiegeSystemMessage 0x70040026 whose field [1] overwrites the duration (FUN_00b82ca0). Chat::UIHandler sends it
//     for a "[siege]" or "[effectstr]" tagged line with 7000 ms -> SIEGE_MESSAGE_MS.
//   SystemMessageWnd (FUN_00b81fd0): SystemMessage 0x70040016 -> lbl_message, SystemMessage2 0x70040029 -> lbl_bigmessage;
//     "[message]" tagged chat lines (chat type 2) are shown 7000 ms (type 0x13: 4000 ms); the tick hides the window
//     when now - start > duration (no fade).
//   EventMessageWnd (Chat::EventMessage 0x7004001e from the server text packet, subtype 2): queue of at most 5 lines,
//     the oldest is dropped after 15000 ms (FUN_00b341b0) or when a 6th arrives (FUN_00b34220).
// String-table routing: the leading tag of each Global string picks the window; untagged strings are chat only.
// "@<effectui>id,a,ms,b" in a string plays effect banner `id` for `ms` (effectscene cate 8, events_effectui.json).
// Scripts under global-prepared/.../data/script/ui/game2/.

export const SIEGE_MESSAGE_INIT_MS = 10000; // window default before the first SiegeSystemMessage (never shown with it)
export const SIEGE_MESSAGE_MS = 7000;
export const SYSTEM_MESSAGE_MS = 7000;
export const SYSTEM_MESSAGE_SHORT_MS = 4000;
export const EVENT_MESSAGE_MS = 15000;
export const EVENT_MESSAGE_QUEUE = 5;
// EventMessageWnd line join (FUN_00b34270): each queued line becomes "<center>" + line + DAT_01ac172c. DAT_01ac172c is the
// wide string L"\\" (bytes 5c 00 00 00, read from decompile reconstructed-images/dekaron32-memory-image.bin at the
// lbl_message / u"<center>" / DAT_01ac172c run). Global text layout ends a line at 0x5c (FUN_00a8fb70), so the lines stack.
export const EVENT_MESSAGE_LINE_BREAK = '\\';
// Guild War Hunting finish (FUN_00d00b70): SiegeMessage 8000 ms with string 0x2800d8 = stringtable_pc 40:216, <NAME> =
// the first entry of the final ranking list.
export const GWH_TOP_GUILD_MS = 8000;
export const GWH_TOP_GUILD_STRING = Object.freeze({ group: 'NORMAL', cate: 40, code: 216 });
export const GWH_TOP_GUILD_TEXT = '<color=F4BE3D><NAME></color> guild has become the top guild in the Braiken Castle defense battle.';

export const SIEGE_MESSAGE_SCRIPT = 'game2/systemwnd/ui_siegemessagewnd.txt';
export const SIEGE_MESSAGE_WINDOW = 'siege_message';
export const SYSTEM_MESSAGE_SCRIPT = 'game2/systemwnd/ui_systemmessagewnd.txt';
export const SYSTEM_MESSAGE_WINDOW = 'hud_sysmsg';

/** @typedef {{ mode: string, element: string, window: string, script: string, trigger: string, stringRef?: string, durationMs?: number|null, owner: string, status: 'wired'|'fixed'|'removed'|'owner-other'|'gap'|'unresolved', evidence: string, notes?: string }} ModeUiRow */

/** @type {readonly ModeUiRow[]} */
export const MODE_UI_CATALOG = Object.freeze([
  // --- Shared / cross-mode ---
  { mode: 'shared', element: 'centerEventMessage', window: 'ev_message', script: 'game2/ui_eventmessagewnd.txt',
    trigger: 'Messenger/EventUI.notice on map-script message / effectui text', stringRef: 'events_text / map tables',
    durationMs: EVENT_MESSAGE_MS, owner: 'lane72', status: 'fixed',
    evidence: 'decompile Chat::EventMessage 0x7004001e; FUN_00b341b0 shared 15000ms age; FUN_00b34220 queue of 5; FUN_00b34270 "<center>"+line+DAT_01ac172c; GLOBAL client image DAT_01ac172c = L"\\" (line break in FUN_00a8fb70)',
    notes: 'was one line replaced on every notice with its own 15 s; now EventMessageQueue (5 lines, oldest drops, shared age)' },
  { mode: 'colosseumArena', element: 'stringBanners', window: 'ev_effect', script: 'game2/ui_effectuiwnd.txt',
    trigger: 'Colosseum / Arena / DK Square string-table lines -> presentGlobalMessage (banners, then [siege]/[message] window, then chat)',
    stringRef: 'stringtable_colosseum 360:149 @<effectui>2156 5000 ms; arena / DK Square cate 160 lines in use carry no token', durationMs: 5000,
    owner: 'lane72', status: 'fixed',
    evidence: 'decompile 64-bit Chat::UIHandler vf23 finds "<effectui>" in every chat line (decompiled-named.c ~2213643); GLOBAL stringtable_colosseum 360:149; GLOBAL stringtable cate 160 scan',
    notes: 'tokens were stripped and dropped in arena.js / colosseum.js / dksquare.js' },
  { mode: 'shared', element: 'systemMessage', window: SYSTEM_MESSAGE_WINDOW, script: SYSTEM_MESSAGE_SCRIPT,
    trigger: '"[message]" tagged string (chat type 2), hud.toast', stringRef: 'any [message] string',
    durationMs: SYSTEM_MESSAGE_MS, owner: 'lane72', status: 'fixed',
    evidence: 'decompile FUN_00b81fd0 0x70040016/0x70040029; Chat::UIHandler [message] type 2 = 7000, type 0x13 = 4000; no fade',
    notes: 'was 5 s with a 0.8 s fade (no source)' },
  { mode: 'shared', element: 'effectBanner', window: 'ev_effect', script: 'game2/ui_effectuiwnd.txt',
    trigger: 'events_effectui @<effectui>id / EffectBanners', stringRef: 'effectscene cate 8',
    durationMs: null, owner: 'events/effectui', status: 'wired',
    evidence: 'Global ui_effectuiwnd + events_effectui.json; ms from the string token' },
  { mode: 'shared', element: 'bossHpBar', window: 'hud_bosshp', script: 'game2/ui_bosshpbar.txt',
    trigger: 'target is boss-class monster (hud target path)', stringRef: null,
    durationMs: null, owner: 'hud', status: 'wired',
    evidence: 'decompile ui_BossHpBar; hudwins.js BOSS_BARS=10' },

  // --- Siege classic (Lane 20 HUD) ---
  { mode: 'siege', element: 'siegeMessage', window: SIEGE_MESSAGE_WINDOW, script: SIEGE_MESSAGE_SCRIPT,
    trigger: 'siegeNotice whose Global string starts with [siege] / [effectstr]', stringRef: 'SIEGE 701:300-303',
    durationMs: SIEGE_MESSAGE_MS, owner: 'lane72', status: 'fixed',
    evidence: 'stringtable_siege.txt tags; Chat::UIHandler [siege]/[effectstr] -> SiegeSystemMessage 7000 (FUN_00b82ca0 duration = msg[1])',
    notes: 'was 10000 ms (window init default) and shown for every siegeNotice' },
  { mode: 'siege', element: 'systemMessage', window: SYSTEM_MESSAGE_WINDOW, script: SYSTEM_MESSAGE_SCRIPT,
    trigger: 'siegeNotice whose Global string starts with [message]', stringRef: 'SIEGE 700:1/13/18/40/58/71/72/74/75/79/127-130/140, 701:100-106/200-220/380-382/400-405',
    durationMs: SYSTEM_MESSAGE_MS, owner: 'lane72', status: 'fixed',
    evidence: 'stringtable_siege.txt [message] tags; Chat::UIHandler [message] -> SystemMessage 7000',
    notes: 'was drawn in the siege window' },
  { mode: 'siege', element: 'chatOnly', window: 'chat', script: '-',
    trigger: 'siegeNotice whose Global string has no tag', stringRef: 'SIEGE 700:* untagged',
    durationMs: null, owner: 'lane72', status: 'removed',
    evidence: 'stringtable_siege.txt: no tag = chat line only',
    notes: 'the 4.2.0 siege-window popup for untagged strings had no Global source' },
  { mode: 'siege', element: 'warState', window: 'siege_war', script: 'game2/siege/ui_warstatewnd.txt',
    trigger: 'on castle during battle/prep', durationMs: null, owner: 'lane20', status: 'wired',
    evidence: 'Lane 20 + siege.js SIEGE_SCRIPTS' },
  { mode: 'siege', element: 'playTime', window: 'siege_time', script: 'game2/siege/ui_siege_play_timewnd.txt',
    trigger: 'on castle; lbl_text from NORMAL 290:51', durationMs: null, owner: 'lane20', status: 'wired',
    evidence: 'siege.js HUD time' },
  { mode: 'siege', element: 'pendantState', window: 'siege_stones', script: 'game2/siege/ui_allzeolitestatewnd.txt',
    trigger: 'on castle; 5 guardian stones', durationMs: null, owner: 'lane20', status: 'wired',
    evidence: 'siege.js HUD stones' },
  { mode: 'siege', element: 'gateState', window: 'siege_gates', script: 'game2/siege/ui_allgatestatewnd.txt',
    trigger: 'on castle; 3 gates', durationMs: null, owner: 'lane20', status: 'wired',
    evidence: 'siege.js HUD gates' },
  { mode: 'siege', element: 'empathyAttach', window: 'siege_attach', script: 'game2/siege/ui_attachtimewnd.txt',
    trigger: 'empathy / reign progress', stringRef: 'NORMAL 290:42', durationMs: null, owner: 'lane20', status: 'wired',
    evidence: 'siege.js attach' },
  { mode: 'siege', element: 'respawnCountdown', window: 'siege_respawn', script: 'game2/siege/ui_respawnwnd.txt',
    trigger: 'player dead in siege with respawn snapshot', stringRef: 'NORMAL 290:41', durationMs: null, owner: 'lane20', status: 'wired',
    evidence: 'siege.js respawn' },
  { mode: 'siege', element: 'timeNoticeBox', window: 'siege_timenotice', script: 'game2/msgbox/ui_siegetimenotice.txt',
    trigger: 'siege start-time set confirm', durationMs: null, owner: 'lane20', status: 'wired',
    evidence: 'SIEGE_SCRIPTS.timenotice' },
  { mode: 'siege', element: 'countdown30', window: 'ev_effect', script: 'game2/ui_effectuiwnd.txt',
    trigger: 'server announce loop COUNTDOWN mark 30 min before start', stringRef: 'SIEGE 700:150 @<effectui>2556,1,2000,1',
    durationMs: 2000, owner: 'lane72', status: 'fixed',
    evidence: 'stringtable_siege.txt 700:150 (untagged: chat + effect banner 2556 for 2000 ms)' },
  { mode: 'siege', element: 'countdown10', window: 'ev_effect', script: 'game2/ui_effectuiwnd.txt',
    trigger: 'COUNTDOWN mark 10 min', stringRef: 'SIEGE 700:151 @<effectui>2557,1,2000,1',
    durationMs: 2000, owner: 'lane72', status: 'fixed',
    evidence: 'stringtable_siege.txt 700:151' },
  { mode: 'siege', element: 'countdown5', window: 'ev_effect', script: 'game2/ui_effectuiwnd.txt',
    trigger: 'COUNTDOWN mark 5 min', stringRef: 'SIEGE 700:152 @<effectui>2558,1,2000,1',
    durationMs: 2000, owner: 'lane72', status: 'fixed',
    evidence: 'stringtable_siege.txt 700:152' },
  { mode: 'siege', element: 'startedBanner', window: 'ev_effect', script: 'game2/ui_effectuiwnd.txt',
    trigger: 'battle start notice', stringRef: 'SIEGE 700:55 @<effectui>2559,1,2000,1 / 700:124 @<effectui>2028,1,5000,1',
    durationMs: null, owner: 'lane72', status: 'fixed',
    evidence: 'stringtable_siege.txt 700:55 (2000 ms) and 700:124 (5000 ms)' },
  { mode: 'siege', element: 'resultBanner', window: 'ev_effect', script: 'game2/ui_effectuiwnd.txt',
    trigger: 'won / lost notice', stringRef: 'SIEGE 700:122 @<effectui>2029,1,10000,1 / 700:123 @<effectui>2030,1,10000,1',
    durationMs: 10000, owner: 'lane72', status: 'fixed',
    evidence: 'stringtable_siege.txt 700:122/123' },

  // --- Siege Renew ---
  { mode: 'siegeRenew', element: 'siegeMessage', window: SIEGE_MESSAGE_WINDOW, script: SIEGE_MESSAGE_SCRIPT,
    trigger: 'siegeNotice mode=siegeRenew, routed by the Global string tag', stringRef: 'SIEGE 701:*',
    durationMs: SIEGE_MESSAGE_MS, owner: 'lane72', status: 'fixed',
    evidence: 'same tag routing as classic siege ([siege] 7000 / [message] SystemMessage 7000 / untagged chat only)' },
  { mode: 'siegeRenew', element: 'playTime', window: 'siegeRenewTime', script: 'game2/siege/ui_siege_play_timewnd.txt',
    trigger: 'battle phase; NORMAL 290:51 minutes left', durationMs: null, owner: 'lane20', status: 'wired',
    evidence: 'siege-renew.js timer()' },

  // --- Dead Front (verified: DEAD-FRONT.md, Lanes 45/59) ---
  { mode: 'deadFront', element: 'limitTime', window: 'ev_limittime', script: 'game2/partywar/ui_limittimewnd.txt',
    trigger: 'phase timer Waiting to Start / battle clock', stringRef: 'partywar #300|3-9',
    durationMs: null, owner: 'lane45+events', status: 'wired',
    evidence: 'EventUI.timer; partywar ui_limittimewnd' },
  { mode: 'deadFront', element: 'remainTime', window: 'ev_remaintime', script: 'game2/partywar/ui_remainwartimewnd.txt',
    trigger: 'lobby / application timer', durationMs: null, owner: 'lane45+events', status: 'wired',
    evidence: 'EventUI.lobbyTimer' },
  { mode: 'deadFront', element: 'partyInfo', window: 'ev_partyinfo', script: 'game2/partywar/ui_mypartyinfownd.txt',
    trigger: 'score/rank updates', durationMs: null, owner: 'lane45+events', status: 'wired',
    evidence: 'EventUI.partyInfo' },
  { mode: 'deadFront', element: 'towerGauge', window: 'ev_tower', script: 'game2/partywar/ui_towerwnd.txt',
    trigger: 'Tower of Shield gauge', durationMs: null, owner: 'lane45', status: 'owner-other',
    evidence: 'EventUI.tower; DEAD-FRONT.md verified' },
  { mode: 'deadFront', element: 'attachProcess', window: 'ev_attach', script: 'game2/partywar/ui_attachprocesswnd.txt',
    trigger: 'channel / supply depot capture', durationMs: null, owner: 'lane45', status: 'owner-other',
    evidence: 'EventUI channel gauge; DEAD-FRONT.md verified' },
  { mode: 'deadFront', element: 'result', window: 'ev_result', script: 'game2/partywar/ui_resultwnd.txt',
    trigger: 'end of round / win-lose', durationMs: null, owner: 'lane45', status: 'owner-other',
    evidence: 'EventUI.result; DEAD-FRONT.md verified' },
  { mode: 'deadFront', element: 'centerNotice', window: 'ev_message', script: 'game2/ui_eventmessagewnd.txt',
    trigger: 'wave start / boss spawn / warnings via Messenger', durationMs: EVENT_MESSAGE_MS, owner: 'lane45+lane46', status: 'wired',
    evidence: 'EventUI.notice 15s' },
  { mode: 'deadFront', element: 'waveBannersLeversBosses', window: 'DF-owned', script: 'see DEAD-FRONT.md',
    trigger: 'every wave, lever, boss, win/lose screen', durationMs: null, owner: 'lane45/59', status: 'owner-other',
    evidence: 'DEAD-FRONT.md (verified by Lanes 45/59)' },

  // --- Ice Castle / party-war siblings (verified: ICE-CASTLE-EVIDENCE.md) ---
  { mode: 'iceCastle', element: 'limitTime', window: 'ev_limittime', script: 'game2/partywar/ui_limittimewnd.txt',
    trigger: 'phase timer', durationMs: null, owner: 'events', status: 'wired', evidence: 'same partywar stack as DF' },
  { mode: 'iceCastle', element: 'result', window: 'ev_result', script: 'game2/partywar/ui_resultwnd.txt',
    trigger: 'match end', durationMs: null, owner: 'events', status: 'wired', evidence: 'EventUI.result' },
  { mode: 'iceCastle', element: 'centerNotice', window: 'ev_message', script: 'game2/ui_eventmessagewnd.txt',
    trigger: 'timed map messages', durationMs: EVENT_MESSAGE_MS, owner: 'lane46+events', status: 'wired', evidence: 'EventUI.notice' },

  // --- Colosseum / Infinite / staged dungeons ---
  { mode: 'colosseumArena', element: 'dungeonTime', window: 'ev_dtime', script: 'game2/dungeon/ui_dungeontimewnd.txt',
    trigger: 'arena round timer rows', durationMs: null, owner: 'events', status: 'wired', evidence: 'EventUI ev_dtime' },
  { mode: 'colosseumArena', element: 'matchingWait', window: 'ev_matching', script: 'game2/colosseum/ui_matchingwait.txt',
    trigger: 'solo no-match wait', durationMs: null, owner: 'events', status: 'wired', evidence: 'EventUI ev_matching' },
  { mode: 'infiniteBattle', element: 'dungeonTime', window: 'ev_dtime', script: 'game2/dungeon/ui_dungeontimewnd.txt',
    trigger: 'stage timers', durationMs: null, owner: 'events', status: 'wired', evidence: 'EventUI' },
  { mode: 'infiniteBattle', element: 'scoreboard', window: 'ev_score', script: 'game2/dungeon/ui_dungeonscoreboardwnd.txt',
    trigger: 'combo/fever', durationMs: null, owner: 'events', status: 'wired', evidence: 'EventUI ev_score' },
  { mode: 'infiniteBattle', element: 'count', window: 'ev_count', script: 'game2/dungeon/ui_dungeoncountwnd.txt',
    trigger: 'accumulation counter', durationMs: null, owner: 'events', status: 'wired', evidence: 'EventUI ev_count' },

  // --- Field Boss ---
  { mode: 'fieldBoss', element: 'fieldBossTime', window: 'ev_fbtime', script: 'game2/fieldboss/ui_fieldbosstimewnd.txt',
    trigger: 'field boss window open / schedule', durationMs: null, owner: 'lane40+events', status: 'wired',
    evidence: 'FieldBossRun + EventUI ev_fbtime' },
  { mode: 'fieldBoss', element: 'bossHpBar', window: 'hud_bosshp', script: 'game2/ui_bosshpbar.txt',
    trigger: 'targeting field boss', durationMs: null, owner: 'hud', status: 'wired', evidence: 'hud_bosshp' },
  { mode: 'fieldBoss', element: 'supplyPlate', window: 'shops.fieldboss', script: 'game2/fieldbosssupply/ui_fieldbosssupplywnd.txt',
    trigger: 'field boss supply NPC/roulette', durationMs: null, owner: 'shops', status: 'wired',
    evidence: 'supply.js fieldboss plate' },
  { mode: 'fieldBoss', element: 'centerNotice', window: 'ev_message', script: 'game2/ui_eventmessagewnd.txt',
    trigger: 'spawn / 5-min warnings via map text', durationMs: EVENT_MESSAGE_MS, owner: 'lane46+events', status: 'wired',
    evidence: 'Messenger notice path' },

  // --- OX Quiz ---
  { mode: 'oxQuiz', element: 'question', window: 'oxquiz', script: 'game2/event/ui_oxquizwnd.txt',
    trigger: 'each round question', stringRef: 'OX 2300:28-32', durationMs: null, owner: 'events/gm', status: 'wired',
    evidence: 'ox-quiz-rules OX_QUIZ.window; events.js oxquiz; Global ships no OX result/rank window' },

  // --- Dungeons / instances (verified: DUNGEONS-PER-DUNGEON.md, Lanes 23/38/65) ---
  { mode: 'dungeon', element: 'dungeonTime', window: 'dungeon_time', script: 'game2/dungeon/ui_dungeontimewnd.txt',
    trigger: 'dungeon instance timer', durationMs: null, owner: 'lane23/38', status: 'owner-other',
    evidence: 'dungeons/ui.js; DUNGEONS-PER-DUNGEON.md verified' },
  { mode: 'dungeon', element: 'bossHpBar', window: 'hud_bosshp', script: 'game2/ui_bosshpbar.txt',
    trigger: 'dungeon boss targeted', durationMs: null, owner: 'hud', status: 'wired', evidence: 'hud' },
  { mode: 'dungeon', element: 'waveBannerNotices', window: 'ev_message|effect', script: 'game2/ui_eventmessagewnd.txt',
    trigger: 'dungeon script timed notices / waves', durationMs: EVENT_MESSAGE_MS, owner: 'lane23/38/65', status: 'owner-other',
    evidence: 'DUNGEONS-PER-DUNGEON.md verified' },
  { mode: 'dungeon', element: 'eventLine', window: 'hud_eventline', script: 'game2/systemwnd/ui_eventlinewnd.txt',
    trigger: 'Dungeon::UIHandler EventLineMessage 0x70040027 (duration, fade-in, fade-out from the sender)', durationMs: null,
    owner: 'lane72', status: 'wired',
    evidence: 'decompile FUN_00b83a50 / FUN_00b84110; 64-bit Dungeon::UIHandler builds EventLineMessage with caller values; no 4.2.0 caller fires it' },

  // --- Other scheduled modes (statuses per EVENTS-MODES-COVERAGE.md, Lane 71) ---
  { mode: 'urbanWarfare', element: 'modeUiStack', window: 'urban-warfare-routes.js windows', script: 'game2/dksquare/ui_urban*.txt',
    trigger: 'Sat 21:00 battle (entry 5 min before), FightTime 1800 s, 15 s capture', stringRef: 'strings 650 / 1013-2001', durationMs: null,
    owner: 'lane12/30/71', status: 'wired',
    evidence: 'EVENTS-MODES-COVERAGE.md VERIFIED: GLOBAL share/urbanwarfare time.csv; ONLINE JP guide pno=64' },
  { mode: 'dkSquare', element: 'modeUiStack', window: 'dksquare windows', script: 'game2/dksquare/*.txt',
    trigger: '3-min wait, revive 20 s, forced exit after 1 min', stringRef: 'string cate 160', durationMs: null,
    owner: 'lane30/47/71', status: 'wired',
    evidence: 'EVENTS-MODES-COVERAGE.md VERIFIED: GLOBAL guide 1305/5; ONLINE JP guide pno=61; confirm / move-out seconds removed (no source)' },
  { mode: 'guildWarHunting', element: 'modeUiStack', window: 'ui_huntscoreboardwnd / ui_huntguildinfownd / ui_huntscoreboard_alarm / ui_huntminimapwnd',
    script: 'game2/guildwarhunting/ui_hunt*.txt', trigger: 'Global GM guildwarhunting_open|ready|start|finish [world index] (shared host)', durationMs: null, owner: 'events', status: 'wired',
    evidence: 'src/systems/network/guild-war-hunting.js opens the Global guildwarhunting windows from the host run; solo DefenseRun refuses (shared-host GM flow only); pan_light_N kept hidden (no source for their meaning: removed); session timers removed (EVENTS-MODES-COVERAGE.md)' },
  { mode: 'guildWarHunting', element: 'topGuildMessage', window: SIEGE_MESSAGE_WINDOW, script: SIEGE_MESSAGE_SCRIPT,
    trigger: 'hunt finished: the final scoreboard first shows (showHuntTopGuild)', stringRef: 'NORMAL 40:216, <NAME> = rank 1 guild',
    durationMs: GWH_TOP_GUILD_MS, owner: 'lane72', status: 'fixed',
    evidence: 'decompile 32-bit-main FUN_00d00b70 (decompiled.c 992059): string 0x2800d8, FUN_00cff010 message +4 = 8000, posted to SiegeMessage; GLOBAL stringtable_pc 40:216',
    notes: 'the 8000 ms message had no 4.2.0 caller' },
  { mode: 'guildTournament', element: 'modeUiStack', window: 'guild-tournament.js windows', script: 'game2/guildtournament/*.txt',
    trigger: 'ready 5 min, round 10 min, break 5 min, 3 rounds; WAITING_TIME 180', durationMs: null,
    owner: 'lane40/71', status: 'wired',
    evidence: 'EVENTS-MODES-COVERAGE.md VERIFIED: GLOBAL share/guildtournament; ONLINE JP notice no=589; phases with no source skipped' },
  { mode: 'mapEvent', element: 'timedNotices', window: 'ev_message', script: 'game2/ui_eventmessagewnd.txt',
    trigger: 'GM /gm mapevent 1-5 only (map 706 Hidden Mansion of Kastotica); no automatic trigger', durationMs: EVENT_MESSAGE_MS, owner: 'lane49/64', status: 'wired',
    evidence: 'EVENTS-MODES-COVERAGE.md WIRED; LANE-64-REPORT.md map-event-presentation.js; eventInfo.enable=false (no event-info UI); automatic trigger removed' },
  { mode: 'monsterCarnival', element: 'teamModeUi', window: 'carnival_*', script: 'game2/forgottenshipwreck/*.txt',
    trigger: 'none: carnival-register refused (closed, 403)', durationMs: null, owner: 'lane71', status: 'removed',
    evidence: 'EVENTS-MODES-COVERAGE.md CLOSED: no Global entrance; the Forgotten Shipwreck dungeon reward roulette (ui_reward_slotwnd) stays on the dungeon path' },
  { mode: 'race', element: 'modeUiStack', window: '-', script: 'game2/race/*.txt',
    trigger: 'none', durationMs: null, owner: 'lane47', status: 'removed',
    evidence: 'EVENTS-MODES-COVERAGE.md REMOVED: Global never opens game2/race windows' },
  { mode: 'trainingCamp', element: 'modeUiStack', window: '-', script: '-',
    trigger: 'none', durationMs: null, owner: 'lane40', status: 'removed',
    evidence: 'EVENTS-MODES-COVERAGE.md REMOVED: no Global source for lobby / play timings' },
  { mode: 'phantomCastle', element: 'entry', window: '-', script: '-',
    trigger: 'none: entry refused (closed)', durationMs: null, owner: 'lane40', status: 'removed',
    evidence: 'EVENTS-MODES-COVERAGE.md CLOSED: no entrance in Global' },
]);

export function catalogByMode(mode) {
  return MODE_UI_CATALOG.filter((r) => r.mode === mode);
}

export function catalogGaps() {
  return MODE_UI_CATALOG.filter((r) => r.status === 'gap' || r.status === 'unresolved');
}

/**
 * Global Chat::UIHandler routing of one string-table line by its leading tag:
 *   [siege] / [effectstr] -> SiegeMessage 7000 ms, [message] -> SystemMessage 7000 ms, no tag -> chat only.
 * Also lists the "@<effectui>id,a,ms,b" banners the line carries.
 */
export function globalMessageRoute(raw) {
  const s = String(raw ?? '');
  const tag = /^\s*\[(siege|effectstr|message)\]/.exec(s)?.[1] || null;
  const effectUi = [];
  for (const m of s.matchAll(/@<effectui>(\d+),(\d+),(\d+),(\d+)/gi)) {
    effectUi.push({ id: Number(m[1]), a: Number(m[2]), ms: Number(m[3]), b: Number(m[4]) });
  }
  if (tag === 'siege' || tag === 'effectstr') return { tag, window: 'siege', durationMs: SIEGE_MESSAGE_MS, effectUi };
  if (tag === 'message') return { tag, window: 'system', durationMs: SYSTEM_MESSAGE_MS, effectUi };
  return { tag: null, window: null, durationMs: null, effectUi };
}

/** Show a routed Global line: effect banners, then the siege or system window. Chat stays with the caller. */
export function presentGlobalMessage(game, raw, text) {
  const route = globalMessageRoute(raw);
  for (const e of route.effectUi) {
    try { game?.eventsSystem?.banner?.(e.id, e.ms); } catch (err) { console.warn('[mode-ui] banner', err); }
  }
  const body = String(text ?? '');
  if (!body) return null;
  if (route.window === 'siege') return showSiegeMessage(game, body, { durationMs: route.durationMs });
  if (route.window === 'system') { try { game?.hud?.toast?.(body); } catch (err) { console.warn('[mode-ui] system message', err); } }
  return null;
}

/**
 * Open Global ui_siegemessagewnd (7 s, the duration Chat::UIHandler sends). Chat remains separate.
 * Uses existing approved script only.
 */
export function showSiegeMessage(game, text, { durationMs = SIEGE_MESSAGE_MS } = {}) {
  const body = String(text ?? '');
  if (!body || !game?.uiwin) return null;
  const ui = game.uiwin;
  if (typeof ui.registerWindow === 'function' && !ui.has?.(SIEGE_MESSAGE_WINDOW) && !ui.window?.(SIEGE_MESSAGE_WINDOW)) {
    ui.registerWindow(SIEGE_MESSAGE_WINDOW, {
      script: SIEGE_MESSAGE_SCRIPT,
      hud: true,
      escClose: false,
      remember: false,
      band: 'system',
    });
  }
  const gen = (game._siegeMessageGen = (game._siegeMessageGen || 0) + 1);
  const open = ui.open?.(SIEGE_MESSAGE_WINDOW) || ui.openWindow?.(SIEGE_MESSAGE_WINDOW);
  const apply = (win) => {
    if (!win || game._siegeMessageGen !== gen) return win;
    const lbl = win.control?.('lbl_message') || win.control?.('lbl_message_bg');
    if (lbl?.setRichText) lbl.setRichText(body);
    else if (lbl?.setText) lbl.setText(body);
    if (Number.isFinite(durationMs) && durationMs > 0) {
      clearTimeout(game._siegeMessageTimer);
      game._siegeMessageTimer = setTimeout(() => {
        if (game._siegeMessageGen === gen) ui.close?.(SIEGE_MESSAGE_WINDOW);
      }, durationMs);
    }
    return win;
  };
  if (open && typeof open.then === 'function') return open.then(apply);
  return apply(open);
}

/** Test/helper: describe the UI emission a siegeNotice produces for its Global string `raw`. */
export function siegeNoticePresentation(record, raw = '') {
  const code = Array.isArray(record?.code) ? record.code : null;
  const route = globalMessageRoute(raw);
  return {
    type: 'siegeNotice',
    window: route.window === 'siege' ? SIEGE_MESSAGE_WINDOW : route.window === 'system' ? SYSTEM_MESSAGE_WINDOW : null,
    script: route.window === 'siege' ? SIEGE_MESSAGE_SCRIPT : route.window === 'system' ? SYSTEM_MESSAGE_SCRIPT : null,
    durationMs: route.durationMs,
    effectUi: route.effectUi,
    stringRef: code ? `SIEGE ${code[0]}:${code[1]}` : null,
    code,
    chat: true,
  };
}

export function eventNoticePresentation(text) {
  return {
    type: 'eventNotice',
    window: 'ev_message',
    script: 'game2/ui_eventmessagewnd.txt',
    durationMs: EVENT_MESSAGE_MS,
    text: String(text ?? ''),
  };
}

/** Global EventMessageWnd markup for the queued lines: "<center>" + line + "\\" per line (FUN_00b34270). */
export function eventMessageMarkup(lines) {
  return (lines || []).map((l) => `<center>${String(l ?? '')}${EVENT_MESSAGE_LINE_BREAK}`).join('');
}

/** The same markup for the 4.2.0 label renderer, whose line break is "\n" (the trailing break adds no line). */
export function eventMessageDisplay(lines) {
  return eventMessageMarkup(lines).split(EVENT_MESSAGE_LINE_BREAK).join('\n').replace(/\n$/, '');
}

/**
 * Global EventMessageWnd queue (FUN_00b341b0 / FUN_00b34220): at most 5 lines and one shared age counter.
 * A 6th line drops the oldest and resets the counter; otherwise adding a line keeps the counter running.
 * Each frame adds the elapsed ms; past 15000 ms the oldest line drops and the counter resets. Empty = hidden.
 */
export class EventMessageQueue {
  constructor() { this.lines = []; this.ageMs = 0; }
  push(line) {
    if (this.lines.length >= EVENT_MESSAGE_QUEUE) { this.lines.shift(); this.ageMs = 0; }
    this.lines.push(String(line ?? ''));
    return this;
  }
  /** Advance by ms; true when a line expired (the caller repaints or hides). */
  tick(ms) {
    if (!this.lines.length) return false;
    this.ageMs += Number(ms) || 0;
    if (this.ageMs <= EVENT_MESSAGE_MS) return false;
    this.lines.shift();
    this.ageMs = 0;
    return true;
  }
  /** Remove one specific line (the OX quiz removes its own expired wall notice); true when it was queued. */
  drop(line) {
    const i = this.lines.lastIndexOf(String(line ?? ''));
    if (i < 0) return false;
    this.lines.splice(i, 1);
    if (!this.lines.length) this.ageMs = 0;
    return true;
  }
  get visible() { return this.lines.length > 0; }
  get markup() { return eventMessageMarkup(this.lines); }
  get display() { return eventMessageDisplay(this.lines); }
}

/** Global FUN_00d00b70 text: stringtable_pc 40:216 with <NAME> = the first-ranked guild. */
export function gwhTopGuildText(template, name) {
  const t = String(template || GWH_TOP_GUILD_TEXT);
  return name ? t.split('<NAME>').join(String(name)) : '';
}
