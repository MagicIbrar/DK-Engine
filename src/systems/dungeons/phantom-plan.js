import {PHANTOM_CASTLE as C} from '../../config/engine-chosen-phantom-castle.js';

export function phantomCastlePlan(anchors) {
 return {
  name:'phantom-castle',
  setup(d) {
   if(!d.info.scriptMonsters?.includes(C.boss)||!d.game.data?.monster?.(C.boss))
    throw Error('The original Phantom Castle monster is unavailable.');
   const point=anchors(d,1)[0];
   if(!point)throw Error('No reachable Phantom Castle encounter room exists.');
   d.stages=[{n:1,call:1,kind:'wave',objective:'kill-all',rows:[[C.boss,point[0],point[1],0,1]],
    center:point.slice(0,2),opens:[],bosses:[C.boss],group:0,spawned:false,done:false,recs:[],
    synth:'ENGINE-CHOSEN Phantom Castle script reconstruction'}];
   d.clearDef={kind:'all-waves'};d.waitStart=false;d.sequential=true;d.killTarget=0;
   d.limit=Number(d.dungeon.expireTime)*60;
   d.missions=[{kind:'kill',text:d.game.data.monster(C.boss).name,idx:[C.boss],done:false,failed:false}];
   d.phantomPrepared=true;
  },
  clearMet(d) {return (d.spawnedIdx.get(C.boss)||0)===1&&(d.killedIdx.get(C.boss)||0)>=1;},
  talk(d,npc,sn) {
   if(Number(sn.npc)!==5916)return false;
   const text=d.phase==='cleared'?'The Phantom Castle has been cleared.':'Defeat the Acquirai Fanatic before time runs out.';
   d.sys.dialog.open({title:npc.name||sn.name,text,options:true,menu:[{text:'Return to Zuto’s Road',onClick:()=>d.sys.leave(d,'exit')}]});
   return true;
  },
 };
}
