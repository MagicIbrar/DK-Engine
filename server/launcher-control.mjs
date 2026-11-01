// A private host token controls only this process. It is never exposed to browser assets or accounts.
import fs from 'node:fs/promises';
import path from 'node:path';
import { randomBytes, timingSafeEqual } from 'node:crypto';
import { ownerLocalRequest, protectLauncherFile } from './accounts/owner-auth.mjs';
import { serverName } from './world/rates.mjs';
const local = address => address === '::1' || address === '127.0.0.1' || address === '::ffff:127.0.0.1';
function reply(res,status,value){res.writeHead(status,{'Content-Type':'application/json','Cache-Control':'no-store'});res.end(JSON.stringify(value));}
export function launcherStorageDetails(mode, details) {
  if(mode!=='sqlserver')return {mode};
  // Only nonsecret instance/database names belong in the private launcher status.
  const instance=typeof details?.instance==='string'&&/^(?:\.|\(local\)|localhost|[A-Za-z0-9][A-Za-z0-9.-]*)(?:\\[A-Za-z0-9_$-]+)?(?:,[0-9]{1,5})?$/.test(details.instance)?details.instance:null;
  const database=typeof details?.database==='string'&&/^[A-Za-z_][A-Za-z0-9_]{0,127}$/.test(details.database)?details.database:null;
  return {mode,instance,database};
}
export function launcherControlFile(engine, port) {
  if (!Number.isInteger(port) || port < 1 || port > 65535) throw new Error('Invalid launcher port.');
  return path.join(engine, 'server', `launcher-control-${port}.json`);
}
export function createLauncherControl({engine,status,storageMode='json',storageDetails=null,characters=null,players=()=>0,connections=async()=>0,stop,preparation=null,ownerLaunch=null,ownerAccounts=null,settings=null,capacity=null,activePermissions=async()=>null,adminGuildStatus=()=>null,publication=async()=>{throw new Error('Publication is unavailable.');},actor=()=>null,now=Date.now,file=path.join(engine,'server','launcher-control.json')}) {
  const token=randomBytes(32).toString('hex'),startedAt=Date.now(); let stopping=false;
  let run=null,primary=null,pending=null,ownerAvailable=false;
  const matches = value => {if(typeof value!=='string')return false;const bytes=Buffer.from(value),expected=Buffer.from(token);return bytes.length===expected.length&&timingSafeEqual(bytes,expected)};
  const readyActor = (id,lease) => {
    const p=actor(id),ready=p?.launcherReady;
    return !!(run&&primary===id&&!stopping&&p&&!p.leaving&&!p.sceneTransition&&p.token===lease&&ready?.lease===lease&&ready.map===p.map&&now()-ready.at>=0&&now()-ready.at<6500);
  };
  const builderReady = async () => {
    if(!primary)return false;const p=actor(primary);
    if(!readyActor(primary,p?.token))return false;
    const access=await activePermissions(primary);return !!(access?.capabilities?.includes('gm:panel')&&readyActor(primary,p?.token));
  };
  return {
    clientReady(id,lease,ready,map,sequence){
      const p=actor(id);
      if(!p||p.token!==lease||primary!==id||!Number.isSafeInteger(sequence)||sequence<1)return false;
      if(p.launcherReadySequence?.lease===lease&&sequence<=p.launcherReadySequence.sequence)return false;
      p.launcherReadySequence={lease,sequence};
      if(!ready){delete p.launcherReady;pending=null;return false;}
      if(!run||stopping||p.leaving||p.sceneTransition||p.map!==map)return false;
      p.launcherReady={lease,map,at:now()};return true;
    },
    authenticated(id){if(run&&!primary)primary=id;},
    drain(id,lease){
      if(pending&&pending.expires<Date.now())pending=null;
      if(!pending||primary!==id||pending.lease!==lease)return [];
      if(!readyActor(id,lease)){pending=null;return [];}
      const commands=[{tool:pending.tool,id:pending.id}];pending=null;return commands;
    },
    async publish(url,controlUrl=url){
      await fs.mkdir(path.dirname(file),{recursive:true});
      const previous=await fs.lstat(file).catch(e=>{if(e.code==='ENOENT')return null;throw e;});
      if(previous&&(!previous.isFile()||previous.isSymbolicLink()||previous.nlink>1))throw new Error('Launcher control file must be an ordinary private file.');
      const temporary=file+'.'+randomBytes(6).toString('hex')+'.tmp';
      try{await fs.writeFile(temporary,'',{flag:'wx',mode:0o600});ownerAvailable=await protectLauncherFile(temporary,engine);await fs.writeFile(temporary,JSON.stringify({engineId:status.engineId,pid:status.pid,url,controlUrl,token,startedAt}));await fs.rename(temporary,file);}finally{await fs.rm(temporary,{force:true}).catch(()=>{});}
    },
    async clean(){try{const saved=JSON.parse(await fs.readFile(file,'utf8'));if(saved.token===token&&saved.pid===status.pid)await fs.unlink(file);}catch(e){if(e.code!=='ENOENT')console.warn('[launcher] control cleanup failed');}},
    async handle(req,res,pathname){
      if(!pathname.startsWith('/api/launcher/'))return false;
      if(!ownerLocalRequest(req)||!matches(req.headers['x-dekaron-launcher-token'])){reply(res,403,{error:'This endpoint requires the private local launcher.'});return true;}
      if(req.headers.origin!==undefined||req.headers['sec-fetch-site']==='cross-site'){reply(res,403,{error:'Browser requests cannot control the local server.'});return true;}
      if(pathname==='/api/launcher/characters'){
        if(!ownerAvailable||!characters||stopping)reply(res,403,{error:'Character roster requires the local installation owner.'});
        else if(req.method!=='GET')reply(res,405,{error:'Character roster requires GET.'});
        else reply(res,200,{characters:await characters()});
      }
      else if(pathname==='/api/launcher/status'&&req.method==='GET')reply(res,200,{...status,storageMode,storage:launcherStorageDetails(storageMode,storageDetails),startedAt,players:players(),connectedClients:Math.max(Number(status.realPlayers)||0,await connections()),stopping,primary:primary||null,builderReady:await builderReady(),ownerAvailable:ownerAvailable&&!!ownerLaunch,accountsAvailable:ownerAvailable&&!!ownerAccounts&&!stopping,settingsAvailable:ownerAvailable&&!!settings&&!stopping,name:settings?.read().name || 'Dekaron Online',adminGuild:adminGuildStatus()});
      else if(pathname==='/api/launcher/preparation'){
        if(req.method!=='GET')reply(res,405,{error:'Preparation status requires GET.'});
        else if(new URL(req.url,'http://localhost').search)reply(res,400,{error:'Preparation status accepts no parameters.'});
        else reply(res,200,{...status,stopping,preparation:stopping||!preparation?{ready:false,phase:'failed',retryAfterMs:0,error:'Shared world preparation is unavailable.'}:preparation()});
      }
      else if(pathname==='/api/launcher/settings'){
        if(!ownerAvailable){reply(res,403,{error:'Server settings require the installation owner.'});return true;}
        if(stopping||!settings){reply(res,503,{error:stopping?'The server is stopping.':'Server settings are unavailable.'});return true;}
        if(req.method==='GET')reply(res,200,settings.read());
        else if(req.method==='POST'||req.method==='PUT'){
          let change;
          try{
            if(!/^application\/json(?:\s*;|$)/i.test(req.headers['content-type']||''))throw Error('Expected JSON.');
            const chunks=[];let size=0;for await(const chunk of req){size+=Buffer.byteLength(chunk);if(size>512){reply(res,413,{error:'Server settings request too large.'});return true;}chunks.push(Buffer.from(chunk));}
            const input=JSON.parse(Buffer.concat(chunks).toString('utf8'));
            // one change per request: the server name, or the per-server starter pack switch (new characters get the starter kit or not)
            if(!input||Array.isArray(input)||Object.keys(input).length!==1)throw Error('Expected one setting.');
            if(req.method==='PUT'){if(!Object.hasOwn(input,'npcPopulation')||!Number.isInteger(input.npcPopulation)||input.npcPopulation<10||input.npcPopulation>100||typeof settings.npcPopulation!=='function')throw Error('Invalid bot population.');change={npcPopulation:input.npcPopulation};}
            else if(Object.hasOwn(input,'npcLanguage')){if(!['en','es','pt','de','fr'].includes(input.npcLanguage)||typeof settings.npcLanguage!=='function')throw Error('Invalid bot language.');change={npcLanguage:input.npcLanguage};}
            else if(Object.hasOwn(input,'name'))change={name:serverName(input.name)};
            else{const key=['starterPack','fieldPk','npcPlayers'].find(k=>Object.hasOwn(input,k)&&typeof input[k]==='boolean'&&typeof settings[k]==='function');if(!key)throw Error('Expected a server name or a server switch.');change={[key]:input[key]};}
          }catch{reply(res,400,{error:'POST one server name, boolean switch (starterPack / fieldPk / npcPlayers), or npcLanguage (en / es / pt / de / fr); PUT one npcPopulation integer from 10 to 100.'});return true;}
          if(stopping){reply(res,503,{error:'The server is stopping.'});return true;}
          try{reply(res,200,await settings.set(change));}
          catch{reply(res,503,{error:'The setting could not be saved. Refresh settings before retrying.'});}
        }else reply(res,405,{error:'Unsupported server settings operation.'});
      }
      // Dashboard > Settings > Server capacity (live numbers; player cap / upload apply at once, memory at the next start)
      else if(pathname==='/api/launcher/capacity'){
        if(!ownerAvailable){reply(res,403,{error:'Server capacity requires the installation owner.'});return true;}
        if(stopping||!capacity){reply(res,503,{error:stopping?'The server is stopping.':'Server capacity is unavailable.'});return true;}
        if(req.method==='GET')reply(res,200,capacity.read());
        else if(req.method==='POST'){
          let input;
          try{
            if(!/^application\/json(?:\s*;|$)/i.test(req.headers['content-type']||''))throw Error('Expected JSON.');
            const chunks=[];let size=0;for await(const chunk of req){size+=Buffer.byteLength(chunk);if(size>1024){reply(res,413,{error:'Capacity request too large.'});return true;}chunks.push(Buffer.from(chunk));}
            input=JSON.parse(Buffer.concat(chunks).toString('utf8'));
            if(!input||typeof input!=='object'||Array.isArray(input))throw Error('Expected capacity settings.');
          }catch{reply(res,400,{error:'Send the capacity settings as JSON.'});return true;}
          try{reply(res,200,await capacity.save(input));}
          catch(error){reply(res,400,{error:error?.message||'The capacity settings could not be saved.'});}
        }else reply(res,405,{error:'Unsupported capacity operation.'});
      }
      else if(pathname==='/api/launcher/owner-launch'&&req.method==='POST'){if(!ownerAvailable||!ownerLaunch||stopping)reply(res,403,{error:'Local admin requires the installation owner.'});else await ownerLaunch(req,res);}
      else if(pathname==='/api/launcher/accounts'){
        if(!ownerAvailable||!ownerAccounts){reply(res,403,{error:'Account management requires the installation owner.'});return true;}
        if(stopping){reply(res,503,{error:'The server is stopping.'});return true;}
        if(req.method==='GET'){
          try{reply(res,200,{accounts:await ownerAccounts.list()});}catch{reply(res,503,{error:'Registered accounts could not be read.'});}
        }else if(req.method==='POST'){
          let input;
          try{
            if(!/^application\/json(?:\s*;|$)/i.test(req.headers['content-type']||''))throw Error('Expected JSON.');
            const chunks=[];let size=0;for await(const chunk of req){size+=Buffer.byteLength(chunk);if(size>512){reply(res,413,{error:'Account request too large.'});return true;}chunks.push(Buffer.from(chunk));}
            input=JSON.parse(Buffer.concat(chunks).toString('utf8'));
            if(!input||typeof input!=='object'||Array.isArray(input)||Object.keys(input).length!==2||Object.keys(input).some(k=>!['account','role'].includes(k))||typeof input.account!=='string'||!/^\s*[a-z0-9_-]{3,32}\s*$/i.test(input.account)||!['gm','player'].includes(input.role))throw Error('Invalid account request.');
          }catch{reply(res,400,{error:'Expected registered account and player or gm role.'});return true;}
          try{const changed=await ownerAccounts.set(input);reply(res,200,{account:changed.id,role:changed.role,capabilities:changed.capabilities,leaseInvalidated:true});}
          catch(error){const expected=/installation owner|registered account|Invalid account ID|Expected registered account|Role must be/.test(error.message||'');reply(res,expected?400:503,{error:expected?error.message:'The permission change could not be confirmed. Refresh accounts before retrying.'});}
        }else reply(res,405,{error:'Unsupported account operation.'});
      }
      else if(pathname==='/api/launcher/publication'&&req.method==='POST'){try{if(stopping)throw new Error('The server is stopping.');const chunks=[];let size=0;for await(const chunk of req){size+=chunk.length;if(size>4096)throw new Error('Publication request too large.');chunks.push(chunk);}const value=JSON.parse(Buffer.concat(chunks).toString('utf8'));if(!value||Array.isArray(value)||Object.keys(value).some(k=>!['enabled','url'].includes(k))||typeof value.enabled!=='boolean')throw new Error('Invalid publication request.');reply(res,200,await publication(value));}catch{reply(res,400,{error:'Publication failed. Verify open mode and the relay hostname.'});}}
      else if(pathname==='/api/launcher/begin'&&req.method==='POST'){
        // A second launcher cannot silently retarget the first launcher's primary.
        if(!run){run=randomBytes(16).toString('hex');primary=null;pending=null;}
        reply(res,200,{run,primary});
      }
      else if(pathname==='/api/launcher/tool'&&req.method==='POST'){
        try{
          if(stopping)throw Object.assign(new Error('The server is stopping.'),{status:503});
          let raw='';for await(const chunk of req){raw+=chunk;if(raw.length>512)throw Object.assign(new Error('Tool request too large.'),{status:413});}
          let input;try{input=JSON.parse(raw);}catch{throw Object.assign(new Error('Expected a tool request.'),{status:400});}
          if(!input||typeof input!=='object'||Array.isArray(input)||Object.keys(input).some(k=>k!=='tool')||!['itembuilder','mapbuilder'].includes(input.tool))throw Object.assign(new Error('Unknown builder.'),{status:400});
          if(!primary)throw Object.assign(new Error('Log in to the first game window and enter a character first.'),{status:409});
          const access=await activePermissions(primary);
          if(!access)throw Object.assign(new Error('The primary account must log back in. Another account cannot replace it.'),{status:409});
          if(!access.capabilities?.includes('gm:panel'))throw Object.assign(new Error('The primary account does not have GM builder permission.'),{status:403});
          const p=actor(primary);
          if(!p||p.leaving)throw Object.assign(new Error('Enter a character on the primary account first.'),{status:409});
          if(!readyActor(primary,p.token))throw Object.assign(new Error('Wait until the primary GM game has fully loaded and is connected.'),{status:409});
          if(pending&&pending.expires>=Date.now()&&pending.lease===p.token)throw Object.assign(new Error('A builder request is already waiting for the primary game window.'),{status:409});
          pending={tool:input.tool,id:randomBytes(16).toString('hex'),lease:p.token,expires:Date.now()+30000};
          reply(res,200,{queued:true,primary,tool:input.tool});
        }catch(error){reply(res,error.status||500,{error:error.message});}
      }
      else if(pathname==='/api/launcher/stop'&&req.method==='POST'){
        if(stopping){reply(res,409,{error:'The server is already stopping.'});return true;}
        const connected=Math.max(Number(status.realPlayers)||0,await connections());
        if(connected>0){reply(res,409,{error:'Disconnect all clients from this server before stopping it. Sign out of the lobby too, or wait one minute after closing a client.',connectedClients:connected});return true;}
        if(stopping){reply(res,409,{error:'The server is already stopping.'});return true;}
        stopping=true;
        try{await stop();reply(res,200,{stopped:true,saved:true});res.once('finish',()=>{});}
        catch(error){stopping=false;reply(res,503,{error:'The server could not save all progress. It has not been terminated.'});console.error('[launcher] stop failed',error);}
      }else reply(res,405,{error:'Unsupported launcher operation.'});
      return true;
    },
  };
}

