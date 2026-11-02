// Shared helpers of the item windows: icons in grids / slots, drag payloads, footprint maths.
import { paintIcon, socketMarkerLayout } from '../../../ui/uiwin/controls.js';
import { socketGems } from '../authored-effects-data.js';
import { canStack } from '../model.js';
import { isBoundInst } from '../flags.js';

/** Socket glow of a weapon instance's icon, in the icon's own reference px, or null: {key, gems:[{x, y, size, attribute}]}.
 * One gem per FILLED socket at the centre of the marker paintIcon() draws for it (same socketMarkerLayout inputs as
 * itemPreviewIcon: markerSize = the box the markers are laid out in, offset = its origin relative to the icon image), with the
 * modeleffect group24 attribute of that stone. icons.js bakes the native socket glow around these points. Weapons only: the
 * Global socket scenes are weapon effects. */
export function socketIconGlow(sys, inst, imageSize, markerSize = imageSize, offset = null) {
  if (!inst?.sockets?.length) return null;
  const def = sys.db.def(inst.itemIndex);
  if (def?.slot !== 'weapon') return null;
  const sockets = inst.sockets.slice(0, 4), gems = socketGems(sockets, sys.db);
  if (!gems.length) return null;
  const layout = socketMarkerLayout(markerSize[0], markerSize[1], sockets.length, [Math.max(1, def.w || 1), Math.max(1, def.h || 1)]);
  const [ox, oy] = offset || [0, 0], half = n => Math.round(n * 2) / 2;
  const list = gems.map(({ index, attribute }) => {
    const p = layout.points[index];
    return p ? { x: half(p.x + layout.size / 2 + ox), y: half(p.y + layout.size / 2 + oy), size: layout.size, attribute } : null;
  }).filter(Boolean);
  return list.length ? { key: `${imageSize[0]}x${imageSize[1]}/${sockets.length}:${list.map(g => `${g.attribute}@${g.x},${g.y},${g.size}`).join(';')}`, gems: list, capacity: sockets.length } : null;
}
const sameGlow = (sys, inst, size, glow) => (socketIconGlow(sys, inst, size)?.key || '') === (glow?.key || '');


// Native Socket atlas art follows stored stone IDs, independently of model art.
const socketDecorations = new WeakMap();
export function itemPreviewIcon(sys, inst, icon, size = null, offset = null) {
 if (!icon || !inst?.sockets?.length) return icon;
 const markers = inst.sockets.slice(0,4).map(id => {
  const stone = id ? sys.db.def(Number(id)) : null;
  const index = id ? stone?.use?.socketIcon : 0;
  const art = sys.db.enums.socketIcons?.[index];
  return art && !art.outside ? {index:Number(index),label:id?(stone.name||String(id)):'Empty socket'} : null;
 });
 if (!markers.some(Boolean)) return icon;
 const def=sys.db.def(inst.itemIndex);
 // The stones follow THIS item's own footprint (item.dat Width x Height), not a class- or kind-wide default.
 const socketCells=[Math.max(1,def?.w||1),Math.max(1,def?.h||1)];
 const socketSize=size||[socketCells[0]*32,socketCells[1]*32],socketOffset=offset||[0,0];
 const key=JSON.stringify([markers,socketSize,socketOffset,socketCells]);
 if (typeof icon !== 'object') return {baseIcon:icon,socketMarkers:markers,socketSize,socketOffset,socketCells};
 let cache=socketDecorations.get(icon);if(!cache){cache=new Map();socketDecorations.set(icon,cache);}
 if(!cache.has(key)){if(cache.size>=8)cache.delete(cache.keys().next().value);cache.set(key,{...icon,baseIcon:icon,socketMarkers:markers,socketSize,socketOffset,socketCells});}
 return cache.get(key);
}

export const fmt = (n) => Number(n || 0).toLocaleString('en-US');

