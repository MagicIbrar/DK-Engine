// Emotes / motions, sit & stand, costume motions and interactive actions (levers).
//
// Data: the class action table (share/action/action/pc/<cls>.act.0.dat, style 0): MOTION 10..27 = the emotes,
// MOTION 100/101 = lever ready / pull (script/interactiveaction), MOTION 700..702 = costume motions
// (script/cosmotion/cosmotion.csv: MotionIndex, Class, SubType, ItemID = the costume that unlocks it),
// EMOTIONSTART / EMOTIONKEEP / EMOTIONEND = sit down / sitting loop / stand up. life.json classMotions.
// Names and chat commands: string table stringtable_emoticon.txt: NORMAL 50:1..21 = emote names, 50:4001..4021 =
// the chat commands of each ("/hi /hello /greeting"). Emote id k (1..21) -> MOTION 9 + k for k 1..17, 18 = sit,
// 19 = stand, 20 = MOTION 27 (apology), 21 = the equipped costume's motion.
// Sounds: sound.json emote[class][motion index] (soundscript code1 23).
// UI: the live client lists the emotes in the chat window's action combobox (emoteList()); the old tabbed
// game2/charwindow/ui_emotionwnd.txt references art that no longer exists in this client, so it is not used.
// Keymap actions 1001..1015 (Express Emotion) call playMotion(motion) (1 = sit toggle).
// Moving, attacking or using a skill cancels an emote (the controller plays its own state); sitting ends the same
// way, or with /stand (the stand-up motion).
import { resetAnimState } from '../../game/combat.js';
import { str, strNow, registerChat, equippedWeapon, wornItems } from './common.js';

const EMOTE_NAME_CATE = 50;
/** ENGINE-CHOSEN refusal lines (the client's string tables have no emote refusal text; see Emotes._refuse). */
const REFUSAL_TEXT = {
  dead: 'You cannot use emotes while dead.',
  fishing: 'You cannot use emotes while fishing.',
  casting: 'You cannot use emotes while using a skill.',
  riding: 'You cannot use emotes while riding.',
  shop: 'The shop is in operation.',   // native 180:3 (stringtable_auction): the host refuses every emote while the seller's shop is open
};
const REFUSAL_REPEAT_MS = 1500;   // ENGINE-CHOSEN: do not spam the same line when a key is held / clicked repeatedly
/** emote id (string 50:id) -> motion index (or 'sit' / 'stand' / 'costume') */
export function emoteMotion(id) {
  id = Number(id);
  if (id >= 1 && id <= 17) return 9 + id;
  if (id === 18) return 'sit';
  if (id === 19) return 'stand';
  if (id === 20) return 27;
  if (id === 21) return 'costume';
  return null;
}

