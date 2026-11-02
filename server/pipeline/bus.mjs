// MAIN PIPELINE (bus core). One router that every Dekaron service connects to; services never talk to each other directly.
// Wire format (structured clone over MessagePort / advanced-serialization IPC, never JSON on the hot path):
//   batch  = {b:[msg...], s:seq}        one postMessage per flush (fewer crossings than one per message)
//   msg    = {k:topic, p:prio, d:data, i?:requestId, r?:replyToId, c?:coalesceKey, f?:fromService, e?:error}
//   ack    = {a:seq}                    receiver -> hub after it handled a batch (credit-based backpressure)
//   op     = {o:'hello'|'sub', ...}     control
// Priorities: 0 = PING/INPUT/CONTROL (never queued, never blocked by credits), 1 = REQUEST/REPLY (bounded, rejects when full),
//             2 = STATE/STATS (coalesced by key: only the newest value per key is kept), 3 = BULK/LOG (bounded, drop-oldest + counted).
import { performance } from 'node:perf_hooks';
export const PRIO = Object.freeze({ REALTIME: 0, REQUEST: 1, STATE: 2, BULK: 3 });
const DEFAULT_LIMITS = { window: 8, batch: 512, requestCap: 10000, stateCap: 4096, bulkCap: 20000 };

/** One outbound link with priority lanes + credit window. `post(batch)` does the actual crossing. */
export function createLink(name, post, limits = {}) {
  const L = { ...DEFAULT_LIMITS, ...limits };
  const lanes = [null, [], new Map(), []];
  let inflight = 0, seq = 0, scheduled = false, closed = false;
  const stats = { sent: 0, batches: 0, rejected: 0, coalesced: 0, dropped: 0, maxDepth: 0, stalls: 0 };
  const depth = () => lanes[1].length + lanes[2].size + lanes[3].length;
  const schedule = () => { if (!scheduled && !closed) { scheduled = true; setImmediate(flush); } };
  function flush() {
    scheduled = false; if (closed) return;
    while (inflight < L.window && depth()) {
      const out = [];
      while (out.length < L.batch && lanes[1].length) out.push(lanes[1].shift());
      if (out.length < L.batch && lanes[2].size) for (const [key, m] of lanes[2]) { lanes[2].delete(key); out.push(m); if (out.length >= L.batch) break; }
      while (out.length < L.batch && lanes[3].length) out.push(lanes[3].shift());
      if (!out.length) break;
      inflight++; stats.batches++; stats.sent += out.length;
      try { post({ b: out, s: ++seq }); } catch { closed = true; return; }
    }
    if (depth() && inflight >= L.window) stats.stalls++;
  }
  return {
    name, stats, get depth() { return depth(); }, get inflight() { return inflight; },
    /** Returns false when the message was refused (request lane full). */
    send(m) {
      if (closed) return false;
      const p = m.p ?? PRIO.REQUEST;
      if (p === PRIO.REALTIME) { stats.sent++; try { post({ b: [m], s: 0 }); } catch { closed = true; return false; } return true; }
      if (p === PRIO.REQUEST) { if (lanes[1].length >= L.requestCap) { stats.rejected++; return false; } lanes[1].push(m); }
      else if (p === PRIO.STATE) { const key = m.c ?? m.k; if (lanes[2].has(key)) { lanes[2].delete(key); stats.coalesced++; } else if (lanes[2].size >= L.stateCap) { const first = lanes[2].keys().next().value; lanes[2].delete(first); stats.dropped++; } lanes[2].set(key, m); }
      else { if (lanes[3].length >= L.bulkCap) { lanes[3].shift(); stats.dropped++; } lanes[3].push(m); }
      const d = depth(); if (d > stats.maxDepth) stats.maxDepth = d;
      schedule(); return true;
    },
    ack(s) { if (s > 0 && inflight > 0) inflight--; schedule(); },
    close() { closed = true; },
  };
}

