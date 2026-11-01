// Renew has native entrances, refusals and OBSERVER_COUNT, but no observer/info
// rows. These explicit adaptations reuse its authored travel locations and the
// classic siege's camera, ticket and delay. They are not recovered Global rules.
export const RENEW_OBSERVER_CHOSEN=Object.freeze({
  capacityScope:'per-castle',cameraSpeed:10,enterEnableMs:1000,ticket:54501,
  areaTypes:Object.freeze([2,4,1]),includeGuardian:true,exitTo:'native-Ardeca-return',
  npcRadius:8,actions:Object.freeze(['move','stop','chat','emote','observer']),
});
