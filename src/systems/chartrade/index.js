// Character trade: the original "Character Move" windows of game2/chartradewnd. The giving player
// opens it from the player menu row 11 (Global label 240:11) (or /chartrade Name); the receiver answers
// msgbox/ui_chartradeinvite; both then see ui_chartradewnd (character list + 556:16-29 stats, Details ->
// ui_chartradeinfownd presets/counts, payment grid + DIL, Confirm / Approve / Cancel). The host
// (server/world/char-trade.mjs) owns every rule; this module only displays network.charTrade.
// Pure helpers: rules.js. ENGINE-CHOSEN values: src/config/engine-chosen-char-trade.js.
import { installPcPop } from '../pvp/duel.js';
import { partyPvpRunning } from '../pvp/pk-channel.js';
import { needStrings } from '../hud-options/util.js';
import { strings } from '../../ui/uiwin/strings.js';
import { Container } from '../items/model.js';
import { gridItems, slotIcon } from '../items/ui/common.js';
import { buildTooltip } from '../items/tooltip.js';
import { askAmount } from '../items/ui/dialogs.js';
import { placeWithBag } from '../items/ui/craft.js';
import { S } from '../items/equip.js';
import { CHAR_TRADE_SCRIPTS as SCRIPTS, STRING_CATE, BUSY_PARTY_PVP, STRING_CODES, MENU, INVITE_TITLE, COMMAND, SLOT_IDS, CHAR_TRADE_ENGINE_CHOSEN as C,
  errorMsg, menuVisible, charTradeView, lockProgress, characterCaption, charInfoColumns, presetItem, eventMsg } from './rules.js';

let API = null;

