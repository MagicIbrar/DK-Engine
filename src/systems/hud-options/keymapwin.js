// The "Change Controls" window (script/ui/game2/keymap/ui_keymapwnd.txt): one row per action of the current key
// version, rows built from the hidden pan_base template (label, key button, clear button, separator line, 24 px
// high = pivot_line), 18 visible rows scrolled by keymap_scroll. Click a key button then press a key (with
// Ctrl/Shift/Alt) to bind it; the x clears it. OK keeps, Cancel reverts, "Reverting all" restores the defaults,
// "Shortkey version reset" switches between the old and the new key version (2202:5 / 2202:121).
import { ACTIONS, ACTION_BY_ID, bindingName, MAX_KEYS } from './keymap.js';
import { str, plainMarkup } from './util.js';

const ROW_H = 24;
const OLD_HEADERS = [0, 14, 23, 34, 41, 54, 67, 82, 93];
const rowLabel = row => ACTION_BY_ID.get(row?.id)?.label || str(2200, row?.code);

/** Rows of a key version: [{code, header, id}] */
export function keymapRows(version) {
  if (version === 1) {
    const rows = [];
    const byOld = new Map(ACTIONS.filter(a => a.id && a.old != null).map(a => [a.old, a]));
    for (let code = 0; code <= 99; code++) {
      if (OLD_HEADERS.includes(code)) { rows.push({ code, header: true }); continue; }
      const a = byOld.get(code);
      if (a && str(2200, code)) rows.push({ code, id: a.id });
    }
    for (const a of ACTIONS.filter(a => a.kind === 'camera')) rows.push({ code: a.code, id: a.id });
    return rows;
  }
  return ACTIONS.map(a => ({ code: a.code, header: !a.id, id: a.id }));
}

