// Premium services (docs/formats/shops.md 4.2 "premium"): share/item/premiereitem.csv rows
//   [Time, ExpAdd, Rate, PartyBonusRate, Teleport, Respon, StatusIndex, StoreIndex, Post, Brokerage, PartyWarp,
//    NpcWarp, ItemUpgradeRate, RuneIndex]
// Using a premium item (Growth Blessing, Holy Water of the Almighty...) starts a timed account service (real time, like the
// original's server clock). Rules (shared with the authoritative server) live in premium-rules.js:
//   * Rate %: extra EXP (game.expModifiers hook read by progression.grantExp); online the server adds it to the reward
//   * StatusIndex: a status.csv buff kept in save.buffs while active (e.g. 6644 All Stat +35)
//   * StoreIndex: the remote store (shop 5 "[Grocery Shop]") from anywhere
//   * Teleport / Respon: the premium teleport and return lists (share/premiere/teleport.csv, respon.csv) shown in the
//     map window's list_teleportlist / list_responlist (game2/ui_new_mapwnd.txt, owned by hud-options) while active;
//     warpTo() is the premium warp with game2/ui_warpteleportwnd.txt, setReturnPoint() picks the premium revive town
//   * Post / Brokerage / StoreIndex / storage: the "Holy Water of Almighty" menu (game2/growbless/growbless.txt:
//     Shop, Agency, Mail, Stash, Close), shown when such a premium starts and by game.premium.openAlmighty()
//   * the Almighty premium item (cashshop_almightypremium.csv) = premiereitem row 0 for its 30 service days; it is a
//     box for the items system, so game.boxes.open is wrapped (index.js) to refuse it outside the renewal window
//   * ItemUpgradeRate %: game.premium.upgradeRateBonus() for the enhancement system
// ExpAdd is the service group (1 Growth Blessing, 2 Almighty): the two kinds cannot run together (stringtable_system
// 109); items of the running group add their time. ONLINE the server owns all of it: item use, the warp cast, the return
// point and the revive target (server/world/premium*.mjs); this module only mirrors game.save.premium / premiumRespawn
// (synced from the profile) and sends intents.
import { fetchJSON } from '../../engine/assets.js';
import { rewardBonusPercent } from '../../game/reward-bonus.js';
import { T, loadDshop, itemInfo, str, strAsync, say, notice } from './common.js';
import { PREMIUM_TEXT, almightyOf, premiumFields, premiumBlock, premiumActivation, activePremiums, premiumAny, premiumSum, premiumTeleportList, premiumResponList, isPremiumItem, partyWarpText } from './premium-rules.js';

const nl = s => String(s ?? '').replace(/\\/g, '\n');

// ---- the online Select Warp / Party Warp bar: the server's 10 s frozen cast (premium-rules.js PREMIUM_WARP_MS) shown on the
// original warp window game2/ui_warpteleportwnd.txt. Same shape as the channel bar (hud-options/sysmenu.js pickChannel).
// The client only shows the bar: the host decides when the cast is over (warpfinish) and what interrupts it (move, damage, mount).
// ENGINE-CHOSEN (no data holds them): the 250 ms timer that keeps the cast moving while the tab is hidden (a hidden tab pauses
// requestAnimationFrame), and the 400 ms a "the cast is gone" reading must persist before the bar is dropped (a snapshot that was
// already in flight when the cast began has no smartWarp and must not close the bar while the host still freezes the character).
const WARP_LOST_CAST_MS = 400, WARP_TIMER_MS = 250;
const warping = new WeakSet();   // games with a warp bar running: one cast at a time
/**
 * Warp to `t` (a premium teleport row, or { member } for Party Warp) with the server's cast. env = { say, now, setTimeout,
 * clearTimeout, requestAnimationFrame } (tests inject a fake clock). Resolves true when the host moved the player.
 */
