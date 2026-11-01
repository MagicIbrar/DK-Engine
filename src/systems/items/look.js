// Character look of the items system: equipping changes the Player's skinned parts, weapon meshes (on the class
// bones of items.json weaponBones, battle vs peace columns, left/right/both hands, dual-wield second mesh, shield /
// guard arm / quiver) and the animation set of the weapon stance (gamedata/items-styles.json).
//
// The Player (src/actors/player.js) reads save.equipment (legacy view built by Equipment.view) for parts and weapon;
// the stance's clips come from a per-player copy of the classes.json class with the style's anims merged in.
import { SWIM_FALLBACK } from '../../game/swim-fallback.js';

/** classes.json class + the anims/speeds/combo of a weapon style. */
export function styledClass(base, db, style) {
  const root = base?._base || base;
  if (!root || Number(root.style) === style) return root;
  const ci = Number(root.index) || 0;
  const A = db.styleAnims(ci, style);
  if (!A) return root;
  const swim = SWIM_FALLBACK[String(ci)]?.styles?.[String(style)] || SWIM_FALLBACK[String(ci)]?.base;
  const anims = { ...root.anims };
  for (const k of ['idle', 'idleAlt', 'walk', 'run', 'swimIdle', 'swimIdleCombat', 'swimWalk', 'swimRun', 'die', 'dieAlt', 'revive', 'knockdown', 'stun', 'sleep', 'block', 'guard']) {
    if (A[k]) anims[k] = A[k];
    else if (k.startsWith('swim') && swim?.[k]) anims[k] = swim[k];
  }
  for (const k of ['attack', 'hit', 'blocked']) if (A[k]?.length) anims[k] = A[k];
  const sfr = { ...(root.stats?.speedFromRootMotion || {}) };
  if (A.speedFromRootMotion?.run > 0) sfr.run = A.speedFromRootMotion.run;
  if (A.speedFromRootMotion?.walk > 0) sfr.walk = A.speedFromRootMotion.walk;
  const combo = db.styleCombo(ci, style);
  return {
    ...root, _base: root, _styled: true, style, styleName: db.enums.styleNames?.[style] || root.styleName,
    anims, stats: { ...root.stats, speedFromRootMotion: sfr }, combo: combo || root.combo,
  };
}

export class Look {
  constructor(sys) {
    this.sys = sys;
    this._busy = null;
    this._again = false;
    this._sig = '';
  }
  get game() { return this.sys.game; }

  /** Signature of what the body shows (so an unchanged equip does not reload the model). */
  signature(eqView, style) {
    // Asset identity includes authored material maps, not just geometry. Two
    // refinement variants can reuse the mesh while naming different textures.
    const asset = a => a ? JSON.stringify([a.mesh || null, a.tpack || null, a.textures || null]) : '-';
    const parts = ['helmet', 'coat', 'pants', 'glove', 'boots'].map(p => asset(eqView[p])).join('|');
    const w = eqView.weapon || {};
    return `${parts}|${w.none ? 'none' : JSON.stringify([asset(w), w.bone, w.bonePeace, asset({mesh:w.leftMesh,tpack:w.leftTpack,textures:w.leftTextures}), w.boneLeft, w.bonePeaceLeft, w.skel, w.anim, w.animTime, w.leftSkel, w.leftAnim, w.leftAnimTime, w.attachSkel, w.leftAttachSkel])}|s${style}`;
  }

  /** 2u (playgate): the player was just built from the current save.equipment + styled class during the loading
   *  screen - record that look, so the first apply() after spawn does not rebuild an identical body. */
  prime() {
    try { this._sig = this.signature(this.game.save.equipment || {}, this.sys.equip.style()); } catch { this._sig = ''; }
  }

  /** Reuse an identical in-flight candidate; newer canonical equipment supersedes it. */
  async apply(force = false) {
    const g=this.game,p=g.player;if(!p)return false;
    const preview=p._equipmentPreview;
    const style=preview?.style??this.sys.equip.style(),sig=this.signature(preview?.equipment||g.save.equipment||{},style);
    if(!force&&sig===this._sig&&p.loaded){
      // Reverting to the still-visible body must revoke a different pending
      // candidate, otherwise its late completion can overwrite the revert.
      if(this._busy&&sig!==this._pendingSig){
        this._generation=(this._generation||0)+1;
        p._appearanceGeneration=(p._appearanceGeneration||0)+1;
        p.classDef=styledClass(g.classDef,this.sys.db,style);
        this._busy=null;this._pendingSig=null;
      }
      return true;
    }
    if(!force&&this._busy&&sig===this._pendingSig)return this._busy;
    const generation=this._generation=(this._generation||0)+1;
    this._pendingSig=sig;p.classDef=styledClass(g.classDef,this.sys.db,style);
    let timer;const refresh=Promise.resolve(p.refreshAppearance?.()).catch(()=>false);
    const appearanceGeneration=p._appearanceGeneration;
    const work=(async()=>{
      await 0;
      try{
        const ok=await Promise.race([refresh,new Promise(resolve=>{timer=globalThis.setTimeout(()=>resolve(false),10000);})]);
        if(generation!==this._generation)return false;
        if(ok!==true){
          // Revoke only this candidate (including a timeout). A costume or
          // transform refresh may already own a newer Player generation.
          if(p._appearanceGeneration===appearanceGeneration)p._appearanceGeneration=(p._appearanceGeneration||0)+1;
          this._sig='';return false;
        }
        this._sig=sig;g.events?.emit('player:look',{style});return true;
      }finally{
        globalThis.clearTimeout(timer);
        if(generation===this._generation){this._busy=null;this._pendingSig=null;}
      }
    })();
    this._busy=work;return work;
  }
}

