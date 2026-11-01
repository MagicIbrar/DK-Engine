// Canonical preview URLs belong to resource bundles, not to item/model aliases.
const descriptors = new WeakMap();
const owners = new WeakMap();
const resolveRecord = icon => descriptors.get(icon?.baseIcon || icon);
export const PREVIEW_CACHE_LIMIT = 400;   // count cap; the 64 MB byte cap below still bounds memory (a 60x60 shop icon is ~57 KB)
export const PREVIEW_CACHE_BYTES = 64 * 1024 * 1024;
export const PREVIEW_ALIAS_LIMIT = 512;

/** A bounded inactive LRU plus explicitly live DOM references. */
export class PreviewCache extends Map {
  constructor({ limit = PREVIEW_CACHE_LIMIT, bytes = PREVIEW_CACHE_BYTES, aliases = PREVIEW_ALIAS_LIMIT, schedule = (callback, delay) => globalThis.setTimeout(callback, delay), cancel = timer => globalThis.clearTimeout(timer), revoke = url => URL.revokeObjectURL(url) } = {}) {
    super(); this.generation = 0; this.limit = limit; this.byteLimit = bytes; this.aliasLimit = aliases;
    this.resources = new Set(); this.clock = 0; this.timer = null; this.observer = null;
    this.schedule = schedule; this.cancel = cancel; this.revoke = revoke;
  }
  get(key) {
    const value = super.get(key), record = resolveRecord(value);
    if (record?.live) record.used = ++this.clock;
    return value;
  }
  set(key, value) {
    // Preserve Map callers that seed a ready icon: conservatively charge the
    // entire inactive byte budget when its pixel dimensions are unknown.
    if (value?.url && !value?.then && !descriptors.has(value)) this.remember(value, this.byteLimit, () => null);
    super.set(key, value); this.deferTrim(); return this;
  }
  remember(icon, decodedBytes, reload) {
    if (descriptors.has(icon)) return icon;
    const record = { cache: this, live: true, bytes: decodedBytes, used: ++this.clock, pins: new Set(), urls: new Set(), reload, url: icon.url, sheetURL: icon.spin?.url };
    this.resources.add(record);
    this.alias(icon, record);
    this.deferTrim(); return icon;
  }
  alias(icon, source) {
    const record = source?.cache === this ? source : resolveRecord(source);
    if (!record) return icon;
    const url = icon.url, spin = icon.spin;
    if (url?.startsWith('blob:')) record.urls.add(url);
    if (spin?.url?.startsWith('blob:')) record.urls.add(spin.url);
    const sheetAlias = url === record.sheetURL;
    Object.defineProperty(icon, 'url', { enumerable: true, configurable: true, get: () => record.live ? (sheetAlias ? record.sheetURL : record.url) : null });
    if (spin) {
      const sheet = { ...spin };
      Object.defineProperty(sheet, 'url', { enumerable: true, get: () => record.live ? record.sheetURL : null });
      Object.defineProperty(icon, 'spin', { enumerable: true, configurable: true, value: sheet });
    }
    descriptors.set(icon, record); return icon;
  }
  deferTrim() {
    if (this.timer !== null) return;
    // Promise consumers get the whole current task to attach/paint their owner.
    this.timer = this.schedule(() => { this.timer = null; this.trim(); }, 0);
  }
  pin(owner, record) {
    const pin = { owner: new WeakRef(owner), record };
    record.pins.add(pin); owners.set(owner, pin);
    if (!this.observer && typeof MutationObserver === 'function' && globalThis.document?.documentElement) {
      this.observer = new MutationObserver(() => this.deferTrim());
      this.observer.observe(document.documentElement, { childList: true, subtree: true });
    }
    this.deferTrim();
  }
  unpin(pin) { pin.record.pins.delete(pin); this.deferTrim(); }
  prunePins(record) {
    for (const pin of record.pins) {
      const owner = pin.owner.deref();
      if (!owner?.isConnected) {
        record.pins.delete(pin);
        if (owner && owners.get(owner) === pin) owners.delete(owner);
      }
    }
  }
  evict(record) {
    record.live = false; this.resources.delete(record);
    for (const [key, value] of this) if (resolveRecord(value) === record) super.delete(key);
    for (const url of record.urls) this.revoke(url);
    record.urls.clear(); record.pins.clear(); record.url = record.sheetURL = null;
  }
  trim() {
    for (const record of this.resources) this.prunePins(record);
    const inactive = [...this.resources].filter(r => !r.pins.size).sort((a, b) => a.used - b.used);
    let bytes = inactive.reduce((n, r) => n + r.bytes, 0), count = inactive.length;
    for (const record of inactive) {
      if (count <= this.limit && bytes <= this.byteLimit) break;
      bytes -= record.bytes; count--; this.evict(record);
    }
    // Item aliases are rebuildable from the canonical model key. Pending work
    // is never dropped: its aliases retain the existing single-flight contract.
    const ready = [...this].filter(([key, value]) => !value?.then && (/^(s\|)?\d+\|/.test(key) || !resolveRecord(value)));
    let countKeys = ready.length;
    for (const [key] of ready) {
      if (countKeys <= this.aliasLimit) break;
      super.delete(key); countKeys--;
    }
  }
  stats() {
    const records = [...this.resources], pinned = records.filter(r => r.pins.size), inactive = records.filter(r => !r.pins.size);
    return { resources: records.length, inactive: inactive.length, inactiveDecodedBytes: inactive.reduce((n, r) => n + r.bytes, 0), pinned: pinned.length, pinnedDecodedBytes: pinned.reduce((n, r) => n + r.bytes, 0), urls: records.reduce((n, r) => n + r.urls.size, 0), readyAliases: [...this.values()].filter(v => !v?.then).length, rebuildableAliases: [...this].filter(([key, value]) => !value?.then && (/^(s\|)?\d+\|/.test(key) || !resolveRecord(value))).length, pendingAliases: [...this.values()].filter(v => v?.then).length, trimPending: this.timer !== null };
  }
  clear() {
    this.generation++;
    if (this.timer !== null) this.cancel(this.timer);
    this.timer = null; this.observer?.disconnect(); this.observer = null;
    for (const record of [...this.resources]) this.evict(record);
    super.clear();
  }
}

