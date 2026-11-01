// Keep a human's unsent presentation through unrelated crowd traffic. These
// records never award progress or alter combat; authoritative state is separate.
const PROGRESS=new Set(['reward','loot','petinventory','levelup']);
class NoticeRing{
 constructor(cap){this.cap=cap;this.rows=new Array(cap);this.start=0;this.size=0;}
 get length(){return this.size;}
 prune(cursor){while(this.size&&this.rows[this.start].sequence<=cursor){this.rows[this.start]=undefined;this.start=(this.start+1)%this.cap;this.size--;}}
 push(event,cursor){this.prune(cursor);if(this.size===this.cap){this.rows[this.start]=event;this.start=(this.start+1)%this.cap;}else{this.rows[(this.start+this.size)%this.cap]=event;this.size++;}}
 after(cursor){this.prune(cursor);return Array.from({length:this.size},(_,i)=>this.rows[(this.start+i)%this.cap]);}
}
export function rememberHumanPresentation(player,event){
 if(!player?.id||player.npcPlayer||player.profile?.npcPlayer)return;
 const progress=PROGRESS.has(event.type)&&event.actorId===player.id;
 const damage=event.type==='damage'&&(event.sourceId===player.id||event.targetId===player.id);
 if(!progress&&!damage)return;
 const key=progress?'_pendingProgressEvents':'_pendingDamageEvents',cap=progress?512:2048;
 const since=Number.isSafeInteger(player._streamEventSeq)?player._streamEventSeq:-1;
 const pending=player[key]||(player[key]=new NoticeRing(cap));pending.push(event,since);
}
export function pendingPresentationEvents(player,rows,since){
 const cursor=Number.isSafeInteger(since)?since:-1;
 const progress=player._pendingProgressEvents?.after(cursor)||[];
 const damage=player._pendingDamageEvents?.after(cursor)||[];
 if(!progress.length&&!damage.length)return rows;
 return [...new Map([...rows,...progress,...damage].map(e=>[e.sequence,e])).values()].sort((a,b)=>a.sequence-b.sequence);
}
