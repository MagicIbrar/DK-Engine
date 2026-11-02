# dekaron.exe (2Moons Open Beta / Action 2, PE build <date>): wiring map

Source image: `<path> It was rebuilt from a memory dump. Raw offset = RVA, and VA = 0x400000 + RVA.
The originals were not modified (sha256 062a7c58…d21d).
Ghidra project: `work/projcopy` (canonical, fixed). `work/projcopy2` is a read-only copy used by `work/dc.sh`.
Decompiled C: `src/dekaron_XXXXXXXX.c`, one file per 64 KB range, 90 files. 42,061 functions decompiled, 1 failed.
Tables: `exports/functions.csv` (42,212 funcs), `imports.csv`, `strings.tsv`, `string_xrefs.tsv`, `call_xrefs.tsv`, `opcodes.tsv`, `opmap.json`, `sendops.json`, `vtables.json`/`rtti_names.txt` (in `work/`).
Anything marked **INFERRED** is reasoned from code shape rather than seen on the wire. No game traffic has been captured yet (see §8).

## 0. Unpacking (for reference)
- Packer: ASProtect-style. The real OEP is **0x800a62** (VC7.1 WinMainCRTStartup). The stolen bytes were restored as `6A 60 68 E8 5A A0 00`.
- WinMain is **0x401130** (called at 0x800be1). The app init that also starts GameGuard is FUN_00402f30.
- IAT: 0x99c000–0x99c4ec, 305 imports from 11 DLLs, rebuilt into a new `.idata2` section (RVA 0x786000).
- The image runs under Ghidra/static tools only. It is not meant to be executed. The `client-nogg/run_nogg.py` is the runtime path.

## 1. Network layer

### 1.1 Socket setup
| What | Where |
|---|---|
| TCP socket class | `Network::Socket::TCPAsyncSelect`. socket()+WSAAsyncSelect at 0x44582a/0x44583e (window-message driven) |
| Connect | FUN_00444710: WSAConnect at 0x444763, non-blocking. WSAEWOULDBLOCK (0x2733) puts the socket on a pending list. On failure it posts internal event 0x10004 |
| Connect timeout | FUN_00444510: **7000 ms**. On timeout it posts 0x10004 |
| Send | wrapper FUN_00444b50 (WSASend) |
| Recv | wrapper FUN_00444c10 (WSARecv) |
| Second, blocking socket path | 0x7ced20 (gethostbyname/connect/send 0x7cee91/recv 0x7cbcd7/select). **INFERRED**: aux/HTTP (patch/web), not the game protocol |
| GameGuard's own sockets | send 0x819980 / WSASend 0x81993f inside the GG lib (0x813000–0x81c000) |

### 1.2 Session object graph
FUN_004441a0 builds the session Provider (vtable 0x99e94c). Its fields:
- [8] = core (FUN_00447cf0, 0x78 bytes)
- [3] = Cipher::UDP (0x449700)
- [2] = Cipher::TCP (0x4492e0, vtable 0x99eb48)
- [7] = Dissembler (0x447fc0)
- [6] = Receiver (0x448910)
- [5] = Sender/Handler (0x4483f0)
- [4] = Assembler (0x4478c0)

Session states:
- **Closed**
- **Connecting**: vtable 0x99e858. Enter = FUN_00443070. Recv = FUN_00443430
- **Established**: vtable 0x99e8bc. Enter = 0x443a70. Tick = 0x443ae0. Recv = 0x443b40 → FUN_00443f70

The client's internal event queues are DAT_00b5a68c (network→app) and DAT_00b5a71c (app→network controller).

### 1.3 Packet header (16 bytes, every packet)
| off | size | meaning |
|---|---|---|
| +0x00 | u32 | CRC = bswap(~CRC32) over bytes [4 .. len-1] of the **ciphertext**. Table at 0x99ec78 (standard CRC-32) |
| +0x04 | u16 | **sequence number**. Used by the reliable layer (Receiver FUN_004486f0) to order and ACK, with 16-bit wraparound compare (0x7fff window) |
| +0x06 | u16 | total length including the header. Max 0x400 (every packet buffer is `new(0x400)`) |
| +0x08 | u32 | context / session-serial. Login packets put a param there. Usually 0 |
| +0x0c | u32 | **opcode** = (category << 16) \| code. Read by `Packet::GetOpcode` FUN_00424500 (`mov eax,[ecx+0xc]`). FUN_004244e0(cat) compares the u16 at +0x0e |

- All header fields go on the wire **big-endian**: FUN_00449f30 swaps host→net on send, FUN_00449fc0 swaps net→host on recv.
- Payload starts at +0x10.
- Session-control (category 0x0002) payload ints are byte-swapped explicitly (big-endian).
- Game payloads (category ≥0x0200) are read raw. **INFERRED**: those are little-endian on the wire.
- **Reliability flag:** FUN_0044a050 returns `(byte at +0x0c & 0x80) == 0`, i.e. bit 7 of the low byte of the opcode in host order.
  - Bit clear → reliable packet. The client sends an ACK `0x00020005 {u16 seq}` (FUN_004485f0) and delivers in order.
  - Bit set (e.g. 0x2008x) → unreliable/control.

### 1.4 Encryption (Cipher::TCP)
Vtable 0x99eb48: 0x449550 dtor, 0x449250 **encrypt**, 0x4493c0 **decrypt**, 0x449210 reset, 0x449390, 0x449240, 0x449370.
```
for i in 4 .. len-1:  c[i] = p[i] ^ (T[i & 0xff] & 0xff) ^ k0 ^ k1     (T = dword table at 0x99ec78, i.e. CRC table low bytes)
then CRC over c[4..len-1] -> header +0 (bswap(~crc))
```
- The 2-byte key (k0,k1) lives at session+0xc (getter 0x447cc0, setter 0x447cd0). It is **0/0 until the handshake**.
- The setter is called from FUN_00443610 with `k0 = pkt[0x18], k1 = pkt[0x1c]` from server packet 0x20081 (see §2).
- So the first packet each side sends (0x20080) is effectively XORed with the table only.
- Decrypt: decrypt the first 16 bytes, swap the header, check length ≤0x400, decrypt the rest, then verify the CRC.

### 1.5 Opcode dispatch
- There is no single table. Every NetHandler/PacketQueue Receiver is a function with `switch(GetOpcode())`.
- 124 dispatch sites call FUN_00424500/FUN_004244e0.
- Game-state events reach handlers as event type **0x50011** ("packet arrived"). Event 0x40001 is the timer tick (handlers use 20000 ms command timeouts).
- Extracted map (`exports/opcodes.tsv`, heuristic, from `tools/opmap.py` + `tools/sendops.py`): **634 distinct opcodes in 127 categories**.
  - 332 have a recognised receive handler.
  - 327 have a client-side builder (`mov [reg+0xc], imm32`).
  - Convention: **even code = client→server request, odd code = server→client reply**. This holds for every pair checked in the login and char-select ranges.
- Main receiver classes (RTTI PacketQueue Receivers):

| Receiver | addr | handles (sample) |
|---|---|---|
| Battle? | 0x5370a0 | 0x06000100–0x06000108 |
| Creature | 0x537ab0 | 0x05050010, 0x05060006, 0x05080001, 0x05090001/3/4, 0x05160001 |
| Effect | 0x5385c0 | 0x05190003, 0x051d0003 |
| **Enter** | 0x53a180 | 0x05020000, 0x05030002, 0x05040000, 0x05050000, 0x05190000, 0x051d0000 (spawn/appear packets: **INFERRED**) |
| Game | 0x53a4f0 / 0x53a7f0 | 0x050d0000 / 0x050d0004 |
| PC | 0x53bbf0 | 0x05070000, 0x05080000, 0x05090000 |
| Packet queueing filter | 0x4f46e0 / 0x4f4930 | queues 0x0504/0505/0507/0508/0509/0519 xxxx0000 while loading ("Packet Queueing") |
| Network::Game::Handler | 0x511720 | 0x05060008 → 0x511510 |

## 2. Session handshake (category 0x0001 = internal, 0x0002 = wire)
Internal events, **never on the wire**:

| opcode | meaning |
|---|---|
| 0x10000 | connect request: ip u32 @+0x14, port u16 @+0x18 |
| 0x10001 | disconnect |
| 0x10002 | connected/established |
| 0x10003 | closed |
| 0x10004 | connect failed |
| 0x10005 | latency stats: 4×u32 |

Wire sequence (verified in code):
1. TCP connects → Connecting.enter (FUN_00443070) resets seq/cipher and sends **C→S 0x00020080**, len 0x14: `u32 BE clientTick` (FUN_00442fd0).
2. **S→C 0x00020081** (only opcode accepted while Connecting, FUN_00443430 → FUN_00443610). Layout:
   - +0x10 u32 BE serverTime
   - +0x14 u32 BE echoed clientTick (RTT = now − this)
   - +0x18 u8 key0
   - +0x1c u8 key1
   - +0x20 64 bytes copied to session+0x35 (**INFERRED**: server/session id blob)
3. The client then:
   - sends **C→S 0x00020082** `u32 BE serverTime echo` (FUN_00443590);
   - switches to Established;
   - posts internal 0x10002 (FUN_00443500) and 0x10005.
4. Established:
   - **0x00020083** ping is sent when idle >20000 ms (FUN_00443d30, u32 BE tick). When the server sends 0x20083 the client replies **0x00020084** (FUN_00443db0).
   - **0x00020005** = ACK {u16 seq}.
   - **0x0002008a** S→C = GameGuard CS-auth query (4×u32; prints "Auth Server : %lu %lu %lu %lu" and calls GG FUN_00815860).
   - **0x0002008b** C→S = GG auth answer (len 0x50, 64-byte blob, FUN_00412790).

## 3. Login flow (category 0x0300 = login server; LoginList → 7880)
- UI: CLoginScene (vtable 0x9b3428) and LoginWnd (0x9d643c), via WrapTryLogin (0x71f929).
- Command object `Framework::ModelCenter::Connect::Login` (vtable 0x9b5c7c): Start = FUN_0050c710, OnEvent = FUN_0050cb00.
- Login server model FUN_004e14d0 reads LoginList ("Empty Login ServerList" if none).

**C→S login request.** The variant depends on the login-option type at cmd+0x3c, which comes from the cmdline/provider (§6). id/pw are NUL-terminated and truncated (strncpy-style with forced NUL).

| type | opcode | len | id @ (size) | pw @ (size) |
|---|---|---|---|---|
| default (region≠3) | **0x03000000** | 0x34 | +0x10 (17) | +0x21 (17) |
| 1 | 0x03000004 | 0x64 | +0x10 (17) | +0x21 (65) |
| 2 | 0x03000005 | 0x94 | +0x10 (65) | +0x51 (65) |
| 3 | 0x03000006 | 0xd4 | +0x10 (129) | +0x91 (65) |
| 4 | 0x03000008 | 0x74 | +0x10 (33) | +0x31 (65) |
| default, region==3 | 0x03000007 | 0x74 | +0x10 (33) | +0x31 (65) |

- For the plain `-i:user,pass` OB client, expect **0x03000000, 52 bytes**. Mapping types 1–4 to jnm@ / GCJ@ / acclaim@ prefixes is **INFERRED**.

**S→C 0x03000001 login ack** (FUN_0050c540):

| off | type | meaning |
|---|---|---|
| +0x10 | u32 | account/user no → model+0x54 |
| +0x14 | i32 | result. **0 = OK**. Otherwise error code (shown as -code, 600 = "login fail" UI) |
| +0x18 | u32 | → model+0x58. **INFERRED**: session key / serial |
| +0x1c | char[] | NUL-terminated string. **INFERRED**: account name / billing tag |
| +0x2b | u8 | flag (1 = clear an option bit; region-dependent) |

Logout: **0x03000002** (len 0x10) → **0x03000003** {i32 result} (FUN_00509630/FUN_00509760).

Channel/server select:
- `ChannelSelectWnd` and `Framework::GameHandler::SelectChannel` (vtable 0x9f0488; 0x744220 dtor, 0x7441c0 stub).
- The channel model (0x4e0860/0x4e0830) reads channellist.csv.
- Picking a channel issues internal 0x10000 connect to the channel IP:port (7881). That runs the §2 handshake again on the new socket.

Then lock/check-in (category 0x0400 / 0x0301):
- **0x04000000** LOCK (FUN_0050b5c0, len 0x40): +0x10 u32 sessionServerId, +0x14 u32 serialKey, +0x18 string User NO.
  - Replies: 0x04000003 (lock ack start: i32 result, 3 flag bytes @+0x14..+0x16) and 0x04000002 (lock ack end: u32 @+0x10, flag @+0x14).
  - The names are from debug strings "LOCKACKSTART/END". Which handler goes with 0x02 vs 0x03 is from the switch in FUN_0050b800.
- **0x04000006** UNLOCK (len 0x10) → 0x04000007.
- **0x03010002** CHECKIN (FUN_00509a60, len 0x40): +0x10 serialKey, +0x14 sessionServerId, +0x18 char name (25), +0x31 char no/str. Reply 0x03010003 {i32 result}.
- **0x03010000** CHECKOUT (FUN_0050c040, len 0x2c, name @+0x10) → **0x03010001** {i32 result @+0x10, ..., u32 @+0x1c}. On success this pushes **SceneCharSelect**.

## 4. Character select (category 0x0206 / 0x0204 / 0x0302)
Dispatcher FUN_005035e0 (char-select scene) and FUN_0050b800.

| opcode | dir | meaning (handler) |
|---|---|---|
| **0x02060000** | C→S | request PC list, len 0x18, u32 @+0x10 from DAT_00b5ac1c (**INFERRED**: account no). Sent by FUN_004ffd40 |
| **0x02060001** | S→C | "receive pclist ack" begin (FUN_005001c0) |
| **0x02040000** | S→C | open one PC record: creates the PC object and parses it via vtbl+0x1c (FUN_00501ec0) |
| **0x02040001** / 0x02040016 / 0x0204001a | S→C | per-PC "suit" (equipment appearance) blob: bytes [0x18 .. len) (FUN_00500af0 / 0x500bb0 / 0x500c70) |
| **0x02060002** | S→C | per-PC name, string @+0x18 (FUN_00500d30) |
| **0x02060003** | S→C | end of list → build the UI: up to **6** slots `character_list_btn_%d`, `btn_create_char` (FUN_00502c10) |
| **0x03020000** | C→S | create character, len 0x2c: name @+0x10, +0x29 u8 (class), +0x2a u8 (slot/index) (FUN_004fd1c0) |
| **0x03020001** | S→C | create ack: i32 @+0x10, ≥0 OK. Errors -1, -2, -3, -11, -12 (FUN_004fc8b0) |
| **0x03020002** | C→S | delete character (FUN_006eb170) |
| **0x03020003** | S→C | delete ack: i32 result ("Destroy Character OK/Fail") (FUN_00500250) |

**INFERRED** minimal server order for an empty account: 0x02060001 → 0x02060003 (zero PCs) → the create button appears.

## 5. Enter world (**INFERRED**)
- After char select the client sends CHECKIN 0x03010002 to the game/channel server (session transfer by serialKey + sessionServerId), then LOCK 0x04000000.
- World spawn traffic arrives in category 0x05xx through the Enter receiver (0x53a180: 0x05020000, 0x05030002, 0x05040000, 0x05050000, 0x05190000, 0x051d0000).
- While the map loads, packets in 0x0504/0505/0507/0508/0509/0519 are buffered by the "Packet Queueing" filter (0x4f46e0).
- Exact order and payloads are not reversed yet. Use `exports/opcodes.tsv` and `src/` to follow the handlers.

## 6. Command line (FUN_00417340, LoginOption Provider vtable 0x99d890)
Seen by our emulated GetCommandLineA: `"…\dekaron.exe" ,preceding`.

| token | effect |
|---|---|
| `,preceding` | required launcher token; sets a local flag (without it the launcher path is taken) |
| `-i:user,pass` | auto-login id/pw (3-char prefix compare) |
| `-testsvr` | obj+0x48 = 1 (test server) |
| `15` / `18` | obj+4 = 0 / 1 (**INFERRED**: age-rating / region) |
| `jnm@`, `GCJ@` (4-char), `acclaim@` (8-char) | id prefixes selecting the login type (feeds Login cmd+0x3c → §3 table; mapping **INFERRED**) |

## 7. Data loaders
- **Pack:** `data/data.hd` + `data/data.pak` (strings 0x99e57c/0x99e58c). PackIO is initialised in FUN_00402f30.
- **CSV loader FUN_0050d550:** `Loginlist.csv` → DAT_00b5ac7c, `channellist.csv` → DAT_00b5ac78, `period.csv` → DAT_00b5ace0, plus `version.ini` (0x50d6e6). Parser objects are 0x81d3a0/0x81d550.
- **Columns:**
  - loginlist: `Group,LoginServer Index,IP,Port` (stock: <official login server IP>,7880)
  - channellist: `Group,Channel Index,IP,Port,Name` (stock: .143/.144/.145 : 7881)
- **Startpoint:** loader is under `Support\startpoint\flyweight\Container.cpp` (string 0x9ce2d0).

## 8. GameGuard (nProtect, statically linked, ~0x813000–0x81c000)
- **FUN_00815730** = InitNPGameMon wrapper:
  - Allocates the 0x1690-byte GG context into DAT_00b5cf2c.
  - Calls **FUN_00815ac0** (setup, call site 0x81581c).
  - Stores the result at ctx+0x10.
  - Its callers are 3 sites in FUN_00402f30 (0x403058/0x403068/0x4030a4), chosen by login-option state.
- FUN_00815ac0:
  - Returns **0x755 (NPGAMEMON_SUCCESS)** early if already initialised.
  - Otherwise builds `C:\Program Files\Acclaim\2Moons\GameGuard\` (npgl.erl), spawns GameMon (CreateProcess) and uses CryptEncrypt (0x815fee) / CryptDecrypt (0x81b84e).
  - Logs "InitNPGameMon: %lu" (0x815a7d).
- FUN_00815860 = CS-auth answer (from 0x2008a); FUN_00815710 = post-init (SetHwnd). **INFERRED**.
- **Bypass patch (INFERRED, already done in memory by the no-GG launcher):** make 0x815730 return 0x755 with ctx created. Make 0x815860 return 1, or have the server never send 0x2008a.

## 9. Cross-check against packet logs
- `<path>
  - `run1/2/3/5.pcap` and the head and tail of the live `run7.pcap` contain **no TCP 7880/7881 traffic** (only local VNC/CDP/HTTPS).
  - There are no `sniff_*.log` files.
  - The wine logs have none of the client's debug strings ("packet send %X", "LOGINCMD", "Receive Ping").
  - So the opcode map is **not yet wire-verified**.
- First wire test to run:
  - expect C→S 0x00020080 (20 bytes, XOR-table only, BE header) immediately after connect to 7880;
  - answer with 0x00020081;
  - expect 0x00020082, then 0x03000000 (52 bytes).
