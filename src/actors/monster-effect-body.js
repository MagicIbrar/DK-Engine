// Effect-body monsters (src/game/effect-body.js): their model is the empty *_none mesh, and the original client draws
// them only through the effect each action record authors (modeleffect.csv 25/1 -> effect scene drawing the real body
// mesh, e.g. Ghostman_knight 3810 / Ghostman_archer 3813 on the Nest of Cherubim). Nothing is drawn while they stand or
// move, exactly as their STAND / MOVE records author no effect.
//
// The scenes are not part of the prepared skill effect library; they are read on demand from the original effect files
// (property/effect/effectscene.*.txt + effectdata.*.txt, the same parser and cache as equipment effects:
// game.items.authoredEffects.data, else a private AuthoredEffectsData) and played by ONE EffectPlayer per game, ticked
// once per frame by whichever effect-body monster updates first.
// ENGINE CHOICE (the data has no rule): the body effect is the monster's model, so the effects on/off option that hides
// skill effects does not hide it; a newer action cuts the previous body effect (the body cannot hold two poses).
import { EffectPlayer } from '../systems/skills/effects.js';
import { AuthoredEffectsData } from '../systems/items/authored-effects-data.js';

const keyOf = ref => `${Number(ref.cate)}:${Number(ref.id)}`;

/** The game's body-effect player (created once; tests may pre-set game.monsterBodyEffects). */
export function monsterBodyEffects(game) {
  if (!game) return null;
  if (game.monsterBodyEffects) return game.monsterBodyEffects;
  const data = game.items?.authoredEffects?.data || new AuthoredEffectsData();
  const fx = new EffectPlayer(game, data);
  const failed = new Set(), loading = new Map();
  let frame;
  const player = {
    data, fx,
    ready(ref) { return !!data.scene(keyOf(ref)); },
    /** Load one authored scene from the original files; resolves true when it can play. */
    load(ref) {
      const key = keyOf(ref);
      if (data.scene(key)) return Promise.resolve(true);
      if (failed.has(key)) return Promise.resolve(false);
      if (!loading.has(key)) {
        loading.set(key, Promise.resolve().then(() => data.load({ cate: Number(ref.cate), id: Number(ref.id) }))
          .then(() => { const ok = !!data.scene(key); if (!ok) failed.add(key); return ok; },
            error => { failed.add(key); console.warn('[monsters] body effect unavailable', key, error?.message || error); return false; })
          .finally(() => loading.delete(key)));
      }
      return loading.get(key);
    },
    /** Play one authored body effect on the actor now (null while its scene is still loading). */
    play(actor, ref) {
      if (!ref || !this.ready(ref)) { if (ref) void this.load(ref); return null; }
      return fx.play(actor, { cate: Number(ref.cate), id: Number(ref.id), scene: Number(ref.scene) || 1, timeMs: Number(ref.timeMs) || 1000, loop: ref.loop }, { loop: false });
    },
    /** Advance the shared player once per frame (several monsters call it). */
    tick(dt) {
      const t = game.time;
      if (t != null && t === frame) return;
      frame = t;
      fx.update(dt);
    },
  };
  game.monsterBodyEffects = player;
  return player;
}
