// Shared helpers of the hud-options system (HUD shell, options, key map, chat, help).
import { strings } from '../../ui/uiwin/strings.js';

export const LS = {
  load(key, dflt) { try { const v = JSON.parse(globalThis.localStorage?.getItem(key) || 'null'); return v ?? dflt; } catch { return dflt; } },
  save(key, v) { try { globalThis.localStorage?.setItem(key, JSON.stringify(v)); } catch { /* private mode / quota */ } },
};

/** NORMAL string (cate, code), sync when loaded (else ''), with an async fallback. */
export function str(cate, code, group = 'NORMAL') {
  return strings.get({ group, cate, code }) ?? '';
}
export function strAsync(cate, code, group = 'NORMAL') {
  return strings.resolve({ group, cate, code }).then(v => v ?? '');
}
/** Preload whole cates (list of [group, cate, code]) so str() is synchronous afterwards. */
export async function needStrings(refs) {
  await strings.need(refs.map(([group, cate, code]) => ({ group, cate, code })));
  // hinted files might not hold them: resolve each once (loads the whole group when needed)
  await Promise.all(refs.map(([group, cate, code]) => strings.get({ group, cate, code }) == null ? strings.resolve({ group, cate, code }) : null));
}

/** Strip the client's layout tags (<font=N>, <center>, <set=N>, <Align=..>) keeping colour markup. */
export function plainMarkup(s) {
  return String(s ?? '')
    .replace(/<\/?font[^>]*>/gi, '')
    .replace(/<center>|<\/center>|<left>|<right>/gi, '')
    .replace(/<set=[^>]*>/gi, '')
    .replace(/<color=0x([0-9a-f]{2})([0-9a-f]{6})>/gi, '<color=$2>')
    .replace(/\\\\/g, '\n').replace(/\\$/gm, '');
}
/** Only the visible text (no markup at all). */
export function plainText(s) { return plainMarkup(s).replace(/<\/?color[^>]*>/gi, '').replace(/<[^>]+>/g, ''); }

export const clamp = (v, a, b) => Math.max(a, Math.min(b, v));
export const clamp01 = v => clamp(Number(v) || 0, 0, 1);
export const fmtInt = n => Math.round(Number(n) || 0).toLocaleString('en-US');

/** Is the keyboard focus in a text field? */
export function isTyping() {
  const a = globalThis.document?.activeElement;
  return !!(a && (a.tagName === 'INPUT' || a.tagName === 'TEXTAREA' || a.isContentEditable));
}

/** Show exactly one page of a tabbed window: pages = {tabBtnId: pageId}; the tab button shows its check sprite. */
export function selectPage(win, pages, tab) {
  for (const [btn, page] of Object.entries(pages)) {
    const on = btn === tab;
    win.control(btn).setChecked(on);
    if (page) for (const p of [].concat(page)) win.control(p).setVisible(on);
  }
}

/**
 * A client string that stayed Korean in this EU build, read as Latin-1 (EUC-KR = two high bytes per syllable):
 * e.g. the job strings of the event snowmen (desc 61808/61810). Such text is replaced by the EU name.
 */
export const garbledKr = s => /[¡-þ]{2}/.test(String(s || ''));
/** NPC name + title from a job string (splitNameTitle result) with the npc.csv EU name as the fallback. */
export function npcNameFix(nt, fallback) {
  const bad = garbledKr(nt?.name) || garbledKr(nt?.title);
  return { name: (!garbledKr(nt?.name) && nt?.name) || fallback || '', title: bad ? '' : (nt?.title || '') };
}

/** ARGB colour string 'ffRRGGBB' -> '#rrggbb'. */
export const argbToCss = a => `#${String(a || 'ffffffff').slice(-6)}`;

/** A tiny event hub. */
export class Hub {
  constructor() { this._h = Object.create(null); }
  on(ev, fn) { (this._h[ev] ||= []).push(fn); return () => this.off(ev, fn); }
  off(ev, fn) { const a = this._h[ev]; if (a) this._h[ev] = a.filter(f => f !== fn); }
  emit(ev, ...args) { for (const f of (this._h[ev] || []).slice()) { try { f(...args); } catch (err) { console.error(`[hud-options] ${ev}`, err); } } }
}
