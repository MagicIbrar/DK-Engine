// Auto-find: click-to-travel to NPCs and places, and the client's "find auto" check.
//
// 1. game.findAuto.goTo({map, x, z}) / goToNpc(npcIndex) / goToLocation(locationIndex) / goToDungeon(dungeonId):
//    walks the player there with the normal A* movement (controller.moveTo), across maps through the walk-in warp
//    zones and the teleport NPCs of dungeons_travel.json (mapGraph + warps + teleports): the route is a BFS over
//    the map graph; each leg walks into the warp rectangle (or to the teleport NPC, then teleports with its dil
//    cost). A manual move / attack order cancels it. Arriving at an NPC opens its dialog.
//    Events: 'findauto' {state: 'start'|'leg'|'arrive'|'cancel'|'fail', target}.
//
// 2. share/findauto/config.csv (SAFEAUTOTIME 600, GIVEDIL 100, ANSWERTIME 60, MAXFAILCOUNT 3, ITEMINDEX 56901
//    "Anti-Auto") is the anti-macro "Auto Prevent System" (window game2/autousercheck/ui_autoquestionwnd.txt, maplist
//    IsFindAuto = 1 on 140 raw map rows). Original service admission/scheduling and item56901's handler are
//    unknown. The existing optional solo practice uses ENGINE-CHOSEN arming/three digits/item skip;
//    native config supplies its 60 s/+100 DIL/3 miss values. Shared-server practice refuses admission,
//    including direct opening and late answers; no original challenge service is claimed here.
import { D, location, dungeonById, mapInfo } from './data.js';
import { fetchCSV } from '../../engine/assets.js';

const REACH = 2.5;

