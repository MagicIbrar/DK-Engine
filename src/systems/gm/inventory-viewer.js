import {randomUUID} from '../network/web-crypto.js';
import {h,btn,input,select,vlist} from './kit.js';
import {playerIntent} from './players.js';
import {buildTooltip} from '../items/tooltip.js';
import {Equipment} from '../items/equip.js';
import {ITEM_GRADE_COLORS,dilColor,formatDil} from '../../ui/item-colors.js';

export function inventoryPage(ctx) {
  let selected=null, snapshot=null, offset=0,total=0, listing=false, inspecting=false, listAt=0, inspectAt=0, generation=0, detailUid=null,taking=false,pendingTransfer=null;
  const name=input('text','',{placeholder:'Search character name…','aria-label':'Find character inventory'});
  const roster=vlist({height:405,cols:[{get:r=>`${r.online?'●':'○'} ${r.name}`,width:'grow'},{get:r=>`Lv ${r.level}`,width:48}],onSelect:r=>{generation++;selected=r;clearSnapshot('Loading character inventory…');void inspect();}});
  const count=h('span.dim'), identity=h('div.gold',null,'Choose a character to inspect.'), money=h('div.row'), status=h('div.dim');
  const section=select([['inventory','Inventory'],['storage','Stash'],['equip','Equipment'],['costumeBag','Costumes'],['cash','Cash inventory'],['pets','Pet bags'],['shared','Shared stash']],'inventory',()=>{detailUid=null;draw();});
  section.setAttribute('aria-label','Item container');
  const grid=h('div.scroll',{style:{display:'grid',gridTemplateColumns:'repeat(auto-fill,minmax(145px,1fr))',alignContent:'start',gap:'5px',minHeight:'90px',maxHeight:'280px'}});
  const quantity=input('number',1,{min:1,max:100000,'aria-label':'Transfer item quantity'}),reason=input('text','GM item transfer',{maxLength:160,'aria-label':'Transfer audit reason'});
  const take=btn('Take to my inventory',()=>void transfer());take.disabled=true;
  const transferControls=h('div.row',null,quantity,take,reason);
  const detail=h('div.scroll',{style:{maxHeight:'185px',marginTop:'6px'}});
  const previous=btn('Previous',()=>{if(offset){offset=Math.max(0,offset-100);void list();}}),next=btn('Next',()=>{if(offset+100<total){offset+=100;void list();}});
  const refresh=btn('Refresh',()=>{void list();void inspect();});
  function clearSnapshot(message='Choose a character to inspect.'){detailUid=null;take.disabled=true;pendingTransfer=null;snapshot=null;identity.textContent=message;money.replaceChildren();grid.replaceChildren();detail.replaceChildren();status.textContent='';}
  function showDetail(inst){if(detailUid!==inst.uid)quantity.value=String(inst.count||1);detailUid=inst.uid;quantity.max=String(inst.count||1);take.disabled=taking||!['inventory','storage'].includes(section.value)||!snapshot?.revision||!snapshot?.destinationRevision;detail.replaceChildren();
    const sys=ctx.game.items;
    if(sys && snapshot){const viewer=Object.create(sys);viewer.game={...ctx.game,save:{level:snapshot.character.level,classIndex:snapshot.character.classIndex,equip:snapshot.contents.equip},player:{stats:snapshot.character.stats}};viewer.equip=new Equipment(viewer);
      const tooltip=buildTooltip(viewer,inst,{where:section.value==='storage'?'storage':'bag'});if(tooltip)detail.append(tooltip);
    }
    detail.append(h('div.dim',null,`Item ${inst.itemIndex} · ${inst.uid || ''}`));
    // Always expose instance modifiers even when a table's tooltip layout omits a section.
    const fields=['grade','count','rnd','sockets','brand','crest','bound','expiresAt','durability'];
    detail.append(h('div.out',null,fields.filter(k=>inst[k]!=null).map(k=>`${k}: ${JSON.stringify(inst[k])}`).join('\n')));
  }
  function draw(){grid.replaceChildren();detail.replaceChildren();take.disabled=true;if(!snapshot)return;
    const {character:c,contents:s}=snapshot;
    identity.textContent=`${c.name} · Lv ${c.level} · ${c.online?'Online':'Offline'} · Map ${c.map}`;
    money.replaceChildren(...[['DIL',s.dil],['Stash DIL',s.stashDil],['Shared DIL',s.sharedDil]].map(([label,n])=>h('span',{style:{color:dilColor(n)}},`${label}: ${formatDil(n)}`)));
    const rows=section.value==='equip'?Object.values(s.equip.items):s[section.value]||[];
    status.textContent=`${rows.length} item stacks · Bag/stash transfers go to your GM inventory · Updated ${new Date(snapshot.serverTime).toLocaleTimeString()}`;
    if(!rows.length)grid.append(h('div.dim',null,'This container is empty.'));
    for(const inst of rows){const def=ctx.game.items?.db?.def(inst.itemIndex),label=def?.name||inst.name||`Item ${inst.itemIndex}`;
      const icon=h('img',{alt:'',width:32,height:32,style:{objectFit:'contain'}});
      const card=h('button',{type:'button','aria-label':`${label}, quantity ${inst.count||1}`,style:{display:'flex',gap:'6px',alignItems:'center',minHeight:'52px',textAlign:'left',background:'#171915',border:'1px solid #54472e',color:ITEM_GRADE_COLORS[inst.grade]||'#fff',cursor:'pointer',padding:'5px'},onclick:()=>showDetail(inst)},icon,h('span',null,label,h('div.dim',null,`×${inst.count||1} · ${inst.grade||'normal'}`)));
      if(section.value==='equip'){const slots=s.equip.presets.flatMap((p,i)=>Object.entries(p).filter(([,uid])=>uid===inst.uid).map(([slot])=>`Preset ${i+1}, slot ${slot}${i===s.equip.active?' (active)':''}`));card.title=slots.join('\n');}
      else card.title=`${inst.petName?`${inst.petName} · `:''}Page ${(inst.page||0)+1}, cell ${inst.x??0}, ${inst.y??0}`;
      grid.append(card);
      const cached=ctx.game.items?.icons?.now(inst.itemIndex,32,32);if(cached?.url)icon.src=cached.url;
      else void ctx.game.items?.icons?.get(inst.itemIndex,32,32)?.then(value=>{if(value?.url&&card.isConnected)icon.src=value.url;}).catch(()=>{});
    }
    if(detailUid){const inst=rows.find(i=>i.uid===detailUid);if(inst)showDetail(inst);}
  }
  async function list(){if(listing)return;listing=true;listAt=Date.now();const query=name.value.trim(),start=offset,gen=generation;
    try{const result=await playerIntent(ctx,'characterDirectory',{query,offset:start});if(gen!==generation||query!==name.value.trim()||start!==offset)return;total=result.total;roster.setRows(result.characters);count.textContent=`${Math.min(start+1,total)}–${Math.min(start+100,total)} / ${total}`;previous.disabled=!start;next.disabled=start+100>=total;}
    catch(error){if(gen===generation){status.textContent=error.message;roster.setRows([]);}}finally{listing=false;if(active&&(gen!==generation||query!==name.value.trim()||start!==offset))void list();}
  }
  async function inspect(){if(!selected||inspecting||taking)return;inspecting=true;inspectAt=Date.now();const id=selected.ref||selected.targetId,gen=generation;
    try{const result=await playerIntent(ctx,'inspectInventory',selected.ref?{ref:selected.ref}:{targetId:selected.targetId});if(gen!==generation||id!==(selected?.ref||selected?.targetId))return;
      selected=result.character;const changed=JSON.stringify(snapshot?.contents)!==JSON.stringify(result.contents)||JSON.stringify(snapshot?.character)!==JSON.stringify(result.character);snapshot=result;if(changed)draw();
    }catch(error){if(gen===generation){snapshot=null;grid.replaceChildren();detail.replaceChildren();money.replaceChildren();status.textContent=error.message;}}
    finally{inspecting=false;if(active&&(gen!==generation||id!==(selected?.ref||selected?.targetId)))void inspect();}
  }
  async function transfer(){
    if(taking||!snapshot||!detailUid||!['inventory','storage'].includes(section.value))return;
    const item=snapshot.contents[section.value]?.find(i=>i.uid===detailUid),count=Number(quantity.value);if(!item||!Number.isSafeInteger(count)||count<1||count>(item.count||1)){status.textContent='Choose an available item quantity.';return;}
    const fields={ref:snapshot.character.ref,container:section.value,uid:detailUid,count,revision:snapshot.revision,destinationRevision:snapshot.destinationRevision,reason:reason.value.trim()};
    const digest=JSON.stringify({...fields,revision:undefined,destinationRevision:undefined});if(pendingTransfer?.digest!==digest)pendingTransfer={digest,fields:{...fields,requestId:randomUUID()}};
    const request=pendingTransfer,gen=generation;taking=true;take.disabled=true;refresh.disabled=true;
    try{const result=await playerIntent(ctx,'takeInventoryItem',request.fields);if(active&&gen===generation){pendingTransfer=null;detailUid=null;snapshot=null;grid.replaceChildren();detail.replaceChildren();status.textContent=result.replayed?'Transfer already committed; refreshing.':'Transfer saved; refreshing.';}}
    catch(error){if(active&&gen===generation){if([400,401,403,404,409,422,429].includes(error.status))pendingTransfer=null;status.textContent=error.message;}}
    finally{taking=false;refresh.disabled=false;if(active)void inspect();}
  }
  let debounce;name.addEventListener('input',()=>{offset=0;clearTimeout(debounce);debounce=setTimeout(list,120);});
  const el=h('div',{style:{display:'flex',gap:'10px',height:'100%'}},h('div.col',{style:{width:'214px',flexShrink:0}},name,roster.el,h('div.row',null,previous,next),count),h('div.col',{style:{flex:'1',minWidth:0}},identity,money,h('div.row',null,section,refresh),status,grid,detail,transferControls));
  let active=false;
  return {el,onShow(arg){active=true;generation++;if(arg?.targetId){selected={targetId:arg.targetId};clearSnapshot('Loading character inventory…');}void list();void inspect();},onHide(){active=false;generation++;clearTimeout(debounce);selected=null;clearSnapshot();roster.setRows([]);count.textContent='';},tick(){if(!active)return;if(Date.now()-listAt>10000)void list();if(Date.now()-inspectAt>2000)void inspect();}};
}
