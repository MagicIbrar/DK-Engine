// Character window (key: charwin) — the ORIGINAL "Stats" window
// (script/ui/game2/charwindow/ui_statewnd_renew.txt) and its point-assignment window
// (ui_statesettingwnd_renew.txt), replacing the old CSS 'character' panel of src/ui/windows.js.
//
//   C / main-menu btn_character   -> 'character' (tabs Abilities / DK / Info / Title, three battle-info pages)
//   Points (btn_statpoint)         -> 'statsetting' (Str / Dex / Heal / Spr +/- with Shift = 10, preview before/after, Apply)
//
// Values come from progression.deriveStats (the same numbers combat uses); the base stat is save.stats, the "+n"
// line under it is what equipment / buffs add. Grade / chaotic / titles come from game.life.grade when the life
// system is installed. Nothing here owns game state except the stat allocation (progression.allocateStat).
import { deriveStats, expToNext, allocateStat } from '../../game/progression.js';
import { str as gstr, needStrings } from '../hud-options/util.js';
import { titleRows } from '../life/title-rules.js';
import { personalExpBonus } from './exp-bonus.js';

const STATS = ['str', 'dex', 'con', 'spr'];
const TABS = [['btn_battle', 'pan_battle'], ['btn_personability', 'pan_personability'], ['btn_score', 'pan_score'], ['btn_title', 'pan_title']];
const n0 = v => (Number.isFinite(Number(v)) ? Number(v) : 0);
const fmt = v => Math.round(n0(v)).toLocaleString('en-US');
const pct = v => `${(Math.round(n0(v) * 10) / 10).toFixed(1)}%`;

let G = null;

