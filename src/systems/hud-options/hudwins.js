// HUD windows of the original client, built from their game2 scripts through the UI platform (docs/UIWIN.md):
//   hud_hp        mainbar/ui_hpwnd.txt        HP/MP/shield gauges, class icon, level, name, EXP %
//   hud_mainmenu  mainbar/ui_mainmenuwnd.txt  EXP bar across the screen bottom + the menu column + shop/menu buttons
//   hud_target    ui_targetpop.txt            target plate (name, level colour, HP, ownership orb, statuses, ToT)
//   hud_bosshp    ui_bosshpbar.txt            the big stacked boss HP bar
//   hud_buff / hud_skillbuff / hud_debuff     mainbar/ui_buffwnd.txt, ui_skillbuffwnd.txt, ui_debuffwnd.txt
import { gfxC } from '../../ui/gfx-parity-c.js'; // gfxC: Global 43.19 recording 'Lv.1' (left) / 'EXP 0.00%'
import { classIconSprite, atlas } from '../../ui/atlas.js';
import { classDefOf, expProgress, isBoss, levelDiffColor, npcDef } from '../../ui/gameinfo.js';
import { loadStringTable, NPC_JOB, npcJobNameTitle } from '../../ui/strings.js';
import { bindingName } from './keymap.js';
import { str, plainMarkup, clamp01, fmtInt, npcNameFix } from './util.js';
import {statusRemaining, statusFraction} from '../../ui/cooldown.js';
import {statusIconDrag} from './status-drag.js';
import { overflowCount, spellCountText } from './mainbar-extras-rules.js';
import { shortName } from '../skills/statuses.js';
import { playerNameplateName } from '../../game/nameplate-view.js';

const HUD = { hud: true, remember: true, escClose: false };

// ------------------------------------------------------------------------------------------ HP window
export function registerHpWindow(game) {
  game.uiwin.registerWindow('hud_hp', {
    ...HUD, script: 'game2/mainbar/ui_hpwnd.txt',
    create(win) { win.data.sig = {}; },
    update(win) {
      const g = game, p = g.player, s = g.save || {};
      if (!p) return;
      const d = win.data.sig;
      const hp = Math.max(0, Math.round(p.hp || 0)), mhp = Math.max(1, Math.round(p.maxHp || 1));
      const mp = Math.max(0, Math.round(p.mp || 0)), mmp = Math.max(1, Math.round(p.maxMp || 1));
      const sh = Number(p.shield) || 0, msh = Number(p.maxShield) || 0;
      if (d.hp !== hp || d.mhp !== mhp) { d.hp = hp; d.mhp = mhp; win.control('hp').setGauge(hp / mhp); win.control('lbl_hp').setText(`${fmtInt(hp)} / ${fmtInt(mhp)}`); }
      if (d.mp !== mp || d.mmp !== mmp) { d.mp = mp; d.mmp = mmp; win.control('mp').setGauge(mp / mmp); win.control('lbl_mp').setText(`${fmtInt(mp)} / ${fmtInt(mmp)}`); }
      const shf = msh > 0 ? clamp01(sh / msh) : 0;
      if (d.sh !== shf) { d.sh = shf; win.control('shield').setGauge(shf); }
      const lv = s.level || p.level || 1;
      // the level box reads "Lv. #", centred in its box
      if (d.lv !== lv) { d.lv = lv; win.control('lbl_pclevel').setText(gfxC('hudfmt') ? (gfxC('hudpos') ? `Lv.${lv}` /* gfxC3: lbl_pclevel has no align in ui_hpwnd.txt -> left, as the Global recording */ : `<center>Lv.${lv}`) : `<center>Lv. ${lv}`) /* gfxC: Global text 'Lv.1' (no space); Global draws it left-aligned, kept centred here until hud_hp sits at Global's offset (left text is under the quickslot B panel now) */; }
      const name = playerNameplateName(p.name || s.name || '',p.nameplate||g.network?.self?.nameplate);
      if (d.name !== name) { d.name = name; win.control('lbl_pcname').setText(name); }
      const cls = classDefOf(g)?.index ?? s.classIndex;
      if (d.cls !== cls) { d.cls = cls; const [grp, i] = classIconSprite(cls); win.control('pan_class').setSprite(grp, i); win.control('pan_class').setTooltip(classDefOf(g)?.name || ''); }
      const { frac } = expProgress(g);
      const pct = `${(clamp01(frac) * 100).toFixed(2)}%`;
      if (d.exp !== pct) { d.exp = pct; win.control('lbl_exp').setText(gfxC('hudfmt') ? `EXP ${pct}` : pct); }
      // action gauge (charging skills): skills.js may expose a charge fraction
      const ch = Number(g.skills?.chargeFraction?.());
      const act = Number.isFinite(ch) && ch > 0;
      if (d.act !== act) { d.act = act; win.control('pan_actgage').setVisible(act); }
      if (act) { win.control('actgage').setGauge(ch); win.control('lbl_actgage').setText(`${Math.round(ch * 100)}%`); }
    },
  });
}

