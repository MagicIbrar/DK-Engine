// Server-issued recovery survives lease replacement, logout and process restart.
// Client join/action bodies cannot supply this record; it is read only from the canonical profile.
import {movementState} from './movement-authority.mjs';
const finite=value=>typeof value==='number'&&Number.isFinite(value);
function phase(value){
  if(!value||typeof value.key!=='string'||value.key.length>256||!Number.isInteger(value.step)||value.step<0||value.step>63||
    ![value.speed,value.slot,value.wallAt,value.timing?.next,value.timing?.hitAt,value.timing?.len].every(finite)||value.speed<=0||value.timing.next<0||value.timing.hitAt<0)return null;
  return {key:value.key,step:value.step,speed:value.speed,slot:value.slot,wallAt:value.wallAt,timing:{next:value.timing.next,hitAt:value.timing.hitAt,len:value.timing.len}};
}
export function captureRejoinRecovery(world,p,activeSeconds=0){
  const out={version:1};
  for(const key of ['attackAt','lastCombat','respawnReadyAt'])if(finite(p[key]))out[key]=p[key];
  const step=phase(p._attackStepAuthority);if(step)out.attackStep=step;
  const castUntil=Math.max(Number(p._rejoinCastUntil)||0,activeSeconds>0?world.now()+activeSeconds*1000:0);
  if(castUntil>world.now())out.castUntil=castUntil;
  const mv=p.mv;
  if(mv&&finite(mv.budget)&&finite(mv.budgetAt)){
    out.movement={budget:mv.budget,budgetAt:mv.budgetAt};
    for(const key of ['peakSpeed','peakAt'])if(finite(mv[key]))out.movement[key]=mv[key];
  }
  return out;
}
export function restoreRejoinRecovery(world,p){
  const saved=p.profile.combatRecovery;
  if(!saved||saved.version!==1)return;
  for(const key of ['attackAt','lastCombat'])if(finite(saved[key]))p[key]=saved[key];
  if(p.dead&&finite(saved.respawnReadyAt))p.respawnReadyAt=saved.respawnReadyAt;
  const step=phase(saved.attackStep);if(step)p._attackStepAuthority=step;
  if(finite(saved.castUntil)&&saved.castUntil>world.now())p._rejoinCastUntil=saved.castUntil;
  const m=saved.movement;
  if(m&&finite(m.budget)&&finite(m.budgetAt)){
    const mv=movementState(world,p);mv.budget=m.budget;mv.budgetAt=m.budgetAt;
    for(const key of ['peakSpeed','peakAt'])if(finite(m[key]))mv[key]=m[key];
  }
}