/** Grid items of a container page for a UIGrid (icons fill their current rows asynchronously). */
export function gridItems(sys, grid, container, page, { dim = null, mark = null, held = null, referenceStock = true } = {}) {
  const out = [];
  let pending = false;
  for (const inst of container.items(page)) {
    const [w, h] = container.size(inst);
    const pw = w * grid.cw, ph = h * grid.ch;
    const def = sys.db.def(inst.itemIndex);
    const carrying = !!held && inst.uid === held;
    // Belt assignment retains inventory ownership. Keep usable non-equipment stock
    // visible throughout pickup/drop, including percentage recovery and status items.
    const shortcutStock = referenceStock && carrying && !def?.slot && !!def?.use && Object.keys(def.use).length > 0;
    if (carrying && !shortcutStock) {
      out.push({ x: inst.x, y: inst.y, w, h, icon: null,
        data: inst, count: null, dim: false, _held: true });
      continue;
    }
    // the original 3D inventory model, spinning (icons.js sprite sheet); the still stands in while the sheet renders
    const glow = socketIconGlow(sys, inst, [pw, ph]);
    let icon = sys.icons.spinNow(inst.itemIndex, pw, ph, null, glow);
    if (!icon) {
      pending = true; icon = sys.icons.now(inst.itemIndex, pw, ph, null, glow) || sys.icons.cached?.(inst.itemIndex) || null;
      const itemIndex = inst.itemIndex, generation = sys.icons.cache?.generation;
      const key = `${itemIndex}|${pw}x${ph}${glow ? `|${glow.key}` : ''}`;
      const waits = grid._itemIconWaits ||= new Map();
      if (!waits.has(key) || waits.get(key).generation !== generation) {
        const apply = ic => {
          if (!ic || generation !== sys.icons.cache?.generation) return;
          for (const row of grid.items || []) {
            if (row.data?.itemIndex !== itemIndex || (row.w || 1) * grid.cw !== pw || (row.h || 1) * grid.ch !== ph || (row._held && !row._heldReference) || !sameGlow(sys, row.data, [pw, ph], glow)) continue;
            const nextIcon = itemPreviewIcon(sys, row.data, ic, [pw,ph]);
            if (row.icon === nextIcon) continue;
            row.icon = nextIcon;
            if (row._el) { const count = row._el.querySelector('.uw-count'); paintIcon(row._el, row.icon); if (count) row._el.appendChild(count); }
          }
        };
        const request = sys.icons.get(itemIndex, pw, ph, null, glow).then(ic => { apply(ic); return sys.icons.spin(itemIndex, pw, ph, null, glow); });
        waits.set(key, { request, generation });
        void request.then(ic => {
          // Failed/missing models must not trigger a refresh -> resolved-null -> refresh loop.
          // Paint only matching current rows: bag switches, drags and server updates can replace them.
          if (!ic || generation !== sys.icons.cache?.generation) return;
          for (const row of grid.items || []) {
            if (row.data?.itemIndex !== itemIndex || (row.w || 1) * grid.cw !== pw || (row.h || 1) * grid.ch !== ph || !sameGlow(sys, row.data, [pw, ph], glow)) continue;
            if (row._held && !row._heldReference) continue;
            const nextIcon = itemPreviewIcon(sys, row.data, ic, [pw,ph]);
            if (row.icon === nextIcon) continue;
            row.icon = nextIcon;
            if (row._el) {
              const count = row._el.querySelector('.uw-count');
              paintIcon(row._el, row.icon);
              if (count) row._el.appendChild(count);
            }
          }
        }).catch(() => {}).finally(() => { if (waits.get(key)?.request === request) waits.delete(key); });
      }
    }
    const stack = sys.db.stackSize(def);
    const expired = inst.expiresAt && inst.expiresAt < Date.now();
    const registered = !!sys.reserved?.has(inst.uid);   // registered in an item NPC window (ui/craft.js)
    out.push({
      x: inst.x, y: inst.y, w, h, icon:itemPreviewIcon(sys, inst, icon, [pw,ph]), data: inst,
      count: stack > 1 ? inst.count : 1,
      dim: shortcutStock || expired || registered || (dim ? dim(inst) : false),
      _held: carrying, _heldReference: shortcutStock,
      color: mark && mark(inst) ? '#fdb602' : null,
    });
  }
  return { items: out, pending };
}

