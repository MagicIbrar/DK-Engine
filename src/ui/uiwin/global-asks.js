// Global confirmation boxes that carry their own text (script text2 title / message / buttons), opened through
// UIManager.msgbox({ script, scripted: true }) so the scripted strings stay. Spec: Global script/ui/game2/msgbox/*.txt.
//   disbandGuild  ui_disbandguild.txt   disband_guild           100:56 title, lbl_disbandMsg 130:71, Yes/No
//   secedeGuild   ui_secedeguild.txt    secede_msgbox           100:58 title, lbl_msg 130:44, Yes/No
//   joinGuild     ui_joinguild.txt      guildinvite_msgbox      100:72 title, lbl_inviteMsg 130:45, lbl_text = guild, Accept/Decline
//   partyDisband  ui_partydisband.txt   partydisband_msgbox     70:34 title, lbl_msg 70:30, Yes/No (the leader leaves)
//   partySecede   ui_partysecession.txt partysecession_msgbox   70:35 title, lbl_msg 70:26, Yes/No (a member leaves)
//   troopLeave    ui_troopleave.txt     troopleave_msgbox       100:98 title, lbl_msg 555:28, Yes/No
//   troopDisband  ui_troopdisband.txt   troopdisband_msgbox     300:12 title, lbl_msg 555:30, 70:39/70:40
//   addFriend     ui_addfriend.txt      addfriend_msgbox        100:60 title, lbl_text = requester, lbl_askMsg 1006:1, Yes/No
//   changeGradeGuild ui_changegradeguild.txt changegrade_guild 100:48 title, lbl_disbandmsg 130:146 "request the changed authority setting?", Accept/Decline
//   troopInvite   ui_troopinvite.txt    troopinvite_msgbox      555:21 title, lbl_text = inviter, lbl_msg 555:23, Accept/Decline
export const GLOBAL_ASKS = Object.freeze({
  disbandGuild: { script: 'game2/msgbox/ui_disbandguild.txt', window: 'disband_guild' },
  secedeGuild: { script: 'game2/msgbox/ui_secedeguild.txt', window: 'secede_msgbox' },
  joinGuild: { script: 'game2/msgbox/ui_joinguild.txt', window: 'guildinvite_msgbox', body: 'lbl_text' },
  partyDisband: { script: 'game2/msgbox/ui_partydisband.txt', window: 'partydisband_msgbox' },
  partySecede: { script: 'game2/msgbox/ui_partysecession.txt', window: 'partysecession_msgbox' },
  troopLeave: { script: 'game2/msgbox/ui_troopleave.txt', window: 'troopleave_msgbox' },
  troopDisband: { script: 'game2/msgbox/ui_troopdisband.txt', window: 'troopdisband_msgbox' },
  addFriend: { script: 'game2/msgbox/ui_addfriend.txt', window: 'addfriend_msgbox', body: 'lbl_text' },
  changeGradeGuild: { script: 'game2/msgbox/ui_changegradeguild.txt', window: 'changegrade_guild' },
  troopInvite: { script: 'game2/msgbox/ui_troopinvite.txt', window: 'troopinvite_msgbox', body: 'lbl_text' },
});

/** Opens a Global confirmation; resolves true on Yes/Accept. `text` fills the box's free label (joinGuild: the guild). */
export async function globalAsk(game, key, text = null) {
  const a = GLOBAL_ASKS[key];
  if (!a) throw new Error(`unknown Global ask ${key}`);
  const ui = game?.uiwin;
  if (!ui?.msgbox) return false;
  const r = await ui.msgbox(text, { kind: 'yesno', script: a.script, name: a.window, scripted: true, body: a.body });
  return r === 'yes';
}
