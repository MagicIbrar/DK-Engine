// The native registration script clones the missing btn_purchase. Its same-row
// btn_regist supplies the original style. Keep Close's native label and place it
// beside Register; the old clone rectangle is inside the fee controls.
export function repairConsignmentCancel(window) {
 const button=window.find?.('btn_cancel'),source=window.find?.('btn_regist');
 if(!button?.spec||!source?.spec||button.spec.cloneOf||button.spec.props?.clone?.[0]!=='btn_purchase')return false;
 if(button.spec.images?.length||!source.spec.images?.length)return false;
 for(const image of source.spec.images)button.setImage(image.key,{...image});
 const titles=Object.create(null);
 for(const title of source.spec.titles||[])titles[title.state]={...title};
 for(const title of button.spec.titles||[])titles[title.state]={...(titles[title.state]||{}),...title};
 button.titles=titles;
 button.spec.align=source.spec.align?{...source.spec.align}:button.spec.align;
 if(button.el)button.el.style.zIndex=String(Math.max(0,Math.round(source.spec.layer||0)));
 const [x,y,w,h]=source.spec.rect;
 button.setRect?.(x+w+6,y,w,h);
 button.paintText?.();
 return true;
}
