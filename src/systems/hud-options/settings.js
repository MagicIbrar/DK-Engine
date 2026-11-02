// The client options (script/ui/game2/option/ui_optionwnd.txt, every tab), their defaults, persistence and the
// real behaviour each one drives. game.options = this store:
//   get(key) / all() / set(patch) (applies + persists + emits 'options' on game.events) / defaults / on('change', fn)
// Other systems read the options that belong to them (e.g. blockTrade, smartwarp, autoRevive) with game.options.get().
//
// Keys follow the option window's control ids (check_cloud -> cloud, sld_sound -> bgm ...). Sliders keep the
// script's own ranges (0..100, bloom 0..2, chat alpha 0..255).
import { LS, Hub, clamp } from './util.js';
import { gfxC } from '../../ui/gfx-parity-c.js';

const KEY = 'dekaron-solo:options:v1';

/** Graphics defaults follow Global options where known, except the foreground frame limit. */
export const DEFAULTS = Object.freeze({
  // ---- Graphics (pan_screen)
  quality: 'good',          // btn_levelgood|average|poor -> FUN_00b42c00(3|2|1); option.txt quality 2=average. Keep 'good' so DRAW_DISTANCE=1.0 matches Global clipfar full range.
  gamma: 50,                // sld_gamma 0..100 (50 = neutral)
  resolution: '1024x768',   // com_display: 'native' (window as it is) or 'WxH'; default = Global data/shadow.txt [init] display_width 1024 / display_height 768
  winmode: false,           // check_winmode (unchecked = full screen); Global option.txt mode true = fullscreen
  cloud: true, specular: true, bump: false, blood: true, quake: true, bloom: true,
  swimming: false, reflectTile: true, smartwarp: true,  // Global swimming_effect false
  bloomLevel: 1,            // sld_bloom 0..2 -> BLOOM_LEVELS 1.0 = Global full ONE/ONE add (bloomeffect.fx has no intensity uniform).
                            // 2026-10-29 [flash-sun]: was 0 (x0.7, from mapping option.txt bloom_value 0.10 -> int 0, an ENGINE guess). Ardeca 150
                            // 306,126 18:23 side-by-side vs Global: x1.0 ground = [225,170,216] vs Global [224,167,212]; x0.7 = [191,141,183].
  trace: 2,                 // com_trace: 0 N/A, 1 Character, 2 All
  shadow: 2,                // com_shadow = Global rc_shadowlevel: 0 off, 1 256, 2 512, 3 1024 (apply.js); Global option.txt shadowlevel 2
  highShadow: false,         // Global option.txt high_shadow false; option +0x12. Stored only: FUN_00a28080 is a UI layout clamp, not a shadow gate (LANE-66). No ui_optionwnd control.
  triFilter: false,           // Global option.txt tri_filter false; decompile +0x11 (capability-gated sampler filter enable). No ui_optionwnd control.
  water: 1,                 // com_water: 0 Low, 1 Middle, 2 High; Global option.txt waterlevel 1
  bgFrame: 2,               // com_background_frame index into BG_FRAMES; Global option.txt backgroundframe 66 (non-UI) snapped to nearest valid 60
  frameLimit: 0,            // no application frame cap for new profiles; display/compositor cadence can still limit frames
  quakeOption: 0,           // com_quake_option: 0 Strong, 1 Medium, 2 Weak, 3 Very weak; Global quake_segment 0
  // ---- Sound (pan_sound)
  mp3: false,
  bgm: 50, bgmMute: false,
  ambient: 80, ambientMute: false,  // Global option.txt ambientsound 80.00
  skillSound: 80, skillSoundMute: false,
  servant: 80, servantMute: false,
  effect: 80, effectMute: false,  // Global option.txt effectsound 80.00
  // ---- Game (pan_game)
  blockTrade: false, blockParty: false, blockGuild: false, blockFriend: false, blockPvp: false, blockPartyPvp: false,
  blockAlliance: false, rejectRevive: false,
  partyUiOpen: false, // Global43.8.0: reveal party status on channel change; preserve prior hidden-state default.
  stackQuestReward: true, dropMsg: true, runeMsg: true, priceMsg: true, sortMsg: true, presetMsg: true,
  presetBlinkIcon: true, presetCallPet: true,  // Global option.txt presetchangecallpet true
  // ---- View (pan_see)
  showServer: true, showReception: true, showCostume: true, showWing: true, saveCamera: false,
  cameraMode: 'third-person', firstPersonFov: 70,
  damageView: 0,            // com_damage: 0 all, 1 own only, 2 none
  effectView: 0,            // com_effect: 0 all users, 1 own only, 2 none
  charName: true, nameView: 0, guildName: true, allianceName: true, titleName: true, ratingName: true, allShow: true,
  captionBar: 0,            // 0 brightly, 1 darkly
  damageFont: 0,            // 0..3 = Type A..D
  // ---- Battle Setting (pan_combat)
  controlType: 1,           // 0 = A (select then right click), 1 = B (hotkey uses the skill)
  notExpedition: true, notGuild: true, notFriend: true, notGeneral: false,
  selfTarget: false, dkAutoEnter: false, siegeForceAttack: false,
  autoPotion: true, hpLimit: 50, mpLimit: 50, autoRevive: false,  // Global autoUsePotion true / useMpPotionRatio 50
  // ---- Chatting (pan_chat) + chat option window
  chatOnTop: true, chatMovable: false, chatExtra: false,  // Global option.txt alwaysontop true
  // gfxC4 [chatgeom]: Global bin/option.txt genchatalpha 80 / syschatalpha 80 (same 0-255 scale)
  chatAlpha: gfxC('chatgeom') ? 80 : 128, chatSize: 3, chatFont: 2, sysAlpha: gfxC('chatgeom') ? 80 : 128, sysSize: 3,
  chatType: 0,
  chatNormal: true, chatWorldMatch: true, chatParty: true, chatGuild: true, chatShout: true, chatWhisper: true,
  chatOfficer: true, chatAlliance: true, chatWorld: true,
  chatColors: null,         // {type: 'RRGGBB'} overrides (select-colour window)
  chatVisible: true,        // Ctrl+C (View/Hide Chat)
  // ---- HUD layout state (quick slot rows etc. live in the character save)
  minimapZoom: 0,           // 0 normal, 1 "bigmap" (+)
  minimapHidden: false,
  mapAlpha: 100,            // world-map sld_alpha (ui_mapwnd.txt 0..100; runtime floor 30). Global option.txt mapalpha 0..255; UI 100 == file 255 == opaque. Opacity = mapAlpha/100.
});

