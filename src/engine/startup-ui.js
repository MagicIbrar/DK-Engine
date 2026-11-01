import { STARTUP_UI_SCRIPTS, STARTUP_UI_EXCLUDED_REFERENCES } from '../config/engine-chosen-startup-ui.js';
import { SCRIPT_LANES } from '../config/engine-chosen-loading.js';
import { nextTask } from './yield.js';

// Pure UI scripts are shared across every UIManager. Prepare them at client startup;
// do not instantiate gameplay systems, allocate all windows, or call service/onOpen actions.
// This is an eager discovery list, not a list of required boot dependencies. Older
// asset sets may omit optional panels; actual boot consumers still require their windows.
export async function prepareStartupUIScripts(manager, { names = STARTUP_UI_SCRIPTS,
  onProgress = () => {}, current = () => true, signal, yieldTask = nextTask } = {}) {
  const report = { done: 0, total: names.length, prepared: 0, skippedMissing: [], warnings: [], excludedReferences: [...STARTUP_UI_EXCLUDED_REFERENCES] };
  const assertCurrent = () => {
    if (signal?.aborted || !current()) throw Object.assign(new Error('Startup interface preparation cancelled.'), { name: 'AbortError' });
  };
  let cursor = 0, failure = null;
  assertCurrent();
  onProgress(0, names.length);
  await Promise.all(Array.from({ length: Math.min(SCRIPT_LANES, names.length) }, async () => {
    while (!failure && cursor < names.length) {
      assertCurrent();
      const script = names[cursor++];
      try {
        const result = await manager.loadScript(script);
        assertCurrent();
        if (failure) throw failure;
        if (result?.format === 'missing') {
          // Only the manager's explicit missing result is optional. Never turn
          // transport, decoding, compilation or malformed-result failures into skips.
          report.skippedMissing.push(script);
        } else if (!result || !(result.windows?.length || result.fragments?.length)) {
          throw new Error(`Startup interface script unavailable: ${script}`);
        } else report.prepared++;
        if (result.warnings?.length) report.warnings.push({ script, messages: result.warnings.slice() });
        // Discovery is complete for an absent optional panel too. This is not
        // proof that a window was prepared, nor that login/graphics are ready.
        onProgress(++report.done, report.total, script);
        await yieldTask();
      } catch (error) { failure = error; throw error; }
    }
  }));
  assertCurrent();
  return report;
}
