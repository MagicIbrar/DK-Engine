// Status icons move their remembered HUD window after a real drag, never on a click.
export function statusIconDrag(win, control) {
  let suppressClick = false;
  control.el.addEventListener('click', e => {
    if (suppressClick) { suppressClick = false; e.preventDefault(); e.stopImmediatePropagation(); }
  }, true);
  control.el.addEventListener('pointerdown', e => {
    if (e.button !== 0) return;
    suppressClick = false;
    e.stopPropagation();
    win.mgr.focus(win);
    const sx=e.clientX, sy=e.clientY, ox=win.box.x, oy=win.box.y, scale=win.mgr.scale||1;
    let dragged=false;
    const move=ev=>{
      if (ev.pointerId !== e.pointerId) return;
      if (!dragged && Math.hypot(ev.clientX-sx,ev.clientY-sy)<5) return;
      dragged=true; ev.preventDefault();
      win.setPosition(Math.round(ox+(ev.clientX-sx)/scale),Math.round(oy+(ev.clientY-sy)/scale),false);
    };
    const up=ev=>{
      if (ev.pointerId !== e.pointerId) return;
      removeEventListener('pointermove',move);removeEventListener('pointerup',up);removeEventListener('pointercancel',up);
      if (dragged) { suppressClick=true; win.setPosition(win.box.x,win.box.y); }
    };
    addEventListener('pointermove',move);addEventListener('pointerup',up);addEventListener('pointercancel',up);
  });
}
