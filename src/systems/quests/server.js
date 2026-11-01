/** Read original quest UI state, submit only server-validated intents. */
export function installServerQuests(sys) {
  const g=sys.game, eng=sys.engine;
  if(g.save.authority !== 'server') return;
  const command=async(operation,id,options={}) => {
    const data={operation,questId:Number(id)};
    if(options.npc != null) data.npc=Number(options.npc);
    if(options.option != null) data.option=Number(options.option);
    if(options.on != null) data.on=!!options.on;
    const response=await g.network?.action('quest',data);
    return response?.result || {ok:false};
  };
  eng.accept=(id,o) => command('accept',id,o);
  eng.acceptInstant=(id,o) => command('instant',id,o);
  eng.claim=(id,o) => command('claim',id,o);
  eng.purchase=(id,o) => command('purchase',id,o);   // scripted vehicle purchase (Sergio's "Purchase Swift Box"): the host charges and hands the box over
  eng.exchange=(id,o)=>command('exchange',id,o);
  eng.abandon=async id => (await command('abandon',id)).ok;
  eng.track=async(id,on=true) => (await command('track',id,{on})).ok;
  eng.talkTo=async(npc,onlyId=null) => {
    const ids=onlyId == null ? eng.activeIds().filter(id => (eng.db.quest(id)?.objectives || []).some(o => o.kind==='talk' && (o.targets || []).some(t => Number(t.id)===Number(npc)))) : [onlyId];
    for(const id of ids) await command('talk',id,{npc});
    return ids;
  };
  for(const name of ['advance','onKill','onSkill','onFish','onClearMap','recountCollect']) eng[name]=() => false;
  // The network emits quest:changed only when canonical quest data changes;
  // avoid rebuilding every quest window for every movement snapshot.
}
