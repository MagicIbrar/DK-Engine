// Mainbar extras (game2/mainbar: ui_monsterquickslotwnd, ui_spellcountwnd, ui_upkeepstatuswnd and the lbl_spellcount
// label of ui_buffwnd / ui_skillbuffwnd): values the shipped client data does not contain.
// Every value here is ENGINE-CHOSEN (not in Global data). Data-backed values stay in the data:
//   share/change_monster.csv (INDEX, ACTION, MONSTER_INDEX, MONSTER_HEIGHT, MONSTER_SCALE, MONSTER_COMBO, COMBO_START,
//     Buff = itemstatus index, Skill_1..5), share/skill/status.csv option STATUS_CHANGE_MONSTER (value = change_monster
//     INDEX) through gamedata/skills_status.json, the window scripts (rects, images, tooltip 23|55 "Transfom Cancel
//     Button") and the status icons / option codes of every buff.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const MAINBAR_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,

  // lbl_spellcount (rect 0 0 30 30 over the left-most cell of the first icon row): the number of active statuses of
  // that window that have no drawn cell (each row draws 10 icons), shown as "+N"; empty while everything fits.
  spellCountLabel: Object.freeze({ iconsPerRow: 10, prefix: '+' }),

  // ui_spellcountwnd: pan_attack / pan_defense count the player's active non-harmful statuses that raise an attack
  // or a defence value (an option code below with a positive value). A status with both kinds counts in both.
  // A panel is shown only while its count is above 0; the tooltip lists the counted statuses.
  // enabled:false (the bottom-right counter with a 2 and a 3 reads as an ammo indicator but counts buffs): both
  // panels of the shipped script draw imagetable `bow` #1 (UI\Game\theme01\bow.dds, the same arrow sprite as the
  // arrow-stock window ui_stackcountwnd), so the counts looked like an ammo indicator and duplicated the buff bar.
  // Buffs are shown only by the buff windows; the counter window stays registered but is not opened.
  spellCount: Object.freeze({
    enabled: false,
    attackPrefixes: Object.freeze(['DAMAGE_MINPHYSICAL', 'DAMAGE_MAXPHYSICAL', 'DAMAGE_PHYSICAL', 'DAMAGE_MINMAGICAL',
      'DAMAGE_MAXMAGICAL', 'DAMAGE_MAGICAL', 'DAMAGERATE_', 'DAMAGEADD_', 'SIZEDAMAGERATE_', 'RATING_ATTACK_ADD',
      'RATING_CRITICAL_ADD', 'SPEED_ATTACK_MUL', 'COMBINE_OPTION_COMBINE_MUL']),
    defensePrefixes: Object.freeze(['DEFENSE_', 'RESIST_', 'RATING_BLOCKING_ADD', 'RATING_GUARD_ADD',
      'RATING_CRITICAL_SUB', 'REFLECT_', 'SHIELD_MAX', 'HP_MAX_', 'DAMAGERATE_DAMAGEHP_MUL']),
    // listed in both prefix families above but only a defence value
    attackExclude: Object.freeze(['DAMAGERATE_DAMAGEHP_MUL']),
    maxShown: 99,
  }),

  // ui_upkeepstatuswnd: "upkeep" statuses are the long-running ones a player keeps up (premium services, day/month
  // items): a total duration of at least minDurationSec (or a premium service entry). Up to 15 icons fill
  // btn_upkeepstatus_0..14 in button order; tooltip = the buff tooltip, right click = cancel (as in the buff windows).
  // They also stay in their buff window row.
  upkeep: Object.freeze({ minDurationSec: 3600, maxIcons: 15, iconGroup: 'buffer_b' }),

  // Monster transformation (STATUS_CHANGE_MONSTER): the player is drawn as change_monster MONSTER_INDEX at that
  // monster's own native size (its own model and monsters.json data, exactly as the monster itself is drawn).
  monsterForm: Object.freeze({
    // MONSTER_SCALE and MONSTER_HEIGHT are data with no stated meaning: no modifier is added for either.
    monsterScale: 'not applied (Global parity: native size)',
    monsterHeight: 'not applied (Global parity: native size)',
    // The data lists no transformed skills (Skill_1..5 are all 0): class skills, the normal quickslot and the item
    // belt stay usable while transformed; ui_monsterquickslotwnd shows only its plate, its cancel button
    // (btn_close: cancels the transformation status) and a slot for each non-zero Skill_n.
    keepClassSkills: true,
    controlTypeText: '',            // lbl_controltype has no text source
    liftAboveQuickslot: true,       // drawn right above the normal quickslot window (same left-bottom anchor)
    runSpeed: 2.6,                  // cells/s of the player's ground speed above which the monster plays run
    walkSpeed: 0.25,                // ... above which it plays walk (idle below)
  }),
});
