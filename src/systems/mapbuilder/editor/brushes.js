// Terrain / tile / water / collision brushes. Called from editor.js's pointer loop: beginStroke() on pointerdown,
// applyAt(x, z, dt) every frame the button is held over the ground, endStroke() on pointerup (pushes one undo entry
// covering the whole stroke). x, z are FILE coordinates (float); radius is in cells.
//
// Undo: every per-vertex/per-cell array write captures the ORIGINAL value the first time a stroke touches that
// index (lazily, into a small Map - proportional to the brush footprint, not the whole map). On pointerup the
// current ("after") value of every captured index is read back and one history entry restores either side.
const smooth = (t) => t * t * (3 - 2 * t); // 0..1 falloff, 1 at the brush centre
export function brushFalloff(distance, radius, mode = 'smooth') {
  if (!(radius > 0) || distance > radius) return 0;
  const t = Math.max(0, Math.min(1, 1 - distance / radius));
  if (mode === 'hard') return 1;
  if (mode === 'linear') return t;
  if (mode === 'soft') return t * t;
  return smooth(t);
}

export class Brushes {
  constructor(editor) {
    this.ed = editor;
    this._stroke = null;
  }

  beginStroke(tool, x, z, opts = {}) {
    const doc = this.ed.doc;
    this._stroke = {
      tool, opts, seen: new Set(),
      orig: {}, // field -> Map(index -> original scalar | [tuple])
      dirty: { x0: Infinity, z0: Infinity, x1: -Infinity, z1: -Infinity },
      touchedFields: new Set(), // which doc.* arrays this stroke wrote to (for the post-refresh)
      flattenHeight: doc.heightAt(x, z),
    };
  }

  _expandDirty(x0, z0, x1, z1) {
    const d = this._stroke.dirty;
    d.x0 = Math.min(d.x0, x0); d.z0 = Math.min(d.z0, z0); d.x1 = Math.max(d.x1, x1); d.z1 = Math.max(d.z1, z1);
  }

  /** Capture doc[field][idx] the first time this stroke touches it, then write `value`. */
  _write(field, idx, value) {
    const s = this._stroke, doc = this.ed.doc;
    if(this.ed.originalLive?.allowsWrite&&!this.ed.originalLive.allowsWrite(field,idx))return;
    let m = s.orig[field]; if (!m) m = s.orig[field] = new Map();
    if (!m.has(idx)) m.set(idx, doc[field][idx]);
    doc[field][idx] = value;
    s.touchedFields.add(field);
  }
  /** Same, for the 4-channel colour array (captures/writes a whole RGBA tuple by vertex index). */
  _writeColor(idx, r, g, b) {
    const s = this._stroke, doc = this.ed.doc;
    const base = idx * 4;
    if(this.ed.originalLive?.allowsWrite&&![0,1,2,3].every(c=>this.ed.originalLive.allowsWrite('colors',base+c)))return;
    let m = s.orig.colors; if (!m) m = s.orig.colors = new Map();
    if (!m.has(idx)) m.set(idx, [doc.colors[base], doc.colors[base + 1], doc.colors[base + 2], doc.colors[base + 3]]);
    doc.colors[base] = r; doc.colors[base + 1] = g; doc.colors[base + 2] = b;
    s.touchedFields.add('colors');
  }
  /** Same, for water (def index + level, captured/written together by cell index). */
  _writeWater(idx, def, h) {
    const s = this._stroke, doc = this.ed.doc;
    if(this.ed.originalLive?.allowsWrite&&(!this.ed.originalLive.allowsWrite('waterDef',idx)||!this.ed.originalLive.allowsWrite('waterH',idx)))return;
    let m = s.orig.water; if (!m) m = s.orig.water = new Map();
    if (!m.has(idx)) m.set(idx, [doc.waterDef[idx], doc.waterH[idx]]);
    doc.waterDef[idx] = def; doc.waterH[idx] = h;
    s.touchedFields.add('water');
  }

