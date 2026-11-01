import { borrowPreviewIcon } from '../../ui/preview-cache.js';

// Store static shop thumbnails independently of the bounded live 3D preview
// cache. Keeping compressed PNGs avoids pinning the whole catalogue's decoded
// GPU previews or rebaking a product each time another page evicts its model.
export async function retainShopBitmap(icon) {
  if (!icon?.url || !icon.url.startsWith('blob:') || typeof FileReader !== 'function') return icon;
  const release = borrowPreviewIcon(icon);
  try {
    const blob = await fetch(icon.url).then(response => {
      if (!response.ok) throw Error('Shop thumbnail could not be retained.');
      return response.blob();
    });
    const url = await new Promise((resolve, reject) => {
      const reader = new FileReader();
      reader.onload = () => resolve(reader.result);
      reader.onerror = () => reject(reader.error || Error('Shop thumbnail could not be retained.'));
      reader.readAsDataURL(blob);
    });
    return { url };
  } catch {
    // Browsers without a working bitmap export keep the canonical live icon.
    return icon;
  } finally { release(); }
}
