# A2 world crash in Loa Castle (about 60 s after entering, "when a monster appears")

**Status: root cause confirmed** by the client's own crash dump and the packet capture (2026-10-29, all times PT). Fix is **staged, not applied**.

## TL;DR
The HellSpider A2 server spawns monster **index 3510 ("Akris", shape `Event_Mob01`)** in Loa Castle. The 2007 client's `monster.csv` stops before that range and has no row for it. When the server sends `MONSTER_APPEAR 0x05040000` with index 3510, the client looks the index up in its monster table, gets NULL, and calls a virtual method on that NULL. The result is an access violation at `0x00632544` and the game closes. **Emily (NPC 727) is not the cause.** The player talked to her 30 s earlier with no problem; the crash just happens near her spawn point.

## Evidence
### 1. Client crash dump (`2Moons/bin/userdump.dmp`, written 22:24:00.16 PT)
- Exception `0xC0000005` (access violation), **read of address 0x0**, EIP **0x00632544**, EAX = 0.
- EIP is inside `FUN_00632530` (`decompiled-source/a2-2moons-2007/dekaron_00630000.c:2121`):
  ```c
  piVar1 = (int *)(**(code **)(*DAT_00b5a75c + 8))(*(undefined2 *)(in_ECX + 0xb2)); // table->Get(monsterIndex)
  (**(code **)(*piVar1 + 4))();                                                     // no NULL check -> crash
  ```
- `DAT_00b5a75c` is the **monster template table**. The GM command `callmonster` (`dekaron_00510000.c:12880`) uses the same `Get(index)` and *does* NULL-check it before printing "call %u monster".
- Stack (return addresses in the dump): `FUN_0052a2b0` ← `FUN_00527d40` ← `FUN_00515030` (actor construction) ← `FUN_005f6290` ← `FUN_00633c40` ← `FUN_005394f0` … ← main loop `FUN_004581a0`.
- `userdump.info`: "Crash Tick 1111876". The `EXIT=0` line in the terminal comes from the wine wrapper, not the game.

### 2. Packet capture (`game.pcap`, client ⇄ channel 7881)
| time (PT) | packet | note |
|---|---|---|
| 22:22:58 | C>S `0x050d0007` ENTER_WORLD, map 7 | Loa Castle |
| 22:23:25 | S>C `0x05050000` NPC_APPEAR idx 727 (Emily) → `0x05050001/2/3`, `0x050a` shop | talked to Emily, **no crash** |
| 22:23:53 | S>C 3× `0x05040000` idx 701 (Blaverus) | **no crash** (701 is in the client table) |
| 22:23:57.03 | S>C 5× idx 701 **+ 1× idx 3510** (obj 0x10001266, HP 1079) → `0x050d0005` OBJECTS_DISAPPEAR → `0x050d0004` MONSTER_CONTROL ×6 | last packet the client acknowledged |
| 22:24:00.16 | crash dump written | |
| 22:24:00.23 | client TCP FIN | process gone |

### 3. Table mismatch
- Server `share/creature/monster.csv` has 824 rows; the client pak `share/creature/monster.csv` has 754. **71 indices exist only on the server**: 2064, 2070–2074, 3510–3523 (Akris event mobs, `Event_Mob*`) and 3600–3730 (later content). The client pak has no `Event_Mob*` mesh either.
- Loa Castle `share/map/07_loa_castle/mon_07_loa_castle.csv` lines **458–490**: 33 spawn rows of 3510 (e.g. `3510,2700,262,80`).
- The same problem will hit **16 other maps**: 00 Braiken, 01 North Ares, 02 Norak, 03 Deneb, 05 Haihaff, 06 Parca, 08 North Morte, 10 Castor, 11 Crevasse, 12 Crespo, 14 Norak 2nd, 15 Castor 2nd, 17 Requies, 27/28 Conscript. Maps 46 and 47 are entirely later content and are not in the 2007 client.
- NPC check: every Loa Castle NPC is known to the client. Server-only NPC ids are placed in maps 08 (811–814), 26 (1711), 27/28 (2605–2615), 46 (3300–3305) and 47 (3401–3406). They will probably crash the same way through the NPC table there (INFERRED, not tested).

## Fix (staged in `a2-crash-fix/`, NOT applied)
- `make_staged.py` builds filtered copies of every `mon_*.csv`, dropping rows whose monster index is missing from the client table. Result: 848 rows across 16 maps (Loa Castle 490 → 457 rows). Maps 46/47 are left alone because every row there is later content. Output is in `staged/`, with per-file detail in `staged/REPORT.json`.
- `apply.sh SERVER_DIR` copies them in and keeps `<file>.orig` (never overwrites an existing .orig). `revert.sh SERVER_DIR` restores them.
- It only takes effect after an **A2 channel/game server restart**. It was not applied because that restart would drop anyone else on the live server.
- Option B (server-side, no data loss): give the client the missing rows/assets. That's a bigger job: it needs the Event_Mob meshes and a client pak rebuild.
- Option C (bridge/dashboard): filter `0x05040000` where the u16 at +0x14 is not in the client's monster table, and filter `0x05050000` where the u16 at +0x14 is not in its NPC table.

## How to verify after applying
Enter Loa Castle and stay more than 2 minutes near Emily. In the capture, no `0x05040000` should carry an index ≥ 3510, and no new `userdump.dmp` should appear.
