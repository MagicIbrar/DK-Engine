// Global store/ui_storepurchase_2 is the listing-detail page before the quantity
// confirmation (ui_storebuyconfirm_2). It does not itself mutate money or items.
export const CONSIGNMENT_DETAILS = 'shops.consigndetails';
export function installConsignmentDetails(game, { info, icon, tooltip, funds, format, purchase, available }) {
  let generation = 0, selected = null;
  const lease = () => [game.save?.id, game.network, game.network?.token];
  const sameLease = a => a.every((v, i) => v === lease()[i]);
  game.uiwin.registerWindow(CONSIGNMENT_DETAILS, {
    script: 'game2/store/ui_storepurchase_2.txt',
    modal: true,
    create(win) {
      win.control('btn_cancel').onClick(() => win.close('cancel'));
      win.control('btn_purchase').onClick(() => {
        const s = selected;
        if (!s || !s.ready || !sameLease(s.lease) || !available()) return;
        selected = null; // A second click must not open another confirmation.
        win.close('purchase');
        purchase(s.row);
      });
      win.control('btn_preview').onClick(() => {
        const s = selected;
        if (!s?.ready || !sameLease(s.lease)) return;
        game.chatLinks?.openPreview?.({ name: s.name, item: { ...s.row.entry, ...s.row.item, itemIndex: s.row.itemIndex } });
      });
      win.control('select_item').setTooltip(() => selected?.ready ? tooltip(selected.row) : null);
    },
    async onOpen(win, { row } = {}) {
      const epoch = ++generation;
      selected = null;
      win.control('btn_purchase').setEnabled(false);
      win.control('btn_preview').setEnabled(false);
      win.control('select_item').setIcon(null);
      for (const id of ['lbl_item', 'lbl_price', 'lbl_tax', 'lbl_totalprice', 'lbl_curMycash', 'lbl_SellerName', 'lbl_SeverName']) win.control(id).setText('');
      if (!row || row.mine || !available()) { win.close('unavailable'); return; }
      const s = { row: structuredClone(row), lease: lease(), ready: false, name: '' };
      selected = s;
      const item = await info(row.itemIndex);
      if (epoch !== generation || selected !== s || !sameLease(s.lease) || !win.isOpen) return;
      s.name = item.name;
      win.control('lbl_item').setText(item.name);
      win.control('lbl_price').setText(format(row.unit));
      // Global's consignment fee is seller-side. The existing host charges the
      // buyer only unit * count; do not invent a second tax here.
      win.control('lbl_tax').setText(format(0));
      win.control('lbl_totalprice').setText(format(row.unit * row.count));
      win.control('lbl_curMycash').setText(format(funds()));
      win.control('lbl_SellerName').setText(row.sellerName || '');
      win.control('lbl_SeverName').setText(game.network?.serverName || '');
      s.ready = true;
      win.control('btn_purchase').setEnabled(true);
      win.control('btn_preview').setEnabled(typeof game.chatLinks?.openPreview === 'function');
      // Render into a guarded sink: a late image from another listing must not
      // overwrite a reopened window.
      await icon({
        get box() { return win.control('select_item').box; },
        get _icon() { return epoch === generation && selected === s ? win.control('select_item')._icon : null; },
        setIcon(value) {
        if (epoch === generation && selected === s && sameLease(s.lease) && win.isOpen) win.control('select_item').setIcon(value);
      } }, row.itemIndex);
    },
    onClose() { generation++; selected = null; },
  });
  return row => game.uiwin.open(CONSIGNMENT_DETAILS, { row });
}
