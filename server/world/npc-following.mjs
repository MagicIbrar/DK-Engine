import {sameScene,sceneKey} from './scene.mjs';

// ENGINE-CHOSEN human escort spacing/hysteresis. Native movement, speed,
// collision and combat admission remain authoritative; this only chooses goals.
export const NPC_FOLLOW_POLICY=Object.freeze({minimumGap:2.8,settleGap:3.6,resumeGap:6.2,goalChange:.9,leaderMotion:.25});
// ENGINE-CHOSEN explicit "follow" escort targets the leader point for lures.
// Native terrain/path authority decides reachability. Speed/admission never change.
export const NPC_CLOSE_FOLLOW_POLICY=Object.freeze({minimumGap:0,settleGap:.35,resumeGap:.75,goalChange:.2,leaderMotion:.05,lateralGap:0,rowGap:0,leaderPoint:true,continuous:true});
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);

/** A stable escort goal, or a settled hold. Never changes an actor's position. */
export function npcFollowPlan(player,leader,brain,{map,now=Date.now(),policy=NPC_FOLLOW_POLICY}={}){
 if(!player||!leader||player===leader||!sameScene(player,leader)||!map)return null;
 if(brain.closeFollow&&policy===NPC_FOLLOW_POLICY)policy=NPC_CLOSE_FOLLOW_POLICY;
 const key=leader.id+':'+sceneKey(leader.map,leader.instanceId,leader.channel);
 let state=brain.followMotion;
 if(state?.key!==key)state=brain.followMotion={key,x:leader.x,z:leader.z,heading:null,settled:false,goal:null};
 const dx=leader.x-state.x,dz=leader.z-state.z,moved=Math.hypot(dx,dz)>policy.leaderMotion;
 if(moved)state.heading={x:dx/Math.hypot(dx,dz),z:dz/Math.hypot(dx,dz)};
 const moving=!!leader.path?.length||moved,gap=distance(player,leader);
 state.x=leader.x;state.z=leader.z;state.at=now;
 // Once settled, small leader position changes do not reopen a path. Stop an
 // obsolete path, rather than walking past the idle leader then turning back.
 if(!moving&&gap>=policy.minimumGap&&gap<=policy.resumeGap){
  state.settled=true;state.goal=null;
  return {kind:player.path?.length?'stop':'hold',gap};
 }
 if(moving&&gap<=policy.settleGap){
  if(policy.continuous&&player.path?.length)return {kind:'continue',gap,at:state.goal};
  state.settled=true;return {kind:player.path?.length?'stop':'hold',gap};
 }
 state.settled=false;
 const ordinal=Number(player.profile?.npcSeed?.slot)||0;
 const heading=state.heading||{x:-Math.sin(Number(leader.yaw)||0),z:-Math.cos(Number(leader.yaw)||0)};
 const lateral=((ordinal%3)-1)*(policy.lateralGap??1.8),behind=policy.leaderPoint?0:policy.settleGap+Math.floor(ordinal/3)%2*(policy.rowGap??.6);
 let target={x:leader.x-heading.x*behind-heading.z*lateral,z:leader.z-heading.z*behind+heading.x*lateral};
 // A follower already beside a stationary leader backs away along its own
 // radial direction once; it does not orbit around to a new formation slot.
 if(!moving&&gap<policy.minimumGap&&gap>.1)target={x:leader.x+(player.x-leader.x)/gap*behind,z:leader.z+(player.z-leader.z)/gap*behind};
 if(!policy.leaderPoint&&!moving&&state.goal&&distance(state.goal,leader)>=policy.minimumGap&&distance(state.goal,leader)<=policy.resumeGap)target=state.goal;
 const at=map.isWalkable?.(target.x,target.z)?target:map.nearest?.(target.x,target.z);
 if(!at||distance(at,leader)<policy.minimumGap||distance(at,leader)>policy.resumeGap)return {kind:player.path?.length?'stop':'hold',gap,blocked:true};
 if(player.path?.length&&state.goal&&distance(state.goal,at)<policy.goalChange)return {kind:'continue',gap,at:state.goal};
 state.goal={x:at.x,z:at.z};return {kind:'move',gap,at:state.goal};
}
