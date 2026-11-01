// Cooperative time-slicing for asset work on the main thread (performance: no hitch when monsters spawn).
//
// Parsing meshes / skeletons / anims, building clips and decoding textures all run in promise continuations. When a
// few of them resolve together they can block the main thread for 50-100 ms, which shows as a hitch the moment a new
// monster type spawns. `breathe()` ends the current task once it has run longer than a budget, and waiting work is
// resumed ONE piece per macrotask (MessageChannel, which background tabs do not throttle, unlike setTimeout), so the
// browser can render frames in between. Cheap when there is nothing to do: it only yields after BUDGET_MS.

const BUDGET_MS = 6;

let resumeAt = -Infinity;     // when the current slice started
const queue = [];
let channel = null;
let posted = false;

function post() {
  if (posted) return;
  posted = true;
  if (typeof MessageChannel === 'function') {
    if (!channel) { channel = new MessageChannel(); channel.port1.onmessage = pump; }
    channel.port2.postMessage(0);
  } else setTimeout(pump, 0);
}

function pump() {
  posted = false;
  const r = queue.shift();
  if (queue.length) post();
  resumeAt = performance.now();
  if (r) r();
}

/** Resolve on a fresh macrotask (one waiter per task). */
export function nextTask() {
  return new Promise(resolve => { queue.push(resolve); post(); });
}

/**
 * Yield to the event loop when this slice of work has used its budget. Await it before a heavy synchronous step.
 * @param {number} [budgetMs]
 */
export function breathe(budgetMs = BUDGET_MS) {
  if (performance.now() - resumeAt < budgetMs) return Promise.resolve();
  return nextTask();
}
