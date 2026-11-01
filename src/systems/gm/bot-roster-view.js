// ENGINE-CHOSEN read-only GM roster; dormant identities are not connected actors.
import {h,btn,select} from './kit.js';
import {hasGMPanelPermission} from './permissions.js';

const integer = v => Number.isSafeInteger(v) && v >= 0;
const label = (v,max=100) => String(v ?? '').slice(0,max);
// ENGINE-CHOSEN: browse one map, initially the currently displayed world.
export function currentPlayerMap(game) {
  for(const value of [game.world?.info?.index,game.save?.map,game.network?.self?.map])if(value!==null&&value!==undefined&&value!==''){const map=Number(value);if(integer(map))return String(map);}
  return '';
}
export function createBotRosterView(ctx,{request,limit=50,showMapFilter=true,onMaps=()=>{}}={}) {
  const pageSize=Number.isInteger(limit)?Math.max(1,Math.min(100,limit)):50;
  let active=false,epoch=0,offset=0,total=0,busy=false,session=null;
  const title=h('summary.gold',null,'Persistent player directory');
  const census=h('div.gold',{'aria-label':'Persistent player census'},'Loading persistent character census…');
  const status=h('div.dim',{'aria-label':'Bot roster status'},'Browse persistent character records.');
  const rows=h('tbody'),table=h('table',{'aria-label':'Bot roster rows'},h('thead',null,h('tr',null,...['Name','Map','Class','Level','Activity','Status'].map(v=>h('th',null,v)))),rows);
  let sceneMap=currentPlayerMap(ctx.game);
  const filter=select([[sceneMap,sceneMap?`Map ${sceneMap}`:'Current map unavailable']],sceneMap,()=>{offset=0;void refresh();});filter.setAttribute('aria-label','Bot roster map filter');
  const previous=btn('Previous',()=>{offset=Math.max(0,offset-pageSize);void refresh();});
  const next=btn('Next',()=>{offset+=pageSize;void refresh();});
  const reload=btn('Refresh roster',()=>void refresh());
  const el=h('details.box',{open:true},title,census,h('div.tip',null,'Saved-map directory, not connected-player counts. Dormant intentions earn no offline progress; only active actors have live positions or editable targets.'),h('div.row',null,...(showMapFilter?[filter]:[]),reload,previous,next),status,h('div.scroll',{style:{maxHeight:'260px'}},table));
  const current=()=>{const net=ctx.game.network;return net?.ready&&net.token&&!net.disposed&&hasGMPanelPermission(ctx.game)?{net,token:net.token}:null;};
  const same=s=>{const now=current();return !!s&&now?.net===s.net&&now.token===s.token;};
  function buttons(){previous.disabled=busy||offset===0||total===0;next.disabled=busy||total===0||offset+pageSize>=total;reload.disabled=busy;}
  function clear(message){rows.replaceChildren();total=0;status.textContent=message;census.textContent='Persistent character census unavailable.';title.textContent='Persistent player directory';buttons();}
  function invalidate(message){epoch++;busy=false;session=null;clear(message);}
  async function refresh(){
    if(!active||!el.open)return;
    const owner=current();if(!owner||typeof request!=='function'){invalidate('Connect with GM permission to browse the bot roster.');return;}
    const ticket=++epoch,fields={offset,limit:pageSize};if(filter.value!==''&&integer(Number(filter.value)))fields.map=Number(filter.value);
    session=owner;busy=true;rows.replaceChildren();status.textContent='Loading bot roster…';buttons();
    try {
      const result=await request(fields);
      if(!active||!el.open||ticket!==epoch)return;
      if(!same(owner)){invalidate('The GM session changed. Refresh after reconnecting.');return;}
      const data=result?.npcRoster??result;
      if(data?.enabled===false){offset=0;filter.disabled=true;clear('Persistent directory unavailable.');return;}
      if(data?.enabled!==true||!integer(data.total)||!Array.isArray(data.rows))throw Error('Invalid roster response');
      filter.disabled=false;total=data.total;offset=integer(data.offset)?Math.min(data.offset,Math.max(0,total-1)):fields.offset;
      const summary=data.summary||{},persistent=integer(summary.canonicalCharacters)?summary.canonicalCharacters:integer(summary.total)?summary.total:integer(summary.identities)?summary.identities:null,verified=integer(summary.materializedCharacters)?summary.materializedCharacters:integer(summary.active)?summary.active:null;
      title.textContent=persistent===null?'Persistent player directory':`Persistent player directory · ${persistent} characters`;
      const counts=summary.counts||{},parts=[persistent===null?'Global saved census unavailable':`${persistent} saved characters`,verified===null?'Native actor census unavailable':`${verified} materialized native actors`];
      for(const [key,name]of [['working','remote workers'],['visible','visible actors'],['departing','departing actors'],['queued','queued for native work'],['parked','saved / parked'],['blocked','blocked'],['disabled','simulation disabled']])if(integer(counts[key]))parts.push(`${counts[key]} ${name}`);
      census.textContent=parts.join(' · ')+(data.actorsEnabled===false?' · actor simulation OFF':'');
      const selected=filter.value;filter.replaceChildren();
      for(const map of (Array.isArray(data.maps)?data.maps:[]).slice(0,1000))if(integer(map.map)&&integer(map.count))filter.append(h('option',{value:String(map.map)},`Map ${map.map} (${map.count})`));
      if(selected!==''&&!Array.from(filter.children).some(o=>o.value===selected))filter.append(h('option',{value:selected},`Map ${selected}`));filter.value=selected;onMaps(Array.isArray(data.maps)?data.maps:[]);
      const count=Math.min(pageSize,100,integer(data.limit)?data.limit:pageSize);
      for(const row of data.rows.slice(0,count)) {
        const level=integer(row.level)?row.level:integer(row.startingLevel)?row.startingLevel:'—';
        const className=integer(row.classIndex)?ctx.game.data?.classDef?.(row.classIndex)?.name:null;
        const labels={working:'Native worker',visible:'Visible native actor',materialized:'Materialized native actor',departing:'Departing native actor',queued:'Queued for native work',parked:'Saved / parked',blocked:'Blocked native admission',disabled:'Simulation disabled','unmaterialized-record':'Unmaterialized starting record'};
        const isActor=['working','visible','materialized','departing','active'].includes(row.status),state=labels[row.status]||(row.status==='active'?'Active (server verified)':row.bound===true?'Dormant · saved profile':'Dormant · starting record');
        const activity=typeof row.activity==='string'?row.activity:row.activity?.kind;
        const map=isActor&&integer(row.activeMap)?`${row.activeMap} live / ${row.map} saved`:integer(row.map)?row.map:'—',levelLabel=isActor&&integer(row.activeLevel)?row.activeLevel:row.bound===true||isActor?level:`${level} start`,activityLabel=isActor?label(activity,60):`${row.bound===true?'Saved intention':'Planned'}: ${label(activity,60)}`;
        rows.append(h('tr',null,...[label(row.name),map,className?label(className):integer(row.classIndex)?`Class ${row.classIndex}`:'—',levelLabel,activityLabel,state].map(v=>h('td',null,v))));
      }
      status.textContent=rows.children.length?`Showing ${offset+1}–${offset+rows.children.length} of ${total} roster identities · read-only`:`0 of ${total} roster identities · read-only`;
    } catch {
      if(active&&el.open&&ticket===epoch)clear('Bot roster unavailable. Refresh after reconnecting.');
    } finally {
      if(ticket===epoch){busy=false;buttons();}
    }
  }
  el.addEventListener('toggle',()=>{if(el.open){if(!session){offset=0;void refresh();}}else invalidate('Expand to browse simulated identities.');});
  function setMap(value){if(value===null||value===undefined||value==='')return;const map=Number(value);if(!integer(map))return;const next=String(map);if(filter.value===next)return;offset=0;if(!Array.from(filter.children).some(o=>o.value===next))filter.append(h('option',{value:next},`Map ${next}`));filter.value=next;if(active)void refresh();}
  buttons();
  return {el,setMap,onShow(){if(active)return;sceneMap=currentPlayerMap(ctx.game);setMap(sceneMap);active=true;el.open=true;void refresh();},onHide(){active=false;offset=0;el.open=false;invalidate('Expand to browse simulated identities.');},tick(){const map=currentPlayerMap(ctx.game);if(active&&map!==sceneMap){sceneMap=map;setMap(map);}if(session&&!same(session))invalidate('The GM session changed. Refresh after reconnecting.');}};
}
