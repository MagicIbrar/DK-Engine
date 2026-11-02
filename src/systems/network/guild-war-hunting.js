// Shared play: Guild War Hunting (Braiken Castle Defense Battle 707). The host runs it (server/world/guild-war-hunting.mjs);
// this module answers Vascuda's original jobs 137 (guild member entry) / 138 (observer entry) and draws the run from
// snapshot.hunt with the original windows:
//   dungeon timer rows (707|100 Begin in / 101 Progress Time / 103 End waiting time), the guild info board
//   game2/guildwarhunting/ui_huntguildinfownd.txt (live top 10, 270|79/80/83), the alarm button
//   ui_huntscoreboard_alarm.txt (opens the board), and the final ranking ui_huntscoreboardwnd.txt (270|4/77-85).
// The castle gate brick (maps[707] isCreate 1) is drawn and blocks movement like the host's collision.
// Guild marks are painted on both boards. ui_huntminimapwnd opens with its five pan_light_N hidden: Global shows a light
// only for nonzero server x,y (HuntMinimapWnd 0x71430002); no source says what each light means, so the host never sends one (removed, lanes 47/71).
// The session follows the GM steps (open/ready = 100 Begin in, start = 101 Progress Time, finish = 103 End waiting
// time); Global has no durations, so the rows show the label without a countdown.
// When the final board first opens, Global posts stringtable_pc 40:216 (top guild) to the SiegeMessage window for 8000 ms
// (decompile 32-bit-main FUN_00d00b70; showHuntTopGuild).
import {EventUI} from '../events/windows.js';
import {loadEventData} from '../events/data.js';
import {Brick,footprintCells} from '../events/bricks.js';
import {blockCollisionCells} from '../../world/collision-blockers.js';
import {huntBoardMarks,huntInfoMarks} from '../events/guild-war-hunting-rules.js';
import {installSharedGuildTournament} from './guild-tournament.js';
import {installSharedDkrPvp} from './dkr-pvp.js';
import {GWH_TOP_GUILD_MS,GWH_TOP_GUILD_STRING,gwhTopGuildText,showSiegeMessage} from '../events/mode-ui-rules.js';
const SCRIPTS={board:'game2/guildwarhunting/ui_huntscoreboardwnd.txt',info:'game2/guildwarhunting/ui_huntguildinfownd.txt',alarm:'game2/guildwarhunting/ui_huntscoreboard_alarm.txt',minimap:'game2/guildwarhunting/ui_huntminimapwnd.txt'};
/** Paint (or hide) scripted guild mark panels from huntBoardMarks / huntInfoMarks. */
export function applyHuntMarks(win,list){for(const {panel,image} of list){const c=win.control(panel);if(image){c.setImage('none',image);c.setVisible(true);}else c.setVisible(false);}}
/** Hide the five ui_huntminimapwnd lights: no source gives their meaning (server x,y per pan_light_N): removed. */
export function placeHuntLights(win){for(let i=0;i<5;i++)win.control(`pan_light_${i}`)?.setVisible?.(false);}
const npcId=n=>Number(n?.npcIndex??n?.index??n?.st??n?.def?.index);
const fmt=n=>Number(n||0).toLocaleString('en-US');
/** Fill the original final scoreboard from a host run record (top 10 + own guild row). */
export function fillHuntBoard(win,run){
  const top=run?.top||[],first=top[0];
  win.control('lbl_firstrank').setText(first?String(first.rank):'');win.control('lbl_firstguildname').setText(first?.name||'');win.control('lbl_firstguildscore').setText(first?fmt(first.score):'');
  for(let i=0;i<10;i++){const r=top[i];
    win.control(`lbl_vecrank_${i}`).setText(r?String(r.rank):'');win.control(`lbl_vecguildname_${i}`).setText(r?.name||'');win.control(`lbl_vecservername_${i}`).setText(r?.server||'');
    win.control(`lbl_vecguildlevel_${i}`).setText(r?String(r.level):'');win.control(`lbl_vecguildmaster_${i}`).setText(r?.master||'');win.control(`lbl_vecguildscore_${i}`).setText(r?fmt(r.score):'');}
  const me=run?.me;
  win.control('lbl_guildrank').setText(me?String(me.rank):'');win.control('lbl_guildname').setText(me?.guildName||'');win.control('lbl_servername').setText(me?.server||'');
  win.control('lbl_pcname').setText(me?.name||'');win.control('lbl_guildscore').setText(me?fmt(me.guildScore):'');
  applyHuntMarks(win,huntBoardMarks(run));
}
/** Fill the live guild info board (top 10 guild names + scores). */
export function fillHuntInfo(win,run){const top=run?.top||[];for(let i=0;i<10;i++){const r=top[i];win.control(`lbl_vecguildname_${i}`).setText(r?.name||'');win.control(`lbl_vecguildscore_${i}`).setText(r?fmt(r.score):'');}applyHuntMarks(win,huntInfoMarks(run));}
/** Global FUN_00d00b70: when the hunt finishes and the final board first shows, the SiegeMessage window shows stringtable_pc
 *  40:216 for 8000 ms with <NAME> = the first-ranked guild. No first entry = no message. */
export function showHuntTopGuild(game,run){const name=run?.top?.[0]?.name;if(!name)return null;
  const text=gwhTopGuildText(game?.uiwin?.strings?.get?.(GWH_TOP_GUILD_STRING),name);return text?showSiegeMessage(game,text,{durationMs:GWH_TOP_GUILD_MS}):null;}
