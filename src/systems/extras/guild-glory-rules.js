// Guild of Glory = the glowing guild emblem. share/item itemcash Type 0 Code 16 ("Guild of Glory - Purple Star / Snake / Kamit / Orion / ... Best
// Guild / Sky / Fire / Poison / Gold / Dark"): item text "Use this item to register your Guild Emblem. May be used only by a Guild Leader."
// (stringtable_item), and the guild strings of cate 130: 70 "Guild emblem has been changed.", 121 "You have no authority to change the guild
// emblem.", 175 "The guild emblem effect is not applied right now.", 176 "Do you wish to delete guild emblem effect?", 177 "Successfully deleted
// guild emblem effect." The Alliance of Glory (Code 30, extras/alliance*.js) is the same idea for an alliance and was already built.
// ENGINE-CHOSEN (the effect itself is packed in the live client): the effect is a golden glow around the guild mark on name plates and the
// item stays recorded as guild.glory.itemIndex; deleting it goes through the guild mark deletion NPC (DELETEGUILDMARK), like the alliance's.
export const GUILD_GLORY = Object.freeze({ type: 0, code: 16 });
/** Is this item a Guild of Glory (itemcash Type 0 Code 16)? */
export const isGuildGloryItem = def => !!def && Number(def.type) === GUILD_GLORY.type && Number(def.code) === GUILD_GLORY.code;
export const GLORY_STR = Object.freeze({ changed: [130, 70], noAuthority: [130, 121], none: [130, 175], deleteAsk: [130, 176], deleted: [130, 177], confirm: [130, 221] });
export const GLORY_TEXT = Object.freeze({
  changed: 'Guild emblem has been changed.', noAuthority: 'You have no authority to change the guild emblem.', none: 'The guild emblem effect is not applied right now.',
  deleteAsk: 'Do you wish to delete guild emblem effect?', deleted: 'Successfully deleted guild emblem effect.', confirm: 'Confirm Guild Emblem',
  notInGuild: 'You are not in a guild.',
});
/** CSS of the glow drawn around a guild (or alliance) mark that has a Glory effect (name plates). */
export const GLORY_GLOW_CSS = 'drop-shadow(0 0 2px #fff2b0) drop-shadow(0 0 5px #ffc247)';
