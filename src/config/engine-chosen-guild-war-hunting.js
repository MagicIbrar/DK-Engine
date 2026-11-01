// Guild War Hunting (Braiken Castle Defense Battle, map 707): values the shipped client data does not contain.
// Every value here is ENGINE-CHOSEN (not in Global data). The Global client data is byte-identical to this copy,
// so the real server timings and the cross-server schedule cannot be recovered. Data-backed values stay in the
// data (share/guildwarhunting/config.csv: DKSERVERINDEX 100, MAPINDEX 707, ObserverMaxCount 200, StartX/Y 397,410,
// ReviveX1/Y1, ObserverSpeed 20, monster -> score rows; maps[707] random call / position tables; strings 707|100-103,
// 270|4/77-85). Used by the offline run (src/systems/events/defense.js) and the host (server/world/guild-war-hunting.mjs).
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const GUILD_WAR_HUNTING_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  beginSec: 60,          // countdown before the battle ("Begin in" 707|100)
  battleSec: 30 * 60,    // battle length ("Progress Time" 707|101)
  callEverySec: 90,      // one random call table every 90 s, in table order (first call 1 s after the start)
  endSec: 60,            // "End waiting time" (707|103) before everyone is returned
  // (invader aggro / pursuit ranges are NOT chosen here: every invader keeps its own monsters.json ai block,
  // aggressive true, sight 32, pursuit 38)
  // The data lists one past cross-server date (World1 2026-05-23 19:00). Shared play opens a session when the first
  // guild member enters at Vascuda. Guilds can join until the battle ends.
  session: 'on-demand',
  // share/arena/gameservername.csv only lists test servers, so the scoreboard's server column shows this name.
  serverName: 'Dekaron Online',
  // Scoreboard / guild info guild marks: the scripted mark panels carry no image, so they are painted with the
  // original guild mark imagetables (small 15 px rows: guildbg_s / guildicon_s; the 45 px first-place mark: guildbg /
  // guildicon), as the guild rank window does.
  marks: Object.freeze({ small: ['guildbg_s', 'guildicon_s'], large: ['guildbg', 'guildicon'], color: 'ffffffff' }),
  // ui_huntminimapwnd: the five pan_light_N panels (60x60, no image in the script) have no documented meaning.
  // ENGINE-CHOSEN meaning, in panel order:
  //   0 = you, 1 = your guild members (their centre), 2 and 3 = the two areas with the most live invaders,
  //   4 = the strongest live invader (boss; score >= bossMinScore, blinking).
  // World area of the 256x256 minimap image: the script's pivot_mapsize rect (142 111 263 311) read as world
  // x / z origin and size (ENGINE-CHOSEN reading; every random position of maps[707] falls inside it). North is up
  // (z grows downwards on the image) unless flipZ is set.
  minimap: Object.freeze({
    world: Object.freeze({ x: 142, z: 111, width: 263, height: 311 }),
    image: 256,
    flipZ: false,
    bossMinScore: 2500,
    lights: Object.freeze([
      Object.freeze({ panel: 'pan_light_0', meaning: 'self', color: 'ffffffff', size: 18 }),
      Object.freeze({ panel: 'pan_light_1', meaning: 'guild', color: 'ff3cb4ff', size: 30 }),
      Object.freeze({ panel: 'pan_light_2', meaning: 'invaders', color: 'ffff5a3c', size: 40 }),
      Object.freeze({ panel: 'pan_light_3', meaning: 'invaders', color: 'ffff5a3c', size: 40 }),
      Object.freeze({ panel: 'pan_light_4', meaning: 'boss', color: 'ffffd700', size: 60, blink: true }),
    ]),
  }),
});