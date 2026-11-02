// Fatal crash log: write a shareable text dump, show it on screen (copy/send instantly),
// auto-download the file, and on the local Windows host ask the server to open it (notepad).
// Does not change loading-screen opacity / artGate (black-screen fixes stay untouched).

const CRASH_DIR_HINT = 'DK Engine crash log';

function stamp() {
  const d = new Date();
  const p = n => String(n).padStart(2, '0');
  return `${d.getFullYear()}${p(d.getMonth() + 1)}${p(d.getDate())}-${p(d.getHours())}${p(d.getMinutes())}${p(d.getSeconds())}`;
}

export function formatCrashLog(err, extra = {}) {
  const lines = [];
  lines.push('DK Engine crash log');
  lines.push(`Time (local): ${new Date().toString()}`);
  lines.push(`URL: ${typeof location !== 'undefined' ? location.href : ''}`);
  lines.push(`UserAgent: ${typeof navigator !== 'undefined' ? navigator.userAgent : ''}`);
  if (extra.phase) lines.push(`Loading phase: ${extra.phase}`);
  if (extra.where) lines.push(`Where: ${extra.where}`);
  lines.push('');
  const message = err && (err.stack || err.message) ? String(err.stack || err.message) : String(err ?? 'Unknown error');
  lines.push(message);
  if (extra.detail) { lines.push(''); lines.push(String(extra.detail)); }
  lines.push('');
  lines.push('Copy this whole file and send it with a short note of what you clicked before the crash.');
  return lines.join('\n');
}

function downloadText(filename, text) {
  try {
    const blob = new Blob([text], { type: 'text/plain;charset=utf-8' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url; a.download = filename; a.rel = 'noopener';
    document.body.appendChild(a); a.click(); a.remove();
    setTimeout(() => URL.revokeObjectURL(url), 4000);
    return true;
  } catch { return false; }
}

async function copyText(text) {
  try {
    if (navigator?.clipboard?.writeText) { await navigator.clipboard.writeText(text); return true; }
  } catch { /* fall through */ }
  try {
    const ta = document.createElement('textarea');
    ta.value = text; ta.style.position = 'fixed'; ta.style.left = '-9999px';
    document.body.appendChild(ta); ta.select();
    const ok = document.execCommand?.('copy');
    ta.remove();
    return !!ok;
  } catch { return false; }
}

/** Ask the local engine (loopback only) to write the log under run/crashes and open it. */
async function openViaLocalHost(filename, text) {
  try {
    const res = await fetch('/api/client-crash', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ filename, text, open: true }),
      cache: 'no-store',
    });
    if (!res.ok) return null;
    return await res.json().catch(() => ({ ok: true }));
  } catch { return null; }
}

