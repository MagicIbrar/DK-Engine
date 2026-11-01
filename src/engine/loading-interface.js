import {prepareEntryPanels} from '../ui/uiwin/prebuild.js';
// Required entry preparation waits for completion. A caller can explicitly ask
// for bounded optional warmup, but that policy must never admit the game early.
export async function finishInterfaceWarmup(game, {maxMs = null, onArtworkProgress, onPanelProgress, onIconProgress, onWaiting} = {}) {
  const previousIconProgress = game._shopIconProgress;
  if (onIconProgress) {
    game._shopIconProgress = onIconProgress;
    const state = game._shopIconWarmup;
    if (state) onIconProgress(state.done, state.total);
  }
  const work = {};
  if (game._uiArtReady) {
    work.artwork = Promise.all([game._uiArtReady, game.uiwin.prewarm({priorityOnly:maxMs!=null,prebuild:false,onProgress:onArtworkProgress})])
      .then(results=>{game._interfaceArtworkReport=results[1];return results;});
    game._uiArtReady = null;
  }
  work.icons = Promise.all(game._interfaceIconTasks || []);
  game._interfaceIconTasks = [];
  if (!game._joinedInventoryWarmDone) {
    game._joinedInventoryWarmDone = true;
    work.inventory = game.items?._warm?.();
  }
  // Full registration is complete before entry. Wait for the art phase before
  // sequential panel construction so the progress display cannot skip ahead.
  work.panels = maxMs==null&&game.uiwin.defs instanceof Map
    ? Promise.resolve(work.artwork).then(()=>prepareEntryPanels(game.uiwin,{onProgress:onPanelProgress}))
    : Promise.all(['skills','dshop'].filter(name=>game.uiwin.has(name)).map(name=>game.uiwin.get(name)));
  let timer;
  const pending=new Set(Object.keys(work)),timings={};
  const began=performance.now();
  game._interfaceWarmupTimings=timings;
  const tracked=Object.entries(work).map(([name,job])=>[name,Promise.resolve(job).then(value=>{
    timings[name]=Math.round(performance.now()-began);pending.delete(name);
    // A completed panel counter must not hide another required image task.
    if(!pending.has('panels')&&pending.size)try{onWaiting?.({pending:[...pending]});}catch{}
    return value;
  })]);
  const deadline = maxMs==null?null:new Promise(resolve=>{timer=setTimeout(()=>resolve(false),maxMs);});
  try {
    return Object.fromEntries(await Promise.all(tracked.map(async ([name,job])=>
      [name,await (deadline?Promise.race([Promise.resolve(job).then(()=>true),deadline]):Promise.resolve(job).then(()=>true))])));
  } finally { clearTimeout(timer); game._shopIconProgress = previousIconProgress; }
}
