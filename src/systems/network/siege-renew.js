// Active193/194/195 SiegeRenew intent/presentation. The host owns eligibility,
// combat, capture, revival, timers and persistence. No local phase/reward logic.
import {SiegeForceAttackAlarm,siegePlayerHostile} from './siege-force-attack.js';
import {registerEventActors} from './event-actors.js';
import {fetchJSON} from '../../engine/assets.js';
import {Brick} from '../events/bricks.js';
import {siegeRenewCastles} from '../../game/siege-renew-rules.js';
import {RENEW as R} from '../../game/siege-renew-controller-rules.js';
import {fillText,plainText} from '../../game/siege-rules.js';
import {RENEW_OBSERVER_TEXT} from '../../game/siege-renew-service-rules.js';
import {Trigger} from '../dungeons/triggers.js';
import {D,loadData} from '../dungeons/data.js';
import {bindSiegeGuardWindow} from './siege-renew-guard-window.js';
import {SiegeGuardEffects} from './siege-renew-guard-effects.js';
import {SiegeRenewGates} from './siege-renew-gates.js';
import {bindSiegeGateWindow} from './siege-renew-gate-window.js';
import {siegeUpgradeConfirm} from './siege-upgrade-confirm.js';
import {renewGateHP,renewGateRows} from '../../game/siege-renew-gate-rules.js';
const npcId=n=>Number(n?.npcIndex??n?.def?.index??n?.index);
const script='game2/siege/ui_siege_play_timewnd.txt',windowName='siegeRenewTime';
// stringtable_siegeUI.txt cates 290 / 320 load in group NORMAL; every other Renew code is group SIEGE.
const NORMAL_CATES=new Set([290,320,410]);
const sref=([cate,code])=>({group:R.castles.includes(Number(cate))?'DUNGEON':NORMAL_CATES.has(Number(cate))?'NORMAL':'SIEGE',cate,code});

