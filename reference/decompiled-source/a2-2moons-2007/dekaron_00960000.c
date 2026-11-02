// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x960000-0x96ffff

// ==== FUN_00960ee0 @ 0x00960ee0 ====

void FUN_00960ee0(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short *psVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  short sVar9;
  short sVar10;
  int iVar11;
  short sVar12;
  int local_1c;
  
  psVar4 = (short *)(param_1 + 4);
  local_1c = 8;
  do {
    sVar7 = psVar4[-2] + psVar4[5];
    sVar12 = psVar4[-2] - psVar4[5];
    sVar3 = psVar4[-1] + psVar4[4];
    sVar5 = psVar4[-1] - psVar4[4];
    sVar9 = psVar4[3] + *psVar4;
    sVar6 = *psVar4 - psVar4[3];
    sVar10 = psVar4[2] + psVar4[1];
    sVar1 = psVar4[2];
    sVar2 = sVar10 + sVar7;
    sVar7 = sVar7 - sVar10;
    psVar4[-2] = sVar9 + sVar3 + sVar2;
    psVar4[2] = sVar2 - (sVar9 + sVar3);
    sVar3 = (short)((uint)(((int)(short)(sVar3 - sVar9) + (int)sVar7) * 0xb5) >> 8);
    psVar4[4] = sVar7 - sVar3;
    *psVar4 = sVar3 + sVar7;
    iVar11 = (int)(short)((psVar4[1] - sVar1) + sVar6);
    iVar8 = (int)(short)(sVar5 + sVar12);
    sVar1 = (short)((uint)((iVar11 - iVar8) * 0x62) >> 8);
    sVar7 = (short)((uint)(iVar11 * 0x8b) >> 8) + sVar1;
    sVar1 = (short)((uint)(iVar8 * 0x14e) >> 8) + sVar1;
    sVar2 = (short)((uint)((short)(sVar6 + sVar5) * 0xb5) >> 8);
    sVar3 = sVar2 + sVar12;
    sVar12 = sVar12 - sVar2;
    psVar4[3] = sVar12 + sVar7;
    psVar4[-1] = sVar3 + sVar1;
    psVar4[1] = sVar12 - sVar7;
    psVar4[5] = sVar3 - sVar1;
    psVar4 = psVar4 + 8;
    local_1c = local_1c + -1;
  } while (local_1c != 0);
  psVar4 = (short *)(param_1 + 0x20);
  param_1 = 8;
  do {
    sVar7 = psVar4[-0x10] + psVar4[0x28];
    sVar12 = psVar4[-0x10] - psVar4[0x28];
    sVar3 = psVar4[-8] + psVar4[0x20];
    sVar5 = psVar4[-8] - psVar4[0x20];
    sVar9 = psVar4[0x18] + *psVar4;
    sVar6 = *psVar4 - psVar4[0x18];
    sVar10 = psVar4[0x10] + psVar4[8];
    sVar1 = psVar4[0x10];
    sVar2 = sVar10 + sVar7;
    sVar7 = sVar7 - sVar10;
    psVar4[-0x10] = sVar9 + sVar3 + sVar2;
    psVar4[0x10] = sVar2 - (sVar9 + sVar3);
    sVar3 = (short)((uint)(((int)(short)(sVar3 - sVar9) + (int)sVar7) * 0xb5) >> 8);
    psVar4[0x20] = sVar7 - sVar3;
    *psVar4 = sVar3 + sVar7;
    iVar11 = (int)(short)(sVar6 + (psVar4[8] - sVar1));
    iVar8 = (int)(short)(sVar5 + sVar12);
    sVar1 = (short)((uint)((iVar11 - iVar8) * 0x62) >> 8);
    sVar7 = (short)((uint)(iVar11 * 0x8b) >> 8) + sVar1;
    sVar1 = (short)((uint)(iVar8 * 0x14e) >> 8) + sVar1;
    sVar2 = (short)((uint)((short)(sVar6 + sVar5) * 0xb5) >> 8);
    sVar3 = sVar2 + sVar12;
    sVar12 = sVar12 - sVar2;
    psVar4[0x18] = sVar12 + sVar7;
    psVar4[-8] = sVar3 + sVar1;
    psVar4[8] = sVar12 - sVar7;
    psVar4[0x28] = sVar3 - sVar1;
    psVar4 = psVar4 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}


// ==== FUN_00961130 @ 0x00961130 ====

void FUN_00961130(int param_1)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_20;
  
  psVar3 = (short *)(param_1 + 4);
  local_20 = 8;
  do {
    iVar5 = (int)psVar3[-2] + (int)psVar3[5];
    iVar8 = (int)psVar3[-2] - (int)psVar3[5];
    iVar6 = (int)psVar3[-1] + (int)psVar3[4];
    iVar10 = (int)psVar3[-1] - (int)psVar3[4];
    iVar7 = (int)psVar3[3] + (int)*psVar3;
    iVar11 = (int)*psVar3 - (int)psVar3[3];
    iVar9 = (int)psVar3[2] + (int)psVar3[1];
    iVar4 = (int)psVar3[1] - (int)psVar3[2];
    sVar2 = (short)iVar9 + (short)iVar5;
    iVar5 = iVar5 - iVar9;
    sVar1 = (short)iVar7 + (short)iVar6;
    iVar6 = iVar6 - iVar7;
    psVar3[-2] = (sVar1 + sVar2) * 4;
    psVar3[2] = (sVar2 - sVar1) * 4;
    iVar7 = (iVar6 + iVar5) * 0x1151;
    *psVar3 = (short)(iVar5 * 0x187e + 0x400 + iVar7 >> 0xb);
    psVar3[4] = (short)(iVar7 + iVar6 * -0x3b21 + 0x400 >> 0xb);
    iVar9 = (iVar11 + iVar8 + iVar4 + iVar10) * 0x25a1;
    iVar5 = (iVar4 + iVar8) * -0x1ccd;
    iVar6 = (iVar11 + iVar10) * -0x5203;
    iVar7 = iVar9 + (iVar4 + iVar10) * -0x3ec5;
    iVar9 = iVar9 + (iVar11 + iVar8) * -0xc7c;
    psVar3[5] = (short)(iVar4 * 0x98e + iVar7 + 0x400 + iVar5 >> 0xb);
    psVar3[3] = (short)(iVar11 * 0x41b3 + iVar9 + 0x400 + iVar6 >> 0xb);
    psVar3[1] = (short)(iVar10 * 0x6254 + iVar7 + 0x400 + iVar6 >> 0xb);
    psVar3[-1] = (short)(iVar8 * 0x300b + iVar9 + 0x400 + iVar5 >> 0xb);
    psVar3 = psVar3 + 8;
    local_20 = local_20 + -1;
  } while (local_20 != 0);
  psVar3 = (short *)(param_1 + 0x20);
  param_1 = 8;
  do {
    iVar5 = (int)psVar3[-0x10] + (int)psVar3[0x28];
    iVar8 = (int)psVar3[-0x10] - (int)psVar3[0x28];
    iVar6 = (int)psVar3[-8] + (int)psVar3[0x20];
    iVar11 = (int)psVar3[-8] - (int)psVar3[0x20];
    iVar7 = (int)psVar3[0x18] + (int)*psVar3;
    iVar12 = (int)*psVar3 - (int)psVar3[0x18];
    iVar9 = (int)psVar3[0x10] + (int)psVar3[8];
    iVar4 = (int)psVar3[8] - (int)psVar3[0x10];
    iVar10 = iVar9 + iVar5;
    iVar5 = iVar5 - iVar9;
    iVar9 = iVar7 + iVar6;
    iVar6 = iVar6 - iVar7;
    psVar3[-0x10] = (short)(iVar9 + 2 + iVar10 >> 2);
    psVar3[0x10] = (short)((iVar10 - iVar9) + 2 >> 2);
    iVar7 = (iVar6 + iVar5) * 0x1151;
    *psVar3 = (short)(iVar5 * 0x187e + 0x4000 + iVar7 >> 0xf);
    psVar3[0x20] = (short)(iVar7 + iVar6 * -0x3b21 + 0x4000 >> 0xf);
    iVar9 = (iVar12 + iVar8 + iVar4 + iVar11) * 0x25a1;
    iVar5 = (iVar4 + iVar8) * -0x1ccd;
    iVar6 = (iVar12 + iVar11) * -0x5203;
    iVar7 = iVar9 + (iVar4 + iVar11) * -0x3ec5;
    iVar9 = iVar9 + (iVar12 + iVar8) * -0xc7c;
    psVar3[0x28] = (short)(iVar4 * 0x98e + iVar7 + 0x4000 + iVar5 >> 0xf);
    psVar3[0x18] = (short)(iVar12 * 0x41b3 + iVar9 + 0x4000 + iVar6 >> 0xf);
    psVar3[8] = (short)(iVar11 * 0x6254 + iVar7 + 0x4000 + iVar6 >> 0xf);
    psVar3[-8] = (short)(iVar8 * 0x300b + iVar9 + 0x4000 + iVar5 >> 0xf);
    psVar3 = psVar3 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}


// ==== FUN_0096146b @ 0x0096146b ====

void FUN_0096146b(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(param_5 + 0x20))(*(undefined4 *)(param_5 + 0x28),1,0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    *(undefined1 *)(puVar1 + 4) = param_1;
    *(undefined1 *)((int)puVar1 + 0x11) = param_2;
    puVar1[5] = param_3;
    puVar1[6] = param_4;
  }
  return;
}


