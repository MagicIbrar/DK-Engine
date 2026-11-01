// Stage a NEW dedicated install without altering the downloaded clients or a live world.
// The installed game still reads the validated prepared Global generation by path.
import fs from 'node:fs';
import fsp from 'node:fs/promises';
import path from 'node:path';
import {execFileSync} from 'node:child_process';
import {fileURLToPath} from 'node:url';
import {clientSource} from '../server/client-source.mjs';
import {prepareClient,JOBS} from './prepare-client.mjs';
import {stagePreparedGlobal,createOwnedPreparation} from './portable-global-assets.mjs';
import {sanitizeReleasePng} from './release-image.mjs';
import {writeInstallOwnership} from './upgrade-dedicated-install.mjs';

const ROOT=path.resolve(fileURLToPath(new URL('../',import.meta.url)));
const WEBVIEW2_DOWNLOAD='https://developer.microsoft.com/en-us/microsoft-edge/webview2/';
const DIRECTORIES=['server','src','site','web','vendor','client-assets'];
const FILES=['server.mjs','package.json','package-lock.json','index.html','join.html','launch.html','Client.exe','GameWindow.exe','tools/setup-dedicated-sql.mjs','tools/dedicated-setup-guard.mjs','tools/create-dedicated-shortcut.ps1','tools/save-backup.mjs','tools/lib/sql-migrations.mjs','docs/SAVE-BACKUP.md','deploy/start-host.mjs','Dockerfile','compose.yaml','render.yaml','railway.json','.dockerignore','THIRD_PARTY_NOTICES.md'];
export const USER_DOCUMENTS=['docs/README.md','docs/SQL-SETUP.md','docs/DEDICATED-INSTALLER-3.3.0.md','docs/INSTALLATION-HOTFIX-3.3.1.md','docs/UPDATE-3.3.3.md','docs/UPDATE-3.3.4.md','docs/UPDATE-3.3.5.md','docs/UPDATE-4.0.0.md','docs/UPDATE-4.0.1.md','docs/UPDATE-4.0.2.md','docs/UPDATE-4.0.3.md','docs/UPDATE-4.1.0.md','docs/HOSTING.md'];
export const START_HERE=`DK ENGINE 4.1.0 - COMMAND CENTER

1. Open Client.exe for DK Command Center.
   If assets are not installed, keep the downloaded Global folder next to this engine.
   Client checks runtimes and prepares or updates your dedicated installation.
2. Create your own account. This copy includes no development accounts or saved passwords.
3. For SQL, stop the world and open Options > SQL / Storage.
   Choose Local world or Hosted world, then Prepare SQL automatically.
   For missing SQL, review and accept Microsoft terms; approve Windows UAC.
   Setup runs in the background and selects SQL storage after successful world setup.
4. On Home, review your world settings and click Start world.
   Choose DX11 Client (windowed 1280x720) or adjacent DX11 Fullscreen (borderless).
   Sign in when prompted. Local DX11 loads in the same native GameWindow.exe:
   installed-byte verification first, then frontend/graphics readiness before login.
   Host friends, Connect and Hosting options remain available.
5. Read docs/README.md, docs/SQL-SETUP.md and docs/UPDATE-4.1.0.md.
6. Update checks run on opening and every five minutes. Click the notice to install;
   close this world/game/launcher when asked, then reopen Client.exe.

Keep account/database backups before changing storage. Local and hosted accounts stay separate.
Use Client.exe for setup, updates and Command Center. Setup-DK.cmd is an alias.
If Command Center cannot open, Client.exe falls back to the classic launcher. Use Settings > Launcher to choose the classic launcher at the next start.
Updates preserve existing accounts, settings and SQL progress; back up your own saves first.
This engine reads Global assets; it does not run the original Global executable. A clean-Windows installation is not proven.
`;
// Server inventory contains only .mjs/.ps1 runtime code; all other server files are local state.
const PRIVATE=/^(?:server\/(?!.*\.(?:mjs|ps1)$).*|.*\.(?:db|sqlite|sqlite3|log|tmp|pem|key)(?:-(?:wal|shm))?)$/i;

