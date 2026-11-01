// Equipment preset HUD pieces and the Game tab's preset options (the presets themselves belong to the items system:
// game.items.setPreset(i), save.equip.active 0..4):
//   hud_presetmini   game2/inven/ui_presetmini_icon.txt   the current preset under the minimap (Inven_02 #42..#46)
//   hud_presetblink  game2/inven/ui_presetblink_icon.txt  "Preset Change Icon Visibility": the preset's icon blinks
//                    (non-glare #32..#36 / glare #37..#41) for 2.5 s at the centre after a switch
//   presetMsg        "Item Equipment Info Notification": "Switching to preset [N]." (2000:124) in the system chat
//   presetCallPet    "Auto-Summon on Preset Change": the preset's pet is summoned after the switch (mounts system)
// Keys (keymap.js): Equip Preset 1..5 (1101..1105), Weapon Swap (Tab: the items system's weapon tab II),
// Equipment Swap (Ctrl+Tab: the next preset that holds equipment).
import { str } from './util.js';
import { FirstPersonSwap } from '../../engine/first-person-swap.js';
import { firstPersonSwapEligible } from '../../engine/native-first-person-presentation.js';

const BLINK_SEC = 2.5;

export function registerPresets(game, ctx) {
  const active = () => Number(game.items?.equip?.data?.active) || 0;

  game.uiwin.registerWindow('hud_presetmini', {
    hud: true, escClose: false, script: 'game2/inven/ui_presetmini_icon.txt', remember: false,
    create(win) {
      const b = win.control('btn_presetMiniicon');
      b.setTooltip(() => str(260, 53 + active()) || `Preset ${active() + 1}`);
    },
    update(win) {
      const on = !!game.items?.equip;
      if (win.data.on !== on) { win.data.on = on; win.root.el.style.visibility = on ? '' : 'hidden'; }
      const i = active();
      if (win.data.i !== i) { win.data.i = i; win.control('btn_presetMiniicon').setImage('none', 'Inven_02', 42 + i).setImage('disable', 'Inven_02', 42 + i); }
    },
  });

  game.uiwin.registerWindow('hud_presetblink', {
    hud: true, escClose: false, script: 'game2/inven/ui_presetblink_icon.txt', remember: false,
    onOpen(win, i) { win.data.i = Number(i) || 0; win.data.t = 0; win.data.f = -1; },
    update(win, dt) {
      const d = win.data;
      d.t += dt;
      const f = Math.floor(d.t / 0.25) % 2;
      if (f !== d.f) { d.f = f; win.control('btn_presetBlinkIcon').setImage('none', 'Inven_02', (f ? 37 : 32) + d.i); }
      if (d.t >= BLINK_SEC) game.uiwin.close('hud_presetblink');
    },
  });

  let last = null;
  game.events?.on?.('equip', ({ reason } = {}) => {
    if (reason !== 'preset') return;
    const i = active();
    if (i === last) return;
    last = i;
    if (ctx.options.get('presetMsg')) ctx.chat?.system((str(2000, 124) || 'Switching to preset [%d].').replace('%d', String(i + 1)));
    if (ctx.options.get('presetBlinkIcon')) { game.uiwin.close('hud_presetblink'); game.uiwin.open('hud_presetblink', i); }
    if (ctx.options.get('presetCallPet')) {
      const m = game.mounts;
      const petSlot = m?.EQUIP_SLOT?.pet ?? 19;
      const hasPet = !!game.items?.equip?.get?.(petSlot);
      if (hasPet && m && !m.pet) { try { m.summonPet(); } catch (err) { console.warn('[hud-options] preset pet', err); } }
    }
  });
  game.events?.on?.('map', () => { last = active(); });

  /** Keymap actions. */
  return {
    setPreset(i) { game.items?.setPreset?.(Number(i)); },
    // First person on foot: the arms lower, the swap runs at the low point, the arms come back (ENGINE-CHOSEN, the data has no
    // swap clip or delay: see engine/first-person-swap.js). Everywhere else the swap is immediate, as before.
    weaponSwap() {
      const swap = (game.fpSwap ||= new FirstPersonSwap(game));
      const worn = () => (game.player?._weaponObjs || []).map(w => w.obj?.uuid).join(',');
      if (swap.begin(() => game.items?.swapWeaponTab?.(), firstPersonSwapEligible(game), worn)) return;
      game.items?.swapWeaponTab?.();
    },
    nextPreset() {
      const E = game.items?.equip;
      if (!E) return;
      const n = E.data.presets?.length || 5;
      for (let k = 1; k < n; k++) {
        const j = (E.data.active + k) % n;
        if (Object.keys(E.preset(j) || {}).length) { game.items.setPreset(j); return; }
      }
    },
  };
}
