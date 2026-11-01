// Fishing (share/fishing, share/arrange/cell.csv, class action tables style 23, stringtable_fishing SYSTEM 130).
//
// Flow (the original client + server rules the data describes):
//   1. A fishing rod (item type 4 code 19 manual / code 30 auto) in the weapon slot, the class's Fishing Mastery
//      skill (fishingskill.csv, e.g. 181 for the Azure Knight) learned, standing on or facing fishing water
//      (.mac cell whose cell.csv row has Fishing = Y: 100-105 water, 106-110 shallows, 201-210, 301-310).
//      Checks -> SYSTEM 130:3 no rod, 130:8 no skill, 130:4 not a fishing area, 130:5 too far, 130:6 skill too low,
//      130:16 mounted, 130:9 busy, 130:10 already fishing.
//   2. Cast: OPENFISHING 0 (throw) then OPENFISHING 1 (keep, loop); the fishing window (game2/fishing/
//      ui_fishingwnd.txt) shows pan_casting: pro_casting fills over CAST_MS, btn_cancel stops. When it is full the
//      cell's FishingCasting (bite chance per 100 000: Braiken stream 55 %, Ares 60 %, Deneb/Requies 5 %, Avalon 20 %,
//      the Braiken/Loa moat 0 %) decides: no bite -> "The fish are laughing at you. You got diddly..." (130:7). BGM playlist 1000 (fishing) replaces the map music while fishing, 1001 during the fight.
//      One bait (item type 0 code 19) is used per cast when the bag has any.
//   3. Bite: a fish is drawn from the cell's FishIndex/FishRatio list (weights, total 100 000). Fight = pan_fighting:
//      the line gauge pro_line (rod MaxHP from fishingrod.csv) and the fish gauge pro_fish (fish MaxHP, starting at
//      StartHP). The fish alternates between resting (DelayTime ms) and resisting (ResistRatio / 100 000 chance at
//      each decision, for ResistTime ms). The player pulls (FISHFIGHTING 0) while the left mouse button is held on
//      the fishing window or Space is held, else relaxes (FISHFIGHTING 1):
//        pulling while the fish rests   -> fish HP - rod Strength / s
//        pulling while the fish resists -> line HP - fish Strength / s
//        relaxing                       -> line HP + rod Recovery / s, fish HP + fish Recovery / s
//      Line 0 -> "line snapped" (130:0, CLOSEFISHING 1); fish HP full -> "the fish got away" (130:1, CLOSEFISHING 2);
//      fish HP 0 -> caught (CLOSEFISHING 0): one of the fish's ItemSets by ItemSetDropRatio, then an item of the set by
//      weight (share/item/itemset.csv), shown in the fishgiveitem window, "You have caught %s." (130:11), fish Exp as
//      character EXP. Full bag -> 130:2. Cancelling a fight: "You missed the fish." (130:14).
//   4. Auto fishing rods (rod rows 7-9 auto): cast -> the cell's AutoFishIndex_1/2/Unique fish is landed without a
//      fight at the end of every cast, EXP = exp.json autoFishExp of the level, until cancelled.
// Decision: the shipped Fishing Mastery has max level 1 while some cells ask FishSkillLevelMin 2..4; a requirement
// above the skill's own cap is treated as met by a maxed skill (otherwise Deneb/Requies/Avalon/Crespo/Draco water
// could never be fished with this client's data).
import { msgRef, str, itemInfo, countItem, takeItem, giveItem, canGive, equippedWeapon, weighted, setItemIcon, rand } from './common.js';
import { resetAnimState } from '../../game/combat.js';

const FISH_STR = (code) => [130, code, 'SYSTEM'];
const CAST_MS = 8000;       // the casting bar (the data has no casting length; OPENFISHING throw 2 s + 3 keep loops)
const MAX_REACH = 4.5;      // units in front of the player a fishing cell may be
const NEAR_REACH = 9;       // "too far" beyond this

export class Fishing {
  constructor(game, life) {
    this.game = game;
    this.life = life;
    this.F = life.data?.fishing || null;
    this.active = null;         // { phase: 'cast'|'fight'|'close', ... }
    this.win = null;
    this._pull = false;
  }

