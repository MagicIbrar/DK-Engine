// One bounded shared worker. Blob URLs stay owned by the main-thread preview cache.
self.onmessage = async ({ data }) => {
  if (data?.kind !== 'preview-png') return;
  const { id, width, height, rgba } = data; let canvas;
  try {
    if (!Number.isInteger(width) || !Number.isInteger(height) || width < 1 || height < 1 || width * height * 4 > 4096 * 4096 * 4 || !(rgba instanceof ArrayBuffer) || rgba.byteLength !== width * height * 4) throw Error('Invalid preview pixel buffer');
    canvas = new OffscreenCanvas(width, height);
    const context = canvas.getContext('2d', { alpha: true }); if (!context) throw Error('Worker 2D context unavailable');
    context.putImageData(new ImageData(new Uint8ClampedArray(rgba), width, height), 0, 0);
    const blob = await canvas.convertToBlob({ type: 'image/png' });
    if (!blob?.size || blob.type !== 'image/png') throw Error('Worker PNG unavailable');
    self.postMessage({ kind: 'preview-png-result', id, blob });
  } catch (error) { self.postMessage({ kind: 'preview-png-result', id, error: String(error?.message || error) }); }
  finally { if (canvas) { try { canvas.width = canvas.height = 0; } catch {} } }
};
