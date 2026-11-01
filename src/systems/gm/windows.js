// The original GM windows of the client, through the UI platform (docs/UIWIN.md):
//   gmconsole   script/ui/console/ui_main.txt        developer console: output panel over a 200-char command line
//                                                     (Alt+` / "`" / /gm console; history Up/Down, Tab completion)
//   gmsysinfo   script/ui/console/ui_system.txt      "SYSTEM INFOMATION" 600x400 text view + refresh (/gm sysinfo,
//                                                     /gm monitor = the live user monitor)
//   gmnotice    script/ui/game2/gmtool/ui_gmtoolwnd.txt   GM Tool notice editor "Write Notice": Send to All / Send to
//                                                     Map / Remove (511 chars, 6 lines)
//   gmmessage   script/ui/game2/gmtool/ui_gmmessagewnd.txt  the player-side GM message window (13 yellow lines)
//   gmrestrain  script/ui/game2/gmtool/ui_shutoffwnd.txt    "Restrain Chat" (minutes + Yes / No)
import { gmData } from './data.js';
import { atlas } from '../../ui/atlas.js';

export class GMWindows {
  constructor(gm) {
    this.gm = gm;
    this.game = gm.game;
    this.hist = [];
    this.hIndex = -1;
    this.lines = [];
  }

  register() {
    const ui = this.game.uiwin;
    const self = this;
    // ------------------------------------------------------------------ console
    ui.registerWindow('gmconsole', {
      script: 'console/ui_main.txt', band: 'system', remember: false,
      create(win) {
        self.cwin = win;
        const admin = document.createElement('button');
        admin.type = 'button';
        admin.textContent = 'ADMIN';
        admin.title = 'Open GM tools (F10)';
        admin.setAttribute('aria-label', 'Open GM tools');
        admin.style.cssText = 'position:absolute;right:8px;top:6px;z-index:20;padding:4px 12px;border:1px solid #bc9c53;border-radius:3px;background:#17130f;color:#f3d891;font:700 12px Arial,sans-serif;cursor:pointer;';
        admin.addEventListener('pointerdown', event => event.stopPropagation());
        admin.addEventListener('click', event => { event.stopPropagation(); self.gm.openPanel(); });
        win.el.append(admin);
        // the script's backdrop sprite (group "console") is not in this client's imagetable: use the common white
        // sprite modulated to a translucent black (docs/UIWIN.md 6, common#1 + color)
        atlas.sprite('console', 1).then(s => {
          if (s) return;
          for (const id of ['pan_output', 'pan_command']) win.control(id).setImage('none', { screen: 'common', index: 1, color: id === 'pan_output' ? 'B4000000' : 'E0101010' });
        }).catch(() => {});
        const out = win.control('text_out');
        for (const l of self.lines) out.addLine?.(l.text, l.color);
        const ed = win.control('edit_command');
        ed.setPlaceholder?.('GM command (e.g. /gm help, /gm callmonster Spider 3, /gm move Ardeca) - Tab completes, Up/Down history');
        ed.on('enter', () => {
          const v = String(ed.getValue() || '').trim();
          ed.setValue('');
          if (!v) return;
          self.hist.unshift(v); self.hist = self.hist.slice(0, 60); self.hIndex = -1;
          self.print(`> ${v}`, 'ffc8c8c8');
          const line = /^[/`]/.test(v) || /^gm\s/i.test(v) ? v : `/gm ${v}`;
          self.gm.run(line, { source: 'console' });
          setTimeout(() => ed.focus(), 0);
        });
        ed.on('escape', () => win.close());
        ed.input?.addEventListener('keydown', (e) => {
          if (e.key === 'ArrowUp' || e.key === 'ArrowDown') {
            e.preventDefault();
            self.hIndex = Math.max(-1, Math.min(self.hist.length - 1, self.hIndex + (e.key === 'ArrowUp' ? 1 : -1)));
            ed.setValue(self.hIndex >= 0 ? self.hist[self.hIndex] : '');
          } else if (e.key === 'Tab') {
            e.preventDefault();
            ed.setValue(self.complete(String(ed.getValue() || '')));
          } else if (e.code === 'Backquote') {
            // ` toggles the console (the command line never needs the character itself)
            e.preventDefault();
            if (!e.repeat) { ed.blur?.(); win.close(); }
          } else if (e.code === 'F10') {
            e.preventDefault(); ed.blur?.(); self.gm.togglePanel();
          }
          e.stopPropagation();
        });
      },
      onOpen(win) { setTimeout(() => win.control('edit_command').focus(), 30); },
    });
    // ------------------------------------------------------------------ system info / user monitor
    ui.registerWindow('gmsysinfo', {
      script: 'console/ui_system.txt', band: 'system',
      create(win) {
        self.swin = win;
        win.control('btn_title').onClick(() => self.fillSysinfo(win));
      },
      onOpen(win, mode) { win.data.mode = mode || 'info'; win.control('lbl_title').setText(mode === 'monitor' ? 'USER MONITOR' : 'SYSTEM INFOMATION'); self.fillSysinfo(win); },
      update(win, dt) {
        if (win.data.mode !== 'monitor') return;
        win.data.t = (win.data.t || 0) - dt;
        if (win.data.t <= 0) { win.data.t = 1; self.fillSysinfo(win); }
      },
    });
    // ------------------------------------------------------------------ notice editor
    ui.registerWindow('gmnotice', {
      script: 'game2/gmtool/ui_gmtoolwnd.txt',
      create(win) {
        win.control('pan_back').setVisible(true);
        win.control('btn_view').onClick(() => { const p = win.control('pan_back'); p.setVisible(!p.isVisible()); });
        const text = () => String(win.control('textbox').getText?.() || '').trim();
        win.control('btn_allsend').onClick(() => { const t = text(); if (t) self.gm.run(`/gm notice all "${t.replace(/"/g, "'")}"`); });
        win.control('btn_mapsend').onClick(() => { const t = text(); if (t) self.gm.run(`/gm notice map "${t.replace(/"/g, "'")}"`); });
        win.control('btn_delete').onClick(() => { self.gm.run('/gm notice clear'); win.control('textbox').clear?.(); });
      },
      onOpen(win) { setTimeout(() => win.control('textbox').focus?.(), 30); },
    });
    // ------------------------------------------------------------------ GM message (player side)
    ui.registerWindow('gmmessage', { script: 'game2/gmtool/ui_gmmessagewnd.txt', escClose: true });
    // ------------------------------------------------------------------ restrain chat
    ui.registerWindow('gmrestrain', {
      script: 'game2/gmtool/ui_shutoffwnd.txt', modal: true,
      create(win) {
        win.control('lbl_already').setText(self.gm.st.muteUntil > Date.now() ? `Chat is restrained until ${new Date(self.gm.st.muteUntil).toLocaleTimeString()}.` : '');
        win.control('lbl_text').setText('Restrain your own chat for the number of minutes below (0 lifts it).');
        win.control('lbl_text_time').setText('min');
        win.control('btn_yes').onClick(() => { const m = Number(win.control('edit_time').getValue?.() || 0) || 0; win.close('yes'); self.gm.run(`/gm mute me ${m}`); });
        win.control('btn_no').onClick(() => win.close('no'));
      },
      onOpen(win) { win.control('edit_time').setValue?.('10'); },
    });
  }

