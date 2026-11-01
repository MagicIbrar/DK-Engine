// Exact generated art names are public; prompts, private runtime and arbitrary
// files placed beside them never become downloads.
const connectorAssets=new Set(['index.html','portal.js','connect.js','portal-config.js','portal.css','logo.png','hosting.html','help.html','join.js']);
// Keep the signed-out menu reachable without exposing deployment files or host secrets.
export function isPublicConnectorAsset(pathname){
 return typeof pathname==='string'&&pathname.startsWith('/web/public/')&&connectorAssets.has(pathname.slice('/web/public/'.length));
}
export function isPublicEngineAsset(rel){
 if(isPublicConnectorAsset('/'+rel))return true;
 return typeof rel==='string'&&!rel.split('/').some(part=>part.startsWith('.'))&&!/^(server|docs)\//i.test(rel)&&
  /^(src\/|vendor\/|tools\/|node_modules\/three\/|client-assets\/(?:launcher-background-v1|dekaron-online-logo-v1|dekaron-online-emblem-v1|server-logo-v1)\.png$|index\.html$|Play\.bat$|Client\.bat$|Client\.exe$|Install\.bat$)/i.test(rel);
}
