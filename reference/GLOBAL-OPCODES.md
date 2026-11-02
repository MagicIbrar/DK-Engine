# Global 0.0.1: every opcode, explained

Client: Global 0.0.1 `dekaron.exe` (SHA256 a0f0bddd…7cec). Source of truth: the decompiled client in `decompiled-source/global-0.0.1/` (Ghidra pseudocode; 96,011 functions).
Evidence labels used: **decompile** (read directly from the decompiled source), **Global** (engine-bridge layouts validated on live Global 43.3.0 traffic, and observed 43.3.0-era packets). No online sources were needed or used. Anything reasoned rather than read is marked INFERRED.
The Global binary itself is packed, so every opcode comes from the decompile. Nothing here was wire-tested against 0.0.1.

## Wire basics

- Header: 16 bytes big-endian: +0 u32 ~crc32(enc[4:]) | +4 u16 seq | +6 u16 total size | +8 u32 tick/context | +0xC u32 opcode. Body little-endian.
- Cipher: enc[i]=p[i]^(CRC32TABLE[i&0xff]&0xff)^key for i>=4; key 0x0F until CON_ACK 0x00020081, then key0^key1 from it.

## Counts

| status | count | meaning |
|---|---|---|
| explained | 131 | purpose from decompile strings/Global traffic/bridge notes (not family-level guess) AND at least part of the layout (or empty body) known |
| partial_layout | 1003 | handler/builder located and some field offsets/types read from the decompile, but purpose is only family-level INFERRED |
| located_only | 559 | handler/builder located in the decompile with a file:line ref, but no field reads recovered and purpose family-level INFERRED |
| minimal | 0 | opcode and direction only |
| **total** | **1693** | |

Direction: S>C 1084, C>S 562, both 47

Columns: **layout** offsets count from the start of the 16-byte header (body begins at +10). Anything not listed is unknown and was not guessed. **ref** is `file:line` in the decompiled source (folder 3). Full detail (every handler, builder, debug string and evidence label) is in the JSON twin.

## 0x0001 — Session/internal

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x00010002` | INTERNAL_CONNECTED | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown | internal connected event (not on the wire) | decompiled-source/global-0.0.1/decompiled-named.c:340052 | explained |

## 0x0002 — Session

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x00020005` | SESSION_ACK | C>S | +10 ushort unknown | sequenced-packet ack, body u16be seq (FUN_009149e0) | decompiled-source/global-0.0.1/decompiled-named.c:341110 | explained |
| `0x00020080` | CON | C>S | +10 ptr/copy unknown | client hello; body u32be clientTick (session+0x2c); size 0x14; sent under initial key | decompiled-source/global-0.0.1/decompiled-named.c:340193 | explained |
| `0x00020081` | CON_ACK | S>C | unknown | server hello; FUN_00912da0 reads key bytes @0x18,@0x1c (cipher key = lo^hi), 64-byte passport @0x20..0x5f, ticks @0x10/@0x14 (byteswapped) | decompiled-source/global-0.0.1/decompiled-named.c:339926 | located_only |
| `0x00020082` | CON_CONFIRM | C>S | +10 ptr/copy unknown | client echoes serverTick (FUN_00912f70) under the new key | decompiled-source/global-0.0.1/decompiled-named.c:340084 | explained |
| `0x00020083` | PING | both | +10 ptr/copy unknown | keep-alive ping, body u32be tick; both directions | decompiled-source/global-0.0.1/decompiled-named.c:339539<br>decompiled-source/global-0.0.1/decompiled-named.c:339654 | explained |
| `0x00020084` | PONG | both | +10 ptr/copy unknown | ping echo, body u32be tick; both directions | decompiled-source/global-0.0.1/decompiled-named.c:339592<br>decompiled-source/global-0.0.1/decompiled-named.c:339729 | explained |

## 0x0204 — Character object (PC_OBJECT / LoadInfo)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x02040000` | PC_OBJECT | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 ptr unknown | character load record: 8 bytes then LoadInfo @0x18 (LoadInfo is byte-swapped field by field -> big-endian); handler FUN_008762a0 logs "ExecCmd::Lock InfoPacket mapIdx" | decompiled-source/global-0.0.1/decompiled-named.c:206760<br>decompiled-source/global-0.0.1/decompiled-named.c:2111359<br>decompiled-source/global-0.0.1/decompiled-named.c:235511 | explained |
| `0x02040001` | CHARACTER_OBJECT_PC_OBJECT_0204_0001 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235686 | partial_layout |
| `0x02040002` | CHARACTER_OBJECT_PC_OBJECT_0204_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235659 | partial_layout |
| `0x02040003` | CHARACTER_OBJECT_PC_OBJECT_0204_0003 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235713 | partial_layout |
| `0x0204000f` | CHARACTER_OBJECT_PC_OBJECT_0204_000F *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235821 | partial_layout |
| `0x02040010` | CHARACTER_OBJECT_PC_OBJECT_0204_0010 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235848 | partial_layout |
| `0x02040011` | CHARACTER_OBJECT_PC_OBJECT_0204_0011 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235875 | partial_layout |
| `0x02040012` | CHARACTER_OBJECT_PC_OBJECT_0204_0012 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235902 | partial_layout |
| `0x02040013` | CHARACTER_OBJECT_PC_OBJECT_0204_0013 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 ptr unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2252076<br>decompiled-source/global-0.0.1/decompiled-named.c:235794 | partial_layout |
| `0x02040015` | CHARACTER_OBJECT_PC_OBJECT_0204_0015 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236278 | partial_layout |
| `0x02040019` | CHARACTER_OBJECT_PC_OBJECT_0204_0019 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236416 | partial_layout |
| `0x0204001d` | CHARACTER_OBJECT_PC_OBJECT_0204_001D *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236443 | partial_layout |
| `0x02040024` | CHARACTER_OBJECT_PC_OBJECT_0204_0024 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236302 | partial_layout |
| `0x02040025` | CHARACTER_OBJECT_PC_OBJECT_0204_0025 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236335 | partial_layout |
| `0x02040026` | CHARACTER_OBJECT_PC_OBJECT_0204_0026 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236362 | partial_layout |
| `0x02040027` | CHARACTER_OBJECT_PC_OBJECT_0204_0027 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236389 | partial_layout |
| `0x02040029` | CHARACTER_OBJECT_PC_OBJECT_0204_0029 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236520 | partial_layout |
| `0x0204002a` | CHARACTER_OBJECT_PC_OBJECT_0204_002A *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235956 | partial_layout |
| `0x0204002b` | CHARACTER_OBJECT_PC_OBJECT_0204_002B *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235740 | partial_layout |
| `0x0204002e` | CHARACTER_OBJECT_PC_OBJECT_0204_002E *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236547 | partial_layout |
| `0x02040036` | CHARACTER_OBJECT_PC_OBJECT_0204_0036 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236470 | partial_layout |
| `0x02040038` | CHARACTER_OBJECT_PC_OBJECT_0204_0038 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236495 | partial_layout |
| `0x02040039` | CHARACTER_OBJECT_PC_OBJECT_0204_0039 *(label)* | S>C | +18 ptr unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2153702 | partial_layout |
| `0x0204003a` | CHARACTER_OBJECT_PC_OBJECT_0204_003A *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235929 | partial_layout |
| `0x02040040` | CHARACTER_OBJECT_PC_OBJECT_0204_0040 *(label)* | S>C | +18 ptr unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1952405 | partial_layout |
| `0x02040041` | CHARACTER_OBJECT_PC_OBJECT_0204_0041 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236571 | partial_layout |
| `0x02040042` | CHARACTER_OBJECT_PC_OBJECT_0204_0042 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236596 | partial_layout |
| `0x02040044` | CHARACTER_OBJECT_PC_OBJECT_0204_0044 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236621 | partial_layout |
| `0x0204004a` | CHARACTER_OBJECT_PC_OBJECT_0204_004A *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236646 | partial_layout |
| `0x0204004d` | CHARACTER_OBJECT_PC_OBJECT_0204_004D *(label)* | S>C | +54 int unknown; +58 int unknown; +60 uint unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3271259 | partial_layout |
| `0x0204004e` | CHARACTER_OBJECT_PC_OBJECT_0204_004E *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 ptr unknown | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111526<br>decompiled-source/global-0.0.1/decompiled-named.c:235767 | partial_layout |

## 0x0206 — Character list (PCLIST)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x02060000` | PCLIST_REQ | C>S | +10 undefined4 unknown | character list request, size 0x18: u32 @0x10 (account value) | decompiled-source/global-0.0.1/decompiled-named.c:206715 | explained |
| `0x02060001` | PCLIST_ACK | S>C | unknown | character list begin | decompiled-source/global-0.0.1/decompiled-named.c:2110568<br>decompiled-source/global-0.0.1/decompiled-named.c:3235549 | located_only |
| `0x02060002` | PCLIST_NAME | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +54 int unknown; +58 int unknown | next listed character name (login) / own PC name (game server) | decompiled-source/global-0.0.1/decompiled-named.c:206855<br>decompiled-source/global-0.0.1/decompiled-named.c:2111415<br>decompiled-source/global-0.0.1/decompiled-named.c:235601 | explained |
| `0x02060003` | PCLIST_END | S>C | unknown | end of list; client builds character select UI (max 6) | decompiled-source/global-0.0.1/decompiled-named.c:2110568<br>decompiled-source/global-0.0.1/decompiled-named.c:3235549 | located_only |
| `0x02060005` | CHARACTER_LIST_PCLIST_0206_0005 *(label)* | S>C | unknown | Character list (PCLIST): reply/notification. Character list request and list framing (begin / name / end). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3235549 | located_only |

## 0x0207 — Character object (misc)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x02070002` | MAIL_ITEMLESS_INBOX_LIST_READ_DIL_DELETE_0207_0002 *(label)* | S>C | +18 ptr unknown | Character object (misc): reply/notification. Character-related notice. Prior-build note (43.3.0, INFERRED for 0.0.1): S070: S>C 0x02070002 at packet+0x18. All multibyte scalar stream values BE; *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097441 | partial_layout |

## 0x020d — Character object (misc)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x020d000c` | CHARACTER_OBJECT_MISC_020D_000C *(label)* | S>C | unknown | Character object (misc): reply/notification. Character-related notice during login/enter. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111433 | located_only |
| `0x020d000d` | CHARACTER_OBJECT_MISC_020D_000D *(label)* | S>C | unknown | Character object (misc): reply/notification. Character-related notice during login/enter. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110568 | located_only |

## 0x0300 — Login

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x03000000` | LOGIN (legacy id/pw) | C>S | unknown | factory only in 0.0.1 (size 100); legacy id/pw login variant | decompiled-source/global-0.0.1/decompiled-named.c:234522 | located_only |
| `0x03000001` | LOGIN_ACK | S>C | +5c undefined4 unknown; +60 undefined2 unknown; +62 undefined2 unknown | login result; dispatcher FUN_00872dd0 -> FUN_008731b0 "Rev Login Packet"; 43.3.0 layout: u32 userNo@0x10, i32 result@0x14 (0 ok), u32 sessionKey@0x18, name@0x1c | decompiled-source/global-0.0.1/decompiled-named.c:233564 | explained |
| `0x03000002` | LOGOUT | C>S | empty body | header only (size 0x10) | decompiled-source/global-0.0.1/decompiled-named.c:234018<br>decompiled-source/global-0.0.1/decompiled-named.c:234538<br>decompiled-source/global-0.0.1/decompiled-named.c:237605 | explained |
| `0x03000003` | LOGOUT_ACK | S>C | unknown | Login: reply/notification. Account login (VL launcher login, legacy id/pw variants), logout, second password. Likely reply to C>S 0x03000002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2841046 | located_only |
| `0x03000004` | LOGIN_V4 | C>S | unknown | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:234442 | located_only |
| `0x03000011` | LOGIN_0011 | S>C | +10 char unknown; +13 char unknown; +16 char unknown | login-scene packet; handler FUN_00872ef0 reads three 3-char strings @0x10/@0x13/@0x16 (pairs with C>S 0x03000012 version/region triple) | decompiled-source/global-0.0.1/decompiled-named.c:233480 | explained |
| `0x03000012` | LOGIN_0012 | C>S | +10 ptr/copy unknown; +13 ptr/copy unknown; +16 ptr/copy unknown | three 3-byte strings @0x10/@0x13/@0x16 (client version/locale triple), size 0x1c | decompiled-source/global-0.0.1/decompiled-named.c:233258 | explained |
| `0x03000014` | LOGIN_0300_0014 *(label)* | C>S | unknown | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:234458 | located_only |
| `0x03000015` | LOGIN_0300_0015 *(label)* | S>C | +54 int unknown; +58 int unknown; +114 int unknown; +118 int unknown | Login: reply/notification. Account login (VL launcher login, legacy id/pw variants), logout, second password. Likely reply to C>S 0x03000014 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:233785 | partial_layout |
| `0x03000018` | LOGIN_0300_0018 *(label)* | C>S | unknown | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:234426 | located_only |
| `0x0300001e` | LOGIN_0300_001E *(label)* | C>S | unknown | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:234474 | located_only |
| `0x0300001f` | VL_LOGIN | C>S | unknown | launcher (VL) login, size 0x310: char a[256]@0x10, b[256]@0x110, c[256]@0x210 (from launcher args; empty without launcher) | decompiled-source/global-0.0.1/decompiled-named.c:234490 | located_only |
| `0x03000020` | SECONDPW_OPEN | S>C | +5c undefined4 unknown | second password prompt: u8 mode @0x10 (1 enter, 2 register) | decompiled-source/global-0.0.1/decompiled-named.c:233816 | explained |
| `0x03000021` | SECONDPW_VERIFY | C>S | unknown | second password verify (size 0x54) | decompiled-source/global-0.0.1/decompiled-named.c:3282120 | located_only |
| `0x03000022` | SECONDPW_VERIFY_ACK | S>C | +10 int unknown; +14 undefined4 unknown | second password verify result | decompiled-source/global-0.0.1/decompiled-named.c:233890 | explained |
| `0x03000025` | SECONDPW_SET | C>S | unknown | second password set (size 0x54) | decompiled-source/global-0.0.1/decompiled-named.c:3282135 | located_only |
| `0x03000026` | SECONDPW_SET_ACK | S>C | +10 undefined4 unknown | second password set result | decompiled-source/global-0.0.1/decompiled-named.c:234161 | explained |
| `0x03000028` | SECONDPW_CHANGE | C>S | unknown | second password change (size 0x94) | decompiled-source/global-0.0.1/decompiled-named.c:3282150 | located_only |
| `0x03000029` | SECONDPW_CHANGE_ACK | S>C | unknown | second password change result | decompiled-source/global-0.0.1/decompiled-named.c:234018 | located_only |
| `0x0300002a` | LOGIN_0300_002A *(label)* | S>C | unknown | Login: reply/notification. Account login (VL launcher login, legacy id/pw variants), logout, second password. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:233439 | located_only |
| `0x03000030` | LOGIN_0300_0030 *(label)* | C>S | unknown | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:234506 | located_only |

## 0x0301 — Login server Checkout/Checkin

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x03010000` | CHECKOUT | C>S | unknown | select character, leave login server (Connect::State::Command::Checkout, "Send Check Out"); size 0x3c; wchar name[21]@0x10 | decompiled-source/global-0.0.1/decompiled-named.c:234909 | located_only |
| `0x03010001` | CHECKOUT_ACK | S>C | unknown | checkout result: i32 result@0x10, then game-server ticket/address | decompiled-source/global-0.0.1/decompiled-named.c:2840857 | located_only |
| `0x03010002` | CHECKIN | C>S | +10 int unknown; +14 int unknown; +18 int unknown; +46 undefined1 unknown | return to login server (Connect::State::Command::Checkin), size 0x5c: u32 userNo@0x10, u32 sessionKey@0x14, u32 ticket@0x18, wchar name[21]@0x1c, account@0x46 | decompiled-source/global-0.0.1/decompiled-named.c:237749 | explained |
| `0x03010003` | CHECKIN_ACK | S>C | unknown | checkin result i32@0x10 | decompiled-source/global-0.0.1/decompiled-named.c:2841078 | located_only |
| `0x03010004` | LOGIN_SERVER_CHECKOUT_0301_0004 *(label)* | C>S | empty body | Login server Checkout/Checkin: request. Leave login server with selected character (Checkout), or return to login server (Checkin). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:210313 | partial_layout |
| `0x03010005` | LOGIN_SERVER_CHECKOUT_0301_0005 *(label)* | S>C | +10 undefined4 unknown | Login server Checkout/Checkin: reply/notification. Leave login server with selected character (Checkout), or return to login server (Checkin). Likely reply to C>S 0x03010004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:208685<br>decompiled-source/global-0.0.1/decompiled-named.c:212616 | partial_layout |

## 0x0302 — Character create/delete + ServerTransfer

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x03020000` | CHAR_CREATE | C>S | +3a undefined1 unknown; +3b undefined1 unknown; +3c undefined4 unknown | size 0x40: wchar name[21]@0x10, u8 class@0x3a | decompiled-source/global-0.0.1/decompiled-named.c:212637 | explained |
| `0x03020001` | CHAR_CREATE_ACK | S>C | unknown | i32 result@0x10 | decompiled-source/global-0.0.1/decompiled-named.c:212616 | located_only |
| `0x03020002` | CHAR_DELETE | C>S | unknown | size 0x3c: wchar name[21]@0x10 | decompiled-source/global-0.0.1/decompiled-named.c:856038<br>decompiled-source/global-0.0.1/decompiled-named.c:856274 | located_only |
| `0x03020003` | CHAR_DELETE_ACK | S>C | +18 undefined4 unknown; +1c undefined4 unknown; +6c undefined1 unknown; +8c int unknown | i32 result; on success client re-requests PCLIST | decompiled-source/global-0.0.1/decompiled-named.c:207041 | explained |
| `0x03020004` | CHARACTER_CREATE_0302_0004 *(label)* | C>S | +10 ptr/copy unknown; +3a ptr/copy unknown; +65 undefined1 unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3170405 | partial_layout |
| `0x03020005` | CHARACTER_CREATE_0302_0005 *(label)* | S>C | unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263973 | located_only |
| `0x03020006` | CHARACTER_CREATE_0302_0006 *(label)* | C>S | unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2079351 | located_only |
| `0x03020007` | CHARACTER_CREATE_0302_0007 *(label)* | S>C | unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263973 | located_only |
| `0x03020008` | CHARACTER_CREATE_0302_0008 *(label)* | C>S | +10 undefined2 unknown; +65 undefined1 unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2079383 | partial_layout |
| `0x03020009` | CHARACTER_CREATE_0302_0009 *(label)* | S>C | unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263973 | located_only |
| `0x0302000a` | CHARACTER_CREATE_0302_000A *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +3e undefined2 unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2079447 | partial_layout |
| `0x0302000b` | CHARACTER_CREATE_0302_000B *(label)* | S>C | +10 int unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x0302000a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2079617 | partial_layout |
| `0x0302000d` | CHARACTER_CREATE_0302_000D *(label)* | S>C | unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:206894 | located_only |
| `0x03020016` | CHARACTER_CREATE_0302_0016 *(label)* | C>S | unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:856038 | located_only |
| `0x03020017` | CHARACTER_CREATE_0302_0017 *(label)* | S>C | +18 uint unknown; +54 int unknown; +58 int unknown; +6d byte unknown; +8c int unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020016 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:207193 | partial_layout |
| `0x03020018` | CHARACTER_CREATE_0302_0018 *(label)* | C>S | unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3280104 | located_only |
| `0x03020019` | CHARACTER_CREATE_0302_0019 *(label)* | S>C | +18 uint unknown; +54 int unknown; +58 int unknown; +6d byte unknown; +8c int unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020018 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:207320 | partial_layout |

## 0x0400 — World server Lock / WaitEnter

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x04000000` | LOCK | C>S | +10 int unknown; +14 int unknown; +18 int unknown; +1c undefined1 unknown; +154 int unknown; +158 int unknown | enter game server, size 0x15c: u32 sessionKey@0x10, u32 userNo@0x14, u32 ticket@0x18, userId@0x1c, extra u32 @0x154/@0x158 (Connect::State::Command::Lock) | decompiled-source/global-0.0.1/decompiled-named.c:235247 | explained |
| `0x04000002` | LOCK_ACK_START | S>C | +10 undefined4 unknown; +14 undefined2 unknown; +16 short unknown | "Rev Lock Start": i32 result@0x10, u8 flags @0x14..0x16 | decompiled-source/global-0.0.1/decompiled-named.c:235467 | explained |
| `0x04000003` | LOCK_ACK_END | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +16 ushort unknown | "Rev Lock End": logs worldId/WorldIdx/ChannelIdx; u32 handle@0x10, u8 flag@0x14; needs own PC_OBJECT first | decompiled-source/global-0.0.1/decompiled-named.c:236076 | explained |
| `0x04000006` | UNLOCK | C>S | empty body | header only (Connect::State::Command::Unlock) | decompiled-source/global-0.0.1/decompiled-named.c:237934 | explained |
| `0x04000007` | WORLD_SERVER_LOCK_0400_0007 *(label)* | S>C | unknown | World server Lock / WaitEnter: reply/notification. Game-server lock (enter-world handshake), lock result, unlock, wait/queue notices. Likely reply to C>S 0x04000006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3235929 | located_only |
| `0x04000008` | WAIT_NOTICE | S>C | unknown | queue/wait notice during enter | decompiled-source/global-0.0.1/decompiled-named.c:236970<br>decompiled-source/global-0.0.1/decompiled-named.c:236998 | located_only |
| `0x04000015` | LOCK_0015 | S>C | +10 undefined4 unknown; +14 undefined4 unknown | enter-world dispatcher case | decompiled-source/global-0.0.1/decompiled-named.c:236037 | explained |
| `0x04000016` | WORLD_SERVER_LOCK_0400_0016 *(label)* | C>S | +10 undefined2 unknown; +14 ptr/copy unknown | World server Lock / WaitEnter: request. Game-server lock (enter-world handshake), lock result, unlock, wait/queue notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:803233 | partial_layout |
| `0x04000017` | WORLD_SERVER_LOCK_0400_0017 *(label)* | S>C | unknown | World server Lock / WaitEnter: reply/notification. Game-server lock (enter-world handshake), lock result, unlock, wait/queue notices. Likely reply to C>S 0x04000016 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2851248 | located_only |

## 0x0500 — Inventory / CashItem / RandomBox

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05000000` | INVENTORY_0500_0000 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined2 unknown; +16 undefined1 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1832062<br>decompiled-source/global-0.0.1/decompiled-named.c:2238242<br>decompiled-source/global-0.0.1/decompiled-named.c:3266517 | partial_layout |
| `0x05000001` | INVENTORY_0500_0001 *(label)* | S>C | +10 char unknown; +11 char unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1944185 | partial_layout |
| `0x05000002` | INVENTORY_0500_0002 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3150368<br>decompiled-source/global-0.0.1/decompiled-named.c:3150399<br>decompiled-source/global-0.0.1/decompiled-named.c:3163202 … | partial_layout |
| `0x05000003` | INVENTORY_0500_0003 *(label)* | S>C | +10 char unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1944289 | partial_layout |
| `0x05000004` | INVENTORY_0500_0004 *(label)* | S>C | +10 ptr unknown; +13 undefined4 unknown; +21 short unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945044 | partial_layout |
| `0x05000005` | INVENTORY_0500_0005 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945152 | partial_layout |
| `0x05000006` | INVENTORY_0500_0006 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945249 | partial_layout |
| `0x05000007` | INVENTORY_0500_0007 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945333 | partial_layout |
| `0x05000008` | INVENTORY_0500_0008 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3300992 | partial_layout |
| `0x05000009` | INVENTORY_0500_0009 *(label)* | S>C | +10 ptr unknown; +13 undefined1 unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037936 | partial_layout |
| `0x05000013` | CASHITEM_0500_0013 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined2 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05000013 rename, size 0x40 (builder 0x16f7f30): +0x00 ref3 item (getter +4/+6), +0x04 UTF-16LE new name ("%s" 0x1dd112c, max 0x15 wchars incl. NUL) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2035097 | partial_layout |
| `0x05000014` | CASHITEM_0500_0014 *(label)* | S>C | +10 undefined4 unknown; +14 ptr unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000013 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S019: S>C 0x05000014 result (dispatch 0x16fc900 -> 0x16ff640): +0x00 i32 result, +0x04 UTF-16LE name (read on success, handed to the name setter): *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038957 | partial_layout |
| `0x05000018` | RANDOMBOX_0500_0018 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined2 unknown; +16 undefined4 unknown; +1a undefined4 unknown; +1e undefined4 unknown; +22 undefined4 unknown; +26 undefined8 unknown; +2e undefined4 unknown; +32 undefined2 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05000018 selection box, size 0x34 (0x175a1b0): +0x00 u16 pos, +0x02 u8 container (box ref), +0x04 u16 (UNVERIFIED: chosen entry), *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2094891 | explained |
| `0x0500001b` | INVENTORY_0500_001B *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3163119 | partial_layout |
| `0x0500001c` | INVENTORY_0500_001C *(label)* | S>C | +10 ptr unknown; +13 undefined1 unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x0500001b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037985 | partial_layout |
| `0x0500001d` | INVENTORY_0500_001D *(label)* | S>C | +10 undefined4 unknown; +1e short unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +5c ptr unknown; +5f char unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946355 | partial_layout |
| `0x0500001e` | INVENTORY_0500_001E *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3171111 | partial_layout |
| `0x0500001f` | INVENTORY_0500_001F *(label)* | S>C | unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x0500001e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946485 | located_only |
| `0x05000020` | INVENTORY_0500_0020 *(label)* | S>C | unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946563 | located_only |
| `0x05000023` | INVENTORY_0500_0023 *(label)* | C>S | +10 undefined1 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3198490 | partial_layout |
| `0x05000024` | INVENTORY_0500_0024 *(label)* | S>C | +11 undefined1 unknown; +12 char unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000023 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946602 | partial_layout |
| `0x05000026` | INVENTORY_0500_0026 *(label)* | S>C | +14 int unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945420 | partial_layout |
| `0x05000027` | INVENTORY_0500_0027 *(label)* | C>S | empty body | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3150431 | partial_layout |
| `0x05000028` | INVENTORY_0500_0028 *(label)* | S>C | unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000027 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945450 | located_only |
| `0x05000029` | INVENTORY_0500_0029 *(label)* | C>S | unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2268281 | located_only |
| `0x05000030` | INVENTORY_0500_0030 *(label)* | S>C | +10 undefined3 unknown; +16 short unknown; +18 undefined4 unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1944111 | partial_layout |
| `0x05000031` | CASHITEM_0500_0031 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined2 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2036156 | partial_layout |
| `0x05000033` | CASHITEM_0500_0033 *(label)* | C>S | unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037100 | located_only |
| `0x05000034` | INVENTORY_0500_0034 *(label)* | S>C | unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000033 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3275869 | located_only |
| `0x05000035` | INVENTORY_0500_0035 *(label)* | S>C | +10 ptr unknown; +13 undefined4 unknown; +21 short unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946656 | partial_layout |
| `0x05000036` | INVENTORY_0500_0036 *(label)* | S>C | +10 ptr unknown; +13 undefined4 unknown; +21 short unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946769 | partial_layout |

## 0x0501 — Ornament / MainToolBar

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05010000` | ORNAMENT_0501_0000 *(label)* | C>S | +10 undefined4 unknown | Ornament / MainToolBar: request. Ornament and toolbar sync. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2064966<br>decompiled-source/global-0.0.1/decompiled-named.c:3261527 | partial_layout |
| `0x05010001` | ORNAMENT_0501_0001 *(label)* | S>C | +10 int unknown; +14 undefined4 unknown; +18 undefined3 unknown | Ornament / MainToolBar: reply/notification. Ornament and toolbar sync. Likely reply to C>S 0x05010000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1927667 | partial_layout |

## 0x0502 — CashItem / CashShop / game events

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05020000` | CASHITEM_0502_0000 *(label)* | S>C | +10 undefined4 unknown; +14 ushort unknown; +16 ushort unknown; +18 byte unknown; +1c undefined4 unknown; +24 undefined1 unknown; +28 undefined4 unknown; +2c char unknown; +68 undefined4 unknown; +6c float unknown; +70 undefined2 unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:309347 | partial_layout |
| `0x05020001` | CASHITEM_0502_0001 *(label)* | C>S | unknown | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2268721 | located_only |
| `0x05020002` | CASHITEM_0502_0002 *(label)* | S>C | +10 undefined1 unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1943670 | partial_layout |
| `0x05020003` | CASHITEM_0502_0003 *(label)* | C>S | +10 int unknown; +14 undefined1 unknown | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244025 | partial_layout |
| `0x05020004` | CASHITEM_0502_0004 *(label)* | S>C | +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +5c char unknown; +5d undefined1 unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1943445 | partial_layout |
| `0x05020006` | CASHITEM_0502_0006 *(label)* | S>C | +10 int unknown; +14 undefined1 unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1943754 | partial_layout |
| `0x05020007` | CASHITEM_0502_0007 *(label)* | C>S | empty body | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3169615<br>decompiled-source/global-0.0.1/decompiled-named.c:3188152 | partial_layout |
| `0x05020008` | CASHITEM_0502_0008 *(label)* | S>C | +10 undefined1 unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2078075 | partial_layout |
| `0x0502000b` | CASHITEM_0502_000B *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037064 | partial_layout |
| `0x0502000c` | CASHITEM_0502_000C *(label)* | S>C | +10 ptr unknown; +13 char unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x0502000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037638 | partial_layout |
| `0x0502000e` | CASHITEM_0502_000E *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined4 unknown | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2034993<br>decompiled-source/global-0.0.1/decompiled-named.c:2131109<br>decompiled-source/global-0.0.1/decompiled-named.c:248177 | partial_layout |
| `0x0502000f` | CASHITEM_0502_000F *(label)* | S>C | +10 ptr unknown; +13 undefined1 unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x0502000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037763 | partial_layout |
| `0x05020011` | CASHITEM_0502_0011 *(label)* | S>C | unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2078154 | located_only |
| `0x05020012` | CASHITEM_0502_0012 *(label)* | S>C | unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2851248 | located_only |
| `0x05020013` | CASHITEM_0502_0013 *(label)* | S>C | unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2851248 | located_only |
| `0x05020014` | CASHITEM_0502_0014 *(label)* | S>C | unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1943072 | located_only |

## 0x0503 — World enter / creature appear

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05030000` | WORLD_ENTER_0503_0000 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +18 undefined4 unknown; +1c undefined4 unknown | World enter / creature appear: request. Object enter (appear) records. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2268737 | partial_layout |
| `0x05030001` | WORLD_ENTER_0503_0001 *(label)* | S>C | +10 uint unknown; +14 int unknown; +18 char unknown | World enter / creature appear: reply/notification. Object enter (appear) records. Likely reply to C>S 0x05030000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1944017 | partial_layout |
| `0x05030002` | WORLD_ENTER_0503_0002 *(label)* | S>C | +10 undefined4 unknown; +14 ushort unknown; +16 ushort unknown; +18 byte unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 char unknown | World enter / creature appear: reply/notification. Object enter (appear) records. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:309447 | partial_layout |
| `0x05030003` | WORLD_ENTER_0503_0003 *(label)* | C>S | +10 undefined1 unknown; +14 undefined4 unknown | World enter / creature appear: request. Object enter (appear) records. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266490 | partial_layout |
| `0x05030004` | WORLD_ENTER_0503_0004 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 char unknown | World enter / creature appear: reply/notification. Object enter (appear) records. Likely reply to C>S 0x05030003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1943808 | partial_layout |

## 0x0504 — World enter / PC appear

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05040000` | PC_STATE | S>C | +10 undefined4 unknown; +14 undefined2 unknown; +20 int unknown; +24 ptr unknown; +33 byte unknown; +44 undefined4 unknown; +1b0 char unknown; +1b4 int unknown; +1b8 undefined4 unknown; +1bc undefined1 unknown | PC appear/state record (size 448) | decompiled-source/global-0.0.1/decompiled-named.c:197212<br>decompiled-source/global-0.0.1/decompiled-named.c:309509 | explained |

## 0x0505 — NPC dialog / Quest

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05050000` | NPC_OBJECT | both | +10 undefined4 unknown; +14 short unknown; +16 undefined4 unknown; +1a undefined2 unknown; +1c undefined1 unknown | NPC/object record (size 32) | decompiled-source/global-0.0.1/decompiled-named.c:197212<br>decompiled-source/global-0.0.1/decompiled-named.c:2223614<br>decompiled-source/global-0.0.1/decompiled-named.c:309684 | explained |
| `0x05050001` | NPCDIALOG_0505_0001 *(label)* | C>S | unknown | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: TalkNPC 0x05050001 -> 0x05050002 with all npc.csv job slots; choice 0x05050003 -> shop open (job 0/102) or the module claiming that job type; close 0x05050007. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:224001 | located_only |
| `0x05050002` | NPCDIALOG_0505_0002 *(label)* | S>C | unknown | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1908379 | located_only |
| `0x05050003` | NPCDIALOG_0505_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined1 unknown | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: TalkNPC 0x05050001 -> 0x05050002 with all npc.csv job slots; choice 0x05050003 -> shop open (job 0/102) or the module claiming that job type; close 0x05050007. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1908771<br>decompiled-source/global-0.0.1/decompiled-named.c:3197127 | partial_layout |
| `0x05050004` | NPC_DIALOG_0505_0004 *(label)* | S>C | unknown | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3260312 | located_only |
| `0x05050005` | NPC_DIALOG_0505_0005 *(label)* | C>S | +10 undefined4 unknown | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:284374<br>decompiled-source/global-0.0.1/decompiled-named.c:305141<br>decompiled-source/global-0.0.1/decompiled-named.c:3143242 | partial_layout |
| `0x05050006` | NPC_DIALOG_0505_0006 *(label)* | S>C | unknown | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3236575 | located_only |
| `0x05050007` | NPCDIALOG_0505_0007 *(label)* | C>S | empty body | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: TalkNPC 0x05050001 -> 0x05050002 with all npc.csv job slots; choice 0x05050003 -> shop open (job 0/102) or the module claiming that job type; close 0x05050007. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197102<br>decompiled-source/global-0.0.1/decompiled-named.c:3197152<br>decompiled-source/global-0.0.1/decompiled-named.c:3197207 … | partial_layout |
| `0x05050008` | NPC_DIALOG_0505_0008 *(label)* | S>C | unknown | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3260312 | partial_layout |
| `0x05050010` | NPC_DIALOG_0505_0010 *(label)* | S>C | unknown | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |

## 0x0506 — AutoHunt / GrowBless / Dekaron provider / DKSquare entry

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05060001` | AUTOHUNT_0506_0001 *(label)* | S>C | +10 char unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1925292 | partial_layout |
| `0x05060006` | AUTOHUNT_0506_0006 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x05060007` | AUTOHUNT_0506_0007 *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3238618 | partial_layout |
| `0x05060008` | AUTOHUNT_0506_0008 *(label)* | S>C | +10 char unknown; +24 undefined4 unknown; +28 undefined2 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:245512 | partial_layout |
| `0x05060009` | AUTOHUNT_0506_0009 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3140203 | located_only |
| `0x0506000a` | AUTOHUNT_0506_000A *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145347 | located_only |
| `0x0506000b` | AUTOHUNT_0506_000B *(label)* | C>S | +10 byte unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847510<br>decompiled-source/global-0.0.1/decompiled-named.c:3135076<br>decompiled-source/global-0.0.1/decompiled-named.c:3135522 | partial_layout |
| `0x0506000c` | AUTOHUNT_0506_000C *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1996322 | located_only |
| `0x0506000d` | AUTOHUNT_0506_000D *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1996500 | partial_layout |
| `0x0506000e` | AUTOHUNT_0506_000E *(label)* | S>C | +18 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1996360 | partial_layout |
| `0x0506000f` | AUTOHUNT_0506_000F *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3301132 | partial_layout |
| `0x05060010` | AUTOHUNT_0506_0010 *(label)* | S>C | +10 ptr unknown; +13 undefined1 unknown; +14 char unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037538 | partial_layout |
| `0x05060011` | PCINFO_0506_0011 *(label)* | C>S | +10 short unknown; +12 short unknown; +14 short unknown; +16 short unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05060011 (sender 0x16b8740, size 0x18; takes request lock 2 via [0x22c1070] vf+4, skipped when all four are 0): *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3155315 | partial_layout |
| `0x05060012` | PCINFO_0506_0012 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060011 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S077: S>C 0x05060012 (PCInfo switch 0x16b913a -> 0x16b9530): releases lock 2 (vf+8), u8 result @0x10; 0 = refresh the two stat UIs *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262573 | explained |
| `0x05060013` | CASHITEM_0506_0013 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3163079 | partial_layout |
| `0x05060014` | AUTOHUNT_0506_0014 *(label)* | S>C | +10 ptr unknown; +18 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037584 | partial_layout |
| `0x05060016` | AUTOHUNT_0506_0016 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262573 | located_only |
| `0x05060017` | AUTOHUNT_0506_0017 *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3238618 | partial_layout |
| `0x05060018` | AUTOHUNT_0506_0018 *(label)* | S>C | +10 char unknown; +12 undefined4 unknown; +16 undefined2 unknown; +18 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:245591 | partial_layout |
| `0x05060019` | AUTOHUNT_0506_0019 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262573 | located_only |
| `0x0506001a` | AUTOHUNT_0506_001A *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262573 | located_only |
| `0x0506001b` | AUTOHUNT_0506_001B *(label)* | C>S | +10 short unknown; +12 short unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1955654<br>decompiled-source/global-0.0.1/decompiled-named.c:3238652 | partial_layout |
| `0x0506001c` | AUTOHUNT_0506_001C *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506001b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261894 | located_only |
| `0x0506001d` | AUTOHUNT_0506_001D *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3280816 | partial_layout |
| `0x0506001e` | AUTOHUNT_0506_001E *(label)* | S>C | +10 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506001d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3236783 | partial_layout |
| `0x0506001f` | AUTOHUNT_0506_001F *(label)* | C>S | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3238667 | located_only |
| `0x05060020` | AUTOHUNT_0506_0020 *(label)* | S>C | +10 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506001f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3236753 | partial_layout |
| `0x05060023` | AUTOHUNT_0506_0023 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264852 | located_only |
| `0x05060024` | AUTOHUNT_0506_0024 *(label)* | C>S | +10 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3153401 | partial_layout |
| `0x05060025` | AUTOHUNT_0506_0025 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060024 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261894 | located_only |
| `0x05060026` | AUTOHUNT_0506_0026 *(label)* | C>S | +10 undefined4 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2154196<br>decompiled-source/global-0.0.1/decompiled-named.c:2223455 | partial_layout |
| `0x05060027` | AUTOHUNT_0506_0027 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060026 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3185733 | located_only |
| `0x05060029` | AUTOHUNT_0506_0029 *(label)* | C>S | +10 undefined2 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2155973 | partial_layout |
| `0x05060030` | AUTOHUNT_0506_0030 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3186110 | located_only |
| `0x05060031` | AUTOHUNT_0506_0031 *(label)* | S>C | +18 undefined4 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1996579 | partial_layout |
| `0x05060032` | AUTOHUNT_0506_0032 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): S013: S>C 0x05060032 (0x17953d0): u16 stamina @+0 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264659 | explained |
| `0x05060033` | AUTOHUNT_0506_0033 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264659 | located_only |
| `0x05060034` | AUTOHUNT_0506_0034 *(label)* | C>S | +10 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05060034 empty (0x1795270 / 0x1795620) = enable  -> S>C 0x05060035 (0x17954a0): u8 result @+0, u16 stamina @+2 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3180743 | explained |
| `0x05060035` | AUTOHUNT_0506_0035 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060034 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S013: C>S 0x05060034 empty (0x1795270 / 0x1795620) = enable  -> S>C 0x05060035 (0x17954a0): u8 result @+0, u16 stamina @+2 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264659 | explained |
| `0x05060036` | AUTOHUNT_0506_0036 *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05060036 empty (0x17952e0 / 0x1795650) = disable -> S>C 0x05060037 (no body read, case 0x1795393) map is allowed. UNVERIFIED: 0x05060036 -> 0x05060037 pairing, stamina scale. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3180770 | explained |
| `0x05060037` | AUTOHUNT_0506_0037 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060036 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S013: C>S 0x05060036 empty (0x17952e0 / 0x1795650) = disable -> S>C 0x05060037 (no body read, case 0x1795393) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264659 | explained |
| `0x05060038` | AUTOHUNT_0506_0038 *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1870184 | partial_layout |
| `0x05060039` | AUTOHUNT_0506_0039 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060038 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1997430 | located_only |
| `0x0506003a` | AUTOHUNT_0506_003A *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1870601<br>decompiled-source/global-0.0.1/decompiled-named.c:3138578 | partial_layout |
| `0x0506003e` | AUTOHUNT_0506_003E *(label)* | C>S | +10 ptr/copy unknown; +364 byte unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:106867 | partial_layout |
| `0x0506003f` | AUTOHUNT_0506_003F *(label)* | C>S | +10 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2830980 | partial_layout |
| `0x05060040` | AUTOHUNT_0506_0040 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506003f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x05060041` | AUTOHUNT_0506_0041 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262573 | located_only |
| `0x05060042` | AUTOHUNT_0506_0042 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262573 | located_only |

## 0x0507 — PC state

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05070000` | PC_STATE_0507_0000 *(label)* | S>C | unknown | PC state: reply/notification. PC state event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:197212<br>decompiled-source/global-0.0.1/decompiled-named.c:2850264 | located_only |

