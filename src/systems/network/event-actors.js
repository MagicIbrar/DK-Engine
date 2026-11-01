// Actor sources share one bounded dispatcher. Per-frame wrapper flags only see
// the outer function and let independent systems endlessly wrap one another.
const registries = new WeakMap();

export function registerEventActors(network, owner, resolve, priority = 0) {
  let registry = registries.get(network);
  if (!registry) {
    const fallback = network.eventActor;
    registry = { sources: new Map(), ordered: [] };
    network.eventActor = id => {
      for (const source of registry.ordered) {
        const actor = source.resolve(id);
        if (actor) return actor;
      }
      return fallback?.call(network, id) || null;
    };
    registries.set(network, registry);
  }
  const source = { resolve, priority };
  const refresh = () => { registry.ordered = [...registry.sources.values()].sort((a, b) => b.priority - a.priority); };
  registry.sources.set(owner, source);
  refresh();
  return () => {
    // A stale disposer cannot remove a replacement from the same owner.
    if (registry.sources.get(owner) !== source) return;
    registry.sources.delete(owner);
    refresh();
  };
}
