// Dead Front / Ice Castle (party war): this file no longer holds any timing. Data-backed values stay in
// gamedata/events.json (share/partywar/*.csv, script/partywar/icecastle.csv: phase times, fields, respawns, rewards,
// tower damage, scriptOrder, strings).
//   Dead Front  -> src/config/dead-front-script-ref.js (Lane 59, older server reference, per version)
//   Ice Castle  -> src/config/ice-castle-script-ref.js (Lane 68: Global / older server reference / online, each labelled;
//                  the former open Ice Castle / party-war values were replaced
//                  by a sourced value or removed; see ICE_CASTLE_REMOVED there)
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
// Lane 59: values re-sourced from the older server reference (server-ref, data only, never run):
// ScriptProcess.dll build 11.07.29 (pdb d:\World\Fgc\Dekaron\11.07.29.95), IScript::Dungeon classes Dead_Front_Rabble /
// Peer / Baron / Earl / Duke / Arch / Doom / Hell and the _DK variants. Not Global; Global data has no timings.
export const OLDER_SERVER_REF_TAG = 'older server reference (ScriptProcess.dll 11.07.29 Dead_Front_*)';

/** Superseded: the Dead Front values are DEAD_FRONT_SCRIPT_REF (src/config/dead-front-script-ref.js, older server
 *  reference, per version). The engine-chosen guard placement / half-HP / armory timers were removed (Lane 59). */
export const DEAD_FRONT_ENGINE_CHOSEN = Object.freeze({
  tag: OLDER_SERVER_REF_TAG,
  supersededBy: 'src/config/dead-front-script-ref.js',
});

/** Superseded (Lane 68): the Ice Castle and shared party-war values are in src/config/ice-castle-script-ref.js. */
export const ICE_CASTLE_SUPERSEDED_BY = 'src/config/ice-castle-script-ref.js';