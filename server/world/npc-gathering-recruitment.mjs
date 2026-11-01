import {sameScene} from './scene.mjs';
import {npcEventOptions,npcEventCapabilities} from './npc-event-parties.mjs';
import {FOREIGN_KEEPERS} from '../../src/systems/dungeons/data.js';
import {premiumDungeonFee} from './premium-fees.mjs';
// ENGINE-CHOSEN class diversity preferences and speech only. None of these
// classes is presented as a native admission requirement. No invite, currency,
// ticket, registration or private instance is created by this pure query.
const owns=(p,id)=>(p.profile.inventory||[]).some(i=>Number(i.itemIndex)===Number(id)&&Number(i.count??1)>0);
const alive=p=>p&&!p.dead&&!p.leaving&&!p.revoked&&!p.sceneTransition&&!p.instanceId&&!p.mount&&!p.tradeId&&!p.progressCommitting;
const band=(p,range)=>p.profile.level>=Number(range?.[0]||1)&&(!Number(range?.[1])||p.profile.level<=Number(range[1]));
const supported=info=>info?.files?.map&&['boss','all-waves','all-static'].includes(info.stages?.clear?.kind)&&!!(info.waves?.length&&info.files?.calls||info.static?.rows?.length&&info.files?.monsters||info.scriptSpawns?.length&&info.files?.npcs);
export function npcGatheringRecruitment({world,player:p,brain={},now=world.now()}){
 if(world.players.get(p?.account)!==p||!alive(p)||p.profile?.authority!=='server'||!p.npcPlayer||!p.profile.npcPlayer||p.gmAuthorized||p.pcShopOpen)return null;
 const party=p.partyId&&world.parties.get(p.partyId);if(!party||party.leader!==p.id||party.members.length>=7)return null;
 const actors=new Map([...world.players.values()].map(q=>[q.id,q])),members=party.members.map(id=>actors.get(id));
 if(!members.length||members.some(q=>!alive(q)||q.partyId!==party.id||!sameScene(p,q)||Math.hypot(p.x-q.x,p.z-q.z)>20))return null;
 const used=new Set(members.map(q=>q.profile.classIndex)),classes=world.data.classesFile?.classes||[],start=(Number(p.profile.npcSeed?.slot)||0)%Math.max(1,classes.length),preferences=[],owned=members.map(q=>npcEventCapabilities(world.data,q)),missingRoles=['heal','support','damage'].filter(role=>!owned.some(r=>r[role])),minimumLevel=Math.min(...members.map(q=>q.profile.level));
 // Prospective class preferences use actual catalogued ally skills, separately
 // from the team's OWNED capability checks. They never claim a recruit owns a
 // skill, and never grant any skills or establish a required admission role.
 const potential=cls=>{const skills=Object.fromEntries(Object.values(world.data.skillPacks?.[cls.index]?.skills||{}).filter(s=>s.levels?.[0]?.reqLevel<=minimumLevel).map(s=>[s.index,s.levels[0].level]));return npcEventCapabilities(world.data,{profile:{classIndex:cls.index,level:minimumLevel,skills}});};
 const ordered=Array.from({length:classes.length},(_,i)=>classes[(start+i)%classes.length]),scores=new Map(ordered.map(cls=>{const roles=potential(cls);return [cls,missingRoles.reduce((n,r)=>n+(roles[r]?(r==='heal'?100:r==='support'?40:20):0),0)];}));ordered.sort((a,b)=>scores.get(b)-scores.get(a));
 for(const cls of ordered){if(!used.has(cls.index)&&cls.name)preferences.push(cls.name);if(preferences.length===2)break;}
 if(!preferences.length)return null;
 const speech=(name,maximum,metadata)=>{const free=maximum-members.length;if(free<1)return null;const role=missingRoles[0]==='heal'?'healer':missingRoles[0];return {text:`Gathering for ${name}. ${free} spot${free===1?'':'s'} open; ${role?'we could use '+(role==='support'?'support':'a '+role)+'. ':''}A ${preferences.join(' or ')} would help the class mix.`,topic:'party',partyId:party.id,missingRoles:missingRoles.map(r=>r==='heal'?'healer':r),classPreferences:[...preferences],...metadata,provenance:{policy:'ENGINE-CHOSEN absent-class/learned-role preference; no required class claim',source:metadata.event?'native placed officer, event registration window/bands and actual owned tickets':'native placed ordinary entrance, complete authored floors/host inputs, levels/tickets/fees',sent:false}};};
 for(const o of npcEventOptions(world,p,now))if(o.window.phase==='register'&&Math.hypot(p.x-o.at.x,p.z-o.at.z)<=8&&members.every(q=>band(q,o.registrationLevel)&&band(q,o.entryLevel)&&owns(q,o.ticket))){const name=o.mode==='deadFront'?'Dead Front':'Ice Castle';return speech(name,7,{event:{mode:o.mode,map:o.map,officer:o.npc,ticket:o.ticket,registrationLevel:o.registrationLevel,entryLevel:o.entryLevel,window:o.window}});}
 const catalog=world.data.dungeonData,placed=world.data.progression?.npcs?.placements?.[p.map]?.rows||[];
 const candidates=Object.entries(catalog?.dg?.dungeons||{}).filter(([id,d])=>!id.startsWith('m')&&!FOREIGN_KEEPERS.has(d.keeper)&&!['SOLO','PARTYMATCH','GUILD'].includes(d.keeper)&&!d.solo?.pvpOnly&&!d.missingFloors?.length&&d.floors?.length&&d.floors.every(m=>supported(catalog.dg.maps[m])));
 candidates.sort(([a],[b])=>Number(b===String(brain.taskGoal?.dungeonId))-Number(a===String(brain.taskGoal?.dungeonId)));
 for(const[id,d]of candidates){const first=catalog.dg.maps[d.floors[0]],clear=first.stages?.clear?.kind,inputs=first.waves?.length&&first.files?.calls||first.static?.rows?.length&&first.files?.monsters||first.scriptSpawns?.length&&first.files?.npcs;
  // Unknown/borrowed/synthesized host flows do not become gathering promises.
  if(first.flags?.siege||d.keeper==='SQUARE'&&first.flags?.pvp||!['boss','all-waves','all-static'].includes(clear)||!inputs)continue;
  const entrance=d.entry?.npcs?.find(n=>Number(n.map)===p.map&&placed.some(r=>Number(r[0])===Number(n.npc)&&Math.hypot(Number(r[1])-Number(n.x),Number(r[2])-Number(n.y))<=1)&&Math.hypot(p.x-Number(n.x),p.z-Number(n.y))<=10);if(!entrance)continue;
  const maximum=Math.min(7,Number(d.party?.max)||7),minimum=Number(d.party?.min)||1;if(minimum>maximum||members.length>=maximum||!members.every(q=>band(q,d.entry.levels)&&(!d.entry.ticket?.item||owns(q,d.entry.ticket.item))))continue;
  const greeting=catalog.dialogs?.npcs?.[entrance.npc]?.greeting||'',fee=Number(/Entry Fee:\s*([\d,]+)\s*dil/i.exec(greeting)?.[1]?.replaceAll(',',''))||0;
  if(!members.every(q=>Number(q.profile.dil||0)>=premiumDungeonFee(world,q.profile,fee)))continue;
  return speech(d.name||first.name,maximum,{dungeon:{id,map:Number(d.floors[0]),entrance:Number(entrance.npc),entranceMap:p.map,levels:d.entry.levels,ticket:d.entry.ticket?.item||null,fee,min:minimum,max:maximum}});
 }
 return null;
}
