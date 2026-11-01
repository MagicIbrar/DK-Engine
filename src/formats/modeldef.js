// Dekaron model definitions: which mesh / skeleton / animations make up a model, and how long each animation plays.
//
// Pure parsers (no three.js, no Node APIs). See docs/formats/modeldef.md.
//
//  1. object/static/**/*.txt  - static map-object descriptor (parseModelDef)
//        mesh        Object\animal\a_pig_01.mesh
//        animation   Object\animal\a_pig_01.anim 5          <- seconds for one pass of the normalised (0..1) anim
//        skeleton    Object\animal\a_pig_01.skel
//        shadow 1 | meshtype building | twoside 1 | transparent 1 | maxdiffuse 1 | uvanim 0 -1 3 | nofog 1
//        //animation ... (commented-out lines are kept in .commented)
//  2. share/action/<kind>/*.csv - "action table" (parseActionTable): per creature, the animation of every game action
//        Creature,MONSTER / Index,110 / Skeleton,Monster\morpha.skel / (blank)
//        Style,Action,Index,Animation,Start_Inter,End_Inter,TimeLength,Swing,Strike,Timing,Split,Timing2,Freeze
//        [,Effect,CancelTime[,DefaultAction|Default[,Intersect[,Through]]]]
//  3. share/action/action/<kind>/*.dat - the compiled binary form of the same tables (parseActionDat); 17,909 files,
//     i.e. more creatures than the 15,629 shipped .csv (e.g. 9475.applemon01.act.dat has no .csv).
//
// Game paths are relative to the per-type data root and case-insensitive:
//   mesh -> mesh/<p>, skeleton -> skel/<p>, animation -> anim/<p>; lower-case + forward slashes = /data/<key>.

import { parseCSV, decodeText, BinReader, toArrayBuffer } from './binreader.js';

const toText = (src) => (typeof src === 'string' ? src : decodeText(src instanceof ArrayBuffer ? new Uint8Array(src) : src, true));

/** Normalise a game path to a data key under `root` ("NPC\\a.mesh", "mesh" -> "mesh/npc/a.mesh"). */
export function gameKey(root, p) {
  const n = String(p ?? '').trim().replace(/\\/g, '/').replace(/^(\.\/)+/, '').replace(/^\/+/, '').replace(/\/{2,}/g, '/').toLowerCase();
  if (!n) return null;
  const r = root.toLowerCase().replace(/\/$/, '');
  return n.startsWith(r + '/') ? n : `${r}/${n}`;
}

const num = (s) => { const t = String(s ?? '').trim(); const v = Number(t); return t !== '' && Number.isFinite(v) ? v : null; };

/** basename -> data keys index for resolveDataKey (feed it the manifest / directory listing of anim/, skel/, mesh/). */
export function buildBasenameIndex(keys) {
  const m = new Map();
  for (const k of keys) { const b = k.slice(k.lastIndexOf('/') + 1); (m.get(b) || m.set(b, []).get(b)).push(k); }
  return m;
}

/**
 * Remake-side fallback for table references to files that are not where the table says (the client ships ~560
 * such action-table rows; the original client simply fails to load them). Order:
 *   1. the key itself;
 *   2. blanks removed around path segments / before the extension ("..._rid_run .anim" -> "..._rid_run.anim");
 *   3. files with the same basename under the same root folder (anim/, skel/, mesh/): the only one, or the one whose
 *      directory shares the most trailing/leading segments with the key ("skel/npc_human_size.skel" ->
 *      "skel/npc/npc_human_size.skel", "anim/monster/mitera_ghostt/x.anim" -> "anim/monster/mitera_ghost/x.anim").
 * Recovers 42 of 559 missing anim keys and 7 of 34 missing skel keys (e.g. npc_human_size.skel, 44 table rows).
 * @param {string} key                   data key
 * @param {(k:string)=>boolean} exists   existence predicate (e.g. manifestSet.has.bind(manifestSet))
 * @param {Map<string,string[]>} [byBase] buildBasenameIndex(allKeys); without it only steps 1-2 run
 * @returns {string|null}
 */
