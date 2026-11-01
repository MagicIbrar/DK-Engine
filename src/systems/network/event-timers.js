// Display authoritative deadlines with the shared monotonic server clock.
// A countdown reaching zero never advances a phase or admits a player.
const PHASE_CODES = { waitStart: 3, fortress: 4, waitPvp: 5, pvp: 6, waitExtension: 7, extension: 8, waitClose: 9 };
const fileFor = mode => mode === 'iceCastle' ? 'stringtable_partywar2.txt' : 'stringtable_partywar.txt';

export function createSharedEventTimers(game, network, ui, getData) {
  let record = null, rendered = null, disposed = false;
  const now = () => network.serverNow?.() ?? (network._serverClock ? network._serverClock.time + performance.now() - network._serverClock.at : NaN);
  const current = value => !!value && !disposed && !network.disposed && record === value && !game._loadingMap &&
    Number(game.world?.info?.index) === value.map && Number(network.self?.map) === value.map &&
    (value.instanceId ? network.self?.instanceId === value.instanceId : !network.self?.instanceId);
  const close = () => { rendered = null; ui.close('ev_remaintime'); ui.close('ev_limittime'); };
  return {
    snapshot(snapshot) {
      const instance = snapshot?.instance, lobby = snapshot?.eventLobby;
      if (instance && PHASE_CODES[instance.phase] && ['deadFront', 'iceCastle'].includes(instance.kind) &&
          Number.isFinite(snapshot.serverTime) && Number.isFinite(instance.remainingMs)) {
        record = { instanceId: instance.id, map: Number(instance.map), mode: instance.kind, phase: instance.phase,
          cate: 300, code: PHASE_CODES[instance.phase], until: snapshot.serverTime + Math.max(0, instance.remainingMs), window: 'ev_limittime' };
      } else if (!snapshot?.self?.instanceId && lobby && ['deadFront', 'iceCastle'].includes(lobby.mode) &&
          Number.isFinite(lobby.until) && ((lobby.cate === 100 && [11, 12].includes(lobby.code)) || (lobby.cate === 200 && lobby.code === 103))) {
        record = { ...lobby, map: Number(lobby.map), window: 'ev_remaintime' };
      } else record = null;
      this.update();
    },
    update() {
      const data = getData(), value = record, time = now();
      if (!value || !data || !Number.isFinite(time) || !current(value)) { close(); return; }
      const seconds = Math.ceil(Math.max(0, value.until - time) / 1000);
      const fmt = data.txt(fileFor(value.mode), value.cate, value.code);
      if (!fmt) { close(); return; }
      const key = `${value.window}:${value.map}:${value.mode}:${value.phase}:${value.instanceId || value.cycle}:${seconds}`;
      if (key === rendered && ui._win(value.window)?.isOpen) return;
      rendered = key;
      ui.close(value.window === 'ev_remaintime' ? 'ev_limittime' : 'ev_remaintime');
      const options = { isCurrent: () => current(record) && record.map === value.map && record.window === value.window && record.phase === value.phase &&
        record.mode === value.mode && record.instanceId === value.instanceId && record.cycle === value.cycle };
      if (value.window === 'ev_remaintime') void ui.lobbyTimer(fmt, seconds, options);
      else void ui.timer(fmt, seconds, options);
    },
    dispose() { disposed = true; record = null; close(); },
  };
}
