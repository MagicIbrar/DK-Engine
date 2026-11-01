// MONSTER CARNIVAL client (shared play): the Forgotten Shipwreck team mode windows of game2/forgottenshipwreck. The host owns the
// lobby, teams, CP, team skills, result and roulette (server/world/monster-carnival.mjs); this module reads
// snapshot.colosseum.carnival, sends the colosseum carnival-* intents and draws the original windows:
//   wait      ui_matchingwait      161:7 + 161:8 "%d of %d people are waiting.", Cancel
//   score     ui_scorewnd          161:1 timer (monster_carnival digits 0-9), BLUE / RED score numbers
//   team      ui_team_skill_wnd    show / hide tabs, the six skill buttons (monster_carnival 33-38), uses left (161:11), CP (161:3)
//   buff      ui_buff_skill_wnd    skills 1-5: icon, "CP %d consumed" (161:4), text 161:133-137, Use (161:5)
//   target    ui_target_skill_wnd  skill 6: one row per standing opponent (class icon, name, check), 161:138, Use
//   roulette  ui_reward_slotwnd    Shipwreck Roulette (161:2): START asks the host for its slot, then the exit (161:6)
// Effects: 161:105 + 161:225 at the start, 161:103 (win) / 161:104 (lose) at the end. The skill grid of the single btn_skill
// template is ENGINE-CHOSEN (src/config/engine-chosen-monster-carnival.js skillGrid).
import { CARNIVAL_TEXT, CARNIVAL_CODES, CARNIVAL_SKILLS, BLUE, fmt } from '../events/monster-carnival-rules.js';
import { CARNIVAL_CHOSEN as C } from '../../config/engine-chosen-monster-carnival.js';

const SCRIPTS = Object.freeze({ wait: 'ui_matchingwait', score: 'ui_scorewnd', team: 'ui_team_skill_wnd', buff: 'ui_buff_skill_wnd', target: 'ui_target_skill_wnd', roulette: 'ui_reward_slotwnd' });
const plain = s => String(s ?? '').replace(/<\/?center>/gi, '').replace(/<\/?color[^>]*>/gi, '').replace(/^\s*\[message\]\s*/i, '').trim();
const text = (c, v) => c?.setText?.(v == null ? '' : String(v));
const CLASS_ICON = { screen: 'guildwar_apply', first: 11, count: 15 };
/** What the windows show for one carnival snapshot (pure): seconds = the timer of the score window. */
export function carnivalWindowView(s, elapsedMs = 0) {
  const run = s?.run && !s.run.left ? s.run : null;
  const seconds = run ? Math.max(0, Math.ceil((Number(run.remainingMs) - Math.max(0, elapsedMs)) / 1000)) : null;
  return { wait: !!s?.queue && !run, score: !!run, team: !!run && run.phase === 'run', roulette: !!run && run.phase !== 'run', seconds,
    digits: seconds == null ? null : [Math.floor(Math.min(99, Math.floor(seconds / 60)) / 10), Math.min(99, Math.floor(seconds / 60)) % 10, Math.floor((seconds % 60) / 10), seconds % 60 % 10] };
}
/**
 * game.uiwin (registerWindow / open / close), the carnival state getter, and the host intents:
 * ctx = { state(), send(operation, fields) -> Promise<result|null>, str(code) -> native 161 text, say(text, kind),
 *         effect(code) (plays a 161 effect string), itemName(index), selfId() }.
 */
