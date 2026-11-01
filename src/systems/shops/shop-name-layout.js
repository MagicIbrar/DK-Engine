/** Original Tahoma text, fitted above the original variant combo. measure uses the original font. */
export function shopNameLayout(name, measure, { rect = [84, 32, 143, 14], comboY = 57 } = {}) {
  const [x, originalY, width, originalHeight] = rect;
  let lines = 0;
  for (const paragraph of String(name).split('\n')) {
    let line = '', count = 1;
    for (const word of paragraph.split(/\s+/).filter(Boolean)) {
      const next = line ? line + ' ' + word : word;
      if (measure(next) <= width) { line = next; continue; }
      if (line) { count++; line = ''; }
      for (const char of word) {
        if (line && measure(line + char) > width) { count++; line = ''; }
        line += char;
      }
    }
    lines += count;
  }
  const available = Math.max(1, comboY - 4);
  const lineHeight = lines === 1 ? Math.min(15, originalHeight) : Math.max(12, Math.min(15, Math.floor(available / lines)));
  const height = lines === 1 ? originalHeight : Math.min(available, lines * lineHeight);
  const y = lines === 1 ? Math.min(originalY, comboY - 2 - height) : Math.max(2, comboY - 2 - height);
  return { x, y, width, height, lines, lineHeight, clipped: lines * lineHeight > available };
}
