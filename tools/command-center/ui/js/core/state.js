// Small shared store: world status, settings, updates. Subscribers re-render only what they own.
const data = {world: null, settings: null, schema: null, updates: null, errors: 0};
const subs = new Map();
export const state = new Proxy(data, {set(t, k, v) { t[k] = v; for (const f of subs.get(k) || []) { try { f(v); } catch (e) { console.error(e); } } return true; }});
export function on(key, fn) { if (!subs.has(key)) subs.set(key, new Set()); subs.get(key).add(fn); if (data[key] !== null && data[key] !== undefined) fn(data[key]); return () => subs.get(key).delete(fn); }
