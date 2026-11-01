// Aggregate active server leases only. No names, accounts, profiles or identities
// are returned; durable/offline roster rows do not count as connected players.
export function playerPopulation(world,{isNpc}={}){
 let realPlayers=0,botPlayers=0;
 if(!(world?.players instanceof Map))return {players:0,realPlayers,botPlayers};
 for(const [account,p]of world.players){
  if(!p||p.leaving||p.revoked||p.account!==account)continue;
  const canonical=typeof account==='string'&&/^npc_[a-f0-9]{32}$/.test(account)&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true;
  const bot=canonical&&(typeof isNpc!=='function'||isNpc(p)===true);
  if(bot)botPlayers++;else realPlayers++;
 }
 return {players:realPlayers+botPlayers,realPlayers,botPlayers};
}
