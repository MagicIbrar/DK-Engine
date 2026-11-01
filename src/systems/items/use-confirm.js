// Global's own confirmation / refusal boxes before a cash item is used (script/ui/game2/msgbox/cashitem, strings cate 170 of
// stringtable_cashitem.txt). Client side only: the rules themselves are enforced by ItemUse (use.js), which the host runs too.
//   Traveler's Backpack   (type 0 code 15)  ui_addbag 170:19 "Remaining uses: <VALUE>" | ui_erraddbag 170:22 at the 5-use cap
//   Storage Mastery       (code 20)         ui_addstorage 170:21 | ui_erraddstorage (its 170:24 is absent: 170:22 shown)
//   Storage Keeper's Key  (code 29)         ui_addcommonstorage 170:20 | ui_erraddcommonstorage (170:23 absent: 170:22)
//   Master's Mistake      (code 10)         ui_mastermistake 170:26 <CUR_NUM> -> <POST_NUM> | ui_errmastermistake 170:25 at 0
//   Regenerators          (codes 6..9)      ui_powerreset / ui_energyreset / ui_speedreset / ui_spiritreset, 170:28 with the
//                                           stat name 170:30..33, current stat, Level 1 stat, stat points afterwards
//   Portal Scroll         (type 3 code 4)   ui_potalorder 170:35 "Would you like to use Portal Scroll?"
// Each box has one Confirm (btn_yes) and the close cross: Confirm uses the item, the cross keeps it.
import { formatString } from '../../ui/uiwin/strings.js';
import { STAT_RESET, wearsWeapon } from './use.js';

const BOX = 'game2/msgbox/cashitem/';
const S = (game, code) => game.uiwin?.strings?.resolve?.({ group: 'NORMAL', cate: 170, code }).then(v => v ?? '').catch(() => '') ?? Promise.resolve('');
const REGEN = { 6: ['ui_powerreset', 30], 7: ['ui_energyreset', 31], 8: ['ui_speedreset', 32], 9: ['ui_spiritreset', 33] };
const box = (game, script, text, body) => game.uiwin.msgbox(text, { kind: 'yesno', script: BOX + script, scripted: true, body });
const notice = (game, script, text = null, body) => game.uiwin.msgbox(text, { kind: 'ok', script: BOX + script, scripted: true, body });

/** Resolves true when the item may be used (confirmed, or no Global box applies). */
export async function confirmItemUse(game, inst, def) {
  if (!game?.uiwin?.msgbox || !def) return true;
  const t = Number(def.type), c = Number(def.code), save = game.save || {};
  const yes = r => r === 'yes';
  if (t === 3 && c === 4) return yes(await box(game, 'ui_potalorder.txt', await S(game, 35), 'lbl_text'));
  if (t !== 0) return true;
  if (c === 63) return yes(await game.uiwin.msgbox(null, {
    kind: 'yesno', script: 'game2/skillmsg/ui_skillmsgbox.txt', scripted: true,
  }));
  if (c === 15) {
    const left = 7 - (Number(save.bagsUnlocked) || 2);
    if (left <= 0) { await notice(game, 'ui_erraddbag.txt'); return false; }
    return yes(await box(game, 'ui_addbag.txt', formatString(await S(game, 19), { VALUE: left }), 'lbl_msg'));
  }
  if (c === 20) {
    const left = 4 - (Number(save.stashUnlocked) || 2);
    if (left <= 0) { await notice(game, 'ui_erraddstorage.txt', await S(game, 24) || await S(game, 22), 'lbl_errMsg'); return false; }
    return yes(await box(game, 'ui_addstorage.txt', formatString(await S(game, 21), { VALUE: left }), 'lbl_msg'));
  }
  if (c === 29) {
    const shared = !!(game.items?.account?.()?.sharedStash ?? save.accountFeatures?.sharedStash);
    if (shared) { await notice(game, 'ui_erraddcommonstorage.txt', await S(game, 23) || await S(game, 22), 'lbl_errMsg'); return false; }
    return yes(await box(game, 'ui_addcommonstorage.txt', formatString(await S(game, 20), { VALUE: 1 }), 'lbl_msg'));
  }
  if (c === 10) {
    const resets = Math.max(0, Math.floor(Number(save.skillResets) || 0));
    if (!resets) { await notice(game, 'ui_errmastermistake.txt'); return false; }
    return yes(await box(game, 'ui_mastermistake.txt', formatString(await S(game, 26), { CUR_NUM: resets, POST_NUM: resets - 1 }), 'lbl_msg'));
  }
  if (REGEN[c]) {
    if (game.items && wearsWeapon(game.items)) return true;   // ItemUse refuses (40:51); no confirmation for a refused use
    const [script, nameCode] = REGEN[c], key = STAT_RESET[c];
    const base = Number(game.classDef?.stats?.base?.[key]) || 0, now = Number(save.stats?.[key]) || 0;
    const back = Math.max(0, now - base), points = Number(save.statPoints) || 0;
    if (!back) return true;   // ItemUse reports the nothing-to-reset case (40:51)
    const name = (await S(game, nameCode)).trim();
    const text = formatString(await S(game, 28), { NAME: name, VALUE1: now, VALUE2: base, VALUE3: points + back });
    return yes(await box(game, `${script}.txt`, text, 'multilbl_0'));
  }
  return true;
}
