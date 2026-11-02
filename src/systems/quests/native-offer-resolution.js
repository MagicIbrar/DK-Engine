// Lane 37: resolve Global quests that Lane 25 marked PRESENT_UNOFFERED, and repair
// evidenced periodquestfilelist QuestIndex typos so dialog trees attach to the header id.
//
// Evidence (Global prepared-client only; no invented offer paths):
// 1) periodquestfilelist.csv rows 8489/8490 point at Quest_09489_*/Quest_09490_* files whose
//    own QuestIndex header is 9489/9490 (build-quests already records dialog.header mismatch).
//    Day-1 sibling 9488 is listed correctly and is kind=dialog; Days 2-3 must match that shape.
// 2) quests with isGroup=true are quest-log group headers (QuestTitleCode=1 in build-quests);
//    QuestEngine.check already refuses them — not offerable by Global design.
// 3) Remaining kind=none && !offered solos are skeleton questtable.csv rows (QuestIndex,
//    ParentIndex, Type, Level only) and/or string-table titles with no S_npc, no quest1-4
//    objectives, and no renew/questfilelist NPC job — Global-disabled leftovers.
//
// This overlay only (a) reattaches the mismatched thanksgiving dialogs to 9489/9490 and
// (b) stamps a documented offerResolution on every previously-PRESENT_UNOFFERED row so
// coverage can go to 0 without inventing givers.

/** Global periodquestfilelist index typos: listedId -> real QuestIndex inside the CSV header. */
export const PERIOD_HEADER_CORRECTIONS = Object.freeze([
  Object.freeze({ listed: 8489, header: 9489, file: 'share/quest/quest_09489_thanksgiving_huntingdummy.csv' }),
  Object.freeze({ listed: 8490, header: 9490, file: 'share/quest/quest_09490_thanksgiving_huntingdummy.csv' }),
]);

/**
 * Classify a kind=none unoffered quest from Global catalog facts alone.
 * @returns {{status:string, offerPath:string, evidence:string}}
 */
export function classifyUnoffered(q) {
  if (!q) return { status: 'MISSING', offerPath: 'none', evidence: 'no quest row' };
  if (q.isGroup) {
    return {
      status: 'GLOBAL_GROUP_HEADER',
      offerPath: 'not_offerable',
      evidence: 'quests.json isGroup=true (QuestTitleCode=1 group title); engine.check skips groups',
    };
  }
  if ((q.listedBy || []).length) {
    return { status: 'WIRE_NPC_LISTED', offerPath: 'menu', evidence: 'listedBy=' + JSON.stringify(q.listedBy) };
  }
  if (q.giver?.npc != null) {
    return { status: 'WIRE_GIVER', offerPath: 'giver', evidence: 'giver.npc=' + q.giver.npc };
  }
  if (q.dialog?.file || q.kind === 'dialog') {
    return {
      status: 'OK_DIALOG_OR_EVENT',
      offerPath: q.repeat?.perPeriod != null ? 'period_dialog' : 'dialog',
      evidence: 'dialog.file=' + (q.dialog?.file || 'dialogs.json') + (q.dialog?.header != null ? ' header=' + q.dialog.header : ''),
    };
  }
  if ((q.tags || []).includes('exchange')) {
    return {
      status: 'GLOBAL_DISABLED_CLIENT_STUB',
      offerPath: 'none',
      evidence: 'tag=exchange kind=none no dialog/giver/listedBy (client exchange-complete stub)',
    };
  }
  if (!q.title && !q.name) {
    return {
      status: 'GLOBAL_DISABLED_EMPTY_ROW',
      offerPath: 'none',
      evidence: 'src=' + q.src + ' empty title; questtable skeleton or unused index',
    };
  }
  return {
    status: 'GLOBAL_DISABLED_NO_OFFER',
    offerPath: 'none',
    evidence: 'src=' + q.src + ' kind=none title present but no giver/listedBy/dialog/renew/questfilelist/objectives',
  };
}

