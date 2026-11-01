// Shared play: Guild War Hunting (Braiken Castle Defense Battle 707). The host runs it (server/world/guild-war-hunting.mjs);
// this module answers Vascuda's original jobs 137 (guild member entry) / 138 (observer entry) and draws the run from
// snapshot.hunt with the original windows:
//   dungeon timer rows (707|100 Begin in / 101 Progress Time / 103 End waiting time), the guild info board
//   game2/guildwarhunting/ui_huntguildinfownd.txt (live top 10, 270|79/80/83), the alarm button
//   ui_huntscoreboard_alarm.txt (opens the board), and the final ranking ui_huntscoreboardwnd.txt (270|4/77-85).
// The castle gate brick (maps[707] isCreate 1) is drawn and blocks movement like the host's collision.
// Guild marks are painted on both boards; ui_huntminimapwnd shows five lights with an ENGINE-CHOSEN meaning
// (you / guild members / two invader areas / boss; src/config/engine-chosen-guild-war-hunting.js minimap).
import {EventUI} from '../events/windows.js';
import {loadEventData} from '../events/data.js';
import {Brick,footprintCells} from '../events/bricks.js';
import {blockCollisionCells} from '../../world/collision-blockers.js';
import {huntBoardMarks,huntInfoMarks,huntLightLayout,argbCss} from '../events/guild-war-hunting-rules.js';
import {installSharedGuildTournament} from './guild-tournament.js';
import {installSharedDkrPvp} from './dkr-pvp.js';
const SCRIPTS={board:'game2/guildwarhunting/ui_huntscoreboardwnd.txt',info:'game2/guildwarhunting/ui_huntguildinfownd.txt',alarm:'game2/guildwarhunting/ui_huntscoreboard_alarm.txt',minimap:'game2/guildwarhunting/ui_huntminimapwnd.txt'};
/** Paint (or hide) scripted guild mark panels from huntBoardMarks / huntInfoMarks. */
export function applyHuntMarks(win,list){for(const {panel,image} of list){const c=win.control(panel);if(image){c.setImage('none',image);c.setVisible(true);}else c.setVisible(false);}}
/** Place the five ui_huntminimapwnd lights (ENGINE-CHOSEN meaning: you / guild / invader areas / boss). */
export function placeHuntLights(win,lights){for(const l of huntLightLayout(lights)){const c=win.control(l.panel);if(!l.visible){c.setVisible(false);if(c._huntBlink){c.setBlink?.(false);c._huntBlink=false;}continue;}
  c.setRect(l.x,l.y,l.size,l.size);if(c.el?.style){c.el.style.background=`radial-gradient(circle, ${argbCss(l.color)} 0%, rgba(0,0,0,0) 70%)`;c.el.style.borderRadius='50%';}c.setVisible(true);if(!!c._huntBlink!==l.blink){c.setBlink?.(l.blink);c._huntBlink=l.blink;}}}
const npcId=n=>Number(n?.npcIndex??n?.index??n?.st??n?.def?.index);
const fmt=n=>Number(n||0).toLocaleString('en-US');
const mmss=ms=>{const s=Math.max(0,Math.floor(ms/1000));return `${String(Math.floor(s/60)).padStart(2,'0')}:${String(s%60).padStart(2,'0')}`;};
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
    void state.ui.dungeonTimes([`${label} ${mmss(run.remainingMs)}`,run.me?`<color=fdb602>Score:</color> ${fmt(run.me.guildScore)}`:null]);
    const alarm=await win('alarm');if(alarm&&!alarm.isOpen)game.uiwin.openWindow(alarm);
    const minimap=await win('minimap');if(minimap){placeHuntLights(minimap,run.lights);if(!minimap.isOpen)game.uiwin.openWindow(minimap);}
    if(run.phase!=='end'){const info=await win('info');if(info){fillHuntInfo(info,run);if(!info.isOpen)game.uiwin.openWindow(info);}}
    else{state.wins.info?.close?.('end');if(run.final&&state.finalShown!==run.id){state.finalShown=run.id;await openBoard();}}
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