// ------------------------------------------------------------------------------------------ main menu + EXP
/** Main-menu buttons: id -> [tooltip code (stringtable_tooltip cate 22) | literal, keymap action id, fallback]. */
const MENU = {
  btn_vehicle: [5, 'ride'], btn_inven: [9, 'inventory'], btn_ride: [19, 'mount'], btn_petsummon: [6, 'petsummon'],
  btn_petinven: [7, 'pet'], btn_fishing: [3, 'fishing'], btn_mail: [4, 'messenger'], btn_expedition: [8, 'expedition'],
  btn_party: [2, 'party'], btn_guild: [1, 'guild'], btn_craft: [20, 'craft'], btn_character: [15, 'character'],
  btn_skill: [10, 'skill'], btn_quest: [11, 'quest'], btn_map: [16, 'map'], btn_personalshop: [13, 'personalshop'],
  btn_escoption: [14, null], btn_supplymachine: [null, null], btn_single_supplymachine: [null, null],
  btn_vipshop: [null, null], btn_cashinven: [null, null], btn_cash: [null, null], btn_menu: [null, null],
};

export function registerMainMenu(game, ctx) {
  game.uiwin.registerWindow('hud_mainmenu', {
    ...HUD, script: 'game2/mainbar/ui_mainmenuwnd.txt', remember: false,
    create(win) {
      win.data.menuOpen = true;
      for (const [id, [tip, action]] of Object.entries(MENU)) {
        const b = win.control(id);
        if (tip != null) b.setTooltip(() => plainMarkup(str(22, tip)).replace('<keyname>', action ? bindingName(ctx.keymap.get(action)) : ''));
        // a menu button nobody bound yet still answers: the key map's action (window / message)
        b.on('click', () => { if (!game.uiwin.hasMenuButton(id)) ctx.menuFallback(id, action); });
      }
      // "Menu" pops the menu column in and out (guide: the main menu button pops up the menu)
      const cols = ['pan_menu_top', 'pan_menu_middle', 'pan_menu_bottom'];
      win.control('btn_menu').on('click', () => {
        if (game.uiwin.hasMenuButton('btn_menu')) return;
        win.data.menuOpen = !win.data.menuOpen;
        for (const c of cols) win.control(c).setVisible(win.data.menuOpen);
      });
      win.control('exp').setTooltip(() => {
        const { cur, need, level } = expProgress(game);
        return Number.isFinite(need) ? `Lv ${level}  ${fmtInt(cur)} / ${fmtInt(need)}` : `Lv ${level}`;
      });
    },
    update(win) {
      const { frac } = expProgress(game);
      const f = clamp01(frac);
      if (win.data.exp !== f) { win.data.exp = f; win.control('exp').setGauge(f); }
    },
  });
}

// ------------------------------------------------------------------------------------------ target plate
let jobStrings = null;
loadStringTable(NPC_JOB).then(t => { jobStrings = t; }).catch(() => {});

