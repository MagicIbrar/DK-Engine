// Event-weapon attack sound (item_shape Targeteffect -> modeleffect 38/1/code3). Mechanism and values are native; see
// src/systems/items/weapon-target-sound.js. Only the mapping of engine hit events onto the native attack results is chosen here.
export const TARGET_SOUND = Object.freeze({
 code1: 38, code2: 1,                     // NATIVE: modeleffect group 38 / code2 1
 landedHitsOnly: true,                    // ENGINE-CHOSEN: a miss plays nothing (whether the native results include misses is not decoded)
 skillHits: true,                         // ENGINE-CHOSEN: plain and skill hit results both play it
 attackerKinds: Object.freeze(['player']),// ENGINE-CHOSEN: player attackers only; the native routine reads a character's weapon items
 distinctLeftItem: true,                  // ENGINE-CHOSEN: the left-hand slot counts only for a different item (one item drawn in both hands plays once)
});
