// Shared Zuto's Battlefield client bridge (owner-directed single-server adaptation, src/game/urban-warfare-rules.js
// ZUTO_ADAPTATION). Intent only: the host assigns the side, owns the battle clock, stones, kills, refusals and rewards.
//   - Ardeca Jerome (121): native job31/65000, label150:65000 and prompt150:65100. The
//     registration intent lets the host assign the character and move it to the appropriate lobby.
//   - Guardian stones (job 119) on map 650: {type:'zuto', operation:'seize', npcIndex} for a current member; otherwise the
//     caller keeps the native unavailable text (network/events.js).
//   - Host notices (zutoNotice {cate, code}) and stone changes (zutoStone) become chat lines with the original strings.
// The Checkpoint (Entrance) teleport 133 needs no client change: the ordinary teleport window sends the native intent.
import {plain} from '../events/text.js';
import {message as dungeonMessage} from '../dungeons/data.js';
import {EffectBanners} from '../events/effectui.js';
import {installZutoWindows} from './zuto-windows.js';

const REGISTER_NPC = 121, ARDECA = 150, BATTLEFIELD = 650, ROLE = 'ZUTO_ENTRANCE';
const STONE_NAME = [606, 607, 608, 609, 610];          // stringtable_dksquare 160:606-610
const TEAM = { red: 644, blue: 643 }; // native dashboard and victory banners: red Ricchez, blue Miseria
const FALLBACK = {
  '150:65000': '[DKS] You are moving to Zuto’s Battlefield.', '150:65100': 'Would you move to Zuto’s Battlefield?',
  '160:643': 'Miseria', '160:644': 'Ricchez', '160:625': 'Neutral State',
};

export function installSharedZuto(game, network, { bridge } = {}) {
  const state = { snapshot: null }, banners = new EffectBanners(game, bridge);
  let disposed = false;
  const text = (cate, code) => {
    const data = bridge?.data; let t = null;
    try { t = data?.mapTxt?.(cate, code) || data?.txt?.('stringtable_map_string_01.txt', cate, code) || data?.txt?.('stringtable_map_string_02.txt', cate, code) || data?.txt?.('stringtable_dksquare.txt', cate, code); } catch { t = null; }
    return plain(String(t || dungeonMessage(cate,code)?.t || FALLBACK[`${cate}:${code}`] || '')).trim();
  };
  const say = (line, kind = 'sys') => { if (line) game.chat?.system?.(line, kind); };
  const refusal = error => { const m = /^zuto:(\d+):(\d+)$/.exec(String(error?.message || '')); return m ? text(Number(m[1]), Number(m[2])) || error.message : error?.message; };
  // network.action resolves null on a refusal (client.js shows plain-text refusals and leaves coded `zuto:<cate>:<code>`
  // ones to this bridge), so a null result reads the coded refusal back and shows its original string.
  const send = input => Promise.resolve(network.action('zuto', input)).then(result => {
    if (result == null) { const m = network._lastCommandError?.message; if (/^zuto:\d+:\d+$/.test(String(m || ''))) say(refusal({ message: m }), 'err'); }
    return result;
  });
  const online = () => !!network && !network.disposed;
  const windows=installZutoWindows(game,network,()=>state.snapshot,text);

  // Jerome's authored job31/65000. The dialog merges this override into the native job row.
  const provider = n => Number(n) === REGISTER_NPC && online() && Number(game.world?.info?.index) === ARDECA ? [{ jobType:31, jobIndex:65000, role: ROLE, label: text(150, 65000) }] : [];
  const registerEntry = () => {
    const ask = game.uiwin?.msgbox?.(text(150, 65100), { kind: 'yesno', title: text(150, 65000) });
    void Promise.resolve(ask).then(answer => {
      if (answer !== 'yes' && answer !== true) return;
      return send({ operation: 'register', npcIndex: REGISTER_NPC }).then(result => {
        const r = result?.zutoResult;
        if (r?.registered) say(`${text(150, 65000)}: ${text(160, TEAM[r.side])}`);
      });
    }).catch(error => say(refusal(error), 'err'));
    return true;
  };
  let undo = [];
  const register = () => {
    for (const u of undo) { try { u?.(); } catch { /* registry replaced */ } }
    undo = [game.npcServices?.provide?.(provider), game.npcServices?.register?.(31, (npc,info) => Number(info.npcIndex)===REGISTER_NPC&&Number(info.jobIndex)===65000&&Number(game.world?.info?.index)===ARDECA ? registerEntry():false), game.npcServices?.register?.(ROLE, () => registerEntry())];
  };
  register(); game.events?.on?.('systems', register);

  // Guardian stone (job 119): only a current member on the battlefield sends the seize intent.
  const stone = npc => {
    if (!online() || Number(game.world?.info?.index) !== BATTLEFIELD || !state.snapshot?.mine || state.snapshot.mine.left || state.snapshot.mine.evicted) return false;
    void send({ operation: 'seize', npcIndex: Number(npc?.npcIndex ?? npc?.def?.index) }).catch(error => say(refusal(error), 'err'));
    return true;
  };

  const originalSnapshot = network._snapshot.bind(network);
  network._snapshot = snapshot => { originalSnapshot(snapshot); if (!network.disposed && Number(snapshot?.sequence) >= network.sequence) {state.snapshot = snapshot?.zuto ?? null;windows.update();} };
  const originalEvent = network._event.bind(network);
  network._event = event => {
    if (event?.type === 'zutoNotice') {
      const cate=Number(event.cate),code=Number(event.code),data=bridge?.data;
      const entry=data?.mapStr?.(cate,code)||data?.str?.('stringtable_dksquare.txt',cate,code);
      say(text(cate,code).replace(/__/g,String(event.minutes??'')));
      for(const effect of entry?.effectUi||[]) if(!disposed) void banners.show(effect.id,effect.ms).catch(()=>{});
      return;
    }
    if (event?.type === 'zutoStone') { say(`${text(160, STONE_NAME[event.stone] ?? 606)} - ${event.owner ? text(160, TEAM[event.owner]) : text(160, 625)}`); return; }
    if (event?.type === 'zutoMove') return;
    originalEvent(event);
  };
  const previousUpdate=bridge.update;bridge.update=dt=>{previousUpdate?.(dt);if(!disposed){banners.update(dt);windows.update();}};
  const api = { stone, get snapshot() { return state.snapshot; }, dispose() { disposed=true;windows.dispose();for(const b of banners.live)for(const p of b.parts)p.el.remove();banners.live.length=0;for (const u of undo) { try { u?.(); } catch { /* ignore */ } } undo = []; } };
  const previousDispose=bridge.dispose;bridge.dispose=()=>{api.dispose();previousDispose?.();};
  game.sharedZuto = api;
  return api;
}
