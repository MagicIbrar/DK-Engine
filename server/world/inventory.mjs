import {gameplayPreferences} from '../../src/game/gameplay-preferences.js';
import {potionBelt} from '../../src/systems/items/belt.js';
import { Container, createItem } from '../../src/systems/items/model.js';

/** Validate an optional exact destination; callers transact a cloned profile. */
export function inventoryDestination(input, container) {
  if(input.page==null&&input.x==null&&input.y==null)return null;
  for(const [key,max] of [['page',container.unlocked],['x',container.cols],['y',container.rows]])
    if(!Number.isInteger(input[key])||input[key]<0||input[key]>=max)throw Object.assign(new Error('Invalid inventory destination.'),{status:400});
  return {page:input.page,x:input.x,y:input.y};
}
export function receiveAt(container,item,at) {
  return at?container.placeAt(item,at.page,at.x,at.y):(container.add(item).ok?'moved':null);
}

/** Shared pure item rules on a server-owned profile (callers transact a clone). */
export class AuthoritativeInventory {
  constructor(profile, db, { now = Date.now, random = Math.random } = {}) {
    this.profile = profile; this.db = db; this.now = now; this.random = random;
    profile.inventory ||= [];
    this.belt=potionBelt(profile,db);
    this.bag = new Container(profile.inventory, db, { pages: 7, cols: 10, rows: 5, unlocked: () => profile.bagsUnlocked || 2, name: 'bag' });
    const add=this.bag.add.bind(this.bag);this.bag.add=(item,opts)=>this.belt.byUid(item?.uid)?{ok:false,reason:'duplicate potion belt identity'}:add(item,opts);
  }
  count(index) { return this.bag.list.filter(e => e.itemIndex === Number(index) && !(e.expiresAt && e.expiresAt <= this.now())).reduce((n, e) => n + (e.count || 1), 0); }
  get dil() { return Number(this.profile.dil) || 0; }
  addDil(amount) { this.profile.dil = Math.max(0, Math.min(10_000_000_000, this.dil + Number(amount))); }
  canFit(list) {
    const profile = { ...this.profile, inventory: structuredClone(this.profile.inventory) };
    const simulated = new AuthoritativeInventory(profile, this.db, { now: this.now, random: this.random });
    return (list || []).every(e => simulated.add(e.item, e.count || 1, e));
  }
  add(index, count = 1, options = {}) {
    const def = this.db.def(Number(index));
    if (!def || !Number.isInteger(count) || count < 1 || count > 100000) return false;
    const stack = this.db.stackSize(def);
    let left = count;
    while (left > 0) {
      const n = Math.min(left, stack);
      const item = createItem(this.db, Number(index), { count: n, grade:options.grade, rnd:options.rnd, brand:options.brand, roll:options.roll,
        sockets: options.sockets, bound: options.bound, now: this.now(), rng: this.random });
      if (options.period > 0) item.expiresAt = this.now() + options.period * 1000;
      const noStack=options.noStack===true||((options.reason||options.source)==='questReward'&&!gameplayPreferences(this.profile.gameplayPreferences).stackQuestReward);
      const result = this.bag.add(item,{noStack});
      if (!result.ok) return false;
      left -= n;
    }
    return true;
  }
  remove(index, count = 1) {
    if (!Number.isInteger(count) || count < 1 || this.count(index) < count) return false;
    let left=count;
    for(const item of [...this.bag.list].filter(e => e.itemIndex===Number(index) && !(e.expiresAt && e.expiresAt<=this.now())).sort((a,b)=>(a.count||1)-(b.count||1))){
      const take=Math.min(left,item.count || 1);this.bag.take(item,take);left-=take;if(!left)break;
    }
    return left===0;
  }
  consumeEntry(entry, count = 1) {
    const owned=[this.bag,this.belt].filter(c=>c.byUid(entry?.uid));if(owned.length!==1)return false;const container=owned[0],item=container.byUid(entry?.uid);
    if (!item || (item.count || 1) < count || (item.expiresAt && item.expiresAt <= this.now())) return false;
    return !!container.take(item, count);
  }
}