export function resolveDataKey(key, exists, byBase = null) {
  if (!key) return null;
  if (exists(key)) return key;
  const squeezed = key.split('/').map(s => s.trim()).join('/').replace(/\s+(\.[a-z0-9]+)$/, '$1');
  if (squeezed !== key && exists(squeezed)) return squeezed;
  if (!byBase) return null;
  const segs = squeezed.split('/'), base = segs[segs.length - 1], root = segs[0];
  const cands = (byBase.get(base) || []).filter(k => k.startsWith(root + '/') && exists(k));
  if (cands.length <= 1) return cands[0] || null;
  const score = (k) => {
    const s = k.split('/'); let a = 0, b = 0;
    while (a < s.length - 1 && a < segs.length - 1 && s[a] === segs[a]) a++;
    while (b < s.length - 1 && b < segs.length - 1 && s[s.length - 2 - b] === segs[segs.length - 2 - b]) b++;
    return a + b;
  };
  return cands.sort((x, y) => score(y) - score(x) || x.length - y.length || (x < y ? -1 : 1))[0];
}

// ------------------------------------------------------------------------------------ object/static/*.txt

/**
 * Parse an object/static descriptor.
 * @param {string|ArrayBuffer|Uint8Array} src
 * @returns {{ mesh:string, animation:string, animTime:number|null, skeleton:string,
 *   meshKey:string|null, animKey:string|null, skelKey:string|null,
 *   shadow:number|null, meshtype:string, twoside:number|null, transparent:number|null, maxdiffuse:number|null,
 *   uvanim:number[]|null, nofog:number|null, extra:Record<string,string>, commented:string[], lines:string[][] }}
 *   animTime = seconds for one pass over the normalised [0,1] animation (loop period).
 *   uvanim   = 3 numbers as written (texture scroll; see docs/formats/modeldef.md).
 */
export function parseModelDef(src) {
  const text = toText(src);
  const o = {
    mesh: '', animation: '', animTime: null, skeleton: '', meshKey: null, animKey: null, skelKey: null,
    shadow: null, meshtype: '', twoside: null, transparent: null, maxdiffuse: null, uvanim: null, nofog: null,
    extra: {}, commented: [], lines: [],
  };
  for (const rawLine of text.split(/\r?\n/)) {
    const line = rawLine.trim();
    if (!line) continue;
    if (line.startsWith('//') || line.startsWith(';') || line.startsWith('#')) { o.commented.push(line); continue; }
    const parts = line.split(/\s+/);
    o.lines.push(parts);
    const key = parts[0].toLowerCase();
    const rest = parts.slice(1);
    switch (key) {
      case 'mesh': o.mesh = rest.join(' '); break;
      case 'skeleton': case 'skel': o.skeleton = rest.join(' '); break;
      case 'animation': case 'anim': {
        const last = rest[rest.length - 1];
        if (rest.length > 1 && num(last) !== null) { o.animation = rest.slice(0, -1).join(' '); o.animTime = num(last); }
        else o.animation = rest.join(' ');
        break;
      }
      case 'shadow': o.shadow = num(rest[0]); break;
      case 'meshtype': o.meshtype = rest.join(' '); break;
      case 'twoside': o.twoside = num(rest[0]); break;
      case 'transparent': case 'trensparent': o.transparent = num(rest[0]); break; // "trensparent" typo exists in data
      case 'maxdiffuse': o.maxdiffuse = num(rest[0]); break;
      case 'uvanim': o.uvanim = rest.map(Number); break;
      case 'nofog': o.nofog = num(rest[0]); break;
      default: o.extra[key] = rest.join(' ');
    }
  }
  o.meshKey = o.mesh ? gameKey('mesh', o.mesh) : null;
  o.animKey = o.animation ? gameKey('anim', o.animation) : null;
  o.skelKey = o.skeleton ? gameKey('skel', o.skeleton) : null;
  return o;
}

// ---------------------------------------------------------------------------------------- action tables

/** Creature type codes of the compiled .dat header (value -> "Creature" string of the .csv). */
export const CREATURE_TYPES = Object.freeze({
  0: 'PC', 1: 'MONSTER', 2: 'SERVANT', 3: 'GUARD', 4: 'NPC', 5: 'BRICK', 6: 'SENTRY', 7: 'VEHICLE', 8: 'RIDER',
  9: 'ITEM', 17: 'PET', 19: 'WINGRIDER', 22: 'TRIGGER',
});

/**
 * Action ids of the compiled .dat records (value -> Action name of the .csv). Derived by joining all 15,629
 * csv/dat pairs on (style, index, animation). Ids not listed never appear in a joinable row.
 */
