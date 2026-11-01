// "View Drop Item Name" (key map action 'dropnames', default Alt).
//
// Game files (read-only data tree): script/string/normal/stringtable_keymap.txt cate 2200 code 117 "View Drop Item Name" (old key
// version code 95 "See drop item name"); script/string/help/guide_info_system.txt (control guide, "display" keys): "Alt = view drop
// item names"; script/string/help/stringtable_helper.txt (the Pick / Discard Items help page): "View / Hide Name [Alt] key".
// The files give the key and what it shows (the names of the items lying on the ground); they do not say whether the key is
// held or toggled and not what the ground shows without it.
//   ENGINE-CHOSEN: the key is HELD (as before: docs/HUD_OPTIONS.md "drop names Alt (held)"); released = hidden again.
//   ENGINE-CHOSEN: without the key the ground labels stay as they were (DROP_NAMES_ONLY_ON_KEY = false). Set it to true to show
//   them only while the key is held (the reading of "View / Hide" as "hidden unless the key is down").
//
// What this module draws: while the key is held, every ground item gets a screen label with ITS OWN label text and colour (the
// text and the grade colour the item's ground sprite uses: drop.labelText / drop.labelColor of systems/items/ground.js; the
// colours are the authored item grades of ui/item-colors.js, dil gold). The sprite of that drop is hidden meanwhile so the name is
// not drawn twice. The first version of this key drew "Item" in white for every drop (it read a field that drops do not have).
import * as THREE from 'three';
import { ITEM_GRADE_COLORS } from '../../ui/item-colors.js';

export const DROP_NAMES_ONLY_ON_KEY = false;
const DIL_COLOR = '#ffcf40';        // the colour of the dil label sprite (systems/items/ground.js)
const MAX_LABELS = 120;
const _v = new THREE.Vector3();

/** The name a ground item shows: the sprite's own text, else the drop's label, else built from its entry. */
export function dropNameText(dr) {
  if (dr?.labelText) return String(dr.labelText);
  if (dr?.label) return String(dr.label);
  const e = dr?.entry;
  if (e?.kind === 'dil') return `${Math.round(Number(e.amount) || 0).toLocaleString('en-US')} Dil`;
  return String(e?.inst?.name || e?.name || 'Item');
}
/** Its colour: the sprite's own, else dil gold / the item grade colour. */
export function dropNameColor(dr) {
  if (dr?.labelColor) return String(dr.labelColor);
  const e = dr?.entry;
  if (e?.kind === 'dil') return DIL_COLOR;
  return ITEM_GRADE_COLORS[e?.inst?.grade || e?.grade] || ITEM_GRADE_COLORS.normal;
}

function layerOf(game, st) {
  if (st.layer) return st.layer;
  const d = document.createElement('div');
  d.style.cssText = 'position:fixed;left:0;top:0;width:100%;height:100%;pointer-events:none;z-index:29';
  (game.ui || document.body).appendChild(d);
  return (st.layer = d);
}

/** Every frame (hud-options update). opts.onlyOnKey overrides DROP_NAMES_ONLY_ON_KEY (tests). */
export function updateDropNames(game, ctx, opts = {}) {
  const only = opts.onlyOnKey ?? DROP_NAMES_ONLY_ON_KEY;
  const st = (ctx._dropNames ||= { layer: null, els: new Map() });
  const spec = ctx.keymap?.get('dropnames');
  const held = !!spec && !!ctx.keymap.down(spec) && !game.uiwin?.capturesInput;
  const drops = game.loot?.drops || [];
  // the ground sprites: shown unless the key's own labels replace them (held) or they are only wanted on the key
  const spritesOn = !held && !only;
  for (const d of drops) { const s = d.labelSprite; if (s && s.visible !== spritesOn) s.visible = spritesOn; }
  if (!held) { if (st.els.size) { st.layer?.replaceChildren(); st.els.clear(); } return; }
  const layer = layerOf(game, st), cam = game.camera;
  const live = new Set();
  let n = 0;
  for (const dr of drops) {
    if (n >= MAX_LABELS) break;
    const y = (Number.isFinite(dr.y) ? dr.y : (game.world?.heightAt?.(dr.x, dr.z) || 0)) + (dr.labelSprite?.position?.y ?? 0.9);
    _v.set(dr.x, y, -dr.z).project(cam);
    if (_v.z > 1 || _v.z < -1) continue;
    n++; live.add(dr);
    let el = st.els.get(dr);
    if (!el) {
      el = document.createElement('div');
      el.textContent = dropNameText(dr);
      el.style.cssText = 'position:absolute;transform:translate(-50%,-50%);font:bold 12px Tahoma,Verdana,sans-serif;text-shadow:1px 1px 0 #000,-1px -1px 0 #000,1px -1px 0 #000,-1px 1px 0 #000;white-space:nowrap;background:rgba(0,0,0,.45);padding:0 3px';
      el.style.color = dropNameColor(dr);
      layer.appendChild(el);
      st.els.set(dr, el);
    }
    el.style.left = `${((_v.x + 1) / 2 * innerWidth).toFixed(0)}px`;
    el.style.top = `${((1 - _v.y) / 2 * innerHeight).toFixed(0)}px`;
  }
  for (const [dr, el] of st.els) if (!live.has(dr)) { el.remove?.(); st.els.delete(dr); }
}

/** Remove the labels and give the sprites back (hud-options dispose). */
export function disposeDropNames(game, ctx) {
  const st = ctx?._dropNames;
  for (const d of game?.loot?.drops || []) if (d.labelSprite) d.labelSprite.visible = true;
  st?.layer?.remove?.();
  if (ctx) ctx._dropNames = null;
}
