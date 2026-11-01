// The native guild frame is translucent; give it its own body surface so HUD
// chat underneath cannot look like guild content. Keep authored frame/buttons.
export function guildWindowSurface(window) {
 if(!window?.el?.style)return;
 window.el.style.isolation='isolate';
 // The script reserves space beyond its painted 512px frame for popups. Do
 // not paint that empty tail; cover only the authored frame panels.
 for(const id of ['pan_top','pan_mid','pan_bottom']) {
  const panel=window.find?.(id);
  if(panel?.el?.style)panel.el.style.backgroundColor='#17130f';
 }
}
