// Pure CPU texture operations shared by the asset workers and fallback path.
// ------------------------------------------------------------------------------------------ alpha analysis
// Thresholds on 0..255 alpha: <= LO counts as "transparent", >= HI as "opaque"; anything between is "smooth".
const A_LO = 8, A_HI = 247;

export function classifyCounts(transparent, mid, total) {
  if (!total || (!transparent && !mid)) return { hasAlpha: false, alphaKind: 'none', alphaFraction: 0 };
  // a handful of in-between texels at cut-out edges (DXT5 hair) still reads as a cut-out
  const kind = mid > Math.max(16, total * 0.002) ? 'smooth' : 'binary';
  return { hasAlpha: true, alphaKind: kind, alphaFraction: (transparent + mid) / total };
}

/** Alpha statistics of RGBA8 pixels (every 4th byte). */
export function analyseRGBA(data) {
  let lo = 0, mid = 0;
  const n = data.length >> 2;
  for (let i = 3; i < data.length; i += 4) {
    const a = data[i];
    if (a >= A_HI) continue;
    if (a <= A_LO) lo++; else mid++;
  }
  return classifyCounts(lo, mid, n);
}

const _apal = new Uint8Array(8);
/** Alpha statistics straight from the compressed level-0 blocks (no colour decode). */
export function analyseDDSAlpha(dds) {
  const lvl = dds.mipmaps[0];
  if (!lvl) return classifyCounts(0, 0, 0);
  const src = lvl.data;
  if (dds.format === 'DXT1') {
    return dds.punchThrough ? { hasAlpha: true, alphaKind: 'binary', alphaFraction: null } : classifyCounts(0, 0, 1);
  }
  let lo = 0, mid = 0, total = 0;
  if (dds.format === 'DXT3' || dds.format === 'DXT2') {
    for (let o = 0; o + 16 <= src.length; o += 16) {
      for (let i = 0; i < 8; i++) {
        const v = src[o + i];
        if (v === 0xff) continue;                    // both texels opaque (nibble 15 = 255)
        const n0 = v & 15, n1 = v >> 4;              // nibble * 17: 0 -> transparent, 15 -> opaque, else smooth
        if (n0 === 0) lo++; else if (n0 !== 15) mid++;
        if (n1 === 0) lo++; else if (n1 !== 15) mid++;
      }
      total += 16;
    }
    return classifyCounts(lo, mid, total);
  }
  if (dds.format === 'DXT5' || dds.format === 'DXT4') {
    for (let o = 0; o + 16 <= src.length; o += 16) {
      const a0 = src[o], a1 = src[o + 1];
      total += 16;
      if (a0 > a1 && a1 >= A_HI) continue;           // every interpolated value >= a1: fully opaque block
      _apal[0] = a0; _apal[1] = a1;
      if (a0 > a1) for (let i = 1; i < 7; i++) _apal[i + 1] = ((7 - i) * a0 + i * a1 + 3) / 7 | 0;
      else { for (let i = 1; i < 5; i++) _apal[i + 1] = ((5 - i) * a0 + i * a1 + 2) / 5 | 0; _apal[6] = 0; _apal[7] = 255; }
      const lo24 = src[o + 2] | (src[o + 3] << 8) | (src[o + 4] << 16);
      const hi24 = src[o + 5] | (src[o + 6] << 8) | (src[o + 7] << 16);
      for (let i = 0; i < 16; i++) {
        const idx = i < 8 ? (lo24 >> (i * 3)) & 7 : (hi24 >> ((i - 8) * 3)) & 7;
        const a = _apal[idx];
        if (a >= A_HI) continue;
        if (a <= A_LO) lo++; else mid++;
      }
    }
    return classifyCounts(lo, mid, total);
  }
  return null; // uncompressed: analysed on the decoded RGBA
}

// ------------------------------------------------------------------------------------------ mip generation
/**
 * 2x2 box filter of an RGBA8 image (odd sizes clamp). Colour is weighted by alpha, so fully transparent texels (the
 * black behind DXT1 punch-through) do not darken the edge of cut-outs; alpha is the plain average.
 */
