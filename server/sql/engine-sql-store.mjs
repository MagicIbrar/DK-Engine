// SQL system of record for the engine's accounts and characters.
//  * hydrate(state): at boot, merge SQL into the engine's in-memory account state (higher account `revision` wins; ties keep the file).
//  * mirror(prev, next): after every atomic file write, queue the accounts whose content changed and write them to SQL in the
//    background (write-behind, coalesced, retried). With strict=true the caller awaits the write instead.
// The engine's own atomic JSON store stays the working copy on disk, so a SQL outage never stops the game; nothing is lost because the
// next successful write (or hydrate/reconcile at the next boot) brings SQL level again.
import { createHash } from 'node:crypto';
import { assertIdentifier, DEFAULT_ENGINE_DB } from './engine-schema.mjs';

const sha = (text) => createHash('sha1').update(text).digest('hex');
const isNpc = (id) => /^npc_[0-9a-f]{32}$/.test(id);
const num = (v, d = null) => (Number.isFinite(Number(v)) ? Number(v) : d);

/** Everything on a user object except the characters array (kept in engine_account.extras_json). */
function splitUser(user) {
  const { id, salt, digest, created, revision, characters, legacyUserNo, ...extras } = user;
  return { id, salt, digest, created, revision, legacyUserNo: legacyUserNo ?? null, characters: Array.isArray(characters) ? characters : [], extras };
}

function characterRow(ch, slot) {
  return {
    id: String(ch.id), slot, name: String(ch.name ?? ''), cls: Math.trunc(num(ch.classIndex, 0)), level: Math.trunc(num(ch.level, 1)),
    exp: num(ch.exp), dil: num(ch.dil), map: ch.map === undefined || ch.map === null ? null : Math.trunc(num(ch.map, 0)),
    x: num(ch.pos?.x), z: num(ch.pos?.z), lp: num(ch.lastPlayed), legacy: ch.legacyCharacterNo ?? null, profile: JSON.stringify(ch),
  };
}

