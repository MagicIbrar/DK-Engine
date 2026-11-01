// Explicit settings shared by browser options and the authenticated world command.
export const GAMEPLAY_PREFERENCE_DEFAULTS=Object.freeze({rejectRevive:false,stackQuestReward:true,notExpedition:true,notGuild:true,notFriend:true,notGeneral:false,blockFriend:false});
export const GAMEPLAY_PREFERENCE_KEYS=Object.freeze(Object.keys(GAMEPLAY_PREFERENCE_DEFAULTS));
export function gameplayPreferences(value){return Object.fromEntries(GAMEPLAY_PREFERENCE_KEYS.map(k=>[k,typeof value?.[k]==='boolean'?value[k]:GAMEPLAY_PREFERENCE_DEFAULTS[k]]));}
