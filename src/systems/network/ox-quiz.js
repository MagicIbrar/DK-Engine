// Display and intent transport for the GM-run native OX Quiz. No local quiz timer, answer picker, reward or elimination.
import {fetchText} from '../../engine/assets.js';
import {parseStringTableCates} from '../../ui/uiwin/strings.js';
import {OX_QUIZ as Q,oxWindowView,oxFormat} from '../../game/ox-quiz-rules.js';
import {Brick,footprintCells} from '../events/bricks.js';
import {blockCollisionCells} from '../../world/collision-blockers.js';
import {Messenger} from '../events/text.js';
import {EffectBanners} from '../events/effectui.js';

let presentationStrings;
const loadStrings=()=>presentationStrings||=Promise.all([fetchText(Q.window.file),fetchText('script/string/map/stringtable_map_string_01.txt')]).then(([window,map])=>({window:parseStringTableCates(window),map:parseStringTableCates(map)}));
// Only the native Ox directives used by cate22/654: preserving original text, message kind and countdown effect.
function nativeEntry(text){if(!text)return null;const effectUi=[];text=String(text).replace(/@<effectui>(\d+),(\d+),(\d+),(\d+)/gi,(_m,id,a,ms,b)=>{effectUi.push({id:Number(id),a:Number(a),ms:Number(ms),b:Number(b)});return '';});const kind=/^\s*\[message\]/i.test(text)?'message':'dialog';return {text:text.replace(/^\s*\[message\]\s*/i,''),kind,effectUi};}
const npcId=npc=>Number(npc?.npcIndex??npc?.def?.index);
const menu=[['wall',Q.menu.wall],['unwall',Q.menu.unwall],['eliminate',Q.menu.eliminateO,'O'],['eliminate',Q.menu.eliminateX,'X'],['question',Q.menu.question],['close',Q.menu.close],['end',Q.menu.end]];

