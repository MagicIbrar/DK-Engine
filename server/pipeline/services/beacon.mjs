// BEACON worker (Link + Beacon, Phase B step 3): the presence directory, off Realm's thread.
//   beacon.presence  (publish, STATE lane, from Realm)   full presence table, newest wins
//   beacon.where     {name}|{characterId}  -> {online, map, channel, ...} | {online:false}
//   beacon.population                       -> per-channel / per-map player counts
//   link.account     {account}             -> {online, characters:[...]}
//   link.count                              -> number of characters online
//   beacon.stats                            -> directory health (rows, age of the last table)
// Read-only: Realm stays authoritative; a query never touches game state. Clean-room (no official server code).
import { connectWorker } from '../worker-endpoint.mjs';
import { createDirectory } from './beacon-directory.mjs';
const dir = createDirectory();
const ep = connectWorker('Beacon', {
  'beacon.presence': table => { dir.load(table); },
  'beacon.where': q => dir.where(q || {}),
  'beacon.population': () => dir.population(),
  'beacon.stats': () => dir.stats(),
  'link.account': q => dir.account(q || {}),
  'link.count': () => dir.count(),
}, ['beacon.*', 'link.*']);
ep.publish('hub.ready', { service: 'Beacon' });
