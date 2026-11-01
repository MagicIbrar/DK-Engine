export function serverAddress(value) {
  let text = String(value || '').trim();
  if (!text || text.length > 512 || /\s/.test(text)) throw new Error('Enter the server address your host shared.');
  const suppliedScheme = /^[a-z][a-z0-9+.-]*:\/\//i.test(text);
  if (!suppliedScheme) {
    const local = /^(?:localhost(?::|$)|\d{1,3}(?:\.\d{1,3}){3}(?::|$)|\[)/i.test(text);
    text = `${local ? 'http' : 'https'}://${text}`;
  }
  let url; try { url = new URL(text); } catch { throw new Error('Use an IP:port or an HTTPS server address.'); }
  if (!['http:', 'https:'].includes(url.protocol) || url.username || url.password || url.search || url.hash || !['/', '/join'].includes(url.pathname)) throw new Error('Enter only the server address, without a password or extra path.');
  if (!suppliedScheme && url.protocol === 'http:' && !url.port) url.port = '7778';
  if(url.protocol==='http:'){
    const octets=url.hostname.split('.').map(Number),local=url.hostname==='localhost'||url.hostname==='[::1]'||octets.length===4&&octets.every(n=>Number.isInteger(n)&&n>=0&&n<=255)&&(octets[0]===127||octets[0]===10||octets[0]===172&&octets[1]>=16&&octets[1]<=31||octets[0]===192&&octets[1]===168);
    if(!local)throw new Error('Internet servers require HTTPS.');
  }
  return new URL('/join', url.origin);
}
export function compatibleServer(info) {
  return info?.app === 'dekaron-engine' && info.version === 1 && info.protocol === 1 && typeof info.name === 'string' && info.name.length > 0 && info.name.length <= 64 && ((info.hostMode==='friends'&&info.requiresInvite===true)||(info.hostMode==='open'&&info.requiresInvite===false));
}
export async function inspectServer(url, request = fetch) {
  const response = await request(new URL('/api/friends/status', url), { credentials: 'omit', cache: 'no-store', redirect: 'error', signal: AbortSignal.timeout(6000) });
  if (!response.ok) throw new Error('This address is not accepting connections.');
  const info = await response.json();
  if (!compatibleServer(info)) throw new Error('No compatible game server found at this address.');
  return info;
}
/** The window this page runs in: client=desktop (launcher windows) and shell=native (Dekaron.exe, which owns its window size/fullscreen). */
export function clientWindow(search){const q=new URLSearchParams(search||''),flags={desktop:q.get('client')==='desktop',native:q.get('shell')==='native'};if(q.get('client')==='phone')flags.phone=true;return flags;}
/** Presentation only. Touch browsers use the same pages without requiring an Android shell. */
export function phonePresentationRequested({search=globalThis.location?.search||'',matchMedia=globalThis.matchMedia,width=globalThis.innerWidth}={}){
  const client=new URLSearchParams(search).get('client');
  return client==='phone'||client!=='desktop'&&Number(width)<=1366&&!!matchMedia?.('(pointer: coarse)').matches;
}
/** Adds the window flags to a same-flow destination so the next page keeps the same client behaviour. */
export function withClientWindow(target,{desktop=false,native=false,phone=false}={}){if(desktop)target.searchParams.set('client','desktop');else if(phone)target.searchParams.set('client','phone');if(native)target.searchParams.set('shell','native');return target;}
export function connectionDestination(url,info,{desktop=false,native=false,phone=false}={}){const target=new URL(!phone&&(info.hostMode==='open'||info.hostMode==='local')?'/?screen=login&credentials=1':'/join',url.origin);return withClientWindow(target,{desktop,native,phone});}
/** Verify this origin's ordinary session; an unavailable service is not an anonymous session. */
export async function verifiedSession(origin,request=globalThis.fetch){
  let response;try{response=await request(new URL('/api/auth/me',origin),{credentials:'same-origin',cache:'no-store',redirect:'error',signal:AbortSignal.timeout(7000)});}catch{throw new Error('Could not check your account session. Check the connection and retry.');}
  if(response.status===401)return null;
  if(!response.ok)throw new Error('The account service is unavailable. Retry or choose another world.');
  let data;try{data=await response.json();}catch{throw new Error('The server did not confirm your account session. Retry.');}
  if(data?.id===null)return null;
  if(typeof data?.id!=='string'||!data.id||data.id.length>32)throw new Error('The server did not confirm your account session. Retry.');
  return data.id;
}
/** Called only for the page's own origin. A private local server has metadata but no public discovery endpoint. */
export async function inspectCurrentServer(origin,request=fetch) {
  const options={credentials:'omit',cache:'no-store',redirect:'error',signal:AbortSignal.timeout(6000)};
  let response=await request(new URL('/api/friends/status',origin),options);
  if(response.status===404){
    response=await request(new URL('/api/server/info',origin),options);
    if(!response.ok)throw new Error('No game server on this website.');
    const info=await response.json();
    if(info.protocol!==1||typeof info.name!=='string'||!info.name||info.name.length>64)throw new Error('No compatible game server on this website.');
    return {...info,hostMode:'local',requiresInvite:false};
  }
  if(!response.ok)throw new Error('This server is unavailable.');
  const info=await response.json();if(!compatibleServer(info))throw new Error('No compatible game server on this website.');return info;
}
export function rateSummary(info){const rates=info?.rates;if(!rates||['exp','dil','drop'].some(key=>!Number.isFinite(rates[key])||rates[key]<=0))return '';return `EXP ${rates.exp}× · DIL ${rates.dil}× · Drops ${rates.drop}×`;}
export function accountDestination(origin,kind,{desktop=false,native=false,phone=false}={}){
  const next=new URL('/',origin);next.searchParams.set('screen',phone||kind==='signup'?'select':'login');if(!phone&&kind!=='signup')next.searchParams.set('credentials','1');withClientWindow(next,{desktop,native,phone});
  if(phone){const target=new URL(kind==='signup'?'/site/signup.html':'/site/login.html',origin);target.searchParams.set('client','phone');target.searchParams.set('next',next.pathname+next.search);return target;}
  if(kind!=='signup')return next;
  const target=new URL('/site/signup.html',origin);target.searchParams.set('next',next.pathname+next.search);return target;
}
export function directoryAddress(value){const u=new URL(value);if(u.protocol!=='https:'||u.username||u.password||u.pathname!=='/'||u.search||u.hash)throw new Error('Use the directory HTTPS address without extra paths.');return u;}
export async function inspectDirectory(value,request=fetch){
 const url=directoryAddress(value),response=await request(new URL('/api/servers',url),{credentials:'omit',cache:'no-store',redirect:'error',signal:AbortSignal.timeout(8000)});
 if(!response.ok)throw new Error('The public server directory is unavailable.');
 const data=await response.json();if(data.app!=='dekaron-directory'||data.version!==1||data.protocol!==1||!Array.isArray(data.servers)||data.servers.length>1000)throw new Error('This is not a compatible public server directory.');
 const seen=new Set();return data.servers.filter(entry=>{
  try{const destination=directoryAddress(entry.url);if(!((entry.hostMode==='open'&&entry.requiresInvite===false)||(entry.hostMode==='friends'&&entry.requiresInvite===true))||entry.protocol!==1||entry.version!==1||typeof entry.id!=='string'||!entry.id||typeof entry.name!=='string'||entry.name.length>64||!Number.isSafeInteger(entry.players)||entry.players<0||seen.has(destination.origin))return false;seen.add(destination.origin);return true;}catch{return false;}
 });
}
