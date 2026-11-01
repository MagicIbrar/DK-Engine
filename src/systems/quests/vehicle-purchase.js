// Scripted vehicle purchase dialogs ("Purchase Swift Box", Sergio, quest 15820): read the price tiers, the level and the sold-out page
// from the original dialog text, count what a character bought. Pure functions shared by the quest engine (host and offline) and the
// NPC dialog. What the NPC hands over is ENGINE-CHOSEN: src/config/engine-chosen-vehicle-purchase.js.
import { VEHICLE_PURCHASE } from '../../config/engine-chosen-vehicle-purchase.js';

export const purchaseFlag = id => `purchase:${id}`;
const num = v => (Number.isFinite(Number(v)) ? Number(v) : 0);

/** {tiers:[{page, price, purchaseOption, declineOption}], soldOutPage, minLevel, item} of a purchase dialog, or null for any other quest. */
export function purchaseInfo(db, id) {
  const q = db?.quest?.(id);
  if (!q || !/vehiclepurchase/i.test(String(q.dialog?.file || ''))) return null;
  const item = VEHICLE_PURCHASE.items[Number(id)];
  if (!item) return null;
  const rows = [...(db.tree(id)?.messages || [])].sort((a, b) => Number(a[0]) - Number(b[0]));
  const tiers = [];
  for (const row of rows) {
    const options = db.pageOptions(id, row[0]);
    const text = db.pageText(id, row[0]) || '';
    const price = /([0-9][0-9,]*)\s*DIL/i.exec(text);
    if (options.length < 2 || !price) continue;
    tiers.push({ page: Number(row[0]), price: Number(price[1].replace(/,/g, '')), purchaseOption: Number(options[0].option), declineOption: Number(options[options.length - 1].option) });
  }
  if (!tiers.length) return null;
  const last = tiers[tiers.length - 1].page;
  const sold = rows.find(r => Number(r[0]) > last && db.pageOptions(id, r[0]).length === 1 && db.pageText(id, r[0]) != null);
  const level = /over\s+(\d+)\s+levels?/i.exec(db.pageText(id, tiers[0].page) || '');
  return { tiers, soldOutPage: sold ? Number(sold[0]) : null, minLevel: level ? Number(level[1]) : 1, item };
}

/** Purchases this character has made of dialog `id` (quests.flags). */
export const purchasesDone = (flags, id) => Math.max(0, Math.floor(num(flags?.[purchaseFlag(id)])));

/** The dialog page that is current for `done` purchases: the next tier, or the sold-out page after the last. */
export const purchasePage = (info, done) => (done < info.tiers.length ? info.tiers[done].page : info.soldOutPage);