export function install(game) {
  G = game;
  const ui = game.uiwin;
  if (!ui?.registerWindow) return;
  const st = { tab: 0, info: 0, titleTop: 0, titleSel: null };

  const classDef = () => game.classDef || game.data?.classByIndex?.get(Number(game.save?.classIndex)) || null;
  const stats = () => game.player?.stats || deriveStats(game.save, classDef(), game.data);

  // Each page brings its own full-window background (pan_base State#32 for Abilities, pan_score State#33 for Info,
  // pan_title State#34 for Title; DK uses the renewed frame without the Abilities fields baked into State#32).
  const PAGES = [
    ['pan_base', 'pan_basebottom', 'pan_battle'],
    ['pan_basebottom', 'pan_personability'],
    ['pan_score', 'pan_basebottom'],
    ['pan_title'],
  ];
  const ALL_PAGES = ['pan_base', 'pan_basebottom', 'pan_battle', 'pan_personability', 'pan_score', 'pan_title'];
  function showTab(win, k) {
    st.tab = k;
    TABS.forEach(([b], i) => win.control(b).setChecked(i === k));
    for (const id of ALL_PAGES) win.control(id).setVisible(PAGES[k].includes(id));
    refresh(win);
  }
  function showInfo(win, k) {
    st.info = k;
    for (let i = 0; i < 3; i++) {
      win.control(`pan_battle_info_${i}`).setVisible(i === k);
      win.control(`btn_battle_info_${i}`).setChecked(i === k);
    }
  }

  function refresh(win) {
    if (!win?.isOpen) return;
    const s = game.save || {}, p = game.player || {}, S = stats(), c = classDef();
    const life = game.life?.grade || null;
    // ---- header (pan_basebottom)
    win.control('lbl_class').setText(c?.name || s.className || '');
    win.control('lbl_transjob').setText(s.transJob || '');
    win.control('lbl_name').setText(p.name || s.name || '');
    win.control('lbl_level').setText(String(s.level || 1));
    let grade = '';
    try { grade = life?.current?.()?.name || ''; } catch { /* no grade table */ }
    win.control('lbl_grade').setText(grade);
    win.control('lbl_guild').setText(game.guild?.name || s.guild?.name || '');
    // ---- Abilities
    const base = s.stats || c?.stats?.base || {};
    for (const k of STATS) {
      win.control(`lbl_${k}`).setText(String(n0(base[k])));
      const add = n0(S[k]) - n0(base[k]);
      win.control(`lbl_${k}add`).setText(add ? `${add > 0 ? '+' : ''}${add}` : '');
    }
    win.control('lbl_statpoint').setText(String(n0(s.statPoints)));
    win.control('btn_statpoint').setEnabled(true);
    win.control('lbl_melee').setText(`${fmt(S.meleeMin)} ~ ${fmt(S.meleeMax)}`);
    win.control('lbl_range').setText(`${fmt(S.rangeMin)} ~ ${fmt(S.rangeMax)}`);
    win.control('lbl_magic').setText(`${fmt(S.magicMin)} ~ ${fmt(S.magicMax)}`);
    win.control('lbl_defense').setText(fmt(S.defense));
    win.control('lbl_magicresist').setText(fmt(S.magicResist ?? S.magicDefense ?? 0));
    // lane 62: a field with no 4.2.0 source value stays empty (no invented 0 / 0.0%); see PLAYER-CARD-PARITY.md.
    const val = (id, v, f = fmt) => win.control(id).setText(v == null || !Number.isFinite(Number(v)) ? '' : f(v));
    val('lbl_pvp_attack', S.pvpAttack);
    // page 0: resistances / ratings / speeds
    for (const [id, key] of [['fire', 'resistFire'], ['ice', 'resistIce'], ['lightning', 'resistLightning'], ['poison', 'resistPoison'], ['curse', 'resistCurse'], ['dark', 'resistDark']]) {
      val(`lbl_${id}`, S[key] ?? S.resist?.[id]);
    }
    win.control('lbl_hitrating').setText(fmt(S.hitRate));
    win.control('lbl_blockrating').setText(fmt(S.dodge));
    win.control('lbl_guardrating').setText(pct(S.guardRate));
    val('lbl_acceleration', S.acceleration);
    win.control('lbl_movespeed').setText(pct(n0(S.moveSpeedMul || 1) * 100));
    win.control('lbl_attckspeed').setText(pct(n0(S.attackSpeed || 1) * 100));
    // page 1: critical / damage rates
    val('lbl_skillful', S.skillful);
    val('lbl_vitality', S.vitality);
    val('lbl_destroy', S.destroy);
    val('lbl_criticalrating', S.critRating);
    win.control('lbl_criticalrate').setText(pct(S.critRate));
    val('lbl_critical_damage_rate', S.critMultiplier == null ? null : n0(S.critMultiplier) * 100, pct);   // classinfo CRITICAL_DAMAGE_FACTORY / 1000
    val('lbl_damage_rate', S.damageRate, pct);
    val('lbl_pvp_tole_damage', S.pvpToleDamage, pct);
    val('lbl_pve_tole_damage', S.pveToleDamage, pct);
    val('lbl_rating_anti_status', S.antiStatus);
    val('lbl_distance_meleedamage', S.distanceMelee, pct);
    val('lbl_distance_rangedamage', S.distanceRange, pct);
    // page 2: recovery / penetration
    win.control('lbl_hp_recovery').setText((Math.round(n0(S.hpRegen) * 10) / 10).toString());
    win.control('lbl_mp_recovery').setText((Math.round(n0(S.mpRegen) * 10) / 10).toString());
    val('lbl_shild_recovery', S.shieldRegen, v => (Math.round(n0(v) * 10) / 10).toString());   // progression shieldRegen (classinfo SHIELD_RPS / SHIELD_RPS_LF)
    val('lbl_defeat_recovery', S.defeatRecovery);
    val('lbl_speed_cooltime', S.cooldownMul == null ? null : (1 - n0(S.cooldownMul)) * 100, pct);
    val('lbl_anti_rating_anti_status_add', S.antiStatusAdd);
    val('label_pvp_damage_add', S.pvpDamageAdd);
    val('label_pvp_damagerate_add', S.pvpDamageRateAdd, pct);
    val('label_phhysical_penetrate', S.physicalPenetrate);
    val('label_magical_penetrate', S.magicalPenetrate);
    val('label_boss_damage_mul', S.bossDamageMul, pct);
    win.control('label_bonus_exp_add').setText(pct(personalExpBonus(game,S)));   // no tooltip: Global's script has none
    // gauges
    const hp = n0(p.hp), mhp = Math.max(1, n0(p.maxHp || S.maxHp)), mp = n0(p.mp), mmp = Math.max(1, n0(p.maxMp || S.maxMp));
    win.control('pro_hp').setGauge(hp / mhp);
    win.control('lbl_hp').setText(`${fmt(hp)} / ${fmt(mhp)}`);
    win.control('pro_mp').setGauge(mp / mmp);
    win.control('lbl_mp').setText(`${fmt(mp)} / ${fmt(mmp)}`);
    const sh = n0(p.shield), msh = n0(p.maxShield);
    win.control('pro_shield').setGauge(msh > 0 ? sh / msh : 0);
    win.control('lbl_shield').setText(`${fmt(sh)} / ${fmt(msh)}`);
    // ---- Info
    const need = expToNext(n0(s.level) || 1, game.data);
    const ef = Number.isFinite(need) && need > 0 ? Math.min(1, n0(s.exp) / need) : 1;
    win.control('pro_exp').setGauge(ef);
    win.control('lbl_exp').setText(Number.isFinite(need) ? `${fmt(s.exp)} / ${fmt(need)} (${(ef * 100).toFixed(2)}%)` : fmt(s.exp));   // no invented '-' at the level cap
    let gp = { cur: 0, need: 0, frac: 0 };
    try { if (life?.progress) gp = life.progress(); } catch { /* ignore */ }
    win.control('pro_gradeexp').setGauge(gp.frac || 0);
    win.control('lbl_gradeexp').setText(`${fmt(Math.max(0, n0(gp.cur)))} / ${fmt(gp.need)} (${((gp.frac || 0) * 100).toFixed(2)}%)`);
    win.control('lbl_advpoint').setText(fmt(s.advPoints ?? 0));
    let ch = { value: 0, pk: 0 };
    try { if (life?.chaoticStatus) ch = life.chaoticStatus(); } catch { /* ignore */ }
    win.control('lbl_disposition').setText(fmt(ch.value));
    win.control('lbl_pk').setText(fmt(ch.pk));
    win.control('lbl_pvp').setText(fmt(s.pvpWins ?? 0));
    win.control('lbl_colosseum').setText(fmt(s.colosseumPoints ?? s.colosseum?.points ?? 0));
    win.control('lbl_dkpoint').setText(fmt(s.dkPoints ?? 0));
    win.control('lbl_dktier').setText(s.dkTier == null ? '' : String(s.dkTier));
    win.control('lbl_dkpoint_dk').setText(fmt(s.dkPoints ?? 0));
    win.control('lbl_dktier_dk').setText(s.dkTier == null ? '' : String(s.dkTier));
    // ---- Title
    if (st.tab === 3) paintTitles(win);
  }

  // ---------------------------------------------------------------------------------------- titles
  function paintTitles(win) {
    const life = game.life?.grade;
    const list = life?.titles || [];
    const cur = (() => { try { return life?.title?.() || null; } catch { return null; } })();
    if (cur?.Name) win.control('lbl_mytitle').setText(cur.Name); else win.control('lbl_mytitle').resetText?.();
    const optBox = win.control('textbox_option');
    optBox.setText?.(cur ? `${cur.Option_info || ''} ${cur.Option_Value1 ?? ''}`.trim() : '');
    const rows = 10;
    const tl = win.control('lbl_tagtitlelist');
    if (win.data.tlFmt == null) win.data.tlFmt = tl.getText?.() || 'Title List (%d/%d)';
    // EVENT-MODES: every title is listed; an owned one (life.owns, src/systems/life/title-rules.js) shows its name, an unowned
    // one keeps the script's own row text 2801|6 "Unacquired Title"; the info box shows the 2803|<Index> acquisition text and
    // only an owned title can be applied (TITLE_CHOSEN.window).
    const owned = (i) => (typeof life?.owns === 'function' ? !!life.owns(i) : true);
    const progress = new Map(titleRows(list, game.save?.life?.titles).map(r => [r.index, r]));
    tl.setText(win.data.tlFmt, list.filter(t => owned(t.Index)).length, list.length);
    st.titleTop = Math.max(0, Math.min(st.titleTop, Math.max(0, list.length - rows)));
    win.control('body_scroll').setRange(Math.max(0, list.length - rows), rows).setValue(st.titleTop);
    const tmpl = win.control('pan_element');
    for (let i = 0; i < rows; i++) {
      let row = win.find(`pan_element_r${i}`);
      if (!row && tmpl.cloneAs) {
        row = tmpl.cloneAs(`_r${i}`, { x: 0, y: i * 17, visible: true });
        const k = i;
        row?.control?.(`btn_element_r${k}`)?.onClick(() => {
          const t = (game.life?.grade?.titles || [])[st.titleTop + k];
          if (!t) return;
          st.titleSel = t.Index;
          paintTitles(win);
        });
      }
      if (!row) continue;
      const t = list[st.titleTop + i];
      row.setVisible(!!t);
      if (!t) continue;
      row.control(`btn_element_r${i}`).setText(owned(t.Index) ? (t.Name || `#${t.Index}`) : (gstr(2801, 6) || 'Unacquired Title'));
      row.control(`pan_select_r${i}`).setVisible(st.titleSel === t.Index || (st.titleSel == null && cur?.Index === t.Index));
    }
    const sel = list.find(t => t.Index === st.titleSel) || cur;
    win.control('textbox_optioninfo').setText?.(sel ? `${sel.Option_info || ''} ${sel.Option_Value1 ?? ''}`.trim() : '');
    const how = sel ? String(gstr(2803, sel.Index) || '').replace(/<\/?color[^>]*>/gi, '').replace(/\\n|\n/g, ' ').trim() : '';
    const pr = sel && progress.get(sel.Index), count = pr && pr.need != null && !pr.owned ? (gstr(2802, 9) || '').replace(/^\s*\[message\]\s*/i, '').replace('<VALUE>', sel.Name || '').replace('[COUNT1]', pr.have).replace('[COUNT2]', pr.need) : '';
    win.control('textbox_titleinfo').setText?.(sel ? [owned(sel.Index) ? (sel.Name || '') : '', how, count].filter(Boolean).join(' - ') : '');
  }

  // ---------------------------------------------------------------------------------------- Stats window
  ui.registerWindow('character', {
    script: 'game2/charwindow/ui_statewnd_renew.txt',
    replaces: 'character',
    create(win) {
      // The script gives the header (pan_basebottom) and the Info / DK / Title pages layer 103 but the Abilities
      // background pan_base layer 200, so with "higher layer on top" the background hid the header (it rendered dimmed
      // and empty). Keep page backgrounds (including the composed DK frame) at the bottom, then the header,
      // then the tab strip and the Abilities controls (200), then the title and X (300).
      const z = { pan_base: 150, pan_score: 150, pan_title: 150, pan_basebottom: 180, pan_personability: 150 };
      for (const [id, v] of Object.entries(z)) {
        const el = win.control(id).el;
        if (el) el.style.zIndex = String(v);
      }
      // The renewed script retains an obsolete 322px DK panel at y136. State#32
      // is not a blank frame: its Abilities fields are baked into the atlas, so
      // leaving it behind this page draws empty boxes through the DK labels.
      // Keep only its authored header, and fill the DK body with the native
      // renewed-frame strips (State#81/#82 in imagetable.txt). Original assets
      // and the other tabs are untouched; only this runtime page is composed.
      const dk = win.control('pan_personability');
      const base = win.control('pan_base'), [, , width, height] = base.spec.rect;
      const bodyY = win.control('pan_battle').spec.rect[1];
      dk.setRect(0, 0, width, height);
      dk.images = Object.create(null); dk.paintImage();
      dk.control('lbl_tagexp')?.hide(); // scope duplicate ID: Info's EXP label is still needed
      const header = base.cloneAs('_dk_header', { parent: dk, x: 0, y: 0 });
      header.el.style.clipPath = `inset(0 0 ${height - bodyY}px 0)`;
      header.el.style.zIndex = '0';
      const body = base.cloneAs('_dk_body', { parent: dk, x: 0, y: bodyY });
      body.setSprite('State', 81).setRect(0, bodyY, width, height - bodyY - 5);
      body.el.style.zIndex = '0';
      const bottom = base.cloneAs('_dk_bottom', { parent: dk, x: 0, y: height - 5 });
      bottom.setSprite('State', 82).setRect(0, height - 5, width, 5);
      bottom.el.style.zIndex = '0';
      for (const [id, x, y] of [['lbl_tagdkpoint',25,24],['pan_dkpoint',138,22],['lbl_tagdktier',25,58],['pan_dktier',138,56]]) {
        win.control(id).cloneAs('_dk', {parent:dk,x,y:bodyY+y});
      }
      TABS.forEach(([b], i) => win.control(b).onClick(() => showTab(win, i)));
      for (let i = 0; i < 3; i++) win.control(`btn_battle_info_${i}`).onClick(() => showInfo(win, i));
      win.control('btn_detail').onClick(() => showInfo(win, (st.info + 1) % 3));
      win.control('btn_statpoint').onClick(() => ui.toggle('statsetting'));
      void needStrings([['NORMAL', 2803, 1]]).catch(() => {});
      win.control('btn_titleselect').onClick(() => {
        const life = game.life?.grade;
        // original messages 2802|4 Unacquired Title / 2802|7 Title already applied / 2802|8 No Title selected
        const say = (code) => game.chat?.system?.((gstr(2802, code) || '').replace(/^\s*\[message\]\s*/i, ''), 'err');
        if (st.titleSel == null) say(8);
        else if (life?.owns && !life.owns(st.titleSel)) say(4);
        else if (life?.title?.()?.Index === st.titleSel) say(7);
        else if (life?.setTitle && life.setTitle(st.titleSel) === false) say(4);
        refresh(win);
      });
      win.control('btn_titlecancel').onClick(() => {
        const life = game.life?.grade;
        if (!life?.title?.()) game.chat?.system?.((gstr(2802, 10) || '').replace(/^\s*\[message\]\s*/i, ''), 'err');
        else if (life?.setTitle) life.setTitle(0);
        st.titleSel = null;
        refresh(win);
      });
      win.control('pan_titlelist').on?.('wheel', (e) => { st.titleTop += (e?.deltaY || 0) > 0 ? 1 : -1; paintTitles(win); });
      win.control('body_scroll').on('change', value => { st.titleTop = value; paintTitles(win); });
      const again = () => refresh(win);
      for (const ev of ['stats', 'levelup', 'equip', 'inventory', 'status', 'life:grade', 'life:title', 'exp']) game.events?.on?.(ev, again);
      win.data.tick = 0;
    },
    onOpen(win) { showTab(win, st.tab); showInfo(win, st.info); },
    update(win, dt) {
      win.data.tick = (win.data.tick || 0) + dt;
      if (win.data.tick > 0.5) { win.data.tick = 0; refresh(win); }   // HP / MP gauges, regen, buffs
    },
  });

  // ---------------------------------------------------------------------------------------- point assignment
  const pend = { str: 0, dex: 0, con: 0, spr: 0 };
  const pendSum = () => STATS.reduce((a, k) => a + pend[k], 0);
  const setVal = (c, v) => { if (typeof c.setValue === 'function') c.setValue(String(v)); else c.setText(String(v)); };
  function paintSetting(win) {
    if (!win?.isOpen) return;
    const s = game.save || {}, c = classDef();
    const base = s.stats || c?.stats?.base || {};
    const before = stats();
    const trial = { ...s, stats: { ...base } };
    for (const k of STATS) trial.stats[k] = n0(base[k]) + pend[k];
    let after = before;
    try { after = deriveStats(trial, c, game.data); } catch { /* keep before */ }
    for (const k of STATS) {
      setVal(win.control(`edit_${k}`), n0(base[k]) + pend[k]);
      win.control(`lbl_${k}_add`).setText(pend[k] ? `+${pend[k]}` : '');
      win.control(`btn_${k}_down`).setEnabled(pend[k] > 0);
      win.control(`btn_${k}_up`).setEnabled(n0(s.statPoints) - pendSum() > 0);
    }
    win.control('lbl_statpoint').setText(String(n0(s.statPoints) - pendSum()));
    const pair = (a, b) => `${fmt(a)} ~ ${fmt(b)}`;
    const rows = [
      ['hp', fmt(before.maxHp), fmt(after.maxHp)], ['mp', fmt(before.maxMp), fmt(after.maxMp)],
      ['shield', fmt(game.player?.maxShield || 0), fmt(game.player?.maxShield || 0)],
      ['Meleedamage', pair(before.meleeMin, before.meleeMax), pair(after.meleeMin, after.meleeMax)],
      ['Rangedamage', pair(before.rangeMin, before.rangeMax), pair(after.rangeMin, after.rangeMax)],
      ['magicdamage', pair(before.magicMin, before.magicMax), pair(after.magicMin, after.magicMax)],
      ['defense', fmt(before.defense), fmt(after.defense)],
    ];
    for (const [id, a, b] of rows) {
      win.control(`lbl_${id}_before`).setText(a);
      win.control(`lbl_${id}_after`).setText(b);
    }
    win.control('btn_apply').setEnabled(pendSum() > 0);
  }
  ui.registerWindow('statsetting', {
    script: 'game2/charwindow/ui_statesettingwnd_renew.txt',
    create(win) {
      for (const k of STATS) {
        win.control(`btn_${k}_up`).onClick((e) => {
          const left = n0(game.save?.statPoints) - pendSum();
          pend[k] += Math.min(left, e?.shiftKey ? 10 : 1);
          paintSetting(win);
        });
        win.control(`btn_${k}_down`).onClick((e) => { pend[k] = Math.max(0, pend[k] - (e?.shiftKey ? 10 : 1)); paintSetting(win); });
        // typing a value in the box assigns up to that many points (never below the current base)
        const ed = win.control(`edit_${k}`);
        const typed = () => {
          const base = n0((game.save?.stats || classDef()?.stats?.base || {})[k]);
          const v = Math.floor(Number(ed.getValue?.() ?? ed.getText?.()));
          if (!Number.isFinite(v)) { paintSetting(win); return; }
          const left = n0(game.save?.statPoints) - pendSum() + pend[k];
          pend[k] = Math.max(0, Math.min(left, v - base));
          paintSetting(win);
        };
        ed.on?.('enter', typed);
        ed.on?.('blur', typed);
      }
      win.control('btn_apply').onClick(() => {
        for (const k of STATS) if (pend[k] > 0) allocateStat(game, k, pend[k]);
        for (const k of STATS) pend[k] = 0;
        paintSetting(win);
        refresh(ui.window('character'));
      });
      game.events?.on?.('levelup', () => paintSetting(win));
    },
    onOpen(win) { for (const k of STATS) pend[k] = 0; paintSetting(win); },
    onClose() { for (const k of STATS) pend[k] = 0; },
  });
}

export function dispose() { G = null; }
void G;
