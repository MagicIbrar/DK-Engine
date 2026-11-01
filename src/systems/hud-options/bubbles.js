// Chat balloons over the speaker's head: script/ui/game2/ui_chatbubble.txt (window chatbubblewnd, layertype bottom).
//   pan_middle  the pcpop#100 frame (imagetable: name.dds 294,34 20x20, nine-slice margins 4,4,4,4) = the whole balloon
//   textbox     at 4,4 inside it: fonttype 2, lineheight 16, colour FFFFFFFF
// The other rows of the same strip colour the frame for the other channels (imagetable comments): 101 light green,
// 102 light purple, 103 red, 104 yellow, 105 sky blue. Normal chat uses the plain frame; party / guild / shout lines
// shown over the speaker get the frame of their channel colour.
// API: ctx.bubbles.show(actor, text, type) (game.chat.bubble(actor, text, type) too); update(dt) every frame.
import * as THREE from 'three';
import { atlas } from '../../ui/atlas.js';
import { applyFont } from '../../ui/uiwin/fonts.js';
import { nameplateHeadGap } from '../../game/nameplate-layout.js';

export const BUBBLE_FRAME = { normal: 100, party: 105, guild: 101, officer: 101, alliance: 104, matching: 102, shout: 103, whisper: 102, world: 104, gm: 104 };
const INSET = 4;          // textbox rect 4 4 (the frame's nine-slice margin)
const LINE_H = 16;        // textbox lineheight
const FONT = 2;           // textbox fonttype
const MAX_TEXT_W = 196;   // wrap width of the balloon text (reference px)
const LIFE = 6;           // seconds on screen
const FADE = 0.4;
const tmp = new THREE.Vector3();

export class ChatBubbles {
  constructor(game) {
    this.game = game;
    this.list = new Map();   // actor -> {el, text, t, w, h}
    this.layer = null;
    this.frames = new Map(); // sprite index -> url
  }

  _layer() {
    if (this.layer?.isConnected) return this.layer;
    const L = document.createElement('div');
    L.className = 'dk-bubbles';
    Object.assign(L.style, { position: 'fixed', left: '0', top: '0', width: '100%', height: '100%', overflow: 'hidden', pointerEvents: 'none' });
    // same stacking context as the name plates (after them: a balloon covers a name behind it)
    const plates = this.game.hud?.els?.plates;
    (plates?.parentNode || document.body).appendChild(L);
    this.layer = L;
    return L;
  }

  _frame(el, index, bubble=null) {
    const url = this.frames.get(index);
    const apply = (u) => {
      el.style.borderStyle = 'solid';
      el.style.borderWidth = `${INSET}px`;
      el.style.borderImage = `url("${u}") ${INSET} fill / ${INSET}px stretch`;
      // The atlas may settle after the first unframed size measurement.
      if(bubble?.el===el)bubble.w=bubble.h=0;
    };
    if (url) { apply(url); return; }
    atlas.sprite('pcpop', index).then(s => {
      const u = s?.url || null;
      if (!u) { if (index !== 100) this._frame(el, 100, bubble); return; }
      this.frames.set(index, u);
      apply(u);
    });
  }

  /** A balloon over `actor` (the player when omitted) saying `text`; type = chat channel (frame colour). */
  show(actor, text, type = 'normal') {
    if (type === 'party') return;
    actor ||= this.game.player;
    const t = String(text ?? '').trim();
    if (!actor || !t || typeof document === 'undefined') return;
    let b = this.list.get(actor);
    if (!b) {
      const el = document.createElement('div');
      Object.assign(el.style, { position: 'absolute', left: '0', top: '0', boxSizing: 'content-box', transformOrigin: '0 0', willChange: 'transform' });
      const tx = document.createElement('div');
      Object.assign(tx.style, { maxWidth: `${MAX_TEXT_W}px`, width: 'max-content', whiteSpace: 'pre-wrap', wordBreak: 'break-word', color: '#ffffff', textAlign: 'left' });
      applyFont(tx, FONT, LINE_H);
      el.appendChild(tx);
      this._layer().appendChild(el);
      b = { el, tx };
      this.list.set(actor, b);
    }
    b.type = type;
    this._frame(b.el, BUBBLE_FRAME[type] || 100, b);
    b.tx.textContent = t;
    b.t = 0;
    b.w = b.h = 0;   // measured on the next update
    b.plateMeasureAt = 0;   // the lifetime/cache clock restarts with new speech
    b.el.style.opacity = '1';
    b.el.style.display = '';
  }

