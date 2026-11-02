// NETX4: how many worker threads this machine may use (the owner's rule, overridable). Main thread always runs the game.
//   1 core -> 0 workers (single-thread path) | 2-4 cores -> 1 worker (2 threads total) | 5+ -> 2 (cap: measured 2026-10-29, a 3rd worker gave nothing at 200p)
// DK_CORES=<n> pretends the machine has n cores (tests); DK_WORKER_BUDGET=<n> sets the worker count directly.
import os from 'node:os';
export const coreCount = (env = process.env) => Number(env.DK_CORES) > 0 ? Math.floor(Number(env.DK_CORES)) : (typeof os.availableParallelism === 'function' ? os.availableParallelism() : os.cpus().length);
export function workerBudget(env = process.env) {
  if (env.DK_WORKER_BUDGET !== undefined && Number.isFinite(Number(env.DK_WORKER_BUDGET))) return Math.max(0, Math.min(2, Math.floor(Number(env.DK_WORKER_BUDGET))));
  const c = coreCount(env); return c <= 1 ? 0 : c <= 4 ? 1 : 2;
}
// Mind (CPU work) gets the first worker, Vault (persistence writer) the next one.
export const mindAllowed = (env = process.env) => env.DK_MIND === '1' && workerBudget(env) >= 1;
export const vaultAllowed = (env = process.env) => env.DK_VAULT === '1' && workerBudget(env) >= (mindAllowed(env) ? 2 : 1);
