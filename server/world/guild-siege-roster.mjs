// Classic siege: Global guild.csv SIEGE_ATTACK_MAX and stringtable_guild 130:382/427:
// at most 50 selected members; only selected members may enter; selection is
// locked while the guild prepares/participates. This is separate from a
// castle's ENTERPCCOUNT. Renewed siege guide32 admits all guild members; no
// native linkage to this classic roster is established. Legacy guilds have no
// implicit classic grants: their master
// selects the initial roster. Existing in-scene players are not expelled.
import {socialError as fail} from './social-state.mjs';

export function guildSiegeLimit(world) {
  const n=Number(world.data.guild?.config?.SIEGE_ATTACK_MAX);
  return Number.isSafeInteger(n)&&n>0&&n<=500?n:0;
}
export function guildSiegeLocked(world,g,state=world.socialState) {
  if(!g)return false;
  const classic=world.siegeLive?.battle;
  if(classic&&['prep','battle'].includes(classic.phase)
    &&(state?.siege?.owner?.guild===g.id||state?.siege?.seals?.some(s=>s.guild===g.id)))return true;
  return false;
}
export function guildSiegeRoster(world,g,state=world.socialState) {
  const limit=guildSiegeLimit(world),members=new Set(g?.members?.map(m=>m.ref)||[]);
  const selected=Array.isArray(g?.siegeMembers)?[...new Set(g.siegeMembers.filter(ref=>typeof ref==='string'&&members.has(ref)))]:[];
  return {limit,selected:selected.slice(0,limit),configured:Array.isArray(g?.siegeMembers),locked:guildSiegeLocked(world,g,state)};
}
export function setGuildSiegeRoster(world,state,g,ref,memberRefs) {
  if(!g||g.master!==ref)fail('Guild Master permission is required.',403);
  const limit=guildSiegeLimit(world);
  if(!limit)fail('The original siege participant limit is unavailable.',503);
  if(guildSiegeLocked(world,g,state))fail('Siege participant selection cannot be changed while preparing or participating in Siege.',409);
  if(!Array.isArray(memberRefs)||memberRefs.length>limit||memberRefs.some(r=>typeof r!=='string')||new Set(memberRefs).size!==memberRefs.length)
    fail(`Select up to ${limit} distinct guild members.`);
  const members=new Set(g.members.map(m=>m.ref));
  if(memberRefs.some(r=>!members.has(r)))fail('Choose current guild members.',409);
  g.siegeMembers=[...memberRefs];
}
export function requireGuildSiegeMember(world,g,ref) {
  const view=guildSiegeRoster(world,g);
  if(!view.limit)fail('The original siege participant limit is unavailable.',503);
  if(!view.selected.includes(ref))fail('Only selected guild members are allowed in Siege.',403);
}