export function downsampleRGBA(src, w, h) {
  const nw = Math.max(1, w >> 1), nh = Math.max(1, h >> 1);
  const out = new Uint8Array(nw * nh * 4);
  for (let y = 0; y < nh; y++) {
    const y0 = Math.min(2 * y, h - 1), y1 = Math.min(2 * y + 1, h - 1);
    for (let x = 0; x < nw; x++) {
      const x0 = Math.min(2 * x, w - 1), x1 = Math.min(2 * x + 1, w - 1);
      const i0 = (y0 * w + x0) * 4, i1 = (y0 * w + x1) * 4, i2 = (y1 * w + x0) * 4, i3 = (y1 * w + x1) * 4;
      const a0 = src[i0 + 3], a1 = src[i1 + 3], a2 = src[i2 + 3], a3 = src[i3 + 3];
      const sa = a0 + a1 + a2 + a3;
      const o = (y * nw + x) * 4;
      if (sa > 0 && sa < 1020) {
        for (let c = 0; c < 3; c++) {
          out[o + c] = (src[i0 + c] * a0 + src[i1 + c] * a1 + src[i2 + c] * a2 + src[i3 + c] * a3 + (sa >> 1)) / sa | 0;
        }
      } else {
        for (let c = 0; c < 3; c++) out[o + c] = (src[i0 + c] + src[i1 + c] + src[i2 + c] + src[i3 + c] + 2) >> 2;
      }
      out[o + 3] = (sa + 2) >> 2;
    }
  }
  return { data: out, width: nw, height: nh };
}

/** Full RGBA mip chain [level0, level1, ... 1x1] (level 0 = the given image). */
export function rgbaMipChain(img) {
  const chain = [{ data: img.data, width: img.width, height: img.height }];
  let cur = chain[0];
  while (cur.width > 1 || cur.height > 1) {
    cur = downsampleRGBA(cur.data, cur.width, cur.height);
    chain.push(cur);
  }
  return chain;
}

// ---- DXT block encoder (fast bounding-box + diagonal selection + inset, nearest palette index). Quality is ample for
//      mip levels 1+ (level 0 always stays the file's own data).
const _blk = new Uint8Array(64);
const _pal = new Int32Array(12);

function loadBlock(img, bx, by) {
  const { data, width: w, height: h } = img;
  for (let py = 0; py < 4; py++) {
    const y = Math.min(by * 4 + py, h - 1);
    for (let px = 0; px < 4; px++) {
      const x = Math.min(bx * 4 + px, w - 1);
      const s = (y * w + x) * 4, d = (py * 4 + px) * 4;
      _blk[d] = data[s]; _blk[d + 1] = data[s + 1]; _blk[d + 2] = data[s + 2]; _blk[d + 3] = data[s + 3];
    }
  }
}

const clamp255 = v => (v < 0 ? 0 : v > 255 ? 255 : v);
function pack565(r, g, b) {
  return ((Math.round(clamp255(r) * 31 / 255) << 11) | (Math.round(clamp255(g) * 63 / 255) << 5) | Math.round(clamp255(b) * 31 / 255)) >>> 0;
}
function expand565(c, out, o) {
  const r = c >> 11, g = (c >> 5) & 63, b = c & 31;
  out[o] = (r << 3) | (r >> 2); out[o + 1] = (g << 2) | (g >> 4); out[o + 2] = (b << 3) | (b >> 2);
}

// Selector state of the last assign() call (per texel palette entry, 3 = transparent) and its result.
const _sel = new Uint8Array(16), _bestSel = new Uint8Array(16);
const _opaque = new Uint8Array(16);
let _aC0 = 0, _aC1 = 0, _aErr = 0;

/** Order the endpoints for the mode, build the decoder's palette, pick the nearest entry per texel. */
function assignColors(c0, c1, three) {
  if (three ? c0 > c1 : c0 < c1) { const t = c0; c0 = c1; c1 = t; }
  expand565(c0, _pal, 0); expand565(c1, _pal, 3);
  let entries = 4;
  if (!three && c0 === c1) entries = 1;                  // decoder would switch to 3-colour mode: use entry 0 only
  else if (three) {
    for (let c = 0; c < 3; c++) _pal[6 + c] = (_pal[c] + _pal[3 + c] + 1) >> 1;
    entries = 3;
  } else {
    for (let c = 0; c < 3; c++) {
      _pal[6 + c] = (2 * _pal[c] + _pal[3 + c] + 1) / 3 | 0;
      _pal[9 + c] = (_pal[c] + 2 * _pal[3 + c] + 1) / 3 | 0;
    }
  }
  let err = 0;
  for (let i = 0; i < 16; i++) {
    if (!_opaque[i]) { _sel[i] = 3; continue; }
    const d = i * 4;
    let best = 0, bd = Infinity;
    for (let e = 0; e < entries; e++) {
      const dr = _blk[d] - _pal[e * 3], dg = _blk[d + 1] - _pal[e * 3 + 1], db = _blk[d + 2] - _pal[e * 3 + 2];
      const dist = dr * dr + dg * dg + db * db;
      if (dist < bd) { bd = dist; best = e; }
    }
    _sel[i] = best; err += bd;
  }
  _aC0 = c0; _aC1 = c1; _aErr = err;
}

