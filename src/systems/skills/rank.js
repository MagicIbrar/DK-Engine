// Meister rank is separate from character level and Awakening Grade EXP.
export function meisterRank(save){const value=Number(save?.meister?.grade);return Number.isInteger(value)&&value>=0?value:save?.meister?.path?1:0;}
export function meisterRequirement(skill){return Math.max(0,Number(skill?.meister?.meisterGrade)||0);}
export function awardMeisterRank(save,reward){const grade=Number(reward?.grade),type=Number(reward?.type);if(!Number.isInteger(grade)||grade<0||!Number.isInteger(type)||type<0)throw Error('Invalid authored Meister rank award');save.meister={...(save.meister||{}),grade:Math.max(meisterRank(save),grade),type};return save.meister;}
