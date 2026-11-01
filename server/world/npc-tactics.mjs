import {ensureSkills} from './skills.mjs';
import {sameScene} from './scene.mjs';
import {nativeStatusEquivalent} from '../../src/systems/skills/statuses.js';

// ENGINE-CHOSEN decisions. Skill effects, costs, timing, targets and item consumption remain native authority rules.
const distance=(a,b)=>Math.hypot(a.x-b.x,a.z-b.z);
export function npcLearnedSkills(world,p){
 const engine=ensureSkills(world,p).engine;
 return Object.keys(p.profile.skills||{}).map(Number).map(id=>engine.skillDef(id)).filter(s=>s&&!engine.isPassive(s)&&engine.skillLevel(s.index)>0).map(s=>({skill:s,level:engine.levelData(s,engine.skillLevel(s.index)),engine}));
}
function outcomes(row){return (row.level?.steps||row.skill.steps||[]).map(s=>s.result).filter(Boolean);}
export function npcHasStatus(world,p,id){return hasStatus(world,p,id);}
function hasStatus(world,p,id){return (p.profile.buffs||[]).some(s=>(Number(s.statusIndex)===Number(id)||s.skillIndex!=null&&nativeStatusEquivalent(world.data.skillStatuses?.[s.statusIndex],world.data.skillStatuses?.[id]))&&(!Number.isFinite(s.remaining)||s.remaining>2));}
function allies(world,p){const party=p.partyId&&world.parties.get(p.partyId);return [...world.players.values()].filter(q=>!q.leaving&&sameScene(p,q)&&(q===p||party?.members.includes(q.id)));}
async function cast(act,p,row,target){
 if(!row.engine.usability(row.skill.index).ok)return false;
 const self=(Number(row.skill.targetMask)&16)!==0&&(Number(row.skill.targetMask)&(2|4|8|32|64))===0;
 try{await act(p,{type:'cast',skillId:Number(row.skill.index),...(self?{}:{targetId:target.id,x:target.x,z:target.z})});return true}catch(e){if(!e.status)throw e;return false;}
}
export async function npcRecovery(world,p,act,{hpRatio=.45,mpRatio=.25}={}){
 const needHp=p.hp<(p.maxHp||p.stats.maxHp)*hpRatio,needMp=p.mp<(p.stats.maxMp||0)*mpRatio;
 if(!needHp&&!needMp)return false;
 const items=[...(p.profile.inventory||[]),...(p.profile.potionBelt||[])];
 for(const item of items){const u=world.data.itemDB?.def(item.itemIndex)?.use;if(!u||!(needHp&&(u.hp||u.hpPct)||needMp&&(u.mp||u.mpPct)))continue;
  try{await act(p,{type:'itemuse',uid:item.uid});return true}catch(e){if(!e.status)throw e;}
 }return false;
}
export function npcAllies(world,p){return allies(world,p);}
export async function npcSupport(world,p,act,{buff=true,priority:order=null}={}){
 const rows=npcLearnedSkills(world,p),engine=ensureSkills(world,p).engine;if(engine.casting)return false;
 const team=allies(world,p).sort(order||((a,b)=>(a.hp/(a.maxHp||a.stats.maxHp||1))-(b.hp/(b.maxHp||b.stats.maxHp||1))));
 // Resurrection and healing take priority over optional pre-buffing. A dead ally remains subject to normal native range/target gates.
 for(const q of team){if(distance(p,q)>24)continue;
  for(const row of rows){const results=outcomes(row),mask=Number(row.skill.targetMask)||0;
   if(q.dead&&q!==p&&(mask&32)&&results.some(r=>r.family==='resurrect')){if(await cast(act,p,row,q))return true;}
   if(!q.dead&&q.hp<(q.maxHp||q.stats.maxHp)*.65&&results.some(r=>['heal','heal_area','heal_party'].includes(r.family))&&(q===p?mask&(2|16):mask&2)){if(await cast(act,p,row,q))return true;}
  }
 }
 if(!buff)return false;
 // ENGINE-CHOSEN preparation preference: a legal native party aura that fills
 // missing useful effects for at least two actual members precedes single buffs.
 // Healing/resurrection above, and all native cast/range/resource gates, remain.
 const party=p.partyId&&world.parties.get(p.partyId),priority=new Map(rows.map(row=>{
  const results=outcomes(row),mask=Number(row.skill.targetMask)||0,helpful=results.filter(r=>r.durationMs>=5000&&Number(world.data.skillStatuses?.[r.statusIndex]?.property)===1),radius=Math.max(0,...results.map(r=>Number(r.radius)||0));
  const legal=!!party?.members.includes(p.id)&&row.engine.usability(row.skill.index).ok&&!!(mask&(2|16))&&!(mask&(4|32|64))&&results.length>0&&results.every(r=>['status','area_status_party'].includes(r.family))&&results.some(r=>r.target==='party')&&helpful.length>0;
  return [row,legal&&team.filter(q=>!q.dead&&party.members.includes(q.id)&&distance(p,q)<=radius&&helpful.some(r=>!hasStatus(world,q,r.statusIndex))).length>=2?1:0];
 }));
 for(const row of rows.sort((a,b)=>priority.get(b)-priority.get(a))){const results=outcomes(row),mask=Number(row.skill.targetMask)||0;
  if(!(mask&(2|16))||(mask&(4|32|64))||!results.length||results.some(r=>!['status','area_status_party'].includes(r.family)))continue;
  const helpful=results.filter(r=>r.durationMs>=5000&&Number(world.data.skillStatuses?.[r.statusIndex]?.property)===1);
  if(!helpful.length)continue;
  const target=(mask&16)?p:team.find(q=>!q.dead&&distance(p,q)<=Number(row.skill.range||3)&&helpful.some(r=>!hasStatus(world,q,r.statusIndex)))||p;
  const recipients=results.some(r=>r.target==='party')?team.filter(q=>!q.dead&&distance(p,q)<=Math.max(...results.map(r=>Number(r.radius)||0))):[target];
  if(!recipients.some(q=>helpful.some(r=>!hasStatus(world,q,r.statusIndex))))continue;
  if(await cast(act,p,row,target))return true;
 }return false;
}
export function npcAttackSkills(world,p){
 return npcLearnedSkills(world,p).filter(row=>!(Number(row.skill.targetMask)&(2|32))&&outcomes(row).some(r=>['damage','remote','projectile','servant_explode'].includes(r.family))).sort((a,b)=>(b.level?.reqLevel||0)-(a.level?.reqLevel||0));
}
