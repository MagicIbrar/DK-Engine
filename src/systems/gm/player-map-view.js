// Translation is measured in viewport fractions, so resize and UI scale changes
// preserve the viewed location. FILE-map axes are intentionally transposed.
const clamp=(n,min,max)=>Math.max(min,Math.min(max,n));
export function constrainPlayerMapView(view={}){
 const zoom=clamp(Number(view.zoom)||1,1,8);
 return {zoom,x:clamp(Number(view.x)||0,1-zoom,0),y:clamp(Number(view.y)||0,1-zoom,0)};
}
export function zoomPlayerMap(view,zoom,anchor={x:.5,y:.5}){
 const current=constrainPlayerMapView(view),next=constrainPlayerMapView({zoom});
 const x=clamp(Number(anchor.x)||0,0,1),y=clamp(Number(anchor.y)||0,0,1),ratio=next.zoom/current.zoom;
 return constrainPlayerMapView({zoom:next.zoom,x:x-(x-current.x)*ratio,y:y-(y-current.y)*ratio});
}
export function panPlayerMap(view,x,y){
 const current=constrainPlayerMapView(view);
 return constrainPlayerMapView({...current,x:current.x+x,y:current.y+y});
}
export function playerMapPoint(player,size={}){
 const fraction=(value,extent)=>clamp((Number(value)||0)/(Number(extent)>0?Number(extent):512),0,1);
 return {x:fraction(player.z,size.height),y:fraction(player.x,size.width)};
}
export function playerMapPosition(player,size={},view={zoom:1,x:0,y:0}){
 const point=playerMapPoint(player,size),camera=constrainPlayerMapView(view);
 const pct=n=>camera.zoom===1?`clamp(6px, ${n*100}%, calc(100% - 6px))`:`${n*100}%`;
 return {left:pct(point.x*camera.zoom+camera.x),top:pct(point.y*camera.zoom+camera.y)};
}

/** Invert FILE-map's transposed axes after camera translation and zoom. */
export function playerMapDestination(point,size={},view={}){
 const camera=constrainPlayerMapView(view),width=Number(size.width)||512,height=Number(size.height)||512;
 if(!Number.isFinite(point.x)||!Number.isFinite(point.y)||width<=0||height<=0)return null;
 const z=(point.x-camera.x)/camera.zoom,x=(point.y-camera.y)/camera.zoom;
 if(x<0||z<0||x>=1||z>=1)return null;
 return {x:x*width,z:z*height};
}
