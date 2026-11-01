// Friends / messenger (game2/messenger/ui_messengerwnd.txt "messenger" - hotkey F / main-menu btn_mail, wired by
// hud-options' keymap.js and hudwins.js MENU table to this exact window name). A single-player game has nobody to
// actually be online, so every friend entry is honestly shown offline/"not connected" (matching the client's own
// whisper-to-nobody message, hud-options/chat.js's `str(1006, 48)`); online rosters are scoped to the authenticated
// account/character and serving origin; solo rosters retain a separate legacy migration. You can add
// your own alts or any name; shared-world registration awaits the host save and
// respects the recipient's canonical Block friend requests setting (online or offline).
// "Send Message" opens the bottom chat whisper input.
// No server-side friend cap exists to read, so
// MAX_FRIENDS below is Global's per-PC cap of 30 (global-re/SERVER-RE.md §6, Segment<30>).
// MESSENGER-CHAT: in shared play src/systems/network/messenger.js sets the hooks online(name) (presence from the host's
// connected list), chat(name) ("Talk" 1006:5 opens the 1:1 chat window), partyInvite(name) and onDecline(on); the
// checkbox row pan_noMsg is the original "Decline messages" (1006:47) switch. Without the hooks (single player) every
// friend stays Offline and "Talk" answers 1006:48 as before.
import { str, msg, account, saveAccount, friendRosterKey, friendRosterReady } from './common.js';
import { listCharacters } from '../../game/save.js';

const MAX_FRIENDS = 30;   // Global per-PC Segment<30, Coupler<String<25>, IFriend*>> (global-re/SERVER-RE.md §6)
const key = (n) => String(n || '').trim().toLowerCase();

