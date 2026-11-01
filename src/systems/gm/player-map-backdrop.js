import {atlas} from '../../ui/atlas.js';
import {fetchBuffer} from '../../engine/assets.js';
import {parseMap} from '../../formats/map.js';
import {mapDataPaths} from '../../formats/spawn.js';

const games=new WeakMap();
// Both authored minimaps and terrain samples use original FILE axes: U=Z, V=X.
export function playerMapBackdrop(game,id,{terrainOnly=false}={}){
 let cache=games.get(game);if(!cache||cache.data!==game.data){cache={data:game.data,entries:new Map()};games.set(game,cache);}
 cache=cache.entries;const key=`${id}:${terrainOnly}`;
 if(!cache.has(key))cache.set(key,(async()=>{
  if(!terrainOnly){const sprite=await atlas.sprite('minimap',Number(id)).catch(()=>null);if(sprite)return {url:sprite.url,source:'original-minimap'};}
  const row=game.data?.mapByIndex?.(id);if(!row)return null;
  const map=parseMap(await fetchBuffer(mapDataPaths(row).map));
  const canvas=document.createElement('canvas');canvas.width=canvas.height=256;
  const ctx=canvas.getContext('2d'),image=ctx.createImageData(256,256);
  for(let v=0;v<256;v++)for(let u=0;u<256;u++){
   const x=Math.min(map.width-1,Math.floor(v/256*map.width)),z=Math.min(map.height-1,Math.floor(u/256*map.height)),i=z*map.vertsX+x;
   const slope=(map.heights[i+1]-map.heights[i])+(map.heights[i+map.vertsX]-map.heights[i]);
   const light=Math.max(.35,Math.min(1.2,.8-slope*.12)),o=(v*256+u)*4;
   image.data[o]=map.colors[i*4+2]*light;image.data[o+1]=map.colors[i*4+1]*light;image.data[o+2]=map.colors[i*4]*light;image.data[o+3]=255;
  }
  ctx.putImageData(image,0,0);return {url:canvas.toDataURL(),source:'original-terrain'};
 })().catch(()=>null).then(result=>{if(!result)cache.delete(key);return result;}));
 return cache.get(key);
}
