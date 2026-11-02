# A2 (2Moons 2007 / Action 2): every opcode, explained

Client: 2Moons/Dekaron Open Beta `dekaron.exe` (PE build 2007-07-30), unpacked. Source of truth: `decompiled-source/a2-2moons-2007/` (Ghidra, 42,061 functions, one file per 64 KB).
Server reference: HellSpider Action2 server files (data only). Wire evidence: a capture of the A2 client and test probes talking to that server on the box on 2026-10-29 (login, character select, enter Loa Castle, NPCs, monsters).
Evidence labels: **decompile**, **server-ref** (HellSpider wire capture / server data), **Global 0.0.1 counterpart** (INFERRED when used for purpose). Login packets are documented by layout only; no credentials are recorded.

## Wire basics

- Header: 16 B big-endian: +0 u32 bswap(~crc32(cipher[4:])) | +4 u16 seq | +6 u16 total len (max 0x400) | +8 u32 context | +0xC u32 opcode
- Cipher: c[i]=p[i]^(CRC32TABLE[i&0xff]&0xff)^key for i>=4; key 0x0F before handshake, then key0^key1 from 0x00020081 (+0x18,+0x1c)
- Reliability: low byte of opcode bit 0x80 clear = reliable (ACK 0x00020005 {u16 seq}); set = control

## Counts

| status | count | meaning |
|---|---|---|
| explained | 55 | purpose from A2 decompile strings / hand analysis / wire capture, and layout (or empty body) known |
| partial_layout | 352 | some offsets/types recovered; purpose INFERRED from Global counterpart or unknown |
| located_only | 206 | handler/builder/dispatcher located with file:line, layout not recovered |
| wire_only | 0 | seen on the wire only |
| **total** | **613** | |

Direction: S>C 325, C>S 263, both 19, internal 6

Columns: **layout** offsets count from the start of the 16-byte header (body begins at +10). Anything not listed is unknown and was not guessed. **ref** is `file:line` in the decompiled source (folder 3). Full detail (every handler, builder, debug string and evidence label) is in the JSON twin.

## 0x0001

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x00010000` | INT_CONNECT_REQ | internal | +14 u32 IPv4 address; +18 u16 port | Internal event (never on the wire): connect request to ip:port. | decompiled-source/a2-2moons-2007/dekaron_00460000.c:3690 | explained |
| `0x00010001` | INT_DISCONNECT | internal | empty body | Internal event (never on the wire): disconnect. | decompiled-source/a2-2moons-2007/dekaron_00400000.c:12763<br>decompiled-source/a2-2moons-2007/dekaron_00460000.c:3551<br>decompiled-source/a2-2moons-2007/dekaron_00460000.c:3774 | explained |
| `0x00010002` | INT_CONNECTED | internal | unknown | Internal event (never on the wire): session established. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3114<br>decompiled-source/a2-2moons-2007/dekaron_00460000.c:330<br>decompiled-source/a2-2moons-2007/dekaron_00460000.c:4318 | located_only |
| `0x00010003` | INT_CLOSED | internal | unknown | Internal event (never on the wire): session closed. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3567<br>decompiled-source/a2-2moons-2007/dekaron_00460000.c:4295<br>decompiled-source/a2-2moons-2007/dekaron_00460000.c:4318 | located_only |
| `0x00010004` | INT_CONNECT_FAILED | internal | unknown | Internal event (never on the wire): connect failed or 7000 ms timeout. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:4076<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:4121<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:4197 … | located_only |
| `0x00010005` | INT_LATENCY | internal | +10 u32[4] latency stats | Internal event (never on the wire): latency statistics (4 x u32). | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3172<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:3636<br>decompiled-source/a2-2moons-2007/dekaron_00460000.c:3576 … | explained |

## 0x0002

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x00020005` | SESSION_ACK | both | +10 u16 BE acked sequence number | Reliable-layer ACK for a sequenced packet. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3524<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:3703<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:8424 | explained |
| `0x00020080` | CON | C>S | +10 u32 BE client tick (ms) | Client hello, first packet after TCP connect; cipher key still 0x0F. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:2760 | explained |
| `0x00020081` | CON_ACK | S>C | +10 u32 BE server time; +14 u32 BE echoed client tick (RTT); +18 u8 key0; +1c u8 key1; +20 u8[64] copied to session+0x35; purpose unknown (zeros seen) | Server hello. Sets the cipher key (key0^key1) and session blob. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3051<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:3172 | explained |
| `0x00020082` | CON_CONFIRM | C>S | +10 u32 BE echoed server time | Client confirms handshake; session becomes Established. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3148 | explained |
| `0x00020083` | PING | both | +10 u32 BE sender tick | Keepalive; either side sends after idle (client: >20000 ms). | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3588<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:3636<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:3703 | explained |
| `0x00020084` | PONG | both | +10 u32 BE echoed tick | Reply to PING, echoes the tick. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3501<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:3612<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:3703 | explained |
| `0x0002008a` | GG_AUTH_QUERY | S>C | +10 u32[4] auth query words | GameGuard CS-auth query (server -> client). The no-GG client path answers nothing. | decompiled-source/a2-2moons-2007/dekaron_00440000.c:3363<br>decompiled-source/a2-2moons-2007/dekaron_00440000.c:3703 | explained |
| `0x0002008b` | GG_AUTH_ANSWER | C>S | +10 u8[64] GameGuard answer blob | GameGuard CS-auth answer. | decompiled-source/a2-2moons-2007/dekaron_00410000.c:2670 | explained |

## 0x0007

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x00070004` | A2_0007_0004 *(label)* | S>C | +1c undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: show_auction | decompiled-source/a2-2moons-2007/dekaron_00730000.c:10789<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:11244 | partial_layout |

## 0x0030

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x00300000` | A2_0030_0000 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00490000.c:10700 | located_only |

## 0x0204

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x02040000` | PC_OBJECT | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes PC info record parsed via vtbl+0x1c; field map not recovered | Open one PC record; creates the PC object and parses it (115 bytes on wire). | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10142<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:1661 … | explained |
| `0x02040001` | PC_SUIT | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes suit blob | Per-PC equipment appearance ("suit") blob; bytes from +0x18 to end. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:2775<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:495 … | explained |
| `0x02040002` | PC_INFO_02 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9579 | partial_layout |
| `0x02040003` | PC_INFO_03 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9612 | partial_layout |
| `0x0204000f` | PC_INFO_0F | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9678 | partial_layout |
| `0x02040010` | PC_INFO_10 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9711 | partial_layout |
| `0x02040011` | PC_INFO_11 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9744 | partial_layout |
| `0x02040012` | PC_INFO_12 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9777 | partial_layout |
| `0x02040013` | PC_INFO_13 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9645<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:9027 … | partial_layout |
| `0x02040014` | PC_INFO_14 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9810 | partial_layout |
| `0x02040015` | PC_INFO_15 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9843 | partial_layout |
| `0x02040016` | PC_INFO_16 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:2775<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:548 … | partial_layout |
| `0x02040017` | PC_INFO_17 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9899 | partial_layout |
| `0x02040018` | PC_INFO_18 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9932 | partial_layout |
| `0x02040019` | PC_INFO_19 | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9965 | partial_layout |
| `0x0204001a` | PC_INFO_1A | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:2775<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:601 … | partial_layout |
| `0x0204001b` | PC_INFO_1B | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10031<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344 | partial_layout |
| `0x0204001c` | PC_INFO_1C | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10064<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344 | partial_layout |
| `0x0204001d` | PC_INFO_1D | S>C | +10 u32 unknown key; +14 u32 character id; +18 bytes sub-record payload (count/flags seen: 0x0002..0x0004) | Per-PC info sub-record (sent in a fixed sequence after PC_OBJECT on channel entry). Exact meaning of this sub-type not recovered. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10097<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344 | partial_layout |

## 0x0206

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x02060000` | PCLIST_REQ | C>S | +10 u32 serial key from LOGIN_ACK | Request the character list. | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:14151 | explained |
| `0x02060001` | PCLIST_BEGIN | S>C | +10 u32 serial key echo; +14 u32 account/char key (unknown exact meaning) | Character list begins. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:2775<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:3 | explained |
| `0x02060002` | PCLIST_NAME | S>C | +10 u32 unknown; +14 u32 character id; +18 char[] character name | Per-character name record. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:2775<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:654 … | explained |
| `0x02060003` | PCLIST_END | S>C | +10 u32 key echo; +14 u32 unknown | End of list; client builds up to 6 slots and the Create button. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:2316<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:2775 | explained |

## 0x0207

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x02070002` | MAIL_ITEMLESS_INBOX_LIST_READ_DIL_DELETE_0207_0002 *(label)* | S>C | unknown | Character object (misc): reply/notification. Character-related notice. Prior-build note (43.3.0, INFERRED for 0.0.1): S070: S>C 0x02070002 at packet+0x18. All multibyte scalar stream values BE; *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:3027<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:3754 | located_only |

## 0x0281

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0281000d` | A2_0281_000D *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00710000.c:7005<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x02810010` | A2_0281_0010 *(label)* | S>C | +10 ushort unknown; +2c undefined4 unknown; +30 undefined2 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00710000.c:7231<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | partial_layout |

## 0x0300

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x03000000` | LOGIN | C>S | +10 char[17] account id; +21 char[17] password (never logged) | Login request (default type). 52 bytes. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:11411 | explained |
| `0x03000001` | LOGIN_ACK | S>C | +10 u32 serial/session key (reused in PCLIST and LOCK); +14 i32 result (0 = OK); +18 u32 session-server id (reused in LOCK); +1c char[15] User NO string; +2b u8 flag (1 = clear an option bit; region dependent) | Login result. 0 = OK; otherwise error code (600 = login fail UI). | decompiled-source/a2-2moons-2007/dekaron_00500000.c:11030<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:11304 | explained |
| `0x03000002` | LOGOUT | C>S | empty body | Logout request (empty body). | decompiled-source/a2-2moons-2007/dekaron_00500000.c:8447 | explained |
| `0x03000003` | LOGOUT_ACK | S>C | +10 i32 result | Logout result. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:8503<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:8545 | explained |
| `0x03000004` | LOGIN_V4 | C>S | +10 char[17] account id; +21 char[65] password (never logged) | Login request, type 1 (long password). 100 bytes. Used by the test client. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:11331 | explained |
| `0x03000005` | LOGIN_V5 | C>S | +10 char[65] account id; +51 char[65] password | Login request, type 2. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:11347 | explained |
| `0x03000006` | LOGIN_V6 | C>S | +10 char[129] account id; +91 char[65] password | Login request, type 3. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:11363 | explained |
| `0x03000007` | LOGIN_V7 | C>S | +10 char[33] account id; +31 char[65] password | Login request, region 3 default. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:11395 | explained |
| `0x03000008` | LOGIN_V8 | C>S | +10 char[33] account id; +31 char[65] password | Login request, type 4. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:11379 | explained |

## 0x0301

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x03010000` | CHECKOUT | C>S | +10 char[25] character name | Pick character and leave the login server for the channel. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10703 | explained |
| `0x03010001` | CHECKOUT_ACK | S>C | +10 i32 result (0 = OK); +14 char[] string, "NODATA" seen; meaning unknown; +1c u32 unknown | Checkout result; on success the client connects to the channel server. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10530<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:10786 | explained |
| `0x03010002` | CHECKIN | C>S | +10 u32 serial key; +14 u32 session-server id; +18 char[25] character name; +31 char[] character no (string) | Session transfer to the game server. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:8669 | explained |
| `0x03010003` | CHECKIN_ACK | S>C | +10 i32 result | Check-in result. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:8615<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:8773 | explained |

## 0x0302

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x03020000` | CHAR_CREATE | C>S | +10 char[25] name; +29 u8 class; +2a u8 slot/index | Create character. | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:11885 | explained |
| `0x03020001` | CHAR_CREATE_ACK | S>C | +10 i32 result | Create result: >=0 OK; -1,-2,-3,-11,-12 errors. | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:11470<br>decompiled-source/a2-2moons-2007/dekaron_004f0000.c:11869 | explained |
| `0x03020002` | CHAR_DELETE | C>S | unknown | Delete character. | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:9088 | located_only |
| `0x03020003` | CHAR_DELETE_ACK | S>C | +10 i32 result | Delete result ("Destroy Character OK/Fail"). | decompiled-source/a2-2moons-2007/dekaron_00500000.c:2775<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:35 | explained |
| `0x03020004` | CHARACTER_CREATE_0302_0004 *(label)* | C>S | +42 undefined1 unknown; +43 undefined1 unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:10386 | partial_layout |
| `0x03020005` | CHARACTER_CREATE_0302_0005 *(label)* | S>C | unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9780<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9885 | located_only |
| `0x03020006` | CHARACTER_CREATE_0302_0006 *(label)* | C>S | unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:10271 | located_only |
| `0x03020007` | CHARACTER_CREATE_0302_0007 *(label)* | S>C | unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9844<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9885 | located_only |
| `0x03020008` | CHARACTER_CREATE_0302_0008 *(label)* | C>S | +42 undefined1 unknown; +43 undefined1 unknown | Character create/delete + ServerTransfer: request. Character create/delete at character select; server-transfer UI requests. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:10315 | partial_layout |
| `0x03020009` | CHARACTER_CREATE_0302_0009 *(label)* | S>C | unknown | Character create/delete + ServerTransfer: reply/notification. Character create/delete at character select; server-transfer UI requests. Likely reply to C>S 0x03020008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9812<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9885 | located_only |

