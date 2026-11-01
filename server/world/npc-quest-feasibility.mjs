// ENGINE-CHOSEN bot planning predicates for quests. These never change quest
// eligibility, admission, rewards or the server's validation: a bot only
// declines to PLAN a quest it has no existing way to progress, and an accepted
// quest that cannot be progressed is deferred (transient) or abandoned through
// the ordinary player `abandon` operation (permanent). Every outcome is
// recorded with a reason so a stall is never silent.
import {npcQuestSpawnMap} from './npc-quest-targets.mjs';
// Objective kinds the bot quest step (npc-players quest()) can execute today.
// scripted / clearMap / fish objectives have no bot executor and stay unsupported.
export const NPC_QUEST_RUNNABLE_KINDS=Object.freeze(['talk','kill','killOnMap','collect','useSkill']);
export const NPC_QUEST_STALL_POLICY=Object.freeze({deferMs:60000,maxDeferMs:900000,claimDeferMs:120000,permanentAbandonAfterMs:30000,maxTracked:16});
const placedCache=new WeakMap();
function placed(world,map,npc){
 const rows=world.data.progression?.npcs?.placements?.[Number(map)]?.rows;if(!rows)return false;
 let set=placedCache.get(rows);if(!set){set=new Set(rows.map(r=>Number(r[0])));placedCache.set(rows,set);}
 return set.has(Number(npc));
}
/** Can the bot quest step execute this objective at all (not "right now")? */
export function npcQuestObjectiveRunnable(world,q,o,{classIndex=null}={}){
 if(!o)return {ok:false,reason:'missing-objective',permanent:true};
 if(!NPC_QUEST_RUNNABLE_KINDS.includes(o.kind))return {ok:false,reason:'unsupported-objective:'+o.kind,permanent:true};
 if(o.kind==='talk'){const t=o.targets?.[0];if(!t)return {ok:false,reason:'talk-without-target',permanent:true};const map=t.map??q.giver?.map;return placed(world,map,t.id)?{ok:true}:{ok:false,reason:'talk-npc-not-placed',permanent:true};}
 if(o.kind==='useSkill'){const pack=world.data.skillPacks?.[classIndex]?.skills;const ids=(o.targets||[]).map(t=>Number(t.id));
  // The quest step only casts self-targeted (targetMask 16) skills of the bot's own class.
  return ids.some(id=>pack?.[id]&&Number(pack[id].targetMask)===16)?{ok:true}:{ok:false,reason:'useSkill-not-self-castable',permanent:true};}
 const map=npcQuestSpawnMap(world,q,o,Number(q.giver?.map));
 return map===null?{ok:false,reason:'no-native-field-spawn:'+o.kind,permanent:true}:{ok:true};
}
const feasCache=new WeakMap();
/** Whole-quest planning feasibility (static data only; cached per quest x class). */
export function npcQuestFeasible(world,q,{classIndex=null}={}){
 if(!q)return {ok:false,reason:'unknown-quest',permanent:true};
 let byClass=feasCache.get(q);if(!byClass){byClass=new Map();feasCache.set(q,byClass);}
 const key=String(classIndex);if(byClass.has(key))return byClass.get(key);
 let out={ok:true};
 if(!(q.objectives||[]).length&&!q.require?.instant&&q.kind!=='instant')out={ok:false,reason:'no-objectives',permanent:true};
 else for(const o of q.objectives||[]){const r=npcQuestObjectiveRunnable(world,q,o,{classIndex});if(!r.ok){out={...r,slot:o.slot};break;}}
 if(out.ok){const who=q.turnIn||q.giver;if(!who||!placed(world,who.map??q.giver?.map,who.npc))out={ok:false,reason:'turn-in-npc-not-placed',permanent:true};}
 byClass.set(key,Object.freeze(out));return byClass.get(key);
}
/** The engine's own "never enters the log" rule (talk-only / exchange menus), mirrored for planning. */
export function npcQuestTalkOnly(engine,q){try{return !!engine?.isTalkOnly?.(q);}catch{return false;}}
/**
 * Bounded per-brain stall ledger. Returns what the quest step should do now:
 *   {action:'proceed'} | {action:'defer', until, reason} | {action:'abandon', reason}
 */
export function npcQuestStall(b,questId,{reason,permanent=false,now,claim=false}){
 const P=NPC_QUEST_STALL_POLICY,id=Number(questId);b.questStalls||=new Map();
 let row=b.questStalls.get(id);if(!row){row={since:now,count:0,reason,until:0};b.questStalls.set(id,row);
  if(b.questStalls.size>P.maxTracked){const oldest=[...b.questStalls].sort((a,c)=>a[1].since-c[1].since)[0][0];b.questStalls.delete(oldest);}}
 row.count++;row.reason=reason;row.last=now;
 if(permanent&&!claim&&now-row.since>=P.permanentAbandonAfterMs)return {action:'abandon',reason};
 const base=claim?P.claimDeferMs:P.deferMs;row.until=now+Math.min(P.maxDeferMs,base*2**Math.min(4,row.count-1));
 b.questBlocked={questId:id,reason,until:row.until,permanent:!!permanent};
 return {action:'defer',until:row.until,reason};
}
export function npcQuestDeferred(b,questId,now){const row=b.questStalls?.get(Number(questId));return !!row&&now<row.until;}
export function npcQuestProgressed(b,questId){b.questStalls?.delete(Number(questId));if(b.questBlocked?.questId===Number(questId))b.questBlocked=null;}
