// CHARACTER SELECT screen (its own screen, as in the original client).
//
// Scene: the selected character stands in its class-select map exactly as the client stages it
// (script/producer/char_selectinfo.txt: map 100..113, position, direction, scale, camera eye / horizon / vertical),
// wearing its own equipment (the in-game Player assembly, FrontCharacter.fromSave) and looping the class-select
// STAND motion; the rotate buttons of pan_connect (and dragging on the scene) turn it. Music: sound.json
// bgmSpecial.charSelect (the playlists of maps 100..113 = bgm_charselect.mp3). Selecting a character of a class staged
// in another map fades to it (scenefadeout/in.txt, 500 ms).
//
// Window: script/ui/game2/ui_charselectwnd.txt built by the UI platform (src/ui/uiwin):
//   letterbox bars, pan_select (right, top 100): the character slots character_list_btn_0..4 (58 px rows, check =
//   Character_4#5, over = Character_new#11; name / level + class / location), the page buttons btn_page_1 / 2
//   (5 slots a page, 2 pages = 10 characters; the list frame's middle piece is stretched to the rows as the client
//   does), Standard / Arena mode buttons; pan_select_char (the selected character's name plate), pan_connect
//   (turn left / Connect / turn right), btn_create_char (New), btn_delete_char (Delete, confirmed in
//   ui_deletecharwnd.txt by typing the name), btn_exit (Exit Game -> back to the login screen: a browser tab cannot
//   quit itself).
// Decisions: deletion is immediate after the confirmation (the server-side "Deletion in progress" timer of the live
// service, lbl_character_del_* / btn_delete_cancel / btn_delete_char_confirm, has no meaning offline and stays
// hidden); field-channel choices come from the authenticated host catalog.
import { FrontCharacter } from './character.js';
import { updateOrbit } from '../../systems/items/weapon-orbit.js';
import { loadSelectInfo, classSceneInfo, selectCharYaw, frameView, rowCamHeight, SELECT_BAND } from './selectinfo.js';
import { rowFovDeg } from './stage.js';
import { cloneTemplate, rich } from './ui.js';
import { SERVER_LABEL } from './login.js';
import { listCharacters, deleteAccountCharacter } from '../../game/save.js';
import { prewarmClassIcons } from '../icon-prewarm.js';
import { playerNameplateName } from '../../game/nameplate-view.js';

export const ROWS_PER_PAGE = 5;
export const PAGES = 2;
export const MAX_CHARACTERS = ROWS_PER_PAGE * PAGES;
const ROW_H = 58;
const EMPTY_MAP = 100;

export class SelectScreen {
  constructor(fe) {
    this.fe = fe;
    this.stage = fe.stage;
    this.T = fe.texts;
    this.chars = [];
    this.page = 0;
    this.selectedId = null;
    this.model = null;
    this._seq = 0;
    this._turn = 0;
  }

  /** @returns {Promise<{action:'enter'|'create'|'logout', character?:object}>} */
  async run({ selectId = null } = {}) {
    const fe = this.fe;
    this.staffTag=null;
    try { const session=await fe.accounts.request('/api/auth/me');if(session.id===fe.account&&session.capabilities?.includes('gm:commands'))this.staffTag='ADMIN'; } catch { /* ordinary labels when the session cannot be checked */ }
    this.serverLabel = SERVER_LABEL;
    try { const info = await fe.accounts.request('/api/server/info'); if (typeof info.name === 'string' && info.name.trim()) this.serverLabel = info.name.trim().slice(0,64); } catch { /* local fallback retains the configured frontend name */ }
    this.channels=[];this.channelError=null;this.selectedChannel=null;
    try{
      const catalog=await fe.accounts.request('/api/world/channels');
      if(!Array.isArray(catalog.field)||catalog.field.some(row=>!Number.isInteger(row.index)||row.index<0||typeof row.name!=='string'||typeof row.available!=='boolean')||new Set(catalog.field.map(row=>row.index)).size!==catalog.field.length)throw Error('The server returned an invalid channel list.');
      this.channels=catalog.field;const available=this.channels.filter(row=>row.available);
      this.selectedChannel=available.find(row=>row.index===fe.selectedChannel)?.index??available.find(row=>row.index===catalog.defaultChannel)?.index??available[0]?.index??null;
      if(this.selectedChannel===null)this.channelError='This server has no available field channels.';
    }catch(error){this.channelError='Could not load this server’s channels. Return to login and retry. '+error.message;}
    this.classes = await fe.classes();
    this.classByIndex = fe.data.classByIndex;
    this.info = await loadSelectInfo();
    this.chars = listCharacters();
    this.selectedId = (selectId && this.chars.find(c => c.id === selectId)?.id) || this.chars[0]?.id || null;
    const i = this.chars.findIndex(c => c.id === this.selectedId);
    this.page = i >= 0 ? Math.floor(i / ROWS_PER_PAGE) : 0;

    await fe.fade(1, 500, { over: true });
    fe.busy(true);
    this.stage.clearActors();
    await this._buildUI();
    this._wireInput();
    this._offFrame = this.stage.onFrame(dt => this._frame(dt));
    this._refresh();
    await this._showSelected({ initial: true });
    await fe.finishPreload();
    fe.busy(false);
    fe.showWindow(this.win);
    fe.fade(0, 500, { over: true });
    return new Promise(resolve => { this._resolve = resolve; });
  }

