// server/forum/store.mjs — tiny JSON-file forum store. No database: categories are seeded once,
// threads/posts persist to server/forum/data.json (created on first write). Good enough for a
// small community site; swap for a real DB later without changing api.mjs's call shape.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const HERE = path.dirname(fileURLToPath(import.meta.url));
const DATA_FILE = path.join(HERE, 'data.json');

const DEFAULT_CATEGORIES = [
  { id: 'announcements', name: 'Announcements', description: 'Official news and patch notes.', order: 1 },
  { id: 'general', name: 'General Discussion', description: 'Talk about Dekaron Online.', order: 2 },
  { id: 'classes', name: 'Classes & Builds', description: 'Warrior, Berserker, Priestess, Magician, Petmaster, Sader, Dragon Knight, Archer builds.', order: 3 },
  { id: 'trade', name: 'Marketplace', description: 'Buy, sell and trade with other players.', order: 4 },
  { id: 'support', name: 'Bug Reports & Support', description: 'Report issues and get help.', order: 5 },
];

class HttpError extends Error {
  constructor(status, message) { super(message); this.status = status; }
}

let state = null;

function load() {
  if (state) return state;
  try {
    state = JSON.parse(fs.readFileSync(DATA_FILE, 'utf8'));
  } catch {
    state = { categories: DEFAULT_CATEGORIES.slice(), threads: [], posts: [], nextThreadId: 1, nextPostId: 1 };
  }
  if (!Array.isArray(state.categories)) state.categories = [];
  if (!Array.isArray(state.threads)) state.threads = [];
  if (!Array.isArray(state.posts)) state.posts = [];
  if (!state.nextThreadId) state.nextThreadId = 1;
  if (!state.nextPostId) state.nextPostId = 1;
  // Backfill categories added to DEFAULT_CATEGORIES after a store already exists on disk.
  for (const c of DEFAULT_CATEGORIES) {
    if (!state.categories.some((x) => x.id === c.id)) state.categories.push(c);
  }
  return state;
}

let saveTimer = null;
function scheduleSave() {
  clearTimeout(saveTimer);
  saveTimer = setTimeout(() => {
    try { fs.writeFileSync(DATA_FILE, JSON.stringify(state, null, 2)); }
    catch (err) { console.error('[forum] failed to save data.json:', err.message); }
  }, 50);
}

function decorateThread(t, s) {
  const posts = s.posts.filter((p) => p.threadId === t.id);
  const lastActivity = posts.reduce((max, p) => Math.max(max, p.createdAt), t.createdAt);
  return {
    id: t.id, categoryId: t.categoryId, title: t.title, author: t.author,
    createdAt: t.createdAt, pinned: !!t.pinned, locked: !!t.locked,
    postCount: posts.length, lastActivity,
  };
}

export function listCategories() {
  const s = load();
  return s.categories
    .slice()
    .sort((a, b) => (a.order || 0) - (b.order || 0))
    .map((c) => ({ ...c, threadCount: s.threads.filter((t) => t.categoryId === c.id).length }));
}

export function getCategory(id) {
  return load().categories.find((c) => c.id === id) || null;
}

export function listThreads(categoryId) {
  const s = load();
  return s.threads
    .filter((t) => t.categoryId === categoryId)
    .map((t) => decorateThread(t, s))
    .sort((a, b) => (Number(b.pinned) - Number(a.pinned)) || (b.lastActivity - a.lastActivity));
}

export function getThread(id) {
  const s = load();
  const t = s.threads.find((x) => x.id === id);
  if (!t) return null;
  const posts = s.posts
    .filter((p) => p.threadId === id)
    .sort((a, b) => a.createdAt - b.createdAt)
    .map((p) => ({ id: p.id, threadId: p.threadId, author: p.author, body: p.body, createdAt: p.createdAt }));
  return { thread: decorateThread(t, s), posts };
}

function cleanTitle(v) { return String(v ?? '').trim().slice(0, 120); }
function cleanBody(v) { return String(v ?? '').trim().slice(0, 8000); }

export function createThread({ categoryId, title, body, author }) {
  const s = load();
  if (!s.categories.some((c) => c.id === categoryId)) throw new HttpError(404, 'unknown category');
  title = cleanTitle(title);
  body = cleanBody(body);
  if (!title) throw new HttpError(400, 'title is required');
  if (!body) throw new HttpError(400, 'body is required');
  if (!author) throw new HttpError(401, 'login required');
  const now = Date.now();
  const id = String(s.nextThreadId++);
  const thread = { id, categoryId, title, author, createdAt: now, pinned: false, locked: false };
  s.threads.push(thread);
  const postId = String(s.nextPostId++);
  s.posts.push({ id: postId, threadId: id, author, body, createdAt: now });
  scheduleSave();
  return decorateThread(thread, s);
}

export function addPost({ threadId, body, author }) {
  const s = load();
  const t = s.threads.find((x) => x.id === threadId);
  if (!t) throw new HttpError(404, 'unknown thread');
  if (t.locked) throw new HttpError(403, 'thread is locked');
  body = cleanBody(body);
  if (!body) throw new HttpError(400, 'body is required');
  if (!author) throw new HttpError(401, 'login required');
  const id = String(s.nextPostId++);
  const post = { id, threadId, author, body, createdAt: Date.now() };
  s.posts.push(post);
  scheduleSave();
  return post;
}

export { HttpError };
