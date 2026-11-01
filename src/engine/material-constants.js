// Constants of the client's armour / weapon / glow shaders (data/binary/boneanimation.fx, itemmesh.fx, glow.fx,
// blurglow.fx) that the material code (src/engine/matfx.js) uses. Each one is either DERIVED from the Global data
// (the source is named) or ENGINE-CHOSEN: the exe sets that shader uniform at run time, the value is in no data
// file, and the engine picks a reasonable value (the reason is given). Tests: tools/test-mat-armor-weapon-fx.mjs.

/**
 * DERIVED. boneanimation.fx "BoneAnimEnv" samples `textureCUBE envTexture` (texCUBE(envSampler, f3Reflect)). The only
 * cube map among the 37,695 DDS files of the data is texture/environment/cube/test=.dds (128x128 DXT1, all six faces
 * the same: soft white light spots on black), listed in script/dxtalphafiltertable.txt with the textures the client
 * loads. The map EnvironmentMap strips (texture/water/skycube*.dds) are plain 2D textures a texCUBE cannot sample:
 * they are the water reflection only.
 */
export const ENV_CUBE_KEY = 'texture/environment/cube/test=.dds';

/** DERIVED. glow.fx `uniform float4 glowColor = { 0.4f, 0.4f, 0.4f, 1.0f }` (glow buffer = glowTexture x glowColor x baseColor). */
export const GLOW_COLOR = 0.4;

/** DERIVED. itemmesh.fx ps2Specular: pow(max(0, N.H), g_fShininess) x g_f3ColorWithIntensity x 1.2. */
export const ITEM_SPECULAR_SCALE = 1.2;

/**
 * ENGINE-CHOSEN (not in Global data): g_fShininess of itemmesh.fx (weapons, drops). The exe sets it; item tables carry
 * no shininess. 30 = the value the data uses for 7,169 of 7,478 rows of the only shininess column the client has
 * (script/object/*.csv, column 17, the same shader uniform for map objects).
 */
export const ITEM_SHININESS = 30;

/** ENGINE-CHOSEN (not in Global data): f4GlobalColor (vertex colour multiplier of every bone/item shader) = white. */
export const GLOBAL_COLOR = 1;

/** ENGINE-CHOSEN (not in Global data): f4SpecularColor (constant added to COLOR0 / COLOR1 by boneanimation.fx) = 0. */
export const SPECULAR_COLOR = 0;

/** ENGINE-CHOSEN (not in Global data): glow.fx baseColor (multiplies glowColor) = white. */
export const GLOW_BASE_COLOR = 1;

/**
 * ENGINE-CHOSEN (not in Global data): blurglow.fx weight0..3 / uvoffset0..3 (four additive directional blur passes of
 * the glow buffer). The engine keeps the glow buffer's own strength on the surface (emissive = glowColor x baseColor x
 * glow texture) and lets the bloom pass spread the halo.
 */
export const GLOW_COMPOSITE = 'emissive glowColor x baseColor x glowTexture + bloom halo';

/**
 * ENGINE-CHOSEN (not in Global data): the eye-vector convention of boneanimation.fx / itemmesh.fx. The text writes
 * reflect(eyeToVertex, N) and H = normalize(L - eye) with eye = normalize(g_f3EyePos - position), and the item vertex
 * shader takes that position from the clip-space output; read literally, H never faces a front-facing surface and the
 * 1.2 x specular map term of ps2Specular could not show. The exe's real eye value is not in the data, so the engine uses
 * the textbook view vector V (vertex -> camera): H = normalize(L + V), R = reflect(-V, N) (physical reflection).
 */
export const EYE_CONVENTION = 'H = normalize(L + V), R = reflect(-V, N)';

// ------------------------------------------------------------------------------- texture sampler state
// share/maplist.csv gives every map the Direct3D 9 sampler state its textures are drawn with: MipMapEnable,
// MipMapBias (D3DSAMP_MIPMAPLODBIAS), MipMapFilter (D3DSAMP_MIPFILTER), MaxFilter (D3DSAMP_MAGFILTER), MinFilter
// (D3DSAMP_MINFILTER), the filters as D3DTEXTUREFILTERTYPE (0 NONE, 1 POINT, 2 LINEAR, 3 ANISOTROPIC).
// src/engine/sampler-state.js maps them to WebGL; tools/test-mat-texture-sampling.mjs.

/**
 * DERIVED. The Global client's data/shadow.txt (the install, next to the pack) has `anisotropy_filtering 0`, and no
 * maplist row uses D3DTEXF_ANISOTROPIC (3): textures are sampled without anisotropy on every map.
 */
export const SAMPLER_ANISOTROPY = 1;

/**
 * ENGINE-CHOSEN (not in Global data): what MipMapEnable switches. The engine reads it as "apply MipMapBias": the bias
 * is used when MipMapEnable is exactly 1 (95 of the 301 rows: -0.5 on fields / dungeons, -10 on the selection maps, 0), and
 * ignored otherwise (0, and the one malformed row 20 / 30 of Arcadia - Prison, which as a bias of +30 would pin every
 * texture to its smallest mip). MipMapFilter alone decides whether mips are sampled.
 */
