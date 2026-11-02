// Private, single-server accounts and character snapshots. No game assets leave this server.
import {createEntityJournal,diffStores} from './entity-journal.mjs';
import {createVaultJournal,vaultEnabled} from '../pipeline/services/vault.mjs'; // VAULT: opt-in persistence writer (DK_VAULT=1)
import {normalizeCharacterName, normalizeStaffCharacterName, stripStaffNameTag, characterNameKey, normalizeCharacterNameColor} from '../../src/game/character-name.js';
import {isStaffBracketAccount,normalizeStaffBracket,staffBracket} from './staff-brackets.mjs';
import fs from 'node:fs/promises';
import path from 'node:path';
import { accountPermissions, permissionFile, setAccountRole } from './permissions.mjs';
import { applyStaffCharacterCreate, normalizeStaffShowcasesInStore } from './owner-roster.mjs';
import { loadWorldData } from '../world/data.mjs';
import { localDemoInfo } from './bootstrap.mjs';
import { ownerLocalRequest } from './owner-auth.mjs';
import { characterRef } from './character-ref.mjs';
import {writeAtomicStore} from './atomic-store.mjs';
import {SqliteAccountStore} from './sqlite-store.mjs';
import {createNpcRecordCache} from './npc-record-cache.mjs';
import {createNpcNameMigration} from './npc-name-migration.mjs';
import {NPC_PROFILE_LIMIT} from '../world/npc-profiles.mjs';
import {createGMTransferHooks} from './gm-transfers.mjs';
import {createCharTransferHooks} from './char-transfer.mjs';
import {createSocialAccountHooks} from '../world/social-state.mjs';
import {hydrateAccountPremium,mergeAccountPremiumFeatures} from '../world/account-premium.mjs';
import {defaultRoots} from '../world/prepared-roots.mjs';
import { fileURLToPath } from 'node:url';
import { randomBytes, scrypt as scryptCallback, timingSafeEqual, createHash, randomUUID } from 'node:crypto';
import { promisify, isDeepStrictEqual } from 'node:util';
import { CHAR_TRADE_ENGINE_CHOSEN } from '../../src/config/engine-chosen-char-trade.js';

const scrypt = promisify(scryptCallback);
// 2nd password limits: Global stringtable_loginmsg cate 30 (120 "between 4 & 12 digits", 112 "%d/%d", 116 "more than 5 times").
export const SECONDPW_MIN = 4, SECONDPW_MAX = 12, SECONDPW_MAX_WRONG = 5, SECONDPW_RATE = 10;
const validSecondPw = pin => typeof pin === 'string' && /^\d{4,12}$/.test(pin);
const DEFAULT_STORE = fileURLToPath(new URL('./data.json', import.meta.url));
const COOKIE = 'dekaron_session';
const SESSION_MS = 7 * 24 * 60 * 60 * 1000;
// Cold WebView2 startup can outlast the old 45-second handoff window. Tickets
// remain one-use, hashed in memory, account-bound and tied to the chosen host.
const LAUNCH_TICKET_MS = 180000;
const MAX_BYTES = 8 * 1024 * 1024;
// Evidenced (older server-ref legacy DK Engine server/accounts/api.mjs): REMEMBER_MS=30d, MAX_REMEMBER=5, token sha256 hex64; slice(-MAX_REMEMBER). Global client auth stack not shipped; do not touch sign-in credential flows.
const REMEMBER_MS = 30 * 24 * 60 * 60 * 1000, MAX_REMEMBER = 5, REMEMBER_TOKEN = /^[a-f0-9]{64}$/;
const hash = value => createHash('sha256').update(value).digest('hex');
class HttpError extends Error { constructor(status, message) { super(message); this.status = status; } }
function json(res, status, value, headers = {}) {
  res.writeHead(status, { 'Content-Type': 'application/json; charset=utf-8', 'Cache-Control': 'no-store', ...headers });
  res.end(JSON.stringify(value));
}
async function body(req, limit = MAX_BYTES) {
  const chunks = []; let size = 0;
  for await (const chunk of req) {
    size += chunk.length;
    if (size > limit) throw new HttpError(413, 'Save or request is too large.');
    chunks.push(chunk);
  }
  try { const value = JSON.parse(Buffer.concat(chunks).toString() || '{}');
    if (!value || typeof value !== 'object' || Array.isArray(value)) throw new Error();
    return value;
  } catch { throw new HttpError(400, 'Expected a JSON object.'); }
}
// MIGRATION-4.1.x: 4.1.0-4.1.3 allowed up to 100 characters per account; 4.2.0 slots are 18 (receiverMaxCharacters).
// Accounts that already hold more keep them (grandfathered, never trimmed) but cannot grow; new accounts get 18.
const LEGACY_MAX_CHARACTERS = 100;
export const accountCharacterLimit = (existing = 0) => Math.max(CHAR_TRADE_ENGINE_CHOSEN.receiverMaxCharacters, Math.min(LEGACY_MAX_CHARACTERS, Number(existing) || 0));
function validateCharacters(value) {
  if (!Array.isArray(value) || value.length > LEGACY_MAX_CHARACTERS) throw new HttpError(400, `Expected at most ${CHAR_TRADE_ENGINE_CHOSEN.receiverMaxCharacters} characters.`);
  const ids = new Set();
  for (const ch of value) {
    if (!ch || typeof ch !== 'object' || typeof ch.id !== 'string' || !/^[a-zA-Z0-9_-]{1,100}$/.test(ch.id)
      || ids.has(ch.id) || typeof ch.name !== 'string' || !ch.name.trim() || ch.name.length > 64
      || !Number.isInteger(ch.classIndex) || ch.classIndex < 0 || ch.classIndex > 14
      || !Number.isFinite(ch.level) || ch.level < 1) throw new HttpError(400, 'Invalid or duplicate character.');
    ids.add(ch.id);
  }
  return value;
}
const NPC_ACCOUNT_ID=/^npc_[0-9a-f]{32}$/;
// LANE1-PERF: optional extra bot-only save coalescing window (ms), bounded 0..2000.
// Default 0: no added latency; transactions that queue while a write is in flight
// still share the next write. Measured: a 250 ms window raised bot save p50 from
// ~44 ms to ~300 ms and cut bot command throughput 20-38 % (bots await saves), so
// it is opt-in only (DEKARON_NPC_SAVE_COALESCE_MS).
function npcSaveCoalesceDefault(env=process.env){const raw=env.DEKARON_NPC_SAVE_COALESCE_MS;if(raw===undefined||raw==='')return 0;const n=Number(raw);return Number.isInteger(n)&&n>=0&&n<=2000?n:0;}
function validateNpcProfile(accountId,profile){
  if(typeof accountId!=='string'||!NPC_ACCOUNT_ID.test(accountId)||profile?.authority!=='server'||profile?.npcPlayer!==true)throw new HttpError(400,'Invalid private NPC profile.');
  validateCharacters([profile]);
}
function validateNpcAdmissions(rows){
  if(!Array.isArray(rows)||!rows.length||rows.length>16)throw new HttpError(400,'NPC admission requires one to sixteen identities.');
  const seen=new Set();
  for(const r of rows){if(!r||typeof r.accountId!=='string'||!NPC_ACCOUNT_ID.test(r.accountId)||typeof r.characterId!=='string'||!/^[a-zA-Z0-9_-]{1,100}$/.test(r.characterId)||seen.has(r.accountId))throw new HttpError(400,'Invalid NPC admission identity.');seen.add(r.accountId);}
}
function storedNpcProfile(profile,old=profile){
  const stored={...structuredClone(profile),id:old.id,name:old.name,nameColor:old.nameColor||'white',classIndex:old.classIndex,className:old.className,authority:'server',npcPlayer:true,lastPlayed:Date.now()};
  delete stored.accountFeatures;return stored;
}
/** The untouched 'admin' that server start reserves on a fresh local install (bootstrap.mjs initializeLocalDemo): the
 *  local-demo marker, no characters, never changed (revision 0). */
/** ROLE-AUTOLOGIN: 4.1.0-4.1.2 reserved only 'admin' at signup, so a player could register 'dev' and that record survives an
 *  update. An existing staff-bracket record belongs to the owner launcher only when it carries the bracket marker, is a bracket no
 *  player could ever register (admin is reserved everywhere; 'gm' is shorter than the 3-character ID minimum), is still empty, or
 *  holds server characters the owner roster / staff create stamped for this account. Anything else is a player's account. */
function ownerBracketRecord(row, id) {
  if (!row || typeof row !== 'object') return false;
  if (row.staffBracket === id || id === 'admin' || id === 'gm') return true;
  const characters = Array.isArray(row.characters) ? row.characters : [];
  if (!characters.length && !Number(row.revision)) return true;
  return characters.some(c => c?.authority === 'server' && c.ownerProvision?.account === id);
}
function freshOwnerPlaceholder(store) {
  const admin = store?.users?.admin;
  return !!admin && store.localDemo?.id === 'admin' && Array.isArray(admin.characters) && !admin.characters.length && !Number(admin.revision);
}