export async function runWarpOnline(game, t, env = {}) {
  const net = game.network;
  if (warping.has(game)) return false;
  warping.add(game);
  const tell = env.say || say;
  const now = env.now || (() => performance.now());
  const later = env.setTimeout || ((fn, ms) => globalThis.setTimeout(fn, ms));
  const unlater = env.clearTimeout || (id => globalThis.clearTimeout(id));
  const frame = env.requestAnimationFrame || (globalThis.requestAnimationFrame ? fn => globalThis.requestAnimationFrame(fn) : null);
  let cast = null, win = null, cancel = false, interrupted = false, closing = false, wake = null;
  const alive = () => net.active && net.ready && net.self?.smartWarp?.nonce === cast.nonce;
  try {
    game.controller?.stop?.();
    const begin = await net.action('premium', t.member ? { operation: 'warpbegin', member: t.member } : { operation: 'warpbegin', location: Number(t.location) });
    cast = begin?.self?.smartWarp;
    if (!cast || cast.kind !== 'premium') return false;
    const ms = Math.max(1000, cast.readyAt - (begin.serverTime || Date.now()));
    // title: 2000|38 "Select Warp" is the original text of the map window's list this warp comes from (the window's own default,
    // 100|138 "Store Game Information", is not about warping). Party Warp has no string of its own: it reuses it (ENGINE-CHOSEN).
    const title = await strAsync(game, 2000, 38, '');
    win = await game.uiwin.create('game2/ui_warpteleportwnd.txt', { modal: true, remember: false, disposeOnClose: true });
    if (title) win.control('lbl_title')?.setText?.(title);
    win.control('lbl_text')?.setText?.(`${t.name ?? ''}`);
    const bar = win.control('processbar');
    // Cancel, Esc and every other way the window is closed (map change, death: uiwin.closeAll) cancel the cast
    win.control('btn_cancel')?.onClick?.(() => { cancel = true; win.close('cancel'); });
    win.on?.('close', () => { if (!closing) { cancel = true; wake?.(); } });
    game.uiwin.openWindow(win);
    const T0 = now();
    await new Promise(resolve => {
      let live = true, timer = null, rafPending = false, lostAt = null;
      const end = () => { if (!live) return; live = false; unlater(timer); resolve(); };
      wake = end;
      const step = () => {
        if (!live) return;
        if (cancel) return end();
        // moving, taking damage, mounting or a lost lease drop the server's cast: stop the bar
        if (!alive()) { lostAt ??= now(); if (now() - lostAt >= WARP_LOST_CAST_MS) { interrupted = true; return end(); } } else lostAt = null;
        const f = Math.min(1, (now() - T0) / ms);
        bar?.setGauge?.(f);
        if (f >= 1 && lostAt == null) return end();
        unlater(timer); timer = later(step, WARP_TIMER_MS);
        if (frame && !rafPending) { rafPending = true; frame(() => { rafPending = false; step(); }); }
      };
      step();
    });
    closing = true;
    if (cancel || interrupted) {
      if (interrupted) win.close('interrupted');
      // cancelled by the player: release the host's cast (it also freezes movement); interrupted: the host already dropped it
      const snap = net.self?.smartWarp;
      if (cancel && net.active && net.ready && (!snap || snap.nonce === cast.nonce)) await net.action('premium', { operation: 'warpcancel', nonce: cast.nonce });
      return false;
    }
    // the bar ran for readyAt - serverTime after the begin answer, so the host's own preparation time is over
    const done = await net.action('premium', { operation: 'warpfinish', nonce: cast.nonce });
    win.close(done ? 'done' : 'failed');
    if (done?.premiumResult?.partyWarp?.text) tell(game, done.premiumResult.partyWarp.text, 'sys');   // 101:161
    return !!done;
  } catch (error) {
    // the bar could not be built: never leave the host's cast freezing the character
    console.error('[premium] warp cast', error);
    if (cast && net.active && net.ready) await net.action('premium', { operation: 'warpcancel', nonce: cast.nonce }).catch(() => null);
    try { if (win?.isOpen) { closing = true; win.close('failed'); } } catch { /* already gone */ }
    return false;
  } finally { warping.delete(game); }
}

