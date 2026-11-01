import {sameScene} from './scene.mjs';
import {npcLocalAudible} from './npc-chat-scope.mjs';
import {SHOUT_COOLDOWN_MS,WORLD_CHAT_COOLDOWN_MS,SUPERCHAT_TEXT,worldWaitText,serverScope} from '../../src/systems/hud-options/superchat-rules.js';
import {hostChatLinks} from '../../src/systems/hud-options/chat-links-rules.js';

export const SOCIAL_SCHEMAS = {chat:['token','type','text','channel','targetName']};
const fail=(message,status=400)=>{throw Object.assign(new Error(message),{status});};

/** Normal, map-wide shout, server-wide world, and private whisper channels (shout 230:69 every 10 s; world 230:90 +
 * formula.ini dwShoutDelay every 30 s, reaching the speaker's server: the field channels, or the one DK server).
 * Recipient lists are always derived on the server; clients cannot forge them. */
export function socialChat(world,p,input) {
  const now=world.now(),channel=input.channel??'normal';
  if(!['normal','shout','world','whisper'].includes(channel))fail('This chat channel is unavailable in shared play.');
  if(now<(p.muteUntil||0))fail('Your chat is temporarily restrained.',403);
  if(typeof input.text!=='string'||!input.text.trim()||input.text.length>250)fail('Chat must contain 1–250 characters.');
  // CHAT-LINKS: {item:uid} tokens name the speaker's own items; the host swaps them for "[Name]" + a copy (chat-links-rules.js)
  const linked=hostChatLinks(p.profile,world.data?.itemDB,input.text.replace(/[\x00-\x1f\x7f]/g,' ').trim(),now),text=linked.text;
  if(!text)fail('Chat message is empty.');
  if(now<(p.chatAt||0))fail('Wait one second between chat messages.',429);
  if(channel==='shout'&&now<(p.shoutAt||0))fail(SUPERCHAT_TEXT.shoutWait,429);
  if(channel==='world'&&now<(p.worldChatAt||0))fail(worldWaitText(p.worldChatAt-now),429);
  let target;
  if(channel==='whisper'){
    if(typeof input.targetName!=='string'||!input.targetName.trim()||input.targetName.length>20)fail('Choose a connected character to whisper to.');
    target=[...world.players.values()].find(q=>!q.leaving&&q.profile.name.toLowerCase()===input.targetName.trim().toLowerCase());
    if(!target)fail('That character is not connected.',404);
  } else if(input.targetName!==undefined)fail('A recipient is only allowed for whispers.');
  p.chatAt=now+1000;
  if(channel==='shout')p.shoutAt=now+SHOUT_COOLDOWN_MS;
  if(channel==='world')p.worldChatAt=now+WORLD_CHAT_COOLDOWN_MS;
  const recipients=channel==='whisper'
    ? [...new Set([p.id,target.id])]
    : channel==='world'
      ? [...world.players.values()].filter(q=>!q.leaving&&serverScope(q.channel)===serverScope(p.channel)).map(q=>q.id)
      : [...world.players.values()].filter(q=>!q.leaving&&sameScene(q,p)&&(channel!=='normal'||npcLocalAudible(p,q))).map(q=>q.id);
  world.emit(p.map,{type:'chat',channel,actorId:p.id,name:p.profile.name,text,recipients,...(linked.links.length?{links:linked.links}:{}),...(target?{targetId:target.id,targetName:target.profile.name}:{})});
}
