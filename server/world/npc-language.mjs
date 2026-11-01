// ENGINE-CHOSEN deterministic language rules. Understand supported requests,
// questions and negations; unrecognized text remains an honest clarification.
export function normalizeNpcText(value){return String(value||'').normalize('NFKC').toLowerCase().replace(/[’‘]/g,"'").replace(/\bdon't\b/g,'do not').replace(/\bdont\b/g,'do not').replace(/\bcan't\b/g,'cannot').replace(/\bu\b/g,'you').replace(/\bur\b/g,'your').replace(/\br\b/g,'are').replace(/\bpls?\b/g,'please').replace(/\bwanna\b/g,'want to').replace(/\btryna\b/g,'trying to').replace(/\by'?all\b/g,'you all').replace(/\brn\b/g,'right now').replace(/\bidk\b/g,'i do not know').replace(/\bim\b/g,'i am').replace(/\byoure\b/g,'you are').replace(/\s+/g,' ').trim();}
// A bounded question topic only; no party, travel or event admission request.
export function npcEventRunQuestion(value){return typeof value==='string'&&value.length<=500&&/^(?:do you )?want to run df[.!? ]*$/.test(normalizeNpcText(value));}
export function npcPartyRecruitment(value){const text=normalizeNpcText(value);return /^(?:(?:party|pt|pty)(?: me)?|lfp|lfm)[!? .]*$|\b(?:anyone|anybody|any of you|you guys)\b.{0,40}\b(?:party|group|team|join)|\b(?:lfp|lfm|looking for (?:a )?(?:party|group|members)|lf (?:seg|segnale|healer|tank|dps|dd|mage|summy|bagi|hunter)|need (?:a )?(?:healer|segnale|seg|tank|dps))\b|\b(?:can|could|may) i join\b|\b(?:party|group) up\b|\b(?:invite|inv|pt|pty) me\b/i.test(text)&&! /\b(?:do not|no|not|decline|rather not)\b.{0,22}\b(?:party|group|invite|inv|pt|pty|lfp|lfm)\b/.test(text);}
export function npcSentenceIntent(value){
 const text=normalizeNpcText(value);
 if(npcEventRunQuestion(value))return 'dungeon';
 if(/^(?:let'?s go|lets go|come on|come with us|get up(?: and (?:come|follow))?|follow us|come along)[!? .]*$/.test(text))return 'follow';
 const short=text.replace(/[.!?]+$/,'').trim();
 const lingo={lfp:'party',lfm:'party','pt me':'party','pty me':'party','inv me':'party',gg:'friend',gz:'friend',gratz:'friend',wp:'friend',brb:'time',afk:'time',omw:'time',oom:'potion',pots:'potion',ty:'thanks',thx:'thanks',sry:'apology',mb:'apology'};
 if(Object.hasOwn(lingo,short))return lingo[short];
 const shorthand={pt:'party',pty:'party',party:'party',group:'party',invite:'party',df:'dungeon',dung:'dungeon',dungeon:'dungeon',crespo:'dungeon',loa:'location',ardecca:'location',ardeca:'location',lvl:'level',lv:'level',level:'level',q:'quest',quest:'quest',quests:'quest',gear:'gear',rings:'gear',armor:'gear',armour:'gear',weapon:'gear',buff:'prepare',buffs:'prepare',ready:'prepare',heal:'potion',mana:'potion',hp:'potion',mp:'potion',hi:'hello',hey:'hello',yo:'hello',hello:'hello',sup:'wellbeing',follow:'follow',wait:'stop',stop:'stop',stay:'stop',lure:'lure',pull:'lure',solo:'roam',farm:'grind',farming:'grind',pk:'pvp',pvp:'pvp',duel:'pvp',trade:'trade',class:'class',where:'location',why:'continue',how:'continue'};
 if(Object.hasOwn(shorthand,short))return shorthand[short];
 if(/\b(?:do not|never|no need to)\s+(?:stop|quit)\s+(?:following|follow)/.test(text))return 'follow';
 if(/\b(?:do not|stop|quit)\s+(?:following|follow)|\bleave me alone|\bwait (?:right |over )?here|\bstay (?:right |over )?here/.test(text))return 'stop';
 if(/\b(?:do not|no|not|decline|rather not)\b.{0,22}\b(?:party|group|invite|inv|pt|pty|lfp|lfm)|\b(?:solo|on my own)\b.*\b(?:please|thanks|for now)/.test(text))return 'decline';
 if(/\b(?:party|group)\b.{0,16}\b(?:loot|item setting|itemway|distribution)/.test(text))return 'loot';
 if(npcPartyRecruitment(text))return 'party';
 if(/\b(?:party size|party leader|group leader)\b|\bhow many\b.{0,20}\b(?:members|players)\b|\b(?:who is|who's)\b.{0,12}\b(?:leading|leader)\b/.test(text))return 'status';
 if(/\b(?:what|which)\b.{0,18}\b(?:weapon|armor|armour|rings|build|gear)|\b(?:what are you wearing|what are you using|your equipment)\b/.test(text))return 'gear';
 if(/\b(?:meet|meetup|gather|regroup)\b/.test(text)&&! /\b(?:fight|attack|pull)\b/.test(text))return 'time';
 if(/\b(?:selling|buying|shop|price|offer|wtb|wts|wtt|pricecheck)\b/.test(text))return 'trade';
 if(/\b(?:restock|low on pots|out of pots|need pots|recover|recovery)\b/.test(text))return 'potion';
 if(/\b(?:cooldown|combo|rotation)\b/.test(text))return 'skills';
 if(/\b(?:what|which)\s+(?:quest|mission|objective)|\bquest\b.*\b(?:working on|doing|on|have)|\b(?:working on|doing)\b.*\bquest\b/.test(text))return 'quest';
 if(/\b(?:what|how)\b.{0,30}\b(?:level|lvl)|\bwhat level are/.test(text))return 'level';
 if(/\b(?:what are you doing|what are you up to|what is your plan|are you busy|why are you .*slow)/.test(text))return 'status';
 if(/\b(?:what|which)\b.{0,20}\bclass|\bwhat do you play/.test(text))return 'class';
 if(/\b(?:where are|where do|which map|where.*going)/.test(text))return 'location';
 if(/\b(?:who are you|what is your name|are you (?:a bot|human|real))/.test(text))return 'identity';
 if(/\b(?:can|could|would|will) you\b.{0,35}\b(?:follow|come|join me)|\b(?:come|follow|keep up)\b.{0,24}\b(?:me|us|along)|\bstick (?:with|by) me|\b(?:farm|grind|hunt) with me/.test(text))return 'follow';
 if(/\b(?:can|could|would|will) you\b.{0,20}\b(?:buff|prepare)|\b(?:buff|buffs|prebuff)\b.{0,25}\b(?:up|before|please|timer)|\bget ready/.test(text))return 'prepare';
 if(/\b(?:can|could|would|will) you\b.{0,20}\b(?:pull|lure)|\b(?:pull|lure)\b.{0,22}\b(?:me|us|here|back|please)/.test(text))return 'lure';
 if(/\b(?:want to|can we|let us|let's|lets|join my|invite me|party up|group up|team up)\b.{0,25}\b(?:party|group|team)|\b(?:party|group|team)\s+(?:up|with me)|\binvite me|\bjoin my party/.test(text))return 'party';
 if(/^(?:yes|yeah|yep|sure|okay|ok|sounds good|go ahead|tell me more|why|how)[.!? ]*$/.test(text))return 'continue';
 return null;
}
