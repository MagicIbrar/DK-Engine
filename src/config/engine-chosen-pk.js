// FIELD PK (forced attack, Ctrl) - ENGINE-CHOSEN values. The Global data names the pieces (maplist IsPvP / PVP_PeaceZone / IsNotIncreaseChao,
// the keymap "Force Attack" = Ctrl, stringtable_pc cate 1003 "PK" messages, share/pc/{chaotic,pkcount,pklevelcap}.csv) but not how long a
// forced attack stays armed, how often a notice repeats or what colour a wanted name has; those are chosen here.
export const FIELD_PK = Object.freeze({
  tag: 'ENGINE-CHOSEN (not in Global data)',
  // A forced attack / skill command arms the attacker for this long: the swings and area skills that follow keep hitting players until it
  // runs out. Without a new Ctrl action the attacker is a normal player again (monsters, party and everybody else are never touched).
  forcedWindowMs: 4000,
  // "<name> attacked you." / "has been attacked by you." (1003:1 / 1003:2) are said once per attacker-target pair per this long.
  noticeRepeatMs: 10000,
  // Wanted status: the chaotic value (share/pc/chaotic.csv bands in life.json pk.chaotic) above 0 colours the name purple; the bands that
  // force a respawn (the data's own respawn column > 0) colour it red.
  wantedColors: Object.freeze({ 1: '#c77dff', 2: '#ff5a5a' }),
  // VERIFIED (not engine-chosen), official Global guide 62 "Battle status" (webapi-dekaron.ubifungames.com GetGameGuidePost?guideNo=62):
  // "It lasts for 60 seconds from the moment you start PK with the character." A battle-status (purple) aggressor is a lawful
  // target for that long, and the guide's combat-mode refusals (vehicle / NPC / channel / character selection) apply for it too.
  battleStatusMs: 60_000,
  // Fallback only. The native rate is per map: share/maplist.csv wChaoticDecrease per dwChaoticDecreasePeriod (ms), applied by
  // src/game/chaotic-decay.js (3/60000 on 132 active maps, 1/60000 on 52, 2/60000 on 601-603, 0 on 11 dungeons). This 3/minute
  // value is used only when a row lacks those columns (synthetic fixtures). Decay happens only while logged in.
  decayPerSec: 3 / 60,
  // Killing a player who is already wanted (chaotic > 0) adds nothing to the killer's chaotic value.
  justKill: true,
});
export const PK_TEXT = Object.freeze({   // stringtable_pc.txt cate 1003 (verbatim)
  1: 'attacked you.', 2: 'has been attacked by you.', 3: 'cannot be attacked.', 4: 'killed you.', 5: 'has been killed by you.',
  6: '[Message] Your Tendency Index has decreased; your Tendency has changed to Helion [Good].',
  7: '[Message] Your Tendency Index has increased; your Tendency has changed to Niete [Evil].',
  8: '[Message] You cannot PvP while in the Safety Zones.',
  9: '[Message] The character has entered the Safe Time mode; you cannot attack the target.',
});
/** Combat-mode refusals (verbatim native strings): stringtable_pc 40:108, stringtable_party 70:164, stringtable_system 101:248. */
export const COMBAT_TEXT = Object.freeze({
  service: '[Message] This cannot be used in the Combat mode.',
  channel: 'Users in Niete (Evil-side) or in combat cannot switch channels.',
  premium: 'The Almighty Holy Water Premium feature is not available in combat.',
});
