// ENGINE-CHOSEN optional NPC ambient/local chat policy, matching the director's
// default chatDistance. Original Global's normal-chat distance is not recovered.
export const NPC_LOCAL_CHAT_DISTANCE=24;
export function verifiedNpcChatActor(p){return p?.npcPlayer===true&&p.profile?.npcPlayer===true&&p.profile.authority==='server'&&/^npc_[a-f0-9]{32}$/.test(p.account||'');}
export function npcLocalAudible(speaker,listener){return !verifiedNpcChatActor(speaker)||Math.hypot(listener.x-speaker.x,listener.z-speaker.z)<=NPC_LOCAL_CHAT_DISTANCE;}
