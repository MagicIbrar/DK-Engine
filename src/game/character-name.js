// Character cosmetics. Account login IDs/roles remain separate.
import { FIELD_PK } from '../config/engine-chosen-pk.js';   // FIELD-PK wanted name colours (purple / red)
export const CHARACTER_NAME_MIN = 2, CHARACTER_NAME_MAX = 30;
export const CHARACTER_NAME_COLORS = Object.freeze({
  white: '#ffffff', gold: '#f6df91', cyan: '#9be7ff', green: '#b8efab', pink: '#f0b7db', lavender: '#cbbcff',
});
const invalid = message => { throw Object.assign(new Error(message), {status: 400}); };
export function characterNameKey(value) {
  return String(value ?? '').normalize('NFC').replace(/ +/g, ' ').trim().toLowerCase();
}
export function normalizeCharacterName(value) {
  if (typeof value !== 'string' || /[\p{Cc}\p{Cf}\p{Cs}]/u.test(value)) invalid('Use letters, numbers, ordinary spaces, underscores or dashes in the character name.');
  const name = value.normalize('NFC').replace(/ +/g, ' ').replace(/^ +| +$/g, '');
  if (!/^[\p{L}\p{M}\p{N}_ -]+$/u.test(name) || [...name].length < CHARACTER_NAME_MIN || [...name].length > CHARACTER_NAME_MAX)
    invalid('Choose a character name of 2–30 characters: letters, numbers, spaces, underscores or dashes.');
  return name;
}
export function normalizeCharacterNameColor(value = 'white') {
  if (typeof value !== 'string' || !Object.hasOwn(CHARACTER_NAME_COLORS, value)) invalid('Choose an available character name color.');
  return value;
}
/** Staff name tags: ADMIN, GM, DEV stay distinct (one privilege set, three brackets). */
export const STAFF_NAME_TAG = 'ADMIN';
export const STAFF_NAME_TAG_ALIASES = Object.freeze(['ADMIN', 'GM', 'DEV']);
export function stripStaffNameTag(value) {
  return String(value ?? '').replace(/^ *(?:\[(?:ADMIN|GM|DEV)\]\s*)+/iu, '');
}
export function normalizeStaffCharacterName(value, preferredTag = STAFF_NAME_TAG) {
  if (typeof value !== 'string') invalid('Choose a valid staff character name.');
  const match = /^\[(ADMIN|GM|DEV)\]\s*(.+)$/iu.exec(value.trim());
  const tagRaw = match ? match[1] : preferredTag;
  const tag = String(tagRaw || STAFF_NAME_TAG).toUpperCase();
  if (!STAFF_NAME_TAG_ALIASES.includes(tag)) invalid('Choose ADMIN, GM, or DEV as the staff name tag.');
  const base = stripStaffNameTag(value.trim());
  const name = `[${tag}] ${normalizeCharacterName(base)}`;
  if ([...name].length > CHARACTER_NAME_MAX) invalid('The staff tag and character name must fit within 30 characters.');
  return name;
}
export function characterNameCSS(value) { if (value === 'wanted1' || value === 'wanted2') return FIELD_PK.wantedColors[value.slice(6)]; return CHARACTER_NAME_COLORS[Object.hasOwn(CHARACTER_NAME_COLORS, value) ? value : 'white']; }
export function configureCharacterNameInput(input) {
  if (!input) return;
  input.maxLength = CHARACTER_NAME_MAX * 2; // HTML counts UTF-16; policy counts Unicode code points.
  input.title = '2–30 characters; letters, numbers, spaces, underscores or dashes.';
  const bound = () => { if (input.composing) return; input.value = [...input.value.normalize('NFC')].slice(0, CHARACTER_NAME_MAX).join(''); };
  input.addEventListener('compositionstart', () => { input.composing = true; });
  input.addEventListener('compositionend', () => { input.composing = false; bound(); });
  input.addEventListener('input', bound);
}
export function characterNameColorSelect() {
  const select = document.createElement('select');
  select.setAttribute('aria-label', 'Character name color'); select.title = 'Cosmetic character name color';
  for (const key of Object.keys(CHARACTER_NAME_COLORS)) {
    const option = document.createElement('option'); option.value = key; option.textContent = key[0].toUpperCase()+key.slice(1); select.appendChild(option);
  }
  select.value = 'white'; return select;
}
