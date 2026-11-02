// Realm (world server) side of the main pipeline (child process of ServerOn, IPC with structured-clone serialization).
// Null unless this process was started by server/pipeline/serveron.mjs; then logs go to Archive (BULK lane), live stats
// go to the hub (STATE lane, coalesced), and the hub can ask this process to save and stop (REALTIME lane).
import { createEndpoint, PRIO } from './bus.mjs';
let client;
export function pipelineClient() {
  if (client !== undefined) return client;
  if (process.env.DEKARON_PIPELINE_CHILD !== '1' || typeof process.send !== 'function') return (client = null);
  const handlers = {};
  const ep = createEndpoint('Realm', packet => { if (process.connected) process.send(packet); }, { handlers });
  process.on('message', packet => { if (packet && typeof packet === 'object') ep.onPacket(packet); });
  process.on('disconnect', () => { client?.onHubLost?.(); });
  ep.subscribe(['realm.*', 'ctl.Realm']);
  client = {
    PRIO, endpoint: ep, handlers,
    on(topic, fn) { handlers[topic] = fn; },
    log(line, svc = 'Realm') { ep.publish('archive.write', { svc, line }, PRIO.BULK); },
    stats(topic, value) { ep.publish(topic, value, PRIO.STATE, topic); },
    onHubLost: null,
  };
  return client;
}
