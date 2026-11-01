// Data roots for the world's secondary readers (Arena, DK Square, Training Camp, Race, channels, observer, loadWorldData defaults).
// An installed engine has NO engine/gamedata folder (the release excludes it): the tables live in the active prepared generation
// engine/.client-cache/generations/<id>/{gamedata,data}, which server/client-source.mjs resolves for server.mjs. Every default here
// follows the same order: explicit argument > environment variable (DEKARON_DATA / DEKARON_GAMEDATA) > the active prepared
// generation > the legacy dev layout (clientSource's own fallback). Host-loaded tables (world.data.*) always come first.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { clientSource } from '../client-source.mjs';

const ENGINE = fileURLToPath(new URL('../../', import.meta.url));

/** { dataRoot, gamedataRoot }: explicit > env > prepared generation > legacy. The resolver only runs when something is missing. */
export function defaultRoots({ dataRoot, gamedataRoot, engine = ENGINE, env = process.env } = {}) {
  let source = null;
  const prepared = () => (source ||= clientSource(engine));
  return {
    dataRoot: dataRoot || env.DEKARON_DATA || prepared().dataRoot,
    gamedataRoot: gamedataRoot || env.DEKARON_GAMEDATA || prepared().gamedataRoot,
  };
}

/** The roots this host loaded its tables from (loadWorldData returns them as world.data.dataRoot / gamedataRoot), else the defaults. */
export function worldRoots(world, options = {}) {
  return defaultRoots({ ...options, dataRoot: world?.data?.dataRoot, gamedataRoot: world?.data?.gamedataRoot });
}

/**
 * events.json of this host: an explicit file when given; else the host's loaded event tables (world.data.eventData, built by
 * loadWorldData from <gamedataRoot>/events.json); else <the world's gamedata root>/events.json.
 */
export async function hostEvents(world, file, options = {}) {
  if (file) return JSON.parse(await fs.promises.readFile(file, 'utf8'));
  const ed = world?.data?.eventData;
  const loaded = ed?.ev && typeof ed.ev === 'object' ? ed.ev : ed?.modes ? { modes: ed.modes, maps: ed.maps || {} } : null;
  if (loaded) return loaded;
  return JSON.parse(await fs.promises.readFile(path.join(worldRoots(world, options).gamedataRoot, 'events.json'), 'utf8'));
}
