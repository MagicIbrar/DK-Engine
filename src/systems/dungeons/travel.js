// World travel (gamedata/dungeons_travel.json, docs/formats/dungeons.md "Travel"):
//
//   TELEPORT NPCs (job 2)        teleport.csv menu (stringtable_teleport prompt + "<MAPNAME> [ <LEVEL> Level / <COST> Dil ]")
//                                 -> level + dil check, dil charged, travel to the unit's location.csv point
//   RETURN NPCs (job 4)          set the Return Point (location.csv bind point = JobIndex); save.returnLocation
//   PORTAL NPCs (job 16)          "Return Portal": to the Return Point, or any portal town (portal.csv + portallocation.csv)
//   SKY_TELEPORT (job 42)         skyteleport.csv (Plane of Pilgrimage, level 130)
//   SIEGE_TELEPORT (21/127/128)   siegeteleport.csv location
//   Smart Warp                    ui_smartwarpwnd (Field / Dungeon tabs, rows of smartwarp.csv in the level range),
//                                 ui_smartwarp_alarm button, needs one Blessing Warp Stone (item 7447 / 1601022),
//                                 cast on the warpteleport window; ui_specialsmartwarp for the Dead Front / Ice Castle rows
//   Return scroll support         returnToBind() (blocked where maplist IsReturnScroll = 0)
//   Walk-in warp zones are src/systems/warpzones (coreintegrate); scripted warps (kind 'scripted') run from here.
import { D, location, mapInfo, fillSlots, sysText } from './data.js';

const WARP_STONES = [7447, 1601022];
const MSG_NO_DIL = '[Message] You do not have enough dil.';
const MSG_LOW = 'Your level is too low to enter.';
const CAST_MS = 3000;

