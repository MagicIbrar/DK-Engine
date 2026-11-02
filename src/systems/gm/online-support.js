// Keep presentation routing and visible control availability aligned with the GM host.
// tpclick: a local on/off; each Ctrl+click it enables travels through the server's authenticated GM route
// (operation 'teleportDestination', server/world/gm-map-destination.mjs), never through client-side movement.
export const ONLINE_PRESENTATION = new Set(['help','panel','console','sysinfo','usermonitor','userlog','pos','viewer','showdebug','hideui','fps','inspect','droptable','simdrops','effect','bgm','freecam','sky','weatherfx','time','itemedit','maptool','tpclick']);
export const ONLINE_SERVER_COMMANDS = new Set(['exprate','droprate','dilrate','mapbuff','god','hide','onehit','infinitemp','gmmode','skill','allskills','skillreset','cooldowns','buff','level','exp','dil','dkc','vip','heal','revive','setstat','statreset','grade','speed','move','guildwarteleport','siegemonitor','goloc','gotonpc','usercount','mapusercount','notice','mute','freeze','ai','callmonster','killall','respawn','makeitem','clearinv','quest','queststate','repairall','save','monstertune','monsterloot','partywar','partywarevent','ox','oxentry','giveitem','dkrpvp_create','dkrpvp_delete','dkrpvp_applystart','dkrpvp_applymember','dkrpvp_selectteam','dkrpvp_createleague','dkrpvp_open','dkrpvp_finish','dkrpvp_setstatus','dkrpvp_createtournament','set_dksquareinfo','guildwarhunting_open','guildwarhunting_ready','guildwarhunting_start','guildwarhunting_finish']);
// Tools that act on the shared world or on other connected characters: no solo counterpart.
const SHARED_ONLY=new Set(['monstertune','monsterloot','giveitem']);
// Lane 47: Global GM event commands (dkrpvp_*, set_dksquareInfo, guildwarhunting_*) exist only on a shared host.
export const GLOBAL_EVENT_GM=new Set(['dkrpvp_create','dkrpvp_delete','dkrpvp_applystart','dkrpvp_applymember','dkrpvp_selectteam','dkrpvp_createleague','dkrpvp_open','dkrpvp_finish','dkrpvp_setstatus','dkrpvp_createtournament','set_dksquareinfo','guildwarhunting_open','guildwarhunting_ready','guildwarhunting_start','guildwarhunting_finish']);
const REASONS={
  setclass:'Online class changes need a server migration for equipment, skills and saved character data.',
  noclip:'The shared world enforces movement collision. Use the GM 3D camera to inspect through geometry.',
  unlockmaps:'The shared world enforces map entry and collision rules.',
  spawnnpc:'Live NPC spawning has no server route. Place original NPCs in a Map Builder draft and publish the custom map.',
  enterdungeon:'This original GM dungeon command has no server route. Use the supported NPC or party entry.',
  pcroomexp:'Shared PC-cafe EXP overrides have no server route.',
  timescale:'The authoritative simulation clock cannot be changed by this client.',
  event:'This original GM event starter has no shared-server route. Inspect the timetable or use supported event entry.',
  shutdown:'The game client cannot schedule or cancel shared-server shutdown.',
  formula:'Online formula overrides have no server route.',sysvar:'Online system-variable overrides have no server route.',applyall:'Online formula/system-variable overrides cannot be applied or saved.',resetformula:'Online formula overrides cannot be reset from this client.',
  snapshot:'Online snapshots cannot be saved/restored by this tool. Export a read-only character snapshot instead.',
  importSave:'Online character JSON import/apply is unavailable. Use server GM character commands.',
  questslots:'Online objective counters are owned by the server. Use the server Complete action for GM completion.',
  questdone:'Online completion must use the server Complete action so quest rewards and persistence stay consistent.',
};
const VISUAL=new Set(['time','weatherfx','sky','effect','bgm','freecam','showdebug','hideui','fps']);
/** GM toggles that live only in this client (save.gm) and are never part of the server profile. A canonical snapshot
 *  replaces save.gm with the profile's gm object (network/client.js _profile), which silently switched Ctrl+click teleport
 *  off after any server GM command; keepClientLocalGM carries them over. */
export const CLIENT_LOCAL_GM=Object.freeze(['tpclick']);
export function keepClientLocalGM(previous,save){
  if(!previous||typeof previous!=='object'||!save)return;
  const kept={};for(const key of CLIENT_LOCAL_GM)if(Object.hasOwn(previous,key))kept[key]=previous[key];
  if(Object.keys(kept).length)save.gm={...(save.gm&&typeof save.gm==='object'?save.gm:{}),...kept};
}
export function commandSupport(game,id,args={}) {
  if(game.save?.authority!=='server'&&GLOBAL_EVENT_GM.has(id))return{enabled:false,kind:'unsupported',reason:'Global event GM commands run on a shared server host.'};
  if(game.save?.authority!=='server')return SHARED_ONLY.has(id)?{enabled:false,kind:'unsupported',reason:id==='giveitem'?'GM prizes go to other connected characters on a shared server.':'This runtime monster tool belongs to a shared server.'}:{enabled:true,kind:'solo',reason:''};
  if(id==='save'&&['import'].includes(String(args.action).toLowerCase()))return{enabled:false,kind:'unsupported',reason:REASONS.importSave};
  if(id==='save'&&['export','edit'].includes(String(args.action).toLowerCase()))return{enabled:true,kind:'inspection',reason:'Read-only client snapshot/export; online JSON changes cannot be applied.'};
  if(id==='tpclick')return{enabled:true,kind:'server',reason:''};
  if(id==='oxentry')return{enabled:true,kind:'server',reason:''};
  if(id==='ox')return String(args.action).toLowerCase()==='auto'?{enabled:false,kind:'unsupported',reason:'Scheduled OX runs automatically on Saturday at17:00 server time. This GM session remains manual; use Ask and elimination controls.'}:{enabled:true,kind:'server',reason:''};
  if(ONLINE_PRESENTATION.has(id))return{enabled:true,kind:VISUAL.has(id)?'presentation':'inspection',reason:VISUAL.has(id)?'Local visual preview: affects only this client.':''};
  if(ONLINE_SERVER_COMMANDS.has(id))return{enabled:true,kind:'server',reason:''};
  return{enabled:false,kind:'unsupported',reason:REASONS[id]||`This original GM tool (${id}) has no shared-server route. Solo behavior is preserved.`};
}

export function applyCommandSupport(element,game,id,args={}) {
  const state=commandSupport(game,id,args);
  element.disabled=!state.enabled;
  if(!state.enabled){if(!element.hasAttribute('data-gm-unavailable'))element._gmSupportedTitle=element.title;element.title=state.reason;element.setAttribute('data-gm-unavailable',id);element.setAttribute('aria-disabled','true');}
  else {if(element.hasAttribute('data-gm-unavailable'))element.title=element._gmSupportedTitle||'';element.removeAttribute('data-gm-unavailable');element.removeAttribute('aria-disabled');}
  return state;
}
