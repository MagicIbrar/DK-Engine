// Global result code -> server Attack Result class (MATH-VERIFY row 7c).
// Source: DekaronServer.exe result factory 0x58a15d..0x58ad01. Each entry is `call <ctor>` (the ctor stores the class
// vtable) followed by `mov dword [eax], <code>`. The class names come from the RTTI of each vtable, and each class's
// calculator slot comes from math-re/calc-slot-map.txt (Calculator Provider [0xe4f6ac], vt 0x9fef84).
// The full dump is math-re/r7/result-code-class.txt. Damage codes missing from this table (for example 1000107,
// 1000117, 1000212, 1000213, 1000311, 1000312, 1000420, 1000701) have NO registration in the server factory, so their
// Global class is UNPROVEN. Callers keep their old decode for those codes and flag them.
export const GLOBAL_ATTACK_CLASS = Object.freeze({
  1000101: 'Melee@Single', 1000102: 'MeleeFar@Single', 1000103: 'Range@Single', 1000105: 'MagicMelee@Single',
  1000106: 'RangeMelee@Single', 1000112: 'FireFar@Single', 1000113: 'IceFar@Single', 1000114: 'LightningFar@Single',
  1000115: 'PoisonFar@Single', 1000116: 'CurseFar@Single',
  1000411: 'IceFar@Single', 1000412: 'PoisonFar@Single', 1000413: 'CurseFar@Single', 1000414: 'MeleeFar@Single',
  1000415: 'Range@Single', 1000416: 'FireFar@Single', 1000417: 'LightningFar@Single', 1000418: 'KnockBackMelee@Single',
  1000419: 'StunMelee@Single',
  1000201: 'Melee@Area', 1000202: 'Melee@Area', 1000203: 'MagicMelee@Area', 1000204: 'MagicMelee@Area',
  1000210: 'Range@Area', 1000211: 'Range@Area',
  1000301: 'Fire@Area', 1000302: 'Fire@Area', 1000303: 'Ice@Area', 1000304: 'Ice@Area', 1000305: 'Lightning@Area',
  1000306: 'Lightning@Area', 1000307: 'Poison@Area', 1000308: 'Poison@Area', 1000309: 'Curse@Area', 1000310: 'Curse@Area',
  1000512: 'Ice@Area', 1000513: 'KnockBackMelee@Area', 1000514: 'KnockBackMelee@Area', 1000515: 'StunMelee@Area',
  1000516: 'StunMelee@Area', 1000601: 'MaxDamage@Area',
});

// Class family -> Calculator Provider slot / function (calc-slot-map.txt) and the engine damage class + element.
// Melee 0x599660 (+4), MagicMelee 0x59a1d0 (+8), RangeMelee 0x597bc0 (+0xc), Range 0x5985a0 (+0x10),
// Fire 0x59b6f0 (+0x14), Ice 0x59aff0 (+0x18), Lightning 0x59a8f0 (+0x1c), Curse 0x59bda0 (+0x20),
// Poison 0x598f60 (+0x24), KnockBackMelee 0x597210 (+0x28), StunMelee 0x59ca40 (+0x38), MaxDamage = +4 then +8.
const FAMILY = {
  Melee: { cls: 'melee', calc: 0x599660 }, MeleeFar: { cls: 'melee', calc: 0x599660 },
  KnockBackMelee: { cls: 'melee', calc: 0x597210 }, StunMelee: { cls: 'melee', calc: 0x59ca40 },
  MaxDamage: { cls: 'melee', calc: 0x599660 }, MagicMelee: { cls: 'magic', calc: 0x59a1d0 },
  Range: { cls: 'range', calc: 0x5985a0 }, RangeMelee: { cls: 'range', calc: 0x597bc0 },
  Fire: { cls: 'magic', element: 'fire', calc: 0x59b6f0 }, FireFar: { cls: 'magic', element: 'fire', calc: 0x59b6f0 },
  Ice: { cls: 'magic', element: 'ice', calc: 0x59aff0 }, IceFar: { cls: 'magic', element: 'ice', calc: 0x59aff0 },
  Lightning: { cls: 'magic', element: 'lightning', calc: 0x59a8f0 }, LightningFar: { cls: 'magic', element: 'lightning', calc: 0x59a8f0 },
  Poison: { cls: 'magic', element: 'poison', calc: 0x598f60 }, PoisonFar: { cls: 'magic', element: 'poison', calc: 0x598f60 },
  Curse: { cls: 'magic', element: 'curse', calc: 0x59bda0 }, CurseFar: { cls: 'magic', element: 'curse', calc: 0x59bda0 },
};

/** { attackClass, cls, element?, calc } for a registered Global damage code, otherwise null (UNPROVEN code). */
export function globalAttackClass(code) {
  const name = GLOBAL_ATTACK_CLASS[Number(code)];
  if (!name) return null;
  const f = FAMILY[name.split('@')[0]];
  return f ? { attackClass: name, ...f } : null;
}
