// Live wiring for Global dungeon map-event cinematics (Lane 49).
// Client runner: src/systems/events/map-event-runner.js (Global Dungeon::Reference).
// Trigger: Global server->client opcode 0x05260021 (u32 index at +0x10). Older server-ref
// DekaronServer_A11.exe has no 0x05260021 (opcodes stop ~0x05260012), so the binary packet
// is not emulated here. 4.2.0 uses the same high-level event bus as dungeon:sound:
//   server emits { type:'dungeon:map-event', index }
//   client starts the runner; skip sends { type:'dungeon', operation:'map-event-skip' }.
// Lane 64: indices 1-5 = map 706 Hidden Mansion of Kastotica (Global data; map-event-rules.js MAP_EVENT_BINDING).
// Lane 64: 'dungeon:map-event-end' follows Global 0x05260023 (end requested only while actions are pending,
// End runs on the next tick); fade/camera/move payloads carry Global owner semantics (see map-event-runner.js).

import { loadEventData } from '../events/data.js';
import { normalizeMapEventRows } from '../events/map-event-rules.js';
import {
  createMapEventRunner, MAP_EVENT_OPCODES, MAP_EVENT_NATIVE, MAP_EVENT_RUNNER_UNRESOLVED,
} from '../events/map-event-runner.js';
import { registerEventActors } from './event-actors.js';
import { createFadeWnd } from '../events/map-event-presentation.js';

function rowsFrom(data) {
  const src = data?.modes?.mapEvent || data?.ev?.modes?.mapEvent || null;
  return normalizeMapEventRows(src);
}

function makeHooks(game, network, local) {
  const emit = (kind, detail) => { try { game.events?.emit?.(kind, detail); } catch { /* display only */ } };
  return {
    spawnActor(a) {
      // Global Enter allocates a client-local actor ("Dungeon_Event_Enter.cpp"). Not networked.
      const def = game.data?.monster?.(a.monster) || game.data?.monsters?.monsters?.[a.monster];
      if (!def) { emit('map-event:spawn-missing', a); return null; }
      const id = `mapevent:${a.id}:${a.monster}`;
      const actor = {
        id, networkId: id, mapEventId: a.id, monsterIndex: a.monster, name: def.name || `Monster ${a.monster}`,
        x: a.x, z: a.y, dirRad: a.dirRad, facing: a.facing, dir: a.dir || null, cellX: a.cellX, cellY: a.cellY,
        kind: 'map-event', presentation: true, dead: false,
      };
      local.actors.set(id, actor);
      emit('map-event:spawn', { actor, row: a });
      return id;
    },
    removeActor(handle) {
      const actor = local.actors.get(handle);
      local.actors.delete(handle);
      if (actor) emit('map-event:remove', { actor });
    },
    resolveActor(id) {
      for (const [handle, actor] of local.actors) if (actor.mapEventId === id) return handle;
      // BrickAction resolves by brick id; existing dungeon bricks use brick:<instance>:<uid>.
      return network.dungeonActor?.(`brick:${id}`) ? `brick:${id}` : network.eventActor?.(id) || null;
    },
    actorPos(handle) {
      const a = local.actors.get(handle);
      if (a) return { x: a.x, y: a.z };
      const brick = typeof handle === 'string' && handle.startsWith('brick:') ? network.dungeonActor?.(handle) : null;
      if (brick) return { x: brick.x, y: brick.z ?? brick.y };
      return { x: 0, y: 0 };
    },
    actorDir(handle) {
      // Global IActor slot 0x58: direction vector (-sin, -cos) of the actor facing.
      const a = local.actors.get(handle);
      return a?.dir || null;
    },
    cameraParams() {
      // CameraImpl f0..f2 snapshot for SetCamera mode 0 restore; only when the 4.2.0 camera exposes it.
      const p = (game.cam?.mapEventParams ? game.cam.mapEventParams() : game.camera?.mapEventParams?.());
      return Array.isArray(p) ? p : null;
    },
    moveActor(m) {
      const a = local.actors.get(m.handle);
      if (a && m.target) { a.x = m.target.x; a.z = m.target.y; }
      emit('map-event:move', m);
    },
    setAction(m) { emit('map-event:action', m); },
    stopAction(m) { emit('map-event:stop', m); },
    talk(m) {
      const text = local.string?.(m.text?.category, m.text?.index) || '';
      if (text) game.chat?.system?.(text) || game.dungeons?.notice?.(text) || game.eventsSystem?.notice?.(text);
      emit('map-event:talk', { ...m, text });
    },
    dialog(m) {
      const text = local.string?.(m.text?.category, m.text?.index) || '';
      emit('map-event:dialog', { ...m, text });
    },
    // Lane 64 render consumers: SetCamera -> 4.2.0 FollowCamera (game.cam, the CameraImpl owner); FadeInOut -> FadeWnd overlay.
    camera(m) { try { game.cam?.applyMapEvent?.(m); } catch { /* display only */ } emit('map-event:camera', m); },
    fade(m) { local.fade?.fade(m.mode, m.duration); emit('map-event:fade', m); },
    fadeHide(m) { local.fade?.hide(); emit('map-event:fade-hide', m); },
    showAllUI(on) {
      // Global ShowAllUI: id 1 show, id 0 hide. Prefer the shared GM hideUI surface when present.
      if (game.gm?.hideUI) game.gm.hideUI(!on);
      emit('map-event:ui', { show: on });
    },
    brickAction(m) { emit('map-event:brick', m); },
    onStart(m) { emit('map-event:start', m); },
    enterPresentation(m) { emit('map-event:presentation', { enter: true, ...m }); },
    endPresentation() {
      // Global Reference End (FUN_7ff6714e4020): fade owner slot 0xf0 (hide), camera override +0xa8 = 0, drift flags +0xd0 = 0.
      local.fade?.hide();
      try { game.cam?.endMapEvent?.(); } catch { /* display only */ }
      emit('map-event:presentation', { enter: false });
    },
    sendSkip(bytes) {
      // 4.2.0 action bus (not binary 0x05260022). Payload size is recorded for parity checks.
      void Promise.resolve(network.action?.('mapEvent', { operation: 'skip', opcode: MAP_EVENT_OPCODES.SKIP, headerBytes: bytes?.length || 16 }))
        .then((r) => { if (r?.end) local.serverStop?.(); }) // host answers with the 0x05260023 end (Global client)
        .catch(() => {});
    },
  };
}

