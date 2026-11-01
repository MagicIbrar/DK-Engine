// Native share/event/oxlist.csv row17: Premium Holy Water benefits all characters on the account;
// regular Holy Water benefits its consuming character. Entitlements share the existing accountFeatures transaction.
export function hydrateAccountPremium(profile,now=Date.now()) {
 const shared=profile.accountFeatures?.premium;if(!shared)return profile;
 profile.premium={...(profile.premium||{})};
 for(const [group,entry]of Object.entries(shared)){
  if(!entry?.accountWide||!(entry.until>now))continue;
  const local=profile.premium[group];
  if(local&&!local.accountWide&&local.until>now){profile.premium[`regular:${group}`]=structuredClone(local);profile.premium[group]=structuredClone(entry);continue;}
  // Preserve the existing service-group behavior: a newer character-local activation may supersede its view.
  if(!local||local.until<=now||Number(entry.start)>=Number(local.start))profile.premium[group]=structuredClone(entry);
 }
 return profile;
}
export function mergeAccountPremiumFeatures(previous,incoming,now=Date.now()) {
 const features=structuredClone(incoming||previous||{}),premium={};
 for(const source of [previous?.premium,incoming?.premium])for(const [group,entry]of Object.entries(source||{})){
  if(!entry?.accountWide||!(entry.until>now))continue;
  if(!premium[group]||Number(entry.until)>Number(premium[group].until))premium[group]=structuredClone(entry);
 }
 if(Object.keys(premium).length)features.premium=premium;else delete features.premium;
 return features;
}