  get selected() { return this.chars.find(c => c.id === this.selectedId) || null; }
  _pageChars() { return this.chars.slice(this.page * ROWS_PER_PAGE, (this.page + 1) * ROWS_PER_PAGE); }
  _classDef(save) { return this.classByIndex.get(Number(save?.classIndex)) || this.classes[0]; }
  _mapName(save) { return this.fe.data.mapByIndex(save?.map != null ? save.map : 150)?.Name || ''; }
  _describe(c) {
    const def = this._classDef(c);
    return `${playerNameplateName(c.name,{staffTag:this.staffTag})}\nLv. ${c.level || 1}  ${c.className || def?.name || ''}\n${this._mapName(c)}`;
  }

  // ---------------------------------------------------------------------------------------- scene
  /** Stage the selected character in its class-select map (or the first class map when there is none). */
  async _showSelected({ initial = false } = {}) {
    const seq = ++this._seq;
    const fe = this.fe, stage = this.stage;
    const save = this.selected;
    if (save) prewarmClassIcons(save.classIndex);
    // 2.2.1 instant loading: the tables and the recorded assets of the map this character will enter start now, at low fetch
    // priority (the select scene's own requests go first), so a quick Start still finds most of them in the caches (engine/prefetch.js)
    if (save) fe.warmForCharacter?.(save);
    const def = save ? this._classDef(save) : null;
    const si = classSceneInfo(this.info.get(Number(def?.index ?? 0)) || this.info.get(0) || null);
    const mapIndex = Number(save ? si?.mapIndex ?? def?.showcase?.mapIndex : EMPTY_MAP) || EMPTY_MAP;
    const mapChange = stage.worldIndex !== mapIndex;
    // Rapid slot changes supersede each other: every call that faded the scene out has left it black, and only the
    // newest call survives to the end. The newest call must therefore fade back in whoever started the fade (its own
    // `mapChange` can be false when a superseded call already set stage.worldIndex to the same map).
    if (mapChange && !initial) { this._faded = true; await fe.fade(1, 300); fe.busy(true); }
    if (seq !== this._seq) return;
    const char = save ? FrontCharacter.fromSave(stage, save, def, { scale: Number(si?.scale) || 1, rest: 'createPose', standDuration: si?.stand }) : null;
    if (char) char.group.visible = false;
    try {
      await Promise.all([
        stage.loadWorld(mapIndex, { focus: si ? { x: si.x, z: si.z } : null }),
        char ? char.load().then(() => char.readyPose('createPose')) : null,
      ]);
    } catch (err) {
      console.warn('[frontend] select scene failed', err);
      if (seq === this._seq && this._faded) { this._faded = false; fe.busy(false); fe.fade(0, 400); }
      throw err;
    }
    if (seq !== this._seq) { char?.dispose(); return; }
    if (this.model) stage.removeActor(this.model, true);
    this.model = char;
    const row = fe.data.mapByIndex(mapIndex);
    const fov = rowFovDeg(row);
    let body = null;
    if (char && si) {
      char.standCap = si.eye.y + 1.2;
      char.place(si.x, si.z, selectCharYaw(si));
      stage.addActor(char);
      body = char.standOnFloor('createPose');     // feet on the drawn floor + the posed bounds (helmet, weapon)
      char.group.visible = true;
      char.play('createPose');
    }
    if (si) {
      // the original framing: file anchor + maplist Camera_Height, the whole body inside the
      // letterbox with head and foot room; with no character, a nominal 2.4 m body on the stage
      if (!body) {
        const bottom = char ? char.y : stage.heightAt(si.x, si.z, si.eye.y + 0.7);
        body = { x: si.x, z: si.z, bottom, top: bottom + (char ? char.height * char.scale : 2.4) };
      }
      const v = frameView(si, body, fov, rowCamHeight(row), { band: SELECT_BAND });
      stage.lookFrom(v.eye, v.target, v.fov);
    }
    fe.playBGM('charSelect', mapIndex);
    if (this._faded && !initial) { this._faded = false; fe.busy(false); fe.fade(0, 400); }
  }

