// ENGINE-CHOSEN presentation facets for scripted players, not native attributes,
// memories, expertise evidence, combat bonuses or authority. These helpers are
// pure: the caller supplies verified current facts and schedules ordinary chat.
const tiers=['bad','mid','good','insane'];
const domains=['quests','equipment','travel','parties','combat','trading','events'];
const hash=value=>{let h=2166136261;for(const c of String(value)){h^=c.codePointAt(0);h=Math.imul(h,16777619);}return h>>>0;};
const oneOf=(value,choices,fallback)=>choices.includes(value)?value:fallback;
const budget=value=>Number.isFinite(Number(value))?Math.max(0,Math.floor(Number(value))):250;
const signature=profile=>JSON.stringify([profile?.name||'',profile?.classIndex??null,profile?.npcSeed?.slot??null,profile?.npcSeed?.homeMap??profile?.npcSeed?.map??null]);

export function npcPersona(profile={}){
 const traits=profile.npcTraits||{},h=hash(signature(profile)),social=oneOf(traits.social,['social','solo','outlaw'],'social'),chat=oneOf(traits.chat,['quiet','relaxed','playful','funny','competitive','frustrated'],['quiet','relaxed','playful','competitive'][h%4]);
 const combatTier={novice:'bad',regular:'mid',expert:'good',elite:'insane'}[traits.pvpSkill];
 const knowledgeTier=oneOf(traits.knowledgeTier??traits.competence,tiers,combatTier||tiers[(h>>>4)%4]);
 const tone=chat==='quiet'?'reserved':chat==='competitive'?'direct':chat==='playful'||chat==='funny'?'playful':chat==='frustrated'?'dry':'warm';
 const interests=[];const goal=profile.npcSeed?.initialGoal;
 if(goal?.kind==='quest')interests.push('quests');else if(goal?.kind==='event')interests.push('events');
 if(traits.gear==='strong'||traits.gear==='balanced')interests.push('equipment');
 if(social==='social')interests.push('parties');else if(social==='outlaw')interests.push('combat');
 for(let n=0;interests.length<3&&n<domains.length;n++){const domain=domains[(h+n*3)%domains.length];if(social==='solo'&&domain==='parties')continue;if(!interests.includes(domain))interests.push(domain);}
 return {policy:'ENGINE-CHOSEN',social,chat,tone,socialEnergy:chat==='quiet'?'low':social==='solo'?'measured':'high',patience:chat==='competitive'?'brisk':chat==='quiet'||social==='solo'?'patient':'steady',confidence:knowledgeTier==='bad'?'tentative':knowledgeTier==='mid'?'measured':'confident',humor:chat==='quiet'?'none':chat==='playful'||chat==='funny'?'playful':chat==='frustrated'?'dry':'light',competence:knowledgeTier,knowledgeTier,combatSkill:traits.pvpSkill||'regular',interests,helpOpenness:knowledgeTier==='bad'?'readily':knowledgeTier==='mid'?'sometimes':'specific-blockers'};
}

function situation(context){
 if(context.dead===true)return 'dead';
 if(context.danger===true||context.inCombat===true)return 'danger';
 if(context.busy===true)return 'busy';
 if(context.recovering===true)return 'recovering';
 if(context.mood==='frustrated')return 'frustrated';
 return 'calm';
}
const acknowledgments={
 thanks:{reserved:'No problem.',warm:'Anytime.',playful:'Happy to help.',direct:'You got it.',dry:'No worries.'},
 apology:{reserved:'All good.',warm:'No worries.',playful:'We are good.',direct:'Alright, regroup.',dry:'It happens.'}
};

/** Preserve factual payloads verbatim. maxLength limits optional presentation;
 * an oversized original is returned intact for the caller's existing chunking
 * policy rather than silently clipping a native name, number or command.
 * memory is read-only and optional: personaRecent can suppress repeated lead-ins.
 */
export function npcPersonaSpeech(text,{profile={},context={},memory={},topic='',maxLength=250}={}){
 const base=String(text??'');if(!base||context.verbatim===true)return base;
 const p=npcPersona(profile),state=situation(context),limit=budget(maxLength);
 if(base.length>limit)return base;
 const safeAck=topic==='thanks'&&/^(?:Np\.|Anytime\.|You are welcome\.|No problem\.)$/.test(base)||topic==='apology'&&/^(?:All good\.|No worries\.|It happens\.)$/.test(base);
 if(state==='calm'&&safeAck){const result=acknowledgments[topic][p.tone];return result.length<=limit?result:base;}
 // Urgency affects the typing schedule, not a repetitive spoken status label.
 const lead=state==='frustrated'&&['death','retry'].includes(topic)?'Rough one. ':'';
 if(!lead||p.tone==='reserved'||memory.personaRecent?.includes(state)||lead.length+base.length>limit)return base;
 return lead+base;
}

/** Behavioral typing policy only; never changes native cast/cooldown timing. */
export function npcTypingDelay(profile,{text='',topic='',context={}}={}){
 const p=npcPersona(profile),h=hash(signature(profile)+'|'+topic+'|'+String(text)),state=situation(context),length=Math.min(250,String(text).length);
 const base=state==='danger'?1500:state==='busy'?2850:p.socialEnergy==='low'?2550:1800;
 return Math.max(1500,Math.min(5000,base+Math.round(length*5)+(h%701)));
}

/** A caller-verified CURRENT blocker supplies the complete factual question.
 * Seed intentions alone are insufficient. This never sends chat or asks the
 * director to accept a quest, buy an item, invite, move or change its own goal.
 */
export function npcPersonaHelpQuestion(profile,{context={},maxLength=250}={}){
 const need=context.helpNeed;if(!need||need.verified!==true||need.current!==true||!['quest','equipment','travel','event'].includes(need.kind)||typeof need.question!=='string'||!need.question.trim()||situation(context)!=='calm')return '';
 const question=need.question.trim();
 if(question.length>budget(maxLength))return '';
 return question;
}
