// site/js/api.js — thin fetch wrapper for the accounts API (/api/auth/*), the forum API
// (/api/forum/*, owned by this site) and the rankings endpoint. Same-origin (server.mjs serves
// both the site and the API), so no CORS headaches; credentials:'include' carries the session
// cookie the accounts API sets on login.

export class ApiError extends Error {
  constructor(message, status, data) {
    super(message);
    this.name = 'ApiError';
    this.status = status;
    this.data = data;
  }
}

async function request(path, { method = 'GET', body } = {}) {
  let res;
  try {
    res = await fetch(path, {
      method,
      credentials: 'include',
      headers: body !== undefined ? { 'Content-Type': 'application/json' } : undefined,
      body: body !== undefined ? JSON.stringify(body) : undefined,
    });
  } catch {
    throw new ApiError('Could not reach the server. Is it running?', 0, null);
  }
  let data = null;
  const text = await res.text().catch(() => '');
  if (text) { try { data = JSON.parse(text); } catch { data = null; } }
  if (!res.ok) {
    const message = (data && (data.error || data.message)) || `${res.status} ${res.statusText}`;
    throw new ApiError(message, res.status, data);
  }
  return data;
}

export const auth = {
  signup: (id, password) => request('/api/auth/signup', { method: 'POST', body: { id, password } }),
  login: (id, password) => request('/api/auth/login', { method: 'POST', body: { id, password } }),
  logout: () => request('/api/auth/logout', { method: 'POST' }),
  me: () => request('/api/auth/me'),
};

export const forum = {
  categories: () => request('/api/forum/categories'),
  threads: (categoryId) => request(`/api/forum/categories/${encodeURIComponent(categoryId)}/threads`),
  thread: (id) => request(`/api/forum/threads/${encodeURIComponent(id)}`),
  createThread: (categoryId, title, body) =>
    request(`/api/forum/categories/${encodeURIComponent(categoryId)}/threads`, { method: 'POST', body: { title, body } }),
  reply: (threadId, body) =>
    request(`/api/forum/threads/${encodeURIComponent(threadId)}/posts`, { method: 'POST', body: { body } }),
};

export const rankings = {
  rebirth: () => request('/api/rankings'),
};

export const characters = { list: () => request('/api/characters') };

/** Resolves the current user id, or null if not logged in / accounts API not up yet. Never throws. */
export async function currentUserId() {
  try {
    const me = await auth.me();
    return me?.id ?? me?.account ?? me?.user?.id ?? me?.user?.account ?? null;
  } catch {
    return null;
  }
}
