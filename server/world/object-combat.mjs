// A solid server-created object may be hit at an exposed edge, never through other walls.
export function objectHitPoint(map,source,target){
 if(!target?.isBrick||!Array.isArray(target.objectFootprint)||!map?.collision)return null;
 const col=map.collision,owned=new Set(target.objectFootprint.map(c=>c.i)),candidates=[];
 for(const cell of target.objectFootprint)for(const[dx,dz]of[[1,0],[-1,0],[0,1],[0,-1]]){const x=cell.x+dx,z=cell.z+dz,i=z*col.width+x;if(owned.has(i)||!col.walkableCell(x,z))continue;candidates.push({x:x+.5,z:z+.5});}
 candidates.sort((a,b)=>Math.hypot(source.x-a.x,source.z-a.z)-Math.hypot(source.x-b.x,source.z-b.z));
 return candidates.find(point=>col.lineOfSight(source.x,source.z,point.x,point.z))||null;
}
