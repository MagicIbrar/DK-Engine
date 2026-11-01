import {GAMEPLAY_PREFERENCE_KEYS,gameplayPreferences} from '../../src/game/gameplay-preferences.js';
import {serializeLife,commitLife,validateLife} from './life-transactions.mjs';
import {characterRef} from '../accounts/character-ref.mjs';
import {wantedLevel,pkBattleActive} from './wanted.mjs';
export const GAMEPLAY_PREFERENCE_SCHEMAS={preferences:['token','type','values']};
export async function gameplayPreferenceCommand(world,p,input){
 validateLife(input,GAMEPLAY_PREFERENCE_SCHEMAS);
 const values=input.values;
 if(!values||typeof values!=='object'||Array.isArray(values)||Object.keys(values).length>GAMEPLAY_PREFERENCE_KEYS.length||Object.entries(values).some(([k,v])=>!GAMEPLAY_PREFERENCE_KEYS.includes(k)||typeof v!=='boolean'))throw Object.assign(Error('Send only supported boolean gameplay preferences.'),{status:400});
 const token=p.token;
 return serializeLife(p,async()=>{
  if(world.lease(p.account,token)!==p)throw Object.assign(Error('Gameplay preference session changed.'),{status:409});
  const next={...gameplayPreferences(p.profile.gameplayPreferences),...values};
  if(JSON.stringify(next)===JSON.stringify(p.profile.gameplayPreferences))return true;
  const profile=structuredClone(p.profile);profile.gameplayPreferences=next;
  await commitLife(world,p,profile);world.changed(p);return true;
 });
}
export function rejectsResurrection(player){return gameplayPreferences(player?.profile?.gameplayPreferences).rejectRevive;}
const guildOf=(world,p)=>{const ref=characterRef(p.account,p.characterId);return Object.values(world.socialState?.guilds||{}).find(g=>g.members?.some(m=>m.ref===ref))?.id;};
/** User attack exclusions only remove eligible targets; disabling never bypasses a mode's rules. */
export function attackPreferenceRefusal(world,p,q){
 if(!p||!q||p===q)return null;
 const prefs=gameplayPreferences(p.profile?.gameplayPreferences);
 if(prefs.notExpedition){const a=world.parties?.get(p.partyId)?.expedition,b=world.parties?.get(q.partyId)?.expedition;if(a&&a===b)return 'expedition';}
 if(prefs.notGuild){const a=guildOf(world,p);if(a&&a===guildOf(world,q))return 'guild';}
 if(prefs.notFriend&&p.profile?.npcFriends?.some(n=>String(n).toLowerCase()===String(q.profile?.name).toLowerCase()))return 'friend';
 if(prefs.notGeneral&&wantedLevel(world,q)<=0&&!pkBattleActive(world,q))return 'normal';
 return null;
}
