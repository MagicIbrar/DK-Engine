// Screenshot key (key map 901, F12 by default): saves the current view as a JPEG file, named like the client's
// ScreenShot folder files (Dekaron_YYYYMMDD_HHMMSS.jpg), and reports it in the system chat, as the client does.
// The 3D view is rendered once more and read back in the same task (the WebGL canvas keeps no drawing buffer).
// The interface is DOM over the canvas, so it is painted on top by walking the visible elements in stacking order:
// sprite backgrounds (with background position/size: damage digits), nine-slice border images, canvases (item
// renders), rotated sprites (minimap arrows), text runs (font, colour, 1-px shadow), opacity and overflow clipping.
export async function takeScreenshot(game, ctx) {
  const r = game.renderer;
  if (!r) return;
  try { r.render(game.scene, game.camera); } catch { /* keep the last frame */ }
  const src = r.domElement;
  const W = innerWidth, H = innerHeight;
  const cv = document.createElement('canvas');
  cv.width = W; cv.height = H;
  const g = cv.getContext('2d');
  const sr = src.getBoundingClientRect();
  g.filter = getComputedStyle(src).filter || 'none';
  g.drawImage(src, sr.left, sr.top, sr.width, sr.height);
  g.filter = 'none';
  try { await paintDom(g, game, src); } catch (err) { console.warn('[hud-options] screenshot UI', err); }
  const pad = n => String(n).padStart(2, '0');
  const d = new Date();
  const name = `Dekaron_${d.getFullYear()}${pad(d.getMonth() + 1)}${pad(d.getDate())}_${pad(d.getHours())}${pad(d.getMinutes())}${pad(d.getSeconds())}.jpg`;
  return new Promise((resolve) => cv.toBlob((blob) => {
    if (!blob) { resolve(null); return; }
    const a = document.createElement('a');
    a.href = URL.createObjectURL(blob); a.download = name;
    document.body.appendChild(a); a.click(); a.remove();
    setTimeout(() => URL.revokeObjectURL(a.href), 3000);
    ctx.chat?.system(`ScreenShot\\${name}`);
    resolve({ name, blob, canvas: cv });
  }, 'image/jpeg', 0.92));
}

// ------------------------------------------------------------------------------------------ DOM painter
const imgCache = new Map();
function loadImage(url) {
  if (!imgCache.has(url)) {
    imgCache.set(url, new Promise(res => { const im = new Image(); im.onload = () => res(im); im.onerror = () => res(null); im.src = url; }));
    if (imgCache.size > 400) imgCache.delete(imgCache.keys().next().value);
  }
  return imgCache.get(url);
}
const urlOf = (v) => { const m = /url\("?([^")]+)"?\)/.exec(v || ''); return m ? m[1] : null; };
const px = (v) => parseFloat(v) || 0;

async function paintDom(g, game, canvasEl) {
  const root = game.ui || document.body;
  const tops = [...root.children].filter(el => el !== canvasEl && !el.contains(canvasEl));
  // the canvas' own container may hold overlays too (siblings after it)
  for (const el of sortByZ(tops)) await paintEl(g, el, 1);
}

function sortByZ(list) {
  return list.map((el, i) => ({ el, i, z: Number(getComputedStyle(el).zIndex) || 0 }))
    .sort((a, b) => (a.z - b.z) || (a.i - b.i)).map(x => x.el);
}

