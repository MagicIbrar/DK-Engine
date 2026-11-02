// 4.3.2 option "Login dance" (settings.loginDance, OFF by default). When on, the login hall seats the player's
// character in the throne instead of the hall figure, dims the hall BGM when the startup load reaches 100%, and 2 s
// later plays the user's OWN song (a local audio file the user picks; kept only in this browser's IndexedDB, never
// uploaded or bundled) while the character dances the choreography and sits back down at the end.
import { LoginDance, loadChoreography } from './login-dance.js';
import { hideHallFigure, addPurplePath, CHAIR } from './login-scene.js';

const DB = 'dekaron-login-dance', STORE = 'song';
function idb() { return new Promise((res, rej) => { const r = indexedDB.open(DB, 1); r.onupgradeneeded = () => r.result.createObjectStore(STORE); r.onsuccess = () => res(r.result); r.onerror = () => rej(r.error); }); }
export async function getSong() { try { const db = await idb(); return await new Promise(res => { const q = db.transaction(STORE).objectStore(STORE).get('file'); q.onsuccess = () => res(q.result || null); q.onerror = () => res(null); }); } catch { return null; } }
export async function setSong(file) { const db = await idb(); await new Promise((res, rej) => { const t = db.transaction(STORE, 'readwrite'); t.objectStore(STORE).put(file, 'file'); t.oncomplete = res; t.onerror = () => rej(t.error); }); }
/** Let the user pick their song (file input); stored locally. */
export function pickSong() {
  return new Promise(res => {
    const inp = Object.assign(document.createElement('input'), { type: 'file', accept: 'audio/*' });
    inp.onchange = async () => { const f = inp.files?.[0]; if (f) await setSong(f); res(f || null); };
    inp.click();
  });
}

export const loginDanceEnabled = settings => !!settings?.loginDance;      // default off

/**
 * Start the login dance on the login hall. Call after stage.loadWorld(LOGIN_MAP) resolved; call the returned
 * `loaded()` when the startup cover reaches 100% (finishPreload). Returns { loaded, dispose } or null when unavailable.
 */
export async function startLoginDance(fe, { classCode = 'SWD' } = {}) {
  const stage = fe.stage;
  try {
    const [{ FrontCharacter }] = await Promise.all([import('../character.js'), stage.data.loadClasses()]);
    const classDef = stage.data.classes.find(c => c.code === classCode) || stage.data.classes[0];
    const { choreo, beatmap } = await loadChoreography();
    const figure = hideHallFigure(stage.world, stage);
    const path = addPurplePath(stage);
    const actor = FrontCharacter.showcase(stage, classDef, { rest: 'idlePeace' });
    await actor.load();
    stage.addActor(actor);
    const music = () => fe.audio;
    const base = Number(fe.settings?.musicVolume ?? 0.5);
    let ramp = null;
    const dimBgm = (to, sec) => {
      const a = music(); if (!a?.setVolumes) return;
      const t0 = performance.now(), from = base;
      cancelAnimationFrame(ramp);
      const tick = () => { const k = Math.min(1, (performance.now() - t0) / (sec * 1000)); a.setVolumes({ music: from + (base * to - from) * k }); if (k < 1) ramp = requestAnimationFrame(tick); };
      tick();
    };
    const song = await getSong();
    const audio = song ? new Audio(URL.createObjectURL(song)) : null;
    if (audio) audio.volume = Math.max(0, Math.min(1, Number(fe.settings?.musicVolume ?? 0.5) * 1.6));
    let started = false;
    const dance = await new LoginDance({ stage, actor, choreo, beatmap, chair: CHAIR, dimBgm, songTime: () => (started && audio ? audio.currentTime : null) }).prepare();
    const off = stage.onFrame(() => { if (!started && dance.wantsSong && audio) { started = true; audio.play().catch(() => { started = false; }); } });
    return {
      dance,
      loaded: () => dance.loaded(),
      dispose() {
        off(); cancelAnimationFrame(ramp);
        if (audio) { audio.pause(); URL.revokeObjectURL(audio.src); }
        music()?.setVolumes?.({ music: base });
        dance.dispose(); stage.removeActor?.(actor); path.userData.off?.(); path.removeFromParent();
        figure?._danceOff?.(); if (figure?.inst?.object) figure.inst.object.traverse(c => c.layers.set(0));
      },
    };
  } catch (err) { console.warn('[login-dance] unavailable', err); return null; }
}

