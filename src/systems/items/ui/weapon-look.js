// Ian's weapon appearance window (npc job 110 CHANGESHAPE_JOB): game2/changeshapewnd/changeshapewnd.txt "Change Weapon
// appearance" (101:199). item_left = the target weapon (101:200 "Target"), item_right = the appearance material (101:201
// "Changed appearance"), btn_change, lbl_cost = the DIL cost of the material's kind (101:202 '%d'), btn_close / btn_exit.
// Rules: ../weapon-appearance.js; host transaction: server/world/ian-appearance.mjs (intent 'weaponlook'); open choices:
// src/config/engine-chosen-ian.js. Online the host consumes, pays and saves; the window only sends the reviewed selection.
// A local save (offline play) applies the same rules to its own items. update() announces a run-out appearance of the
// character's own items once (101:204) and rebuilds the look when a worn weapon was affected.
import { Crafting, sysSound, clean } from './craft.js';
import { fmt } from './common.js';
import { fetchCSV } from '../../../engine/assets.js';
import { strings } from '../../../ui/uiwin/strings.js';
import { appearanceMaterial, materialFits, materialSeconds, appearanceCost, appearanceRunning, appearanceExpired, systemVariables, WEAPON_LOOK_TEXT } from '../weapon-appearance.js';

export const WEAPON_LOOK_JOB = 110, WEAPON_LOOK_ROLE = 'CHANGESHAPE_JOB', WEAPON_LOOK_WINDOW = 'weaponlook';
const SCRIPT = 'game2/changeshapewnd/changeshapewnd.txt';

/** A native line of the service ([TARGET_ITEM] etc. filled), markup kept for the window's rich labels. */
export function weaponLookString(key, vars = {}) {
  const [group, cate, code, fallback] = WEAPON_LOOK_TEXT[key];
  let t = String(strings.get({ group, cate, code }) ?? fallback);
  for (const [k, v] of Object.entries(vars)) t = t.split(`[${k}]`).join(String(v));
  return t;
}
const plain = (key, vars) => clean(weaponLookString(key, vars)).replace(/<[^>]+>/g, '').replace(/\\\\?/g, ' ').trim();
const requestId = () => {
  const b = new Uint8Array(16);
  if (globalThis.crypto?.getRandomValues) globalThis.crypto.getRandomValues(b); else for (let i = 0; i < b.length; i++) b[i] = Math.floor(Math.random() * 256);
  return 'wl' + [...b].map(x => x.toString(16).padStart(2, '0')).join('');
};

