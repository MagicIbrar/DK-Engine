import { fetchJSON } from './assets.js';
import { breathe } from './yield.js';
import { STARTUP_JSON, DEFERRED_JSON, JSON_PREFETCH_LANES } from '../config/engine-chosen-loading.js';
import { awaitLoadingStage } from './loading-deadline.js';
import { warmWholeScene } from './warm-draw.js';
// Catalogs shared by login/selection and the game. Models for the chosen map and
// actors are prepared by their scene loaders; this is not whole-game GPU residency.
export const STARTUP_CATALOGS = Object.freeze([...new Set([...STARTUP_JSON, ...DEFERRED_JSON,
  'classes', 'frontend', 'sound', 'skills_effects', 'skills_status', 'dungeons', 'events'])]);
export async function prepareStartupCatalogs({read=fetchJSON,onProgress=()=>{},names=STARTUP_CATALOGS,yieldTask=breathe}={}) {
  let cursor=0,done=0;
  onProgress(done,names.length);
  await Promise.all(Array.from({length:JSON_PREFETCH_LANES},async()=>{
    while(cursor<names.length){const name=names[cursor++];await read(`/gamedata/${name}.json`);onProgress(++done,names.length,name);await yieldTask();}
  }));
  return {completed:done,total:names.length};
}
// Overall startup percentage counts three completed preparation phases. It is
// neither downloaded-byte percentage nor a prediction of remaining seconds.
export function startupPhaseProgress(phase,fraction=0){
  if(!Number.isInteger(phase)||phase<0||phase>2)throw new Error('Invalid startup phase');
  return (phase+Math.max(0,Math.min(1,Number(fraction)||0)))/3;
}
export async function prepareStartupScene(stage,{onProgress=()=>{}}={}) {
  if (!stage.world) throw new Error('Login scene did not finish loading. Retry loading.');
  if (stage.renderer.getContext?.()?.isContextLost?.()) throw new Error('Graphics context was lost. Retry loading.');
  onProgress(0,'Preparing startup graphics');
  stage.world.update?.(0,stage.camera.position);
  if (typeof stage.renderer.compileAsync==='function') await awaitLoadingStage(()=>stage.renderer.compileAsync(stage.scene,stage.camera),{stage:'Startup graphics',current:()=>!stage._disposed&&!stage.renderer.getContext?.()?.isContextLost?.()});
  onProgress(0.5,'Warming startup graphics');
  warmWholeScene(stage);
  stage.renderer.render(stage.scene,stage.camera);
  onProgress(1,'Startup graphics ready');
}
