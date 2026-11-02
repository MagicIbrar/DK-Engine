// LOGIN screen (docs/ARCHITECTURE.md §3.9): the client's login scene and its original window.
//
// Scene: maplist 110 "New_Server" = map/MAL_Login.map, the login map of this client (sound.json bgmSpecial.login is
// playlist 9999 = bgm/bgm_mal_login.mp3). A throne room whose .mol places MAL_Login_Sit (Alokes in the RON costume
// on MAL_Login_Chair, skel object/etc/mal_login_sit.skel + anim mal_chair_sit.anim, 6 s loop): the animated figure
// sitting on the throne, played by the world's ObjectLayer. The room floor is terrain height 19 (the ceiling is a
// temple floor mesh 7.9 m above it, which is why the camera heights below are absolute). The vertical field of view
// is the map row's FOV (0.65 rad). The camera path itself is hard-coded in the client exe (not part of the data):
// a slow dolly from the whole hall up the carpet towards the throne, with a gentle sway.
//
// Window: script/ui/game2/ui_loginwnd.txt, built by the UI platform (src/ui/uiwin). As in the client, the server
// group window (pan_selectgroup: "Server Login" / "Exit Game") retains its selected-host row; the selected host opens its login panel directly
// (pan_login: ID / PW edits, Log In, Server/Exit = save, sign out and return to browser server choice, the virtual-keyboard toggle btn_vk that
// opens game2/login/ui_keyboardwnd.txt with its 36 shuffled keys). Login requires an existing server account
// and password, or its verified website session (accounts.js). Messages go to pan_message / lbl_message (stringtable_system.txt
// <cate> 100: "Logging into the server." ...).
// Decision: pan_15 / pan_18 (the Korean 15+/18+ rating marks) are hidden as in the EU client.
import { rowFovDeg } from './stage.js';
import { cloneTemplate, rich } from './ui.js';

export const LOGIN_MAP = 110;
/** The server logo shown in the login hall's logo slot (the server's own art). */
export const SERVER_LOGO = '/client-assets/server-logo-v1.png';
/** Opened by the launcher after its sign-in (launch.html adds gate=1 for all three clients; shell=native = Dekaron.exe). */
export const LAUNCHER_GATE = () => { try { const q = new URLSearchParams(globalThis.location?.search || ''); return q.get('gate') === '1' || q.get('shell') === 'native'; } catch { return false; } };
const FLOOR = 19;
export const THRONE = { x: 255.85, z: 271.7 };
export const SERVER_NAME = 'Dekaron Online';
/** The server's own name (server list, in-game server panel). The game title stays SERVER_NAME. */
export const SERVER_LABEL = 'Dekaron Online';

/** Login camera at time t (s): dolly-in over DOLLY seconds, then a slow sway. FILE frame. */
const DOLLY = 24;
export function loginCamera(t, fov = 37.24) {
  const k = Math.min(1, t / DOLLY);
  const e = 1 - Math.pow(1 - k, 3);
  const sway = Math.sin(t * 0.11) * 0.45;
  // from the whole hall (curtains, pillars, the weapon racks) up the carpet to the throne and its seated figure,
  // framed above the bottom-centre login windows
  return {
    eye: { x: THRONE.x + sway, y: FLOOR + 2.6 - e * 0.25, z: 254 + e * 5.5 },
    target: { x: THRONE.x + sway * 0.2, y: FLOOR + 0.9 - e * 0.15, z: THRONE.z },
    fov,
  };
}

/** A shuffled virtual keyboard layout (36 keys: digits + letters), as security keypads do. */
export function keyboardLayout(rnd = Math.random) {
  const keys = '1234567890abcdefghijklmnopqrstuvwxyz'.split('');
  for (let i = keys.length - 1; i > 0; i--) { const j = Math.floor(rnd() * (i + 1)); [keys[i], keys[j]] = [keys[j], keys[i]]; }
  return keys;
}

export class LoginScreen {
  constructor(fe) {
    this.fe = fe;
    this.stage = fe.stage;
    this.T = fe.texts;
    this.win = null;
    this.vk = null;
    this._t0 = 0;
    this.server = null;
    this.serverLabel = SERVER_LABEL;
    this.lastEdit = null;
  }

