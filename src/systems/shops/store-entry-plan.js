// These are exactly the NPC job types dispatched to createStore in shops/index.js.
const STORE_JOBS = new Set([0, 33, 43, 51, 83, 102]);

export function storeCatalogKeys(shops, itemInfo = () => ({}), cell = 33) {
  const keys = new Set();
  for (const set of Object.values(shops?.sets || {})) for (const [item] of set.items || []) {
    const info = itemInfo(Number(item));
    keys.add(`${Number(item)}:${Math.max(1, info.w || 1) * cell}:${Math.max(1, info.h || 1) * cell}`);
  }
  return [...keys];
}

// Entry needs the initial tab of stores placed on this map, rather than every
// tab in every world's store catalogue. Keep the native set's entire grid.
export function storeEntryPlan({map, npcs, placements, shops, itemInfo = () => ({}), remoteShops = [], cell = 33}) {
  const rows = placements ?? npcs?.placements?.[map]?.rows ?? [];
  const npcIds = new Set(rows.map(row => Number(Array.isArray(row) ? row[0] : row.npcIndex)));
  const shopIds = new Set(remoteShops.map(Number).filter(index => index > 0));
  for (const index of npcIds) {
    for (const job of npcs?.npcs?.[index]?.jobs || []) {
      const type = Number(Array.isArray(job) ? job[0] : job.jobType);
      const shop = Number(Array.isArray(job) ? job[1] : job.jobIndex);
      if (STORE_JOBS.has(type) && Number.isFinite(shop)) shopIds.add(shop);
    }
  }
  const keys = new Set();
  const placedShops = [...shopIds].filter(index => shops?.shops?.[index]).sort((a, b) => a - b);
  for (const index of placedShops) {
    const tab = shops.shops[index].tabs?.[0];
    for (const [item] of shops.sets?.[tab?.set]?.items || []) {
      const info = itemInfo(Number(item));
      keys.add(`${Number(item)}:${Math.max(1, info.w || 1) * cell}:${Math.max(1, info.h || 1) * cell}`);
    }
  }
  return {map: Number(map), npcIds: [...npcIds], shopIds: placedShops, keys: [...keys]};
}
