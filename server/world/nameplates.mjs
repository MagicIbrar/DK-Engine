import {characterRef} from '../accounts/character-ref.mjs';
import {normalizeCharacterNameColor} from '../../src/game/character-name.js';
import {normalizeGuildNameColor} from '../../src/game/guild-name-color.js';
import {guildMark} from './guilds.mjs';
import {allianceOfGuild} from './alliance.mjs';
import {wantedLevel} from './wanted.mjs';
import {pkPlace} from './field-pk.mjs';
import {sameScene} from './scene.mjs';
import {FIELD_PK} from '../../src/config/engine-chosen-pk.js';

const boundedText = (value, max = 64) => typeof value === 'string' ? [...value.replace(/[\p{Cc}\p{Cf}]/gu, '')].slice(0,max).join('') : '';
/** Existing canonical fields only. No earned title, rank, crest or GM marker is manufactured. */
export function publicNameplate(world, player) {
  const profile = player.profile;
  let nameColor = 'white'; try { nameColor = normalizeCharacterNameColor(profile.nameColor); } catch { /* legacy default */ }
  const wanted=wantedLevel(world,player);
  // Publisher guide9: battle purple, Niete red. Native wanted respawn bands
  // remain penalty metadata; they do not select this display color. Battle
  // expiry follows the existing ENGINE-CHOSEN forced-field latch only.
  if(wanted>0)nameColor='wanted2';
  else if(!player.duelId&&player.pkBattleAt!=null&&player.pkForcedAt!=null&&world.now()-player.pkBattleAt>=0&&world.now()-player.pkBattleAt<=FIELD_PK.forcedWindowMs&&world.now()-player.pkForcedAt>=0&&world.now()-player.pkForcedAt<=FIELD_PK.forcedWindowMs&&pkPlace(world,player)===null){
    const victim=[...world.players.values()].find(q=>q.id===player.pkBattleVictim&&!q.leaving&&sameScene(q,player));
    if(victim)nameColor='wanted1';
  }
  const ref = characterRef(player.account, player.characterId);
  const guild = Object.values(world.socialState?.guilds || {}).find(g => g.members?.some(m => m.ref === ref));
  const alliance = guild ? allianceOfGuild(world.socialState, guild.id) : null;   // ALLIANCE: name + mark line (ENGINE-CHOSEN NAMEPLATE)
  const selected = profile.life?.grade;
  const title = world.data.nameplateTitles?.find(row => row.Index === selected?.titleIndex);
  const grade = typeof selected?.rowKey === 'string' ? world.data.nameplateGrades?.find(row => `${row.division}.${row.grade}` === selected.rowKey) : null;
  // Cosmetic staff tag comes only from the host's current permission check.
  const admin = player.gmAuthorized === true && !player.npcPlayer;
  const adminGuild = guild && guild.name === 'ADMIN' && admin;
  return {nameColor,
    ...(admin ? {staffTag:'ADMIN'} : {}),
    // glory = the Guild / Alliance of Glory effect item (a glowing mark, extras/guild-glory-rules.js): only its item index travels
    guild: guild ? {id:guild.id, name:boundedText(guild.name,16), color:adminGuild?'red':normalizeGuildNameColor(guild.color), mark:guildMark(guild.mark), ...(guild.glory&&Number.isSafeInteger(guild.glory.itemIndex)?{glory:guild.glory.itemIndex}:{})} : null,
    alliance: alliance ? {id:alliance.id, name:boundedText(alliance.name,20), mark:guildMark(alliance.mark), ...(alliance.glory&&Number.isSafeInteger(alliance.glory.itemIndex)?{glory:alliance.glory.itemIndex}:{})} : null,
    title:boundedText(title?.Name), grade:boundedText(grade?.name),
    dkTier:Number.isSafeInteger(profile.dkTier) && profile.dkTier >= 0 ? profile.dkTier : null,
    // FIELD-PK wanted status (server/world/wanted.mjs): 1 purple, 2 red; absent when the player is not wanted
    ...(wanted > 0 ? {wanted} : {})};
}
