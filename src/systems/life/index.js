// Life & social systems (docs/formats/life.md): day/night clock, weather, ambient sounds, emotes / sit / costume
// motions / levers, fishing, crafting (production), Deka Pass, events (virus/vaccine, OX quiz, timetable),
// grade / chaotic / PK, guild, party, mail and friends (messenger) - every window is the original script window
// (src/ui/uiwin, docs/UIWIN.md). Data: gamedata/life.json (tools/build-life.mjs).
//
// Facade: game.life = { data, clock, weather, ambience, emotes, fishing, craft, dekapass, events, grade, guild,
//   party, mail, friends, emote(id), sit(), stand(), interact(trigger) }.
// game.guild / game.party are also set as top-level aliases (hud-options/chat.js reads them directly).
import { lifeData, setItems } from './common.js';
import { WorldClock } from './clock.js';
import { Weather } from './weather.js';
import { Ambience } from './ambience.js';
import { Emotes } from './emotes.js';
import { awakeningShieldRows } from '../../game/awakening-shield.js';

const MODULES = [
  ['fishing', () => import('./fishing.js'), 'Fishing'],
  ['craft', () => import('./craft.js'), 'Craft'],
  ['dekapass', () => import('./dekapass.js'), 'DekaPass'],
  ['events', () => import('./events.js'), 'LifeEvents'],
  ['grade', () => import('./grade.js'), 'Grade'],
  ['guild', () => import('./guild.js'), 'Guild'],
  ['party', () => import('./party.js'), 'Party'],
  ['expedition', () => import('./expedition.js'), 'Expedition'],
  ['mail', () => import('./mail.js'), 'Mail'],
  ['friends', () => import('./friends.js'), 'Friends'],
  ['monsterTalk', () => import('./monster-talk.js'), 'MonsterTalk'],
];

let life = null;

export async function install(game) {
  const data = await lifeData();
  if (data?.items) setItems(data.items);
  // awakening grade shield table for the stat derivation (src/game/awakening-shield.js; the host does the same)
  // (the life system installs before the player exists: refresh only when there is one, and never let it abort the install)
  if (game.data && data?.grade?.grades) {
    game.data.gradeShieldRows = awakeningShieldRows(data.grade.grades);
    if (game.player) { try { game.refreshPlayerStats?.(false); } catch (err) { console.warn('[life] grade shield refresh', err); } }
  }
  life = {
    game, data,
    clock: new WorldClock(game),
    weather: new Weather(game, data?.weather || null),
    ambience: new Ambience(game),
    emote: (id) => life.emotes?.emote(id),
    sit: () => life.emotes?.sit(),
    stand: () => life.emotes?.stand(),
    interact: (t) => life.emotes?.interact(t) ?? Promise.resolve(false),
  };
  game.life = life;
  life.emotes = new Emotes(game, life);
  try { await life.emotes.install(); } catch (err) { console.error('[life] emotes', err); }
  // 2.2.1: the ten modules are fetched together (each import used to wait for the previous one's round trip); they still
  // install in this order, one after the other, exactly as before.
  const loaded = MODULES.map(([, load]) => load().catch(err => err));
  for (const [i, [key, , cls]] of MODULES.entries()) {
    try {
      const mod = await loaded[i];
      if (mod instanceof Error) throw mod;
      const C = mod[cls];
      if (!C) continue;
      life[key] = new C(game, life);
      await life[key].install?.();
    } catch (err) { console.error(`[life] ${key} failed to install`, err); life[key] = life[key] || null; }
  }
  // map changes: ambience + weather follow the new map
  game.events?.on?.('map', ({ index }) => {
    life.weather.onMap();
    life.ambience.load(index).catch((err) => console.warn('[life] ambience', err));
    for (const [key] of MODULES) { try { life[key]?.onMap?.(index); } catch (err) { console.error(`[life] ${key}.onMap`, err); } }
  });
  // npc services register when the quest/dialog system provides the registry (installed before or after us)
  life._servicesDone = false;
  return life;
}

function registerServices(game) {
  if (life._servicesDone || !game.npcServices?.register) return;
  life._servicesDone = true;
  for (const [key] of MODULES) { try { life[key]?.registerServices?.(game.npcServices); } catch (err) { console.error(`[life] ${key}.registerServices`, err); } }
}

export function update(dt, game) {
  if (!life) return;
  if (!life._servicesDone) registerServices(game);
  life.clock.update(dt);
  life.weather.update(dt);
  life.ambience.update(dt);
  life.emotes?.update(dt);
  for (const [key] of MODULES) { const m = life[key]; if (m?.update) { try { m.update(dt); } catch (err) { console.error(`[life] ${key}.update`, err); m.update = null; } } }
  // first map: the 'map' event fired before we were installed
  if (life.ambience.map == null && game.world?.info && !life._ambLoading) {
    life._ambLoading = true;
    life.ambience.load(game.world.info.index).finally(() => { life._ambLoading = false; if (life.ambience.map == null) life.ambience.map = -1; });
  }
}

export function dispose() {
  if (!life) return;
  life.weather.dispose();
  life.ambience.dispose();
  for (const [key] of MODULES) { try { life[key]?.dispose?.(); } catch { /* ignore */ } }
  life = null;
}
