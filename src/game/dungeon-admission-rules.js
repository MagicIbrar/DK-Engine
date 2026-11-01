// Costs in original entrance NPC text are mode-specific. Ticket=1 in
// dungeonlist is a sentinel, never an item ID. These selectors preserve the
// original shared-NPC sections rather than applying their first fee to all jobs.
const sectionSets={
 1208:[['33',/^-Rank A-$/i],['600',/^-Hard Mode-$/i]],
 1239:[['121',/^Karon's Fragments? \(Normal\)\s*:/i],['603',/^Karon's Fragments? \(Hard\)\s*:/i],['602',/^Karon's Fragments? \(Core\)\s*:/i]],
 1913:[['94',/^Shadow Shield$/i],['31',/^< Requirements - Magic Field of Crack >$/i],['34',/^< Requirements - Magic Field of Crack: Depth >$/i]],
 3601:[['607',/^Karon's Transport Ship\s*\(Fresh\) Expedition Crew$/i],['605',/^Karon's Transport Ship\s*\(Fresh\) Party$/i]],
 5273:[['176',/^\[Lv\..*\] Favnil Nest$/i],['151',/^< Conditions to Enter \/ Ruins of Baz>$/i],['152',/^< Conditions to Enter \/ Ruins of Rudene>$/i]],
 3308:[['176',/^\[Lv\..*\] Favnil Nest$/i],['151',/^< Conditions to Enter \/ Ruins of Baz>$/i],['152',/^< Conditions to Enter \/ Ruins of Rudene>$/i]],
 5266:[['180',/^\[Lv\..*\] Elleghos$/i],['614',/^\[Lv\..*\] Elleghos \[Time Attack\]$/i]],
 5992:[['263',/^\[ Solo Mode \]$/i],['234',/^\[ Normal Mode \]$/i],['250',/^\[ Hard Mode \]$/i]],
 5965:[['608',/^Undo Mazokie's Test \(Party\)$/i],['617',/^Undo Mazokie's Test$/i]],
};
const unavailable=()=>{throw Object.assign(Error('The original dungeon entrance cost is unavailable.'),{status:503});};
const plain=text=>String(text||'').replace(/<\/?(?:color|font)\b[^>]*>/gi,'');
function section(npc,id,greeting){
 const lines=plain(greeting).split(/\r?\n/).map(line=>line.trim()),selectors=sectionSets[npc];
 if(!selectors)return lines.join('\n');
 const wanted=selectors.find(([key])=>key===String(id));if(!wanted)unavailable();
 const start=lines.findIndex(line=>wanted[1].test(line));if(start<0)unavailable();
 let end=lines.length;
 for(let i=start+1;i<lines.length;i++)if(selectors.some(([,heading])=>heading.test(lines[i]))){end=i;break;}
 return lines.slice(start,end).join('\n');
}
const feePattern=/^\s*(?:(?:Entry|Entrance|Entering)\s+(?:Fee(?:\s+DIL)?|DIL)|(?:Required|Waste)\s+DIL|Fee|Price|DIL)\s*:\s*([\d,]+)(?:\s+DIL)?/gim;
/** Own native NPC only. Blank test entrances use this mode's public source,
 * while an authored original NPC with its own cost keeps its original text. */
function entranceSource(d,dialogs,npc){
 const placed=d.entry?.npcs||[],unplaced=d.entry?.unplacedNpcs||[],own=[...placed,...unplaced],selected=own.find(n=>Number(n.npc)===Number(npc));
 const informative=n=>/\bdil\b|ticket|entry cost/i.test(dialogs.npcs?.[n.npc]?.greeting||'');
 return selected&&informative(selected)?selected:placed.find(n=>Number(n.map)!==38&&informative(n))||own.find(informative)||selected||own[0]||null;
}
// Each binding is an explicitly named native requirement. Quest IDs are
// evidence for the exact issued item, not a rule that every NPC quest is needed.
const ticketBindings={
 121:{npc:1239,item:4002360,quest:263,require:/^Ticket: Karon's Fragment \(Normal\) Admission Ticket x1$/im},
 603:{npc:1239,item:4002361,quest:264,require:/^Ticket: Karon's Fragment \(Hard\) Admission Ticket x1$/im},
 176:{npc:5273,item:1700023,quest:281,require:/^Favnil Nest Entrance Ticket 1x$/im},
 249:{npc:5411,item:1700024,quest:261,require:/^Python Palace Entrance Ticket 1x$/im},
 180:{npc:5266,item:1700027,quest:271,require:/^Elleghos Entrance Ticket 1x$/im},
 181:{npc:5295,item:1700058,quest:372,require:/^Secret Passage Entrance Ticket 1x$/im},
 263:{npc:5992,item:4003081,quest:283,require:/^Entry Ticket: Forgotten Shipwreck Solo Entry Ticket$/im},
 153:{npc:5525,item:4000268,name:'Norak Secret Arena Admission Ticket',require:/^1 Norak Secret Arena Ticket$/im},
 154:{npc:4156,item:4002358,name:'[Cartel] Infinite battle admission ticket',require:/^\[Cartel\] Infinite battle admission ticket 1\.$/im},
 // NPC 4157 names no item ("The first entrance will pay the ticket."); it is the
 // same NPC whose job 57:272 issues this mode's own 3600 s ticket 4002359.
 155:{npc:4157,item:4002359,name:'Colosseum[Infitite battle] admission ticket',require:/^\(The first entrance will pay the ticket\.\)$/im},
 177:{npc:5236,item:1700024,name:'Python Castle Admission Ticket',require:/^1 Python Castle Ticket$/im},
 225:{npc:5734,item:4000420,quest:225,require:/^Nunvice Temple Entrance Ticket 1x$/im},
 227:{npc:5781,item:4000520,quest:201,require:/^Entrance Ticket : 1 Hall of Circulation Entrance Ticket$/im},
 230:{npc:1710,item:4002295,quest:472,require:/^Admission: 1 Karon's Transport Ship Solo Admission Ticket$/im},
 233:{npc:6034,item:4002330,quest:477,require:/^Santa Karon.s Gift Factory Admission Ticket$/im},
 244:{npc:6144,item:4002421,quest:484,require:/^1 ticket to the Scream Cave$/im},
 246:{npc:6159,item:4002484,quest:268,require:/^Mysterious Portal Ticket x1$/im},
 247:{npc:6161,item:1195010,quest:280,require:/^Deka Island Entry Ticket$/im},
 254:{npc:6190,item:1195273,name:'Deka Village Entry Ticket',require:/^Requirement: Deka Village Entry Ticket$/im},
 255:{npc:6190,item:1195273,name:'Deka Village Entry Ticket',require:/^Requirement: Deka Village Entry Ticket$/im},
 257:{npc:6200,item:1195359,quest:275,require:/^Entry Item: Road to Immortality Ticket$/im},
 259:{npc:6022,item:4003078,quest:279,require:/^Entry Requirement : Gniar's Library Entry Ticket$/im},
 260:{npc:6215,item:4003102,quest:285,require:/^Requirement: Forbidden Fetters Entry Ticket$/im},
 265:{npc:6107,item:4003082,quest:284,require:/^Entry Ticket : Hidden Mansion of Kastotica Solo Ticket x1$/im},
 617:{npc:5965,item:4002240,quest:467,require:/^1 entry ticket for Undo Mazokie's training$/im},
};
function explicitTicket(world,id,d,dialogs){
 const binding=ticketBindings[id];if(!binding)return null;
 if(![...(d.entry?.npcs||[]),...(d.entry?.unplacedNpcs||[])].some(n=>Number(n.npc)===binding.npc))unavailable();
 const text=section(binding.npc,id,dialogs.npcs?.[binding.npc]?.greeting);
 if(!binding.require.test(text))unavailable();
 const def=world.data.itemDB.def(binding.item);if(!def||Number(def.type)!==0||![4,5].includes(Number(def.code)))unavailable();
 if(binding.quest){const q=world.data.progression?.quests?.quests?.[binding.quest];if(Number(q?.rewards?.timedItem?.item)!==binding.item||Number(q?.giver?.npc)!==binding.npc)unavailable();}
 else if(def.name?.trim()!==binding.name)unavailable();
 return {items:[binding.item],count:1};
}
// Infinite Battle 2 entrance text: "Ticket : Infinite Battle 2 ticket or 2 Super
// Pass" (NPC 5358 for 534/535, NPC 5927 for Stardion 613). The in-game NPC
// count (2) and ticket name are kept over the item description/guide ("x5",
// Stardion "Infinite Battle1") per the owner. 5358 adds "First player to enter
// consumes the ticket" (payer:'first'); both say the ticket is consumed before
// passes. ENGINE CHOICE within a class: expiring 1-day ticket first, Premium
// tickets (benefits not modelled) after plain ones, bound Super Pass first.
const IB2_TICKETS=[[7372,'Infinite Battle 2 Ticket (1 Day)',521],[7371,'Infinite Battle 2 Ticket',521]];
const IB2_PREMIUM=[[1191833,'Premium Infinite Battle 2 Ticket',516],[1751977,'Premium Infinite Battle 2 Ticket',516],[1751984,'Premium Infinite Battle 2 Ticket x10',516],[2313715,'Premium Infinite Battle 2 Ticket x10',516]];
const IB2_TEXT={521:['Admission ticket to enter Infinite Battle 2','Available on all ranks in Infinite Battle 2.'],516:['Ticket required to enter Infinite Battle 2','Can be used in all Infinite Battle 2 Ranks.']};
const passBindings={
 534:{npc:5358,premium:true,payer:'first',require:[/^Ticket : Infinite Battle 2 ticket or 2 Super Pass$/im,/^\* First player to enter consumes the ticket\.$/im,/^\* The Infinite Battle 2 ticket will be consumed first\.$/im]},
 535:{npc:5358,premium:true,payer:'first',require:[/^Ticket : Infinite Battle 2 ticket or 2 Super Pass$/im,/^\* First player to enter consumes the ticket\.$/im,/^\* The Infinite Battle 2 ticket will be consumed first\.$/im]},
 // The Stardion text names the plain IB2 ticket; Premium descriptions are limited to IB2 ranks.
 613:{npc:5927,premium:false,require:[/^Ticket : Infinite Battle 2 ticket or 2 Super Pass$/im,/^\* The Infinite Battle ticket will be consumed first\.$/im]},
};
function superPasses(world){
 const ids=[4002293,7550];if(ids.some((index,k)=>world.data.itemDB.def(index)?.name!==['Super Pass (Bind)','Super Pass'][k]))unavailable();
 // The native ticket exchange reward cost explicitly treats these two IDs as
 // Super Pass alternatives; package/box items are never accepted as passes.
 const cost=world.data.progression?.quests?.quests?.[261]?.rewardVariants?.list?.find(row=>row.repeat===3)?.reward?.take?.[0];
 if(!ids.every(index=>cost?.item?.includes(index)))unavailable();
 return ids;
}
function passTicket(world,id,d,dialogs){
 const binding=passBindings[id];if(!binding)return null;
 if(![...(d.entry?.npcs||[]),...(d.entry?.unplacedNpcs||[])].some(n=>Number(n.npc)===binding.npc))unavailable();
 const text=section(binding.npc,id,dialogs.npcs?.[binding.npc]?.greeting);
 if(!binding.require.every(pattern=>pattern.test(text)))unavailable();
 const db=world.data.itemDB,tickets=[...IB2_TICKETS,...(binding.premium?IB2_PREMIUM:[])];
 for(const[index,name,desc]of tickets){
  const def=db.def(index),about=typeof db.description==='function'?db.description(def):'';
  if(!def||Number(def.type)!==0||Number(def.code)!==5||def.name?.trim()!==name||Number(def.desc)!==desc||!IB2_TEXT[desc].every(line=>about.includes(line)))unavailable();
 }
 return {items:tickets.map(([index])=>index),count:1,alternatives:[{items:superPasses(world),count:2}],...(binding.payer?{payer:binding.payer}:{})};
}
export function dungeonEntranceCosts(world,id,npc){
 const c=world.data.dungeonData,d=c.dg.dungeons[String(id)],source=entranceSource(d,c.dialogs,npc),text=source?section(source.npc,id,c.dialogs.npcs?.[source.npc]?.greeting):'';
 const fees=[...text.matchAll(feePattern)].map(match=>Number(match[1].replaceAll(',',''))),unique=[...new Set(fees)];if(unique.length>1||unique.some(fee=>!Number.isSafeInteger(fee)||fee<0))unavailable();
 const requirements=[],native=d.entry?.ticket?.item;if(native)requirements.push({items:[Number(native)],count:1});
 const ticket=explicitTicket(world,String(id),d,c.dialogs);if(ticket&&!requirements.some(r=>r.items.includes(ticket.items[0])))requirements.push(ticket);
 const pass=passTicket(world,String(id),d,c.dialogs);if(pass)requirements.push(pass);
 if(String(id)==='250'){
  const greeting=section(5992,id,c.dialogs.npcs?.[5992]?.greeting);if(!/^Entry Cost: Super Pass x3$/im.test(greeting))unavailable();
  const ids=[4002293,7550];if(ids.some(index=>!['Super Pass','Super Pass (Bind)'].includes(world.data.itemDB.def(index)?.name)))unavailable();
  // The native ticket exchange reward cost explicitly treats these two IDs as
  // Super Pass alternatives; package/box items are never accepted as passes.
  const cost=world.data.progression?.quests?.quests?.[261]?.rewardVariants?.list?.find(row=>row.repeat===3)?.reward?.take?.[0];
  if(!ids.every(index=>cost?.item?.includes(index)))unavailable();
  requirements.push({items:ids,count:3});
 }
 return {fee:unique[0]||0,requirements,sourceNpc:source?.npc||null};
}
/** The concrete {items,count} a payer uses for each requirement, in priority
 * order: the requirement itself, then its `alternatives`. A payer:'first'
 * requirement is paid only by the first player to enter. null = unmet. */
export function selectDungeonRequirements(count,requirements,{first=true}={}){
 const picks=[];
 for(const requirement of requirements){
  if(requirement.payer==='first'&&!first)continue;
  const pick=[requirement,...(requirement.alternatives||[])].find(option=>option.items.reduce((sum,index)=>sum+count(index),0)>=option.count);
  if(!pick)return null;picks.push({items:pick.items,count:pick.count});
 }
 return picks;
}
/** Called only on the staged profile: failed group admission cannot consume
 * any live player's ticket or DIL. Expired items never count as admission. */
export function consumeDungeonRequirements(inv,requirements,options){
 const picks=selectDungeonRequirements(index=>inv.count(index),requirements,options);if(!picks)return false;
 for(const requirement of picks){
  if(requirement.items.reduce((sum,index)=>sum+inv.count(index),0)<requirement.count)return false;
  let left=requirement.count;for(const index of requirement.items){const take=Math.min(left,inv.count(index));if(take&&!inv.remove(index,take))return false;left-=take;if(!left)break;}
 }
 return true;
}
