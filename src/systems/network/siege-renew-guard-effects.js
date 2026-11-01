import {ApprovedGroundEffects} from './skill-ground-effects.js';

// Host-approved native projectile cosmetics. Result payloads never execute game
// rules here: the locally compiled sentry attack supplies the visual definition.
export class SiegeGuardEffects {
 constructor(game,network,{ground=(data,fx)=>new ApprovedGroundEffects(game,data,fx)}={}){this.game=game;this.network=network;this.makeGround=ground;this.seen=new Set();this.epoch=0;this.scope=null;}
 scene(){const n=this.network,s=n.self,w=this.game.world;return !this.disposed&&!n.disposed&&n.active&&n.ready&&n.token&&[193,194,195].includes(Number(s?.map))&&s?.instanceId&&Number(w?.info?.index)===s.map?{world:w,token:n.token,map:s.map,instanceId:s.instanceId}:null;}
 matches(scope){const c=this.scene();return !!c&&c.world===scope.world&&c.token===scope.token&&c.map===scope.map&&c.instanceId===scope.instanceId;}
 sync(){const c=this.scene();if(this.scope&&!this.matches(this.scope))this.clear();this.scope=c;return c;}
 async event(event){
  if(event?.type!=='guardremote')return false;
  const scope=this.sync(),n=this.network,sequence=Number(event.sequence),actor=n.monsters?.get(event.actorId),target=event.targetId===n.self?.id?this.game.player:n.players?.get(event.targetId);
  const valid=()=>this.matches(scope)&&!actor?.dead&&!actor?.disposed&&actor?.renewGuard===true&&actor.def?.sentry===true&&n.monsters?.get(event.actorId)===actor&&actor._serverScene?.instanceId===scope.instanceId&&!target?.dead&&!target?.disposed&&(event.targetId===n.self?.id?target===this.game.player:n.players?.get(event.targetId)===target);
  if(!scope||event.instanceId!==scope.instanceId||!Number.isInteger(sequence)||sequence<1||this.seen.has(sequence)||!actor||!target||!valid())return true;
  const result=actor.def.attackResults?.[event.attackKey];if(result?.family!=='projectile')return true;
  const now=n._serverClock?n._serverClock.time+performance.now()-n._serverClock.at:Date.now(),age=Number.isFinite(event.at)?Math.max(0,now-event.at):0;if(age>3000)return true;
  this.seen.add(sequence);if(this.seen.size>256)this.seen.delete(this.seen.values().next().value);
  const engine=this.game.skills,data=engine?.data,epoch=this.epoch;if(!data)return true;
  await Promise.all([data.remote(result.remoteIndex)?null:data._loadFull?.('skills'),data._loadFull?.('effects')]);
  if(epoch!==this.epoch||!valid()||this.game.skills!==engine||!data.remote(result.remoteIndex))return true;
  if(!this.ground)this.ground=this.makeGround(data,engine.fx);
  this.ground.play({caster:actor,target,point:{x:target.x,z:target.z},skill:{targetMask:4}},result);
  return true;
 }
 update(dt){this.sync();this.ground?.update(dt);}
 clear(){this.epoch++;this.ground?.clear();this.ground=null;this.scope=null;this.seen.clear();}
 dispose(){this.disposed=true;this.clear();}
}
