// A guild frame owns its foreground; chat stays a separate HUD underneath it.
export function chatStackBand(onTop,windows=[]) {
 return windows.some(w=>w.isOpen&&!w.opts?.hud&&/\/guild\//i.test(w.key||w.spec?.file||''))?'hud':onTop?'system':undefined;
}
