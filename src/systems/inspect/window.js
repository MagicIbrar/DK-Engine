// Inspect player window: game2/previewplayer/ui_previewplayerwnd.txt (window "preview", title 2000:16 "Preview").
// pan_screen (328x328) shows the inspected character's current look: its body with the worn equipment / costume,
// its weapons in hand and its wing, standing in its idle pose. btn_left / btn_right turn it (held = keeps turning),
// btn_zoom_out / btn_zoom_in and sld_zoom zoom, btn_ok (2000:15) and btn_exit close.
// Opened from the player menu (target plate -> pcpop) and with /inspect [Name] (src/config/engine-chosen-inspect.js).
import * as THREE from 'three';
import { ModelPreview } from '../mounts/ui-util.js';
import { previewAuraSources } from '../mounts/preview-aura.js';
import { INSPECT_SCRIPT, INSPECT_WINDOW, SLIDER, sliderToZoom, stepSlider, zoomButtons, inspectable, lookSignature, INSPECT_ENGINE_CHOSEN as C } from './rules.js';

/** The wing item whose look the actor shows (own: the mounts system; remote: its shared-mount wing visual). */
export function wingOf(game, actor) {
  try {
    if (actor === game.player) return game.mounts?.system?.wings?.equipped?.() ?? null;
    return actor?._sharedMount?.wings?.equipped?.() ?? null;
  } catch { return null; }
}

/** ModelPreview of ANY player actor (the costume / wing previews only draw your own body). */
export class InspectPreview extends ModelPreview {
  async showActor(actor) {
    const tok = ++this._token;
    const g = this.game, sys = this.sys;
    if (!inspectable(actor) || typeof actor._loadVisuals !== 'function') { this.clear(); return false; }
    // a snapshot of the look: later equipment changes of the actor do not touch this body
    const candidate = Object.create(actor);
    candidate.classDef = actor.classDef;
    candidate.save = { ...actor.save, equipment: structuredClone(actor.save?.equipment || {}) };
    const v = await candidate._loadVisuals();
    if (tok !== this._token || !v?.model) return false;
    const inst = v.model.instantiate();
    const extra = [];
    const idle = actor.anims?.idlePeace || actor.anims?.idle;
    if (idle?.anim) {
      const clip = await g.models.loadClip(idle.anim, v.model, { duration: idle.timeLength || null }).catch(() => null);
      if (clip) { const m = new THREE.AnimationMixer(inst.root); m.clipAction(clip).play(); m.setTime(0.1); }
    }
    // weapons in hand (on foot), as the world draws them
    const d = v.weapon?.def || {}, weaponObjs = [];
    for (const [m, bone] of [[v.weapon?.main, d.bone], [v.weapon?.second, d.boneLeft]]) {
      if (!m || !bone || !inst.getBone?.(bone)) continue;
      const obj = m.instantiate();
      inst.attach(obj, bone);
      weaponObjs.push(obj);
    }
    const wing = wingOf(g, actor);
    const w = wing != null ? sys.data?.wing?.(wing) : null;
    if (w) {
      let wobj = null;
      if (w.table?.skel) {
        const wm = await g.models.loadSkinned({ skelKey: w.table.skel, parts: [{ meshKey: w.asset.mesh, tpackKey: w.asset.tpack || null, textures: w.asset.textures || null }] });
        if (wm) {
          const wi = wm.instantiate(); wobj = wi.root; extra.push(() => wi.dispose());
          const row = sys.data.row?.(w.table, 1, 0, 0);
          if (row) { const c = await g.models.loadClip(row.anim, wm, { duration: row.timeLength }).catch(() => null); if (c) { const mx = new THREE.AnimationMixer(wi.root); mx.clipAction(c).play(); mx.setTime(0.1); } }
        }
      }
      if (!wobj) { const sm = await g.models.loadStatic(w.asset.mesh, { tpackKey: w.asset.tpack || null, textures: w.asset.textures || null, twoSide: true }); if (sm) wobj = sm.instantiate(); }
      if (wobj) { inst.attach(wobj, sys.data.core?.wingBone || 'weaponW'); if (wobj.userData.wingMotion) extra.push(() => wobj.userData.wingMotion.dispose()); }
    }
    const dispose = () => { for (const x of extra) { try { x(); } catch { /* ignore */ } } inst.dispose(); };
    if (tok !== this._token) { dispose(); return false; }
    // aura of the worn gear (refinement tiers, weapon gems): same hues and strengths as in the world (preview-aura.js)
    this.aura = await previewAuraSources(g, candidate, inst, weaponObjs).catch(() => null);
    if (tok !== this._token) { dispose(); return false; }
    this._set(inst.root, dispose);
    return true;
  }
}

