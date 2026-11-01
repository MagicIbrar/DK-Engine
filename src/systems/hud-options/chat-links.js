// CHAT-LINKS: item links in the chat + the link windows of the original client.
//   * insert: Shift + left click on a bag / equipment item while the chat input line is open writes "[Item Name]" into the
//     line (CHAT_LINK_CONFIG.insertGesture); on send the label becomes an {item:uid} token (chat.js _out -> encode).
//     Single player resolves the tokens against the own save (resolveLocal); shared play sends them and the host
//     (social.mjs / party.mjs / guilds.mjs, hostChatLinks) swaps them for "[Name]" + a copy of the item it owns.
//   * show: a chat line with links gets clickable runs coloured by the item grade (stringtable_color palette); hover = the
//     item tooltip, click = the pinned link tooltip game2/itemlink/ui_tooltip.txt (ItemLinktooltipwnd: pan_tooltip in the
//     etc_01#66 frame + btn_exit), Ctrl + click = the Preview window game2/itemlinkpreview/ui_itemlinkpreview.txt.
//   * Preview (100:154): lbl_item_name, pan_bg 360x360 model slot; btn_link_item "Link Item" (2000:89) shows the linked
//     item, btn_my_chara "My Character" (2000:83) the own body wearing it (costume / wing; other items keep the look);
//     pets / mounts: "Link Pet" / "My Pet" (2000:85/86), "Link Mount" / "My Mount" (2000:87/88); btn_ok "Ok" (2000:15).
//     Drag on the model turns it, the wheel zooms.
//   * key map 908 "Show ItemLink" (no default key) reopens the last link (CHAT_LINK_CONFIG.showItemLinkKey).
// Engine choices: chat-links-config.js (ENGINE-CHOSEN, not in Global data).
import { str, plainText, needStrings } from './util.js';
import { ITEM_GRADE_COLORS } from '../../ui/item-colors.js';
import {
  CHAT_LINK_CONFIG as C, CHAT_LINK_SCRIPTS, CHAT_LINK_STRINGS as S, PREVIEW_BUTTONS,
  linkToken, linkLabel, resolveChatLinks, linkableItems, cleanLinks, linkSegments, previewKind,
} from './chat-links-rules.js';

const ALL_REFS = Object.values(S).map(([cate, code]) => ({ group: 'NORMAL', cate, code }));