export function targetHpNumbers(actor) {
  const rawMax = Number(actor?.maxHp), rawHp = Number(actor?.hp);
  const max = Number.isFinite(rawMax) ? Math.max(0, Math.min(Number.MAX_SAFE_INTEGER, rawMax)) : 0;
  const hp = Number.isFinite(rawHp) ? Math.max(0, Math.min(max, rawHp)) : 0;
  return { hp, max };
}

export function registerTargetWindow(game, ctx) {
  game.uiwin.registerWindow('hud_target', {
    ...HUD, script: 'game2/ui_targetpop.txt', remember: false,
    create(win) {
      win.data.sig = '';
      const label = win.data.mobHp = document.createElement('span');
      label.style.cssText = 'position:absolute;inset:0;display:flex;align-items:center;justify-content:center;pointer-events:none;z-index:2;color:#fff;font:9px/11px Tahoma,Verdana,sans-serif;text-shadow:0 1px 1px #000,1px 0 1px #000;white-space:nowrap;overflow:hidden';
      win.control('processbar_hp').el.append(label);
      win.control('btn_closepcpop').onClick(() => { if(!game.pcpop?.close())ctx.clearTarget(); });
      // the player menu (game2/ui_pcpopwnd.txt, game.pcpop) when a system registered entries; else the old behaviour
      win.control('btn_showpcpop').onClick(() => { const t = game.player?.target; if (!(t?.kind === 'player' && game.pcpop?.toggle(t))) ctx.clearTarget(); });
      for (let i = 0; i < 8; i++) {
        const c = win.control(`pan_tp_status_${i}`);
        c.setTooltip(() => { const s = win.data.statuses?.[i]; return s ? statusTip(s, game) : null; });   // game: host rows count down
      }
    },
    update(win) {
      const g = game, t = g.player?.target;
      const d = win.data;
      // Self-target remains selected for friendly skills, but the player's own
      // HP window and overhead nameplate already show this information.
      if (!t || t === g.player || t.disposed || (t.kind === 'monster' && t.dead && ctx.deadFor(t) > 1.5)) {
        if (d.sig !== 'none') { d.sig = 'none'; win.root.el.style.visibility = 'hidden'; }
        ctx.bossBar(null);
        return;
      }
      win.root.el.style.visibility = '';
      const boss = t.kind === 'monster' && isBoss(t);
      const sig = `${t.id ?? t.name}|${boss}|${t.level}|${t.name}`;
      if (sig !== d.sig) {
        d.sig = sig;
        win.control('pan_bg').setVisible(!boss);
        win.control('pan_bg1').setVisible(boss);
        let name = t.name || '';
        let color = 'ffffffff';
        if (t.kind === 'npc') {
          const js = jobStrings?.get(Number(npcDef(g, t).desc));
          name = npcNameFix(npcJobNameTitle(t, js), name).name;
          color = 'ffffd76a';
        } else if (t.kind === 'monster') {
          name = t.level != null ? `Lv.${t.level} ${name}` : name;
          color = levelDiffColor(g, t.level);
        }
        win.control('lbl_name').setText(name).setTextColor(color);
        win.control('processbar_hp').setVisible(t.kind !== 'npc');
        win.control('pan_showpcpop').setVisible(t.kind === 'player');
      }
      // ownership orb: grey until the player has hit the monster, then "you own this monster" (green)
      const owned = t.kind === 'monster' && ctx.ownedBy(t);
      for (let i = 1; i <= 5; i++) win.control(`pan_owner${i}`).setVisible(i === 1 && owned);
      win.control('pan_ownerBg').setVisible(t.kind === 'monster');
      win.control('pan_ownerBg').setTooltip(owned ? str(40, 20) : '');
      const health = targetHpNumbers(t);
      if (t.kind !== 'npc') win.control('processbar_hp').setGauge(health.max > 0 ? health.hp / health.max : 0);
      d.mobHp.style.display = t.kind === 'monster' ? 'flex' : 'none';
      const hpText = t.kind === 'monster' ? fmtInt(Math.floor(health.hp)) : '';
      if (d.mobHp.textContent !== hpText) d.mobHp.textContent = hpText;
      // target of target (the monster's own target)
      const tt = t.target && !t.target.disposed ? t.target : null;
      const totName = tt ? (tt === g.player ? (g.player.name || '') : (tt.name || '')) : '';
      if (d.tot !== totName) { d.tot = totName; win.control('pan_tot').setVisible(!!totName); win.control('lbl_tot_name').setText(totName); }
      // statuses (ui_targetpop pan_tp_status_0..7: imagetable `buffer` 22x22 icons)
      const list = targetStatuses(g, ctx, t).slice(0, 8);
      d.statuses = list;
      const ssig = list.map(s => `${s.key ?? s.statusIndex ?? s.name}:${s.iconIndex}`).join('|');
      if (d.ssig !== ssig) {
        d.ssig = ssig;
        for (let i = 0; i < 8; i++) {
          const c = win.control(`pan_tp_status_${i}`), s = list[i];
          c.setVisible(!!s);
          if (s) c.setImage('none', 'buffer', statusIcon(s));
        }
      }
      refreshTimedStatusTooltip(win,list.map((s,i)=>({s,ctrl:win.control(`pan_tp_status_${i}`)})),game);
      ctx.bossBar(boss ? t : null);
    },
  });
}

