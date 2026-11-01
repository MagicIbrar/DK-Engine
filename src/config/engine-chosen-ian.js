// WEAPON APPEARANCE (npc 5507 Ian in Ardeca, job 110 CHANGESHAPE_JOB, game2/changeshapewnd/changeshapewnd.txt). Global parity:
// the materials (item type 0 code 64 / 65, value1 = weapon code, value2 = seconds, their own item_shape look), the DIL costs
// (share/system_variable.csv 21 / 22) and the window strings (stringtable_system 101:199-207) come from the Global data
// (src/systems/items/weapon-appearance.js). Only the gaps the data leaves open are listed here, each on its own tagged line.
export const ENGINE_CHOSEN_TAG = 'ENGINE-CHOSEN (not in Global data)';
export const IAN_CHOSEN = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): the target weapon and the material are registered from the bag (inventory) like every NPC item window; an equipped weapon is taken off first.
  source: 'bag only',
  // ENGINE-CHOSEN (not in Global data): a material on a weapon that already shows an appearance replaces it at once (the remaining time is lost), after the native caution box (title 101:206, text 101:207 with the weapon name).
  replace: 'replace after the 101:206 / 101:207 caution',
  // ENGINE-CHOSEN (not in Global data): there is no free removal; the "Appearance Reset" materials (item text "Item used to reset Weapon appearance", value2 1 s, the basic weapon shape) go through the same change as every material and expire after their own duration. 101:205 "Appearance Reset" has no recovered call site and is not bound.
  reset: 'reset materials only, same change',
  // ENGINE-CHOSEN (not in Global data): the material's own classMask / level are not checked; the rule applied is the native type match (value1 = weapon code).
  classCheck: 'none beyond the type match',
  // ENGINE-CHOSEN (not in Global data): native lines bound to the refusals: 1001:185 not a weapon / not a material, 40:57 material of another weapon type, 1001:118 item gone or changed, 1001:260 no material, 101:229 not enough DIL.
  refusals: '1001:185, 40:57, 1001:118, 1001:260, 101:229',
  // ENGINE-CHOSEN (not in Global data): every look builder hides an appearance at its exact end time; the host clears the stored fields durably at this cadence (ms) per online character (the reset item text promises "about 1 minute").
  sweepMs: 1000,
  // ENGINE-CHOSEN (not in Global data): the appearance belongs to the weapon instance: trade, storage, mail and every other move keep it with its absolute end time (the material itself is trade 0 and is consumed).
  travel: 'with the weapon instance, absolute end time',
  // ENGINE-CHOSEN (not in Global data): durable replay receipts kept per character (requestId + intent signature).
  receipts: 32,
  // ENGINE-CHOSEN (not in Global data): inside a DK Square / Draco battle the squad's projected weapon look (changeshape.csv Team 0 row, src/config/engine-chosen-dk-square.js teamLook) is drawn instead of a running Ian appearance; after the battle the Ian appearance returns with its own end time.
  battle: 'team look first while inside the battle',
});

export function ianChosenList() {
  return Object.entries(IAN_CHOSEN).map(([k, v]) => `${k}=${typeof v === 'number' ? v : JSON.stringify(v)}`);
}