// ==== FUN_009614a0 @ 0x009614a0 ====

void FUN_009614a0(uint param_1,int *param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *local_14;
  undefined1 *local_10;
  uint local_c;
  byte *local_8;
  
  piVar6 = param_2;
  iVar5 = param_1;
  local_8 = (byte *)*param_2;
  local_c = param_2[1];
  puVar10 = *(undefined1 **)(param_1 + 0x34);
  piVar2 = *(int **)(param_1 + 4);
  param_2 = *(int **)(param_1 + 0x20);
  if (puVar10 < *(undefined1 **)(param_1 + 0x30)) {
    local_10 = *(undefined1 **)(param_1 + 0x30) + (-1 - (int)puVar10);
    param_1 = *(uint *)(param_1 + 0x1c);
  }
  else {
    local_10 = (undefined1 *)(*(int *)(param_1 + 0x2c) - (int)puVar10);
    param_1 = *(uint *)(param_1 + 0x1c);
  }
  do {
    puVar9 = puVar10;
    switch(*piVar2) {
    case 0:
      if (((undefined1 *)0x101 < local_10) && (9 < local_c)) {
        *(int **)(iVar5 + 0x20) = param_2;
        *(uint *)(iVar5 + 0x1c) = param_1;
        piVar6[1] = local_c;
        piVar6[2] = (int)(local_8 + (piVar6[2] - *piVar6));
        *piVar6 = (int)local_8;
        *(undefined1 **)(iVar5 + 0x34) = puVar10;
        param_3 = FUN_0096205b((char)piVar2[4],*(undefined1 *)((int)piVar2 + 0x11),piVar2[5],
                               piVar2[6],iVar5,piVar6);
        puVar10 = *(undefined1 **)(iVar5 + 0x34);
        local_8 = (byte *)*piVar6;
        local_c = piVar6[1];
        param_2 = *(int **)(iVar5 + 0x20);
        param_1 = *(uint *)(iVar5 + 0x1c);
        if (puVar10 < *(undefined1 **)(iVar5 + 0x30)) {
          local_10 = *(undefined1 **)(iVar5 + 0x30) + (-1 - (int)puVar10);
        }
        else {
          local_10 = (undefined1 *)(*(int *)(iVar5 + 0x2c) - (int)puVar10);
        }
        if (param_3 != 0) {
          *piVar2 = (uint)(param_3 != 1) * 2 + 7;
          break;
        }
      }
      piVar2[3] = (uint)*(byte *)(piVar2 + 4);
      piVar2[2] = piVar2[5];
      *piVar2 = 1;
    case 1:
      for (; param_1 < (uint)piVar2[3]; param_1 = param_1 + 8) {
        if (local_c == 0) goto LAB_00961961;
        param_3 = 0;
        local_c = local_c - 1;
        param_2 = (int *)((uint)param_2 | (uint)*local_8 << ((byte)param_1 & 0x1f));
        local_8 = local_8 + 1;
      }
      pbVar7 = (byte *)(piVar2[2] + (*(uint *)(&DAT_00a30790 + piVar2[3] * 4) & (uint)param_2) * 8);
      param_2 = (int *)((uint)param_2 >> (pbVar7[1] & 0x1f));
      param_1 = param_1 - pbVar7[1];
      bVar1 = *pbVar7;
      uVar8 = (uint)bVar1;
      if (uVar8 == 0) {
        pbVar7 = *(byte **)(pbVar7 + 4);
        *piVar2 = 6;
      }
      else {
        if ((bVar1 & 0x10) != 0) {
          piVar2[2] = uVar8 & 0xf;
          piVar2[1] = *(int *)(pbVar7 + 4);
          *piVar2 = 2;
          break;
        }
        if ((bVar1 & 0x40) != 0) {
          if ((bVar1 & 0x20) == 0) {
            *piVar2 = 9;
            piVar6[6] = (int)s_invalid_literal_length_code_00a2f358;
switchD_009614e7_caseD_9:
            param_3 = -3;
            puVar9 = puVar10;
            goto LAB_00961912;
          }
          *piVar2 = 7;
          break;
        }
        piVar2[3] = uVar8;
        pbVar7 = pbVar7 + *(int *)(pbVar7 + 4) * 8;
      }
LAB_00961724:
      piVar2[2] = (int)pbVar7;
      break;
    case 2:
      for (; param_1 < (uint)piVar2[2]; param_1 = param_1 + 8) {
        if (local_c == 0) goto LAB_00961961;
        param_3 = 0;
        local_c = local_c - 1;
        param_2 = (int *)((uint)param_2 | (uint)*local_8 << ((byte)param_1 & 0x1f));
        local_8 = local_8 + 1;
      }
      piVar2[1] = piVar2[1] + (*(uint *)(&DAT_00a30790 + piVar2[2] * 4) & (uint)param_2);
      param_2 = (int *)((uint)param_2 >> ((byte)piVar2[2] & 0x1f));
      param_1 = param_1 - piVar2[2];
      piVar2[3] = (uint)*(byte *)((int)piVar2 + 0x11);
      piVar2[2] = piVar2[6];
      *piVar2 = 3;
    case 3:
      for (; param_1 < (uint)piVar2[3]; param_1 = param_1 + 8) {
        if (local_c == 0) goto LAB_00961961;
        param_3 = 0;
        local_c = local_c - 1;
        param_2 = (int *)((uint)param_2 | (uint)*local_8 << ((byte)param_1 & 0x1f));
        local_8 = local_8 + 1;
      }
      pbVar7 = (byte *)(piVar2[2] + (*(uint *)(&DAT_00a30790 + piVar2[3] * 4) & (uint)param_2) * 8);
      param_2 = (int *)((uint)param_2 >> (pbVar7[1] & 0x1f));
      param_1 = param_1 - pbVar7[1];
      bVar1 = *pbVar7;
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          *piVar2 = 9;
          piVar6[6] = (int)(s_5_invalid_distance_code_00a2f33e + 2);
          goto switchD_009614e7_caseD_9;
        }
        piVar2[3] = (uint)bVar1;
        pbVar7 = pbVar7 + *(int *)(pbVar7 + 4) * 8;
        goto LAB_00961724;
      }
      piVar2[2] = bVar1 & 0xf;
      piVar2[3] = *(int *)(pbVar7 + 4);
      *piVar2 = 4;
      break;
    case 4:
      for (; param_1 < (uint)piVar2[2]; param_1 = param_1 + 8) {
        if (local_c == 0) goto LAB_00961961;
        param_3 = 0;
        local_c = local_c - 1;
        param_2 = (int *)((uint)param_2 | (uint)*local_8 << ((byte)param_1 & 0x1f));
        local_8 = local_8 + 1;
      }
      piVar2[3] = piVar2[3] + (*(uint *)(&DAT_00a30790 + piVar2[2] * 4) & (uint)param_2);
      param_2 = (int *)((uint)param_2 >> ((byte)piVar2[2] & 0x1f));
      param_1 = param_1 - piVar2[2];
      *piVar2 = 5;
    case 5:
      local_14 = puVar10 + -piVar2[3];
      if (local_14 < *(undefined1 **)(iVar5 + 0x28)) {
        do {
          local_14 = local_14 + (*(int *)(iVar5 + 0x2c) - (int)*(undefined1 **)(iVar5 + 0x28));
        } while (local_14 < *(undefined1 **)(iVar5 + 0x28));
      }
      while (piVar2[1] != 0) {
        puVar9 = puVar10;
        if (local_10 == (undefined1 *)0x0) {
          if (puVar10 == *(undefined1 **)(iVar5 + 0x2c)) {
            local_10 = *(undefined1 **)(iVar5 + 0x30);
            puVar9 = *(undefined1 **)(iVar5 + 0x28);
            if (local_10 != puVar9) {
              if (puVar9 < local_10) {
                local_10 = local_10 + (-1 - (int)puVar9);
              }
              else {
                local_10 = *(undefined1 **)(iVar5 + 0x2c) + -(int)puVar9;
              }
              puVar10 = puVar9;
              if (local_10 != (undefined1 *)0x0) goto LAB_00961838;
            }
          }
          *(undefined1 **)(iVar5 + 0x34) = puVar10;
          param_3 = FUN_00961f48(iVar5,piVar6,param_3);
          puVar9 = *(undefined1 **)(iVar5 + 0x34);
          puVar10 = *(undefined1 **)(iVar5 + 0x30);
          if (puVar9 < puVar10) {
            local_10 = puVar10 + (-1 - (int)puVar9);
          }
          else {
            local_10 = (undefined1 *)(*(int *)(iVar5 + 0x2c) - (int)puVar9);
          }
          if ((puVar9 == *(undefined1 **)(iVar5 + 0x2c)) &&
             (puVar3 = *(undefined1 **)(iVar5 + 0x28), puVar10 != puVar3)) {
            puVar9 = puVar3;
            if (puVar3 < puVar10) {
              local_10 = puVar10 + (-1 - (int)puVar3);
            }
            else {
              local_10 = *(undefined1 **)(iVar5 + 0x2c) + -(int)puVar3;
            }
          }
          if (local_10 == (undefined1 *)0x0) goto LAB_00961912;
        }
LAB_00961838:
        param_3 = 0;
        *puVar9 = *local_14;
        puVar10 = puVar9 + 1;
        local_14 = local_14 + 1;
        local_10 = local_10 + -1;
        if (local_14 == *(undefined1 **)(iVar5 + 0x2c)) {
          local_14 = *(undefined1 **)(iVar5 + 0x28);
        }
        piVar2[1] = piVar2[1] + -1;
      }
      *piVar2 = 0;
      break;
    case 6:
      if (local_10 != (undefined1 *)0x0) goto LAB_009618f4;
      if (puVar10 == *(undefined1 **)(iVar5 + 0x2c)) {
        local_10 = *(undefined1 **)(iVar5 + 0x30);
        puVar9 = *(undefined1 **)(iVar5 + 0x28);
        if (local_10 != puVar9) {
          if (puVar9 < local_10) {
            local_10 = local_10 + (-1 - (int)puVar9);
          }
          else {
            local_10 = *(undefined1 **)(iVar5 + 0x2c) + -(int)puVar9;
          }
          puVar10 = puVar9;
          if (local_10 != (undefined1 *)0x0) goto LAB_009618f4;
        }
      }
      *(undefined1 **)(iVar5 + 0x34) = puVar10;
      param_3 = FUN_00961f48(iVar5,piVar6,param_3);
      puVar9 = *(undefined1 **)(iVar5 + 0x34);
      puVar10 = *(undefined1 **)(iVar5 + 0x30);
      if (puVar9 < puVar10) {
        local_10 = puVar10 + (-1 - (int)puVar9);
      }
      else {
        local_10 = (undefined1 *)(*(int *)(iVar5 + 0x2c) - (int)puVar9);
      }
      if ((puVar9 == *(undefined1 **)(iVar5 + 0x2c)) &&
         (puVar3 = *(undefined1 **)(iVar5 + 0x28), puVar10 != puVar3)) {
        puVar9 = puVar3;
        if (puVar3 < puVar10) {
          local_10 = puVar10 + (-1 - (int)puVar3);
        }
        else {
          local_10 = *(undefined1 **)(iVar5 + 0x2c) + -(int)puVar3;
        }
      }
      if (local_10 == (undefined1 *)0x0) goto LAB_00961912;
LAB_009618f4:
      param_3 = 0;
      *puVar9 = (char)piVar2[2];
      puVar10 = puVar9 + 1;
      local_10 = local_10 + -1;
      *piVar2 = 0;
      break;
    case 7:
      if (7 < param_1) {
        param_1 = param_1 - 8;
        local_c = local_c + 1;
        local_8 = local_8 + -1;
      }
      *(undefined1 **)(iVar5 + 0x34) = puVar10;
      param_3 = FUN_00961f48(iVar5,piVar6,param_3);
      puVar10 = *(undefined1 **)(iVar5 + 0x34);
      if (*(undefined1 **)(iVar5 + 0x30) == puVar10) {
        *piVar2 = 8;
switchD_009614e7_caseD_8:
        param_3 = 1;
        puVar9 = puVar10;
LAB_00961912:
        *(int **)(iVar5 + 0x20) = param_2;
        *(uint *)(iVar5 + 0x1c) = param_1;
        piVar6[1] = local_c;
        puVar10 = puVar9;
LAB_00961924:
        iVar4 = *piVar6;
        *piVar6 = (int)local_8;
        piVar6[2] = (int)(local_8 + (piVar6[2] - iVar4));
      }
      else {
        *(int **)(iVar5 + 0x20) = param_2;
        *(uint *)(iVar5 + 0x1c) = param_1;
        piVar6[1] = local_c;
        iVar4 = *piVar6;
        *piVar6 = (int)local_8;
        piVar6[2] = (int)(local_8 + (piVar6[2] - iVar4));
      }
      *(undefined1 **)(iVar5 + 0x34) = puVar10;
      FUN_00961f48(iVar5,piVar6,param_3);
      return;
    case 8:
      goto switchD_009614e7_caseD_8;
    case 9:
      goto switchD_009614e7_caseD_9;
    default:
      param_3 = -2;
      goto LAB_00961912;
    }
  } while( true );
