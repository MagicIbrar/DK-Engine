// Authoritative counterpart of MonsterBrain's native explore/stand/walk policy (the table's mode EXPLORE).
// Event objects, traps, stop patterns, boss phases, monsters with explore range 0 and WalkSpeed 0 monsters do not roam (unchanged).
// speedMul / flags: the monster's skill statuses (monster-rules.js statusSpeedMul / statusFlags): a rooted monster stands.
//
// After PERSUIT_OUT (core.mjs tick) a monster is simply in EXPLORE again. The data does not say what EXPLORE roams around;
// ENGINE-CHOSEN (engine-chosen-monster-ai.js explore.anchor 'ended'): the
// roaming centre is the spawn (m.home) until a chase ends and the point where it ended (m.anchor, set by the PERSUIT_OUT block of
// core.mjs) afterwards, so after a give-up the monster is inside its own explore area and just roams there: nothing walks back.
// The pursuit range / leash origin is the same point (roamCentre(m), core.mjs): the range follows the monster at every give-up, so a player
// can pull it across the whole map and it never walks back; m.home stays the ORIGINAL spawn and only death (respawn) returns it there.
// A monster that never gave up a chase has no anchor and is not affected at all.
// `away` (a roamer outside its centre's disc) can only be true with anchor 'home' (the old reading) or a monster moved by something
// else (knockback, a map edit); it then picks explore points in the disc as before: WalkSpeed, the normal explore stand delay, no
// speed multiplier, no evade, no heal, never teleported; when the straight leg is blocked it tries the same steering angles as the
// offline brain (src/game/ai.js STEER_ANGLES). A monster that never roamed gets no new movement: it stays where the chase ended.
//
// Lane 27/27b: while an explore step actually moves the record, tag m.moveGait = 'walk' (WalkSpeed). Chase in core.mjs
// uses RunSpeed and tags 'run' via tagMonsterChaseGait; monsterRow spreads monsterRowGait(m) (walk:'peace' for explore).
// Client inferRemoteMonsterWalk remains a fallback when row.walk is omitted (old-protocol). See server/world/monster-gait.mjs.
import {outsideExploreArea,roamCentre} from '../../src/game/monster-rules.js';
import {tagMonsterExploreLeg} from './monster-gait.mjs';   // Lane 60: Global MoveDest destination (row.mv)
const STEER_ANGLES=[.45,-.45,.9,-.9,1.35,-1.35];
export function idleMonster(world,m,map,dt,speedMul=1,flags=null){
 const ai=m.def.ai||{},mul=Number(speedMul)||1,radius=Number(ai.explore)||0,speed=(Number(m.def.speed?.[0])||0)*mul;
 if(flags?.move||m.def.role==='object'||m.def.role==='invisible'||[7,13,1002].includes(ai.pattern)||ai.style==='boss'||(ai.pattern>=20&&ai.pattern<=23)||speed<=0||radius<=0){m.moveGait=null;m.moveTo=null;return;}
 const ctr=roamCentre(m),away=outsideExploreArea(m.def,m,ctr);   // ctr = roaming centre (spawn, or where the last chase ended); only a monster that roams at all (the guard above) can be "away"; no new movement for the others
 const delay=()=>Math.max(0,Number(ai.delays?.[0])||2000)/1000*(.6+world.random()*.8);
 const state=m.idleMove||(m.idleMove={wait:delay()*world.random(),goal:null,time:0});
 if(!state.goal){m.moveGait=null;m.moveTo=null;state.wait-=dt;if(state.wait>0)return;
  for(let i=0;i<8;i++){const angle=world.random()*Math.PI*2,r=radius*Math.sqrt(world.random()),goal={x:ctr.x+Math.cos(angle)*r,z:ctr.z+Math.sin(angle)*r};if(map.isWalkable(goal.x,goal.z)&&(away||!map.collision?.lineOfSight||map.collision.lineOfSight(m.x,m.z,goal.x,goal.z))){state.goal=goal;break;}}
  if(!state.goal){state.wait=delay();return;}
  state.time=0;state.max=Math.max(3,Math.max(radius*2,Math.hypot(state.goal.x-m.x,state.goal.z-m.z))/speed+1);
 }
 const x=m.x,z=m.z;state.time+=dt;
 let arrived=world.step(m,state.goal,speed,dt,map);
 if(!arrived&&away&&m.x===x&&m.z===z){   // blocked on the way back: steer around it as the offline brain does
  const dx=state.goal.x-x,dz=state.goal.z-z,d=Math.hypot(dx,dz)||1,ux=dx/d,uz=dz/d;
  for(const a of STEER_ANGLES){const c=Math.cos(a),s=Math.sin(a);world.step(m,{x:x+(ux*c-uz*s)*2,z:z+(ux*s+uz*c)*2},speed,dt,map);if(m.x!==x||m.z!==z)break;}
 }
 const blocked=m.x===x&&m.z===z;
 m.moveGait = blocked ? null : 'walk';   // explore legs always WalkSpeed (monster.dat); null while blocked this tick
 tagMonsterExploreLeg(m, blocked ? null : state.goal, speed);   // Lane 60: the leg goal is the Global MoveDest destination
 if(arrived||blocked||state.time>(state.max||Math.max(3,radius*2/speed+1))){state.goal=null;state.wait=delay();if(arrived||blocked){m.moveGait=null;m.moveTo=null;}}
}