import {canonicalNpc} from './npc-human-slots.mjs';
import {npcEventTeamSelection} from './npc-event-parties.mjs';
import {partyWarWindow} from '../../src/systems/events/partywar-clock.js';
import {createNpcEventResourceBudget} from './npc-event-resource-budget.mjs';
import {npcRoutePlan} from './npc-routing.mjs';
import {channelData} from './channels.mjs';
import {dkLocates,dkMap} from '../../src/systems/channels/channel-rules.js';
import {npcReachableApproach} from './npc-navigation.mjs';

// Native bounded searches may stop short on long field routes. The endpoint
// is only an ordinary walking goal, never proof of service arrival. Existing
// move validation and the original service command remain authoritative.
export function npcEventWalkStage(map,p,target){
 if(!map||![p?.x,p?.z,target?.x,target?.z].every(Number.isFinite))return null;
 if(p.path?.length){const end=p.path.at(-1);return Number.isFinite(end?.x)&&Number.isFinite(end?.z)?{map:p.map,x:end.x,z:end.z}:null;}
 const goal=map.isWalkable?.(target.x,target.z)?target:map.nearest?.(target.x,target.z);if(!goal)return null;
 const path=map.path?.(p.x,p.z,goal.x,goal.z),end=path?.at(-1);
 if(!end||!map.isWalkable?.(end.x,end.z)||Math.hypot(end.x-goal.x,end.z-goal.z)>=Math.hypot(p.x-goal.x,p.z-goal.z)-.5)return null;
 // At most two original path waypoints per decision. A partial endpoint is
 // not itself assumed reachable by another bounded search.
 for(const index of [...new Set([Math.min(7,path.length-1),0])]){const at=path[index];if(!map.isWalkable(at.x,at.z)||Math.hypot(at.x-goal.x,at.z-goal.z)>=Math.hypot(p.x-goal.x,p.z-goal.z)-.5)continue;if(npcReachableApproach(map,p,at,1))return {map:p.map,x:at.x,z:at.z};}
 return null;
}

