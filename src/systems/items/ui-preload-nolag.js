// UI-PRELOAD-NOLAG: bake every owned inventory / equipment / bag / costume / cash icon and
// preload every equipment-preset body mesh behind the loading screen so opening inventory,
// switching bags, and swapping full-set <-> empty presets never wait on first-use IO or GPU bake.
// Server already owns inventory + all 5 presets in the profile snapshot; the client only displays.
// Kill switch: globalThis.__dekaronNoUiPreload = true
import { warmIcons } from '../../ui/icon-prewarm.js';
import { borrowPreviewIcon } from '../../ui/preview-cache.js';
import { socketIconGlow } from './ui/common.js';
import { PRESETS, S, PART_OF_SLOT } from './equip.js';

const SLOT_IDS = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 18, 19, 20, 24, 25, 26, 27, 28, 33, 34, 35, 36];
// Typical equipment-slot paint sizes from ui_invenwnd_base_renew (cell ~31; armour/weapon taller).
const SLOT_PX = Object.freeze({
  [S.helmet]: [72, 72], [S.armor]: [72, 99], [S.pants]: [72, 72], [S.glove]: [72, 72], [S.boots]: [72, 72],
  [S.weapon]: [72, 140], [S.offhand]: [72, 140], [S.wing]: [72, 72], [S.costume]: [72, 99],
  [S.grow]: [48, 48], [S.pet]: [48, 48], [S.vehicle]: [48, 48], [S.emblem]: [48, 48],
  [S.talisman]: [48, 48], [S.belt]: [48, 48], [S.acc1]: [36, 36], [S.acc2]: [36, 36],
  [S.acc3]: [36, 36], [S.acc4]: [36, 36], [S.earL]: [36, 36], [S.earR]: [36, 36],
  [S.brace1]: [36, 36], [S.brace2]: [36, 36], [S.force1]: [36, 36], [S.force2]: [36, 36],
});

export function uiPreloadDisabled() {
  return globalThis.__dekaronNoUiPreload === true || globalThis.__dekaronNoPrewarm === true;
}

async function decodeUrl(icon) {
  if (!icon?.url || typeof Image === 'undefined') return;
  const release = borrowPreviewIcon(icon);
  try {
    const image = new Image();
    image.src = icon.url;
    if (typeof image.decode === 'function') await image.decode().catch(() => {});
  } finally { release(); }
}

/** Spin + decode every unique item across all unlocked bag pages at bag cell size. */
export async function warmAllBagSpins(sys, { cw = 37, ch = 36, concurrency = 3 } = {}) {
  if (uiPreloadDisabled() || !sys?.icons) return { items: 0 };
  const seen = new Map();
  const unlocked = Math.max(1, Number(sys.bag?.unlocked) || 2);
  for (let page = 0; page < unlocked; page++) {
    for (const inst of sys.bag.items(page) || []) {
      if (!inst || seen.has(inst.itemIndex)) continue;
      seen.set(inst.itemIndex, inst);
    }
  }
  const list = [...seen.values()];
  await warmIcons(list, async inst => {
    const [w, h] = sys.bag.size(inst);
    const pw = w * cw, ph = h * ch;
    const glow = socketIconGlow(sys, inst, [pw, ph]);
    const icon = await sys.icons.spin(inst.itemIndex, pw, ph, null, glow).catch(() => null)
      || await sys.icons.get(inst.itemIndex, pw, ph, null, glow).catch(() => null);
    await decodeUrl(icon);
  }, { concurrency });
  await sys.icons.queue;
  return { items: list.length, pages: unlocked };
}

/** ICON-PRELOAD (2026-10-30): storage + shared storage icons at the storage grid's cell size (its grid paints spins). */
export async function warmStorageIcons(sys, { concurrency = 3 } = {}) {
  if (uiPreloadDisabled() || !sys?.icons) return { items: 0 };
  let cw = 37, ch = 36;
  try {
    const grid = (await sys.game?.uiwin?.get?.('storage'))?.control?.('slotitem');
    if (grid?.cw > 0 && grid?.ch > 0) { cw = grid.cw; ch = grid.ch; }
  } catch { /* optional panel: bag cell size */ }
  const jobs = new Map();
  for (const container of [sys.stash, sys.shared]) {
    let list = [];
    try { list = container?.list || []; } catch { list = []; }
    for (const inst of list) {
      if (!inst) continue;
      const [w, h] = container.size(inst);
      const pw = w * cw, ph = h * ch, glow = socketIconGlow(sys, inst, [pw, ph]);
      jobs.set(`${inst.itemIndex}|${pw}x${ph}|${glow?.key || ''}`, { inst, pw, ph, glow });
    }
  }
  await warmIcons([...jobs.values()], async job => {
    const icon = await sys.icons.spin(job.inst.itemIndex, job.pw, job.ph, null, job.glow).catch(() => null)
      || await sys.icons.get(job.inst.itemIndex, job.pw, job.ph, null, job.glow).catch(() => null);
    await decodeUrl(icon);
  }, { concurrency });
  await sys.icons.queue;
  return { items: jobs.size, cell: [cw, ch] };
}

