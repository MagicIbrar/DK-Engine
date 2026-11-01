// Keep one physical pointer in charge of a panel until release or cancellation.
// Touch scrolling is suppressed only while its title is being dragged.
export function beginPanelDrag(event, { surface, move, finish, win = globalThis }) {
  if (event.button !== 0 || event.isPrimary === false) return null;
  event.preventDefault();
  const id = event.pointerId;
  let ended = false;
  const owns = e => e.pointerId === id;
  const stopScroll = e => { if (event.pointerType === 'touch') e.preventDefault(); };
  const onMove = e => { if (owns(e)) { e.preventDefault(); move(e); } };
  const end = e => { if (!e || owns(e)) cancel(); };
  const cancel = () => {
    if (ended) return;
    ended = true;
    win.removeEventListener('pointermove', onMove);
    for (const name of ['pointerup', 'pointercancel']) win.removeEventListener(name, end);
    for (const name of ['blur', 'pagehide']) win.removeEventListener(name, cancel);
    surface.removeEventListener('lostpointercapture', end);
    for (const name of ['touchstart', 'touchmove', 'contextmenu']) surface.removeEventListener(name, stopScroll);
    try { if (surface.hasPointerCapture?.(id)) surface.releasePointerCapture(id); } catch { /* A removed panel has already lost capture. */ }
    finish?.();
  };
  win.addEventListener('pointermove', onMove, { passive: false });
  for (const name of ['pointerup', 'pointercancel']) win.addEventListener(name, end);
  for (const name of ['blur', 'pagehide']) win.addEventListener(name, cancel);
  surface.addEventListener('lostpointercapture', end);
  // Pointerdown precedes touchstart. Cancel the browser's default pan before it
  // steals this title gesture, without disabling scrolling in the panel body.
  for (const name of ['touchstart', 'touchmove', 'contextmenu']) surface.addEventListener(name, stopScroll, { passive: false });
  try { surface.setPointerCapture?.(id); } catch { /* Synthetic test pointers may not have native capture. */ }
  return cancel;
}