// PERSIST-PERF: one round trip and one transaction (one log flush) for every queued account. Only characters whose JSON
// changed since the last confirmed write are sent; extra/cash projections are upserted for exactly those characters.
const BATCH_SQL = `SET XACT_ABORT ON; SET NOCOUNT ON; BEGIN TRAN;
  DECLARE @a TABLE (id nvarchar(40) PRIMARY KEY, has_acct bit, salt nvarchar(64), digest nvarchar(256), created bigint, revision int, legacy varchar(20), extras nvarchar(max), keep nvarchar(max));
  INSERT @a SELECT id, has_acct, salt, digest, created, revision, legacy, extras, keep FROM OPENJSON(@b) WITH (id nvarchar(40) '$.id', has_acct bit '$.hasAcct',
    salt nvarchar(64) '$.salt', digest nvarchar(256) '$.digest', created bigint '$.created', revision int '$.revision', legacy varchar(20) '$.legacy',
    extras nvarchar(max) '$.extras', keep nvarchar(max) '$.keep' AS JSON);
  UPDATE t SET salt=a.salt, digest=a.digest, created_ms=a.created, revision=a.revision, legacy_user_no=a.legacy, extras_json=a.extras, updated_at=SYSUTCDATETIME()
    FROM dbo.engine_account t JOIN @a a ON a.id=t.account_id WHERE a.has_acct=1;
  INSERT dbo.engine_account (account_id, salt, digest, created_ms, revision, legacy_user_no, extras_json)
    SELECT id, salt, digest, created, revision, legacy, extras FROM @a a WHERE a.has_acct=1 AND NOT EXISTS (SELECT 1 FROM dbo.engine_account t WHERE t.account_id=a.id);
  DECLARE @gone TABLE (id nvarchar(100) PRIMARY KEY);
  INSERT @gone SELECT c.character_id FROM dbo.engine_character c JOIN @a a ON a.id=c.account_id
    WHERE c.character_id NOT IN (SELECT value FROM OPENJSON(a.keep));
  DELETE x FROM dbo.engine_character_extra x JOIN @gone g ON g.id=x.character_id;
  DELETE x FROM dbo.engine_cash x JOIN @gone g ON g.id=x.character_id;
  DELETE c FROM dbo.engine_character c JOIN @gone g ON g.id=c.character_id;
  DECLARE @c TABLE (id nvarchar(100) PRIMARY KEY, acct nvarchar(40), slot int, name nvarchar(64), cls int, level int, exp bigint, dil bigint, map int, x float, z float, lp bigint, legacy varchar(18), profile nvarchar(max));
  INSERT @c SELECT c.id, a.id, c.slot, c.name, c.cls, c.level, c.exp, c.dil, c.map, c.x, c.z, c.lp, c.legacy, c.profile FROM OPENJSON(@b) WITH (id nvarchar(40) '$.id', chars nvarchar(max) '$.chars' AS JSON) a
    CROSS APPLY OPENJSON(a.chars) WITH (id nvarchar(100) '$.id', slot int '$.slot', name nvarchar(64) '$.name', cls int '$.cls', level int '$.level', exp bigint '$.exp', dil bigint '$.dil',
      map int '$.map', x float '$.x', z float '$.z', lp bigint '$.lp', legacy varchar(18) '$.legacy', profile nvarchar(max) '$.profile') c;
  UPDATE t SET account_id=c.acct, slot=c.slot, name=c.name, class_index=c.cls, level=c.level, exp=c.exp, dil=c.dil, map_index=c.map, pos_x=c.x, pos_z=c.z,
         last_played_ms=c.lp, legacy_character_no=c.legacy, profile_json=c.profile, updated_at=SYSUTCDATETIME() FROM dbo.engine_character t JOIN @c c ON c.id=t.character_id;
  INSERT dbo.engine_character (character_id, account_id, slot, name, class_index, level, exp, dil, map_index, pos_x, pos_z, last_played_ms, legacy_character_no, profile_json)
    SELECT id, acct, slot, name, cls, level, exp, dil, map, x, z, lp, legacy, profile FROM @c c WHERE NOT EXISTS (SELECT 1 FROM dbo.engine_character t WHERE t.character_id=c.id);
  UPDATE x SET inventory_json=COALESCE(JSON_QUERY(c.profile,'$.inventory'),N'[]'), storage_json=COALESCE(JSON_QUERY(c.profile,'$.storage'),N'[]'),
         equipment_json=COALESCE(JSON_QUERY(c.profile,'$.equip'),N'{}'), updated_at=SYSUTCDATETIME() FROM dbo.engine_character_extra x JOIN @c c ON c.id=x.character_id;
  INSERT dbo.engine_character_extra (character_id, inventory_json, storage_json, equipment_json)
    SELECT id, COALESCE(JSON_QUERY(profile,'$.inventory'),N'[]'), COALESCE(JSON_QUERY(profile,'$.storage'),N'[]'), COALESCE(JSON_QUERY(profile,'$.equip'),N'{}')
    FROM @c c WHERE NOT EXISTS (SELECT 1 FROM dbo.engine_character_extra x WHERE x.character_id=c.id);
  UPDATE x SET dkc=COALESCE(TRY_CONVERT(bigint,JSON_VALUE(c.profile,'$.dkc')),0), vip_points=COALESCE(TRY_CONVERT(bigint,JSON_VALUE(c.profile,'$.vipPoints')),0),
         cash_inventory_json=COALESCE(JSON_QUERY(c.profile,'$.cashInv'),N'[]'), updated_at=SYSUTCDATETIME() FROM dbo.engine_cash x JOIN @c c ON c.id=x.character_id;
  INSERT dbo.engine_cash (character_id, dkc, vip_points, cash_inventory_json)
    SELECT id, COALESCE(TRY_CONVERT(bigint,JSON_VALUE(profile,'$.dkc')),0), COALESCE(TRY_CONVERT(bigint,JSON_VALUE(profile,'$.vipPoints')),0), COALESCE(JSON_QUERY(profile,'$.cashInv'),N'[]')
    FROM @c c WHERE NOT EXISTS (SELECT 1 FROM dbo.engine_cash x WHERE x.character_id=c.id);
  IF @s IS NOT NULL BEGIN UPDATE dbo.engine_social SET json=@s, updated_at=SYSUTCDATETIME() WHERE id=1; IF @@ROWCOUNT=0 INSERT dbo.engine_social (id, json) VALUES (1, @s); END
  COMMIT;`;
