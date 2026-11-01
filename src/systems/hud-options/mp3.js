// MP3 player (script/ui/game2/mp3player/ui_mp3playerwnd.txt, Mp_3 art), shown by the Sound tab's "MP3 Player" option.
//
// The client plays the music files of its own MP3 folder. Here the folder is `mp3/` inside the game data
// (data/unpacked/data/mp3, listed through /api/ls, served from /data/mp3/...); audio files dropped from the desktop
// onto the player are added to the list for the session. Controls, as the art names them (imagetable Mp_3):
//   prev #11 / play #21 / hold (pause) #31 / stop #41 / next #51 / list #61 / repeat mode #71 all, #81 one, #91 off /
//   minimise #101 (only the note button #151 stays) / close #111 (unchecks the option);
//   sld_play + probar_play = seek + progress (0..118), sld_volume + probar_volume = volume (0..35).
// While a song plays the game BGM is silenced and comes back when it stops (the client pauses its BGM stream).
import { listDir } from '../../engine/assets.js';
import { clamp, LS } from './util.js';

const LS_KEY = 'dekaron-solo:mp3:v1';
const AUDIO_EXT = /\.(mp3|ogg|wav|m4a|aac|flac|wma)$/i;

export function registerMp3Player(game, ctx) {
  const st = { list: [], index: -1, mode: 3, audio: null, playing: false, min: false, listOpen: true, volume: 0.8, ...(LS.load(LS_KEY, {}) || {}) };
  st.list = []; st.playing = false; st.index = -1;
  const save = () => LS.save(LS_KEY, { mode: st.mode, volume: st.volume, min: st.min, listOpen: st.listOpen });
  const audio = st.audio = new Audio();
  audio.preload = 'auto';
  audio.volume = st.volume;

  const bgm = (silence) => {
    if (silence) game.audio?.setVolumes?.({ music: 0, sfx: 1 });
    else ctx.effects?.applySound?.();
  };
  audio.addEventListener('play', () => { st.playing = true; bgm(true); paint(); });
  audio.addEventListener('pause', () => { st.playing = false; bgm(false); paint(); });
  audio.addEventListener('ended', () => {
    if (st.mode === 2) { audio.currentTime = 0; audio.play().catch(() => {}); return; }
    if (st.index + 1 < st.list.length) { playIndex(st.index + 1); return; }
    if (st.mode === 1 && st.list.length) { playIndex(0); return; }
    st.playing = false; bgm(false); paint();
  });

  let win = null;
  function paint() {
    if (!win) return;
    win.control('btn_mp3play').setVisible(!st.playing);
    win.control('btn_mp3pause').setVisible(st.playing);
    for (let m = 1; m <= 3; m++) win.control(`btn_playtype${m}`).setVisible(st.mode === m);
    const cur = st.list[st.index];
    win.control('lbl_mp3file_title').setText(cur ? cur.name.replace(AUDIO_EXT, '') : '');
    win.control('pan_mp3list').setVisible(st.listOpen && !st.min);
    win.control('pan_mp3back').setVisible(!st.min);
    win.control('btn_mp3note').setVisible(st.min);
    win.control('probar_volume').setGauge(st.volume);
    win.control('sld_volume').setValue(Math.round(st.volume * 35));
  }
  function fillList() {
    if (!win) return;
    const lb = win.control('list_mp3list');
    lb.setItems(st.list.map((s, i) => ({ text: `${i + 1}. ${s.name.replace(AUDIO_EXT, '')}`, data: i })));
    if (st.index >= 0) lb.select(st.index);
  }
  function playIndex(i) {
    const s = st.list[i];
    if (!s) return;
    st.index = i;
    audio.src = s.url;
    audio.play().catch(() => { st.playing = false; paint(); });
    fillList(); paint();
  }
  async function scan() {
    const found = [];
    try {
      const root = await listDir('');
      const dir = (root || []).find(e => e.dir && /^mp3$/i.test(e.name));
      if (dir) {
        for (const e of await listDir(dir.name)) if (!e.dir && AUDIO_EXT.test(e.name)) found.push({ name: e.name, url: `/data/${dir.name}/${encodeURIComponent(e.name)}` });
      }
    } catch { /* no folder */ }
    const dropped = st.list.filter(s => s.local);
    st.list = [...found.sort((a, b) => a.name.localeCompare(b.name)), ...dropped];
    fillList(); paint();
  }

  game.uiwin.registerWindow('mp3player', {
    script: 'game2/mp3player/ui_mp3playerwnd.txt', escClose: false,
    create(w) {
      win = w;
      w.control('btn_mp3play').onClick(() => {
        if (st.index < 0 && st.list.length) { playIndex(0); return; }
        if (st.index >= 0) audio.play().catch(() => {});
      });
      w.control('btn_mp3pause').onClick(() => audio.pause());
      w.control('btn_mp3stop').onClick(() => { audio.pause(); try { audio.currentTime = 0; } catch { /* no source */ } paint(); });
      w.control('btn_mp3prev').onClick(() => { if (st.list.length) playIndex(st.index > 0 ? st.index - 1 : (st.mode === 1 ? st.list.length - 1 : 0)); });
      w.control('btn_mp3next').onClick(() => { if (st.list.length) playIndex(st.index + 1 < st.list.length ? st.index + 1 : (st.mode === 1 ? 0 : st.list.length - 1)); });
      for (let m = 1; m <= 3; m++) w.control(`btn_playtype${m}`).onClick(() => { st.mode = m % 3 + 1; save(); paint(); });
      w.control('btn_mp3list').onClick(() => { st.listOpen = !st.listOpen; save(); paint(); });
      w.control('btn_listclose').onClick(() => { st.listOpen = false; save(); paint(); });
      w.control('btn_mp3min').onClick(() => { st.min = true; save(); paint(); });
      w.control('btn_mp3note').onClick(() => { st.min = false; save(); paint(); });
      w.control('btn_mp3close').onClick(() => ctx.options.set({ mp3: false }));
      const lb = w.control('list_mp3list');
      lb.on('dblclick', () => { const i = lb.getSelected(); if (i >= 0) playIndex(i); });
      const seek = w.control('sld_play');
      seek.setRange(0, 118);
      seek.on('commit', v => { if (audio.duration > 0) audio.currentTime = clamp(v / 118, 0, 1) * audio.duration; });
      const vol = w.control('sld_volume');
      vol.setRange(0, 35);
      vol.on('change', v => { st.volume = clamp(v / 35, 0, 1); audio.volume = st.volume; w.control('probar_volume').setGauge(st.volume); });
      vol.on('commit', () => save());
      // files dropped from the desktop join the list for this session
      w.el.addEventListener('dragover', (e) => { if (e.dataTransfer?.types?.includes('Files')) e.preventDefault(); });
      w.el.addEventListener('drop', (e) => {
        const files = [...(e.dataTransfer?.files || [])].filter(f => AUDIO_EXT.test(f.name) || /^audio\//.test(f.type));
        if (!files.length) return;
        e.preventDefault();
        for (const f of files) st.list.push({ name: f.name, url: URL.createObjectURL(f), local: true });
        fillList(); paint();
      });
      // Construction is also used by entry preloading. Scan media only when
      // the player opens this panel (onOpen below), not during preparation.
      paint();
    },
    onOpen() { scan(); paint(); },
    onClose() { audio.pause(); },
    update(w) {
      if (!st.playing || !(audio.duration > 0)) return;
      const f = clamp(audio.currentTime / audio.duration, 0, 1);
      w.control('probar_play').setGauge(f);
      const s = w.control('sld_play');
      if (!s.thumb?.pressed) s.setValue(Math.round(f * 118));
    },
  });

  const sync = () => { if (ctx.options.get('mp3')) game.uiwin.open('mp3player'); else if (game.uiwin.isOpen('mp3player')) game.uiwin.close('mp3player'); };
  ctx.options.on('change', (patch) => { if ('mp3' in patch) sync(); });
  sync();
  return st;
}
