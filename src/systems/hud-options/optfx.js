// Option behaviours that reach into other systems through hooks (no edits in their files). Each option of the Option
// window drives something real; the ones listed here are those whose effect lives outside the HUD:
//
//   blood        Blood Effect [Require Re-login]: the blood splash of modeleffect 21 (code 0, blood type 1..8 of
//                monster.dat BloodInfo = monsters.json flags[4] -> effect 6:91..98) + the blood sound (4:905) on every
//                landed hit on a monster. As the caption says, the value read at login is the one in force.
//   effectView   Skill Effect Display Setting: 0 all users, 1 own only, 2 none -> skill effects (cate 100) owned by a
//                player character, its summons, or a ground point cast by it are dropped (monster skills stay).
//                Single player: "own only" = all (there are no other players).
//   quake        Screen Shake Effect off = no skill camera quakes either; Display shaking effect scales them.
//   trace        Trace Effect (trace.js).   swimming / reflectTile: Water Effect, Tile Reflection Effect (waterfx.js).
//   smartwarp    Smart Warp: the smart warp alarm button (dungeons system window 'smartwarp_alarm') shown / hidden.
//   dropMsg      Item/DIL Drop Warning Message <-> the items system's discard confirmation (settings.skipDiscardConfirm,
//                also set by the confirmation's own "Do not show this again").
//   sortMsg      Inventory/Stash Sort Warning Message: the sort confirmation (string 260:43) is skipped when off.
//   showCostume / showWing   Display Costume Look / wings -> the mounts system's costume and wing visuals.
//   selfTarget   Auto Self Target: an ally / self skill cast without a friendly target selects your own character.
//   captionBar   Window title bar colour: the browser's title bar colour (theme-color) = the client's caption bar
//                art (captionbar#0 "Brightly", the dark button set captionbar#8.. "Darkly").
import { QUAKE_SCALE } from './settings.js';
import { WeaponTraces } from './trace.js';
import { WaterFx } from './waterfx.js';
import { saveSettings } from '../../game/save.js';
import { atlas } from '../../ui/atlas.js';
import { str, plainText, clamp, npcNameFix } from './util.js';

const T_ALLY = 2, T_ENEMY = 4, T_SELF = 16;

export class OptionHooks {
  constructor(game, ctx) {
    this.game = game;
    this.ctx = ctx;
    this.O = ctx.options;
    this.bloodOn = !!this.O.get('blood');           // "[Require Re-login]"
    this.lastSkillAt = -1e9;
    this.traces = new WeaponTraces(game, ctx);
    this.water = new WaterFx(game, ctx);
    this._t = 0;
    this._wrapMsgbox();
    this._wrapNamePlates();
    this._events();
    this.O.on('change', (patch) => this._apply(patch));
    this._apply(null);
  }

  // ------------------------------------------------------------------ option changes
  _apply(patch) {
    const has = k => !patch || k in patch;
    const g = this.game;
    if (has('reflectTile')) this.water.applyFloors();
    if (has('captionBar')) this._caption();
    if (has('dropMsg') && g.settings) {
      const skip = !this.O.get('dropMsg');
      if (!!g.settings.skipDiscardConfirm !== skip) { g.settings.skipDiscardConfirm = skip; try { saveSettings(g.settings); } catch { /* storage */ } }
    }
    if (has('showCostume') && g.mounts?.setCostumeShown && g.mounts.costumeShown !== !!this.O.get('showCostume')) g.mounts.setCostumeShown(!!this.O.get('showCostume'));
    if (has('showWing')) { const w = g.mounts?.system?.wings; if (w) w.hidden = !this.O.get('showWing'); }
    if (has('smartwarp')) this._smartwarp();
    if (has('trace') && !Number(this.O.get('trace'))) this.traces.clear();
    if (has('swimming') && !this.O.get('swimming')) this.water.clearFx();
  }

  // ------------------------------------------------------------------ per frame
  update(dt) {
    this._hookEffects();
    this.traces.update(dt);
    this.water.update(dt);
    this._t -= dt;
    if (this._t > 0) return;
    this._t = 0.5;
    const g = this.game;
    // the discard confirmation's "Do not show this again" unticks the option
    if (g.settings?.skipDiscardConfirm && this.O.get('dropMsg')) this.O.set({ dropMsg: false });
    this._smartwarp();
    const w = g.mounts?.system?.wings;
    if (w && w.hidden !== !this.O.get('showWing')) w.hidden = !this.O.get('showWing');
  }

  _smartwarp() {
    const w = this.game.uiwin?.window?.('smartwarp_alarm');
    if (!w?.root?.el) return;
    const vis = this.O.get('smartwarp') !== false ? '' : 'hidden';
    if (w.root.el.style.visibility !== vis) w.root.el.style.visibility = vis;
  }

  // ------------------------------------------------------------------ effects: filter, quakes, blood
  _hookEffects() {
    const fx = this.game.effects;
    if (!fx || fx._hoHooked) return;
    fx._hoHooked = true;
    const origPlay = fx.play.bind(fx);
    fx.play = (owner, ref, opts = {}) => {
      if (this._hideSkillFx(owner, ref)) return null;
      return origPlay(owner, ref, opts);
    };
    if (typeof fx.addQuake === 'function') {
      const origQuake = fx.addQuake.bind(fx);
      fx.addQuake = (q) => {
        if (!this.O.get('quake')) return;
        const k = QUAKE_SCALE[clamp(Number(this.O.get('quakeOption')) || 0, 0, 3)];
        if (q && Number.isFinite(q.amp)) q.amp *= k;
        return origQuake(q);
      };
    }
  }
  _hideSkillFx(owner, ref) {
    const v = Number(this.O.get('effectView')) || 0;
    if (v === 0 || !ref || Number(ref.cate ?? 100) !== 100) return false;
    const p = this.game.player;
    if (!owner || !p) return false;
    if (v === 1) {
      // Own-only keeps the local body and its owned summons while suppressing remote players.
      // Unattributed ground anchors and monster effects remain visible: guessing ownership could hide hazards.
      const source = owner.owner || owner.master || owner.summoner || owner;
      return source !== p && source.kind === 'player';
    }
    if (owner === p || owner.kind === 'player') return true;
    if (owner.owner === p || owner.master === p || owner.summoner === p || owner.kind === 'servant' || owner.kind === 'pet') return true;
    // a ground point / projectile anchor: hidden while the player's skill is running
    const isActor = !!(owner.group || owner.instance || owner.kind);
    return !isActor && (this.game.time || 0) - this.lastSkillAt < 3;
  }

