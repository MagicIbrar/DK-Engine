// Native title 27 "Agent of 12 Gods" (share/pc/title/title_base.csv Type 9; stringtable_title_syetem 2803|27 "Obtainable
// upon defeating all monsters in Karon's Fragment Hard/Core."). Host only: server/world/dungeons.mjs tickDungeons calls
// trackFullClearTitle for every running dungeon instance after its director step. Readings of the data gaps:
// src/config/engine-chosen-quests.js title27*. The grant rides the instance progress transaction: it is applied to staged
// profiles, published only when the party write succeeds, retried after a failed write, and its receipt stops a replay.
import {queueInstanceProgress} from './instance-progress.mjs';
import {grantTitleState} from '../../src/systems/life/title-rules.js';
import {TITLE_TEXT,titleText,refreshTitleStats} from './titles.mjs';
import {QUEST_CHOSEN} from '../../src/config/engine-chosen-quests.js';

export const FULL_CLEAR_TITLE=Object.freeze({index:27,name:'Agent of 12 Gods',dungeons:Object.freeze({602:"Karon's Fragments (Core)",603:"Karon's Fragments (Hard)"})});
const countable=m=>!!m&&m.kind==='monster'&&!m.isBrick&&m.def?.role!=='invisible';
/** Title index this dungeon can earn (0 = none). Every native fact must still match, else nothing is tracked. */
export function fullClearTitleFor(world,dungeonId){
  const id=String(dungeonId),t=FULL_CLEAR_TITLE;
  if(!QUEST_CHOSEN.title27Dungeons.includes(id))return 0;
  const row=(world.data?.nameplateTitles||[]).find(r=>r.Index===t.index);
  if(row?.Name!==t.name||Number(row.Type)!==9)return 0;
  return world.data?.dungeonData?.dg?.dungeons?.[id]?.name===t.dungeons[id]?t.index:0;
}
// A defeat counts only from the host reward path, for the live member inside this instance; never a GM one-hit or a
// staged GM kill-all copy.
const liveKiller=(world,i,killer)=>!!killer&&world.players.get(killer.account)===killer&&!killer.leaving&&killer.instanceId===i.id&&!(killer.gmAuthorized&&killer.profile?.gm?.onehit);
function earnFullClearTitle(world,p,index){
  const titles=world.data?.nameplateTitles||[],r=grantTitleState(titles,p.profile.life?.titles,index);
  if(!r.granted)return false;
  p.profile.life||={};p.profile.life.titles=r.state;
  world.emit(p.map,{type:'event:message',text:titleText(TITLE_TEXT.earned,titles.find(t=>t.Index===index)?.Name||`#${index}`),recipients:[p.id],actorId:p.id});
  return true;
}
/** One instance step: tag the run's monsters, void the run on any death the host did not reward to a live member, and
 *  once the native clear is reached with every spawned monster defeated, queue the durable grant (once per run). */
export function trackFullClearTitle(world,i){
  if(i.fullClear?.done||!i.scene?.monsters||!i.director)return;
  const run=i.fullClear||={index:fullClearTitleFor(world,i.dungeonId),tagged:new Map(),credited:new Set(),done:false};
  if(!run.index){run.done=true;return;}
  const stop=reason=>{run.done=true;run.stopped=reason;};
  for(const m of i.scene.monsters.values()){
    if(!countable(m)||run.tagged.has(m.id))continue;
    if(m.dead)return stop('death before tracking');
    run.tagged.set(m.id,m);
    const previous=m.onKilled;
    m.onKilled=killer=>{previous?.(killer);if(liveKiller(world,i,killer))run.credited.add(m.id);};
  }
  const population=[...run.tagged.values()];
  if(population.some(m=>m.dead&&!run.credited.has(m.id)))return stop('defeat without a rewarded member');
  const d=i.director;
  if(d.phase==='failed')return stop('failed run');
  if(d.phase!=='cleared'||!population.length||population.some(m=>!m.dead))return;
  if(d.stages?.some(s=>!s.optional&&!s.spawned))return stop('floor not fully spawned');
  run.done=true;run.queued=true;const granted=new Set();
  queueInstanceProgress(world,i,`title:${run.index}:${i.id}`,(p,facade)=>{if(earnFullClearTitle(facade,p,run.index))granted.add(p.id);},()=>{for(const q of world.players.values())if(granted.has(q.id)&&!q.leaving)refreshTitleStats(world,q);});
}
