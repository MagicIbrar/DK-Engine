// System registry. Every gameplay/UI system lives in src/systems/<name>/index.js and exports
//   install(game)            required; may be async. Register windows/hotkeys here (docs/UIWIN.md).
//   update(dt, game)         optional; called every unpaused frame after the core modules.
//   dispose(game)            optional; called when the game shuts down.
// and is registered by ONE line in the list below (keep it sorted by nothing in particular; just append).
// Loading is dynamic and isolated: a system that fails to load or install is logged and skipped, it never
// breaks the game or the other systems. game.js calls installSystems / updateSystems / disposeSystems.
//
//   sys('inventory', () => import('./inventory/index.js'));

const REGISTRY = [];
/** Register a system loader (one line per system, below). */
export function sys(name, loader, opts = {}) { REGISTRY.push({ name, loader, opts }); }

// ------------------------------------------------------------------------------------------ registry
// (append one line per system)
sys('warpzones', () => import('./warpzones/index.js'));
sys('items', () => import('./items/index.js'));
sys('life', () => import('./life/index.js'));
sys('shops', () => import('./shops/index.js'));
sys('mounts', () => import('./mounts/index.js'));
sys('dungeons', () => import('./dungeons/index.js'));
sys('quests', () => import('./quests/index.js'));
sys('events', () => import('./events/index.js'));
sys('skills', () => import('./skills/index.js'));
sys('graphics', () => import('./graphics/index.js'));   // before hud-options: its Options drive game.gfx (bloom etc.)
sys('hud-options', () => import('./hud-options/index.js'));
sys('mapbuilder', () => import('./mapbuilder/index.js'));
sys('itembuilder', () => import('./itembuilder/index.js'));
sys('charwin', () => import('./charwin/index.js'));
sys('gm', () => import('./gm/index.js'));
sys('network', () => import('./network/index.js'));
sys('extras', () => import('./extras/index.js'));   // mini help, map item list, bounty ... (docs: extras/index.js)
sys('chartrade', () => import('./chartrade/index.js'));   // Character trade (game2/chartradewnd), after network + items
sys('skillmaster', () => import('./skillmaster/index.js'));   // Learn Skill popup + skill blind (game2/skill), after skills + network

/** Declarative fetch/compile hints only; never execute loaders before their ordered install. */
export function preloadSystemModules(doc = globalThis.document) {
  if (!doc?.head) return;
  for (const {name} of REGISTRY) {
    const href = new URL(`./${name}/index.js`, import.meta.url).href;
    if (doc.querySelector(`link[rel="modulepreload"][href="${href}"]`)) continue;
    const link = doc.createElement('link'); link.rel = 'modulepreload'; link.href = href;
    doc.head.appendChild(link);
  }
}

// ------------------------------------------------------------------------------------------ runtime
const installed = [];   // { name, mod }
const failed = [];      // { name, error }

/** Names of the registered systems (in registration order). */
export function registeredSystems() { return REGISTRY.map(r => r.name); }
/** { installed: [names], failed: [{name, error}] } */
export function systemStatus() { return { installed: installed.map(s => s.name), failed: failed.map(f => ({ name: f.name, error: String(f.error?.message || f.error) })) }; }
/** The installed module of a system (its exports), or null. */
export function getSystem(name) { return installed.find(s => s.name === name)?.mod || null; }

/**
 * Load and install every registered system, in order. Never throws.
 * game.systems gets { get(name), status() } so systems can find each other.
 */
