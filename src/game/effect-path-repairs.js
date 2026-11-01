// ENGINE-CHOSEN repairs of shipped effect references to existing Global assets.
// Exact unit + original path allowlist; no fuzzy search, no imported artwork.
// Sources: presentation P5 / skill-basename-fallback.json (2026-10-13).
// A valid authored path always takes priority in the caller.
export const EFFECT_PATH_REPAIRS = Object.freeze([
  {
    "unit": "02:mh_cetus_hunter_lighting",
    "from": "anim/effect/monster/cetus_hunter_lighting.anim",
    "to": "anim/effect/cetus_hunter_lighting.anim"
  },
  {
    "unit": "03:mh_ancient_sum_soul_att2",
    "from": "mesh/effect/monster/ancient_summoner_soul.mesh",
    "to": "mesh/monster/ancient_summoner_soul.mesh"
  },
  {
    "unit": "03:mh_ancient_sum_soul_att2",
    "from": "texturepack/effect/monster/ancient_summoner_soul.tpack",
    "to": "texturepack/monster/ancient_summoner_soul.tpack"
  },
  {
    "unit": "03:mh_ancient_sum_soul_att2",
    "from": "anim/effect/monster/ancient_summoner_soul_att2.anim",
    "to": "anim/monster/ancient_summoner_soul/ancient_summoner_soul_att2.anim"
  },
  {
    "unit": "03:mh_ancient_sum_soul_att2",
    "from": "skel/effect/monster/ancient_summoner_soul.skel",
    "to": "skel/monster/ancient_summoner_soul.skel"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att3",
    "from": "mesh/effect/monster/ancient_magician_soul.mesh",
    "to": "mesh/monster/ancient_magician_soul.mesh"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att3",
    "from": "texturepack/effect/monster/ancient_magician_soul.tpack",
    "to": "texturepack/monster/ancient_magician_soul.tpack"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att3",
    "from": "anim/effect/monster/ancient_magician_soul_att_a2.anim",
    "to": "anim/monster/ancient_magician_soul/ancient_magician_soul_att_a2.anim"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att3",
    "from": "skel/effect/monster/ancient_magician_soul.skel",
    "to": "skel/monster/ancient_magician_soul.skel"
  },
  {
    "unit": "03:mh_ancient_sum_soul_att3",
    "from": "mesh/effect/monster/ancient_summoner_soul.mesh",
    "to": "mesh/monster/ancient_summoner_soul.mesh"
  },
  {
    "unit": "03:mh_ancient_sum_soul_att3",
    "from": "texturepack/effect/monster/ancient_summoner_soul.tpack",
    "to": "texturepack/monster/ancient_summoner_soul.tpack"
  },
  {
    "unit": "03:mh_ancient_sum_soul_att3",
    "from": "anim/effect/monster/ancient_summoner_soul_att3.anim",
    "to": "anim/monster/ancient_summoner_soul/ancient_summoner_soul_att3.anim"
  },
  {
    "unit": "03:mh_ancient_sum_soul_att3",
    "from": "skel/effect/monster/ancient_summoner_soul.skel",
    "to": "skel/monster/ancient_summoner_soul.skel"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att4",
    "from": "mesh/effect/monster/ancient_magician_soul.mesh",
    "to": "mesh/monster/ancient_magician_soul.mesh"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att4",
    "from": "texturepack/effect/monster/ancient_magician_soul.tpack",
    "to": "texturepack/monster/ancient_magician_soul.tpack"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att4",
    "from": "anim/effect/monster/ancient_magician_soul_att_a1.anim",
    "to": "anim/monster/ancient_magician_soul/ancient_magician_soul_att_a1.anim"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att4",
    "from": "skel/effect/monster/ancient_magician_soul.skel",
    "to": "skel/monster/ancient_magician_soul.skel"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att1",
    "from": "mesh/effect/monster/ancient_magician_soul.mesh",
    "to": "mesh/monster/ancient_magician_soul.mesh"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att1",
    "from": "texturepack/effect/monster/ancient_magician_soul.tpack",
    "to": "texturepack/monster/ancient_magician_soul.tpack"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att1",
    "from": "anim/effect/monster/ancient_magician_soul_att_b1.anim",
    "to": "anim/monster/ancient_magician_soul/ancient_magician_soul_att_b1.anim"
  },
  {
    "unit": "03:mh_ancient_sor_soul_att1",
    "from": "skel/effect/monster/ancient_magician_soul.skel",
    "to": "skel/monster/ancient_magician_soul.skel"
  },
  {
    "unit": "03:mh_mon_gavian_praet_att1",
    "from": "mesh/effect/monster/gavian_praet.mesh",
    "to": "mesh/monster/gavian_praet.mesh"
  },
  {
    "unit": "03:mh_mon_gavian_praet_att1",
    "from": "texturepack/effect/monster/gavian_praet.tpack",
    "to": "texturepack/monster/gavian_praet.tpack"
  },
  {
    "unit": "03:mh_mon_gavian_praet_att1",
    "from": "anim/effect/monster/gavian_praet_att1.anim",
    "to": "anim/monster/gavian_praet/gavian_praet_att1.anim"
  },
  {
    "unit": "03:mh_mon_gavian_praet_att1",
    "from": "skel/effect/monster/gavian_praet.skel",
    "to": "skel/monster/gavian_praet.skel"
  },
  {
    "unit": "03:mh_mon_gavian_praet_att2",
    "from": "mesh/effect/monster/gavian_praet.mesh",
    "to": "mesh/monster/gavian_praet.mesh"
  },
  {
    "unit": "03:mh_mon_gavian_praet_att2",
    "from": "texturepack/effect/monster/gavian_praet.tpack",
    "to": "texturepack/monster/gavian_praet.tpack"
  },
  {
    "unit": "03:mh_mon_gavian_praet_att2",
    "from": "anim/effect/monster/gavian_praet_att2.anim",
    "to": "anim/monster/gavian_praet/gavian_praet_att2.anim"
  },
  {
    "unit": "03:mh_mon_gavian_praet_att2",
    "from": "skel/effect/monster/gavian_praet.skel",
    "to": "skel/monster/gavian_praet.skel"
  },
  {
    "unit": "03:mh_mon_gavian_quaestor_att1",
    "from": "mesh/effect/monster/gavian_quaestor.mesh",
    "to": "mesh/monster/gavian_quaestor.mesh"
  },
  {
    "unit": "03:mh_mon_gavian_quaestor_att1",
    "from": "texturepack/effect/monster/gavian_quaestor.tpack",
    "to": "texturepack/monster/gavian_quaestor.tpack"
  },
  {
    "unit": "03:mh_mon_gavian_quaestor_att1",
    "from": "anim/effect/monster/gavian_quaestor_att1.anim",
    "to": "anim/monster/gavian_quaestor/gavian_quaestor_att1.anim"
  },
  {
    "unit": "03:mh_mon_gavian_quaestor_att1",
    "from": "skel/effect/monster/gavian_quaestor.skel",
    "to": "skel/monster/gavian_quaestor.skel"
  },
  {
    "unit": "03:mh_mon_gavian_quaestor_att2",
    "from": "mesh/effect/monster/gavian_quaestor.mesh",
    "to": "mesh/monster/gavian_quaestor.mesh"
  },
  {
    "unit": "03:mh_mon_gavian_quaestor_att2",
    "from": "texturepack/effect/monster/gavian_quaestor.tpack",
    "to": "texturepack/monster/gavian_quaestor.tpack"
  },
  {
    "unit": "03:mh_mon_gavian_quaestor_att2",
    "from": "anim/effect/monster/gavian_quaestor_att2.anim",
    "to": "anim/monster/gavian_quaestor/gavian_quaestor_att2.anim"
  },
  {
    "unit": "03:mh_mon_gavian_quaestor_att2",
    "from": "skel/effect/monster/gavian_quaestor.skel",
    "to": "skel/monster/gavian_quaestor.skel"
  },
  {
    "unit": "01:mh_recovery_test",
    "from": "anim/character/bard/imsi/bar_skl_haf_focusing_01.anim",
    "to": "anim/character/bard/skill/bar_skl_haf_focusing_01.anim"
  },
  {
    "unit": "01:mh_drag_cel_test",
    "from": "anim/character/bard/imsi/bar_skl_cel_drag.anim",
    "to": "anim/character/bard/skill/bar_skl_cel_drag.anim"
  },
  {
    "unit": "02:mh_mal_replica_remote_02",
    "from": "skel/effect/monster/eff_carcer_remote.skeleffect/monster/eff_carcer_remote.skel",
    "to": "skel/effect/monster/eff_carcer_remote.skel"
  },
  {
    "unit": "03:mh_bar_tron_froud",
    "from": "anim/character/bard/imsi/bar_skl_cel_tron_froud.anim",
    "to": "anim/character/bard/skill/bar_skl_cel_tron_froud.anim"
  },
  {
    "unit": "03:mh_test9",
    "from": "mesh/mon_bluedragon.mesh",
    "to": "mesh/monster/mon_bluedragon.mesh"
  },
  {
    "unit": "03:mh_test9",
    "from": "texturepack/poseidon_hard.tpack",
    "to": "texturepack/monster/poseidon_hard.tpack"
  },
  {
    "unit": "03:mh_test9",
    "from": "anim/mon_bluedragon_cstand.anim",
    "to": "anim/monster/mon_bluedragon/mon_bluedragon_cstand.anim"
  },
  {
    "unit": "03:mh_test9",
    "from": "skel/mon_bluedragon.skel",
    "to": "skel/monster/mon_bluedragon.skel"
  }
].map(Object.freeze));
const repairs = new Map(EFFECT_PATH_REPAIRS.map(r => [r.unit+"|"+r.from,r.to]));
export function repairedEffectPath(unit, original) {
 return repairs.get(String(unit).toLowerCase()+"|"+original) || null;
}

