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
export function normalizeStaffCharacterName(value) {
  if (typeof value !== 'string') invalid('Choose a valid staff character name.');
  const match = /^\[(GM|DEV)\]\s*(.+)$/u.exec(value.trim());
  if (!match) return normalizeCharacterName(value);
  const name = `[${match[1]}] ${normalizeCharacterName(match[2])}`;
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