  async install() {
    const g = this.game;
    g.ui?.registerWindow?.('fishing', {
      script: 'game2/fishing/ui_fishingwnd.txt', escClose: false, remember: false, hud: true,
      create: (win) => this._create(win),
      // the gauge sits centred above the quick slots (the script's 50,99 box is the client's 800x600-era spot)
      onOpen: (win) => { const s = g.uiwin.screen; win.setPosition(Math.round((s.w - 462) / 2), Math.round(s.h * 0.64)); },
    });
    g.ui?.registerWindow?.('fishgiveitem', { script: 'game2/fishing/ui_fishgiveitemwnd.txt', escClose: true, hud: true, remember: false });
    // "Cast fishing rod" (keymap action 208, default L) and the main menu's fishing button
    g.uiwin?.registerMenuButton?.('btn_fishing', () => this.toggle());
    // the Fishing Mastery skill used from the skill window / hotbar casts too
    g.events?.on?.('skill', ({ actor, skill }) => { if (actor === g.player && this._isFishingSkill(skill?.index ?? skill)) this.start(); });
    this._keyDown = (e) => { if (e.code === 'Space' && this.active?.phase === 'fight') { this._pull = true; e.preventDefault(); } };
    this._keyUp = (e) => { if (e.code === 'Space') this._pull = false; };
    addEventListener('keydown', this._keyDown, true);
    addEventListener('keyup', this._keyUp, true);
  }

  _isFishingSkill(i) { return Object.values(this.F?.skills || {}).includes(Number(i)); }

  _create(win) {
    this.win = win;
    win.control('btn_cancel').onClick(() => this.stop('cancel'));
    for (const id of ['pan_fighting', 'pan_fightingbg', 'pan_fighting_eff', 'pan_reel', 'pan_back']) {
      const c = win.control(id);
      c.on('down', () => { this._mousePull = true; });
      c.on('up', () => { this._mousePull = false; });
      c.on('out', () => { this._mousePull = false; });
    }
    win.control('pan_reel').setTooltip(() => 'Hold to reel in (Space)');
  }

  // ---------------------------------------------------------------------------------------- checks
  _rod() {
    const w = equippedWeapon(this.game);
    const rodIdx = w ? this.F?.rodItems?.[String(w)] : null;
    return rodIdx != null ? { item: w, index: rodIdx, ...this.F.rods[String(rodIdx)] } : null;
  }
  _skillLevel() {
    const cls = Number(this.game.save?.classIndex) || 0;
    const si = this.F?.skills?.[String(cls)];
    if (!si) return { index: null, level: 0, max: 1 };
    const lv = Number(this.game.save?.skills?.[si] ?? this.game.save?.skills?.[String(si)]) || Number(this.game.skills?.skillLevel?.(si)) || 0;
    const def = this.game.data?.skills?.skills?.[si];
    return { index: si, level: lv, max: Number(def?.maxLevel?.normal) || 1 };
  }
  /** The fishing cell the player stands on or faces: {x, z, attr, cell, dist} or {error: code}. */
  _findSpot() {
    const p = this.game.player, w = this.game.world;
    const col = w?.collision;
    if (!p || !col) return { error: 4 };
    const fx = -Math.sin(p.yaw), fz = -Math.cos(p.yaw);
    let nearest = null;
    for (let d = 0; d <= NEAR_REACH; d += 0.5) {
      // straight ahead first, then a small fan
      for (const a of [0, 0.35, -0.35, 0.7, -0.7]) {
        const c = Math.cos(a), s = Math.sin(a);
        const dx = fx * c - fz * s, dz = fx * s + fz * c;
        const x = p.x + dx * d, z = p.z + dz * d;
        const attr = col.attrAt(x, z);
        const cell = this.F?.cells?.[String(attr)];
        if (cell && cell.fishing && cell.fish.length) { nearest = { x, z, attr, cell, dist: d }; break; }
      }
      if (nearest) break;
    }
    if (!nearest) return { error: 4 };
    if (nearest.dist > MAX_REACH) return { error: 5 };
    return nearest;
  }

  async _say(code, kind = 'err', ...args) { return msgRef(this.game, ...FISH_STR(code), kind, ...args); }

  toggle() { if (this.active) this.stop('cancel'); else this.start(); }