  // ------------------------------------------------------------------ console output
  print(text, color = 'ffffedfc') {
    const t = String(text ?? '');
    for (const line of t.split('\n')) {
      this.lines.push({ text: line, color });
      if (this.lines.length > 400) this.lines.shift();
      this.cwin?.control('text_out').addLine?.(line, color);
    }
  }
  toggleConsole() { return this.game.uiwin.toggle('gmconsole'); }
  /** Tab completion: command ids / aliases, then list names of the argument under the cursor. */
  complete(v) {
    const m = /^(\/gm\s+|\/)?(\S*)$/i.exec(v);
    if (m) {
      const pre = m[2].toLowerCase();
      const ids = [...gmData.commands.map(c => c.id), ...gmData.extra.keys()];
      const hits = ids.filter(i => i.startsWith(pre));
      if (hits.length === 1) return `/gm ${hits[0]} `;
      if (hits.length > 1) { this.print(hits.join('  '), 'ffa0d2ff'); let p = hits[0]; for (const h of hits) while (!h.startsWith(p)) p = p.slice(0, -1); return `/gm ${p}`; }
      return v;
    }
    const mm = /^\/gm\s+(\S+)\s+(.*)$/i.exec(v);
    const cmd = mm ? (gmData.command(mm[1]) || gmData.extra.get(mm[1].toLowerCase())) : null;
    const arg = cmd?.args?.find(a => a.list);
    if (cmd && arg && typeof arg.list === 'string' && gmData.loaded(arg.list)) {
      const q = mm[2].trim().toLowerCase();
      gmData.list(arg.list).then(rows => {
        const hits = rows.filter(r => r.name.toLowerCase().startsWith(q)).slice(0, 12);
        if (hits.length) this.print(hits.map(r => `${r.id}:${r.name}`).join('  '), 'ffa0d2ff');
      });
    } else if (cmd && arg) gmData.list(arg.list);   // warm the list for the next Tab
    if (cmd?.args?.some(a => a.type === 'enum')) this.print(cmd.syntax, 'ffa0d2ff');
    return v;
  }

  // ------------------------------------------------------------------ system info
  openSysinfo(mode = 'info') { return this.game.uiwin.open('gmsysinfo', mode); }
  fillSysinfo(win) {
    const tv = win.control('text_view');
    tv.clear?.();
    for (const l of (win.data.mode === 'monitor' ? this.gm.monitorLines() : this.gm.sysinfoLines())) tv.addLine?.(l, 'ffffffff');
    tv.setTop?.(0);
  }

  // ------------------------------------------------------------------ notices
  openNoticeEditor() { this.game.uiwin.open('gmnotice'); return null; }
  async showNotice(text) {
    const win = await this.game.uiwin.open('gmmessage');
    const tb = win.control('textbox');
    tb.clear?.();
    for (const l of String(text).split(/\\n|\n/)) tb.addLine?.(l, 'ffedfc00');
    this.game.chat?.system?.(`[GM] ${String(text).replace(/\\n/g, ' ')}`, 'gm');
  }
  hideNotice() { this.game.uiwin.close('gmmessage'); }
}
