// Socket presentation contract; the former whole-weapon overlay and linear
// per-count strength are retired. No renderer imports gain/tint knobs here.
// Verified Global: stone Attribute (CSV column 5, item.dat offset 149),
// modeleffect.csv group24/sub1/code3=0/code4=attribute -> cate7 IDs1..6;
// row0 selects ID6. One camera sprite, size .9, original socket_*.dds, additive,
// original 1000ms alpha (.5/.8/.5) and scale (.8/1/.8) keys, no extra gain.
// ENGINE-CHOSEN integration, because native binary invocation is unavailable:
// - unchanged zero-offset sprite at each equipped weapon's local origin;
//   no authored bone/position or trace-line midpoint exists in these scenes;
// - one simultaneous scene per distinct stone attribute, including stat stones;
//   duplicate stones do not multiply brightness and partial sockets are allowed;
// - attribute0 modern elemental stones use their single damage option56..60;
//   otherwise attribute0 uses Global's default row0 (normal sprite).
// - the existing first-person attachment pass rebases the SAME sprite to the
//   visible weapon. No first-person size, brightness, or material override.
// This is source-backed effect playback, not a claim of native binary parity.
//
// ---- Revision: socket mist along the blade + gem-coloured weapon wash --------------------------------
// The data above fixes WHICH scene plays for a stone (attribute -> sk_* sprite, its texture, alpha and scale keys) and the
// stone's colour (the socket_*.dds hue, socketHueOf()). It authors no position, no blade length, no count rule and no
// weapon tint. The values below are therefore ENGINE-CHOSEN (not in Global data):
/** Strength factor of a weapon glow with `filled` gems in `capacity` sockets: 1 with any gem, 0 with none.
 *  FROM THE DATA (re-checked): Global has NO gem-count rule. modeleffect.csv
 *  group 24 has exactly 7 rows, code1 24 / code2 1 / code3 0 / code4 = stone Attribute 0..6 -> one effect scene each; code3
 *  is never non-zero, so no row varies with the number of gems; the scenes themselves (cate 7 ids 1..6, sp_socket_*) have
 *  fixed alpha/scale keys; share/item socket tables (itemsocket, socketmaxinfo, itemetc_socket, itemaddsocket) hold only
 *  stats and rates. So one gem shows the same authored effect as four. The former 51/68/84/100 % steps were an
 *  unsourced rule with an ENGINE-CHOSEN minimum (not data) and are removed. `capacity` is kept for callers. */