  applyAt(x, z, dt, opts) {
    if (!this._stroke) return;
    const s = this._stroke;
    // Recheck the active scope even if this stroke began before live entry.
    if(this.ed.originalLive?.active&&Array.isArray(this.ed.originalLive.allowedTools)&&!this.ed.originalLive.allowedTools.includes(s.tool))return;
    const o = { ...s.opts, ...opts };
    const radius = Math.max(0.25, Number(o.radius) || 4);
    switch (s.tool) {
      case 'raise': this._height(x, z, radius, dt * (Number(o.strength) || 3), o); break;
      case 'lower': this._height(x, z, radius, -dt * (Number(o.strength) || 3), o); break;
      case 'smooth': this._smooth(x, z, radius, dt * (Number(o.strength) || 4), o); break;
      case 'flatten': this._flatten(x, z, radius, dt * (Number(o.strength) || 6), o); break;
      case 'noise': this._noise(x, z, radius, Number(o.strength) || 0.6, o); break;
      case 'vcolor': this._vcolor(x, z, radius, dt * (Number(o.strength) || 4), o); break;
      case 'type': this._type(x, z, radius, o); break;
      case 'variant': this._variant(x, z, radius, o); break;
      case 'hole': this._hole(x, z, radius, o); break;
      case 'water': this._water(x, z, radius, o); break;
      case 'collision': this._collision(x, z, radius, o); break;
      default: break;
    }
    if(s.dirty.x1>=s.dirty.x0)this.ed.emit?.('brush:changed',{fields:s.touchedFields,rect:s.dirty});
  }

  /** Finish the stroke: reads the "after" values of every captured index and pushes one undo entry. */
  endStroke() {
    const s = this._stroke;
    this._stroke = null;
    if (!s || s.dirty.x1 < s.dirty.x0) return null;
    const doc = this.ed.doc;
    const after = {};
    for (const field of Object.keys(s.orig)) {
      const m = new Map();
      for (const idx of s.orig[field].keys()) {
        if (field === 'colors') { const b = idx * 4; m.set(idx, [doc.colors[b], doc.colors[b + 1], doc.colors[b + 2], doc.colors[b + 3]]); }
        else if (field === 'water') m.set(idx, [doc.waterDef[idx], doc.waterH[idx]]);
        else m.set(idx, doc[field][idx]);
      }
      after[field] = m;
    }
    const before = s.orig, rect = { ...s.dirty };
    const write = (snapshot) => {
      for (const [idx, v] of snapshot.heights || []) doc.heights[idx] = v;
      for (const [idx, v] of snapshot.colors || []) { const b = idx * 4; doc.colors[b] = v[0]; doc.colors[b + 1] = v[1]; doc.colors[b + 2] = v[2]; doc.colors[b + 3] = v[3]; }
      for (const [idx, v] of snapshot.vertexTypes || []) doc.vertexTypes[idx] = v;
      for (const [idx, v] of snapshot.cellVariants || []) doc.cellVariants[idx] = v;
      for (const [idx, v] of snapshot.holes || []) doc.holes[idx] = v;
      for (const [idx, v] of snapshot.attrs || []) doc.attrs[idx] = v;
      for (const [idx, v] of snapshot.water || []) { doc.waterDef[idx] = v[0]; doc.waterH[idx] = v[1]; }
      this._refresh(s.touchedFields, rect);
    };
    this.ed.history.push(`${s.tool} brush`, () => write(before), () => write(after));
    return s;
  }

  _refresh(fields, rect) {
    const x0 = Math.max(0, Math.floor(rect.x0)), z0 = Math.max(0, Math.floor(rect.z0));
    const x1 = Math.ceil(rect.x1), z1 = Math.ceil(rect.z1);
    if (fields.has('heights') || fields.has('colors')) { this.ed.view.updateVertices(x0, z0, x1, z1); this.ed.objects?.terrainChanged(x0, z0, x1, z1); this.ed.markers?.terrainChanged(); }
    if (fields.has('vertexTypes') || fields.has('cellVariants') || fields.has('holes')) this.ed.view.updateTiles(x0, z0, x1, z1);
    if (fields.has('water')) this.ed.view.markWater(0);
    if (fields.has('attrs')) this.ed.emit('collision');
    this.ed.emit?.('brush:changed',{fields,rect});
  }

