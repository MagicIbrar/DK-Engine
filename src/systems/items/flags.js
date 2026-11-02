/**
 * Global item flag readers and transfer rules (Lane 26 / Lane 42 step 27 enforcement).
 *
 * Field meanings come from Global item.dat + itemdesc + 4.2.0 ItemDB defaults
 * (dedicated-source -> global-prepared items.json). Unknown bits stay UNRESOLVED.
 * Do not invent MaxStackNumber / AutoStack / Belong=2 merge or bind rules here.
 */
export const FLAG_FIELDS = Object.freeze([
  'trade', 'belong', 'periodBreak', 'period',
  'stack', 'maxStack', 'autoStack',
  'npcSell', 'sell', 'price', 'cash',
  'classMask', 'reqLv', 'maxLv', 'reqStr', 'reqDex', 'reqSpr', 'reqGrade',
  'attribute', 'group', 'union', 'appraisal', 'rank',
  'dropStack', 'dropRate',
]);

/** trade!=0 after defaults (default trade=1). */
export function isTradableDef(def) {
  return !!def && Number(def.trade) !== 0;
}

/** Instance bind flag (set on pickup when belong===1, or by reward options). */
export function isBoundInst(inst) {
  return !!(inst && inst.bound);
}

/**
 * belong===1 is Bind-on-pickup (sets inst.bound).
 * belong===2 is NOT bind-on-pickup: 231 cash pet/package/premium rows; 29 keep trade=1.
 * Positive meaning of belong=2 stays UNRESOLVED — never invent account-bind from it.
 */
export function bindsOnPickup(def) {
  return Number(def?.belong) === 1;
}

export function belongValue(def) {
  return Number(def?.belong) || 0;
}

/** PeriodBreak truthy -> destroy when expires (client ItemsSystem._expire). Default 1. */
export function destroysOnExpiry(def) {
  return !!(def && def.periodBreak);
}

export function hasPeriod(def) {
  return Number(def?.period) > 0;
}

export function isExpiredInst(inst, now) {
  return !!(inst?.expiresAt && inst.expiresAt <= now);
}

/**
 * Stack merge/split limit: ItemDB.stackSize uses StackNumber only (item.dat @334).
 * MaxStackNumber (items.json maxStack @332) often differs on cash rows (e.g. Magic HP A
 * stack=9999 maxStack=300). Tooltip MAXSTACK currently = stackSize (bag capacity).
 * Shop buy qty UI uses maxlength4 (9999) / shop-slot StockCount — not MaxStackNumber.
 * Effect of MaxStackNumber remains UNRESOLVED; expose via maxStackNumber() only.
 */
export function stackLimit(def) {
  const s = Number(def?.stack) || 0;
  return s > 1 ? s : 1;
}

/** Raw MaxStackNumber after ItemDB merge (0 when unset). */
export function maxStackNumber(def) {
  return Number(def?.maxStack) || 0;
}

/**
 * AutoStack bit (item.dat @336). 3923 defs autoStack=1; 708 stackable defs auto=0
 * (quest mats/food). Container.add merges any stackSize>1; no recovered path gates
 * merge on this bit. UNRESOLVED — do not refuse merges when autoStack=0.
 */
export function isAutoStackDef(def) {
  return Number(def?.autoStack) === 1;
}

export function isStackable(def) {
  return stackLimit(def) > 1;
}

/** NPC sell allowed: npcSell!=0 (default 1). */
export function isNpcSellableDef(def) {
  return !!def && Number(def.npcSell) !== 0;
}

/** type=0 code=4 cannot be discarded (loot / cursor-custody). No separate destroyable column. */
export function canDiscardDef(def) {
  return !(Number(def?.type) === 0 && Number(def?.code) === 4);
}

/** Ground drop creates a loot pile only when tradable and unbound (else discard destroys). */
export function canDropToGround(def, inst) {
  return !!def && !isBoundInst(inst) && isTradableDef(def);
}

/** Shared/account storage deposit (personal stash allows bound). Pet refusal stays at call site. */
export function canEnterSharedStorage(def, inst) {
  return !!def && !isBoundInst(inst) && isTradableDef(def);
}

function petBlocked(inst) {
  return !!(inst?.pet?.active || inst?.pet?.inv?.length);
}

/** Player trade / char-trade payment offer. */
export function canTradeOffer(def, inst, now) {
  return !!def
    && !isBoundInst(inst)
    && isTradableDef(def)
    && !isExpiredInst(inst, now)
    && !petBlocked(inst);
}

/** Mail attachment: also refuses any period/timed def (even before expiresAt is set). */
export function canMailAttachment(def, inst) {
  return !!def
    && !isBoundInst(inst)
    && isTradableDef(def)
    && !inst?.expiresAt
    && !hasPeriod(def)
    && !petBlocked(inst);
}

/** Consignment register: same as mail for bind/trade/period/pet. */
export function canConsignItem(def, inst) {
  return canMailAttachment(def, inst);
}

/** Personal shop listing. */
export function canPcShopList(def, inst, now) {
  return !!def
    && !isBoundInst(inst)
    && isTradableDef(def)
    && !isExpiredInst(inst, now);
}

/**
 * NPC buyback/sell: refuses timed defs, npcSell=0, and bound==='nosell' sentinel.
 * Matches server/world/shops.mjs sell gate.
 */
export function canNpcSell(def, inst) {
  return !!def
    && Number(def.npcSell) !== 0
    && !inst?.expiresAt
    && !hasPeriod(def)
    && inst?.bound !== 'nosell';
}

/** Snapshot of resolved flags for docs/tests (after ItemDB.def merge). */
export function readFlags(def) {
  if (!def) return null;
  return {
    trade: Number(def.trade) || 0,
    belong: Number(def.belong) || 0,
    periodBreak: Number(def.periodBreak) || 0,
    period: Number(def.period) || 0,
    stack: Number(def.stack) || 0,
    maxStack: Number(def.maxStack) || 0,
    autoStack: Number(def.autoStack) || 0,
    npcSell: Number(def.npcSell) || 0,
    sell: Number(def.sell) || 0,
    price: Number(def.price) || 0,
    cash: Number(def.cash) || 0,
    classMask: Number(def.classMask) || 0,
    reqLv: Number(def.reqLv) || 0,
    maxLv: Number(def.maxLv) || 0,
    reqStr: Number(def.reqStr) || 0,
    reqDex: Number(def.reqDex) || 0,
    reqSpr: Number(def.reqSpr) || 0,
    reqGrade: Number(def.reqGrade) || 0,
    attribute: Number(def.attribute) || 0,
    group: Number(def.group) || 0,
    stackLimit: stackLimit(def),
    maxStackNumber: maxStackNumber(def),
    bindsOnPickup: bindsOnPickup(def),
    destroysOnExpiry: destroysOnExpiry(def),
    tradable: isTradableDef(def),
    npcSellable: isNpcSellableDef(def),
    stackable: isStackable(def),
    discardable: canDiscardDef(def),
    isAutoStack: isAutoStackDef(def),
    /** belong=2 is not bind-on-pickup; positive meaning still UNRESOLVED. */
    belong2NotBindOnPickup: belongValue(def) === 2,
    maxStackUnresolvedForMerge: true,
    autoStackUnresolvedForMergeGate: true,
  };
}
