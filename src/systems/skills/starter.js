/** Only the original free level-one active skill; never fills later learned skills. */
export function starterSkill(list){
 return list.find(skill=>!skill.hidden&&skill.kind==='active'&&skill.tree?.window==='skill'&&Number(skill.levels?.[0]?.reqLevel)<=1&&Number(skill.levels[0].spCost||0)===0&&Number(skill.levels[0].grade||0)===0&&!(skill.levels[0].prereqs||[]).length);
}
export function seedStarterSlot(save,list){
 if(save.starterSkillSeeded)return false;
 const sets=save.quickslot?.sets;
 const pristine=Number(save.level||1)===1&&Number(save.exp||0)===0&&!sets&&!(save.hotbar||[]).some(Boolean);
 if(!save.starterSkillPending&&!pristine)return false;
 const skill=starterSkill(list);if(!skill)return false;
 save.skills ||= {};save.skills[skill.index]=Math.max(1,Number(save.skills[skill.index])||0);
 if(!(save.hotbar||[]).some(Boolean)&&(!sets||!sets.some(set=>(set||[]).some(Boolean)))){
  const entry={type:'skill',index:skill.index};save.hotbar ||= [];save.hotbar[0]=entry;
  if(sets){const set=save.quickslot.rowSet?.[0]??0;sets[set] ||= [];sets[set][0]=entry;}
  else save.quickslot={sets:[Array.from({length:12},(_,i)=>i===0?entry:null),Array(12).fill(null),Array(12).fill(null)],rows:3,rowSet:[0,1,2],fixed:[false,false,false],locked:true,belt:Array(10).fill(null)};
 }
 save.starterSkillSeeded=true;delete save.starterSkillPending;return true;
}