async function paintEl(g, el, parentAlpha) {
  if (!(el instanceof HTMLElement) && !(el instanceof SVGElement)) return;
  if (el.tagName === 'SCRIPT' || el.tagName === 'STYLE' || el.tagName === 'A') return;
  const cs = getComputedStyle(el);
  if (cs.display === 'none' || cs.visibility === 'hidden') return;
  const alpha = parentAlpha * (Number(cs.opacity) || 0);
  if (alpha <= 0.004) return;
  const rc = el.getBoundingClientRect();
  if (rc.right < 0 || rc.bottom < 0 || rc.left > innerWidth || rc.top > innerHeight) {
    if (cs.overflow === 'hidden') return;          // clipped away entirely
  }
  g.save();
  g.globalAlpha = alpha;
  // own rotation (minimap arrows / camera radar): draw in the element's rotated frame
  const m = cs.transform && cs.transform !== 'none' ? new DOMMatrixReadOnly(cs.transform) : null;
  const ang = m ? Math.atan2(m.b, m.a) : 0;
  let box = { x: rc.left, y: rc.top, w: rc.width, h: rc.height };
  const ow = el.offsetWidth || rc.width, oh = el.offsetHeight || rc.height;
  if (Math.abs(ang) > 0.001 && ow && oh) {
    const k = Math.hypot(m.a, m.b) * layerScale(el);
    const w = ow * k, h = oh * k;
    g.translate(rc.left + rc.width / 2, rc.top + rc.height / 2);
    g.rotate(ang);
    box = { x: -w / 2, y: -h / 2, w, h };
  }
  const sx = ow ? box.w / ow : 1, sy = oh ? box.h / oh : 1;
  if (box.w >= 1 && box.h >= 1) {
    // nine-slice border image
    const bi = urlOf(cs.borderImageSource);
    if (bi) {
      const im = await loadImage(bi);
      if (im) nine(g, im, cs, box, sx, sy);
    }
    // background image (sprite / digit sheet)
    const bg = urlOf(cs.backgroundImage);
    if (bg) {
      const im = await loadImage(bg);
      if (im) {
        const [bw, bh] = bgSize(cs.backgroundSize, im, ow, oh);
        const [bx, by] = String(cs.backgroundPosition || '0px 0px').split(' ').map((v, i) => (v.endsWith('%') ? (px(v) / 100) * ((i ? oh : ow) - (i ? bh : bw)) : px(v)));
        g.save();
        g.beginPath(); g.rect(box.x, box.y, box.w, box.h); g.clip();
        g.drawImage(im, box.x + bx * sx, box.y + (by || 0) * sy, bw * sx, bh * sy);
        g.restore();
      }
    } else if (cs.backgroundColor && !/rgba\(0, 0, 0, 0\)|transparent/.test(cs.backgroundColor)) {
      g.fillStyle = cs.backgroundColor;
      g.fillRect(box.x, box.y, box.w, box.h);
    }
    if (el.tagName === 'CANVAS' && el.width && el.height) { try { g.drawImage(el, box.x, box.y, box.w, box.h); } catch { /* tainted */ } }
    if (el.tagName === 'IMG' && el.complete && el.naturalWidth) g.drawImage(el, box.x, box.y, box.w, box.h);
  }
  // clip the children to this box when it hides overflow
  if (cs.overflow === 'hidden' || cs.overflowX === 'hidden' || cs.overflow === 'clip') { g.beginPath(); g.rect(box.x, box.y, box.w, box.h); g.clip(); }
  if (Math.abs(ang) > 0.001) { g.restore(); g.save(); g.globalAlpha = alpha; }
  // text of this element (direct text nodes; inputs show their value)
  if (el.tagName === 'INPUT' || el.tagName === 'TEXTAREA') {
    if (el.value && el.type !== 'password') drawText(g, el.value, cs, rc.left + px(cs.paddingLeft) * sx, rc.top + (rc.height - px(cs.fontSize) * sy) / 2, sy);
  } else {
    for (const n of el.childNodes) if (n.nodeType === 3 && n.textContent.trim()) drawTextNode(g, n, cs, sy);
  }
  const kids = sortByZ([...el.children]);
  for (const k of kids) await paintEl(g, k, alpha);
  g.restore();
}

function layerScale(el) {
  const p = el.parentElement;
  if (!p || !p.offsetWidth) return 1;
  return p.getBoundingClientRect().width / p.offsetWidth;
}