function usage(){throw Error('Use --check [--global-engine PATH | --raw-global PATH], or --stage NEW_DIR [--global-engine PATH] [--node-exe PATH] [--linked-global | --engine-only] [--no-shortcut].');}
function options(argv){
  const value={check:false,stage:null,globalEngine:null,rawGlobal:null,nodeExe:null,shortcut:true,linkedGlobal:false,engineOnly:false};
  for(let i=0;i<argv.length;i++){
    const a=argv[i];
    if(a==='--check')value.check=true;
    else if(a==='--stage')value.stage=argv[++i]||usage();
    else if(a==='--raw-global')value.rawGlobal=argv[++i]||usage();
    else if(a==='--global-engine')value.globalEngine=argv[++i]||usage();
    else if(a==='--node-exe')value.nodeExe=argv[++i]||usage();
    else if(a==='--no-shortcut')value.shortcut=false;
    else if(a==='--linked-global')value.linkedGlobal=true;
    else if(a==='--engine-only')value.engineOnly=true;
    else usage();
  }
  if((value.engineOnly&&(value.check||value.rawGlobal||value.linkedGlobal||value.globalEngine)) || value.check===!!value.stage || (value.rawGlobal && (value.globalEngine || value.linkedGlobal)))usage();
  return value;
}
function exists(file){return fs.existsSync(file);}
function nearbyBases(source){
  const bases=[path.dirname(source),path.dirname(path.dirname(source))];
  for(const base of [...bases]){
    try{for(const row of fs.readdirSync(base,{withFileTypes:true})){
      if(row.isDirectory()&&/global|engine/i.test(row.name))bases.push(path.join(base,row.name));
    }}catch{}
  }
  return [...new Set(bases.map(x=>path.resolve(x)))];
}
function configuredGlobal(source){
  try{
    const config=JSON.parse(fs.readFileSync(path.join(source,'dedicated-source.json'),'utf8'));
    return config.version===1&&typeof config.sourceEngine==='string'?config.sourceEngine:null;
  }catch{return null;}
}
function discoverGlobal(source){
  const candidates=[configuredGlobal(source),...nearbyBases(source).flatMap(base=>[base,path.join(base,'engine')])];
  return candidates.find(candidate=>candidate&&exists(path.join(candidate,'.client-cache','current.json')))||null;
}
export function discoverRawGlobals(source){
 // Only this engine and its sibling download folders; never walk into an ancestor's backup tree.
 const bases=[path.resolve(source),path.dirname(path.resolve(source))],near=[];
 for(const base of bases){near.push(base);try{for(const entry of fs.readdirSync(base,{withFileTypes:true}))if(entry.isDirectory()&&/global|dekaron/i.test(entry.name))near.push(path.join(base,entry.name));}catch{}}
 const candidates=near.flatMap(base=>[base,path.join(base,'data'),path.join(base,'data/unpacked/data'),path.join(base,'unpacked/data'),path.join(base,'Dekaron'),path.join(base,'Dekaron/data')]);
 return [...new Set(candidates.filter(candidate=>exists(path.join(candidate,'pack.hdr'))||exists(path.join(candidate,'share/maplist.csv'))).map(candidate=>path.resolve(candidate)))];
}
function hasWebView2(){
  if(process.platform!=='win32')return false;
  const folders=[
    process.env['ProgramFiles(x86)']&&path.join(process.env['ProgramFiles(x86)'],'Microsoft','EdgeWebView','Application'),
    process.env.ProgramFiles&&path.join(process.env.ProgramFiles,'Microsoft','EdgeWebView','Application'),
    process.env.LOCALAPPDATA&&path.join(process.env.LOCALAPPDATA,'Microsoft','EdgeWebView','Application')
  ].filter(Boolean);
  return folders.some(folder=>{
    try{return fs.readdirSync(folder,{withFileTypes:true}).some(row=>row.isDirectory()&&exists(path.join(folder,row.name,'msedgewebview2.exe')));}catch{return false;}
  });
}
function assertNoLinks(location){
  let current=path.resolve(location);
  while(true){
    if(exists(current)&&fs.lstatSync(current).isSymbolicLink())throw Error(`Linked path refused: ${current}`);
    const parent=path.dirname(current);
    if(parent===current)break;
    current=parent;
  }
}
function inside(candidate,root){
  const rel=path.relative(path.resolve(root),path.resolve(candidate));
  return !rel||(!rel.startsWith('..'+path.sep)&&rel!=='..'&&!path.isAbsolute(rel));
}
export function missingRuntimeFiles(source){
  return [...FILES,...ORIGINAL_LAUNCHER_TOOLS.map(name=>'tools/'+name),...USER_DOCUMENTS]
    .filter(rel=>!exists(path.join(source,rel)));
}
function inspect({globalEngine,dedicatedSource=ROOT,validateGlobalSource=true}){
  dedicatedSource=path.resolve(dedicatedSource);
  globalEngine=globalEngine?path.resolve(globalEngine):discoverGlobal(dedicatedSource);
  const checks={
    windows:process.platform==='win32',
    node24:Number(process.versions.node.split('.')[0])>=24,
    webView2:hasWebView2(),
    dashboard:exists(path.join(dedicatedSource,'Client.exe')),
    gameWindow:exists(path.join(dedicatedSource,'GameWindow.exe')),
    launcherFiles:missingRuntimeFiles(dedicatedSource).length===0,
    preparedGlobal:!!globalEngine&&exists(path.join(globalEngine,'.client-cache','current.json')),
    sqlSetup:exists(path.join(dedicatedSource,'tools','setup-dedicated-sql.mjs')),
  };
  let globalSourceKind=null;
  if(checks.preparedGlobal){
    try{
      const manifest=JSON.parse(fs.readFileSync(path.join(globalEngine,'.client-cache','current.json'),'utf8'));
      globalSourceKind=manifest.source?.kind||null;
      checks.preparedGlobal=!!manifest.generation&&['pack','loose','prepared'].includes(globalSourceKind);
    }catch{checks.preparedGlobal=false;}
  }
  if(checks.preparedGlobal&&(validateGlobalSource||globalSourceKind==='prepared')){
    try{checks.preparedGlobal=!!clientSource(globalEngine).manifest;}
    catch{checks.preparedGlobal=false;}
  }
  const ready=Object.values(checks).every(Boolean);
  const help=[];
  if(!checks.preparedGlobal)help.push('Select the engine folder with a prepared .client-cache/current.json using --global-engine PATH.');
  if(!checks.webView2)help.push(`Install Microsoft WebView2 Runtime from ${WEBVIEW2_DOWNLOAD}`);
  if(!checks.node24)help.push('Install Node.js 24 or newer, then run setup again.');
  if(!checks.launcherFiles)help.push('This Engine folder is incomplete. Restore the full download; missing: '+missingRuntimeFiles(dedicatedSource).slice(0,8).join(', '));
  return {ready,checks,globalSourceKind,globalEngine,dedicatedSource,help,
    note:'The default install copies user-supplied prepared Global assets into the independent installed engine. Original game executables are not copied.'};
}
const PACKAGE_PNGS=new Set(['client-assets/dk-engine-emblem-v1.png','client-assets/dk-engine-logo-v1.png','client-assets/launcher-background-v1.png','web/public/logo.png']);
const OMIT_OWN_LEGACY_FILES=new Set(["client-assets/dekaron-online-logo-v1.png", "client-assets/dekaron-online-emblem-v1.png", "client-assets/dekaron-online.ico"]);
async function copyTree(from,to,rel=''){
  const st=await fsp.lstat(from);
  if(st.isSymbolicLink())throw Error(`Linked source refused: ${from}`);
  if(st.isDirectory()){
    await fsp.mkdir(to,{recursive:true});
    for(const name of await fsp.readdir(from))await copyTree(path.join(from,name),path.join(to,name),rel?`${rel}/${name}`:name);
  }else if(st.isFile()&&!PRIVATE.test(rel.replaceAll('\\','/'))&&!OMIT_OWN_LEGACY_FILES.has(rel.replaceAll('\\','/'))){
    await fsp.mkdir(path.dirname(to),{recursive:true});
    if(PACKAGE_PNGS.has(rel.replaceAll('\\','/')))await fsp.writeFile(to,sanitizeReleasePng(await fsp.readFile(from)),{flag:'wx'});
    else await fsp.copyFile(from,to,fs.constants.COPYFILE_EXCL);
  }
}
export async function copyRuntimeDependencies(source,target){
 // Match the original installer: browsers load addons from vendor/jsm; Node uses Three core only.
 for(const rel of ['node_modules/three/build','node_modules/three/src','node_modules/three/package.json','node_modules/three/LICENSE'])
  await copyTree(path.join(source,rel),path.join(target,rel),rel);
}
// Copy just the preparation program and its relative module/resource closure, never the tools evidence tree.
export async function copyPreparationTools(source,target){
  const queue=['tools/prepare-client.mjs','tools/client-pack.mjs',...JOBS.filter(j=>j.step!=='site-art').map(j=>'tools/build-'+j.step+'.mjs')];
  const visited=new Set();
  while(queue.length){
    const rel=queue.shift();if(visited.has(rel))continue;visited.add(rel);
    const full=path.resolve(source,rel);
    if(!inside(full,source))throw Error('Preparation dependency escapes engine.');
    if(!exists(full))throw Error('Required preparation dependency missing: '+rel);
    const text=await fsp.readFile(full,'utf8');
    if(rel.startsWith('tools/'))await copyTree(full,path.join(target,rel),rel);
    for(const match of text.matchAll(/['"](\.\.?\/[^'"`]+\.(?:mjs|js|json))['"]/g)){
      const child=path.resolve(path.dirname(full),match[1]);
      if(inside(child,source)&&exists(child))queue.push(path.relative(source,child).replaceAll('\\','/'));
    }
  }
  return [...visited];
}
export async function stageRawGlobal(rawGlobal,destination,{dedicatedSource=ROOT,prepare=prepareClient,...stageOptions}={}){
  rawGlobal=path.resolve(rawGlobal);destination=path.resolve(destination);
  const missing=missingRuntimeFiles(dedicatedSource);
  if(missing.length)throw Error('Incomplete dedicated Engine package; missing: '+missing.slice(0,8).join(', '));
  assertNoLinks(rawGlobal);assertNoLinks(path.dirname(destination));
  for(const protectedRoot of [rawGlobal,dedicatedSource])if(inside(destination,protectedRoot)||inside(protectedRoot,destination))throw Error('Raw preparation destination overlaps source.');
  if(exists(destination))throw Error('Destination already exists; refusing to replace files or live data.');
  const ownedPreparation=await createOwnedPreparation(destination);
  const prepRoot=ownedPreparation.root;
  let created=true;
  try{
    for(const rel of DIRECTORIES)await copyTree(path.join(dedicatedSource,rel),path.join(prepRoot,rel),rel);
    await copyRuntimeDependencies(dedicatedSource,prepRoot);
    if(exists(path.join(dedicatedSource,'gamedata-overrides')))await copyTree(path.join(dedicatedSource,'gamedata-overrides'),path.join(prepRoot,'gamedata-overrides'),'gamedata-overrides');
    await copyPreparationTools(dedicatedSource,prepRoot);
    await prepare({engine:prepRoot,data:rawGlobal,log:message=>console.error(message)});
    const plan=inspect({dedicatedSource,globalEngine:prepRoot});
    return await stage(plan,destination,{...stageOptions,stageGlobal:true,ownedPreparation});
  }finally{
    // Only this invocation's new sibling is removed. Source folders are never cleanup targets.
    if(created&&exists(prepRoot))await fsp.rm(prepRoot,{recursive:true,force:true});
  }
}
export const ORIGINAL_LAUNCHER_TOOLS=["command-center","client-release-update.ps1","release-update.mjs","release-update-worker.mjs","safe-release-extract.ps1","native-preload-art.mjs","verify-warm-assets.mjs","client-asset-warm.ps1","upgrade-dedicated-install.mjs","runtime-licenses/node-v24.18.0-LICENSE","start-dedicated-client.ps1","dedicated-client-entry.mjs","ClientLauncher.cs","LauncherVisuals.cs","DKClient.cs","DKClient.manifest","build-dedicated.ps1","launcher/DedicatedDashboard.cs","client-ui.ps1","client-runtime.ps1","client-location.ps1","client-dashboard.ps1","client-prestart-settings.ps1","client-capacity-panel.ps1","client-friends.ps1","client-qr.ps1","client-auth.ps1","client-owner-accounts.ps1","client-port.ps1","client-hosting-setup.ps1","client-dedicated-sql.ps1","client-prestart-settings.mjs","client-qr.mjs","vendor/qrcodegen.mjs","client-ready.mjs","install-client.mjs","configure-friends-host.mjs","client-relay.mjs","publish-server.mjs","start-directory.mjs","net-speed-test.mjs","capacity-settings.mjs","set-account-role.mjs","build-native-client.ps1","build-client-icon.ps1","dedicated-client-plan.mjs","setup-dedicated-sql.mjs","dedicated-setup-guard.mjs","mapbuilder.html","map-preview.html","viewer.html","viewer.js"];
export async function copyLauncherTools(source,target){
 const queue=ORIGINAL_LAUNCHER_TOOLS.map(name=>'tools/'+name),visited=new Set();
 while(queue.length){
  const rel=queue.shift();if(visited.has(rel))continue;visited.add(rel);
  const full=path.resolve(source,rel);
  if(!inside(full,source)||!exists(full))throw Error('Required launcher dependency missing: '+rel);
  if(rel.startsWith('tools/')&&!exists(path.join(target,rel)))await copyTree(full,path.join(target,rel),rel);
  if(!/\.(?:mjs|js)$/.test(rel))continue;
  const text=await fsp.readFile(full,'utf8');
  for(const match of text.matchAll(/['"](\.\.?\/[^'"`]+\.(?:mjs|js|json))['"]/g)){
   const child=path.resolve(path.dirname(full),match[1]);
   if(inside(child,source)&&exists(child))queue.push(path.relative(source,child).replaceAll('\\','/'));
  }
 }
 return [...visited];
}
async function makeShortcut(destination){
  const result=execFileSync('powershell.exe',['-NoProfile','-NonInteractive','-File',path.join(destination,'tools','create-dedicated-shortcut.ps1'),'-InstallRoot',destination],{encoding:'utf8'});
  return result.trim();
}
async function stage(plan,destination,{shortcut=true,stageGlobal=true,nodeExecutable=null,engineOnly=false,ownedPreparation=null}={}){
  const missing=missingRuntimeFiles(plan.dedicatedSource);
  if(missing.length)throw Error('Incomplete dedicated Engine package; missing: '+missing.slice(0,8).join(', '));
  if(engineOnly)stageGlobal=false;
  const prerequisites=engineOnly?Object.entries(plan.checks).filter(([name])=>!['preparedGlobal','webView2'].includes(name)).every(([,value])=>value):plan.ready;
  if(!prerequisites)throw Error('Preflight failed; see --check output. Nothing was copied.');
  destination=path.resolve(destination);
  for(const protectedRoot of [plan.dedicatedSource,plan.globalEngine].filter(Boolean)){
    if(inside(destination,protectedRoot)||inside(protectedRoot,destination))throw Error(`Destination overlaps source: ${protectedRoot}`);
  }
  if(exists(destination))throw Error('Destination already exists; refusing to replace files or live data.');
  assertNoLinks(path.dirname(destination));
  const temp=destination+`.staging-${process.pid}-${Date.now()}`;
  if(exists(temp))throw Error('Staging path already exists.');
  try{
    await fsp.mkdir(temp,{recursive:false});
    for(const rel of DIRECTORIES)await copyTree(path.join(plan.dedicatedSource,rel),path.join(temp,rel),rel);
    if(exists(path.join(plan.dedicatedSource,'sql')))await copyTree(path.join(plan.dedicatedSource,'sql'),path.join(temp,'sql'),'sql');
    await copyRuntimeDependencies(plan.dedicatedSource,temp);
    for(const rel of FILES){
      if(!exists(path.join(plan.dedicatedSource,rel)))throw Error(`Required runtime file missing: ${rel}`);
      await copyTree(path.join(plan.dedicatedSource,rel),path.join(temp,rel),rel);
    }
    if(exists(path.join(plan.dedicatedSource,'tools/prepare-client.mjs')))await copyPreparationTools(plan.dedicatedSource,temp);
    await copyLauncherTools(plan.dedicatedSource,temp);
    for(const rel of ['tools/install-dedicated-sql.ps1','tools/bootstrap-dedicated-runtime.ps1','tools/stage-dedicated-install.mjs','tools/portable-global-assets.mjs','Setup-DK.cmd'])if(exists(path.join(plan.dedicatedSource,rel))&&!exists(path.join(temp,rel)))await copyTree(path.join(plan.dedicatedSource,rel),path.join(temp,rel),rel);
    if(nodeExecutable){
      nodeExecutable=path.resolve(nodeExecutable);
      if(!exists(nodeExecutable))throw Error('Prepared Node.js executable is missing.');
      const version=execFileSync(nodeExecutable,['--version'],{encoding:'utf8'}).trim();
      if(!/^v(\d+)\./.test(version)||Number(version.match(/^v(\d+)\./)[1])<24)throw Error('Prepared Node.js must be version 24 or newer.');
      await fsp.mkdir(path.join(temp,'runtime'),{recursive:true});
      const licenseCandidates=[path.join(path.dirname(nodeExecutable),'LICENSE'),path.join(plan.dedicatedSource,'tools/runtime-licenses','node-'+version+'-LICENSE'),process.env.LOCALAPPDATA&&path.join(process.env.LOCALAPPDATA,'Dekaron Dedicated Setup','Licenses',version,'LICENSE')].filter(Boolean);
      const licenseFile=licenseCandidates.find(file=>exists(file)&&fs.statSync(file).size>4096&&fs.readFileSync(file,'utf8').startsWith('Node.js is licensed for use as follows:'));
      if(!licenseFile)throw Error('Matching Node.js LICENSE and third-party notices are missing. Run the Client runtime bootstrap before packaging.');
      await fsp.copyFile(nodeExecutable,path.join(temp,'runtime','node.exe'),fs.constants.COPYFILE_EXCL);
      await fsp.copyFile(licenseFile,path.join(temp,'runtime','LICENSE'),fs.constants.COPYFILE_EXCL);
      await fsp.writeFile(path.join(temp,'runtime','node-license.json'),JSON.stringify({version,source:'https://raw.githubusercontent.com/nodejs/node/'+version+'/LICENSE'},null,2));
    }
    let stagedGlobal=null;
    if(stageGlobal){
      console.error(ownedPreparation?'Validating and relocating freshly prepared Global assets within this installer staging area. Original downloads stay untouched.':'Copying prepared Global game files into this portable install. The source stays unchanged.');
      stagedGlobal=await stagePreparedGlobal({sourceEngine:plan.globalEngine,destinationEngine:temp,ownedPreparation,onProgress:({phase,files,totalFiles,bytes,totalBytes})=>{
        const pct=totalFiles?Math.min(100,Math.floor(files*100/totalFiles)):0;
        console.error(`Global files ${phase}: ${pct}% (${files.toLocaleString()}/${totalFiles.toLocaleString()} files, ${(bytes/1073741824).toFixed(2)}/${(totalBytes/1073741824).toFixed(2)} GiB)`);
      }});
    }
    for(const rel of USER_DOCUMENTS)await copyTree(path.join(plan.dedicatedSource,rel),path.join(temp,rel),rel);
    await fsp.writeFile(path.join(temp,'START-HERE.txt'),START_HERE,{flag:'wx'});
    if(!engineOnly)await fsp.writeFile(path.join(temp,'dedicated-source.json'),JSON.stringify({version:1,sourceEngine:stagedGlobal?.sourceEngine||plan.globalEngine},null,2)+'\n');
    await fsp.writeFile(path.join(temp,'install-sources.json'),JSON.stringify({version:1,globalMode:engineOnly?'user-supplied':stagedGlobal?'portable-copy':'linked',assetSource:'User-supplied Global game data; original game executables are not redistributed.'},null,2)+'\n');
    if(!engineOnly)await writeInstallOwnership(temp,destination);
    const stagedMissing=missingRuntimeFiles(temp);
    if(stagedMissing.length)throw Error('Installed engine is incomplete before activation; missing: '+stagedMissing.slice(0,8).join(', '));
    await fsp.rename(temp,destination);
  }catch(error){
    if(exists(temp))await fsp.rm(temp,{recursive:true,force:true}); // installer-owned, validated sibling only
    throw error;
  }
  let shortcutPath=null,shortcutError=null;
  if(shortcut)try{shortcutPath=await makeShortcut(destination);}catch(error){shortcutError=String(error.message||error);}
  return {installed:destination,shortcut:shortcutPath,shortcutError,globalMode:engineOnly?'user-supplied':stageGlobal?'portable-copy':'linked'};
}

