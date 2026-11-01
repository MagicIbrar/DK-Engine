import {CHARACTER_NAME_MIN, CHARACTER_NAME_MAX, normalizeCharacterName, characterNameKey, characterNameCSS, configureCharacterNameInput, characterNameColorSelect} from '../../game/character-name.js';
import {applyFont} from '../uiwin/fonts.js';
// CHARACTER CREATE screen (its own screen, as in the original client).
//
// Scene: the class-select map of the chosen class (script/producer/char_selectinfo.txt: map 100..113 = the
// "<Class> Selection Map" maplist rows, the same as classes.json showcase.mapIndex). The class stands at `position`
// facing `direction`, scaled by `scale`, in its showcase outfit (classes.json showcase.parts, the _14 armour set) and
// loops the class-select STAND motion (anims.createPose). The camera is the file's eye (`cameratarget`) looking along
// horizon / vertical, with the map row's FOV. Dragging on the scene (or holding the arrow buttons) turns the model.
// Music: sound.json bgmSpecial.charSelect (bgm_charselect.mp3, the playlists of maps 100..113).
//
// Window: script/ui/game2/ui_classselectwnd.txt built by the UI platform (src/ui/uiwin):
//   letterbox; pan_class_title (class name); the left column pan_class_Bg with the Information / Preview tabs
//   (btn_class_info_tab / btn_equip_info_tab):
//     Information: pan_class_desc = stringtable_loginmsg 30:<class>, the class graph Character#65 (the overseas
//                  version of the radar background, English labels; the script's #64 is the Korean one) with the
//                  class shape Character#66.. at 52,52.
//     Preview:     btn_weapon_right / btn_armor / btn_weapon_left pick what list_itemlist shows - the class's weapons
//                  and armour sets of script/producer/char_iteminfo.txt (gamedata/frontend.json, set names =
//                  stringtable_loginmsg <cate> 31); picking one dresses the model, the item slots show the item's
//                  inventory model (the client's item icons are 3D models), and the camera moves to the
//                  char_previewinfo.txt close-up with the battle stance (target_style 1).
//   pan_class_select (right): one pan_char_list clone per class (2 x 8 grid of 87x77 buttons, portrait Character#49+i,
//   check #42 = the chosen class); pan_character_name: rotate buttons + name edit (init text 30:131);
//   btn_ok / btn_back. btn_exit / btn_server stay hidden (disabled in the script).
// Original name rules (the client's messages, 30:51 / 55 / 54 / 52 / 59): not empty, no spaces, alphanumeric only,
// no word of script/producer/filtering.txt, unique; 2..16 letters.
// Engine extension: 2..30 Unicode code points, normalized ordinary spaces, and a cosmetic name-color picker.
// The shared character policy overrides those historical length/space limits; account login rules are unchanged.
// Appearance: the client has no face / hair / colour options (characters.md: the helmet part holds face and hair);
// the Preview tab is the only appearance control of the original screen.
import { FrontCharacter } from './character.js';
import { updateOrbit } from '../../systems/items/weapon-orbit.js';
import { loadSelectInfo, loadPreviewInfo, selectCharYaw, classSceneInfo, previewView, frameView, rowCamHeight, CREATE_BAND } from './selectinfo.js';
import { rowFovDeg } from './stage.js';
import { cloneTemplate, rich } from './ui.js';
import { listCharacters, createAccountCharacter } from '../../game/save.js';
import { MAX_CHARACTERS } from './select.js';
import { fetchJSON, fetchText } from '../../engine/assets.js';
import { renderItemIcon } from './itemicon.js';

// Global creation reference pairs the original class with its alternate in each row.
export const CLASS_DISPLAY_ORDER = Object.freeze([0,7,1,8,2,9,3,10,4,11,5,12,6,13,14]);
export function orderedCreateClasses(classes) {
  const rank = new Map(CLASS_DISPLAY_ORDER.map((id,i)=>[id,i]));
  return [...classes].sort((a,b)=>(rank.get(Number(a.index))??999)-(rank.get(Number(b.index))??999));
}
export const PORTRAIT = i => (i >= 0 && i <= 14 ? 49 + i : 48);                           // Character#49.. (#48 silhouette)
export const GRAPH = i => (i >= 0 && i <= 12 ? 66 + i : i === 13 ? 88 : i === 14 ? 87 : null); // radar shapes
export const NAME_MIN = CHARACTER_NAME_MIN, NAME_MAX = CHARACTER_NAME_MAX;

