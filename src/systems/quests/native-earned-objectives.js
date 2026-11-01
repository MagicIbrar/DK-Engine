import {expRateFor} from '../../game/progression.js';
import {D as dungeonTables} from '../dungeons/data.js';
// Original quest labels/counts and grade divisions. ENGINE-CHOSEN: Adinos
// certifies every rank already earned; talking does not manufacture rank XP.
const rankLabels=[
 ['New Recruit Trainee','Trainee','Advanced Trainee','Elite Trainee'],
 ['New Recruit Regular','Regular Army','Advanced Regular Soldier','Elite Regular Soldier'],
 ['New Recruit Guard','Guard','Advanced Guardsman','Elite Guardsman'],
 ['New Recruit Servant Knight','Sergeant',"Advanced Knight's Apprentice","Elite Knight's Apprentice"],
 ['New Recruit Knight','Knight','Advanced Knight','Elite Knight'],
 ['New Recruit White Knight','White Knight','Advanced White Knight','Elite White Knight'],
 ['New Recruit Blue Knight','Blue Knight','Advanced Blue Knight','Elite Blue Knight'],
 ['New Recruit Black Knight','Black Knight','Advanced Black Knight','Elite Black Knight'],
 ['New Recruit Twilight Knight','Twilight Knight','Advanced Twilight Knight','Elite Twilight Knight'],
 ['New Recruit Dawn Knight','Dawn Knight','Advanced Dawn Knight','Elite Dawn Knight'],
 ['New Recruit Light Knight','Aurora Knight','Advanced Daybreak Knight','Elite Daybreak Knight'],
 ['New Recruit Radiant Knight','Radiant Knight','Advanced Radiant Knight','Elite Radiant Knight'],
 ['New Knight of Hope','Knight of Hope','Senior Knight of Hope','Elite Knight of Hope'],
 ['New Knight of Glory','Knight of Glory','Senior Knight of Glory','Elite Knight of Glory'],
 ['New Knight of Honor','Knight of Honor','Senior Knight of Honor','Elite Knight of Honor'],
 ['New Knight Commander','Knight Commander','Senior Knight Commander','Elite Knight Commander'],
 ['New Honorary Commander','Honorary Commander','Senior Honorary Commander','Elite Honorary Commander'],
];
export function rankObjective(quest,objective){
 const division=Number(quest?.id)-2010,slot=Number(objective?.slot);
 return Number(quest?.turnIn?.npc)===5489&&objective?.count===1&&rankLabels[division-1]?.[slot]===objective.label?4*(division-1)+slot+1:null;
}
export function nativeEarnedObjectives(catalogue,dialogs){
 const quests={...catalogue.quests};
 for(let id=2011;id<=2027;id++){
  const q=quests[id];if(!q)continue;
  // "Guard" and "Knight" were falsely inferred as monster kills by the builder.
  quests[id]={...q,objectives:(q.objectives||[]).map(o=>rankObjective(q,o)?{...o,kind:'scripted',hint:'rank',targets:[],inferred:undefined}:o)};
 }
 const q=quests[8072];
 if(q&&String(dialogs?.strings?.[8072]?.[12]).includes('[nlink]5913[/nlink'))quests[8072]={...q,turnIn:{npc:5913,map:651,pos:[253.19,55.25],alsoOn:[652],recoveredFrom:'native journal nlink5913'}};
 return {...catalogue,quests};
}
const pvpRows={2081:['Complete DK Square',1,'finish'],2082:['Win DK Square',1,'win'],2083:['Defeat Enemy',3,'kills'],2085:['Win DK Square',5,'win'],2086:['DK Square Defeat',1,'lose']};
export function creditPvpResult(engine,{venue,outcome,kills=0}={}){
 if(venue!=='dkSquare'||!['win','lose','draw'].includes(outcome))return;
 for(const[id,[label,count,kind]]of Object.entries(pvpRows)){
  const q=engine.db.quest(id),o=q?.objectives?.find(o=>o.slot===0);
  if(!engine.isActive(id)||o?.kind!=='scripted'||o.label!==label||o.count!==count)continue;
  const n=kind==='kills'?Math.max(0,Math.floor(Number(kills)||0)):kind==='finish'||kind===outcome?1:0;
  if(n)engine.advance(Number(id),0,n);
 }
}

const earnedKills={5004:[1,'First Test',500,'level'],5005:[1,'Second Test',1500,'level'],5006:[1,'Last Test',3500,'level'],5007:[0,'Low Level Task',50,'deadfront'],5008:[0,'Intermediate Task',50,'infinite'],5009:[0,'High Level Task',1,'dungeonBoss'],5421:[1,"Giant Penril 's Crest",30,'penril']};
export function earnedKillKind(q,o){const r=earnedKills[q?.id];return r&&o?.kind==='scripted'&&o.slot===r[0]&&o.label===r[1]&&o.count===r[2]?r[3]:null;}
export function earnedKillMatches(engine,q,o,actor){
 const kind=earnedKillKind(q,o);if(!kind)return false;
 const map=Number(engine.mapIndex),mi=Number(actor.monsterIndex??actor.def?.index??actor.index);
 if(kind==='penril')return [7301,7306,7314].includes(mi)&&[167,172,173,174].includes(map);
 if(!engine._inGuild())return false;
 const data=engine.game.data;
 if(kind==='level'){
  // ENGINE-CHOSEN native levelcap.csv full-XP band defines "match your level".
  const level=Number(actor.def?.level??actor.level);
  return Number.isFinite(level)&&Array.isArray(data?.exp?.levelDifference)&&data.exp.levelDifference.length>0&&expRateFor(level-engine.level,data)===100;
 }
 const maps=data?.dungeonMaps||dungeonTables.dg?.maps,meta=maps?.[map],name=String(meta?.name||'');
 // Native maplist script identities survive display-name/localisation changes.
 // Current 153/154/155/613 are labelled "[IB]", not "Infinite Battle".
 const script=String(meta?.script||'');
 const df=/^(?:Dead_Front_|Map_\d+_IceCastle(?:_|$))/i.test(script)||/Dead Front|Ice Castle/i.test(name);
 const infinite=/^Map_\d+_(?:Event_(?:Prison|Draco|Norak|Stadion)|Infinite_?2)(?:_|$)/i.test(script)||/Infinite Battle/i.test(name);
 if(kind==='deadfront')return df;
 if(kind==='infinite')return infinite;
 // The native map catalogue must declare a dungeon and the native monster a
 // boss. A field raid / other event cannot satisfy the advanced dungeon task.
 return kind==='dungeonBoss'&&meta?.kind==='instance'&&!df&&!infinite&&!/Field Raid/i.test(name)&&Number(actor.def?.rank)>=3;
}
export function earnedFishMatches(q,o,item){return q?.id===15706&&o?.slot===1&&o.kind==='scripted'&&o.label==='Strarving Piranha'&&o.count===10&&Number(item)===56636;}

export function stoneObjective(q,o){
 if(q?.id===8072&&o?.slot===1&&o.kind==='scripted'&&o.count===1&&o.label==='Investigate the Water Guardian Stone')return [5906];
 if(q?.id===8073&&o?.slot===0&&o.kind==='scripted'&&o.count===2&&o.label==='Investigate Guardian Stone')return [5907,5908,5909,5910];
 return null;
}
