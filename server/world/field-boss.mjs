// Field Boss host (step 57): Saturday 23:00-23:20 on public map 533 (Mitera).
// Evidence: share/fieldboss/config.csv + summonsmonster.csv; dungeons.json fieldBosses/fieldBossSummons;
// client FieldBossRun (src/systems/events/fieldboss.js). Public-field spawn pattern mirrors ox-quiz.mjs
// (scene.monsters.set on an existing or loaded public scene). Tick from events.mjs tickEvents.
// Lane 64: Noty_1..5 (121-125) are not broadcast and no special loot is added (no source; FIELD_BOSS_DECISIONS).
import { randomUUID } from 'node:crypto';
import {
  fieldBossConfig,
  fieldBossSummons,
  fieldBossWindow,
  fieldBossDurationSec,
  fieldBossSummonCount,
  FIELD_BOSS_MAP_STRINGS,
  FIELD_BOSS_ENERGY,
} from '../../src/systems/events/fieldboss-rules.js';
import { plain } from '../../src/systems/events/text.js';

const TAG = 'fieldboss';

function cfgOf(world) {
  return fieldBossConfig(world.data?.eventData?.modes, world.data?.dungeonCatalog?.fieldBosses);
}

function summonsOf(world) {
  return fieldBossSummons(world.data?.eventData?.modes, world.data?.dungeonCatalog?.fieldBossSummons, 1);
}

function mapText(world, map, code) {
  return plain(world.data?.eventData?.mapTxt?.(map, code) || '').trim();
}

function say(world, run, code) {
  if (run.said.has(code)) return;
  run.said.add(code);
  const text = mapText(world, run.map, code);
  if (!text) return;
  world.emit(run.map, { type: 'event:message', text, channel: run.channel, instanceId: null });
}

/** Find or load the public Field Boss scene (map 533, channel from config default 0). */
async function ensureScene(world, map, channel = 0) {
  for (const s of world.maps.values()) {
    if (s.index === map && !s.instanceId && (s.channel ?? 0) === channel) return s;
  }
  if (typeof world.map === 'function') return world.map(map, null, channel);
  return null;
}

function placeNear(scene, x, z) {
  if (typeof scene.nearest === 'function') {
    const at = scene.nearest(x, z);
    if (at) return at;
  }
  return { x, z };
}

function spawnMonster(world, scene, run, { monsterIndex, x, z, role }) {
  const def = world.data.monsterDef?.(monsterIndex);
  if (!def) return null;
  const at = placeNear(scene, x, z);
  const id = `${TAG}:${run.id}:${role}:${randomUUID()}`;
  const m = {
    id,
    map: run.map,
    channel: run.channel,
    instanceId: null,
    monsterIndex,
    name: def.name,
    x: at.x,
    z: at.z,
    hp: def.hp,
    maxHp: def.hp,
    home: { x: at.x, z: at.z },
    dead: false,
    targetId: null,
    attackAt: 0,
    respawnAt: Infinity,
    respawnSec: Infinity,
    def: { ...def },
    fieldBoss: { runId: run.id, role },
  };
  scene.monsters.set(id, m);
  run.spawned.add(id);
  return m;
}

async function beginRun(world, cfg, window) {
  const channel = 0;
  const scene = await ensureScene(world, cfg.map, channel);
  if (!scene?.monsters) return null;
  const run = {
    id: randomUUID(),
    map: cfg.map,
    channel,
    phase: 'fight',
    startedAt: window.startAt,
    endAt: window.endAt,
    durationSec: fieldBossDurationSec(cfg),
    bossId: null,
    spawned: new Set(),
    sumT: new Map(),
    said: new Set(),
    energyMsgs: new Set(),
    purified: false,
    scene,
  };
  const boss = spawnMonster(world, scene, run, {
    monsterIndex: cfg.monster,
    x: cfg.x + 0.5,
    z: cfg.y + 0.5,
    role: 'boss',
  });
  if (!boss) return null;
  run.bossId = boss.id;
  cfg.slaves.forEach((monsterIndex, i) => {
    const a = i * 2.1;
    spawnMonster(world, scene, run, {
      monsterIndex,
      x: cfg.x + 0.5 + Math.cos(a) * 4,
      z: cfg.y + 0.5 + Math.sin(a) * 4,
      role: 'slave',
    });
  });
  world.fieldBoss = run;
  say(world, run, FIELD_BOSS_MAP_STRINGS.start);
  return run;
}

function clearRun(world, run) {
  const scene = run.scene;
  if (scene?.monsters) {
    for (const id of run.spawned) scene.monsters.delete(id);
  }
  run.spawned.clear();
  if (world.fieldBoss === run) world.fieldBoss = null;
}

