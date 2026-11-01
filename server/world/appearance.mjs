// Public presentation only: no inventory, ownership UIDs, stats, options or account identifiers.
// 33 emblem and 36 talisman carry native worn effects (emblem aura, talisman ground sigil).
const slots=[4,5,7,8,9,10,11,12,18,33,36];
export function publicAppearance(profile){
  const eq=profile.equip,preset=eq?.presets?.[eq.active||0]||{};
  return slots.flatMap(slot=>{
    const item=eq?.items?.[preset[slot]];
    if(!Number.isSafeInteger(item?.itemIndex)||item.itemIndex<=0)return [];
    return [{slot,itemIndex:item.itemIndex,appearance:Number.isSafeInteger(item.appearance)?item.appearance:0,
      sockets:Array.isArray(item.sockets)?item.sockets.slice(0,8).map(v=>Number.isSafeInteger(v)?v:0):[]}];
  });
}
