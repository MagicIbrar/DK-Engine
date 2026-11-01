// MESSENGER-CHAT: the Messenger's 1:1 chat window in shared play (script/ui/game2/messenger/ui_chatwnd.txt "messenger_chat",
// edit_text maxlength 60) and its "Decline messages" switch (ui_messengerwnd.txt lbl_noMsg, 1006:47). The host derives the
// two recipients itself; a client only names the partner. Refusals are the original stringtable_messenger.txt (cate 1006) text,
// answered as codes so the client prints the localized line with the partner's name. Rules the data does not state are
// ENGINE-CHOSEN and listed in MESSENGER_CONFIG and docs/MESSENGER-CHAT.md.
import {WorldError} from './core.mjs';

export const MESSENGER_SCHEMAS={messenger:['token','type','operation','targetName','text','on']};
export const MESSENGER_MAX_TEXT=60;                // ui_chatwnd.txt edit_text maxlength 60
export const MESSENGER_MAX_NAME=20;                // ui_messengerwnd.txt edit_text maxlength 20 (character names)
/** ENGINE-CHOSEN (not in Global data): pacing and partner rules the client data does not carry. */
export const MESSENGER_CONFIG=Object.freeze({
  cooldownMs:1000,          // one message per second, the same pacing as the shared chat channels (server/world/social.mjs)
  friendRequired:false,     // the friend list is client-held (src/systems/life/friends.js), so any connected name can be messaged
});
/** Original text (script/string/normal/stringtable_messenger.txt cate 1006). */
export const MESSENGER_CODES=Object.freeze({
  notConnected:'1006:48',   // "is not connected to the game, therefore cannot send the message."
  declines:'1006:42',       // "does not accept any requests."
});
export const MESSENGER_SELF_TEXT='You cannot talk to yourself.';   // ENGINE-CHOSEN (not in Global data)
const fail=(message,status=400)=>{throw new WorldError(status,message);};
const live=world=>[...world.players.values()].filter(q=>!q.leaving);
export const findConnected=(world,name)=>{const k=String(name||'').trim().toLowerCase();return k?live(world).find(q=>String(q.profile?.name||'').toLowerCase()===k)||null:null;};

export function messengerCommand(world,p,input){
  const op=input.operation;
  if(op==='decline'){
    if(typeof input.on!=='boolean'||input.targetName!==undefined||input.text!==undefined)fail('Choose whether to decline messages.');
    p.messengerDecline=input.on;
    return {decline:p.messengerDecline};
  }
  if(op!=='send')fail('This messenger action is unavailable.');
  if(input.on!==undefined)fail('Choose whether to decline messages.');
  if(typeof input.targetName!=='string'||!input.targetName.trim()||input.targetName.length>MESSENGER_MAX_NAME)fail('Choose a friend to talk to.');
  if(typeof input.text!=='string'||input.text.length>MESSENGER_MAX_TEXT)fail(`Messages must contain 1-${MESSENGER_MAX_TEXT} characters.`);
  const text=input.text.replace(/[\x00-\x1f\x7f]/g,' ').trim();
  if(!text)fail('Message is empty.');
  const now=world.now();
  if(now<(p.muteUntil||0))fail('Your chat is temporarily restrained.',403);
  const target=findConnected(world,input.targetName),name=target?.profile.name||input.targetName.trim();
  if(target===p)fail(MESSENGER_SELF_TEXT);
  if(!target)return {sent:false,code:MESSENGER_CODES.notConnected,targetName:name};
  if(target.messengerDecline)return {sent:false,code:MESSENGER_CODES.declines,targetName:name};
  if(now<(p.messengerAt||0))fail('Wait one second between messages.',429);
  p.messengerAt=now+MESSENGER_CONFIG.cooldownMs;
  world.emit(null,{type:'messenger',actorId:p.id,name:p.profile.name,targetId:target.id,targetName:name,text,time:now,recipients:[p.id,target.id]});
  return {sent:true,targetName:name};
}