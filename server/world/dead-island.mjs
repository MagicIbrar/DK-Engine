// Dead Island admission: native guild/level/rank/channel/ticket refusals and 120-minute challenge.
// Ticket issuance: Global binds the quest1637 Frontier ticket dialogue to no NPC (npcs.json/dialogs.json jobs,
// quest.csv S_npc/E_npc 0), and no shop, box, quest reward or event issues item 7519; the guessed Vascuda issuer
// was removed (lane 57). UNRESOLVED: Global's 7519 source. ENGINE-CHOSEN: creations are counted per guild/server
// day; corresponding named ships choose landings.
// Creations 4-6 need one Camouflage [Frontier] (system_variable 51 = 1755139) per server day. No shop, box, quest
// or drop issues it: it is a GM-event prize, awarded with the GM grant command (/gm giveitem, server/world/gm.mjs).
import {socialState,socialRef} from './social-state.mjs';
import {guildFrontierAccess,frontierSettlementPending} from './guild-frontier.mjs';
import {AuthoritativeInventory} from './inventory.mjs';
import {createInstance,stageInstanceMembers} from './instances.mjs';
import {prepareDungeon} from './dungeons.mjs';
import {sceneKey} from './scene.mjs';
import {nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {serverDayKey} from '../../src/game/server-time.js';
import {progressDekaPass} from './dekapass.mjs';
import {chooseAbility,releaseAbility,issueStageStones,resonate,enterArena,tickDeadIslandRun,resetDeadIslandBattle} from './dead-island-run.mjs';

const fail=(message,status=400)=>{throw Object.assign(Error(message),{status});};
const plain=text=>String(text||'').replace(/^\[message\]\s*/,'').replace(/<[^>]*>/g,'').trim();
const text=(world,code)=>plain(world.data.dungeonData?.dg?.maps?.[551]?.messages?.[code]?.t);
const refuse=(world,code)=>fail(text(world,code)||`Dead Island admission refused (${code}).`);
const SHIPS=new Map([[5665,5542],[5666,5543],[5667,5544]]);
export const DEAD_ISLAND_POLICY=Object.freeze({map:551,durationMs:7200000,ticket:7519,eventTicket:1601106,camouflage:1755139,baseCreates:3,maxCreates:6,label:'ENGINE-CHOSEN per-guild server-day counter and named-ship landing; native restrictions, items and challenge duration; Camouflage [Frontier] is a GM-event prize (/gm giveitem)'});
function active(world,p){if(world.players.get(p.account)!==p||p.leaving||p.dead||p.instanceId||p.tradeId||p.tradeCommitting||p.combatUntil>world.now())fail('Leave battle, trading and your current instance before using this service.');}
function guildLevel(world,g){if(Number.isSafeInteger(g.level)&&g.level>0)return g.level;let level=1;for(let n=1;n<=15;n++)if(Number(g.gpoint)>=Number(world.data.guild?.config?.[`LEVELSTEP${n}`]))level=n;return level;}
function ancientQuickslot(profile){const entries=[...(profile.hotbar||[]),...(profile.quickslot?.belt||[]),...(profile.quickslot?.sets||[]).flat()];return entries.some(e=>e?.type==='item'&&e.itemIndex>=7499&&e.itemIndex<=7518);}
function eligibility(world,p,npc){
 active(world,p);if(p.map!==550||!SHIPS.has(npc))fail('Walk to a Dead Island ship in Harbor Town.');
 const placed=nearbyNpc(world,p,{npcIndex:npc,radius:10});if(!placed||!offersOriginalJob(world,placed,19,551))fail('Walk to a Dead Island ship in Harbor Town.');
 const {guild,award}=guildFrontierAccess(world,p);if(!guild)refuse(world,107);if(guildLevel(world,guild)<5)refuse(world,109);
 if(frontierSettlementPending(world))refuse(world,106);if(!award)refuse(world,105);
 const channel=award.dungeonGrade<=5?0:1;if((p.channel??0)!==channel)refuse(world,103);
 if(ancientQuickslot(p.profile))refuse(world,108);if(p.mount)fail('Dismiss your mount before entering Dead Island.');
 return {guild,award,channel};
}
function stateCopy(world){const current=socialState(world);return {current,state:structuredClone(current)};}
async function save(world,current,state,q){state.revision=current.revision+1;if(await world.saveSocialTransaction({expectedRevision:current.revision,state,updates:[{accountId:q.account,characterId:q.characterId,profile:world.canonical(q)}]})===false)fail('Dead Island could not save your admission. Nothing was consumed.',503);world.socialState=state;}
function installBattleService(world,i){
 const d=i.director,authorize=()=>{const p=i.acting,{guild}=guildFrontierAccess(world,p);if(!p||world.players.get(p.account)!==p||p.dead||p.leaving||p.instanceId!==i.id||i.closeRequested||!guild||guild.id!==i.frontierGuild||guild.master!==socialRef(p))refuse(world,263);return p;};
 d.game.deadIslandService={
  async start(){authorize();if(d.phase!=='waiting')refuse(world,247);d.waitStart=false;d._begin();await saveRun(world,i);},
  async reset(price){const p=authorize();if(d.phase!=='running')refuse(world,248);const expected=[10000000,20000000,40000000,80000000,160000000][Math.min(4,d.deadIslandResets)];if(price!==expected)fail('Choose the current battle reset.');
   const profile=structuredClone(p.profile),inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});if(inv.dil<price)refuse(world,259);inv.addDil(-price);
   const staged=stageInstanceMembers(world,[p],[profile]),q=staged.candidates[0],oldTransition=p.sceneTransition;p.sceneTransition=true;
   try{world.changed(q);await world.persist(q);await staged.commit();for(const s of d.stages){for(const r of s.recs||[])if(r.monster)i.scene.monsters.delete(r.monster.id);s.spawned=false;s.done=false;s.recs=[];}for(const m of [...i.scene.monsters.values()])if(m.deadIslandRun&&!m.isBrick)i.scene.monsters.delete(m.id);d.game.spawner.records.length=0;d._later=[];d.kills=0;d.killedIdx.clear();d.spawnedIdx.clear();d.phase='waiting';d.waitStart=true;d.deadIslandResets++;resetDeadIslandBattle(i);d.effect(220);}finally{p.sceneTransition=oldTransition;}
   await saveRun(world,i);
  },
  choose:menu=>chooseAbility(world,i,menu),release:()=>releaseAbility(world,i),resonate:npc=>resonate(world,i,npc),enter:npc=>enterArena(world,i,npc),
  hasAbility:()=>!!i.acting&&!!i.deadIslandRun?.choices?.has(i.acting.characterId),
  stage:n=>{void issueStageStones(world,i,n).catch(error=>{i.saveError=error.message;});},
  tick:()=>{tickDeadIslandRun(world,i);if(d.phase==='cleared'&&!i.deadIslandClearSaved){i.deadIslandClearSaved=true;void saveRun(world,i).catch(()=>{i.deadIslandClearSaved=false;});}},
 };
}
/** Durable paid-run custody (ENGINE-CHOSEN, src/config/engine-chosen-dead-island.js). */
function runRecord(i){return {id:i.id,expiresAt:i.expiresAt,channel:i.channel,award:i.frontierAward,resets:i.director?.deadIslandResets||0,admitted:[...i.admitted],cleared:i.director?.phase==='cleared'};}
async function saveRun(world,i){
 const current=socialState(world),state=structuredClone(current),g=state.guilds[i.frontierGuild];if(!g?.deadIsland)return;
 const next=runRecord(i);if(JSON.stringify(g.deadIsland.run)===JSON.stringify(next))return;g.deadIsland.run=next;state.revision=current.revision+1;
 if(await world.saveSocialTransaction({expectedRevision:current.revision,state,updates:[]})===false)fail('Dead Island could not save the run record.',503);world.socialState=state;
}
export function deadIslandRunSaver(world,i){return ()=>saveRun(world,i);}
/** A returning admitted member reattaches to its guild's paid run after a host
 * restart or after every member left. Called before core restores the instance. */