// Retained preferences whose gameplay adapters are not implemented in this client.
export const UNIMPLEMENTED_OPTIONS = Object.freeze([
  'chatExtra',
]);

/** Graphics quality presets (btn_levelgood/average/poor) -> the options they set. */
export const QUALITY = {
  // decompile FUN_00b42c00(3/2/1) <- btn_levelgood/average/poor. Fields: water+0x46 shadow+0x47 trace+0x3d bloom+0x1a bump+0x1e blood+0x18 specular+0x1c cloud+0x1d. Does not set swimming/reflect_tile.
  good:    { shadow: 2, water: 2, trace: 2, cloud: true,  specular: true,  bump: true,  bloom: true,  blood: true  },
  average: { shadow: 1, water: 1, trace: 1, cloud: true,  specular: true,  bump: false, bloom: false, blood: true  },
  poor:    { shadow: 0, water: 0, trace: 0, cloud: false, specular: false, bump: false, bloom: false, blood: false },
};
export const FRAME_LIMITS = [0, 60, 75, 120, 144, 165, 200, 240, 300];
export const BG_FRAMES = [15, 30, 60];
/**
 * The frame limit in force right now: the "Max fps" entry (0 = unlimited) while the window is in front, the
 * background-frame entry (BG_FRAMES, always > 0) while it is hidden or unfocused. One definition shared by the limiter
 * (apply.js) and the quality governor (graphics/index.js), so the governor never mistakes a background cap for lag.
 */
export function effectiveFrameLimit(frameLimitIndex, bgFrameIndex, background) {
  if (background) return BG_FRAMES[clamp(Math.round(Number(bgFrameIndex) || 0), 0, BG_FRAMES.length - 1)];
  const own = FRAME_LIMITS[clamp(Math.round(Number(frameLimitIndex) || 0), 0, FRAME_LIMITS.length - 1)];
  const cap = launcherFrameCap();
  return cap > 0 && (own === 0 || own > cap) ? cap : own;
}
/**
 * The DK Command Center "Frame rate cap" (Play settings, default 240; 0 = uncapped): a ceiling on the in-game Max fps, handed
 * to the page as ?maxfps= by launch.html and remembered for the tab (sessionStorage) because later in-page navigations drop
 * the query. Paced by frame-pacer.js on requestAnimationFrame, so with vsync on it never exceeds the display rate (no tearing).
 */