  // ---------------------------------------------------------------------------------------- vertex (height/colour)
  _vertexRect(x, z, radius) {
    const doc = this.ed.doc;
    return {
      x0: Math.max(0, Math.floor(x - radius)), z0: Math.max(0, Math.floor(z - radius)),
      x1: Math.min(doc.width, Math.ceil(x + radius)), z1: Math.min(doc.height, Math.ceil(z + radius)),
    };
  }

  _height(x, z, radius, amount, o) {
    const doc = this.ed.doc, X = doc.width + 1, r = this._vertexRect(x, z, radius);
    const min = o.min != null && o.min !== '' ? Number(o.min) : -Infinity, max = o.max != null && o.max !== '' ? Number(o.max) : Infinity;
    for (let vz = r.z0; vz <= r.z1; vz++) {
      for (let vx = r.x0; vx <= r.x1; vx++) {
        const d = Math.hypot(vx - x, vz - z);
        if (d > radius) continue;
        const i = vz * X + vx, f = brushFalloff(d, radius, o.falloff);
        this._write('heights', i, Math.max(min, Math.min(max, doc.heights[i] + amount * f)));
      }
    }
    this._expandDirty(r.x0, r.z0, r.x1, r.z1);
    this.ed.view.updateVertices(r.x0, r.z0, r.x1, r.z1);
    this.ed.objects?.terrainChanged(r.x0, r.z0, r.x1, r.z1);
  }

  _smooth(x, z, radius, amount, o) {
    const doc = this.ed.doc, X = doc.width + 1, r = this._vertexRect(x, z, radius);
    const src = doc.heights.slice();
    for (let vz = r.z0; vz <= r.z1; vz++) {
      for (let vx = r.x0; vx <= r.x1; vx++) {
        const d = Math.hypot(vx - x, vz - z);
        if (d > radius) continue;
        let sum = 0, n = 0;
        for (let dz = -1; dz <= 1; dz++) for (let dx = -1; dx <= 1; dx++) {
          const nx = vx + dx, nz = vz + dz;
          if (nx < 0 || nz < 0 || nx > doc.width || nz > doc.height) continue;
          sum += src[nz * X + nx]; n++;
        }
        const avg = sum / Math.max(1, n), i = vz * X + vx, f = brushFalloff(d, radius, o.falloff);
        this._write('heights', i, src[i] + (avg - src[i]) * Math.min(1, amount * f));
      }
    }
    this._expandDirty(r.x0, r.z0, r.x1, r.z1);
    this.ed.view.updateVertices(r.x0, r.z0, r.x1, r.z1);
    this.ed.objects?.terrainChanged(r.x0, r.z0, r.x1, r.z1);
  }

  _flatten(x, z, radius, amount, o) {
    const doc = this.ed.doc, X = doc.width + 1, r = this._vertexRect(x, z, radius), target = this._stroke.flattenHeight;
    for (let vz = r.z0; vz <= r.z1; vz++) {
      for (let vx = r.x0; vx <= r.x1; vx++) {
        const d = Math.hypot(vx - x, vz - z);
        if (d > radius) continue;
        const i = vz * X + vx, f = brushFalloff(d, radius, o.falloff);
        this._write('heights', i, doc.heights[i] + (target - doc.heights[i]) * Math.min(1, amount * f));
      }
    }
    this._expandDirty(r.x0, r.z0, r.x1, r.z1);
    this.ed.view.updateVertices(r.x0, r.z0, r.x1, r.z1);
    this.ed.objects?.terrainChanged(r.x0, r.z0, r.x1, r.z1);
  }

