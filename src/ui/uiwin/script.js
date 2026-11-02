// Parser for the original window scripts script/ui/**/*.txt (docs/formats/ui.md §2, docs/UIWIN.md).
// Pure (no DOM): runs in Node for tests and in the browser.
//
// Three formats live under script/ui:
//   * 'tags'   the game UI (game2/**, com/ui_initscene, maptool/ui_notice*, environmentwindow/ui_envwnd_*):
//              <window> / <panel> / <button> ... blocks with one "key value..." per line.
//   * 'legacy' the old tool UI (maptool, effecttool, com/ui_modemenuwindow, environmentmainwnd):
//              window_* lines + "create_control <kind> <id>" { control_* lines, nested create_control }.
//   * 'table'  sprite tables (com/imagetable.txt, com/preloading.txt): group,index,texture,x,y,w,h,L,T,R,B,desc.
//
// Robustness rules (the shipped files contain these quirks; see docs/UIWIN.md "Parser quirks"):
//   * a close tag pops back to the nearest open element of the same name; a close tag whose name is not open
//     is compared with the element on top of the stack (typos: </widow>, </pannel>, </buton>) and pops it when
//     the names are within edit distance 1; otherwise it is ignored (stray
//     </image> after a button's images). Unclosed elements are closed at end of file.
//   * several tags on one line (</button>  </panel>), garbage after a tag (<image>s, <image>1), '<title?' and
//     '</window' without '>' are accepted.
//   * placeholders such as <NUM>, <GROUP>, <BG_TOP> inside values are template variables filled by
//     "loadchildname <VAR> value" when the file is pulled in with "loadchild" (they are never tags).
//   * keys are case-insensitive (fontIndex == fontindex). Values keep their case. A key given twice keeps the last.
//     Misspelled keys (enbale, psotion, lienheight...) are kept verbatim and therefore ignored, exactly as a
//     string-compare parser would.

/** Split a value string into tokens; "double quoted" strings stay one token (quotes removed). */
export function splitTokens(s) {
  const out = [];
  const re = /"([^"]*)"?|(\S+)/g;
  let m;
  while ((m = re.exec(s))) out.push(m[1] != null ? m[1] : m[2]);
  return out;
}

/** Levenshtein distance (small strings). */
function editDistance(a, b) {
  const d = Array.from({ length: a.length + 1 }, (_, i) => [i]);
  for (let j = 1; j <= b.length; j++) d[0][j] = j;
  for (let i = 1; i <= a.length; i++) {
    for (let j = 1; j <= b.length; j++) {
      d[i][j] = Math.min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (a[i - 1] === b[j - 1] ? 0 : 1));
    }
  }
  return d[a.length][b.length];
}

/** Which of the three formats a script/ui text uses. */
export function detectFormat(text) {
  const t = String(text);
  if (/^\s*create_control\s/m.test(t) || /^\s*window_(size|position|layer)\s/m.test(t)) return 'legacy';
  if (/^\s*<\s*\/?\s*[A-Za-z_]/m.test(t)) return 'tags';
  if (/^[^,\r\n]+,-?\d+,[^,\r\n]+\.(dds|tga|bmp|png|jpg)\s*,/im.test(t)) return 'table';
  return 'tags';
}

function newNode(tag, line) {
  return { tag, props: Object.create(null), order: [], children: [], line };
}

/**
 * Parse a 'tags' window script.
 * @param {string} text
 * @param {{file?: string, vars?: Object<string,string>}} opts  vars: template variables ('<NUM>' -> '0')
 * @returns {{ roots: Node[], warnings: string[] }}
 *   Node = { tag, props: {key: string[]}, order: [[key, tokens]], children: Node[], line }
 */