  // ---------------------------------------------------------------------------------------- start
  async start() {
    const g = this.game, p = g.player;
    if (!this.F || !p || p.dead) return false;
    if (this.active) { this._say(10); return false; }
    if (g.mounts?.riding || p.mounted) { this._say(16); return false; }
    if (g.skills?.busy || (p.target && !p.target.dead && p.lastCombat != null && g.time - p.lastCombat < 2)) { this._say(9); return false; }
    const rod = this._rod();
    if (!rod) { this._say(3); return false; }
    // (the rod item's own level requirement is enforced when it is equipped; fishingrod.csv RequirePCLevel belongs
    // to the old rod rows the 255 "unusable rod" items were mapped onto, so it is not applied twice)
    const sk = this._skillLevel();
    if (!sk.index || sk.level < 1) {
      // Fishing Mastery is learned automatically once reqLevel is met (skills.js rule for level-1 skills)
      const auto = g.skills?.skillLevel?.(sk.index);
      if (!(auto >= 1)) { this._say(8); return false; }
      sk.level = auto;
    }
    const spot = this._findSpot();
    if (spot.error) { this._say(spot.error); return false; }
    const need = spot.cell.skillMin || 0;
    if (need > sk.level && sk.level < sk.max) { this._say(6); return false; }
    // face the water, leave the battle stance (the controller's stance timer would replace the fishing motions)
    p.faceTowards?.(spot.x, spot.z);
    g.controller?.stop?.();
    this.life.emotes?.cancel();
    p.lastCombat = null; p._gpState = 'idle'; p._gpHold = 0;
    const bait = this._useBait();
    this.active = { phase: 'cast', rod, spot, cell: spot.cell, t: 0, castMs: CAST_MS, biteChance: Number(spot.cell.casting) || 0, bait, auto: !!rod.auto };
    this._anim('OPENFISHING:0', false, () => { if (this.active?.phase === 'cast') this._anim('OPENFISHING:1', true); });
    this._music(1000);
    const win = await g.uiwin.open('fishing');
    this.win = win;
    this._showPhase('cast');
    g.events?.emit?.('life:fishing', { phase: 'cast', auto: this.active?.auto });
    return true;
  }

  _useBait() {
    for (const [k] of Object.entries(this.F?.baits || {}).sort((a, b) => b[1] - a[1])) {
      if (countItem(this.game, k) > 0) { takeItem(this.game, k, 1); return Number(k); }
    }
    return null;
  }

  _anim(key, loop, onEnd) {
    const p = this.game.player;
    const cls = Number(this.game.save?.classIndex) || 0;
    const rec = this.life.data?.classMotions?.[cls]?.fishing?.[key];
    if (!rec || !p) { if (onEnd) setTimeout(onEnd, 300); return; }
    const state = `fish:${key}`;
    this._state = state;
    p.play(state, { anim: rec.anim, timeLength: rec.t, loop, fade: 0.12, onEnd: loop ? undefined : onEnd });
    const eff = rec.effect;
    if (eff) this.game.audio?.playAll?.(this.game.data?.sound?.actionEffectSfx?.pc?.[String(eff)], { at: { x: p.x, z: p.z } });
  }

  _music(idx) {
    const a = this.game.audio;
    if (!a?.playBGM) return;
    if (this._prevMusic == null) this._prevMusic = a.music?.mapIndex ?? this.game.world?.info?.index;
    a.playBGM(String(idx));
  }
  _restoreMusic() {
    const a = this.game.audio;
    if (this._prevMusic != null && a?.playBGM) a.playBGM(this.game.world?.info?.index ?? this._prevMusic);
    this._prevMusic = null;
  }

  _showPhase(phase) {
    const w = this.win;
    if (!w) return;
    w.control('pan_casting').setVisible(phase === 'cast');
    w.control('pan_fighting').setVisible(phase === 'fight');
  }

  // ---------------------------------------------------------------------------------------- update
  update(dt) {
    const A = this.active, g = this.game, p = g.player;
    if (!A) return;
    if (!p || p.dead || !g.world) { this.stop('abort'); return; }
    // any other animation state (moved, attacked, hit, skill) ends fishing
    if (A.phase !== 'close' && p.state && !String(p.state).startsWith('fish:')) { this.stop(A.phase === 'fight' ? 'miss' : 'abort'); return; }
    A.t += dt * 1000;
    if (A.phase === 'cast') {
      const f = Math.min(1, A.t / A.castMs);
      this.win?.control('pro_casting').setGauge(f);
      if (f >= 1) {
        if (A.auto) this._autoCatch();
        else this._bite();
      }
    } else if (A.phase === 'fight') this._fight(dt);
  }

