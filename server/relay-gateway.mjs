import http from 'node:http';
import {isIP} from 'node:net';
import {createHmac,timingSafeEqual} from 'node:crypto';
import {isPublicConnectorAsset} from './public-assets.mjs';

const loopback=ip=>['127.0.0.1','::1','::ffff:127.0.0.1'].includes(ip);
const hop=new Set(['connection','keep-alive','proxy-authenticate','proxy-authorization','te','trailer','transfer-encoding','upgrade']);
const commandHeaders=new Set(['x-dekaron-command-sequence','x-dekaron-command-time']);
export function publicRelayOrigin(value){const u=new URL(value),hostname=u.hostname.replace(/\.+$/,'');if(u.protocol!=='https:'||u.username||u.password||u.port||u.pathname!=='/'||u.search||u.hash||isIP(u.hostname)||!hostname.includes('.')||hostname.endsWith('.localhost'))throw new Error('Use a public HTTPS origin.');return u.origin;}
// Only the privately configured gateway can assign a public request identity.
export function authenticateRelayRequest(req,{secret,origin}={}){
  const given=req.headers['x-dekaron-relay-secret'];
  if(!loopback(req.socket.remoteAddress)||!/^([a-f0-9]{64})$/.test(secret||'')||typeof given!=='string')return null;
  const a=Buffer.from(given),b=Buffer.from(secret);if(a.length!==b.length||!timingSafeEqual(a,b))return null;
  const clientKey=req.headers['x-dekaron-relay-client'];if(!/^[a-f0-9]{64}$/.test(clientKey||''))return null;
  const transport=req.headers['x-dekaron-relay-transport'];if(transport!==undefined&&!['polling','sse'].includes(transport))return null;
  let actual;try{actual=publicRelayOrigin('https://'+req.headers.host);}catch{return null;}
  if(origin&&actual!==publicRelayOrigin(origin))return null;
  if(req.headers.origin&&req.headers.origin!==actual)return null;
  return {origin:actual,clientKey,secure:true,transport:transport||'sse'};
}
function permitted(raw){
  if(!raw.startsWith('/')||raw.startsWith('//')||/[\\\x00-\x20]/.test(raw))return false;
  let pathname;try{pathname=decodeURIComponent(raw.split('?')[0]);}catch{return false;}
  if(/[\\%]/.test(pathname)||pathname.split('/').some(s=>s==='.'||s==='..'))return false;
  if(/^\/web(?:\/|$)/i.test(pathname))return isPublicConnectorAsset(pathname);
  if(pathname==='/api/auth/demo'||pathname==='/api/world/launcher-tools')return false;
  if(pathname.startsWith('/api/'))return /^\/api\/(auth\/|world\/|friends\/|forum\/)/.test(pathname)||['/api/server/info','/api/characters','/api/rankings','/api/ls'].includes(pathname);
  return !/^\/(server|tools|deploy|docs|\.client-cache|runtime)(\/|$)/i.test(pathname);
}
export function createRelayGateway({backend,secret,origin=null,quick=false,maxRequests=192,maxPerClient=24,timeout=30000}={}){
  const target=new URL(backend);if(target.protocol!=='http:'||target.hostname!=='127.0.0.1'||target.username||target.password||target.pathname!=='/'||target.search||target.hash)throw new Error('Relay target must be the selected loopback engine.');
  if(!/^[a-f0-9]{64}$/.test(secret||''))throw new Error('Private relay secret is required.');
  let published=origin?publicRelayOrigin(origin):null,active=0,closed=false;const requests=new Set(),perClient=new Map();
  const fail=(res,status)=>{res.writeHead(status,{'Content-Type':'application/json','Cache-Control':'no-store'});res.end(JSON.stringify({error:status===503?'Relay unavailable.':status===429?'Too many connections from your address.':'Request not available.'}));};
  const server=http.createServer({noDelay:true},(req,res)=>{
    if(closed||!published)return fail(res,503);
    if(!loopback(req.socket.remoteAddress)||req.headers.host!==new URL(published).host||!permitted(req.url))return fail(res,404);
    const discovery=['GET','HEAD'].includes(req.method)&&req.url.split('?')[0]==='/api/friends/status';
    if(!discovery&&req.headers.origin&&req.headers.origin!==published)return fail(res,403);
    if(quick&&req.url.split('?')[0]==='/api/world/events')return fail(res,501);
    if(active>=maxRequests)return fail(res,503);
    // Per-IP concurrency cap (item 2). The key is the edge-set CF-Connecting-IP; a request without it cannot be attributed and only counts toward the total cap.
    const ipKey=typeof req.headers['cf-connecting-ip']==='string'?req.headers['cf-connecting-ip']:null;
    if(ipKey&&(perClient.get(ipKey)||0)>=maxPerClient)return fail(res,429);
    const headers={};const connectionTokens=String(req.headers.connection||'').toLowerCase().split(',').map(x=>x.trim());
    for(const [key,value]of Object.entries(req.headers))if(!hop.has(key)&&!connectionTokens.includes(key)&&(!key.startsWith('x-dekaron-')||commandHeaders.has(key))&&!key.startsWith('x-forwarded-')&&!['forwarded','cf-connecting-ip','cf-connecting-ipv6','cf-ray','true-client-ip'].includes(key))headers[key]=value;
    // Public portal discovery never forwards credentials or an external Origin.
    if(discovery)for(const key of ['origin','cookie','authorization'])delete headers[key];
    // Cloudflare overwrites CF-Connecting-IP at its edge; never use it for permissions.
    headers['x-dekaron-relay-secret']=secret;headers['x-dekaron-relay-client']=createHmac('sha256',secret).update(String(req.headers['cf-connecting-ip']||'unknown')).digest('hex');
    headers['x-dekaron-relay-transport']=quick?'polling':'sse';
    active++;if(ipKey)perClient.set(ipKey,(perClient.get(ipKey)||0)+1);
    const upstream=http.request(target,{method:req.method,path:req.url,headers},incoming=>{
      const outgoing={};for(const [key,value]of Object.entries(incoming.headers))if(!hop.has(key)&&!key.startsWith('x-dekaron-')&&!key.startsWith('x-powered-'))outgoing[key]=value;
      if(discovery){outgoing['access-control-allow-origin']='*';delete outgoing['access-control-allow-credentials'];delete outgoing['set-cookie'];}
      if(outgoing.location){try{const u=new URL(outgoing.location,published);if(u.origin!==published){incoming.destroy();return fail(res,502);}}catch{incoming.destroy();return fail(res,502);}}
      const cookies=outgoing['set-cookie'];if(cookies&&[].concat(cookies).some(c=>!/(?:^|;)\s*Secure(?:;|$)/i.test(c))){incoming.destroy();return fail(res,502);}
      res.writeHead(incoming.statusCode,outgoing);incoming.pipe(res);incoming.on('error',()=>res.destroy());
    });
    upstream.on('socket',socket=>socket.setNoDelay?.(true)); // MOVE-NO-RUBBERBAND: forwarded movement is not Nagle-delayed
    requests.add(upstream);let released=false;
    const release=()=>{if(released)return;released=true;active--;if(ipKey){const left=(perClient.get(ipKey)||1)-1;if(left>0)perClient.set(ipKey,left);else perClient.delete(ipKey);}requests.delete(upstream);upstream.destroy();};
    res.once('close',release);req.once('aborted',release);
    upstream.setTimeout(timeout,()=>upstream.destroy(new Error('timeout')));
    upstream.on('error',()=>{if(!res.headersSent)fail(res,502);else res.destroy();});req.pipe(upstream);
  });
  server.headersTimeout=15000;server.requestTimeout=30000;server.on('upgrade',(_req,socket)=>socket.destroy());
  return {server,setOrigin(value){published=publicRelayOrigin(value);},status(){return {active,origin:published,quick,clients:perClient.size};},async close(){closed=true;for(const req of requests)req.destroy();server.closeAllConnections();await new Promise(resolve=>server.close(resolve));}};
}
