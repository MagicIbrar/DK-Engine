import {EffectPlayer} from '../systems/skills/effects.js';

// Native modeleffect39/62: Ground target -> field_target (5:2). Its two decal
// layers supply their own textures, opposite rotations, scale/alpha keys and
// persistent scene duration. Only the destination/lifetime is input-driven.
export class MoveMarker {
  constructor(game){this.game=game;this.world=game.world;this.point={x:0,y:0,z:0};this.fx=null;this.handle=null;this.disposed=false;}
  show(x,z){
    if(this.disposed||!Number.isFinite(x)||!Number.isFinite(z))return false;
    this.point.x=x;this.point.z=z;
    const y=this.game.world?.heightAt?.(x,z);this.point.y=Number.isFinite(y)?y:Number(this.game.player?.y)||0;
    const data=this.game.skills?.data;if(!data)return false;
    if(this.fx?.data!==data){this.handle?.stop(true);this.fx?.dispose();this.fx=new EffectPlayer(this.game,data);this.fx.soundOn=false;this.fx.root.name='native move destination';this.handle=null;}
    if(!this.handle||this.handle.done){
      const ref=data.modelEffects?.game?.find(row=>Number(row.code?.[0])===62&&Number(row.code?.[1])===0&&Number(row.code?.[2]||0)===0)?.effect;
      if(!ref)return false;
      this.handle=this.fx.play(this.point,ref,{followPoint:true,particleSpace:'attachment',scale:1});
    }
    return !!this.handle;
  }
  update(dt){
    if(this.disposed)return;
    if(this.world!==this.game.world||(this.fx&&this.fx.root.parent!==this.game.worldRoot)){this.dispose();return;}
    if(!this.handle)this.show(this.point.x,this.point.z);
    this.fx?.update(Math.max(0,Number(dt)||0));
  }
  dispose(){if(this.disposed)return;this.disposed=true;this.handle?.stop(true);this.handle=null;this.fx?.dispose();this.fx=null;}
}