## 0x0508 — Creature/PC state

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05080000` | CREATURE_0508_0000 *(label)* | S>C | unknown | Creature/PC state: reply/notification. Creature/PC state events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:197212<br>decompiled-source/global-0.0.1/decompiled-named.c:3236810 | located_only |
| `0x05080001` | CREATURE_0508_0001 *(label)* | S>C | unknown | Creature/PC state: reply/notification. Creature/PC state events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x05080003` | CREATURE_0508_0003 *(label)* | S>C | unknown | Creature/PC state: reply/notification. Creature/PC state events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |

## 0x0509 — PK / Chaotic

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05090000` | PK_0509_0000 *(label)* | S>C | unknown | PK / Chaotic: reply/notification. PK mode and chaotic timer. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:197212<br>decompiled-source/global-0.0.1/decompiled-named.c:2850264 | located_only |
| `0x0509000a` | PK_0509_000A *(label)* | C>S | empty body | PK / Chaotic: request. PK mode and chaotic timer. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2848448 | partial_layout |
| `0x0509000b` | PK_0509_000B *(label)* | C>S | empty body | PK / Chaotic: request. PK mode and chaotic timer. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2848470 | partial_layout |
| `0x0509000c` | PK_0509_000C *(label)* | S>C | unknown | PK / Chaotic: reply/notification. PK mode and chaotic timer. Likely reply to C>S 0x0509000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3161906 | located_only |

## 0x050a — NPC Shop

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050a0000` | SHOP_050A_0000 *(label)* | S>C | +10 int unknown; +14 short unknown; +16 char unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1951124 | partial_layout |
| `0x050a0001` | SHOP_050A_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown; +18 undefined1 unknown; +19 undefined1 unknown | NPC Shop: request. NPC shop buy/sell/repair. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: open 0x050a0000 (sent by S069 on a SHOP/MULTISHOP job), buy 0x050a0001 -> 0x050a0002, bulk buy 0x050a0009 -> 0x050a0002 path, *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261804 | partial_layout |
| `0x050a0002` | SHOP_050A_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 char unknown; +19 byte unknown; +58 uint unknown; +5c undefined4 unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1951333 | partial_layout |
| `0x050a0003` | SHOP_050A_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown | NPC Shop: request. NPC shop buy/sell/repair. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: sell 0x050a0003 (sells the client's cursor item, tracked by S055) -> 0x050a0004. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3152466 | partial_layout |
| `0x050a0004` | SHOP_050A_0004 *(label)* | S>C | +10 undefined4 unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1951854 | partial_layout |
| `0x050a0005` | NPC_SHOP_050A_0005 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown; +18 undefined1 unknown | NPC Shop: request. NPC shop buy/sell/repair. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3152497 | partial_layout |
| `0x050a0006` | NPC_SHOP_050A_0006 *(label)* | S>C | +10 undefined4 unknown; +14 ptr unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1951983 | partial_layout |
| `0x050a0007` | NPC_SHOP_050A_0007 *(label)* | C>S | empty body | NPC Shop: request. NPC shop buy/sell/repair. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3152534 | partial_layout |
| `0x050a0008` | NPC_SHOP_050A_0008 *(label)* | S>C | unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1952077 | located_only |
| `0x050a0009` | SHOP_050A_0009 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown; +18 undefined1 unknown; +1a short unknown | NPC Shop: request. NPC shop buy/sell/repair. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: open 0x050a0000 (sent by S069 on a SHOP/MULTISHOP job), buy 0x050a0001 -> 0x050a0002, bulk buy 0x050a0009 -> 0x050a0002 path, *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3152384 | partial_layout |
| `0x050a000a` | NPC_SHOP_050A_000A *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 char unknown; +19 char unknown; +58 short unknown; +5c uint unknown; +60 undefined4 unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1951629 | partial_layout |
| `0x050a000b` | NPC_SHOP_050A_000B *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown; +18 undefined2 unknown; +1c undefined4 unknown | NPC Shop: request. NPC shop buy/sell/repair. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3152346 | partial_layout |
| `0x050a000c` | NPC_SHOP_050A_000C *(label)* | S>C | +10 char unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 char unknown; +5c int unknown; +60 short unknown; +68 undefined4 unknown; +6c undefined4 unknown; +70 undefined8 unknown; +78 undefined4 unknown; +7c ptr unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1951518 | partial_layout |
| `0x050a000d` | NPC_SHOP_050A_000D *(label)* | S>C | +10 undefined4 unknown; +14 undefined2 unknown; +16 char unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1951275 | partial_layout |
| `0x050a000e` | NPC_SHOP_050A_000E *(label)* | C>S | +10 undefined4 unknown; +14 uint unknown | NPC Shop: request. NPC shop buy/sell/repair. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3152420 | partial_layout |
| `0x050a000f` | NPC_SHOP_050A_000F *(label)* | S>C | unknown | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1952346 | located_only |
| `0x050a0010` | NPC_SHOP_050A_0010 *(label)* | C>S | empty body | NPC Shop: request. NPC shop buy/sell/repair. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2223335<br>decompiled-source/global-0.0.1/decompiled-named.c:931940 | partial_layout |

## 0x050b — Storage (warehouse)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050b0000` | STORAGE_WAREHOUSE_050B_0000 *(label)* | S>C | unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949207 | partial_layout |
| `0x050b0001` | STORAGE_WAREHOUSE_050B_0001 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151763 | partial_layout |
| `0x050b0002` | STORAGE_WAREHOUSE_050B_0002 *(label)* | S>C | +10 char unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949222 | partial_layout |
| `0x050b0003` | STORAGE_WAREHOUSE_050B_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1948603 | partial_layout |
| `0x050b0004` | STORAGE_WAREHOUSE_050B_0004 *(label)* | S>C | +10 char unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949648 | partial_layout |
| `0x050b0005` | STORAGE_WAREHOUSE_050B_0005 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151919 | partial_layout |
| `0x050b0006` | STORAGE_WAREHOUSE_050B_0006 *(label)* | S>C | +10 char unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949585 | partial_layout |
| `0x050b0007` | STORAGE_WAREHOUSE_050B_0007 *(label)* | C>S | empty body | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151949 | partial_layout |
| `0x050b0008` | STORAGE_WAREHOUSE_050B_0008 *(label)* | S>C | unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949716 | partial_layout |
| `0x050b0009` | STORAGE_WAREHOUSE_050B_0009 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3301027 | partial_layout |
| `0x050b0010` | STORAGE_WAREHOUSE_050B_0010 *(label)* | S>C | +10 ptr unknown; +13 undefined1 unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3275918 | partial_layout |
| `0x050b0011` | STORAGE_WAREHOUSE_050B_0011 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151794 | partial_layout |
| `0x050b0012` | STORAGE_WAREHOUSE_050B_0012 *(label)* | S>C | +10 char unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949401 | partial_layout |
| `0x050b0013` | STORAGE_WAREHOUSE_050B_0013 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3301062 | partial_layout |
| `0x050b0014` | STORAGE_WAREHOUSE_050B_0014 *(label)* | S>C | +10 ptr unknown; +13 undefined1 unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038901 | partial_layout |
| `0x050b0015` | STORAGE_WAREHOUSE_050B_0015 *(label)* | C>S | +10 undefined1 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151176 | partial_layout |
| `0x050b0016` | STORAGE_WAREHOUSE_050B_0016 *(label)* | S>C | +10 undefined1 unknown; +11 char unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1950008 | partial_layout |
| `0x050b0017` | STORAGE_WAREHOUSE_050B_0017 *(label)* | C>S | +10 undefined1 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151490 | partial_layout |
| `0x050b0018` | STORAGE_WAREHOUSE_050B_0018 *(label)* | S>C | +10 undefined1 unknown; +11 char unknown | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1950060 | partial_layout |

## 0x050c — PVP / DKSquare options

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050c0000` | PVP_050C_0000 *(label)* | C>S | unknown | PVP / DKSquare options: request. PVP/arena option toggles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1833428 | located_only |
| `0x050c0001` | PVP_050C_0001 *(label)* | S>C | +10 char unknown | PVP / DKSquare options: reply/notification. PVP/arena option toggles. Likely reply to C>S 0x050c0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945487 | partial_layout |
| `0x050c0031` | PVP_050C_0031 *(label)* | C>S | +10 undefined1 unknown | PVP / DKSquare options: request. PVP/arena option toggles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2830921 | partial_layout |
| `0x050c0032` | PVP_050C_0032 *(label)* | S>C | +10 int unknown; +14 undefined1 unknown | PVP / DKSquare options: reply/notification. PVP/arena option toggles. Likely reply to C>S 0x050c0031 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945566 | partial_layout |
| `0x050c0036` | PVP_050C_0036 *(label)* | C>S | +10 undefined1 unknown | PVP / DKSquare options: request. PVP/arena option toggles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2830949 | partial_layout |
| `0x050c0037` | PVP_050C_0037 *(label)* | S>C | +10 int unknown; +14 undefined1 unknown | PVP / DKSquare options: reply/notification. PVP/arena option toggles. Likely reply to C>S 0x050c0036 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945599 | partial_layout |

## 0x050d — Movement / Chat / Enter world

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050d0010` | MOVE | both | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c uint unknown; +20 uint unknown; +24 undefined1 unknown; +28 undefined1 unknown | movement (size 52), highest-volume op | decompiled-source/global-0.0.1/decompiled-named.c:1865353<br>decompiled-source/global-0.0.1/decompiled-named.c:221675<br>decompiled-source/global-0.0.1/decompiled-named.c:223026 … | explained |
| `0x050d0011` | MOVEMENT_050D_0011 *(label)* | C>S | +10 undefined2 unknown | Movement / Chat / Enter world: request. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:277115 | partial_layout |
| `0x050d0012` | MOVEMENT_050D_0012 *(label)* | C>S | +10 undefined4 unknown; +14 short unknown | Movement / Chat / Enter world: request. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:319234<br>decompiled-source/global-0.0.1/decompiled-named.c:328647 | partial_layout |
| `0x050d0013` | CHAT_050D_0013 *(label)* | both | +10 undefined4 unknown; +14 ushort unknown; +18 undefined4 unknown; +34 ptr unknown; +3c undefined1 unknown; +40 undefined4 unknown; +214 undefined4 unknown | Movement / Chat / Enter world: request and reply share this opcode. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x050d0013 (sender 0x1649819, base size 0x34 + text): u32 speaker @0x10 (0x22c03a4 vf+0xc), u16 textLen @0x14 (UTF-16 units incl. NUL, S>C 0x050d0013 (dispatch 0x164d4a7 -> 0x164dd30): u32 speaker handle  *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1922204<br>decompiled-source/global-0.0.1/decompiled-named.c:1924502 | explained |
| `0x050d0014` | MOVEMENT_050D_0014 *(label)* | S>C | unknown | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). Likely reply to C>S 0x050d0013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850319 | located_only |
| `0x050d0015` | MOVEMENT_050D_0015 *(label)* | both | +10 undefined4 unknown | Movement / Chat / Enter world: request and reply share this opcode. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224267<br>decompiled-source/global-0.0.1/decompiled-named.c:2851248 | partial_layout |
| `0x050d0016` | CHAT_050D_0016 *(label)* | both | +11 ptr unknown; +26 undefined1 unknown; +54 undefined4 unknown; +58 undefined4 unknown | Movement / Chat / Enter world: request and reply share this opcode. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1922434<br>decompiled-source/global-0.0.1/decompiled-named.c:1924610 | explained |
| `0x050d0017` | ENTER_WORLD (WAITENTER) | S>C | unknown | WaitEnter state waits for this; handler logs u16@0x10; client then sends ENTER_DONE | decompiled-source/global-0.0.1/decompiled-named.c:236970<br>decompiled-source/global-0.0.1/decompiled-named.c:236998 | located_only |
| `0x050d0018` | MOVEMENT_050D_0018 *(label)* | S>C | unknown | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850319 | located_only |
| `0x050d0019` | MOVEMENT_050D_0019 *(label)* | S>C | +10 short unknown; +52 short unknown; +94 uint unknown; +98 char unknown; +9c undefined2 unknown | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1924251 | partial_layout |
| `0x050d001a` | MOVEMENT_050D_001A *(label)* | S>C | unknown | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2851248 | located_only |
| `0x050d001b` | MOVEMENT_050D_001B *(label)* | C>S | +10 undefined1 unknown | Movement / Chat / Enter world: request. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:215263 | partial_layout |
| `0x050d001c` | MOVEMENT_050D_001C *(label)* | S>C | +10 short unknown; +52 short unknown; +94 uint unknown; +98 char unknown; +9c undefined2 unknown | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). Likely reply to C>S 0x050d001b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1924251 | partial_layout |
| `0x050d001d` | MOVEMENT_050D_001D *(label)* | S>C | +10 undefined4 unknown | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1924351 | partial_layout |
| `0x050d001e` | MOVEMENT_050D_001E *(label)* | S>C | +10 undefined4 unknown; +14 char unknown | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1925950 | partial_layout |

## 0x050e — Trade

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050e0000` | TRADE_050E_0000 *(label)* | both | +10 undefined4 unknown; +14 undefined4 unknown; +18 ptr/copy unknown | Trade: request and reply share this opcode. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1958267<br>decompiled-source/global-0.0.1/decompiled-named.c:224644 | partial_layout |
| `0x050e0001` | TRADE_050E_0001 *(label)* | S>C | +10 undefined4 unknown | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957622 | partial_layout |
| `0x050e0002` | TRADE_050E_0002 *(label)* | C>S | +10 undefined4 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957438<br>decompiled-source/global-0.0.1/decompiled-named.c:1958267<br>decompiled-source/global-0.0.1/decompiled-named.c:3153995 … | partial_layout |
| `0x050e0003` | TRADE_050E_0003 *(label)* | S>C | unknown | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957673 | located_only |
| `0x050e0004` | TRADE_050E_0004 *(label)* | S>C | +10 int unknown; +14 undefined4 unknown | Trade: reply/notification. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957838 | partial_layout |
| `0x050e0005` | TRADE_050E_0005 *(label)* | C>S | empty body | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957422<br>decompiled-source/global-0.0.1/decompiled-named.c:3153812 | partial_layout |
| `0x050e0006` | TRADE_050E_0006 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957302 | partial_layout |
| `0x050e0007` | TRADE_050E_0007 *(label)* | S>C | unknown | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957907 | located_only |
| `0x050e0008` | TRADE_050E_0008 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957251 | partial_layout |
| `0x050e0009` | TRADE_050E_0009 *(label)* | S>C | unknown | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1957933 | located_only |
| `0x050e000b` | TRADE_050E_000B *(label)* | S>C | unknown | Trade: reply/notification. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1958005 | located_only |
| `0x050e000c` | TRADE_050E_000C *(label)* | C>S | +10 undefined1 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3153760 | partial_layout |
| `0x050e000d` | TRADE_050E_000D *(label)* | S>C | unknown | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1958044 | located_only |
| `0x050e000e` | TRADE_050E_000E *(label)* | S>C | +10 char unknown | Trade: reply/notification. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1958059 | partial_layout |
| `0x050e0011` | TRADE_050E_0011 *(label)* | C>S | unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2238043 | located_only |
| `0x050e0012` | TRADE_050E_0012 *(label)* | S>C | +10 undefined1 unknown | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1943266 | partial_layout |
| `0x050e0013` | TRADE_050E_0013 *(label)* | C>S | +10 undefined1 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3153786 | partial_layout |
| `0x050e0014` | TRADE_050E_0014 *(label)* | S>C | +10 char unknown | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1958071 | partial_layout |
| `0x050e0015` | TRADE_050E_0015 *(label)* | S>C | +10 char unknown | Trade: reply/notification. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1958123 | partial_layout |
| `0x050e0016` | TRADE_050E_0016 *(label)* | S>C | unknown | Trade: reply/notification. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1958158 | located_only |
| `0x050e0017` | TRADE_050E_0017 *(label)* | S>C | unknown | Trade: reply/notification. Player-to-player trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1958215 | located_only |

## 0x050f — Tutorial / Quest

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050f0000` | TUTORIAL_050F_0000 *(label)* | C>S | +10 undefined2 unknown | Tutorial / Quest: request. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3143095 | partial_layout |
| `0x050f0001` | TUTORIAL_050F_0001 *(label)* | S>C | +10 undefined2 unknown; +12 char unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898134 | partial_layout |
| `0x050f0002` | TUTORIAL_050F_0002 *(label)* | S>C | +10 short unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898245 | partial_layout |
| `0x050f0003` | TUTORIAL_050F_0003 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898295 | partial_layout |
| `0x050f0004` | TUTORIAL_050F_0004 *(label)* | S>C | +10 undefined2 unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898322 | partial_layout |
| `0x050f0005` | TUTORIAL_050F_0005 *(label)* | S>C | +10 undefined2 unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898346 | partial_layout |
| `0x050f0006` | TUTORIAL_050F_0006 *(label)* | S>C | unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3260374 | located_only |
| `0x050f0007` | TUTORIAL_050F_0007 *(label)* | S>C | unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3260374 | located_only |
| `0x050f0008` | TUTORIAL_050F_0008 *(label)* | C>S | +10 int unknown; +14 short unknown; +16 short unknown | Tutorial / Quest: request. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197063 | partial_layout |
| `0x050f0009` | TUTORIAL_050F_0009 *(label)* | S>C | +10 undefined2 unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898391 | partial_layout |
| `0x050f000a` | TUTORIAL_050F_000A *(label)* | S>C | unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898430 | located_only |
| `0x050f0010` | TUTORIAL_050F_0010 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898176 | partial_layout |
| `0x050f0011` | TUTORIAL_050F_0011 *(label)* | S>C | +12 undefined1 unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898417 | partial_layout |
| `0x050f0012` | TUTORIAL_050F_0012 *(label)* | both | +10 short unknown | Tutorial / Quest: request and reply share this opcode. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898799<br>decompiled-source/global-0.0.1/decompiled-named.c:2230709<br>decompiled-source/global-0.0.1/decompiled-named.c:3182270 … | partial_layout |
| `0x050f0013` | TUTORIAL_050F_0013 *(label)* | C>S | empty body | Tutorial / Quest: request. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3303845 | partial_layout |
| `0x050f0014` | TUTORIAL_050F_0014 *(label)* | S>C | +10 ushort unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898780 | partial_layout |
| `0x050f0015` | TUTORIAL_050F_0015 *(label)* | S>C | unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3274270 | located_only |
| `0x050f0016` | TUTORIAL_050F_0016 *(label)* | S>C | unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898443 | located_only |
| `0x050f0017` | TUTORIAL_050F_0017 *(label)* | C>S | empty body | Tutorial / Quest: request. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:223985 | partial_layout |
| `0x050f0018` | TUTORIAL_050F_0018 *(label)* | S>C | unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898538 | located_only |
| `0x050f0019` | TUTORIAL_050F_0019 *(label)* | C>S | empty body | Tutorial / Quest: request. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3195919 | partial_layout |
| `0x050f001a` | TUTORIAL_050F_001A *(label)* | S>C | unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0019 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898630 | located_only |

## 0x0512 — Attack (assault/fly)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05120002` | ATTACK_ASSAULT_0512_0002 *(label)* | C>S | +10 undefined4 unknown | Attack (assault/fly): request. Special attack moves. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:326746 | partial_layout |
| `0x05120003` | ATTACK_ASSAULT_0512_0003 *(label)* | C>S | +10 undefined4 unknown | Attack (assault/fly): request. Special attack moves. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2852965<br>decompiled-source/global-0.0.1/decompiled-named.c:304473<br>decompiled-source/global-0.0.1/decompiled-named.c:319685 … | partial_layout |

## 0x0515 — Skill

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05150001` | SKILL_0515_0001 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261894 | located_only |
| `0x05150002` | SKILL_0515_0002 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3153333 | partial_layout |
| `0x05150003` | SKILL_0515_0003 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261894 | located_only |
| `0x05150004` | MAINTOOLBAR_0515_0004 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +14 undefined1 unknown; +15 undefined1 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05150004 size 0x18: u32 id @0x10 (obj vf+0x18 -> vf+0x10 -> [0]), u8 a2 @0x14, u8 a3 @0x15   (register) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3147945 | explained |
| `0x05150005` | MAINTOOLBAR_0515_0005 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150004 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S063: S>C 0x05150005 / 0x05150007 (Skill switch 0x167d1e8 -> 0x167d6d0 / 0x167d800): releases lock 1, u8 result @0x10; *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:36553 | explained |
| `0x05150006` | MAINTOOLBAR_0515_0006 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +14 undefined1 unknown; +15 undefined1 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05150006 size 0x14: u8 a2 @0x10, u8 a3 @0x11                                                (clear, obj == null) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3147945 | explained |
| `0x05150007` | MAINTOOLBAR_0515_0007 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:36553 | explained |
| `0x05150008` | SKILL_0515_0008 *(label)* | C>S | +10 ushort unknown; +12 undefined1 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined2 unknown; +22 undefined1 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1955177 | partial_layout |
| `0x05150009` | SKILL_0515_0009 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261894 | located_only |
| `0x0515000a` | SKILL_0515_000A *(label)* | C>S | +10 ushort unknown; +12 undefined1 unknown; +14 undefined1 unknown; +15 undefined1 unknown; +16 undefined1 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined2 unknown; +22 char unknown; +23 char unknown; +24 undefined1 unknown; +25 char unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1955209 | partial_layout |
| `0x0515000b` | SKILL_0515_000B *(label)* | C>S | +10 ushort unknown; +12 undefined1 unknown; +14 undefined1 unknown; +15 undefined1 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined2 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1955252 | partial_layout |
| `0x0515000d` | SKILL_0515_000D *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:76428 | located_only |
| `0x0515000e` | SKILL_0515_000E *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261894 | located_only |
| `0x0515000f` | SKILL_0515_000F *(label)* | C>S | +10 undefined1 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3153355 | partial_layout |
| `0x05150010` | SKILL_0515_0010 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x0515000f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1565200 | located_only |
| `0x05150011` | SKILL_0515_0011 *(label)* | C>S | +10 ushort unknown; +12 undefined1 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3153379 | partial_layout |
| `0x05150012` | SKILL_0515_0012 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261894 | located_only |
| `0x05150013` | SKILL_0515_0013 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261894 | located_only |
| `0x05150014` | SKILL_0515_0014 *(label)* | C>S | +10 undefined4 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:254134<br>decompiled-source/global-0.0.1/decompiled-named.c:254425<br>decompiled-source/global-0.0.1/decompiled-named.c:254521 … | partial_layout |
| `0x05150015` | SKILL_0515_0015 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown; +18 undefined1 unknown; +19 undefined2 unknown; +1b undefined1 unknown; +1c undefined1 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3184839 | partial_layout |
| `0x05150016` | SKILL_0515_0016 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264852 | located_only |
| `0x05150017` | SKILL_0515_0017 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264852 | located_only |
| `0x05150018` | SKILL_0515_0018 *(label)* | C>S | empty body | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3184819 | partial_layout |
| `0x05150019` | SKILL_0515_0019 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150018 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264852 | located_only |

## 0x0516 — Creature event

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05160000` | CREATURE_EVENT_0516_0000 *(label)* | C>S | unknown | Creature event: request. Creature event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:317996 | located_only |
| `0x05160001` | CREATURE_EVENT_0516_0001 *(label)* | S>C | unknown | Creature event: reply/notification. Creature event. Likely reply to C>S 0x05160000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |

## 0x0517 — NPC teleport

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05170000` | NPC_TELEPORT_0517_0000 *(label)* | S>C | unknown | NPC teleport: reply/notification. NPC teleport. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1910264<br>decompiled-source/global-0.0.1/decompiled-named.c:1910288 | located_only |
| `0x05170001` | NPC_TELEPORT_0517_0001 *(label)* | C>S | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown | NPC teleport: request. NPC teleport. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197177 | partial_layout |
| `0x05170002` | NPC_TELEPORT_0517_0002 *(label)* | S>C | unknown | NPC teleport: reply/notification. NPC teleport. Likely reply to C>S 0x05170001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1910264<br>decompiled-source/global-0.0.1/decompiled-named.c:1910288 | located_only |

## 0x0518 — Status

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0518000a` | STATUS_0518_000A *(label)* | S>C | +10 undefined2 unknown; +14 int unknown; +18 int unknown | Status: reply/notification. Stat points and status updates. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1997490 | partial_layout |
| `0x0518000b` | STATUS_0518_000B *(label)* | S>C | +10 int unknown; +14 undefined2 unknown | Status: reply/notification. Stat points and status updates. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1997542 | partial_layout |
| `0x0518000c` | STATUS_0518_000C *(label)* | S>C | +10 int unknown; +14 undefined2 unknown | Status: reply/notification. Stat points and status updates. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1997605 | partial_layout |
| `0x0518000f` | STATUS_0518_000F *(label)* | S>C | unknown | Status: reply/notification. Stat points and status updates. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264986 | located_only |
| `0x05180010` | STATUS_0518_0010 *(label)* | S>C | unknown | Status: reply/notification. Stat points and status updates. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264986 | located_only |
| `0x05180011` | STATUS_0518_0011 *(label)* | C>S | unknown | Status: request. Stat points and status updates. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:606000 | located_only |
| `0x05180012` | STATUS_0518_0012 *(label)* | S>C | unknown | Status: reply/notification. Stat points and status updates. Likely reply to C>S 0x05180011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264986 | located_only |
| `0x05180013` | STATUS_0518_0013 *(label)* | C>S | empty body | Status: request. Stat points and status updates. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3282315 | partial_layout |

## 0x0519 — Servant / effects

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05190000` | SERVANT_0519_0000 *(label)* | both | +10 undefined4 unknown; +14 undefined4 unknown; +18 short unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +32 undefined4 unknown; +34 undefined4 unknown; +36 undefined2 unknown; +37 char unknown; +46 undefined4 unknown; +4a ptr/copy unknown; +1b2 char unknown; +1b4 undefined2 unknown | Servant / effects: request and reply share this opcode. Servant and effect notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:197212<br>decompiled-source/global-0.0.1/decompiled-named.c:2223712<br>decompiled-source/global-0.0.1/decompiled-named.c:310084 | partial_layout |
| `0x05190001` | SERVANT_0519_0001 *(label)* | C>S | +10 undefined2 unknown; +16 undefined4 unknown; +1a undefined2 unknown | Servant / effects: request. Servant and effect notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3158450 | partial_layout |
| `0x05190002` | SERVANT_0519_0002 *(label)* | C>S | empty body | Servant / effects: request. Servant and effect notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3158430 | partial_layout |
| `0x05190003` | SERVANT_0519_0003 *(label)* | S>C | +14 undefined4 unknown; +18 char unknown | Servant / effects: reply/notification. Servant and effect notices. Likely reply to C>S 0x05190002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:308441 | partial_layout |

## 0x051a — Store (personal shop) / Auction

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051a0000` | STORE_PERSONAL_SHOP_051A_0000 *(label)* | C>S | +10 undefined4 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2250115 | partial_layout |
| `0x051a0001` | STORE_PERSONAL_SHOP_051A_0001 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3207191 | located_only |
| `0x051a0002` | STORE_PERSONAL_SHOP_051A_0002 *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3207693 | partial_layout |
| `0x051a0003` | STORE_PERSONAL_SHOP_051A_0003 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2251793 | located_only |
| `0x051a0004` | STORE_PERSONAL_SHOP_051A_0004 *(label)* | C>S | unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2251257 | located_only |
| `0x051a0005` | STORE_PERSONAL_SHOP_051A_0005 *(label)* | S>C | +14 int unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2251168 | partial_layout |
| `0x051a0006` | STORE_PERSONAL_SHOP_051A_0006 *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3207505 | partial_layout |
| `0x051a0007` | STORE_PERSONAL_SHOP_051A_0007 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2251793<br>decompiled-source/global-0.0.1/decompiled-named.c:3207455 | located_only |
| `0x051a0008` | STORE_PERSONAL_SHOP_051A_0008 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined1 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2250795 | partial_layout |
| `0x051a0009` | STORE_PERSONAL_SHOP_051A_0009 *(label)* | S>C | +10 undefined1 unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2250915 | partial_layout |
| `0x051a000a` | STORE_PERSONAL_SHOP_051A_000A *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2250761 | partial_layout |
| `0x051a000b` | STORE_PERSONAL_SHOP_051A_000B *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2251082 | located_only |
| `0x051a000c` | STORE_PERSONAL_SHOP_051A_000C *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown; +17 bool unknown; +18 undefined2 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3277071 | partial_layout |
| `0x051a000d` | STORE_PERSONAL_SHOP_051A_000D *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 ptr unknown; +1c short unknown; +1e undefined1 unknown; +1f char unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2251829<br>decompiled-source/global-0.0.1/decompiled-named.c:3207455 | partial_layout |
| `0x051a000e` | STORE_PERSONAL_SHOP_051A_000E *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3158767 | partial_layout |
| `0x051a000f` | STORE_PERSONAL_SHOP_051A_000F *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2007769<br>decompiled-source/global-0.0.1/decompiled-named.c:2008035 | located_only |
| `0x051a0010` | STORE_PERSONAL_SHOP_051A_0010 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined1 unknown; +13 undefined1 unknown; +14 undefined1 unknown; +15 undefined1 unknown; +16 undefined1 unknown; +17 undefined1 unknown; +1c undefined4 unknown; +20 ptr/copy unknown; +a0 undefined1 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3175243 | partial_layout |
| `0x051a0012` | STORE_PERSONAL_SHOP_051A_0012 *(label)* | C>S | +3a undefined4 unknown; +3e undefined4 unknown; +42 undefined4 unknown; +46 undefined4 unknown; +4a undefined4 unknown; +4e undefined4 unknown; +52 undefined4 unknown; +56 undefined4 unknown; +5a undefined4 unknown; +5e undefined4 unknown; +62 undefined4 unknown; +66 undefined4 unknown; +6a undefined8 unknown; +72 undefined4 unknown; +76 undefined1 unknown; +77 undefined8 unknown; +7f undefined4 unknown; +88 undefined8 unknown; +8c undefined4 unknown; +90 undefined1 unknown; +91 undefined1 unknown; +92 undefined2 unknown; +98 undefined4 unknown; +9c undefined4 unknown; +a0 undefined1 unknown; +b3 undefined4 unknown; +b7 undefined4 unknown; +bb undefined4 unknown; +bf undefined4 unknown; +c3 undefined1 unknown; +c4 undefined1 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2098701 | partial_layout |
| `0x051a0013` | STORE_PERSONAL_SHOP_051A_0013 *(label)* | S>C | +10 char unknown; +60 undefined4 unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0012 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2098880 | partial_layout |
| `0x051a0014` | STORE_PERSONAL_SHOP_051A_0014 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2098311 | located_only |
| `0x051a0015` | STORE_PERSONAL_SHOP_051A_0015 *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3175323 | partial_layout |
| `0x051a0016` | STORE_PERSONAL_SHOP_051A_0016 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2098853 | located_only |
| `0x051a0017` | STORE_PERSONAL_SHOP_051A_0017 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3301097 | partial_layout |
| `0x051a0018` | STORE_PERSONAL_SHOP_051A_0018 *(label)* | S>C | +10 ptr unknown; +13 undefined1 unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2039079 | partial_layout |
| `0x051a0019` | STORE_PERSONAL_SHOP_051A_0019 *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2223377<br>decompiled-source/global-0.0.1/decompiled-named.c:599255 | partial_layout |
| `0x051a001a` | STORE_PERSONAL_SHOP_051A_001A *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined1 unknown; +22 ptr/copy unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2107693 | partial_layout |
| `0x051a001b` | STORE_PERSONAL_SHOP_051A_001B *(label)* | S>C | +18 undefined4 unknown; +1c undefined4 unknown; +20 char unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a001a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2007769<br>decompiled-source/global-0.0.1/decompiled-named.c:2008035<br>decompiled-source/global-0.0.1/decompiled-named.c:2099512 | partial_layout |
| `0x051a001c` | STORE_PERSONAL_SHOP_051A_001C *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3176086 | partial_layout |
| `0x051a001d` | STORE_PERSONAL_SHOP_051A_001D *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3176112 | partial_layout |
| `0x051a001f` | STORE_PERSONAL_SHOP_051A_001F *(label)* | S>C | +10 undefined4 unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2099601 | partial_layout |
| `0x051a0020` | STORE_PERSONAL_SHOP_051A_0020 *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3176148 | partial_layout |
| `0x051a0021` | STORE_PERSONAL_SHOP_051A_0021 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0020 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2098243 | located_only |
| `0x051a0022` | STORE_PERSONAL_SHOP_051A_0022 *(label)* | C>S | +10 uint unknown; +14 uint unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3176173 | partial_layout |
| `0x051a0023` | STORE_PERSONAL_SHOP_051A_0023 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 undefined4 unknown; +3c undefined4 unknown; +40 undefined4 unknown; +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined8 unknown; +58 undefined4 unknown; +5c undefined1 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3176206 | partial_layout |
| `0x051a0024` | STORE_PERSONAL_SHOP_051A_0024 *(label)* | S>C | +10 char unknown; +60 undefined4 unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0023 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2099781 | partial_layout |
| `0x051a0025` | STORE_PERSONAL_SHOP_051A_0025 *(label)* | C>S | +10 ptr/copy unknown; +14 undefined4 unknown; +b0 undefined4 unknown; +b4 undefined4 unknown; +b8 uint unknown; +bc undefined4 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2107931<br>decompiled-source/global-0.0.1/decompiled-named.c:3176263 | partial_layout |
| `0x051a0026` | STORE_PERSONAL_SHOP_051A_0026 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 char unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0025 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2099663 | partial_layout |
| `0x051a0027` | STORE_PERSONAL_SHOP_051A_0027 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2098243 | located_only |

## 0x051c — Upgrade

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051c0000` | UPGRADE_051C_0000 *(label)* | S>C | unknown | Upgrade: reply/notification. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0000 open window, no body (case 0x16ef7e6 -> handler 0x16ef830) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263000 | located_only |
| `0x051c0001` | UPGRADE_051C_0001 *(label)* | C>S | +10 int unknown; +14 undefined2 unknown; +16 undefined1 unknown; +17 undefined2 unknown; +19 undefined1 unknown; +1a undefined2 unknown; +1c undefined1 unknown; +1d undefined2 unknown; +1f undefined1 unknown; +20 undefined2 unknown; +22 undefined1 unknown; +23 undefined2 unknown; +25 undefined1 unknown; +26 undefined1 unknown | Upgrade: request. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051c0001 upgrade request, size 0x28 (builder 0x16ef020). Body offsets (packet offset - 0x10): *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3161473 | partial_layout |
| `0x051c0002` | UPGRADE_051C_0002 *(label)* | S>C | unknown | Upgrade: reply/notification. Item upgrade (enchant). Likely reply to C>S 0x051c0001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0002 result (handler 0x16ef880), size 0x1e (= last field read; exact size UNVERIFIED): *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263000 | located_only |
| `0x051c0003` | UPGRADE_051C_0003 *(label)* | C>S | empty body | Upgrade: request. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051c0003 close (size 0x10, builder 0x16eefd0) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3161453 | partial_layout |
| `0x051c0004` | UPGRADE_051C_0004 *(label)* | S>C | unknown | Upgrade: reply/notification. Item upgrade (enchant). Likely reply to C>S 0x051c0003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0004 close window, no body (case 0x16ef7f1).  Other S>C cases UNDECODED, not sent. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263000 | partial_layout |
| `0x051c0005` | UPGRADE_051C_0005 *(label)* | S>C | unknown | Upgrade: reply/notification. Item upgrade (enchant). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263000 | located_only |

## 0x051d — Target

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051d0000` | TARGET_051D_0000 *(label)* | S>C | +10 undefined4 unknown; +14 int unknown; +1c int unknown; +20 int unknown; +24 uint unknown; +33 char unknown | Target: reply/notification. Target selection. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:309242 | partial_layout |
| `0x051d0001` | TARGET_051D_0001 *(label)* | C>S | +10 int unknown | Target: request. Target selection. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:310701<br>decompiled-source/global-0.0.1/decompiled-named.c:3157115 | partial_layout |
| `0x051d0003` | TARGET_051D_0003 *(label)* | S>C | +14 undefined4 unknown; +18 char unknown | Target: reply/notification. Target selection. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:308358 | partial_layout |
| `0x051d0004` | TARGET_051D_0004 *(label)* | C>S | empty body | Target: request. Target selection. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2845370 | partial_layout |

