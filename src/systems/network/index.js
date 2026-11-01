import {installGameplayPreferences} from './gameplay-preferences.js';
import {installOriginalMapEdits} from './original-map-edits.js';
import {installNetworkPageLifecycle} from './page-lifecycle.js';
import { SharedWorld, noteNetworkFailure } from './client.js';
import { installSharedItems } from './items.js';
import { installSharedLoot } from './loot.js';
import { installSharedCustomItems } from './custom-items.js';
import {installSharedCustomMaps} from './custom-maps.js';
import { installSharedSkills } from './skills.js';
import { installSharedMounts } from './mounts.js';
import { installSharedVehicleServices } from './vehicle-services.js';
import { installSharedPets } from './pets.js';
import {installSharedEvents} from './events.js';
import {installSharedDungeons} from './dungeons.js';
import {installSharedTravel} from './travel.js';
import {ClientReadiness} from './client-ready.js';
import {installSharedLife} from './life.js';
import {installSharedLifeEvents} from './life-events.js';
import {installSharedProduction} from './production.js';
import {installSharedFishing} from './fishing.js';
import {installSharedSupply} from './supply.js';
import {installSharedTrade} from './trade.js';
import {installSharedMailGuild} from './mail-guild.js';
import {installSharedConsignment} from './consignment.js';
import {installSharedPvp} from './pvp.js';
import {installSharedTrainingCamp} from './training-camp.js';
import {installSharedDkSquare} from '../pvp/dksquare.js';
import {installSharedRace} from './race.js';
import {installSharedPersonalShop} from './pcshop.js';
import {installSharedPartyFinder} from './party-finder.js';
import {installSharedMessenger} from './messenger.js';
import {installFriendRequests} from './friend-requests.js';
import {installSharedPlayerMenu} from './player-menu.js';
import {installNpcFriends} from './npc-friends.js';

export function connectionPanel(network) {   // (exported for tools/test-per-frame-cluster5.mjs)
  if (typeof document === 'undefined') return;
  const panel = network._statusPanel = document.createElement('div');
  panel.className = 'dk-shared-world-status';
  panel.setAttribute('role', 'status');
  // Status text uses the native server-name row at top left. This small DOM
  // accessory only holds the signed-out Rejoin action beside that row.
  Object.assign(panel.style, { position: 'absolute', top: '0', left: '100%', display:'none', whiteSpace: 'nowrap',
    zIndex: '500', pointerEvents: 'auto' });
  const label = document.createElement('span'), retry = document.createElement('button');
  retry.type = 'button'; retry.textContent = 'Rejoin'; retry.hidden = true;
  Object.assign(retry.style, { marginLeft: '8px', cursor: 'pointer', color: '#efe2b2', background: '#353123', border: '1px solid #85714b' });
  retry.onclick = async () => {
    retry.disabled = true; network._fatal = false; network._status('connecting');
    await network.join(); retry.disabled = false;
  };
  label.hidden=true;
  panel.append(label, retry); (network.game.ui || document.body).appendChild(panel);
  network._paintStatus = () => {
    const native=network.game.uiwin?.window?.('hud_population');
    const anchor=native?.el;
    if (anchor && panel.parentElement !== anchor) { anchor.appendChild(panel); panel.style.position = 'absolute'; }
    let text = network.active ? 'CONNECTING…' : 'SANDBOX';
    if (network.active && network.status === 'connected') {
      const age = network._snapshotAt ? Date.now() - network._snapshotAt : 0;
      text = age > 4000 ? 'RECONNECTING…' : !network.disposed&&network.token&&network._snapshotAt&&network._simulationPopulationView?network._simulationPopulationView.label:`ONLINE - (${network.onlineCount ?? network.players.size + 1})`;
    } else if (network.active && network.status === 'preparing') text = 'PREPARING WORLD…';
    else if (network.active && network.status === 'preparation-failed') text = 'WORLD PREPARATION FAILED';
    else if (network.active && network.status === 'expired') text = 'SIGNED OUT';
    else if (network.active && network.status === 'disconnected') text = 'RECONNECTING…';
    const error = network._lastCommandError;
    // PERF: this runs every frame (network.update); writing the same attribute value again still queued a DOM mutation + a style
    // invalidation each time (measured ~1 per frame each: title, hidden, data-state). Only write what changed.
    const population=network.active&&!network.disposed&&network.status==='connected'&&network.token&&network._snapshotAt&&Date.now()-network._snapshotAt<=4000?network._simulationPopulationView:null;
    const title = String(error && Date.now() - error.at < 5000 ? error.message : population?.title||'Players online across the shared world');
    if (panel.title !== title) panel.title = title;
    if (label.textContent !== text) label.textContent = text;
    const count=population?.counts?.humans??network.onlineCount??network.players.size+1;
    const shortStatus={'PREPARING WORLD…':'Preparing…','WORLD PREPARATION FAILED':'Unavailable','SIGNED OUT':'Signed out','RECONNECTING…':'Reconnecting…','CONNECTING…':'Connecting…','SANDBOX':'Local play'};
    const compact=network.active&&network.status==='connected'&&(!network._snapshotAt||Date.now()-network._snapshotAt<=4000)?`Online: ${count}`:shortStatus[text]||text;
    if(native&&native.data.populationText!==compact){native.control('lbl_server').setText(compact);native.data.populationText=compact;}
    if(anchor&&anchor.title!==title)anchor.title=title;
    const hidden = network.status !== 'expired' || !!network.token;
    if (retry.hidden !== hidden) retry.hidden = hidden;
    const display=anchor&&!hidden?'':'none';
    if(panel.style.display!==display)panel.style.display=display;
    const state = String(network.status);
    if (panel.dataset.state !== state) panel.dataset.state = state;
  };
  network._paintStatus();
}