  _events() {
    const g = this.game, ev = g.events;
    if (!ev) return;
    ev.on('map', () => { this.traces.clear(); this.water.onMap(); });
    if (g.world) this.water.onMap();
    ev.on('skill', ({ actor, skill } = {}) => {
      if (actor !== g.player) return;
      this.lastSkillAt = g.time || 0;
      // Auto Self Target
      if (!this.O.get('selfTarget') || !skill) return;
      const mask = Number(skill.targetMask) || (skill.target || []).reduce((a, b) => a | Number(b), 0);
      if (!(mask & (T_ALLY | T_SELF)) || (mask & T_ENEMY)) return;
      const p = g.player, t = p.target;
      if (t && t !== p && (t.kind === 'player' || t.kind === 'servant')) return;
      try { t?.setHighlight?.(false); } catch { /* ignore */ }
      p.target = p;
      ev.emit('target', { actor: p });
    });
    ev.on('damage', (e) => this._blood(e));
    ev.on('costume', ({ shown } = {}) => { if (shown != null && !!shown !== !!this.O.get('showCostume')) this.O.set({ showCostume: !!shown }); });
  }

  _blood(e) {
    if (!this.bloodOn || !e?.target || e.miss || e.dot || !(e.amount > 0)) return;
    const t = e.target, fx = this.game.effects;
    if (t.kind !== 'monster' || !fx) return;
    const b = Number((t.def?.flags || [])[4]) || 0;
    if (b < 1 || b > 8) return;
    const rows = fx.data?.modelEffects?.combat || [];
    const find = (a, bb, c) => rows.find(r => r.code?.[0] === a && r.code?.[1] === bb && r.code?.[2] === c)?.effect || null;
    const splash = find(0, b, 0);
    if (splash) fx.play(t, splash, { bone: 'body_u' });
    const snd = find(0, 0, Math.floor(Math.random() * 3));
    if (snd) fx.play(t, snd, {});
  }

  // ------------------------------------------------------------------ message boxes the options suppress
  _wrapMsgbox() {
    const mgr = this.game.uiwin;
    if (!mgr || mgr._hoMsg) return;
    mgr._hoMsg = true;
    const orig = mgr.msgbox.bind(mgr);
    mgr.msgbox = (text, opts = {}) => {
      const t = plainText(String(text ?? ''));
      const sortWarn = plainText(str(260, 43)).trim();
      if (!this.O.get('sortMsg') && sortWarn && t.includes(sortWarn)) return Promise.resolve(opts.kind === 'ok' ? 'ok' : 'yes');
      return orig(text, opts);
    };
  }

  // ------------------------------------------------------------------ the old HUD's name plates
  _wrapNamePlates() {
    const h = this.game.hud;
    if (!h || typeof h._npcPlateText !== 'function' || h._hoPlate) return;
    h._hoPlate = true;
    const orig = h._npcPlateText.bind(h);
    h._npcPlateText = (a, pl) => {
      orig(a, pl);
      if (!pl?.name) return;
      const fixed = npcNameFix({ name: pl.name.textContent, title: String(pl.title?.textContent || '').replace(/^<|>$/g, '') }, a?.name);
      if (fixed.name !== pl.name.textContent) pl.name.textContent = fixed.name;
      const tt = fixed.title || '';
      if (pl.title && pl.title.textContent !== tt) pl.title.textContent = tt;
    };
  }

  // ------------------------------------------------------------------ caption bar colour -> theme-color
  async _caption() {
    const dark = Number(this.O.get('captionBar')) === 1;
    let color = dark ? '#1c1a17' : '#a8a08e';
    try {
      const s = await atlas.sprite('captionbar', dark ? 8 : 0);
      if (s?.url) color = await averageColor(s.url) || color;
    } catch { /* keep the fallback */ }
    let m = document.querySelector('meta[name="theme-color"]');
    if (!m) { m = document.createElement('meta'); m.name = 'theme-color'; document.head.appendChild(m); }
    m.content = color;
  }

  dispose() { this.traces.dispose(); this.water.dispose(); }
}

function averageColor(url) {
  return new Promise((res) => {
    const im = new Image();
    im.onload = () => {
      try {
        const c = document.createElement('canvas');
        c.width = 16; c.height = 4;
        const g = c.getContext('2d');
        g.drawImage(im, 0, 0, 16, 4);
        const d = g.getImageData(0, 0, 16, 4).data;
        let r = 0, gg = 0, b = 0, n = 0;
        for (let i = 0; i < d.length; i += 4) { if (d[i + 3] < 16) continue; r += d[i]; gg += d[i + 1]; b += d[i + 2]; n++; }
        if (!n) { res(null); return; }
        const hex = v => Math.round(v / n).toString(16).padStart(2, '0');
        res(`#${hex(r)}${hex(gg)}${hex(b)}`);
      } catch { res(null); }
    };
    im.onerror = () => res(null);
    im.src = url;
  });
}