export function registerKeymapWindow(game, ctx) {
  const km = ctx.keymap;
  game.uiwin.registerWindow('keymap', {
    script: 'game2/keymap/ui_keymapwnd.txt',
    create(win) {
      const d = win.data;
      d.rows = [];
      d.top = 0;
      d.listen = null;
      const area = win.control('pan_keycontrol');
      const tpl = win.control('pan_base');   // the row template (hidden): lbl_keymap_base, btn_keymap_base, ...
      const visible = Math.floor((area.box.h || 432) / ROW_H);
      for (let i = 0; i < visible; i++) {
        const r = tpl.cloneAs(`_${i}`, { x: 0, y: i * ROW_H, parent: area });
        r.setRect(0, i * ROW_H, 444, ROW_H);
        const btn = win.control(`btn_keymap_base_${i}`);
        const clr = win.control(`btn_keymap_clear_base_${i}`);
        btn.onClick(() => startListen(i));
        clr.onClick(() => clearRow(i));
        r.el.addEventListener('wheel', (e) => { e.preventDefault(); scrollTo(d.top + Math.sign(e.deltaY) * 3); }, { passive: false });
        d.rows.push({ panel: r, lbl: win.control(`lbl_keymap_base_${i}`), btn, clr, line: win.control(`lbl_keymapline_base_${i}`) });
      }
      const sc = win.control('keymap_scroll');
      sc.on('change', v => { d.top = v; render(); });
      area.el.addEventListener('wheel', (e) => { e.preventDefault(); scrollTo(d.top + Math.sign(e.deltaY) * 3); }, { passive: false });

      const list = () => keymapRows(km.version);
      function scrollTo(t) {
        const max = Math.max(0, list().length - d.rows.length);
        d.top = Math.max(0, Math.min(max, Math.round(t)));
        sc.setRange(max, d.rows.length).setValue(d.top);
        render();
      }
      function render() {
        const L = list();
        sc.setRange(Math.max(0, L.length - d.rows.length), d.rows.length);
        d.rows.forEach((row, i) => {
          const it = L[d.top + i];
          row.item = it || null;
          row.panel.setVisible(!!it);
          if (!it) return;
          const label = rowLabel(it);
          row.lbl.setRichText(plainMarkup(label).replace(/^\s+/, it.header ? '' : '    '));
          row.btn.setVisible(!it.header);
          row.clr.setVisible(!it.header);
          if (!it.header) {
            row.btn.setText(bindingName(km.get(it.id)));
            row.btn.setChecked(d.listen === it.id);
          }
        });
        const n = km.count();
        win.control('lbl_count').setRichText(plainMarkup(str(2202, n >= MAX_KEYS ? 3 : 2)).replace('%u', n).replace('%d', MAX_KEYS));
        win.control('btn_version_change').setText(str(2202, km.version === 2 ? 119 : 120) || str(2202, 4));
      }
      function message(code, vars = {}) {
        let s = plainMarkup(str(2202, code));
        for (const [k, v] of Object.entries(vars)) s = s.replace(`<${k}>`, v);
        win.control('lbl_message').setRichText(s);
      }
      function startListen(i) {
        const it = d.rows[i]?.item;
        if (!it || it.header) return;
        d.listen = d.listen === it.id ? null : it.id;
        if (d.listen) message(114, { lblname: plainMarkup(rowLabel(it)).trim() });
        render();
      }
      function clearRow(i) {
        const it = d.rows[i]?.item;
        if (!it || it.header) return;
        km.set(it.id, '');
        d.listen = null;
        message(113, { lblname: plainMarkup(rowLabel(it)).trim() });
        render();
      }
      // key capture while a row listens (capture phase: nothing else sees the key)
      d.onKey = (e) => {
        if (!win.isOpen || !d.listen) return;
        e.preventDefault(); e.stopPropagation();
        const code = e.code;
        if (code === 'Escape') { d.listen = null; render(); return; }
        const isMod = /^(Control|Shift|Alt)(Left|Right)$/.test(code);
        let spec;
        if (isMod) spec = code.startsWith('Control') ? 'Ctrl' : code.startsWith('Shift') ? 'Shift' : 'Alt';
        else {
          const mods = [];
          if (e.ctrlKey) mods.push('Ctrl');
          if (e.shiftKey) mods.push('Shift');
          if (e.altKey) mods.push('Alt');
          spec = [...mods, code].join('+');
        }
        const name = bindingName(spec);
        if (km.forbidden(code)) { message(115); return; }
        const owner = km.holder(spec, d.listen);
        if (owner) { message(116, { keyname: name }); return; }
        if (!km.get(d.listen) && km.count() >= MAX_KEYS) { message(1); return; }
        km.set(d.listen, spec);
        message(111, { keyname: name });
        d.listen = null;
        render();
      };
      addEventListener('keydown', d.onKey, true);
      // mouse buttons can't be bound: a click elsewhere just stops listening

      win.control('btn_ok').onClick(() => { d.snapshot = null; win.close('ok'); });
      win.control('btn_cancel').onClick(() => win.close('cancel'));
      win.control('btn_keyorigin').onClick(() => { km.resetAll(); d.listen = null; message(118); render(); });
      win.control('btn_version_change').onClick(async () => {
        const toOld = km.version === 2;
        const r = await game.uiwin.msgbox(plainMarkup(str(2202, toOld ? 5 : 121)).replace(/\\/g, ''), { kind: 'yesno' });
        if (r !== 'yes') return;
        km.version = toOld ? 1 : 2;
        km.save();
        d.top = 0;
        render();
      });
      d.render = render;
      d.scrollTo = scrollTo;
    },
    onOpen(win) {
      const d = win.data;
      d.snapshot = { version: ctx.keymap.version, bindings: { ...ctx.keymap.bindings } };
      d.listen = null;
      win.control('lbl_message').setText('');
      d.scrollTo(0);
    },
    onClose(win, result) {
      const d = win.data;
      if (result !== 'ok' && d.snapshot) {
        ctx.keymap.version = d.snapshot.version;
        ctx.keymap.bindings = d.snapshot.bindings;
        ctx.keymap.save();
        ctx.keymap.emit('change', null);
      }
      d.snapshot = null;
      d.listen = null;
      if (win.data.returnTo) { const t = win.data.returnTo; win.data.returnTo = null; t(); }
    },
  });
  return { ACTION_BY_ID };
}