// Backward-compatible export; both frontend screens use the same native camera correction.
export { classSceneInfo as createClassSceneInfo } from './selectinfo.js';

let filterWords = null;
/** script/producer/filtering.txt: words a character name may not contain. */
export function loadNameFilter() {
  if (!filterWords) {
    filterWords = fetchText('script/producer/filtering.txt', true)
      .then(t => t.split(/[\r\n,\t]+/).map(s => s.trim().toLowerCase()).filter(s => s && !/^[#/]/.test(s) && s.length >= 2))
      .catch(() => []);
  }
  return filterWords;
}

/**
 * Validate a new character name. Returns null when valid, else {code, text, word?} of the client's message
 * (stringtable_loginmsg 30:51 empty, 30:55 spaces, 30:54 not alphanumeric, 30:52 a filtered word, 30:59 taken)
 * or a length message.
 */
export function validateName(name, existing = [], filter = []) {
  let n;try { n=normalizeCharacterName(name); } catch(error) { return {code:null,text:error.message}; }
  const low = characterNameKey(n);
  const bad = filter.find(w => /^[a-z0-9]+$/.test(w) && low.includes(w));
  if (bad) return { code: 52, text: `The word ${bad} cannot be used.`, word: bad };
  if (existing.some(c => characterNameKey(c.name) === low)) return { code: 59, text: 'This name is already in use.' };
  return null;
}

export class CreateScreen {
  constructor(fe) {
    this.fe = fe;
    this.stage = fe.stage;
    this.T = fe.texts;
    this.classIndex = 0;
    this.model = null;
    this._seq = 0;
    this._turn = 0;
    this.tab = 'info';
    this.equipMode = 'armor';                 // which list the Preview tab shows: 'right' | 'armor' | 'left'
    this.pick = { right: null, armor: null, left: null };
  }

  /** @returns {Promise<{action:'created'|'back', character?:object}>} */
  async run() {
    const fe = this.fe;
    this.classes = await fe.classes();
    [this.info, this.pinfo, this.previewData] = await Promise.all([
      loadSelectInfo(), loadPreviewInfo(), fetchJSON('/gamedata/frontend.json').catch(() => ({ classes: {} })), loadNameFilter(),
    ]);
    this.classIndex = Number(this.classes[0]?.index) || 0;
    await fe.fade(1, 400, { over: true });
    fe.busy(true);
    this.stage.clearActors();
    await this._buildUI();
    this._wireInput();
    this._offFrame = this.stage.onFrame(dt => this._frame(dt));
    const sceneReady = await this._showClass(this.classIndex, { initial: true });
    if (sceneReady !== false) await fe.finishPreload();
    fe.busy(false);
    fe.showWindow(this.win);
    this._fitClassList();
    await fe.fade(0, 500, { over: true });
    setTimeout(() => this.nameEdit?.focus(), 50);
    return new Promise(resolve => { this._resolve = resolve; });
  }

  get classDef() { return this.classes.find(c => Number(c.index) === this.classIndex) || null; }
  get equipData() { return this.previewData?.classes?.[this.classIndex] || { sets: [], weapons: [] }; }

  // ---------------------------------------------------------------------------------------- scene
  /** Stage a class: its select map (loaded when different), the showcase model, the camera. */
  async _showClass(index, { initial = false } = {}) {
    const seq = ++this._seq;
    const def = this.classes.find(c => Number(c.index) === Number(index));
    if (!def) return;
    this._sceneReady = false;
    this.classIndex = Number(index);
    this.pick = { right: null, armor: null, left: null };
    this._refreshUI();
    const si = classSceneInfo(this.info.get(this.classIndex) || null);
    const mapIndex = Number(si?.mapIndex ?? def.showcase?.mapIndex ?? 100);
    const stage = this.stage, fe = this.fe;
    const mapChange = stage.worldIndex !== mapIndex;
    // Rapid class changes supersede each other (see SelectScreen._showSelected): the newest call fades back in whoever
    // started the fade, whatever its own `mapChange` says.
    if (mapChange && !initial) { this._faded = true; await fe.fade(1, 300); fe.busy(true); }
    if (seq !== this._seq) return;
    const ch = FrontCharacter.showcase(stage, def, { scale: Number(si?.scale) || Number(def.showcase?.scale) || 1, standDuration: si?.stand });
    ch.group.visible = false;
    try {
      await Promise.all([stage.loadWorld(mapIndex, { focus: si ? { x: si.x, z: si.z } : null }), ch.load().then(() => ch.readyPose('createPose'))]);
    } catch (err) {
      console.warn('[frontend] class scene failed', err);
      ch.dispose();
      if (seq !== this._seq) return false;
      this._sceneFailed = true;
      fe.busy(false);
      if (this._faded) { this._faded = false; fe.fade(0, 400); }
      if (fe.preload) fe.preload.fail(err);
      else void fe.messageBox('This class preview could not finish loading. Select the class again to retry, or choose another class.');
      return false;
    }
    if (seq !== this._seq) { ch.dispose(); return; }
    if (this.model) stage.removeActor(this.model, true);
    this.model = ch;
    this.si = si;
    this.fov = rowFovDeg(fe.data.mapByIndex(mapIndex));
    this.camH = rowCamHeight(fe.data.mapByIndex(mapIndex));
    if (si) {
      ch.standCap = si.eye.y + 1.2;
      ch.place(si.x, si.z, selectCharYaw(si));
    }
    stage.addActor(ch);
    // feet on the drawn stage floor (showcase scale), and the posed bounds the camera frames
    this.body = si ? ch.standOnFloor('createPose') : null;
    ch.group.visible = true;
    this._applyView(true);
    fe.playBGM('charSelect', mapIndex);
    this._sceneReady = true; this._sceneFailed = false;
    if (this._faded && !initial) { this._faded = false; fe.busy(false); fe.fade(0, 400); }
    return true;
  }

  /** Information tab: the class-select view and STAND motion; Preview tab: the char_previewinfo close-up. */
  _applyView(snap = false) {
    const ch = this.model, si = this.si;
    if (!ch || !si) return;
    if (this.tab === 'preview') {
      const pi = this.pinfo.get(this.classIndex) || this.pinfo.get(0);
      const v = previewView(si, pi, ch.y + (ch.feetAdjust || 0), ch.scale, this.fov);
      this._want = v;
      const battle = Number(pi?.targetStyle) === 1;
      ch.frontRest = battle ? 'idleCombat' : 'createPose';
    } else {
      // the original framing: file anchor + maplist Camera_Height, the whole posed body inside the letterbox with
      // head and foot room (selectinfo.js frameView)
      const body = this.body || { x: ch.x, z: ch.z, bottom: ch.y, top: ch.y + ch.height * ch.scale };
      this._want = { ...frameView(si, body, this.fov, this.camH, { band: CREATE_BAND }), yaw: selectCharYaw(si) };
      ch.frontRest = 'createPose';
    }
    if (snap) ch.yaw = this._want.yaw;
    ch.play(ch.frontRest);
    if (snap || !this._view) this._view = JSON.parse(JSON.stringify(this._want));
    this._glideYaw = snap ? null : this._want.yaw;
  }

  _frame(dt) {
    const m = this.model;
    if (m && m.loaded && this._turn) { m.yaw = m.yaw + this._turn * dt * 2.4; this._glideYaw = null; }
    // Black Wizard orbs keep their in-game battle stand orbit in the class scene (see select.js _frame; items/weapon-orbit.js)
    if (m && m.loaded) updateOrbit(m, dt, { force: true });
    if (m && m.loaded && this._glideYaw != null) {
      const d = Math.atan2(Math.sin(this._glideYaw - m.yaw), Math.cos(this._glideYaw - m.yaw));
      if (Math.abs(d) < 1e-3) this._glideYaw = null; else m.yaw = m.yaw + d * (1 - Math.exp(-dt * 5));
    }
    const w = this._want, v = this._view;
    if (w && v) {
      const k = 1 - Math.exp(-dt * 4);
      for (const p of ['eye', 'target']) for (const a of ['x', 'y', 'z']) v[p][a] += (w[p][a] - v[p][a]) * k;
      v.fov += (w.fov - v.fov) * k;
      this.stage.lookFrom(v.eye, v.target, v.fov);
    }
  }

  // ---------------------------------------------------------------------------------------- window
  async _buildUI() {
    const win = this.win = await this.fe.uim.create('game2/ui_classselectwnd.txt', { name: 'class_select', escClose: false, remember: false, autoClose: false });
    win.el.classList.add('fe-global-front');
    const c = id => win.control(id);
    // Information / Preview tabs
    c('btn_class_info_tab').onClick(() => this._tab('info'));
    c('btn_equip_info_tab').onClick(() => this._tab('preview'));
    c('pan_graph_bg').setSprite('Character', 65);
    // the client draws a window's controls in one flat `layer` order: the Preview tab's buttons (130) and item slots
    // (140) sit inside pan_equip_list (layer 90) but above the equipment background pan_class_select_bg2 (120)
    const eqList = win.find('pan_equip_list');
    if (eqList) eqList.el.style.zIndex = '121';
    // Preview tab buttons + list
    c('btn_weapon_right').onClick(() => this._equipMode('right'));
    c('btn_armor').onClick(() => this._equipMode('armor'));
    c('btn_weapon_left').onClick(() => this._equipMode('left'));
    this.list = win.find('list_itemlist');
    this.list?.on('select', (i, it) => this._pickItem(it?.data));
    // the class grid: one clone of the pan_char_list template per class
    this.clsBtns = [];
    orderedCreateClasses(this.classes).forEach((cl, k) => {
      const idx = Number(cl.index);
      const pan = cloneTemplate(win, 'pan_char_list', `pan_char_list_${idx}`, [11 + (k % 2) * 87, 50 + Math.floor(k / 2) * 77, 87, 77]);
      if (!pan) return;
      pan.control('pan_char_draw')?.setSprite('Character', PORTRAIT(idx));
      const btn = pan.control('btn_list');
      if (!btn) return;
      btn.setTooltip(cl.name);
      btn.onClick(() => {
        if (idx !== this.classIndex || this._sceneFailed) this._showClass(idx);
        this._paintClasses();
      });
      this.clsBtns.push({ idx, btn });
    });
    // name box
    this.nameEdit = win.find('edit_text');
    if (this.nameEdit) this.nameEdit.inputType=0;
    configureCharacterNameInput(this.nameEdit?.input);
    const colorParent=win.find('pan_character_name');
    if(colorParent?.el) {
      this.nameColorSelect=characterNameColorSelect();applyFont(this.nameColorSelect,2);
      Object.assign(this.nameColorSelect.style,{position:'absolute',left:'76px',top:'56px',width:'153px',height:'22px',pointerEvents:'auto',background:'#17130f',border:'1px solid #6a5630',color:'#fff'});
      this.nameColorSelect.addEventListener('change',()=>{if(this.nameEdit?.input)this.nameEdit.input.style.color=characterNameCSS(this.nameColorSelect.value);});
      this.nameColorSelect.addEventListener('pointerdown',e=>e.stopPropagation());colorParent.el.appendChild(this.nameColorSelect);
    }
    this.nameEdit?.on('enter', () => this._ok());
    this.nameEdit?.on('escape', () => this._back());
    for (const [id, dir] of [['btn_turn_left', 1], ['btn_turn_right', -1]]) {
      const b = c(id);
      b.on('down', () => { this._turn = dir; });
      b.on('up', () => { this._turn = 0; });
      b.on('out', () => { this._turn = 0; });
    }
    c('btn_ok').onClick(() => this._ok());
    c('btn_back').onClick(() => this._back());
    c('btn_exit').show(); c('btn_exit').setEnabled(true);
    c('btn_exit').onClick(() => { if (!this._leaving) this._finish({ action: 'logout' }); });
    c('btn_server').hide();
    c('pan_classname').hide();
    this._tab('info', true);
  }

  /**
   * Every class must be visible and clickable. The script's class grid (pan_class_select at top 66,
   * rows of 77 px from 50) holds 8 rows for 15 classes and reaches y 732, while btn_ok / btn_back (bottom -40) and
   * the lower letterbox bar start at ~688: on a 768-px-high screen - which the scaled UI always is - the 8th row (the
   * 15th class) lies under them. The whole panel is scaled down, anchored at its top-right corner (no distortion), just
   * enough for the last class button to clear them.
   */
  _fitClassList(tries = 0) {
    const win = this.win;
    const panel = win?.find('pan_class_select')?.el;
    const last = this.clsBtns?.[this.clsBtns.length - 1]?.btn?.el;
    const blockers = ['btn_ok', 'btn_back', 'pan_widebackdown_1'].map(id => win?.find(id)?.el).filter(Boolean);
    if (!panel || !last || !blockers.length) return;
    panel.style.transform = '';
    const pr = panel.getBoundingClientRect(), lr = last.getBoundingClientRect();
    if (!(pr.height > 0 && lr.height > 0)) {                        // not laid out yet
      if (tries < 30) setTimeout(() => this._fitClassList(tries + 1), 50);
      return;
    }
    const tops = blockers.map(el => el.getBoundingClientRect()).filter(r => r.height > 0 && r.right > pr.left).map(r => r.top);
    if (!tops.length) return;
    const room = Math.min(...tops) - 3 - pr.top, need = lr.bottom - pr.top;
    if (!(room > 0) || need <= room) return;
    panel.style.transformOrigin = 'right top';
    panel.style.transform = `scale(${(room / need).toFixed(4)})`;
  }

  _paintClasses() {
    for (const { idx, btn } of this.clsBtns) btn.setChecked(idx === this.classIndex);
  }

  _tab(which, quiet = false) {
    this.tab = which;
    const c = id => this.win.control(id);
    c('btn_class_info_tab').setChecked(which === 'info');
    c('btn_equip_info_tab').setChecked(which === 'preview');
    c('pan_class_info').setVisible(which === 'info');
    c('pan_equip_info').setVisible(which === 'preview');
    if (which === 'preview') this._fillList();
    if (!quiet) this._applyView(false);
  }

  _refreshUI() {
    const def = this.classDef;
    if (!def || !this.win) return;
    const c = id => this.win.control(id);
    c('lbl_class_name').setText(def.name);
    this._paintClasses();
    const desc = this.win.find('pan_class_desc');
    if (desc) {
      // the client's class texts are broken into lines by hand for its own Tahoma: keep those lines (no re-wrap);
      // a line a few pixels wider than the 187-px box stays inside the 260-px column
      if (desc.content) desc.content.style.whiteSpace = 'pre';
      if (desc.view) desc.view.style.overflow = 'visible';
      desc.clear?.();
      desc.setText?.(rich(this.T.raw(30, this.classIndex, '')));
    }
    const shape = GRAPH(this.classIndex);
    if (shape != null) c('pan_graph').setSprite('Character', shape);
    this._updateEquipLabels();
    this._paintSlots();
    if (this.tab === 'preview') this._fillList();
  }

  // ---------------------------------------------------------------------------------------- preview tab
  _equipMode(mode) {
    this.equipMode = mode;
    this._fillList();
  }

  _entries(mode) {
    const D = this.equipData;
    if (mode === 'armor') return D.sets.map(s => ({ kind: 'armor', set: s, text: this.T.get(31, s.id, s.name || `Set ${s.id}`) }));
    return D.weapons.filter(w => w.hand === mode).map(w => ({ kind: mode, weapon: w, text: w.name }));
  }

  _fillList() {
    const c = id => this.win.control(id);
    for (const [id, m] of [['btn_weapon_right', 'right'], ['btn_armor', 'armor'], ['btn_weapon_left', 'left']]) c(id).setChecked(this.equipMode === m);
    const items = this._entries(this.equipMode);
    const cur = this.pick[this.equipMode];
    const sel = items.findIndex(it => (it.set && cur?.set === it.set) || (it.weapon && cur?.weapon === it.weapon));
    this.list?.setItems(items.map(it => ({ text: it.text, data: it })));
    this.list?.setTop?.(0);
    this.list?.select(sel);
  }

  _updateEquipLabels() {
    const c = id => this.win.control(id);
    const r = this.pick.right?.weapon;
    c('lbl_equip_right').setText(this.T.get(30, r && r.hands >= 2 ? 206 : 204, r && r.hands >= 2 ? 'Both Hands' : 'Right-handed'));
    c('lbl_equip_armor').setText(this.T.get(30, 207, 'Armor'));
    c('lbl_equip_left').setText(this.T.get(30, 205, 'Left-handed'));
  }

  async _pickItem(it) {
    if (!it) return;
    const mode = it.kind;
    this.pick[mode] = it;
    if (mode === 'right' && it.weapon.hands >= 2) this.pick.left = null;   // two-handed: the left hand is taken
    if (mode === 'left' && (this.pick.right?.weapon?.hands || 1) >= 2) this.pick.right = null;
    this._updateEquipLabels();
    this._paintSlots();
    const m = this.model;
    if (!m) return;
    const parts = this.pick.armor ? this.pick.armor.set.parts : null;
    const weapons = (this.pick.right || this.pick.left) ? { right: this.pick.right?.weapon || null, left: this.pick.left?.weapon || null } : null;
    await m.setPreview({ parts, weapons });
    if (this.tab === 'preview') this._applyView(false);
  }

  /** The three item slots show the inventory model of what is picked (the armour slot: the set's coat). */
  _paintSlots() {
    const slots = [
      ['item_weapon_right', this.pick.right?.weapon?.inv],
      ['item_weapon_armor', this.pick.armor?.set?.items?.coat?.inv || this.pick.armor?.set?.items?.helmet?.inv],
      ['item_weapon_left', this.pick.left?.weapon?.inv],
    ];
    for (const [id, inv] of slots) {
      const ctl = this.win.find(id);
      if (!ctl) continue;
      const seq = (ctl.data.iconSeq = (ctl.data.iconSeq || 0) + 1);
      if (!inv) { ctl.setIcon(null); continue; }
      const r = ctl.spec.rect || [0, 0, 63, 117];
      renderItemIcon(this.stage, inv, r[2] || 63, r[3] || 117).then(url => {
        if (seq === ctl.data.iconSeq) ctl.setIcon(url ? { url } : null);
      });
    }
  }

  // ---------------------------------------------------------------------------------------- input
  _wireInput() {
    const cv = this.stage.canvas;
    let down = null;
    const onDown = e => { if (e.button === 0 || e.button === 2) { down = { x: e.clientX }; this._glideYaw = null; } };
    const onMove = e => {
      if (!down) return;
      const m = this.model;
      if (m && m.loaded) m.yaw = m.yaw + (e.movementX || 0) * 0.012;
    };
    const onUp = () => { down = null; };
    const onKey = e => {
      if (this._leaving || this.fe.uim.modalOpen || /INPUT|TEXTAREA/.test(document.activeElement?.tagName || '')) return;
      if (e.key === 'Escape') this._back();
      else if (e.key === 'Enter') this._ok();
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
  async _ok() {
    if (this._leaving || this.fe.uim.modalOpen) return;
    if (this._sceneReady === false) { this.fe.messageBox('Wait for the class preview to finish loading. If it failed, select the class again to retry.'); return; }
    const def = this.classDef;
    if (!def) return;
    const existing = listCharacters();
    if (existing.length >= MAX_CHARACTERS) { this.fe.messageBox(rich(this.T.raw(30, 48))); return; }
    const name = String(this.nameEdit?.getValue() || '');
    const err = validateName(name, existing, await loadNameFilter());
    if (err) {
      let text = err.code != null ? rich(this.T.raw(30, err.code, err.text)) : err.text;
      if (err.word) text = text.replace('%s', err.word);
      this.fe.messageBox(text, () => this.nameEdit?.focus());
      return;
    }
    this.fe.uim.sound(1);
    try {
      const options = { name:normalizeCharacterName(name), nameColor:this.nameColorSelect?.value||'white', classIndex: Number(def.index), className: def.name };
      const account = await this.fe.accounts.restore();
      if (!account || account !== this.fe.account) throw new Error('Your account session changed or expired. Log in again before creating a character.');
      const character = await createAccountCharacter(options);
      this._finish({ action: 'created', character });
    } catch (err) { this.fe.messageBox(err.message); }
  }

  _back() {
    if (this._leaving) return;
    this._finish({ action: 'back' });
  }

  _finish(res) {
    this._leaving = true;
    this._seq++;
    this._unwire?.();
    const win = this.win;
    this.fe.hideWindow(win).then(() => win.dispose());
    this.fe.fade(1, 400, { over: true }).then(() => {
      this._offFrame?.();
      if (this.model) this.stage.removeActor(this.model, true);
      this.model = null;
      this._resolve(res);
    });
  }
}
