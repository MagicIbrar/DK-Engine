import {createHash} from 'node:crypto';
import {parseMap} from '../../src/formats/map.js';
import {parseBrickCSV,parseCallMonsterCSV} from '../../src/formats/spawn.js';
import {footprintCells} from '../../src/systems/dungeons/bricks.js';
import {heightDependencies,nativeDrapeVertices} from '../../src/world/original-height-patch.js';
const expected={map:'caa74a8a6b8e9ccf93095007564a6079c55308bfec7ec2ea91360c9ae5d1acaf',mac:'ad5619a1f78d43cccbe3638f5ac5a95c9323f6cd3c2f09b9d6bf870e680e1c4a',mol:'487433f0e1bbf4689442ec6707948733ddf187c331ec512acdaa20efc6d6a418',bricks:'00b1e5f3e61f91303387ffc4dcfccef6b30838e4067183670d50afdf793cbe32',callMonsters:'8633eedd66339f55f20b1f9530ab9e280facfa86af0e73baff27afb8473aafde'};
const sizes={36899:[1,1],36900:[1,1],36901:[1,1],36902:[2,2],36903:[2,2],36904:[2,2],36905:[2,2],36906:[3,3],36907:[3,3],36908:[3,3],36909:[3,3],36970:[2,2]};
const fail=message=>{throw Object.assign(Error(message),{status:409});};
/** Narrow engine-authoring scope for the audited native Ardeca generation.
 * Native script tables are immutable; this does not implement the missing official map script. */
export function ardecaHeightScope({index,files,brickDefs,npcs=[],gates=[]}) {
  if(index!==150)fail('This protected original scope supports Ardeca 150 only.');
  for(const [key,sha]of Object.entries(expected))if(!files[key]||createHash('sha256').update(files[key]).digest('hex')!==sha)fail(`Ardeca ${key} source changed; review protected terrain scope.`);
  const map=parseMap(files.map),bricks=parseBrickCSV(files.bricks),calls=parseCallMonsterCSV(files.callMonsters);
  if(!map.knownVersion||map.width!==512||map.height!==512||map.trailing||calls.mapIndex!==150||calls.calls.length||calls.randomCalls.length||calls.randomPositions.length||bricks.length!==46)fail('Ardeca native scope no longer matches its audited tables.');
  const forbidden=nativeDrapeVertices(map),protectedCells=new Set(),X=map.vertsX;
  const rectangle=(x0,z0,x1,z1)=>{if(![x0,z0,x1,z1].every(Number.isFinite))fail('Unknown original protected position.');for(let z=Math.max(0,Math.floor(z0));z<=Math.min(map.height-1,Math.ceil(z1));z++)for(let x=Math.max(0,Math.floor(x0));x<=Math.min(map.width-1,Math.ceil(x1));x++)protectedCells.add(z*map.width+x);};
  for(const p of bricks){const size=brickDefs?.[p.brickIndex]?.size;if(!sizes[p.brickIndex]||JSON.stringify(size)!==JSON.stringify(sizes[p.brickIndex])||![p.x,p.y,p.direction].every(Number.isFinite))fail('Unknown original brick footprint.');for(const c of footprintCells({collision:map},p.x,p.y,p.direction,size))rectangle(c.x-1,c.z-1,c.x+1,c.z+1);}
  if(!Array.isArray(npcs)||npcs.length!==90||!Array.isArray(gates)||gates.length!==3)fail('The audited Ardeca NPC and zone-gate tables are required.');
  // Engine safety margin around native NPC services/warp points and zone gates.
  for(const n of npcs){rectangle(Number(n[1])-2,Number(n[2])-2,Number(n[1])+2,Number(n[2])+2);if(Number(n[4])>1&&Number(n[5])>1)rectangle(Number(n[4])-2,Number(n[5])-2,Number(n[4])+2,Number(n[5])+2);}
  for(const box of gates){if(!Array.isArray(box)||box.length!==4||!box.every(Number.isFinite)||box[0]>box[2]||box[1]>box[3])fail('Unknown original zone-gate footprint.');rectangle(box[0]-1,box[1]-1,box[2]+1,box[3]+1);}
  for(const i of protectedCells){const x=i%map.width,z=Math.floor(i/map.width);for(const [dx,dz]of [[0,0],[1,0],[0,1],[1,1]])forbidden.add((z+dz)*X+x+dx);}
  // A changed vertex also changes normals at its four cardinal neighbours.
  const protectedVertices=new Set(forbidden);
  for(const i of forbidden){const x=i%X,z=Math.floor(i/X);for(const [dx,dz]of [[-1,0],[1,0],[0,-1],[0,1]])if(x+dx>=0&&x+dx<=map.width&&z+dz>=0&&z+dz<=map.height)protectedVertices.add((z+dz)*X+x+dx);}
  const sorted=[...protectedVertices].sort((a,b)=>a-b),runs=[];for(const i of sorted){const prior=runs.at(-1);if(prior&&prior[0]+prior[1]===i)prior[1]++;else runs.push([i,1]);}
  if(protectedVertices.size>=X*(map.height+1))fail('No supported Ardeca terrain remains.');
  return {format:'ardeca-height-scope@1',fields:['heights'],width:map.width,height:map.height,protectedRuns:runs,protectedVertices:protectedVertices.size,editableVertices:X*(map.height+1)-protectedVertices.size,brickPlacements:bricks.length,npcPlacements:npcs.length,zoneGates:gates.length,reason:'Height brushes only. Native bricks, NPC services, warp/gate areas, water and decals are protected; collision and script tables remain intact.'};
}

export function validateScopedChanges(scope,doc,changes,{batch=true}={}) {
  if(!scope)return;
  if(scope.format!=='ardeca-height-scope@1'||scope.width!==doc.width||scope.height!==doc.height)fail('Invalid original protected scope.');
  const blocked=scope.protectedRuns;
  for(const [field,i]of changes){if(field!=='heights')fail(scope.reason);let low=0,high=blocked.length-1;while(low<=high){const mid=(low+high)>>1,[start,count]=blocked[mid];if(i<start)high=mid-1;else if(i>=start+count)low=mid+1;else fail('This terrain vertex is protected by a native structure, service, water or decal footprint.');}}
  if(batch&&heightDependencies(doc,changes.map(r=>r[1])).chunks.size>16)fail('Keep each shared height batch within 16 native terrain chunks.');
}
