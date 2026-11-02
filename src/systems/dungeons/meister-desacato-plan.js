// Dungeon floors (2026-10-29): 544 [Meister]Desacato - the Meister's Test solo run.
// Every monster and its stats come from Global; the room positions are the engine's default (configurable).
//
// Source labels:
//   'Global'  - Global client data (quests.json quest 1624 "Meister's Test", monsters.json 7742-7746,
//               dungeons.json maps.544 messages/bricks/NPCs).
//   'online'  - https://w.atwiki.jp/espritlibre/pages/295.html (Meister Desacato: Quilue Liana -> Kintais ->
//               Illipia -> Binaelle Fairie memories, then Enigma; solo).
//   ENGINE-DEFAULT (configurable) - no source gives a spawn X/Y: each boss stands in the middle of its room,
//               between the 4 Global gate bricks 101-104 (x 254; y 363.2 / 272.6 / 175.1 / 78.8).
//
// Progression ("same kind of boss, harder each room"), Global monsters.json, all level 175 rank 3:
//   7742 Quilue Liana's Soul      HP 1,094,231   Global message 5016
//   7743 Kintais's Soul           HP 1,181,770   Global message 5011
//   7744 Illipia's Soul           HP 1,269,308   Global message 5012
//   7745 Binaelle Fairie's Soul   HP 1,356,847   Global message 5013
//   7746 Enigma (final stage)     HP 1,697,266   Global message 5014
// Counts: one of each (Global quest 1624: objective 0 = the 4 souls x1 each, objective 1 = Enigma x1).
// Gate rule: killing a room's boss opens the gate brick toward the next room (ENGINE-DEFAULT, inferred from the
// Global brick layout; all 4 bricks are IsCreate=1).
// Reezena 5473 (begin): Global 5001 "Talk to Reezena to start instantly." / 5031 "You have already started."
// Reezena 5474 (end):  Global 10011 "Quit." / 5032 "You haven't defeated the Final Boss Enigma yet."
// Time limit 720 s is Global's (maps.544.timeLimit) and stays with the director.
// Data copy + instructions: server-ref\dungeon-floors\

export const MEISTER_MAP = 544;
export const MEISTER_SOURCE = 'Global quest 1624 + monsters.json; online: https://w.atwiki.jp/espritlibre/pages/295.html';

// [monster, x, y, cell, count, global message, gate opened on kill]
export const MEISTER_ROOMS = [
  [7742, 254, 405, 0, 1, 5016, 101],
  [7743, 254, 318, 0, 1, 5011, 102],
  [7744, 254, 224, 0, 1, 5012, 103],
  [7745, 254, 127, 0, 1, 5013, 104],
  [7746, 254, 57, 0, 1, 5014, null],
];
const FINAL = 7746, BEGIN_NPC = 5473, END_NPC = 5474;

function enigmaDead(d) {
  const st = (d.stages || []).find(s => s.rows?.[0]?.[0] === FINAL);
  return !!st?.done;
}

export function meisterDesacatoPlan() {
  return {
    name: 'global-544-meister',
    setup(d) {
      d.stages = MEISTER_ROOMS.map(([mon, x, y, cell, count, msg, gate], i) => ({
        n: 100 + i, call: null, kind: 'wave', objective: mon === FINAL ? 'kill-boss' : 'kill-all',
        rows: [[mon, x, y, cell, count]], center: [x, y], opens: gate != null ? [gate] : [], bosses: [mon],
        group: 0, spawned: false, done: false, recs: [], source: 'Global', posSource: 'ENGINE-DEFAULT (configurable)', msg,
      }));
      d.sequential = true;
      d.killTarget = 0;
      d.clearDef = { kind: 'boss', monsters: [FINAL] };
    },
    begin(d) { d.alert?.(MEISTER_ROOMS[0][5]); },
    stageDone(d, st) {
      const i = MEISTER_ROOMS.findIndex(r => r[0] === st.rows?.[0]?.[0]);
      const next = MEISTER_ROOMS[i + 1];
      if (next && d.running) d.alert?.(next[5]);
    },
    talk(d, npc, sn) {
      const id = Number(sn?.npc);
      if (id === BEGIN_NPC) {
        if (d.phase === 'countdown' && typeof d._begin === 'function') { d._begin(); return true; }
        if (d.running) { d.alert?.(5031); return true; }
        return false;
      }
      if (id === END_NPC) {
        if (d.running && !enigmaDead(d)) { d.alert?.(5032); return true; }
        return false;      // director default: the Global "Quit." exit
      }
      return false;
    },
  };
}