const W4 = [1, 0, 2 / 3, 1 / 3], W3 = [1, 0, 0.5];
const _ls = new Float64Array(6);
/** Least-squares endpoints for the current selectors (stb_dxt RefineBlock). Returns false when singular. */
function refineEndpoints(three) {
  const W = three ? W3 : W4;
  let aa = 0, bb = 0, ab = 0, atR = 0, atG = 0, atB = 0, btR = 0, btG = 0, btB = 0;
  for (let i = 0; i < 16; i++) {
    if (!_opaque[i]) continue;
    const w = W[_sel[i]] ?? 0, v = 1 - w, d = i * 4;
    aa += w * w; bb += v * v; ab += w * v;
    atR += w * _blk[d]; atG += w * _blk[d + 1]; atB += w * _blk[d + 2];
    btR += v * _blk[d]; btG += v * _blk[d + 1]; btB += v * _blk[d + 2];
  }
  const det = aa * bb - ab * ab;
  if (Math.abs(det) < 1e-9) return false;
  const f = 1 / det;
  _ls[0] = (atR * bb - btR * ab) * f; _ls[1] = (atG * bb - btG * ab) * f; _ls[2] = (atB * bb - btB * ab) * f;
  _ls[3] = (btR * aa - atR * ab) * f; _ls[4] = (btG * aa - atG * ab) * f; _ls[5] = (btB * aa - atB * ab) * f;
  return true;
}

/**
 * Encode _blk's colour into 8 bytes at out[o]: endpoints from the principal axis of the block's colours (power
 * iteration on the covariance), then two least-squares refinement passes (stb_dxt method).
 * punch: DXT1 1-bit alpha (texels with alpha < 128 -> index 3 of the three-colour mode). Without punch the block is
 * always four-colour (c0 > c1), which DXT3/5 require.
 */
function encodeColorBlock(out, o, punch) {
  let n = 0, mr = 0, mg = 0, mb = 0;
  for (let i = 0; i < 16; i++) {
    const d = i * 4;
    _opaque[i] = punch && _blk[d + 3] < 128 ? 0 : 1;
    if (!_opaque[i]) continue;
    mr += _blk[d]; mg += _blk[d + 1]; mb += _blk[d + 2]; n++;
  }
  if (!n) {                                              // all transparent: c0 == c1 (three-colour mode), index 3
    out[o] = out[o + 1] = out[o + 2] = out[o + 3] = 0;
    out[o + 4] = out[o + 5] = out[o + 6] = out[o + 7] = 0xff;
    return;
  }
  const three = n < 16;
  mr /= n; mg /= n; mb /= n;
  let crr = 0, cgg = 0, cbb = 0, crg = 0, crb = 0, cgb = 0;
  let minR = 255, minG = 255, minB = 255, maxR = 0, maxG = 0, maxB = 0;
  for (let i = 0; i < 16; i++) {
    if (!_opaque[i]) continue;
    const d = i * 4, r = _blk[d] - mr, g = _blk[d + 1] - mg, b = _blk[d + 2] - mb;
    crr += r * r; cgg += g * g; cbb += b * b; crg += r * g; crb += r * b; cgb += g * b;
    if (_blk[d] < minR) minR = _blk[d]; if (_blk[d] > maxR) maxR = _blk[d];
    if (_blk[d + 1] < minG) minG = _blk[d + 1]; if (_blk[d + 1] > maxG) maxG = _blk[d + 1];
    if (_blk[d + 2] < minB) minB = _blk[d + 2]; if (_blk[d + 2] > maxB) maxB = _blk[d + 2];
  }
  // principal axis by power iteration, seeded with the bounding-box diagonal
  let vr = maxR - minR, vg = maxG - minG, vb = maxB - minB;
  if (vr === 0 && vg === 0 && vb === 0) { vr = 1; vg = 1; vb = 1; }
  for (let it = 0; it < 4; it++) {
    const r = vr * crr + vg * crg + vb * crb, g = vr * crg + vg * cgg + vb * cgb, b = vr * crb + vg * cgb + vb * cbb;
    const l = Math.max(Math.abs(r), Math.abs(g), Math.abs(b));
    if (l < 1e-6) break;
    vr = r / l; vg = g / l; vb = b / l;
  }
  // endpoints = the extreme texels along the axis
  let dmin = Infinity, dmax = -Infinity, imin = 0, imax = 0;
  for (let i = 0; i < 16; i++) {
    if (!_opaque[i]) continue;
    const d = i * 4, p = _blk[d] * vr + _blk[d + 1] * vg + _blk[d + 2] * vb;
    if (p < dmin) { dmin = p; imin = i; }
    if (p > dmax) { dmax = p; imax = i; }
  }
  let c0 = pack565(_blk[imax * 4], _blk[imax * 4 + 1], _blk[imax * 4 + 2]);
  let c1 = pack565(_blk[imin * 4], _blk[imin * 4 + 1], _blk[imin * 4 + 2]);
  assignColors(c0, c1, three);
  let bestC0 = _aC0, bestC1 = _aC1, bestErr = _aErr;
  _bestSel.set(_sel);
  for (let pass = 0; pass < 2 && bestErr > 0; pass++) {
    if (!refineEndpoints(three)) break;
    c0 = pack565(_ls[0], _ls[1], _ls[2]); c1 = pack565(_ls[3], _ls[4], _ls[5]);
    assignColors(c0, c1, three);
    if (_aErr >= bestErr) break;
    bestC0 = _aC0; bestC1 = _aC1; bestErr = _aErr; _bestSel.set(_sel);
  }
  out[o] = bestC0 & 255; out[o + 1] = bestC0 >> 8; out[o + 2] = bestC1 & 255; out[o + 3] = bestC1 >> 8;
  let idx = 0;
  for (let i = 15; i >= 0; i--) idx = ((idx << 2) | _bestSel[i]) >>> 0;
  out[o + 4] = idx & 255; out[o + 5] = (idx >>> 8) & 255; out[o + 6] = (idx >>> 16) & 255; out[o + 7] = idx >>> 24;
}

