// Mini help (ui_minihelpwnd) rules, pure (no DOM): the timing table `script/minihelp.csv` and the movement tutorial
// of `script/string/normal/stringtable_tutorial.txt` (NORMAL cate 3100 codes 1-8, 10000-10003, 50000).
//
// Data facts used here:
//   minihelp.csv  index,cate,code,fadein,view,fadeout,delaytime - every row of the shipped file is 700 / 8000 / 700 / 10000 (ms):
//                 a hint fades in over 700 ms, stays 8 s, fades out over 700 ms and is repeated after the delay while its
//                 condition is not met.
//   cate 3100     1 "Press the W key to move forward." 2 S, 3 A, 4 D, 5 "Hold the right mouse button and move the mouse left to look
//                 left.", 6 (right), 7 "Click the left mouse button to move to the green area", 8 "You've completed the movement
//                 tutorial."; 10000 title "tutorial", 10001 "Welcome to Dekaron. Would you like to view the tutorial?", 10002 "You can't
//                 begin the tutorial again if you cancel. Are you sure you want to end the tutorial?", 50000 completion text.
// ASSUMPTIONS (the data names no trigger values): a key step completes when that key goes down; a look step completes after
// LOOK_PIXELS of mouse travel in the named direction while the right button is held; the "green area" of step 7 has no position in
// the data, so it completes on the first left-click ground move.
export const FADE_DEFAULT = Object.freeze({ fadein: 700, view: 8000, fadeout: 700, delay: 10000 });
export const LOOK_PIXELS = 60;
export const TUTORIAL_CATE = 3100;

/** Parse script/minihelp.csv -> [{index, cate, code, fadein, view, fadeout, delay}]. */
export function parseMiniHelpCsv(text) {
  const rows = [];
  const lines = String(text || '').split(/\r?\n/).map(l => l.trim()).filter(Boolean);
  const head = (lines.shift() || '').split(',').map(h => h.trim().toLowerCase());
  const col = name => head.indexOf(name);
  const c = { index: col('index'), cate: col('cate'), code: col('code'), fadein: col('fadein'), view: col('view'), fadeout: col('fadeout'), delay: col('delaytime') };
  for (const line of lines) {
    const f = line.split(',').map(x => x.trim());
    const n = k => Number(f[c[k]]);
    if (![c.index, c.cate, c.code].every(i => i >= 0) || !Number.isFinite(n('index'))) continue;
    rows.push({ index: n('index'), cate: n('cate'), code: n('code'), fadein: n('fadein'), view: n('view'), fadeout: n('fadeout'), delay: n('delay') });
  }
  return rows;
}

/** The fade timing of the table (every row of the shipped file is identical); falls back to FADE_DEFAULT. */
export function fadeTiming(rows) {
  const first = rows?.[0];
  return first && [first.fadein, first.view, first.fadeout, first.delay].every(Number.isFinite)
    ? { fadein: first.fadein, view: first.view, fadeout: first.fadeout, delay: first.delay } : { ...FADE_DEFAULT };
}

/** Opacity of a hint `t` ms after it started: 0 -> 1 over fadein, 1 for view, 1 -> 0 over fadeout; `done` once the cycle is over. */
export function hintPhase(t, timing = FADE_DEFAULT) {
  const { fadein, view, fadeout } = timing;
  if (t < 0) return { alpha: 0, done: false };
  if (t < fadein) return { alpha: fadein ? t / fadein : 1, done: false };
  if (t < fadein + view) return { alpha: 1, done: false };
  if (t < fadein + view + fadeout) return { alpha: fadeout ? 1 - (t - fadein - view) / fadeout : 0, done: false };
  return { alpha: 0, done: true };
}

/** The client writes colours as <color=0xRRGGBB> (or 0xAARRGGBB): normalise to <color=RRGGBB> for the UI markup runs. */
export function normaliseTutorialMarkup(text) {
  return String(text ?? '').replace(/<color=0x(?:[0-9a-f]{2})?([0-9a-f]{6})>/gi, '<color=$1>');
}

/** Movement tutorial steps (string codes of cate 3100). */
export const MOVEMENT_STEPS = Object.freeze([
  { code: 1, test: 'key', key: 'KeyW' },
  { code: 2, test: 'key', key: 'KeyS' },
  { code: 3, test: 'key', key: 'KeyA' },
  { code: 4, test: 'key', key: 'KeyD' },
  { code: 5, test: 'look', dir: -1 },
  { code: 6, test: 'look', dir: 1 },
  { code: 7, test: 'clickmove' },
  { code: 8, test: 'end' },
]);

/**
 * The movement tutorial state machine. feed() takes the input of one frame:
 *   { keys: Set|array of KeyboardEvent.code held, rightHeld: boolean, dx: mouse movement this frame, clickMove: boolean }
 * and returns the step code now showing (null when finished). A step that completes advances at once.
 */
export class MovementTutorial {
  constructor() { this.index = 0; this.look = 0; this.finished = false; }
  get step() { return this.finished ? null : MOVEMENT_STEPS[this.index]; }
  get code() { return this.step?.code ?? null; }
  /** Advance to the next step (also used by the end step once its text has been shown). */
  advance() {
    this.look = 0;
    if (this.index >= MOVEMENT_STEPS.length - 1) { this.finished = true; return null; }
    this.index++;
    return this.code;
  }
  feed({ keys = [], rightHeld = false, dx = 0, clickMove = false } = {}) {
    const step = this.step;
    if (!step) return null;
    const held = keys instanceof Set ? keys : new Set(keys);
    if (step.test === 'key' && held.has(step.key)) return this.advance();
    if (step.test === 'look') {
      if (rightHeld && Math.sign(dx) === step.dir) this.look += Math.abs(dx);
      if (this.look >= LOOK_PIXELS) return this.advance();
    }
    if (step.test === 'clickmove' && clickMove) return this.advance();
    return this.code;
  }
}