## 0x051e — ItemAddSocket

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051e0001` | ITEMADDSOCKET_051E_0001 *(label)* | C>S | unknown | ItemAddSocket: request. Add socket to item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051e0001 request, size 0x30 (ctor 0x16f53d0, filled at 0x16f4d1d / 0x16f50c3 from a 0x17-byte struct: zero 0x16f42a0, *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2033632 | located_only |
| `0x051e0003` | ITEMADDSOCKET_051E_0003 *(label)* | C>S | empty body | ItemAddSocket: request. Add socket to item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051e0003 close, size 0x10 (0x16f4b50) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3162501 | partial_layout |

## 0x051f — NPC mail

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051f0000` | NPC_MAIL_051F_0000 *(label)* | both | unknown | NPC mail: request and reply share this opcode. NPC mail dialog. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145311<br>decompiled-source/global-0.0.1/decompiled-named.c:3197425 | located_only |
| `0x051f0001` | NPC_MAIL_051F_0001 *(label)* | C>S | empty body | NPC mail: request. NPC mail dialog. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197448 | partial_layout |
| `0x051f0002` | NPC_MAIL_051F_0002 *(label)* | S>C | unknown | NPC mail: reply/notification. NPC mail dialog. Likely reply to C>S 0x051f0001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145311 | located_only |
| `0x051f0003` | NPC_MAIL_051F_0003 *(label)* | C>S | empty body | NPC mail: request. NPC mail dialog. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2223356<br>decompiled-source/global-0.0.1/decompiled-named.c:599239 | partial_layout |

## 0x0520 — CashShop / VipShop

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05200000` | VIPSHOP_0520_0000 *(label)* | C>S | +10 undefined1 unknown | CashShop / VipShop: request. Cash/VIP shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3169563<br>decompiled-source/global-0.0.1/decompiled-named.c:3188100 | explained |
| `0x05200001` | CASHSHOP_0520_0001 *(label)* | S>C | +10 undefined1 unknown; +11 char unknown | CashShop / VipShop: reply/notification. Cash/VIP shop. Likely reply to C>S 0x05200000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2076439 | partial_layout |
| `0x05200002` | VIPSHOP_0520_0002 *(label)* | C>S | +10 undefined1 unknown | CashShop / VipShop: request. Cash/VIP shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3169589<br>decompiled-source/global-0.0.1/decompiled-named.c:3169780<br>decompiled-source/global-0.0.1/decompiled-named.c:3188126 | explained |
| `0x05200003` | CASHSHOP_0520_0003 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash/VIP shop. Likely reply to C>S 0x05200002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2076500 | located_only |

## 0x0521 — Fishing

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05210000` | FISHING_0521_0000 *(label)* | C>S | unknown | Fishing: request. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2231849 | located_only |
| `0x05210001` | FISHING_0521_0001 *(label)* | S>C | unknown | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3211567 | located_only |
| `0x05210003` | FISHING_0521_0003 *(label)* | C>S | empty body | Fishing: request. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266745 | partial_layout |
| `0x05210004` | FISHING_0521_0004 *(label)* | S>C | unknown | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3211346 | located_only |
| `0x05210006` | FISHING_0521_0006 *(label)* | S>C | unknown | Fishing: reply/notification. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1818045 | located_only |
| `0x05210007` | FISHING_0521_0007 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined8 unknown; +38 undefined4 unknown | Fishing: request. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1817682 | partial_layout |
| `0x05210008` | FISHING_0521_0008 *(label)* | S>C | unknown | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1818045 | located_only |
| `0x05210009` | FISHING_0521_0009 *(label)* | S>C | +10 ptr unknown; +4d char unknown | Fishing: reply/notification. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945735 | partial_layout |
| `0x0521000a` | FISHING_0521_000A *(label)* | C>S | empty body | Fishing: request. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1865089 | partial_layout |

## 0x0522 — PVP duel

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05220000` | PVP_DUEL_0522_0000 *(label)* | C>S | +10 undefined4 unknown; +14 ptr/copy unknown; +3e undefined1 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1819305 | partial_layout |
| `0x05220001` | PVP_DUEL_0522_0001 *(label)* | S>C | unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x05220000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256925 | located_only |
| `0x05220002` | PVP_DUEL_0522_0002 *(label)* | C>S | +10 ptr/copy unknown; +40 undefined1 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1819255 | partial_layout |
| `0x05220003` | PVP_DUEL_0522_0003 *(label)* | S>C | unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x05220002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1850944 | located_only |
| `0x05220004` | PVP_DUEL_0522_0004 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1850879 | partial_layout |
| `0x05220005` | PVP_DUEL_0522_0005 *(label)* | C>S | +10 ptr/copy unknown; +3c undefined4 unknown; +40 undefined1 unknown; +41 undefined1 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1851335<br>decompiled-source/global-0.0.1/decompiled-named.c:1852837<br>decompiled-source/global-0.0.1/decompiled-named.c:1852891 … | partial_layout |
| `0x05220006` | PVP_DUEL_0522_0006 *(label)* | S>C | unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x05220005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256925 | located_only |
| `0x05220007` | PVP_DUEL_0522_0007 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c ptr unknown; +46 ptr unknown; +72 ushort unknown; +74 ushort unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1850990 | partial_layout |
| `0x05220008` | PVP_DUEL_0522_0008 *(label)* | C>S | +10 undefined4 unknown; +14 ptr/copy unknown; +3e undefined1 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1818514 | partial_layout |
| `0x05220009` | PVP_DUEL_0522_0009 *(label)* | S>C | unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x05220008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1851056 | located_only |
| `0x0522000a` | PVP_DUEL_0522_000A *(label)* | C>S | +10 undefined1 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1818748 | partial_layout |
| `0x0522000b` | PVP_DUEL_0522_000B *(label)* | S>C | unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x0522000a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256925 | located_only |
| `0x0522000d` | PVP_DUEL_0522_000D *(label)* | S>C | +18 undefined4 unknown; +1c undefined2 unknown; +1e undefined2 unknown; +20 undefined2 unknown; +24 undefined4 unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1851079 | partial_layout |
| `0x0522000e` | PVP_DUEL_0522_000E *(label)* | S>C | unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256925 | located_only |
| `0x0522000f` | PVP_DUEL_0522_000F *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1852444 | partial_layout |
| `0x05220011` | PVP_DUEL_0522_0011 *(label)* | S>C | +10 char unknown; +14 int unknown; +18 int unknown; +1c int unknown; +20 int unknown | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1851160 | partial_layout |

## 0x0523 — Portal / CashItem

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05230000` | PORTAL_0523_0000 *(label)* | S>C | unknown | Portal / CashItem: reply/notification. Portal and cash item notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145376 | located_only |
| `0x05230001` | PORTAL_0523_0001 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Portal / CashItem: request. Portal and cash item notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3301167 | partial_layout |
| `0x05230002` | CASHITEM_0523_0002 *(label)* | S>C | +10 ptr unknown; +13 undefined1 unknown | Portal / CashItem: reply/notification. Portal and cash item notices. Likely reply to C>S 0x05230001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038582 | partial_layout |
| `0x05230003` | PORTAL_0523_0003 *(label)* | S>C | +10 undefined4 unknown; +14 ushort unknown; +16 ushort unknown; +18 byte unknown; +1c undefined4 unknown; +20 undefined2 unknown; +22 undefined2 unknown; +24 undefined1 unknown | Portal / CashItem: reply/notification. Portal and cash item notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:309861 | partial_layout |
| `0x05230004` | PORTAL_0523_0004 *(label)* | S>C | +10 char unknown | Portal / CashItem: reply/notification. Portal and cash item notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3275976 | partial_layout |
| `0x05230005` | CASHITEM_0523_0005 *(label)* | C>S | unknown | Portal / CashItem: request. Portal and cash item notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2037048 | located_only |
| `0x05230006` | PORTAL_0523_0006 *(label)* | S>C | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown | Portal / CashItem: reply/notification. Portal and cash item notices. Likely reply to C>S 0x05230005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038648 | partial_layout |
| `0x05230007` | PORTAL_0523_0007 *(label)* | S>C | +10 undefined4 unknown | Portal / CashItem: reply/notification. Portal and cash item notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038731 | partial_layout |

## 0x0524 — Enter event

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05240000` | ENTER_EVENT_0524_0000 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined2 unknown; +76 undefined1 unknown; +77 undefined1 unknown | Enter event: reply/notification. Object enter event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:309161 | partial_layout |

## 0x0525 — Quest

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05250000` | QUEST_0525_0000 *(label)* | S>C | unknown | Quest: reply/notification. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1897950 | located_only |
| `0x05250001` | QUEST_0525_0001 *(label)* | C>S | +10 undefined4 unknown; +14 short unknown | Quest: request. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3143167 | partial_layout |
| `0x05250002` | QUEST_0525_0002 *(label)* | S>C | +10 undefined1 unknown | Quest: reply/notification. Quest UI. Likely reply to C>S 0x05250001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898644 | partial_layout |
| `0x05250003` | QUEST_0525_0003 *(label)* | C>S | empty body | Quest: request. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3143138 | partial_layout |
| `0x05250004` | QUEST_0525_0004 *(label)* | S>C | unknown | Quest: reply/notification. Quest UI. Likely reply to C>S 0x05250003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1897950 | located_only |

## 0x0526 — Dungeon / InformDialog / Captcha

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05260000` | DUNGEON_0526_0000 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260001` | DUNGEON_0526_0001 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2059044 | partial_layout |
| `0x05260002` | DUNGEON_0526_0002 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145406 | located_only |
| `0x05260003` | DUNGEON_0526_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197473 | partial_layout |
| `0x05260004` | DUNGEON_0526_0004 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined1 unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. Likely reply to C>S 0x05260003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2059319 | partial_layout |
| `0x05260005` | DUNGEON_0526_0005 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260006` | DUNGEON_0526_0006 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260007` | DUNGEON_0526_0007 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260008` | DUNGEON_0526_0008 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260009` | DUNGEON_0526_0009 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x0526000a` | DUNGEON_0526_000A *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x0526000b` | DUNGEON_0526_000B *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x0526000c` | DUNGEON_0526_000C *(label)* | S>C | +10 undefined2 unknown; +14 undefined4 unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2059410 | partial_layout |
| `0x0526000d` | DUNGEON_0526_000D *(label)* | C>S | +10 undefined2 unknown; +14 undefined4 unknown; +18 undefined1 unknown; +1a short unknown; +1c ptr/copy unknown | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2214221<br>decompiled-source/global-0.0.1/decompiled-named.c:3239048 | partial_layout |
| `0x0526000e` | DUNGEON_0526_000E *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. Likely reply to C>S 0x0526000d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260010` | DUNGEON_0526_0010 *(label)* | C>S | empty body | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2871717<br>decompiled-source/global-0.0.1/decompiled-named.c:3239033 | partial_layout |
| `0x05260011` | DUNGEON_0526_0011 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. Likely reply to C>S 0x05260010 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260012` | DUNGEON_0526_0012 *(label)* | S>C | +14 ushort unknown; +16 ushort unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2086736 | partial_layout |
| `0x05260013` | DUNGEON_0526_0013 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263865 | located_only |
| `0x05260014` | DUNGEON_0526_0014 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2087083 | located_only |
| `0x05260015` | DUNGEON_0526_0015 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2087169 | located_only |
| `0x05260016` | DUNGEON_0526_0016 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260017` | DUNGEON_0526_0017 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260018` | DUNGEON_0526_0018 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260019` | DUNGEON_0526_0019 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260020` | DUNGEON_0526_0020 *(label)* | S>C | +10 char unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2059447 | partial_layout |
| `0x05260021` | DUNGEON_0526_0021 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260022` | DUNGEON_0526_0022 *(label)* | C>S | empty body | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3166043 | partial_layout |
| `0x05260023` | DUNGEON_0526_0023 *(label)* | S>C | unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. Likely reply to C>S 0x05260022 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263635 | located_only |
| `0x05260025` | DUNGEON_0526_0025 *(label)* | C>S | unknown | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:271498 | located_only |
| `0x05260026` | DUNGEON_0526_0026 *(label)* | C>S | unknown | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:271514 | located_only |

## 0x0527 — Creature/enter events

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05270000` | CREATURE_0527_0000 *(label)* | S>C | +10 undefined4 unknown; +14 int unknown; +38 undefined2 unknown; +3a undefined2 unknown; +3c undefined2 unknown; +68 short unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:308935 | partial_layout |
| `0x05270001` | CREATURE_0527_0001 *(label)* | S>C | unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x05270002` | CREATURE_0527_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined1 unknown; +18 int unknown; +1c undefined4 unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:309077 | partial_layout |
| `0x05270003` | CREATURE_0527_0003 *(label)* | S>C | unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x05270004` | CREATURE_0527_0004 *(label)* | S>C | unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x05270005` | CREATURE_0527_0005 *(label)* | S>C | +10 undefined4 unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276242 | partial_layout |

## 0x0528 — Siege

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05280000` | SIEGE_0528_0000 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145115 | located_only |
| `0x05280001` | SIEGE_0528_0001 *(label)* | C>S | +10 short unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197232 | partial_layout |
| `0x05280002` | SIEGE_0528_0002 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145115 | located_only |
| `0x05280003` | SIEGE_0528_0003 *(label)* | C>S | +10 undefined2 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165187 | partial_layout |
| `0x05280004` | SIEGE_0528_0004 *(label)* | S>C | +10 undefined1 unknown; +18 int unknown; +1c int unknown; +28 undefined4 unknown; +2c undefined2 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053255 | partial_layout |
| `0x05280007` | SIEGE_0528_0007 *(label)* | S>C | +10 char unknown; +14 undefined4 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1911666 | partial_layout |
| `0x05280008` | SIEGE_0528_0008 *(label)* | C>S | empty body | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197331 | partial_layout |
| `0x05280009` | SIEGE_0528_0009 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1911637 | located_only |
| `0x0528000a` | SIEGE_0528_000A *(label)* | C>S | empty body | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165265 | partial_layout |
| `0x0528000b` | SIEGE_0528_000B *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528000a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1911637 | located_only |
| `0x0528000c` | SIEGE_0528_000C *(label)* | S>C | +10 undefined4 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276216 | partial_layout |
| `0x0528000d` | SIEGE_0528_000D *(label)* | C>S | +10 undefined4 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3163699 | partial_layout |
| `0x0528000e` | SIEGE_0528_000E *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528000d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263392 | located_only |
| `0x0528000f` | SIEGE_0528_000F *(label)* | S>C | +10 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053761 | partial_layout |
| `0x05280010` | SIEGE_0528_0010 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053824 | located_only |
| `0x05280011` | SIEGE_0528_0011 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x05280012` | SIEGE_0528_0012 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263392 | located_only |
| `0x05280013` | SIEGE_0528_0013 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x05280014` | SIEGE_0528_0014 *(label)* | S>C | +10 undefined1 unknown; +14 undefined4 unknown; +18 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2052638 | partial_layout |
| `0x05280015` | SIEGE_0528_0015 *(label)* | C>S | empty body | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165439 | partial_layout |
| `0x05280016` | SIEGE_0528_0016 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x05280017` | SIEGE_0528_0017 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165459 | partial_layout |
| `0x05280018` | SIEGE_0528_0018 *(label)* | S>C | +10 undefined1 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2052704 | partial_layout |
| `0x05280019` | SIEGE_0528_0019 *(label)* | S>C | +10 char unknown; +11 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053918 | partial_layout |
| `0x0528001a` | SIEGE_0528_001A *(label)* | S>C | +10 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2052573 | partial_layout |
| `0x0528001b` | SIEGE_0528_001B *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x05280020` | SIEGE_0528_0020 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x05280021` | SIEGE_0528_0021 *(label)* | S>C | +10 char unknown; +18 char unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054063 | partial_layout |
| `0x05280022` | SIEGE_0528_0022 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined1 unknown; +13 undefined1 unknown; +14 undefined1 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165014 | partial_layout |
| `0x05280023` | SIEGE_0528_0023 *(label)* | S>C | +10 char unknown; +68 undefined4 unknown; +6c undefined4 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280022 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054182 | partial_layout |
| `0x05280024` | SIEGE_0528_0024 *(label)* | S>C | +10 char unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054527 | partial_layout |
| `0x05280025` | SIEGE_0528_0025 *(label)* | C>S | +10 uint unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165100 | partial_layout |
| `0x05280026` | SIEGE_0528_0026 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280025 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x05280027` | SIEGE_0528_0027 *(label)* | C>S | empty body | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165126 | partial_layout |
| `0x05280028` | SIEGE_0528_0028 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280027 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x05280029` | SIEGE_0528_0029 *(label)* | S>C | +10 int unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +34 undefined8 unknown; +3c undefined2 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054322 | partial_layout |
| `0x0528002a` | SIEGE_0528_002A *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054423 | located_only |
| `0x0528002b` | SIEGE_0528_002B *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145694 | located_only |
| `0x0528002c` | SIEGE_0528_002C *(label)* | C>S | +10 short unknown; +12 undefined2 unknown; +14 undefined2 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2051281 | partial_layout |
| `0x0528002d` | SIEGE_0528_002D *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528002c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x0528002e` | SIEGE_0528_002E *(label)* | C>S | empty body | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165068 | partial_layout |
| `0x0528002f` | SIEGE_0528_002F *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528002e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x05280030` | SIEGE_0528_0030 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145723 | located_only |
| `0x05280031` | SIEGE_0528_0031 *(label)* | C>S | +10 undefined2 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197853 | partial_layout |
| `0x05280032` | SIEGE_0528_0032 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280031 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145723 | located_only |
| `0x05280033` | SIEGE_0528_0033 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145759 | located_only |
| `0x05280034` | SIEGE_0528_0034 *(label)* | C>S | +10 undefined2 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197906 | partial_layout |
| `0x05280035` | SIEGE_0528_0035 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280034 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145759 | located_only |
| `0x05280036` | SIEGE_0528_0036 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145795 | located_only |
| `0x05280037` | SIEGE_0528_0037 *(label)* | C>S | +10 undefined2 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197959 | partial_layout |
| `0x05280038` | SIEGE_0528_0038 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280037 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145795 | located_only |
| `0x05280039` | SIEGE_0528_0039 *(label)* | S>C | +10 int unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054471 | partial_layout |
| `0x0528003a` | SIEGE_0528_003A *(label)* | S>C | +34 int unknown; +38 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054616 | partial_layout |
| `0x0528003b` | SIEGE_0528_003B *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x0528003c` | SIEGE_0528_003C *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |

## 0x0529 — Enter event

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05290000` | ENTER_EVENT_0529_0000 *(label)* | S>C | +10 int unknown; +18 int unknown; +1c float unknown; +20 ptr unknown | Enter event: reply/notification. Enter event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:309983 | partial_layout |

## 0x052a — Vehicle

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052a0000` | VEHICLE_052A_0000 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3166562 | partial_layout |
| `0x052a0001` | VEHICLE_052A_0001 *(label)* | S>C | unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263719 | explained |
| `0x052a0002` | VEHICLE_052A_0002 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3166583 | partial_layout |
| `0x052a0003` | VEHICLE_052A_0003 *(label)* | S>C | +10 undefined1 unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2060120 | explained |
| `0x052a0004` | VEHICLE_052A_0004 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3166603 | partial_layout |
| `0x052a0005` | VEHICLE_052A_0005 *(label)* | S>C | unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263719 | explained |
| `0x052a0006` | VEHICLE_052A_0006 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3166624 | partial_layout |
| `0x052a0007` | VEHICLE_052A_0007 *(label)* | S>C | +10 undefined1 unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2060176 | explained |
| `0x052a0008` | VEHICLE_052A_0008 *(label)* | S>C | unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263719 | explained |
| `0x052a0009` | VEHICLE_052A_0009 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2059696 | partial_layout |
| `0x052a0010` | VEHICLE_052A_0010 *(label)* | S>C | +10 char unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2060227 | explained |
| `0x052a0011` | VEHICLE_052A_0011 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2059696 | partial_layout |
| `0x052a0012` | VEHICLE_052A_0012 *(label)* | S>C | +14 char unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2060262 | partial_layout |
| `0x052a0013` | VEHICLEUPGRADE_052A_0013 *(label)* | C>S | unknown | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0013 vf+0x54 0x17c0b20 size 0x30: +0x10 10 x ref3 (memcpy 0x1e bytes from +0xa)  -> engine vehicleservice 'crystallize' {uids (1..10)} *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2161463 | located_only |
| `0x052a0014` | VEHICLEUPGRADE_052A_0014 *(label)* | S>C | +2e undefined1 unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2161765 | explained |
| `0x052a0015` | VEHICLEUPGRADE_052A_0015 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined2 unknown; +15 undefined1 unknown; +16 undefined2 unknown | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0015 vf+0x58 0x17c0b80 size 0x18: +0x10 ref3 vehicle, +0x13 ref3 material, +0x16 u16 material stack (item(ref B) vf+0x1c -> +0x0e) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2161485 | explained |
| `0x052a0016` | VEHICLEUPGRADE_052A_0016 *(label)* | S>C | +18 undefined1 unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2161837 | explained |
| `0x052a0017` | VEHICLEUPGRADE_052A_0017 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined2 unknown; +15 undefined1 unknown | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0017 vf+0x60 0x17c02a0 size 0x18: +0x10 ref3 vehicle, +0x13 ref3 gearwheel        -> engine 'enchant' {uid, gear} *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2161103 | partial_layout |
| `0x052a0018` | VEHICLEUPGRADE_052A_0018 *(label)* | S>C | +10 undefined3 unknown; +13 undefined3 unknown; +1c undefined2 unknown; +1e undefined1 unknown; +20 undefined4 unknown; +24 undefined4 unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2161909 | explained |
| `0x052a0019` | VEHICLEUPGRADE_052A_0019 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined2 unknown; +15 undefined1 unknown | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0019 vf+0x64 0x17c0310 size 0x18: +0x10 ref3 vehicle, +0x13 ref3 material         -> engine 'enhance' {uid} *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2161128 | partial_layout |
| `0x052a001a` | VEHICLEUPGRADE_052A_001A *(label)* | S>C | +13 undefined3 unknown; +1e undefined2 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined1 unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0019 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2162034 | explained |
| `0x052a001b` | VEHICLEUPGRADE_052A_001B *(label)* | S>C | unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265073 | located_only |
| `0x052a001c` | VEHICLEUPGRADE_052A_001C *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a001c vf+0x6c 0x17c0450 size 0x10: close request                                   -> S>C 0x052a001d *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3187026 | partial_layout |
| `0x052a001d` | VEHICLEUPGRADE_052A_001D *(label)* | S>C | unknown | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a001c (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S123: 0x052a001c vf+0x6c 0x17c0450 size 0x10: close request                                   -> S>C 0x052a001d *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2162165 | located_only |

## 0x052b — AutoReport

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052b0005` | AUTOREPORT_052B_0005 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | AutoReport: request. Auto-report (bot/macro report) from PC dialog. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2248480 | partial_layout |
| `0x052b0006` | AUTOREPORT_052B_0006 *(label)* | S>C | +10 undefined1 unknown | AutoReport: reply/notification. Auto-report (bot/macro report) from PC dialog. Likely reply to C>S 0x052b0005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1925668 | partial_layout |

## 0x052c — CoinExchange / Exchange

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052c0000` | EXCHANGE_052C_0000 *(label)* | S>C | unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): S037: S>C 0x052c0000 open (case 0x1723820 -> 0x1723880): +0x00 u32 (npc handle), +0x04 u16 (UNVERIFIED: catalog = npc.csv JobIndex), +0x08 u32 (UNDECODED, 0) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061350 | explained |
| `0x052c0001` | EXCHANGE_052C_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 ushort unknown; +18 undefined2 unknown; +1a undefined1 unknown | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0001, size 0x18: +0x00 u32 (npc handle), +0x04 u16 a, +0x06 u16 b   (UNVERIFIED: a = catalog, b = row) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061652 | explained |
| `0x052c0002` | EXCHANGE_052C_0002 *(label)* | S>C | +60 ptr unknown; +68 char unknown; +69 char unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S037: S>C 0x052c0002 (-> 0x1723900), size 0x6a: +0x00 0x58-byte block (lea [pkt+0x10]; UNDECODED, zeros), +0x58 u8 result (handler tests == 0), +0x59 u8 (switch 0..9) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061388 | explained |
| `0x052c0003` | EXCHANGE_052C_0003 *(label)* | C>S | empty body | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0003 close, size 0x10 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167176 | partial_layout |
| `0x052c0004` | COINEXCHANGE_052C_0004 *(label)* | S>C | unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061637 | located_only |
| `0x052c0005` | EXCHANGE_052C_0005 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 ushort unknown; +18 undefined2 unknown; +1a undefined1 unknown | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0005, size 0x1c: +0x00 u32, +0x04 u16, +0x06 u16, +0x08 u16, +0x0a u8   (UNVERIFIED: catalog, row, count, kind -> engine 'store' kind) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061652 | explained |
| `0x052c0006` | EXCHANGE_052C_0006 *(label)* | S>C | +60 ptr unknown; +68 char unknown; +69 ptr unknown; +6c char unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0005 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S037: S>C 0x052c0006 (-> 0x1723c10), size 0x6d: +0x00 block, +0x58 u8 result, +0x59 bytes, +0x5c u8 (switch 0..12) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061510 | explained |
| `0x052c0007` | COINEXCHANGE_052C_0007 *(label)* | C>S | +10 undefined4 unknown | CoinExchange / Exchange: request. Coin exchange and NPC exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2203710 | partial_layout |
| `0x052c0008` | COINEXCHANGE_052C_0008 *(label)* | S>C | +10 char unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2200364 | partial_layout |
| `0x052c0009` | COINEXCHANGE_052C_0009 *(label)* | C>S | +10 undefined4 unknown | CoinExchange / Exchange: request. Coin exchange and NPC exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2203710 | partial_layout |
| `0x052c000a` | COINEXCHANGE_052C_000A *(label)* | S>C | +10 char unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2200471 | partial_layout |
| `0x052c000b` | COINEXCHANGE_052C_000B *(label)* | S>C | unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266017 | located_only |
| `0x052c000c` | COINEXCHANGE_052C_000C *(label)* | C>S | empty body | CoinExchange / Exchange: request. Coin exchange and NPC exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3194459 | partial_layout |
| `0x052c000d` | COINEXCHANGE_052C_000D *(label)* | S>C | unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266017 | located_only |
| `0x052c0010` | COINEXCHANGE_052C_0010 *(label)* | C>S | +10 undefined4 unknown | CoinExchange / Exchange: request. Coin exchange and NPC exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2203710 | partial_layout |
| `0x052c0011` | COINEXCHANGE_052C_0011 *(label)* | S>C | +10 char unknown; +18 undefined4 unknown; +1c undefined4 unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0010 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2200578 | partial_layout |
| `0x052c0012` | COINEXCHANGE_052C_0012 *(label)* | C>S | +10 undefined4 unknown | CoinExchange / Exchange: request. Coin exchange and NPC exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2203710 | partial_layout |
| `0x052c0013` | COINEXCHANGE_052C_0013 *(label)* | S>C | +10 char unknown; +18 uint unknown; +1c int unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0012 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2200603 | partial_layout |
| `0x052c0014` | COINEXCHANGE_052C_0014 *(label)* | S>C | unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266017 | located_only |
| `0x052c0015` | COINEXCHANGE_052C_0015 *(label)* | C>S | empty body | CoinExchange / Exchange: request. Coin exchange and NPC exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3194459 | partial_layout |
| `0x052c0016` | COINEXCHANGE_052C_0016 *(label)* | S>C | unknown | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266017 | located_only |

## 0x052d — Observer

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052d0000` | OBSERVER_052D_0000 *(label)* | S>C | unknown | Observer: reply/notification. Observer/spectator mode. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263755 | located_only |
| `0x052d0001` | OBSERVER_052D_0001 *(label)* | C>S | +10 undefined2 unknown | Observer: request. Observer/spectator mode. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167514 | partial_layout |
| `0x052d0002` | OBSERVER_052D_0002 *(label)* | S>C | +16 undefined2 unknown; +18 undefined2 unknown | Observer: reply/notification. Observer/spectator mode. Likely reply to C>S 0x052d0001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2062171 | partial_layout |
| `0x052d0003` | OBSERVER_052D_0003 *(label)* | C>S | +10 undefined4 unknown | Observer: request. Observer/spectator mode. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167536 | partial_layout |
| `0x052d0004` | OBSERVER_052D_0004 *(label)* | S>C | +10 int unknown; +14 undefined3 unknown; +18 undefined4 unknown; +1c ptr unknown; +22 undefined1 unknown; +24 undefined4 unknown | Observer: reply/notification. Observer/spectator mode. Likely reply to C>S 0x052d0003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061804 | partial_layout |
| `0x052d0005` | OBSERVER_052D_0005 *(label)* | C>S | empty body | Observer: request. Observer/spectator mode. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263850 | partial_layout |
| `0x052d0006` | OBSERVER_052D_0006 *(label)* | S>C | +10 int unknown; +14 ptr unknown; +1a undefined1 unknown; +1c undefined4 unknown | Observer: reply/notification. Observer/spectator mode. Likely reply to C>S 0x052d0005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061891 | partial_layout |
| `0x052d0007` | OBSERVER_052D_0007 *(label)* | C>S | +10 ptr/copy unknown | Observer: request. Observer/spectator mode. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2064821 | partial_layout |
| `0x052d0008` | OBSERVER_052D_0008 *(label)* | S>C | +10 undefined4 unknown | Observer: reply/notification. Observer/spectator mode. Likely reply to C>S 0x052d0007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2062097 | partial_layout |
| `0x052d0009` | OBSERVER_052D_0009 *(label)* | S>C | unknown | Observer: reply/notification. Observer/spectator mode. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263755 | located_only |
| `0x052d000a` | OBSERVER_052D_000A *(label)* | S>C | +10 short unknown; +12 short unknown; +14 short unknown; +16 undefined1 unknown; +18 undefined4 unknown | Observer: reply/notification. Observer/spectator mode. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2061960 | partial_layout |
| `0x052d000b` | OBSERVER_052D_000B *(label)* | S>C | +10 short unknown; +12 short unknown; +14 short unknown; +16 undefined1 unknown; +18 undefined4 unknown | Observer: reply/notification. Observer/spectator mode. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2062029 | partial_layout |

## 0x052f — Ornament events

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052f0000` | ORNAMENT_EVENTS_052F_0000 *(label)* | S>C | +19 char unknown; +1a char unknown | Ornament events: reply/notification. Ornament events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2064999 | partial_layout |
| `0x052f0001` | ORNAMENT_EVENTS_052F_0001 *(label)* | S>C | unknown | Ornament events: reply/notification. Ornament events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167677 | located_only |
| `0x052f0002` | ORNAMENT_EVENTS_052F_0002 *(label)* | S>C | +10 undefined4 unknown; +3e undefined4 unknown; +40 ushort unknown; +42 undefined2 unknown; +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined2 unknown | Ornament events: reply/notification. Ornament events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:309769 | partial_layout |
| `0x052f0003` | ORNAMENT_EVENTS_052F_0003 *(label)* | S>C | unknown | Ornament events: reply/notification. Ornament events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167677 | located_only |

## 0x0530 — Party war (NPC)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05300000` | PARTY_WAR_NPC_0530_0000 *(label)* | S>C | +10 undefined4 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1913978 | partial_layout |
| `0x05300001` | PARTY_WAR_NPC_0530_0001 *(label)* | S>C | +10 undefined4 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1913602 | partial_layout |
| `0x05300002` | PARTY_WAR_NPC_0530_0002 *(label)* | C>S | +10 undefined2 unknown | Party war (NPC): request. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197524 | partial_layout |
| `0x05300003` | PARTY_WAR_NPC_0530_0003 *(label)* | S>C | +10 undefined4 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. Likely reply to C>S 0x05300002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1913805 | partial_layout |
| `0x05300004` | PARTY_WAR_NPC_0530_0004 *(label)* | S>C | +10 int unknown; +14 int unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2067676 | partial_layout |
| `0x05300005` | PARTY_WAR_NPC_0530_0005 *(label)* | C>S | +10 undefined2 unknown | Party war (NPC): request. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197577 | partial_layout |
| `0x05300006` | PARTY_WAR_NPC_0530_0006 *(label)* | S>C | +10 undefined4 unknown; +14 undefined3 unknown; +18 int unknown; +1c undefined4 unknown; +20 undefined2 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. Likely reply to C>S 0x05300005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1914181 | partial_layout |
| `0x05300007` | PARTY_WAR_NPC_0530_0007 *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263865 | located_only |
| `0x05300008` | PARTY_WAR_NPC_0530_0008 *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2067748 | located_only |
| `0x05300009` | PARTY_WAR_NPC_0530_0009 *(label)* | S>C | +10 undefined4 unknown; +14 int unknown; +1c int unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2067827 | partial_layout |
| `0x0530000a` | PARTY_WAR_NPC_0530_000A *(label)* | S>C | +10 undefined4 unknown; +14 int unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2067942 | partial_layout |
| `0x0530000b` | PARTY_WAR_NPC_0530_000B *(label)* | S>C | +10 int unknown; +14 undefined4 unknown; +18 undefined2 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2068139 | partial_layout |
| `0x0530000c` | PARTY_WAR_NPC_0530_000C *(label)* | S>C | +10 char unknown; +12 short unknown; +14 undefined2 unknown; +18 undefined4 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2068259 | partial_layout |
| `0x0530000d` | PARTY_WAR_NPC_0530_000D *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263865 | located_only |
| `0x0530000e` | PARTY_WAR_NPC_0530_000E *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2067787 | located_only |
| `0x0530000f` | PARTY_WAR_NPC_0530_000F *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263865 | located_only |
| `0x05300010` | PARTY_WAR_NPC_0530_0010 *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263865 | located_only |
| `0x05300011` | PARTY_WAR_NPC_0530_0011 *(label)* | S>C | +10 ptr unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2068373 | partial_layout |
| `0x05300012` | PARTY_WAR_NPC_0530_0012 *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263865 | located_only |
| `0x05300013` | PARTY_WAR_NPC_0530_0013 *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263865 | located_only |
| `0x05300014` | PARTY_WAR_NPC_0530_0014 *(label)* | S>C | +10 undefined4 unknown; +14 uint unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2068042 | partial_layout |
| `0x05300015` | PARTY_WAR_NPC_0530_0015 *(label)* | C>S | empty body | Party war (NPC): request. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197552<br>decompiled-source/global-0.0.1/decompiled-named.c:3197605 | partial_layout |
| `0x0530001a` | PARTY_WAR_NPC_0530_001A *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261202<br>decompiled-source/global-0.0.1/decompiled-named.c:3261234 | located_only |
| `0x0530001b` | PARTY_WAR_NPC_0530_001B *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263865 | located_only |
| `0x0530001d` | PARTY_WAR_NPC_0530_001D *(label)* | S>C | +10 undefined1 unknown; +11 undefined1 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2068585 | partial_layout |

## 0x0531 — Observer

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05310000` | OBSERVER_0531_0000 *(label)* | S>C | unknown | Observer: reply/notification. Observer list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276303 | located_only |
| `0x05310001` | OBSERVER_0531_0001 *(label)* | C>S | +10 undefined4 unknown | Observer: request. Observer list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167536 | partial_layout |
| `0x05310002` | OBSERVER_0531_0002 *(label)* | S>C | +10 int unknown; +14 undefined3 unknown; +18 ptr unknown; +20 float unknown | Observer: reply/notification. Observer list. Likely reply to C>S 0x05310001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2062201 | partial_layout |
| `0x05310003` | OBSERVER_0531_0003 *(label)* | C>S | +10 undefined4 unknown | Observer: request. Observer list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167582 | partial_layout |
| `0x05310004` | OBSERVER_0531_0004 *(label)* | S>C | +10 int unknown; +14 ptr unknown; +1c float unknown | Observer: reply/notification. Observer list. Likely reply to C>S 0x05310003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2062279 | partial_layout |
| `0x05310005` | OBSERVER_0531_0005 *(label)* | S>C | +10 int unknown; +14 byte unknown | Observer: reply/notification. Observer list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1925434 | partial_layout |
| `0x05310006` | OBSERVER_0531_0006 *(label)* | S>C | unknown | Observer: reply/notification. Observer list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276321 | located_only |

## 0x0532 — ItemRemoveStone

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05320001` | ITEMREMOVESTONE_0532_0001 *(label)* | C>S | +14 uint unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 ptr/copy unknown; +28 undefined4 unknown | ItemRemoveStone: request. Remove stone from item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05320001 request, size 0x2c (builders 0x1733630 / 0x1733f30; body is a struct copy, pkt+0x28 u32 from [ebp-0x14]): *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2070339<br>decompiled-source/global-0.0.1/decompiled-named.c:3169307 | explained |
| `0x05320003` | ITEMREMOVESTONE_0532_0003 *(label)* | C>S | empty body | ItemRemoveStone: request. Remove stone from item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05320003 close, size 0x10 (0x17335e0) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3169067<br>decompiled-source/global-0.0.1/decompiled-named.c:3169327 | partial_layout |

## 0x0534 — Servant

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05340000` | SERVANT_0534_0000 *(label)* | S>C | unknown | Servant: reply/notification. Servant notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3158518 | located_only |

## 0x0535 — Sky teleport

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05350000` | SKY_TELEPORT_0535_0000 *(label)* | S>C | unknown | Sky teleport: reply/notification. Sky teleport NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3260374 | located_only |
| `0x05350001` | SKY_TELEPORT_0535_0001 *(label)* | S>C | unknown | Sky teleport: reply/notification. Sky teleport NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3260374 | located_only |
| `0x05350002` | SKY_TELEPORT_0535_0002 *(label)* | S>C | unknown | Sky teleport: reply/notification. Sky teleport NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1914338<br>decompiled-source/global-0.0.1/decompiled-named.c:1914362 | located_only |
| `0x05350003` | SKY_TELEPORT_0535_0003 *(label)* | C>S | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown | Sky teleport: request. Sky teleport NPC. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197630 | partial_layout |
| `0x05350004` | SKY_TELEPORT_0535_0004 *(label)* | S>C | unknown | Sky teleport: reply/notification. Sky teleport NPC. Likely reply to C>S 0x05350003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1914338<br>decompiled-source/global-0.0.1/decompiled-named.c:1914362 | located_only |