/** Top-left cell of a w x h footprint centred on the pointer (the drag icon is centred on the cursor). */
export function footprintAt(grid, e, w, h) {
  const r = grid.el.getBoundingClientRect();
  const sc = grid.win.mgr?.scale || 1;
  const px = (e.clientX - r.left) / sc, py = (e.clientY - r.top) / sc;
  let x = Math.round(px / grid.cw - w / 2), y = Math.round(py / grid.ch - h / 2);
  // The pointer can be inside a valid edge cell while the centred cursor icon
  // extends outside the grid. Snap the whole footprint inward in that case.
  const cols = grid.cols, rows = grid.rowsN;
  if (Number.isFinite(cols) && Number.isFinite(rows) && px >= 0 && py >= 0 && px < cols * grid.cw && py < rows * grid.ch && w <= cols && h <= rows) {
    x = Math.max(0, Math.min(cols - w, x));
    y = Math.max(0, Math.min(rows - h, y));
  }
  return { x, y };
}

/** Icon of an item sized to its footprint inside a slot control (cellsize), centred. */
export function slotIcon(sys, ctrl, inst) {
  if (!inst) {
    // Invalidate pending loads before clearing an empty slot.
    ctrl._itemIconState = null; ctrl._itemIconInstance = null;
    if (ctrl._itemIconPainted !== null) { ctrl.setIcon(null); ctrl._itemIconPainted = null; }
    ctrl.setCount?.(''); return;
  }
  ctrl._itemIconInstance = inst;
  const def = sys.db.def(inst.itemIndex);
  const cs = ctrl.cell || [32, 32];
  const w = Math.max(1, def?.w || 1), h = Math.max(1, def?.h || 1);
  let pw = w * cs[0], ph = h * cs[1];
  const bw = ctrl.box.w || pw, bh = ctrl.box.h || ph;
  const k = Math.min(1, bw / pw, bh / ph);
  // A slot larger than the footprint (equipment: armour 72x99 / helmet 72x72 / weapon 72x140 at cellsize 31) draws the
  // model at the slot's own cell scale over the whole slot rect, so a model wider/taller than its footprint (Rondo's
  // Armor 2.4 x 1.8 cells) is not shrunk into the footprint box; a smaller slot keeps the shrunk footprint image.
  const span = k >= 1 && (bw > pw || bh > ph) ? [bw / cs[0], bh / cs[1]] : null;
  if (span) { pw = bw; ph = bh; }
  pw = Math.round(pw * (span ? 1 : k)); ph = Math.round(ph * (span ? 1 : k));
  const place = (icon) => {
    // Socket markers belong to the full control, not the centred/scaled model.
    icon = itemPreviewIcon(sys, ctrl._itemIconInstance, icon, [bw,bh], [-Math.round((bw-pw)/2),-Math.round((bh-ph)/2)]);
    if (ctrl._itemIconPainted === icon && ctrl._itemIconSize === `${pw}x${ph}`) return;
    ctrl.setIcon(icon || null, { inset: 0 });
    ctrl._itemIconPainted = icon || null;
    ctrl._itemIconSize = `${pw}x${ph}`;
    const s = ctrl._icon?.style;
    if (s) { s.width = `${pw}px`; s.height = `${ph}px`; s.left = `${Math.round((bw - pw) / 2)}px`; s.top = `${Math.round((bh - ph) / 2)}px`; }
  };
  // The socket glow is baked around the markers of the full control box (see socketIconGlow).
  const glow = socketIconGlow(sys, inst, [pw, ph], [bw, bh], [-Math.round((bw - pw) / 2), -Math.round((bh - ph) / 2)]);
  const key = `${inst.itemIndex}|${pw}x${ph}|${span || ''}|${glow?.key || ''}|g${sys.icons.cache?.generation || 0}`;
  let state = ctrl._itemIconState;
  if (state?.key !== key) state = ctrl._itemIconState = { key };
  const now = sys.icons.spinNow(inst.itemIndex, pw, ph, span, glow);
  if (now) place(now);
  else {
    place(sys.icons.now(inst.itemIndex, pw, ph, span, glow) || sys.icons.cached?.(inst.itemIndex));
    if (!state.request) {
      state.request = sys.icons.get(inst.itemIndex, pw, ph, span, glow).then(ic => { if (ctrl._itemIconState === state && ic) place(ic); return sys.icons.spin(inst.itemIndex, pw, ph, span, glow); });
      void state.request.then(ic => { if (ctrl._itemIconState === state && ic) place(ic); }).catch(() => {});
    }
  }
  const stack = sys.db.stackSize(def);
  ctrl.setCount?.(stack > 1 && inst.count > 1 ? inst.count : '');
}

