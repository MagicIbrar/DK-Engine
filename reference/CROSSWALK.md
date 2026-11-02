# CROSSWALK: A2 (2Moons 2007) ⇄ Global 0.0.1

How every A2 opcode maps to Global 0.0.1: **identical**, **same code but different** (and how), **A2-only**, **Global-only**. Built from both decompiled clients (folder 3, `decompiled-source/`). Per-opcode detail lives in `A2-OPCODES.*` and `GLOBAL-OPCODES.*`; the `global_crosswalk` field in `A2-OPCODES.json` carries the category for every A2 row.

## Wire-verified updates (A2 client ⇄ HellSpider A2 server capture, 2026-10-29)

These supersede the static-only notes further down where they disagree.

| item | finding |
|---|---|
| initial cipher key | **0x0F** before CON_ACK is confirmed on the wire for A2 (the test client decodes every server packet with 0x0F until 0x00020081, then key0^key1). The "0/0" reading of the decompile below is wrong. |
| handshake | 0x20080 (20 B) → 0x20081 (64 B) → 0x20082 (20 B) → login, verified. Control packets 0x0002xxxx reuse the last data sequence number and do not advance it. |
| login used by the A2 client | **0x03000004** (100 B, id char[17] @+0x10, pw char[65] @+0x21), not 0x03000000. |
| 0x05040000 | **Not the same meaning.** A2: MONSTER_APPEAR, 76 B (monster index u16 @+0x14, HP u32 @+0x18). Global 0.0.1: PC_STATE, 448 B. Same code, different packet. Treat as *different*, not *identical*. |
| 0x050d0000 / 0x050d0004 / 0x050d0005 / 0x050d0007 | A2-only and live on the wire: ACTOR_ACTION (48 B, both ways, server echoes), MONSTER_CONTROL (28 B, client-side monster AI), OBJECTS_DISAPPEAR (4 B per id), ENTER_WORLD (24 B, map index @+0x10). |
| 0x050d0005 direction | The decompile lists it as C>S only; the server sends it S>C. Treat as both. |
| GameGuard 0x2008a | The HellSpider server sent 0x2008a in one probe session (22:04 PT); the real-client session that reached the world (22:22 PT) received none. Whether the no-GG client survives it is not tested. |

## Counts

| category | count | meaning |
|---|---|---|
| identical | 391 | same code and direction; builder sizes agree where both known (139 size-verified, 252 with no size on one or both sides, so identical is **INFERRED** for those) |
| same code, different | 84 | 79 size, 9 direction, 6 known core layout (an op can have several reasons) |
| A2 only | 134 | |
| Global only | 1218 | |

Totals: Global 1,693 = identical + different + Global-only. A2 rows: 634 in opcodes.tsv, plus 11 recovered from offset switches, minus 36 dropped as non-opcode noise, gives 609.

A2 input corrections (made here, not in the A2 export):
- **Offset-switch cases.** opcodes.tsv drops opmap keys 0..6, which are case values of `switch(op + K)`. Example: FUN_0050b800 `switch(uVar1 + 0xfdfbffe9)` means case n is 0x02040017+n. I recovered 13 opcodes (0x02040017, 0x02040018, 0x02040019, 0x0204001a, 0x0204001b, 0x0204001c, 0x0204001d, 0x09000001, 0x09000002, 0x09000003, 0x09000004, 0x09000005, 0x09000006) and marked them INFERRED.
- **Noise dropped (INFERRED).** 36 send-only values whose family low byte is ≥0x60 and which are absent from Global (for example 0x12e90001, 0x46c60001, 0x0389xxxx). They are mostly immediates in FUN_007df870, FUN_007dd3a0 and FUN_007cfbe0, which are not packet builders: 0x009500b0, 0x01b80004, 0x02b80004, 0x03890004, 0x03b80004, 0x06890004, 0x06b80004, 0x06e90004, 0x08b80004, 0x08b80008, 0x09eb0100, 0x12e90001, 0x15e90004, 0x168b0001, 0x16eb0080, 0x17e90001, 0x19e90004, 0x1ee90004, 0x22e90004, 0x32e90001, 0x347d0001, 0x35e90004, 0x36e90001, 0x40c60001, 0x40c70001, 0x43c70050, 0x43c70062, 0x45c70070, 0x46c60001, 0x46c60004, 0x46c70001, 0x478b0004, 0x47e90008, 0x4e890040, 0x4e8b0001, 0x508b0004.
- **Lock-ack naming.** A2 WIRING-MAP.md line 162 swaps the lock acks. The A2 decompile itself says 0x04000002 = `>> Receive LOCKACKSTART` (FUN_0050b470: i32 result @+0x10, flags @+0x14..0x16) and 0x04000003 = `>> Receive LOCKACKEND` (FUN_0050b510: u32 @+0x10, flag @+0x14). That is the same naming and the same read offsets as Global (FUN_00876180 / FUN_00876c60), so there is **no** naming reversal between the clients.

## Header, cipher, session

| item | A2 2007 | Global 0.0.1 | verdict |
|---|---|---|---|
| header | 16 B big-endian: +0 checksum, +4 u16 seq, +6 u16 size, +8 u32 tick, +0xC u32 opcode | same 16 B BE layout (FUN_00917890 recv swap, FUN_009177c0 send swap) | identical |
| max size | 0x400 | 0x400 (decrypt rejects size ≥0x401) | identical |
| cipher | XOR from byte 4: c[i]=T[i&0xff]&0xff ^ p[i] ^ k1 ^ k0; encrypt 0x449250, decrypt 0x4493c0 | same formula, FUN_009174e0 / FUN_00917580 | identical |
| CRC table | 0x99ec78 (standard CRC32) | DAT_01aa3c30 (standard CRC32) | identical content (INFERRED: both are the standard 0xEDB88320 table) |
| checksum | bswap(~CRC32) over ciphertext from +4 | same; reset FUN_00917450 pos=4, crc=0xffffffff | identical |
| key | (k0,k1) at session+0xC, 0/0 until 0x20081, then pkt[0x18], pkt[0x1c] (FUN_00443610) | session+0xC, set from CON_ACK +0x18/+0x1c (FUN_00912da0); no explicit init found in reset | same; the bridge value 0x0F as initial key is **INFERRED**/unconfirmed, and both decompiles point to 0/0 before CON_ACK |
| reliability | low byte & 0x80 means unreliable (FUN_0044a050); ACK 0x00020005 | same rule; ACK 0x00020005 | identical (A2 also has a handler for 0x20005 and 0x10002, so it is "both" there) |
| handshake | C 0x20080 (0x14, u32 BE tick) → S 0x20081 (serverTime, tick echo, key0, key1, 64 B blob) → C 0x20082 → ping/pong 0x20083/84 | CON 0x20080 (0x14) → CON_ACK 0x20081 (64 B passport @+0x20) → CONFIRM 0x20082 → 0x20083/84 | identical codes and sizes; meaning of the 64 B blob (A2) vs passport (Global) is the same slot, but content is INFERRED |
| GameGuard | S 0x2008a CS-auth query → C 0x2008b answer (0x50) | absent | A2 only: the server must not send 0x2008a, or must accept any 0x2008b |
| internal 0x0001xxxx | 0x00010000/01/03/04/05 have builders/handlers | only 0x00010002 / 0x00010005 seen | A2 has extra internal session events; client-local, not on the wire (INFERRED) |
| ports | login 7880, channel 7881 (channellist.csv) | per Global config | config, not protocol |

## Core flows

| step | A2 2007 | Global 0.0.1 | same? |
|---|---|---|---|
| login request | **0x03000000**, 0x34 B: id char[17]@+0x10, pw char[17]@+0x21. Variants 0x03000004 (0x64), 05 (0x94), 06 (0xd4), 07/08 (0x74) | **VL_LOGIN 0x0300001f**, 0x310 B (three 256-byte strings). 0x03000000 exists only as a 100 B factory with no live sender; 0x03000004 is 0xa8 | **different**: the server must accept 0x03000000/52 for A2 |
| login ack | 0x03000001: u32 userNo@+0x10, i32 result@+0x14, u32@+0x18, char[]@+0x1c, u8@+0x2b (about 0x2c) | 0x03000001, Global handler reads up to +0x62 (at least 0x64, INFERRED) | **different layout**; same opcode |
| logout | 0x03000002 (0x10) → 0x03000003 | same | identical |
| character list | PCLIST_REQ 0x02060000 (0x18) → 0x02060001 → 0x02040000 PC records + 0x02040001/16/1a suit → 0x02060002 (name @+0x18) → 0x02060003; 6 slots | same opcodes; PCLIST_REQ 0x18 | codes and order identical; record/name layouts unverified (INFERRED: Global names likely wide) |
| char create | 0x03020000, 0x2c: char name@+0x10, class u8@+0x29, slot u8@+0x2a → 0x03020001 | 0x03020000, 0x40: wchar name, class @+0x3a → 0x03020001 | **different** |
| char delete | 0x03020002, 0x2c → 0x03020003 | 0x03020002, 0x3c | **different** (size) |
| checkout (select) | 0x03010000, 0x2c: char name[25]@+0x10 → 0x03010001 {i32 result, …, u32@+0x1c} | 0x03010000, 0x3c: wchar name[21] → 0x03010001 | **different** |
| checkin (channel) | 0x03010002, 0x40: serialKey, sessionServerId, char name[25]@+0x18 → 0x03010003 | 0x03010002, 0x5c, wchar name | **different** |
| lock | 0x04000000, 0x40: +0x10 sessionServerId, +0x14 serialKey, +0x18 UserNO string → 0x04000002 start, 0x04000003 end | 0x04000000, 0x15c → 0x04000002 start, 0x04000003 end (same reads) | request **different**; acks identical |
| unlock | 0x04000006 (0x10) → 0x04000007 | same | identical |
| enter world | INFERRED: CHECKIN + LOCK on the channel, then 0x05xx Enter traffic | same family 0x05xx | codes largely shared; many 0x05xx builders differ by 4–16 B (see below) |

