// Dungeon entry captcha, the "Dekaron Clean Campaign" check (share dungeonlist CaptchaRate = % of entries that
// ask it: Magic Field of Crack, Ruins of Baz / Rudene, Nunvice Temple 225, Sacred Claw, Forgotten Underground
// Temple, Abandoned Qune's Temple ...) on the original window game2/captchawnd/ui_captchawnd.txt:
//
//   lbl_captchatitle / lbl_explain   2004:130 "Captcha Code" / 2004:131 (the rules, 3 failures = 5 minutes)
//   pan_capcha                       the code image (captcha#0 = captcha_0.png, which the server generated per
//                                    request and the client never shipped: drawn here on a canvas, 240 x 79)
//   pan_answer_0..3 > pan_Num        the typed digits (captchaansnum#0..9)
//   btn_number_0..9, btn_backspace   the keypad (captchabtn#0..9 / +10 over / +20 down)
//   btn_refresh                      a new code
//   btn_ok / btn_cancel              2000:22 / 2000:14
// A wrong code counts a failure ("Captcha Code Failed" 2004:132) and draws a new one; the third failure closes the
// window and bars dungeon entry for 5 minutes (2004:133 "... %d minutes %d seconds ... You cannot enter dungeons.").
import { sysText } from './data.js';

const SCRIPT = 'game2/captchawnd/ui_captchawnd.txt';
const DIGITS = 4;
const FAIL_MAX = 3;
const PENALTY_SEC = 300;

export class Captcha {
  constructor(sys) {
    this.sys = sys;
    this.game = sys.game;
    this.fails = 0;
  }

  get _state() { const s = this.game.save || (this.game.save = {}); return (s.dungeonCaptcha ||= { blockedUntil: 0 }); }

  /** Seconds of the failure penalty left (0 = may enter). */
  blockedFor() { return Math.max(0, Math.ceil((Number(this._state.blockedUntil) - Date.now()) / 1000)); }

  /** Does this entry ask the captcha? (CaptchaRate % per entry) */
  rolls(dungeon) {
    const rate = Number(dungeon?.entry?.captchaRate) || 0;
    return rate > 0 && Math.random() * 100 < rate;
  }

  /** The penalty text (2004:133) for the time left. */
  penaltyText() {
    const s = this.blockedFor();
    return sysText(133, Math.floor(s / 60), s % 60);
  }

  /** Ask the captcha. Resolves true when the right code was entered. */
  async ask() {
    const mgr = this.game.uiwin;
    if (!mgr?.create) return true;
    const win = await mgr.create(SCRIPT, { name: 'dungeon_captcha', modal: true, escClose: true, remember: false, disposeOnClose: true });
    let code = '', typed = [];
    const paintAnswer = () => {
      for (let k = 0; k < DIGITS; k++) {
        const num = win.control(`pan_answer_${k}`).control?.('pan_Num');
        if (!num) continue;
        if (typed[k] == null) num.hide();
        else { num.setSprite('captchaansnum', typed[k]); num.show(); }
      }
    };
    const fresh = () => {
      code = Array.from({ length: DIGITS }, () => Math.floor(Math.random() * 10)).join('');
      typed = [];
      const c = drawCode(code);
      if (c) win.control('pan_capcha').setIcon({ canvas: c });
      paintAnswer();
    };
    return new Promise((resolve) => {
      let done = false;
      const finish = (ok) => { if (done) return; done = true; resolve(ok); };
      win.once('close', (r) => finish(r === 'ok'));
      for (let i = 0; i <= 9; i++) win.control(`btn_number_${i}`).onClick(() => { if (typed.length < DIGITS) { typed.push(i); paintAnswer(); } });
      win.control('btn_backspace').onClick(() => { typed.pop(); paintAnswer(); });
      win.control('btn_refresh').onClick(() => fresh());
      win.control('btn_cancel').onClick(() => win.close('cancel'));
      win.control('btn_ok').onClick(() => {
        if (typed.length === DIGITS && typed.join('') === code) { this.fails = 0; win.close('ok'); return; }
        this.fails++;
        this.sys.notice(sysText(132));
        if (this.fails >= FAIL_MAX) {
          this.fails = 0;
          this._state.blockedUntil = Date.now() + PENALTY_SEC * 1000;
          this.game.persist?.();
          win.close('fail');
          this.sys.ui.result(this.penaltyText());
          return;
        }
        fresh();
      });
      fresh();
      mgr.openWindow(win);
    });
  }
}

/** The code image: digits in varied size / tilt / colour over noise and strike lines (240 x 79). */
function drawCode(code) {
  if (typeof document === 'undefined') return null;
  const W = 240, H = 79;
  const c = document.createElement('canvas');
  c.width = W; c.height = H;
  const x = c.getContext('2d');
  const r = (a, b) => a + Math.random() * (b - a);
  const g = x.createLinearGradient(0, 0, W, H);
  g.addColorStop(0, `hsl(${r(0, 360)},25%,82%)`);
  g.addColorStop(1, `hsl(${r(0, 360)},25%,68%)`);
  x.fillStyle = g;
  x.fillRect(0, 0, W, H);
  for (let i = 0; i < 260; i++) { x.fillStyle = `hsla(${r(0, 360)},40%,${r(30, 70)}%,${r(0.2, 0.6)})`; x.fillRect(r(0, W), r(0, H), r(1, 3), r(1, 3)); }
  const step = W / (code.length + 1);
  for (let i = 0; i < code.length; i++) {
    x.save();
    x.translate(step * (i + 1) + r(-8, 8), H / 2 + r(-6, 6));
    x.rotate(r(-0.45, 0.45));
    x.font = `bold ${Math.round(r(38, 50))}px ${['Georgia', 'Arial Black', 'Verdana', 'Times New Roman'][i % 4]}, serif`;
    x.textAlign = 'center'; x.textBaseline = 'middle';
    x.fillStyle = `hsl(${r(0, 360)},60%,${r(18, 35)}%)`;
    x.strokeStyle = 'rgba(255,255,255,0.5)';
    x.lineWidth = 1;
    x.fillText(code[i], 0, 0);
    x.strokeText(code[i], 0, 0);
    x.restore();
  }
  for (let i = 0; i < 4; i++) {
    x.strokeStyle = `hsla(${r(0, 360)},50%,30%,0.55)`;
    x.lineWidth = r(1, 2.5);
    x.beginPath();
    x.moveTo(0, r(0, H));
    x.bezierCurveTo(r(0, W), r(0, H), r(0, W), r(0, H), W, r(0, H));
    x.stroke();
  }
  return c;
}
