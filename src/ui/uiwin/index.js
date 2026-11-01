// UI window platform: original Dekaron windows from script/ui/**/*.txt + texture/ui atlases.
// API reference and examples: docs/UIWIN.md.
import './controls.js';
import './lists.js';
import './edit.js';
import './dnd.js';

export { UIManager, collectRefs, parseKey } from './manager.js';
export { UIWindow } from './window.js';
export { UIControl, NullControl, registerControlType, createControl, paintIcon, TYPES } from './controls.js';
export { UIScroll, UISlider, UICombo, UIList, UITextBox, UITree, UIBoard, UIMailList, UIGrid } from './lists.js';
export { UIEdit, UILegacy } from './edit.js';
export { loadScriptSpecs, buildSpecs, expandIncludes, scriptKey, parseARGB } from './spec.js';
export { parseTagScript, parseLegacyScript, parseSpriteTable, detectFormat, splitTokens } from './script.js';
export { strings, StringTables, formatString, markupRuns, parseStringList, parseStringTableCates } from './strings.js';
export { FONT_TABLE, fontCSS, fontOf, applyFont, measureText, loadFonts } from './fonts.js';
export { computeWindowBox, controlBox, REF_W, REF_H } from './layout.js';
