// Worker-thread side of the main pipeline: wraps the MessagePort the hub handed this service.
import { workerData } from 'node:worker_threads';
import { createEndpoint } from './bus.mjs';
export function connectWorker(name, handlers = {}, topics = []) {
  const port = workerData.busPort;
  const ep = createEndpoint(name, packet => port.postMessage(packet), { handlers });
  port.on('message', packet => ep.onPacket(packet));
  if (topics.length) ep.subscribe(topics);
  return ep;
}