let _launcherCap;
export function launcherFrameCap(win = globalThis) {
  if (_launcherCap !== undefined && win === globalThis) return _launcherCap;
  let cap = 0;
  try {
    const raw = new URLSearchParams(win.location?.search || '').get('maxfps');
    if (raw != null && /^\d{1,3}$/.test(raw)) { cap = Number(raw); try { win.sessionStorage?.setItem('dk.launchMaxFps', String(cap)); } catch { /* storage off */ } }
    else { const s = win.sessionStorage?.getItem('dk.launchMaxFps'); if (s != null && /^\d{1,3}$/.test(s)) cap = Number(s); }
  } catch { cap = 0; }
  cap = cap >= 30 && cap <= 500 ? cap : 0;
  if (win === globalThis) _launcherCap = cap;
  return cap;
}
// Validate persisted values and patches at the boundary, before any consumer sees them.
export const OPTION_RANGES = Object.freeze({
  gamma: [0,100], bloomLevel: [0,2], trace: [0,2], shadow: [0,3], water: [0,2], bgFrame: [0,2], frameLimit: [0,8], quakeOption: [0,3],
  bgm: [0,100], ambient: [0,100], skillSound: [0,100], servant: [0,100], effect: [0,100],
  firstPersonFov: [50,100], damageView: [0,2], effectView: [0,2], nameView: [0,2], captionBar: [0,1], damageFont: [0,3], controlType: [0,1],
  hpLimit: [0,100], mpLimit: [0,100], chatAlpha: [0,255], chatSize: [1,6], chatFont: [1,5], sysAlpha: [0,255], sysSize: [1,6], chatType: [0,6], minimapZoom: [0,1], mapAlpha: [0,100],
});
export function normalizeOption(key, value) {
  const fallback = DEFAULTS[key];
  if (typeof fallback === 'boolean') return value === true || value === 1 || value === 'true' ? true : value === false || value === 0 || value === 'false' ? false : fallback;
  if (OPTION_RANGES[key]) {
    const n = typeof value === 'number' || (typeof value === 'string' && value.trim()) ? Number(value) : NaN;
    const [lo, hi] = OPTION_RANGES[key];
    return Number.isFinite(n) ? clamp(Math.round(n), lo, hi) : fallback;
  }
  if (key === 'quality') return ['good','average','poor'].includes(value) ? value : fallback;
  if (key === 'cameraMode') return ['first-person','third-person'].includes(value) ? value : fallback;
  if (key === 'resolution') {
    if (value === 'native') return value;   // the window as it is (an explicit choice; no longer the default)
    const m = typeof value === 'string' && /^(\d{3,5})x(\d{3,5})$/.exec(value);
    return m && Number(m[1]) >= 320 && Number(m[2]) >= 240 && Number(m[1]) <= 16384 && Number(m[2]) <= 16384 ? value : fallback;
  }
  if (key === 'chatColors') {
    if (!value || typeof value !== 'object' || Array.isArray(value)) return null;
    const colors = {};
    for (const type of ['normal','party','guild','officer','alliance','matching','world','shout','whisper','megaphone']) {
      if (typeof value[type] === 'string' && /^[a-f0-9]{6}$/i.test(value[type])) colors[type] = value[type];
    }
    return Object.keys(colors).length ? colors : null;
  }
  return fallback;
}
export function normalizeOptions(input) {
  return Object.fromEntries(Object.keys(DEFAULTS).map(key => [key, normalizeOption(key, input?.[key])]));
}
export const QUAKE_SCALE = [1.0, 0.7, 0.4, 0.2];

export class OptionStore extends Hub {
  constructor(game) {
    super();
    this.game = game;
    this.defaults = DEFAULTS;
    const saved = LS.load(KEY, null);
    this.values = normalizeOptions(saved);
    // the old HUD's settings (musicVolume/sfxVolume 0..1) seed the sound sliders the first time
    const s = game.settings || {};
    if (!saved) {
      if (Number.isFinite(Number(s.musicVolume))) this.values.bgm = Math.round(clamp(Number(s.musicVolume), 0, 1) * 100);
      if (Number.isFinite(Number(s.sfxVolume))) this.values.effect = Math.round(clamp(Number(s.sfxVolume), 0, 1) * 100);
      if (s.shadows === false) this.values.shadow = 0;
      if (s.pcShopSkipPriceCheck === true) this.values.priceMsg = false;
    }
  }
  get(k) { return this.values[k] ?? DEFAULTS[k]; }
  all() { return { ...this.values, chatColors: this.values.chatColors ? { ...this.values.chatColors } : null }; }
  /** Apply a patch: persist, then emit 'change' (patch, values) on the store and 'options' on game.events. */
  set(patch = {}) {
    const changed = {};
    for (const [k, raw] of Object.entries(patch && typeof patch === 'object' ? patch : {})) {
      if (!Object.hasOwn(DEFAULTS, k)) continue;
      const v = normalizeOption(k, raw);
      if (JSON.stringify(this.values[k]) === JSON.stringify(v)) continue;
      this.values[k] = v; changed[k] = v;
    }
    if (!Object.keys(changed).length) return changed;
    LS.save(KEY, this.values);
    this.emit('change', changed, this.values);
    this.game.events?.emit?.('options', { changed, values: this.values });
    return changed;
  }
  /** Back to the defaults (keeps nothing). */
  reset() { const d = { ...DEFAULTS }; this.set(d); }
}
