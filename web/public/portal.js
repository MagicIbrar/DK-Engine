import { serverAddress, inspectServer, connectionDestination, inspectDirectory, inspectCurrentServer, rateSummary, clientWindow, withClientWindow } from './connect.js';
import { defaultDirectory } from './portal-config.js';

export function mountPortal({document=globalThis.document,location=globalThis.location,request=globalThis.fetch}={}) {
  // client=desktop (launcher windows) and shell=native (Dekaron.exe) carry over to every world opened from this menu.
  const shell=clientWindow(location.search),desktop=shell.desktop;
  for(const link of document.querySelectorAll('[data-menu-link]'))if(desktop||shell.native)link.href=withClientWindow(new URL(link.href,location.href),shell).href;
  const form=document.getElementById('connectForm'),button=document.getElementById('connectButton'),status=document.getElementById('status');
  form.addEventListener('submit',async event=>{
    event.preventDefault();if(button.disabled)return;button.disabled=true;
    try {
      const url=serverAddress(form.elements.server.value);
      // Private HTTP hosts open their own connector; HTTPS pages cannot inspect them with fetch.
      if(location.protocol==='https:'&&url.protocol==='http:'){
        withClientWindow(url,shell);status.textContent='Opening the host’s connection screen…';location.assign(url.href);return;
      }
      status.textContent='Checking the server…';const info=await inspectServer(url,request);
      status.textContent=`Opening ${info.name}…`;location.assign(connectionDestination(url,info,shell).href);
    }catch(error){status.textContent=error instanceof TypeError?'Could not reach that server. Check its address and ask the host to start it.':error.message;button.disabled=false;}
  });
  const current=document.getElementById('currentServer'),reconnect=document.getElementById('reconnect'),currentStatus=document.getElementById('currentStatus');
  const ready=inspectCurrentServer(location.origin,request).then(info=>{
    document.getElementById('currentName').textContent=info.name;
    document.getElementById('currentAddress').textContent=location.host;
    document.getElementById('currentRates').textContent=rateSummary(info);
    document.getElementById('currentMode').textContent=info.hostMode==='friends'?'Invite only':info.hostMode==='open'?'Open world':'Local world';
    current.hidden=false;
  }).catch(()=>{});
  reconnect.addEventListener('click',async()=>{
    if(reconnect.disabled)return;reconnect.disabled=true;
    try{const info=await inspectCurrentServer(location.origin,request);location.assign(connectionDestination(new URL(location.origin),info,shell).href);}
    catch(error){currentStatus.textContent=error.message;reconnect.disabled=false;}
  });
  const directoryForm=document.getElementById('directoryForm'),directoryStatus=document.getElementById('directoryStatus'),list=document.getElementById('serverList'),refresh=document.getElementById('refreshServers');
  directoryForm.elements.directory.value=defaultDirectory;
  const refreshList=async event=>{
    event?.preventDefault();if(refresh.disabled)return;refresh.disabled=true;list.replaceChildren();directoryStatus.textContent='Checking listed worlds…';
    try{
      const entries=await inspectDirectory(directoryForm.elements.directory.value,request);directoryStatus.textContent=entries.length?`${entries.length} listed ${entries.length===1?'world':'worlds'}`:'No listed worlds are online.';
      for(const entry of entries){
        const row=document.createElement('button');row.type='button';const summary=document.createElement('div'),name=document.createElement('b'),detail=document.createElement('span'),join=document.createElement('span');name.textContent=entry.name;detail.textContent=`${entry.requiresInvite?'Password required':'Open'} · ${entry.players} ${entry.players===1?'player':'players'}${rateSummary(entry)?' · '+rateSummary(entry):''}`;join.textContent='Join →';summary.append(name,detail);row.append(summary,join);row.title=entry.url;
        row.addEventListener('click',async()=>{
          if(row.disabled)return;row.disabled=true;
          try{const target=serverAddress(entry.url),info=await inspectServer(target,request);directoryStatus.textContent=`Opening ${info.name}…`;location.assign(connectionDestination(target,info,shell).href);}
          catch(error){directoryStatus.textContent=error.message;row.disabled=false;}
        });list.append(row);
      }
    }catch(error){directoryStatus.textContent=error instanceof TypeError?'Could not reach that directory. Check its HTTPS address.':error.message;}finally{refresh.disabled=false;}
  };
  directoryForm.addEventListener('submit',refreshList);
  if(defaultDirectory)void refreshList();
  return ready;
}
if(globalThis.document)void mountPortal();
