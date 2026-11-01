import fs from 'node:fs/promises';import path from 'node:path';import {randomUUID} from 'node:crypto';
import {Director} from '../../src/systems/dungeons/director.js';
import {D,startPos,FOREIGN_KEEPERS} from '../../src/systems/dungeons/data.js';
import {planFor} from '../../src/systems/dungeons/scripts.js';
import {footprintCells} from '../../src/systems/dungeons/bricks.js';
import {createInstance,exitInstance,stageInstanceMembers,requestInstanceClose} from './instances.mjs';import {sameScene,sceneKey} from './scene.mjs';
import {eventEntryMembers} from './events.mjs';import {EXPEDITION_MAX} from './expedition.mjs';import {AuthoritativeInventory} from './inventory.mjs';
import {Trigger} from '../../src/systems/dungeons/triggers.js';
import {pickRewardSlot} from '../../src/systems/dungeons/reward-slot.js';
import {rollMonsterDrops} from '../../src/game/loot.js';
import {partyLootOwner} from './party.mjs';
import {premiumDungeonFee} from './premium-fees.mjs';
import {dungeonEntranceCosts,consumeDungeonRequirements} from './dungeon-admission-rules.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {questClear} from './quests.mjs';import {scaledReward} from './rates.mjs';
import {queueInstanceProgress,retryInstanceProgress,flushInstanceProgress} from './instance-progress.mjs';
import {isCustomScene,nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {dungeonGatePlacement} from '../../src/config/engine-chosen-karin-dungeon-gates.js';
import {assertUrbanWarfareAdmissionAvailable} from './urban-warfare.mjs';
import {phantomCastleCommand} from './phantom-castle.mjs';
import {earnDungeonClearTitle,refreshTitleStats} from './titles.mjs';import {trackFullClearTitle} from './full-clear-title.mjs';
// Staged server adapter. Core/API wiring is intentionally separate until its original-data tests pass.
import {OBSERVER_SCHEMAS,observerCommand} from './observer.mjs';
import {ARENA_SCHEMAS} from './arena-schema.mjs';
import {deadIslandCommand} from './dead-island.mjs';
import {arenaCommand,tickArena} from './arena.mjs';
// ARENA (npc jobs 130 / 111 battlefields) rides the same dispatch ({arenaResult}) and tick: server/world/arena.mjs.
// OBSERVER (npc job 40) rides this dispatch so its {observerResult} reaches the client: server/world/observer.mjs.
export const DUNGEON_SCHEMAS={dungeon:['token','type','operation','dungeonId','npc','path','trigger','gateId'],...OBSERVER_SCHEMAS,...ARENA_SCHEMAS};
const fail=(text,status=400)=>{throw Object.assign(Error(text),{status});};
export async function loadDungeonData(root){const read=async name=>JSON.parse(await fs.readFile(path.join(root,name+'.json'),'utf8'));const[dg,tr,dialogs,effects]=await Promise.all(['dungeons','dungeons_travel','dialogs','dungeons_uifx'].map(read));return {dg,tr,dialogs,effects};}
function catalog(world){const c=world.data.dungeonData;if(!c)fail('Dungeon tables are unavailable.',503);D.dg=c.dg;D.tr=c.tr;D.ready=true;return c;}
function members(world,i){return [...world.players.values()].filter(p=>!p.leaving&&p.instanceId===i.id);}
function activeInteraction(world,p,i,director){if(world.players.get(p.account)!==p||p.leaving||p.dead||p.instanceId!==i.id||p.map!==i.map||i.director!==director||director.disposed||i.floorTransition||i.closeRequested)fail('This dungeon interaction is no longer available.',409);}
function validate(world,p,input){const c=catalog(world),id=String(input.dungeonId),d=c.dg.dungeons[id];if(!d||id.startsWith('m')||d.missingFloors?.length||!d.floors?.length||!d.floors.every(m=>c.dg.maps[m]?.files?.map))fail('The original client does not contain every floor of this dungeon.');const f=c.dg.maps[d.floors[0]];if(FOREIGN_KEEPERS.has(d.keeper)||d.keeper==='PARTYMATCH'||d.keeper==='GUILD'||d.keeper==='SQUARE'||d.solo?.pvpOnly||f.flags?.siege)fail('Use the dedicated event or PvP admission for this dungeon.');
 for(const map of d.floors)assertUrbanWarfareAdmissionAvailable(world,map);
 const custom=isCustomScene(world,p.map),placed=d.entry?.npcs?.find(n=>Number(n.npc)===input.npc&&(custom||Number(n.map)===p.map)),fallback=d.entry?.fallback;
 const fallbackAllowed=!custom&&fallback&&Number(fallback.map)===p.map&&(!input.npc||input.npc===4001||d.entry.unplacedNpcs?.some(n=>Number(n.npc)===input.npc));
 const authored=custom&&nearbyNpc(world,p,{npcIndex:input.npc,radius:10});
 const supported=authored&&[19,45,58,34].some(type=>offersOriginalJob(world,authored,type,Number(id)));
 const at=custom?(supported?{x:authored.x,y:authored.z}:null):placed||fallbackAllowed&&dungeonGatePlacement(fallback,id);
 if(!at||Math.hypot(p.x-Number(at.x),p.z-Number(at.y))>10)fail('Walk to the original dungeon entrance.');
 const troop=d.keeper==='TROOP',solo=d.keeper==='SOLO',group=eventEntryMembers(world,p),min=solo?1:Number(d.party?.min)||1,max=solo?1:troop?EXPEDITION_MAX:Number(d.party?.max)||7;if(min>max)fail('This original dungeon requires a larger group than the supported maximum.');if(group.length<min||group.length>max)fail(`This original dungeon needs ${min}–${max} connected ${troop?'expedition':'party'} members.`);const[lo,hi]=d.entry.levels||[0,0],{fee,requirements}=dungeonEntranceCosts(world,id,input.npc);
 const profiles=group.map(member=>{if(member.dead||member.instanceId||!sameScene(member,p)||Math.hypot(member.x-p.x,member.z-p.z)>20)fail('Gather the living party at the entrance.');if(member.profile.level<lo||hi>=lo&&hi>0&&member.profile.level>hi)fail('Every member must meet the original dungeon level range.');if(member.mount&&!d.entry.vehicle)fail('Dismiss mounts before entering this dungeon.');const profile=structuredClone(member.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});if(!consumeDungeonRequirements(inv,requirements,{first:member===p}))fail(member===p&&requirements.some(r=>r.payer==='first')?'The first player to enter needs the original admission ticket or entry item.':'Every member needs the original admission ticket or entry item.');const chargedFee=premiumDungeonFee(world,profile,fee);if(inv.dil<chargedFee)fail('Every member needs the original entrance fee.');inv.addDil(-chargedFee);return profile;});return {id,d,group,profiles};}
