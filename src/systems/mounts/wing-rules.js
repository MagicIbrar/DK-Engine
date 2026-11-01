// Rules shared by the wing windows (win-wing.js) and the authoritative server (server/world/item-services.mjs).
// Pure functions over the original tables (wingupgrade.csv, wingchangelist.csv, itemwingexchange.csv): nothing is guessed here.
import { wingDesignForItem, wingAssetKey } from '../../content/wings-catalog.js';

/** wingupgrade.csv has Korean headers: columns by position (the builder renames them the same way). */
export const WING_UPGRADE_COLUMNS = ['itemCode', 'rank', 'level', 'material', 'materialCount', 'costDil', 'rate', 'rate2Unused', 'penalty', 'value'];
/** itemwingexchange.csv: group, one wing item per class (pcclass order), name. */
export const WING_EXCHANGE_COLUMNS = ['groupIndex', ...Array.from({ length: 15 }, (_, c) => `class${c}`), 'name'];

/** The look of a wing item: the modeled-wing catalogue first, else the mounts table (mounts.json wings + assets). */
export function wingVisual(core, item) {
  const design = wingDesignForItem(item);
  if (design) return { asset: { mesh: wingAssetKey(design.id) }, design };
  const w = core?.wings?.[item];
  if (!w) return null;
  const asset = core.assets?.[w[0]];
  return asset ? { asset } : null;
}

/** Wing Awakening: the WINGS row of wingupgrade.csv for the wing's item level. */
export const wingUpgradeRow = (rows, def) => (rows || []).find(r => r.itemCode === 'WINGS' && Number(r.level) === Number(def?.itemLv)) || null;

/** Awakening succeeds with probability rate percent (wingupgrade.csv "Upgrade Rate"). `random()` returns [0, 1). */
export const wingUpgradeSucceeds = (rate, random) => random() * 100 < Number(rate);

/** The paid appearance-change cost: the first wingchangelist.csv row that carries one (NeedMoney + NeedMaterialIndex1 x NeedCount). */
export const wingChangeCost = rows => (rows || []).find(r => r.NeedMoney) || null;

/**
 * Wings whose look the given wing may take: the rows of wingchangelist.csv inside the wing's Group_Min..Group_Max, wearable by
 * the class, with a look of their own that differs from the ones already listed.
 *   defOf(index) -> item definition, visualOf(index) -> wingVisual(...)
 */
export function wingChangeCandidates({ rows, index, classIndex, defOf, visualOf }) {
  const own = (rows || []).find(r => r.Index === Number(index));
  if (!own) return [];
  const seen = new Set([JSON.stringify(visualOf(index)?.asset?.mesh)]);
  const out = [];
  for (const x of rows) {
    if (x.Group < own.Group_Min || x.Group > own.Group_Max) continue;
    const def = defOf(x.Index);
    if (def && !((Number(def.classMask) >>> classIndex) & 1)) continue;
    const look = visualOf(x.Index);
    if (!look) continue;
    const key = JSON.stringify(look.asset.mesh + (look.asset.textures?.[0]?.diffuse || ''));
    if (seen.has(key)) continue;
    seen.add(key); out.push(x.Index);
  }
  return out;
}

/** Wing Class Exchange: the itemwingexchange.csv group that lists this wing for one of the 15 classes. */
export const wingExchangeGroup = (rows, index) => (rows || []).find(r => Array.from({ length: 15 }, (_, c) => r[`class${c}`]).includes(Number(index))) || null;