/** Install the map-event runner on the shared dungeon network bridge. */
export async function installMapEvent(game, network) {
  const data = await loadEventData();
  const local = {
    actors: new Map(),
    fade: createFadeWnd({ doc: globalThis.document }),
    string(cate, code) {
      // Talk uses UIString(category,index). events_text has no cate 3000; leave empty when missing (do not invent).
      for (const file of Object.keys(data.text?.tables || {})) {
        const t = data.txt(file, cate, code, '');
        if (t) return t;
      }
      return '';
    },
  };
  let clock = 0;
  const runner = createMapEventRunner({
    rows: rowsFrom(data),
    now: () => clock,
    hooks: makeHooks(game, network, local),
  });
  local.serverStop = () => runner.serverStop();
  const unregister = registerEventActors(network, 'map-event', (id) => {
    const a = local.actors.get(id);
    return a || null;
  }, 5);

  const previousEvent = network._event.bind(network);
  network._event = (event) => {
    if (event?.type === 'dungeon:map-event') {
      const index = Number(event.index);
      if (Number.isFinite(index)) runner.start(index);
      return;
    }
    if (event?.type === 'dungeon:map-event-end') {
      runner.serverStop();
      return;
    }
    previousEvent(event);
  };

  const bridge = {
    runner,
    opcodes: MAP_EVENT_OPCODES,
    native: MAP_EVENT_NATIVE,
    unresolved: MAP_EVENT_RUNNER_UNRESOLVED,
    start(index) { return runner.start(index); },
    skip() { return runner.skip(); },
    end() { runner.end(); },
    fade: local.fade,
    update(dt) {
      local.fade.update(Math.max(0, Number(dt) || 0) * 1000); // FadeWnd runs on its own frame clock, also after End
      if (!runner.playing) return;
      clock += Math.max(0, Number(dt) || 0) * 1000; // row.time is ms (Global Time::Provider slot 0x58)
      runner.tick();
    },
    dispose() {
      runner.end();
      unregister?.();
      local.actors.clear();
      local.fade.dispose();
      network._event = previousEvent;
    },
  };
  game.mapEvent = bridge;
  return bridge;
}
