// Guild War Hunting presentation rules shared by the client windows and the tests (no DOM, no three.js).
// ENGINE-CHOSEN values come from src/config/engine-chosen-guild-war-hunting.js.
import {GUILD_WAR_HUNTING_ENGINE_CHOSEN as CHOSEN} from '../../config/engine-chosen-guild-war-hunting.js';
const valid=mark=>!!mark&&Number.isInteger(mark.bg)&&Number.isInteger(mark.icon)&&mark.bg>=1&&mark.icon>=1;
/** Guild mark images for one scripted mark pair: [{panel, image|null}] (null hides the panel). */
export function huntMarkImages(mark,bgPanel,iconPanel,size='small'){
  const [bg,icon]=CHOSEN.marks[size]||CHOSEN.marks.small,ok=valid(mark);
  return [{panel:bgPanel,image:ok?{screen:bg,index:mark.bg,color:CHOSEN.marks.color}:null},{panel:iconPanel,image:ok?{screen:icon,index:mark.icon,color:CHOSEN.marks.color}:null}];
}
/** Every mark panel of the final scoreboard (first place, rows 0..9, own guild) for a host run record. */
export function huntBoardMarks(run){
  const top=run?.top||[],out=[...huntMarkImages(top[0]?.mark,'pan_first_guildmarkbg','pan_first_guildmark','large')];
  for(let i=0;i<10;i++)out.push(...huntMarkImages(top[i]?.mark,`pan_vec_guildmarkbg_${i}`,`pan_vec_guildmark_${i}`));
  out.push(...huntMarkImages(run?.me?.mark,'pan_guildmarkbg','pan_guildmark'));
  return out;
}
/** Mark panels of the live guild info board (rows 0..9). */
export function huntInfoMarks(run){const top=run?.top||[],out=[];for(let i=0;i<10;i++)out.push(...huntMarkImages(top[i]?.mark,`pan_vec_guildmarkbg_${i}`,`pan_vec_guildmark_${i}`));return out;}
