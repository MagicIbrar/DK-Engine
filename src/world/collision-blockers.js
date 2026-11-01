// Dynamic blockers share cell ownership. The last release restores the original
// attribute mask, even when overlapping objects open in a different order.
const masks=new WeakMap();
export function blockCollisionCells(collision,indices){
  if(!collision?.cells)return ()=>{};
  let mask=masks.get(collision);if(!mask){mask=new Map();masks.set(collision,mask);}
  const owned=[];
  for(const i of new Set(indices)){
    if(!Number.isInteger(i)||i<0||i>=collision.cells.length)continue;
    const cell=mask.get(i)||{base:collision.cells[i],count:0};cell.count++;mask.set(i,cell);collision.cells[i]=1;owned.push(i);
  }
  let released=false;
  return ()=>{if(released)return;released=true;for(const i of owned){const cell=mask.get(i);if(!cell)continue;if(--cell.count===0){collision.cells[i]=cell.base;mask.delete(i);}else collision.cells[i]=1;}if(!mask.size)masks.delete(collision);};
}