export function parseTagScript(text, { file = '', vars = null } = {}) {
  let src = String(text);
  if (vars) for (const [k, v] of Object.entries(vars)) src = src.split(k).join(String(v));
  const root = newNode('#root', 0);
  const stack = [root];
  const warnings = [];
  const lines = src.split(/\r\n|\n|\r/);
  for (let i = 0; i < lines.length; i++) {
    let s = lines[i].trim();
    if (!s || s.startsWith('//') || s.startsWith(';') || s.startsWith('#')) continue;
    let sawTag = false;
    while (s.startsWith('<')) {
      const m = /^<\s*(\/?)\s*([A-Za-z_][\w]*)\s*(>|\?>?|$)/.exec(s);
      if (!m) break;
      sawTag = true;
      const close = !!m[1];
      const name = m[2].toLowerCase();
      s = s.slice(m[0].length).trim();
      if (!close) {
        const n = newNode(name, i + 1);
        stack[stack.length - 1].children.push(n);
        stack.push(n);
        continue;
      }
      // close: pop to the nearest open element with that name
      let at = -1;
      for (let k = stack.length - 1; k > 0; k--) if (stack[k].tag === name) { at = k; break; }
      if (at > 0) {
        if (at !== stack.length - 1) warnings.push(`${file}:${i + 1} </${name}> also closes ${stack.slice(at + 1).map(n => n.tag).join('>')}`);
        stack.length = at;
      } else if (stack.length > 1) {
        const top = stack[stack.length - 1].tag;
        if (editDistance(top, name) <= 1) {
          warnings.push(`${file}:${i + 1} </${name}> closes <${top}> (typo)`);
          stack.pop();
        } else warnings.push(`${file}:${i + 1} stray </${name}> ignored (open: <${top}>)`);
      } else warnings.push(`${file}:${i + 1} stray </${name}> at top level`);
    }
    if (!s) continue;
    if (sawTag) { warnings.push(`${file}:${i + 1} text after tag ignored: ${s}`); continue; }
    const km = /^(\S+)\s*(.*)$/.exec(s);
    if (!km) continue;
    const key = km[1].toLowerCase();
    const toks = splitTokens(km[2]);
    const cur = stack[stack.length - 1];
    cur.props[key] = toks;
    cur.order.push([key, toks]);
  }
  if (stack.length > 1) warnings.push(`${file}: unclosed ${stack.slice(1).map(n => n.tag).join('>')} (closed at end of file)`);
  return { roots: root.children, warnings };
}

/**
 * Parse a 'legacy' tool-UI script (create_control blocks).
 * @returns {{ window: {key: string[]}, roots: Node[], warnings: string[] }}  Node.tag = control kind, Node.id = id
 */
export function parseLegacyScript(text, { file = '' } = {}) {
  const win = newNode('window', 0);
  const stack = [win];
  const warnings = [];
  let pending = null;
  const lines = String(text).split(/\r\n|\n|\r/);
  for (let i = 0; i < lines.length; i++) {
    const s = lines[i].trim();
    if (!s || s.startsWith('//') || s.startsWith(';')) continue;
    if (s === '{') {
      if (pending) { stack[stack.length - 1].children.push(pending); stack.push(pending); pending = null; }
      else warnings.push(`${file}:${i + 1} '{' without create_control`);
      continue;
    }
    if (s === '}') { if (stack.length > 1) stack.pop(); else warnings.push(`${file}:${i + 1} stray '}'`); continue; }
    const km = /^(\S+)\s*(.*)$/.exec(s);
    if (!km) continue;
    const key = km[1].toLowerCase();
    const toks = splitTokens(km[2]);
    if (key === 'create_control') {
      if (pending) stack[stack.length - 1].children.push(pending);   // block-less control
      pending = newNode(String(toks[0] || 'panel').toLowerCase(), i + 1);
      pending.props.id = [toks[1] || ''];
      pending.order.push(['id', [toks[1] || '']]);
      continue;
    }
    const cur = stack[stack.length - 1];
    cur.props[key] = toks;
    cur.order.push([key, toks]);
  }
  if (pending) stack[stack.length - 1].children.push(pending);
  return { window: win, roots: win.children, warnings };
}

/**
 * Parse sprite-table lines (imagetable.txt / preloading.txt).
 * @returns {Array<{group,index,tex,x,y,w,h,m:[L,T,R,B],desc}>}
 */
export function parseSpriteTable(text) {
  const out = [];
  for (const line of String(text).split(/\r\n|\n|\r/)) {
    const c = line.split(',');
    if (c.length < 7) continue;
    const group = c[0].trim(); const idx = c[1].trim();
    if (!group || !/^-?\d+$/.test(idx) || !c[2] || !c[2].trim()) continue;
    const nums = c.slice(3, 7).map(Number);
    if (nums.some(v => !Number.isFinite(v))) continue;
    const mm = c.slice(7, 11).map(v => (String(v).trim() === '' ? NaN : Number(v)));
    const m = mm.length === 4 && mm.every(Number.isFinite) ? mm : [0, 0, 0, 0];
    out.push({ group, index: Number(idx), tex: c[2].trim(), x: nums[0], y: nums[1], w: nums[2], h: nums[3], m, desc: (mm.length === 4 && mm.every(Number.isFinite) ? c.slice(11) : c.slice(7)).join(',').trim() });
  }
  return out;
}

/** Collect every template variable used in a text ('<NUM>', '<GROUP>', ...) that is not a tag line. */
export function templateVars(text) {
  const out = new Set();
  for (const line of String(text).split(/\r\n|\n|\r/)) {
    const s = line.trim();
    if (!s || s.startsWith('<')) continue;
    for (const m of s.matchAll(/<[A-Za-z_]\w*>/g)) out.add(m[0]);
  }
  return [...out];
}
