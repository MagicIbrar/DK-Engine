// Character name change + guild name change: the original item windows. Using a Type 0 Code 23 item (Change Character Name /
// New Name Seed) or a Type 0 Code 80 item (Guild Name Change) runs these flows; every rule and data source: namechange-rules.js.
//   character: refusal box (msgbox/ui_changecharnameerror.txt, 170:40..44) when a 170:10 condition fails -> name entry
//     (changecharname/ui_changecharnamewnd.txt: 170:6 current name/level/class, 170:8, edt_name maxlength 20, red lbl_failmsg)
//     -> "New Character Name" confirm (msgbox/ui_changecharnameconfirm.txt: 170:10 + 170:6 with the new name) -> caution
//     (msgbox/ui_changecharnamecaution.txt: 170:10 + 170:11 with the new name, "You will be redirected to the Character
//     Selection screen") -> the host renames (server/world/name-change.mjs, one write with the spent item) -> character select.
//   guild: guild master only (130:23 / 130:315) -> name entry (changeguildname/ui_changeguildnamewnd.txt: 170:88 current guild
//     name, 170:89, edt_name maxlength 20) -> confirm (msgbox/ui_changeguildnameconfirm.txt: 130:310, the new name, 130:318)
//     -> the host's guild 'rename' operation (server/world/guilds.mjs, spends the item in the same social transaction).
// The ORDER of the three character windows is not in the data (the scripts are separate files); it follows their texts: the
// confirm names the new character, the caution announces the redirect. The friend list is client-held (life/friends.js),
// so its condition (170:41) is checked here; party / expedition / guild are checked again by the host.
import { randomUUID } from '../network/web-crypto.js';
import { fetchText } from '../../engine/assets.js';
import { SCRIPTS, NAME_STRINGS, NAME_TEXT, isCharNameItem, isGuildNameItem, isGuildMistakeItem, GUILD_NAME_CHANGES_MAX, charNameBlocker, checkNewCharacterName, checkNewGuildName, fillName } from './namechange-rules.js';

const ref = ([cate, code]) => ({ group: 'NORMAL', cate, code });

export class NameChange {
  constructor(game) { this.game = game; this._filter = null; this.busy = false; }

  async install() {
    const g = this.game;
    g.nameChange = this;
    try { await g.uiwin?.strings?.need?.(Object.values(NAME_STRINGS).map(ref)); } catch { /* strings load lazily */ }
  }

  /** Item-use entry (items/use.js offline, network/items.js online). Returns false: the item is spent only by the rename. */
  use(item, def) {
    if (isCharNameItem(def)) void this.character(item);
    else if (isGuildNameItem(def)) void this.guild(item);
    else if (isGuildMistakeItem(def)) void this.guildReset(item);
    else return false;
    return true;
  }

  get online() { return this.game.save?.authority === 'server' && !!this.game.network; }
  text(key, fallback = '') { return this.game.uiwin?.strings?.get?.(ref(NAME_STRINGS[key])) ?? NAME_TEXT[key] ?? fallback; }

