// Styles of the UI window platform, injected once (no stylesheet edits needed by pages that use it).
const CSS = `
.uw-layer{position:fixed;left:0;top:0;transform-origin:0 0;pointer-events:none;z-index:40;overflow:visible;
  -webkit-user-select:none;user-select:none;font:11px Tahoma,Verdana,"Segoe UI",sans-serif;color:#fff}
.uw-layer *{box-sizing:border-box}
.uw-win{position:absolute;pointer-events:none}
.uw-win.uw-hidden,.uw-c.uw-hidden{display:none!important}
.uw-c{position:absolute;pointer-events:none}
.uw-c.uw-hit{pointer-events:auto}
.uw-bg{position:absolute;left:0;top:0;width:100%;height:100%;pointer-events:none;background-repeat:no-repeat;background-size:100% 100%}
.uw-bg.uw-nat{width:auto;height:auto;background-size:100% 100%}
.uw-t{position:absolute;left:0;top:0;width:100%;height:100%;display:flex;pointer-events:none;white-space:pre;overflow:visible}
.uw-t>span{display:block;max-width:none}
.uw-t.uw-wrap{white-space:pre-wrap;word-break:break-word}
.uw-t.uw-wrap>span{max-width:100%}
.uw-edit{position:absolute;left:0;top:0;width:100%;height:100%;background:transparent;border:0;outline:0;padding:0 2px;margin:0;
  color:#fff;pointer-events:auto;caret-color:currentColor;resize:none;overflow:hidden}
/* the page-wide input[type=text] rule (src/ui/style.css: gold frame, 8px 10px padding, width:100%) would otherwise win on specificity
   and draw its own offset frame over the script's plate (personal shop Shop Name field) */
input.uw-edit[type=text],input.uw-edit[type=password],input.uw-edit[type=number]{background:transparent;border:0;border-radius:0;outline:0;padding:0 2px;margin:0;width:100%;height:100%;box-sizing:border-box}
.uw-edit::placeholder{color:inherit;opacity:.65}
.uw-rows{position:absolute;left:0;top:0;right:0;bottom:0;overflow:hidden;pointer-events:none}
.uw-row{position:absolute;left:0;white-space:pre;overflow:visible;pointer-events:auto}
.uw-row .uw-cell{position:absolute;top:0;height:100%;overflow:hidden;white-space:pre;text-overflow:clip}
.uw-rowactions{position:absolute;right:2px;top:1px;bottom:1px;display:flex;align-items:stretch;gap:3px;z-index:3}
.uw-rowaction{display:flex;align-items:center;padding:0 8px;box-sizing:border-box;border:1px solid #0b2a06;border-radius:3px;background:linear-gradient(#7fd63a,#2f8a14);color:#fff;font:bold 11px/1 Tahoma,Arial,sans-serif;text-shadow:0 1px 0 #1a4a0a;cursor:pointer}
.uw-rowaction:hover{filter:brightness(1.15)}
.uw-rowbadge{display:flex;align-items:center;padding:0 4px;font:italic bold 11px/1 Tahoma,Arial,sans-serif;color:#d05cff;text-shadow:0 1px 0 #000;pointer-events:none}
.uw-drop{position:absolute;pointer-events:auto;z-index:100000}
.uw-drop .uw-row:hover{background:rgba(255,255,255,.12)}
.uw-icon{position:absolute;pointer-events:none;background-repeat:no-repeat;background-size:100% 100%;image-rendering:auto}
.uw-count{position:absolute;right:1px;bottom:0;font:bold 11px Tahoma,Verdana,sans-serif;color:#fff;text-shadow:1px 1px 0 #000,-1px 0 0 #000;pointer-events:none}
.uw-cool{position:absolute;left:0;top:0;width:100%;height:100%;pointer-events:none}
.uw-foot{position:absolute;pointer-events:none;z-index:50;box-shadow:inset 0 0 0 1px rgba(255,255,255,.5)}
.uw-foot.ok{background:rgba(40,200,60,.10)}
.uw-foot.bad{background:rgba(220,40,40,.35)}
.uw-gridsel{position:absolute;pointer-events:none;box-shadow:inset 0 0 0 1px rgba(255,220,120,.9)}
.uw-tip{position:absolute;pointer-events:none;z-index:200000;padding:6px 8px;max-width:360px;white-space:pre-wrap;color:#fff;
  font:11px Tahoma,Verdana,"Segoe UI",sans-serif;line-height:14px;background:rgba(10,8,6,.88);border-style:solid;border-width:5px}
.uw-tip.uw-tip-pair{padding:0;max-width:none;border-width:0!important;border-image:none!important;background:none!important}
.uw-tip-frame{border-style:solid;border-width:5px;background:rgba(10,8,6,.88)}
.uw-dnd{position:absolute;pointer-events:none;z-index:300000;background-repeat:no-repeat;background-size:100% 100%;image-rendering:auto}
.uw-dnd>canvas{display:block;width:100%;height:100%}
.uw-held{visibility:hidden}
.uw-backdrop{position:absolute;left:0;top:0;width:100%;height:100%;pointer-events:auto;background:transparent}
.uw-marquee{position:absolute;white-space:nowrap;will-change:transform}
.uw-blink{animation:uwblink 1s steps(2,start) infinite}
@keyframes uwblink{50%{opacity:.35}}
.uw-spin{animation:none;transition:background-color .18s ease-out,box-shadow .18s ease-out}
.uw-spin:hover,:hover>.uw-spin,.uw-spin.uw-spin-hot{animation:var(--uw-spin)}
.uw-spin.uw-spin-hot{background-color:rgba(92,124,220,.30);box-shadow:inset 0 0 12px 2px rgba(150,182,255,.42),0 0 3px rgba(120,160,255,.30)}
.uw-item-socket.uw-gem{isolation:isolate}
.uw-item-socket.uw-gem::after{content:'';position:absolute;inset:0;background:inherit;transform:scale(1.45);filter:blur(2.5px) brightness(1.9) saturate(1.5);
  mix-blend-mode:screen;opacity:.55;pointer-events:none;animation:uwgem 2.4s ease-in-out infinite}
@keyframes uwgem{0%,100%{opacity:.38}50%{opacity:.78}}
@keyframes uwspinx{from{background-position-x:0%}to{background-position-x:100%}}
@keyframes uwspiny{from{background-position-y:0%}to{background-position-y:100%}}
`;

let injected = false;
export function injectCSS() {
  if (injected || typeof document === 'undefined') return;
  injected = true;
  const st = document.createElement('style');
  st.id = 'uiwin-css';
  st.textContent = CSS;
  document.head.appendChild(st);
}
