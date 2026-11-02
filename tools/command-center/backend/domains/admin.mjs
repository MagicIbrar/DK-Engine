// World settings, capacity, player accounts (GM grants), character roster and builder tools.
// Running world: the private /api/launcher/* endpoints. Stopped world: the engine's offline prestart tool (same as today).
import {define, v, ACCOUNT_ID} from '../core/rpc.mjs';
import {UserError} from '../core/util.mjs';
import {event} from '../core/events.mjs';
import {world, refresh, launcherCall, offlineSettings} from './world.mjs';

const scopeOf = mode => mode === 'hosted' ? 'friends' : 'local';
async function running() { await refresh({maxAgeMs: 0}); return world.status === 'running' && world.control; }
const nameOk = s => typeof s === 'string' && s.trim() && s.length <= 64 && !/[\x00-\x1f\x7f]/.test(s);

async function getSettings(scope) {
  if (await running()) { const s = await launcherCall('settings'); return {source: 'running world', live: true, scope: scopeOf(world.mode), settings: s}; }
  const r = await offlineSettings('read', scope);
  if (r.running) throw new UserError('A world of this installation is running; refresh to use its live settings.', 409);
  return {source: 'saved settings (world stopped)', live: false, scope, reviewed: r.reviewed, settings: r.settings};
}
async function setSetting(scope, change) {
  const key = Object.keys(change)[0], value = change[key];
  if (key === 'name' && !nameOk(value)) throw new UserError('Use a server name of 1-64 printable characters.', 400, {field: 'name'});
  let saved;
  if (await running()) saved = await launcherCall('settings', {method: key === 'npcPopulation' ? 'PUT' : 'POST', body: {[key]: value}, timeoutMs: 15000});
  else saved = await offlineSettings('set', scope, {[key]: value});
  // Confirm what the server actually stored; never report success for a value that did not commit.
  const stored = key === 'starterPack' || key === 'fieldPk' ? saved[key] !== false : key === 'npcPlayers' ? saved[key] === true : key === 'npcLanguage' ? (saved.npcLanguage || 'en') : saved[key];
  const wanted = key === 'name' ? value.trim() : value;
  if (stored !== wanted && !(key === 'name' && saved.name === wanted)) throw new UserError('The saved setting did not match. Refresh settings before retrying.', 409);
  event('ok', 'world', `World setting saved: ${key}${key === 'name' ? ' = ' + saved.name : ''}.`);
  return {settings: saved, live: world.status === 'running'};
}
const MESSAGES = {starterPack: [`New characters on this server get the starter pack.`, `New characters get NO starter pack. Existing characters keep what they have.`], fieldPk: ['PK is on: players can attack each other with Ctrl on open PvP maps (never in safe zones, parties or guilds).', 'PK is off on this server: Ctrl does not attack players.'], npcPlayers: ['Experimental bots are on. Behaviour and performance are still a work in progress.', 'Bots are off. Their progress is saved.']};

