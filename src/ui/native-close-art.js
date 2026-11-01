// ENGINE-CHOSEN presentation repair for explicitly identified removed close
// sprites. Reuse the original Guild Notice close button (etc_01 315..317),
// retaining authored hit boxes. These are real native atlas rows, not new art.
// Future client data containing the original requested rows always wins.
export function repairMissingCloseButton(button,group,first,table) {
  const images=button?.spec?.images;
  if (!button?.setImage || images?.length!==3 || !images.every((image,i)=>image.screen?.toLowerCase()===group.toLowerCase()&&image.index===first+i)) return;
  if (table && images.every(image=>table.has(`${image.screen.toLowerCase()}#${image.index}`))) return;
  for (const [state,index] of [['none',315],['over',316],['down',317]]) button.setImage(state,'etc_01',index);
}