/** The hub: owns every link, routes by topic, replies by request id. Runs on a thread that does nothing else. */
export function createHub({ log = () => {} } = {}) {
  const services = new Map();          // name -> {link, topics:Set}
  const subs = new Map();              // topic -> [serviceName]
  const pending = new Map();           // requestId -> {from, at}
  const started = performance.now();
  const stats = { routed: 0, unrouted: 0, requests: 0, replies: 0, routeNs: 0 };
  function match(topic) {
    const exact = subs.get(topic); if (exact?.length) return exact;
    const dot = topic.indexOf('.'); return dot > 0 ? subs.get(topic.slice(0, dot) + '.*') || [] : [];
  }
  function deliver(from, m) {
    const t0 = performance.now(); stats.routed++;
    if (m.r !== undefined) { const req = pending.get(m.r); if (req) { pending.delete(m.r); stats.replies++; services.get(req.from)?.link.send(m); } return; }
    const targets = match(m.k);
    if (!targets.length) { stats.unrouted++; if (m.i !== undefined) services.get(from)?.link.send({ k: m.k, p: PRIO.REALTIME, r: m.i, e: 'no service for ' + m.k }); return; }
    m.f = from;
    if (m.i !== undefined) {           // request: first subscriber answers
      stats.requests++; pending.set(m.i, { from, at: Date.now() });
      if (!services.get(targets[0])?.link.send(m)) { pending.delete(m.i); services.get(from)?.link.send({ k: m.k, p: PRIO.REALTIME, r: m.i, e: 'BUSY: ' + targets[0] + ' request queue full' }); }
    } else for (const name of targets) if (name !== from) services.get(name)?.link.send(m);
    stats.routeNs += (performance.now() - t0) * 1e6;
  }
  function receive(name, packet) {
    if (packet.a !== undefined) { services.get(name)?.link.ack(packet.a); return; }
    if (packet.o === 'sub') { const s = services.get(name); for (const t of packet.topics) { s.topics.add(t); const list = subs.get(t) || []; if (!list.includes(name)) list.push(name); subs.set(t, list); } return; }
    if (packet.b) { for (const m of packet.b) deliver(name, m); if (packet.s > 0) services.get(name)?.post({ a: packet.s }); }
  }
  setInterval(() => { const now = Date.now(); for (const [id, r] of pending) if (now - r.at > 30000) pending.delete(id); }, 5000).unref();
  return {
    stats, services,
    /** Attach a service. `post` sends a packet to it; call the returned function with every packet it sends. */
    attach(name, post, limits) {
      if (services.has(name)) throw new Error('service already attached: ' + name);
      services.set(name, { link: createLink(name, post, limits), post: p => { try { post(p); } catch {} }, topics: new Set(), at: Date.now() });
      log('pipeline: service attached ' + name);
      return packet => receive(name, packet);
    },
    detach(name) { const s = services.get(name); if (!s) return; s.link.close(); for (const t of s.topics) subs.set(t, (subs.get(t) || []).filter(n => n !== name)); services.delete(name); log('pipeline: service detached ' + name); },
    /** The hub can publish too (control, stats fan-out). */
    publish(k, d, p = PRIO.STATE, c) { deliver('hub', { k, d, p, c }); },
    snapshot() {
      const out = { uptimeS: Math.round((performance.now() - started) / 1000), ...stats, routeUsAvg: stats.routed ? +(stats.routeNs / stats.routed / 1000).toFixed(2) : 0, pending: pending.size, services: {} };
      delete out.routeNs;
      for (const [n, s] of services) out.services[n] = { topics: [...s.topics], depth: s.link.depth, inflight: s.link.inflight, ...s.link.stats };
      return out;
    },
  };
}

/** Service side of a link (worker thread or child process). `post` crosses to the hub; call `onPacket` for every hub packet. */
export function createEndpoint(name, post, { handlers = {}, limits } = {}) {
  const out = createLink(name + '>hub', post, limits);
  const waiting = new Map(); let nextId = 1;
  const prefix = (Math.random() * 1e9 | 0).toString(36) + ':';
  async function handle(m) {
    const fn = handlers[m.k] || handlers[m.k.slice(0, m.k.indexOf('.') + 1) + '*'];
    if (m.i === undefined) { try { await fn?.(m.d, m); } catch (e) { console.error('[pipeline ' + name + '] ' + m.k + ' failed:', e?.message || e); } return; }
    try { const v = await fn(m.d, m); out.send({ k: m.k, p: m.p === 0 ? 0 : PRIO.REQUEST, r: m.i, d: v }); }
    catch (e) { out.send({ k: m.k, p: PRIO.REQUEST, r: m.i, e: String(e?.message || e) }); }
  }
  return {
    link: out,
    onPacket(packet) {
      if (packet.a !== undefined) { out.ack(packet.a); return; }
      if (!packet.b) return;
      const work = [];
      for (const m of packet.b) {
        if (m.r !== undefined) { const w = waiting.get(m.r); if (w) { waiting.delete(m.r); clearTimeout(w.t); m.e ? w.reject(new Error(m.e)) : w.resolve(m.d); } continue; }
        work.push(handle(m));
      }
      if (packet.s > 0) { if (work.length) Promise.allSettled(work).then(() => post({ a: packet.s })); else post({ a: packet.s }); }
    },
    subscribe(topics) { post({ o: 'sub', topics }); },
    publish(k, d, p = PRIO.STATE, c) { return out.send({ k, d, p, c }); },
    request(k, d, { p = PRIO.REQUEST, timeoutMs = 5000 } = {}) {
      const i = prefix + nextId++;
      return new Promise((resolve, reject) => {
        const t = setTimeout(() => { waiting.delete(i); reject(new Error('pipeline request timed out: ' + k)); }, timeoutMs); t.unref?.();
        waiting.set(i, { resolve, reject, t });
        if (!out.send({ k, d, p, i })) { clearTimeout(t); waiting.delete(i); reject(new Error('BUSY: pipeline send queue full')); }
      });
    },
  };
}
