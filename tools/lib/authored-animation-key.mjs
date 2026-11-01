import fs from 'node:fs';
import path from 'node:path';

/** Correct only an omitted .anim suffix or whitespace immediately before it.
 * The authored exact path wins. Multiple case-insensitive matches are refused;
 * no spelling, basename, directory or animation-name substitutions are made. */
export function resolveAuthoredAnimationKey(authored, lookup) {
  const key = String(authored || '').replace(/\\/g, '/');
  if (!key.startsWith('anim/') || key.split('/').some(part => part === '..' || part === '.')) return {key:null, reason:'invalid'};
  const exact = [...new Set(lookup(key))];
  if (exact.length) return exact.length === 1 ? {key:exact[0], reason:'exact'} : {key:null, reason:'ambiguous'};
  const base = key.slice(key.lastIndexOf('/') + 1);
  const candidates = [];
  if (/\s+\.anim$/i.test(base)) candidates.push(key.replace(/\s+\.anim$/i, '.anim'));
  if (base && !base.includes('.') && !/\s$/.test(base)) candidates.push(key + '.anim');
  const found = [...new Set(candidates.flatMap(candidate => lookup(candidate)))];
  return found.length === 1 ? {key:found[0], reason:'extension'} : {key:null, reason:found.length ? 'ambiguous' : 'missing'};
}

/** Reads only the exact parent directories referenced by authored clip paths. */
export function createAuthoredAnimationLookup(dataRoot) {
  const directories = new Map();
  return key => {
    const dir = path.posix.dirname(key), name = path.posix.basename(key).toLowerCase();
    if (!directories.has(dir)) {
      const names = new Map();
      try {
        for (const entry of fs.readdirSync(path.join(dataRoot, dir), {withFileTypes:true})) {
          if (!entry.isFile()) continue;
          const fold = entry.name.toLowerCase();
          if (!names.has(fold)) names.set(fold, []);
          names.get(fold).push(`${dir}/${entry.name}`);
        }
      } catch (error) {
        if (error.code !== 'ENOENT') throw error;
      }
      directories.set(dir, names);
    }
    return directories.get(dir).get(name) || [];
  };
}
