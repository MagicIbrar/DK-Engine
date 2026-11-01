// Authored stringtable_color.txt palette: Magic blue, Noble pale blue, Divine yellow.
export const ITEM_GRADE_COLORS = Object.freeze({ normal:'#FFFFFF', magic:'#74AEE4', noble:'#C1C1FF', divine:'#FCFC00' });
export function dilColor(value) {
  const n=Number(value)||0;
  return n<0?'#FF0000':n>=1000000000?'#FCFC00':n>=100000000?'#C1C1FF':n>=10000000?'#74AEE4':n>=1000000?'#00FF00':'#FFFFFF';
}
export function formatDil(value) { return Math.trunc(Number(value)||0).toLocaleString('en-US'); }
export function dilMarkup(value) { return `<color=${dilColor(value).slice(1)}>${formatDil(value)}</color>`; }
export function optionValueColor(value) { return Number(value)<0?'#FF0000':'#00FF00'; }
