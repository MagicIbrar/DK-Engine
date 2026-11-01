import {ensureSkills} from './skills.mjs';
import {npcLearnedSkills} from './npc-tactics.mjs';
import {mapFor} from './scene.mjs';

// ENGINE-CHOSEN companion decisions. Ordinary cast/order commands retain native
// learning, weapon stance, mana, cooldown, target, summon and totem authority.
export async function npcCompanionSupport(world,p,act,{prepare=false,target=null}={}){
 if(!p.profile.npcPlayer||p.profile.authority!=='server'||p.dead)return false;
 const sys=ensureSkills(world,p),{engine,game,summons}=sys;if(engine.active||engine.casting)return false;
 const enemy=target&&!target.dead&&mapFor(world,p)?.monsters.get(target.id)===target?target:null;
 if(!prepare&&!enemy)return false;
 const rows=npcLearnedSkills(world,p).sort((a,b)=>(b.level?.reqLevel||0)-(a.level?.reqLevel||0));
 const results=row=>(row.level?.steps||row.skill.steps||[]).map(step=>step.result).filter(Boolean);
 const cast=async(row,to)=>{if(!engine.usability(row.skill.index).ok)return false;const mask=Number(row.skill.targetMask)||0,selfOnly=(mask&16)&&!(mask&(2|4|8|32|64));
  try{await act(p,{type:'cast',skillId:Number(row.skill.index),...(selfOnly?{}:{targetId:to.id,x:to.x,z:to.z})});return true;}catch(e){if(!e.status)throw e;return false;}
 };
 const servant=summons.servantOf(game.player);
 if(!servant)for(const row of rows){const result=results(row).find(r=>r.family==='summon');if(!result||!engine.data.servant(result.servantIndex))continue;if(await cast(row,p))return true;}
 if(servant&&enemy&&(summons.mode!=='attack'||servant.target?._record?.id!==enemy.id)){
  try{await act(p,{type:'summonOrder',order:'attack',targetId:enemy.id});return true;}catch(e){if(!e.status)throw e;}
 }
 if(servant&&enemy&&!servant.pendingGreat&&summons.greatBlock(servant)&&summons.greatCharge(servant)>=1){
  try{await act(p,{type:'summonGreat',targetId:enemy.id});return true;}catch(e){if(!e.status)throw e;}
 }
 for(const row of rows){const result=results(row).find(r=>r.family==='totem'),def=result&&engine.data.totem(result.totemIndex);if(!def?.aura)continue;
  const helpful=def.aura.target==='party'||Number(world.data.skillStatuses?.[def.aura.statusIndex]?.property)===1;if(!enemy&&!helpful)continue;
  const center=helpful?p:enemy;if(!center)continue;
  // Native totem families replace by name. Keep the living aura at this fight;
  // move it only when the owner/target has actually left the authored radius.
  if(summons.totems.some(t=>t.alive&&t.owner===game.player&&t.def.name===def.name&&Math.hypot(t.x-center.x,t.z-center.z)<=Number(def.aura.radius||0)))continue;
  if(await cast(row,center))return true;
 }
 return false;
}