export function installCarnivalWindows(game, ctx) {
  const ui = game.uiwin, wanted = new Map(), pending = new Map();
  let disposed = false, last = null, receivedAt = 0, seen = new Map(), lastNotice = null, collapsed = false, skillOpen = null, target = null, spinning = false;
  const T = key => plain(ctx.str?.(CARNIVAL_CODES[key])) || plain(CARNIVAL_TEXT[key]);
  const S = code => plain(ctx.str?.(code));
  for (const [name, script] of Object.entries(SCRIPTS)) ui?.registerWindow?.(`carnival_${name}`, { script: `game2/forgottenshipwreck/${script}.txt`, hud: ['score', 'team'].includes(name), remember: false, escClose: ['buff', 'target'].includes(name), band: ['score', 'team'].includes(name) ? 'hud' : 'normal' });
  const close = name => { wanted.delete(name); ui?.close?.(`carnival_${name}`); };
  const show = (name, fill) => {
    wanted.set(name, fill); if (pending.has(name) || !ui?.open) return;
    const promise = Promise.resolve(ui.open(`carnival_${name}`)).then(w => { if (disposed || !wanted.has(name)) { ui.close(`carnival_${name}`); return; } wanted.get(name)?.(w); })
      .catch(e => ctx.say?.(e.message, 'err')).finally(() => pending.delete(name));
    pending.set(name, promise);
  };
  const once = (w, key, fn) => { if (!w[key]) { w[key] = true; fn(); } };
  // ------------------------------------------------------------------------------------------------ lobby
  const fillWait = (w, s) => {
    text(w.find('lbl_info'), T('waiting')); text(w.find('lbl_info_count'), fmt(T('count'), s.queue?.waiting || 0, s.need || 0));
    once(w, '_carCancel', () => w.find('btn_cancel')?.onClick?.(() => { void ctx.send('carnival-cancel'); close('wait'); }));
  };
  // ------------------------------------------------------------------------------------------------ in the run
  const fillScore = (w, run, v) => {
    w.find('pan_score')?.setVisible?.(true); text(w.find('lbl_time_info'), T('time'));
    ['pan_min_timer_1', 'pan_min_timer_2', 'pan_sec_timer_1', 'pan_sec_timer_2'].forEach((id, k) => w.find(id)?.setImage?.('none', 'monster_carnival', v.digits[k]));
    w.find('number_blue')?.setNumber?.(run.teams?.[0]?.score || 0); w.find('number_red')?.setNumber?.(run.teams?.[1]?.score || 0);
  };
  const fillTeam = (w, run) => {
    once(w, '_carGrid', () => {
      w.find('btn_skill')?.setVisible?.(false); w.find('pan_skill_icon')?.setVisible?.(false);
      CARNIVAL_SKILLS.forEach((s, k) => {
        const x = C.skillGrid.x + (k % 2) * C.skillGrid.dx, y = C.skillGrid.y + Math.floor(k / 2) * C.skillGrid.dy;
        const b = w.clone?.('btn_skill', `_${s.skill}`, { x, y }), icon = w.clone?.('pan_skill_icon', `_${s.skill}`, { x: x + 5, y: y + 5 });
        icon?.setImage?.('none', 'monster_carnival', s.icon); b?.setEnabled?.(true); b?.onClick?.(() => openSkill(s.skill));
      });
      w.find('btn_hide')?.onClick?.(() => { collapsed = true; last = null; update(); });
      w.find('btn_show')?.onClick?.(() => { collapsed = false; last = null; update(); });
    });
    w.find('pan_skill_window')?.setVisible?.(!collapsed); w.find('btn_hide')?.setVisible?.(!collapsed); w.find('btn_show')?.setVisible?.(collapsed);
    text(w.find('lbl_count_text'), T('uses')); text(w.find('lbl_count'), run.usesLeft); text(w.find('lbl_point_text'), T('cp')); text(w.find('lbl_point_value'), run.cp);
  };
  function openSkill(n) { skillOpen = n; target = null; last = null; update(); }
  const fillBuff = (w, s) => {
    w.find('pan_image')?.setImage?.('none', 'monster_carnival', s.icon); text(w.find('lbl_point'), fmt(T('consumed'), s.cost)); text(w.find('lbl_info'), S(s.long)); text(w.find('btn_confirm'), T('use'));
    once(w, '_carWired', () => {
      w.find('btn_confirm')?.onClick?.(() => { const n = skillOpen; skillOpen = null; close('buff'); void ctx.send('carnival-skill', { skill: n }); });
      w.find('btn_exit')?.onClick?.(() => { skillOpen = null; close('buff'); });
    });
  };
  const fillTarget = (w, run, s) => {
    const foes = (run.members || []).filter(m => m.team !== run.team && !m.left);
    w.find('pan_list')?.setVisible?.(false);
    foes.forEach((m, k) => {
      const row = w.find(`pan_list_${k}`) || w.clone?.('pan_list', `_${k}`, { y: 42 + k * 27 }); row?.setVisible?.(true);
      w.find(`pan_class_icon_${k}`)?.setImage?.('none', CLASS_ICON.screen, CLASS_ICON.first + Math.max(0, Math.min(CLASS_ICON.count - 1, Number(m.classIndex) | 0)));
      text(w.find(`lbl_name_${k}`), m.name); const check = w.find(`check_target_${k}`); check?.setChecked?.(target === m.id);
      if (check && check._carFor !== m.id) { check._carFor = m.id; check.onClick?.(() => { target = target === m.id ? null : m.id; last = null; update(); }); }
    });
    for (let k = foes.length; w.find(`pan_list_${k}`); k++) w.find(`pan_list_${k}`).setVisible?.(false);
    text(w.find('lbl_point'), fmt(T('consumed'), s.cost)); text(w.find('lbl_info'), S(s.long)); text(w.find('btn_confirm'), T('use'));
    once(w, '_carWired', () => {
      w.find('btn_confirm')?.onClick?.(() => { if (!target) { ctx.say?.(T('badTarget'), 'err'); return; } const t = target; skillOpen = null; target = null; close('target'); void ctx.send('carnival-skill', { skill: 6, target: t }); });
      w.find('btn_exit')?.onClick?.(() => { skillOpen = null; target = null; close('target'); });
    });
  };
  const fillRoulette = (w, run) => {
    const spun = run.spun;
    text(w.find('lbl_title'), T('roulette'));
    w.find('lbl_result_rullet')?.setVisible?.(!!spun); text(w.find('lbl_result_rullet'), spun ? `${ctx.itemName?.(spun.item) || spun.item} x${spun.count}` : '');
    w.find('btn_exit')?.setVisible?.(!!spun); w.find('lbl_info')?.setVisible?.(!!spun); text(w.find('lbl_info'), S(6));
    w.find('btn_start')?.setEnabled?.(!spun && !spinning);
    once(w, '_carWired', () => {
      w.find('btn_start')?.onClick?.(() => { if (spinning || ctx.state()?.run?.spun) return; spinning = true; Promise.resolve(ctx.send('carnival-spin')).then(r => { if (r?.text) ctx.say?.(r.text, 'item'); }).finally(() => { spinning = false; last = null; update(); }); });
      w.find('btn_exit')?.onClick?.(() => { void ctx.send('carnival-exit'); close('roulette'); });
    });
  };
  // ------------------------------------------------------------------------------------------------ events
  function onEvents(run) {
    const mine = seen.get(run.id) || 0, fresh = (run.events || []).filter(e => e.seq > mine); if (!fresh.length) return;
    seen.set(run.id, Math.max(mine, ...fresh.map(e => e.seq)));
    for (const e of fresh) {
      if (e.kind === 'start') for (const code of e.effects || []) ctx.effect?.(code);
      if (e.kind === 'result') {
        const won = e.winner === run.team, side = e.winner == null ? '' : T(e.winner === BLUE ? 'blue' : 'red');
        ctx.effect?.(won ? e.effects?.[0] : e.effects?.[1]); ctx.say?.(`${side} ${run.result?.scores?.join(' : ') || ''}`.trim());
      }
      if (e.kind === 'skill') ctx.say?.(`${e.name}: ${S(32 + Number(e.skill)).replace(/\s*\n\s*/g, ' ')}`);
    }
  }
  function update(s = ctx.state()) {
    if (disposed) return;
    if (s !== last?.s) { if (s && s !== last?.s) receivedAt = performance.now(); }
    const v = carnivalWindowView(s, performance.now() - receivedAt), key = JSON.stringify([s, v.seconds, collapsed, skillOpen, target, spinning]);
    if (key === last?.key) return; last = { s, key };
    if (s?.notice && s.notice.at !== lastNotice) { lastNotice = s.notice.at; ctx.say?.(plain(s.notice.text)); }
    const run = s?.run && !s.run.left ? s.run : null;
    if (run) onEvents(run);
    if (v.wait) show('wait', w => fillWait(w, s)); else close('wait');
    if (v.score) show('score', w => fillScore(w, run, v)); else close('score');
    if (v.team) show('team', w => fillTeam(w, run)); else { close('team'); skillOpen = null; }
    const skill = v.team && skillOpen ? CARNIVAL_SKILLS.find(x => x.skill === skillOpen) : null;
    if (skill && !skill.target) show('buff', w => fillBuff(w, skill)); else close('buff');
    if (skill?.target) show('target', w => fillTarget(w, run, skill)); else close('target');
    if (v.roulette) show('roulette', w => fillRoulette(w, run)); else close('roulette');
  }
  /** /carnival: the lobby (register / waiting window), or the team skill window inside a run. */
  async function open() {
    const s = ctx.state();
    if (s?.run && !s.run.left) { collapsed = !collapsed; last = null; update(); return; }
    if (s?.queue) { last = null; update(); return; }
    const r = await ctx.send('carnival-register');
    if (r?.registered) ctx.say?.(T('waiting'));
  }
  return { update, open, view: carnivalWindowView, dispose() { disposed = true; for (const name of Object.keys(SCRIPTS)) close(name); } };
}
