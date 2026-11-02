// Stream B (gfx parity, effects) runtime off switches. Every Global-43.19 effects fix landed by stream B is gated here so it
// can be turned off at runtime without a rebuild:
//   globalThis.__dekaronGfxB = { questMarkNative: false }   // console / boot override; missing keys keep the default
// Defaults are ON (the Global-derived behaviour). Each switch is documented inline below with its Global source (the
// stream-B LANDED-B.md note it used to point to was never shipped).
export const GFX_B_DEFAULTS = Object.freeze({
  questMarkNative: true,   // NPC quest marks play Global's modeleffect.csv code1 18 scenes (1:2551 ...) instead of 11:2220
  wingTpackNoRelocate: true, // Wings of Demon God mh_SUM_WING02: keep Global's absent Effect\Wing tpack path (no engine relocation)
  // ---- stream B2 (2026-10-29): engine-chosen / fitted effect values replaced by what the Global 43.19 data states or implies
  auraBlurGlow: true,        // aura composite = binary/blurglow.fx: 4 additive directional passes (+-0.75 x, +-1 y), 4 taps each, ONE/ONE, no Z; taps/weights = bloomeffect.fx kernel halves, unit gain (was FITTED TAP_SCALE 2.2 / PASSES 2 / GAIN 4)
  auraNoDistanceCap: true,   // no 70 m aura cut-off: Global has no glow distance rule, the camera far plane (option.txt clipfar) is the only limit
  // GLOW-RESTORE 2026-10-30: OFF. With it on, the refinement (enhancement) shine drew at the authored ~0.4-0.5 alpha of a 230-grey
  // tint (gain 1, no rim, no aura source) and was practically invisible: the silver/blue/gold/red/purple armor + weapon glow
  // players saw before gfx-B2 (10/29) was gone. Off = the previous tier gain (x2-2.5), tier-hue rim light and aura source
  // (hues = the colour of Global's own eff_upgrade_13/46/79/1114/15 tier textures). Console: __dekaronGfxB = {refineShellAuthored:true}.
  refineShellAuthored: false, // on = refinement shells draw texture x colour x alpha only (effectscene 7:10): no x2-2.5 gain, no tier rim light / HUES, no aura source
  socketWashOff: true,       // no gem-coloured weapon wash: Global data authors no weapon tint (only modeleffect group 24 -> one sprite scene per stone attribute)
  refineLoopAuthored: true,  // refinement shine plays its authored length: effectscene 7:10 `lifetime 0 1000` (was 3500 ms by eye); socket loop = modeleffect group 24 eff_time 1000 (was 4000)
  itemGlassOff: true,        // no 0.3-opacity bottle glass: gen_pot_cas_bottle.dds is DXT1 with no transparent texels and no blend data -> drawn as the data says
  yaxisHeightZ: true,        // yaxis sprite quad height = size x scale.z (Global authors upright sprites in z: Dani_Sacra sp_red_vertical (3,1,10),
                              // sp_emitedflash_lighting_01 (0,0,35), bon_fire_01/bon_blue_fire_01 sp_fire flame (0.8,2,1)); was scale.y -> 2x-tall braziers
  scrollAlphaBlend: true,    // round 3: UV-scrolling table objects (uvx/uvy/uvspeed, transparent 0) whose texture alpha is smooth (DXT3/5) are alpha
                              // blended, not cut at alphaTest 0.5: Global g195 shows the a_fountain-01-* jets (a_fountain_01.dds DXT3, alpha 0..221)
                              // as soft continuous water; the 0.5 cut is ENGINE-CHOSEN (no Global .fx/table sets an alpha ref for map objects)
  // GLOW-RESTORE 2026-10-30 (icons): the three icon halo switches are OFF again (halos on). Global's inventory icons show the tier glow; its pulse is the
  // authored UI upgrade scene alpha (effectscene.com cate 8:21..25, lifetime 0 1000). The halo sizes/strengths are ENGINE-DEFAULT (no Global source).
  previewTierAuraOff: false, // round 3 (was true): no tier tint / silhouette halos on weapon icons (TIER_AURA + FAMILY_HUE are ENGINE-CHOSEN); the authored UI upgrade scene still plays
  previewFortifyOff: false,  // round 3 (was true): no +4..+10 rim-light boost on icon specular (FORTIFY_STRENGTH 0.4, 'engine approximation'; the tier curve is in the exe)
  previewGlowHaloOff: false, // round 3 (was true): no canvas blur halo (radius 3, strength 0.9 ENGINE-CHOSEN) around glow-mapped icon pixels; the glow map stays on the surface
  trailAuthoredCount: true,  // tailstep copies = authored count (max 300 in effectdata); the 128 cap cut 6 units
  // ---- LANE-54 (2026-10-29): Global mesh alpha modes (src/engine/global-alpha-modes.js) replace the ENGINE-CHOSEN alphaTest 0.5
  globalAlphaModes: true,    // DDS textures: DXT1/A1R5G5B5 cut at ALPHAREF 240 (none if in DXTAlphaFilterTable.txt); DXT3/DXT5/A8R8G8B8/A4R4G4B4
                              // blended at ALPHAREF 1 (SrcAlpha/InvSrcAlpha, '#' names SrcAlpha/One), depth writes on. 64-bit Bone::Normal
                              // 7ff6716aa930 / vf01 7ff6716aafb0 / vf02 7ff6716ab000, presets 7ff6716c9870, class 32-bit FUN_0151e070
  // ---- LANE-54 pass 5 (2026-10-29): step 7 map objects / effect meshes
  occlusionHideOff: true,    // no camera-occlusion hiding of map props (objects.js _occlusion; OCC_INTERVAL / OCC_MAX_R / OCC_SHRINK are
                              // ENGINE-CHOSEN, no Global constant or code path: FieldImpl slot 3 FUN_7ff671737340 / FUN_7ff6717378a0 submits
                              // every field object with colour 0xFFFFFFFF and no camera test) -> removes the pumpkin / prop flutter
  effectMeshDepthWrite: true, // effect Mesh units keep depth writes in every bucket: FUN_7ff6716ab050 (transparent buckets) and the presets
                              // FUN_7ff6716c9870 never set D3DRS_ZWRITEENABLE (0xe); the bone passes restore it to 1
  // ---- LANE-70b (2026-10-29): weapon effects
  iconSocketWashOff: true,   // inventory/equipment socket glow = only the authored UI sprite (effectscene cate 8 ids 1..6) at its authored alpha:
                              // no gem-coloured tint/wash over the icon art, no blurred halo stack, no SPRITE_GAIN 1.3 (all ENGINE-CHOSEN ICON values)
  socketSpriteAuthored: true, // equipped socket scene (7:1..6) at its authored size/scale keys: no stationScale (SPRITE_SPACING .4, clamp .6..1.5)
                              // and no MIST_DEPTH_BIAS camera shift (both ENGINE-CHOSEN, engine-chosen-socket-glow.js)
  effectMeshLit: true,       // effect Mesh units are lit like every Global binary/boneanimation.fx technique (g_f3ambient + N.L x
                              // g_f3ColorWithIntensity, BoneAnimDiffuse ADLighting); no boneanimation.fx technique is unlit
  // ---- LANE-70 (2026-10-29): wings / shared engine, 70b handoff
  // GLOW-RESTORE 2026-10-30: OFF so preview windows show the same refinement-tier / gem aura as the world (refineShellAuthored off).
  previewAuraAuthored: false, // on = preview windows (mounts/preview-aura.js) add no refinement-tier or gem aura source: tierHue (FAMILY_HUE, ENGINE-CHOSEN
                              // colours) and the gem-hue halo have no Global source, the same as refineShellAuthored / socketWashOff in the world
});
export function gfxB(name) {
  const o = globalThis.__dekaronGfxB;
  if (o && typeof o === 'object' && Object.prototype.hasOwnProperty.call(o, name)) return o[name] !== false;
  return GFX_B_DEFAULTS[name] !== false;
}
