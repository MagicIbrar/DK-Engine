// Extras: the original windows and services of the client that no other system owns (mini help, map item list, monster bounty, ...).
// Each module is a class `new C(game, extras)` with optional install(), update(dt), dispose(); one failing module is logged and
// skipped, never breaking the others. Installed after `network` so game.network (the shared-world client) already exists.
// The server side of the same modules lives in server/world/extras.mjs (snapshot field `ext`, event `server:ext` on game.events).
const MODULES = [
  ['minihelp', () => import('./minihelp.js'), 'MiniHelp'],
  ['bounty', () => import('./bounty.js'), 'MonsterBounty'],
  ['namechange', () => import('./namechange.js'), 'NameChange'],
  ['connectreward', () => import('./connectreward.js'), 'ConnectReward'],   // Reward Event window + HUD gift box (host: server/world/support-rewards.mjs)
  ['attendance', () => import('./attendance.js'), 'AttendanceReward'],     // Attendance Rewards board + HUD alarm (same host module)
  ['guildboard', () => import('./guildboard.js'), 'GuildBoard'],           // guild publicity board / applications / record / Best Guild War (host: server/world/guild-board.mjs)
  ['guildrank', () => import('./guildrank.js'), 'GuildRank'],              // Guild Frontier Ranking window + help (host: server/world/guild-frontier.mjs guildFrontierRanking)
  ['alliance', () => import('./alliance.js'), 'Alliance'],                // guild alliance windows / requests / mark / chat (host: server/world/alliance.mjs)
  ['guildextras', () => import('./guildextras.js'), 'GuildExtras'],       // Member list / info / delegate, guild skills, war declare / accept (host: server/world/guild-extras.mjs)
  ['mapitemlist', () => import('./mapitemlist.js'), 'MapItemList'],    // UI-MAPITEMLIST Main Reward Item List from the big map (drop-table derived, ENGINE-CHOSEN rules)
  ['siege', () => import('./siege.js'), 'Siege'],                         // SIEGE Zenoa Castle siege war NPCs / windows / battle HUD / castle objects (host: server/world/siege.mjs)
];

let extras = null;

export async function install(game) {
  extras = { game, modules: {} };
  game.extras = extras;
  // 2.2.1: the modules are fetched together (each import used to wait for the previous one's round trip); they still install
  // in this order, one after the other, exactly as before.
  const loaded = MODULES.map(([, load]) => load().catch(err => err));
  for (const [i, [key, , cls]] of MODULES.entries()) {
    try {
      const mod = await loaded[i];
      if (mod instanceof Error) throw mod;
      const C = mod[cls];
      if (!C) continue;
      const m = new C(game, extras);
      extras.modules[key] = m;
      await m.install?.();
    } catch (err) { console.error(`[extras] ${key} failed to install`, err); delete extras.modules[key]; }
  }
  return extras;
}

export function update(dt, game) {
  if (!extras) return;
  for (const [key, m] of Object.entries(extras.modules)) {
    if (!m.update) continue;
    try { m.update(dt); } catch (err) { console.error(`[extras] ${key}.update`, err); m.update = null; }
  }
}

export function dispose() {
  if (!extras) return;
  for (const m of Object.values(extras.modules)) { try { m.dispose?.(); } catch { /* ignore */ } }
  extras = null;
}
