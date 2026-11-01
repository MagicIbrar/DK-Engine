// Server transfer (one character) and server combination (whole store) between ENGINE-LOCAL account stores.
// Rules come only from Global client evidence (docs/SERVER-TRANSFER.md):
//   script/ui/game2/ui_servertransfer.txt, ui_servercombinationwnd.txt, msgbox/servertransfer/*.txt,
//   script/string/normal/stringtable_servermove.txt (<cate> 275; 1219 B = Global pack.d04 entry size).
// Anything Global does not show (mail, guild assets, dshop/cash, inventories on merge) is NOT invented: those cases refuse
// with code 6 "Unable to Move" + reason 'global-rule-unknown' unless the operator passes an explicit policy.
// Safety: a verified backup (save-backup.mjs) of every touched store before the first write; a journal makes each operation
// idempotent and resumable; stores are written tmp+rename. Never run against a live store while its server is running.
import fs from 'node:fs/promises'; import fss from 'node:fs'; import path from 'node:path'; import { createHash, randomBytes } from 'node:crypto';
import { characterRef } from './accounts/character-ref.mjs';
import { characterNameKey, normalizeCharacterName } from '../src/game/character-name.js';
import { createBackup, verifyBackup } from './save-backup.mjs';
import { readDurableAccountStore } from './accounts/entity-journal.mjs';

/** stringtable_servermove.txt <cate> 275 (Global). Unlisted codes are not used. */
export const SERVERMOVE_TEXT = Object.freeze({
  0: 'List of Available Servers', 1: 'Allowed to Move', 2: 'Do you agree to move your character?', 3: 'Confirm character movement',
  6: 'Unable to Move', 7: 'You must quit your current guild.', 8: 'Result', 9: 'Character Name Change', 110: 'Character Movement Request',
  120: 'I agree.', 200: '1. Selecting servers to combine', 210: 'Select servers to combine.', 220: 'Incorrect server selection.',
  240: 'The name has to be at least 4 characters.', 250: 'You may not use blanks.', 260: 'The maximum number of characters has been reached.',
  300: 'Changing character name', 310: 'Enter a new character name.', 320: 'That name is already in use!!',
  330: '%s contains prohibited words and therefore cannot be used.', 340: 'Cannot create more characters in the server.',
  400: 'Request character movement', 420: 'Cancel', 500: 'Move Successful', 501: 'Movement Failed', 502: 'More than 6 characters', 503: 'That name is already in use!!',
});
const fail = (code, extra = {}) => ({ ok: false, code, text: SERVERMOVE_TEXT[code], ...extra });
// Engine character cap (src/ui/frontend/select.js MAX_CHARACTERS = 5 rows x 2 pages). Global's 502 "More than 6 characters"
// has no visible trigger condition in the UI scripts -> kept as text only, not enforced (UNKNOWN).
export const ENGINE_MAX_CHARACTERS = 10;

/** Name rules shown by ServerTransferWnd / servercombinationWnd (275:240/250/330/320) + the engine's own name validation. */
export function checkMoveName(name, takenKeys, filter = []) {
  const s = String(name ?? '');
  if (/\s/.test(s)) return fail(250);
  if ([...s].length < 4) return fail(240);
  let n; try { n = normalizeCharacterName(s); } catch (e) { return fail(501, { reason: 'engine-name-rule', detail: e.message }); }
  const low = characterNameKey(n), bad = filter.find(w => w && low.includes(String(w).toLowerCase()));
  if (bad) return { ...fail(330), text: SERVERMOVE_TEXT[330].replace('%s', bad) };
  if (takenKeys.has(low)) return fail(320);
  return { ok: true, name: n };
}
const allNames = (db) => new Set(Object.values(db.users || {}).flatMap(u => (u.characters || []).map(c => characterNameKey(c.name))));
const sharedKeys = (db) => Object.keys(db || {}).filter(k => !['users', 'sessions', 'version', 'npcProfiles', 'localDemo'].includes(k));
function refUse(db, ref) { // which shared records mention this character (guild roster, mail, market, ...)
  const hits = []; for (const k of sharedKeys(db)) { const v = db[k]; if (v == null) continue;
    if (k === 'social') { for (const [sk, sv] of Object.entries(v || {})) if (sv != null && JSON.stringify(sv).includes(ref)) hits.push(`social.${sk}`); }
    else if (JSON.stringify(v).includes(ref)) hits.push(k); }
  return hits;
}

