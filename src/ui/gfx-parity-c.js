// Stream C (Global 43.19 UI parity, 2026-10-29) runtime off switch.
// All C fixes off: globalThis.__dkGfxParityC = false, or localStorage 'dk.gfxC.off' = '1'.
// One fix off: globalThis.__dkGfxParityC = { <key>: false } or localStorage 'dk.gfxC.off.<key>' = '1'
// (keys: fontweight, hudfmt, chatcolor; stream C3: hudpos, quickslot, topleft; round 4: chatgeom, alarms). Read when the value is built (fonts / chat colours at load, HUD text on change).
export function gfxC(key) {
  try {
    const g = globalThis.__dkGfxParityC;
    if (g === false || (g && typeof g === 'object' && g[key] === false)) return false;
    const ls = globalThis.localStorage;
    if (ls && (ls.getItem('dk.gfxC.off') === '1' || ls.getItem('dk.gfxC.off.' + key) === '1')) return false;
  } catch { /* no storage */ }
  return true;
}