  _frame(dt) {
    const m = this.model;
    if (m && m.loaded && this._turn) m.yaw = m.yaw + this._turn * dt * 2.4;
    // Black Wizard orbs: the class-select STAND clip (bwz_com_create_01) authors no BAL_* track, so the orbs sat motionless at the
    // bind pose; keep the in-game battle stand orbit looping (same data, the class's own anims.idle; items/weapon-orbit.js).
    if (m && m.loaded) updateOrbit(m, dt, { force: true });
  }

  // ---------------------------------------------------------------------------------------- window
  async _buildUI() {
    const win = this.win = await this.fe.uim.create('game2/ui_charselectwnd.txt', { name: 'char_select', escClose: false, remember: false, autoClose: false });
    win.el.classList.add('fe-global-front');
    const c = id => win.control(id);
    c('channel_select_win').show();
    const visibleChannels=Math.max(1,Math.min(4,this.channels.length)),channelBottom=38+visibleChannels*25;
    // Keep the authored align_right pin: setRect is an absolute override in
    // uiwin, so changing the script rect retains responsive right alignment.
    const channelPanel=c('channel_select_win');channelPanel.spec.rect=[0,60,236,channelBottom+78];channelPanel.layout(channelPanel.parent.box);
    c('pan_channel_select2').setVisible(channelBottom>78).setRect(0,78,236,Math.max(0,channelBottom-78));
    c('pan_channel_select3').setRect(0,channelBottom,236,78);
    const channelHost=c('pan_channel_bg');channelHost.afterLayout=()=>{channelHost.el.style.overflowY='auto';channelHost.el.style.overflowX='hidden';};channelHost.setRect(8,38,220,visibleChannels*25);channelHost.el.setAttribute('role','radiogroup');channelHost.el.setAttribute('aria-label','Server channels');
    this.channelRows=this.channels.map((row,index)=>{
      const button=c('character_list_btn_0').cloneAs('_channel_'+index,{x:0,y:index*25,parent:channelHost});
      button.setRect(0,index*25,220,25).setText(row.name).setEnabled(row.available).setChecked(row.index===this.selectedChannel);
      button.el.setAttribute('role','radio');button.el.setAttribute('aria-checked',String(row.index===this.selectedChannel));
      button.el.setAttribute('aria-disabled',String(!row.available));button.el.tabIndex=row.available?0:-1;
      button.el.addEventListener('keydown',event=>{if(event.key==='Enter'||event.key===' '){event.preventDefault();event.stopPropagation();this.selectChannel(row.index);}});
      button.onClick(()=>this.selectChannel(row.index));return button;
    });
    if(this.channelError){const label=cloneTemplate(win,'lbl_channel','lbl_channel_error',[10,38,216,25]);label?.setText('Channels unavailable').setFont(2).setTextColor('ffff6b5a');}
    c('pan_select').spec.props.align_top = [String(60+channelBottom+78+10)];
    c('pan_select').show();
    // the list frame fits ROWS_PER_PAGE slots: stretch the middle piece, move the bottom piece below the rows
    const rowsBottom = 32 + ROWS_PER_PAGE * ROW_H;
    c('pan_class_select2').setRect(0, 78, 236, rowsBottom - 78);
    c('pan_class_select3').setRect(0, rowsBottom, 236, 78);
    // slots
    this.rows = [];
    for (let k = 0; k < 9; k++) {
      const b = win.find(`character_list_btn_${k}`);
      if (!b) continue;
      win.find(`lbl_character_del_${k}`)?.hide();
      if (k >= ROWS_PER_PAGE) { b.hide(); continue; }
      b.onClick(() => { if (b.data.char) this.select(b.data.char.id); });
      b.onDoubleClick(() => { if (b.data.char) { this.select(b.data.char.id); this._enter(); } });
      this.rows.push(b);
    }
    c('btn_page_1').onClick(() => this._turnPage(-1));
    c('btn_page_2').onClick(() => this._turnPage(1));
    const standardMode = win.find('btn_sel_standard_mode');
    standardMode?.setChecked(true).onClick(() => standardMode.setChecked(true));
    win.find('btn_sel_arena_mode')?.setEnabled(false);
    // connect bar
    c('btn_delete_cancel').hide();
    c('btn_delete_char_confirm').hide();
    c('btn_connect').onClick(() => this._enter());
    for (const [id, dir] of [['btn_turn_left', 1], ['btn_turn_right', -1]]) {
      const b = c(id);
      b.on('down', () => { this._turn = dir; });
      b.on('up', () => { this._turn = 0; });
      b.on('out', () => { this._turn = 0; });
    }
    c('btn_create_char').onClick(() => this._create());
    c('btn_delete_char').onClick(() => this._confirmDelete());
    c('btn_exit').onClick(() => this._logout());
    // Native Character_4#4 card: server above the character name, not a duplicate slot description.
    c('lbl_select_msg').setRect(20,50,178,22);
    this.cardServer = cloneTemplate(win,'lbl_select_msg','lbl_select_server',[20,28,178,22]);
    this.cardServer?.setText(this.serverLabel || SERVER_LABEL).setTextColor('ff76f856');
    // Name the signed-in account (the original window has no account line).
    if (this.fe.account) {
      const line = this.accountLine = document.createElement('div');
      line.className = 'fe-account-line';
      line.textContent = `Account: ${this.fe.account}`;
      this.fe.ui.appendChild(line);
    }
  }