/** Install once per game: the NPC service, the window (registered on first use) and the run-out watcher. */
export function installWeaponLook(game) {
  if (game.weaponLook) return game.weaponLook;
  let VARS = null, K = null, W = null, bound = false, next = 0;
  const announced = new Set(), S = {};
  const now = () => (typeof game.now === 'function' ? game.now() : Date.now());
  const vars = () => (VARS ||= fetchCSV('share/system_variable.csv').then(rows => systemVariables(rows.slice(1))).catch(() => { VARS = null; return new Map(); }));
  strings.need(Object.values(WEAPON_LOOK_TEXT).map(([group, cate, code]) => ({ group, cate, code }))).catch(() => {});
  const items = () => game.items || null;
  const say = (text, kind = 'sys') => { try { game.hud?.log?.(text, kind); } catch { /* chat unavailable */ } };
  /** A refusal: NORMAL lines through the items system's own message path, SYSTEM lines as text. */
  const refuse = (key) => { const [group, cate, code] = WEAPON_LOOK_TEXT[key], sys = items(); if (group === 'NORMAL') sys?.msg?.(cate, code); else if (sys?.msg) sys.msg(null, null, plain(key)); else say(plain(key), 'err'); return false; };
  const slotRefusal = (key) => { const [group, cate, code] = WEAPON_LOOK_TEXT[key]; return group === 'NORMAL' ? [cate, code] : plain(key); };
  const defOf = inst => items()?.db?.def(inst?.itemIndex) || null;

  function refresh() {
    if (!W || !K) return;
    const w = S.weapon.inst, m = S.material.inst, md = defOf(m), label = W.control('lbl_cost');
    if (md) void vars().then(v => { if (S.material.inst === m) { const c = appearanceCost(md, v); label.setText(c == null ? '' : weaponLookString('cost').replace('%d', fmt(c))); } });
    else label.setText('0');
    W.control('btn_change').setEnabled(!!(w && md && materialFits(md, defOf(w)) && !K.busy));
  }
  /** The reviewed online send without a confirmation box: the same session / selection custody as Crafting.review. */
  async function direct(send) {
    if (K.busy || !K.validate()) return null;
    const network = game.network, lease = network?.token, character = game.save?.id;
    const current = () => game.save?.authority === 'server' && game.save?.id === character && game.network === network && network?.token === lease &&
      !network?.disposed && network?.ready !== false && network?.active !== false && typeof network?.action === 'function';
    K.busy = true;
    try { if (!current()) { refuse('missing'); return null; } return await send(network); } finally { K.busy = false; }
  }
  function done() {
    sysSound(items(), 101);
    say(plain('success'));
  }
  async function change() {
    const sys = items(); if (!sys || !K || K.busy) return;
    const w = S.weapon.inst, m = S.material.inst, wd = defOf(w), md = defOf(m);
    if (!w || !m) return refuse('missing');
    if (Number(wd?.type) !== 4 || !appearanceMaterial(md)) return refuse('unusable');
    if (!materialFits(md, wd)) return refuse('mismatch');
    const cost = appearanceCost(md, await vars()), seconds = materialSeconds(md);
    if (cost == null || !seconds) return refuse('unusable');
    if ((Number(sys.dil) || 0) < cost) return refuse('dil');
    // the running appearance is deleted by the change (101:207 "Deleted appearance cannot be retrieved.")
    const caution = Number(w.appearance) > 0 && appearanceRunning(w, now()) ? weaponLookString('remove', { TARGET_ITEM: sys.db.name(w.itemIndex) }).replace(/\\\\?/g, '\n') : null;
    if (game.save?.authority === 'server') {
      const send = async (network) => {
        const result = await network.action(WEAPON_LOOK_WINDOW, { operation: 'change', weapon: w.uid, material: m.uid, revision: Number(game.save?.weaponLook?.revision) || 0, requestId: requestId() });
        if (!result?.weaponLookResult) return null;
        done();
        return result;
      };
      if (caution) await K.review(caution, weaponLookString('caution'), send); else await direct(send);
      K.validate(); refresh(); return;
    }
    if (caution && !(await K.confirm(caution, weaponLookString('caution')))) return;
    if (!K.validate() || S.weapon.inst !== w || S.material.inst !== m) return refuse('missing');
    if (!sys.spendDil(cost)) return refuse('dil');
    K.consume(m, 1); S.material.clear(false);
    w.appearance = md.index; w.appearanceExpiresAt = now() + seconds * 1000;
    done();
    sys.changed('upgrade', { item: w });
    refresh();
  }
  function ensureWindow() {
    const sys = items(), mgr = game.uiwin;
    if (!sys?.bag || !sys.db || !mgr?.registerWindow) return false;
    if (mgr.has?.(WEAPON_LOOK_WINDOW)) return true;
    mgr.registerWindow(WEAPON_LOOK_WINDOW, {
      script: SCRIPT,
      create(win) {
        W = win; K = new Crafting(sys, win, WEAPON_LOOK_WINDOW);
        S.weapon = K.slot('item_left', { count: false, accept: (inst, def) => (Number(def?.type) === 4 && (inst.count || 1) === 1 ? true : slotRefusal('unusable')), onChange: () => {
          const m = S.material.inst;
          if (m && S.weapon.inst && !materialFits(defOf(m), defOf(S.weapon.inst))) { S.material.clear(false); refuse('mismatch'); }
          refresh();
        } });
        S.material = K.slot('item_right', { count: false, accept: (inst, def) => (!appearanceMaterial(def) ? slotRefusal('unusable') : S.weapon.inst && !materialFits(def, defOf(S.weapon.inst)) ? slotRefusal('mismatch') : true), onChange: refresh });
        win.control('btn_change').onClick(() => change());
        win.control('btn_close').onClick(() => win.close());
        win.control('btn_exit').onClick(() => win.close());
        game.events?.on?.('inventory', () => { if (win.isOpen && !K.busy) { K.validate(); refresh(); } });
      },
      onOpen(win, arg) {
        K.opened(win, arg, inst => (Number(defOf(inst)?.type) === 4 ? S.weapon.put(inst) : S.material.put(inst)) || true);
        void vars(); refresh();
      },
      onClose() { K.closed(); },
      update(win) { K.tick(win); },
    });
    return true;
  }
  const open = (npc, info) => { if (!ensureWindow()) return false; game.uiwin.open(WEAPON_LOOK_WINDOW, { npc, ...(info || {}) }); return true; };
  const bind = () => {
    const svc = game.npcServices;
    if (bound || !svc?.register) return bound;
    bound = true; svc.register(WEAPON_LOOK_JOB, open); svc.register(WEAPON_LOOK_ROLE, open);
    return true;
  };
  if (!bind()) {
    game.events?.on?.('systems', bind);
    const t = setInterval(() => { if (bind() || !game.uiwin) clearInterval(t); }, 1000);
    t.unref?.();
  }
  /** Run-out appearances of the character's own items: 101:204 once each, the look rebuilt when a worn weapon lost it. A local
   *  save clears the fields itself; online the host clears them (server/world/ian-appearance.mjs tickWeaponLooks). */
  function update() {
    const t = now(), save = game.save;
    if (t < next || !save) return; next = t + 1000;
    let fresh = false, worn = false;
    const worns = Object.values(save.equip?.items || {});
    for (const list of [save.inventory, worns, save.storage, save.accountFeatures?.shared]) {
      if (!Array.isArray(list)) continue;
      for (const item of list) {
        if (!appearanceExpired(item, t)) continue;
        const key = `${item.uid}:${item.appearanceExpiresAt}`;
        if (!announced.has(key)) { announced.add(key); fresh = true; if (list === worns) worn = true; }
        if (save.authority !== 'server') { delete item.appearance; delete item.appearanceExpiresAt; }
      }
    }
    if (fresh) say(plain('expired'));
    if (worn) items()?.changed?.('expire:weaponlook');
  }
  return (game.weaponLook = { open, update, ensureWindow, change, state: S, get window() { return W; } });
}
