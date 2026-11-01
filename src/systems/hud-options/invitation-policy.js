// Client-side invitation preferences use each feature's existing authenticated response action.
// Server validation remains authoritative. Failed declines retry on a later snapshot, at most once a second.
const attempts = new WeakMap();
export function applyInvitationPreference(game, key, id, decline) {
  if (!id || game.options?.get?.(key) !== true) return false;
  let states = attempts.get(game); if (!states) attempts.set(game, states = new Map());
  const now = performance.now(), old = states.get(key);
  if (old?.id === id && (old.pending || old.done || now < old.retryAt)) return true;
  const attempt = { id, pending: true, done: false, retryAt: now + 1000 };
  states.set(key, attempt);
  // Invoke immediately so a replacement invitation cannot be accidentally declined by a deferred callback.
  try {
    Promise.resolve(decline()).then(result => { attempt.done = !!result; }, () => {}).finally(() => { attempt.pending = false; });
  } catch { attempt.pending = false; }
  return true;
}

export const declineBlockedInvitation = applyInvitationPreference;