// Read-only UI can stay open. Mutations unsupported by the shared server are explicitly blocked.
function restrict(game, network) {
  const block = (object, key, label, promise = false) => {
    if (!object || typeof object[key] !== 'function') return;
    object[key] = () => { network.unavailable(label); return promise ? Promise.resolve(false) : false; };
  };
  for (const key of ['use', 'useSlot', 'useSkill', 'learn', 'learnFromBook', 'setLevel', 'resetPoints', 'applyResult', 'applyImpact', 'addStatus'])
    block(game.skills, key, 'Skills');
  // The skill hook redirects projectile/area combo rows through this method before controller damage.
  // Route those ordinary attacks to the server too, without letting client skill results run.
  if (game.skills) game.skills.basicAttack = target => network.attack(target);
  for (const key of ['addDil', 'spendDil', 'add', 'remove', 'removeInst', 'consume', 'receiveCash', 'transfer',
    'unequipTo', 'equipItem', 'unequip', 'equipFromDrag', 'setPreset', 'swapWeaponTab', 'clonePreset', 'rightClick',
    'receiveInBag']) block(game.items, key, 'Item changes');
  const useBox=ref => {
    const bag=game.items?.bag?.list || [];
    const inst=typeof ref==='object' ? bag.find(e => e.uid===ref?.uid) : typeof ref==='number' ? bag[ref] : bag.find(e => e.uid===ref);
    if(inst && game.boxes?.isBox?.(inst.itemIndex)) return game.boxes.open(inst);
    network.unavailable('This item use');return Promise.resolve(false);
  };
  if(game.items){game.items.rightClick=useBox;game.items.useRef=useBox;game.items.use=useBox;if(game.items.uses)game.items.uses.use=useBox;}
  // Quest engine mutations are server intents installed by quests/server.js.
  for (const key of ['dropFrom', 'pickup', 'pickUp']) block(game.loot, key, 'Loot');
  // These windows are client authoring tools; secure profiles never expose them as world commands.
  const ui = game.uiwin;
  if (typeof ui?.open === 'function') {
    const open = ui.open.bind(ui);
    ui.open = (name, ...args) => /^(?:gm|mapbuilder|itembuilder)/i.test(String(name)) && !game.accountPermissions?.capabilities?.includes('gm:panel') ? network.unavailable('GM permission') : open(name, ...args);
  }
  if (game.chat) game.chat._channel = (type, text) => ['normal','party','whisper','shout','world'].includes(type) ? network.chat(text,type) : network.unavailable('This chat channel');
}

