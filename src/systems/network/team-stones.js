import {Brick} from '../events/bricks.js';
import {registerEventActors} from './event-actors.js';

// Host-owned DK Square (map 67) / Draco (map 702) squad stones (server/world/team-stones.mjs). The host owns HP,
// custody and destruction; this draws the native brick model (mesh / tpack / DEAD clip), blocks the same native
// footprint (Brick.block -> eventBrickFootprintCells), makes an enemy squad's standing stone targetable and shows its
// HP. Rows come from the battle state of dksquare.js (snapshot) and arena.js (polled), one owner at a time.
export class TeamStones {
 constructor(game,defOf){this.game=game;this.defOf=defOf;this.actors=new Map();this.sources=new Map();this.key=null;this.epoch=0;this.disposed=false;}
 unpick(b){const list=this.game.spawner?.monsters,index=list?.indexOf(b)??-1;if(index>=0)list.splice(index,1);if(this.game.player?.target===b||this.game.controller?.target===b)this.game.controller?.setTarget?.(null);}
 remove(id){const b=this.actors.get(id);if(!b)return;this.unpick(b);b.dispose();this.actors.delete(id);}
 clear(){this.epoch++;for(const id of [...this.actors.keys()])this.remove(id);this.key=null;}
 /** owner: 'dkSquare' | 'arena'; battle: that owner's battle state (null = none). */
 sync(owner,battle){
  if(this.disposed)return;
  this.sources.set(owner,battle?.inside&&Array.isArray(battle.stones)?battle:null);
  const active=[...this.sources.values()].find(Boolean)||null,map=Number(this.game.world?.info?.index);
  if(!active||Number(active.map)!==map){if(this.actors.size||this.key)this.clear();return;}
  const key=`${active.id}@${map}`;if(this.key!==key){this.clear();this.key=key;}
  const keep=new Set();
  for(const row of active.stones){
   const def=this.defOf(row.brickIndex);
   if(!def||typeof row.id!=='string'||![row.x,row.z,row.dir,row.hp,row.maxHp].every(Number.isFinite))continue;
   keep.add(row.id);let b=this.actors.get(row.id);
   if(!b){b=new Brick(this.game,def,{uid:row.uid,brick:row.brickIndex,x:row.x,z:row.z,dir:row.dir,isCreate:1});b.brain=null;b.isBrick=true;b.teamStone=true;b.networkId=row.id;this.actors.set(row.id,b);
    const epoch=this.epoch;b.block(this.game.world?.collision);
    void b.load().then(()=>{if(this.disposed||epoch!==this.epoch||this.actors.get(row.id)!==b){this.unpick(b);b.dispose();}else if(b.dead&&!b._dying)b.group.visible=false;}).catch(error=>{if(this.actors.get(row.id)===b)this.remove(row.id);console.warn('[dk] stone model',error);});
   }
   this.apply(b,row);
  }
  for(const id of [...this.actors.keys()])if(!keep.has(id))this.remove(id);
 }
 apply(b,row){
  const died=!!row.dead&&!b.dead;
  b.hp=row.dead?0:row.hp;b.maxHp=b.maxHP=row.maxHp;b.dead=!!row.dead;b.team=row.team;
  b.breakable=!!row.breakable&&!b.dead;b.kind=b.breakable?'monster':'brick';
  if(b.breakable&&!this.game.spawner?.monsters?.includes(b))this.game.spawner?.monsters?.push(b);else if(!b.breakable)this.unpick(b);
  if(died){b.removed=true;b.unblock();this.unpick(b);
   if(b.model&&b._specFor('die')){b._dying=true;b.play('die',{loop:false,onEnd:()=>setTimeout(()=>{if(!b.disposed){b.group.visible=false;b._dying=false;}},400)});}
   else if(b.group)b.group.visible=false;}
 }
 /** Live HP between state refreshes: the host's own damage events on a stone. */
 event(e){const b=e?.type==='damage'&&this.actors.get(e.targetId);if(b&&!b.dead&&Number(e.amount)>0)b.hp=Math.max(0,b.hp-Number(e.amount));}
 actor(id){const b=this.actors.get(id);return b&&!b.disposed?b:null;}
 update(dt){for(const b of this.actors.values())b.update(dt);}
 dispose(){if(this.disposed)return;this.disposed=true;this.clear();this.sources.clear();}
}
/** One renderer per game, wired once into the network client (update, events, damage-target lookup). */
export function teamStonesFor(game,network){
 if(game.teamStones&&!game.teamStones.disposed)return game.teamStones;
 const stones=game.teamStones=new TeamStones(game,id=>game.sharedEvents?.data?.brick?.(id)||null);
 const releaseActor=registerEventActors(network,'team-stones',id=>stones.actor(id),20);
 const update=network.update?.bind(network);if(update)network.update=dt=>{update(dt);stones.update(dt);};
 const event=network._event?.bind(network);if(event)network._event=e=>{stones.event(e);event(e);};
 const leave=network.leave?.bind(network);if(leave)network.leave=options=>{stones.clear();stones.sources.clear();return leave(options);};
 const dispose=network.dispose?.bind(network);if(dispose)network.dispose=()=>{releaseActor();stones.dispose();if(game.teamStones===stones)game.teamStones=null;return dispose();};
 return stones;
}
