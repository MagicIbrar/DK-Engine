// Human connections replace NPC connections; canonical saved identities remain.
export const canonicalNpc=p=>/^npc_[a-f0-9]{32}$/.test(p?.account)&&p.profile?.authority==='server'&&p.profile?.npcPlayer===true&&p.characterId===p.profile.id&&p.id===p.account+':'+p.profile.id;
export function npcSlotTarget(world,cap){
 const humans=[...world.players.values()].filter(p=>!canonicalNpc(p)).length,pending=[...(world.npcHumanReservations||[])].filter(account=>!world.players.has(account)).length;
 return Math.max(0,cap-humans-pending);
}
export function npcSlotsAvailable(world,count=1,admittingAccounts=[]){
 if(!Number.isInteger(world.npcSlotCapacity))return true;
 if(typeof world.npcPendingAdmissionAccounts==='function'){
  const owners=new Set(world.players.keys()),admitting=new Set(admittingAccounts);
  for(const account of world.npcHumanReservations||[])owners.add(account);
  for(const account of world.npcPendingAdmissionAccounts())if(!admitting.has(account)||world.players.has(account))owners.add(account);
  return owners.size+count<=world.npcSlotCapacity;
 }
 let pending=0;for(const account of world.npcHumanReservations||[])if(!world.players.has(account))pending++;
 return world.players.size+pending+count<=world.npcSlotCapacity;
}
// A held native admission owns its account until publication or cancellation.
// Count unique owners at the human handoff; never discount a victim whose save
// has not actually removed it. NPC final checks add their own staged count and
// therefore identify their own staged accounts to avoid counting tickets twice.
function humanAdmissionFits(world){
 if(!Number.isInteger(world.npcSlotCapacity)||typeof world.npcPendingAdmissionAccounts!=='function')return true;
 const held=world.npcPendingAdmissionAccounts();
 // Human-only admission retains its existing configured cap/owner rules.
 // This fence governs capacity shared with live or still-owned NPC work.
 if(!held.length&&![...world.players.values()].some(canonicalNpc))return true;
 const owners=new Set(world.players.keys());
 for(const account of world.npcHumanReservations||[])owners.add(account);
 for(const account of held)owners.add(account);
 return owners.size<=world.npcSlotCapacity;
}
function requireHumanAdmissionFits(world){
 if(!humanAdmissionFits(world))throw Object.assign(Error('Bots are finishing reserved admissions. Please retry joining shortly.'),{status:503});
}
export async function reserveHumanNpcSlot(world,account,{random=Math.random,maxHumans=Infinity}={}){
 if(world.players.has(account))return ()=>{};
 const reservations=world.npcHumanReservations||(world.npcHumanReservations=new Set()),claimed=world.npcHumanVictims||(world.npcHumanVictims=new Set());
 if(reservations.has(account))throw Object.assign(Error('This account is already joining.'),{status:409});
 reservations.add(account);let victim;
 const release=()=>{reservations.delete(account);if(victim)claimed.delete(victim.account);};
 try{
  const humans=[...world.players.values()].filter(p=>!canonicalNpc(p)).length,pending=[...reservations].filter(a=>!world.players.has(a)).length;
  if(humans+pending>maxHumans)throw Object.assign(Error('This server is full. Please retry joining later.'),{status:503});
  const bots=[...world.players.values()].filter(p=>canonicalNpc(p)&&!p.leaving&&!claimed.has(p.account));
  if(!bots.length){requireHumanAdmissionFits(world);return release;}
  const eligible=bots.filter(p=>!p.commandActive&&!p.progressCommitting&&!p.sceneTransition&&!p.tradeId&&!p.tradeCommitting&&!p.pcShopOpen&&!p.instanceId&&!p.attackTarget&&!p._skills?.engine.active&&!p._skills?.engine.queued&&!world.npcHumanSlotProtected?.(p));
  if(!eligible.length)throw Object.assign(Error('Bots are finishing protected actions. Please retry joining shortly.'),{status:503});
  const value=Number(random());victim=eligible[Math.min(eligible.length-1,Math.max(0,Math.floor((Number.isFinite(value)?value:0)*eligible.length)))];claimed.add(victim.account);
  await world.leave(victim.account,victim.token);
  if(world.players.get(victim.account)===victim)throw Object.assign(Error('The bot could not save and release its player slot.'),{status:503});
  requireHumanAdmissionFits(world);
  return release;
 }catch(error){release();throw error;}
}
