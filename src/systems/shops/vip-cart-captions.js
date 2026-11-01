// Native VIP captions get two original-font rows inside the cart column.
// Full localized text, colors and number widths stay in their original controls.
export function fitVipCartCaptions(win) {
  const current = win.find('lbl_tagcurrentcash'), total = win.find('lbl_tagallpaycash');
  const remain = win.find('lbl_tagremaincash'), buy = win.find('btn_allbuy');
  if (!current || !total || !remain || !buy) return;
  const rowHeight = 28, gap = 6;
  for (const [caption, amountId, minY, maxBottom] of [
    [total, 'lbl_allpaycash', current.spec.rect[1] + current.spec.rect[3] + 4, remain.spec.rect[1] - 4],
    [remain, 'lbl_remaincash', remain.spec.rect[1], buy.spec.rect[1] - 3],
  ]) {
    const amount = win.find(amountId);
    if (!amount) continue;
    const [x, originalY, , originalHeight] = caption.spec.rect;
    const [numberX, , numberWidth, numberHeight] = amount.spec.rect;
    const width = numberX - gap - x;
    if (width <= 0 || maxBottom - minY < rowHeight) continue;
    const y = Math.max(minY, Math.min(originalY - (rowHeight - originalHeight) / 2, maxBottom - rowHeight));
    caption.spec = { ...caption.spec, props: { ...caption.spec.props, autoline: ['true'], lineheight: ['14'] } };
    caption.setRect(x, y, width, rowHeight);
    // Collapse wrap-boundary spaces while preserving explicit native line breaks.
    if (caption.txt) caption.txt.style.whiteSpace = 'pre-line';
    amount.setRect(numberX, y + (rowHeight - numberHeight) / 2, numberWidth, numberHeight);
  }
}
