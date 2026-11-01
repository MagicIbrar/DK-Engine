// Original SIEGE100:42 supplies named costs, levels, durations and cooldowns.
// Castle dungeon message100 binds menu selections to101/102/103 in this order.
// Named native effects are50160–62; unbound markers50175–77 are cataloged only.
export const SIEGE_RENEW_DEFENDER_SKILL_BINDINGS=Object.freeze([
 Object.freeze({selection:0,name:'Guardian',statusIndex:50160,markerIndex:50175,labelCode:51,targetDescription:'all guild members',optionCodes:['COMBINE_OPTION_COMBINE_MUL','DEFENSE_MUL','POSITIVE_ALLRESIST_ADD']}),
 Object.freeze({selection:1,name:'Power',statusIndex:50161,markerIndex:50176,labelCode:52,targetDescription:'all attackers',optionCodes:['SPEED_MOVE_MUL']}),
 Object.freeze({selection:2,name:'Domination',statusIndex:50162,markerIndex:50177,labelCode:53,targetDescription:'all attackers',optionCodes:['ACTION_DISALLOW_MOVE']}),
]);
export const SIEGE_RENEW_DEFENDER_SKILL_DEPENDENCIES=Object.freeze([
 'Native description/status data must be present and match the authored menu requirements.',
]);
const duration=(value,unit)=>Number(value)*(unit.toLowerCase().startsWith('minute')?60000:1000);
/** Returns a catalog only when every authored description/effect/marker is present. */
export function siegeRenewDefenderSkillCatalog(eventData,statuses){
 const text=eventData?.txt?.('stringtable_siege.txt',100,42);if(typeof text!=='string'||!/Only usable by leader of defending guild\./.test(text))return null;
 const result=[];
 for(const binding of SIEGE_RENEW_DEFENDER_SKILL_BINDINGS){
  const section=text.split('<'+binding.name+'>')[1]?.split(/<(?:Guardian|Power|Domination)>/)[0];
  const level=/Guild Level Required:\s*(\d+)/.exec(section||''),cost=/DIL Cost:\s*([\d,]+)/.exec(section||''),cooldown=/Cool time:\s*(\d+)\s*(minutes?|seconds?)/.exec(section||''),time=/Duration:\s*(\d+)\s*(minutes?|seconds?)/.exec(section||'');
  const effect=statuses?.[binding.statusIndex],marker=statuses?.[binding.markerIndex];
  if(!level||!cost||!cooldown||!time||!section.includes(binding.targetDescription)||!effect||!marker||Number(effect.group)!==129||Number(marker.group)!==129||!effect.description?.toLowerCase().includes(binding.name.toLowerCase())||!marker.description?.toLowerCase().includes(binding.name.toLowerCase())||(marker.options||[]).length||JSON.stringify((effect.options||[]).map(o=>o.code))!==JSON.stringify(binding.optionCodes))return null;
  result.push({...binding,guildLevel:Number(level[1]),dil:Number(cost[1].replaceAll(',','')),cooldownMs:duration(cooldown[1],cooldown[2]),durationMs:duration(time[1],time[2]),status:effect,marker,
   association:'NATIVE MENU: castle dungeon message100 selects101/102/103 in Guardian/Power/Domination order; named Group129 effects50160–62. Marker purpose remains unbound; markers are not applied.'});
 }
 return result;
}
