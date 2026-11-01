// Publish only fields owned by the staged transaction. Cross-player skills can
// legitimately mutate the live recipient while its own simulation is paused.
// Keeping live profile identity also retains transient status source references.
const equal=(a,b)=>JSON.stringify(a)===JSON.stringify(b);
const record=value=>value!==null&&typeof value==='object'&&!Array.isArray(value);
const buffIdentity=b=>b.family!=null?'family:'+b.family:b.key!=null?'key:'+b.key:b.statusIndex!=null?'status:'+b.statusIndex:JSON.stringify(b);
/** Native buffs refresh by family. Apply only this transaction's family delta;
 * never union arbitrary arrays or resurrect a recipient's later removal. */
function publishBuffChanges(live,before,staged){
  const old=new Map(before.map(b=>[buffIdentity(b),b])),next=new Map(staged.map(b=>[buffIdentity(b),b]));
  for(const [id,b]of old){if(next.has(id))continue;const index=live.findIndex(value=>buffIdentity(value)===id);if(index>=0&&(equal(live[index],b)||Number(live[index].remaining)<=0))live.splice(index,1);}
  for(const [id,b]of next){const prior=old.get(id);if(prior&&equal(prior,b))continue;const index=live.findIndex(value=>buffIdentity(value)===id);if(!prior){if(index<0)live.push(structuredClone(b));}else if(index>=0&&equal(live[index],prior))live[index]=structuredClone(b);}
}
export function publishProfileChanges(live,before,staged,nested=false){
  for(const key of new Set([...Object.keys(before),...Object.keys(staged)])){
    if(equal(before[key],staged[key])&&Object.hasOwn(before,key)===Object.hasOwn(staged,key))continue;
    if(!nested&&key==='buffs'&&(Array.isArray(before.buffs)||Array.isArray(staged.buffs))){live.buffs=Array.isArray(live.buffs)?live.buffs:[];publishBuffChanges(live.buffs,before.buffs||[],staged.buffs||[]);continue;}
    if(!Object.hasOwn(staged,key)){delete live[key];continue;}
    if(record(before[key])&&record(staged[key])&&record(live[key]))publishProfileChanges(live[key],before[key],staged[key],true);
    else live[key]=structuredClone(staged[key]);
  }
  return live;
}
export function refreshConcurrentBuffStats(world,p,before){
  if(equal(before.buffs,p.profile.buffs)||!world.data?.stats)return;
  const buffs=[...(p.profile.buffs||[]),...(p._skills?.engine.passiveEntries()||[])];
  p.stats=world.data.stats({...p.profile,buffs},p,world.now());p.maxHp=p.stats.maxHp;
  p.hp=Math.min(p.hp,p.maxHp);p.mp=Math.min(p.mp||0,p.stats.maxMp||0);
}
/** This runs after the original saveQueue task settles, never from inside it.
 * Ownership/reward is already durable; an additional failure cannot roll it back.
 * A newer skill during this save leaves the normal generation dirty for retry. */
export async function persistInterveningProgress(world,players){
  let pending=false;
  for(const p of players){if(!p.dirty)continue;try{await world.persist(p);}catch{pending=true;}}
  return pending||players.some(p=>p.dirty);
}