Recurring size pattern (INFERRED): 44→60, 64→92, 72→104 and similar steps fit A2 `char name[25]` becoming Global `wchar name[21]` or wider structs. Many 0x05xx/0x07xx ops differ by +4 B, which suggests one extra u32 field in Global.

## What matters for a GLOBAL A2 dashboard serving the 2007 client

- Transport can be shared. The header, cipher, CRC, 0x400 cap, reliability/ACK rule and the 0x20080/81/82/83/84 handshake are the same. The server sends CON_ACK with key0/key1 at +0x18/+0x1c for both.
- Key before handshake: both decompiles imply 0/0 until CON_ACK. The 0x0F from the bridge is INFERRED, so test both.
- GameGuard: never send 0x2008a to A2, or accept and ignore 0x2008b (0x50).
- Login: accept A2 0x03000000 (52 B, char id/pw) in addition to VL_LOGIN 0x0300001f (784 B). Reply 0x03000001 in the A2 short layout (about 0x2c, result @+0x14).
- Per-client codecs are required for CHECKOUT 0x03010000 (44 vs 60), CHECKIN 0x03010002 (64 vs 92), CHAR_CREATE 0x03020000 (44 vs 64, class @+0x29 vs +0x3a), CHAR_DELETE 0x03020002 (44 vs 60), LOCK 0x04000000 (64 vs 348), and every name field (char vs wchar).
- Client detection: the first login opcode (0x03000000 vs 0x0300001f) is a clean switch to pick the A2 or Global codec for the session.
- S>C replies (PCLIST, PC_OBJECT, CHECKOUT_ACK, CHAR_CREATE_ACK) share codes but have no sizes on either side. Build them from the A2 handler read offsets (A2 WIRING-MAP), not from Global layouts.
- Beyond login there are about 71 gameplay ops with differing sizes (0x05xx/07xx/08xx/09xx/0a02/0c00/11xx/14xx). A2 needs its own struct table for these; the identical ones (391, 139 of them size-verified) can be shared.
- 1218 Global-only ops (DekaPass, Title, later systems) must never be sent to A2. A2 dispatchers return 0 on unknown codes; the effect is INFERRED (likely ignored, possibly a disconnect).

## Same code, different size/layout/direction (84)

| opcode | Global name | A2 dir | Global dir | A2 size | Global size | why | INFERRED |
|---|---|---|---|---|---|---|---|
| 0x00010002 | INTERNAL_CONNECTED | both | C>S | 24 | 24 | direction A2 both vs Global C>S |  |
| 0x00020005 | SESSION_ACK | both | C>S | 20 | 20 | direction A2 both vs Global C>S |  |
| 0x03000000 | LOGIN (legacy id/pw) | C>S | C>S | 52 | 100 | size A2 [52] vs Global [100] bytes; layout: A2 real login (0x34: id char[17]@+0x10, pw char[17]@+0x21). Global: only a 100-byte factory, no live sender; Global logs in with VL_LOGIN 0x0300001f (0x310). |  |
| 0x03000001 | LOGIN_ACK | S>C | S>C | - | - | layout: LOGIN_ACK: A2 FUN_0050c540 reads up to +0x2b (u32 userNo@+0x10, i32 result@+0x14, u32@+0x18, char[]@+0x1c, u8@+0x2b); Global FUN_008731b0 reads +0x5c/+0x60/+0x62, so the Global ack is at least 0x64 bytes (INFERRED from read offsets). | yes |
| 0x03000004 | - | C>S | C>S | 100 | 168 | size A2 [100] vs Global [168] bytes |  |
| 0x03010000 | CHECKOUT | C>S | C>S | 44 | 60 | size A2 [44] vs Global [60] bytes; layout: CHECKOUT: A2 0x2c, char name[25]@+0x10; Global 0x3c, wchar name[21]. |  |
| 0x03010002 | CHECKIN | C>S | C>S | 64 | 92 | size A2 [64] vs Global [92] bytes; layout: CHECKIN: A2 0x40 (serialKey, sessionServerId, char name[25]@+0x18); Global 0x5c (wchar name). |  |
| 0x03020000 | CHAR_CREATE | C>S | C>S | 44 | 64 | size A2 [44] vs Global [64] bytes; layout: CHAR_CREATE: A2 0x2c (char name@+0x10, class u8@+0x29, slot u8@+0x2a); Global 0x40 (wchar name, class@+0x3a). |  |
| 0x03020002 | CHAR_DELETE | C>S | C>S | 44 | 60 | size A2 [44] vs Global [60] bytes |  |
| 0x03020004 | - | C>S | C>S | 68 | 104 | size A2 [68] vs Global [104] bytes |  |
| 0x03020006 | - | C>S | C>S | 44 | 60 | size A2 [44] vs Global [60] bytes |  |
| 0x03020008 | - | C>S | C>S | 68 | 104 | size A2 [68] vs Global [104] bytes |  |
| 0x04000000 | LOCK | C>S | C>S | 64 | 348 | size A2 [64] vs Global [348] bytes; layout: LOCK: A2 0x40 (+0x10 sessionServerId, +0x14 serialKey, +0x18 UserNO string); Global 0x15c. |  |
| 0x05030000 | - | C>S | C>S | 28 | 32 | size A2 [28] vs Global [32] bytes |  |
| 0x05030003 | - | C>S | C>S | 20 | 24 | size A2 [20] vs Global [24] bytes |  |
| 0x05040000 | PC_STATE | both | S>C | 76 | - | direction A2 both vs Global S>C |  |
| 0x050a0005 | - | C>S | C>S | 16 | 28 | size A2 [16] vs Global [28] bytes |  |
| 0x050a0007 | - | C>S | C>S | 28 | 16 | size A2 [28] vs Global [16] bytes |  |
| 0x050b0003 | - | C>S | C>S | 20 | 24 | size A2 [20] vs Global [24] bytes |  |
| 0x050b0005 | - | C>S | C>S | 20 | 24 | size A2 [20] vs Global [24] bytes |  |
| 0x050e0000 | - | both | both | 52 | 68 | size A2 [52] vs Global [68] bytes |  |
| 0x050e0008 | - | C>S | C>S | 20 | 24 | size A2 [20] vs Global [24] bytes |  |
| 0x0515000a | - | C>S | C>S | 28 | 40 | size A2 [28] vs Global [40] bytes |  |
| 0x0515000f | - | C>S | C>S | 16 | 20 | size A2 [16] vs Global [20] bytes |  |
| 0x05190000 | - | both | both | 76 | 440 | size A2 [76] vs Global [440] bytes |  |
| 0x051a0004 | - | C>S | C>S | 44 | 60 | size A2 [44] vs Global [60] bytes |  |
| 0x051a0008 | - | C>S | C>S | 24 | 40 | size A2 [24] vs Global [40] bytes |  |
| 0x051a000c | - | C>S | C>S | 24 | 28 | size A2 [24] vs Global [28] bytes |  |
| 0x051c0001 | - | C>S | C>S | 32 | 40 | size A2 [32] vs Global [40] bytes |  |
| 0x05200000 | - | C>S | C>S | 16 | 20 | size A2 [16] vs Global [20] bytes |  |
| 0x05200002 | - | C>S | C>S | 16 | 20 | size A2 [16] vs Global [20] bytes |  |
| 0x05220000 | - | C>S | C>S | 48 | 64 | size A2 [48] vs Global [64] bytes |  |
| 0x05220002 | - | C>S | C>S | 48 | 68 | size A2 [48] vs Global [68] bytes |  |
| 0x05220005 | - | C>S | C>S | 52 | 68 | size A2 [52] vs Global [68] bytes |  |
| 0x05220008 | - | C>S | C>S | 48 | 64 | size A2 [48] vs Global [64] bytes |  |
| 0x0522000a | - | C>S | C>S | 16 | 20 | size A2 [16] vs Global [20] bytes |  |
| 0x0526000d | - | C>S | C>S | 24 | 64 | size A2 [24] vs Global [64] bytes |  |
| 0x052d0007 | - | C>S | C>S | 44 | 60 | size A2 [44] vs Global [60] bytes |  |
| 0x05320001 | - | C>S | C>S | 40 | 44 | size A2 [40] vs Global [44] bytes |  |
| 0x07000002 | - | C>S | both | 20 | 24 | direction A2 C>S vs Global both; size A2 [20] vs Global [24] bytes |  |
| 0x07000005 | - | C>S | C>S | 16 | 20 | size A2 [16] vs Global [20] bytes |  |
| 0x07000009 | - | C>S | C>S | 28 | 48 | size A2 [28] vs Global [48] bytes |  |
| 0x07000017 | - | C>S | C>S | 20 | 60 | size A2 [20] vs Global [60] bytes |  |
| 0x07000028 | - | C>S | C>S | 16 | 20 | size A2 [16] vs Global [20] bytes |  |
| 0x07000030 | - | C>S | C>S | 20 | 24 | size A2 [20] vs Global [24] bytes |  |
| 0x07000047 | - | C>S | C>S | 20 | 24 | size A2 [20] vs Global [24] bytes |  |
| 0x08000002 | - | C>S | C>S | 60 | 84 | size A2 [60] vs Global [84] bytes |  |
| 0x08000003 | - | C>S | C>S | 28 | 32 | size A2 [28] vs Global [32] bytes |  |
| 0x09000000 | - | C>S | C>S | 52 | 60 | size A2 [52] vs Global [60] bytes |  |
| 0x09000005 | - | both | C>S | 16 | 16 | direction A2 both vs Global C>S |  |
| 0x09020001 | - | C>S | C>S | 44 | 60 | size A2 [44] vs Global [60] bytes |  |
| 0x09020004 | - | both | both | 76 | 104 | size A2 [76] vs Global [104] bytes |  |
| 0x0a020000 | - | both | both | 72 | 104 | size A2 [72] vs Global [104] bytes |  |
| 0x0a020003 | - | C>S | C>S | 72 | 104 | size A2 [72] vs Global [104] bytes |  |
| 0x0a020005 | - | C>S | C>S | 72 | 104 | size A2 [72] vs Global [104] bytes |  |
| 0x0a020007 | - | C>S | C>S | 72 | 104 | size A2 [72] vs Global [104] bytes |  |
| 0x0c000000 | - | C>S | C>S | 16 | 20 | size A2 [16] vs Global [20] bytes |  |
| 0x0c000005 | - | C>S | C>S | 36 | 24 | size A2 [36] vs Global [24] bytes |  |
| 0x0c000007 | - | C>S | C>S | 36 | 24 | size A2 [36] vs Global [24] bytes |  |
| 0x0c000009 | - | C>S | C>S | 36 | 24 | size A2 [36] vs Global [24] bytes |  |
| 0x0c00000b | - | C>S | C>S | 36 | 24 | size A2 [36] vs Global [24] bytes |  |
| 0x0d000000 | - | C>S | C>S | 16 | 20 | size A2 [16] vs Global [20] bytes |  |
| 0x0e010002 | - | C>S | C>S | 56 | 60 | size A2 [56] vs Global [60] bytes |  |
| 0x11010000 | - | C>S | C>S | 24 | 68 | size A2 [24] vs Global [68] bytes |  |
| 0x11010003 | - | C>S | C>S | 536 | 968 | size A2 [536] vs Global [968] bytes |  |
| 0x11010006 | - | C>S | C>S | 28 | 72 | size A2 [28] vs Global [72] bytes |  |
| 0x11010009 | - | C>S | C>S | 60 | 104 | size A2 [60] vs Global [104] bytes |  |
| 0x1101000c | - | C>S | C>S | 32 | 76 | size A2 [32] vs Global [76] bytes |  |
| 0x1101000f | - | C>S | C>S | 64 | 108 | size A2 [64] vs Global [108] bytes |  |
| 0x11020005 | - | C>S | C>S | 24 | 68 | size A2 [24] vs Global [68] bytes |  |
| 0x11020007 | - | C>S | C>S | 56 | 116 | size A2 [56] vs Global [116] bytes |  |
| 0x11020009 | - | C>S | C>S | 52 | 112 | size A2 [52] vs Global [112] bytes |  |
| 0x1102000c | - | C>S | C>S | 52 | 112 | size A2 [52] vs Global [112] bytes |  |
| 0x11030000 | - | both | both | 304 | 648 | size A2 [304] vs Global [648] bytes |  |
| 0x11030001 | - | both | both | 364 | 732 | size A2 [364] vs Global [732] bytes |  |
| 0x11030003 | - | C>S | both | 60 | 120 | direction A2 C>S vs Global both; size A2 [60] vs Global [120] bytes |  |
| 0x11030004 | - | C>S | both | 84 | 164 | direction A2 C>S vs Global both; size A2 [84] vs Global [164] bytes |  |
| 0x11030005 | - | C>S | both | 60 | 120 | direction A2 C>S vs Global both; size A2 [60] vs Global [120] bytes |  |
| 0x11030007 | - | C>S | both | 304 | 652 | direction A2 C>S vs Global both; size A2 [304] vs Global [652] bytes |  |
| 0x14000001 | - | C>S | C>S | 52 | 120 | size A2 [52] vs Global [120] bytes |  |
| 0x14000002 | - | both | both | 76 | 124 | size A2 [76] vs Global [124] bytes |  |
| 0x14010001 | - | both | both | 324 | 648 | size A2 [324] vs Global [648] bytes |  |
| 0x14010005 | - | C>S | C>S | 52 | 80 | size A2 [52] vs Global [80] bytes |  |
| 0x14010006 | - | both | both | 72 | 116 | size A2 [72] vs Global [116] bytes |  |

