# Login dance (option, OFF by default)

Options → "Login dance (your own song, picked below)" + "Choose login dance song…".
The song is a user-chosen local file kept in this browser's IndexedDB (`dekaron-login-dance`); nothing is bundled or uploaded.

## owner timing (required)
1. Character starts **seated** on the throne (game `mal_chair_sit` pose).
2. Login/menu loads to **100%**.
3. **2 seconds** later he **stands up**.
4. **Then** the song starts; he dances to the user's video/MP3 (choreography on `beatmap.json`).
5. When the dance ends he **sits back down**.

## Clips per move
| Move / phase | Source |
|---|---|
| Seated (start + end) | game `anim/object/etc/mal_chair_sit.anim`, Bip01 rebased by yaw; seat from MAL_Login_Sit .mol (255.847, 19.03, 271.63, scale 1.36) |
| Stand up (PRE-SONG) | wall-clock `standUpSeconds` (~1.85 s) crossfade mal_chair_sit → `swd_non_stand_01.anim` AFTER load 100% + `preSongSeconds` |
| Sit down | song-beat `sitDown` section at end of choreography |
| Standing base / moves | `swd_non_stand_01` + custom keyframes in `moves.js` (wiggle, shuffle, strut, chestPose) |

No game dance emote (`*_emt_dance`) is used.

## Data
- `beatmap.json`: beat times (~130 BPM; analyzed from the owner's Sexy and I Know It class track when available).
- `choreography.json`: song sections. **Moves still PLACEHOLDER** until reference clip is watched and recreated move-by-move.
- Live preview: `node tools/dance-preview/serve.mjs` → http://127.0.0.1:8765/