export {options,inspect,stage,discoverGlobal};
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url)){
  try{
    const args=options(process.argv.slice(2));
    if(args.rawGlobal){
      if(args.check){
        assertNoLinks(args.rawGlobal);
        const raw=exists(path.join(args.rawGlobal,'pack.hdr'))||exists(path.join(args.rawGlobal,'share/maplist.csv'));
        console.log(JSON.stringify({rawGlobal:path.resolve(args.rawGlobal),rawSourceFound:raw,note:'Full preparation validates all required tables; this check does not extract or write source files.'},null,2));process.exitCode=raw?0:3;
      }else console.log(JSON.stringify(await stageRawGlobal(args.rawGlobal,args.stage,{dedicatedSource:ROOT,shortcut:args.shortcut,nodeExecutable:args.nodeExe,engineOnly:args.engineOnly}),null,2));
    }else {
    const plan=inspect(args);
    if(args.check){console.log(JSON.stringify(plan,null,2));process.exitCode=plan.ready?0:(!plan.checks.preparedGlobal?3:2);}
    else console.log(JSON.stringify(await stage(plan,args.stage,{shortcut:args.shortcut,stageGlobal:!args.linkedGlobal,nodeExecutable:args.nodeExe,engineOnly:args.engineOnly}),null,2));
    }
  }catch(error){console.error(error.message);process.exitCode=1;}
}
