// ENGINE-CHOSEN selection fairness, not native cooldowns or certified Global
// rotations. lastUsed is authored SkillEngine history: it changes only after
// a cast passes ordinary native target/style/resource gates and really starts.
export const NPC_REPERTOIRE_WINDOW_MS=Object.freeze({novice:3000,regular:6000,expert:12000,elite:16000});

export function npcRepertoireOrder(scored,{ability='regular',lowMana=false,engine,now,openings=new Set()}={}){
 const window=NPC_REPERTOIRE_WINDOW_MS[ability]??NPC_REPERTOIRE_WINDOW_MS.regular;
 const recent=s=>{
  const at=engine?.lastUsed?.get(Number(s.row.skill.index));
  return Number.isFinite(at)?Math.max(0,window-Math.max(0,now-at*1000)):0;
 };
 const conserve=ability==='novice'||lowMana,advanced=ability==='expert'||ability==='elite';
 // With depleted MP, a fresh affordable alternative still wins on native cost.
 // If all affordable attacks were used recently, conserve mana with the
 // director's ordinary basic-attack fallback. No native cooldown is changed.
 const attacks=scored.filter(s=>s.group===1),cheapest=Math.min(...attacks.map(s=>s.cost));
 if(lowMana&&attacks.length&&scored.every(s=>s.group<2)&&attacks.filter(s=>s.cost===cheapest).every(s=>recent(s)>0))return [];
 return [...scored].sort((a,b)=>b.group-a.group
  ||(conserve?a.cost-b.cost:0)
  ||recent(a)-recent(b)
  ||(advanced?Number(openings.has(b.row.skill.index))-Number(openings.has(a.row.skill.index)):0)
  ||(conserve?0:b.level-a.level)
  ||a.row.skill.index-b.row.skill.index);
}
