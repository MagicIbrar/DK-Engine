// Mail (game2/letter: `ui_newletterboxwnd2.txt` "mail", `ui_newletterreadwnd2.txt` "mailread", the arrival popup
// `ui_arrivemailwnd.txt` "mailalert"). There are no other players to mail in a single-player game, so mail here is
// account-wide between YOUR OWN saved characters (common.js's `account()` localStorage store, whose own comment
// already calls out "mail of other characters" as its purpose) - a solo-meaningful reuse of the system for moving
// Dil and items between alts - plus "System" mail that other systems (rewards, GM tools) hand a character while
// it is not even loaded, via `receiveSystem`. Opened from an NPC shop's own Mail button (shops/premium.js tries
// window names 'mail' / 'mailbox' / 'post' in that order) or by clicking the arrival popup; `game.events` emits
// `'mail' {unread}` so hud-options' chat window can blink its own btn_mail icon.
// Known gap: attaching an ITEM when composing needs the items system's drag-and-drop grid (`letter_item`'s
// `pan_inven` loadchild is the original bag panel, rendered but not wired to `acceptDrop` here) - composing
// currently sends Dil only; receiving mail with an attached item (system rewards) works fully.
import { str, strNow, msg, account, saveAccount, canGive, giveItem, dil, spendDil, setItemIcon, numText, rejectUnsupportedOnline } from './common.js';
import { listCharacters } from '../../game/save.js';
import { MAIL_TEXT, mailAttachError, mailSendCost, trimSent, mailDeleteError } from './mail-rules.js';

// Postage is the original flat 100 DIL (250:20, official guide 25), shared with the host: no percentage tax exists.
const QUICK = { btn_million: 1000000, btn_100thousand: 100000, btn_10thousand: 10000 };

function acctMail() { const a = account(); if (!a.mail) a.mail = {}; if (!a.mailSent) a.mailSent = {}; return a; }
const key = (name) => String(name || '').trim().toLowerCase();

