import { runAssetTask, transferBuffers } from './asset-tasks.js';
self.onmessage = ({ data: { id, type, buffer, options } }) => {
  try {
    const value = runAssetTask(type, buffer, options);
    self.postMessage({ id, value }, transferBuffers(value));
  } catch (err) {
    self.postMessage({ id, error: String(err?.stack || err) });
  }
};