export function installSharedSiegeRenew(game,network,{bridge,dialog}){
 const client=game.sharedSiegeRenew={state:null,brick:null},registered=new Set(),seen=new Set();
 const guardEffects=new SiegeGuardEffects(game,network);
 const gates=new SiegeRenewGates(game,id=>bridge.data?.brick?.(id));client.gates=gates.actors;
 let gateWindow=null,gateGeneration=0;
 let disposed=false,latest=null,catalog=null,world=null,castleId=null,generation=0,timerGeneration=0,timerKey=null,taxScope=null,guardWindow=null,guardGeneration=0;
 const nativeText=pair=>plainText(game.uiwin?.strings?.get?.(sref(pair))||(NORMAL_CATES.has(Number(pair[0]))?'':bridge.data?.txt?.('stringtable_siege.txt',...pair))||'');
 const say=(text,kind='sys')=>{if(text)game.chat?.system?.(plainText(text),kind);};
 const nativeError=message=>{const match=/^siege:(\d+):(\d+)$/.exec(String(message||''));if(!match)return false;const text=nativeText([Number(match[1]),Number(match[2])]);if(text){say(text,'err');void game.uiwin?.msgbox?.(text,{kind:'ok'});}return !!text;};
 game.uiwin?.registerWindow?.(windowName,{script,hud:true,escClose:false,remember:false,band:'hud'});
 game.uiwin?.registerWindow?.('siegeRenewTax',{script:'game2/siege/ui_siegetaxwnd.txt',remember:false});
 game.uiwin?.registerWindow?.('siegeRenewGuards',{script:'game2/siege/ui_siegeguardwnd.txt',remember:false});
 game.uiwin?.registerWindow?.('siegeRenewGates',{script:'game2/siege/ui_gateupgradewnd2.txt',remember:false});
 const ready=Promise.resolve(bridge.ready).then(async()=>{
  catalog=game.data?.npcs||await fetchJSON('/gamedata/npcs.json');
  await game.uiwin?.strings?.need?.([...Object.values(R.text).map(sref),{group:'NORMAL',cate:290,code:51},...Object.values(RENEW_OBSERVER_TEXT).map(sref)]);
  await game.uiwin?.strings?.need?.(R.castles.flatMap(map=>[100,101,102,103,111,112,114,115,116,117,118,119].map(code=>sref([map,code]))));
  await game.uiwin?.strings?.need?.([[320,107],[701,213],[701,218],[701,219],[701,207]].map(sref));
  await game.uiwin?.strings?.need?.([1,2,3,4,5].map(code=>sref([410,code])));
  if(!disposed)sync();return bridge.data;
 }).catch(error=>{if(!disposed)say(error.message,'err');return null;});
 const active=()=>!disposed&&!network.disposed&&network.active&&network.ready&&!!network.token;
 const castle=()=>{const c=latest?.castle,self=network.self;return active()&&c&&R.castles.includes(Number(c.map))&&self?.map===c.map&&self.instanceId===c.instanceId&&!!c.instanceId&&Number(game.world?.info?.index)===c.map?c:null;};
 const forceAlarm=new SiegeForceAttackAlarm(game,'siegeRenewForceAlarm',()=>castle()?.phase==='battle');
 const serverNow=()=>network._serverClock?network._serverClock.time+performance.now()-network._serverClock.at:Date.now();
 const send=async(operation,fields={})=>{
  if(!active())return null;const token=network.token,before=network._lastCommandError;
  try{const result=await network.action('siegerenew',{operation,...fields});if(disposed||network.disposed||network.token!==token)return null;if(!result&&network._lastCommandError!==before)nativeError(network._lastCommandError?.message);return result?.siegeRenewResult??result;}
  catch(error){if(!disposed&&network.token===token&&!nativeError(error.message))say(error.message,'err');return null;}
 };
 const unpick=b=>{const list=game.spawner?.monsters,i=list?.indexOf(b)??-1;if(i>=0)list.splice(i,1);if(game.player?.target===b||game.controller?.target===b)game.controller?.setTarget?.(null);};
 const clear=()=>{generation++;if(client.brick){unpick(client.brick);client.brick.dispose();client.brick=null;}castleId=null;};
 const closeTimer=()=>{timerGeneration++;timerKey=null;game.uiwin?.close?.(windowName);};
 const syncBrick=c=>{
  if(world!==game.world||castleId!==c?.instanceId){clear();world=game.world;castleId=c?.instanceId||null;}
  const row=c?.crystal,def=row&&bridge.data?.brick?.(row.brickIndex);
  if(!row||!def||R.guardian[c.map]?.[0]!==row.uid||R.guardian[c.map]?.[1]!==row.brickIndex){if(client.brick)clear();return;}
  let b=client.brick;
  if(b&&b.networkId!==row.id){clear();castleId=c.instanceId;b=null;}
  if(!b){b=client.brick=new Brick(game,def,{uid:row.uid,brick:row.brickIndex,x:row.x,z:row.z,dir:row.dir,isCreate:1});b.brain=null;b.isBrick=true;b.networkId=row.id;const epoch=generation,scene=world;
   void b.load().then(()=>{if(disposed||generation!==epoch||world!==scene||scene!==game.world||client.brick!==b){unpick(b);b.dispose();}}).catch(error=>{unpick(b);b.dispose();if(client.brick===b)client.brick=null;if(!disposed&&generation===epoch)say(error.message,'err');});
  }
  b.hp=row.hp;b.maxHp=b.maxHP=row.maxHp;b.dead=row.hp<=0;b.breakable=!!row.breakable&&c.phase==='battle'&&!b.dead;b.kind=b.breakable?'monster':'brick';
  if(b.breakable&&!game.spawner?.monsters?.includes(b))game.spawner?.monsters?.push(b);else if(!b.breakable)unpick(b);
  if(!b.dead&&!b.blocking)b.block(game.world?.collision);
 };
 const timer=c=>{
  if(!c||c.phase!=='battle'){if(timerKey!==null)closeTimer();return;}
  const format=plainText(game.uiwin?.strings?.get?.({group:'NORMAL',cate:290,code:51})||'');if(!format)return;
  const text=fillText(format,Math.max(0,Math.ceil((c.endAt-serverNow())/60000))),key=c.instanceId+':'+text;if(timerKey===key)return;timerKey=key;const epoch=++timerGeneration,scene=game.world;
  void game.uiwin?.open?.(windowName).then(win=>{if(disposed||epoch!==timerGeneration||scene!==game.world||castle()?.instanceId!==c.instanceId){if(!castle())game.uiwin?.close?.(windowName);return;}win?.control?.('lbl_text')?.setText?.(text);}).catch(error=>{if(!disposed&&epoch===timerGeneration){timerKey=null;say(error.message,'err');}});
 };
 // Lord's Treasure Chest: the native trigger (siege_box, trigger.csv 1/46/47) at its authored cell, shown from the host's
 // castle snapshot. Presentation only: availability, the claim and the reward are host decisions; no local roll or grant.
 let chestKey=null,tables=null;
 const clearChest=()=>{const t=client.chest;chestKey=null;if(!t)return;client.chest=null;const i=game.npcs?.indexOf(t)??-1;if(i>=0)game.npcs.splice(i,1);if(game.player?.target===t||game.controller?.target===t)game.controller?.setTarget?.(null);t.dispose();};
 const syncChest=c=>{
  const row=c?.chest,key=row?`${c.instanceId}:${row.trigger}`:null;
  if(key!==chestKey||client.chest?.disposed)clearChest();
  if(!key)return;
  const def=D.dg?.triggers?.[String(row.trigger)];
  if(!def){if(!tables)tables=Promise.resolve(D.dg?D:loadData()).then(()=>{if(!disposed)sync();}).catch(error=>{tables=null;if(!disposed)say(error.message,'err');});return;}
  let t=client.chest;
  if(!t){t=client.chest=new Trigger(game,def,{trigger:row.trigger,x:row.x,y:row.z,dir:row.dir},c.map);t.renewChest=true;t.networkId=`renew-chest:${key}`;chestKey=key;(game.npcs||=[]).push(t);const scene=game.world;void Promise.resolve(t.load()).then(()=>{if(!t.disposed&&(disposed||client.chest!==t||scene!==game.world))t.dispose();});}
  t.renewAvailable=!!row.available;
  if(row.claimed&&!t.renewOpened){t.renewOpened=true;t.advance();}   // native TRIGGERCHANGE_1 then STAND_2 (open box)
 };
 function sync(){const c=castle();forceAlarm.update();client.state=c?latest:null;syncBrick(c);gates.sync(c);syncChest(c);timer(c);if(taxScope&&!taxScope()){game.uiwin?.close?.('siegeRenewTax');taxScope=null;}if(guardWindow){if(!guardWindow.active)closeGuards();else guardWindow.update();}if(gateWindow){if(!gateWindow.active)closeGates();else gateWindow.update();}}
 const closeGuards=()=>{guardGeneration++;guardWindow?.dispose();guardWindow=null;game.uiwin?.close?.('siegeRenewGuards');};
 const closeGates=()=>{gateGeneration++;gateWindow?.dispose();gateWindow=null;game.uiwin?.close?.('siegeRenewGates');game.uiwin?.close?.('siegeRenewGateConfirm');};
 const nativeNpc=id=>catalog?.npcs?.[id]||bridge.data?.npc?.(id);
 const authoredJob=(id,type,index)=>nativeNpc(id)?.jobs?.some(([t,i])=>Number(t)===type&&Number(i)===index);
 const label=(npc,info)=>plainText(info?.label||nativeNpc(npcId(npc))?.name||npc?.name||'');
 const menuScope=npc=>{const scene=game.world,token=network.token,id=network.self?.instanceId;return ()=>active()&&network.token===token&&game.world===scene&&network.self?.instanceId===id&&!npc.disposed;};
 const pick=(operation,fields,current)=>{dialog.close();if(current())void send(operation,fields);};
 const page=(npc,options)=>void dialog.open(npc,{title:npc.name||nativeNpc(npcId(npc))?.name,text:bridge.data?.npc?.(npcId(npc))?.greeting||'',options});
 const openTax=async(npc,id,current)=>{
  dialog.close();if(!current())return;const result=await send('tax',{npcIndex:id});if(!current()||!result?.days)return;
  const win=await game.uiwin?.open?.('siegeRenewTax');if(!win)return;if(!current()){game.uiwin?.close?.('siegeRenewTax');return;}taxScope=current;
  const fill=rows=>{for(const row of rows){win.control(`lbl_money${row.day}`)?.setText?.(Number(row.amount).toLocaleString('en-US'));win.control(`btn_receive${row.day}`)?.setVisible?.(row.published&&!row.collected&&row.amount>0);win.control(`pan_received${row.day}`)?.setVisible?.(row.collected);}const any=rows.some(r=>r.published&&!r.collected&&r.amount>0);win.control('btn_receive7')?.setVisible?.(any);win.control('pan_received7')?.setVisible?.(!any);};
  let pending=false;for(let i=0;i<8;i++)win.control(`btn_receive${i}`)?.onClick?.(async()=>{if(pending||!current())return;pending=true;try{const next=await send('tax',{npcIndex:id,day:i===7?-1:i});if(current()&&next?.days)fill(next.days);}finally{pending=false;}});
  fill(result.days);
 };
 const openGuards=async(npc,id,current)=>{
  dialog.close();if(!current())return;closeGuards();const epoch=guardGeneration,c=castle(),native=siegeRenewCastles(bridge.data).find(r=>r.map===c?.map);if(!c||!native?.deployMask)return;
  const win=await game.uiwin?.open?.('siegeRenewGuards');if(!win)return;if(epoch!==guardGeneration)return;if(!current()||castle()?.instanceId!==c.instanceId){closeGuards();return;}
  guardWindow=bindSiegeGuardWindow(win,{map:c.map,cfg:native.cfg,mask:native.deployMask,defs:game.data?.monsters?.monsters||{},current:()=>current()&&castle()?.instanceId===c.instanceId,state:castle,funds:()=>network.self?.dil,send:fields=>send('sentry',{npcIndex:id,...fields}),refuse:pair=>nativeError(`siege:${pair[0]}:${pair[1]}`),close:closeGuards});
  if(!guardWindow)closeGuards();
 };
 const openGates=async(npc,id,current)=>{
  dialog.close();if(!current())return;closeGates();const epoch=gateGeneration,c=castle(),native=siegeRenewCastles(bridge.data).find(r=>r.map===c?.map);if(!c||!native)return;
  const result=await send('gate',{npcIndex:id});if(!result?.groups||!current()||epoch!==gateGeneration||castle()?.instanceId!==c.instanceId)return;
  castle().gateUpgrade=result;
  const win=await game.uiwin?.open?.('siegeRenewGates');if(!win||epoch!==gateGeneration)return;if(!current()||castle()?.instanceId!==c.instanceId){closeGates();return;}
  gateWindow=bindSiegeGateWindow(win,{map:c.map,prices:native.upgradePrices,current:()=>current()&&castle()?.instanceId===c.instanceId,state:castle,text:code=>nativeText([410,code]),ask:(text,plan)=>{
    const groups=castle().gateUpgrade.groups.map(group=>{const targetLevel=group.group===plan.group?plan.targetLevel:group.level,defs=renewGateRows(native,bridge.data).filter(row=>row.group===group.group).map(row=>row.def);
      return {...group,targetLevel,hp:defs.reduce((sum,def)=>sum+renewGateHP(def,group.level,native.upgradePrices.length),0),targetHp:defs.reduce((sum,def)=>sum+renewGateHP(def,targetLevel,native.upgradePrices.length),0)};});
    return siegeUpgradeConfirm(game,{groups,price:plan.price},()=>current()&&castle()?.instanceId===c.instanceId&&epoch===gateGeneration);
  },close:closeGates,send:async fields=>{const next=await send('gate',{npcIndex:id,...fields});if(current()&&castle()?.instanceId===c.instanceId&&next?.groups)castle().gateUpgrade=next;return next;}});
 };
 const service=(npc,info)=>{
  if(!active())return false;const id=Number(info?.npcIndex??npcId(npc)),type=Number(info?.jobType),index=Number(info?.jobIndex),map=Number(game.world?.info?.index);
  const isEntrance=[R.entranceJob,R.observerJob].includes(type)&&R.castles.includes(index),isLorenzo=R.castles.includes(map)&&[R.taxJob,R.sentryJob,R.skillJob,R.defenderTeleportJob,R.masterTeleportJob].includes(type);
  if(!isEntrance&&!isLorenzo)return false;
  const current=menuScope(npc);void ready.then(()=>{if(!current()||!authoredJob(id,type,index))return;
   if(type===R.defenderTeleportJob){const c=siegeRenewCastles(bridge.data).find(c=>c.map===map),points=c?.locations.filter(l=>l.type===4&&l.map===map&&l.name)||[];page(npc,points.map(l=>({label:plainText(l.name),pick:()=>pick('stronghold',{npcIndex:id,location:l.index},current)})));return;}
   if(type===R.skillJob){const available=nativeText([100,43]);let text=bridge.data?.txt?.('stringtable_siege.txt',100,42)||'';for(let i=0;i<3;i++){const seconds=Math.max(0,Math.ceil(((castle()?.skillReadyAt?.[i]||0)-serverNow())/1000));text=text.replaceAll(`<REMAINTIME${i}>`,seconds?`${Math.floor(seconds/60)}:${String(seconds%60).padStart(2,'0')}`:available);}void dialog.open(npc,{title:npc.name,text:plainText(text),options:[0,1,2].map(selection=>({label:nativeText([map,101+selection]),pick:()=>pick('skill',{npcIndex:id,selection},current)}))});return;}
   if(type===R.taxJob){const text=label(npc,info);if(text)page(npc,[{label:text,pick:()=>void openTax(npc,id,current)}]);return;}
   if(type===R.sentryJob){page(npc,[{label:label(npc,info),pick:()=>void openGuards(npc,id,current)},{label:nativeText([410,1]),pick:()=>void openGates(npc,id,current)}]);return;}
   if(type===R.observerJob){const text=label(npc,info);if(text)page(npc,[{label:text,pick:()=>{dialog.close();if(current())void game.observer?.choose?.(id,`renew-${index}`);}}]);return;}
   const operation=type===R.entranceJob?'enter':type===R.masterTeleportJob?'castellan':type===R.taxJob?'tax':type===R.sentryJob?'sentry':'skill',text=label(npc,info);
   if(text)page(npc,[{label:text,pick:()=>pick(operation,{npcIndex:id},current)}]);
  });return true;
 };
 const register=()=>{const registry=game.npcServices;if(!registry||registered.has(registry))return;registered.add(registry);for(const job of [21,36,125,126,127,128,129]){const list=registry.handlers?.get(job);if(Array.isArray(list))list.unshift(service);else registry.register?.(job,service);}};register();const off=game.events?.on?.('systems',register);
 const questOpen=npc=>{const c=castle(),id=npcId(npc);if(!c)return false;const operation=id===R.warpStones[c.map]?'warpstone':id===R.jegarr[c.map]?'jegarr':null,quest=operation==='warpstone'?R.warpStoneQuest[c.map]:R.jegarrQuest[c.map];if(!operation)return false;
  const current=menuScope(npc);void ready.then(()=>{if(!current()||!authoredJob(id,1,quest))return;const row=game.data?.quests?.quests?.[quest]??game.quests?.data?.quests?.[quest],text=plainText(row?.title||row?.name||nativeNpc(id)?.name||npc.name||'');if(text)page(npc,[{label:text,pick:()=>pick(operation,{npcIndex:id},current)}]);});return true;
 };
 // A click on the chest sends the claim intent (native trigger index only); the host checks lord/week/position/bag.
 const chestOpen=npc=>{if(!npc||npc!==client.chest)return false;const c=castle(),trigger=c?.chest?.trigger;if(!c||!trigger||npc.disposed)return true;const current=menuScope(npc);void ready.then(()=>{if(current()&&client.chest===npc)void send('chest',{trigger});});return true;};
 const oldOpen=game.windows?.openNpc?.bind(game.windows),open=npc=>chestOpen(npc)||questOpen(npc);if(oldOpen)game.windows.openNpc=npc=>open(npc)?null:oldOpen(npc);
 const previousHostile=game.isPvpHostile,hostile=actor=>{const c=castle();return c?siegePlayerHostile(game,actor,c.foes):!!previousHostile?.(actor);};game.isPvpHostile=hostile;
 const releaseActor=registerEventActors(network,'siege-renew',id=>!disposed&&(client.brick&&client.brick.networkId===id&&!client.brick.disposed?client.brick:gates.actor(id))||null,10);
 const previousCommand=game.chat?.commands?.get('/leavesiege'),command=args=>{if(castle()){void send('leave');return true;}return previousCommand?.fn?.(args)??false;};game.chat?.registerCommand?.('/leavesiege',command,'Leave the current castle siege.');
 const previousSnapshot=network._snapshot.bind(network);network._snapshot=snapshot=>{if(disposed||network.disposed||!snapshot?.self||!Number.isFinite(Number(snapshot.sequence))||Number(snapshot.sequence)<network.sequence){previousSnapshot(snapshot);return;}if(Object.hasOwn(snapshot,'siegeRenew'))latest=snapshot.siegeRenew;previousSnapshot(snapshot);sync();};
 const previousEvent=network._event.bind(network);network._event=event=>{
  if(event?.type==='guardremote'){void guardEffects.event(event).catch(error=>console.warn('[siege] guard effect failed',error));return;}
  if(!disposed&&event?.type==='siegeNotice'&&event.mode==='siegeRenew'){if(event.recipients&&!event.recipients.includes(network.self?.id))return;const key=event.sequence+':'+event.code?.join(':');if(seen.has(key))return;seen.add(key);if(seen.size>256)seen.delete(seen.values().next().value);say(fillText(nativeText(event.code||[]),...(event.args||[])));return;}
  // Forced movement remains owned by the normal authoritative snapshot path.
  previousEvent(event);
 };
 const previousUpdate=bridge.update;bridge.update=dt=>{previousUpdate(dt);if(!disposed){sync();client.brick?.update(dt);gates.update(dt);guardEffects.update(dt);}};
 const previousDispose=bridge.dispose;bridge.dispose=()=>{if(!disposed){disposed=true;off?.();for(const registry of registered)for(const job of [21,36,125,126,127,128,129])registry.unregister?.(job,service);registered.clear();clear();clearChest();closeTimer();seen.clear();client.state=null;if(game.isPvpHostile===hostile)game.isPvpHostile=previousHostile;if(game.chat?.commands?.get('/leavesiege')?.fn===command){if(previousCommand)game.chat.commands.set('/leavesiege',previousCommand);else game.chat.commands.delete('/leavesiege');}}previousDispose();};
 const previousGuardDispose=bridge.dispose;bridge.dispose=()=>{forceAlarm.dispose();releaseActor();closeGuards();closeGates();gates.dispose();guardEffects.dispose();previousGuardDispose();};
 client.service=service;client.ready=ready;client.action=send;client.openNpc=open;return client;
}
