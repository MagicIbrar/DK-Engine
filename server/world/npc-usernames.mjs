import {normalizeCharacterName,characterNameKey} from '../../src/game/character-name.js';

// ENGINE-CHOSEN gamer/person handles. Existing server validation admits 3–12;
// no claim that the untouched Global server minimum was recovered from its UI.
export const NPC_USERNAME_POLICY=Object.freeze({version:2,min:3,max:12,digitFraction:.2});
const bases=('Fade Flux Ace Nova Zero Jett Echo Mako Kai Mira Milo Luna Nico Finn Liam Evan Noah Alex Adam Aiden Aaron Alec Alan Andy Arlo Avery Blake Ben Bobby Brad Brett Brian Bryce Caleb Cam Carter Casey Chase Chris Cody Cole Colin Connor Corey Cruz Dale Dan Danny Dean Derek Drew Dylan Eli Elias Eric Ethan Ezra Felix Gabe Gavin George Gray Harper Hayden Henry Hugo Hunter Ian Isaac Jack Jake Jamie James Jay Jesse Joel Jordan Josh Jude Julian Justin Kane Kian Kit Kyle Leo Levi Logan Lou Luca Luke Max Micah Miles Morgan Nate Neil Nick Nolan Ollie Omar Owen Parker Pat Peter Quinn Ray Reed Reese Riley Robin Rory Rowan Ryan Sam Sean Seth Shane Shay Simon Sky Sonny Taylor Theo Toby Trent Troy Tyler Vince Wade Will Wyatt Xander Zeke Zoe Abby Amy Anna Aria Ava Bella Beth Brooke Cara Chloe Clara Cora Daisy Dani Ella Ellie Emma Eva Grace Gwen Hailey Holly Hope Iris Isla Ivy Jade Jane Jess Jules June Kate Katie Kira Lana Leah Lexi Lily Liv Lola Lucy Mae Maya Mia Nina Nora Olive Paige Poppy Rae Rose Ruby Sage Sara Skye Sophie Stella Tess Tori Vera Wren Zara Axel Boost Clutch Dash Drift Edge Fast Faze Frost Ghost Glitch Haze Hex Icon Ink Jinx Link Loop Lucky Lynx Mint Mist Neon Onyx Orbit Pace Peak Pixel Pulse Quest Rain Raze Riot Rogue Rush Scout Shift Silk Slate Snip Spark Steel Sync Toast Trace Tune Valor Vex Volt Wave Wick Wisp Wolf Zen').split(' ');
const styles=[n=>n,n=>n+'J',n=>n+'K',n=>'x'+n,n=>n+'R',n=>n+'T',n=>n+'GG',n=>n+'S',n=>n+'M',n=>n+'V',n=>n+'TV',n=>n+'D',n=>n+'H',n=>n+'B',n=>n+'FPS',n=>n+'L',n=>n+'P',n=>n+'AFK',n=>n+'C',n=>n+'W',n=>n+'IRL',n=>n+'N',n=>n+'HD',n=>n+'A'];
const legal=n=>/^[A-Za-z][A-Za-z0-9]{2,11}$/.test(n)&&normalizeCharacterName(n)===n;
const unique=values=>{const seen=new Set();return values.filter(n=>{const k=characterNameKey(n);if(!legal(n)||seen.has(k))return false;seen.add(k);return true;});};
const letters=unique(styles.flatMap((style,i)=>bases.map((base,j)=>{const n=style(base);return (i+j)%5===2?n.toLowerCase():(i+j)%11===7?n.toUpperCase():n;})));
const digits=unique(['7','17','23','28','42','77','90','99','101','420'].flatMap((suffix,i)=>bases.map((base,j)=>(i+j)%3===1?base.toLowerCase()+suffix:base+suffix)));
const pool=[];for(let n=0;n<Math.min(Math.floor(letters.length/4),digits.length);n++)pool.push(...letters.slice(n*4,n*4+4),digits[n]);Object.freeze(pool);
const poolKeys=new Set(pool.map(characterNameKey));
export function npcGeneratedUsername(name){return typeof name==='string'&&poolKeys.has(characterNameKey(name))&&legal(name);}
export function npcUsername(serial,used=new Set()){
 const taken=new Set([...used].map(characterNameKey)),start=Number.isFinite(serial)?Math.max(0,Math.floor(serial)):0;
 for(let n=0;n<pool.length;n++){const name=pool[(start+n)%pool.length];if(!taken.has(characterNameKey(name)))return name;}
 throw Error('No distinct NPC gamer handle is available.');
}
const oldHandles='Moonlit AshenBlade Velvet Frostbite Kael Mira Rynn Sable Lumi Orin Ember Zane Iris Voss Mako Eira Jori Kira Bryn Rune Ravenfall Afterglow Duskborn Solstice Silverleaf Wildheart Rainfall Nightbloom Cinder Zephyr Thorn Echo'.split(' '),oldSuffixes=['','Shade','Sky','Rose','Mist','Flame','Gale','Vale','Song','Dawn','Moon','Star','Tide','Wren','Wolf','Fox','Reed','Oak','Frost','Bloom','Stone','Dusk','Light','Leaf','Heart','Wing','Wind','Ash','Rain','Snow','Rune','Blade'],oldEndings=['','a','en','ia','in','is','on','ra'],oldStarts='Amber Ash Birch Blue Bright Cedar Cloud Copper Dawn Deep Ember Frost Gold Grey Hazel Iron Jade Juniper Lake Maple Moon Night Oak Pine Rain Red River Silver Snow Star Stone Sun'.split(' '),oldEnds='bloom brook crest fall fern field flame flight forge gale garden grove hollow leaf light meadow mist moth path peak pine reed ridge shade song spring stream thorn trail vale wind wood'.split(' '),familiar=new Set(oldHandles.map(characterNameKey));
const tails=new Set(oldSuffixes.flatMap(s=>oldEndings.map(e=>(s+e).toLowerCase()))),dormantTails=new Set(oldEnds.flatMap(s=>oldEndings.map(e=>s+e)));
export function npcLegacyGeneratedName(name){
 if(typeof name!=='string'||!/^[A-Za-z]{4,10}$/.test(name)||familiar.has(characterNameKey(name)))return false;const lower=name.toLowerCase();
 return oldHandles.some(h=>lower.startsWith(h.toLowerCase())&&tails.has(lower.slice(h.length)))||oldStarts.some(h=>lower.startsWith(h.toLowerCase())&&dormantTails.has(lower.slice(h.length)));
}
/** Reviewable proposal only. An unmarked custom name matching the legacy pool
 * cannot be proven generated, so verified IDs/generation provenance are needed.
 * Root applies through its offline canonical migration transaction, never here. */