// ------------------------------------------------------------------------------------------ boss HP bar
const BOSS_BARS = 10;   // HP is shown as stacked bars that change colour (bosshpbar_1..5)
export function registerBossBar(game) {
  game.uiwin.registerWindow('hud_bosshp', {
    ...HUD, script: 'game2/ui_bosshpbar.txt', remember: false,
    create(win) {
      // the five colour layers share the id pan_hpbar_; the client sizes them at run time
      win.data.layers = win.root.children.filter(c => c.id.toLowerCase() === 'pan_hpbar_');
      const base = win.data.layers[0];
      const [x, y, w, h] = base?.spec.rect || [59, 42, 670, 18];
      win.data.rect = { x, y, w, h };
      for (const L of win.data.layers) {
        L.setRect(x, y, w, h);
        const [l, c, r] = L.children;
        l?.setRect(0, 0, 47, h); c?.setRect(47, 0, w - 47 - 35, h); r?.setRect(w - 35, 0, 35, h);
        L.setClip(true);
      }
    },
    update(win) {
      const t = win.data.target;
      if (!t) return;
      const { x, y, w, h } = win.data.rect;
      const f = t.maxHp > 0 ? clamp01(t.hp / t.maxHp) : 0;
      const total = f * BOSS_BARS;
      const bar = Math.min(BOSS_BARS - 1, Math.floor(total - 1e-9));   // index of the bar being emptied
      const within = total - Math.max(0, bar);
      const L = win.data.layers, n = L.length || 1;
      L.forEach((layer, i) => layer.setVisible(false));
      if (total > 0) {
        const top = L[bar % n], under = bar > 0 ? L[(bar - 1) % n] : null;
        if (under && under !== top) { under.setVisible(true); under.setRect(x, y, w, h); under.el.style.zIndex = '1'; }
        top.setVisible(true); top.setRect(x, y, Math.max(1, Math.round(w * within)), h); top.el.style.zIndex = '2';
      }
      const step = `x${Math.max(0, bar + 1)}`;
      if (win.data.step !== step) { win.data.step = step; win.control('lbl_stepnum').setText(step); win.control('lbl_stepnum_bg').setText(step); }
    },
  });
}

// ------------------------------------------------------------------------------------------ buffs
function activeStatuses(list, game) {
  return Array.isArray(list) ? list.filter(s => s && !((game ? statusRemaining(game, s) : Number(s.remaining)) <= 0)) : [];
}
/**
 * The target plate's statuses (2.2.1: monsters' buffs / debuffs online). Offline, a monster's StatusSystem entries
 * (statuses.js: iconIndex, name, remaining) are used as before. Online, local status ticking is off (network/skills.js) and
 * a networked actor carries the host's public rows instead (server/world/skills.mjs skillStatusVisuals, the original
 * SendToOthers=1 statuses: key/family/statusIndex/spell/spellIcon/at/remaining, no icon): their icon and text come from
 * the status table (mainbar-extras.js defOf: skills_status.json IconIndex / Description). Spell auras are left out: their
 * art is the Spell_B group, not the plate's 22x22 `buffer` cells (ENGINE-CHOSEN; the data does not show them here).
 */
