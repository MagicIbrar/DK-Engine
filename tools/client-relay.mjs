// Portable, opt-in transport. No system installation, router changes, or public demo.
import fs from 'node:fs/promises';
import path from 'node:path';
import {fileURLToPath} from 'node:url';
import {createHash,randomBytes} from 'node:crypto';
import {spawn} from 'node:child_process';
import readline from 'node:readline';
import {createRelayGateway,publicRelayOrigin} from '../server/relay-gateway.mjs';
export const CLOUDFLARED={version:'2026.9.3',url:'https://github.com/cloudflare/cloudflared/releases/download/2026.9.3/cloudflared-windows-amd64.exe',sha256:'f096265ec2fcbe9bb6e2d64268db167ced3fcbb83d894bdb9e2fcdb26f2ea7e2',source:'https://api.github.com/repos/cloudflare/cloudflared/releases/tags/2026.9.3'};
export async function ordinaryPath(value,{file=false}={}){
  const full=path.resolve(value);let at=path.parse(full).root;
  for(const component of path.relative(at,full).split(path.sep).filter(Boolean)){at=path.join(at,component);const st=await fs.lstat(at).catch(e=>{if(e.code==='ENOENT')return null;throw e;});if(!st)continue;if(st.isSymbolicLink()||st.isFile()&&st.nlink!==1)throw new Error('Relay paths must not contain links.');}
  if(file){const st=await fs.lstat(full);if(!st.isFile())throw new Error('Relay file is not an ordinary file.');}return full;
}
async function digest(file){if((await fs.stat(file)).size>100*1024*1024)throw new Error('Relay runtime exceeds its size limit.');return createHash('sha256').update(await fs.readFile(file)).digest('hex');}
export async function ensureCloudflared(engine,{download=fetch}={}){
  if(process.platform!=='win32'||process.arch!=='x64')throw new Error('This portable relay runtime currently requires Windows x64.');
  const directory=await ordinaryPath(path.join(engine,'runtime')),destination=await ordinaryPath(path.join(directory,`cloudflared-${CLOUDFLARED.version}.exe`));await fs.mkdir(directory,{recursive:true});
  try{if(await digest(destination)===CLOUDFLARED.sha256)return destination;throw new Error('Installed relay runtime failed verification.');}catch(e){if(e.code!=='ENOENT')throw e;}
  const temporary=path.join(directory,'.relay-'+randomBytes(12).toString('hex')+'.tmp');let output;
  try{
    output=await fs.open(temporary,'wx',0o600);let url=CLOUDFLARED.url,response;
    for(let redirects=0;redirects<=5;redirects++){
      const u=new URL(url);if(u.protocol!=='https:'||!['github.com','release-assets.githubusercontent.com','objects.githubusercontent.com'].includes(u.hostname))throw new Error('Unexpected relay download destination.');
      response=await download(url,{redirect:'manual',signal:AbortSignal.timeout(120000)});
      if([301,302,303,307,308].includes(response.status)){url=new URL(response.headers.get('location'),url).href;await response.body?.cancel();continue;}break;
    }
    if(!response?.ok||!response.body)throw new Error('Official relay download failed.');
    const hash=createHash('sha256');let bytes=0;for await(const chunk of response.body){bytes+=chunk.length;if(bytes>100*1024*1024)throw new Error('Relay download exceeds its size limit.');hash.update(chunk);await output.writeFile(chunk);}
    await output.sync();await output.close();output=null;
    if(hash.digest('hex')!==CLOUDFLARED.sha256)throw new Error('Official relay download failed SHA256 verification.');
    await ordinaryPath(destination);await fs.rename(temporary,destination);return destination;
  }finally{await output?.close().catch(()=>{});await fs.rm(temporary,{force:true}).catch(()=>{});}
}
export async function verifyRelayBackend(config,{request=fetch}={}){
  const u=new URL(config.backend);if(u.protocol!=='http:'||u.hostname!=='127.0.0.1'||u.pathname!=='/'||u.username||u.password||u.search||u.hash)throw new Error('Choose the selected loopback engine.');
  if(!/^[a-f0-9]{64}$/.test(config.secret||'')||!Number.isSafeInteger(config.pid)||config.pid<=0||!config.engineId)throw new Error('Private engine relay configuration is incomplete.');
  const response=await request(new URL('/api/client/status',u),{redirect:'error',signal:AbortSignal.timeout(5000)});if(!response.ok)throw new Error('Selected engine status is unavailable.');
  const status=await response.json();if(status.app!=='dekaron-engine'||status.engineId!==config.engineId||status.pid!==config.pid||status.listenHost!=='127.0.0.1'||status.relayEnabled!==true||status.localDemo!==false||!['open','friends'].includes(status.hostMode))throw new Error('Only a verified non-demo online engine can be published.');
  return status;
}
export function createRelayController({engine=fileURLToPath(new URL('../',import.meta.url)),runtime=ensureCloudflared,launch=spawn,verify=verifyRelayBackend}={}){
  let child=null,gateway=null,state='stopped',publicOrigin=null,mode=null;
  const status=()=>({state,publicOrigin,mode,transport:mode==='quick'?'polling':'sse',temporary:mode==='quick'});
  async function stop(){const owned=child;child=null;state='stopped';publicOrigin=null;if(owned&&!owned.killed){owned.kill();await new Promise(resolve=>{owned.once('exit',resolve);const timer=setTimeout(resolve,3000);timer.unref();});}const previous=gateway;gateway=null;if(previous)await previous.close();return status();}
  async function start(config){
    if(state!=='stopped')throw new Error('Stop the existing relay before starting another.');
    if(!['quick','named'].includes(config.mode))throw new Error('Select a temporary or managed relay.');
    if(config.mode==='quick'&&config.testOnly!==true)throw new Error('Temporary public testing must be explicitly selected.');
    await verify(config);mode=config.mode;state='starting';
    try{
      let tokenFile;if(mode==='named'){publicOrigin=publicRelayOrigin(config.publicOrigin);tokenFile=await ordinaryPath(config.tokenFile,{file:true});if(!Number.isInteger(config.gatewayPort)||config.gatewayPort<1024||config.gatewayPort>65535)throw new Error('Configure the managed tunnel loopback gateway port.');}
      const executable=await runtime(engine);gateway=createRelayGateway({backend:config.backend,secret:config.secret,origin:publicOrigin,quick:mode==='quick'});
      await new Promise((resolve,reject)=>{gateway.server.once('error',reject);gateway.server.listen(config.gatewayPort||0,'127.0.0.1',resolve);});
      const gatewayUrl=`http://127.0.0.1:${gateway.server.address().port}`;
      const args=mode==='quick'?['--no-autoupdate','tunnel','--url',gatewayUrl]:['--no-autoupdate','tunnel','run','--token-file',tokenFile];
      const childEnv={...process.env};for(const key of Object.keys(childEnv))if(key.startsWith('DEKARON_')||key.startsWith('TUNNEL_')||key.startsWith('CLOUDFLARE_'))delete childEnv[key];
      child=launch(executable,args,{windowsHide:true,stdio:['ignore','pipe','pipe'],env:childEnv});
      const owned=child;
      await new Promise((resolve,reject)=>{
        const timer=setTimeout(()=>reject(new Error('Relay did not become ready within 90 seconds.')),90000);timer.unref();let buffer='';
        const ready=()=>{clearTimeout(timer);state='online';resolve();};
        const inspect=chunk=>{buffer=(buffer+chunk.toString()).slice(-16000);if(mode==='quick'){const match=buffer.match(/https:\/\/[a-z0-9-]+\.trycloudflare\.com\b/);if(match){publicOrigin=publicRelayOrigin(match[0]);gateway.setOrigin(publicOrigin);}}if(publicOrigin&&/Registered tunnel connection/.test(buffer))ready();};
        child.stdout.on('data',inspect);child.stderr.on('data',inspect);
        child.once('error',()=>{clearTimeout(timer);reject(new Error('The verified relay executable could not start.'));});
        child.once('exit',()=>{clearTimeout(timer);reject(new Error('Relay exited before readiness.'));if(child===owned&&state==='online'){state='failed';void gateway?.close();gateway=null;}});
      });return {...status(),gatewayPort:gateway.server.address().port};
    }catch(error){await stop();throw error;}
  }
  return {start,stop,status};
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){
  const controller=createRelayController();const lines=readline.createInterface({input:process.stdin,crlfDelay:Infinity});let queue=Promise.resolve();
  const send=value=>process.stdout.write(JSON.stringify(value)+'\n');
  lines.on('line',line=>{queue=queue.then(async()=>{let input;try{if(line.length>16384)throw new Error('Relay request is too large.');input=JSON.parse(line);if(!['start','status','stop'].includes(input.command))throw new Error('Unknown relay command.');const result=input.command==='start'?await controller.start(input.config):input.command==='stop'?await controller.stop():controller.status();send({id:input.id,ok:true,...result});}catch(error){send({id:input?.id,ok:false,error:error.message.startsWith('Relay')||error.message.startsWith('Select')||error.message.startsWith('Only')||error.message.startsWith('Choose')||error.message.startsWith('Private')?error.message:'The relay could not start. Check its private configuration.'});}});});
  lines.on('close',()=>{void queue.finally(()=>controller.stop());});for(const signal of ['SIGINT','SIGTERM'])process.on(signal,()=>{void controller.stop().finally(()=>process.exit(0));});
}
