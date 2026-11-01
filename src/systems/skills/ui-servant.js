// The summoner's servant windows (docs/UIWIN.md platform):
//   servant_win   script/ui/game2/ui_servantwnd.txt: portrait (pcpop 13.. = servant.csv IconIndex), name + level, HP
//                 gauge, the current order icon (pan_curcommand: pcpop 21 attack / 22 independence / 24 call / 25 stop),
//                 and the order menu (pan_command, pcpop 6 with the icons baked in; btn_* hover frames pcpop 7) unfolded
//                 by btn_showcom / btn_hidecom.
//   servantskill  script/ui/game2/ui_servantskillwnd.txt: the Great-attack power gauge (bar_power, pcpop 28), its icon
//                 (pcpop 32-35), the ready orb (pan_servantskillalarm blinks at 100 %). Shown above servant_win for the
//                 servants that have a Great block (Bregon, Anathema, Agares, Musfel, Erigol, Gigantes).
// Orders also come from the key map "Order Summon" actions (hud-options 'keyaction': sumattack / sumauto / sumcall /
// sumstop / sumdisband / sumskill). Tooltips: stringtable_servant.txt <cate> 400 (1..6, 31) with the bound key names.
import { fetchText } from '../../engine/assets.js';

const ORDER_ICON = { assist: 21, attack: 21, free: 22, call: 24, stop: 25 };
const KEY_OF = { attack: 'sumattack', free: 'sumauto', call: 'sumcall', stop: 'sumstop', destroy: 'sumdisband', skill: 'sumskill' };
const TIP_OF = { attack: 1, free: 2, assist: 3, call: 4, stop: 5, destroy: 6 };
// Great icons and their unlocking skills come from native article/gage.csv.

async function loadServantStrings() {
  const out = {};
  try {
    const t = await fetchText('script/string/normal/stringtable_servant.txt', true);
    const re = /code\s+(\d+)[^\n]*\n\s*\{([\s\S]*?)\n\s*\}/g;
    let m;
    while ((m = re.exec(t))) out[Number(m[1])] = m[2].replace(/\r/g, '').trim();
  } catch { /* optional */ }
  return out;
}

function keyText(game, id) {
  const spec = game.keymap?.get?.(id) || '';
  if (!spec) return '';
  return spec.split('+').map(k => k.replace(/^Key/, '').replace(/^Digit/, '').replace('Backslash', '\\')).join(' + ');
}

export async function installServantWindows(game, sys) {
  const ui = game.uiwin || game.ui;
  const sm = sys.summons;
  if (!ui?.registerWindow || !sm) return;
  const S = await loadServantStrings();
  sm.strings = S;
  const tip = (mode) => () => {
    const t = S[TIP_OF[mode]] || mode;
    const k = keyText(game, KEY_OF[mode]);
    return t.replace('<keyname>', k || '-');
  };
  const order = (mode) => () => { if (sm.command(mode)) game.audio?.ui?.('buttonCommon'); };

  ui.registerWindow('servant_win', {
    script: 'game2/ui_servantwnd.txt',
    hud: true,
    escClose: false,
    create(win) {
      win.control('btn_attack').onClick(order('attack')).setTooltip(tip('attack'));
      win.control('btn_free').onClick(order('free')).setTooltip(tip('free'));
      win.control('btn_call').onClick(order('call')).setTooltip(tip('call'));
      win.control('btn_stop').onClick(order('stop')).setTooltip(tip('stop'));
      win.control('btn_destroy').onClick(order('destroy')).setTooltip(tip('destroy'));
      const show = v => { win.control('pan_command').setVisible(v); win.control('btn_showcom').setVisible(!v); win.control('btn_hidecom').setVisible(v); };
      win.control('btn_showcom').onClick(() => { show(true); game.audio?.ui?.('buttonCommon'); });
      win.control('btn_hidecom').onClick(() => { show(false); game.audio?.ui?.('buttonCommon'); });
      win.control('pan_curcommand').setTooltip(() => tip(sm.mode || 'assist')());
      show(false);
    },
    onOpen(win) { win.data.icon = null; win.data.mode = null; },
    update(win) {
      const sv = sm.servantOf(game.player);
      if (!sv) { win.close(); return; }
      const name = `${sv.name} Lv ${sv.level}`;
      if (win.data.name !== name) { win.data.name = name; win.control('lbl_name').setText(name); }
      win.control('bar_hp').setGauge?.(sv.maxHp > 0 ? sv.hp / sv.maxHp : 0);
      const icon = Number(sv.def.iconIndex);
      if (icon > 0 && win.data.icon !== icon) { win.data.icon = icon; win.control('pan_servant').setSprite('pcpop', icon); }
      const mode = sm.mode || 'assist';
      if (win.data.mode !== mode) { win.data.mode = mode; win.control('pan_curcommand').setSprite('pcpop', ORDER_ICON[mode] || 21); }
    },
  });

  ui.registerWindow('servantskill', {
    script: 'game2/ui_servantskillwnd.txt',
    hud: true,
    escClose: false,
    create(win) {
      win.control('pan_servantskillicontip').setTooltip(() => {
        const sv = sm.servantOf(game.player);
        const k = keyText(game, KEY_OF.skill);
        return { lines: [{ text: `<color=ffd257>${sv?.name || ''}</color>`, font: 4 }, { text: S[31] || '' }, k ? { text: (S[30] || 'Shortcut key: <keyname>').replace('<keyname>', k) } : null].filter(Boolean) };
      });
      win.control('pan_servantskillalarm').onClick(() => sm.useGreat());
    },
    onOpen(win) { win.data.ready = null; win.data.sv = null; },
    update(win) {
      const sv = sm.servantOf(game.player);
      const blk = sm.greatBlock(sv);
      if (!sv || !blk) { win.close(); return; }
      if (win.data.sv !== sv) {
        win.data.sv = sv;
        const row = sm.gaugeRow(sv);
        win.control('pan_servantskillicon').setSprite('pcpop', row.icon);
        win.control('lbl_skillname').setText(game.skills?.skillDef(row.skill)?.name || '');
      }
      const f = sm.greatCharge(sv);
      win.control('bar_power').setGauge?.(f);
      const ready = f >= 1;
      if (win.data.ready !== ready) { win.data.ready = ready; win.control('pan_servantskillalarm').setBlink(ready); }
    },
  });

  game.events?.on('summon', ({ on, owner, servant }) => {
    if (owner !== game.player) return;
    if (on) {
      sm.mode = 'assist';
      ui.open('servant_win');
      if (sm.greatBlock(servant)) ui.open('servantskill');
    }
  });

  // key map "Order Summon" actions
  const KEYS = { sumattack: 'attack', sumauto: 'free', sumcall: 'call', sumstop: 'stop', sumdisband: 'destroy' };
  game.events?.on('keyaction', ({ id } = {}) => {
    if (KEYS[id]) order(KEYS[id])();
    else if (id === 'sumskill') sm.useGreat();
  });
}