## A2 only (134)

| opcode | A2 dir | A2 size | A2 handlers | A2 builders | note |
|---|---|---|---|---|---|
| 0x00010000 | C>S | 28 | - | 464750@464792 |  |
| 0x00010001 | both | 16 | - | 464520@46454d,464920@464970 |  |
| 0x00010003 | both | 20 | FUN_00465280 | 443cd0@443ce9 |  |
| 0x00010004 | both | 24 | FUN_00465210 | 444510@444566,4445f0@444654 |  |
| 0x00010005 | both | 32 | FUN_00464580 | 443610@443734,443e30@443eed |  |
| 0x0002008a | S>C | - | FUN_00443990 | - | GameGuard |
| 0x0002008b | C>S | 80 | - | 412790@4127a9 | GameGuard |
| 0x00070004 | S>C | - | FUN_0073c7c0 | - |  |
| 0x00300000 | C>S | - | - | 49c850@49c880 |  |
| 0x02040014 | S>C | - | FUN_0050ae10 | - |  |
| 0x02040016 | S>C | - | FUN_00500bb0,FUN_0050af00 | - |  |
| 0x02040017 | S>C | - | FUN_0050af90 | - | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x02040018 | S>C | - | FUN_0050b020 | - | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x0204001a | S>C | - | FUN_00500c70,FUN_0050b140 | - |  |
| 0x0204001b | S>C | - | FUN_0050b1d0 | - | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x0204001c | S>C | - | FUN_0050b260 | - | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x0281000d | S>C | - | FUN_00717830 | - |  |
| 0x02810010 | S>C | - | FUN_00717cb0 | - |  |
| 0x03000005 | C>S | 148 | - | 50cba0@50cbb4 |  |
| 0x03000006 | C>S | 212 | - | 50cbd0@50cbe4 |  |
| 0x03000007 | C>S | 116 | - | 50cc30@50cc44 |  |
| 0x03000008 | C>S | 116 | - | 50cc00@50cc14 |  |
| 0x0500000a | C>S | 28 | - | 7959e0@7959f4 |  |
| 0x0500000b | S>C | - | FUN_0075b880 | - |  |
| 0x05010002 | C>S | 28 | - | 760710@760724 |  |
| 0x05010003 | S>C | - | FUN_0075f300 | - |  |
| 0x05020009 | C>S | 24 | - | 71a9a0@71a9e3 |  |
| 0x0502001a | S>C | - | FUN_0071a360 | - |  |
| 0x05060000 | C>S | 20 | - | 763320@76345c |  |
| 0x05060002 | C>S | 20 | - | 746c70@746ca9,746cf0@746d29 |  |
| 0x05060003 | S>C | - | FUN_00746390 | - |  |
| 0x05060004 | C>S | 16 | - | 532480@532496,5324c0@5324d6 |  |
| 0x05090001 | S>C | - | FUN_00537210 | - |  |
| 0x05090003 | S>C | - | FUN_005374d0 | - |  |
| 0x05090004 | S>C | - | FUN_0053ac80 | - |  |
| 0x05090006 | C>S | - | - | 5326c0@532756 |  |
| 0x0509000d | S>C | - | FUN_00759740 | - |  |
| 0x0509000e | S>C | - | FUN_007467a0 | - |  |
| 0x050c0002 | C>S | 20 | - | 795a40@795a54 |  |
| 0x050c0003 | S>C | - | FUN_0075bec0 | - |  |
| 0x050c0004 | S>C | - | FUN_0075c040 | - |  |
| 0x050d0000 | both | 48 | FUN_0053a340 | 4edfb0@4edfca,4eef70@4eef84 |  |
| 0x050d0001 | C>S | 20 | - | 524500@524582 |  |
| 0x050d0002 | C>S | 24 | - | 53edd0@53eea8,548e10@548f07 |  |
| 0x050d0003 | both | 24 | FUN_00761ff0 | 7638b0@763beb |  |
| 0x050d0004 | S>C | - | FUN_0053a5c0 | - |  |
| 0x050d0005 | C>S | 20 | - | 781970@7819b3 |  |
| 0x050d0006 | C>S | 20 | - | 762f60@763204 |  |
| 0x050d0007 | S>C | - | FUN_0050a520 | - |  |
| 0x050e000f | C>S | 20 | - | 7910c0@7910d4 |  |
| 0x050e0010 | S>C | - | FUN_007599f0 | - |  |
| 0x05100001 | C>S | 20 | - | 794760@794783 |  |
| 0x05100003 | both | 20 | FUN_0075e5e0 | 7748c0@7748d4,78e3b0@78e3ed |  |
| 0x05100005 | C>S | 20 | - | 75e5e0@75e62c,75e5e0@75e6b0 |  |
| 0x05100006 | C>S | 16 | - | 7915d0@7915e4 |  |
| 0x05100009 | C>S | 16 | - | 7942b0@7942d0,794370@794390 |  |
| 0x0510000c | C>S | 20 | - | 794410@794430 |  |
| 0x05110000 | both | 56 | FUN_00772620 | 7945e0@794605 |  |
| 0x05110002 | C>S | 20 | - | 7944c0@79450c,794550@794599 |  |
| 0x05110003 | C>S | 20 | - | 7943b0@7943e4 |  |
| 0x05110004 | C>S | 20 | - | 794460@794494 |  |
| 0x05110006 | C>S | 16 | - | 6ec4f0@6ec51f |  |
| 0x0511000c | both | 24 | FUN_00761e30 | 7638b0@763b53 |  |
| 0x0511000e | S>C | - | FUN_0075aed0 | - |  |
| 0x05180004 | C>S | 16 | - | 745570@745590 |  |
| 0x05180005 | C>S | 20 | - | 7455b0@7455d0 |  |
| 0x051b0000 | C>S | 16 | - | 73b9d0@73ba01 |  |
| 0x051b0002 | C>S | 20 | - | 73ba30@73ba9b |  |
| 0x051b0004 | C>S | 20 | - | 73bae0@73bb4a |  |
| 0x051b0006 | C>S | 16 | - | 73bba0@73bbd1 |  |
| 0x051b0008 | C>S | 16 | - | 73bc00@73bc31 |  |
| 0x051b000a | C>S | 16 | - | 73bc60@73bc91 |  |
| 0x051b000e | C>S | 16 | - | 73bcc0@73bcf1 |  |
| 0x051e0000 | S>C | - | - | - |  |
| 0x051e0002 | S>C | - | FUN_00721820 | - |  |
| 0x051e0004 | S>C | - | - | - |  |
| 0x05210005 | S>C | - | FUN_006f8720 | - |  |
| 0x0521000b | S>C | - | FUN_006f8c40 | - |  |
| 0x052b0001 | C>S | 20 | - | 709840@709860 |  |
| 0x052b0002 | S>C | - | FUN_00709580 | - |  |
| 0x052b0003 | S>C | - | FUN_00709520 | - |  |
| 0x052b0004 | S>C | - | FUN_007095d0 | - |  |
| 0x05320000 | S>C | - | - | - |  |
| 0x05320002 | S>C | - | FUN_006fe6b0 | - |  |
| 0x05320004 | S>C | - | - | - |  |
| 0x05330000 | C>S | 16 | - | 7015f0@701643 |  |
| 0x05330001 | S>C | - | FUN_00701670 | - |  |
| 0x05330005 | C>S | 412 | - | 7017a0@701810 |  |
| 0x06000000 | C>S | 32 | - | 532580@532596 |  |
| 0x06000001 | S>C | - | FUN_005361c0 | - |  |
| 0x06000002 | S>C | - | FUN_005369a0 | - |  |
| 0x06000003 | S>C | - | FUN_00536e40 | - |  |
| 0x06000004 | S>C | - | FUN_00536460 | - |  |
| 0x06000005 | S>C | - | FUN_00535f20 | - |  |
| 0x06000006 | S>C | - | FUN_005367a0 | - |  |
| 0x06000007 | S>C | - | FUN_00536270 | - |  |
| 0x06000008 | S>C | - | FUN_00536b80 | - |  |
| 0x06000009 | S>C | - | FUN_00536ce0 | - |  |
| 0x06000100 | S>C | - | FUN_00535c10 | - |  |
| 0x06020001 | C>S | 32 | - | 532600@53261c,5326c0@5326d8 |  |
| 0x07000003 | C>S | 24 | - | 6f6700@6f6731,6f7f90@6f7fc1 |  |
| 0x07000004 | S>C | - | FUN_00777520,FUN_00783730 | - |  |
| 0x07000011 | C>S | 20 | - | 6f5fe0@6f6000,6f7620@6f7640 |  |
| 0x07000012 | S>C | - | FUN_00777840,FUN_00783a50 | - |  |
| 0x07000015 | C>S | 20 | - | 6f5f40@6f5f60,6f7580@6f75a0 |  |
| 0x07000016 | S>C | - | FUN_007778a0,FUN_00783ab0 | - |  |
| 0x0700001b | C>S | 20 | - | 6f6070@6f6090,6f76b0@6f76d0 |  |
| 0x0700001c | S>C | - | FUN_007778e0,FUN_00783af0 | - |  |
| 0x0700001e | C>S | 20 | - | 6f60c0@6f60e0,6f7700@6f7720 |  |
| 0x0700001f | S>C | - | FUN_00777920,FUN_00783b30 | - |  |
| 0x07000020 | C>S | 20 | - | 6f6110@6f6130,6f7750@6f7770 |  |
| 0x07000021 | S>C | - | FUN_00777a50,FUN_00783c60 | - |  |
| 0x07000044 | C>S | 16 | - | 6f7e30@6f7e50,778570@778590 |  |
| 0x07000045 | S>C | - | FUN_00777f60,FUN_00781360,FUN_00784930 | - |  |
| 0x08000004 | C>S | 28 | - | 51ec00@51ec14,6f64a0@6f64e5 |  |
| 0x08000007 | C>S | 20 | - | 7712f0@771304 |  |
| 0x08000008 | C>S | 20 | - | 771320@771334 |  |
| 0x09000002 | S>C | - | FUN_007328f0 | - | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x09000003 | S>C | - | FUN_007329f0 | - | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x0a560004 | S>C | - | FUN_00538e60 | - |  |
| 0x0b290002 | S>C | - | FUN_00539400 | - |  |
| 0x0d000002 | C>S | 44 | - | 6fc890@6fc9f8,71cf90@71d0fc |  |
| 0x0d000004 | S>C | - | FUN_004ea270 | - |  |
| 0x0d000006 | C>S | 632 | - | 6fd250@6fd62d,71d2b0@71d68e |  |
| 0x0d000007 | S>C | - | FUN_006faa60,FUN_0071b150 | - |  |
| 0x0f020006 | S>C | - | FUN_00767b90 | - |  |
| 0x0f020008 | S>C | - | - | - |  |
| 0x0f020009 | S>C | - | FUN_00767520 | - |  |
| 0x0f02000b | S>C | - | - | - |  |
| 0x0f02000c | S>C | - | FUN_00769c80 | - |  |
| 0x0f02000e | S>C | - | - | - |  |
| 0x0f02000f | S>C | - | FUN_00768200 | - |  |
| 0x0f020011 | S>C | - | - | - |  |
| 0x50000101 | S>C | - | FUN_004ead90 | - |  |

