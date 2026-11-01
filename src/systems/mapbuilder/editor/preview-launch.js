// Reserve the sandbox window synchronously while the initiating click is active.
// Save the exact current draft before navigating; never report a blocked preview.
export async function launchSandboxPreview(editor,openWindow=(...args)=>window.open(...args)) {
  const preview=openWindow('about:blank','_blank');
  if(!preview)throw new Error('Sandbox preview was blocked. Allow popups for this game and try again.');
  try {
    if(!editor.currentId||editor.dirty)await editor.save();
    if(editor.dirty)throw new Error('The map changed during saving. Save the latest edits before playtesting.');
    const index=editor.doc.meta.index;
    if(!index)throw new Error('Save the custom map before opening its sandbox preview.');
    if(preview.closed)throw new Error('The sandbox preview window was closed before the map finished saving.');
    const url=`/tools/map-preview.html?map=${index}`;
    preview.location.replace(url);
    return url;
  } catch(error) {
    try{if(!preview.closed)preview.close();}catch{}
    throw error;
  }
}