export const SAMPLER_BIAS_GATE = 'MipMapBias applies when MipMapEnable === 1';

/**
 * ENGINE-CHOSEN (not in Global data): MaxFilter / MinFilter 0 (D3DTEXF_NONE is not a valid magnification /
 * minification filter in D3D9; the runtime samples it as POINT). A value outside 0..3 samples as LINEAR.
 */
export const SAMPLER_NONE_FILTER = 'D3DTEXF_NONE as MAG/MIN filter = POINT; out of range = LINEAR';

/**
 * ENGINE-CHOSEN (not in Global data): shadow.txt `trilinear_filtering 0` is an Options switch of the exe whose effect is
 * not in the files; the maplist MipMapFilter is used as written.
 */
export const SAMPLER_TRILINEAR_OPTION = 'maplist MipMapFilter used as written (shadow.txt trilinear_filtering 0)';

/**
 * ENGINE-CHOSEN (not in Global data): which samplers the map state reaches. The exe sets the sampler states itself; the
 * engine applies the filters to every TextureCache 2D texture (objects, actors, items, water, decals) and the LOD bias to
 * the diffuse map of every lit world material (shade.js). The terrain tile atlas (terrain.js), cube maps and
 * the front-end / tool caches keep the engine default (no map row).
 */
export const SAMPLER_SCOPE = 'filters: TextureCache 2D textures; bias: diffuse map of shade.js materials';

/** ENGINE-CHOSEN (not in Global data): with no map loaded, textures use linear + linear mips, bias 0, anisotropy 4. */
export const SAMPLER_DEFAULT = 'no map: LINEAR / LINEAR / LINEAR mips, bias 0, anisotropy 4';

// ------------------------------------------------------------------------------- terrain + sky
// Terrain / decals follow data/binary/geometry.fx MapLight exactly (tile x saturate(vertexColour x (g_ambient + sun x N.L x
// shade)); src/world/terrain.js, tools/test-matfx-shader-parity.mjs): no constant is needed there. The sky is
// data/binary/skybox.fx technique Skybox (COLOR0 = vertex.color x globalColor, Texture[0] sky, Texture[1] cloud, no pixel
// shader); the exe builds the dome and sets the uniforms / stage ops:

/** ENGINE-CHOSEN (not in Global data): skybox.fx vertex.color x globalColor = white (the exe's dome mesh and uniform). */
export const SKY_DIFFUSE = 1;

/**
 * ENGINE-CHOSEN (not in Global data): the fixed-function stage ops of skybox.fx (PixelShader = NULL). Stage 0 = D3D9's
 * default MODULATE(sky texture, COLOR0); stage 1 = BLENDTEXTUREALPHA: the cloud layer over the sky by its own alpha x the
 * light file cloud_type alpha (4th value / 255). Nothing is added: the old "+ 0.25 x alpha" cloud lift is gone.
 */
export const SKY_STAGE_OPS = 'stage0 MODULATE(sky, COLOR0); stage1 BLENDTEXTUREALPHA(cloud x cloud_type alpha)';

/**
 * ENGINE-CHOSEN (not in Global data): the dome geometry the exe builds. The engine samples the 512x256 gradient by
 * elevation (row 0 zenith, row 128 horizon), blends its alpha over the fog colour below the horizon, and projects the
 * cloud layer on a plane (uv = dir.xz / (dir.y + 0.25) x 0.35, fading in over dir.y 0.02..0.3, drift 0.004 x speed).
 */
export const SKY_GEOMETRY = 'elevation gradient over the fog colour; planar cloud projection';

/**
 * ENGINE-CHOSEN (not in Global data): geometry.fx MapLight's Texture[1] (shadowTexture, built by the exe). The engine's
 * optional sun shadow map removes the sun term only (three DirectionalLight shadow), the ambient term stays.
 */
export const TERRAIN_SHADOW = 'shadow map scales the sun term only';

/** Every engine-chosen value, for the pass evidence / test report. */
export const ENGINE_CHOSEN = {
  SKY_DIFFUSE: `${SKY_DIFFUSE} (skybox.fx vertex.color x globalColor)`,
  SKY_STAGE_OPS,
  SKY_GEOMETRY,
  TERRAIN_SHADOW,
  SAMPLER_BIAS_GATE,
  SAMPLER_NONE_FILTER,
  SAMPLER_TRILINEAR_OPTION,
  SAMPLER_SCOPE,
  SAMPLER_DEFAULT,
  ITEM_SHININESS: `${ITEM_SHININESS} (g_fShininess, itemmesh.fx)`,
  EYE_CONVENTION: `${EYE_CONVENTION} (g_f3EyePos sign / meaning)`,
  GLOBAL_COLOR: `${GLOBAL_COLOR} (f4GlobalColor)`,
  SPECULAR_COLOR: `${SPECULAR_COLOR} (f4SpecularColor)`,
  GLOW_BASE_COLOR: `${GLOW_BASE_COLOR} (glow.fx baseColor)`,
  GLOW_COMPOSITE: `${GLOW_COMPOSITE} (blurglow.fx weights)`,
};
