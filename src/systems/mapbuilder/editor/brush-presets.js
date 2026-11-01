export const BRUSH_PRESETS = {
  hill: { tool: 'raise', radius: 10, strength: 3, falloff: 'soft' },
  valley: { tool: 'lower', radius: 10, strength: 3, falloff: 'soft' },
  detail: { tool: 'raise', radius: 2, strength: 1, falloff: 'smooth' },
  soften: { tool: 'smooth', radius: 6, strength: 4, falloff: 'smooth' },
  plateau: { tool: 'flatten', radius: 8, strength: 6, falloff: 'linear' },
  paint: { tool: 'vcolor', radius: 4, strength: 3, falloff: 'soft' },
};
