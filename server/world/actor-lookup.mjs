// Canonical player IDs begin with their account key. Retain the legacy fixture
// fallback, without allocating a full population array for every party lookup.
export function findWorldPlayer(world,id){
 if(typeof id!=='string'||!id)return null;
 const colon=id.indexOf(':'),account=colon<0?id:id.slice(0,colon),direct=world.players.get(account);
 if(direct?.id===id&&!direct.leaving)return direct;
 for(const player of world.players.values())if(player.id===id&&!player.leaving)return player;
 return null;
}
