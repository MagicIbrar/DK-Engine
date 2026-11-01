// site/js/forum-category.js — thread list + new-thread form for forum-category.html.
import { forum, ApiError, currentUserId } from './api.js';

function el(tag, className, text) {
  const n = document.createElement(tag);
  if (className) n.className = className;
  if (text !== undefined) n.textContent = text;
  return n;
}

function fmtDate(ts) {
  try { return new Date(ts).toLocaleString(undefined, { dateStyle: 'medium', timeStyle: 'short' }); }
  catch { return ''; }
}

const params = new URLSearchParams(location.search);
const categoryId = params.get('id') || '';

function showMsg(msgEl, text, kind) { msgEl.textContent = text; msgEl.className = `form-msg ${kind}`; }

async function renderThreads() {
  const host = document.getElementById('threadList');
  if (!categoryId) {
    host.innerHTML = '';
    host.append(el('div', 'empty-state', 'No category selected.'));
    return;
  }
  let category, threads;
  try {
    ({ category, threads } = await forum.threads(categoryId));
  } catch (err) {
    host.innerHTML = '';
    const box = el('div', 'empty-state');
    box.append(el('span', 'icon', '⚠'), el('h3', null, 'Could not load this category'),
      el('p', null, err instanceof ApiError ? err.message : 'Please try again shortly.'));
    host.append(box);
    return;
  }

  document.getElementById('categoryName').textContent = category?.name || categoryId;
  document.getElementById('categoryTitle').textContent = category?.name || categoryId;
  document.title = `${category?.name || 'Forum'} — Dekaron Online`;

  host.innerHTML = '';
  if (!threads.length) {
    const box = el('div', 'empty-state');
    box.append(el('span', 'icon', '\u{1F4AD}'), el('h3', null, 'No threads yet'), el('p', null, 'Be the first to post in this category.'));
    host.append(box);
    return;
  }
  for (const t of threads) {
    const row = el('a', 'thread-row');
    row.href = `forum-thread.html?id=${encodeURIComponent(t.id)}`;
    const main = el('div');
    const title = el('div', 'title');
    if (t.pinned) title.append(el('span', 'pin', '\u{1F4CC}'));
    title.append(document.createTextNode(t.title));
    main.append(title, el('div', 'meta', `by ${t.author} · ${fmtDate(t.createdAt)}`));
    const stat = el('div', 'stat');
    stat.append(el('b', null, String(t.postCount ?? 1)), document.createTextNode('replies'));
    row.append(main, stat);
    host.append(row);
  }
}

async function setupNewThread() {
  const btn = document.getElementById('newThreadBtn');
  const panel = document.getElementById('newThreadPanel');
  const loginPrompt = document.getElementById('loginPrompt');
  const id = await currentUserId();
  if (id) {
    btn.style.display = '';
  } else {
    loginPrompt.style.display = '';
  }
  btn.addEventListener('click', () => { panel.style.display = ''; btn.style.display = 'none'; });
  document.getElementById('cancelNewThread').addEventListener('click', () => { panel.style.display = 'none'; btn.style.display = ''; });

  const form = document.getElementById('newThreadForm');
  const msg = document.getElementById('formMsg');
  form.addEventListener('submit', async (e) => {
    e.preventDefault();
    const title = form.title.value.trim();
    const body = form.body.value.trim();
    if (!title || !body) { showMsg(msg, 'Title and message are required.', 'error'); return; }
    const submit = form.querySelector('button[type="submit"]');
    submit.disabled = true;
    try {
      const { thread } = await forum.createThread(categoryId, title, body);
      location.href = `forum-thread.html?id=${encodeURIComponent(thread.id)}`;
    } catch (err) {
      showMsg(msg, err instanceof ApiError ? err.message : 'Could not post thread.', 'error');
      submit.disabled = false;
    }
  });
}

renderThreads();
setupNewThread();
