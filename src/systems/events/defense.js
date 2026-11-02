// Guild War Hunting: "Braiken Castle Defense Battle" (map 707, share/guildwarhunting, maps[707] random call tables,
// stringtable_dungeon_22 #707). In Global it is a host session driven by the GM commands
// guildwarhunting_open|ready|start|finish [world index] (server/world/guild-war-hunting.mjs, shared play only).
// Lane 47: the solo run's invented begin/battle/call/end timers and server name were removed (no Global value),
// so there is no solo session: start() refuses.
import { EventRun } from './run.js';

export class DefenseRun extends EventRun {
  async start() {
    throw Object.assign(Error('Guild War Hunting runs on a shared host through the GM commands guildwarhunting_open|ready|start|finish [world index].'), { status: 503 });
  }
}