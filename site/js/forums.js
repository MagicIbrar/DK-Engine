// site/js/forums.js — renders the category list on forums.html.
import { forum, ApiError } from './api.js';

function el(tag, className, text) {
  const n = document.createElement(tag);
  if (className) n.className = className;
  if (text !== undefined) n.textContent = text;
  return n;
}

function fmtCount(n, label) { return `${n} ${label}${n === 1 ? '' : 's'}`; }

async function render() {
  const host = document.getElementById('categoryList');
  let categories;
  try {
    ({ categories } = await forum.categories());
  } catch (err) {
    host.innerHTML = '';
    const box = el('div', 'empty-state');
    box.append(
      el('span', 'icon', '⚠'),
      el('h3', null, 'Forums are unavailable'),
      el('p', null, err instanceof ApiError ? err.message : 'Please try again shortly.'),
    );
    host.append(box);
    return;
  }

  host.innerHTML = '';
  if (!categories || !categories.length) {
    const box = el('div', 'empty-state');
    box.append(el('span', 'icon', '\u{1F4AC}'), el('h3', null, 'No categories yet'));
    host.append(box);
    return;
  }

  for (const c of categories) {
    const row = el('a', 'category-row');
    row.href = `forum-category.html?id=${encodeURIComponent(c.id)}`;
    const main = el('div');
    main.append(el('div', 'name', c.name), el('div', 'desc', c.description || ''));
    const count = el('div', 'count');
    count.append(el('b', null, String(c.threadCount ?? 0)), document.createTextNode(fmtCount(c.threadCount ?? 0, 'thread')));
    row.append(main, count);
    host.append(row);
  }
}

render();
