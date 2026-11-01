// A quick slot is a reference. Its payload can never contain an inventory item,
// quantity, generated UID, reward or resource mutation.
function refuse(message) { throw Object.assign(new Error(message), {status:400}); }
export function quickslotEntry(world, player, engine, entry, {itemsOnly=false}={}) {
  if(entry===null)return null;
  if(!entry||typeof entry!=='object'||Array.isArray(entry))refuse('Invalid quick slot reference.');
  if(entry.type==='skill'&&!itemsOnly){
    if(Object.keys(entry).some(k=>!['type','index'].includes(k))||!Number.isInteger(entry.index)||engine.learnedLevel(entry.index)<=0)refuse('Choose a learned skill for this quick slot.');
    return {type:'skill',index:entry.index};
  }
  if(entry.type==='item'){
    if(Object.keys(entry).some(k=>!['type','itemIndex'].includes(k))||!Number.isInteger(entry.itemIndex)||!world.data.itemDB?.def(entry.itemIndex))refuse('Choose an existing item for this shortcut.');
    return {type:'item',itemIndex:entry.itemIndex};
  }
  refuse(itemsOnly?'The item belt only accepts items.':'Invalid quick slot type.');
}
export function quickslotLayout(world,player,engine,input){
  if(!input||typeof input!=='object'||Array.isArray(input)||Object.keys(input).some(k=>!['sets','belt','rows','rowSet','fixed','locked'].includes(k)))refuse('Invalid quick slot layout.');
  if(!Array.isArray(input.sets)||input.sets.length!==3||input.sets.some(row=>!Array.isArray(row)||row.length!==12)||!Array.isArray(input.belt)||input.belt.length!==10)refuse('Quick slots require three rows and ten item belt cells.');
  if(!Number.isInteger(input.rows)||input.rows<1||input.rows>3||!Array.isArray(input.rowSet)||input.rowSet.length!==3||new Set(input.rowSet).size!==3||input.rowSet.some(n=>!Number.isInteger(n)||n<0||n>2)||!Array.isArray(input.fixed)||input.fixed.length!==3||input.fixed.some(v=>typeof v!=='boolean')||typeof input.locked!=='boolean')refuse('Invalid quick slot settings.');
  return {sets:input.sets.map(row=>row.map(entry=>quickslotEntry(world,player,engine,entry))),belt:input.belt.map(entry=>quickslotEntry(world,player,engine,entry,{itemsOnly:true})),rows:input.rows,rowSet:[...input.rowSet],fixed:[...input.fixed],locked:input.locked};
}
