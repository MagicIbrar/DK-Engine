// Select the authored renewal layout without breaking older Global packs.
export const LEGACY_PET_UI = 'game2/pet/ui_petinfownd.txt';
export const RENEWAL_PET_UI = 'game2/pet/ui_petinfownd_renewal.txt';
export async function resolvePetLayout(manager) {
  const result = await manager.loadScript(RENEWAL_PET_UI);
  return result?.windows?.find(w => w.name === 'petinfo') || LEGACY_PET_UI;
}
export function refreshPetDetails(win, sys, def, state, skills) {
  win.find('lbl_def_petkind')?.setText(def?.n || '');
  for (let i = 0; i < 4; i++) {
    const skill = skills?.[i];
    const icon = win.find('pan_skillicon_' + i);
    icon?.setIcon(skill ? { sprite: ['pet_skill', skill.icon] } : null);
    icon?.setTooltip(skill ? () => skill.name + '\n' + sys.optionLine(skill.option) : null);
    win.find('lbl_def_skill_' + i)?.setText(skill?.name || '');
    win.find('lbl_def_skillv_' + i)?.setText(skill ? sys.optionLine(skill.option) : '');
  }
  for (let i = 0; i < 3; i++) {
    const option = state?.opts?.[i];
    const row = option && sys.data.ui?.petTables?.option?.find(r => r.index === Number(option[2]));
    const name = row ? String(row.text || row.type || '').replace(/<[^>]+>/g, '').trim() : '';
    win.find('lbl_def_grade_' + i)?.setText(name);
    win.find('lbl_def_gradev_' + i)?.setText(row ? String(option[1]) : '');
    for (const id of ['lbl_def_socket_' + i, 'lbl_def_socketv_' + i]) {
      win.find(id)?.setText('').setTooltip('Pet socket bonuses are not supported by this engine.');
    }
  }
}
export function bindRenewalPetControls(win) {
  win.find('btn_settingclose')?.onClick(() => win.close());
  win.find('check_questitem')?.setChecked(false).setEnabled(false)
    .setTooltip('Quest items cannot be collected by pets.');
}
