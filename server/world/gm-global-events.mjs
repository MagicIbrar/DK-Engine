// Lane 47 (2026-10-29): host side of the Global GM event commands (names and argument lists from the Global client GM help
// strings, decompile 64-bit-named strings-xref.csv; 32-bit-main decompiled.c 269311-270054). Arguments are whitespace separated
// as in Global: dkrpvp_* (server/world/dkr-pvp.mjs), set_dksquareInfo (server/world/dk-square.mjs) and
// guildwarhunting_open|ready|start|finish [world index] (server/world/guild-war-hunting.mjs). The client lists them in
// src/systems/gm/commands.js (GLOBAL_EVENT_GM) and gm.mjs routes them here.
import {dkrGm} from './dkr-pvp.mjs';
import {dkSquareGm} from './dk-square.mjs';
// guild-war-hunting.mjs is loaded on first use: a static import here closes an import cycle through arena.mjs.
const GUILD_WAR_HUNTING_GM_COMMANDS=Object.freeze(['guildwarhunting_open','guildwarhunting_ready','guildwarhunting_start','guildwarhunting_finish']);
export const GLOBAL_DKR_COMMANDS=Object.freeze(['dkrpvp_create','dkrpvp_delete','dkrpvp_applystart','dkrpvp_applymember','dkrpvp_selectteam',
  'dkrpvp_createleague','dkrpvp_open','dkrpvp_finish','dkrpvp_setstatus','dkrpvp_createtournament']);
export const GLOBAL_EVENT_COMMANDS=Object.freeze([...GLOBAL_DKR_COMMANDS,'set_dksquareinfo',...GUILD_WAR_HUNTING_GM_COMMANDS]);
/** "/gm dkrpvp_open tournament 16 1", "gm dkrpvp_open ...", "/dkrpvp_open ..." or "dkrpvp_open ..." -> {name,args}; anything else -> null. */
export function globalEventLine(line){
  const parts=String(line??'').trim().replace(/^\/?(?:gm\s+)?/i,'').split(/\s+/).filter(Boolean);
  if(!parts.length)return null;const name=parts[0].toLowerCase();
  if(!GLOBAL_EVENT_COMMANDS.includes(name))return null;
  return {name,args:parts.slice(1)};
}
export async function globalEventGM(world,line){
  const c=globalEventLine(line);if(!c)return null;
  if(c.name==='set_dksquareinfo')return dkSquareGm(world,c.args);
  if(GUILD_WAR_HUNTING_GM_COMMANDS.includes(c.name))return (await import('./guild-war-hunting.mjs')).guildWarHuntingGm(world,c.name,c.args);
  return dkrGm(world,c.name,c.args);
}