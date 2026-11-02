# Folder 3 of 3: Opcodes + Decompiled Source

Scrubbed package layout:

| folder | contents |
|---|---|
| 1 | Join-only client (GameWindow.exe) that connects to a hosted world |
| 2 | Dashboard: hosting and joining (runs the servers, hosts, joins) |
| **3** | **This folder**: every opcode explained, plus the source recovered by taking the client apart. That process is called **reverse engineering**. The output is **decompiled source** (Ghidra **decompilation** of the **disassembled** exe). |

## Contents
| path | what |
|---|---|
| `GLOBAL-OPCODES.md` / `.json` | Dekaron Global 0.0.1: **1,693** opcodes. 131 explained, 1,003 partial layout, 559 located only (handler/builder found, fields not read yet). All rows have a decompile file:line. |
| `A2-OPCODES.md` / `.json` | 2Moons Action 2 (2007): **613** opcodes (607 wire + 6 internal events). 55 explained, 352 partial layout, 206 located only. 609 have a file:line. 4 were found only on the wire against the HellSpider server (0x050a0000/02/06 NPC shop, 0x05260000). |
| `CROSSWALK.md` | A2 ⇄ Global: 391 identical, 84 same code but different (with how), 134 A2-only, 1,218 Global-only. Also covers header/cipher/session and wire-verified corrections. |
| `A2-WORLD-CRASH.md` | Root cause of the Loa Castle crash (confirmed by crash dump and capture). |
| `a2-crash-fix/` | Spawn-file fix scripts (`make_staged.py`, `apply.sh`, `revert.sh`, `staged/REPORT.json`). No game data is included: run `python make_staged.py SERVER_DIR CLIENT_MONSTER_CSV` with your own A2 server folder and your own client monster.csv to build `staged/`. **Not applied.** |
| `decompiled-source/global-0.0.1/` | `decompiled-named.c` (3,308,528 lines; same file as the 32-bit-main FINAL build, SHA-256 a6fafa3b…), `names.csv`, `WIRING-MAP.md`. Scrubbed, line-preserving. |
| `decompiled-source/a2-2moons-2007/` | `dekaron_XXXXXXXX.c` (Ghidra output split per 64 KB of address space), `exports/` (opcodes.tsv, opmap.json, sendops.json, functions.csv, strings, xrefs), `WIRING-MAP.md`. |
| `tools/scrub-decompile.js` | Line-preserving scrub (`node scrub-decompile.js IN OUT`). |
| `tools/internal/` | Build scripts that generated the docs. Removed from this release. |

## How to read a row
`opcode | name | dir | layout | what it does | ref | status`
- **opcode** = (category << 16) | code. Even code = request, odd = reply. Low byte with bit 0x80 set = unreliable (no ACK).
- **layout** offsets are from the start of the packet. The 16-byte header (+0 CRC, +4 u16 seq, +6 u16 length, +8 u32 tick, +0xC u32 opcode, big-endian) comes first, so the body starts at +0x10. Fields nobody has decoded are written as `unknown`, with the bytes seen.
- **evidence**: `decompile` (read from the decompile), `wire` (seen in a real capture), `server-ref` (server data files), `bridge-43.3.0` (notes from the 43.3.0 engine bridge, a different build; treat as a hint). Generated names are flagged as labels, not real names.
- **status**: explained = meaning and layout known; partial_layout = offsets/types known, meaning partly; located_only = function found, fields not decoded; wire_only = seen on the wire, not found in the decompile map.

## Scrub list (done / still to do before release)
| item | state |
|---|---|
| Internal work-folder names, VERIFY/run notes, dates in `decompiled-named.c` and `names.csv` (1,994 + 1,993 lines) | done (line-preserving, so refs still match) |
| Absolute box/PC paths in WIRING-MAPs | done |
| Opcode docs | relative paths only; no IPs, account keys, passwords or user numbers. Wire samples only for world packets. |
| `tools/internal/` | done (not included) |
| Packet captures, decoded pcaps, crash dumps, screenshots, test-account files, agent transcripts, logs, system IDs | not included in this folder; keep them out of all 3 folders |
| `a2-crash-fix/make_staged.py` | takes the server dir as an argument (no baked-in path) |
| Game data (client monster/npc tables, server spawn CSVs) | removed from this release (engine only); the scripts rebuild them from your own files |
