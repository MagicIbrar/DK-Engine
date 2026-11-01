import { ownerLocalRequest } from './accounts/owner-auth.mjs';

const ROUTE='/api/world/server-control';
const json=(res,status,value)=>{res.writeHead(status,{'Content-Type':'application/json','Cache-Control':'no-store'});res.end(JSON.stringify(value));};
/** One lifecycle for the private launcher and the authenticated in-game owner. */
export function createGameShutdown({resolveUser,save,clean=async()=>{},close,now=Date.now,setTimer=setTimeout,clearTimer=clearTimeout,countdownMs=10000,finishDelay=1500}={}) {
  let phase='running',deadline=null,error=null,version=0,countdown=null,finish=null,pending=null;
  const mutations=new Set();
  const change=(value)=>{phase=value;version++;};
  const status=()=>({state:phase,serverTime:now(),deadline,remaining:phase==='countdown'?Math.max(0,Math.ceil((deadline-now())/1000)):0,error,version});
  const originOK=req=>!req.headers.origin||req.headers.origin===(req.relay?.origin||`${req.socket.encrypted?'https':'http'}://${req.headers.host}`);
  const localHost=req=>{try{const url=new URL(`http://${req.headers.host}`);return !url.username&&!url.password&&['localhost','127.0.0.1','[::1]'].includes(url.hostname);}catch{return false;}};
  const owner=(req,user)=>localHost(req)&&user?.id==='admin'&&user.capabilities?.includes('gm:panel')&&ownerLocalRequest(req)&&originOK(req);
  async function stopNow(){
    if(pending)return pending;
    if(countdown){clearTimer(countdown);countdown=null;}
    change('saving');
    pending=(async()=>{
      // Includes accepted account/character HTTP mutations, not just world commands.
      await Promise.allSettled([...mutations]);
      await save();
      try{await clean();}catch{console.error('[server] saved shutdown could not remove its private control file');}
      error=null;change('saved');
      // Give connected clients a short chance to read the saved notice/logout.
      finish=setTimer(()=>{finish=null;close();},finishDelay);finish?.unref?.();
      return status();
    })().catch(err=>{error='Progress could not be saved. The server remains running.';deadline=null;change('failed');pending=null;throw err;});
    return pending;
  }
  return {
    status,stopNow,
    get saving(){return phase==='saving'||phase==='saved';},
    track(req,res,pathname){
      if(!['POST','PUT','PATCH','DELETE'].includes(req.method)||!pathname.startsWith('/api/')||[ROUTE,'/api/launcher/stop','/api/auth/logout'].includes(pathname))return;
      let done;const wait=new Promise(resolve=>done=resolve);mutations.add(wait);
      return ()=>{mutations.delete(wait);done();};
    },
    dispose(){if(countdown)clearTimer(countdown);if(finish)clearTimer(finish);},
    async handle(req,res,pathname){
      if(pathname!==ROUTE)return false;
      try{
        const user=await resolveUser(req);
        if(!user){json(res,401,{error:'Sign in before using server controls.'});return true;}
        if(!originOK(req)){json(res,403,{error:'Server controls require the same origin.'});return true;}
        if(req.method==='GET'){json(res,200,{...status(),canStop:!!owner(req,user)});return true;}
        if(req.method!=='POST'){json(res,405,{error:'Method not allowed.'});return true;}
        if(!owner(req,user)||!req.headers.origin){json(res,403,{error:'Only the installation owner signed in locally can stop this server.'});return true;}
        if(!String(req.headers['content-type']||'').startsWith('application/json')){json(res,400,{error:'Use the server stop control.'});return true;}
        let text='';for await(const bytes of req){text+=bytes;if(Buffer.byteLength(text)>128){json(res,413,{error:'Server control request is too large.'});return true;}}
        const value=JSON.parse(text||'{}');
        if(!value||Array.isArray(value)||Object.keys(value).length){json(res,400,{error:'The countdown is fixed at ten seconds.'});return true;}
        if(!owner(req,await resolveUser(req))){json(res,403,{error:'The owner session is no longer valid.'});return true;}
        if(phase==='running'||phase==='failed'){
          error=null;deadline=now()+countdownMs;change('countdown');
          countdown=setTimer(()=>{countdown=null;void stopNow().catch(()=>{});},countdownMs);countdown?.unref?.();
        }
        json(res,202,{...status(),canStop:true});
      }catch(err){json(res,err instanceof SyntaxError?400:500,{error:err instanceof SyntaxError?'Invalid server control request.':'Server controls are unavailable.'});}
      return true;
    },
  };
}
