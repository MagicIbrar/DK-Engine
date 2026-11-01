// ENGINE-CHOSEN composition of map551's authored three calls and native boss family.
// The absent server director does not establish boss multiplicity/order/placement.
// Use every native family boss once in stage4, inside the arena toward each
// boss's gate (the Helion anchors are outside the arena wall); never alter stats.
// In-run mechanics (abilities, totems, gates, curses) are host services; their
// native rows and engine choices are in src/config/engine-chosen-dead-island.js.
import {DEAD_ISLAND_BOSS_GATES,DEAD_ISLAND_BOSS_RADIUS,DEAD_ISLAND_ARENA_CENTRE} from '../../config/engine-chosen-dead-island.js';
const RESETS=[10000000,20000000,40000000,80000000,160000000];
const TYPES={13001:{page:13100,menu:[14001,14002,14009]},13002:{page:13200,menu:[14003,14008,14010]},13003:{page:13300,menu:[14004,14005,14006,14007]}};
const TOTEMS=new Set([5537,5538,5539,5540,5541,5545]),GATES=new Set([5660,5661,5662]),HELIONS=new Set([5533,5534,5535]);
const label=(d,code)=>String(d.text(code)||'').split('<')[0].replace(/^\[message\]\s*/,'').trim();
export function deadIslandPlan(){
 return {name:'dead-island-engine-chosen',setup(d){
  d.waitStart=true;d.phase='waiting';d.sequential=true;d.limit=7200;d.deadIslandStartedAt=d.game.time;
  d.stages=d.stages.filter(s=>[1,2,3].includes(s.call)).map(s=>({...s,opens:[],bosses:[],group:0}));
  const c=DEAD_ISLAND_ARENA_CENTRE,rows=DEAD_ISLAND_BOSS_GATES.map(([boss,gate])=>{const g=d.scriptNpc(gate),L=g?Math.hypot(g.x-c.x,g.y-c.z):0;return [boss,L?c.x+(g.x-c.x)/L*DEAD_ISLAND_BOSS_RADIUS:c.x,L?c.z+(g.y-c.z)/L*DEAD_ISLAND_BOSS_RADIUS:c.z,0,1];});
  d.stages.push({n:4,kind:'wave',objective:'kill-all',rows,opens:[],bosses:[7979,7980,7981],group:0,spawned:false,done:false,recs:[]});
  d.clearDef={kind:'all-waves'};d.deadIslandResets=0;
 },begin(d){d.effect(219);d.openAllGates(false);d.game.deadIslandService?.stage?.(1);},
 update(d){if(d.phase==='running')d.elapsed=Math.max(0,d.game.time-d.deadIslandStartedAt);d.game.deadIslandService?.tick?.();},
 stageDone(d,s){if(s.n===1)d.effect(202);else if(s.n===2)d.effect(203);else if(s.n===3)d.effect(266);else if(s.n===4){d.effect(267);d._spawnStage({n:5,kind:'reward',rows:[[7987,256,272,0,1]],opens:[],recs:[],spawned:false});}
  if(s.n<4)d.later(3.1,()=>{if(d.running)d.game.deadIslandService?.stage?.(s.n+1);});},
 clearMet(d){return d.stages.length===4&&d.stages.every(s=>s.spawned&&s.done);},
 talk(d,npc,sn){
  const service=d.game.deadIslandService,title=npc.name||sn.name;
  const menu=(code,onClick)=>({text:label(d,code),onClick}),open=(code,items,text)=>d.sys.dialog.open({title,text:text??d.text(code),menu:items,options:true});
  if([5542,5543,5544].includes(sn.npc)){
   const code=sn.npc===5542?31000:sn.npc===5543?32000:33000;
   d.sys.dialog.open({title,text:d.text(code),menu:[{text:d.text(31001),onClick:()=>d.sys.leave(d,'exit')}],options:true});return true;
  }
  if(!service)return false;
  const resetPage=()=>{const index=Math.min(4,d.deadIslandResets);open(21000+index*100,[menu(21001,async()=>{await service.reset(RESETS[index]);d.sys.dialog.close();}),menu(21002,()=>d.sys.dialog.close())]);};
  if(HELIONS.has(sn.npc)){
   // Native row 13000: Attack/Defense/Support type, Ancient power release, Reset Battle.
   const home=()=>open(13000,[...Object.entries(TYPES).map(([code,t])=>menu(Number(code),()=>open(t.page,[...t.menu.map(m=>menu(m,async()=>{await service.choose(m);d.sys.dialog.close();})),menu(13009,home)]))),
    menu(13004,async()=>{await service.release();d.sys.dialog.close();}),menu(20002,resetPage)]);
   home();return true;
  }
  if(TOTEMS.has(sn.npc)){open(30000,[menu(30001,async()=>{await service.resonate(sn.npc);d.sys.dialog.close();}),menu(30002,()=>d.sys.dialog.close())]);return true;}
  if(GATES.has(sn.npc)){
   const go=async()=>{await service.enter(sn.npc);d.sys.dialog.close();};
   if(service.hasAbility?.())open(5005,[menu(5005,go)],'');
   else open(40000,[menu(40001,go),menu(40002,()=>d.sys.dialog.close())]);
   return true;
  }
  if(sn.npc!==5536)return false;
  open(20000,[menu(20001,async()=>{await service.start();d.sys.dialog.close();}),menu(20002,resetPage),menu(20003,()=>d.sys.leave(d,'exit'))]);return true;
 }};
}