export async function installSystems(game, onProgress = () => {}) {
  game.systems = { get: getSystem, status: systemStatus, list: registeredSystems };
  game.systemInstallErrors = new Map();
  if (game.save.authority === 'server') {
    game.accountPermissions = { role: 'player', capabilities: [] };
    try {
      const response = await fetch('/api/auth/me', { credentials: 'same-origin', signal: AbortSignal.timeout(15000) });
      const account = await response.json();
      if (response.ok && account.id) game.accountPermissions = { role: account.role || 'player', capabilities: account.capabilities || [] };
    } catch (error) { console.warn('[systems] account permissions unavailable', error); }
  }
  const pending = REGISTRY.filter(r => {
    if (game.save.authority === 'server' && ['gm', 'itembuilder'].includes(r.name) && !game.accountPermissions.capabilities.includes('gm:panel')) return false;
    if (game.save.authority === 'server' && ['dungeons', 'events'].includes(r.name)) return false;
    return !installed.some(s => s.name === r.name);
  });
  let done = 0;
  const progress = name => { try { onProgress(done, pending.length, name); } catch (error) { console.warn('[systems] progress callback failed', error); } };
  progress(null);
  for (const r of pending) {
    // These systems still run locally; verified multiplayer must not install client-side reward/admin paths.
    if (game.save.authority === 'server' && ['gm', 'itembuilder'].includes(r.name) && !game.accountPermissions.capabilities.includes('gm:panel')) continue;
    if (game.save.authority === 'server' && ['dungeons', 'events'].includes(r.name)) continue;
    if (installed.some(s => s.name === r.name)) continue;
    try {
      progress(r.name);
      const mod = await r.loader();
      if (typeof mod?.install === 'function') await mod.install(game);
      installed.push({ name: r.name, mod });
    } catch (error) {
      failed.push({ name: r.name, error });
      game.systemInstallErrors.set(r.name,error);
      console.error(`[systems] ${r.name} failed to install`, error);
    }
    done++; progress(r.name);
  }
  game.events?.emit?.('systems', systemStatus());
  return systemStatus();
}

/**
 * Per-frame update of every installed system that has update(dt). Errors are logged once per system and message.
 * (playgate) A single throw no longer disables the system for the whole session (one bad frame used to kill the HUD
 * or the skills for good); only an update that keeps throwing for 600 frames in a row is disabled.
 */
export function updateSystems(game, dt) {
  // Items' ordinary update stays in registry order; wing effects sample after the mount rig advances.
  const itemsIndex = installed.findIndex(s => s.name === 'items');
  const mountsIndex = installed.findIndex(s => s.name === 'mounts');
  const items = itemsIndex >= 0 ? installed[itemsIndex] : null;
  const deferEffects = items && mountsIndex > itemsIndex;
  const updateEffects = () => {
    const fn = items?.mod?.updateEquipmentEffects;
    if (typeof fn !== 'function' || items.broken || items.equipmentEffectsBroken) return;
    try { fn.call(items.mod, dt, game); items.equipmentEffectsFails = 0; }
    catch (err) {
      items.equipmentEffectsFails = (items.equipmentEffectsFails || 0) + 1;
      const seen = (items.equipmentEffectsErrors ||= new Set());
      const msg = String(err?.message || err);
      if (!seen.has(msg)) { seen.add(msg); console.error('[systems] items equipment effects update threw (kept running)', err); }
      if (items.equipmentEffectsFails >= 600) { items.equipmentEffectsBroken = true; console.error('[systems] items equipment effects keeps throwing; disabled'); }
    }
  };
  for (const s of installed) {
    const fn = s.mod?.update;
    if (typeof fn === 'function' && !s.broken) {
      try { fn.call(s.mod, dt, game); s.fails = 0; }
      catch (err) {
        s.fails = (s.fails || 0) + 1;
        const seen = (s.errSeen ||= new Set());
        const msg = String(err?.message || err);
        if (!seen.has(msg)) { seen.add(msg); console.error(`[systems] ${s.name}.update threw (kept running)`, err); }
        if (s.fails >= 600) { s.broken = true; console.error(`[systems] ${s.name}.update keeps throwing; disabled`); }
      }
    }
    if (s === items && !deferEffects) updateEffects();
    else if (deferEffects && s.name === 'mounts') updateEffects();
  }
}

/** Dispose every installed system (reverse order). */
export function disposeSystems(game) {
  for (const s of installed.slice().reverse()) {
    try { s.mod?.dispose?.(game); } catch (err) { console.error(`[systems] ${s.name}.dispose threw`, err); }
  }
  installed.length = 0;
}
