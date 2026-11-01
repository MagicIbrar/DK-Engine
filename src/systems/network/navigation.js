import { FindAuto } from '../dungeons/findauto.js';

// Shared clients omit the local dungeon reward system. Keep its ordinary
// quest/NPC navigation, while travel and all rewards remain host-owned.
export function installSharedNavigation(sys, network) {
  const game = sys.game, finder = new FindAuto(sys);
  finder.install();
  const publicFinder = game.findAuto;
  let disposed = false, mapPending = false;
  const offMap = game.events?.on?.('map', () => { mapPending = true; });
  const api = {
    update(dt) {
      if (disposed || network.disposed || !network.active || !network.ready ||
          network._transferring || game._loadingMap || !Number.isFinite(dt) ||
          !game.world || !game.player ||
          Number(game.world.info?.index) !== Number(network.self?.map)) return;
      if (mapPending) { mapPending = false; finder._leg(); }
      finder.update(dt);
    },
    dispose() {
      if (disposed) return;
      disposed = true;
      offMap?.();
      finder.cancel('dispose');
      if (game.findAuto === publicFinder) game.findAuto = null;
      if (game.sharedNavigation === api) game.sharedNavigation = null;
    },
  };
  game.sharedNavigation?.dispose?.();
  game.sharedNavigation = api;
  return api;
}
