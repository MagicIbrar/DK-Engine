// server/forum/api.mjs — routes /api/forum/* for server.mjs. Zero external deps: plain node:http
// req/res, JSON in/out. Import and call handleForumApi(req, res, pathname, method); it returns
// true if it handled (and ended) the response, false if the path didn't match anything here.
import * as store from './store.mjs';

const PORT = Number(process.env.PORT || 7777);
const MAX_BODY = 64 * 1024;

function readJsonBody(req) {
  return new Promise((resolve, reject) => {
    let size = 0;
    const chunks = [];
    req.on('data', (chunk) => {
      size += chunk.length;
      if (size > MAX_BODY) { reject(new store.HttpError(413, 'request body too large')); req.destroy(); return; }
      chunks.push(chunk);
    });
    req.on('end', () => {
      if (!chunks.length) return resolve({});
      try { resolve(JSON.parse(Buffer.concat(chunks).toString('utf8'))); }
      catch { reject(new store.HttpError(400, 'invalid JSON body')); }
    });
    req.on('error', reject);
  });
}

// Resolves the logged-in user's id by asking this same server's own /api/auth/me, forwarding the
// request's cookies. Keeps this module decoupled from however the accounts system stores
// sessions; returns null (not logged in / accounts service not up yet) instead of throwing.
async function currentUser(req) {
  try {
    const headers = {};
    if (req.headers.cookie) headers.cookie = req.headers.cookie;
    if (req.headers.authorization) headers.authorization = req.headers.authorization;
    const r = await fetch(`http://127.0.0.1:${PORT}/api/auth/me`, { headers });
    if (!r.ok) return null;
    const data = await r.json().catch(() => null);
    const id = data?.id ?? data?.account ?? data?.user?.id ?? data?.user?.account ?? null;
    return id ? String(id) : null;
  } catch {
    return null; // accounts endpoint not reachable/implemented yet
  }
}

function sendJson(res, status, body) {
  const buf = Buffer.from(JSON.stringify(body));
  res.writeHead(status, {
    'Content-Type': 'application/json; charset=utf-8',
    'Content-Length': buf.length,
    'Cache-Control': 'no-cache',
  });
  res.end(buf);
}

export async function handleForumApi(req, res, pathname, method, resolveUser = null) {
  // pathname always starts with /api/forum/ when this is called
  const seg = pathname.split('/').filter(Boolean).slice(2); // drop 'api','forum'

  try {
    // GET /api/forum/categories
    if (method === 'GET' && seg.length === 1 && seg[0] === 'categories') {
      sendJson(res, 200, { categories: store.listCategories() });
      return true;
    }

    // GET /api/forum/categories/:id/threads
    if (method === 'GET' && seg.length === 3 && seg[0] === 'categories' && seg[2] === 'threads') {
      const categoryId = decodeURIComponent(seg[1]);
      if (!store.getCategory(categoryId)) { sendJson(res, 404, { error: 'unknown category' }); return true; }
      sendJson(res, 200, { category: store.getCategory(categoryId), threads: store.listThreads(categoryId) });
      return true;
    }

    // POST /api/forum/categories/:id/threads  {title, body}
    if (method === 'POST' && seg.length === 3 && seg[0] === 'categories' && seg[2] === 'threads') {
      const categoryId = decodeURIComponent(seg[1]);
      const author = resolveUser ? (await resolveUser(req))?.id : await currentUser(req);
      if (!author) { sendJson(res, 401, { error: 'login required' }); return true; }
      const { title, body } = await readJsonBody(req);
      const thread = store.createThread({ categoryId, title, body, author });
      sendJson(res, 201, { thread });
      return true;
    }

    // GET /api/forum/threads/:id
    if (method === 'GET' && seg.length === 2 && seg[0] === 'threads') {
      const id = decodeURIComponent(seg[1]);
      const result = store.getThread(id);
      if (!result) { sendJson(res, 404, { error: 'unknown thread' }); return true; }
      sendJson(res, 200, result);
      return true;
    }

    // POST /api/forum/threads/:id/posts  {body}
    if (method === 'POST' && seg.length === 3 && seg[0] === 'threads' && seg[2] === 'posts') {
      const threadId = decodeURIComponent(seg[1]);
      const author = resolveUser ? (await resolveUser(req))?.id : await currentUser(req);
      if (!author) { sendJson(res, 401, { error: 'login required' }); return true; }
      const { body } = await readJsonBody(req);
      const post = store.addPost({ threadId, body, author });
      sendJson(res, 201, { post });
      return true;
    }

    return false; // not a forum route this module knows
  } catch (err) {
    const status = err instanceof store.HttpError ? err.status : 500;
    if (status === 500) console.error('[forum]', err);
    sendJson(res, status, { error: err.message || 'forum error' });
    return true;
  }
}
