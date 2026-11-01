import {chaoticValue,pkBattleActive} from './wanted.mjs';
import {COMBAT_TEXT} from '../../src/config/engine-chosen-pk.js';
// Current Global PK/PVP guide9: Niete cannot use NPC stores or NPC/item teleportation.
// Native script/string/normal/stringtable_pc.txt 40:93 supplies the refusal.
export const NIETE_SERVICE_TEXT='[Message] You cannot use this command while in the Niete (Evil) status.';
export function assertNieteService(world,p){if(chaoticValue(world,p)>0)throw Object.assign(new Error(NIETE_SERVICE_TEXT),{status:400});}
export function assertNieteChannel(world,p){if(chaoticValue(world,p)>0)throw Object.assign(new Error('You cannot switch channels while in the Niete status.'),{status:400});} // native40:132.
// Current Global guide62 "Battle status": for 60 s after starting PK a character cannot board a vehicle, use a mobile portal or an
// NPC, move channels or go to character selection; the Holy Water premium features are unavailable too. Native refusals:
// stringtable_pc 40:108 (service), stringtable_party 70:164 (channel), stringtable_system 101:248 (premium).
const combat=(world,p,text)=>{if(pkBattleActive(world,p))throw Object.assign(new Error(text),{status:400});};
export function assertCombatService(world,p){combat(world,p,COMBAT_TEXT.service);}
export function assertCombatChannel(world,p){combat(world,p,COMBAT_TEXT.channel);}
export function assertCombatPremium(world,p){combat(world,p,COMBAT_TEXT.premium);}
