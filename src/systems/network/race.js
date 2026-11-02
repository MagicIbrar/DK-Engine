// EVENT-MODES shared-world adapter: the host-owned Mission titles (server/world/titles.mjs).
// Titles only: game.life.grade.setTitle sends the `title` operation and game.life.grade.owns reads the host's profile.life.titles.
import { ownsTitle } from '../life/title-rules.js';

// Lane 47: the Global client never opens game2/race/ui_entreeinfo, ui_connectpc or ui_dashboard (no script reference in any
// decompile decompiled.c), so the race windows, their English labels/status texts, the plate colours and the /race command
// (all invented) are removed. Only the Mission titles stay.
export function installSharedRace(game, network) {
  // Lane 47: the race host state, race PvP hostility and race death-window override are removed with the race host.
  const err = e => game.chat?.system?.(e?.message || String(e), 'err');
  // ---- Mission titles: the host owns ownership and the shown title
  const grade = game.life?.grade, setTitle = grade?.setTitle, owns = grade?.owns;
  if (grade) {
    grade.owns = i => ownsTitle(game.save?.life?.titles, i);
    grade.setTitle = i => {
      const index = Number(i) || 0;
      if (index && !grade.owns(index)) return false;
      void network.action('event', { operation: 'title', title: index }).then(() => game.events?.emit?.('life:title', { index })).catch(err);
      return true;
    };
  }
  const dispose = network.dispose.bind(network);
  network.dispose = () => {
    if (grade) { if (setTitle) grade.setTitle = setTitle; if (owns) grade.owns = owns; else delete grade.owns; }
    dispose();
  };
  return null;
}
