// Premium-service rules shared by the client (shops/premium.js) and the authoritative server (server/world/premium.mjs).
// Source tables: share/item/premiereitem.csv (dshop.json premium.items), share/premiere/teleport.csv + respon.csv
// (premium.teleport / premium.respon), share/item/cashshop_almightypremium.csv (premium.almighty).
// Row layout: [Time, ExpAdd, Rate, PartyBonusRate, Teleport, Respon, StatusIndex, StoreIndex, Post, Brokerage, PartyWarp,
//              NpcWarp, ItemUpgradeRate, RuneIndex]; ExpAdd is the service group (1 = Growth Blessing, 2 = Holy Water of
// the Almighty). script/string/system/stringtable_system.txt code 109: "Growth Blessing and Holy Water of Almighty
// cannot be used together." -> only one group can be active at a time; items of the active group add their time.
// Party Warp (premiereitem.csv PartyWarp = 1 on the Holy Water of Almighty rows; item text 701 "Party warp"). Original hook: the
// party_renew window's per-member btn_move_<n> (ui_partyinfo_renew.txt, text 2000:77). Original texts: stringtable_system cate 101.
import { TRAVEL_FREEZE_MS } from '../../config/owner-travel-freeze.js';
export const PARTY_WARP_TEXT = Object.freeze({
  limited: '[TARGET_NAME] is in the map where Party Warp is limited.',                 // 101:160
  done: 'You have teleported to the map where [TARGET_NAME] is.',                      // 101:161
  notInParty: 'You can use it only when you are in the party.',                        // 101:163
  expedition: 'You cannot use Party Warp function when you are in the Expedition.',    // 101:164
  noLocation: "You cannot find the party member's location.",                          // 101:166
  currentMap: 'You cannot use this function in current map.',                          // 101:167
  cannotTarget: "You cannot teleport to [TARGET_NAME]'s location.",                    // 101:168
  level: 'You are not in the right level to teleport.',                                // 101:169
});
export const partyWarpText = (key, name = '') => PARTY_WARP_TEXT[key].replace('[TARGET_NAME]', name);
// NPC Warp = teleport to a map NPC (premiereitem.csv NpcWarp = 1 on the Holy Water of Almighty rows; item text 701 "NPC warp";
// premium status line 101:187 "Able to use NPC Warp"; premium button text "Open: NPC Warp Function"). Without the service the
// map list's Move walks instead (hud-options/minimap.js walkMapNpc). Original texts: stringtable_system cate 101.
export const NPC_WARP_TEXT = Object.freeze({
  done: "You have suceeded to teleport [NPC_NAME]'s location.",                       // 101:171 (original spelling)
  expedition: "You can't move to NPC while you are participating in an expedition.",  // 101:172
  cannot: 'You cannot transport to the NPC.',                                          // 101:173
});
export const npcWarpText = (key, name = '') => NPC_WARP_TEXT[key].replace('[NPC_NAME]', name);
export const PREMIUM_FIELDS = ['time', 'expAdd', 'rate', 'partyBonusRate', 'teleport', 'respon', 'statusIndex', 'storeIndex', 'post', 'brokerage', 'partyWarp', 'npcWarp', 'itemUpgradeRate', 'runeIndex'];
// stringtable_system.txt (system cate) original texts.
export const PREMIUM_TEXT = {
  together: 'Growth Blessing and Holy Water of Almighty cannot be used together.',           // code 109
  changeFail: 'CHANGE_FAIL: Failed to change Return Point',                                   // code 100
  riding: 'You cannot use teleportation while riding a creature.',                            // code 102
  dungeon: 'This cannot be used in dungeons.',                                                // code 104
  noService: 'Premium service that is enabled through\nGrowth Blessing and Holy Water of Almighty.', // tooltip 50
};
// The premium window (game2/ui_warpteleportwnd.txt) only carries a progress bar + Cancel, no duration. Until 2.2.1 it borrowed the
// Smart Warp's 3 s; Global's 10 s frozen bar applies to the big map's teleports (src/config/owner-travel-freeze.js).
export const PREMIUM_WARP_MS = TRAVEL_FREEZE_MS;

