import {createBotRosterView,currentPlayerMap} from './bot-roster-view.js';
import {normalizeCharacterName, normalizeStaffCharacterName, configureCharacterNameInput, characterNameColorSelect} from '../../game/character-name.js';
import {playerMapBackdrop} from './player-map-backdrop.js';
import {h,btn,input,select} from './kit.js';
import {playerMapPosition,constrainPlayerMapView,zoomPlayerMap,panPlayerMap,playerMapDestination} from './player-map-view.js';
import {hasGMPanelPermission,requireGMPanelPermission} from './permissions.js';
export {playerMapPosition} from './player-map-view.js';
export async function playerIntent(ctx,operation,fields={}){
 requireGMPanelPermission(ctx.game);
 const net=ctx.game.network,token=net?.token;if(!net?.ready||!token||net.disposed)throw Error('Connect to the shared world first.');
 const result=await net._request('gm',{token,operation,...fields});if(ctx.game.network!==net||net.token!==token||!net.ready||net.disposed||!hasGMPanelPermission(ctx.game))throw Error('The GM session changed. Reconnect and refresh this tool.');if(result.state)net._receiveSnapshot(result.state);if(result.message)ctx.status(result.message);return result;
}
export function renameControls(ctx){
 const name=input('text','',{placeholder:'New character name'});configureCharacterNameInput(name);
 const staffTag=select([['','Ordinary name'],['GM','[GM] override'],['DEV','[DEV] override']], '',()=>{});
 const color=characterNameColorSelect();
 const keep=document.createElement('option');keep.value='';keep.textContent='Keep current color';color.insertBefore(keep,color.firstChild);
 const target=h('span.gold');const refresh=()=>{target.textContent=ctx.panel.playerTarget?.name||ctx.game.save.name;color.value=ctx.panel.playerTarget?(ctx.panel.playerTarget.nameColor||''):(ctx.game.save.nameColor||'white');};
 let pending=false;
 const rename=async()=>{if(pending)return;const targetId=ctx.panel.playerTarget?.id||ctx.game.network?.self?.id;pending=true;renameButton.disabled=true;try{const result=await playerIntent(ctx,'renamePlayer',{targetId,name:staffTag.value?normalizeStaffCharacterName(`[${staffTag.value}] ${name.value.replace(/^\[(GM|DEV)\]\s*/,'' )}`):normalizeCharacterName(name.value),staffOverride:!!staffTag.value,...(color.value?{nameColor:color.value}:{})});if(!hasGMPanelPermission(ctx.game))return;if(ctx.panel.playerTarget?.id===targetId&&result.player?.id===targetId){ctx.panel.playerTarget.name=result.player.name;ctx.panel.playerTarget.nameColor=result.player.nameColor;}refresh();}catch(e){if(hasGMPanelPermission(ctx.game))ctx.status(e.message);}finally{pending=false;renameButton.disabled=false;}};const renameButton=btn('Rename',rename);refresh();
 return {el:h('div.row',null,h('span.lbl',null,'Rename'),target,name,staffTag,color,renameButton,btn('Select self',()=>{ctx.panel.playerTarget=null;refresh();})),refresh};
}
export function playersPage(ctx){
 let rows=[],maps=[],busy=false,last=0,active=true,generation=0,destination=null,teleporting=false;
 const tiles=new Map(),views=new Map();
 let sceneMap=currentPlayerMap(ctx.game),rosterMaps=[];
 const filter=select([[sceneMap,sceneMap?`Map ${sceneMap}`:'Current map unavailable']],sceneMap,()=>{botRoster.setMap(filter.value);draw();}),status=h('div.dim');
 filter.setAttribute('aria-label','Player map filter');
 const botRoster=createBotRosterView(ctx,{request:fields=>playerIntent(ctx,'npcRoster',fields),showMapFilter:false,onMaps:value=>{rosterMaps=value;updateFilter();}});botRoster.onShow();
 const destinationLabel=h('span.gold',null,'Click the map to mark a teleport destination. Ctrl+click to teleport at once.');
 const teleportNow=async()=>{
  if(!destination||teleporting)return;const point={...destination},gen=generation;teleporting=true;teleport.disabled=true;
  try{const result=await playerIntent(ctx,'teleportDestination',point);if(active&&gen===generation&&destination?.map===point.map&&destination?.x===point.x&&destination?.z===point.z){destination=result.destination;destinationLabel.textContent=`Arrived · Map ${destination.map} · ${destination.x.toFixed(1)}, ${destination.z.toFixed(1)}`;draw();}}
  catch(error){if(active&&gen===generation)ctx.status(error.message);}finally{teleporting=false;teleport.disabled=!destination||!active;}
 };
 const teleport=btn('Teleport',teleportNow);teleport.disabled=true;teleport.title='Teleport your GM character to the marked walkable location.';
 const board=h('div.scroll',{style:{height:'430px',background:'linear-gradient(140deg,#18292d,#0b1017)',border:'1px solid #675736',display:'grid',gridTemplateColumns:'repeat(auto-fit,minmax(min(100%,300px),1fr))',gap:'8px',padding:'6px',alignContent:'start',justifyItems:'center'}});
 const list=h('div.scroll',{style:{height:'135px'}}),selected=h('div.gold',null,'Click a dot or character name to choose a target.');
 const choose=p=>{ctx.panel.playerTarget={id:p.id,name:p.name};selected.textContent=`Selected: ${p.name} · Lv ${p.level} · Map ${p.map}`;};
 const act=async(line)=>{if(!ctx.panel.playerTarget)return ctx.status('Select a connected character.');try{await playerIntent(ctx,'playerCommand',{targetId:ctx.panel.playerTarget.id,line});}catch(e){ctx.status(e.message);}};
 const level=input('number',1,{min:1,max:250}),dil=input('number',1000000);level.style.width='55px';dil.style.width='100px';
 function renderView(tile){
  if(tile.destinationMarker){const marked=destination?.map===tile.id;tile.destinationMarker.hidden=!marked;if(marked)Object.assign(tile.destinationMarker.style,playerMapPosition(destination,tile.size,tile.view));}
  const {zoom,x,y}=tile.view;views.set(tile.id,tile.view);
  tile.backdrop.style.transform=`translate(${x*100}%,${y*100}%) scale(${zoom})`;
  tile.zoomLabel.textContent=`${Math.round(zoom*100)}%`;
  tile.zoomOut.disabled=zoom<=1;tile.zoomIn.disabled=zoom>=8;
  tile.viewport.style.cursor=zoom>1?'grab':'default';
  for(const [id,dot]of tile.dots){const p=tile.positions.get(id);if(p)Object.assign(dot.style,playerMapPosition(p,tile.size,tile.view));}
 }
 function createTile(mapId,size){
  const mapName=ctx.game.data?.mapByIndex?.(mapId)?.Name,label=`${mapName?`${mapName} · `:''}Map ${mapId}`;
  const el=h('div.gm-player-map',{style:{width:'100%',maxWidth:'410px',minWidth:'0'}});
  const viewport=h('div.gm-player-map-viewport',{tabIndex:0,role:'group','aria-label':`${label} live player map`,style:{position:'relative',width:'100%',aspectRatio:`${Number(size.height)||512} / ${Number(size.width)||512}`,border:'1px solid #394744',overflow:'hidden',touchAction:'none',userSelect:'none'}});
  const backdrop=h('div.gm-player-map-art',{style:{position:'absolute',inset:'0',backgroundSize:'100% 100%',pointerEvents:'none',transformOrigin:'0 0'}});
  const zoomLabel=h('output',{'aria-label':`${label} zoom`,style:{minWidth:'42px',textAlign:'center'}});
  const tile={id:mapId,el,viewport,backdrop,zoomLabel,size,dots:new Map(),positions:new Map(),view:views.get(mapId)||constrainPlayerMapView(),suppressClickUntil:0};
  const changeZoom=(value,anchor)=>{tile.view=zoomPlayerMap(tile.view,value,anchor);renderView(tile);};
  const control=(text,title,action)=>h('button',{type:'button',title,'aria-label':`${label} ${title}`,onclick:action,style:{border:'1px solid #526061',borderRadius:'4px',background:'#16242e',color:'#eed494',padding:'2px 8px',cursor:'pointer'}},text);
  tile.zoomOut=control('−','Zoom out',()=>changeZoom(tile.view.zoom/1.5));
  tile.zoomIn=control('+','Zoom in',()=>changeZoom(tile.view.zoom*1.5));
  const reset=control('Reset','Reset view',()=>{tile.view=constrainPlayerMapView();renderView(tile);});
  el.append(h('div.row',{style:{gap:'4px',padding:'3px 0'}},tile.zoomOut,zoomLabel,tile.zoomIn,reset,h('span.dim',null,'Scroll to zoom · drag to pan')),viewport);
  tile.destinationMarker=h('span.gm-map-destination',{'aria-label':'Marked teleport destination',hidden:true,style:{position:'absolute',zIndex:'5',width:'16px',height:'16px',border:'2px solid #77ecff',borderRadius:'50%',transform:'translate(-50%,-50%)',boxShadow:'0 0 4px #000',pointerEvents:'none'}});
  viewport.append(tile.destinationMarker);
  viewport.addEventListener('click',event=>{
   if(!active||event.target.closest?.('.gm-player-marker')||performance.now()<tile.suppressClickUntil)return;
   const rect=viewport.getBoundingClientRect();if(!rect.width||!rect.height)return;
   const point=playerMapDestination({x:(event.clientX-rect.left)/rect.width,y:(event.clientY-rect.top)/rect.height},tile.size,tile.view);if(!point)return;
   destination={map:mapId,...point};destinationLabel.textContent=`Map ${mapId} · ${point.x.toFixed(1)}, ${point.z.toFixed(1)}`;teleport.disabled=teleporting;for(const current of tiles.values())renderView(current);
   if(event.ctrlKey)teleportNow();   // Ctrl+click = mark + Teleport in one click (same server intent as the button)
  });
  viewport.append(backdrop,h('span.dim',{style:{position:'absolute',zIndex:'4',background:'#000b',pointerEvents:'none'}},label));
  viewport.addEventListener('wheel',event=>{
   event.preventDefault();const rect=viewport.getBoundingClientRect(),delta=event.deltaY*(event.deltaMode===1?16:event.deltaMode===2?rect.height:1);
   changeZoom(tile.view.zoom*Math.exp(-Math.max(-600,Math.min(600,delta))*.002),{x:(event.clientX-rect.left)/rect.width,y:(event.clientY-rect.top)/rect.height});
  },{passive:false});
  let drag=null;
  viewport.addEventListener('pointerdown',event=>{
   if(event.button!==0||!event.isPrimary)return;
   drag={id:event.pointerId,x:event.clientX,y:event.clientY,view:tile.view,moved:false};
  });
  viewport.addEventListener('pointermove',event=>{
   if(!drag||drag.id!==event.pointerId||tile.view.zoom<=1)return;
   if(!(event.buttons&1)){drag=null;return;}
   const dx=event.clientX-drag.x,dy=event.clientY-drag.y;
   if(!drag.moved&&Math.hypot(dx,dy)<4)return;
   drag.moved=true;viewport.setPointerCapture(event.pointerId);
   const rect=viewport.getBoundingClientRect();tile.view=panPlayerMap(drag.view,dx/rect.width,dy/rect.height);renderView(tile);viewport.style.cursor='grabbing';
  });
  const endDrag=event=>{if(!drag||drag.id!==event.pointerId)return;if(drag.moved)tile.suppressClickUntil=performance.now()+300;drag=null;if(viewport.hasPointerCapture(event.pointerId))viewport.releasePointerCapture(event.pointerId);renderView(tile);};
  viewport.addEventListener('pointerup',endDrag);viewport.addEventListener('pointercancel',endDrag);viewport.addEventListener('lostpointercapture',endDrag);
  viewport.addEventListener('pointerleave',()=>{if(drag&&!drag.moved)drag=null;});
  viewport.addEventListener('keydown',event=>{
   if(event.target!==viewport)return;
   if(event.key==='+'||event.key==='=')changeZoom(tile.view.zoom*1.5);
   else if(event.key==='-')changeZoom(tile.view.zoom/1.5);
   else if(event.key==='0'||event.key==='Home'){tile.view=constrainPlayerMapView();renderView(tile);}
   else if(['ArrowLeft','ArrowRight','ArrowUp','ArrowDown'].includes(event.key)){tile.view=panPlayerMap(tile.view,event.key==='ArrowLeft'?.1:event.key==='ArrowRight'?-.1:0,event.key==='ArrowUp'?.1:event.key==='ArrowDown'?-.1:0);renderView(tile);}
   else return;
   event.preventDefault();event.stopPropagation();
  });
  renderView(tile);return tile;
 }
 function draw(){
 const target=rows.find(p=>p.id===ctx.panel.playerTarget?.id);
 if(target){ctx.panel.playerTarget.name=target.name;selected.textContent=`Selected: ${target.name} · Lv ${target.level} · Map ${target.map}`;}
 else{ctx.panel.playerTarget=null;selected.textContent='Click a dot or character name to choose a target.';}
 list.replaceChildren();const visible=rows.filter(p=>String(p.map)===filter.value);
 const mapIds=filter.value!==''?[Number(filter.value)]:[];
 status.textContent=`${visible.length} connected characters · Map ${filter.value||'unavailable'} · server positions`;
 for(const [id,tile]of tiles)if(!mapIds.includes(id)){tile.el.remove();tiles.delete(id);}
 for(const mapId of mapIds){
  const size=maps.find(m=>Number(m.id)===mapId)||{width:512,height:512};
  let tile=tiles.get(mapId);
  if(!tile){
   tile=createTile(mapId,size);tiles.set(mapId,tile);board.append(tile.el);
  }
  if(!tile.art&&!tile.loading){tile.loading=true;const current=tile;
   void playerMapBackdrop(ctx.game,mapId).then(art=>{if(tiles.get(mapId)!==current)return;if(art){current.art=art;current.backdrop.style.backgroundImage=`url("${art.url}")`;current.backdrop.dataset.source=art.source;current.backdrop.textContent='';}else current.backdrop.textContent='Map preview unavailable; live positions remain shown.';}).finally(()=>{current.loading=false;});
  }
  const players=visible.filter(p=>Number(p.map)===mapId),ids=new Set(players.map(p=>p.id));
  tile.size=size;
  for(const [id,dot]of tile.dots)if(!ids.has(id)){dot.remove();tile.dots.delete(id);tile.positions.delete(id);}
  for(const p of players){
   let dot=tile.dots.get(p.id);
   if(!dot){dot=h('button.gm-player-marker',{type:'button',onclick:e=>{e.stopPropagation();if(e.detail&&performance.now()<tile.suppressClickUntil)return;const current=rows.find(row=>row.id===p.id);if(current){choose(current);draw();ctx.show('inventories',{targetId:current.id});}},style:{position:'absolute',zIndex:'3',transform:'translate(-50%,-50%)',padding:'2px',width:'10px',height:'10px',minWidth:'10px',borderRadius:'50%',border:'0',background:'transparent',cursor:'pointer'}},h('span',{style:{display:'block',width:'6px',height:'6px',borderRadius:'50%',border:'1px solid #17252a',background:'#ffdc77',boxSizing:'border-box',pointerEvents:'none'}}));tile.dots.set(p.id,dot);tile.viewport.append(dot);}
   dot.title=`${p.name} · Lv ${p.level} (${Number(p.x).toFixed(1)},${Number(p.z).toFixed(1)})`;
   dot.setAttribute('aria-label',`Inspect ${p.name} inventory and stash`);dot.setAttribute('aria-pressed',String(ctx.panel.playerTarget?.id===p.id));
   tile.positions.set(p.id,p);Object.assign(dot.style,playerMapPosition(p,size,tile.view));
   dot.style.zIndex=ctx.panel.playerTarget?.id===p.id?'4':'3';dot.firstElementChild.style.background=ctx.panel.playerTarget?.id===p.id?'#72ecff':'#ffdc77';
  }renderView(tile);
 }
 if(!mapIds.length){if(!board.querySelector('.gm-player-map-empty'))board.append(h('div.gm-player-map-empty',null,'No connected characters on this map.'));}else board.querySelector('.gm-player-map-empty')?.remove();
 for(const p of visible)list.append(h('div.row',null,btn(p.name,()=>{choose(p);draw();}),h('span.dim',null,`Lv ${p.level} · Map ${p.map} · ${Number(p.x).toFixed(1)}, ${Number(p.z).toFixed(1)}`)));
 }
 function updateFilter(){const previous=filter.value||currentPlayerMap(ctx.game),ids=new Set([...rows.map(p=>Number(p.map)),...maps.map(m=>Number(m.id)),...rosterMaps.map(m=>Number(m.map)),...(ctx.game.data?.maps?.keys?.()||[])]);if(previous!=='')ids.add(Number(previous));filter.replaceChildren();for(const id of [...ids].filter(id=>Number.isSafeInteger(id)&&id>=0).sort((a,b)=>a-b)){const name=ctx.game.data?.mapByIndex?.(id)?.Name;filter.append(h('option',{value:String(id)},name?`${name} · Map ${id}`:`Map ${id}`));}filter.value=previous;}
 function resetCurrentMap(){sceneMap=currentPlayerMap(ctx.game);if(sceneMap!==''&&!Array.from(filter.children).some(o=>o.value===sceneMap))filter.append(h('option',{value:sceneMap},`Map ${sceneMap}`));filter.value=sceneMap;botRoster.setMap(sceneMap);draw();}
 async function refresh(){if(busy||!active)return;busy=true;last=Date.now();const gen=generation;try{const data=await playerIntent(ctx,'players');if(!active||gen!==generation||!hasGMPanelPermission(ctx.game))return;rows=data.players;maps=data.maps;updateFilter();draw();}catch(e){if(active&&gen===generation)status.textContent=e.message;}finally{busy=false;if(active&&gen!==generation)void refresh();}}
 void refresh();return {el:h('div.scroll',{style:{height:'100%'}},botRoster.el,h('div.row',null,filter,btn('Refresh',refresh)),status,board,h('div.row',null,destinationLabel,teleport),selected,h('div.row',null,btn('Heal',()=>act('/gm heal')),level,btn('Set level',()=>act(`/gm level ${level.value}`)),dil,btn('Add DIL',()=>act(`/gm dil ${dil.value}`)),btn('Rename…',()=>ctx.show('character')),btn('View inventory / stash',()=>{if(ctx.panel.playerTarget)ctx.show('inventories',{targetId:ctx.panel.playerTarget.id});else ctx.status('Select a character on the map or list.');})),list),onShow(){if(!active){active=true;generation++;resetCurrentMap();botRoster.onShow();void refresh();}},onHide(){botRoster.onHide();active=false;generation++;rows=[];maps=[];destination=null;teleport.disabled=true;destinationLabel.textContent='Click the map to mark a teleport destination.';tiles.clear();board.replaceChildren();list.replaceChildren();status.textContent='';selected.textContent='Click a dot or character name to choose a target.';},tick(){if(active&&currentPlayerMap(ctx.game)!==sceneMap){generation++;resetCurrentMap();last=0;}botRoster.tick();if(active&&Date.now()-last>2000)void refresh();}};
}