## 0x0536 — (unattributed)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05360000` | UNATTRIBUTED_0536_0000 *(label)* | S>C | +10 undefined4 unknown; +14 undefined2 unknown; +16 char unknown | (unattributed): reply/notification. Unattributed family. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1951212 | partial_layout |

## 0x0537 — Pet

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05370000` | PET_0537_0000 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c ptr unknown; +44 undefined4 unknown; +48 undefined1 unknown; +4c int unknown | Pet: reply/notification. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:197212<br>decompiled-source/global-0.0.1/decompiled-named.c:310287 | partial_layout |
| `0x05370001` | PET_0537_0001 *(label)* | C>S | +10 undefined4 unknown | Pet: request. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2081132 | partial_layout |
| `0x05370002` | PET_0537_0002 *(label)* | S>C | +10 char unknown | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083155 | partial_layout |
| `0x05370003` | PET_0537_0003 *(label)* | C>S | empty body | Pet: request. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3170771 | partial_layout |
| `0x05370004` | PET_0537_0004 *(label)* | C>S | +10 ptr/copy unknown | Pet: request. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2081335 | partial_layout |
| `0x05370005` | PET_0537_0005 *(label)* | S>C | +10 char unknown | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083012 | partial_layout |
| `0x05370006` | PET_0537_0006 *(label)* | S>C | +10 char unknown; +18 undefined4 unknown | Pet: reply/notification. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083230 | partial_layout |
| `0x05370008` | PET_0537_0008 *(label)* | S>C | unknown | Pet: reply/notification. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082576 | located_only |
| `0x05370009` | PET_0537_0009 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Pet: request. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3171000 | partial_layout |
| `0x05370010` | PET_0537_0010 *(label)* | S>C | +10 undefined1 unknown; +18 undefined8 unknown; +20 undefined4 unknown | Pet: reply/notification. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083624 | partial_layout |
| `0x05370011` | PET_0537_0011 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined2 unknown; +15 undefined1 unknown; +16 undefined2 unknown; +18 undefined1 unknown; +19 undefined1 unknown | Pet: request. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3171058 | partial_layout |
| `0x05370012` | PET_0537_0012 *(label)* | S>C | +10 undefined1 unknown | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083816 | partial_layout |
| `0x05370015` | PET_0537_0015 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Pet: request. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3171029 | partial_layout |
| `0x05370016` | PET_0537_0016 *(label)* | S>C | +10 undefined1 unknown | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083728 | partial_layout |
| `0x05370017` | PET_0537_0017 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined1 unknown | Pet: request. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082301 | partial_layout |
| `0x05370018` | PET_0537_0018 *(label)* | S>C | +10 char unknown | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082659 | partial_layout |
| `0x05370019` | PET_0537_0019 *(label)* | C>S | empty body | Pet: request. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2081409 | partial_layout |
| `0x05370020` | PET_0537_0020 *(label)* | S>C | +10 char unknown | Pet: reply/notification. Pet summon/feed/inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083072 | partial_layout |

## 0x0538 — Pet

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05380000` | PET_0538_0000 *(label)* | C>S | empty body | Pet: request. Pet UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3170885 | partial_layout |
| `0x05380001` | PET_0538_0001 *(label)* | S>C | unknown | Pet: reply/notification. Pet UI. Likely reply to C>S 0x05380000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082576 | located_only |
| `0x05380002` | PET_0538_0002 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined1 unknown; +14 undefined2 unknown | Pet: request. Pet UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082449<br>decompiled-source/global-0.0.1/decompiled-named.c:3170849 | partial_layout |
| `0x05380003` | PET_0538_0003 *(label)* | S>C | +10 char unknown; +11 char unknown | Pet: reply/notification. Pet UI. Likely reply to C>S 0x05380002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083302 | partial_layout |
| `0x05380004` | PET_0538_0004 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | Pet: reply/notification. Pet UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083528 | partial_layout |
| `0x05380005` | PET_0538_0005 *(label)* | S>C | +10 ptr unknown | Pet: reply/notification. Pet UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083912 | partial_layout |
| `0x05380006` | PET_0538_0006 *(label)* | C>S | unknown | Pet: request. Pet UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082433 | located_only |
| `0x05380007` | PET_0538_0007 *(label)* | S>C | +10 ptr unknown; +16 short unknown; +18 undefined4 unknown | Pet: reply/notification. Pet UI. Likely reply to C>S 0x05380006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2083974 | partial_layout |

## 0x0539 — Troop

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05390000` | TROOP_0539_0000 *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264002 | located_only |
| `0x05390001` | TROOP_0539_0001 *(label)* | C>S | +10 ptr/copy unknown | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091827 | partial_layout |
| `0x05390002` | TROOP_0539_0002 *(label)* | S>C | +10 undefined1 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 undefined8 unknown; +40 undefined2 unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2090632 | partial_layout |
| `0x05390003` | TROOP_0539_0003 *(label)* | both | +10 ptr/copy unknown; +3a ptr/copy unknown; +66 ptr/copy unknown; +90 undefined1 unknown | Troop: request and reply share this opcode. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091594<br>decompiled-source/global-0.0.1/decompiled-named.c:2091874<br>decompiled-source/global-0.0.1/decompiled-named.c:2248221 | partial_layout |
| `0x05390004` | TROOP_0539_0004 *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2090759 | located_only |
| `0x05390005` | TROOP_0539_0005 *(label)* | both | +10 undefined1 unknown; +12 undefined2 unknown; +3c undefined2 unknown; +66 undefined1 unknown; +68 undefined2 unknown; +92 undefined1 unknown | Troop: request and reply share this opcode. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091594<br>decompiled-source/global-0.0.1/decompiled-named.c:2092117<br>decompiled-source/global-0.0.1/decompiled-named.c:3264002 | partial_layout |
| `0x05390006` | TROOP_0539_0006 *(label)* | C>S | +10 ptr/copy unknown; +3a undefined1 unknown | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091973<br>decompiled-source/global-0.0.1/decompiled-named.c:2092067 | partial_layout |
| `0x05390007` | TROOP_0539_0007 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 byte unknown; +1a undefined4 unknown; +1e undefined4 unknown; +22 undefined4 unknown; +26 undefined4 unknown; +2a undefined4 unknown; +2e undefined4 unknown; +32 undefined4 unknown; +36 undefined4 unknown; +3a undefined8 unknown; +42 undefined2 unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2090780 | partial_layout |
| `0x05390008` | TROOP_0539_0008 *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2090853 | located_only |
| `0x05390009` | TROOP_0539_0009 *(label)* | C>S | empty body | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3172939 | partial_layout |
| `0x0539000a` | TROOP_0539_000A *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2090874 | located_only |
| `0x0539000b` | TROOP_0539_000B *(label)* | C>S | empty body | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3173011 | partial_layout |
| `0x0539000c` | TROOP_0539_000C *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x0539000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264002 | located_only |
| `0x0539000d` | TROOP_0539_000D *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264002 | located_only |
| `0x0539000e` | TROOP_0539_000E *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264002 | located_only |
| `0x0539000f` | TROOP_0539_000F *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264002 | located_only |
| `0x05390010` | TROOP_0539_0010 *(label)* | C>S | +10 ptr/copy unknown | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2092020 | partial_layout |
| `0x05390011` | TROOP_0539_0011 *(label)* | S>C | +10 char unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390010 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2090969 | partial_layout |
| `0x05390012` | TROOP_0539_0012 *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091033 | located_only |
| `0x05390013` | TROOP_0539_0013 *(label)* | C>S | +10 undefined4 unknown | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3172987 | partial_layout |
| `0x05390014` | TROOP_0539_0014 *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091237 | located_only |
| `0x05390015` | TROOP_0539_0015 *(label)* | S>C | +10 undefined4 unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091281 | partial_layout |
| `0x05390016` | TROOP_0539_0016 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 undefined4 unknown; +3c undefined4 unknown; +40 undefined4 unknown; +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined8 unknown | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3173059 | partial_layout |
| `0x05390017` | TROOP_0539_0017 *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390016 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091548 | located_only |
| `0x05390018` | TROOP_0539_0018 *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264002 | located_only |
| `0x05390019` | TROOP_0539_0019 *(label)* | C>S | +10 undefined4 unknown | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3173035 | partial_layout |
| `0x0539001a` | TROOP_0539_001A *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390019 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091504 | located_only |
| `0x0539001b` | TROOP_0539_001B *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264002 | located_only |
| `0x0539001c` | TROOP_0539_001C *(label)* | C>S | +10 undefined4 unknown | Troop: request. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3172959 | partial_layout |
| `0x0539001d` | TROOP_0539_001D *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x0539001c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091107 | located_only |
| `0x0539001e` | TROOP_0539_001E *(label)* | S>C | +10 int unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091128 | partial_layout |
| `0x0539001f` | TROOP_0539_001F *(label)* | S>C | +10 undefined1 unknown; +11 char unknown; +14 undefined4 unknown; +18 int unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2091350 | partial_layout |
| `0x05390020` | TROOP_0539_0020 *(label)* | S>C | +10 char unknown; +11 char unknown | Troop: reply/notification. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946268 | partial_layout |
| `0x05390021` | TROOP_0539_0021 *(label)* | both | +10 undefined4 unknown; +14 short unknown; +18 undefined4 unknown; +3c undefined1 unknown; +40 undefined4 unknown; +214 undefined4 unknown | Troop: request and reply share this opcode. Troop (team) create/rename/leave. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1922204<br>decompiled-source/global-0.0.1/decompiled-named.c:1925222 | partial_layout |
| `0x05390022` | TROOP_0539_0022 *(label)* | S>C | unknown | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390021 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264002 | located_only |

## 0x053a — OptionUpgrade

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x053a0001` | OPTIONUPGRADE_053A_0001 *(label)* | C>S | unknown | OptionUpgrade: request. Item option upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x053a0001 request, size 0x2c (ctor 0x1758170, filled at 0x1757220 from UI slot getters vf+0x28..+0x3c). Body offsets: *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2093495 | located_only |
| `0x053a0003` | OPTIONUPGRADE_053A_0003 *(label)* | C>S | empty body | OptionUpgrade: request. Item option upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x053a0003 close, size 0x10 (0x1757070) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3173604 | partial_layout |

## 0x053b — PartyPVP

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x053b0000` | PARTYPVP_053B_0000 *(label)* | C>S | +10 undefined4 unknown; +14 ptr/copy unknown; +3e undefined1 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1819586 | partial_layout |
| `0x053b0001` | PARTYPVP_053B_0001 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0002` | PARTYPVP_053B_0002 *(label)* | S>C | +10 ptr unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853489 | partial_layout |
| `0x053b0003` | PARTYPVP_053B_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined1 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1863241<br>decompiled-source/global-0.0.1/decompiled-named.c:1863618<br>decompiled-source/global-0.0.1/decompiled-named.c:1863643 … | partial_layout |
| `0x053b0004` | PARTYPVP_053B_0004 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0005` | PARTYPVP_053B_0005 *(label)* | S>C | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined1 unknown; +14 undefined2 unknown; +16 undefined1 unknown; +18 ptr unknown; +6c undefined4 unknown; +70 undefined4 unknown; +76 undefined1 unknown; +78 char unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853686 | partial_layout |
| `0x053b0006` | PARTYPVP_053B_0006 *(label)* | C>S | +10 undefined1 unknown; +12 undefined2 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1a undefined1 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3137694 | partial_layout |
| `0x053b0007` | PARTYPVP_053B_0007 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0008` | PARTYPVP_053B_0008 *(label)* | S>C | +10 byte unknown; +12 undefined2 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1a undefined1 unknown; +1b char unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853648 | partial_layout |
| `0x053b0009` | PARTYPVP_053B_0009 *(label)* | C>S | +10 ptr/copy unknown; +3a undefined1 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1863181 | partial_layout |
| `0x053b0010` | PARTYPVP_053B_0010 *(label)* | S>C | +3a byte unknown; +3b byte unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853589 | partial_layout |
| `0x053b0011` | PARTYPVP_053B_0011 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0013` | PARTYPVP_053B_0013 *(label)* | C>S | +10 ptr/copy unknown; +3a undefined1 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1819538 | partial_layout |
| `0x053b0014` | PARTYPVP_053B_0014 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0015` | PARTYPVP_053B_0015 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853791 | located_only |
| `0x053b0016` | PARTYPVP_053B_0016 *(label)* | S>C | +10 undefined1 unknown; +324 undefined1 unknown; +325 undefined1 unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853828 | partial_layout |
| `0x053b0019` | PARTYPVP_053B_0019 *(label)* | C>S | empty body | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3137752 | partial_layout |
| `0x053b0020` | PARTYPVP_053B_0020 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0021` | PARTYPVP_053B_0021 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0022` | PARTYPVP_053B_0022 *(label)* | C>S | empty body | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3137727 | partial_layout |
| `0x053b0023` | PARTYPVP_053B_0023 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0022 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0024` | PARTYPVP_053B_0024 *(label)* | C>S | +10 undefined4 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167536 | partial_layout |
| `0x053b0025` | PARTYPVP_053B_0025 *(label)* | S>C | +10 char unknown; +12 ptr unknown; +18 float unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0024 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2062349 | partial_layout |
| `0x053b0026` | PARTYPVP_053B_0026 *(label)* | C>S | +10 undefined4 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3167582 | partial_layout |
| `0x053b0027` | PARTYPVP_053B_0027 *(label)* | S>C | +10 char unknown; +12 ptr unknown; +18 float unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0026 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2062417 | partial_layout |
| `0x053b0028` | PARTYPVP_053B_0028 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256970 | located_only |
| `0x053b0029` | PARTYPVP_053B_0029 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263755 | located_only |
| `0x053b0030` | PARTYPVP_053B_0030 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263755 | located_only |
| `0x053b0031` | PARTYPVP_053B_0031 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853899 | located_only |
| `0x053b0032` | PARTYPVP_053B_0032 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3137777 | partial_layout |
| `0x053b0033` | PARTYPVP_053B_0033 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0032 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853930 | located_only |
| `0x053b0035` | PARTYPVP_053B_0035 *(label)* | C>S | +10 undefined8 unknown; +18 undefined2 unknown | PartyPVP: request. Party PVP matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3137799 | partial_layout |
| `0x053b0036` | PARTYPVP_053B_0036 *(label)* | S>C | unknown | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0035 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1853967 | located_only |

## 0x053c — DKSquare / Arena

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x053c0003` | Ghost::GameHandler::DKSquare::State::Lobby::Lobby | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1820559 | located_only |
| `0x053c0011` | DKSQUARE_053C_0011 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1809816 | located_only |
| `0x053c0012` | DKSQUARE_053C_0012 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0016` | UIString::UIString | S>C | +1c undefined4 unknown; +20 undefined4 unknown; +3c undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +62 undefined2 unknown; +68 undefined4 unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:306764 | partial_layout |
| `0x053c0017` | DKSQUARE_053C_0017 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0018` | DKSQUARE_053C_0018 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145540 | located_only |
| `0x053c001a` | DKSQUARE_053C_001A *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145540 | located_only |
| `0x053c001b` | DKSQUARE_053C_001B *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c001c` | DKSQUARE_053C_001C *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c001d` | DKSQUARE_053C_001D *(label)* | C>S | empty body | DKSquare / Arena: request. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3138892 | partial_layout |
| `0x053c001e` | DKSQUARE_053C_001E *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. Likely reply to C>S 0x053c001d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:35416 | partial_layout |
| `0x053c001f` | DKSQUARE_053C_001F *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:35416 | partial_layout |
| `0x053c0020` | DKSQUARE_053C_0020 *(label)* | C>S | empty body | DKSquare / Arena: request. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3138867 | partial_layout |
| `0x053c0021` | DKSQUARE_053C_0021 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. Likely reply to C>S 0x053c0020 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0022` | DKSQUARE_053C_0022 *(label)* | C>S | +10 undefined4 unknown | DKSquare / Arena: request. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1809914 | partial_layout |
| `0x053c0023` | DKSQUARE_053C_0023 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. Likely reply to C>S 0x053c0022 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0024` | DKSQUARE_053C_0024 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0025` | DKSQUARE_053C_0025 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0026` | DKSQUARE_053C_0026 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0027` | DKSQUARE_053C_0027 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0028` | DKSQUARE_053C_0028 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:49516 | located_only |
| `0x053c0029` | DKSQUARE_053C_0029 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0032` | Ghost::GameHandler::DKSquare::State::Battle::Battle | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1813462 | located_only |
| `0x053c0033` | DKSQUARE_053C_0033 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0034` | DKSQUARE_053C_0034 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1821070 | located_only |
| `0x053c0035` | Ghost::GameHandler::DKSquare::State::Battle::Battle | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1813462 | located_only |
| `0x053c0036` | DKSQUARE_053C_0036 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1654714 | located_only |
| `0x053c0038` | Ghost::GameHandler::Message::DKSquare::ShowUrbanWaitUI::ShowUrbanWaitUI | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1875474 | located_only |
| `0x053c0039` | UIString::UIString | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1878473 | located_only |
| `0x053c003b` | UIString::UIString | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1870691 | located_only |
| `0x053c003c` | DKSQUARE_053C_003C *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:35416 | partial_layout |
| `0x053c003d` | DKSQUARE_053C_003D *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:35416 | partial_layout |
| `0x053c003e` | DKSQUARE_053C_003E *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:36553 | located_only |
| `0x053c003f` | DKSQUARE_053C_003F *(label)* | C>S | empty body | DKSquare / Arena: request. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257086 | partial_layout |
| `0x053c0040` | DKSQUARE_053C_0040 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. Likely reply to C>S 0x053c003f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1878681 | located_only |
| `0x053c0041` | DKSQUARE_053C_0041 *(label)* | S>C | +10 byte unknown; +14 undefined4 unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1878698 | partial_layout |
| `0x053c0042` | DKSQUARE_053C_0042 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0043` | DKSQUARE_053C_0043 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0044` | Ghost::GameHandler::DKSquare::State::Lobby::Lobby | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1820559 | located_only |
| `0x053c0045` | DKSQUARE_053C_0045 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0046` | DKSQUARE_053C_0046 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0048` | DKSQUARE_053C_0048 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x053c0049` | DKSQUARE_053C_0049 *(label)* | S>C | unknown | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |

## 0x053d — CharacterTrade

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x053d0003` | CHARACTERTRADE_053D_0003 *(label)* | S>C | +10 undefined4 unknown | CharacterTrade: reply/notification. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110946 | partial_layout |
| `0x053d0007` | CHARACTERTRADE_053D_0007 *(label)* | S>C | +10 int unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown | CharacterTrade: reply/notification. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110738 | partial_layout |
| `0x053d0008` | CHARACTERTRADE_053D_0008 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | CharacterTrade: reply/notification. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110898 | partial_layout |
| `0x053d000a` | CHARACTERTRADE_053D_000A *(label)* | S>C | +10 undefined4 unknown | CharacterTrade: reply/notification. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1943330 | partial_layout |
| `0x053d000b` | CHARACTERTRADE_053D_000B *(label)* | S>C | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined4 unknown; +50 ptr unknown; +5c undefined4 unknown; +60 int unknown | CharacterTrade: reply/notification. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111668 | partial_layout |
| `0x053d000d` | CHARACTERTRADE_053D_000D *(label)* | S>C | unknown | CharacterTrade: reply/notification. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110696 | located_only |
| `0x053d001b` | CHARACTERTRADE_053D_001B *(label)* | C>S | +10 ptr/copy unknown | CharacterTrade: request. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111600 | partial_layout |
| `0x053d001c` | CHARACTERTRADE_053D_001C *(label)* | S>C | unknown | CharacterTrade: reply/notification. Character trade market. Likely reply to C>S 0x053d001b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111196 | located_only |
| `0x053d001d` | CHARACTERTRADE_053D_001D *(label)* | S>C | +10 undefined4 unknown | CharacterTrade: reply/notification. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111076 | partial_layout |
| `0x053d001e` | CHARACTERTRADE_053D_001E *(label)* | C>S | +10 undefined1 unknown | CharacterTrade: request. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177314 | partial_layout |
| `0x053d001f` | CHARACTERTRADE_053D_001F *(label)* | S>C | unknown | CharacterTrade: reply/notification. Character trade market. Likely reply to C>S 0x053d001e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111164 | located_only |
| `0x053d0020` | CHARACTERTRADE_053D_0020 *(label)* | S>C | +10 char unknown | CharacterTrade: reply/notification. Character trade market. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111181 | partial_layout |

## 0x053e — (unattributed)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x053e0010` | UNATTRIBUTED_053E_0010 *(label)* | S>C | +10 ptr unknown | (unattributed): reply/notification. Unattributed family. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898750 | partial_layout |

## 0x053f — Quest

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x053f0000` | QUEST_053F_0000 *(label)* | S>C | +10 undefined4 unknown | Quest: reply/notification. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898674 | partial_layout |
| `0x053f0001` | QUEST_053F_0001 *(label)* | C>S | +10 undefined4 unknown; +14 short unknown | Quest: request. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3143192 | partial_layout |
| `0x053f0002` | QUEST_053F_0002 *(label)* | S>C | +10 char unknown | Quest: reply/notification. Quest UI. Likely reply to C>S 0x053f0001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898685 | partial_layout |
| `0x053f0004` | QUEST_053F_0004 *(label)* | S>C | +10 undefined4 unknown | Quest: reply/notification. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898712 | partial_layout |

## 0x0541 — Target

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05410000` | TARGET_0541_0000 *(label)* | S>C | unknown | Target: reply/notification. Target net handler. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3156339 | located_only |
| `0x05410001` | TARGET_0541_0001 *(label)* | C>S | +10 undefined2 unknown; +14 undefined4 unknown | Target: request. Target net handler. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1999672 | partial_layout |
| `0x05410002` | TARGET_0541_0002 *(label)* | C>S | +10 undefined2 unknown | Target: request. Target net handler. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3156358 | partial_layout |

## 0x0542 — (unattributed)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05420000` | UNATTRIBUTED_0542_0000 *(label)* | S>C | +10 undefined4 unknown; +14 int unknown; +18 undefined2 unknown; +1c int unknown; +20 undefined4 unknown; +24 uint unknown; +33 char unknown | (unattributed): reply/notification. Unattributed family. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:310483 | partial_layout |
| `0x05420003` | UNATTRIBUTED_0542_0003 *(label)* | S>C | +14 undefined4 unknown; +18 char unknown | (unattributed): reply/notification. Unattributed family. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:308539 | partial_layout |

## 0x0543 — Storage

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05430000` | STORAGE_0543_0000 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined1 unknown | Storage: request. Storage extension. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151825 | partial_layout |
| `0x05430001` | STORAGE_0543_0001 *(label)* | S>C | +10 undefined1 unknown; +11 char unknown | Storage: reply/notification. Storage extension. Likely reply to C>S 0x05430000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949737 | partial_layout |
| `0x05430002` | STORAGE_0543_0002 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Storage: request. Storage extension. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151857 | partial_layout |
| `0x05430003` | STORAGE_0543_0003 *(label)* | S>C | +10 undefined1 unknown | Storage: reply/notification. Storage extension. Likely reply to C>S 0x05430002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949854 | partial_layout |
| `0x05430004` | STORAGE_0543_0004 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Storage: request. Storage extension. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3151888 | partial_layout |
| `0x05430005` | STORAGE_0543_0005 *(label)* | S>C | +10 undefined1 unknown | Storage: reply/notification. Storage extension. Likely reply to C>S 0x05430004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1949930 | partial_layout |

## 0x0544 — Party

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05440001` | PARTY_0544_0001 *(label)* | C>S | +10 ptr/copy unknown | Party: request. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2232200 | partial_layout |
| `0x05440002` | PARTY_0544_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +44 undefined1 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S080: S>C 0x05440002 PARTY FORMED, handler 0x161be60: +0x10 i32 result (0 ok -> 70:59; 1..10 -> 70:0x5d,0x5e,0x3c..0x40,0x57,0x9c), *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1889685 | partial_layout |
| `0x05440003` | PARTY_0544_0003 *(label)* | both | +10 undefined2 unknown; +40 undefined8 unknown; +48 undefined2 unknown; +72 undefined2 unknown; +9c undefined1 unknown; +9d undefined1 unknown; +a0 undefined4 unknown | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05440003 INVITE  size 0xa8, builder 0x1619230 (UIHandler@Party; msg 70:12 "Invite %s to your Party.", 70:163) S>C 0x05440003 same struct relayed to the target; handler 0x161eaf0 reads +0x40/+0x44, +0x48 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1820962<br>decompiled-source/global-0.0.1/decompiled-named.c:1887941<br>decompiled-source/global-0.0.1/decompiled-named.c:1888671 … | partial_layout |
| `0x05440004` | PARTY_0544_0004 *(label)* | S>C | +10 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890838 | partial_layout |
| `0x05440005` | PARTY_0544_0005 *(label)* | both | +10 undefined1 unknown; +12 ptr/copy unknown; +3c ptr/copy unknown; +66 undefined1 unknown; +67 undefined1 unknown | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05440005 DECLINE size 0x68, builder 0x1620fa0: +0x10 u8 reason (client sends 2), +0x12 wchar[21] name B, S>C 0x05440005 decline relay, handler 0x161dd30: +0x10 u8 reason, +0x12 wchar[21] name -> 70:10/7 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890981<br>decompiled-source/global-0.0.1/decompiled-named.c:1891596<br>decompiled-source/global-0.0.1/decompiled-named.c:1893212 | explained |
| `0x05440006` | PARTY_0544_0006 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 ptr/copy unknown; +42 undefined1 unknown; +43 undefined1 unknown | Party: request. Party invite/accept/leave/kick/leader/options. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05440006 ACCEPT  size 0x48, builder 0x1620ec0: +0x10 u64 partyId (from invite +0x40), +0x18 wchar[21] name A, *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1893159 | partial_layout |
| `0x05440007` | PARTY_0544_0007 *(label)* | S>C | +40 undefined4 unknown; +44 undefined4 unknown; +48 undefined1 unknown; +4c undefined1 unknown; +50 undefined1 unknown; +54 undefined4 unknown; +58 char unknown; +5c undefined4 unknown; +60 char unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440006 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S080: S>C 0x05440007 MEMBER JOINED, handler 0x161c000: +0x10 wchar[21] name, +0x40 u64 partyId, +0x48 u8, +0x4c u8, +0x50 u8, *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1889770 | explained |
| `0x05440008` | PARTY_0544_0008 *(label)* | S>C | +10 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890899 | partial_layout |
| `0x05440009` | PARTY_0544_0009 *(label)* | C>S | empty body | Party: request. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3196664<br>decompiled-source/global-0.0.1/decompiled-named.c:3196831 | partial_layout |
| `0x0544000a` | PARTY_0544_000A *(label)* | S>C | +10 char unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1889823 | partial_layout |
| `0x0544000b` | PARTY_0544_000B *(label)* | S>C | +48 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1889871 | partial_layout |
| `0x0544000c` | PARTY_0544_000C *(label)* | S>C | +3a undefined1 unknown; +3c undefined2 unknown; +3e undefined1 unknown; +3f undefined1 unknown; +40 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1892070 | partial_layout |
| `0x0544000d` | PARTY_0544_000D *(label)* | S>C | unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Prior-build note (43.3.0, INFERRED for 0.0.1): S080: S>C 0x0544000d MEMBER LEFT, handler 0x161f210: +0x10 wchar[21] name, +0x3a u8 -> 70:1 "has left the Party." *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891907 | explained |
| `0x0544000f` | PARTY_0544_000F *(label)* | S>C | +10 ushort unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1892121 | partial_layout |
| `0x05440010` | PARTY_0544_0010 *(label)* | C>S | +10 undefined2 unknown; +12 undefined2 unknown; +14 byte unknown; +16 ushort unknown; +18 undefined1 unknown; +1d byte unknown; +1e ptr/copy unknown | Party: request. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1888501 | explained |
| `0x05440012` | PARTY_0544_0012 *(label)* | S>C | +10 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891065 | explained |
| `0x05440013` | PARTY_0544_0013 *(label)* | C>S | +10 byte unknown | Party: request. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1888468 | partial_layout |
| `0x05440014` | PARTY_0544_0014 *(label)* | S>C | +10 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891124 | partial_layout |
| `0x05440015` | PARTY_0544_0015 *(label)* | both | empty body | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891575<br>decompiled-source/global-0.0.1/decompiled-named.c:3142229 | partial_layout |
| `0x05440016` | PARTY_0544_0016 *(label)* | both | empty body | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891824<br>decompiled-source/global-0.0.1/decompiled-named.c:3142209 | partial_layout |
| `0x05440017` | PARTY_0544_0017 *(label)* | both | +10 uint unknown | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890755<br>decompiled-source/global-0.0.1/decompiled-named.c:3196684 | explained |
| `0x05440018` | PARTY_0544_0018 *(label)* | S>C | unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1892219 | located_only |
| `0x05440019` | PARTY_0544_0019 *(label)* | S>C | unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1892271 | located_only |
| `0x0544001a` | PARTY_0544_001A *(label)* | S>C | +10 undefined1 unknown; +12 undefined2 unknown; +14 undefined2 unknown; +16 undefined1 unknown; +18 undefined1 unknown; +19 undefined1 unknown; +1a undefined8 unknown; +22 undefined4 unknown; +26 undefined2 unknown; +28 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891838 | partial_layout |
| `0x0544001b` | PARTY_0544_001B *(label)* | C>S | +10 byte unknown | Party: request. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1888087 | partial_layout |
| `0x0544001c` | PARTY_0544_001C *(label)* | S>C | +10 undefined1 unknown; +11 undefined1 unknown; +14 ptr unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x0544001b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891173 | partial_layout |
| `0x0544001d` | PARTY_0544_001D *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Party: request. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3142187 | partial_layout |
| `0x0544001e` | PARTY_0544_001E *(label)* | S>C | +10 undefined1 unknown; +3c byte unknown; +3e ptr unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x0544001d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891224 | partial_layout |
| `0x0544001f` | PARTY_0544_001F *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1a ptr/copy unknown | Party: request. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1888120<br>decompiled-source/global-0.0.1/decompiled-named.c:1888165 | partial_layout |
| `0x05440020` | PARTY_0544_0020 *(label)* | both | +10 ulonglong unknown; +42 undefined2 unknown; +44 undefined4 unknown; +48 undefined1 unknown; +50 ptr unknown; +68 undefined8 unknown; +70 undefined2 unknown; +74 undefined4 unknown; +78 char unknown | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1888269<br>decompiled-source/global-0.0.1/decompiled-named.c:1891423 | partial_layout |
| `0x05440021` | PARTY_0544_0021 *(label)* | both | +10 ulonglong unknown; +42 undefined2 unknown; +44 undefined4 unknown; +68 undefined8 unknown; +70 undefined2 unknown; +74 undefined4 unknown; +78 char unknown; +80 ptr unknown | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1888269<br>decompiled-source/global-0.0.1/decompiled-named.c:1891344 | partial_layout |
| `0x05440022` | PARTY_0544_0022 *(label)* | S>C | +10 ulonglong unknown; +18 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440021 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1891501 | partial_layout |
| `0x05440023` | PARTY_0544_0023 *(label)* | C>S | +10 ptr/copy unknown; +3a undefined1 unknown | Party: request. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1888221 | explained |
| `0x05440024` | PARTY_0544_0024 *(label)* | S>C | +10 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440023 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1892283 | partial_layout |
| `0x05440025` | PARTY_0544_0025 *(label)* | S>C | +10 char unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1893319 | partial_layout |
| `0x05440026` | PARTY_0544_0026 *(label)* | S>C | +10 char unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1893336 | partial_layout |
| `0x05440027` | PARTY_0544_0027 *(label)* | S>C | +10 int unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1893353 | partial_layout |
| `0x05440028` | PARTY_0544_0028 *(label)* | S>C | +10 ptr unknown; +3a char unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1893367 | partial_layout |
| `0x05440029` | PARTY_0544_0029 *(label)* | S>C | +10 undefined1 unknown | Party: reply/notification. Party invite/accept/leave/kick/leader/options. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1893522 | partial_layout |

## 0x0545 — Party (notify/chat)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05450000` | PARTY_NOTIFY_0545_0000 *(label)* | both | +10 ptr/copy unknown | Party (notify/chat): request and reply share this opcode. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890303<br>decompiled-source/global-0.0.1/decompiled-named.c:2232383 | partial_layout |
| `0x05450003` | Ghost::GameHandler::Message::Party::LeaveParty::LeaveParty | both | +10 ptr/copy unknown; +3a undefined1 unknown | Party (notify/chat): request and reply share this opcode. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1885569<br>decompiled-source/global-0.0.1/decompiled-named.c:2232330 | partial_layout |
| `0x05450004` | PARTY_NOTIFY_0545_0004 *(label)* | S>C | +10 byte unknown | Party (notify/chat): reply/notification. Party notifications and party chat. Likely reply to C>S 0x05450003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890181 | partial_layout |
| `0x05450005` | PARTY_0545_0005 *(label)* | both | +3a undefined1 unknown | Party (notify/chat): request and reply share this opcode. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890210<br>decompiled-source/global-0.0.1/decompiled-named.c:2232430 | explained |
| `0x05450006` | PARTY_NOTIFY_0545_0006 *(label)* | C>S | empty body | Party (notify/chat): request. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3131249 | partial_layout |
| `0x05450007` | PARTY_NOTIFY_0545_0007 *(label)* | S>C | +10 undefined4 unknown; +18 undefined1 unknown; +19 byte unknown; +1a byte unknown | Party (notify/chat): reply/notification. Party notifications and party chat. Likely reply to C>S 0x05450006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890372 | partial_layout |
| `0x05450008` | PARTY_NOTIFY_0545_0008 *(label)* | S>C | +10 undefined4 unknown; +1a undefined2 unknown | Party (notify/chat): reply/notification. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890464 | partial_layout |
| `0x05450009` | PARTY_NOTIFY_0545_0009 *(label)* | S>C | +10 undefined4 unknown | Party (notify/chat): reply/notification. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890542 | partial_layout |
| `0x0545000a` | PARTY_NOTIFY_0545_000A *(label)* | S>C | +10 undefined4 unknown; +1a ushort unknown; +1c ushort unknown | Party (notify/chat): reply/notification. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890526 | partial_layout |
| `0x0545000b` | PARTY_NOTIFY_0545_000B *(label)* | S>C | +10 undefined4 unknown; +1a undefined2 unknown | Party (notify/chat): reply/notification. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890511 | partial_layout |
| `0x0545000c` | PARTY_NOTIFY_0545_000C *(label)* | both | +10 undefined4 unknown; +18 undefined4 unknown; +3a ushort unknown; +3c undefined1 unknown; +40 undefined4 unknown; +44 undefined4 unknown; +214 undefined4 unknown | Party (notify/chat): request and reply share this opcode. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1922204<br>decompiled-source/global-0.0.1/decompiled-named.c:1925012 | partial_layout |
| `0x0545000d` | PARTY_NOTIFY_0545_000D *(label)* | S>C | +10 undefined1 unknown; +11 char unknown; +14 undefined4 unknown; +18 int unknown | Party (notify/chat): reply/notification. Party notifications and party chat. Likely reply to C>S 0x0545000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890569 | partial_layout |
| `0x0545000e` | PARTY_NOTIFY_0545_000E *(label)* | S>C | +10 char unknown; +4e char unknown | Party (notify/chat): reply/notification. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1943930 | partial_layout |
| `0x05450011` | PARTY_NOTIFY_0545_0011 *(label)* | S>C | +10 undefined4 unknown; +1a undefined2 unknown; +1c undefined2 unknown; +1e undefined2 unknown; +20 undefined2 unknown | Party (notify/chat): reply/notification. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890554 | partial_layout |
| `0x05450012` | PARTY_NOTIFY_0545_0012 *(label)* | S>C | unknown | Party (notify/chat): reply/notification. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1890477 | located_only |
| `0x05450013` | PARTY_NOTIFY_0545_0013 *(label)* | C>S | unknown | Party (notify/chat): request. Party notifications and party chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2154277<br>decompiled-source/global-0.0.1/decompiled-named.c:2223398 | located_only |
| `0x05450014` | PARTY_NOTIFY_0545_0014 *(label)* | S>C | unknown | Party (notify/chat): reply/notification. Party notifications and party chat. Likely reply to C>S 0x05450013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3185733 | located_only |

## 0x0546 — Party

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05460000` | PARTY_0546_0000 *(label)* | C>S | +10 undefined1 unknown | Party: request. Party UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3142249 | partial_layout |
| `0x05460001` | PARTY_0546_0001 *(label)* | S>C | +10 undefined1 unknown; +11 byte unknown | Party: reply/notification. Party UI. Likely reply to C>S 0x05460000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1892345 | partial_layout |

## 0x0547 — CashItem

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05470000` | CASHITEM_0547_0000 *(label)* | S>C | +10 undefined1 unknown; +14 undefined4 unknown; +18 undefined4 unknown | CashItem: reply/notification. Cash item use. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276000 | partial_layout |
| `0x05470001` | CASHITEM_0547_0001 *(label)* | S>C | +10 undefined1 unknown | CashItem: reply/notification. Cash item use. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038035 | partial_layout |
| `0x05470002` | CASHITEM_0547_0002 *(label)* | C>S | +10 undefined2 unknown | CashItem: request. Cash item use. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3163237 | partial_layout |
| `0x05470003` | CASHITEM_0547_0003 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1a undefined1 unknown; +1c undefined4 unknown | CashItem: reply/notification. Cash item use. Likely reply to C>S 0x05470002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038277 | partial_layout |
| `0x05470004` | CASHITEM_0547_0004 *(label)* | C>S | +10 undefined2 unknown | CashItem: request. Cash item use. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3163267 | partial_layout |
| `0x05470005` | CASHITEM_0547_0005 *(label)* | S>C | +10 undefined4 unknown | CashItem: reply/notification. Cash item use. Likely reply to C>S 0x05470004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038372 | partial_layout |
| `0x05470006` | CASHITEM_0547_0006 *(label)* | S>C | unknown | CashItem: reply/notification. Cash item use. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263213 | located_only |
| `0x05470007` | CASHITEM_0547_0007 *(label)* | S>C | +10 undefined1 unknown; +11 char unknown | CashItem: reply/notification. Cash item use. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038107 | partial_layout |
| `0x05470008` | CASHITEM_0547_0008 *(label)* | C>S | empty body | CashItem: request. Cash item use. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:931956 | partial_layout |
| `0x05470009` | CASHITEM_0547_0009 *(label)* | S>C | +10 byte unknown | CashItem: reply/notification. Cash item use. Likely reply to C>S 0x05470008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038537 | partial_layout |