export function installSharedOxQuiz(game,network,{bridge,dialog,ui}){
 const ox=game.sharedOxQuiz={state:null,brick:null},banners=new EffectBanners(game,bridge);
 let disposed=false,latest=null,texts=null,mapTexts=null,world=null,wallKey=null,releaseMask=null,generation=0,renderKey=null,renderGeneration=0;
 const seen=new Set(),wallBanners=new Map();let noticeDeadline=null,wallNotice=null;
 game.uiwin?.registerWindow('oxquiz',{script:Q.script,hud:true,escClose:false,remember:false,band:'hud'});
 // Lane 47: Global opens only UI_Game2_Event_ui_oxquizwnd for OX (decompile 32-bit-main decompiled.c:1020158, dekaron64:1301913);
 // no OX countdown window exists in Global, so the former OX countdown window (partywar limittime with non-Global English labels) is removed.
 const ready=Promise.all([bridge.ready,loadStrings()]).then(([data,strings])=>{texts=strings.window;mapTexts=strings.map;if(!disposed)sync();return data;}).catch(error=>{if(!disposed)game.chat?.system?.(error.message,'err');return null;});
 const current=()=>!disposed&&!network.disposed&&latest?.available===true&&latest.channel===true&&[Q.arena,Q.lobby].includes(Number(network.self?.map))&&Number(game.world?.info?.index)===Number(network.self?.map)&&latest.map===Number(network.self?.map);
 const arena=()=>current()&&latest.map===Q.arena;
 const serverTime=()=>{const clock=network._serverClock;return Number.isFinite(clock?.time)&&Number.isFinite(clock?.at)?clock.time+performance.now()-clock.at:NaN;};
 const pending=at=>arena()&&latest.wall?.state==='pending'&&Number.isFinite(at)&&latest.wall.at===at&&serverTime()<at;
 const dropBanner=effect=>{for(const part of effect.parts)part.el.remove();const index=banners.live.indexOf(effect);if(index>=0)banners.live.splice(index,1);wallBanners.delete(effect);};
 // EventMessage lines stack (Global 5-line queue): remove only this quiz's own line; older EventUI hosts close the window as before.
 const dropNotice=text=>{if(typeof ui?.dropNotice==='function'){ui.dropNotice(text);return;}if(game.uiwin?.window('ev_message')?.control('lbl_message').getText()===text)game.uiwin?.close('ev_message');};
 const syncWarnings=()=>{
  for(const [effect,at]of wallBanners){if(!pending(at)||!banners.live.includes(effect))dropBanner(effect);else effect.t=Math.max(effect.t,effect.ms-(at-serverTime()));}
  if(wallNotice&&!pending(wallNotice.at)){dropNotice(wallNotice.text);wallNotice=null;}
 };
 let bannerQueue=Promise.resolve();const speaker=new Messenger(game,{
  notice:text=>{const noticeWorld=game.world,at=noticeDeadline;void ui.notice(text).then(()=>{if(at!=null)wallNotice={text,at};if(disposed||noticeWorld!==game.world||at!=null&&!pending(at))dropNotice(text);});},
  banner:(id,ms)=>{const bannerWorld=game.world,at=noticeDeadline;bannerQueue=bannerQueue.then(async()=>{if(!arena()||bannerWorld!==game.world||at!=null&&!pending(at))return;const before=new Set(banners.live);await banners.show(id,ms);for(const effect of banners.live.filter(b=>!before.has(b))){if(disposed||bannerWorld!==game.world||at!=null&&!pending(at))dropBanner(effect);else if(at!=null){effect.t=Math.max(0,ms-(at-serverTime()));wallBanners.set(effect,at);}}});},
 });
 const closeWindow=()=>{renderGeneration++;renderKey=null;game.uiwin?.close('oxquiz');};
 const clearWall=()=>{generation++;releaseMask?.();releaseMask=null;ox.brick?.dispose();ox.brick=null;wallKey=null;};
 const wall=()=>{
  if(world!==game.world){clearWall();world=game.world;}
  const row=arena()&&latest.wall?.state==='up'?latest.wall:null,def=row&&bridge.data?.brick(row.brick);
  if(!row||row.uid!==Q.wall.uid||row.brick!==Q.wall.brick||!def||!Number.isFinite(row.footprintDir)){if(wallKey)clearWall();return;}
  const key=JSON.stringify([row.uid,row.brick,row.x,row.z,row.dir,row.footprintDir,row.w,row.h]);if(wallKey===key)return;
  clearWall();wallKey=key;const collision=world?.collision;
  if(collision?.cells){const indices=footprintCells(row.x,row.z,row.footprintDir,def.widthSize,def.heightSize).filter(([x,z])=>x>=0&&z>=0&&x<collision.width&&z<collision.height).map(([x,z])=>z*collision.width+x);releaseMask=blockCollisionCells(collision,indices);}
  const b=ox.brick=new Brick(game,def,row),epoch=generation;b.breakable=false;b.brain=null;b.kind='brick';
  void b.load().then(()=>{if(disposed||generation!==epoch||world!==game.world||ox.brick!==b)b.dispose();}).catch(error=>{b.dispose();if(ox.brick===b)ox.brick=null;if(!disposed&&generation===epoch)game.chat?.system?.(error.message,'err');});
 };
 const render=()=>{
  const view=arena()?oxWindowView(latest):null;if(!view||!texts){if(renderKey)closeWindow();return;}
  const values=Object.fromEntries(Object.entries(view).map(([id,value])=>[id,value.text??oxFormat(texts.get(`${value.cate}:${value.code}`),value.args)]));
  if(Object.values(values).some(v=>!v)){if(renderKey)closeWindow();return;}
  const key=JSON.stringify(values);if(renderKey===key)return;renderKey=key;const epoch=++renderGeneration,renderWorld=game.world;
  void game.uiwin?.open('oxquiz').then(win=>{if(disposed||epoch!==renderGeneration||renderWorld!==game.world||!arena()){if(!arena())game.uiwin?.close('oxquiz');return;}for(const [id,text]of Object.entries(values))win.control(id).setRichText(text);}).catch(error=>{if(!disposed&&epoch===renderGeneration){renderKey=null;game.chat?.system?.(error.message,'err');}});
 };
 function sync(){ox.state=current()?latest:null;wall();render();syncWarnings();}
 const nativeError=message=>{const m=/^oxquiz:(22|654):(\d+)$/.exec(String(message||''));if(!m)return false;const entry=nativeEntry(mapTexts?.get(`${m[1]}:${m[2]}`));if(entry)speaker.say(entry);return !!entry;};
 const send=async(operation,answer)=>{
  if(disposed||!network.ready||!network.token)return null;const token=network.token,before=network._lastCommandError;
  try{const result=await network.action('oxquiz',{operation,...(answer?{answer}:{})});if(disposed||network.disposed||network.token!==token)return null;
   if(!result&&network._lastCommandError!==before)nativeError(network._lastCommandError?.message);
   return result;
  }catch(error){if(!disposed&&network.token===token&&!nativeError(error.message))game.chat?.system?.(error.message,'err');return null;}
 };
 const pick=(operation,answer)=>{dialog.close();void send(operation,answer);};
 const option=(map,code,operation,answer)=>{const label=mapTexts?.get(`${map}:${code}`);return label?{label,pick:()=>pick(operation,answer)}:null;};
 const open=npc=>{
  const id=npcId(npc),map=Number(game.world?.info?.index);if(!((map===Q.lobby&&id===Q.npcs.hani)||(map===Q.arena&&[Q.npcs.startStone,Q.npcs.escapeStone].includes(id))))return false;
  // Consume a recognized OX NPC even before readiness; it must never fall through to a local dungeon/GM simulation.
  const dialogWorld=game.world;
  void ready.then(()=>{if(!current()||dialogWorld!==game.world||latest.map!==map)return;const data=bridge.data,record=data?.npc(id),job=id===Q.npcs.hani?Q.jobs.hani:id===Q.npcs.startStone?Q.jobs.startStone:Q.jobs.escapeStone;
   if(!record?.jobs?.some(([type,index])=>Number(type)===job[0]&&Number(index)===job[1]))return;
   const choices=id===Q.npcs.hani?[option(Q.lobby,9710,'enter')]:id===Q.npcs.escapeStone?[option(Q.arena,Q.menu.escape,'leave')]:latest.gm?menu.map(([operation,code,answer])=>option(Q.arena,code,operation,answer)):[];
   const page={title:record.name,text:record.greeting,options:choices.filter(Boolean)};
   void dialog.open(npc,page).then(()=>{if((disposed||dialogWorld!==game.world)&&dialog.root===page)dialog.close();});
  });return true;
 };
 const oldOpen=game.windows?.openNpc?.bind(game.windows);if(oldOpen)game.windows.openNpc=npc=>open(npc)?null:oldOpen(npc);
 const registered=new Set(),service=npc=>open(npc);
 const register=()=>{const registry=game.npcServices;if(!registry||registered.has(registry))return;registered.add(registry);const list=registry.handlers?.get(31);if(Array.isArray(list))list.unshift(service);else registry.register?.(31,service);};register();const off=game.events?.on?.('systems',register);
 const command=args=>{const [name,answer,...extra]=String(args||'').trim().split(/\s+/),operation=name?.toLowerCase()==='closeentry'?'closeEntry':name?.toLowerCase();
  if(extra.length||!['enter','leave','open','closeEntry','close','wall','unwall','question','eliminate','end'].includes(operation)||(operation==='eliminate'?!/^[OX]$/i.test(answer||''):!!answer)){game.chat?.system?.('/oxquiz <enter|leave|open|closeentry|wall|unwall|question|eliminate O/X|close|end>','sys');return true;}
  void send(operation,answer?.toUpperCase());return true;
 };
 const previousCommand=game.chat?.commands?.get('/oxquiz');game.chat?.registerCommand?.('/oxquiz',command,'OX quiz native entry and GM controls; the server checks every intent.');
 const originalSnapshot=network._snapshot.bind(network);network._snapshot=snapshot=>{if(disposed||network.disposed)return;if(Number(snapshot?.sequence)<network.sequence){originalSnapshot(snapshot);return;}if(Object.hasOwn(snapshot||{},'oxQuiz'))latest=snapshot.oxQuiz;originalSnapshot(snapshot);sync();};
 const originalEvent=network._event.bind(network);network._event=event=>{
  if(!['oxQuizNotice','oxQuizWall','oxQuizMove','oxQuiz'].includes(event.type)){originalEvent(event);return;}
  if(!(arena()&&Number(event.map)===Q.arena)&&!(current()&&latest.map===Q.lobby&&Number(event.map)===Q.lobby&&event.type==='oxQuizNotice'))return;
  if(event.channel!==network.self?.channel)return;
  const key=`${event.sequence}:${event.type}`;if(seen.has(key))return;seen.add(key);if(seen.size>256)seen.delete(seen.values().next().value);
  if(event.type==='oxQuizNotice'){
   const wallCue=event.cate===Q.arena&&[Q.notice.wallCountdown,Q.notice.wallWarning].includes(event.code);
   if(wallCue&&!pending(event.at))return;
   noticeDeadline=wallCue?event.at:null;try{speaker.say(nativeEntry(mapTexts?.get(`${event.cate}:${event.code}`)));}finally{noticeDeadline=null;}
  }
  if(event.type==='oxQuiz'&&event.phase==='solution'&&texts)speaker.say(oxFormat(texts.get(`${Q.window.cate}:${Q.window.survivors}`),{COUNT:event.survivors,MAX_COUNT:event.maxCount}));
  // The host snapshot, including its position revision, owns wall state and forced displacement.
 };
 const update=bridge.update;bridge.update=dt=>{update(dt);if(disposed)return;sync();banners.update(dt);ox.brick?.update(dt);};
 const dispose=bridge.dispose;bridge.dispose=()=>{if(!disposed){disposed=true;off?.();for(const registry of registered)registry.unregister?.(31,service);registered.clear();clearWall();closeWindow();seen.clear();for(const b of banners.live)for(const p of b.parts)p.el.remove();banners.live.length=0;wallBanners.clear();wallNotice=null;if(game.chat?.commands?.get('/oxquiz')?.fn===command){if(previousCommand)game.chat.commands.set('/oxquiz',previousCommand);else game.chat.commands.delete('/oxquiz');}ox.state=null;}dispose();};
 ox.ready=ready;ox.action=send;ox.openNpc=open;return ox;
}