export function targetStatuses(game, ctx, t) {
  const online = t !== game.player && Array.isArray(t?._skillStatusVisuals);
  const rows = t === game.player ? (game.save?.buffs || t.statuses) : online ? t._skillStatusVisuals : t?.statuses;
  const list = activeStatuses(rows, online ? game : null);
  if (!online) return list;
  const defOf = ctx?.mainbarExtras?.defOf || (i => game.skills?.data?.status?.(i) || null);
  return list.map(s => {
    if (s.spell) return null;
    if (s.iconIndex != null) return s;
    const def = defOf(s.statusIndex);   // a definition still loading (skills/data.js _wantFull) shows on a later frame
    return def && def.iconIndex != null ? { ...s, iconIndex: def.iconIndex, description: def.description || '', name: shortName(def.description), debuff: Number(def.property) !== 1 } : null;
  }).filter(Boolean);
}
export function statusIcon(s) { const n = Number(s.iconIndex ?? s.icon ?? 1); return Number.isFinite(n) && n >= 0 ? n : 1; }
export function statusTip(s, game) {
  const r = game ? statusRemaining(game, s) : Number(s.remaining);
  const time = Number.isFinite(r) ? (r >= 3600 ? `${Math.floor(r / 3600)}h ${Math.floor((r % 3600) / 60)}m` : r >= 60 ? `${Math.floor(r / 60)}m ${Math.floor(r % 60)}s` : `${Math.ceil(r)}s`) : '';
  return [s.name || 'Status', s.description || '', time ? `<color=ffff00>${time}</color>` : ''].filter(Boolean).join('\n');
}
// Status bars already interpolate their authoritative countdown each frame.
// Refresh only the hovered tooltip when its displayed second changes.
export function refreshTimedStatusTooltip(win, entries, game) {
  const tips=game.uiwin?.tooltips,owner=tips?.owner;
  const entry=owner&&entries.find(e=>e.ctrl===owner);
  if(!entry?.s){
    if(owner&&win.data.timedTipOwner===owner)tips.hide?.();
    win.data.timedTipOwner=null;win.data.timedTipText=null;return;
  }
  const text=statusTip(entry.s,game);
  if(win.data.timedTipOwner===owner&&win.data.timedTipText===text)return;
  win.data.timedTipOwner=owner;win.data.timedTipText=text;
  tips.refresh(owner);
}
/** Which of the buff windows a player status belongs to. */
export function statusKind(s) {
  if (s.debuff || s.harmful || s.negative || s.type === 'debuff' || s.kind === 'debuff' || Number(s.style) === 2) return 'debuff';
  if (s.rune || s.kind === 'rune') return 'rune';
  if (s.item || s.potion || s.source === 'item' || s.kind === 'item' || s.itemIndex != null) return 'potion';
  return 'skill';
}

