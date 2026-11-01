import { ShopPageAssets } from '../shops/page-assets.js';
import { copyPreviewIcon } from '../../ui/preview-cache.js';
/** Page-scoped native stills. The canonical icon cache owns and revokes URLs. */
export class DekaPassRewardAssets {
  constructor(load, { generation = () => 0, ...options } = {}) {
    this.generation = generation; this.current = generation(); this.disposed = false;
    this.assets = new ShopPageAssets(async (id, info) => {
      const epoch = this.sync(), value = await load(id, info);
      return !this.disposed && epoch === this.sync() && value ? copyPreviewIcon(value, { generation: epoch }) : null;
    }, { concurrency: 2, limit: 30, ...options });
  }
  sync() { const next = this.generation(); if (next !== this.current) { this.current = next; this.assets.cache.clear(); } for (const [id, value] of this.assets.cache) if (!value?.url) this.assets.cache.delete(id); return next; }
  now(id) { const epoch = this.sync(), value = this.assets.now(id); return value?.generation === epoch ? value : null; }
  ids(rewards, page) {
    if (page < 0) return [];
    return [...new Set(rewards.slice(page * 5, page * 5 + 5).flatMap(row => [row.basic[0], row.premium[0]]).map(Number).filter(id => id > 0))];
  }
  page(rewards, page, options = {}) { this.sync(); return this.assets.page(this.ids(rewards, page), options); }
  neighbors(rewards, page, { signal } = {}) { this.sync(); return this.assets.page([...this.ids(rewards, page - 1), ...this.ids(rewards, page + 1)], { signal, priority: 1 }); }
  visible(id, { onReady, ...options }) {
    this.sync(); return this.assets.visible(id, { ...options, onReady: value => { if (value.generation === this.sync()) onReady?.(value); } });
  }
  dispose() { this.disposed = true; this.assets.dispose(); }
}