  clear(actor) {
    const b = this.list.get(actor);
    if (!b) return;
    b.el.remove();
    this.list.delete(actor);
  }

  update(dt) {
    if (!this.list.size) return;
    const g = this.game, cam = g.camera;
    const c = g.canvas;
    const hud=g.hud;
    const hudProjection=typeof hud?._screen==='function'&&Number.isFinite(hud._vw)&&Number.isFinite(hud._vh);
    // The HUD already caches the canvas rect for this frame. Reuse its exact
    // head projection so speech and names keep the same viewport anchor.
    const rect=hudProjection?null:c?.getBoundingClientRect?.();
    const W = rect?.width || c?.clientWidth || globalThis.innerWidth || 1024, H = rect?.height || c?.clientHeight || globalThis.innerHeight || 768;
    cam?.updateWorldMatrix?.(true,false);
    const s = Number(g.uiwin?.scale) || 1;
    for (const [a, b] of this.list) {
      b.t += dt;
      const gone = b.t >= LIFE || a.dead || a.disposed || (a.group && a.group.parent === null);
      if (gone) { this.clear(a); continue; }
      if (!cam) continue;
      const point=b.point||(b.point={x:0,y:0});
      let projected;
      if(hudProjection)projected=hud._screen(a,point);
      else{
        let v = null;
        try { v = a.headWorldPosition ? a.headWorldPosition(tmp) : null; } catch { v = null; }
        if (!v) v = tmp.set(a.x || 0, (a.y || 0) + (a.height || 2), -(a.z || 0));
        v.project(cam);
        if(v.z<=1&&v.z>=-1){point.x=(rect?.left||0)+(v.x+1)*0.5*W;point.y=(rect?.top||0)+(1-v.y)*0.5*H;projected=point;}
      }
      if (!projected || (a.group && a.group.visible === false)) { b.el.style.display = 'none'; continue; }
      if (b.el.style.display === 'none') b.el.style.display = '';
      if (!b.w) { b.w = b.el.offsetWidth; b.h = b.el.offsetHeight; }
      // Anchor above the actual nameplate height, including guild crest/title lines.
      // Cache the measurement briefly so speech does not force layout every frame.
      const hx = point.x, hy = point.y;
      const plate = hud?._plates?.get(a);
      const visiblePlate = plate && !plate.hidden && plate.el?.isConnected;
      if (visiblePlate && (b.plate !== plate || b.plateMeasureAt <= b.t)) {
        b.plate = plate;
        b.plateHeight = plate.el.offsetHeight;
        b.plateMeasureAt = b.t + 0.25;
      }
      const clearance = visiblePlate ? (plate.headGap??nameplateHeadGap(a)) + (b.plateHeight || 18) + 6 : 26 * s;
      const x = Math.round(hx - (b.w * s) / 2), y = Math.round(hy - clearance - b.h * s);
      b.el.style.transform = `translate(${x}px, ${y}px)${s !== 1 ? ` scale(${s})` : ''}`;
      const left = LIFE - b.t;
      b.el.style.opacity = left < FADE ? (left / FADE).toFixed(2) : '1';
    }
  }

  dispose() {
    for (const a of [...this.list.keys()]) this.clear(a);
    this.layer?.remove();
    this.layer = null;
  }
}
