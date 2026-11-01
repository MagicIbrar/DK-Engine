// Hosted game assets are session-protected separately from the world-action API.
// This access control does not establish rights to distribute their content.
export async function hostedAssetAccess(req,res,pathname,{enabled=false,canReadAssets}={}){
 if(!enabled)return false;
 const entry=pathname==='/'||pathname==='/index.html';
 const imported=pathname==='/api/ls'||['/data/','/gamedata/','/sound/'].some(prefix=>pathname.startsWith(prefix));
 if(!entry&&!imported)return false;
 if(await canReadAssets(req))return false;
 if(entry&&['GET','HEAD'].includes(req.method)){
  res.writeHead(303,{Location:'/site/login.html?next=%2F%3Fscreen%3Dselect','Cache-Control':'no-store'});res.end();
 }else{
  res.writeHead(401,{'Content-Type':'application/json; charset=utf-8','Cache-Control':'no-store'});
  res.end(req.method==='HEAD'?undefined:JSON.stringify({error:'Sign in to this server before loading game content.'}));
 }
 return true;
}
