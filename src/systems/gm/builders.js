// Both native shortcuts and the GM tab use the same permission-checked opening hook.
import {requireGMPanelPermission} from './permissions.js';
import {openNativeOriginalEditor} from './native-original-editor.js';
export async function openBuilder(game,tool,{currentOriginal=null}={}) {
  requireGMPanelPermission(game);
  const network=game.network,lease=network?.token;
  const live=()=>game.save?.authority!=='server'||game.network===network&&network?.active===true&&network.ready===true&&!!lease&&network.token===lease&&!network.disposed;
  if(!live())throw new Error('Connect to the loaded shared world before opening a builder.');
  if(tool==='itembuilder') {
    if(!game.customItems?.openBuilder)throw new Error('Item Builder is not ready. Enter the game first.');
    return game.customItems.openBuilder();
  }
  if(tool!=='mapbuilder')throw new Error('Unknown builder.');
  if(currentOriginal===null)currentOriginal=game.originalMapEdits?.list().includes(Number(game.world?.info?.index))===true;
  if(currentOriginal&&!game.originalMapEdits?.list().includes(Number(game.world?.info?.index)))throw Error('This current field is not configured for original live brush editing. The existing fly camera remains available.');
  if(currentOriginal){
    const old=document.getElementById('gm-map-builder');
    if(old?.querySelector('iframe')?.contentWindow?.mapbuilder?.editor?.dirty)throw Error('Save or cancel the open builder draft before editing the current native field.');
    if(old?.querySelector('iframe')?.contentWindow?.mapbuilder?.editor?.originalLive?.active){await game._returnOriginalEditor();}
    else if(old){old.remove();game._returnOriginalEditor=null;}
    return openNativeOriginalEditor(game);
  }
  if(game.originalSceneEditor?.active){await game.originalSceneEditor.requestExit();if(game.originalSceneEditor?.active)return game.originalSceneEditor;}
  if(!game.customMaps?.openBuilder)throw new Error('Map Builder is not ready.');
  // Remote/native clicks cannot open a browser popup. Embed the existing editor
  // on the same authenticated origin instead; its implementation is unchanged.
  let host=document.getElementById('gm-map-builder');
  if(host){host.style.display='flex';if(currentOriginal){host.querySelector('iframe').contentWindow.dispatchEvent(new host.querySelector('iframe').contentWindow.Event('originaleditingready'));}return;}
  host=document.createElement('div');host.id='gm-map-builder';
  // The editor must cover the floating GM helper so its own navigation and
  // history controls receive clicks. The close button stays inside this host.
  Object.assign(host.style,{position:'fixed',inset:'20px',zIndex:'100020',display:'flex',flexDirection:'column',background:'#151b26',border:'1px solid #b89652'});
  const returnToCharacter=async()=>{const live=frame.contentWindow?.mapbuilder?.editor?.originalLive;if(live?.active)await live.finish(false);host.remove();game._returnOriginalEditor=null;const mode=game.gm?.buildMode;if(mode){mode._returning=true;try{mode.set(false);}finally{mode._returning=false;}}if(game._worldReady&&!game._loadingMap)game.cam?.snap?.();};
  game._returnOriginalEditor=returnToCharacter;
  const close=document.createElement('button');close.textContent='Exit · return to character / cancel draft';close.onclick=()=>{void returnToCharacter().catch(error=>game.gm?.say?.(error.message));};
  const frame=document.createElement('iframe');frame.title='Map Builder';frame.src='/tools/mapbuilder.html';Object.assign(frame.style,{flex:'1',width:'100%',border:'0'});
  frame.addEventListener('load',()=>{if(document.getElementById('gm-map-builder')!==host)return;try{requireGMPanelPermission(game);if(!live()){host.remove();return;}if(game.originalMapEdits){game.originalMapEdits.returnToCharacter=returnToCharacter;game.originalMapEdits.openCurrentInGame=()=>openBuilder(game,'mapbuilder',{currentOriginal:true});frame.contentWindow.originalMapEditing=game.originalMapEdits;}if(game.serverMaps){frame.contentWindow.mapPublication=game.serverMaps;frame.contentWindow.dispatchEvent(new frame.contentWindow.Event('mappublicationready'));}if(currentOriginal)frame.contentWindow.dispatchEvent(new frame.contentWindow.Event('originaleditingready'));}catch{host.remove();game._returnOriginalEditor=null;}});
  host.append(close,frame);document.body.append(host);
}
