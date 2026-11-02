import {EffectPlayer} from '../systems/skills/effects.js';

// Native modeleffect 39/62: Ground target -> field_target (5:2 scene 1, modeleffect.csv "39,62,0,0,5,2,1,2000,0,").
// Its two decal layers supply their own textures, opposite rotations, scale/alpha keys and the 2 s looping scene.
//
// Lane 60 - Global rule (64-bit client, Ghost::GameHandler::Target::State::Ground, "Target\State\Ground.cpp",
// vft 7ff671e7e690):
//   * slot 2 FUN_7ff67162c620 (a ground target is set): first slot 5 FUN_7ff67162c710 clears the old target
//     (FUN_7ff67162c910 removes the old effect instance), then the point is stored with the terrain height and,
//     when it is not the origin (|p|^2 > 1e-6), FUN_7ff67162c750 spawns a NEW modeleffect (0x27, 0x3e) instance there.
//   * slot 6 (the per-frame hook) is an empty `ret`: the effect never follows anything once spawned.
// So every set restarts the scene at its first frame at a fixed point. While the left button is held the target is set
// again every frame (the circle sits on its first frame = static, not spinning); after release nothing re-sets it, so
// the last instance plays its authored scene (spin, then the pulse/flash, looping) where the button was released.
export class MoveMarker {
  constructor(game){this.game=game;this.world=game.world;this.point={x:0,y:0,z:0};this.fx=null;this.handle=null;this.disposed=false;this.spawns=0;}
  /** Global Target::State::Ground set: clear the old instance and spawn a new one at a fixed point. */
  show(x,z){
    if(this.disposed||!Number.isFinite(x)||!Number.isFinite(z))return false;
    const y=this.game.world?.heightAt?.(x,z);
    const point={x,y:Number.isFinite(y)?y:Number(this.game.player?.y)||0,z};
    this.handle?.stop(true);this.handle=null;   // FUN_7ff67162c910: the previous instance is removed
    this.point=point;
    if(!(x*x+point.y*point.y+z*z>1e-6))return false;   // FUN_7ff67162c620: nothing is spawned at the origin
    const data=this.game.skills?.data;if(!data)return false;
    if(this.fx?.data!==data){this.fx?.dispose();this.fx=new EffectPlayer(this.game,data);this.fx.soundOn=false;this.fx.root.name='native move destination';}
    const ref=data.modelEffects?.game?.find(row=>Number(row.code?.[0])===62&&Number(row.code?.[1])===0&&Number(row.code?.[2]||0)===0)?.effect;
    if(!ref)return false;
    this.handle=this.fx.play({...point},ref,{particleSpace:'attachment',scale:1});
    if(this.handle)this.spawns++;
    return !!this.handle;
  }
  update(dt){
    if(this.disposed)return;
    if(this.world!==this.game.world||(this.fx&&this.fx.root.parent!==this.game.worldRoot)){this.dispose();return;}
    this.fx?.update(Math.max(0,Number(dt)||0));
  }
  dispose(){if(this.disposed)return;this.disposed=true;this.handle?.stop(true);this.handle=null;this.fx?.dispose();this.fx=null;}
}