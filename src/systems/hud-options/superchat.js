// Super chat: the Megaphone / DK Megaphone input window (game2/chat/ui_superchatinputwnd.txt) and the broadcast
// band at the top of the screen (game2/chat/ui_superchatwnd.txt). Rules, string ids and sources: ./superchat-rules.js.
//   * right click on a Megaphone (item Type 0 Code 38) or DK Megaphone (Code 39) -> 175:1 when the area does not fit the
//     item, else the input window: title 100:126 / 100:127, the item art (imagetable megaphone 2 / 3, its notes 174:38 /
//     174:39 as tooltip), 160 characters, repeat 1..5 (btn_left / btn_right, lbl_repeat), colour palette (btn_open ->
//     pan_color btn_color_1..8), Enter / btn_enter -> caution box 80:69 + 81:69 (80:70 + 81:70) -> broadcast.
//   * shared play: the host spends one Megaphone per broadcast and queues them (server/world/megaphone.mjs); offline the
//     same rules run on the local bag and the band shows the queue to the player alone.
//   * the band: one broadcast at a time "<name> : <text>" in its colour; a click on the name opens pan_pop (Party 240:4 ->
//     party invite, Whisper 240:3 -> the chat input, Friend 240:1 -> the friend list). Each broadcast also goes to the
//     chat window's world box (text_superchat).
import { str, plainText, needStrings } from './util.js';
import {
  SUPERCHAT_SCRIPTS, SUPERCHAT_STRINGS as S, MEGAPHONE_COLORS, MEGAPHONE_DEFAULT_COLOR, MEGAPHONE_MAX_REPEAT, MEGAPHONE_SLOT_MS,
  megaphoneCode, megaphoneMapBlocker, checkMegaphone, sameLeft, recordSame, SUPERCHAT_TEXT,
} from './superchat-rules.js';

const text = (ref, key) => plainText(str(ref[0], ref[1]) || SUPERCHAT_TEXT[key] || '').replace(/\s*\n\s*/g, ' ').trim();
const live = (e, now) => !!e && !(e.expiresAt && e.expiresAt <= now);

