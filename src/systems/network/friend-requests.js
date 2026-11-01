// Incoming friend requests, client side (server/world/friend-requests.mjs). The target sees Global's
// msgbox/ui_addfriend.txt (addfriend_msgbox: title 100:60, lbl_text = requester, lbl_askMsg 1006:1, Yes/No); Yes adds
// the requester to the local friend list (life/friends.js add) and tells the server, which notifies the requester, whose
// client adds the target too. Isolated: messenger/block rules plug in on the server (shouldDeliverFriendRequest).
import { globalAsk } from '../../ui/uiwin/global-asks.js';

export function installFriendRequests(game, network) {
  const log = (t, k = 'sys') => game.hud?.log?.(t, k);
  const api = {
    async request(name) {
      const r = await network.action('friendrequest', { operation: 'request', targetName: String(name || '').trim() });
      const res = r?.friendRequestResult; if (!res) return null;
      if (!res.sent) log(res.code === 'full' ? 'Your friend list is full.' : res.code === 'targetFull' ? `${res.targetName || name}'s friend list is full.` : `[${res.targetName || name}] does not accept any requests.`, 'err');
      return res;
    },
    async receive(ev) {
      if (ev.reason === 'request') {
        const yes = await globalAsk(game, 'addFriend', ev.fromName);
        const r = await network.action('friendrequest', { operation: yes ? 'accept' : 'decline', id: ev.id });
        if (yes && r?.friendRequestResult?.accepted) game.life?.friends?.add?.(ev.fromName);
        return yes;
      }
      if (ev.reason === 'accept') { game.life?.friends?.add?.(ev.name); return true; }
      if (ev.reason === 'decline') { log(`${ev.name} declined your friend request.`, 'sys'); return false; }
      return null;
    },
  };
  game.friendRequests = api;
  const prev = network._event?.bind(network);
  network._event = record => { if (record?.type === 'friendrequest') void api.receive(record); else prev?.(record); };
  game.chat?.registerCommand?.('/friendrequest', name => { if (name) void api.request(name); return true; }, 'Send a friend request: /friendrequest Name');
  return api;
}
