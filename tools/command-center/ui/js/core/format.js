export const n = (x, d = 0) => x === null || x === undefined || Number.isNaN(Number(x)) ? '—' : Number(x).toLocaleString(undefined, {maximumFractionDigits: d, minimumFractionDigits: d});
export function bytes(b, d = 1) { if (b === null || b === undefined) return '—'; const u = ['B', 'KB', 'MB', 'GB', 'TB']; let i = 0, v = Number(b); while (v >= 1024 && i < u.length - 1) { v /= 1024; i++; } return `${v.toFixed(i ? d : 0)} ${u[i]}`; }
export function mb(m, d = 1) { return m === null || m === undefined ? '—' : `${n(m, d)} MB`; }
export function duration(ms) { if (ms === null || ms === undefined) return '—'; const s = Math.round(ms / 1000); if (s < 60) return `${s} s`; const m = Math.floor(s / 60); if (m < 60) return `${m} min ${s % 60} s`; const hrs = Math.floor(m / 60); if (hrs < 48) return `${hrs} h ${m % 60} min`; return `${Math.floor(hrs / 24)} d ${hrs % 24} h`; }
export function ago(t) { if (!t) return 'never'; const ms = Date.now() - new Date(t).getTime(); if (ms < 5000) return 'just now'; if (ms < 60000) return `${Math.round(ms / 1000)} s ago`; if (ms < 3600000) return `${Math.round(ms / 60000)} min ago`; if (ms < 86400000) return `${Math.round(ms / 3600000)} h ago`; return new Date(t).toLocaleString(); }
export const time = t => t ? new Date(t).toLocaleTimeString([], {hour: '2-digit', minute: '2-digit', second: '2-digit'}) : '—';
export const dateTime = t => t ? new Date(t).toLocaleString([], {year: 'numeric', month: 'short', day: 'numeric', hour: '2-digit', minute: '2-digit'}) : '—';
export const plural = (k, one, many = one + 's') => `${n(k)} ${k === 1 ? one : many}`;
export const ms = x => x === null || x === undefined ? '—' : `${n(x, x < 10 ? 1 : 0)} ms`;
export const short = (s, len = 12) => s ? (String(s).length > len ? String(s).slice(0, len) + '…' : String(s)) : '—';
