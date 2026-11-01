import {ensureSkills} from './skills.mjs';

/** Authored share/article/partypvpbuff.csv. Duplicate base selection is
 * engine-chosen; the inspected Global table has one row per base. */
export function parsePartyPvpBuffs(text) {
  const lines=String(text).split(/\r?\n/).filter(line=>line.trim()),header=lines.shift()?.split(',').map(s=>s.trim())||[];
  const required=['Index','StatusIndex','BaseStatusIndex','ItemIndex'];
  if(required.some(key=>!header.includes(key)))throw Error('partypvpbuff.csv is missing a required column.');
  const seen=new Set();
  return lines.map(line=>{
    const cells=line.split(','),row=Object.fromEntries(required.map(key=>[key,Number(cells[header.indexOf(key)])]));
    if(required.some(key=>!Number.isSafeInteger(row[key])||row[key]<=0)||seen.has(row.Index))throw Error('partypvpbuff.csv contains an invalid or duplicate buff.');
    seen.add(row.Index);return {index:row.Index,status:row.StatusIndex,base:row.BaseStatusIndex,item:row.ItemIndex};
  });
}

export function selectPartyPvpBuff(rows,selected,index,enabled) {
  if(!Number.isSafeInteger(index)||typeof enabled!=='boolean')throw Error('Choose a listed Party Match buff.');
  const row=rows.find(r=>r.index===index);if(!row)throw Error('Choose a listed Party Match buff.');
  const next=new Set(selected||[]);
  if(enabled){for(const other of rows)if(other.base===row.base)next.delete(other.index);next.add(index);}
  else next.delete(index);
  return [...next];
}

/** 1008:40: old item/recovery buffs are consumed, not restored after the match. */
export function clearPartyPvpBuffs(world,p) {
  const sys=ensureSkills(world,p);
  sys.statuses.remove(sys.game.player,()=>true,'silent');
  p.profile.buffs=[];world.changed(p);
}
export function applyPartyPvpBuffs(world,p,rows,selected,durationMs) {
  const sys=ensureSkills(world,p),choices=new Set(selected||[]);
  for(const row of rows)if(choices.has(row.index)&&!sys.data.status(row.status))throw Error(`Party Match status ${row.status} is unavailable.`);
  clearPartyPvpBuffs(world,p);
  for(const row of rows)if(choices.has(row.index)){
    const entry=sys.statuses.add(sys.game.player,row.status,durationMs,{source:sys.game.player});
    if(!entry)throw Error(`Party Match status ${row.status} could not be applied.`);
    entry.partyPvpBuff=true;entry.mapMoveDelete=true;
  }
  world.changed(p);
}
