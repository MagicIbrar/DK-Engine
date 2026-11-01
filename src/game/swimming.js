// The native maplist uses aquaress.pre for its underwater maps. Movement speed
// alone is not enough: the Tower of Spell also uses 0.8 without being water.
export function isUnderwaterMap(row) {
  return String(row?.Preloading || '').trim().toLowerCase() === 'aquaress.pre';
}
