// Dead Front's nine final boxes are only available after the boss and final
// party battle. A sole admitted team wins uncontested; otherwise place 1 wins.
export function canClaimDeadFrontTreasure(world, player, monster) {
  if (!monster?.eventTreasure) return true;
  const run = player?.instanceId && world.instances?.get(player.instanceId);
  if (!run || run.kind !== 'deadFront' || run.id !== monster.instanceId || !run.run?.won) return false;
  const team = run.teams?.find(t => t.ids.has(player.id));
  if (!team) return false;
  return (run.startingTeamCount ?? run.teams.length) < 2 || team.place === 1;
}