## 0x0400

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x04000000` | LOCK | C>S | +10 u32 session-server id; +14 u32 serial key; +18 char[15] User NO; +27 char[25] client version string ("USA-18.0.1" seen) | Lock the account onto this game server. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10253 | explained |
| `0x04000002` | LOCK_ACK_START | S>C | +10 i32 result; +14 u8[3] flags | Lock accepted; character data follows. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10180<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344 | explained |
| `0x04000003` | LOCK_ACK_END | S>C | +10 u32 player object id (matches later 050d0000 actor id); +14 u8 flag | Character data finished. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:10215<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:10344 | explained |
| `0x04000006` | UNLOCK | C>S | empty body | Release the account lock (empty). | decompiled-source/a2-2moons-2007/dekaron_00500000.c:9023 | explained |
| `0x04000007` | UNLOCK_ACK | S>C | unknown | Unlock reply. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:9087<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9116 | located_only |
| `0x04000008` | WAIT_NOTICE | S>C | unknown | queue/wait notice during enter *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00500000.c:9325<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9405 | located_only |

## 0x0500

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05000000` | INVENTORY_0500_0000 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined2 unknown; +16 undefined1 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:6757<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:7255 | partial_layout |
| `0x05000002` | INVENTORY_0500_0002 *(label)* | C>S | unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:6537 | located_only |
| `0x05000008` | INVENTORY_0500_0008 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Inventory / CashItem / RandomBox: request. Inventory item moves/use, cash items, random boxes. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:8535 | partial_layout |
| `0x05000009` | INVENTORY_0500_0009 *(label)* | S>C | unknown | Inventory / CashItem / RandomBox: reply/notification. Inventory item moves/use, cash items, random boxes. Likely reply to C>S 0x05000008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:7374<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x0500000a` | A2_0500_000A *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:6521 | located_only |
| `0x0500000b` | A2_0500_000B *(label)* | S>C | +10 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pPC != NULL; pBag != NULL; RECEIVE ----  BAGPACKETS::SA_UseTo\n | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11097<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |

## 0x0501

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05010000` | ORNAMENT_0501_0000 *(label)* | C>S | +10 undefined4 unknown | Ornament / MainToolBar: request. Ornament and toolbar sync. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5234<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:5529 | partial_layout |
| `0x05010001` | ORNAMENT_0501_0001 *(label)* | S>C | unknown | Ornament / MainToolBar: reply/notification. Ornament and toolbar sync. Likely reply to C>S 0x05010000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:14778<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:15029 | located_only |
| `0x05010002` | A2_0501_0002 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00760000.c:378 | located_only |
| `0x05010003` | A2_0501_0003 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00750000.c:14908<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:15029 | located_only |

## 0x0502

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05020000` | CASHITEM_0502_0000 *(label)* | S>C | +10 undefined4 unknown; +1a ushort unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:9502<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | partial_layout |
| `0x05020001` | CASHITEM_0502_0001 *(label)* | C>S | unknown | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:6977 | located_only |
| `0x05020002` | CASHITEM_0502_0002 *(label)* | S>C | +10 char unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:10289<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |
| `0x05020003` | CASHITEM_0502_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined1 unknown | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:7168 | partial_layout |
| `0x05020004` | CASHITEM_0502_0004 *(label)* | S>C | +34 undefined4 unknown; +38 undefined4 unknown; +3c undefined4 unknown; +40 char unknown; +41 undefined1 unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:10001<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |
| `0x05020006` | CASHITEM_0502_0006 *(label)* | S>C | +10 int unknown; +14 undefined1 unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:10426<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |
| `0x05020007` | CASHITEM_0502_0007 *(label)* | C>S | empty body | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:12211<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:11690 | partial_layout |
| `0x05020008` | CASHITEM_0502_0008 *(label)* | S>C | unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x05020007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11706<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11796<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:11147 … | located_only |
| `0x05020009` | A2_0502_0009 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +13 short unknown; +15 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00710000.c:9796 | partial_layout |
| `0x0502000b` | CASHITEM_0502_000B *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:8507 | partial_layout |
| `0x0502000c` | CASHITEM_0502_000C *(label)* | S>C | unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x0502000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:6911<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x0502000e` | CASHITEM_0502_000E *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined4 unknown | CashItem / CashShop / game events: request. Cash item and shop notices, game-event queue. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:8669 | partial_layout |
| `0x0502000f` | CASHITEM_0502_000F *(label)* | S>C | unknown | CashItem / CashShop / game events: reply/notification. Cash item and shop notices, game-event queue. Likely reply to C>S 0x0502000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:7077<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x0502001a` | A2_0502_001A *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pPC != NULL; pBag != NULL; pItemArticle != NULL; SA_Segregation IN CASH - ERROR default | decompiled-source/a2-2moons-2007/dekaron_00710000.c:9449<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:9564 | located_only |

## 0x0503

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05030000` | WORLD_ENTER_0503_0000 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +18 undefined4 unknown | World enter / creature appear: request. Object enter (appear) records. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:7052 | partial_layout |
| `0x05030001` | WORLD_ENTER_0503_0001 *(label)* | S>C | +14 char unknown | World enter / creature appear: reply/notification. Object enter (appear) records. Likely reply to C>S 0x05030000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:10735<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |
| `0x05030002` | WORLD_ENTER_0503_0002 *(label)* | S>C | +1c undefined4 unknown | World enter / creature appear: reply/notification. Object enter (appear) records. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8957<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | partial_layout |
| `0x05030003` | WORLD_ENTER_0503_0003 *(label)* | C>S | +10 undefined4 unknown | World enter / creature appear: request. Object enter (appear) records. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:7212 | partial_layout |
| `0x05030004` | WORLD_ENTER_0503_0004 *(label)* | S>C | +14 char unknown | World enter / creature appear: reply/notification. Object enter (appear) records. Likely reply to C>S 0x05030003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:10504<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |

## 0x0504

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05040000` | MONSTER_APPEAR | S>C | +10 u32 object id; +14 u16 monster index (share/creature/monster.csv Index; 701 Blaverus, 3510 Akris seen); +16 u16 unknown (0 seen); +18 u32 current HP (equals server monster.csv MaxHP: 258 for 701, 1079 for 3510); +1c u32 stored to actor state +4 (0 seen); +20 bytes[28] position/movement block passed whole to the actor (bytes seen 36 26 00 00 00 ca 80 73 c8 2c 00 01 ...); +3c u32 copied to Monster state +0x44; +40 u8[8] effect/buff ids; each non-zero entry is applied; +48 u8 copied to Monster state +0x40 | A monster enters view. Handler FUN_005394f0 ("New Enter : Monster(%08X)"). Creates a Monster actor from the client monster table using the index at +0x14. | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:4145<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9162<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 … | explained |

## 0x0505

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05050000` | NPC_APPEAR | S>C | +10 u32 object id; +14 u16 NPC index (share/creature/npc.csv; 727 = Emily, 721 = Audrey, 732 = Pluto seen); +16 bytes[6] position/direction (handler copies +0x16 hi word and +0x1a); exact split unknown; +1c u8 passed with the object id to the NPC icon/state setter | An NPC enters view. Handler FUN_00538a70 ("New Enter : NPC(%08X)"). | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:4145<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:8651<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 … | explained |
| `0x05050001` | NPC_DIALOG_OPEN | C>S | +10 u32 NPC object id | Click/talk to an NPC. | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:1269 | explained |
| `0x05050002` | NPC_DIALOG_OPEN_ACK | S>C | +10 u32 NPC object id; +14 u8 unknown (1 seen); +16 u16 unknown (1 seen); +18 u32 unknown (tick-like) | Opens the NPC dialog (pCreature/pDialog checks in FUN_0076ce70). | decompiled-source/a2-2moons-2007/dekaron_00760000.c:10651<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:11034 | explained |
| `0x05050003` | NPC_DIALOG_SELECT | C>S | +10 u32 NPC object id; +14 u32 job/entry index (0 seen) | Choose a dialog entry/job of the NPC. | decompiled-source/a2-2moons-2007/dekaron_00790000.c:3193 | explained |
| `0x05050004` | NPC_DIALOG_0505_0004 *(label)* | S>C | +10 undefined4 unknown | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:10591<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:11034 | partial_layout |
| `0x05050005` | NPC_ICON_REQ | C>S | +10 u32 NPC object id | Ask for the NPC overhead icon/state, sent for every NPC that appears. | decompiled-source/a2-2moons-2007/dekaron_00520000.c:14988 | explained |
| `0x05050006` | NPC_ICON | S>C | +10 u32 NPC object id; +14 u8 icon id; +15 bytes[3] unknown | NPC icon/state ("Receive NPC Icon %u(%s)"). | decompiled-source/a2-2moons-2007/dekaron_00520000.c:15200<br>decompiled-source/a2-2moons-2007/dekaron_00520000.c:15248 | explained |
| `0x05050007` | NPCDIALOG_0505_0007 *(label)* | C>S | empty body | NPC dialog / Quest: request. NPC dialog open/select/close, quest NPC dialogs. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: TalkNPC 0x05050001 -> 0x05050002 with all npc.csv job slots; choice 0x05050003 -> shop open (job 0/102) or the module claiming that job type; close 0x05050007. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:3123<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:3219<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:3803 … | partial_layout |
| `0x05050008` | NPC_DIALOG_0505_0008 *(label)* | S>C | unknown | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. Likely reply to C>S 0x05050007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:11034 | located_only |
| `0x05050010` | NPC_DIALOG_0505_0010 *(label)* | S>C | +10 undefined4 unknown; +14 char unknown | NPC dialog / Quest: reply/notification. NPC dialog open/select/close, quest NPC dialogs. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7539<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | partial_layout |

## 0x0506

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05060000` | A2_0506_0000 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00760000.c:3122 | located_only |
| `0x05060002` | A2_0506_0002 *(label)* | C>S | +10 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00740000.c:7201<br>decompiled-source/a2-2moons-2007/dekaron_00740000.c:7229<br>decompiled-source/a2-2moons-2007/dekaron_00740000.c:7257 … | partial_layout |
| `0x05060003` | A2_0506_0003 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00740000.c:6642<br>decompiled-source/a2-2moons-2007/dekaron_00740000.c:7013 | located_only |
| `0x05060004` | A2_0506_0004 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:2886<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:2904 | partial_layout |
| `0x05060006` | AUTOHUNT_0506_0006 *(label)* | S>C | +10 int unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined4 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7453<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | partial_layout |
| `0x05060007` | AUTOHUNT_0506_0007 *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00510000.c:973<br>decompiled-source/a2-2moons-2007/dekaron_006a0000.c:7683 | partial_layout |
| `0x05060008` | AUTOHUNT_0506_0008 *(label)* | S>C | +10 char unknown; +24 undefined4 unknown; +28 undefined2 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00510000.c:1095<br>decompiled-source/a2-2moons-2007/dekaron_00510000.c:1167 | partial_layout |
| `0x05060009` | AUTOHUNT_0506_0009 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:5925<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:6015 | located_only |
| `0x0506000a` | AUTOHUNT_0506_000A *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:6190<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:6343 | located_only |
| `0x0506000b` | AUTOHUNT_0506_000B *(label)* | C>S | +10 byte unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:3034<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6207<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7780 | partial_layout |
| `0x0506000c` | AUTOHUNT_0506_000C *(label)* | S>C | +14 undefined4 unknown; +18 byte unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00740000.c:6593<br>decompiled-source/a2-2moons-2007/dekaron_00740000.c:7013 | partial_layout |
| `0x0506000d` | AUTOHUNT_0506_000D *(label)* | C>S | empty body | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00740000.c:6936 | partial_layout |
| `0x0506000e` | AUTOHUNT_0506_000E *(label)* | S>C | +14 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000d (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00740000.c:6814<br>decompiled-source/a2-2moons-2007/dekaron_00740000.c:7013 | partial_layout |
| `0x0506000f` | AUTOHUNT_0506_000F *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:8446 | partial_layout |
| `0x05060010` | AUTOHUNT_0506_0010 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x0506000f (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:6653<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x05060011` | PCINFO_0506_0011 *(label)* | C>S | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown; +16 undefined2 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05060011 (sender 0x16b8740, size 0x18; takes request lock 2 via [0x22c1070] vf+4, skipped when all four are 0): *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00740000.c:7313 | partial_layout |
| `0x05060012` | PCINFO_0506_0012 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060011 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S077: S>C 0x05060012 (PCInfo switch 0x16b913a -> 0x16b9530): releases lock 2 (vf+8), u8 result @0x10; 0 = refresh the two stat UIs *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00740000.c:7013 | located_only |
| `0x05060013` | CASHITEM_0506_0013 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: request. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:8474 | partial_layout |
| `0x05060014` | AUTOHUNT_0506_0014 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. Likely reply to C>S 0x05060013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:6753<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x05060016` | AUTOHUNT_0506_0016 *(label)* | S>C | unknown | AutoHunt / GrowBless / Dekaron provider / DKSquare entry: reply/notification. Auto-hunt settings, growth blessings, misc Dekaron provider. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00740000.c:7013 | located_only |

## 0x0507

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05070000` | PC_STATE_0507_0000 *(label)* | S>C | unknown | PC state: reply/notification. PC state event. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:4145<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:11104<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:11312 | located_only |

