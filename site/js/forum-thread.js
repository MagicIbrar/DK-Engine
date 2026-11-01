// site/js/forum-thread.js — posts list + reply form for forum-thread.html.
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

function showMsg(msgEl, text, kind) { msgEl.textContent = text; msgEl.className = `form-msg ${kind}`; }

const threadId = new URLSearchParams(location.search).get('id') || '';

async function renderThread() {
  const host = document.getElementById('postList');
  if (!threadId) {
    host.innerHTML = '';
    host.append(el('div', 'empty-state', 'No thread selected.'));
    return null;
  }
  let thread, posts;
  try {
    ({ thread, posts } = await forum.thread(threadId));
  } catch (err) {
    host.innerHTML = '';
    const box = el('div', 'empty-state');
    box.append(el('span', 'icon', '⚠'), el('h3', null, 'Could not load this thread'),
      el('p', null, err instanceof ApiError ? err.message : 'Please try again shortly.'));
    host.append(box);
    return null;
  }

  document.getElementById('threadTitle').textContent = thread.title;
  document.getElementById('threadTitleCrumb').textContent = thread.title;
  document.title = `${thread.title} — Dekaron Online`;
  const catLink = document.getElementById('categoryLink');
  catLink.href = `forum-category.html?id=${encodeURIComponent(thread.categoryId)}`;
  catLink.textContent = thread.categoryId;

  host.innerHTML = '';
  const opAuthor = posts[0]?.author;
  for (const p of posts) {
    const row = el('div', 'post');
    const author = el('div', 'author', p.author);
    if (p.author === opAuthor && p === posts[0]) author.append(el('span', 'op-tag', 'Original Poster'));
    author.append(el('div', 'when', fmtDate(p.createdAt)));
    const body = el('div', 'body', p.body);
    row.append(author, body);
    host.append(row);
  }
  return thread;
}

async function setupReply(thread) {
  const panel = document.getElementById('replyPanel');
  const loginPrompt = document.getElementById('loginPrompt');
  if (!thread) return;
  const id = await currentUserId();
  if (thread.locked) return; // locked: no reply UI at all
  if (id) panel.style.display = ''; else loginPrompt.style.display = '';

  const form = document.getElementById('replyForm');
  const msg = document.getElementById('formMsg');
  form.addEventListener('submit', async (e) => {
    e.preventDefault();
    const body = form.body.value.trim();
    if (!body) { showMsg(msg, 'Write something first.', 'error'); return; }
    const submit = form.querySelector('button[type="submit"]');
    submit.disabled = true;
    try {
      await forum.reply(threadId, body);
      location.reload();
    } catch (err) {
      showMsg(msg, err instanceof ApiError ? err.message : 'Could not post reply.', 'error');
      submit.disabled = false;
    }
  });
}

renderThread().then(setupReply);
