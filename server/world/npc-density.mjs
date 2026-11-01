import {mapFor} from './scene.mjs';
import {isDkChannel} from '../../src/systems/channels/channel-rules.js';

// ENGINE-CHOSEN NPC population policy, not a Global spawn-density assertion.
// All area inputs are native collision walkability. Count the human's reachable
// component and connected local area, rather than terrain rectangle dimensions.
export const NPC_NONHUB_LIMIT=35;
const AREA_BANDS=[[4096,6],[16384,12],[65536,24],[Infinity,NPC_NONHUB_LIMIT]],AREA_LIMIT=65537,LOCAL_RADIUS=48,CACHE_MS=5000;
const cache=new WeakMap(),localCache=new WeakMap();
function flood(collision,x,z,{radius=Infinity,limit=AREA_LIMIT,probe=null}={}) {
 const w=collision.width,h=collision.height,cells=collision.cells,cx=Math.floor(x),cz=Math.floor(z),start=cz*w+cx;
 if(cx<0||cz<0||cx>=w||cz>=h||cells[start]!==0)return 0;
 const left=Math.max(0,cx-radius),right=Math.min(w-1,cx+radius),top=Math.max(0,cz-radius),bottom=Math.min(h-1,cz+radius),span=right-left+1;
 // Local floods allocate only their clipped window. Reread native cells on
 // every call so topology changes immediately constrain the global cache.
 const seen=new Uint8Array(span*(bottom-top+1)),queue=new Uint32Array(Math.min(limit,seen.length));let head=0,count=1;
 seen[(cz-top)*span+cx-left]=1;queue[0]=start;
 while(head<count&&count<limit){const i=queue[head++],ix=i%w,iz=Math.floor(i/w);
  for(let direction=0;direction<4;direction++){
   const nx=ix+(direction===0?-1:direction===1?1:0),nz=iz+(direction===2?-1:direction===3?1:0);
   if(nx<left||nz<top||nx>right||nz>bottom)continue;
   const n=nz*w+nx,v=(nz-top)*span+nx-left;if(cells[n]!==0||seen[v])continue;seen[v]=1;queue[count++]=n;if(count>=limit)break;
  }
 }if(probe){const px=Math.floor(probe.x),pz=Math.floor(probe.z);probe.reached=px>=left&&px<=right&&pz>=top&&pz<=bottom&&seen[(pz-top)*span+px-left]===1;}return count;
}
// Compare native local bytes before reusing a flood. Native editors and gates
// may change a Uint8Array in place, so object identity/time alone is unsafe.
// This bounds each hit to the 97x97 local window with no per-hit allocation.
function localFlood(collision,x,z,probe){
 const cx=Math.floor(x),cz=Math.floor(z),w=collision.width,h=collision.height,cells=collision.cells;
 const left=Math.max(0,cx-LOCAL_RADIUS),right=Math.min(w-1,cx+LOCAL_RADIUS),top=Math.max(0,cz-LOCAL_RADIUS),bottom=Math.min(h-1,cz+LOCAL_RADIUS),span=right-left+1;
 if(cx<0||cz<0||cx>=w||cz>=h)return 0;
 let memo=localCache.get(collision),same=!!memo&&memo.cx===cx&&memo.cz===cz&&memo.cells===cells&&memo.w===w&&memo.h===h&&memo.px===(probe?.x??null)&&memo.pz===(probe?.z??null);
 if(same){let i=0;for(let z=top;same&&z<=bottom;z++)for(let x=left;x<=right;x++)if(memo.bytes[i++]!==cells[z*w+x]){same=false;break;}}
 if(!same){const count=flood(collision,x,z,{radius:LOCAL_RADIUS,limit:(LOCAL_RADIUS*2+1)**2,probe}),bytes=new Uint8Array(span*(bottom-top+1));let i=0;for(let z=top;z<=bottom;z++)for(let x=left;x<=right;x++)bytes[i++]=cells[z*w+x];memo={cx,cz,w,h,cells,bytes,count,px:probe?.x??null,pz:probe?.z??null,reached:probe?.reached===true};localCache.set(collision,memo);}
 if(probe)probe.reached=memo.reached;return memo.count;
}
export function npcDensityMetrics(world,anchor,policy={}) {
 const none={density:0,reachableCells:0,reachableIsLowerBound:false,localCells:0};
 if(!anchor||anchor.npcPlayer||anchor.profile?.npcPlayer||anchor.leaving||anchor.dead||anchor.sceneTransition||anchor.instanceId||isDkChannel(anchor.channel)||world.data.requiresInstance?.(anchor.map)||world.players.get(anchor.account)!==anchor)return none;
 const map=mapFor(world,anchor),collision=map?.collision;
 if(!collision?.hasData||!collision.cells||!Number.isSafeInteger(collision.width)||!Number.isSafeInteger(collision.height)||collision.width*collision.height!==collision.cells.length)return none;
 // A nearby cached anchor must still be in this exact local component.
 // Bucket equality alone does not establish connectivity across native walls.
 let recent=cache.get(collision);const probe=recent?{x:recent.x,z:recent.z,reached:false}:null;
 const localCells=localFlood(collision,anchor.x,anchor.z,probe);if(!localCells)return none;
 const bucket=`${Math.floor(anchor.x/32)}:${Math.floor(anchor.z/32)}`,now=world.now();
 if(!recent||!probe.reached||recent.bucket!==bucket||now-recent.at>=CACHE_MS||now<recent.at){recent={bucket,at:now,x:Math.floor(anchor.x),z:Math.floor(anchor.z),count:flood(collision,anchor.x,anchor.z)};cache.set(collision,recent);}
 const target=AREA_BANDS.find(([max])=>recent.count<=max)[1],localCap=Math.max(6,Math.floor(localCells/128)),requested=Number(policy.maxPerScene??policy.total??42),ceiling=Number.isFinite(requested)?Math.max(0,Math.floor(requested)):42;
 // ENGINE-CHOSEN: only Ardeca's very large verified connected town can host
 // the larger crowd. Fields and smaller towns keep their existing local bound.
 const row=world.data.mapRow?.(anchor.map),town=Number(row?.PeaceZone)===1&&Number(row?.PcStore)===1;
 const ardecaCrowd=town&&Number(anchor.map)===150&&recent.count>=AREA_LIMIT;
 const areaTarget=ardecaCrowd?70:target;
 return {density:Math.min(ardecaCrowd?70:NPC_NONHUB_LIMIT,ceiling,areaTarget,town?areaTarget:localCap),reachableCells:recent.count,reachableIsLowerBound:recent.count===AREA_LIMIT,localCells};
}
export const npcSceneDensity=(world,anchor,policy={})=>npcDensityMetrics(world,anchor,policy).density;

// ENGINE-CHOSEN user population preference. Scale only within the existing
// native-area and server caps; it never expands collision areas or instances.
export function npcScaledDensity(density,percentage=100,maxDensity=42){
 const count=Math.max(0,Math.min(Math.max(0,Math.floor(Number(maxDensity)||0)),Math.floor(Number(density)||0))),value=Number(percentage);
 const scale=Number.isInteger(value)&&value>=10&&value<=100?value:100;
 return count?Math.max(1,Math.ceil(count*scale/100)):0;
}
