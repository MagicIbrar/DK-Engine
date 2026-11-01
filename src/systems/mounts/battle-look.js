// The own body inside a DK Square / Draco battle draws its squad's team look (share/arena/changeshape.csv), as other players
// already see it. The host projects that look on the character's public rows only inside its battle instance during the fight
// and the result wait (server/world/battle-looks.mjs, ENGINE-CHOSEN teamLook) and flags each replaced row `projected`; the own
// public row (network.self.appearance) is read back here for the local look builders: the items system's equipment view
// (Equipment.view: costume parts, wings, insignia, weapon appearance), CostumeLook and WingVisual. Nothing is written to the
// save, the equipment or the stats; when the projection ends the real look returns.
/** {costume, wing, emblem, weapon: {4, 5}} item indices of the projected own rows, or null outside a projected battle. */
export function ownBattleLook(game) {
  const net = game?.network;
  if (!net || net.disposed || net.active === false || !net.ready || game.save?.authority !== 'server') return null;
  const rows = net.self?.appearance;
  if (!Array.isArray(rows)) return null;
  let out = null;
  for (const r of rows) {
    if (!r?.projected || !Number.isSafeInteger(r.itemIndex)) continue;
    out ||= { weapon: {} };
    if (r.slot === 18) out.costume = r.itemIndex;
    else if (r.slot === 7) out.wing = r.itemIndex;
    else if (r.slot === 33) out.emblem = r.itemIndex;
    else if ((r.slot === 4 || r.slot === 5) && Number.isSafeInteger(r.appearance) && r.appearance > 0) out.weapon[r.slot] = r.appearance;
  }
  return out;
}
/** Stable signature of a projection (empty outside the battle). */
export function battleLookSignature(look) { return look ? JSON.stringify([look.costume || 0, look.wing || 0, look.emblem || 0, look.weapon?.[4] || 0, look.weapon?.[5] || 0]) : ''; }
