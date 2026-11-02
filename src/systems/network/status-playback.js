// Presentation of authoritative status rows. Never advances gameplay timers,
// applies options, deals damage, learns skills, or writes the character save.
const number = value => Number.isFinite(Number(value)) ? Number(value) : 0;
const keyOf = entry => String(entry.family || entry.key || `status:${entry.statusIndex}:spell:${entry.spellIcon}`);
const signatureOf = entry => `${number(entry.statusIndex)}:${number(entry.spellIcon)}:${!!entry.spell}`;
// lane70c: a modeleffect row persists while the status lasts when its Global eff_loop is 0 and plays once when it is 1
// (see statuses.js). Spell auras (modeleffect 41, all eff_loop 1) keep looping: JUDGMENT, as in spells.js.
const persists = ref => !!ref && Number(ref.loop) === 0;
const stop = handle => { try { handle?.stop?.(true); } catch (error) { console.warn('[skills] status effect stop failed', error); } };

export class SharedStatusPlayback {
  constructor(game, network) {
    this.game=game;this.network=network;this.engine=game.skills;
    this.active=new Map();this.transients=new Map();this.generation=0;
  }
  entries(actor) { return actor===this.game.player ? this.game.save.buffs||[] : actor._skillStatusVisuals||[]; }
  valid(actor, entry) {
    return !this.disposed&&!actor.dead&&!actor.disposed&&
      this.entries(actor).some(row=>keyOf(row)===keyOf(entry)&&signatureOf(row)===signatureOf(entry)&&number(row.remaining)>0);
  }
  refs(entry, def) {
    if(entry.spell) {
      const keep=this.engine.data?.modelEffects?.spell?.[entry.spellIcon];
      return keep ? {keep,spellAura:true} : null;
    }
    return def?.effects || this.engine.data?.modelEffects?.status?.[def?.iconIndex] || null;
  }
  play(actor, ref, loop, record, isKeep=loop) {
    if(!ref)return;
    const tracked=loop&&isKeep;
    const generation=this.generation,epoch=record.epoch;
    if(tracked)record.loading=true;
    const retain=handle=>{
      if(epoch===record.epoch&&tracked)record.loading=false;
      if(!handle)return;
      if(this.disposed||generation!==this.generation||epoch!==record.epoch||record.stopped||performance.now()>=record.deadline||!this.valid(actor,record.entry))stop(handle);
      else {record.handles.push(handle);if(tracked){record.hasKeep=true;record.keepHandle=handle;}}
    };
    try {
      const handle=this.engine.fx?.play(actor,ref,{loop});
      if(handle?.then)void Promise.resolve(handle).then(retain).catch(error=>{if(epoch===record.epoch&&tracked)record.loading=false;console.warn('[skills] status effect failed',error);});
      else retain(handle);
    } catch(error) { if(tracked)record.loading=false;console.warn('[skills] status effect failed',error); }
  }
  retryData(actor,record,error) {
    const transient=!!error?.retryable||!error?.status&&['TypeError','AbortError'].includes(error?.name);
    if(transient&&(record.dataAttempts||0)<3&&!record.stopped&&performance.now()<record.deadline&&this.valid(actor,record.entry))record.dataRetryAt=Math.max(performance.now()+250,number(error?.retryAt));
  }
  start(actor, record, fresh=false) {
    if(performance.now()>=record.deadline){this.stopRecord(record);return;}
    const epoch=record.epoch;record.loading=true;record.attemptAt=performance.now();
    const apply=def=>{
      if(epoch!==record.epoch||record.stopped||!this.valid(actor,record.entry))return;
      if(performance.now()>=record.deadline){this.stopRecord(record);return;}
      record.loading=false;
      const refs=this.refs(record.entry,def);record.refs=refs;
      const keepLoops=!!refs?.keep&&(refs.spellAura||persists(refs.keep));
      record.wantsKeep=keepLoops;
      if(!def&&!record.entry.spell)this.retryData(actor,record,this.engine.data?.statusLoadFailure);
      // A persistent start row (eff_loop 0) is retained like the keep row and stopped with the record; it is replayed on a
      // restart only when the record has no handles left from the first start.
      if(refs?.start&&(fresh||persists(refs.start)&&!record.handles.length))this.play(actor,refs.start,persists(refs.start),record,false);
      if(refs?.keep)this.play(actor,refs.keep,keepLoops,record,keepLoops);
    };
    const data=this.engine.data,def=record.entry.spell?null:data?.status?.(record.entry.statusIndex);
    if(def||record.entry.spell)apply(def);
    else if(data?.statusAsync){
      record.dataAttempts=(record.dataAttempts||0)+1;
      void Promise.resolve().then(()=>data.statusAsync(record.entry.statusIndex)).then(apply).catch(error=>{
        if(epoch===record.epoch){record.loading=false;this.retryData(actor,record,error);}
        console.warn('[skills] status data failed',error);
      });
    }
    else record.loading=false;
  }
  sync(actor, freshKey=null) {
    if(!actor||actor.dead||actor.disposed){this.end(actor);return;}
    // PERF: an actor with no status rows and no running record (almost every monster, every frame) has nothing to start or stop;
    // the code below would only allocate a Set + Map for it and put / remove it in `active` again.
    if(!this.active.has(actor)&&!(this.entries(actor).length>0))return;
    const now=performance.now(),live=new Set(),records=this.active.get(actor)||new Map();
    this.active.set(actor,records);
    for(const entry of this.entries(actor)) {
      if(!(number(entry.remaining)>0))continue;
      const key=keyOf(entry),signature=signatureOf(entry);live.add(key);
      let record=records.get(key);
      const hadRecord=!!record;
      if(record&&record.signature!==signature){this.stopRecord(record);records.delete(key);record=null;}
      if(!record){
        record={entry,signature,handles:[],epoch:0,deadline:now+number(entry.remaining)*1000};records.set(key,record);
        this.start(actor,record,!hadRecord&&key===freshKey);
      } else if(record.entry!==entry) {
        // Snapshots replace objects; preserve the running loop across replacement.
        record.entry=entry;record.deadline=now+number(entry.remaining)*1000;
        if(record.stopped){record.stopped=false;this.start(actor,record);}
      }
      if(!record.stopped&&!record.loading&&record.dataRetryAt!=null&&now>=record.dataRetryAt){record.dataRetryAt=null;this.start(actor,record);}
      if(record.keepHandle?.done){record.hasKeep=false;record.keepHandle=null;record.handles=record.handles.filter(handle=>!handle.done);}
      if(!record.stopped&&!record.loading&&record.wantsKeep&&!record.hasKeep&&now-record.attemptAt>=250)this.start(actor,record);
    }
    for(const [key,record]of records) {
      if(!live.has(key)){this.stopRecord(record);records.delete(key);}
      else if(now>=record.deadline&&!record.stopped)this.stopRecord(record);
    }
    if(!records.size)this.active.delete(actor);
  }
  event(event,actor) {
    if(!actor||event.type!=='status')return;
    const key=String(event.family||event.key||`status:${event.statusIndex}:spell:undefined`);
    if(event.on){this.sync(actor,key);return;}
    const records=this.active.get(actor),record=records?.get(key);
    if(!record)return;
    this.stopRecord(record);records.delete(key);
    // End scenes only follow actual server removal, never map/disconnect cleanup.
    if(!actor.dead&&!actor.disposed&&event.reason!=='silent'&&record.refs?.end) {
      const generation=this.generation;
      const retain=handle=>{
        if(!handle)return;
        if(this.disposed||generation!==this.generation||actor.dead||actor.disposed)stop(handle);
        else this.transients.set(handle,actor);
      };
      try {
        const handle=this.engine.fx?.play(actor,record.refs.end,{loop:false});
        if(handle?.then)void Promise.resolve(handle).then(retain).catch(error=>console.warn('[skills] status end effect failed',error));
        else retain(handle);
      }
      catch(error){console.warn('[skills] status end effect failed',error);}
    }
  }
  update() {
    if(!this.transients.size&&!this.active.size){
      // PERF: nothing is running, so there is nothing to retire and the pool Set is not needed: sync straight from the live maps in the
      // same order (own body, players, monsters, servants; the own body once).
      const player=this.game.player;
      if(player)this.sync(player);
      this._syncMap(this.network.players,player);this._syncMap(this.network.monsters,player);this._syncMap(this.network.servants,player);
      return;
    }
    const pool=new Set([this.game.player,...(this.network.players?.values?.()||[]),...(this.network.monsters?.values?.()||[]),...(this.network.servants?.values?.()||[])]);
    for(const [handle,actor]of this.transients)if(handle.done||actor.dead||actor.disposed||!pool.has(actor)){stop(handle);this.transients.delete(handle);}
    for(const actor of this.active.keys())if(!pool.has(actor))this.end(actor);
    for(const actor of pool)if(actor)this.sync(actor);
  }
  _syncMap(map,player) { const values=map?.values?.();if(values)for(const actor of values)if(actor&&actor!==player)this.sync(actor); }
  stopRecord(record) { record.stopped=true;record.dataRetryAt=null;record.epoch++;record.loading=false;record.hasKeep=false;record.keepHandle=null;for(const handle of record.handles)stop(handle);record.handles=[]; }
  end(actor) { for(const record of this.active.get(actor)?.values()||[])this.stopRecord(record);this.active.delete(actor); }
  clear() { this.generation++;for(const actor of this.active.keys())this.end(actor);for(const handle of this.transients.keys())stop(handle);this.transients.clear(); }
  dispose() { this.disposed=true;this.clear(); }
}
