// lane-perf: the load-time scene compile as one renderer.compileAsync per top-level child (each against the whole scene, so
// lights / fog / program keys are the same as one compileAsync(scene)), so the loading bar advances with finished work, then a
// final compileAsync(scene) that finds everything built. three r170 compileAsync uses KHR_parallel_shader_compile when present.
export async function compileSceneInParts(renderer, scene, camera, onProgress = () => {}) {
  const parts = scene.children.filter(o => !o.isLight && o.visible !== false);
  onProgress(0, parts.length);
  for (let i = 0; i < parts.length; i++) { await renderer.compileAsync(parts[i], camera, scene); onProgress(i + 1, parts.length); }
  await renderer.compileAsync(scene, camera);
  return parts.length;
}
