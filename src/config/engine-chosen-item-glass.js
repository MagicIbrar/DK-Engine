// POTION BOTTLE GLASS (item meshes whose texture is texture/item/*bottle*.dds, e.g. gen_pot_cas_bottle.dds on the cash / Package
// potions 60296 / 60297). The Global data holds the glass texture and its mesh subset (the glass is drawn over the coloured liquid
// subset) but no blend state: that lives in the client's own item shader, not in the data. The engine therefore draws the glass
// with normal alpha blending at a partial opacity so the red / blue liquid underneath keeps its colour (additive blending washed
// it out to white under the full-bright inventory icon light). Every entry is ENGINE-CHOSEN (not in Global data).
export const ITEM_GLASS_CHOSEN = Object.freeze({
  /** ENGINE-CHOSEN (not in Global data): the glass subset is drawn with normal alpha blending (never additive), no depth write, after the opaque liquid. */
  BLEND: 'normal alpha, no depth write, after the liquid',
  /** ENGINE-CHOSEN (not in Global data): opacity of the bottle glass over the liquid (0..1); tuned so the liquid colour reads clearly and the glass still looks like glass. */
  OPACITY: 0.3,
});
