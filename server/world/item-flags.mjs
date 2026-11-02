/**
 * Server-side item flag enforcement helpers (Lane 26 + Lane 42).
 * Re-exports pure rules from src/systems/items/flags.js and adds inventory purge
 * matching client ItemsSystem._expire (bag / personal stash / costume bag only).
 */
import {
  canConsignItem,
  canDiscardDef,
  canDropToGround,
  canEnterSharedStorage,
  canMailAttachment,
  canNpcSell,
  canPcShopList,
  canTradeOffer,
  destroysOnExpiry,
  isBoundInst,
  isExpiredInst,
  isTradableDef,
  bindsOnPickup,
  belongValue,
  stackLimit,
  maxStackNumber,
  isAutoStackDef,
  isStackable,
  isNpcSellableDef,
  hasPeriod,
  readFlags,
  FLAG_FIELDS,
} from '../../src/systems/items/flags.js';

export {
  canConsignItem,
  canDiscardDef,
  canDropToGround,
  canEnterSharedStorage,
  canMailAttachment,
  canNpcSell,
  canPcShopList,
  canTradeOffer,
  destroysOnExpiry,
  isBoundInst,
  isExpiredInst,
  isTradableDef,
  bindsOnPickup,
  belongValue,
  stackLimit,
  maxStackNumber,
  isAutoStackDef,
  isStackable,
  isNpcSellableDef,
  hasPeriod,
  readFlags,
  FLAG_FIELDS,
};

/**
 * Remove expired bag/storage/costumeBag entries when PeriodBreak is truthy.
 * Mirrors src/systems/items/index.js _expire. Does not touch account-shared
 * storage (client _expire does not). Equip expiry stays in deriveEquipment.
 * Mutates profile arrays in place; returns count removed.
 */
export function purgeExpiredInventory(profile, db, now) {
  if (!profile || !db || !Number.isFinite(now)) return 0;
  let removed = 0;
  const lists = [profile.inventory, profile.storage, profile.costumeBag];
  for (const list of lists) {
    if (!Array.isArray(list)) continue;
    for (let i = list.length - 1; i >= 0; i--) {
      const it = list[i];
      if (!it?.expiresAt || it.expiresAt >= now) continue;
      const def = db.def(it.itemIndex);
      if (def?.periodBreak) {
        list.splice(i, 1);
        removed++;
      }
    }
  }
  return removed;
}

/** Refuse reason strings; shared/discard/npcSell use Global text (190:7, 40:80, 340:9) since lane 67. */
export const FLAG_REFUSALS = Object.freeze({
  trade: 'That item cannot be traded.',
  shared: 'You cannot store items in the selected location.',
  mail: 'That item cannot be mailed.',
  consignBind: 'Binded Items cannot be registered',
  consignPeriod: 'Periodical/Timed Items cannot be registered',
  consignPet: 'This item cannot be registered',
  discard: '[Message] Quest or Event items cannot be discarded.',
  npcSell: 'Cannot sell items.',
});