function bgSize(v, im, w, h) {
  const parts = String(v || 'auto').split(' ');
  const one = (s, full, nat) => (s.endsWith('%') ? (px(s) / 100) * full : s === 'auto' ? nat : px(s));
  if (parts[0] === 'cover' || parts[0] === 'contain') {
    const k = parts[0] === 'cover' ? Math.max(w / im.width, h / im.height) : Math.min(w / im.width, h / im.height);
    return [im.width * k, im.height * k];
  }
  const bw = one(parts[0], w, im.width);
  const bh = parts[1] ? one(parts[1], h, im.height) : (parts[0] === 'auto' ? im.height : bw * (im.height / im.width));
  return [bw, bh];
}

function nine(g, im, cs, box, sx, sy) {
  const sl = String(cs.borderImageSlice || '0').split(/\s+/).filter(s => s !== 'fill').map(px);
  const [t, r = t, b = t, l = r] = sl;
  const bt = px(cs.borderTopWidth) * sy, br = px(cs.borderRightWidth) * sx, bb = px(cs.borderBottomWidth) * sy, bl = px(cs.borderLeftWidth) * sx;
  const W = im.width, H = im.height;
  const sxs = [0, l, W - r, W], sys = [0, t, H - b, H];
  const dxs = [box.x, box.x + bl, box.x + box.w - br, box.x + box.w], dys = [box.y, box.y + bt, box.y + box.h - bb, box.y + box.h];
  for (let j = 0; j < 3; j++) for (let i = 0; i < 3; i++) {
    const sw = sxs[i + 1] - sxs[i], shh = sys[j + 1] - sys[j], dw = dxs[i + 1] - dxs[i], dh = dys[j + 1] - dys[j];
    if (sw > 0 && shh > 0 && dw > 0 && dh > 0) g.drawImage(im, sxs[i], sys[j], sw, shh, dxs[i], dys[j], dw, dh);
  }
}

function drawTextNode(g, node, cs, sy) {
  const range = document.createRange();
  range.selectNodeContents(node);
  const rects = [...range.getClientRects()].filter(r => r.width > 0);
  if (!rects.length) return;
  const text = node.textContent;
  if (rects.length === 1) { drawText(g, text.replace(/\s+/g, ' ').trim() ? text : '', cs, rects[0].left, rects[0].top, sy, rects[0].height); return; }
  // wrapped: group the characters by line box
  let line = '', top = null, left = 0, hgt = 0;
  for (let i = 0; i < text.length; i++) {
    range.setStart(node, i); range.setEnd(node, i + 1);
    const r = range.getClientRects()[0];
    if (!r) { line += text[i]; continue; }
    if (top === null || Math.abs(r.top - top) > 2) {
      if (line.trim()) drawText(g, line, cs, left, top, sy, hgt);
      line = ''; top = r.top; left = r.left; hgt = r.height;
    }
    line += text[i];
  }
  if (line.trim()) drawText(g, line, cs, left, top, sy, hgt);
}

function drawText(g, text, cs, x, y, sy, lineH = 0) {
  if (!text) return;
  const size = px(cs.fontSize) * sy;
  g.font = `${cs.fontStyle} ${cs.fontWeight} ${size}px ${cs.fontFamily}`;
  g.textBaseline = 'middle';
  const cy = y + (lineH ? lineH / 2 : size / 2);
  const t = text.replace(/\s+$/g, '');
  if (cs.textShadow && cs.textShadow !== 'none') {
    const sm = /(rgba?\([^)]*\)|#[0-9a-f]+|black)?\s*(-?[\d.]+)px\s+(-?[\d.]+)px/i.exec(cs.textShadow);
    g.fillStyle = sm?.[1] || '#000';
    g.fillText(t, x + (sm ? px(sm[2]) * sy : 1), cy + (sm ? px(sm[3]) * sy : 1));
  }
  g.fillStyle = cs.color;
  g.fillText(t, x, cy);
}