function encodeAlphaDXT3(out, o) {
  for (let i = 0; i < 8; i++) {
    const a0 = (_blk[i * 8 + 3] * 15 + 127) / 255 | 0, a1 = (_blk[i * 8 + 7] * 15 + 127) / 255 | 0;
    out[o + i] = a0 | (a1 << 4);
  }
}

const _apal5 = new Int32Array(8);
function encodeAlphaDXT5(out, o) {
  let amin = 255, amax = 0;
  for (let i = 0; i < 16; i++) { const a = _blk[i * 4 + 3]; if (a < amin) amin = a; if (a > amax) amax = a; }
  out[o] = amax; out[o + 1] = amin;
  if (amax === amin) { for (let i = 2; i < 8; i++) out[o + i] = 0; return; }
  _apal5[0] = amax; _apal5[1] = amin;
  for (let i = 1; i < 7; i++) _apal5[i + 1] = ((7 - i) * amax + i * amin + 3) / 7 | 0;
  let lo = 0, hi = 0;
  for (let i = 0; i < 16; i++) {
    const a = _blk[i * 4 + 3];
    let best = 0, bd = 1e9;
    for (let e = 0; e < 8; e++) { const dd = Math.abs(a - _apal5[e]); if (dd < bd) { bd = dd; best = e; } }
    if (i < 8) lo |= best << (i * 3); else hi |= best << ((i - 8) * 3);
  }
  out[o + 2] = lo & 255; out[o + 3] = (lo >> 8) & 255; out[o + 4] = (lo >> 16) & 255;
  out[o + 5] = hi & 255; out[o + 6] = (hi >> 8) & 255; out[o + 7] = (hi >> 16) & 255;
}

/** Encode one RGBA8 image to DXT1 / DXT3 / DXT5 blocks. */
export function encodeDXT(format, img, { punch = false } = {}) {
  const bw = Math.max(1, (img.width + 3) >> 2), bh = Math.max(1, (img.height + 3) >> 2);
  const bb = format === 'DXT1' ? 8 : 16;
  const out = new Uint8Array(bw * bh * bb);
  for (let by = 0; by < bh; by++) {
    for (let bx = 0; bx < bw; bx++) {
      loadBlock(img, bx, by);
      const o = (by * bw + bx) * bb;
      if (format === 'DXT1') encodeColorBlock(out, o, punch);
      else {
        if (format === 'DXT3') encodeAlphaDXT3(out, o); else encodeAlphaDXT5(out, o);
        encodeColorBlock(out, o + 8, false);
      }
    }
  }
  return out;
}

/**
 * Mip levels 1..(1x1) for a DXT texture whose file has level 0 only: box-filter the decoded level 0 and re-encode each
 * level in the same format (what D3DX does on load).
 * @param {'DXT1'|'DXT3'|'DXT5'} format
 * @param {{data:Uint8Array,width:number,height:number}} rgba0  decoded level 0
 * @returns {{data:Uint8Array,width:number,height:number}[]}
 */
export function encodeDXTMips(format, rgba0, { punch = false } = {}) {
  const chain = rgbaMipChain(rgba0);
  return chain.slice(1).map(l => ({ data: encodeDXT(format, l, { punch }), width: l.width, height: l.height }));
}

export const ENCODABLE = new Set(['DXT1', 'DXT3', 'DXT5']);