export class FindAuto {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.target = null;       // {map, x, z, npc?, name}
    this.route = null;        // [{from, to, via, ref}]
    this.cfg = { SAFEAUTOTIME: 600, GIVEDIL: 100, ANSWERTIME: 60, MAXFAILCOUNT: 3, ITEMINDEX: 56901 };
    this.safeUntil = 0;
    this.fails = 0;
  }

  install() {
    const g = this.game, self = this;
    g.findAuto = {
      goTo: (t) => self.goTo(t),
      goToNpc: (i) => self.goToNpc(i),
      goToLocation: (i) => self.goToLocation(i),
      goToDungeon: (id) => self.goToDungeon(id),
      cancel: () => self.cancel('api'),
      get target() { return self.target; },
      route: (from, to) => self.findRoute(from, to),
      question: () => self.question(),
    };
    fetchCSV('share/findauto/config.csv').then(rows => {
      for (const r of rows) if (r[0] && r[1] != null) { const v = Number(r[1]); if (Number.isFinite(v)) this.cfg[String(r[0]).trim()] = v; }
    }).catch(() => {});
    g.uiwin?.registerWindow('autoquestion', {
      script: 'game2/autousercheck/ui_autoquestionwnd.txt', modal: true, escClose: false,
      create(win) {
        win.control('btn_answer').onClick(() => self._answer(win));
        win.control('edit_answer').on('enter', () => self._answer(win));
      },
      onOpen(win) { self._fillQuestion(win); },
      update(win, dt) { self._tickQuestion(win, dt); },
    });
  }

  // ------------------------------------------------------------------------------------------ routes
  /** BFS over the map graph: walk-in warps and teleport NPCs. Returns [{from, to, via, ref}] or null. */
  findRoute(from, to) {
    from = Number(from); to = Number(to);
    if (from === to) return [];
    const G = D.tr?.mapGraph || {};
    const prev = new Map([[from, null]]);
    const q = [from];
    while (q.length) {
      const m = q.shift();
      for (const e of G[m] || []) {
        if (e.via !== 'warp' && e.via !== 'teleport') continue;
        const n = Number(e.to);
        if (prev.has(n)) continue;
        prev.set(n, { from: m, ...e, to: n });
        if (n === to) {
          const out = [];
          for (let k = n; prev.get(k); k = prev.get(k).from) out.unshift(prev.get(k));
          return out;
        }
        q.push(n);
      }
    }
    return null;
  }

  goTo(t) {
    const g = this.game;
    if (!t || t.map == null || !g.world || !g.player) return false;
    const here = g.world.info.index;
    const route = this.findRoute(here, t.map);
    if (!route) { this._event('fail', t); this.sys.notice(`${mapInfo(t.map)?.name || ''}: no route.`); return false; }
    this.target = { ...t, map: Number(t.map) };
    this.route = route;
    this._event('start', this.target);
    this._leg();
    return true;
  }

  goToLocation(i) {
    const l = location(i);
    return l ? this.goTo({ map: l[0], x: l[1] + 0.5, z: l[2] + 0.5, name: l[4] }) : false;
  }

  goToNpc(npcIndex) {
    const g = this.game;
    const live = (g.npcs || []).find(n => Number(n.npcIndex) === Number(npcIndex));
    if (live) { const point=live.interactPoint || live; return this.goTo({map:g.world.info.index,x:point.x,z:point.z,npc:Number(npcIndex),name:live.name}); }
    const pl = g.data?.npcs?.placements || {};
    const here = g.world?.info?.index;
    let best = null;
    for (const [m, p] of Object.entries(pl)) {
      for (const r of p.rows || []) {
        if (Number(r[0]) !== Number(npcIndex)) continue;
        const route = Number(m) === here ? [] : this.findRoute(here, m);
        if (!route) continue;
        const cost = route.length * 1000 + (Number(m) === here ? Math.hypot(r[1] - g.player.x, r[2] - g.player.z) : 0);
        if (!best || cost < best.cost) best = { cost, map: Number(m), x: r[4] > 1 ? r[4] + 0.5 : r[1], z: r[5] > 1 ? r[5] + 0.5 : r[2], npc: Number(npcIndex) };
      }
    }
    if (!best) return false;
    best.name = g.data?.npcs?.npcs?.[npcIndex]?.name || '';
    return this.goTo(best);
  }

  goToDungeon(id) {
    const dn = dungeonById(id);
    const n = dn?.entry?.npcs?.[0];
    if (n) return this.goTo({ map: n.map, x: (n.warp?.[0] ?? n.x) + 0.5, z: (n.warp?.[1] ?? n.y) + 0.5, npc: n.npc, name: n.name });
    const f = dn?.entry?.fallback;
    return f ? this.goTo({ map: f.map, x: f.x + 0.5, z: f.y + 0.5, name: dn.name }) : false;
  }

  cancel(reason = 'cancel') {
    if (!this.target) return;
    const t = this.target;
    this.target = null; this.route = null; this._order = null;
    this._event('cancel', { ...t, reason });
  }

  _event(state, target) { this.game.events?.emit?.('findauto', { state, target }); }

  _leg() {
    const g = this.game, t = this.target;
    if (!t || !g.world) return;
    const here = g.world.info.index;
    if (here === t.map) { this._walk(t.x, t.z, 'final'); return; }
    const leg = this.route?.find(e => Number(e.from) === here);
    if (!leg) { const r = this.findRoute(here, t.map); if (!r) { this.cancel('lost'); return; } this.route = r; return this._leg(); }
    this._event('leg', { ...t, leg });
    if (leg.via === 'warp') {
      const w = (D.tr?.warps || []).find(x => x.id === Number(leg.ref));
      if (!w?.box) { this.cancel('nowarp'); return; }
      const [x0, y0, x1, y1] = w.box;
      // a walkable cell of the warp rectangle (the zone fires as soon as the player stands inside it)
      let best = null;
      const p = g.player;
      for (let cz = y0; cz < Math.max(y0 + 1, y1); cz++) for (let cx = x0; cx < Math.max(x0 + 1, x1); cx++) {
        if (!g.world.isWalkable(cx + 0.5, cz + 0.5)) continue;
        const d = Math.hypot(cx + 0.5 - p.x, cz + 0.5 - p.z);
        if (!best || d < best.d) best = { x: cx + 0.5, z: cz + 0.5, d };
      }
      this._walk(best ? best.x : (x0 + x1) / 2 + 0.5, best ? best.z : (y0 + y1) / 2 + 0.5, 'warp');
    } else if (leg.via === 'teleport') {
      const [npc, table] = String(leg.ref).split(':').map(Number);
      const row = (g.data?.npcs?.placements?.[here]?.rows || []).find(r => Number(r[0]) === npc);
      if (!row) { this.cancel('nonpc'); return; }
      this._walk(row[4] > 1 ? row[4] + 0.5 : row[1], row[5] > 1 ? row[5] + 0.5 : row[2], 'teleport', { npc, table });
    }
  }

  _walk(x, z, kind, extra = {}) {
    const c = this.game.controller;
    if (!c?.moveTo) { this.cancel('nocontroller'); return; }
    c.moveTo(x, z);
    this._order = c.order;
    this._goal = { x, z, kind, ...extra };
    this._stuck = 0;
    this._retries = 0;
  }

  onMap() { if (this.target) setTimeout(() => this._leg(), 300); }

  update(dt) {
    if (!this.target || !this._goal) return;
    const g = this.game, p = g.player, c = g.controller;
    if (!p || p.dead) return;
    const d = Math.hypot(p.x - this._goal.x, p.z - this._goal.z);
    if (c && c.order && c.order !== this._order) { this.cancel('manual'); return; }   // another order: stop following
    if (d > REACH) {
      if (!c?.order) {
        // the path ended short (blocked goal / interrupted): retry a few times, then accept a near arrival
        this._stuck += dt;
        if (this._stuck > 0.6) {
          this._retries = (this._retries || 0) + 1;
          if (this._retries > 3) { if (d < 6 && this._goal.kind === 'final') { this._stuck = 0; } else { this.cancel('stuck'); return; } }
          else { c.moveTo(this._goal.x, this._goal.z); this._order = c.order; this._stuck = 0; return; }
        } else return;
      } else return;
    }
    this._retries = 0;
    const goal = this._goal;
    this._goal = null;
    if (goal.kind === 'final') {
      const t = this.target;
      this.target = null; this.route = null;
      this._event('arrive', t);
      if (t.npc != null) {
        const npc = g.npcs?.find(n => Number(n.npcIndex) === Number(t.npc));
        if (npc) g.windows?.openNpc?.(npc);
      }
    } else if (goal.kind === 'teleport') {
      const leg = this.route?.find(e => Number(e.from) === g.world.info.index);
      const tp = D.tr?.teleports?.[String(goal.table)];
      const u = tp?.units?.find(x => Number(x.map) === Number(leg?.to));
      if (!u || !this.sys.travel.teleportTo(u, { npc: goal.npc, table: goal.table })) this.cancel('teleport');
    }
    // 'warp': the warp zone fires by itself (warpzones system); onMap continues
  }

  // ------------------------------------------------------------------------------------------ find-auto check
  _armed() {
    const g = this.game;
    if (g.save?.authority === 'server') return false; // host challenge admission is not implemented
    if (!g.settings?.autoCheck) return false;
    const row = g.mapRow?.(g.world?.info?.index);
    return String(row?.IsFindAuto ?? mapInfo(g.world?.info?.index)?.raw?.IsFindAuto ?? '0') === '1';
  }

  tick(dt) {
    if (!this._armed() || this.game.uiwin?.isOpen('autoquestion')) return;
    if (this.game.time < this.safeUntil) return;
    if (this.sys.itemCount([this.cfg.ITEMINDEX]) > 0) { this.safeUntil = this.game.time + this.cfg.SAFEAUTOTIME; return; }
    this.safeUntil = this.game.time + this.cfg.SAFEAUTOTIME;
    this.question();
  }

  question() {
    if (this.game.save?.authority === 'server') {
      this.game.chat?.system?.('Automatic player checks are not supported by this server.', 'err');
      return false;
    }
    this.q = { digits: [0, 1, 2].map(() => Math.floor(Math.random() * 10)), t: this.cfg.ANSWERTIME, misses: 0 };
    return this.game.uiwin?.open('autoquestion');
  }

  _fillQuestion(win) {
    const q = this.q || (this.q = { digits: [1, 2, 5], t: this.cfg.ANSWERTIME, misses: 0 });
    // ENGINE-CHOSEN presentation repair: the old autocheck number rows were
    // removed from the native atlas. Existing native number glyphs keep this
    // optional local practice challenge readable without synthesizing art.
    q.digits.forEach((d, i) => win.control(`pan_question_${i}`).setSprite('ImageNumber_01', d));
    for (let i = 0; i < 3; i++) win.control(`pan_fail_${i}`).setVisible(i < q.misses);
    win.control('edit_answer').setValue?.('');
    win.control('edit_answer').focus?.();
  }

  _tickQuestion(win, dt) {
    const q = this.q;
    if (!q) return;
    q.t -= dt;
    const lbl = win.control('lbl_descript');
    const s = win.mgr.strings.get({ group: 'NORMAL', cate: 280, code: 102 }) || 'Answer the question in %d seconds.';
    lbl.setText(s.replace('%d', String(Math.max(0, Math.ceil(q.t)))));
    if (q.t <= 0) this._miss(win);
  }

  _answer(win) {
    if (this.game.save?.authority === 'server') { this.q = null; win.close('unsupported'); return; }
    const q = this.q;
    if (!q) return;
    const v = String(win.control('edit_answer').getValue?.() ?? '').trim();
    if (v === q.digits.join('')) {
      const g = this.game;
      if (typeof g.items?.addDil === 'function') g.items.addDil(this.cfg.GIVEDIL); else g.save.dil = (Number(g.save.dil) || 0) + this.cfg.GIVEDIL;
      g.events?.emit?.('loot', { name: 'Dil', count: this.cfg.GIVEDIL });
      this.safeUntil = g.time + this.cfg.SAFEAUTOTIME;
      this.q = null;
      win.close('ok');
      this._result(113);        // "A reward has been given because you are not using macro."
      return;
    }
    this._miss(win);
  }

  /** The result box (game2/msgbox/ui_autocheckresult.txt): message 280:code, Ok, a 5 s bar that closes it. */
  async _result(code) {
    const mgr = this.game.uiwin;
    if (!mgr?.create) return;
    try {
      const win = await mgr.create('game2/msgbox/ui_autocheckresult.txt', { name: 'autocheckresult', modal: false, escClose: true, remember: false, disposeOnClose: true });
      const ref = { group: 'NORMAL', cate: 280, code };
      await mgr.strings?.need?.([ref]);
      win.control('lbl_text').setText(mgr.strings?.get(ref) || '');
      win.control('btn_yes').onClick(() => win.close('ok'));
      const bar = win.control('processbar');
      bar.setGauge?.(1);
      let t = 0;
      win.on('update', (dt) => { t += dt; bar.setGauge?.(Math.max(0, 1 - t / 5)); if (t >= 5) win.close('timeout'); });
      mgr.openWindow(win);
    } catch (err) { console.warn('[dungeons] auto check result', err); }
  }

  _miss(win) {
    const q = this.q;
    q.misses++;
    q.t = this.cfg.ANSWERTIME;
    q.digits = [0, 1, 2].map(() => Math.floor(Math.random() * 10));
    if (q.misses >= this.cfg.MAXFAILCOUNT) {
      this.q = null;
      win.close('fail');
      this._result(112);        // "You are identified as macro user and will be moved to return location."
      const r = this.game.respawnTarget?.();
      if (r) this.game.travel(r.mapIndex, r);
      return;
    }
    this._fillQuestion(win);
  }
}
