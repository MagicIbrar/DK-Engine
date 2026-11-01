import { nameDisplayPatch, NAME_DISPLAY_KEYS } from './name-display-options.js';
// The Option window (script/ui/game2/option/ui_optionwnd.txt, 470x556, option_2 art) with every original tab:
// Graphics, Game, Battle Setting, Sound, View, Change Controls (opens the key map window in its place) and
// Chatting. The controls edit a working copy; OK applies and closes, Apply applies, Cancel / x / Esc discard.
// Every control is bound to an OptionStore key (settings.js) whose real effect lives in apply.js or in the system
// that owns the feature (game.options.get(key)).
import { QUALITY, FRAME_LIMITS, UNIMPLEMENTED_OPTIONS } from './settings.js';
import { DISPLAY_MODES } from './apply.js';
import { bindingName } from './keymap.js';
import { str, plainMarkup, clamp } from './util.js';

const TABS = { btn_screen: 'pan_screen', btn_game: 'pan_game', btn_combat: 'pan_combat', btn_sound: 'pan_sound', btn_see: 'pan_see', btn_chat: 'pan_chat' };

const CHECKS = {
  check_winmode: 'winmode', check_cloud: 'cloud', check_specular: 'specular', check_bump: 'bump', check_blood: 'blood',
  check_quake: 'quake', check_bloom: 'bloom', check_swimming_effect: 'swimming', check_reflect_tile: 'reflectTile', check_smartwarp: 'smartwarp',
  check_mp3: 'mp3', check_nosound: 'bgmMute', check_no_ambient: 'ambientMute', check_no_skillsound: 'skillSoundMute',
  check_no_servant: 'servantMute', check_noeffect: 'effectMute',
  check_trade: 'blockTrade', check_party: 'blockParty', check_guild: 'blockGuild', check_friend: 'blockFriend', check_pvp: 'blockPvp',
  check_partypvp: 'blockPartyPvp', check_alliance: 'blockAlliance', check_revive: 'rejectRevive',
  check_partyuiopen: 'partyUiOpen',
  check_itemstack_quest: 'stackQuestReward', check_dropmsg: 'dropMsg', check_runemsg: 'runeMsg', check_pricemsg: 'priceMsg',
  check_showalignmentmsg: 'sortMsg', check_presetmsg: 'presetMsg', check_presetblickicon: 'presetBlinkIcon', check_presetchangecallpet: 'presetCallPet',
  check_server: 'showServer', check_reception: 'showReception', check_showcostume: 'showCostume', check_showwing: 'showWing',
  save_camera_stock: 'saveCamera', check_charname: 'charName', check_guildname: 'guildName', check_aliancename: 'allianceName',
  check_titlename: 'titleName', check_ratingname: 'ratingName', check_allshow: 'allShow',
  check_not_extedition: 'notExpedition', check_not_guild: 'notGuild', check_not_friend: 'notFriend', check_not_general: 'notGeneral',
  check_selftarget: 'selfTarget', check_dksquareautoenter: 'dkAutoEnter', check_siegeautoforceattack: 'siegeForceAttack',
  check_autodrink: 'autoPotion', check_autorevive: 'autoRevive',
  check_alwaysontop: 'chatOnTop', check_chatfixed: 'chatMovable', check_extrafeatures: 'chatExtra',
  check_chatwnd_normal: 'chatNormal', check_chatwnd_world: 'chatWorldMatch', check_chatwnd_party: 'chatParty', check_chatwnd_guild: 'chatGuild',
  check_chatwnd_shout: 'chatShout', check_chatwnd_whisper: 'chatWhisper', check_chatwnd_guildleader: 'chatOfficer',
  check_chatwnd_alliance: 'chatAlliance', check_chatwnd_allworldchat: 'chatWorld',
};
/** Radio groups: key -> [control ids in value order]. */
const RADIOS = {
  controlType: ['check_control_0', 'check_control_1'],
  captionBar: ['check_captionbar_white', 'check_captionbar_dark'],
  damageFont: ['check_damage_font_0', 'check_damage_font_1', 'check_damage_font_2', 'check_damage_font_3'],
};
const SLIDERS = {
  sld_gamma: 'gamma', sld_bloom: 'bloomLevel', sld_sound: 'bgm', sld_ambient: 'ambient', sld_skillsound: 'skillSound',
  sld_servant: 'servant', sld_effect: 'effect', sld_hp: 'hpLimit', sld_mp: 'mpLimit', sld_chatwnd_alpha: 'chatAlpha', sld_syswnd_alpha: 'sysAlpha',
};
const COMBOS = {
  com_trace: 'trace', com_shadow: 'shadow', com_water: 'water', com_background_frame: 'bgFrame', com_frame_limit: 'frameLimit',
  com_quake_option: 'quakeOption', com_damage: 'damageView', com_effect: 'effectView', com_show_chatmsg_chattype: 'chatType',
};
/** Chat window size steps (lbl value) and font sizes the +/- buttons walk through. */
export const CHAT_SIZES = [1, 2, 3, 4, 5, 6];
export const CHAT_FONTS = [1, 2, 3, 4, 5];