export function installSharedGuildWarHunting(game,network){
  const state={run:null,data:null,ui:null,wins:{},bricks:new Map(),release:null,finalShown:null,generation:0};
  void loadEventData().then(d=>{state.data=d;}).catch(()=>{});
  const report=error=>game.chat?.system?.(error?.message||String(error),'err');
  const send=intent=>network.action('hunt',intent).catch(report);
  const win=async key=>{if(state.wins[key]&&!state.wins[key].disposed)return state.wins[key];const w=await game.uiwin?.create?.(SCRIPTS[key],{name:`ev_hunt_${key}`,disposeOnClose:key==='board'});if(!w)return null;state.wins[key]=w;
    if(key==='board'){const exit=w.control('btn_exit');exit.setVisible(true);exit.setEnabled(true);exit.onClick(()=>w.close('ok'));}
    if(key==='alarm')w.control('btn_alarm').onClick(()=>void openBoard());
    return w;};
  const openBoard=async()=>{const run=state.run;if(!run)return;const w=await win('board');if(!w)return;fillHuntBoard(w,run);game.uiwin.openWindow(w);};
  const clear=()=>{state.generation++;state.run=null;state.finalShown=null;for(const [k,w] of Object.entries(state.wins)){try{w.close?.('hunt');}catch{}}state.wins={};
    for(const b of state.bricks.values())b.dispose?.();state.bricks.clear();state.release?.();state.release=null;game.uiwin?.close?.('ev_dtime');};
  const bricks=run=>{if(!state.data||state.bricks.size||!run.bricks?.length)return;const col=game.world?.collision,cells=[],generation=state.generation;
    for(const row of run.bricks){const def=state.data.brick(row.brick);if(!def)continue;
      if(col?.cells)for(const [x,z] of footprintCells(row.x,row.z,row.dir,def.widthSize||1,def.heightSize||1))if(x>=0&&z>=0&&x<col.width&&z<col.height)cells.push(z*col.width+x);
      const b=new Brick(game,def,{...row,isCreate:1});b.isBrick=true;b.kind='brick';b.brain=null;state.bricks.set(row.uid,b);void b.load?.().then(()=>{if(generation!==state.generation)b.dispose?.();}).catch(()=>{b.dispose?.();state.bricks.delete(row.uid);});}
    if(col?.cells&&cells.length)state.release=blockCollisionCells(col,cells);};
  const sync=async run=>{
    if(!run||Number(game.world?.info?.index)!==run.map){if(state.run)clear();return;}
    if(state.run&&state.run.id!==run.id)clear();state.run=run;hook();bricks(run);
    const d=state.data,code=run.phase==='begin'?100:run.phase==='battle'?101:103,label=d?.mapTxt?.(run.map,code)||'';
    state.ui||=new EventUI(game,state);
    void state.ui.dungeonTimes([label,run.me?`<color=fdb602>Score:</color> ${fmt(run.me.guildScore)}`:null]);
    const alarm=await win('alarm');if(alarm&&!alarm.isOpen)game.uiwin.openWindow(alarm);
    const minimap=await win('minimap');if(minimap){placeHuntLights(minimap);if(!minimap.isOpen)game.uiwin.openWindow(minimap);}
    if(run.phase!=='end'){const info=await win('info');if(info){fillHuntInfo(info,run);if(!info.isOpen)game.uiwin.openWindow(info);}}
    else{state.wins.info?.close?.('end');if(run.final&&state.finalShown!==run.id){state.finalShown=run.id;try{void Promise.resolve(showHuntTopGuild(game,run)).catch(()=>{});}catch{}await openBoard();}}
    if(state.wins.board?.isOpen)fillHuntBoard(state.wins.board,run);
  };
  // Shared Game skips the local spawner loop: drive the gate brick's visual update from the shared frame hook.
  const hook=()=>{const host=game.sharedEvents;if(!host||host.huntUpdate)return;const update=host.update;host.huntUpdate=true;host.update=dt=>{update?.(dt);for(const b of state.bricks.values())if(!b.disposed)b.update?.(dt);};};
  const original=network._snapshot?.bind(network);
  if(original)network._snapshot=snapshot=>{original(snapshot);if(!network.disposed)void sync(snapshot?.hunt||null).catch(()=>{});};
  let services=null;
  const register=()=>{const s=game.npcServices;if(!s?.register||services===s)return;services=s;
    s.register(137,n=>{game.uiwin?.close('npc');void send({operation:'enter',npcIndex:npcId(n)});return true;});
    s.register(138,n=>{game.uiwin?.close('npc');void send({operation:'observe',npcIndex:npcId(n)});return true;});};
  register();game.events?.on?.('systems',register);
  game.chat?.registerCommand?.('/leavehunt',()=>{if(state.run)void send({operation:'leave'});return true;},'Leave Guild War Hunting.');
  const leave=network.leave?.bind(network);if(leave)network.leave=options=>{clear();return leave(options);};
  // The Guild Tournament (Colosseum guild events, network/guild-tournament.js) installs alongside the hunt.
  try{if(!game.sharedGuildTournament)game.sharedGuildTournament=installSharedGuildTournament(game,network,game.sharedTravel?.sys);}catch(error){console.warn('[network] Guild Tournament unavailable',error);}
  // DK Rumble 3v3 PvP (Colosseum pvp3v3, network/dkr-pvp.js) installs alongside them.
  try{if(!game.sharedDkrPvp)game.sharedDkrPvp=installSharedDkrPvp(game,network,game.sharedTravel?.sys);}catch(error){console.warn('[network] DK Rumble unavailable',error);}
  return {state,sync,openBoard};
}