function showCrashViewer(filename, text, hostResult) {
  if (typeof document === 'undefined') return;
  const existing = document.getElementById('dk-crash-viewer');
  if (existing) existing.remove();
  const root = document.createElement('div');
  root.id = 'dk-crash-viewer';
  root.setAttribute('role', 'alertdialog');
  root.setAttribute('aria-label', CRASH_DIR_HINT);
  Object.assign(root.style, {
    position: 'fixed', inset: '0', zIndex: '2147483000', background: 'rgba(8,9,12,.92)',
    display: 'flex', alignItems: 'center', justifyContent: 'center', padding: '24px',
    fontFamily: 'Segoe UI, Tahoma, sans-serif', color: '#efe0c2',
  });
  const panel = document.createElement('div');
  Object.assign(panel.style, {
    width: 'min(920px, 96vw)', maxHeight: '90vh', background: '#16151c', border: '1px solid #5a4a2e',
    boxShadow: '0 12px 48px rgba(0,0,0,.55)', display: 'flex', flexDirection: 'column', gap: '12px', padding: '16px',
  });
  const title = document.createElement('h2');
  title.textContent = 'Crash log';
  Object.assign(title.style, { margin: '0', fontSize: '18px', fontWeight: '600', color: '#f2d9a0' });
  const note = document.createElement('div');
  note.style.fontSize = '13px';
  note.style.opacity = '0.9';
  const opened = hostResult?.opened ? ` Opened in notepad: ${hostResult.path || filename}` :
    hostResult?.path ? ` Saved: ${hostResult.path}` : ` Downloaded as ${filename} (and copied when allowed).`;
  note.textContent = 'The game hit a fatal error.' + opened + ' Copy/send this log so it can be fixed.';
  const pre = document.createElement('pre');
  Object.assign(pre.style, {
    margin: '0', flex: '1', overflow: 'auto', whiteSpace: 'pre-wrap', wordBreak: 'break-word',
    background: '#0c0c10', color: '#f2b3a8', padding: '12px', fontSize: '12px', lineHeight: '1.35',
    border: '1px solid #2a2a33', maxHeight: '55vh',
  });
  pre.textContent = text;
  const row = document.createElement('div');
  Object.assign(row.style, { display: 'flex', gap: '8px', flexWrap: 'wrap' });
  const mkBtn = (label, onClick) => {
    const b = document.createElement('button');
    b.type = 'button'; b.textContent = label;
    Object.assign(b.style, {
      cursor: 'pointer', background: '#2a2418', color: '#efe0c2', border: '1px solid #7a6230',
      padding: '8px 14px', fontSize: '13px',
    });
    b.onclick = onClick;
    return b;
  };
  row.appendChild(mkBtn('Copy log', async () => {
    const ok = await copyText(text);
    note.textContent = ok ? 'Crash log copied to clipboard.' : 'Copy failed — select the text above and Ctrl+C.';
  }));
  row.appendChild(mkBtn('Download again', () => { downloadText(filename, text); }));
  row.appendChild(mkBtn('Reload', () => { location.reload(); }));
  row.appendChild(mkBtn('Close', () => { root.remove(); }));
  panel.appendChild(title); panel.appendChild(note); panel.appendChild(pre); panel.appendChild(row);
  root.appendChild(panel);
  (document.getElementById('ui') || document.body).appendChild(root);
  try { pre.focus?.(); } catch {}
  // Select text so Ctrl+C works instantly even if clipboard API is blocked.
  try {
    const range = document.createRange();
    range.selectNodeContents(pre);
    const sel = getSelection();
    sel.removeAllRanges(); sel.addRange(range);
  } catch {}
}

let reporting = false;

/**
 * Record a fatal error: download + on-screen viewer + optional local notepad open.
 * Safe to call more than once; only the first report opens UI (later ones still log).
 */
export async function reportCrash(err, extra = {}) {
  const text = formatCrashLog(err, extra);
  const filename = `dk-crash-${stamp()}.txt`;
  console.error('[crash]', text);
  try { localStorage.setItem('dk.lastCrashLog', text); localStorage.setItem('dk.lastCrashFile', filename); } catch {}
  if (reporting) return { filename, text, duplicate: true };
  reporting = true;
  downloadText(filename, text);
  void copyText(text);
  const hostResult = await openViaLocalHost(filename, text);
  showCrashViewer(filename, text, hostResult);
  return { filename, text, hostResult };
}

export function installCrashHandlers({ onFatal } = {}) {
  if (typeof window === 'undefined') return;
  window.addEventListener('error', (ev) => {
    const err = ev.error || ev.message || 'window.error';
    void reportCrash(err, { where: 'window.error' });
    onFatal?.(err);
  });
  window.addEventListener('unhandledrejection', (ev) => {
    const err = ev.reason || 'unhandledrejection';
    // Always log; open the viewer for Error-like rejections (map-entry recovery has its own UI).
    console.error('unhandled', err);
    const loadingAlert = typeof document !== 'undefined' && document.querySelector?.('.fe-loading [role="alert"]');
    if (loadingAlert) return;
    void reportCrash(err, { where: 'unhandledrejection' });
    onFatal?.(err);
  });
}