// Cached item sheets animate in CSS. Hit testing happens only after input/layout/paint,
// never once per item per game frame; a large grid shares a 2ms / 64-box budget.
export function createSpinHover(doc, raf, now = () => performance.now()) {
  let point = null, hot = null, queued = false, candidates = null, cursor = 0, found = null;
  function mark(el) {
    // paintIcon may clear/repaint the same slot node as well as replace grids.
    if (hot === el) { hot?.classList.add('uw-spin-hot'); return; }
    hot?.classList.remove('uw-spin-hot');
    hot = el;
    hot?.classList.add('uw-spin-hot');
  }
  function tick() {
    queued = false;
    if (!point || doc.hidden) { candidates = null; mark(null); return; }
    if (!candidates) {
      // Icons don't receive pointer events. Their grid/slot does, and excludes
      // items behind another window or outside a clipped scrolling region.
      const hit = doc.elementFromPoint(point.x, point.y);
      const scope = hit?.closest('.uw-c, .uw-dnd');
      candidates = scope ? [...scope.querySelectorAll('.uw-spin')] : [];
      cursor = 0; found = null;
    }
    const start = now(); let count = 0;
    while (cursor < candidates.length && count++ < 64 && now() - start < 2) {
      const el = candidates[cursor++];
      if (!el.isConnected || el.closest('.uw-hidden, .uw-held')) continue;
      const r = el.getBoundingClientRect();
      if (r.width && r.height && point.x >= r.left && point.x < r.right && point.y >= r.top && point.y < r.bottom) found = el;
    }
    if (cursor < candidates.length) { queued = true; raf(tick); }
    else { candidates = null; mark(found); }
  }
  function refresh() { candidates = null; if (!queued) { queued = true; raf(tick); } }
  function move(event) { point = { x: event.clientX, y: event.clientY }; refresh(); }
  function leave() { point = null; refresh(); }
  doc.addEventListener('pointermove', move, { passive: true });
  doc.addEventListener('pointerleave', leave, { passive: true });
  doc.addEventListener('scroll', refresh, { passive: true, capture: true });
  doc.addEventListener('visibilitychange', () => { if (doc.hidden) leave(); else refresh(); });
  doc.defaultView?.addEventListener('resize', refresh, { passive: true });
  doc.defaultView?.addEventListener('blur', leave);
  return { refresh };
}

let tracker;
export function refreshSpinHover() {
  if (!globalThis.document || !globalThis.requestAnimationFrame) return;
  tracker ||= createSpinHover(document, requestAnimationFrame);
  tracker.refresh();
}