// A finite appropriate-level subset travels through original Deneb job96 and
// returns through original job97. Prior intent is planner-only, never a profile
// snapshot or replay of accepted quest/resources. Native DK entry breaks parties.
export function createNpcChainFireAttendance(world,{act,move,canAttend,capture,resume,yieldToHuman=()=>false,onError=()=>{}}){
 const groups=new Set(),budget=createNpcEventResourceBudget(world);let next=0;
 const current=m=>world.players.get(m.player.account)===m.player&&m.player.token===m.token&&!m.player.leaving&&!m.player.revoked;
 const groupFor=p=>[...groups].find(g=>g.members.some(m=>!m.done&&m.player===p&&current(m)));
 const row=map=>(world.data.progression?.npcs?.placements?.[map]?.rows||[]).find(r=>Number(r[0])===(map===3?5362:5359));
 const action=async(p,input)=>{try{return await act(p,input);}catch(e){if(!e.status)throw e;onError(e,p);return null;}};
 async function finish(g,m){
  const p=m.player;if(!current(m)||yieldToHuman(p)){m.done=true;return;}
  if(p.instanceId){await action(p,{type:'event',operation:'exit'});return;}
  if(p.map===84){const at=row(84);if(!at){m.reason='native return NPC unavailable';return;}if(Math.hypot(p.x-Number(at[1]),p.z-Number(at[2]))>8){await move(p,{map:84,x:Number(at[1]),z:Number(at[2]),channel:p.channel});return;}await action(p,{type:'channel',operation:'dkleave',npcIndex:5359});if(p.map===84)return;}
  const party=p.partyId&&world.parties?.get(p.partyId);
  if(party&&m.eventParty===party.id&&party.members.every(id=>g.members.some(q=>q.player.id===id)))await action(p,{type:'party',operation:'leave'});
  resume(p,m.intent);m.done=true;
 }
 return {
  async tick(){
   const now=world.now();
   for(const g of [...groups]){
    if(now>=g.deadline||!g.reservation.valid()&&!g.members.some(m=>current(m)&&m.player.instanceId))g.returning=true;
    for(const m of g.members){if(m.done)continue;if(!current(m)){m.done=true;continue;}const p=m.player;
     if(yieldToHuman(p)){m.done=true;g.returning=true;continue;}
     if(p.partyId&&world.parties?.get(p.partyId)?.members.every(id=>g.members.some(q=>q.player.id===id)))m.eventParty=p.partyId;
     if(p.instanceId){m.entered=true;if(g.returning)await finish(g,m);continue;}
     if(m.entered||g.returning){await finish(g,m);continue;}
     if(!canAttend(p,{reserved:true})){g.returning=true;await finish(g,m);continue;}
     if(p.map===84)continue;
     const plan=npcRoutePlan(world,p,g.destination);if(plan.blockedReason){m.reason=plan.blockedReason;g.returning=true;await finish(g,m);continue;}
     await move(p,g.destination);
    }
    if(g.members.every(m=>m.done)){g.reservation.release();groups.delete(g);}
    else if(!g.members.some(m=>current(m)&&m.player.instanceId)&&now>=g.window.end)g.returning=true;
   }
   if(now<next||groups.size>=2)return;next=now+30000;
   const window=partyWarWindow(world.data.eventData?.modes?.deadFront,now,{upcoming:true});if(!window||window.register-now>300000||now>=window.closed)return;
   // Only the proven active DK lobby. Never activate native-disabled map45.
   if(Number(world.data.mapRow?.(84)?.isUseMap)!==1||!row(3)||!row(84))return;
   const locate=dkLocates(channelData(world),84)[0];if(!locate)return;
   const nativeLocate=dkMap(channelData(world),84)?.locate;if(!nativeLocate?.every(Number.isFinite))return;
   const destination={map:84,x:nativeLocate[0]+.5,z:nativeLocate[1]+.5,channel:locate.channel};
   const mode=world.data.eventData.modes.deadFront,live=new Set(world.data.eventData.solo?.deadFront?.liveMaps||[]);
   selection:for(let attempt=groups.size;attempt<2;attempt++){
   for(const tier of mode.tiers||[])for(const option of tier.maps||[]){
    if(option.variant!=='dk'||!option.officerPlaced||!live.has(option.map))continue;
    const field=world.data.eventData.field('deadFront',option.map),band=field?.entryLevel||option.entryLevel,max=Math.min(2,Math.max(0,Number(field?.maxParties)-1));
    if(!Number.isInteger(max)||[...groups].filter(g=>g.targetMap===option.map&&g.window.cycle===window.cycle).length>=max)continue;
    const pool=[...world.players.values()].filter(p=>!groupFor(p)&&canonicalNpc(p)&&canAttend(p)&&p.profile.level>=option.registrationLevel[0]&&p.profile.level<=option.registrationLevel[1]&&p.profile.level>=band[0]&&p.profile.level<=band[1]&&!npcRoutePlan(world,p,destination).blockedReason);
    if(pool.length<7)continue;const picked=npcEventTeamSelection(world.data,pool,7),deadline=window.end+2700000;if(picked.length!==7)continue;
    const reservation=await budget.acquire(picked,{map:84,until:deadline});if(!reservation)continue;
    const members=picked.map(player=>({player,token:player.token,intent:capture(player),done:false,entered:false}));groups.add({members,reservation,destination,window,deadline,targetMap:option.map,returning:false});continue selection;
   }
   break;
   }
  },
  handles:p=>!!groupFor(p)&&!p.instanceId,
  retains:p=>!!groupFor(p),
  teamFor:p=>groupFor(p)?.members.filter(m=>!m.done&&current(m)).map(m=>m.player)||null,
  snapshot:()=>[...groups].map(g=>({members:g.members.filter(m=>current(m)&&!m.done).length,returning:g.returning,deadline:g.deadline,entered:g.members.filter(m=>m.entered).length,reasons:[...new Set(g.members.map(m=>m.reason).filter(Boolean))]})),
  dispose(){for(const g of groups)g.reservation.release();groups.clear();},
 };
}