/** Drag payload for an instance. */
/** Global's held (sticky) item icon is 32 px per footprint cell whatever window it came from (CCursorControl).
 * The legacy cell argument is still accepted from callers but no longer sizes the held icon. */
export const HELD_ICON_CELL = 32;
export function itemPayload(sys, inst, from, extra = {}, cell = [37, 36]) {
  const def = sys.db.def(inst.itemIndex);
  const w = Math.max(1, def?.w || 1), h = Math.max(1, def?.h || 1);
  const size = [w * HELD_ICON_CELL, h * HELD_ICON_CELL]; void cell;
  const glow = socketIconGlow(sys, inst, size);
  const spin = sys.icons.spinNow(inst.itemIndex, size[0], size[1], null, glow);
  const icon = spin || sys.icons.now(inst.itemIndex, size[0], size[1], null, glow) || sys.icons.cached?.(inst.itemIndex) || null;
  const stack = sys.db.stackSize(def);
  return {
    data: { kind: 'item', from, inst, itemIndex: inst.itemIndex, uid: inst.uid, count: inst.count || 1, ...extra },
    canRetain: () => ownedDragItem(sys, from, inst.uid, extra) !== null,
    ...(from !== 'cursor' && !extra.split && ['bag','equip','stash','shared','costume','belt','cash','pet'].includes(from) && typeof sys.cursorPickup === 'function'
      ? { onPickup: () => cursorActionResult(sys, sys.cursorPickup({from,uid:inst.uid,...extra})) } : {}),
    // the held icon = the item's own spinning inventory model at its footprint size (rendered on demand when the
    // source showed it at another size, e.g. an equipment slot), with the stack count like the bag cell
    icon:itemPreviewIcon(sys, inst, icon, size), iconAsync: spin ? null : sys.icons.get(inst.itemIndex, size[0], size[1], null, glow).then(ic=>itemPreviewIcon(sys,inst,ic,size)),
    iconSpinAsync: spin ? null : sys.icons.get(inst.itemIndex, size[0], size[1], null, glow).then(() => sys.icons.spin(inst.itemIndex, size[0], size[1], null, glow)).then(ic=>itemPreviewIcon(sys,inst,ic,size)),
    count: stack > 1 ? (inst.count || 1) : 1,
    size,
  };
}

// Resolve presentation against current ownership, never an object captured before an async action.
function ownedDragItem(sys, from, uid, where) {
  if (from === 'cursor') return sys.game?.save?.itemCursor?.item?.uid === uid ? sys.game.save.itemCursor.item : null;
  if (from === 'bag') return sys.bag?.list?.find(item => item.uid === uid) || null;
  if (from === 'belt') return sys.game?.save?.potionBelt?.find(item => item.uid === uid && item.x === where.slot) || null;
  if (from === 'equip') { const item = sys.equip?.get(where.slot, where.preset); return item?.uid === uid ? item : null; }
  if (from === 'stash' || from === 'shared') return sys[from]?.list?.find(item => item.uid === uid) || null;
  if (from === 'cash') return sys.game?.save?.cashInv?.find(item=>item.uid===uid)||null;
  if (from === 'costume') return sys.game?.save?.costumeBag?.find(item=>item.uid===uid)||null;
  if (from === 'pet') {const eq=sys.game?.save?.equip,parent=eq?.items?.[eq?.presets?.[eq.active||0]?.[19]];return parent?.uid===where.parentUid?parent.pet?.inv?.find(item=>item.uid===uid)||null:null;}
  return undefined; // Other item windows retain their existing cancellation/ownership rules.
}

