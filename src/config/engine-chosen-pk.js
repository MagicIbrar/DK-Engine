// FIELD PK (forced attack, Ctrl). The Global data names the pieces (maplist IsPvP / PVP_PeaceZone / IsNotIncreaseChao, the keymap
// "Force Attack" = Ctrl, stringtable_pc cate 1003 "PK" messages, share/pc/{chaotic,pkcount,pklevelcap}.csv). Lane 51 g: every value
// below is labelled SOURCE / VERIFIED or JUDGMENT.
export const FIELD_PK = Object.freeze({
  tag: 'lane 51 g: SOURCE / VERIFIED / JUDGMENT per key',
  // forcedWindowMs 4000 REMOVED (lane 51 g). SOURCE: FINAL 64-bit decompile GameUser::EventHandler::Command::Force::State::PK (ctor
  // 0x7ff670988480 stores the target id + a forced byte, FUN_7ff670988550 reads it, no timer): the forced flag is part of the attack /
  // cast command on that target. Host: server/world/pvp.mjs noteForcedIntent (armed until a command without the flag); client:
  // src/systems/network/field-pk.js latches the forced target with no expiry.
  // JUDGMENT (lane 51 g): a forced hit still credits the PK kill (chaotic) when the victim falls within the guide-62 battle status
  // (60 s) of that hit, e.g. a damage-over-time finish. Reasoning: the only PK duration any source gives is that battle status.
  killCreditMs: 60_000,
  // noticeRepeatMs REMOVED (f pass: no source). "<name> attacked you." / "has been attacked by you." (1003:1 / 1003:2) are said when
  // the PK starts and again only once the guide-62 battle status below (60 s from the start of the PK) has run out for that pair.
  // Wanted status: chaotic > 0 with no prison respawn (chaotic.csv wRespawnIndex=0) uses purple; bands with
  // wRespawnIndex > 0 use red. Hex from Global script/string/stringtable_color.txt purpul1=C1C1FF / red1=FF3300
  // (also hard-coded 0xc1c1ff / 0xff3300 in Global client decompiled name-draw).
  wantedColors: Object.freeze({ 1: '#c1c1ff', 2: '#ff3300' }), // VERIFIED stringtable_color purpul1/red1 + decompiled 0xc1c1ff/0xff3300
  // VERIFIED (not engine-chosen), official Global guide 62 "Battle status" (webapi-dekaron.ubifungames.com GetGameGuidePost?guideNo=62):
  // "It lasts for 60 seconds from the moment you start PK with the character." A battle-status (purple) aggressor is a lawful
  // target for that long, and the guide's combat-mode refusals (vehicle / NPC / channel / character selection) apply for it too.
  battleStatusMs: 60_000,
  // decayPerSec fallback REMOVED (f pass: no source). The rate is only the map's share/maplist.csv wChaoticDecrease per
  // dwChaoticDecreasePeriod (src/game/chaotic-decay.js); a row without those columns decays nothing.
  // JUDGMENT (lane 51 g; no source gives the rule): killing a player who is already wanted (chaotic > 0) adds nothing to the killer's
  // chaotic value. Reasoning: a wanted player is a lawful target (guide 62 battle status / native wanted colour), like a guild war
  // kill, which official JP notice dekaron-hangame no=1168 says gives no Niete increase.
  justKill: true,
});
export const PK_TEXT = Object.freeze({   // stringtable_pc.txt cate 1003 (verbatim)
  1: 'attacked you.', 2: 'has been attacked by you.', 3: 'cannot be attacked.', 4: 'killed you.', 5: 'has been killed by you.',
  6: '[Message] Your Tendency Index has decreased; your Tendency has changed to Helion [Good].',
  7: '[Message] Your Tendency Index has increased; your Tendency has changed to Niete [Evil].',
  8: '[Message] You cannot PvP while in the Safety Zones.',
  9: '[Message] The character has entered the Safe Time mode; you cannot attack the target.',
  // stringtable_pc cate 1003 codes 10-11 (verbatim). Duration = formula.ini dwNonPKTime (30000 ms) matching code 10.
  10: '[Message] You  entered the Safe Time mode; you cannot attack or be attacked for 30 seconds.',
  11: '[Message] You are in the Safe Time mode; you cannot attack for now.',
});
/** Combat-mode refusals (verbatim native strings): stringtable_pc 40:108, stringtable_party 70:164, stringtable_system 101:248. */
export const COMBAT_TEXT = Object.freeze({
  service: '[Message] This cannot be used in the Combat mode.',
  channel: 'Users in Niete (Evil-side) or in combat cannot switch channels.',
  premium: 'The Almighty Holy Water Premium feature is not available in combat.',
});