function tickSummons(world, run) {
  const scene = run.scene;
  const boss = scene?.monsters?.get(run.bossId);
  if (!boss || boss.dead) return;
  const now = world.now();
  const rows = summonsOf(world);
  for (const s of rows) {
    const k = `${s.group}:${s.no}`;
    const nextAt = run.sumT.get(k) ?? (now + (s.tickMs || 15000));
    if (now < nextAt) continue;
    run.sumT.set(k, now + (s.tickMs || 15000));
    let alive = 0;
    for (const id of run.spawned) {
      const m = scene.monsters.get(id);
      if (m && !m.dead && m.fieldBoss?.role === `sum_${k}`) alive += 1;
    }
    const n = fieldBossSummonCount(s, alive);
    if (n <= 0) continue;
    const [r0, r1] = s.range || [5, 48];
    for (let i = 0; i < n; i++) {
      const a = (world.random?.() ?? Math.random()) * Math.PI * 2;
      const d = r0 + (world.random?.() ?? Math.random()) * Math.max(0, Math.min(r1, 48) - r0);
      spawnMonster(world, scene, run, {
        monsterIndex: s.monster,
        x: boss.x + Math.cos(a) * d,
        z: boss.z + Math.sin(a) * d,
        role: `sum_${k}`,
      });
    }
  }
}

function tickEnergy(world, run) {
  const elapsed = (world.now() - run.startedAt) / 1000;
  const f = Math.min(1, Math.max(0, elapsed / run.durationSec));
  for (const [p, code] of FIELD_BOSS_ENERGY) {
    if (f >= p && !run.energyMsgs.has(code)) {
      run.energyMsgs.add(code);
      say(world, run, code);
    }
  }
}

function checkPurified(world, run) {
  const boss = run.scene?.monsters?.get(run.bossId);
  if (!boss || !boss.dead || run.purified) return;
  run.purified = true;
  run.phase = 'done';
  say(world, run, FIELD_BOSS_MAP_STRINGS.purified);
  // Clear summons only (client FieldBossRun clears sum_* groups).
  for (const id of [...run.spawned]) {
    const m = run.scene.monsters.get(id);
    if (m?.fieldBoss?.role?.startsWith('sum_')) {
      run.scene.monsters.delete(id);
      run.spawned.delete(id);
    }
  }
  run.closeAt = world.now() + 60_000;
}

/**
 * Tick Field Boss from tickEvents. Safe when data is missing (no-op).
 * Pre-window five-minute cue (map string 120) fires once when now is within 5 min of start.
 */
export async function tickFieldBoss(world) {
  const cfg = cfgOf(world);
  if (!cfg) return;
  const now = world.now();
  const window = fieldBossWindow(cfg, now);
  let run = world.fieldBoss || null;

  // Five minutes before start (client FieldBossRun startIn > 60 => say 120).
  if (window.phase === 'closed' && window.nextStartAt != null) {
    const until = window.nextStartAt - now;
    if (until > 0 && until <= 5 * 60_000) {
      if (!world._fieldBossPreSaid) {
        world._fieldBossPreSaid = true;
        const text = mapText(world, cfg.map, FIELD_BOSS_MAP_STRINGS.fiveMin);
        if (text) world.emit(cfg.map, { type: 'event:message', text, channel: 0, instanceId: null });
      }
    } else if (until > 5 * 60_000) {
      world._fieldBossPreSaid = false;
    }
  }

  if (window.phase === 'active' && !run) {
    run = await beginRun(world, cfg, window);
  }
  if (!run) return;

  if (run.phase === 'fight') {
    tickSummons(world, run);
    tickEnergy(world, run);
    checkPurified(world, run);
  }

  if (run.phase === 'fight' && now >= run.endAt) {
    say(world, run, FIELD_BOSS_MAP_STRINGS.timeUp);
    clearRun(world, run);
    return;
  }

  if (run.phase === 'done' && run.closeAt && now >= run.closeAt) {
    clearRun(world, run);
  }
}

export function fieldBossSnapshot(world) {
  const run = world.fieldBoss;
  if (!run) return null;
  const remainingMs = Math.max(0, (run.phase === 'fight' ? run.endAt : (run.closeAt || run.endAt)) - world.now());
  const elapsed = Math.max(0, world.now() - run.startedAt);
  const energy = Math.min(100, Math.floor((elapsed / 1000 / run.durationSec) * 100));
  return {
    id: run.id,
    map: run.map,
    phase: run.phase,
    remainingMs,
    energy: run.phase === 'fight' ? energy : null,
    purified: !!run.purified,
  };
}
