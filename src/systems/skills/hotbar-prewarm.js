// Optional, bounded visual preparation after map entry. Never gates the world
// or spends resources; a cast still uses the normal readiness/authority path.
// dkfps 2026-10-30: chain the next hotbar skill ~120 ms after one finishes (was the 750 ms idle poll per skill: 36 skills took ~27 s,
// so an early first cast still paid the texture/model loads). Still one plan at a time; the idle poll stays 750 ms.
const HOTBAR_CHAIN_MS=120;
export function createHotbarPrewarm(game,engine,makePlan,weaponCompatible){
  let busy=false,disposed=false,next=0;
  const retryAt=new Map();
  function update(now=performance.now()){
    if(disposed||busy||now<next)return;
    next=now+750;
    for(const [key,until]of retryAt)if(until<=now)retryAt.delete(key);
    if(game._worldReady!==true||game._loadingMap||!game.world||!game.player||
       (game.save?.authority==='server'&&!game.network?.ready))return;
    const q=game.save?.quickslot,sets=q?.sets,rows=q?.rowSet;
    if(!Array.isArray(sets)||!Array.isArray(rows))return;
    const style=engine.equippedStyle(),seen=new Set();
    for(const row of rows.slice(0,Math.min(3,Number(q.rows)||0))){
      const slots=sets[row];if(!Array.isArray(slots))continue;
      for(const entry of slots.slice(0,12)){
        const id=Number(entry?.index);if(entry?.type!=='skill'||!Number.isSafeInteger(id)||id<=0||seen.has(id))continue;
        seen.add(id);
        const skill=engine.skillDef(id),level=engine.skillLevel(id);
        if(!skill||!(level>0)||engine.isPassive(skill)||!weaponCompatible(skill,style))continue;
        const key=`${engine.data.classIndex}:${id}:${level}:${style}`;
        if(engine.effectResources.plans.has(key)||(retryAt.get(key)||0)>now)continue;
        engine.warmBodyClips?.(id);   // SKILL-CLIP-COLD: the skill's body clips too (never waits; actor clip cache)
        const plan=makePlan(engine,id);if(!plan)continue;
        busy=true;
        Promise.resolve().then(()=>disposed?null:engine.effectResources.prepare(plan)).catch(()=>{if(!disposed)retryAt.set(key,performance.now()+10000);}).finally(()=>{busy=false;next=Math.min(next,performance.now()+HOTBAR_CHAIN_MS);});
        return;
      }
    }
  }
  return {update,dispose(){disposed=true;retryAt.clear();}};
}
