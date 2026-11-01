import { auth, forum } from './api.js';
function node(tag, cls, text) { const el = document.createElement(tag); if (cls) el.className = cls; if (text !== undefined) el.textContent = text; return el; }
async function service() {
  const el = document.getElementById('serviceStatus');
  try { await auth.me(); el.textContent = 'Account service connected'; el.classList.add('connected'); }
  catch { el.textContent = 'Account service unavailable'; }
}
async function news() {
  const host = document.getElementById('homeNews');
  try {
    const data = await forum.categories();
    const category = data.categories?.find(c => /announcement|news|update/i.test(c.name));
    const feed = category ? await forum.threads(category.id) : {threads: []};
    host.replaceChildren();
    if (!feed.threads?.length) {
      const card = node('article', 'dispatch-card');
      card.append(node('span', 'eyebrow', 'COMMUNITY NOTICEBOARD'), node('h3', null, 'The next story starts with you.'), node('p', null, 'No announcements have been posted yet. Visit the forums for discussions, questions and updates.'));
      const link = node('a', 'text-link', 'Open the community ↗'); link.href = 'forums.html'; card.append(link); host.append(card); return;
    }
    for (const thread of feed.threads.slice(0,3)) {
      const card = node('a', 'dispatch-card'); card.href = `forum-thread.html?id=${encodeURIComponent(thread.id)}`;
      card.append(node('span', 'eyebrow', category.name), node('h3', null, thread.title), node('p', null, thread.author ? `Posted by ${thread.author}` : 'Community announcement'), node('span', 'text-link', 'Read the dispatch ↗')); host.append(card);
    }
  } catch { host.replaceChildren(node('div', 'empty-state', 'Announcements could not be loaded. Visit the community or try again later.')); }
}
async function classes() {
  const menu = document.getElementById('classMenu');
  try {
    const response = await fetch('/gamedata/classes.json'); if (!response.ok) throw new Error('Unavailable');
    const data = await response.json(); const list = data.classes.filter(c => c.playable !== false);
    menu.replaceChildren();
    function select(c, button) {
      menu.querySelectorAll('button').forEach(b => { b.classList.toggle('selected', b === button); b.setAttribute('aria-pressed', String(b === button)); });
      document.getElementById('classNumber').textContent = `CLASS ${String(c.index + 1).padStart(2,'0')} / ${list.length}`;
      document.getElementById('className').textContent = c.name;
      document.getElementById('classDescription').textContent = `Begin with ${c.weapon?.name || 'your class equipment'} and develop your own build through equipment and skills. These starting attributes come from the game's class data.`;
      const stats = document.getElementById('classStats'); stats.replaceChildren();
      for (const [key, label] of [['str','Strength'],['dex','Dexterity'],['con','Constitution'],['spr','Spirit']]) {
        const box = node('div'); box.append(node('strong', null, c.stats?.base?.[key] ?? '—'), node('span',null,label)); stats.append(box);
      }
    }
    list.forEach((c,i) => { const button = node('button','class-option'); button.type = 'button'; button.append(node('span',null,String(i+1).padStart(2,'0')),document.createTextNode(c.name)); button.addEventListener('click',() => select(c,button)); menu.append(button); if (i === 0) select(c,button); });
  } catch { menu.replaceChildren(node('p',null,'Class data is unavailable. You can still explore the classes in game.')); }
}
service(); news(); classes();