// Attach safe failure metadata (src/systems/network/client.js describeFailure) to an error without changing the error itself.
function withFailure(error, failure) {
  if (failure && error && typeof error === 'object') { try { error.failure = failure; } catch { /* a frozen error keeps its own fields */ } }
  return error;
}

export async function install(game) {
  const network = game.network = new SharedWorld(game,{prepareWorld:true});
  network._installationComplete = false;
  connectionPanel(network);
  if (!network.active) return;
  game._launcherReadiness = new ClientReadiness(game,network);
  const preparationGeneration = network._leaseGeneration;
  // Whatever leaves install() carries SAFE failure metadata (error.failure: phase / category / status / name / code, never server text).
  let prepared = false;
  try { prepared = await network._prepareWorld(preparationGeneration); }
  catch (error) { throw withFailure(error, network.disposed ? null : noteNetworkFailure(network, error, 'ready', preparationGeneration)); }
  if(!prepared||network.disposed||game.network!==network||network._leaseGeneration!==preparationGeneration)
    throw withFailure(new Error('Shared world preparation did not complete before network installation. Retry loading.'), network._admissionFailure?.generation===preparationGeneration ? network._admissionFailure : null);
  restrict(game, network);
  installSharedItems(game, network);
  installSharedLoot(game, network);
  installSharedCustomItems(game, network);
  installSharedSkills(game, network);
  installSharedMounts(game, network);
  installSharedVehicleServices(game, network);
  installSharedPets(game, network);
  installSharedLife(game, network);
  installSharedLifeEvents(game,network);
  installSharedProduction(game,network);
  installSharedFishing(game,network);
  installSharedSupply(game,network);
  installSharedTrade(game,network);
  installSharedMailGuild(game,network);
  installSharedConsignment(game,network);
  installSharedPvp(game,network);
  installSharedTrainingCamp(game,network);
  try{installSharedDkSquare(game,network);}catch(error){console.warn('[network] DK Square unavailable',error);}
  installSharedRace(game,network);   // EVENT-MODES: Server Whole Competition windows + host-owned Mission titles
  installSharedPersonalShop(game,network);
  installSharedPartyFinder(game,network);
  installSharedMessenger(game,network);   // MESSENGER-CHAT: 1:1 chat windows + msn_notify
  installFriendRequests(game,network);    // incoming friend requests (ui_addfriend), after the messenger event chain
  installSharedPlayerMenu(game,network);
  installNpcFriends(game,network);
  installGameplayPreferences(game,network);
  installSharedEvents(game,network);
  await installSharedDungeons(game,network);
  await installSharedTravel(game,network);
  await installSharedCustomMaps(game,network);
  await installOriginalMapEdits(game,network);
  game.chat?.registerCommand?.('/invite',name=>{void game.party?.inviteName?.(name);return true;},'Invite a connected character to your party.');
  network._offMap = game.events?.on?.('map', ({ index }) => {
    if (network._actorMap !== Number(index)) network._clearActors();
    network._lastMove = null; void network.joinMap();
  });
  installNetworkPageLifecycle(network);
  await network.join();
  if(network.disposed||game.network!==network)throw new Error('Network installation was cancelled. Retry loading.');
  network._installationComplete = true;
}
export function update(dt, game) { game.network?.update(dt);game.gameplayPreferences?.update();game.npcFriends?.update(); game.sharedEvents?.update(dt); game.sharedDungeons?.update(dt); game.sharedNavigation?.update(dt);game.observer?.update(dt); }
export function dispose(game) { game.gameplayPreferences?.dispose(); game.observer?.dispose();game.sharedNavigation?.dispose();game.npcFriends?.dispose();game.originalMapEdits?.dispose();game.network?.dispose(); }
