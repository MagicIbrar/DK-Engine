// Dialogue may describe a pull only when the actor has a real reason to fight
// and a reachable, living monster on this scene. A seed goal alone is not one.
import {npcReachableApproach} from './npc-navigation.mjs';
export function npcCanDiscussPull(world, player, brain, map) {
  if (!player || !map?.monsters || Number(map.index)!==Number(player.map) || player.dead || player.leaving || player.sceneTransition || player.instanceId) return false;
  // Reuse the actual farm/quest selection. Speech neither chooses a new
  // target nor pathfinds the monster catalog; masks are checked at selection
  // of speech/invitation, without a cached connectivity assumption.
  const target=map.monsters.get(brain?.target||brain?.farmTarget);
  if(!target||target.dead||target.isBrick||target.eventObject||target.def?.role!=='creature'||!(Number(target.def.exp)>0)||!Number.isFinite(target.x)||!Number.isFinite(target.z)||Math.hypot(target.x-player.x,target.z-player.z)>=35)return false;
  const active = player.profile?.quests?.active || {};
  const killQuest = Object.keys(active).some(id => {
    const quest = world.data.progression?.quests?.quests?.[id];
    return quest?.objectives?.some(objective => {
      if (!['kill', 'killOnMap'].includes(objective.kind)) return false;
      const state=active[id],count=Number(objective.count),slot=Number(objective.slot);
      if(Array.isArray(state?.s)&&Number.isInteger(slot)&&count>0&&Number(state.s[slot])>=count)return false;
      if(objective.map!=null&&Number(objective.map)!==Number(player.map))return false;
      return (objective.targets||[]).some(row=>Number(row.id)===Number(objective.kind==='killOnMap'?player.map:target.monsterIndex)&&(row.map==null||Number(row.map)===Number(player.map)));
    });
  });
  const farming=brain?.taskGoal?.kind==='farm'&&Number(brain.taskGoal.map)===Number(player.map);
  if(!farming&&!killQuest)return false;
  return !!npcReachableApproach(map,player,target,1);
}