export const almightyOf = (dshop, idx) => (dshop?.premium?.almighty || []).find(a => a.item === Number(idx)) || null;
export const premiumRow = (dshop, idx) => dshop?.premium?.items?.[Number(idx)] || (almightyOf(dshop, idx) ? dshop?.premium?.items?.[0] : null) || null;
export function premiumFields(dshop, idx) {
  const row = premiumRow(dshop, idx);
  return row ? Object.fromEntries(PREMIUM_FIELDS.map((k, i) => [k, Number(row[i]) || 0])) : null;
}
export const isPremiumItem = (dshop, idx) => Number(idx) > 0 && !!premiumRow(dshop, idx);
export const activePremiums = (state, now) => Object.values(state || {}).filter(p => p && p.until > now);
export const premiumAny = (state, now, key) => activePremiums(state, now).some(p => p.fields?.[key] > 0);
export const holyWaterFields = fields => fields?.storeIndex>0&&fields?.post>0&&fields?.brokerage>0;
// Global formula.ini byAddExpPlus=10 (and older server-ref period.csv IPAMON Exp AddRate=10).
// Native cash strings code83: Premium + regular adds 10% EXP; shared effects do not multiply.
export const BY_ADD_EXP_PLUS = 10;
export const premiumSum = (state, now, key) => {
  const entries=activePremiums(state,now),holy=entries.filter(p=>holyWaterFields(p.fields));
  if(holy.some(p=>p.accountWide)&&holy.some(p=>!p.accountWide)){
    const value=Math.max(...holy.map(p=>Number(p.fields?.[key])||0))+(key==='rate'?BY_ADD_EXP_PLUS:0);
    return value+entries.filter(p=>!holyWaterFields(p.fields)).reduce((sum,p)=>sum+(p.fields?.[key]||0),0);
  }
  return entries.reduce((s,p)=>s+(p.fields?.[key]||0),0);
};
// Deka Pass premium track. stringtable_dekapass 3200:2: "By using the Premium Holy Water of Almighty, you can obtain a Premium
// Pass item." No item is named "Premium Pass" (items.json, 95,000 rows) and premiereitem.csv has no pass column, so the track
// opens while a service of that name runs: 1171289 "Premium Holy Water of the Almighty" (cashshop_almightypremium.csv) and the
// premiereitem.csv rows 1194638 (15 days), 1762418 / 2313369 (30 days). The plain Holy Water of Almighty (1191676) does not.
export const PREMIUM_PASS_NAME = /^Premium Holy Water of (the )?Almighty/i;
export const premiumPassActive = (services, now, nameOf) => Object.values(services || {}).some(p => p && Number(p.until) > now && PREMIUM_PASS_NAME.test(String(nameOf(p.item) || '')));

/** Why this premium item cannot start now ('together' | 'renew') or null when it can. */
export function premiumBlock(dshop, state, idx, now) {
  const f = premiumFields(dshop, idx);
  if (!f) return 'unknown';
  const group = String(f.expAdd || 0), alm = almightyOf(dshop, idx);
  // a service of the other group is running: the two kinds cannot be used together
  const accountWide=!!alm||PREMIUM_PASS_NAME.test(String(dshop?.items?.[idx]?.name||''));
  if (activePremiums(state, now).some(p => String(p.fields?.expAdd || 0) !== group&&!(holyWaterFields(p.fields)&&holyWaterFields(f)&&(accountWide||p.accountWide)))) return 'together';
  const cur = accountWide?activePremiums(state,now).find(p=>p.accountWide||almightyOf(dshop,p.item)||PREMIUM_PASS_NAME.test(String(dshop?.items?.[p.item]?.name||''))):state?.[activePremiums(state,now).some(p=>p.accountWide)&&holyWaterFields(f)?`regular:${group}`:group];
  if (cur && cur.until > now && alm && cur.item === Number(idx) && cur.until - now > alm.updatableDays * 86400000) return 'renew';
  return null;
}

/** New group record after using `idx`: a running service of the same group is extended by the item's time (the newest
 *  item's service fields apply from then on). Pure: returns {group, entry}. */
export function premiumActivation(dshop, state, idx, now) {
  const f = premiumFields(dshop, idx);
  idx = Number(idx);
  const alm = almightyOf(dshop, idx),accountWide=!!alm||PREMIUM_PASS_NAME.test(String(dshop?.items?.[idx]?.name||''));
  const rawGroup = String(f.expAdd || 0),group=!accountWide&&holyWaterFields(f)&&activePremiums(state,now).some(p=>p.accountWide)?`regular:${rawGroup}`:rawGroup;
  const old=state?.[group],cur=old&&!!old.accountWide===accountWide?old:null;
  const base = cur && cur.until > now ? cur.until : now;
  const dur = (f.time > 0 ? f.time : (alm?.serviceDays || 30) * 86400) * 1000;
  return { group, entry: { item: idx, start: cur && cur.until > now ? cur.start : now, until: base + dur, fields: f,...(accountWide?{accountWide:true}:{}) } };
}

const inRange = (t, level) => level >= (t.minLv || 0) && level <= (t.maxLv || 999);
export const premiumTeleportList = (dshop, level) => (dshop?.premium?.teleport || []).filter(t => inRange(t, level));
export const premiumResponList = (dshop, level) => (dshop?.premium?.respon || []).filter(t => inRange(t, level)).sort((a, b) => (a.order || 0) - (b.order || 0));