/** ServerTransferWnd eligibility. opts: {agree, accountId, characterId, newName?, filter?, sameStore?} */
export function checkTransfer(src, dst, { agree, accountId, characterId, newName = null, filter = [], sameStore = false }) {
  if (!agree) return fail(6, { reason: 'agreement-required', ui: 'pan_agree_check (275:120 "I agree.")' }); // btn_apply needs the check (exact UI gating UNKNOWN)
  if (sameStore) return fail(220);
  const user = src.users?.[accountId], c = user?.characters?.find(x => x.id === characterId);
  if (!c) return fail(501, { reason: 'character-not-found' });
  const ref = characterRef(accountId, characterId), uses = refUse(src, ref);
  if (uses.some(u => u === 'social.guilds')) return fail(7);
  if (uses.length) return fail(6, { reason: 'global-rule-unknown', detail: `character referenced by ${uses.join(', ')}; Global shows no rule for moving these` });
  const target = dst.users?.[accountId];
  if ((target?.characters?.length || 0) >= ENGINE_MAX_CHARACTERS) return fail(340);
  const taken = allNames(dst), name = newName ?? c.name;
  const nm = checkMoveName(name, taken, filter); if (!nm.ok) return { ...nm, needsRename: nm.code === 320, ui: 'edt_charname (275:300/310)' };
  return { ok: true, code: 1, text: SERVERMOVE_TEXT[1], name: nm.name, character: c };
}

/** servercombinationWnd: plan a full-store merge. Collisions need a rename (275:300/310/320). */
export function planMerge(src, dst, { renames = {}, filter = [], policy = {} } = {}) {
  const blockers = [], moves = [], needsRename = [];
  const srcShared = sharedKeys(src).filter(k => src[k] && (typeof src[k] !== 'object' || Object.keys(src[k]).length));
  if (srcShared.length && !policy.sharedState) blockers.push({ code: 6, reason: 'global-rule-unknown', detail: `source has shared state (${srcShared.join(', ')}): guilds/mail/market merge rules are not in the Global UI/strings` });
  const taken = allNames(dst); const planned = new Set(taken);
  for (const [accountId, u] of Object.entries(src.users || {})) {
    const existing = dst.users?.[accountId]?.characters?.length || 0; let add = 0;
    if (dst.users?.[accountId] && JSON.stringify(dst.users[accountId].auth ?? dst.users[accountId].salt ?? null) !== JSON.stringify(u.auth ?? u.salt ?? null))
      blockers.push({ code: 6, reason: 'global-rule-unknown', detail: `account id ${accountId} exists on both servers with different credentials` });
    for (const c of u.characters || []) {
      const key = `${accountId}/${c.id}`, want = renames[key] ?? c.name;
      if (dst.users?.[accountId]?.characters?.some(x => x.id === c.id)) { blockers.push({ code: 501, reason: 'character-id-collision', key }); continue; }
      const nm = checkMoveName(want, planned, filter);
      if (!nm.ok) { if (nm.code === 320) needsRename.push({ key, name: c.name, code: 320, text: SERVERMOVE_TEXT[320] }); else blockers.push({ ...nm, key }); continue; }
      if (existing + ++add > ENGINE_MAX_CHARACTERS) { blockers.push({ ...fail(340), key }); continue; }
      planned.add(characterNameKey(nm.name)); moves.push({ accountId, characterId: c.id, name: nm.name, renamed: nm.name !== c.name });
    }
  }
  return { ok: !blockers.length && !needsRename.length, blockers, needsRename, moves };
}

// ---------------------------------------------------------------- execution (backup + journal + atomic writes)
// An account store may carry a save journal (accounts/entity-journal.mjs, 4.1.0): read the durable state (checkpoint + journal)
// and write it back with journalSeq = the last applied journal line, so the next server start never replays those lines over it.
const storeSeq = new Map();
const readStore = async f => { const { state, seq } = await readDurableAccountStore(f); storeSeq.set(path.resolve(f), seq); return state; };
async function writeStore(f, v) { const seq = storeSeq.get(path.resolve(f)), value = seq ? { ...v, journalSeq: seq } : v; const t = `${f}.${randomBytes(6).toString('hex')}.tmp`; await fs.writeFile(t, JSON.stringify(value), { flag: 'wx', mode: 0o600 }); await fs.rename(t, f); }
const opId = (kind, args) => createHash('sha256').update(JSON.stringify([kind, args])).digest('hex').slice(0, 16);
async function journal(file) { try { return JSON.parse(await fs.readFile(file, 'utf8')); } catch { return { version: 1, ops: {} }; } }
async function step(jf, j, id, name, fn) { const op = j.ops[id] ||= { steps: [] }; if (op.steps.includes(name)) return false; await fn(); op.steps.push(name); await writeStore(jf, j); return true; }

