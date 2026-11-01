// BLACKLIST client API (C29): talks to the host's own 'blacklist' message (server/world/blacklist.mjs). Results carry the
// original stringtable_messenger.txt code (1006:54-59, 1006:24) for the caller to print. The Messenger window's
// btn_tab_1 "Blacklist" tab is not wired here (the messenger window file is shared with lane-world's ui_addfriend work).
export function installBlacklist(game){
  const call=async(operation,targetName)=>{const net=game?.network;if(!net?.active||!net.ready)return {ok:false,offline:true};
    const result=await net.action('blacklist',targetName===undefined?{operation}:{operation,targetName});return result?.blacklistResult??result;};
  game.blacklist={list:()=>call('list'),add:name=>call('add',String(name??'')),remove:name=>call('remove',String(name??''))};
  return game.blacklist;
}
