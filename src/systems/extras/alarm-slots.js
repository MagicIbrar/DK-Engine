// Original HUD alarm scripts share a 40px grid and several duplicate positions.
// Their compiled client's collision rule is unknown. The six common icons sit in
// two rows of three, with Deka Pass beneath and reception clear on the left. Conditional alarms
// keep their original controls/actions and use free columns beside that reserved block.
export const ALARM_PITCH = 40;
export const POPULATION_ROW_PITCH = 19;

// Compact alarm block. Keep original controls, art, sizes and actions.
// The crossed-swords lobby icon belongs LEFT of the gift box (connect reward), lined up with
// the other five - the Training Camp icon (tc_active) was drawn in a free column far right instead. The lobby icons share
// that one slot: the first open keeps it, a second one uses the next free column (no overlap).
const HUD_ALARM_POSITIONS = Object.fromEntries(Object.entries({
  hud_helpalarm: [50, 60], tc_active: [90, 60], dk_active: [90, 60], dk_alarm: [90, 60], connectreward_alarm: [130, 60],
  'shops.supply_alarm': [50, 100], 'shops.orbis_alarm': [90, 100], autohunt_alarm: [130, 100],
  dekapassalarm: [50, 140],
}).map(([name,[x,y]])=>[name,[x,y+POPULATION_ROW_PITCH]]));
const HUD_RESERVED = [[0, 60, 50, 40], [50, 60, 30, 31], [90, 60, 30, 30], [130, 60, 30, 30],
  [50, 100, 30, 30], [90, 100, 30, 30], [130, 100, 30, 30], [50, 140, 111, 28]].map(([x,y,w,h])=>[x,y+POPULATION_ROW_PITCH,w,h]);
const SHARED_LOBBY_SLOT = new Set(['tc_active', 'dk_active', 'dk_alarm']);
function fixedAlarmRect(win, button, ui = null) {
  const p = HUD_ALARM_POSITIONS[win?.name], r = button?.spec?.rect;
  if (!(p && r && ['btn_alarm', 'btn_active'].includes(button.id))) return null;
  const rect = [...p, r[2], r[3]];
  // the shared lobby slot is taken by another open lobby icon: use the next free column instead
  if (ui && SHARED_LOBBY_SLOT.has(win.name) && occupiedRects(ui, [win.name]).some(o => overlaps(rect, o))) return null;
  return rect;
}
function setAlarmRect(button, rect) {
  const cur = button._rectOverride || button.spec.rect;
  if (cur.some((n, i) => n !== rect[i])) button.setRect(...rect);
}

/** Apply layout on existing window opens; no new timer, visibility rule or action handler. */
export function installHudAlarmLayout(ui) {
  if (!ui?.on || ui._hudAlarmLayout) return;
  ui._hudAlarmLayout = true;
  const place = () => {
    const server=ui.window?.('hud_server');
    if(server){
      const origin=server.defaultBox();
      for(const [name,row]of [['hud_server',0],['hud_population',1],['hud_localtime',2]]){
        const win=ui.window?.(name);if(win)win.setPosition(origin.x,origin.y+row*POPULATION_ROW_PITCH,false);
      }
    }
    for (const win of ui.openWindows()) {
      if (!win.opts.hud) continue;
      if (win.name === 'hud_reception') {
        // Pin to the alarm row instead of proportional screen placement. The value stays
        // below its bars in the clear left strip, using the original font and height.
        win.setPosition(0, 60+POPULATION_ROW_PITCH, false);
        win.control('pan_reception').setRect(8, 4, 33, 11);
        win.control('lbl_ping').setRect(0, 16, 45, 18);
        continue;
      }
      for (const c of win.controls(k => k.spec?.type === 'button')) {
        const fixed = fixedAlarmRect(win, c, ui);
        if (fixed) { setAlarmRect(c, fixed); continue; }
        if (!c.isVisible() || !c.box.w || !c.box.h) continue;
        let x = win.box.x, y = win.box.y;
        for (let k = c; k && k !== win.root; k = k.parent) { x += k.box.x; y += k.box.y; }
        const rect = [x, y, c.box.w, c.box.h];
        if (x >= 230 || y < 50 || y > 200+POPULATION_ROW_PITCH || c.box.w > 120 || c.box.h > 40 || !HUD_RESERVED.some(r => overlaps(rect, r))) continue;
        // Conditional alarms retain their actions and use a free column beside the block.
        const next = freeSlot(rect, [...HUD_RESERVED, ...occupiedRects(ui, [win.name])]);
        c.setRect(c.box.x + next[0] - x, c.box.y + next[1] - y, c.box.w, c.box.h);
      }
    }
  };
  ui.on('open', place);
  ui.on('resize', place);
  place();
}

const overlaps = (a, b) => a[0] < b[0] + b[2] && b[0] < a[0] + a[2] && a[1] < b[1] + b[3] && b[1] < a[1] + a[3];
/** First rect of the scripted row (x0, x0 + 40, ...) that no occupied rect covers; the scripted rect when none is free. */
export function freeSlot(rect, occupied, { pitch = ALARM_PITCH, maxX = 1024 } = {}) {
  const [x0, y, w, h] = rect;
  for (let x = x0; x + w <= maxX; x += pitch) if (!occupied.some(o => overlaps([x, y, w, h], o))) return [x, y, w, h];
  return rect.slice();
}
/** Screen rects (reference px) of the visible buttons of the open HUD windows, except the named windows. */
export function occupiedRects(ui, exclude = []) {
  const out = [];
  for (const w of ui?.openWindows?.() || []) {
    if (!w?.opts?.hud || exclude.includes(w.name)) continue;
    for (const c of w.controls?.(k => k.spec?.type === 'button') || []) {
      if (!c.isVisible?.() || !c.box?.w || !c.box?.h) continue;
      let x = w.box?.x || 0, y = w.box?.y || 0;
      for (let k = c; k && k !== w.root; k = k.parent) { x += k.box?.x || 0; y += k.box?.y || 0; }
      out.push([x, y, c.box.w, c.box.h]);
    }
  }
  return out;
}
/**
 * Keep `button` (a control of a full-screen 'position inverse inverse' alarm window, so its rect is a screen rect) on a free
 * slot of its scripted row. `exclude` = windows that never push it (itself and lower-priority alarms). Returns the rect used.
 */
export function placeAlarmButton(ui, win, button, exclude = []) {
  if (!win?.isOpen || !button?.spec?.rect) return null;
  const rect = fixedAlarmRect(win, button, ui) || freeSlot(button.spec.rect, [...HUD_RESERVED, ...occupiedRects(ui, [win.name, ...exclude])]);
  const cur = button._rectOverride || button.spec.rect;
  if (cur[0] !== rect[0] || cur[1] !== rect[1]) button.setRect(rect[0], rect[1], rect[2], rect[3]);
  return rect;
}
