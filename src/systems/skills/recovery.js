// Successful item-use events select the original modeleffect game recovery
// scenes. This module only presents an already committed use; it never changes
// resources, cooldowns or item ownership.
export function installRecoveryEffects(game, data, fx) {
  const refs = new Map((data.modelEffects?.game || [])
    .filter(row => [21, 31].includes(Number(row.code?.[0])) && !Number(row.code?.[1]) && !Number(row.code?.[2]))
    .map(row => [Number(row.code[0]), row.effect]));
  return game.events?.on?.('itemuse', ({def} = {}) => {
    const player = game.player;
    if (!player || player.dead || player.disposed) return;
    const use = def?.use || {};
    // The legacy loot adapter uses kind instead of the modern original fields.
    const hp = Number(use.hp) > 0 || Number(use.hpPct) > 0 || ['hp', 'hp%', 'hpmp%'].includes(def?.kind);
    const mp = Number(use.mp) > 0 || Number(use.mpPct) > 0 || ['mp', 'mp%', 'hpmp%'].includes(def?.kind);
    for (const code of [hp && 21, mp && 31]) {
      const ref = refs.get(code);
      if (ref) fx.play(player, ref, {loop: false});
    }
  });
}
