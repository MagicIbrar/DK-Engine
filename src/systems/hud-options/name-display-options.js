// Native option labels 2001:135/136 explicitly auto-check the character-name master.
// View all (2001:137), in the same name-display group, selects that group's switches.
export const NAME_DISPLAY_KEYS = Object.freeze(['charName','guildName','allianceName','titleName','ratingName']);
export function nameDisplayPatch(values, key, value) {
  const patch = {[key]:value};
  if (key === 'allShow') {
    for (const name of NAME_DISPLAY_KEYS) patch[name] = !!value;
    if (value) patch.nameView = 0;
  } else if (NAME_DISPLAY_KEYS.includes(key)) {
    if (value && (key === 'guildName' || key === 'allianceName')) { patch.charName = true; patch.nameView = 0; }
    patch.allShow = NAME_DISPLAY_KEYS.every(name => (name in patch ? patch[name] : values[name]) === true) && (patch.nameView ?? values.nameView ?? 0) === 0;
  }
  return patch;
}
