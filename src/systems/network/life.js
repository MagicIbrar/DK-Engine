// Canonical server pass state feeds the original window. Browser events cannot award points.
export function installSharedLife(game,network){
 const pass=game.life?.dekapass;if(!pass)return;
 const empty={season:pass.season,points:0,dayPoints:0,daily:{},dailyDone:{},seasonProg:{},seasonDone:{},claimed:{},claimedP:{},playSec:0};
 Object.defineProperty(pass,'st',{get:()=>game.save.life?.dekapass||empty});
 Object.defineProperty(pass,'premium',{get:()=>pass.st.season===pass.season&&pass.st.premium===true});
 const refresh=pass._refresh?.bind(pass);
 pass._refresh=async w=>{await refresh?.(w);w.control('btn_buypass').hide();};
 pass._buyPass=()=>false;
 pass.progress=()=>false;
 pass.claim=(level,premium=false)=>network.action('dekapass',{level:Number(level),premium:!!premium});
 pass.claimAll=()=>network.action('dekapass',{all:true});
 pass.update=()=>{};
 const showAlarm=()=>{
  if(!pass.active||pass._serverAlarmOpening)return;
  if(!game.uiwin.window('dekapassalarm')?.isOpen){pass._serverAlarmOpening=true;void game.uiwin.open('dekapassalarm').then(()=>{pass._serverAlarmOpening=false;showAlarm();}).catch(()=>{pass._serverAlarmOpening=false;});return;}
  // Keep the script's own tooltip (ui_dekapassalarmwnd.txt tooltip 3200 1 = "Deka Pass"); the invented
  // "Daily missions and reward boxes / Played today / Open to inspect ..." text is not in the client strings.
  pass._alarm();
 };
 showAlarm();
 game.events?.on?.('server:profile',()=>{
  const signature=JSON.stringify(game.save.life?.dekapass||null);if(signature===pass._serverSignature)return;pass._serverSignature=signature;
  if(pass.win?.isOpen)void pass._refresh(pass.win);if(pass.mwin?.isOpen)pass._refreshMissions(pass.mwin);showAlarm();
 });
}