  filterWords() {
    // script/producer/filtering.txt: the words a character name may not contain (same parse as character creation, create.js)
    return this._filter ||= fetchText('script/producer/filtering.txt', true)
      .then(t => t.split(/[\r\n,\t]+/).map(s => s.trim().toLowerCase()).filter(s => s && !/^[#/]/.test(s) && s.length >= 2))
      .catch(() => []);
  }

  /** The 170:10 conditions as the client sees them (the host re-checks party / expedition / guild). */
  conditions() {
    const g = this.game, n = g.network;
    return {
      party: !!n?.party?.active,
      expedition: !!n?.expedition?.active,
      guild: this.online ? !!n?.guild?.founded : !!g.guild?.founded,
      friends: g.life?.friends?.list?.()?.length || 0,
    };
  }

  // ------------------------------------------------------------------ windows
  async _window(script, name, setup) {
    const W = this.game.uiwin;
    W.close(name);
    const win = await W.create(script, { name, escClose: true, remember: false, disposeOnClose: true });
    // the non-modal caution box too gets the legible prompt surface create() gives modal msgbox scripts (manager.js)
    if (/(?:^|\/)msgbox\//i.test(script) && win.el?.style) win.el.style.backgroundColor = '#17130f';
    return new Promise(resolve => {
      win.once('close', r => resolve(r));
      try { setup?.(win); } catch (err) { console.error('[namechange]', name, err); }
      W.openWindow(win);
      // the msgbox scripts give a rect centred on 0 (e.g. -116 -78 116 79) and no position: a screen-centred box
      const s = win.spec;
      if (s && !s.anchor && !s.center && !s.edges && Array.isArray(s.rect) && s.rect[0] < 0) win.center?.();
    });
  }

  /** The refusal box (msgbox/ui_changecharnameerror.txt): lbl_errMsg = the reason. */
  showError(message) {
    return this._window(SCRIPTS.charError, 'error_changecharname', w => {
      if (message) w.control('lbl_errMsg').setText(message);
      w.control('btn_yes').onClick(() => w.close('ok'));
    });
  }

  /** Name entry window; resolves the validated name or null. */
  _entry(script, name, { line, validate }) {
    let value = null;
    return this._window(script, name, w => {
      w.control('lbl_name').setRichText(line);
      const edit = w.control('edt_name'), fail = w.control('lbl_failmsg');
      const submit = async () => {
        const r = await validate(String(edit.getValue?.() ?? ''));
        if (r.error) { fail.setText(r.error).show(); return; }
        value = r.name; w.close('yes');
      };
      w.control('btn_yes').onClick(submit);
      edit.on?.('enter', submit);
      w.control('btn_cancle').onClick(() => w.close('no'));
      setTimeout(() => edit.focus?.(), 0);
    }).then(() => value);
  }

  /** Two-button prompt (confirm / caution): resolves true on OK. texts = [labelId, markup] drawn top to bottom. */
  _ask(script, name, texts) {
    return this._window(script, name, w => {
      for (const [id, text] of texts) w.control(id).setRichText(text);
      w.control('btn_yes').onClick(() => w.close('yes'));
      w.control('btn_no').onClick(() => w.close('no'));
      w.once?.('open', () => this._fit(w, texts.map(([id]) => id)));
    }).then(r => r === 'yes');
  }

  /**
   * The EU strings of these older msgbox scripts are several lines each (170:10 three, 170:11 four) while the script gives
   * every one a 14 px label, so drawn as scripted they overlap and run past the frame. Each label keeps its script x/width,
   * wraps inside that width, and starts below the previous label's text; the frame (background panel) and the buttons move
   * down by the extra height. Texts, controls and art stay the script's. No-op without a DOM (tests).
   */
  _fit(w, ids) {
    const labels = ids.map(id => w.find?.(id)).filter(c => c?.txt?.firstChild);
    if (!labels.length) return;
    let bottom = -Infinity;
    for (const c of labels) {
      c.isMultiline = () => true; c.autoWrap = () => true; c.paintText();   // this instance only (the cached spec is shared)
      const [x, y, width] = c.spec.rect;
      const h = Math.ceil(c.txt.firstChild.offsetHeight || 14);
      const top = Math.max(y, bottom + 4);
      c.setRect(x, top, width, h);
      bottom = top + h;
    }
    const buttons = ['btn_yes', 'btn_no'].map(id => w.find(id)).filter(Boolean);
    const buttonY = Math.min(...buttons.map(b => b.spec.rect[1]));
    const grow = Math.max(0, Math.ceil(bottom + 8 - buttonY));
    if (!grow) return;
    for (const b of buttons) { const [x, y, bw, bh] = b.spec.rect; b.setRect(x, y + grow, bw, bh); }
    const back = w.find('pan_confirm_back') || w.find('pan_caution_back');
    if (back) { const [x, y, bw, bh] = back.spec.rect; back.setRect(x, y, bw, bh + grow); }
    w.box.h += grow; w.el.style.height = `${w.box.h}px`;
    w.center?.();
  }

  // ------------------------------------------------------------------ character
  async character(item) {
    const g = this.game, s = g.save || {};
    if (this.busy) return false;
    const blocker = charNameBlocker(this.conditions());
    if (blocker) { await this.showError(this.text(blocker)); return false; }
    const who = newName => ({ name: newName, level: s.level || 1, className: s.className || '' });
    const filter = await this.filterWords();
    const name = await this._entry(SCRIPTS.charName, 'changecharname', {
      line: fillName(this.text('charLine'), who(s.name || '')),
      validate: async v => {
        const r = checkNewCharacterName(v, { current: s.name || '', filter });
        if (r.error === 'nameWord') return { error: String(this.text('nameWord', 'The word %s cannot be used.')).replace('%s', r.word).replace(/<[^>]+>/g, '').replace(/\n/g, ' ') };
        if (r.error) return { error: this.text(r.error) };
        if (!this.online && (await this._localNames()).some(n => n.toLowerCase() === r.name.toLowerCase())) return { error: this.text('nameTaken') };
        return r;
      },
    });
    if (!name) return false;
    if (!await this._ask(SCRIPTS.charConfirm, 'changecharname_confirm', [['lbl_confirm_static1', this.text('conditions')], ['lbl_text', fillName(this.text('charLine'), who(name))]])) return false;
    if (!await this._ask(SCRIPTS.charCaution, 'changecharname_caution', [['lbl_static1', this.text('conditions')], ['lbl_caution1', fillName(this.text('redirect'), { name })]])) return false;
    this.busy = true;
    try {
      const ok = this.online ? await this._renameOnline(item, name) : this._renameLocal(item, name);
      if (!ok) return false;
    } finally { this.busy = false; }
    this.toCharacterSelect();
    return true;
  }

  async _renameOnline(item, name) {
    const n = this.game.network;
    const result = await n.action('charname', { uid: item.uid, name });
    if (result?.nameChangeResult?.name) return true;
    await this.showError(n._lastCommandError?.message || '');
    return false;
  }

  async _localNames() {
    try { const { listCharacters } = await import('../../game/save.js'); return listCharacters().filter(c => c.id !== this.game.save?.id).map(c => String(c.name || '')); } catch { return []; }
  }

  _renameLocal(item, name) {
    const g = this.game;
    if (!g.items?.consume) return false;
    g.items.consume(item, 1);
    g.save.name = name;
    if (g.player) g.player.name = name;
    g.events?.emit?.('rename', { name });
    try { g.persist?.(); } catch (err) { console.error(err); }
    return true;
  }

  /** 170:11 "You will be redirected to the Character Selection screen": the system menu's Character path (sysmenu.js). */
  toCharacterSelect() {
    const g = this.game, go = () => {
      try { g.persist?.(); } catch (err) { console.error(err); }
      if (globalThis.dekaronReturnTo) globalThis.dekaronReturnTo('select');
      else globalThis.location?.reload?.();
    };
    if (g.uiwin?.has?.('systemwait')) g.uiwin.open('systemwait', { go }); else go();
  }

  // ------------------------------------------------------------------ guild
  guildState() {
    const g = this.game;
    if (this.online) { const s = g.network?.guild; return s?.founded ? { name: s.name, master: !!s.myRef && s.master === s.myRef, state: s } : null; }
    return g.guild?.founded ? { name: g.guild.st.name, master: true, state: g.guild.st } : null;
  }

  async guild(item) {
    const g = this.game;
    if (this.busy) return false;
    const st = this.guildState();
    if (!st) { await g.uiwin?.msgbox?.(this.text('noGuild'), { kind: 'ok' }); return false; }
    if (!st.master) { await g.uiwin?.msgbox?.(this.text('guildLeaderOnly'), { kind: 'ok' }); return false; }
    // one change (130:314 "Changed: <VALUE>/1 Time"): past it 130:317; else the caution box first (130:313 + the count)
    const changes = Math.max(0, Number(st.state?.nameChanges) || 0);
    if (changes >= GUILD_NAME_CHANGES_MAX) { await g.uiwin?.msgbox?.(this.text('guildLimit'), { kind: 'ok' }); return false; }
    if (!await this._ask(SCRIPTS.guildCaution, 'guildchangename_caution', [['lbl_static1', this.text('guildChangeAsk')], ['lbl_text', this.text('guildChanged').replace('<VALUE>', String(changes))]])) return false;
    const name = await this._entry(SCRIPTS.guildName, 'changeguildname', {
      line: fillName(this.text('guildLine'), { name: st.name }),
      validate: async v => { const r = checkNewGuildName(v, { taken: key => key === String(st.name || '').toLowerCase() }); return r.error ? { error: this.text(r.error) } : r; },
    });
    if (!name) return false;
    // lbl_text: the typed name on the guild-name line 170:88 (the script's default 170:6 adds a character level/class line)
    if (!await this._ask(SCRIPTS.guildConfirm, 'changeguildname_confirm', [['lbl_static1', this.text('guildRetyped')], ['lbl_text', fillName(this.text('guildLine'), { name })], ['lbl_caution', this.text('guildCount')]])) return false;
    this.busy = true;
    try {
      if (this.online) {
        const n = g.network, s = n.guild;
        const result = await n.action('guild', { operation: 'rename', revision: s.revision, requestId: randomUUID(), name, uid: item.uid });
        if (!result) { await g.uiwin?.msgbox?.(n._lastCommandError?.message || this.text('guildNameInvalid'), { kind: 'ok' }); return false; }
      } else {
        if (!g.items?.consume) return false;
        g.items.consume(item, 1);
        g.guild.st.name = name;
        g.guild.st.nameChanges = (Number(g.guild.st.nameChanges) || 0) + 1;   // 130:318: each change counts once
        try { g.persist?.(); } catch (err) { console.error(err); }
      }
    } finally { this.busy = false; }
    g.events?.emit?.('guild:renamed', { name });
    return true;
  }

  /** Guild Master's Mistake (Type 0 Code 27): msgbox/ui_guildchangenameclearcount (170:14) resets the name change history. */
  async guildReset(item) {
    const g = this.game;
    if (this.busy) return false;
    const st = this.guildState();
    if (!st) { await g.uiwin?.msgbox?.(this.text('noGuild'), { kind: 'ok' }); return false; }
    if (!st.master) { await g.uiwin?.msgbox?.(this.text('guildLeaderOnly'), { kind: 'ok' }); return false; }
    if (!(Number(st.state?.nameChanges) > 0)) { await g.uiwin?.msgbox?.(this.text('guildZeroChanges'), { kind: 'ok' }); return false; }
    // lbl_caution1's 170:15 is "Pet/Mount" in this Global (the code was reused): left empty
    if (!await this._ask(SCRIPTS.guildClearCount, 'guildchangename_clearcount', [['lbl_static1', this.text('guildResetAsk')], ['lbl_caution1', '']])) return false;
    this.busy = true;
    try {
      if (this.online) {
        const n = g.network, s = n.guild;
        const result = await n.action('guild', { operation: 'resetNameChanges', revision: s.revision, requestId: randomUUID(), uid: item.uid });
        if (!result) { await g.uiwin?.msgbox?.(n._lastCommandError?.message || this.text('guildZeroChanges'), { kind: 'ok' }); return false; }
      } else {
        if (!g.items?.consume) return false;
        g.items.consume(item, 1);
        g.guild.st.nameChanges = 0;
        try { g.persist?.(); } catch (err) { console.error(err); }
      }
    } finally { this.busy = false; }
    return true;
  }
}