export class Emotes {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.D = life.data;
    this.cmds = new Map();          // '/hi' -> emote id
    this.cur = null;                // { kind: 'emote'|'sit', motion, state }
  }

  get classIndex() { return Number(this.game.save?.classIndex) || 0; }
  get motions() { return this.D?.classMotions?.[this.classIndex] || { motions: {}, emotion: {} }; }

  async install() {
    const g = this.game;
    // chat commands from the emoticon string table
    const S = g.uiwin?.strings;
    if (S) {
      for (let id = 1; id <= 21; id++) {
        const line = await str(g, EMOTE_NAME_CATE, 4000 + id);
        for (const c of String(line || '').split(/\s+/)) if (c.startsWith('/')) this.cmds.set(c.toLowerCase(), id);
      }
      // the older per-slot commands (51:n) as aliases
      for (let n = 1; n <= 70; n++) { const c = strNow(g, 51, n) || await str(g, 51, n); if (c && c.startsWith('/') && !this.cmds.has(c.toLowerCase())) this.cmds.set(c.toLowerCase(), this._legacyId(c)); }
    }
    registerChat(g, (text) => this._chat(text));
    // NOTE: game2/charwindow/ui_emotionwnd.txt is a stale window of this client (its art groups `Skill` and
    // `motion` are not in script/ui/com/imagetable.txt: 65 of 65 sprites missing). The live client lists the
    // emotes in the chat window (game2/chat/ui_chatwnd.txt btn_action -> com_action_1/2 comboboxes, owned by the
    // chat/HUD system), which should fill its combobox from emoteList() and call emote(id).
    for (let id = 1; id <= 21; id++) await str(g, EMOTE_NAME_CATE, id);
  }

  /** The emote list of the chat window's action combobox: [{id, name, motion, commands, available}]. */
  emoteList() {
    const out = [];
    for (let id = 1; id <= 21; id++) {
      const m = emoteMotion(id);
      const available = m === 'sit' || m === 'stand' ? !!this.motions.emotion?.EMOTIONSTART : m === 'costume' ? true : !!this.motions.motions?.[m];
      out.push({ id, name: strNow(this.game, EMOTE_NAME_CATE, id), motion: m, commands: [...this.cmds].filter(([, v]) => v === id).map(([k]) => k), available });
    }
    return out;
  }

  _legacyId(cmd) {
    const map = { '/hi': 1, '/thanks': 2, '/sit': 18, '/stand': 19, '/surrender': 14, '/standby': 6, '/oh': 7, '/clap': 8, '/cry': 9, '/dance': 10,
      '/smile': 11, '/stretch': 12, '/despair': 15, '/angry': 16, '/taunt': 17, '/appology': 20, '/costume': 21 };
    return map[String(cmd).toLowerCase()] || null;
  }

  _chat(text) {
    const t = String(text || '').trim().toLowerCase();
    if (!t.startsWith('/')) return false;
    const id = this.cmds.get(t.split(/\s+/)[0]);
    if (!id) return false;
    this.emote(id);
    return true;
  }

  // ---------------------------------------------------------------------------------------- playing
  /** Why the player cannot emote now: 'dead' | 'fishing' | 'casting' | 'riding', or null when it can. */
  _refusal() {
    const p = this.game.player;
    if (!p) return 'none';
    if (p.dead) return 'dead';
    if (this.life.fishing?.active) return 'fishing';
    if (this.game.skills?.busy) return 'casting';
    if (this.game.mounts?.riding || p.mounted) return 'riding';
    return null;
  }

  /** Can the player emote now? (not dead, not fishing, not mounted, not casting) */
  _canAct() { return this._refusal() === null; }
  /** An open Personal Shop holds its seller seated (server/world/pcshop.mjs refuses emotes, 180:3); only host pose calls ({server:true}) change it. */
  _shopHeld() { return this.game.network?.pcShop?.open === true; }

  /**
   * A refused emote must not fail silently (it used to do nothing): post a system chat line saying why.
   * ENGINE-CHOSEN wording: the client string tables (script/string/**) have no emote-specific refusal text (checked
   * stringtable_emoticon, _chat, _inven "Cannot change presets while mounted/fishing/using a skill", _pc, _vehicle), so
   * these lines follow the wording pattern of those client messages. The same reason is not repeated within 1.5 s.
   */
  _refuse(reason = this._refusal(), { quiet = false } = {}) {
    const text = REFUSAL_TEXT[reason];
    if (quiet || !text) return false;
    const now = Date.now(), last = this.lastRefusal;
    if (last && last.reason === reason && now - last.at < REFUSAL_REPEAT_MS) return false;
    this.lastRefusal = { reason, text, at: now };
    try { this.game.chat?.system?.(text, 'err'); } catch (err) { console.warn('[emotes] refusal notice', err); }
    return false;
  }

  /** Play emote id 1..21 (string 50:id). */
  emote(id) {
    const m = emoteMotion(id);
    if (m == null) return false;
    if (this._shopHeld()) return this._refuse('shop');
    if (m === 'sit') return this.sit();
    if (m === 'stand') return this.stand();
    if (m === 'costume') return this.costume();
    return this.playMotion(m);
  }

  /** Play MOTION index m of the class action table. */
  playMotion(m, { onEnd = null, loop = false, face = null, quiet = false } = {}) {
    m = Number(m);
    if (this._shopHeld()) return this._refuse('shop', { quiet });
    if (m === 1 || m === 12 || m === 14) return this.sitting ? this.stand() : this.sit();   // sit slot / key "Sit" toggles
    if (m === 13) return this.stand();
    if (!this._canAct()) return this._refuse(undefined, { quiet });
    const rec = this.motions.motions?.[m];
    if (!rec) return false;
    const p = this.game.player;
    this._calm(p);
    this.game.controller?.stop?.();
    if (face != null) p.yaw = face;
    const state = `motion${m}`;
    this.cur = { kind: 'emote', motion: m, state };
    p.play(state, {
      anim: rec.anim, timeLength: rec.t, loop, fade: 0.15,
      onEnd: () => { if (this.cur?.state === state) this._end(); onEnd?.(); },
    });
    this._sound(m);
    this.game.events?.emit?.('life:emote', { motion: m });
    this._share(m);
    return true;
  }

  /** Online: the host shows the motion to the map (server/world/emotes.mjs). */
  _share(motion) {
    const n = this.game.network;
    if (n?.active && n.ready && typeof n.action === 'function') void Promise.resolve(n.action('emote', { motion })).catch(() => {});
  }

  /** Another player's motion (host `emote` event / `sitting` row): played on that player's own class table. */
  playRemote(actor, motion) {
    if (!actor || actor.dead || actor === this.game.player) return false;
    const cls = Number(actor.classDef?.index ?? actor.save?.classIndex) || 0;
    const T = this.D?.classMotions?.[cls] || { motions: {}, emotion: {} };
    const now = performance.now(), E = T.emotion || {};
    if (motion === 'sit') {
      actor._remoteSit = true; actor._networkAnimHold = Infinity;
      const keep = () => { if (actor._remoteSit && E.EMOTIONKEEP) actor.play('sit', { anim: E.EMOTIONKEEP.anim, timeLength: E.EMOTIONKEEP.t, loop: true, fade: 0.1 }); };
      if (E.EMOTIONSTART) actor.play('sitdown', { anim: E.EMOTIONSTART.anim, timeLength: E.EMOTIONSTART.t, loop: false, fade: 0.15, onEnd: keep }); else keep();
      return true;
    }
    if (motion === 'sit-keep') {   // already sitting when first seen (snapshot of a player that sat before)
      actor._remoteSit = true; actor._networkAnimHold = Infinity;
      if (E.EMOTIONKEEP) actor.play('sit', { anim: E.EMOTIONKEEP.anim, timeLength: E.EMOTIONKEEP.t, loop: true, fade: 0.1 });
      return true;
    }
    if (motion === 'stand') {
      actor._remoteSit = false;
      actor._networkAnimHold = now + (E.EMOTIONEND ? E.EMOTIONEND.t * 1000 : 0);
      if (E.EMOTIONEND) actor.play('standup', { anim: E.EMOTIONEND.anim, timeLength: E.EMOTIONEND.t, loop: false, fade: 0.1 });
      return true;
    }
    const rec = T.motions?.[Number(motion)];
    if (!rec) return false;
    actor._remoteSit = false;
    actor._networkAnimHold = now + rec.t * 1000;
    actor.play(`motion${motion}`, { anim: rec.anim, timeLength: rec.t, loop: false, fade: 0.15 });
    return true;
  }

  sit({ server = false } = {}) {
    if (!this._canAct()) return this._refuse();
    if (!server && this._shopHeld()) return this._refuse('shop');
    if (this.cur?.kind === 'sit') return true;
    const E = this.motions.emotion || {};
    const start = E.EMOTIONSTART, keep = E.EMOTIONKEEP;
    if (!start && !keep) return false;
    const p = this.game.player;
    this._calm(p);
    if (!server) this.game.controller?.stop?.();
    this.cur = { kind: 'sit', state: 'sitdown', server };
    const toKeep = () => { if (this.cur?.kind !== 'sit') return; this.cur.state = 'sit'; if (keep) p.play('sit', { anim: keep.anim, timeLength: keep.t, loop: true, fade: 0.1 }); };
    if (start) p.play('sitdown', { anim: start.anim, timeLength: start.t, loop: false, fade: 0.15, onEnd: toKeep });
    else toKeep();
    this._sound(12);
    this.game.events?.emit?.('life:sit', { sitting: true });
    if (!server) this._share('sit');
    return true;
  }

  stand({ server = false } = {}) {
    const p = this.game.player;
    if (!server && this._shopHeld()) return this._refuse('shop');
    if (this.cur?.kind !== 'sit' || !p) return false;
    const end = this.motions.emotion?.EMOTIONEND;
    this.cur = { kind: 'emote', state: 'standup', motion: 13 };
    if (end) p.play('standup', { anim: end.anim, timeLength: end.t, loop: false, fade: 0.1, onEnd: () => { if (this.cur?.state === 'standup') this._end(); } });
    else this._end();
    this.game.events?.emit?.('life:sit', { sitting: false });
    if (!server) this._share('stand');
    return true;
  }

  get sitting() { return this.cur?.kind === 'sit'; }

  /** /costume: the motion of the equipped costume (cosmotion.csv). */
  costume() {
    const cls = this.classIndex;
    const worn = wornItems(this.game);
    const w = equippedWeapon(this.game); if (w) worn.add(w);
    const row = (this.D?.cosmotion || []).find((r) => r.cls === cls && worn.has(r.item));
    if (!row) return false;          // no costume with a motion worn: the client does nothing
    return this.playMotion(row.motion);
  }

  /**
   * Interactive action (script/interactiveaction/triggerinteractiveaction.csv): face `dir` degrees and play the
   * trigger's motion chain (100 lever ready -> 101 lever pull). Resolves when the last motion ends.
   */
  interact(triggerIndex) {
    const row = (this.D?.interactive || []).find((r) => r.trigger === Number(triggerIndex));
    const chain = row ? row.actions : [100, 101];
    const yaw = row ? (row.dir * Math.PI) / 180 : null;
    return new Promise((resolve) => {
      const step = (i) => {
        if (i >= chain.length) { resolve(true); this.game.events?.emit?.('life:interact', { trigger: triggerIndex, interaction: row?.interaction }); return; }
        const ok = this.playMotion(chain[i], { face: i === 0 ? yaw : null, quiet: true, onEnd: () => step(i + 1) });   // a lever is not an emote: no emote refusal line
        if (!ok) resolve(false);
      };
      step(0);
    });
  }

  /**
   * Leave the battle stance for the motion: the controller keeps the peace idle it tracks (_gpState) and does not
   * replace the motion when the stance timer runs out.
   */
  _calm(p) {
    if (!p) return;
    p.lastCombat = null;
    // Track the stand the controller itself would request (controller._idle: 'idleCombat' while p.inBattle() - any equipped
    // weapon keeps the battle stand - else 'idle'). Tracking 'idle' for an armed player made the controller's next
    // playLoop('idleCombat') replace the motion 2 ms after it started and emotes.update() then cancelled it: every emote
    // and /sit of a character with a weapon did nothing (measured in the real client, GM fixture: motion10 -> idleCombat
    // 2 ms later -> emotes.cancel). Unarmed characters (peace stand) were never affected.
    p._gpState = (typeof p.inBattle === 'function' ? p.inBattle() : false) ? 'idleCombat' : 'idle';
    p._gpHold = 0;
  }

  _sound(m) {
    const list = this.game.data?.sound?.emote?.[String(this.classIndex)]?.[String(m)];
    if (Array.isArray(list) && list.length) this.game.audio?.playAll?.(list, { at: { x: this.game.player.x, z: this.game.player.z } });
  }

  _end() {
    const p = this.game.player;
    this.cur = null;
    if (!p || p.dead) return;
    resetAnimState(p);         // the controller re-issues idle next frame
  }

  /** Cancel the current emote/sit without a motion (movement, combat, fishing). */
  cancel() { if (this.cur) { const was = this.cur.kind; this.cur = null; if (was === 'sit') this.game.events?.emit?.('life:sit', { sitting: false }); } }

  update() {
    const p = this.game.player;
    if (!this.cur || !p) return;
    // another module played a different state (movement, attack, hit, skill, death): the emote is over
    const mine = this.cur.kind === 'sit' ? ['sitdown', 'sit'] : [this.cur.state];
    if (!mine.includes(p.state)) this.cancel();
  }
}