LAB_00961961:
  *(int **)(iVar5 + 0x20) = param_2;
  *(uint *)(iVar5 + 0x1c) = param_1;
  piVar6[1] = 0;
  goto LAB_00961924;
}


// ==== FUN_009619f9 @ 0x009619f9 ====

void FUN_009619f9(undefined4 param_1,int param_2)

{
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return;
}


// ==== FUN_00961a0e @ 0x00961a0e ====

undefined4
FUN_00961a0e(uint *param_1,uint param_2,uint param_3,int param_4,int param_5,int *param_6,
            int param_7,uint *param_8,uint *param_9)

{
  undefined3 uVar1;
  uint *in_EAX;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  byte bVar11;
  int iVar12;
  undefined4 uStack_10c;
  int local_fc [15];
  uint local_c0 [16];
  uint local_80 [17];
  int local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  uint *local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_80[0] = 0;
  local_80[1] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[4] = 0;
  local_80[5] = 0;
  local_80[6] = 0;
  local_80[7] = 0;
  local_80[8] = 0;
  local_80[9] = 0;
  local_80[10] = 0;
  local_80[0xb] = 0;
  local_80[0xc] = 0;
  local_80[0xd] = 0;
  local_80[0xe] = 0;
  local_80[0xf] = 0;
  piVar4 = (int *)param_1;
  uVar9 = param_2;
  do {
    local_80[*piVar4] = local_80[*piVar4] + 1;
    piVar4 = piVar4 + 1;
    uVar9 = uVar9 - 1;
  } while (uVar9 != 0);
  if (local_80[0] == param_2) {
    *param_6 = 0;
    *in_EAX = 0;
  }
  else {
    local_8 = *in_EAX;
    uVar5 = 1;
    uVar9 = 0xf;
    do {
      if (local_80[uVar5] != 0) break;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0x10);
    local_c = uVar5;
    if (*in_EAX < uVar5) {
      local_8 = uVar5;
    }
    do {
      if (local_80[uVar9] != 0) break;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    local_30 = uVar9;
    if (uVar9 < local_8) {
      local_8 = uVar9;
    }
    *in_EAX = local_8;
    iVar10 = 1 << ((byte)uVar5 & 0x1f);
    for (; uVar5 < uVar9; uVar5 = uVar5 + 1) {
      if ((int)(iVar10 - local_80[uVar5]) < 0) goto LAB_00961ba1;
      iVar10 = (iVar10 - local_80[uVar5]) * 2;
    }
    uVar5 = local_80[uVar9];
    iVar10 = iVar10 - uVar5;
    local_38 = iVar10;
    if (iVar10 < 0) {
LAB_00961ba1:
      uStack_10c = 0xfffffffd;
      goto LAB_00961a74;
    }
    local_80[uVar9] = uVar5 + iVar10;
    iVar6 = 0;
    iVar2 = uVar9 - 1;
    local_c0[1] = 0;
    if (iVar2 != 0) {
      iVar12 = 0;
      do {
        iVar6 = iVar6 + *(int *)((int)local_80 + iVar12 + 4);
        iVar2 = iVar2 + -1;
        *(int *)((int)local_c0 + iVar12 + 8) = iVar6;
        iVar12 = iVar12 + 4;
      } while (iVar2 != 0);
    }
    uVar5 = 0;
    do {
      iVar6 = local_38;
      iVar2 = *param_1;
      param_1 = param_1 + 1;
      if (iVar2 != 0) {
        uVar3 = local_c0[iVar2];
        param_9[uVar3] = uVar5;
        local_c0[iVar2] = uVar3 + 1;
        iVar10 = iVar6;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_2);
    uVar9 = local_c0[uVar9];
    local_10 = -1;
    param_1 = param_9;
    iVar2 = -local_8;
    local_24 = 0;
    local_c0[0] = 0;
    local_fc[0] = 0;
    local_2c = 0;
    local_14 = 0;
    if ((int)local_c <= (int)local_30) {
      local_34 = local_c - 1;
      local_28 = local_80 + local_c;
      do {
        local_20 = *local_28;
        if (local_20 != 0) {
          do {
            local_20 = local_20 - 1;
            local_3c = local_8 + iVar2;
            if (local_3c < (int)local_c) {
              local_80[0x10] = iVar2 - local_8;
              do {
                iVar10 = local_10;
                local_10 = local_10 + 1;
                iVar2 = iVar2 + local_8;
                local_80[0x10] = local_80[0x10] + local_8;
                local_3c = local_3c + local_8;
                uVar5 = local_30 - iVar2;
                if (local_8 < local_30 - iVar2) {
                  uVar5 = local_8;
                }
                uVar7 = local_c - iVar2;
                uVar3 = 1 << ((byte)uVar7 & 0x1f);
                if ((local_20 + 1 < uVar3) && (iVar6 = uVar3 + (-1 - local_20), uVar7 < uVar5)) {
                  uVar7 = uVar7 + 1;
                  puVar8 = local_28;
                  if (uVar7 < uVar5) {
                    while( true ) {
                      uVar3 = puVar8[1];
                      if ((uint)(iVar6 * 2) <= uVar3) break;
                      iVar6 = iVar6 * 2 - uVar3;
                      uVar7 = uVar7 + 1;
                      if (uVar5 <= uVar7) break;
                      puVar8 = puVar8 + 1;
                    }
                  }
                }
                local_14 = 1 << ((byte)uVar7 & 0x1f);
                uVar5 = *param_8 + local_14;
                if (0x5a0 < uVar5) goto LAB_00961ba1;
                local_2c = param_7 + *param_8 * 8;
                local_fc[local_10] = local_2c;
                uVar3 = local_24;
                *param_8 = uVar5;
                if (local_10 == 0) {
                  *param_6 = local_2c;
                }
                else {
                  local_c0[local_10] = local_24;
                  local_1c = CONCAT31(CONCAT21(local_1c._2_2_,(undefined1)local_8),(byte)uVar7);
                  uVar3 = uVar3 >> ((byte)local_80[0x10] & 0x1f);
                  iVar10 = local_fc[iVar10];
                  local_18 = (local_2c - iVar10 >> 3) - uVar3;
                  *(uint *)(iVar10 + uVar3 * 8) = local_1c;
                  *(uint *)(iVar10 + 4 + uVar3 * 8) = local_18;
                }
              } while (local_3c < (int)local_c);
              iVar10 = local_38;
            }
            bVar11 = (byte)iVar2;
            uVar1 = CONCAT21(local_1c._2_2_,(char)local_c - bVar11);
            if (param_1 < param_9 + uVar9) {
              local_18 = *param_1;
              if (local_18 < param_3) {
                local_1c = CONCAT31(uVar1,(local_18 < 0x100) + -1) & 0xffffff60;
              }
              else {
                iVar6 = (local_18 - param_3) * 4;
                local_1c = CONCAT31(uVar1,*(char *)(iVar6 + param_5) + 'P');
                local_18 = *(uint *)(iVar6 + param_4);
              }
              param_1 = param_1 + 1;
            }
            else {
              local_1c = CONCAT31(uVar1,0xc0);
            }
            iVar6 = 1 << ((char)local_c - bVar11 & 0x1f);
            uVar5 = local_24 >> (bVar11 & 0x1f);
            if (uVar5 < local_14) {
              puVar8 = (uint *)(local_2c + uVar5 * 8);
              do {
                *puVar8 = local_1c;
                puVar8[1] = local_18;
                uVar5 = uVar5 + iVar6;
                puVar8 = puVar8 + iVar6 * 2;
              } while (uVar5 < local_14);
              iVar10 = local_38;
            }
            uVar5 = 1 << ((byte)local_34 & 0x1f);
            while ((local_24 & uVar5) != 0) {
              local_24 = local_24 ^ uVar5;
              uVar5 = uVar5 >> 1;
            }
            local_24 = local_24 ^ uVar5;
            if (((1 << (bVar11 & 0x1f)) - 1U & local_24) != local_c0[local_10]) {
              do {
                iVar2 = iVar2 - local_8;
                local_10 = local_10 + -1;
              } while (((1 << ((byte)iVar2 & 0x1f)) - 1U & local_24) != local_c0[local_10]);
            }
          } while (local_20 != 0);
        }
        local_c = local_c + 1;
        local_28 = local_28 + 1;
        local_34 = local_34 + 1;
      } while ((int)local_c <= (int)local_30);
    }
    if ((iVar10 != 0) && (local_30 != 1)) {
      uStack_10c = 0xfffffffb;
      goto LAB_00961a74;
    }
  }
  uStack_10c = 0;
LAB_00961a74:
  return uStack_10c;
}


// ==== FUN_00961da2 @ 0x00961da2 ====

int FUN_00961da2(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = (**(code **)(param_5 + 0x20))(*(undefined4 *)(param_5 + 0x28),0x13,4);
  if (iVar1 == 0) {
    iVar2 = -4;
  }
  else {
    iVar2 = FUN_00961a0e(param_1,0x13,0x13,0,0,param_3,param_4,&local_8,iVar1);
    if (iVar2 == -3) {
      *(char **)(param_5 + 0x18) = s_oversubscribed_dynamic_bit_lengt_00a306c4;
    }
    else if ((iVar2 == -5) || (*param_2 == 0)) {
      *(char **)(param_5 + 0x18) = s_incomplete_dynamic_bit_lengths_t_00a306a0;
      iVar2 = -3;
    }
    (**(code **)(param_5 + 0x24))(*(undefined4 *)(param_5 + 0x28),iVar1);
  }
  return iVar2;
}


// ==== FUN_00961e1d @ 0x00961e1d ====

int FUN_00961e1d(uint param_1,undefined4 param_2,int param_3,int *param_4,int *param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = (**(code **)(param_9 + 0x20))(*(undefined4 *)(param_9 + 0x28),0x120,4);
  if (iVar1 == 0) {
    return -4;
  }
  iVar2 = FUN_00961a0e(param_3,param_1,0x101,&DAT_00a2f3a8,&DAT_00a2f428,param_6,param_8,&local_8,
                       iVar1);
  if (iVar2 == 0) {
    if (*param_4 == 0) goto LAB_00961efb;
    iVar2 = FUN_00961a0e(param_3 + param_1 * 4,param_2,0,&DAT_00a2f4a8,&DAT_00a2f520,param_7,param_8
                         ,&local_8,iVar1);
    if (iVar2 == 0) {
      if ((*param_5 != 0) || (param_1 < 0x102)) {
        iVar2 = 0;
        goto LAB_00961f07;
      }
LAB_00961edf:
      *(char **)(param_9 + 0x18) = s_empty_distance_tree_with_lengths_00a30730;
    }
    else {
      if (iVar2 == -3) {
        *(char **)(param_9 + 0x18) = s_oversubscribed_distance_tree_00a30770;
        goto LAB_00961f07;
      }
      if (iVar2 != -5) {
        if (iVar2 == -4) goto LAB_00961f07;
        goto LAB_00961edf;
      }
      *(char **)(param_9 + 0x18) = s_incomplete_distance_tree_00a30754;
    }
  }
  else {
    if (iVar2 == -3) {
      *(char **)(param_9 + 0x18) = s_oversubscribed_literal_length_tr_00a3070c;
      goto LAB_00961f07;
    }
    if (iVar2 == -4) goto LAB_00961f07;
LAB_00961efb:
    *(char **)(param_9 + 0x18) = s_incomplete_literal_length_tree_00a306ec;
  }
  iVar2 = -3;
LAB_00961f07:
  (**(code **)(param_9 + 0x24))(*(undefined4 *)(param_9 + 0x28),iVar1);
  return iVar2;
}


// ==== FUN_00961f19 @ 0x00961f19 ====

undefined4
FUN_00961f19(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_1 = 9;
  *param_2 = 5;
  *param_3 = &DAT_00a2f5a0;
  *param_4 = &DAT_00a305a0;
  return 0;
}


// ==== FUN_00961f48 @ 0x00961f48 ====

int FUN_00961f48(undefined1 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *local_c;
  uint local_8;
  
  iVar2 = (int)param_1;
  puVar1 = *(undefined4 **)((int)param_1 + 0x30);
  local_c = *(undefined4 **)(param_2 + 0xc);
  puVar6 = *(undefined4 **)((int)param_1 + 0x34);
  if (puVar6 < puVar1) {
    puVar6 = *(undefined4 **)((int)param_1 + 0x2c);
  }
  uVar5 = *(uint *)(param_2 + 0x10);
  local_8 = (int)puVar6 - (int)puVar1;
  if (uVar5 < (uint)((int)puVar6 - (int)puVar1)) {
    local_8 = uVar5;
  }
  if ((local_8 != 0) && (param_3 == -5)) {
    param_3 = 0;
  }
  *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + local_8;
  *(uint *)(param_2 + 0x10) = uVar5 - local_8;
  if (*(code **)((int)param_1 + 0x38) != (code *)0x0) {
    uVar4 = (**(code **)((int)param_1 + 0x38))(*(undefined4 *)((int)param_1 + 0x3c),puVar1,local_8);
    *(undefined4 *)((int)param_1 + 0x3c) = uVar4;
    *(undefined4 *)(param_2 + 0x30) = uVar4;
  }
  puVar6 = puVar1;
  puVar7 = local_c;
  for (uVar5 = local_8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  local_c = (undefined4 *)((int)local_c + local_8);
  for (uVar5 = local_8 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  puVar3 = (undefined1 *)((int)puVar1 + local_8);
  if ((undefined1 *)((int)puVar1 + local_8) == *(undefined1 **)((int)param_1 + 0x2c)) {
    puVar1 = *(undefined4 **)((int)param_1 + 0x28);
    if (*(undefined1 **)((int)param_1 + 0x34) == *(undefined1 **)((int)param_1 + 0x2c)) {
      *(undefined4 **)((int)param_1 + 0x34) = puVar1;
    }
    uVar5 = *(uint *)(param_2 + 0x10);
    local_8 = *(int *)((int)param_1 + 0x34) - (int)puVar1;
    if (uVar5 < local_8) {
      local_8 = uVar5;
    }
    if ((local_8 != 0) && (param_3 == -5)) {
      param_3 = 0;
    }
    *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + local_8;
    *(uint *)(param_2 + 0x10) = uVar5 - local_8;
    if (*(code **)((int)param_1 + 0x38) != (code *)0x0) {
      uVar4 = (**(code **)((int)param_1 + 0x38))
                        (*(undefined4 *)((int)param_1 + 0x3c),puVar1,local_8);
      *(undefined4 *)((int)param_1 + 0x3c) = uVar4;
      *(undefined4 *)(param_2 + 0x30) = uVar4;
    }
    puVar6 = puVar1;
    puVar7 = local_c;
    for (uVar5 = local_8 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    local_c = (undefined4 *)((int)local_c + local_8);
    for (uVar5 = local_8 & 3; puVar3 = (undefined1 *)((int)puVar1 + local_8), uVar5 != 0;
        uVar5 = uVar5 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
  }
  param_1 = puVar3;
  *(undefined4 **)(param_2 + 0xc) = local_c;
  *(undefined1 **)(iVar2 + 0x30) = param_1;
  return param_3;
}


// ==== FUN_0096205b @ 0x0096205b ====

undefined4 FUN_0096205b(uint param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  byte *pbVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  byte *local_14;
  byte *local_10;
  byte *local_c;
  uint local_8;
  
  piVar3 = param_6;
  local_10 = *(byte **)(param_5 + 0x34);
  uVar8 = *(uint *)(param_5 + 0x1c);
  local_c = (byte *)*param_6;
  local_8 = param_6[1];
  param_6 = *(int **)(param_5 + 0x20);
  if (local_10 < *(byte **)(param_5 + 0x30)) {
    local_14 = *(byte **)(param_5 + 0x30) + (-1 - (int)local_10);
  }
  else {
    local_14 = (byte *)(*(int *)(param_5 + 0x2c) - (int)local_10);
  }
  uVar7 = *(uint *)(&DAT_00a30790 + param_1 * 4);
  uVar6 = *(uint *)(&DAT_00a30790 + param_2 * 4);
  do {
    for (; uVar8 < 0x14; uVar8 = uVar8 + 8) {
      local_8 = local_8 - 1;
      param_6 = (int *)((uint)param_6 | (uint)*local_c << ((byte)uVar8 & 0x1f));
      local_c = local_c + 1;
    }
    pbVar12 = (byte *)(param_3 + (uVar7 & (uint)param_6) * 8);
    bVar1 = *pbVar12;
LAB_00962108:
    param_1 = (uint)bVar1;
    if (param_1 != 0) {
      param_6 = (int *)((uint)param_6 >> (pbVar12[1] & 0x1f));
      uVar8 = uVar8 - pbVar12[1];
      if ((bVar1 & 0x10) != 0) {
        param_1 = param_1 & 0xf;
        uVar10 = *(uint *)(&DAT_00a30790 + param_1 * 4) & (uint)param_6;
        param_6 = (int *)((uint)param_6 >> (sbyte)param_1);
        uVar10 = uVar10 + *(int *)(pbVar12 + 4);
        for (uVar8 = uVar8 - param_1; uVar8 < 0xf; uVar8 = uVar8 + 8) {
          local_8 = local_8 - 1;
          param_6 = (int *)((uint)param_6 | (uint)*local_c << ((byte)uVar8 & 0x1f));
          local_c = local_c + 1;
        }
        pbVar12 = (byte *)(param_4 + (uVar6 & (uint)param_6) * 8);
        param_6 = (int *)((uint)param_6 >> (pbVar12[1] & 0x1f));
        uVar8 = uVar8 - pbVar12[1];
        while( true ) {
          bVar1 = *pbVar12;
          if ((bVar1 & 0x10) != 0) {
            uVar9 = bVar1 & 0xf;
            for (; uVar8 < uVar9; uVar8 = uVar8 + 8) {
              local_8 = local_8 - 1;
              param_6 = (int *)((uint)param_6 | (uint)*local_c << ((byte)uVar8 & 0x1f));
              local_c = local_c + 1;
            }
            uVar11 = *(uint *)(&DAT_00a30790 + uVar9 * 4) & (uint)param_6;
            param_6 = (int *)((uint)param_6 >> (sbyte)uVar9);
            local_14 = local_14 + -uVar10;
            uVar8 = uVar8 - uVar9;
            pbVar4 = local_10 + -(uVar11 + *(int *)(pbVar12 + 4));
            pbVar12 = *(byte **)(param_5 + 0x28);
            if (pbVar4 < pbVar12) {
              do {
                pbVar4 = pbVar4 + (*(int *)(param_5 + 0x2c) - (int)pbVar12);
              } while (pbVar4 < pbVar12);
              uVar9 = *(int *)(param_5 + 0x2c) - (int)pbVar4;
              if (uVar9 < uVar10) {
                param_1 = uVar10 - uVar9;
                do {
                  *local_10 = *pbVar4;
                  local_10 = local_10 + 1;
                  pbVar4 = pbVar4 + 1;
                  uVar9 = uVar9 - 1;
                } while (uVar9 != 0);
                pbVar12 = *(byte **)(param_5 + 0x28);
                do {
                  *local_10 = *pbVar12;
                  local_10 = local_10 + 1;
                  pbVar12 = pbVar12 + 1;
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
              else {
                *local_10 = *pbVar4;
                local_10[1] = pbVar4[1];
                local_10 = local_10 + 2;
                pbVar4 = pbVar4 + 2;
                param_1 = uVar10 - 2;
                do {
                  *local_10 = *pbVar4;
                  local_10 = local_10 + 1;
                  pbVar4 = pbVar4 + 1;
                  param_1 = param_1 + -1;
                } while (param_1 != 0);
              }
            }
            else {
              *local_10 = *pbVar4;
              local_10[1] = pbVar4[1];
              local_10 = local_10 + 2;
              pbVar4 = pbVar4 + 2;
              param_1 = uVar10 - 2;
              do {
                *local_10 = *pbVar4;
                local_10 = local_10 + 1;
                pbVar4 = pbVar4 + 1;
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
            goto LAB_00962278;
          }
          if ((bVar1 & 0x40) != 0) break;
          pbVar12 = pbVar12 + ((*(uint *)(&DAT_00a30790 + (uint)bVar1 * 4) & (uint)param_6) +
                              *(int *)(pbVar12 + 4)) * 8;
          param_6 = (int *)((uint)param_6 >> (pbVar12[1] & 0x1f));
          uVar8 = uVar8 - pbVar12[1];
        }
        piVar3[6] = (int)(s_5_invalid_distance_code_00a2f33e + 2);
        uVar7 = piVar3[1] - local_8;
        if (uVar8 >> 3 < piVar3[1] - local_8) {
          uVar7 = uVar8 >> 3;
        }
LAB_009622e8:
        uVar5 = 0xfffffffd;
        goto LAB_009622eb;
      }
      if ((bVar1 & 0x40) == 0) break;
      uVar6 = uVar8 >> 3;
      if ((bVar1 & 0x20) == 0) {
        uVar7 = piVar3[1] - local_8;
        piVar3[6] = (int)s_invalid_literal_length_code_00a2f358;
        if (uVar6 < uVar7) {
          uVar7 = uVar6;
        }
        goto LAB_009622e8;
      }
      uVar7 = piVar3[1] - local_8;
      if (uVar6 < uVar7) {
        uVar7 = uVar6;
      }
      uVar5 = 1;
      goto LAB_009622eb;
    }
    param_6 = (int *)((uint)param_6 >> (pbVar12[1] & 0x1f));
    uVar8 = uVar8 - pbVar12[1];
    local_14 = local_14 + -1;
    *local_10 = pbVar12[4];
    local_10 = local_10 + 1;
LAB_00962278:
    if ((local_14 < (byte *)0x102) || (local_8 < 10)) {
      uVar7 = piVar3[1] - local_8;
      if (uVar8 >> 3 < piVar3[1] - local_8) {
        uVar7 = uVar8 >> 3;
      }
      uVar5 = 0;
LAB_009622eb:
      *(int **)(param_5 + 0x20) = param_6;
      *(uint *)(param_5 + 0x1c) = uVar8 + uVar7 * -8;
      piVar3[1] = uVar7 + local_8;
      iVar2 = *piVar3;
      *piVar3 = (int)local_c - uVar7;
      piVar3[2] = piVar3[2] + (((int)local_c - uVar7) - iVar2);
      *(byte **)(param_5 + 0x34) = local_10;
      return uVar5;
    }
  } while( true );
  pbVar12 = pbVar12 + ((*(uint *)(&DAT_00a30790 + param_1 * 4) & (uint)param_6) +
                      *(int *)(pbVar12 + 4)) * 8;
  bVar1 = *pbVar12;
  goto LAB_00962108;
}


// ==== FUN_0096231f @ 0x0096231f ====
/* DECOMPILE FAILED: Exception while decompiling 0096231f: process: timeout
 */