  _refresh() {
    const c = id => this.win.control(id);
    const page = this._pageChars();
    this.rows.forEach((b, k) => {
      const ch = page[k] || null;
      b.data.char = ch;
      if (!ch) { b.hide(); return; }
      b.setText(this._describe(ch));
      b.setChecked(ch.id === this.selectedId);
      b.show();
    });
    const pages = Math.max(1, Math.ceil(this.chars.length / ROWS_PER_PAGE));
    c('btn_page_1').setEnabled(this.page > 0);
    c('btn_page_2').setEnabled(this.page < pages - 1);
    const sel = this.selected;
    c('pan_select_char').setVisible(!!sel);
    c('pan_connect').setVisible(!!sel);
    c('btn_connect').setEnabled(!!sel&&Number.isInteger(this.selectedChannel)&&!this.channelError);
    c('btn_delete_char').setEnabled(!!sel);
    c('btn_create_char').setEnabled(this.chars.length < MAX_CHARACTERS);
    if (sel) c('lbl_select_msg').setText(playerNameplateName(sel.name,{staffTag:this.staffTag}));
  }

  select(id) {
    if (!id || id === this.selectedId) return;
    this.selectedId = id;
    const i = this.chars.findIndex(c => c.id === id);
    this.page = Math.floor(i / ROWS_PER_PAGE);
    this._refresh();
    this._showSelected();
  }

  selectChannel(index){
    if(!this.channels.some(row=>row.index===index&&row.available))return;
    this.selectedChannel=index;this.fe.selectedChannel=index;
    this.channelRows.forEach((button,i)=>{const selected=this.channels[i].index===index;button.setChecked(selected);button.el.setAttribute('aria-checked',String(selected));});
    this._refresh();
  }

  _turnPage(d) {
    const pages = Math.max(1, Math.ceil(this.chars.length / ROWS_PER_PAGE));
    const p = Math.max(0, Math.min(pages - 1, this.page + d));
    if (p === this.page) return;
    this.page = p;
    const first = this._pageChars()[0];
    if (first) this.select(first.id); else this._refresh();
  }

  // ---------------------------------------------------------------------------------------- input
  _wireInput() {
    const cv = this.stage.canvas;
    let down = null;
    const onDown = e => { if (e.button === 0 || e.button === 2) down = { x: e.clientX }; };
    const onMove = e => {
      if (!down) return;
      const m = this.model;
      if (m && m.loaded) m.yaw = m.yaw + (e.movementX || 0) * 0.012;
    };
    const onUp = () => { down = null; };
    const onKey = e => {
      if (this._modal || this._leaving || /INPUT|TEXTAREA/.test(document.activeElement?.tagName || '')) return;
      const i = this.chars.findIndex(c => c.id === this.selectedId);
      if (e.key === 'Enter') { e.preventDefault(); this._enter(); }
      else if (e.key === 'ArrowDown') { if (i < this.chars.length - 1) { this.fe.uim.sound(0); this.select(this.chars[i + 1].id); } }
      else if (e.key === 'ArrowUp') { if (i > 0) { this.fe.uim.sound(0); this.select(this.chars[i - 1].id); } }
      else if (e.key === 'Delete') this._confirmDelete();
    };
    cv.addEventListener('pointerdown', onDown);
    globalThis.addEventListener('pointermove', onMove);
    globalThis.addEventListener('pointerup', onUp);
    globalThis.addEventListener('keydown', onKey);
    this._unwire = () => {
      cv.removeEventListener('pointerdown', onDown);
      globalThis.removeEventListener('pointermove', onMove);
      globalThis.removeEventListener('pointerup', onUp);
      globalThis.removeEventListener('keydown', onKey);
    };
  }