export function createAccountsApi({ initialOwnerCharacters = null, file = process.env.DEKARON_ACCOUNT_STORE || DEFAULT_STORE, sqlFile = process.env.DEKARON_ACCOUNT_SQLITE || null, engineSqlStore = null, permissionsFile = permissionFile(file), gamedataRoot = defaultRoots().gamedataRoot, onInvalidate = async () => {}, onAuthenticated = () => {}, onOwnerPrepared = () => null, isAccountOnline = () => false, cookieName = COOKIE, secureCookies = process.env.DEKARON_SECURE_COOKIES === '1', launchNow = Date.now, launchAccess = () => ({allowed:true,proof:null}), launchInvite = () => ({allowed:true,cookie:null}), storeIo = undefined, npcSaveCoalesceMs = npcSaveCoalesceDefault(), loginVersionGate = null } = {}) {
  if(typeof cookieName!=='string'||! /^[A-Za-z0-9_-]{1,80}$/.test(cookieName))throw new Error('Invalid account cookie name.');
  if(sqlFile&&engineSqlStore)throw new Error('Choose one dedicated account database.');
  let state, loading, queue = Promise.resolve();
  let sqliteStore = null;
  const npcRecordCache=createNpcRecordCache();
  const attempts = new Map(), purchaseAttempts = new Map();
  const launchTickets = new Map(), launchAttempts = new Map(), ownerSessions = new Set();
  function pruneLaunchTickets(){for(const[key,value]of launchTickets)if(value.expires<=launchNow())launchTickets.delete(key);}
  function invalidateLaunchTickets(id,source=null){for(const[key,value]of launchTickets)if(value.id===id||source&&value.source===source)launchTickets.delete(key);}
  function launchRate(req){const time=launchNow(),key=req.relay?.clientKey||req.socket.remoteAddress||'local';for(const[ip,value]of launchAttempts)if(value.until<=time)launchAttempts.delete(ip);if(!launchAttempts.has(key)&&launchAttempts.size>=5000)throw new HttpError(429,'Try launching again later.');const rate=launchAttempts.get(key)||{count:0,until:time+60000};launchAttempts.set(key,rate);if(++rate.count>60)throw new HttpError(429,'Too many launch attempts. Try again in a minute.');}
  function launchHost(req){const raw=String(req.headers.host||'').toLowerCase();if(!raw||raw.length>255||/[\s/@\\?#]/.test(raw))throw new HttpError(400,'Invalid server address.');try{return new URL(`http://${raw}`).host;}catch{throw new HttpError(400,'Invalid server address.');}}
  const rememberAttempts = new Map();
  function rememberRate(req){const time=Date.now(),key=req.relay?.clientKey||req.socket.remoteAddress||'local';for(const[k,v]of rememberAttempts)if(v.until<=time)rememberAttempts.delete(k);if(!rememberAttempts.has(key)&&rememberAttempts.size>=5000)throw new HttpError(429,'Try again later.');const rate=rememberAttempts.get(key)||{count:0,until:time+60000};rememberAttempts.set(key,rate);if(++rate.count>30)throw new HttpError(429,'Too many saved-login attempts. Try again in a minute.');}
  const sessionQueues = new Map(), sessionActivity = new Map();
  function assertLoginAvailable(db,id,allowedSource=null) {
    // KICK_STALE_LOGIN (Global parity): a correct new login replaces this account's older session and disconnects its
    // old or dead client instead of refusing. Returns true when an older session/client must be kicked.
    let kick=!!isAccountOnline(id);
    for(const key of sessionKeysOf(db,id)) {const value=db.sessions[key];
      // Owner cookies are valid only in the process that authenticated them.
      // An unusable persisted owner session must not block a fresh private launch.
      if(isStaffBracketAccount(id)&&!ownerSessions.has(key))continue;
      if(value.id===id && key!==allowedSource && value.expires>Date.now() && Date.now()-(sessionActivity.get(key) ?? value.lastActive ?? 0)<60000)
        kick=true;
    }
    return kick;
  }
  function withAccountSession(id,fn){const task=Promise.resolve((sessionQueues.get(id)||Promise.resolve()).catch(()=>{}).then(fn));sessionQueues.set(id,task);Promise.resolve(task).finally(()=>{if(sessionQueues.get(id)===task)sessionQueues.delete(id);}).catch(()=>{});return task;}
  async function load() {
    if (state) return state;
    if (!loading) loading = (async () => {
      if (sqlFile) {
        sqliteStore ||= new SqliteAccountStore(sqlFile);
        if (sqliteStore.empty()) {
          let original;
          try { original = JSON.parse(await fs.readFile(file, 'utf8')); }
          catch (err) { if (err.code !== 'ENOENT') throw err; original = { version: 1, users: {}, sessions: {} }; }
          if (original.version !== 1 || !original.users || !original.sessions) throw new Error('Invalid JSON account import; original file preserved.');
          sqliteStore.write(original);
        }
        state = sqliteStore.read();
      } else {
        try { state = JSON.parse(await fs.readFile(file, 'utf8')); }
        catch (err) { if (err.code !== 'ENOENT') throw err; state = { version: 1, users: {}, sessions: {} }; }
        if (journal) await journal.recover(state); else { const j=createEntityJournal({file,writeCheckpoint:async()=>{}}); await j.recover(state); if(j.stats.replayed){await writeAtomicStore(file,state);await fs.rm(file+'.journal',{force:true});} }
      }
      if (state.version !== 1 || !state.users || !state.sessions) throw new Error('Invalid account store; original file preserved.');
      if(engineSqlStore){
        const merged=await engineSqlStore.hydrate(state);
        state=merged.state;
        if(merged.dirty)await writeAtomicStore(file,journal?{...state,journalSeq:journal.seq}:state);
      }
      // STAFF-STANCE: fix illegal staff showcase weapon tabs in memory (persisted with the next normal save; version-gated).
      if(process.env.DEKARON_STAFF_STANCE!=='0'){try{const r=await normalizeStaffShowcasesInStore(state,{gamedataRoot});if(r.changed||r.error||r.errors?.length)console.log('[accounts] staff stance',JSON.stringify(r));}catch(e){console.warn('[accounts] staff stance skipped',e?.message||e);}}
      return state;
    })().catch(err => { loading = null; state = null; throw err; });
    return loading;
  }
  // LANE1-PERF group commit. Every transaction still resolves only after the
  // atomic temp+rename that contains it (and its SQL mirror) completed; nothing
  // is acknowledged early. Consecutive transactions that touch ONLY private NPC
  // records may share one file write, optionally waiting npcSaveCoalesceMs for
  // more bot saves. Any human/session/other transaction runs alone, immediately,
  // exactly as before. sqlite stores keep one write per transaction.
  // PERSIST-PERF: per-entity journal + background checkpoint (default on for the JSON store; DEKARON_ACCOUNT_JOURNAL=0 = old full rewrite)
  const journal=!sqlFile&&process.env.DEKARON_ACCOUNT_JOURNAL!=='0'?(vaultEnabled()&&storeIo===undefined?createVaultJournal:createEntityJournal)({file,checkpointMs:Number(process.env.DEKARON_CHECKPOINT_MS)||30000,
    checkpointBytes:Number(process.env.DEKARON_CHECKPOINT_BYTES)||64*1024*1024,writeCheckpoint:value=>writeAtomicStore(file,value,{io:storeIo,accountNpcProfiles:true})}):null;
  const sqlGroupCommit=!!engineSqlStore?.commitOwn&&process.env.DEKARON_SQL_GROUP_COMMIT!=='0';
  const pendingCommits=[];let committing=false,coalesceWake=null,coalesceTimer=null,flushRequested=0;
  const MAX_GROUP=128;
  function wakeCoalesce(){if(coalesceTimer){clearTimeout(coalesceTimer);coalesceTimer=null;}const wake=coalesceWake;coalesceWake=null;wake?.();}
  function enqueueCommit(entry){
    const task=new Promise((resolve,reject)=>{entry.resolve=resolve;entry.reject=reject;});
    entry.at=Date.now();pendingCommits.push(entry);
    if(!entry.bot)wakeCoalesce();
    void pumpCommits();
    queue=task.catch(()=>{});
    return task;
  }
  async function pumpCommits(){
    if(committing)return;committing=true;
    try{
      while(pendingCommits.length){
        const head=pendingCommits[0];
        const groupable=(head.bot||sqlGroupCommit)&&!sqliteStore;
        if(groupable&&head.bot&&npcSaveCoalesceMs>0&&!flushRequested&&pendingCommits.every(t=>t.bot)&&pendingCommits.length<MAX_GROUP){
          const wait=head.at+npcSaveCoalesceMs-Date.now();
          if(wait>0){await new Promise(r=>{coalesceWake=r;coalesceTimer=setTimeout(wakeCoalesce,wait);});continue;}
        }
        let count=1;if(groupable)while(count<pendingCommits.length&&count<MAX_GROUP&&(sqlGroupCommit||pendingCommits[count].bot))count++;
        await runCommitGroup(pendingCommits.splice(0,count));
      }
    }finally{committing=false;}
  }
  async function runCommitGroup(group){
    try{await load();}catch(error){for(const t of group)t.reject(error);return;}
    let current=state;const built=[];
    for(const t of group){try{const r=await t.build(current);built.push({t,previous:current,r});current=r.next;}catch(error){t.reject(error);}}
    if(!built.length)return;
    const full=built.some(b=>b.r.full),touched=new Set();for(const b of built)for(const id of b.r.touched||[])touched.add(id);
    const fragments=npcRecordCache.prepare(current,full?{}:{reuse:true,touched});
    try{
      if (sqliteStore) sqliteStore.write(current);
      else if (journal && !full) {
        // one fsynced line with only the dirty entities of this group (hints from the builders; identity diff otherwise)
        const hint={};for(const b of built)for(const [col,keys] of Object.entries(b.r.dirty||{}))for(const k of keys)(hint[col]||=new Set()).add(k);
        const hinted=built.every(b=>b.r.dirty);
        const rec=diffStores(state,current,hinted?hint:null);
        if(rec)await journal.append(rec);
      } else if (journal) {
        // full-clone transactions (rare admin/rename paths): a synchronous checkpoint replaces the journal
        await journal.checkpoint(current,journal.seq,{replace:true}); // VAULT: 3rd arg read only by createVaultJournal
      } else await writeAtomicStore(file,current,{io:storeIo,accountNpcProfiles:true,accountNpcRecordFragment:fragments.lookup});
    }
    catch(error){for(const b of built){b.r.undo?.();b.t.reject(error);}return;}
    state=current;fragments.commit();commitStats.writes++;commitStats.transactions+=built.length;
    if(journal?.due()){const snap=state,at=journal.seq;void journal.checkpoint(snap,at).catch(error=>console.error(`[accounts] background checkpoint failed (journal kept): ${error?.message||error}`));}
    if(!sqlGroupCommit){for(const b of built){try{if(engineSqlStore)await engineSqlStore.mirror(b.previous,b.r.next,b.r.dirty?.users);b.t.resolve(b.r.result);}catch(error){b.t.reject(error);}}return;}
    // PERSIST-PERF group commit (strict SQL store): every transaction of this group is queued on the store in commit order, the
    // whole group shares one SQL round trip/transaction, and each caller is acknowledged only after ITS snapshot committed in SQL
    // (and after the file write above). The next group's file write overlaps this group's SQL commit; at most one group waits.
    await sqlInflight;
    const acks=built.map(b=>Promise.resolve().then(()=>engineSqlStore.mirror(b.previous,b.r.next,b.r.dirty?.users)).then(()=>b.t.resolve(b.r.result),error=>b.t.reject(error)));
    sqlInflight=Promise.all(acks);
  }
  const commitStats={writes:0,transactions:0};
  let sqlInflight=Promise.resolve();
  async function transact(fn) {
    return enqueueCommit({bot:false,build:async base=>{const next = structuredClone(base), result = await fn(next);return {next,result,full:true};}});
  }
  // Profile-only callbacks replace these records; every other namespace remains
  // immutable. Keep the same global queue and publish only after atomic rename.
  async function transactProfiles(accountIds, fn) {
    const ids=Array.isArray(accountIds)?accountIds:[];
    const bot=ids.length>0&&ids.every(id=>typeof id==='string'&&NPC_ACCOUNT_ID.test(id));
    return enqueueCommit({bot,build:async base=>{
      const next = { ...base, users: { ...base.users } };
      if (base.npcProfiles) next.npcProfiles = { ...base.npcProfiles };
      const ownedIds=new Set(ids);for (const id of ownedIds) {
        if (typeof id !== 'string') continue;
        if (Object.hasOwn(next.users, id)) next.users[id] = structuredClone(next.users[id]);
        if (Object.hasOwn(next.npcProfiles || {}, id)) next.npcProfiles[id] = structuredClone(next.npcProfiles[id]);
      }
      const result = await fn(next);
      return {next,result,touched:ownedIds,dirty:{users:[...ownedIds].filter(id=>Object.hasOwn(next.users,id)||Object.hasOwn(base.users,id)),npcProfiles:[...ownedIds].filter(id=>Object.hasOwn(next.npcProfiles||{},id)||Object.hasOwn(base.npcProfiles||{},id))}};
    }});
  }
  // A transaction that changes ONE account only (world profile saves): copies that account instead of the whole store. The
  // structuredClone of every account on each save was ~19 % of the server's CPU with 100 players (measured).
  // Same queue, same atomic write, same all-or-nothing swap of the in-memory state.
  async function transactUser(accountId, fn) {
    return enqueueCommit({bot:false,build:async base=>{
      const users = { ...base.users };
      if (Object.hasOwn(users, accountId)) users[accountId] = structuredClone(users[accountId]);
      const next = { ...base, users }, result = await fn(next);
      return {next,result,dirty:{users:[accountId]}};
    }});
  }
  // PERSIST-PERF O(1) login: sessions change IN PLACE (no world clone, no users copy); every change is recorded for undo if the
  // durable write fails. The per-account session index replaces the scan over every session.
  const sessionIndexes=new WeakMap();
  function sessionIndex(sessions){let ix=sessionIndexes.get(sessions);if(!ix){ix=new Map();for(const [k,v] of Object.entries(sessions))if(v&&v.id!==undefined){if(!ix.has(v.id))ix.set(v.id,new Set());ix.get(v.id).add(k);}sessionIndexes.set(sessions,ix);}return ix;}
  function sessionKeysOf(db,id){return [...(sessionIndex(db.sessions).get(id)||[])];}
  async function transactSessions(fn){
    return enqueueCommit({bot:false,build:async base=>{
      const sessions=base.sessions,ix=sessionIndex(sessions),undo=[],dirty=new Set();
      const ops={get:k=>sessions[k],keysOf:id=>[...(ix.get(id)||[])],
        set(k,v){undo.push([k,Object.hasOwn(sessions,k)?sessions[k]:undefined]);const old=sessions[k];if(old)ix.get(old.id)?.delete(k);sessions[k]=v;if(!ix.has(v.id))ix.set(v.id,new Set());ix.get(v.id).add(k);dirty.add(k);},
        delete(k){if(!Object.hasOwn(sessions,k))return;undo.push([k,sessions[k]]);ix.get(sessions[k].id)?.delete(k);delete sessions[k];dirty.add(k);}};
      let result;try{result=await fn(base,ops);}catch(error){rollback();throw error;}
      function rollback(){for(const [k,v] of undo.reverse()){const cur=sessions[k];if(cur)ix.get(cur.id)?.delete(k);if(v===undefined)delete sessions[k];else{sessions[k]=v;if(!ix.has(v.id))ix.set(v.id,new Set());ix.get(v.id).add(k);}}undo.length=0;}
      return {next:base,result,dirty:{sessions:[...dirty]},undo:rollback};
    }});
  }
  let sweepAt=0;
  function scheduleSessionSweep(){const now=Date.now();if(now<sweepAt)return;sweepAt=now+60000;
    void transactSessions((db,ops)=>{for(const [k,v] of Object.entries(db.sessions))if(!v||v.expires<=Date.now()){if(sessionActivity.has(k)&&Date.now()-sessionActivity.get(k)<60000)continue;ops.delete(k);sessionActivity.delete(k);ownerSessions.delete(k);}}).catch(()=>{});}
  /** Shutdown / explicit checkpoint: drain commits, write the full snapshot atomically, compact the journal. */
  async function checkpointNow(){await flushPendingCommits();if(journal&&state)await journal.checkpoint(state,journal.seq);}
  async function flushPendingCommits(until=null){flushRequested++;try{wakeCoalesce();if(until)await Promise.resolve(until).catch(()=>{});while(pendingCommits.length||committing){await queue;await new Promise(r=>setImmediate(r));}}finally{flushRequested--;}}
  function token(req) {
    return String(req.headers.cookie || '').split(';').map(s => s.trim()).find(s => s.startsWith(`${cookieName}=`))?.slice(cookieName.length + 1) || '';
  }
  async function sessionUser(req) {
    const db = await load(), session = db.sessions[hash(token(req))];
    if (!session || session.expires <= Date.now() || !Object.hasOwn(db.users, session.id)) return null;
    if(isStaffBracketAccount(session.id)&&(!ownerLocalRequest(req)||!ownerSessions.has(hash(token(req)))))return null;
    sessionActivity.set(hash(token(req)),Date.now());
    return db.users[session.id];
  }
  async function user(req) {
    const owner=await sessionUser(req);
    if(!owner)return null;
    // 2nd password (Global ui_secondpwwnd, server-checked like Global 30:114/30:117): the record never leaves this module;
    // world join reads only these two flags. NPC accounts stay exempt; the owner/admin launcher account is NOT exempt (D1).
    const {secondPw,...rest}=owner,session=(await load()).sessions[hash(token(req))];
    return {...rest,secondPwRequired:secondPwApplies(owner.id),secondPwVerified:!!session?.secondPw,...await accountPermissions(permissionsFile,owner.id)};
  }
  const secondPwApplies=id=>!NPC_ACCOUNT_ID.test(id);
  const secondPwAttempts=new Map();
  function secondPwRate(id){const now=Date.now();for(const[k,v]of secondPwAttempts)if(v.until<=now)secondPwAttempts.delete(k);const r=secondPwAttempts.get(id)||{count:0,until:now+60000};secondPwAttempts.set(id,r);return ++r.count<=SECONDPW_RATE;}
  async function secondPwDigest(pin,salt){return (await scrypt(pin,salt,64)).toString('hex');}
  async function secondPwMatches(rec,pin){if(!validSecondPw(pin)||!/^[a-f0-9]{128}$/.test(String(rec?.digest)))return false;const a=Buffer.from(await secondPwDigest(pin,rec.salt),'hex');return timingSafeEqual(a,Buffer.from(rec.digest,'hex'));}
  // STABILITY-PING: session/one-account changes no longer structuredClone + checkpoint the whole store (~250 ms main-thread stall each, measured).
  async function markSecondPwSession(req,id){const key=hash(token(req));await transactSessions((db,ops)=>{const s=ops.get(key);if(s&&s.id===id)ops.set(key,{...s,secondPw:true});});}
  function cookie(req, value, maxAge) {
    return `${cookieName}=${value}; HttpOnly; SameSite=Strict; Path=/; Max-Age=${maxAge}${req.socket.encrypted || req.relay?.secure || secureCookies ? '; Secure' : ''}`;
  }
  async function sessionUnlocked(req, res, id, status = 200, extraCookies = [], owner = false, allowedSource = null) {
    const source=hash(token(req));
    const secret = randomBytes(32).toString('hex');
    let removed=[];
    const replaced=await transactSessions((db,ops) => {
      const kick=assertLoginAvailable(db,id,allowedSource);
      let replaced=kick;
      // only THIS account's sessions are replaced here; expired sessions of other accounts are swept in the background
      for (const key of ops.keysOf(id)) {const value=ops.get(key);if(value.expires>Date.now())replaced=true;ops.delete(key);removed.push(key);}
      ops.set(hash(secret), { id, expires: Date.now() + SESSION_MS, lastActive: Date.now() });
      return replaced;
    });
    sessionActivity.set(hash(secret),Date.now());
    for(const key of removed){sessionActivity.delete(key);ownerSessions.delete(key);}
    if(owner)ownerSessions.add(hash(secret));
    scheduleSessionSweep();
    invalidateLaunchTickets(id,source);
    if(replaced)await onInvalidate(id,'session-replaced');
    if(status===200)await onAuthenticated(id);
    json(res, status, { id, ...await accountPermissions(permissionsFile, id) }, { 'Set-Cookie': extraCookies.length ? [cookie(req, secret, SESSION_MS / 1000),...extraCookies] : cookie(req, secret, SESSION_MS / 1000) });
  }
  async function session(req,res,id,status=200){return withAccountSession(id,()=>sessionUnlocked(req,res,id,status,[],false,hash(token(req))));}
  // 2nd password endpoints. Every reply carries the Global stringtable_loginmsg cate-30 id in `code`.
  //   GET  /api/auth/secondpw            -> {exists, locked, verified, code:104|107|116}
  //   POST /api/auth/secondpw/set        {pin, again}           -> 106 | 115 | 120 | 121 | 119
  //   POST /api/auth/secondpw/verify     {pin}                  -> 106 | 112 (wrong/max) | 116 | 113
  //   POST /api/auth/secondpw/change     {current, pin, again}  -> 106 | 112 | 116 | 113 | 120 | 121 | 118
  //   POST /api/auth/secondpw/unlock     {account}  owner launcher session only -> 106 | 113
  async function handleSecondPw(req,res,method,pathname){
    const reply=(status,code,extra={})=>json(res,status,{ok:status===200&&[104,106,107].includes(code),code,...extra});
    const current=await user(req);if(!current)throw new HttpError(401,'Log in first.');
    const op=pathname.slice('/api/auth/secondpw'.length).replace(/^\//,'');
    if(op==='unlock'){
      if(method!=='POST')throw new HttpError(405,'Use POST.');
      if(current.id!=='admin'||!current.capabilities?.includes('gm:commands'))throw new HttpError(403,'Only the installation owner can unlock a 2nd password.');
      const data=await body(req,512);const id=String(data.account||'').trim().toLowerCase();
      if(Object.keys(data).some(k=>k!=='account')||!/^[a-z0-9_-]{3,32}$/.test(id)||id==='__proto__')throw new HttpError(400,'Name one account to unlock.');
      const r=await transactUser(id,db=>{const u=Object.hasOwn(db.users,id)?db.users[id]:null;if(!u)throw new HttpError(404,'That registered account does not exist.');if(!u.secondPw)return 113;u.secondPw={...u.secondPw,wrong:0,locked:false};return 106;});
      return json(res,200,{ok:r===106,code:r,account:id});
    }
    // Exempt accounts (owner launcher, NPC) answer the status read with required:false so the client skips the window; every
    // 2nd password action stays refused for them.
    if(!secondPwApplies(current.id)){if(op===''&&method==='GET')return json(res,200,{ok:true,code:106,required:false,exists:false,locked:false,verified:true});throw new HttpError(403,'This account does not use a 2nd password.');}
    const rec=()=>{const u=state.users[current.id];return u?.secondPw||null;};
    if(op===''){if(method!=='GET')throw new HttpError(405,'Use GET.');const r=rec();return reply(200,!r?107:r.locked?116:104,{required:true,exists:!!r,locked:!!r?.locked,verified:!!current.secondPwVerified,wrong:r?.wrong||0,max:SECONDPW_MAX_WRONG});}
    if(method!=='POST')throw new HttpError(405,'Use POST.');
    const fields={set:['pin','again'],verify:['pin'],change:['current','pin','again']}[op];
    if(!fields)throw new HttpError(404,'Unknown 2nd password action.');
    const data=await body(req,512);if(Object.keys(data).some(k=>!fields.includes(k))||fields.some(k=>typeof data[k]!=='string'||data[k].length>32))return reply(400,114);
    if(op!=='set'&&!secondPwRate(current.id))return reply(429,117,{error:'Too many 2nd password attempts. Try again in a minute.'});
    return withAccountSession(current.id,async()=>{
      // Check, count and lock inside one transaction so parallel guesses cannot exceed 5.
      const check=async(pin)=>{const r=rec();if(!r)return {code:113};if(r.locked)return {code:116};
        if(await secondPwMatches(r,pin)){await transactUser(current.id,db=>{const u=db.users[current.id];if(u?.secondPw)u.secondPw={...u.secondPw,wrong:0};});return {code:106};}
        const wrong=await transactUser(current.id,db=>{const u=db.users[current.id];if(!u?.secondPw)return 0;const w=Math.min(SECONDPW_MAX_WRONG,(u.secondPw.wrong||0)+1);u.secondPw={...u.secondPw,wrong:w,locked:w>=SECONDPW_MAX_WRONG};return w;});
        return wrong>=SECONDPW_MAX_WRONG?{code:116}:{code:112,wrong};};
      const store=async(pin,code)=>{const salt=randomBytes(16).toString('hex'),digest=await secondPwDigest(pin,salt);
        try{await transactUser(current.id,db=>{const u=db.users[current.id];if(!u)throw new HttpError(401,'Log in first.');if(code===119&&u.secondPw)throw Object.assign(new Error('set'),{already:true});u.secondPw={salt,digest,wrong:0,locked:false,updated:Date.now()};});}
        catch(e){if(e.already)return 115;if(e.status)throw e;return code;}
        await markSecondPwSession(req,current.id);return 106;};
      if(op==='set'){if(rec())return reply(200,115);if(!validSecondPw(data.pin))return reply(200,120);if(data.pin!==data.again)return reply(200,121);return reply(200,await store(data.pin,119));}
      if(op==='verify'){const v=await check(data.pin);if(v.code===106)await markSecondPwSession(req,current.id);return reply(200,v.code,v.wrong?{wrong:v.wrong,max:SECONDPW_MAX_WRONG}:{});}
      const v=await check(data.current);if(v.code!==106)return reply(200,v.code,v.wrong?{wrong:v.wrong,max:SECONDPW_MAX_WRONG}:{});
      if(!validSecondPw(data.pin))return reply(200,120);if(data.pin!==data.again)return reply(200,121);return reply(200,await store(data.pin,118));
    });
  }
  return {
    user,
    /** PERSIST-PERF: drain + full atomic checkpoint (call at shutdown). */
    checkpoint: checkpointNow,
    persistenceStats(){return {journal:journal?{seq:journal.seq,...journal.stats,busy:journal.busy}:null,commits:{...commitStats}};},
    // Private launcher management reads the live account state, including accounts
    // hydrated from SQL Server, before changing a role in the local permission store.
    async listRegisteredAccountIds(){
      const db=await load();
      return Object.keys(db.users).sort();
    },
    // Trusted private lifecycle only: all admission stamps originate here.
    async readNpcAdmissions(rows){
      validateNpcAdmissions(rows);
      const db=await load();
      return rows.map(r=>{
        const old=Object.hasOwn(db.npcProfiles||{},r.accountId)&&db.npcProfiles[r.accountId];
        if(!old||old.id!==r.characterId||Object.hasOwn(db.users,r.accountId))throw new HttpError(404,'Private NPC admission is unavailable.');
        validateNpcProfile(r.accountId,old);
        return {accountId:r.accountId,characterId:r.characterId,expected:structuredClone(old)};
      });
    },
    async commitNpcAdmissions(rows){
      validateNpcAdmissions(rows);
      return transactProfiles(rows.map(r=>r.accountId),db=>{
        const targets=rows.map(r=>{
          validateNpcProfile(r.accountId,r.profile);
          const old=Object.hasOwn(db.npcProfiles||{},r.accountId)&&db.npcProfiles[r.accountId];
          if(!old||old.id!==r.characterId||r.profile.id!==r.characterId||Object.hasOwn(db.users,r.accountId))throw new HttpError(404,'Private NPC admission is unavailable.');
          validateNpcProfile(r.accountId,old);
          if(!r.expected||!isDeepStrictEqual(old,r.expected))throw new HttpError(409,'Canonical NPC profile changed before admission.');
          return {r,old};
        });
        const updates=[];
        for(const {r,old} of targets){const profile=storedNpcProfile(r.profile,old);db.npcProfiles[r.accountId]=profile;updates.push({accountId:r.accountId,characterId:r.characterId,profile:structuredClone(profile)});}
        return {committed:true,updates};
      });
    },
    migrateNpcNames:createNpcNameMigration({transact}),
    ...createSocialAccountHooks({load,transact,transactProfiles,saveNpcProfile:(db,{accountId,characterId,profile,expected,preserveLastPlayed=false})=>{
      validateNpcProfile(accountId,profile);
      const old=Object.hasOwn(db.npcProfiles||{},accountId)&&db.npcProfiles[accountId];
      if(!old||old.id!==characterId||profile.id!==characterId||Object.hasOwn(db.users,accountId))throw new HttpError(404,'A private NPC character is unavailable.');
      validateNpcProfile(accountId,old);
      if(expected!==undefined||preserveLastPlayed!==false||Object.hasOwn(profile,'accountFeatures'))throw new HttpError(400,'Unsupported private NPC social profile semantics.');
      db.npcProfiles[accountId]=storedNpcProfile(profile,old);return true;
    }}),
    ...createCharTransferHooks({load,transact}),
    ...createGMTransferHooks({load,transact,authorize:async(req,db)=>{
      const key=hash(token(req)),session=db.sessions[key];
      if(!session||session.expires<=Date.now()||!Object.hasOwn(db.users,session.id)||isStaffBracketAccount(session.id)&&(!ownerLocalRequest(req)||!ownerSessions.has(key)))return null;
      return {id:session.id,...await accountPermissions(permissionsFile,session.id)};
    }}),
    async ownerLaunch(req,res) {
      try {
        if(!ownerLocalRequest(req)||req.headers.origin!==undefined)throw new HttpError(403,'Local admin requires the private owner launcher.');
        const input=await body(req,512);
        const inputKeys=Object.keys(input||{});
        if(inputKeys.some(k=>k!=='staffRole'))throw new HttpError(400,'Owner launch accepts no credentials.');
        let bracketKey='admin';
        if(input.staffRole!=null){try{bracketKey=normalizeStaffBracket(input.staffRole);}catch{throw new HttpError(400,'Staff role must be admin, gm, or dev.');}}
        const bracket=staffBracket(bracketKey);
        const accountId=bracket.id;
        await withAccountSession(accountId,async()=>{
          const db=await load();
          assertLoginAvailable(db,accountId);
          // ROLE-AUTOLOGIN: never sign the owner into (or grant staff to) a player's pre-4.2.0 'dev' account.
          if(Object.hasOwn(db.users,accountId)&&!ownerBracketRecord(db.users[accountId],accountId))throw new HttpError(409,`A player account named "${accountId}" was registered before 4.2.0 reserved it. ${bracket.tag} owner launch was refused so that player's account is not taken over or given staff rights. Rename or remove that account first.`);
          if(!Object.hasOwn(db.users,accountId)){
            const salt=randomBytes(16).toString('hex'),digest=(await scrypt(randomBytes(48).toString('hex'),salt,64)).toString('hex');
            const characters=initialOwnerCharacters?await initialOwnerCharacters({id:accountId,characters:[],staffRole:bracketKey}):[];
            validateCharacters(characters);
            await transact(next=>{
              if(Object.hasOwn(next.users,accountId))throw new HttpError(409,'The installation owner already exists. Retry sign-in.');
              const names=new Set(Object.values(next.users).flatMap(u=>(u.characters||[]).map(c=>c.name.toLowerCase())));
              for(const ch of characters){if(names.has(ch.name.toLowerCase()))throw new HttpError(409,'An owner showcase character name is already occupied. Existing progress is preserved.');names.add(ch.name.toLowerCase());}
              next.users[accountId]={id:accountId,salt,digest,created:Date.now(),revision:characters.length?1:0,characters,staffBracket:bracketKey};
            });
          }else if(initialOwnerCharacters&&(accountId==='admin'?freshOwnerPlaceholder(db):((db.users[accountId]?.characters||[]).length===0&&(db.users[accountId]?.revision||0)===0))){
            const characters=await initialOwnerCharacters({id:accountId,characters:[],staffRole:bracketKey});
            validateCharacters(characters);
            if(characters.length)await transact(next=>{
              const row=next.users[accountId];
              const fresh=accountId==='admin'?freshOwnerPlaceholder(next):((row?.characters||[]).length===0&&(row?.revision||0)===0);
              if(!fresh||!ownerBracketRecord(row,accountId))throw new HttpError(409,'The installation owner changed during setup. Retry sign-in.');
              const names=new Set(Object.values(next.users).flatMap(u=>(u.characters||[]).map(c=>c.name.toLowerCase())));
              for(const ch of characters){if(names.has(ch.name.toLowerCase()))throw new HttpError(409,'An owner showcase character name is already occupied. Existing progress is preserved.');names.add(ch.name.toLowerCase());}
              next.users[accountId]={...next.users[accountId],revision:1,characters};
            });
          }
          await setAccountRole({accountStore:file,file:permissionsFile,account:accountId,role:'gm'});
          let adminGuild=null;
          try{const report=onOwnerPrepared();if(report?.then)void Promise.resolve(report).catch(()=>{});else adminGuild=report;}catch{adminGuild={phase:'deferred',complete:false,reason:'setup-unavailable'};}
          pruneLaunchTickets();invalidateLaunchTickets(accountId);
          const ticket=randomBytes(32).toString('hex');launchTickets.set(hash(ticket),{id:accountId,owner:true,staffBracket:bracketKey,host:launchHost(req),expires:launchNow()+LAUNCH_TICKET_MS});
          json(res,200,{ticket,expiresIn:LAUNCH_TICKET_MS/1000,account:accountId,staffRole:bracketKey,...(adminGuild?{adminGuild}:{})});
        });
      }catch(error){json(res,error.status||500,{error:error.status?error.message:'Owner sign-in failed.'});}
    },

    // Host-private stop guard: match the existing one-minute live-session admission window.
    // Persisted seven-day cookies and closed/crashed clients must not block stop forever.
    async activeSessionCount() {
      const db=await load(),now=Date.now();
      return new Set(Object.entries(db.sessions).filter(([key,value])=>Object.hasOwn(db.users,value.id)&&value.expires>now&&(!isStaffBracketAccount(value.id)||ownerSessions.has(key))&&now-(sessionActivity.get(key)??value.lastActive??0)<60000).map(([,value])=>value.id)).size;
    },
    async activePermissions(id) {
      const db=await load();
      return Object.entries(db.sessions).some(([key,s])=>s.id===id&&s.expires>Date.now()&&(!isStaffBracketAccount(id)||ownerSessions.has(key))) ? accountPermissions(permissionsFile,id) : null;
    },
    // Host-private identity/permission join; never included in account HTTP
    // responses and never inferred from character names or NPC labels.
    // Private host-only provision authority. Delegated GM roles are not owners.
    async canProvisionAdminGuildSetup(id){if(!isStaffBracketAccount(id))return false;const db=await load();return Object.hasOwn(db.users,id)&&(await accountPermissions(permissionsFile,id)).capabilities.includes('gm:commands');},
    async canProvisionAdminGuildGlory(id){if(!isStaffBracketAccount(id))return false;const db=await load();return Object.hasOwn(db.users,id)&&(await accountPermissions(permissionsFile,id)).capabilities.includes('gm:commands');},
    async listAdminGuildCandidates(){const db=await load(),out=[];for(const [id,owner]of Object.entries(db.users)){if(NPC_ACCOUNT_ID.test(id))continue;const access=await accountPermissions(permissionsFile,id);if(!access.capabilities.includes('gm:commands'))continue;for(const ch of owner.characters||[])if(ch.authority==='server'&&!ch.npcPlayer&&!ch.npcSeed)out.push({account:id,characterId:ch.id});}return out;},
    async readAdminGuildAccess(id){const db=await load();return Object.hasOwn(db.users,id)?accountPermissions(permissionsFile,id):{role:'player',capabilities:[]};},
    async canReadAssets(req) {return !!await sessionUser(req);},
    /** Trusted simulation backend only. NPCs have no users, passwords, sessions or HTTP account routes. */
    flushPendingCommits,commitStats:()=>({...commitStats,pending:pendingCommits.length,coalesceMs:npcSaveCoalesceMs}),
    async loadNpcProfiles(){const db=await load();return structuredClone(db.npcProfiles||{});},
    async addNpcProfile(accountId,profile){
      validateNpcProfile(accountId,profile);
      return transactProfiles([accountId],db=>{
        db.npcProfiles||={};if(Object.hasOwn(db.users,accountId)||Object.hasOwn(db.npcProfiles,accountId))throw new HttpError(409,'This private NPC identity already exists.');
        if(Object.keys(db.npcProfiles).length>=NPC_PROFILE_LIMIT)throw new HttpError(400,'The private NPC limit has been reached.');
        db.npcProfiles[accountId]=storedNpcProfile(profile);return true;
      });
    },
    // Trusted native-population bootstrap only. Batching avoids rewriting the
    // whole private store once for every newly prepared server-owned actor.
    async addNpcProfiles(rows){
      if(!Array.isArray(rows)||!rows.length||rows.length>64)throw new HttpError(400,'Invalid private NPC bootstrap batch.');
      const input=structuredClone(rows),ids=new Set();for(const r of input){validateNpcProfile(r.accountId,r.profile);if(ids.has(r.accountId))throw new HttpError(409,'Duplicate private NPC identity.');ids.add(r.accountId);}
      return transactProfiles(input.map(r=>r.accountId),db=>{
        db.npcProfiles||={};if(Object.keys(db.npcProfiles).length+input.length>NPC_PROFILE_LIMIT)throw new HttpError(400,'The private NPC limit has been reached.');
        for(const r of input)if(Object.hasOwn(db.users,r.accountId)||Object.hasOwn(db.npcProfiles,r.accountId))throw new HttpError(409,'This private NPC identity already exists.');
        for(const r of input)db.npcProfiles[r.accountId]=storedNpcProfile(r.profile);return true;
      });
    },
    async saveNpcProfile(accountId,characterId,profile){
      validateNpcProfile(accountId,profile);
      return transactProfiles([accountId],db=>{
        const old=db.npcProfiles?.[accountId];if(!old||old.id!==characterId)return false;
        db.npcProfiles[accountId]=storedNpcProfile(profile,old);return true;
      });
    },
    async saveWorldAndNpcProfiles(updates){
      if(!Array.isArray(updates)||!updates.length||updates.length>187)throw new HttpError(400,'Invalid mixed progress transaction.');
      return transactProfiles(updates.map(u=>u?.accountId),db=>{
        let humanCount=0;const keys=new Set();
        const targets=updates.map(update=>{
          if(!update||typeof update.accountId!=='string'||typeof update.characterId!=='string'||!update.profile)throw new HttpError(400,'Invalid mixed progress target.');
          const {accountId,characterId,profile}=update,key=JSON.stringify([accountId,characterId]);if(keys.has(key))throw new HttpError(400,'Duplicate party character.');keys.add(key);
          if(NPC_ACCOUNT_ID.test(accountId)){
            validateNpcProfile(accountId,profile);const old=db.npcProfiles?.[accountId];if(!old||old.id!==characterId)throw new HttpError(404,'A private NPC character is unavailable.');return{npc:true,accountId,old,profile};
          }
          if(++humanCount>7)throw new HttpError(400,'Invalid party progress transaction.');
          const owner=Object.hasOwn(db.users,accountId)&&db.users[accountId],index=owner?.characters?.findIndex(c=>c.id===characterId&&c.authority==='server')??-1;
          if(index<0)throw new HttpError(404,'A party character is unavailable.');return{owner,index,profile};
        });
        for(const target of targets){
          if(target.npc){db.npcProfiles[target.accountId]=storedNpcProfile(target.profile,target.old);continue;}
          const {owner,index,profile}=target,old=owner.characters[index];owner.characters[index]={...structuredClone(profile),id:old.id,name:old.name,nameColor:old.nameColor||'white',classIndex:old.classIndex,className:old.className,authority:'server',lastPlayed:Date.now()};
          if(profile.accountFeatures){owner.accountFeatures=mergeAccountPremiumFeatures(owner.accountFeatures,profile.accountFeatures);delete owner.characters[index].accountFeatures;}owner.revision++;
        }
        return true;
      });
    },
    async getWorldProfile(accountId, characterId) {
      const db = await load();
      if (!Object.hasOwn(db.users, accountId)) return null;
      const ch = db.users[accountId].characters.find(c => c.id === characterId && c.authority === 'server');
      if(!ch)return null;
      const owner=db.users[accountId],profile=structuredClone(ch);
      if(owner.accountFeatures)profile.accountFeatures=structuredClone(owner.accountFeatures);
      return hydrateAccountPremium(profile);
    },
    async listWorldCharacters() {
      const db = await load();
      return Object.values(db.users).flatMap(owner => owner.characters.filter(c => c.authority === 'server').map(c => ({
        ref: characterRef(owner.id, c.id), name: c.name, classIndex: c.classIndex, level: c.level,
        map: c.map, lastPlayed: c.lastPlayed || 0, colosseum: c.colosseum || null,
      })));
    },
    async inspectWorldCharacter(ref) {
      const db = await load();
      for (const owner of Object.values(db.users)) for (const c of owner.characters) {
        if (c.authority === 'server' && characterRef(owner.id, c.id) === ref) return hydrateAccountPremium(structuredClone({...c,...(owner.accountFeatures?{accountFeatures:owner.accountFeatures}:{})}));
      }
      return null;
    },
    async saveWorldProfiles(updates) {
      if(!Array.isArray(updates)||updates.length<1||updates.length>7)throw new HttpError(400,'Invalid party progress transaction.');
      return transactProfiles(updates.map(u=>u?.accountId),db=>{
        const targets=updates.map(({accountId,characterId,profile})=>{
          const owner=Object.hasOwn(db.users,accountId)&&db.users[accountId];
          const index=owner?.characters?.findIndex(c=>c.id===characterId&&c.authority==='server')??-1;
          if(index<0)throw new HttpError(404,'A party character is unavailable.');
          return {owner,index,profile};
        });
        if(new Set(updates.map(u=>u.accountId+':'+u.characterId)).size!==updates.length)throw new HttpError(400,'Duplicate party character.');
        for(const {owner,index,profile} of targets){const old=owner.characters[index];owner.characters[index]={...structuredClone(profile),id:old.id,name:old.name,nameColor:old.nameColor||'white',classIndex:old.classIndex,className:old.className,authority:'server',lastPlayed:Date.now()};if(profile.accountFeatures){owner.accountFeatures=mergeAccountPremiumFeatures(owner.accountFeatures,profile.accountFeatures);delete owner.characters[index].accountFeatures;}owner.revision++;}
        return true;
      });
    },
    /** SHOP-WINDOWS purchase password: true when `password` is the account's sign-in password (scrypt, constant time). At most
     *  10 wrong attempts per account per minute (then 429), like the login's rate limit. The owner account never signs in with a
     *  password (ownerLaunch), so it is never verified here. */
    async verifyAccountPassword(accountId, password) {
      if (typeof accountId !== 'string' || accountId === 'admin' || typeof password !== 'string' || !password || password.length > 128) return false;
      const now = Date.now(), key = 'purchase:' + accountId;
      for (const [k, v] of purchaseAttempts) if (v.until < now) purchaseAttempts.delete(k);
      const rate = purchaseAttempts.get(key) || { count: 0, until: now + 60000 };
      if (rate.count >= 10) throw new HttpError(429, 'Too many password attempts. Try again in a minute.');
      const db = await load(), found = Object.hasOwn(db.users, accountId) ? db.users[accountId] : null;
      const actual = await scrypt(password, found?.salt || 'dekaron-unknown-account', 64);
      const ok = !!found?.digest && actual.length === Buffer.from(found.digest, 'hex').length && timingSafeEqual(actual, Buffer.from(found.digest, 'hex'));
      if (!ok) { rate.count++; purchaseAttempts.set(key, rate); }
      return ok;
    },
    async renameWorldCharacter(accountId, characterId, name, nameColor, profile, {staffOverride=false}={}) {
      if(staffOverride&&!(await accountPermissions(permissionsFile,accountId)).capabilities.includes('gm:commands'))throw new HttpError(403,'Staff labels require a currently authorized staff account.');
      name = staffOverride ? normalizeStaffCharacterName(name) : normalizeCharacterName(name);
      if (nameColor !== undefined) nameColor = normalizeCharacterNameColor(nameColor);
      return transact(db => {
        const owner=Object.hasOwn(db.users,accountId) && db.users[accountId];
        const index=owner?owner.characters.findIndex(c=>c.id===characterId && c.authority==='server'):-1;
        if(index<0) throw new HttpError(404,'The character is no longer available.');
        if(Object.values(db.users).some(u=>u.characters.some(c=>c.authority==='server' && (u.id!==accountId || c.id!==characterId) && characterNameKey(c.name)===characterNameKey(name)))) throw new HttpError(409,'That character name is already taken.');
        // Optional staged profile (the name change item): the spent item and the new name commit in this one write.
        if(profile){const old=owner.characters[index];owner.characters[index]={...structuredClone(profile),id:old.id,name:old.name,nameColor:old.nameColor||'white',classIndex:old.classIndex,className:old.className,authority:'server',lastPlayed:Date.now()};if(profile.accountFeatures){owner.accountFeatures=mergeAccountPremiumFeatures(owner.accountFeatures,profile.accountFeatures);delete owner.characters[index].accountFeatures;}}
        const character=owner.characters[index];
        character.name=name;if(nameColor!==undefined)character.nameColor=nameColor;owner.revision++;return {id:character.id,name,nameColor:character.nameColor||'white'};
      });
    },
    async saveWorldProfile(accountId, characterId, profile) {
      return transactUser(accountId, db => {   // touches db.users[accountId] only
        const owner = Object.hasOwn(db.users, accountId) && db.users[accountId];
        const index = owner ? owner.characters.findIndex(c => c.id === characterId && c.authority === 'server') : -1;
        if (index < 0) return false;
        const old = owner.characters[index];
        owner.characters[index] = { ...structuredClone(profile), id: old.id, name: old.name, nameColor: old.nameColor || 'white', classIndex: old.classIndex, className: old.className, authority: 'server', lastPlayed: Date.now() };
        if(profile.accountFeatures){owner.accountFeatures=mergeAccountPremiumFeatures(owner.accountFeatures,profile.accountFeatures);delete owner.characters[index].accountFeatures;}
        owner.revision++;
        return true;
      });
    },
    /** Owner/staff tool path: clears a 30:116 lock (Global: the player contacts support). Does not reveal or change the PIN. */
    async unlockSecondPassword(accountId){return transact(db=>{const u=Object.hasOwn(db.users,accountId)?db.users[accountId]:null;if(!u)throw new HttpError(404,'That registered account does not exist.');if(!u.secondPw)return {ok:true,code:113,text:'2nd password is not exist'};u.secondPw={...u.secondPw,wrong:0,locked:false};return {ok:true,code:106,account:accountId};});},
    async handle(req, res, pathname) {
      if (!pathname.startsWith('/api/auth/') && pathname !== '/api/characters' && pathname !== '/api/rankings') return false;
      try {
        const method = req.method;
        if (method !== 'GET' && method !== 'HEAD') {
          const origin = req.headers.origin;
          if (origin) { let allowed=false;try{allowed=new URL(origin).host===req.headers.host;}catch{}if(!allowed)throw new HttpError(403, 'Cross-origin writes are not allowed.'); }
          if (req.headers['sec-fetch-site'] === 'cross-site') throw new HttpError(403, 'Cross-site writes are not allowed.');
          if (!String(req.headers['content-type'] || '').startsWith('application/json') && pathname !== '/api/auth/logout') throw new HttpError(415, 'Use application/json.');
        }
        if (method === 'POST' && pathname === '/api/auth/launch-ticket') {
          launchRate(req);const input=await body(req,512);if(Object.keys(input).length)throw new HttpError(400,'Launch accepts no account or credential fields.');
          const source=hash(token(req)),current=await user(req);if(!current)throw new HttpError(401,'Log in before launching.');
          await withAccountSession(current.id,async()=>{
            const active=(await load()).sessions[source];if(!active||active.id!==current.id||active.expires<=Date.now())throw new HttpError(401,'Your account session changed. Log in again.');
            const access=await launchAccess(req);if(!access?.allowed)throw new HttpError(401,'Enter the server password before launching.');
            pruneLaunchTickets();invalidateLaunchTickets(current.id);if(launchTickets.size>=1000)throw new HttpError(503,'Launch limit reached. Try again shortly.');
            const ticket=randomBytes(32).toString('hex');launchTickets.set(hash(ticket),{id:current.id,source,host:launchHost(req),expires:launchNow()+LAUNCH_TICKET_MS,proof:access.proof});json(res,200,{ticket,expiresIn:LAUNCH_TICKET_MS/1000});
          });
        } else if (method === 'POST' && pathname === '/api/auth/launch-redeem') {
          launchRate(req);const input=await body(req,512);if(Object.keys(input).length!==1||typeof input.ticket!=='string'||! /^[a-f0-9]{64}$/.test(input.ticket))throw new HttpError(400,'Invalid launch ticket.');
          pruneLaunchTickets();const key=hash(input.ticket),ticket=launchTickets.get(key);if(!ticket)throw new HttpError(401,'Launch expired or was already used. Log in again.');
          await withAccountSession(ticket.id,async()=>{
            if(launchTickets.get(key)!==ticket||ticket.expires<=launchNow())throw new HttpError(401,'Launch expired or was already used. Log in again.');
            if(isStaffBracketAccount(ticket.id)&&(!ticket.owner||!ownerLocalRequest(req)))throw new HttpError(403,'Local admin cannot connect remotely.');
            if(ticket.host!==launchHost(req))throw new HttpError(401,'Launch belongs to a different server address. Log in again.');
            if(ticket.owner){launchTickets.delete(key);await sessionUnlocked(req,res,ticket.id,200,[],true);return;}
            launchTickets.delete(key);const active=(await load()).sessions[ticket.source];if(!active||active.id!==ticket.id||active.expires<=Date.now())throw new HttpError(401,'Your account session changed. Log in again.');
            const invite=await launchInvite(req,ticket.proof);if(!invite?.allowed)throw new HttpError(401,'Server access expired. Enter the server password again.');
            await sessionUnlocked(req,res,ticket.id,200,invite.cookie?[invite.cookie]:[],false,ticket.source);
          });
        } else if (method === 'GET' && pathname === '/api/auth/demo') {
          json(res,200,{localDemo:false});
        } else if (method === 'POST' && ['/api/auth/signup', '/api/auth/login'].includes(pathname)) {
          const data = await body(req, 4096), id = String(data.id || '').trim().toLowerCase(), password = data.password;
          if (Object.keys(data).some(key => !['id', 'password', ...(loginVersionGate?.acceptsField ? ['clientVersion'] : [])].includes(key))) throw new HttpError(400, 'Login and signup accept only ID and password.');
          if (loginVersionGate?.enabled) { const gate = loginVersionGate.check(data.clientVersion); if (!gate.ok) throw new HttpError(426, gate.error); }
          if (!/^[a-z0-9_-]{3,32}$/.test(id) || id === '__proto__' || typeof password !== 'string' || password.length < 6 || password.length > 128) throw new HttpError(400, 'Use an ID of 3–32 letters, numbers, underscores or dashes and a password of 6–128 characters.');
          if(id==='admin'||id==='gm'||id==='dev')throw new HttpError(403,'This account is reserved for the installation owner launcher.');
          const key = req.relay?.clientKey || req.socket.remoteAddress || 'local', now = Date.now();
          for (const [k, v] of attempts) if (v.until < now) attempts.delete(k);
          const rate = attempts.get(key) || { count: 0, until: now + 60000 };
          rate.count++; attempts.set(key, rate);
          if (rate.count > 30) throw new HttpError(429, 'Too many login attempts. Try again in a minute.');
          const db = await load();
          if (pathname.endsWith('/signup')) {
            const salt = randomBytes(16).toString('hex'), digest = (await scrypt(password, salt, 64)).toString('hex');
            await transactUser(id, next => {
              if (Object.hasOwn(next.users, id)) throw new HttpError(409, 'That account ID is already taken.');
              next.users[id] = { id, salt, digest, created: now, revision: 0, characters: [] };
            });
            await session(req, res, id, 201);
          } else {
            const found = Object.hasOwn(db.users, id) ? db.users[id] : null;
            const actual = await scrypt(password, found?.salt || 'dekaron-unknown-account', 64);
            if (!found || !timingSafeEqual(actual, Buffer.from(found.digest, 'hex'))) throw new HttpError(401, 'Incorrect ID or password.');
            await session(req, res, id);
          }
        } else if (method === 'POST' && pathname === '/api/auth/remember') {
          // "Save account" (item 11a2): the signed-in session asks THIS server for a remember token. Only a SHA-256 of the token is
          // stored, on this server's own account record, so it can never be replayed against another server and no password is saved.
          rememberRate(req);
          const input=await body(req,512);if(Object.keys(input).some(k=>k!=='replace'))throw new HttpError(400,'Remember accepts only the previous token to replace.');
          if(input.replace!==undefined&&!REMEMBER_TOKEN.test(String(input.replace)))throw new HttpError(400,'Invalid remember token.');
          const current=await user(req);if(!current)throw new HttpError(401,'Log in before saving this account.');
          if(isStaffBracketAccount(current.id))throw new HttpError(403,'The installation owner account cannot be saved.');
          const secret=randomBytes(32).toString('hex'),now=Date.now();
          await transactUser(current.id,db=>{const u=db.users[current.id];if(!u)throw new HttpError(401,'Log in before saving this account.');
            const old=input.replace===undefined?null:hash(input.replace);
            u.remember=(Array.isArray(u.remember)?u.remember:[]).filter(r=>r.expires>now&&r.h!==old);
            u.remember.push({h:hash(secret),created:now,expires:now+REMEMBER_MS});u.remember=u.remember.slice(-MAX_REMEMBER);});
          json(res,200,{token:secret,expiresIn:REMEMBER_MS/1000});
        } else if (method === 'POST' && pathname === '/api/auth/remember-login') {
          rememberRate(req);
          const data=await body(req,512);if(Object.keys(data).some(k=>!['id','token'].includes(k)))throw new HttpError(400,'Saved login accepts only ID and token.');
          const id=String(data.id||'').trim().toLowerCase();
          if(!/^[a-z0-9_-]{3,32}$/.test(id)||id==='__proto__'||id==='admin'||id==='gm'||id==='dev'||!REMEMBER_TOKEN.test(String(data.token)))throw new HttpError(401,'This saved login is no longer valid. Sign in with your password.');
          const db=await load(),found=Object.hasOwn(db.users,id)?db.users[id]:null,digest=Buffer.from(hash(data.token),'hex');
          const match=!!found&&(Array.isArray(found.remember)?found.remember:[]).some(r=>r.expires>Date.now()&&/^[a-f0-9]{64}$/.test(r.h)&&timingSafeEqual(Buffer.from(r.h,'hex'),digest));
          if(!match)throw new HttpError(401,'This saved login is no longer valid. Sign in with your password.');
          await session(req,res,id);
        } else if (method === 'POST' && pathname === '/api/auth/remember-revoke') {
          rememberRate(req);
          const data=await body(req,512);if(Object.keys(data).some(k=>!['id','token'].includes(k)))throw new HttpError(400,'Revoke accepts only ID and token.');
          const id=String(data.id||'').trim().toLowerCase();
          if(/^[a-z0-9_-]{3,32}$/.test(id)&&id!=='__proto__'&&REMEMBER_TOKEN.test(String(data.token))){const h=hash(data.token);
            await transactUser(id,db=>{const u=Object.hasOwn(db.users,id)?db.users[id]:null;if(u&&Array.isArray(u.remember))u.remember=u.remember.filter(r=>r.h!==h);});}
          json(res,200,{ok:true});
        } else if (method === 'POST' && pathname === '/api/auth/logout') {
          const key=hash(token(req)),current=(await load()).sessions[key];
          const logout=async()=>{const id=await transactSessions((db,ops)=>{const found=ops.get(key);ops.delete(key);return found&&found.expires>Date.now()?found.id:null;});if(id){invalidateLaunchTickets(id,key);await onInvalidate(id,'logout');}};
          if(current)await withAccountSession(current.id,logout);else await logout();
          json(res, 200, { ok: true }, { 'Set-Cookie': cookie(req, '', 0) });
        } else if (method === 'GET' && pathname === '/api/auth/me') {
          const current = await user(req); json(res, 200, { id: current?.id || null, role: current?.role || null, capabilities: current?.capabilities || [] });
        } else if (pathname === '/api/characters' && ['GET', 'PUT', 'POST', 'DELETE'].includes(method)) {
          const current = await user(req);
          if (!current) throw new HttpError(401, 'Log in to sync your characters.');
          if (method === 'GET') json(res, 200, { account: current.id, revision: current.revision, characters: current.characters });
          else if (method === 'DELETE') {
            // Character select > Delete: the host removes an ONLINE character (a browser backup can never delete one, see PUT below).
            // The typed name is checked again here; a character that is in a guild must leave it first (guild rosters keep character refs).
            // cancelPending:true (Global client action 5 / btn_delete_cancel): clear pendingDeleteAt only — no removal.
            // Delay duration remains UNRESOLVED; host only stores/clears a field the Global client already displays.
            const data = await body(req, 1024);
            if (data.account !== current.id) throw new HttpError(409, 'The signed-in account changed. Reload before deleting a character.');
            if (typeof data.id !== 'string' || !data.id) throw new HttpError(400, 'Choose a character to confirm.');
            if (data.cancelPending === true) {
              const result = await transactUser(current.id, db => {
                const owner = db.users[current.id];
                const index = owner.characters.findIndex(c => c.id === data.id && c.authority === 'server');
                if (index < 0) throw new HttpError(404, 'That online character no longer exists.');
                const cur = owner.characters[index];
                const next = { ...cur };
                delete next.pendingDeleteAt; delete next.deleteAt; delete next.pending_delete_at;
                owner.characters[index] = next; owner.revision++;
                return { account: owner.id, revision: owner.revision, characters: owner.characters, cancelledPending: cur.id };
              });
              json(res, 200, result);
            } else {
              if (typeof data.name !== 'string') throw new HttpError(400, 'Choose a character and type its name to confirm.');
              if (isAccountOnline(current.id)) throw new HttpError(409, 'This account is connected to the world. Leave the world before deleting a character.');
              const result = await transactUser(current.id, db => {
                const owner = db.users[current.id];
                const index = owner.characters.findIndex(c => c.id === data.id && c.authority === 'server');
                if (index < 0) throw new HttpError(404, 'That online character no longer exists.');
                const doomed = owner.characters[index];
                if (characterNameKey(doomed.name) !== characterNameKey(data.name)) throw new HttpError(400, 'Type the character name exactly to confirm the deletion.');
                const ref = characterRef(owner.id, doomed.id);
                if (Object.values(db.social?.guilds || {}).some(g => (g.members || []).some(m => m.ref === ref))) throw new HttpError(409, 'This character is in a guild. Leave (or hand over) the guild first, then delete it.');
                owner.characters.splice(index, 1); owner.revision++;
                return { account: owner.id, revision: owner.revision, characters: owner.characters, deleted: doomed.id };
              });
              json(res, 200, result);
            }
          }
          else if (method === 'POST') {
            const data = await body(req, 4096);
            if (data.account !== current.id) throw new HttpError(409, 'The signed-in account changed. Reload before creating a character.');
            const name = normalizeCharacterName(data.name), nameColor = normalizeCharacterNameColor(data.nameColor), classIndex = data.classIndex;
            if (!Number.isInteger(classIndex) || classIndex < 0 || classIndex > 14) throw new HttpError(400, 'Choose a valid class.');
            const classes = JSON.parse(await fs.readFile(path.join(gamedataRoot, 'classes.json'), 'utf8'));
            const def = (classes.classes || []).find(c => Number(c.index) === classIndex);
            if (!def) throw new HttpError(400, 'Unknown class.');
            let staffPrivileges = false;
            let staffRole = null;
            let staffName = name;
            if (data.staffPrivileges === true) {
              if (!current.capabilities?.includes('gm:commands')) throw new HttpError(403, 'Admin / GM / Dev character create requires max staff privileges.');
              staffPrivileges = true;
              staffRole = data.staffRole != null ? normalizeStaffBracket(data.staffRole) : (isStaffBracketAccount(current.id) ? normalizeStaffBracket(current.id) : 'admin');
              staffName = normalizeStaffCharacterName('[' + staffBracket(staffRole).tag + '] ' + stripStaffNameTag(name), staffBracket(staffRole).tag);
            } else if (data.staffPrivileges != null) throw new HttpError(400, 'staffPrivileges must be true when set.');
            else if (data.staffRole != null) throw new HttpError(400, 'staffRole requires staffPrivileges.');
            const ch = { id: `c${randomUUID().replace(/-/g, '')}`, name: staffName, nameColor, classIndex, className: def.name, authority: 'server',
              starterSkillPending: true, level: 1, exp: 0, dil: 0, hp: null, mp: null, statPoints: 0, skillPoints: 0, stats: null, map: 150,
              pos: { x: 203.5, z: 247.5, dirDeg: 0 }, inventory: [], equipment: {}, hotbar: [], skills: {},
              kills: 0, deaths: 0, playSeconds: 0, created: Date.now(), lastPlayed: Date.now() };
            // STAFF_CREATE_HOOK: unified Admin/GM/Dev checkbox -> full admin PvP/mobs builds when world data loads.
            if (staffPrivileges) {
              let worldData = null;
              try { worldData = await loadWorldData({ gamedataRoot }); } catch {}
              applyStaffCharacterCreate(ch, { account: current.id, classIndex, data: worldData || undefined, staffRole });
            }
            const result = await transactUser(current.id, db => {
              const owner = db.users[current.id];
              if (owner.characters.length >= CHAR_TRADE_ENGINE_CHOSEN.receiverMaxCharacters) throw new HttpError(409, 'Character slots are full.'); // Evidenced Global UI capacity 18 (see engine-chosen-char-trade.js)
              if (Object.values(db.users).some(u => u.characters.some(c => c.authority === 'server' && characterNameKey(c.name) === characterNameKey(staffName)))) throw new HttpError(409, 'That character name is already taken.');
              owner.characters.push(ch); owner.revision++;
              return { account: owner.id, revision: owner.revision, character: ch, characters: owner.characters };
            });
            json(res, 201, result);
          }
          else {
            const data = await body(req), characters = validateCharacters(data.characters);
            // A different login in another tab must never receive this tab's characters.
            if (data.account !== current.id) throw new HttpError(409, 'The signed-in account changed. Reload before saving.');
            const result = await transactUser(current.id, db => {
              const owner = db.users[current.id];
              if (data.revision !== owner.revision) throw new HttpError(409, 'Characters changed in another session. Your local backup is preserved; reload to reconcile before syncing.');
              const trusted = owner.characters.filter(c => c.authority === 'server');
              const trustedIds = new Set(trusted.map(c => c.id));
              if (characters.some(c => c.authority === 'server' && !trustedIds.has(c.id))) throw new HttpError(403, 'Verified characters must be created by the server.');
              // Client backups cannot rewrite or delete characters belonging to the authoritative world.
              const combined = [...trusted, ...characters.filter(c => !trustedIds.has(c.id) && c.authority !== 'server')];
              if (combined.length > accountCharacterLimit(owner.characters.length)) throw new HttpError(400, `An account can hold at most ${CHAR_TRADE_ENGINE_CHOSEN.receiverMaxCharacters} characters.`); // Evidenced Global UI capacity 18
              owner.characters = combined; owner.revision++;
              return { account: owner.id, revision: owner.revision };
            });
            json(res, 200, result);
          }
        } else if (method === 'GET' && pathname === '/api/rankings') {
          const db = await load();
          const rankings = Object.values(db.users).flatMap(u => u.characters).filter(ch => ch.authority === 'server').map(ch => ({ name: ch.name, className: ch.className || `Class ${ch.classIndex}`, level: ch.level, rebirths: Number(ch.rebirths ?? ch.rebirthCount ?? 0) || 0 }))
            .filter(ch => ch.rebirths > 0).sort((a, b) => b.rebirths - a.rebirths || b.level - a.level).slice(0, 100).map((ch, i) => ({ rank: i + 1, ...ch }));
          json(res, 200, { rankings });
        } else if (pathname === '/api/auth/secondpw' || pathname.startsWith('/api/auth/secondpw/')) {
          await handleSecondPw(req, res, method, pathname);
        } else json(res, 404, { error: 'Unknown account endpoint.' });
      } catch (err) {
        if (!err.status) console.error('[accounts]', err);
        if (!res.headersSent) json(res, err.status || 500, { error: err.status ? err.message : 'Account storage is unavailable. Please try again.' });
      }
      return true;
    },
  };
}