export class Friends {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.declineMessages = false;   // pan_noMsg "Decline messages" (1006:47)
    this.sel = null;
    this.pendingAdds = new Map();
  }

  myKey() { return key(this.game.save?.name || this.game.player?.name); }
  storageKey() { return friendRosterKey(this.game); }
  list() {
    const scope = this.storageKey();
    if (!scope || !friendRosterReady(this.game)) return [];
    const a = account();
    if (!a.friends || typeof a.friends !== 'object') a.friends = {};
    if (!Array.isArray(a.friends[scope])) {
      // Online names come only from this authenticated character's canonical
      // consent, never another character's unowned legacy name bucket.
      const online = this.game.save?.authority === 'server' || this.game.network?.active;
      const self = this.game.network?.self;
      const names = online ? (self?.profile?.id === this.game.save.id ? Array.isArray(self.profile.npcFriends) ? self.profile.npcFriends : [] : []) : null;
      a.friends[scope] = online ? names.filter(n => typeof n === 'string' && n.trim()).map(name => ({ name, addedAt: 0 }))
        : (Array.isArray(a.friends[this.myKey()]) ? a.friends[this.myKey()] : []).map(entry => ({ ...entry }));
      saveAccount();
    }
    return a.friends[scope];
  }
  isKnownAlt(name) { return listCharacters().some((c) => key(c.name) === key(name) && key(c.name) !== this.myKey()); }

  add(name) {
    name = String(name || '').trim();
    if (!name) return false;
    if (!this.storageKey() || !friendRosterReady(this.game)) { msg(this.game, 'Connect before changing online friends.', 'err'); return false; }
    if (key(name) === this.myKey()) { msg(this.game, "You can't add yourself.", 'err'); return false; }
    const list = this.list();
    if (list.length >= MAX_FRIENDS) { msg(this.game, 'Your friend list is full.', 'err'); return false; }
    if (list.some((f) => key(f.name) === key(name))) { msg(this.game, `${name} is already on your list.`, 'err'); return false; }
    if(this.game.network?.active||this.game.save?.authority==='server')return this._addShared(name);
    list.push({ name, addedAt: Date.now() });
    saveAccount();
    if (this.win) this._refresh(this.win);
    this._syncNpcFriends();
    return true;
  }
  remove(name) {
    const pending=this.pendingAdds.get(key(name));if(pending){pending.cancelled=true;return true;}
    if (!name || !this.list().some(f => key(f.name) === key(name))) return false;
    const a = account();
    a.friends[this.storageKey()] = this.list().filter((f) => key(f.name) !== key(name));
    saveAccount();
    if (key(this.sel) === key(name)) this.sel = null;
    if (this.win) this._refresh(this.win);
    this._syncNpcFriends();
    return true;
  }
  _syncNpcFriends() {
    const pending = this.game.npcFriends?.sync?.();
    if (pending?.catch) void pending.catch(err => msg(this.game, err.message, 'err'));
  }
  get pendingAdd(){return this.pendingAdds.size>0;}
  async _addShared(name){
    const g=this.game,n=g.network,scope=this.storageKey(),owner=n?.self?.id,token=n?.token;
    if(!n?.active||!n.ready||!owner||!g.npcFriends||g.npcFriends.disposed||this.pendingAdd)return false;
    const pending={cancelled:false};this.pendingAdds.set(key(name),pending);
    try{
      const result=await n.action('npcfriends',{operation:'set',names:[...this.list().map(f=>f.name),name]});
      if(!result||pending.cancelled||g.npcFriends.disposed||g.network!==n||!n.active||!n.ready||owner!==n.self?.id||token!==n.token||scope!==this.storageKey()||!friendRosterReady(g))return false;
      this.list().push({name,addedAt:Date.now()});saveAccount();if(this.win)this._refresh(this.win);return true;
    }catch(error){msg(g,error.message,'err');return false;}
    finally{this.pendingAdds.delete(key(name));if(g.network===n&&token===n.token&&scope===this.storageKey()&&owner===n?.self?.id){g.npcFriends?.invalidate?.();this._syncNpcFriends();}}
  }

  async install() {
    const g = this.game;
    await Promise.all([str(g, 1006, 9), str(g, 1006, 49), str(g, 1006, 47)]);
    g.ui?.registerWindow?.('messenger', { script: 'game2/messenger/ui_messengerwnd.txt', menuButton: 'btn_mail', create: (w) => this._create(w), onOpen: (w) => this._refresh(w) });
  }

  _create(w) {
    this.win = w;
    w.control('btn_exit').onClick(() => w.close());
    const doAdd = async () => { if (await this.add(w.control('edit_text').getValue?.())) { w.control('edit_text').setValue?.(''); this._refresh(w); } };
    w.control('btn_add').onClick(doAdd);
    w.control('edit_text').on?.('enter', doAdd);
    w.control('pan_noMsg_check').setVisible(this.declineMessages);
    w.control('pan_noMsg').on('click', () => { this.declineMessages = !this.declineMessages; w.control('pan_noMsg_check').setVisible(this.declineMessages); void this.onDecline?.(this.declineMessages); });
    const tree = w.control('messenger_tree');
    tree.on?.('select', (node) => { this.sel = node?.data?.name || null; });
    tree.on?.('rclick', (node, e) => { this.sel = node?.data?.name || null; if (this.sel) this._openMenu(w, e); });
    const pop = w.control('pan_menuPop');
    pop.hide();
    // The authored Delete (1006:8) and Party (1006:60) share rect13,58,75,16.
    // Keep both native controls: one extra pixel fits five independent rows.
    // This reflow is ENGINE-CHOSEN; all labels/art remain the owner's originals.
    pop.control('pan_menuPop_bgM').setRect?.(0, 12, 101, 90);
    pop.control('pan_menuPop_bgB').setRect?.(0, 102, 101, 12);
    pop.control('btn_party').setRect?.(13, 74, 75, 16);
    // The native per-label left offsets overflow the translated English labels.
    // Centre inside each existing hit area; keep native font, states and artwork.
    for (const id of ['btn_chat','btn_sendMsg','btn_moveGroup','btn_delete','btn_party']) {
      const button = pop.control(id);
      button.spec = { ...button.spec, align: { h: 'center', v: 'top' } };
      button.refresh?.();
    }
    pop.control('btn_chat').onClick(() => { pop.hide(); if (!this.sel) return; if (this.chat) void this.chat(this.sel); else msg(this.game, `[${this.sel}] is not connected to the game, therefore cannot send the message.`, 'err'); });
    pop.control('btn_sendMsg').onClick(() => { pop.hide(); if (this.sel) this.game.chat?.openInput?.(`"${this.sel} `); });
    pop.control('btn_moveGroup').onClick(() => { pop.hide(); msg(this.game, 'Only one friend group is available.', 'err'); });
    pop.control('btn_party').onClick(() => { pop.hide(); if (!this.sel) return; if (this.partyInvite) void this.partyInvite(this.sel); else msg(this.game, `[${this.sel}] is not connected to the game.`, 'err'); });
    pop.control('btn_delete').onClick(() => { pop.hide(); if (this.sel) { this.remove(this.sel); this.sel = null; this._refresh(w); } });
  }

  _openMenu(w, e) {
    const pop = w.control('pan_menuPop');
    if (!this.sel || !this.list().some(f => key(f.name) === key(this.sel))) { pop.hide(); return; }
    const ui = this.game.uiwin, parent = pop.parent || w.root;
    const r = parent.el.getBoundingClientRect(), origin = ui.toLayer(r.left, r.top);
    const point = ui.toLayer(e.clientX, e.clientY);
    if (![origin.x, origin.y, point.x, point.y].every(Number.isFinite)) { pop.hide(); return; }
    // The authored window includes invisible space around the visible panel.
    // Clamp to the actual UI viewport so the popup stays by the clicked friend.
    const x = Math.max(0, Math.min(ui.screen.w - 101, Math.round(point.x)));
    const y = Math.max(0, Math.min(ui.screen.h - 114, Math.round(point.y)));
    pop.setRect(x - origin.x, y - origin.y, 101, 114);
    pop.show();
  }

  _refresh(w) {
    // single player: everyone is offline; shared play: online() is the host's connected list (online friends first)
    const list = this.list().slice();
    if (this.sel && !list.some(f => key(f.name) === key(this.sel))) { this.sel = null; w.control('pan_menuPop').hide(); }
    const on = (f) => !!this.online?.(f.name);
    w.control('lbl_count').setText(`${list.length} / ${MAX_FRIENDS}`);
    const nodes = list.length
      ? list.sort((a, b) => (on(b) - on(a)) || a.name.localeCompare(b.name)).map((f) => ({ text: `${f.name}${this.isKnownAlt(f.name) ? ' (alt)' : ''}`, color: on(f) ? 'ffffffff' : 'ffb0b0b0', right: on(f) ? 'Online' : 'Offline', data: f, selectable: true }))
      : [{ text: '(no friends added)', color: 'ff7d7d7d', selectable: false }];
    w.control('messenger_tree').setNodes?.(nodes);
  }
}