export const ACTION_IDS = Object.freeze({
  0: 'ENTER', 1: 'STAND', 2: 'MOVE', 6: 'ATTACK', 7: 'DEFEAT', 8: 'DEAD', 9: 'LEAVE', 10: 'SKILL', 11: 'REVIVE',
  12: 'BLOCKING', 13: 'BLOCKED', 14: 'GUARDING', 15: 'MOTION', 17: 'OPENMARKET', 18: 'CLOSEMARKET',
  21: 'FISHFIGHTING', 22: 'OPENFISHING', 23: 'CLOSEFISHING', 24: 'OPENBRICK', 25: 'CLOSEBRICK',
  26: 'SM_STAND', 27: 'SM_DEAD', 28: 'SM_MOVE', 29: 'SM_REVIVE', 30: 'ENDSIEGE', 38: 'KNOCKDOWN',
  39: 'AWK_STAND', 40: 'AWK_MOVE', 41: 'STUN', 43: 'SLEEP', 44: 'RUSH',
  46: 'EMOTIONSTART', 47: 'EMOTIONKEEP', 48: 'EMOTIONEND', // 46/48 inferred (sitdown/situp anims), 47 joined
  49: 'TRIGGERCHANGE',
  53: 'SURRENDER', // inferred from the "*_com_surrender" animation (no csv row names it)
  // Seen only in .dat rows without a csv counterpart, returned as "ACTION_<id>":
  //   51 (23 rows, monster "*_appear" anims), 52 (23 rows, "*_disappear"), 54 (6 rows, brick door opening/fail anims)
});
const ACTION_NAME_TO_ID = Object.fromEntries(Object.entries(ACTION_IDS).map(([k, v]) => [v, Number(k)]));

const ACTION_COLS = {
  style: 'style', action: 'action', index: 'index', animation: 'animation', start_inter: 'startInter',
  end_inter: 'endInter', timelength: 'timeLength', swing: 'swing', strike: 'strike', timing: 'timing', split: 'split',
  timing2: 'timing2', freeze: 'freeze', effect: 'effect', canceltime: 'cancelTime', defaultaction: 'defaultAction',
  default: 'defaultAction', intersect: 'intersect', through: 'through',
};

function finishTable(out) {
  for (const row of out.actions) (out.byAction[row.action] ||= []).push(row);
  return out;
}

/**
 * Parse an action table (.csv).
 * @returns {{ creature:string, index:number|null, skeleton:string, skelKey:string|null, columns:string[],
 *   actions: Array<{ style:number, action:string, actionId:number|null, index:number, animation:string, animKey:string|null,
 *     startInter:number, endInter:number, timeLength:number, swing:number, strike:number, timing:number,
 *     split:number, timing2:number, freeze:number, effect?:number, cancelTime?:number, defaultAction?:number,
 *     intersect?:number, through?:number, extra?:Record<string,string> }>,
 *   byAction: Record<string, object[]> }}   byAction[ACTION] = rows of that action (all styles), in file order
 */
export function parseActionTable(src) {
  const rows = parseCSV(toText(src));
  const out = { creature: '', index: null, skeleton: '', skelKey: null, columns: [], actions: [], byAction: {} };
  let cols = null;
  for (const r of rows) {
    const c0 = String(r[0] ?? '').trim();
    if (!cols) {
      const k = c0.toLowerCase();
      if (k === 'creature') out.creature = String(r[1] ?? '').trim();
      else if (k === 'index') out.index = num(r[1]);
      else if (k === 'skeleton') { out.skeleton = String(r[1] ?? '').trim(); out.skelKey = out.skeleton ? gameKey('skel', out.skeleton) : null; }
      else if (k === 'style') {
        cols = r.map(x => String(x ?? '').trim());
        while (cols.length && cols[cols.length - 1] === '') cols.pop();
        if (cols[3] === '') cols[3] = 'Animation'; // 216 tables have an empty 4th header cell
        out.columns = cols;
      }
      continue;
    }
    if (!c0 || r.every(x => String(x ?? '').trim() === '')) continue;
    const row = {};
    cols.forEach((name, i) => {
      const key = ACTION_COLS[name.toLowerCase()];
      const v = String(r[i] ?? '').trim();
      if (key === 'action' || key === 'animation') row[key] = v;
      else if (key) row[key] = num(v) ?? 0;
      else if (name) (row.extra ||= {})[name] = v;
    });
    row.actionId = ACTION_NAME_TO_ID[row.action] ?? null;
    row.animKey = row.animation ? gameKey('anim', row.animation) : null;
    out.actions.push(row);
  }
  return finishTable(out);
}