export async function install(game) {
  if (!game.uiwin) return null;
  const st = { net: null, s: null, busy: false, main: null, info: null, wait: null, promptId: null, opening: false, waitOpening: false,
    infoChar: null, preset: 0, weapon2: false, costume: false, disposed: false };
  const sys = () => game.items;
  const net = () => game.network;
  const txt = (code, cate = STRING_CATE) => strings.get({ group: 'NORMAL', cate, code }) ?? '';
  void needStrings([...STRING_CODES.map(c => ['NORMAL', STRING_CATE, c]), ['NORMAL', 100, 37], ['NORMAL', 100, 38], ['NORMAL', 100, 84],
    ['NORMAL', 100, 85], ['NORMAL', MENU.cate, MENU.label], ['NORMAL', STRING_CATE, BUSY_PARTY_PVP]]).catch(() => {});
  const say = (code, kind = 'sys') => { const t = txt(code); if (t) game.chat?.system?.(t.replace(/\s*\n\s*/g, ' '), kind); return t; };
  const serverNow = () => { const n = net(), c = n?._serverClock; return c ? c.time + performance.now() - c.at : Date.now(); };

  const send = async (operation, extra = {}) => {
    const n = net(), s = st.s;
    if (!n || st.busy || (!s && operation !== 'request')) return null;
    st.busy = true;
    try {
      const body = { operation, ...(operation === 'request' ? {} : { id: s.id, ...(['cancel', 'decline'].includes(operation) ? {} : { revision: s.revision }) }), ...extra };
      const r = await n.action('chartrade', body);
      if (!r) {
        const message = n._lastCommandError?.message || '', code = errorMsg(message);
        if (code == null || !say(code, 'err')) { if (message) game.chat?.system?.(message, 'err'); }
        console.warn('[chartrade]', operation, message);
      }
      return r;
    } finally { st.busy = false; render(); }
  };
  const request = (actor) => send('request', { targetId: actor?.networkId || actor?.id });
  const payer = () => st.s?.role === 'buyer' && st.s.phase === 'open';
  const rows = () => st.s?.payment?.items?.map(i => ({ uid: i.uid, count: i.count || 1 })) || [];
  const offer = (items, dil = st.s?.payment?.dil || 0) => send('offer', { items, dil });
  const add = async (item, count = item?.count || 1) => {
    if (!payer() || !item) return false;
    const next = rows(), e = next.find(i => i.uid === item.uid);
    if (e) e.count = count; else next.push({ uid: item.uid, count });
    return offer(next);
  };
  const remove = item => payer() ? offer(rows().filter(i => i.uid !== item.uid)) : null;

  function render() {
    const w = st.main, s = st.s, items = sys();
    if (!w?.isOpen || !s) return;
    const v = charTradeView(s, serverNow());
    // setEnabled clears a press in progress: only touch a control whose state really changes
    const en = (c, on) => { if (c.enabled !== !!on) c.setEnabled?.(!!on); };
    w.control('lbl_targetname').setText(v.receiver);
    w.control('lbl_targettrade').setText(txt(1));
    const combo = w.control('com_characterlist'), sig = v.list.map(c => `${c.id}:${c.restricted}`).join('|');
    if (combo.data.sig !== sig) { combo.data.sig = sig; combo.setItems(v.list.map(c => ({ text: characterCaption(c), value: c.id }))); }
    if (v.selected) combo.selectValue(v.selected); else combo.select(-1);
    en(combo, v.seller && v.open && !st.busy);
    w.control('lbl_charInfo').setText(charInfoColumns(s.character, txt));
    w.control('pan_infoshield').setVisible(v.infoShield);
    w.control('pan_slotshield').setVisible(v.slotShield);
    if (items) {
      const grid = w.control('slottradeitem'), bag = new Container(structuredClone(v.items), items.db, { pages: 1, ...C.paymentGrid });
      grid.setItems?.(gridItems(items, grid, bag, 0).items);
    }
    w.control('lbl_trademoney').setDil?.(v.dil);
    w.control('btn_accept1').setChecked?.(v.accept1);
    w.control('btn_accept2').setChecked?.(v.accept2);
    en(w.control('btn_ok'), !st.busy && v.canConfirm);
    en(w.control('btn_agree'), !st.busy && v.canApprove);
    en(w.control('btn_viewdetail'), !!(s.character || v.list.length));
    w.control('pan_progressBg').setVisible(v.progress);
    w.control('processbar').setGauge?.(lockProgress(s, serverNow()));
    w.data.view = v;
    renderInfo();
  }

  // ------------------------------------------------------------------ Details: ui_chartradeinfownd
  function renderInfo() {
    const w = st.info, c = st.infoChar, items = sys();
    if (!w?.isOpen || !c || !items) return;
    const equip = c.detail?.equip || null;
    for (let pi = 0; pi < 5; pi++) {
      w.control(`btn_preset_${pi + 1}`).setChecked?.(pi === st.preset);
      const pan = w.control(`pan_Preset_${pi + 1}`);
      pan.setVisible(pi === st.preset);
      if (pi !== st.preset) continue;
      for (const id of SLOT_IDS) {
        const ctrl = pan.control(`suititem_${id}`);
        if (ctrl.missing) continue;
        const slot = st.weapon2 && (id === S.weapon || id === S.offhand) ? id + 100 : id;
        ctrl.data.slot = slot; ctrl.data.inst = presetItem(equip, pi, slot);
        slotIcon(items, ctrl, ctrl.data.inst);
        if (id === S.armor) ctrl.setVisible(!st.costume);
        if (id === S.costume) ctrl.setVisible(st.costume);
      }
    }
    w.control('btn_weapontab_0').setChecked?.(!st.weapon2);
    w.control('btn_weapontab_1').setChecked?.(st.weapon2);
    w.control('btn_ArmorTab').setChecked?.(!st.costume);
    w.control('btn_CostumeTab').setChecked?.(st.costume);
    w.control('pan_CostumeBG').setVisible(st.costume);
    const d = c.detail || {};
    w.control('lbl_invencount').setText(String(d.inventoryCount ?? 0));
    w.control('lbl_invenmoney').setDil?.(Number(d.dil) || 0);
    w.control('lbl_storagecount').setText(String(d.storageCount ?? 0));
    w.control('lbl_storagemoney').setDil?.(Number(d.storageDil) || 0);
  }
  const openInfo = async () => {
    const s = st.s, combo = st.main?.control('com_characterlist');
    const c = s?.character || (s?.characters || []).find(x => x.id === combo?.getValue?.()) || s?.characters?.[0] || null;
    if (!c) return false;
    st.infoChar = c; st.preset = Math.max(0, Math.min(4, Number(c.detail?.equip?.active) || 0)); st.weapon2 = false; st.costume = false;
    try { await game.uiwin.open('chartradeinfo'); } catch (error) { console.warn('[chartrade] details window', error); return false; }
    return game.uiwin.isOpen?.('chartradeinfo') ?? true;
  };
  game.uiwin.registerWindow?.('chartradeinfo', {
    script: SCRIPTS.info,
    create(w) {
      st.info = w;
      for (let pi = 0; pi < 5; pi++) {
        w.control(`btn_preset_${pi + 1}`).onClick(() => { st.preset = pi; renderInfo(); });
        const pan = w.control(`pan_Preset_${pi + 1}`);
        for (const id of SLOT_IDS) {
          const ctrl = pan.control(`suititem_${id}`);
          if (ctrl.missing) continue;
          ctrl.setTooltip?.(() => { const inst = ctrl.data.inst, items = sys(); return inst && items ? buildTooltip(items, inst, { where: 'equip' }) : null; });
        }
      }
      w.control('btn_weapontab_0').onClick(() => { st.weapon2 = false; renderInfo(); });
      w.control('btn_weapontab_1').onClick(() => { st.weapon2 = true; renderInfo(); });
      w.control('btn_ArmorTab').onClick(() => { st.costume = false; renderInfo(); });
      w.control('btn_CostumeTab').onClick(() => { st.costume = true; renderInfo(); });
      w.control('btn_exit').onClick(() => w.close('exit'));
    },
    onOpen(w) {
      renderInfo();
      const m = st.main;
      if (m?.isOpen) w.setPosition?.(Math.max(0, m.box.x - w.box.w - 4), m.box.y);
    },
  });

  // ------------------------------------------------------------------ requester: ui_invitechartrade ("Requesting...")
  game.uiwin.registerWindow?.('chartradewait', {
    script: SCRIPTS.wait,
    create(w) { st.wait = w; w.control('btn_cancel').onClick(() => { void send('cancel'); }); },
    onOpen(w) { w.data.total = Math.max(1, (st.s?.expiresAt || 0) - serverNow()); w.control('processbar').setGauge?.(0); },
    update(w) { const s = st.s; if (s?.expiresAt) w.control('processbar').setGauge?.(Math.max(0, Math.min(1, 1 - (s.expiresAt - serverNow()) / (w.data.total || 1)))); },
    onClose(w, result) { if (result !== 'server' && st.s?.phase === 'invited' && st.s.role === 'seller') void send('cancel'); },
  });

  // ------------------------------------------------------------------ both: ui_chartradewnd
  game.uiwin.registerWindow?.('chartrade', {
    script: SCRIPTS.main,
    create(w) {
      st.main = w;
      // 14 stat lines in the 187 x 51 multiline label: the overflow scrolls inside the label rect (ENGINE-CHOSEN gap)
      const info = w.control('lbl_charInfo').el;
      if (info) Object.assign(info.style, { overflowY: 'auto', overflowX: 'hidden', height: '44px', whiteSpace: 'pre', pointerEvents: 'auto', alignItems: 'flex-start' });
      const items = sys();
      const grid = w.control('slottradeitem');
      grid._itemsRefresh = render;
      if (items) grid.setItemTooltip?.(it => buildTooltip(items, it.data, { where: 'trade' }));
      grid.on?.('cellrclick', (cell, it) => { if (it) void remove(it.data); });
      grid.on?.('celldbl', (cell, it) => { if (it) void remove(it.data); });
      grid.acceptDrop?.({ referenceSource:'bag',referenceLabel:'Character trade',accept: d => payer() && d?.kind === 'item' && d.from === 'bag', drop: d => add(d.inst, d.count || d.inst.count || 1) });
      w.control('com_characterlist').on?.('change', (i, item) => { if (st.s?.role === 'seller' && st.s.phase === 'open' && item?.value) void send('choose', { characterId: item.value }); });
      w.control('btn_viewdetail').onClick(() => { void openInfo(); });
      const money = w.control('lbl_trademoney');
      money.onClick(async () => { if (!payer()) return; const n = await askAmount(items, txt(6) || 'DIL', Number(game.save?.dil) || 0); if (n) await offer(rows(), n); });
      money.on?.('rclick', () => { if (payer()) void offer(rows(), 0); });
      for (const id of ['btn_ok', 'btn_accept1', 'btn_accept2']) w.control(id).onClick(() => { if (charTradeView(st.s, serverNow())?.canConfirm) void send('confirm'); else render(); });
      w.control('btn_agree').onClick(() => { void send('approve'); });
      for (const id of ['btn_cancel', 'btn_exit']) w.control(id).onClick(() => { void send('cancel'); });
      for (const id of ['lbl_itemmessage', 'lbl_moneymessage', 'pan_inven']) w.control(id).hide?.();
      grid.setTooltip?.(() => (payer() ? 'Drop bag items here. Right-click an offered item to remove it.' : null));
      money.setTooltip?.(() => (payer() ? 'Click to offer DIL; right-click to clear the DIL offer.' : null));
    },
    onOpen(w) { render(); const items = sys(); if (items && st.s?.role === 'buyer') void placeWithBag(items, w); },
    update(w) { if (st.s?.phase === 'locked') { w.control('processbar').setGauge?.(lockProgress(st.s, serverNow())); const ready = !!st.s.unlocked || serverNow() >= st.s.lockUntil; if (ready !== w.data.unlocked) { w.data.unlocked = ready; render(); } } },
    onClose(w, result) { if (result !== 'server' && st.s) void send('cancel'); if (st.info?.isOpen) st.info.close('server'); },
  });

  // ------------------------------------------------------------------ host snapshot -> windows
  const sync = async () => {
    const s = st.s;
    if (!s) {
      if (st.main?.isOpen) st.main.close('server');
      if (st.wait?.isOpen) st.wait.close('server');
      if (st.info?.isOpen) st.info.close('server');
      game.uiwin.close?.('chartradeinvite', 'no');
      return;
    }
    if (s.phase === 'invited') {
      if (s.role === 'buyer') {
        if (st.promptId !== s.id) {
          st.promptId = s.id; const id = s.id;
          const answer = await game.uiwin.msgbox?.(s.partner.name, { script: SCRIPTS.invite, name: 'chartradeinvite', kind: 'yesno', title: txt(INVITE_TITLE.code, INVITE_TITLE.cate) });
          if (st.s?.id === id && st.s.phase === 'invited') await send(answer === 'yes' ? 'accept' : 'decline');
        }
      } else if (!st.wait?.isOpen && !st.waitOpening && !st.disposed) {
        st.waitOpening = true; try { await game.uiwin.open('chartradewait'); } finally { st.waitOpening = false; }
      }
      return;
    }
    if (st.wait?.isOpen) st.wait.close('server');
    if (!st.main?.isOpen && !st.opening && !st.disposed) {
      st.opening = true;
      try { await game.uiwin.open('chartrade'); if (!st.s) st.main?.close('server'); } finally { st.opening = false; }
    }
    render();
  };
  const hook = (n) => {
    if (!n || n._charTradeHooked) return;
    n._charTradeHooked = true;
    const snapshot = n._snapshot.bind(n);
    n._snapshot = (record) => {
      if (n.disposed || Number(record?.sequence) < n.sequence) return;
      snapshot(record);
      n.charTrade = record?.chartrade || null;
      // snapshots stream several times a second: refresh the windows only when the session changed
      const sig = n.charTrade ? JSON.stringify(n.charTrade) : '';
      if (game.network === n && sig !== st.sig) { st.sig = sig; st.s = n.charTrade; void sync(); }
    };
    const event = n._event.bind(n);
    n._event = (record) => {
      if (record?.type === 'chartrade' && game.network === n) {
        const code = eventMsg(record);
        if (code === C.msg.done || code === C.msg.received) void game.uiwin.msgbox?.(txt(code), { title: txt(0) });
        else if (code != null) say(code, 'err');
      }
      return event(record);
    };
  };
  st.hook = () => {
    const n = net();
    if (n === st.net) return;
    st.net = n; st.s = n?.charTrade || null; st.sig = st.s ? JSON.stringify(st.s) : ''; hook(n); void sync();
  };
  st.hook();

  // the receiver's bag right-click offers the item while the payment side is open
  const items = sys();
  if (items?.rightClick) { const rc = items.rightClick.bind(items); items.rightClick = (item, where = 'bag') => (payer() && where === 'bag' && st.main?.isOpen ? add(item) : rc(item, where)); }

  try {
    installPcPop(game).add({ code: MENU.order, cate: MENU.cate, label: MENU.label, visible: t => menuVisible(t, game.player, !!net()?.active), run: t => { if (partyPvpRunning(net())) { say(BUSY_PARTY_PVP, 'err'); return; } void request(t); } });   // Global row 11: 556:38 while a Party PvP runs
  } catch (error) { console.warn('[chartrade] player menu', error); }
  game.chat?.registerCommand?.(COMMAND, (args) => {
    const name = String(args || '').trim().toLowerCase();
    const target = [...(net()?.players?.values?.() || [])].find(p => p.name?.toLowerCase() === name);
    if (target) void request(target); else say(C.msg.notFound, 'err');
    return true;
  }, 'Transfer one of your other characters to a nearby player.');

  API = game.charTrade = { request, state: () => st.s, send, openInfo, render, view: () => charTradeView(st.s, serverNow()), windows: () => ({ main: st.main, info: st.info, wait: st.wait }), _tick: () => st.hook(), busy: () => st.busy };
  return API;
}

/** Follow game.network (created and replaced at login) and keep the timers moving. */
export function update(dt, game) { if (API && game?.charTrade === API) API._tick?.(); }

export function dispose(game) { if (game?.charTrade === API) game.charTrade = null; API = null; }