/** buffwnd: rows 0 buff / 1 potion / 2 rune, skillbuffwnd: skill buffs, debuffwnd: debuffs. 10 icons per row. */
export function registerBuffWindows(game, ctx) {
  const defs = [
    ['hud_buff', 'game2/mainbar/ui_buffwnd.txt', s => ['buff', 'potion', 'rune'].indexOf(kindRow(s)), 3],
    ['hud_skillbuff', 'game2/mainbar/ui_skillbuffwnd.txt', s => (kindRow(s) === 'skill' ? 0 : -1), 3],
    ['hud_debuff', 'game2/mainbar/ui_debuffwnd.txt', s => (kindRow(s) === 'debuff' ? 0 : -1), 1],
  ];
  function kindRow(s) { const k = statusKind(s); return k === 'potion' ? 'potion' : k === 'rune' ? 'rune' : k === 'debuff' ? 'debuff' : k === 'skill' ? (s.fromItem ? 'buff' : 'skill') : 'buff'; }
  for (const [name, script, rowOf, rows] of defs) {
    game.uiwin.registerWindow(name, {
      ...HUD, script, movable: true,
      create(win) {
        win.data.icons = [];
        win.data.rows = rows;
        for (const t of win.controls(/^pan_title/i)) t.hide();
      },
      update(win) {
        const all = activeStatuses(game.network?.active ? game.save?.buffs : game.player?.statuses?.length ? game.player.statuses : game.save?.buffs, game);
        const per = [[], [], []];
        for (const s of all) { const r = rowOf(s); if (r >= 0 && r < rows) per[r].push(s); }
        // Skill window has three native rows; overflow belongs in its next row.
        // lbl_spellcount: statuses with no drawn cell (ENGINE-CHOSEN, src/config/engine-chosen-mainbar.js)
        const over = name === 'hud_skillbuff' ? Math.max(0, per[0].length - rows * 10) : overflowCount(per.slice(0, rows));
        if (name === 'hud_skillbuff') { const skills = per[0]; for (let r = 0; r < rows; r++) per[r] = skills.slice(r * 10, (r + 1) * 10); }
        const sig = per.map(l => l.map(s => `${s.key ?? s.name}:${s.iconIndex}:${s.stack ?? ''}`).join(',')).join('|');
        const d = win.data;
        const any = per.some(l => l.length);
        win.root.el.style.visibility = any ? '' : 'hidden';
        if (win.data.over !== over) { win.data.over = over; if (win.has('lbl_spellcount')) win.control('lbl_spellcount').setText(spellCountText(over)); }
        if (d.sig !== sig) {
          d.sig = sig;
          const tips=game.uiwin?.tooltips;
          if(d.icons.some(icon=>icon.ctrl===tips?.owner))tips.hide?.();
          for (const c of d.icons) c.ctrl.remove();
          d.icons = [];
          const tpl = win.find('pan_bufficon');
          const bg = win.control('pan_bg');
          per.forEach((list, r) => list.slice(0, 10).forEach((s, i) => {
            const y = rows === 1 ? 0 : r * 30;
            const c = tpl.cloneAs(`_${r}_${i}`, { x: 300 - (i + 1) * 30, y, parent: bg });
            c.stop?.();
            c.setImage('none', s.iconGroup || 'buffer_b', statusIcon(s));   // skills: spells use imagetable Spell_B
            // a smaller icon (Spell_B cells are 28x28 in the 30x30 buff cell) is drawn at its own size, centred on
            // whole pixels, never stretched
            const ir = atlas.rect(s.iconGroup || 'buffer_b', statusIcon(s));
            if (ir && ir.w > 0 && ir.h > 0 && (ir.w < 30 || ir.h < 30)) {
              const iw = Math.min(30, ir.w), ih = Math.min(30, ir.h);
              c.setRect(300 - (i + 1) * 30 + Math.floor((30 - iw) / 2), y + Math.floor((30 - ih) / 2), iw, ih);
            }
            const icon = { ctrl: c, s, r, i };
            c.setTooltip(() => statusTip(icon.s, game));
            c.onRightClick(() => ctx.cancelStatus(icon.s));
            statusIconDrag(win,c);
            const stack = c.control(`lbl_stack_${r}_${i}`) || c.children[0];
            stack?.setText(Number(s.stack) > 1 ? String(s.stack) : '');
            d.icons.push(icon);
          }));
        }
        // blink when about to run out (the timerpanel pulse), steady otherwise
        for (const it of d.icons) {
          it.s = per[it.r][it.i];
          it.ctrl.setCooldown(statusFraction(game, it.s));
          const r = statusRemaining(game, it.s);
          const ending = Number.isFinite(r) && r < 10;
          if (it.ending !== ending) { it.ending = ending; if (ending) it.ctrl.start?.(); else { it.ctrl.stop?.(); } }
        }
        refreshTimedStatusTooltip(win,d.icons,game);
      },
    });
  }
}
