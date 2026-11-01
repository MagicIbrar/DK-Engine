import {sceneKey} from './scene.mjs';
import {isDkChannel} from './channels.mjs';

// ENGINE-CHOSEN scheduling of existing ordinary actors, never simulated rewards.
export const NPC_BACKGROUND_WORK_POLICY=Object.freeze({maxLeases:6,leaseMs:120000,maxTracked:42});
export function npcBackgroundWorkEligible(world,p,b){
 if(!p||!b||p.leaving||p.dead||p.npcPlayer!==true||p.profile?.npcPlayer!==true||p.profile?.authority!=='server'||!p.account||!p.id||p.instanceId||isDkChannel(p.channel)||p.pcShopOpen||p.tradeId||p.sceneTransition)return false;
 if(world.players?.get(p.account)!==p||world.data.requiresInstance?.(p.map)||world.data.eventData?.modeOf?.(p.map)||Number(world.data.mapRow?.(p.map)?.IsSiege))return false;
 const quest=Number(b.questId),accepted=Number.isInteger(quest)&&quest>0&&Object.hasOwn(p.profile.quests?.active||{},String(quest));
 const map=world.maps?.get(sceneKey(p.map,p.instanceId,p.channel)),target=map?.monsters?.get(p.attackTarget||b.farmTarget||b.target);
 const farm=b.taskGoal?.kind==='farm'&&target&&!target.dead&&Number(target.hp)>0;
 const path=Array.isArray(p.path)&&p.path.length>0&&Number.isFinite(p.path[0]?.x)&&Number.isFinite(p.path[0]?.z);
 return !!(accepted||farm||path);
}
export function createNpcBackgroundWork(world,options={}){
 const finite=(v,fallback,min,max)=>Number.isFinite(v)?Math.max(min,Math.min(max,Math.trunc(v))):fallback;
 const policy={maxLeases:finite(options.maxLeases,6,0,6),leaseMs:finite(options.leaseMs,120000,1,120000),maxTracked:finite(options.maxTracked,42,1,42)},states=new Map();let lastNow=0,cursor=0;
 const now=()=>{const value=Number(world.now());if(Number.isFinite(value))lastNow=Math.max(lastNow,value);return lastNow;};
 const exhaust=s=>{s.active=false;s.exhausted=true;delete s.player;delete s.brain;};
 const expire=()=>{const at=now();for(const s of states.values())if(s.active&&at>=s.until)exhaust(s);};
 return{
  observe(p,b,{occupied=false,protected:protectedActor=false}={}){
   expire();const id=p?.account;if(!id)return false;let s=states.get(id);
   if(occupied){states.delete(id);return false;}
   if(protectedActor){if(s)exhaust(s);return false;}
   if(!npcBackgroundWorkEligible(world,p,b)){if(s)exhaust(s);return false;}
   const scene=sceneKey(p.map,p.instanceId,p.channel);
   if(s){if(s.exhausted)return false;if(s.scene!==scene||s.player!==p){exhaust(s);return false;}s.brain=b;return true;}
   if(states.size>=policy.maxTracked)return false;
   const other=Math.max(0,Math.min(policy.maxLeases,Math.trunc(Number(options.additionalWorkers?.())||0)));
   if([...states.values()].filter(v=>v.active).length+other>=policy.maxLeases){states.set(id,{scene,active:false,exhausted:true});return false;}
   s={scene,until:now()+policy.leaseMs,active:true,exhausted:false,player:p,brain:b};states.set(id,s);return true;
  },
  next(players=world.players){
   expire();const entries=[...states.entries()];if(!entries.length)return null;
   for(let n=0;n<entries.length;n++){const i=(cursor+n)%entries.length,[id,s]=entries[i];if(!s.active)continue;
    if(players.get(id)!==s.player||s.scene!==sceneKey(s.player.map,s.player.instanceId,s.player.channel)||!npcBackgroundWorkEligible(world,s.player,s.brain)){exhaust(s);continue;}
    cursor=(i+1)%entries.length;return {player:s.player,brain:s.brain};
   }return null;
  },
  owns(p){
   expire();const s=states.get(p?.account);if(!s?.active)return false;
   if(s.player!==p||world.players.get(p.account)!==p||s.scene!==sceneKey(p.map,p.instanceId,p.channel)||!npcBackgroundWorkEligible(world,p,s.brain)){exhaust(s);return false;}
   return true;
  },
  forget(account){states.delete(account);},
  clear(){states.clear();cursor=0;},
  snapshot(){expire();return {policy:'ENGINE-CHOSEN actual ordinary actor work only',...policy,active:[...states.values()].filter(s=>s.active).length,exhausted:[...states.values()].filter(s=>s.exhausted).length,tracked:states.size};},
 };
}
