// LANE1-PERF measured backpressure for optional bot work. ENGINE-CHOSEN.
// Signals (rolling windows): event-loop delay p99 (excess over the histogram
// resolution) and human HTTP request latency p95 (SSE streams excluded).
// Levels: 0 normal; 1 throttle optional bot thinking (decision-flight cap drops
// toward minFlights); 2 additionally pause NEW optional admissions. Never drops
// events, rewards, mobs or validation; never touches human requests. Hysteresis:
// enter after `enterWindows` over budget, leave after `exitWindows` below
// exitRatio*budget. Fairness/bounds come from the existing round-robin cursor and
// bounded flight map; stale flights already cancel through custody checks.
import {monitorEventLoopDelay} from 'node:perf_hooks';
export const NPC_BACKPRESSURE_DEFAULTS=Object.freeze({enabled:true,eventLoopP99Ms:60,humanP95Ms:150,windowMs:1000,maxFlights:8,minFlights:2,enterWindows:2,exitWindows:3,exitRatio:0.7,minHumanSamples:5});
const quantile=(values,q)=>{if(!values.length)return null;const s=[...values].sort((a,b)=>a-b);return s[Math.min(s.length-1,Math.floor(q*s.length))];};
export function createNpcBackpressure(settings={},{now=()=>performance.now(),histogram=null}={}){
 const cfg={...NPC_BACKPRESSURE_DEFAULTS,...settings};
 const h=histogram||(cfg.enabled?monitorEventLoopDelay({resolution:10}):null);if(h&&!histogram)h.enable();
 const resolutionMs=histogram?0:10;let human=[],windowStart=now(),over=0,under=0,level=0,last={eventLoopP99Ms:null,humanP95Ms:null,humanSamples:0};const stats={windows:0,throttledWindows:0,pausedWindows:0,transitions:0};
 function roll(){
  const at=now();if(at-windowStart<cfg.windowMs)return;windowStart=at;stats.windows++;
  const eld=h?Math.max(0,h.percentile(99)/1e6-resolutionMs):0;h?.reset();
  const hp=human.length>=cfg.minHumanSamples?quantile(human,.95):null;last={eventLoopP99Ms:+eld.toFixed(1),humanP95Ms:hp==null?null:+hp.toFixed(1),humanSamples:human.length};human=[];
  const ratio=Math.max(eld/cfg.eventLoopP99Ms,hp==null?0:hp/cfg.humanP95Ms);
  if(ratio>1){over++;under=0;}else if(ratio<cfg.exitRatio){under++;over=0;}else{over=0;under=0;}
  const before=level;
  if(over>=cfg.enterWindows&&level<2){level++;over=0;}
  else if(under>=cfg.exitWindows&&level>0){level--;under=0;}
  if(level!==before)stats.transitions++;if(level>=1)stats.throttledWindows++;if(level>=2)stats.pausedWindows++;
 }
 return Object.freeze({
  settings:()=>({...cfg}),
  recordHuman(ms){if(cfg.enabled&&Number.isFinite(ms)&&ms>=0&&human.length<4096)human.push(ms);},
  sample(){if(cfg.enabled)roll();},
  level:()=>cfg.enabled?level:0,
  flightCap(){const l=cfg.enabled?level:0;return l===0?cfg.maxFlights:Math.max(cfg.minFlights,Math.floor(cfg.maxFlights/(2*l)));},
  admissionsPaused:()=>cfg.enabled&&level>=2,
  state:()=>({enabled:cfg.enabled,level:cfg.enabled?level:0,flightCap:cfg.enabled&&level?Math.max(cfg.minFlights,Math.floor(cfg.maxFlights/(2*level))):cfg.maxFlights,admissionsPaused:cfg.enabled&&level>=2,...last,...stats}),
  close(){if(h&&!histogram)h.disable();},
 });
}
