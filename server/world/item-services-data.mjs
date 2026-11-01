import fs from 'node:fs/promises';
import path from 'node:path';
import {decodeText,parseCSV} from '../../src/formats/binreader.js';
import {loadCrestSources} from '../../src/systems/items/crest-rules.js';
import {WING_UPGRADE_COLUMNS,WING_EXCHANGE_COLUMNS} from '../../src/systems/mounts/wing-rules.js';

/** Missing original tables disable their service; they never provide guessed prices or rewards. */
export async function loadItemServiceData(dataRoot) {
  const read=async name=>{
    try {
      const rows=parseCSV(decodeText(await fs.readFile(path.join(dataRoot,name)))),header=rows.shift()||[];
      return rows.filter(row=>row.length>=header.length&&String(row[0]??'').trim()!==''&&Number.isFinite(Number(row[0]))).map(row=>Object.fromEntries(header.map((key,i)=>{
        const value=String(row[i]??'').trim();return [key.trim(),value!==''&&Number.isFinite(Number(value))?Number(value):value];
      })));
    } catch(error) {if(error.code==='ENOENT')return [];throw error;}
  };
  const [stoneProduce,stoneCrusher,talisman,sewing,disassemble,shapes,transcendence,sewingList,option,crestSources]=await Promise.all([
    'share/support/socketstone/socketstone_produce.csv','share/support/socketstone/socketstone_crusher.csv',
    'share/support/tarlismaneffecttransform/talismaneffecttransform.csv',
    'share/item/costumesewing.csv','share/item/costumedisassemble.csv',
    'share/item/costumeshapechange.csv','share/item/transcendencecostume.csv',
    'share/item/costumesewinglist.csv','share/item/costume_option.csv',
  ].map(read).concat(loadCrestSources(async name=>{
    try{return parseCSV(decodeText(await fs.readFile(path.join(dataRoot,name))));}
    catch(error){if(error.code==='ENOENT')return [];throw error;}
  })));
  // wing services: wingupgrade.csv / itemwingexchange.csv have Korean headers (columns by position, as tools/build-items.mjs renames them)
  const readPositional=async (name,keys,accept)=>{
    try {
      const rows=parseCSV(decodeText(await fs.readFile(path.join(dataRoot,name)))).slice(1);
      return rows.filter(row=>accept(row)).map(row=>Object.fromEntries(keys.map((key,i)=>{const value=String(row[i]??'').trim();return [key,value!==''&&Number.isFinite(Number(value))?Number(value):value];})));
    } catch(error) {if(error.code==='ENOENT')return [];throw error;}
  };
  const [wingUpgrade,wingExchange,wingChange]=await Promise.all([
    readPositional('share/item/wingupgrade.csv',WING_UPGRADE_COLUMNS,row=>String(row[0]??'').trim()!==''&&Number.isFinite(Number(row[2]))),
    readPositional('share/item/itemwingexchange.csv',WING_EXCHANGE_COLUMNS,row=>Number.isFinite(Number(row[0]))&&String(row[0]).trim()!==''),
    read('share/item/wingchangelist.csv'),
  ]);
  return {stoneProduce,stoneCrusher,talisman,crestSources,costume:{sewing,disassemble,shapes,transcendence,sewingList,option},wing:{upgrade:wingUpgrade,exchange:wingExchange,change:wingChange}};
}
