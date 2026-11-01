// Skill master popup + skill blind.
//   skillmasterwnd   game2/skill/ui_skillmasterwnd.txt  "Learn Skill" (100:4): the newly learned skill's icon and the
//                    client's learn line 60:25 "You have learned the skill:  [<name>]"; OK / close / Esc dismiss it
//                    and show the next queued first learn.
//   skill_blind_win  game2/skill/ui_skillblindwnd.txt   full-screen blind: four blocking panels around a clickable
//                    cut-out (pan_clickable_area). Never opened on its own; game.skillMaster.blind(rect) opens it.
// Triggers, queueing and the blind's use are ENGINE-CHOSEN (src/config/engine-chosen-skill-master.js); placement,
// sprites, fonts and texts are the scripts' and string tables' own. Pure helpers: rules.js.
import { needStrings } from '../hud-options/util.js';
import {atlas} from '../../ui/atlas.js';
import {repairMissingCloseButton} from '../../ui/native-close-art.js';
import { SKILL_MASTER_SCRIPTS as SCRIPTS, WINDOW, CONTROLS as K, TITLE, SKILL_MASTER_ENGINE_CHOSEN as C,
  labelText, LearnTracker, localLearn, enqueue, blindRects } from './rules.js';

let API = null;

export async function install(game) {
  if (!game.uiwin) return null;
  const ui = game.uiwin;
  const st = { queue: [], showing: null, shown: [], tracker: new LearnTracker(), opening: false, blindRect: null };
  const engine = () => game.skills;
  const who = () => game.save?.id ?? game.save?.name ?? null;
  const skillsNow = () => game.save?.skills || {};
  void needStrings([[TITLE.group, TITLE.cate, TITLE.code]]).catch(() => {});

  const paint = (win, index) => {
    const e = engine(), s = e?.skillDef?.(index);
    if (!s) return false;
    win.control(K.icon).setIcon({ sprite: ['skill_icon', Number(s.iconIndex ?? s.index)] });
    win.control(K.label).setText(labelText(e.messages?.[C.labelMessage] ?? e.msg?.(C.labelMessage) ?? '', s.name));
    return true;
  };
  const next = () => {
    if (st.opening || st.showing != null || ui.isOpen(WINDOW.master)) return;
    while (st.queue.length) {
      const index = st.queue.shift();
      if (!engine()?.skillDef?.(index)) continue;
      st.showing = index;
      st.opening = true;
      Promise.resolve(ui.open(WINDOW.master, index)).catch(err => { console.warn('[skillmaster] open failed', err); st.showing = null; })
        .finally(() => { st.opening = false; });
      return;
    }
  };
  const announce = indexes => {
    if (!indexes.length) return;
    enqueue(st.queue, indexes, st.showing);
    if (C.closeBlindOnLearn && ui.isOpen(WINDOW.blind)) ui.close(WINDOW.blind, 'learn');
    next();
  };

  ui.registerWindow(WINDOW.master, {
    script: SCRIPTS.master, escClose: true, modal: false,
    create(win) {
      repairMissingCloseButton(win.control(K.close),'skill_up',21,atlas.table);
      win.control(K.ok).onClick(() => win.close('ok'));
      win.control(K.close).onClick(() => win.close('close'));
    },
    onOpen(win, index) {
      if (!paint(win, index)) { win.close('missing'); return; }
      st.shown.push(index);
      if (st.shown.length > 32) st.shown.shift();
    },
    onClose() {
      st.showing = null;
      setTimeout(next, 0);
    },
  });

  ui.registerWindow(WINDOW.blind, {
    script: SCRIPTS.blind, escClose: C.blindEscClose, modal: false, remember: false,
    create(win) {
      // the blocks are intersect true in the script (the client's own hit test), but carry no image, which the
      // engine's generic panels would let the mouse through: a click sink keeps them taking the mouse as scripted
      for (const id of K.blocks) win.control(id).onClick(() => {});
    },
    onOpen(win, rect) {
      st.blindRect = rect || null;
      const r = blindRects(rect || { x: 0, y: 0, w: 0, h: 0 }, ui.screen || { w: 1024, h: 768 });
      win.control(K.hole).setRect(...r.hole);
      K.blocks.forEach((id, i) => win.control(id).setRect(...r.blocks[i]));
    },
    onClose() { st.blindRect = null; },
  });

  const offs = [];
  const on = (ev, fn) => { const off = game.events?.on?.(ev, fn); if (typeof off === 'function') offs.push(off); };
  on('skilllearn', e => {
    const id = who();
    if (!e || e.reset) { st.tracker.sync(id, skillsNow()); return; }
    if (e.server) { announce(st.tracker.observe(id, skillsNow())); return; }
    const index = localLearn(e, st.tracker.before(id, e.skill?.index));
    st.tracker.sync(id, skillsNow());
    if (index != null) announce([index]);
  });
  on('map', () => { if (!st.tracker.has(who())) st.tracker.sync(who(), skillsNow()); });
  on('network', ({ state } = {}) => { if (['connecting', 'disconnected', 'expired'].includes(state)) st.tracker.reset(); });
  if (game.save) st.tracker.sync(who(), skillsNow());

  API = game.skillMaster = {
    /** queue the Learn Skill popup for a skill index (what a first learn does) */
    show(index) { announce([Number(index)]); return true; },
    /** open the blind with its cut-out over a reference-px rect {x, y, w, h} */
    blind(rect) { return ui.open(WINDOW.blind, rect); },
    closeBlind() { if (ui.isOpen(WINDOW.blind)) ui.close(WINDOW.blind, 'api'); return true; },
    state() { return { queue: [...st.queue], showing: st.showing, shown: [...st.shown], blind: st.blindRect, open: ui.isOpen(WINDOW.master) }; },
    config: C,
    dispose() { for (const off of offs.splice(0)) off(); },
  };
  return API;
}

export function uninstall() { API?.dispose?.(); API = null; }
