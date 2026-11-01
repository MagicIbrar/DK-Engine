// Shared-world PvP adapter (PVP-DUEL server/world/pvp.mjs, PARTY-PVP server/world/party-pvp.mjs). Reads the private
// pvp / partyPvp snapshots, sends their intents and marks the duel opponent and the Party Match enemies as the only
// hostile players (game.isPvpHostile: basic attacks in src/game/controller.js, skill targeting in
// src/systems/skills/engine.js). The host computes every hit (src/game/pvp-rules.js).
import { installDuelWindows } from '../pvp/duel.js';
import { installPartyPvpWindows } from '../pvp/partypvp.js';
import { installSharedColosseum } from './colosseum.js';
import { installFieldPk } from './field-pk.js';
import { partyWarHostilePhase } from '../../game/pvp-rules.js';
import {installPartyObserverWindow} from '../pvp/party-observer-window.js';

const BLANK = { points: { points: 0, wins: 0, losses: 0, draws: 0 }, restoreAt: null, result: null, notice: null };
const PARTY_BLANK = { result: null, notice: null };

export function installSharedPvp(game, network) {
  let disposed = false, warInstance = null;
  const st = () => network.pvpState || BLANK;
  const pst = () => network.partyPvpState || PARTY_BLANK;
  const sender = (type, key) => async (operation, fields = {}) => {
    if (disposed || !network.active) return null;
    const r = await network.action(type, { operation, ...fields });
    return r ? (r[key] ?? {}) : null;
  };
  const send = sender('pvp', 'pvpResult'), psend = sender('partypvp', 'partyPvpResult');
  const idOf = actor => (typeof actor === 'string' ? actor : actor?.networkId);
  const serverNow = () => (network._serverClock ? network._serverClock.time + performance.now() - network._serverClock.at : Date.now());
  network.pvp = {
    state: st,
    request: actor => send('request', { targetId: idOf(actor) }),
    accept: () => send('accept'), decline: () => send('decline'), cancel: () => send('cancel'), restore: () => send('restore'),
    isOpponent: a => !!a && a.kind === 'player' && a !== game.player && st().phase === 'fight' && a.networkId === st().opponent?.id,
    serverNow,
  };
  network.partyPvp = {
    state: pst,
    request: actor => psend('request', { targetId: idOf(actor) }),
    accept: () => psend('accept'), decline: () => psend('decline'), cancel: () => psend('cancel'),
    setting: (row, fee, minutes) => psend('setting', { row, fee, minutes }), ready: () => psend('ready'), withdraw: () => psend('withdraw'),
    buff:(buff,enabled)=>psend('buff',{buff,enabled}),
    list:()=>psend('list'),observe:matchId=>psend('observe',{matchId}),leaveObserver:()=>psend('leaveObserver'),
    isEnemy: a => !!a && a.kind === 'player' && a !== game.player && pst().phase === 'fight' && (pst().enemies || []).includes(a.networkId),
    serverNow,
  };
  // PARTY-WAR: the other parties of a contested Dead Front / Ice Castle war (snapshot instance.war.enemies)
  const isWarEnemy = a => !!a && a.kind === 'player' && a !== game.player &&
    warInstance?.id === network.self?.instanceId && Number(game.world?.info?.index) === warInstance?.map &&
    partyWarHostilePhase(warInstance?.kind, warInstance?.phase) && (warInstance?.war?.enemies || []).includes(a.networkId);
  installFieldPk(game, network);   // Ctrl = Force Attack on other players of open PvP fields (the host decides)
  game.isPvpHostile = a => !!network.pvp?.isOpponent(a) || !!network.partyPvp?.isEnemy(a) || isWarEnemy(a) || !!network.colosseum?.isEnemy(a) || !!network.fieldPk?.isEnemy(a);
  // the duel loser resurrects at the spot through pvp_restore; a downed Party Match participant stays down until the
  // result (both without the death window)
  const hud = game.hud, showDeath = hud?.showDeath;
  if (hud && typeof showDeath === 'function') hud.showDeath = function (...args) { if (network.active && (st().restoreAt || pst().id || network.colosseumState?.match?.id)) return undefined; return showDeath.apply(this, args); };
  const snapshot = network._snapshot.bind(network);
  network._snapshot = record => {
    if (network.disposed || Number(record?.sequence) < network.sequence) return;
    const prev = network.pvpState, pprev = network.partyPvpState;
    warInstance = record?.instance || null;
    network.pvpState = record?.pvp || BLANK;
    network.partyPvpState = record?.partyPvp || PARTY_BLANK;
    snapshot(record);
    game.events?.emit?.('pvp', { state: network.pvpState, prev });
    game.events?.emit?.('partypvp', { state: network.partyPvpState, prev: pprev });
  };
  const dispose = network.dispose.bind(network);
  const disposeObserver=installPartyObserverWindow(game,network);
  network.dispose = () => { disposed = true;disposeObserver(); network.fieldPk?.dispose?.(); network.fieldPk = null; network.pvpState = null; network.pvp = null; network.partyPvpState = null; network.partyPvp = null; delete game.isPvpHostile; if (hud && showDeath) hud.showDeath = showDeath; dispose(); };
  installDuelWindows(game, network);
  installPartyPvpWindows(game, network);
  installSharedColosseum(game, network);   // COLOSSEUM: queues, Battle Royale, Individual Match
  return network.pvp;
}