## 0x0508

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05080000` | CREATURE_0508_0000 *(label)* | S>C | unknown | Creature/PC state: reply/notification. Creature/PC state events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:4145<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:11312 | located_only |
| `0x05080001` | CREATURE_0508_0001 *(label)* | S>C | +10 int unknown; +40 undefined1 unknown; +41 byte unknown; +42 undefined1 unknown; +44 undefined2 unknown; +46 undefined2 unknown; +48 undefined2 unknown; +4a undefined1 unknown; +4b undefined1 unknown; +4c undefined1 unknown | Creature/PC state: reply/notification. Creature/PC state events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7714<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | partial_layout |

## 0x0509

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05090000` | PK_0509_0000 *(label)* | S>C | unknown | PK / Chaotic: reply/notification. PK mode and chaotic timer. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00420000.c:4012<br>decompiled-source/a2-2moons-2007/dekaron_004f0000.c:4145<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:11312 | located_only |
| `0x05090001` | A2_0509_0001 *(label)* | S>C | +10 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7443<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | partial_layout |
| `0x05090003` | A2_0509_0003 *(label)* | S>C | +10 int unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +22 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: ChangePointPacket : %d %d %d | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7569<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | partial_layout |
| `0x05090004` | A2_0509_0004 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:10365<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | located_only |
| `0x05090006` | A2_0509_0006 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:3007 | located_only |
| `0x0509000a` | PK_0509_000A *(label)* | C>S | empty body | PK / Chaotic: request. PK mode and chaotic timer. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:3034 | partial_layout |
| `0x0509000b` | PK_0509_000B *(label)* | C>S | empty body | PK / Chaotic: request. PK mode and chaotic timer. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:3052 | partial_layout |
| `0x0509000d` | A2_0509_000D *(label)* | S>C | +10 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:9554 | partial_layout |
| `0x0509000e` | A2_0509_000E *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00740000.c:6892<br>decompiled-source/a2-2moons-2007/dekaron_00740000.c:7013 | located_only |

## 0x050a

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050a0000` | NPC_SHOP_OPEN | S>C | +10 u32 NPC object id; +14 u32 unknown (0x11 seen) | Shop/job window open reply after NPC_DIALOG_SELECT. INFERRED. |  | explained |
| `0x050a0001` | NPC_SHOP_REQ | C>S | +10 u32 NPC object id; +14 u32 unknown (0x11 seen); +18 bytes[4] unknown (08 00 01 00 seen) | Shop/job request. INFERRED. | decompiled-source/a2-2moons-2007/dekaron_00750000.c:6334 | explained |
| `0x050a0002` | NPC_SHOP_DATA | S>C | +10 bytes[44] unknown | Shop/job data (60 bytes). Content not decoded. |  | partial_layout |
| `0x050a0003` | SHOP_050A_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown | NPC Shop: request. NPC shop buy/sell/repair. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: sell 0x050a0003 (sells the client's cursor item, tracked by S055) -> 0x050a0004. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:6405 | partial_layout |
| `0x050a0005` | NPC_SHOP_CLOSE | C>S | empty body | Close the shop/job window (empty). | decompiled-source/a2-2moons-2007/dekaron_00750000.c:6437 | explained |
| `0x050a0006` | NPC_SHOP_CLOSE_ACK | S>C | unknown | Close reply (empty). |  | explained |
| `0x050a0007` | NPC_SHOP_050A_0007 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown; +18 undefined1 unknown; +19 char unknown | NPC Shop: request. NPC shop buy/sell/repair. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:6369 | partial_layout |

## 0x050b

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050b0001` | STORAGE_WAREHOUSE_050B_0001 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:7698 | partial_layout |
| `0x050b0003` | STORAGE_WAREHOUSE_050B_0003 *(label)* | C>S | +10 undefined4 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:7978 | partial_layout |
| `0x050b0005` | STORAGE_WAREHOUSE_050B_0005 *(label)* | C>S | +10 undefined4 unknown | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:7734 | partial_layout |
| `0x050b0007` | STORAGE_WAREHOUSE_050B_0007 *(label)* | C>S | empty body | Storage (warehouse): request. Warehouse open/deposit/withdraw/dil. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:7767 | partial_layout |

## 0x050c

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050c0000` | PVP_050C_0000 *(label)* | C>S | unknown | PVP / DKSquare options: request. PVP/arena option toggles. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:6875 | located_only |
| `0x050c0001` | PVP_050C_0001 *(label)* | S>C | +10 char unknown | PVP / DKSquare options: reply/notification. PVP/arena option toggles. Likely reply to C>S 0x050c0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11315<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |
| `0x050c0002` | A2_050C_0002 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:6553 | located_only |
| `0x050c0003` | A2_050C_0003 *(label)* | S>C | +11 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pPC != NULL; pSuit != NULL; RECEIVE ---- SUITPACKETS::SA_SwapWeapon\n | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11435<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |
| `0x050c0004` | A2_050C_0004 *(label)* | S>C | +10 int unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pPC_L != NULL | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11505<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |

## 0x050d

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050d0000` | ACTOR_ACTION | both | +10 u32 actor object id (player or controlled monster); +14 u32 client time (ms, increasing); +18 bytes[4] position-related (changes every step); unknown packing; +1c bytes[3] unknown; +1f u8 action kind (handler switch; 0x02 = move seen most; 0x11 reads +0x20); +20 u8 action argument; +21 bytes[15] action data; for some kinds a string from +0x30 when len >= 0x31 | Movement/action of an actor. Client sends it for its own character and for monsters it controls; the server echoes it back. Handler FUN_0053a340 switches on +0x1f. | decompiled-source/a2-2moons-2007/dekaron_004e0000.c:13552<br>decompiled-source/a2-2moons-2007/dekaron_004e0000.c:14389<br>decompiled-source/a2-2moons-2007/dekaron_004f0000.c:1028 … | explained |
| `0x050d0001` | SECTOR_REPORT | C>S | +10 u16 sector/cell index; +12 bytes[2] uninitialised buffer bytes (not a field) | Client reports its current sector/cell index when it changes (builder FUN_00524500). | decompiled-source/a2-2moons-2007/dekaron_00520000.c:5183 | explained |
| `0x050d0002` | ACTOR_SECTOR_CHANGE | C>S | +10 u32 actor object id; +14 u16 new sector; +16 u16 unknown | A controlled actor moved between sectors ("%u sector -> %u sector"). | decompiled-source/a2-2moons-2007/dekaron_00530000.c:14399<br>decompiled-source/a2-2moons-2007/dekaron_00540000.c:7936 | explained |
| `0x050d0003` | A2_050D_0003 *(label)* | both | +10 undefined4 unknown; +14 ushort unknown | Purpose unknown. Handler/builder located (see refs); debug strings: [SLANG] | decompiled-source/a2-2moons-2007/dekaron_00760000.c:1907<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:2026<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:3398 | partial_layout |
| `0x050d0004` | MONSTER_CONTROL | S>C | +10 u32 controller (player) object id; +14 u32 monster object id; +18 u16 unknown (0x01d9..0x021a seen); +1a u8 stored to control state [3] (100 seen); +1b u8 stored to control state [4] (100 seen) | Server hands control (AI/movement) of a monster to this client ("%X Controlled by %X"; unknown id -> "Unhandled Monster Control Packet"). | decompiled-source/a2-2moons-2007/dekaron_00530000.c:10060<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9971 | explained |
| `0x050d0005` | OBJECTS_DISAPPEAR | S>C | +10 u32[] object ids | Remove objects from view. List of object ids (length 20 = 1 id, 24 = 2 ids). INFERRED from ids matching earlier APPEAR packets. | decompiled-source/a2-2moons-2007/dekaron_00780000.c:511 | explained |
| `0x050d0006` | A2_050D_0006 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00760000.c:3010 | located_only |
| `0x050d0007` | ENTER_WORLD | S>C | +10 u8 map index (7 = 07_loa_castle in the session captured); +11 bytes unknown (07 00 00 a8 00 b7 00 00 seen) | Server tells the client which map to load. Handler FUN_0050a520 immediately sends ENTER_DONE 0x09020000. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:9282<br>decompiled-source/a2-2moons-2007/dekaron_00500000.c:9405 | explained |

## 0x050e

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050e0000` | TRADE_050E_0000 *(label)* | both | +10 undefined4 unknown; +14 undefined4 unknown | Trade: request and reply share this opcode. Player-to-player trade. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_004f0000.c:2425<br>decompiled-source/a2-2moons-2007/dekaron_004f0000.c:2633<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:14140 … | partial_layout |
| `0x050e0002` | TRADE_050E_0002 *(label)* | C>S | +10 undefined4 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:13789<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:14140 | partial_layout |
| `0x050e0005` | TRADE_050E_0005 *(label)* | C>S | empty body | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:13967<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:776 | partial_layout |
| `0x050e0006` | TRADE_050E_0006 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:830 | partial_layout |
| `0x050e0008` | TRADE_050E_0008 *(label)* | C>S | +10 undefined4 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:800 | partial_layout |
| `0x050e000c` | TRADE_050E_000C *(label)* | C>S | +10 undefined1 unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:750 | partial_layout |
| `0x050e000f` | A2_050E_000F *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:1168 | located_only |
| `0x050e0010` | A2_050E_0010 *(label)* | S>C | +10 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings: RECEIVE ---- ITEMPACKETS::SA_Pick \n | decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:9672 | partial_layout |
| `0x050e0011` | TRADE_050E_0011 *(label)* | C>S | unknown | Trade: request. Player-to-player trade. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:1152 | located_only |
| `0x050e0012` | TRADE_050E_0012 *(label)* | S>C | +10 char unknown | Trade: reply/notification. Player-to-player trade. Likely reply to C>S 0x050e0011 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:9589 | partial_layout |

## 0x050f

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x050f0000` | TUTORIAL_050F_0000 *(label)* | C>S | +10 undefined2 unknown | Tutorial / Quest: request. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:563 | partial_layout |
| `0x050f0006` | TUTORIAL_050F_0006 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:10490<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:9821 | partial_layout |
| `0x050f0007` | TUTORIAL_050F_0007 *(label)* | S>C | +14 ushort unknown; +16 undefined2 unknown | Tutorial / Quest: reply/notification. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:10017<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:10490 | partial_layout |
| `0x050f0008` | TUTORIAL_050F_0008 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown | Tutorial / Quest: request. Tutorial renew and quest progress. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:4077 | partial_layout |

## 0x0510

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05100001` | A2_0510_0001 *(label)* | C>S | +10 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:5350 | partial_layout |
| `0x05100003` | A2_0510_0003 *(label)* | both | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00750000.c:13999<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:14219<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:4270 … | located_only |
| `0x05100005` | A2_0510_0005 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00750000.c:13999<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:1773 | located_only |
| `0x05100006` | A2_0510_0006 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:1722 | partial_layout |
| `0x05100009` | A2_0510_0009 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:4949<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:5035 | partial_layout |
| `0x0510000c` | A2_0510_000C *(label)* | C>S | +10 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:5079 | partial_layout |

## 0x0511

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05110000` | A2_0511_0000 *(label)* | both | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00770000.c:2381<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:3344<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:5190 | located_only |
| `0x05110002` | A2_0511_0002 *(label)* | C>S | +10 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:5125<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:5158 | partial_layout |
| `0x05110003` | A2_0511_0003 *(label)* | C>S | +10 int unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:5054 | partial_layout |
| `0x05110004` | A2_0511_0004 *(label)* | C>S | +10 int unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00790000.c:5100 | partial_layout |
| `0x05110006` | A2_0511_0006 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:10126 | partial_layout |
| `0x0511000c` | A2_0511_000C *(label)* | both | +10 undefined4 unknown; +14 ushort unknown | Purpose unknown. Handler/builder located (see refs); debug strings: [SLANG] | decompiled-source/a2-2moons-2007/dekaron_00760000.c:1809<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:2026<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:3398 | partial_layout |
| `0x0511000e` | A2_0511_000E *(label)* | S>C | +34 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings: RECEIVE ---- PARTYPACKETS::SN_ShareItem \n | decompiled-source/a2-2moons-2007/dekaron_00750000.c:10617<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |

