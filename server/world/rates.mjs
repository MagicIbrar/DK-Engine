// Host base rates and validated authoritative event multipliers.
export function readWorldRates(env=process.env) {
  const rates={};
  for(const [key,name]of [['exp','DEKARON_EXP_RATE'],['dil','DEKARON_DIL_RATE'],['drop','DEKARON_DROP_RATE']]){
    const raw=env[name],value=raw===undefined?1:Number(raw);
    if(raw!==undefined&&(String(raw).trim()===''||!Number.isFinite(value)||value<0.1||value>100))throw new Error(`${name} must be between 0.1 and 100.`);
    rates[key]=value;
  }
  return Object.freeze(rates);
}
export function readEffectiveRates(value){if(!value||Object.keys(value).length!==3||['exp','dil','drop'].some(k=>!Number.isFinite(value[k])||value[k]<=0||value[k]>100000))throw Error('Invalid effective server rates.');return Object.freeze({exp:value.exp,dil:value.dil,drop:value.drop});}
export const DEFAULT_WORLD_RATES=readWorldRates({});
export function scaledReward(amount,multiplier=1){const value=Number(amount);if(!Number.isFinite(value)||value<=0)return 0;return Math.min(Number.MAX_SAFE_INTEGER,Math.floor(value*multiplier));}
export function serverName(value=process.env.DEKARON_SERVER_NAME||'Dekaron Online'){if(typeof value!=='string'||!value.trim()||value.trim().length>64||/[\x00-\x1f\x7f]/.test(value))throw new Error('Server name must be 1–64 printable characters.');return value.trim();}
export function serverMetadata({rates=readWorldRates(),name=serverName(),engineVersion='1',contentVersion='unknown'}={}){return Object.freeze({protocol:1,name:serverName(name),engineVersion:String(engineVersion),contentVersion:String(contentVersion),rates:readEffectiveRates(rates)});}
