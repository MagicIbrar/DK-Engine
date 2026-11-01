// Native pcpop#79: black name_border; pcpop#105: sky-blue nine-slice.
// ENGINE-CHOSEN association follows the owner's Global party reference. The
// sprite itself is native; exact executable precedence for other teams is unknown.
export const PARTY_NAMEPLATE_FRAME=105;
export const ORDINARY_NAMEPLATE_FRAME=79;
export function partyNameplateFrame(game,actor){
 if(actor?.kind!=='player')return ORDINARY_NAMEPLATE_FRAME;
 const network=game.network,party=network?.active?network.party:null;
 if(!party?.active)return ORDINARY_NAMEPLATE_FRAME;
 const id=actor.networkId||(actor===game.player?network.self?.id:null);
 return id&&party.members?.some(m=>m.id===id)?PARTY_NAMEPLATE_FRAME:ORDINARY_NAMEPLATE_FRAME;
}