export function installSuperChat(game, ctx) {
  void needStrings([
    ['NORMAL', 100, 126], ['NORMAL', 173, 38], ['NORMAL', 174, 38], ['NORMAL', 80, 69], ['NORMAL', 81, 69],
    ['NORMAL', 170, 59], ['NORMAL', 175, 1], ['NORMAL', 240, 1], ['NORMAL', 230, 78],
  ]).catch(err => console.warn('[superchat] strings', err));
  const st = { item: null, code: 38, repeat: 1, color: MEGAPHONE_DEFAULT_COLOR, busy: false };
  const band = { win: null, queue: [], current: null, until: 0, popName: '' };
  const online = () => game.save?.authority === 'server' && !!game.network;
  const channel = () => online() ? game.network.self?.channel ?? 0 : 0;
  const me = () => game.player?.name || game.save?.name || '';
  const sys = (t, kind = 'sys') => game.chat?.system?.(t, kind);

  // ------------------------------------------------------------------ input window
  game.uiwin.registerWindow('superchatinput', {
    script: SUPERCHAT_SCRIPTS.input,
    modal: false,
    create(win) {
      const ed = win.control('edt_input');
      ed.on('enter', () => void submit(win));
      win.control('btn_enter').onClick(() => void submit(win));
      win.control('btn_left').onClick(() => { st.repeat = Math.max(1, st.repeat - 1); paint(win); });
      win.control('btn_right').onClick(() => { st.repeat = Math.min(MEGAPHONE_MAX_REPEAT, st.repeat + 1); paint(win); });
      const pal = win.control('pan_color');
      win.control('btn_open').onClick(() => pal.setVisible(!pal.isVisible()));
      for (let k = 0; k < MEGAPHONE_COLORS.length; k++) {
        win.control(`btn_color_${k + 1}`).onClick(() => { st.color = k; pal.setVisible(false); paint(win); });
      }
      const ty = win.control('btn_type');
      ty.setText(str(...S.eng) || 'ENG'); ty.setChecked(true);
      ty.onClick(() => ty.setChecked(!ty.isChecked()));
    },
    onOpen(win, arg) {
      st.item = arg?.item || null; st.code = Number(arg?.code) || 38; st.repeat = 1; st.color = MEGAPHONE_DEFAULT_COLOR;
      win.control('lbl_title').setText(plainText(str(...S.title[st.code]) || ''));
      const art = win.control('pan_megaphone');
      art.setImage('none', { screen: 'megaphone', index: st.code === 39 ? 3 : 2 });
      art.setTooltip(str(...S.notes[st.code]) || null);
      win.control('pan_color').setVisible(false);
      win.control('edt_input').clear?.();
      paint(win);
      setTimeout(() => win.control('edt_input').focus?.(), 0);
    },
  });
  function paint(win) {
    win.control('lbl_repeat').setText(String(st.repeat));
    win.control('edt_input').input?.style && (win.control('edt_input').input.style.color = `#${MEGAPHONE_COLORS[st.color]}`);
  }
  async function submit(win) {
    if (st.busy || !st.item) return false;
    const checked = checkMegaphone({ text: win.control('edt_input').getValue(), color: st.color, repeat: st.repeat });
    if (checked.error) { sys(text(S.failed, 'failed'), 'err'); return false; }
    const answer = await caution(st.code);
    if (answer !== 'yes') return false;
    st.busy = true;
    try {
      const ok = online() ? await sendOnline(checked) : sendLocal(checked);
      if (!ok) { sys(text(S.failed, 'failed'), 'err'); return false; }
      sys(text(S.sent, 'sent'));
      game.uiwin.close('superchatinput', 'sent');
      return true;
    } finally { st.busy = false; }
  }
  /** Caution box 80:69/81:69 (80:70/81:70) in msgbox/ui_msgbox_ok.txt. Engine choice: the 12-line original text is
   *  taller than the 90 px lbl_text, so the box grows (frame, text, Yes/No moved down) to fit it once it opens. */
  async function caution(code) {
    const ui = game.uiwin, NAME = 'superchatcaution';
    const fit = (w) => { if (w?.name === NAME || w?.opts?.name === NAME) { ui.off?.('open', fit); try { fitCaution(w); } catch (err) { console.error(err); } } };
    ui.on?.('open', fit);
    try {
      return await ui.msgbox(plainText(str(...S.caution[code]) || ''), { title: plainText(str(...S.cautionTitle[code]) || ''), kind: 'yesno', name: NAME });
    } catch { return 'no'; } finally { ui.off?.('open', fit); }
  }
  function fitCaution(w) {
    const body = w.find?.('lbl_text');
    if (!body?.el || !w.box) return;
    const extra = Math.max(0, Math.ceil(body.el.scrollHeight) - (body.box?.h || 90) + 4);
    if (!extra) return;
    const W = w.box.w, H = w.box.h + extra;
    w.box.h = H; w.el.style.height = `${H}px`;
    w.root._rectOverride = [0, 0, W, H];
    w.root.layout({ x: 0, y: 0, w: W, h: H });
    const grow = (id) => { const c = w.find(id); if (c?.box) c.setRect(c.box.x, c.box.y, c.box.w, c.box.h + extra); };
    const down = (id) => { const c = w.find(id); if (c?.box) c.setRect(c.box.x, c.box.y + extra, c.box.w, c.box.h); };
    grow('pan_back'); grow('lbl_text'); down('btn_yes'); down('btn_no');
    w.center?.();
  }
  async function sendOnline(checked) {
    const n = game.network;
    const result = await n.action('megaphone', { uid: st.item.uid, text: checked.text, color: checked.color, repeat: checked.repeat });
    return !!result?.megaphoneResult;
  }
  function sendLocal(checked) {
    const items = game.items, now = Date.now();
    const blocker = megaphoneMapBlocker(st.code, channel());
    if (blocker) { sys(text(S[blocker], blocker), 'err'); return false; }
    const stacks = [st.item, ...(items?.bag?.list || []).filter(e => e !== st.item && live(e, now) && megaphoneCode(items.def(e.itemIndex)) === st.code)];
    if (!live(st.item, now) || stacks.reduce((n, e) => n + (e.count || 1), 0) < checked.repeat) { sys(text(S.noItem, 'noItem'), 'err'); return false; }
    const life = game.save.life || (game.save.life = {});
    if (sameLeft(life.megaphone, checked.text, now) < checked.repeat) return false;
    let left = checked.repeat;
    for (const e of stacks) { const take = Math.min(left, e.count || 1); items.consume(e, take); left -= take; if (!left) break; }
    life.megaphone = recordSame(life.megaphone, checked.text, checked.repeat, now);
    try { game.persist?.(); } catch (err) { console.error(err); }
    for (let i = 0; i < checked.repeat; i++) receive({ name: me(), text: checked.text, color: MEGAPHONE_COLORS[checked.color], code: st.code, duration: MEGAPHONE_SLOT_MS });
    return true;
  }
  /** Item use (items/use.js offline, network/items.js online): returns false, the broadcast spends the items. */
  function use(inst, def) {
    const code = megaphoneCode(def);
    if (!code || !inst) return false;
    const blocker = megaphoneMapBlocker(code, channel());
    if (blocker) { sys(text(S[blocker], blocker), 'err'); return false; }
    void game.uiwin.open('superchatinput', { item: inst, code });
    return false;
  }

  // ------------------------------------------------------------------ the band
  game.uiwin.registerWindow('superchat', {
    script: SUPERCHAT_SCRIPTS.output,
    hud: true, escClose: false, remember: false,
    create(win) {
      band.win = win;
      win.root.el.style.pointerEvents = 'none';
      const out = win.control('pan_output'), pop = win.control('pan_pop');
      out.el.style.pointerEvents = 'auto'; pop.el.style.pointerEvents = 'auto';
      out.setVisible(false); pop.setVisible(false);
      const line = document.createElement('div');
      Object.assign(line.style, { position: 'absolute', left: '0', top: '0', height: '20px', lineHeight: '20px', padding: '0 12px', whiteSpace: 'nowrap', font: '12px Tahoma, sans-serif', textShadow: '1px 1px 0 #000' });
      const name = document.createElement('span'), body = document.createElement('span');
      name.style.cursor = 'pointer';
      line.append(name, body); out.el.append(line);
      band.line = line; band.name = name; band.body = body;
      name.addEventListener('click', (e) => {
        e.stopPropagation();
        if (!band.current || band.current.name === me()) return;
        band.popName = band.current.name;
        pop.control('lbl_name').setText(band.popName);
        const sc = game.uiwin.scale || 1, r = out.el.getBoundingClientRect(), n = name.getBoundingClientRect();
        pop.setRect(Math.round((r.left - win.root.el.getBoundingClientRect().left) / sc + (n.left - r.left) / sc), 20, 145, 62);
        pop.setVisible(true);
      });
      pop.control('btn_invite').onClick(() => { pop.setVisible(false); if (game.party?.inviteName) void game.party.inviteName(band.popName); else sys(`[${band.popName}] ${str(1006, 48)}`, 'err'); });
      pop.control('btn_whisper').onClick(() => { pop.setVisible(false); game.chat?.openInput?.(`"${band.popName} `); });
      pop.control('btn_friend').onClick(() => { pop.setVisible(false); const f = game.life?.friends; if (f?.add) f.add(band.popName); else sys(`[${band.popName}] ${str(1006, 48)}`, 'err'); });
      addEventListener('pointerdown', (e) => { if (pop.isVisible() && !pop.el.contains(e.target)) pop.setVisible(false); }, true);
    },
    update(win) {
      const now = performance.now();
      if (band.current && now >= band.until) { band.current = null; win.control('pan_output').setVisible(false); win.control('pan_pop').setVisible(false); }
      if (!band.current && band.queue.length) show(band.queue.shift());
    },
  });
  function show(b) {
    const win = band.win;
    band.current = b; band.until = performance.now() + (Number(b.duration) || MEGAPHONE_SLOT_MS);
    band.name.textContent = `${b.name} : `;
    band.body.textContent = b.text;
    band.line.style.color = `#${b.color || 'ffffff'}`;
    const out = win.control('pan_output'), sc = game.uiwin.scale || 1;
    out.setVisible(true);
    // the band script is 1024 wide at 0,0: keep it at the top of the screen, centred horizontally (engine placement)
    const W = win.box?.w || 1024, scrW = game.uiwin.screen?.w || W;
    win.setPosition?.(Math.max(0, Math.round((scrW - W) / 2)), 0, false);
    const w = Math.ceil(band.line.getBoundingClientRect().width / sc) || 200;
    out.setRect(Math.max(0, Math.round((W - w) / 2)), 0, w, 20);
  }
  /** One broadcast (host event or local): to the band queue and the chat window's world box. */
  function receive(b) {
    if (!b?.text) return;
    band.queue.push(b);
    const label = plainText(str(...(S.name[b.code] || S.name[38])) || 'Megaphone');
    game.chat?.say?.('megaphone', b.name, b.text, { color: b.color, label });
    if (!game.uiwin.isOpen('superchat')) void game.uiwin.open('superchat');
  }
  const api = { use, receive, submit: () => band && game.uiwin.window('superchatinput') && submit(game.uiwin.window('superchatinput')), state: st, band };
  game.superchat = api;
  return api;
}