## 0x0512

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05120002` | ATTACK_ASSAULT_0512_0002 *(label)* | C>S | +10 undefined4 unknown | Attack (assault/fly): request. Special attack moves. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00540000.c:6596 | partial_layout |
| `0x05120003` | ATTACK_ASSAULT_0512_0003 *(label)* | C>S | +10 undefined4 unknown | Attack (assault/fly): request. Special attack moves. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:10433<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:12427<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:12857 … | partial_layout |

## 0x0515

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05150001` | SKILL_0515_0001 *(label)* | S>C | +10 ushort unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:3286<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:3827 | partial_layout |
| `0x05150002` | SKILL_0515_0002 *(label)* | C>S | +10 undefined2 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:2798 | partial_layout |
| `0x05150003` | SKILL_0515_0003 *(label)* | S>C | +10 char unknown; +12 undefined2 unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:3400<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:3827 | partial_layout |
| `0x05150004` | MAINTOOLBAR_0515_0004 *(label)* | C>S | +10 undefined1 unknown; +11 char unknown; +12 undefined1 unknown; +13 char unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05150004 size 0x18: u32 id @0x10 (obj vf+0x18 -> vf+0x10 -> [0]), u8 a2 @0x14, u8 a3 @0x15   (register) *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:15575 | partial_layout |
| `0x05150005` | MAINTOOLBAR_0515_0005 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150004 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S063: S>C 0x05150005 / 0x05150007 (Skill switch 0x167d1e8 -> 0x167d6d0 / 0x167d800): releases lock 1, u8 result @0x10; *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:2913<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:3827 | located_only |
| `0x05150006` | MAINTOOLBAR_0515_0006 *(label)* | C>S | +10 undefined1 unknown; +11 char unknown; +12 undefined1 unknown; +13 char unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05150006 size 0x14: u8 a2 @0x10, u8 a3 @0x11                                                (clear, obj == null) *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:15575 | partial_layout |
| `0x05150007` | MAINTOOLBAR_0515_0007 *(label)* | S>C | unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:2991<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:3827 | located_only |
| `0x05150008` | SKILL_0515_0008 *(label)* | C>S | +12 undefined4 unknown; +16 undefined4 unknown; +1a undefined4 unknown; +1e undefined2 unknown; +20 undefined1 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:2768 | partial_layout |
| `0x05150009` | SKILL_0515_0009 *(label)* | S>C | +10 ushort unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x05150008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:2749<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:3827 | partial_layout |
| `0x0515000a` | SKILL_0515_000A *(label)* | C>S | +12 char unknown; +13 char unknown; +14 undefined4 unknown; +18 undefined2 unknown | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:3764 | partial_layout |
| `0x0515000d` | SKILL_0515_000D *(label)* | S>C | +10 undefined1 unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:3549<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:3827 | partial_layout |
| `0x0515000e` | SKILL_0515_000E *(label)* | S>C | +14 undefined4 unknown; +18 byte unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:2835<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:3827 | partial_layout |
| `0x0515000f` | SKILL_0515_000F *(label)* | C>S | empty body | Skill: request. Skill learn/use/reinforce, toolbar skills. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:2817 | partial_layout |
| `0x05150010` | SKILL_0515_0010 *(label)* | S>C | +10 undefined4 unknown; +14 char unknown | Skill: reply/notification. Skill learn/use/reinforce, toolbar skills. Likely reply to C>S 0x0515000f (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:3070<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:3827 | partial_layout |

## 0x0516

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05160000` | CREATURE_EVENT_0516_0000 *(label)* | C>S | +10 undefined2 unknown | Creature event: request. Creature event. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:11459 | partial_layout |
| `0x05160001` | CREATURE_EVENT_0516_0001 *(label)* | S>C | unknown | Creature event: reply/notification. Creature event. Likely reply to C>S 0x05160000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7504<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | located_only |

## 0x0517

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05170000` | NPC_TELEPORT_0517_0000 *(label)* | S>C | +14 char unknown | NPC teleport: reply/notification. NPC teleport. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:9511<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:9720 | partial_layout |
| `0x05170001` | NPC_TELEPORT_0517_0001 *(label)* | C>S | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown | NPC teleport: request. NPC teleport. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:3975 | partial_layout |
| `0x05170002` | NPC_TELEPORT_0517_0002 *(label)* | S>C | unknown | NPC teleport: reply/notification. NPC teleport. Likely reply to C>S 0x05170001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:9355<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:9720 | located_only |

## 0x0518

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05180004` | A2_0518_0004 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00740000.c:5780 | partial_layout |
| `0x05180005` | A2_0518_0005 *(label)* | C>S | +10 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00740000.c:5799 | partial_layout |

## 0x0519

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05190000` | SERVANT_0519_0000 *(label)* | both | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1c undefined4 unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined2 unknown; +2e undefined1 unknown; +2f undefined1 unknown; +42 undefined4 unknown; +46 undefined4 unknown | Servant / effects: request and reply share this opcode. Servant and effect notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00420000.c:4012<br>decompiled-source/a2-2moons-2007/dekaron_004f0000.c:4145<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9369 … | partial_layout |
| `0x05190001` | SERVANT_0519_0001 *(label)* | C>S | +10 undefined2 unknown; +16 undefined4 unknown; +1a undefined2 unknown | Servant / effects: request. Servant and effect notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:13362 | partial_layout |
| `0x05190002` | SERVANT_0519_0002 *(label)* | C>S | empty body | Servant / effects: request. Servant and effect notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:12760 | partial_layout |
| `0x05190003` | SERVANT_0519_0003 *(label)* | S>C | +14 undefined4 unknown; +18 char unknown | Servant / effects: reply/notification. Servant and effect notices. Likely reply to C>S 0x05190002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8212<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:8392 | partial_layout |

## 0x051a

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051a0000` | STORE_PERSONAL_SHOP_051A_0000 *(label)* | C>S | +10 undefined4 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:10880 | partial_layout |
| `0x051a0001` | STORE_PERSONAL_SHOP_051A_0001 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:10914<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:11036 | located_only |
| `0x051a0002` | STORE_PERSONAL_SHOP_051A_0002 *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:8499 | partial_layout |
| `0x051a0003` | STORE_PERSONAL_SHOP_051A_0003 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:8466<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:9085 | located_only |
| `0x051a0004` | STORE_PERSONAL_SHOP_051A_0004 *(label)* | C>S | unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:10717 | located_only |
| `0x051a0005` | STORE_PERSONAL_SHOP_051A_0005 *(label)* | S>C | unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:10668<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:9975 | located_only |
| `0x051a0006` | STORE_PERSONAL_SHOP_051A_0006 *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:9213 | partial_layout |
| `0x051a0007` | STORE_PERSONAL_SHOP_051A_0007 *(label)* | S>C | +10 int unknown; +14 char unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0006 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:8962<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:9085<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:9494 … | partial_layout |
| `0x051a0008` | STORE_PERSONAL_SHOP_051A_0008 *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown; +14 undefined4 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:10105 | partial_layout |
| `0x051a0009` | STORE_PERSONAL_SHOP_051A_0009 *(label)* | S>C | +10 char unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a0008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:10189<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:10668 | partial_layout |
| `0x051a000a` | STORE_PERSONAL_SHOP_051A_000A *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:9881 | partial_layout |
| `0x051a000b` | STORE_PERSONAL_SHOP_051A_000B *(label)* | S>C | +10 char unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000a (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:10391<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:10668 | partial_layout |
| `0x051a000c` | STORE_PERSONAL_SHOP_051A_000C *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined1 unknown; +17 bool unknown | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:8612 | partial_layout |
| `0x051a000d` | STORE_PERSONAL_SHOP_051A_000D *(label)* | S>C | +17 char unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:8765<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:9085<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:9562 … | partial_layout |
| `0x051a000e` | STORE_PERSONAL_SHOP_051A_000E *(label)* | C>S | empty body | Store (personal shop) / Auction: request. Personal store and auction house. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:10770 | partial_layout |
| `0x051a000f` | STORE_PERSONAL_SHOP_051A_000F *(label)* | S>C | +14 char unknown | Store (personal shop) / Auction: reply/notification. Personal store and auction house. Likely reply to C>S 0x051a000e (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:10987<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:11244 | partial_layout |

## 0x051b

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051b0000` | A2_051B_0000 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:9747 | partial_layout |
| `0x051b0002` | A2_051B_0002 *(label)* | C>S | +10 undefined1 unknown; +11 bool unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:9771 | partial_layout |
| `0x051b0004` | A2_051B_0004 *(label)* | C>S | +10 short unknown; +12 char unknown; +13 bool unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:9808 | partial_layout |
| `0x051b0006` | A2_051B_0006 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:9846 | partial_layout |
| `0x051b0008` | A2_051B_0008 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:9870 | partial_layout |
| `0x051b000a` | A2_051B_000A *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:9894 | partial_layout |
| `0x051b000e` | A2_051B_000E *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:9918 | partial_layout |

## 0x051c

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051c0000` | UPGRADE_051C_0000 *(label)* | S>C | unknown | Upgrade: reply/notification. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0000 open window, no body (case 0x16ef7e6 -> handler 0x16ef830) *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:12485 | located_only |
| `0x051c0001` | UPGRADE_051C_0001 *(label)* | C>S | unknown | Upgrade: request. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051c0001 upgrade request, size 0x28 (builder 0x16ef020). Body offsets (packet offset - 0x10): *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13053 | located_only |
| `0x051c0002` | UPGRADE_051C_0002 *(label)* | S>C | unknown | Upgrade: reply/notification. Item upgrade (enchant). Likely reply to C>S 0x051c0001 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0002 result (handler 0x16ef880), size 0x1e (= last field read; exact size UNVERIFIED): *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:12263<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:12485 | located_only |
| `0x051c0003` | UPGRADE_051C_0003 *(label)* | C>S | empty body | Upgrade: request. Item upgrade (enchant). Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051c0003 close (size 0x10, builder 0x16eefd0) *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:12774 | partial_layout |
| `0x051c0004` | UPGRADE_051C_0004 *(label)* | S>C | unknown | Upgrade: reply/notification. Item upgrade (enchant). Likely reply to C>S 0x051c0003 (request even / reply odd convention). Prior-build note (43.3.0, INFERRED for 0.0.1): S117: S>C 0x051c0004 close window, no body (case 0x16ef7f1).  Other S>C cases UNDECODED, not sent. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:12485 | located_only |

## 0x051d

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051d0000` | TARGET_051D_0000 *(label)* | S>C | unknown | Target: reply/notification. Target selection. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8999<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | located_only |
| `0x051d0001` | TARGET_051D_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown | Target: request. Target selection. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8651 | partial_layout |
| `0x051d0003` | TARGET_051D_0003 *(label)* | S>C | +14 undefined4 unknown; +18 char unknown | Target: reply/notification. Target selection. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8302<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:8392 | partial_layout |
| `0x051d0004` | TARGET_051D_0004 *(label)* | C>S | empty body | Target: request. Target selection. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00520000.c:11043 | partial_layout |

## 0x051e

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051e0000` | A2_051E_0000 *(label)* | S>C | unknown | Seen only on the wire; purpose unknown. | decompiled-source/a2-2moons-2007/dekaron_00720000.c:1632 | located_only |
| `0x051e0001` | ITEMADDSOCKET_051E_0001 *(label)* | C>S | unknown | ItemAddSocket: request. Add socket to item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051e0001 request, size 0x30 (ctor 0x16f53d0, filled at 0x16f4d1d / 0x16f50c3 from a 0x17-byte struct: zero 0x16f42a0, *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:2146 | located_only |
| `0x051e0002` | A2_051E_0002 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00720000.c:1275<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:1632 | located_only |
| `0x051e0003` | ITEMADDSOCKET_051E_0003 *(label)* | C>S | empty body | ItemAddSocket: request. Add socket to item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x051e0003 close, size 0x10 (0x16f4b50) *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:1949 | partial_layout |
| `0x051e0004` | A2_051E_0004 *(label)* | S>C | unknown | Seen only on the wire; purpose unknown. | decompiled-source/a2-2moons-2007/dekaron_00720000.c:1632 | located_only |

## 0x051f

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x051f0000` | NPC_MAIL_051F_0000 *(label)* | both | unknown | NPC mail: request and reply share this opcode. NPC mail dialog. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:6440<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:6506<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:3289 | located_only |
| `0x051f0001` | NPC_MAIL_051F_0001 *(label)* | C>S | empty body | NPC mail: request. NPC mail dialog. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:3312 | partial_layout |
| `0x051f0002` | NPC_MAIL_051F_0002 *(label)* | S>C | unknown | NPC mail: reply/notification. NPC mail dialog. Likely reply to C>S 0x051f0001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:6411<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:6506 | located_only |

## 0x0520

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05200000` | VIPSHOP_0520_0000 *(label)* | C>S | empty body | CashShop / VipShop: request. Cash/VIP shop. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:12163<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:11642 | partial_layout |
| `0x05200001` | CASHSHOP_0520_0001 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash/VIP shop. Likely reply to C>S 0x05200000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:10803<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11796<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:10242 … | located_only |
| `0x05200002` | VIPSHOP_0520_0002 *(label)* | C>S | empty body | CashShop / VipShop: request. Cash/VIP shop. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:12187<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:11666 | partial_layout |
| `0x05200003` | CASHSHOP_0520_0003 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash/VIP shop. Likely reply to C>S 0x05200002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:10757<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11796<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:10196 … | located_only |

## 0x0521

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05210000` | FISHING_0521_0000 *(label)* | C>S | unknown | Fishing: request. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:3350 | located_only |
| `0x05210001` | FISHING_0521_0001 *(label)* | S>C | +10 undefined4 unknown; +14 undefined2 unknown; +16 char unknown | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:3262<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:3325 | partial_layout |
| `0x05210003` | FISHING_0521_0003 *(label)* | C>S | empty body | Fishing: request. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:5862 | partial_layout |
| `0x05210004` | FISHING_0521_0004 *(label)* | S>C | unknown | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:5896<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:5942 | located_only |
| `0x05210005` | A2_0521_0005 *(label)* | S>C | +10 undefined2 unknown; +14 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8757<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9199 | partial_layout |
| `0x05210006` | FISHING_0521_0006 *(label)* | S>C | unknown | Fishing: reply/notification. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:12789<br>decompiled-source/a2-2moons-2007/dekaron_006e0000.c:13234 | located_only |
| `0x05210007` | FISHING_0521_0007 *(label)* | C>S | unknown | Fishing: request. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:13306 | located_only |
| `0x05210008` | FISHING_0521_0008 *(label)* | S>C | +10 char unknown | Fishing: reply/notification. Fishing cast/wait/reel. Likely reply to C>S 0x05210007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:13015<br>decompiled-source/a2-2moons-2007/dekaron_006e0000.c:13234 | partial_layout |
| `0x05210009` | FISHING_0521_0009 *(label)* | S>C | +34 char unknown | Fishing: reply/notification. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11554<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | partial_layout |
| `0x0521000a` | FISHING_0521_000A *(label)* | C>S | empty body | Fishing: request. Fishing cast/wait/reel. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9100 | partial_layout |
| `0x0521000b` | A2_0521_000B *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9100<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:9199 | located_only |

## 0x0522

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05220000` | PVP_DUEL_0522_0000 *(label)* | C>S | +10 undefined4 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:11553 | partial_layout |
| `0x05220002` | PVP_DUEL_0522_0002 *(label)* | C>S | unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:11505 | located_only |
| `0x05220005` | PVP_DUEL_0522_0005 *(label)* | C>S | +2c undefined4 unknown; +30 undefined1 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:11158<br>decompiled-source/a2-2moons-2007/dekaron_006e0000.c:11213 | partial_layout |
| `0x05220008` | PVP_DUEL_0522_0008 *(label)* | C>S | +10 undefined4 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:12287 | partial_layout |
| `0x0522000a` | PVP_DUEL_0522_000A *(label)* | C>S | empty body | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006e0000.c:12028 | partial_layout |
| `0x0522000f` | PVP_DUEL_0522_000F *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown | PVP duel: request. 1v1 PVP duel request/accept/result. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:3819 | partial_layout |

## 0x0523

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05230000` | PORTAL_0523_0000 *(label)* | S>C | unknown | Portal / CashItem: reply/notification. Portal and cash item notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:6108 | located_only |
| `0x05230001` | PORTAL_0523_0001 *(label)* | C>S | unknown | Portal / CashItem: request. Portal and cash item notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:9096 | located_only |
| `0x05230002` | CASHITEM_0523_0002 *(label)* | S>C | unknown | Portal / CashItem: reply/notification. Portal and cash item notices. Likely reply to C>S 0x05230001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:7499<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x05230003` | PORTAL_0523_0003 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1c undefined4 unknown; +20 undefined2 unknown; +22 undefined2 unknown | Portal / CashItem: reply/notification. Portal and cash item notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8725<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | partial_layout |
| `0x05230004` | PORTAL_0523_0004 *(label)* | S>C | +10 char unknown | Portal / CashItem: reply/notification. Portal and cash item notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:6557<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | partial_layout |
| `0x05230005` | CASHITEM_0523_0005 *(label)* | C>S | unknown | Portal / CashItem: request. Portal and cash item notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:9112 | located_only |
| `0x05230006` | PORTAL_0523_0006 *(label)* | S>C | unknown | Portal / CashItem: reply/notification. Portal and cash item notices. Likely reply to C>S 0x05230005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:7677<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x05230007` | PORTAL_0523_0007 *(label)* | S>C | +10 undefined4 unknown | Portal / CashItem: reply/notification. Portal and cash item notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:7844<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | partial_layout |

## 0x0524

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05240000` | ENTER_EVENT_0524_0000 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown; +20 undefined2 unknown | Enter event: reply/notification. Object enter event. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8569<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | partial_layout |

## 0x0525

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05250000` | QUEST_0525_0000 *(label)* | S>C | unknown | Quest: reply/notification. Quest UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:150 | located_only |
| `0x05250001` | QUEST_0525_0001 *(label)* | C>S | +10 undefined4 unknown; +14 short unknown | Quest: request. Quest UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:605 | partial_layout |
| `0x05250002` | QUEST_0525_0002 *(label)* | S>C | +10 undefined1 unknown | Quest: reply/notification. Quest UI. Likely reply to C>S 0x05250001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:150<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:80 | partial_layout |
| `0x05250003` | QUEST_0525_0003 *(label)* | C>S | empty body | Quest: request. Quest UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:586 | partial_layout |
| `0x05250004` | QUEST_0525_0004 *(label)* | S>C | unknown | Quest: reply/notification. Quest UI. Likely reply to C>S 0x05250003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:150 | located_only |

## 0x0526

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05260000` | ENTER_WORLD_BLOCK_0526 | S>C | +10 bytes[264] unknown (starts 07 00 ...) | Large block sent right after ENTER_WORLD (280 bytes). Content not decoded. |  | partial_layout |
| `0x05260002` | DUNGEON_0526_0002 *(label)* | S>C | +14 undefined2 unknown | Dungeon / InformDialog / Captcha: reply/notification. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:5743<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:6027 | partial_layout |
| `0x05260003` | DUNGEON_0526_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 undefined2 unknown | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:3096 | partial_layout |
| `0x0526000d` | DUNGEON_0526_000D *(label)* | C>S | +10 undefined2 unknown; +14 undefined4 unknown | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00660000.c:9942 | partial_layout |
| `0x05260010` | DUNGEON_0526_0010 *(label)* | C>S | empty body | Dungeon / InformDialog / Captcha: request. Dungeon entry dialogs, dungeon reference/map events, captcha. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00660000.c:9942 | partial_layout |

## 0x0527

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05270000` | CREATURE_0527_0000 *(label)* | S>C | +10 undefined4 unknown; +14 int unknown; +18 undefined2 unknown; +34 undefined2 unknown; +36 undefined2 unknown; +5c short unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:9551<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | partial_layout |
| `0x05270001` | CREATURE_0527_0001 *(label)* | S>C | +10 undefined4 unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7612<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | partial_layout |
| `0x05270002` | CREATURE_0527_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined1 unknown; +18 int unknown; +1c undefined4 unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8476<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | partial_layout |
| `0x05270003` | CREATURE_0527_0003 *(label)* | S>C | +10 undefined4 unknown; +14 undefined1 unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7832<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | partial_layout |
| `0x05270004` | CREATURE_0527_0004 *(label)* | S>C | unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:10163<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | located_only |
| `0x05270005` | CREATURE_0527_0005 *(label)* | S>C | +10 undefined4 unknown | Creature/enter events: reply/notification. Creature/enter events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12498<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | partial_layout |

## 0x0528

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05280000` | SIEGE_0528_0000 *(label)* | S>C | +10 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:9074<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:9254 | partial_layout |
| `0x05280001` | SIEGE_0528_0001 *(label)* | C>S | +10 undefined2 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:3873 | partial_layout |
| `0x05280002` | SIEGE_0528_0002 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:8827<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:9254 | located_only |
| `0x05280003` | SIEGE_0528_0003 *(label)* | C>S | +10 undefined2 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:832 | partial_layout |
| `0x05280004` | SIEGE_0528_0004 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:13411<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x05280007` | SIEGE_0528_0007 *(label)* | S>C | +10 char unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:7623<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:8423 | partial_layout |
| `0x05280008` | SIEGE_0528_0008 *(label)* | C>S | empty body | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:3655 | partial_layout |
| `0x05280009` | SIEGE_0528_0009 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280008 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:8423 | located_only |
| `0x0528000a` | SIEGE_0528_000A *(label)* | C>S | empty body | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:908 | partial_layout |
| `0x0528000b` | SIEGE_0528_000B *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528000a (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:7790<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:8423 | located_only |
| `0x0528000c` | SIEGE_0528_000C *(label)* | S>C | +10 undefined4 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:4508<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:4660 | partial_layout |
| `0x0528000d` | SIEGE_0528_000D *(label)* | C>S | +10 undefined4 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:4787 | partial_layout |
| `0x0528000e` | SIEGE_0528_000E *(label)* | S>C | +38 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x0528000d (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:4547<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:4660 | partial_layout |
| `0x0528000f` | SIEGE_0528_000F *(label)* | S>C | +10 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:14508<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | partial_layout |
| `0x05280010` | SIEGE_0528_0010 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:14564<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x05280011` | SIEGE_0528_0011 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:14702<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x05280012` | SIEGE_0528_0012 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:4660 | located_only |
| `0x05280013` | SIEGE_0528_0013 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12461<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x05280014` | SIEGE_0528_0014 *(label)* | S>C | +14 undefined4 unknown; +18 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12955<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | partial_layout |
| `0x05280015` | SIEGE_0528_0015 *(label)* | C>S | empty body | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:1076 | partial_layout |
| `0x05280016` | SIEGE_0528_0016 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280015 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12487<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x05280017` | SIEGE_0528_0017 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown | Siege: request. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:1095 | partial_layout |
| `0x05280018` | SIEGE_0528_0018 *(label)* | S>C | +10 undefined1 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. Likely reply to C>S 0x05280017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:13874<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | partial_layout |
| `0x05280019` | SIEGE_0528_0019 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:14846<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x0528001a` | SIEGE_0528_001A *(label)* | S>C | +10 undefined1 unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12847<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | partial_layout |
| `0x0528001b` | SIEGE_0528_001B *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12448<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x05280020` | SIEGE_0528_0020 *(label)* | S>C | unknown | Siege: reply/notification. Castle siege UI, siege teleport, sentries. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |

## 0x0529

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05290000` | ENTER_EVENT_0529_0000 *(label)* | S>C | unknown | Enter event: reply/notification. Enter event. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:9269<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | located_only |

## 0x052a

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052a0000` | VEHICLE_052A_0000 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:10583 | partial_layout |
| `0x052a0002` | VEHICLE_052A_0002 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:10607 | partial_layout |
| `0x052a0004` | VEHICLE_052A_0004 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:10626 | partial_layout |
| `0x052a0006` | VEHICLE_052A_0006 *(label)* | C>S | empty body | Vehicle: request. Mount/vehicle and vehicle upgrade. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: 0x052a0000, 0x052a0002, 0x052a0004, 0x052a0006, 0x052a0009. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:10649 | partial_layout |

## 0x052b

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052b0001` | A2_052B_0001 *(label)* | C>S | +10 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00700000.c:9510 | partial_layout |
| `0x052b0002` | A2_052B_0002 *(label)* | S>C | +10 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: RECEIVE ----  SA_FAILCOUNT\n | decompiled-source/a2-2moons-2007/dekaron_00700000.c:9342<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:9382 | partial_layout |
| `0x052b0003` | A2_052B_0003 *(label)* | S>C | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: RECEIVE ----  SA_FAILCOUNT\n | decompiled-source/a2-2moons-2007/dekaron_00700000.c:9322<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:9382 | partial_layout |
| `0x052b0004` | A2_052B_0004 *(label)* | S>C | +10 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: RECEIVE ----  SA_FAILCOUNT\n | decompiled-source/a2-2moons-2007/dekaron_00700000.c:9356<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:9382 | partial_layout |

## 0x052c

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052c0001` | EXCHANGE_052C_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 ushort unknown; +18 undefined2 unknown; +1a undefined1 unknown | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0001, size 0x18: +0x00 u32 (npc handle), +0x04 u16 a, +0x06 u16 b   (UNVERIFIED: a = catalog, b = row) *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:8366 | partial_layout |
| `0x052c0003` | EXCHANGE_052C_0003 *(label)* | C>S | empty body | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0003 close, size 0x10 *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:8347 | partial_layout |
| `0x052c0005` | EXCHANGE_052C_0005 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +16 ushort unknown; +18 undefined2 unknown; +1a undefined1 unknown | CoinExchange / Exchange: request. Coin exchange and NPC exchange. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x052c0005, size 0x1c: +0x00 u32, +0x04 u16, +0x06 u16, +0x08 u16, +0x0a u8   (UNVERIFIED: catalog, row, count, kind -> engine 'store' kind) *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:8366 | partial_layout |

## 0x052d

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052d0001` | OBSERVER_052D_0001 *(label)* | C>S | +10 undefined2 unknown | Observer: request. Observer/spectator mode. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5621 | partial_layout |
| `0x052d0003` | OBSERVER_052D_0003 *(label)* | C>S | empty body | Observer: request. Observer/spectator mode. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5643 | partial_layout |
| `0x052d0005` | OBSERVER_052D_0005 *(label)* | C>S | empty body | Observer: request. Observer/spectator mode. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5670 | partial_layout |
| `0x052d0007` | OBSERVER_052D_0007 *(label)* | C>S | unknown | Observer: request. Observer/spectator mode. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5697 | located_only |

## 0x052f

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x052f0000` | ORNAMENT_EVENTS_052F_0000 *(label)* | S>C | unknown | Ornament events: reply/notification. Ornament events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5260<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:5488 | located_only |
| `0x052f0003` | ORNAMENT_EVENTS_052F_0003 *(label)* | S>C | unknown | Ornament events: reply/notification. Ornament events. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5488 | located_only |

## 0x0530

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05300000` | PARTY_WAR_NPC_0530_0000 *(label)* | S>C | +10 undefined4 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:5166<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:5291 | partial_layout |
| `0x05300001` | PARTY_WAR_NPC_0530_0001 *(label)* | S>C | +10 undefined4 unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:5506<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:5631 | partial_layout |
| `0x05300002` | PARTY_WAR_NPC_0530_0002 *(label)* | C>S | +10 undefined2 unknown | Party war (NPC): request. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:2996 | partial_layout |
| `0x05300003` | PARTY_WAR_NPC_0530_0003 *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. Likely reply to C>S 0x05300002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:5418<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:5631 | located_only |
| `0x05300005` | PARTY_WAR_NPC_0530_0005 *(label)* | C>S | +10 undefined2 unknown | Party war (NPC): request. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:2897 | partial_layout |
| `0x05300006` | PARTY_WAR_NPC_0530_0006 *(label)* | S>C | unknown | Party war (NPC): reply/notification. Party war record/teleport via NPC. Likely reply to C>S 0x05300005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:5070<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:5291 | located_only |
| `0x05300015` | PARTY_WAR_NPC_0530_0015 *(label)* | C>S | empty body | Party war (NPC): request. Party war record/teleport via NPC. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00790000.c:2926<br>decompiled-source/a2-2moons-2007/dekaron_00790000.c:3025 | partial_layout |

## 0x0531

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05310000` | OBSERVER_0531_0000 *(label)* | S>C | unknown | Observer: reply/notification. Observer list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:7567<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:8157 | located_only |
| `0x05310001` | OBSERVER_0531_0001 *(label)* | C>S | unknown | Observer: request. Observer list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5643 | located_only |
| `0x05310002` | OBSERVER_0531_0002 *(label)* | S>C | +10 int unknown; +14 undefined3 unknown; +20 undefined4 unknown | Observer: reply/notification. Observer list. Likely reply to C>S 0x05310001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:7845<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:8157 | partial_layout |
| `0x05310003` | OBSERVER_0531_0003 *(label)* | C>S | unknown | Observer: request. Observer list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:5670 | located_only |
| `0x05310004` | OBSERVER_0531_0004 *(label)* | S>C | +10 int unknown; +1c undefined4 unknown | Observer: reply/notification. Observer list. Likely reply to C>S 0x05310003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:7947<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:8157 | partial_layout |
| `0x05310005` | OBSERVER_0531_0005 *(label)* | S>C | +10 int unknown; +14 byte unknown | Observer: reply/notification. Observer list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00760000.c:1255<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:2026 | partial_layout |

## 0x0532

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05320000` | A2_0532_0000 *(label)* | S>C | unknown | Seen only on the wire; purpose unknown. | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:14313 | located_only |
| `0x05320001` | ITEMREMOVESTONE_0532_0001 *(label)* | C>S | unknown | ItemRemoveStone: request. Remove stone from item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05320001 request, size 0x2c (builders 0x1733630 / 0x1733f30; body is a struct copy, pkt+0x28 u32 from [ebp-0x14]): *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:13891<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:13937 | located_only |
| `0x05320002` | A2_0532_0002 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:13975<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:14313 | located_only |
| `0x05320003` | ITEMREMOVESTONE_0532_0003 *(label)* | C>S | empty body | ItemRemoveStone: request. Remove stone from item. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: C>S 0x05320003 close, size 0x10 (0x17335e0) *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:13956<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:14569 | partial_layout |
| `0x05320004` | A2_0532_0004 *(label)* | S>C | unknown | Seen only on the wire; purpose unknown. | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:14313 | located_only |

## 0x0533

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x05330000` | A2_0533_0000 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00700000.c:1465 | partial_layout |
| `0x05330001` | A2_0533_0001 *(label)* | S>C | +10 byte unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00700000.c:1501<br>decompiled-source/a2-2moons-2007/dekaron_00700000.c:1723 | partial_layout |
| `0x05330005` | A2_0533_0005 *(label)* | C>S | +198 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00700000.c:1574 | partial_layout |

## 0x0600

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x06000000` | A2_0600_0000 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown; +19 undefined1 unknown; +1a undefined1 unknown; +1b undefined1 unknown; +1c undefined1 unknown; +1d undefined1 unknown; +1e undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:2941 | partial_layout |
| `0x06000001` | A2_0600_0001 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:6662<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | located_only |
| `0x06000002` | A2_0600_0002 *(label)* | S>C | +14 int unknown; +18 int unknown; +1c undefined1 unknown; +1d uint unknown; +21 undefined4 unknown; +25 undefined4 unknown; +29 undefined4 unknown; +2c undefined4 unknown; +2d undefined2 unknown; +2f undefined1 unknown; +30 undefined4 unknown; +34 undefined4 unknown; +38 undefined4 unknown; +3c undefined4 unknown; +40 undefined2 unknown; +42 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7030<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | partial_layout |
| `0x06000003` | A2_0600_0003 *(label)* | S>C | +10 undefined4 unknown; +14 int unknown; +18 int unknown; +1c int unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined1 unknown; +2d undefined1 unknown; +2e undefined1 unknown; +34 undefined1 unknown; +36 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: SlidePacket : %d %d | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7240<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | partial_layout |
| `0x06000004` | A2_0600_0004 *(label)* | S>C | +10 undefined4 unknown; +14 int unknown; +18 int unknown; +1c int unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined1 unknown; +2d undefined1 unknown; +2e undefined1 unknown; +2f uint unknown; +33 uint unknown; +37 undefined4 unknown; +3b undefined4 unknown; +3f undefined4 unknown; +43 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:6797<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | partial_layout |
| `0x06000005` | A2_0600_0005 *(label)* | S>C | +10 int unknown; +14 int unknown; +18 int unknown; +1c undefined4 unknown; +20 undefined1 unknown; +21 uint unknown; +25 undefined4 unknown; +29 undefined1 unknown; +2b undefined1 unknown; +2d undefined4 unknown; +31 undefined1 unknown; +32 undefined1 unknown; +33 char unknown; +34 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:6548<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | partial_layout |
| `0x06000006` | A2_0600_0006 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 int unknown; +1c int unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +2c undefined1 unknown; +2d undefined1 unknown; +2e uint unknown; +32 undefined4 unknown; +36 undefined4 unknown; +3a undefined4 unknown; +3d undefined4 unknown; +3e undefined2 unknown; +40 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:6943<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | partial_layout |
| `0x06000007` | A2_0600_0007 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:6708<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | located_only |
| `0x06000008` | A2_0600_0008 *(label)* | S>C | +14 undefined4 unknown; +18 int unknown; +1c undefined1 unknown; +1d uint unknown; +21 undefined4 unknown; +25 undefined4 unknown; +29 undefined4 unknown; +2c undefined4 unknown; +2d undefined2 unknown; +2f undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7107<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | partial_layout |
| `0x06000009` | A2_0600_0009 *(label)* | S>C | +14 int unknown; +18 undefined4 unknown; +1c undefined1 unknown; +1d uint unknown; +21 undefined4 unknown; +25 undefined4 unknown; +29 undefined4 unknown; +2d undefined2 unknown; +2f undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7173<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | partial_layout |
| `0x0600000b` | MESSAGE_0600_000B *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined1 unknown; +1d undefined1 unknown; +1e undefined1 unknown; +20 undefined1 unknown | Message / mail (legacy): request. Legacy message/mail. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00520000.c:10171 | partial_layout |
| `0x0600000c` | MESSAGE_0600_000C *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown; +19 undefined1 unknown; +1a undefined1 unknown; +1c undefined1 unknown; +1d undefined1 unknown | Message / mail (legacy): request. Legacy message/mail. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00520000.c:13945 | partial_layout |
| `0x0600000d` | MESSAGE_0600_000D *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined1 unknown; +19 undefined1 unknown; +1a undefined1 unknown; +1c undefined1 unknown; +1d undefined1 unknown | Message / mail (legacy): request. Legacy message/mail. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00520000.c:12110 | partial_layout |
| `0x06000100` | A2_0600_0100 *(label)* | S>C | +10 undefined4 unknown; +14 int unknown; +18 int unknown; +1c int unknown; +20 undefined4 unknown; +24 undefined4 unknown; +28 undefined4 unknown; +30 undefined1 unknown; +31 undefined1 unknown; +32 uint unknown; +36 uint unknown; +3a undefined4 unknown; +3e undefined4 unknown; +42 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:6411<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7341 | partial_layout |

## 0x0602

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x06020001` | A2_0602_0001 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00530000.c:2968<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:3007 | partial_layout |
| `0x06020002` | ENTER_EVENT_0602_0002 *(label)* | C>S | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined4 unknown | Enter event: request. Enter event. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:12570<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:12657<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:13016 … | partial_layout |

## 0x0603

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x06030006` | EFFECT_EVENT_0603_0006 *(label)* | S>C | +10 short unknown; +12 short unknown; +14 undefined4 unknown; +18 undefined4 unknown | Effect event: reply/notification. Effect event. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8107<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:8392 | partial_layout |
| `0x06030007` | EFFECT_EVENT_0603_0007 *(label)* | S>C | +10 short unknown; +12 short unknown; +14 undefined4 unknown; +18 undefined4 unknown; +1c undefined4 unknown | Effect event: reply/notification. Effect event. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8160<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:8392 | partial_layout |

## 0x0604

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x06040000` | SKILL_0604_0000 *(label)* | C>S | +10 undefined4 unknown; +16 undefined1 unknown; +17 undefined1 unknown; +18 undefined1 unknown; +19 undefined1 unknown; +1a undefined1 unknown; +1b undefined1 unknown; +1c undefined4 unknown; +20 undefined2 unknown | Skill: request. Skill net. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:3704 | partial_layout |

## 0x0700

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x07000002` | GAMEMASTER_0700_0002 *(label)* | C>S | unknown | GameMaster / Developer / Dekaron provider: request and reply share this opcode. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6482<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8213 | located_only |
| `0x07000003` | A2_0700_0003 *(label)* | C>S | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6512<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8243 | partial_layout |
| `0x07000004` | A2_0700_0004 *(label)* | S>C | +10 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00770000.c:6928<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:1791 … | partial_layout |
| `0x07000005` | GAMEMASTER_0700_0005 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6551<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8282 | partial_layout |
| `0x07000006` | GAMEMASTER_0700_0006 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:6992<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:1855 … | partial_layout |
| `0x07000007` | GAMEMASTER_0700_0007 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:5945<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7518 | partial_layout |
| `0x07000009` | GAMEMASTER_0700_0009 *(label)* | C>S | +10 undefined2 unknown; +12 undefined4 unknown; +16 undefined2 unknown; +18 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00510000.c:13111<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6238<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7811 … | partial_layout |
| `0x0700000b` | GAMEMASTER_0700_000B *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:5968<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7541 | partial_layout |
| `0x0700000c` | GAMEMASTER_0700_000C *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00740000.c:1319 | located_only |
| `0x0700000d` | GAMEMASTER_0700_000D *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00740000.c:1319 | located_only |
| `0x0700000e` | GAMEMASTER_0700_000E *(label)* | C>S | +10 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6016<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7589 | partial_layout |
| `0x07000010` | GAMEMASTER_0700_0010 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7056<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:1919 … | partial_layout |
| `0x07000011` | A2_0700_0011 *(label)* | C>S | +10 undefined2 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6037<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7610 | partial_layout |
| `0x07000012` | A2_0700_0012 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings: %d / %d; %d / %d | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7119<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:1982 … | located_only |
| `0x07000013` | GAMEMASTER_0700_0013 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6058<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7631 | partial_layout |
| `0x07000014` | GAMEMASTER_0700_0014 *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000013 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:6879<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:1742 … | located_only |
| `0x07000015` | A2_0700_0015 *(label)* | C>S | +10 undefined2 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:5995<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7568 | partial_layout |
| `0x07000016` | A2_0700_0016 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings: Reset MaxPC OK; Reset MaxPC OK | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7133<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:1996 … | located_only |
| `0x07000017` | GAMEMASTER_0700_0017 *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6734<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8310 | partial_layout |
| `0x07000018` | GAMEMASTER_0700_0018 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000017 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2526<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x0700001b` | A2_0700_001B *(label)* | C>S | +10 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6077<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7650 | partial_layout |
| `0x0700001c` | A2_0700_001C *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings: Reset Exp Ratio OK; Reset Exp Ratio OK | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7154<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2017 … | located_only |
| `0x0700001e` | A2_0700_001E *(label)* | C>S | +10 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6098<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7671 | partial_layout |
| `0x0700001f` | A2_0700_001F *(label)* | S>C | +18 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings: OK Old(%f) New(%f); OK Old(%f) New(%f) | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7175<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2038 … | partial_layout |
| `0x07000020` | A2_0700_0020 *(label)* | C>S | +10 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6119<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7692 | partial_layout |
| `0x07000021` | A2_0700_0021 *(label)* | S>C | +18 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings: OK Old(%f) New(%f); OK Old(%f) New(%f) | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7217<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2080 … | partial_layout |
| `0x07000022` | GAMEMASTER_0700_0022 *(label)* | C>S | +10 undefined1 unknown; +12 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6163<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6185<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7736 … | partial_layout |
| `0x07000023` | GAMEMASTER_0700_0023 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000022 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7323<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2186 … | partial_layout |
| `0x07000024` | GAMEMASTER_0700_0024 *(label)* | C>S | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6140<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7713<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:858 | partial_layout |
| `0x07000025` | GAMEMASTER_0700_0025 *(label)* | S>C | +10 char unknown; +12 undefined4 unknown; +16 undefined2 unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000024 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7259<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2122 … | partial_layout |
| `0x07000026` | GAMEMASTER_0700_0026 *(label)* | C>S | +10 undefined2 unknown; +12 undefined2 unknown; +14 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6579<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8340 | partial_layout |
| `0x07000027` | GAMEMASTER_0700_0027 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000026 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2229<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x07000028` | GAMEMASTER_0700_0028 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6618<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8379 | partial_layout |
| `0x07000029` | GAMEMASTER_0700_0029 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000028 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2272<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x0700002a` | GAMEMASTER_0700_002A *(label)* | C>S | +10 undefined1 unknown; +12 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6646<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7949<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8407 … | partial_layout |
| `0x0700002b` | GAMEMASTER_0700_002B *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002a (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2332<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x0700002c` | GAMEMASTER_0700_002C *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6674<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6704<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8437 … | partial_layout |
| `0x0700002d` | GAMEMASTER_0700_002D *(label)* | S>C | +10 ushort unknown; +12 ushort unknown; +14 ushort unknown; +16 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002c (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2395<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x0700002e` | GAMEMASTER_0700_002E *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6408<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7930 | partial_layout |
| `0x0700002f` | GAMEMASTER_0700_002F *(label)* | S>C | unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700002e (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2368<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | located_only |
| `0x07000030` | GAMEMASTER_0700_0030 *(label)* | C>S | +10 undefined1 unknown; +11 undefined1 unknown; +12 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7971<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8527 | partial_layout |
| `0x07000031` | GAMEMASTER_0700_0031 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000030 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2542<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x07000032` | GAMEMASTER_0700_0032 *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:3052<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8032 | partial_layout |
| `0x07000033` | GAMEMASTER_0700_0033 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000032 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2610<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x07000034` | GAMEMASTER_0700_0034 *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:3052<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8053 | partial_layout |
| `0x07000035` | GAMEMASTER_0700_0035 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000034 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2637<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x07000036` | GAMEMASTER_0700_0036 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8013 | partial_layout |
| `0x07000037` | GAMEMASTER_0700_0037 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000036 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2594<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x07000038` | GAMEMASTER_0700_0038 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7994 | partial_layout |
| `0x07000039` | GAMEMASTER_0700_0039 *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000038 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00780000.c:2578<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:2830 | partial_layout |
| `0x0700003a` | GAMEMASTER_0700_003A *(label)* | C>S | unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:2922 | located_only |
| `0x0700003b` | GAMEMASTER_0700_003B *(label)* | S>C | +10 char unknown; +14 undefined4 unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700003a (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:7481<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:7865 | partial_layout |
| `0x0700003c` | GAMEMASTER_0700_003C *(label)* | C>S | +10 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8074<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:8724<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:908 | partial_layout |
| `0x0700003e` | GAMEMASTER_0700_003E *(label)* | C>S | +10 undefined2 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8095<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:8760<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:944 | partial_layout |
| `0x07000040` | GAMEMASTER_0700_0040 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8116<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7718<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:435 | partial_layout |
| `0x07000041` | GAMEMASTER_0700_0041 *(label)* | S>C | +10 char unknown; +11 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000040 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7393<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:122 … | partial_layout |
| `0x07000042` | GAMEMASTER_0700_0042 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8135<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7737<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:454 | partial_layout |
| `0x07000043` | GAMEMASTER_0700_0043 *(label)* | S>C | +10 char unknown; +11 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000042 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7420<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:149 … | partial_layout |
| `0x07000044` | A2_0700_0044 *(label)* | C>S | empty body | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8154<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7756<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:473 | partial_layout |
| `0x07000045` | A2_0700_0045 *(label)* | S>C | +10 char unknown | Purpose unknown. Handler/builder located (see refs); debug strings: ResetCoolTime Command is Success; Close GuildWar Teleport Command is Fail; ResetCoolTime Command is Success; Close GuildWar Teleport Command is Fail | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7447<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:176 … | partial_layout |
| `0x07000047` | GAMEMASTER_0700_0047 *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8173<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:8796<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:980 | partial_layout |
| `0x07000048` | GAMEMASTER_0700_0048 *(label)* | S>C | +10 int unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000047 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7463<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:192 … | partial_layout |
| `0x07000049` | GAMEMASTER_0700_0049 *(label)* | C>S | empty body | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:8194<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7775<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:492 | partial_layout |
| `0x0700004a` | GAMEMASTER_0700_004A *(label)* | S>C | +10 int unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x07000049 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7479<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:208 … | partial_layout |
| `0x0700004b` | GAMEMASTER_0700_004B *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6427<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7310<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7888 | partial_layout |
| `0x0700004c` | GAMEMASTER_0700_004C *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700004b (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7495<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:256 … | partial_layout |
| `0x0700004d` | GAMEMASTER_0700_004D *(label)* | C>S | +10 undefined4 unknown | GameMaster / Developer / Dekaron provider: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6448<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7331<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7909 | partial_layout |
| `0x0700004e` | GAMEMASTER_0700_004E *(label)* | S>C | +10 char unknown | GameMaster / Developer / Dekaron provider: reply/notification. GM and developer commands. Likely reply to C>S 0x0700004d (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7511<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:272 … | partial_layout |

## 0x0800

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x08000002` | GAMEMASTER_0800_0002 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00510000.c:13127<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6285<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7187 | partial_layout |
| `0x08000003` | GAMEMASTER_0800_0003 *(label)* | C>S | +10 undefined4 unknown; +14 undefined2 unknown; +18 undefined4 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00510000.c:13127<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6323<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7225 | partial_layout |
| `0x08000004` | A2_0800_0004 *(label)* | C>S | +10 undefined2 unknown; +12 undefined4 unknown; +16 undefined2 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00510000.c:13127<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6355<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7257 | partial_layout |
| `0x08000005` | GAMEMASTER_0800_0005 *(label)* | C>S | +10 undefined1 unknown | GameMaster / Developer: request. GM and developer commands. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00530000.c:2922<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:6387<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:7289 | partial_layout |
| `0x08000006` | GAMEMASTER_0800_0006 *(label)* | S>C | +10 undefined1 unknown | GameMaster / Developer: reply/notification. GM and developer commands. Likely reply to C>S 0x08000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00770000.c:7366<br>decompiled-source/a2-2moons-2007/dekaron_00770000.c:7527<br>decompiled-source/a2-2moons-2007/dekaron_00780000.c:288 … | partial_layout |
| `0x08000007` | A2_0800_0007 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00770000.c:1109 | located_only |
| `0x08000008` | A2_0800_0008 *(label)* | C>S | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00770000.c:1125 | located_only |

## 0x0900

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x09000000` | GUILD_0900_0000 *(label)* | C>S | unknown | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:5214 | located_only |
| `0x09000001` | GUILD_0900_0001 *(label)* | S>C | +18 undefined2 unknown; +1a undefined1 unknown; +1e undefined1 unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:1864<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x09000002` | A2_0900_0002 *(label)* | S>C | +4a undefined2 unknown; +4c undefined1 unknown; +50 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2016<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x09000003` | A2_0900_0003 *(label)* | S>C | +18 undefined2 unknown; +1a undefined1 unknown; +1e undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2066<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x09000004` | GUILD_0900_0004 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:115<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x09000005` | GUILD_0900_0005 *(label)* | both | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:3473<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:560 | partial_layout |
| `0x09000006` | GUILD_0900_0006 *(label)* | S>C | +18 int unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13693<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x09000008` | GUILD_0900_0008 *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3521 | partial_layout |
| `0x0900000b` | GUILD_0900_000B *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3521<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:3762 | partial_layout |
| `0x0900000c` | GUILD_0900_000C *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x0900000d` | GUILD_0900_000D *(label)* | C>S | +10 undefined2 unknown; +12 undefined1 unknown | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:8563 | partial_layout |
| `0x0900000e` | GUILD_0900_000E *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000d (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:7928<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:8137 | located_only |
| `0x0900000f` | GUILD_0900_000F *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3637 | partial_layout |
| `0x09000010` | GUILD_0900_0010 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x0900000f (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:14486<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x09000011` | GUILD_0900_0011 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x09000012` | GUILD_0900_0012 *(label)* | C>S | empty body | Guild: request. Guild create/join/leave/notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3497 | partial_layout |
| `0x09000013` | GUILD_0900_0013 *(label)* | S>C | unknown | Guild: reply/notification. Guild create/join/leave/notice. Likely reply to C>S 0x09000012 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13513<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |

## 0x0901

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x09010000` | GUILD_0901_0000 *(label)* | S>C | unknown | Guild: reply/notification. Guild notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:162<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x09010001` | GUILD_0901_0001 *(label)* | S>C | unknown | Guild: reply/notification. Guild notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13792<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |

## 0x0902

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x09020000` | ENTER_DONE | C>S | empty body | Client finished loading the map (empty body). Server then starts sending world objects. | decompiled-source/a2-2moons-2007/dekaron_00500000.c:9282 | explained |
| `0x09020001` | GUILD_0902_0001 *(label)* | C>S | unknown | Guild: request. Guild UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:4191 | located_only |
| `0x09020002` | GUILD_0902_0002 *(label)* | S>C | unknown | Guild: reply/notification. Guild UI. Likely reply to C>S 0x09020001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:15210<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x09020003` | GUILD_0902_0003 *(label)* | S>C | unknown | Guild: reply/notification. Guild UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:15322<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x09020004` | GUILD_0902_0004 *(label)* | both | +4a undefined1 unknown | Guild: request and reply share this opcode. Guild UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:15125<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:3826 | partial_layout |
| `0x09020005` | GUILD_0902_0005 *(label)* | S>C | unknown | Guild: reply/notification. Guild UI. Likely reply to C>S 0x09020004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |

## 0x0903

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x09030000` | GUILD_0903_0000 *(label)* | C>S | +10 undefined4 unknown | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3661 | partial_layout |
| `0x09030001` | GUILD_0903_0001 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:14722<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x09030002` | GUILD_0903_0002 *(label)* | C>S | empty body | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3691 | partial_layout |
| `0x09030003` | GUILD_0903_0003 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:14848<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x09030004` | GUILD_0903_0004 *(label)* | S>C | +14 ushort unknown; +18 undefined4 unknown; +1c undefined1 unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:15013<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x09030005` | GUILD_0903_0005 *(label)* | C>S | empty body | Guild / GuildDungeon: request. Guild members, guild dungeon delivery/ranking. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3715 | partial_layout |
| `0x09030006` | GUILD_0903_0006 *(label)* | S>C | unknown | Guild / GuildDungeon: reply/notification. Guild members, guild dungeon delivery/ranking. Likely reply to C>S 0x09030005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13539<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |

## 0x0a00

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a000000` | CHAT_0A00_0000 *(label)* | S>C | unknown | Chat: reply/notification. Chat. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:6236<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | located_only |

## 0x0a02

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a020000` | MESSENGER_0A02_0000 *(label)* | both | unknown | Messenger: request and reply share this opcode. Messenger (friends) list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5716<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:7282 | located_only |
| `0x0a020001` | MESSENGER_0A02_0001 *(label)* | S>C | +2c undefined1 unknown | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5783<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | partial_layout |
| `0x0a020002` | MESSENGER_0A02_0002 *(label)* | S>C | +2c undefined1 unknown; +2e undefined2 unknown; +30 undefined1 unknown; +31 char unknown | Messenger: reply/notification. Messenger (friends) list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5419<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | partial_layout |
| `0x0a020003` | MESSENGER_0A02_0003 *(label)* | C>S | +45 undefined1 unknown | Messenger: request. Messenger (friends) list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:7394 | partial_layout |
| `0x0a020004` | MESSENGER_0A02_0004 *(label)* | S>C | +2c undefined1 unknown | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5497<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | partial_layout |
| `0x0a020005` | MESSENGER_0A02_0005 *(label)* | C>S | unknown | Messenger: request. Messenger (friends) list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:7338 | located_only |
| `0x0a020006` | MESSENGER_0A02_0006 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:6124<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | located_only |
| `0x0a020007` | MESSENGER_0A02_0007 *(label)* | C>S | unknown | Messenger: request. Messenger (friends) list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:7456 | located_only |
| `0x0a020008` | MESSENGER_0A02_0008 *(label)* | S>C | +2c char unknown | Messenger: reply/notification. Messenger (friends) list. Likely reply to C>S 0x0a020007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5923<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | partial_layout |
| `0x0a020009` | MESSENGER_0A02_0009 *(label)* | S>C | +45 undefined1 unknown; +46 undefined2 unknown; +48 undefined1 unknown; +49 char unknown | Messenger: reply/notification. Messenger (friends) list. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5618<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | partial_layout |

## 0x0a03

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a030000` | MESSENGER_0A03_0000 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5259<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | located_only |
| `0x0a030001` | MESSENGER_0A03_0001 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5305<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | located_only |

## 0x0a56

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0a560004` | A2_0A56_0004 *(label)* | S>C | +10 undefined4 unknown; +2e undefined4 unknown; +32 undefined2 unknown; +34 undefined2 unknown; +38 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pItemArticle != NULL; pFlyWeight != NULL; New Enter : Ornament Item | decompiled-source/a2-2moons-2007/dekaron_00530000.c:8824<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | partial_layout |

## 0x0b29

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0b290002` | A2_0B29_0002 *(label)* | S>C | +10 undefined4 unknown; +14 undefined4 unknown; +18 undefined2 unknown; +1a undefined1 unknown; +1b undefined1 unknown; +1c undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: New Enter : Remote( %08X ) | decompiled-source/a2-2moons-2007/dekaron_00530000.c:9108<br>decompiled-source/a2-2moons-2007/dekaron_00530000.c:9741 | partial_layout |

## 0x0c00

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0c000000` | NEWLETTER_MAIL_0C00_0000 *(label)* | C>S | empty body | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:4507 | partial_layout |
| `0x0c000001` | NEWLETTER_MAIL_0C00_0001 *(label)* | S>C | +10 int unknown; +14 undefined2 unknown; +18 ushort unknown; +1a char unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:2786<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:3754 | partial_layout |
| `0x0c000002` | NEWLETTER_MAIL_0C00_0002 *(label)* | S>C | unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:3081<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:3754 | located_only |
| `0x0c000003` | MAIL_COUNTS_PARTIAL_0C00_0003 *(label)* | C>S | empty body | NewLetter (mail): request. Mail list/read/send/delete. Prior-build note (43.3.0, INFERRED for 0.0.1): module-doc: Global mail count request0x0c000003 builder175d4b0: header only. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:4548 | partial_layout |
| `0x0c000004` | MAIL_COUNTS_PARTIAL_0C00_0004 *(label)* | S>C | +10 int unknown; +14 undefined2 unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:2925<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:3754 | partial_layout |
| `0x0c000005` | NEWLETTER_MAIL_0C00_0005 *(label)* | C>S | unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:4589 | located_only |
| `0x0c000006` | NEWLETTER_MAIL_0C00_0006 *(label)* | S>C | +1c undefined4 unknown; +20 undefined2 unknown; +22 undefined1 unknown; +24 int unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:3118<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:3754 | partial_layout |
| `0x0c000007` | NEWLETTER_MAIL_0C00_0007 *(label)* | C>S | unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:4657 | located_only |
| `0x0c000008` | NEWLETTER_MAIL_0C00_0008 *(label)* | S>C | +1c undefined4 unknown; +20 undefined2 unknown; +22 undefined1 unknown; +24 int unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:3288<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:3754 | partial_layout |
| `0x0c000009` | NEWLETTER_MAIL_0C00_0009 *(label)* | C>S | unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:4725 | located_only |
| `0x0c00000a` | NEWLETTER_MAIL_0C00_000A *(label)* | S>C | +1c undefined4 unknown; +20 undefined2 unknown; +22 undefined1 unknown; +24 int unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c000009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:3460<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:3754 | partial_layout |
| `0x0c00000b` | NEWLETTER_MAIL_0C00_000B *(label)* | C>S | unknown | NewLetter (mail): request. Mail list/read/send/delete. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:4793 | located_only |
| `0x0c00000c` | NEWLETTER_MAIL_0C00_000C *(label)* | S>C | +1c undefined4 unknown; +20 undefined2 unknown; +22 undefined1 unknown; +24 int unknown | NewLetter (mail): reply/notification. Mail list/read/send/delete. Likely reply to C>S 0x0c00000b (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:3574<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:3754 | partial_layout |

## 0x0d00

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0d000000` | CASHSHOP_0D00_0000 *(label)* | C>S | empty body | CashShop / VipShop: request. Cash shop. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:13018 | partial_layout |
| `0x0d000001` | CASHSHOP_0D00_0001 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. Likely reply to C>S 0x0d000000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:10782<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11796<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:10221 … | located_only |
| `0x0d000002` | A2_0D00_0002 *(label)* | C>S | +10 undefined2 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:12304<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:11786 | partial_layout |
| `0x0d000003` | CASHSHOP_0D00_0003 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11113<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11796<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:10554 … | located_only |
| `0x0d000004` | A2_0D00_0004 *(label)* | S>C | +18 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_004e0000.c:10169<br>decompiled-source/a2-2moons-2007/dekaron_004e0000.c:10948 | partial_layout |
| `0x0d000005` | CASHSHOP_0D00_0005 *(label)* | S>C | unknown | CashShop / VipShop: reply/notification. Cash shop. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:10746<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11796<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:10185 … | located_only |
| `0x0d000006` | A2_0D00_0006 *(label)* | C>S | +10 undefined2 unknown; +24f undefined1 unknown; +274 undefined4 unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:12789<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:11953 | partial_layout |
| `0x0d000007` | A2_0D00_0007 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings: NoUserName; NoUserName | decompiled-source/a2-2moons-2007/dekaron_006f0000.c:10892<br>decompiled-source/a2-2moons-2007/dekaron_006f0000.c:11796<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:10331 … | located_only |

## 0x0e01

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0e010002` | MONSTER_AI_0E01_0002 *(label)* | C>S | unknown | Monster AI: request. Monster attack. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00520000.c:9538 | located_only |

## 0x0f00

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0f000004` | SIEGE_MISC_0F00_0004 *(label)* | S>C | unknown | Siege (misc): reply/notification. Siege notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12583<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x0f000005` | SIEGE_MISC_0F00_0005 *(label)* | S>C | unknown | Siege (misc): reply/notification. Siege notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12604<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |

## 0x0f02

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0f020000` | SIEGE_0F02_0000 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:862 | partial_layout |
| `0x0f020001` | SIEGE_0F02_0001 *(label)* | S>C | unknown | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:14136<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x0f020002` | SIEGE_0F02_0002 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:885 | partial_layout |
| `0x0f020003` | SIEGE_0F02_0003 *(label)* | S>C | unknown | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020002 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:13201<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x0f020004` | SIEGE_0F02_0004 *(label)* | C>S | +10 undefined1 unknown | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:977 | partial_layout |
| `0x0f020005` | SIEGE_0F02_0005 *(label)* | S>C | unknown | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020004 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:13624<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x0f020006` | A2_0F02_0006 *(label)* | S>C | +10 undefined4 unknown; +14 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pDialog != NULL; Teleport SN_Open Fail !!! | decompiled-source/a2-2moons-2007/dekaron_00760000.c:6945<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:7179 | partial_layout |
| `0x0f020007` | SIEGE_0F02_0007 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:1007 | partial_layout |
| `0x0f020008` | A2_0F02_0008 *(label)* | S>C | unknown | Seen only on the wire; purpose unknown. | decompiled-source/a2-2moons-2007/dekaron_00760000.c:7179 | located_only |
| `0x0f020009` | A2_0F02_0009 *(label)* | S>C | +10 undefined4 unknown; +14 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pDialog != NULL; Teleport SN_Open Fail !!! | decompiled-source/a2-2moons-2007/dekaron_00760000.c:6607<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:6842 | partial_layout |
| `0x0f02000a` | SIEGE_0F02_000A *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:1030 | partial_layout |
| `0x0f02000b` | A2_0F02_000B *(label)* | S>C | unknown | Seen only on the wire; purpose unknown. | decompiled-source/a2-2moons-2007/dekaron_00760000.c:6842 | located_only |
| `0x0f02000c` | A2_0F02_000C *(label)* | S>C | +10 undefined4 unknown; +14 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pDialog != NULL; Teleport SN_Open Fail !!! | decompiled-source/a2-2moons-2007/dekaron_00760000.c:8530<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:8724 | partial_layout |
| `0x0f02000d` | SIEGE_0F02_000D *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:1053 | partial_layout |
| `0x0f02000e` | A2_0F02_000E *(label)* | S>C | unknown | Seen only on the wire; purpose unknown. | decompiled-source/a2-2moons-2007/dekaron_00760000.c:8724 | located_only |
| `0x0f02000f` | A2_0F02_000F *(label)* | S>C | +14 undefined1 unknown | Purpose unknown. Handler/builder located (see refs); debug strings: pDialog != NULL; Siege Info SN_Open Fail !!! | decompiled-source/a2-2moons-2007/dekaron_00760000.c:7282<br>decompiled-source/a2-2moons-2007/dekaron_00760000.c:7520 | partial_layout |
| `0x0f020010` | SIEGE_0F02_0010 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:954 | partial_layout |
| `0x0f020011` | A2_0F02_0011 *(label)* | S>C | unknown | Seen only on the wire; purpose unknown. | decompiled-source/a2-2moons-2007/dekaron_00760000.c:7520 | located_only |
| `0x0f020012` | SIEGE_0F02_0012 *(label)* | C>S | empty body | Siege: request. Siege UI. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00710000.c:931 | partial_layout |
| `0x0f020013` | SIEGE_0F02_0013 *(label)* | S>C | unknown | Siege: reply/notification. Siege UI. Likely reply to C>S 0x0f020012 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:13067<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |

## 0x0f03

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x0f030008` | SIEGE_MISC_0F03_0008 *(label)* | S>C | unknown | Siege (misc): reply/notification. Siege notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12709<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |

## 0x1000

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x10000001` | SHOP_MISC_1000_0001 *(label)* | C>S | +10 undefined4 unknown; +14 short unknown; +16 undefined2 unknown; +18 undefined1 unknown; +19 undefined1 unknown | Shop (misc): request. Shop notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:6299 | partial_layout |
| `0x10000002` | SHOP_MISC_1000_0002 *(label)* | S>C | unknown | Shop (misc): reply/notification. Shop notices. Likely reply to C>S 0x10000001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:5924<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:6066 | located_only |
| `0x10000003` | SHOP_MISC_1000_0003 *(label)* | S>C | unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11678<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | located_only |
| `0x10000004` | SHOP_MISC_1000_0004 *(label)* | S>C | unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11754<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | located_only |
| `0x10000005` | SHOP_MISC_1000_0005 *(label)* | S>C | unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11830<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | located_only |
| `0x10000006` | SHOP_MISC_1000_0006 *(label)* | S>C | unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11878<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | located_only |
| `0x10000007` | SHOP_MISC_1000_0007 *(label)* | S>C | unknown | Shop (misc): reply/notification. Shop notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00750000.c:11953<br>decompiled-source/a2-2moons-2007/dekaron_00750000.c:12028 | located_only |

## 0x1100

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11000004` | GUILD_EXTENDED_1100_0004 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13528<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x11000005` | GUILD_EXTENDED_1100_0005 *(label)* | S>C | +23a undefined2 unknown; +23c undefined4 unknown; +240 undefined2 unknown; +242 undefined2 unknown; +244 undefined2 unknown; +24c undefined4 unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:249<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x11000006` | GUILD_EXTENDED_1100_0006 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2458<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x11000007` | GUILD_EXTENDED_1100_0007 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:341 | located_only |
| `0x11000008` | GUILD_EXTENDED_1100_0008 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13550<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |

## 0x1101

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11010000` | GUILD_1101_0000 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3540 | located_only |
| `0x11010001` | GUILD_1101_0001 *(label)* | S>C | unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11010000 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:14588<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x11010003` | GUILD_1101_0003 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3972 | located_only |
| `0x11010004` | GUILD_1101_0004 *(label)* | S>C | unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11010003 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13845<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x11010006` | GUILD_1101_0006 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:5981 | located_only |
| `0x11010009` | GUILD_1101_0009 *(label)* | C>S | +18 undefined1 unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:4317 | partial_layout |
| `0x1101000c` | GUILD_1101_000C *(label)* | C>S | +18 undefined1 unknown; +1c undefined4 unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3609 | partial_layout |
| `0x1101000f` | GUILD_1101_000F *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:5997 | located_only |
| `0x11010018` | GUILD_1101_0018 *(label)* | S>C | unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |

## 0x1102

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11020000` | GUILD_1102_0000 *(label)* | S>C | +31 char unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2116<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x11020005` | GUILD_1102_0005 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3564 | located_only |
| `0x11020006` | GUILD_1102_0006 *(label)* | S>C | unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11020005 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:15469<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x11020007` | GUILD_1102_0007 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3911 | located_only |
| `0x11020008` | GUILD_1102_0008 *(label)* | S>C | unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11020007 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:3 | located_only |
| `0x11020009` | GUILD_1102_0009 *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:6013 | located_only |
| `0x1102000a` | GUILD_1102_000A *(label)* | S>C | unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11020009 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:14254<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x1102000b` | GUILD_1102_000B *(label)* | S>C | +18 undefined1 unknown | Guild: reply/notification. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:1201<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x1102000c` | GUILD_1102_000C *(label)* | C>S | unknown | Guild: request. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:4524 | located_only |
| `0x1102000d` | GUILD_1102_000D *(label)* | S>C | unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x1102000c (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:14356<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |

## 0x1103

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11030000` | GUILD_1103_0000 *(label)* | both | unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:494<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:5385 | located_only |
| `0x11030001` | GUILD_1103_0001 *(label)* | both | unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:5606<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:631 | located_only |
| `0x11030002` | GUILD_1103_0002 *(label)* | S>C | +18 undefined1 unknown | Guild: reply/notification. Guild. Likely reply to C>S 0x11030001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:13574<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | partial_layout |
| `0x11030003` | GUILD_1103_0003 *(label)* | C>S | +20 undefined2 unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3588 | partial_layout |
| `0x11030004` | GUILD_1103_0004 *(label)* | C>S | unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:4020 | located_only |
| `0x11030005` | GUILD_1103_0005 *(label)* | C>S | unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:3449 | located_only |
| `0x11030007` | GUILD_1103_0007 *(label)* | C>S | unknown | Guild: request and reply share this opcode. Guild. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:5490 | located_only |

## 0x1105

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x11050000` | GUILD_EXTENDED_1105_0000 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:1777<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |
| `0x11050001` | GUILD_EXTENDED_1105_0001 *(label)* | S>C | unknown | Guild (extended): reply/notification. Guild notices. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00730000.c:1826<br>decompiled-source/a2-2moons-2007/dekaron_00730000.c:2560 | located_only |

## 0x1200

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x12000000` | UNATTRIBUTED_1200_0000 *(label)* | S>C | +1c undefined4 unknown; +20 undefined4 unknown; +34 undefined1 unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12518<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | partial_layout |
| `0x12000001` | UNATTRIBUTED_1200_0001 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12541<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x12000002` | UNATTRIBUTED_1200_0002 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12560<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |
| `0x12000003` | UNATTRIBUTED_1200_0003 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:12627<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |

## 0x1202

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x12020000` | UNATTRIBUTED_1202_0000 *(label)* | S>C | unknown | (unattributed): reply/notification. Unattributed (dispatcher FUN_013c06a0). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00700000.c:13717<br>decompiled-source/a2-2moons-2007/dekaron_00710000.c:3 | located_only |

## 0x1400

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x14000001` | MESSENGER_1400_0001 *(label)* | C>S | +30 char unknown; +31 char unknown | Messenger: request. Messenger. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:7179 | partial_layout |
| `0x14000002` | MESSENGER_1400_0002 *(label)* | both | +2c undefined1 unknown; +2e undefined2 unknown; +30 undefined1 unknown; +31 char unknown | Messenger: request and reply share this opcode. Messenger. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5341<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:7226 | partial_layout |

## 0x1401

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x14010001` | MESSENGER_1401_0001 *(label)* | both | unknown | Messenger: request and reply share this opcode. Messenger. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:6396<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:8492 | located_only |
| `0x14010002` | MESSENGER_1401_0002 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger. Likely reply to C>S 0x14010001 (request even / reply odd convention). *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5696<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | located_only |
| `0x14010004` | MESSENGER_1401_0004 *(label)* | S>C | unknown | Messenger: reply/notification. Messenger. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5230<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | located_only |
| `0x14010005` | MESSENGER_1401_0005 *(label)* | C>S | unknown | Messenger: request. Messenger. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:7207 | located_only |
| `0x14010006` | MESSENGER_1401_0006 *(label)* | both | unknown | Messenger: request and reply share this opcode. Messenger. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:6583<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:8088 | located_only |

## 0x1402

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x14020000` | MESSENGER_1402_0000 *(label)* | S>C | +14 undefined1 unknown | Messenger: reply/notification. Messenger notice. *(INFERRED)* | decompiled-source/a2-2moons-2007/dekaron_00720000.c:5214<br>decompiled-source/a2-2moons-2007/dekaron_00720000.c:6676 | partial_layout |

## 0x5000

| opcode | name | dir | layout | what it does | ref | status |
|---|---|---|---|---|---|---|
| `0x50000101` | A2_5000_0101 *(label)* | S>C | unknown | Purpose unknown. Handler/builder located (see refs); debug strings:  | decompiled-source/a2-2moons-2007/dekaron_004e0000.c:10753<br>decompiled-source/a2-2moons-2007/dekaron_004e0000.c:10948 | located_only |
