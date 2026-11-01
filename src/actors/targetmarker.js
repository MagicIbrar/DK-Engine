import {EffectPlayer} from '../systems/skills/effects.js';

// modeleffect group39/code61: Creature target (persistent scene5:4). Art,
// mesh/skeleton animation, colour and timing come from the prepared Global data.
// Placement policy: attach above the selected creature at its scaled top.
// Selection feedback stays visible when skill effects are disabled.
export class TargetMarker {
  constructor(actor) { this.actor=actor; this.fx=null; this.handle=null; }
  update(dt=0) {
    const a=this.actor, game=a.game;
    const visible=a.highlighted&&!a.dead&&!a.faded&&!a.disposed&&a.group?.visible!==false&&a!==game.player;
    if(!visible) { this.stop(); return; }
    const data=game.skills?.data;
    if(!data) return;
    if(this.fx?.data!==data) { this.dispose(); this.fx=new EffectPlayer(game,data); this.fx.soundOn=false; this.fx.root.name='selected creature marker'; }
    if(!this.handle||this.handle.done) {
      const ref=data.modelEffects?.game?.find(row=>row.code?.[0]===61&&row.code?.[1]===0)?.effect;
      if(ref) this.handle=this.fx.play(a,ref,{bone:'top',scale:1,particleSpace:'attachment'});
    }
    this.fx.update(Math.max(0,Number(dt)||0));
  }
  stop() { this.handle?.stop(true); this.handle=null; }
  dispose() { this.stop(); this.fx?.dispose(); this.fx=null; }
}