## Identical (391)

| opcode | Global name | dir | size | size check | note |
|---|---|---|---|---|---|
| 0x00020080 | CON | C>S | 20 | verified (both builders) |  |
| 0x00020081 | CON_ACK | S>C | - | unverified (no size on one/both sides) - INFERRED identical | S>C reply: no size on either side; A2 strings are char[], Global C>S core strings are wchar - name fields here may also be wide in Global (INFERRED, unverified) |
| 0x00020082 | CON_CONFIRM | C>S | 20 | verified (both builders) |  |
| 0x00020083 | PING | both | 20 | verified (both builders) |  |
| 0x00020084 | PONG | both | 20 | verified (both builders) |  |
| 0x02040000 | PC_OBJECT | S>C | - | unverified (no size on one/both sides) - INFERRED identical | S>C reply: no size on either side; A2 strings are char[], Global C>S core strings are wchar - name fields here may also be wide in Global (INFERRED, unverified) |
| 0x02040001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02040002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02040003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0204000f | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02040010 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02040011 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02040012 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02040013 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02040015 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02040019 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x0204001d | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x02060000 | PCLIST_REQ | C>S | 24 | verified (both builders) |  |
| 0x02060001 | PCLIST_ACK | S>C | - | unverified (no size on one/both sides) - INFERRED identical | S>C reply: no size on either side; A2 strings are char[], Global C>S core strings are wchar - name fields here may also be wide in Global (INFERRED, unverified) |
| 0x02060002 | PCLIST_NAME | S>C | - | unverified (no size on one/both sides) - INFERRED identical | S>C reply: no size on either side; A2 strings are char[], Global C>S core strings are wchar - name fields here may also be wide in Global (INFERRED, unverified) |
| 0x02060003 | PCLIST_END | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x02070002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x03000002 | LOGOUT | C>S | 16 | verified (both builders) |  |
| 0x03000003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x03010001 | CHECKOUT_ACK | S>C | - | unverified (no size on one/both sides) - INFERRED identical | S>C reply: no size on either side; A2 strings are char[], Global C>S core strings are wchar - name fields here may also be wide in Global (INFERRED, unverified) |
| 0x03010003 | CHECKIN_ACK | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x03020001 | CHAR_CREATE_ACK | S>C | - | unverified (no size on one/both sides) - INFERRED identical | S>C reply: no size on either side; A2 strings are char[], Global C>S core strings are wchar - name fields here may also be wide in Global (INFERRED, unverified) |
| 0x03020003 | CHAR_DELETE_ACK | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x03020005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x03020007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x03020009 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x04000002 | LOCK_ACK_START | S>C | - | unverified (no size on one/both sides) - INFERRED identical | A2 decompile strings: 0x04000002 = ">> Receive LOCKACKSTART" (FUN_0050b470, i32 result@+0x10, 3 flags @+0x14..16), 0x04000003 = ">> Receive LOCKACKEND" (FUN_0050b510, u32@+0x10, flag@+0x14). Same naming as Global; the A2 WIRING-MAP.md line 162 has them swapped. |
| 0x04000003 | LOCK_ACK_END | S>C | - | unverified (no size on one/both sides) - INFERRED identical | A2 decompile strings: 0x04000002 = ">> Receive LOCKACKSTART" (FUN_0050b470, i32 result@+0x10, 3 flags @+0x14..16), 0x04000003 = ">> Receive LOCKACKEND" (FUN_0050b510, u32@+0x10, flag@+0x14). Same naming as Global; the A2 WIRING-MAP.md line 162 has them swapped. |
| 0x04000006 | UNLOCK | C>S | 16 | verified (both builders) |  |
| 0x04000007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x04000008 | WAIT_NOTICE | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05000000 | - | C>S | 24 | verified (both builders) |  |
| 0x05000002 | - | C>S | 20 | verified (both builders) |  |
| 0x05000008 | - | C>S | 20 | verified (both builders) |  |
| 0x05000009 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05010000 | - | C>S | 20 | verified (both builders) |  |
| 0x05010001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05020000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05020001 | - | C>S | 24 | verified (both builders) |  |
| 0x05020002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05020003 | - | C>S | 24 | verified (both builders) |  |
| 0x05020004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05020006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05020007 | - | C>S | 16 | verified (both builders) |  |
| 0x05020008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0502000b | - | C>S | 20 | verified (both builders) |  |
| 0x0502000c | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0502000e | - | C>S | 24 | verified (both builders) |  |
| 0x0502000f | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05030001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05030002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05030004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05050000 | NPC_OBJECT | both | 32 | verified (both builders) |  |
| 0x05050001 | - | C>S | 20 | verified (both builders) |  |
| 0x05050002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05050003 | - | C>S | 24 | verified (both builders) |  |
| 0x05050004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05050005 | - | C>S | 20 | verified (both builders) |  |
| 0x05050006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05050007 | - | C>S | 16 | verified (both builders) |  |
| 0x05050008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05050010 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05060006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05060007 | - | C>S | 16 | verified (both builders) |  |
| 0x05060008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05060009 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0506000a | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0506000b | - | C>S | 20 | verified (both builders) |  |
| 0x0506000c | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0506000d | - | C>S | 16 | verified (both builders) |  |
| 0x0506000e | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0506000f | - | C>S | 20 | verified (both builders) |  |
| 0x05060010 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05060011 | - | C>S | 24 | verified (both builders) |  |
| 0x05060012 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05060013 | - | C>S | 24 | verified (both builders) |  |
| 0x05060014 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05060016 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05070000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05080000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05080001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05090000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0509000a | - | C>S | 16 | verified (both builders) |  |
| 0x0509000b | - | C>S | 16 | verified (both builders) |  |
| 0x050a0001 | - | C>S | 28 | verified (both builders) |  |
| 0x050a0003 | - | C>S | 24 | verified (both builders) |  |
| 0x050b0001 | - | C>S | 20 | verified (both builders) |  |
| 0x050b0007 | - | C>S | 16 | verified (both builders) |  |
| 0x050c0000 | - | C>S | 20 | verified (both builders) |  |
| 0x050c0001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x050e0002 | - | C>S | 20 | verified (both builders) |  |
| 0x050e0005 | - | C>S | 16 | verified (both builders) |  |
| 0x050e0006 | - | C>S | 20 | verified (both builders) |  |
| 0x050e000c | - | C>S | 20 | verified (both builders) |  |
| 0x050e0011 | - | C>S | 20 | verified (both builders) |  |
| 0x050e0012 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x050f0000 | - | C>S | 20 | verified (both builders) |  |
| 0x050f0006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x050f0007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x050f0008 | - | C>S | 24 | verified (both builders) |  |
| 0x05120002 | - | C>S | 20 | verified (both builders) |  |
| 0x05120003 | - | C>S | 20 | verified (both builders) |  |
| 0x05150001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05150002 | - | C>S | 20 | verified (both builders) |  |
| 0x05150003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05150004 | - | C>S | 20,24 | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05150005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05150006 | - | C>S | 20,24 | verified (both builders) |  |
| 0x05150007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05150008 | - | C>S | 36 | verified (both builders) |  |
| 0x05150009 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0515000d | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0515000e | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05150010 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05160000 | - | C>S | 20 | verified (both builders) |  |
| 0x05160001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05170000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05170001 | - | C>S | 24 | verified (both builders) |  |
| 0x05170002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05190001 | - | C>S | 28 | verified (both builders) |  |
| 0x05190002 | - | C>S | 16 | verified (both builders) |  |
| 0x05190003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051a0000 | - | C>S | 20 | verified (both builders) |  |
| 0x051a0001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051a0002 | - | C>S | 16 | verified (both builders) |  |
| 0x051a0003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051a0005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051a0006 | - | C>S | 16 | verified (both builders) |  |
| 0x051a0007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051a0009 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051a000a | - | C>S | 20 | verified (both builders) |  |
| 0x051a000b | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051a000d | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051a000e | - | C>S | 16 | verified (both builders) |  |
| 0x051a000f | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051c0000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051c0002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051c0003 | - | C>S | 16 | verified (both builders) |  |
| 0x051c0004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051d0000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051d0001 | - | C>S | 24 | verified (both builders) |  |
| 0x051d0003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051d0004 | - | C>S | 16 | verified (both builders) |  |
| 0x051e0001 | - | C>S | 48 | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x051e0003 | - | C>S | 16 | verified (both builders) |  |
| 0x051f0000 | - | both | 20 | verified (both builders) |  |
| 0x051f0001 | - | C>S | 16 | verified (both builders) |  |
| 0x051f0002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05200001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05200003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05210000 | - | C>S | 24 | verified (both builders) |  |
| 0x05210001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05210003 | - | C>S | 16 | verified (both builders) |  |
| 0x05210004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05210006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05210007 | - | C>S | 60 | verified (both builders) |  |
| 0x05210008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05210009 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0521000a | - | C>S | 16 | verified (both builders) |  |
| 0x0522000f | - | C>S | 24 | verified (both builders) |  |
| 0x05230000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05230001 | - | C>S | 20 | verified (both builders) |  |
| 0x05230002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05230003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05230004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05230005 | - | C>S | 20 | verified (both builders) |  |
| 0x05230006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05230007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05240000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05250000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05250001 | - | C>S | 24 | verified (both builders) |  |
| 0x05250002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05250003 | - | C>S | 16 | verified (both builders) |  |
| 0x05250004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05260002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05260003 | - | C>S | 24 | verified (both builders) |  |
| 0x05260010 | - | C>S | 16 | verified (both builders) |  |
| 0x05270000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05270001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05270002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05270003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05270004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05270005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280001 | - | C>S | 20 | verified (both builders) |  |
| 0x05280002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280003 | - | C>S | 20 | verified (both builders) |  |
| 0x05280004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280008 | - | C>S | 16 | verified (both builders) |  |
| 0x05280009 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0528000a | - | C>S | 16 | verified (both builders) |  |
| 0x0528000b | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0528000c | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0528000d | - | C>S | 20 | verified (both builders) |  |
| 0x0528000e | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0528000f | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280010 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280011 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280012 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280013 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280014 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280015 | - | C>S | 16 | verified (both builders) |  |
| 0x05280016 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280017 | - | C>S | 24 | verified (both builders) |  |
| 0x05280018 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280019 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0528001a | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0528001b | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05280020 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05290000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x052a0000 | - | C>S | 16 | verified (both builders) |  |
| 0x052a0002 | - | C>S | 16 | verified (both builders) |  |
| 0x052a0004 | - | C>S | 16 | verified (both builders) |  |
| 0x052a0006 | - | C>S | 16 | verified (both builders) |  |
| 0x052c0001 | - | C>S | 24,28 | verified (both builders) |  |
| 0x052c0003 | - | C>S | 16 | verified (both builders) |  |
| 0x052c0005 | - | C>S | 24,28 | verified (both builders) |  |
| 0x052d0001 | - | C>S | 20 | verified (both builders) |  |
| 0x052d0003 | - | C>S | 16,20 | verified (both builders) |  |
| 0x052d0005 | - | C>S | 16 | verified (both builders) |  |
| 0x052f0000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x052f0003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05300000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05300001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05300002 | - | C>S | 20 | verified (both builders) |  |
| 0x05300003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05300005 | - | C>S | 20 | verified (both builders) |  |
| 0x05300006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05300015 | - | C>S | 16 | verified (both builders) |  |
| 0x05310000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05310001 | - | C>S | 16,20 | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05310002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05310003 | - | C>S | 16,20 | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05310004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05310005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x05320003 | - | C>S | 16 | verified (both builders) |  |
| 0x0600000b | - | C>S | 36 | verified (both builders) |  |
| 0x0600000c | - | C>S | 32 | verified (both builders) |  |
| 0x0600000d | - | C>S | 32 | verified (both builders) |  |
| 0x06020002 | - | C>S | 28 | verified (both builders) |  |
| 0x06030006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x06030007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x06040000 | - | C>S | 36 | verified (both builders) |  |
| 0x07000006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000007 | - | C>S | 20 | verified (both builders) |  |
| 0x0700000b | - | C>S | 20 | verified (both builders) |  |
| 0x0700000c | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700000d | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700000e | - | C>S | 20 | verified (both builders) |  |
| 0x07000010 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000013 | - | C>S | 16 | verified (both builders) |  |
| 0x07000014 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000018 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000022 | - | C>S | 20 | verified (both builders) |  |
| 0x07000023 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000024 | - | C>S | 24 | verified (both builders) |  |
| 0x07000025 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000026 | - | C>S | 24 | verified (both builders) |  |
| 0x07000027 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000029 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700002a | - | C>S | 20 | verified (both builders) |  |
| 0x0700002b | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700002c | - | C>S | 20 | verified (both builders) |  |
| 0x0700002d | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700002e | - | C>S | 16 | verified (both builders) |  |
| 0x0700002f | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000031 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000032 | - | C>S | 20 | verified (both builders) |  |
| 0x07000033 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000034 | - | C>S | 20 | verified (both builders) |  |
| 0x07000035 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000036 | - | C>S | 16 | verified (both builders) |  |
| 0x07000037 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000038 | - | C>S | 16 | verified (both builders) |  |
| 0x07000039 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700003a | - | C>S | 20 | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700003b | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700003c | - | C>S | 20 | verified (both builders) |  |
| 0x0700003e | - | C>S | 20 | verified (both builders) |  |
| 0x07000040 | - | C>S | 16 | verified (both builders) |  |
| 0x07000041 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000042 | - | C>S | 16 | verified (both builders) |  |
| 0x07000043 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000048 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x07000049 | - | C>S | 16 | verified (both builders) |  |
| 0x0700004a | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700004b | - | C>S | 20 | verified (both builders) |  |
| 0x0700004c | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0700004d | - | C>S | 20 | verified (both builders) |  |
| 0x0700004e | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x08000005 | - | C>S | 20 | verified (both builders) |  |
| 0x08000006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09000001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x09000004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x09000006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical | opcode value recovered from an A2 offset switch (case-K); not in A2 opcodes.tsv |
| 0x09000008 | - | C>S | 16 | verified (both builders) |  |
| 0x0900000b | - | C>S | 16 | verified (both builders) |  |
| 0x0900000c | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0900000d | - | C>S | 20 | verified (both builders) |  |
| 0x0900000e | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0900000f | - | C>S | 16 | verified (both builders) |  |
| 0x09000010 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09000011 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09000012 | - | C>S | 16 | verified (both builders) |  |
| 0x09000013 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09010000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09010001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09020000 | ENTER_DONE | C>S | 16 | verified (both builders) |  |
| 0x09020002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09020003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09020005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09030000 | - | C>S | 20 | verified (both builders) |  |
| 0x09030001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09030002 | - | C>S | 16 | verified (both builders) |  |
| 0x09030003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09030004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x09030005 | - | C>S | 16 | verified (both builders) |  |
| 0x09030006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a000000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a020001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a020002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a020004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a020006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a020008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a020009 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a030000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0a030001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0c000001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0c000002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0c000003 | - | C>S | 16 | verified (both builders) |  |
| 0x0c000004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0c000006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0c000008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0c00000a | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0c00000c | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0d000001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0d000003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0d000005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0f000004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0f000005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0f020000 | - | C>S | 16 | verified (both builders) |  |
| 0x0f020001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0f020002 | - | C>S | 16 | verified (both builders) |  |
| 0x0f020003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0f020004 | - | C>S | 20 | verified (both builders) |  |
| 0x0f020005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0f020007 | - | C>S | 16 | verified (both builders) |  |
| 0x0f02000a | - | C>S | 16 | verified (both builders) |  |
| 0x0f02000d | - | C>S | 16 | verified (both builders) |  |
| 0x0f020010 | - | C>S | 16 | verified (both builders) |  |
| 0x0f020012 | - | C>S | 16 | verified (both builders) |  |
| 0x0f020013 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x0f030008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x10000001 | - | C>S | 28 | verified (both builders) |  |
| 0x10000002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x10000003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x10000004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x10000005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x10000006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x10000007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11000004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11000005 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11000006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11000007 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11000008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11010001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11010004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11010018 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11020000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11020006 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11020008 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x1102000a | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x1102000b | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x1102000d | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11030002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11050000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x11050001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x12000000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x12000001 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x12000002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x12000003 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x12020000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x14010002 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x14010004 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |
| 0x14020000 | - | S>C | - | unverified (no size on one/both sides) - INFERRED identical |  |

