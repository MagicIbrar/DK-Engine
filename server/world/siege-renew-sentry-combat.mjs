// Host sentries use decoded native attack results and the shared skill/projectile
// interpreter. No client-supplied result data or guessed average-damage shortcut.
import {SkillEngine} from '../../src/systems/skills/engine.js';
import {SkillData} from '../../src/systems/skills/data.js';
import {optionSum} from '../../src/systems/skills/statuses.js';
import {resolveAttack,elementResistance,modifyHitDamage} from '../../src/game/combat.js';
import {applyAbilityCap} from '../../src/game/ability-cap.js';
import {actorFor,ensureSkills,incomingSkillDamage} from './skills.mjs';
import {siegeRenewGuardCanTarget} from './siege-renew-sentries.mjs';
import {furyHurt} from './fury.mjs';
import {trackForcedDisplacement} from './movement-authority.mjs';
// ENGINE-CHOSEN distance: match the existing skill interpreter's 1.5m knockback.
// Native 1100331 proves the reaction type/radius, but does not author distance.
export function knockbackSiegeRenewGuardTarget(world,m,p){
 if(!siegeRenewGuardCanTarget(world,m,p)||optionSum(p.profile?.buffs||[],'KNOCKBACK_OFF')>0)return false;
 const map=world.siegeRenewLive?.battles?.get(m.map)?.scene,dx=p.x-m.x,dz=p.z-m.z,d=Math.hypot(dx,dz);if(!map||d<.001)return false;
 const start={x:p.x,z:p.z};let x=p.x,z=p.z;
 for(let step=1;step<=6;step++){const nx=start.x+dx/d*step*.25,nz=start.z+dz/d*step*.25;if(!map.isWalkable(nx,nz)||map.collision?.lineOfSight&&!map.collision.lineOfSight(x,z,nx,nz))break;x=nx;z=nz;}
 if(x===p.x&&z===p.z)return false;p.x=x;p.z=z;p.path=[];trackForcedDisplacement(world,p);world.changed(p);return true;
}
class SentryEngine extends SkillEngine {
 _hostile(actor){return !!actor?._record&&siegeRenewGuardCanTarget(this.game._world,this.game._guard,actor._record);}
 unitsNear(point,radius,_ref,side='enemy'){if(side!=='enemy')return [];return [...this.game._world.players.values()].filter(p=>siegeRenewGuardCanTarget(this.game._world,this.game._guard,p)&&Math.hypot(p.x-point.x,p.z-point.z)<=radius+.25).map(p=>ensureSkills(this.game._world,p).game.player);}
 applyImpact(ctx,result,unit,point,extra){if(!this.game._guard.dead&&!this.game._guard.disposed)super.applyImpact(ctx,result,unit,point,extra);}
 _secondary(ctx,r,target){super._secondary(ctx,r,target);if(r.knockback&&this.game._lastHit?.target===target&&this.game._lastHit.amount>0)knockbackSiegeRenewGuardTarget(this.game._world,this.game._guard,target._record);}
 skillDamage(ctx,target,r){
  const res=resolveAttack(ctx.caster,target,{attackKey:ctx.attackKey,kind:r.damageClass,addDamage:Number(r.addDamage)||0,multiplier:Number(r.damagePct)>0?Number(r.damagePct)/100:1,data:this.game.data,deferFinalModifiers:true});
  if(res.miss||!res.amount)return res;let amount=res.amount;
  if(r.element&&['fire','ice','lightning','poison','curse','dark'].includes(r.element)){const part=amount*(Number(r.elementPct)||100)/100;amount-=part*elementResistance(target,r.element,{fire:1,ice:2,lightning:3,poison:4,curse:5,dark:6}[r.element])/100;}
  res.amount=modifyHitDamage(ctx.caster,target,amount);return res;
 }
}
function runtime(world,m){
 if(m._guardCombat)return m._guardCombat;
 const data=new SkillData();data.common=world.data.skillCommon||{};data.pack={};data._wantFull=()=>{};
 for(const [id,row]of Object.entries(world.data.skillFull?.remotes||{}))data.remotes.set(Number(id),row);
 for(const [id,row]of Object.entries(world.data.skillStatuses||{}))data.statuses.set(Number(id),row);
 const game={_world:world,_guard:m,save:{},data:{formula:world.data.formula||{}},time:world.now()/1000,player:actorFor(world,m,'monster'),world:{heightAt:()=>0},events:{emit(type,e){
  const p=(e.target||e.actor)?._record;if(!p?.profile)return;
  if(type==='damage'){game._lastHit={target:e.target,amount:e.amount};p.lastCombat=world.now();world.changed(p);if(e.amount>0)furyHurt(world,p);world.emit(m.map,{type:'damage',sourceId:m.id,targetId:p.id,amount:e.amount,dead:p.hp<=0,miss:!!e.miss,crit:!!e.crit,guard:!!e.guard,block:!!e.block,instanceId:m.instanceId});}
  if(type==='death'){p.path=[];p.profile.deaths=(p.profile.deaths||0)+1;world.changed(p);void world.persist(p).catch(()=>{});}
 }}};
 game.combatHooks={beforeDamage:[(_source,target,result)=>{const p=target._record;if(!siegeRenewGuardCanTarget(world,m,p)||p.gmAuthorized&&p.profile.gm?.god){result.amount=0;result.miss=true;return;}const cap=applyAbilityCap(world.data.abilityCap?.(m.map),{attackerLevel:m.def.level,defenderLevel:p.profile.level,attackerIsPlayer:false,kind:result.kind==='magic'?'magic':'melee'},result.amount,()=>world.random());result.amount=cap.miss?0:incomingSkillDamage(world,p,m,cap.amount,result.kind);result.miss=cap.miss;} ]};
 const statuses={listOf:a=>a.statuses||[],value:(a,key)=>optionSum(a.statuses||[],key),has(a,key){return this.value(a,key)>0;},add(a,index,ms,options){const p=a?._record;if(!p?.profile||!siegeRenewGuardCanTarget(world,m,p)||p.gmAuthorized&&p.profile.gm?.god)return null;return ensureSkills(world,p).statuses.add(a,index,ms,options);}};
 const engine=new SentryEngine(game,{data,statuses,fx:null});game.skills=engine;m._guardCombat=engine;return engine;
}
export function attackSiegeRenewGuard(world,m,target,attackKey){
 if(!siegeRenewGuardCanTarget(world,m,target))return false;
 const result=m.def.attackResults?.[attackKey];if(!result||result.family==='unknown'||result.family==='projectile'&&!world.data.skillFull?.remotes?.[result.remoteIndex])return false;
 const engine=runtime(world,m),actor=ensureSkills(world,target).game.player;engine.game.time=world.now()/1000;
 engine.applyResult({caster:engine.game.player,target:actor,point:{x:target.x,z:target.z},level:1,attackKey,skill:{targetMask:4,type:result.damageClass||(/range/i.test(attackKey)?'range':'melee')}},result);
 if(result.family==='projectile')world.emit(m.map,{type:'guardremote',actorId:m.id,targetId:target.id,monsterIndex:m.monsterIndex,attackKey,result,instanceId:m.instanceId,at:world.now()});
 return true;
}
export function tickSiegeRenewGuardCombat(world,m,dt){const engine=m._guardCombat;if(!engine)return;if(m.dead||m.disposed){engine.remotes.clear();return;}engine.game.time=world.now()/1000;engine.remotes.update(dt);}
