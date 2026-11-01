// Window registration of the mounts system (docs/UIWIN.md): the casting bar, the main-menu buttons, the hotkeys, the
// NPC services, and the vehicle / pet / costume / wing windows (their own modules).
import { registerVehicleWindows } from './win-vehicle.js';
import { registerPetWindows } from './win-pet.js';
import { registerCostumeWindows } from './win-costume.js';
import { registerWingWindows } from './win-wing.js';
import { richify, kitOf, kitOpened, kitClosed, kitTick } from './ui-util.js';

/** NPC job types (share/creature/jobtypeconfig.csv) served by these windows. */
export const JOB = { WINGUPGRADE: 121, COSTUME_CYCLE: 124, VEHICLE_CYCLE: 133, WING_SHAPE_CHANGE: 146, PET_TRANSFORM: 163 };

export function registerWindows(sys) {
  const g = sys.game, mgr = g.uiwin;
  if (!mgr) return;
  // the summon casting bar: a transparent full-screen modal window whose panel pan_waittime is shown while casting
  mgr.registerWindow('mount_delay', {
    script: 'game2/vehicle/ui_delaywnd.txt', modal: true, escClose: true, remember: false, band: 'system',
    onClose: (win, result) => { if (sys._delay && result !== 'done') sys._finishDelay(false); },
  });

  // main menu (ui_mainmenuwnd.txt): btn_vehicle "이동" = ride / dismiss, btn_ride "이동수단강화" = vehicle management,
  // btn_petsummon = pet summon / unsummon, btn_petinven = pet management
  mgr.registerMenuButton('btn_vehicle', () => sys.riding.toggle());
  mgr.registerMenuButton('btn_petsummon', () => sys.pet.toggle());

  // hotkeys from the client's own help texts: "Ride summon/dismiss (J)", "(Ctrl + J) to evolve or crystalize the ride",
  // "Pet summon/unsummon ( T )", "Pet maintenance ( Y )" (stringtable_item 1667, stringtable_petui 63/64)
  const hk = (code, name, fn) => { try { mgr.registerHotkey(code, fn, { name }); } catch (err) { console.warn('[mounts] hotkey', code, err); } };
  hk('KeyJ', 'Summon Mount', () => sys.riding.toggle());
  hk('KeyT', 'Summon Pet', () => sys.pet.toggle());

  const before = new Set(mgr.registered());
  registerVehicleWindows(sys);
  registerPetWindows(sys);
  registerCostumeWindows(sys);
  registerWingWindows(sys);
  // the windows registered here: labels with client markup in their script text are drawn as rich text; windows
  // with item slots register bag items through the items system's kit (ui-util.js acceptItem): the bag opens beside
  // them (not beside the pet management window, which has its own pet inventory), right clicks in the bag offer the
  // item, and an NPC window closes when the character walks away from the NPC.
  const mine = new Set(mgr.registered().filter(n => !before.has(n)));
  sys.windowNames = [...mine];
  const NO_BAG = new Set(['petinfo', 'pet_name', 'pet_stackdivide', 'pet_callalarm', 'pet_preview', 'mount_delay']);
  mgr.on('create', (win) => {
    if (!mine.has(win.name)) return;
    richify(win);
    if (!NO_BAG.has(win.name)) kitOf(sys, win);              // every crafting window opens the bag beside it
    win.on('open', (arg) => kitOpened(sys, win, arg, { bag: !NO_BAG.has(win.name) }));
    win.on('close', () => kitClosed(win));
    win.on('update', () => kitTick(win));
  });

  // NPC services (the quests system's dialog: game.npcServices.register(jobType, handler(npc, info)))
  const bind = () => {
    const svc = g.npcServices;
    if (!svc?.register || sys._npcBound) return !!sys._npcBound;
    sys._npcBound = true;
    const open = name => (npc, info) => { mgr.open(name, { npc, ...(info || {}) }); return true; };
    svc.register(JOB.VEHICLE_CYCLE, open('vehicle_cycle'));
    svc.register('VEHICLE_CYCLE', open('vehicle_cycle'));
    svc.register(JOB.PET_TRANSFORM, open('pet_shapechange'));
    svc.register('PET_TRANSFORM', open('pet_shapechange'));
    // the items system maps COSTUME_CYCLE / WINGUPGRADE / WING_SHAPE_CHANGE to these window names too
    svc.register(JOB.COSTUME_CYCLE, open('costumesewing'));
    svc.register(JOB.WINGUPGRADE, open('wingupgrade'));
    svc.register(JOB.WING_SHAPE_CHANGE, open('wingshape'));
    return true;
  };
  if (!bind()) {
    g.events?.on?.('systems', () => bind());
    const t = setInterval(() => { if (bind() || !g.uiwin) clearInterval(t); }, 1000);
  }
}
