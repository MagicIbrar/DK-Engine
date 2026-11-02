// E2 (4.3.2): every .pre include that Global's own data names but that has no file of that exact name in g2
// (property/preload, matched case-insensitively with '\' == '/', CP949-decoded). Unique missing include names
// (maplist Preloading census; nunvice_01..03 dropped from maplist — removed. hell\u2019s* added for g2 filename mojibake).
// over maplist.csv `Preloading` (tools/lane-perf/list-missing-preload.mjs before this table).
//
// kind 'GLOBAL-TYPO-ALIAS': the include is misspelled in Global's own map .pre, and exactly one g2 file is that entity.
//   Evidence: the target file's first line (its entity tag) and, where noted, that nothing else in g2 includes the
//   target (it only makes sense as the typo's destination). The engine loads the target so the monster is warm.
//   Whether Global's client also resolves these (its loader could fail the open and skip) is UNKNOWN until the
//   Procmon trace (E3) shows the open result for the misspelled name. Set globalThis.__dkPreloadNoAliases = true to
//   behave as a strict exact-name loader (the aliases are then reported as missing, never substituted).
// kind 'ABSENT': no g2 .pre file is that entity (searched every name in property/preload and the entity tag on line 1
//   of all 1140 .pre files). Nothing is substituted; the map's own spawner prewarm still loads those monsters.
export const PRELOAD_INCLUDE_ALIASES = Object.freeze({
  'monster\\aquira_warloard.pre':         { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\aquira_warlord.pre',          evidence: 'target line 1 <Aquira_Warlord>; also included correctly by plane_of_pilgrimage.pre, over_dimension.pre', from: ['mordo.pre'] },
  'monster\\fiend_raspution_sorcerer.pre': { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\fiend_rasputin_sorcerer.pre', evidence: 'target line 1 <fiend_rasputin_sorcerer>; target included by nothing else', from: ['infinite hunt_a.pre', 'infinite hunt_b.pre'] },
  'monster\\fiend_skeleton-bishop.pre':    { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\fiend_skeleton_bishop.pre',    evidence: 'target line 1 <fiend_skeleton-bishop> (exact entity name); target included by nothing else', from: ['infinite hunt_a.pre', 'infinite hunt_b.pre'] },
  'monster\\horror_raspiton_hunter.pre':   { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\horror_rasputin_hunter.pre',   evidence: 'target line 1 <horror_rasputin_hunter>; target included by nothing else', from: ['infinite hunt_a.pre', 'infinite hunt_b.pre'] },
  'monster\\horror_zielogan archer.pre':   { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\horror_zielogan_archer.pre',   evidence: 'target line 1 <horror_zielogan archer> (exact entity name, space); target included by nothing else', from: ['infinite hunt_a.pre', 'infinite hunt_b.pre'] },
  'monster\\ice_drako.pre':                { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\ice_draco.pre',                evidence: 'target line 1 <ice_drako> (exact entity name), lists Monster\\ice_drako.tpack/.mesh; target included by nothing else', from: ['fragment_of_karon.pre'] },
  'monster\\lupainloard.pre':              { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\lupainlord.pre',               evidence: 'target line 1 <lupainlord>; target included by nothing else', from: ['tower_indun_04.pre'] },
  'monster\\venomous_insect.pre':          { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\venomouse_insect.pre',         evidence: 'target line 1 <venomous_insect> (exact entity name); target included by nothing else', from: ['tower_indun_02.pre'] },
  'brick\\dragon_altar.pre':               { kind: 'ABSENT', evidence: 'g2 property/preload has no brick\\ folder and no *dragon_altar* .pre (assets exist: texturepack/object/building_extra/dv_dragon_altar_*.tpack, skel/brick/dv_dragon_altar_02.skel)', from: ['dravis_domain_field.pre'] },
  'monster\\scutum_archer.pre':            { kind: 'ABSENT', evidence: 'no *scutum* .pre and no <scutum...> entity tag in g2 (share/action/monster/scutum_archer.act.*.csv exist)', from: ['transportship_c.pre'] },
  'monster\\scutum_worrior.pre':           { kind: 'ABSENT', evidence: 'no *scutum* .pre and no <scutum...> entity tag in g2 (share/action/monster/scutum_warrior.act.*.csv exist)', from: ['transportship_c.pre'] },
  // g2 pack/extract mojibake: include text (euc-kr) has U+2019; on-disk .pre filename is UTF-8(U+2019) mis-decoded as CP949.
  'monster\\hell’s spider.pre': { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\hell┬í┬»s spider.pre', evidence: 'abyss_of_crespo*.pre include U+2019; disk name is UTF-8-of-U+2019 misread as CP949; target lists hellspider assets', from: ['abyss_of_crespo1.pre','abyss_of_crespo2.pre','abyss_of_crespo3.pre','abyss_of_crespo4.pre'] },
  'monster\\hell’s ghost night.pre': { kind: 'GLOBAL-TYPO-ALIAS', to: 'Monster\\hell┬í┬»s ghost night.pre', evidence: 'abyss_of_crespo*.pre include U+2019; disk name is UTF-8-of-U+2019 misread as CP949; target lists Hell_GhostNight assets', from: ['abyss_of_crespo1.pre','abyss_of_crespo2.pre','abyss_of_crespo3.pre','abyss_of_crespo4.pre'] },
});
/** Lower-case, backslash key of an include as written in a .pre / maplist. */
export const preloadKey = rel => String(rel || '').trim().replace(/\//g, '\\').toLowerCase();