export function previewReload(owner, itemIndex, w, h, spin, generation, cells = null, glow = null) {
  const ref = new WeakRef(owner);
  return () => {
    const icons = ref.deref();
    return icons?.cache.generation === generation ? icons._get(itemIndex, w, h, spin, cells, glow) : null;
  };
}

/** Preserve canonical URL lifetime when a consumer adds its own metadata. */
export function copyPreviewIcon(icon, extra = {}) {
  const copy = { ...icon, ...extra }, record = resolveRecord(icon);
  return record ? record.cache.alias(copy, record) : copy;
}

/** Scoped non-DOM borrow, e.g. while an Image.decode promise owns the URL. */
export function borrowPreviewIcon(icon) {
  const record = resolveRecord(icon);
  if (!record?.live) return () => {};
  const owner = { isConnected: true }; record.cache.pin(owner, record);
  const pin = owners.get(owner); let released = false;
  return () => { if (released) return; released = true; owner.isConnected = false; owners.delete(owner); record.cache.unpin(pin); };
}

/** Bounded consumer caches own a borrow until their normal eviction/clear. */
export class PreviewReferences extends Map {
  constructor() { super(); this.leases = new Map(); }
  set(key, value) {
    if (super.get(key) === value) return this;
    this.delete(key); super.set(key, value); this.leases.set(key, borrowPreviewIcon(value)); return this;
  }
  delete(key) { this.leases.get(key)?.(); this.leases.delete(key); return super.delete(key); }
  clear() { for (const release of this.leases.values()) release(); this.leases.clear(); super.clear(); }
}

/** Paint leases keep live/reused connected controls safe; no strong DOM owner. */
export function retainPreviewIcon(owner, icon) {
  const record = resolveRecord(icon), previous = owners.get(owner);
  if (previous?.record === record && record?.live) return null;
  if (previous) { owners.delete(owner); previous.record.cache.unpin(previous); }
  if (!record) return null;
  if (record.live) { record.cache.pin(owner, record); return null; }
  // Detached/reused UI descriptors expose null URLs after eviction. Rehydrate
  // through the original single-flight path when that descriptor is painted.
  return Promise.resolve().then(record.reload).then(next => {
    if (!next) return null;
    return icon.baseIcon ? { ...icon, baseIcon: next } : next;
  }).catch(() => null);
}