export function createPremium(game, api) {
  let statuses = null;
  const loadStatuses = () => (statuses ||= fetchJSON('/gamedata/skills_status.json').then(j => j.statuses || j).catch(() => ({}))); // lazily
  const state = () => ((game.save.premium ||= {}));   // group -> {item, start, until, fields}
  const online = () => !!game.network?.active;        // the server owns the service
  const dshop = () => T.dshop;
  const fieldsOf = (idx) => premiumFields(dshop(), idx);
  const active = () => activePremiums(state(), Date.now());
  const any = (k) => premiumAny(state(), Date.now(), k);
  const sum = (k) => premiumSum(state(), Date.now(), k);

  /** Is this item a premium-service item? */
  function isPremium(idx) { return isPremiumItem(dshop(), idx); }
  const isAlmightyItem = (idx) => !!almightyOf(dshop(), idx);

  /** Can this premium item be used now? (the other kind must not run; the Almighty renews only in its last days) */
  function canActivate(idx) { return !premiumBlock(dshop(), state(), Number(idx), Date.now()); }

  /** Start / extend the premium of an item. Returns true when it was applied (the caller consumes the item). */
  async function activate(idx, { external = false } = {}) {
    await loadDshop();
    idx = Number(idx);
    const f = fieldsOf(idx);
    if (!f) return false;
    // external = the item was already consumed by the items / boxes system (online: by the server, which also owns the state)
    const now = Date.now(), block = premiumBlock(dshop(), state(), idx, now);
    if (block === 'together') { if (!external) notice(game, PREMIUM_TEXT.together); return false; }
    if (block === 'renew') { notice(game, `${itemInfo(game, idx).name}: it can be renewed during its last ${almightyOf(dshop(), idx).updatableDays} days.`); return false; }
    if (online()) {
      // never consume / mutate locally: the item use already ran on the server; its profile carries the service
      if (!external) return false;
      game.events?.emit?.('premium', { item: idx, external, server: true });
      if (f.storeIndex > 0 || f.post > 0 || f.brokerage > 0) setTimeout(() => openAlmighty(), 0);
      return true;
    }
    const { group, entry } = premiumActivation(dshop(), state(), idx, now);
    const previous=state()[group];if(entry.accountWide&&previous&&!previous.accountWide&&previous.until>now)state()[`regular:${group}`]=previous;
    state()[group] = entry;
    await applyStatus();
    say(game, `${itemInfo(game, idx).name}: ${Math.round((entry.until - now) / 86400000 * 10) / 10} day(s).`, 'item');
    game.events?.emit?.('premium', { item: idx, until: entry.until, fields: f, external });
    // the Holy Water of Almighty menu (growbless.txt) comes up with the remote services it unlocked
    if (f.storeIndex > 0 || f.post > 0 || f.brokerage > 0) setTimeout(() => openAlmighty(), 0);
    return true;
  }

  /** Keep the StatusIndex buffs of the active premiums in save.buffs (remaining = real time left). */
  async function applyStatus() {
    if (online()) return;   // the server keeps profile.buffs (premium:<item>, real-time expiry)
    const buffs = (game.save.buffs ||= []);
    const want = new Map();
    const distinct=new Map();for(const p of active())if(p.fields.statusIndex>0){const old=distinct.get(p.fields.statusIndex);if(!old||p.until>old.until)distinct.set(p.fields.statusIndex,p);}
    for (const p of distinct.values()) want.set(`premium:${p.item}`, p);
    let changed = false;
    for (let i = buffs.length - 1; i >= 0; i--) {
      const b = buffs[i];
      const k = String(b.key || '');
      if (k.startsWith('premium:') && !want.has(k)) { buffs.splice(i, 1); changed = true; }
      // the items system's copy of the same status (key premiere:<item>, set when it consumed the item): the premium
      // service keeps one buff for the whole (real-time, extendable) service instead
      else if (k.startsWith('premiere:') && want.has(`premium:${k.slice(9)}`)) { buffs.splice(i, 1); changed = true; }
    }
    if (want.size) {
      const S = await loadStatuses();
      for (const [key, p] of want) {
        const def = S?.[p.fields.statusIndex] || (Array.isArray(S) ? S.find(s => s?.index === p.fields.statusIndex) : null);
        const left = (p.until - Date.now()) / 1000;
        let b = buffs.find(x => x.key === key);
        if (!b) {
          b = { key, skillIndex: null, statusIndex: p.fields.statusIndex, premium: p.item, name: itemInfo(game, p.item).name,
            description: def?.description || '', iconIndex: def?.iconIndex ?? null,
            options: (def?.options || []).map(o => ({ code: o.code, value: o.value })), duration: (p.until - p.start) / 1000, remaining: left, tick: 0 };
          buffs.push(b);
          changed = true;
        }
        b.remaining = left;
      }
    }
    if (changed) { game.player && (game.player.statuses = buffs); game.refreshPlayerStats?.(false); }
  }

  let acc = 0;
  function update(dt) {
    acc += dt;
    if (acc < 1) return;
    acc = 0;
    if (online()) return;   // expiry is the server's clock
    let expired = false;
    for (const [g, p] of Object.entries(state())) if (p && p.until <= Date.now()) { delete state()[g]; expired = true; say(game, `${itemInfo(game, p.item).name}: the service has ended.`, 'sys'); }
    if (expired || active().some(p => p.fields.statusIndex > 0)) applyStatus();
  }

  // ---------------------------------------------------------------------------------------------- EXP hook
  // hunting EXP only (monster kills pass their level; quest rewards do not). Online the server adds it to the reward.
  // solo hunting EXP: premium Rate + EXP scrolls / items (RESULT_EXP_MUL, src/game/reward-bonus.js), added together like the server does
  (game.expModifiers ||= []).push(({ monsterLevel } = {}) => (online() || monsterLevel == null ? 1
    : 1 + (sum('rate') + rewardBonusPercent('exp', { buffs: game.save?.buffs, itemOptions: game.player?.stats?.itemOptions })) / 100));

  // ---------------------------------------------------------------------------------------------- lists
  const lvl = () => Number(game.save?.level) || 1;
  const teleportList = () => premiumTeleportList(dshop(), lvl());
  const responList = () => premiumResponList(dshop(), lvl());
  const returnPointId = () => { const r = game.save?.premiumRespawn; return r == null ? null : Number(typeof r === 'object' ? r.location : r); };

  /** Warp with the original teleport window (ui_warpteleportwnd.txt: progress bar + Cancel). Online the cast is the
   *  server's (begin -> wait -> finish; moving, damage or Cancel ends it) and the server commits the arrival. */
  async function warpTo(t) {
    if (!t) return false;
    if (online()) return warpOnline(t);
    const win = await game.uiwin.create('game2/ui_warpteleportwnd.txt', { modal: true, remember: false, disposeOnClose: true });
    win.control('lbl_text').setText(`${t.name}`);
    const bar = win.control('processbar');
    let cancel = false;
    win.control('btn_cancel').onClick(() => { cancel = true; win.close('cancel'); });
    game.uiwin.openWindow(win);
    const T0 = performance.now(), DUR = 2000;
    await new Promise((res) => {
      const step = () => {
        if (cancel) return res();
        const f = Math.min(1, (performance.now() - T0) / DUR);
        bar.setGauge(f);
        if (f >= 1) return res();
        requestAnimationFrame(step);
      };
      step();
    });
    if (cancel) return false;
    win.close('done');
    const [x, y, dir] = t.pos || [];
    await game.travel(t.map, { x: Number(x) + 0.5, z: Number(y) + 0.5, dirDeg: (Number(dir) || 0) * 360 / 256 });
    return true;
  }
  async function warpOnline(t) { return runWarpOnline(game, t, { say }); }

  /** Choose the premium return point (the town where the dead revive while the Respon service runs). */
  async function setReturnPoint(t) {
    if (!t) return false;
    if (online()) {
      const done = await game.network.action('premium', { operation: 'returnpoint', location: Number(t.location) });
      if (done) say(game, `${t.name}`, 'sys');
      return !!done;
    }
    if (!any('respon')) { notice(game, PREMIUM_TEXT.noService); return false; }
    game.save.premiumRespawn = Number(t.location);
    say(game, `${t.name}`, 'sys');
    return true;
  }

  // the premium return point: revive at the chosen Respon town while the service is active (field maps only; an
  // instance map's maprespawn.csv row still decides where its dead go). Online the server picks the revive target.
  const baseRespawn = game.respawnTarget?.bind(game);
  if (baseRespawn) {
    game.respawnTarget = (...a) => {
      const id = returnPointId(), row = id == null ? null : responList().find(r => r.location === id);
      const mapIndex = a[0] ?? game.world?.info?.index;
      const instance = (game.world?._tables?.maprespawn || []).some(r => Number(r.MapIndex) === Number(mapIndex));
      if (row && any('respon') && !instance) {
        const [x, y, dir] = row.pos || [];
        return { mapIndex: row.map, x: Number(x) + 0.5, z: Number(y) + 0.5, dirDeg: (Number(dir) || 0) * 360 / 256 };
      }
      return baseRespawn(...a);
    };
  }

  // ---------------------------------------------------------------------------------------------- map window
  // The big map (game2/ui_new_mapwnd.txt) belongs to hud-options: its "Premium Service" button (btn_bless, 2000/63;
  // tooltip 25/50 "enabled through Growth Blessing and Holy Water of Almighty") flips the right-hand lists to
  // Select Warp / Return Point. hud-options fills those two lists from teleportList() / responList() (only while the
  // matching service runs) and calls warpTo() / setReturnPoint() on a double click; nothing else of that window is touched.
  game.events?.on?.('premium', () => { for (const w of game.uiwin?.openWindows?.() || []) if (w.data?.fillPremium) w.data.fillPremium(); });

  // ---------------------------------------------------------------------------------------------- growbless menu
  const isAlmighty = () => any('storeIndex') || any('post') || any('brokerage');
  game.uiwin.registerWindow('shops.growbless', {
    script: 'game2/growbless/growbless.txt',
    create(win) {
      win.control('btn_shop').onClick(() => { const s = active().find(p => p.fields.storeIndex > 0); if (s) { win.close(); api.store.open(s.fields.storeIndex, null, true); } });
      win.control('btn_store').onClick(() => { win.close(); api.search.open(null, { remote: true }); });
      win.control('btn_mail').onClick(() => { win.close(); openOther(['mail', 'mailbox', 'post'], str(game, 171, 50, 'Mail')); });
      win.control('btn_storage').onClick(() => { win.close(); openOther(['storage', 'stash', 'warehouse'], str(game, 171, 54, 'Stash')); });
    },
    onOpen(win) {
      win.control('btn_shop').setEnabled(any('storeIndex'));
      win.control('btn_store').setEnabled(any('brokerage'));
      win.control('btn_mail').setEnabled(any('post'));
      win.control('btn_storage').setEnabled(isAlmighty());
    },
  });
  function openOther(names, label) {
    for (const n of names) if (game.uiwin.has(n)) { game.uiwin.open(n, { remote: true }); return true; }
    if (game.windows?.open && ['storage'].includes(names[0])) { try { game.windows.open(names[0]); return true; } catch { /* no legacy window */ } }
    notice(game, `${label}: ${nl(str(game, 171, 42, 'Cannot use this service now.'))}`);
    return false;
  }
  function openAlmighty() {
    if (!isAlmighty()) { notice(game, str(game, 171, 47, 'Holy Water of Almighty')); return false; }
    game.uiwin.open('shops.growbless');
    return true;
  }

  // resume the buffs of a saved premium
  loadDshop().then(() => applyStatus());

  return {
    isPremium, isAlmightyItem, canActivate, activate, update, active, any, sum,
    get expBonus() { return sum('rate'); },
    upgradeRateBonus: () => sum('itemUpgradeRate'),
    partyBonus: () => sum('partyBonusRate'),
    teleportList, responList, warpTo, setReturnPoint, returnPointId, openAlmighty,
    /** Party Warp (PartyWarp service; party window btn_move_<n>): the server-owned premium cast to a party member's position. */
    warpToMember(member) {
      if (!member?.id) return false;
      if (!online()) { notice(game, partyWarpText('notInParty')); return false; }   // parties exist on a shared server only
      if (!any('partyWarp')) { notice(game, PREMIUM_TEXT.noService); return false; }
      return warpTo({ member: String(member.id), name: member.name || '' });
    },
    remoteStore() { const s = active().find(p => p.fields.storeIndex > 0); if (!s) return false; api.store.open(s.fields.storeIndex, null, true); return true; },
  };
}
