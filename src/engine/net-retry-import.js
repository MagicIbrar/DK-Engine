// Dynamic-import twin of assets.js fetchWithNetRetry: cold-profile Chrome can abort
// in-flight module graph fetches (TypeError / Failed to fetch / net::ERR_ABORTED).
// Retry only that network-layer class; other errors pass through. Used by the
// login/select/create hand-off so Start world / DX11 is not stuck on a one-shot abort.
import { NET_RETRY_DELAYS_MS } from './assets.js';

export async function importWithNetRetry(importer, delays = NET_RETRY_DELAYS_MS) {
  if (typeof importer !== 'function') throw new TypeError('importWithNetRetry expects an importer function');
  let attempt = 0;
  for (;;) {
    try { return await importer(); }
    catch (error) {
      if (!(error instanceof TypeError) || attempt >= delays.length) throw error;
      await new Promise(r => setTimeout(r, delays[attempt++]));
    }
  }
}