async function run(kind, { srcFile, dstFile, backupDir, args, mutate, crashAfter = null }) {
  const jf = `${dstFile}.servermove-journal.json`, j = await journal(jf), id = opId(kind, { src: path.resolve(srcFile), dst: path.resolve(dstFile), ...args });
  if (j.ops[id]?.steps.includes('done')) return { ok: true, code: 500, text: SERVERMOVE_TEXT[500], id, resumed: false, alreadyDone: true };
  const resumed = !!j.ops[id];
  await step(jf, j, id, 'backup', async () => { const b = await createBackup({ sources: [{ kind: 'json', file: srcFile }, { kind: 'json', file: dstFile }], dest: backupDir });
    const v = await verifyBackup(b.set); if (!v.ok) throw new Error('pre-move backup failed verification'); j.ops[id].backup = b.set; });
  if (crashAfter === 'backup') throw new Error('simulated crash after backup');
  // dst first (marked with the op id so a re-run never adds twice), then src removal
  await step(jf, j, id, 'write-dst', async () => { const src = await readStore(srcFile), dst = await readStore(dstFile); mutate.dst(src, dst, id); await writeStore(dstFile, dst); });
  if (crashAfter === 'write-dst') throw new Error('simulated crash after write-dst');
  await step(jf, j, id, 'write-src', async () => { const src = await readStore(srcFile); mutate.src(src, id); await writeStore(srcFile, src); });
  await step(jf, j, id, 'done', async () => {});
  return { ok: true, code: 500, text: SERVERMOVE_TEXT[500], id, resumed, backup: j.ops[id].backup };
}
const addChar = (dst, accountId, srcUser, c, name, id) => {
  dst.users ||= {}; const u = dst.users[accountId] ||= { ...structuredClone(srcUser), characters: [] };
  if (u.characters.some(x => x.id === c.id)) return; // idempotent per character (planMerge refuses pre-existing id collisions)
  u.characters.push({ ...structuredClone(c), name, servermoveOp: id });
};
/** Move one character srcFile -> dstFile (same account id). Re-validates on the stores as they are now. */
export async function transferCharacter({ srcFile, dstFile, backupDir, accountId, characterId, newName = null, agree, filter = [], crashAfter = null }) {
  if (path.resolve(srcFile) === path.resolve(dstFile)) return fail(220);
  const args = { accountId, characterId, newName };
  const jf = `${dstFile}.servermove-journal.json`, j = await journal(jf), id = opId('transfer', { src: path.resolve(srcFile), dst: path.resolve(dstFile), ...args });
  if (!j.ops[id]) { const chk = checkTransfer(await readStore(srcFile), await readStore(dstFile), { agree, accountId, characterId, newName, filter }); if (!chk.ok) return chk; }
  return run('transfer', { srcFile, dstFile, backupDir, args, crashAfter, mutate: {
    dst: (src, dst, op) => { const u = src.users?.[accountId], c = u?.characters?.find(x => x.id === characterId);
      if (!c) { if (!dst.users?.[accountId]?.characters?.some(x => x.servermoveOp === op)) throw new Error('character vanished from source'); return; }
      addChar(dst, accountId, u, c, newName ?? c.name, op); },
    src: (src) => { const u = src.users?.[accountId]; if (u) u.characters = (u.characters || []).filter(x => x.id !== characterId); },
  } });
}
/** Combine srcFile into dstFile using a planMerge plan that must be ok. Shared (social) state is never merged. */
export async function mergeServers({ srcFile, dstFile, backupDir, renames = {}, filter = [], crashAfter = null }) {
  const args = { renames };
  const jf = `${dstFile}.servermove-journal.json`, j = await journal(jf), id = opId('merge', { src: path.resolve(srcFile), dst: path.resolve(dstFile), ...args });
  if (!j.ops[id]) { const plan = planMerge(await readStore(srcFile), await readStore(dstFile), { renames, filter }); if (!plan.ok) return { ...fail(501), plan }; j.plan = plan; }
  return run('merge', { srcFile, dstFile, backupDir, args, crashAfter, mutate: {
    dst: (src, dst, op) => { for (const [accountId, u] of Object.entries(src.users || {})) for (const c of u.characters || []) addChar(dst, accountId, u, c, renames[`${accountId}/${c.id}`] ?? c.name, op); },
    src: (src) => { for (const u of Object.values(src.users || {})) u.characters = []; src.combinedInto = path.basename(dstFile); },
  } });
}
