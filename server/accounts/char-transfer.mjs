// CHAR-TRADE: account-store side of the character transfer (server/world/char-trade.mjs drives the session).
// One store transaction moves the character record between accounts and writes both live (payment) profiles.
import {characterRef} from './character-ref.mjs';
import {CHAR_TRADE_ENGINE_CHOSEN as C} from '../../src/config/engine-chosen-char-trade.js';

export class CharTransferRefusal extends Error { constructor(msg, text) { super(text); this.charTradeMsg = msg; } }
const refuse = (msg, text) => { throw new CharTransferRefusal(msg, text); };
const owned = (db, id) => Object.hasOwn(db.users || {}, id) ? db.users[id] : null;
const n = v => Math.max(0, Math.round(Number(v) || 0));
const sum = list => (Array.isArray(list) ? list : []).reduce((n, row) => n + Math.max(1, Number(row?.inst?.count ?? row?.count) || 1), 0);

// ENGINE-CHOSEN: a character whose ref appears in any shared (non-account) record stays on its account (556:50).
export function referencedCharacter(db, accountId, characterId) {
  if (!C.refuseReferencedCharacters) return false;
  const ref = characterRef(accountId, characterId);
  for (const [key, value] of Object.entries(db || {})) {
    if (key === 'users' || key === 'sessions' || value == null) continue;
    if (JSON.stringify(value).includes(ref)) return true;
  }
  return false;
}

export function transferSummary(db, accountId, c) {
  const equip = c.equip && typeof c.equip === 'object' ? structuredClone(c.equip) : null;
  return {
    id: c.id, name: c.name, level: Math.max(1, Number(c.level) || 1), classIndex: c.classIndex ?? 0, className: c.className || '',
    restricted: referencedCharacter(db, accountId, c.id),
    detail: {
      equip, inventoryCount: Array.isArray(c.inventory) ? c.inventory.length : 0, inventoryItems: sum(c.inventory),
      dil: Math.max(0, Number(c.dil) || 0), storageCount: Array.isArray(c.storage) ? c.storage.filter(Boolean).length : 0,
      storageDil: 0,
      // the 556:16-29 lines of lbl_charInfo (STR DEX HETH MEN STATS SKILL POINTS HP MP SHIELD ADV.PTS EXP PK PVP Tendency)
      info: { str: n(c.stats?.str), dex: n(c.stats?.dex), con: n(c.stats?.con), spr: n(c.stats?.spr), statPoints: n(c.statPoints), skillPoints: n(c.skillPoints),
        hp: n(c.hp), mp: n(c.mp), shield: n(c.shield), advPoints: n(c.advPoints), exp: n(c.exp), pk: n(c.pk), pvp: n(c.kills), tendency: n(c.tendency) },
    },
  };
}

export function createCharTransferHooks({ load, transact }) {
  return {
    // The seller's movable characters (server authority, not the played one) and the account's character count.
    async charTransferInfo(accountId, excludeCharacterId) {
      const db = await load();
      const owner = owned(db, accountId);
      if (!owner) return { count: 0, characters: [] };
      const list = owner.characters || [];
      return {
        count: list.length,
        characters: list.filter(c => c.authority === 'server' && (C.movePlayedCharacter || c.id !== excludeCharacterId)).map(c => transferSummary(db, accountId, c)),
      };
    },
    // fromAccount's character moves to toAccount; updates = the two live profiles after the payment exchange.
    async transferCharacter({ fromAccount, toAccount, characterId, expected, updates }) {
      return transact(db => {
        const from = owned(db, fromAccount), to = owned(db, toAccount);
        if (!from || !to || fromAccount === toAccount) refuse(C.msg.failed, 'Character transfer accounts are unavailable.');
        const index = from.characters.findIndex(c => c.id === characterId && c.authority === 'server');
        if (index < 0) refuse(C.msg.notFound, 'The character is no longer on the account.');
        const moving = from.characters[index];
        if (expected !== undefined && JSON.stringify(moving) !== expected) refuse(C.msg.wait, 'The character changed during the transfer.');
        if (referencedCharacter(db, fromAccount, characterId)) refuse(C.msg.restricted, 'The character is restricted from transfer.');
        if (to.characters.length >= C.receiverMaxCharacters) refuse(C.msg.slotsFull, 'The receiving account has no empty character slot.');
        if (to.characters.some(c => c.id === characterId)) refuse(C.msg.failed, 'Character id collision.');
        const targets = (updates || []).map(({ accountId, characterId: id, profile }) => {
          const owner = owned(db, accountId);
          const at = owner?.characters.findIndex(c => c.id === id && c.authority === 'server') ?? -1;
          if (at < 0 || id === characterId) refuse(C.msg.failed, 'A trading character is unavailable.');
          return { owner, at, profile };
        });
        for (const { owner, at, profile } of targets) {
          const old = owner.characters[at];
          owner.characters[at] = { ...profile, id: old.id, name: old.name, nameColor: old.nameColor || 'white', classIndex: old.classIndex, className: old.className, authority: 'server', lastPlayed: Date.now() };
          if (profile.accountFeatures) { owner.accountFeatures = structuredClone(profile.accountFeatures); delete owner.characters[at].accountFeatures; }
          owner.revision = (owner.revision || 0) + 1;
        }
        from.characters.splice(index, 1);
        to.characters.push({ ...moving, transferredAt: Date.now() });
        from.revision = (from.revision || 0) + 1;
        to.revision = (to.revision || 0) + 1;
        return { id: moving.id, name: moving.name, from: fromAccount, to: toAccount };
      });
    },
  };
}