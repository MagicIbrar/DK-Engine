// ENGINE-CHOSEN presentation reuse: the exact DK Square down-scroll control
// requests missing etc_01 326..329. Reuse the native theme's authored down
// arrow states 14..17 (the same window uses matching up states 18..21).
// Regions come entirely from the original imagetable; hitboxes/actions stay intact.
export function repairDkSquareDownScroll(button,table) {
 const images=button?.spec?.images,states={none:327,over:328,down:329,disable:326},native={none:15,over:16,down:17,disable:14};
 if(!button?.setImage||images?.length!==4||!images.every(i=>i.screen?.toLowerCase()==='etc_01'&&i.index===states[i.key]))return;
 for(const image of images)if(!table?.has(`etc_01#${image.index}`)&&table?.has(`etc_01#${native[image.key]}`))button.setImage(image.key,'etc_01',native[image.key]);
}
