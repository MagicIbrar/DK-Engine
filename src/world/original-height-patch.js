import {MapDoc} from '../systems/mapbuilder/format.js';
import {sampleHeight} from '../formats/map.js';
const chunkKey = (x, z) => `${Math.floor(x / 32)},${Math.floor(z / 32)}`;

/** Native vertex dependencies, shared by server eligibility and client rendering.
 * Water/decal footprints are excluded until their incremental kernels exist. */
export function heightDependencies(map, indices) {
  const vertices = new Set(), cells = new Set(), chunks = new Set(), X = map.width + 1;
  for (const i of indices) {
    if (!Number.isInteger(i) || i < 0 || i >= X * (map.height + 1)) throw Error('Invalid height vertex.');
    const x = i % X, z = Math.floor(i / X);
    vertices.add(i);
    for (const [dx,dz] of [[-1,0],[1,0],[0,-1],[0,1]]) if (x+dx>=0&&x+dx<=map.width&&z+dz>=0&&z+dz<=map.height) vertices.add((z+dz)*X+x+dx);
    for (let cz = Math.max(0,z-1); cz<=Math.min(map.height-1,z); cz++) for (let cx=Math.max(0,x-1);cx<=Math.min(map.width-1,x);cx++) cells.add(cz*map.width+cx);
  }
  for (const i of vertices) { const x=i%X,z=Math.floor(i/X); for(const cz of new Set([Math.min(map.height-1,z),Math.max(0,z-1)]))for(const cx of new Set([Math.min(map.width-1,x),Math.max(0,x-1)]))chunks.add(chunkKey(cx,cz)); }
  return {vertices,cells,chunks};
}

export function nativeDrapeVertices(map) {
  const blocked = new Set(), X=map.width+1;
  const rect=(x,z,w,h)=>{for(let rz=Math.max(0,z);rz<=Math.min(map.height,z+h);rz++)for(let cx=Math.max(0,x);cx<=Math.min(map.width,x+w);cx++)blocked.add(rz*X+cx);};
  for(const w of map.water||[])for(const cell of w.cells||[])rect(cell%map.width,Math.floor(cell/map.width),1,1);
  for(const d of map.decals||[])if(!d.isNone&&!d.isHole)for(let j=0;j<d.count;j++)if(d.sizes[j])rect(d.cells[j]%map.width,Math.floor(d.cells[j]/map.width),d.sizes[j],d.sizes[j]);
  return blocked;
}

/** Synchronous transaction: no asynchronous resource/actor reload and no collision mask change.
 * A failed component restores exact scalars, normals, matrices, helpers, actors and bounds.
 * Collision uses the existing terrain arrays for Y; .mac/pathfinder identity remains intact. */
export function applyNativeHeightPatch(world, changes, actors=[]) {
  const map=world?.map;
  if(!map||!world.terrain?.updateHeightVertices||!world.objects?.prepareTerrainHeights||!world.objects?.applyTerrainHeights) return {applied:false,reason:'Native height tracking unavailable.'};
  if(!Array.isArray(changes)||changes.length>2048||changes.some(r=>r[0]!=='heights'||!Number.isFinite(r[2])||Math.abs(r[2])>10000))return {applied:false,reason:'Only bounded height changes can update in place.'};
  const seen=new Set();for(const r of changes){if(seen.has(r[1]))throw Error('Duplicate height vertex.');seen.add(r[1]);}
  const dependency=heightDependencies(map,seen);
  if(dependency.chunks.size>16)return {applied:false,reason:'Height patch exceeds 16 terrain chunks.'};
  const drapes=world._originalDrapeVertices||(world._originalDrapeVertices=nativeDrapeVertices(map));
  if([...dependency.vertices].some(i=>drapes.has(i)))return {applied:false,reason:'Native water/decal footprint requires full reconstruction.'};
  const heights=changes.map(([,i])=>[i,map.heights[i]]),normals=[...dependency.vertices].map(i=>[i,map.normals.slice(i*3,i*3+3)]);
  const bodies=[...new Set(actors)].filter(a=>a&&!a.disposed&&Number.isFinite(a.x)&&Number.isFinite(a.z)&&Number.isFinite(a.y)).map(a=>{
    const terrain=sampleHeight(map,a.x,a.z),surface=world.ground?.surfaceAt(a.x,a.z,a.y+1.2);
    const floor=Math.max(terrain,surface?.height??-Infinity);
    // Retain positive clearance above the actor's existing support, including
    // jump/fly offsets. A terrain generation never changes its grounding flag,
    // velocity, animation, knockback or other locomotion state.
    return {a,y:a.y,grounded:a._grounded,clearance:Math.max(0,a.y-floor),terrain,surfaceHeight:surface?.height,surface:surface&&surface.height>terrain?surface.id:null};
  });
  let placements=[],chunks=0;
  const sync=a=>{a._syncGroup?.();a.group?.updateMatrix?.();a.group?.updateMatrixWorld?.(true);};
  try {
    for(const [,i,value]of changes)map.heights[i]=Math.fround(value);
    for(const i of dependency.vertices)MapDoc.prototype.recomputeNormals.call(map,i%map.vertsX,Math.floor(i/map.vertsX),i%map.vertsX,Math.floor(i/map.vertsX));
    placements=world.objects.prepareTerrainHeights(dependency.cells,map.width,map.height);
    world.objects.applyTerrainHeights(placements);
    chunks=world.terrain.updateHeightVertices(dependency.vertices);
    let movedActors=0;
    for(const p of bodies){const terrain=sampleHeight(map,p.a.x,p.a.z),helper=p.surface==null?-Infinity:world.ground.triangleHeightAt(p.surface,p.a.x,p.a.z);if(terrain===p.terrain&&(p.surface==null||helper===p.surfaceHeight))continue;p.moved=true;p.a.y=Math.max(terrain,helper)+p.clearance;sync(p.a);movedActors++;}
    return {applied:true,vertices:seen.size,chunks,placements:placements.length,actors:movedActors};
  } catch(error) {
    for(const [i,y]of heights)map.heights[i]=y;
    for(const [i,n]of normals)map.normals.set(n,i*3);
    const failures=[];
    try{world.objects.applyTerrainHeights(placements,true);}catch(e){failures.push(e.message);}
    try{world.terrain.updateHeightVertices(dependency.vertices);}catch(e){failures.push(e.message);}
    for(const p of bodies)if(p.moved){p.a.y=p.y;p.a._grounded=p.grounded;try{sync(p.a);}catch(e){failures.push(e.message);}}
    if(failures.length)throw Error(`Height update failed; scene reconstruction required: ${failures.join('; ')}`,{cause:error});
    throw error;
  }
}
