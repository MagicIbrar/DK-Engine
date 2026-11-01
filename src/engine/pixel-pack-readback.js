// A concurrent async readback can retain its PBO while waiting on a GPU fence.
// Synchronous typed-array readPixels must temporarily use no PIXEL_PACK_BUFFER.
export function readRenderTargetPixels(renderer, ...args) {
  const gl = renderer.getContext?.();
  if (!gl || gl.PIXEL_PACK_BUFFER === undefined || !ArrayBuffer.isView(args[5])) {
    return renderer.readRenderTargetPixels(...args);
  }
  const previous = gl.getParameter(gl.PIXEL_PACK_BUFFER_BINDING);
  try {
    gl.bindBuffer(gl.PIXEL_PACK_BUFFER, null);
    return renderer.readRenderTargetPixels(...args);
  } finally {
    gl.bindBuffer(gl.PIXEL_PACK_BUFFER, previous);
  }
}
