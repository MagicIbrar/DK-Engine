// Online socket-stone insertion from the held cursor.
// With server authority, picking up a bag item moves it into server cursor custody (common.js onPickup), so a
// socket stone dropped onto a socketed item arrived as from:'cursor' and was sent as a cursor place/swap
// against that item; the insert request (socket.js insertStone -> server 'socket' action) never ran.
// Here the held stone is first returned to the bag (its origin cell, else the first free spot, the same rule as
// cursorReferenceDrop), then the normal insertStone confirmation + server request runs on the bag-owned stone.
import { cursorActionResult } from './common.js';

export const isSocketStoneDef = (def) => Number(def?.type) === 1 && Number(def?.code) === 0;

/** Should a cursor drop of `itemIndex` onto the single occupant `occ` become a stone insertion? */
export function cursorStoneTarget(sys, itemIndex, occ) {
  if (typeof sys.insertStone !== 'function' || !Array.isArray(occ) || occ.length !== 1) return null;
  if (!isSocketStoneDef(sys.db.def(itemIndex))) return null;
  return sys.db.def(occ[0].itemIndex)?.slot ? occ[0] : null;
}

export async function cursorStoneInsert(sys, target) {
  const game = sys.game, state = game.save?.itemCursor, item = state?.item;
  if (!item || !target?.uid) return false;
  const origin = state.origin, [w, h] = sys.bag.size(item);
  const at = origin?.container === 'bag' && sys.bag.fits(origin.page, origin.x, origin.y, w, h)
    ? { page: origin.page, x: origin.x, y: origin.y } : sys.bag.findSpot(w, h);
  if (!at) { sys.msg?.(null, null, 'Socket stone insertion requires room in your inventory. The stone is still held.'); return false; }
  const character = game.save.id, lease = game.network?.token, uid = item.uid, targetUid = target.uid;
  if (!await sys.cursorPlace('bag', { ...at, targetUid: null })) return false;
  if (game.save.id !== character || game.network?.token !== lease) return true;
  const stone = sys.bag.byUid(uid), owned = sys.bag.byUid(targetUid);
  if (stone && owned) await sys.insertStone(stone, owned);
  return cursorActionResult(sys, true);
}
