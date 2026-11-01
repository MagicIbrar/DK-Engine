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
/** World x/z -> minimap image pixels (ENGINE-CHOSEN reading of pivot_mapsize). */
export function huntMinimapPoint(x,z,cfg=CHOSEN.minimap){
  const w=cfg.world,u=(Number(x)-w.x)/w.width,v=(Number(z)-w.z)/w.height;
  return [Math.round(Math.max(0,Math.min(1,u))*cfg.image),Math.round(Math.max(0,Math.min(1,cfg.flipZ?1-v:v))*cfg.image)];
}
/** Layout of the five pan_light_N panels from snapshot.hunt.lights: [{panel, meaning, visible, x, y, size, color, blink}]. */
export function huntLightLayout(lights,cfg=CHOSEN.minimap){
  let invader=0;
  return cfg.lights.map(l=>{
    const at=l.meaning==='self'?lights?.self:l.meaning==='guild'?lights?.guild:l.meaning==='boss'?lights?.boss:l.meaning==='invaders'?lights?.invaders?.[invader++]:null;
    if(!at)return {panel:l.panel,meaning:l.meaning,visible:false};
    const [px,py]=huntMinimapPoint(at[0],at[1],cfg);
    return {panel:l.panel,meaning:l.meaning,visible:true,x:px-l.size/2,y:py-l.size/2,size:l.size,color:l.color,blink:!!l.blink};
  });
}
/** 'AARRGGBB' -> css rgba(). */
export function argbCss(argb){const n=String(argb||'ffffffff').padStart(8,'f');const a=parseInt(n.slice(0,2),16)/255,r=parseInt(n.slice(2,4),16),g=parseInt(n.slice(4,6),16),b=parseInt(n.slice(6,8),16);return `rgba(${r},${g},${b},${Math.round(a*1000)/1000})`;}