// ENGINE-CHOSEN scheduling/progress values; these affect loading only, never game data.
// Shares reflect the measured load phases: ~4 s systems, ~1.3 s world,
// ~1.4 s NPCs, ~15 s full artwork. Priority artwork now has a separate barrier.
export const LOADING = Object.freeze({ tables: [0.02, 0.10], systems: [0.10, 0.30],
  world: [0.30, 0.52], player: 0.52, npcs: 0.60, monsters: 0.68, globalPreload: [0.68, 0.72],
  artwork: [0.72, 0.94], icons: 0.94, scene: 0.98, complete: 1 });
export const phaseFraction = (range, fraction) => range[0] + (range[1] - range[0]) * Math.max(0, Math.min(1, Number(fraction) || 0));

export const ARTWORK_LANES = 8;
export const SCRIPT_LANES = 4;
export const PRIORITY_PANELS = Object.freeze(['bag', 'inventory', 'skills', 'dshop', 'costumebag', 'cashinven', 'storage', 'character']);

// ENGINE-CHOSEN idle-time window pre-building (src/ui/uiwin/prebuild.js): windows are built after the world is ready,
// in requestIdleCallback slices that never exceed ~8 ms, never while a map loads, and never run onOpen/services.
export const PREBUILD = Object.freeze({
  budgetMs: 6,           // work per idle slice (also capped by the deadline's timeRemaining() - 1)
  starvedBudgetMs: 3,    // slice length when the page never idles (the idle callback fires only because its timeout expired)
  minIdleMs: 2,          // an idle period shorter than this is not used
  idleTimeoutMs: 120,    // longest wait for an idle period before one starved slice runs
  busyPollMs: 250,       // re-check interval while a map is loading
  scriptLanes: 4,        // window scripts fetched ahead of the builds
  warnMs: 8,             // a single uninterrupted chunk longer than this is reported in the prebuild status
});
// Most-used panels first; everything else follows in registration order.
export const PREBUILD_FIRST = Object.freeze(['character', 'party', 'guild', 'mail', 'quest', 'map', 'options', 'craft', 'petinfo', 'storage',
  'upgrade', 'help', 'contents', 'friends', 'messenger', 'settings', 'statsetting', 'costumebag', 'cashinven', 'shop']);
// Never built ahead of use (audited with every registered create(): no other window issues requests, writes the save, emits
// events or opens windows while it is built; its game-event handlers all return early while the window is closed).
//   mp3player        create() calls scan(), a GET /api/ls directory listing
//   shops.probability create() clones ~1800 controls in one go (re-indexing the whole tree per clone: ~300-400 ms)
export const PREBUILD_SKIP = Object.freeze(['mp3player', 'shops.probability']);

// ENGINE-CHOSEN request scheduling. Existing consumers retain their required/optional policy.
export const JSON_PREFETCH_LANES = 4;
export const STARTUP_JSON = Object.freeze(['dungeons_travel', 'items', 'items-visual',
  'items-looks', 'items-options', 'items-styles', 'items-tables', 'items-actions',
  'life', 'mounts', 'quests', 'dialogs', 'boxes', 'shops', 'dshop', 'skills/common']);
// Full skill/effect and GM catalogs stay with their existing lazy consumers.
export const DEFERRED_JSON = Object.freeze(['shops_search', 'mounts-ui']);

export const NPC_MODEL_LANES = 4;

// ENGINE-CHOSEN asset worker count (engine/asset-work.js: DDS decode + DXT mip encoding, mesh/skeleton/anim parsing).
// 2.2.0 used 2; the trace of a warm Ardeca load showed both busy for ~4 s of the ~10 s loading screen with up to 42 jobs
// waiting (measured). Leave two logical cores for the page's main thread and the GPU process.
// Console override for measurements: globalThis.__dekaronAssetWorkers = n (before the first asset load).
export const ASSET_WORKERS = Object.freeze({ min: 2, max: 6, reservedCores: 2 });
export function assetWorkerCount(cores = globalThis.navigator?.hardwareConcurrency) {
  const forced = Number(globalThis.__dekaronAssetWorkers);
  if (Number.isInteger(forced) && forced >= 1 && forced <= 16) return forced;
  const n = Number.isInteger(cores) && cores > 0 ? cores - ASSET_WORKERS.reservedCores : ASSET_WORKERS.min;
  return Math.max(ASSET_WORKERS.min, Math.min(ASSET_WORKERS.max, n));
}

// ENGINE-CHOSEN front-end prefetch (engine/prefetch.js, 2.2.1 instant loading): request lanes of the character-select
// replay (the select scene's own requests go first: low fetch priority), stored map lists and their size cap (localStorage).
// tableIdleTimeoutMs: a game-table parse waits at most this long for an idle period (the scenes keep rendering between parses).
// portalRadius (cells) / portalLanes: in the world, the destination of a walk-in warp zone this close is replayed in the
// background (systems/warpzones), two requests at a time so play is not disturbed; only maps visited before have a list.
export const PREFETCH = Object.freeze({ lanes: 6, maxMaps: 12, maxManifestBytes: 600 * 1024, tableIdleTimeoutMs: 150, portalRadius: 40, portalLanes: 2, maxUIEntries: 3000 });

// ENGINE-CHOSEN metadata deadline/recovery; missing metadata keeps validator-backed URLs.
export const CONTENT_VERSION_TIMEOUT_MS = 2500;
export const CONTENT_VERSION_RETRY_MS = 1000;
