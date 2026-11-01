// The touch menu follows the rendered ONLINE panel, including native HUD scale.
// Observe layout changes rather than measuring the HUD on every game frame.
export function positionMobileMenu(game,{doc,win,root,rail,extra,modifier}) {
  let status=null,minimap=null,closed=false,discovery=null,resize=null,styles=null;
  const write=(el,key,value)=>{if(el.style[key]!==value)el.style[key]=value;};
  const rect=el=>{const r=el?.getBoundingClientRect?.();return r?.width>0&&r?.height>0?r:null;};
  const clamp=(v,lo,hi)=>Math.max(lo,Math.min(Math.max(lo,hi),v));
  function layout(){
    if(closed)return;
    const r=rect(root),width=win.visualViewport?.width||win.innerWidth||r?.width||800,height=win.visualViewport?.height||win.innerHeight||r?.height||600;
    const inset=win.getComputedStyle?.(root)||{},left=Math.max(8,parseFloat(inset.paddingLeft)||0),right=width-Math.max(8,parseFloat(inset.paddingRight)||0),top=Math.max(8,parseFloat(inset.paddingTop)||0),bottom=height-Math.max(8,parseFloat(inset.paddingBottom)||0);
    const anchor=rect(minimap)||rect(status),map=rect(minimap),size=48,gap=8;
    let x=anchor?anchor.left-gap-size:right-size,y=anchor?anchor.top:top;
    if(x<left&&anchor)y=anchor.bottom+gap;
    x=clamp(x,left,right-size);y=clamp(y,top,bottom-size);
    write(rail,'left',x+'px');write(rail,'top',y+'px');
    let panelWidth=Math.min(280,right-left),panelLeft=clamp(x+size-panelWidth,left,right-panelWidth),panelTop=y+size+gap;
    // Open below the button, to its left. On portrait/narrow windows where that
    // cannot clear the minimap, use the free space immediately below the map.
    if(map&&panelLeft+panelWidth>map.left-gap&&panelTop<map.bottom+gap){
      const room=map.left-gap-left;
      if(room>=220){panelWidth=Math.min(panelWidth,room);panelLeft=clamp(x+size-panelWidth,left,map.left-gap-panelWidth);}
      else panelTop=Math.max(panelTop,map.bottom+gap);
    }
    panelTop=clamp(panelTop,top,bottom-48);
    write(extra,'left',panelLeft+'px');write(extra,'top',panelTop+'px');write(extra,'width',panelWidth+'px');write(extra,'maxHeight',Math.max(48,bottom-panelTop)+'px');
    write(modifier,'left',clamp(x,left,right-88)+'px');write(modifier,'top',clamp(y+size+4,top,bottom-24)+'px');
  }
  function attach(){
    const nextStatus=game.network?._statusPanel||doc.querySelector?.('.dk-shared-world-status'),nextMap=game.uiwin?.window?.('hud_minimap')?.el;
    if(nextStatus===status&&nextMap===minimap){layout();return;}
    status=nextStatus;minimap=nextMap;resize?.disconnect();styles?.disconnect();
    if(typeof win.ResizeObserver==='function'){resize=new win.ResizeObserver(layout);for(const el of new Set([status,minimap].filter(Boolean)))resize.observe(el);}
    if(typeof win.MutationObserver==='function'){styles=new win.MutationObserver(layout);for(const el of new Set([status,minimap].filter(Boolean)))styles.observe(el,{attributes:true,attributeFilter:['style','class']});}
    if(status){discovery?.disconnect();discovery=null;}
    layout();
  }
  if(typeof win.MutationObserver==='function'){discovery=new win.MutationObserver(attach);discovery.observe(doc.body,{childList:true,subtree:true});}
  win.addEventListener('resize',attach);win.visualViewport?.addEventListener?.('resize',layout);attach();
  return {layout,dispose(){closed=true;discovery?.disconnect();resize?.disconnect();styles?.disconnect();win.removeEventListener('resize',attach);win.visualViewport?.removeEventListener?.('resize',layout);}};
}
