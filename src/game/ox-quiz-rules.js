// OX Quiz (Undo Stadion map 22, reached from Theme Park map 654): portable rules derived from the original client
// files only. Everything a host controller needs is read from these sources; anything the data does not define is
// listed in OX_QUIZ_ENGINE_CHOICES or OX_QUIZ_DEPENDENCIES and is never presented as a native rule.
//
// AUTHENTICATED NATIVE SOURCES (data/unpacked/data, byte-identical to the Global packs):
//   share/event/oxlist.csv            Index,Question,Answer(O/X),Solution  (89 rows; commas inside [brackets])
//   share/event/oxevent.csv           MAX_USER 200
//   script/string/normal/stringtable_event.txt  2300:28 "Question <COUNT>", 2300:29 "<COUNT> Solution",
//                                     2300:30 "Answer is <ANSWER>", 2300:31 "Survivors : <COUNT> / <MAX_COUNT>",
//                                     2300:32 "Round : <COUNT> / 15"  (the round limit 15 is read from this string)
//   script/ui/game2/event/ui_oxquizwnd.txt  window oxquiz: lbl_number / lbl_desc / lbl_question
//   share/creature/npc.csv            5830 Start Stone job31 5100 (conv 61755 "OX Quiz Event Stone (Usable by GM characters
//                                     only."), 5831 Escape Stone job31 4900 (conv 61756 "Every dropouts please use
//                                     warpstone and go out this place."), 6185 Hani job97 + job31 9710 (conv 61770:
//                                     "Required Lv: 195+", "Schedule: Sat at 17:00"), 5825 Operation Assistant job31 9559
//   share/dungeon/dungeon_22_ox_quiz.csv  menu 5110 -> 5111..5117; dungeon_654_oxquiz_dk.csv menus 9555 -> 9553/9554 ...
//   script/string/map/stringtable_map_string_01.txt cate 22: 4900 "Return to Ardeca.", 5111 "Create wall.",
//                                     5112 "Remove wall.", 5113/5114 "Eliminate incorrect responders (O)/(X)",
//                                     5115 "Question set (Auto)", 5116 "Not Alloed Enter", 5117 "Export All (Game Over)",
//                                     5200 "@<effectui>2033,1,5000,1", 5201 "[message] In 5 sec, wall appear! step back from
//                                     The Center!", 5202 "@<effectui>2026,1,4000,1"; cate 654: 106 "Maximum capacity reached.
//                                     Entry unavailable.", 107 "Only one character may enter from the same PC.", 9553/9554
//                                     "Entry Allowed"/"Entry Not Allowed", 9710 "Enter the OX Quiz.", 9712 "[message] The OX
//                                     Quiz event is not currently in progress."
//   share/arrange/location.csv + warp.csv  11784 "OX admission" 654(236,263) -> 11785 "OX destination" 22(255,255);
//                                     11786 "OX departure point" 22(255,255) -> 11787 "OX exit destination point" 654(236,263)
//   share/dkmaplist.csv               654 is DK channel map (LocateDK_Index 100, locate/respawn 236,263); 22 has no locate
//   share/map/22_undo_stadion/brick_22_undostadion.csv  UID 101 brick 36100 "Wall of Fire" at 256,256 dir 90,
//                                     IsCreate 0 (32 x 1 cells, all resists 100): the wall that "Create wall" raises
//   share/map/22_undo_stadion/callmonster_22_undostadion.csv  groups 1-6 / 11-15 of monster 8134 (melee 60000-63000)
//   map/arena_ox.mol                  building_extra\ar_flag_O / ar_line_O at (256,265.5) and ar_flag_X / ar_line_X at
//                                     (256,246.5), building\ar_line along z 256: the O half is z > 256, the X half z < 256
//   share/maplist.csv                 22 Undo Stadion levels 1-250 isUseMap 1; 654 Theme Park levels 195-250 isUseMap 1
export const OX_QUIZ = Object.freeze({
  arena: 22, lobby: 654,
  npcs: Object.freeze({ startStone: 5830, escapeStone: 5831, hani: 6185, assistant: 5825 }),
  jobs: Object.freeze({ startStone: [31, 5100], escapeStone: [31, 4900], hani: [31, 9710], assistant: [31, 9559] }),
  locations: Object.freeze({ admission: 11784, destination: 11785, departure: 11786, exit: 11787 }),
  warps: Object.freeze([[11784, 11785], [11786, 11787]]),
  wall: Object.freeze({ uid: 101, brick: 36100 }),
  // GM menu entries (dungeon_22 5110 menu and dungeon_654 9555 menu), cate 22 / cate 654 string codes
  menu: Object.freeze({ wall: 5111, unwall: 5112, eliminateO: 5113, eliminateX: 5114, question: 5115, close: 5116, end: 5117, open: 9553, closeEntry: 9554, escape: 4900 }),
  notice: Object.freeze({ wallCountdown: 5200, wallWarning: 5201, missionClear: 5202 }),
  refusal: Object.freeze({ full: 106, samePc: 107, notRunning: 9712 }),
  window: Object.freeze({ file: 'script/string/normal/stringtable_event.txt', cate: 2300, question: 28, solution: 29, answer: 30, survivors: 31, round: 32 }),
  script: 'game2/event/ui_oxquizwnd.txt',
});