  // ---------------------------------------------------------------------------------------- actions
  async _enter() {
    const c = this.selected;
    if (!c || this._leaving) return;
    if(this.channelError||!this.channels.some(row=>row.index===this.selectedChannel&&row.available)){void this.fe.messageBox(this.channelError||'Select an available server channel.');return;}
    this.fe.uim.sound(1);
    // FrontEnd verifies the account before opening this screen and again before
    // handoff. Character Connect no longer owns the PIN dialog.
    this._finish({ action: 'enter', character: c,channel:this.selectedChannel });
  }

  _create() {
    if (this._leaving) return;
    if (this.chars.length >= MAX_CHARACTERS) { this.fe.messageBox(rich(this.T.raw(30, 48))); return; }
    this._finish({ action: 'create' });
  }

  _logout() {
    if (this._leaving) return;
    this._finish({ action: 'logout' });
  }

  async _finish(res) {
    this._leaving = true;
    this._seq++;
    this._unwire?.();
    this._offFrame?.();
    const win = this.win;
    this.accountLine?.remove(); this.accountLine = null;
    this.fe.hideWindow(win).then(() => win.dispose());
    if (res.action !== 'enter') await this.fe.fade(1, 400, { over: true });
    if (this.model) this.stage.removeActor(this.model, true);
    this.model = null;
    this._resolve(res);
  }

  /** ui_deletecharwnd.txt: "Delete Character", the question, the name edit, Confirm / Cancel. */
  async _confirmDelete() {
    const ch = this.selected;
    if (!ch || this._modal || this._leaving) return;
    this._modal = true;
    const ui = this.fe.uim;
    const dlg = await ui.create('game2/ui_deletecharwnd.txt', { name: 'chardelete', modal: true, remember: false, disposeOnClose: true, autoClose: false });
    dlg.control('lbl_text').setRichText(`${rich(this.T.raw(30, 61))}\n<color=ffd98a>${ch.name}</color>`);
    const edit = dlg.find('edit_text');
    const close = () => { ui.closeWindow(dlg, 'no'); this._modal = false; };
    const yes = () => {
      const typed = String(edit?.getValue() || '').trim();
      if (typed.toLowerCase() !== String(ch.name).toLowerCase()) {
        edit?.setTextColor?.('ffff6b5a');
        if (edit?.input) edit.input.style.color = '#ff6b5a';
        edit?.focus();
        return;
      }
      close();
      void this._delete(ch, typed);
    };
    dlg.control('btn_yes').onClick(yes);
    dlg.control('btn_no').onClick(close);
    edit?.on('enter', yes);
    edit?.on('escape', close);
    edit?.on('change', () => { if (edit.input) edit.input.style.color = ''; });
    dlg.on('close', () => { this._modal = false; });
    ui.openWindow(dlg);
    setTimeout(() => edit?.focus(), 30);
  }

  /** An online character is deleted by the server (it was impossible before: "browser deletion is disabled"); a local one in the browser. */
  async _delete(ch, typedName = ch.name) {
    if (this._deleting) return;
    this._deleting = true;
    try { await deleteAccountCharacter(ch.id, typedName); }
    catch (err) { this._deleting = false; this.fe.messageBox(err.message); return; }
    this._deleting = false;
    if (this._leaving) return;
    const i = this.chars.findIndex(x => x.id === ch.id);
    this.chars = listCharacters();
    const pages = Math.max(1, Math.ceil(this.chars.length / ROWS_PER_PAGE));
    this.page = Math.min(this.page, pages - 1);
    this.selectedId = (this.chars[Math.min(i, this.chars.length - 1)] || null)?.id || null;
    this._refresh();
    this._showSelected();
  }
}
