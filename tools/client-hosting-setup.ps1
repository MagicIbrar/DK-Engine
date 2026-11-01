# Hosting setup kits (2.2.0 item 1/2): decentralised hosting, no project-run server. Each button writes a plain-text guide plus ready-to-edit
# files for ONE route (this PC / own VPS / Vercel / Cloudflare) into engine\hosting-setup\<route>\ and opens that folder.
# Nothing here contacts a provider, creates an account or deploys anything; it only writes files the player runs themselves.
# Provider dashboard labels are described from the existing docs/HOSTING.md; they are NOT verified against the live dashboards.
function Get-HostingSetupRoutes { return @('local','vps','vercel','cloudflare') }
function New-HostingSetupKit([string]$Route,[string]$RelayOrigin='',[string]$DirectoryOrigin='') {
 if($Route -cnotin (Get-HostingSetupRoutes)){throw 'Unknown hosting route.'}
 $relay='https://world.example.com/';$directory='https://directory.example.com/';$placeholders=@()
 try{$relay=(ConvertTo-ClientRelayOrigin $RelayOrigin)+'/'}catch{$placeholders+='relay hostname (world.example.com)'}
 try{$directory=(ConvertTo-ClientRelayOrigin $DirectoryOrigin)+'/'}catch{$placeholders+='directory address (directory.example.com)'}
 $relayHost=([Uri]$relay).Host
 $note=$(if($placeholders.Count){"PLACEHOLDERS: this kit uses example values for the "+($placeholders -join ' and ')+". Replace them with yours (type them in Hosting options / Settings and press the button again to regenerate).`r`n`r`n"}else{''})
 $metadata=[ordered]@{version=1;relayOrigin=$relay;directoryOrigin=$directory;approvedRelayHosts=@($relayHost);hostMode='open';gatewayPort=7840;directoryPort=7790}|ConvertTo-Json
 $files=[ordered]@{}
 switch($Route){
  'local' {
   $title='Host on this PC'
   $files['README.txt']=$note+"HOST ON THIS PC (relay-only by default)`r`n`r`n1. Launcher > Hosting options > create your host (name, GM account, access mode).`r`n2. For other people to join over the Internet WITHOUT revealing your home IP, use an outbound relay: tick 'Online relay (managed HTTPS)' and give it your relay hostname + token file (see the Cloudflare kit for how to get them).`r`n3. Without a relay your server listens on 127.0.0.1 only: nobody else can join. To allow friends on your own network instead, tick 'Allow direct LAN connections' in Settings. That shows your LAN address and is not hidden from them.`r`n4. To appear in a public list, use Settings > Public server list (you will get a warning first).`r`n"
  }
  'vps' {
   $title='My own VPS'
   $files['README.txt']=$note+"OWN VPS: run a server list (directory) and/or your world on a machine you control`r`n`r`nA. Directory (the public list)`r`n   1. Copy this engine folder to the VPS (Node 24 is required).`r`n   2. Run start-directory.ps1 (Windows) or the same commands in a shell: it sets DEKARON_DIRECTORY_TOKEN, DEKARON_DIRECTORY_RELAY_HOSTS and starts tools/start-directory.mjs on 127.0.0.1:7790.`r`n   3. Put an HTTPS reverse proxy (Caddy, nginx, Cloudflare Tunnel...) in front so the public address is $directory`r`n   4. Keep the generated token private. Hosts do not need it; they register with their own publication proof.`r`n   5. To accept ANY relay under a suffix (community lists), set DEKARON_DIRECTORY_RELAY_HOSTS to '*.your-relay-domain.tld'. Exact names are safer.`r`n   6. The directory limits each address to 60 list requests a minute and 10 registrations a minute.`r`n`r`nB. Players: Settings > Public server list > Directory address = $directory then 'Test connection'.`r`n`r`nC. metadata.json is non-secret. Check it with: node tools\permanent-hosting-plan.mjs --manifest hosting-setup\vps\metadata.json (prints a review plan, deploys nothing).`r`n`r`nMore: docs\HOSTING.md (Persistent Docker world, Railway/Render templates).`r`n"
   $files['start-directory.ps1']="# Starts the server-list directory on loopback. Put an HTTPS reverse proxy in front of 127.0.0.1:7790.`r`n`$env:DEKARON_DIRECTORY_TOKEN = (node -e `"process.stdout.write(require('node:crypto').randomBytes(32).toString('hex'))`")`r`n`$env:DEKARON_DIRECTORY_RELAY_HOSTS = '$relayHost'`r`n`$env:HOST = '127.0.0.1'`r`n`$env:PORT = '7790'`r`nnode tools/start-directory.mjs`r`n"
   $files['metadata.json']=$metadata
  }
  'vercel' {
   $title='Vercel'
   $files['README.txt']=$note+"VERCEL: player portal only`r`n`r`nWhat Vercel can do here: serve the static connector (engine\web) so players open one friendly address that checks a host and sends them to it. It contains no game files and no accounts.`r`nWhat it cannot do: run the server list (the directory is a small always-on Node process holding the list in memory) or the game world. Use the 'My own VPS' kit for the directory.`r`n`r`n1. Install the Vercel CLI and log in yourself.`r`n2. In a terminal: cd engine\web ; vercel --prod  (Framework: Other; the included vercel.json serves 'public'; no build/install command).`r`n3. Share the resulting address. Players still sign up on the game server they choose.`r`n`r`nSee docs\HOSTING.md, 'Static connector'. This project verified one static Vercel deployment earlier; it does not deploy anything for you.`r`n"
  }
  'cloudflare' {
   $title='Cloudflare'
   $files['README.txt']=$note+"CLOUDFLARE: relay (hides your home IP) and optional portal`r`n`r`nRelay for your world (outbound-only, your IP is not published):`r`n  1. In your Cloudflare account create a NAMED tunnel (Zero Trust area, Tunnels) and copy its token into a plain file on this PC.`r`n  2. Add a public hostname for the tunnel (for example $relayHost) whose service is http://127.0.0.1:7840 .`r`n  3. Launcher > Hosting options > More: tick 'Online relay (managed HTTPS)', enter $relay and pick the token file.`r`n  4. Start your host. The relay is the part that can be attacked; Cloudflare's own filtering sits in front of it, and Cloudflare sees every player's IP.`r`n  (Dashboard wording can change; this project has not verified the live dashboard steps.)`r`n`r`nPortal on Cloudflare Pages: upload engine\web\public as a Pages project (build command 'exit 0'). Same limits as the Vercel portal.`r`n`r`nSee docs\HOSTING.md, 'Managed HTTPS relay and IP privacy'.`r`n"
   $files['metadata.json']=$metadata
  }
 }
 return [pscustomobject]@{route=$Route;title=$title;files=$files;relay=$relay;directory=$directory;placeholders=@($placeholders)}
}
function Write-HostingSetupKit($Kit,[string]$Engine,[bool]$OpenFolder=$true) {
 $root=Join-Path $Engine 'hosting-setup';Assert-ClientPathUnlinked $root
 $folder=Join-Path $root $Kit.route;Assert-ClientPathUnlinked $folder;[void][IO.Directory]::CreateDirectory($folder)
 foreach($name in $Kit.files.Keys){if($name -notmatch '^[A-Za-z0-9._-]{1,64}$'){throw 'Invalid kit file name.'};$file=Join-Path $folder $name;Assert-ClientPathUnlinked $file;[IO.File]::WriteAllText($file,[string]$Kit.files[$name],(New-Object Text.UTF8Encoding($false)))}
 if($OpenFolder){try{[void](Start-Process -FilePath 'explorer.exe' -ArgumentList ('"'+$folder+'"'))}catch{}}
 return $folder
}
