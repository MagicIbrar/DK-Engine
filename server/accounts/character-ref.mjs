import { createHash } from 'node:crypto';

// Character lookup keys do not expose account names, sessions or storage paths.
// PERF-NET: the key is a pure function of (account, character); it was re-hashed (sha256) for every player row of every
// snapshot (~40% of a 200-player tick). Memoized per (account, character) without building a string; output is byte-identical.
const refs = new Map(); let size = 0;
export const characterRef = (account, character) => {
  let byChar = refs.get(account);
  let ref = byChar?.get(character);
  if (ref === undefined) {
    ref = createHash('sha256').update(JSON.stringify([account, character])).digest('hex');
    if (size >= 20000) { refs.clear(); size = 0; byChar = undefined; }
    if (!byChar) refs.set(account, byChar = new Map());
    byChar.set(character, ref); size++;
  }
  return ref;
};