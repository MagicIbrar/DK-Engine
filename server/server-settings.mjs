// Owner-controlled display metadata. Accounts, admission rules and world rates are never rewritten.
import fs from 'node:fs/promises';
import path from 'node:path';
import { randomBytes } from 'node:crypto';
import { serverName, serverMetadata } from './world/rates.mjs';
import {NPC_CHAT_LANGUAGES} from './world/npc-chat-localization.mjs';

async function ordinaryPath(file) {
  let current = path.parse(file).root;
  const parts = path.relative(current, file).split(path.sep).filter(Boolean);
  for (let i = 0; i < parts.length; i++) {
    if (process.platform === 'win32' && /[:\x00-\x1f]/.test(parts[i])) throw Error('Invalid server settings path.');
    current = path.join(current, parts[i]);
    const stat = await fs.lstat(current).catch(error => { if (error.code === 'ENOENT') return null; throw error; });
    if (stat && (stat.isSymbolicLink() || (i < parts.length - 1 ? !stat.isDirectory() : !stat.isFile() || stat.nlink > 1))) {
      throw Error('Server settings paths must be ordinary unlinked files and directories.');
    }
  }
}

// Per-server on/off switches of the dashboard (Settings). Each is stored ONLY while it is off (absent = the default, ON), so the plain
// two-key file of older engines stays valid: starterPack = a NEW character gets the starter kit (boxes.starter.onCreate),
// fieldPk = Ctrl forced attack (PK) on open PvP fields (server/world/field-pk.mjs).
// starterPack (F1) is an ENGINE-CHOSEN ADDITION kept ON by owner choice: the Global client has no starter-kit table
// (tools/build-boxes.mjs STARTER, docs/formats/boxes.md 4). Scan fix A labels it; it is not a Global rule.
const DEFAULTS={starterPack:true,fieldPk:true,npcPlayers:false}; // NPC players are an opt-in ENGINE-CHOSEN extension.
const SWITCHES = Object.keys(DEFAULTS);
const valueFor=(value,k)=>typeof value?.[k]==='boolean'?value[k]:DEFAULTS[k];
const validPopulation = value => Number.isInteger(value) && value >= 10 && value <= 100;
const KEYS = ['version', 'name', ...SWITCHES, 'npcPopulation', 'npcLanguage'];

async function readSettings(file) {
  await ordinaryPath(file);
  try {
    if ((await fs.stat(file)).size > 1024) throw Error('Invalid server settings.');
    const value = JSON.parse(await fs.readFile(file, 'utf8'));
    const keys = value && !Array.isArray(value) ? Object.keys(value) : [];
    if (!keys.length || value.version !== 1 || !Object.hasOwn(value, 'name') || keys.some(k => !KEYS.includes(k)) || SWITCHES.some(k => Object.hasOwn(value, k) && typeof value[k] !== 'boolean')) throw Error('Invalid server settings.');
    if (Object.hasOwn(value, 'npcPopulation') && !validPopulation(value.npcPopulation)) throw Error('Invalid server settings.');
    if (Object.hasOwn(value, 'npcLanguage') && !NPC_CHAT_LANGUAGES.includes(value.npcLanguage)) throw Error('Invalid server settings.');
    return { npcLanguage: value.npcLanguage ?? 'en', npcPopulation: value.npcPopulation ?? 100, name: serverName(value.name), ...Object.fromEntries(SWITCHES.map(k => [k, valueFor(value,k)])) };
  } catch (error) { if (error.code === 'ENOENT') return null; throw error; }
}

export async function createServerSettings({ accountStore, readRates = null, ...metadataOptions }) {
  if (typeof accountStore !== 'string' || !path.isAbsolute(accountStore) || accountStore.includes('\0')) throw Error('Server settings require an absolute account store.');
  const store = path.resolve(accountStore), file = store + '.settings.json';
  if (store === path.parse(store).root) throw Error('Server settings require an account file.');
  await ordinaryPath(store);
  const saved = await readSettings(file);
  let metadata = serverMetadata({ ...metadataOptions, name: saved?.name ?? metadataOptions.name });
  const on = Object.fromEntries(SWITCHES.map(k => [k, valueFor(saved,k)]));
  let population = saved?.npcPopulation ?? 100;
  let language = saved?.npcLanguage ?? 'en';
  let writes = Promise.resolve();
  // The reply shows a switch only while it is OFF, so the plain {name} shape of older dashboards holds.
  const shape = () => ({ name: metadata.name, ...(population !== 100 ? {npcPopulation: population} : {}), ...(language !== 'en' ? {npcLanguage: language} : {}), ...Object.fromEntries(SWITCHES.filter(k => on[k]!==DEFAULTS[k]).map(k => [k,on[k]])) });
  return {
    read: shape,
    metadata: () => readRates?Object.freeze({...metadata,rates:readRates()}):metadata,
    starterPack: () => on.starterPack,
    fieldPk: () => on.fieldPk,
    npcPlayers: () => on.npcPlayers,
    npcPopulation: () => population,
    npcLanguage: () => language,
    set(value) {
      if (!value || Array.isArray(value) || Object.keys(value).length !== 1 || ![ 'name', ...SWITCHES, 'npcPopulation', 'npcLanguage' ].some(k => Object.hasOwn(value, k))) throw Error('Expected one server setting.');
      const switchKey = SWITCHES.find(k => Object.hasOwn(value, k));
      if (switchKey && typeof value[switchKey] !== 'boolean') throw Error('A server switch must be true or false.');
      if (Object.hasOwn(value, 'npcPopulation') && !validPopulation(value.npcPopulation)) throw Error('Bot population must be a whole number from 10 to 100.');
      if (Object.hasOwn(value, 'npcLanguage') && !NPC_CHAT_LANGUAGES.includes(value.npcLanguage)) throw Error('Choose a supported bot chat language.');
      const requestedPopulation = value.npcPopulation;
      const newName = Object.hasOwn(value, 'name') ? serverName(value.name) : null;
      const pending = writes.then(async () => {
        // resolved when this write's turn comes, so a queued name change is never undone by a queued switch (and the other way round)
        const nextPopulation = requestedPopulation ?? population;
        const nextLanguage = value.npcLanguage ?? language;
        const name = newName ?? metadata.name, next = { ...on, ...(switchKey ? { [switchKey]: value[switchKey] } : {}) };
        await ordinaryPath(store); await readSettings(file);
        await fs.mkdir(path.dirname(file), { recursive: true });
        await ordinaryPath(file);
        const temporary = file + '.' + randomBytes(8).toString('hex') + '.tmp';
        try {
          await fs.writeFile(temporary, JSON.stringify({ version: 1, name, ...(nextPopulation !== 100 ? {npcPopulation: nextPopulation} : {}), ...(nextLanguage !== 'en' ? {npcLanguage: nextLanguage} : {}), ...Object.fromEntries(SWITCHES.filter(k => next[k]!==DEFAULTS[k]).map(k => [k,next[k]])) }, null, 2), { flag: 'wx', mode: 0o600 });
          await ordinaryPath(store); await ordinaryPath(file);
          await fs.rename(temporary, file);
        } finally { await fs.rm(temporary, { force: true }).catch(() => {}); }
        metadata = serverMetadata({ ...metadata, name });
        Object.assign(on, next); population = nextPopulation; language = nextLanguage;
        return shape();
      });
      writes = pending.catch(() => {});
      return pending;
    },
  };
}
