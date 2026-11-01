import { inspectCurrentServer, rateSummary, accountDestination, clientWindow, withClientWindow, phonePresentationRequested, verifiedSession } from './connect.js';

export async function mountJoin({document=globalThis.document,location=globalThis.location,request=globalThis.fetch}={}) {
  const el=id=>document.getElementById(id),form=el('connect'),button=el('submit'),password=el('password'),status=el('status');
  // Dekaron.exe copied alone opens /join?client=desktop&shell=native; every link onward keeps both flags.
  const shell=clientWindow(location.search);
  if(phonePresentationRequested({search:location.search})){
    shell.phone=true;document.documentElement.classList.add('phone-join');
    const fit=()=>{const v=globalThis.visualViewport;document.documentElement.style.setProperty('--phone-height',`${v?.height||globalThis.innerHeight}px`);document.documentElement.style.setProperty('--phone-top',`${v?.offsetTop||0}px`);if(document.activeElement?.tagName==='INPUT')document.activeElement.scrollIntoView({block:'nearest'});};
    globalThis.visualViewport?.addEventListener('resize',fit);globalThis.visualViewport?.addEventListener('scroll',fit);globalThis.addEventListener?.('resize',fit);document.addEventListener('focusin',()=>requestAnimationFrame(fit));fit();
  }
  el('host').textContent=location.host;
  el('signin').href=accountDestination(location.origin,'login',shell).href;
  el('signup').href=accountDestination(location.origin,'signup',shell).href;
  el('servers').href=withClientWindow(new URL('/web/public/index.html',location.origin),shell).href;
  let mode=null,checking=false;
  const showAccounts=async()=>{
    if(checking)return;checking=true;password.value='';form.hidden=true;el('accounts').hidden=true;if(el('retry'))el('retry').hidden=true;
    el('title').textContent=mode==='friends'?'Connected to this world':'Your world is ready';el('intro').textContent='Sign in or create an account on this server.';
    try{
      if(shell.phone){el('accountStatus').textContent='Checking your account session…';const account=await verifiedSession(location.origin,request);
        if(account){el('accountStatus').textContent='Signed in. Opening character select…';location.replace(withClientWindow(new URL('/?screen=select',location.origin),shell).href);return;}}
      el('accounts').hidden=false;el('accountStatus').textContent='Sign in or create an account on this server.';
    }catch(error){el('accountStatus').textContent=error.message;if(el('retry'))el('retry').hidden=false;}
    finally{checking=false;}
  };
  el('retry')?.addEventListener('click',()=>void showAccounts());
  form.addEventListener('submit',async event=>{
    event.preventDefault();if(button.disabled||mode!=='friends')return;button.disabled=true;status.textContent='Connecting…';
    try{
      // A password is posted only to the origin displaying this form; redirects cannot forward it.
      const response=await request(new URL('/api/friends/join',location.origin),{method:'POST',credentials:'same-origin',cache:'no-store',redirect:'error',signal:AbortSignal.timeout(10000),headers:{'Content-Type':'application/json'},body:JSON.stringify({password:password.value})});
      const result=await response.json();if(!response.ok||result.joined!==true)throw new Error(result.error||'Could not connect. Check the server password.');
      await showAccounts();
    }catch(error){password.value='';status.textContent=error instanceof TypeError?'Could not reach this server. Ask the host to check it.':error.message;button.disabled=false;password.focus();}
  });
  try{
    const info=await inspectCurrentServer(location.origin,request);mode=info.hostMode;el('serverName').textContent=info.name;el('rates').textContent=rateSummary(info);
    if(mode==='friends'){el('title').textContent='Join this world';el('intro').textContent='Enter the server password from your host. Your account password is entered separately on this server.';form.hidden=false;button.disabled=false;}
    else{await showAccounts();}
  }catch(error){el('title').textContent='Server unavailable';el('intro').textContent='Check the address and ask the host to start their server.';el('accountStatus').textContent=error.message;}
}
if(globalThis.document)void mountJoin();