export function npcUsernameMigrationEligible(account,p,{confirmedLegacyIds=new Set(),preserveNames=new Set()}={}){
 const marked=p?.npcNameSource==='generated-v1'||confirmedLegacyIds.has(account)||confirmedLegacyIds.has(p?.id)||confirmedLegacyIds.has(p?.npcRosterId),keep=new Set([...preserveNames].map(characterNameKey));
 if(!/^npc_[a-f0-9]{32}$/.test(account)||p?.authority!=='server'||p.npcPlayer!==true||!p.id||!(p.npcSeed||p.npcRosterId)||p.npcNameCustom===true||p.npcCustomName===true||keep.has(characterNameKey(p.name))||!marked||!npcLegacyGeneratedName(p.name))return false;
 return true;
}
export function proposeNpcUsernameMigration({profiles,usedNames=new Set(),preserveNames=new Set(),confirmedLegacyIds=new Set()}={}){
 if(!(profiles instanceof Map)||profiles.size>2500)throw Error('Canonical NPC profiles are required.');
 const used=new Set([...usedNames,...[...profiles.values()].map(p=>p.name)].map(characterNameKey)),keep=new Set([...preserveNames].map(characterNameKey)),changes=[],preserved=[];let serial=0;
 for(const[account,p]of profiles){
  if(!npcUsernameMigrationEligible(account,p,{confirmedLegacyIds,preserveNames:keep})){preserved.push({id:p?.id,reason:'familiar/custom/unproven/nonNPC'});continue;}
  const name=npcUsername(serial++,used);used.add(characterNameKey(name));changes.push({account,characterId:p.id,npcRosterId:p.npcRosterId||null,oldName:p.name,name,npcNameSource:'generated-v2',requiresOffline:true});
 }
 return {version:2,requiresOffline:true,changes,preserved};
}