export const ACTION_DAT_HEADER = 264; // u32 creatureType, u32 index, char[256] skeleton
export const ACTION_DAT_RECORD = 303; // packed (pack(1)) record, see parseActionDat

/**
 * Parse a compiled action table (share/action/action/<kind>/*.dat). Little-endian, packed:
 *   u32 creatureType (CREATURE_TYPES), u32 index, char[256] skeleton (EUC-KR, NUL padded)
 *   records (303 bytes each) to EOF:
 *     +0 u8 style  +1 u32 actionId (ACTION_IDS)  +5 u32 index  +9 char[256] animation
 *     +265 f32 startInter  +269 f32 endInter  +273 f32 timeLength  +277 u8 swing  +278 u8 strike
 *     +279 f32 timing  +283 u8 split  +284 f32 timing2  +288 f32 freeze  +292 u32 effect  +296 u32 cancelTime
 *     +300 u8 defaultAction  +301 u8 intersect  +302 u8 through
 * Record order is the compiler's, not necessarily the .csv row order.
 * @returns same shape as parseActionTable (creature from CREATURE_TYPES), plus creatureType and trailingBytes.
 */
export function parseActionDat(buf) {
  const r = new BinReader(toArrayBuffer(buf));
  const creatureType = r.u32(), index = r.u32();
  const skeleton = r.fixedStr(256, true);
  const out = {
    creature: CREATURE_TYPES[creatureType] ?? String(creatureType), creatureType, index, skeleton,
    skelKey: skeleton ? gameKey('skel', skeleton) : null, columns: [], actions: [], byAction: {}, trailingBytes: 0,
  };
  while (r.remaining >= ACTION_DAT_RECORD) {
    const style = r.u8r(), actionId = r.u32(), idx = r.u32();
    const animation = r.fixedStr(256, true);
    const startInter = r.f32(), endInter = r.f32(), timeLength = r.f32();
    const swing = r.u8r(), strike = r.u8r(), timing = r.f32(), split = r.u8r(), timing2 = r.f32();
    const freeze = r.f32(), effect = r.u32(), cancelTime = r.u32();
    const defaultAction = r.u8r(), intersect = r.u8r(), through = r.u8r();
    out.actions.push({
      style, action: ACTION_IDS[actionId] ?? `ACTION_${actionId}`, actionId, index: idx, animation,
      animKey: animation ? gameKey('anim', animation) : null,
      startInter, endInter, timeLength, swing, strike, timing, split, timing2, freeze, effect, cancelTime,
      defaultAction, intersect, through,
    });
  }
  out.trailingBytes = r.remaining;
  return finishTable(out);
}

/**
 * Playback length in SECONDS of an action row (use this instead of row.timeLength).
 * TimeLength is seconds in 99.99 % of rows (frameCount / TimeLength = 30 fps for most clips), but 72 .dat rows
 * (brick OPENBRICK / CLOSEBRICK / DEAD, a few PC SKILL rows) store MILLISECONDS: 1000..4000, e.g.
 * object/building_extra/invisible_brick_opening.anim has 120 frames and TimeLength 4000 (= 4 s at 30 fps).
 * Values >= 100 are therefore read as ms. Returns null for 0 / missing (7,577 rows, mostly rows without an
 * animation): fall back to parseAnim().estDurationSec. (hwa.act.12 SKILL rows hold frames/0.9, 20..100 - skills are
 * timed by the combo TimeTick instead, see characters.md.)
 * @param {{timeLength:number}} row
 * @returns {number|null}
 */
export function actionSeconds(row) {
  const t = Number(row?.timeLength);
  if (!Number.isFinite(t) || !(t > 0)) return null;
  return t >= 100 ? t / 1000 : t;
}

/**
 * Pick the animation row for a game action: exact (style, index) first, then style 0, then any row of the action.
 * @returns {object|null} action row ({ animKey, timeLength, timing, ... })
 */
export function findAction(table, action, index = 0, style = 0) {
  const rows = table.byAction[action] || [];
  return rows.find(r => r.style === style && r.index === index && r.animKey) ||
    rows.find(r => r.style === 0 && r.index === index && r.animKey) ||
    rows.find(r => r.style === style && r.animKey) || rows.find(r => r.animKey) || null;
}