  /** @returns {Promise<{account:string}>} */
  async run() {
    const fe = this.fe, stage = this.stage;
    await this._buildUI();
    this._t0 = stage.time;
    const fov = rowFovDeg(fe.data.mapByIndex(LOGIN_MAP));
    this._offFrame = stage.onFrame(() => {
      const c = loginCamera(stage.time - this._t0, fov);
      stage.lookFrom(c.eye, c.target, c.fov);
    });
    fe.playBGM('login');
    // The startup cover stays until catalogs, login geometry and shader work
    // finish. No artificial minimum duration is applied to a cached load.
    // 'dekaron:login-ready' marks the hall as shown (automated checks)
    fe.showWindow(this.win);
    const ready = stage.loadWorld(LOGIN_MAP, { focus: { x: THRONE.x, z: THRONE.z - 4 }, onProgress:(fraction,label)=>fe.startupSceneProgress?.(fraction,label) });
    const presented=ready.then(async () => { await fe.finishPreload(); fe.fade(0, 900); try { globalThis.dispatchEvent?.(new Event('dekaron:login-ready')); } catch { /* no window */ } });
    presented.catch(error=>{fe.preload?.fail(error);console.error('[frontend] startup failed',error);});
    const res = await new Promise(resolve => { this._resolve = resolve; });
    await presented;
    return res;
  }

