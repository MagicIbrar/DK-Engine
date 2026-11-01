// Item tooltips as the original client draws them (game2/itemlink/ui_tooltip.txt: etc_01#66 frame, a font-4 title,
// the etc_01#67 title rule, a font-2 text box with 16 px lines and 10/6 margins), filled from items.json
// tooltip.layout[kind].groups (script/itemdesc/itemdesc.csv) and tooltip.strings (stringtable_itemdesc):
//   1 header (grade, bound, remaining time, rank, type, count, required level)   2 recovery / buff
//   3 requirements (red when unmet)   4 attack / defence / speed / block   5 fixed + additional options
//   6 reinforcement   7 rank (random) options   8 sockets   9 brand options   10 item list (boxes)
//   11 description   12 price   + set effect (cate 1000), crest (1300), dual weapon effect (401)
import { atlas } from '../../ui/atlas.js';
import { markupRuns } from '../../ui/uiwin/strings.js';
import { applyFont } from '../../ui/uiwin/fonts.js';
import { instOptions, activeSets } from './stats.js';
import { S } from './equip.js';
import {comparisonTargets,comparisonDeltas,comparisonSlotLabel,optionTemplate} from './compare.js';
import { ITEM_GRADE_COLORS, dilMarkup, optionValueColor } from '../../ui/item-colors.js';
import {optionDisplayValue} from './native-option-values.js';
import {itemOptionRanges} from './tooltip-ranges.js';

export const GRADE_COLOR = ITEM_GRADE_COLORS;
const GRADE_LINE = { magic: 17, noble: 18, divine: 19 };
const VALUE_COL = 118;   // <set=VALUE2> tab stop (px)

function el(tag, cls, parent) { const e = document.createElement(tag); if (cls) e.className = cls; if (parent) parent.appendChild(e); return e; }
function spriteDiv(group, index, w, h, parent) {
  const d = el('div', null, parent);
  d.style.cssText = `width:${w}px;height:${h}px;margin:3px 0;background-size:100% 100%;`;
  const s = atlas.spriteNow?.(group, index);
  if (s) d.style.backgroundImage = `url("${s.url}")`;
  else atlas.sprite?.(group, index).then(sp => { if (sp) d.style.backgroundImage = `url("${sp.url}")`; });
  return d;
}

/** Fill a client line: placeholders by name, then split at <set=...> into label / value. */
function fill(text, vals = {}) {
  return String(text ?? '').replace(/<([A-Z_0-9]+)>/g, (m, k) => (k in vals ? String(vals[k]) : m)).replace(/\\\\/g, '');
}
function runsInto(parent, text, override = null) {
  for (const r of markupRuns(text)) {
    if (r.br) { el('br', null, parent); continue; }
    const s = el('span', null, parent); s.textContent = r.text; if (override || r.color) s.style.color = override || r.color;
  }
}
/** One tooltip line; `<set=X>` splits it into a label and a value column. */
function line(box, text, { color = null, center = false } = {}) {
  const rows = String(text).split('\n');
  for (const row of rows) {
    const d = el('div', 'itt-line', box);
    if (center || /<center>/i.test(row)) d.style.textAlign = 'center';
    if (color) d.style.color = color;
    const segs = row.replace(/<center>/ig, '').replace(/<font=\d+>|<\/font>/ig, '').split(/<set=[^>]*>/i);
    if (segs.length > 1) {
      const a = el('span', 'itt-lab', d); a.style.display = 'inline-block'; a.style.minWidth = `${VALUE_COL}px`; runsInto(a, segs[0], color);
      const b = el('span', 'itt-val', d); runsInto(b, segs.slice(1).join(''), color);
    } else runsInto(d, segs[0], color);
  }
}

const fmt = (n) => Number(n || 0).toLocaleString('en-US');

/**
 * Tooltip Element for an instance (or an item index). ctx: {sys, where: 'bag'|'equip'|'shop'|'storage', price, compare,
 * comparing (inside buildCompare: no hints), optionRanges (Shift range view; default: the tooltip manager's Shift state)}.
 */
