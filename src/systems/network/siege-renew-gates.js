import {Brick,footprintCells} from '../events/bricks.js';
import {blockCollisionCells} from '../../world/collision-blockers.js';
import {RENEW_GATE_LAYOUT} from '../../game/siege-renew-gate-rules.js';

// Host-owned gates use the same explicitly reconstructed half-extent footprint
// as the host. Overlapping gate owners release collision independently.
class RenewGate extends Brick {
 block(collision){
  if(this.blocking||!collision?.cells)return;
  const d=this.brickDef;
  this.cells=footprintCells(this.x,this.z,this.dirDeg,Number(d.widthSize)*2,Number(d.heightSize)*2)
   .filter(([x,z])=>x>=0&&z>=0&&x<collision.width&&z<collision.height).map(([x,z])=>[z*collision.width+x,collision.cells[z*collision.width+x]]);
  this._releaseCollision=blockCollisionCells(collision,this.cells.map(([i])=>i));this._col=collision;this.blocking=true;
 }
}
export class SiegeRenewGates {
 constructor(game,defOf){this.game=game;this.defOf=defOf;this.actors=new Map();this.epoch=0;this.scene=null;this.instance=null;this.disposed=false;}
 unpick(b){const list=this.game.spawner?.monsters,index=list?.indexOf(b)??-1;if(index>=0)list.splice(index,1);if(this.game.player?.target===b||this.game.controller?.target===b)this.game.controller?.setTarget?.(null);}
 remove(id){const b=this.actors.get(id);if(!b)return;this.unpick(b);b.dispose();this.actors.delete(id);}
 clear(){this.epoch++;for(const id of this.actors.keys())this.remove(id);this.scene=null;this.instance=null;}
 sync(castle){
  if(this.disposed)return;
  if(this.scene!==this.game.world||this.instance!==castle?.instanceId){this.clear();this.scene=this.game.world;this.instance=castle?.instanceId||null;}
  const layout=RENEW_GATE_LAYOUT[castle?.map]||[],keep=new Set();
  for(const row of castle?.gates||[]){
   const native=layout.find(r=>r.uid===row.uid&&r.brick===row.brickIndex),def=this.defOf(row.brickIndex);
   if(!native||!def||typeof row.id!=='string'||![row.x,row.z,row.dir,row.hp,row.maxHp].every(Number.isFinite))continue;
   keep.add(row.id);let b=this.actors.get(row.id);
   if(b&&(b.uid!==row.uid||b.x!==row.x||b.z!==row.z||b.dirDeg!==row.dir)){this.remove(row.id);b=null;}
   if(!b){b=new RenewGate(this.game,def,{uid:row.uid,brick:row.brickIndex,x:row.x,z:row.z,dir:row.dir});b.brain=null;b.isBrick=true;b.renewGate=true;b.networkId=row.id;this.actors.set(row.id,b);const epoch=this.epoch,scene=this.scene;
    void b.load().then(()=>{if(this.disposed||epoch!==this.epoch||scene!==this.game.world||this.actors.get(row.id)!==b){this.unpick(b);b.dispose();}else b.group.visible=!b.removed;}).catch(error=>{if(this.actors.get(row.id)===b)this.remove(row.id);console.warn('[siege] gate model',error);});
   }
   const open=row.closed===false||!!row.dead||row.hp<=0||castle.phase!=='battle',changed=b.removed!==open;
   b.hp=row.hp;b.maxHp=b.maxHP=row.maxHp;b.dead=!!row.dead||row.hp<=0;b.breakable=!!row.breakable&&!open;b.kind=b.breakable?'monster':'brick';b.removed=open;
   if(b.breakable&&!this.game.spawner?.monsters?.includes(b))this.game.spawner?.monsters?.push(b);else if(!b.breakable)this.unpick(b);
   if(changed){b._gateAnimationEpoch=(b._gateAnimationEpoch||0)+1;b._gateOpening=false;}
   if(open){b.unblock();const state=b.dead?'die':'open';
    if(changed&&b.animator&&b._specFor(state)){const epoch=b._gateAnimationEpoch;b._gateOpening=true;b.group.visible=true;b.play(state,{loop:false,onEnd:()=>{if(b.removed&&!b.disposed&&epoch===b._gateAnimationEpoch){b._gateOpening=false;b.group.visible=false;}}});}
    else if(!b._gateOpening)b.group.visible=false;
   }
   else{b.group.visible=true;if(changed&&b.model)b.play('close',{loop:false});b.block(this.game.world?.collision);}
  }
  for(const id of this.actors.keys())if(!keep.has(id))this.remove(id);
 }
 actor(id){return this.actors.get(id)||null;}
 update(dt){for(const b of this.actors.values())b.update(dt);}
 dispose(){if(this.disposed)return;this.disposed=true;this.clear();}
}