## Global only (1218) by family

| family | count | opcodes |
|---|---|---|
| 0x0204 | 19 | 02040024, 02040025, 02040026, 02040027, 02040029, 0204002a, 0204002b, 0204002e, 02040036, 02040038, 02040039, 0204003a, 02040040, 02040041, 02040042, 02040044, 0204004a, 0204004d, 0204004e |
| 0x0206 | 1 | 02060005 |
| 0x020d | 2 | 020d000c, 020d000d |
| 0x0300 | 16 | 03000011=LOGIN_0011, 03000012=LOGIN_0012, 03000014, 03000015, 03000018, 0300001e, 0300001f=VL_LOGIN, 03000020=SECONDPW_OPEN, 03000021=SECONDPW_VERIFY, 03000022=SECONDPW_VERIFY_ACK, 03000025=SECONDPW_SET, 03000026=SECONDPW_SET_ACK, 03000028=SECONDPW_CHANGE, 03000029=SECONDPW_CHANGE_ACK, 0300002a, 03000030 |
| 0x0301 | 2 | 03010004, 03010005 |
| 0x0302 | 7 | 0302000a, 0302000b, 0302000d, 03020016, 03020017, 03020018, 03020019 |
| 0x0400 | 3 | 04000015=LOCK_0015, 04000016, 04000017 |
| 0x0500 | 27 | 05000001, 05000003, 05000004, 05000005, 05000006, 05000007, 05000013, 05000014, 05000018, 0500001b, 0500001c, 0500001d, 0500001e, 0500001f, 05000020, 05000023, 05000024, 05000026, 05000027, 05000028, 05000029, 05000030, 05000031, 05000033, 05000034, 05000035, 05000036 |
| 0x0502 | 4 | 05020011, 05020012, 05020013, 05020014 |
| 0x0506 | 33 | 05060001, 05060017, 05060018, 05060019, 0506001a, 0506001b, 0506001c, 0506001d, 0506001e, 0506001f, 05060020, 05060023, 05060024, 05060025, 05060026, 05060027, 05060029, 05060030, 05060031, 05060032, 05060033, 05060034, 05060035, 05060036, 05060037, 05060038, 05060039, 0506003a, 0506003e, 0506003f, 05060040, 05060041, 05060042 |
| 0x0508 | 1 | 05080003 |
| 0x0509 | 1 | 0509000c |
| 0x050a | 13 | 050a0000, 050a0002, 050a0004, 050a0006, 050a0008, 050a0009, 050a000a, 050a000b, 050a000c, 050a000d, 050a000e, 050a000f, 050a0010 |
| 0x050b | 15 | 050b0000, 050b0002, 050b0004, 050b0006, 050b0008, 050b0009, 050b0010, 050b0011, 050b0012, 050b0013, 050b0014, 050b0015, 050b0016, 050b0017, 050b0018 |
| 0x050c | 4 | 050c0031, 050c0032, 050c0036, 050c0037 |
| 0x050d | 15 | 050d0010=MOVE, 050d0011, 050d0012, 050d0013, 050d0014, 050d0015, 050d0016, 050d0017=ENTER_WORLD (WAITENTER), 050d0018, 050d0019, 050d001a, 050d001b, 050d001c, 050d001d, 050d001e |
| 0x050e | 13 | 050e0001, 050e0003, 050e0004, 050e0007, 050e0009, 050e000b, 050e000d, 050e000e, 050e0013, 050e0014, 050e0015, 050e0016, 050e0017 |
| 0x050f | 18 | 050f0001, 050f0002, 050f0003, 050f0004, 050f0005, 050f0009, 050f000a, 050f0010, 050f0011, 050f0012, 050f0013, 050f0014, 050f0015, 050f0016, 050f0017, 050f0018, 050f0019, 050f001a |
| 0x0515 | 10 | 0515000b, 05150011, 05150012, 05150013, 05150014, 05150015, 05150016, 05150017, 05150018, 05150019 |
| 0x0518 | 8 | 0518000a, 0518000b, 0518000c, 0518000f, 05180010, 05180011, 05180012, 05180013 |
| 0x051a | 22 | 051a0010, 051a0012, 051a0013, 051a0014, 051a0015, 051a0016, 051a0017, 051a0018, 051a0019, 051a001a, 051a001b, 051a001c, 051a001d, 051a001f, 051a0020, 051a0021, 051a0022, 051a0023, 051a0024, 051a0025, 051a0026, 051a0027 |
| 0x051c | 1 | 051c0005 |
| 0x051f | 1 | 051f0003 |
| 0x0522 | 10 | 05220001, 05220003, 05220004, 05220006, 05220007, 05220009, 0522000b, 0522000d, 0522000e, 05220011 |
| 0x0526 | 27 | 05260000, 05260001, 05260004, 05260005, 05260006, 05260007, 05260008, 05260009, 0526000a, 0526000b, 0526000c, 0526000e, 05260011, 05260012, 05260013, 05260014, 05260015, 05260016, 05260017, 05260018, 05260019, 05260020, 05260021, 05260022, 05260023, 05260025, 05260026 |
| 0x0528 | 28 | 05280021, 05280022, 05280023, 05280024, 05280025, 05280026, 05280027, 05280028, 05280029, 0528002a, 0528002b, 0528002c, 0528002d, 0528002e, 0528002f, 05280030, 05280031, 05280032, 05280033, 05280034, 05280035, 05280036, 05280037, 05280038, 05280039, 0528003a, 0528003b, 0528003c |
| 0x052a | 20 | 052a0001, 052a0003, 052a0005, 052a0007, 052a0008, 052a0009, 052a0010, 052a0011, 052a0012, 052a0013, 052a0014, 052a0015, 052a0016, 052a0017, 052a0018, 052a0019, 052a001a, 052a001b, 052a001c, 052a001d |
| 0x052b | 2 | 052b0005, 052b0006 |
| 0x052c | 18 | 052c0000, 052c0002, 052c0004, 052c0006, 052c0007, 052c0008, 052c0009, 052c000a, 052c000b, 052c000c, 052c000d, 052c0010, 052c0011, 052c0012, 052c0013, 052c0014, 052c0015, 052c0016 |
| 0x052d | 8 | 052d0000, 052d0002, 052d0004, 052d0006, 052d0008, 052d0009, 052d000a, 052d000b |
| 0x052f | 2 | 052f0001, 052f0002 |
| 0x0530 | 18 | 05300004, 05300007, 05300008, 05300009, 0530000a, 0530000b, 0530000c, 0530000d, 0530000e, 0530000f, 05300010, 05300011, 05300012, 05300013, 05300014, 0530001a, 0530001b, 0530001d |
| 0x0531 | 1 | 05310006 |
| 0x0534 | 1 | 05340000 |
| 0x0535 | 5 | 05350000, 05350001, 05350002, 05350003, 05350004 |
| 0x0536 | 1 | 05360000 |
| 0x0537 | 18 | 05370000, 05370001, 05370002, 05370003, 05370004, 05370005, 05370006, 05370008, 05370009, 05370010, 05370011, 05370012, 05370015, 05370016, 05370017, 05370018, 05370019, 05370020 |
| 0x0538 | 8 | 05380000, 05380001, 05380002, 05380003, 05380004, 05380005, 05380006, 05380007 |
| 0x0539 | 35 | 05390000, 05390001, 05390002, 05390003, 05390004, 05390005, 05390006, 05390007, 05390008, 05390009, 0539000a, 0539000b, 0539000c, 0539000d, 0539000e, 0539000f, 05390010, 05390011, 05390012, 05390013, 05390014, 05390015, 05390016, 05390017, 05390018, 05390019, 0539001a, 0539001b, 0539001c, 0539001d, 0539001e, 0539001f, 05390020, 05390021, 05390022 |
| 0x053a | 2 | 053a0001, 053a0003 |
| 0x053b | 33 | 053b0000, 053b0001, 053b0002, 053b0003, 053b0004, 053b0005, 053b0006, 053b0007, 053b0008, 053b0009, 053b0010, 053b0011, 053b0013, 053b0014, 053b0015, 053b0016, 053b0019, 053b0020, 053b0021, 053b0022, 053b0023, 053b0024, 053b0025, 053b0026, 053b0027, 053b0028, 053b0029, 053b0030, 053b0031, 053b0032, 053b0033, 053b0035, 053b0036 |
| 0x053c | 43 | 053c0003, 053c0011, 053c0012, 053c0016, 053c0017, 053c0018, 053c001a, 053c001b, 053c001c, 053c001d, 053c001e, 053c001f, 053c0020, 053c0021, 053c0022, 053c0023, 053c0024, 053c0025, 053c0026, 053c0027, 053c0028, 053c0029, 053c0032, 053c0033, 053c0034, 053c0035, 053c0036, 053c0038, 053c0039, 053c003b, 053c003c, 053c003d, 053c003e, 053c003f, 053c0040, 053c0041, 053c0042, 053c0043, 053c0044, 053c0045, 053c0046, 053c0048, 053c0049 |
| 0x053d | 12 | 053d0003, 053d0007, 053d0008, 053d000a, 053d000b, 053d000d, 053d001b, 053d001c, 053d001d, 053d001e, 053d001f, 053d0020 |
| 0x053e | 1 | 053e0010 |
| 0x053f | 4 | 053f0000, 053f0001, 053f0002, 053f0004 |
| 0x0541 | 3 | 05410000, 05410001, 05410002 |
| 0x0542 | 2 | 05420000, 05420003 |
| 0x0543 | 6 | 05430000, 05430001, 05430002, 05430003, 05430004, 05430005 |
| 0x0544 | 39 | 05440001, 05440002, 05440003, 05440004, 05440005, 05440006, 05440007, 05440008, 05440009, 0544000a, 0544000b, 0544000c, 0544000d, 0544000f, 05440010, 05440012, 05440013, 05440014, 05440015, 05440016, 05440017, 05440018, 05440019, 0544001a, 0544001b, 0544001c, 0544001d, 0544001e, 0544001f, 05440020, 05440021, 05440022, 05440023, 05440024, 05440025, 05440026, 05440027, 05440028, 05440029 |
| 0x0545 | 17 | 05450000, 05450003, 05450004, 05450005, 05450006, 05450007, 05450008, 05450009, 0545000a, 0545000b, 0545000c, 0545000d, 0545000e, 05450011, 05450012, 05450013, 05450014 |
| 0x0546 | 2 | 05460000, 05460001 |
| 0x0547 | 10 | 05470000, 05470001, 05470002, 05470003, 05470004, 05470005, 05470006, 05470007, 05470008, 05470009 |
| 0x0548 | 5 | 05480000, 05480001, 05480002, 05480003, 05480004 |
| 0x0549 | 4 | 05490001, 05490002, 05490003, 05490004 |
| 0x054b | 4 | 054b0000, 054b0001, 054b0002, 054b0003 |
| 0x054c | 2 | 054c0000, 054c0001 |
| 0x054d | 11 | 054d0000, 054d0001, 054d0002, 054d0003, 054d0004, 054d0005, 054d0006, 054d0007, 054d0008, 054d0009, 054d000a |
| 0x054e | 11 | 054e0000, 054e0001, 054e0002, 054e0003, 054e0004, 054e0005, 054e0006, 054e0007, 054e0008, 054e0009, 054e000a |
| 0x054f | 5 | 054f0000, 054f0001, 054f0002, 054f0003, 054f0004 |
| 0x0550 | 7 | 05500000, 05500001, 05500002, 05500003, 05500004, 05500005, 05500006 |
| 0x0551 | 8 | 05510000, 05510001, 05510002, 05510003, 05510004, 05510005, 05510006, 05510007 |
| 0x0552 | 12 | 05520000, 05520001, 05520002, 05520003, 05520004, 05520005, 05520006, 05520007, 05520008, 05520009, 05520010, 05520011 |
| 0x0553 | 7 | 05530000, 05530001, 05530002, 05530003, 05530004, 05530005, 05530006 |
| 0x0554 | 9 | 05540000, 05540001, 05540002, 05540003, 05540004, 05540005, 05540006, 05540007, 05540008 |
| 0x0555 | 18 | 05550001, 05550002, 05550003, 05550004, 05550005, 05550006, 05550007, 05550008, 05550009, 0555000a, 0555000b, 0555000c, 0555000d, 0555000e, 0555000f, 05550010, 05550011, 05550012 |
| 0x0556 | 2 | 05560000, 05560001 |
| 0x0561 | 4 | 05610000, 05610001, 05610002, 05610003 |
| 0x0562 | 9 | 05620001, 05620002, 05620003, 05620004, 05620005, 05620006, 05620007, 05620008, 05620009 |
| 0x0564 | 6 | 05640000, 05640001, 05640002, 05640003, 05640004, 05640005 |
| 0x0565 | 9 | 05650000, 05650001, 05650002, 05650003, 05650004, 05650005, 05650006, 05650007, 05650008 |
| 0x0566 | 4 | 05660010, 05660011, 05660012, 05660013 |
| 0x0567 | 7 | 05670000, 05670001, 05670002, 05670003, 05670004, 05670005, 05670006 |
| 0x0568 | 13 | 05680000, 05680001, 05680002, 05680003, 05680004, 05680005, 05680006, 05680007, 05680008, 05680009, 0568000a, 0568000e, 0568000f |
| 0x0569 | 7 | 05690000, 05690003, 05690004, 05690005, 05690006, 05690007, 05690008 |
| 0x0570 | 6 | 05700000, 05700001, 05700002, 05700003, 05700004, 05700005 |
| 0x0571 | 1 | 05710001 |
| 0x0572 | 5 | 05720000, 05720001, 05720002, 05720003, 05720004 |
| 0x0574 | 2 | 05740000, 05740001 |
| 0x0575 | 4 | 05750000, 05750001, 05750002, 05750004 |
| 0x0576 | 8 | 05760001, 05760002, 05760003, 05760005, 05760006, 05760007, 05760008, 05760009 |
| 0x0577 | 3 | 05770001, 05770003, 05770005 |
| 0x0578 | 15 | 05780000, 05780001, 05780002, 05780003, 05780004, 05780009, 0578000a, 0578000b, 0578000c, 0578000d, 0578000e, 0578000f, 05780013, 05780014, 05780015 |
| 0x0580 | 3 | 05800000, 05800001, 05800002 |
| 0x0581 | 10 | 05810000, 05810001, 05810002, 05810003, 05810004, 05810005, 05810006, 05810007, 05810008, 05810009 |
| 0x0582 | 7 | 05820000, 05820001, 05820002, 05820003, 05820004, 05820005, 05820006 |
| 0x0583 | 11 | 05830000, 05830001, 05830002, 05830003, 05830004, 05830005, 05830006, 05830007, 05830008, 05830009, 0583000a |
| 0x0584 | 2 | 05840001, 05840003 |
| 0x0602 | 1 | 06020000 |
| 0x0700 | 23 | 07000008, 07000046, 0700004f, 07000050, 07000052, 07000053, 07000054, 07000055, 07000056, 07000057, 07000058, 07000059, 0700005a, 0700005b, 0700005c, 0700005d, 0700005e, 0700005f, 07000060, 07000062, 07000063, 07000064, 07000065 |
| 0x0800 | 27 | 0800000b, 0800000c, 0800000d, 0800000e, 0800000f, 08000010, 08000012, 08000013, 08000014, 08000015, 08000016, 08000017, 08000018, 08000019, 08000020, 08000021, 08000022, 08000023, 08000024, 08000025, 08000026, 08000027, 08000028, 08000029, 08000030, 08000031, 08000032 |
| 0x0900 | 12 | 09000007, 09000009, 0900000a, 09000014, 09000015, 09000016, 09000017, 09000018, 09000019, 0900001a, 0900001b, 0900001d |
| 0x0903 | 35 | 09030011, 09030012, 09030014, 09030015, 09030016, 09030017, 09030018, 09030019, 09030020, 09030021, 09030022, 09030023, 09030024, 09030025, 09030026, 09030027, 09030028, 09030029, 0903002a, 0903002b, 0903002c, 0903002d, 0903002e, 0903002f, 09030030, 09030031, 09030032, 09030033, 09030034, 09030035, 09030036, 09030037, 09030038, 09030039, 0903003a |
| 0x0a01 | 3 | 0a010009, 0a010010, 0a010013 |
| 0x0a04 | 6 | 0a040000, 0a040001, 0a040004, 0a040006, 0a040007, 0a040008 |
| 0x0b10 | 1 | 0b100012 |
| 0x0c00 | 3 | 0c00000d, 0c00000e, 0c00000f |
| 0x0d00 | 22 | 0d000008, 0d000009, 0d00000a, 0d00000b, 0d00000c, 0d00000d, 0d00000e, 0d00000f, 0d000010, 0d000013, 0d000014, 0d000015, 0d000016, 0d000017, 0d000018, 0d00001a, 0d00001b, 0d00001c, 0d00001d, 0d00001e, 0d00001f, 0d000020 |
| 0x0e00 | 1 | 0e000002 |
| 0x0e03 | 1 | 0e030000 |
| 0x1000 | 4 | 10000008, 10000009, 10000010, 10000011 |
| 0x1100 | 2 | 1100000c, 11000010 |
| 0x1101 | 8 | 11010005, 11010007, 11010008, 1101000a, 1101000b, 1101000d, 11010010, 11010011 |
| 0x1102 | 3 | 1102000e, 1102000f, 11020010 |
| 0x1103 | 3 | 11030006, 11030008, 1103000a |
| 0x1104 | 1 | 11040023 |
| 0x1105 | 5 | 11050009, 11050010, 11050013, 11050014, 11050015 |
| 0x1202 | 7 | 12020001, 12020002, 12020003, 12020004, 12020005, 12020006, 12020007 |
| 0x1300 | 7 | 13000000, 13000001, 13000002, 13000003, 13000004, 13000005, 13000010 |
| 0x1401 | 2 | 14010016, 14010017 |
| 0x1500 | 9 | 15000000, 15000001, 15000002, 15000004, 15000005, 15000006, 15000007, 15000008, 15000009 |
| 0x1600 | 6 | 16000002, 16000004, 16000011, 16000012, 16000013, 16000014 |
| 0x1601 | 10 | 16010000, 16010001, 16010002, 16010003, 16010004, 16010005, 16010006, 16010007, 16010008, 16010009 |
| 0x1602 | 14 | 16020000, 16020001, 16020002, 16020003, 16020004, 16020005, 16020008, 16020009, 1602000a, 1602000b, 1602000c, 1602000d, 1602000e, 1602000f |
| 0x1700 | 1 | 17000000 |
| 0x1701 | 1 | 17010001 |
| 0x1702 | 2 | 17020001, 17020007 |
| 0x1704 | 5 | 17040012, 17040014, 17040015, 17040017, 1704001b |
| 0x1705 | 2 | 17050002, 17050013 |
| 0x1801 | 3 | 18010007, 18010010, 18010012 |
| 0x1e00 | 2 | 1e000000, 1e000001 |
| 0x2000 | 22 | 20000000, 20000001, 20000002, 20000004, 20000005, 20000006, 20000008, 20000009, 2000000a, 2000000b, 2000000c, 2000000d, 2000000e, 2000000f, 20000013, 20000014, 20000015, 20000024, 20000027, 20000028, 20000031, 20000032 |
| 0x2100 | 2 | 21000000, 21000001 |
| 0x2200 | 1 | 22000001=STATUS_PUSH |
| 0x3000 | 6 | 30000000, 30000001, 30000002, 30000004, 30000005, 30000006 |
| 0x3003 | 9 | 30030000, 30030001, 30030002, 30030003, 30030004, 30030005, 30030006, 30030007, 30030008 |
| 0x4000 | 5 | 40000005, 40000006, 40000007, 40000008, 40000009 |
| 0x4100 | 8 | 41000001, 41000002, 41000003, 41000004, 41000005, 41000006, 41000007, 41000008 |
| 0x4101 | 1 | 41010001 |
| 0x4102 | 8 | 41020001, 41020002, 41020003, 41020004, 41020005, 41020006, 41020007, 41020008 |
| 0x4103 | 9 | 41030001, 41030002, 41030003, 41030004, 41030005, 41030006, 41030007, 41030008, 41030009 |
| 0x4104 | 3 | 41040001, 41040002, 41040003 |
| 0x4105 | 2 | 41050001, 41050002 |
| 0x4200 | 6 | 42000001, 42000002, 42000003, 42000004, 42000005, 42000007 |
| 0x4201 | 2 | 42010001, 42010003 |
| 0x4202 | 5 | 42020001, 42020003, 42020004, 42020005, 42020006 |
| 0x4203 | 4 | 42030001, 42030002, 42030003, 42030004 |
| 0x4205 | 4 | 42050001, 42050002, 42050003, 42050004 |
| 0x4300 | 5 | 43000001, 43000002, 43000003, 43000004, 43000005 |
| 0x4500 | 7 | 45000002, 45000005, 45000008, 45000009, 4500000a, 4500000b, 4500000c |
| 0x4600 | 12 | 46000004, 46000005, 46000009, 4600000c, 4600000d, 4600000e, 4600000f, 46000010, 46000011, 46000012, 46000013, 46000014 |
| 0x4800 | 12 | 48000001, 48000002, 48000003, 48000004, 48000005, 48000006, 48000007, 48000008, 48000009, 4800000a, 4800000b, 4800000c |