/** Register the window. sys = the mounts system (shared data: wings). -> { open(actor), window() }. */
export function registerInspectWindow(game, sys) {
  const mgr = game.uiwin;
  const st = { actor: null, sig: '', acc: 0, win: null };
  const syncZoom = (win) => {
    const sld = win.control('sld_zoom');
    const v = sld.getValue?.() ?? C.zoomStartValue;
    const b = zoomButtons(v);
    win.control('btn_zoom_out').setEnabled(b.out);
    win.control('btn_zoom_in').setEnabled(b.in);
    win.data.preview?.setZoom(sliderToZoom(v));
  };
  const show = (win) => {
    const a = st.actor;
    st.sig = lookSignature(a, wingOf(game, a));
    void win.data.preview.showActor(a).then(ok => { if (ok) win.data.preview.fadeIn(400); }).catch(error => console.warn('[inspect] preview', error));
  };
  mgr.registerWindow(INSPECT_WINDOW, {
    script: INSPECT_SCRIPT, remember: false, escClose: true,
    create(win) {
      st.win = win;
      const screen = win.control('pan_screen');
      if (screen.el?.style) screen.el.style.backgroundColor = C.screenBackdrop;
      const preview = win.data.preview = new InspectPreview(sys, screen, { w: screen.box?.w || 328, h: screen.box?.h || 328 });
      preview.bindButtons(win, { left: 'btn_left', right: 'btn_right', zin: null, zout: null });
      const sld = win.control('sld_zoom');
      sld.setRange?.(SLIDER.min, SLIDER.max);
      sld.on('change', () => syncZoom(win));
      sld.on('commit', () => syncZoom(win));
      win.control('btn_zoom_in').onClick(() => { sld.setValue(stepSlider(sld.getValue(), 1)); syncZoom(win); });
      win.control('btn_zoom_out').onClick(() => { sld.setValue(stepSlider(sld.getValue(), -1)); syncZoom(win); });
      win.control('btn_ok').onClick(() => win.close('ok'));
      win.control('btn_exit').onClick(() => win.close('exit'));
    },
    onOpen(win, arg) {
      st.actor = arg?.actor || st.actor;
      st.acc = 0;
      const p = win.data.preview;
      p.yaw = C.startYaw;
      win.control('sld_zoom').setValue(C.zoomStartValue);
      p.zoom = sliderToZoom(C.zoomStartValue);
      syncZoom(win);
      show(win);
    },
    update(win, dt) {
      win.data.preview?.tick(dt);
      st.acc += dt * 1000;
      if (st.acc < C.refreshMs) return;
      st.acc = 0;
      const a = st.actor;
      if (!inspectable(a)) return;          // left the world: the window keeps the last look
      const sig = lookSignature(a, wingOf(game, a));
      if (sig !== st.sig) show(win);
    },
    onClose(win) { win.data.preview?.clear(); st.actor = null; st.sig = ''; },
  });
  return {
    async open(actor) {
      if (!inspectable(actor)) return false;
      if (mgr.isOpen(INSPECT_WINDOW)) { st.actor = actor; const w = mgr.window(INSPECT_WINDOW); w.data.preview.yaw = C.startYaw; show(w); return true; }
      await mgr.open(INSPECT_WINDOW, { actor });
      return true;
    },
    state: () => ({ actor: st.actor, name: st.actor?.name || null, signature: st.sig, open: mgr.isOpen(INSPECT_WINDOW) }),
    window: () => mgr.window(INSPECT_WINDOW),
  };
}