export async function restoreDeadIslandRun(world,profile){
 const saved=profile.instance;if(!saved||Number(saved.map)!==551||world.instances?.get(saved.id))return null;
 let state;try{state=socialState(world);}catch{return null;}
 const guild=Object.values(state.guilds||{}).find(g=>g.deadIsland?.run?.id===saved.id),rec=guild?.deadIsland?.run;
 if(!rec||rec.cleared||!(rec.expiresAt>world.now())||!rec.admitted?.includes(profile.id))return null;
 if(world.deadIslandRestoring?.has(rec.id))return world.deadIslandRestoring.get(rec.id);
 const task=(async()=>{
  world.instances||=new Map();
  const instance={id:rec.id,map:551,kind:'dungeon',exit:saved.exit||{map:550,x:167.5,z:108.5},admitted:new Set(rec.admitted),members:new Set(),expiresAt:rec.expiresAt,closed:false};
  instance.scene=await world.map(551,rec.id);instance.frontierGuild=guild.id;instance.frontierAward=rec.award;instance.channel=rec.channel;instance.restored=true;instance.admitting=true;
  world.instances.set(rec.id,instance);
  try{await prepareDungeon(world,instance,'551',0,{x:0,z:0,profile});installBattleService(world,instance);instance.director.deadIslandResets=Number(rec.resets)||0;}
  catch(error){instance.director?.dispose();world.instances.delete(rec.id);world.maps.delete(sceneKey(551,rec.id));throw error;}
  return instance;
 })().finally(()=>world.deadIslandRestoring?.delete(rec.id));
 (world.deadIslandRestoring||=new Map()).set(rec.id,task);return task;
}