  _bite() {
    const A = this.active;
    // FishingCasting = bite chance per 100 000 (bait of a higher grade - value1 - adds its grade x 1 %: decision,
    // the data gives bait no other effect)
    const chance = A.biteChance + (A.bait ? (this.F.baits?.[String(A.bait)] || 0) * 1000 : 0);
    if (!(Math.random() * 100000 < chance)) { this._finish('nothing'); return; }
    const pick = weighted(A.cell.fish);
    const fish = pick ? this.F.fish[String(pick[0])] : null;
    if (!fish) { this._finish('nothing'); return; }
    A.phase = 'fight';
    A.fishIndex = pick[0];
    A.fish = fish;
    A.fishHp = fish.startHp || fish.maxHp * 0.65;
    A.lineHp = A.rod.maxHp;
    A.resisting = false;
    A.timer = rand(fish.delayMin, fish.delayMax);
    this._pulling = null;
    this._showPhase('fight');
    this.win?.control('pan_fish_rank').setImage('none', 'fishing_rank', Math.max(1, fish.rank || 1));
    this._music(1001);
    this.game.events?.emit?.('life:fishing', { phase: 'fight', fish: A.fishIndex });
  }

  _fight(dt) {
    const A = this.active, F = A.fish, R = A.rod;
    // fish behaviour
    A.timer -= dt * 1000;
    if (A.timer <= 0) {
      if (A.resisting) { A.resisting = false; A.timer = rand(F.delayMin, F.delayMax); }
      else if (Math.random() * 100000 < (F.resistRatio || 0)) { A.resisting = true; A.timer = rand(F.resistMin, F.resistMax); }
      else A.timer = rand(F.delayMin, F.delayMax);
    }
    const pulling = !!(this._pull || this._mousePull);
    if (pulling !== this._pulling) { this._pulling = pulling; this._anim(pulling ? 'FISHFIGHTING:0' : 'FISHFIGHTING:1', true); }
    if (pulling) {
      if (A.resisting) A.lineHp -= (F.strength || 10) * dt;
      else A.fishHp -= (R.strength || 4) * dt;
    } else {
      A.lineHp = Math.min(R.maxHp, A.lineHp + (R.recovery || 1) * dt);
      A.fishHp = Math.min(F.maxHp, A.fishHp + (F.recovery || 1) * dt);
    }
    // window
    const w = this.win;
    if (w) {
      const lf = Math.max(0, A.lineHp / R.maxHp), ff = Math.max(0, A.fishHp / F.maxHp);
      w.control('pro_line').setGauge(lf);
      w.control('pro_fish').setGauge(ff);
      w.control('pan_line').setRect(Math.round(lf * 343), 1, 44, 23);
      w.control('pan_fish').setRect(Math.round(ff * 343), 47, 44, 23);
      const shake = A.resisting ? (Math.random() * 4 - 2) : 0;
      w.control('pan_fish').el.style.transform = shake ? `translate(${shake}px, ${Math.random() * 2 - 1}px)` : '';
      const reel = w.control('pan_reel');
      reel.data.rot = (reel.data.rot || 0) + (pulling ? dt * 720 : 0);
      if (reel.bg) reel.bg.style.transform = `rotate(${reel.data.rot}deg)`;
    }
    if (A.lineHp <= 0) this._finish('snap');
    else if (A.fishHp >= F.maxHp) this._finish('escape');
    else if (A.fishHp <= 0) this._finish('catch');
  }

  _autoCatch() {
    const A = this.active;
    const slot = Math.max(0, Math.min(2, (A.rod.index || 7) - 7));
    const fi = A.cell.auto?.[slot] || A.cell.auto?.[0];
    A.fishIndex = fi;
    A.fish = this.F.fish[String(fi)];
    this._finish('catch', true);
  }

