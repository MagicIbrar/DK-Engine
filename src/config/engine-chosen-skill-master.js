// Skill master popup + skill blind: game2/skill/ui_skillmasterwnd.txt ("Learn Skill" 100:4, skill
// icon, centred label, OK / close) and game2/skill/ui_skillblindwnd.txt (skill_blind_win: a full-screen blind with a
// clickable cut-out pan_clickable_area and four blocking panels pan_unclickable_area_0..3).
// The shipped client data names neither window anywhere else, gives lbl_skillmaster no text and has no trigger for
// either, so the values below are ENGINE-CHOSEN (not in Global data). Everything else comes from the scripts:
// placement (rect 0 0 181 167 = the script's centred default), sprites (screen skill_up), title 100:4, fonts.
// Strict parity: no scaling, no sound, no extra effects; the learn message itself stays the original
// stringtable_skill 60:25 "You have learned the skill:  [" + name + "]" that the client already logs.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const SKILL_MASTER_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // trigger: the popup opens when a skill goes from unlearned (0) to learned (>= 1): an announced local learn
  // (skills engine skilllearn level 1, not silent) or, under server authority, a skill that appears in the
  // canonical save.skills between two profiles of the same character (the first profile is only the baseline)
  trigger: 'firstLearn',
  // level ups of an already learned skill (60:26) keep only the original chat line, no popup (the window title is
  // 100:4 "Learn Skill")
  popupOnLevelUp: false,
  // silent learns (GM tools, boxes, migrations) and skill resets never open it
  popupOnSilent: false,
  // lbl_skillmaster text: stringtable_skill 60:25 + skill name + "]" (the same line the client logs)
  labelMessage: 25,
  // several first learns in a row queue and show one after another (OK / close / Esc shows the next one)
  queue: true,
  // queue cap so a bulk grant cannot stack dozens of popups; extra learns are still logged in chat
  maxQueue: 8,
  // the blind has no shipped trigger and its image (screen testskill index 5) is absent from com/imagetable.txt, so
  // Global draws no picture for it: the engine never opens it on its own; game.skillMaster.blind(rect) opens it with
  // the cut-out over a reference-px rect (tutorial / help callers) and it closes on the next first learn or Esc
  autoOpenBlind: false,
  closeBlindOnLearn: true,
  blindEscClose: true,
});