import {parseRewardText} from './reward-text.js';
const normalize = s => String(s||'').toLowerCase().replace(/<[^>]*>/g,'').replace(/[^a-z0-9]+/g,'');
const variants = s => {const k=normalize(s);return [k,normalize(s.replace(/\b(Scroll|Stone|Token|Coin)s\b/gi,'$1')),...(k.endsWith('ies')?[k.slice(0,-3)+'y']:[]),...(k.endsWith('es')?[k.slice(0,-2)]:[]),...(k.endsWith('s')?[k.slice(0,-1)]:[])];};
// Only these translated aliases have a source identity: box contents, item
// descriptions or matching admission requirements. They are not fuzzy search.
const aliases = [
  [[2023,2024,2025,2026,2027,2083,2085,2086],/^DK Guardian(?:'s|’s)? Token$/,8934,"DK Guardian's Proof",'box 1754402 contains 8934'],
  [[2122,2124],/^Broken Dragon's Scale$/,4002263,"Broken Dragon's Scales",'item description: fishing quest reward'],
  [[1497],/^Moon Piece$/,1601351,'Moon Fragment','box1192598; same expiry'],
  [[4147],/^Knowledge Drinks: Item for quest issuance$/,3919,'Knowledge Wine','item description: Endless Debate issuance'],
  [[4151],/^\[First Challenge\] Ticket: Quest Admission Item$/,3929,'First Letter of Challenge','quest4153 admission item'],
  [[4141],/^Empty Beer Barrel$/,3943,'Empty Beer Bottle','item description: beer contest prize'],
  [[15903],/^Bebero's Choco Snack$/,1601565,"Bebero's Chocolate Cookie",'item description: crops raised by Bebero'],
  [[4221,4231],/^Dead Front Pass Exchange Tickets$/,6701,'Fortress Map Exchange Coupon','box2300372 contents'],
  [[12735],/^Elonohm Gold Box$/,1600106,'Ellonom Gold Box','same original box identity'],
  [[15717],/^Rudolph's Sled \(\*{6}\) 14 Days Ex-Box$/,1194247,'Rudolph Sled (******) 14D Ex-Box','original box1194247 holds1761690'],
  [[1067],/^DK Attendance Stamp$/,1600993,'DK Square Attendance Stamp','native Square attendance item identity'],
  [[3871,3873],/^Mana Stones: Allow you to enter Mana Crevice\.$/,3891,'Mana Stone','literal base item c4 stack10'],
  [[10086],/^Mediel \+55$/,6399,'Medial 55','native Medial55 identity; journal typo'],
  [[15848,15849,15850,15851],/^Rudolph Lucky Box$/,1193723,"Rudolph's Lucky Box",'same Rudolph event box; possessive spelling only'],
  [[18028],/^Your Legend \(Binded Tome\)$/,2300871,'Your Legend (Bind Tome)','native Your Legend tome series 2300869-2300871'],
  [[4181],/^Knowledge Drink 1$/,3919,'Knowledge Wine',"same bartender's Knowledge Drink as quest 4147"],
  [[4472],/^Quantity Heath Potions and$/,3807,'Quantity Health Potion','journal typo; listed with Quantity Mana Potion'],
  // Two native rows carry each scroll name; the lowest index is the base row, as preparation resolves duplicate names.
  [[10086],/^Scrolls of Vitality$/,56562,'Scroll of Vitality','base row of the duplicated scroll name'],
  [[10086],/^Scrolls of Patience$/,56563,'Scroll of Patience','base row of the duplicated scroll name'],
];
// One journal line naming several native items (same Marvric series, journal spelling "Mavric"/"Pass").
const splits = [
  [[4801],/^Pass Mavric, 1 Nium Mavric, and 1 Tatum Mavric$/,[[9904,'Pess Marvric'],[9905,'Nium Marvric'],[9906,'Tatum Marvric']]],
];
// Quest 9755 prints "1 Wedding Box (2 hours)"; the native box exists once per class. Literal reading: the box of
// the claiming class. A class without a native box keeps the unresolved line (nothing manufactured).
const weddingBoxes = [[0,2300319,'Knight'],[1,2300320,'Hunter'],[2,2300321,'Magician'],[3,2300322,'Summorner'],[4,2300323,'Segnale'],[5,2300324,'Bagi'],[6,2300325,'Aloken'],[7,2300545,'D-Knight'],[8,2300972,'Shooter'],[9,2300328,'Wizard'],[10,2300326,'Conserra'],[11,2300327,'Segreaper'],[12,2300329,'Half Bagi']];
// Commission journals print ONE random reward in three native layouts: a "1 of following randomly given/distributed"
// header, a "1 random from the list" trailer, or a "Random Reward(receive 1 random from list)" header.
const randomLayouts = [
  /\nRandom Rewards?\s*\n1 of (?:the )?following randomly (?:given|distributed):?\s*\n([\s\S]+)$/i,
  /\nRandom Rewards?\s*\n([\s\S]+?)\n\s*1 random from the list\s*$/i,
  /\nRandom Reward\s*\n\s*\nRandom Reward\(receive 1 random from list\)\s*\n([\s\S]+)$/i,
];
export function nativeTextRewards(catalogue,dialogs,game){
  const db=game?.items?.db, all=db?.items; if(!all)return catalogue;
  const byName=new Map();for(const [id,def]of Object.entries(all)){const key=normalize(def.name);if(!key)continue;const list=byName.get(key)||[];list.push(Number(id));byName.set(key,list);}
  const resolve=name=>{
    const bound=/\(Bind\)\s*$/i.test(name),base=name.replace(/\s*\(.*?\)\s*$/,'');
    for(const key of [...variants(name),...variants(base)]){
      const ids=(byName.get(key)||[]).filter(id=>!bound||db.def(id)?.trade===0);
      if(ids.length===1)return ids[0];
    }
    // The journals print +21 Medial; the native item catalogue prints Medial 21.
    const medial=/^\+(\d+) Medial$/i.exec(name);
    if(medial){const ids=byName.get(normalize('Medial '+medial[1]));if(ids?.length===1)return ids[0];}
    return null;
  };
  const quests={...catalogue.quests};
  for(const q of Object.values(quests)){
    if(!q?.rewards?.fromText)continue;
    let reward={...q.rewards}, original=q.rewards.items||[];
    if([2081,2082,4141,4181,18048].includes(q.id)){
      let journal=dialogs?.strings?.[q.id]?.[12];
      // The only claimable Beer outcome requires all 11 mugs. The native journal
      // names this tier explicitly; no credits are invented for the absent mini-game.
      if(q.id===4141&&journal?.includes('Rewards for 11 glasses'))journal='<font=4>Reward</font>\n'+journal.split('Rewards for 11 glasses')[1];
      const parsed=parseRewardText(journal);
      if(parsed){reward={...reward,exp:parsed.exp,dil:parsed.dil,adv:parsed.adv,notes:[]};original=parsed.items.map(([count,text])=>({count:count??1,text}));}
    }
    const items=original.flatMap(it=>{
      if(Number.isSafeInteger(it.item)&&db.def(it.item))return [it];
      const split=splits.find(([quests,re,list])=>quests.includes(q.id)&&re.test(it.text||'')&&list.every(([id,name])=>db.def(id)?.name?.trim()===name));
      if(split)return split[2].map(([item,name])=>({count:it.count??1,text:name,item,recoveredFrom:'one journal line naming the native Marvric series'}));
      let item=resolve(it.text||''), evidence=item?'exact native name / plural':null;
      if(!item)for(const[quests,re,id,name,source]of aliases)if(quests.includes(q.id)&&re.test(it.text||'')&&db.def(id)?.name===name){item=id;evidence=source;break;}
      return [item?{...it,item,recoveredFrom:evidence}:it];
    });
    reward.items=items;quests[q.id]={...q,rewards:reward};
    if(q.id>=5004&&q.id<=5009&&db.def(7473)?.name==='Medal of Honor (100)'){
      const journal=String(dialogs?.strings?.[q.id]?.[12]||'').replace(/<[^>]*>/g,'');
      const count={5004:1,5005:3,5006:6,5007:2,5008:2,5009:6}[q.id];
      if(journal.includes(`Medal of Honor(100) ${count}x`)&&journal.includes('Lv. 170 or above : 30,530,688 EXP')){
        const medals=items.filter(it=>it.item!==7473&&!/^Medal of Honor\(100\)/.test(it.text||''));
        quests[q.id]={...q,rewards:{...reward,items:[...medals,{item:7473,count,recoveredFrom:'exact native Medal of Honor(100) journal'}],guildExp:{capLevel:170,exp:30530688},recoveredExperience:'170+ exact journal; lower levels ENGINE-CHOSEN same fraction of native level EXP'}};
      }
    }
  }
  // Native Helmut letter dialog is a class-specific choice, not all weapons in
  // the journal. Its terminal option IDs give the exact selection contract.
  const helmut=quests[3282];
  const weapons=[[0,20011,2432,'Colada'],[0,20012,2479,'Kalladvolk'],[0,20021,2682,'Asterope'],[0,20022,2729,'Asura Blinger'],[0,20031,2582,'Seetooth'],[0,20032,2629,'Bash Crash'],[1,21001,2412,'Sheddar'],[1,21002,2882,'Glaciers'],[1,21003,2932,'Primal Fear'],[2,22001,2982,'Sadakvia'],[2,22002,3032,'Sheriark'],[3,23001,2532,'Apocripa'],[3,23002,3032,'Sheriark'],[4,24001,3132,'Belorum'],[5,25001,3212,'Smilothon'],[6,26001,45349,'Asatears']];
  if(helmut?.dialog?.file==='share/quest/quest_03282_dream_of_helmut.csv'&&weapons.every(([,option,item,name])=>String(dialogs?.strings?.[3282]?.[option]||'').includes(name+'(')&&db.def(item)?.name?.trim()===name)){
    quests[3282]={...helmut,rewards:{...helmut.rewards,items:[]},nativeChoicePages:{0:20000,1:21000,2:22000,3:23000,4:24000,5:25000,6:26000},rewardVariants:{mode:'choice',list:weapons.map(([classIndex,option,item])=>({classIndex,option,reward:{items:[{item,count:1}]}}))}};
  }
  for(const[id,prefix,start,dil]of [[7411,'Turncoat',65114,58826],[7421,'Est',65121,76680],[7431,'Ruffian',65128,105152]]){
    const q=quests[id],text=String(dialogs?.strings?.[id]?.[12]||'').replace(/<[^>]*>/g,'');
    if(!q||!text.includes('Random Reward')||!text.includes(dil.toLocaleString('en-US')+' DIL'))continue;
    if(!['Bordeaux','Quartz','Spinel','Lazuli'].every((n,i)=>db.def(start+i)?.name?.trim()===`${prefix} ${n}`))continue;
    quests[id]={...q,rewards:{...q.rewards,dil:0,items:[],randomRewards:[{dil,items:[]},...[0,1,2,3].map(i=>({dil:0,items:[{item:start+i,count:1}]}))],randomRewardPolicy:'ENGINE-CHOSEN equal weights for five journal alternatives; original probabilities absent'}};
  }
  for(const[id,coin,file]of [[511,6804,'share/quest/quest_00511_daily_warrior_proof.csv'],[513,6805,'share/quest/quest_00513_daily_fighter_proof.csv']]){
    const q=quests[id],text=String(dialogs?.strings?.[id]?.[12]||'').replace(/<[^>]*>/g,'');
    const letter=id===511?'B':'P';
    if(q?.dialog?.file!==file||normalize(db.def(coin)?.name)!==normalize(letter+' Coin'))continue;
    const bands=[...text.matchAll(/(\d+)\s*~\s*(\d+)\s*\(Rank [A-Z]\)?\s*:\s*(\d+) ([BP]) Coins/g)];
    if(bands.length!==7||bands.some(m=>m[4]!==letter))continue;
    quests[id]={...q,rewards:{...q.rewards,items:[]},rewardVariants:{mode:'level',list:bands.map(m=>({level:[Number(m[1]),Number(m[2])],reward:{items:[{item:coin,count:Number(m[3])}]}})),recoveredFromReward:'exact native journal level bands; no extrapolation outside 76–200'}};
  }
  const wedding=quests[9755],weddingText=String(dialogs?.strings?.[9755]?.[12]||'').replace(/<[^>]*>/g,'');
  if(wedding?.dialog?.file==='share/quest/quest_09755_wedding_daily.csv'&&/^1 Wedding Box \(2 hours\)$/m.test(weddingText)&&weddingBoxes.every(([,id,cls])=>db.def(id)?.name?.trim()===`Wedding Box (2 Hours) (${cls})`))
    quests[9755]={...wedding,rewardVariants:{mode:'class',list:weddingBoxes.map(([classIndex,item])=>({classIndex,reward:{items:[{item,count:1,recoveredFrom:'native class Wedding Box (2 Hours)'}]}})),recoveredFromReward:'one native box per class; classes without a box keep the unresolved line'}};
  // Commission journals explicitly say ONE random reward. Keep guaranteed rewards in every alternative. Every printed
  // alternative keeps its own equal share; one whose item has no native identity stays in the list as text, so drawing
  // it grants only the guaranteed part (the claim reports the skipped line). The client omits the original weights.
  for(const q of Object.values(quests)){
    if(!q.rewards?.fromText||!/^share\/quest\/request_/.test(q.dialog?.file||''))continue;
    const journal=String(dialogs?.strings?.[q.id]?.[12]||''),plain=journal.replace(/<[^>]*>/g,'');
    let split=null;for(const layout of randomLayouts)if((split=plain.match(layout)))break;
    if(!split)continue;
    const lines=split[1].split('\n').map(x=>x.trim()).filter(Boolean),alternatives=[];
    // Reuse the identity preparation already gave a printed name (duplicate names resolve to the base row there).
    const prepared=new Map((q.rewards.items||[]).filter(it=>Number.isSafeInteger(it.item)&&db.def(it.item)&&it.text).map(it=>[normalize(it.text),it.item]));
    const named=(count,name)=>{const item=prepared.get(normalize(name))??resolve(name);return item?{item,count:count??1}:{count:count??1,text:name};};
    for(const line of lines){
      const parsed=parseRewardText('<font=4>Reward</font>\n'+line);
      if(!parsed)break;
      const items=parsed.items.map(([count,name])=>named(count,name));
      if([parsed.dil,parsed.exp,parsed.adv,items.length].filter(Boolean).length!==1||items.length>1)break;
      alternatives.push({dil:parsed.dil,exp:parsed.exp,adv:parsed.adv,items});
    }
    if(alternatives.length!==lines.length||alternatives.length<2)continue;
    const fixed=parseRewardText(plain.slice(0,split.index));
    if(!fixed)continue;
    const guaranteed=fixed.items.map(([count,name])=>named(count,name));
    const missing=alternatives.some(r=>r.items.some(it=>!it.item));
    // A random scalar augments the guaranteed scalar rather than replacing it.
    quests[q.id]={...q,rewards:{...q.rewards,exp:fixed.exp,dil:fixed.dil,adv:fixed.adv,items:guaranteed,notes:[],randomRewards:alternatives.map(r=>({...r,items:[...guaranteed,...r.items],exp:fixed.exp+r.exp,dil:fixed.dil+r.dil,adv:fixed.adv+r.adv})),randomRewardPolicy:missing?'ENGINE-CHOSEN equal weights for the printed alternatives; an alternative without a native item keeps its share and grants only the guaranteed part; original probabilities absent':'ENGINE-CHOSEN equal weights for exact journal alternatives; original probabilities absent'}};
  }
  return {...catalogue,quests};
}
