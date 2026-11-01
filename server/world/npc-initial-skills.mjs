// Fresh construction only. Reuse the actual server skill adapter; never grant
// points, quest progress, resources or a second initialization to saved actors.
import {ensureSkills,initializeStarterSkills,learnSkill} from './skills.mjs';
const fields=['skills','skillPoints','attrPoints','hotbar','quickslot','starterSkillPending','starterSkillSeeded'];
export function prepareNewNpcSkills(profile,world,{newUnpersistedProfile=false}={}){
 if(!newUnpersistedProfile||profile?.authority!=='server'||profile.npcPlayer!==true||!profile.npcSeed?.readiness||
  ['exp','dil','kills','deaths','playSeconds'].some(k=>profile[k]!==0)||profile.hp!==null||profile.mp!==null||
  profile.starterSkillPending!==true||profile.starterSkillSeeded||Object.keys(profile.skills||{}).length||
  profile.quests||profile.meister||profile.buffs?.length||!Number.isInteger(profile.skillPoints)||profile.skillPoints<0)
  throw Error('Only fresh unpersisted skill profiles');
 if(!world?.data?.skillPacks?.[profile.classIndex]||typeof world.data.stats!=='function'||typeof world.now!=='function')throw Error('Native initial skill context unavailable');
 const next=structuredClone(profile),p={profile:next,id:next.id,characterId:next.id,npcPlayer:true,gmAuthorized:false,map:next.map,channel:0,hp:0,mp:0,x:next.pos.x,z:next.pos.z};
 const local=Object.create(world);local.changed=()=>{};local.emit=()=>{throw Error('Initial learning attempted world effects');};
 initializeStarterSkills(local,p);
 const {engine}=ensureSkills(local,p),pack=world.data.skillPacks[next.classIndex];
 const bound=Object.values(pack.skills||{}).reduce((n,s)=>n+(s.levels?.length||0),0);
 if(!Number.isSafeInteger(bound)||bound>4096)throw Error('Native initial skill budget unavailable');
 let actions=0;
 while(next.skillPoints>0){
  const skills=Object.values(pack.skills||{}).filter(s=>!s.hidden&&s.levels?.length&&engine.canLevel(s.index).ok).sort((a,b)=>Number(!!next.skills[a.index])-Number(!!next.skills[b.index])||(a.levels[0].reqLevel||0));
  if(!skills.length)break;
  if(++actions>bound)throw Error('Native initial learning failed to converge');
  learnSkill(local,p,Number(skills[0].index));
 }
 // Keep adapter-local status/derived state out of the birth profile. Only the
 // ordinary learned fields are transferred; native equipment remains identical.
 const result=structuredClone(profile);
 for(const key of fields){if(Object.hasOwn(next,key))result[key]=structuredClone(next[key]);else delete result[key];}
 return result;
}
