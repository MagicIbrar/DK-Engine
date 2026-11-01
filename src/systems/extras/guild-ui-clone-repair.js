// ENGINE-CHOSEN presentation repair for three broken native clone names in
// ui_gskillwnd_renew.txt. The native duration controls name level0 sources that
// do not exist; their same-row level siblings provide the authored styles.
// No native data is changed, no generic clone-name heuristic is applied.
import {repairMissingCloseButton} from '../../ui/native-close-art.js';
export function repairGuildDurationClones(item) {
  for (const [targetId, sourceId] of [['lbl_skill_time','lbl_skill_level'],['btn_minus_time','btn_minus_level'],['btn_plus_time','btn_plus_level']]) {
    const target=item.control(targetId),source=item.control(sourceId);
    if (!target?.spec || !source?.spec || target.spec.cloneOf || target.spec.props?.clone?.[0]!==sourceId+'0') continue;
    if (!target.spec.images?.length) for (const image of source.spec.images||[]) target.setImage(image.key,{...image});
    if (!target.spec.titles?.length) {
      target.titles=Object.fromEntries((source.spec.titles||[]).map(title=>[title.state,{...title}]));
      target.spec.align=source.spec.align?{...source.spec.align}:null;
      target.paintText?.();
    }
  }
}

// ENGINE-CHOSEN presentation: the active donation script's guild_02 61..63
// close art is absent. Reuse the authored Guild Notice close art, keeping its
// existing hit box and close handler. No synthetic art or atlas rectangle.
export function repairGuildDonationClose(window,table) {
  repairMissingCloseButton(window.control('btn_exit'),'guild_02',61,table);
}