/** A durable cursor is an owner, not an icon hiding an occupied bag cell. */
export function cursorPayload(sys) {
  const state=sys.game?.save?.itemCursor,item=state?.item;if(!item)return null;
  const payload=itemPayload(sys,item,'cursor',{revision:state.revision});
  payload.pendingCount=state.pending?.length||0;
  payload.requestCancel=()=>cursorActionResult(sys,sys.cursorCancel());
  payload.referenceDrop=(target,event)=>cursorReferenceDrop(sys,target,event);
  payload.onDropOutside=()=>cursorDiscardAsk(sys);
  return payload;
}
/** Global plays soundscript code 12 / class 0 (sound.json item.get['0']) whenever an item becomes attached to the cursor. */
export function cursorAttachSound(sys){const a=sys?.game?.audio,list=a?.S?.item?.get?.['0'];if(!list||typeof a.playOne!=='function')return false;try{a.playOne(list,{});return true;}catch{return false;}}
export function cursorActionResult(sys,result){
  const finish=ok=>{if(!ok)return false;const heldItem=cursorPayload(sys);if(heldItem)cursorAttachSound(sys);return heldItem?{heldItem}:true;};
  return result?.then?Promise.resolve(result).then(finish):finish(result);
}
/** Setting a held item down plays Global soundscript 11 with the item's Quality column (def +0x12) as sub-code
 *  (32-bit main callers 01316a20, 01318330, 0131f7f0, 0131fca0, 013f4b50, 01473e80, 014f4c50): bag, equip,
 *  costume bag, storage, warehouse and pet bag. sound.json item.equip[quality]. Belt/cash: no Global caller, no sound. */
export const CURSOR_PLACE_SOUND=new Set(['bag','equip','costume','stash','shared','pet']);
export function cursorPlaceSound(sys,container,def){
  if(!CURSOR_PLACE_SOUND.has(container)||!def)return false;
  const a=sys?.game?.audio,list=a?.S?.item?.equip?.[String(def.quality)];
  if(!list||typeof a.playOne!=='function')return false;
  try{a.playOne(list,{});return true;}catch{return false;}
}
/** Windows that put Global's inventory in a non-Normal Inven::State (Shop, Storage, Trade, CharacterTrade, Mail and
 *  the NPC item services). Every such state's world-release handler (vtable +0x30) is empty: the item stays held. */
export const INVEN_STATE_WINDOWS=['shop','storage','sharedtrade','chartrade','mail','exchange','exchangestore','upgrade','addsocket','removestone','optionupgrade','itemchange','incuse','brand','stonegamble','munzang','vehicle_cycle','accupgrade','helmetrank','talisman','pet_shapechange'];
export function inventoryStateBusy(sys){
  const ui=sys?.game?.uiwin;if(typeof ui?.isOpen!=='function')return false;
  return INVEN_STATE_WINDOWS.some(name=>{try{return !!ui.isOpen(name);}catch{return false;}});
}
/** Global world-release gate, in Global order: CGameUser 008931d0 (state, costume bag 260:72) ->
 *  Inven::State::Normal 01518f70 (map ItemDrop 0 -> 40:9) -> drop result 01315df0 (4: binding -> 40:81). */