export class Travel {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.smartTab = 1;
  }

  install() {
    const mgr = this.game.uiwin;
    if (!mgr) return;
    const self = this;
    mgr.registerWindow('smartwarp', {
      script: 'game2/smartwarp/ui_smartwarpwnd.txt',
      create(win) {
        win.control('tab_warp_1').onClick(() => { self.smartTab = 1; self._fillSmart(win); });
        win.control('tab_warp_2').onClick(() => { self.smartTab = 2; self._fillSmart(win); });
        for (let k = 0; k < 5; k++) win.control(`btn_move_${k}`).onClick(() => self._smartMove(win, k));
      },
      onOpen(win) { self._fillSmart(win); },
    });
    mgr.registerWindow('smartwarp_alarm', {
      script: 'game2/smartwarp/ui_smartwarp_alarm.txt', hud: true, escClose: false, remember: false,
      create(win) {
        const b = win.control('btn_alarm');
        b.onClick(() => mgr.toggle('smartwarp'));
        b.setTooltip(() => self._alarmTip());
      },
    });
    mgr.registerWindow('smartwarp_special', {
      script: 'game2/smartwarp/ui_specialsmartwarp.txt',
      create(win) {
        win.control('btn_move').onClick(() => self._specialMove(win));
        win.control('btn_help').onClick(() => self.sys.notice(sysTextSmart(win, 20, self.game), false));
      },
      onOpen(win, type) { self._fillSpecial(win, type); },
    });
  }

  // ------------------------------------------------------------------------------------------ helpers
  get level() { return Number(this.game.save?.level) || 1; }
  locPos(idx) {
    const l = location(idx);
    if (!l) return null;
    return { map: Number(l[0]), x: Number(l[1]) + 0.5, z: Number(l[2]) + 0.5, dirDeg: Number(l[3]) || 0, name: l[4] || '' };
  }
  go(map, pos) {
    this.game.controller?.stop?.();
    return Promise.resolve(this.game.travel(map, pos)).catch(err => console.error('[dungeons] travel', err));
  }
  _dilOk(cost) {
    const s = this.game.save;
    if ((Number(s?.dil) || 0) < cost) { this.sys.notice(MSG_NO_DIL); this.game.audio?.playOne?.(this.sys.sound?.system?.['1']?.sfx); return false; }
    return true;
  }
  _pay(cost) {
    if (!(cost > 0)) return;
    if (typeof this.game.items?.spendDil === 'function') { this.game.items.spendDil(cost); return; }
    const s = this.game.save;
    s.dil = Math.max(0, (Number(s.dil) || 0) - cost);
    this.game.events?.emit?.('dil', { amount: -cost, reason: 'teleport' });
  }

  // ------------------------------------------------------------------------------------------ teleport NPCs
  teleportMenu(npc, table) {
    const t = D.tr?.teleports?.[String(table)];
    if (!t) return false;
    const menu = t.units.filter(u => u.location && u.map != null).map(u => ({
      text: u.label || fillSlots('<MAPNAME> [ <LEVEL> Level / <COST> Dil ]', { mapName: this.locPos(u.location)?.name, level: u.level, cost: u.cost }),
      onClick: () => this.teleportTo(u),
    }));
    this.sys.dialog.open({ title: npc?.name || '', text: t.prompt || 'Where do you want to go?', menu });
    return true;
  }

  teleportTo(u) {
    const p = this.locPos(u.location);
    if (!p) return false;
    if (this.level < (Number(u.level) || 0)) { this.sys.notice(MSG_LOW); return false; }
    const cost = Number(u.cost) || 0;
    if (!this._dilOk(cost)) return false;
    this._pay(cost);
    this.game.events?.emit?.('teleport:npc', { to: p.map, location: u.location, cost });
    this.go(p.map, p);
    return true;
  }

  // ------------------------------------------------------------------------------------------ return point / portal
  setReturn(npc, locIndex) {
    const p = this.locPos(locIndex);
    const s = this.game.save;
    if (!s) return false;
    s.returnLocation = Number(locIndex);
    s.returnPoint = p ? { map: p.map, x: p.x, z: p.z } : { map: this.game.world?.info?.index, x: this.game.player?.x, z: this.game.player?.z };
    this.game.persist?.();
    const name = String(mapInfo(p?.map)?.name || p?.name || this.game.world?.info?.name || '').trim();
    // messagebox 81:87 "<center> %s has been set as the return point."
    const ref = { group: 'NORMAL', cate: 81, code: 87 };
    const strs = this.game.uiwin?.strings;
    Promise.resolve(strs?.get(ref) ?? strs?.resolve(ref)).then(t => {
      const text = String(t || '%s has been set as the return point.').replace('%s', name).replace(/<center>/g, '').trim();
      this.sys.notice(text);
      this.game.uiwin?.msgbox?.(text, { kind: 'ok' });
    });
    this.game.events?.emit?.('returnpoint', { location: locIndex, map: p?.map });
    return true;
  }

  /** Where the Return Point is (save.returnLocation / returnPoint), default Ardeca's portal arrival. */
  returnTarget() {
    const s = this.game.save || {};
    if (s.returnLocation != null) { const p = this.locPos(s.returnLocation); if (p) return p; }
    if (s.returnPoint?.map != null) return { map: Number(s.returnPoint.map), x: s.returnPoint.x, z: s.returnPoint.z, dirDeg: 0 };
    const a = (D.tr?.portalArrivals || []).find(r => r.map === 150);
    return a ? { map: 150, x: a.x + 0.5, z: a.y + 0.5, dirDeg: a.dir || 0, name: a.name } : null;
  }

  /** Return scroll: to the Return Point unless this map forbids it. */
  returnToBind() {
    const here = mapInfo(this.game.world?.info?.index);
    if (here?.flags && here.flags.returnScroll === 0) { this.sys.notice(sysTextSmart(null, 23, this.game)); return false; }
    const p = this.returnTarget();
    if (!p) return false;
    this.go(p.map, p);
    return true;
  }

  portalMenu(npc) {
    const arrivals = new Map((D.tr?.portalArrivals || []).map(a => [a.map, a]));
    const seen = new Set();
    const menu = [];
    const ret = this.returnTarget();
    if (ret) menu.push({ text: `${ret.name || mapInfo(ret.map)?.name || ''} (Return Point)`, onClick: () => this.go(ret.map, ret) });
    for (const p of D.tr?.portals || []) {
      const a = arrivals.get(p.map);
      if (!a || seen.has(p.map)) continue;
      seen.add(p.map);
      menu.push({ text: a.name || p.mapName, onClick: () => this.go(a.map, { x: a.x + 0.5, z: a.y + 0.5, dirDeg: a.dir || 0 }) });
    }
    this.sys.dialog.open({ title: npc?.name || '', text: this.sys.npcGreeting(npc) || 'The return portal will teleport you to your last\nset Return point.', menu });
    return true;
  }

  skyTeleport(npc, idx) {
    const row = (D.tr?.skyTeleports || []).find(r => r.id === Number(idx)) || (D.tr?.skyTeleports || [])[0];
    if (!row) return false;
    const menu = row.units.map(u => ({
      text: this.locPos(u.location)?.name || `Location ${u.location}`,
      onClick: () => this.teleportTo(u),
    }));
    this.sys.dialog.open({ title: npc?.name || '', text: 'Where do you want to go?', menu });
    return true;
  }

  siegeTeleport(npc, idx) {
    const rows = (D.tr?.siegeTeleports || []).filter(r => r.state !== 0);
    const row = rows.find(r => r.id === Number(idx)) || rows[0];
    const p = row ? this.locPos(row.location) : null;
    if (!p || !(p.x > 1 || p.z > 1)) { this.sys.notice(sysText(17)); return false; }
    this.go(p.map, p);
    return true;
  }

  // ------------------------------------------------------------------------------------------ smart warp
  _smartRows(type) {
    const lv = this.level;
    return (D.tr?.smartWarp || []).filter(r => r.type === type && lv >= r.levels[0] && lv <= r.levels[1]).slice(0, 5);
  }

  _alarmTip() { return sysTextSmart(null, 20, this.game).replace('%s', this.game.save?.name || ''); }

  _fillSmart(win) {
    const g = this.game;
    win.control('tab_warp_1').setChecked(this.smartTab === 1);
    win.control('tab_warp_2').setChecked(this.smartTab === 2);
    const name = win.control('lbl_name_text');
    name.setRichText?.(sysTextSmart(win, 10, g).replace('%s', g.save?.name || '').replace('%d', String(this.level)));
    const rows = this._smartRows(this.smartTab);
    win.control('lbl_move_text').setText(rows.length ? sysTextSmart(win, this.smartTab === 1 ? 6 : 7, g) : sysTextSmart(win, 5, g));
    for (let k = 0; k < 5; k++) {
      const b = win.control(`btn_move_${k}`), r = rows[k];
      b.setVisible(!!r);
      if (r) b.setText(sysTextSmart(win, this.smartTab === 1 ? 11 : 12, g).replace(/<NAME>/g, r.name).replace(/<[^>]+>/g, ''));
      b.data.row = r || null;
    }
    const n = this.sys.itemCount(WARP_STONES);
    win.control('lbl_needitem_count').setText(String(n));
    richNeed(win, g);
  }

  async _smartMove(win, k) {
    const r = win.control(`btn_move_${k}`).data.row;
    if (!r) return;
    const g = this.game;
    const here = mapInfo(g.world?.info?.index);
    if (this.sys.director || (here && here.kind !== 'field' && here.kind !== 'system')) { this.sys.notice(sysTextSmart(win, 23, g)); return; }
    if (this.sys.itemCount(WARP_STONES) < 1) { await g.uiwin.msgbox(sysTextSmart(win, 13, g).replace(/<[^>]+>/g, ''), { kind: 'ok' }); return; }
    const ok = await this.cast(sysTextSmart(win, 0, g).replace(/<[^>]+>/g, ''), sysTextSmart(win, 14, g));
    if (!ok) return;
    if (!this.sys.consumeItem(WARP_STONES, 1)) { this.sys.notice(sysTextSmart(win, 15, g)); return; }
    win.close();
    this.go(r.map, { x: r.x + 0.5, z: r.y + 0.5, dirDeg: r.dirDeg || 0 });
  }

  _fillSpecial(win, type = 3) {
    const g = this.game;
    const rows = (D.tr?.smartWarp || []).filter(r => r.type === Number(type) && this.level >= r.levels[0] && this.level <= r.levels[1]);
    const r = rows[0] || null;
    win.data.row = r;
    win.control('lbl_name_text').setRichText?.(sysTextSmart(win, Number(type) === 4 ? 9 : 8, g));
    win.control('lbl_move_text').setText(sysTextSmart(win, Number(type) === 4 ? 19 : 18, g));
    win.control('btn_move').setText(r ? r.name : '');
    win.control('btn_move').setVisible(!!r);
    win.control('lbl_needitem_count').setText(String(this.sys.itemCount(WARP_STONES)));
    richNeed(win, g);
  }

  async _specialMove(win) {
    const r = win.data.row;
    if (!r) return;
    if (this.sys.itemCount(WARP_STONES) < 1) { await this.game.uiwin.msgbox(sysTextSmart(win, 13, this.game).replace(/<[^>]+>/g, ''), { kind: 'ok' }); return; }
    const ok = await this.cast(sysTextSmart(win, 0, this.game).replace(/<[^>]+>/g, ''), sysTextSmart(win, 14, this.game));
    if (!ok || !this.sys.consumeItem(WARP_STONES, 1)) return;
    win.close();
    this.go(r.map, { x: r.x + 0.5, z: r.y + 0.5, dirDeg: r.dirDeg || 0 });
  }

  /** The warpteleport casting window (progress + Cancel). Resolves true when it completed. */
  async cast(title, text, ms = CAST_MS) {
    const mgr = this.game.uiwin;
    const win = await mgr.create('game2/ui_warpteleportwnd.txt', { name: 'warpteleport', modal: true, escClose: true, remember: false, disposeOnClose: true });
    win.control('lbl_title').setText(title || '');
    win.control('lbl_text').setText(text || '');
    const bar = win.control('processbar');
    bar.setGauge(0);
    win.control('btn_cancel').onClick(() => win.close('cancel'));
    return new Promise((resolve) => {
      let t = 0, done = false;
      win.on('update', (dt) => { if (done) return; t += dt * 1000; bar.setGauge(Math.min(1, t / ms)); if (t >= ms) { done = true; win.close('done'); } });
      win.once('close', (r) => { done = true; resolve(r === 'done'); });
      mgr.openWindow(win);
    });
  }

  /** Scripted warp (warp.csv kind 'scripted', fired by map scripts / NPCs). */
  scriptedWarp(id) {
    const w = (D.tr?.warps || []).find(x => x.id === Number(id));
    if (!w) return false;
    const p = this.locPos(w.to);
    if (!p) return false;
    this.go(p.map, p);
    return true;
  }
}

/** "Use: Blessing Warp Stone <color=ffa500>...(x1)</color>" (6000 4) carries client colour markup: render it. */
function richNeed(win, game) {
  const c = win.control('lbl_needitem');
  const t = sysTextSmart(win, 4, game);
  if (c && t && /<color|<#/i.test(t)) c.setRichText(t);
}

/** A smart-warp string (NORMAL cate 6000) through the window's string tables (loaded with the window). */
export function sysTextSmart(win, code, game) {
  const mgr = win?.mgr || game?.uiwin;
  const v = mgr?.strings?.get({ group: 'NORMAL', cate: 6000, code });
  if (v == null) mgr?.strings?.resolve({ group: 'NORMAL', cate: 6000, code });
  return v ?? '';
}
