// Guild War Hunting (Braiken Castle Defense Battle, map 707).
// Data-backed (share/guildwarhunting/config.csv): DKSERVERINDEX 100, MAPINDEX 707, ObserverMaxCount 200,
// StartX/Y 397,410, Revive*, ObserverSpeed 20, World1/2/3Index 1/10/20 (World1 2026-05-23 19:00), monster->score rows.
// Session (Lane 47): the Global GM commands guildwarhunting_open|ready|start|finish [world index] drive it
// (server/world/guild-war-hunting.mjs). Removed as not in Global (owner rule): the begin/battle/call/end timers
// (Lane 49 had nulled them), the 'world1-calendar' session reading, the server name and the five minimap light
// meanings/colors/sizes/blink and bossMinScore. Lane 71: the pan_light_0..4 meanings (Global HuntMinimapWnd message
// 0x71430002 carries server-chosen x,y pairs per light) and the invader call interval have no source: REMOVED (lights hidden, no timed calls).
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const GUILD_WAR_HUNTING_ENGINE_CHOSEN = Object.freeze({
  tag: ENGINE_CHOSEN_TAG,
  // ENGINE-CHOSEN reading of the imagetable guild mark screens for the scripted mark panels.
  marks: Object.freeze({ small: ['guildbg_s', 'guildicon_s'], large: ['guildbg', 'guildicon'], color: 'ffffffff' }),
});