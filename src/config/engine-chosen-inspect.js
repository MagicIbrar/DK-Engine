// Inspect player (game2/previewplayer/ui_previewplayerwnd.txt, window "preview", title 2000:16 "Preview", Ok 2000:15):
// values the shipped client data does not contain. Every value here is ENGINE-CHOSEN (not in Global data).
// Data-backed values stay in the script: the 341x419 frame, pan_screen 328x328 (the model area), btn_left / btn_right
// rotate, btn_zoom_out / btn_zoom_in and sld_zoom (min 1, max 76, minmaxpos 1..76) zoom, btn_ok / btn_exit close.
// Used by src/systems/inspect (rules.js + window.js).
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const INSPECT_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // How the window opens. The player menu strings (240:0-13) have no "Preview" / "Inspect" row, so the pcpop menu
  // (target plate btn_showpcpop) gets a row labelled with the window's own title 2000:16, and a chat command.
  menu: Object.freeze({ cate: 2000, code: 16, order: 16 }),
  command: '/inspect',
  // /inspect with no name: the selected player, else your own character.
  emptyCommandTarget: 'target-or-self',
  // who can be inspected: any connected character the client currently sees (network.players), no range check
  // beyond the visible area; a target that leaves keeps its last look in the open window.
  maxRange: null,
  // sld_zoom value -> camera zoom (1 = the measured full-body fit; 0.5 farther, 3 closer), linear over min..max
  zoomRange: Object.freeze({ min: 0.5, max: 3 }),
  zoomStartValue: 16,   // slider value of zoom 1 (1 + 75 * (1 - 0.5) / 2.5 = 16)
  zoomButtonStep: 5,    // btn_zoom_in / btn_zoom_out move the slider by 5 (it also auto-repeats while held)
  rotateRadPerSec: 2.2, // btn_left / btn_right turn the model while held (a click turns it 0.25 rad)
  rotateClickRad: 0.25,
  startYaw: 0.35,       // the model starts turned slightly to its left (same as the costume / wing previews)
  // pan_screen is drawn opaque black behind the model (the frame is translucent: the world and its nameplates, which
  // sit below every window, would show through the model area), as the costume / wing previews' black panel
  screenBackdrop: '#000',
  refreshMs: 1000,      // the open window re-reads the target's look (equipment / wing) once a second
  // chat lines (the client has no inspect messages)
  messages: Object.freeze({ usage: 'Choose a connected character you can see: /inspect Name', help: 'Preview a connected character: /inspect Name (or the selected player)' }),
});