import {h,btn,input,select,check} from './kit.js';
import {gearGemChoices,gearSlotChoices,planGearSet} from './gear-set.js';
import {S} from '../items/equip.js';
import {playerIntent} from './players.js';
import {requireGMPanelPermission} from './permissions.js';
import {Container} from '../items/model.js';
import {comparisonSlotLabel} from '../items/compare.js';
export function gearBuilder(ctx){
 const game=ctx.game,db=game.items?.db,out=h('div.out'),target=select([['self',game.save.name]],'self',()=>{});
 const classes=(game.data?.classes||[]).map(c=>[c.index,c.name]),cls=select(classes,game.save.classIndex,()=>{}),level=input('number',game.save.level,{min:1,max:250}),mode=select([['pvp','PvP set'],['monster','Monster set']],'monster',()=>{}),upgrade=input('number',40,{min:0,max:40}),grade=select(['normal','magic','noble','divine'],'divine',()=>{}),sockets=input('number',4,{min:0,max:4});let bound=true,busy=false;
 const weapon=select([['auto','Auto: strongest compatible weapon']],'auto',()=>{}),offhand=select([['auto','Auto: compatible shield/offhand']],'auto',()=>{}),weaponGem=select([['auto','Auto: top compatible gem']],'auto',()=>{}),offhandGem=select([['auto','Auto: top compatible gem']],'auto',()=>{});
 for(const menu of [weapon,offhand,weaponGem,offhandGem])menu.style.maxWidth='310px';
 const overrides=h('textarea',{rows:2,placeholder:'Optional slot overrides: {"8":12345}',style:{width:'100%'}});
 const options=(menu,rows,label)=>{const value=menu.value;menu.replaceChildren(h('option',{value:'auto'},label));for(const row of rows)menu.appendChild(h('option',{value:String(row.index)},`${row.name}  [${row.index}]`));menu.value=[...menu.options].some(o=>o.value===value)?value:'auto';};
 const selection=()=>{const o=overrides.value.trim()?JSON.parse(overrides.value):{};if(weapon.value!=='auto')o[S.weapon]=Number(weapon.value);if(offhand.value!=='auto')o[S.offhand]=Number(offhand.value);return o;};
 const settings=()=>({classIndex:Number(cls.value),level:Number(level.value),mode:mode.value,upgrade:Number(upgrade.value),grade:grade.value,sockets:Number(sockets.value),bound,overrides:selection(),gems:{...(weaponGem.value!=='auto'?{[S.weapon]:Number(weaponGem.value)}:{}),...(offhandGem.value!=='auto'?{[S.offhand]:Number(offhandGem.value)}:{})}});
 const slotName=comparisonSlotLabel;
 const optionText=(code,value)=>{const option=db.optionType(code);return (option?.text?option.text.replace(/<VALUE>/g,String(value)):`${option?.label||'Option '+code}: ${value}`).replace(/<[^>]*>/g,'');};
 out.style.font='11px Tahoma, Verdana, sans-serif';
 const show=plan=>{out.textContent=plan.items.map(i=>`${slotName(i.slot)}: ${i.name}\n  ${i.options.map(([code,value])=>optionText(code,value)).join(', ')} · ${i.sockets.length} filled sockets${i.sockets.some(Boolean)?` (${db.name(i.sockets[0])})`:''}`).join('\n')+(plan.missing.length?`\nUnavailable slots for this class/style: ${plan.missing.map(slotName).join(', ')}`:'');};
 const refreshChoices=async()=>{if(!db)return;try{await db.tables();const base={classIndex:Number(cls.value),level:Number(level.value),mode:mode.value,upgrade:Number(upgrade.value)};
  options(weapon,gearSlotChoices(db,{...base,slot:S.weapon}),'Auto: strongest compatible weapon');
  const auto=planGearSet(db,{...base,sockets:0,overrides:weapon.value==='auto'?{}:{[S.weapon]:Number(weapon.value)}}),main=weapon.value==='auto'?auto.items.find(i=>i.slot===S.weapon)?.item:Number(weapon.value);
  options(offhand,gearSlotChoices(db,{...base,slot:S.offhand,weaponItem:main}),'Auto: compatible shield/offhand');
  let plan;try{plan=planGearSet(db,{...base,sockets:Number(sockets.value),overrides:selection()});}catch{offhand.value='auto';plan=planGearSet(db,{...base,sockets:Number(sockets.value),overrides:selection()});}
  for(const [slot,menu]of [[S.weapon,weaponGem],[S.offhand,offhandGem]]){const item=plan.items.find(i=>i.slot===slot),rows=item?.sockets?.length?gearGemChoices(db,item.item,base.mode):[];options(menu,rows,rows.length?`Auto: ${rows[0].name}`:'No compatible socket stones');menu.disabled=!rows.length;}
 }catch(e){ctx.status(e.message,'ffff5a45');}};
 const run=async preview=>{if(busy)return;busy=true;try{requireGMPanelPermission(game);await db.tables();const config=settings();if(game.save.authority==='server'){const r=await playerIntent(ctx,'gearSet',{targetId:target.value==='self'?game.network.self.id:target.value,settings:config,preview});show(r.plan);}else{const plan=planGearSet(db,config);show(plan);if(!preview){const bag=game.items.bag,copy=new Container(structuredClone(bag.list),db,{pages:bag.pages,cols:bag.cols,rows:bag.rows,unlocked:()=>bag.unlocked,accept:bag.accept});for(const item of plan.items){const created=game.items.create(item.item,{grade:item.grade,rnd:item.options,sockets:item.sockets,bound:item.bound,roll:false});if(!copy.add(created).ok)throw Error('The full set does not fit. Free inventory space and try again.');}bag.list.splice(0,bag.list.length,...copy.list);game.items.changed('gm:gear-set');game.persist();ctx.status(`Granted ${plan.items.length} ${plan.mode} items.`);}}}catch(e){ctx.status(e.message,'ffff5a45');}finally{busy=false;}};
 const refresh=async()=>{try{if(game.save.authority!=='server')return;const r=await playerIntent(ctx,'players');target.replaceChildren(h('option',{value:'self'},game.save.name));for(const p of r.players)if(p.id!==game.network.self.id)target.appendChild(h('option',{value:p.id},p.name));const rows=new Map(r.players.map(p=>[p.id,p]));target.onchange=()=>{const p=rows.get(target.value==='self'?game.network.self.id:target.value);if(p){cls.value=String(p.classIndex);level.value=String(p.level);void refreshChoices();}};}catch(e){ctx.status(e.message,'ffff5a45');}};
 const field=(label,control)=>h('label',null,label,' ',control);
 for(const control of [cls,level,mode,upgrade,sockets,weapon,offhand])control.addEventListener('change',()=>{void refreshChoices();});
 void refreshChoices();
 return h('div',null,h('h4',null,'Perfect gear builder'),h('div.row',null,field('Character',target),btn('Refresh characters',refresh)),h('div.row',null,field('Class',cls),field('Level ceiling',level),mode),h('div.row',null,field('Fortification ceiling',upgrade),grade,field('Sockets',sockets),check('Bound',()=>bound,v=>bound=v)),h('div.row',null,field('Weapon',weapon),field('Weapon gemstone',weaponGem)),h('div.row',null,field('Shield / offhand',offhand),field('Offhand gemstone',offhandGem)),h('div.tip',null,'Native class and level choices are ranked strongest first. PvP and monster modes rank compatible stones separately and fill every available socket. Preview the full set before granting it.'),overrides,h('div.row',null,btn('Preview full set',()=>run(true)),btn('Add full set',()=>run(false))),out);
}
