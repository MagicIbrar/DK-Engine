import { ARTWORK_LANES, SCRIPT_LANES, PRIORITY_PANELS } from '../../config/engine-chosen-loading.js';
// Decode registered panel art before play. Never invoke onOpen or service actions.
export function panelImages(spec, result = new Map()) {
  if (!spec || typeof spec !== 'object') return result;
  for (const image of spec.images || []) {
    if (image.screen && Number.isFinite(Number(image.index)) && Number(image.index) >= 0) {
      const key = JSON.stringify([String(image.screen).toLowerCase(), Number(image.index), image.color || null]);
      result.set(key, image);
    }
  }
  for (const child of spec.children || []) panelImages(child, result);
  return result;
}
async function eachBounded(values, count, action) {
  let cursor = 0;
  await Promise.all(Array.from({ length: Math.min(count, values.length) }, async () => {
    while (cursor < values.length) await action(values[cursor++]);
  }));
}
// One session owns every script/image promise. Priority/full are distinct completion
// barriers: asking only for priority never marks the remaining panels complete.
export function createPanelPrewarm(manager) {
  const images = new Map(), failures = [], listeners = { priority: new Set(), full: new Set() };
  const progress = {priority:{done:0,total:0},full:{done:0,total:0}};
  let defs, lanes = Array.from({length: ARTWORK_LANES}, () => Promise.resolve()), nextLane = 0;
  const notify = () => {
    for (const [phase, list] of Object.entries(listeners)) for (const cb of list) {
      try { cb(progress[phase].done, progress[phase].total); } catch { /* reporting cannot fail art */ }
    }
  };
  const prepare = image => {
    const lane = nextLane++ % lanes.length;
    const task = lanes[lane] = lanes[lane].then(async () => {
      try { await manager.atlas.tinted(image.screen, Number(image.index), image.color); }
      catch (error) { failures.push(String(error?.message || error)); }
    });
    return task;
  };
  const batch = async (selected, phase) => {
    const tasks = [];
    await eachBounded(selected, SCRIPT_LANES, async def => {
      const panelTasks = [];
      try {
        const parsed = typeof def.script === 'object' ? {windows: [def.script]} : await manager.loadScript(def.script);
        const discovered = new Map();
        for (const spec of [...(parsed.windows || []), ...(parsed.fragments || [])]) panelImages(spec, discovered);
        for (const [key, image] of discovered) {
          if (!images.has(key)) images.set(key, prepare(image));
          tasks.push(images.get(key)); panelTasks.push(images.get(key));
        }
      } catch (error) { failures.push(String(error?.message || error)); }
      await Promise.all(panelTasks);
      progress[phase].done++;
      if (phase === 'priority') progress.full.done++;
      notify();
    });
    await Promise.all(tasks);
    notify();
    return {panels: selected.length, sprites: images.size, failures: failures.slice()};
  };
  const messageScripts = ['game2/msgbox/ui_resultbox.txt','game2/msgbox/ui_msgbox_edit.txt','game2/msgbox/ui_msgbox_progress.txt','game2/msgbox/ui_msgbox_ok.txt','game2/msgbox/cashitem/ui_waringbuycashitem.txt','game2/msgbox/cashitem/ui_confirmbuy.txt','game2/msgbox/cashitem/ui_resultbuy_cashinventory.txt'];
  const priority = Promise.resolve(manager.ready).then(async () => {
    defs = [...manager.defs.entries()].filter(([,d]) => !d.alias && d.script).map(([name,d]) => ({...d,name}));
    const selected = defs.filter(d => d.hud || PRIORITY_PANELS.includes(d.name));
    progress.priority.total = selected.length;
    progress.full.total = defs.length + messageScripts.filter(script => !defs.some(d => d.script === script)).length;
    notify();
    return batch(selected, 'priority');
  });
  let full;
  return { priority,
    request({priorityOnly = false, onProgress} = {}) {
      const phase = priorityOnly ? 'priority' : 'full';
      if (onProgress) { listeners[phase].add(onProgress); try { onProgress(progress[phase].done, progress[phase].total); } catch {} }
      const promise = priorityOnly ? priority : (full ||= priority.then(async () => {
        const rest = defs.filter(d => !d.hud && !PRIORITY_PANELS.includes(d.name));
        for (const script of messageScripts) {
          if (!defs.some(d => d.script === script)) rest.push({script});
        }
        const result = await batch(rest, 'full');
        return {...result, panels: defs.length + rest.filter(d => !d.name).length};
      }));
      if (onProgress) promise.then(() => listeners[phase].delete(onProgress), () => listeners[phase].delete(onProgress));
      return promise;
    }
  };
}
export function prewarmPanels(manager, options = {}) {
  return createPanelPrewarm(manager).request(options);
}