export function socketPhase(filled, capacity) {
  return Number(filled) > 0 ? 1 : 0;
}
export const SOCKET_GLOW_CHOSEN = Object.freeze({
  /** IN HAND: one authored sprite scene per FILLED SOCKET (not one per element), placed on the weapon's own blade line:
   *  traceline (blade strip) else weaponline (longest strip) else the long axis of the weapon mesh bounds. Socket i of n sits at
   *  fraction (i + .5) / n of that line, inset to this span so no mist floats off the tip or grip. Socket 0 = tip end
   *  (the same top-down order as the inventory markers). */
  STATION_SPAN: [0.08, 0.92],
  /** ENGINE-CHOSEN: authored sprite scale multiplier = clamp(station spacing (m) / SPRITE_SPACING, SPRITE_MIN_SCALE,
   *  SPRITE_MAX_SCALE): the size-.9 mist of a long blade grows so its sprites overlap into one haze along the whole blade, those
   *  of a short weapon (pierce, orb, wand) shrink so they do not pile onto one blob. The authored alpha keys are untouched. */
  SPRITE_SPACING: 0.4,
  /** ENGINE-CHOSEN: control colour gain of the station mist sprites (equal on r,g,b, so the texture's hue is kept; the texture
   *  centre peaks at .9 x alpha .51 x key .8 = .37 per unit gain, so 2.4 stays below clipping). */
  MIST_GAIN: 2.4,
  SPRITE_MIN_SCALE: 0.6,
  SPRITE_MAX_SCALE: 1.5,
  // (PHASE removed 2026-10-03: the gem-count steps were not in the data - see socketPhase above. The colours still blend by
  //  the gems used, from each stone's socket_*.dds hue.)
  /** ENGINE-CHOSEN: the mist sprites sit ON the blade line, inside the weapon, so a plain depth test lets the weapon's own surface
   *  clip them. Their depth (not their position or size) is shifted toward the camera by FRACTION x the middle extent of the
   *  weapon's bounds (a blade's width, in metres, capped at MAX): enough to clear the weapon's own surface, small enough that a
   *  wall between the camera and the wearer still hides them. Measured in the real client. */
  MIST_DEPTH_BIAS: Object.freeze({FRACTION: 0.5, MAX: 0.6}),
  /** IN HAND: additive gem-coloured pass over the weapon meshes ("a coloured glow ON the weapon"). The colour of every vertex is
   *  the socket hues blended by distance to the sockets (range = max(RANGE_MIN, spacing * RANGE_SPACING) m); the pulse is the
   *  authored socket alpha key track (.5/.8/.5 over 1000 ms) normalised to its peak. */
  // REVISION (compared with the official look): the glow is an OUTER AURA / edge glow, not paint over the weapon. The
  // shell stands out from the surface, is almost transparent where it faces the camera (the weapon's own texture shows through)
  // and glows at the silhouette; only a faint gem light stays on the surface itself, a little stronger near each socket.
  WEAPON_WASH: Object.freeze({
    SHELL: 0.012,        // m, pushed out along the normals: the aura stands off the surface (weapon refinement shell is .005)
    BASE: 0.06,          // gem light on the surface facing the camera (kept faint: the weapon texture stays visible)
    LOCAL: 0.30,         // extra gem light near a socket
    RIM: 2.4,            // view-dependent edge light (rim power 1.6): where the aura lives
    GAIN: 1.0,           // overall gain
    LIGHT_CAP: 1.2,      // gem light ceiling (the hue's strongest channel saturates, so it still reads as that hue in the bloom)
    TINT_BASE: 0.02,     // share of the weapon's own colour replaced by the gem hue on camera-facing surface (premultiplied 'over')
    TINT_LOCAL: 0.06,    // extra replaced share near a socket
    TINT_RIM: 0.75,      // coverage of the shell at the silhouette (the aura itself)
    TINT_CAP: 0.85,
    MEAN_BLEND: 0.15,    // weight of the mean hue far from every socket
    RANGE_MIN: 0.25,
    RANGE_SPACING: 0.9,
    POLYGON_OFFSET: [-4, -16],
  }),
  /** INVENTORY: the icon is baked (icons.js) with the UI (cate 8) twin of the socket scene at every filled socket marker:
   *  sprite size = SPRITE_UNIT x marker size px, authored UI scale keys (1.5,1,1.5)(1.8,2,1.8) stretch it, alpha keys as authored.
   *  A tinted copy of the weapon artwork (each pixel coloured by the gems nearest to it) is added over the art (WASH) and
   *  blurred behind it (HALO), so the gem colour washes over the weapon and haloes along the blade. */
  ICON: Object.freeze({
    SPRITE_UNIT: 1.5,
    SPRITE_GAIN: 1.3,    // the authored alpha keys (.5-.8) times this, capped at 1 (texture alpha is only .5): gems stay defined
    TINT: 0.06,          // share of the artwork's own colour replaced by the gem hue: the weapon art stays visible
    WASH: 0.12,
    HALO: 1.0,           // the aura: blurred silhouette behind the art (strength of the widest-spread layers is scaled by HALOS below)
    HALO_BLUR: 5,        // reference px (legacy single-radius value; HALOS below replace it)
    // Ghost halo, FITTED to a Global inventory screenshot (equipment weapon slot: a soft blue-white cloud reaching ~25 ref px around
    // the weapon). Stacked blurred copies of the gem-coloured silhouette behind the art: [blur radius in reference px, strength].
    HALOS: Object.freeze([[3, 1.0], [8, 0.9], [16, 0.8]]),
    RANGE: 2.6,          // wash colour reach around a gem, in marker sizes
  }),
});
