// NPC point resets on the shared server: Skill Reset (job 7), Attribute Reset (job 120) and Stat Reset (job 13) at the original
// NPCs. Rules: src/game/point-resets.js (exp.csv ClearCount_n / StatClearCost_n DIL, the stat reset count, nothing worn). The
// client only names the reset; the host checks the NPC, recomputes the refund from the server profile and commits it through
// commitLife (life-transactions.mjs), so a failed save leaves the live character unchanged.
import {nearbyNpc,offersOriginalJob} from './npc-services.mjs';
import {ensureSkills} from './skills.mjs';
import {commitLife,serializeLife} from './life-transactions.mjs';
import {RESET_JOBS,RESET_COUNTS,RESET_MSG,STAT_NOTHING_TEXT,resetsUsed,pointResetCost,applyStatReset,statResetErrorCode} from '../../src/game/point-resets.js';

export const POINT_RESET_SCHEMAS=Object.freeze({pointreset:['token','type','kind']});
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status,code:'POINT_RESET_REFUSED'});};
const text=(world,code,named={})=>{let t=String(world.data.skillMessages?.[code]??`(${code})`);for(const[k,v]of Object.entries(named))t=t.replaceAll(`<${k}>`,String(v));return t.replace(/\[message\]/gi,'').replace(/<[^>]+>/g,'').replace(/\s+/g,' ').trim();};
const levelRow=(world,level)=>world.data.exp?.levels?.find(r=>Number(r.level)===Number(level))||null;

export async function pointResetCommand(world,p,input){
  const kind=input.kind;
  if(!Object.hasOwn(RESET_JOBS,kind))fail('Unknown reset.');
  const job=RESET_JOBS[kind],row=nearbyNpc(world,p,{jobType:job});
  if(!row||!offersOriginalJob(world,row,job,row.jobs.find(([type])=>Number(type)===job)?.[1]))fail('Walk near the NPC offering this reset.',403);
  return serializeLife(p,async()=>{
    const before=structuredClone(p.profile),next=structuredClone(before),costs=levelRow(world,before.level);
    let back,cost;
    if(kind==='stat'){
      const result=applyStatReset(next,{base:world.data.classDef(next.classIndex)?.stats?.base,row:costs});
      if(result.error){const code=statResetErrorCode(result.error);fail(code==null?STAT_NOTHING_TEXT:text(world,code,{VALUE:0}));}
      ({back,cost}=result);
    }else{
      // The original reset rule (SkillEngine.resetPoints) on a private copy: the live engine keeps reading the live profile.
      const {engine,game}=ensureSkills(world,p),used=resetsUsed(next,kind);
      cost=pointResetCost(costs,kind,used);
      if((Number(next.dil)||0)<cost)fail(text(world,RESET_MSG.noDil));
      const staged=Object.create(engine);staged._passives=null;
      staged.game={...game,save:next,player:null,events:{emit:()=>{}},refreshPlayerStats:()=>{}};
      back=staged.resetPoints(kind);
      if(!back)fail(text(world,kind==='attribute'?RESET_MSG.attrNone:RESET_MSG.skillNone));
      next[RESET_COUNTS[kind]]=used+1;
    }
    next.dil=Math.max(0,(Number(next.dil)||0)-cost);
    await commitLife(world,p,next,{profileBefore:before});
    // Passive skills and stat points feed the derived stats: rebuild them from the published profile.
    ensureSkills(world,p).engine.refreshPassives();
    world.changed(p);
    return {kind,back,cost,used:resetsUsed(p.profile,kind)};
  });
}