  // ---------------------------------------------------------------------------------------- window
  async _buildUI() {
    const ui = this.fe.uim;
    const [win, vk] = await Promise.all([
      ui.create('game2/ui_loginwnd.txt', { name: 'login', escClose: false, remember: false, autoClose: false }),
      ui.create('game2/login/ui_keyboardwnd.txt', { name: 'vkeyboard', escClose: false, remember: false, autoClose: false }),
    ]);
    this.win = win; this.vk = vk;
    const links = this.accountLinks = document.createElement('nav');
    links.className = 'fe-account-links';
    links.setAttribute('aria-label', 'Account links');
    const next = new URLSearchParams(location.search).get('client') === 'desktop' ? '/?client=desktop' : '/';
    for (const [label, href] of [['Create account', '/site/signup.html?next=' + encodeURIComponent(next)], ['Account website', '/site/'], ['Host a world', '/web/public/hosting.html'], ['Help', '/web/public/help.html']]) {
      const a = document.createElement('a'); a.textContent = label; a.href = href; links.appendChild(a);
    }
    this.fe.ui.appendChild(links);
    const c = id => win.control(id);

    c('pan_15').hide();
    c('pan_18').hide();
    // The server's own logo in the server group window's
    // selected-server image slot (pan_selectsvr_img, 122 x 138 inside the left box pan_bg_select), below the server name
    // label that overlaps its top 25 px, scaled to fit without stretching. The top-left game logo stays the original.
    // The art is the server's own (client-assets/server-logo-v1.png).
    {
      const slot = c('pan_selectsvr_img');
      if (slot?.el) {
        const badge = document.createElement('div');
        badge.className = 'fe-server-badge'; badge.setAttribute('aria-hidden', 'true');
        const img = document.createElement('img');
        img.src = SERVER_LOGO; img.alt = ''; img.draggable = false; img.className = 'fe-server-logo';
        // additive glow copy of the same art (screen-blended, opacity-only animation)
        const glow = document.createElement('img');
        glow.src = SERVER_LOGO; glow.alt = ''; glow.draggable = false; glow.className = 'fe-server-logo fe-server-logo-glow';
        badge.appendChild(img); badge.appendChild(glow); slot.el.appendChild(badge);
        let visible = false;
        const sync = () => { badge.dataset.animate = String(visible && !document.hidden); };
        const observer = new IntersectionObserver(entries => { visible = entries.some(e => e.isIntersecting); sync(); });
        observer.observe(badge); document.addEventListener('visibilitychange', sync); sync();
        this._disposeBadge = () => { observer.disconnect(); document.removeEventListener('visibilitychange', sync); badge.remove(); };
      }
    }
    // only the game's name, centred (the label is `align center` at `center bottom`)
    c('lbl_tag_copyright').setText(SERVER_NAME);

    // ---- server group window: one server row (a clone of the btn_serverlist template)
    const row = this.serverRow = cloneTemplate(win, 'btn_serverlist', 'btn_serverlist_0', [24, 6, 251, 34]);
    if (row) {
      row.control('lbl_servername')?.setText(SERVER_LABEL);
      this.serverBorder = row.control('pan_serverborder');
      row.onClick(() => this._pickServer());
      row.onDoubleClick(() => { this._pickServer(); this._serverLogin(); });
    }
    c('select_ok').onClick(() => this._serverLogin());
    c('select_quit').onClick(() => this._quit());
    this._pickServer();
    fetch('/api/server/info',{cache:'no-store',credentials:'same-origin'}).then(r=>r.ok?r.json():null).then(info=>{
      if(!this.win||this._closed||typeof info?.name!=='string')return;
      this.serverLabel=info.name;this._pickServer();
      this.serverRow?.control('lbl_servername')?.setText(info.name);
      this.win.control('pan_pantheon').setText(info.name);
    }).catch(()=>{});

    // ---- login panel
    this.idEdit = win.find('edt_account');
    this.pwEdit = win.find('edt_password');
    // Global ui_loginwnd: edt_account maxlength 20, edt_password maxlength 16.
    // Engine/website account policy (site/signup.html): ID 3-32, password 6-128 — intentional extension.
    if (this.idEdit?.input) { this.idEdit.input.maxLength = 32; this.idEdit.input.autocomplete = 'username'; }
    if (this.pwEdit?.input) { this.pwEdit.input.maxLength = 128; this.pwEdit.input.autocomplete = 'current-password'; }
    this.idEdit?.setValue(this.fe.accounts.lastId());
    // Prefill only a server-marked fresh local demo, never an existing private store.
    fetch('/api/auth/demo',{cache:'no-store'}).then(r=>r.ok?r.json():null).then(d=>{
      if(!this.fe.requireCredentials && d?.localDemo && d.id==='admin' && ['', 'admin'].includes(this.idEdit?.getValue() || '') && !this.pwEdit?.getValue()){
        this.idEdit?.setValue('admin');this.pwEdit?.setValue('password');
      }
    }).catch(()=>{});
    for (const e of [this.idEdit, this.pwEdit]) {
      if (!e) continue;
      e.on('enter', () => this._login());
      e.on('escape', () => this._toServers());
      e.on('focus', () => { this.lastEdit = e; });
    }
    c('btn_login').onClick(() => this._login());
    c('btn_pantheon').onClick(() => this._toServers());
    c('btn_quit').onClick(() => this._quit());
    c('btn_vk').onClick(() => this._toggleVK());
    // Global login click path / FUN_00a4f030: btn_OK dismisses pan_message2 (+ pan_message).
    c('btn_OK').onClick(() => this._dismissLoginMessage());

    // ---- virtual keyboard (hidden until btn_vk)
    this._layoutVK();
    vk.control('btn_back').onClick(() => { const e = this._vkTarget(); if (e) e.setValue(e.getValue().slice(0, -1)); });
    vk.control('btn_enter').onClick(() => this._login());

    // Enter on the server list = Server Login
    this._onKey = ev => {
      if (!this.win || this._busy || ev.key !== 'Enter') return;
      if (this.win.control('pan_selectgroup').isVisible()) { ev.preventDefault(); this._serverLogin(); }
    };
    globalThis.addEventListener('keydown', this._onKey);
    if (this.fe.requireCredentials) { this.idEdit?.setValue(''); this.pwEdit?.setValue(''); }
    // Launcher clients: the launcher already signed this window in (one-use
    // ticket, launch.html), so the hall keeps its server group window and the server button / Server Login enters with that
    // session - no ID / password. Without a live session it falls back to the ID / PW panel like every other client.
    if (LAUNCHER_GATE() && !this.fe.requireCredentials) {
      this.sessionAccount = await this.fe.accounts.restore({ configure: false }).catch(() => null);
      // Launcher gate: restore session but do NOT auto-click Server Login / 2nd password — owner signs in himself.
      if (this.sessionAccount) return;
    }
    // The launcher/browser URL already selects a host. Start directly at working credential fields.
    this._serverLogin();
  }

  _pickServer() {
    this.server = this.serverLabel;
    this.serverBorder?.setSprite('loginselect', 12);
    this.win.control('lbl_selectsvr_name').setText(this.serverLabel);
  }