export function registerOptionWindow(game, ctx) {
  const store = ctx.options;
  game.uiwin.registerWindow('options', {
    script: 'game2/option/ui_optionwnd.txt',
    create(win) {
      const d = win.data;
      d.draft = { ...store.all() };
      d.tab = 'btn_screen';
      const set = (k, v) => {
        Object.assign(d.draft, nameDisplayPatch(d.draft, k, v));
        if (k === 'allShow' || NAME_DISPLAY_KEYS.includes(k)) {
          for (const [id, key] of Object.entries(CHECKS)) if (key === 'allShow' || NAME_DISPLAY_KEYS.includes(key)) win.control(id).setChecked(!!d.draft[key]);
        }
        refreshDependent();
      };
      // Reuse the original View-tab control art in its free right column.
      const view = win.control('pan_see');
      // The translated native captions can exceed their authored rectangles.
      // Keep them inside the left column beside the gameplay camera controls.
      win.control('lbl_charname').setRect(21, 220, 130, 14).setClip(true).setTooltip(plainMarkup(str(2001, 92)));
      win.control('lbl_charnamekey').setRect(157, 220, 89, 14).setClip(true);
      for (const id of ['check_charname', 'check_guildname', 'check_aliancename', 'check_titlename', 'check_ratingname', 'check_allshow']) {
        win.control(id).setClip(true);
      }
      win.control('lbl_title_show').cloneAs('_camera', { parent: view, x: 250, y: 145 })
        .setRect(250, 145, 200, 14).setText('Gameplay camera');
      const firstPerson = win.control('save_camera_stock').cloneAs('_firstperson', { parent: view, x: 250, y: 160 })
        .setRect(250, 160, 200, 20).setText('First-person view');
      firstPerson.on('change', v => set('cameraMode', v ? 'first-person' : 'third-person'));
      win.control('lbl_title_show').cloneAs('_fov', { parent: view, x: 250, y: 189 })
        .setRect(250, 189, 200, 14).setText('First-person field of view');
      const fov = win.control('com_damage').cloneAs('_fov', { parent: view, x: 250, y: 209 }).setRect(250, 209, 144, 20);
      fov.setItems([50, 60, 70, 80, 90, 100].map(value => ({ text: `${value} degrees`, value })));
      fov.on('change', (i, item) => set('firstPersonFov', item?.value ?? 70));
      for (const [i, text] of ['Hold right mouse to look.', 'WASD moves; arrows look.', 'Right Alt: GM free camera.'].entries()) {
        win.control('lbl_title_show').cloneAs(`_camera_help_${i}`, { parent: view, x: 250, y: 244 + i * 18 })
          .setRect(250, 244 + i * 18, 200, 16).setText(text).setTextColor('ffffffff').setFont(2);
      }
      const cameraKey = win.control('lbl_title_show').cloneAs('_camera_key', { parent: view, x: 250, y: 305 })
        .setRect(250, 305, 200, 36).setTextColor('ffffffff').setFont(2).setClip(true);
      cameraKey.spec.props.multiline = ['TRUE'];

      // tabs
      for (const btn of Object.keys(TABS)) win.control(btn).onClick(() => showTab(btn));
      win.control('btn_keymap_tab').onClick(() => openKeymap());
      win.control('btn_keymap').onClick(() => openKeymap());
      function showTab(btn) {
        d.tab = btn;
        for (const [b, p] of Object.entries(TABS)) { win.control(b).setChecked(b === btn); win.control(p).setVisible(b === btn); }
        win.control('btn_keymap_tab').setChecked(false);
      }
      async function openKeymap() {
        const pos = { x: win.box.x, y: win.box.y };
        const km = await game.uiwin.get('keymap');
        km.setPosition(pos.x, pos.y, false);
        win.data.keepDraft = true;
        win.close('keymap');
        km.data.returnTo = () => { game.uiwin.open('options'); };
        game.uiwin.open('keymap');
      }

      // checkboxes
      for (const [id, k] of Object.entries(CHECKS)) {
        const control = win.control(id);
        if (UNIMPLEMENTED_OPTIONS.includes(k)) control.setEnabled(false).setTooltip('This preference is not implemented in this client yet.');
        else control.on('change', v => set(k, !!v));
      }
      for (const [k, ids] of Object.entries(RADIOS)) ids.forEach((id, i) => win.control(id).on('click', () => {
        ids.forEach((o, j) => win.control(o).setChecked(j === i));
        set(k, i);
      }));
      // sliders
      for (const [id, k] of Object.entries(SLIDERS)) win.control(id).on('change', v => set(k, Math.round(v)));
      // combos
      for (const [id, k] of Object.entries(COMBOS)) win.control(id).on('change', i => set(k, i));
      const disp = win.control('com_display');
      disp.on('change', (i, it) => set('resolution', it?.value ?? 'native'));
      // quality presets
      const QB = { btn_levelgood: 'good', btn_levelaverage: 'average', btn_levelpoor: 'poor' };
      for (const [id, q] of Object.entries(QB)) win.control(id).onClick(() => {
        Object.assign(d.draft, QUALITY[q], { quality: q });
        load(d.draft);
      });
      // chat sizes
      const step = (k, list, dir) => { const i = list.indexOf(Number(d.draft[k])); set(k, list[clamp((i < 0 ? 2 : i) + dir, 0, list.length - 1)]); };
      win.control('btn_chatwnd_wndsize_up').onClick(() => step('chatSize', CHAT_SIZES, 1));
      win.control('btn_chatwnd_wndsize_down').onClick(() => step('chatSize', CHAT_SIZES, -1));
      win.control('btn_chatwnd_fontsize_up').onClick(() => step('chatFont', CHAT_FONTS, 1));
      win.control('btn_chatwnd_fontsize_down').onClick(() => step('chatFont', CHAT_FONTS, -1));
      win.control('btn_syswnd_wndsize_up').onClick(() => step('sysSize', CHAT_SIZES, 1));
      win.control('btn_syswnd_wndsize_down').onClick(() => step('sysSize', CHAT_SIZES, -1));
      win.control('btn_chatcolor').onClick(() => game.uiwin.open('chatcolor', { type: d.draft.chatType, onApply: (colors) => set('chatColors', colors), colors: d.draft.chatColors }));
      win.control('btn_chatcolorrestore').onClick(() => set('chatColors', null));

      // OK / Apply / Cancel
      win.control('btn_apply').onClick(() => apply());
      win.control('btn_ok').onClick(() => { apply(); win.close('ok'); });
      win.control('btn_cancel').onClick(() => win.close('cancel'));

      function apply() {
        const prevRes = store.get('resolution');
        store.set({ ...d.draft });
        if (prevRes !== d.draft.resolution && !String(d.draft.resolution).startsWith('native')) {
          // the client's windowed-mode note (2001:78) when the mode is larger than the desktop
          const m = /^(\d+)x(\d+)$/.exec(d.draft.resolution);
          // (>=: the desktop's own size only fits as full screen; the window keeps its size, DekaronClient.cs Fits)
          if (m && d.draft.winmode && (Number(m[1]) >= screen.width || Number(m[2]) >= screen.height)) ctx.chat?.system(str(2001, 78));
        }
      }

      function refreshDependent() {
        const D = d.draft;
        // HP / MP auto potion thresholds (2001:43 "Auto-use if below [BLINK]")
        const tpl = str(2001, 43) || 'Auto-use if below [BLINK]';
        win.control('lbl_hpLimit').setText(`HP ${tpl.replace('[BLINK]', `${D.hpLimit}%`)}`);
        win.control('lbl_mpLimit').setText(`MP ${tpl.replace('[BLINK]', `${D.mpLimit}%`)}`);
        win.control('lbl_chatwnd_wndsize_value').setText(String(D.chatSize));
        win.control('lbl_chatwnd_fontsize_value').setText(String(D.chatFont));
        win.control('lbl_syswnd_wndsize_value').setText(String(D.sysSize));
        for (const [id, q] of Object.entries(QB)) win.control(id).setChecked(D.quality === q);
        // These four preferences are consumed by playerNameplateDetails in the HUD.
        for (const id of ['check_guildname', 'check_aliancename', 'check_titlename', 'check_ratingname']) {
          win.control(id).setEnabled(true);
        }
        win.control('check_allshow').setEnabled(true);
        win.control('sld_bloom').setEnabled(!!D.bloom);
        win.control('sld_hp').setEnabled(!!D.autoPotion); win.control('sld_mp').setEnabled(!!D.autoPotion);
      }

      function load(D) {
        D.allShow = NAME_DISPLAY_KEYS.every(key => D[key] === true) && Number(D.nameView) === 0;
        firstPerson.setChecked(D.cameraMode === 'first-person');
        fov.selectValue(Number(D.firstPersonFov) || 70);
        cameraKey.setRichText(`Toggle view: ${bindingName(ctx.keymap.get('cameraView'))}\nChange Controls to rebind.`);
        for (const [id, k] of Object.entries(CHECKS)) win.control(id).setChecked(!!D[k]);
        for (const [k, ids] of Object.entries(RADIOS)) ids.forEach((id, i) => win.control(id).setChecked(Number(D[k]) === i));
        for (const [id, k] of Object.entries(SLIDERS)) win.control(id).setValue(Number(D[k]) || 0);
        for (const [id, k] of Object.entries(COMBOS)) win.control(id).select(Number(D[k]) || 0);
        fillDisplay(D.resolution);
        // short-key captions (<keyname>)
        const kn = (id) => bindingName(ctx.keymap.get(id));
        win.control('lbl_charnamekey').setText(plainMarkup(str(2001, 86)).replace('<keyname>', kn('names')));
        win.control('check_control_0').setText(plainMarkup(str(2001, 81)).replace('<keyname>', kn('controlA')));
        win.control('check_control_1').setText(plainMarkup(str(2001, 82)).replace('<keyname>', kn('controlB')));
        refreshDependent();
      }
      function fillDisplay(cur) {
        const vw = innerWidth, vh = innerHeight;
        const items = [{ text: `${vw} x ${vh}`, value: 'native' }];
        for (const [w, h] of DISPLAY_MODES) if (w <= Math.max(screen.width, vw) && h <= Math.max(screen.height, vh)) items.push({ text: `${w} x ${h}`, value: `${w}x${h}` });
        if (cur && cur !== 'native' && !items.some(i => i.value === cur)) { const [w, h] = cur.split('x'); items.push({ text: `${w} x ${h}`, value: cur }); }
        disp.setItems(items);
        disp.selectValue(cur || 'native');
      }
      d.load = load;
      d.showTab = showTab;
      // the frame-limit list shows the script's own captions; keep their order in sync with FRAME_LIMITS
      if (win.control('com_frame_limit').items?.length !== FRAME_LIMITS.length) console.warn('[hud-options] frame limit list size differs from the script');
    },
    onOpen(win) {
      const d = win.data;
      if (!d.keepDraft) d.draft = { ...store.all() };
      d.keepDraft = false;
      d.load(d.draft);
      d.showTab(d.tab || 'btn_screen');
    },
    onClose(win, result) {
      if (result === 'keymap') return;
      win.data.draft = { ...store.all() };
    },
  });
}
