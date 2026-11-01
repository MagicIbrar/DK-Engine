// Ephemeral index for one ordinary roster sync. Preserve Array.find's earliest
// OR-match, including conflicting bindings; the caller owns all validation,
// error handling and durable publication. No profiles or rewards are created.
export function createNpcEarnedRowIndex(rows) {
  const ids=new Map(),profiles=new Map(),accounts=new Map(),names=new Map(),unbound=new Set();
  const fold=value=>String(value).toLowerCase();
  const add=(map,key,index)=>{let positions=map.get(key);if(!positions)map.set(key,positions=new Set());positions.add(index);};
  const remove=(map,key,index)=>{const positions=map.get(key);if(!positions)return;positions.delete(index);if(!positions.size)map.delete(key);};
  const first=positions=>{let at=Infinity;for(const index of positions||[])at=Math.min(at,index);return at;};
  const lookup=(map,key)=>Number.isNaN(key)?Infinity:first(map.get(key));
  const include=index=>{const row=rows[index];add(ids,row.npcRosterId,index);add(profiles,row.binding?.profileId,index);add(accounts,row.binding?.account,index);if(!row.binding){unbound.add(index);add(names,fold(row.name),index);}};
  const exclude=index=>{const row=rows[index];remove(ids,row.npcRosterId,index);remove(profiles,row.binding?.profileId,index);remove(accounts,row.binding?.account,index);if(!row.binding){unbound.delete(index);remove(names,fold(row.name),index);}};
  rows.forEach((_,index)=>include(index));
  return {
    match(account,profile){
      const id=profile.npcRosterId||profile.npcSeed?.rosterId;
      let index=Math.min(lookup(ids,id),lookup(profiles,profile.id),lookup(accounts,account));
      if(index===Infinity)index=first(names.get(fold(profile.name)));
      return index===Infinity?-1:index;
    },
    vacant(held){let at=Infinity;for(const index of unbound)if(!held.has(rows[index].npcRosterId))at=Math.min(at,index);return at===Infinity?-1:at;},
    replace(index,row){exclude(index);rows[index]=row;include(index);return row;},
    assign(index,updated){exclude(index);Object.assign(rows[index],updated);include(index);return rows[index];},
  };
}
