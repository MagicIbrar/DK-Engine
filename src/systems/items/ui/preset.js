// Preset preview (the inventory's btn_preview_off): game2/inven/ui_presetpreviewwnd.txt (260:77 "Preset Preview").
// Shows the equipment of any preset tab without switching to it (tooltip 25:28); tabs, weapon I/II and the
// armour / costume view work as in the inventory, the slots are read-only.
import { slotIcon } from './common.js';
import { buildTooltip } from '../tooltip.js';
import { S } from '../equip.js';

const SLOT_IDS = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 18, 19, 20, 24, 25, 26, 27, 28, 33, 34, 35, 36];

export function registerPresetPreview(sys) {
  const g = sys.game;
  const st = { preset: 0, weapon2: false, costume: false, win: null };
  const render = () => {
    const win = st.win;
    if (!win?.isOpen) return;
    for (let pi = 0; pi < 5; pi++) {
      win.control(`btn_preset_${pi + 1}`).setChecked(pi === st.preset);
      const pan = win.control(`pan_Preset_${pi + 1}`);
      pan.setVisible(pi === st.preset);
      if (pi !== st.preset) continue;
      for (const id of SLOT_IDS) {
        const c = pan.control(`suititem_${id}`);
        if (c.missing) continue;
        const slot = st.weapon2 && (id === S.weapon || id === S.offhand) ? id + 100 : id;
        c.data.slot = slot;
        slotIcon(sys, c, sys.equip.get(slot, pi));
        if (id === S.armor) c.setVisible(!st.costume);
        if (id === S.costume) c.setVisible(st.costume);
      }
    }
    win.control('btn_weapontab_0').setChecked(!st.weapon2);
    win.control('btn_weapontab_1').setChecked(st.weapon2);
    win.control('btn_ArmorTab').setChecked(!st.costume);
    win.control('btn_CostumeTab').setChecked(st.costume);
    win.control('pan_CostumeBG').setVisible(st.costume);
  };
  g.uiwin.registerWindow('presetpreview', {
    script: 'game2/inven/ui_presetpreviewwnd.txt',
    create(win) {
      st.win = win;
      for (let pi = 0; pi < 5; pi++) {
        win.control(`btn_preset_${pi + 1}`).onClick(() => { st.preset = pi; render(); });
        const pan = win.control(`pan_Preset_${pi + 1}`);
        for (const id of SLOT_IDS) {
          const c = pan.control(`suititem_${id}`);
          if (c.missing) continue;
          c.setTooltip(() => { const inst = sys.equip.get(c.data.slot ?? id, pi); return inst ? buildTooltip(sys, inst, { where: 'equip' }) : null; });
        }
      }
      win.control('btn_weapontab_0').onClick(() => { st.weapon2 = false; render(); });
      win.control('btn_weapontab_1').onClick(() => { st.weapon2 = true; render(); });
      win.control('btn_ArmorTab').onClick(() => { st.costume = false; render(); });
      win.control('btn_CostumeTab').onClick(() => { st.costume = true; render(); });
      g.events.on('equip', render);
    },
    onOpen(win) {
      st.preset = (sys.equip.data.active + 1) % 5;
      render();
      const inv = g.uiwin.window('inventory');
      if (inv?.isOpen) win.setPosition(Math.max(0, inv.box.x - win.box.w - 4), inv.box.y);
      sys.inv?.renderEquip?.();
    },
    onClose() { sys.inv?.renderEquip?.(); },
  });
}