export class Mail {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.tab = 0;
  }

  myKey() { return key(this.game.save?.name || this.game.player?.name); }
  inbox() { return (acctMail().mail[this.myKey()] || []).slice().sort((a, b) => b.time - a.time); }
  sent() { return (acctMail().mailSent[this.myKey()] || []).slice().sort((a, b) => b.time - a.time); }
  unreadCount() { return this.inbox().filter((m) => !m.read).length; }

  /** Mail from another system (rewards, GM tools) to a character by name - works even if that character isn't loaded. */
  receiveSystem(toName, { title = 'System', content = '', item = 0, itemCount = 0, dilAmt = 0 } = {}) {
    if(rejectUnsupportedOnline(this.game,'System mail rewards'))return false;
    const a = acctMail();
    const k = key(toName);
    const list = a.mail[k] || (a.mail[k] = []);
    list.push({ id: `m${Date.now().toString(36)}${Math.random().toString(36).slice(2, 6)}`, from: 'System', title, content, item, itemCount, dil: dilAmt, time: Date.now(), read: false, claimed: false });
    saveAccount();
    if (k === this.myKey()) { this._alert(); this.game.events?.emit?.('mail', { unread: this.unreadCount() }); }
  }

  async install() {
    const g = this.game;
    await Promise.all([str(g, 100, 61), str(g, 250, 1)]);
    g.ui?.registerWindow?.('mail', { script: 'game2/letter/ui_newletterboxwnd2.txt', create: (w) => this._create(w), onOpen: (w) => this._refresh(w) });
    g.ui?.registerWindow?.('mailread', { script: 'game2/letter/ui_newletterreadwnd2.txt', modal: true, create: (w) => this._createRead(w), onOpen: (w, m) => this._openRead(w, m) });
    g.ui?.registerWindow?.('mailalert', { script: 'game2/letter/ui_arrivemailwnd.txt', hud: true, escClose: false, remember: false,
      create: (w) => w.control('pan_main').on('click', () => g.uiwin.open('mail')) });
    if (this.unreadCount() > 0) this._alert();
  }

  open() { return this.game.uiwin.open('mail'); }
  /** Open the mailbox on the compose tab with a recipient pre-filled (friends.js "Send Message"). */
  composeTo(name) {
    return this.game.uiwin.open('mail').then((w) => {
      this.tab = 1;
      this._refresh(w);
      w.control('edit_receivename').setValue?.(name || '');
      return w;
    });
  }

  // ------------------------------------------------------------------------------------------- mailbox window
  _create(w) {
    this.win = w;
    for (let t = 0; t <= 2; t++) w.control(`btn_tab_${t}`).onClick(() => { this.tab = t; this._refresh(w); });
    w.control('btn_exit').onClick(() => w.close());
    w.control('recv_maillist').on('dblclick', (i) => { const m = this.inbox()[i]; if (m) this.game.uiwin.open('mailread', m); });
    w.control('send_maillist').on('dblclick', (i) => { const m = this.sent()[i]; if (m) this.game.uiwin.msgbox(`To ${m.toName || '?'}:\n${m.content || ''}`, { kind: 'ok' }); });
    w.control('btn_listbox').setEnabled(true).onClick(() => { const p = w.control('pan_friendlist'); p.setVisible(!p.isVisible()); if (p.isVisible()) this._fillCharList(w); });
    const list = w.control('list_friend');
    list.on?.('select', (i, it) => { const name = typeof it === 'string' ? it : (it?.text || it?.data?.name || ''); if (!name.startsWith('(')) { w.control('edit_receivename').setValue?.(name); } w.control('pan_friendlist').hide(); });
    for (const [id, amt] of Object.entries(QUICK)) w.control(id).onClick(() => { const cur = Number(w.control('edit_dil').getNumber?.() ?? w.control('edit_dil').getValue?.()) || 0; w.control('edit_dil').setValue?.(cur + amt); });
    w.control('btn_send').onClick(() => this._send(w));
    w.control('btn_cancel').onClick(() => { w.control('edit_receivename').setValue?.(''); w.control('edit_title').setValue?.(''); w.control('textbox').setText?.(''); w.control('edit_dil').setValue?.(''); });
    w.control('pan_friendlist').hide();
  }

  _fillCharList(w) {
    const mine = key(this.game.save?.name || this.game.player?.name);
    const names = listCharacters().map((c) => c.name).filter((n) => key(n) !== mine);
    w.control('list_friend').setItems?.(names.length ? names : ['(no other saved characters)']);
  }

  _refresh(w) {
    const g = this.game;
    for (let t = 0; t <= 2; t++) w.control(`btn_tab_${t}`).setChecked(t === this.tab);
    w.control('pan_receivebox').setVisible(this.tab === 0);
    w.control('pan_sendbox').setVisible(this.tab === 1);
    w.control('pan_sendedbox').setVisible(this.tab === 2);
    const inbox = this.inbox();
    w.control('lbl_totalletter').setText(String(inbox.length));
    w.control('lbl_notreadletter').setText(String(inbox.filter((m) => !m.read).length));
    w.control('lbl_tagwarning').setVisible(inbox.length >= 100);
    w.control('recv_maillist').setItems?.(inbox.map((m) => ({ icon: m.item || m.dil ? 1 : 0, title: `${m.from}: ${m.title}`, content: m.content, time: new Date(m.time).toLocaleDateString(), read: m.read, data: m })));
    const sent = this.sent();
    w.control('send_maillist').setItems?.(sent.map((m) => ({ icon: m.item || m.dil ? 1 : 0, title: `${m.toName}: ${m.title}`, content: m.content, time: new Date(m.time).toLocaleDateString(), data: m })));
  }

  async _send(w) {
    const g = this.game;
    if(rejectUnsupportedOnline(g,'Mail delivery'))return false;
    const toName = w.control('edit_receivename').getValue?.() || w.control('edit_receivename').getText?.() || '';
    const title = w.control('edit_title').getValue?.() || '';
    const content = w.control('textbox').getText?.() || '';
    const amt = Math.max(0, Math.floor(Number(w.control('edit_dil').getNumber?.() ?? w.control('edit_dil').getValue?.()) || 0));
    const mine = key(this.game.save?.name || this.game.player?.name);
    if (!toName.trim()) { msg(g, strNow(g, 250, 28) || MAIL_TEXT.noRecipient, 'err'); return; }
    if (key(toName) === mine) { msg(g, "You can't mail yourself.", 'err'); return; }
    const exists = listCharacters().some((c) => key(c.name) === key(toName));
    if (!exists) { msg(g, strNow(g, 250, 36) || MAIL_TEXT.notFound, 'err'); return; }
    const attachError = mailAttachError(amt);
    if (attachError) { msg(g, attachError, 'err'); return; }
    if (!title.trim() && !content.trim() && !amt) { msg(g, 'Nothing to send.', 'err'); return; }
    const total = mailSendCost(amt);
    if (dil(g) < total || !spendDil(g, total)) { msg(g, strNow(g, 250, 31) || MAIL_TEXT.noDil, 'err'); return false; }
    const rec = { id: `m${Date.now().toString(36)}${Math.random().toString(36).slice(2, 6)}`, from: g.save?.name || 'Me', title: title || '(no subject)', content, item: 0, itemCount: 0, dil: amt, time: Date.now(), read: false, claimed: false };
    const a = acctMail();
    (a.mail[key(toName)] || (a.mail[key(toName)] = [])).push(rec);
    a.mailSent[mine] = trimSent([...(a.mailSent[mine] || []), { ...rec, toName }]);   // 250:73: up to 10 recent sent mails
    saveAccount();
    msg(g, strNow(g, 250, 35) || MAIL_TEXT.sent, 'sys');
    w.control('edit_receivename').setValue?.(''); w.control('edit_title').setValue?.(''); w.control('textbox').setText?.(''); w.control('edit_dil').setValue?.('');
    this._refresh(w);
  }

  // ------------------------------------------------------------------------------------------- read window
  _createRead(w) {
    w.control('btn_close').onClick(() => w.close());
    w.control('btn_delete').onClick(() => {
      const m = w.data.mail;
      // 250:24 / 250:64 / 250:65: a mail with an unclaimed item or DIL cannot be deleted (the read window stays open).
      const blocked = mailDeleteError(m);
      if (blocked) { msg(this.game, strNow(this.game, 250, m.item ? 64 : 65) || blocked, 'err'); return; }
      if (m) this._delete(m); w.close();
    });
    w.control('btn_reply').onClick(() => { const m = w.data.mail; w.close(); if (m) { this.game.uiwin.open('mail').then((mw) => { this.tab = 1; this._refresh(mw); mw.control('edit_receivename').setValue?.(m.from); }); } });
    w.control('btn_item').onClick(() => this._claimItem(w));
    w.control('btn_money').onClick(() => this._claimMoney(w));
  }
  _openRead(w, m) {
    if (!m) return;
    w.data.mail = m;
    m.read = true; saveAccount(); this.game.events?.emit?.('mail', { unread: this.unreadCount() });
    w.control('lbl_sendername').setText(m.from || 'System');
    w.control('lbl_Systemletter').setVisible(m.from === 'System');
    w.control('lbl_subject').setText(m.title || '');
    w.control('textbox').setText?.(m.content || '');
    setItemIcon(this.game, w.control('giveitem'), m.item || 0, m.itemCount || 0, 40, 40);
    w.control('btn_item').setEnabled(!!m.item && !m.claimed);
    w.control('lbl_money').setText(m.dil > 0 ? numText(m.dil) : '');
    w.control('btn_money').setEnabled(m.dil > 0 && !m.claimed);
    if (this.win?.isOpen) this._refresh(this.win);
  }
  _claimItem(w) {
    const m = w.data.mail, g = this.game;
    if (!m?.item || m.claimed) return;
    if(g.save?.authority==='server'){msg(g,'Local archive mail cannot grant online items. The attachment remains preserved.','err');return;}
    if (!canGive(g, m.item, m.itemCount || 1)) { msg(g, 'Your inventory is full.', 'err'); return; }
    giveItem(g, m.item, m.itemCount || 1, { source: 'mail' });
    m.claimed = m.dil ? m.claimed : true;
    m.item = 0;
    saveAccount();
    w.control('btn_item').setEnabled(false);
  }
  _claimMoney(w) {
    const m = w.data.mail, g = this.game;
    if (!(m?.dil > 0)) return;
    if(g.save?.authority==='server'){msg(g,'Local archive mail cannot grant online currency. The attachment remains preserved.','err');return;}
    if (typeof g.items?.addDil === 'function') g.items.addDil(m.dil); else { g.save.dil = (g.save.dil || 0) + m.dil; g.events?.emit?.('dil', { amount: m.dil, total: g.save.dil }); }
    const claimedDil = m.dil; m.dil = 0;
    if (!m.item) m.claimed = true;
    saveAccount();
    msg(g, `Received ${numText(claimedDil)} Dil.`, 'item');
    w.control('btn_money').setEnabled(false);
    w.control('lbl_money').setText('');
  }
  _delete(m) {
    const a = acctMail(), k = this.myKey();
    a.mail[k] = (a.mail[k] || []).filter((x) => x.id !== m.id);
    saveAccount();
    if (this.win?.isOpen) this._refresh(this.win);
    this.game.events?.emit?.('mail', { unread: this.unreadCount() });
  }

  // ------------------------------------------------------------------------------------------- arrival popup
  _alert() {
    const g = this.game;
    const n = this.unreadCount();
    if (n > 0) g.uiwin.open('mailalert').then((w) => w.control('lbl_mailNum').setText(String(n)));
    else g.uiwin.close('mailalert');
  }

  update() {
    // pick up mail queued while this character wasn't the active one (another life.mail.receiveSystem call)
    if (!this._lastUnread) this._lastUnread = 0;
    const n = this.unreadCount();
    if (n !== this._lastUnread) { this._lastUnread = n; this._alert(); this.game.events?.emit?.('mail', { unread: n }); }
  }
}
