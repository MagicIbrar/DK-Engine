// Native option 2001:195/196: Siege / Auto Forced Attack. This changes input
// targeting only; a server-supplied foe list remains the authority for opponents.
export function siegeAttackArmed(game) {
  if (game.options?.get?.('siegeForceAttack') === true) return true;
  if (game.uiwin?.capturesInput) return false;
  if (game.network?.fieldPk?.held) return !!game.network.fieldPk.held();
  const key = game.keymap?.get?.('forceattack');
  return !!key && !!game.keymap?.down?.(key, true);
}

export function siegePlayerHostile(game, actor, foes) {
  return !!actor && actor.kind === 'player' && actor !== game.player && !actor.dead
    && !!actor.networkId && (foes || []).includes(actor.networkId) && siegeAttackArmed(game);
}

/** Native smartwarp24 alarm, visible only in the owning castle context while
 * forced targeting is armed. No additional PvP authority is granted here. */
export class SiegeForceAttackAlarm {
  constructor(game,name,current){this.game=game;this.name=name;this.current=current;this.disposed=false;this.win=null;this.making=null;}
  update(){
    const visible=!this.disposed&&this.current()&&siegeAttackArmed(this.game);
    if(!visible){this.win?.close?.();return;}
    if(this.win){this.win.control('btn_alarm').setVisible(true);if(!this.win.isOpen)this.game.uiwin?.openWindow?.(this.win);return;}
    if(this.making||!this.game.uiwin?.create)return;
    this.making=this.game.uiwin.create('game2/siege/ui_siegeforceattackalarmwnd.txt',{name:this.name,hud:true,escClose:false,remember:false}).then(w=>{
      if(this.disposed){w?.close?.();return;}this.win=w;this.update();
    }).catch(error=>console.warn('[siege] force attack alarm unavailable',error)).finally(()=>{this.making=null;});
  }
  dispose(){this.disposed=true;this.win?.close?.();}
}
