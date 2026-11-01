import { h, input } from './kit.js';

// Section names navigate to forms; search never executes a command or edits a save.
const SECTIONS = {
  monsters:['Call monsters','Drops','Simulate kills'], items:['Item spawner','Edit an owned item','Box contents'],
  teleport:['Teleport tools','Map minimap coordinates'], npcs:['NPC actions shops models'],
  character:['Level EXP money','Stats','Class','Cheats','Skills','Buffs','Rename character'],
  players:['Live player map','Heal players','Set player level','Add DIL'],
  inventories:['Inventory viewer','Stash storage warehouse','Equipped items presets','Offline characters'],
  quests:['Quest objectives','Quest state','Quest rewards'],
  world:['Time of day','Weather','Sky','Game speed','Rate events','Notice','Event starter','OX quiz','Music','Effect preview','Server shutdown'],
  drops:['Monster drops','Item drop sources'], builders:['Item Builder weapons armor Meshy import','Map Builder terrain brushes'],
  tools:['Free camera','Performance overlay','Debug collision nav spawns grid bounds','Windows','Model viewer','Tunables formula system variables','Map tool','Clear inventory','Repair all','Event log','Position','Save export import snapshots','Save editor'],
};
export function searchTools(tabs, data, query, extra=[]) {
  const rows=tabs.map(([page,label])=>({label,page,kind:'Tab'}));
  for(const [page,labels] of Object.entries(SECTIONS)) for(const label of labels) rows.push({label,page,kind:'Tool'});
  const seen=new Set();
  for(const command of [...(data.commands||[]),...(data.extra?.values?.()||[])]) {
    if(!command || seen.has(command.id)) continue; seen.add(command.id);
    rows.push({label:command.syntax||command.id,page:'commands',arg:{command:command.id},kind:'Command',search:`${command.id} ${command.desc||''} ${(command.aliases||[]).join(' ')} ${command.category||''}`});
  }
  rows.push(...extra);
  const words=query.toLowerCase().trim().split(/\s+/).filter(Boolean);
  if(!words.length)return [];
  return rows.filter(r=>words.every(w=>`${r.label} ${r.page} ${r.search||''}`.toLowerCase().includes(w))).sort((a,b)=>Number(b.label.toLowerCase().startsWith(query.toLowerCase()))-Number(a.label.toLowerCase().startsWith(query.toLowerCase()))).slice(0,60);
}
export function toolSearch(panel,tabs) {
  const field=input('text','',{placeholder:'Search every GM tool or command…','aria-label':'Search Command Center',autocomplete:'off'});
  Object.assign(field.style,{width:'100%',height:'24px'});
  const results=h('div.scroll',{role:'listbox','aria-label':'GM tool results',style:{display:'none',position:'absolute',top:'26px',left:'0',right:'0',maxHeight:'280px',background:'#14120f',border:'1px solid #8c7647',boxShadow:'0 8px 18px #000b'}});
  const el=h('div.gmk',{style:{position:'absolute',left:'16px',right:'16px',top:'38px',height:'26px',zIndex:80}},field,results);
  let matches=[],active=0;
  function close(){results.style.display='none';field.setAttribute('aria-expanded','false');}
  function choose(row){if(!row)return;panel.show(row.page,row.arg);close();field.value='';field.blur();
    const page=panel.pages[row.page]?.el;
    const candidate=row.element||[...(page?.querySelectorAll('h4,button')||[])].find(e=>e.textContent.toLowerCase().includes(row.label.toLowerCase()));
    if(candidate){candidate.scrollIntoView({block:'nearest'});candidate.animate?.([{backgroundColor:'#99773a'},{backgroundColor:'transparent'}],900);}
  }
  function paint(){results.replaceChildren();results.style.display='block';field.setAttribute('aria-expanded','true');
    if(!matches.length){results.append(h('div',{style:{padding:'8px'}},'No matching tools.'));return;}
    matches.forEach((row,i)=>{const b=h('button',{type:'button',role:'option','aria-selected':i===active,style:{display:'block',width:'100%',textAlign:'left',padding:'7px',border:0,color:'#e8e0c8',background:i===active?'#51432c':'transparent',cursor:'pointer'},onclick:()=>choose(row)},`${row.label}  ·  ${row.kind} / ${tabs.find(t=>t[0]===row.page)?.[1]||row.page}`);results.append(b);if(i===active)b.scrollIntoView({block:'nearest'});});
  }
  function update(){const extra=[];for(const [page,p]of Object.entries(panel.pages))for(const e of p.el.querySelectorAll('h4,button')){const label=e.textContent.trim();if(label.length>3)extra.push({page,label,kind:'Tool',element:e});}
    matches=searchTools(tabs,panel.gm.data,field.value,extra);active=0;if(!field.value.trim())close();else paint();
  }
  field.setAttribute('aria-expanded','false');field.addEventListener('input',update);field.addEventListener('focus',()=>{if(field.value)update();});
  field.addEventListener('keydown',e=>{if(['ArrowDown','ArrowUp','Enter','Escape'].includes(e.key)){e.preventDefault();e.stopPropagation();if(e.key==='Escape'){close();field.blur();}else if(e.key==='Enter')choose(matches[active]);else{active=(active+(e.key==='ArrowDown'?1:-1)+matches.length)%Math.max(1,matches.length);paint();}}});
  el.addEventListener('focusout',e=>{if(!el.contains(e.relatedTarget))close();});
  for(const event of ['pointerdown','mousedown','wheel','keydown'])el.addEventListener(event,e=>e.stopPropagation());
  return {el,close,reset(){close();matches=[];active=0;field.value='';results.replaceChildren();}};
}