  /** "Server Login": leave the server list for the ID / PW panel (Dekaron.exe with its launcher session: enter directly). */
  _serverLogin() {
    if (!this.server) { this._message(rich(this.T.raw(30, 50))); return; }
    if (this.sessionAccount) { this.idEdit?.setValue(''); this.pwEdit?.setValue(''); void this._login(); return; }
    const c = id => this.win.control(id);
    c('pan_selectgroup').hide();
    c('pan_login').show();
    c('pan_pantheon').setText(this.server);
    setTimeout(() => ((this.idEdit?.getValue() ? this.pwEdit : this.idEdit) || this.pwEdit)?.focus(), 30);
  }

  /** "Server" returns to the browser's server picker after saving and signing out. */
  _toServers() { return this._quit(); }

  // ---------------------------------------------------------------------------------------- virtual keyboard
  _layoutVK() {
    const keys = keyboardLayout();
    for (let i = 1; i <= 36; i++) {
      const b = this.vk.find(`btn_key${i}`);
      if (!b) continue;
      b.setText(keys[i - 1]);
      b.data.char = keys[i - 1];
      if (!b.data.wired) {
        b.data.wired = true;
        b.onClick(() => {
          const e = this._vkTarget();
          if (e && e.getValue().length < (e.input?.maxLength > 0 ? e.input.maxLength : 20)) e.setValue(e.getValue() + b.data.char);
        });
      }
    }
  }

  /** The edit the keys type into: the last focused one of the login panel (the password by default). */
  _vkTarget() { return this.lastEdit || this.pwEdit; }

  /** Global btn_OK / FUN_00a4f030(0): hide pan_message + pan_message2. */
  _dismissLoginMessage() {
    clearTimeout(this._msgT);
    this._msgT = null;
    this.win?.control('pan_message')?.hide();
    this.win?.control('pan_message2')?.hide();
  }

  _toggleVK() {
    const on = !this.vk.isOpen;
    if (on) { this._layoutVK(); this.fe.uim.openWindow(this.vk); } else this.fe.uim.closeWindow(this.vk);
    this.win.control('btn_vk').setChecked(on);
  }

  // ---------------------------------------------------------------------------------------- messages
  // Global FUN_00a4f560 empty ID/PW path: *(this+0x20)=2000 ms toast then hide pan_message.
  _message(text, ms = 2000) {
    const pan = this.win.control('pan_message');
    this.win.control('lbl_message').setRichText(text);
    pan.show();
    clearTimeout(this._msgT);
    if (ms) this._msgT = setTimeout(() => pan.hide(), ms);
  }

  async _login() {
    if (this._busy) return;
    this._busy = true;
    try {
      this.fe.sfx('etc_login_button.wav');
      // system messages of the connection process (stringtable_system.txt <cate> 100)
      const sys = await this.fe.systemText();
      this._message(sys.get('100:3') || 'Logging into the server.', 0);
      const r = await this.fe.accounts.login(this.idEdit?.getValue() || '', this.pwEdit?.getValue() || '', { configure: false });
      if (!r.ok) { this._message(r.message || 'Login failed.'); return; }
      this.pwEdit?.setValue('');
      this.fe.gameData();                    // start loading the game tables in the background
      await new Promise(res => setTimeout(res, 350));
      this._message(sys.get('100:4') || 'You have logged into the server.', 0);
      this._close();
      this._resolve({ account: r.account });
    } catch (error) {
      this._message(error?.message || 'Login failed. Please try again.');
    } finally {
      this._busy = false;
    }
  }

  async _quit() {
    if (this._busy) return;
    this._busy = true;
    try {
      this.idEdit?.setValue(''); this.pwEdit?.setValue('');
      this.fe.uim.closeWindow(this.vk);
      await this.fe.serverMenu();
    } catch (error) { this._message(error.message); }
    finally { this._busy = false; }
  }

  _close() {
    this._closed = true;
    this._disposeBadge?.(); this._disposeBadge = null;
    this.accountLinks?.remove();
    this._offFrame?.();
    globalThis.removeEventListener('keydown', this._onKey);
    const ui = this.fe.uim, win = this.win, vk = this.vk;
    this.fe.hideWindow(win).then(() => { win.dispose(); vk.dispose(); });
    ui.closeWindow(vk);
  }
}
