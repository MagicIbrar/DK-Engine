// Explicit operations only. Each method declares its input shape; unknown keys and wrong types are refused here,
// before any handler runs. There is no generic shell, file or SQL passthrough.
import {UserError} from './util.mjs';

const methods = new Map();
export function define(name, {input = v.object({}), run, timeoutMs = 20000, quiet = false}) {
  if (methods.has(name)) throw Error('Duplicate method ' + name);
  methods.set(name, {input, run, timeoutMs, quiet});
}
export function methodNames() { return [...methods.keys()].sort(); }
export async function call(name, params) {
  const m = methods.get(name);
  if (!m) throw new UserError('Unknown operation.', 404);
  const clean = m.input(params ?? {}, 'params');
  let timer;
  try {
    return await Promise.race([m.run(clean), new Promise((_, reject) => { timer = setTimeout(() => reject(new UserError('The operation took too long. Its state is unknown; refresh before retrying.', 504)), m.timeoutMs); })]);
  } finally { clearTimeout(timer); }
}
export const isQuiet = name => methods.get(name)?.quiet;

const fail = (path, msg) => { throw new UserError(`${path}: ${msg}`, 400, {field: path.replace(/^params\.?/, '')}); };
export const v = {
  object(shape, {extra = false} = {}) {
    return (value, path) => {
      if (!value || typeof value !== 'object' || Array.isArray(value)) fail(path, 'expected an object');
      if (!extra) for (const k of Object.keys(value)) if (!Object.hasOwn(shape, k)) fail(path + '.' + k, 'is not accepted');
      const out = {};
      for (const [k, check] of Object.entries(shape)) { const r = check(value[k], path + '.' + k); if (r !== undefined) out[k] = r; }
      return out;
    };
  },
  optional(check) { return (value, path) => value === undefined || value === null ? undefined : check(value, path); },
  string({min = 0, max = 512, pattern, trim = true, oneLine = true} = {}) {
    return (value, path) => {
      if (typeof value !== 'string') fail(path, 'expected text');
      const s = trim ? value.trim() : value;
      if (s.length < min) fail(path, min === 1 ? 'is required' : `needs at least ${min} characters`);
      if (s.length > max) fail(path, `allows at most ${max} characters`);
      if (oneLine && /[\x00-\x1f\x7f]/.test(s)) fail(path, 'contains control characters');
      if (pattern && !pattern.test(s)) fail(path, 'has an invalid format');
      return s;
    };
  },
  secret({min = 0, max = 128} = {}) { return v.string({min, max, trim: false}); },
  int({min = -(2 ** 31), max = 2 ** 31} = {}) { return (value, path) => { if (!Number.isInteger(value)) fail(path, 'expected a whole number'); if (value < min || value > max) fail(path, `must be between ${min} and ${max}`); return value; }; },
  number({min = -Infinity, max = Infinity} = {}) { return (value, path) => { if (typeof value !== 'number' || !Number.isFinite(value)) fail(path, 'expected a number'); if (value < min || value > max) fail(path, `must be between ${min} and ${max}`); return value; }; },
  bool() { return (value, path) => { if (typeof value !== 'boolean') fail(path, 'expected true or false'); return value; }; },
  enum(values) { return (value, path) => { if (!values.includes(value)) fail(path, 'must be one of ' + values.join(', ')); return value; }; },
  array(item, {max = 100} = {}) { return (value, path) => { if (!Array.isArray(value)) fail(path, 'expected a list'); if (value.length > max) fail(path, `allows at most ${max} entries`); return value.map((x, i) => item(x, `${path}[${i}]`)); }; },
  any() { return value => value; },
};
export const ACCOUNT_ID = /^[a-z0-9_-]{3,32}$/;
export const DB_NAME = /^[A-Za-z_][A-Za-z0-9_]{0,127}$/;
export const SQL_INSTANCE = /^(?:\.|\(local\)|localhost|[A-Za-z0-9][A-Za-z0-9.-]{0,252})(?:\\[A-Za-z0-9_][A-Za-z0-9_$-]{0,63})?(?:,[1-9][0-9]{0,4})?$/;