export function buildTooltip(sys, instOrIndex, ctx = {}) {
  const db = sys.db;
  const inst = typeof instOrIndex === 'object' ? instOrIndex : { itemIndex: Number(instOrIndex), count: 1, grade: 'normal' };
  const def = db.def(inst.itemIndex);
  if (!def) return null;
  const grade = def.slot === 'vehicle' || db.stackSize(def)>1 ? 'normal' : inst.grade;
  const S_ = (c, k) => db.str(c, k);
  const layout = db.tooltipLayout(def) || { font: 4, color: 'ffffff', groups: [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0] };
  const G = (n) => !!layout.groups?.[n - 1];
  const player = sys.game.player;
  const stats = player?.stats || {};
  const lv = Number(sys.game.save?.level) || 1;
  const RED = '#FF0000';

  const root = el('div', 'itt');
  // LANE16: wrap inside the (engine-chosen) 320 px box like buildCompare; nowrap let authored lines escape the frame.
  root.style.cssText = 'min-width:170px;max-width:320px;padding:6px 10px;line-height:16px;white-space:normal;overflow-wrap:anywhere;';
  applyFont(root, 2, 16);
  // title
  const title = el('div', 'itt-title', root);
  applyFont(title, layout.font || 4);
  title.style.textAlign = 'center';
  title.style.color = GRADE_COLOR[grade] || `#${String(layout.color || 'ffffff').slice(-6)}`;
  title.textContent = def.name || `Item ${def.index}`;
  spriteDiv('etc_01', 67, '100%', 2, root).style.width = '100%';
  const body = el('div', 'itt-body', root);
  const div = () => { const d = spriteDiv('etc_01', 305, '100%', 8, body); d.style.width = '100%'; d.style.opacity = '0.9'; };

  // 1 header
  if (G(1)) {
    if (GRADE_LINE[grade]) line(body, sys.str(260, GRADE_LINE[grade]) || '', { center: true, color: GRADE_COLOR[grade] });
    if (Number(def.rank) === 2) line(body, S_(102, 0));
    if (inst.bound || Number(def.trade) === 0) line(body, S_(1, 1));
    if (inst.expiresAt) {
      const left = Math.max(0, inst.expiresAt - Date.now()) / 1000;
      const d = Math.floor(left / 86400), h = Math.floor(left % 86400 / 3600), m = Math.floor(left % 3600 / 60);
      line(body, `${S_(1, 2)}${d ? `${d}d ` : ''}${h}h ${m}m</color>`);
    }
    // itemdesc 1:11: a timed weapon appearance (Ian material) shows the material's name and its remaining time.
    const look = inst.appearance && inst.appearanceExpiresAt > Date.now() ? db.def(inst.appearance) : null;
    if (look) {
      const left = Math.max(0, inst.appearanceExpiresAt - Date.now()) / 1000;
      const d = Math.floor(left / 86400), h = Math.floor(left % 86400 / 3600), m = Math.floor(left % 3600 / 60);
      const text = fill(S_(1, 11), { ITEM_SHAPE: look.name || `Item ${look.index}` }), at = text.lastIndexOf('</color>');
      const time = `${d ? `${d}d ` : ''}${h}h ${m}m`;
      line(body, at >= 0 ? text.slice(0, at) + time + text.slice(at) : text + time);
    }
    if (def.rank != null && db.rankName(def)) line(body, fill(S_(1, 3), { RANK: db.rankName(def) }));
    if (db.kindName(def)) line(body, fill(S_(1, 4), { CODE: db.kindName(def) }));
    const stack = db.stackSize(def);
    if (stack > 1) line(body, fill(S_(1, 5), { STACK: fmt(inst.count || 1), MAXSTACK: fmt(stack) }));
    if (def.reqLv > 0) {
      let t = fill(S_(1, 6), { REQLLV: def.reqLv });
      if (def.maxLv > 0) t += fill(S_(1, 7), { REQHLV: def.maxLv });
      line(body, t, { color: lv < def.reqLv || (def.maxLv > 0 && lv > def.maxLv) ? RED : null });
    }
    div();
  }
  // 2 recovery / buff
  if (G(2) && def.use) {
    const u = def.use;
    if (u.hp && u.mp) line(body, fill(S_(2, 4), { VALUE: fmt(u.hp), ADDVALUE: fmt(u.mp) }));
    else if (u.hp) line(body, fill(S_(2, 1), { VALUE: fmt(u.hp) }));
    else if (u.mp) line(body, fill(S_(2, 2), { VALUE: fmt(u.mp) }));
    if (u.hpPct && u.mpPct) line(body, fill(S_(2, 4), { VALUE: `${u.hpPct}%`, ADDVALUE: `${u.mpPct}%` }));
    else if (u.hpPct) line(body, fill(S_(2, 1), { VALUE: `${u.hpPct}%` }));
    else if (u.mpPct) line(body, fill(S_(2, 2), { VALUE: `${u.mpPct}%` }));
    if (u.shield) line(body, fill(S_(2, 3), { VALUE: fmt(u.shield) }));
    if (u.shieldPct) line(body, fill(S_(2, 3), { VALUE: `${u.shieldPct}%` }));
    if (u.itemStatus != null) {
      const st = sys.db.T?.itemStatus?.[u.itemStatus];
      line(body, S_(2, 5));
      if (st?.description) line(body, `<color=FFE08C>${st.description}</color>`);
    }
  }
  // 3 requirements
  if (G(3) || def.slot) {
    const mask = Number(def.classMask);
    if (def.slot && mask && mask !== 32767 && (mask & 32767) !== 32767) {
      const names = (db.enums.classes || []).filter(c => (mask >>> c.index) & 1).map(c => c.name);
      const mine = (mask >>> (Number(sys.game.save?.classIndex) || 0)) & 1;
      line(body, `${S_(3, 1).replace('</color>', '')}${names.join(', ')}</color>`, { color: mine ? null : RED });
    }
    const req = [[4, def.reqStr, stats.str], [5, def.reqDex, stats.dex], [6, def.reqSpr, stats.spr]];
    for (const [code, need, have] of req) if (need > 0) line(body, fill(S_(3, code), { VALUE: need }), { color: (have ?? 0) < need ? RED : null });
  }
  // 4 attack / defence
  if (G(4) || def.slot) {
    let any = false;
    const dk = (Number(def.classMask) >>> 7 & 1) && Number(def.classMask) === 128 ? S_(4, 4) : '';
    if (def.melee?.[1] > 0) { line(body, fill(S_(4, 1), { MIN: fmt(def.melee[0]), MAX: fmt(def.melee[1]) }) + dk); any = true; }
    if (def.ranged?.[1] > 0) { line(body, fill(S_(4, 2), { MIN: fmt(def.ranged[0]), MAX: fmt(def.ranged[1]) })); any = true; }
    if (def.magic?.[1] > 0) { line(body, fill(S_(4, 3), { MIN: fmt(def.magic[0]), MAX: fmt(def.magic[1]) })); any = true; }
    if (def.def?.[1] > 0 || def.def?.[0] > 0) { line(body, fill(S_(4, 5), { VALUE: fmt(def.def[1] || def.def[0]) })); any = true; }
    if (Number(def.type) === 4 && def.speed) { line(body, fill(S_(4, 6), { VALUE: def.speed })); any = true; }
    if (def.block > 0) { line(body, fill(S_(4, 7), { VALUE: def.block })); any = true; }
    const rule = db.weaponRule(def);
    if (rule?.dual && sys.equip.canStyle(10)) {
      const k = { 1: 1, 6: 2, 8: 3 }[def.code];
      if (k) { line(body, S_(401, k)); any = true; }
    }
    if (any) div();
  }
  // Original 910:17 Shift view: proven [min, max] per saved pair (tooltip-ranges.js); ctx.optionRanges, else the
  // tooltip manager's guarded Shift state (src/ui/uiwin/tooltip.js).
  const ranges=itemOptionRanges(db,inst),showRanges=ctx.optionRanges??!!sys.game?.uiwin?.tooltips?._shiftDown;
  const optLine = (type, v, color = null, rankColor = null, range = null) => {
    const ot = db.optionType(type);
    // Same native value column and suffix; the range separator follows original 4:1 <MIN> ~ <MAX> typography.
    const shown=range?range.map(bound=>fmt(optionDisplayValue(type,bound,db))).join(' ~ '):fmt(optionDisplayValue(type,v,db));
    const value = `<color=${optionValueColor(v).slice(1)}>${shown}</color>`;
    // 502, else the original Item Branding (902) line of the same option name, else the prepared text (compare.js)
    const template = optionTemplate(db, type) || ot?.text;
    let text = template ? template.replace(/<VALUE>/g, value) : `Option ${type}: ${value}`;
    // Rarity colors the bonus label; signed canonical values retain green/red.
    if (rankColor) text = `<color=${rankColor.slice(1)}>${text}</color>`;
    const [a, ...b] = text.split(':');
    line(body, b.length && !/<set=/i.test(text) ? `${a}:<set=VALUE2>${b.join(':').trim()}` : text, { color });
  };
  // 5 fixed options
  if ((G(5) || def.slot) && def.options?.length) {
    for (const [t, v] of def.options) optLine(t, v);
    div();
  }
  // 6 reinforcement options: the item tables' Expansion Option columns are the stats a +N row adds (they follow the
  // Game Guide upgrade chart, e.g. Thunder Armor: none to +5, +6 two main stats, +9 physical resistance). itemdesc.csv
  // Group_6 + stringtable_itemdesc 601:1 " Reinforcement Option"; values keep the signed option colours.
  if ((G(6) || G(5) || def.slot) && def.exOptions?.length) {
    line(body, S_(601, 1));
    for (const [t, v] of def.exOptions) optLine(t, v);
    div();
  }
  // 7 rank options
  if (inst.rnd?.length) { const section=showRanges&&ranges.rank;line(body, S_(701, section?2:1));inst.rnd.forEach(([t,v],i)=>optLine(t,v,null,GRADE_COLOR[grade],section?.[i]));div(); }
  // 8 sockets
  if (inst.sockets?.length) {
    const used = inst.sockets.filter(Boolean).length;
    line(body, S_(801, 1).replace('%d', used).replace('%d', inst.sockets.length));
    // Native Socket#0 is empty; each inserted stone selects its original use.socketIcon.
    // Capacity and option lines cannot stand in for the actual stored stone IDs.
    const socketRow = el('div', 'itt-sockets', body);
    socketRow.style.cssText = 'display:flex;gap:4px;margin:3px 0;';
    for (const stoneIndex of inst.sockets.slice(0, 4)) {
      const stone = stoneIndex ? db.def(stoneIndex) : null;
      const icon = stoneIndex ? stone?.use?.socketIcon : 0;
      const art = db.enums.socketIcons?.[icon];
      const cell = art && !art.outside ? spriteDiv('Socket', icon, 32, 32, socketRow) : el('div', null, socketRow);
      cell.style.width = '32px'; cell.style.height = '32px';
      cell.title = stoneIndex ? (stone?.name || String(stoneIndex)) : '- Empty -';
      cell.setAttribute('aria-label', cell.title);
      if (!art || art.outside) cell.textContent = '?';
    }
    for (const s of inst.sockets) {
      if (!s) { line(body, '<color=808080>- Empty -</color>'); continue; }
      const sd = db.def(s);
      line(body, `<color=00FF00>${sd?.name || s}</color>`);
      for (const [t, v] of sd?.options || []) optLine(t, v);
    }
    div();
  }
  // 9 brand options
  if (inst.brand?.length) { const section=showRanges&&ranges.brand;line(body, S_(901, section?2:1));inst.brand.forEach(([t,v],i)=>optLine(t,v,null,null,section?.[i]));div(); }
  // crest
  if (inst.crest?.options?.length) { line(body, S_(1300, 1)); for (const [t, v] of inst.crest.options) optLine(t, v); div(); }
  // set effect
  if (def.union && db.equipment.unionSets?.[def.union]) {
    const set = db.equipment.unionSets[def.union];
    const worn = sys.equip.worn();
    const active = activeSets(db, worn).find(s => s.set === def.union);
    const n = active?.count || 0;
    line(body, `<color=CCA63D>${(S_(1000, 1) || 'Set Effect (%d)').replace('%d', n)}</color>`);
    line(body, `<color=FFE08C>${set.name || ''}</color>`);
    for (const t of set.tiers || []) {
      const on = n >= t.need;
      for (const [ty, v] of t.effects || []) {
        const ot = db.optionType(ty), native = optionTemplate(db, ty);
        const text = ot?.text || (native ? String(native).replace(/<set=[^>]*>/gi, ' ').replace(/\s+/g, ' ') : `Option ${ty}: <VALUE>`);
        line(body, `(${t.need}) ${text.replace(/<VALUE>/g, fmt(optionDisplayValue(ty,v,db)))}`, { color: on ? '#00FF00' : '#808080' });
      }
    }
    div();
  }
  // 10 item list (packages)
  if (G(10) && def.use?.package != null) {
    const pk = sys.db.T?.packages?.[def.use.package];
    if (pk?.items?.length) {
      line(body, S_(10, 1));
      for (const [i, c] of pk.items) line(body, `${db.name(i)}${c > 1 ? ` x${fmt(c)}` : ''}`);
      div();
    }
  }
  // 11 description
  const desc = db.description(def);
  if (G(11) && desc) { for (const l of desc.split('\n')) line(body, l); }
  // 12 price
  if (G(12) || def.slot) {
    if (ctx.buyPrice != null) line(body, fill(S_(12, 2), { VALUE: dilMarkup(ctx.buyPrice) }));
    else if (def.npcSell !== 0 && (def.price > 0 || def.sell > 0)) line(body, fill(S_(12, 1), { VALUE: dilMarkup(sys.sellPrice(inst)) }));
  }
  // compare hint for bag items with a matching equipped item: the original stringtable_itemdesc 910:15 line
  // ("Press Ctrl key to compare the item with the equipped item.", fdb602).
  if (ctx.where === 'bag' && !ctx.comparing && def.slot && comparisonTargets(sys, inst).length) line(body, fill(S_(910, 15)) || '<color=fdb602>Press Ctrl key to compare the item with the equipped item.');
  // Original 910:17 Shift hint (fdb602) only when every present Rank/Brand section resolves; never for missing brand
  // provenance, ambiguous rank sources or custom items, and never inside a comparison (like 910:15).
  if(ranges.complete&&!ctx.comparing)line(body,fill(S_(910,17)));
  // drop trailing rule
  while (body.lastChild && !body.lastChild.textContent && body.lastChild.style?.backgroundImage !== undefined && body.lastChild.className !== 'itt-line') body.lastChild.remove();
  return root;
}

