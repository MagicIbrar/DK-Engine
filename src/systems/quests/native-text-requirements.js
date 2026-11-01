// Requirements omitted by the legacy journal importer. Evidence: original code-12
// journals and native item names.
// "show / must have" keeps the item; "necessary / required / bring" hands it in.
// Exact per-row guards prevent this compatibility layer applying to other data.
const rows = [
  [336, ['Required items', '1 Shattered Mysterious Pendant', '30 Slime Mucus'], [[990153,1,'Shattered Mysterious Pendant'],[54360,30,'Slime Mucus']], true],
  [338, ['Required items', "5 Maneuver's Magic Crystal", '1 Dragon Scale'], [[990152,1,'Mysterious Pendant'],[54362,5,"Maneuver's Magic Crystal"],[980147,1,'Dragon Scale']], true],
  [1807, ['show 20 Dragon Bones', 'items must be in your Inventory'], [[54371,20,'Dragon Bone']], false],
  [1827, ['must have 10 Dravice Normal Artifact'], [[54365,10,'Dravice Normal Artifact']], false],
  [2124, ['Necessary Item', "greatest fisherman of Dekaron's hat costume x1"], [[1760326,1,"Fisherman's Hat Costume"]], true],
  [2125, ['Necessary Item', 'Refined Dragon Incomplete Belt x1'], [[1911270,1,'Refined Dragon Incomplete Belt']], true],
  [2126, ['Necessary Item', 'One of the Strengthened Ignis/Acuanic/Darkness belts'], [[[1911271,1911282,1911293],1,['Strengthened Ignis Belt','Strengthened Aquanic Belt','Strengthened Darkness Belt']]], true],
  [3282, ["Take Helmut's letter"], [[6209,1,"Helmut's Letter"]], true],
  // Singular item with no numeric count: ENGINE-CHOSEN literal one, not a made-up grind.
  [7411, ['Intermediate Grade Raw Mazoram'], [[6153,1,'Intermediate Grade Raw Mazoram']], true],
  [7421, ['High Grade Raw Mazoram'], [[6152,1,'High Grade Raw Mazoram']], true],
  [7431, ['Highest Grade Raw Mazoram'], [[6151,1,'Highest Grade Raw Mazoram']], true],
  [15707, ['10 Traces of Dekaron Fisherman'], [[1602807,10,'Trace of Dekaron Fisherman']], true],
  [15708, ['a Trace of Dekaron Fisherman'], [[1602807,1,'Trace of Dekaron Fisherman']], true],
  [15903, ['100 Monster Heart'], [[1601566,100,'Monster Heart']], true],
];
const strip = value => String(value || '').replace(/<[^>]*>/g,'').replace(/\s+/g,' ');
export function nativeTextRequirements(catalogue, dialogs, game) {
  const quests = {...catalogue.quests}, definition = id => game?.items?.db?.def?.(id) || game?.items?.def?.(id);
  for (const [id,cues,items,take] of rows) {
    const q=quests[id], journal=strip(dialogs?.strings?.[id]?.[12]);
    if (!q || q.objectives?.length || !q.rewards || !cues.every(cue=>journal.includes(cue))) continue;
    const valid=items.every(([ids,,names])=>(Array.isArray(ids)?ids:[ids]).every((id,i)=>definition(id)?.name===(Array.isArray(names)?names[i]:names)));
    const required=items.map(([item,count])=>({item,count}));
    quests[id]={...q,require:{...q.require,...(valid?{items:required}:{unavailable:1050}),...(id===15903?{missingItemsCode:101}:{})},rewards:{...q.rewards,...(valid&&take?{take:required}:{})},recoveredRequirements:'native-journal-20261013'};
  }
  const donation=quests[4151], texts=dialogs?.strings?.[4151];
  if(donation && ['1,000','5,000','10,000'].every((n,i)=>String(texts?.[12000+i*1000]).includes(n)))
    quests[4151]={...donation,require:{...donation.require,dil:1000,missingDilPage:16000},rewards:{...donation.rewards,donationTiers:[10000,5000,1000]},recoveredRequirements:'native-donation-pages; ENGINE-CHOSEN highest affordable bracket'};
  // The bartender's drinking games (beer, wine, rum) end when the drinker passes out; no original table holds that
  // per-drink rule, so none of them can produce an earned glass count. 8055 needs a Halloween Ring and Snowflake I
  // emblem that have no item row, from exchanges no Karin/Wingo job lists.
  const closed=[[4141,'Rewards for 11 glasses',null,'native beer drinking game: no per-glass result in the original data'],[4143,'consume 11 bottles',null,'native wine drinking game: no per-bottle result in the original data'],[4181,'Wine bottle needed for quest issuance',17000,'native rum drinking game: no per-bottle result in the original data'],[8055,'Obtain Halloween Ring',null,'Halloween Ring / Snowflake I have no item row; no Karin or Wingo job offers their exchange']];
  for(const [id,cue,page,why] of closed) {
    const q=quests[id];if(q&&strip(dialogs?.strings?.[id]?.[12]).includes(cue))
      quests[id]={...q,require:{...q.require,unavailable:1050,...(page?{unavailablePage:page}:{})},recoveredRequirements:why};
  }
  for(const id of [12701,12703,12705,12715,12717,12719,12721,12723,12725,12727,12729,12733,12735,12741,12743,12745,12747]){
    const q=quests[id];
    if(q&&strip(dialogs?.strings?.[id]?.[12]).includes('Dekaron 6-Year Anniversary')&&q.objectives?.some(o=>o.count===100))
      quests[id]={...q,require:{...q.require,unavailable:1027},recoveredRequirements:'native 2013 anniversary without event tokens; native event-ended refusal'};
  }
  const missingRows=[[5420,"Magimata's Fire",1050],[2067,'Defeat Egutt Roadkunda',1050],[8059,'Remove Dravicefield Watcher',1050],[8060,'Remove Hell Gatekeeper',1050],[920,'Rage Burst',1027],[921,'Warden Defeat',1027],[923,'Egg Cracking',1027],[1079,'Soccer Ball',1027],[15946,'Monster Gnawing the World Tree',1027],[15992,'Duex Marble',1027],[15995,'Hell Herold',1027]];
  for(const[id,label,code]of missingRows){const q=quests[id];if(q?.objectives?.some(o=>o.kind==='scripted'&&o.label===label))quests[id]={...q,require:{...q.require,unavailable:code},recoveredRequirements:'native target absent from the original data; native unavailable refusal'};}
  // 12 Gods offerings: the Tear items and earrings exist, but no drop, box or shop issues a Tear, the sacrificial
  // monsters have no spawn row and the event NPCs no placement. Every row is matched by its journal, not its
  // translated objective label (which varies per row).
  for(let id=8021;id<=8052;id++){
    if(id>8032&&id<8041)continue;const q=quests[id],journal=strip(dialogs?.strings?.[id]?.[12]);
    if(q?.objectives?.some(o=>o.kind==='scripted'&&o.slot===1&&o.count===12&&/tears?\b/i.test(o.label))&&/sacrific/i.test(journal)&&journal.includes('12 Tears of '))quests[id]={...q,require:{...q.require,unavailable:1027},recoveredRequirements:'12 Gods event: no native producer for the Tear items; event NPCs unplaced'};
  }
  // Event rows whose earned outcome cannot exist in the original data: the 2015 Easter egg fragment has no item row,
  // and Santa Karon (the Rudolph target) has no spawn or call row on any map. Arcadia North: no North Harbour /
  // Avaloha map, no Mega Manis monster and no placement for Elia or Karia.
  const ended=[[1082,1027,'Mysterious Egg Fragment',o=>o.kind==='killOnMap','Easter event: the reward fragment has no item row'],
    ...[15848,15849,15850,15851].map(id=>[id,1027,'Santa Karon',o=>o.kind==='kill'&&o.targets?.some(t=>Number(t.id)===2228),'Christmas event: Santa Karon has no spawn or call row']),
    [8915,1050,'North Harbour',o=>o.kind==='scripted'&&o.label==='Take the Avaroha','Arcadia North content absent from the original data'],
    [8916,1050,'Mega Manis',o=>o.kind==='scripted'&&o.label==='mega manes','Arcadia North content absent from the original data']];
  for(const[id,code,cue,objective,why]of ended){const q=quests[id];if(q&&strip(dialogs?.strings?.[id]?.[12]).includes(cue)&&q.objectives?.some(objective))quests[id]={...q,require:{...q.require,unavailable:code},recoveredRequirements:why};}
  return {...catalogue,quests};
}
