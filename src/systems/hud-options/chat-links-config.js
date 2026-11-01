// CHAT-LINKS (chat item links + game2/itemlinkpreview/ui_itemlinkpreview.txt): the engine's own choices.
// The client data names the two windows (game2/itemlink/ui_tooltip.txt "ItemLinktooltipwnd", game2/itemlinkpreview/
// ui_itemlinkpreview.txt), the key map action 908 "Show ItemLink" (stringtable_keymap, no default key) and the preview captions
// (100:154 Preview, 2000:83 My Character, 2000:85-90 Link Pet / My Pet / Link Mount / My Mount / Link Item / My Character).
// It does not state the chat wire format, the limits or the mouse gestures, so every value below is
// ENGINE-CHOSEN (not in Global data).
export const CHAT_LINK_CONFIG = Object.freeze({
  // ENGINE-CHOSEN (not in Global data): at most this many item links in one chat message; extra links are dropped.
  maxLinksPerMessage: 3,
  // ENGINE-CHOSEN (not in Global data): the JSON size of one linked item copy; a bigger copy is cut to index / count / grade.
  maxSnapshotBytes: 2048,
  // ENGINE-CHOSEN (not in Global data): the wire token a client sends for one of its own items, {item:<uid>}; the host swaps it
  // for "[Item Name]" and attaches a copy of the item, so a client can never link an item it does not own.
  tokenName: 'item',
  // ENGINE-CHOSEN (not in Global data): Shift + left click on a bag / equipment item while the chat input line is open inserts
  // its link (with the input closed Shift + drag keeps splitting a stack).
  insertGesture: 'shift+click',
  // ENGINE-CHOSEN (not in Global data): a plain click on a link pins its tooltip (ItemLinktooltipwnd + btn_exit),
  // Ctrl + click opens the Preview window (ui_itemlinkpreview.txt); hovering shows the normal item tooltip.
  pinGesture: 'click',
  // ENGINE-CHOSEN (not in Global data): Ctrl + click on a link opens the Preview window.
  previewGesture: 'ctrl+click',
  // ENGINE-CHOSEN (not in Global data): key map 908 "Show ItemLink" (unbound by default) reopens the last link received.
  showItemLinkKey: 'last-link',
  // ENGINE-CHOSEN (not in Global data): the containers a link may point at (bag, equipped items, costume bag, cash inventory).
  linkSources: Object.freeze(['inventory', 'equip', 'costumeBag', 'cashInv']),
  // ENGINE-CHOSEN (not in Global data): pinned tooltip offset from the click (reference px).
  pinnedOffset: Object.freeze([12, 12]),
  // ENGINE-CHOSEN (not in Global data): the refusal when a message already carries maxLinksPerMessage links (no client string).
  tooManyText: 'You can link up to 3 items in one message.',
  // ENGINE-CHOSEN (not in Global data): Preview "My Pet" / "My Mount" with no own pet / mount to show (no client string).
  noOwnPetText: 'You have no pet to show.',
  // ENGINE-CHOSEN (not in Global data): the same for "My Mount".
  noOwnMountText: 'You have no mount to show.',
});