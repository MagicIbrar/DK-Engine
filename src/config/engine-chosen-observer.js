// OBSERVER: the values the Global data does not define. Every value carries its own ENGINE-CHOSEN tag.
// Defined by the data and read at run time (src/systems/observer/observer-rules.js):
//   share/observer/info.csv       siege venue: map 23, 10 named areas (X, Y), MaxUserCount 1000, EnterEnableTime 1000, fSpeed 10
//   share/guildobserver/info.csv  guild venue: map 22, POSX / POSY 266,250, MaxUserCount 1000, fSpeed 100
//   share/maplist.csv             map 22 IsGuildObserver 1; map 23 IsSiege 1
//   npc job 40 ENTER_GUILD_OBSERVER (Blake 135, Cain 734); strings 2100 (windows), 2101 (siege area names), 241 (pop buttons)
//   windows script/ui/game2/observer/ui_observer_{enter,exit,areamove,option,pop}wnd.txt
// PvP numbers are not used by observing (observers never fight); any PvP rule stays in src/game/pvp-rules.js.
export const OBSERVER_CHOSEN = Object.freeze({
  // NATIVE: job 40 serves guild observation; Bastian 753 job 36 serves the classic siege.
  jobVenues: Object.freeze(['guild', 'siege']),
  // ENGINE-CHOSEN (not in Global data): how close (cells) to the job 40 NPC the host accepts an entry.
  npcRadius: 12,
  // NATIVE: itemetc 54501/54502, descriptions 18/19, and strings 2100:10/15.
  consumeItem: Object.freeze({siege:54501,guild:54502}),
  // NATIVE: one ticket is consumed, so retain both original cautions.
  stripItemCaution: false,
  // ENGINE-CHOSEN (not in Global data): EnterEnableTime is read as milliseconds that must pass between leaving and entering again.
  enterEnableUnit: 'ms',
  // ENGINE-CHOSEN (not in Global data): guildobserver/info.csv has no EnterEnableTime column; the guild venue uses this.
  guildEnterEnableMs: 1000,
  // ENGINE-CHOSEN (not in Global data): the siege venue lands on this area row (0 = Siege Portal - Offense).
  siegeEntryArea: 0,
  // ENGINE-CHOSEN (not in Global data): fSpeed has no defined unit; the Observer Camera flies at fSpeed cells/s exactly as written (no clamp).
  cameraSpeedUnit: 'cells/s',
  // ENGINE-CHOSEN (not in Global data): walking while observing keeps the normal run speed (the host movement authority is unchanged).
  walkSpeed: 'normal',
  // ENGINE-CHOSEN (not in Global data): Observer UI Options defaults (Chat Window on, Observer Camera off, Siege Status Window on).
  defaults: Object.freeze({ chat: true, camera: false, situation: true }),
  // ENGINE-CHOSEN (not in Global data): Accompany walks after the selected player and stops this many cells behind.
  followDistance: 3,
  // ENGINE-CHOSEN (not in Global data): Accompany re-aims every this many ms.
  followEveryMs: 700,
  // ENGINE-CHOSEN (not in Global data): actions an observer may still send (walk, stop, chat, emote, the observer service).
  actions: Object.freeze(['move', 'stop', 'chat', 'emote', 'observer']),
  // ENGINE-CHOSEN (not in Global data): observers are hidden from every other player, monsters ignore them, PvP cannot target them.
  hidden: true,
  // ENGINE-CHOSEN (not in Global data): Exit returns the observer to where they stood when they entered.
  exitTo: 'entry',
  // ENGINE-CHOSEN (not in Global data): the client refreshes the observer counts this often while observing (ms).
  refreshMs: 5000,
  // ENGINE-CHOSEN (not in Global data): Siege Status Window line while the shared host runs no siege war.
  situationIdle: 'Siege Status: no siege war is in progress.',
  // ENGINE-CHOSEN (not in Global data): the job 40 venue chooser prompt.
  chooseText: 'Where would you like to observe?',
  // ENGINE-CHOSEN (not in Global data): a venue whose map the shared host cannot load (siege maps today) is left out of the chooser.
  closedVenues: 'hidden',
  // ENGINE-CHOSEN (not in Global data): single-player keeps the original job 40 text (there is nobody to watch).
  offline: 'original-text',
});
