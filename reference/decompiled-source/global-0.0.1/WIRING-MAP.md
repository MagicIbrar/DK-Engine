# Global 0.0.1 client: opcode table and wiring map

Generated <date> 21:25 PT (America/Los_Angeles). Machine-readable twin: `opcodes.json` (same rows, full builder/handler/field detail).

## Sources and labels

| label | what it is |
|---|---|
| **Global binary** | `Scrubbed Global 0.0.1\DK Engine\global-client\bin\dekaron.exe`, 13,458,832 bytes, SHA256 `a0f0bddd901f3ff6b66d4d37639178743c829657ac4874194d08467901ad7cec`, PE timestamp 0x6ae1895f. It is packed (section names `kxiwdymm`/`bsdnhrop`), so the binary itself only proves identity. Identical to `Global client\bin\dekaron.exe`. |
| **decompile** (D) | `decompiled-named.c`, a memory-reconstructed image at base 0x006e0000 with 96,011 functions (20.8 % named). The decompile README says this is the client the 0.0.1 launcher uses. **Every opcode in this map comes from here.** |
| **4.2.0 code** | `4.2.0\server` + `4.2.0\src` (1,109 .mjs/.js files, copied read-only). |
| engine bridge (B) | DK Engine bridge `protocol.mjs` + `gameplay/modules` (142 modules, 569 opcodes). Its layouts were validated on Global 43.3.0 live traffic. This is **not 4.2.0**; it is shown in its own column. |
| observed (O) | Bridge packet logs from <date> (`<path>, 115 opcodes, 43.3.0-era client). **All 115 observed opcodes exist in the 0.0.1 decompile.** |
| prior 43.3.0 | The earlier box map `<path> (Global 43.3.0, SHA 41f77300…, a different build). Used only as labelled hints. |
| **INFERRED** | Anything not read directly from the 0.0.1 decompile: descriptions built from RTTI class or family, direction for factory-only builders, every 4.2.0 feature mapping, and anything carried over from 43.3.0. Each JSON row has an `inferred` list. |

## Counts

| | count |
|---|---|
| opcodes in map (after noise filter) | **1693** |
| C>S only / S>C only / both | 562 / 1084 / 47 |
| families | 178 |
| implemented in 4.2.0 at wire level | **0** (4.2.0 has no Dekaron binary protocol) |
| named explicitly by 4.2.0 code, semantic equivalent only | **4** (0x05260021, 0x05260022, 0x05260023, 0x052b0005) |
| 4.2.0 has a feature for this family (INFERRED) | 1625 |
| **MISSING in 4.2.0** (wire) | **1693** of 1693 |
| MISSING in 4.2.0, no feature equivalent either (INFERRED) | 68 |
| claimed by a DK Engine bridge module (not 4.2.0) | 595 |
| rows with at least one INFERRED part | 1664 |
| dropped as noise (non-opcode constants) | 16: 0x281000d, 0x2810010, 0x2aaaaaa, 0x30c30c2, 0x35e50d6, 0x5d1745c, 0x6666665, 0x71c71c6, 0xa4c0024, 0xaaaaaa9, 0xccccccb, 0xffffffe, 0x20030820, 0x20040303, 0x20040729, 0x20191130 |

Noise filter: the dropped rows are values such as vector max_size checks (0x2aaaaaa, 0xaaaaaa9, 0xccccccb, 0xffffffe), date or version literals (0x20040303, 0x20191130) and DriverKernel::Data bone-animation IDs. 0x7xxxxxxx UI command IDs were excluded during extraction.

## Packet header and encryption (D)

- **Header**: 16 bytes, **big-endian on the wire**. It is swapped by FUN_00917890 on receive and FUN_009177c0 on send; the send side also stamps the sequence number.

| off | type | field |
|---|---|---|
| +0x0 | u32 | checksum: ~CRC32 over the encrypted bytes from +4 |
| +0x4 | u16 | seq: sequenced packets are acked with SESSION_ACK 0x00020005. An opcode whose low byte has bit 0x80 set is not sequenced (B). |
| +0x6 | u16 | total size including the header, at most 0x400 (larger packets are rejected) |
| +0x8 | u32 | tick (builders write `DAT_01f9b6b4 vf+0x2c`) |
| +0xC | u32 | opcode, `0xFFFFnnnn` = family/index |
| +0x10.. | | body. Game bodies are **little-endian** raw structs. Session bodies (0x0002xxxx) are byte-swapped to big-endian. The PC_OBJECT LoadInfo block is byte-swapped field by field (B). |

- **Cipher**: class `Network::Session::Cipher::TCP`; decrypt is FUN_00917580.
  - For each byte i ≥ 4: `plain = enc ^ (CRC32TAB[i & 0xff] & 0xff) ^ key`, where `key = keyLo ^ keyHi`. The two key bytes live at session+0xc.
  - A running CRC32 (table DAT_01aa3c30, polynomial 0xedb88320) is taken over the encrypted bytes, and `~crc` must equal the u32 at +0.
  - The initial key is **0x0F** until CON_ACK delivers keyLo/keyHi. CON_ACK reading the key bytes at +0x18/+0x1c is D; the 0x0F start value is INFERRED from the 43.3.0 bridge (B).
- **Builder pattern (C>S)**: `p = operator_new(0x400); p+8 = tick; p+0xc = opcode; p+6 = size; …fields…; (*(DAT_01f9b818+4))->vf+0xc(p)` sends the packet. A builder without that last call is a *factory*; its caller fills the fields and sends.
- **Dispatch (S>C)**: internal event 0x50011 means "packet received". OnMessage handlers test `*(u32*)(pkt+0xc)` with a switch, a switch with an offset, or a compare chain.

### Session layer (D unless noted)

| opcode | name | dir | 0.0.1 function | body |
|---|---|---|---|---|
| 0x00020080 | CON | C>S | B 0x00913480(factory) | client hello; body u32be clientTick (session+0x2c); size 0x14; sent under initial key |
| 0x00020081 | CON_ACK | S>C | H 0x00912d30(cmp) | server hello; FUN_00912da0 reads key bytes @0x18,@0x1c (cipher key = lo^hi), 64-byte passport @0x20..0x5f, ticks @0x10/@0x14 (byteswapped) |
| 0x00020082 | CON_CONFIRM | C>S | B 0x00912f70(factory) | client echoes serverTick (FUN_00912f70) under the new key |
| 0x00020083 | PING | both | B 0x00912320(factory); H 0x009120c0 | keep-alive ping, body u32be tick; both directions |
| 0x00020084 | PONG | both | B 0x009124d0(factory); H 0x009121d0 | ping echo, body u32be tick; both directions |
| 0x00020005 | SESSION_ACK | C>S | B 0x009149e0(factory) | sequenced-packet ack, body u16be seq (FUN_009149e0) |
| 0x00010002 | INTERNAL_CONNECTED | C>S | B 0x00912ee0(factory) | internal connected event (not on the wire) |

## Flows

The flows below use 0.0.1 decompile functions. The reply orders come from observed 43.3.0-era traffic (O); every opcode in them exists in 0.0.1.

### 1. Login (login server)
```
C>S CON 0x00020080 (key 0x0F)          -> S>C CON_ACK 0x00020081 {ticks, keyLo@+0x18, keyHi@+0x1c, passport[64]@+0x20}  [FUN_00912d30/FUN_00912da0]
C>S CON_CONFIRM 0x00020082 (new key)   ; internal 0x10005 time-sync event; PING/PONG 0x00020083/84 keep-alive; SESSION_ACK 0x00020005
C>S 0x03000012 (3x 3-char version/locale strings, FUN_00872ab0)  <-> S>C 0x03000011 (FUN_00872ef0 reads same triple)
C>S VL_LOGIN 0x0300001f (784 B: a[256] b[256] c[256] from launcher args; factory FUN_00874500)
S>C LOGIN_ACK 0x03000001  -> dispatcher FUN_00872dd0 -> FUN_008731b0 "Rev Login Packet" (result 0 = ok; userNo, sessionKey, name)
     optional second password: S>C 0x03000020 SECONDPW_OPEN (mode) -> C>S 0x03000021 later pass / 0x03000025 SET / 0x03000028 CHANGE -> S>C 0x03000022 / 0x03000026 / 0x03000029
     other login-dispatcher cases in 0.0.1: 0x03000015 (FUN_008736e0), 0x0300002a
```
### 2. Character select (still on the login server)
```
C>S PCLIST_REQ 0x02060000 (u32 @+0x10, FUN_0084b2e0)
S>C 0x02060001 PCLIST_ACK -> [0x02040000 PC_OBJECT + 0x02060002 PCLIST_NAME] x N -> 0x02060003 PCLIST_END   (dispatcher FUN_0084b0c0 / FUN_0141f8b0)
C>S CHAR_CREATE 0x03020000 (64 B: wchar name[21]@+0x10, u8 class@+0x3a; FUN_00854310) -> S>C 0x03020001 (i32 result)
C>S CHAR_DELETE 0x03020002 (60 B: wchar name[21]) -> S>C 0x03020003 (FUN_0084ba20) -> client re-sends PCLIST_REQ
ServerTransfer UI (Ghost::GameHandler::ServerTransfer::UIHandler): C>S 0x03020004/06/08/0a <-> S>C 0x03020005/07/09/0b (FUN_013ef180)
```
### 3. Channel / server select -> Checkout
```
C>S CHECKOUT 0x03010000 (60 B, wchar name[21]; Connect::State::Command::Checkout FUN_00874e30, "Send Check Out")
S>C CHECKOUT_ACK 0x03010001 (i32 result + game-server ticket; checked in FUN_00874f60)
client drops the login connection and connects to the chosen game server/channel (new CON/CON_ACK handshake)
back to login: C>S CHECKIN 0x03010002 (92 B: userNo, sessionKey, ticket, wchar name[21], account@+0x46; FUN_008790f0) -> S>C 0x03010003
```
### 4. Enter world (game server)
```
C>S LOCK 0x04000000 (348 B: sessionKey@+0x10, userNo@+0x14, ticket@+0x18, userId@+0x1c, u32@+0x154/+0x158; Connect::State::Command::Lock FUN_00875b40)
S>C 0x04000002 LOCK_ACK_START  ("Rev Lock Start", FUN_00876180)   [enter-world dispatcher FUN_00875e10]
S>C 0x02040000 PC_OBJECT (own PC, FUN_008762a0 "ExecCmd::Lock InfoPacket mapIdx") + 0x02060002 own name
S>C 0x04000003 LOCK_ACK_END    ("Rev Lock End", FUN_00876c60: worldId / WorldIdx / ChannelIdx)
S>C 0x0204000f, 0x02040001.., 0x0204004e (preset, FUN_00876750) ... character data stream; 0x1e000000/1, 0x04000015 also routed here
WaitEnter state (Connect::State::Command::WaitEnter): S>C 0x050d0017 ENTER_WORLD -> C>S 0x09020000 ENTER_DONE -> in game
in game: C>S 0x050d0010 MOVE (52 B), 0x0e000002 ATTACK (64 B); S>C 0x05040000 PC_STATE (448 B), 0x05050000 objects, 0x22000001 status push
leave: C>S UNLOCK 0x04000006 (header only, FUN_00879680)
```

### Flow -> 4.2.0 (INFERRED: 4.2.0 replaces all of this with HTTP/JSON)

| Global step | 4.2.0 equivalent |
|---|---|
| CON / CON_ACK / cipher / SESSION_ACK / PING | none. HTTP + WS transport; `/api/world/ping` (server/world/api.mjs) |
| VL_LOGIN 0x0300001f, LOGIN_ACK | `/api/auth/login`, `/api/auth/launch-ticket`, `/api/auth/launch-redeem` (server/accounts/api.mjs) |
| SECONDPW 0x03000020-29 | `/api/auth/secondpw` |
| PCLIST 0x0206xxxx, CHAR_CREATE/DELETE 0x0302000x | `/api/characters` |
| CHECKOUT / channel select | `/api/world/channels`, `/api/world/join`, the `channel` command |
| LOCK / PC_OBJECT / LOCK_ACK_END / ENTER_WORLD / ENTER_DONE | `/api/world/join` -> `/api/world/state` -> `/api/world/client-ready` / `/api/world/ready` |
| UNLOCK / CHECKIN / LOGOUT | `/api/world/leave`, `/api/auth/logout` |
| every in-game opcode | `POST /api/world/action {type:...}`, dispatched in server/world/core.mjs and modules (115 command types) |

## Dispatchers (D)

| dispatcher | opcodes | class (first seen) |
|---|---|---|
| 0x013922c0 | 87 | - |
| 0x012a5f30 | 54 | Ghost::GameHandler::DKSquare::State::Lobby |
| 0x01315010 | 46 | - |
| 0x013c06a0 | 45 | - |
| 0x012bc680 | 43 | Ghost::GameHandler::Message::Party::LeaveParty |
| 0x00875e10 | 34 | - |
| 0x014d64c0 | 32 | - |
| 0x01426bc0 | 28 | - |
| 0x014cd880 | 27 | - |
| 0x013a9230 | 26 | - |
| 0x013eda90 | 24 | - |
| 0x012c9730 | 24 | - |
| 0x013ffe50 | 24 | - |
| 0x0141f8b0 | 21 | - |
| 0x01263bc0 | 21 | - |
| 0x012f8be0 | 20 | - |
| 0x013cb9f0 | 20 | - |
| 0x01278680 | 20 | - |
| 0x01436960 | 19 | - |
| 0x013db170 | 18 | - |
| 0x013f3cb0 | 18 | - |
| 0x01285970 | 18 | - |
| 0x008e4db0 | 16 | Ghost::ModelCenter::Model2::Event::EventHandler::PacketQueue::Receiver::Enter |
| 0x013d0fa0 | 16 | - |
| 0x0123b2f0 | 14 | - |
| 0x008e2c20 | 13 | Ghost::ModelCenter::Model2::Event::EventHandler::PacketQueue::Receiver::Creature |
| 0x0132e630 | 13 | - |
| 0x014d36e0 | 13 | - |
| 0x01323260 | 12 | - |
| 0x01329830 | 12 | - |
| 0x0140c720 | 12 | - |
| 0x0084b0c0 | 11 | - |
| 0x0131f6a0 | 11 | - |
| 0x01472200 | 11 | - |
| 0x0140af00 | 10 | - |
| 0x01281c00 | 10 | Ghost::GameHandler::PVP::State::Idle |
| 0x01463e60 | 10 | - |
| 0x01365950 | 9 | - |
| 0x014a7c00 | 9 | - |
| 0x014b8f00 | 9 | - |

(Top 40 of 154 dispatchers. The full list is in opcodes.json.)

## Key findings

1. **4.2.0 does not speak the Global wire protocol at all.** Client.exe is a 183 KB WebView wrapper; the server takes JSON actions on `/api/world/action`. All 1693 Global opcodes are **MISSING** at wire level. To run the Global 0.0.1 client against 4.2.0 you need a protocol bridge that implements this map, or the DK Engine bridge.
2. Only **4 opcodes** are named in 4.2.0 code: 0x05260021/22/23 (map-event.mjs, `mapEvent` bus event; the file says outright "Binary 0x05260021 is not emulated") and 0x052B0005 (auto-report.mjs). 0x05260012/0x0526000c appear in comments only.
3. At feature level (INFERRED), 1625 of 1693 opcodes belong to a family that has a 4.2.0 command or module. Families with no 4.2.0 equivalent: 0x0001 Session/internal, 0x0207 Character object (misc), 0x020d Character object (misc), 0x0507 PC state, 0x0516 Creature event, 0x0519 Servant / effects, 0x0524 Enter event, 0x0527 Creature/enter events, 0x0529 Enter event, 0x052f Ornament events, 0x0536 (unattributed), 0x053e (unattributed), 0x0542 (unattributed), 0x0561 Dekaron provider, 0x0571 (unattributed), 0x0584 TalismanEffectTransform, 0x0602 Enter event, 0x0603 Effect event, 0x0a00 Chat, 0x0b10 Tool, 0x1200 (unattributed), 0x1202 (unattributed), 0x1700 Notice, 0x1801 (unattributed), 0x1e00 PC event, 0x2100 Aggro, 0x2200 Unity, 0x4500 (unattributed).
4. The 0.0.1 header and cipher match the 43.3.0 bridge implementation: the same 16-byte big-endian header, CRC32-keyed XOR and CON_ACK key bytes at +0x18/+0x1c. The core login, character and enter sizes also match (VL_LOGIN 784, CHECKOUT 60, CHECKIN 92, CHAR_CREATE 64, LOCK 348, PCLIST_REQ 24). The DK Engine bridge covers 595 of these opcodes and is the nearest working wire implementation.
5. Builds differ: the prior 43.3.0 map lists S>C opcodes such as 0x02040004..0x0204001c that are absent from the 0.0.1 decompile, which more likely reflects jump-table holes or build differences. Of the prior 577 C>S actions, 555 also appear in 0.0.1.
6. Limits: the decompile is memory-reconstructed and many functions are UNRECOVERED, so field layouts are partial. Factory builders (`sends=false`) have the fields filled in by their callers. Many S>C handlers only forward the packet into PacketQueue receivers, so their recorded `reads` are only the first level. Where the decompile is silent, the core-flow layouts come from the bridge (labelled B).

## Cross-reference vs 2007 Action 2 map

Done: see `A2-vs-GLOBAL.md` and `a2_vs_global.json` (identical 391, same-code-different 84, A2-only 134, Global-only 1218).

## Opcode tables by family

Columns: B = builder (C>S), H = handler (S>C), `(factory)` = the caller sends, `(cmp)` = compare only. Body offsets count from the end of the 16-byte header. 4.2.0 wire is MISSING for every row; the 4.2.0 column shows the feature mapping (INFERRED) and marks EXPLICIT references. "bridge" = DK Engine bridge module (not 4.2.0).

### 0x0001 Session/internal (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x00010002 | C>S | INTERNAL_CONNECTED | B 0x00912ee0(factory) | 24 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1 | internal connected event (not on the wire) | MISSING |  | D INFERRED |

### 0x0002 Session (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x00020005 | C>S | SESSION_ACK | B 0x009149e0(factory) | 20 | +0x0 ushort | sequenced-packet ack, body u16be seq (FUN_009149e0) | HTTP+WS transport; /api/world/ping (INFERRED) |  | D INFERRED |
| 0x00020080 | C>S | CON | B 0x00913480(factory) | 20 | +0x0 ptr/copy | client hello; body u32be clientTick (session+0x2c); size 0x14; sent under initial key | HTTP+WS transport; /api/world/ping (INFERRED) |  | D INFERRED |
| 0x00020081 | S>C | CON_ACK | H 0x00912d30(cmp) | - | - | server hello; FUN_00912da0 reads key bytes @0x18,@0x1c (cipher key = lo^hi), 64-byte passport @0x20..0x5f, ticks @0x10/@0x14 (byteswapped) | HTTP+WS transport; /api/world/ping (INFERRED) |  | D INFERRED |
| 0x00020082 | C>S | CON_CONFIRM | B 0x00912f70(factory) | 20 | +0x0 ptr/copy | client echoes serverTick (FUN_00912f70) under the new key | HTTP+WS transport; /api/world/ping (INFERRED) |  | D INFERRED |
| 0x00020083 | both | PING | B 0x00912320(factory); H 0x009120c0 | 20 | +0x0 ptr/copy | keep-alive ping, body u32be tick; both directions | HTTP+WS transport; /api/world/ping (INFERRED) |  | D |
| 0x00020084 | both | PONG | B 0x009124d0(factory); H 0x009121d0 | 20 | +0x0 ptr/copy | ping echo, body u32be tick; both directions | HTTP+WS transport; /api/world/ping (INFERRED) |  | D |

### 0x0204 Character object (PC_OBJECT / LoadInfo) (31)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x02040000 | S>C | PC_OBJECT | H 0x008762a0; H 0x01420a80 | obs 243,115 | +0x0 undefined4, +0x4 undefined4 | character load record: 8 bytes then LoadInfo @0x18 (LoadInfo is byte-swapped field by field -> big-endian); handler FUN_008762a0 logs "ExecCmd::Lock InfoPacket mapIdx" | /api/characters; /api/world/join (INFERRED) | core (server.mjs) | D+B+O |
| 0x02040001 | S>C |  | H 0x00876600 | obs 63,26,100 | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D+O INFERRED |
| 0x02040002 | S>C |  | H 0x00876590 | obs 26,100,178,139,137 | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D+O INFERRED |
| 0x02040003 | S>C |  | H 0x00876670 | obs 26 | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D+O INFERRED |
| 0x0204000f | S>C |  | H 0x00876830 | obs 387,31 | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D+O INFERRED |
| 0x02040010 | S>C |  | H 0x008768a0 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040011 | S>C |  | H 0x00876910 | obs 28 | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D+O INFERRED |
| 0x02040012 | S>C |  | H 0x00876980 | obs 30,28 | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D+O INFERRED |
| 0x02040013 | S>C |  | H 0x008767c0; H 0x01500570 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040015 | S>C |  | H 0x00877110 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040019 | S>C |  | H 0x00877340 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x0204001d | S>C |  | H 0x008773b0 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040024 | S>C |  | H 0x00877170 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040025 | S>C |  | H 0x008771f0 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040026 | S>C |  | H 0x00877260 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040027 | S>C |  | H 0x008772d0 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040029 | S>C |  | H 0x008774e0 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x0204002a | S>C |  | H 0x00876a60 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x0204002b | S>C |  | H 0x008766e0 | obs 26 | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D+O INFERRED |
| 0x0204002e | S>C |  | H 0x00877550 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040036 | S>C |  | H 0x00877420 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040038 | S>C |  | H 0x00877480 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040039 | S>C |  | H 0x014628d0 | - | +0x8 ptr | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x0204003a | S>C |  | H 0x008769f0 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040040 | S>C |  | H 0x013251e0 | - | +0x8 ptr | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040041 | S>C |  | H 0x008775b0 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040042 | S>C |  | H 0x00877610 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x02040044 | S>C |  | H 0x00877670 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x0204004a | S>C |  | H 0x008776d0 | - | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x0204004d | S>C |  | H 0x0084b4f0 | - | +0x44 int, +0x48 int, +0x50 uint | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D INFERRED |
| 0x0204004e | S>C |  | H 0x00876750; H 0x01420db0 | obs 73,120 | +0x0 undefined4, +0x4 undefined4 | Character object (PC_OBJECT / LoadInfo): reply/notification. Character/world object load records: the character list at character select and the own PC on world entry. | /api/characters; /api/world/join (INFERRED) |  | D+O INFERRED |

### 0x0206 Character list (PCLIST) (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x02060000 | C>S | PCLIST_REQ | B 0x0084b2e0 | 24 | +0x0 undefined4 | character list request, size 0x18: u32 @0x10 (account value) | /api/characters (INFERRED) | core (server.mjs) | D+B+O |
| 0x02060001 | S>C | PCLIST_ACK | H 0x0141f8b0(cmp); H 0x0084b0c0(cmp) | obs 20 | - | character list begin | /api/characters (INFERRED) | core (server.mjs) | D+B+O |
| 0x02060002 | S>C | PCLIST_NAME | H 0x00876460; H 0x01420b80 | obs 66,49 | +0x0 undefined4, +0x4 undefined4 | next listed character name (login) / own PC name (game server) | /api/characters (INFERRED) | core (server.mjs) | D+B+O |
| 0x02060003 | S>C | PCLIST_END | H 0x0141f8b0(cmp); H 0x0084b0c0(cmp) | obs 20 | - | end of list; client builds character select UI (max 6) | /api/characters (INFERRED) | core (server.mjs) | D+B+O |
| 0x02060005 | S>C |  | H 0x0084b0c0(cmp) | - | - | Character list (PCLIST): reply/notification. Character list request and list framing (begin / name / end). | /api/characters (INFERRED) |  | D INFERRED |

### 0x0207 Character object (misc) (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x02070002 | S>C |  | H 0x0140b450 | obs 26 | +0x8 ptr | Character object (misc): reply/notification. Character-related notice. Prior-build note (43.3.0, INFERRED for 0.0.1): S070: S>C 0x02070002 at packet+0x18. All multibyte scalar stream values BE; | MISSING |  | D+O INFERRED |

### 0x020d Character object (misc) (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x020d000c | S>C |  | H 0x01420bc0 | - | - | Character object (misc): reply/notification. Character-related notice during login/enter. | MISSING |  | D INFERRED |
| 0x020d000d | S>C |  | H 0x0141f8b0(cmp) | - | - | Character object (misc): reply/notification. Character-related notice during login/enter. | MISSING |  | D INFERRED |

### 0x0300 Login (21)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x03000000 | C>S | LOGIN (legacy id/pw) | B 0x00874560(factory) | 100 | - | factory only in 0.0.1 (size 100); legacy id/pw login variant | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |
| 0x03000001 | S>C | LOGIN_ACK | H 0x008731b0 | obs 80 | +0x4c undefined4, +0x50 undefined2, +0x52 undefined2 | login result; dispatcher FUN_00872dd0 -> FUN_008731b0 "Rev Login Packet"; 43.3.0 layout: u32 userNo@0x10, i32 result@0x14 (0 ok), u32 sessionKey@0x18, name@0x1c | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O |
| 0x03000002 | C>S | LOGOUT | B 0x00873c10; B 0x008745d0(factory) | 16 | - | header only (size 0x10) | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D |
| 0x03000003 | S>C |  | H 0x00878de0(cmp) | - | - | Login: reply/notification. Account login (VL launcher login, legacy id/pw variants), logout, second password. Likely reply to C>S 0x03000002 (request even / reply odd convention). | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |
| 0x03000004 | C>S |  | B 0x00874470(factory) | 168 | - | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |
| 0x03000011 | S>C | LOGIN_0011 | H 0x00872ef0 | - | +0x0 char, +0x3 char, +0x6 char | login-scene packet; handler FUN_00872ef0 reads three 3-char strings @0x10/@0x13/@0x16 (pairs with C>S 0x03000012 version/region triple) | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D |
| 0x03000012 | C>S | LOGIN_0012 | B 0x00872ab0 | 28 | +0x0 ptr/copy, +0x3 ptr/copy, +0x6 ptr/copy | three 3-byte strings @0x10/@0x13/@0x16 (client version/locale triple), size 0x1c | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D |
| 0x03000014 | C>S |  | B 0x008744a0(factory) | 820 | - | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |
| 0x03000015 | S>C |  | H 0x008736e0 | - | +0x44 int, +0x48 int, +0x104 int, +0x108 int | Login: reply/notification. Account login (VL launcher login, legacy id/pw variants), logout, second password. Likely reply to C>S 0x03000014 (request even / reply odd convention). | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |
| 0x03000018 | C>S |  | B 0x00874440(factory) | 64 | - | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |
| 0x0300001e | C>S |  | B 0x008744d0(factory) | 180 | - | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |
| 0x0300001f | C>S | VL_LOGIN | B 0x00874500(factory) | 784 | - | launcher (VL) login, size 0x310: char a[256]@0x10, b[256]@0x110, c[256]@0x210 (from launcher args; empty without launcher) | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x03000020 | S>C | SECONDPW_OPEN | H 0x00873770 | obs 20 | +0x4c undefined4 | second password prompt: u8 mode @0x10 (1 enter, 2 register) | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O |
| 0x03000021 | C>S | SECONDPW_VERIFY | B 0x00a56420(factory) | 84 | - | second password verify (size 0x54) | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x03000022 | S>C | SECONDPW_VERIFY_ACK | H 0x008738c0 | - | +0x0 int, +0x4 undefined4 | second password verify result | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O |
| 0x03000025 | C>S | SECONDPW_SET | B 0x00a56450(factory) | 84 | - | second password set (size 0x54) | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x03000026 | S>C | SECONDPW_SET_ACK | H 0x00873f10 | - | +0x0 undefined4 | second password set result | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O |
| 0x03000028 | C>S | SECONDPW_CHANGE | B 0x00a56480(factory) | 148 | - | second password change (size 0x94) | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x03000029 | S>C | SECONDPW_CHANGE_ACK | H 0x00873c10 | - | - | second password change result | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) | core (server.mjs) | D+B+O |
| 0x0300002a | S>C |  | H 0x00872dd0(cmp) | - | - | Login: reply/notification. Account login (VL launcher login, legacy id/pw variants), logout, second password. | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |
| 0x03000030 | C>S |  | B 0x00874530(factory) | 92 | - | Login: request. Account login (VL launcher login, legacy id/pw variants), logout, second password. | /api/auth/login, /api/auth/secondpw, /api/auth/logout (INFERRED) |  | D INFERRED |

### 0x0301 Login server Checkout/Checkin (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x03010000 | C>S | CHECKOUT | B 0x00874e30 | 60 | - | select character, leave login server (Connect::State::Command::Checkout, "Send Check Out"); size 0x3c; wchar name[21]@0x10 | /api/world/join, /api/world/leave (INFERRED) | core (server.mjs) | D+B+O |
| 0x03010001 | S>C | CHECKOUT_ACK | H 0x00874f60(cmp) | obs 44 | - | checkout result: i32 result@0x10, then game-server ticket/address | /api/world/join, /api/world/leave (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x03010002 | C>S | CHECKIN | B 0x008790f0 | 92 | +0x0 int, +0x4 int, +0x8 int, +0x36 undefined1 | return to login server (Connect::State::Command::Checkin), size 0x5c: u32 userNo@0x10, u32 sessionKey@0x14, u32 ticket@0x18, wchar name[21]@0x1c, account@0x46 | /api/world/join, /api/world/leave (INFERRED) | core (server.mjs) | D+B+O |
| 0x03010003 | S>C | CHECKIN_ACK | H 0x00879240(cmp) | obs 20 | - | checkin result i32@0x10 | /api/world/join, /api/world/leave (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x03010004 | C>S |  | B 0x00850770(factory) | 16 | - | Login server Checkout/Checkin: request. Leave login server with selected character (Checkout), or return to login server (Checkin). | /api/world/join, /api/world/leave (INFERRED) |  | D INFERRED |
| 0x03010005 | S>C |  | H 0x008542d0(cmp); H 0x0084de80 | - | - | Login server Checkout/Checkin: reply/notification. Leave login server with selected character (Checkout), or return to login server (Checkin). Likely reply to C>S 0x03010004 (request even / reply odd convention). | /api/world/join, /api/world/leave (INFERRED) |  | D INFERRED |

### 0x0302 Character create/delete + ServerTransfer (17)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x03020000 | C>S | CHAR_CREATE | B 0x00854310 | 64 | +0x2a undefined1, +0x2b undefined1, +0x2c undefined4 | size 0x40: wchar name[21]@0x10, u8 class@0x3a | /api/characters (create/delete) (INFERRED) | core (server.mjs) | D+B+O |
| 0x03020001 | S>C | CHAR_CREATE_ACK | H 0x008542d0(cmp) | obs 20 | - | i32 result@0x10 | /api/characters (create/delete) (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x03020002 | C>S | CHAR_DELETE | B 0x00c28af0; B 0x00c29010(factory) | 60 | - | size 0x3c: wchar name[21]@0x10 | /api/characters (create/delete) (INFERRED) | core (server.mjs) | D+B+O |
| 0x03020003 | S>C | CHAR_DELETE_ACK | H 0x0084ba20 | - | +0x8 undefined4, +0xc undefined4, +0x5c undefined1, +0x7c int | i32 result; on success client re-requests PCLIST | /api/characters (create/delete) (INFERRED) | core (server.mjs) | D+B+O |
| 0x03020004 | C>S |  | B 0x013eeb50 | 104 | +0x0 ptr/copy, +0x2a ptr/copy, +0x55 undefined1 | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. | /api/characters (create/delete) (INFERRED) | S964 ServerTransferWire | D INFERRED |
| 0x03020005 | S>C |  | H 0x013ef180(cmp) | - | - | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020004 (request even / reply odd convention). | /api/characters (create/delete) (INFERRED) |  | D INFERRED |
| 0x03020006 | C>S |  | B 0x013ee9a0 | 60 | - | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. | /api/characters (create/delete) (INFERRED) | S964 ServerTransferWire | D INFERRED |
| 0x03020007 | S>C |  | H 0x013ef180(cmp) | - | - | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020006 (request even / reply odd convention). | /api/characters (create/delete) (INFERRED) |  | D INFERRED |
| 0x03020008 | C>S |  | B 0x013eea40 | 104 | +0x0 undefined2, +0x55 undefined1 | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. | /api/characters (create/delete) (INFERRED) | S964 ServerTransferWire | D INFERRED |
| 0x03020009 | S>C |  | H 0x013ef180(cmp) | - | - | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020008 (request even / reply odd convention). | /api/characters (create/delete) (INFERRED) |  | D INFERRED |
| 0x0302000a | C>S |  | B 0x013eec70 | 104 | +0x0 undefined4, +0x4 undefined2, +0x2e undefined2 | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. | /api/characters (create/delete) (INFERRED) | S964 ServerTransferWire | D INFERRED |
| 0x0302000b | S>C |  | H 0x013ef2d0 | - | +0x0 int | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x0302000a (request even / reply odd convention). | /api/characters (create/delete) (INFERRED) |  | D INFERRED |
| 0x0302000d | S>C |  | H 0x0084b6d0 | - | - | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. | /api/characters (create/delete) (INFERRED) |  | D INFERRED |
| 0x03020016 | C>S |  | B 0x00c28af0 | 60 | - | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. | /api/characters (create/delete) (INFERRED) | S964 ServerTransferWire | D INFERRED |
| 0x03020017 | S>C |  | H 0x0084bd40 | - | +0x8 uint, +0x44 int, +0x48 int, +0x5d byte, +0x7c int | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020016 (request even / reply odd convention). | /api/characters (create/delete) (INFERRED) |  | D INFERRED |
| 0x03020018 | C>S |  | B 0x0084e0b0 | 60 | - | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. | /api/characters (create/delete) (INFERRED) | S964 ServerTransferWire | D INFERRED |
| 0x03020019 | S>C |  | H 0x0084bfa0 | - | +0x8 uint, +0x44 int, +0x48 int, +0x5d byte, +0x7c int | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020018 (request even / reply odd convention). | /api/characters (create/delete) (INFERRED) |  | D INFERRED |

### 0x0400 World server Lock / WaitEnter (9)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x04000000 | C>S | LOCK | B 0x00875b40 | 348 | +0x0 int, +0x4 int, +0x8 int, +0xc undefined1, +0x144 int, +0x148 int | enter game server, size 0x15c: u32 sessionKey@0x10, u32 userNo@0x14, u32 ticket@0x18, userId@0x1c, extra u32 @0x154/@0x158 (Connect::State::Command::Lock) | /api/world/join + /api/world/ready (INFERRED) | core (server.mjs) | D+B+O |
| 0x04000002 | S>C | LOCK_ACK_START | H 0x00876180 | obs 28 | +0x0 undefined4, +0x4 undefined2, +0x6 short | "Rev Lock Start": i32 result@0x10, u8 flags @0x14..0x16 | /api/world/join + /api/world/ready (INFERRED) | core (server.mjs) | D+B+O |
| 0x04000003 | S>C | LOCK_ACK_END | H 0x00876c60 | obs 56 | +0x0 undefined4, +0x4 undefined4, +0x6 ushort | "Rev Lock End": logs worldId/WorldIdx/ChannelIdx; u32 handle@0x10, u8 flag@0x14; needs own PC_OBJECT first | /api/world/join + /api/world/ready (INFERRED) | core (server.mjs) | D+B+O |
| 0x04000006 | C>S | UNLOCK | B 0x00879680 | 16 | - | header only (Connect::State::Command::Unlock) | /api/world/join + /api/world/ready (INFERRED) | core (server.mjs) | D+B+O |
| 0x04000007 | S>C |  | H 0x008797e0(cmp) | - | - | World server Lock / WaitEnter: reply/notification. Game-server lock (enter-world handshake), lock result, unlock, wait/queue notices. Likely reply to C>S 0x04000006 (request even / reply odd convention). | /api/world/join + /api/world/ready (INFERRED) |  | D INFERRED |
| 0x04000008 | S>C | WAIT_NOTICE | H 0x00877f70(cmp); H 0x00878000(cmp) | - | - | queue/wait notice during enter | /api/world/join + /api/world/ready (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x04000015 | S>C | LOCK_0015 | H 0x00876bb0 | - | +0x0 undefined4, +0x4 undefined4 | enter-world dispatcher case | /api/world/join + /api/world/ready (INFERRED) |  | D |
| 0x04000016 | C>S |  | B 0x00bd6bc0 | 448 | +0x0 undefined2, +0x4 ptr/copy | World server Lock / WaitEnter: request. Game-server lock (enter-world handshake), lock result, unlock, wait/queue notices. | /api/world/join + /api/world/ready (INFERRED) | S701 W15 decoded accept-and-log rows | D INFERRED |
| 0x04000017 | S>C |  | H 0x008e78b0(cmp) | - | - | World server Lock / WaitEnter: reply/notification. Game-server lock (enter-world handshake), lock result, unlock, wait/queue notices. Likely reply to C>S 0x04000016 (request even / reply odd convention). | /api/world/join + /api/world/ready (INFERRED) |  | D INFERRED |

### 0x0500 Inventory / CashItem / RandomBox (31)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05000000 | C>S |  | B 0x01262810; B 0x014e9300 | 24 | +0x0 undefined2, +0x2 undefined1, +0x6 undefined1 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S055 Inven authoritative custody | D+O INFERRED |
| 0x05000001 | S>C |  | H 0x01316a20 | obs 18 | +0x0 char, +0x1 char | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000000 (request even / reply odd convention). | itemmove, itemuse, split, beltmove (INFERRED) |  | D+O INFERRED |
| 0x05000002 | C>S |  | B 0x01319de0; B 0x01319f40 | 20 | +0x0 undefined2, +0x2 undefined1 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S055 Inven authoritative custody | D+O INFERRED |
| 0x05000003 | S>C |  | H 0x01316ca0 | obs 17 | +0x0 char | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000002 (request even / reply odd convention). | itemmove, itemuse, split, beltmove (INFERRED) |  | D+O INFERRED |
| 0x05000004 | S>C |  | H 0x01317880 | - | +0x0 ptr, +0x3 undefined4, +0x11 short | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000005 | S>C |  | H 0x01317ae0 | - | +0x0 undefined4, +0x4 undefined4 | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000006 | S>C |  | H 0x01317d70 | obs 24 | +0x0 undefined4, +0x4 undefined4 | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D+O INFERRED |
| 0x05000007 | S>C |  | H 0x01317fb0 | - | +0x0 undefined4, +0x4 undefined4 | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000008 | C>S |  | B 0x013a7c50 | 20 | +0x0 undefined2, +0x2 undefined1 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05000009 | S>C |  | H 0x013a9cf0 | - | +0x0 ptr, +0x3 undefined1 | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000008 (request even / reply odd convention). | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000013 | C>S |  | B 0x013a4860 | 64 | +0x0 undefined2, +0x2 undefined1, +0x4 undefined2 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05000013 rename, size 0x40 (builder 0x16f7f30): +0x00 ref3 item (getter +4/+6), +0x04 UTF-16LE ne… | itemmove, itemuse, split, beltmove (INFERRED) | S019 CashItem | D INFERRED |
| 0x05000014 | S>C |  | H 0x013abf70 | - | +0x0 undefined4, +0x4 ptr | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000013 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S019: S>C 0x05000014 result (dispa… | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000018 | C>S |  | B 0x01407570 | 52 | +0x0 undefined2, +0x2 undefined1, +0x4 undefined2, +0x6 undefined4, +0xa undefined4, +0xe undefined4 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05000018 selection box, size 0x34 (0x175a1b0): +0x00 u16 pos, +0x02 u8 container (box ref), +0x04… | itemmove, itemuse, split, beltmove (INFERRED) | S092 RandomBox | D INFERRED |
| 0x0500001b | C>S |  | B 0x013a43f0 | 20 | +0x0 undefined2, +0x2 undefined1 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0500001c | S>C |  | H 0x013a9e10 | - | +0x0 ptr, +0x3 undefined1 | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x0500001b (request even / reply odd convention). | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x0500001d | S>C |  | H 0x01319160 | - | +0x0 undefined4, +0xe short, +0x40 undefined4, +0x44 undefined4, +0x48 undefined4, +0x4c ptr | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x0500001e | C>S |  | B 0x013f3060 | 20 | +0x0 undefined2, +0x2 undefined1 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0500001f | S>C |  | H 0x01319410 | - | - | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x0500001e (request even / reply odd convention). | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000020 | S>C |  | H 0x013195c0 | - | - | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000023 | C>S |  | B 0x014e6770 | 720 | +0x0 undefined1 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05000024 | S>C |  | H 0x01319660 | - | +0x1 undefined1, +0x2 char | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000023 (request even / reply odd convention). | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000026 | S>C |  | H 0x01318210 | - | +0x4 int | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000027 | C>S |  | B 0x01319fd0 | 16 | - | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S055 Inven authoritative custody | D+O INFERRED |
| 0x05000028 | S>C |  | H 0x01318290 | - | - | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000027 (request even / reply odd convention). | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000029 | C>S |  | B 0x01517f90(factory) | 24 | - | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05000030 | S>C |  | H 0x01316830 | - | +0x0 undefined3, +0x6 short, +0x8 undefined4 | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000031 | C>S |  | B 0x013a6610 | 64 | +0x0 undefined2, +0x2 undefined1, +0x4 undefined2 | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05000033 | C>S |  | B 0x013a8260(factory) | 32 | - | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05000034 | S>C |  | H 0x013a9f50 | - | - | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000033 (request even / reply odd convention). | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000035 | S>C |  | H 0x01319780 | - | +0x0 ptr, +0x3 undefined4, +0x11 short | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |
| 0x05000036 | S>C |  | H 0x013199e0 | - | +0x0 ptr, +0x3 undefined4, +0x11 short | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. | itemmove, itemuse, split, beltmove (INFERRED) |  | D INFERRED |

### 0x0501 Ornament / MainToolBar (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05010000 | C>S |  | B 0x013d5dd0; B 0x012fe7d0(factory) | 20 | +0x0 undefined4 | Ornament / MainToolBar: request. Ornament and toolbar sync. | hotbar (INFERRED) | S965 OrnamentWire | D INFERRED |
| 0x05010001 | S>C |  | H 0x012feaa0 | - | +0x0 int, +0x4 undefined4, +0x8 undefined3 | Ornament / MainToolBar: reply/notification. Ornament and toolbar sync. Likely reply to C>S 0x05010000 (request even / reply odd convention). | hotbar (INFERRED) |  | D INFERRED |

### 0x0502 CashItem / CashShop / game events (16)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05020000 | S>C |  | H 0x008e57d0 | - | +0x0 undefined4, +0x4 ushort, +0x6 ushort, +0x8 byte, +0xc undefined4, +0x14 undefined1 | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. | coinshop (INFERRED) |  | D INFERRED |
| 0x05020001 | C>S |  | B 0x015190f0(factory) | 24 | - | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. | coinshop (INFERRED) | S055 Inven authoritative custody | D+O INFERRED |
| 0x05020002 | S>C |  | H 0x01315df0 | obs 17 | +0x0 undefined1 | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020001 (request even / reply odd convention). | coinshop (INFERRED) |  | D+O INFERRED |
| 0x05020003 | C>S |  | B 0x014f3f40 | 24 | +0x0 int, +0x4 undefined1 | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. | coinshop (INFERRED) | S142 GroundDrops | D INFERRED |
| 0x05020004 | S>C |  | H 0x01315810 | - | +0x40 undefined4, +0x44 undefined4, +0x48 undefined4, +0x4c char, +0x4d undefined1 | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020003 (request even / reply odd convention). | coinshop (INFERRED) |  | D INFERRED |
| 0x05020006 | S>C |  | H 0x01315ff0 | - | +0x0 int, +0x4 undefined1 | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. | coinshop (INFERRED) |  | D INFERRED |
| 0x05020007 | C>S |  | B 0x013e34a0; B 0x01475590 | 16 | - | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. | coinshop (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05020008 | S>C |  | H 0x013ecc90 | - | +0x0 undefined1 | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020007 (request even / reply odd convention). | coinshop (INFERRED) |  | D INFERRED |
| 0x0502000b | C>S |  | B 0x013a7bb0 | 20 | +0x0 undefined2, +0x2 undefined1 | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. | coinshop (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0502000c | S>C |  | H 0x013a96c0 | - | +0x0 ptr, +0x3 char | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x0502000b (request even / reply odd convention). | coinshop (INFERRED) |  | D INFERRED |
| 0x0502000e | C>S |  | B 0x00889720(factory); B 0x013a4630 | 24 | - | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. | coinshop (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0502000f | S>C |  | H 0x013a9940 | - | +0x0 ptr, +0x3 undefined1 | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x0502000e (request even / reply odd convention). | coinshop (INFERRED) |  | D INFERRED |
| 0x05020011 | S>C |  | H 0x013ecea0 | - | - | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. | coinshop (INFERRED) |  | D INFERRED |
| 0x05020012 | S>C |  | H 0x008e78b0(cmp) | - | - | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. | coinshop (INFERRED) |  | D INFERRED |
| 0x05020013 | S>C |  | H 0x008e78b0(cmp) | - | - | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. | coinshop (INFERRED) |  | D INFERRED |
| 0x05020014 | S>C |  | H 0x01315010(cmp) | - | - | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. | coinshop (INFERRED) |  | D INFERRED |

### 0x0503 World enter / creature appear (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05030000 | C>S |  | B 0x01519130 | 32 | +0x0 undefined4, +0x4 undefined2, +0x8 undefined4, +0xc undefined4 | World enter / creature appear: request. Object enter (appear) records. | world snapshot stream (INFERRED) | S950 ChatCommandWire | D INFERRED |
| 0x05030001 | S>C |  | H 0x01316650 | - | +0x0 uint, +0x4 int, +0x8 char | World enter / creature appear: reply/notification. Object enter (appear) records. Likely reply to C>S 0x05030000 (request even / reply odd convention). | world snapshot stream (INFERRED) |  | D INFERRED |
| 0x05030002 | S>C |  | H 0x008e5a30 | - | +0x0 undefined4, +0x4 ushort, +0x6 ushort, +0x8 byte, +0x10 undefined4, +0x14 undefined4 | World enter / creature appear: reply/notification. Object enter (appear) records. | world snapshot stream (INFERRED) |  | D INFERRED |
| 0x05030003 | C>S |  | B 0x015192f0 | 24 | +0x0 undefined1, +0x4 undefined4 | World enter / creature appear: request. Object enter (appear) records. | world snapshot stream (INFERRED) | S950 ChatCommandWire | D INFERRED |
| 0x05030004 | S>C |  | H 0x01316180 | - | +0x0 undefined4, +0x4 undefined4, +0x8 char | World enter / creature appear: reply/notification. Object enter (appear) records. Likely reply to C>S 0x05030003 (request even / reply odd convention). | world snapshot stream (INFERRED) |  | D INFERRED |

### 0x0504 World enter / PC appear (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05040000 | S>C | PC_STATE | H 0x00836790(cmp); H 0x008e5ba0 | obs 448 | - | PC appear/state record (size 448) | world snapshot stream (INFERRED) |  | D+O |

### 0x0505 NPC dialog / Quest (10)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05050000 | both | NPC_OBJECT | B 0x014d1e70(factory); H 0x00836790(cmp); H 0x008e5f80 | 32 | +0x0 undefined4, +0x4 short, +0x6 undefined4, +0xa undefined2 | NPC/object record (size 32) | quest, npcfriends (INFERRED) |  | D+O |
| 0x05050001 | C>S |  | B 0x00866240(factory) | 20 | - | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: TalkNPC 0x05050001 -> 0x05050002 with all npc.csv job slots; choice 0x05050003 -> shop open (job 0/102) or the module cl… | quest, npcfriends (INFERRED) | S069 NPCDialog | D+O INFERRED |
| 0x05050002 | S>C |  | H 0x012dbc10 | obs 42 | - | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050001 (request even / reply odd convention). | quest, npcfriends (INFERRED) |  | D+O INFERRED |
| 0x05050003 | C>S |  | B 0x012dc420(factory); B 0x014e0620 | 24 | - | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: TalkNPC 0x05050001 -> 0x05050002 with all npc.csv job slots; choice 0x05050003 -> shop open (job 0/102) or the module cl… | quest, npcfriends (INFERRED) | S069 NPCDialog | D+O INFERRED |
| 0x05050004 | S>C |  | H 0x012dba50(cmp) | - | - | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050003 (request even / reply odd convention). | quest, npcfriends (INFERRED) |  | D INFERRED |
| 0x05050005 | C>S |  | B 0x008c19d0; B 0x008dec90 | 20 | +0x0 undefined4 | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. | quest, npcfriends (INFERRED) | S980 wire-W11-npc | D+O INFERRED |
| 0x05050006 | S>C |  | H 0x008c1a70(cmp) | - | - | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050005 (request even / reply odd convention). | quest, npcfriends (INFERRED) |  | D INFERRED |
| 0x05050007 | C>S |  | B 0x014e03a0; B 0x014e0690 | 16 | - | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: TalkNPC 0x05050001 -> 0x05050002 with all npc.csv job slots; choice 0x05050003 -> shop open (job 0/102) or the module cl… | quest, npcfriends (INFERRED) | S069 NPCDialog | D INFERRED |
| 0x05050008 | S>C |  | H 0x012dba50(cmp) | obs 16 | - | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050007 (request even / reply odd convention). | quest, npcfriends (INFERRED) |  | D+O INFERRED |
| 0x05050010 | S>C |  | H 0x008e2c20(cmp) | - | - | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. | quest, npcfriends (INFERRED) |  | D INFERRED |

### 0x0506 AutoHunt / GrowBless / Dekaron provider / DKSquare entry (49)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05060001 | S>C |  | H 0x012fa560 | - | +0x0 char | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060006 | S>C |  | H 0x008e2c20(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060007 | C>S |  | B 0x00b3bf80 | 16 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D+O INFERRED |
| 0x05060008 | S>C |  | H 0x00885430 | obs 44 | +0x0 char, +0x14 undefined4, +0x18 undefined2 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060007 (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D+O INFERRED |
| 0x05060009 | S>C |  | H 0x012ae4e0(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506000a | S>C |  | H 0x012e4fb0(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506000b | C>S |  | B 0x0127bc30; B 0x0127bd00 | 20 | +0x0 byte | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0506000c | S>C |  | H 0x01365a40 | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000b (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506000d | C>S |  | B 0x01365e90 | 16 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0506000e | S>C |  | H 0x01365ad0 | - | +0x8 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000d (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506000f | C>S |  | B 0x013a7ed0 | 20 | +0x0 undefined2, +0x2 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05060010 | S>C |  | H 0x013a9470 | - | +0x0 ptr, +0x3 undefined1, +0x4 char | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000f (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060011 | C>S |  | B 0x01364f60 | 24 | +0x0 short, +0x2 short, +0x4 short, +0x6 short | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05060011 (sender 0x16b8740, size 0x18; takes request lock 2 via … | hunt, dksquare (INFERRED) | S077 PCInfo | D INFERRED |
| 0x05060012 | S>C |  | H 0x01365950(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060011 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S… | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060013 | C>S |  | B 0x013a4320 | 24 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05060014 | S>C |  | H 0x013a9570 | - | +0x0 ptr, +0x8 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060013 (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060016 | S>C |  | H 0x01365950(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060017 | C>S |  | B 0x00b3bf80 | 16 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05060018 | S>C |  | H 0x008855f0 | - | +0x0 char, +0x2 undefined4, +0x6 undefined2, +0x8 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060017 (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060019 | S>C |  | H 0x01365950(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506001a | S>C |  | H 0x01365950(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506001b | C>S |  | B 0x0132b640; B 0x00b3c100(factory) | 20 | +0x0 short, +0x2 short | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0506001c | S>C |  | H 0x01329830(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506001b (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506001d | C>S |  | B 0x008df6e0 | 16 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0506001e | S>C |  | H 0x008e13a0 | - | +0x0 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506001d (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506001f | C>S |  | B 0x00b3c130(factory) | 20 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05060020 | S>C |  | H 0x008e1330 | - | +0x0 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506001f (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060023 | S>C |  | H 0x0145d920(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060024 | C>S |  | B 0x0132a910 | 20 | +0x0 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05060025 | S>C |  | H 0x01329830(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060024 (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060026 | C>S |  | B 0x014635b0; B 0x014d1bd0 | 20 | +0x0 undefined4 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05060027 | S>C |  | H 0x01462d20(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060026 (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060029 | C>S |  | B 0x01466320 | 20 | +0x0 undefined2 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05060030 | S>C |  | H 0x01465e40(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060031 | S>C |  | H 0x01366000 | - | +0x8 undefined4 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060032 | S>C |  | H 0x014428d0(cmp) | obs 18 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): S013: S>C 0x05060032 (0x17953d0): u16 stamina @+0 | hunt, dksquare (INFERRED) |  | D+O INFERRED |
| 0x05060033 | S>C |  | H 0x014428d0(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060034 | C>S |  | B 0x014427d0 | 20 | +0x0 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05060034 empty (0x1795270 / 0x1795620) = enable  -> S>C 0x050600… | hunt, dksquare (INFERRED) | S013 AutoHunt | D INFERRED |
| 0x05060035 | S>C |  | H 0x014428d0(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060034 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S… | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060036 | C>S |  | B 0x01442850 | 16 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05060036 empty (0x17952e0 / 0x1795650) = disable -> S>C 0x050600… | hunt, dksquare (INFERRED) | S013 AutoHunt | D INFERRED |
| 0x05060037 | S>C |  | H 0x014428d0(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060036 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S… | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060038 | C>S |  | B 0x0129d0f0 | 16 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05060039 | S>C |  | H 0x01367780(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060038 (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x0506003a | C>S |  | B 0x0129d8a0(factory); B 0x0129b030 | 16 | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0506003e | C>S |  | B 0x007aa9b0 | 872 | +0x0 ptr/copy, +0x354 byte | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x0506003f | C>S |  | B 0x007a6530 | 20 | +0x0 undefined1 | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) | S902 wire-W02-misc | D+O INFERRED |
| 0x05060040 | S>C |  | H 0x008e2c20(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506003f (request even / reply odd convention). | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060041 | S>C |  | H 0x01365950(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |
| 0x05060042 | S>C |  | H 0x01365950(cmp) | - | - | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. | hunt, dksquare (INFERRED) |  | D INFERRED |

### 0x0507 PC state (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05070000 | S>C |  | H 0x00836790(cmp); H 0x008e1270(cmp) | - | - | PC state: reply/notification. PC state event. | MISSING |  | D INFERRED |

### 0x0508 Creature/PC state (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05080000 | S>C |  | H 0x00836790(cmp); H 0x008e1430 | - | - | Creature/PC state: reply/notification. Creature/PC state events. | world snapshot stream (INFERRED) |  | D INFERRED |
| 0x05080001 | S>C |  | H 0x008e2c20(cmp) | - | - | Creature/PC state: reply/notification. Creature/PC state events. | world snapshot stream (INFERRED) |  | D INFERRED |
| 0x05080003 | S>C |  | H 0x008e2c20(cmp) | - | - | Creature/PC state: reply/notification. Creature/PC state events. | world snapshot stream (INFERRED) |  | D INFERRED |

### 0x0509 PK / Chaotic (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05090000 | S>C |  | H 0x00836790(cmp); H 0x008e1270(cmp) | - | - | PK / Chaotic: reply/notification. PK mode and chaotic timer. | pvp (INFERRED) |  | D INFERRED |
| 0x0509000a | C>S |  | B 0x008ccb30 | 16 | - | PK / Chaotic: request. PK mode and chaotic timer. | pvp (INFERRED) | S701 W15 decoded accept-and-log rows | D INFERRED |
| 0x0509000b | C>S |  | B 0x008ccc50 | 16 | - | PK / Chaotic: request. PK mode and chaotic timer. | pvp (INFERRED) | S701 W15 decoded accept-and-log rows | D INFERRED |
| 0x0509000c | S>C |  | H 0x0139d580(cmp) | - | - | PK / Chaotic: reply/notification. PK mode and chaotic timer. Likely reply to C>S 0x0509000b (request even / reply odd convention). | pvp (INFERRED) |  | D INFERRED |

### 0x050a NPC Shop (17)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x050a0000 | S>C |  | H 0x013233a0 | obs 23 | +0x0 int, +0x4 short, +0x6 char | NPC Shop: reply/notification. NPC shop buy/sell/repair. | shopbuy, shopsell (INFERRED) |  | D+O INFERRED |
| 0x050a0001 | C>S |  | B 0x013223f0 | 28 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined2, +0x8 undefined1, +0x9 undefined1 | NPC Shop: request. NPC shop buy/sell/repair. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: open 0x050a0000 (sent by S069 on a SHOP/MULTISHOP job), buy 0x050a0001 -> 0x050a0002, bulk buy 0x050a0009 -> 0x050a0002 path, | shopbuy, shopsell (INFERRED) | S097 Shop | D+O INFERRED |
| 0x050a0002 | S>C |  | H 0x013237e0 | obs 96 | +0x0 undefined4, +0x4 undefined4, +0x8 char, +0x9 byte, +0x48 uint, +0x4c undefined4 | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0001 (request even / reply odd convention). | shopbuy, shopsell (INFERRED) |  | D+O INFERRED |
| 0x050a0003 | C>S |  | B 0x01322660 | 24 | +0x0 undefined4, +0x4 undefined2 | NPC Shop: request. NPC shop buy/sell/repair. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: sell 0x050a0003 (sells the client's cursor item, tracked by S055) -> 0x050a0004. | shopbuy, shopsell (INFERRED) | S097 Shop | D+O INFERRED |
| 0x050a0004 | S>C |  | H 0x013243e0 | obs 20 | +0x0 undefined4 | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0003 (request even / reply odd convention). | shopbuy, shopsell (INFERRED) |  | D+O INFERRED |
| 0x050a0005 | C>S |  | B 0x01322700 | 28 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined2, +0x8 undefined1 | NPC Shop: request. NPC shop buy/sell/repair. | shopbuy, shopsell (INFERRED) | S982 wire-W11-shop-ext | D INFERRED |
| 0x050a0006 | S>C |  | H 0x01324720 | - | +0x0 undefined4, +0x4 ptr | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0005 (request even / reply odd convention). | shopbuy, shopsell (INFERRED) |  | D INFERRED |
| 0x050a0007 | C>S |  | B 0x013227b0 | 16 | - | NPC Shop: request. NPC shop buy/sell/repair. | shopbuy, shopsell (INFERRED) | S982 wire-W11-shop-ext | D INFERRED |
| 0x050a0008 | S>C |  | H 0x01324980 | - | - | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0007 (request even / reply odd convention). | shopbuy, shopsell (INFERRED) |  | D INFERRED |
| 0x050a0009 | C>S |  | B 0x013224b0 | 28 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined2, +0x8 undefined1, +0xa short | NPC Shop: request. NPC shop buy/sell/repair. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: open 0x050a0000 (sent by S069 on a SHOP/MULTISHOP job), buy 0x050a0001 -> 0x050a0002, bulk buy 0x050a0009 -> 0x050a0002 path, | shopbuy, shopsell (INFERRED) | S097 Shop | D INFERRED |
| 0x050a000a | S>C |  | H 0x01323f00 | - | +0x0 undefined4, +0x4 undefined4, +0x8 char, +0x9 char, +0x48 short, +0x4c uint | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a0009 (request even / reply odd convention). | shopbuy, shopsell (INFERRED) |  | D INFERRED |
| 0x050a000b | C>S |  | B 0x01322320 | 32 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1, +0x8 undefined2, +0xc undefined4 | NPC Shop: request. NPC shop buy/sell/repair. | shopbuy, shopsell (INFERRED) | S982 wire-W11-shop-ext | D INFERRED |
| 0x050a000c | S>C |  | H 0x01323c10 | - | +0x0 char, +0x40 undefined4, +0x44 undefined4, +0x48 char, +0x4c int, +0x50 short | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a000b (request even / reply odd convention). | shopbuy, shopsell (INFERRED) |  | D INFERRED |
| 0x050a000d | S>C |  | H 0x013236b0 | - | +0x0 undefined4, +0x4 undefined2, +0x6 char | NPC Shop: reply/notification. NPC shop buy/sell/repair. | shopbuy, shopsell (INFERRED) |  | D INFERRED |
| 0x050a000e | C>S |  | B 0x01322580 | 28 | +0x0 undefined4, +0x4 uint | NPC Shop: request. NPC shop buy/sell/repair. | shopbuy, shopsell (INFERRED) | S982 wire-W11-shop-ext | D INFERRED |
| 0x050a000f | S>C |  | H 0x013250d0 | - | - | NPC Shop: reply/notification. NPC shop buy/sell/repair. Likely reply to C>S 0x050a000e (request even / reply odd convention). | shopbuy, shopsell (INFERRED) |  | D INFERRED |
| 0x050a0010 | C>S |  | B 0x00ca04b0(factory); B 0x014d19c0 | 16 | - | NPC Shop: request. NPC shop buy/sell/repair. | shopbuy, shopsell (INFERRED) | S982 wire-W11-shop-ext | D INFERRED |

### 0x050b Storage (warehouse) (19)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x050b0000 | S>C |  | H 0x0131f7c0 | obs 16 | - | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) |  | D+O INFERRED |
| 0x050b0001 | C>S |  | B 0x0131dd50 | 20 | +0x0 undefined2, +0x2 undefined1 | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) | S105 Storage | D+O INFERRED |
| 0x050b0002 | S>C |  | H 0x0131f7f0 | obs 17 | +0x0 char | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0001 (request even / reply odd convention). | storage, stashmove, bank (INFERRED) |  | D+O INFERRED |
| 0x050b0003 | C>S |  | B 0x0131e030 | 24 | +0x0 undefined4, +0x4 undefined4 | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) | S105 Storage | D+O INFERRED |
| 0x050b0004 | S>C |  | H 0x013202e0 | obs 17 | +0x0 char | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0003 (request even / reply odd convention). | storage, stashmove, bank (INFERRED) |  | D+O INFERRED |
| 0x050b0005 | C>S |  | B 0x0131e1c0 | 24 | +0x0 undefined4, +0x4 undefined4 | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) | S105 Storage | D+O INFERRED |
| 0x050b0006 | S>C |  | H 0x01320180 | obs 17 | +0x0 char | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0005 (request even / reply odd convention). | storage, stashmove, bank (INFERRED) |  | D+O INFERRED |
| 0x050b0007 | C>S |  | B 0x0131e240 | 16 | - | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) | S105 Storage | D+O INFERRED |
| 0x050b0008 | S>C |  | H 0x01320460 | obs 16 | - | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0007 (request even / reply odd convention). | storage, stashmove, bank (INFERRED) |  | D+O INFERRED |
| 0x050b0009 | C>S |  | B 0x013a7cf0 | 20 | +0x0 undefined2, +0x2 undefined1 | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) | S105 StorageHandoff | D INFERRED |
| 0x050b0010 | S>C |  | H 0x013abcb0 | - | +0x0 ptr, +0x3 undefined1 | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) |  | D INFERRED |
| 0x050b0011 | C>S |  | B 0x0131dde0 | 20 | +0x0 undefined2, +0x2 undefined1 | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) | S105 Storage | D INFERRED |
| 0x050b0012 | S>C |  | H 0x0131fca0 | - | +0x0 char | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0011 (request even / reply odd convention). | storage, stashmove, bank (INFERRED) |  | D INFERRED |
| 0x050b0013 | C>S |  | B 0x013a7d90 | 20 | +0x0 undefined2, +0x2 undefined1 | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) | S105 StorageHandoff | D INFERRED |
| 0x050b0014 | S>C |  | H 0x013abe20 | - | +0x0 ptr, +0x3 undefined1 | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0013 (request even / reply odd convention). | storage, stashmove, bank (INFERRED) |  | D INFERRED |
| 0x050b0015 | C>S |  | B 0x0131cf40 | 820 | +0x0 undefined1 | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) |  | D INFERRED |
| 0x050b0016 | S>C |  | H 0x01320bd0 | - | +0x0 undefined1, +0x1 char | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0015 (request even / reply odd convention). | storage, stashmove, bank (INFERRED) |  | D INFERRED |
| 0x050b0017 | C>S |  | B 0x0131d670 | 220 | +0x0 undefined1 | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. | storage, stashmove, bank (INFERRED) |  | D INFERRED |
| 0x050b0018 | S>C |  | H 0x01320cd0 | - | +0x0 undefined1, +0x1 char | Storage (warehouse): reply/notification. Warehouse open/deposit/withdraw/dil. Likely reply to C>S 0x050b0017 (request even / reply odd convention). | storage, stashmove, bank (INFERRED) |  | D INFERRED |

### 0x050c PVP / DKSquare options (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x050c0000 | C>S |  | B 0x01264d80(factory) | 20 | - | PVP / DKSquare options: request. PVP/arena option toggles. | pvp, dksquare (INFERRED) | S701 W15 decoded accept-and-log rows | D+O INFERRED |
| 0x050c0001 | S>C |  | H 0x01318330 | - | +0x0 char | PVP / DKSquare options: reply/notification. PVP/arena option toggles. Likely reply to C>S 0x050c0000 (request even / reply odd convention). | pvp, dksquare (INFERRED) |  | D INFERRED |
| 0x050c0031 | C>S |  | B 0x007a6420 | 20 | +0x0 undefined1 | PVP / DKSquare options: request. PVP/arena option toggles. | pvp, dksquare (INFERRED) | S988 wire-W12-dksquare-flags | D+O INFERRED |
| 0x050c0032 | S>C |  | H 0x013184d0 | - | +0x0 int, +0x4 undefined1 | PVP / DKSquare options: reply/notification. PVP/arena option toggles. Likely reply to C>S 0x050c0031 (request even / reply odd convention). | pvp, dksquare (INFERRED) |  | D INFERRED |
| 0x050c0036 | C>S |  | B 0x007a64a0 | 20 | +0x0 undefined1 | PVP / DKSquare options: request. PVP/arena option toggles. | pvp, dksquare (INFERRED) | S988 wire-W12-dksquare-flags | D+O INFERRED |
| 0x050c0037 | S>C |  | H 0x01318560 | - | +0x0 int, +0x4 undefined1 | PVP / DKSquare options: reply/notification. PVP/arena option toggles. Likely reply to C>S 0x050c0036 (request even / reply odd convention). | pvp, dksquare (INFERRED) |  | D INFERRED |

### 0x050d Movement / Chat / Enter world (15)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x050d0010 | both | MOVE | B 0x00862d60; B 0x00864b60; H 0x008e78b0(cmp) | 52 | +0x0 undefined4 | movement (size 52), highest-volume op | move, emote, megaphone (INFERRED) | core (server.mjs) | D+B+O |
| 0x050d0011 | C>S |  | B 0x008b70b0 | 20 | +0x0 undefined2 | Movement / Chat / Enter world: request. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) |  | D+O INFERRED |
| 0x050d0012 | C>S |  | B 0x008f2f40; B 0x009010c0 | 24 | +0x0 undefined4, +0x4 short | Movement / Chat / Enter world: request. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) | S949 ChatSceneWire | D INFERRED |
| 0x050d0013 | both |  | B 0x012f4dd0; H 0x012f94d0 | 52,96,112,132,560,668 | +0x0 undefined4, +0x8 undefined4, +0x2c undefined1, +0x30 undefined4, +0x204 undefined4 | Movement / Chat / Enter world: request and reply share this opcode. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x050d0013 (sender 0x1649819, base size 0x34 + text)… | move, emote, megaphone (INFERRED) | S024 Chat | D+O INFERRED |
| 0x050d0014 | S>C |  | H 0x008e2040(cmp) | - | - | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). Likely reply to C>S 0x050d0013 (request even / reply odd convention). | move, emote, megaphone (INFERRED) |  | D INFERRED |
| 0x050d0015 | both |  | B 0x014d2a90(factory); H 0x008e78b0(cmp) | 20 | +0x0 undefined4 | Movement / Chat / Enter world: request and reply share this opcode. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) | S949 ChatSceneWire | D+O INFERRED |
| 0x050d0016 | both |  | B 0x012f55b0; H 0x012f9750 | 92 | +0x16 undefined1, +0x44 undefined4 | Movement / Chat / Enter world: request and reply share this opcode. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) | S949 ChatSceneWire | D INFERRED |
| 0x050d0017 | S>C | ENTER_WORLD (WAITENTER) | H 0x00877f70(cmp); H 0x00878000(cmp) | obs 24 | - | WaitEnter state waits for this; handler logs u16@0x10; client then sends ENTER_DONE | move, emote, megaphone (INFERRED) | core (server.mjs) | D+B+O INFERRED |
| 0x050d0018 | S>C |  | H 0x008e2040(cmp) | - | - | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) |  | D INFERRED |
| 0x050d0019 | S>C |  | H 0x012f8ec0 | - | +0x0 short, +0x42 short, +0x84 uint, +0x88 char, +0x8c undefined2 | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) |  | D INFERRED |
| 0x050d001a | S>C |  | H 0x008e78b0(cmp) | - | - | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) |  | D INFERRED |
| 0x050d001b | C>S |  | B 0x00857d50 | 272 | +0x0 undefined1 | Movement / Chat / Enter world: request. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) | S949 ChatSceneWire | D+O INFERRED |
| 0x050d001c | S>C |  | H 0x012f8ec0 | - | +0x0 short, +0x42 short, +0x84 uint, +0x88 char, +0x8c undefined2 | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). Likely reply to C>S 0x050d001b (request even / reply odd convention). | move, emote, megaphone (INFERRED) |  | D INFERRED |
| 0x050d001d | S>C |  | H 0x012f9130 | - | +0x0 undefined4 | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) |  | D INFERRED |
| 0x050d001e | S>C |  | H 0x012fb230 | - | +0x0 undefined4, +0x4 char | Movement / Chat / Enter world: reply/notification. Movement (0x050d0010), chat, enter-world complete (0x050d0017 WAITENTER). | move, emote, megaphone (INFERRED) |  | D INFERRED |

### 0x050e Trade (21)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x050e0000 | both |  | B 0x00867100; H 0x0132f5a0 | 68 | +0x0 undefined4, +0x4 undefined4, +0x8 ptr/copy | Trade: request and reply share this opcode. Player-to-player trade. | trade (INFERRED) | S971 TradeWire | D INFERRED |
| 0x050e0001 | S>C |  | H 0x0132e770 | - | +0x0 undefined4 | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0000 (request even / reply odd convention). | trade (INFERRED) |  | D INFERRED |
| 0x050e0002 | C>S |  | B 0x0132e230(factory); B 0x0132f5a0 | 20 | - | Trade: request. Player-to-player trade. | trade (INFERRED) | S971 TradeWire | D INFERRED |
| 0x050e0003 | S>C |  | H 0x0132e890 | - | - | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0002 (request even / reply odd convention). | trade (INFERRED) |  | D INFERRED |
| 0x050e0004 | S>C |  | H 0x0132ed30 | - | +0x0 int, +0x4 undefined4 | Trade: reply/notification. Player-to-player trade. | trade (INFERRED) |  | D INFERRED |
| 0x050e0005 | C>S |  | B 0x0132e1a0(factory); B 0x0132dc00 | 16 | - | Trade: request. Player-to-player trade. | trade (INFERRED) | S971 TradeWire | D INFERRED |
| 0x050e0006 | C>S |  | B 0x0132dd80 | 20 | +0x0 undefined2, +0x2 undefined1 | Trade: request. Player-to-player trade. | trade (INFERRED) | S971 TradeWire | D INFERRED |
| 0x050e0007 | S>C |  | H 0x0132ee80 | - | - | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0006 (request even / reply odd convention). | trade (INFERRED) |  | D INFERRED |
| 0x050e0008 | C>S |  | B 0x0132dc70 | 24 | +0x0 undefined4, +0x4 undefined4 | Trade: request. Player-to-player trade. | trade (INFERRED) | S971 TradeWire | D INFERRED |
| 0x050e0009 | S>C |  | H 0x0132ef30 | - | - | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0008 (request even / reply odd convention). | trade (INFERRED) |  | D INFERRED |
| 0x050e000b | S>C |  | H 0x0132f0c0 | - | - | Trade: reply/notification. Player-to-player trade. | trade (INFERRED) |  | D INFERRED |
| 0x050e000c | C>S |  | B 0x0132db20 | 20 | +0x0 undefined1 | Trade: request. Player-to-player trade. | trade (INFERRED) | S971 TradeWire | D INFERRED |
| 0x050e000d | S>C |  | H 0x0132f180 | - | - | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e000c (request even / reply odd convention). | trade (INFERRED) |  | D INFERRED |
| 0x050e000e | S>C |  | H 0x0132f1c0 | - | +0x0 char | Trade: reply/notification. Player-to-player trade. | trade (INFERRED) |  | D INFERRED |
| 0x050e0011 | C>S |  | B 0x014e8e60(factory) | 20 | - | Trade: request. Player-to-player trade. | trade (INFERRED) | S971 TradeWire | D INFERRED |
| 0x050e0012 | S>C |  | H 0x01315470 | - | +0x0 undefined1 | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0011 (request even / reply odd convention). | trade (INFERRED) |  | D INFERRED |
| 0x050e0013 | C>S |  | B 0x0132db90 | 20 | +0x0 undefined1 | Trade: request. Player-to-player trade. | trade (INFERRED) | S971 TradeWire | D INFERRED |
| 0x050e0014 | S>C |  | H 0x0132f1f0 | - | +0x0 char | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0013 (request even / reply odd convention). | trade (INFERRED) |  | D INFERRED |
| 0x050e0015 | S>C |  | H 0x0132f300 | - | +0x0 char | Trade: reply/notification. Player-to-player trade. | trade (INFERRED) |  | D INFERRED |
| 0x050e0016 | S>C |  | H 0x0132f3a0 | - | - | Trade: reply/notification. Player-to-player trade. | trade (INFERRED) |  | D INFERRED |
| 0x050e0017 | S>C |  | H 0x0132f4b0 | - | - | Trade: reply/notification. Player-to-player trade. | trade (INFERRED) |  | D INFERRED |

### 0x050f Tutorial / Quest (22)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x050f0000 | C>S |  | B 0x012c8320 | 20 | +0x0 undefined2 | Tutorial / Quest: request. Tutorial renew and quest progress. | quest (INFERRED) | S904 Quest abandon wire (W04) | D INFERRED |
| 0x050f0001 | S>C |  | H 0x012c9b20 | - | +0x0 undefined2, +0x2 char | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0000 (request even / reply odd convention). | quest (INFERRED) |  | D INFERRED |
| 0x050f0002 | S>C |  | H 0x012c9cf0 | obs 18 | +0x0 short | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D+O INFERRED |
| 0x050f0003 | S>C |  | H 0x012c9e00 | obs 21 | +0x0 undefined2, +0x2 undefined2 | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D+O INFERRED |
| 0x050f0004 | S>C |  | H 0x012c9e70 | - | +0x0 undefined2 | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f0005 | S>C |  | H 0x012c9ec0 | obs 18 | +0x0 undefined2 | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D+O INFERRED |
| 0x050f0006 | S>C |  | H 0x012dda90(cmp) | - | - | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f0007 | S>C |  | H 0x012dda90(cmp) | obs 24 | - | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D+O INFERRED |
| 0x050f0008 | C>S |  | B 0x014e02a0 | 24 | +0x0 int, +0x4 short, +0x6 short | Tutorial / Quest: request. Tutorial renew and quest progress. | quest (INFERRED) | S091 Authored quest dialog | D+O INFERRED |
| 0x050f0009 | S>C |  | H 0x012c9fd0 | obs 18 | +0x0 undefined2 | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0008 (request even / reply odd convention). | quest (INFERRED) |  | D+O INFERRED |
| 0x050f000a | S>C |  | H 0x012ca060 | - | - | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f0010 | S>C |  | H 0x012c9be0 | - | +0x0 undefined2, +0x2 undefined2 | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f0011 | S>C |  | H 0x012ca030 | - | +0x2 undefined1 | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f0012 | both |  | B 0x014dba60; B 0x0144cfd0; H 0x012ca6d0 | 20 | +0x0 short | Tutorial / Quest: request and reply share this opcode. Tutorial renew and quest progress. | quest (INFERRED) | S904 Tutorial progress (W04) | D+O INFERRED |
| 0x050f0013 | C>S |  | B 0x0144db50 | 16 | - | Tutorial / Quest: request. Tutorial renew and quest progress. | quest (INFERRED) | S904 Tutorial progress (W04) | D INFERRED |
| 0x050f0014 | S>C |  | H 0x012ca690 | - | +0x0 ushort | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0013 (request even / reply odd convention). | quest (INFERRED) |  | D INFERRED |
| 0x050f0015 | S>C |  | H 0x012de020 | - | - | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f0016 | S>C |  | H 0x012ca090 | - | - | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f0017 | C>S |  | B 0x00866210(factory) | 16 | - | Tutorial / Quest: request. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f0018 | S>C |  | H 0x012ca230 | - | - | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0017 (request even / reply odd convention). | quest (INFERRED) |  | D INFERRED |
| 0x050f0019 | C>S |  | B 0x014cad00 | 16 | - | Tutorial / Quest: request. Tutorial renew and quest progress. | quest (INFERRED) |  | D INFERRED |
| 0x050f001a | S>C |  | H 0x012ca480 | - | - | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. Likely reply to C>S 0x050f0019 (request even / reply odd convention). | quest (INFERRED) |  | D INFERRED |

### 0x0512 Attack (assault/fly) (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05120002 | C>S |  | B 0x008feb40 | 20 | +0x0 undefined4 | Attack (assault/fly): request. Special attack moves. | attack (INFERRED) | S957 GameUserWire | D INFERRED |
| 0x05120003 | C>S |  | B 0x008de0e0; B 0x008f3e30 | 20 | +0x0 undefined4 | Attack (assault/fly): request. Special attack moves. | attack (INFERRED) | S957 GameUserWire | D INFERRED |

### 0x0515 Skill (24)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05150001 | S>C |  | H 0x01329830(cmp) | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150002 | C>S |  | B 0x0132a7e0 | 20 | +0x0 undefined2, +0x2 undefined1 | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S099 Skill learning and cast intent | D INFERRED |
| 0x05150003 | S>C |  | H 0x01329830(cmp) | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150002 (request even / reply odd convention). | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150004 | C>S |  | B 0x012fe420 | 20,24 | +0x0 undefined1, +0x1 undefined1, +0x4 undefined1, +0x5 undefined1 | Skill: request. Skill learn/use/reinforce, toolbar skills. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05150004 size 0x18: u32 id @0x10 (obj vf+0x18 -> vf+0x10 -> [0]), u8 a2 @0x14, u8 a3 @0x15   (register) | cast, learn, quickslots (INFERRED) | S063 MainToolBar | D INFERRED |
| 0x05150005 | S>C |  | H 0x00740450 | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150004 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S063: S>C 0x05150005 / 0x05150007 (Skill switch 0x167d1e8 -> 0x167d6d0… | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150006 | C>S |  | B 0x012fe420 | 20,24 | +0x0 undefined1, +0x1 undefined1, +0x4 undefined1, +0x5 undefined1 | Skill: request. Skill learn/use/reinforce, toolbar skills. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05150006 size 0x14: u8 a2 @0x10, u8 a3 @0x11                                                (clear, obj == null) | cast, learn, quickslots (INFERRED) | S063 MainToolBar | D INFERRED |
| 0x05150007 | S>C |  | H 0x00740450 | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150006 (request even / reply odd convention). | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150008 | C>S |  | B 0x0132a5e0 | 36 | +0x0 ushort, +0x2 undefined1, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined2 | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S099 Skill learning and cast intent | D+O INFERRED |
| 0x05150009 | S>C |  | H 0x01329830(cmp) | obs 18 | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150008 (request even / reply odd convention). | cast, learn, quickslots (INFERRED) |  | D+O INFERRED |
| 0x0515000a | C>S |  | B 0x0132a670 | 40 | +0x0 ushort, +0x2 undefined1, +0x4 undefined1, +0x5 undefined1, +0x6 undefined1, +0x8 undefined4 | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S958 SkillWire | D INFERRED |
| 0x0515000b | C>S |  | B 0x0132a750 | 36 | +0x0 ushort, +0x2 undefined1, +0x4 undefined1, +0x5 undefined1, +0x8 undefined4, +0xc undefined4 | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S958 SkillWire | D INFERRED |
| 0x0515000d | S>C |  | H 0x0077b9d0 | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x0515000e | S>C |  | H 0x01329830(cmp) | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x0515000f | C>S |  | B 0x0132a840 | 20 | +0x0 undefined1 | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S958 SkillWire | D INFERRED |
| 0x05150010 | S>C |  | H 0x01082450 | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x0515000f (request even / reply odd convention). | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150011 | C>S |  | B 0x0132a8a0 | 20 | +0x0 ushort, +0x2 undefined1 | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S958 SkillWire | D INFERRED |
| 0x05150012 | S>C |  | H 0x01329830(cmp) | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150011 (request even / reply odd convention). | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150013 | S>C |  | H 0x01329830(cmp) | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150014 | C>S |  | B 0x00893bb0; B 0x008941c0 | 20 | +0x0 undefined4 | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S958 SkillWire | D INFERRED |
| 0x05150015 | C>S |  | B 0x0145d810 | 32 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined2, +0x8 undefined1, +0x9 undefined2, +0xb undefined1 | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S959 SkillReinforceWire | D INFERRED |
| 0x05150016 | S>C |  | H 0x0145d920(cmp) | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150015 (request even / reply odd convention). | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150017 | S>C |  | H 0x0145d920(cmp) | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) |  | D INFERRED |
| 0x05150018 | C>S |  | B 0x0145d7c0 | 16 | - | Skill: request. Skill learn/use/reinforce, toolbar skills. | cast, learn, quickslots (INFERRED) | S959 SkillReinforceWire | D INFERRED |
| 0x05150019 | S>C |  | H 0x0145d920(cmp) | - | - | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150018 (request even / reply odd convention). | cast, learn, quickslots (INFERRED) |  | D INFERRED |

### 0x0516 Creature event (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05160000 | C>S |  | B 0x008f1070(factory) | 20 | - | Creature event: request. Creature event. | MISSING | S947 wire-W06-unattributed | D INFERRED |
| 0x05160001 | S>C |  | H 0x008e2c20(cmp) | - | - | Creature event: reply/notification. Creature event. Likely reply to C>S 0x05160000 (request even / reply odd convention). | MISSING |  | D INFERRED |

### 0x0517 NPC teleport (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05170000 | S>C |  | H 0x012e03e0(cmp); H 0x012e0440(cmp) | - | - | NPC teleport: reply/notification. NPC teleport. | mapnpcwarp (INFERRED) |  | D INFERRED |
| 0x05170001 | C>S |  | B 0x014e08c0 | 24 | +0x0 undefined2, +0x2 undefined2, +0x4 undefined2 | NPC teleport: request. NPC teleport. | mapnpcwarp (INFERRED) | S935 wire-W05-npcdialog | D INFERRED |
| 0x05170002 | S>C |  | H 0x012e03e0(cmp); H 0x012e0440(cmp) | - | - | NPC teleport: reply/notification. NPC teleport. Likely reply to C>S 0x05170001 (request even / reply odd convention). | mapnpcwarp (INFERRED) |  | D INFERRED |

### 0x0518 Status (8)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0518000a | S>C |  | H 0x013678b0 | obs 28 | +0x0 undefined2, +0x4 int, +0x8 int | Status: reply/notification. Stat points and status updates. | pointreset (INFERRED) |  | D+O INFERRED |
| 0x0518000b | S>C |  | H 0x013679e0 | - | +0x0 int, +0x4 undefined2 | Status: reply/notification. Stat points and status updates. | pointreset (INFERRED) |  | D INFERRED |
| 0x0518000c | S>C |  | H 0x01367b30 | - | +0x0 int, +0x4 undefined2 | Status: reply/notification. Stat points and status updates. | pointreset (INFERRED) |  | D INFERRED |
| 0x0518000f | S>C |  | H 0x0146c370(cmp) | - | - | Status: reply/notification. Stat points and status updates. | pointreset (INFERRED) |  | D INFERRED |
| 0x05180010 | S>C |  | H 0x0146c370(cmp) | - | - | Status: reply/notification. Stat points and status updates. | pointreset (INFERRED) |  | D INFERRED |
| 0x05180011 | C>S |  | B 0x00a9f410(factory) | 20 | - | Status: request. Stat points and status updates. | pointreset (INFERRED) | S966 StatusWire | D INFERRED |
| 0x05180012 | S>C |  | H 0x0146c370(cmp) | - | - | Status: reply/notification. Stat points and status updates. Likely reply to C>S 0x05180011 (request even / reply odd convention). | pointreset (INFERRED) |  | D INFERRED |
| 0x05180013 | C>S |  | B 0x00ac1dc0(factory) | 16 | - | Status: request. Stat points and status updates. | pointreset (INFERRED) | S966 StatusWire | D INFERRED |

### 0x0519 Servant / effects (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05190000 | both |  | B 0x014d20a0(factory); H 0x00836790(cmp); H 0x008e67a0 | 440 | +0x0 undefined4, +0x4 undefined4, +0x8 short, +0xc undefined4, +0x10 undefined4, +0x18 undefined4 | Servant / effects: request and reply share this opcode. Servant and effect notices. | MISSING | S944 wire-W06-servant | D INFERRED |
| 0x05190001 | C>S |  | B 0x01376d60 | 28 | +0x0 undefined2, +0x6 undefined4, +0xa undefined2 | Servant / effects: request. Servant and effect notices. | MISSING | S944 wire-W06-servant | D INFERRED |
| 0x05190002 | C>S |  | B 0x01376d10 | 16 | - | Servant / effects: request. Servant and effect notices. | MISSING | S944 wire-W06-servant | D INFERRED |
| 0x05190003 | S>C |  | H 0x008e4430 | - | +0x4 undefined4, +0x8 char | Servant / effects: reply/notification. Servant and effect notices. Likely reply to C>S 0x05190002 (request even / reply odd convention). | MISSING |  | D INFERRED |

### 0x051a Store (personal shop) / Auction (38)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x051a0000 | C>S |  | B 0x014fd090 | 20 | +0x0 undefined4 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S700 Personal shop buyer wire (W15) | D INFERRED |
| 0x051a0001 | S>C |  | H 0x014fd050(cmp) | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0000 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0002 | C>S |  | B 0x014ffa80 | 16 | - | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S903 Personal shop wire (W03) | D INFERRED |
| 0x051a0003 | S>C |  | H 0x014ffef0(cmp) | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0002 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0004 | C>S |  | B 0x014fed20(factory) | 60 | - | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S903 Personal shop seller wire (W03) | D INFERRED |
| 0x051a0005 | S>C |  | H 0x014fead0 | - | +0x4 int | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0004 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0006 | C>S |  | B 0x014ff040 | 16 | - | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S903 Personal shop wire (W03) | D INFERRED |
| 0x051a0007 | S>C |  | H 0x014ffef0(cmp); H 0x014fefb0(cmp) | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0006 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0008 | C>S |  | B 0x014fe2c0 | 40 | +0x0 undefined2, +0x2 undefined1, +0x8 undefined4, +0xc undefined4, +0x10 undefined1 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S903 Personal shop seller wire (W03) | D INFERRED |
| 0x051a0009 | S>C |  | H 0x014fe5c0 | - | +0x0 undefined1 | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0008 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a000a | C>S |  | B 0x014fe230 | 20 | +0x0 undefined2, +0x2 undefined1 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S903 Personal shop seller wire (W03) | D INFERRED |
| 0x051a000b | S>C |  | H 0x014fe900 | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000a (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a000c | C>S |  | B 0x014ffd20 | 28 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1, +0x7 bool, +0x8 undefined2 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S700 Personal shop buyer wire (W15) | D INFERRED |
| 0x051a000d | S>C |  | H 0x014fff70; H 0x014fefb0(cmp) | - | +0x0 undefined4, +0x4 undefined4, +0x8 ptr, +0xc short, +0xe undefined1, +0xf char | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000c (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a000e | C>S |  | B 0x013787b0 | 16 | - | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S705 W15 consign retrieve-all + dungeon entry yes (S707) | D INFERRED |
| 0x051a000f | S>C |  | H 0x01378190(cmp); H 0x01378800(cmp) | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000e (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0010 | C>S |  | B 0x0140d190 | 164 | +0x0 undefined1, +0x1 undefined1, +0x2 undefined1, +0x3 undefined1, +0x4 undefined1, +0x5 undefined1 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S703 W15 consign buy/receive | D INFERRED |
| 0x051a0012 | C>S |  | B 0x0140d3a0 | 200 | +0x2a undefined4, +0x2e undefined4, +0x32 undefined4, +0x36 undefined4, +0x3a undefined4, +0x3e undefined4 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S703 W15 consign buy/receive | D INFERRED |
| 0x051a0013 | S>C |  | H 0x0140d700 | - | +0x0 char, +0x50 undefined4 | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0012 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0014 | S>C |  | H 0x0140c870 | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0015 | C>S |  | B 0x0140d2f0 | 16 | - | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S702 W15 store actions: pcshop expand item + consignment register | D INFERRED |
| 0x051a0016 | S>C |  | H 0x0140d680 | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0015 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0017 | C>S |  | B 0x013a7e30 | 20 | +0x0 undefined2, +0x2 undefined1 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S702 W15 store actions: pcshop expand item + consignment register | D INFERRED |
| 0x051a0018 | S>C |  | H 0x013ac2c0 | - | +0x0 ptr, +0x3 undefined1 | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0017 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0019 | C>S |  | B 0x00a95b20(factory); B 0x014d1a60 | 16 | - | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S701 W15 decoded accept-and-log rows | D INFERRED |
| 0x051a001a | C>S |  | B 0x0141a8d0 | 168 | +0x0 undefined2, +0x2 undefined1, +0x8 undefined4, +0xc undefined4, +0x10 undefined1, +0x12 ptr/copy | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S702 W15 store actions: pcshop expand item + consignment register | D INFERRED |
| 0x051a001b | S>C |  | H 0x01378190(cmp); H 0x01378800(cmp) | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a001a (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a001c | C>S |  | B 0x0141aa20 | 24 | +0x0 undefined4, +0x4 undefined4 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S703 W15 consign buy/receive | D INFERRED |
| 0x051a001d | C>S |  | B 0x0141aa90 | 16 | - | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S703 W15 consign buy/receive | D INFERRED |
| 0x051a001f | S>C |  | H 0x0140e890 | - | +0x0 undefined4 | Store (personal shop) / Auction: reply/notification. Personal store and auction house. | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0020 | C>S |  | B 0x0141ab40 | 16 | - | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S702 W15 store actions: pcshop expand item + consignment register | D INFERRED |
| 0x051a0021 | S>C |  | H 0x0140c720(cmp) | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0020 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0022 | C>S |  | B 0x0141abb0 | 24 | +0x0 uint, +0x4 uint | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S703 W15 consign buy/receive | D INFERRED |
| 0x051a0023 | C>S |  | B 0x0141af10 | 96 | +0x0 undefined1, +0x1 undefined1, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S703 W15 consign buy/receive | D INFERRED |
| 0x051a0024 | S>C |  | H 0x0140ec10 | - | +0x0 char, +0x50 undefined4 | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0023 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0025 | C>S |  | B 0x0141b100; B 0x0141aff0 | 192 | +0x0 ptr/copy, +0xa0 undefined4, +0xa4 undefined4, +0xa8 uint, +0xac undefined4 | Store (personal shop) / Auction: request. Personal store and auction house. | pcshop, consign (INFERRED) | S703 W15 consign buy/receive | D INFERRED |
| 0x051a0026 | S>C |  | H 0x0140e9c0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 char | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0025 (request even / reply odd convention). | pcshop, consign (INFERRED) |  | D INFERRED |
| 0x051a0027 | S>C |  | H 0x0140c720(cmp) | - | - | Store (personal shop) / Auction: reply/notification. Personal store and auction house. | pcshop, consign (INFERRED) |  | D INFERRED |

### 0x051c Upgrade (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x051c0000 | S>C |  | H 0x0139c110(cmp) | - | - | Upgrade: reply/notification. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0000 open window, no body (case 0x16ef7e6 -> handler 0x16ef830) | socket (INFERRED) |  | D INFERRED |
| 0x051c0001 | C>S |  | B 0x0139b930 | 40 | +0x0 int, +0x4 undefined2, +0x6 undefined1, +0x7 undefined2, +0x9 undefined1, +0xa undefined2 | Upgrade: request. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051c0001 upgrade request, size 0x28 (builder 0x16ef020). Body offsets (packet offset - 0x10): | socket (INFERRED) | S117 Upgrade | D+O INFERRED |
| 0x051c0002 | S>C |  | H 0x0139c110(cmp) | obs 30 | - | Upgrade: reply/notification. Item upgrade (enchant). Likely reply to C>S 0x051c0001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0002 result (handler 0x16ef880), size 0x1e (= last field read; exact si… | socket (INFERRED) |  | D+O INFERRED |
| 0x051c0003 | C>S |  | B 0x0139b8e0 | 16 | - | Upgrade: request. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051c0003 close (size 0x10, builder 0x16eefd0) | socket (INFERRED) | S117 Upgrade | D+O INFERRED |
| 0x051c0004 | S>C |  | H 0x0139c110(cmp) | obs 16 | - | Upgrade: reply/notification. Item upgrade (enchant). Likely reply to C>S 0x051c0003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0004 close window, no body (case 0x16ef7f1).  Other S>C cases UNDECODED… | socket (INFERRED) |  | D+O INFERRED |
| 0x051c0005 | S>C |  | H 0x0139c110(cmp) | - | - | Upgrade: reply/notification. Item upgrade (enchant). | socket (INFERRED) |  | D INFERRED |

### 0x051d Target (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x051d0000 | S>C |  | H 0x008e55c0 | - | +0x0 undefined4, +0x4 int, +0xc int, +0x10 int, +0x14 uint, +0x23 char | Target: reply/notification. Target selection. | shareTarget (INFERRED) |  | D INFERRED |
| 0x051d0001 | C>S |  | B 0x008e7650(factory); B 0x0136cf90 | 24 | - | Target: request. Target selection. | shareTarget (INFERRED) | S946 wire-W06-target | D INFERRED |
| 0x051d0003 | S>C |  | H 0x008e42b0 | - | +0x4 undefined4, +0x8 char | Target: reply/notification. Target selection. | shareTarget (INFERRED) |  | D INFERRED |
| 0x051d0004 | C>S |  | B 0x008be5b0 | 16 | - | Target: request. Target selection. | shareTarget (INFERRED) | S946 wire-W06-target | D INFERRED |

### 0x051e ItemAddSocket (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x051e0001 | C>S |  | B 0x013a1d00(factory) | 48 | - | ItemAddSocket: request. Add socket to item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051e0001 request, size 0x30 (ctor 0x16f53d0, filled at 0x16f4d1d / 0x16f50c3 from a 0x17-byte struct: zero 0x16f42a0, | socket (INFERRED) | S056 ItemAddSocket | D INFERRED |
| 0x051e0003 | C>S |  | B 0x013a1480 | 16 | - | ItemAddSocket: request. Add socket to item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051e0003 close, size 0x10 (0x16f4b50) | socket (INFERRED) | S056 ItemAddSocket | D INFERRED |

### 0x051f NPC mail (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x051f0000 | both |  | B 0x014e1bc0; H 0x012e4c20(cmp) | 20 | - | NPC mail: request and reply share this opcode. NPC mail dialog. | mail (INFERRED) | S972 NpcDialogWire | D INFERRED |
| 0x051f0001 | C>S |  | B 0x014e1c20 | 16 | - | NPC mail: request. NPC mail dialog. | mail (INFERRED) | S972 NpcDialogWire | D INFERRED |
| 0x051f0002 | S>C |  | H 0x012e4c20(cmp) | - | - | NPC mail: reply/notification. NPC mail dialog. Likely reply to C>S 0x051f0001 (request even / reply odd convention). | mail (INFERRED) |  | D INFERRED |
| 0x051f0003 | C>S |  | B 0x00a95af0(factory); B 0x014d1a10 | 16 | - | NPC mail: request. NPC mail dialog. | mail (INFERRED) | S972 NpcDialogWire | D INFERRED |

### 0x0520 CashShop / VipShop (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05200000 | C>S |  | B 0x013e29a0; B 0x01475330 | 20 | +0x0 undefined1 | CashShop / VipShop: request. Cash/VIP shop. | coinshop (INFERRED) | S967 CashShopWire | D INFERRED |
| 0x05200001 | S>C |  | H 0x013ea250 | - | +0x0 undefined1, +0x1 char | CashShop / VipShop: reply/notification. Cash/VIP shop. Likely reply to C>S 0x05200000 (request even / reply odd convention). | coinshop (INFERRED) |  | D INFERRED |
| 0x05200002 | C>S |  | B 0x013e2a10; B 0x013e3fc0 | 20 | +0x0 undefined1 | CashShop / VipShop: request. Cash/VIP shop. | coinshop (INFERRED) | S967 CashShopWire | D INFERRED |
| 0x05200003 | S>C |  | H 0x013ea3d0 | - | - | CashShop / VipShop: reply/notification. Cash/VIP shop. Likely reply to C>S 0x05200002 (request even / reply odd convention). | coinshop (INFERRED) |  | D INFERRED |

### 0x0521 Fishing (9)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05210000 | C>S |  | B 0x014dd610(factory) | 24 | - | Fishing: request. Fishing cast/wait/reel. | fishing (INFERRED) | S968 FishingWire | D INFERRED |
| 0x05210001 | S>C |  | H 0x015177d0(cmp) | - | - | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210000 (request even / reply odd convention). | fishing (INFERRED) |  | D INFERRED |
| 0x05210003 | C>S |  | B 0x01516d30 | 16 | - | Fishing: request. Fishing cast/wait/reel. | fishing (INFERRED) | S968 FishingWire | D INFERRED |
| 0x05210004 | S>C |  | H 0x01516ce0(cmp) | - | - | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210003 (request even / reply odd convention). | fishing (INFERRED) |  | D INFERRED |
| 0x05210006 | S>C |  | H 0x0124c8d0(cmp) | - | - | Fishing: reply/notification. Fishing cast/wait/reel. | fishing (INFERRED) |  | D INFERRED |
| 0x05210007 | C>S |  | B 0x0124c0a0 | 60 | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Fishing: request. Fishing cast/wait/reel. | fishing (INFERRED) | S968 FishingWire | D INFERRED |
| 0x05210008 | S>C |  | H 0x0124c8d0(cmp) | - | - | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210007 (request even / reply odd convention). | fishing (INFERRED) |  | D INFERRED |
| 0x05210009 | S>C |  | H 0x01318770 | - | +0x0 ptr, +0x3d char | Fishing: reply/notification. Fishing cast/wait/reel. | fishing (INFERRED) |  | D INFERRED |
| 0x0521000a | C>S |  | B 0x01296290 | 16 | - | Fishing: request. Fishing cast/wait/reel. | fishing (INFERRED) | S968 FishingWire | D INFERRED |

### 0x0522 PVP duel (16)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05220000 | C>S |  | B 0x0124e250 | 64 | +0x0 undefined4, +0x4 ptr/copy, +0x2e undefined1 | PVP duel: request. 1v1 PVP duel request/accept/result. | pvp (INFERRED) | S960 PvP22Wire | D INFERRED |
| 0x05220001 | S>C |  | H 0x01281c00(cmp) | - | - | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x05220000 (request even / reply odd convention). | pvp (INFERRED) |  | D INFERRED |
| 0x05220002 | C>S |  | B 0x0124e180 | 68 | +0x0 ptr/copy, +0x30 undefined1 | PVP duel: request. 1v1 PVP duel request/accept/result. | pvp (INFERRED) | S960 PvP22Wire | D INFERRED |
| 0x05220003 | S>C |  | H 0x01281e80 | - | - | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x05220002 (request even / reply odd convention). | pvp (INFERRED) |  | D INFERRED |
| 0x05220004 | S>C |  | H 0x01281d40 | - | +0x0 undefined4, +0x4 undefined4 | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. | pvp (INFERRED) |  | D INFERRED |
| 0x05220005 | C>S |  | B 0x01282840(factory); B 0x01284970 | 68 | - | PVP duel: request. 1v1 PVP duel request/accept/result. | pvp (INFERRED) | S960 PvP22Wire | D INFERRED |
| 0x05220006 | S>C |  | H 0x01281c00(cmp) | - | - | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x05220005 (request even / reply odd convention). | pvp (INFERRED) |  | D INFERRED |
| 0x05220007 | S>C |  | H 0x01281fe0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc ptr, +0x36 ptr, +0x62 ushort | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. | pvp (INFERRED) |  | D INFERRED |
| 0x05220008 | C>S |  | B 0x0124d210 | 64 | +0x0 undefined4, +0x4 ptr/copy, +0x2e undefined1 | PVP duel: request. 1v1 PVP duel request/accept/result. | pvp (INFERRED) | S960 PvP22Wire | D INFERRED |
| 0x05220009 | S>C |  | H 0x01282130 | - | - | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x05220008 (request even / reply odd convention). | pvp (INFERRED) |  | D INFERRED |
| 0x0522000a | C>S |  | B 0x0124d670 | 20 | +0x0 undefined1 | PVP duel: request. 1v1 PVP duel request/accept/result. | pvp (INFERRED) | S960 PvP22Wire | D INFERRED |
| 0x0522000b | S>C |  | H 0x01281c00(cmp) | - | - | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. Likely reply to C>S 0x0522000a (request even / reply odd convention). | pvp (INFERRED) |  | D INFERRED |
| 0x0522000d | S>C |  | H 0x012821d0 | - | +0x8 undefined4, +0xc undefined2, +0xe undefined2, +0x10 undefined2, +0x14 undefined4 | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. | pvp (INFERRED) |  | D INFERRED |
| 0x0522000e | S>C |  | H 0x01281c00(cmp) | - | - | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. | pvp (INFERRED) |  | D INFERRED |
| 0x0522000f | C>S |  | B 0x01284130 | 24 | +0x0 undefined4, +0x4 undefined2 | PVP duel: request. 1v1 PVP duel request/accept/result. | pvp (INFERRED) | S960 PvP22Wire | D INFERRED |
| 0x05220011 | S>C |  | H 0x012823a0 | - | +0x0 char, +0x4 int, +0x8 int, +0xc int, +0x10 int | PVP duel: reply/notification. 1v1 PVP duel request/accept/result. | pvp (INFERRED) |  | D INFERRED |

### 0x0523 Portal / CashItem (8)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05230000 | S>C |  | H 0x012e5470(cmp) | - | - | Portal / CashItem: reply/notification. Portal and cash item notices. | smartwarp (INFERRED) |  | D INFERRED |
| 0x05230001 | C>S |  | B 0x013a7f70 | 20 | +0x0 undefined2, +0x2 undefined1 | Portal / CashItem: request. Portal and cash item notices. | smartwarp (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05230002 | S>C |  | H 0x013ab3a0 | - | +0x0 ptr, +0x3 undefined1 | Portal / CashItem: reply/notification. Portal and cash item notices. Likely reply to C>S 0x05230001 (request even / reply odd convention). | smartwarp (INFERRED) |  | D INFERRED |
| 0x05230003 | S>C |  | H 0x008e6320 | - | +0x0 undefined4, +0x4 ushort, +0x6 ushort, +0x8 byte, +0xc undefined4, +0x10 undefined2 | Portal / CashItem: reply/notification. Portal and cash item notices. | smartwarp (INFERRED) |  | D INFERRED |
| 0x05230004 | S>C |  | H 0x013ab750 | - | +0x0 char | Portal / CashItem: reply/notification. Portal and cash item notices. | smartwarp (INFERRED) |  | D INFERRED |
| 0x05230005 | C>S |  | B 0x013a7af0(factory) | 20 | - | Portal / CashItem: request. Portal and cash item notices. | smartwarp (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05230006 | S>C |  | H 0x013ab550 | - | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1 | Portal / CashItem: reply/notification. Portal and cash item notices. Likely reply to C>S 0x05230005 (request even / reply odd convention). | smartwarp (INFERRED) |  | D INFERRED |
| 0x05230007 | S>C |  | H 0x013ab7b0 | - | +0x0 undefined4 | Portal / CashItem: reply/notification. Portal and cash item notices. | smartwarp (INFERRED) |  | D INFERRED |

### 0x0524 Enter event (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05240000 | S>C |  | H 0x008e5440 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined2, +0x66 undefined1 | Enter event: reply/notification. Object enter event. | MISSING |  | D INFERRED |

### 0x0525 Quest (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05250000 | S>C |  | H 0x012c9730(cmp) | - | - | Quest: reply/notification. Quest UI. | quest (INFERRED) |  | D INFERRED |
| 0x05250001 | C>S |  | B 0x012c8cf0 | 24 | +0x0 undefined4, +0x4 short | Quest: request. Quest UI. | quest (INFERRED) | S904 Quest window 0x12 wire (W04) | D INFERRED |
| 0x05250002 | S>C |  | H 0x012ca4c0 | - | +0x0 undefined1 | Quest: reply/notification. Quest UI. Likely reply to C>S 0x05250001 (request even / reply odd convention). | quest (INFERRED) |  | D INFERRED |
| 0x05250003 | C>S |  | B 0x012c8bf0 | 16 | - | Quest: request. Quest UI. | quest (INFERRED) | S904 Quest window 0x12 wire (W04) | D INFERRED |
| 0x05250004 | S>C |  | H 0x012c9730(cmp) | - | - | Quest: reply/notification. Quest UI. Likely reply to C>S 0x05250003 (request even / reply odd convention). | quest (INFERRED) |  | D INFERRED |

### 0x0526 Dungeon / InformDialog / Captcha (31)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05260000 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260001 | S>C |  | H 0x013cbcf0 | - | +0x0 undefined2, +0x2 undefined2 | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260002 | S>C |  | H 0x012e58d0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260003 | C>S |  | B 0x014e1eb0 | 24 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined2 | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) | S707 W15 instance dungeon entry confirm (0x0526000c ask / 0x0526000e result) | D INFERRED |
| 0x05260004 | S>C |  | H 0x013cc4b0 | - | +0x0 undefined2, +0x2 undefined2, +0x4 undefined1 | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. Likely reply to C>S 0x05260003 (request even / reply odd convention). | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260005 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260006 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260007 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260008 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260009 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x0526000a | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x0526000b | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x0526000c | S>C |  | H 0x013cc7e0 | - | +0x0 undefined2, +0x4 undefined4 | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x0526000d | C>S |  | B 0x014c4190; B 0x00b91cb0(factory) | 64 | +0x0 undefined2, +0x4 undefined4, +0x8 undefined1, +0xa short, +0xc ptr/copy | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) | S705 W15 consign retrieve-all + dungeon entry yes (S707) | D INFERRED |
| 0x0526000e | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. Likely reply to C>S 0x0526000d (request even / reply odd convention). | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260010 | C>S |  | B 0x00b91b60; B 0x00b91c80(factory) | 16 | - | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) | S701 W15 decoded accept-and-log rows | D INFERRED |
| 0x05260011 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. Likely reply to C>S 0x05260010 (request even / reply odd convention). | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260012 | S>C |  | H 0x013fa910 | - | +0x4 ushort, +0x6 ushort | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260013 | S>C |  | H 0x013db170(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260014 | S>C |  | H 0x013fae20 | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260015 | S>C |  | H 0x013fb060 | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260016 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260017 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260018 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260019 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260020 | S>C |  | H 0x013ccd20 | - | +0x0 char | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260021 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. | EXPLICIT* map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260022 | C>S |  | B 0x013c9ea0 | 16 | - | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. | EXPLICIT* map-event (explicit 0x05260021-23); dungeons (INFERRED) | S701 W15 decoded accept-and-log rows | D INFERRED |
| 0x05260023 | S>C |  | H 0x013cb9f0(cmp) | - | - | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. Likely reply to C>S 0x05260022 (request even / reply odd convention). | EXPLICIT* map-event (explicit 0x05260021-23); dungeons (INFERRED) |  | D INFERRED |
| 0x05260025 | C>S |  | B 0x008aeac0(factory) | 20 | - | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) | S701 W15 decoded accept-and-log rows | D INFERRED |
| 0x05260026 | C>S |  | B 0x008aeaf0(factory) | 20 | - | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. | map-event (explicit 0x05260021-23); dungeons (INFERRED) | S701 W15 decoded accept-and-log rows | D INFERRED |

### 0x0527 Creature/enter events (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05270000 | S>C |  | H 0x008e4f20 | - | +0x0 undefined4, +0x4 int, +0x28 undefined2, +0x2a undefined2, +0x2c undefined2, +0x58 short | Creature/enter events: reply/notification. Creature/enter events. | MISSING |  | D INFERRED |
| 0x05270001 | S>C |  | H 0x008e2c20(cmp) | - | - | Creature/enter events: reply/notification. Creature/enter events. | MISSING |  | D INFERRED |
| 0x05270002 | S>C |  | H 0x008e52a0 | - | +0x0 undefined4, +0x4 undefined1, +0x8 int, +0xc undefined4 | Creature/enter events: reply/notification. Creature/enter events. | MISSING |  | D INFERRED |
| 0x05270003 | S>C |  | H 0x008e2c20(cmp) | - | - | Creature/enter events: reply/notification. Creature/enter events. | MISSING |  | D INFERRED |
| 0x05270004 | S>C |  | H 0x008e2c20(cmp) | - | - | Creature/enter events: reply/notification. Creature/enter events. | MISSING |  | D INFERRED |
| 0x05270005 | S>C |  | H 0x013c36f0 | - | +0x0 undefined4 | Creature/enter events: reply/notification. Creature/enter events. | MISSING |  | D INFERRED |

### 0x0528 Siege (55)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05280000 | S>C |  | H 0x012e1080(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280001 | C>S |  | B 0x014e0b90; B 0x014e0b90 | 20 | +0x0 short | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280002 | S>C |  | H 0x012e1080(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280001 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280003 | C>S |  | B 0x013bfa40 | 20 | +0x0 undefined2 | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280004 | S>C |  | H 0x013c1f80 | - | +0x0 undefined1, +0x8 int, +0xc int, +0x18 undefined4, +0x1c undefined2 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280003 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280007 | S>C |  | H 0x012e26d0 | - | +0x0 char, +0x4 undefined4 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280008 | C>S |  | B 0x014e1140 | 16 | - | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280009 | S>C |  | H 0x012e2620(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280008 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528000a | C>S |  | B 0x013bfb80 | 16 | - | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x0528000b | S>C |  | H 0x012e2620(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528000a (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528000c | S>C |  | H 0x013b0330 | - | +0x0 undefined4 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528000d | C>S |  | B 0x013afb10 | 20 | +0x0 undefined4 | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S943 wire-W06-sentry | D INFERRED |
| 0x0528000e | S>C |  | H 0x013b0110(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528000d (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528000f | S>C |  | H 0x013c2b80 | - | +0x0 undefined1 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280010 | S>C |  | H 0x013c2d50 | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280011 | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280012 | S>C |  | H 0x013b0110(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280013 | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280014 | S>C |  | H 0x013c0e70 | - | +0x0 undefined1, +0x4 undefined4, +0x8 undefined1 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280015 | C>S |  | B 0x013bfe40 | 16 | - | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280016 | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280015 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280017 | C>S |  | B 0x013bffe0 | 24 | +0x0 undefined4, +0x4 undefined4 | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280018 | S>C |  | H 0x013c1040 | - | +0x0 undefined1, +0x4 undefined4, +0x8 undefined4, +0xc undefined4 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280017 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280019 | S>C |  | H 0x013c3580 | - | +0x0 char, +0x1 undefined1 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528001a | S>C |  | H 0x013c0ce0 | - | +0x0 undefined1 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528001b | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280020 | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280021 | S>C |  | H 0x013c3b60 | - | +0x0 char, +0x8 char | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280022 | C>S |  | B 0x013be320 | 24 | +0x0 undefined1, +0x1 undefined1, +0x2 undefined1, +0x3 undefined1, +0x4 undefined1 | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280023 | S>C |  | H 0x013c3d40 | - | +0x0 char, +0x58 undefined4, +0x5c undefined4 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280022 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280024 | S>C |  | H 0x013c4470 | - | +0x0 char | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280025 | C>S |  | B 0x013be7e0 | 20 | +0x0 uint | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280026 | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280025 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280027 | C>S |  | B 0x013be850 | 16 | - | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280028 | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280027 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280029 | S>C |  | H 0x013c40d0 | - | +0x0 int, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528002a | S>C |  | H 0x013c4270 | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528002b | S>C |  | H 0x012ebcd0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528002c | C>S |  | B 0x013be670 | 24 | +0x0 short, +0x2 undefined2, +0x4 undefined2 | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x0528002d | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528002c (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528002e | C>S |  | B 0x013be620 | 16 | - | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x0528002f | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528002e (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280030 | S>C |  | H 0x012ebfe0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280031 | C>S |  | B 0x014e36a0 | 20 | +0x0 undefined2 | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280032 | S>C |  | H 0x012ebfe0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280031 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280033 | S>C |  | H 0x012ecb00(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280034 | C>S |  | B 0x014e3960 | 20 | +0x0 undefined2 | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280035 | S>C |  | H 0x012ecb00(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280034 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280036 | S>C |  | H 0x012ed5c0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280037 | C>S |  | B 0x014e3c20 | 20 | +0x0 undefined2 | Siege: request. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) | S945 wire-W06-siege | D INFERRED |
| 0x05280038 | S>C |  | H 0x012ed5c0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280037 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x05280039 | S>C |  | H 0x013c4380 | - | +0x0 int | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528003a | S>C |  | H 0x013c4770 | - | +0x24 int, +0x28 undefined1 | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528003b | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0528003c | S>C |  | H 0x013c06a0(cmp) | - | - | Siege: reply/notification. Castle siege UI, siege teleport, sentries. | siegerenew (INFERRED) |  | D INFERRED |

### 0x0529 Enter event (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05290000 | S>C |  | H 0x008e6600 | - | +0x0 int, +0x8 int, +0xc float, +0x10 ptr | Enter event: reply/notification. Enter event. | MISSING |  | D INFERRED |

### 0x052a Vehicle (24)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x052a0000 | C>S |  | B 0x013ce400 | 16 | - | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. | wing (INFERRED) | S122 Vehicle | D INFERRED |
| 0x052a0001 | S>C |  | H 0x013cde00(cmp) | - | - | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0000 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a0002 | C>S |  | B 0x013ce460 | 16 | - | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. | wing (INFERRED) | S122 Vehicle | D INFERRED |
| 0x052a0003 | S>C |  | H 0x013cdfa0 | - | +0x0 undefined1 | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0002 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a0004 | C>S |  | B 0x013ce4b0 | 16 | - | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. | wing (INFERRED) | S122 Vehicle | D INFERRED |
| 0x052a0005 | S>C |  | H 0x013cde00(cmp) | - | - | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0004 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a0006 | C>S |  | B 0x013ce510 | 16 | - | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. | wing (INFERRED) | S122 Vehicle | D INFERRED |
| 0x052a0007 | S>C |  | H 0x013ce160 | - | +0x0 undefined1 | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0006 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a0008 | S>C |  | H 0x013cde00(cmp) | - | - | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. | wing (INFERRED) |  | D INFERRED |
| 0x052a0009 | C>S |  | B 0x013cd400 | 16 | - | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. | wing (INFERRED) | S122 Vehicle | D INFERRED |
| 0x052a0010 | S>C |  | H 0x013ce2a0 | - | +0x0 char | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. | wing (INFERRED) |  | D INFERRED |
| 0x052a0011 | C>S |  | B 0x013cd400 | 16 | - | Vehicle: request. Mount/vehicle and vehicle upgrade. | wing (INFERRED) | S973 VehicleWire | D INFERRED |
| 0x052a0012 | S>C |  | H 0x013ce350 | - | +0x4 char | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0011 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a0013 | C>S |  | B 0x0146e800 | 48 | - | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0013 vf+0x54 0x17c0b20 size 0x30: +0x10 10 x ref3 (memcpy 0x1e bytes from +0xa)  -> engine vehicleservice 'crystallize' {uids (1..10)} | wing (INFERRED) | S123 VehicleUpgrade | D INFERRED |
| 0x052a0014 | S>C |  | H 0x0146f100 | - | +0x1e undefined1 | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0013 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a0015 | C>S |  | B 0x0146e860 | 24 | +0x0 undefined2, +0x2 undefined1, +0x3 undefined2, +0x5 undefined1, +0x6 undefined2 | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0015 vf+0x58 0x17c0b80 size 0x18: +0x10 ref3 vehicle, +0x13 ref3 material, +0x16 u16 material stack (item(ref B) vf+0x1c -> +0x0e) | wing (INFERRED) | S123 VehicleUpgrade | D INFERRED |
| 0x052a0016 | S>C |  | H 0x0146f260 | - | +0x8 undefined1 | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0015 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a0017 | C>S |  | B 0x0146df80 | 24 | +0x0 undefined2, +0x2 undefined1, +0x3 undefined2, +0x5 undefined1 | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0017 vf+0x60 0x17c02a0 size 0x18: +0x10 ref3 vehicle, +0x13 ref3 gearwheel        -> engine 'enchant' {uid, gear} | wing (INFERRED) | S123 VehicleUpgrade | D INFERRED |
| 0x052a0018 | S>C |  | H 0x0146f3f0 | - | +0x0 undefined3, +0x3 undefined3, +0xc undefined2, +0xe undefined1, +0x10 undefined4, +0x14 undefined4 | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0017 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a0019 | C>S |  | B 0x0146dff0 | 24 | +0x0 undefined2, +0x2 undefined1, +0x3 undefined2, +0x5 undefined1 | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0019 vf+0x64 0x17c0310 size 0x18: +0x10 ref3 vehicle, +0x13 ref3 material         -> engine 'enhance' {uid} | wing (INFERRED) | S123 VehicleUpgrade | D INFERRED |
| 0x052a001a | S>C |  | H 0x0146f700 | - | +0x3 undefined3, +0xe undefined2, +0x10 undefined4, +0x14 undefined4, +0x18 undefined1 | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a0019 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |
| 0x052a001b | S>C |  | H 0x0146f060(cmp) | - | - | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. | wing (INFERRED) |  | D INFERRED |
| 0x052a001c | C>S |  | B 0x0146e130 | 16 | - | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a001c vf+0x6c 0x17c0450 size 0x10: close request                                   -> S>C 0x052a001d | wing (INFERRED) | S123 VehicleUpgrade | D INFERRED |
| 0x052a001d | S>C |  | H 0x0146fa80 | - | - | Vehicle: reply/notification. Mount/vehicle and vehicle upgrade. Likely reply to C>S 0x052a001c (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S123: 0x052a001c vf+0x6c 0x17c0450 size 0x10: close request                 … | wing (INFERRED) |  | D INFERRED |

### 0x052b AutoReport (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x052b0005 | C>S |  | B 0x014fac30 | 24 | +0x0 undefined4, +0x4 undefined4 | AutoReport: request. Auto-report (bot/macro report) from PC dialog. | EXPLICIT* autoreport (explicit 0x052B0005) (INFERRED) | S938 wire-W06-chat | D INFERRED |
| 0x052b0006 | S>C |  | H 0x012fac50 | - | +0x0 undefined1 | AutoReport: reply/notification. Auto-report (bot/macro report) from PC dialog. Likely reply to C>S 0x052b0005 (request even / reply odd convention). | autoreport (explicit 0x052B0005) (INFERRED) |  | D INFERRED |

### 0x052c CoinExchange / Exchange (21)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x052c0000 | S>C |  | H 0x013d03c0 | - | - | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): S037: S>C 0x052c0000 open (case 0x1723820 -> 0x1723880): +0x00 u32 (npc handle), +0x04 u16 (UNVERIFIED: catalog = npc.csv JobIndex), … | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0001 | C>S |  | B 0x013d0ac0 | 24,28 | +0x0 undefined4, +0x4 undefined2, +0x6 ushort, +0x8 undefined2, +0xa undefined1 | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0001, size 0x18: +0x00 u32 (npc handle), +0x04 u16 a, +0x06 u16 b   (UNVERIFIED: a = catalog, b = row) | exchangebuy (INFERRED) | S037 Exchange | D INFERRED |
| 0x052c0002 | S>C |  | H 0x013d0440 | - | +0x50 ptr, +0x58 char, +0x59 char | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S037: S>C 0x052c0002 (-> 0x1723900), size 0x6a: +0x00 0x58-byte… | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0003 | C>S |  | B 0x013d0a70 | 16 | - | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0003 close, size 0x10 | exchangebuy (INFERRED) | S037 Exchange | D INFERRED |
| 0x052c0004 | S>C |  | H 0x013d0a40 | - | - | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0003 (request even / reply odd convention). | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0005 | C>S |  | B 0x013d0ac0 | 24,28 | +0x0 undefined4, +0x4 undefined2, +0x6 ushort, +0x8 undefined2, +0xa undefined1 | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0005, size 0x1c: +0x00 u32, +0x04 u16, +0x06 u16, +0x08 u16, +0x0a u8   (UNVERIFIED: catalog, row, count, kind -> engine '… | exchangebuy (INFERRED) | S037 Exchange | D INFERRED |
| 0x052c0006 | S>C |  | H 0x013d0750 | - | +0x50 ptr, +0x58 char, +0x59 ptr, +0x5c char | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0005 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S037: S>C 0x052c0006 (-> 0x1723c10), size 0x6d: +0x00 block, +0… | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0007 | C>S |  | B 0x014b2330(factory) | 16,20 | +0x0 undefined4 | CoinExchange / Exchange: request. Coin exchange and NPC exchange. | exchangebuy (INFERRED) | S985 wire-W11-coinexchange | D INFERRED |
| 0x052c0008 | S>C |  | H 0x014ac940 | - | +0x0 char | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0007 (request even / reply odd convention). | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0009 | C>S |  | B 0x014b2330(factory) | 16,20 | +0x0 undefined4 | CoinExchange / Exchange: request. Coin exchange and NPC exchange. | exchangebuy (INFERRED) | S985 wire-W11-coinexchange | D INFERRED |
| 0x052c000a | S>C |  | H 0x014acb10 | - | +0x0 char | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0009 (request even / reply odd convention). | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c000b | S>C |  | H 0x014ac880(cmp) | - | - | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c000c | C>S |  | B 0x014ac7d0 | 16 | - | CoinExchange / Exchange: request. Coin exchange and NPC exchange. | exchangebuy (INFERRED) | S985 wire-W11-coinexchange | D INFERRED |
| 0x052c000d | S>C |  | H 0x014ac880(cmp) | - | - | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c000c (request even / reply odd convention). | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0010 | C>S |  | B 0x014b2330(factory) | 16,20 | +0x0 undefined4 | CoinExchange / Exchange: request. Coin exchange and NPC exchange. | exchangebuy (INFERRED) | S985 wire-W11-coinexchange | D INFERRED |
| 0x052c0011 | S>C |  | H 0x014acce0 | - | +0x0 char, +0x8 undefined4, +0xc undefined4 | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0010 (request even / reply odd convention). | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0012 | C>S |  | B 0x014b2330(factory) | 16,20 | +0x0 undefined4 | CoinExchange / Exchange: request. Coin exchange and NPC exchange. | exchangebuy (INFERRED) | S985 wire-W11-coinexchange | D INFERRED |
| 0x052c0013 | S>C |  | H 0x014acd60 | - | +0x0 char, +0x8 uint, +0xc int | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0012 (request even / reply odd convention). | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0014 | S>C |  | H 0x014ac880(cmp) | - | - | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. | exchangebuy (INFERRED) |  | D INFERRED |
| 0x052c0015 | C>S |  | B 0x014ac7d0 | 16 | - | CoinExchange / Exchange: request. Coin exchange and NPC exchange. | exchangebuy (INFERRED) | S985 wire-W11-coinexchange | D INFERRED |
| 0x052c0016 | S>C |  | H 0x014ac880(cmp) | - | - | CoinExchange / Exchange: reply/notification. Coin exchange and NPC exchange. Likely reply to C>S 0x052c0015 (request even / reply odd convention). | exchangebuy (INFERRED) |  | D INFERRED |

### 0x052d Observer (12)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x052d0000 | S>C |  | H 0x013d0fa0(cmp) | - | - | Observer: reply/notification. Observer/spectator mode. | observer (INFERRED) |  | D INFERRED |
| 0x052d0001 | C>S |  | B 0x013d55a0 | 20 | +0x0 undefined2 | Observer: request. Observer/spectator mode. | observer (INFERRED) | S941 wire-W06-observer | D INFERRED |
| 0x052d0002 | S>C |  | H 0x013d1980 | - | +0x6 undefined2, +0x8 undefined2 | Observer: reply/notification. Observer/spectator mode. Likely reply to C>S 0x052d0001 (request even / reply odd convention). | observer (INFERRED) |  | D INFERRED |
| 0x052d0003 | C>S |  | B 0x013d5600 | 16,20 | +0x0 undefined4 | Observer: request. Observer/spectator mode. | observer (INFERRED) | S941 wire-W06-observer | D INFERRED |
| 0x052d0004 | S>C |  | H 0x013d1130 | - | +0x0 int, +0x4 undefined3, +0x8 undefined4, +0xc ptr, +0x12 undefined1, +0x14 undefined4 | Observer: reply/notification. Observer/spectator mode. Likely reply to C>S 0x052d0003 (request even / reply odd convention). | observer (INFERRED) |  | D INFERRED |
| 0x052d0005 | C>S |  | B 0x013d5b80(factory) | 16 | - | Observer: request. Observer/spectator mode. | observer (INFERRED) | S941 wire-W06-observer | D INFERRED |
| 0x052d0006 | S>C |  | H 0x013d1300 | - | +0x0 int, +0x4 ptr, +0xa undefined1, +0xc undefined4 | Observer: reply/notification. Observer/spectator mode. Likely reply to C>S 0x052d0005 (request even / reply odd convention). | observer (INFERRED) |  | D INFERRED |
| 0x052d0007 | C>S |  | B 0x013d56e0 | 60 | +0x0 ptr/copy | Observer: request. Observer/spectator mode. | observer (INFERRED) | S941 wire-W06-observer | D INFERRED |
| 0x052d0008 | S>C |  | H 0x013d1820 | - | +0x0 undefined4 | Observer: reply/notification. Observer/spectator mode. Likely reply to C>S 0x052d0007 (request even / reply odd convention). | observer (INFERRED) |  | D INFERRED |
| 0x052d0009 | S>C |  | H 0x013d0fa0(cmp) | - | - | Observer: reply/notification. Observer/spectator mode. | observer (INFERRED) |  | D INFERRED |
| 0x052d000a | S>C |  | H 0x013d1480 | - | +0x0 short, +0x2 short, +0x4 short, +0x6 undefined1, +0x8 undefined4 | Observer: reply/notification. Observer/spectator mode. | observer (INFERRED) |  | D INFERRED |
| 0x052d000b | S>C |  | H 0x013d1610 | - | +0x0 short, +0x2 short, +0x4 short, +0x6 undefined1, +0x8 undefined4 | Observer: reply/notification. Observer/spectator mode. | observer (INFERRED) |  | D INFERRED |

### 0x052f Ornament events (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x052f0000 | S>C |  | H 0x013d5e90 | - | +0x9 char, +0xa char | Ornament events: reply/notification. Ornament events. | MISSING |  | D INFERRED |
| 0x052f0001 | S>C |  | H 0x013d5d70(cmp) | - | - | Ornament events: reply/notification. Ornament events. | MISSING |  | D INFERRED |
| 0x052f0002 | S>C |  | H 0x008e6170 | - | +0x0 undefined4, +0x2e undefined4, +0x30 ushort, +0x32 undefined2, +0x34 undefined4, +0x38 undefined4 | Ornament events: reply/notification. Ornament events. | MISSING |  | D INFERRED |
| 0x052f0003 | S>C |  | H 0x013d5d70(cmp) | - | - | Ornament events: reply/notification. Ornament events. | MISSING |  | D INFERRED |

### 0x0530 Party war (NPC) (25)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05300000 | S>C |  | H 0x012e8290 | - | +0x0 undefined4 | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300001 | S>C |  | H 0x012e7910 | - | +0x0 undefined4 | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300002 | C>S |  | B 0x014e2160 | 20 | +0x0 undefined2 | Party war (NPC): request. Party war record/teleport via NPC. | partypvp (INFERRED) | S706 W15 party war (Dead Front / Ice Castle) apply + in-war UI | D INFERRED |
| 0x05300003 | S>C |  | H 0x012e7dc0 | - | +0x0 undefined4 | Party war (NPC): reply/notification. Party war record/teleport via NPC. Likely reply to C>S 0x05300002 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x05300004 | S>C |  | H 0x013db2e0 | - | +0x0 int, +0x4 int | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300005 | C>S |  | B 0x014e2450 | 20 | +0x0 undefined2 | Party war (NPC): request. Party war record/teleport via NPC. | partypvp (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |
| 0x05300006 | S>C |  | H 0x012e8740 | - | +0x0 undefined4, +0x4 undefined3, +0x8 int, +0xc undefined4, +0x10 undefined2 | Party war (NPC): reply/notification. Party war record/teleport via NPC. Likely reply to C>S 0x05300005 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x05300007 | S>C |  | H 0x013db170(cmp) | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300008 | S>C |  | H 0x013db400 | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300009 | S>C |  | H 0x013db660 | - | +0x0 undefined4, +0x4 int, +0xc int | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x0530000a | S>C |  | H 0x013db8a0 | - | +0x0 undefined4, +0x4 int | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x0530000b | S>C |  | H 0x013dc090 | - | +0x0 int, +0x4 undefined4, +0x8 undefined2 | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x0530000c | S>C |  | H 0x013dc2d0 | - | +0x0 char, +0x2 short, +0x4 undefined2, +0x8 undefined4 | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x0530000d | S>C |  | H 0x013db170(cmp) | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x0530000e | S>C |  | H 0x013db4a0 | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x0530000f | S>C |  | H 0x013db170(cmp) | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300010 | S>C |  | H 0x013db170(cmp) | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300011 | S>C |  | H 0x013dc6c0 | - | +0x0 ptr | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300012 | S>C |  | H 0x013db170(cmp) | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300013 | S>C |  | H 0x013db170(cmp) | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300014 | S>C |  | H 0x013dbaf0 | - | +0x0 undefined4, +0x4 uint | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x05300015 | C>S |  | B 0x014e21e0; B 0x014e24d0 | 16 | - | Party war (NPC): request. Party war record/teleport via NPC. | partypvp (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |
| 0x0530001a | S>C |  | H 0x012e78a0(cmp); H 0x012e8220(cmp) | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x0530001b | S>C |  | H 0x013db170(cmp) | - | - | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |
| 0x0530001d | S>C |  | H 0x013dcbb0 | - | +0x0 undefined1, +0x1 undefined1 | Party war (NPC): reply/notification. Party war record/teleport via NPC. | partypvp (INFERRED) |  | D INFERRED |

### 0x0531 Observer (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05310000 | S>C |  | H 0x013d1a00 | - | - | Observer: reply/notification. Observer list. | observer (INFERRED) |  | D INFERRED |
| 0x05310001 | C>S |  | B 0x013d5600 | 16,20 | +0x0 undefined4 | Observer: request. Observer list. | observer (INFERRED) | S941 wire-W06-observer | D INFERRED |
| 0x05310002 | S>C |  | H 0x013d1a50 | - | +0x0 int, +0x4 undefined3, +0x8 ptr, +0x10 float | Observer: reply/notification. Observer list. Likely reply to C>S 0x05310001 (request even / reply odd convention). | observer (INFERRED) |  | D INFERRED |
| 0x05310003 | C>S |  | B 0x013d5860 | 16,20 | +0x0 undefined4 | Observer: request. Observer list. | observer (INFERRED) | S941 wire-W06-observer | D INFERRED |
| 0x05310004 | S>C |  | H 0x013d1bf0 | - | +0x0 int, +0x4 ptr, +0xc float | Observer: reply/notification. Observer list. Likely reply to C>S 0x05310003 (request even / reply odd convention). | observer (INFERRED) |  | D INFERRED |
| 0x05310005 | S>C |  | H 0x012fa860 | - | +0x0 int, +0x4 byte | Observer: reply/notification. Observer list. | observer (INFERRED) |  | D INFERRED |
| 0x05310006 | S>C |  | H 0x013d1d70 | - | - | Observer: reply/notification. Observer list. | observer (INFERRED) |  | D INFERRED |

### 0x0532 ItemRemoveStone (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05320001 | C>S |  | B 0x013e0160; B 0x013e12d0 | 44 | +0x4 uint, +0x8 undefined4, +0xc undefined4, +0x10 ptr/copy, +0x18 undefined4 | ItemRemoveStone: request. Remove stone from item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05320001 request, size 0x2c (builders 0x1733630 / 0x1733f30; body is a struct copy, pkt+0x28 u32 from [ebp-0x14]): | socket (INFERRED) | S062 ItemRemoveStone | D INFERRED |
| 0x05320003 | C>S |  | B 0x013e0110; B 0x013e1320 | 16 | - | ItemRemoveStone: request. Remove stone from item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05320003 close, size 0x10 (0x17335e0) | socket (INFERRED) | S062 ItemRemoveStone | D INFERRED |

### 0x0534 Servant (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05340000 | S>C |  | H 0x01377130(cmp) | - | - | Servant: reply/notification. Servant notice. | summonOrder (INFERRED) |  | D INFERRED |

### 0x0535 Sky teleport (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05350000 | S>C |  | H 0x012dda90(cmp) | - | - | Sky teleport: reply/notification. Sky teleport NPC. | mapnpcwarp (INFERRED) |  | D INFERRED |
| 0x05350001 | S>C |  | H 0x012dda90(cmp) | - | - | Sky teleport: reply/notification. Sky teleport NPC. | mapnpcwarp (INFERRED) |  | D INFERRED |
| 0x05350002 | S>C |  | H 0x012e8b50(cmp); H 0x012e8bb0(cmp) | - | - | Sky teleport: reply/notification. Sky teleport NPC. | mapnpcwarp (INFERRED) |  | D INFERRED |
| 0x05350003 | C>S |  | B 0x014e2730 | 24 | +0x0 undefined2, +0x2 undefined2, +0x4 undefined2 | Sky teleport: request. Sky teleport NPC. | mapnpcwarp (INFERRED) | S939 wire-W06-npcdialog | D INFERRED |
| 0x05350004 | S>C |  | H 0x012e8b50(cmp); H 0x012e8bb0(cmp) | - | - | Sky teleport: reply/notification. Sky teleport NPC. Likely reply to C>S 0x05350003 (request even / reply odd convention). | mapnpcwarp (INFERRED) |  | D INFERRED |

### 0x0536 (unattributed) (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05360000 | S>C |  | H 0x01323560 | - | +0x0 undefined4, +0x4 undefined2, +0x6 char | (unattributed): reply/notification. Unattributed family. | MISSING |  | D INFERRED |

### 0x0537 Pet (18)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05370000 | S>C |  | H 0x00836790(cmp); H 0x008e6bd0 | - | - | Pet: reply/notification. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370001 | C>S |  | B 0x013f16b0 | 80 | +0x0 undefined4 | Pet: request. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05370002 | S>C |  | H 0x013f4740 | - | +0x0 char | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370001 (request even / reply odd convention). | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370003 | C>S |  | B 0x013f1600 | 16 | - | Pet: request. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05370004 | C>S |  | B 0x013f1ac0 | 56 | +0x0 ptr/copy | Pet: request. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05370005 | S>C |  | H 0x013f4500 | - | +0x0 char | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370004 (request even / reply odd convention). | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370006 | S>C |  | H 0x013f48a0 | - | +0x0 char, +0x8 undefined4 | Pet: reply/notification. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370008 | S>C |  | H 0x013f3cb0(cmp) | - | - | Pet: reply/notification. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370009 | C>S |  | B 0x013f2c00 | 20 | +0x0 undefined2, +0x2 undefined1 | Pet: request. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05370010 | S>C |  | H 0x013f5370 | - | +0x0 undefined1, +0x8 undefined8, +0x10 undefined4 | Pet: reply/notification. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370011 | C>S |  | B 0x013f2d20 | 28 | +0x0 undefined2, +0x2 undefined1, +0x3 undefined2, +0x5 undefined1, +0x6 undefined2, +0x8 undefined1 | Pet: request. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05370012 | S>C |  | H 0x013f5720 | - | +0x0 undefined1 | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370011 (request even / reply odd convention). | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370015 | C>S |  | B 0x013f2c90 | 20 | +0x0 undefined2, +0x2 undefined1 | Pet: request. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05370016 | S>C |  | H 0x013f5590 | - | +0x0 undefined1 | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370015 (request even / reply odd convention). | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370017 | C>S |  | B 0x013f3240 | 20 | +0x0 undefined1, +0x1 undefined1, +0x2 undefined1 | Pet: request. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05370018 | S>C |  | H 0x013f3e80 | - | +0x0 char | Pet: reply/notification. Pet summon/feed/inventory. Likely reply to C>S 0x05370017 (request even / reply odd convention). | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |
| 0x05370019 | C>S |  | B 0x013f1c10 | 16 | - | Pet: request. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05370020 | S>C |  | H 0x013f4610 | - | +0x0 char | Pet: reply/notification. Pet summon/feed/inventory. | pet, petinventory, petsettings, petname (INFERRED) |  | D INFERRED |

### 0x0538 Pet (8)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05380000 | C>S |  | B 0x013f20a0 | 16 | - | Pet: request. Pet UI. | pet, petcombine, petsoul, petawake (INFERRED) | S989 wire-W12-pet | D+O INFERRED |
| 0x05380001 | S>C |  | H 0x013f3cb0(cmp) | - | - | Pet: reply/notification. Pet UI. Likely reply to C>S 0x05380000 (request even / reply odd convention). | pet, petcombine, petsoul, petawake (INFERRED) |  | D INFERRED |
| 0x05380002 | C>S |  | B 0x013f3820(factory); B 0x013f1ff0 | 24 | - | Pet: request. Pet UI. | pet, petcombine, petsoul, petawake (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05380003 | S>C |  | H 0x013f4b50 | - | +0x0 char, +0x1 char | Pet: reply/notification. Pet UI. Likely reply to C>S 0x05380002 (request even / reply odd convention). | pet, petcombine, petsoul, petawake (INFERRED) |  | D INFERRED |
| 0x05380004 | S>C |  | H 0x013f50f0 | - | +0x0 undefined4, +0x4 undefined4 | Pet: reply/notification. Pet UI. | pet, petcombine, petsoul, petawake (INFERRED) |  | D INFERRED |
| 0x05380005 | S>C |  | H 0x013f5910 | - | +0x0 ptr | Pet: reply/notification. Pet UI. | pet, petcombine, petsoul, petawake (INFERRED) |  | D INFERRED |
| 0x05380006 | C>S |  | B 0x013f37f0(factory) | 24 | - | Pet: request. Pet UI. | pet, petcombine, petsoul, petawake (INFERRED) | S989 wire-W12-pet | D INFERRED |
| 0x05380007 | S>C |  | H 0x013f5a60 | - | +0x0 ptr, +0x6 short, +0x8 undefined4 | Pet: reply/notification. Pet UI. Likely reply to C>S 0x05380006 (request even / reply odd convention). | pet, petcombine, petsoul, petawake (INFERRED) |  | D INFERRED |

### 0x0539 Troop (35)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05390000 | S>C |  | H 0x013ffe50(cmp) | obs 456 | - | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D+O INFERRED |
| 0x05390001 | C>S |  | B 0x014022b0 | 60 | +0x0 ptr/copy | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S113 Troop solo create and refresh (partial) | D+O INFERRED |
| 0x05390002 | S>C |  | H 0x01400060 | obs 68 | +0x0 undefined1, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390001 (request even / reply odd convention). | partyfinder (INFERRED) |  | D+O INFERRED |
| 0x05390003 | both |  | B 0x01402360; B 0x014fa740; H 0x01401de0 | 148 | +0x0 ptr/copy, +0x2a ptr/copy, +0x56 ptr/copy | Troop: request and reply share this opcode. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S948 TroopWire | D INFERRED |
| 0x05390004 | S>C |  | H 0x01400390 | - | - | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390003 (request even / reply odd convention). | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390005 | both |  | B 0x01401de0; B 0x01402970; H 0x013ffe50(cmp) | 148 | +0x0 undefined1, +0x2 undefined2, +0x2c undefined2, +0x56 undefined1, +0x58 undefined2, +0x82 undefined1 | Troop: request and reply share this opcode. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S948 TroopWire | D INFERRED |
| 0x05390006 | C>S |  | B 0x01402530; B 0x014028a0 | 60 | +0x0 ptr/copy | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S948 TroopWire | D INFERRED |
| 0x05390007 | S>C |  | H 0x014007a0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 byte, +0xa undefined4, +0xe undefined4, +0x12 undefined4 | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390006 (request even / reply odd convention). | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390008 | S>C |  | H 0x01400920 | - | - | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390009 | C>S |  | B 0x014024e0 | 16 | - | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S113 Troop rename and leave (partial) | D+O INFERRED |
| 0x0539000a | S>C |  | H 0x01400a70 | obs 17 | - | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390009 (request even / reply odd convention). | partyfinder (INFERRED) |  | D+O INFERRED |
| 0x0539000b | C>S |  | B 0x01402760 | 16 | - | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S113 Troop solo create and refresh (partial) | D+O INFERRED |
| 0x0539000c | S>C |  | H 0x013ffe50(cmp) | obs 456 | - | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x0539000b (request even / reply odd convention). | partyfinder (INFERRED) |  | D+O INFERRED |
| 0x0539000d | S>C |  | H 0x013ffe50(cmp) | - | - | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x0539000e | S>C |  | H 0x013ffe50(cmp) | - | - | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x0539000f | S>C |  | H 0x013ffe50(cmp) | - | - | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390010 | C>S |  | B 0x014025e0 | 60 | +0x0 ptr/copy | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S113 Troop rename and leave (partial) | D+O INFERRED |
| 0x05390011 | S>C |  | H 0x01400c50 | - | +0x0 char | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390010 (request even / reply odd convention). | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390012 | S>C |  | H 0x01400d90 | obs 60 | - | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D+O INFERRED |
| 0x05390013 | C>S |  | B 0x01402700 | 20 | +0x0 undefined4 | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S948 TroopWire | D INFERRED |
| 0x05390014 | S>C |  | H 0x01401410 | - | - | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390013 (request even / reply odd convention). | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390015 | S>C |  | H 0x014014d0 | - | +0x0 undefined4 | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390016 | C>S |  | B 0x01402820 | 88 | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S948 TroopWire | D INFERRED |
| 0x05390017 | S>C |  | H 0x01401c10 | - | - | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390016 (request even / reply odd convention). | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390018 | S>C |  | H 0x013ffe50(cmp) | - | - | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390019 | C>S |  | B 0x014027c0 | 20 | +0x0 undefined4 | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S948 TroopWire | D INFERRED |
| 0x0539001a | S>C |  | H 0x01401b30 | - | - | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390019 (request even / reply odd convention). | partyfinder (INFERRED) |  | D INFERRED |
| 0x0539001b | S>C |  | H 0x013ffe50(cmp) | - | - | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x0539001c | C>S |  | B 0x01402690 | 20 | +0x0 undefined4 | Troop: request. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S948 TroopWire | D INFERRED |
| 0x0539001d | S>C |  | H 0x01400ee0 | - | - | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x0539001c (request even / reply odd convention). | partyfinder (INFERRED) |  | D INFERRED |
| 0x0539001e | S>C |  | H 0x014011e0 | - | +0x0 int | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x0539001f | S>C |  | H 0x01401610 | - | +0x0 undefined1, +0x1 char, +0x4 undefined4, +0x8 int | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390020 | S>C |  | H 0x01318f80 | - | +0x0 char, +0x1 char | Troop: reply/notification. Troop (team) create/rename/leave. | partyfinder (INFERRED) |  | D INFERRED |
| 0x05390021 | both |  | B 0x012f4dd0; H 0x012fa410 | 52,96,112,132,560,668 | +0x0 undefined4, +0x8 undefined4, +0x2c undefined1, +0x30 undefined4, +0x204 undefined4 | Troop: request and reply share this opcode. Troop (team) create/rename/leave. | partyfinder (INFERRED) | S948 TroopWire | D INFERRED |
| 0x05390022 | S>C |  | H 0x013ffe50(cmp) | - | - | Troop: reply/notification. Troop (team) create/rename/leave. Likely reply to C>S 0x05390021 (request even / reply odd convention). | partyfinder (INFERRED) |  | D INFERRED |

### 0x053a OptionUpgrade (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x053a0001 | C>S |  | B 0x01405530(factory) | 44 | - | OptionUpgrade: request. Item option upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x053a0001 request, size 0x2c (ctor 0x1758170, filled at 0x1757220 from UI slot getters vf+0x28..+0x3c). Body offsets: | socket (INFERRED) | S074 OptionUpgrade | D INFERRED |
| 0x053a0003 | C>S |  | B 0x01404450 | 16 | - | OptionUpgrade: request. Item option upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x053a0003 close, size 0x10 (0x1757070) | socket (INFERRED) | S074 OptionUpgrade | D INFERRED |

### 0x053b PartyPVP (33)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x053b0000 | C>S |  | B 0x0124e9e0 | 64 | +0x0 undefined4, +0x4 ptr/copy, +0x2e undefined1 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0001 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0000 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0002 | S>C |  | H 0x01285b50 | - | +0x0 ptr | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0003 | C>S |  | B 0x01293700; B 0x01294000 | 24 | +0x0 undefined4, +0x4 undefined1 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0004 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0003 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0005 | S>C |  | H 0x012863a0 | - | +0x0 undefined1, +0x1 undefined1, +0x2 undefined1, +0x4 undefined2, +0x6 undefined1, +0x8 ptr | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0006 | C>S |  | B 0x01293390 | 28 | +0x0 undefined1, +0x2 undefined2, +0x4 undefined4, +0x8 undefined2, +0xa undefined1 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0007 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0006 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0008 | S>C |  | H 0x012862a0 | - | +0x0 byte, +0x2 undefined2, +0x4 undefined4, +0x8 undefined2, +0xa undefined1, +0xb char | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0009 | C>S |  | B 0x01293430 | 60 | +0x0 ptr/copy, +0x2a undefined1 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0010 | S>C |  | H 0x01285d90 | - | +0x2a byte, +0x2b byte | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0011 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0013 | C>S |  | B 0x0124e920 | 60 | +0x0 ptr/copy, +0x2a undefined1 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0014 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0013 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0015 | S>C |  | H 0x01286980 | - | - | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0016 | S>C |  | H 0x01286ad0 | - | +0x0 undefined1, +0x314 undefined1, +0x315 undefined1 | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0019 | C>S |  | B 0x01293590 | 16 | - | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0020 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0021 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0022 | C>S |  | B 0x01293520 | 16 | - | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0023 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0022 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0024 | C>S |  | B 0x013d5600 | 16,20 | +0x0 undefined4 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0025 | S>C |  | H 0x013d1e10 | - | +0x0 char, +0x2 ptr, +0x8 float | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0024 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0026 | C>S |  | B 0x013d5860 | 16,20 | +0x0 undefined4 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0027 | S>C |  | H 0x013d1f60 | - | +0x0 char, +0x2 ptr, +0x8 float | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0026 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0028 | S>C |  | H 0x01285970(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0029 | S>C |  | H 0x013d0fa0(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0030 | S>C |  | H 0x013d0fa0(cmp) | - | - | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0031 | S>C |  | H 0x01286c80 | - | - | PartyPVP: reply/notification. Party PVP matches. | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0032 | C>S |  | B 0x01293600 | 20 | +0x0 undefined1, +0x1 undefined1 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0033 | S>C |  | H 0x01286d00 | - | - | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0032 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |
| 0x053b0035 | C>S |  | B 0x01293660 | 28 | +0x0 undefined8, +0x8 undefined2 | PartyPVP: request. Party PVP matches. | partypvp (INFERRED) | S969 PartyPvpWire | D INFERRED |
| 0x053b0036 | S>C |  | H 0x01286d90 | - | - | PartyPVP: reply/notification. Party PVP matches. Likely reply to C>S 0x053b0035 (request even / reply odd convention). | partypvp (INFERRED) |  | D INFERRED |

### 0x053c DKSquare / Arena (43)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x053c0003 | S>C |  | H 0x01250140 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0011 | S>C |  | H 0x01240630 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0012 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0016 | S>C |  | H 0x008e1120 | - | +0xc undefined4, +0x10 undefined4, +0x2c undefined4, +0x38 undefined4, +0x3c undefined4, +0x40 undefined4 | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0017 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0018 | S>C |  | H 0x012e94c0(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c001a | S>C |  | H 0x012e94c0(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c001b | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c001c | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c001d | C>S |  | B 0x0129c950 | 16 | - | DKSquare / Arena: request. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) | S961 DKSquareWire | D INFERRED |
| 0x053c001e | S>C |  | H 0x0073ebb0 | - | +0x0 undefined4, +0x4 undefined4 | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. Likely reply to C>S 0x053c001d (request even / reply odd convention). | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c001f | S>C |  | H 0x0073ebb0 | - | +0x0 undefined4, +0x4 undefined4 | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0020 | C>S |  | B 0x0129c2c0 | 16 | - | DKSquare / Arena: request. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) | S961 DKSquareWire | D INFERRED |
| 0x053c0021 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. Likely reply to C>S 0x053c0020 (request even / reply odd convention). | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0022 | C>S |  | B 0x01240900 | 20 | +0x0 undefined4 | DKSquare / Arena: request. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) | S961 DKSquareWire | D INFERRED |
| 0x053c0023 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. Likely reply to C>S 0x053c0022 (request even / reply odd convention). | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0024 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0025 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0026 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0027 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0028 | S>C |  | H 0x00752d60 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0029 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0032 | S>C |  | H 0x01245b30 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0033 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0034 | S>C |  | H 0x01250e20 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0035 | S>C |  | H 0x01245b30 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0036 | S>C |  | H 0x01150dd0 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0038 | S>C |  | H 0x012a5020 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0039 | S>C |  | H 0x012aa170 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c003b | S>C |  | H 0x0129dc80 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c003c | S>C |  | H 0x0073ebb0 | - | +0x0 undefined4, +0x4 undefined4 | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c003d | S>C |  | H 0x0073ebb0 | - | +0x0 undefined4, +0x4 undefined4 | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c003e | S>C |  | H 0x00740450 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c003f | C>S |  | B 0x0129d870(factory) | 16 | - | DKSquare / Arena: request. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) | S961 DKSquareWire | D+O INFERRED |
| 0x053c0040 | S>C |  | H 0x012aa5a0 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. Likely reply to C>S 0x053c003f (request even / reply odd convention). | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0041 | S>C |  | H 0x012aa5d0 | - | +0x0 byte, +0x4 undefined4 | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0042 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0043 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0044 | S>C |  | H 0x01250140 | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0045 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0046 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0048 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |
| 0x053c0049 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare / Arena: reply/notification. DK Square / arena teleport and matches. | dksquare, arena (INFERRED) |  | D INFERRED |

### 0x053d CharacterTrade (12)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x053d0003 | S>C |  | H 0x0141ffb0 | - | +0x0 undefined4 | CharacterTrade: reply/notification. Character trade market. | chartrade (INFERRED) |  | D INFERRED |
| 0x053d0007 | S>C |  | H 0x0141fba0 | - | +0x0 int, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | CharacterTrade: reply/notification. Character trade market. | chartrade (INFERRED) |  | D INFERRED |
| 0x053d0008 | S>C |  | H 0x0141fed0 | - | +0x0 undefined4, +0x4 undefined4 | CharacterTrade: reply/notification. Character trade market. | chartrade (INFERRED) |  | D INFERRED |
| 0x053d000a | S>C |  | H 0x013155b0 | - | +0x0 undefined4 | CharacterTrade: reply/notification. Character trade market. | chartrade (INFERRED) |  | D INFERRED |
| 0x053d000b | S>C |  | H 0x01421190 | - | +0x0 undefined2, +0x2 undefined1, +0x3 undefined4, +0x40 ptr, +0x4c undefined4, +0x50 int | CharacterTrade: reply/notification. Character trade market. | chartrade (INFERRED) |  | D INFERRED |
| 0x053d000d | S>C |  | H 0x0141fae0 | - | - | CharacterTrade: reply/notification. Character trade market. | chartrade (INFERRED) |  | D INFERRED |
| 0x053d001b | C>S |  | B 0x01420f20 | 60 | +0x0 ptr/copy | CharacterTrade: request. Character trade market. | chartrade (INFERRED) | S806 P8 CharacterTrade invite/accept (presence-gated, W16) | D INFERRED |
| 0x053d001c | S>C |  | H 0x01420670 | - | - | CharacterTrade: reply/notification. Character trade market. Likely reply to C>S 0x053d001b (request even / reply odd convention). | chartrade (INFERRED) |  | D INFERRED |
| 0x053d001d | S>C |  | H 0x014203b0 | - | +0x0 undefined4 | CharacterTrade: reply/notification. Character trade market. | chartrade (INFERRED) |  | D INFERRED |
| 0x053d001e | C>S |  | B 0x01421040 | 20 | +0x0 undefined1 | CharacterTrade: request. Character trade market. | chartrade (INFERRED) | S806 P8 CharacterTrade invite/accept (presence-gated, W16) | D INFERRED |
| 0x053d001f | S>C |  | H 0x01420600 | - | - | CharacterTrade: reply/notification. Character trade market. Likely reply to C>S 0x053d001e (request even / reply odd convention). | chartrade (INFERRED) |  | D INFERRED |
| 0x053d0020 | S>C |  | H 0x01420640 | - | +0x0 char | CharacterTrade: reply/notification. Character trade market. | chartrade (INFERRED) |  | D INFERRED |

### 0x053e (unattributed) (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x053e0010 | S>C |  | H 0x012ca610 | - | +0x0 ptr | (unattributed): reply/notification. Unattributed family. | MISSING |  | D INFERRED |

### 0x053f Quest (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x053f0000 | S>C |  | H 0x012ca530 | - | +0x0 undefined4 | Quest: reply/notification. Quest UI. | quest (INFERRED) |  | D INFERRED |
| 0x053f0001 | C>S |  | B 0x012c8d60 | 24 | +0x0 undefined4, +0x4 short | Quest: request. Quest UI. | quest (INFERRED) | S800 Quest windows 0x36/0x93 accept (W16) | D INFERRED |
| 0x053f0002 | S>C |  | H 0x012ca550 | - | +0x0 char | Quest: reply/notification. Quest UI. Likely reply to C>S 0x053f0001 (request even / reply odd convention). | quest (INFERRED) |  | D INFERRED |
| 0x053f0004 | S>C |  | H 0x012ca5a0 | - | +0x0 undefined4 | Quest: reply/notification. Quest UI. | quest (INFERRED) |  | D INFERRED |

### 0x0541 Target (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05410000 | S>C |  | H 0x0136ab70(cmp) | - | - | Target: reply/notification. Target net handler. | shareTarget (INFERRED) |  | D INFERRED |
| 0x05410001 | C>S |  | B 0x0136ac90 | 24 | +0x0 undefined2, +0x4 undefined4 | Target: request. Target net handler. | shareTarget (INFERRED) | S955 TargetMiscWire | D INFERRED |
| 0x05410002 | C>S |  | B 0x0136ad10 | 20 | +0x0 undefined2 | Target: request. Target net handler. | shareTarget (INFERRED) | S955 TargetMiscWire | D INFERRED |

### 0x0542 (unattributed) (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05420000 | S>C |  | H 0x008e7090 | - | +0x0 undefined4, +0x4 int, +0x8 undefined2, +0xc int, +0x10 undefined4, +0x14 uint | (unattributed): reply/notification. Unattributed family. | MISSING |  | D INFERRED |
| 0x05420003 | S>C |  | H 0x008e45f0 | - | +0x4 undefined4, +0x8 char | (unattributed): reply/notification. Unattributed family. | MISSING |  | D INFERRED |

### 0x0543 Storage (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05430000 | C>S |  | B 0x0131de70 | 20 | +0x0 undefined2, +0x2 undefined1, +0x3 undefined1 | Storage: request. Storage extension. | storage (INFERRED) | S105 StorageHandoff | D INFERRED |
| 0x05430001 | S>C |  | H 0x013204c0 | - | +0x0 undefined1, +0x1 char | Storage: reply/notification. Storage extension. Likely reply to C>S 0x05430000 (request even / reply odd convention). | storage (INFERRED) |  | D INFERRED |
| 0x05430002 | C>S |  | B 0x0131df10 | 20 | +0x0 undefined2, +0x2 undefined1 | Storage: request. Storage extension. | storage (INFERRED) | S105 StorageHandoff | D INFERRED |
| 0x05430003 | S>C |  | H 0x013207f0 | - | +0x0 undefined1 | Storage: reply/notification. Storage extension. Likely reply to C>S 0x05430002 (request even / reply odd convention). | storage (INFERRED) |  | D INFERRED |
| 0x05430004 | C>S |  | B 0x0131dfa0 | 20 | +0x0 undefined2, +0x2 undefined1 | Storage: request. Storage extension. | storage (INFERRED) | S105 StorageHandoff | D INFERRED |
| 0x05430005 | S>C |  | H 0x013209e0 | - | +0x0 undefined1 | Storage: reply/notification. Storage extension. Likely reply to C>S 0x05430004 (request even / reply odd convention). | storage (INFERRED) |  | D INFERRED |

### 0x0544 Party (39)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05440001 | C>S |  | B 0x014ddf00 | 60 | +0x0 ptr/copy | Party: request. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440002 | S>C |  | H 0x012bcc70 | obs 88 | +0x0 undefined4, +0x4 undefined4, +0x34 undefined1, +0x38 undefined4, +0x3c undefined4, +0x40 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S080: S>C 0x05440002 PARTY FORMED, handler 0x161be60: +0x10 i32 re… | party (INFERRED) |  | D+O INFERRED |
| 0x05440003 | both |  | B 0x01250b70; B 0x012ba070; H 0x012bf920 | 168 | +0x30 undefined8, +0x8c undefined1, +0x8d undefined1, +0x90 undefined4 | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05440003 INVITE  size 0xa8, builder 0x1619230 (UIHandler@Party; msg 70:12 "Invite %s to your Party.",… | party (INFERRED) | S080 Party | D+O INFERRED |
| 0x05440004 | S>C |  | H 0x012be7e0 | - | +0x0 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440003 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x05440005 | both |  | B 0x012bf920; B 0x012c1dd0; H 0x012beb70 | 104 | +0x0 undefined1, +0x56 undefined1, +0x57 undefined1 | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05440005 DECLINE size 0x68, builder 0x1620fa0: +0x10 u8 reason (client sends 2), +0x12 wchar[21] name… | party (INFERRED) | S080 Party | D INFERRED |
| 0x05440006 | C>S |  | B 0x012c1cf0 | 72 | +0x0 undefined4, +0x4 undefined4, +0x8 ptr/copy, +0x32 undefined1, +0x33 undefined1 | Party: request. Party invite/accept/leave/kick/leader/options. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05440006 ACCEPT  size 0x48, builder 0x1620ec0: +0x10 u64 partyId (from invite +0x40), +0x18 wchar[21] name A, | party (INFERRED) | S080 Party | D INFERRED |
| 0x05440007 | S>C |  | H 0x012bce10 | obs 96 | +0x30 undefined4, +0x34 undefined4, +0x38 undefined1, +0x3c undefined1, +0x40 undefined1, +0x44 undefined4 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440006 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S080: S>C 0x05440007 MEMBER JOINED, handler 0x161c000: +0x10 wchar… | party (INFERRED) |  | D+O INFERRED |
| 0x05440008 | S>C |  | H 0x012be960 | - | +0x0 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x05440009 | C>S |  | B 0x014de1d0; B 0x014de860 | 16 | - | Party: request. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x0544000a | S>C |  | H 0x012bcf60 | - | +0x0 char | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440009 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x0544000b | S>C |  | H 0x012bd040 | - | +0x38 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x0544000c | S>C |  | H 0x012c0290 | - | +0x2a undefined1, +0x2c undefined2, +0x2e undefined1, +0x2f undefined1, +0x30 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x0544000d | S>C |  | H 0x012c0040 | obs 64 | - | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Prior-build note (43.3.0, INFERRED for 0.0.1): S080: S>C 0x0544000d MEMBER LEFT, handler 0x161f210: +0x10 wchar[21] name, +0x3a u8 -> 70:1 "has left the Party." | party (INFERRED) |  | D+O INFERRED |
| 0x0544000f | S>C |  | H 0x012c03b0 | - | +0x0 ushort | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x05440010 | C>S |  | B 0x012bad40 | 48 | +0x0 undefined2, +0x2 undefined2, +0x4 byte, +0x6 ushort, +0x8 undefined1, +0xd byte | Party: request. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440012 | S>C |  | H 0x012bedd0 | - | +0x0 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x05440013 | C>S |  | B 0x012bac70 | 24 | +0x0 byte | Party: request. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440014 | S>C |  | H 0x012bef20 | - | +0x0 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440013 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x05440015 | both |  | B 0x012bae90; H 0x012bf8c0 | 16 | - | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440016 | both |  | B 0x012bacf0; H 0x012bfea0 | 16 | - | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440017 | both |  | B 0x014de3b0; H 0x012be660 | 20 | +0x0 uint | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440018 | S>C |  | H 0x012c0590 | - | - | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440017 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x05440019 | S>C |  | H 0x012c0690 | - | - | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x0544001a | S>C |  | H 0x012bfee0 | - | +0x0 undefined1, +0x2 undefined2, +0x4 undefined2, +0x6 undefined1, +0x8 undefined1, +0x9 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x0544001b | C>S |  | B 0x012ba3f0 | 24 | +0x0 byte | Party: request. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x0544001c | S>C |  | H 0x012bf030 | - | +0x0 undefined1, +0x1 undefined1, +0x4 ptr | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x0544001b (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x0544001d | C>S |  | B 0x012ba6f0 | 24 | +0x0 undefined4, +0x4 undefined4 | Party: request. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x0544001e | S>C |  | H 0x012bf170 | - | +0x0 undefined1, +0x2c byte, +0x2e ptr | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x0544001d (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x0544001f | C>S |  | B 0x012ba470; B 0x012ba530 | 32 | +0x0 undefined4, +0x4 undefined4, +0x8 undefined2, +0xa ptr/copy | Party: request. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440020 | both |  | B 0x012ba750; H 0x012bf540 | 80,128 | +0x0 ulonglong, +0x32 undefined2, +0x34 undefined4, +0x58 undefined8, +0x60 undefined2, +0x64 undefined4 | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440021 | both |  | B 0x012ba750; H 0x012bf370 | 80,128 | +0x0 ulonglong, +0x32 undefined2, +0x34 undefined4, +0x58 undefined8, +0x60 undefined2, +0x64 undefined4 | Party: request and reply share this opcode. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440022 | S>C |  | H 0x012bf720 | - | +0x0 ulonglong, +0x8 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440021 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x05440023 | C>S |  | B 0x012ba630 | 60 | +0x0 ptr/copy, +0x2a undefined1 | Party: request. Party invite/accept/leave/kick/leader/options. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05440024 | S>C |  | H 0x012c06c0 | - | +0x0 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. Likely reply to C>S 0x05440023 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x05440025 | S>C |  | H 0x012c1fa0 | - | +0x0 char | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x05440026 | S>C |  | H 0x012c1fe0 | - | +0x0 char | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x05440027 | S>C |  | H 0x012c2010 | - | +0x0 int | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x05440028 | S>C |  | H 0x012c2040 | - | +0x0 ptr, +0x2a char | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |
| 0x05440029 | S>C |  | H 0x012c2320 | - | +0x0 undefined1 | Party: reply/notification. Party invite/accept/leave/kick/leader/options. | party (INFERRED) |  | D INFERRED |

### 0x0545 Party (notify/chat) (17)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05450000 | both |  | B 0x014de300; H 0x012bdad0 | 60 | +0x0 ptr/copy | Party (notify/chat): request and reply share this opcode. Party notifications and party chat. | party (INFERRED) | S942 wire-W06-party | D INFERRED |
| 0x05450003 | both |  | B 0x014de220; H 0x012b6da0 | 84 | +0x0 ptr/copy, +0x2a undefined1 | Party (notify/chat): request and reply share this opcode. Party notifications and party chat. | party (INFERRED) | S938 wire-W06-chat | D INFERRED |
| 0x05450004 | S>C |  | H 0x012bd790 | - | +0x0 byte | Party (notify/chat): reply/notification. Party notifications and party chat. Likely reply to C>S 0x05450003 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x05450005 | both |  | B 0x014de410; H 0x012bd820 | 84 | +0x2a undefined1 | Party (notify/chat): request and reply share this opcode. Party notifications and party chat. | party (INFERRED) | S080 PartyHandoff | D INFERRED |
| 0x05450006 | C>S |  | B 0x012451b0 | 16 | - | Party (notify/chat): request. Party notifications and party chat. | party (INFERRED) | S938 wire-W06-chat | D INFERRED |
| 0x05450007 | S>C |  | H 0x012bdc10 | - | +0x0 undefined4, +0x8 undefined1, +0x9 byte, +0xa byte | Party (notify/chat): reply/notification. Party notifications and party chat. Likely reply to C>S 0x05450006 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x05450008 | S>C |  | H 0x012bdf70 | - | +0x0 undefined4, +0xa undefined2 | Party (notify/chat): reply/notification. Party notifications and party chat. | party (INFERRED) |  | D INFERRED |
| 0x05450009 | S>C |  | H 0x012be140 | - | +0x0 undefined4 | Party (notify/chat): reply/notification. Party notifications and party chat. | party (INFERRED) |  | D INFERRED |
| 0x0545000a | S>C |  | H 0x012be0c0 | - | +0x0 undefined4, +0xa ushort, +0xc ushort | Party (notify/chat): reply/notification. Party notifications and party chat. | party (INFERRED) |  | D INFERRED |
| 0x0545000b | S>C |  | H 0x012be070 | - | +0x0 undefined4, +0xa undefined2 | Party (notify/chat): reply/notification. Party notifications and party chat. | party (INFERRED) |  | D INFERRED |
| 0x0545000c | both |  | B 0x012f4dd0; H 0x012f9fd0 | 52,96,112,132,560,668 | +0x0 undefined4, +0x8 undefined4, +0x2c undefined1, +0x30 undefined4, +0x204 undefined4 | Party (notify/chat): request and reply share this opcode. Party notifications and party chat. | party (INFERRED) | S938 wire-W06-chat | D INFERRED |
| 0x0545000d | S>C |  | H 0x012be1b0 | - | +0x0 undefined1, +0x1 char, +0x4 undefined4, +0x8 int | Party (notify/chat): reply/notification. Party notifications and party chat. Likely reply to C>S 0x0545000c (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |
| 0x0545000e | S>C |  | H 0x01316470 | - | +0x0 char, +0x3e char | Party (notify/chat): reply/notification. Party notifications and party chat. | party (INFERRED) |  | D INFERRED |
| 0x05450011 | S>C |  | H 0x012be170 | - | +0x0 undefined4, +0xa undefined2, +0xc undefined2, +0xe undefined2, +0x10 undefined2 | Party (notify/chat): reply/notification. Party notifications and party chat. | party (INFERRED) |  | D INFERRED |
| 0x05450012 | S>C |  | H 0x012bdfa0 | - | - | Party (notify/chat): reply/notification. Party notifications and party chat. | party (INFERRED) |  | D INFERRED |
| 0x05450013 | C>S |  | B 0x014637e0(factory); B 0x014d1ab0 | 60 | - | Party (notify/chat): request. Party notifications and party chat. | party (INFERRED) | S938 wire-W06-chat | D INFERRED |
| 0x05450014 | S>C |  | H 0x01462d20(cmp) | - | - | Party (notify/chat): reply/notification. Party notifications and party chat. Likely reply to C>S 0x05450013 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |

### 0x0546 Party (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05460000 | C>S |  | B 0x012baee0 | 20 | +0x0 undefined1 | Party: request. Party UI. | party (INFERRED) | S974 PartyWire | D INFERRED |
| 0x05460001 | S>C |  | H 0x012c0810 | - | +0x0 undefined1, +0x1 byte | Party: reply/notification. Party UI. Likely reply to C>S 0x05460000 (request even / reply odd convention). | party (INFERRED) |  | D INFERRED |

### 0x0547 CashItem (10)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05470000 | S>C |  | H 0x013aa050 | - | +0x0 undefined1, +0x4 undefined4, +0x8 undefined4 | CashItem: reply/notification. Cash item use. | itemuse (INFERRED) |  | D INFERRED |
| 0x05470001 | S>C |  | H 0x013aa1d0 | - | +0x0 undefined1 | CashItem: reply/notification. Cash item use. | itemuse (INFERRED) |  | D INFERRED |
| 0x05470002 | C>S |  | B 0x013a4a20 | 20 | +0x0 undefined2 | CashItem: request. Cash item use. | itemuse (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05470003 | S>C |  | H 0x013aad20 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined2, +0xa undefined1, +0xc undefined4 | CashItem: reply/notification. Cash item use. Likely reply to C>S 0x05470002 (request even / reply odd convention). | itemuse (INFERRED) |  | D INFERRED |
| 0x05470004 | C>S |  | B 0x013a4aa0 | 20 | +0x0 undefined2 | CashItem: request. Cash item use. | itemuse (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05470005 | S>C |  | H 0x013aaeb0 | - | +0x0 undefined4 | CashItem: reply/notification. Cash item use. Likely reply to C>S 0x05470004 (request even / reply odd convention). | itemuse (INFERRED) |  | D INFERRED |
| 0x05470006 | S>C |  | H 0x013a9230(cmp) | - | - | CashItem: reply/notification. Cash item use. | itemuse (INFERRED) |  | D INFERRED |
| 0x05470007 | S>C |  | H 0x013aa880 | - | +0x0 undefined1, +0x1 char | CashItem: reply/notification. Cash item use. | itemuse (INFERRED) |  | D INFERRED |
| 0x05470008 | C>S |  | B 0x00ca04e0(factory) | 16 | - | CashItem: request. Cash item use. | itemuse (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x05470009 | S>C |  | H 0x013ab2d0 | - | +0x0 byte | CashItem: reply/notification. Cash item use. Likely reply to C>S 0x05470008 (request even / reply odd convention). | itemuse (INFERRED) |  | D INFERRED |

### 0x0548 ItemChange (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05480000 | S>C |  | H 0x0142a680(cmp) | - | - | ItemChange: reply/notification. Item change/convert. | craft (INFERRED) |  | D INFERRED |
| 0x05480001 | C>S |  | B 0x0142aa90 | 24 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1 | ItemChange: request. Item change/convert. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05480001 request, size 0x18 (builder 0x177d5e0): +0x00 u32 (window+4 = the value the open packet carried), +0x04 ref3 target | craft (INFERRED) | S057 ItemChange | D INFERRED |
| 0x05480002 | S>C |  | H 0x0142a680(cmp) | - | - | ItemChange: reply/notification. Item change/convert. Likely reply to C>S 0x05480001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S057: S>C 0x05480002 result, size 0x5b (last field read): | craft (INFERRED) |  | D INFERRED |
| 0x05480003 | C>S |  | B 0x0142ab20 | 16 | - | ItemChange: request. Item change/convert. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05480003 close, size 0x10 (0x177d670) | craft (INFERRED) | S057 ItemChange | D INFERRED |
| 0x05480004 | S>C |  | H 0x0142a680(cmp) | - | - | ItemChange: reply/notification. Item change/convert. Likely reply to C>S 0x05480003 (request even / reply odd convention). | craft (INFERRED) |  | D INFERRED |

### 0x0549 CashInventory (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05490001 | C>S |  | B 0x0142b390 | 16 | - | CashInventory: request. Cash inventory claim. | cashclaim (INFERRED) | S975 CashInventoryWire | D INFERRED |
| 0x05490002 | S>C |  | H 0x0142d690 | - | +0x0 undefined4 | CashInventory: reply/notification. Cash inventory claim. Likely reply to C>S 0x05490001 (request even / reply odd convention). | cashclaim (INFERRED) |  | D INFERRED |
| 0x05490003 | C>S |  | B 0x0142b440 | 16 | - | CashInventory: request. Cash inventory claim. | cashclaim (INFERRED) | S975 CashInventoryWire | D INFERRED |
| 0x05490004 | S>C |  | H 0x0142d7f0 | - | - | CashInventory: reply/notification. Cash inventory claim. Likely reply to C>S 0x05490003 (request even / reply odd convention). | cashclaim (INFERRED) |  | D INFERRED |

### 0x054b NPC transfer (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x054b0000 | S>C |  | H 0x012e9890 | - | +0x0 undefined4, +0x4 undefined2 | NPC transfer: reply/notification. NPC transfer dialog. | mapnpcwarp (INFERRED) |  | D INFERRED |
| 0x054b0001 | C>S |  | B 0x014e2a20; B 0x012e9890 | 24 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1 | NPC transfer: request. NPC transfer dialog. | mapnpcwarp (INFERRED) | S954 NPCDialogWire | D INFERRED |
| 0x054b0002 | S>C |  | H 0x012e9be0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined2, +0xa ushort | NPC transfer: reply/notification. NPC transfer dialog. Likely reply to C>S 0x054b0001 (request even / reply odd convention). | mapnpcwarp (INFERRED) |  | D INFERRED |
| 0x054b0003 | S>C |  | H 0x012e9de0 | - | +0x0 char | NPC transfer: reply/notification. NPC transfer dialog. | mapnpcwarp (INFERRED) |  | D INFERRED |

### 0x054c RandomBox (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x054c0000 | C>S |  | B 0x01407df0(factory) | 24 | - | RandomBox: request. Random box open. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054c0000 keyed box, size 0x18 (ctor 0x175aa30, filled at 0x175a5a7): +0x00 ref3 box, +0x03 ref3 key | itemuse (INFERRED) | S092 RandomBox | D INFERRED |
| 0x054c0001 | S>C |  | H 0x01408640(cmp) | - | - | RandomBox: reply/notification. Random box open. Likely reply to C>S 0x054c0000 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S092: S>C 0x054c0001 (cmp 0x175b2c7 -> 0x175b2e0), size 0x11: +0x00 u8 result (switch 0..19 … | itemuse (INFERRED) |  | D INFERRED |

### 0x054d SupplyMachine (11)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x054d0000 | C>S |  | B 0x014d0d00; B 0x01443dc0 | 20 | +0x0 ptr/copy | SupplyMachine: request. Supply machine. | supply (INFERRED) | S981 wire-W11-supplymachine | D+O INFERRED |
| 0x054d0001 | S>C |  | H 0x01444bf0 | - | +0x0 uint, +0x4 ptr | SupplyMachine: reply/notification. Supply machine. Likely reply to C>S 0x054d0000 (request even / reply odd convention). | supply (INFERRED) |  | D INFERRED |
| 0x054d0002 | S>C |  | H 0x01444e30 | - | +0x0 int | SupplyMachine: reply/notification. Supply machine. | supply (INFERRED) |  | D INFERRED |
| 0x054d0003 | C>S |  | B 0x014d0c60; B 0x01443e50 | 20 | +0x0 ptr/copy | SupplyMachine: request. Supply machine. | supply (INFERRED) | S981 wire-W11-supplymachine | D INFERRED |
| 0x054d0004 | S>C |  | H 0x01444f30 | - | - | SupplyMachine: reply/notification. Supply machine. Likely reply to C>S 0x054d0003 (request even / reply odd convention). | supply (INFERRED) |  | D INFERRED |
| 0x054d0005 | S>C |  | H 0x01444f90 | - | +0x0 undefined4 | SupplyMachine: reply/notification. Supply machine. | supply (INFERRED) |  | D INFERRED |
| 0x054d0006 | S>C |  | H 0x014450d0 | - | +0x0 byte, +0x4 ptr | SupplyMachine: reply/notification. Supply machine. | supply (INFERRED) |  | D INFERRED |
| 0x054d0007 | S>C |  | H 0x014452c0 | - | - | SupplyMachine: reply/notification. Supply machine. | supply (INFERRED) |  | D INFERRED |
| 0x054d0008 | C>S |  | B 0x014d0ff0; B 0x014d0ff0 | 20 | +0x0 uint | SupplyMachine: request. Supply machine. | supply (INFERRED) | S981 wire-W11-supplymachine | D INFERRED |
| 0x054d0009 | C>S |  | B 0x014d0f50; B 0x014d95c0 | 20 | +0x0 ptr/copy | SupplyMachine: request. Supply machine. | supply (INFERRED) | S981 wire-W11-supplymachine | D INFERRED |
| 0x054d000a | S>C |  | H 0x01445390 | - | +0x0 uint, +0x4 uint, +0x8 uint, +0xc undefined4, +0x10 undefined4, +0x14 undefined2 | SupplyMachine: reply/notification. Supply machine. Likely reply to C>S 0x054d0009 (request even / reply odd convention). | supply (INFERRED) |  | D INFERRED |

### 0x054e ItemIncuse (11)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x054e0000 | S>C |  | H 0x014515d0(cmp) | - | - | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. | craft (INFERRED) |  | D INFERRED |
| 0x054e0001 | C>S |  | B 0x015128d0 | 28 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1, +0x7 undefined2, +0x9 undefined1 | ItemIncuse: request. Item incuse/disassemble/amplify. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054e0001 brand, size 0x1c (0x185fb40): +0x00 u32 (window+4), +0x04 ref3 (UNVERIFIED target), +0x07 ref3 (UNVERIFIED Soul Stone) | craft (INFERRED) | S058 ItemIncuse | D INFERRED |
| 0x054e0002 | S>C |  | H 0x01512890(cmp) | - | - | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. Likely reply to C>S 0x054e0001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S058: S>C 0x054e0002 (cmp 0x185fe07 -> 0x185fe30) u8 result @+0x00: 0 ok \| … | craft (INFERRED) |  | D INFERRED |
| 0x054e0003 | C>S |  | B 0x01513410 | 28 | +0x0 undefined4, +0x4 ushort, +0x6 undefined2, +0x8 undefined1 | ItemIncuse: request. Item incuse/disassemble/amplify. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054e0003, size 0x1c (0x1860670): +0x00 u32, +0x04 u16 (return of a UI getter; UNVERIFIED count), +0x06 ref3 material | craft (INFERRED) | S058 ItemIncuse | D INFERRED |
| 0x054e0004 | S>C |  | H 0x015133d0(cmp) | - | - | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. Likely reply to C>S 0x054e0003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S058: S>C 0x054e0004 (cmp 0x18607a7 -> 0x18607c0) u8 result @+0x03: 0 ok \| … | craft (INFERRED) |  | D INFERRED |
| 0x054e0005 | C>S |  | B 0x01513b00 | 28 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1, +0x7 undefined2, +0x9 undefined1, +0xa undefined1 | ItemIncuse: request. Item incuse/disassemble/amplify. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054e0005 brand with locks, size 0x1c (0x1860c40): +0x00 u32, +0x04 ref3 target, +0x07 ref3 stone, +0x0a u8 (UNVERIFIED lock bitmask) | craft (INFERRED) | S058 ItemIncuse | D INFERRED |
| 0x054e0006 | S>C |  | H 0x01513ac0(cmp) | - | - | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. Likely reply to C>S 0x054e0005 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S058: S>C 0x054e0006 (cmp 0x1860e47 -> 0x1860e60): +0x00 u8 result (0 ok \| … | craft (INFERRED) |  | D INFERRED |
| 0x054e0007 | C>S |  | B 0x01451520 | 16 | - | ItemIncuse: request. Item incuse/disassemble/amplify. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x054e0007 close, size 0x10 (0x17a3940) | craft (INFERRED) | S058 ItemIncuse | D INFERRED |
| 0x054e0008 | S>C |  | H 0x014515d0(cmp) | - | - | ItemIncuse: reply/notification. Item incuse/disassemble/amplify. Likely reply to C>S 0x054e0007 (request even / reply odd convention). | craft (INFERRED) |  | D INFERRED |
| 0x054e0009 | C>S |  | B 0x01513be0 | 24 | +0x0 undefined4, +0x4 undefined2 | ItemIncuse: request. Item incuse/disassemble/amplify. | craft (INFERRED) |  | D INFERRED |
| 0x054e000a | C>S |  | B 0x01513e00 | 16 | - | ItemIncuse: request. Item incuse/disassemble/amplify. | craft (INFERRED) |  | D INFERRED |

### 0x054f Event (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x054f0000 | S>C |  | H 0x014524b0(cmp) | - | - | Event: reply/notification. Event UI. | event (INFERRED) |  | D INFERRED |
| 0x054f0001 | S>C |  | H 0x014524b0(cmp) | - | - | Event: reply/notification. Event UI. | event (INFERRED) |  | D INFERRED |
| 0x054f0002 | C>S |  | B 0x014520b0 | 16 | - | Event: request. Event UI. | event (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x054f0003 | S>C |  | H 0x01452580 | - | +0x0 undefined1, +0x2 undefined2, +0x4 undefined4, +0x8 undefined4 | Event: reply/notification. Event UI. Likely reply to C>S 0x054f0002 (request even / reply odd convention). | event (INFERRED) |  | D INFERRED |
| 0x054f0004 | S>C |  | H 0x014526b0 | - | +0x0 char, +0x2 undefined2, +0x4 undefined4, +0x8 undefined4 | Event: reply/notification. Event UI. | event (INFERRED) |  | D INFERRED |

### 0x0550 StoneGamble (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05500000 | S>C |  | H 0x01454760(cmp) | - | - | StoneGamble: reply/notification. Stone gamble. Prior-build note (43.3.0, INFERRED for 0.0.1): S104: S>C 0x05500000 open (case 0x17a6a8b, no body read) \| 0x05500002 -> 0x17a6b20 \| 0x05500004 -> 0x17a6ca0 \| 0x05500006 (case 0x17a6abc, close) | craft (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05500001 | C>S |  | B 0x01454ae0 | 52 | +0x0 undefined1, +0x1 ptr/copy, +0x1f undefined1, +0x20 undefined2, +0x22 undefined1 | StoneGamble: request. Stone gamble. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05500001 crush, size 0x34 (0x17a6df0): +0x00 u8 (UI vf10, UNVERIFIED count), +0x01 ref3 stones packed (UI slots 0..9, empty slots skipped), then 1 more ref3… | craft (INFERRED) (INFERRED) | S104 StoneGamble | D INFERRED |
| 0x05500002 | S>C |  | H 0x01454810 | - | +0x0 undefined2, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x18 undefined4 | StoneGamble: reply/notification. Stone gamble. Likely reply to C>S 0x05500001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S104: S>C 0x05500002, size 0x30: +0x00 u16 result: 0 ok \| 1 350:121 system error \| 2 350:122 … | craft (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05500003 | C>S |  | B 0x01454bd0 | 44 | +0x0 undefined4, +0x4 undefined1, +0x5 ptr/copy | StoneGamble: request. Stone gamble. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05500003 produce, size 0x2c (0x17a6ee0): +0x00 u32 machine (UI vf2c; UNVERIFIED = stoneproduce Index), +0x04 u8 (UI vf40), +0x05 u8[20] per-slot lock flags … | craft (INFERRED) (INFERRED) | S104 StoneGamble | D INFERRED |
| 0x05500004 | S>C |  | H 0x01454760(cmp) | - | - | StoneGamble: reply/notification. Stone gamble. Likely reply to C>S 0x05500003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S104: S>C 0x05500004, size 0x19: +0x04 u32 (UNVERIFIED result itemIndex), +0x08 u8 (0..9, UNV… | craft (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05500005 | C>S |  | B 0x01454c90 | 16 | - | StoneGamble: request. Stone gamble. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05500005 close, size 0x10 (0x17a6fa0) | craft (INFERRED) (INFERRED) | S104 StoneGamble | D INFERRED |
| 0x05500006 | S>C |  | H 0x01454760(cmp) | - | - | StoneGamble: reply/notification. Stone gamble. Likely reply to C>S 0x05500005 (request even / reply odd convention). | craft (INFERRED) (INFERRED) |  | D INFERRED |

### 0x0551 ConnectReward (8)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05510000 | C>S |  | B 0x01461fe0 | 18 | +0x0 undefined1, +0x1 undefined1 | ConnectReward: request. Connection-time rewards. | connectreward (INFERRED) | S983 wire-W11-connectreward | D INFERRED |
| 0x05510001 | S>C |  | H 0x014626a0 | - | +0x0 undefined1, +0x1 undefined1 | ConnectReward: reply/notification. Connection-time rewards. Likely reply to C>S 0x05510000 (request even / reply odd convention). | connectreward (INFERRED) |  | D INFERRED |
| 0x05510002 | S>C |  | H 0x01462580(cmp) | - | - | ConnectReward: reply/notification. Connection-time rewards. | connectreward (INFERRED) |  | D INFERRED |
| 0x05510003 | S>C |  | H 0x01462580(cmp) | - | - | ConnectReward: reply/notification. Connection-time rewards. | connectreward (INFERRED) |  | D INFERRED |
| 0x05510004 | S>C |  | H 0x01462580(cmp) | - | - | ConnectReward: reply/notification. Connection-time rewards. | connectreward (INFERRED) |  | D INFERRED |
| 0x05510005 | S>C |  | H 0x01462580(cmp) | - | - | ConnectReward: reply/notification. Connection-time rewards. | connectreward (INFERRED) |  | D INFERRED |
| 0x05510006 | S>C |  | H 0x01462580(cmp) | - | - | ConnectReward: reply/notification. Connection-time rewards. | connectreward (INFERRED) |  | D INFERRED |
| 0x05510007 | S>C |  | H 0x01462580(cmp) | - | - | ConnectReward: reply/notification. Connection-time rewards. | connectreward (INFERRED) |  | D INFERRED |

### 0x0552 ChangeShape (12)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05520000 | S>C |  | H 0x01463f40 | - | - | ChangeShape: reply/notification. Change shape (transformation). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520001 | C>S |  | B 0x01464670 | 16 | - | ChangeShape: request. Change shape (transformation). | costume (INFERRED) (INFERRED) | S801 ChangeShape weapon appearance (W16) | D INFERRED |
| 0x05520002 | S>C |  | H 0x01463ff0 | - | - | ChangeShape: reply/notification. Change shape (transformation). Likely reply to C>S 0x05520001 (request even / reply odd convention). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520003 | C>S |  | B 0x01464ac0(factory) | 24 | - | ChangeShape: request. Change shape (transformation). | costume (INFERRED) (INFERRED) | S801 ChangeShape weapon appearance (W16) | D INFERRED |
| 0x05520004 | S>C |  | H 0x014640a0 | - | - | ChangeShape: reply/notification. Change shape (transformation). Likely reply to C>S 0x05520003 (request even / reply odd convention). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520005 | S>C |  | H 0x01464230 | - | - | ChangeShape: reply/notification. Change shape (transformation). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520006 | S>C |  | H 0x01464330 | - | +0x0 undefined4 | ChangeShape: reply/notification. Change shape (transformation). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520007 | S>C |  | H 0x01463e60(cmp) | - | - | ChangeShape: reply/notification. Change shape (transformation). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520008 | S>C |  | H 0x01463e60(cmp) | - | - | ChangeShape: reply/notification. Change shape (transformation). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520009 | S>C |  | H 0x01463e60(cmp) | - | - | ChangeShape: reply/notification. Change shape (transformation). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520010 | S>C |  | H 0x01463e60(cmp) | - | - | ChangeShape: reply/notification. Change shape (transformation). | costume (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05520011 | S>C |  | H 0x01463e60(cmp) | - | - | ChangeShape: reply/notification. Change shape (transformation). | costume (INFERRED) (INFERRED) |  | D INFERRED |

### 0x0553 ItemMunzang (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05530000 | S>C |  | H 0x0146ade0(cmp) | - | - | ItemMunzang: reply/notification. Item crest (munzang). | craft (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05530001 | C>S |  | B 0x01469d40 | 40 | +0x0 undefined2, +0x2 undefined1, +0x3 undefined4, +0x7 undefined4, +0xb undefined4, +0xf undefined4 | ItemMunzang: request. Item crest (munzang). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05530001 insert, size 0x28 (0x17bc050): +0x00 ref3 costume, +0x03 + 3*i ref3 crest for slot i (i = 0..5; 16 bytes + u16 copied from window+7..+0x18) | craft (INFERRED) (INFERRED) | S061 ItemMunzang | D INFERRED |
| 0x05530002 | S>C |  | H 0x0146b080 | - | +0x0 undefined3, +0x4 undefined3, +0x8 ushort, +0xa ushort, +0xc undefined3, +0x10 ushort | ItemMunzang: reply/notification. Item crest (munzang). Likely reply to C>S 0x05530001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S061: S>C 0x05530002, size 0x49: +0x00 ref3 costume, +0x04 + 8*i {ref3, u16 @+4, u16 … | craft (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05530003 | C>S |  | B 0x01469cf0 | 16 | - | ItemMunzang: request. Item crest (munzang). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05530003 close, size 0x10 | craft (INFERRED) (INFERRED) | S061 ItemMunzang | D INFERRED |
| 0x05530004 | S>C |  | H 0x0146ade0(cmp) | - | - | ItemMunzang: reply/notification. Item crest (munzang). Likely reply to C>S 0x05530003 (request even / reply odd convention). | craft (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05530005 | C>S |  | B 0x01469dc0 | 28 | +0x0 undefined2, +0x2 undefined1, +0x3 undefined2, +0x5 undefined1, +0x6 ptr/copy, +0xa ptr/copy | ItemMunzang: request. Item crest (munzang). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05530005 extract, size 0x1c (0x17bc0d0): +0x00 ref3 costume (window+4), +0x03 ref3 plier (window+0x19), +0x06 u8[6] slot selected flags (window+0x1c) | craft (INFERRED) (INFERRED) | S061 ItemMunzang | D INFERRED |
| 0x05530006 | S>C |  | H 0x0146ae80 | - | +0x3 undefined3, +0x1e char, +0x20 undefined4, +0x24 undefined4, +0x28 byte | ItemMunzang: reply/notification. Item crest (munzang). Likely reply to C>S 0x05530005 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S061: S>C 0x05530006, size 0x39: +0x03 ref3, +0x1e u8 (0/1 branch, UNVERIFIED: plier … | craft (INFERRED) (INFERRED) |  | D INFERRED |

### 0x0554 Title (9)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05540000 | S>C |  | H 0x0146ca40 | - | +0x0 undefined1, +0x8 undefined4, +0xc undefined2 | Title: reply/notification. Titles. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05540001 | S>C |  | H 0x0146cc90 | - | +0x0 undefined1, +0x2 undefined2, +0x8 undefined4, +0xc undefined2 | Title: reply/notification. Titles. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05540002 | C>S |  | B 0x0146d350; B 0x0146d4e0 | 20 | +0x0 undefined1 | Title: request. Titles. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05540002 (builders 0x17bf660 / 0x17bf7f0): size 0x14, u8 titleIndex @0x10 (0xff = take title off). | module only (no command type) (INFERRED) | S110 Title | D INFERRED |
| 0x05540003 | S>C |  | H 0x0146c900 | - | - | Title: reply/notification. Titles. Likely reply to C>S 0x05540002 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S110: S>C 0x05540003 (case @switch 0x17beb5b): u8 result @0x10 (0 ok; 1 -> msg 0xaf2:5; 2 -> msg 0xaf2:4), | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05540004 | S>C |  | H 0x0146cc10 | - | - | Title: reply/notification. Titles. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05540005 | S>C |  | H 0x0146d180 | - | +0x0 undefined1 | Title: reply/notification. Titles. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05540006 | S>C |  | H 0x0146d220 | - | +0x16 undefined1, +0x18 undefined4, +0x1c undefined4 | Title: reply/notification. Titles. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05540007 | S>C |  | H 0x0146c840(cmp) | - | - | Title: reply/notification. Titles. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05540008 | S>C |  | H 0x0146c840(cmp) | - | - | Title: reply/notification. Titles. | module only (no command type) (INFERRED) |  | D INFERRED |

### 0x0555 Product (crafting) (18)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05550001 | S>C |  | H 0x01472200(cmp) | - | - | Product (crafting): reply/notification. Production learn/catalyst. | production, craft (INFERRED) |  | D INFERRED |
| 0x05550002 | C>S |  | B 0x00cbadf0(factory) | 24 | - | Product (crafting): request. Production learn/catalyst. | production, craft (INFERRED) | S956 CraftWire | D INFERRED |
| 0x05550003 | S>C |  | H 0x01472560 | - | +0x0 char, +0x4 undefined1, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550002 (request even / reply odd convention). | production, craft (INFERRED) |  | D INFERRED |
| 0x05550004 | C>S |  | B 0x00cbe890(factory) | 20 | - | Product (crafting): request. Production learn/catalyst. | production, craft (INFERRED) | S956 CraftWire | D INFERRED |
| 0x05550005 | S>C |  | H 0x01472960 | - | +0x0 undefined1, +0x4 undefined4, +0x8 char | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550004 (request even / reply odd convention). | production, craft (INFERRED) |  | D INFERRED |
| 0x05550006 | C>S |  | B 0x00cbf340 | 20 | +0x0 undefined1 | Product (crafting): request. Production learn/catalyst. | production, craft (INFERRED) | S956 CraftWire | D INFERRED |
| 0x05550007 | S>C |  | H 0x01472400 | - | +0x0 char, +0x1 undefined1, +0x8 undefined4, +0xc undefined4, +0x10 undefined1, +0x14 undefined4 | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550006 (request even / reply odd convention). | production, craft (INFERRED) |  | D INFERRED |
| 0x05550008 | C>S |  | B 0x00cbddf0 | 20 | +0x0 short, +0x2 char | Product (crafting): request. Production learn/catalyst. | production, craft (INFERRED) | S956 CraftWire | D INFERRED |
| 0x05550009 | S>C |  | H 0x014722f0 | - | +0x0 undefined1, +0x1 char | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550008 (request even / reply odd convention). | production, craft (INFERRED) |  | D INFERRED |
| 0x0555000a | C>S |  | B 0x00cc0430 | 24 | +0x0 undefined1, +0x1 short, +0x3 char, +0x4 undefined1 | Product (crafting): request. Production learn/catalyst. | production, craft (INFERRED) | S956 CraftWire | D INFERRED |
| 0x0555000b | S>C |  | H 0x014727a0 | - | +0x0 undefined1, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 char | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x0555000a (request even / reply odd convention). | production, craft (INFERRED) |  | D INFERRED |
| 0x0555000c | S>C |  | H 0x01472200(cmp) | - | - | Product (crafting): reply/notification. Production learn/catalyst. | production, craft (INFERRED) |  | D INFERRED |
| 0x0555000d | C>S |  | B 0x00cbf090 | 16 | - | Product (crafting): request. Production learn/catalyst. | production, craft (INFERRED) | S956 CraftWire | D INFERRED |
| 0x0555000e | S>C |  | H 0x01472200(cmp) | - | - | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x0555000d (request even / reply odd convention). | production, craft (INFERRED) |  | D INFERRED |
| 0x0555000f | S>C |  | H 0x01472200(cmp) | - | - | Product (crafting): reply/notification. Production learn/catalyst. | production, craft (INFERRED) |  | D INFERRED |
| 0x05550010 | S>C |  | H 0x01472d80 | - | +0x0 int | Product (crafting): reply/notification. Production learn/catalyst. | production, craft (INFERRED) |  | D INFERRED |
| 0x05550011 | C>S |  | B 0x00cbe480 | 20 | +0x0 undefined1 | Product (crafting): request. Production learn/catalyst. | production, craft (INFERRED) | S956 CraftWire | D INFERRED |
| 0x05550012 | S>C |  | H 0x01472b10 | - | +0x0 char, +0x1 undefined1, +0x4 undefined4 | Product (crafting): reply/notification. Production learn/catalyst. Likely reply to C>S 0x05550011 (request even / reply odd convention). | production, craft (INFERRED) |  | D INFERRED |

### 0x0556 CostumeWardrobe (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05560000 | C>S |  | B 0x01473a90 | 20 | +0x0 undefined2, +0x2 undefined1 | CostumeWardrobe: request. Costume wardrobe. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05560000, size 0x14 (0x17c5db0): +0x00 ref3 costume (bag) | costume (INFERRED) | S029 CostumeWardrobe | D INFERRED |
| 0x05560001 | S>C |  | H 0x01473e20(cmp) | - | - | CostumeWardrobe: reply/notification. Costume wardrobe. Likely reply to C>S 0x05560000 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S029: S>C 0x05560001 (cmp 0x17c6187 -> 0x17c61a0), size 0x11: +0x00 u8 result (handle… | costume (INFERRED) |  | D INFERRED |

### 0x0561 Dekaron provider (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05610000 | C>S |  | B 0x008ad950; B 0x014d2b70 | 528 | +0x0 ptr/copy | Dekaron provider: request. Dekaron misc. | MISSING |  | D INFERRED |
| 0x05610001 | S>C |  | H 0x014cebc0 | - | +0x0 undefined4, +0x4 undefined4, +0x28 int, +0x2c undefined4 | Dekaron provider: reply/notification. Dekaron misc. Likely reply to C>S 0x05610000 (request even / reply odd convention). | MISSING |  | D INFERRED |
| 0x05610002 | S>C |  | H 0x014ceae0 | - | +0x0 undefined1 | Dekaron provider: reply/notification. Dekaron misc. | MISSING |  | D INFERRED |
| 0x05610003 | S>C |  | H 0x014ced30; H 0x014d4180 | - | +0x0 byte, +0x4 ptr, +0xc ptr | Dekaron provider: reply/notification. Dekaron misc. | MISSING |  | D INFERRED |

### 0x0562 PrivateSupply / FieldBossSupply (9)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05620001 | C>S |  | B 0x01446350 | 16 | - | PrivateSupply / FieldBossSupply: request. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05620001 spin  -> S>C 0x05620002 (0x17997f0): u8 result @+0 (switch 0..9), u32 @+4, @+8, @+0xc | supply (INFERRED) | S087 PrivateSupply | D INFERRED |
| 0x05620002 | S>C |  | H 0x01446cb0(cmp) | - | - | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Likely reply to C>S 0x05620001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S087: 0x05620001 spin  -> S>C 0x05620002 (0x17997… | supply (INFERRED) |  | D INFERRED |
| 0x05620003 | S>C |  | H 0x01446e00 | - | +0x0 undefined1 | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): S087: 0x05620006 mix   -> S>C 0x05620003 (0x17998a0): u8 result @+0 | supply (INFERRED) |  | D INFERRED |
| 0x05620004 | C>S |  | B 0x01446300; B 0x01497910 | 16 | - | PrivateSupply / FieldBossSupply: request. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05620004 state (sent from 0x1798da0 / 0x17991f0 / 0x17e9ba0) -> S>C 0x05620005 (0x17999f0), body 0x5c: | supply (INFERRED) | S087 PrivateSupply | D INFERRED |
| 0x05620005 | S>C |  | H 0x01446f50 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Likely reply to C>S 0x05620004 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S087: 0x05620004 state (sent from 0x1798da0 / 0x1… | supply (INFERRED) |  | D INFERRED |
| 0x05620006 | C>S |  | B 0x014463c0 | 16 | - | PrivateSupply / FieldBossSupply: request. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05620006 mix   -> S>C 0x05620003 (0x17998a0): u8 result @+0 | supply (INFERRED) | S087 PrivateSupply | D INFERRED |
| 0x05620007 | S>C |  | H 0x01446cb0(cmp) | - | - | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Likely reply to C>S 0x05620006 (request even / reply odd convention). | supply (INFERRED) |  | D INFERRED |
| 0x05620008 | C>S |  | B 0x01446410 | 16 | - | PrivateSupply / FieldBossSupply: request. Private supply and field boss supply. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05620008 close (no reply) | supply (INFERRED) | S087 PrivateSupply | D INFERRED |
| 0x05620009 | S>C |  | H 0x01446cb0(cmp) | - | - | PrivateSupply / FieldBossSupply: reply/notification. Private supply and field boss supply. Likely reply to C>S 0x05620008 (request even / reply odd convention). | supply (INFERRED) |  | D INFERRED |

### 0x0564 UpgradeWing (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05640000 | S>C |  | H 0x0147c800(cmp) | - | - | UpgradeWing: reply/notification. Wing upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): S121: S>C 0x05640000 open, no body (case 0x17ceac6 -> handler 0x17ceb10) | wing (INFERRED) |  | D INFERRED |
| 0x05640001 | C>S |  | B 0x0147c460 | 24 | +0x0 int, +0x4 undefined2, +0x6 undefined1 | UpgradeWing: request. Wing upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05640001 request, size 0x18 (builder 0x17ce700): +0x00 u32 [window+8] (UNVERIFIED npc handle/context), +0x04 ref3 wing | wing (INFERRED) | S121 UpgradeWing | D INFERRED |
| 0x05640002 | S>C |  | H 0x0147c800(cmp) | - | - | UpgradeWing: reply/notification. Wing upgrade. Likely reply to C>S 0x05640001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S121: S>C 0x05640002 result (handler 0x17ceb50), size 0x1e (= last field read; exact size UNV… | wing (INFERRED) |  | D INFERRED |
| 0x05640003 | C>S |  | B 0x0147c410 | 16 | - | UpgradeWing: request. Wing upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05640003 close, size 0x10 (0x17ce690) | wing (INFERRED) | S121 UpgradeWing | D INFERRED |
| 0x05640004 | S>C |  | H 0x0147c800(cmp) | - | - | UpgradeWing: reply/notification. Wing upgrade. Likely reply to C>S 0x05640003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S121: S>C 0x05640004 close window (case 0x17cead1).  0x05640005 (0x17cec60: u8 +4, u32 +0) UN… | wing (INFERRED) |  | D INFERRED |
| 0x05640005 | S>C |  | H 0x0147c9c0 | - | +0x0 undefined4, +0x4 char | UpgradeWing: reply/notification. Wing upgrade. | wing (INFERRED) |  | D INFERRED |

### 0x0565 UpgradeAccessory / MaterialExchange (9)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05650000 | S>C |  | H 0x0147ee20 | - | - | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): S118: S>C 0x05650000 open, no body (case 0x17d105e -> handler 0x17d10c0) | socket, exchangebuy (INFERRED) |  | D INFERRED |
| 0x05650001 | C>S |  | B 0x0147e9b0 | 32 | +0x0 int, +0x4 undefined4, +0x8 undefined4, +0xc undefined2, +0xe undefined1 | UpgradeAccessory / MaterialExchange: request. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05650001 request, size 0x20 (builder 0x17d0c50): | socket, exchangebuy (INFERRED) | S118 UpgradeAccessory | D INFERRED |
| 0x05650002 | S>C |  | H 0x0147ee90 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined1 | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Likely reply to C>S 0x05650001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S118: S>C 0x05650002 result (handler 0x17d… | socket, exchangebuy (INFERRED) |  | D INFERRED |
| 0x05650003 | C>S |  | B 0x0147e960 | 16 | - | UpgradeAccessory / MaterialExchange: request. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05650003 close, size 0x10 (0x17d0c00) | socket, exchangebuy (INFERRED) | S118 UpgradeAccessory | D INFERRED |
| 0x05650004 | S>C |  | H 0x0147ee50 | - | - | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Likely reply to C>S 0x05650003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S118: S>C 0x05650004 close (case 0x17d106c… | socket, exchangebuy (INFERRED) |  | D INFERRED |
| 0x05650005 | S>C |  | H 0x0147f0f0 | - | +0x0 undefined4, +0x4 char | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. | socket, exchangebuy (INFERRED) |  | D INFERRED |
| 0x05650006 | C>S |  | B 0x0147ea50; B 0x014c2d30 | 24 | +0x0 undefined4, +0x4 undefined2 | UpgradeAccessory / MaterialExchange: request. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05650006, size 0x18 (0x17d0cf0 / 0x1813e30): +0x00 u32, +0x04 u16   (UNVERIFIED: row, count) | socket, exchangebuy (INFERRED) | S065 MaterialExchange | D INFERRED |
| 0x05650007 | S>C |  | H 0x0147f1b0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined1 | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Likely reply to C>S 0x05650006 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S065: S>C 0x05650007 (accessory window cas… | socket, exchangebuy (INFERRED) |  | D INFERRED |
| 0x05650008 | S>C |  | H 0x014c2fb0(cmp) | - | - | UpgradeAccessory / MaterialExchange: reply/notification. Accessory upgrade and material exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): S065: S>C 0x05650008 open (cmp 0x18140a8 -> window [0x22c17cc] vf+8 with u16 @+0x04; UNVERIFIED: +0x00 u32 npc h… | socket, exchangebuy (INFERRED) |  | D INFERRED |

### 0x0566 ForgottenShipwreck (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05660010 | S>C |  | H 0x0147fde0(cmp) | - | - | ForgottenShipwreck: reply/notification. Forgotten Shipwreck event. | event (INFERRED) |  | D INFERRED |
| 0x05660011 | C>S |  | B 0x0147f9b0 | 20 | +0x0 undefined1 | ForgottenShipwreck: request. Forgotten Shipwreck event. | event (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |
| 0x05660012 | S>C |  | H 0x0147fde0(cmp) | - | - | ForgottenShipwreck: reply/notification. Forgotten Shipwreck event. Likely reply to C>S 0x05660011 (request even / reply odd convention). | event (INFERRED) |  | D INFERRED |
| 0x05660013 | S>C |  | H 0x0147fde0(cmp) | - | - | ForgottenShipwreck: reply/notification. Forgotten Shipwreck event. | event (INFERRED) |  | D INFERRED |

### 0x0567 AttendanceReward (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05670000 | C>S |  | B 0x014812f0 | 16 | - | AttendanceReward: request. Attendance rewards. | connectreward (INFERRED) | S970 AttendanceWire | D INFERRED |
| 0x05670001 | S>C |  | H 0x01481ab0 | - | +0x0 char, +0x1 char, +0x2 char, +0x3 undefined1, +0x4 undefined4 | AttendanceReward: reply/notification. Attendance rewards. Likely reply to C>S 0x05670000 (request even / reply odd convention). | connectreward (INFERRED) |  | D INFERRED |
| 0x05670002 | C>S |  | B 0x01481460 | 20 | - | AttendanceReward: request. Attendance rewards. | connectreward (INFERRED) | S970 AttendanceWire | D INFERRED |
| 0x05670003 | S>C |  | H 0x01481c20 | - | +0x2 undefined1 | AttendanceReward: reply/notification. Attendance rewards. Likely reply to C>S 0x05670002 (request even / reply odd convention). | connectreward (INFERRED) |  | D INFERRED |
| 0x05670004 | S>C |  | H 0x01481a10(cmp) | - | - | AttendanceReward: reply/notification. Attendance rewards. | connectreward (INFERRED) |  | D INFERRED |
| 0x05670005 | S>C |  | H 0x01481a10(cmp) | - | - | AttendanceReward: reply/notification. Attendance rewards. | connectreward (INFERRED) |  | D INFERRED |
| 0x05670006 | S>C |  | H 0x01481dd0 | - | - | AttendanceReward: reply/notification. Attendance rewards. | connectreward (INFERRED) |  | D INFERRED |

### 0x0568 UpgradeCostume (13)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05680000 | S>C |  | H 0x01486960(cmp) | - | - | UpgradeCostume: reply/notification. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): S119: S>C 0x05680000 open (case 0x17d8c27, no body). NPC job 124 COSTUME_CYCLE (engine src\systems\mounts\windows.js; UNVERIFIED vs Global npc.csv). | costume (INFERRED) |  | D INFERRED |
| 0x05680001 | C>S |  | B 0x01485a50 | 100 | +0x0 int, +0x4 undefined4, +0x9 ptr/copy | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680001 dismantle, size 0x64 (0x17d7cf0): +0x00 u32 count, +0x04 u32 window field this+8 (UNVERIFIED: npc/window id), | costume (INFERRED) | S119 UpgradeCostume | D INFERRED |
| 0x05680002 | S>C |  | H 0x01486ae0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined1 | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680001 (request even / reply odd convention). | costume (INFERRED) |  | D INFERRED |
| 0x05680003 | C>S |  | B 0x01485940 | 16 | - | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680003, size 0x10 (0x17d7be0): no body (UNVERIFIED: close/reset) -> S>C 0x05680004 (0x17d8ce0 resets three UI slots; no body read) | costume (INFERRED) | S119 UpgradeCostume | D INFERRED |
| 0x05680004 | S>C |  | H 0x01486a40 | - | - | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S119: C>S 0x05680003, size 0x10 (0x17d7be0): no body (UNVERIFIED: close/reset) -> S>C 0… | costume (INFERRED) |  | D INFERRED |
| 0x05680005 | C>S |  | B 0x014857e0 | 24 | +0x0 undefined4, +0x4 undefined4 | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680005 sew, size 0x18 (0x17d7a80): +0x00 u32 this+8, +0x04 u32 arg (UNVERIFIED: chosen appearance item index) | costume (INFERRED) | S119 UpgradeCostume | D INFERRED |
| 0x05680006 | S>C |  | H 0x01486f00 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined1 | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680005 (request even / reply odd convention). | costume (INFERRED) |  | D INFERRED |
| 0x05680007 | C>S |  | B 0x01485850 | 24 | +0x4 undefined1, +0x5 undefined1, +0x6 undefined1 | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680007 options, size 0x18 (0x17d7af0): +0x04 ref3 costume (getter +4/+5/+6), +0x00 u32 left 0 | costume (INFERRED) | S119 UpgradeCostume | D INFERRED |
| 0x05680008 | S>C |  | H 0x01486cf0 | - | +0x0 undefined4, +0x4 undefined4, +0xb undefined1, +0xc ptr, +0x1c undefined1 | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680007 (request even / reply odd convention). | costume (INFERRED) |  | D INFERRED |
| 0x05680009 | C>S |  | B 0x01485990 | 28 | +0x0 undefined4, +0x4 undefined4, +0x8 short, +0xa undefined1 | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05680009 appearance, size 0x1c (0x17d7c30): +0x00 u32 arg (UNVERIFIED: appearance item index), +0x04 u32 0, +0x08 ref3 costume | costume (INFERRED) | S119 UpgradeCostume | D INFERRED |
| 0x0568000a | S>C |  | H 0x014870d0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined1, +0xc undefined4 | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x05680009 (request even / reply odd convention). | costume (INFERRED) |  | D INFERRED |
| 0x0568000e | C>S |  | B 0x01485ec0 | 24 | +0x0 undefined4, +0x4 undefined4 | UpgradeCostume: request. Costume upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x0568000e fabric exchange, size 0x18 (0x17d8160): +0x00 u32 arg (UNVERIFIED: count), +0x04 u32 this+8 | costume (INFERRED) | S119 UpgradeCostume | D INFERRED |
| 0x0568000f | S>C |  | H 0x01487390 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined1 | UpgradeCostume: reply/notification. Costume upgrade. Likely reply to C>S 0x0568000e (request even / reply odd convention). | costume (INFERRED) |  | D INFERRED |

### 0x0569 NPC dialog / creature (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05690000 | S>C |  | H 0x008e7370 | - | +0x0 int | NPC dialog / creature: reply/notification. NPC dialog and creature events. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05690003 | C>S |  | B 0x00869fe0(factory); B 0x012db1c0 | 24 | - | NPC dialog / creature: request. NPC dialog and creature events. | module only (no command type) (INFERRED) | S034 Dungeon trigger scene and use (partial) | D INFERRED |
| 0x05690004 | S>C |  | H 0x008e2c20(cmp) | - | - | NPC dialog / creature: reply/notification. NPC dialog and creature events. Likely reply to C>S 0x05690003 (request even / reply odd convention). | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05690005 | S>C |  | H 0x008e2c20(cmp) | - | - | NPC dialog / creature: reply/notification. NPC dialog and creature events. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05690006 | C>S |  | B 0x008c2d60 | 24 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined1, +0x7 undefined1 | NPC dialog / creature: request. NPC dialog and creature events. | module only (no command type) (INFERRED) | S954 NPCDialogWire | D INFERRED |
| 0x05690007 | C>S |  | B 0x008d8b20(factory) | 24 | - | NPC dialog / creature: request. NPC dialog and creature events. | module only (no command type) (INFERRED) | S954 NPCDialogWire | D INFERRED |
| 0x05690008 | S>C |  | H 0x008e2c20(cmp) | - | - | NPC dialog / creature: reply/notification. NPC dialog and creature events. Likely reply to C>S 0x05690007 (request even / reply odd convention). | module only (no command type) (INFERRED) |  | D INFERRED |

### 0x0570 UpgradeHelmet (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05700000 | S>C |  | H 0x0148a7a0(cmp) | - | - | UpgradeHelmet: reply/notification. Helmet upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): S120: S>C 0x05700000 open, no body (case 0x17dca66 -> handler 0x17dcaa0) | socket (INFERRED) |  | D INFERRED |
| 0x05700001 | C>S |  | B 0x0148a340 | 24 | +0x0 int, +0x4 undefined2, +0x6 undefined1 | UpgradeHelmet: request. Helmet upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05700001 request, size 0x18 (builder 0x17dc5e0): +0x00 u32 [window+8] (UNVERIFIED context), +0x04 ref3 helmet | socket (INFERRED) | S120 UpgradeHelmet | D INFERRED |
| 0x05700002 | S>C |  | H 0x0148a7a0(cmp) | - | - | UpgradeHelmet: reply/notification. Helmet upgrade. Likely reply to C>S 0x05700001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S120: S>C 0x05700002 result (handler 0x17dcae0), size 0x20 (= last field read; exact serv… | socket (INFERRED) |  | D INFERRED |
| 0x05700003 | C>S |  | B 0x0148a2f0 | 16 | - | UpgradeHelmet: request. Helmet upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05700003 close, size 0x10 (0x17dc570) | socket (INFERRED) | S120 UpgradeHelmet | D INFERRED |
| 0x05700004 | S>C |  | H 0x0148a7a0(cmp) | - | - | UpgradeHelmet: reply/notification. Helmet upgrade. Likely reply to C>S 0x05700003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S120: S>C 0x05700004 close window (case 0x17dca71) | socket (INFERRED) |  | D INFERRED |
| 0x05700005 | S>C |  | H 0x0148a7a0(cmp) | - | - | UpgradeHelmet: reply/notification. Helmet upgrade. | socket (INFERRED) |  | D INFERRED |

### 0x0571 (unattributed) (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05710001 | S>C |  | H 0x01490c40(cmp) | - | - | (unattributed): reply/notification. Unattributed family. | MISSING |  | D INFERRED |

### 0x0572 WingShapeChange (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05720000 | S>C |  | H 0x01491640(cmp) | - | - | WingShapeChange: reply/notification. Wing shape change. | wing (INFERRED) |  | D INFERRED |
| 0x05720001 | C>S |  | B 0x01492a60 | 28 | +0x0 undefined4, +0x4 undefined4, +0x8 short, +0xa undefined1 | WingShapeChange: request. Wing shape change. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05720001 change, size 0x1c (builder 0x17e4cf0): +0x00 u32 = 0, +0x04 u32 = builder arg (UNVERIFIED: chosen appearance item index), +0x08 ref3 wing | wing (INFERRED) | S126 WingShapeChange | D INFERRED |
| 0x05720002 | S>C |  | H 0x01491700 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined1 | WingShapeChange: reply/notification. Wing shape change. Likely reply to C>S 0x05720001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S126: S>C 0x05720002 / 0x05740001, size 0x1d: +0x00 i64 (dwords +0x10/+0x14 handed t… | wing (INFERRED) |  | D INFERRED |
| 0x05720003 | C>S |  | B 0x01492a10 | 16 | - | WingShapeChange: request. Wing shape change. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05720003 close, size 0x10 (0x17e4ca0) | wing (INFERRED) | S126 WingShapeChange | D INFERRED |
| 0x05720004 | S>C |  | H 0x014916c0 | - | - | WingShapeChange: reply/notification. Wing shape change. Likely reply to C>S 0x05720003 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |

### 0x0574 WingShapeChange (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05740000 | C>S |  | B 0x01492b00 | 28 | +0x0 undefined4, +0x4 undefined4, +0x8 short, +0xa undefined1 | WingShapeChange: request. Wing shape change. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05740000 restore, size 0x1c (builder 0x17e4d90), same layout | wing (INFERRED) | S126 WingShapeChange | D INFERRED |
| 0x05740001 | S>C |  | H 0x014918e0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined1 | WingShapeChange: reply/notification. Wing shape change. Likely reply to C>S 0x05740000 (request even / reply odd convention). | wing (INFERRED) |  | D INFERRED |

### 0x0575 Quest (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05750000 | S>C |  | H 0x012ca5a0 | - | +0x0 undefined4 | Quest: reply/notification. Quest UI. | quest (INFERRED) |  | D INFERRED |
| 0x05750001 | C>S |  | B 0x012c8dd0 | 24 | +0x0 undefined4, +0x4 short | Quest: request. Quest UI. | quest (INFERRED) | S800 Quest windows 0x36/0x93 accept (W16) | D INFERRED |
| 0x05750002 | S>C |  | H 0x012ca5c0 | - | +0x0 char | Quest: reply/notification. Quest UI. Likely reply to C>S 0x05750001 (request even / reply odd convention). | quest (INFERRED) |  | D INFERRED |
| 0x05750004 | S>C |  | H 0x012c9730(cmp) | - | - | Quest: reply/notification. Quest UI. | quest (INFERRED) |  | D INFERRED |

### 0x0576 FieldBossSupply (8)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05760001 | C>S |  | B 0x01497960 | 20 | +0x0 undefined1 | FieldBossSupply: request. Field boss supply. | supply (INFERRED) | S962 FieldBossSupplyWire | D INFERRED |
| 0x05760002 | S>C |  | H 0x014982e0 | - | - | FieldBossSupply: reply/notification. Field boss supply. Likely reply to C>S 0x05760001 (request even / reply odd convention). | supply (INFERRED) |  | D INFERRED |
| 0x05760003 | S>C |  | H 0x01498390 | - | +0x0 undefined1 | FieldBossSupply: reply/notification. Field boss supply. | supply (INFERRED) |  | D INFERRED |
| 0x05760005 | S>C |  | H 0x01498620 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | FieldBossSupply: reply/notification. Field boss supply. | supply (INFERRED) |  | D INFERRED |
| 0x05760006 | C>S |  | B 0x014979e0 | 16 | - | FieldBossSupply: request. Field boss supply. | supply (INFERRED) | S962 FieldBossSupplyWire | D+O INFERRED |
| 0x05760007 | S>C |  | H 0x014984d0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | FieldBossSupply: reply/notification. Field boss supply. Likely reply to C>S 0x05760006 (request even / reply odd convention). | supply (INFERRED) |  | D INFERRED |
| 0x05760008 | C>S |  | B 0x01497a30 | 16 | - | FieldBossSupply: request. Field boss supply. | supply (INFERRED) | S962 FieldBossSupplyWire | D INFERRED |
| 0x05760009 | S>C |  | H 0x01498230(cmp) | - | - | FieldBossSupply: reply/notification. Field boss supply. Likely reply to C>S 0x05760008 (request even / reply odd convention). | supply (INFERRED) |  | D INFERRED |

### 0x0577 DKRPvPBattle (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05770001 | C>S |  | B 0x014a6280 | 76,232 | +0x36 undefined2, +0x38 undefined2 | DKRPvPBattle: request. DKR PvP battle. | dkr (INFERRED) | S951 DKRPvPWire | D INFERRED |
| 0x05770003 | C>S |  | B 0x014a6280 | 76,232 | +0x36 undefined2, +0x38 undefined2 | DKRPvPBattle: request. DKR PvP battle. | dkr (INFERRED) | S951 DKRPvPWire | D INFERRED |
| 0x05770005 | C>S |  | B 0x014a6460 | 28 | +0x0 ptr/copy | DKRPvPBattle: request. DKR PvP battle. | dkr (INFERRED) | S951 DKRPvPWire | D INFERRED |

### 0x0578 Equipment presets / Inven states (15)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05780000 | C>S |  | B 0x01518580(factory) | 20 | - | Equipment presets / Inven states: request. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) | S641 wire-W18-presets-select | D INFERRED |
| 0x05780001 | C>S |  | B 0x01518f30(factory) | 16 | - | Equipment presets / Inven states: request. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) | S950 ChatCommandWire | D INFERRED |
| 0x05780002 | S>C |  | H 0x014f44a0 | - | +0x0 char | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x05780001 (request even / reply odd convention). | preset, equipswap, clonepreset (INFERRED) |  | D INFERRED |
| 0x05780003 | C>S |  | B 0x01295010(factory) | 28 | - | Equipment presets / Inven states: request. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) | S055 Native equipment preset custody | D+O INFERRED |
| 0x05780004 | S>C |  | H 0x014f4880 | obs 30 | +0x0 char, +0x1 undefined3, +0x8 byte | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x05780003 (request even / reply odd convention). | preset, equipswap, clonepreset (INFERRED) |  | D+O INFERRED |
| 0x05780009 | C>S |  | B 0x01518400(factory) | 24 | - | Equipment presets / Inven states: request. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) | S055 Native equipment preset custody | D+O INFERRED |
| 0x0578000a | S>C |  | H 0x014f45a0 | obs 32 | +0x0 char, +0x9 undefined4, +0xd undefined1 | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x05780009 (request even / reply odd convention). | preset, equipswap, clonepreset (INFERRED) |  | D+O INFERRED |
| 0x0578000b | C>S |  | B 0x01264db0(factory) | 24 | - | Equipment presets / Inven states: request. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) | S950 ChatCommandWire | D INFERRED |
| 0x0578000c | S>C |  | H 0x014f4c50 | - | +0x0 char, +0x6 char | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x0578000b (request even / reply odd convention). | preset, equipswap, clonepreset (INFERRED) |  | D INFERRED |
| 0x0578000d | S>C |  | H 0x014f54b0 | - | +0x0 char | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) |  | D INFERRED |
| 0x0578000e | C>S |  | B 0x01519710; B 0x014e6650 | 16 | - | Equipment presets / Inven states: request. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) | S950 ChatCommandWire | D INFERRED |
| 0x0578000f | S>C |  | H 0x014f5060 | - | +0x0 char | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x0578000e (request even / reply odd convention). | preset, equipswap, clonepreset (INFERRED) |  | D INFERRED |
| 0x05780013 | S>C |  | H 0x014f5190 | - | +0x0 char, +0x1 undefined1 | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) |  | D INFERRED |
| 0x05780014 | C>S |  | B 0x008896d0(factory) | 16 | - | Equipment presets / Inven states: request. Equipment preset save/apply. | preset, equipswap, clonepreset (INFERRED) | S950 ChatCommandWire | D INFERRED |
| 0x05780015 | S>C |  | H 0x014f5570 | - | - | Equipment presets / Inven states: reply/notification. Equipment preset save/apply. Likely reply to C>S 0x05780014 (request even / reply odd convention). | preset, equipswap, clonepreset (INFERRED) |  | D INFERRED |

### 0x0580 OXQuiz (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05800000 | S>C |  | H 0x014ab720 | - | +0x0 short, +0x200 undefined1 | OXQuiz: reply/notification. OX quiz event. | oxquiz (INFERRED) |  | D INFERRED |
| 0x05800001 | S>C |  | H 0x014ab670(cmp) | - | - | OXQuiz: reply/notification. OX quiz event. | oxquiz (INFERRED) |  | D INFERRED |
| 0x05800002 | S>C |  | H 0x014ab8b0 | - | +0x0 short | OXQuiz: reply/notification. OX quiz event. | oxquiz (INFERRED) |  | D INFERRED |

### 0x0581 Pet shape change/restore/disassemble (10)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05810000 | S>C |  | H 0x01263680; H 0x01263bc0(cmp) | - | - | Pet shape change/restore/disassemble: reply/notification. Pet shape services. | petcombine (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05810001 | both |  | B 0x01263c20; H 0x01263bc0(cmp); H 0x01263bc0(cmp) | 36 | +0x4 undefined4, +0x8 undefined2, +0xa undefined1, +0xc undefined4, +0x10 undefined4 | Pet shape change/restore/disassemble: request and reply share this opcode. Pet shape services. | petcombine (INFERRED) (INFERRED) | S805 P8 pet/quest-store refusals + window close (W16) | D INFERRED |
| 0x05810002 | S>C |  | H 0x01263bc0(cmp); H 0x01263bc0(cmp) | - | - | Pet shape change/restore/disassemble: reply/notification. Pet shape services. Likely reply to C>S 0x05810001 (request even / reply odd convention). | petcombine (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05810003 | both |  | B 0x00d33230; B 0x00d35d20; H 0x01263bc0(cmp); H 0x01263bc0(cmp) | 16 | - | Pet shape change/restore/disassemble: request and reply share this opcode. Pet shape services. | petcombine (INFERRED) (INFERRED) | S805 P8 pet/quest-store refusals + window close (W16) | D INFERRED |
| 0x05810004 | S>C |  | H 0x01263700; H 0x01263bc0(cmp) | - | - | Pet shape change/restore/disassemble: reply/notification. Pet shape services. Likely reply to C>S 0x05810003 (request even / reply odd convention). | petcombine (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05810005 | both |  | B 0x00d374b0; H 0x01263bc0(cmp); H 0x01263bc0(cmp) | 260 | +0x0 uint, +0x4 ptr/copy | Pet shape change/restore/disassemble: request and reply share this opcode. Pet shape services. | petcombine (INFERRED) (INFERRED) | S805 P8 pet/quest-store refusals + window close (W16) | D INFERRED |
| 0x05810006 | S>C |  | H 0x00740450; H 0x01263bc0(cmp) | - | - | Pet shape change/restore/disassemble: reply/notification. Pet shape services. Likely reply to C>S 0x05810005 (request even / reply odd convention). | petcombine (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05810007 | S>C |  | H 0x01263bc0(cmp) | - | - | Pet shape change/restore/disassemble: reply/notification. Pet shape services. | petcombine (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05810008 | S>C |  | H 0x01263bc0(cmp) | - | - | Pet shape change/restore/disassemble: reply/notification. Pet shape services. | petcombine (INFERRED) (INFERRED) |  | D INFERRED |
| 0x05810009 | S>C |  | H 0x01263bc0(cmp) | - | - | Pet shape change/restore/disassemble: reply/notification. Pet shape services. | petcombine (INFERRED) (INFERRED) |  | D INFERRED |

### 0x0582 Exchange store (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05820000 | S>C |  | H 0x01248b90 | - | - | Exchange store: reply/notification. Exchange store / coin shop. | exchangebuy, coinshop (INFERRED) |  | D INFERRED |
| 0x05820001 | S>C |  | H 0x01248dd0(cmp) | - | - | Exchange store: reply/notification. Exchange store / coin shop. | exchangebuy, coinshop (INFERRED) |  | D INFERRED |
| 0x05820002 | C>S |  | B 0x00d470a0 | 16 | - | Exchange store: request. Exchange store / coin shop. | exchangebuy, coinshop (INFERRED) | S805 P8 pet/quest-store refusals + window close (W16) | D INFERRED |
| 0x05820003 | C>S |  | B 0x01248e60 | 28 | +0x0 undefined2, +0x4 undefined4, +0x8 undefined2 | Exchange store: request. Exchange store / coin shop. | exchangebuy, coinshop (INFERRED) | S805 P8 pet/quest-store refusals + window close (W16) | D INFERRED |
| 0x05820004 | S>C |  | H 0x00740450 | - | - | Exchange store: reply/notification. Exchange store / coin shop. Likely reply to C>S 0x05820003 (request even / reply odd convention). | exchangebuy, coinshop (INFERRED) |  | D INFERRED |
| 0x05820005 | C>S |  | B 0x01248b90 | 20 | +0x0 undefined2 | Exchange store: request. Exchange store / coin shop. | exchangebuy, coinshop (INFERRED) |  | D INFERRED |
| 0x05820006 | S>C |  | H 0x01248dd0(cmp) | - | - | Exchange store: reply/notification. Exchange store / coin shop. Likely reply to C>S 0x05820005 (request even / reply odd convention). | exchangebuy, coinshop (INFERRED) |  | D INFERRED |

### 0x0583 DekaPass (11)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05830000 | C>S |  | B 0x0123b370 | 16 | - | DekaPass: request. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05830000 open / pass info, no body, no lock (0x159ea70; callers AlarmWnd 0x10ef900 and the 'dekapass' chat command 0xc48960) | module only (no command type) (INFERRED) | S129 DekaPass | D+O INFERRED |
| 0x05830001 | S>C |  | H 0x00740450; H 0x010ab960 | - | - | DekaPass: reply/notification. DekaPass battle pass. Likely reply to C>S 0x05830000 (request even / reply odd convention). | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05830002 | both |  | B 0x0123b3c0; H 0x0123b2f0(cmp); H 0x0123b2f0(cmp) | 16 | - | DekaPass: request and reply share this opcode. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05830002 mission list, no body, no lock (0x159eac0; btn_missionlist in CDekaPassWnd click 0x10eac30) | module only (no command type) (INFERRED) | S129 DekaPass | D INFERRED |
| 0x05830003 | S>C |  | H 0x00740450; H 0x0123b2f0(cmp) | - | - | DekaPass: reply/notification. DekaPass battle pass. Likely reply to C>S 0x05830002 (request even / reply odd convention). | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05830004 | C>S |  | B 0x0123b410 | 20 | +0x0 ushort | DekaPass: request. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05830004 claim one, size 0x14, takes request lock 0 (0x159eb10): +0 u8 kind (0 = btn_normal_k, 1 = btn_premium_k), +1 u8 level | module only (no command type) (INFERRED) | S129 DekaPass | D INFERRED |
| 0x05830005 | S>C |  | H 0x0123b2f0(cmp) | - | - | DekaPass: reply/notification. DekaPass battle pass. Likely reply to C>S 0x05830004 (request even / reply odd convention). | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05830006 | both |  | B 0x0123b490; H 0x00740450; H 0x00740450 | 16 | - | DekaPass: request and reply share this opcode. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x05830006 receive all, lock 0 (0x159eb90 via writer 0x1414750; btn_receiveall): +0 u16 total (= 3 + 2n), +2 u8 n, | module only (no command type) (INFERRED) | S129 DekaPass | D INFERRED |
| 0x05830007 | S>C |  | H 0x010ab960 | - | - | DekaPass: reply/notification. DekaPass battle pass. Likely reply to C>S 0x05830006 (request even / reply odd convention). | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05830008 | S>C |  | H 0x00995b10 | - | - | DekaPass: reply/notification. DekaPass battle pass. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x05830009 | S>C |  | H 0x0123c320 | - | - | DekaPass: reply/notification. DekaPass battle pass. | module only (no command type) (INFERRED) |  | D INFERRED |
| 0x0583000a | C>S |  | B 0x0123b550 | 16 | - | DekaPass: request. DekaPass battle pass. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x0583000a sent by the open mission list every 60 s of window time (0x159ec50, caller 0x10ed614). No reply case exists. UNVERIFIED: premium state 0 for level… | module only (no command type) (INFERRED) | S129 DekaPass | D INFERRED |

### 0x0584 TalismanEffectTransform (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x05840001 | C>S |  | B 0x014cbe60; B 0x014cbf80 | 28 | +0x0 undefined2, +0x2 undefined1, +0x4 undefined4, +0x8 undefined4 | TalismanEffectTransform: request. Talisman effect transform. | MISSING |  | D INFERRED |
| 0x05840003 | C>S |  | B 0x014cbe10 | 16 | - | TalismanEffectTransform: request. Talisman effect transform. | MISSING |  | D INFERRED |

### 0x0600 Message / mail (legacy) (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0600000b | C>S |  | B 0x008b97d0 | 36 | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined1, +0xd undefined1, +0xe undefined1 | Message / mail (legacy): request. Legacy message/mail. | mail (INFERRED) | S937 wire-W05-message-rtti | D INFERRED |
| 0x0600000c | C>S |  | B 0x008bff50(factory) | 32 | - | Message / mail (legacy): request. Legacy message/mail. | mail (INFERRED) | S937 wire-W05-message-rtti | D INFERRED |
| 0x0600000d | C>S |  | B 0x008bce90 | 32 | +0x0 undefined4, +0x4 undefined4, +0x8 undefined1, +0x9 undefined1, +0xa undefined1, +0xb ptr/copy | Message / mail (legacy): request. Legacy message/mail. | mail (INFERRED) | S937 wire-W05-message-rtti | D INFERRED |

### 0x0602 Enter event (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x06020000 | S>C |  | H 0x008e72c0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined2, +0xa undefined1, +0xb undefined1, +0xc undefined4 | Enter event: reply/notification. Enter event. | MISSING |  | D INFERRED |
| 0x06020002 | C>S |  | B 0x008f3ea0; B 0x008f4880 | 28 | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4 | Enter event: request. Enter event. | MISSING | S804 P8 coverage no-reply rows (W16) | D INFERRED |

### 0x0603 Effect event (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x06030006 | S>C |  | H 0x008e4720 | - | +0x0 short, +0x2 short, +0x4 undefined4, +0x8 undefined4, +0xc ushort, +0xe ushort | Effect event: reply/notification. Effect event. | MISSING |  | D INFERRED |
| 0x06030007 | S>C |  | H 0x008e48c0 | - | +0x0 short, +0x2 ushort, +0x4 int, +0x8 int, +0xc undefined4 | Effect event: reply/notification. Effect event. | MISSING |  | D INFERRED |

### 0x0604 Skill (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x06040000 | C>S |  | B 0x0132a530 | 36 | +0x0 undefined4, +0x4 ushort, +0x6 undefined1, +0x8 undefined1, +0x9 undefined1, +0xa undefined1 | Skill: request. Skill net. | cast (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |

### 0x0700 GameMaster / Developer / Dekaron provider (77)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x07000002 | both |  | B 0x0127b9a0; B 0x0127cf70; H 0x012fa690 | 24 | +0x2 undefined1, +0x4 undefined4 | GameMaster / Developer / Dekaron provider: request and reply share this opcode. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000005 | C>S |  | B 0x0127ba70; B 0x0127d110 | 20 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000006 | S>C |  | H 0x014d3840; H 0x014d64c0(cmp) | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000005 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000007 | C>S |  | B 0x0127b830; B 0x0127ce00 | 20 | +0x0 undefined1, +0x1 undefined1, +0x2 undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000008 | S>C |  | H 0x012fa9f0 | - | +0x0 undefined1 | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000007 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000009 | C>S |  | B 0x0127aa30; B 0x0127bf50 | 48 | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined8, +0x18 undefined4 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700000b | C>S |  | B 0x0127af80; B 0x0127b890 | 20 | +0x0 undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700000c | S>C |  | H 0x0136f680(cmp) | - | - | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700000b (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700000d | S>C |  | H 0x0136f680(cmp) | - | - | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700000e | C>S |  | B 0x0127b8f0; B 0x0127cec0 | 20 | +0x0 undefined2 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000010 | S>C |  | H 0x014d3920; H 0x014d6830 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000013 | C>S |  | B 0x0127b950; B 0x0127cf20 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000014 | S>C |  | H 0x014d3a00; H 0x014d6910 | - | +0x0 undefined2 | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000013 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000017 | C>S |  | B 0x0127c560; B 0x0127d750 | 60 | +0x0 ptr/copy, +0x2a undefined1, +0x2b undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000018 | S>C |  | H 0x014d7180 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000017 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000022 | C>S |  | B 0x0127bb80; B 0x0127bbd0 | 20 | +0x0 undefined1, +0x2 undefined2 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000023 | S>C |  | H 0x014d3c20; H 0x014d6b20 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000022 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000024 | C>S |  | B 0x014d2320; B 0x0127bb10 | 24 | +0x0 short, +0x2 short, +0x4 short | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000025 | S>C |  | H 0x014ce390; H 0x014d3b00 | - | +0x0 char, +0x2 undefined4, +0x6 undefined2 | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000024 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000026 | C>S |  | B 0x0127aeb0; B 0x0127c060 | 24 | +0x0 undefined2, +0x2 short, +0x4 short | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000027 | S>C |  | H 0x014ce130; H 0x014d6bc0 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000026 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000028 | C>S |  | B 0x0127afe0; B 0x0127c130 | 20 | +0x0 undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000029 | S>C |  | H 0x014cdb10; H 0x014d6e20 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000028 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700002a | C>S |  | B 0x0127b130; B 0x0127c1d0 | 20 | +0x1 undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700002b | S>C |  | H 0x014cdbc0; H 0x014d6ee0 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002a (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700002c | C>S |  | B 0x0127c270; B 0x0127c3c0 | 20 | +0x0 undefined1, +0x1 undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700002d | S>C |  | H 0x014d7050 | - | +0x0 undefined2, +0x2 undefined2, +0x4 undefined2, +0x6 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002c (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700002e | C>S |  | B 0x0127c510; B 0x0127e040 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700002f | S>C |  | H 0x014d6fc0 | - | +0x0 undefined4, +0x4 undefined4 | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002e (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000030 | C>S |  | B 0x0127e280; B 0x0127e420 | 24 | +0x0 undefined1, +0x1 undefined2 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000031 | S>C |  | H 0x014d7220 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000030 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000032 | C>S |  | B 0x008601b0; B 0x0127e520 | 20 | +0x0 undefined4 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000033 | S>C |  | H 0x014d7440 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000032 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000034 | C>S |  | B 0x00860200; B 0x0127e580 | 20 | +0x0 undefined4 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000035 | S>C |  | H 0x014d74f0 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000034 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000036 | C>S |  | B 0x0127e4d0 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000037 | S>C |  | H 0x014d73a0 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000036 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000038 | C>S |  | B 0x0127e480 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000039 | S>C |  | H 0x014d7300 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000038 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700003a | C>S |  | B 0x00895c40; B 0x0127ae50 | 20 | +0x0 char | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700003b | S>C |  | H 0x008e2c20(cmp) | - | - | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700003a (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700003c | C>S |  | B 0x014d2450; B 0x014d5c70 | 20 | +0x0 short | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700003e | C>S |  | B 0x014d24f0; B 0x014d5d10 | 20 | +0x0 short | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000040 | C>S |  | B 0x014d2590; B 0x014d5db0 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000041 | S>C |  | H 0x014ce4b0; H 0x014d3da0 | - | +0x0 char, +0x1 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000040 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000042 | C>S |  | B 0x014d25e0; B 0x014d5e00 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000043 | S>C |  | H 0x014ce560; H 0x014d3e50 | - | +0x0 char, +0x1 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000042 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000046 | S>C |  | H 0x012fea10(cmp) | - | - | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000047 | C>S |  | B 0x014d26d0; B 0x014d5e50 | 24 | +0x0 int, +0x4 int | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000048 | S>C |  | H 0x014ce6b0; H 0x014d3f00 | - | +0x0 int | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000047 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000049 | C>S |  | B 0x014d27b0; B 0x014d5ee0 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700004a | S>C |  | H 0x014ce750; H 0x014d3fa0 | - | +0x0 int | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000049 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700004b | C>S |  | B 0x0127ab40; B 0x0127c710 | 20 | +0x0 undefined4 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700004c | S>C |  | H 0x014ce800; H 0x014d4040 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700004b (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700004d | C>S |  | B 0x0127aba0; B 0x0127c770 | 20 | +0x0 undefined4 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700004e | S>C |  | H 0x014ce8a0; H 0x014d40e0 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700004d (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700004f | C>S |  | B 0x014d2630; B 0x0127e740 | 20 | +0x0 bool | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000050 | S>C |  | H 0x014ce610; H 0x014d7700 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700004f (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000052 | C>S |  | B 0x014d28c0; B 0x0127e850 | 20 | +0x0 short | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000053 | S>C |  | H 0x014ce940; H 0x014d7a30 | - | - | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000052 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000054 | C>S |  | B 0x014d2960; B 0x0127e8b0 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000055 | S>C |  | H 0x014ce9c0; H 0x014d7ab0 | - | - | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000054 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000056 | C>S |  | B 0x0127aca0; B 0x0127e900 | 20 | +0x0 undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000057 | S>C |  | H 0x014cea40; H 0x014d7b30 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000056 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000058 | C>S |  | B 0x0127d570 | 20 | +0x0 undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000059 | S>C |  | H 0x014d7cb0 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000058 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700005a | C>S |  | B 0x012c86c0; B 0x0127d690 | 20 | +0x0 short | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700005b | C>S |  | B 0x012c86c0; B 0x0127d6f0 | 20 | +0x0 short | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700005c | C>S |  | B 0x0127ac50; B 0x0127ec70 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700005d | S>C |  | H 0x014ce2b0; H 0x014d6d40 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700005c (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0700005e | C>S |  | B 0x0127ac00; B 0x0127ec20 | 16 | - | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x0700005f | S>C |  | H 0x014ce1d0; H 0x014d6c60 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700005e (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000060 | S>C |  | H 0x012fab50 | - | - | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000062 | C>S |  | B 0x0127ed80 | 64 | +0x0 ptr/copy, +0x2a undefined1, +0x2c undefined4 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000063 | S>C |  | H 0x014d7d50 | - | +0x0 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000062 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x07000064 | C>S |  | B 0x0127ef40 | 60 | +0x0 ptr/copy, +0x2a undefined1 | GameMaster / Developer / Dekaron provider: request. GM and developer commands. | /api/world/gm (INFERRED) | S900 GameMasterWire | D INFERRED |
| 0x07000065 | S>C |  | H 0x014d7e20 | - | +0x2a char, +0x30 char | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000064 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |

### 0x0800 GameMaster / Developer (31)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x08000002 | C>S |  | B 0x0127a8d0; B 0x0127bdf0 | 84 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined4, +0xa undefined4, +0xe undefined4, +0x12 undefined4 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |
| 0x08000003 | C>S |  | B 0x0127a990; B 0x0127beb0 | 32 | +0x0 undefined4, +0x4 undefined2, +0x8 undefined4, +0xc undefined4 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |
| 0x08000005 | C>S |  | B 0x00895c40; B 0x0127aae0 | 20 | +0x0 char | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000006 | S>C |  | H 0x0127a430(cmp); H 0x014cdca0 | - | - | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000005 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0800000b | C>S |  | B 0x0085ff20; B 0x0127ea50 | 20 | +0x0 undefined2 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x0800000c | S>C |  | H 0x014cdd80 | - | +0x0 undefined2 | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x0800000b (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x0800000d | C>S |  | B 0x0085ff70; B 0x0127eab0 | 20 | +0x0 undefined4 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x0800000e | C>S |  | B 0x0085ffc0; B 0x0127eb10 | 20 | +0x0 undefined4 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x0800000f | C>S |  | B 0x00860010; B 0x0127eb70 | 16 | - | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000010 | S>C |  | H 0x014cde60 | - | +0x0 char | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x0800000f (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000012 | S>C |  | H 0x012a5f30(cmp) | - | - | GameMaster / Developer: reply/notification. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000013 | C>S |  | B 0x008602c0 | 16 | - | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000014 | C>S |  | B 0x00860300 | 20 | +0x0 undefined1 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000015 | C>S |  | B 0x00860350 | 24 | +0x0 undefined4, +0x4 undefined4 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000016 | C>S |  | B 0x01431bc0 | 20 | +0x0 undefined1 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000017 | C>S |  | B 0x014d0e60 | 16 | - | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000018 | C>S |  | B 0x00860010; B 0x0127eb70 | 16 | - | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000019 | S>C |  | H 0x014cdf50 | - | +0x0 char | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000018 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000020 | C>S |  | B 0x014d0eb0 | 16 | - | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000021 | S>C |  | H 0x01447170; H 0x01498840 | - | +0x0 undefined4 | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000020 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000022 | C>S |  | B 0x014d0f00 | 16 | - | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000023 | S>C |  | H 0x014471e0; H 0x014988b0 | - | +0x0 uint, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000022 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000024 | C>S |  | B 0x00860010 | 16 | - | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000025 | S>C |  | H 0x014ce040 | - | +0x0 char | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000024 (request even / reply odd convention). | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000026 | C>S |  | B 0x0127b1d0; B 0x0127c7d0 | 20 | +0x0 undefined2 | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |
| 0x08000027 | C>S |  | B 0x008603a0 | 20 | +0x0 char | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000028 | C>S |  | B 0x008603f0 | 20 | +0x0 char | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000029 | C>S |  | B 0x00860440 | 16 | - | GameMaster / Developer: request. GM and developer commands. | /api/world/gm (INFERRED) | S904 GM debug commands wire (W04) | D INFERRED |
| 0x08000030 | S>C |  | H 0x014cef70 | - | +0xc int | GameMaster / Developer: reply/notification. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000031 | S>C |  | H 0x014cf0a0 | - | +0x0 ptr | GameMaster / Developer: reply/notification. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |
| 0x08000032 | S>C |  | H 0x014cf210 | - | +0xb undefined1, +0xc int | GameMaster / Developer: reply/notification. GM and developer commands. | /api/world/gm (INFERRED) |  | D INFERRED |

### 0x0900 Guild (27)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x09000000 | C>S |  | B 0x0138d950 | 60 | - | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x09000001 | S>C |  | H 0x01393960 | - | +0x0 undefined4, +0x4 undefined4, +0x10 undefined1 | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000000 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09000004 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. | guild (INFERRED) |  | D INFERRED |
| 0x09000005 | C>S |  | B 0x0138d760 | 16 | - | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x09000006 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000005 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09000007 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. | guild (INFERRED) |  | D INFERRED |
| 0x09000008 | C>S |  | B 0x0138d8b0 | 16 | - | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x09000009 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000008 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x0900000a | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. | guild (INFERRED) |  | D INFERRED |
| 0x0900000b | C>S |  | B 0x0138d340 | 16 | - | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x0900000c | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000b (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x0900000d | C>S |  | B 0x013a8010 | 20 | +0x0 undefined2, +0x2 undefined1 | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x0900000e | S>C |  | H 0x013aba50 | - | +0x0 undefined4, +0x4 ptr | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000d (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x0900000f | C>S |  | B 0x013902d0 | 16 | - | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x09000010 | S>C |  | H 0x013950e0 | - | +0x0 undefined4 | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000f (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09000011 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. | guild (INFERRED) |  | D INFERRED |
| 0x09000012 | C>S |  | B 0x0138d840 | 16 | - | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x09000013 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000012 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09000014 | S>C |  | H 0x01393d10 | - | - | Guild: reply/notification. Guild create/join/leave/notice. | guild (INFERRED) |  | D INFERRED |
| 0x09000015 | C>S |  | B 0x0138d7d0 | 16 | - | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x09000016 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000015 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09000017 | C>S |  | B 0x0138dcd0 | 60 | - | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x09000018 | S>C |  | H 0x01393f20 | - | +0x0 undefined1 | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000017 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09000019 | C>S |  | B 0x0138e000 | 60 | +0x0 ptr/copy | Guild: request. Guild create/join/leave/notice. | guild (INFERRED) | S976 GuildWire | D INFERRED |
| 0x0900001a | S>C |  | H 0x01394070 | - | +0x0 undefined1, +0x1 ptr | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000019 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x0900001b | S>C |  | H 0x013942a0 | - | - | Guild: reply/notification. Guild create/join/leave/notice. | guild (INFERRED) |  | D INFERRED |
| 0x0900001d | S>C |  | H 0x013ac150 | - | +0x3 byte, +0x4 undefined1 | Guild: reply/notification. Guild create/join/leave/notice. | guild (INFERRED) |  | D INFERRED |

### 0x0901 Guild (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x09010000 | S>C |  | H 0x01397390 | - | +0x0 char | Guild: reply/notification. Guild notice. | guild (INFERRED) |  | D INFERRED |
| 0x09010001 | S>C |  | H 0x01399290 | - | - | Guild: reply/notification. Guild notice. | guild (INFERRED) |  | D INFERRED |

### 0x0902 Guild (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x09020000 | C>S | ENTER_DONE | B 0x00878070 | 16 | - | header only, sent after ENTER_WORLD | guild (INFERRED) | core (server.mjs) | D+B+O |
| 0x09020001 | C>S |  | B 0x0138ed40 | 60 | +0x2a char | Guild: request. Guild UI. | guild (INFERRED) | S952 Guild09Wire | D INFERRED |
| 0x09020002 | S>C |  | H 0x013962d0 | - | +0x0 undefined1 | Guild: reply/notification. Guild UI. Likely reply to C>S 0x09020001 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09020003 | S>C |  | H 0x01396520 | - | - | Guild: reply/notification. Guild UI. | guild (INFERRED) |  | D INFERRED |
| 0x09020004 | both |  | B 0x0138ef60; H 0x013961e0 | 104 | +0x0 ptr/copy, +0x2a ptr/copy | Guild: request and reply share this opcode. Guild UI. | guild (INFERRED) | S952 Guild09Wire | D INFERRED |
| 0x09020005 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild UI. Likely reply to C>S 0x09020004 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |

### 0x0903 Guild / GuildDungeon (42)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x09030000 | C>S |  | B 0x01390340 | 20 | +0x0 undefined4 | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030001 | S>C |  | H 0x01395580 | - | +0x0 int, +0x4 undefined4 | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030000 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030002 | C>S |  | B 0x01390440 | 16 | - | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030003 | S>C |  | H 0x013956f0 | - | +0x0 int | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030002 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030004 | S>C |  | H 0x01396030 | - | +0x4 undefined2, +0x8 undefined4, +0xc undefined4, +0x10 undefined1 | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x09030005 | C>S |  | B 0x013904b0 | 16 | - | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030006 | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030005 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030011 | C>S |  | B 0x013903c0 | 24 | +0x0 undefined4, +0x4 undefined4 | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030012 | S>C |  | H 0x01398120 | - | +0x0 int, +0x8 undefined4, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030011 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030014 | C>S |  | B 0x01390520 | 20 | +0x0 short | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030015 | S>C |  | H 0x013982d0 | - | +0x0 int | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030014 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030016 | C>S |  | B 0x01390520 | 20 | +0x0 short | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030017 | S>C |  | H 0x01398370 | - | +0x0 int | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030016 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030018 | C>S |  | B 0x013908b0 | 20 | +0x0 undefined4 | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030019 | S>C |  | H 0x01392fc0 | - | +0x0 int | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030018 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030020 | S>C |  | H 0x01466b60(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x09030021 | both |  | B 0x01467360; H 0x01466b60(cmp) | 16 | - | Guild / GuildDungeon: request and reply share this opcode. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S934 wire-W05-guild-dungeon-delivery | D INFERRED |
| 0x09030022 | C>S |  | B 0x01467580 | 84 | +0x0 char | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S934 wire-W05-guild-dungeon-delivery | D INFERRED |
| 0x09030023 | S>C |  | H 0x01466ca0 | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030022 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030024 | C>S |  | B 0x01468a80 | 20 | +0x0 undefined4 | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S047 Guild Dungeon rankings (partial integration) | D INFERRED |
| 0x09030025 | C>S |  | B 0x0138e110 | 20 | +0x0 undefined4 | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030026 | C>S |  | B 0x0138e9d0 | 580 | +0x0 undefined1, +0x1 undefined1, +0x2 undefined1, +0x12 undefined1, +0x13 undefined1, +0x14 ptr/copy | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030027 | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030026 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030028 | C>S |  | B 0x0138e840 | 16 | - | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030029 | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030028 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x0903002a | S>C |  | H 0x013994e0 | - | +0x0 undefined4, +0x3c short, +0x66 undefined2, +0x68 undefined2, +0x6a undefined1, +0x6c undefined2 | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x0903002b | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x0903002c | C>S |  | B 0x0138e880 | 80 | +0x0 ptr/copy, +0xe ptr/copy | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x0903002d | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x0903002c (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x0903002e | C>S |  | B 0x0138e910 | 64 | +0x0 ptr/copy, +0x2c undefined4 | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x0903002f | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x0903002e (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030030 | C>S |  | B 0x0138e990 | 16 | - | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030031 | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030030 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030032 | S>C |  | H 0x01399930 | - | +0x0 undefined2, +0x2 undefined1, +0x3 undefined1, +0x2e short | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x09030033 | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x09030034 | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x09030035 | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x09030036 | S>C |  | H 0x01399e20 | - | +0x0 byte, +0x1 byte, +0x2 undefined8, +0xa undefined4, +0xe undefined2, +0x10 undefined1 | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) |  | D INFERRED |
| 0x09030037 | C>S |  | B 0x0138eb10 | 60 | +0x0 ptr/copy | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x09030038 | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030037 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x09030039 | C>S |  | B 0x0138ebc0 | 132 | +0x0 ptr/copy, +0xe ptr/copy | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x0903003a | S>C |  | H 0x013922c0(cmp) | - | - | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030039 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |

### 0x0a00 Chat (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0a000000 | S>C |  | H 0x01278a20 | - | - | Chat: reply/notification. Chat. | MISSING |  | D INFERRED |

### 0x0a01 Chat (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0a010009 | both |  | B 0x012f4dd0; H 0x012f8be0(cmp) | 52,96,112,132,560,668 | +0x0 undefined4, +0x8 undefined4, +0x2c undefined1, +0x30 undefined4, +0x204 undefined4 | Chat: request and reply share this opcode. Chat channels. | megaphone (INFERRED) | S803 WIRE-P8 world/matching/alliance chat | D INFERRED |
| 0x0a010010 | C>S |  | B 0x012f4dd0 | 52,96,112,132,560,668 | +0x0 undefined4, +0x8 undefined4, +0x2c undefined1, +0x30 undefined4, +0x204 undefined4 | Chat: request. Chat channels. | megaphone (INFERRED) | S803 WIRE-P8 world/matching/alliance chat | D INFERRED |
| 0x0a010013 | S>C |  | H 0x012fb430 | - | +0x80 undefined2, +0x82 undefined2 | Chat: reply/notification. Chat channels. | megaphone (INFERRED) |  | D INFERRED |

### 0x0a02 Messenger (10)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0a020000 | both |  | B 0x012776b0; H 0x01279040 | 104 | +0x2c undefined2, +0x56 undefined1 | Messenger: request and reply share this opcode. Messenger (friends) list. | messenger, friendrequest (INFERRED) | S903 Messenger friend wire (W03) | D INFERRED |
| 0x0a020001 | S>C |  | H 0x01279180 | - | +0x2c undefined1 | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020000 (request even / reply odd convention). | messenger, friendrequest (INFERRED) |  | D INFERRED |
| 0x0a020002 | S>C |  | H 0x012793b0 | - | +0x0 ptr, +0x2a undefined1, +0x2c undefined1, +0x2e undefined2, +0x30 undefined1, +0x31 char | Messenger: reply/notification. Messenger (friends) list. | messenger, friendrequest (INFERRED) |  | D INFERRED |
| 0x0a020003 | C>S |  | B 0x01277dc0 | 104 | +0x2c ptr/copy, +0x56 undefined1, +0x57 undefined1 | Messenger: request. Messenger (friends) list. | messenger, friendrequest (INFERRED) | S903 Messenger friend wire (W03) | D INFERRED |
| 0x0a020004 | S>C |  | H 0x012794c0 | - | - | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020003 (request even / reply odd convention). | messenger, friendrequest (INFERRED) |  | D INFERRED |
| 0x0a020005 | C>S |  | B 0x01277d10 | 104 | +0x2c ptr/copy | Messenger: request. Messenger (friends) list. | messenger, friendrequest (INFERRED) | S903 Messenger friend wire (W03) | D INFERRED |
| 0x0a020006 | S>C |  | H 0x01278680(cmp) | - | - | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020005 (request even / reply odd convention). | messenger, friendrequest (INFERRED) |  | D INFERRED |
| 0x0a020007 | C>S |  | B 0x01277ee0 | 104 | +0x2c ptr/copy, +0x56 undefined1 | Messenger: request. Messenger (friends) list. | messenger, friendrequest (INFERRED) | S903 Messenger friend wire (W03) | D INFERRED |
| 0x0a020008 | S>C |  | H 0x01279680 | - | +0x2a undefined1, +0x2c char, +0x2e ptr | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020007 (request even / reply odd convention). | messenger, friendrequest (INFERRED) |  | D INFERRED |
| 0x0a020009 | S>C |  | H 0x01279a70 | - | +0x0 ptr, +0x2a undefined1, +0x56 undefined1, +0x58 undefined2, +0x5a undefined1, +0x5b char | Messenger: reply/notification. Messenger (friends) list. | messenger, friendrequest (INFERRED) |  | D INFERRED |

### 0x0a03 Messenger (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0a030000 | S>C |  | H 0x01278820 | - | - | Messenger: reply/notification. Messenger notice. | messenger (INFERRED) |  | D INFERRED |
| 0x0a030001 | S>C |  | H 0x012788e0 | - | - | Messenger: reply/notification. Messenger notice. | messenger (INFERRED) |  | D INFERRED |

### 0x0a04 Messenger (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0a040000 | C>S |  | B 0x012779e0 | 104 | +0x2c undefined2, +0x56 undefined1 | Messenger: request. Messenger. | messenger (INFERRED) | S977 MessengerWire | D INFERRED |
| 0x0a040001 | S>C |  | H 0x01279b80 | - | +0x2c undefined1 | Messenger: reply/notification. Messenger. Likely reply to C>S 0x0a040000 (request even / reply odd convention). | messenger (INFERRED) |  | D INFERRED |
| 0x0a040004 | S>C |  | H 0x01278680(cmp) | - | - | Messenger: reply/notification. Messenger. | messenger (INFERRED) |  | D INFERRED |
| 0x0a040006 | S>C |  | H 0x01279ee0 | - | +0x2c ptr, +0x6b undefined1 | Messenger: reply/notification. Messenger. | messenger (INFERRED) |  | D INFERRED |
| 0x0a040007 | C>S |  | B 0x01277ff0 | 104 | +0x2a undefined1, +0x2c ptr/copy | Messenger: request. Messenger. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x0a040007 packet size 0x68, selector at packet+0x3a, UTF16 name at +0x3c. | messenger (INFERRED) | S067 Messenger blacklist removal (partial) | D INFERRED |
| 0x0a040008 | S>C |  | H 0x01279d00 | - | +0x2c char, +0x2e ptr, +0x58 undefined1 | Messenger: reply/notification. Messenger. Likely reply to C>S 0x0a040007 (request even / reply odd convention). | messenger (INFERRED) |  | D INFERRED |

### 0x0b10 Tool (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0b100012 | S>C |  | H 0x01442d90(cmp) | - | - | Tool: reply/notification. Tool net handler. | MISSING |  | D INFERRED |

### 0x0c00 NewLetter (mail) (16)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0c000000 | C>S |  | B 0x0140a810 | 20 | +0x0 undefined4 | NewLetter (mail): request. Mail list/read/send/delete. | mail (INFERRED) | S070 Mail itemless inbox list/read/DIL/delete (partial) | D+O INFERRED |
| 0x0c000001 | S>C |  | H 0x0140b050 | obs 32 | +0x0 int, +0x4 undefined2, +0x6 undefined2, +0x8 ushort, +0xa char, +0xc undefined4 | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000000 (request even / reply odd convention). | mail (INFERRED) |  | D+O INFERRED |
| 0x0c000002 | S>C |  | H 0x0140af00(cmp) | - | - | NewLetter (mail): reply/notification. Mail list/read/send/delete. | mail (INFERRED) |  | D INFERRED |
| 0x0c000003 | C>S |  | B 0x0140a870 | 16 | - | NewLetter (mail): request. Mail list/read/send/delete. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: Global mail count request0x0c000003 builder175d4b0: header only. | mail (INFERRED) | S070 Mail counts (partial) | D+O INFERRED |
| 0x0c000004 | S>C |  | H 0x0140b400 | obs 24 | +0x0 int, +0x4 undefined2, +0x6 undefined2 | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000003 (request even / reply odd convention). | mail (INFERRED) |  | D+O INFERRED |
| 0x0c000005 | C>S |  | B 0x0140a8c0 | 24 | +0x0 undefined4, +0x4 undefined4 | NewLetter (mail): request. Mail list/read/send/delete. | mail (INFERRED) | S070 Mail itemless inbox list/read/DIL/delete (partial) | D INFERRED |
| 0x0c000006 | S>C |  | H 0x0140b740 | - | +0x0 undefined4, +0x4 undefined4, +0x8 int | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000005 (request even / reply odd convention). | mail (INFERRED) |  | D INFERRED |
| 0x0c000007 | C>S |  | B 0x0140a930 | 24 | +0x0 undefined4, +0x4 undefined4 | NewLetter (mail): request. Mail list/read/send/delete. | mail (INFERRED) | S070 Mail itemless inbox list/read/DIL/delete (partial) | D INFERRED |
| 0x0c000008 | S>C |  | H 0x0140b850 | - | +0x0 undefined4, +0x4 undefined4, +0x8 int | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000007 (request even / reply odd convention). | mail (INFERRED) |  | D INFERRED |
| 0x0c000009 | C>S |  | B 0x0140a990 | 24 | +0x0 undefined4, +0x4 undefined4 | NewLetter (mail): request. Mail list/read/send/delete. | mail (INFERRED) | S070 Mail itemless inbox list/read/DIL/delete (partial) | D INFERRED |
| 0x0c00000a | S>C |  | H 0x0140b960 | - | +0x0 undefined4, +0x4 undefined4, +0x8 int | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000009 (request even / reply odd convention). | mail (INFERRED) |  | D INFERRED |
| 0x0c00000b | C>S |  | B 0x0140a9f0 | 24 | +0x0 undefined4, +0x4 undefined4 | NewLetter (mail): request. Mail list/read/send/delete. | mail (INFERRED) | S070 Mail itemless inbox list/read/DIL/delete (partial) | D INFERRED |
| 0x0c00000c | S>C |  | H 0x0140bb50 | - | +0x0 undefined4, +0x4 undefined4, +0x8 int | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c00000b (request even / reply odd convention). | mail (INFERRED) |  | D INFERRED |
| 0x0c00000d | S>C |  | H 0x0140b020 | - | - | NewLetter (mail): reply/notification. Mail list/read/send/delete. | mail (INFERRED) |  | D INFERRED |
| 0x0c00000e | C>S |  | B 0x0140a660 | 136 | +0x0 ptr/copy, +0x2a ptr/copy, +0x5e undefined1, +0x5f undefined2, +0x61 undefined1, +0x68 undefined4 | NewLetter (mail): request. Mail list/read/send/delete. | mail (INFERRED) | S940 wire-W06-newletter | D INFERRED |
| 0x0c00000f | S>C |  | H 0x0140b280 | - | - | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c00000e (request even / reply odd convention). | mail (INFERRED) |  | D INFERRED |

### 0x0d00 CashShop / VipShop (26)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0d000000 | C>S |  | B 0x013e4200(factory) | 20 | - | CashShop / VipShop: request. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) | S967 CashShopWire | D INFERRED |
| 0x0d000001 | S>C |  | H 0x013ea040 | - | +0x0 uint, +0x4 undefined4, +0x8 undefined4, +0xc char | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d000000 (request even / reply odd convention). | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000003 | S>C |  | H 0x013eb9f0 | - | +0x0 int, +0x5c int | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000005 | S>C |  | H 0x013ebbc0 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000008 | S>C |  | H 0x013ebc00 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000009 | S>C |  | H 0x013ebe30 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00000a | S>C |  | H 0x013ec070 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00000b | S>C |  | H 0x013ec1e0 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00000c | S>C |  | H 0x013ec380 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00000d | S>C |  | H 0x013ec6c0 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00000e | S>C |  | H 0x013ec800 | - | +0x0 undefined4, +0x4 undefined1 | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00000f | S>C |  | H 0x013eca00 | - | +0x3 char | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000010 | S>C |  | H 0x013ecb80 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000013 | S>C |  | H 0x01367c50 | obs 18 | +0x0 undefined2 | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D+O INFERRED |
| 0x0d000014 | S>C |  | H 0x013ec520 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000015 | C>S |  | B 0x013e2a80; B 0x01475410 | 492 | +0x0 ptr/copy, +0x15 byte, +0x1d8 undefined1 | CashShop / VipShop: request. Cash shop. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x0d000015 buy, size 0x1ec. Built by the D-Shop UI 0x1735bb0 (+0x1e8 = 0) and the VIP shop UI 0x17c7740 (+0x1e8 = 1). Body offsets: | coinshop, dshopbuy, dshopgift (INFERRED) | S020 CashShop | D INFERRED |
| 0x0d000016 | S>C |  | H 0x013ea420 | - | +0x0 undefined4, +0x4 undefined4, +0x8 byte, +0x7c int, +0x80 undefined4, +0x84 char | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d000015 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S020: S>C 0x0d000016 buy result (case 0x174078c -> 0x173d270), size 0x95: +0x00 i64 (2 dw… | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000017 | C>S |  | B 0x013e2c10; B 0x013e3020 | 864 | +0x0 undefined1, +0x240 undefined1, +0x26c byte | CashShop / VipShop: request. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) | S967 CashShopWire | D INFERRED |
| 0x0d000018 | S>C |  | H 0x013eb3a0 | - | +0x0 undefined4, +0x4 undefined4, +0x34 byte, +0xa8 int, +0xac undefined4 | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d000017 (request even / reply odd convention). | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00001a | S>C |  | H 0x013ed010 | - | - | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00001b | S>C |  | H 0x013ed280 | - | +0x0 undefined3 | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00001c | C>S |  | B 0x014752b0 | 20 | +0x0 bool | CashShop / VipShop: request. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) | S967 CashShopWire | D INFERRED |
| 0x0d00001d | S>C |  | H 0x013ed3f0 | - | - | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d00001c (request even / reply odd convention). | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00001e | S>C |  | H 0x013ed450 | - | +0x0 int, +0x4 undefined4, +0x12 short, +0x5c int, +0x63 char | CashShop / VipShop: reply/notification. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d00001f | C>S |  | B 0x013e3eb0; B 0x01475f30 | 20 | +0x0 undefined1 | CashShop / VipShop: request. Cash shop. | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |
| 0x0d000020 | S>C |  | H 0x013ed8d0 | - | +0x0 char, +0x1 undefined1, +0x4 ptr | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d00001f (request even / reply odd convention). | coinshop, dshopbuy, dshopgift (INFERRED) |  | D INFERRED |

### 0x0e00 Target / attack (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0e000002 | C>S |  | B 0x00860250 | 64 | +0x1d undefined4, +0x21 undefined4, +0x28 undefined4, +0x2d undefined1 | Target / attack: request. Normal attack. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: monster the Global client sent C>S 0x0e000002, 48-byte body every ~0.6 s: | attack (INFERRED) | S109 Target (normal attack) | D+O INFERRED |

### 0x0e01 Monster AI (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0e010002 | C>S |  | B 0x008baec0; B 0x008bbf70(factory) | 60 | +0x0 undefined4, +0x21 undefined4, +0x25 undefined4 | Monster AI: request. Monster attack. | attack (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |

### 0x0e03 Attack (misc) (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0e030000 | C>S |  | B 0x008c1220 | 60 | +0x0 int, +0x29 undefined1 | Attack (misc): request. Attack. | attack (INFERRED) | S955 TargetMiscWire | D INFERRED |

### 0x0f00 Siege (misc) (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0f000004 | S>C |  | H 0x013c3a80 | - | +0x0 ptr | Siege (misc): reply/notification. Siege notice. | siegerenew (INFERRED) |  | D INFERRED |
| 0x0f000005 | S>C |  | H 0x013c3ac0 | - | +0x0 ptr | Siege (misc): reply/notification. Siege notice. | siegerenew (INFERRED) |  | D INFERRED |

### 0x0f02 Siege (12)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0f020000 | C>S |  | B 0x013bfac0 | 16 | - | Siege: request. Siege UI. | siegerenew (INFERRED) | S990 wire-W12-siege | D INFERRED |
| 0x0f020001 | S>C |  | H 0x013c15b0 | - | +0x0 int, +0x8 undefined4, +0xc undefined4 | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020000 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x0f020002 | C>S |  | B 0x013bfb20 | 16 | - | Siege: request. Siege UI. | siegerenew (INFERRED) | S990 wire-W12-siege | D INFERRED |
| 0x0f020003 | S>C |  | H 0x013c1b20 | - | +0x0 int | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020002 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x0f020004 | C>S |  | B 0x013bfca0 | 20 | +0x0 undefined1 | Siege: request. Siege UI. | siegerenew (INFERRED) | S990 wire-W12-siege | D INFERRED |
| 0x0f020005 | S>C |  | H 0x013c2350 | - | +0x0 int, +0x8 undefined4, +0xc int | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020004 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |
| 0x0f020007 | C>S |  | B 0x013bfd20 | 16 | - | Siege: request. Siege UI. | siegerenew (INFERRED) | S990 wire-W12-siege | D INFERRED |
| 0x0f02000a | C>S |  | B 0x013bfd80 | 16 | - | Siege: request. Siege UI. | siegerenew (INFERRED) | S990 wire-W12-siege | D INFERRED |
| 0x0f02000d | C>S |  | B 0x013bfde0 | 16 | - | Siege: request. Siege UI. | siegerenew (INFERRED) | S990 wire-W12-siege | D INFERRED |
| 0x0f020010 | C>S |  | B 0x013bfc40 | 16 | - | Siege: request. Siege UI. | siegerenew (INFERRED) | S990 wire-W12-siege | D INFERRED |
| 0x0f020012 | C>S |  | B 0x013bfbe0 | 16 | - | Siege: request. Siege UI. | siegerenew (INFERRED) | S990 wire-W12-siege | D INFERRED |
| 0x0f020013 | S>C |  | H 0x013c13d0 | - | +0x0 int | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020012 (request even / reply odd convention). | siegerenew (INFERRED) |  | D INFERRED |

### 0x0f03 Siege (misc) (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x0f030008 | S>C |  | H 0x013c0aa0 | - | - | Siege (misc): reply/notification. Siege notice. | siegerenew (INFERRED) |  | D INFERRED |

### 0x1000 Shop (misc) (11)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x10000001 | C>S |  | B 0x01322260; B 0x01322b00(factory) | 28 | +0x0 undefined4, +0x4 undefined2, +0x6 undefined2, +0x8 undefined1, +0x9 undefined1 | Shop (misc): request. Shop notices. | shopbuy (INFERRED) | S902 wire-W02-misc | D INFERRED |
| 0x10000002 | S>C |  | H 0x013249b0 | - | +0x40 undefined4, +0x44 undefined4, +0x48 undefined4, +0x50 undefined4, +0x58 undefined4, +0x5c undefined2 | Shop (misc): reply/notification. Shop notices. Likely reply to C>S 0x10000001 (request even / reply odd convention). | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000003 | S>C |  | H 0x01318950 | - | +0x0 undefined4, +0x4 byte | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000004 | S>C |  | H 0x01318ab0 | - | +0x0 ptr | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000005 | S>C |  | H 0x01318b60 | - | - | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000006 | S>C |  | H 0x01318c30 | - | +0x0 ptr | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000007 | S>C |  | H 0x01318ce0 | - | +0x0 ptr | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000008 | S>C |  | H 0x01318ee0 | - | +0x0 ptr | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000009 | S>C |  | H 0x01318d90 | - | +0x0 ptr | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000010 | S>C |  | H 0x01318e40 | - | +0x0 undefined4 | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |
| 0x10000011 | S>C |  | H 0x01319e70 | - | +0x0 undefined3 | Shop (misc): reply/notification. Shop notices. | shopbuy (INFERRED) |  | D INFERRED |

### 0x1100 Guild (extended) (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x11000004 | S>C |  | H 0x013978c0 | - | - | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11000005 | S>C |  | H 0x013922c0(cmp) | - | - | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11000006 | S>C |  | H 0x01397b30 | - | - | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11000007 | S>C |  | H 0x01397c70 | - | +0x34 ptr | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11000008 | S>C |  | H 0x013922c0(cmp) | - | - | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x1100000c | S>C |  | H 0x013922c0(cmp) | - | - | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11000010 | S>C |  | H 0x013922c0(cmp) | - | - | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |

### 0x1101 Guild (17)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x11010000 | C>S |  | B 0x0138eca0 | 68 | - | Guild: request. Guild. | guild (INFERRED) | S802 wire-W16-guild-manage | D INFERRED |
| 0x11010001 | S>C |  | H 0x01395270 | - | +0x34 undefined4 | Guild: reply/notification. Guild. Likely reply to C>S 0x11010000 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11010003 | C>S |  | B 0x0138f900 | 968 | - | Guild: request. Guild. | guild (INFERRED) | S991 wire-W12-guild | D INFERRED |
| 0x11010004 | S>C |  | H 0x01394580 | - | +0x34 char | Guild: reply/notification. Guild. Likely reply to C>S 0x11010003 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11010005 | S>C |  | H 0x01398aa0 | - | - | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |
| 0x11010006 | C>S |  | B 0x0138fa00 | 72 | +0x34 undefined2, +0x36 undefined2 | Guild: request. Guild. | guild (INFERRED) | S991 wire-W12-guild | D INFERRED |
| 0x11010007 | S>C |  | H 0x01394680 | - | +0x38 undefined4, +0x3c undefined4, +0x48 undefined1 | Guild: reply/notification. Guild. Likely reply to C>S 0x11010006 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11010008 | S>C |  | H 0x01398bc0 | - | +0x34 undefined2, +0x36 undefined2 | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |
| 0x11010009 | C>S |  | B 0x0138fc70 | 104 | +0x34 undefined1 | Guild: request. Guild. | guild (INFERRED) | S802 wire-W16-guild-manage | D INFERRED |
| 0x1101000a | S>C |  | H 0x013948f0 | - | +0x34 undefined4 | Guild: reply/notification. Guild. Likely reply to C>S 0x11010009 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x1101000b | S>C |  | H 0x01398cc0 | - | - | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |
| 0x1101000c | C>S |  | B 0x0138fda0 | 76 | +0x34 undefined1, +0x38 undefined4 | Guild: request. Guild. | guild (INFERRED) | S802 wire-W16-guild-manage | D INFERRED |
| 0x1101000d | S>C |  | H 0x01394a40 | - | +0x34 undefined4 | Guild: reply/notification. Guild. Likely reply to C>S 0x1101000c (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x1101000f | C>S |  | B 0x013915c0(factory) | 108 | - | Guild: request. Guild. | guild (INFERRED) | S802 wire-W16-guild-manage | D INFERRED |
| 0x11010010 | S>C |  | H 0x01394b90 | - | +0x34 undefined4 | Guild: reply/notification. Guild. Likely reply to C>S 0x1101000f (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11010011 | S>C |  | H 0x01398f10 | - | +0x34 byte, +0x38 undefined4 | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |
| 0x11010018 | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |

### 0x1102 Guild (13)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x11020000 | S>C |  | H 0x01397480 | - | +0x5e char | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |
| 0x11020005 | C>S |  | B 0x0138f070 | 68 | - | Guild: request. Guild. | guild (INFERRED) | S984 wire-W11-guild-member | D INFERRED |
| 0x11020006 | S>C |  | H 0x01396810 | - | +0x34 undefined4 | Guild: reply/notification. Guild. Likely reply to C>S 0x11020005 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11020007 | C>S |  | B 0x0138f0e0 | 116 | +0x34 ptr/copy | Guild: request. Guild. | guild (INFERRED) | S802 wire-W16-guild-manage | D INFERRED |
| 0x11020008 | S>C |  | H 0x013969e0 | - | +0x60 undefined4 | Guild: reply/notification. Guild. Likely reply to C>S 0x11020007 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11020009 | C>S |  | B 0x013915f0(factory) | 112 | - | Guild: request. Guild. | guild (INFERRED) | S802 wire-W16-guild-manage | D INFERRED |
| 0x1102000a | S>C |  | H 0x01394d10 | - | +0x34 undefined4 | Guild: reply/notification. Guild. Likely reply to C>S 0x11020009 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x1102000b | S>C |  | H 0x013922c0(cmp) | - | - | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |
| 0x1102000c | C>S |  | B 0x013901c0 | 112 | - | Guild: request. Guild. | guild (INFERRED) | S984 wire-W11-guild-member | D INFERRED |
| 0x1102000d | S>C |  | H 0x01394e90 | - | +0x34 undefined4 | Guild: reply/notification. Guild. Likely reply to C>S 0x1102000c (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x1102000e | C>S |  | B 0x01390910 | 212 | +0x34 ptr/copy, +0x35 ptr/copy, +0xc0 int | Guild: request. Guild. | guild (INFERRED) | S802 wire-W16-guild-manage | D INFERRED |
| 0x1102000f | S>C |  | H 0x01393630 | - | +0x34 int | Guild: reply/notification. Guild. Likely reply to C>S 0x1102000e (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11020010 | S>C |  | H 0x01393870 | - | - | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |

### 0x1103 Guild (10)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x11030000 | both |  | B 0x0138f1f0; H 0x01398480 | 648 | +0x274 undefined4 | Guild: request and reply share this opcode. Guild. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x11030001 | both |  | B 0x0138f5f0; H 0x013922c0(cmp) | 732 | +0x2c8 undefined4 | Guild: request and reply share this opcode. Guild. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x11030002 | S>C |  | H 0x01398890 | - | +0x34 undefined1 | Guild: reply/notification. Guild. Likely reply to C>S 0x11030001 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11030003 | both |  | B 0x0138fb30; H 0x01396c10 | 120 | +0x3c undefined2 | Guild: request and reply share this opcode. Guild. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x11030004 | both |  | B 0x0138fb80; H 0x01396e10 | 164 | +0x34 ptr/copy | Guild: request and reply share this opcode. Guild. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x11030005 | both |  | B 0x0138d710; H 0x01397150 | 120 | +0x34 undefined2, +0x36 undefined1, +0x3a undefined1 | Guild: request and reply share this opcode. Guild. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x11030006 | S>C |  | H 0x01397230 | - | - | Guild: reply/notification. Guild. Likely reply to C>S 0x11030005 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x11030007 | both |  | B 0x01391440(factory); H 0x013922c0(cmp) | 652 | - | Guild: request and reply share this opcode. Guild. | guild (INFERRED) | S933 wire-W05-guild | D INFERRED |
| 0x11030008 | S>C |  | H 0x013989b0 | - | +0x34 int | Guild: reply/notification. Guild. Likely reply to C>S 0x11030007 (request even / reply odd convention). | guild (INFERRED) |  | D INFERRED |
| 0x1103000a | S>C |  | H 0x01396f00 | - | +0x8a undefined2 | Guild: reply/notification. Guild. | guild (INFERRED) |  | D INFERRED |

### 0x1104 GuildDungeonRanking (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x11040023 | S>C |  | H 0x01468580(cmp) | - | - | GuildDungeonRanking: reply/notification. Guild dungeon ranking. | guild (INFERRED) |  | D INFERRED |

### 0x1105 Guild (extended) (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x11050000 | S>C |  | H 0x01395900 | - | +0x60 undefined4, +0x64 undefined4, +0x68 undefined4 | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11050001 | S>C |  | H 0x01395b70 | - | +0x34 undefined2, +0x38 undefined4, +0x3c undefined4 | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11050009 | S>C |  | H 0x01395d00 | - | +0x60 undefined4, +0x64 undefined4, +0x68 undefined4, +0x6c undefined4, +0x74 undefined4 | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11050010 | S>C |  | H 0x01395e70 | - | +0x38 undefined4, +0x40 undefined4, +0x74 undefined4 | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11050013 | S>C |  | H 0x01393190 | - | +0x34 undefined4, +0x38 undefined4, +0x3c undefined4, +0x40 undefined4, +0x44 undefined4, +0x48 undefined4 | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11050014 | S>C |  | H 0x01466eb0 | - | +0x34 undefined4, +0x38 undefined4 | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |
| 0x11050015 | S>C |  | H 0x01467200 | - | +0x34 undefined4, +0x38 undefined4 | Guild (extended): reply/notification. Guild notices. | guild (INFERRED) |  | D INFERRED |

### 0x1200 (unattributed) (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x12000000 | S>C |  | H 0x013c3960 | - | +0x38 undefined4, +0x3c undefined4, +0x50 undefined1 | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12000001 | S>C |  | H 0x013c39e0 | - | - | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12000002 | S>C |  | H 0x013c3a20 | - | +0x38 ptr | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12000003 | S>C |  | H 0x013c3b20 | - | +0x38 ptr | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |

### 0x1202 (unattributed) (8)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x12020000 | S>C |  | H 0x013c2710 | - | - | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12020001 | S>C |  | H 0x013c2800 | - | - | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12020002 | S>C |  | H 0x013c06a0(cmp) | - | - | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12020003 | S>C |  | H 0x013c2560 | - | +0x34 undefined4, +0x38 int | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12020004 | S>C |  | H 0x013c2960 | - | +0x34 undefined1 | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12020005 | S>C |  | H 0x013c06a0(cmp) | - | - | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12020006 | S>C |  | H 0x013c06a0(cmp) | - | - | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |
| 0x12020007 | S>C |  | H 0x013c0b80 | - | +0x34 int | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). | MISSING |  | D INFERRED |

### 0x1300 Pet (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x13000000 | C>S |  | B 0x013f1790 | 20 | +0x0 undefined2, +0x2 undefined1 | Pet: request. Pet. | pet (INFERRED) | S936 wire-W05-pet | D INFERRED |
| 0x13000001 | S>C |  | H 0x013f3cb0(cmp) | - | - | Pet: reply/notification. Pet. Likely reply to C>S 0x13000000 (request even / reply odd convention). | pet (INFERRED) |  | D INFERRED |
| 0x13000002 | C>S |  | B 0x013f18b0 | 24 | +0x0 undefined2, +0x2 undefined1, +0x3 undefined2, +0x5 undefined1 | Pet: request. Pet. | pet (INFERRED) | S936 wire-W05-pet | D INFERRED |
| 0x13000003 | S>C |  | H 0x013f4190 | - | +0x0 int, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Pet: reply/notification. Pet. Likely reply to C>S 0x13000002 (request even / reply odd convention). | pet (INFERRED) |  | D INFERRED |
| 0x13000004 | C>S |  | B 0x013f1980 | 20 | +0x0 undefined2, +0x2 undefined1 | Pet: request. Pet. | pet (INFERRED) | S936 wire-W05-pet | D INFERRED |
| 0x13000005 | S>C |  | H 0x013f4380 | - | +0x0 int | Pet: reply/notification. Pet. Likely reply to C>S 0x13000004 (request even / reply odd convention). | pet (INFERRED) |  | D INFERRED |
| 0x13000010 | S>C |  | H 0x013f4060 | - | +0x4 undefined4, +0x8 undefined1 | Pet: reply/notification. Pet. | pet (INFERRED) |  | D INFERRED |

### 0x1400 Messenger (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x14000001 | C>S |  | B 0x01277120 | 120 | +0x3c char, +0x3d char | Messenger: request. Messenger. | messenger (INFERRED) |  | D+O INFERRED |
| 0x14000002 | both |  | B 0x012771a0; H 0x01278c20 | 124 | +0x34 undefined1, +0x3e ptr/copy | Messenger: request and reply share this opcode. Messenger. | messenger (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |

### 0x1401 Messenger (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x14010001 | both |  | B 0x01277260; H 0x01278d80 | 648 | +0x34 undefined1, +0x264 undefined4, +0x270 undefined1 | Messenger: request and reply share this opcode. Messenger. | messenger (INFERRED) | S953 MessengerWire | D INFERRED |
| 0x14010002 | S>C |  | H 0x01278680(cmp) | - | - | Messenger: reply/notification. Messenger. Likely reply to C>S 0x14010001 (request even / reply odd convention). | messenger (INFERRED) |  | D INFERRED |
| 0x14010004 | S>C |  | H 0x01278d30 | - | +0x4 ptr, +0x34 undefined1 | Messenger: reply/notification. Messenger. | messenger (INFERRED) |  | D INFERRED |
| 0x14010005 | C>S |  | B 0x01277fa0 | 80 | - | Messenger: request. Messenger. | messenger (INFERRED) | S953 MessengerWire | D INFERRED |
| 0x14010006 | both |  | B 0x01277550; H 0x01278f00 | 116 | +0x4 undefined2, +0x34 undefined1, +0x38 ptr/copy | Messenger: request and reply share this opcode. Messenger. | messenger (INFERRED) | S953 MessengerWire | D INFERRED |
| 0x14010016 | both |  | B 0x012f7c80(factory); H 0x012f9cc0 | 652 | +0x264 ptr | Messenger: request and reply share this opcode. Messenger. | messenger (INFERRED) | S953 MessengerWire | D INFERRED |
| 0x14010017 | S>C |  | H 0x012f9e70 | - | +0x38 char | Messenger: reply/notification. Messenger. Likely reply to C>S 0x14010016 (request even / reply odd convention). | messenger (INFERRED) |  | D INFERRED |

### 0x1402 Messenger (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x14020000 | S>C |  | H 0x012789f0 | - | - | Messenger: reply/notification. Messenger notice. | messenger (INFERRED) |  | D INFERRED |

### 0x1500 CharacterTrade (9)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x15000000 | both |  | B 0x008675d0; H 0x014212c0 | 68 | +0x0 undefined4, +0x4 undefined4, +0x8 ptr/copy, +0x32 undefined1 | CharacterTrade: request and reply share this opcode. Character trade. | chartrade (INFERRED) | S806 P8 CharacterTrade invite/accept (presence-gated, W16) | D INFERRED |
| 0x15000001 | S>C |  | H 0x01420740 | - | - | CharacterTrade: reply/notification. Character trade. Likely reply to C>S 0x15000000 (request even / reply odd convention). | chartrade (INFERRED) |  | D INFERRED |
| 0x15000002 | C>S |  | B 0x0141f370(factory); B 0x014212c0 | 20 | - | CharacterTrade: request. Character trade. | chartrade (INFERRED) | S806 P8 CharacterTrade invite/accept (presence-gated, W16) | D INFERRED |
| 0x15000004 | S>C |  | H 0x0141fd20 | - | +0x0 int, +0x4 undefined4 | CharacterTrade: reply/notification. Character trade. | chartrade (INFERRED) |  | D INFERRED |
| 0x15000005 | C>S |  | B 0x014210b0 | 16 | - | CharacterTrade: request. Character trade. | chartrade (INFERRED) | S806 P8 CharacterTrade invite/accept (presence-gated, W16) | D INFERRED |
| 0x15000006 | C>S |  | B 0x01420fd0 | 20 | +0x0 undefined4 | CharacterTrade: request. Character trade. | chartrade (INFERRED) | S806 P8 CharacterTrade invite/accept (presence-gated, W16) | D INFERRED |
| 0x15000007 | S>C |  | H 0x0141fb60 | - | - | CharacterTrade: reply/notification. Character trade. Likely reply to C>S 0x15000006 (request even / reply odd convention). | chartrade (INFERRED) |  | D INFERRED |
| 0x15000008 | S>C |  | H 0x0141fab0 | - | +0x0 int | CharacterTrade: reply/notification. Character trade. | chartrade (INFERRED) |  | D INFERRED |
| 0x15000009 | C>S |  | B 0x014203b0; B 0x01421140 | 16 | - | CharacterTrade: request. Character trade. | chartrade (INFERRED) | S804 P8 coverage no-reply rows (W16) | D INFERRED |

### 0x1600 Alliance (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x16000002 | S>C |  | H 0x01426fa0 | - | - | Alliance: reply/notification. Guild alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16000004 | C>S |  | B 0x01423cd0 | 84 | - | Alliance: request. Guild alliance. | guild (INFERRED) (INFERRED) | S932 wire-W05-alliance | D INFERRED |
| 0x16000011 | S>C |  | H 0x014275b0 | - | - | Alliance: reply/notification. Guild alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16000012 | S>C |  | H 0x01427680 | - | +0x44 short, +0x364 short, +0x38e short, +0x3b8 undefined4, +0x3bc undefined2, +0x3be undefined2 | Alliance: reply/notification. Guild alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16000013 | S>C |  | H 0x014278d0 | - | - | Alliance: reply/notification. Guild alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16000014 | S>C |  | H 0x01426bc0(cmp) | - | - | Alliance: reply/notification. Guild alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |

### 0x1601 Alliance (10)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x16010000 | S>C |  | H 0x01427c00 | - | +0x6e char | Alliance: reply/notification. Guild alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16010001 | C>S |  | B 0x01423ee0 | 140 | +0x6e ptr/copy | Alliance: request. Guild alliance. | guild (INFERRED) (INFERRED) | S932 wire-W05-alliance | D INFERRED |
| 0x16010002 | S>C |  | H 0x01427ff0 | - | +0x44 undefined4 | Alliance: reply/notification. Guild alliance. Likely reply to C>S 0x16010001 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16010003 | C>S |  | B 0x01423e70 | 84 | - | Alliance: request. Guild alliance. | guild (INFERRED) (INFERRED) | S932 wire-W05-alliance | D INFERRED |
| 0x16010004 | S>C |  | H 0x01427ed0 | - | +0x44 undefined4 | Alliance: reply/notification. Guild alliance. Likely reply to C>S 0x16010003 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16010005 | C>S |  | B 0x01423fe0 | 128 | +0x6e undefined1 | Alliance: request. Guild alliance. | guild (INFERRED) (INFERRED) | S932 wire-W05-alliance | D INFERRED |
| 0x16010006 | S>C |  | H 0x01428110 | - | +0x44 undefined1 | Alliance: reply/notification. Guild alliance. Likely reply to C>S 0x16010005 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16010007 | S>C |  | H 0x014282d0 | - | - | Alliance: reply/notification. Guild alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16010008 | C>S |  | B 0x01424160 | 88 | +0x44 undefined1 | Alliance: request. Guild alliance. | guild (INFERRED) (INFERRED) | S932 wire-W05-alliance | D INFERRED |
| 0x16010009 | S>C |  | H 0x014284a0 | - | +0x98 undefined1 | Alliance: reply/notification. Guild alliance. Likely reply to C>S 0x16010008 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |

### 0x1602 Alliance (14)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x16020000 | C>S |  | B 0x014241c0 | 884 | +0x44 ptr/copy | Alliance: request. Guild alliance + chat. | guild (INFERRED) (INFERRED) | S903 Alliance wire (W03) | D INFERRED |
| 0x16020001 | S>C |  | H 0x01428700 | - | +0x44 undefined1 | Alliance: reply/notification. Guild alliance + chat. Likely reply to C>S 0x16020000 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16020002 | S>C |  | H 0x01428820 | - | - | Alliance: reply/notification. Guild alliance + chat. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16020003 | C>S |  | B 0x01424380 | 88 | +0x44 undefined2, +0x46 undefined2 | Alliance: request. Guild alliance + chat. | guild (INFERRED) (INFERRED) | S903 Alliance wire (W03) | D INFERRED |
| 0x16020004 | S>C |  | H 0x01428e20 | - | +0x48 undefined4, +0x4c undefined4, +0x58 undefined1 | Alliance: reply/notification. Guild alliance + chat. Likely reply to C>S 0x16020003 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16020005 | S>C |  | H 0x01428fe0 | - | +0x44 undefined2, +0x46 undefined2 | Alliance: reply/notification. Guild alliance + chat. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16020008 | S>C |  | H 0x014290d0 | - | +0x44 short | Alliance: reply/notification. Guild alliance + chat. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x16020009 | C>S |  | B 0x01424450 | 84 | - | Alliance: request. Guild alliance + chat. | guild (INFERRED) (INFERRED) | S903 Alliance wire (W03) | D INFERRED |
| 0x1602000a | S>C |  | H 0x014292e0 | - | +0x44 undefined1 | Alliance: reply/notification. Guild alliance + chat. Likely reply to C>S 0x16020009 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x1602000b | both |  | B 0x012f4dd0; H 0x012fa270 | 52,96,112,132,560,668 | +0x0 undefined4, +0x8 undefined4, +0x2c undefined1, +0x30 undefined4, +0x204 undefined4 | Alliance: request and reply share this opcode. Guild alliance + chat. | guild (INFERRED) (INFERRED) | S803 WIRE-P8 world/matching/alliance chat | D INFERRED |
| 0x1602000c | C>S |  | B 0x014242a0 | 128 | +0x44 ptr/copy, +0x6e undefined1 | Alliance: request. Guild alliance + chat. | guild (INFERRED) (INFERRED) | S903 Alliance wire (W03) | D INFERRED |
| 0x1602000d | S>C |  | H 0x014289b0 | - | +0x44 undefined1 | Alliance: reply/notification. Guild alliance + chat. Likely reply to C>S 0x1602000c (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x1602000e | S>C |  | H 0x01428ae0 | - | +0x6e undefined1 | Alliance: reply/notification. Guild alliance + chat. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x1602000f | S>C |  | H 0x01428cd0 | - | +0x98 undefined1 | Alliance: reply/notification. Guild alliance + chat. | guild (INFERRED) (INFERRED) |  | D INFERRED |

### 0x1700 Notice (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x17000000 | C>S |  | B 0x014559b0 | 16 | - | Notice: request. Server notice. | MISSING | S963 NoticeWire | D INFERRED |

### 0x1701 GuildTournament (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x17010001 | S>C |  | H 0x01254c40; H 0x01255660 | - | +0x34 undefined4, +0x38 char, +0x3c ptr | GuildTournament: reply/notification. Guild tournament info/seed. | tourney (INFERRED) |  | D INFERRED |

### 0x1702 GuildTournament (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x17020001 | S>C |  | H 0x012560a0 | - | +0x34 int, +0x3c ptr | GuildTournament: reply/notification. Guild tournament entry member. | tourney (INFERRED) |  | D INFERRED |
| 0x17020007 | S>C |  | H 0x01392b80 | - | +0x34 char | GuildTournament: reply/notification. Guild tournament entry member. | tourney (INFERRED) |  | D INFERRED |

### 0x1704 GuildTournament (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x17040012 | S>C |  | H 0x01258b20 | - | +0x94 undefined4 | GuildTournament: reply/notification. Guild tournament betting. | tourney (INFERRED) |  | D INFERRED |
| 0x17040014 | S>C |  | H 0x01258860(cmp) | - | - | GuildTournament: reply/notification. Guild tournament betting. | tourney (INFERRED) |  | D INFERRED |
| 0x17040015 | S>C |  | H 0x01258860(cmp) | - | - | GuildTournament: reply/notification. Guild tournament betting. | tourney (INFERRED) |  | D INFERRED |
| 0x17040017 | S>C |  | H 0x0125a960 | - | +0x34 undefined4 | GuildTournament: reply/notification. Guild tournament betting. | tourney (INFERRED) |  | D INFERRED |
| 0x1704001b | S>C |  | H 0x0125a7b0 | - | +0x34 int, +0x38 ptr | GuildTournament: reply/notification. Guild tournament betting. | tourney (INFERRED) |  | D INFERRED |

### 0x1705 GuildTournament (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x17050002 | S>C |  | H 0x013993e0 | - | +0x34 undefined1, +0x35 undefined1, +0x36 undefined1 | GuildTournament: reply/notification. Guild tournament. | tourney (INFERRED) |  | D INFERRED |
| 0x17050013 | S>C |  | H 0x013929c0 | - | - | GuildTournament: reply/notification. Guild tournament. | tourney (INFERRED) |  | D INFERRED |

### 0x1801 (unattributed) (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x18010007 | S>C |  | H 0x0140c8b0 | - | - | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |
| 0x18010010 | S>C |  | H 0x0140da90 | - | +0x4 uint, +0x8 int, +0xc byte, +0xd byte, +0x10 ptr | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |
| 0x18010012 | S>C |  | H 0x0140e170 | - | +0x4 uint, +0x8 char, +0xc byte, +0xd byte, +0x10 ptr | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |

### 0x1e00 PC event (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x1e000000 | S>C |  | H 0x00876ad0; H 0x008e14f0 | - | +0x0 undefined4, +0x4 undefined4 | PC event: reply/notification. PC event (dispatched by enter-world dispatcher). | MISSING |  | D INFERRED |
| 0x1e000001 | S>C |  | H 0x00876b40; H 0x008e14a0 | - | +0x0 undefined4, +0x4 undefined4 | PC event: reply/notification. PC event (dispatched by enter-world dispatcher). | MISSING |  | D INFERRED |

### 0x2000 DKSquare (22)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x20000000 | C>S |  | B 0x0129c070 | 128 | +0x0 undefined1, +0x30 undefined1 | DKSquare: request. DK Square battle. | dksquare (INFERRED) | S600 P9 DK1 Square lobby 0x2000 (W17) | D INFERRED |
| 0x20000001 | C>S |  | B 0x0129c100 | 120 | +0x0 undefined1, +0x30 undefined4 | DKSquare: request. DK Square battle. | dksquare (INFERRED) | S600 P9 DK1 Square lobby 0x2000 (W17) | D INFERRED |
| 0x20000002 | C>S |  | B 0x0129c190 | 72 | +0x0 undefined1, +0x30 undefined4 | DKSquare: request. DK Square battle. | dksquare (INFERRED) | S600 P9 DK1 Square lobby 0x2000 (W17) | D INFERRED |
| 0x20000004 | S>C |  | H 0x012a7040 | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000005 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000006 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000008 | S>C |  | H 0x016c70e6 | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000009 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x2000000a | C>S |  | B 0x0129c220 | 76 | +0x0 undefined1, +0x34 undefined4, +0x38 bool | DKSquare: request. DK Square battle. | dksquare (INFERRED) | S600 P9 DK1 Square lobby 0x2000 (W17) | D INFERRED |
| 0x2000000b | S>C |  | H 0x016c70e6 | - | - | DKSquare: reply/notification. DK Square battle. Likely reply to C>S 0x2000000a (request even / reply odd convention). | dksquare (INFERRED) |  | D INFERRED |
| 0x2000000c | C>S |  | B 0x0129bff0 | 68 | +0x0 undefined1 | DKSquare: request. DK Square battle. | dksquare (INFERRED) | S600 P9 DK1 Square lobby 0x2000 (W17) | D INFERRED |
| 0x2000000d | S>C |  | H 0x016c70e6 | - | - | DKSquare: reply/notification. DK Square battle. Likely reply to C>S 0x2000000c (request even / reply odd convention). | dksquare (INFERRED) |  | D INFERRED |
| 0x2000000e | S>C |  | H 0x016c70e6 | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x2000000f | S>C |  | H 0x016c70e6 | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000013 | S>C |  | H 0x01245b30 | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000014 | S>C |  | H 0x00740220 | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000015 | S>C |  | H 0x016c70e6 | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000024 | S>C |  | H 0x012aa510 | - | +0x34 undefined4, +0x38 undefined2 | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000027 | C>S |  | B 0x0129b310 | 148 | +0x0 undefined1 | DKSquare: request. DK Square battle. | dksquare (INFERRED) | S600 P9 DK1 Square lobby 0x2000 (W17) | D INFERRED |
| 0x20000028 | S>C |  | H 0x016c70e6 | - | - | DKSquare: reply/notification. DK Square battle. Likely reply to C>S 0x20000027 (request even / reply odd convention). | dksquare (INFERRED) |  | D INFERRED |
| 0x20000031 | S>C |  | H 0x012a5f30(cmp) | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |
| 0x20000032 | S>C |  | H 0x00740570 | - | - | DKSquare: reply/notification. DK Square battle. | dksquare (INFERRED) |  | D INFERRED |

### 0x2100 Aggro (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x21000000 | S>C |  | H 0x008e0b70 | - | +0x0 undefined1, +0x1 undefined1, +0x4 undefined4, +0x8 undefined4, +0xc undefined4, +0x10 undefined4 | Aggro: reply/notification. Aggro event. | MISSING |  | D INFERRED |
| 0x21000001 | S>C |  | H 0x008e0b00(cmp) | - | - | Aggro: reply/notification. Aggro event. | MISSING |  | D INFERRED |

### 0x2200 Unity (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x22000001 | S>C | STATUS_PUSH | H 0x008e9e40(cmp) | obs 45,61,37,77 | - | server push (variable size 37-77), handler FUN_008e9e40 reads a list via reader vf+0x14 | MISSING |  | D+O INFERRED |

### 0x3000 Alliance (ext) (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x30000000 | C>S |  | B 0x01423af0 | 60 | +0x2a undefined1 | Alliance (ext): request. Alliance. | guild (INFERRED) (INFERRED) | S601 P9 Guild Alliance 0x3000/0x3003 (W17) | D INFERRED |
| 0x30000001 | S>C |  | H 0x01426e40 | - | - | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30000000 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x30000002 | C>S |  | B 0x01423c70 | 20 | +0x0 undefined1 | Alliance (ext): request. Alliance. | guild (INFERRED) (INFERRED) | S601 P9 Guild Alliance 0x3000/0x3003 (W17) | D INFERRED |
| 0x30000004 | C>S |  | B 0x01423d30 | 60 | +0x2a undefined1 | Alliance (ext): request. Alliance. | guild (INFERRED) (INFERRED) | S601 P9 Guild Alliance 0x3000/0x3003 (W17) | D INFERRED |
| 0x30000005 | S>C |  | H 0x01427320 | - | +0x0 char, +0x4 int, +0x8 undefined4 | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30000004 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x30000006 | S>C |  | H 0x01427170 | - | +0x0 undefined1 | Alliance (ext): reply/notification. Alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |

### 0x3003 Alliance (ext) (9)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x30030000 | C>S |  | B 0x013a80b0 | 20 | +0x0 undefined2, +0x2 undefined1 | Alliance (ext): request. Alliance. | guild (INFERRED) (INFERRED) | S601 P9 Guild Alliance 0x3000/0x3003 (W17) | D INFERRED |
| 0x30030001 | S>C |  | H 0x013abbc0 | - | - | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30030000 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x30030002 | S>C |  | H 0x01426bc0(cmp) | - | - | Alliance (ext): reply/notification. Alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x30030003 | S>C |  | H 0x014291a0 | - | - | Alliance (ext): reply/notification. Alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x30030004 | C>S |  | B 0x014243f0 | 16 | - | Alliance (ext): request. Alliance. | guild (INFERRED) (INFERRED) | S601 P9 Guild Alliance 0x3000/0x3003 (W17) | D INFERRED |
| 0x30030005 | S>C |  | H 0x01426bc0(cmp) | - | - | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30030004 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x30030006 | C>S |  | B 0x014244b0 | 16 | - | Alliance (ext): request. Alliance. | guild (INFERRED) (INFERRED) | S601 P9 Guild Alliance 0x3000/0x3003 (W17) | D INFERRED |
| 0x30030007 | S>C |  | H 0x01429400 | - | - | Alliance (ext): reply/notification. Alliance. Likely reply to C>S 0x30030006 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x30030008 | S>C |  | H 0x014294d0 | - | +0x2a short | Alliance (ext): reply/notification. Alliance. | guild (INFERRED) (INFERRED) |  | D INFERRED |

### 0x4000 CashInventory (ext) (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x40000005 | C>S |  | B 0x0142b4b0 | 20 | +0x0 ushort | CashInventory (ext): request. Cash inventory. | cashclaim (INFERRED) | S602 P9 CashInventory 0x40/0x41 (W17) | D INFERRED |
| 0x40000006 | S>C |  | H 0x0142d820 | - | +0x0 int, +0x4 undefined2, +0x6 undefined1 | CashInventory (ext): reply/notification. Cash inventory. Likely reply to C>S 0x40000005 (request even / reply odd convention). | cashclaim (INFERRED) |  | D INFERRED |
| 0x40000007 | C>S |  | B 0x0142b530 | 44 | +0x0 undefined4, +0x4 ptr/copy | CashInventory (ext): request. Cash inventory. | cashclaim (INFERRED) | S602 P9 CashInventory 0x40/0x41 (W17) | D INFERRED |
| 0x40000008 | S>C |  | H 0x0142d9b0 | - | +0x0 int, +0x4 ptr | CashInventory (ext): reply/notification. Cash inventory. Likely reply to C>S 0x40000007 (request even / reply odd convention). | cashclaim (INFERRED) |  | D INFERRED |
| 0x40000009 | S>C |  | H 0x0142d600(cmp) | - | - | CashInventory (ext): reply/notification. Cash inventory. | cashclaim (INFERRED) |  | D INFERRED |

### 0x4100 Colosseum (8)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x41000001 | C>S |  | B 0x014e2cb0 | 24 | +0x0 uint, +0x4 undefined2 | Colosseum: request. Colosseum. | colosseum (INFERRED) | S603 P9 Colosseum selection 0x41000001 + guild 0x4200000x (W17) | D INFERRED |
| 0x41000002 | S>C |  | H 0x012ea130(cmp) | - | - | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41000001 (request even / reply odd convention). | colosseum (INFERRED) |  | D INFERRED |
| 0x41000003 | C>S |  | B 0x01431790 | 16 | - | Colosseum: request. Colosseum. | colosseum (INFERRED) | S602 P9 CashInventory 0x40/0x41 (W17) | D INFERRED |
| 0x41000004 | S>C |  | H 0x01437060 | - | +0x0 undefined1 | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41000003 (request even / reply odd convention). | colosseum (INFERRED) |  | D INFERRED |
| 0x41000005 | S>C |  | H 0x01436b30 | - | +0x0 undefined4, +0x4 undefined2, +0x8 undefined4, +0xc ushort, +0x10 undefined1 | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41000006 | C>S |  | B 0x01431720 | 16 | - | Colosseum: request. Colosseum. | colosseum (INFERRED) | S602 P9 CashInventory 0x40/0x41 (W17) | D INFERRED |
| 0x41000007 | S>C |  | H 0x01436f20 | - | +0x0 undefined1 | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41000006 (request even / reply odd convention). | colosseum (INFERRED) |  | D INFERRED |
| 0x41000008 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |

### 0x4101 Colosseum (1)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x41010001 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |

### 0x4102 Colosseum (8)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x41020001 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41020002 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41020003 | S>C |  | H 0x014372a0 | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41020004 | C>S |  | B 0x00bb0bb0(factory) | 16 | - | Colosseum: request. Colosseum. | colosseum (INFERRED) | S602 P9 CashInventory 0x40/0x41 (W17) | D INFERRED |
| 0x41020005 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41020004 (request even / reply odd convention). | colosseum (INFERRED) |  | D INFERRED |
| 0x41020006 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41020007 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41020008 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |

### 0x4103 Colosseum (9)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x41030001 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41030002 | C>S |  | B 0x014318c0 | 16 | - | Colosseum: request. Colosseum. | colosseum (INFERRED) | S602 P9 CashInventory 0x40/0x41 (W17) | D INFERRED |
| 0x41030003 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41030002 (request even / reply odd convention). | colosseum (INFERRED) |  | D INFERRED |
| 0x41030004 | C>S |  | B 0x01431800 | 176 | +0x0 undefined4, +0x4 undefined4, +0x8 int, +0xc undefined4, +0x10 undefined4, +0x14 undefined4 | Colosseum: request. Colosseum. | colosseum (INFERRED) | S602 P9 CashInventory 0x40/0x41 (W17) | D INFERRED |
| 0x41030005 | S>C |  | H 0x01436d00 | - | +0x0 undefined4, +0x4 ptr | Colosseum: reply/notification. Colosseum. Likely reply to C>S 0x41030004 (request even / reply odd convention). | colosseum (INFERRED) |  | D INFERRED |
| 0x41030006 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41030007 | S>C |  | H 0x01436ec0 | - | +0x0 ptr | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41030008 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41030009 | S>C |  | H 0x01436960(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |

### 0x4104 Colosseum (3)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x41040001 | S>C |  | H 0x0125e4f0(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41040002 | S>C |  | H 0x0125e4f0(cmp) | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41040003 | S>C |  | H 0x0125f790 | - | - | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |

### 0x4105 Colosseum (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x41050001 | S>C |  | H 0x0125e9c0 | - | +0x0 int, +0x4 int, +0x32 undefined1 | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |
| 0x41050002 | S>C |  | H 0x0125eb30 | - | +0x0 int, +0x2e undefined1 | Colosseum: reply/notification. Colosseum. | colosseum (INFERRED) |  | D INFERRED |

### 0x4200 GuildTournament / Donation (6)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x42000001 | S>C |  | H 0x012eaab0(cmp) | - | - | GuildTournament / Donation: reply/notification. Guild tournament entry, donation. | tourney (INFERRED) |  | D INFERRED |
| 0x42000002 | C>S |  | B 0x014e3360 | 20 | +0x0 undefined1 | GuildTournament / Donation: request. Guild tournament entry, donation. | tourney (INFERRED) | S603 P9 Colosseum selection 0x41000001 + guild 0x4200000x (W17) | D INFERRED |
| 0x42000003 | C>S |  | B 0x014e34d0(factory) | 20 | - | GuildTournament / Donation: request. Guild tournament entry, donation. | tourney (INFERRED) | S603 P9 Colosseum selection 0x41000001 + guild 0x4200000x (W17) | D INFERRED |
| 0x42000004 | S>C |  | H 0x012eaab0(cmp) | - | - | GuildTournament / Donation: reply/notification. Guild tournament entry, donation. Likely reply to C>S 0x42000003 (request even / reply odd convention). | tourney (INFERRED) |  | D INFERRED |
| 0x42000005 | S>C |  | H 0x01437c20(cmp); H 0x01253ca0(cmp) | - | - | GuildTournament / Donation: reply/notification. Guild tournament entry, donation. | tourney (INFERRED) |  | D INFERRED |
| 0x42000007 | S>C |  | H 0x01437c20(cmp); H 0x012543f0(cmp) | - | - | GuildTournament / Donation: reply/notification. Guild tournament entry, donation. | tourney (INFERRED) |  | D INFERRED |

### 0x4201 GuildTournament (2)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x42010001 | C>S |  | B 0x01254b90; B 0x012555b0 | 16 | - | GuildTournament: request. Guild tournament info. | tourney (INFERRED) | S604 P9 0x4201-0x4205 gt/guild family (W17) | D INFERRED |
| 0x42010003 | S>C |  | H 0x01437c20(cmp); H 0x01255370(cmp) | - | - | GuildTournament: reply/notification. Guild tournament info. | tourney (INFERRED) |  | D INFERRED |

### 0x4202 Guild (tournament) (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x42020001 | C>S |  | B 0x01255ff0 | 16 | - | Guild (tournament): request. Guild tournament guild UI. | tourney (INFERRED) | S604 P9 0x4201-0x4205 gt/guild family (W17) | D INFERRED |
| 0x42020003 | S>C |  | H 0x01437c20(cmp); H 0x01257380 | - | - | Guild (tournament): reply/notification. Guild tournament guild UI. | tourney (INFERRED) |  | D INFERRED |
| 0x42020004 | C>S |  | B 0x012571e0 | 24 | +0x0 undefined4, +0x4 undefined4 | Guild (tournament): request. Guild tournament guild UI. | tourney (INFERRED) | S604 P9 0x4201-0x4205 gt/guild family (W17) | D INFERRED |
| 0x42020005 | S>C |  | H 0x012575d0 | - | +0x0 undefined2, +0x2 undefined2 | Guild (tournament): reply/notification. Guild tournament guild UI. Likely reply to C>S 0x42020004 (request even / reply odd convention). | tourney (INFERRED) |  | D INFERRED |
| 0x42020006 | C>S |  | B 0x01390ae0 | 16 | - | Guild (tournament): request. Guild tournament guild UI. | tourney (INFERRED) | S604 P9 0x4201-0x4205 gt/guild family (W17) | D INFERRED |

### 0x4203 GuildTournament (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x42030001 | C>S |  | B 0x01258650 | 28 | +0x0 undefined4, +0x4 undefined4, +0x8 undefined4 | GuildTournament: request. Guild tournament betting. | tourney (INFERRED) | S604 P9 0x4201-0x4205 gt/guild family (W17) | D INFERRED |
| 0x42030002 | C>S |  | B 0x0125a6e0 | 20 | +0x0 undefined4 | GuildTournament: request. Guild tournament betting. | tourney (INFERRED) | S604 P9 0x4201-0x4205 gt/guild family (W17) | D INFERRED |
| 0x42030003 | C>S |  | B 0x0125a670 | 16 | - | GuildTournament: request. Guild tournament betting. | tourney (INFERRED) | S604 P9 0x4201-0x4205 gt/guild family (W17) | D INFERRED |
| 0x42030004 | S>C |  | H 0x01437dd0; H 0x0125a420(cmp) | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined2, +0xc undefined4 | GuildTournament: reply/notification. Guild tournament betting. Likely reply to C>S 0x42030003 (request even / reply odd convention). | tourney (INFERRED) |  | D INFERRED |

### 0x4205 GuildTournament (ext) (4)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x42050001 | C>S |  | B 0x01257280 | 24 | +0x0 undefined4, +0x4 undefined4 | GuildTournament (ext): request. Guild tournament. | tourney (INFERRED) | S604 P9 0x4201-0x4205 gt/guild family (W17) | D INFERRED |
| 0x42050002 | S>C |  | H 0x012577c0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined2, +0xc undefined4 | GuildTournament (ext): reply/notification. Guild tournament. Likely reply to C>S 0x42050001 (request even / reply odd convention). | tourney (INFERRED) |  | D INFERRED |
| 0x42050003 | S>C |  | H 0x0125e5d0 | - | - | GuildTournament (ext): reply/notification. Guild tournament. | tourney (INFERRED) |  | D INFERRED |
| 0x42050004 | S>C |  | H 0x0125e7f0 | - | - | GuildTournament (ext): reply/notification. Guild tournament. | tourney (INFERRED) |  | D INFERRED |

### 0x4300 SuperChat (5)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x43000001 | S>C |  | H 0x01442ff0(cmp) | - | - | SuperChat: reply/notification. Super chat (megaphone). | megaphone (INFERRED) |  | D INFERRED |
| 0x43000002 | S>C |  | H 0x01442ff0(cmp) | - | - | SuperChat: reply/notification. Super chat (megaphone). | megaphone (INFERRED) |  | D INFERRED |
| 0x43000003 | C>S |  | B 0x013a6310; B 0x014d1660 | 539 | +0x0 undefined2, +0x2 ushort, +0x4 undefined2, +0x6 undefined1, +0x7 undefined1, +0x8 undefined2 | SuperChat: request. Super chat (megaphone). | megaphone (INFERRED) | S605 P9 CashItem 0x43, FieldBossSupply 0x46, CoinExchange 0x48 (W17) | D INFERRED |
| 0x43000004 | S>C |  | H 0x013ac3d0 | - | +0x0 char | SuperChat: reply/notification. Super chat (megaphone). Likely reply to C>S 0x43000003 (request even / reply odd convention). | megaphone (INFERRED) |  | D INFERRED |
| 0x43000005 | S>C |  | H 0x012fad50 | - | +0x2 ushort, +0x4 ushort, +0x6 char, +0x8 short, +0x32 short | SuperChat: reply/notification. Super chat (megaphone). | megaphone (INFERRED) |  | D INFERRED |

### 0x4500 (unattributed) (7)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x45000002 | S>C |  | H 0x0148b6b0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined2 | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |
| 0x45000005 | S>C |  | H 0x0148b3a0 | - | +0x0 undefined4, +0x4 undefined4, +0x8 undefined2 | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |
| 0x45000008 | S>C |  | H 0x0148b960 | - | +0x0 undefined2, +0x2 undefined2, +0x4 undefined2, +0x6 undefined2, +0x8 undefined2, +0xa undefined2 | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |
| 0x45000009 | S>C |  | H 0x0148bb30 | - | +0x0 int | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |
| 0x4500000a | S>C |  | H 0x01490c40(cmp) | - | - | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |
| 0x4500000b | S>C |  | H 0x01490c40(cmp) | - | - | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |
| 0x4500000c | S>C |  | H 0x0148b310(cmp) | - | - | (unattributed): reply/notification. Unattributed. | MISSING |  | D INFERRED |

### 0x4600 DKRPvPBattle (12)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x46000004 | C>S |  | B 0x014a7530 | 76 | +0x0 ptr/copy, +0x2a undefined1 | DKRPvPBattle: request. DKR PvP battle. | dkr (INFERRED) | S605 P9 CashItem 0x43, FieldBossSupply 0x46, CoinExchange 0x48 (W17) | D INFERRED |
| 0x46000005 | S>C |  | H 0x014a8f40 | - | +0x0 int | DKRPvPBattle: reply/notification. DKR PvP battle. Likely reply to C>S 0x46000004 (request even / reply odd convention). | dkr (INFERRED) |  | D INFERRED |
| 0x46000009 | S>C |  | H 0x014a7c00(cmp) | - | - | DKRPvPBattle: reply/notification. DKR PvP battle. | dkr (INFERRED) |  | D INFERRED |
| 0x4600000c | S>C |  | H 0x014a9970 | - | +0x0 undefined1, +0x1 undefined1, +0x47 undefined1, +0x48 undefined1, +0x94 undefined1, +0xc3 ptr | DKRPvPBattle: reply/notification. DKR PvP battle. | dkr (INFERRED) |  | D INFERRED |
| 0x4600000d | S>C |  | H 0x014a7c00(cmp) | - | - | DKRPvPBattle: reply/notification. DKR PvP battle. | dkr (INFERRED) |  | D INFERRED |
| 0x4600000e | S>C |  | H 0x014a9d10 | - | +0x0 undefined1, +0x1 undefined1, +0x2 undefined1, +0x8 int | DKRPvPBattle: reply/notification. DKR PvP battle. | dkr (INFERRED) |  | D INFERRED |
| 0x4600000f | S>C |  | H 0x014a7c00(cmp) | - | - | DKRPvPBattle: reply/notification. DKR PvP battle. | dkr (INFERRED) |  | D INFERRED |
| 0x46000010 | C>S |  | B 0x014a7600 | 32 | - | DKRPvPBattle: request. DKR PvP battle. | dkr (INFERRED) | S605 P9 CashItem 0x43, FieldBossSupply 0x46, CoinExchange 0x48 (W17) | D INFERRED |
| 0x46000011 | S>C |  | H 0x014a7c00(cmp) | - | - | DKRPvPBattle: reply/notification. DKR PvP battle. Likely reply to C>S 0x46000010 (request even / reply odd convention). | dkr (INFERRED) |  | D INFERRED |
| 0x46000012 | C>S |  | B 0x013d5b50(factory) | 32 | - | DKRPvPBattle: request. DKR PvP battle. | dkr (INFERRED) | S605 P9 CashItem 0x43, FieldBossSupply 0x46, CoinExchange 0x48 (W17) | D INFERRED |
| 0x46000013 | S>C |  | H 0x014a96b0 | - | +0x0 undefined4, +0x4 ptr, +0xc float | DKRPvPBattle: reply/notification. DKR PvP battle. Likely reply to C>S 0x46000012 (request even / reply odd convention). | dkr (INFERRED) |  | D INFERRED |
| 0x46000014 | S>C |  | H 0x014aa270 | - | +0x2a undefined1 | DKRPvPBattle: reply/notification. DKR PvP battle. | dkr (INFERRED) |  | D INFERRED |

### 0x4800 GuildWar (12)

| opcode | dir | name | 0.0.1 B/H | size | body fields | description | 4.2.0 | bridge | src |
|---|---|---|---|---|---|---|---|---|---|
| 0x48000001 | S>C |  | H 0x014b8fd0 | - | +0x0 undefined1, +0x8 undefined4, +0xc undefined4, +0x10 undefined4 | GuildWar: reply/notification. Guild war declare/accept. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x48000002 | S>C |  | H 0x014b8f00(cmp) | - | - | GuildWar: reply/notification. Guild war declare/accept. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x48000003 | C>S |  | B 0x014bac50 | 20 | +0x0 undefined1 | GuildWar: request. Guild war declare/accept. | guild (INFERRED) (INFERRED) | S605 P9 CashItem 0x43, FieldBossSupply 0x46, CoinExchange 0x48 (W17) | D INFERRED |
| 0x48000004 | S>C |  | H 0x014b92a0 | - | +0x4 ptr | GuildWar: reply/notification. Guild war declare/accept. Likely reply to C>S 0x48000003 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x48000005 | C>S |  | B 0x00d5a370; B 0x00d5aba0(factory) | 88 | +0x44 char, +0x45 undefined1 | GuildWar: request. Guild war declare/accept. | guild (INFERRED) (INFERRED) | S605 P9 CashItem 0x43, FieldBossSupply 0x46, CoinExchange 0x48 (W17) | D INFERRED |
| 0x48000006 | S>C |  | H 0x014b93c0 | - | - | GuildWar: reply/notification. Guild war declare/accept. Likely reply to C>S 0x48000005 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x48000007 | S>C |  | H 0x014b8f00(cmp) | - | - | GuildWar: reply/notification. Guild war declare/accept. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x48000008 | C>S |  | B 0x014bacb0 | 20 | +0x0 undefined1 | GuildWar: request. Guild war declare/accept. | guild (INFERRED) (INFERRED) | S605 P9 CashItem 0x43, FieldBossSupply 0x46, CoinExchange 0x48 (W17) | D INFERRED |
| 0x48000009 | S>C |  | H 0x014b94b0 | - | - | GuildWar: reply/notification. Guild war declare/accept. Likely reply to C>S 0x48000008 (request even / reply odd convention). | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x4800000a | S>C |  | H 0x014b9560 | - | - | GuildWar: reply/notification. Guild war declare/accept. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x4800000b | S>C |  | H 0x014b9600 | - | - | GuildWar: reply/notification. Guild war declare/accept. | guild (INFERRED) (INFERRED) |  | D INFERRED |
| 0x4800000c | S>C |  | H 0x014b92e0 | - | - | GuildWar: reply/notification. Guild war declare/accept. | guild (INFERRED) (INFERRED) |  | D INFERRED |