const MAX_BATCH = 64;

export function createEngineSqlStore({ sql, database = DEFAULT_ENGINE_DB, strict = false, log = () => {}, retryMs = 2000, maxRetryMs = 30000,
  afterAccountWrite = null, onLink = null } = {}) {
  // afterAccountWrite(user) -> { [characterId]: legacyCharacterNo } | void : runs after an account reached SQL (legacy mirror). It never
  // fails the write: legacy trouble is counted in status() and logged, the engine keeps playing.
  // onLink(characterId, legacyCharacterNo): told about every known engine<->legacy character link when hydrating.
  assertIdentifier(database);
  const db = { db: database };
  const mirrored = new Map();       // account id -> hash of the last version known to be in SQL
  const mirroredParts = new Map();  // account id -> { acct: hash of the account fields, chars: Map(characterId -> hash) } confirmed in SQL
  let waiters = [];                  // strict callers: resolved when the batch holding their snapshot commits
  let socialHash = null;
  const pending = new Map();        // account id -> { json (user JSON), hash }
  let pendingSocial = null;         // { json, hash }
  let pump = null, timer = null, failures = 0;
  const stats = { written: 0, failures: 0, legacyErrors: 0, lastError: null, lastLegacyError: null, lastOkAt: null, hydrated: null };

  async function legacyStep(user) {
    if (!afterAccountWrite) return;
    try {
      const links = await afterAccountWrite(user);
      for (const [characterId, no] of Object.entries(links || {}))
        await sql.run('UPDATE dbo.engine_character SET legacy_character_no=@no WHERE character_id=@id AND (legacy_character_no IS NULL OR legacy_character_no<>@no)', { no, id: characterId }, db);
    } catch (error) {
      stats.legacyErrors++; stats.lastLegacyError = String(error?.message || error); log(`[sql] legacy mirror failed: ${stats.lastLegacyError}`);
    }
  }

  async function writeAccount(userJson) {
    const user = JSON.parse(userJson), p = splitUser(user);
    const chars = JSON.stringify(p.characters.map((c, i) => characterRow(c, i)));
    await sql.run(
      `SET XACT_ABORT ON; BEGIN TRAN;
       UPDATE dbo.engine_account SET salt=@salt, digest=@digest, created_ms=@created, revision=@revision, legacy_user_no=@legacy, extras_json=@extras, updated_at=SYSUTCDATETIME() WHERE account_id=@id;
       IF @@ROWCOUNT = 0 INSERT dbo.engine_account (account_id, salt, digest, created_ms, revision, legacy_user_no, extras_json) VALUES (@id,@salt,@digest,@created,@revision,@legacy,@extras);
       DECLARE @c TABLE (id nvarchar(100), slot int, name nvarchar(64), cls int, level int, exp bigint, dil bigint, map int, x float, z float, lp bigint, legacy varchar(18), profile nvarchar(max));
       INSERT @c SELECT id, slot, name, cls, level, exp, dil, map, x, z, lp, legacy, profile FROM OPENJSON(@chars)
         WITH (id nvarchar(100) '$.id', slot int '$.slot', name nvarchar(64) '$.name', cls int '$.cls', level int '$.level', exp bigint '$.exp', dil bigint '$.dil',
               map int '$.map', x float '$.x', z float '$.z', lp bigint '$.lp', legacy varchar(18) '$.legacy', profile nvarchar(max) '$.profile');
       DELETE x FROM dbo.engine_character_extra x JOIN dbo.engine_character c ON c.character_id=x.character_id WHERE c.account_id=@id;
       DELETE x FROM dbo.engine_cash x JOIN dbo.engine_character c ON c.character_id=x.character_id WHERE c.account_id=@id;
       DELETE FROM dbo.engine_character WHERE account_id=@id AND character_id NOT IN (SELECT id FROM @c);
       UPDATE t SET account_id=@id, slot=c.slot, name=c.name, class_index=c.cls, level=c.level, exp=c.exp, dil=c.dil, map_index=c.map, pos_x=c.x, pos_z=c.z,
              last_played_ms=c.lp, legacy_character_no=c.legacy, profile_json=c.profile, updated_at=SYSUTCDATETIME()
         FROM dbo.engine_character t JOIN @c c ON c.id = t.character_id;
       INSERT dbo.engine_character (character_id, account_id, slot, name, class_index, level, exp, dil, map_index, pos_x, pos_z, last_played_ms, legacy_character_no, profile_json)
         SELECT id, @id, slot, name, cls, level, exp, dil, map, x, z, lp, legacy, profile FROM @c c WHERE NOT EXISTS (SELECT 1 FROM dbo.engine_character t WHERE t.character_id = c.id);
       INSERT dbo.engine_character_extra (character_id, inventory_json, storage_json, equipment_json)
         SELECT id, COALESCE(JSON_QUERY(profile,'$.inventory'),N'[]'), COALESCE(JSON_QUERY(profile,'$.storage'),N'[]'),
           COALESCE(JSON_QUERY(profile,'$.equip'),N'{}') FROM @c;
       INSERT dbo.engine_cash (character_id, dkc, vip_points, cash_inventory_json)
         SELECT id, COALESCE(TRY_CONVERT(bigint,JSON_VALUE(profile,'$.dkc')),0),
           COALESCE(TRY_CONVERT(bigint,JSON_VALUE(profile,'$.vipPoints')),0),
           COALESCE(JSON_QUERY(profile,'$.cashInv'),N'[]') FROM @c;
       COMMIT;`,
      { id: p.id, salt: p.salt ?? null, digest: p.digest ?? null, created: { $big: String(Math.trunc(num(p.created, 0))) }, revision: Math.trunc(num(p.revision, 0)),
        legacy: p.legacyUserNo, extras: JSON.stringify(p.extras), chars }, { ...db, timeout: 120 });
  }
  function partsOf(user) {
    const p = splitUser(user), rows = p.characters.map((c, i) => characterRow(c, i));
    const acct = { salt: p.salt ?? null, digest: p.digest ?? null, created: Math.trunc(num(p.created, 0)), revision: Math.trunc(num(p.revision, 0)), legacy: p.legacyUserNo, extras: JSON.stringify(p.extras) };
    return { id: p.id, acct, acctHash: sha(JSON.stringify(acct)), rows, rowHash: rows.map(r => sha(JSON.stringify(r))) };
  }
  function rememberParts(user) { const q = partsOf(user); mirroredParts.set(q.id, { acct: q.acctHash, chars: new Map(q.rows.map((r, i) => [r.id, q.rowHash[i]])) }); }
  async function writeBatch(items, social) {
    const parts = items.map(([, it]) => partsOf(JSON.parse(it.json)));
    const b = parts.map(q => { const known = mirroredParts.get(q.id);
      const chars = q.rows.filter((r, i) => !known || known.chars.get(r.id) !== q.rowHash[i]);
      return { id: q.id, hasAcct: !known || known.acct !== q.acctHash, ...q.acct, keep: q.rows.map(r => r.id), chars }; });
    await sql.run(BATCH_SQL, { b: JSON.stringify(b), s: social ? social.json : null }, { ...db, timeout: 120 });
    for (const q of parts) mirroredParts.set(q.id, { acct: q.acctHash, chars: new Map(q.rows.map((r, i) => [r.id, q.rowHash[i]])) });
  }
  async function writeSocial(json) {
    await sql.run(`UPDATE dbo.engine_social SET json=@j, updated_at=SYSUTCDATETIME() WHERE id=1; IF @@ROWCOUNT=0 INSERT dbo.engine_social (id, json) VALUES (1, @j);`, { j: json }, db);
  }

  async function drain() {
    while (pending.size || pendingSocial) {
      const items = [...pending].slice(0, MAX_BATCH), social = pendingSocial, done = waiters; waiters = [];
      try { await writeBatch(items, social); }
      catch (error) { waiters = done.concat(waiters); throw error; }
      if (social) { if (pendingSocial === social) pendingSocial = null; socialHash = social.hash; stats.written++; }
      for (const [id, item] of items) {
        if (pending.get(id) === item) pending.delete(id);   // a newer snapshot may have been queued meanwhile
        mirrored.set(id, item.hash); stats.written++;
      }
      stats.batches = (stats.batches || 0) + 1;
      for (const w of done) if (w.ids.every(id => !pending.has(id) || pending.get(id).hash !== w.hashes.get(id)) && (!w.social || !pendingSocial || pendingSocial !== w.social)) w.resolve(); else waiters.push(w);
      for (const [id, item] of items) await legacyStep(JSON.parse(item.json));
    }
  }
  function schedule(delay = 0) {
    if (pump || timer) return;
    timer = setTimeout(async () => {
      timer = null;
      pump = drain().then(() => { failures = 0; stats.lastError = null; stats.lastOkAt = Date.now(); })
        .catch((error) => { failures++; stats.failures++; stats.lastError = String(error?.message || error); log(`[sql] write failed (retry ${failures}): ${stats.lastError}`); })
        .finally(() => { pump = null; if (pending.size || pendingSocial) schedule(Math.min(maxRetryMs, retryMs * 2 ** Math.max(0, failures - 1)) * (failures ? 1 : 0)); });
    }, delay);
    timer.unref?.();
  }

  return {
    /** Merge SQL into `state` (the parsed account file). Returns { state, dirty, report }. dirty = the file must be rewritten. */
    async hydrate(state) {
      const next = { ...state, users: { ...state.users } };
      const accounts = await sql.query('SELECT account_id, salt, digest, created_ms, revision, legacy_user_no, extras_json FROM dbo.engine_account', {}, db);
      const chars = await sql.query('SELECT character_id, account_id, slot, profile_json, legacy_character_no FROM dbo.engine_character ORDER BY account_id, slot', {}, db);
      const byAccount = new Map();
      for (const c of chars) {
        if (!byAccount.has(c.account_id)) byAccount.set(c.account_id, []);
        const profile = JSON.parse(c.profile_json);
        if (c.legacy_character_no) { profile.legacyCharacterNo ||= c.legacy_character_no; onLink?.(c.character_id, c.legacy_character_no); }
        byAccount.get(c.account_id).push(profile);
      }
      const report = { fromSql: 0, keptFile: 0, pushedToSql: 0, sqlAccounts: accounts.length };
      let dirty = false;
      const seen = new Set();
      for (const a of accounts) {
        seen.add(a.account_id);
        const fromSql = { id: a.account_id, ...(a.salt ? { salt: a.salt } : {}), ...(a.digest ? { digest: a.digest } : {}), created: Number(a.created_ms), revision: Number(a.revision),
          ...(a.legacy_user_no ? { legacyUserNo: a.legacy_user_no } : {}), ...(a.extras_json ? JSON.parse(a.extras_json) : {}), characters: byAccount.get(a.account_id) ?? [] };
        const local = Object.hasOwn(next.users, a.account_id) ? next.users[a.account_id] : null;
        if (!local || Number(local.revision) < fromSql.revision) { next.users[a.account_id] = fromSql; dirty = true; report.fromSql++; mirrored.set(a.account_id, sha(JSON.stringify(fromSql))); rememberParts(fromSql); }
        else { report.keptFile++; rememberParts(fromSql); if (Number(local.revision) === fromSql.revision && JSON.stringify(local) === JSON.stringify(fromSql)) mirrored.set(a.account_id, sha(JSON.stringify(local))); }
      }
      // accounts that exist only in the file (or are newer there) go to SQL
      for (const [id, user] of Object.entries(next.users)) {
        if (isNpc(id) || !user || typeof user !== 'object') continue;
        const hash = sha(JSON.stringify(user));
        if (mirrored.get(id) !== hash) { pending.set(id, { json: JSON.stringify(user), hash }); report.pushedToSql++; }
      }
      const social = await sql.query('SELECT json FROM dbo.engine_social WHERE id = 1', {}, db);
      if (social[0] && (!next.social || Number(next.social.revision || 0) < Number(JSON.parse(social[0].json).revision || 0))) { next.social = JSON.parse(social[0].json); dirty = true; socialHash = sha(social[0].json); }
      else if (next.social) { const j = JSON.stringify(next.social), h = sha(j); if (h !== socialHash) pendingSocial = { json: j, hash: h }; }
      stats.hydrated = report;
      if (pending.size || pendingSocial) await this.flush();
      return { state: next, dirty, report };
    },

    /** Called after the engine has atomically written `next`. Cheap when nothing relevant changed. */
    async mirror(prev, next, dirtyIds = null) {
      const ids = [], social = null;
      // PERSIST-PERF: a transaction that kept the users map (sessions-only, e.g. login) checks no account; a hinted one checks
      // only its dirty accounts; otherwise every account is compared by reference (no hashing of unchanged objects).
      const scan = prev?.users === next.users && mirroredParts.size ? [] : dirtyIds ? [...dirtyIds].map(id => [id, next.users?.[id]]) : Object.entries(next.users || {});
      for (const [id, user] of scan) {
        if (isNpc(id) || !user || typeof user !== 'object') continue;
        if (prev?.users?.[id] === user && mirrored.has(id)) continue;     // same object: untouched by this transaction
        const json = JSON.stringify(user), hash = sha(json);
        if (mirrored.get(id) === hash || pending.get(id)?.hash === hash) continue;
        pending.set(id, { json, hash }); ids.push(id);
      }
      if (next.social && prev?.social !== next.social) {
        const json = JSON.stringify(next.social), hash = sha(json);
        if (hash !== socialHash && pendingSocial?.hash !== hash) pendingSocial = { json, hash };
      }
      if (!ids.length && !pendingSocial) return;
      if (!pending.size && !pendingSocial) return;
      if (strict) return this.commitOwn(ids, social);
      schedule(250);
    },

    /** Strict: resolve once the batch carrying THESE snapshots committed (rejects with the batch error; the snapshot stays queued
     *  for the retry). Concurrent transactions share batches, so N saves cost one round trip and one log flush. */
    commitOwn(ids, social) {
      const hashes = new Map(ids.map(id => [id, pending.get(id)?.hash]));
      const p = new Promise((resolve, reject) => waiters.push({ ids, hashes, social: social || pendingSocial, resolve, reject }));
      if (!pump) { if (timer) { clearTimeout(timer); timer = null; }
        pump = drain().then(() => { failures = 0; stats.lastError = null; stats.lastOkAt = Date.now(); })
          .catch((error) => { failures++; stats.failures++; stats.lastError = String(error?.message || error); const w = waiters; waiters = []; for (const x of w) x.reject(error); })
          .finally(() => { pump = null; if (waiters.length) { const w = waiters; waiters = []; for (const x of w) this.commitOwn(x.ids, x.social).then(x.resolve, x.reject); } }); }
      return p;
    },

    /** Resolve when every queued change is in SQL; rejects if SQL stays unreachable for `timeoutMs`. */
    async flush(timeoutMs = 30000) {
      const deadline = Date.now() + timeoutMs;
      while (pending.size || pendingSocial) {
        if (timer) { clearTimeout(timer); timer = null; }
        if (!pump) pump = drain().then(() => { failures = 0; stats.lastError = null; stats.lastOkAt = Date.now(); })
          .catch((error) => { failures++; stats.failures++; stats.lastError = String(error?.message || error); }).finally(() => { pump = null; });
        await pump;
        if ((pending.size || pendingSocial) && Date.now() > deadline) throw new Error(`SQL flush timed out: ${stats.lastError || 'unknown error'}`);
        if (pending.size || pendingSocial) await new Promise((r) => setTimeout(r, 200));
      }
    },

    status() { return { pending: pending.size + (pendingSocial ? 1 : 0), mirroredAccounts: mirrored.size, ...stats, strict, database }; },
  };
}
