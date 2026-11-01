import {normalizeNpcText} from './npc-language.mjs';

// ENGINE-CHOSEN finite speech cues. No action, inventory assumption, external
// model or consent authority. The director still selects audience and pacing.
export function npcConversationCue(value){
 if(typeof value!=='string'||value.length>500)return null;
 const text=normalizeNpcText(value).replace(/[.!?]+$/,'').trim();
 // Keep the established explicit stop-following and double-negative rules.
 // Other negative action requests acknowledge restraint without stopping jobs.
 if(/\b(?:do not|never|no need to|please not)\b.{0,24}\b(?:pull|lure|buff|prepare|cast|attack|fight|invite|trade)\b/.test(text)||/\b(?:can|could|would|will) you not\b.{0,20}\b(?:pull|lure|buff|prepare|cast|attack|fight|follow|invite|trade)\b/.test(text))return {intent:'continue',kind:'restraint',reply:'Alright, leaving that alone.'};
 if(/^(?:what|huh|wdym|what do you mean|what was that|say that again|come again)$/.test(text))return {intent:'continue',kind:'clarify'};
 if(/^(?:(?:do you|you) )?(?:need|want) anything(?: (?:for your run|for the run|right now))?$/.test(text))return {intent:'trade',kind:'item-offer',reply:'What item? Link it or put it in trade so I can check.'};
 if(/^(?:(?:i have|i got|i've got|got) )?(?:some |a |an )?spare (?:items?|gear|equipment|weapons?|armor|armour|pots?|potions?)(?: (?:for you|if you want|you want it))?$/.test(text))return {intent:'trade',kind:'item-offer',reply:'Thanks, what have you got? Link it?'};
 return null;
}