/**
 * Compare one explicitly labeled matching equipped slot at a time. The original tooltipwnd (script/ui/game2/
 * ui_tooltip.txt) owns two separate etc_01#66 panels: pan_tooltip (the hovered item) and pan_tooltipEx (the equipped
 * item, headed by lbl_tooltiptitleEx). Each item tooltip here is therefore its own frame (class uw-tip-frame, framed by
 * src/ui/uiwin/tooltip.js) at its natural width within the usual 170-320 px text box, and the pair (class
 * itt-compare) is placed, flipped, clamped and shrunk as one box. Their side-by-side order and the 4 px gap are an
 * ENGINE CHOICE: both panels are authored at 0,0 and positioned at runtime.
 */
export function buildCompare(sys, inst, ctx = {}) {
 const a=buildTooltip(sys,inst,{...ctx,comparing:true}),targets=comparisonTargets(sys,inst);if(!a||!targets.length)return a;
 const index=((ctx.compareIndex||0)%targets.length+targets.length)%targets.length,{slot,worn}=targets[index];
 const wrap=document.createElement('div');wrap.className='itt-compare';wrap.style.cssText='display:flex;gap:4px;align-items:flex-start;width:max-content';
 const b=buildTooltip(sys,worn,{where:'equip',comparing:true,optionRanges:ctx.optionRanges});
 // a single tooltip is the .uw-tip box (padding 6/8) around .itt (padding 6/10): each frame keeps that same inset
 for(const tip of [a,b]){tip.className+=' uw-tip-frame';tip.style.flex='none';tip.style.padding='12px 18px';}
 // Original tooltipEx caption: stringtable_tooltip 21:1 "Current Item" in lbl_tooltiptitleEx (game2/ui_tooltip.txt:
 // fontIndex 4, centre, ff00ff00). With several matching equipped slots the engine-extra slot label names the
 // compared slot (ctx.compareIndex, default the first); there is no keyboard pin or cycle.
 if(targets.length>1){const which=document.createElement('div');which.className='itt-slot';which.textContent=`${comparisonSlotLabel(slot)} (${index+1}/${targets.length})`;which.style.cssText='color:#fdb602;text-align:center';b.prepend(which);}
 const tag=document.createElement('div');tag.className='itt-caption';applyFont(tag,4);tag.textContent=sys.str?.(21,1)||'Current Item';tag.style.color='#00FF00';tag.style.textAlign='center';b.prepend(tag);
 const changes=el('div','itt-comparison',a);line(changes,`Compared with ${comparisonSlotLabel(slot)}`,{color:'#fdb602'});
 for(const row of comparisonDeltas(sys.db,inst,worn))line(changes,`${row.label}:<set=VALUE2>${fmt(row.value)}${row.unit||''} (${row.delta>0?'+':''}${fmt(row.delta)}${row.unit||''})`,{color:row.delta*row.direction>0?'#00FF00':row.delta*row.direction<0?'#FF0000':null});   // stringtable_color green1 / exceed (as option values)
 wrap.append(a,b);return wrap;
}

void S;