  _noise(x, z, radius, strength, o) {
    const doc = this.ed.doc, X = doc.width + 1, r = this._vertexRect(x, z, radius), s = this._stroke;
    for (let vz = r.z0; vz <= r.z1; vz++) {
      for (let vx = r.x0; vx <= r.x1; vx++) {
        const key = vz * X + vx;
        if (s.seen.has(key)) continue;
        const d = Math.hypot(vx - x, vz - z);
        if (d > radius) continue;
        s.seen.add(key);
        const f = brushFalloff(d, radius, o.falloff);
        let h = (vx * 374761393 + vz * 668265263) ^ (vx << 13); h = Math.imul(h ^ (h >>> 15), 2246822519); h ^= h >>> 13;
        const rnd = ((h >>> 0) / 4294967295) * 2 - 1;
        this._write('heights', key, doc.heights[key] + rnd * strength * f);
      }
    }
    this._expandDirty(r.x0, r.z0, r.x1, r.z1);
    this.ed.view.updateVertices(r.x0, r.z0, r.x1, r.z1);
    this.ed.objects?.terrainChanged(r.x0, r.z0, r.x1, r.z1);
  }

  _vcolor(x, z, radius, amount, o) {
    const doc = this.ed.doc, X = doc.width + 1, r = this._vertexRect(x, z, radius);
    const [cr, cg, cb] = o.color || [255, 255, 255];
    for (let vz = r.z0; vz <= r.z1; vz++) {
      for (let vx = r.x0; vx <= r.x1; vx++) {
        const d = Math.hypot(vx - x, vz - z);
        if (d > radius) continue;
        const i = vz * X + vx, base = i * 4, f = Math.min(1, amount * brushFalloff(d, radius, o.falloff));
        this._writeColor(i, doc.colors[base] + (cr - doc.colors[base]) * f, doc.colors[base + 1] + (cg - doc.colors[base + 1]) * f, doc.colors[base + 2] + (cb - doc.colors[base + 2]) * f);
      }
    }
    this._expandDirty(r.x0, r.z0, r.x1, r.z1);
    this.ed.view.updateVertices(r.x0, r.z0, r.x1, r.z1, { normals: false });
  }

  // ---------------------------------------------------------------------------------------- cell (type/variant/hole/water/collision)
  _cellRect(x, z, radius) {
    const doc = this.ed.doc;
    return {
      x0: Math.max(0, Math.floor(x - radius)), z0: Math.max(0, Math.floor(z - radius)),
      x1: Math.min(doc.width - 1, Math.ceil(x + radius)), z1: Math.min(doc.height - 1, Math.ceil(z + radius)),
    };
  }

  _type(x, z, radius, o) {
    // vertexTypes is per-VERTEX (the 4-corner ground blend), so painting a "ground type" touches the vertex grid
    const doc = this.ed.doc, X = doc.width + 1, r = this._vertexRect(x, z, radius), t = Number(o.type) & 3;
    for (let vz = r.z0; vz <= r.z1; vz++) for (let vx = r.x0; vx <= r.x1; vx++) if (Math.hypot(vx - x, vz - z) <= radius) this._write('vertexTypes', vz * X + vx, t);
    this._expandDirty(r.x0, r.z0, r.x1, r.z1);
    this.ed.view.updateTiles(r.x0, r.z0, r.x1, r.z1);
  }

  _variant(x, z, radius, o) {
    const doc = this.ed.doc, W = doc.width, r = this._cellRect(x, z, radius), s = this._stroke;
    for (let cz = r.z0; cz <= r.z1; cz++) {
      for (let cx = r.x0; cx <= r.x1; cx++) {
        const key = cz * W + cx;
        if (s.seen.has(key) || Math.hypot(cx + 0.5 - x, cz + 0.5 - z) > radius) continue;
        s.seen.add(key);
        this._write('cellVariants', key, (Math.random() * 4) | 0);
      }
    }
    this._expandDirty(r.x0, r.z0, r.x1 + 1, r.z1 + 1);
    this.ed.view.updateTiles(r.x0, r.z0, r.x1, r.z1);
  }

