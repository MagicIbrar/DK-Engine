import { characters, ApiError } from './api.js';
import { configureAccountSaves, importLocalCharacters, getLocalCharacters, exportCharacterBackup, getSaveStatus } from '/src/game/save.js';

const host = document.getElementById('charactersHost');
const msg = document.getElementById('accountMsg');
const importButton = document.getElementById('importLocal');
const accountBackup = document.getElementById('accountBackup');
let ready = false;

function status(text, kind = 'ok') {
  msg.textContent = text;
  msg.className = `form-msg ${kind}`;
}

function download(data, name) {
  const url = URL.createObjectURL(new Blob([JSON.stringify(data, null, 2)], { type: 'application/json' }));
  const link = document.createElement('a');
  link.href = url; link.download = name;
  document.body.append(link); link.click(); link.remove();
  setTimeout(() => URL.revokeObjectURL(url), 2000);
}

function cell(row, value) {
  const td = document.createElement('td'); td.textContent = String(value); row.append(td);
}

async function loadCharacters() {
  const data = await characters.list();
  const id = typeof data.account === 'object' ? data.account.id : data.account;
  document.getElementById('accountIdentity').textContent = String(id || 'Account');
  host.replaceChildren();
  const list = Array.isArray(data.characters) ? data.characters : [];
  document.getElementById('accountCharacterCount').textContent = String(list.length);
  document.getElementById('localCharacterCount').textContent = String(getLocalCharacters().length);
  if (!list.length) {
    const empty = document.createElement('p');
    empty.textContent = 'No account characters yet. Open Play Now to create one. Older local saves can be archived below.';
    host.append(empty);
  } else {
    const wrap = document.createElement('div'); wrap.className = 'table-wrap';
    const table = document.createElement('table'); table.className = 'rankings';
    const head = document.createElement('thead');
    const labels = document.createElement('tr');
    for (const name of ['Character', 'Class', 'Level', 'Rebirths', 'Mode']) {
      const th = document.createElement('th'); th.textContent = name; labels.append(th);
    }
    head.append(labels);
    const body = document.createElement('tbody');
    for (const character of list) {
      const row = document.createElement('tr');
      cell(row, character.name || 'Unnamed');
      cell(row, character.className || `Class ${character.classIndex ?? '—'}`);
      cell(row, character.level ?? 1);
      cell(row, character.rebirths ?? character.rebirthCount ?? 0);
      const mode = document.createElement('td');
      const badge = document.createElement('span');
      const verified = character.authority === 'server';
      badge.className = verified ? 'mode-badge verified' : 'mode-badge';
      badge.textContent = verified ? 'Shared world • server verified' : 'Archived local save';
      mode.append(badge); row.append(mode);
      body.append(row);
    }
    table.append(head, body); wrap.append(table); host.append(wrap);
  }
  return id;
}

document.getElementById('localBackup').addEventListener('click', () => {
  download({ format: 'dekaron-local-characters', version: 1, characters: getLocalCharacters() }, 'Dekaron_Local_Characters.json');
  status('Local character backup downloaded.');
});

accountBackup.addEventListener('click', () => {
  download(exportCharacterBackup(), 'Dekaron_Account_Backup.json');
  status('Account backup downloaded, including any saved conflict recovery data.');
});

importButton.addEventListener('click', async () => {
  if (!ready) return;
  importButton.disabled = true;
  accountBackup.disabled = true;
  try {
    status('Copying local characters to your account…');
    const result = await importLocalCharacters();
    await loadCharacters();
    status(`Copied ${result.imported} sandbox character(s); skipped ${result.skipped} already present. Browser originals were kept. Imported characters do not enter the verified shared world or trusted rankings.${getSaveStatus().message ? ` ${getSaveStatus().message}` : ''}`);
  } catch (err) { status(err.message || 'Could not copy characters. Download a local backup and try again.', 'error'); }
  finally { importButton.disabled = false; accountBackup.disabled = false; }
});

async function init() {
  try {
    const id = await loadCharacters();
    await configureAccountSaves(id);
    ready = true;
    importButton.disabled = false;
    accountBackup.disabled = false;
    const saveState = getSaveStatus();
    if (saveState.message) status(saveState.message, saveState.state === 'synced' ? 'ok' : 'error');
  } catch (err) {
    if (err instanceof ApiError && err.status === 401) {
      location.href = 'login.html?next=%2Fsite%2Faccount.html';
      return;
    }
    status(err.message || 'Could not load your account.', 'error');
    accountBackup.disabled = !getSaveStatus().account;
    host.querySelector('.skeleton')?.remove();
  }
}

init();
