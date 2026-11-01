// Generic undo/redo stack for the map builder. Every edit (terrain stroke, object add/move/remove, marker edit,
// env/meta change) pushes one command {label, undo(), redo()}. Commands are plain closures built by the caller
// (brushes.js, objects3d.js, markers.js, editor.js) so this file stays tool-agnostic.
const MAX = 120;

export class History {
  constructor(onChange = () => {}) {
    this.undoStack = [];
    this.redoStack = [];
    this.onChange = onChange;
  }
  /** Push an already-applied command (its redo() already happened as the live edit). */
  push(label, undo, redo) {
    this.undoStack.push({ label, undo, redo });
    if (this.undoStack.length > MAX) this.undoStack.shift();
    this.redoStack.length = 0;
    this.onChange();
  }
  get canUndo() { return this.undoStack.length > 0; }
  get canRedo() { return this.redoStack.length > 0; }
  undo() {
    const c = this.undoStack.pop();
    if (!c) return false;
    c.undo();
    this.redoStack.push(c);
    this.onChange();
    return true;
  }
  redo() {
    const c = this.redoStack.pop();
    if (!c) return false;
    c.redo();
    this.undoStack.push(c);
    this.onChange();
    return true;
  }
  clear() { this.undoStack.length = 0; this.redoStack.length = 0; this.onChange(); }
}