export function groundDropRefusal(sys,inst){
  const game=sys.game;
  if(inventoryStateBusy(sys))return {silent:true};
  if(game.uiwin?.isOpen?.('costumebag'))return {cate:260,code:72};
  if(Number(game.world?.info?.row?.ItemDrop??1)===0)return {cate:40,code:9};
  if(isBoundInst(inst))return {cate:40,code:81};
  return null;
}
export async function cursorDiscardAsk(sys){
  const game=sys.game,state=game.save.itemCursor,item=state?.item;if(!item)return false;
  const revision=state.revision,uid=item.uid,character=game.save.id,token=game.network?.token;
  const refusal=groundDropRefusal(sys,item);if(refusal){if(!refusal.silent)sys.msg?.(refusal.cate,refusal.code);return false;}
  // Use the original confirmation window; retain its explicit skip-confirm preference.
  const {confirmDiscard}=await import('./dialogs.js');
  if(!await confirmDiscard(sys,item))return false;
  if(game.save.id!==character||game.network?.token!==token||game.save.itemCursor?.revision!==revision||game.save.itemCursor?.item?.uid!==uid)return false;
  return cursorActionResult(sys,sys.cursorDiscard(uid,revision));
}
export function restoreCursor(sys){
  const dnd=sys.game?.uiwin?.dnd;if(!dnd||dnd.active)return;
  const payload=cursorPayload(sys);if(payload)dnd.start(payload,dnd._lastPointer||null,'sticky');
}
/** Native service slots reference real general-inventory items; they do not own an escrow item.
 * Explicit target opt-in only. Never invent a parking cell or execute service input after a lease change.
 */
export async function cursorReferenceDrop(sys,target,event){
  const game=sys.game,state=game.save.itemCursor,item=state?.item,rule=target?._dropT;
  if(!item||rule?.referenceSource!=='bag')return false;
  const label=rule.referenceLabel||'This service',origin=state.origin,[w,h]=sys.bag.size(item);
  const at=origin?.container==='bag'&&sys.bag.fits(origin.page,origin.x,origin.y,w,h)?{page:origin.page,x:origin.x,y:origin.y}:sys.bag.findSpot(w,h);
  if(!at){sys.msg?.(null,null,`${label} requires room in your inventory. The item is still held.`);return false;}
  const character=game.save.id,lease=game.network?.token,uid=item.uid;
  if(!await sys.cursorPlace('bag',{...at,targetUid:null}))return false;
  const sameSession=()=>game.save.id===character&&game.network?.token===lease;
  if(!sameSession())return true; // Old character's accepted placement remains durably owned there.
  const owned=sys.bag.byUid(uid),data=owned?{kind:'item',from:'bag',inst:owned,uid,itemIndex:owned.itemIndex,count:owned.count,page:owned.page}:null;
  let accepted=false;
  try{if(data&&target.win?.isOpen!==false&&rule.accept?.(data,event,target)!==false)accepted=(await rule.drop?.(data,event,target))!==false;}catch{}
  if(accepted)return cursorActionResult(sys,true);
  if(!sameSession())return true;
  if(!game.save.itemCursor?.item&&sys.bag.byUid(uid)&&!sys.reserved?.has(uid)){
    try{if(await sys.cursorPickup({from:'bag',uid}))return cursorActionResult(sys,true);}catch{}
  }
  sys.msg?.(null,null,`${label} did not register the item. Its current inventory position is shown.`);
  return cursorActionResult(sys,true);
}

// A successful swap may put the displaced item in a different bag cell (or,
// for an equipment swap, in the original equipment slot). Follow the unique
// owned UID from the canonical state instead of guessing its new position.
function ownedCursorItem(sys, uid, source) {
  if (!uid) return null;
  if (source.from === 'stash' || source.from === 'shared') {
    const item = sys[source.from]?.list?.find(entry => entry.uid === uid);
    if (item) return { inst: item, from: source.from, extra: { page: item.page } };
    return null;
  }
  const bag = sys.bag?.list?.find(item => item.uid === uid);
  if (bag) return { inst: bag, from: 'bag', extra: { page: bag.page } };
  const belt = sys.game?.save?.potionBelt?.find(item => item?.uid === uid);
  if (belt) return { inst: belt, from: 'belt', extra: { slot: belt.x, entry: belt } };
  // An item still worn in another preset was not displaced into the bag. Only
  // an equipment-to-equipment swap may hand back the original equipment slot.
  if (source.from === 'equip') {
    const inst = sys.equip?.get(source.slot, source.preset);
    if (inst?.uid === uid) return { inst, from: 'equip', extra: { slot: source.slot, preset: source.preset } };
  }
  return null;
}

