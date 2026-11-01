// FIELD-PK, client side: the Force Attack key (key map action 'forceattack', Ctrl by default) arms attacks on other players of open PvP
// fields. While the key is held (or for a moment after a forced attack, so the swings of a fight keep going) another player who is not in
// your party or guild counts as hostile (game.isPvpHostile): the click attacks it, skills may target it, the cursor turns into the swords.
// The HOST decides everything (server/world/field-pk.mjs): the client only says "forced" with the attack / cast command. Maps follow
// the original maplist flags (IsPvP 1 + PVP_PeaceZone 0). Messages are stringtable_pc cate 1003.
import { FIELD_PK, PK_TEXT } from '../../config/engine-chosen-pk.js';

export function installFieldPk(game, network) {
  const latch = { id: null, until: 0 };
  const now = () => (typeof performance !== 'undefined' ? performance.now() : Date.now());
  let fallbackCtrl = false;   // without the key map (headless): the Ctrl key itself
  const track = e => { if (e.key === 'Control') fallbackCtrl = e.type === 'keydown'; };
  const reset = () => { fallbackCtrl = false; };
  const w = globalThis.window;
  w?.addEventListener?.('keydown', track, true); w?.addEventListener?.('keyup', track, true); w?.addEventListener?.('blur', reset);
  const held = () => {
    const km = game.keymap, spec = km?.get?.('forceattack');
    if (km && spec) return !!km.down(spec, true) && !game.uiwin?.capturesInput;
    return fallbackCtrl;
  };
  const pkMap = () => {
    // Instanced modes authorize their own targets. Ctrl never promotes a
    // protected Dead Front party (or another instance) to a field-PK enemy.
    if (network.self?.instanceId) return false;
    const index = game.world?.info?.index, row = game.mapRow?.(index) || game.world?.info?.row || null;
    return Number(row?.IsPvP) === 1 && Number(row?.PVP_PeaceZone) === 0;
  };
  const ally = a => {
    const id = a?.networkId;
    if (!id) return false;
    if ((network.party?.members || []).some(m => m.id === id)) return true;
    const mine = network.self?.nameplate?.guild?.id ?? game.player?.nameplate?.guild?.id, theirs = a.nameplate?.guild?.id;
    return game.options?.get?.('notGuild') !== false && !!mine && mine === theirs;
  };
  const api = {
    held,
    /** Ctrl is down on a PK field: an area skill / swing with no player target may hit players too. */
    armedNow() { if (!pkMap()) return false; if (held()) { latch.any = now() + FIELD_PK.forcedWindowMs; return true; } return now() < (latch.any || 0); },
    /** May this player be attacked right now with the Force Attack key (host re-checks everything)? */
    isEnemy(a) {
      if (!a || a.kind !== 'player' || a === game.player || a.dead || !a.networkId || !pkMap() || ally(a)) return false;
      return Number(a.nameplate?.wanted)>0 || a.nameplate?.nameColor==='wanted1' || held() || (latch.id === a.networkId && now() < latch.until);
    },
    /** Does this attack / cast command carry the forced flag? Arms the follow-up swings for a moment. */
    forcedFor(a) {
      if (!api.isEnemy(a) || !(held() || (latch.id === a.networkId && now() < latch.until))) return false;
      latch.id = a.networkId; latch.until = latch.any = now() + FIELD_PK.forcedWindowMs;
      return true;
    },
    dispose() { w?.removeEventListener?.('keydown', track, true); w?.removeEventListener?.('keyup', track, true); w?.removeEventListener?.('blur', reset); },
  };
  network.fieldPk = api;
  return api;
}

/** The chat line of a host 'pk' event (stringtable_pc 1003): null when it is not for this player. */
export function pkNotice(event, selfId, nameOf, text = (code) => null) {
  const line = code => text(code) || PK_TEXT[code];
  const who = id => nameOf(id) || '';
  const toMe = event.targetId === selfId, byMe = event.actorId === selfId;
  switch (event.reason) {
    case 'attacked': return toMe ? { text: `${who(event.actorId)} ${line(1)}`, kind: 'err' } : byMe ? { text: `${who(event.targetId)} ${line(2)}`, kind: 'sys' } : null;
    case 'killed': return toMe ? { text: `${who(event.actorId)} ${line(4)}`, kind: 'err' } : byMe ? { text: `${who(event.targetId)} ${line(5)}`, kind: 'sys' } : null;
    case 'evil': return byMe ? { text: String(line(7)).replace(/^\[Message\]\s*/i, ''), kind: 'err' } : null;
    default: return null;
  }
}
