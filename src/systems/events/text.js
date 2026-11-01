// Event messages (docs/formats/events.md §2.7): every parsed client string is
//   {text, kind: 'message'|'dialog'|'effect', effectUi:[{id,a,ms,b}], sound:[{a,id}], effectSound:[{cat,id,vol,range}], gauge}
// and is played by Messenger.say():
//   text        -> the system chat line and the original centre event message (ui_eventmessagewnd.txt, 4 s)
//   effectUi    -> the full-screen UI effect banner (effectui.js, effectscene cate 8 id, shown for ms)
//   sound a=0   -> the scripted BGM cue: sound.json bgmByMapIndex[id] (e.g. 3001 = the Dead Front battle theme)
//   effectSound -> script/effect/soundscript.csv (cat, id, vol, range) -> effectscene.snd cate 4 -> sound.json effectSound
// Named tokens (<PARTYNAME>, <CHECKPOINT>, <NPC_NAME>, <PARTYNAMES>) and printf specs are filled from `vars`.
import { fetchCSV } from '../../engine/assets.js';
import { formatString } from '../../ui/uiwin/strings.js';

let soundScript = null;   // Promise<Map('cat,id,a,b' -> {effId, scene})>
function loadSoundScript() {
  if (!soundScript) {
    soundScript = fetchCSV('script/effect/soundscript.csv').then(rows => {
      const m = new Map();
      for (const r of rows.slice(1)) {
        const c = r.map(v => Number(String(v ?? '').trim()));
        if (!Number.isFinite(c[0]) || !Number.isFinite(c[4])) continue;
        m.set(`${c[0]},${c[1]},${c[2]},${c[3]}`, { effId: c[4], scene: c[5] || 1 });
        if (!m.has(`${c[0]},${c[1]}`)) m.set(`${c[0]},${c[1]}`, { effId: c[4], scene: c[5] || 1 });
      }
      return m;
    }).catch(() => new Map());
  }
  return soundScript;
}

/** Fill printf specs and named tokens. */
export function fill(text, vars = null, args = []) {
  let s = String(text ?? '');
  if (args?.length) s = formatString(s, ...args);
  if (vars) s = s.replace(/<([A-Z_][A-Z_0-9]*)>/g, (m, k) => (k in vars ? String(vars[k]) : m));
  // the English map tables write the party placeholder out: "(conquering party name)", "(name of occupied team)"
  if (vars?.PARTYNAME) s = s.replace(/\((?:name of [a-z ]*?(?:party|team)|[a-z ]*?(?:party|team) name)\)/gi, String(vars.PARTYNAME));
  return s;
}

/** Strip client colour markup for plain chat lines. */
export function plain(text) {
  return String(text ?? '').replace(/<\/?color[^>]*>/gi, '').replace(/<\/?font[^>]*>/gi, '').replace(/<#[0-9a-f]{6}>/gi, '');
}

/** A system chat line; never throws (the HUD / chat owner may be mid-reload). */
export function hudLog(game, text, kind = 'sys') {
  try { game?.hud?.log?.(text, kind); } catch (err) {
    if (!hudLog._warned) { hudLog._warned = true; console.warn('[events] hud.log failed', err); }
    try { console.info(`[${kind}] ${text}`); } catch { /* ignore */ }
  }
}

export class Messenger {
  constructor(game, sys) {
    this.game = game;
    this.sys = sys;          // events system (effect banners, event message window)
    this.lastBgm = null;
  }

  /**
   * Play a parsed string. opts: { vars, args, at: FILE point for effect sounds, chat: false, notice: false,
   * kind: override }.
   */
  say(entry, opts = {}) {
    if (!entry) return;
    if (typeof entry === 'string') entry = { text: entry, kind: 'message' };
    const text = entry.text ? fill(entry.text, opts.vars, opts.args) : '';
    const kind = opts.kind || entry.kind;
    if (text) {
      if (opts.chat !== false) {
        for (const line of plain(text).split('\n')) if (line.trim()) hudLog(this.game, line, 'sys');
      }
      if (opts.notice !== false && kind !== 'dialog-silent') this.sys.notice?.(text);
    }
    for (const e of entry.effectUi || []) this.sys.banner?.(e.id, e.ms);
    for (const s of entry.sound || []) this.cue(s);
    for (const s of entry.effectSound || []) this.effectSound(s, opts.at);
  }

  /** `@<sound>a,id` : a = 0 switches the BGM to sound.json bgmByMapIndex[id]. */
  cue(s) {
    if (!s) return;
    const id = Number(s.id);
    if (Number(s.a) === 0 && Number.isFinite(id)) {
      const list = this.game.data?.sound?.bgmByMapIndex?.[String(id)];
      if (list?.length) { this.lastBgm = id; try { this.game.audio?.playBGM?.(id); } catch { /* audio optional */ } }
    }
  }

  /** `@<effectsound>cat,id,a,b` -> soundscript row -> effectSound[4][effId].scenes[scene]. */
  async effectSound(s, at = null) {
    if (!s) return;
    const map = await loadSoundScript();
    const row = map.get(`${s.cat},${s.id},${s.vol ?? 0},${s.range ?? 0}`) || map.get(`${s.cat},${s.id}`);
    if (!row) return;
    const S = this.game.data?.sound;
    const eff = S?.effectSound?.['4']?.[String(row.effId)];
    const list = eff?.scenes?.[String(row.scene)] || eff?.scenes?.['1'];
    if (Array.isArray(list)) this.game.audio?.playAll?.(list, { at });
  }

  /** Play a soundscript code directly (22 = system / dungeon sounds). */
  code(cat, id, a = 0, b = 0, at = null) { return this.effectSound({ cat, id, vol: a, range: b }, at); }
}
