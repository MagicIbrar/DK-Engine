// Shared-world Consignment / Agency adapter (server/world/consignment.mjs). The Middleman windows in
// src/systems/shops/search.js read network.consignment while online: listings, receipts and the policy come from the
// private snapshot, the market board from the server 'list' intent, and every register / cancel / buy / receive is
// an intent the host commits atomically with the bag and DIL. Nothing here changes the local save.
import {randomUUID} from './web-crypto.js';
const BLANK = { available: false, revision: 0, listings: [], receipts: [] };

export function installSharedConsignment(game, network) {
  let busy = false, disposed = false, seen = null;
  const st = () => network.consign || BLANK;
  async function send(operation, fields = {}) {
    if (disposed || busy) return null;
    const s = st();
    if (!s.available) { game.chat?.system?.('This server has no durable consignment service.', 'err'); return null; }
    busy = true;
    try {
      const intent = operation === 'list' ? {} : { revision: s.revision, requestId: randomUUID() };
      const result = await network.action('consign', { operation, ...intent, ...fields });
      return result ? (result.consignResult ?? {}) : null;
    } finally { busy = false; }
  }
  network.consignment = {
    available: () => !!st().available,
    get busy() { return busy; },
    policy: () => st().policy || null,
    listings: () => st().listings || [],
    receipts: () => st().receipts || [],
    async search() { const r = await send('list'); return r ? r.listings || [] : null; },
    register: (uid, count, unit) => send('register', { uid, count, unit }),
    cancel: id => send('cancel', { id }),
    buy: (id, count) => send('buy', { id, count }),
    receive: id => send('receive', id === true ? { all: true } : { id }),
  };
  const snapshot = network._snapshot.bind(network);
  network._snapshot = record => {
    if (network.disposed || Number(record?.sequence) < network.sequence) return;
    network.consign = record?.consign || BLANK;
    snapshot(record);
    // a sale or an expiry that happened while the windows were closed (the seller may have been offline)
    const ids = new Set(st().receipts.map(r => r.id));
    const fresh = seen ? st().receipts.filter(r => !seen.has(r.id)) : [];
    seen = ids;
    game.events?.emit?.('consign', { fresh });
  };
  const dispose = network.dispose.bind(network);
  network.dispose = () => { disposed = true; network.consign = null; network.consignment = null; dispose(); };
  return network.consignment;
}