// Exact scene/path corrections verified against existing Global assets and rigs.
// Engine compatibility repair, not a claim about native executable fallback behavior.
export const BONE_ANIMATION_PATH_REPAIRS = Object.freeze([
  {
    "effect": "100:1688",
    "from": "anim/effect/skill/trans03/eff_bwz_awk_03.skel",
    "to": "anim/effect/skill/trans03/eff_bwz_awk_03.anim"
  },
  {
    "effect": "100:3116",
    "from": "skel/effect/skill/venomlight/eff_venomlight_remote_01.skel",
    "to": "skel/effect/skill/vemonlight/eff_venomlight_remote_01.skel"
  },
  {
    "effect": "100:3116",
    "from": "anim/effect/skill/venomlight/eff_venomlight_remote_01.anim",
    "to": "anim/effect/skill/vemonlight/eff_venomlight_remote_01.anim"
  },
  {
    "effect": "100:3116",
    "from": "skel/effect/skill/venomlight/eff_venomlight_remote_02.skel",
    "to": "skel/effect/skill/vemonlight/eff_venomlight_remote_02.skel"
  },
  {
    "effect": "100:3116",
    "from": "anim/effect/skill/venomlight/eff_venomlight_remote_02.anim",
    "to": "anim/effect/skill/vemonlight/eff_venomlight_remote_02.anim"
  },
  {
    "effect": "100:30040",
    "from": "anim/eff_bar_summon03_breath_fire_rota_lv2.anim",
    "to": "anim/effect/skill/dragon_burst/eff_bar_summon03_breath_fire_rota_lv2.anim"
  },
  {
    "effect": "100:30041",
    "from": "anim/eff_bar_summon03_breath_fire_rota_lv2.anim",
    "to": "anim/effect/skill/dragon_burst/eff_bar_summon03_breath_fire_rota_lv2.anim"
  },
  {
    "effect": "100:30042",
    "from": "anim/eff_bar_summon03_breath_fire_rota_lv3.anim",
    "to": "anim/effect/skill/dragon_burst/eff_bar_summon03_breath_fire_rota_lv3.anim"
  }
].map(Object.freeze));
const boneRepairs = new Map(BONE_ANIMATION_PATH_REPAIRS.map(r => [r.effect+"|"+r.from,r.to]));
export function repairedBoneAnimationPath(effect, original, exists) {
 if (!original || exists(original)) return original;
 const replacement = boneRepairs.get(effect+"|"+original);
 return replacement && exists(replacement) ? replacement : original;
}

// Same basename and class; the native action table also references the destination.
// Original valid paths take precedence. No cross-class animation substitution.
export function repairedActionAnimationPath(actionFile, original, exists) {
 if (!original || exists(original)) return original;
 if (actionFile !== 'share/action/action/pc/sum.act.3.dat' || original !== 'anim/character/summoner/skill/sum_dul_stand_01.anim') return original;
 const replacement = 'anim/character/summoner/motion/dul/sum_dul_stand_01.anim';
 return exists(replacement) ? replacement : original;
}