## 0x0548 — ItemChange

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05480000` | ITEMCHANGE_0548_0000 *(label)* | S>C | unknown | ItemChange: reply/notification. Item change/convert. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264302 | explained |
| `0x05480001` | ITEMCHANGE_0548_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown | ItemChange: request. Item change/convert. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05480001 request, size 0x18 (builder 0x177d5e0): +0x00 u32 (window+4 = the value the open packet carried), +0x04 ref3 target *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2118074 | explained |
| `0x05480002` | ITEMCHANGE_0548_0002 *(label)* | S>C | unknown | ItemChange: reply/notification. Item change/convert. Likely reply to C>S 0x05480001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S057: S>C 0x05480002 result, size 0x5b (last field read): *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264302 | explained |
| `0x05480003` | ITEMCHANGE_0548_0003 *(label)* | C>S | empty body | ItemChange: request. Item change/convert. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05480003 close, size 0x10 (0x177d670) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178122 | partial_layout |
| `0x05480004` | ITEMCHANGE_0548_0004 *(label)* | S>C | unknown | ItemChange: reply/notification. Item change/convert. Likely reply to C>S 0x05480003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264302 | explained |

## 0x0549 — CashInventory

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05490001` | CASHINVENTORY_0549_0001 *(label)* | C>S | empty body | CashInventory: request. Cash inventory claim. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178196 | partial_layout |
| `0x05490002` | CASHINVENTORY_0549_0002 *(label)* | S>C | +10 undefined4 unknown | CashInventory: reply/notification. Cash inventory claim. Likely reply to C>S 0x05490001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2119903 | partial_layout |
| `0x05490003` | CASHINVENTORY_0549_0003 *(label)* | C>S | empty body | CashInventory: request. Cash inventory claim. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178232 | partial_layout |
| `0x05490004` | CASHINVENTORY_0549_0004 *(label)* | S>C | unknown | CashInventory: reply/notification. Cash inventory claim. Likely reply to C>S 0x05490003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2119963 | located_only |

## 0x054b — NPC transfer

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x054b0000` | NPC_TRANSFER_054B_0000 *(label)* | S>C | +10 undefined4 unknown; +14 undefined2 unknown | NPC transfer: reply/notification. NPC transfer dialog. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261266 | partial_layout |
| `0x054b0001` | NPC_TRANSFER_054B_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown | NPC transfer: request. NPC transfer dialog. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197685<br>decompiled-source/global-0.0.1/decompiled-named.c:3261266 | partial_layout |
| `0x054b0002` | NPC_TRANSFER_054B_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1a ushort unknown | NPC transfer: reply/notification. NPC transfer dialog. Likely reply to C>S 0x054b0001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1914776 | partial_layout |
| `0x054b0003` | NPC_TRANSFER_054B_0003 *(label)* | S>C | +10 char unknown | NPC transfer: reply/notification. NPC transfer dialog. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1914881 | partial_layout |

## 0x054c — RandomBox

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x054c0000` | RANDOMBOX_054C_0000 *(label)* | C>S | unknown | RandomBox: request. Random box open. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054c0000 keyed box, size 0x18 (ctor 0x175aa30, filled at 0x175a5a7): +0x00 ref3 box, +0x03 ref3 key *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2095300 | located_only |
| `0x054c0001` | RANDOMBOX_054C_0001 *(label)* | S>C | unknown | RandomBox: reply/notification. Random box open. Likely reply to C>S 0x054c0000 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S092: S>C 0x054c0001 (cmp 0x175b2c7 -> 0x175b2e0), size 0x11: +0x00 u8 result (switch 0..19 @0x175b389; 0 = success path; failure texts UNDECODED) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3174453 | explained |

## 0x054d — SupplyMachine

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x054d0000` | SUPPLYMACHINE_054D_0000 *(label)* | C>S | +10 ptr/copy unknown | SupplyMachine: request. Supply machine. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2222796<br>decompiled-source/global-0.0.1/decompiled-named.c:3180951 | partial_layout |
| `0x054d0001` | SUPPLYMACHINE_054D_0001 *(label)* | S>C | +10 uint unknown; +14 ptr unknown | SupplyMachine: reply/notification. Supply machine. Likely reply to C>S 0x054d0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2134441 | partial_layout |
| `0x054d0002` | SUPPLYMACHINE_054D_0002 *(label)* | S>C | +10 int unknown | SupplyMachine: reply/notification. Supply machine. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2134544 | partial_layout |
| `0x054d0003` | SUPPLYMACHINE_054D_0003 *(label)* | C>S | +10 ptr/copy unknown | SupplyMachine: request. Supply machine. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2222758<br>decompiled-source/global-0.0.1/decompiled-named.c:3180979 | partial_layout |
| `0x054d0004` | SUPPLYMACHINE_054D_0004 *(label)* | S>C | unknown | SupplyMachine: reply/notification. Supply machine. Likely reply to C>S 0x054d0003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2134609 | located_only |
| `0x054d0005` | SUPPLYMACHINE_054D_0005 *(label)* | S>C | +10 undefined4 unknown | SupplyMachine: reply/notification. Supply machine. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2134632 | partial_layout |
| `0x054d0006` | SUPPLYMACHINE_054D_0006 *(label)* | S>C | +10 byte unknown; +14 ptr unknown | SupplyMachine: reply/notification. Supply machine. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2134701 | partial_layout |
| `0x054d0007` | SUPPLYMACHINE_054D_0007 *(label)* | S>C | unknown | SupplyMachine: reply/notification. Supply machine. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2134799 | located_only |
| `0x054d0008` | SUPPLYMACHINE_054D_0008 *(label)* | C>S | +10 uint unknown | SupplyMachine: request. Supply machine. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2222959<br>decompiled-source/global-0.0.1/decompiled-named.c:2224422<br>decompiled-source/global-0.0.1/decompiled-named.c:2228709 | partial_layout |
| `0x054d0009` | SUPPLYMACHINE_054D_0009 *(label)* | C>S | +10 ptr/copy unknown | SupplyMachine: request. Supply machine. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2222921<br>decompiled-source/global-0.0.1/decompiled-named.c:2228668 | partial_layout |
| `0x054d000a` | SUPPLYMACHINE_054D_000A *(label)* | S>C | +10 uint unknown; +14 uint unknown; +18 uint unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined2 unknown; +26 undefined2 unknown; +28 undefined2 unknown; +2a undefined2 unknown; +2c undefined2 unknown; +2e undefined2 unknown; +30 undefined2 unknown; +32 undefined2 unknown; +34 undefined2 unknown; +36 undefined2 unknown; +38 undefined2 unknown; +3a undefined2 unknown; +3c undefined2 unknown; +3e undefined2 unknown; +40 undefined2 unknown; +42 undefined2 unknown; +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +5c undefined4 unknown; +60 undefined4 unknown | SupplyMachine: reply/notification. Supply machine. Likely reply to C>S 0x054d0009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2134843 | partial_layout |

## 0x054e — ItemIncuse

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x054e0000` | ITEMINCUSE_054E_0000 *(label)* | S>C | unknown | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264766 | explained |
| `0x054e0001` | ITEMINCUSE_054E_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown; +17 undefined2 unknown; +19 undefined1 unknown | ItemIncuse: request. Item incuse/disassemble/amplify. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054e0001 brand, size 0x1c (0x185fb40): +0x00 u32 (window+4), +0x04 ref3 (UNVERIFIED target), +0x07 ref3 (UNVERIFIED Soul Stone) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3210730 | explained |
| `0x054e0002` | ITEMINCUSE_054E_0002 *(label)* | S>C | unknown | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. Likely reply to C>S 0x054e0001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S058: S>C 0x054e0002 (cmp 0x185fe07 -> 0x185fe30) u8 result @+0x00: 0 ok \| 1 1001:133 no material \| 2 1001:134 no target \| 3 1001:135 not a target *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3210714 | explained |
| `0x054e0003` | ITEMINCUSE_054E_0003 *(label)* | C>S | +10 undefined4 unknown; +14 ushort unknown; +16 undefined2 unknown; +18 undefined1 unknown | ItemIncuse: request. Item incuse/disassemble/amplify. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054e0003, size 0x1c (0x1860670): +0x00 u32, +0x04 u16 (return of a UI getter; UNVERIFIED count), +0x06 ref3 material *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3210943 | explained |
| `0x054e0004` | ITEMINCUSE_054E_0004 *(label)* | S>C | unknown | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. Likely reply to C>S 0x054e0003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S058: S>C 0x054e0004 (cmp 0x18607a7 -> 0x18607c0) u8 result @+0x03: 0 ok \| 1 1001:133 \| 2 1001:136 \| 3,4 other.  Mapped to engine Soul Stone amplify (UNVERIFIED) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3210927 | explained |
| `0x054e0005` | ITEMINCUSE_054E_0005 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown; +17 undefined2 unknown; +19 undefined1 unknown; +1a undefined1 unknown | ItemIncuse: request. Item incuse/disassemble/amplify. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054e0005 brand with locks, size 0x1c (0x1860c40): +0x00 u32, +0x04 ref3 target, +0x07 ref3 stone, +0x0a u8 (UNVERIFIED lock bitmask) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3211051 | explained |
| `0x054e0006` | ITEMINCUSE_054E_0006 *(label)* | S>C | unknown | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. Likely reply to C>S 0x054e0005 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S058: S>C 0x054e0006 (cmp 0x1860e47 -> 0x1860e60): +0x00 u8 result (0 ok \| 1..5 as above \| 6 1001:149 not fully branded \| 7 1001:150 lock location \| 8 1001:152 no locks) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3211035 | explained |
| `0x054e0007` | ITEMINCUSE_054E_0007 *(label)* | C>S | empty body | ItemIncuse: request. Item incuse/disassemble/amplify. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054e0007 close, size 0x10 (0x17a3940) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3183005 | partial_layout |
| `0x054e0008` | ITEMINCUSE_054E_0008 *(label)* | S>C | unknown | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. Likely reply to C>S 0x054e0007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264766 | explained |
| `0x054e0009` | ITEMINCUSE_054E_0009 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown | ItemIncuse: request. Item incuse/disassemble/amplify. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2265935 | partial_layout |
| `0x054e000a` | ITEMINCUSE_054E_000A *(label)* | C>S | empty body | ItemIncuse: request. Item incuse/disassemble/amplify. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3211095 | partial_layout |

## 0x054f — Event

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x054f0000` | EVENT_054F_0000 *(label)* | S>C | unknown | Event: reply/notification. Event UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264793 | located_only |
| `0x054f0001` | EVENT_054F_0001 *(label)* | S>C | unknown | Event: reply/notification. Event UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264793 | located_only |
| `0x054f0002` | EVENT_054F_0002 *(label)* | C>S | empty body | Event: request. Event UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3183205 | partial_layout |
| `0x054f0003` | EVENT_054F_0003 *(label)* | S>C | +10 undefined1 unknown; +12 undefined2 unknown; +14 undefined4 unknown; +18 undefined4 unknown | Event: reply/notification. Event UI. Likely reply to C>S 0x054f0002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2143632 | partial_layout |
| `0x054f0004` | EVENT_054F_0004 *(label)* | S>C | +10 char unknown; +12 undefined2 unknown; +14 undefined4 unknown; +18 undefined4 unknown | Event: reply/notification. Event UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2143697 | partial_layout |

## 0x0550 — StoneGamble

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05500000` | STONEGAMBLE_0550_0000 *(label)* | S>C | unknown | StoneGamble: reply/notification. Stone gamble. Prior-build note (43.3.0, INFERRED for 0.0.1): S104: S>C 0x05500000 open (case 0x17a6a8b, no body read) \| 0x05500002 -> 0x17a6b20 \| 0x05500004 -> 0x17a6ca0 \| 0x05500006 (case 0x17a6abc, close) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264823 | located_only |
| `0x05500001` | STONEGAMBLE_0550_0001 *(label)* | C>S | +10 undefined1 unknown; +11 ptr/copy unknown; +2f undefined1 unknown; +30 undefined2 unknown; +32 undefined1 unknown | StoneGamble: request. Stone gamble. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05500001 crush, size 0x34 (0x17a6df0): +0x00 u8 (UI vf10, UNVERIFIED count), +0x01 ref3 stones packed (UI slots 0..9, empty slots skipped), then 1 more ref3 (UI vf18, UNVERIFIED) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3184033 | explained |
| `0x05500002` | STONEGAMBLE_0550_0002 *(label)* | S>C | +10 undefined2 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown | StoneGamble: reply/notification. Stone gamble. Likely reply to C>S 0x05500001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S104: S>C 0x05500002, size 0x30: +0x00 u16 result: 0 ok \| 1 350:121 system error \| 2 350:122 socket not registered \| 3 350:123 inventory full *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2144776 | explained |
| `0x05500003` | STONEGAMBLE_0550_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined1 unknown; +15 ptr/copy unknown | StoneGamble: request. Stone gamble. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05500003 produce, size 0x2c (0x17a6ee0): +0x00 u32 machine (UI vf2c; UNVERIFIED = stoneproduce Index), +0x04 u8 (UI vf40), +0x05 u8[20] per-slot lock flags (UI vf38(i)) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3184087 | explained |
| `0x05500004` | STONEGAMBLE_0550_0004 *(label)* | S>C | unknown | StoneGamble: reply/notification. Stone gamble. Likely reply to C>S 0x05500003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S104: S>C 0x05500004, size 0x19: +0x04 u32 (UNVERIFIED result itemIndex), +0x08 u8 (0..9, UNVERIFIED winning slot) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264823 | explained |
| `0x05500005` | STONEGAMBLE_0550_0005 *(label)* | C>S | empty body | StoneGamble: request. Stone gamble. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05500005 close, size 0x10 (0x17a6fa0) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3184127 | partial_layout |
| `0x05500006` | STONEGAMBLE_0550_0006 *(label)* | S>C | unknown | StoneGamble: reply/notification. Stone gamble. Likely reply to C>S 0x05500005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264823 | located_only |

## 0x0551 — ConnectReward

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05510000` | CONNECTREWARD_0551_0000 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown | ConnectReward: request. Connection-time rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3185536 | partial_layout |
| `0x05510001` | CONNECTREWARD_0551_0001 *(label)* | S>C | +10 undefined1 unknown; +11 undefined1 unknown | ConnectReward: reply/notification. Connection-time rewards. Likely reply to C>S 0x05510000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2153595 | partial_layout |
| `0x05510002` | CONNECTREWARD_0551_0002 *(label)* | S>C | unknown | ConnectReward: reply/notification. Connection-time rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264895 | located_only |
| `0x05510003` | CONNECTREWARD_0551_0003 *(label)* | S>C | unknown | ConnectReward: reply/notification. Connection-time rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264895 | located_only |
| `0x05510004` | CONNECTREWARD_0551_0004 *(label)* | S>C | unknown | ConnectReward: reply/notification. Connection-time rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264895 | located_only |
| `0x05510005` | CONNECTREWARD_0551_0005 *(label)* | S>C | unknown | ConnectReward: reply/notification. Connection-time rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264895 | located_only |
| `0x05510006` | CONNECTREWARD_0551_0006 *(label)* | S>C | unknown | ConnectReward: reply/notification. Connection-time rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264895 | located_only |
| `0x05510007` | CONNECTREWARD_0551_0007 *(label)* | S>C | unknown | ConnectReward: reply/notification. Connection-time rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264895 | located_only |

## 0x0552 — ChangeShape

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05520000` | CHANGESHAPE_0552_0000 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2154522 | located_only |
| `0x05520001` | CHANGESHAPE_0552_0001 *(label)* | C>S | empty body | ChangeShape: request. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3185857 | partial_layout |
| `0x05520002` | CHANGESHAPE_0552_0002 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). Likely reply to C>S 0x05520001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2154560 | located_only |
| `0x05520003` | CHANGESHAPE_0552_0003 *(label)* | C>S | unknown | ChangeShape: request. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2154936 | located_only |
| `0x05520004` | CHANGESHAPE_0552_0004 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). Likely reply to C>S 0x05520003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2154597 | located_only |
| `0x05520005` | CHANGESHAPE_0552_0005 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2154663 | located_only |
| `0x05520006` | CHANGESHAPE_0552_0006 *(label)* | S>C | +10 undefined4 unknown | ChangeShape: reply/notification. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2154707 | partial_layout |
| `0x05520007` | CHANGESHAPE_0552_0007 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264941 | located_only |
| `0x05520008` | CHANGESHAPE_0552_0008 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264941 | located_only |
| `0x05520009` | CHANGESHAPE_0552_0009 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264941 | located_only |
| `0x05520010` | CHANGESHAPE_0552_0010 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264941 | located_only |
| `0x05520011` | CHANGESHAPE_0552_0011 *(label)* | S>C | unknown | ChangeShape: reply/notification. Change shape (transformation). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264941 | located_only |

## 0x0553 — ItemMunzang

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05530000` | ITEMMUNZANG_0553_0000 *(label)* | S>C | unknown | ItemMunzang: reply/notification. Item crest (munzang). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2159072 | located_only |
| `0x05530001` | ITEMMUNZANG_0553_0001 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined4 unknown; +17 undefined4 unknown; +1b undefined4 unknown; +1f undefined4 unknown; +23 undefined2 unknown | ItemMunzang: request. Item crest (munzang). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05530001 insert, size 0x28 (0x17bc050): +0x00 ref3 costume, +0x03 + 3*i ref3 crest for slot i (i = 0..5; 16 bytes + u16 copied from window+7..+0x18) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2158252 | explained |
| `0x05530002` | ITEMMUNZANG_0553_0002 *(label)* | S>C | +10 undefined3 unknown; +14 undefined3 unknown; +18 ushort unknown; +1a ushort unknown; +1c undefined3 unknown; +20 ushort unknown; +22 ushort unknown; +24 undefined3 unknown; +28 ushort unknown; +2a ushort unknown; +2c undefined3 unknown; +30 ushort unknown; +32 ushort unknown; +34 undefined3 unknown; +37 byte unknown; +38 ushort unknown; +3a undefined3 unknown; +3d byte unknown; +3e ushort unknown; +40 undefined4 unknown; +44 undefined4 unknown; +48 byte unknown | ItemMunzang: reply/notification. Item crest (munzang). Likely reply to C>S 0x05530001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S061: S>C 0x05530002, size 0x49: +0x00 ref3 costume, +0x04 + 8*i {ref3, u16 @+4, u16 @+6} for slots 0..5 (UNVERIFIED: crest ref + option code/value), +0x38 u8 result *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2159189 | explained |
| `0x05530003` | ITEMMUNZANG_0553_0003 *(label)* | C>S | empty body | ItemMunzang: request. Item crest (munzang). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05530003 close, size 0x10 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3186549 | partial_layout |
| `0x05530004` | ITEMMUNZANG_0553_0004 *(label)* | S>C | unknown | ItemMunzang: reply/notification. Item crest (munzang). Likely reply to C>S 0x05530003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2159072 | located_only |
| `0x05530005` | ITEMMUNZANG_0553_0005 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined2 unknown; +15 undefined1 unknown; +16 ptr/copy unknown; +1a ptr/copy unknown | ItemMunzang: request. Item crest (munzang). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05530005 extract, size 0x1c (0x17bc0d0): +0x00 ref3 costume (window+4), +0x03 ref3 plier (window+0x19), +0x06 u8[6] slot selected flags (window+0x1c) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2158285 | explained |
| `0x05530006` | ITEMMUNZANG_0553_0006 *(label)* | S>C | +13 undefined3 unknown; +2e char unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 byte unknown | ItemMunzang: reply/notification. Item crest (munzang). Likely reply to C>S 0x05530005 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S061: S>C 0x05530006, size 0x39: +0x03 ref3, +0x1e u8 (0/1 branch, UNVERIFIED: plier kept), +0x20 i64 (UNVERIFIED: dil), +0x28 u8 result (read @pkt+0x38) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2159102 | explained |

## 0x0554 — Title

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05540000` | TITLE_0554_0000 *(label)* | S>C | +10 undefined1 unknown; +18 undefined4 unknown; +1c undefined2 unknown | Title: reply/notification. Titles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2160184 | partial_layout |
| `0x05540001` | TITLE_0554_0001 *(label)* | S>C | +10 undefined1 unknown; +12 undefined2 unknown; +18 undefined4 unknown; +1c undefined2 unknown | Title: reply/notification. Titles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2160294 | partial_layout |
| `0x05540002` | TITLE_0554_0002 *(label)* | C>S | +10 undefined1 unknown | Title: request. Titles. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05540002 (builders 0x17bf660 / 0x17bf7f0): size 0x14, u8 titleIndex @0x10 (0xff = take title off). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2160583<br>decompiled-source/global-0.0.1/decompiled-named.c:2160659 | explained |
| `0x05540003` | TITLE_0554_0003 *(label)* | S>C | unknown | Title: reply/notification. Titles. Likely reply to C>S 0x05540002 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S110: S>C 0x05540003 (case @switch 0x17beb5b): u8 result @0x10 (0 ok; 1 -> msg 0xaf2:5; 2 -> msg 0xaf2:4), *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2160119 | explained |
| `0x05540004` | TITLE_0554_0004 *(label)* | S>C | unknown | Title: reply/notification. Titles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2160260 | located_only |
| `0x05540005` | TITLE_0554_0005 *(label)* | S>C | +10 undefined1 unknown | Title: reply/notification. Titles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2160493 | partial_layout |
| `0x05540006` | TITLE_0554_0006 *(label)* | S>C | +26 undefined1 unknown; +28 undefined4 unknown; +2c undefined4 unknown | Title: reply/notification. Titles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2160526 | partial_layout |
| `0x05540007` | TITLE_0554_0007 *(label)* | S>C | unknown | Title: reply/notification. Titles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265011 | located_only |
| `0x05540008` | TITLE_0554_0008 *(label)* | S>C | unknown | Title: reply/notification. Titles. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265011 | located_only |

## 0x0555 — Product (crafting)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05550001` | PRODUCT_CRAFTING_0555_0001 *(label)* | S>C | unknown | Product (crafting): reply/notification. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265106 | located_only |
| `0x05550002` | PRODUCT_CRAFTING_0555_0002 *(label)* | C>S | unknown | Product (crafting): request. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:948970 | located_only |
| `0x05550003` | PRODUCT_CRAFTING_0555_0003 *(label)* | S>C | +10 char unknown; +14 undefined1 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2164044 | partial_layout |
| `0x05550004` | PRODUCT_CRAFTING_0555_0004 *(label)* | C>S | unknown | Product (crafting): request. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3240709 | located_only |
| `0x05550005` | PRODUCT_CRAFTING_0555_0005 *(label)* | S>C | +10 undefined1 unknown; +14 undefined4 unknown; +18 char unknown | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2164217 | partial_layout |
| `0x05550006` | PRODUCT_CRAFTING_0555_0006 *(label)* | C>S | +10 undefined1 unknown | Product (crafting): request. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3284044 | partial_layout |
| `0x05550007` | PRODUCT_CRAFTING_0555_0007 *(label)* | S>C | +10 char unknown; +11 undefined1 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined1 unknown; +24 undefined4 unknown | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2163979 | partial_layout |
| `0x05550008` | PRODUCT_CRAFTING_0555_0008 *(label)* | C>S | +10 short unknown; +12 char unknown | Product (crafting): request. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3284018 | partial_layout |
| `0x05550009` | PRODUCT_CRAFTING_0555_0009 *(label)* | S>C | +10 undefined1 unknown; +11 char unknown | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2163924 | partial_layout |
| `0x0555000a` | PRODUCT_CRAFTING_0555_000A *(label)* | C>S | +10 undefined1 unknown; +11 short unknown; +13 char unknown; +14 undefined1 unknown | Product (crafting): request. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2883919 | partial_layout |
| `0x0555000b` | PRODUCT_CRAFTING_0555_000B *(label)* | S>C | +10 undefined1 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 char unknown; +26 short unknown | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x0555000a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2164130 | partial_layout |
| `0x0555000c` | PRODUCT_CRAFTING_0555_000C *(label)* | S>C | unknown | Product (crafting): reply/notification. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265106 | located_only |
| `0x0555000d` | PRODUCT_CRAFTING_0555_000D *(label)* | C>S | empty body | Product (crafting): request. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2883715 | partial_layout |
| `0x0555000e` | PRODUCT_CRAFTING_0555_000E *(label)* | S>C | unknown | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x0555000d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265106 | located_only |
| `0x0555000f` | PRODUCT_CRAFTING_0555_000F *(label)* | S>C | unknown | Product (crafting): reply/notification. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265106 | located_only |
| `0x05550010` | PRODUCT_CRAFTING_0555_0010 *(label)* | S>C | +10 int unknown | Product (crafting): reply/notification. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2164400 | partial_layout |
| `0x05550011` | PRODUCT_CRAFTING_0555_0011 *(label)* | C>S | +10 undefined1 unknown | Product (crafting): request. Production learn/catalyst. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:950381 | partial_layout |
| `0x05550012` | PRODUCT_CRAFTING_0555_0012 *(label)* | S>C | +10 char unknown; +11 undefined1 unknown; +14 undefined4 unknown | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2164304 | partial_layout |

## 0x0556 — CostumeWardrobe

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05560000` | COSTUMEWARDROBE_0556_0000 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | CostumeWardrobe: request. Costume wardrobe. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05560000, size 0x14 (0x17c5db0): +0x00 ref3 costume (bag) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3187716 | partial_layout |
| `0x05560001` | COSTUMEWARDROBE_0556_0001 *(label)* | S>C | unknown | CostumeWardrobe: reply/notification. Costume wardrobe. Likely reply to C>S 0x05560000 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S029: S>C 0x05560001 (cmp 0x17c6187 -> 0x17c61a0), size 0x11: +0x00 u8 result (handler branches on == 0; UNVERIFIED 0 = ok) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3187879 | explained |

## 0x0561 — Dekaron provider

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05610000` | DEKARON_PROVIDER_0561_0000 *(label)* | C>S | +10 ptr/copy unknown | Dekaron provider: request. Dekaron misc. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224311<br>decompiled-source/global-0.0.1/decompiled-named.c:2224361<br>decompiled-source/global-0.0.1/decompiled-named.c:2230565 … | partial_layout |
| `0x05610001` | DEKARON_PROVIDER_0561_0001 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +38 int unknown; +3c undefined4 unknown | Dekaron provider: reply/notification. Dekaron misc. Likely reply to C>S 0x05610000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221575 | partial_layout |
| `0x05610002` | DEKARON_PROVIDER_0561_0002 *(label)* | S>C | +10 undefined1 unknown | Dekaron provider: reply/notification. Dekaron misc. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221532 | partial_layout |
| `0x05610003` | DEKARON_PROVIDER_0561_0003 *(label)* | S>C | +10 byte unknown; +14 ptr unknown; +1c ptr unknown | Dekaron provider: reply/notification. Dekaron misc. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273320<br>decompiled-source/global-0.0.1/decompiled-named.c:3273424 | partial_layout |

## 0x0562 — PrivateSupply / FieldBossSupply

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05620001` | PRIVATESUPPLY_0562_0001 *(label)* | C>S | empty body | PrivateSupply / FieldBossSupply: request. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05620001 spin  -> S>C 0x05620002 (0x17997f0): u8 result @+0 (switch 0..9), u32 @+4, @+8, @+0xc *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3181300 | explained |
| `0x05620002` | PRIVATESUPPLY_0562_0002 *(label)* | S>C | unknown | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Likely reply to C>S 0x05620001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S087: 0x05620001 spin  -> S>C 0x05620002 (0x17997f0): u8 result @+0 (switch 0..9), u32 @+4, @+8, @+0xc *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264723 | explained |
| `0x05620003` | PRIVATESUPPLY_0562_0003 *(label)* | S>C | +10 undefined1 unknown | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): S087: 0x05620006 mix   -> S>C 0x05620003 (0x17998a0): u8 result @+0 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2135801 | explained |
| `0x05620004` | PRIVATESUPPLY_0562_0004 *(label)* | C>S | empty body | PrivateSupply / FieldBossSupply: request. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05620004 state (sent from 0x1798da0 / 0x17991f0 / 0x17e9ba0) -> S>C 0x05620005 (0x17999f0), body 0x5c: *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3181280<br>decompiled-source/global-0.0.1/decompiled-named.c:3192548 | partial_layout |
| `0x05620005` | PRIVATESUPPLY_0562_0005 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 undefined4 unknown; +3c undefined4 unknown; +40 undefined4 unknown; +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +5c undefined4 unknown; +60 undefined4 unknown; +68 int unknown | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Likely reply to C>S 0x05620004 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S087: 0x05620004 state (sent from 0x1798da0 / 0x17991f0 / 0x17e9ba0) -> S>C 0x05620005 (0x17999f0), body 0x5c: *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2135875 | partial_layout |
| `0x05620006` | PRIVATESUPPLY_0562_0006 *(label)* | C>S | empty body | PrivateSupply / FieldBossSupply: request. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05620006 mix   -> S>C 0x05620003 (0x17998a0): u8 result @+0 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3181325 | explained |
| `0x05620007` | PRIVATESUPPLY_0562_0007 *(label)* | S>C | unknown | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Likely reply to C>S 0x05620006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264723 | located_only |
| `0x05620008` | PRIVATESUPPLY_0562_0008 *(label)* | C>S | empty body | PrivateSupply / FieldBossSupply: request. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05620008 close (no reply) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3181345 | partial_layout |
| `0x05620009` | PRIVATESUPPLY_0562_0009 *(label)* | S>C | unknown | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Likely reply to C>S 0x05620008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264723 | located_only |

## 0x0564 — UpgradeWing

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05640000` | UPGRADEWING_0564_0000 *(label)* | S>C | unknown | UpgradeWing: reply/notification. Wing upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): S121: S>C 0x05640000 open, no body (case 0x17ceac6 -> handler 0x17ceb10) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265154 | located_only |
| `0x05640001` | UPGRADEWING_0564_0001 *(label)* | C>S | +10 int unknown; +14 undefined2 unknown; +16 undefined1 unknown | UpgradeWing: request. Wing upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05640001 request, size 0x18 (builder 0x17ce700): +0x00 u32 [window+8] (UNVERIFIED npc handle/context), +0x04 ref3 wing *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3189390 | explained |
| `0x05640002` | UPGRADEWING_0564_0002 *(label)* | S>C | unknown | UpgradeWing: reply/notification. Wing upgrade. Likely reply to C>S 0x05640001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S121: S>C 0x05640002 result (handler 0x17ceb50), size 0x1e (= last field read; exact size UNVERIFIED): +0x00 i64 dil (money setter push), +0x08 u32 UNDECODED (0), *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265154 | explained |
| `0x05640003` | UPGRADEWING_0564_0003 *(label)* | C>S | empty body | UpgradeWing: request. Wing upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05640003 close, size 0x10 (0x17ce690) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3189370 | partial_layout |
| `0x05640004` | UPGRADEWING_0564_0004 *(label)* | S>C | unknown | UpgradeWing: reply/notification. Wing upgrade. Likely reply to C>S 0x05640003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S121: S>C 0x05640004 close window (case 0x17cead1).  0x05640005 (0x17cec60: u8 +4, u32 +0) UNDECODED, not sent. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265154 | explained |
| `0x05640005` | UPGRADEWING_0564_0005 *(label)* | S>C | +10 undefined4 unknown; +14 char unknown | UpgradeWing: reply/notification. Wing upgrade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2170112 | explained |

## 0x0565 — UpgradeAccessory / MaterialExchange

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05650000` | UPGRADEACCESSORY_0565_0000 *(label)* | S>C | unknown | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): S118: S>C 0x05650000 open, no body (case 0x17d105e -> handler 0x17d10c0) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2171663 | located_only |
| `0x05650001` | UPGRADEACCESSORY_0565_0001 *(label)* | C>S | +10 int unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined2 unknown; +1e undefined1 unknown | UpgradeAccessory / MaterialExchange: request. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05650001 request, size 0x20 (builder 0x17d0c50): *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3189645 | partial_layout |
| `0x05650002` | UPGRADEACCESSORY_0565_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Likely reply to C>S 0x05650001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S118: S>C 0x05650002 result (handler 0x17d1130), size 0x19 (= last field read; UNVERIFIED): +0x00 i64 dil, +0x08 u8 result: *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2171698 | explained |
| `0x05650003` | UPGRADEACCESSORY_0565_0003 *(label)* | C>S | empty body | UpgradeAccessory / MaterialExchange: request. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05650003 close, size 0x10 (0x17d0c00) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3189625 | partial_layout |
| `0x05650004` | UPGRADEACCESSORY_0565_0004 *(label)* | S>C | unknown | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Likely reply to C>S 0x05650003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S118: S>C 0x05650004 close (case 0x17d106c -> 0x17d10f0). 0x05650005 (u8 +4, u32 +0) UNDECODED, not sent. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2171680 | explained |
| `0x05650005` | UPGRADEACCESSORY_0565_0005 *(label)* | S>C | +10 undefined4 unknown; +14 char unknown | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2171803 | explained |
| `0x05650006` | MATERIALEXCHANGE_0565_0006 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown | UpgradeAccessory / MaterialExchange: request. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05650006, size 0x18 (0x17d0cf0 / 0x1813e30): +0x00 u32, +0x04 u16   (UNVERIFIED: row, count) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2171551<br>decompiled-source/global-0.0.1/decompiled-named.c:2213474 | explained |
| `0x05650007` | MATERIALEXCHANGE_0565_0007 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Likely reply to C>S 0x05650006 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S065: S>C 0x05650007 (accessory window case 0x17d1088 -> 0x17d1450), size 0x19: +0x00 i64 dil, +0x08 u8 result: *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2171843 | explained |
| `0x05650008` | MATERIALEXCHANGE_0565_0008 *(label)* | S>C | unknown | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): S065: S>C 0x05650008 open (cmp 0x18140a8 -> window [0x22c17cc] vf+8 with u16 @+0x04; UNVERIFIED: +0x00 u32 npc handle, +0x04 u16 catalog) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266111 | explained |

## 0x0566 — ForgottenShipwreck

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05660010` | FORGOTTENSHIPWRECK_0566_0010 *(label)* | S>C | unknown | ForgottenShipwreck: reply/notification. Forgotten Shipwreck event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265181 | located_only |
| `0x05660011` | FORGOTTENSHIPWRECK_0566_0011 *(label)* | C>S | +10 undefined1 unknown | ForgottenShipwreck: request. Forgotten Shipwreck event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3189762 | partial_layout |
| `0x05660012` | FORGOTTENSHIPWRECK_0566_0012 *(label)* | S>C | unknown | ForgottenShipwreck: reply/notification. Forgotten Shipwreck event. Likely reply to C>S 0x05660011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265181 | located_only |
| `0x05660013` | FORGOTTENSHIPWRECK_0566_0013 *(label)* | S>C | unknown | ForgottenShipwreck: reply/notification. Forgotten Shipwreck event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265181 | located_only |

## 0x0567 — AttendanceReward

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05670000` | ATTENDANCEREWARD_0567_0000 *(label)* | C>S | empty body | AttendanceReward: request. Attendance rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3190131 | partial_layout |
| `0x05670001` | ATTENDANCEREWARD_0567_0001 *(label)* | S>C | +10 char unknown; +11 char unknown; +12 char unknown; +13 undefined1 unknown; +14 undefined4 unknown | AttendanceReward: reply/notification. Attendance rewards. Likely reply to C>S 0x05670000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2173369 | partial_layout |
| `0x05670002` | ATTENDANCEREWARD_0567_0002 *(label)* | C>S | unknown | AttendanceReward: request. Attendance rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3304287 | located_only |
| `0x05670003` | ATTENDANCEREWARD_0567_0003 *(label)* | S>C | +12 undefined1 unknown | AttendanceReward: reply/notification. Attendance rewards. Likely reply to C>S 0x05670002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2173435 | partial_layout |
| `0x05670004` | ATTENDANCEREWARD_0567_0004 *(label)* | S>C | unknown | AttendanceReward: reply/notification. Attendance rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265288 | located_only |
| `0x05670005` | ATTENDANCEREWARD_0567_0005 *(label)* | S>C | unknown | AttendanceReward: reply/notification. Attendance rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265288 | located_only |
| `0x05670006` | ATTENDANCEREWARD_0567_0006 *(label)* | S>C | unknown | AttendanceReward: reply/notification. Attendance rewards. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2173522 | located_only |

## 0x0568 — UpgradeCostume

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05680000` | UPGRADECOSTUME_0568_0000 *(label)* | S>C | unknown | UpgradeCostume: reply/notification. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): S119: S>C 0x05680000 open (case 0x17d8c27, no body). NPC job 124 COSTUME_CYCLE (engine src\systems\mounts\windows.js; UNVERIFIED vs Global npc.csv). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2176535 | located_only |
| `0x05680001` | UPGRADECOSTUME_0568_0001 *(label)* | C>S | +10 int unknown; +14 undefined4 unknown; +19 ptr/copy unknown | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680001 dismantle, size 0x64 (0x17d7cf0): +0x00 u32 count, +0x04 u32 window field this+8 (UNVERIFIED: npc/window id), *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2175933 | explained |
| `0x05680002` | UPGRADECOSTUME_0568_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2176601 | explained |
| `0x05680003` | UPGRADECOSTUME_0568_0003 *(label)* | C>S | empty body | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680003, size 0x10 (0x17d7be0): no body (UNVERIFIED: close/reset) -> S>C 0x05680004 (0x17d8ce0 resets three UI slots; no body read) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3190747 | partial_layout |
| `0x05680004` | UPGRADECOSTUME_0568_0004 *(label)* | S>C | unknown | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S119: C>S 0x05680003, size 0x10 (0x17d7be0): no body (UNVERIFIED: close/reset) -> S>C 0x05680004 (0x17d8ce0 resets three UI slots; no body read) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2176572 | located_only |
| `0x05680005` | UPGRADECOSTUME_0568_0005 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680005 sew, size 0x18 (0x17d7a80): +0x00 u32 this+8, +0x04 u32 arg (UNVERIFIED: chosen appearance item index) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2175909 | explained |
| `0x05680006` | UPGRADECOSTUME_0568_0006 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2176804 | explained |
| `0x05680007` | UPGRADECOSTUME_0568_0007 *(label)* | C>S | +14 undefined1 unknown; +15 undefined1 unknown; +16 undefined1 unknown | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680007 options, size 0x18 (0x17d7af0): +0x04 ref3 costume (getter +4/+5/+6), +0x00 u32 left 0 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3190657 | explained |
| `0x05680008` | UPGRADECOSTUME_0568_0008 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +1b undefined1 unknown; +1c ptr unknown; +2c undefined1 unknown | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2176703 | explained |
| `0x05680009` | UPGRADECOSTUME_0568_0009 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 short unknown; +1a undefined1 unknown | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680009 appearance, size 0x1c (0x17d7c30): +0x00 u32 arg (UNVERIFIED: appearance item index), +0x04 u32 0, +0x08 ref3 costume *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3190767 | explained |
| `0x0568000a` | UPGRADECOSTUME_0568_000A *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown; +1c undefined4 unknown | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2176895 | explained |
| `0x0568000e` | UPGRADECOSTUME_0568_000E *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x0568000e fabric exchange, size 0x18 (0x17d8160): +0x00 u32 arg (UNVERIFIED: count), +0x04 u32 this+8 *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2176178 | explained |
| `0x0568000f` | UPGRADECOSTUME_0568_000F *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x0568000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2177024 | explained |

