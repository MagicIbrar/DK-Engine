// Canonical guild cosmetics are independent of character PvP/name status.
// Only these fixed palette keys may cross the public nameplate boundary.
export const GUILD_NAME_COLORS = Object.freeze({
  white:'#ffffff', red:'#e51b23', gold:'#f6df91', cyan:'#9be7ff',
  green:'#b8efab', pink:'#f0b7db', lavender:'#cbbcff',
});
export function normalizeGuildNameColor(value = 'white') {
  return typeof value === 'string' && Object.hasOwn(GUILD_NAME_COLORS,value) ? value : 'white';
}
export function guildNameCSS(value) { return GUILD_NAME_COLORS[normalizeGuildNameColor(value)]; }