export function installChatLinks(game, ctx) {
  const chat = ctx.chat;
  const st = { pending: [], expected: [], last: null, pinned: null, holder: null };
  const pv = { win: null, link: null, kind: 'item', mode: 'link', model: null, body: null, drag: null };
  void needStrings?.(ALL_REFS)?.catch?.(() => {});
  const items = () => game.items;
  const nameOf = (i) => items()?.db?.def?.(i)?.name || '';
  const T = (k, fb = '') => plainText(str(...S[k]) || '') || fb;
  const gradeColor = (item) => {
    const def = items()?.db?.def?.(item?.itemIndex);
    const stack = def && (items()?.db?.stackSize?.(def) || 1) > 1;
    return ITEM_GRADE_COLORS[stack || def?.slot === 'vehicle' ? 'normal' : item?.grade] || ITEM_GRADE_COLORS.normal;
  };
  const mountsData = () => game.mounts?.system?.data || null;

  // ------------------------------------------------------------------ writing a link
  function editor() { return chat.win?.control?.('edit_text') || null; }
  /** Write an item's "[Name]" into the chat input line (opens it). */
  function insert(inst) {
    if (!inst?.uid) return false;
    const name = nameOf(inst.itemIndex);
    if (!name) return false;
    if (!chat.inputOpen) chat.openInput();
    const ed = editor();
    if (!ed) return false;
    const cur = String(ed.getValue() ?? '');
    st.pending = st.pending.filter(p => cur.includes(linkLabel(p.name)));
    if (st.pending.length >= C.maxLinksPerMessage) { chat.system(C.tooManyText, 'err'); return true; }
    const label = linkLabel(name);
    const next = `${cur}${cur && !/\s$/.test(cur) ? ' ' : ''}${label} `;
    const max = Number(ed.input?.maxLength) > 0 ? Number(ed.input.maxLength) : Infinity;
    if (next.length > max) return true;
    ed.setValue(next);
    st.pending.push({ name, uid: inst.uid });
    setTimeout(() => { try { ed.focus?.(); const n = ed.input.value.length; ed.input.setSelectionRange(n, n); } catch { /* ignore */ } }, 0);
    return true;
  }
  /** Bag / equipment click hook (items/ui/inventory.js): Shift + click while the input line is open = link the item. */
  function fromClick(inst, e) {
    if (!inst || !chat.inputOpen) return false;
    const shift = !!e?.shiftKey || !!(game.input?.down?.('ShiftLeft') || game.input?.down?.('ShiftRight'));
    return shift ? insert(inst) : false;
  }
  /** chat.js _out: the input's link labels -> {item:uid} tokens, in the order they were inserted. */
  function encode(text) {
    let out = String(text ?? '');
    const list = st.pending; st.pending = [];
    let from = 0;
    for (const p of list) {
      const label = linkLabel(p.name), k = out.indexOf(label, from);
      if (k < 0) continue;
      const tok = linkToken(p.uid);
      out = out.slice(0, k) + tok + out.slice(k + label.length);
      from = k + tok.length;
    }
    return out;
  }
  /** Single player: the tokens against the own save (the same rules the host applies). */
  function resolveLocal(text) {
    const own = new Map(linkableItems(game.save).map(e => [e.uid, e]));
    for (const e of items()?.bag?.list || []) if (e?.uid && !own.has(e.uid)) own.set(e.uid, e);
    for (const { inst } of items()?.equip?.entries?.() || []) if (inst?.uid && !own.has(inst.uid)) own.set(inst.uid, inst);
    return resolveChatLinks(text, uid => own.get(uid), nameOf);
  }

  // ------------------------------------------------------------------ receiving
  /** A host chat record carries links: kept until chat.say shows that text. */
  function expect(record) {
    const links = cleanLinks(record?.links);
    if (!links.length) return;
    st.expected.push({ text: String(record.text ?? ''), links });
    if (st.expected.length > 20) st.expected.shift();
  }
  /** chat.say: the line's links (given, or the expected record with the same text). */
  function incoming(given, text) {
    const k = st.expected.findIndex(x => x.text === String(text ?? ''));
    const hit = k >= 0 ? st.expected.splice(k, 1)[0].links : null;
    const links = given ? cleanLinks(given) : hit;
    if (links?.length) st.last = links[links.length - 1];
    return links?.length ? links : null;
  }
  /** Rebuild a chat line element with clickable link runs. */
  function decorate(div, e) {
    if (!div || !e?.links?.length) return;
    const segs = linkSegments(e.text, e.links);
    if (!segs.some(s => s.link != null)) return;
    div.replaceChildren();
    for (const s of segs) {
      const span = document.createElement('span');
      span.textContent = s.text;
      if (s.link != null) {
        const l = e.links[s.link];
        span.className = 'chat-itemlink';
        span.dataset.itemlink = String(s.link);
        Object.assign(span.style, { color: gradeColor(l.item), cursor: 'pointer', pointerEvents: 'auto' });
        span.addEventListener('pointerenter', (ev) => { span.style.textDecoration = 'underline'; hoverTip(l, ev); });
        span.addEventListener('pointerleave', () => { span.style.textDecoration = ''; game.uiwin.tooltips?.hide?.(); });
        // pointerdown, not click: the text box captures the pointer for its drag-scroll, so a click never reaches the run
        span.addEventListener('pointerdown', (ev) => { if (ev.button) return; ev.stopPropagation(); ev.preventDefault(); void open(l, ev); });
        span.addEventListener('click', (ev) => { ev.stopPropagation(); ev.preventDefault(); });   // not the line's whisper click
      }
      div.appendChild(span);
    }
  }
  function tipOf(l) { try { return items()?.tooltip?.(l.item, { where: 'link' }) || null; } catch (err) { console.error(err); return null; } }
  function hoverTip(l, ev) { const t = tipOf(l); if (t) game.uiwin.tooltips?.show?.(t, ev.clientX, ev.clientY); }
  /** Click: pin the tooltip; Ctrl + click: the Preview window. */
  function open(l, ev) {
    game.uiwin.tooltips?.hide?.();
    st.last = l;
    return ev?.ctrlKey ? openPreview(l) : pin(l, ev);
  }

  // ------------------------------------------------------------------ pinned link tooltip (ItemLinktooltipwnd)
  game.uiwin.registerWindow('itemlinktooltip', {
    script: CHAT_LINK_SCRIPTS.tooltip, escClose: true, remember: false, pos: { x: 0, y: 0 },
    create(win) {
      win.root.el.style.pointerEvents = 'none';
      for (const id of ['textbox', 'lbl_tooltiptitle', 'pan_tooltiptitle', 'btn_arrow', 'pan_tooltipEx']) win.find(id)?.setVisible?.(false);
      const pan = win.control('pan_tooltip');
      pan.el.style.pointerEvents = 'auto';
      const holder = document.createElement('div');
      Object.assign(holder.style, { position: 'absolute', left: '0', top: '0' });
      pan.el.appendChild(holder);
      st.holder = holder;
      const exit = win.control('btn_exit');
      exit.el.style.pointerEvents = 'auto';
      exit.el.style.zIndex = '10000';   // above pan_tooltip (layer 200), as the client draws the X on the frame
    },
    onOpen(win, arg) {
      if (!arg?.content) return;
      st.holder.replaceChildren(arg.content);
      const sc = game.uiwin.scale || 1, r = arg.content.getBoundingClientRect?.() || { width: 180, height: 80 };
      const w = Math.max(60, Math.ceil(r.width / sc)), h = Math.max(30, Math.ceil(r.height / sc));
      fitBox(win, w, h);
      win.control('pan_tooltip').setRect(0, 0, w, h);
      win.control('btn_exit').setRect(w - 22, 3, 19, 19);
      const [ox, oy] = C.pinnedOffset;
      const p = arg.at ? game.uiwin.toLayer(arg.at[0], arg.at[1]) : { x: Math.round((game.uiwin.screen.w - w) / 2), y: Math.round((game.uiwin.screen.h - h) / 2) + h + oy };
      win.setPosition(Math.round(p.x + ox), Math.round(p.y - h - oy), false);
      st.pinned = arg.link;
    },
  });
  function fitBox(win, W, H) {
    win.box.w = W; win.box.h = H;
    win.el.style.width = `${W}px`; win.el.style.height = `${H}px`;
    win.root._rectOverride = [0, 0, W, H];
    win.root.layout({ x: 0, y: 0, w: W, h: H });
  }
  async function pin(l, ev) {
    const content = tipOf(l);
    if (!content) return false;
    await game.uiwin.open('itemlinktooltip', { link: l, content, at: ev && Number.isFinite(ev.clientX) ? [ev.clientX, ev.clientY] : null });
    return true;
  }

  // ------------------------------------------------------------------ Preview (ui_itemlinkpreview.txt)
  game.uiwin.registerWindow('itemlinkpreview', {
    script: CHAT_LINK_SCRIPTS.preview, escClose: true, remember: true,
    async create(win) {
      pv.win = win;
      win.find('pan_mark')?.setVisible?.(false);
      win.control('btn_ok').onClick(() => win.close('close'));
      win.control('btn_link_item').onClick(() => void show('link'));
      win.control('btn_my_item').onClick(() => void show('mine'));
      win.control('btn_my_chara').onClick(() => void show('chara'));
      const bg = win.control('pan_bg');
      // pan_bg is the client's 3D render slot (common #65500, no sprite) over the translucent Itemchoice #2 body: the client
      // renders the model on its own cleared view, so the slot gets a solid backing instead of showing the world through it
      if (bg.el) bg.el.style.backgroundColor = '#000000';
      try {
        const { ModelPreview } = await import('../shops/preview.js');
        pv.model = new ModelPreview(game, 360, 360);
        bg.setIcon({ canvas: pv.model.canvas });
      } catch (err) { console.warn('[chat-links] preview model', err); }
      const el = bg.el;
      if (el) {
        el.style.pointerEvents = 'auto';
        el.addEventListener('pointerdown', (e) => { pv.drag = e.clientX; e.stopPropagation(); });
        addEventListener('pointerup', () => { pv.drag = null; });
        el.addEventListener('pointermove', (e) => { if (pv.drag == null) return; const d = (e.clientX - pv.drag) / 80; pv.drag = e.clientX; turn(d); });
        el.addEventListener('wheel', (e) => { e.preventDefault(); zoom(e.deltaY < 0 ? 1.1 : 1 / 1.1); }, { passive: false });
      }
    },
    onOpen(win, link) { if (link) void setLink(win, link); },
    onClose() { pv.body?.clear?.(); pv.mode = 'link'; },
    update(win, dt) { if (pv.mode === 'link') pv.model?.tick?.(dt); else pv.body?.tick?.(dt); },
  });
  function turn(d) { const m = pv.mode === 'link' ? pv.model : pv.body; if (!m) return; if (m === pv.model) m.auto = false; m.rotate?.(d); }
  function zoom(f) { const m = pv.mode === 'link' ? pv.model : pv.body; if (m?.setZoom) m.setZoom((m.zoom || 1) * f); }
  async function setLink(win, link) {
    pv.link = link;
    pv.kind = previewKind(link.item.itemIndex, mountsData());
    const b = PREVIEW_BUTTONS[pv.kind];
    const name = win.control('lbl_item_name');
    name.setText(link.name);
    if (name.el) name.el.style.color = gradeColor(link.item);
    win.control('btn_link_item').setText(T(b.link, 'Link Item'));
    win.control('btn_my_item').setVisible(!!b.mine);
    if (b.mine) win.control('btn_my_item').setText(T(b.mine));
    win.control('btn_my_chara').setVisible(b.chara);
    await show('link');
  }
  /** mode: 'link' (the linked item / pet / mount), 'chara' (own body wearing it), 'mine' (own pet / mount of that kind). */
  async function show(mode) {
    const win = pv.win, link = pv.link;
    if (!win || !link) return false;
    const bg = win.control('pan_bg');
    if (mode === 'chara') {
      const sys = game.mounts?.system;
      if (!sys || !game.player) return false;
      if (!pv.body) { const { ModelPreview: BodyPreview } = await import('../mounts/ui-util.js'); pv.body = new BodyPreview(sys, bg, { w: 360, h: 360 }); }
      pv.mode = 'chara';
      bg.setIcon(null);
      const idx = link.item.itemIndex, cls = Number(game.player.classIndex ?? 0);
      await pv.body.showPlayer({ costume: sys.data?.costume?.(idx, cls) ? idx : null, wing: sys.data?.wing?.(idx) ? idx : null });
      return true;
    }
    let index = link.item.itemIndex;
    if (mode === 'mine') {
      const data = mountsData();
      const own = linkableItems(game.save).find(e => previewKind(e.itemIndex, data) === pv.kind);
      if (!own) { chat.system(pv.kind === 'pet' ? C.noOwnPetText : C.noOwnMountText, 'err'); return false; }
      index = own.itemIndex;
    }
    pv.body?.clear?.();
    pv.mode = 'link';
    if (pv.model) { bg.setIcon({ canvas: pv.model.canvas }); pv.model.auto = true; await pv.model.show(index); }
    pv.shown = { mode, index };
    return true;
  }
  async function openPreview(l) {
    await game.uiwin.open('itemlinkpreview', l);
    return true;
  }

  // key map 908 "Show ItemLink": the last link again
  game.events?.on?.('keyaction', (a) => { if (a?.id === 'itemlink' && st.last) void pin(st.last, null); });

  const api = {
    insert, fromClick, encode, resolveLocal, expect, incoming, decorate, open, pin, openPreview, show,
    clear: () => { st.pending = []; },
    state: st, preview: pv,
  };
  chat.links = api;
  game.chatLinks = api;
  return api;
}