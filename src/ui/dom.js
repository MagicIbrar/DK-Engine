// Tiny DOM helpers for the HUD/windows (no framework). Elements are built with h() and kept by
// reference, so nothing depends on innerHTML parsing or selectors (and the UI can be exercised in
// Node with a minimal DOM shim - see tools/test-ui.mjs).

/**
 * h('div', { class: 'x', style: {left: '3px'}, text: 'hi', onclick: fn, title: 't' }, ...children)
 */
export function h(tag, props, ...children) {
  const el = document.createElement(tag);
  if (props) {
    for (const k of Object.keys(props)) {
      const v = props[k];
      if (v == null || v === false) continue;
      if (k === 'class') el.className = v;
      else if (k === 'text') el.textContent = String(v);
      else if (k === 'style' && typeof v === 'object') Object.assign(el.style, v);
      else if (k === 'dataset') Object.assign(el.dataset, v);
      else if (k.startsWith('on') && typeof v === 'function') el.addEventListener(k.slice(2), v);
      else if (k === 'value' || k === 'checked' || k === 'disabled' || k === 'draggable' || k === 'min' || k === 'max' || k === 'step' || k === 'type' || k === 'placeholder') el[k] = v;
      else el.setAttribute(k, v === true ? '' : String(v));
    }
  }
  append(el, children);
  return el;
}

export function append(el, children) {
  for (const c of children) {
    if (c == null || c === false) continue;
    if (Array.isArray(c)) append(el, c);
    else if (typeof c === 'string' || typeof c === 'number') el.appendChild(document.createTextNode(String(c)));
    else el.appendChild(c);
  }
  return el;
}

export function clear(el) {
  while (el.firstChild) el.removeChild(el.firstChild);
  return el;
}

export const clamp = (v, a, b) => (v < a ? a : v > b ? b : v);
export const clamp01 = v => clamp(Number.isFinite(v) ? v : 0, 0, 1);

/** 1234567 -> "1,234,567" */
export function fmtInt(n) {
  n = Math.round(Number(n) || 0);
  const s = String(Math.abs(n)).replace(/\B(?=(\d{3})+(?!\d))/g, ',');
  return n < 0 ? `-${s}` : s;
}

/** 0.12345 -> "12.34%" (Dekaron shows two decimals) */
export function fmtPct(frac) {
  return `${(Math.floor(clamp01(frac) * 10000) / 100).toFixed(2)}%`;
}

export function fmtSec(ms) {
  const s = Number(ms) / 1000;
  if (!Number.isFinite(s)) return '-';
  if (s >= 60) return `${Math.round(s / 6) / 10}m`;
  return `${Math.round(s * 10) / 10}s`;
}

export function fmtDuration(sec) {
  sec = Math.max(0, Math.floor(Number(sec) || 0));
  const hh = Math.floor(sec / 3600), mm = Math.floor((sec % 3600) / 60);
  return hh ? `${hh}h ${mm}m` : `${mm}m ${sec % 60}s`;
}

/** Set text only when it changed (cheap per-frame updates). */
export function setText(el, text) {
  text = String(text);
  if (el._t !== text) { el._t = text; el.textContent = text; }
}

/** Set a style property only when it changed. */
export function setStyle(el, prop, value) {
  const key = `_s_${prop}`;
  if (el[key] !== value) { el[key] = value; el.style[prop] = value; }
}

export function toggleClass(el, cls, on) {
  const key = `_c_${cls}`;
  on = !!on;
  if (el[key] !== on) { el[key] = on; el.classList.toggle(cls, on); }
}

/** localStorage JSON helpers that never throw. */
export function loadLocal(key, fallback) {
  try {
    const v = globalThis.localStorage?.getItem(key);
    return v == null ? fallback : JSON.parse(v);
  } catch { return fallback; }
}
export function saveLocal(key, value) {
  try { globalThis.localStorage?.setItem(key, JSON.stringify(value)); } catch { /* ignore */ }
}

/** True while the user is typing in a text field (keys must not reach the game). */
export function isTyping() {
  const el = globalThis.document?.activeElement;
  return !!el && (el.tagName === 'INPUT' || el.tagName === 'TEXTAREA' || el.isContentEditable === true);
}