## 0x0569 — NPC dialog / creature

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05690000` | NPC_DIALOG_0569_0000 *(label)* | S>C | +10 int unknown | NPC dialog / creature: reply/notification. NPC dialog and creature events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:310633 | partial_layout |
| `0x05690003` | NPC_DIALOG_0569_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined1 unknown; +15 undefined1 unknown | NPC dialog / creature: request. NPC dialog and creature events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:226632<br>decompiled-source/global-0.0.1/decompiled-named.c:3144837 | partial_layout |
| `0x05690004` | NPC_DIALOG_0569_0004 *(label)* | S>C | unknown | NPC dialog / creature: reply/notification. NPC dialog and creature events. Likely reply to C>S 0x05690003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x05690005` | NPC_DIALOG_0569_0005 *(label)* | S>C | unknown | NPC dialog / creature: reply/notification. NPC dialog and creature events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x05690006` | NPC_DIALOG_0569_0006 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown; +17 undefined1 unknown | NPC dialog / creature: request. NPC dialog and creature events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:285254 | partial_layout |
| `0x05690007` | NPC_DIALOG_0569_0007 *(label)* | C>S | unknown | NPC dialog / creature: request. NPC dialog and creature events. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:300573 | located_only |
| `0x05690008` | NPC_DIALOG_0569_0008 *(label)* | S>C | unknown | NPC dialog / creature: reply/notification. NPC dialog and creature events. Likely reply to C>S 0x05690007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |

## 0x0570 — UpgradeHelmet

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05700000` | UPGRADEHELMET_0570_0000 *(label)* | S>C | unknown | UpgradeHelmet: reply/notification. Helmet upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): S120: S>C 0x05700000 open, no body (case 0x17dca66 -> handler 0x17dcaa0) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265320 | located_only |
| `0x05700001` | UPGRADEHELMET_0570_0001 *(label)* | C>S | +10 int unknown; +14 undefined2 unknown; +16 undefined1 unknown | UpgradeHelmet: request. Helmet upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05700001 request, size 0x18 (builder 0x17dc5e0): +0x00 u32 [window+8] (UNVERIFIED context), +0x04 ref3 helmet *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3191151 | explained |
| `0x05700002` | UPGRADEHELMET_0570_0002 *(label)* | S>C | unknown | UpgradeHelmet: reply/notification. Helmet upgrade. Likely reply to C>S 0x05700001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S120: S>C 0x05700002 result (handler 0x17dcae0), size 0x20 (= last field read; exact server size UNVERIFIED): +0x00 i64 dil (0x17dcbf5/fc), +0x08 u8 result, +0x0c u32 (read @0x17dcb5d; UNDECODED, 0) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265320 | explained |
| `0x05700003` | UPGRADEHELMET_0570_0003 *(label)* | C>S | empty body | UpgradeHelmet: request. Helmet upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05700003 close, size 0x10 (0x17dc570) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3191131 | partial_layout |
| `0x05700004` | UPGRADEHELMET_0570_0004 *(label)* | S>C | unknown | UpgradeHelmet: reply/notification. Helmet upgrade. Likely reply to C>S 0x05700003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S120: S>C 0x05700004 close window (case 0x17dca71) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265320 | located_only |
| `0x05700005` | UPGRADEHELMET_0570_0005 *(label)* | S>C | unknown | UpgradeHelmet: reply/notification. Helmet upgrade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265320 | located_only |

## 0x0571 — (unattributed)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05710001` | UNATTRIBUTED_0571_0001 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed family. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265377 | located_only |

## 0x0572 — WingShapeChange

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05720000` | WINGSHAPECHANGE_0572_0000 *(label)* | S>C | unknown | WingShapeChange: reply/notification. Wing shape change. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2183797 | located_only |
| `0x05720001` | WINGSHAPECHANGE_0572_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 short unknown; +1a undefined1 unknown | WingShapeChange: request. Wing shape change. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05720001 change, size 0x1c (builder 0x17e4cf0): +0x00 u32 = 0, +0x04 u32 = builder arg (UNVERIFIED: chosen appearance item index), +0x08 ref3 wing *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3191990 | explained |
| `0x05720002` | WINGSHAPECHANGE_0572_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined1 unknown | WingShapeChange: reply/notification. Wing shape change. Likely reply to C>S 0x05720001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S126: S>C 0x05720002 / 0x05740001, size 0x1d: +0x00 i64 (dwords +0x10/+0x14 handed to a setter; UNVERIFIED = dil), +0x08 u32 appearance (success only, to 0x17e3e30), *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2183846 | explained |
| `0x05720003` | WINGSHAPECHANGE_0572_0003 *(label)* | C>S | empty body | WingShapeChange: request. Wing shape change. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05720003 close, size 0x10 (0x17e4ca0) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3191970 | partial_layout |
| `0x05720004` | WINGSHAPECHANGE_0572_0004 *(label)* | S>C | unknown | WingShapeChange: reply/notification. Wing shape change. Likely reply to C>S 0x05720003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2183830 | located_only |

## 0x0574 — WingShapeChange

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05740000` | WINGSHAPECHANGE_0574_0000 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 short unknown; +1a undefined1 unknown | WingShapeChange: request. Wing shape change. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05740000 restore, size 0x1c (builder 0x17e4d90), same layout *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3192032 | partial_layout |
| `0x05740001` | WINGSHAPECHANGE_0574_0001 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined1 unknown | WingShapeChange: reply/notification. Wing shape change. Likely reply to C>S 0x05740000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2183942 | explained |

## 0x0575 — Quest

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05750000` | QUEST_0575_0000 *(label)* | S>C | +10 undefined4 unknown | Quest: reply/notification. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898712 | partial_layout |
| `0x05750001` | QUEST_0575_0001 *(label)* | C>S | +10 undefined4 unknown; +14 short unknown | Quest: request. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3143217 | partial_layout |
| `0x05750002` | QUEST_0575_0002 *(label)* | S>C | +10 char unknown | Quest: reply/notification. Quest UI. Likely reply to C>S 0x05750001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1898723 | partial_layout |
| `0x05750004` | QUEST_0575_0004 *(label)* | S>C | unknown | Quest: reply/notification. Quest UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1897950 | located_only |

## 0x0576 — FieldBossSupply

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05760001` | FIELDBOSSSUPPLY_0576_0001 *(label)* | C>S | +10 undefined1 unknown | FieldBossSupply: request. Field boss supply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3192568 | partial_layout |
| `0x05760002` | FIELDBOSSSUPPLY_0576_0002 *(label)* | S>C | unknown | FieldBossSupply: reply/notification. Field boss supply. Likely reply to C>S 0x05760001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2187688 | located_only |
| `0x05760003` | FIELDBOSSSUPPLY_0576_0003 *(label)* | S>C | +10 undefined1 unknown | FieldBossSupply: reply/notification. Field boss supply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2187715 | partial_layout |
| `0x05760005` | FIELDBOSSSUPPLY_0576_0005 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 undefined4 unknown; +3c undefined4 unknown; +40 undefined4 unknown; +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +5c undefined4 unknown; +60 undefined4 unknown; +68 int unknown | FieldBossSupply: reply/notification. Field boss supply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2187853 | partial_layout |
| `0x05760006` | FIELDBOSSSUPPLY_0576_0006 *(label)* | C>S | empty body | FieldBossSupply: request. Field boss supply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3192598 | partial_layout |
| `0x05760007` | FIELDBOSSSUPPLY_0576_0007 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 undefined4 unknown; +3c undefined4 unknown; +40 undefined4 unknown; +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +5c undefined4 unknown; +60 undefined4 unknown | FieldBossSupply: reply/notification. Field boss supply. Likely reply to C>S 0x05760006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2187789 | partial_layout |
| `0x05760008` | FIELDBOSSSUPPLY_0576_0008 *(label)* | C>S | empty body | FieldBossSupply: request. Field boss supply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3192618 | partial_layout |
| `0x05760009` | FIELDBOSSSUPPLY_0576_0009 *(label)* | S>C | unknown | FieldBossSupply: reply/notification. Field boss supply. Likely reply to C>S 0x05760008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265406 | located_only |

## 0x0577 — DKRPvPBattle

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05770001` | DKRPVPBATTLE_0577_0001 *(label)* | C>S | +46 undefined2 unknown; +48 undefined2 unknown | DKRPvPBattle: request. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2197241 | partial_layout |
| `0x05770003` | DKRPVPBATTLE_0577_0003 *(label)* | C>S | +46 undefined2 unknown; +48 undefined2 unknown | DKRPvPBattle: request. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2197241 | partial_layout |
| `0x05770005` | DKRPVPBATTLE_0577_0005 *(label)* | C>S | +10 ptr/copy unknown | DKRPvPBattle: request. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3193785 | partial_layout |

## 0x0578 — Equipment presets / Inven states

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05780000` | EQUIPMENT_PRESETS_0578_0000 *(label)* | C>S | unknown | Equipment presets / Inven states: request. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2268395 | located_only |
| `0x05780001` | EQUIPMENT_PRESETS_0578_0001 *(label)* | C>S | empty body | Equipment presets / Inven states: request. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2268643 | partial_layout |
| `0x05780002` | EQUIPMENT_PRESETS_0578_0002 *(label)* | S>C | +10 char unknown | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x05780001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244211 | partial_layout |
| `0x05780003` | EQUIPMENT_PRESETS_0578_0003 *(label)* | C>S | unknown | Equipment presets / Inven states: request. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1864343 | located_only |
| `0x05780004` | EQUIPMENT_PRESETS_0578_0004 *(label)* | S>C | +10 char unknown; +11 undefined3 unknown; +18 byte unknown | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x05780003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244364 | partial_layout |
| `0x05780009` | EQUIPMENT_PRESETS_0578_0009 *(label)* | C>S | unknown | Equipment presets / Inven states: request. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276994 | located_only |
| `0x0578000a` | EQUIPMENT_PRESETS_0578_000A *(label)* | S>C | +10 char unknown; +19 undefined4 unknown; +1d undefined1 unknown | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x05780009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244257 | partial_layout |
| `0x0578000b` | EQUIPMENT_PRESETS_0578_000B *(label)* | C>S | unknown | Equipment presets / Inven states: request. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1833444 | located_only |
| `0x0578000c` | EQUIPMENT_PRESETS_0578_000C *(label)* | S>C | +10 char unknown; +16 char unknown | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x0578000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244569 | partial_layout |
| `0x0578000d` | EQUIPMENT_PRESETS_0578_000D *(label)* | S>C | +10 char unknown | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244943 | partial_layout |
| `0x0578000e` | EQUIPMENT_PRESETS_0578_000E *(label)* | C>S | empty body | Equipment presets / Inven states: request. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2268948<br>decompiled-source/global-0.0.1/decompiled-named.c:3198447<br>decompiled-source/global-0.0.1/decompiled-named.c:3199031 … | partial_layout |
| `0x0578000f` | EQUIPMENT_PRESETS_0578_000F *(label)* | S>C | +10 char unknown | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x0578000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244749 | partial_layout |
| `0x05780013` | EQUIPMENT_PRESETS_0578_0013 *(label)* | S>C | +10 char unknown; +11 undefined1 unknown | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244813 | partial_layout |
| `0x05780014` | EQUIPMENT_PRESETS_0578_0014 *(label)* | C>S | empty body | Equipment presets / Inven states: request. Equipment preset save/apply. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:248161 | partial_layout |
| `0x05780015` | EQUIPMENT_PRESETS_0578_0015 *(label)* | S>C | unknown | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x05780014 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2244984 | located_only |

## 0x0580 — OXQuiz

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05800000` | OXQUIZ_0580_0000 *(label)* | S>C | +10 short unknown; +210 undefined1 unknown | OXQuiz: reply/notification. OX quiz event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2199741 | partial_layout |
| `0x05800001` | OXQUIZ_0580_0001 *(label)* | S>C | unknown | OXQuiz: reply/notification. OX quiz event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3194230 | located_only |
| `0x05800002` | OXQUIZ_0580_0002 *(label)* | S>C | +10 short unknown | OXQuiz: reply/notification. OX quiz event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2199812 | partial_layout |

## 0x0581 — Pet shape change/restore/disassemble

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05810000` | PET_SHAPE_CHANGE_0581_0000 *(label)* | S>C | unknown | Pet shape change/restore/disassemble: reply/notification. Pet shape services. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1832681<br>decompiled-source/global-0.0.1/decompiled-named.c:3273528 | located_only |
| `0x05810001` | PET_SHAPE_CHANGE_0581_0001 *(label)* | both | +14 undefined4 unknown; +18 undefined2 unknown; +1a undefined1 unknown; +1c undefined4 unknown; +20 undefined4 unknown | Pet shape change/restore/disassemble: request and reply share this opcode. Pet shape services. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1833006<br>decompiled-source/global-0.0.1/decompiled-named.c:3273528 | partial_layout |
| `0x05810002` | PET_SHAPE_CHANGE_0581_0002 *(label)* | S>C | unknown | Pet shape change/restore/disassemble: reply/notification. Pet shape services. Likely reply to C>S 0x05810001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273528 | located_only |
| `0x05810003` | PET_SHAPE_CHANGE_0581_0003 *(label)* | both | empty body | Pet shape change/restore/disassemble: request and reply share this opcode. Pet shape services. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1021170<br>decompiled-source/global-0.0.1/decompiled-named.c:1022879<br>decompiled-source/global-0.0.1/decompiled-named.c:2887082 … | partial_layout |
| `0x05810004` | PET_SHAPE_CHANGE_0581_0004 *(label)* | S>C | unknown | Pet shape change/restore/disassemble: reply/notification. Pet shape services. Likely reply to C>S 0x05810003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1832716<br>decompiled-source/global-0.0.1/decompiled-named.c:3273528 | located_only |
| `0x05810005` | PET_SHAPE_CHANGE_0581_0005 *(label)* | both | +10 uint unknown; +14 ptr/copy unknown | Pet shape change/restore/disassemble: request and reply share this opcode. Pet shape services. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273528<br>decompiled-source/global-0.0.1/decompiled-named.c:3284573 | partial_layout |
| `0x05810006` | PET_SHAPE_CHANGE_0581_0006 *(label)* | S>C | unknown | Pet shape change/restore/disassemble: reply/notification. Pet shape services. Likely reply to C>S 0x05810005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273528<br>decompiled-source/global-0.0.1/decompiled-named.c:36553 | located_only |
| `0x05810007` | PET_SHAPE_CHANGE_0581_0007 *(label)* | S>C | unknown | Pet shape change/restore/disassemble: reply/notification. Pet shape services. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273528 | located_only |
| `0x05810008` | PET_SHAPE_CHANGE_0581_0008 *(label)* | S>C | unknown | Pet shape change/restore/disassemble: reply/notification. Pet shape services. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273528 | located_only |
| `0x05810009` | PET_SHAPE_CHANGE_0581_0009 *(label)* | S>C | unknown | Pet shape change/restore/disassemble: reply/notification. Pet shape services. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273528 | located_only |