// DELIBERATE ENGINE CHOICES (not native rules; each is a bounded, fail-closed substitute for a missing server script).
export const OX_QUIZ_ENGINE_CHOICES = Object.freeze([
  'The Operation Assistant 5825 has no field placement (0,0), so Entry Allowed / Entry Not Allowed (9553/9554) are accepted from an authorized GM on map 22 or 654 without NPC proximity.',
  'Entry Allowed is the admission signal: Hani refuses with654:9712 whenever it is closed. Manual GM events remain manual; an unoccupied scheduled Saturday17:00 UTC+1 window runs automatically.',
  'Eliminate (O)/(X) are read as "the correct answer is O/X; the other half is out". The host refuses a button that disagrees with the current oxlist answer, and refuses elimination without a host-set question, so neither reading can eliminate correct responders.',
  'Wrong-side elimination after the wall rises summons the authored 8134 rows on that half (O78/X75) with unchanged native combat values. Staff and correct responders are never eligible targets. ENGINE-CHOSEN lifetime: Remove Wall or session end despawns them. Dropouts may use the Escape Stone as conv61756 instructs.',
  'Leaving the arena (Escape Stone, disconnect, any travel) ends that character\'s participation as a dropout; re-entry is allowed only as a dropout.',
  'Entry keeps the Theme Park DK channel for map 22, so the existing DK reconnect rule (a reconnect never resumes a DK session) applies; the quiz state is host-memory only.',
  'Survivors MAX_COUNT is the number of distinct characters admitted in the session (GM characters are staff, not participants).',
  'Hani admits a character only on the single Theme Park DK channel of dkmaplist 654; the arena runs on that same channel. A player in the arena without admission (no session, another channel, not registered) is moved out by the tick.',
  'Export All moves every non-GM player in the arena through warp 11786 -> 11787; the GM stays to close the event.',
  'Automatic scheduling follows native Hani Saturday17:00 with the shared fixed UTC+1 clock. ENGINE-CHOSEN missing pacing:5min admission,30sec answer,native5sec wall,10sec solution,15 rounds,60sec return. An active manual event is never replaced.',
  'ENGINE-CHOSEN reward binding: latest native OX Quiz Gift Box1192809 x1 after all15 correct rounds, still present, saved once with a durable session receipt. Failed storage or full bags hold settlement for retry. Native5202 clear effect plays after durability.',
  'Native Operation Assistant choices9601–9609 bind to status7484–7492 for1800seconds, recovered from the client executable. Only this OX buff family is replaced; unrelated potion buffs survive. The tenth untranslated choice remains refused.',
  'A player pushed onto the raised Wall of Fire footprint is moved to the nearest walkable cell.',
]);

// DEPENDENCIES (absent from the supplied client data; nothing is invented for them).
// Round-3 census (tools/audit-r3-events-native-3.1.0.mjs) found no further source.
export const OX_QUIZ_DEPENDENCIES = Object.freeze([
  '654:107 "Only one character may enter from the same PC." needs a trusted machine identity the host does not have; only the inherent one-character-per-account rule applies.',
  'The Escape Stone text 4900 says "Return to Ardeca." while warp 11786 leads to the Theme Park exit point 11787; the explicit warp is used and the text is preserved unchanged.',
]);

const num = (v, d = 0) => { const n = Number(v); return Number.isFinite(n) ? n : d; };
const stripBrackets = s => String(s ?? '').trim().replace(/^\[/, '').replace(/\]$/, '').trim();

/** 15 from 2300:32 "Round : <COUNT> / 15"; null when the original string is missing or has another shape. */
export function oxRoundLimit(roundText) {
  const m = /Round\s*:\s*<COUNT>\s*\/\s*(\d+)/.exec(String(roundText || ''));
  const n = m ? Number(m[1]) : NaN;
  return Number.isSafeInteger(n) && n > 0 ? n : null;
}

