// Optional login version gate, matching Global DekaronServer CQ_Lock: the client's strVersion must equal the server's
// version (OnCQLock.cpp, "CQ_Lock Process Invalid Version [Client : %s] [Server : %s]"). The expected value comes from
// THIS host's own client data (share/version.ini, e.g. "VERSION,EU-18.0.3"), an operator override, or the applied
// Global version reported by global-update-watch. OFF unless DEKARON_LOGIN_VERSION_GATE=1; with no version found it
// warns and stays off, so existing logins never change by default.
import nodeFs from 'node:fs';import path from 'node:path';
export function parseVersionIni(text){const m=/^\s*VERSION\s*,\s*([^\r\n,]+?)\s*$/im.exec(String(text||''));return m?m[1]:null;}
const nativeView={readdir:dir=>nodeFs.readdirSync(dir),read:file=>nodeFs.readFileSync(file,'latin1')};
// Windows-style roots (drive letter or backslashes) resolve with win32 rules; data roots on Linux may use any case.
function findCaseInsensitive(root,parts,view){const p=/^[a-zA-Z]:[\\/]|\\/.test(root)?path.win32:path.posix;let dir=root;
 for(const part of parts){let names;try{names=view.readdir(dir);}catch{return null;}const hit=names.find(n=>n.toLowerCase()===part);if(!hit)return null;dir=p.join(dir,hit);}return dir;}
export function detectGlobalVersion({dataRoots=[],override=null,fsView=nativeView}={}){
 if(override&&String(override).trim())return {version:String(override).trim(),source:'config override'};
 for(const root of dataRoots.filter(Boolean)){const file=findCaseInsensitive(root,['share','version.ini'],fsView);if(!file)continue;
  let text;try{text=fsView.read(file);}catch{continue;}const version=parseVersionIni(text);if(version)return {version,source:file};}
 return null;}
export function createLoginVersionGate({env=process.env,dataRoots=[],appliedVersion=null,fsView,log=console}={}){
 const off={enabled:false,acceptsField:false,expected:null,source:null,check:()=>({ok:true})};
 if(env.DEKARON_LOGIN_VERSION_GATE!=='1')return off;
 const found=detectGlobalVersion({dataRoots,override:env.DEKARON_LOGIN_VERSION,fsView});
 if(!found){log.warn(`[login-version] DEKARON_LOGIN_VERSION_GATE=1 but no share/version.ini was found under ${dataRoots.filter(Boolean).join(', ')||'(no data root)'}; gate disabled.`);return off;}
 log.info(`[login-version] gate on: expected client version ${found.version} (from ${found.source})${appliedVersion?'; follows applied Global updates':''}.`);
 const expected=()=>{const live=typeof appliedVersion==='function'?appliedVersion():null;return live&&env.DEKARON_LOGIN_VERSION==null?String(live):found.version;};
 return {enabled:true,acceptsField:true,get expected(){return expected();},source:found.source,
  check(clientVersion){const want=expected();if(typeof clientVersion==='string'&&clientVersion===want)return {ok:true};
   return {ok:false,expected:want,error:`Client version ${clientVersion??'(none)'} does not match this server (${want}). Update the client.`};}};
}
