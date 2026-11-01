// CHAT-LINKS rules shared by the host (server/world/social.mjs, party.mjs, guilds.mjs) and the client (chat-links.js).
// Original data: game2/itemlink/ui_tooltip.txt (ItemLinktooltipwnd: pan_tooltip etc_01#66 frame, btn_exit etc_01#315-317),
// game2/itemlinkpreview/ui_itemlinkpreview.txt (lbl_title 100:154 "Preview", lbl_item_name, pan_bg 360x360 model slot
// common#65500, btn_my_chara 2000:83, btn_link_item / btn_my_item / btn_ok 2000:15), stringtable_button 2000:85-90
// (Link Pet, My Pet, Link Mount, My Mount, Link Item, My Character), key map 908 "Show ItemLink".
// Engine choices (wire token, limits, gestures): chat-links-config.js, every value ENGINE-CHOSEN (not in Global data).
import { CHAT_LINK_CONFIG } from './chat-links-config.js';

export { CHAT_LINK_CONFIG };
export const CHAT_LINK_SCRIPTS = Object.freeze({ tooltip: 'game2/itemlink/ui_tooltip.txt', preview: 'game2/itemlinkpreview/ui_itemlinkpreview.txt' });
export const CHAT_LINK_STRINGS = Object.freeze({
  title: [100, 154], ok: [2000, 15], myChara: [2000, 83],
  linkPet: [2000, 85], myPet: [2000, 86], linkMount: [2000, 87], myMount: [2000, 88], linkItem: [2000, 89], myCharacter: [2000, 90],
});
/** Preview window captions per kind: [btn_link_item, btn_my_item]; btn_my_chara (2000:83) shows only for wearable items. */
export const PREVIEW_BUTTONS = Object.freeze({
  item: Object.freeze({ link: 'linkItem', mine: null, chara: true }),
  pet: Object.freeze({ link: 'linkPet', mine: 'myPet', chara: false }),
  mount: Object.freeze({ link: 'linkMount', mine: 'myMount', chara: false }),
});
export const KEYMAP_SHOW_ITEMLINK = 908;
const TOKEN = CHAT_LINK_CONFIG.tokenName;
export const LINK_TOKEN_RE = new RegExp(`\\{${TOKEN}:([A-Za-z0-9_-]{1,64})\\}`, 'g');
export const linkToken = (uid) => `{${TOKEN}:${uid}}`;
/** "[Name]" as the chat shows a link (brackets / braces inside a name are dropped so a label never nests). */
export const linkLabel = (name) => `[${String(name ?? '').replace(/[[\]{}]/g, '').trim()}]`;

const DROP = new Set(['uid', 'page', 'x', 'y', 'slot', 'preset', 'locked', 'reserved', 'pending']);
/** A copy of one item for the link: everything the tooltip reads, never its place or uid. */
export function linkSnapshot(inst, max = CHAT_LINK_CONFIG.maxSnapshotBytes) {
  const index = Number(inst?.itemIndex);
  if (!inst || !Number.isInteger(index) || index <= 0) return null;
  const out = {};
  for (const [k, v] of Object.entries(inst)) if (!DROP.has(k) && v !== undefined && typeof v !== 'function') out[k] = v;
  out.itemIndex = index;
  let json = '';
  try { json = JSON.stringify(out); } catch { json = ''; }
  const small = { itemIndex: index, count: Math.max(1, Number(inst.count) || 1), grade: typeof inst.grade === 'string' ? inst.grade : 'normal' };
  if (!json || json.length > max) return small;
  return JSON.parse(json);
}
/** Every item a profile / save owns that a link may point at (CHAT_LINK_CONFIG.linkSources). */
export function linkableItems(profile) {
  const out = [];
  const arr = (v) => (Array.isArray(v) ? v : Array.isArray(v?.list) ? v.list : []);
  for (const src of CHAT_LINK_CONFIG.linkSources) {
    if (src === 'equip') out.push(...Object.values(profile?.equip?.items || {}));
    else out.push(...arr(profile?.[src]));
  }
  return out.filter(e => e && typeof e.uid === 'string');
}
/** Swap the {item:uid} tokens of a message for "[Name]" + a link copy (unknown / not owned / over the limit: dropped). */
export function resolveChatLinks(text, find, nameOf, now = Date.now()) {
  const links = [];
  let touched = false;
  const out = String(text ?? '').replace(LINK_TOKEN_RE, (m, uid) => {
    touched = true;
    if (links.length >= CHAT_LINK_CONFIG.maxLinksPerMessage) return '';
    const inst = find(uid);
    if (!inst || (inst.expiresAt && inst.expiresAt <= now)) return '';
    const item = linkSnapshot(inst);
    const name = item ? String(nameOf(item.itemIndex) || '').trim() : '';
    if (!name) return '';
    links.push({ name: linkLabel(name).slice(1, -1), item });
    return linkLabel(name);
  });
  return { text: touched ? out.replace(/[ \t]{2,}/g, ' ').trim() : out, links };
}
/** Host side: resolve against the speaker's own profile (server-authoritative; the client only names a uid). */
export function hostChatLinks(profile, db, text, now = Date.now()) {
  if (!LINK_TOKEN_RE.test(String(text ?? ''))) { LINK_TOKEN_RE.lastIndex = 0; return { text, links: [] }; }
  LINK_TOKEN_RE.lastIndex = 0;
  const own = new Map(linkableItems(profile).map(e => [e.uid, e]));
  return resolveChatLinks(text, uid => own.get(uid), i => db?.def?.(i)?.name || '', now);
}
/** Client side: keep only well-formed links of a host record. */
export function cleanLinks(links) {
  if (!Array.isArray(links)) return [];
  return links.slice(0, CHAT_LINK_CONFIG.maxLinksPerMessage).filter(l => l && typeof l.name === 'string' && l.name.length <= 80
    && l.item && Number.isInteger(Number(l.item.itemIndex)) && Number(l.item.itemIndex) > 0);
}
/** Split a chat line into plain text and link runs: each link takes the first "[name]" after the previous one, searched
 *  after the speaker separator " : " so a channel label such as "[Shout]" is never taken. */
export function linkSegments(line, links) {
  const text = String(line ?? ''), sep = text.indexOf(' : ');
  let at = sep >= 0 ? sep + 3 : 0;
  const out = [];
  let last = 0;
  (links || []).forEach((l, i) => {
    const label = linkLabel(l.name), k = text.indexOf(label, at);
    if (k < 0) return;
    if (k > last) out.push({ text: text.slice(last, k) });
    out.push({ text: label, link: i });
    last = at = k + label.length;
  });
  if (last < text.length) out.push({ text: text.slice(last) });
  return out;
}
/** Which preview the item gets: a pet, a mount, or an item (shown alone or worn by My Character). */
export function previewKind(itemIndex, mountsData) {
  if (mountsData?.isPet?.(itemIndex)) return 'pet';
  if (mountsData?.isVehicle?.(itemIndex)) return 'mount';
  return 'item';
}