async function admit(world,p,input){
 const npc=Number(input.npc),access=eligibility(world,p,npc),{current,state}=stateCopy(world),profile=structuredClone(p.profile),guild=state.guilds[access.guild.id];
 let instance=[...(world.instances?.values()||[])].find(i=>i.map===551&&i.frontierGuild===guild.id&&!i.closed&&!i.closeRequested&&i.expiresAt>world.now());
 const existing=!!instance;let staged,previousAdmitting;
 if(!existing){
  if(guild.master!==socialRef(p))refuse(world,104);
  const day=serverDayKey(world.now()),saved=guild.deadIsland,record=saved?.day===day?{...saved}:{day,created:0,camouflageUsed:false};
  if(!Number.isSafeInteger(record.created)||record.created<0||record.created>6||typeof record.camouflageUsed!=='boolean')fail('The guild dungeon counter is invalid; it was preserved.',503);
  if(record.created>=6)refuse(world,110);
  const inv=new AuthoritativeInventory(profile,world.data.itemDB,{now:world.now,random:world.random});
  if(record.created<3){if(!inv.remove(7519,1)&&!inv.remove(1601106,1))refuse(world,110);}
  else if(!record.camouflageUsed){if(!inv.remove(1755139,1))refuse(world,110);record.camouflageUsed=true;}
  record.created++;guild.deadIsland=record;
 }
 staged=stageInstanceMembers(world,[p],[profile]);const q=staged.candidates[0];
 try{
  if(!existing){instance=await createInstance(staged.world,{map:551,members:[q],kind:'dungeon',exit:{map:550,x:167.5,z:108.5},durationMs:DEAD_ISLAND_POLICY.durationMs});instance.frontierGuild=guild.id;instance.frontierAward=access.award.periodId;instance.channel=access.channel;instance.admitting=true;await prepareDungeon(staged.world,instance,'551',0,q);installBattleService(world,instance);}
  else {previousAdmitting=instance.admitting;instance.admitting=true;staged.world.emit(q.map,{type:'leave',actorId:q.id});q.instanceId=instance.id;q.map=551;q.path=[];q.mount=null;q.pet=null;q.profile.instance={id:instance.id,kind:'dungeon',map:551,exit:instance.exit};}
  const landing=world.data.dungeonData?.dg?.maps?.[551]?.scriptNpcs?.find(n=>n.npc===SHIPS.get(npc)),at=landing&&instance.scene.nearest(Number(landing.x),Number(landing.y));if(!at)fail('The original ship landing is unavailable.',503);
  q.x=at.x;q.z=at.z;q.path=[];world.changed(q);progressDekaPass(staged.world,q,2,16,551,1);
  const recheck=eligibility(world,p,npc);if(recheck.guild.id!==guild.id||recheck.award.periodId!==access.award.periodId)fail('Your guild dungeon permission changed; choose entry again.');
  // The paid run and its admitted members are durable with the same admission write.
  if(guild.deadIsland){const prior=guild.deadIsland.run?.id===instance.id?guild.deadIsland.run.admitted||[]:[];guild.deadIsland.run={id:instance.id,expiresAt:instance.expiresAt,channel:access.channel,award:access.award.periodId,resets:instance.director?.deadIslandResets||0,admitted:[...new Set([...prior,...instance.admitted,q.characterId])],cleared:false};}
  await save(world,current,state,q);instance.admitted.add(q.characterId);instance.members.add(q.id);staged.world.emit(551,{type:'join',actorId:q.id});
  return {staged,instance,previousAdmitting,result:{deadIsland:{instanceId:instance.id,joined:existing,remainingMs:instance.expiresAt-world.now()}}};
 }catch(error){if(instance&&!existing){instance.director?.dispose();world.instances.delete(instance.id);world.maps.delete(sceneKey(551,instance.id));}else if(instance)instance.admitting=previousAdmitting;throw error;}
}
export async function deadIslandCommand(world,p,input){
 if(input.type!=='dungeon'||input.operation!=='enter'||String(input.dungeonId)!=='551')return false;
 if(Object.keys(input).some(k=>!['type','token','operation','dungeonId','npc'].includes(k)))fail('Send the Frontier service intent only.');
 const transition=p.sceneTransition;if(transition)fail('Finish travelling before using this service.');p.sceneTransition=true;let pending;
 const task=(world.saveQueue||Promise.resolve()).catch(()=>{}).then(()=>admit(world,p,input));world.saveQueue=task.catch(()=>{});
 try{pending=await task;await pending.staged.commit();if(pending.instance){pending.instance.acting=p;pending.instance.admitting=pending.previousAdmitting??false;}return pending.result;}
 finally{p.sceneTransition=transition;if(pending?.instance)pending.instance.admitting=pending.previousAdmitting??false;}
}