/** Bake spinning icons for every equipped item in all 5 presets at their slot pixel sizes. */
export async function warmAllEquipSlotIcons(sys, { concurrency = 3 } = {}) {
  if (uiPreloadDisabled() || !sys?.icons || !sys.equip) return { slots: 0 };
  const jobs = [];
  for (let pi = 0; pi < PRESETS; pi++) {
    for (const id of SLOT_IDS) {
      const inst = sys.equip.get(id, pi);
      if (!inst) continue;
      const size = SLOT_PX[id] || [48, 48];
      const def = sys.db.def(inst.itemIndex);
      const fw = Math.max(1, def?.w || 1), fh = Math.max(1, def?.h || 1);
      const cs = 31;
      let pw = fw * cs, ph = fh * cs;
      const bw = size[0], bh = size[1];
      const k = Math.min(1, bw / pw, bh / ph);
      const span = k >= 1 && (bw > pw || bh > ph) ? [bw / cs, bh / cs] : null;
      if (span) { pw = bw; ph = bh; }
      else { pw = Math.round(pw * k); ph = Math.round(ph * k); }
      jobs.push({ inst, pw, ph, span, bw, bh });
    }
  }
  const unique = [...new Map(jobs.map(j => {
    const glow = socketIconGlow(sys, j.inst, [j.pw, j.ph], [j.bw, j.bh], [-Math.round((j.bw - j.pw) / 2), -Math.round((j.bh - j.ph) / 2)]);
    return [`${j.inst.itemIndex}|${j.pw}x${j.ph}|${j.span || ''}|${glow?.key || ''}`, { ...j, glow }];
  })).values()];
  await warmIcons(unique, async job => {
    const icon = await sys.icons.spin(job.inst.itemIndex, job.pw, job.ph, job.span, job.glow).catch(() => null)
      || await sys.icons.get(job.inst.itemIndex, job.pw, job.ph, job.span, job.glow).catch(() => null);
    await decodeUrl(icon);
  }, { concurrency });
  await sys.icons.queue;
  return { slots: unique.length, presets: PRESETS };
}

/** Costume wardrobe + cash-inventory stills (and spins where cheap). */
export async function warmCostumeAndCash(sys, { concurrency = 2 } = {}) {
  if (uiPreloadDisabled() || !sys?.icons) return { costume: 0, cash: 0 };
  const costume = [...new Map((sys.costumeBag?.list || []).map(i => [i.itemIndex, i])).values()];
  const cash = [...new Map((sys.game?.save?.cashInv || []).map(i => [i.itemIndex, i])).values()];
  const cw = 33, ch = 33;
  await warmIcons(costume, async inst => {
    const [w, h] = sys.costumeBag?.size?.(inst) || [1, 1];
    const icon = await sys.icons.spin(inst.itemIndex, w * cw, h * ch).catch(() => null)
      || await sys.icons.get(inst.itemIndex, w * cw, h * ch).catch(() => null);
    await decodeUrl(icon);
  }, { concurrency });
  await warmIcons(cash, async inst => {
    const icon = await sys.icons.get(inst.itemIndex, 36, 36).catch(() => null);
    await decodeUrl(icon);
  }, { concurrency });
  await sys.icons.queue;
  return { costume: costume.length, cash: cash.length };
}

async function warmWeaponAsset(models, w) {
  if (!w?.mesh || w.none) return 0;
  let n = 0;
  const loadOne = async (mesh, tpack, textures, skel, attachSkel) => {
    if (!mesh) return;
    try {
      if (skel) await models.loadSkinned({ skelKey: skel, parts: [{ meshKey: mesh, tpackKey: tpack || null, textures: textures || null }] });
      else await models.loadStatic(mesh, { tpackKey: tpack || null, textures: textures || null });
      if (attachSkel && !skel) {
        await models.loadSkinned({ skelKey: attachSkel, parts: [{ meshKey: mesh, tpackKey: tpack || null, textures: textures || null }] }).catch(() => null);
      }
      n++;
    } catch { /* missing asset must not block entry */ }
  };
  await loadOne(w.mesh, w.tpack, w.textures, w.skel, w.attachSkel);
  await loadOne(w.leftMesh, w.leftTpack || w.tpack, w.leftTextures || w.textures, w.leftSkel, w.leftAttachSkel);
  return n;
}

/**
 * Fetch every mesh/tpack used by any of the 5 equipment presets into ModelCache so
 * Look.apply / refreshAppearance on preset switch is a cache hit (no hitch full-set <-> empty).
 * Does not mutate save.equipment — only flips equip.data.active temporarily to build each view.
 */