/** Continue holding only a remainder or displaced UID present in the acknowledged source container. */
export function itemSwapResult(sys, result, source, displacedUid) {
  const finish = ok => {
    if (!ok) return false;
    if (!displacedUid || !['bag', 'belt', 'equip', 'stash', 'shared'].includes(source.from)) return true;
    const uid = source.uid || source.inst?.uid || source.entry?.uid;
    const remaining = ownedDragItem(sys, source.from, uid, source);
    const count = source.count ?? source.inst?.count ?? source.entry?.count;
    const remainder = remaining && remaining.count < count;
    const held = remainder ? ownedCursorItem(sys, uid, source)
      : displacedUid !== uid ? ownedCursorItem(sys, displacedUid, source) : null;
    if (!held) return true;
    // A full merge consumes the source stack; the target stack stays placed.
    if (!remainder && canStack(held.inst, source.inst || source.entry, sys.db)) return true;
    const { inst, from, extra } = held;
    const payload = itemPayload(sys, inst, from, extra, from === 'belt' ? [32,32] : [37,36]);
    payload.onDropOutside = from === 'bag' ? e => sys.invState?.dropOutside?.(inst,e) ?? sys.discardAsk?.(inst) ?? false : () => false;
    return {heldItem:payload};
  };
  return result?.then ? Promise.resolve(result).then(finish) : finish(result);
}

/** Retain live icon nodes and their hover animation when only backing instance objects changed. */
export function setGridItems(grid, items) {
  const previous = grid.items || [];
  const same = previous.length === items.length && items.every((item, i) => {
    const old = previous[i];
    return ['x', 'y', 'w', 'h', 'icon', 'count', 'dim', 'color'].every(key => item[key] === old[key]) && item.data?.uid === old.data?.uid;
  });
  if (!same) { grid.setItems(items); return; }
  items.forEach((item, i) => { item._el = previous[i]._el; });
  grid.items = items;
}

/** Publish canonical slots immediately; cold models fill independently without locking the bag. */
export function setReadyGridItems(sys, grid, items) {
  const token = grid._readyItemPaint = {};
  const cold = items.filter(item => !item.icon && (!item._held || item._heldReference));
  const generation = sys.icons.cache?.generation;
  for (const item of cold) {
    item.icon = itemPreviewIcon(sys,item.data,sys.icons.cached?.(item.data.itemIndex) || null);
  }
  if (grid.el) { grid.el.style.pointerEvents = ''; grid.el.setAttribute?.('aria-busy', String(!!cold.length)); }
  setGridItems(grid, items);
  return Promise.all(cold.map(async item => {
    let icon;
    try { icon = await sys.icons.get(item.data.itemIndex, (item.w || 1) * grid.cw, (item.h || 1) * grid.ch, null, socketIconGlow(sys, item.data, [(item.w || 1) * grid.cw, (item.h || 1) * grid.ch])); } catch { return; }
    if (!icon || grid._readyItemPaint !== token || generation !== sys.icons.cache?.generation) return;
    // Another subscriber may already have supplied the rotating preview.
    if (item.icon?.spin) return;
    item.icon = itemPreviewIcon(sys,item.data,icon);
    if (item._el) { const count = item._el.querySelector('.uw-count'); paintIcon(item._el, item.icon); if (count) item._el.appendChild(count); }
  })).then(() => {
    if (grid._readyItemPaint !== token || generation !== sys.icons.cache?.generation) return false;
    grid.el?.setAttribute?.('aria-busy', 'false');
    const tips = grid.win?.mgr?.tooltips;
    if (tips?.owner === grid && tips._last) {
      if (tips.refresh) tips.refresh(grid);
      else tips.move(grid, tips._last);
    }
    return true;
  });
}

export function isCtrl(game) { const i = game.input; return !!(i?.down?.('ControlLeft') || i?.down?.('ControlRight')); }
export function isShift(game) { const i = game.input; return !!(i?.down?.('ShiftLeft') || i?.down?.('ShiftRight')); }