## 0x0582 — Exchange store

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05820000` | EXCHANGE_STORE_0582_0000 *(label)* | S>C | unknown | Exchange store: reply/notification. Exchange store / coin shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1815836 | located_only |
| `0x05820001` | EXCHANGE_STORE_0582_0001 *(label)* | S>C | unknown | Exchange store: reply/notification. Exchange store / coin shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273744 | located_only |
| `0x05820002` | EXCHANGE_STORE_0582_0002 *(label)* | C>S | empty body | Exchange store: request. Exchange store / coin shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2887945 | partial_layout |
| `0x05820003` | EXCHANGE_STORE_0582_0003 *(label)* | C>S | +10 undefined2 unknown; +14 undefined4 unknown; +18 undefined2 unknown | Exchange store: request. Exchange store / coin shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1815938 | partial_layout |
| `0x05820004` | EXCHANGE_STORE_0582_0004 *(label)* | S>C | unknown | Exchange store: reply/notification. Exchange store / coin shop. Likely reply to C>S 0x05820003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:36553 | located_only |
| `0x05820005` | EXCHANGE_STORE_0582_0005 *(label)* | C>S | +10 undefined2 unknown | Exchange store: request. Exchange store / coin shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1815836 | partial_layout |
| `0x05820006` | EXCHANGE_STORE_0582_0006 *(label)* | S>C | unknown | Exchange store: reply/notification. Exchange store / coin shop. Likely reply to C>S 0x05820005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273744 | located_only |

## 0x0583 — DekaPass

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05830000` | DEKAPASS_0583_0000 *(label)* | C>S | empty body | DekaPass: request. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05830000 open / pass info, no body, no lock (0x159ea70; callers AlarmWnd 0x10ef900 and the 'dekapass' chat command 0xc48960) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1806190 | partial_layout |
| `0x05830001` | DEKAPASS_0583_0001 *(label)* | S>C | unknown | DekaPass: reply/notification. DekaPass battle pass. Likely reply to C>S 0x05830000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1577690<br>decompiled-source/global-0.0.1/decompiled-named.c:1807013<br>decompiled-source/global-0.0.1/decompiled-named.c:36553 | explained |
| `0x05830002` | DEKAPASS_0583_0002 *(label)* | both | empty body | DekaPass: request and reply share this opcode. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05830002 mission list, no body, no lock (0x159eac0; btn_missionlist in CDekaPassWnd click 0x10eac30) *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1806211<br>decompiled-source/global-0.0.1/decompiled-named.c:3273874 | partial_layout |
| `0x05830003` | DEKAPASS_0583_0003 *(label)* | S>C | unknown | DekaPass: reply/notification. DekaPass battle pass. Likely reply to C>S 0x05830002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273874<br>decompiled-source/global-0.0.1/decompiled-named.c:36553 | explained |
| `0x05830004` | DEKAPASS_0583_0004 *(label)* | C>S | +10 ushort unknown | DekaPass: request. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05830004 claim one, size 0x14, takes request lock 0 (0x159eb10): +0 u8 kind (0 = btn_normal_k, 1 = btn_premium_k), +1 u8 level *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1806232 | explained |
| `0x05830005` | DEKAPASS_0583_0005 *(label)* | S>C | unknown | DekaPass: reply/notification. DekaPass battle pass. Likely reply to C>S 0x05830004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273874 | explained |
| `0x05830006` | DEKAPASS_0583_0006 *(label)* | both | empty body | DekaPass: request and reply share this opcode. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05830006 receive all, lock 0 (0x159eb90 via writer 0x1414750; btn_receiveall): +0 u16 total (= 3 + 2n), +2 u8 n, *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1806260<br>decompiled-source/global-0.0.1/decompiled-named.c:36553 | explained |
| `0x05830007` | DEKAPASS_0583_0007 *(label)* | S>C | unknown | DekaPass: reply/notification. DekaPass battle pass. Likely reply to C>S 0x05830006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1577690 | explained |
| `0x05830008` | DEKAPASS_0583_0008 *(label)* | S>C | unknown | DekaPass: reply/notification. DekaPass battle pass. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:428830 | explained |
| `0x05830009` | DEKAPASS_0583_0009 *(label)* | S>C | unknown | DekaPass: reply/notification. DekaPass battle pass. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1807013 | explained |
| `0x0583000a` | DEKAPASS_0583_000A *(label)* | C>S | empty body | DekaPass: request. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x0583000a sent by the open mission list every 60 s of window time (0x159ec50, caller 0x10ed614). No reply case exists. UNVERIFIED: premium state 0 for levels without a premium reward (client only tests ==2 / *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1806294 | partial_layout |

## 0x0584 — TalismanEffectTransform

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05840001` | TALISMANEFFECTTRANSFORM_0584_0001 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined4 unknown; +18 undefined4 unknown | TalismanEffectTransform: request. Talisman effect transform. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2219782<br>decompiled-source/global-0.0.1/decompiled-named.c:3196115 | partial_layout |
| `0x05840003` | TALISMANEFFECTTRANSFORM_0584_0003 *(label)* | C>S | empty body | TalismanEffectTransform: request. Talisman effect transform. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3196095 | partial_layout |

## 0x0600 — Message / mail (legacy)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0600000b` | MESSAGE_0600_000B *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined1 unknown; +1d undefined1 unknown; +1e undefined1 unknown; +1f ptr/copy unknown; +20 undefined1 unknown | Message / mail (legacy): request. Legacy message/mail. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:278935 | partial_layout |
| `0x0600000c` | MESSAGE_0600_000C *(label)* | C>S | unknown | Message / mail (legacy): request. Legacy message/mail. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:283232 | located_only |
| `0x0600000d` | MESSAGE_0600_000D *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown; +19 undefined1 unknown; +1a undefined1 unknown; +1b ptr/copy unknown; +1c undefined1 unknown; +1d undefined1 unknown | Message / mail (legacy): request. Legacy message/mail. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:281094 | partial_layout |

## 0x0602 — Enter event

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x06020000` | ENTER_EVENT_0602_0000 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1a undefined1 unknown; +1b undefined1 unknown; +1c undefined4 unknown; +20 uint unknown | Enter event: reply/notification. Enter event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:310592 | partial_layout |
| `0x06020002` | ENTER_EVENT_0602_0002 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown | Enter event: request. Enter event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:319718<br>decompiled-source/global-0.0.1/decompiled-named.c:320087<br>decompiled-source/global-0.0.1/decompiled-named.c:320565 … | partial_layout |

## 0x0603 — Effect event

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x06030006` | EFFECT_EVENT_0603_0006 *(label)* | S>C | +10 short unknown; +12 short unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c ushort unknown; +1e ushort unknown; +20 byte unknown | Effect event: reply/notification. Effect event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:308578 | partial_layout |
| `0x06030007` | EFFECT_EVENT_0603_0007 *(label)* | S>C | +10 short unknown; +12 ushort unknown; +14 int unknown; +18 int unknown; +1c undefined4 unknown | Effect event: reply/notification. Effect event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:308650 | partial_layout |

## 0x0604 — Skill

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x06040000` | SKILL_0604_0000 *(label)* | C>S | +10 undefined4 unknown; +14 ushort unknown; +16 undefined1 unknown; +18 undefined1 unknown; +19 undefined1 unknown; +1a undefined1 unknown; +1b undefined1 unknown; +1c undefined1 unknown; +1d undefined1 unknown; +1e undefined4 unknown; +22 undefined2 unknown | Skill: request. Skill net. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1955141 | partial_layout |

## 0x0700 — GameMaster / Developer / Dekaron provider

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x07000002` | GAMEMASTER_0700_0002 *(label)* | both | +10 ushort unknown; +12 undefined1 unknown; +13 undefined1 unknown; +14 undefined4 unknown | GameMaster / Developer / Dekaron provider: request and reply share this opcode. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1925362<br>decompiled-source/global-0.0.1/decompiled-named.c:3134970<br>decompiled-source/global-0.0.1/decompiled-named.c:3135378 … | partial_layout |
| `0x07000005` | GAMEMASTER_0700_0005 *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847478<br>decompiled-source/global-0.0.1/decompiled-named.c:1848157 | partial_layout |
| `0x07000006` | GAMEMASTER_0700_0006 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224556<br>decompiled-source/global-0.0.1/decompiled-named.c:3256799 | partial_layout |
| `0x07000007` | GAMEMASTER_0700_0007 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134876<br>decompiled-source/global-0.0.1/decompiled-named.c:3135284 | partial_layout |
| `0x07000008` | GAMEMASTER_0700_0008 *(label)* | S>C | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1925526 | partial_layout |
| `0x07000009` | GAMEMASTER_0700_0009 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined8 unknown; +28 undefined4 unknown; +2c undefined2 unknown; +2e undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847034<br>decompiled-source/global-0.0.1/decompiled-named.c:1847644<br>decompiled-source/global-0.0.1/decompiled-named.c:3135100 … | partial_layout |
| `0x0700000b` | GAMEMASTER_0700_000B *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134793<br>decompiled-source/global-0.0.1/decompiled-named.c:3134899<br>decompiled-source/global-0.0.1/decompiled-named.c:3135307 | partial_layout |
| `0x0700000c` | GAMEMASTER_0700_000C *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3157622 | located_only |
| `0x0700000d` | GAMEMASTER_0700_000D *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3157622 | located_only |
| `0x0700000e` | GAMEMASTER_0700_000E *(label)* | C>S | +10 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134926<br>decompiled-source/global-0.0.1/decompiled-named.c:3135334 | partial_layout |
| `0x07000010` | GAMEMASTER_0700_0010 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224610<br>decompiled-source/global-0.0.1/decompiled-named.c:2226584 | partial_layout |
| `0x07000013` | GAMEMASTER_0700_0013 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134950<br>decompiled-source/global-0.0.1/decompiled-named.c:3135358 | partial_layout |
| `0x07000014` | GAMEMASTER_0700_0014 *(label)* | S>C | +10 undefined2 unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224662<br>decompiled-source/global-0.0.1/decompiled-named.c:2226636 | partial_layout |
| `0x07000017` | GAMEMASTER_0700_0017 *(label)* | C>S | +10 ptr/copy unknown; +3a undefined1 unknown; +3b undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847930<br>decompiled-source/global-0.0.1/decompiled-named.c:1848230 | partial_layout |
| `0x07000018` | GAMEMASTER_0700_0018 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227073 | partial_layout |
| `0x07000022` | GAMEMASTER_0700_0022 *(label)* | C>S | +10 undefined1 unknown; +12 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3135029<br>decompiled-source/global-0.0.1/decompiled-named.c:3135051<br>decompiled-source/global-0.0.1/decompiled-named.c:3135475 … | partial_layout |
| `0x07000023` | GAMEMASTER_0700_0023 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000022 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224774<br>decompiled-source/global-0.0.1/decompiled-named.c:2226744 | partial_layout |
| `0x07000024` | GAMEMASTER_0700_0024 *(label)* | C>S | +10 short unknown; +12 short unknown; +14 short unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2223829<br>decompiled-source/global-0.0.1/decompiled-named.c:3135006<br>decompiled-source/global-0.0.1/decompiled-named.c:3135452 | partial_layout |
| `0x07000025` | GAMEMASTER_0700_0025 *(label)* | S>C | +10 char unknown; +12 undefined4 unknown; +16 undefined2 unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000024 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221109<br>decompiled-source/global-0.0.1/decompiled-named.c:2224719<br>decompiled-source/global-0.0.1/decompiled-named.c:2226693 | partial_layout |
| `0x07000026` | GAMEMASTER_0700_0026 *(label)* | C>S | +10 undefined2 unknown; +12 short unknown; +14 short unknown; +16 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847144<br>decompiled-source/global-0.0.1/decompiled-named.c:1847687<br>decompiled-source/global-0.0.1/decompiled-named.c:1848320 | partial_layout |
| `0x07000027` | GAMEMASTER_0700_0027 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000026 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2220982<br>decompiled-source/global-0.0.1/decompiled-named.c:2226779 | partial_layout |
| `0x07000028` | GAMEMASTER_0700_0028 *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847185<br>decompiled-source/global-0.0.1/decompiled-named.c:1847728<br>decompiled-source/global-0.0.1/decompiled-named.c:1848401 | partial_layout |
| `0x07000029` | GAMEMASTER_0700_0029 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000028 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2220659<br>decompiled-source/global-0.0.1/decompiled-named.c:2226896 | partial_layout |
| `0x0700002a` | GAMEMASTER_0700_002A *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847252<br>decompiled-source/global-0.0.1/decompiled-named.c:1847760<br>decompiled-source/global-0.0.1/decompiled-named.c:1848468 … | partial_layout |
| `0x0700002b` | GAMEMASTER_0700_002B *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2220699<br>decompiled-source/global-0.0.1/decompiled-named.c:2226934 | partial_layout |
| `0x0700002c` | GAMEMASTER_0700_002C *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847792<br>decompiled-source/global-0.0.1/decompiled-named.c:1847861<br>decompiled-source/global-0.0.1/decompiled-named.c:1848542 … | partial_layout |
| `0x0700002d` | GAMEMASTER_0700_002D *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown; +16 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227013 | partial_layout |
| `0x0700002e` | GAMEMASTER_0700_002E *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3135160<br>decompiled-source/global-0.0.1/decompiled-named.c:3135750 | partial_layout |
| `0x0700002f` | GAMEMASTER_0700_002F *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2226984 | partial_layout |
| `0x07000030` | GAMEMASTER_0700_0030 *(label)* | C>S | +10 undefined1 unknown; +11 undefined2 unknown; +14 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1848752<br>decompiled-source/global-0.0.1/decompiled-named.c:3135795 | partial_layout |
| `0x07000031` | GAMEMASTER_0700_0031 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000030 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227110 | partial_layout |
| `0x07000032` | GAMEMASTER_0700_0032 *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219871<br>decompiled-source/global-0.0.1/decompiled-named.c:3135860 | partial_layout |
| `0x07000033` | GAMEMASTER_0700_0033 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000032 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227234 | partial_layout |
| `0x07000034` | GAMEMASTER_0700_0034 *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219893<br>decompiled-source/global-0.0.1/decompiled-named.c:3135884 | partial_layout |
| `0x07000035` | GAMEMASTER_0700_0035 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000034 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227274 | partial_layout |
| `0x07000036` | GAMEMASTER_0700_0036 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3135840 | partial_layout |
| `0x07000037` | GAMEMASTER_0700_0037 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000036 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227197 | partial_layout |
| `0x07000038` | GAMEMASTER_0700_0038 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3135820 | partial_layout |
| `0x07000039` | GAMEMASTER_0700_0039 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000038 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227160 | partial_layout |
| `0x0700003a` | GAMEMASTER_0700_003A *(label)* | C>S | +10 char unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:255503<br>decompiled-source/global-0.0.1/decompiled-named.c:3134769<br>decompiled-source/global-0.0.1/decompiled-named.c:3136280 | partial_layout |
| `0x0700003b` | GAMEMASTER_0700_003B *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700003a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2850443 | located_only |
| `0x0700003c` | GAMEMASTER_0700_003C *(label)* | C>S | +10 short unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2223887<br>decompiled-source/global-0.0.1/decompiled-named.c:2226263<br>decompiled-source/global-0.0.1/decompiled-named.c:3135908 | partial_layout |
| `0x0700003e` | GAMEMASTER_0700_003E *(label)* | C>S | +10 short unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2223923<br>decompiled-source/global-0.0.1/decompiled-named.c:2226299<br>decompiled-source/global-0.0.1/decompiled-named.c:3135932 | partial_layout |
| `0x07000040` | GAMEMASTER_0700_0040 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2223959<br>decompiled-source/global-0.0.1/decompiled-named.c:2226335<br>decompiled-source/global-0.0.1/decompiled-named.c:3135956 | partial_layout |
| `0x07000041` | GAMEMASTER_0700_0041 *(label)* | S>C | +10 char unknown; +11 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000040 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221164<br>decompiled-source/global-0.0.1/decompiled-named.c:2224854<br>decompiled-source/global-0.0.1/decompiled-named.c:2227314 | partial_layout |
| `0x07000042` | GAMEMASTER_0700_0042 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2223980<br>decompiled-source/global-0.0.1/decompiled-named.c:2226356<br>decompiled-source/global-0.0.1/decompiled-named.c:3135976 | partial_layout |
| `0x07000043` | GAMEMASTER_0700_0043 *(label)* | S>C | +10 char unknown; +11 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000042 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221206<br>decompiled-source/global-0.0.1/decompiled-named.c:2224896<br>decompiled-source/global-0.0.1/decompiled-named.c:2227356 | partial_layout |
| `0x07000046` | GAMEMASTER_0700_0046 *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3148131 | located_only |
| `0x07000047` | GAMEMASTER_0700_0047 *(label)* | C>S | +10 int unknown; +14 int unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224038<br>decompiled-source/global-0.0.1/decompiled-named.c:2226377<br>decompiled-source/global-0.0.1/decompiled-named.c:3136020 | partial_layout |
| `0x07000048` | GAMEMASTER_0700_0048 *(label)* | S>C | +10 int unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000047 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221285<br>decompiled-source/global-0.0.1/decompiled-named.c:2224938<br>decompiled-source/global-0.0.1/decompiled-named.c:2227435 | partial_layout |
| `0x07000049` | GAMEMASTER_0700_0049 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224086<br>decompiled-source/global-0.0.1/decompiled-named.c:2226414<br>decompiled-source/global-0.0.1/decompiled-named.c:3136042 | partial_layout |
| `0x0700004a` | GAMEMASTER_0700_004A *(label)* | S>C | +10 int unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000049 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221322<br>decompiled-source/global-0.0.1/decompiled-named.c:2224975<br>decompiled-source/global-0.0.1/decompiled-named.c:2227472 | partial_layout |
| `0x0700004b` | GAMEMASTER_0700_004B *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134657<br>decompiled-source/global-0.0.1/decompiled-named.c:3135180<br>decompiled-source/global-0.0.1/decompiled-named.c:3135654 | partial_layout |
| `0x0700004c` | GAMEMASTER_0700_004C *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700004b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221360<br>decompiled-source/global-0.0.1/decompiled-named.c:2225012<br>decompiled-source/global-0.0.1/decompiled-named.c:2227510 | partial_layout |
| `0x0700004d` | GAMEMASTER_0700_004D *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134681<br>decompiled-source/global-0.0.1/decompiled-named.c:3135204<br>decompiled-source/global-0.0.1/decompiled-named.c:3135678 | partial_layout |
| `0x0700004e` | GAMEMASTER_0700_004E *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700004d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221397<br>decompiled-source/global-0.0.1/decompiled-named.c:2225049<br>decompiled-source/global-0.0.1/decompiled-named.c:2227547 | partial_layout |
| `0x0700004f` | GAMEMASTER_0700_004F *(label)* | C>S | +10 bool unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224001<br>decompiled-source/global-0.0.1/decompiled-named.c:3135996 | partial_layout |
| `0x07000050` | GAMEMASTER_0700_0050 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700004f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221248<br>decompiled-source/global-0.0.1/decompiled-named.c:2227398 | partial_layout |
| `0x07000052` | GAMEMASTER_0700_0052 *(label)* | C>S | +10 short unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224165<br>decompiled-source/global-0.0.1/decompiled-named.c:3136062 | partial_layout |
| `0x07000053` | GAMEMASTER_0700_0053 *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000052 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221434<br>decompiled-source/global-0.0.1/decompiled-named.c:2227584 | located_only |
| `0x07000054` | GAMEMASTER_0700_0054 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2224201<br>decompiled-source/global-0.0.1/decompiled-named.c:3136086 | partial_layout |
| `0x07000055` | GAMEMASTER_0700_0055 *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000054 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221464<br>decompiled-source/global-0.0.1/decompiled-named.c:2227614 | located_only |
| `0x07000056` | GAMEMASTER_0700_0056 *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847077<br>decompiled-source/global-0.0.1/decompiled-named.c:1848826 | partial_layout |
| `0x07000057` | GAMEMASTER_0700_0057 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000056 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221494<br>decompiled-source/global-0.0.1/decompiled-named.c:2227644 | partial_layout |
| `0x07000058` | GAMEMASTER_0700_0058 *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3135630 | partial_layout |
| `0x07000059` | GAMEMASTER_0700_0059 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000058 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227725 | partial_layout |
| `0x0700005a` | GAMEMASTER_0700_005A *(label)* | C>S | +10 short unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1897399<br>decompiled-source/global-0.0.1/decompiled-named.c:3135702 | partial_layout |
| `0x0700005b` | GAMEMASTER_0700_005B *(label)* | C>S | +10 short unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1897399<br>decompiled-source/global-0.0.1/decompiled-named.c:3135726 | partial_layout |
| `0x0700005c` | GAMEMASTER_0700_005C *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134725<br>decompiled-source/global-0.0.1/decompiled-named.c:3136236 | partial_layout |
| `0x0700005d` | GAMEMASTER_0700_005D *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700005c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221062<br>decompiled-source/global-0.0.1/decompiled-named.c:2226853 | partial_layout |
| `0x0700005e` | GAMEMASTER_0700_005E *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134705<br>decompiled-source/global-0.0.1/decompiled-named.c:3136216 | partial_layout |
| `0x0700005f` | GAMEMASTER_0700_005F *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700005e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221019<br>decompiled-source/global-0.0.1/decompiled-named.c:2226814 | partial_layout |
| `0x07000060` | GAMEMASTER_0700_0060 *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1925601 | located_only |
| `0x07000062` | GAMEMASTER_0700_0062 *(label)* | C>S | +10 ptr/copy unknown; +3a undefined1 unknown; +3c undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1848893 | partial_layout |
| `0x07000063` | GAMEMASTER_0700_0063 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000062 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227763 | partial_layout |
| `0x07000064` | GAMEMASTER_0700_0064 *(label)* | C>S | +10 ptr/copy unknown; +3a undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1848983 | partial_layout |
| `0x07000065` | GAMEMASTER_0700_0065 *(label)* | S>C | +3a char unknown; +40 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000064 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2227809 | partial_layout |

## 0x0800 — GameMaster / Developer

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x08000002` | GAMEMASTER_0800_0002 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined4 unknown; +1a undefined4 unknown; +1e undefined4 unknown; +22 undefined4 unknown; +26 undefined4 unknown; +2a undefined4 unknown; +2e undefined4 unknown; +32 undefined4 unknown; +36 undefined4 unknown; +3a undefined4 unknown; +3e undefined4 unknown; +42 undefined4 unknown; +46 undefined8 unknown; +4e undefined4 unknown; +52 undefined1 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1846942<br>decompiled-source/global-0.0.1/decompiled-named.c:1847552 | partial_layout |
| `0x08000003` | GAMEMASTER_0800_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +18 undefined4 unknown; +1c undefined4 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1847000<br>decompiled-source/global-0.0.1/decompiled-named.c:1847610 | partial_layout |
| `0x08000005` | GAMEMASTER_0800_0005 *(label)* | C>S | +10 char unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:255503<br>decompiled-source/global-0.0.1/decompiled-named.c:3134633<br>decompiled-source/global-0.0.1/decompiled-named.c:3134745 … | partial_layout |
| `0x08000006` | GAMEMASTER_0800_0006 *(label)* | S>C | +10 undefined1 unknown | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2220749<br>decompiled-source/global-0.0.1/decompiled-named.c:2224811<br>decompiled-source/global-0.0.1/decompiled-named.c:3134585 … | partial_layout |
| `0x0800000b` | GAMEMASTER_0800_000B *(label)* | C>S | +10 undefined2 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219779<br>decompiled-source/global-0.0.1/decompiled-named.c:3136106 | partial_layout |
| `0x0800000c` | GAMEMASTER_0800_000C *(label)* | S>C | +10 undefined2 unknown | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x0800000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2220792 | partial_layout |
| `0x0800000d` | GAMEMASTER_0800_000D *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219799<br>decompiled-source/global-0.0.1/decompiled-named.c:3136130 | partial_layout |
| `0x0800000e` | GAMEMASTER_0800_000E *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219819<br>decompiled-source/global-0.0.1/decompiled-named.c:3136154 | partial_layout |
| `0x0800000f` | GAMEMASTER_0800_000F *(label)* | C>S | empty body | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219839<br>decompiled-source/global-0.0.1/decompiled-named.c:3136178 | partial_layout |
| `0x08000010` | GAMEMASTER_0800_0010 *(label)* | S>C | +10 char unknown | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x0800000f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2220835 | partial_layout |
| `0x08000012` | GAMEMASTER_0800_0012 *(label)* | S>C | unknown | GameMaster / Developer: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x08000013` | GAMEMASTER_0800_0013 *(label)* | C>S | empty body | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219942 | partial_layout |
| `0x08000014` | GAMEMASTER_0800_0014 *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219961 | partial_layout |
| `0x08000015` | GAMEMASTER_0800_0015 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219981 | partial_layout |
| `0x08000016` | GAMEMASTER_0800_0016 *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178852 | partial_layout |
| `0x08000017` | GAMEMASTER_0800_0017 *(label)* | C>S | empty body | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2222858 | partial_layout |
| `0x08000018` | GAMEMASTER_0800_0018 *(label)* | C>S | empty body | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219839<br>decompiled-source/global-0.0.1/decompiled-named.c:3136178 | partial_layout |
| `0x08000019` | GAMEMASTER_0800_0019 *(label)* | S>C | +10 char unknown | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000018 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2220884 | partial_layout |
| `0x08000020` | GAMEMASTER_0800_0020 *(label)* | C>S | empty body | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2222879 | partial_layout |
| `0x08000021` | GAMEMASTER_0800_0021 *(label)* | S>C | +10 undefined4 unknown | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000020 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276836<br>decompiled-source/global-0.0.1/decompiled-named.c:3276853 | partial_layout |
| `0x08000022` | GAMEMASTER_0800_0022 *(label)* | C>S | empty body | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2222900 | partial_layout |
| `0x08000023` | GAMEMASTER_0800_0023 *(label)* | S>C | +10 uint unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined4 unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 undefined4 unknown; +3c undefined4 unknown; +40 undefined4 unknown; +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +5c undefined4 unknown; +60 undefined4 unknown | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000022 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2135995<br>decompiled-source/global-0.0.1/decompiled-named.c:2187973 | partial_layout |
| `0x08000024` | GAMEMASTER_0800_0024 *(label)* | C>S | empty body | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219839 | partial_layout |
| `0x08000025` | GAMEMASTER_0800_0025 *(label)* | S>C | +10 char unknown | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000024 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2220933 | partial_layout |
| `0x08000026` | GAMEMASTER_0800_0026 *(label)* | C>S | +10 undefined2 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134820<br>decompiled-source/global-0.0.1/decompiled-named.c:3135228 | partial_layout |
| `0x08000027` | GAMEMASTER_0800_0027 *(label)* | C>S | +10 char unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:220002 | partial_layout |
| `0x08000028` | GAMEMASTER_0800_0028 *(label)* | C>S | +10 char unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:220024 | partial_layout |
| `0x08000029` | GAMEMASTER_0800_0029 *(label)* | C>S | empty body | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:220046 | partial_layout |
| `0x08000030` | GAMEMASTER_0800_0030 *(label)* | S>C | +1c int unknown | GameMaster / Developer: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221642 | partial_layout |
| `0x08000031` | GAMEMASTER_0800_0031 *(label)* | S>C | +10 ptr unknown | GameMaster / Developer: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221718 | partial_layout |
| `0x08000032` | GAMEMASTER_0800_0032 *(label)* | S>C | +1b undefined1 unknown; +1c int unknown | GameMaster / Developer: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2221809 | partial_layout |

## 0x0900 — Guild

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x09000000` | GUILD_0900_0000 *(label)* | C>S | unknown | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2022257 | located_only |
| `0x09000001` | GUILD_0900_0001 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +20 undefined1 unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2025702 | partial_layout |
| `0x09000004` | GUILD_0900_0004 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09000005` | GUILD_0900_0005 *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160404 | partial_layout |
| `0x09000006` | GUILD_0900_0006 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09000007` | GUILD_0900_0007 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09000008` | GUILD_0900_0008 *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160479 | partial_layout |
| `0x09000009` | GUILD_0900_0009 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x0900000a` | GUILD_0900_000A *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x0900000b` | GUILD_0900_000B *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2022065 | partial_layout |
| `0x0900000c` | GUILD_0900_000C *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x0900000d` | GUILD_0900_000D *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3301202 | partial_layout |
| `0x0900000e` | GUILD_0900_000E *(label)* | S>C | +10 undefined4 unknown; +14 ptr unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000d (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2038843 | partial_layout |
| `0x0900000f` | GUILD_0900_000F *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160789 | partial_layout |
| `0x09000010` | GUILD_0900_0010 *(label)* | S>C | +10 undefined4 unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026734 | partial_layout |
| `0x09000011` | GUILD_0900_0011 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09000012` | GUILD_0900_0012 *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160454 | partial_layout |
| `0x09000013` | GUILD_0900_0013 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000012 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09000014` | GUILD_0900_0014 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2025830 | located_only |
| `0x09000015` | GUILD_0900_0015 *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160429 | partial_layout |
| `0x09000016` | GUILD_0900_0016 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09000017` | GUILD_0900_0017 *(label)* | C>S | unknown | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2022423 | located_only |
| `0x09000018` | GUILD_0900_0018 *(label)* | S>C | +10 undefined1 unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2025928 | partial_layout |
| `0x09000019` | GUILD_0900_0019 *(label)* | C>S | +10 ptr/copy unknown | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2022581 | partial_layout |
| `0x0900001a` | GUILD_0900_001A *(label)* | S>C | +10 undefined1 unknown; +11 ptr unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000019 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026005 | partial_layout |
| `0x0900001b` | GUILD_0900_001B *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026150 | located_only |
| `0x0900001d` | GUILD_0900_001D *(label)* | S>C | +13 byte unknown; +14 undefined1 unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276126 | partial_layout |

## 0x0901 — Guild

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x09010000` | GUILD_0901_0000 *(label)* | S>C | +10 char unknown | Guild: reply/notification. Guild notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028320 | partial_layout |
| `0x09010001` | GUILD_0901_0001 *(label)* | S>C | unknown | Guild: reply/notification. Guild notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029379 | located_only |

## 0x0902 — Guild

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x09020000` | ENTER_DONE | C>S | empty body | header only, sent after ENTER_WORLD | decompiled-source/global-0.0.1/decompiled-named.c:237019 | explained |
| `0x09020001` | GUILD_0902_0001 *(label)* | C>S | +3a char unknown | Guild: request. Guild UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023245 | partial_layout |
| `0x09020002` | GUILD_0902_0002 *(label)* | S>C | +10 undefined1 unknown | Guild: reply/notification. Guild UI. Likely reply to C>S 0x09020001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027522 | partial_layout |
| `0x09020003` | GUILD_0902_0003 *(label)* | S>C | unknown | Guild: reply/notification. Guild UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027608 | located_only |
| `0x09020004` | GUILD_0902_0004 *(label)* | both | +10 ptr/copy unknown; +3a ptr/copy unknown | Guild: request and reply share this opcode. Guild UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023345<br>decompiled-source/global-0.0.1/decompiled-named.c:2027460 | partial_layout |
| `0x09020005` | GUILD_0902_0005 *(label)* | S>C | unknown | Guild: reply/notification. Guild UI. Likely reply to C>S 0x09020004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |

## 0x0903 — Guild / GuildDungeon

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x09030000` | GUILD_0903_0000 *(label)* | C>S | +10 undefined4 unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160814 | partial_layout |
| `0x09030001` | GUILD_0903_0001 *(label)* | S>C | +10 int unknown; +14 undefined4 unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026907 | partial_layout |
| `0x09030002` | GUILD_0903_0002 *(label)* | C>S | empty body | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160872 | partial_layout |
| `0x09030003` | GUILD_0903_0003 *(label)* | S>C | +10 int unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026972 | partial_layout |
| `0x09030004` | GUILD_0903_0004 *(label)* | S>C | +14 undefined2 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined1 unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027386 | partial_layout |
| `0x09030005` | GUILD_0903_0005 *(label)* | C>S | empty body | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160897 | partial_layout |
| `0x09030006` | GUILD_0903_0006 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09030011` | GUILD_0903_0011 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160844 | partial_layout |
| `0x09030012` | GUILD_0903_0012 *(label)* | S>C | +10 int unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028819 | partial_layout |
| `0x09030014` | GUILD_0903_0014 *(label)* | C>S | +10 short unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2024209 | partial_layout |
| `0x09030015` | GUILD_0903_0015 *(label)* | S>C | +10 int unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030014 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028896 | partial_layout |
| `0x09030016` | GUILD_0903_0016 *(label)* | C>S | +10 short unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2024209 | partial_layout |
| `0x09030017` | GUILD_0903_0017 *(label)* | S>C | +10 int unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030016 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028933 | partial_layout |
| `0x09030018` | GUILD_0903_0018 *(label)* | C>S | +10 undefined4 unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160941 | partial_layout |
| `0x09030019` | GUILD_0903_0019 *(label)* | S>C | +10 int unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030018 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2025236 | partial_layout |
| `0x09030020` | GUILD_0903_0020 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2156287 | located_only |
| `0x09030021` | GUILD_0903_0021 *(label)* | both | empty body | Guild / GuildDungeon: request and reply share this opcode. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2156287<br>decompiled-source/global-0.0.1/decompiled-named.c:3186243 | partial_layout |
| `0x09030022` | GUILD_0903_0022 *(label)* | C>S | +10 char unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3186275 | partial_layout |
| `0x09030023` | GUILD_0903_0023 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030022 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2156364 | located_only |
| `0x09030024` | GUILD_0903_0024 *(label)* | C>S | +10 undefined4 unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3186439 | partial_layout |
| `0x09030025` | GUILD_0903_0025 *(label)* | C>S | +10 undefined4 unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160499 | partial_layout |
| `0x09030026` | GUILD_0903_0026 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined1 unknown; +22 undefined1 unknown; +23 undefined1 unknown; +24 ptr/copy unknown; +4e ptr/copy unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160556 | partial_layout |
| `0x09030027` | GUILD_0903_0027 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030026 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09030028` | GUILD_0903_0028 *(label)* | C>S | empty body | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160520 | partial_layout |
| `0x09030029` | GUILD_0903_0029 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030028 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x0903002a` | GUILD_0903_002A *(label)* | S>C | +10 undefined4 unknown; +4c short unknown; +76 undefined2 unknown; +78 undefined2 unknown; +7a undefined1 unknown; +7c undefined2 unknown; +98 undefined4 unknown; +9c undefined4 unknown; +a0 undefined8 unknown; +a8 undefined4 unknown; +ac undefined2 unknown; +ae undefined1 unknown; +af undefined1 unknown; +b0 undefined4 unknown; +b4 short unknown; +de short unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029428 | partial_layout |
| `0x0903002b` | GUILD_0903_002B *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x0903002c` | GUILD_0903_002C *(label)* | C>S | +10 ptr/copy unknown; +1e ptr/copy unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023101 | partial_layout |
| `0x0903002d` | GUILD_0903_002D *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x0903002c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x0903002e` | GUILD_0903_002E *(label)* | C>S | +10 ptr/copy unknown; +3c undefined4 unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023151 | partial_layout |
| `0x0903002f` | GUILD_0903_002F *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x0903002e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09030030` | GUILD_0903_0030 *(label)* | C>S | empty body | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160538 | partial_layout |
| `0x09030031` | GUILD_0903_0031 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030030 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09030032` | GUILD_0903_0032 *(label)* | S>C | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined1 unknown; +3e short unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029582 | partial_layout |
| `0x09030033` | GUILD_0903_0033 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09030034` | GUILD_0903_0034 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09030035` | GUILD_0903_0035 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09030036` | GUILD_0903_0036 *(label)* | S>C | +10 byte unknown; +11 byte unknown; +12 undefined8 unknown; +1a undefined4 unknown; +1e undefined2 unknown; +20 undefined1 unknown; +21 undefined1 unknown; +22 byte unknown; +4e short unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029680 | partial_layout |
| `0x09030037` | GUILD_0903_0037 *(label)* | C>S | +10 ptr/copy unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160630 | partial_layout |
| `0x09030038` | GUILD_0903_0038 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030037 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x09030039` | GUILD_0903_0039 *(label)* | C>S | +10 ptr/copy unknown; +1e ptr/copy unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023187 | partial_layout |
| `0x0903003a` | GUILD_0903_003A *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030039 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |

## 0x0a00 — Chat

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a000000` | CHAT_0A00_0000 *(label)* | S>C | unknown | Chat: reply/notification. Chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273215 | located_only |

## 0x0a01 — Chat

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a010009` | CHAT_0A01_0009 *(label)* | both | +10 undefined4 unknown; +18 undefined4 unknown; +3c undefined1 unknown; +40 undefined4 unknown; +214 undefined4 unknown | Chat: request and reply share this opcode. Chat channels. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1922204<br>decompiled-source/global-0.0.1/decompiled-named.c:1924096 | partial_layout |
| `0x0a010010` | CHAT_0A01_0010 *(label)* | C>S | +10 undefined4 unknown; +18 undefined4 unknown; +3c undefined1 unknown; +40 undefined4 unknown; +214 undefined4 unknown | Chat: request. Chat channels. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1922204 | partial_layout |
| `0x0a010013` | CHAT_0A01_0013 *(label)* | S>C | +90 undefined2 unknown; +92 undefined2 unknown | Chat: reply/notification. Chat channels. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1926052 | partial_layout |

## 0x0a02 — Messenger

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a020000` | MESSENGER_0A02_0000 *(label)* | both | +3a undefined1 unknown; +3c undefined2 unknown; +66 undefined1 unknown | Messenger: request and reply share this opcode. Messenger (friends) list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845058<br>decompiled-source/global-0.0.1/decompiled-named.c:1845854 | partial_layout |
| `0x0a020001` | MESSENGER_0A02_0001 *(label)* | S>C | +3c undefined1 unknown | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845917 | partial_layout |
| `0x0a020002` | MESSENGER_0A02_0002 *(label)* | S>C | +10 ptr unknown; +3a undefined1 unknown; +3c undefined1 unknown; +3e undefined2 unknown; +40 undefined1 unknown; +41 char unknown; +42 undefined1 unknown | Messenger: reply/notification. Messenger (friends) list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1846014 | partial_layout |
| `0x0a020003` | MESSENGER_0A02_0003 *(label)* | C>S | +3c ptr/copy unknown; +66 undefined1 unknown; +67 undefined1 unknown | Messenger: request. Messenger (friends) list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845307 | partial_layout |
| `0x0a020004` | MESSENGER_0A02_0004 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1846076 | located_only |
| `0x0a020005` | MESSENGER_0A02_0005 *(label)* | C>S | +3c ptr/copy unknown | Messenger: request. Messenger (friends) list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845260 | partial_layout |
| `0x0a020006` | MESSENGER_0A02_0006 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256503 | located_only |
| `0x0a020007` | MESSENGER_0A02_0007 *(label)* | C>S | +3c ptr/copy unknown; +66 undefined1 unknown | Messenger: request. Messenger (friends) list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845373 | partial_layout |
| `0x0a020008` | MESSENGER_0A02_0008 *(label)* | S>C | +3a undefined1 unknown; +3c char unknown; +3e ptr unknown | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1846097 | partial_layout |
| `0x0a020009` | MESSENGER_0A02_0009 *(label)* | S>C | +10 ptr unknown; +3a undefined1 unknown; +66 undefined1 unknown; +68 undefined2 unknown; +6a undefined1 unknown; +6b char unknown; +6c undefined1 unknown | Messenger: reply/notification. Messenger (friends) list. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1846201 | partial_layout |

## 0x0a03 — Messenger

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a030000` | MESSENGER_0A03_0000 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845582 | located_only |
| `0x0a030001` | MESSENGER_0A03_0001 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845626 | located_only |

## 0x0a04 — Messenger

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a040000` | MESSENGER_0A04_0000 *(label)* | C>S | +3c undefined2 unknown; +66 undefined1 unknown | Messenger: request. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845159 | partial_layout |
| `0x0a040001` | MESSENGER_0A04_0001 *(label)* | S>C | +3c undefined1 unknown | Messenger: reply/notification. Messenger. Likely reply to C>S 0x0a040000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1846263 | partial_layout |
| `0x0a040004` | MESSENGER_0A04_0004 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256503 | located_only |
| `0x0a040006` | MESSENGER_0A04_0006 *(label)* | S>C | +3c ptr unknown; +7b undefined1 unknown | Messenger: reply/notification. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1846422 | partial_layout |
| `0x0a040007` | MESSENGER_BLACKLIST_REMOVAL_PARTIAL_0A04_0007 *(label)* | C>S | +3a undefined1 unknown; +3c ptr/copy unknown | Messenger: request. Messenger. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x0a040007 packet size 0x68, selector at packet+0x3a, UTF16 name at +0x3c. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1845421 | partial_layout |
| `0x0a040008` | MESSENGER_BLACKLIST_REMOVAL_PARTIAL_0A04_0008 *(label)* | S>C | +3c char unknown; +3e ptr unknown; +68 undefined1 unknown | Messenger: reply/notification. Messenger. Likely reply to C>S 0x0a040007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1846328 | partial_layout |

## 0x0b10 — Tool

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0b100012` | TOOL_0B10_0012 *(label)* | S>C | unknown | Tool: reply/notification. Tool net handler. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3180822 | located_only |

## 0x0c00 — NewLetter (mail)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0c000000` | NEWLETTER_MAIL_0C00_0000 *(label)* | C>S | +10 undefined4 unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3175032 | partial_layout |
| `0x0c000001` | NEWLETTER_MAIL_0C00_0001 *(label)* | S>C | +10 int unknown; +14 undefined2 unknown; +16 undefined2 unknown; +18 ushort unknown; +1a char unknown; +1c undefined4 unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097248 | partial_layout |
| `0x0c000002` | NEWLETTER_MAIL_0C00_0002 *(label)* | S>C | unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097178 | located_only |
| `0x0c000003` | MAIL_COUNTS_PARTIAL_0C00_0003 *(label)* | C>S | empty body | NewLetter (mail): request. Mail list/read/send/delete. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: Global mail count request0x0c000003 builder175d4b0: header only. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3175056 | partial_layout |
| `0x0c000004` | MAIL_COUNTS_PARTIAL_0C00_0004 *(label)* | S>C | +10 int unknown; +14 undefined2 unknown; +16 undefined2 unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097416 | explained |
| `0x0c000005` | NEWLETTER_MAIL_0C00_0005 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2096992 | partial_layout |
| `0x0c000006` | NEWLETTER_MAIL_0C00_0006 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 int unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097599 | partial_layout |
| `0x0c000007` | NEWLETTER_MAIL_0C00_0007 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097017 | partial_layout |
| `0x0c000008` | NEWLETTER_MAIL_0C00_0008 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 int unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097658 | partial_layout |
| `0x0c000009` | NEWLETTER_MAIL_0C00_0009 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097040 | partial_layout |
| `0x0c00000a` | NEWLETTER_MAIL_0C00_000A *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 int unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097717 | partial_layout |
| `0x0c00000b` | NEWLETTER_MAIL_0C00_000B *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097063 | partial_layout |
| `0x0c00000c` | NEWLETTER_MAIL_0C00_000C *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 int unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c00000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097785 | partial_layout |
| `0x0c00000d` | NEWLETTER_MAIL_0C00_000D *(label)* | S>C | unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097235 | located_only |
| `0x0c00000e` | NEWLETTER_MAIL_0C00_000E *(label)* | C>S | +10 ptr/copy unknown; +3a ptr/copy unknown; +6e undefined1 unknown; +6f undefined2 unknown; +71 undefined1 unknown; +78 undefined4 unknown; +7c undefined4 unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3174947 | partial_layout |
| `0x0c00000f` | NEWLETTER_MAIL_0C00_000F *(label)* | S>C | unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c00000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2097364 | located_only |

## 0x0d00 — CashShop / VipShop

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0d000000` | CASHSHOP_0D00_0000 *(label)* | C>S | unknown | CashShop / VipShop: request. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2072608 | located_only |
| `0x0d000001` | CASHSHOP_0D00_0001 *(label)* | S>C | +10 uint unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c char unknown | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2076345 | partial_layout |
| `0x0d000003` | CASHSHOP_0D00_0003 *(label)* | S>C | +10 int unknown; +6c int unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077267 | partial_layout |
| `0x0d000005` | CASHSHOP_0D00_0005 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077335 | located_only |
| `0x0d000008` | CASHSHOP_0D00_0008 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077349 | located_only |
| `0x0d000009` | CASHSHOP_0D00_0009 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077413 | located_only |
| `0x0d00000a` | CASHSHOP_0D00_000A *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077513 | located_only |
| `0x0d00000b` | CASHSHOP_0D00_000B *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077589 | located_only |
| `0x0d00000c` | CASHSHOP_0D00_000C *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077646 | located_only |
| `0x0d00000d` | CASHSHOP_0D00_000D *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077760 | located_only |
| `0x0d00000e` | CASHSHOP_0D00_000E *(label)* | S>C | +10 undefined4 unknown; +14 undefined1 unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077809 | partial_layout |
| `0x0d00000f` | CASHSHOP_0D00_000F *(label)* | S>C | +13 char unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077931 | partial_layout |
| `0x0d000010` | CASHSHOP_0D00_0010 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2078014 | located_only |
| `0x0d000013` | CASHSHOP_0D00_0013 *(label)* | S>C | +10 undefined2 unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1997660 | partial_layout |
| `0x0d000014` | CASHSHOP_0D00_0014 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077703 | located_only |
| `0x0d000015` | CASHSHOP_0D00_0015 *(label)* | C>S | +10 ptr/copy unknown; +25 byte unknown; +1e8 undefined1 unknown | CashShop / VipShop: request. Cash shop. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x0d000015 buy, size 0x1ec. Built by the D-Shop UI 0x1735bb0 (+0x1e8 = 0) and the VIP shop UI 0x17c7740 (+0x1e8 = 1). Body offsets: *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2071562<br>decompiled-source/global-0.0.1/decompiled-named.c:2165834 | partial_layout |
| `0x0d000016` | CASHSHOP_0D00_0016 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 byte unknown; +8c int unknown; +90 undefined4 unknown; +94 char unknown | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d000015 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S020: S>C 0x0d000016 buy result (case 0x174078c -> 0x173d270), size 0x95: +0x00 i64 (2 dwords to [0x22c0404]->vf+0x48; UNVERIFIED balance), *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2076520 | partial_layout |
| `0x0d000017` | CASHSHOP_0D00_0017 *(label)* | C>S | +10 undefined1 unknown; +250 undefined1 unknown; +27c byte unknown | CashShop / VipShop: request. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2071643<br>decompiled-source/global-0.0.1/decompiled-named.c:2071810 | partial_layout |
| `0x0d000018` | CASHSHOP_0D00_0018 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +44 byte unknown; +b8 int unknown; +bc undefined4 unknown | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d000017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2077040 | partial_layout |
| `0x0d00001a` | CASHSHOP_0D00_001A *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2078232 | located_only |
| `0x0d00001b` | CASHSHOP_0D00_001B *(label)* | S>C | +10 undefined3 unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2078333 | partial_layout |
| `0x0d00001c` | VIPSHOP_0D00_001C *(label)* | C>S | +10 bool unknown | CashShop / VipShop: request. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3188074 | explained |
| `0x0d00001d` | CASHSHOP_0D00_001D *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d00001c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2078409 | located_only |
| `0x0d00001e` | CASHSHOP_0D00_001E *(label)* | S>C | +10 int unknown; +14 undefined4 unknown; +22 short unknown; +6c int unknown; +73 char unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2078438 | partial_layout |
| `0x0d00001f` | CASHSHOP_0D00_001F *(label)* | C>S | +10 undefined1 unknown | CashShop / VipShop: request. Cash shop. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3169742<br>decompiled-source/global-0.0.1/decompiled-named.c:3188269 | partial_layout |
| `0x0d000020` | CASHSHOP_0D00_0020 *(label)* | S>C | +10 char unknown; +11 undefined1 unknown; +14 ptr unknown | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d00001f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2078609 | partial_layout |

## 0x0e00 — Target / attack

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0e000002` | TARGET_NORMAL_ATTACK_0E00_0002 *(label)* | C>S | +2d undefined4 unknown; +31 undefined4 unknown; +38 undefined4 unknown; +3d undefined1 unknown | Target / attack: request. Normal attack. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: monster the Global client sent C>S 0x0e000002, 48-byte body every ~0.6 s: *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:219915 | partial_layout |

## 0x0e01 — Monster AI

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0e010002` | MONSTER_AI_0E01_0002 *(label)* | C>S | +10 undefined4 unknown; +31 undefined4 unknown; +35 undefined4 unknown | Monster AI: request. Monster attack. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:279828<br>decompiled-source/global-0.0.1/decompiled-named.c:280366 | partial_layout |

## 0x0e03 — Attack (misc)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0e030000` | ATTACK_MISC_0E03_0000 *(label)* | C>S | +10 int unknown; +39 undefined1 unknown | Attack (misc): request. Attack. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:284055 | partial_layout |

## 0x0f00 — Siege (misc)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0f000004` | SIEGE_MISC_0F00_0004 *(label)* | S>C | +10 ptr unknown | Siege (misc): reply/notification. Siege notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054007 | partial_layout |
| `0x0f000005` | SIEGE_MISC_0F00_0005 *(label)* | S>C | +10 ptr unknown | Siege (misc): reply/notification. Siege notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054025 | partial_layout |

## 0x0f02 — Siege

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0f020000` | SIEGE_0F02_0000 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165217 | partial_layout |
| `0x0f020001` | SIEGE_0F02_0001 *(label)* | S>C | +10 int unknown; +18 undefined4 unknown; +1c undefined4 unknown | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2052952 | partial_layout |
| `0x0f020002` | SIEGE_0F02_0002 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165241 | partial_layout |
| `0x0f020003` | SIEGE_0F02_0003 *(label)* | S>C | +10 int unknown | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053130 | partial_layout |
| `0x0f020004` | SIEGE_0F02_0004 *(label)* | C>S | +10 undefined1 unknown | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165337 | partial_layout |
| `0x0f020005` | SIEGE_0F02_0005 *(label)* | S>C | +10 int unknown; +18 undefined4 unknown; +1c int unknown | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053400 | partial_layout |
| `0x0f020007` | SIEGE_0F02_0007 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165367 | partial_layout |
| `0x0f02000a` | SIEGE_0F02_000A *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165391 | partial_layout |
| `0x0f02000d` | SIEGE_0F02_000D *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165415 | partial_layout |
| `0x0f020010` | SIEGE_0F02_0010 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165313 | partial_layout |
| `0x0f020012` | SIEGE_0F02_0012 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3165289 | partial_layout |
| `0x0f020013` | SIEGE_0F02_0013 *(label)* | S>C | +10 int unknown | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020012 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2052837 | partial_layout |

## 0x0f03 — Siege (misc)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0f030008` | SIEGE_MISC_0F03_0008 *(label)* | S>C | unknown | Siege (misc): reply/notification. Siege notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2052434 | located_only |

## 0x1000 — Shop (misc)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x10000001` | SHOP_MISC_1000_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown; +18 undefined1 unknown; +19 undefined1 unknown | Shop (misc): request. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3261769<br>decompiled-source/global-0.0.1/decompiled-named.c:3299036 | partial_layout |
| `0x10000002` | SHOP_MISC_1000_0002 *(label)* | S>C | +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +60 undefined4 unknown; +68 undefined4 unknown; +6c undefined2 unknown; +70 undefined4 unknown; +74 char unknown | Shop (misc): reply/notification. Shop notices. Likely reply to C>S 0x10000001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1952090 | partial_layout |
| `0x10000003` | SHOP_MISC_1000_0003 *(label)* | S>C | +10 undefined4 unknown; +14 byte unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945826 | partial_layout |
| `0x10000004` | SHOP_MISC_1000_0004 *(label)* | S>C | +10 ptr unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945919 | partial_layout |
| `0x10000005` | SHOP_MISC_1000_0005 *(label)* | S>C | unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1945969 | located_only |
| `0x10000006` | SHOP_MISC_1000_0006 *(label)* | S>C | +10 ptr unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946029 | partial_layout |
| `0x10000007` | SHOP_MISC_1000_0007 *(label)* | S>C | +10 ptr unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946077 | partial_layout |
| `0x10000008` | SHOP_MISC_1000_0008 *(label)* | S>C | +10 ptr unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946222 | partial_layout |
| `0x10000009` | SHOP_MISC_1000_0009 *(label)* | S>C | +10 ptr unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946125 | partial_layout |
| `0x10000010` | SHOP_MISC_1000_0010 *(label)* | S>C | +10 undefined4 unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946173 | partial_layout |
| `0x10000011` | SHOP_MISC_1000_0011 *(label)* | S>C | +10 undefined3 unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1946943 | partial_layout |

## 0x1100 — Guild (extended)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11000004` | GUILD_EXTENDED_1100_0004 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3275403 | located_only |
| `0x11000005` | GUILD_EXTENDED_1100_0005 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x11000006` | GUILD_EXTENDED_1100_0006 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028566 | located_only |
| `0x11000007` | GUILD_EXTENDED_1100_0007 *(label)* | S>C | +44 ptr unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028642 | partial_layout |
| `0x11000008` | GUILD_EXTENDED_1100_0008 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x1100000c` | GUILD_EXTENDED_1100_000C *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x11000010` | GUILD_EXTENDED_1100_0010 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |

## 0x1101 — Guild

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11010000` | GUILD_1101_0000 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160672 | located_only |
| `0x11010001` | GUILD_1101_0001 *(label)* | S>C | +44 undefined4 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11010000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026798 | partial_layout |
| `0x11010003` | GUILD_1101_0003 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023774 | located_only |
| `0x11010004` | GUILD_1101_0004 *(label)* | S>C | +44 char unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11010003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026266 | partial_layout |
| `0x11010005` | GUILD_1101_0005 *(label)* | S>C | unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029068 | located_only |
| `0x11010006` | GUILD_1101_0006 *(label)* | C>S | +44 undefined2 unknown; +46 undefined2 unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023826 | partial_layout |
| `0x11010007` | GUILD_1101_0007 *(label)* | S>C | +48 undefined4 unknown; +4c undefined4 unknown; +58 undefined1 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11010006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026313 | partial_layout |
| `0x11010008` | GUILD_1101_0008 *(label)* | S>C | +44 undefined2 unknown; +46 undefined2 unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029121 | partial_layout |
| `0x11010009` | GUILD_1101_0009 *(label)* | C>S | +44 undefined1 unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023939 | partial_layout |
| `0x1101000a` | GUILD_1101_000A *(label)* | S>C | +44 undefined4 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11010009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026409 | partial_layout |
| `0x1101000b` | GUILD_1101_000B *(label)* | S>C | unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029173 | located_only |
| `0x1101000c` | GUILD_1101_000C *(label)* | C>S | +44 undefined1 unknown; +48 undefined4 unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160761 | partial_layout |
| `0x1101000d` | GUILD_1101_000D *(label)* | S>C | +44 undefined4 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x1101000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026467 | partial_layout |
| `0x1101000f` | GUILD_1101_000F *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2024690 | located_only |
| `0x11010010` | GUILD_1101_0010 *(label)* | S>C | +44 undefined4 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x1101000f (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026525 | partial_layout |
| `0x11010011` | GUILD_1101_0011 *(label)* | S>C | +44 byte unknown; +48 undefined4 unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029299 | partial_layout |
| `0x11010018` | GUILD_1101_0018 *(label)* | S>C | unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |

## 0x1102 — Guild

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11020000` | GUILD_1102_0000 *(label)* | S>C | +6e char unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028367 | partial_layout |
| `0x11020005` | GUILD_1102_0005 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160715 | located_only |
| `0x11020006` | GUILD_1102_0006 *(label)* | S>C | +44 undefined4 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11020005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027753 | partial_layout |
| `0x11020007` | GUILD_1102_0007 *(label)* | C>S | +44 ptr/copy unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023412 | partial_layout |
| `0x11020008` | GUILD_1102_0008 *(label)* | S>C | +70 undefined4 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11020007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027824 | partial_layout |
| `0x11020009` | GUILD_1102_0009 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2024706 | located_only |
| `0x1102000a` | GUILD_1102_000A *(label)* | S>C | +44 undefined4 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11020009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026588 | partial_layout |
| `0x1102000b` | GUILD_1102_000B *(label)* | S>C | unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x1102000c` | GUILD_1102_000C *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2024157 | located_only |
| `0x1102000d` | GUILD_1102_000D *(label)* | S>C | +44 undefined4 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x1102000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2026651 | partial_layout |
| `0x1102000e` | GUILD_1102_000E *(label)* | C>S | +44 ptr/copy unknown; +45 ptr/copy unknown; +d0 int unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3160965 | partial_layout |
| `0x1102000f` | GUILD_1102_000F *(label)* | S>C | +44 int unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x1102000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2025552 | partial_layout |
| `0x11020010` | GUILD_1102_0010 *(label)* | S>C | unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2025650 | located_only |

## 0x1103 — Guild

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11030000` | GUILD_1103_0000 *(label)* | both | +284 undefined4 unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023475<br>decompiled-source/global-0.0.1/decompiled-named.c:3275414 | partial_layout |
| `0x11030001` | GUILD_1103_0001 *(label)* | both | +2d8 undefined4 unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023654<br>decompiled-source/global-0.0.1/decompiled-named.c:3262668 | partial_layout |
| `0x11030002` | GUILD_1103_0002 *(label)* | S>C | +44 undefined1 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11030001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028970 | partial_layout |
| `0x11030003` | GUILD_1103_0003 *(label)* | both | +44 undefined2 unknown; +46 undefined1 unknown; +4a undefined1 unknown; +4c undefined2 unknown; +4e short unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027908<br>decompiled-source/global-0.0.1/decompiled-named.c:3160740 | partial_layout |
| `0x11030004` | GUILD_1103_0004 *(label)* | both | +44 ptr/copy unknown; +98 undefined2 unknown; +9a undefined1 unknown; +9e undefined1 unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2023881<br>decompiled-source/global-0.0.1/decompiled-named.c:2028002 | partial_layout |
| `0x11030005` | GUILD_1103_0005 *(label)* | both | +44 undefined2 unknown; +46 undefined1 unknown; +4a undefined1 unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028184<br>decompiled-source/global-0.0.1/decompiled-named.c:3160380 | partial_layout |
| `0x11030006` | GUILD_1103_0006 *(label)* | S>C | unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11030005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028240 | located_only |
| `0x11030007` | GUILD_1103_0007 *(label)* | both | unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2024674<br>decompiled-source/global-0.0.1/decompiled-named.c:3262668 | located_only |
| `0x11030008` | GUILD_1103_0008 *(label)* | S>C | +44 int unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11030007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2029022 | partial_layout |
| `0x1103000a` | GUILD_1103_000A *(label)* | S>C | +9a undefined2 unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2028058 | partial_layout |

## 0x1104 — GuildDungeonRanking

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11040023` | GUILDDUNGEONRANKING_1104_0023 *(label)* | S>C | unknown | GuildDungeonRanking: reply/notification. Guild dungeon ranking. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3186423 | located_only |

## 0x1105 — Guild (extended)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11050000` | GUILD_EXTENDED_1105_0000 *(label)* | S>C | +70 undefined4 unknown; +74 undefined4 unknown; +78 undefined4 unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027062 | partial_layout |
| `0x11050001` | GUILD_EXTENDED_1105_0001 *(label)* | S>C | +44 undefined2 unknown; +48 undefined4 unknown; +4c undefined4 unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027171 | partial_layout |
| `0x11050009` | GUILD_EXTENDED_1105_0009 *(label)* | S>C | +70 undefined4 unknown; +74 undefined4 unknown; +78 undefined4 unknown; +7c undefined4 unknown; +84 undefined4 unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027248 | partial_layout |
| `0x11050010` | GUILD_EXTENDED_1105_0010 *(label)* | S>C | +48 undefined4 unknown; +50 undefined4 unknown; +84 undefined4 unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2027313 | partial_layout |
| `0x11050013` | GUILD_EXTENDED_1105_0013 *(label)* | S>C | +44 undefined4 unknown; +48 undefined4 unknown; +4c undefined4 unknown; +50 undefined4 unknown; +54 undefined4 unknown; +58 undefined4 unknown; +5c undefined4 unknown; +60 undefined4 unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2025319 | partial_layout |
| `0x11050014` | GUILD_EXTENDED_1105_0014 *(label)* | S>C | +44 undefined4 unknown; +48 undefined4 unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2156454 | partial_layout |
| `0x11050015` | GUILD_EXTENDED_1105_0015 *(label)* | S>C | +44 undefined4 unknown; +48 undefined4 unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2156587 | partial_layout |

## 0x1200 — (unattributed)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x12000000` | UNATTRIBUTED_1200_0000 *(label)* | S>C | +48 undefined4 unknown; +4c undefined4 unknown; +60 undefined1 unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276262 | partial_layout |
| `0x12000001` | UNATTRIBUTED_1200_0001 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276285 | located_only |
| `0x12000002` | UNATTRIBUTED_1200_0002 *(label)* | S>C | +48 ptr unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053987 | partial_layout |
| `0x12000003` | UNATTRIBUTED_1200_0003 *(label)* | S>C | +48 ptr unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2054045 | partial_layout |

## 0x1202 — (unattributed)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x12020000` | UNATTRIBUTED_1202_0000 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053589 | located_only |
| `0x12020001` | UNATTRIBUTED_1202_0001 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053638 | located_only |
| `0x12020002` | UNATTRIBUTED_1202_0002 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x12020003` | UNATTRIBUTED_1202_0003 *(label)* | S>C | +44 undefined4 unknown; +48 int unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053500 | partial_layout |
| `0x12020004` | UNATTRIBUTED_1202_0004 *(label)* | S>C | +44 undefined1 unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2053712 | partial_layout |
| `0x12020005` | UNATTRIBUTED_1202_0005 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x12020006` | UNATTRIBUTED_1202_0006 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263452 | located_only |
| `0x12020007` | UNATTRIBUTED_1202_0007 *(label)* | S>C | +44 int unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2052483 | partial_layout |

## 0x1300 — Pet

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x13000000` | PET_1300_0000 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Pet: request. Pet. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2081174 | partial_layout |
| `0x13000001` | PET_1300_0001 *(label)* | S>C | unknown | Pet: reply/notification. Pet. Likely reply to C>S 0x13000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082576 | located_only |
| `0x13000002` | PET_1300_0002 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 undefined2 unknown; +15 undefined1 unknown | Pet: request. Pet. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2081230 | partial_layout |
| `0x13000003` | PET_1300_0003 *(label)* | S>C | +10 int unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown | Pet: reply/notification. Pet. Likely reply to C>S 0x13000002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082806 | partial_layout |
| `0x13000004` | PET_1300_0004 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Pet: request. Pet. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2081274 | partial_layout |
| `0x13000005` | PET_1300_0005 *(label)* | S>C | +10 int unknown | Pet: reply/notification. Pet. Likely reply to C>S 0x13000004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082920 | partial_layout |
| `0x13000010` | PET_1300_0010 *(label)* | S>C | +14 undefined4 unknown; +18 undefined1 unknown | Pet: reply/notification. Pet. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2082748 | partial_layout |

## 0x1400 — Messenger

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x14000001` | MESSENGER_1400_0001 *(label)* | C>S | +4c char unknown; +4d char unknown | Messenger: request. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134454 | partial_layout |
| `0x14000002` | MESSENGER_1400_0002 *(label)* | both | +14 ptr unknown; +44 undefined1 unknown; +48 undefined1 unknown; +4a undefined2 unknown; +4c undefined1 unknown; +4d char unknown; +4e ptr/copy unknown; +78 undefined1 unknown | Messenger: request and reply share this opcode. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1844835<br>decompiled-source/global-0.0.1/decompiled-named.c:1845679 | partial_layout |

## 0x1401 — Messenger

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x14010001` | MESSENGER_1401_0001 *(label)* | both | +44 undefined1 unknown; +274 undefined4 unknown; +280 undefined1 unknown | Messenger: request and reply share this opcode. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1844883<br>decompiled-source/global-0.0.1/decompiled-named.c:1845741 | partial_layout |
| `0x14010002` | MESSENGER_1401_0002 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger. Likely reply to C>S 0x14010001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256503 | located_only |
| `0x14010004` | MESSENGER_1401_0004 *(label)* | S>C | +14 ptr unknown; +44 undefined1 unknown | Messenger: reply/notification. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273281 | partial_layout |
| `0x14010005` | MESSENGER_1401_0005 *(label)* | C>S | unknown | Messenger: request. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3134481 | located_only |
| `0x14010006` | MESSENGER_1401_0006 *(label)* | both | +14 undefined2 unknown; +44 undefined1 unknown; +48 ptr/copy unknown | Messenger: request and reply share this opcode. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1844973<br>decompiled-source/global-0.0.1/decompiled-named.c:1845805 | partial_layout |
| `0x14010016` | MESSENGER_1401_0016 *(label)* | both | +274 ptr unknown | Messenger: request and reply share this opcode. Messenger. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1923602<br>decompiled-source/global-0.0.1/decompiled-named.c:1924866 | partial_layout |
| `0x14010017` | MESSENGER_1401_0017 *(label)* | S>C | +48 char unknown | Messenger: reply/notification. Messenger. Likely reply to C>S 0x14010016 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1924942 | partial_layout |

## 0x1402 — Messenger

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x14020000` | MESSENGER_1402_0000 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273304 | located_only |

## 0x1500 — CharacterTrade

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x15000000` | CHARACTERTRADE_1500_0000 *(label)* | both | +10 undefined4 unknown; +14 undefined4 unknown; +18 ptr/copy unknown; +42 undefined1 unknown | CharacterTrade: request and reply share this opcode. Character trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111732<br>decompiled-source/global-0.0.1/decompiled-named.c:224871 | partial_layout |
| `0x15000001` | CHARACTERTRADE_1500_0001 *(label)* | S>C | unknown | CharacterTrade: reply/notification. Character trade. Likely reply to C>S 0x15000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111242 | located_only |
| `0x15000002` | CHARACTERTRADE_1500_0002 *(label)* | C>S | +10 undefined4 unknown | CharacterTrade: request. Character trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110384<br>decompiled-source/global-0.0.1/decompiled-named.c:2111732<br>decompiled-source/global-0.0.1/decompiled-named.c:3177214 | partial_layout |
| `0x15000004` | CHARACTERTRADE_1500_0004 *(label)* | S>C | +10 int unknown; +14 undefined4 unknown | CharacterTrade: reply/notification. Character trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110809 | partial_layout |
| `0x15000005` | CHARACTERTRADE_1500_0005 *(label)* | C>S | empty body | CharacterTrade: request. Character trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177340 | partial_layout |
| `0x15000006` | CHARACTERTRADE_1500_0006 *(label)* | C>S | +10 undefined4 unknown | CharacterTrade: request. Character trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177288 | partial_layout |
| `0x15000007` | CHARACTERTRADE_1500_0007 *(label)* | S>C | unknown | CharacterTrade: reply/notification. Character trade. Likely reply to C>S 0x15000006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110721 | located_only |
| `0x15000008` | CHARACTERTRADE_1500_0008 *(label)* | S>C | +10 int unknown | CharacterTrade: reply/notification. Character trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2110681 | partial_layout |
| `0x15000009` | CHARACTERTRADE_1500_0009 *(label)* | C>S | empty body | CharacterTrade: request. Character trade. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2111076<br>decompiled-source/global-0.0.1/decompiled-named.c:2111647 | partial_layout |

## 0x1600 — Alliance

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x16000002` | ALLIANCE_1600_0002 *(label)* | S>C | unknown | Alliance: reply/notification. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2115399 | located_only |
| `0x16000004` | ALLIANCE_1600_0004 *(label)* | C>S | unknown | Alliance: request. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177660 | located_only |
| `0x16000011` | ALLIANCE_1600_0011 *(label)* | S>C | unknown | Alliance: reply/notification. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2115679 | located_only |
| `0x16000012` | ALLIANCE_1600_0012 *(label)* | S>C | +54 short unknown; +374 short unknown; +39e short unknown; +3c8 undefined4 unknown; +3cc undefined2 unknown; +3ce undefined2 unknown; +3d0 undefined2 unknown; +3d3 ulonglong unknown; +3db undefined4 unknown; +3df undefined1 unknown | Alliance: reply/notification. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2115725 | partial_layout |
| `0x16000013` | ALLIANCE_1600_0013 *(label)* | S>C | unknown | Alliance: reply/notification. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2115829 | located_only |
| `0x16000014` | ALLIANCE_1600_0014 *(label)* | S>C | unknown | Alliance: reply/notification. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264176 | located_only |

## 0x1601 — Alliance

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x16010000` | ALLIANCE_1601_0000 *(label)* | S>C | +7e char unknown | Alliance: reply/notification. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2115938 | partial_layout |
| `0x16010001` | ALLIANCE_1601_0001 *(label)* | C>S | +7e ptr/copy unknown | Alliance: request. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2113681 | partial_layout |
| `0x16010002` | ALLIANCE_1601_0002 *(label)* | S>C | +54 undefined4 unknown | Alliance: reply/notification. Guild alliance. Likely reply to C>S 0x16010001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116139 | partial_layout |
| `0x16010003` | ALLIANCE_1601_0003 *(label)* | C>S | unknown | Alliance: request. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177684 | located_only |
| `0x16010004` | ALLIANCE_1601_0004 *(label)* | S>C | +54 undefined4 unknown | Alliance: reply/notification. Guild alliance. Likely reply to C>S 0x16010003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116073 | partial_layout |
| `0x16010005` | ALLIANCE_1601_0005 *(label)* | C>S | +7e undefined1 unknown | Alliance: request. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2113731 | partial_layout |
| `0x16010006` | ALLIANCE_1601_0006 *(label)* | S>C | +54 undefined1 unknown | Alliance: reply/notification. Guild alliance. Likely reply to C>S 0x16010005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116205 | partial_layout |
| `0x16010007` | ALLIANCE_1601_0007 *(label)* | S>C | unknown | Alliance: reply/notification. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116303 | located_only |
| `0x16010008` | ALLIANCE_1601_0008 *(label)* | C>S | +54 undefined1 unknown | Alliance: request. Guild alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177709 | partial_layout |
| `0x16010009` | ALLIANCE_1601_0009 *(label)* | S>C | +a8 undefined1 unknown | Alliance: reply/notification. Guild alliance. Likely reply to C>S 0x16010008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116391 | partial_layout |

## 0x1602 — Alliance

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x16020000` | ALLIANCE_1602_0000 *(label)* | C>S | +54 ptr/copy unknown | Alliance: request. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177733 | partial_layout |
| `0x16020001` | ALLIANCE_1602_0001 *(label)* | S>C | +54 undefined1 unknown | Alliance: reply/notification. Guild alliance + chat. Likely reply to C>S 0x16020000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116494 | partial_layout |
| `0x16020002` | ALLIANCE_1602_0002 *(label)* | S>C | unknown | Alliance: reply/notification. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116557 | located_only |
| `0x16020003` | ALLIANCE_1602_0003 *(label)* | C>S | +54 undefined2 unknown; +56 undefined2 unknown | Alliance: request. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177781 | partial_layout |
| `0x16020004` | ALLIANCE_1602_0004 *(label)* | S>C | +58 undefined4 unknown; +5c undefined4 unknown; +68 undefined1 unknown | Alliance: reply/notification. Guild alliance + chat. Likely reply to C>S 0x16020003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116845 | partial_layout |
| `0x16020005` | ALLIANCE_1602_0005 *(label)* | S>C | +54 undefined2 unknown; +56 undefined2 unknown | Alliance: reply/notification. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116944 | partial_layout |
| `0x16020008` | ALLIANCE_1602_0008 *(label)* | S>C | +54 short unknown | Alliance: reply/notification. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116986 | partial_layout |
| `0x16020009` | ALLIANCE_1602_0009 *(label)* | C>S | unknown | Alliance: request. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177825 | located_only |
| `0x1602000a` | ALLIANCE_1602_000A *(label)* | S>C | +54 undefined1 unknown | Alliance: reply/notification. Guild alliance + chat. Likely reply to C>S 0x16020009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2117094 | partial_layout |
| `0x1602000b` | ALLIANCE_1602_000B *(label)* | both | +10 undefined4 unknown; +18 undefined4 unknown; +3c undefined1 unknown; +40 undefined4 unknown; +7e short unknown; +214 undefined4 unknown | Alliance: request and reply share this opcode. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1922204<br>decompiled-source/global-0.0.1/decompiled-named.c:1925143 | partial_layout |
| `0x1602000c` | ALLIANCE_1602_000C *(label)* | C>S | +54 ptr/copy unknown; +7e undefined1 unknown | Alliance: request. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2113799 | partial_layout |
| `0x1602000d` | ALLIANCE_1602_000D *(label)* | S>C | +54 undefined1 unknown | Alliance: reply/notification. Guild alliance + chat. Likely reply to C>S 0x1602000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116626 | partial_layout |
| `0x1602000e` | ALLIANCE_1602_000E *(label)* | S>C | +7e undefined1 unknown | Alliance: reply/notification. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116695 | partial_layout |
| `0x1602000f` | ALLIANCE_1602_000F *(label)* | S>C | +a8 undefined1 unknown | Alliance: reply/notification. Guild alliance + chat. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2116792 | partial_layout |

## 0x1700 — Notice

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x17000000` | NOTICE_1700_0000 *(label)* | C>S | empty body | Notice: request. Server notice. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3184228 | partial_layout |

## 0x1701 — GuildTournament

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x17010001` | GUILDTOURNAMENT_1701_0001 *(label)* | S>C | +44 undefined4 unknown; +48 char unknown; +4c ptr unknown | GuildTournament: reply/notification. Guild tournament info/seed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1823453<br>decompiled-source/global-0.0.1/decompiled-named.c:1823894<br>decompiled-source/global-0.0.1/decompiled-named.c:1825148 | partial_layout |

## 0x1702 — GuildTournament

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x17020001` | GUILDTOURNAMENT_1702_0001 *(label)* | S>C | +44 int unknown; +4c ptr unknown | GuildTournament: reply/notification. Guild tournament entry member. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1824314 | partial_layout |
| `0x17020007` | GUILDTOURNAMENT_1702_0007 *(label)* | S>C | +44 char unknown | GuildTournament: reply/notification. Guild tournament entry member. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2025064 | partial_layout |

## 0x1704 — GuildTournament

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x17040012` | GUILDTOURNAMENT_1704_0012 *(label)* | S>C | +a4 undefined4 unknown | GuildTournament: reply/notification. Guild tournament betting. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1826216 | partial_layout |
| `0x17040014` | GUILDTOURNAMENT_1704_0014 *(label)* | S>C | unknown | GuildTournament: reply/notification. Guild tournament betting. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1826070 | located_only |
| `0x17040015` | GUILDTOURNAMENT_1704_0015 *(label)* | S>C | unknown | GuildTournament: reply/notification. Guild tournament betting. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1826070 | located_only |
| `0x17040017` | GUILDTOURNAMENT_1704_0017 *(label)* | S>C | +44 undefined4 unknown | GuildTournament: reply/notification. Guild tournament betting. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1827432 | partial_layout |
| `0x1704001b` | GUILDTOURNAMENT_1704_001B *(label)* | S>C | +44 int unknown; +48 ptr unknown | GuildTournament: reply/notification. Guild tournament betting. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1827354 | partial_layout |

## 0x1705 — GuildTournament

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x17050002` | GUILDTOURNAMENT_1705_0002 *(label)* | S>C | +44 undefined1 unknown; +45 undefined1 unknown; +46 undefined1 unknown | GuildTournament: reply/notification. Guild tournament. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3275575 | partial_layout |
| `0x17050013` | GUILDTOURNAMENT_1705_0013 *(label)* | S>C | unknown | GuildTournament: reply/notification. Guild tournament. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3275490 | located_only |

## 0x1801 — (unattributed)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x18010007` | UNATTRIBUTED_1801_0007 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2098331 | located_only |
| `0x18010010` | UNATTRIBUTED_1801_0010 *(label)* | S>C | +14 uint unknown; +18 int unknown; +1c byte unknown; +1d byte unknown; +20 ptr unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2099015 | partial_layout |
| `0x18010012` | UNATTRIBUTED_1801_0012 *(label)* | S>C | +14 uint unknown; +18 char unknown; +1c byte unknown; +1d byte unknown; +20 ptr unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2099285 | partial_layout |

## 0x1e00 — PC event

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x1e000000` | PC_EVENT_1E00_0000 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +70 ptr unknown | PC event: reply/notification. PC event (dispatched by enter-world dispatcher). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:235983<br>decompiled-source/global-0.0.1/decompiled-named.c:3236848 | partial_layout |
| `0x1e000001` | PC_EVENT_1E00_0001 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +70 ptr unknown | PC event: reply/notification. PC event (dispatched by enter-world dispatcher). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:236010<br>decompiled-source/global-0.0.1/decompiled-named.c:3236829 | partial_layout |

## 0x2000 — DKSquare

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x20000000` | DKSQUARE_2000_0000 *(label)* | C>S | +10 undefined1 unknown; +40 undefined1 unknown | DKSquare: request. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3138729 | partial_layout |
| `0x20000001` | DKSQUARE_2000_0001 *(label)* | C>S | +10 undefined1 unknown; +40 undefined4 unknown | DKSquare: request. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3138764 | partial_layout |
| `0x20000002` | DKSQUARE_2000_0002 *(label)* | C>S | +10 undefined1 unknown; +40 undefined4 unknown | DKSquare: request. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3138799 | partial_layout |
| `0x20000004` | DKSQUARE_2000_0004 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1876656 | located_only |
| `0x20000005` | DKSQUARE_2000_0005 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x20000006` | DKSQUARE_2000_0006 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x20000008` | DKSQUARE_2000_0008 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2575253 | located_only |
| `0x20000009` | DKSQUARE_2000_0009 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x2000000a` | DKSQUARE_2000_000A *(label)* | C>S | +10 undefined1 unknown; +44 undefined4 unknown; +48 bool unknown | DKSquare: request. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3138834 | partial_layout |
| `0x2000000b` | DKSQUARE_2000_000B *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. Likely reply to C>S 0x2000000a (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2575253 | located_only |
| `0x2000000c` | DKSQUARE_2000_000C *(label)* | C>S | +10 undefined1 unknown | DKSquare: request. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3138699 | partial_layout |
| `0x2000000d` | DKSQUARE_2000_000D *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. Likely reply to C>S 0x2000000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2575253 | located_only |
| `0x2000000e` | DKSQUARE_2000_000E *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2575253 | located_only |
| `0x2000000f` | DKSQUARE_2000_000F *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2575253 | located_only |
| `0x20000013` | Ghost::GameHandler::DKSquare::State::Battle::Battle | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1813462 | located_only |
| `0x20000014` | DKSQUARE_2000_0014 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:36441 | located_only |
| `0x20000015` | DKSQUARE_2000_0015 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2575253 | located_only |
| `0x20000024` | DKSQUARE_2000_0024 *(label)* | S>C | +44 undefined4 unknown; +48 undefined2 unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1878649 | partial_layout |
| `0x20000027` | DKSQUARE_2000_0027 *(label)* | C>S | +10 undefined1 unknown | DKSquare: request. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3138652 | partial_layout |
| `0x20000028` | DKSQUARE_2000_0028 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. Likely reply to C>S 0x20000027 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2575253 | located_only |
| `0x20000031` | DKSQUARE_2000_0031 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3257101 | located_only |
| `0x20000032` | DKSQUARE_2000_0032 *(label)* | S>C | unknown | DKSquare: reply/notification. DK Square battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:36624 | located_only |

## 0x2100 — Aggro

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x21000000` | AGGRO_2100_0000 *(label)* | S>C | +10 undefined1 unknown; +11 undefined1 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown | Aggro: reply/notification. Aggro event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:306476 | partial_layout |
| `0x21000001` | AGGRO_2100_0001 *(label)* | S>C | unknown | Aggro: reply/notification. Aggro event. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:306445 | located_only |

## 0x2200 — Unity

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x22000001` | STATUS_PUSH | S>C | unknown | server push (variable size 37-77), handler FUN_008e9e40 reads a list via reader vf+0x14 | decompiled-source/global-0.0.1/decompiled-named.c:2851838 | located_only |

## 0x3000 — Alliance (ext)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x30000000` | ALLIANCE_EXT_3000_0000 *(label)* | C>S | +3a undefined1 unknown | Alliance (ext): request. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2113554 | partial_layout |
| `0x30000001` | ALLIANCE_EXT_3000_0001 *(label)* | S>C | unknown | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276723 | located_only |
| `0x30000002` | ALLIANCE_EXT_3000_0002 *(label)* | C>S | +10 undefined1 unknown | Alliance (ext): request. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177636 | partial_layout |
| `0x30000004` | ALLIANCE_EXT_3000_0004 *(label)* | C>S | +3a undefined1 unknown | Alliance (ext): request. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2113622 | partial_layout |
| `0x30000005` | ALLIANCE_EXT_3000_0005 *(label)* | S>C | +10 char unknown; +14 int unknown; +18 undefined4 unknown | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30000004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2115578 | partial_layout |
| `0x30000006` | ALLIANCE_EXT_3000_0006 *(label)* | S>C | +10 undefined1 unknown | Alliance (ext): reply/notification. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2115487 | partial_layout |

## 0x3003 — Alliance (ext)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x30030000` | ALLIANCE_EXT_3003_0000 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Alliance (ext): request. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3301237 | partial_layout |
| `0x30030001` | ALLIANCE_EXT_3003_0001 *(label)* | S>C | unknown | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30030000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276094 | located_only |
| `0x30030002` | ALLIANCE_EXT_3003_0002 *(label)* | S>C | unknown | Alliance (ext): reply/notification. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264176 | located_only |
| `0x30030003` | ALLIANCE_EXT_3003_0003 *(label)* | S>C | unknown | Alliance (ext): reply/notification. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2117027 | located_only |
| `0x30030004` | ALLIANCE_EXT_3003_0004 *(label)* | C>S | empty body | Alliance (ext): request. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177804 | partial_layout |
| `0x30030005` | ALLIANCE_EXT_3003_0005 *(label)* | S>C | unknown | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30030004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264176 | located_only |
| `0x30030006` | ALLIANCE_EXT_3003_0006 *(label)* | C>S | empty body | Alliance (ext): request. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3177846 | partial_layout |
| `0x30030007` | ALLIANCE_EXT_3003_0007 *(label)* | S>C | unknown | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30030006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2117157 | located_only |
| `0x30030008` | ALLIANCE_EXT_3003_0008 *(label)* | S>C | +3a short unknown | Alliance (ext): reply/notification. Alliance. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2117202 | partial_layout |

## 0x4000 — CashInventory (ext)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x40000005` | CASHINVENTORY_EXT_4000_0005 *(label)* | C>S | +10 ushort unknown | CashInventory (ext): request. Cash inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178257 | partial_layout |
| `0x40000006` | CASHINVENTORY_EXT_4000_0006 *(label)* | S>C | +10 int unknown; +14 undefined2 unknown; +16 undefined1 unknown | CashInventory (ext): reply/notification. Cash inventory. Likely reply to C>S 0x40000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2119978 | partial_layout |
| `0x40000007` | CASHINVENTORY_EXT_4000_0007 *(label)* | C>S | +10 undefined4 unknown; +14 ptr/copy unknown | CashInventory (ext): request. Cash inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2118449 | partial_layout |
| `0x40000008` | CASHINVENTORY_EXT_4000_0008 *(label)* | S>C | +10 int unknown; +14 ptr unknown | CashInventory (ext): reply/notification. Cash inventory. Likely reply to C>S 0x40000007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2120056 | partial_layout |
| `0x40000009` | CASHINVENTORY_EXT_4000_0009 *(label)* | S>C | unknown | CashInventory (ext): reply/notification. Cash inventory. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2119864 | located_only |

## 0x4100 — Colosseum

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x41000001` | COLOSSEUM_4100_0001 *(label)* | C>S | +10 uint unknown; +14 undefined2 unknown | Colosseum: request. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3197740 | partial_layout |
| `0x41000002` | COLOSSEUM_4100_0002 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41000001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145617 | located_only |
| `0x41000003` | COLOSSEUM_4100_0003 *(label)* | C>S | empty body | Colosseum: request. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178768 | partial_layout |
| `0x41000004` | COLOSSEUM_4100_0004 *(label)* | S>C | +10 undefined1 unknown | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41000003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126328 | partial_layout |
| `0x41000005` | COLOSSEUM_4100_0005 *(label)* | S>C | +10 undefined4 unknown; +14 undefined2 unknown; +18 undefined4 unknown; +1c ushort unknown; +20 undefined1 unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126091 | partial_layout |
| `0x41000006` | COLOSSEUM_4100_0006 *(label)* | C>S | empty body | Colosseum: request. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178743 | partial_layout |
| `0x41000007` | COLOSSEUM_4100_0007 *(label)* | S>C | +10 undefined1 unknown | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41000006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126264 | partial_layout |
| `0x41000008` | COLOSSEUM_4100_0008 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |

## 0x4101 — Colosseum

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x41010001` | COLOSSEUM_4101_0001 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |

## 0x4102 — Colosseum

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x41020001` | COLOSSEUM_4102_0001 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41020002` | COLOSSEUM_4102_0002 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41020003` | COLOSSEUM_4102_0003 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126404 | located_only |
| `0x41020004` | COLOSSEUM_4102_0004 *(label)* | C>S | empty body | Colosseum: request. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:780365 | partial_layout |
| `0x41020005` | COLOSSEUM_4102_0005 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41020004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41020006` | COLOSSEUM_4102_0006 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41020007` | COLOSSEUM_4102_0007 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41020008` | COLOSSEUM_4102_0008 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |

## 0x4103 — Colosseum

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x41030001` | COLOSSEUM_4103_0001 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41030002` | COLOSSEUM_4103_0002 *(label)* | C>S | empty body | Colosseum: request. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178832 | partial_layout |
| `0x41030003` | COLOSSEUM_4103_0003 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41030002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41030004` | COLOSSEUM_4103_0004 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 int unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined2 unknown; +2a undefined2 unknown; +2c undefined1 unknown | Colosseum: request. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3178793 | partial_layout |
| `0x41030005` | COLOSSEUM_4103_0005 *(label)* | S>C | +10 undefined4 unknown; +14 ptr unknown | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41030004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126164 | partial_layout |
| `0x41030006` | COLOSSEUM_4103_0006 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41030007` | COLOSSEUM_4103_0007 *(label)* | S>C | +10 ptr unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126244 | partial_layout |
| `0x41030008` | COLOSSEUM_4103_0008 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |
| `0x41030009` | COLOSSEUM_4103_0009 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3264343 | located_only |

## 0x4104 — Colosseum

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x41040001` | COLOSSEUM_4104_0001 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256451 | located_only |
| `0x41040002` | COLOSSEUM_4104_0002 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256451 | located_only |
| `0x41040003` | COLOSSEUM_4104_0003 *(label)* | S>C | unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1830358 | located_only |

## 0x4105 — Colosseum

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x41050001` | COLOSSEUM_4105_0001 *(label)* | S>C | +10 int unknown; +14 int unknown; +42 undefined1 unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1830153 | partial_layout |
| `0x41050002` | COLOSSEUM_4105_0002 *(label)* | S>C | +10 int unknown; +3e undefined1 unknown | Colosseum: reply/notification. Colosseum. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1830220 | partial_layout |

## 0x4200 — GuildTournament / Donation

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x42000001` | GUILDTOURNAMENT_4200_0001 *(label)* | S>C | unknown | GuildTournament / Donation: reply/notification. Guild tournament entry, donation. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145653 | located_only |
| `0x42000002` | GUILDTOURNAMENT_4200_0002 *(label)* | C>S | +10 undefined1 unknown | GuildTournament / Donation: request. Guild tournament entry, donation. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2235162 | partial_layout |
| `0x42000003` | GUILDTOURNAMENT_4200_0003 *(label)* | C>S | unknown | GuildTournament / Donation: request. Guild tournament entry, donation. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2235205 | located_only |
| `0x42000004` | GUILDTOURNAMENT_4200_0004 *(label)* | S>C | unknown | GuildTournament / Donation: reply/notification. Guild tournament entry, donation. Likely reply to C>S 0x42000003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3145653 | located_only |
| `0x42000005` | GUILDTOURNAMENT_4200_0005 *(label)* | S>C | unknown | GuildTournament / Donation: reply/notification. Guild tournament entry, donation. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126760<br>decompiled-source/global-0.0.1/decompiled-named.c:3132937 | located_only |
| `0x42000007` | GUILDTOURNAMENT_4200_0007 *(label)* | S>C | unknown | GuildTournament / Donation: reply/notification. Guild tournament entry, donation. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126760<br>decompiled-source/global-0.0.1/decompiled-named.c:3132980 | located_only |

## 0x4201 — GuildTournament

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x42010001` | GUILDTOURNAMENT_4201_0001 *(label)* | C>S | empty body | GuildTournament: request. Guild tournament info. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1823427<br>decompiled-source/global-0.0.1/decompiled-named.c:1823868<br>decompiled-source/global-0.0.1/decompiled-named.c:3277883 | partial_layout |
| `0x42010003` | GUILDTOURNAMENT_4201_0003 *(label)* | S>C | unknown | GuildTournament: reply/notification. Guild tournament info. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126760<br>decompiled-source/global-0.0.1/decompiled-named.c:3133064 | located_only |

## 0x4202 — Guild (tournament)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x42020001` | GUILD_TOURNAMENT_4202_0001 *(label)* | C>S | empty body | Guild (tournament): request. Guild tournament guild UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3256394 | partial_layout |
| `0x42020003` | GUILD_TOURNAMENT_4202_0003 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined4 unknown | Guild (tournament): reply/notification. Guild tournament guild UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126760<br>decompiled-source/global-0.0.1/decompiled-named.c:3273095 | partial_layout |
| `0x42020004` | GUILD_TOURNAMENT_4202_0004 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Guild (tournament): request. Guild tournament guild UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1825072 | partial_layout |
| `0x42020005` | GUILD_TOURNAMENT_4202_0005 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown | Guild (tournament): reply/notification. Guild tournament guild UI. Likely reply to C>S 0x42020004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1825235 | partial_layout |
| `0x42020006` | GUILD_TOURNAMENT_4202_0006 *(label)* | C>S | empty body | Guild (tournament): request. Guild tournament guild UI. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2024468 | partial_layout |

## 0x4203 — GuildTournament

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x42030001` | GUILDTOURNAMENT_4203_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown | GuildTournament: request. Guild tournament betting. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1825965 | partial_layout |
| `0x42030002` | GUILDTOURNAMENT_4203_0002 *(label)* | C>S | +10 undefined4 unknown | GuildTournament: request. Guild tournament betting. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3240197 | partial_layout |
| `0x42030003` | GUILDTOURNAMENT_4203_0003 *(label)* | C>S | empty body | GuildTournament: request. Guild tournament betting. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1827328 | partial_layout |
| `0x42030004` | GUILDTOURNAMENT_4203_0004 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1c undefined4 unknown | GuildTournament: reply/notification. Guild tournament betting. Likely reply to C>S 0x42030003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2126845<br>decompiled-source/global-0.0.1/decompiled-named.c:3133291 | partial_layout |

## 0x4205 — GuildTournament (ext)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x42050001` | GUILDTOURNAMENT_EXT_4205_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | GuildTournament (ext): request. Guild tournament. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1825110 | partial_layout |
| `0x42050002` | GUILDTOURNAMENT_EXT_4205_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1c undefined4 unknown | GuildTournament (ext): reply/notification. Guild tournament. Likely reply to C>S 0x42050001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1825313 | partial_layout |
| `0x42050003` | GUILDTOURNAMENT_EXT_4205_0003 *(label)* | S>C | unknown | GuildTournament (ext): reply/notification. Guild tournament. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3273114 | located_only |
| `0x42050004` | GUILDTOURNAMENT_EXT_4205_0004 *(label)* | S>C | unknown | GuildTournament (ext): reply/notification. Guild tournament. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1830034 | located_only |

## 0x4300 — SuperChat

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x43000001` | SUPERCHAT_4300_0001 *(label)* | S>C | unknown | SuperChat: reply/notification. Super chat (megaphone). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3180852 | located_only |
| `0x43000002` | SUPERCHAT_4300_0002 *(label)* | S>C | unknown | SuperChat: reply/notification. Super chat (megaphone). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3180852 | located_only |
| `0x43000003` | SUPERCHAT_4300_0003 *(label)* | C>S | +10 undefined2 unknown; +12 ushort unknown; +14 undefined2 unknown; +16 undefined1 unknown; +17 undefined1 unknown; +18 undefined2 unknown; +1a undefined1 unknown | SuperChat: request. Super chat (megaphone). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2035997<br>decompiled-source/global-0.0.1/decompiled-named.c:2223196 | partial_layout |
| `0x43000004` | SUPERCHAT_4300_0004 *(label)* | S>C | +10 char unknown | SuperChat: reply/notification. Super chat (megaphone). Likely reply to C>S 0x43000003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276076 | partial_layout |
| `0x43000005` | SUPERCHAT_4300_0005 *(label)* | S>C | +12 ushort unknown; +14 ushort unknown; +16 char unknown; +18 short unknown; +42 short unknown | SuperChat: reply/notification. Super chat (megaphone). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1925730 | partial_layout |

## 0x4500 — (unattributed)

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x45000002` | UNATTRIBUTED_4500_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2179812 | partial_layout |
| `0x45000005` | UNATTRIBUTED_4500_0005 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2179689 | partial_layout |
| `0x45000008` | UNATTRIBUTED_4500_0008 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown; +16 undefined2 unknown; +18 undefined2 unknown; +1a undefined2 unknown; +1c undefined2 unknown; +1e undefined2 unknown; +20 undefined2 unknown; +22 undefined2 unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2179924 | partial_layout |
| `0x45000009` | UNATTRIBUTED_4500_0009 *(label)* | S>C | +10 int unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2180004 | partial_layout |
| `0x4500000a` | UNATTRIBUTED_4500_000A *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265377 | located_only |
| `0x4500000b` | UNATTRIBUTED_4500_000B *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265377 | located_only |
| `0x4500000c` | UNATTRIBUTED_4500_000C *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265347 | located_only |

## 0x4600 — DKRPvPBattle

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x46000004` | DKRPVPBATTLE_4600_0004 *(label)* | C>S | +10 ptr/copy unknown; +3a undefined1 unknown | DKRPvPBattle: request. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3194130 | partial_layout |
| `0x46000005` | DKRPVPBATTLE_4600_0005 *(label)* | S>C | +10 int unknown | DKRPvPBattle: reply/notification. DKR PvP battle. Likely reply to C>S 0x46000004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3276888 | partial_layout |
| `0x46000009` | DKRPVPBATTLE_4600_0009 *(label)* | S>C | unknown | DKRPvPBattle: reply/notification. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265920 | located_only |
| `0x4600000c` | DKRPVPBATTLE_4600_000C *(label)* | S>C | +10 undefined1 unknown; +11 undefined1 unknown; +57 undefined1 unknown; +58 undefined1 unknown; +a4 undefined1 unknown; +d3 ptr unknown; +1d0 int unknown; +1d4 char unknown | DKRPvPBattle: reply/notification. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2198650 | partial_layout |
| `0x4600000d` | DKRPVPBATTLE_4600_000D *(label)* | S>C | unknown | DKRPvPBattle: reply/notification. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265920 | located_only |
| `0x4600000e` | DKRPVPBATTLE_4600_000E *(label)* | S>C | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined1 unknown; +18 int unknown | DKRPvPBattle: reply/notification. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2198774 | partial_layout |
| `0x4600000f` | DKRPVPBATTLE_4600_000F *(label)* | S>C | unknown | DKRPvPBattle: reply/notification. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265920 | located_only |
| `0x46000010` | DKRPVPBATTLE_4600_0010 *(label)* | C>S | unknown | DKRPvPBattle: request. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2197950 | located_only |
| `0x46000011` | DKRPVPBATTLE_4600_0011 *(label)* | S>C | unknown | DKRPvPBattle: reply/notification. DKR PvP battle. Likely reply to C>S 0x46000010 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3265920 | located_only |
| `0x46000012` | DKRPVPBATTLE_4600_0012 *(label)* | C>S | unknown | DKRPvPBattle: request. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3263835 | located_only |
| `0x46000013` | DKRPVPBATTLE_4600_0013 *(label)* | S>C | +10 undefined4 unknown; +14 ptr unknown; +1c float unknown | DKRPvPBattle: reply/notification. DKR PvP battle. Likely reply to C>S 0x46000012 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2198540 | partial_layout |
| `0x46000014` | DKRPVPBATTLE_4600_0014 *(label)* | S>C | +3a undefined1 unknown | DKRPvPBattle: reply/notification. DKR PvP battle. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2198995 | partial_layout |

## 0x4800 — GuildWar

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x48000001` | GUILDWAR_4800_0001 *(label)* | S>C | +10 undefined1 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown | GuildWar: reply/notification. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2206998 | partial_layout |
| `0x48000002` | GUILDWAR_4800_0002 *(label)* | S>C | unknown | GuildWar: reply/notification. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266055 | located_only |
| `0x48000003` | GUILDWAR_4800_0003 *(label)* | C>S | +10 undefined1 unknown | GuildWar: request. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3195110 | partial_layout |
| `0x48000004` | GUILDWAR_4800_0004 *(label)* | S>C | +14 ptr unknown | GuildWar: reply/notification. Guild war declare/accept. Likely reply to C>S 0x48000003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2207125 | partial_layout |
| `0x48000005` | GUILDWAR_4800_0005 *(label)* | C>S | +10 ptr/copy unknown; +1d ptr/copy unknown; +2a ptr/copy unknown; +54 char unknown; +55 undefined1 unknown | GuildWar: request. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:1046205<br>decompiled-source/global-0.0.1/decompiled-named.c:1046465<br>decompiled-source/global-0.0.1/decompiled-named.c:2208303 | partial_layout |
| `0x48000006` | GUILDWAR_4800_0006 *(label)* | S>C | unknown | GuildWar: reply/notification. Guild war declare/accept. Likely reply to C>S 0x48000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2207192 | located_only |
| `0x48000007` | GUILDWAR_4800_0007 *(label)* | S>C | unknown | GuildWar: reply/notification. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3266055 | located_only |
| `0x48000008` | GUILDWAR_4800_0008 *(label)* | C>S | +10 undefined1 unknown | GuildWar: request. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:3195132 | partial_layout |
| `0x48000009` | GUILDWAR_4800_0009 *(label)* | S>C | unknown | GuildWar: reply/notification. Guild war declare/accept. Likely reply to C>S 0x48000008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2207236 | located_only |
| `0x4800000a` | GUILDWAR_4800_000A *(label)* | S>C | unknown | GuildWar: reply/notification. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2207275 | located_only |
| `0x4800000b` | GUILDWAR_4800_000B *(label)* | S>C | unknown | GuildWar: reply/notification. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2207311 | located_only |
| `0x4800000c` | GUILDWAR_4800_000C *(label)* | S>C | unknown | GuildWar: reply/notification. Guild war declare/accept. *(INFERRED)* | decompiled-source/global-0.0.1/decompiled-named.c:2207142 | located_only |
