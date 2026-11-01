// TRAINING-CAMP shared-world adapter (server/world/training-camp.mjs): reads the private trainingCamp snapshot, sends its
// intents, marks the other team's participants as hostile during the battle (chained onto game.isPvpHostile of
// network/pvp.js) and keeps the death window away while the battlefield respawns its participants. The host computes
// every hit (src/game/pvp-rules.js through server/world/pvp.mjs).
import { atlas } from '../../ui/atlas.js';
import { trainingCampImageTableText } from '../../config/engine-chosen-training-camp.js';
import { installTrainingCampWindows } from '../pvp/trainingcamp.js';

const BLANK = { lobbies: [], lobby: null, result: null, notice: null, rules: null };

export function installSharedTrainingCamp(game, network) {
  atlas.addRows?.(trainingCampImageTableText());
  let disposed = false;
  const st = () => network.trainingCampState || BLANK;
  const send = async (operation, fields = {}) => {
    if (disposed || !network.active) return null;
    const r = await network.action('trainingcamp', { operation, ...fields });
    return r ? (r.trainingCampResult ?? {}) : null;
  };
  const serverNow = () => (network._serverClock ? network._serverClock.time + performance.now() - network._serverClock.at : Date.now());
  const inBattle = () => { const l = st().lobby; return !!l && ['fight', 'over'].includes(l.phase) && l.inside; };
  network.trainingCamp = {
    state: st,
    open: () => send('open'), join: lobbyId => send('join', { lobbyId }), cancel: () => send('cancel'),
    accept: () => send('accept'), decline: () => send('decline'), leave: () => send('leave'),
    isEnemy: a => !!a && a.kind === 'player' && a !== game.player && st().lobby?.phase === 'fight' && (st().lobby.enemies || []).includes(a.networkId),
    serverNow,
  };
  const hostile = game.isPvpHostile;
  game.isPvpHostile = a => !!network.trainingCamp?.isEnemy(a) || !!hostile?.(a);
  const hud = game.hud, showDeath = hud?.showDeath;
  if (hud && typeof showDeath === 'function') hud.showDeath = function (...args) { if (network.active && inBattle()) return undefined; return showDeath.apply(this, args); };
  const snapshot = network._snapshot.bind(network);
  network._snapshot = record => {
    if (network.disposed || Number(record?.sequence) < network.sequence) return;
    const prev = network.trainingCampState;
    network.trainingCampState = record?.trainingCamp || BLANK;
    snapshot(record);
    game.events?.emit?.('trainingcamp', { state: network.trainingCampState, prev });
  };
  const dispose = network.dispose.bind(network);
  network.dispose = () => { disposed = true; network.trainingCampState = null; network.trainingCamp = null; if (hostile) game.isPvpHostile = hostile; if (hud && showDeath) hud.showDeath = showDeath; dispose(); };
  installTrainingCampWindows(game, network);
  return network.trainingCamp;
}