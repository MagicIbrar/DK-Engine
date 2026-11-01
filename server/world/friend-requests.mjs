// Incoming friend requests (Global msgbox/ui_addfriend.txt "<name> has made a friend request. Would you like to accept
// it?" 1006:1, title 100:60, Yes/No). Minimal and isolated: the messenger/block system (lane-core) plugs in through
// shouldDeliverFriendRequest only.
//   friendrequest {operation:'request', targetName}  -> event {type:'friendrequest', reason:'request', id, fromName} to the target
//   friendrequest {operation:'accept'|'decline', id} -> event {type:'friendrequest', reason:'accept'|'decline', id, name} to the requester
// Pending requests live in memory for REQUEST_TTL_MS; the friend lists themselves stay client-side (src/systems/life/friends.js).
import { randomUUID } from 'node:crypto';
import { isBlacklisted } from './blacklist.mjs';
import { gameplayPreferences } from '../../src/game/gameplay-preferences.js';

export const FRIEND_REQUEST_SCHEMAS = { friendrequest: ['token', 'type', 'operation', 'targetName', 'id'] };
export const REQUEST_TTL_MS = 60000;
/** Global per-PC friend map Segment<30, Coupler<String<25>, IFriend*>> (global-re/SERVER-RE.md:143,148). No Global
 *  "friend list full" string exists (only 1006:56 for the blacklist), so the refusal uses code 'full'. */
export const MAX_FRIENDS = 30;
const friendCount = q => (q?.profile?.npcFriends || []).length;
const fail = (m, status = 400) => { throw Object.assign(Error(m), { status }); };
const key = n => String(n || '').trim().toLowerCase();

/** HOOK (lane-core): return false to drop a request silently, e.g. when `to` blocks `from`. Default delivers.
 *  At merge with lane-core 6345456 (server/world/blacklist.mjs, isBlacklisted at :19), the intended body is
 *    return !isBlacklisted(world, to, from);   // check its exact signature there; no cross-branch import yet. */
export function shouldDeliverFriendRequest(world, from, to) { return !isBlacklisted(to, from?.profile?.name); }   // integration: lane-core blacklist.mjs isBlacklisted(owner,name)

function pending(world) {
  const m = world.friendRequests ||= new Map(), now = world.now?.() ?? Date.now();
  for (const [id, r] of m) if (now - r.at > REQUEST_TTL_MS) m.delete(id);
  return m;
}

export function friendRequestCommand(world, p, input) {
  const m = pending(world);
  if (input.operation === 'request') {
    const name = key(input.targetName);
    if (!name || typeof input.targetName !== 'string' || input.targetName.length > 64) fail('Choose a character name.');
    if (name === key(p.profile?.name)) fail("You can't add yourself.");
    const to = [...world.players.values()].find(q => q !== p && !q.leaving && key(q.profile?.name) === name);
    if (!to) fail(`${input.targetName.trim()} is not connected.`, 404);
    if (gameplayPreferences(to.gameplayPreferences ?? to.profile?.gameplayPreferences).blockFriend) return { sent: false, code: 'declines', targetName: to.profile.name };
    if (friendCount(p) >= MAX_FRIENDS) return { sent: false, code: 'full', targetName: to.profile.name };
    if (friendCount(to) >= MAX_FRIENDS) return { sent: false, code: 'targetFull', targetName: to.profile.name };
    for (const r of m.values()) if (r.fromId === p.id && r.toId === to.id) return { sent: true, id: r.id, targetName: to.profile.name };
    if (!shouldDeliverFriendRequest(world, p, to)) return { sent: true, targetName: to.profile.name };
    const r = { id: randomUUID(), fromId: p.id, toId: to.id, fromName: p.profile.name, toName: to.profile.name, at: world.now?.() ?? Date.now() };
    m.set(r.id, r);
    world.emit(null, { type: 'friendrequest', reason: 'request', id: r.id, fromName: r.fromName, recipients: [to.id] });
    return { sent: true, id: r.id, targetName: r.toName };
  }
  if (input.operation === 'accept' || input.operation === 'decline') {
    const r = m.get(String(input.id || ''));
    if (!r || r.toId !== p.id) fail('That friend request is no longer available.', 404);
    m.delete(r.id);
    if (input.operation === 'accept' && friendCount(p) >= MAX_FRIENDS) fail('Your friend list is full.', 409);
    world.emit(null, { type: 'friendrequest', reason: input.operation, id: r.id, name: r.toName, recipients: [r.fromId] });
    return { accepted: input.operation === 'accept', fromName: r.fromName };
  }
  fail('Unknown friend request operation.');
}