export async function warmAllPresetLooks(sys) {
  if (uiPreloadDisabled() || !sys?.equip || !sys.game?.models) return { meshes: 0 };
  const models = sys.game.models;
  const skel = sys.game.player?.classDef?.skeleton || sys.game.classDef?.skeleton || null;
  const bodyParts = [];
  const weapons = [];
  const wings = [];
  const prev = sys.equip.data.active;
  try {
    for (let pi = 0; pi < PRESETS; pi++) {
      sys.equip.data.active = pi;
      const view = sys.equip.view(sys.itemStats || {});
      for (const part of Object.values(PART_OF_SLOT)) {
        const a = view[part];
        if (a?.mesh) bodyParts.push(a);
      }
      if (view.weapon && !view.weapon.none) weapons.push(view.weapon);
      if (view.wing?.mesh) wings.push(view.wing);
    }
  } finally {
    sys.equip.data.active = prev;
  }
  const uniqBody = [...new Map(bodyParts.map(a => [`${a.mesh}|${a.tpack || ''}|${JSON.stringify(a.textures || null)}`, a])).values()];
  const uniqWing = [...new Map(wings.map(a => [`${a.mesh}|${a.tpack || ''}|${JSON.stringify(a.textures || null)}`, a])).values()];
  let ok = 0;
  if (skel && uniqBody.length) {
    try {
      await models.loadSkinned({
        skelKey: skel,
        parts: uniqBody.map(a => ({ meshKey: a.mesh, tpackKey: a.tpack || null, textures: a.textures || null })),
      });
      ok += uniqBody.length;
    } catch {
      for (const a of uniqBody) {
        try {
          await models.loadSkinned({ skelKey: skel, parts: [{ meshKey: a.mesh, tpackKey: a.tpack || null, textures: a.textures || null }] });
          ok++;
        } catch { /* ignore */ }
      }
    }
  } else {
    for (const a of uniqBody) {
      try { await models.loadStatic(a.mesh, { tpackKey: a.tpack || null, textures: a.textures || null }); ok++; } catch { /* ignore */ }
    }
  }
  for (const w of weapons) ok += await warmWeaponAsset(models, w);
  for (const a of uniqWing) {
    try {
      if (a.skel) await models.loadSkinned({ skelKey: a.skel, parts: [{ meshKey: a.mesh, tpackKey: a.tpack || null, textures: a.textures || null }] });
      else await models.loadStatic(a.mesh, { tpackKey: a.tpack || null, textures: a.textures || null });
      ok++;
    } catch { /* ignore */ }
  }
  return { meshes: ok, body: uniqBody.length, weapons: weapons.length, wings: uniqWing.length };
}

/** Keep owned bag/equip icon blobs alive so D-Shop background bakes cannot LRU-evict them. */
export function pinOwnedPreviewIcons(sys) {
  if (uiPreloadDisabled() || !sys?.icons?.cache) return { pinned: 0 };
  const owner = sys._uiPreloadPinOwner || (sys._uiPreloadPinOwner = { isConnected: true, releases: [] });
  for (const release of owner.releases || []) { try { release(); } catch { /* ignore */ } }
  owner.releases = [];
  let pinned = 0;
  for (const value of sys.icons.cache.values()) {
    if (!value?.url || value.then) continue;
    try {
      owner.releases.push(borrowPreviewIcon(value));
      pinned++;
    } catch { /* ignore */ }
  }
  owner._pinnedAt = performance.now();
  return { pinned };
}

/** Full no-lag warm used by items._warm during the loading barrier. */
export async function preloadUiNoLag(sys, report = {}) {
  if (uiPreloadDisabled()) { report.skipped = 'kill switch'; return report; }
  const g = sys.game;
  try {
    const win = await g.uiwin?.get?.('inventory');
    if (win && !win.isOpen) { win.place(); sys.inv?.render?.(); }
    for (const name of ['costumebag', 'cashinven', 'storage', 'dshop', 'skills', 'character', 'bag']) {
      try { await g.uiwin?.get?.(name); } catch { /* optional panel */ }
    }
    const t0 = performance.now(), stats0 = { ...(sys.icons?.stats || {}) };
    report.bags = await warmAllBagSpins(sys);
    report.storage = await warmStorageIcons(sys);
    report.equip = await warmAllEquipSlotIcons(sys);
    report.extra = await warmCostumeAndCash(sys);
    report.looks = await warmAllPresetLooks(sys);
    report.pins = pinOwnedPreviewIcons(sys);
    const stats1 = sys.icons?.stats || {};
    report.icons = { ms: Math.round(performance.now() - t0), bakes: (stats1.bakes || 0) - (stats0.bakes || 0), diskHits: (stats1.diskHits || 0) - (stats0.diskHits || 0) };
    if (win && !win.isOpen) sys.inv?.render?.();
    report.ok = true;
  } catch (err) {
    report.ok = false;
    report.error = String(err?.message || err);
    console.warn('[ui-preload-nolag]', report.error);
  }
  sys._uiPreloadReport = report;
  return report;
}
