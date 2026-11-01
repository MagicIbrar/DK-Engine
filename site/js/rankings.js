// site/js/rankings.js — renders /api/rankings on rankings.html, stubbing gracefully until the
// accounts server has real rebirth data (endpoint missing, empty, or shaped differently — all
// handled without throwing).
import { rankings, ApiError } from './api.js';

function el(tag, className, text) {
  const n = document.createElement(tag);
  if (className) n.className = className;
  if (text !== undefined) n.textContent = text;
  return n;
}

function emptyState(icon, title, text) {
  const box = el('div', 'empty-state');
  box.append(el('span', 'icon', icon), el('h3', null, title));
  if (text) box.append(el('p', null, text));
  return box;
}

function normalizeRows(data) {
  const rows = Array.isArray(data) ? data : (Array.isArray(data?.rankings) ? data.rankings : (Array.isArray(data?.rows) ? data.rows : null));
  if (!rows) return null;
  return rows.map((r, i) => ({
    rank: r.rank ?? i + 1,
    name: r.name ?? r.character ?? r.charName ?? 'Unknown',
    className: r.class ?? r.className ?? r.job ?? '—',
    rebirths: r.rebirths ?? r.rebirthCount ?? r.rebirth ?? 0,
    level: r.level ?? r.lv ?? '—',
  })).filter(r => Number.isFinite(Number(r.rebirths)) && Number(r.rebirths) > 0);
}

function badgeFor(rank) {
  if (rank === 1) return el('span', 'rank-badge r1', '1');
  if (rank === 2) return el('span', 'rank-badge r2', '2');
  if (rank === 3) return el('span', 'rank-badge r3', '3');
  return document.createTextNode(String(rank));
}

async function render() {
  const host = document.getElementById('rankingsHost');
  let data;
  try {
    data = await rankings.rebirth();
  } catch (err) {
    host.innerHTML = '';
    host.append(emptyState('⚠', 'Could not load rankings', err instanceof ApiError ? err.message : 'Please try again shortly.'));
    return;
  }

  const rows = normalizeRows(data);
  host.innerHTML = '';
  if (!rows || !rows.length) {
    host.append(emptyState('\u{1F31F}', 'No rebirths yet', 'Be the first character to reach rebirth and claim the top spot.'));
    return;
  }

  const wrap = el('div', 'table-wrap');
  const table = document.createElement('table');
  table.className = 'rankings';
  const thead = document.createElement('thead');
  thead.innerHTML = '<tr><th>Rank</th><th>Character</th><th>Class</th><th>Rebirths</th><th>Level</th></tr>';
  const tbody = document.createElement('tbody');
  for (const r of rows) {
    const tr = document.createElement('tr');
    const tdRank = document.createElement('td');
    tdRank.append(badgeFor(r.rank));
    const tdName = el('td', null, r.name);
    const tdClass = el('td', null, r.className);
    const tdRebirths = el('td', null, String(r.rebirths));
    const tdLevel = el('td', null, String(r.level));
    tr.append(tdRank, tdName, tdClass, tdRebirths, tdLevel);
    tbody.append(tr);
  }
  table.append(thead, tbody);
  wrap.append(table);
  host.append(wrap);
}

render();