define('world.settings.get', {input: v.object({scope: v.optional(v.enum(['local', 'friends']))}), timeoutMs: 40000, run: async ({scope = 'local'}) => getSettings(scope)});
define('world.settings.set', {input: v.object({scope: v.optional(v.enum(['local', 'friends'])), change: v.object({name: v.optional(v.string({min: 1, max: 64})), starterPack: v.optional(v.bool()), fieldPk: v.optional(v.bool()), npcPlayers: v.optional(v.bool()), npcLanguage: v.optional(v.enum(['en', 'es', 'pt', 'de', 'fr'])), npcPopulation: v.optional(v.int({min: 10, max: 100}))})}), timeoutMs: 40000, run: async ({scope = 'local', change}) => {
  if (Object.keys(change).length !== 1) throw new UserError('Change one setting at a time.');
  const r = await setSetting(scope, change); const k = Object.keys(change)[0];
  return {...r, message: MESSAGES[k] ? MESSAGES[k][change[k] ? 0 : 1] : k === 'name' ? 'Server name saved. Open game clients update their server display shortly.' : k === 'npcLanguage' ? 'Bot chat language saved. Common replies use this language; other replies stay in English.' : 'Saved.'};
}});
define('world.review.complete', {input: v.object({scope: v.enum(['local', 'friends'])}), timeoutMs: 30000, run: async ({scope}) => { const r = await offlineSettings('review', scope); event('ok', 'world', 'World settings reviewed for first start.'); return r; }});
define('world.capacity.get', {input: v.object({}), timeoutMs: 30000, run: async () => { if (await running()) { const r = await launcherCall('capacity'); return {...r, live: r.live || null, running: true}; } return {...(await offlineSettings('capacityRead', 'local')), live: null, running: false}; }});
define('world.capacity.set', {input: v.object({maxPlayers: v.optional(v.int({min: 1, max: 500})), memoryMB: v.optional(v.int({min: 0, max: 1048576})), uploadMbps: v.optional(v.number({min: 0, max: 10000})), uploadShare: v.optional(v.number({min: 0.1, max: 0.95}))}), timeoutMs: 30000, run: async input => {
  const live = await running();
  const reply = live ? await launcherCall('capacity', {method: 'POST', body: input}) : await offlineSettings('capacitySet', 'local', input);
  for (const k of ['maxPlayers', 'uploadMbps', 'uploadShare']) if (input[k] !== undefined && Number(reply.settings?.[k]) !== Number(input[k])) throw new UserError('Saved capacity did not match. Refresh before retrying.', 409);
  event('ok', 'world', 'Server capacity saved (player cap and upload apply now; memory at next start).');
  return {...reply, live: reply.live || null, running: live, applies: {maxPlayers: live ? 'now' : 'next-start', uploadMbps: live ? 'now' : 'next-start', uploadShare: live ? 'now' : 'next-start', memoryMB: 'next-start'}};
}});
define('world.accounts', {input: v.object({}), timeoutMs: 20000, run: async () => {
  if (!await running()) throw new UserError('Accounts are available only while your own world is running.', 409);
  if (!world.lastStatus?.accountsAvailable) throw new UserError('Account management requires the installation owner.', 403);
  const r = await launcherCall('accounts', {timeoutMs: 15000}); const seen = new Set();
  for (const row of r.accounts || []) { if (!ACCOUNT_ID.test(row.id) || row.id === 'admin' || !['gm', 'player'].includes(row.role) || seen.has(row.id)) throw new UserError('The account list could not be verified.'); seen.add(row.id); }
  return {accounts: r.accounts || [], storageMode: world.lastStatus?.storageMode || null};
}});
define('world.accounts.setRole', {input: v.object({account: v.string({min: 3, max: 32, pattern: ACCOUNT_ID}), role: v.enum(['gm', 'player'])}), timeoutMs: 20000, run: async ({account, role}) => {
  if (!await running()) throw new UserError('Start your own world first.', 409);
  if (account === 'admin') throw new UserError('Select a registered player account.');
  const r = await launcherCall('accounts', {method: 'POST', body: {account, role}, timeoutMs: 15000});
  if (r.account !== account || r.role !== role || r.leaseInvalidated !== true) throw new UserError('The permission change could not be verified. Refresh accounts.', 409);
  event('ok', 'world', `${role === 'gm' ? 'Granted Admin / GM / Dev to' : 'Revoked Admin / GM / Dev from'} ${account}. The player must re-enter their character.`);
  return {...r, message: `${role === 'gm' ? 'Granted Admin / GM / Dev to' : 'Revoked Admin / GM / Dev from'} ${account}. The player must re-enter their character.`};
}});
define('world.characters', {input: v.object({}), timeoutMs: 30000, run: async () => {
  if (!await running()) throw new UserError('The character roster is read from the running world.', 409);
  const r = await launcherCall('characters', {timeoutMs: 25000});
  return {characters: (r.characters || []).slice(0, 5000), note: 'Read-only roster from the world server (the authoritative record). Characters are changed only through gameplay and GM services, never edited here.'};
}});
define('world.tool', {input: v.object({tool: v.enum(['itembuilder', 'mapbuilder'])}), run: async ({tool}) => {
  if (!await running()) throw new UserError('Start the world, sign in with your GM account and enter a character first.', 409);
  const r = await launcherCall('tool', {method: 'POST', body: {tool}});
  if (!r.queued) throw new UserError('The server did not accept the builder request.');
  event('info', 'content', `Opening ${tool === 'itembuilder' ? 'Item Builder' : 'Map Builder'} in primary account ${r.primary}.`);
  return {...r, message: `Opening ${tool === 'itembuilder' ? 'Item Builder' : 'Map Builder'} in primary account ${r.primary}.`};
}});
