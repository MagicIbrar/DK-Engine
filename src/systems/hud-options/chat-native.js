// Authored Global presentation inputs, without inferring executable chat palettes.
// script/ui/game2/chat/ui_chatwnd.txt text_system / text_superchat color.
export const NATIVE_SYSTEM_COLOR = 'ffedfc00';
// script/ui/game2/messenger/ui_chatwnd.txt textview color. The script does not
// specify separate own/partner/notice colors, so keep its authored default.
export const NATIVE_MESSENGER_COLOR = 'ffffffff';
// stringtable_chat cate 230: channel names (the prefixes live in separate help entries).
export const NATIVE_CHAT_LABEL_CODES = Object.freeze({ shout:29, party:16,
  guild:17, officer:18, alliance:19, matching:82, world:87 });
// btn_color_1..55 centers within imagetable fontcolor#2 (6,27,366,199),
// texture/ui/game/chat/chat_fontcolor.dds, decoded top-down RGBA. These are the
// actual flat swatch pixels, not an HSL reconstruction or new palette.
export const NATIVE_CHAT_SWATCHES = Object.freeze([
  'ffcbbb','ffdfb2','fffac3','eff4c3','c6e6c9','b2ebf2','badefc','c3cae7','e1bde7','f7bace','ffccd1',
  'ffab91','ffcb84','fff69c','e4ef9c','a5d6a8','84deea','91cafa','9fa9d9','ce95d6','f491b0','ef9b9c',
  'ff7547','ffa721','ffef5d','d3e05d','6bba70','21c6d9','45a5f4','6370c0','aa4cbb','ec447e','ef5955',
  'f4561b','fc8e00','fcd734','c0ca31','47a14a','00adc0','1b8ae4','394daa','8f20aa','d61766','e43b34',
  'bd3708','e45600','f48213','847c13','18641b','006668','0b4ca2','161f81','4f108f','890c55','b51818',
]);
