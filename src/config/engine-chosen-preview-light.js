// Lights of the 3D model preview windows (systems/mounts/ui-util.js ModelPreview: Inspect / character preview, costume,
// wing, chat-link and D-Shop body previews; systems/shops/preview.js ModelPreview: the D-Shop item Preview and box Detail pane).
// ENGINE-CHOSEN: the client exe sets these lights; they are not in the data.
// UNITS (measured fix for dim / grey armour in the preview): three r170 divides light by PI
// (BRDF_Lambert), and the world (world/environment.js) and the icons (items/preview-materials.js ICON_LIGHT) give their
// lights in x PI units. The old preview values 0.8 / 0.8 were not in those units and drew the model at 31 % of its texture
// brightness (measured: lit mean 35.8 vs texture 115.6).
// LEVEL: D3D9 saturates ambient + N.L x light before it modulates the texture, so a lit surface is never brighter than
// its texture. The preview materials have no clamp (0.8 / 0.8 x PI measured 24 % of pixels brighter than their texture),
// so ambient + key = 1 keeps that rule without a clamp (a face turned to the key light shows exactly its texture).
// The ambient : key ratio 1 : 1 is the preview's previous ratio.
export const PREVIEW_LIGHT = Object.freeze({ ambient: 0.5 * Math.PI, key: 0.5 * Math.PI });