  async _finish(result, auto = false) {
    const A = this.active, g = this.game;
    if (!A || A.phase === 'close') return;
    A.phase = 'close';
    this._showPhase('none');
    let item = null;
    if (result === 'catch') {
      const set = this._rollSet(A.fish);
      if (set) {
        if (!canGive(g, set.item, set.count)) { await this._say(2); result = 'full'; }
        else {
          giveItem(g, set.item, set.count, { silent: true, source: 'fishing' });
          item = set;
          const name = itemInfo(g, set.item)?.name || '';
          await this._say(11, 'item', name);
          this._showCatch(set.item);
        }
      } else { await this._say(7); result = 'nothing'; }
      // exp: fish Exp (manual) / exp.json autoFishExp of the level (auto rods)
      const lv = Number(g.save.level) || 1;
      const exp = auto ? Number(g.data?.exp?.levels?.[lv - 1]?.autoFishExp) || 0 : Number(A.fish?.exp) || 0;
      if (exp > 0) { try { const { grantExp } = await import('../../game/progression.js'); grantExp(g, exp); } catch { /* optional */ } }
      g.events?.emit?.('fish', { count: 1, fish: A.fishIndex, item: item?.item || null });
      g.events?.emit?.('life:fishing', { phase: 'catch', fish: A.fishIndex, item: item?.item || null });
    } else if (result === 'snap') await this._say(0);
    else if (result === 'escape') await this._say(1);
    else if (result === 'nothing') await this._say(7);
    const close = result === 'catch' || result === 'full' ? 'CLOSEFISHING:0' : result === 'snap' ? 'CLOSEFISHING:1' : 'CLOSEFISHING:2';
    this._anim(close, false, () => {
      if (this.active !== A) return;
      if (auto && result === 'catch') { this.active = null; this.start(); return; }   // auto rods keep fishing
      this._end();
    });
  }

  /** One item from the fish's item sets (ItemSetDropRatio weights) -> {item, count} or null. */
  _rollSet(fish) {
    if (!fish?.sets?.length) return null;
    const pick = weighted(fish.sets, 100000);
    const set = pick ? this.F.sets?.[String(pick[0])] : null;
    if (!set?.items?.length) return null;
    const total = set.items.reduce((s, x) => s + x[1], 0);
    const it = weighted(set.items.map((x) => [x, x[1]]), Math.max(total, set.total || 0))?.[0];
    if (!it) return null;
    const lo = Math.max(1, it[2] || 1), hi = Math.max(lo, it[3] || lo);
    const stackable = (itemInfo(this.game, it[0])?.stack || 0) > 1;
    return { item: it[0], count: stackable ? lo + Math.floor(Math.random() * (hi - lo + 1)) : 1 };
  }

  async _showCatch(itemIndex) {
    const g = this.game;
    const w = await g.uiwin.open('fishgiveitem');
    const h = itemInfo(g, itemIndex)?.h || 2;
    const big = h > 2;
    w.control('pan_item_2').setVisible(!big);
    w.control('pan_item_4').setVisible(big);
    await setItemIcon(g, w.control(big ? 'giveitem_4' : 'giveitem_2'), itemIndex, 0);
    clearTimeout(this._catchT);
    this._catchT = setTimeout(() => g.uiwin.close('fishgiveitem'), 3500);
  }

  /** Stop fishing. reason: 'cancel' (button / key), 'miss' (moved away during a fight), 'abort'. */
  stop(reason = 'cancel') {
    const A = this.active;
    if (!A) return;
    if (A.phase === 'fight' && (reason === 'cancel' || reason === 'miss')) this._say(14, 'sys');
    if (reason === 'cancel' && A.phase !== 'close') {
      A.phase = 'close';
      this._showPhase('none');
      this._anim('CLOSEFISHING:2', false, () => { if (this.active === A) this._end(); });
      return;
    }
    this._end();
  }

  _end() {
    const g = this.game;
    this.active = null;
    this._pull = this._mousePull = false;
    this._pulling = null;
    g.uiwin?.close('fishing');
    this._restoreMusic();
    if (g.player && !g.player.dead) resetAnimState(g.player);
    if (g.player?.state && String(g.player.state).startsWith('fish:')) g.player.play('idle', { loop: true });
    g.events?.emit?.('life:fishing', { phase: 'end' });
  }

  onMap() { if (this.active) this._end(); }

  dispose() {
    removeEventListener('keydown', this._keyDown, true);
    removeEventListener('keyup', this._keyUp, true);
  }
}

export { str };
