// The client options (script/ui/game2/option/ui_optionwnd.txt, every tab), their defaults, persistence and the
// real behaviour each one drives. game.options = this store:
//   get(key) / all() / set(patch) (applies + persists + emits 'options' on game.events) / defaults / on('change', fn)
// Other systems read the options that belong to them (e.g. blockTrade, smartwarp, autoRevive) with game.options.get().
//
// Keys follow the option window's control ids (check_cloud -> cloud, sld_sound -> bgm ...). Sliders keep the
// script's own ranges (0..100, bloom 0..2, chat alpha 0..255).
import { LS, Hub, clamp } from './util.js';

const KEY = 'dekaron-solo:options:v1';

export const DEFAULTS = Object.freeze({
  // ---- Graphics (pan_screen)
  quality: 'good',          // btn_levelgood | btn_levelaverage | btn_levelpoor preset
  gamma: 50,                // sld_gamma 0..100 (50 = neutral)
  resolution: '1024x768',   // com_display: 'native' (window as it is) or 'WxH'; default = Global data/shadow.txt [init] display_width 1024 / display_height 768
  winmode: true,            // check_winmode (unchecked = full screen)
  cloud: true, specular: true, bump: true, blood: true, quake: true, bloom: true,
  swimming: true, reflectTile: true, smartwarp: true,
  bloomLevel: 1,            // sld_bloom 0..2
  trace: 2,                 // com_trace: 0 N/A, 1 Character, 2 All
  shadow: 2,                // com_shadow: 0 Low, 1 Middle, 2 High, 3 Highest
  water: 2,                 // com_water: 0 Low, 1 Middle, 2 High
  bgFrame: 1,               // com_background_frame: 15 / 30 / 60 fps while the window is in the background
  frameLimit: 0,            // com_frame_limit: 0 Unlimited, 60, 75, 120, 144, 165, 200, 240, 300 Hz
  quakeOption: 1,           // com_quake_option: 0 Strong, 1 Medium, 2 Weak, 3 Very weak
  // ---- Sound (pan_sound)
  mp3: false,
  bgm: 50, bgmMute: false,
  ambient: 70, ambientMute: false,
  skillSound: 80, skillSoundMute: false,
  servant: 80, servantMute: false,
  effect: 70, effectMute: false,
  // ---- Game (pan_game)
  blockTrade: false, blockParty: false, blockGuild: false, blockFriend: false, blockPvp: false, blockPartyPvp: false,
  blockAlliance: false, rejectRevive: false,
  partyUiOpen: false, // Global43.8.0: reveal party status on channel change; preserve prior hidden-state default.
  stackQuestReward: true, dropMsg: true, runeMsg: true, priceMsg: true, sortMsg: true, presetMsg: true,
  presetBlinkIcon: true, presetCallPet: false,
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
  autoPotion: false, hpLimit: 50, mpLimit: 30, autoRevive: false,
  // ---- Chatting (pan_chat) + chat option window
  chatOnTop: false, chatMovable: false, chatExtra: false,
  chatAlpha: 128, chatSize: 3, chatFont: 2, sysAlpha: 128, sysSize: 3,
  chatType: 0,
  chatNormal: true, chatWorldMatch: true, chatParty: true, chatGuild: true, chatShout: true, chatWhisper: true,
  chatOfficer: true, chatAlliance: true, chatWorld: true,
  chatColors: null,         // {type: 'RRGGBB'} overrides (select-colour window)
  chatVisible: true,        // Ctrl+C (View/Hide Chat)
  // ---- HUD layout state (quick slot rows etc. live in the character save)
  minimapZoom: 0,           // 0 normal, 1 "bigmap" (+)
  minimapHidden: false,
  mapAlpha: 100,            // world map transparency slider
});

// Retained preferences whose gameplay adapters are not implemented in this client.
export const UNIMPLEMENTED_OPTIONS = Object.freeze(['chatExtra']);

/** Graphics quality presets (btn_levelgood/average/poor) -> the options they set. */
export const QUALITY = {
  good: { shadow: 2, water: 2, trace: 2, cloud: true, specular: true, bump: true, reflectTile: true, swimming: true },
  average: { shadow: 1, water: 1, trace: 1, cloud: true, specular: true, bump: false, reflectTile: false, swimming: true },
  poor: { shadow: 0, water: 0, trace: 0, cloud: false, specular: false, bump: false, reflectTile: false, swimming: false, bloom: false },
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
  return FRAME_LIMITS[clamp(Math.round(Number(frameLimitIndex) || 0), 0, FRAME_LIMITS.length - 1)];
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
