// Staff brackets: three separate Play/create roles with distinct accounts, name tags, guild marks, and Guild of Glory statues.
// Capabilities stay identical (role `gm`); identity/guild art differ per bracket.
export const STAFF_BRACKET_IDS = Object.freeze(['admin', 'gm', 'dev']);
export const STAFF_BRACKETS = Object.freeze({
  admin: Object.freeze({
    id: 'admin',
    tag: 'ADMIN',
    guildName: 'ADMIN',
    // Existing default crest + Purple Star glory statue
    mark: Object.freeze({ bg: 1, icon: 1 }),
    gloryItem: 60040,
    gloryName: 'Guild of Glory - Purple Star',
  }),
  gm: Object.freeze({
    id: 'gm',
    tag: 'GM',
    guildName: 'GM',
    // Distinct native crest cells + Fire glory statue
    mark: Object.freeze({ bg: 77, icon: 401 }),
    gloryItem: 1160017,
    gloryName: 'Guild of Glory - Fire',
  }),
  dev: Object.freeze({
    id: 'dev',
    tag: 'DEV',
    guildName: 'DEV',
    // Distinct native crest cells + Dark glory statue
    mark: Object.freeze({ bg: 166, icon: 666 }),
    gloryItem: 1160020,
    gloryName: 'Guild of Glory - Dark',
  }),
});
export function normalizeStaffBracket(value) {
  const key = String(value ?? '').trim().toLowerCase();
  if (Object.hasOwn(STAFF_BRACKETS, key)) return key;
  throw new Error('Staff bracket must be admin, gm, or dev.');
}
export function staffBracket(value) {
  return STAFF_BRACKETS[normalizeStaffBracket(value)];
}
export function isStaffBracketAccount(id) {
  return STAFF_BRACKET_IDS.includes(String(id || '').trim().toLowerCase());
}
export function staffTaggedName(tag, baseName) {
  const t = String(tag || '').toUpperCase();
  if (!['ADMIN', 'GM', 'DEV'].includes(t)) throw new Error('Invalid staff name tag.');
  const bare = String(baseName || '').replace(/^\[(?:ADMIN|GM|DEV)\]\s*/iu, '').trim();
  return `[${t}] ${bare}`.replace(/ +/g, ' ').trim();
}
