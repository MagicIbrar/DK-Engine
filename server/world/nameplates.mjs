import {characterRef} from '../accounts/character-ref.mjs';
import {normalizeCharacterNameColor, stripStaffNameTag} from '../../src/game/character-name.js';
import {authorizedStaffTag} from '../../src/game/nameplate-view.js';
import {normalizeGuildNameColor} from '../../src/game/guild-name-color.js';
import {guildMark} from './guilds.mjs';
import {allianceOfGuild} from './alliance.mjs';
import {wantedLevel, pkBattleActive} from './wanted.mjs';

const boundedText = (value, max = 64) => typeof value === 'string' ? [...value.replace(/[\p{Cc}\p{Cf}]/gu, '')].slice(0,max).join('') : '';
// Strip legacy staff brackets from unprivileged public rows, including older clients.
export function publicCharacterName(player) {
  const value=String(player?.profile?.name||'');
  return player?.gmAuthorized===true && !player.npcPlayer ? value : stripStaffNameTag(value);
}
/** Existing canonical fields only. No earned title, rank, crest or GM marker is manufactured. */
export function publicNameplate(world, player) {
  const profile = player.profile;
  let nameColor = 'white'; try { nameColor = normalizeCharacterNameColor(profile.nameColor); } catch { /* legacy default */ }
  const wanted=wantedLevel(world,player);
  // Publisher guide 62 / helper PK: battle status = purple for battleStatusMs (60s);
  // Niete / prison-band wanted = red. wantedLevel 1 = purple band, 2 = red (respawn) band.
  // Colors: stringtable_color purpul1/red1 via engine-chosen-pk wantedColors (stringtable_color).
  if(wanted===2)nameColor='wanted2';
  else if(wanted===1||pkBattleActive(world,player))nameColor='wanted1';
  const ref = characterRef(player.account, player.characterId);
  const guild = Object.values(world.socialState?.guilds || {}).find(g => g.members?.some(m => m.ref === ref));
  const alliance = guild ? allianceOfGuild(world.socialState, guild.id) : null;   // ALLIANCE: name + mark line (ENGINE-CHOSEN NAMEPLATE)
  const selected = profile.life?.grade;
  const title = world.data.nameplateTitles?.find(row => row.Index === selected?.titleIndex);
  const grade = typeof selected?.rowKey === 'string' ? world.data.nameplateGrades?.find(row => `${row.division}.${row.grade}` === selected.rowKey) : null;
  // Cosmetic staff tag comes only from the host's current permission check.
  const admin = player.gmAuthorized === true && !player.npcPlayer;
  const staffTag = authorizedStaffTag(profile.name, player.account, admin);
  const adminGuild = guild && guild.name === 'ADMIN' && admin;
  return {nameColor,
    ...(staffTag ? {staffTag} : {}),
    // glory = the Guild / Alliance of Glory effect item (a glowing mark, extras/guild-glory-rules.js): only its item index travels
    guild: guild ? {id:guild.id, name:boundedText(guild.name,16), color:adminGuild?'red':normalizeGuildNameColor(guild.color), mark:guildMark(guild.mark), ...(guild.glory&&Number.isSafeInteger(guild.glory.itemIndex)?{glory:guild.glory.itemIndex}:{})} : null,
    alliance: alliance ? {id:alliance.id, name:boundedText(alliance.name,20), mark:guildMark(alliance.mark), ...(alliance.glory&&Number.isSafeInteger(alliance.glory.itemIndex)?{glory:alliance.glory.itemIndex}:{})} : null,
    title:boundedText(title?.Name), grade:boundedText(grade?.name),
    dkTier:Number.isSafeInteger(profile.dkTier) && profile.dkTier >= 0 ? profile.dkTier : null,
    // FIELD-PK wanted status (server/world/wanted.mjs): 1 purple, 2 red; absent when the player is not wanted
    ...(wanted > 0 ? {wanted} : {})};
}
