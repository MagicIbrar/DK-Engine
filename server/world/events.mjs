import {randomUUID} from 'node:crypto';
import {DeadFrontRun} from '../../src/systems/events/deadfront.js';
import {validateNpcEventAdmission} from './npc-event-admission.mjs';
import {npcEventWindow} from './npc-event-parties.mjs';
import {IceCastleRun} from '../../src/systems/events/icecastle.js';
import {eventBrickFootprintCells,isBreakable} from '../../src/systems/events/bricks.js';
import {fill,plain} from '../../src/systems/events/text.js';
import {AuthoritativeInventory} from './inventory.mjs';
import {createInstance,exitInstance,stageInstanceMembers,requestInstanceClose} from './instances.mjs';
import {mapFor,sameScene} from './scene.mjs';
import {isCustomScene,nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {queueInstanceProgress,retryInstanceProgress} from './instance-progress.mjs';
import {questClear} from './quests.mjs';
import {progressDekaPass} from './dekapass.mjs';
import {scaledReward} from './rates.mjs';
import {isEventObject} from './event-object-combat.mjs';
import {expeditionMembers} from './expedition.mjs';
import {installPartyWar,joinableWar,joinWarTeam,removeTeam,lastHitter,partyWarSnapshot,teamOf} from './party-war.mjs';
// Lane 59 (d): Dead Front script ops on the host (Op1034 / Op1c20 / Op1c28 / Op101ae / level-up gifts)
import {installDeadFrontHost} from './dead-front-host.mjs';
import {selectTitle,tickTitles,titleSnapshot} from './titles.mjs';
import {partyWarWindow,partyWarLobbyTimer} from '../../src/systems/events/partywar-clock.js';
import {serverDate,serverTimestamp,SERVER_TIME} from '../../src/game/server-time.js';
import {tickFieldBoss} from './field-boss.mjs';
// EVENT-MODES: operations titles / title (server/world/titles.mjs). Race removed (Lane 68): Global's client has no race feature;
// old clients sending race-info / race-entry / race-leave get the normal unknown-operation refusal below.
export const EVENT_SCHEMAS={event:['token','type','operation','map','npc','path','title']};
const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
// Global client dialogs describe a four-person party minimum. The host accepts a solo entrant by user request,
// while preserving original field level bands, admission items, officer placement, and team capacity.
const EVENT_MAX_PARTIES=4;
export const eventWindow=(world,mode)=>{
 const now=world.now(),override=world.eventOverrides?.get(mode);
 if(override&&now>=override.register&&now<override.end)return {...override,phase:now<override.closed?'register':now<override.enter?'selection':'enter'};
 // Existing controlled fixtures inject an explicit phase without using GM commands.
 if(override?.phase&&!Number.isFinite(override.end))return override;
 return npcEventWindow(world.data.eventData.modes?.[mode],now);
};
// Public clock cues for shared clients. Keep the host's clock authoritative: a
// client may load late, have the wrong local time, or be in another map.
export function partyWarAnnouncements(world,now=world.now()){
 const due=[],date=serverDate(now);
 for(const mode of ['deadFront','iceCastle']){
  const table=world.data.eventData?.modes?.[mode],cfg=table?.config;if(!cfg)continue;
  const add=(cycle,at,cate,code)=>{if(Number.isFinite(at)&&now>=at&&now-at<60000)due.push({mode,cycle,at,cate,code});};
  const override=world.eventOverrides?.get(mode);
  if(override&&Number.isFinite(override.end)&&now<override.end){
   const cycle=override.cycle;
   add(cycle,override.register,100,101);
   add(cycle,override.closed-(Number(cfg.RecordEndTime)-Number(cfg.RecordBeforeEnd))*1000,100,102);
   add(cycle,override.closed,100,103);
   add(cycle,override.enter,200,7);
   add(cycle,override.enter+(Number(cfg.BattleBefor3M)-Number(cfg.ChooseTime))*1000,200,100);
   add(cycle,override.enter+(Number(cfg.BattleBefor1M)-Number(cfg.ChooseTime))*1000,200,101);
   add(cycle,override.enter+(Number(cfg.BattleBefor30S)-Number(cfg.ChooseTime))*1000,200,102);
   continue;
  }
  // config.csv column -> partywar string: the same column-name/arithmetic pairing as the first five cues. Round 3 adds
  // RecordBeforeEnd 1560 -> 100:102 "1 minute left ... application ends" (1620-1560 = 60 s), RecordEndTime 1620 ->
  // 100:103 "application has ended", BattleBefor30S 1770 -> 200:102 "30 seconds remaining" (1800-1770 = 30 s).
  for(const shift of [-1,0,1])for(const row of table.schedule||[]){
   const match=/^(\d{1,2}):(\d{2})$/.exec(row.cycleStart||'');if(!match||+match[1]>23||+match[2]>59)continue;
   const cycle=serverTimestamp(date.getUTCFullYear(),date.getUTCMonth(),date.getUTCDate()+shift,+match[1],+match[2]);
   for(const [offset,cate,code] of [[cfg.RecordBefore,100,100],[cfg.RecordTime,100,101],[cfg.RecordBeforeEnd,100,102],[cfg.RecordEndTime,100,103],[cfg.ChooseTime,200,7],[cfg.BattleBefor3M,200,100],[cfg.BattleBefor1M,200,101],[cfg.BattleBefor30S,200,102]])
    if(offset!=null)add(cycle,cycle+Number(offset)*1000,cate,code);
  }
 }
 return due;
}
const applicantKey=(world,p)=>p.partyId&&world.parties?.has(p.partyId)?`party:${p.partyId}`:`solo:${p.id}`;
// Only a lobby visitor or a current applicant needs this separate popup.
// Inside an instance, its own phase timer replaces the application clock.
export function partyWarLobbySnapshot(world,p,now=world.now()){
 if(!p||p.instanceId)return null;
 const data=world.data.eventData;
 for(const mode of ['deadFront','iceCastle']){
  const table=data?.modes?.[mode];if(!table)continue;
  const lobbyWindow=()=>eventWindow(world,mode)||partyWarWindow(table,now,{upcoming:true});
  const window=world.broadcastMemo?world.broadcastMemo(`partyWarLobbyWindow:${mode}:${now}`,lobbyWindow):lobbyWindow();
  const here=table.lobbies?.some(map=>Number(map)===Number(p.map));
  const applied=window&&[...(world.eventApplications||[])].some(([key,rows])=>key.startsWith(`${mode}:`)&&key.endsWith(`:${window.cycle}`)&&rows.some(row=>row.applicant===applicantKey(world,p)));
  if(!here&&!applied)continue;
  const timer=partyWarLobbyTimer(mode,window,now);
  if(timer)return {...timer,map:Number(p.map),...(applied&&timer.phase==='enter'?{selection:partyWarSelectionCue(world,p,mode,window,now)}:{})};
 }
 return null;
}
// Lane 59: the selection result at ChooseTime, partywar 100:105 "You have been selected to join ..." / 100:106 "You were
// not selected ..." (@<effectui>2045/2046, both partywar tables), told once to each applicant in the first minute of
// the entry window (the same 60 s host-cue window as partyWarAnnouncements). Selected = within the field's entry
// capacity, the same rule the enter command applies; the record cap (Global 100:3) keeps every applicant within it.
function partyWarSelectionCue(world,p,mode,window,now){
 if(!window||!Number.isFinite(window.enter)||now<window.enter||now-window.enter>=60000)return null;
 const applicant=applicantKey(world,p);
 for(const[key,rows]of world.eventApplications||[]){
  if(!key.startsWith(`${mode}:`)||!key.endsWith(`:${window.cycle}`))continue;
  const index=rows.findIndex(row=>row.applicant===applicant);if(index<0)continue;
  const map=Number(key.split(':')[1]),field=world.data.eventData?.field(mode,map),capacity=Math.min(EVENT_MAX_PARTIES,Number(field?.maxParties)||EVENT_MAX_PARTIES);
  return {mode,cycle:window.cycle,at:window.enter,cate:100,code:index<capacity?105:106};
 }
 return null;
}
export async function gmPartyWarControl(world,content,state){
 const name=String(content?.raw?.name||content?.name||content||'').toLowerCase(),mode=name==='dead front'?'deadFront':name==='ice castle'?'iceCastle':null;
 if(!mode)fail(`${content?.name||content||'This content'} has no shared Party War route. Use Dead Front or Ice Castle.`,400);
 if(!world.data.eventData?.modes?.[mode])fail('The original Party War tables are unavailable.',503);
 const overrides=world.eventOverrides||=new Map(),prior=overrides.get(mode);
 if(state==='end'){
  overrides.delete(mode);
  if(prior)for(const instance of world.instances?.values()||[])if(instance.kind===mode&&instance.gmCycle===prior.cycle){instance.run?.end('GM ended event');await requestInstanceClose(world,instance);}
  return `${name}: GM event closed.`;
 }
 if(!['open','start'].includes(state))fail('Use open, start, or end for this event.');
 const cfg=world.data.eventData.modes[mode].config,now=world.now();
 if(!cfg||!['RecordTime','RecordEndTime','ChooseTime','WaitTime'].every(key=>Number.isFinite(Number(cfg[key]))))fail('The original Party War clock is unavailable.',503);
 const register=state==='open'?now:now-Math.max(0,Number(cfg.ChooseTime)-Number(cfg.RecordTime))*1000;
 const closed=register+Math.max(0,Number(cfg.RecordEndTime)-Number(cfg.RecordTime))*1000;
 const enter=state==='open'?register+Math.max(0,Number(cfg.ChooseTime)-Number(cfg.RecordTime))*1000:now;
 const end=enter+Math.max(0,Number(cfg.WaitTime))*1000;
 if(!Number.isFinite(closed)||!Number.isFinite(enter)||!Number.isFinite(end)||end<=enter)fail('The original Party War clock is unavailable.',503);
 // Dead Front 16a (b6e6e66 / MATH-VERIFY 16a): Global OnDeadFrontStart refuses when any field IsBattleStart.
 // Engine mirror: refuse GM start/open while a live instance of this mode is mid-battle.
 for(const instance of world.instances?.values()||[]){
  if(instance.kind===mode&&instance.run&&!instance.run.ended&&!instance.closeRequested)
   fail(`${name}: a live battle is already running. End it before starting another.`);
 }
 // 16a bShowEnterDelay (2d7a963): refuse another GM start/open while a prior override's enter/registration window is still open (now < prior.end).
 if(prior&&Number.isFinite(prior.end)&&now<prior.end)
  fail(`${name}: entry/registration is still open until ${new Date(prior.end).toISOString()}. End it first, or wait.`);
 // 16c_GM_FULL_CYCLE_BLOCKED: Global full notice→register→~30min battle cycle vs instant test start remains ENGINE-CHOSEN / needs owner.
 const cycle=prior?.cycle??now;
 overrides.set(mode,{cycle,register,closed,enter,end,gm:true});
 return `${name}: ${state==='open'?'applications open':'entry open'} at the original officers until ${serverDate(state==='open'?closed:end).toISOString().slice(11,19)} ${SERVER_TIME.name}; level and ticket rules still apply.`;
}
function members(world,instance){return [...world.players.values()].filter(p=>!p.leaving&&p.instanceId===instance.id);}
function emit(world,instance,event){world.emit(instance.map,{...event,instanceId:instance.id});}
export function eventChannel(world,instance,p,text,ms,opts={}){
 const run=instance.run,phase=run.phase,map=instance.map,channelId=randomUUID(),startedAt=world.now(),durationMs=Math.max(0,Number(ms)||0),endAt=startedAt+durationMs,start={x:p.x,z:p.z},hp=p.hp,hitRevision=p.hitRevision||0;
 const valid=()=>world.instances?.get(instance.id)===instance&&instance.run===run&&!instance.closeRequested&&!run.ended&&run.won==null&&run.phase===phase&&world.players.get(p.account)===p&&!p.leaving&&!p.dead&&p.instanceId===instance.id&&p.map===map&&Math.hypot(p.x-start.x,p.z-start.z)<=.1&&p.hp>=hp&&(p.hitRevision||0)===hitRevision;
 // Why a channel failed (partywar #300|124-126: moved / attacked / left the map); 'scope' = the run moved on.
 const failReason=()=>world.instances?.get(instance.id)!==instance||instance.run!==run||instance.closeRequested||run.ended||run.won!=null||run.phase!==phase?'scope':world.players.get(p.account)!==p||p.leaving||p.instanceId!==instance.id||p.map!==map?'left':p.dead||p.hp<hp||(p.hitRevision||0)!==hitRevision?'hit':Math.hypot(p.x-start.x,p.z-start.z)>.1?'moved':null;
 const failed=()=>{const why=failReason();if(why)opts.onFail?.(why);};
 const send=event=>world.emit(map,{...event,instanceId:instance.id,actorId:p.id,recipients:[p.id],channelId,channelKind:'event'});
 if(!valid()){failed();return Promise.resolve(false);}
 let channel,timer;
 return new Promise(resolve=>{
  let done=false;channel={end:endAt,p,start,valid,descriptor:{type:'event:channel',map,instanceId:instance.id,actorId:p.id,channelId,channelKind:'event',text:String(text),durationMs,startedAt,endAt,phase,depot:opts.depot?{id:opts.depot.id,rank:opts.depot.rank}:null},resolve(ok){if(done)return;done=true;clearInterval(timer);instance.channels=instance.channels.filter(c=>c!==channel);resolve(!!ok&&world.now()>=endAt&&valid());}};
  (instance.channels||=[]).push(channel);send({type:'event:channel',text:String(text),durationMs,startedAt,endAt,phase});
  timer=setInterval(()=>{if(!valid())channel.resolve(false);},50);timer.unref?.();
 }).then(ok=>{const completed=!!ok&&valid();send({type:'event:channel-end',completed});if(!completed)failed();return completed;});
}
class HostBricks {
 constructor(world,instance,data){this.world=world;this.instance=instance;this.data=data;this.placements=new Map((data.map(instance.map)?.bricks||[]).map(([uid,brick,x,z,dir,isCreate])=>[uid,{uid,brick,x,z,dir,isCreate}]));this.byUid=new Map();this.counts=new Map();this.base=new Uint8Array(instance.scene.collision?.cells||0);}
 rows(){return [...this.placements.values()];}
 async spawn(uid){const pl=this.placements.get(uid),def=pl&&this.data.brick(pl.brick);if(!def)return null;let current=this.byUid.get(uid);if(current&&(!current.removed||isEventObject(current)))return current;const cells=eventBrickFootprintCells(this.instance.map,pl,def).filter(([x,z])=>x>=0&&z>=0&&x<this.instance.scene.width&&z<this.instance.scene.height).map(([x,z])=>z*this.instance.scene.width+x);current={...pl,removed:false,dead:false,cells,play:()=>{}};
 // Lane 59: Dead Front breakable bricks (the armory wood fences; brick.csv resists below 100, isBreakable) are event objects.
 const dfObject=this.instance.kind==='deadFront'&&isBreakable(def);if((this.instance.kind==='iceCastle'&&[36818,36819].includes(pl.brick)||dfObject)&&def.targeting&&def.isAttackable){
  if(dfObject)current.deadFrontObject=true;
  Object.assign(current,{eventObject:true,isBrick:true,brickIndex:pl.brick,id:`event-brick:${this.instance.id}:${uid}`,instanceId:this.instance.id,map:this.instance.map,name:def.name,brickDef:def,hp:def.maxHP,maxHp:def.maxHP,respawnAt:Infinity,respawnSec:Infinity,targetId:null,objectFootprint:cells.map(i=>({i,x:i%this.instance.scene.width,z:Math.floor(i/this.instance.scene.width)})),def:{name:def.name,level:def.level,hp:def.maxHP,exp:def.exp,def:[0,0],guard:[0,0],resist:[],speed:[0,0],role:'object',antiStatusRate:def.raw?.AntiStatusRate,antiKnockBack:Number(def.raw?.AntiKnockBackRate)>=100}});
  this.instance.scene.monsters.set(current.id,current);
 }this.byUid.set(uid,current);for(const i of cells){this.counts.set(i,(this.counts.get(i)||0)+1);this.instance.scene.collision.cells[i]=1;}return current;}
 spawnAll(ids){return Promise.all([...ids].map(id=>this.spawn(id)));}
 spawnInitial(){return this.spawnAll(this.rows().filter(p=>Number(p.isCreate)===1).map(p=>p.uid));}
 get(uid){return this.byUid.get(uid);}
 standing(uid){const b=this.get(uid);return !!b&&!b.removed;}
 remove(uid,animation='open'){const b=this.get(uid);if(!b||b.removed)return;b.removed=true;b.animation=animation;if(isEventObject(b)){b.dead=true;b.hp=0;}if(b.passable)return;for(const i of b.cells){const n=Math.max(0,(this.counts.get(i)||1)-1);this.counts.set(i,n);this.instance.scene.collision.cells[i]=n?1:this.base[i];}}
 removeAll(ids,animation){for(const id of ids)this.remove(id,animation);}
 // Lane 59: script BrickOpenRedCell / BrickCloseRedCell (older server reference): visible brick, walkable or blocked cells.
 setPassable(uid,on){const b=this.get(uid);if(!b||b.removed||!!b.passable===!!on)return false;b.passable=!!on;for(const i of b.cells){const n=Math.max(0,(this.counts.get(i)||0)+(on?-1:1));this.counts.set(i,n);this.instance.scene.collision.cells[i]=n?1:this.base[i];}return true;}
 update(){}dispose(){for(const id of this.byUid.keys())this.remove(id);}
}
class HostWaves {
 constructor(world,instance){this.world=world;this.instance=instance;this.groups=new Map();}
 spawn(key,rows,opts={}){const group={key,opts,recs:[],total:0,killed:0,removed:0,done:false};this.groups.set(key,group);
  for(const row of rows||[]){const [index,x,z,radius,count]=Array.isArray(row)?row:[row.monster,row.x,row.z,row.radius||0,row.count||1];const def=this.world.data.monsterDef(Number(index));if(!def)fail(`Original event monster ${index} is unavailable.`,503);for(let n=0;n<Math.max(1,Number(count)||1);n++){let sx=Number(x)+(Array.isArray(row)?0.5:0),sz=Number(z)+(Array.isArray(row)?0.5:0);
   // Match the local Dead Front wave's radius sampling: six authored group members must not share one pose.
   // Count/radius remain the explicitly ENGINE-CHOSEN Dead Front rules; no population scaling is inferred.
   if(this.instance.kind==='deadFront'&&Number(radius)>0)for(let t=0;t<8;t++){const a=this.world.random()*Math.PI*2,d=Number(radius)*Math.sqrt(this.world.random()),qx=sx+Math.cos(a)*d,qz=sz+Math.sin(a)*d;if(this.instance.scene.isWalkable(qx,qz)){sx=qx;sz=qz;break;}}
   const point=this.instance.scene.isWalkable(sx,sz)?{x:sx,z:sz}:this.instance.scene.nearest(sx,sz);if(!point)fail('No safe event spawn point is available.',503);const id=`event:${this.instance.id}:${randomUUID()}`;// the same ENGINE-CHOSEN wave override as the offline Waves (src/systems/events/waves.js _adopt): an aggressive wave forces
// aggression, explicit opts.sight / opts.pursuit raise the data ranges; a brain (tower march) spawn is passive like MarchBrain;
// otherwise the monster keeps its own monsters.json ai block
const ai={...def.ai};if(opts.brain)ai.aggressive=false;else if(opts.aggressive){ai.aggressive=true;if(opts.sight>0)ai.sight=Math.max(Number(ai.sight)||0,opts.sight);if(opts.pursuit>0)ai.pursuit=Math.max(Number(ai.pursuit)||0,opts.pursuit);}
const m={id,map:this.instance.map,instanceId:this.instance.id,monsterIndex:Number(index),name:def.name,...point,hp:def.hp,maxHp:def.hp,home:{...point},dead:false,targetId:null,attackAt:0,respawnAt:Infinity,respawnSec:Infinity,def:{...def,ai},eventGroup:group};group.recs.push(m);this.instance.scene.monsters.set(id,m);
 if(opts.brain){m.kind='monster';m.play=()=>{};const brain=opts.brain(this.instance.game,m);m.eventMarch={goal:brain.goal,reach:brain.goalReach,speed:brain.runSpeed||3,onArrive:brain.onArrive};}
 opts.onSpawn?.(m,group);}}
  group.total=group.recs.length;if(!group.total)this.finish(group);return group;
 }
 finish(group){if(group.done)return;group.done=true;if(!this.disposing)group.opts.onDone?.(group);}
 deaths(){for(const group of [...this.groups.values()]){for(const m of group.recs)if(m.dead&&!m._eventCounted){m._eventCounted=true;group.killed++;this.instance.creditId=lastHitter(this.world,m.id);group.opts.onKill?.(m,group);}if(group.killed+group.removed>=group.total)this.finish(group);}}
 group(key){return this.groups.get(key);}live(key){return this.groups.get(key)?.recs.filter(m=>!m.dead)||[];}left(key){const g=this.groups.get(key);return g?g.total-g.killed-g.removed:0;}isDone(key){return !!this.groups.get(key)?.done;}
 removeMonster(m){if(m._eventCounted)return;m._eventCounted=true;m.dead=true;m.hp=0;m.eventGroup.removed++;this.instance.scene.monsters.delete(m.id);if(m.eventGroup.killed+m.eventGroup.removed>=m.eventGroup.total)this.finish(m.eventGroup);}
 clearGroup(key){for(const m of this.groups.get(key)?.recs||[])this.removeMonster(m);}aliveCount(){return [...this.groups.values()].reduce((n,g)=>n+this.left(g.key),0);}dispose(){this.disposing=true;for(const key of this.groups.keys())this.clearGroup(key);}
}
async function prepareRun(world,instance,leader){
 const data=world.data.eventData,scene=instance.scene;const dialogs=new Map();let acting=leader;
 const game={time:world.now()/1000,settings:{},data:{monster:id=>world.data.monsterDef(id)},events:{on(){return()=>{}},off(){},emit(){}},uiwin:null,world:{info:{index:instance.map},collision:scene.collision,isWalkable:scene.isWalkable,findPath:scene.path,nearestWalkable:scene.nearest},npcs:(data.map(instance.map)?.npcs||[]).map(row=>({npcIndex:row[0],x:Number(row[1])+0.5,z:Number(row[2])+0.5})),spawner:{near:(x,z,r)=>[...scene.monsters.values()].filter(m=>!m.dead&&Math.hypot(m.x-x,m.z-z)<r)},hud:{log:text=>emit(world,instance,{type:'event:message',text:String(text)})},persist:()=>{},travel:async(map,point)=>{for(const p of members(world,instance)){if(map===instance.map){const at=scene.nearest(point.x,point.z);if(at){p.x=at.x;p.z=at.z;p.path=[];world.changed(p);}}else await exitInstance(world,p);}}};
 Object.defineProperty(game,'save',{get:()=>acting.profile});Object.defineProperty(game,'player',{get:()=>acting});
 game.items={count:id=>new AuthoritativeInventory(acting.profile,world.data.itemDB).count(id),spendDil:amount=>{const inv=new AuthoritativeInventory(acting.profile,world.data.itemDB);if(inv.dil<amount)return false;inv.addDil(-amount);world.changed(acting);return true;}};
 const ui={partyInfo(){},timer(){},result(){},tower(){},closeAll(){},channel:(text,ms,opts)=>eventChannel(world,instance,acting,text,ms,opts)};
 const sys={game,data,ui,msg:{say:(e,opts={})=>{
  if(!e)return;const nativeEntry={...e,text:e.text?fill(e.text,opts.vars,opts.args):''},text=plain(nativeEntry.text);
   if(opts.source)nativeEntry.source={file:opts.source.file??null,cate:opts.source.cate??null,code:opts.source.code??null,args:Array.isArray(opts.args)?[...opts.args]:[]};
  // Empty-text native countdown, BGM and result directives are still real stage events.
  for(const sound of e.sound||[])if(Number(sound.a)===0&&Number.isSafeInteger(Number(sound.id)))instance.nativeBgm=Number(sound.id);
  if(text.trim()||e.effectUi?.length||e.sound?.length||e.effectSound?.length)emit(world,instance,{type:'event:message',text,nativeEntry,phase:instance.run?.phase,chat:opts.chat!==false,notice:opts.notice!==false,...(instance.sayTo?{recipients:[...instance.sayTo]}:{})});
 },code(cat,id,vol=0,range=0,at=null){
  emit(world,instance,{type:'event:message',text:'',phase:instance.run?.phase,nativeEntry:{kind:'effect',effectSound:[{cat,id,vol,range}]},at:at?{x:at.x,z:at.z}:null});
 }},dialog:{show:page=>dialogs.set(acting.id,page),close:()=>dialogs.delete(acting.id)}};
 const run=instance.kind==='deadFront'?new DeadFrontRun(sys,instance.map,{entry:'officer'}):new IceCastleRun(sys,instance.map,{entry:'officer'});run.waves.dispose();run.bricks=new HostBricks(world,instance,data);run.waves=new HostWaves(world,instance);
 run.rewards=()=>{
  if(instance.rewarded)return;
  // The shared host replaces PartyWarRun.rewards. Lane 59: the Dead Front treasure boxes come from the script close
  // step (deadfront.js _closeStep, older server reference spots), not from here.
  // PARTY-WAR: with two or more teams each member is paid by its team's place (server/world/party-war.mjs)
  const war=(instance.startingTeamCount??instance.teams?.length??0)>1;
  // Publisher July 25, 2024: initially single-party runs earn no PvP score
  // or PvP EXP. Their PvE score and existing additional-EXP ratio remain.
  const won=!!run.won,res=run.res,score=run.score;
  // Preserve the existing PartyWarRun result-table formula; its EXP ratio is inferred in that source.
  const exp=Math.max(0,Math.round(score*(Number(res.advRatio)||0)));
  const points=instance.fortressFailed?0:Math.max(0,(won?Number(run.field.winRPoint)||0:0)+(Number(won?res.winRPoint4PvP:res.lostRPoint4PvP)||0));
  queueInstanceProgress(world,instance,`event:${instance.id}`,(p,facade)=>{
   const receipts=p.profile.eventRewards||=[];if(receipts.includes(instance.id))return;
   const pay=war?instance.warReward(p):{won,exp,points};
   if(pay.exp)world.grantProgress.call(facade,p,scaledReward(pay.exp,world.rates.exp));
   if(pay.points)p.profile.rPoint=(Number(p.profile.rPoint)||0)+pay.points;
   if(pay.won){questClear(facade,p,instance.map,{profile:p.profile});progressDekaPass(facade,p,2,12,instance.map,1);}
   receipts.push(instance.id);if(receipts.length>32)receipts.shift();
  },()=>{instance.rewarded=true;
   if(war){const rowOf=t=>{const r=instance.warReward({id:[...t.ids][0]});return {r,row:{rank:t.place,party:t.name,point:t.score,exp:scaledReward(r.exp,world.rates.exp)}};},rows=[...instance.teams].sort((a,b)=>a.place-b.place).map(t=>rowOf(t).row);
    instance.results=new Map(instance.teams.map(t=>{const {r}=rowOf(t);return [t.index,{type:'event:result',map:instance.map,instanceId:instance.id,won:r.won,score:r.score,rPoint:r.points,exp:scaledReward(r.exp,world.rates.exp),cooperative:true,war:true,team:t.index,place:t.place,...(instance.fortressFailed?{failed:true}:{}),teams:rows}];}));
    for(const t of instance.teams){const ids=[...world.players.values()].filter(q=>!q.leaving&&q.instanceId===instance.id&&t.ids.has(q.id)).map(q=>q.id);if(ids.length)emit(world,instance,{...instance.results.get(t.index),recipients:ids});}
    instance.result=instance.results.get(instance.teams.find(t=>t.place===1)?.index)||null;return;}
   run.score=score;instance.result={type:'event:result',map:instance.map,instanceId:instance.id,won,score,rPoint:points,exp:scaledReward(exp,world.rates.exp),cooperative:true,...(instance.fortressFailed?{failed:true}:{} )};emit(world,instance,instance.result);});
  instance.rewardSave=instance.progressSave;
 };
 const originalAfter=run.after.bind(run);run.after=(sec,fn)=>originalAfter(sec,()=>{try{const result=fn();if(result?.then)result.catch(error=>{instance.saveError=error.message;run.end('server error');});}catch(error){instance.saveError=error.message;run.end('server error');}});
 // The original solo close() moves its one player. A shared Reezena interaction
 // exits only its caller; the close timer separately moves all remaining members.
 run.close=()=>requestInstanceClose(world,instance);
 const exitPage=run.exitPage.bind(run);run.exitPage=npc=>{
  const page=exitPage(npc);
  if(run.phase==='waitClose')page.options[0].pick=async()=>{const p=acting;sys.dialog.close();await exitInstance(world,p);};
  return page;
 };
 if(instance.kind==='iceCastle'){
 const npcPage=run.npcPage.bind(run);run.npcPage=npc=>{
  const page=npcPage(npc);
  if(Number(npc.npcIndex)===5671&&page?.options?.[0])page.options[0].pick=async()=>{
   const p=acting;sys.dialog.close();if(run.midDead<=0){game.hud.log(run.text(10033));return;}
   const point=run._near({x:255.5,z:280},2),at=scene.nearest(point.x,point.z);if(!at)fail('No safe original event destination is available.',503);
   const candidate={...p,profile:structuredClone(p.profile),x:at.x,z:at.z,path:[]};world.changed(candidate);
   const transition=p.sceneTransition;p.sceneTransition=true;instance.serviceSave=true;
   try{await world.persist(candidate);for(const key of ['profile','x','z','path','revision','dirty','saveError'])p[key]=candidate[key];}
   finally{p.sceneTransition=transition;instance.serviceSave=false;}
  };
  return page;
 };
 const hitTower=run._hitTower.bind(run);run._hitTower=m=>{if(!instance.serviceSave)hitTower(m);};
 run._reenergize=async()=>{
  const p=acting;sys.dialog.close();
  if(!run.tower||run.failed||run.cleared||run.won!=null||run.phase!=='fortress'||run.towerHp>=100){run.say(10036);return;}
  const candidate={...p,profile:structuredClone(p.profile)},inv=new AuthoritativeInventory(candidate.profile,world.data.itemDB);
  if(inv.dil<100000){run.say(10037);return;}
  inv.addDil(-100000);world.changed(candidate);
  const transition=p.sceneTransition;p.sceneTransition=true;instance.serviceSave=true;
  try{await world.persist(candidate);for(const key of ['profile','revision','dirty','saveError'])p[key]=candidate[key];run.towerHp=100;run.ui.tower(1);run.say(10035);}
  finally{p.sceneTransition=transition;instance.serviceSave=false;}
 };
 }
 instance.run=run;instance.dialogs=dialogs;instance.actAs=p=>{acting=p;};instance.actor=()=>acting;instance.game=game;installPartyWar(world,instance,run);installDeadFrontHost(world,instance,run);await run.start();instance.eventTickAt=world.now();return run;
}
export function eventEntryMembers(world,p){
 // An expedition enters as one group in corp order; only its leader may choose the instance.
 const expedition=expeditionMembers(world,p);
 if(expedition){if(expedition.leader!==p.id)fail('The expedition leader must choose the instance.');if(expedition.members.some(q=>q.offline))fail('All expedition members must be connected.');return expedition.members;}
 const party=p.partyId&&world.parties?.get(p.partyId);if(party&&party.leader!==p.id)fail('The party leader must choose the instance.');const result=party?party.members.map(id=>[...world.players.values()].find(q=>q.id===id&&!q.leaving)): [p];if(result.some(q=>!q))fail('All party members must be connected.');return result;}
export async function eventCommand(world,p,input){
 if(input.operation==='titles')return {titles:titleSnapshot(p)};
 if(input.operation==='title'){const title=selectTitle(world,p,input.title);await world.persist(p);return {title,titles:titleSnapshot(p)};}
 if(input.operation==='record'){
  // Native job 37/98 RECORD_PARTY_WAR: a solo player or party leader applies during registration.
  const data=world.data.eventData;if(!data)fail('Event tables are unavailable.',503);const mode=data.modeOf(input.map);if(!['deadFront','iceCastle'].includes(mode))fail('Choose a supported cooperative event.');const officer=data.officerByNpc.get(input.npc);if(!officer||officer.mode!==mode||officer.map!==input.map)fail('Choose the original event officer.');
  const win=eventWindow(world,mode);if(win?.phase!=='register')fail('It is not the application period.');
  // Global PartywarRecordHandler result 6 = 100:6 "You need to form a party in order to apply." (stringtable_partywar)
  if(!(p.partyId&&world.parties?.get(p.partyId)))fail('You need to form a party in order to apply.');
  const members=eventEntryMembers(world,p),applicant=applicantKey(world,p);
  const placement=nearbyNpc(world,p,{npcIndex:input.npc,radius:8});
  if(!placement||isCustomScene(world,p.map)&&!offersOriginalJob(world,placement,mode==='deadFront'?37:98,input.map))fail('Walk to the event officer.');
  const field=data.field(mode,input.map),[lo,hi]=field.entryLevel||field.level||[1,250],itemCode=Number(field?.itemCode)||0;
  for(const member of members){if(member.dead||!sameScene(member,p))fail('All party members must be in the entrance area.');if(member.profile.level<lo||member.profile.level>hi)fail('Every party member must meet the original entry level.');if(itemCode>0&&new AuthoritativeInventory(member.profile,world.data.itemDB).count(itemCode)<1)fail('Each party member needs the original admission ticket.');}
  const apps=(world.eventApplications||=new Map());for(const[k,list]of apps)if(k.endsWith(':'+win.cycle)&&list.some(a=>a.applicant===applicant))fail('You have already applied.');
  // Global field.csv RecordEnableCount caps the applications of a field; PartywarRecordHandler result 3 is 100:3
  // "Maximum # of party reached. You cannot apply.", so more than RecordEnableCount (at most 4) applicants never exist.
  const key=`${mode}:${input.map}:${win.cycle}`,list=apps.get(key)||[];if(list.length>=Math.min(EVENT_MAX_PARTIES,Number(field?.maxParties)||EVENT_MAX_PARTIES))fail('Maximum # of party reached. You cannot apply.');list.push({applicant,leader:p.id,at:world.now()});apps.set(key,list);
  for(const[k,l]of apps)if(Number(k.split(':').pop())<win.cycle-86400000)apps.delete(k);
  return {applied:true,position:list.length};
 }
 if(input.operation==='enter'){
  const data=world.data.eventData;if(!data)fail('Event tables are unavailable.',503);const mode=data.modeOf(input.map);if(!['deadFront','iceCastle'].includes(mode))fail('Choose a supported cooperative event.');const officer=data.officerByNpc.get(input.npc);if(!officer||officer.mode!==mode||officer.map!==input.map)fail('Choose the original event officer.');
  const participants=eventEntryMembers(world,p),field=data.field(mode,input.map),tier=data.tierOf(mode,input.map)?.tier,itemCode=Number(field?.itemCode)||0;
  const npcOnly=participants.every(member=>member.npcPlayer===true),npcWarId=validateNpcEventAdmission(world,participants,{mode,map:input.map,leader:p});
  {// Entry window ChooseTime..ChooseTime+WaitTime; at most min(EVENT_MAX_PARTIES, RecordEnableCount) applicants per field: the record command refuses more (Global 100:3), so every applicant is selected.
   const win=eventWindow(world,mode),list=(win&&world.eventApplications?.get(`${mode}:${input.map}:${win.cycle}`))||[],capacity=Math.min(EVENT_MAX_PARTIES,Number(field?.maxParties)||EVENT_MAX_PARTIES);
   if(win?.phase!=='enter')fail('Entry opens only after the application period and selection.');if(!(win.gm&&list.length===0)&&!list.slice(0,capacity).some(a=>a.applicant===applicantKey(world,p)))fail('You were not selected for this event.');}
  const placement=nearbyNpc(world,p,{npcIndex:input.npc,radius:8});
  if(!placement||isCustomScene(world,p.map)&&!offersOriginalJob(world,placement,mode==='deadFront'?38:99,input.map))fail('Walk to the event officer.');
  const [lo,hi]=field.entryLevel||field.level||[1,250];const clones=participants.map(member=>{if(member.dead||member.instanceId||!sameScene(member,p)||Math.hypot(member.x-p.x,member.z-p.z)>20)fail('All party members must gather alive beside the officer.');if(member.profile.level<lo||member.profile.level>hi)fail('Every party member must meet the original entry level.');const profile=structuredClone(member.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:()=>world.now(),random:world.random});if(itemCode>0&&!inv.remove(itemCode,1))fail('Each party member needs the original admission ticket.');return profile;});
  let instance;for(const member of participants)member.sceneTransition=true;
  const staged=stageInstanceMembers(world,participants,clones);
  let joined=null,team=null,npcStored=false,npcCommitted=false;
  try{joined=joinableWar(world,mode,input.map,p);if(npcWarId&&joined?.id!==npcWarId)throw Object.assign(Error("NPC event target changed. Choose entry again."),{status:409});if(joined){team=joinWarTeam(staged.world,joined,staged.candidates);}else{instance=await createInstance(staged.world,{map:input.map,members:staged.candidates,kind:mode,exit:data.fieldPoint(mode,input.map,field.endWarRespawn),durationMs:2400000});instance.admitting=true;instance.gmCycle=eventWindow(world,mode)?.gm?eventWindow(world,mode).cycle:null;const start=data.fieldPoint(mode,input.map,field.starts[0]);const at=instance.scene.nearest(start.x,start.z);if(!at)fail('No safe event start exists.',503);for(const member of staged.candidates){member.x=at.x;member.z=at.z;world.changed(member);}await prepareRun(staged.world,instance,staged.candidates[0]);}const current=eventEntryMembers(world,p);if(current.length!==participants.length||current.some(member=>!participants.includes(member)||world.players.get(member.account)!==member))fail('Party membership changed. Choose entry again.',409);for(const member of staged.candidates)progressDekaPass(staged.world,member,2,16,input.map,1);if(npcOnly)validateNpcEventAdmission(world,participants,{mode,map:input.map,leader:p,warId:npcWarId});await world.persistMany(staged.candidates);npcStored=npcOnly;if(npcOnly)validateNpcEventAdmission(world,participants,{mode,map:input.map,leader:p,warId:npcWarId});npcCommitted=true;await staged.commit();(instance||joined).actAs(p);if(instance)instance.admitting=false;}catch(error){if(joined&&team)removeTeam(joined,team);if(instance){instance.run?.end('entry failed');world.instances.delete(instance.id);world.maps.delete(`${instance.map}@${instance.id}`);}if(npcStored&&!npcCommitted)await world.persistMany(participants);throw error;}finally{for(const member of participants)member.sceneTransition=false;}
  return;
 }
 const instance=world.instances?.get(p.instanceId);if(!instance?.run)fail('You are not in an active cooperative event.');
 if(input.operation==='exit'){await exitInstance(world,p);return;}
 if(input.operation!=='npc'||!Number.isInteger(input.npc)||!Array.isArray(input.path)||input.path.length>3||input.path.some(i=>!Number.isInteger(i)||i<0||i>20))fail('Choose an original event interaction.');
 const validateInteraction=()=>{
  if(world.players.get(p.account)!==p||p.leaving||p.dead||p.instanceId!==instance.id||instance.run.ended||instance.closeRequested)fail('This event interaction is no longer available.',409);
  const info=world.data.eventData.map(p.map),placement=(info.npcs||[]).find(row=>Number(row[0])===input.npc&&Math.hypot(p.x-(Number(row[1])+0.5),p.z-(Number(row[2])+0.5))<=8);
  if(!placement)fail('Walk to this event NPC.');
  if(input.npc!==5672&&instance.run.won!=null)fail('The event objectives have finished.',409);
  return placement;
 };
 validateInteraction();
 const prior=instance.interactionQueue||Promise.resolve();let release;instance.interactionQueue=new Promise(resolve=>release=resolve);await prior.catch(()=>{});try{
 const placement=validateInteraction();instance.actAs(p);let page=instance.run.npcPage({npcIndex:input.npc,x:Number(placement[1])+0.5,z:Number(placement[2])+0.5,name:world.data.eventData.npc(input.npc)?.name||'Event NPC'});if(!page)fail('This event interaction is unavailable.');
 for(const index of input.path){const option=page.options?.[index];if(!option)fail('Choose a current original dialogue option.');instance.dialogs.delete(p.id);const before=new Set(instance.channels||[]);const picked=option.pick();
  // A job that opens an attach channel (supply depot, slate) answers now: holding this command for the whole channel
  // would queue the player's own move/attack commands behind it, so moving could never cancel it (#300|124-126).
  if((instance.channels||[]).some(c=>c.p===p&&!before.has(c))){Promise.resolve(picked).catch(error=>console.warn('[events] channel job failed',error?.message||error));page={text:'',options:[]};break;}
  await picked;page=instance.dialogs.get(p.id)||{text:'',options:[]};}
 if(p.dirty)await world.persist(p);return {dialog:{npc:input.npc,text:page.text||'',options:(page.options||[]).map(o=>({label:o.label||'Continue'}))}};}finally{release();}
}
export function tickEvents(world,dt){tickTitles(world);void tickFieldBoss(world).catch(error=>console.warn('[fieldboss] tick failed',error?.message||error));for(const instance of world.instances?.values()||[]){
 retryInstanceProgress(world,instance);
 if(instance.admitting||instance.progressSave||instance.floorTransition||instance.serviceSave)continue;
 const run=instance.run;
 if(instance.expiresAt<=world.now()||instance.closeRequested){
  for(const channel of instance.channels||[])channel.resolve(false);instance.channels=[];
  requestInstanceClose(world,instance);continue;
 }
 if(instance.kind==='dungeon'||!run||run.ended)continue;
 instance.game.time=world.now()/1000;run.waves.deaths();
 for(const channel of [...instance.channels||[]])if(world.now()>=channel.end||channel.valid&&!channel.valid()||channel.p.dead||channel.p.leaving||channel.p.instanceId!==instance.id||Math.hypot(channel.p.x-channel.start.x,channel.p.z-channel.start.z)>0.1){
  instance.channels=instance.channels.filter(c=>c!==channel);
  channel.resolve(!channel.p.dead&&!channel.p.leaving&&channel.p.instanceId===instance.id&&Math.hypot(channel.p.x-channel.start.x,channel.p.z-channel.start.z)<=0.1);
 }
 // World movement clamps a slow tick to 0.2 s; event countdowns and scripted
 // delays must still follow the host's elapsed wall time.
 const eventNow=world.now(),clockDt=Number.isFinite(instance.eventTickAt)?Math.max(0,(eventNow-instance.eventTickAt)/1000):dt;
 instance.eventTickAt=eventNow;
 run.update(dt,clockDt);
}}
export function eventSnapshot(world,p){const i=world.instances?.get(p.instanceId),r=i?.run;return r&&i.kind!=='dungeon'?{id:i.id,map:i.map,kind:i.kind,phase:r.phase,nativeBgm:i.nativeBgm??null,remainingMs:Math.max(0,Math.round(r.phaseT*1000)),score:i.teams?.length>1?teamOf(i,p)?.score??0:r.score,won:i.teams?.length>1?(i.rewarded?teamOf(i,p)?.place===1:null):r.won,war:partyWarSnapshot(world,p,i),towerHp:r.towerHp??null,cooperative:true,channels:(i.channels||[]).filter(c=>c.p===p&&c.valid?.()).map(c=>c.descriptor),result:i.rewarded?(i.resultFor?.(p)||i.result):null,saveError:i.saveError||null,bricks:[...r.bricks.byUid.values()].map(b=>({uid:b.uid,brick:b.brick,x:b.x,z:b.z,dir:b.dir,id:isEventObject(b)?b.id:null,hp:isEventObject(b)?b.hp:null,maxHp:isEventObject(b)?b.maxHp:null,breakable:isEventObject(b),dead:!!b.dead,removed:b.removed,passable:!!b.passable,animation:b.animation||null}))}:null;}