  _hole(x, z, radius, o) {
    const doc = this.ed.doc, W = doc.width, r = this._cellRect(x, z, radius), erase = !!o.erase;
    for (let cz = r.z0; cz <= r.z1; cz++) for (let cx = r.x0; cx <= r.x1; cx++) if (Math.hypot(cx + 0.5 - x, cz + 0.5 - z) <= radius) this._write('holes', cz * W + cx, erase ? 0 : 1);
    this._expandDirty(r.x0, r.z0, r.x1 + 1, r.z1 + 1);
    this.ed.view.updateTiles(r.x0, r.z0, r.x1, r.z1);
  }

  _water(x, z, radius, o) {
    const doc = this.ed.doc, W = doc.width, r = this._cellRect(x, z, radius), erase = !!o.erase;
    let defIdx = 0;
    if (!erase) {
      const name = o.defName || doc.waterDefs[0] || 'water01.txt';
      let k = doc.waterDefs.findIndex(n => n.toLowerCase() === name.toLowerCase());
      if (k < 0) { doc.waterDefs.push(name); k = doc.waterDefs.length - 1; }
      defIdx = k + 1;
    }
    const level = o.absolute != null && o.absolute !== '' ? Number(o.absolute) : null;
    for (let cz = r.z0; cz <= r.z1; cz++) {
      for (let cx = r.x0; cx <= r.x1; cx++) {
        if (Math.hypot(cx + 0.5 - x, cz + 0.5 - z) > radius) continue;
        const i = cz * W + cx;
        if (erase) { this._writeWater(i, 0, doc.waterH[i]); continue; }
        this._writeWater(i, defIdx, level != null ? level : doc.heightAt(cx + 0.5, cz + 0.5) + (Number(o.offset) || 0.4));
      }
    }
    this._expandDirty(r.x0, r.z0, r.x1 + 1, r.z1 + 1);
    this.ed.view.markWater(0.15);
  }

  _collision(x, z, radius, o) {
    const doc = this.ed.doc, W = doc.width, r = this._cellRect(x, z, radius), attr = Number(o.attr) || 0;
    for (let cz = r.z0; cz <= r.z1; cz++) for (let cx = r.x0; cx <= r.x1; cx++) if (Math.hypot(cx + 0.5 - x, cz + 0.5 - z) <= radius) this._write('attrs', cz * W + cx, attr);
    this._expandDirty(r.x0, r.z0, r.x1 + 1, r.z1 + 1);
    this.ed.emit('collision');
  }

  // ---------------------------------------------------------------------------------------- decals (single stamps, own undo)
  stampDecal(x, z, { name, size = 1, rot = 0 }) {
    const doc = this.ed.doc, W = doc.width;
    const cx = Math.max(0, Math.min(W - size, Math.floor(x - size / 2))), cz = Math.max(0, Math.min(doc.height - size, Math.floor(z - size / 2)));
    const cell = cz * W + cx;
    const entry = { name, cell, size, rot: rot & 3, mat: 0 };
    doc.decals.push(entry);
    this.ed.history.push('Stamp decal',
      () => { const i = doc.decals.indexOf(entry); if (i >= 0) doc.decals.splice(i, 1); this.ed.view.markDecals(0); },
      () => { doc.decals.push(entry); this.ed.view.markDecals(0); });
    this.ed.view.markDecals(0.1);
  }
  eraseDecalAt(x, z) {
    const doc = this.ed.doc;
    const idx = doc.decals.findIndex(d => {
      const cx = d.cell % doc.width, cz = Math.floor(d.cell / doc.width);
      return x >= cx && x <= cx + d.size && z >= cz && z <= cz + d.size;
    });
    if (idx < 0) return false;
    const [entry] = doc.decals.splice(idx, 1);
    this.ed.history.push('Erase decal',
      () => { doc.decals.splice(idx, 0, entry); this.ed.view.markDecals(0); },
      () => { const i = doc.decals.indexOf(entry); if (i >= 0) doc.decals.splice(i, 1); this.ed.view.markDecals(0); });
    this.ed.view.markDecals(0.1);
    return true;
  }
}