export async function dispatchDungeon(world,p,input){if(input.type==='observer')return observerCommand(world,p,input);if(input.type==='arena')return arenaCommand(world,p,input);if(input.type!=='dungeon')return false;
 if(input.operation==='frontier-ticket'||input.operation==='enter'&&String(input.dungeonId)==='551')return deadIslandCommand(world,p,input);
 if(['phantom-info','phantom-ticket','phantom-enter'].includes(input.operation))return phantomCastleCommand(world,p,input);
 if(input.operation==='enter'){
  const{id,d,group,profiles}=validate(world,p,input);let i;for(const q of group)q.sceneTransition=true;
  const staged=stageInstanceMembers(world,group,profiles);
  try{const exit=d.exit?.to?.[0]||{map:p.map,x:p.x-.5,y:p.z-.5};i=await createInstance(staged.world,{map:Number(d.floors[0]),members:staged.candidates,kind:'dungeon',exit:{map:Number(exit.map),x:Number(exit.x)+.5,z:Number(exit.y)+.5},durationMs:Math.max(600000,(Number(d.expireTime)||60)*60000)});i.admitting=true;await prepareDungeon(staged.world,i,id,0,staged.candidates[0]);const current=eventEntryMembers(world,p);if(current.length!==group.length||current.some(q=>!group.includes(q)||world.players.get(q.account)!==q))fail('Party membership changed. Choose entry again.',409);for(const q of staged.candidates)progressDekaPass(staged.world,q,2,16,i.map,1);await world.persistMany(staged.candidates);await staged.commit();i.acting=p;i.admitting=false;}
  catch(error){if(i){i.director?.dispose();world.instances.delete(i.id);world.maps.delete(sceneKey(i.map,i.id));}throw error;}
  finally{for(const q of group)q.sceneTransition=false;}return true;
 }
 const i=world.instances?.get(p.instanceId);if(!i?.director)fail('You are not inside a dungeon.');if(input.operation==='exit'){await exitInstance(world,p);return true;}
 if(input.operation==='warp'){
  activeInteraction(world,p,i,i.director);
  if(!Number.isSafeInteger(input.gateId))fail('Choose an original dungeon portal.');
  const c=catalog(world),gate=c.tr.warps?.find(w=>w.id===input.gateId&&w.kind==='zone'&&w.dungeon&&!w.siege&&w.box&&Number(w.fromMap)===i.map&&Number(w.toMap)===i.map);
  const target=gate&&c.tr.locations?.[String(gate.to)];
  if(!target||Number(target[0])!==i.map)fail('Choose a portal in this dungeon.');
  const [left,top,right,bottom]=gate.box,dx=Math.max(left-p.x,0,p.x-(right+1)),dz=Math.max(top-p.z,0,p.z-(bottom+1));
  if(Math.hypot(dx,dz)>2.5)fail('Walk into the original dungeon portal.');
  const at=i.scene.nearest(Number(target[1])+.5,Number(target[2])+.5);
  if(!at)fail('No safe dungeon portal arrival is available.');
  p.x=at.x;p.z=at.z;p.path=[];p.attackTarget=null;world.changed(p);await world.persist(p);return true;
 }
 if(input.operation==='trigger'){const director=i.director,t=director.triggers.find(t=>t.uid===input.trigger);if(!t||Math.hypot(p.x-t.x,p.z-t.z)>3)fail('Walk to the original dungeon object.');const previous=i.interactionQueue||Promise.resolve();let release;i.interactionQueue=new Promise(resolve=>release=resolve);await previous.catch(()=>{});try{activeInteraction(world,p,i,director);if(Math.hypot(p.x-t.x,p.z-t.z)>3)fail('Walk to the original dungeon object.');i.acting=p;await director.useTrigger(t);await world.persist(p);return true;}finally{release();}}if(input.operation!=='npc'||!Number.isInteger(input.npc)||!Array.isArray(input.path)||input.path.length>4||input.path.some(n=>!Number.isInteger(n)||n<0||n>20))fail('Choose an original dungeon NPC interaction.');
 const director=i.director,sn=director.scriptNpc(input.npc);if(!sn||Math.hypot(p.x-sn.x,p.z-sn.y)>8)fail('Walk to that original dungeon NPC.');const previous=i.interactionQueue||Promise.resolve();let release;i.interactionQueue=new Promise(resolve=>release=resolve);await previous.catch(()=>{});try{activeInteraction(world,p,i,director);if(Math.hypot(p.x-sn.x,p.z-sn.y)>8)fail('Walk to that original dungeon NPC.');i.acting=p;director.talk({npcIndex:input.npc,name:sn.name,x:sn.x,z:sn.y});let page=i.dialog;for(const index of input.path){const option=page?.menu?.[index];if(!option)fail('Choose a current dialogue option.');i.dialog=null;await option.onClick();if(i.pendingTransfer)await i.pendingTransfer;page=i.dialog;}await world.persist(p);return {dialog:{npc:input.npc,text:page?.text||'',options:(page?.menu||[]).map(o=>({label:o.text}))}};}finally{release();}
}
function emit(world,i,event){const record={...event,instanceId:i.id};if(i.stageEvents){i.stageEvents.push([i.map,record]);return;}world.emit(i.map,record);}
function recordDungeonResult(world,i,id,floor,keeper,won,elapsed,event){
 // TITLES: a clear-condition title (20 Solo Champion = the solo Colosseum Arena) is granted in this same durable transaction.
 const map=i.map,clear={dungeonId:id,keeper,lastFloor:floor===(world.data.dungeonData?.dg?.dungeons?.[id]?.floors?.length||1)-1,members:members(world,i).length},titled=new Set();
 queueInstanceProgress(world,i,`dungeon:${i.id}:${floor}:result`,(p,facade)=>{
  const st=p.profile.dungeonRecords||={},key=`${id}:${floor}`,old=st[key]||{};
  st[key]={clears:(old.clears||0)+(won?1:0),failures:(old.failures||0)+(won?0:1),bestSeconds:won?Math.min(Number.isFinite(old.bestSeconds)?old.bestSeconds:Infinity,elapsed):old.bestSeconds??null};
  if(won){questClear(facade,p,map,{profile:p.profile});progressDekaPass(facade,p,2,12,map,1);progressDekaPass(facade,p,2,keeper==='SOLO'?13:keeper==='TROOP'?15:14,map,1);if(earnDungeonClearTitle(facade,p,clear))titled.add(p.id);}
 },()=>{for(const q of world.players.values())if(titled.has(q.id)&&!q.leaving)refreshTitleStats(world,q);emit(world,i,{type:won?'dungeon:clear':'dungeon:fail',...event});});
}
export async function prepareDungeon(world,i,id,floor,leader){catalog(world);i.acting=leader;i.dungeonId=id;i.floor=floor;i.channels=[];const scene=i.scene,records=[],dialogs={open:p=>i.dialog=p,push:p=>i.dialog=p,close:()=>i.dialog=null,gauge:(text,ms,{sound=null}={})=>{
 const p=i.acting,director=i.director,phase=director.phase,map=i.map,channelId=randomUUID(),startedAt=world.now(),durationMs=Math.max(300,Number(ms)||1000),endAt=startedAt+durationMs,origin={x:p.x,z:p.z},hitRevision=p.hitRevision||0;
 const scope={id:i.id,map,stageEvents:i.stageEvents},send=event=>emit(world,scope,{...event,actorId:p.id,channelId,channelKind:'dungeon',recipients:[p.id]});
 const valid=()=>!world.shuttingDown&&world.instances?.get(i.id)===i&&i.director===director&&!director.disposed&&!i.closeRequested&&director.phase===phase&&i.map===map&&i.floor===floor&&world.players.get(p.account)===p&&!p.leaving&&!p.dead&&p.instanceId===i.id&&p.map===map&&(p.hitRevision||0)===hitRevision&&Math.hypot(p.x-origin.x,p.z-origin.z)<=.1;
 if(!valid())return Promise.resolve(false);
 const cue=Array.isArray(sound)&&sound.length===4&&sound.every(Number.isSafeInteger)?sound.slice():null;
 let channel,timer;
 return new Promise(resolve=>{
  let done=false;channel={p,x:origin.x,z:origin.z,end:endAt,resolve(ok){if(done)return;done=true;clearInterval(timer);i.channels=i.channels.filter(c=>c!==channel);resolve(!!ok&&world.now()>=endAt&&valid());}};
  i.channels.push(channel);
  send({type:'event:channel',text:String(text),durationMs,startedAt,endAt,sound:cue,soundEvent:'dungeon:sound'});
  if(cue)send({type:'dungeon:sound',sound:cue,startedAt,endAt,origin});
  // Invalid instances can be skipped/removed by the world tick. Resolve their
  // waiting dialog without advancing an objective or completing by wall time.
  timer=setInterval(()=>{if(!valid())channel.resolve(false);},50);timer.unref?.();
 }).then(ok=>{
  const completed=!!ok&&valid();send({type:'event:channel-end',completed});if(cue)send({type:'dungeon:sound-stop',completed});return completed;
 });
}};
 const game={settings:{dropRate:world.rates.drop,moneyRate:world.rates.dil},time:world.now()/1000,data:{monster:n=>world.data.monsterDef(n),monsters:world.data.progression?.monsters},world:{info:{index:i.map},collision:scene.collision,isWalkable:scene.isWalkable,findPath:scene.path,nearestWalkable:scene.nearest},npcs:(world.data.dungeonData.dg.maps[i.map]?.scriptNpcs||[]).map(n=>({npcIndex:n.npc,x:n.x,z:n.y,name:n.name})),events:{emit(kind,event){if(kind==='dungeon:clear'||kind==='dungeon:fail')recordDungeonResult(world,i,id,floor,i.director.dungeon.keeper,kind==='dungeon:clear',i.director.elapsed,event);},on(){return()=>{}},off(){}},travel:async(map,point)=>{if(map!==i.map)fail('Use the original floor transition.');for(const p of members(world,i)){const at=scene.nearest(point.x,point.z);if(at){p.x=at.x;p.z=at.z;p.path=[];world.changed(p);}}}};
 Object.defineProperty(game,'player',{get:()=>i.acting});Object.defineProperty(game,'save',{get:()=>i.acting.profile});
 const spawn=rec=>{if(rec.skip||rec.monster)return;const def=world.data.monsterDef(rec.spawn.monsterIndex);if(!def||def.role==='invisible'){rec.skip=true;if(rec.dg)rec.dg.killed=true;return;}const point=scene.nearest(rec.spawn.x,rec.spawn.z);if(!point)fail('No safe original dungeon monster spawn exists.',503);const m={id:`dungeon:${i.id}:${randomUUID()}`,map:i.map,instanceId:i.id,monsterIndex:rec.spawn.monsterIndex,name:def.name,...point,hp:def.hp,maxHp:def.hp,home:{...point},dead:false,targetId:null,attackAt:0,respawnSec:Infinity,respawnAt:Infinity,def,kind:'monster',spawnRecord:rec,setPosition(x,z){this.x=x;this.z=z;},play(){}};rec.monster=m;scene.monsters.set(m.id,m);};
 for(const m of scene.monsters.values()){m.kind='monster';m.respawnSec=Infinity;m.respawnAt=Infinity;const rec={id:m.id,spawn:{monsterIndex:m.monsterIndex,x:m.x,z:m.z},monster:m,respawnSec:Infinity};m.spawnRecord=rec;records.push(rec);}
 const push=records.push.bind(records);records.push=(...rows)=>{for(const rec of rows){push(rec);spawn(rec);}return records.length;};game.spawner={records,get monsters(){return [...scene.monsters.values()]},near:(x,z,r)=>[...scene.monsters.values()].filter(m=>!m.dead&&Math.hypot(m.x-x,m.z-z)<r)};
 const grantExp=amount=>{if(!Number.isFinite(amount)||amount<=0)return;const key=`dungeon:${i.id}:${floor}:exp:${i.expRewardId=(i.expRewardId||0)+1}`;queueInstanceProgress(world,i,key,(p,facade)=>world.grantProgress.call(facade,p,scaledReward(amount,world.rates.exp),0));};
 const sys={game,dialog:dialogs,ui:new Proxy({},{get:()=>()=>{}}),uifx:{play(id,ms){emit(world,i,{type:'dungeon:effect',effect:id,durationMs:ms});},info:async id=>world.data.dungeonData.effects?.effects?.[id]||null},notice:text=>emit(world,i,{type:'event:message',text:String(text)}),playEffectSound(sound){emit(world,i,{type:'dungeon:sound',sound});},playJingle(sound){emit(world,i,{type:'dungeon:jingle',sound});},grantExp,rollRewardList(list){const slot=pickRewardSlot(list,world.random);if(slot)drop({kind:'item',itemIndex:slot[0],count:slot[1]},i.acting.x,i.acting.z);},recordRun(){},leave:(_director,reason)=>{
  i.pendingTransfer=['transfer','fail'].includes(reason)?requestInstanceClose(world,i)||Promise.resolve():exitInstance(world,i.acting);
  void i.pendingTransfer.catch(error=>{i.saveError=error.message;});return i.pendingTransfer;
 },enterFloor:(_,next)=>{i.pendingTransfer=transferFloor(world,i,id,next);void i.pendingTransfer.catch(error=>{i.saveError=error.message;});return i.pendingTransfer;}};
 const director=new Director(sys,{map:i.map,dungeonId:id,floor});i.director=director;i.game=game;i.scene.baseMask=new Uint8Array(scene.collision.cells);i.scene.brickCounts=new Map();
 director._createBrick=async(pl,closing)=>{const def=D.dg.bricks[pl.brick];if(!def)return null;const cells=footprintCells(game.world,pl.x,pl.y,pl.dir,def.size);const b={id:`brick:${i.id}:${pl.uid}`,uid:pl.uid,place:pl,brick:def,brickDef:def,isBrick:true,objectFootprint:cells,breakable:def.role==='breakable',map:i.map,instanceId:i.id,name:def.name,kind:def.role==='breakable'?'monster':'brick',x:pl.x,z:pl.y,hp:Number(def.hp0||def.hp)||1,maxHp:Number(def.hp)||1,dead:false,open:false,def:{index:-1,exp:def.exp||0,def:def.def||[0,0],money:def.money||[0,0,0],drops:{sets:(def.drops||[]).map(([set,ratio])=>[set,ratio,0])},ai:{aggressive:false},speed:[0,0]},respawnSec:Infinity,respawnAt:Infinity,home:{x:pl.x,z:pl.y},play(){},dispose(){this.unblock();this.disposed=true;},block(){if(!this.unblocked||this.open||this.dead||this.disposed)return;this.unblocked=false;for(const{i:cell}of cells){scene.brickCounts.set(cell,(scene.brickCounts.get(cell)||0)+1);scene.collision.cells[cell]=1;}},unblock(){if(this.unblocked)return;this.unblocked=true;for(const{i:cell}of cells){const n=Math.max(0,(scene.brickCounts.get(cell)||1)-1);scene.brickCounts.set(cell,n);scene.collision.cells[cell]=n?1:scene.baseMask[cell];}},openGate(){if(this.breakable||this.open)return false;this.open=true;this.unblock();return true;},destroyed(){this.dead=true;this.unblock();}};for(const{i:cell}of cells){scene.brickCounts.set(cell,(scene.brickCounts.get(cell)||0)+1);scene.collision.cells[cell]=1;}director.bricks.push(b);director.brickByUid.set(pl.uid,b);game.npcs.push(b);if(b.breakable)scene.monsters.set(b.id,b);return b;};
 const drop=(entry,x,z)=>{if(entry.kind==='item'&&!world.data.itemDB.def(entry.itemIndex))return;if(entry.kind==='dil')entry.amount=scaledReward(entry.amount,world.rates.dil);const ownership=partyLootOwner(world,i.acting,{x,z}),owner=ownership.player||i.acting;world.groundLoot||=new Map();const uid=randomUUID();world.groundLoot.set(uid,{id:uid,map:i.map,instanceId:i.id,x,z,entry,ownerId:owner.id,protectedUntil:ownership.free?0:world.now()+30000,expiresAt:world.now()+180000});};
 director._buildTriggers=()=>{for(const[uid,pl]of (director.info.triggers||[]).entries()){const def=D.dg.triggers[pl.trigger];if(!def)continue;const t={uid:`trigger:${i.map}:${uid}`,trig:def,place:pl,x:pl.x,z:pl.y,name:def.name,tstate:1,busy:false,locked:false,opened:false,group:{visible:true},play(){},get stateDef(){return this.trig.states?.[this.tstate-1]||null;},get clickable(){return !!this.stateDef?.clickable&&!this.busy&&!this.locked&&!this.opened;},advance:Trigger.prototype.advance};t.drop=D.dg.triggerDrops?.[pl.drop||`${i.map}:${pl.trigger}`]||null;if(t.drop&&!/^click$/i.test(t.drop.cond||'Click'))t.locked=true;director.triggers.push(t);game.npcs.push(t);}};
 director._dropTrigger=t=>{if(t.rewarded)return;t.rewarded=true;const reward=t.drop,def={drops:{money:reward.money?[reward.money]:[],sets:reward.sets||[],fixed:reward.fixed||[],fixedSets:reward.fixedSets||[],maxSets:reward.maxItemSet||1}};for(const entry of rollMonsterDrops(def,world.data.progression?.monsters,{rng:world.random,itemRate:world.rates.drop,moneyRate:1}))drop(entry,t.x,t.z);};
 const at=startPos(i.map)||{x:leader.x,z:leader.z},safe=scene.nearest(at.x,at.z);if(!safe)fail('No safe dungeon floor start is available.',503);for(const p of members(world,i)){p.x=safe.x;p.z=safe.z;p.path=[];world.changed(p);}
 await director.start(planFor(i.map,director));i.run={end:()=>director.dispose(),get ended(){return director.disposed;}};return director;
}
async function transferFloor(world,i,id,floor){
 const d=world.data.dungeonData.dg.dungeons[id],map=Number(d.floors[floor]);if(i.floorTransition)fail('A dungeon floor transition is already in progress.');
 if(!Number.isInteger(map)||floor!==i.floor+1||i.director.phase!=='cleared')fail('Clear the current original floor before taking the next stairs.');
 i.transitionSnapshot=dungeonSnapshot(world,i.acting);i.floorTransition=true;
 try{await flushInstanceProgress(world,i.acting,i,{allowFloorTransition:true});}catch(error){i.floorTransition=false;delete i.transitionSnapshot;throw error;}
 const group=members(world,i),previous=i.map,before={...i},keys=['profile','map','x','z','path','mount','pet','dirty','revision','saveError','sceneTransition'],states=group.map(p=>Object.fromEntries(keys.map(key=>[key,p[key]])));
 for(const p of group)p.sceneTransition=true;
 try{
  const scene=await world.map(map,i.id);i.map=map;i.scene=scene;i.stageEvents=[];
  const candidates=group.map(p=>({...p,map,path:[],mount:null,pet:null,profile:structuredClone(p.profile)}));
  for(const p of candidates){p.profile.instance.map=map;world.changed(p);}
  const stagedPlayers=new Map(world.players);for(const p of candidates)stagedPlayers.set(p.account,p);
  let staging=true;const facade=new Proxy(world,{get(target,key,receiver){return key==='players'&&staging?stagedPlayers:Reflect.get(target,key,receiver);}});
  await prepareDungeon(facade,i,id,floor,candidates[0]);await world.persistMany(candidates);
  staging=false;
  group.forEach((p,index)=>{for(const key of keys)if(key!=='sceneTransition')p[key]=candidates[index][key];});i.acting=group[0];
  const staged=i.stageEvents;delete i.stageEvents;before.director.dispose();world.maps.delete(sceneKey(previous,i.id));
  for(const p of group){world.emit(previous,{type:'leave',actorId:p.id,instanceId:i.id});world.emit(map,{type:'join',actorId:p.id,instanceId:i.id});}
  for(const[sceneIndex,event]of staged)world.emit(sceneIndex,event);
 }catch(error){
  if(i.director!==before.director)i.director.dispose();world.maps.delete(sceneKey(map,i.id));
  for(const key of Object.keys(i))if(!Object.hasOwn(before,key))delete i[key];Object.assign(i,before);
  group.forEach((p,index)=>{Object.assign(p,states[index]);world.changed(p);});throw error;
 }finally{i.floorTransition=false;delete i.transitionSnapshot;group.forEach((p,index)=>p.sceneTransition=states[index].sceneTransition||false);}
}
export function tickDungeons(world,dt){void tickArena(world).catch(()=>{});for(const i of world.instances?.values()||[]){try{retryInstanceProgress(world,i);if(i.faulted){if(members(world,i).length)void requestInstanceClose(world,i)?.catch?.(()=>{});continue;}if(i.admitting||i.progressSave||i.floorTransition||i.closeRequested||!i.director||i.director.disposed)continue;if(!i.acting||world.players.get(i.acting.account)!==i.acting||i.acting.leaving)i.acting=members(world,i)[0];if(!i.acting)continue;i.game.time=world.now()/1000;for(const channel of [...i.channels])if(world.now()>=channel.end||channel.p.dead||channel.p.leaving||channel.p.instanceId!==i.id||Math.hypot(channel.p.x-channel.x,channel.p.z-channel.z)>.1){i.channels=i.channels.filter(c=>c!==channel);channel.resolve(!channel.p.dead&&!channel.p.leaving&&channel.p.instanceId===i.id&&Math.hypot(channel.p.x-channel.x,channel.p.z-channel.z)<=.1);}for(const m of i.scene.monsters.values())if(m.dead&&!m._dungeonCounted){m._dungeonCounted=true;i.director.onDeath(m);}i.director.update(dt);trackFullClearTitle(world,i);}catch(error){dungeonFault(world,i,error);}}}
// capacity-test.mjs --dungeon all: one dungeon's script failing (e.g. 'No safe original dungeon monster spawn
// exists.') threw out of the world tick and stopped the whole server for every player. Now only that instance stops: it is
// logged once and its players are returned to the dungeon exit through the normal durable close (progress saved).
function dungeonFault(world,i,error){if(i.faulted)return;i.faulted=true;console.error('[dungeons] instance stopped:',i.dungeonId,'map',i.map,'-',error?.message||error);try{requestInstanceClose(world,i);}catch(closeError){console.error('[dungeons] instance close failed:',closeError?.message||closeError);}}
export function dungeonSnapshot(world,p){const i=world.instances?.get(p.instanceId),d=i?.director;if(i?.floorTransition&&i.transitionSnapshot)return i.transitionSnapshot;return d?{id:i.id,map:i.map,kind:'dungeon',name:d.name,dungeonId:i.dungeonId,floor:i.floor,phase:d.phase,remainingMs:Math.max(0,(d.phase==='countdown'?d.countdown:d.phase==='cleared'?d.transfer:d.phase==='failed'?d.closing:d.limit-d.elapsed)*1000),saveError:i.saveError||null,missions:d.missions,...(d.dungeon?.keeper==='SOLO'?{remainingMonsters:[...i.scene.monsters.values()].filter(m=>!m.dead&&!m.isBrick&&m.def?.role!=='invisible').length}:{}),triggers:d.triggers.map(t=>({uid:t.uid,trigger:t.place.trigger,x:t.x,z:t.z,dir:t.place.dir,tstate:t.tstate,opened:t.opened,locked:t.locked})),bricks:d.bricks.map(b=>({uid:b.uid,brick:b.place.brick,x:b.x,z:b.z,dir:b.place.dir,hp:b.hp,maxHp:b.maxHp,removed:b.open||b.dead,animation:b.dead?'die':'open'})),cooperative:true}:null;}
