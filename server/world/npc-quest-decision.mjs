// ENGINE-CHOSEN bounded planning, never a quest eligibility/admission change.
export const NPC_QUEST_DECISION_POLICY=Object.freeze({paths:2,retryMs:10000});
export function npcQuestDecision({quests,seedId,slot=0,level=1,map,eligible,reachable,planning,context={},now=0}){
 const sourceX=Math.floor(Number(context.sourceX)||0),sourceZ=Math.floor(Number(context.sourceZ)||0),key=[map,level,seedId,slot,sourceX,sourceZ,context.conditionRevision??''].join(':');
 if(planning.catalog!==quests||planning.key!==key||planning.scene!==context.map||planning.collision!==context.map?.collision||planning.path!==context.map?.path||planning.profile!==context.profile){
  const seed=quests?.[seedId],offered=q=>q&&!q.isGroup&&!q.hidden;
  const candidates=Object.values(quests||{}).filter(q=>q!==seed&&Number(q.giver?.map)===Number(map)&&offered(q)).sort((a,b)=>Math.abs((a.level?.[0]||1)-level)-Math.abs((b.level?.[0]||1)-level));
  const offset=Math.max(0,Math.trunc(Number(slot)||0))%Math.max(1,Math.min(6,candidates.length));
  Object.assign(planning,{catalog:quests,key,scene:context.map,collision:context.map?.collision,path:context.map?.path,profile:context.profile,rows:[...(offered(seed)?[seed]:[]),...candidates.slice(offset),...candidates.slice(0,offset)],cursor:0,retryAt:0,selected:null});
 }
 let paths=0;if(planning.selected){const selected=planning.selected;planning.selected=null;if(eligible(selected)){paths++;if(reachable(selected)){planning.selected=selected;return selected;}}}
 if(now<planning.retryAt)return null;if(planning.cursor>=planning.rows.length){planning.cursor=0;planning.retryAt=0;}
 while(planning.cursor<planning.rows.length&&paths<NPC_QUEST_DECISION_POLICY.paths){const q=planning.rows[planning.cursor++];if(!eligible(q))continue;paths++;if(reachable(q)){planning.selected=q;return q;}}
 if(planning.cursor>=planning.rows.length)planning.retryAt=now+NPC_QUEST_DECISION_POLICY.retryMs;
 return null;
}
