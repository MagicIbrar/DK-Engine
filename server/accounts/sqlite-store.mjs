// Dedicated-server account persistence. Static Global assets remain files;
// mutable account, character, session and NPC documents live in SQLite rows.
import fs from 'node:fs';
import path from 'node:path';
import { DatabaseSync } from 'node:sqlite';

const SCOPES = Object.freeze({ users: 'user', sessions: 'session', npcProfiles: 'npc' });
const parse = row => JSON.parse(row.json);

export class SqliteAccountStore {
  constructor(databaseFile) {
    fs.mkdirSync(path.dirname(databaseFile), { recursive: true });
    this.db = new DatabaseSync(databaseFile);
    this.db.exec('PRAGMA journal_mode=WAL; PRAGMA synchronous=FULL; PRAGMA busy_timeout=5000;');
    this.db.exec('CREATE TABLE IF NOT EXISTS documents (scope TEXT NOT NULL, id TEXT NOT NULL, json TEXT NOT NULL, PRIMARY KEY(scope,id)) STRICT;');
    this.select = this.db.prepare('SELECT scope,id,json FROM documents');
    this.first = this.db.prepare('SELECT 1 FROM documents LIMIT 1');
    this.put = this.db.prepare('INSERT INTO documents(scope,id,json) VALUES (?,?,?) ON CONFLICT(scope,id) DO UPDATE SET json=excluded.json');
    this.remove = this.db.prepare('DELETE FROM documents WHERE scope=? AND id=?');
    this.cache = new Map();
  }

  empty() { return this.first.get() === undefined; }

  read() {
    const state = { version: 1, users: {}, sessions: {} };
    this.cache.clear();
    for (const row of this.select.all()) {
      this.cache.set(`${row.scope}\0${row.id}`, row.json);
      const value = parse(row);
      if (row.scope === 'root') state[row.id] = value;
      else if (row.scope === 'user') state.users[row.id] = value;
      else if (row.scope === 'session') state.sessions[row.id] = value;
      else if (row.scope === 'npc') (state.npcProfiles ||= {})[row.id] = value;
      else throw new Error('Unknown account SQL record scope');
    }
    if (state.version !== 1 || !state.users || !state.sessions) throw new Error('Invalid SQL account store');
    return state;
  }

  write(state) {
    if (state?.version !== 1 || !state.users || !state.sessions) throw new Error('Invalid account snapshot');
    const next = new Map();
    for (const [field, scope] of Object.entries(SCOPES)) {
      for (const [id, value] of Object.entries(state[field] || {})) next.set(`${scope}\0${id}`, JSON.stringify(value));
    }
    for (const [id, value] of Object.entries(state)) {
      if (id === 'users' || id === 'sessions' || id === 'npcProfiles') continue;
      next.set(`root\0${id}`, JSON.stringify(value));
    }
    this.db.exec('BEGIN IMMEDIATE');
    try {
      for (const [key, json] of next) {
        if (json === undefined) throw new Error('Account document cannot be serialized');
        if (this.cache.get(key) !== json) {
          const split = key.indexOf('\0');
          this.put.run(key.slice(0, split), key.slice(split + 1), json);
        }
      }
      for (const key of this.cache.keys()) if (!next.has(key)) {
        const split = key.indexOf('\0');
        this.remove.run(key.slice(0, split), key.slice(split + 1));
      }
      this.db.exec('COMMIT');
      this.cache = next;
    } catch (error) {
      this.db.exec('ROLLBACK');
      throw error;
    }
  }

  close() { this.db.close(); }
}

/** Read-only identity lookup for host permission controls outside the account API. */
export function sqliteAccountIds(databaseFile) {
  const db = new DatabaseSync(databaseFile, { readOnly: true });
  try { return db.prepare("SELECT id FROM documents WHERE scope='user' ORDER BY id").all().map(row => row.id); }
  finally { db.close(); }
}
