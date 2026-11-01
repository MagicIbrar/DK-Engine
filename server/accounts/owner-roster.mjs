// Shared source-backed local-owner roster. No account/store writes here.
// Mechanically relocated from reviewed C21 freeze cd005a90edca88f6f0f010dc7df874a37b72af35e6e1b499383d467f4ddac775.
import fs from 'node:fs/promises';
import path from 'node:path';
import {randomUUID} from 'node:crypto';
import {loadWorldData} from '../world/data.mjs';
import {createItem,rollOptions,Container} from '../../src/systems/items/model.js';
import {Equipment,S,emptyEquip} from '../../src/systems/items/equip.js';
import {stoneFits,isStone,socketable} from '../../src/systems/items/ui/socket.js';
import {documentedSocketLimit} from '../../src/systems/items/socket-capacity.js';
import {SkillEngine} from '../../src/systems/skills/engine.js';
import {SkillData} from '../../src/systems/skills/data.js';
import {awardMeisterRank} from '../../src/systems/skills/rank.js';
const CAPACITY=d=>(d.socketRates||[]).reduce((n,rate,i)=>Number(rate)>0?Math.min(4,i+1):n,0);
export function supportedSocketCapacity(db,def){
 const native=CAPACITY(def),limit=documentedSocketLimit(db,def);if(limit===0)return 0;if(!socketable(def))return limit===null?native:Math.min(native,limit);if(limit===null)return native;
 if(Number(def.type)===6&&Number(def.code)===1){const row=db.T?.wingAddSocket?.rows?.find(r=>Number(r.ItemIndex)===def.index);return row&&Number(row.Rate)>0?limit:Math.min(native,limit);}
 if(Number(def.rank)===4)return Math.min(native,limit);
 let row=db.T?.addSocket?.rows?.[0];for(const r of db.T?.addSocket?.rows||[])if(Number(r.ITEM_LEVEL)<=Number(def.reqLv||0))row=r;else break;
 const rate=Number(row?.[Number(def.rank)===5?'Deka_Rate':'DIVIN_Rate']);return row&&Number.isFinite(rate)&&rate+Math.min(25,5*(Number(row.SocketStone_Rate)||5))>0?limit:Math.min(native,limit);
}
export function chooseDivineOptions(db,def,score){const out=[],pools=db.options?.pools||{},slots=def.optionPools||[];for(let k=0;k<4&&slots.length;k++){const [,hi]=slots[Math.min([0,0,1,2][k],slots.length-1)]||[];const choices=(pools[hi]||[]).filter(r=>r[1]!=null&&Number(r[3])!==0).map(r=>({pair:[Number(r[1]),Number(r[3])],score:score([...out,[Number(r[1]),Number(r[3])]])}));choices.sort((a,b)=>b.score-a.score||a.pair[0]-b.pair[0]||b.pair[1]-a.pair[1]);if(choices.length)out.push(choices[0].pair);}return out;}
export function chooseFilledGem(db,stones,def,item,capacity,score){const choices=stones.filter(d=>isStone(d)&&!d.period&&stoneFits(db,d,def)).map(d=>({def:d,score:score({...item,sockets:Array(capacity).fill(d.index)})}));choices.sort((a,b)=>b.score-a.score||b.def.index-a.def.index);return choices[0]||null;}
export const OWNER_GEAR_POLICY='Maximum supported source refinement per slot, then class-primary expected damage plus relative defense/HP/MP/element resistance benefit in canonical derived stats; requirement level/index break ties. Not official BIS or unsupported effect parity.';
export function completeNativeWing(data,def){const row=data.mountData?.wings?.[def.index],asset=row&&data.mountData.assets?.[row[0]],shape=data.mountUI?.itemShape?.[def.index],inv=shape!=null&&data.mountUI?.shapes?.[shape];return !!(asset?.mesh&&inv?.mesh&&data.itemDB.look(def.index));}
export function maximizeOwnerSkills(data,profile){
 const pack=data.skillPacks?.[profile.classIndex];if(!pack)return {available:false,reason:'Canonical class skill pack unavailable.'};
 const list=Object.values(pack.skills||{}),rows=(data.ownerGradeData?.grades||[]).slice().sort((a,b)=>a.division-b.division||a.grade-b.grade);let cumulative=0,last=null;
 for(const row of rows){cumulative+=Math.max(0,Number(row.gradeExp)||0);if(Number(row.levelLimit||0)<=profile.level)last={...row,cumulative};else break;}
 if(last){profile.life||={};profile.life.grade={...(profile.life.grade||{}),totalExp:Math.max(Number(profile.life.grade?.totalExp)||0,last.cumulative),rowKey:last.division+'.'+last.grade};profile.grade=Math.max(Number(profile.grade)||0,Number(last.grade)||0);}
 const rewards=Object.values(data.progression?.quests?.quests||{}).map(q=>q.rewards?.meister||q.reward?.meister).filter(r=>Number.isInteger(Number(r?.grade))).sort((a,b)=>Number(b.grade)-Number(a.grade));
 if(rewards[0])awardMeisterRank(profile,rewards[0]);
 const paths=['A','B'].filter(path=>list.some(s=>s.tree?.window==='meister'&&s.tree.path===path));if(!profile.meister?.path&&paths.length)profile.meister={...(profile.meister||{}),path:paths[0]};
 const sd=new SkillData();sd.pack=pack;for(const s of list)sd.skills.set(Number(s.index),s);sd._wantFull=()=>{};
 const game={save:profile,classDef:{...data.classDef(profile.classIndex),skills:list},events:{emit(){}},player:null},engine=new SkillEngine(game,{data:sd,statuses:{}});profile.skills||={};
 let changed=true,passes=0;while(changed&&passes++<=list.reduce((n,s)=>n+(s.levels?.length||0),0)){changed=false;for(const s of list){if(s.hidden)continue;const old=engine.learnedLevel(s.index),next=old+1,L=sd.level(s,next);if(!L||next>engine.maxLevelFor(s)||Number(L.reqLevel)>profile.level||Number(L.grade||0)>Number(profile.grade??profile.transGrade)||L.prereqs?.some(pr=>engine.learnedLevel(pr.skill)<Number(pr.level)))continue;const path=profile.meister?.path;if(L.availability&&L.availability!=='all'&&!(L.availability==='path A'?path==='A':L.availability==='path B'?path==='B':!!path))continue;if(s.tree?.window==='meister'&&old>=1&&!(s.upgrade||[]).some(r=>Number(r.level)===old))continue;profile.skills[s.index]=next;changed=true;}}
 const learned=list.filter(s=>engine.learnedLevel(s.index)>0),missingBookTargets=[...new Set(Object.keys(data.itemDB.items).map(id=>data.itemDB.def(id)).filter(d=>((Number(d.classMask)>>>profile.classIndex)&1)).map(d=>Number(d.use?.meisterSkill||d.use?.skill)).filter(id=>id>0&&!sd.skill(id)))];
 return {available:true,path:profile.meister?.path||null,meisterGrade:profile.meister?.grade||0,awakening:last?{grade:last.grade,name:last.name}:null,learned:learned.length,totalRanks:learned.reduce((n,s)=>n+engine.learnedLevel(s.index),0),normal:learned.filter(s=>s.tree?.window!=='meister').length,meister:learned.filter(s=>s.tree?.window==='meister'&&s.tree?.tier!=='grand_meister').length,grand:learned.filter(s=>s.tree?.tier==='grand_meister').length,missingBookTargets,unsupportedTransform:learned.filter(s=>engine._missingTransform(s,sd.level(s,engine.learnedLevel(s.index))||{})).map(s=>s.index),unavailable:list.filter(s=>(!s.hidden&&engine.learnedLevel(s.index)<engine.maxLevelFor(s))||(s.tree?.window==='meister'&&s.tree.path&&s.tree.path!==profile.meister?.path)).map(s=>({skillIndex:s.index,name:s.name,reason:s.tree?.path&&s.tree.path!==profile.meister?.path?'Opposite exclusive Meister path.':'Authored level/prerequisite/reinforcement data gate.'}))};
}
const mainDamage=def=>[['melee',def.melee],['range',def.ranged],['magic',def.magic]].sort((a,b)=>Number(b[1]?.[1]||0)-Number(a[1]?.[1]||0))[0][0];
function canonicalStats(data,profile,slot,item){const copy={...profile,buffs:structuredClone(profile.buffs||[]),equip:structuredClone(profile.equip)};if(item){copy.equip.items.__owner_probe={...item,uid:'__owner_probe'};copy.equip.presets[copy.equip.active][slot]='__owner_probe';}return {stats:data.stats(copy),view:copy.equipment};}
function benefit(stats,base,kind){
 const expected=s=>Number(s[kind+'Max']||s.attackMax||0)*(1+Number(s.critRate||0)/100*(Number(s.critMultiplier||1.5)-1));
 const relative=(value,old)=>Number(value||0)/Math.max(1,Math.abs(Number(old||0)));
 return relative(expected(stats),expected(base))*5+relative(stats.defense,base.defense)*2+relative(stats.maxHp,base.maxHp)*2+relative(stats.maxMp,base.maxMp)*.5+Object.values(stats.resist||{}).reduce((a,v)=>a+Number(v||0),0)/100000+Number(stats.bossDamage||0)/100+Number(stats.vitality||0)/10000+Number(stats.magicResist||0)/10000;
}
export function adminProfile(data,existing,ci,now=Date.now()){
 const previous=existing?.equip,previousPreset=previous?.presets?.[previous.active||0]||{};
 const def=data.classDef(ci),profile=existing?structuredClone(existing):{id:'c'+randomUUID().replaceAll('-',''),name:'Admin'+def.name.replace(/[^A-Za-z]/g,'').slice(0,15),classIndex:ci,className:def.name,authority:'server',starterSkillPending:true,inventory:[],hotbar:[],skills:{},kills:0,deaths:0,playSeconds:0,created:now,map:data.start.map,pos:{x:data.start.x,z:data.start.z,dirDeg:0}};
 profile.level=Math.max(profile.level||1,data.maxLevel);profile.exp??=0;profile.statPoints??=0;profile.skillPoints=Math.max(profile.skillPoints||0,data.maxLevel-1);
 profile.stats=Object.fromEntries(['str','dex','con','spr'].map(stat=>[stat,data.statCap(ci,stat)]));
 data.initializeEquipment(profile);
 const db=data.itemDB;db.T=data.itemUseData.tables;
 const equipment=new Equipment({db,game:{save:profile}}),defs=Object.keys(db.items).map(id=>db.def(id));
 const allowed=d=>d?.slot&&((Number(d.classMask)>>>ci)&1)&&!d.period&&!(d.reqLv>profile.level)&&!(d.maxLv>0&&d.maxLv<profile.level)&&Number(d.itemLv||0)<=15&&!/test|테스트/i.test(d.name||'')&&(d.slot!=='wing'||completeNativeWing(data,d));
 const stones=defs.filter(d=>isStone(d)&&!/test|테스트/i.test(d.name||'')),gear=[],unavailable=[];
 const active=profile.equip.active,bag=new Container(profile.inventory,db,{pages:7,cols:10,rows:5,unlocked:()=>profile.bagsUnlocked||2});
 const scoreProfile={...profile,buffs:[],equip:emptyEquip()};
 const slots=[S.weapon,S.offhand,...new Set(Object.values(db.equipment.slotGroups||{}).flat().filter(slot=>![S.weapon,S.offhand].includes(slot))),S.weapon2,S.offhand2];
 const kind=mainDamage(db.def(def.weapon.itemIndex)||defs.find(d=>d?.slot==='weapon'&&Number(d.code)===Number(def.weapon.code))||{});
 for(const slot of slots){
  const baseSlot=slot>=100?slot-100:slot;
  let candidates=defs.filter(d=>allowed(d)&&equipment.slotsFor(d).includes(baseSlot)&&(baseSlot!==4||Number(d.code)===Number(def.weapon.code)));
  if([0,1,2,3].includes(baseSlot))candidates=candidates.filter(d=>/ring|반지/i.test(d.name||''));
  if([4,8,9,10,11,12].includes(baseSlot))candidates=candidates.filter(d=>rollOptions(d,'divine',db,()=>0).length===4);
  candidates=candidates.filter(d=>equipment.check({itemIndex:d.index},slot,profile.stats).ok);
  if(!candidates.length){unavailable.push({slot,reason:'No permanent class/level/weapon-compatible source item.'});continue;}
  const maxRefine=Math.max(...candidates.map(d=>Number(d.itemLv||0)));candidates=candidates.filter(d=>Number(d.itemLv||0)===maxRefine);
  const base=canonicalStats(data,scoreProfile).stats;
  const rankedItem=d=>{const item=createItem(db,d.index,{grade:'divine',rng:()=>0,bound:true,now});item.rnd=chooseDivineOptions(db,d,rnd=>benefit(canonicalStats(data,scoreProfile,baseSlot,{...item,rnd}).stats,base,kind));if(!item.rnd.length)delete item.rnd;return item;};
  const scored=candidates.map(d=>({def:d,score:benefit(canonicalStats(data,scoreProfile,baseSlot,rankedItem(d)).stats,base,kind)}));
  scored.sort((a,b)=>b.score-a.score||Number(b.def.reqLv||0)-Number(a.def.reqLv||0)||b.def.index-a.def.index);const selected=scored[0].def;
  const old=equipment.get(slot),generated=rankedItem(selected);
  const item=old?.itemIndex===selected.index?{...old,...generated,uid:old.uid}:generated;
  delete item.sockets;
  if(!generated.rnd)delete item.rnd;
  if(old?.itemIndex!==selected.index){let uid='adminmax-'+ci+'-'+slot+'-v2-'+selected.index;while(profile.equip.items[uid]||profile.inventory.some(i=>i.uid===uid))uid+='n';item.uid=uid;}
  const emptyItem={...item,sockets:[]},emptyStats=canonicalStats(data,scoreProfile,baseSlot,emptyItem).stats;
  const capacity=supportedSocketCapacity(db,selected),choice=chooseFilledGem(db,stones,selected,emptyItem,capacity,candidate=>benefit(canonicalStats(data,scoreProfile,baseSlot,candidate).stats,emptyStats,kind)-benefit(emptyStats,emptyStats,kind)),gem=choice?.score>1e-10?choice.def:null;
  if(capacity&&!gem)throw Error('No canonically effective compatible gem for source gear slot '+slot);
  if(capacity)item.sockets=Array(capacity).fill(gem.index);
  const placed=equipment.place(item,slot,active);
  for(const displaced of placed.displaced){if(displaced.uid===item.uid)continue;if(!bag.canAdd(displaced)||!bag.add(displaced).ok)throw Error('No safe bag room for preserved displaced owner gear; provisioning refused.');}
  gear.push({slot,itemIndex:item.itemIndex,name:selected.name,refinement:selected.itemLv||0,reqLevel:selected.reqLv,optionLines:item.rnd?.length||0,sockets:item.sockets?.length||0,gem:item.sockets?.length?gem.index:null,gemName:item.sockets?.length?gem.name:null,canonicalGemBenefit:capacity?choice.score:0});
 }
 // Re-rank complete filled arrays against the final, buff-free active loadout.
 for(const row of gear){const item=equipment.get(row.slot),d=db.def(item.itemIndex),capacity=supportedSocketCapacity(db,d);if(!capacity)continue;const ref={...profile,buffs:[]},slot=row.slot>=100?row.slot-100:row.slot,empty={...item,sockets:[]},base=canonicalStats(data,ref,slot,empty).stats,choice=chooseFilledGem(db,stones,d,empty,capacity,candidate=>benefit(canonicalStats(data,ref,slot,candidate).stats,base,kind)-benefit(base,base,kind));if(!choice||choice.score<=1e-10)throw Error('No effective fully filled gem choice for slot '+row.slot);item.sockets=Array(capacity).fill(choice.def.index);row.gem=choice.def.index;row.gemName=choice.def.name;row.canonicalGemBenefit=choice.score;}
 if(!gear.some(g=>g.slot===S.weapon))throw Error('No compatible original weapon for '+def.name);
 const skills=maximizeOwnerSkills(data,profile);
 const result=canonicalStats(data,profile),stats=result.stats;if(!Number.isFinite(stats.maxHp)||!Number.isFinite(stats.maxMp))throw Error('Invalid canonical derived stats');profile.equipment=result.view;profile.hp=stats.maxHp;profile.mp=stats.maxMp;
 profile.ownerProvision={...(profile.ownerProvision||{}),version:2,level:data.maxLevel,policy:OWNER_GEAR_POLICY};
 const changes={missingSlots:[],itemChanges:[],gemChanges:[],optionChanges:[]};
 for(const selected of gear){const old=previous?.items?.[previousPreset[selected.slot]],current=equipment.get(selected.slot);if(!old)changes.missingSlots.push(selected.slot);else{if(old.itemIndex!==selected.itemIndex)changes.itemChanges.push(selected.slot);if(JSON.stringify(old.sockets||[])!==JSON.stringify(current.sockets||[]))changes.gemChanges.push(selected.slot);if(JSON.stringify(old.rnd||[])!==JSON.stringify(current.rnd||[]))changes.optionChanges.push(selected.slot);}}
 return {profile,summary:{classIndex:ci,className:def.name,existing:!!existing,level:profile.level,baseStats:profile.stats,gear,unavailable,skills,changes,policy:OWNER_GEAR_POLICY}};
}

// Invoked only inside accounts.ownerLaunch's authenticated fresh-admin branch.
// Existing owners use saved progress; ordinary signups never call this factory.
export function createFreshOwnerRoster({dataRoot,gamedataRoot,customItemsFile,loadData}={}) {
 let loading;
 return async owner => {
  if(owner?.id!=='admin'||!Array.isArray(owner.characters)||owner.characters.length)throw Error('Initial roster requires a fresh installation-owner account.');
  if(!loading)loading=(async()=>{
   const data=loadData?await loadData():await loadWorldData({dataRoot,gamedataRoot,customItemsFile});
   const ownerGradeData=data.ownerGradeData||JSON.parse(await fs.readFile(path.join(gamedataRoot,'life.json'),'utf8')).grade;
   if(!data.itemDB||!data.skillPacks||!ownerGradeData?.grades?.length)throw Error('Canonical owner-roster sources are unavailable.');
   return {...data,ownerGradeData};
  })().catch(error=>{loading=null;throw error;});
  const data=await loading,now=Date.now(),characters=[];
  for(let ci=0;ci<15;ci++)characters.push(adminProfile(data,null,ci,now).profile);
  return characters;
 };
}
