import { Messenger } from '../events/text.js';

/** Show each host-clock Party War cue once, even though snapshots repeat it. */
export function createSharedEventAnnouncer(game, ui, banners, data) {
  const seen = new Set();
  const speaker = new Messenger(game, {
    notice: text => ui.notice(text),
    banner: (id, ms) => banners.show(id, ms),
  });
  return {
    consume(rows) {
      for (const row of rows || []) {
        if (!['deadFront', 'iceCastle'].includes(row.mode)) continue;
        const key = `${row.mode}:${row.cycle}:${row.at}:${row.cate}:${row.code}`;
        if (seen.has(key)) continue;
        const file = row.mode === 'deadFront' ? 'stringtable_partywar.txt' : 'stringtable_partywar2.txt';
        const entry = data.str(file, row.cate, row.code);
        if (!entry) continue;
        seen.add(key);
        if (seen.size > 128) seen.delete(seen.values().next().value);
        speaker.say(entry);
        // The original clock strings have no sound directive. This is the
        // shipped sound.json system[11] "Message" alert.
        const sound = game.audio?.S?.system?.['11']?.sfx;
        if (sound?.length) game.audio.playAll(sound, { volume: 0.8 });
      }
    },
    update(dt) { banners.update(dt); },
    dispose() {
      for (const effect of banners.live || []) for (const part of effect.parts) part.el.remove();
      if (banners.live) banners.live.length = 0;
      seen.clear();
    },
  };
}