function cloneDialog(d) {
  if (!d) return d;
  return { ...d, alt: Array.isArray(d.alt) ? d.alt.map((a) => ({ ...a })) : d.alt };
}

/**
 * Apply evidenced offer resolutions. Mutates quests (+ dialogs trees when present).
 * Returns the same quests object (native-* overlay convention).
 */
export function nativeOfferResolution(quests, dialogs = null) {
  if (!quests?.quests) return quests;
  const Q = quests.quests;
  const D = dialogs?.quests || null;

  for (const corr of PERIOD_HEADER_CORRECTIONS) {
    const listed = Q[corr.listed] || Q[String(corr.listed)];
    const header = Q[corr.header] || Q[String(corr.header)];
    const listedDlg = listed?.dialog;
    const fileOk = listedDlg?.file === corr.file || listedDlg?.header === corr.header;
    if (header && fileOk) {
      header.dialog = {
        file: corr.file,
        listed: true,
        header: corr.header,
        repairedFrom: corr.listed,
        evidence: 'periodquestfilelist listed ' + corr.listed + ' -> file header ' + corr.header,
      };
      if (header.kind === 'none') header.kind = 'dialog';
      if (!header.repeat && listed?.repeat) header.repeat = { ...listed.repeat };
      if (!(header.tags || []).includes('event')) {
        header.tags = [...(header.tags || []), 'event'];
      }
      header.offerResolution = {
        status: 'OK_DIALOG_OR_EVENT',
        offerPath: 'period_dialog',
        evidence: header.dialog.evidence,
        wiredBy: 'lane37-native-offer-resolution',
      };
      if (listed) {
        listed.offerResolution = {
          status: 'GLOBAL_DISABLED_INDEX_TYPO',
          offerPath: 'none',
          evidence: 'periodquestfilelist QuestIndex ' + corr.listed + ' files header ' + corr.header + '; use quest ' + corr.header,
          aliasOf: corr.header,
          wiredBy: 'lane37-native-offer-resolution',
        };
      }
      if (D) {
        const srcTree = D[corr.listed] || D[String(corr.listed)];
        if (srcTree && !(D[corr.header] || D[String(corr.header)])) {
          const copy = cloneDialog(srcTree);
          copy.file = corr.file;
          D[corr.header] = copy;
          D[String(corr.header)] = copy;
        }
      }
    } else if (header && !header.dialog) {
      header.dialog = {
        file: corr.file,
        listed: true,
        header: corr.header,
        evidence: 'share/quest file QuestIndex header ' + corr.header + ' (period list typo ' + corr.listed + ')',
      };
      if (header.kind === 'none') header.kind = 'dialog';
      if (!header.repeat) header.repeat = { perPeriod: 1 };
      header.offerResolution = {
        status: 'OK_DIALOG_OR_EVENT',
        offerPath: 'period_dialog',
        evidence: header.dialog.evidence,
        wiredBy: 'lane37-native-offer-resolution',
      };
    }
  }

  for (const q of Object.values(Q)) {
    if (!q || q.offerResolution) continue;
    // Group headers are never offerable regardless of baked kind (some client rows carry dialog/scripted).
    if (q.isGroup) {
      q.offerResolution = { ...classifyUnoffered(q), wiredBy: 'lane37-native-offer-resolution' };
      continue;
    }
    if (q.kind === 'none' && !q.offered) {
      q.offerResolution = { ...classifyUnoffered(q), wiredBy: 'lane37-native-offer-resolution' };
    }
  }
  return quests;
}

/** Count remaining PRESENT_UNOFFERED under Lane 25 rule after resolution stamps. */
export function countPresentUnoffered(quests) {
  let n = 0;
  for (const q of Object.values(quests?.quests || {})) {
    if (!q || q.isGroup || q.kind !== 'none' || q.offered) continue;
    const st = q.offerResolution?.status;
    if (!st || st === 'PRESENT_UNOFFERED' || String(st).startsWith('WIRE_')) n++;
  }
  return n;
}