/** Validated oxlist rows [{index, question, answer:'O'|'X', solution}] (life.json events.ox.questions shape or raw). */
export function oxQuestions(rows) {
  const out = [];
  for (const r of rows || []) {
    const index = num(r.index ?? r.Index, NaN), answer = String(r.a ?? r.answer ?? r.Answer ?? '').trim().toUpperCase();
    const question = stripBrackets(r.q ?? r.question ?? r.Question), solution = stripBrackets(r.why ?? r.solution ?? r.Solution);
    if (!Number.isSafeInteger(index) || !['O', 'X'].includes(answer) || !question) return null;   // a malformed table fails closed
    out.push({ index, question, answer, solution });
  }
  return out.length ? out : null;
}

/** Original O / X answer markers of the arena MOL (ar_flag_O / ar_line_O, ar_flag_X / ar_line_X) and the dividing ar_line row. */
export function oxSides(molObjects) {
  const objs = molObjects || [];
  const avg = re => { const hit = objs.filter(o => re.test(String(o.name || ''))); return hit.length ? { x: hit.reduce((s, o) => s + o.x, 0) / hit.length, z: hit.reduce((s, o) => s + o.z, 0) / hit.length, count: hit.length } : null; };
  const O = avg(/\\ar_(flag|line)_O$/i), X = avg(/\\ar_(flag|line)_X$/i);
  const line = objs.filter(o => /\\ar_line$/i.test(String(o.name || '')));
  if (!O || !X || !line.length) return null;
  return { O: { x: O.x, z: O.z }, X: { x: X.x, z: X.z }, line: { z: line.reduce((s, o) => s + o.z, 0) / line.length, x0: Math.min(...line.map(o => o.x)), x1: Math.max(...line.map(o => o.x)) } };
}

/** 'O' | 'X' for a position: the nearer original marker. */
export function oxSideAt(sides, x, z) {
  const dO = Math.hypot(x - sides.O.x, z - sides.O.z), dX = Math.hypot(x - sides.X.x, z - sides.X.z);
  return dO < dX ? 'O' : dX < dO ? 'X' : null;
}

/** Call groups of the arena callmonster table on each half (each group's rows by majority side). */
export function oxCallHalves(calls, sides) {
  const out = { O: [], X: [] };
  for (const [group, rows] of Object.entries(calls || {})) {
    let o = 0, x = 0;
    for (const r of rows) { const s = oxSideAt(sides, num(r[1]) + .5, num(r[2]) + .5); if (s === 'O') o++; else if (s === 'X') x++; }
    if (o && !x) out.O.push(Number(group)); else if (x && !o) out.X.push(Number(group)); else return null;   // a mixed group has no source side
  }
  out.O.sort((a, b) => a - b); out.X.sort((a, b) => a - b);
  return out;
}

/** Admission refusal code of Hani's 9710 (cate 654), or null when entry is allowed. */
export function oxEntryRefusal({ open, count, max }) {
  if (!open) return OX_QUIZ.refusal.notRunning;
  if (!(count < max)) return OX_QUIZ.refusal.full;
  return null;
}

/** Fill <NAME> tokens of an original string. */
export function oxFormat(text, args = {}) {
  return String(text ?? '').replace(/<([A-Z_]+)>/g, (all, k) => Object.hasOwn(args, k) ? String(args[k]) : all);
}

/**
 * The three labels of the original oxquiz window for a snapshot, as string references the client resolves
 * ({cate, code, args} = stringtable_event.txt) or plain question/solution text from oxlist.csv.
 */
export function oxWindowView(snap) {
  const W = OX_QUIZ.window;
  if (!snap || !snap.round || !['question', 'solution'].includes(snap.phase)) return null;
  if (snap.phase === 'question') return {
    lbl_number: { cate: W.cate, code: W.question, args: { COUNT: snap.round } },
    lbl_desc: { cate: W.cate, code: W.round, args: { COUNT: snap.round } },
    lbl_question: { text: snap.question?.text || '' },
  };
  return {
    lbl_number: { cate: W.cate, code: W.solution, args: { COUNT: snap.round } },
    lbl_desc: { cate: W.cate, code: W.answer, args: { ANSWER: snap.solution?.answer || '' } },
    lbl_question: { text: snap.solution?.text || '' },
  };
}

/** Next question: an unused oxlist row (random), or null when every row was used. */
export function oxPickQuestion(questions, used, random = Math.random) {
  const pool = questions.filter(q => !used.has(q.index));
  if (!pool.length) return null;
  return pool[Math.min(pool.length - 1, Math.floor(random() * pool.length))];
}
