// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x8f0000-0x8fffff

// ==== FUN_008f0186 @ 0x008f0186 ====

void FUN_008f0186(uint *param_1,byte *param_2,int param_3,uint param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  uint uVar7;
  uint local_8;
  
  iVar4 = (int)param_2;
  puVar3 = param_1;
  uVar2 = *param_1;
  if ((char)param_1[2] == '\x03') {
    bVar1 = *(byte *)((int)param_1 + 9);
    if (bVar1 < 8) {
      local_8 = uVar2;
      if (bVar1 == 1) {
        param_1 = (uint *)(7 - (uVar2 - 1 & 7));
        pbVar6 = (byte *)((uVar2 - 1 >> 3) + (int)param_2);
        if (uVar2 != 0) {
          param_2 = (byte *)((uVar2 - 1) + (int)param_2);
          do {
            *param_2 = *pbVar6 >> ((byte)param_1 & 0x1f) & 1;
            if (param_1 == (uint *)0x7) {
              param_1 = (uint *)0x0;
              pbVar6 = pbVar6 + -1;
            }
            else {
              param_1 = (uint *)((int)param_1 + 1);
            }
            param_2 = param_2 + -1;
            local_8 = local_8 - 1;
          } while (local_8 != 0);
        }
      }
      else if (bVar1 == 2) {
        param_1 = (uint *)((3 - (uVar2 - 1 & 3)) * 2);
        pbVar6 = (byte *)((uVar2 - 1 >> 2) + (int)param_2);
        if (uVar2 != 0) {
          param_2 = (byte *)((uVar2 - 1) + (int)param_2);
          do {
            *param_2 = *pbVar6 >> ((byte)param_1 & 0x1f) & 3;
            if (param_1 == (uint *)0x6) {
              param_1 = (uint *)0x0;
              pbVar6 = pbVar6 + -1;
            }
            else {
              param_1 = (uint *)((int)param_1 + 2);
            }
            param_2 = param_2 + -1;
            local_8 = local_8 - 1;
          } while (local_8 != 0);
        }
      }
      else if (bVar1 == 4) {
        param_1 = (uint *)((uVar2 & 1) << 2);
        pbVar6 = (byte *)((uVar2 - 1 >> 1) + (int)param_2);
        if (uVar2 != 0) {
          param_2 = (byte *)((uVar2 - 1) + (int)param_2);
          do {
            *param_2 = *pbVar6 >> ((byte)param_1 & 0x1f) & 0xf;
            if (param_1 == (uint *)0x4) {
              param_1 = (uint *)0x0;
              pbVar6 = pbVar6 + -1;
            }
            else {
              param_1 = (uint *)((int)param_1 + 4);
            }
            param_2 = param_2 + -1;
            local_8 = local_8 - 1;
          } while (local_8 != 0);
        }
      }
      *(undefined1 *)((int)puVar3 + 9) = 8;
      *(undefined1 *)((int)puVar3 + 0xb) = 8;
      puVar3[1] = uVar2;
    }
    if (*(char *)((int)puVar3 + 9) == '\b') {
      pbVar6 = (byte *)((uVar2 - 1) + iVar4);
      if (param_4 == 0) {
        uVar7 = uVar2 * 3;
        puVar5 = (undefined1 *)((uVar7 - 1) + iVar4);
        if (uVar2 != 0) {
          param_4 = uVar2;
          do {
            *puVar5 = *(undefined1 *)((uint)*pbVar6 * 3 + 2 + param_3);
            puVar5[-1] = *(undefined1 *)((uint)*pbVar6 * 3 + 1 + param_3);
            puVar5[-2] = *(undefined1 *)(param_3 + (uint)*pbVar6 * 3);
            puVar5 = puVar5 + -3;
            pbVar6 = pbVar6 + -1;
            param_4 = param_4 - 1;
          } while (param_4 != 0);
        }
        *(undefined1 *)((int)puVar3 + 0xb) = 0x18;
        *(undefined1 *)(puVar3 + 2) = 2;
        *(undefined1 *)((int)puVar3 + 10) = 3;
      }
      else {
        uVar7 = uVar2 * 4;
        puVar5 = (undefined1 *)((uVar7 - 1) + iVar4);
        if (uVar2 != 0) {
          param_1 = (uint *)uVar2;
          do {
            if ((int)(uint)*pbVar6 < param_5) {
              *puVar5 = *(undefined1 *)(*pbVar6 + param_4);
            }
            else {
              *puVar5 = 0xff;
            }
            puVar5[-1] = *(undefined1 *)((uint)*pbVar6 * 3 + 2 + param_3);
            puVar5[-2] = *(undefined1 *)((uint)*pbVar6 * 3 + 1 + param_3);
            puVar5[-3] = *(undefined1 *)(param_3 + (uint)*pbVar6 * 3);
            puVar5 = puVar5 + -4;
            pbVar6 = pbVar6 + -1;
            param_1 = (uint *)((int)param_1 - 1);
          } while (param_1 != (uint *)0x0);
        }
        *(undefined1 *)((int)puVar3 + 0xb) = 0x20;
        *(undefined1 *)(puVar3 + 2) = 6;
        *(undefined1 *)((int)puVar3 + 10) = 4;
      }
      *(undefined1 *)((int)puVar3 + 9) = 8;
      puVar3[1] = uVar7;
    }
  }
  return;
}


// ==== FUN_008f0391 @ 0x008f0391 ====

void FUN_008f0391(byte *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  ushort uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int local_c;
  
  iVar4 = param_3;
  iVar6 = param_2;
  piVar2 = (int *)param_1;
  iVar1 = *(int *)param_1;
  if ((char)*(int *)((int)param_1 + 8) == '\0') {
    uVar7 = 0;
    if (param_3 != 0) {
      uVar7 = *(ushort *)(param_3 + 8);
    }
    bVar3 = *(byte *)((int)param_1 + 9);
    if (bVar3 < 8) {
      local_c = iVar1;
      if (bVar3 == 1) {
        uVar7 = uVar7 * 0xff;
        param_1 = (byte *)(iVar1 + -1 + param_2);
        pbVar5 = (byte *)((iVar1 - 1U >> 3) + param_2);
        if (iVar1 != 0) {
          param_2 = 7 - (iVar1 - 1U & 7);
          do {
            *param_1 = -((*pbVar5 >> ((byte)param_2 & 0x1f) & 1) != 0);
            if (param_2 == 7) {
              param_2 = 0;
              pbVar5 = pbVar5 + -1;
            }
            else {
              param_2 = param_2 + 1;
            }
            param_1 = param_1 + -1;
            local_c = local_c + -1;
          } while (local_c != 0);
        }
      }
      else if (bVar3 == 2) {
        uVar7 = uVar7 * 0x55;
        param_1 = (byte *)(iVar1 + -1 + param_2);
        pbVar5 = (byte *)((iVar1 - 1U >> 2) + param_2);
        if (iVar1 != 0) {
          param_2 = (3 - (iVar1 - 1U & 3)) * 2;
          do {
            bVar3 = *pbVar5 >> ((byte)param_2 & 0x1f) & 3;
            *param_1 = ((bVar3 << 2 | bVar3) << 2 | bVar3) << 2 | bVar3;
            if (param_2 == 6) {
              param_2 = 0;
              pbVar5 = pbVar5 + -1;
            }
            else {
              param_2 = param_2 + 2;
            }
            param_1 = param_1 + -1;
            local_c = local_c + -1;
          } while (local_c != 0);
        }
      }
      else if (bVar3 == 4) {
        uVar7 = uVar7 * 0x11;
        param_1 = (byte *)(iVar1 + -1 + param_2);
        pbVar5 = (byte *)((iVar1 - 1U >> 1) + param_2);
        if (iVar1 != 0) {
          param_2 = (iVar1 - 1U & 1) * -4 + 4;
          do {
            bVar3 = *pbVar5 >> ((byte)param_2 & 0x1f);
            *param_1 = bVar3 << 4 | bVar3 & 0xf;
            iVar4 = 4;
            if (param_2 == 4) {
              iVar4 = 0;
              pbVar5 = pbVar5 + -1;
            }
            param_1 = param_1 + -1;
            local_c = local_c + -1;
            param_2 = iVar4;
          } while (local_c != 0);
        }
      }
      *(undefined1 *)((int)piVar2 + 9) = 8;
      *(undefined1 *)((int)piVar2 + 0xb) = 8;
      piVar2[1] = iVar1;
    }
    if (param_3 == 0) {
      return;
    }
    if (*(char *)((int)piVar2 + 9) == '\b') {
      pbVar5 = (byte *)(iVar1 + -1 + iVar6);
      puVar8 = (undefined1 *)(iVar6 + -1 + iVar1 * 2);
      if (iVar1 != 0) {
        iVar6 = iVar1;
        do {
          if (*pbVar5 == uVar7) {
            *puVar8 = 0;
          }
          else {
            *puVar8 = 0xff;
          }
          puVar8[-1] = *pbVar5;
          puVar8 = puVar8 + -2;
          pbVar5 = pbVar5 + -1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
    }
    else if (*(char *)((int)piVar2 + 9) == '\x10') {
      puVar8 = (undefined1 *)(piVar2[1] + -1 + iVar6);
      puVar9 = (undefined1 *)(iVar6 + -1 + piVar2[1] * 2);
      if (iVar1 != 0) {
        param_3 = iVar1;
        do {
          if (CONCAT11(puVar8[-1],*puVar8) == uVar7) {
            *puVar9 = 0;
            puVar9[-1] = 0;
          }
          else {
            *puVar9 = 0xff;
            puVar9[-1] = 0xff;
          }
          puVar9[-2] = *puVar8;
          puVar9[-3] = puVar8[-1];
          puVar9 = puVar9 + -4;
          puVar8 = puVar8 + -2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    *(undefined1 *)(piVar2 + 2) = 4;
    *(undefined1 *)((int)piVar2 + 10) = 2;
    bVar3 = *(char *)((int)piVar2 + 9) << 1;
  }
  else {
    if ((char)*(int *)((int)param_1 + 8) != '\x02') {
      return;
    }
    if (param_3 == 0) {
      return;
    }
    if (*(char *)((int)param_1 + 9) == '\b') {
      pbVar5 = (byte *)(*(int *)((int)param_1 + 4) + -1 + param_2);
      puVar8 = (undefined1 *)(param_2 + -1 + iVar1 * 4);
      if (iVar1 != 0) {
        param_3 = iVar1;
        do {
          if ((((ushort)pbVar5[-2] == *(ushort *)(iVar4 + 2)) &&
              ((ushort)pbVar5[-1] == *(ushort *)(iVar4 + 4))) &&
             ((ushort)*pbVar5 == *(ushort *)(iVar4 + 6))) {
            *puVar8 = 0;
          }
          else {
            *puVar8 = 0xff;
          }
          puVar8[-1] = *pbVar5;
          puVar8[-2] = pbVar5[-1];
          puVar8[-3] = pbVar5[-2];
          puVar8 = puVar8 + -4;
          pbVar5 = pbVar5 + -3;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    else if (*(char *)((int)param_1 + 9) == '\x10') {
      puVar8 = (undefined1 *)(*(int *)((int)param_1 + 4) + -1 + param_2);
      puVar9 = (undefined1 *)(param_2 + -1 + iVar1 * 8);
      if (iVar1 != 0) {
        param_2 = iVar1;
        do {
          if (((CONCAT11(puVar8[-5],puVar8[-4]) == *(short *)(param_3 + 2)) &&
              (CONCAT11(puVar8[-3],puVar8[-2]) == *(short *)(param_3 + 4))) &&
             (CONCAT11(puVar8[-1],*puVar8) == *(short *)(param_3 + 6))) {
            *puVar9 = 0;
            puVar9[-1] = 0;
          }
          else {
            *puVar9 = 0xff;
            puVar9[-1] = 0xff;
          }
          puVar9[-2] = *puVar8;
          puVar9[-3] = puVar8[-1];
          puVar9[-4] = puVar8[-2];
          puVar9[-5] = puVar8[-3];
          puVar9[-6] = puVar8[-4];
          puVar9[-7] = puVar8[-5];
          puVar9 = puVar9 + -8;
          puVar8 = puVar8 + -6;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
    *(undefined1 *)((int)param_1 + 8) = 6;
    *(undefined1 *)((int)param_1 + 10) = 4;
    bVar3 = *(char *)((int)param_1 + 9) << 2;
  }
  *(byte *)((int)piVar2 + 0xb) = bVar3;
  piVar2[1] = (uint)bVar3 * iVar1 >> 3;
  return;
}


// ==== FUN_008f06ea @ 0x008f06ea ====

void FUN_008f06ea(int *param_1,byte *param_2,int param_3,int param_4)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  piVar3 = param_1;
  cVar1 = (char)param_1[2];
  iVar4 = *param_1;
  if (((cVar1 == '\x02') && (param_3 != 0)) && (*(char *)((int)param_1 + 9) == '\b')) {
    if (iVar4 != 0) {
      pbVar7 = param_2;
      param_1 = (int *)iVar4;
      do {
        bVar2 = *pbVar7;
        pbVar5 = pbVar7 + 1;
        pbVar6 = pbVar7 + 2;
        pbVar7 = pbVar7 + 3;
        param_1 = (int *)((int)param_1 + -1);
        *param_2 = *(byte *)((((bVar2 & 0xf8) << 5 | *pbVar5 & 0xf8) << 2 | (int)(uint)*pbVar6 >> 3)
                            + param_3);
        param_2 = param_2 + 1;
      } while (param_1 != (int *)0x0);
    }
  }
  else {
    if (((cVar1 != '\x06') || (param_3 == 0)) || (*(char *)((int)param_1 + 9) != '\b')) {
      if (cVar1 != '\x03') {
        return;
      }
      if (param_4 == 0) {
        return;
      }
      if (*(char *)((int)param_1 + 9) != '\b') {
        return;
      }
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        *param_2 = *(byte *)((uint)*param_2 + param_4);
        param_2 = param_2 + 1;
      }
      return;
    }
    if (iVar4 != 0) {
      pbVar7 = param_2;
      param_1 = (int *)iVar4;
      do {
        bVar2 = *pbVar7;
        pbVar5 = pbVar7 + 1;
        pbVar6 = pbVar7 + 2;
        pbVar7 = pbVar7 + 4;
        param_1 = (int *)((int)param_1 + -1);
        *param_2 = *(byte *)((((bVar2 & 0xf8) << 5 | *pbVar5 & 0xf8) << 2 | (int)(uint)*pbVar6 >> 3)
                            + param_3);
        param_2 = param_2 + 1;
      } while (param_1 != (int *)0x0);
    }
  }
  *(byte *)((int)piVar3 + 0xb) = *(byte *)((int)piVar3 + 9);
  *(undefined1 *)(piVar3 + 2) = 3;
  *(undefined1 *)((int)piVar3 + 10) = 1;
  piVar3[1] = (uint)*(byte *)((int)piVar3 + 9) * iVar4 + 7 >> 3;
  return;
}


// ==== FUN_008f07fb @ 0x008f07fb ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f07fb(uint param_1)

{
  ushort *puVar1;
  byte bVar2;
  int iVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  ushort local_10;
  uint local_8;
  
  iVar3 = param_1;
  if ((float)_DAT_0099d098 != *(float *)(param_1 + 0x130)) {
    if (*(byte *)(param_1 + 0x117) < 9) {
      uVar6 = FUN_0090c9a9(param_1,0x100);
      param_1 = 0;
      *(undefined4 *)(iVar3 + 0x138) = uVar6;
      do {
        FUN_00801f40();
        uVar4 = __ftol();
        iVar10 = param_1 + 1;
        *(undefined1 *)(param_1 + *(int *)(iVar3 + 0x138)) = uVar4;
        param_1 = iVar10;
      } while (iVar10 < 0x100);
    }
    else {
      if ((*(byte *)(param_1 + 0x116) & 2) == 0) {
        local_8 = (uint)*(byte *)(param_1 + 0x153);
      }
      else {
        local_8 = (uint)*(byte *)(param_1 + 0x150);
        if ((uint)*(byte *)(param_1 + 0x150) < (uint)*(byte *)(param_1 + 0x151)) {
          local_8 = (uint)*(byte *)(param_1 + 0x151);
        }
        if (local_8 < *(byte *)(param_1 + 0x152)) {
          local_8 = (uint)*(byte *)(param_1 + 0x152);
        }
      }
      if (local_8 == 0) {
        local_8 = 0;
      }
      else {
        local_8 = 0x10 - local_8;
      }
      if (((*(byte *)(param_1 + 0x61) & 4) != 0) && ((int)local_8 < 5)) {
        local_8 = 5;
      }
      if (8 < (int)local_8) {
        local_8 = 8;
      }
      if ((int)local_8 < 0) {
        local_8 = 0;
      }
      bVar2 = (byte)local_8;
      bVar9 = 8 - bVar2;
      iVar10 = 1 << (bVar9 & 0x1f);
      *(uint *)(param_1 + 300) = local_8 & 0xff;
      uVar6 = FUN_0090c9a9(param_1,iVar10 << 2);
      puVar1 = (ushort *)(param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x144) = uVar6;
      param_1 = 0;
      if ((*puVar1 & 0x480) == 0) {
        if (0 < iVar10) {
          do {
            uVar6 = FUN_0090c9a9(iVar3,0x200);
            *(undefined4 *)(*(int *)(iVar3 + 0x144) + param_1 * 4) = uVar6;
            iVar12 = 0;
            do {
              FUN_00801f40();
              uVar5 = __ftol();
              *(undefined2 *)(iVar12 + *(int *)(*(int *)(iVar3 + 0x144) + param_1 * 4)) = uVar5;
              iVar12 = iVar12 + 2;
            } while (iVar12 < 0x200);
            param_1 = param_1 + 1;
          } while ((int)param_1 < iVar10);
        }
      }
      else {
        if (0 < iVar10) {
          do {
            uVar6 = FUN_0090c9a9(iVar3,0x200);
            iVar12 = param_1 + 1;
            *(undefined4 *)(*(int *)(iVar3 + 0x144) + param_1 * 4) = uVar6;
            param_1 = iVar12;
          } while (iVar12 < iVar10);
        }
        uVar13 = 0;
        param_1 = 0;
        do {
          FUN_00801f40();
          uVar7 = __ftol();
          if (uVar13 <= uVar7) {
            local_10 = (ushort)((param_1 & 0xff) << 8) | (ushort)param_1;
            do {
              uVar11 = uVar13 >> (bVar9 & 0x1f);
              uVar8 = 0xff >> (bVar2 & 0x1f) & uVar13;
              uVar13 = uVar13 + 1;
              *(ushort *)(*(int *)(*(int *)(iVar3 + 0x144) + uVar8 * 4) + uVar11 * 2) = local_10;
            } while (uVar13 <= uVar7);
          }
          param_1 = param_1 + 1;
        } while ((int)param_1 < 0x100);
        if (uVar13 < (uint)(iVar10 << 8)) {
          do {
            *(undefined2 *)
             (*(int *)(*(int *)(iVar3 + 0x144) + (0xff >> (bVar2 & 0x1f) & uVar13) * 4) +
             (uVar13 >> (bVar9 & 0x1f)) * 2) = 0xffff;
            uVar13 = uVar13 + 1;
          } while (uVar13 < (uint)(iVar10 << 8));
        }
      }
    }
  }
  return;
}


// ==== FUN_008f0b02 @ 0x008f0b02 ====

void FUN_008f0b02(int param_1)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_8;
  
  iVar2 = param_1;
  cVar1 = *(char *)(param_1 + 0x116);
  if ((*(uint *)(param_1 + 0x60) & 0x602000) != 0) {
    FUN_008f07fb(param_1);
    if (cVar1 == '\x03') {
      uVar5 = (uint)*(ushort *)(param_1 + 0x108);
      if (uVar5 != 0) {
        pbVar3 = (byte *)(*(int *)(param_1 + 0x104) + 2);
        do {
          pbVar3[-2] = *(byte *)((uint)pbVar3[-2] + *(int *)(param_1 + 0x138));
          pbVar3[-1] = *(byte *)((uint)pbVar3[-1] + *(int *)(param_1 + 0x138));
          *pbVar3 = *(byte *)((uint)*pbVar3 + *(int *)(param_1 + 0x138));
          pbVar3 = pbVar3 + 3;
          uVar5 = uVar5 - 1;
        } while (uVar5 != 0);
      }
    }
  }
  if (((*(byte *)(param_1 + 0x60) & 8) != 0) && (cVar1 == '\x03')) {
    pbVar3 = (byte *)(param_1 + 0x152);
    iVar6 = 8 - (uint)*(byte *)(param_1 + 0x150);
    param_1 = 8 - (uint)*(byte *)(param_1 + 0x151);
    local_8 = 8 - (uint)*pbVar3;
    if ((iVar6 < 0) || (8 < iVar6)) {
      iVar6 = 0;
    }
    if ((param_1 < 0) || (8 < param_1)) {
      param_1 = 0;
    }
    if ((local_8 < 0) || (8 < local_8)) {
      local_8 = 0;
    }
    if (*(ushort *)(iVar2 + 0x108) != 0) {
      iVar4 = 0;
      uVar5 = (uint)*(ushort *)(iVar2 + 0x108);
      do {
        pbVar3 = (byte *)(iVar4 + *(int *)(iVar2 + 0x104));
        *pbVar3 = *pbVar3 >> ((byte)iVar6 & 0x1f);
        pbVar3 = (byte *)(iVar4 + 1 + *(int *)(iVar2 + 0x104));
        *pbVar3 = *pbVar3 >> ((byte)param_1 & 0x1f);
        pbVar3 = (byte *)(iVar4 + 2 + *(int *)(iVar2 + 0x104));
        *pbVar3 = *pbVar3 >> ((byte)local_8 & 0x1f);
        iVar4 = iVar4 + 3;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
    }
  }
  return;
}


// ==== FUN_008f0c18 @ 0x008f0c18 ====

void FUN_008f0c18(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xdc) == 0) {
    FUN_008ee0f5(param_1,s_NULL_row_buffer_00a24ec4);
  }
  if ((*(byte *)(param_1 + 0x61) & 0x10) != 0) {
    if (*(char *)(param_1 + 0xf8) == '\x03') {
      FUN_008f0186(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1,*(undefined4 *)(param_1 + 0x104),
                   *(undefined4 *)(param_1 + 0x15c),*(undefined2 *)(param_1 + 0x10a));
    }
    else {
      if (*(short *)(param_1 + 0x10a) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = param_1 + 0x160;
      }
      FUN_008f0391(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1,iVar1);
    }
  }
  if (((*(byte *)(param_1 + 0x61) & 0x20) != 0) && (*(char *)(param_1 + 0x116) != '\x03')) {
    FUN_008efe34(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1,*(undefined4 *)(param_1 + 0x138),
                 *(undefined4 *)(param_1 + 0x144),*(undefined4 *)(param_1 + 300));
  }
  if ((*(byte *)(param_1 + 0x61) & 4) != 0) {
    FUN_008efbb5(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1);
  }
  if ((*(byte *)(param_1 + 0x60) & 0x40) != 0) {
    FUN_008f06ea(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1,*(undefined4 *)(param_1 + 0x174),
                 *(undefined4 *)(param_1 + 0x178));
    if (*(int *)(param_1 + 0xf4) == 0) {
      FUN_008ee0f5(param_1,s_p_png_do_dither_returned_rowbyte_00a24e9e + 2);
    }
  }
  if ((*(byte *)(param_1 + 0x60) & 8) != 0) {
    FUN_008efa37(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1,param_1 + 0x155);
  }
  if ((*(byte *)(param_1 + 0x60) & 4) != 0) {
    FUN_008ef924(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1);
  }
  if ((*(byte *)(param_1 + 0x60) & 1) != 0) {
    FUN_008ef72d(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1);
  }
  if ((*(byte *)(param_1 + 0x61) & 0x80) != 0) {
    FUN_008efbff(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1,*(undefined2 *)(param_1 + 0x11e),
                 *(undefined4 *)(param_1 + 0x5c));
  }
  if ((*(byte *)(param_1 + 0x60) & 0x10) != 0) {
    FUN_008ef6fa(param_1 + 0xf0,*(int *)(param_1 + 0xdc) + 1);
  }
  return;
}


// ==== FUN_008f0db9 @ 0x008f0db9 ====

void FUN_008f0db9(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(code **)(param_1 + 0x50) == (code *)0x0) {
    FUN_008ee0f5(param_1,s_Call_to_NULL_read_function_00a24ed4);
  }
  else {
    (**(code **)(param_1 + 0x50))(param_1,param_2,param_3);
  }
  return;
}


// ==== FUN_008f0de5 @ 0x008f0de5 ====

void FUN_008f0de5(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x54) = param_2;
  *(undefined4 *)(param_1 + 0x50) = param_3;
  if (*(int *)(param_1 + 0x4c) != 0) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    FUN_008ee116(param_1,s_It_s_an_error_to_set_both_read_d_00a24f28);
    FUN_008ee116(param_1,s_same_structure__Resetting_write__00a24ef0);
  }
  *(undefined4 *)(param_1 + 0x120) = 0;
  return;
}


// ==== FUN_008f0e26 @ 0x008f0e26 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f0e26(void)

{
  float fVar1;
  float *in_EAX;
  uint in_ECX;
  
  fVar1 = _DAT_00a171a8;
  *in_EAX = (float)(in_ECX >> 0xb & 0x1f) * _DAT_00a171a8;
  in_EAX[1] = (float)(in_ECX >> 5 & 0x3f) * _DAT_00a171a4;
  in_EAX[2] = (float)(in_ECX & 0x1f) * fVar1;
  in_EAX[3] = 1.0;
  return;
}


// ==== FUN_008f0e74 @ 0x008f0e74 ====

undefined4 FUN_008f0e74(void)

{
  float fVar1;
  float fVar2;
  float *in_ECX;
  int iVar3;
  
  iVar3 = 0x10;
  do {
    if (DAT_0099cdc8 == in_ECX[3]) {
      *in_ECX = 0.0;
      in_ECX[1] = 0.0;
      fVar1 = 0.0;
LAB_008f0eec:
      in_ECX[2] = fVar1;
    }
    else if (in_ECX[3] < 1.0) {
      fVar1 = 1.0 / in_ECX[3];
      if (in_ECX[3] <= *in_ECX) {
        fVar2 = 1.0;
      }
      else {
        fVar2 = fVar1 * *in_ECX;
      }
      *in_ECX = fVar2;
      if (in_ECX[3] <= in_ECX[1]) {
        fVar2 = 1.0;
      }
      else {
        fVar2 = fVar1 * in_ECX[1];
      }
      in_ECX[1] = fVar2;
      if (in_ECX[3] <= in_ECX[2]) {
        fVar1 = 1.0;
      }
      else {
        fVar1 = fVar1 * in_ECX[2];
      }
      goto LAB_008f0eec;
    }
    in_ECX = in_ECX + 4;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0;
    }
  } while( true );
}


// ==== FUN_008f0ef8 @ 0x008f0ef8 ====

undefined4 FUN_008f0ef8(void)

{
  float *in_EAX;
  float *in_ECX;
  int iVar1;
  
  iVar1 = 0x10;
  do {
    *in_ECX = in_EAX[3] * *in_EAX;
    iVar1 = iVar1 + -1;
    in_ECX[1] = in_EAX[1] * in_EAX[3];
    in_ECX[2] = in_EAX[2] * in_EAX[3];
    in_ECX[3] = in_EAX[3];
    in_EAX = in_EAX + 4;
    in_ECX = in_ECX + 4;
  } while (iVar1 != 0);
  return 0;
}


// ==== FUN_008f0f28 @ 0x008f0f28 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_008f0f28(void)

{
  float *in_ECX;
  float local_20;
  float local_1c;
  float local_18;
  
  if (DAT_0099cdc8 <= *in_ECX) {
    if (DAT_0099d080 < *in_ECX) {
      local_20 = 1.0;
    }
    else {
      local_20 = *in_ECX;
    }
  }
  else {
    local_20 = 0.0;
  }
  if (DAT_0099cdc8 <= in_ECX[1]) {
    if (DAT_0099d080 < in_ECX[1]) {
      local_1c = 1.0;
    }
    else {
      local_1c = in_ECX[1];
    }
  }
  else {
    local_1c = 0.0;
  }
  if (DAT_0099cdc8 <= in_ECX[2]) {
    if (in_ECX[2] <= DAT_0099d080) {
      local_18 = in_ECX[2];
    }
    else {
      local_18 = 1.0;
    }
  }
  else {
    local_18 = 0.0;
  }
  return ((int)ROUND(local_20 * _DAT_00a171ac + DAT_0099d0b4) << 6 |
         (int)ROUND(local_1c * DAT_00a10a2c + DAT_0099d0b4)) << 5 |
         (int)ROUND(local_18 * _DAT_00a171ac + DAT_0099d0b4);
}


// ==== FUN_008f102b @ 0x008f102b ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f102b(float *param_1,float *param_2,int param_3,uint param_4)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  undefined2 in_FPUControlWord;
  float local_58 [6];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  float local_30;
  float local_2c;
  float local_28;
  uint local_24;
  undefined4 *local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (param_4 == 6) {
    pfVar6 = (float *)&DAT_00a25044;
    local_20 = &DAT_00a2502c;
  }
  else {
    pfVar6 = (float *)&DAT_00a2500c;
    local_20 = (undefined4 *)&DAT_00a24fec;
  }
  uVar4 = 0;
  local_8 = 1.0;
  local_c = 0.0;
  if (param_4 == 8) {
    do {
      pfVar3 = (float *)(param_3 + uVar4 * 4);
      if (*pfVar3 < local_8) {
        local_8 = *pfVar3;
      }
      if (local_c < *pfVar3) {
        local_c = *pfVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
  }
  else {
    do {
      pfVar3 = (float *)(param_3 + uVar4 * 4);
      if ((*pfVar3 < local_8) && (DAT_0099cdc8 < *pfVar3)) {
        local_8 = *pfVar3;
      }
      if ((local_c < *pfVar3) && (*pfVar3 < DAT_0099d080)) {
        local_c = *pfVar3;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    if (local_8 == local_c) {
      local_c = 1.0;
    }
  }
  uVar4 = param_4 - 1;
  local_28 = (float)(int)uVar4;
  if ((int)uVar4 < 0) {
    local_28 = local_28 + _DAT_0099d104;
  }
  local_24 = CONCAT22(local_24._2_2_,in_FPUControlWord);
  local_38 = local_24;
  local_24 = 0;
  while (_DAT_009ae954 <= local_c - local_8) {
    local_2c = local_28 / (local_c - local_8);
    if (param_4 != 0) {
      iVar5 = (int)local_20 - (int)pfVar6;
      pfVar3 = pfVar6;
      uVar7 = param_4;
      do {
        *(float *)(((int)local_58 - (int)pfVar6) + (int)pfVar3) =
             local_8 * *pfVar3 + local_c * *(float *)(iVar5 + (int)pfVar3);
        pfVar3 = pfVar3 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    if (param_4 == 6) {
      local_40 = 0;
      local_3c = 0x3f800000;
    }
    uVar7 = 0;
    local_10 = 0.0;
    local_14 = 0.0;
    local_18 = 0.0;
    local_1c = 0.0;
    do {
      pfVar3 = (float *)(param_3 + uVar7 * 4);
      fVar1 = (*pfVar3 - local_8) * local_2c;
      if ((NAN(fVar1) || NAN(DAT_0099cdc8)) || fVar1 < DAT_0099cdc8 == (fVar1 == DAT_0099cdc8)) {
        if (fVar1 < local_28) {
          local_30 = fVar1 + DAT_0099d0b4;
          local_34 = (uint)ROUND(fVar1 + DAT_0099d0b4);
        }
        else {
          if (param_4 == 6) {
            fVar2 = (local_c + DAT_0099d080) * DAT_0099d0b4;
            fVar1 = *pfVar3;
            if ((!NAN(fVar2) && !NAN(fVar1)) && fVar2 < fVar1 != (fVar2 == fVar1))
            goto LAB_008f1256;
          }
          local_34 = uVar4;
        }
LAB_008f1214:
        if (local_34 < param_4) {
          local_10 = (*pfVar3 - local_58[local_34]) * pfVar6[local_34] + local_10;
          local_18 = pfVar6[local_34] * pfVar6[local_34] + local_18;
          local_14 = (*pfVar3 - local_58[local_34]) * (float)local_20[local_34] + local_14;
          fVar1 = (float)local_20[local_34];
          local_1c = fVar1 * fVar1 + local_1c;
        }
      }
      else if ((param_4 != 6) || (local_8 * DAT_0099d0b4 < *pfVar3)) {
        local_34 = 0;
        goto LAB_008f1214;
      }
LAB_008f1256:
      uVar7 = uVar7 + 1;
    } while (uVar7 < 0x10);
    if (DAT_0099cdc8 < local_18) {
      local_8 = local_8 - local_10 / local_18;
    }
    if (DAT_0099cdc8 < local_1c) {
      local_c = local_c - local_14 / local_1c;
    }
    fVar1 = local_c;
    if (local_c < local_8) {
      local_c = local_8;
      local_8 = fVar1;
    }
    if (((local_10 * local_10 < _DAT_00a176b0) && (local_14 * local_14 < _DAT_00a176b0)) ||
       (local_24 = local_24 + 1, 7 < local_24)) break;
  }
  if (DAT_0099cdc8 <= local_8) {
    if (DAT_0099d080 < local_8) {
      local_8 = 1.0;
    }
  }
  else {
    local_8 = 0.0;
  }
  *param_1 = local_8;
  if (DAT_0099cdc8 <= local_c) {
    if (DAT_0099d080 < local_c) {
      local_c = 1.0;
    }
  }
  else {
    local_c = 0.0;
  }
  *param_2 = local_c;
  return;
}


// ==== FUN_008f1352 @ 0x008f1352 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f1352(float *param_1,float *param_2,float param_3,float param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  float *pfVar17;
  undefined2 in_FPUControlWord;
  float local_c4 [16];
  int local_84;
  float *local_80;
  undefined4 local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 *local_68;
  uint local_64;
  float local_60;
  float *local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_44;
  float local_40;
  float local_3c;
  float local_34 [6];
  float local_1c;
  float local_14;
  float local_10;
  float local_c;
  undefined4 uStack_8;
  
  iVar10 = (int)param_4;
  if (param_4 == 4.2039e-45) {
    local_5c = (float *)&DAT_00a25090;
    local_68 = &DAT_00a25084;
  }
  else {
    local_5c = (float *)&DAT_00a25074;
    local_68 = (undefined4 *)&DAT_00a25064;
  }
  local_34[4] = 0.0;
  local_34[5] = 0.0;
  local_14 = DAT_00b590a8;
  local_10 = DAT_00b590ac;
  local_1c = 0.0;
  local_c = DAT_00b590b0;
  uStack_8 = DAT_00b590b4;
  pfVar17 = (float *)((int)param_3 + 8);
  iVar11 = 0x10;
  local_80 = pfVar17;
  pfVar12 = pfVar17;
  iVar13 = iVar11;
  do {
    if (pfVar12[-2] < local_14) {
      local_14 = pfVar12[-2];
    }
    if (pfVar12[-1] < local_10) {
      local_10 = pfVar12[-1];
    }
    fVar3 = local_10;
    if (*pfVar12 < local_c) {
      local_c = *pfVar12;
    }
    if (local_34[4] < pfVar12[-2]) {
      local_34[4] = pfVar12[-2];
    }
    if (local_34[5] < pfVar12[-1]) {
      local_34[5] = pfVar12[-1];
    }
    if (local_1c < *pfVar12) {
      local_1c = *pfVar12;
    }
    fVar9 = local_1c;
    pfVar12 = pfVar12 + 4;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  fVar5 = local_34[4] - local_14;
  fVar7 = local_34[5] - local_10;
  fVar4 = local_1c - local_c;
  local_58 = fVar5 * fVar5 + fVar7 * fVar7 + fVar4 * fVar4;
  if (_DAT_009fc7a4 <= local_58) {
    fVar8 = 1.0 / local_58;
    local_78 = fVar5 * fVar8;
    local_74 = fVar7 * fVar8;
    local_70 = fVar8 * fVar4;
    local_54 = (local_34[4] + local_14) * DAT_0099d0b4;
    local_50 = (local_34[5] + local_10) * DAT_0099d0b4;
    local_4c = (local_1c + local_c) * DAT_0099d0b4;
    local_34[3] = 0.0;
    local_34[2] = 0.0;
    local_34[1] = 0.0;
    local_34[0] = 0.0;
    do {
      local_44 = (pfVar17[-2] - local_54) * fVar5 * fVar8;
      local_40 = (pfVar17[-1] - local_50) * fVar7 * fVar8;
      fVar2 = *pfVar17;
      pfVar17 = pfVar17 + 4;
      iVar11 = iVar11 + -1;
      fVar2 = (fVar2 - local_4c) * fVar8 * fVar4;
      fVar6 = local_40 + fVar2 + local_44;
      local_34[0] = fVar6 * fVar6 + local_34[0];
      fVar6 = (local_40 + local_44) - fVar2;
      local_34[1] = fVar6 * fVar6 + local_34[1];
      fVar6 = (local_44 - local_40) + fVar2;
      local_34[2] = fVar6 * fVar6 + local_34[2];
      fVar2 = (local_44 - local_40) - fVar2;
      local_34[3] = fVar2 * fVar2 + local_34[3];
    } while (iVar11 != 0);
    uVar16 = 0;
    uVar14 = 1;
    do {
      if (local_34[0] < local_34[uVar14]) {
        local_34[0] = local_34[uVar14];
        uVar16 = uVar14;
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < 4);
    if ((uVar16 & 2) != 0) {
      local_10 = local_34[5];
      local_34[5] = fVar3;
    }
    if ((uVar16 & 1) != 0) {
      local_1c = local_c;
      local_c = fVar9;
    }
    if (_DAT_00a25060 <= local_58) {
      iVar11 = (int)param_4 + -1;
      local_58 = (float)iVar11;
      if (iVar11 < 0) {
        local_58 = local_58 + _DAT_0099d104;
      }
      param_4 = (float)CONCAT22((short)((uint)iVar11 >> 0x10),in_FPUControlWord);
      local_64 = 0;
      local_7c = param_4;
      while( true ) {
        iVar11 = 0x10;
        if (iVar10 != 0) {
          pfVar12 = local_c4 + 1;
          iVar15 = (int)local_68 - (int)local_5c;
          pfVar17 = local_5c;
          iVar13 = iVar10;
          do {
            pfVar12[-1] = local_34[4] * *(float *)(iVar15 + (int)pfVar17) + local_14 * *pfVar17;
            *pfVar12 = local_34[5] * *(float *)(iVar15 + (int)pfVar17) + local_10 * *pfVar17;
            fVar3 = *pfVar17;
            pfVar1 = (float *)(iVar15 + (int)pfVar17);
            pfVar17 = pfVar17 + 1;
            pfVar12[1] = local_1c * *pfVar1 + local_c * fVar3;
            pfVar12 = pfVar12 + 4;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
        }
        fVar9 = local_34[4] - local_14;
        fVar3 = local_34[5] - local_10;
        fVar7 = local_1c - local_c;
        fVar5 = fVar9 * fVar9 + fVar3 * fVar3 + fVar7 * fVar7;
        if (fVar5 < _DAT_00a25060) break;
        fVar5 = local_58 / fVar5;
        local_44 = fVar5 * fVar9;
        local_40 = fVar3 * fVar5;
        local_3c = fVar5 * fVar7;
        local_34[2] = 0.0;
        local_34[1] = 0.0;
        local_34[0] = 0.0;
        local_4c = 0.0;
        local_50 = 0.0;
        local_54 = 0.0;
        param_3 = 0.0;
        param_4 = 0.0;
        pfVar12 = local_80;
        do {
          fVar4 = (*pfVar12 - local_c) * fVar5 * fVar7 +
                  (pfVar12[-2] - local_14) * fVar5 * fVar9 +
                  (pfVar12[-1] - local_10) * fVar3 * fVar5;
          local_60 = fVar4;
          if (fVar4 < local_58) {
            local_60 = fVar4 + DAT_0099d0b4;
            local_84 = (int)ROUND(fVar4 + DAT_0099d0b4);
          }
          else {
            local_84 = iVar10 + -1;
          }
          pfVar17 = pfVar12 + -2;
          local_74 = local_c4[local_84 * 4 + 1] - pfVar12[-1];
          fVar4 = *pfVar12;
          fVar2 = local_5c[local_84] * _DAT_009b0e90;
          pfVar12 = pfVar12 + 4;
          iVar11 = iVar11 + -1;
          fVar8 = (float)local_68[local_84] * _DAT_009b0e90;
          param_4 = fVar2 * local_5c[local_84] + param_4;
          local_54 = fVar2 * (local_c4[local_84 * 4] - *pfVar17) + local_54;
          local_50 = fVar2 * local_74 + local_50;
          local_4c = fVar2 * (local_c4[local_84 * 4 + 2] - fVar4) + local_4c;
          param_3 = fVar8 * (float)local_68[local_84] + param_3;
          local_34[0] = fVar8 * (local_c4[local_84 * 4] - *pfVar17) + local_34[0];
          local_34[1] = local_74 * fVar8 + local_34[1];
          local_34[2] = fVar8 * (local_c4[local_84 * 4 + 2] - fVar4) + local_34[2];
        } while (iVar11 != 0);
        if (DAT_0099cdc8 < param_4) {
          param_4 = DAT_0099d0dc / param_4;
          local_14 = local_54 * param_4 + local_14;
          local_10 = local_50 * param_4 + local_10;
          local_c = param_4 * local_4c + local_c;
        }
        if (DAT_0099cdc8 < param_3) {
          param_3 = DAT_0099d0dc / param_3;
          local_34[4] = local_34[0] * param_3 + local_34[4];
          local_34[5] = local_34[1] * param_3 + local_34[5];
          local_1c = param_3 * local_34[2] + local_1c;
        }
        if (((((local_54 * local_54 < _DAT_00a2505c) && (local_50 * local_50 < _DAT_00a2505c)) &&
             (local_4c * local_4c < _DAT_00a2505c)) &&
            (((local_34[0] * local_34[0] < _DAT_00a2505c &&
              (local_34[1] * local_34[1] < _DAT_00a2505c)) &&
             (local_34[2] * local_34[2] < _DAT_00a2505c)))) ||
           (local_64 = local_64 + 1, 7 < local_64)) break;
      }
      *param_1 = local_14;
      param_1[1] = local_10;
      param_1[2] = local_c;
      *param_2 = local_34[4];
      param_2[1] = local_34[5];
    }
    else {
      *param_1 = local_14;
      param_1[1] = local_10;
      param_1[2] = local_c;
      param_2[1] = local_34[5];
      *param_2 = local_34[4];
    }
  }
  else {
    *param_1 = local_14;
    param_1[1] = local_10;
    param_1[2] = local_c;
    param_2[1] = local_34[5];
    *param_2 = local_34[4];
  }
  param_2[2] = local_1c;
  return;
}


// ==== FUN_008f18d2 @ 0x008f18d2 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008f18d2(ushort *param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_EAX;
  float *pfVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  ushort uVar10;
  uint uVar11;
  uint uVar12;
  ushort uVar13;
  int iVar14;
  undefined2 in_FPUControlWord;
  undefined2 uVar15;
  float local_2e0;
  float local_2dc [63];
  float local_1e0;
  float local_1dc;
  undefined1 local_1d8 [4];
  undefined1 local_1d4 [4];
  undefined1 local_1d0 [4];
  undefined1 local_1cc [20];
  undefined1 local_1b8 [4];
  undefined1 local_1b4 [4];
  undefined1 local_1b0 [4];
  undefined1 local_1ac [4];
  undefined1 local_1a8 [4];
  float local_1a4;
  float local_1a0 [2];
  undefined1 local_198 [4];
  undefined1 local_194 [4];
  undefined1 local_190 [4];
  undefined1 local_18c [172];
  undefined1 *local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  int local_cc;
  int local_c8;
  int local_c4;
  undefined1 *local_c0;
  undefined1 *local_bc;
  int local_b8;
  undefined1 *local_b4;
  undefined1 *local_b0;
  undefined1 *local_ac;
  float local_a8 [4];
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  undefined1 *local_68;
  undefined1 *local_64;
  undefined1 *local_60;
  undefined4 local_5c;
  undefined1 *local_58;
  float local_54;
  float local_50;
  float local_4c;
  float fStack_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined1 *local_34;
  float local_30;
  undefined1 *local_2c;
  int local_28;
  undefined1 *local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float fStack_10;
  float *local_c;
  undefined *local_8;
  
  if (param_2 == 0.0) {
    local_28 = 4;
  }
  else {
    iVar8 = 0;
    pfVar5 = (float *)(in_EAX + 0xc);
    iVar14 = 0x10;
    do {
      if (*pfVar5 < DAT_0099d0b4) {
        iVar8 = iVar8 + 1;
      }
      pfVar5 = pfVar5 + 4;
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    if (iVar8 == 0x10) {
      param_1[1] = 0xffff;
      param_1[2] = 0xffff;
      param_1[3] = 0xffff;
      *param_1 = 0;
      return 0;
    }
    local_28 = 4 - (uint)(iVar8 != 0);
  }
  if (param_3 != 0) {
    pfVar5 = &local_1e0;
    for (iVar14 = 0x40; iVar14 != 0; iVar14 = iVar14 + -1) {
      *pfVar5 = 0.0;
      pfVar5 = pfVar5 + 1;
    }
  }
  param_2 = (float)CONCAT22(param_2._2_2_,in_FPUControlWord);
  local_b8 = (int)local_2dc + (0xfc - in_EAX);
  local_64 = (undefined1 *)((int)local_2dc - in_EAX);
  local_58 = local_1d8 + -in_EAX;
  local_c0 = local_1d4 + -in_EAX;
  local_b4 = local_1d0 + -in_EAX;
  local_60 = local_1b8 + -in_EAX;
  local_bc = local_1b4 + -in_EAX;
  local_b0 = local_1b0 + -in_EAX;
  local_2c = local_1a8 + -in_EAX;
  local_24 = local_198 + -in_EAX;
  local_ac = local_194 + -in_EAX;
  local_34 = local_190 + -in_EAX;
  puVar9 = local_1a8 + (4 - in_EAX);
  iVar14 = (int)local_1a0 - in_EAX;
  local_5c = param_2;
  local_30 = (float)((int)local_2dc + (-4 - in_EAX));
  param_2 = 0.0;
  pfVar5 = (float *)(in_EAX + 8);
  local_e0 = puVar9;
  local_c8 = iVar14;
  uVar12 = 0;
  do {
    local_1c = pfVar5[-2];
    local_18 = pfVar5[-1];
    local_14 = *pfVar5;
    if (param_3 != 0) {
      local_1c = pfVar5[-2] + *(float *)((int)local_2dc + uVar12 + 0xfc);
      local_18 = pfVar5[-1] + *(float *)(local_1d8 + (uVar12 - 4));
      local_14 = *pfVar5 + *(float *)(local_b8 + (int)pfVar5);
    }
    local_cc = (int)ROUND(local_1c * _DAT_00a171ac + DAT_0099d0b4);
    fVar1 = (float)local_cc * _DAT_00a171a8;
    local_20 = fVar1;
    *(float *)((int)local_2dc + (uVar12 - 4)) = fVar1;
    local_c4 = (int)ROUND(local_18 * DAT_00a10a2c + DAT_0099d0b4);
    fVar2 = (float)local_c4 * _DAT_00a171a4;
    local_8 = (undefined *)fVar2;
    *(float *)((int)local_2dc + uVar12) = fVar2;
    local_68 = (undefined1 *)(int)ROUND(local_14 * _DAT_00a171ac + DAT_0099d0b4);
    local_c = (float *)local_68;
    fVar3 = (float)(int)local_68 * _DAT_00a171a8;
    *(float *)((int)local_30 + (int)pfVar5) = fVar3;
    *(undefined4 *)((int)local_64 + (int)pfVar5) = 0x3f800000;
    if (param_3 != 0) {
      fVar1 = local_1c - fVar1;
      uVar11 = (uint)param_2 & 3;
      fVar2 = local_18 - fVar2;
      local_c = (float *)uVar11;
      local_40 = fVar2;
      fVar4 = local_14 - fVar3;
      local_3c = fVar4;
      if (uVar11 != 3) {
        *(float *)(local_58 + (int)pfVar5) =
             fVar1 * _DAT_00a250bc + *(float *)(local_58 + (int)pfVar5);
        *(float *)(local_c0 + (int)pfVar5) =
             fVar2 * _DAT_00a250bc + *(float *)(local_c0 + (int)pfVar5);
        *(float *)(local_b4 + (int)pfVar5) =
             fVar4 * _DAT_00a250bc + *(float *)(local_b4 + (int)pfVar5);
      }
      if (uVar12 < 0xc0) {
        if (uVar11 != 0) {
          *(float *)(local_60 + (int)pfVar5) =
               fVar1 * _DAT_00a171c4 + *(float *)(local_60 + (int)pfVar5);
          *(float *)(local_bc + (int)pfVar5) =
               fVar2 * _DAT_00a171c4 + *(float *)(local_bc + (int)pfVar5);
          *(float *)(local_b0 + (int)pfVar5) =
               fVar4 * _DAT_00a171c4 + *(float *)(local_b0 + (int)pfVar5);
        }
        *(float *)(local_2c + (int)pfVar5) =
             fVar1 * _DAT_00a171c0 + *(float *)(local_2c + (int)pfVar5);
        *(float *)(puVar9 + (int)pfVar5) = fVar2 * _DAT_00a171c0 + *(float *)(puVar9 + (int)pfVar5);
        *(float *)(iVar14 + (int)pfVar5) = fVar4 * _DAT_00a171c0 + *(float *)(iVar14 + (int)pfVar5);
        if (uVar11 != 3) {
          *(float *)(local_24 + (int)pfVar5) =
               fVar1 * DAT_009af898 + *(float *)(local_24 + (int)pfVar5);
          *(float *)(local_ac + (int)pfVar5) =
               local_40 * DAT_009af898 + *(float *)(local_ac + (int)pfVar5);
          *(float *)(local_34 + (int)pfVar5) =
               local_3c * DAT_009af898 + *(float *)(local_34 + (int)pfVar5);
        }
      }
    }
    param_2 = (float)((int)param_2 + 1);
    uVar11 = uVar12 + 0x10;
    *(float *)((int)local_2dc + (uVar12 - 4)) = local_20 * DAT_00b590a8;
    *(float *)((int)local_2dc + uVar12) = (float)local_8 * DAT_00b590ac;
    *(float *)((int)local_30 + (int)pfVar5) = fVar3 * DAT_00b590b0;
    pfVar5 = pfVar5 + 4;
    uVar12 = uVar11;
  } while (uVar11 < 0x100);
  uVar15 = (undefined2)local_5c;
  FUN_008f1352(&local_1c,&local_54,&local_2e0,local_28);
  local_dc = local_1c * _DAT_00b590b8;
  local_d8 = local_18 * _DAT_00b590bc;
  local_d4 = local_14 * _DAT_00b590c0;
  local_44 = local_54 * _DAT_00b590b8;
  local_40 = local_50 * _DAT_00b590bc;
  local_3c = local_4c * _DAT_00b590c0;
  uVar6 = FUN_008f0f28();
  local_2c = (undefined1 *)uVar6;
  local_24 = (undefined1 *)FUN_008f0f28();
  uVar10 = (ushort)uVar6;
  uVar13 = (ushort)local_24;
  if ((local_28 == 4) && (uVar10 == uVar13)) {
    param_1[2] = 0;
    param_1[3] = 0;
    *param_1 = uVar10;
    param_1[1] = uVar13;
  }
  else {
    FUN_008f0e26();
    FUN_008f0e26();
    local_1c = local_dc * DAT_00b590a8;
    local_18 = local_d8 * DAT_00b590ac;
    local_14 = local_d4 * DAT_00b590b0;
    local_54 = local_44 * DAT_00b590a8;
    local_50 = local_40 * DAT_00b590ac;
    local_4c = local_3c * DAT_00b590b0;
    if ((local_28 == 3) == uVar10 <= uVar13) {
      *param_1 = uVar10;
      param_1[1] = uVar13;
      local_a8[0] = local_1c;
      local_a8[1] = local_18;
      local_a8[2] = local_14;
      local_a8[3] = fStack_10;
      pfVar5 = &local_54;
    }
    else {
      param_1[1] = uVar10;
      *param_1 = uVar13;
      local_a8[0] = local_54;
      local_a8[1] = local_50;
      local_a8[2] = local_4c;
      local_a8[3] = fStack_48;
      pfVar5 = &local_1c;
    }
    local_98 = *pfVar5;
    local_94 = pfVar5[1];
    local_90 = pfVar5[2];
    local_8c = pfVar5[3];
    fVar1 = *pfVar5 - local_a8[0];
    if (local_28 == 3) {
      local_8 = &DAT_00a250b0;
      local_88 = DAT_0099d0b4 * fVar1 + local_a8[0];
      local_84 = (local_94 - local_a8[1]) * DAT_0099d0b4 + local_a8[1];
      local_80 = (local_90 - local_a8[2]) * DAT_0099d0b4 + local_a8[2];
      local_7c = (local_8c - local_a8[3]) * DAT_0099d0b4 + local_a8[3];
    }
    else {
      local_8 = &DAT_00a250a0;
      local_88 = _DAT_009fc7c8 * fVar1 + local_a8[0];
      local_84 = _DAT_009fc7c8 * (local_94 - local_a8[1]) + local_a8[1];
      local_80 = _DAT_009fc7c8 * (local_90 - local_a8[2]) + local_a8[2];
      local_7c = _DAT_009fc7c8 * (local_8c - local_a8[3]) + local_a8[3];
      local_78 = fVar1 * _DAT_00a2509c + local_a8[0];
      local_74 = (local_94 - local_a8[1]) * _DAT_00a2509c + local_a8[1];
      local_70 = (local_90 - local_a8[2]) * _DAT_00a2509c + local_a8[2];
      local_6c = (local_8c - local_a8[3]) * _DAT_00a2509c + local_a8[3];
    }
    local_94 = local_94 - local_a8[1];
    param_2 = local_90 - local_a8[2];
    iVar14 = local_28 + -1;
    local_30 = (float)iVar14;
    if (iVar14 < 0) {
      local_30 = local_30 + _DAT_0099d104;
    }
    if ((short)local_2c == (short)local_24) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = local_30 / (fVar1 * fVar1 + local_94 * local_94 + param_2 * param_2);
    }
    local_20 = 0.0;
    local_54 = fVar1 * fVar2;
    local_50 = fVar2 * local_94;
    local_4c = fVar2 * param_2;
    if (param_3 != 0) {
      pfVar5 = &local_1e0;
      for (iVar8 = 0x40; iVar8 != 0; iVar8 = iVar8 + -1) {
        *pfVar5 = 0.0;
        pfVar5 = pfVar5 + 1;
      }
    }
    param_2._2_2_ = (undefined2)((uint)iVar14 >> 0x10);
    param_2 = (float)CONCAT22(param_2._2_2_,uVar15);
    local_5c = param_2;
    local_c = &local_1e0;
    local_58 = local_1cc + -in_EAX;
    param_2 = 0.0;
    local_64 = local_1ac + -in_EAX;
    iVar14 = (int)local_2dc + (4 - in_EAX);
    iVar8 = (int)local_1a0 + (4 - in_EAX);
    pfVar5 = (float *)(in_EAX + 4);
    local_24 = local_1d8 + (-4 - in_EAX);
    local_68 = local_18c + -in_EAX;
    do {
      if ((local_28 != 3) || (DAT_0099d0b4 <= pfVar5[2])) {
        local_1c = DAT_00b590a8 * pfVar5[-1];
        local_18 = DAT_00b590ac * *pfVar5;
        local_14 = DAT_00b590b0 * pfVar5[1];
        if (param_3 != 0) {
          local_1c = DAT_00b590a8 * pfVar5[-1] + *local_c;
          local_18 = DAT_00b590ac * *pfVar5 + *(float *)((int)pfVar5 + local_b8);
          local_14 = DAT_00b590b0 * pfVar5[1] + *(float *)(local_24 + (int)pfVar5);
        }
        fVar1 = (local_1c - local_a8[0]) * local_54 +
                (local_18 - local_a8[1]) * local_50 + (local_14 - local_a8[2]) * local_4c;
        if ((NAN(fVar1) || NAN(DAT_0099cdc8)) || fVar1 < DAT_0099cdc8 == (fVar1 == DAT_0099cdc8)) {
          if (fVar1 < local_30) {
            local_2c = (undefined1 *)(fVar1 + DAT_0099d0b4);
            local_60 = (undefined1 *)(int)ROUND(fVar1 + DAT_0099d0b4);
            iVar7 = *(int *)(local_8 + (int)local_60 * 4);
          }
          else {
            iVar7 = 1;
          }
        }
        else {
          iVar7 = 0;
        }
        local_20 = (float)(iVar7 << 0x1e | (uint)local_20 >> 2);
        if (param_3 != 0) {
          uVar12 = (uint)param_2 & 3;
          fVar2 = (local_1c - local_a8[iVar7 * 4]) * *(float *)(iVar14 + (int)pfVar5);
          fVar3 = (local_18 - local_a8[iVar7 * 4 + 1]) * *(float *)(iVar14 + (int)pfVar5);
          local_40 = fVar3;
          fVar1 = (local_14 - local_a8[iVar7 * 4 + 2]) * *(float *)(iVar14 + (int)pfVar5);
          local_3c = fVar1;
          if (uVar12 != 3) {
            *(float *)(local_c0 + (int)pfVar5) =
                 fVar2 * _DAT_00a250bc + *(float *)(local_c0 + (int)pfVar5);
            *(float *)(local_b4 + (int)pfVar5) =
                 _DAT_00a250bc * fVar3 + *(float *)(local_b4 + (int)pfVar5);
            *(float *)(local_58 + (int)pfVar5) =
                 fVar1 * _DAT_00a250bc + *(float *)(local_58 + (int)pfVar5);
          }
          if ((uint)param_2 < 0xc) {
            if (uVar12 != 0) {
              *(float *)(local_bc + (int)pfVar5) =
                   fVar2 * _DAT_00a171c4 + *(float *)(local_bc + (int)pfVar5);
              *(float *)(local_b0 + (int)pfVar5) =
                   _DAT_00a171c4 * fVar3 + *(float *)(local_b0 + (int)pfVar5);
              *(float *)(local_64 + (int)pfVar5) =
                   fVar1 * _DAT_00a171c4 + *(float *)(local_64 + (int)pfVar5);
            }
            *(float *)(local_e0 + (int)pfVar5) =
                 fVar2 * _DAT_00a171c0 + *(float *)(local_e0 + (int)pfVar5);
            *(float *)(local_c8 + (int)pfVar5) =
                 fVar3 * _DAT_00a171c0 + *(float *)(local_c8 + (int)pfVar5);
            *(float *)(iVar8 + (int)pfVar5) =
                 fVar1 * _DAT_00a171c0 + *(float *)(iVar8 + (int)pfVar5);
            if (uVar12 != 3) {
              *(float *)(local_ac + (int)pfVar5) =
                   fVar2 * DAT_009af898 + *(float *)(local_ac + (int)pfVar5);
              *(float *)(local_34 + (int)pfVar5) =
                   local_40 * DAT_009af898 + *(float *)(local_34 + (int)pfVar5);
              *(float *)(local_68 + (int)pfVar5) =
                   local_3c * DAT_009af898 + *(float *)(local_68 + (int)pfVar5);
            }
          }
        }
      }
      else {
        local_20 = (float)((uint)local_20 >> 2 | 0xc0000000);
      }
      param_2 = (float)((int)param_2 + 1);
      local_c = local_c + 4;
      pfVar5 = pfVar5 + 4;
    } while ((uint)param_2 < 0x10);
    *(float *)(param_1 + 2) = local_20;
  }
  return 0;
}


// ==== FUN_008f2225 @ 0x008f2225 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008f2225(float *param_1,ushort *param_2)

{
  float *pfVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  float local_5c [4];
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  float local_8;
  
  uVar2 = *param_2;
  FUN_008f0e26();
  uVar3 = param_2[1];
  FUN_008f0e26();
  if (uVar3 < uVar2) {
    local_3c = (local_4c - local_5c[0]) * _DAT_009fc7c8 + local_5c[0];
    local_38 = (local_48 - local_5c[1]) * _DAT_009fc7c8 + local_5c[1];
    local_8 = local_44 - local_5c[2];
    local_34 = local_8 * _DAT_009fc7c8 + local_5c[2];
    local_c = local_40 - local_5c[3];
    local_30 = local_c * _DAT_009fc7c8 + local_5c[3];
    local_2c = (local_4c - local_5c[0]) * _DAT_00a2509c + local_5c[0];
    local_28 = (local_48 - local_5c[1]) * _DAT_00a2509c + local_5c[1];
    local_24 = local_8 * _DAT_00a2509c + local_5c[2];
    local_20 = local_c * _DAT_00a2509c + local_5c[3];
  }
  else {
    local_3c = (local_4c - local_5c[0]) * DAT_0099d0b4 + local_5c[0];
    local_38 = (local_48 - local_5c[1]) * DAT_0099d0b4 + local_5c[1];
    local_34 = (local_44 - local_5c[2]) * DAT_0099d0b4 + local_5c[2];
    local_30 = (local_40 - local_5c[3]) * DAT_0099d0b4 + local_5c[3];
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_2c = 0.0;
    local_28 = 0.0;
    local_24 = 0.0;
    local_20 = 0.0;
  }
  uVar6 = *(uint *)(param_2 + 2);
  iVar4 = 0x10;
  do {
    uVar5 = uVar6 & 3;
    *param_1 = local_5c[uVar5 * 4];
    param_1[1] = local_5c[uVar5 * 4 + 1];
    pfVar1 = param_1 + 3;
    param_1[2] = local_5c[uVar5 * 4 + 2];
    param_1 = param_1 + 4;
    uVar6 = uVar6 >> 2;
    iVar4 = iVar4 + -1;
    *pfVar1 = local_5c[uVar5 * 4 + 3];
  } while (iVar4 != 0);
  return 0;
}


// ==== FUN_008f2367 @ 0x008f2367 ====

/* WARNING: Removing unreachable block (ram,0x008f23a0) */
/* WARNING: Removing unreachable block (ram,0x008f23cf) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008f2367(int param_1,uint *param_2)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = FUN_008f2225(param_1,param_2 + 2);
  fVar1 = _DAT_00a171c8;
  if (-1 < iVar2) {
    uVar4 = *param_2;
    iVar2 = 8;
    pfVar3 = (float *)(param_1 + 0xc);
    do {
      uVar5 = uVar4 & 0xf;
      uVar4 = uVar4 >> 4;
      *pfVar3 = (float)uVar5 * fVar1;
      pfVar3 = pfVar3 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar4 = param_2[1];
    iVar2 = 8;
    pfVar3 = (float *)(param_1 + 0x8c);
    do {
      uVar5 = uVar4 & 0xf;
      uVar4 = uVar4 >> 4;
      *pfVar3 = (float)uVar5 * fVar1;
      pfVar3 = pfVar3 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_008f23ec @ 0x008f23ec ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008f23ec(int param_1,byte *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  uint uVar6;
  float local_24 [8];
  
  iVar3 = FUN_008f2225(param_1,param_2 + 8);
  if (-1 < iVar3) {
    local_24[0] = (float)*param_2 * DAT_0099d0b0;
    local_24[1] = (float)param_2[1] * DAT_0099d0b0;
    if (param_2[1] < *param_2) {
      uVar4 = 1;
      do {
        fVar1 = (float)(int)(7 - uVar4);
        if ((int)(7 - uVar4) < 0) {
          fVar1 = fVar1 + _DAT_0099d104;
        }
        fVar2 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        uVar4 = uVar4 + 1;
        local_24[uVar4] = (fVar2 * local_24[1] + fVar1 * local_24[0]) * _DAT_00a171cc;
      } while (uVar4 < 7);
    }
    else {
      uVar4 = 1;
      do {
        fVar1 = (float)(int)(5 - uVar4);
        if ((int)(5 - uVar4) < 0) {
          fVar1 = fVar1 + _DAT_0099d104;
        }
        fVar2 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        uVar4 = uVar4 + 1;
        local_24[uVar4] = (fVar2 * local_24[1] + fVar1 * local_24[0]) * DAT_009b02a8;
      } while (uVar4 < 5);
      local_24[6] = 0.0;
      local_24[7] = 1.0;
    }
    iVar3 = 8;
    uVar4 = (uint)*(uint3 *)(param_2 + 2);
    pfVar5 = (float *)(param_1 + 0xc);
    do {
      uVar6 = uVar4 & 7;
      uVar4 = uVar4 >> 3;
      *pfVar5 = local_24[uVar6];
      pfVar5 = pfVar5 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 8;
    uVar4 = (uint)*(uint3 *)(param_2 + 5);
    pfVar5 = (float *)(param_1 + 0x8c);
    do {
      uVar6 = uVar4 & 7;
      uVar4 = uVar4 >> 3;
      *pfVar5 = local_24[uVar6];
      pfVar5 = pfVar5 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 0;
  }
  return iVar3;
}


// ==== FUN_008f252a @ 0x008f252a ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008f252a(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  undefined2 in_FPUControlWord;
  float local_150 [64];
  float local_50 [16];
  uint local_10;
  uint local_c;
  float local_8;
  
  if (param_3 != 0) {
    pfVar4 = local_50;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar4 = 0.0;
      pfVar4 = pfVar4 + 1;
    }
    local_8 = (float)CONCAT22(local_8._2_2_,in_FPUControlWord);
    local_c = (uint)local_8 | 0xc00;
    local_10 = (uint)local_8;
    uVar7 = 0;
    pfVar6 = local_150 + 1;
    pfVar4 = (float *)(param_2 + 0xc);
    do {
      fVar2 = local_50[uVar7];
      pfVar6[-1] = pfVar4[-3];
      fVar3 = *pfVar4;
      *pfVar6 = pfVar4[-2];
      local_8 = fVar2 + fVar3;
      pfVar6[1] = pfVar4[-1];
      iVar5 = (int)ROUND(fVar2 + fVar3 + DAT_0099d0b4);
      local_c = iVar5;
      uVar1 = uVar7 & 3;
      *(float *)(((int)local_150 - param_2) + (int)pfVar4) = (float)iVar5;
      fVar2 = local_8 - (float)iVar5;
      if (uVar1 != 3) {
        local_50[uVar7 + 1] = _DAT_00a250bc * fVar2 + local_50[uVar7 + 1];
      }
      if (uVar7 < 0xc) {
        if (uVar1 != 0) {
          local_50[uVar7 + 3] = _DAT_00a171c4 * fVar2 + local_50[uVar7 + 3];
        }
        local_50[uVar7 + 4] = _DAT_00a171c0 * fVar2 + local_50[uVar7 + 4];
        if (uVar1 != 3) {
          local_50[uVar7 + 5] = fVar2 * DAT_009af898 + local_50[uVar7 + 5];
        }
      }
      uVar7 = uVar7 + 1;
      pfVar6 = pfVar6 + 4;
      pfVar4 = pfVar4 + 4;
    } while (uVar7 < 0x10);
  }
  iVar5 = FUN_008f18d2(param_1,1,param_3);
  if (-1 < iVar5) {
    iVar5 = 0;
  }
  return iVar5;
}


// ==== FUN_008f264e @ 0x008f264e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f264e(undefined4 *param_1,int param_2,int param_3)

{
  uint *puVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  float *pfVar7;
  undefined2 in_FPUControlWord;
  float local_54 [17];
  float local_10;
  float local_c;
  float *local_8;
  
  puVar3 = param_1;
  uVar5 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  if (param_3 != 0) {
    pfVar7 = local_54;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *pfVar7 = 0.0;
      pfVar7 = pfVar7 + 1;
    }
  }
  param_1 = (undefined4 *)CONCAT22(param_1._2_2_,in_FPUControlWord);
  local_54[0x10] = (float)param_1;
  local_8 = (float *)(param_2 + 0xc);
  do {
    param_1 = (undefined4 *)*local_8;
    if (param_3 != 0) {
      param_1 = (undefined4 *)((float)param_1 + local_54[uVar5]);
    }
    local_c = (float)param_1 * DAT_009bfa74 + DAT_0099d0b4;
    local_10 = (float)(int)ROUND(local_c);
    puVar1 = puVar3 + (uVar5 >> 3);
    *puVar1 = *puVar1 >> 4 | (int)local_10 << 0x1c;
    if (param_3 != 0) {
      fVar2 = (float)(int)local_10;
      if ((int)local_10 < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      uVar6 = uVar5 & 3;
      fVar2 = (float)param_1 - fVar2 * _DAT_00a171c8;
      if (uVar6 != 3) {
        local_54[uVar5 + 1] = _DAT_00a250bc * fVar2 + local_54[uVar5 + 1];
      }
      local_c = local_10;
      if (uVar5 < 0xc) {
        if (uVar6 != 0) {
          local_54[uVar5 + 3] = _DAT_00a171c4 * fVar2 + local_54[uVar5 + 3];
        }
        local_54[uVar5 + 4] = _DAT_00a171c0 * fVar2 + local_54[uVar5 + 4];
        if (uVar6 != 3) {
          local_54[uVar5 + 5] = fVar2 * DAT_009af898 + local_54[uVar5 + 5];
        }
      }
    }
    local_8 = local_8 + 4;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x10);
  FUN_008f18d2(puVar3 + 2,0,param_3);
  return;
}


// ==== FUN_008f277d @ 0x008f277d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008f277d(char *param_1,float param_2,int param_3)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  float *pfVar14;
  float *pfVar15;
  undefined2 in_FPUControlWord;
  float local_a4 [32];
  int local_24;
  float local_20;
  float *local_1c;
  uint local_18;
  float *local_14;
  float local_10;
  undefined *local_c;
  undefined4 local_8;
  
  pcVar1 = param_1;
  pfVar15 = (float *)((int)param_2 + 0xc);
  uVar13 = 0;
  local_1c = pfVar15;
  local_14 = (float *)*pfVar15;
  local_8 = (float *)*pfVar15;
  if (param_3 != 0) {
    pfVar14 = local_a4;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pfVar14 = 0.0;
      pfVar14 = pfVar14 + 1;
    }
  }
  param_2 = (float)CONCAT22(param_2._2_2_,in_FPUControlWord);
  local_c = (undefined *)((uint)param_2 | 0xc00);
  local_18 = (uint)param_2;
  do {
    param_2 = *pfVar15;
    if (param_3 != 0) {
      param_2 = param_2 + local_a4[uVar13];
    }
    local_10 = (float)(int)ROUND(param_2 * DAT_0099d0b8 + DAT_0099d0b4);
    local_c = (undefined *)local_10;
    fVar2 = (float)(int)local_10 * DAT_0099d0b0;
    local_a4[uVar13 + 0x10] = fVar2;
    if ((float)local_14 <= fVar2) {
      if ((float)local_8 < fVar2) {
        local_8 = (float *)fVar2;
      }
    }
    else {
      local_14 = (float *)fVar2;
    }
    if (param_3 != 0) {
      fVar2 = param_2 - fVar2;
      uVar10 = uVar13 & 3;
      if (uVar10 != 3) {
        local_a4[uVar13 + 1] = _DAT_00a250bc * fVar2 + local_a4[uVar13 + 1];
      }
      if (uVar13 < 0xc) {
        if (uVar10 != 0) {
          local_a4[uVar13 + 3] = _DAT_00a171c4 * fVar2 + local_a4[uVar13 + 3];
        }
        local_a4[uVar13 + 4] = _DAT_00a171c0 * fVar2 + local_a4[uVar13 + 4];
        if (uVar10 != 3) {
          local_a4[uVar13 + 5] = fVar2 * DAT_009af898 + local_a4[uVar13 + 5];
        }
      }
    }
    uVar13 = uVar13 + 1;
    pfVar15 = pfVar15 + 4;
  } while (uVar13 < 0x10);
  iVar8 = FUN_008f18d2(param_1 + 8,0,param_3);
  if (iVar8 < 0) {
    return iVar8;
  }
  if (DAT_0099d080 == (float)local_14) {
    *param_1 = -1;
    param_1[1] = -1;
LAB_008f29b0:
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1[4] = '\0';
    pcVar1[5] = '\0';
    pcVar1[6] = '\0';
    pcVar1[7] = '\0';
    goto LAB_008f2c48;
  }
  if ((DAT_0099cdc8 == (float)local_14) || (DAT_0099d080 == (float)local_8)) {
    param_1 = (char *)0x6;
    iVar8 = 6;
  }
  else {
    iVar8 = 8;
    param_1 = (char *)0x8;
  }
  FUN_008f102b(&local_10,&param_2,local_a4 + 0x10,iVar8);
  uVar13 = (uint)ROUND(local_10 * DAT_0099d0b8 + DAT_0099d0b4);
  uVar10 = (uint)ROUND(param_2 * DAT_0099d0b8 + DAT_0099d0b4);
  fVar2 = (float)(uVar13 & 0xff) * DAT_0099d0b0;
  fVar3 = (float)(uVar10 & 0xff) * DAT_0099d0b0;
  cVar6 = (char)uVar13;
  cVar7 = (char)uVar10;
  if (iVar8 == 8) {
    if (cVar6 == cVar7) {
      *pcVar1 = cVar6;
      pcVar1[1] = cVar7;
      goto LAB_008f29b0;
    }
LAB_008f2a25:
    pcVar1[1] = cVar6;
    local_a4[0x18] = fVar3;
    local_a4[0x19] = fVar2;
    *pcVar1 = cVar7;
    uVar13 = 1;
    do {
      fVar4 = (float)(int)(7 - uVar13);
      if ((int)(7 - uVar13) < 0) {
        fVar4 = fVar4 + _DAT_0099d104;
      }
      fVar5 = (float)(int)uVar13;
      if ((int)uVar13 < 0) {
        fVar5 = fVar5 + _DAT_0099d104;
      }
      uVar10 = uVar13 + 1;
      local_a4[uVar13 + 0x19] = (fVar5 * fVar2 + fVar4 * fVar3) * _DAT_00a171cc;
      uVar13 = uVar10;
    } while (uVar10 < 7);
    local_c = &DAT_00a250c0;
  }
  else {
    if (iVar8 != 6) goto LAB_008f2a25;
    *pcVar1 = cVar6;
    local_a4[0x18] = fVar2;
    local_a4[0x19] = fVar3;
    pcVar1[1] = cVar7;
    uVar13 = 1;
    do {
      fVar4 = (float)(int)(5 - uVar13);
      if ((int)(5 - uVar13) < 0) {
        fVar4 = fVar4 + _DAT_0099d104;
      }
      fVar5 = (float)(int)uVar13;
      if ((int)uVar13 < 0) {
        fVar5 = fVar5 + _DAT_0099d104;
      }
      uVar10 = uVar13 + 1;
      local_a4[uVar13 + 0x19] = (fVar5 * fVar3 + fVar4 * fVar2) * DAT_009b02a8;
      uVar13 = uVar10;
    } while (uVar10 < 5);
    local_c = &DAT_00a250e0;
    local_a4[0x1e] = 0.0;
    local_a4[0x1f] = 1.0;
  }
  iVar8 = iVar8 + -1;
  local_10 = (float)iVar8;
  if (iVar8 < 0) {
    local_10 = local_10 + _DAT_0099d104;
  }
  if (local_a4[0x18] == local_a4[0x19]) {
    local_20 = 0.0;
  }
  else {
    local_20 = local_10 / (local_a4[0x19] - local_a4[0x18]);
  }
  if (param_3 != 0) {
    pfVar15 = local_a4;
    for (iVar9 = 0x10; iVar9 != 0; iVar9 = iVar9 + -1) {
      *pfVar15 = 0.0;
      pfVar15 = pfVar15 + 1;
    }
  }
  param_2._2_2_ = (undefined2)((uint)iVar8 >> 0x10);
  param_2 = (float)CONCAT22(param_2._2_2_,in_FPUControlWord);
  local_18 = (uint)param_2;
  local_14 = local_1c;
  uVar13 = 0;
  do {
    uVar12 = 0;
    uVar10 = uVar13 + 8;
    local_8 = (float *)0x0;
    if (uVar13 < uVar10) {
      local_8 = local_14;
      do {
        param_2 = *local_8;
        if (param_3 != 0) {
          param_2 = param_2 + local_a4[uVar13];
        }
        fVar2 = (param_2 - local_a4[0x18]) * local_20;
        if ((NAN(fVar2) || NAN(DAT_0099cdc8)) || fVar2 < DAT_0099cdc8 == (fVar2 == DAT_0099cdc8)) {
          if (fVar2 < local_10) {
            local_1c = (float *)(fVar2 + DAT_0099d0b4);
            local_24 = (int)ROUND(fVar2 + DAT_0099d0b4);
            iVar8 = *(int *)(local_c + local_24 * 4);
          }
          else if ((param_1 != (char *)0x6) ||
                  (fVar2 = (local_a4[0x19] + DAT_0099d080) * DAT_0099d0b4,
                  !((!NAN(fVar2) && !NAN(param_2)) && fVar2 < param_2 != (fVar2 == param_2)))) {
            iVar8 = 1;
          }
          else {
            iVar8 = 7;
          }
        }
        else if ((param_1 != (char *)0x6) || (local_a4[0x18] * DAT_0099d0b4 < param_2)) {
          iVar8 = 0;
        }
        else {
          iVar8 = 6;
        }
        uVar12 = uVar12 >> 3 | iVar8 << 0x15;
        if (param_3 != 0) {
          param_2 = param_2 - local_a4[iVar8 + 0x18];
          uVar11 = uVar13 & 3;
          if (uVar11 != 3) {
            local_a4[uVar13 + 1] = _DAT_00a250bc * param_2 + local_a4[uVar13 + 1];
          }
          if (uVar13 < 0xc) {
            if (uVar11 != 0) {
              local_a4[uVar13 + 3] = _DAT_00a171c4 * param_2 + local_a4[uVar13 + 3];
            }
            local_a4[uVar13 + 4] = _DAT_00a171c0 * param_2 + local_a4[uVar13 + 4];
            if (uVar11 != 3) {
              local_a4[uVar13 + 5] = param_2 * DAT_009af898 + local_a4[uVar13 + 5];
            }
          }
        }
        local_8 = local_8 + 4;
        uVar13 = uVar13 + 1;
      } while (uVar13 < uVar10);
      local_8 = (float *)uVar12;
    }
    local_14 = local_14 + 0x20;
    pcVar1[4] = local_8._2_1_;
    pcVar1[2] = (char)local_8;
    pcVar1[3] = (char)((uint)local_8 >> 8);
    uVar13 = uVar10;
    pcVar1 = pcVar1 + 3;
  } while (uVar10 < 0x10);
LAB_008f2c48:
  return 0;
}


// ==== FUN_008f2c51 @ 0x008f2c51 ====

int FUN_008f2c51(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_008f2367(param_1,param_2);
  if (-1 < iVar1) {
    iVar1 = FUN_008f0e74();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_008f2c77 @ 0x008f2c77 ====

int FUN_008f2c77(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_008f23ec(param_1,param_2);
  if (-1 < iVar1) {
    iVar1 = FUN_008f0e74();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_008f2c9d @ 0x008f2c9d ====

int FUN_008f2c9d(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_104 [256];
  
  iVar1 = FUN_008f0ef8();
  if (-1 < iVar1) {
    iVar1 = FUN_008f264e(param_1,local_104,param_3);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_008f2cd6 @ 0x008f2cd6 ====

int FUN_008f2cd6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 local_104 [256];
  
  iVar1 = FUN_008f0ef8();
  if (-1 < iVar1) {
    iVar1 = FUN_008f277d(param_1,local_104,param_3);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_008f2d0f @ 0x008f2d0f ====

undefined4 FUN_008f2d0f(uint *param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  if (param_1 == (uint *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    uVar3 = *param_1 & 0xffff0000;
    puVar4 = param_1;
    if (((((uVar3 == 0x46580000) || (uVar3 == 0x54580000)) || (uVar3 == 0x7ffe0000)) ||
        ((uVar3 == 0x7fff0000 || (uVar3 == 0xfffe0000)))) || (uVar3 == 0xffff0000)) {
      do {
        while( true ) {
          do {
            puVar1 = puVar4;
            puVar4 = puVar1 + 1;
            uVar3 = *puVar4;
          } while ((int)uVar3 < 0);
          uVar5 = uVar3 & 0xffff;
          if (uVar5 == 0xffff) {
            return 1;
          }
          if (uVar5 != 0xfffe) break;
          uVar3 = uVar3 >> 0x10 & 0x7fff;
          if ((1 < uVar3) && (param_2 == puVar1[2])) {
            if (param_3 != (undefined4 *)0x0) {
              *param_3 = puVar1 + 3;
            }
            if (param_4 != (int *)0x0) {
              *param_4 = uVar3 * 4 + -4;
            }
            return 0;
          }
LAB_008f2ddc:
          puVar4 = puVar4 + uVar3;
        }
        if (0x1ff < (*param_1 & 0xffff)) {
          uVar3 = uVar3 >> 0x18 & 0xf;
          goto LAB_008f2ddc;
        }
        if (uVar5 == 0x51) {
          puVar4 = puVar1 + 6;
        }
      } while( true );
    }
    uVar2 = 0x88760b59;
  }
  return uVar2;
}


// ==== FUN_008f2df6 @ 0x008f2df6 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008f2df6(uint *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  int local_14;
  char local_10 [12];
  
  if (param_1 == (uint *)0x0) {
    return 0x8876086c;
  }
  local_14 = 0;
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  uVar8 = *param_1;
  uVar6 = uVar8 & 0xffff0000;
  if (uVar6 != 0x46580000) {
    if (uVar6 == 0xfffe0000) {
      bVar3 = *(byte *)((int)param_1 + 1);
      while( true ) {
        do {
          puVar7 = param_1;
          param_1 = puVar7 + 1;
        } while ((int)*param_1 < 0);
        if (((*param_1 & 0xffff) == 0x1f) &&
           ((puVar7[3] >> 0x14 & 0x700 | puVar7[3] & 0x1800) == 0x100)) {
          if (param_2 != 0) {
            *(uint *)(local_14 * 8 + param_2) = puVar7[2] & 0xffff;
            *(uint *)(local_14 * 8 + 4 + param_2) = *(ushort *)((int)puVar7 + 10) & 0x7fff;
          }
          local_14 = local_14 + 1;
        }
        uVar8 = *param_1;
        uVar6 = uVar8 & 0xffff;
        if (uVar6 == 0xffff) break;
        if (uVar6 == 0xfffe) {
          param_1 = param_1 + (uVar8 >> 0x10 & 0x7fff);
        }
        else if (bVar3 < 2) {
          if (uVar6 == 0x51) {
            param_1 = puVar7 + 6;
          }
        }
        else {
          param_1 = param_1 + (uVar8 >> 0x18 & 0xf);
        }
      }
    }
    else {
      if (uVar6 != 0xffff0000) {
        return 0x88760b59;
      }
      cVar2 = *(char *)((int)param_1 + 1);
      if (cVar2 == '\x03') {
        while( true ) {
          puVar7 = param_1 + 1;
          if (((*puVar7 & 0xffff) == 0x1f) &&
             ((param_1[3] >> 0x14 & 0x700 | param_1[3] & 0x1800) == 0x100)) {
            if (param_2 != 0) {
              *(uint *)(local_14 * 8 + param_2) = param_1[2] & 0xffff;
              *(uint *)(local_14 * 8 + 4 + param_2) = *(ushort *)((int)param_1 + 10) & 0x7fff;
            }
            local_14 = local_14 + 1;
          }
          uVar8 = *puVar7;
          if ((uVar8 & 0xffff) == 0xffff) break;
          if ((uVar8 & 0xffff) == 0xfffe) {
            uVar8 = uVar8 >> 0x10 & 0x7fff;
          }
          else {
            uVar8 = uVar8 >> 0x18 & 0xf;
          }
          param_1 = puVar7 + uVar8;
        }
      }
      else {
        if (cVar2 == '\x02') {
          do {
            puVar7 = param_1 + 1;
            if ((*puVar7 & 0xffff) == 0x1f) {
              uVar6 = param_1[3] & 0x7ff;
              uVar8 = param_1[3] & 0xf0001800;
              if (param_2 == 0) {
LAB_008f2f61:
                if (uVar8 == 0xa0000800) goto LAB_008f2f6b;
              }
              else if (uVar8 == 0xb0000000) {
                *(undefined4 *)(local_14 * 8 + param_2) = 5;
                *(uint *)(local_14 * 8 + 4 + param_2) = uVar6;
              }
              else {
                if (uVar8 != 0x90000000) {
                  if (uVar8 != 0xa0000800) {
                    return 0x80004005;
                  }
                  goto LAB_008f2f61;
                }
                if (1 < uVar6) {
                  return 0x80004005;
                }
                *(undefined4 *)(local_14 * 8 + 4 + param_2) = 0;
                *(undefined4 *)(local_14 * 8 + param_2) = 10;
              }
              local_14 = local_14 + 1;
            }
LAB_008f2f6b:
            uVar8 = *puVar7;
            if ((uVar8 & 0xffff) == 0xffff) goto LAB_008f310e;
            if ((uVar8 & 0xffff) == 0xfffe) {
              uVar8 = uVar8 >> 0x10 & 0x7fff;
            }
            else {
              uVar8 = uVar8 >> 0x18 & 0xf;
            }
            param_1 = puVar7 + uVar8;
          } while( true );
        }
        if (cVar2 != '\x01') {
          return 0x80004005;
        }
        local_10[0] = '\0';
        local_10[1] = '\0';
        local_10[2] = '\0';
        local_10[3] = '\0';
        local_10[4] = '\0';
        local_10[5] = '\0';
        bVar10 = (char)uVar8 == '\x04';
        bVar4 = false;
        bVar5 = false;
        while( true ) {
          while( true ) {
            puVar7 = param_1;
            param_1 = puVar7 + 1;
            uVar6 = *param_1;
            if (-1 < (int)uVar6) break;
            if ((uVar6 & 0xf0001800) == 0x90000000) {
              if ((uVar6 & 0x7ff) == 0) {
                bVar4 = true;
              }
              else if ((uVar6 & 0x7ff) == 1) {
                bVar5 = true;
              }
            }
            if ((bVar10) && ((uVar6 & 0xf0001800) == 0xb0000000)) {
              local_10[uVar6 & 0x7ff] = '\x01';
            }
          }
          uVar9 = uVar6 & 0xffff;
          if (uVar9 == 0xffff) break;
          if (uVar9 == 0xfffe) {
            uVar6 = uVar6 >> 0x10 & 0x7fff;
LAB_008f309b:
            param_1 = param_1 + uVar6;
          }
          else {
            if ((((!bVar10) && (0x3f < uVar9)) &&
                ((uVar9 < 0x4b ||
                 ((0x4b < uVar9 && ((uVar9 < 0x4e || ((0x51 < uVar9 && (uVar9 < 0x58)))))))))) &&
               ((puVar7[2] & 0xf0001800) == 0xb0000000)) {
              local_10[puVar7[2] & 0x7ff] = '\x01';
            }
            if (0x1ff < (uVar8 & 0xffff)) {
              uVar6 = uVar6 >> 0x18 & 0xf;
              goto LAB_008f309b;
            }
            if (uVar9 == 0x51) {
              param_1 = puVar7 + 6;
            }
          }
        }
        uVar8 = 0;
        do {
          if (local_10[uVar8] != '\0') {
            if (param_2 != 0) {
              *(undefined4 *)(local_14 * 8 + param_2) = 5;
              *(uint *)(local_14 * 8 + 4 + param_2) = uVar8;
            }
            local_14 = local_14 + 1;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < 6);
        if (bVar4) {
          if (param_2 != 0) {
            puVar1 = (undefined4 *)(param_2 + local_14 * 8);
            *puVar1 = 10;
            puVar1[1] = 0;
          }
          local_14 = local_14 + 1;
        }
        if (bVar5) {
          if (param_2 != 0) {
            puVar1 = (undefined4 *)(param_2 + local_14 * 8);
            *puVar1 = 10;
            puVar1[1] = 1;
          }
          local_14 = local_14 + 1;
        }
      }
    }
LAB_008f310e:
    if (param_3 != (int *)0x0) {
      *param_3 = local_14;
    }
  }
  return 0;
}


// ==== FUN_008f31de @ 0x008f31de ====

void FUN_008f31de(byte param_1)

{
  void *in_ECX;
  
  FUN_00910f08();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008f31ff @ 0x008f31ff ====

undefined4 FUN_008f31ff(byte *param_1,uint param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  uint local_8;
  
  uVar5 = 0;
  if (param_1 == (byte *)0x0) {
    uVar2 = 0x8876086c;
  }
  else {
    local_8 = 0x2c;
    do {
      uVar3 = local_8 + uVar5 >> 1;
      pbVar6 = *(byte **)(uVar3 * 0xc + 0xa250f8);
      pbVar7 = param_1;
      do {
        bVar1 = *pbVar6;
        bVar8 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_008f324f:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_008f3254;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar8 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_008f324f;
        pbVar6 = pbVar6 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_008f3254:
      if (iVar4 == 0) {
        iVar4 = uVar3 * 0xc;
        if ((*(uint *)(&DAT_00a25100 + iVar4) & param_2) == param_2) {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = *(undefined4 *)(iVar4 + 0xa250f8);
            param_3[1] = *(undefined4 *)(iVar4 + 0xa250fc);
            param_3[2] = *(undefined4 *)(&DAT_00a25100 + iVar4);
          }
          return 0;
        }
        break;
      }
      if (iVar4 < 0) {
        uVar5 = uVar3 + 1;
      }
      else {
        local_8 = uVar3;
      }
    } while (uVar5 < local_8);
    uVar2 = 0x80004005;
  }
  return uVar2;
}


// ==== FUN_008f329d @ 0x008f329d ====

undefined4 FUN_008f329d(uint param_1,uint param_2,undefined4 *param_3)

{
  uint *puVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = 0x2c;
  pcVar2 = s_vs_3_0_00a25310;
  while( true ) {
    puVar1 = (uint *)((int)pcVar2 + -0x10);
    pcVar2 = (char *)((int)pcVar2 + -0xc);
    iVar3 = iVar3 + -1;
    if ((*puVar1 == param_1) && ((*(uint *)pcVar2 & param_2) == param_2)) break;
    if (pcVar2 < (uint *)0xa25101) {
      return 0x80004005;
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    iVar3 = iVar3 * 0xc;
    *param_3 = *(undefined4 *)(iVar3 + 0xa250f8);
    param_3[1] = *(undefined4 *)(iVar3 + 0xa250fc);
    param_3[2] = *(undefined4 *)(&DAT_00a25100 + iVar3);
  }
  return 0;
}


// ==== FUN_008f32ec @ 0x008f32ec ====

int FUN_008f32ec(uint *param_1,int *param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
  }
  if ((param_1 == (uint *)0x0) || (param_2 == (int *)0x0)) {
    return -0x7789f794;
  }
  if (((*param_1 & 0xffff0000) == 0xfffe0000) || ((*param_1 & 0xffff0000) == 0xffff0000)) {
    pvVar1 = operator_new(0x20);
    if (pvVar1 != (void *)0x0) {
      iVar3 = FUN_00913995();
    }
    if (iVar3 == 0) {
      return -0x7ff8fff2;
    }
    iVar2 = FUN_009139b6(param_1,0);
    if (iVar2 < 0) {
      FUN_008f31de(1);
      return iVar2;
    }
  }
  *param_2 = iVar3;
  return 0;
}


// ==== FUN_008f336d @ 0x008f336d ====

void FUN_008f336d(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *in_ECX;
  _SYSTEM_INFO local_28;
  
  *in_ECX = 0;
  GetSystemInfo(&local_28);
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[1] = local_28.dwPageSize;
  uVar1 = (local_28.dwPageSize - 1) + param_2 & ~(local_28.dwPageSize - 1);
  in_ECX[1] = uVar1;
  if (param_1 == 0) {
    param_1 = 0x100000;
  }
  in_ECX[5] = (uVar1 - 1) + param_1 & ~(uVar1 - 1);
  return;
}


// ==== FUN_008f33c5 @ 0x008f33c5 ====

void FUN_008f33c5(void)

{
  int *lpAddress;
  int *in_ECX;
  
  while (*in_ECX != 0) {
    lpAddress = (int *)*in_ECX;
    *in_ECX = *lpAddress;
    VirtualFree(lpAddress,0,0x8000);
  }
  return;
}


// ==== FUN_008f33e7 @ 0x008f33e7 ====

int FUN_008f33e7(int param_1,int param_2)

{
  uint uVar1;
  int *lpAddress;
  LPVOID pvVar2;
  int *in_ECX;
  uint dwSize;
  uint uVar3;
  
  uVar3 = (param_2 + -1 + in_ECX[2] & ~(param_2 - 1U)) + param_1;
  if ((uint)in_ECX[4] < uVar3) {
    uVar3 = (param_2 + 3U & ~(param_2 - 1U)) + param_1;
    for (uVar1 = in_ECX[5]; uVar1 < uVar3; uVar1 = uVar1 * 2) {
    }
    lpAddress = VirtualAlloc((LPVOID)0x0,uVar1,0x2000,4);
    if (lpAddress == (int *)0x0) {
      return 0;
    }
    dwSize = in_ECX[1] + -1 + uVar3 & ~(in_ECX[1] - 1U);
    pvVar2 = VirtualAlloc(lpAddress,dwSize,0x1000,4);
    if (pvVar2 == (LPVOID)0x0) {
      VirtualFree(lpAddress,0,0x8000);
      return 0;
    }
    *lpAddress = *in_ECX;
    *in_ECX = (int)lpAddress;
    in_ECX[4] = uVar1;
  }
  else {
    uVar1 = in_ECX[3];
    if (uVar3 <= uVar1) goto LAB_008f348e;
    dwSize = in_ECX[1] + -1 + uVar3 & ~(in_ECX[1] - 1U);
    pvVar2 = VirtualAlloc((LPVOID)(*in_ECX + uVar1),dwSize - uVar1,0x1000,4);
    if (pvVar2 == (LPVOID)0x0) {
      return 0;
    }
  }
  in_ECX[3] = dwSize;
LAB_008f348e:
  in_ECX[2] = uVar3;
  return (*in_ECX - param_1) + uVar3;
}


// ==== FUN_008f34d1 @ 0x008f34d1 ====

void FUN_008f34d1(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_00a2545c;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_008f34f0 @ 0x008f34f0 ====

bool FUN_008f34f0(int param_1)

{
  int in_ECX;
  bool bVar1;
  
  bVar1 = false;
  if (param_1 != 0) {
    bVar1 = *(int *)(param_1 + 4) == *(int *)(in_ECX + 4);
  }
  return bVar1;
}


// ==== FUN_008f350b @ 0x008f350b ====

uint FUN_008f350b(undefined4 *param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = (uint)(param_2 == 0);
  }
  else {
    uVar1 = (**(code **)*param_1)(param_2);
  }
  return uVar1;
}


// ==== FUN_008f352c @ 0x008f352c ====

undefined4 FUN_008f352c(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(*param_1 + 4))();
  }
  return uVar1;
}


// ==== FUN_008f3545 @ 0x008f3545 ====

int FUN_008f3545(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = &param_1;
    do {
      piVar1 = (int *)(*piVar1 + 0xc);
    } while (*piVar1 != 0);
    *piVar1 = param_2;
    param_2 = param_1;
  }
  return param_2;
}


// ==== FUN_008f356e @ 0x008f356e ====

undefined4 * FUN_008f356e(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(1);
  extraout_EDX[4] = 0;
  *extraout_EDX = &PTR_FUN_00a25468;
  return extraout_EDX;
}


// ==== FUN_008f3584 @ 0x008f3584 ====

undefined4 * FUN_008f3584(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(1);
  extraout_EDX[2] = param_1;
  extraout_EDX[3] = param_2;
  extraout_EDX[4] = param_3;
  *extraout_EDX = &PTR_FUN_00a25468;
  return extraout_EDX;
}


// ==== FUN_008f35b0 @ 0x008f35b0 ====

undefined4 FUN_008f35b0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  uVar3 = 0;
  iVar2 = extraout_ECX;
  if (iVar1 != 0) {
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      if (*(int *)(iVar2 + 4) != 1) {
        iVar2 = FUN_008f350b(iVar2,param_1);
        if (iVar2 == 0) {
          return 0;
        }
        break;
      }
      if (param_1 == 0) {
        return 0;
      }
      if (*(int *)(param_1 + 4) != 1) {
        return 0;
      }
      iVar1 = FUN_008f350b(*(undefined4 *)(iVar2 + 8),*(undefined4 *)(param_1 + 8));
      if (iVar1 == 0) {
        return 0;
      }
      param_1 = *(int *)(param_1 + 0xc);
    }
    uVar3 = 1;
  }
  return uVar3;
}


// ==== FUN_008f360d @ 0x008f360d ====

undefined4 * FUN_008f360d(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(2);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  *extraout_EDX = &PTR_FUN_00a25474;
  return extraout_EDX;
}


// ==== FUN_008f3627 @ 0x008f3627 ====

undefined4 *
FUN_008f3627(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(2);
  extraout_EDX[4] = param_1;
  extraout_EDX[2] = param_2;
  extraout_EDX[3] = param_3;
  extraout_EDX[5] = param_4;
  *extraout_EDX = &PTR_FUN_00a25474;
  return extraout_EDX;
}


// ==== FUN_008f3659 @ 0x008f3659 ====

bool FUN_008f3659(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if ((((iVar1 == 0) || (*(int *)(in_ECX + 0x10) != *(int *)(param_1 + 0x10))) ||
      (*(int *)(in_ECX + 0x14) != *(int *)(param_1 + 0x14))) ||
     (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(param_1 + 8)), iVar1 == 0)) {
    return false;
  }
  iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(param_1 + 0xc));
  return iVar1 != 0;
}


// ==== FUN_008f36a9 @ 0x008f36a9 ====

undefined4 FUN_008f36a9(void)

{
  byte bVar1;
  int *in_EAX;
  byte *pbVar2;
  int iVar3;
  int *in_ECX;
  byte *pbVar4;
  bool bVar5;
  
  iVar3 = *in_ECX;
  if (iVar3 != *in_EAX) {
    return 0;
  }
  if (iVar3 < 9) {
    if (4 < iVar3) {
      if (*(double *)(in_ECX + 2) == *(double *)(in_EAX + 2)) {
        return 1;
      }
      return 0;
    }
    if (iVar3 != 0) {
      if (iVar3 == 1) {
        pbVar4 = (byte *)(in_EAX + 2);
        pbVar2 = (byte *)(in_ECX + 2);
        do {
          bVar1 = *pbVar2;
          bVar5 = bVar1 < *pbVar4;
          if (bVar1 != *pbVar4) goto LAB_008f376d;
          if (bVar1 == 0) break;
          bVar1 = pbVar2[1];
          bVar5 = bVar1 < pbVar4[1];
          if (bVar1 != pbVar4[1]) goto LAB_008f376d;
          pbVar2 = pbVar2 + 2;
          pbVar4 = pbVar4 + 2;
        } while (bVar1 != 0);
        goto LAB_008f3701;
      }
      if (iVar3 < 2) {
        return 1;
      }
      if (4 < iVar3) {
        return 1;
      }
    }
    bVar5 = in_ECX[2] == in_EAX[2];
    goto LAB_008f36d3;
  }
  if (iVar3 == 9) {
    pbVar4 = (byte *)in_EAX[2];
    pbVar2 = (byte *)in_ECX[2];
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) goto LAB_008f376d;
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_008f376d;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
  }
  else {
    if (iVar3 != 10) {
      return 1;
    }
    pbVar4 = (byte *)in_EAX[2];
    pbVar2 = (byte *)in_ECX[2];
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) goto LAB_008f376d;
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_008f376d;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
  }
LAB_008f3701:
  iVar3 = 0;
LAB_008f3772:
  bVar5 = iVar3 == 0;
LAB_008f36d3:
  if (bVar5) {
    return 1;
  }
  return 0;
LAB_008f376d:
  iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
  goto LAB_008f3772;
}


// ==== FUN_008f3779 @ 0x008f3779 ====

undefined4 * FUN_008f3779(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(3);
  *extraout_EDX = &PTR_FUN_00a25480;
  return extraout_EDX;
}


// ==== FUN_008f378b @ 0x008f378b ====

undefined4 * FUN_008f378b(undefined4 *param_1)

{
  int iVar1;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  
  FUN_008f34d1(3);
  *extraout_EDX = &PTR_FUN_00a25480;
  puVar2 = extraout_EDX + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return extraout_EDX;
}


// ==== FUN_008f37b4 @ 0x008f37b4 ====

bool FUN_008f37b4(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_008f34f0(param_1);
  bVar2 = false;
  if (iVar1 != 0) {
    iVar1 = FUN_008f36a9();
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// ==== FUN_008f37db @ 0x008f37db ====

undefined4 * FUN_008f37db(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(4);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  *extraout_EDX = &PTR_FUN_00a2548c;
  return extraout_EDX;
}


// ==== FUN_008f37fb @ 0x008f37fb ====

undefined4 *
FUN_008f37fb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(4);
  extraout_EDX[4] = param_1;
  extraout_EDX[5] = param_2;
  extraout_EDX[6] = param_3;
  extraout_EDX[7] = param_4;
  *extraout_EDX = &PTR_FUN_00a2548c;
  return extraout_EDX;
}


// ==== FUN_008f382d @ 0x008f382d ====

bool FUN_008f382d(undefined4 param_1)

{
  int iVar1;
  int extraout_ECX;
  bool bVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_008f34f0(param_1);
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  if (((((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x10) != *(int *)(iVar1 + 0x10))) ||
      (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar1 + 0x14))) ||
     (*(int *)(extraout_ECX + 0x18) != *(int *)(iVar1 + 0x18))) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_008f350b(*(undefined4 *)(extraout_ECX + 0x1c),*(undefined4 *)(iVar1 + 0x1c));
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// ==== FUN_008f3870 @ 0x008f3870 ====

undefined4 * FUN_008f3870(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(5);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  extraout_EDX[8] = 0;
  *extraout_EDX = &PTR_FUN_00a25498;
  return extraout_EDX;
}


// ==== FUN_008f3893 @ 0x008f3893 ====

undefined4 *
FUN_008f3893(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(5);
  extraout_EDX[4] = param_1;
  extraout_EDX[5] = param_2;
  extraout_EDX[6] = param_3;
  extraout_EDX[7] = param_4;
  extraout_EDX[8] = param_5;
  *extraout_EDX = &PTR_FUN_00a25498;
  return extraout_EDX;
}


// ==== FUN_008f38cb @ 0x008f38cb ====

undefined4 FUN_008f38cb(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if ((((iVar1 == 0) || (*(int *)(in_ECX + 0x10) != *(int *)(param_1 + 0x10))) ||
      (*(int *)(in_ECX + 0x14) != *(int *)(param_1 + 0x14))) ||
     (((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(param_1 + 0x18)),
       iVar1 == 0 ||
       (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(param_1 + 0x1c)),
       iVar1 == 0)) ||
      (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(param_1 + 0x20)),
      iVar1 == 0)))) {
    return 0;
  }
  return 1;
}


// ==== FUN_008f392b @ 0x008f392b ====

undefined4 * FUN_008f392b(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(6);
  extraout_EDX[9] = 0xffffffff;
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  extraout_EDX[8] = 0;
  extraout_EDX[10] = 0;
  extraout_EDX[0xb] = 0;
  *extraout_EDX = &PTR_FUN_00a254a4;
  return extraout_EDX;
}


// ==== FUN_008f3958 @ 0x008f3958 ====

undefined4 *
FUN_008f3958(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(6);
  extraout_EDX[4] = param_1;
  extraout_EDX[5] = param_2;
  extraout_EDX[6] = param_3;
  extraout_EDX[7] = param_4;
  extraout_EDX[9] = 0xffffffff;
  extraout_EDX[8] = 0;
  extraout_EDX[10] = 0;
  extraout_EDX[0xb] = 0;
  *extraout_EDX = &PTR_FUN_00a254a4;
  return extraout_EDX;
}


// ==== FUN_008f3999 @ 0x008f3999 ====

undefined4 FUN_008f3999(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if ((((((iVar1 == 0) || (*(int *)(in_ECX + 0x10) != *(int *)(param_1 + 0x10))) ||
        (*(int *)(in_ECX + 0x20) != *(int *)(param_1 + 0x20))) ||
       ((*(int *)(in_ECX + 0x24) != *(int *)(param_1 + 0x24) ||
        (*(int *)(in_ECX + 0x28) != *(int *)(param_1 + 0x28))))) ||
      ((*(int *)(in_ECX + 0x2c) != *(int *)(param_1 + 0x2c) ||
       ((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(param_1 + 0x14)),
        iVar1 == 0 ||
        (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(param_1 + 0x18)),
        iVar1 == 0)))))) ||
     (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(param_1 + 0x1c)),
     iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// ==== FUN_008f3a11 @ 0x008f3a11 ====

undefined4 * FUN_008f3a11(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(7);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  *extraout_EDX = &PTR_FUN_00a254b0;
  return extraout_EDX;
}


// ==== FUN_008f3a2e @ 0x008f3a2e ====

undefined4 * FUN_008f3a2e(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(7);
  extraout_EDX[4] = param_1;
  extraout_EDX[5] = param_2;
  extraout_EDX[6] = param_3;
  *extraout_EDX = &PTR_FUN_00a254b0;
  return extraout_EDX;
}


// ==== FUN_008f3a5a @ 0x008f3a5a ====

undefined4 FUN_008f3a5a(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if ((((iVar1 == 0) || (*(int *)(in_ECX + 0x10) != *(int *)(param_1 + 0x10))) ||
      (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(param_1 + 0x14)),
      iVar1 == 0)) ||
     (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(param_1 + 0x18)),
     iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// ==== FUN_008f3aa3 @ 0x008f3aa3 ====

undefined4 * FUN_008f3aa3(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(8);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  *extraout_EDX = &PTR_FUN_00a254bc;
  return extraout_EDX;
}


// ==== FUN_008f3abd @ 0x008f3abd ====

undefined4 * FUN_008f3abd(undefined4 param_1,undefined4 param_2)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(8);
  extraout_EDX[4] = param_1;
  extraout_EDX[5] = param_2;
  *extraout_EDX = &PTR_FUN_00a254bc;
  return extraout_EDX;
}


// ==== FUN_008f3ae3 @ 0x008f3ae3 ====

bool FUN_008f3ae3(undefined4 param_1)

{
  int iVar1;
  int extraout_ECX;
  bool bVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_008f34f0(param_1);
  iVar1 = (int)((ulonglong)uVar3 >> 0x20);
  if (((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar1 + 0x14))) {
    bVar2 = false;
  }
  else {
    iVar1 = FUN_008f350b(*(undefined4 *)(extraout_ECX + 0x10),*(undefined4 *)(iVar1 + 0x10));
    bVar2 = iVar1 != 0;
  }
  return bVar2;
}


// ==== FUN_008f3b16 @ 0x008f3b16 ====

undefined4 * FUN_008f3b16(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(9);
  extraout_EDX[4] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  extraout_EDX[8] = 0;
  *extraout_EDX = &PTR_FUN_00a254c8;
  extraout_EDX[5] = 9;
  return extraout_EDX;
}


// ==== FUN_008f3b3d @ 0x008f3b3d ====

undefined4 *
FUN_008f3b3d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(9);
  extraout_EDX[4] = param_1;
  extraout_EDX[5] = param_2;
  extraout_EDX[6] = param_3;
  extraout_EDX[7] = param_4;
  extraout_EDX[8] = param_5;
  *extraout_EDX = &PTR_FUN_00a254c8;
  return extraout_EDX;
}


// ==== FUN_008f3b75 @ 0x008f3b75 ====

undefined4 FUN_008f3b75(undefined4 param_1)

{
  undefined4 uVar1;
  int extraout_ECX;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_008f34f0(param_1);
  iVar2 = (int)((ulonglong)uVar3 >> 0x20);
  if (((((int)uVar3 == 0) || (*(int *)(extraout_ECX + 0x10) != *(int *)(iVar2 + 0x10))) ||
      (*(int *)(extraout_ECX + 0x14) != *(int *)(iVar2 + 0x14))) ||
     (((*(int *)(extraout_ECX + 0x18) != *(int *)(iVar2 + 0x18) ||
       (*(int *)(extraout_ECX + 0x1c) != *(int *)(iVar2 + 0x1c))) ||
      (*(int *)(extraout_ECX + 0x20) != *(int *)(iVar2 + 0x20))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_008f3bba @ 0x008f3bba ====

undefined4 * FUN_008f3bba(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(10);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  extraout_EDX[8] = 0;
  extraout_EDX[9] = 0;
  extraout_EDX[10] = 0;
  extraout_EDX[0xb] = 0;
  extraout_EDX[0xc] = 0;
  extraout_EDX[0xd] = 0;
  extraout_EDX[0xe] = 0;
  extraout_EDX[0xf] = 0;
  *extraout_EDX = &PTR_FUN_00a254d4;
  return extraout_EDX;
}


// ==== FUN_008f3bf2 @ 0x008f3bf2 ====

undefined4 FUN_008f3bf2(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if (((((iVar1 == 0) || (*(int *)(in_ECX + 0x10) != *(int *)(param_1 + 0x10))) ||
       (*(int *)(in_ECX + 0x14) != *(int *)(param_1 + 0x14))) ||
      (((*(int *)(in_ECX + 0x18) != *(int *)(param_1 + 0x18) ||
        (*(int *)(in_ECX + 0x38) != *(int *)(param_1 + 0x38))) ||
       ((*(int *)(in_ECX + 0x3c) != *(int *)(param_1 + 0x3c) ||
        ((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(param_1 + 0x1c)),
         iVar1 == 0 ||
         (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(param_1 + 0x20)),
         iVar1 == 0)))))))) ||
     ((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x24),*(undefined4 *)(param_1 + 0x24)),
      iVar1 == 0 ||
      ((((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(param_1 + 0x28)),
         iVar1 == 0 ||
         (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(param_1 + 0x2c)),
         iVar1 == 0)) ||
        (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x30),*(undefined4 *)(param_1 + 0x30)),
        iVar1 == 0)) ||
       (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(param_1 + 0x34)),
       iVar1 == 0)))))) {
    return 0;
  }
  return 1;
}


// ==== FUN_008f3cb2 @ 0x008f3cb2 ====

undefined4 * FUN_008f3cb2(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(0xb);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  extraout_EDX[8] = 0;
  extraout_EDX[9] = 0;
  extraout_EDX[10] = 0;
  extraout_EDX[0xb] = 0;
  extraout_EDX[0xc] = 0;
  extraout_EDX[0xd] = 0;
  extraout_EDX[0xe] = 0;
  extraout_EDX[0xf] = 0;
  *extraout_EDX = &PTR_FUN_00a254e0;
  return extraout_EDX;
}


// ==== FUN_008f3cea @ 0x008f3cea ====

undefined4 FUN_008f3cea(int param_1)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = FUN_008f34f0(param_1);
  if ((((((iVar1 == 0) || (*(int *)(in_ECX + 0x10) != *(int *)(param_1 + 0x10))) ||
        (*(int *)(in_ECX + 0x14) != *(int *)(param_1 + 0x14))) ||
       ((*(int *)(in_ECX + 0x18) != *(int *)(param_1 + 0x18) ||
        (*(int *)(in_ECX + 0x1c) != *(int *)(param_1 + 0x1c))))) ||
      ((*(int *)(in_ECX + 0x34) != *(int *)(param_1 + 0x34) ||
       ((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(param_1 + 0x20)),
        iVar1 == 0 ||
        (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x24),*(undefined4 *)(param_1 + 0x24)),
        iVar1 == 0)))))) ||
     ((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(param_1 + 0x28)),
      iVar1 == 0 ||
      ((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(param_1 + 0x2c)),
       iVar1 == 0 ||
       (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x30),*(undefined4 *)(param_1 + 0x30)),
       iVar1 == 0)))))) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x34) != 0) {
    iVar1 = *(int *)(in_ECX + 0x34) << 2;
    bVar4 = true;
    pcVar2 = *(char **)(in_ECX + 0x38);
    pcVar3 = *(char **)(param_1 + 0x38);
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (!bVar4) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_008f3da4 @ 0x008f3da4 ====

undefined4 * FUN_008f3da4(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(0xc);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  extraout_EDX[8] = 0;
  *extraout_EDX = &PTR_FUN_00a254ec;
  return extraout_EDX;
}


// ==== FUN_008f3dc7 @ 0x008f3dc7 ====

undefined4 FUN_008f3dc7(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if ((((iVar1 == 0) || (*(int *)(in_ECX + 0x10) != *(int *)(param_1 + 0x10))) ||
      (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(param_1 + 0x14)),
      iVar1 == 0)) ||
     (((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(param_1 + 0x18)),
       iVar1 == 0 ||
       (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(param_1 + 0x1c)),
       iVar1 == 0)) ||
      (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(param_1 + 0x20)),
      iVar1 == 0)))) {
    return 0;
  }
  return 1;
}


// ==== FUN_008f3e2e @ 0x008f3e2e ====

undefined4 * FUN_008f3e2e(void)

{
  int iVar1;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  
  FUN_008f34d1(0xd);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  extraout_EDX[8] = 0;
  extraout_EDX[9] = 0;
  *extraout_EDX = &PTR_FUN_00a254f8;
  extraout_EDX[10] = 1;
  puVar2 = extraout_EDX + 0xc;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return extraout_EDX;
}


// ==== FUN_008f3e67 @ 0x008f3e67 ====

undefined4 *
FUN_008f3e67(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  
  FUN_008f34d1(0xd);
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[4] = param_1;
  extraout_EDX[7] = param_2;
  extraout_EDX[8] = param_3;
  extraout_EDX[9] = param_4;
  extraout_EDX[10] = param_5;
  *extraout_EDX = &PTR_FUN_00a254f8;
  puVar2 = extraout_EDX + 0xc;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_6;
    param_6 = param_6 + 1;
    puVar2 = puVar2 + 1;
  }
  return extraout_EDX;
}


// ==== FUN_008f3eb6 @ 0x008f3eb6 ====

undefined4 FUN_008f3eb6(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if ((((((iVar1 == 0) || (*(int *)(in_ECX + 0x14) != *(int *)(param_1 + 0x14))) ||
        (*(int *)(in_ECX + 0x18) != *(int *)(param_1 + 0x18))) ||
       ((*(int *)(in_ECX + 0x1c) != *(int *)(param_1 + 0x1c) ||
        (*(int *)(in_ECX + 0x28) != *(int *)(param_1 + 0x28))))) ||
      ((iVar1 = FUN_008f36a9(), iVar1 == 0 ||
       ((iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(param_1 + 0x10)),
        iVar1 == 0 ||
        (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(param_1 + 0x20)),
        iVar1 == 0)))))) ||
     (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x24),*(undefined4 *)(param_1 + 0x24)),
     iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// ==== FUN_008f3f35 @ 0x008f3f35 ====

undefined4 * FUN_008f3f35(void)

{
  int iVar1;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  
  FUN_008f34d1(0xe);
  *extraout_EDX = &PTR_FUN_00a25504;
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  extraout_EDX[7] = 0;
  puVar2 = extraout_EDX + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  extraout_EDX[4] = 3;
  return extraout_EDX;
}


// ==== FUN_008f3f68 @ 0x008f3f68 ====

void FUN_008f3f68(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  
  FUN_008f34d1(0xe);
  *in_ECX = &PTR_FUN_00a25504;
  in_ECX[4] = *param_1;
  in_ECX[5] = param_1[1];
  in_ECX[6] = param_1[2];
  in_ECX[7] = param_1[3];
  iVar1 = in_ECX[4];
  puVar4 = in_ECX + 8;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  if ((iVar1 == 4) && (in_ECX[6] != 0)) {
    uVar2 = FUN_008f352c(in_ECX[6]);
    in_ECX[6] = uVar2;
  }
  return;
}


// ==== FUN_008f3fb4 @ 0x008f3fb4 ====

undefined4 * FUN_008f3fb4(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  
  FUN_008f34d1(0xe);
  extraout_EDX[4] = param_1;
  extraout_EDX[6] = param_2;
  *extraout_EDX = &PTR_FUN_00a25504;
  puVar2 = extraout_EDX + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  return extraout_EDX;
}


// ==== FUN_008f3fe9 @ 0x008f3fe9 ====

undefined4 * FUN_008f3fe9(undefined4 param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  
  FUN_008f34d1(0xe);
  *(undefined8 *)(extraout_EDX + 6) = param_2;
  extraout_EDX[4] = param_1;
  *extraout_EDX = &PTR_FUN_00a25504;
  puVar2 = extraout_EDX + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  return extraout_EDX;
}


// ==== FUN_008f401e @ 0x008f401e ====

undefined4 *
FUN_008f401e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  
  FUN_008f34d1(0xe);
  extraout_EDX[4] = param_1;
  extraout_EDX[6] = param_2;
  extraout_EDX[7] = param_3;
  *extraout_EDX = &PTR_FUN_00a25504;
  puVar2 = extraout_EDX + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  return extraout_EDX;
}


// ==== FUN_008f4059 @ 0x008f4059 ====

undefined4 FUN_008f4059(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  undefined8 uVar7;
  
  uVar7 = FUN_008f34f0(param_1);
  iVar2 = (int)((ulonglong)uVar7 >> 0x20);
  if ((int)uVar7 != 0) {
    piVar4 = (int *)(iVar2 + 0x10);
    iVar1 = *piVar4;
    if (iVar1 == *(int *)(param_1 + 0x10)) {
      iVar3 = 4;
      bVar6 = true;
      piVar5 = (int *)(param_1 + 0x10);
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *piVar4 == *piVar5;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar6);
      if ((bVar6) ||
         ((iVar1 == 4 &&
          (iVar2 = FUN_008f350b(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(param_1 + 0x18)),
          iVar2 != 0)))) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_008f40aa @ 0x008f40aa ====

undefined4 * FUN_008f40aa(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(0x10);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  extraout_EDX[6] = 0;
  *extraout_EDX = &PTR_FUN_00a25510;
  return extraout_EDX;
}


// ==== FUN_008f40c7 @ 0x008f40c7 ====

undefined4 * FUN_008f40c7(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(0x10);
  extraout_EDX[4] = param_1;
  extraout_EDX[5] = param_2;
  extraout_EDX[6] = param_3;
  *extraout_EDX = &PTR_FUN_00a25510;
  return extraout_EDX;
}


// ==== FUN_008f40f3 @ 0x008f40f3 ====

undefined4 FUN_008f40f3(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if ((((iVar1 == 0) ||
       (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(param_1 + 0x10)),
       iVar1 == 0)) ||
      (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(param_1 + 0x14)),
      iVar1 == 0)) ||
     (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(param_1 + 0x18)),
     iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// ==== FUN_008f4143 @ 0x008f4143 ====

undefined4 * FUN_008f4143(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(0xf);
  extraout_EDX[0xc] = 0;
  extraout_EDX[0xd] = 0;
  *extraout_EDX = &PTR_FUN_00a2551c;
  return extraout_EDX;
}


// ==== FUN_008f415d @ 0x008f415d ====

undefined4 * FUN_008f415d(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  
  FUN_008f34d1(0xf);
  *extraout_EDX = &PTR_FUN_00a2551c;
  puVar2 = extraout_EDX + 4;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  extraout_EDX[0xc] = param_2;
  extraout_EDX[0xd] = param_3;
  return extraout_EDX;
}


// ==== FUN_008f4192 @ 0x008f4192 ====

bool FUN_008f4192(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if (((iVar1 == 0) || (iVar1 = FUN_008f36a9(), iVar1 == 0)) ||
     (*(int *)(param_1 + 0x30) != *(int *)(in_ECX + 0x30))) {
    return false;
  }
  return *(int *)(param_1 + 0x34) == *(int *)(in_ECX + 0x34);
}


// ==== FUN_008f41d4 @ 0x008f41d4 ====

undefined4 * FUN_008f41d4(void)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(0x11);
  extraout_EDX[4] = 0;
  extraout_EDX[5] = 0;
  *extraout_EDX = &PTR_FUN_00a25528;
  return extraout_EDX;
}


// ==== FUN_008f41ee @ 0x008f41ee ====

undefined4 * FUN_008f41ee(undefined4 param_1,undefined4 param_2)

{
  undefined4 *extraout_EDX;
  
  FUN_008f34d1(0x11);
  extraout_EDX[4] = param_1;
  extraout_EDX[5] = param_2;
  *extraout_EDX = &PTR_FUN_00a25528;
  return extraout_EDX;
}


// ==== FUN_008f4214 @ 0x008f4214 ====

undefined4 FUN_008f4214(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008f34f0(param_1);
  if (((iVar1 == 0) ||
      (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(param_1 + 0x10)),
      iVar1 == 0)) ||
     (iVar1 = FUN_008f350b(*(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(param_1 + 0x14)),
     iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// ==== FUN_008f4255 @ 0x008f4255 ====

undefined4 FUN_008f4255(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x10);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_008f34d1(*(undefined4 *)(in_ECX + 4));
  return uVar2;
}


// ==== FUN_008f4275 @ 0x008f4275 ====

int FUN_008f4275(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  int *piVar3;
  int local_8;
  
  local_8 = 0;
  piVar3 = &local_8;
  while( true ) {
    if (in_ECX == (int *)0x0) {
      return local_8;
    }
    if (in_ECX[1] != 1) break;
    iVar1 = FUN_008bf738(0x14);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_008f356e();
    }
    *piVar3 = iVar1;
    if (iVar1 == 0) {
      return local_8;
    }
    *(int *)(iVar1 + 0x10) = in_ECX[4];
    if (in_ECX[2] != 0) {
      uVar2 = (**(code **)(*(int *)in_ECX[2] + 4))();
      *(undefined4 *)(*piVar3 + 8) = uVar2;
      if (*(int *)(*piVar3 + 8) == 0) {
        *piVar3 = 0;
        return local_8;
      }
    }
    in_ECX = (int *)in_ECX[3];
    piVar3 = (int *)(*piVar3 + 0xc);
  }
  iVar1 = (**(code **)(*in_ECX + 4))();
  *piVar3 = iVar1;
  return local_8;
}


// ==== FUN_008f42ee @ 0x008f42ee ====

int FUN_008f42ee(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x18);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f360d();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    if (*(int *)(in_ECX + 8) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 4))();
      *(int *)(iVar1 + 8) = iVar2;
      if (iVar2 == 0) goto LAB_008f4340;
    }
    if (*(int *)(in_ECX + 0xc) == 0) goto LAB_008f4346;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 4))();
    *(int *)(iVar1 + 0xc) = iVar2;
    if (iVar2 != 0) goto LAB_008f4346;
  }
LAB_008f4340:
  iVar1 = 0;
LAB_008f4346:
  return iVar1;
}


// ==== FUN_008f4349 @ 0x008f4349 ====

void FUN_008f4349(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_008bf738(0x30);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3779();
  }
  if (iVar1 == 0) {
    return;
  }
  puVar3 = (undefined4 *)(in_ECX + 0x10);
  puVar4 = (undefined4 *)(iVar1 + 0x10);
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ==== FUN_008f4379 @ 0x008f4379 ====

int FUN_008f4379(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x20);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f37db();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(in_ECX + 0x18);
    if (*(int *)(in_ECX + 0x1c) == 0) goto LAB_008f43c8;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x1c) + 4))();
    *(int *)(iVar1 + 0x1c) = iVar2;
    if (iVar2 != 0) goto LAB_008f43c8;
  }
  iVar1 = 0;
LAB_008f43c8:
  return iVar1;
}


// ==== FUN_008f43cb @ 0x008f43cb ====

int FUN_008f43cb(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3870();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    if (*(int *)(in_ECX + 0x18) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x18) + 4))();
      *(int *)(iVar1 + 0x18) = iVar2;
      if (iVar2 == 0) goto LAB_008f4438;
    }
    if (*(int *)(in_ECX + 0x1c) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x1c) + 4))();
      *(int *)(iVar1 + 0x1c) = iVar2;
      if (iVar2 == 0) goto LAB_008f4438;
    }
    if (*(int *)(in_ECX + 0x20) == 0) goto LAB_008f443e;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x20) + 4))();
    *(int *)(iVar1 + 0x20) = iVar2;
    if (iVar2 != 0) goto LAB_008f443e;
  }
LAB_008f4438:
  iVar1 = 0;
LAB_008f443e:
  return iVar1;
}


// ==== FUN_008f4441 @ 0x008f4441 ====

int FUN_008f4441(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x30);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f392b();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
    if (*(int *)(in_ECX + 0x14) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
      *(int *)(iVar1 + 0x14) = iVar2;
      if (iVar2 == 0) goto LAB_008f44c0;
    }
    if (*(int *)(in_ECX + 0x18) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x18) + 4))();
      *(int *)(iVar1 + 0x18) = iVar2;
      if (iVar2 == 0) goto LAB_008f44c0;
    }
    if (*(int *)(in_ECX + 0x1c) == 0) goto LAB_008f44c6;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x1c) + 4))();
    *(int *)(iVar1 + 0x1c) = iVar2;
    if (iVar2 != 0) goto LAB_008f44c6;
  }
LAB_008f44c0:
  iVar1 = 0;
LAB_008f44c6:
  return iVar1;
}


// ==== FUN_008f44c9 @ 0x008f44c9 ====

int FUN_008f44c9(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x1c);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3a11();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    if (*(int *)(in_ECX + 0x14) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
      *(int *)(iVar1 + 0x14) = iVar2;
      if (iVar2 == 0) goto LAB_008f451b;
    }
    if (*(int *)(in_ECX + 0x18) == 0) goto LAB_008f4521;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x18) + 4))();
    *(int *)(iVar1 + 0x18) = iVar2;
    if (iVar2 != 0) goto LAB_008f4521;
  }
LAB_008f451b:
  iVar1 = 0;
LAB_008f4521:
  return iVar1;
}


// ==== FUN_008f4524 @ 0x008f4524 ====

int FUN_008f4524(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x18);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3aa3();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    if (*(int *)(in_ECX + 0x10) == 0) goto LAB_008f4567;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
    *(int *)(iVar1 + 0x10) = iVar2;
    if (iVar2 != 0) goto LAB_008f4567;
  }
  iVar1 = 0;
LAB_008f4567:
  return iVar1;
}


// ==== FUN_008f456a @ 0x008f456a ====

void FUN_008f456a(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3b16();
  }
  if (iVar1 == 0) {
    return;
  }
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(in_ECX + 0x20);
  return;
}


// ==== FUN_008f45ab @ 0x008f45ab ====

int FUN_008f45ab(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x40);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f3bba();
  }
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(in_ECX + 0x18);
    *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(in_ECX + 0x38);
    *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(in_ECX + 0x3c);
    if (*(int *)(in_ECX + 0x1c) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x1c) + 4))();
      *(int *)(iVar1 + 0x1c) = iVar2;
      if (iVar2 == 0) goto LAB_008f467e;
    }
    if (*(int *)(in_ECX + 0x20) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x20) + 4))();
      *(int *)(iVar1 + 0x20) = iVar2;
      if (iVar2 == 0) goto LAB_008f467e;
    }
    if (*(int *)(in_ECX + 0x24) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 4))();
      *(int *)(iVar1 + 0x24) = iVar2;
      if (iVar2 == 0) goto LAB_008f467e;
    }
    if (*(int *)(in_ECX + 0x28) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x28) + 4))();
      *(int *)(iVar1 + 0x28) = iVar2;
      if (iVar2 == 0) goto LAB_008f467e;
    }
    if (*(int *)(in_ECX + 0x2c) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x2c) + 4))();
      *(int *)(iVar1 + 0x2c) = iVar2;
      if (iVar2 == 0) goto LAB_008f467e;
    }
    if (*(int *)(in_ECX + 0x30) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x30) + 4))();
      *(int *)(iVar1 + 0x30) = iVar2;
      if (iVar2 == 0) goto LAB_008f467e;
    }
    if (*(int *)(in_ECX + 0x34) == 0) goto LAB_008f4684;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x34) + 4))();
    *(int *)(iVar1 + 0x34) = iVar2;
    if (iVar2 != 0) goto LAB_008f4684;
  }
LAB_008f467e:
  iVar1 = 0;
LAB_008f4684:
  return iVar1;
}


// ==== FUN_008f4688 @ 0x008f4688 ====

int FUN_008f4688(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_8;
  
  iVar1 = FUN_008bf738(0x40);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_008f3cb2();
  }
  if (local_8 != 0) {
    *(undefined4 *)(local_8 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(local_8 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    *(undefined4 *)(local_8 + 0x18) = *(undefined4 *)(in_ECX + 0x18);
    *(undefined4 *)(local_8 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
    *(undefined4 *)(local_8 + 0x34) = *(undefined4 *)(in_ECX + 0x34);
    if (*(int *)(in_ECX + 0x20) != 0) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 4))();
      *(int *)(local_8 + 0x20) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (*(int *)(in_ECX + 0x24) != 0) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x24) + 4))();
      *(int *)(local_8 + 0x24) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (*(int *)(in_ECX + 0x28) != 0) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 4))();
      *(int *)(local_8 + 0x28) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (*(int *)(in_ECX + 0x2c) != 0) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x2c) + 4))();
      *(int *)(local_8 + 0x2c) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (*(int *)(in_ECX + 0x30) != 0) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x30) + 4))();
      *(int *)(local_8 + 0x30) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (*(int *)(in_ECX + 0x34) == 0) {
      return local_8;
    }
    iVar1 = FUN_008f33e7(*(int *)(in_ECX + 0x34) << 2,0x10);
    *(int *)(local_8 + 0x38) = iVar1;
    if (iVar1 != 0) {
      iVar1 = FUN_008f33e7(*(int *)(in_ECX + 0x14) << 2,0x10);
      *(int *)(local_8 + 0x3c) = iVar1;
      if (iVar1 != 0) {
        puVar3 = *(undefined4 **)(in_ECX + 0x38);
        puVar4 = *(undefined4 **)(local_8 + 0x38);
        for (uVar2 = *(uint *)(in_ECX + 0x34) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
          *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
          puVar3 = (undefined4 *)((int)puVar3 + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        puVar3 = *(undefined4 **)(in_ECX + 0x3c);
        puVar4 = *(undefined4 **)(local_8 + 0x3c);
        for (uVar2 = *(uint *)(in_ECX + 0x14) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
          *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
          puVar3 = (undefined4 *)((int)puVar3 + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        return local_8;
      }
    }
  }
  return 0;
}


// ==== FUN_008f4851 @ 0x008f4851 ====

int FUN_008f4851(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_8;
  
  iVar1 = FUN_008bf738(0x50);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_008f3e2e();
  }
  if (local_8 == 0) {
    return 0;
  }
  *(undefined4 *)(local_8 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(local_8 + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(local_8 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
  *(undefined4 *)(local_8 + 0x28) = *(undefined4 *)(in_ECX + 0x28);
  puVar2 = (undefined4 *)(in_ECX + 0x30);
  puVar3 = (undefined4 *)(local_8 + 0x30);
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
    *(int *)(local_8 + 0x10) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (*(int *)(in_ECX + 0x20) != 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 4))();
    *(int *)(local_8 + 0x20) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (*(int *)(in_ECX + 0x24) == 0) {
    return local_8;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x24) + 4))();
  *(int *)(local_8 + 0x24) = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  return local_8;
}


// ==== FUN_008f48fa @ 0x008f48fa ====

int FUN_008f48fa(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_8;
  
  iVar1 = FUN_008bf738(0x40);
  if (iVar1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_008f3f35();
  }
  if (local_8 != 0) {
    *(int *)(local_8 + 0x10) = *(int *)(in_ECX + 0x10);
    *(undefined4 *)(local_8 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    *(undefined4 *)(local_8 + 0x18) = *(undefined4 *)(in_ECX + 0x18);
    *(undefined4 *)(local_8 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
    puVar2 = (undefined4 *)(in_ECX + 0x20);
    puVar3 = (undefined4 *)(local_8 + 0x20);
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    if ((*(int *)(in_ECX + 0x10) != 4) || (*(int *)(in_ECX + 0x18) == 0)) goto LAB_008f4960;
    iVar1 = FUN_008f352c(*(int *)(in_ECX + 0x18));
    *(int *)(in_ECX + 0x18) = iVar1;
    if (iVar1 != 0) goto LAB_008f4960;
  }
  local_8 = 0;
LAB_008f4960:
  return local_8;
}


// ==== FUN_008f4963 @ 0x008f4963 ====

int FUN_008f4963(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x1c);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f40aa();
  }
  if (iVar1 != 0) {
    if (*(int *)(in_ECX + 0x10) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
      *(int *)(iVar1 + 0x10) = iVar2;
      if (iVar2 == 0) goto LAB_008f49c4;
    }
    if (*(int *)(in_ECX + 0x14) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
      *(int *)(iVar1 + 0x14) = iVar2;
      if (iVar2 == 0) goto LAB_008f49c4;
    }
    if (*(int *)(in_ECX + 0x18) == 0) goto LAB_008f49ca;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x18) + 4))();
    *(int *)(iVar1 + 0x18) = iVar2;
    if (iVar2 != 0) goto LAB_008f49ca;
  }
LAB_008f49c4:
  iVar1 = 0;
LAB_008f49ca:
  return iVar1;
}


// ==== FUN_008f49cd @ 0x008f49cd ====

void FUN_008f49cd(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_008bf738(0x38);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f4143();
  }
  if (iVar1 == 0) {
    return;
  }
  puVar3 = (undefined4 *)(in_ECX + 0x10);
  puVar4 = (undefined4 *)(iVar1 + 0x10);
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(in_ECX + 0x30);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(in_ECX + 0x34);
  return;
}


// ==== FUN_008f4a0b @ 0x008f4a0b ====

int FUN_008f4a0b(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_008bf738(0x18);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_008f41d4();
  }
  if (iVar1 != 0) {
    if (*(int *)(in_ECX + 0x10) != 0) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
      *(int *)(iVar1 + 0x10) = iVar2;
      if (iVar2 == 0) goto LAB_008f4a57;
    }
    if (*(int *)(in_ECX + 0x14) == 0) goto LAB_008f4a5d;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
    *(int *)(iVar1 + 0x14) = iVar2;
    if (iVar2 != 0) goto LAB_008f4a5d;
  }
LAB_008f4a57:
  iVar1 = 0;
LAB_008f4a5d:
  return iVar1;
}


// ==== FUN_008f4a60 @ 0x008f4a60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f4a60(void)

{
  undefined4 *in_ECX;
  
  *(undefined8 *)(in_ECX + 0x2c) = _DAT_00a168b8;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[6] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0x7ff00000;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0xfff00000;
  return;
}


// ==== FUN_008f4adb @ 0x008f4adb ====

void FUN_008f4adb(byte param_1)

{
  undefined4 in_ECX;
  
  FUN_0095cf1d();
  if ((param_1 & 1) != 0) {
    FUN_00914a24(in_ECX);
  }
  return;
}


// ==== FUN_008f4afb @ 0x008f4afb ====

undefined4 FUN_008f4afb(uint param_1)

{
  void *pvVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  
  uVar3 = *(uint *)(in_ECX + 0x94);
  if (uVar3 < param_1) {
    if (uVar3 == 0) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = uVar3 * 2;
    }
    for (; uVar3 < param_1; uVar3 = uVar3 * 2) {
    }
    pvVar1 = operator_new(uVar3 << 2);
    uVar2 = 0;
    if (pvVar1 != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x90));
      return extraout_EAX;
    }
  }
  else {
    uVar2 = *(undefined4 *)(in_ECX + 0x90);
  }
  return uVar2;
}


// ==== FUN_008f4b5e @ 0x008f4b5e ====

undefined4 * FUN_008f4b5e(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 + 2;
  if (*(uint *)(in_ECX + 0x8c) < uVar2) {
    uVar3 = uVar2;
    if (uVar2 < 0x2000) {
      uVar3 = 0x2000;
    }
    puVar1 = operator_new(uVar3 << 2);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    *puVar1 = *(undefined4 *)(in_ECX + 0x88);
    puVar1[1] = -*(int *)(in_ECX + 0x8c);
    *(undefined4 **)(in_ECX + 0x88) = puVar1;
    *(uint *)(in_ECX + 0x8c) = uVar3;
  }
  else {
    puVar1 = *(undefined4 **)(in_ECX + 0x88);
    *puVar1 = puVar1;
    puVar1[1] = *(undefined4 *)(in_ECX + 0x8c);
  }
  *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) - uVar2;
  *(int *)(in_ECX + 0x88) = *(int *)(in_ECX + 0x88) + uVar2 * 4;
  return puVar1 + 2;
}


// ==== FUN_008f4bdf @ 0x008f4bdf ====

void FUN_008f4bdf(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + -8);
    iVar1 = *(int *)(param_1 + -4);
    if (iVar1 < 1) {
      *(int *)(in_ECX + 0x8c) = -iVar1;
      _free((undefined4 *)(param_1 + -8));
      return;
    }
    *(int *)(in_ECX + 0x8c) = iVar1;
  }
  return;
}


// ==== FUN_008f4c18 @ 0x008f4c18 ====

undefined4 FUN_008f4c18(undefined4 *param_1,int param_2)

{
  if (param_2 != 0) {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      *param_1 = 0xffffffff;
      param_1 = param_1 + 1;
    }
  }
  return 0;
}


// ==== FUN_008f4c34 @ 0x008f4c34 ====

undefined4
FUN_008f4c34(uint *param_1,uint param_2,uint param_3,uint *param_4,uint *param_5,uint param_6,
            int *param_7,undefined4 param_8,int *param_9)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_1c;
  int local_c;
  int local_8;
  
  uVar7 = param_2;
  iVar6 = param_2 * param_3;
  if (iVar6 != 0) {
    if ((param_1 == (uint *)0x2) && (((uint)param_4 & 0x400) == 0)) {
      param_2 = param_3;
      bVar3 = true;
      param_3 = uVar7;
    }
    else {
      bVar3 = false;
    }
    uVar7 = param_3 + 3 >> 2;
    iVar8 = uVar7 * param_2;
    if (param_6 < *(uint *)(*(int *)(in_ECX + 8) + 4)) {
      iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + param_6 * 4);
    }
    else {
      iVar5 = 0;
    }
    if (iVar5 == 0) {
      return 0x80004005;
    }
    iVar2 = *(int *)(iVar5 + 0x10);
    iVar1 = iVar2 + iVar8;
    *(int *)(iVar5 + 0x10) = iVar1;
    if ((*(byte *)(iVar5 + 4) & 0x40) != 0) {
      *(int *)(iVar5 + 8) = iVar1;
    }
    if (param_2 != 0) {
      local_c = 0;
      local_8 = 0;
      param_4 = param_5;
      local_1c = param_2;
      do {
        uVar9 = 0;
        if (param_3 != 0) {
          param_1 = param_4;
          do {
            if (bVar3) {
              uVar4 = *param_1;
            }
            else {
              uVar4 = param_5[local_8 + uVar9];
            }
            if (uVar4 < *(uint *)(*(int *)(in_ECX + 8) + 8)) {
              iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + uVar4 * 4);
            }
            else {
              iVar5 = 0;
            }
            if (iVar5 != 0) {
              *(uint *)(iVar5 + 4) = param_6;
              iVar1 = (uVar9 >> 2) + local_c + iVar2;
              *(undefined4 *)(iVar5 + 0x68) = param_8;
              *(int *)(iVar5 + 0xc) = iVar1;
              *(uint *)(iVar5 + 0x10) = uVar9 & 3;
              *(uint *)(iVar5 + 0x70) = *param_7 + (iVar1 - iVar2) * 4 + (uVar9 & 3);
            }
            param_1 = param_1 + param_2;
            uVar9 = uVar9 + 1;
          } while (uVar9 < param_3);
        }
        param_4 = param_4 + 1;
        local_8 = local_8 + param_3;
        local_c = local_c + uVar7;
        local_1c = local_1c - 1;
      } while (local_1c != 0);
    }
    *param_7 = *param_7 + iVar8 * 4;
  }
  if (param_9 != (int *)0x0) {
    *param_9 = iVar6;
  }
  return 0;
}


// ==== FUN_008f4d96 @ 0x008f4d96 ====

undefined4 FUN_008f4d96(uint param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  iVar3 = param_1;
  uVar7 = 0;
  if (((*(int *)(param_1 + 0x14) == 0) || (*(int *)(param_1 + 0x28) == 0)) ||
     (*(int *)(param_1 + 0x38) != 0)) {
LAB_008f4ed0:
    uVar5 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x34) = 0;
    if (*(int *)(param_1 + 0x14) != 0) {
      iVar6 = *(int *)(param_1 + 0x10) << 2;
      do {
        uVar4 = *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                                 *(int *)(iVar6 + *(int *)(in_ECX + 0x18)) * 4) + 0x70) + 1;
        if (*(uint *)(param_1 + 0x34) < uVar4) {
          *(uint *)(param_1 + 0x34) = uVar4;
        }
        uVar7 = uVar7 + 1;
        iVar6 = iVar6 + 4;
      } while (uVar7 < *(uint *)(param_1 + 0x14));
    }
    iVar6 = FUN_008f33e7(*(int *)(param_1 + 0x34) << 2,0x10);
    *(int *)(param_1 + 0x38) = iVar6;
    if (iVar6 != 0) {
      iVar6 = FUN_008f33e7(*(int *)(param_1 + 0x14) << 2,0x10);
      *(int *)(param_1 + 0x3c) = iVar6;
      if (iVar6 != 0) {
        puVar1 = (uint *)(param_1 + 0x34);
        puVar8 = (undefined4 *)(param_1 + 0x38);
        param_1 = 0;
        puVar8 = (undefined4 *)*puVar8;
        for (uVar7 = *puVar1 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar8 = 0;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        puVar8 = *(undefined4 **)(iVar3 + 0x3c);
        for (uVar7 = *(uint *)(iVar3 + 0x14) & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar8 = 0;
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
        iVar6 = *(int *)(*(int *)(iVar3 + 0x28) + 0x20);
        if (*(int *)(iVar3 + 0x14) != 0) {
          do {
            if (iVar6 == 0) break;
            iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                            *(int *)(*(int *)(in_ECX + 0x18) +
                                    (*(int *)(iVar3 + 0x10) + param_1) * 4) * 4);
            if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(iVar2 + 4) * 4)
                          + 4) & 0x80) == 0) {
              *(int *)(*(int *)(iVar3 + 0x38) + *(int *)(iVar2 + 0x70) * 4) =
                   *(int *)(iVar6 + 8) + 0x10;
              *(int *)(*(int *)(iVar3 + 0x3c) + *(int *)(iVar2 + 100) * 4) =
                   *(int *)(iVar6 + 8) + 0x10;
            }
            param_1 = param_1 + 1;
            iVar6 = *(int *)(iVar6 + 0xc);
          } while (param_1 < *(uint *)(iVar3 + 0x14));
        }
        goto LAB_008f4ed0;
      }
    }
    uVar5 = 0x8007000e;
  }
  return uVar5;
}


// ==== FUN_008f4ed9 @ 0x008f4ed9 ====

void FUN_008f4ed9(double *param_1,double *param_2,double *param_3,byte param_4)

{
  double *pdVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  double local_24 [4];
  
  local_24[0] = *param_2 * *param_3;
  uVar3 = 0;
  local_24[1] = *param_2 * param_3[1];
  local_24[2] = *param_3 * param_2[1];
  local_24[3] = param_2[1] * param_3[1];
  *param_1 = *(double *)(in_ECX + 0xa0);
  param_1[1] = *(double *)(in_ECX + 0xa8);
  do {
    pdVar1 = local_24 + uVar3;
    iVar2 = __isnan(*pdVar1);
    if (iVar2 != 0) {
      if ((param_4 & 0x40) != 0) {
        *param_1 = local_24[uVar3];
        param_1[1] = local_24[uVar3];
        return;
      }
      *pdVar1 = 0.0;
    }
    if (*pdVar1 < *param_1) {
      *param_1 = *pdVar1;
    }
    if (param_1[1] < *pdVar1) {
      param_1[1] = *pdVar1;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 4);
  return;
}


// ==== FUN_008f4f7c @ 0x008f4f7c ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008f4f7c(uint param_1,double *param_2)

{
  double dVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  float10 fVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  float10 fVar13;
  undefined4 uVar14;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  undefined8 local_10;
  int local_8;
  
  iVar6 = *(int *)(in_ECX + 8);
  puVar2 = *(uint **)(*(int *)(iVar6 + 0x14) + param_1 * 4);
  if ((*puVar2 & 0x100) != 0) {
    if (param_2 == (double *)0x0) {
      return 0;
    }
    *param_2 = *(double *)(puVar2 + 8);
    dVar1 = *(double *)(puVar2 + 10);
LAB_008f4fc2:
    param_2[1] = dVar1;
    return 0;
  }
  if ((char)*puVar2 < '\0') {
    if (param_2 == (double *)0x0) {
      return 0;
    }
    *param_2 = *(double *)(puVar2 + 8);
    dVar1 = *(double *)(puVar2 + 8);
    goto LAB_008f4fc2;
  }
  local_38 = *(double *)(in_ECX + 0xa8);
  local_30 = *(double *)(in_ECX + 0xa0);
  local_8 = in_ECX;
  if (puVar2[2] == 0xffffffff) {
    if (((*(byte *)(*(int *)(*(int *)(iVar6 + 0x10) + puVar2[1] * 4) + 4) & 2) != 0) &&
       (puVar2[0x12] != 0xffffffff)) {
      puVar4 = *(uint **)(*(int *)(iVar6 + 0x18) + puVar2[0x12] * 4);
      uVar7 = *puVar4;
      uVar11 = puVar2[4];
      if ((uVar7 & 0xf0000000) == 0x10000000) {
        uVar7 = uVar7 & 0xfff00000;
        if (((((uVar7 != 0x10f00000) && (uVar7 != 0x11000000)) && (uVar7 != 0x11100000)) &&
            ((uVar7 != 0x11200000 && (uVar7 != 0x11300000)))) &&
           ((uVar7 != 0x11400000 && (uVar7 != 0x11500000)))) {
          iVar6 = FUN_008f4f7c(*(undefined4 *)(puVar4[2] + uVar11 * 4),&local_28);
          if (iVar6 < 0) goto LAB_008f5a3a;
          uVar7 = *puVar4 & 0xfff00000;
          uVar12 = SUB84(local_28,0);
          uVar14 = (undefined4)((ulonglong)local_28 >> 0x20);
          if (uVar7 < 0x10700001) {
            if (uVar7 == 0x10700000) {
              if (local_28 < _DAT_0099d098) goto LAB_008f5aa2;
              local_38 = _DAT_0099d0a0 / SQRT(local_20);
              fVar13 = (float10)_DAT_0099d0a0 / SQRT((float10)local_28);
            }
            else if (uVar7 == 0x10000000) {
LAB_008f5885:
              local_38 = local_28;
LAB_008f58d2:
              fVar13 = (float10)local_20;
            }
            else if (uVar7 == 0x10100000) {
              local_38 = -local_20;
              fVar13 = -(float10)local_28;
            }
            else if (uVar7 == 0x10200000) {
              if (_DAT_0099d098 <= local_28) {
                if (local_28 == _DAT_0099d098) {
                  local_38 = 0.0;
                }
                else {
                  local_38 = local_28 + *(double *)(local_8 + 0xb0);
                }
              }
              else {
                local_38 = local_28 - *(double *)(local_8 + 0xb0);
              }
              if (_DAT_0099d098 <= local_20) {
                if (local_20 == _DAT_0099d098) goto LAB_008f5a16;
                fVar13 = (float10)local_20 + (float10)*(double *)(local_8 + 0xb0);
              }
              else {
                fVar13 = (float10)local_20 - (float10)*(double *)(local_8 + 0xb0);
              }
            }
            else if (uVar7 == 0x10300000) {
              if ((local_28 <= _DAT_0099d098) && (_DAT_0099d098 <= local_20)) goto LAB_008f5aa2;
              local_38 = 1.0 / local_20;
              fVar13 = (float10)1 / (float10)local_28;
            }
            else {
              if (uVar7 == 0x10400000) {
                if (local_28 != local_20) goto LAB_008f55c6;
                iVar6 = FUN_00803910(uVar12,uVar14);
                if (iVar6 != 0) {
                  fVar13 = (float10)FUN_008044f0(SUB84(local_20,0),
                                                 (int)((ulonglong)local_20 >> 0x20));
                  fVar13 = (float10)local_28 - fVar13;
                  goto LAB_008f5a85;
                }
                goto LAB_008f53c0;
              }
              if (uVar7 == 0x10500000) {
                fVar13 = (float10)FUN_00801f40();
LAB_008f59c4:
                local_38 = (double)fVar13;
                fVar13 = (float10)FUN_00801f40();
              }
              else {
                if (uVar7 != 0x10600000) goto LAB_008f5aa2;
                if (local_28 <= _DAT_0099d098) {
                  fVar13 = (float10)*(double *)(local_8 + 0xa8);
                }
                else {
                  fVar13 = (float10)log2((float10)local_28);
                  fVar5 = (float10)log2((float10)_DAT_00a0b350);
                  fVar13 = ((float10)0.6931471805599453 * fVar13) /
                           ((float10)0.6931471805599453 * fVar5);
                }
                local_38 = (double)fVar13;
                if (_DAT_0099d098 < local_20) {
                  fVar13 = (float10)log2((float10)local_20);
                  fVar5 = (float10)log2((float10)_DAT_00a0b350);
                  fVar13 = ((float10)0.6931471805599453 * fVar13) /
                           ((float10)0.6931471805599453 * fVar5);
                }
                else {
                  fVar13 = (float10)*(double *)(local_8 + 0xa8);
                }
              }
            }
            goto LAB_008f5a9f;
          }
          if (uVar7 == 0x10800000) {
            if ((local_28 != local_20) || (iVar6 = FUN_00803910(uVar12,uVar14), iVar6 == 0)) {
LAB_008f5a94:
              local_38 = _DAT_009fd350;
              goto LAB_008f5a9a;
            }
            dVar1 = local_28;
LAB_008f5a83:
            fVar13 = (float10)fsin((float10)dVar1);
          }
          else {
            if (uVar7 != 0x10900000) {
              if (uVar7 == 0x10a00000) {
                if ((local_28 < _DAT_009fd350) ||
                   ((NAN(local_20) || NAN(_DAT_0099d0a0)) ||
                    local_20 < _DAT_0099d0a0 == (local_20 == _DAT_0099d0a0))) goto LAB_008f5477;
                fVar13 = (float10)FUN_00801e30();
                local_38 = (double)fVar13;
                fVar13 = (float10)FUN_00801e30();
              }
              else if (uVar7 == 0x10b00000) {
                if ((local_28 < _DAT_009fd350) ||
                   ((NAN(local_20) || NAN(_DAT_0099d0a0)) ||
                    local_20 < _DAT_0099d0a0 == (local_20 == _DAT_0099d0a0))) {
                  local_38 = 0.0;
                  goto LAB_008f56c7;
                }
                fVar13 = (float10)FUN_00801d60();
                local_38 = (double)fVar13;
                fVar13 = (float10)FUN_00801d60();
              }
              else {
                if (uVar7 != 0x10c00000) {
                  if ((((uVar7 == 0x10d00000) || (uVar7 == 0x10e00000)) && (local_28 == local_20))
                     && (iVar6 = FUN_00803910(uVar12,uVar14), iVar6 != 0)) goto LAB_008f53c0;
                  goto LAB_008f5aa2;
                }
                if ((local_28 == local_20) && (iVar6 = FUN_00803910(uVar12,uVar14), iVar6 != 0)) {
                  fVar13 = (float10)1;
                  local_18 = local_28;
                  goto LAB_008f53f9;
                }
LAB_008f5477:
                local_38 = _DAT_00a25550;
                fVar13 = (float10)_DAT_00a25548;
              }
              goto LAB_008f5a9f;
            }
            if ((local_28 != local_20) || (iVar6 = FUN_00803910(uVar12,uVar14), iVar6 == 0))
            goto LAB_008f5a94;
            dVar1 = local_28;
LAB_008f5a90:
            fVar13 = (float10)fcos((float10)dVar1);
          }
LAB_008f5a85:
          local_30 = (double)fVar13;
          local_38 = (double)fVar13;
        }
      }
      else if ((uVar7 & 0xf0000000) == 0x20000000) {
        if ((uVar7 & 0xfff00000) != 0x20900000) {
          iVar6 = FUN_008f4f7c(*(undefined4 *)(puVar4[2] + uVar11 * 4),&local_18);
          if ((iVar6 < 0) ||
             (iVar6 = FUN_008f4f7c(*(undefined4 *)(puVar4[2] + (puVar4[3] + uVar11) * 4),&local_28),
             iVar6 < 0)) goto LAB_008f5a3a;
          uVar7 = *puVar4 & 0xfff00000;
          if (uVar7 < 0x20400001) {
            if (uVar7 == 0x20400000) {
              local_38 = local_28 + local_18;
              fVar13 = (float10)local_20 + (float10)local_10;
            }
            else {
              if (uVar7 != 0x20000000) {
                if (uVar7 == 0x20100000) {
                  if (local_18 <= local_28) goto LAB_008f5653;
                  goto LAB_008f5656;
                }
                if (uVar7 == 0x20200000) {
                  if (local_18 < local_20) {
                    if (local_10 < local_28) goto LAB_008f55a1;
LAB_008f55c6:
                    local_38 = 0.0;
                    goto LAB_008f5a9a;
                  }
                }
                else {
                  if (uVar7 != 0x20300000) goto LAB_008f5aa2;
                  if (local_28 <= local_10) {
                    if (local_18 < local_20) goto LAB_008f55c6;
                    goto LAB_008f55a1;
                  }
                }
                goto LAB_008f53c0;
              }
              if (local_28 <= local_18) {
                local_18 = local_28;
              }
              local_38 = local_18;
              if (local_20 <= local_10) goto LAB_008f58d2;
LAB_008f566a:
              fVar13 = (float10)local_10;
            }
LAB_008f5a9f:
            local_30 = (double)fVar13;
          }
          else if (uVar7 == 0x20500000) {
            FUN_008f4ed9(&local_38,&local_18,&local_28,*puVar2);
          }
          else {
            if (uVar7 == 0x20600000) {
              if ((((local_18 == local_10) &&
                   (iVar6 = FUN_00803910(SUB84(local_18,0),(int)((ulonglong)local_18 >> 0x20)),
                   iVar6 != 0)) && (local_28 == local_20)) &&
                 (iVar6 = FUN_00803910(SUB84(local_28,0),(int)((ulonglong)local_28 >> 0x20)),
                 iVar6 != 0)) {
                fVar13 = (float10)local_28;
LAB_008f53f9:
                fVar13 = (float10)fpatan((float10)local_18,fVar13);
                goto LAB_008f5a85;
              }
              local_38 = _DAT_00a25540;
LAB_008f56c7:
              fVar13 = (float10)_DAT_00a25538;
              goto LAB_008f5a9f;
            }
            if ((uVar7 == 0x20700000) || (uVar7 == 0x20800000)) {
              if (local_28 <= local_18) {
LAB_008f5653:
                local_18 = local_28;
              }
LAB_008f5656:
              local_38 = local_18;
              if (local_10 <= local_20) goto LAB_008f58d2;
              goto LAB_008f566a;
            }
          }
        }
      }
      else {
        uVar10 = uVar7 & 0xfff00000;
        if (uVar10 == 0x50000000) {
          local_38 = 0.0;
          local_10 = (double)(CONCAT44(uVar7,(undefined4)local_10) & 0xfffffffffffff);
          local_30 = 0.0;
          uVar11 = 0;
          if ((uVar7 & 0xfffff) != 0) {
            param_1 = (uVar7 & 0xfffff) << 2;
            do {
              iVar6 = FUN_008f4f7c(*(undefined4 *)(puVar4[2] + uVar11 * 4),&local_28);
              if ((iVar6 < 0) ||
                 (iVar6 = FUN_008f4f7c(*(undefined4 *)(param_1 + puVar4[2]),&local_48), iVar6 < 0))
              goto LAB_008f5a3a;
              FUN_008f4ed9(&local_58,&local_28,&local_48,*puVar2);
              local_38 = local_58 + local_38;
              param_1 = param_1 + 4;
              uVar11 = uVar11 + 1;
              local_30 = local_50 + local_30;
            } while (uVar11 < local_10._4_4_);
          }
        }
        else {
          if (uVar10 == 0x30000000) {
            uVar7 = puVar4[2];
            iVar6 = *(int *)(uVar7 + uVar11 * 4);
            iVar3 = *(int *)(uVar7 + (uVar11 + puVar4[3] * 2) * 4);
            local_10 = (double)CONCAT44(*(undefined4 *)(uVar7 + (puVar4[3] + uVar11) * 4),
                                        (undefined4)local_10);
            iVar8 = FUN_008f4f7c(iVar6,&local_58);
            if (-1 < iVar8) {
              iVar8 = FUN_008f4f7c(local_10._4_4_,&local_28);
              if ((-1 < iVar8) && (iVar8 = FUN_008f4f7c(iVar3,&local_48), -1 < iVar8)) {
                if ((*puVar4 & 0xfff00000) == 0x30000000) {
                  if (iVar6 == local_10._4_4_) {
                    if (local_28 < _DAT_0099d098) {
                      local_28 = 0.0;
                    }
                    if (local_20 < _DAT_0099d098) {
                      local_20 = 0.0;
                    }
                  }
                  if (iVar6 == iVar3) {
                    if (_DAT_0099d098 < local_48) {
                      local_48 = 0.0;
                    }
                    fVar13 = (float10)local_40;
                    if ((float10)_DAT_0099d098 < fVar13) {
                      fVar13 = (float10)0;
                    }
                  }
                  else {
                    fVar13 = (float10)local_40;
                  }
                  if (_DAT_0099d098 <= local_58) goto LAB_008f5885;
                  if (_DAT_0099d098 <= local_50) {
                    if (local_48 <= local_28) {
                      local_38 = local_48;
                    }
                    else {
                      local_38 = local_28;
                    }
                    if (fVar13 < (float10)local_20) goto LAB_008f58d2;
                  }
                  else {
                    local_38 = local_48;
                  }
                  goto LAB_008f5a9f;
                }
                goto LAB_008f5aa2;
              }
            }
            goto LAB_008f5a3a;
          }
          if (uVar10 == 0x50100000) {
            if (uVar11 != 0) {
              if (uVar11 == 1) {
                iVar6 = FUN_008f4f7c(*(undefined4 *)puVar4[2],&local_48);
                if (iVar6 < 0) goto LAB_008f5a3a;
                if (local_48 <= _DAT_0099d098) {
                  local_38 = 0.0;
                  if ((!NAN(local_40) && !NAN(_DAT_0099d098)) &&
                      local_40 < _DAT_0099d098 != (local_40 == _DAT_0099d098)) goto LAB_008f5a16;
                }
                else {
                  local_38 = local_48;
                }
                fVar13 = (float10)local_40;
                goto LAB_008f5a9f;
              }
              if (uVar11 == 2) {
                iVar6 = FUN_008f4f7c(*(undefined4 *)puVar4[2],&local_48);
                if (-1 < iVar6) {
                  if ((!NAN(local_40) && !NAN(_DAT_0099d098)) &&
                      local_40 < _DAT_0099d098 != (local_40 == _DAT_0099d098)) {
LAB_008f53c0:
                    local_38 = 0.0;
LAB_008f5a16:
                    fVar13 = (float10)0;
                    goto LAB_008f5a9f;
                  }
                  iVar6 = FUN_008f4f7c(*(undefined4 *)(puVar4[2] + 4),&local_28);
                  if (-1 < iVar6) {
                    if ((!NAN(local_20) && !NAN(_DAT_0099d098)) &&
                        local_20 < _DAT_0099d098 != (local_20 == _DAT_0099d098)) goto LAB_008f53c0;
                    iVar6 = FUN_008f4f7c(*(undefined4 *)(puVar4[2] + 0xc),&local_58);
                    if (-1 < iVar6) {
                      fVar13 = (float10)FUN_00801f40();
                      if (_DAT_0099d0a0 <= local_20) {
                        local_58 = local_50;
                      }
                      local_10 = local_58;
                      goto LAB_008f59c4;
                    }
                  }
                }
LAB_008f5a3a:
                local_38 = *(double *)(local_8 + 0xa8);
                uVar12 = 0x80004005;
                local_30 = *(double *)(local_8 + 0xa0);
                goto LAB_008f5aa4;
              }
              if (uVar11 != 3) goto LAB_008f5aa2;
            }
LAB_008f55a1:
            local_38 = 1.0;
LAB_008f5a9a:
            fVar13 = (float10)1;
            goto LAB_008f5a9f;
          }
          if (uVar10 == 0x50300000) {
            iVar6 = FUN_008f4f7c(*(undefined4 *)puVar4[2],&local_48);
            if (iVar6 < 0) goto LAB_008f5a3a;
            if ((local_48 != local_40) ||
               (iVar6 = FUN_00803910(SUB84(local_48,0),(int)((ulonglong)local_48 >> 0x20)),
               iVar6 == 0)) goto LAB_008f5a94;
            if (uVar11 == 0) {
              dVar1 = local_48;
              goto LAB_008f5a90;
            }
            if (uVar11 == 1) {
              dVar1 = local_48;
              goto LAB_008f5a83;
            }
          }
        }
      }
    }
  }
  else {
    iVar6 = FUN_008f683e(puVar2[2],&local_20);
    if (-1 < iVar6) {
      iVar6 = __ftol();
      uVar7 = *(uint *)(*(int *)(in_ECX + 8) + 8);
      param_1 = 0;
      local_10 = (double)CONCAT44(uVar7,(undefined4)local_10);
      if (uVar7 != 0) {
        piVar9 = *(int **)(*(int *)(in_ECX + 8) + 0x14);
        do {
          iVar3 = *piVar9;
          if ((((*(uint *)(iVar3 + 4) == puVar2[1]) && (*(int *)(iVar3 + 8) == -1)) &&
              (*(int *)(iVar3 + 0xc) == iVar6 + puVar2[3])) &&
             (*(uint *)(iVar3 + 0x10) == puVar2[4])) {
            iVar6 = FUN_008f4f7c(param_1,&local_38);
            if (iVar6 < 0) goto LAB_008f5a3a;
            break;
          }
          param_1 = param_1 + 1;
          piVar9 = piVar9 + 1;
        } while (param_1 < uVar7);
      }
    }
  }
LAB_008f5aa2:
  uVar12 = 0;
LAB_008f5aa4:
  if ((*puVar2 & 4) == 0) {
    if (_DAT_0099d098 <= local_38) {
      *puVar2 = *puVar2 | 4;
    }
  }
  else {
    if (_DAT_0099d098 > local_38 || local_38 == _DAT_0099d098) {
      local_38 = 0.0;
    }
    if (local_30 <= _DAT_0099d098) {
      local_30 = 0.0;
    }
  }
  if ((*puVar2 & 8) == 0) {
    if ((!NAN(local_30) && !NAN(_DAT_0099d098)) &&
        local_30 < _DAT_0099d098 != (local_30 == _DAT_0099d098)) {
      *puVar2 = *puVar2 | 8;
    }
  }
  else {
    if (_DAT_0099d098 <= local_38) {
      local_38 = 0.0;
    }
    if (_DAT_0099d098 <= local_30) {
      local_30 = 0.0;
    }
  }
  if ((*puVar2 & 0x10) == 0) {
    if ((_DAT_009fd350 <= local_38) &&
       ((!NAN(local_30) && !NAN(_DAT_0099d0a0)) &&
        local_30 < _DAT_0099d0a0 != (local_30 == _DAT_0099d0a0))) {
      *puVar2 = *puVar2 | 0x10;
    }
  }
  else {
    if (_DAT_009fd350 > local_38 || local_38 == _DAT_009fd350) {
      local_38 = _DAT_009fd350;
    }
    if (local_30 <= _DAT_009fd350) {
      local_30 = _DAT_009fd350;
    }
    if (_DAT_0099d0a0 <= local_38) {
      local_38 = 1.0;
    }
    if (_DAT_0099d0a0 <= local_30) {
      local_30 = 1.0;
    }
  }
  if ((local_38 == local_30) &&
     (iVar6 = FUN_00803910(SUB84(local_38,0),(int)((ulonglong)local_38 >> 0x20)), iVar6 != 0)) {
    *(byte *)puVar2 = (byte)*puVar2 | 0x80;
    if ((_DAT_0099d098 == local_38) || (_DAT_0099d0a0 == local_38)) {
      *puVar2 = *puVar2 | 1;
    }
    iVar6 = __ftol();
    if (ABS(local_38 - (double)iVar6) < _DAT_00a168b8) {
      *puVar2 = *puVar2 | 2;
    }
  }
  *(double *)(puVar2 + 8) = local_38;
  *(byte *)((int)puVar2 + 1) = *(byte *)((int)puVar2 + 1) | 1;
  *(double *)(puVar2 + 10) = local_30;
  if (param_2 != (double *)0x0) {
    *param_2 = local_38;
    param_2[1] = local_30;
  }
  return uVar12;
}


// ==== FUN_008f5c46 @ 0x008f5c46 ====

undefined4 FUN_008f5c46(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  uVar3 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = *(uint *)(param_1 + uVar3 * 4);
      if (uVar1 < *(uint *)(*(int *)(in_ECX + 8) + 8)) {
        iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + uVar1 * 4);
      }
      else {
        iVar2 = 0;
      }
      if ((iVar2 == 0) || (*(int *)(iVar2 + 0x68) == 0)) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_2);
  }
  return 1;
}


// ==== FUN_008f5c8b @ 0x008f5c8b ====

bool FUN_008f5c8b(int *param_1,int *param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  bool bVar4;
  uint local_c;
  int *local_8;
  
  if (param_2 == (int *)0x2) {
    bVar4 = false;
    if (param_3 * param_4 != 0) {
      local_c = 0;
      if (param_4 != 0) {
        piVar3 = param_1;
        do {
          iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar3 * 4);
          param_2 = (int *)0x0;
          if (param_3 != 0) {
            local_8 = piVar3;
            do {
              iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *local_8 * 4);
              if (*(int *)(iVar1 + 4) != *(int *)(iVar2 + 4)) goto LAB_008f5e11;
              if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) +
                                     *(int *)(iVar1 + 4) * 4) + 4) & 0x40) == 0) {
                bVar4 = *(int *)(iVar1 + 0x48) == *(int *)(iVar2 + 0x48);
              }
              else {
                if (((uint)param_2 >> 2) + *(int *)(iVar1 + 0xc) != *(int *)(iVar2 + 0xc))
                goto LAB_008f5e11;
                bVar4 = ((uint)param_2 & 3) + *(int *)(iVar1 + 0x10) == *(int *)(iVar2 + 0x10);
              }
              if (!bVar4) goto LAB_008f5e11;
              param_2 = (int *)((int)param_2 + 1);
              local_8 = local_8 + param_4;
            } while (param_2 < param_3);
          }
          local_c = local_c + 1;
          piVar3 = piVar3 + 1;
        } while (local_c < param_4);
      }
      local_c = 0;
      if (param_3 != 0) {
        piVar3 = param_1;
        do {
          iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar3 * 4);
          param_1 = (int *)0x0;
          if (param_4 != 0) {
            param_2 = piVar3;
            do {
              iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *param_2 * 4);
              if (*(int *)(iVar1 + 4) != *(int *)(iVar2 + 4)) {
                return false;
              }
              if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) +
                                     *(int *)(iVar1 + 4) * 4) + 4) & 0x40) == 0) {
                bVar4 = *(int *)(iVar1 + 0x48) == *(int *)(iVar2 + 0x48);
              }
              else {
                if (((uint)param_1 >> 2) + *(int *)(iVar1 + 0xc) != *(int *)(iVar2 + 0xc)) {
                  return false;
                }
                bVar4 = ((uint)param_1 & 3) + *(int *)(iVar1 + 0x10) == *(int *)(iVar2 + 0x10);
              }
              if (!bVar4) {
                return false;
              }
              param_1 = (int *)((int)param_1 + 1);
              param_2 = param_2 + 1;
            } while (param_1 < param_4);
          }
          local_c = local_c + 1;
          piVar3 = piVar3 + param_4;
        } while (local_c < param_3);
      }
LAB_008f5e11:
      bVar4 = true;
    }
  }
  else {
    bVar4 = param_3 == 1;
  }
  return bVar4;
}


// ==== FUN_008f5e1f @ 0x008f5e1f ====

bool FUN_008f5e1f(int *param_1,int *param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  bool bVar4;
  uint local_c;
  int *local_8;
  
  if (param_2 == (int *)0x2) {
    bVar4 = false;
    if (param_3 * param_4 != 0) {
      local_c = 0;
      if (param_3 != 0) {
        piVar3 = param_1;
        do {
          iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar3 * 4);
          param_2 = (int *)0x0;
          if (param_4 != 0) {
            local_8 = piVar3;
            do {
              iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *local_8 * 4);
              if (*(int *)(iVar1 + 4) != *(int *)(iVar2 + 4)) goto LAB_008f5fa7;
              if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) +
                                     *(int *)(iVar1 + 4) * 4) + 4) & 0x40) == 0) {
                bVar4 = *(int *)(iVar1 + 0x48) == *(int *)(iVar2 + 0x48);
              }
              else {
                if (((uint)param_2 >> 2) + *(int *)(iVar1 + 0xc) != *(int *)(iVar2 + 0xc))
                goto LAB_008f5fa7;
                bVar4 = ((uint)param_2 & 3) + *(int *)(iVar1 + 0x10) == *(int *)(iVar2 + 0x10);
              }
              if (!bVar4) goto LAB_008f5fa7;
              param_2 = (int *)((int)param_2 + 1);
              local_8 = local_8 + 1;
            } while (param_2 < param_4);
          }
          local_c = local_c + 1;
          piVar3 = piVar3 + param_4;
        } while (local_c < param_3);
      }
      local_c = 0;
      if (param_4 != 0) {
        piVar3 = param_1;
        do {
          iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar3 * 4);
          param_1 = (int *)0x0;
          if (param_3 != 0) {
            param_2 = piVar3;
            do {
              iVar2 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *param_2 * 4);
              if (*(int *)(iVar1 + 4) != *(int *)(iVar2 + 4)) {
                return false;
              }
              if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) +
                                     *(int *)(iVar1 + 4) * 4) + 4) & 0x40) == 0) {
                bVar4 = *(int *)(iVar1 + 0x48) == *(int *)(iVar2 + 0x48);
              }
              else {
                if (((uint)param_1 >> 2) + *(int *)(iVar1 + 0xc) != *(int *)(iVar2 + 0xc)) {
                  return false;
                }
                bVar4 = ((uint)param_1 & 3) + *(int *)(iVar1 + 0x10) == *(int *)(iVar2 + 0x10);
              }
              if (!bVar4) {
                return false;
              }
              param_1 = (int *)((int)param_1 + 1);
              param_2 = param_2 + param_4;
            } while (param_1 < param_3);
          }
          local_c = local_c + 1;
          piVar3 = piVar3 + 1;
        } while (local_c < param_4);
      }
LAB_008f5fa7:
      bVar4 = true;
    }
  }
  else {
    bVar4 = 1 < param_3;
  }
  return bVar4;
}


// ==== FUN_008f5fb5 @ 0x008f5fb5 ====

int FUN_008f5fb5(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  undefined1 local_1c [4];
  uint local_18;
  int local_10;
  int local_c;
  uint local_8;
  
  local_10 = 0;
  local_8 = 0xffffffff;
  iVar2 = *(int *)(in_ECX + 4);
  if ((iVar2 == 0) || (*(int *)(iVar2 + 4) != 4)) {
    local_10 = 0;
  }
  else {
    for (local_c = *(int *)(iVar2 + 0x1c); local_c != 0; local_c = *(int *)(local_c + 0xc)) {
      iVar2 = *(int *)(local_c + 8);
      if (iVar2 != 0) {
        if (*(int *)(iVar2 + 4) == 6) {
          if (*(int *)(iVar2 + 0x10) == 2) {
            pbVar3 = *(byte **)(*(int *)(iVar2 + 0x14) + 0x18);
            pbVar6 = param_1;
            do {
              bVar1 = *pbVar3;
              bVar7 = bVar1 < *pbVar6;
              if (bVar1 != *pbVar6) {
LAB_008f603a:
                iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
                goto LAB_008f603f;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar3[1];
              bVar7 = bVar1 < pbVar6[1];
              if (bVar1 != pbVar6[1]) goto LAB_008f603a;
              pbVar3 = pbVar3 + 2;
              pbVar6 = pbVar6 + 2;
            } while (bVar1 != 0);
            iVar4 = 0;
LAB_008f603f:
            if (iVar4 == 0) {
              iVar2 = *(int *)(iVar2 + 0x18);
              if (*(int *)(iVar2 + 0x3c) != 0) {
                if ((*(byte *)(iVar2 + 0x18) & 2) == 0) {
                  uVar5 = 0;
                  if (*(int *)(iVar2 + 0x1c) != 0) {
                    iVar4 = FUN_008f31ff(*(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x18),0,local_1c);
                    if (iVar4 < 0) {
                      uVar5 = 0xffffffff;
                    }
                    else {
                      uVar5 = local_18;
                    }
                  }
                  if ((uVar5 & 0xffff0000) != 0) {
                    if ((uVar5 & 0xffff0000) != (*(uint *)(in_ECX + 0x10) & 0xffff0000))
                    goto LAB_008f60ac;
                  }
                  if ((uVar5 & 0xffff) != 0) {
                    if ((uVar5 & 0xffff) != (*(uint *)(in_ECX + 0x10) & 0xffff)) goto LAB_008f60ac;
                  }
                  if (local_8 != 0xffffffff) {
                    if (uVar5 <= local_8) goto LAB_008f60ac;
                  }
                  local_10 = iVar2;
                  local_8 = uVar5;
                }
              }
            }
          }
        }
      }
LAB_008f60ac:
    }
  }
  return local_10;
}


// ==== FUN_008f60cb @ 0x008f60cb ====

int FUN_008f60cb(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  undefined1 local_20 [4];
  uint local_1c;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_14 = 0;
  local_8 = 0xffffffff;
  local_10 = 0;
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 4) != 4)) {
    local_14 = 0;
  }
  else {
    for (local_c = *(int *)(iVar1 + 0x1c); local_c != 0; local_c = *(int *)(local_c + 0xc)) {
      iVar1 = *(int *)(local_c + 8);
      if (iVar1 != 0) {
        if (*(int *)(iVar1 + 4) == 6) {
          if (*(int *)(iVar1 + 0x10) == 2) {
            if (param_1 != 0) {
              iVar2 = param_1;
              do {
                if (*(int *)(iVar1 + 0x24) == *(int *)(*(int *)(iVar2 + 8) + 0x18)) break;
                iVar2 = *(int *)(iVar2 + 0xc);
              } while (iVar2 != 0);
              if (iVar2 != 0) {
                iVar2 = *(int *)(iVar1 + 0x18);
                if (*(int *)(iVar2 + 0x3c) != 0) {
                  uVar4 = 0;
                  if (*(int *)(iVar2 + 0x1c) != 0) {
                    iVar3 = FUN_008f31ff(*(undefined4 *)(*(int *)(iVar2 + 0x1c) + 0x18),0,local_20);
                    if (iVar3 < 0) {
                      uVar4 = 0xffffffff;
                    }
                    else {
                      uVar4 = local_1c;
                    }
                  }
                  if ((uVar4 & 0xffff0000) != 0) {
                    if ((uVar4 & 0xffff0000) != (*(uint *)(in_ECX + 0x10) & 0xffff0000))
                    goto LAB_008f61bc;
                  }
                  if ((uVar4 & 0xffff) != 0) {
                    if ((uVar4 & 0xffff) != (*(uint *)(in_ECX + 0x10) & 0xffff)) goto LAB_008f61bc;
                  }
                  if (local_8 != 0xffffffff) {
                    if (uVar4 <= local_8) goto LAB_008f61bc;
                  }
                  local_10 = *(undefined4 *)(*(int *)(iVar1 + 0x14) + 0x18);
                  local_14 = iVar2;
                  local_8 = uVar4;
                }
              }
            }
          }
        }
      }
LAB_008f61bc:
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = local_10;
    }
  }
  return local_14;
}


// ==== FUN_008f61e7 @ 0x008f61e7 ====

void FUN_008f61e7(byte param_1)

{
  undefined4 in_ECX;
  
  FUN_0095cf1d();
  if ((param_1 & 1) != 0) {
    FUN_00914f82(in_ECX);
  }
  return;
}


// ==== FUN_008f6207 @ 0x008f6207 ====

undefined4 FUN_008f6207(void)

{
  int iVar1;
  int *in_ECX;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined1 local_18 [4];
  uint local_14;
  char *local_c;
  undefined8 *local_8;
  
  puVar3 = *(undefined8 **)(*in_ECX + 0x3c);
  do {
    if (puVar3 == (undefined8 *)0x0) {
      return 0;
    }
    local_c = *(char **)((int)puVar3 + 4);
    puVar2 = (undefined8 *)0x0;
    local_8 = (undefined8 *)0x0;
    do {
      iVar1 = __stricmp(local_c,*(char **)((int)puVar3 + 4));
      if (iVar1 != 0) break;
      iVar1 = FUN_008f31ff(*(undefined4 *)puVar3,0,local_18);
      if (-1 < iVar1) {
        if (in_ECX[4] == local_14) {
          if (puVar2 == (undefined8 *)0x0) {
            puVar2 = puVar3;
          }
        }
        else if (((in_ECX[4] & 0xffff0000U) == local_14) && (local_8 == (undefined8 *)0x0)) {
          local_8 = puVar3;
        }
      }
      puVar3 = *(undefined8 **)(puVar3 + 5);
    } while (puVar3 != (undefined8 *)0x0);
    if ((puVar2 != (undefined8 *)0x0) || (puVar2 = local_8, local_8 != (undefined8 *)0x0)) {
      local_c = (char *)FUN_009152bf(*(undefined4 *)((int)puVar2 + 4),0xb51,1,4);
      if (local_c == (char *)0xffffffff) {
        return 0x8007000e;
      }
      local_8 = (undefined8 *)0x0;
      do {
        puVar2 = puVar2 + 1;
        iVar1 = FUN_00915318(local_c,0,local_8,*puVar2);
        if (iVar1 == -1) {
          return 0x8007000e;
        }
        local_8 = (undefined8 *)((int)local_8 + 1);
      } while (local_8 < 4);
    }
  } while( true );
}


// ==== FUN_008f62e1 @ 0x008f62e1 ====

int FUN_008f62e1(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 == 6) {
      return *(int *)(param_1 + 0x14) + 0x10;
    }
    if (iVar1 != 0xb) {
      if (iVar1 == 0xc) {
        iVar1 = FUN_008f62e1(*(undefined4 *)(param_1 + 0x14));
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_008f62e1(*(undefined4 *)(param_1 + 0x18));
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_008f62e1(*(undefined4 *)(param_1 + 0x1c));
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = FUN_008f62e1(*(undefined4 *)(param_1 + 0x20));
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      else if (iVar1 == 0xd) {
        return param_1 + 0x30;
      }
    }
  }
  return 0;
}


// ==== FUN_008f6353 @ 0x008f6353 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_008f6353(int *param_1,undefined4 param_2,undefined4 param_3,char *param_4,char param_5)

{
  undefined4 uVar1;
  undefined *puVar2;
  char *pcVar3;
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  param_1[0x13] = 1;
  __vsnprintf(local_108,0x100,param_4,&param_5);
  pcVar3 = local_108;
  puVar2 = &DAT_009d5e14;
  local_9 = 0;
  uVar1 = FUN_008f62e1(param_2);
  FUN_008bd320(*param_1 + 0x18,uVar1,param_3,puVar2,pcVar3);
  return 0;
}


// ==== FUN_008f63c5 @ 0x008f63c5 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_008f63c5(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4,char param_5)

{
  undefined8 uVar1;
  undefined *puVar2;
  char *pcVar3;
  char local_108 [255];
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  __vsnprintf(local_108,0x100,param_4,&param_5);
  pcVar3 = local_108;
  puVar2 = &DAT_009d5e14;
  local_9 = 0;
  uVar1 = FUN_008f62e1(param_2);
  FUN_008bd3f7(*(int *)((ulonglong)uVar1 >> 0x20) + 0x18,(int)uVar1,param_3,puVar2,pcVar3);
  return 0;
}


// ==== FUN_008f642e @ 0x008f642e ====

uint FUN_008f642e(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(*(int *)(param_3 + 8) + 0x14);
  iVar2 = *(int *)(iVar1 + *(int *)(*(int *)(param_3 + 0x18) + param_1 * 4) * 4);
  iVar1 = *(int *)(iVar1 + *(int *)(*(int *)(param_3 + 0x18) + param_2 * 4) * 4);
  uVar3 = *(uint *)(iVar2 + 0x6c);
  uVar4 = *(uint *)(iVar1 + 0x6c);
  if (uVar4 <= uVar3) {
    if (uVar4 < uVar3) {
      return 1;
    }
    uVar3 = *(uint *)(iVar2 + 0x10);
    uVar4 = *(uint *)(iVar1 + 0x10);
    if (uVar4 <= uVar3) {
      if (uVar4 < uVar3) {
        return 1;
      }
      if (param_2 <= param_1) {
        return (uint)(param_2 < param_1);
      }
    }
  }
  return 0xffffffff;
}


// ==== FUN_008f6485 @ 0x008f6485 ====

void FUN_008f6485(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_008f64c5 @ 0x008f64c5 ====

int FUN_008f64c5(int param_1,uint *param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = 0;
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = 0;
  if (iVar1 != 1) {
    if (iVar1 == 6) {
      uVar4 = *(undefined4 *)(param_1 + 0x18);
    }
    else {
      if (iVar1 == 8) {
        if (*(int *)(param_1 + 0x14) == 0) {
          return 0;
        }
        do {
          iVar1 = FUN_008f64c5(*(undefined4 *)(param_1 + 0x10),param_2 + iVar2);
          iVar2 = iVar2 + iVar1;
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(param_1 + 0x14));
        return iVar2;
      }
      if (iVar1 == 9) {
        iVar1 = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18);
        uVar3 = 0;
        switch(*(undefined4 *)(param_1 + 0x14)) {
        case 0:
          uVar3 = 0x17;
          break;
        case 1:
        case 5:
          uVar3 = 2;
          break;
        case 2:
        case 6:
          uVar3 = 0x2000002;
          break;
        case 3:
        case 7:
          uVar3 = 0x4000002;
          break;
        case 4:
        case 8:
          uVar3 = 0x8000002;
          break;
        case 10:
          uVar3 = 0x2000000;
          break;
        case 0xb:
          uVar3 = 0x4000000;
          break;
        case 0xc:
          uVar3 = 0x8000000;
        }
        if ((*(byte *)(in_ECX + 0x14) & 0x20) != 0) {
          uVar3 = uVar3 & 0xf3ffffff | 0x2000000;
        }
        if (iVar1 != 0) {
          for (iVar2 = iVar1; iVar2 != 0; iVar2 = iVar2 + -1) {
            *param_2 = uVar3;
            param_2 = param_2 + 1;
          }
        }
        return iVar1;
      }
      if (iVar1 != 0xb) {
        FUN_008f6353();
        return 0;
      }
      uVar4 = *(undefined4 *)(param_1 + 0x20);
    }
    iVar1 = FUN_008f64c5(uVar4,param_2);
    return iVar1;
  }
  do {
    if (*(int *)(param_1 + 4) != 1) break;
    iVar1 = FUN_008f64c5(*(undefined4 *)(param_1 + 8),param_2 + iVar2);
    param_1 = *(int *)(param_1 + 0xc);
    iVar2 = iVar2 + iVar1;
  } while (param_1 != 0);
  if (param_1 == 0) {
    return iVar2;
  }
  iVar1 = FUN_008f64c5(param_1,param_2 + iVar2);
  return iVar2 + iVar1;
}


// ==== FUN_008f6632 @ 0x008f6632 ====

int FUN_008f6632(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                undefined4 param_6,undefined4 *param_7,int *param_8)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  undefined4 local_c;
  int local_8;
  
  iVar3 = param_2;
  iVar2 = param_1;
  uVar5 = 0;
  local_8 = 0;
  local_c = 0;
  if (param_7 == (undefined4 *)0x0) {
    param_7 = &local_c;
  }
  if (param_1 != 0) {
    iVar4 = *(int *)(param_1 + 4);
    if (iVar4 == 1) {
      iVar4 = FUN_008f6632(*(undefined4 *)(param_1 + 8),param_2,param_3,param_4,param_5,param_6,
                           param_7,&param_2);
      if (iVar4 < 0) {
        return iVar4;
      }
      iVar2 = FUN_008f6632(*(undefined4 *)(iVar2 + 0xc),iVar3 + param_2 * 4,param_3,param_4,param_5,
                           param_6,param_7,&param_1);
      if (iVar2 < 0) {
        return iVar2;
      }
      local_8 = param_1 + param_2;
    }
    else {
      if (iVar4 == 6) {
        iVar2 = FUN_008f6632(*(undefined4 *)(param_1 + 0x18),param_2,param_3,param_4,param_5,param_6
                             ,param_7,&local_8);
      }
      else {
        if (iVar4 == 8) {
          if (param_5 == 0) {
            iVar3 = param_1;
            do {
              if (*(int *)(iVar3 + 4) != 8) break;
              iVar3 = *(int *)(iVar3 + 0x10);
            } while (iVar3 != 0);
            if (((iVar3 != 0) && (*(int *)(iVar3 + 4) == 9)) && (*(int *)(iVar3 + 0x10) == 3)) {
              param_3 = FUN_009152bf(&DAT_00a1fc84,0x2d1,0xffffffff,4);
              param_5 = 1;
            }
          }
          if (*(int *)(iVar2 + 0x14) != 0) {
            do {
              iVar3 = FUN_008f6632(*(undefined4 *)(iVar2 + 0x10),param_2 + local_8 * 4,param_3,
                                   param_4,param_5,param_6,param_7,&param_1);
              if (iVar3 < 0) {
                return iVar3;
              }
              local_8 = local_8 + param_1;
              uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint *)(iVar2 + 0x14));
          }
          goto LAB_008f6829;
        }
        if (iVar4 == 9) {
          if (*(int *)(param_1 + 0x10) == 3) {
            if (param_5 == 0) {
              param_3 = FUN_009152bf(&DAT_00a1fc84,0x2d1,0xffffffff,4);
            }
            else {
              pbVar1 = (byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + param_3 * 4) + 4);
              *pbVar1 = *pbVar1 | 0x80;
            }
          }
          iVar2 = FUN_008f4c34(*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x18),
                               *(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x20),param_2,
                               param_3,param_7,param_6,&local_8);
        }
        else {
          if (iVar4 != 0xb) {
            FUN_008f6353();
            goto LAB_008f6829;
          }
          iVar2 = FUN_008f7257(*(undefined4 *)(param_1 + 0x20),param_2,param_3,param_4,param_5,
                               param_6,param_7,*(undefined4 *)(param_1 + 0x2c),
                               *(undefined4 *)(param_1 + 0x30),&local_8);
        }
      }
      if (iVar2 < 0) {
        return iVar2;
      }
    }
  }
LAB_008f6829:
  if (param_8 != (int *)0x0) {
    *param_8 = local_8;
  }
  return 0;
}


// ==== FUN_008f683e @ 0x008f683e ====

int FUN_008f683e(int param_1,double *param_2)

{
  byte *pbVar1;
  int iVar2;
  int in_ECX;
  double local_14;
  double local_c;
  
  pbVar1 = *(byte **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + param_1 * 4);
  if ((*pbVar1 & 0x80) == 0) {
    iVar2 = FUN_008f4f7c(param_1,&local_14);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (local_14 != local_c) {
      return -0x7fffbffb;
    }
    iVar2 = FUN_00803910(local_14);
    if (iVar2 == 0) {
      return -0x7fffbffb;
    }
    if (param_2 == (double *)0x0) {
      return 0;
    }
  }
  else {
    iVar2 = FUN_00803910(*(undefined8 *)(pbVar1 + 0x20));
    if (iVar2 == 0) {
      return -0x7fffbffb;
    }
    if (param_2 == (double *)0x0) {
      return 0;
    }
    local_14 = *(double *)(pbVar1 + 0x20);
  }
  *param_2 = local_14;
  return 0;
}


// ==== FUN_008f68c1 @ 0x008f68c1 ====

undefined4 FUN_008f68c1(int param_1)

{
  int iVar1;
  
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          if (param_1 == 0) {
            return 1;
          }
          iVar1 = *(int *)(param_1 + 4);
          if (iVar1 != 1) break;
          iVar1 = FUN_008f68c1(*(undefined4 *)(param_1 + 8));
          if (iVar1 == 0) {
            return 0;
          }
          param_1 = *(int *)(param_1 + 0xc);
        }
        if (iVar1 != 6) break;
        param_1 = *(int *)(param_1 + 0x18);
      }
      if (iVar1 != 8) break;
LAB_008f6900:
      param_1 = *(int *)(param_1 + 0x10);
    }
    if (iVar1 == 9) {
      if ((*(int *)(param_1 + 0x10) < 0) || (2 < *(int *)(param_1 + 0x10))) {
        return 0;
      }
      return 1;
    }
    if (iVar1 != 0xb) {
      if (iVar1 != 0xd) {
        FUN_008f6353();
        return 0;
      }
      goto LAB_008f6900;
    }
    param_1 = *(int *)(param_1 + 0x20);
  } while( true );
}


// ==== FUN_008f693c @ 0x008f693c ====

undefined4 FUN_008f693c(uint param_1,uint param_2,undefined4 *param_3)

{
  int in_ECX;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(in_ECX + 8);
  uVar2 = param_1;
  if (param_1 < *(uint *)(iVar1 + 8)) {
    do {
      if (*(int *)(*(int *)(iVar1 + 0x14) + uVar2 * 4) != 0) {
        FUN_008f61e7(1);
      }
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + uVar2 * 4) = 0;
      iVar1 = *(int *)(in_ECX + 8);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(iVar1 + 8));
  }
  *(uint *)(*(int *)(in_ECX + 8) + 8) = param_1;
  iVar1 = *(int *)(in_ECX + 8);
  uVar2 = param_2;
  if (param_2 < *(uint *)(iVar1 + 0xc)) {
    do {
      if (*(int *)(*(int *)(iVar1 + 0x18) + uVar2 * 4) != 0) {
        FUN_008f4adb(1);
      }
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + uVar2 * 4) = 0;
      iVar1 = *(int *)(in_ECX + 8);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(iVar1 + 0xc));
  }
  *(uint *)(*(int *)(in_ECX + 8) + 0xc) = param_2;
  puVar3 = *(undefined4 **)(in_ECX + 0x18);
  for (uVar2 = *(uint *)(*(int *)(in_ECX + 4) + 0x18) & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  for (iVar1 = 0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_3;
    param_3 = (undefined4 *)((int)param_3 + 1);
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  return 0;
}


// ==== FUN_008f69da @ 0x008f69da ====

int FUN_008f69da(uint param_1,uint param_2,int param_3,int *param_4,uint *param_5,uint param_6)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int extraout_EAX;
  int in_ECX;
  undefined4 *puVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  int *piVar10;
  bool bVar11;
  undefined4 uVar12;
  undefined4 *local_24 [3];
  int local_18;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  uVar4 = param_2;
  if (((param_2 & 0xfff00000) == 0x20500000) && ((param_6 & 4) != 0)) {
    uVar3 = param_2 & 0xfffff;
    param_2 = 0;
    if (uVar3 != 0) {
      local_8 = (int)param_5 - (int)param_4;
      piVar10 = param_4;
      do {
        if ((*piVar10 != *(int *)(local_8 + (int)piVar10)) ||
           ((**(byte **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar10 * 4) & 1) == 0)) break;
        param_2 = param_2 + 1;
        piVar10 = piVar10 + 1;
      } while (param_2 < uVar3);
    }
    if (param_2 == uVar3) {
      uVar4 = uVar3 | 0x10000000;
    }
  }
  if (uVar4 == 0x50000001) {
    uVar12 = 0x20500001;
LAB_008f6af3:
    iVar5 = FUN_008f69da(param_1,uVar12,param_3,param_4,CONCAT44(param_6,param_5));
    if (iVar5 < 0) {
      return iVar5;
    }
    return 0;
  }
  if ((uVar4 == 0x50000002) && ((*(byte *)(*(int *)(in_ECX + 8) + 0x6c) & 0x20) == 0)) {
    local_14 = -1;
    local_10 = 0xffffffff;
    iVar5 = FUN_008f69da(param_1,0x20500001,&local_14,param_4,param_5,param_6 & 0x40);
    if (iVar5 < 0) {
      return iVar5;
    }
    iVar5 = FUN_008f69da(param_1,0x20500001,&local_10,param_4 + 1,param_5 + 1,param_6 & 0x40);
    if (iVar5 < 0) {
      return iVar5;
    }
    param_5 = &local_10;
    param_4 = &local_14;
    uVar12 = 0x20400001;
    goto LAB_008f6af3;
  }
  if (((*(byte *)(*(int *)(in_ECX + 8) + 0x6c) & 0x80) != 0) &&
     ((((local_10 = uVar4 & 0xfff00000, local_10 == 0x20000000 || (local_10 == 0x20100000)) ||
       (local_10 == 0x20200000)) || (local_10 == 0x20300000)))) {
    uVar4 = uVar4 & 0xfffff;
    local_c = operator_new(uVar4 << 4);
    if (local_c == (undefined4 *)0x0) {
      return -0x7ff8fff2;
    }
    uVar3 = 0;
    puVar6 = local_c;
    do {
      local_24[uVar3] = puVar6;
      uVar3 = uVar3 + 1;
      puVar6 = puVar6 + uVar4;
    } while (uVar3 < 4);
    if (uVar4 != 0) {
      iVar5 = (int)param_4 - (int)local_24[2];
      iVar8 = (int)param_5 - (int)local_24[2];
      local_18 = local_18 - (int)local_24[2];
      local_8 = uVar4;
      do {
        if (local_10 == 0x20000000) {
          *local_24[2] = *(undefined4 *)(iVar8 + (int)local_24[2]);
          uVar12 = *(undefined4 *)(iVar5 + (int)local_24[2]);
LAB_008f6be0:
          *(undefined4 *)(local_18 + (int)local_24[2]) = uVar12;
        }
        else {
          if (local_10 == 0x20100000) {
            *local_24[2] = *(undefined4 *)(iVar5 + (int)local_24[2]);
            uVar12 = *(undefined4 *)(iVar8 + (int)local_24[2]);
            goto LAB_008f6be0;
          }
          if (local_10 == 0x20200000) {
            *local_24[2] = *(undefined4 *)(in_ECX + 0x24);
            uVar12 = *(undefined4 *)(in_ECX + 0x20);
            goto LAB_008f6be0;
          }
          if (local_10 == 0x20300000) {
            *local_24[2] = *(undefined4 *)(in_ECX + 0x20);
            uVar12 = *(undefined4 *)(in_ECX + 0x24);
            goto LAB_008f6be0;
          }
        }
        local_24[2] = local_24[2] + 1;
        local_8 = local_8 - 1;
      } while (local_8 != 0);
    }
    iVar5 = FUN_008f4c18(local_24[0],uVar4);
    if ((-1 < iVar5) && (iVar5 = FUN_008f4c18(local_24[1],uVar4), -1 < iVar5)) {
      iVar5 = FUN_008f69da(param_1,uVar4 | 0x10100000,local_24[0],param_5,0,param_6 & 0x40);
      if ((-1 < iVar5) &&
         (iVar5 = FUN_008f69da(param_1,uVar4 | 0x20400000,local_24[1],param_4,local_24[0],
                               param_6 & 0x40), -1 < iVar5)) {
        FUN_008f69da(param_1,uVar4 | 0x30000000,param_3,local_24[1],local_c + uVar4 * 2,param_6);
      }
    }
    _free(local_c);
    return extraout_EAX;
  }
  local_c = (undefined4 *)in_ECX;
  local_8 = FUN_00915378(uVar4,0xffffffff,0xffffffff);
  if (local_8 < *(uint *)(*(int *)(in_ECX + 8) + 0xc)) {
    puVar9 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + local_8 * 4);
  }
  else {
    puVar9 = (uint *)0x0;
  }
  if (puVar9 == (uint *)0x0) {
    return -0x7ff8fff2;
  }
  if ((puVar9[3] == 0) && (puVar9[1] == 0)) {
    *puVar9 = 0;
    return 0;
  }
  uVar4 = FUN_00914d55(0,0);
  uVar3 = FUN_009145b2(0,0);
  local_10 = uVar3 * 4;
  iVar5 = puVar9[1] - uVar3;
  piVar10 = (int *)puVar9[2];
  for (uVar3 = uVar3 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
    *piVar10 = *param_4;
    param_4 = param_4 + 1;
    piVar10 = piVar10 + 1;
  }
  for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(char *)piVar10 = (char)*param_4;
    param_4 = (int *)((int)param_4 + 1);
    piVar10 = (int *)((int)piVar10 + 1);
  }
  puVar7 = (uint *)(puVar9[2] + local_10);
  for (; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *param_5;
    param_5 = param_5 + 1;
    puVar7 = puVar7 + 1;
  }
  uVar3 = 0;
  if (puVar9[1] != 0) {
    do {
      uVar1 = *(uint *)(puVar9[2] + uVar3 * 4);
      if (uVar1 < *(uint *)(*(int *)((int)local_c + 8) + 8)) {
        iVar5 = *(int *)(*(int *)(*(int *)((int)local_c + 8) + 0x14) + uVar1 * 4);
      }
      else {
        iVar5 = 0;
      }
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x5c) = *(int *)(iVar5 + 0x5c) + 1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < puVar9[1]);
  }
  param_5 = (uint *)0x0;
  if (uVar4 != 0) {
    do {
      param_4 = (int *)0x0;
      if ((param_3 != 0) && (uVar3 = *(uint *)(param_3 + (int)param_5 * 4), uVar3 != 0xffffffff)) {
        if (uVar3 < *(uint *)(*(int *)((int)local_c + 8) + 8)) {
          param_4 = *(int **)(*(int *)(*(int *)((int)local_c + 8) + 0x14) + uVar3 * 4);
        }
        else {
          param_4 = (int *)0x0;
        }
        if (param_4 == (int *)0x0) {
          FUN_008f6353(local_c,0,0,s_internal_error__result_register_i_00a25558);
          return -0x7fffbffb;
        }
      }
      local_10 = FUN_00915318(*(undefined4 *)(*(int *)((int)local_c + 8) + 0x88),0,0,0);
      if (local_10 == 0xffffffff) {
        return -0x7ff8fff2;
      }
      if (local_10 < *(uint *)(*(int *)((int)local_c + 8) + 8)) {
        puVar7 = *(uint **)(*(int *)(*(int *)((int)local_c + 8) + 0x14) + local_10 * 4);
      }
      else {
        puVar7 = (uint *)0x0;
      }
      if (puVar7 == (uint *)0x0) {
        return -0x7ff8fff2;
      }
      *puVar7 = param_6;
      puVar7[0x12] = local_8;
      puVar7[4] = (uint)param_5;
      if ((param_6 & 0xe000000) == 0) {
        *puVar7 = *(uint *)((int)local_c + 100) | param_6;
      }
      puVar7[5] = *(uint *)((int)local_c + 0x30);
      puVar7[6] = *(uint *)((int)local_c + 0x34);
      iVar5 = (int)param_5 * 4;
      *(uint *)(iVar5 + puVar9[4]) = local_10;
      if (param_3 != 0) {
        *(uint *)(iVar5 + param_3) = local_10;
      }
      if (param_4 != (int *)0x0) {
        puVar7[0xc] = *(uint *)((int)param_4 + 0x30);
        puVar7[0x18] = *(uint *)((int)param_4 + 0x60);
        puVar7[0x19] = *(uint *)((int)param_4 + 100);
      }
      if ((puVar7[0xc] != 0xffffffff) &&
         (*(undefined4 *)(*(int *)((int)local_c + 0x18) + puVar7[0xc] * 4) =
               *(undefined4 *)(iVar5 + puVar9[4]), puVar7[0x18] == 0)) {
        FUN_008f6353(local_c,0,0,s_internal_error__argument_missing_00a25580);
      }
      param_5 = (uint *)((int)param_5 + 1);
    } while (param_5 < uVar4);
  }
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      FUN_008f4f7c(*(undefined4 *)(puVar9[4] + uVar3 * 4),0);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  if (((*(byte *)((int)local_c + 0x14) & 4) == 0) && (iVar5 = FUN_009147e7(), iVar5 == 0)) {
    uVar3 = 0;
    bVar11 = uVar4 == 0;
    if (uVar4 != 0) {
      do {
        iVar5 = *(int *)(puVar9[4] + uVar3 * 4);
        if (((**(byte **)(*(int *)(*(int *)((int)local_c + 8) + 0x14) + iVar5 * 4) & 0x40) != 0) ||
           (iVar5 = FUN_008f683e(iVar5,&local_14), iVar5 < 0)) break;
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar4);
      bVar11 = uVar3 == uVar4;
    }
    if (bVar11) {
      *puVar9 = uVar4 & 0xfffff | 0x10000000;
      uVar3 = 0;
      puVar9[1] = puVar9[3];
      if (uVar4 != 0) {
        do {
          uVar12 = FUN_00915318(*(undefined4 *)(*(int *)((int)local_c + 8) + 0x78),0,0,
                                *(undefined8 *)
                                 (*(int *)(*(int *)(*(int *)((int)local_c + 8) + 0x14) +
                                          *(int *)(puVar9[4] + uVar3 * 4) * 4) + 0x20));
          *(undefined4 *)(puVar9[2] + uVar3 * 4) = uVar12;
          if (*(int *)(puVar9[2] + uVar3 * 4) == -1) {
            return -0x7ff8fff2;
          }
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar4);
      }
    }
  }
  uVar3 = *puVar9 & 0xfff00000;
  if (uVar3 < 0x20500001) {
    if (uVar3 != 0x20500000) {
      if (uVar3 == 0x10000000) {
        param_6 = 0;
        if (uVar4 != 0) {
          do {
            iVar5 = *(int *)(*(int *)((int)local_c + 8) + 0x14);
            puVar7 = *(uint **)(iVar5 + *(int *)(param_6 * 4 + puVar9[4]) * 4);
            uVar3 = *(uint *)(param_6 * 4 + puVar9[2]);
            puVar2 = *(uint **)(iVar5 + uVar3 * 4);
            puVar7[0xd] = uVar3;
            *puVar7 = *puVar7 | *puVar2;
            *(undefined8 *)(puVar7 + 8) = *(undefined8 *)(puVar2 + 8);
            *(undefined8 *)(puVar7 + 10) = *(undefined8 *)(puVar2 + 10);
            param_6 = param_6 + 1;
          } while (param_6 < uVar4);
        }
        goto LAB_008f71db;
      }
      if (uVar3 == 0x10100000) {
        param_6 = 0;
        if (uVar4 != 0) {
          do {
            iVar5 = *(int *)(*(int *)((int)local_c + 8) + 0x14);
            puVar7 = *(uint **)(iVar5 + *(int *)(param_6 * 4 + puVar9[4]) * 4);
            *puVar7 = *puVar7 | **(uint **)(iVar5 + *(int *)(param_6 * 4 + puVar9[2]) * 4) & 2;
            param_6 = param_6 + 1;
          } while (param_6 < uVar4);
        }
        goto LAB_008f71db;
      }
      if ((uVar3 != 0x20000000) && (uVar3 != 0x20100000)) {
        if ((uVar3 == 0x20400000) && (param_6 = 0, uVar4 != 0)) {
          do {
            iVar5 = *(int *)(*(int *)((int)local_c + 8) + 0x14);
            puVar7 = *(uint **)(iVar5 + *(int *)(param_6 * 4 + puVar9[4]) * 4);
            *puVar7 = *puVar7 | **(uint **)(iVar5 + *(int *)(puVar9[2] + (puVar9[3] + param_6) * 4)
                                                    * 4) &
                                **(uint **)(iVar5 + *(int *)(param_6 * 4 + puVar9[2]) * 4) & 2;
            param_6 = param_6 + 1;
          } while (param_6 < uVar4);
        }
        goto LAB_008f71db;
      }
    }
  }
  else if ((uVar3 != 0x20700000) && (uVar3 != 0x20800000)) {
    if (uVar3 == 0x30000000) {
      param_4 = (int *)0x0;
      if (uVar4 != 0) {
        do {
          iVar5 = *(int *)(*(int *)((int)local_c + 8) + 0x14);
          puVar7 = *(uint **)(iVar5 + *(int *)(puVar9[4] + (int)param_4 * 4) * 4);
          uVar3 = **(uint **)(iVar5 + *(int *)(puVar9[2] + ((int)param_4 + puVar9[3] * 2) * 4) * 4)
                  & **(uint **)(iVar5 + *(int *)(puVar9[2] + ((int)param_4 + puVar9[3]) * 4) * 4);
          if ((uVar3 & 1) == 0) {
            if ((uVar3 & 2) != 0) {
              *puVar7 = *puVar7 | 2;
            }
          }
          else {
            *puVar7 = *puVar7 | 0x17;
          }
          param_4 = (int *)((int)param_4 + 1);
        } while (param_4 < uVar4);
      }
    }
    else if (uVar3 == 0x50000000) {
      puVar7 = *(uint **)(*(int *)(*(int *)((int)local_c + 8) + 0x14) + *(int *)puVar9[4] * 4);
      param_6 = 0;
      if (uVar4 != 0) {
        param_4 = (int *)puVar9[2];
        iVar5 = *(int *)(*(int *)((int)local_c + 8) + 0x14);
        piVar10 = param_4 + puVar9[3];
        do {
          if ((**(uint **)(iVar5 + *param_4 * 4) & **(uint **)(iVar5 + *piVar10 * 4) & 2) == 0)
          break;
          param_6 = param_6 + 1;
          param_4 = param_4 + 1;
          piVar10 = piVar10 + 1;
        } while (param_6 < uVar4);
      }
      if (param_6 == uVar4) {
        *puVar7 = *puVar7 | 2;
      }
    }
    goto LAB_008f71db;
  }
  param_6 = 0;
  if (uVar4 != 0) {
    do {
      iVar5 = *(int *)(*(int *)((int)local_c + 8) + 0x14);
      puVar7 = *(uint **)(iVar5 + *(int *)(param_6 * 4 + puVar9[4]) * 4);
      uVar3 = **(uint **)(iVar5 + *(int *)(puVar9[2] + (puVar9[3] + param_6) * 4) * 4) &
              **(uint **)(iVar5 + *(int *)(param_6 * 4 + puVar9[2]) * 4);
      if ((uVar3 & 1) == 0) {
        if ((uVar3 & 2) != 0) {
          *puVar7 = *puVar7 | 2;
        }
      }
      else {
        *puVar7 = *puVar7 | 0x17;
      }
      param_6 = param_6 + 1;
    } while (param_6 < uVar4);
  }
LAB_008f71db:
  puVar9[0xf] = param_1;
  puVar9[0xe] = *(uint *)((int)local_c + 0x38);
  return 0;
}


// ==== FUN_008f71f0 @ 0x008f71f0 ====

undefined4 FUN_008f71f0(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *_Memory;
  undefined4 extraout_EAX;
  int in_ECX;
  uint *puVar2;
  
  _Memory = operator_new(param_3 << 2);
  if (_Memory == (uint *)0x0) {
    return 0x8007000e;
  }
  FUN_008f64c5(param_1,_Memory);
  if (param_3 != 0) {
    puVar2 = _Memory;
    do {
      puVar1 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                         *(int *)((param_2 - (int)_Memory) + (int)puVar2) * 4);
      *puVar1 = *puVar1 | *puVar2;
      puVar2 = puVar2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008f7257 @ 0x008f7257 ====

int FUN_008f7257(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5,int param_6,
                undefined4 *param_7,char *param_8,int param_9,undefined4 *param_10)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 *puVar7;
  int in_ECX;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined1 local_20 [4];
  uint local_1c;
  undefined4 local_14;
  undefined4 local_10;
  char *local_c;
  int local_8;
  
  local_10 = 0;
  local_14 = 0;
  if (param_1 != 0) {
    if ((param_4 == 0) && (param_8 != (char *)0x0)) {
      param_6 = (int)param_8;
      param_7 = &local_14;
      param_4 = 1;
    }
    if (((param_5 == 0) && (param_9 != 0)) && (local_8 = in_ECX, *(int *)(in_ECX + 0x84) == 0)) {
      do {
        pcVar5 = (char *)0x0;
        iVar2 = *(int *)(param_9 + 8);
        param_8 = (char *)0x0;
        local_c = (char *)0x0;
        if (*(int *)(iVar2 + 4) == 0x11) {
          pcVar4 = *(char **)(*(int *)(iVar2 + 0x14) + 0x18);
          if (*(int *)(iVar2 + 0x10) == 0) {
            local_c = pcVar4;
          }
          else {
            iVar2 = FUN_008f31ff(*(undefined4 *)(*(int *)(iVar2 + 0x10) + 0x18),0,local_20);
            if (-1 < iVar2) {
              if (*(uint *)(local_8 + 0x10) == local_1c) {
                param_8 = pcVar4;
              }
              else if ((*(uint *)(local_8 + 0x10) & 0xffff0000) == local_1c) {
                pcVar5 = pcVar4;
              }
            }
          }
        }
        iVar2 = local_8;
        param_9 = *(int *)(param_9 + 0xc);
        puVar9 = (undefined4 *)0x0;
        if (param_8 == (char *)0x0) {
          if (pcVar5 == (char *)0x0) {
            param_8 = local_c;
          }
          else {
            param_8 = pcVar5;
          }
          if (param_8 != (char *)0x0) goto LAB_008f7353;
        }
        else {
LAB_008f7353:
          if (param_3 < *(uint *)(*(int *)(local_8 + 8) + 4)) {
            iVar3 = *(int *)(*(int *)(*(int *)(local_8 + 8) + 0x10) + param_3 * 4);
          }
          else {
            iVar3 = 0;
          }
          if (iVar3 == 0) {
            return -0x7fffbffb;
          }
          param_3 = FUN_009153cf(iVar3);
          if (param_3 < *(uint *)(*(int *)(iVar2 + 8) + 4)) {
            puVar9 = *(undefined4 **)(*(int *)(*(int *)(iVar2 + 8) + 0x10) + param_3 * 4);
          }
          if (puVar9 == (undefined4 *)0x0) {
            return -0x7ff8fff2;
          }
          uVar6 = puVar9[1];
          if ((uVar6 & 0x800) == 0) {
            *puVar9 = param_8;
            puVar9[1] = uVar6 | 0x840;
            if (((uVar6 & 0x10) != 0) && (-1 < (char)(uVar6 | 0x840))) {
              if (((uVar6 & 0x200) != 0) && ((*(uint *)(*(int *)(local_8 + 8) + 0x70) & 0x200) != 0)
                 ) {
                puVar9[1] = uVar6 | 0xc40;
              }
              if (((puVar9[1] & 0x200) == 0) && ((*(byte *)(*(int *)(local_8 + 8) + 0x71) & 4) != 0)
                 ) {
                puVar9[1] = puVar9[1] | 0x100400;
              }
            }
          }
          else {
            pcVar4 = (char *)*puVar9;
            pcVar5 = pcVar4 + 1;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            pcVar4 = pcVar4 + -(int)pcVar5;
            pcVar5 = param_8;
            do {
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            uVar6 = (int)pcVar5 - (int)(param_8 + 1);
            local_c = pcVar4;
            puVar7 = (undefined4 *)FUN_008f33e7(pcVar4 + uVar6 + 3,4);
            if (puVar7 == (undefined4 *)0x0) {
              return -0x7ff8fff2;
            }
            puVar10 = (undefined4 *)*puVar9;
            puVar11 = puVar7;
            for (uVar8 = (uint)pcVar4 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *puVar11 = *puVar10;
              puVar10 = puVar10 + 1;
              puVar11 = puVar11 + 1;
            }
            for (uVar8 = (uint)pcVar4 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
              puVar10 = (undefined4 *)((int)puVar10 + 1);
              puVar11 = (undefined4 *)((int)puVar11 + 1);
            }
            pcVar5 = (char *)((int)puVar7 + (int)local_c);
            *pcVar5 = ';';
            pcVar5[1] = ' ';
            pcVar5 = pcVar5 + 2;
            for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
              *(undefined4 *)pcVar5 = *(undefined4 *)param_8;
              param_8 = param_8 + 4;
              pcVar5 = pcVar5 + 4;
            }
            for (uVar8 = uVar6 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
              *pcVar5 = *param_8;
              param_8 = param_8 + 1;
              pcVar5 = pcVar5 + 1;
            }
            ((undefined1 *)((int)puVar7 + uVar6 + 2))[(int)local_c] = 0;
            *puVar9 = puVar7;
          }
          param_5 = 1;
        }
      } while (param_9 != 0);
    }
    iVar2 = FUN_008f6632(param_1,param_2,param_3,param_4,param_5,param_6,param_7,&local_10);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  if (param_10 != (undefined4 *)0x0) {
    *param_10 = local_10;
  }
  return 0;
}


// ==== FUN_008f74a6 @ 0x008f74a6 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f74a6(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
                 uint param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  int local_120;
  int iStack_11c;
  int iStack_118;
  int iStack_114;
  double local_110;
  double local_108;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  uint local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  undefined4 local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  undefined4 local_a4;
  int local_a0;
  undefined4 *local_9c [16];
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  uint local_c;
  int *local_8;
  
  uVar1 = 1;
  local_1c = (undefined4 *)0x0;
  local_c = 1;
  if (1 < param_5) {
    do {
      if (param_2[uVar1] != *param_2) {
        local_c = 0;
        break;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_5);
  }
  uVar1 = *(uint *)(*(int *)(in_ECX + 8) + 0x6c);
  if ((uVar1 & 0x200) == 0) {
    if (((uVar1 & 0x100) == 0) || (local_c == 0)) {
      uVar1 = -(uint)(param_3 != (undefined4 *)0x0) & param_5;
      local_d4 = -(uint)(param_4 != (undefined4 *)0x0) & param_5;
      local_c = local_d4 + uVar1;
      local_10 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255e8);
      local_f0 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255d8);
      local_ec = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a011c0);
      local_dc = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255e0);
      local_d8 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25540);
      local_e0 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255d0);
      local_e8 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255c8);
      local_e4 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255c0);
      local_a4 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255b8);
      local_b4 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255b0);
      local_1c = operator_new(local_c * 0x6c);
      if (local_1c == (undefined4 *)0x0) {
        local_8 = (int *)0x8007000e;
        goto LAB_008f7d35;
      }
      uVar3 = 0;
      puVar2 = local_1c;
      do {
        local_9c[uVar3] = puVar2;
        uVar3 = uVar3 + 1;
        puVar2 = puVar2 + local_c;
      } while (uVar3 < 0x1b);
      uVar3 = 0;
      do {
        uVar6 = FUN_008f4c18(local_9c[uVar3],local_c);
        local_8 = (int *)uVar6;
        if ((int)local_8 < 0) goto LAB_008f7d35;
        uVar3 = (int)((ulonglong)uVar6 >> 0x20) + 1;
      } while (uVar3 < 0xf);
      param_5 = 0;
      if (local_c != 0) {
        local_8 = param_2 + -uVar1;
        local_18 = (int)param_4 - (int)param_2;
        local_14 = (int)param_3 - (int)local_9c[0xf];
        local_c0 = local_5c - (int)local_9c[0xf];
        local_a8 = local_58 - (int)local_9c[0xf];
        local_b0 = local_54 - (int)local_9c[0xf];
        local_b8 = local_50 - (int)local_9c[0xf];
        local_a0 = local_4c - (int)local_9c[0xf];
        local_c8 = local_48 - (int)local_9c[0xf];
        local_d0 = local_44 - (int)local_9c[0xf];
        local_ac = local_40 - (int)local_9c[0xf];
        local_bc = local_3c - (int)local_9c[0xf];
        local_c4 = local_38 - (int)local_9c[0xf];
        local_cc = local_34 - (int)local_9c[0xf];
        puVar2 = local_9c[0xf];
        do {
          if (param_5 < uVar1) {
            uVar4 = *(undefined4 *)(local_14 + (int)puVar2);
          }
          else {
            uVar4 = *(undefined4 *)(local_18 + (int)local_8);
          }
          *puVar2 = uVar4;
          *(undefined4 *)(local_c0 + (int)puVar2) = local_10;
          uVar4 = local_f0;
          if (uVar1 <= param_5) {
            uVar4 = local_ec;
          }
          *(undefined4 *)(local_a8 + (int)puVar2) = uVar4;
          *(undefined4 *)(local_b0 + (int)puVar2) = local_dc;
          *(undefined4 *)(local_b8 + (int)puVar2) = local_d8;
          *(undefined4 *)(local_a0 + (int)puVar2) = local_e0;
          *(undefined4 *)(local_c8 + (int)puVar2) = local_e8;
          *(undefined4 *)(local_d0 + (int)puVar2) = local_e4;
          *(undefined4 *)(local_ac + (int)puVar2) = local_a4;
          *(undefined4 *)(local_bc + (int)puVar2) = local_b4;
          *(undefined4 *)(local_c4 + (int)puVar2) = *(undefined4 *)(in_ECX + 0x20);
          if (param_5 < uVar1) {
            iVar5 = *(int *)(((int)param_2 - (int)local_9c[0xf]) + (int)puVar2);
          }
          else {
            iVar5 = *local_8;
          }
          param_5 = param_5 + 1;
          local_8 = local_8 + 1;
          *(int *)(local_cc + (int)puVar2) = iVar5;
          puVar2 = puVar2 + 1;
        } while (param_5 < local_c);
      }
      local_c = local_c & 0xfffff;
      param_2 = (int *)(local_c | 0x20500000);
      local_8 = (int *)FUN_008f69da(param_1,param_2,local_9c[0],local_34,local_5c,0);
      if ((int)local_8 < 0) goto LAB_008f7d35;
      uVar3 = local_c | 0x20400000;
      local_8 = (int *)FUN_008f69da(param_1,uVar3,local_9c[1],local_9c[0],local_58,0);
      if ((((((((int)local_8 < 0) ||
              (local_8 = (int *)FUN_008f69da(param_1,local_c | 0x10400000,local_9c[2],local_9c[1],0,
                                             0x14), (int)local_8 < 0)) ||
             (local_8 = (int *)FUN_008f69da(param_1,param_2,local_9c[3],local_9c[2],local_54,4),
             (int)local_8 < 0)) ||
            ((local_8 = (int *)FUN_008f69da(param_1,uVar3,local_9c[4],local_9c[3],local_50,0),
             (int)local_8 < 0 ||
             (local_8 = (int *)FUN_008f69da(param_1,param_2,local_9c[5],local_9c[4],local_9c[4],4),
             (int)local_8 < 0)))) ||
           (local_8 = (int *)FUN_008f69da(param_1,param_2,local_9c[6],local_9c[5],local_4c,0),
           (int)local_8 < 0)) ||
          (((local_8 = (int *)FUN_008f69da(param_1,uVar3,local_9c[7],local_9c[6],local_48,0),
            (int)local_8 < 0 ||
            (local_8 = (int *)FUN_008f69da(param_1,param_2,local_9c[8],local_9c[5],local_9c[7],0),
            (int)local_8 < 0)) ||
           ((local_8 = (int *)FUN_008f69da(param_1,uVar3,local_9c[9],local_9c[8],local_44,0),
            (int)local_8 < 0 ||
            (((local_8 = (int *)FUN_008f69da(param_1,param_2,local_9c[10],local_9c[5],local_9c[9],0)
              , (int)local_8 < 0 ||
              (local_8 = (int *)FUN_008f69da(param_1,uVar3,local_9c[0xb],local_9c[10],local_40,0),
              (int)local_8 < 0)) ||
             (local_8 = (int *)FUN_008f69da(param_1,param_2,local_9c[0xc],local_9c[5],local_9c[0xb],
                                            0), (int)local_8 < 0)))))))) ||
         (((local_8 = (int *)FUN_008f69da(param_1,uVar3,local_9c[0xd],local_9c[0xc],local_3c,0),
           (int)local_8 < 0 ||
           (local_8 = (int *)FUN_008f69da(param_1,param_2,local_9c[0xe],local_9c[5],local_9c[0xd],0)
           , (int)local_8 < 0)) ||
          (local_8 = (int *)FUN_008f69da(param_1,uVar3,local_9c[0xf],local_9c[0xe],local_38,0x10),
          (int)local_8 < 0)))) goto LAB_008f7d35;
      puVar2 = local_9c[0xf];
      for (uVar3 = uVar1 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
        *param_3 = *puVar2;
        puVar2 = puVar2 + 1;
        param_3 = param_3 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)param_3 = *(undefined1 *)puVar2;
        puVar2 = (undefined4 *)((int)puVar2 + 1);
        param_3 = (undefined4 *)((int)param_3 + 1);
      }
      puVar2 = local_9c[0xf] + uVar1;
      for (uVar3 = local_d4; uVar3 != 0; uVar3 = uVar3 - 1) {
        *param_4 = *puVar2;
        puVar2 = puVar2 + 1;
        param_4 = param_4 + 1;
      }
    }
    else {
      local_c = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255e8);
      local_10 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a011c0);
      local_18 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255e0);
      local_14 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25540);
      local_8 = (int *)FUN_008f4f7c(*param_2,&local_110);
      if ((int)local_8 < 0) goto LAB_008f7d35;
      if ((local_110 < _DAT_00a25540) || (_DAT_00a25538 < local_108)) {
        local_30 = 0xffffffff;
        local_2c = 0xffffffff;
        local_28 = 0xffffffff;
        local_24 = 0xffffffff;
        local_20 = -1;
        local_8 = (int *)FUN_008f69da(param_1,0x20500001,&local_30,param_2,&local_c,0);
        if ((((int)local_8 < 0) ||
            (((local_8 = (int *)FUN_008f69da(param_1,0x20400001,&local_2c,&local_30,&local_10,0),
              (int)local_8 < 0 ||
              (local_8 = (int *)FUN_008f69da(param_1,0x10400001,&local_28,&local_2c,0,0x14),
              (int)local_8 < 0)) ||
             (local_8 = (int *)FUN_008f69da(param_1,0x20500001,&local_24,&local_28,&local_18,4),
             (int)local_8 < 0)))) ||
           (local_8 = (int *)FUN_008f69da(param_1,0x20400001,&local_20,&local_24,&local_14,0),
           (int)local_8 < 0)) goto LAB_008f7d35;
      }
      else {
        local_20 = *param_2;
      }
      local_100 = 0xffffffff;
      local_fc = 0xffffffff;
      uStack_f8 = 0xffffffff;
      uStack_f4 = 0xffffffff;
      local_120 = local_20;
      iStack_11c = local_20;
      iStack_118 = local_20;
      iStack_114 = local_20;
      local_8 = (int *)FUN_008f69da(param_1,0x50300004,&local_100,&local_120,0,0x10);
      if ((int)local_8 < 0) goto LAB_008f7d35;
      if ((param_4 != (undefined4 *)0x0) && (uVar1 = param_5, param_5 != 0)) {
        for (; uVar1 != 0; uVar1 = uVar1 - 1) {
          *param_4 = local_100;
          param_4 = param_4 + 1;
        }
      }
      if ((param_3 != (undefined4 *)0x0) && (param_5 != 0)) {
        for (; param_5 != 0; param_5 = param_5 - 1) {
          *param_3 = local_fc;
          param_3 = param_3 + 1;
        }
      }
    }
  }
  else if (((param_3 != (undefined4 *)0x0) &&
           (local_8 = (int *)FUN_008f69da(param_1,param_5 & 0xfffff | 0x10800000,param_3,param_2,0,
                                          0x10), (int)local_8 < 0)) ||
          ((param_4 != (undefined4 *)0x0 &&
           (local_8 = (int *)FUN_008f69da(param_1,param_5 & 0xfffff | 0x10900000,param_4,param_2,0,
                                          0x10), (int)local_8 < 0)))) goto LAB_008f7d35;
  local_8 = (int *)0x0;
LAB_008f7d35:
  _free(local_1c);
  return;
}


// ==== FUN_008f7d48 @ 0x008f7d48 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f7d48(undefined4 param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  uint *puVar8;
  int in_ECX;
  uint uVar9;
  undefined8 uVar10;
  int local_84 [21];
  uint *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  void *local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_14 = (void *)0x0;
  if ((*(byte *)(*(int *)(in_ECX + 8) + 0x6d) & 2) == 0) {
    local_10 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25610);
    local_c = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25608);
    uVar2 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25600);
    uVar3 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255f8);
    uVar4 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255f0);
    uVar5 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25538);
    uVar6 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25548);
    local_14 = operator_new(param_5 * 0x70);
    if (local_14 == (void *)0x0) goto LAB_008f7dbd;
    uVar9 = 0;
    pvVar7 = local_14;
    do {
      local_84[uVar9] = (int)pvVar7;
      uVar9 = uVar9 + 1;
      pvVar7 = (void *)((int)pvVar7 + param_5 * 4);
    } while (uVar9 < 0x1c);
    uVar9 = 0;
    do {
      uVar10 = FUN_008f4c18(local_84[uVar9],param_5);
      if ((int)uVar10 < 0) goto LAB_008f7dbd;
      uVar9 = (int)((ulonglong)uVar10 >> 0x20) + 1;
    } while (uVar9 < 0x14);
    if (param_5 != 0) {
      local_8 = param_5;
      puVar8 = local_30;
      do {
        *(undefined4 *)((local_84[0x14] - (int)local_30) + (int)puVar8) =
             *(undefined4 *)(in_ECX + 0x20);
        *puVar8 = local_10;
        *(uint *)((local_2c - (int)local_30) + (int)puVar8) = local_c;
        *(undefined4 *)((local_28 - (int)local_30) + (int)puVar8) = uVar2;
        *(undefined4 *)((local_24 - (int)local_30) + (int)puVar8) = uVar3;
        *(undefined4 *)((local_20 - (int)local_30) + (int)puVar8) = uVar4;
        *(undefined4 *)((local_1c - (int)local_30) + (int)puVar8) = uVar5;
        *(undefined4 *)((local_18 - (int)local_30) + (int)puVar8) = uVar6;
        puVar8 = puVar8 + 1;
        local_8 = local_8 - 1;
      } while (local_8 != 0);
    }
    param_5 = param_5 & 0xfffff;
    local_8 = param_5 | 0x10100000;
    iVar1 = FUN_008f69da(param_1,local_8,local_84[0],param_2,0,0);
    if (((iVar1 < 0) ||
        (iVar1 = FUN_008f69da(param_1,param_5 | 0x20100000,local_84[1],param_2,local_84[0],4),
        iVar1 < 0)) ||
       (iVar1 = FUN_008f69da(param_1,local_8,local_84[2],local_84[1],0,8), iVar1 < 0))
    goto LAB_008f7dbd;
    local_c = param_5 | 0x20400000;
    iVar1 = FUN_008f69da(param_1,local_c,local_84[3],local_84[2],local_84[0x14],0);
    if (((iVar1 < 0) ||
        (iVar1 = FUN_008f69da(param_1,param_5 | 0x10700000,local_84[4],local_84[3],0,4), iVar1 < 0))
       || (iVar1 = FUN_008f69da(param_1,param_5 | 0x10300000,local_84[5],local_84[4],0,4), iVar1 < 0
          )) goto LAB_008f7dbd;
    local_10 = param_5 | 0x20500000;
    iVar1 = FUN_008f69da(param_1,local_10,local_84[6],local_30,local_84[1],0);
    if ((((iVar1 < 0) ||
         (iVar1 = FUN_008f69da(param_1,local_c,local_84[7],local_84[6],local_2c,0), iVar1 < 0)) ||
        ((((iVar1 = FUN_008f69da(param_1,local_10,local_84[8],local_84[7],local_84[1],0), iVar1 < 0
           || (((iVar1 = FUN_008f69da(param_1,local_c,local_84[9],local_84[8],local_28,0), iVar1 < 0
                || (iVar1 = FUN_008f69da(param_1,local_10,local_84[10],local_84[9],local_84[1],0),
                   iVar1 < 0)) ||
               (iVar1 = FUN_008f69da(param_1,local_c,local_84[0xb],local_84[10],local_24,0),
               iVar1 < 0)))) ||
          ((iVar1 = FUN_008f69da(param_1,local_10,local_84[0xc],local_84[0xb],local_84[5],0),
           iVar1 < 0 ||
           (iVar1 = FUN_008f69da(param_1,local_10,local_84[0xd],local_84[0xc],local_20,0), iVar1 < 0
           )))) || (iVar1 = FUN_008f69da(param_1,local_c,local_84[0xe],local_84[0xd],local_1c,0),
                   iVar1 < 0)))) ||
       (((((iVar1 = FUN_008f69da(param_1,param_5 | 0x20200000,local_84[0xf],param_2,local_84[0],0x17
                                ), iVar1 < 0 ||
           (iVar1 = FUN_008f69da(param_1,local_10,local_84[0x10],local_84[0xe],local_84[0xf],0),
           iVar1 < 0)) ||
          ((iVar1 = FUN_008f69da(param_1,local_c,local_84[0x11],local_84[0xc],local_84[0x10],4),
           iVar1 < 0 ||
           ((iVar1 = FUN_008f69da(param_1,local_8,local_84[0x12],local_84[0x11],0,8), iVar1 < 0 ||
            (iVar1 = FUN_008f69da(param_1,local_c,local_84[0x13],local_84[0x12],local_18,0),
            iVar1 < 0)))))) ||
         ((param_3 != 0 &&
          (iVar1 = FUN_008f69da(param_1,param_5 | 0x10000000,param_3,local_84[0x13],0,0), iVar1 < 0)
          ))) || (param_4 == 0)))) goto LAB_008f7dbd;
    param_5 = param_5 | 0x10000000;
    param_2 = local_84[0x11];
  }
  else {
    if (((param_3 != 0) &&
        (iVar1 = FUN_008f69da(param_1,param_5 & 0xfffff | 0x10a00000,param_3,param_2,0,0), iVar1 < 0
        )) || (param_4 == 0)) goto LAB_008f7dbd;
    param_5 = param_5 & 0xfffff | 0x10b00000;
  }
  FUN_008f69da(param_1,param_5,param_4,param_2,0x400000000);
LAB_008f7dbd:
  _free(local_14);
  return;
}


// ==== FUN_008f82c6 @ 0x008f82c6 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f82c6(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  int in_ECX;
  void *pvVar9;
  undefined8 uVar10;
  int local_e0 [40];
  uint *local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  void *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_20 = (void *)0x0;
  if ((*(byte *)(*(int *)(in_ECX + 8) + 0x6d) & 2) == 0) {
    local_10 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25638);
    local_c = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25630);
    local_8 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25628);
    uVar2 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25620);
    uVar3 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25618);
    uVar4 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255f0);
    uVar5 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25548);
    uVar6 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a25540);
    local_20 = operator_new(param_5 * 0xc0);
    if (local_20 == (void *)0x0) goto LAB_008f8ada;
    uVar1 = 0;
    pvVar9 = local_20;
    do {
      local_e0[uVar1] = (int)pvVar9;
      uVar1 = uVar1 + 1;
      pvVar9 = (void *)((int)pvVar9 + param_5 * 4);
    } while (uVar1 < 0x30);
    uVar1 = 0;
    do {
      uVar10 = FUN_008f4c18(local_e0[uVar1],param_5);
      if ((int)uVar10 < 0) goto LAB_008f8ada;
      uVar1 = (int)((ulonglong)uVar10 >> 0x20) + 1;
    } while (uVar1 < 0x27);
    if (param_5 != 0) {
      local_18 = local_3c - (int)local_40;
      local_1c = local_24 - (int)local_40;
      local_14 = param_5;
      puVar7 = local_40;
      do {
        *(uint *)((local_e0[0x27] - (int)local_40) + (int)puVar7) = local_10;
        *puVar7 = local_c;
        *(uint *)(local_18 + (int)puVar7) = local_8;
        *(undefined4 *)((local_38 - (int)local_40) + (int)puVar7) = uVar2;
        *(undefined4 *)((local_34 - (int)local_40) + (int)puVar7) = uVar3;
        *(undefined4 *)((local_30 - (int)local_40) + (int)puVar7) = uVar4;
        *(undefined4 *)((local_2c - (int)local_40) + (int)puVar7) = uVar5;
        *(undefined4 *)((local_28 - (int)local_40) + (int)puVar7) = uVar6;
        *(undefined4 *)(local_1c + (int)puVar7) = *(undefined4 *)(in_ECX + 0x20);
        puVar7 = puVar7 + 1;
        local_14 = local_14 - 1;
      } while (local_14 != 0);
    }
    if (param_3 == 0) {
      param_3 = local_24;
    }
    local_c = param_5 & 0xfffff;
    local_10 = local_c | 0x10100000;
    iVar8 = FUN_008f69da(param_1,local_10,local_e0[0],param_2,0,0);
    if (iVar8 < 0) goto LAB_008f8ada;
    local_14 = local_c | 0x20100000;
    iVar8 = FUN_008f69da(param_1,local_14,local_e0[1],param_2,local_e0[0],4);
    if (((iVar8 < 0) || (iVar8 = FUN_008f69da(param_1,local_10,local_e0[2],param_3,0,0), iVar8 < 0))
       || (iVar8 = FUN_008f69da(param_1,local_14,local_e0[3],param_3,local_e0[2],4), iVar8 < 0))
    goto LAB_008f8ada;
    local_1c = local_c | 0x20000000;
    iVar8 = FUN_008f69da(param_1,local_1c,local_e0[4],local_e0[1],local_e0[3],4);
    if (((iVar8 < 0) ||
        (iVar8 = FUN_008f69da(param_1,local_14,local_e0[5],local_e0[1],local_e0[3],4), iVar8 < 0))
       || (iVar8 = FUN_008f69da(param_1,local_c | 0x10300000,local_e0[6],local_e0[5],0,4), iVar8 < 0
          )) goto LAB_008f8ada;
    uVar1 = local_c | 0x20500000;
    iVar8 = FUN_008f69da(param_1,uVar1,local_e0[7],local_e0[4],local_e0[6],0x14);
    if (((iVar8 < 0) ||
        (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[8],local_e0[7],local_e0[7],0x14), iVar8 < 0))
       || (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[9],local_e0[8],local_e0[0x27],0), iVar8 < 0))
    goto LAB_008f8ada;
    local_8 = local_c | 0x20400000;
    iVar8 = FUN_008f69da(param_1,local_8,local_e0[10],local_e0[9],local_40,0);
    if ((((((iVar8 < 0) ||
           (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0xb],local_e0[8],local_e0[10],0), iVar8 < 0)
           ) || (iVar8 = FUN_008f69da(param_1,local_8,local_e0[0xc],local_e0[0xb],local_3c,0),
                iVar8 < 0)) ||
         ((iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0xd],local_e0[8],local_e0[0xc],0), iVar8 < 0
          || (iVar8 = FUN_008f69da(param_1,local_8,local_e0[0xe],local_e0[0xd],local_38,0),
             iVar8 < 0)))) ||
        (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0xf],local_e0[8],local_e0[0xe],0), iVar8 < 0))
       || ((iVar8 = FUN_008f69da(param_1,local_8,local_e0[0x10],local_e0[0xf],local_34,0), iVar8 < 0
           || (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0x11],local_e0[7],local_e0[0x10],0),
              iVar8 < 0)))) goto LAB_008f8ada;
    local_18 = local_c | 0x20200000;
    iVar8 = FUN_008f69da(param_1,local_18,local_e0[0x12],local_e0[3],local_e0[1],0x17);
    if (((((iVar8 < 0) ||
          (((iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0x13],local_e0[0x11],local_30,0), iVar8 < 0
            || (iVar8 = FUN_008f69da(param_1,local_8,local_e0[0x14],local_e0[0x13],local_2c,0),
               iVar8 < 0)) ||
           (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0x15],local_e0[0x14],local_e0[0x12],0),
           iVar8 < 0)))) ||
         ((((iVar8 = FUN_008f69da(param_1,local_8,local_e0[0x16],local_e0[0x15],local_e0[0x11],0),
            iVar8 < 0 ||
            (iVar8 = FUN_008f69da(param_1,local_18,local_e0[0x1a],param_3,local_e0[2],0x17),
            iVar8 < 0)) ||
           (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0x1b],local_e0[0x1a],local_28,0), iVar8 < 0)
           ) || ((iVar8 = FUN_008f69da(param_1,local_8,local_e0[0x1c],local_e0[0x16],local_e0[0x1b],
                                       0), iVar8 < 0 ||
                 (iVar8 = FUN_008f69da(param_1,local_1c,local_e0[0x1d],param_2,param_3,0), iVar8 < 0
                 )))))) ||
        ((iVar8 = FUN_008f69da(param_1,local_14,local_e0[0x1e],param_2,param_3,0), iVar8 < 0 ||
         (((iVar8 = FUN_008f69da(param_1,local_10,local_e0[0x1f],local_e0[0x1d],0,0), iVar8 < 0 ||
           (iVar8 = FUN_008f69da(param_1,local_18,local_e0[0x20],local_e0[0x1d],local_e0[0x1f],0x17)
           , iVar8 < 0)) ||
          (iVar8 = FUN_008f69da(param_1,local_10,local_e0[0x21],local_e0[0x1e],0,0), iVar8 < 0))))))
       || (((iVar8 = FUN_008f69da(param_1,local_c | 0x20300000,local_e0[0x22],local_e0[0x1e],
                                  local_e0[0x21],0x17), iVar8 < 0 ||
            (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0x23],local_e0[0x20],local_e0[0x22],0x17),
            iVar8 < 0)) ||
           ((iVar8 = FUN_008f69da(param_1,local_8,local_e0[0x24],local_e0[0x1c],local_e0[0x1c],0),
            iVar8 < 0 ||
            ((iVar8 = FUN_008f69da(param_1,local_10,local_e0[0x25],local_e0[0x24],0,0), iVar8 < 0 ||
             (iVar8 = FUN_008f69da(param_1,uVar1,local_e0[0x26],local_e0[0x23],local_e0[0x25],0),
             iVar8 < 0)))))))) goto LAB_008f8ada;
    uVar1 = local_8;
    param_2 = local_e0[0x1c];
    param_3 = local_e0[0x26];
  }
  else {
    if (param_3 == 0) {
      param_3 = 0;
      uVar1 = param_5 & 0xfffff | 0x10c00000;
    }
    else {
      uVar1 = param_5 & 0xfffff | 0x20600000;
    }
  }
  FUN_008f69da(param_1,uVar1,param_4,param_2,param_3);
LAB_008f8ada:
  _free(local_20);
  return;
}


// ==== FUN_008f8aec @ 0x008f8aec ====

void FUN_008f8aec(undefined4 param_1,undefined4 param_2,uint param_3,int param_4,int *param_5,
                 uint param_6)

{
  int in_ECX;
  void *pvVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_1c [3];
  undefined4 *local_10;
  undefined4 *local_c;
  void *local_8;
  
  local_8 = *(void **)(*(int *)(in_ECX + 8) + 0x6c);
  if ((char)local_8 < '\0') {
    uVar3 = 0;
    if (param_6 != 0) {
      while ((**(byte **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + param_5[uVar3] * 4) & 1) != 0) {
        if (((((uint)local_8 & 4) != 0) && (param_5[uVar3] != *param_5)) ||
           (uVar3 = uVar3 + 1, param_6 <= uVar3)) break;
      }
    }
    if (uVar3 != param_6) goto LAB_008f8c16;
    local_8 = operator_new(param_6 * 0xc);
    if (local_8 == (void *)0x0) goto LAB_008f8d33;
    uVar3 = 0;
    pvVar1 = local_8;
    do {
      local_1c[uVar3 + 2] = (int)pvVar1;
      uVar3 = uVar3 + 1;
      pvVar1 = (void *)((int)pvVar1 + param_6 * 4);
    } while (uVar3 < 3);
    if (param_6 != 0) {
      param_4 = param_4 - (int)local_10;
      iVar2 = param_3 - (int)local_10;
      iVar4 = (int)local_c - (int)local_10;
      param_3 = param_6;
      do {
        *local_10 = *(undefined4 *)(iVar2 + (int)local_10);
        *(undefined4 *)(iVar4 + (int)local_10) = *(undefined4 *)(param_4 + (int)local_10);
        local_10 = local_10 + 1;
        param_3 = param_3 - 1;
      } while (param_3 != 0);
    }
    iVar2 = FUN_008f4c18(local_1c[2],param_6);
    if ((iVar2 < 0) || (iVar2 = FUN_008f4c18(param_2,param_6), iVar2 < 0)) goto LAB_008f8d33;
    iVar2 = FUN_008f69da(param_1,param_6 & 0xfffff | 0x10100000,local_1c[2],param_5,0,0x1a);
    if (iVar2 < 0) goto LAB_008f8d33;
    local_c = (undefined4 *)(param_6 * 4 + (int)local_8);
    param_6 = param_6 & 0xfffff | 0x30000000;
  }
  else {
LAB_008f8c16:
    if (((uint)local_8 & 0x2000000) == 0) {
      local_8 = operator_new(param_6 * 0xc);
      if (local_8 == (void *)0x0) goto LAB_008f8d33;
      uVar3 = 0;
      pvVar1 = local_8;
      do {
        local_1c[uVar3 + 2] = (int)pvVar1;
        uVar3 = uVar3 + 1;
        pvVar1 = (void *)((int)pvVar1 + param_6 * 4);
      } while (uVar3 < 3);
      iVar2 = FUN_008f4c18(local_1c[2],param_6);
      if (((iVar2 < 0) || (iVar2 = FUN_008f4c18(local_10,param_6), iVar2 < 0)) ||
         ((iVar2 = FUN_008f4c18(local_c,param_6), iVar2 < 0 ||
          (iVar2 = FUN_008f4c18(param_2,param_6), iVar2 < 0)))) goto LAB_008f8d33;
      uVar3 = param_6 & 0xfffff;
      iVar2 = FUN_008f69da(param_1,uVar3 | 0x10100000,local_1c[2],param_3,0,0);
      if (iVar2 < 0) goto LAB_008f8d33;
      param_6 = uVar3 | 0x20400000;
      iVar2 = FUN_008f69da(param_1,param_6,local_10,param_4,local_1c[2],0);
      if ((iVar2 < 0) ||
         (iVar2 = FUN_008f69da(param_1,uVar3 | 0x20500000,local_c,param_5,local_10,0), iVar2 < 0))
      goto LAB_008f8d33;
    }
    else {
      local_8 = operator_new(param_6 * 0x14);
      if (local_8 == (void *)0x0) goto LAB_008f8d33;
      uVar3 = 0;
      pvVar1 = local_8;
      do {
        local_1c[uVar3] = (int)pvVar1;
        uVar3 = uVar3 + 1;
        pvVar1 = (void *)((int)pvVar1 + param_6 * 4);
      } while (uVar3 < 5);
      uVar3 = 0;
      if (param_6 != 0) {
        do {
          local_c[uVar3] = *(undefined4 *)(in_ECX + 0x20);
          uVar3 = uVar3 + 1;
        } while (uVar3 < param_6);
      }
      iVar2 = FUN_008f4c18(local_1c[0],param_6);
      if ((((iVar2 < 0) || (iVar2 = FUN_008f4c18(local_1c[1],param_6), iVar2 < 0)) ||
          (iVar2 = FUN_008f4c18(local_1c[2],param_6), iVar2 < 0)) ||
         ((iVar2 = FUN_008f4c18(local_10,param_6), iVar2 < 0 ||
          (iVar2 = FUN_008f4c18(param_2,param_6), iVar2 < 0)))) goto LAB_008f8d33;
      uVar3 = param_6 & 0xfffff;
      iVar2 = FUN_008f69da(param_1,uVar3 | 0x10100000,local_1c[0],param_5,0,0);
      if (iVar2 < 0) goto LAB_008f8d33;
      param_6 = uVar3 | 0x20400000;
      iVar2 = FUN_008f69da(param_1,param_6,local_1c[1],local_1c[0],local_c,0);
      if (iVar2 < 0) goto LAB_008f8d33;
      iVar2 = FUN_008f69da(param_1,uVar3 | 0x20500000,local_1c[2],local_1c[1],param_3,0);
      if ((iVar2 < 0) ||
         (iVar2 = FUN_008f69da(param_1,uVar3 | 0x20500000,local_10,param_5,param_4,0), iVar2 < 0))
      goto LAB_008f8d33;
      param_3 = local_1c[2];
      local_c = local_10;
    }
    local_1c[2] = param_3;
  }
  FUN_008f69da(param_1,param_6,param_2,local_1c[2],local_c,0);
LAB_008f8d33:
  _free(local_8);
  return;
}


// ==== FUN_008f8e95 @ 0x008f8e95 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f8e95(undefined4 param_1,uint param_2,int param_3,int *param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  bool bVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  double local_1c;
  uint local_14 [3];
  void *local_8;
  
  uVar7 = 0;
  bVar8 = param_5 == 0;
  local_8 = (void *)0x0;
  local_14[2] = 1;
  local_14[1] = 1;
  if (param_5 != 0) {
    do {
      iVar2 = FUN_008f683e(*(undefined4 *)(param_3 + uVar7 * 4),&local_1c);
      if (iVar2 < 0) break;
      if (local_1c != _DAT_0099d098) {
        local_14[2] = 0;
      }
      if (local_1c != _DAT_0099d0a0) {
        local_14[1] = 0;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_5);
    bVar8 = uVar7 == param_5;
  }
  uVar7 = 1;
  if ((bVar8) && ((local_14[2] != 0 || (local_14[1] != 0)))) {
    local_8 = operator_new(param_5 << 2);
    if (local_8 == (void *)0x0) goto LAB_008f92af;
    uVar7 = 0;
    if (param_5 != 0) {
      do {
        if (local_14[2] == 0) {
          uVar10 = *(undefined4 *)(in_ECX + 0x20);
        }
        else {
          uVar10 = *(undefined4 *)(in_ECX + 0x24);
        }
        *(undefined4 *)((int)local_8 + uVar7 * 4) = uVar10;
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_5);
    }
    uVar9 = FUN_008f4c18(param_2,param_5);
    if ((int)uVar9 < 0) goto LAB_008f92af;
    uVar10 = 0;
    param_5 = param_5 & 0xfffff | 0x10000000;
    uVar7 = (uint)((ulonglong)uVar9 >> 0x20);
LAB_008f9299:
  }
  else {
    bVar8 = param_5 == 1;
    if (1 < param_5) {
      do {
        if (*param_4 != param_4[uVar7]) break;
        uVar7 = uVar7 + 1;
      } while (uVar7 < param_5);
      bVar8 = uVar7 == param_5;
    }
    if ((!bVar8) || (iVar2 = FUN_008f683e(*param_4,local_14), iVar2 < 0)) {
LAB_008f91d7:
      local_8 = operator_new(param_5 << 3);
      if (local_8 == (void *)0x0) goto LAB_008f92af;
      uVar7 = 0;
      pvVar6 = local_8;
      do {
        local_14[uVar7] = (uint)pvVar6;
        uVar7 = uVar7 + 1;
        pvVar6 = (void *)((int)pvVar6 + param_5 * 4);
      } while (uVar7 < 2);
      iVar2 = FUN_008f4c18(local_14[0],param_5);
      if (((iVar2 < 0) || (iVar2 = FUN_008f4c18(local_14[1],param_5), iVar2 < 0)) ||
         (iVar2 = FUN_008f4c18(param_2,param_5), iVar2 < 0)) goto LAB_008f92af;
      param_5 = param_5 & 0xfffff;
      iVar2 = FUN_008f69da(param_1,param_5 | 0x10600000,local_14[0],param_3,0,0);
      if ((iVar2 < 0) ||
         (iVar2 = FUN_008f69da(param_1,param_5 | 0x20500000,local_14[1],param_4,local_14[0],0),
         iVar2 < 0)) goto LAB_008f92af;
      uVar10 = 4;
      param_5 = param_5 | 0x10500000;
      uVar7 = local_14[1];
      goto LAB_008f9299;
    }
    local_14[2] = __ftol();
    uVar7 = param_2;
    if (_DAT_00a168b8 <= ABS((double)CONCAT44(local_14[1],local_14[0]) - (double)(int)local_14[2]))
    {
      if (ABS(ABS((double)CONCAT44(local_14[1],local_14[0])) - _DAT_00a011c0) < _DAT_00a168b8) {
        iVar2 = FUN_008f4c18(param_2,param_5);
        if (iVar2 < 0) goto LAB_008f92af;
        iVar2 = FUN_008f69da(param_1,param_5 & 0xfffff | 0x10700000,param_2,param_3,0,4);
        if ((iVar2 < 0) || ((double)CONCAT44(local_14[1],local_14[0]) < _DAT_0099d098))
        goto LAB_008f92af;
        uVar10 = 4;
        param_5 = param_5 & 0xfffff | 0x10300000;
        goto LAB_008f9299;
      }
      goto LAB_008f91d7;
    }
    iVar2 = 0;
    iVar5 = 0;
    uVar3 = (local_14[2] ^ (int)local_14[2] >> 0x1f) - ((int)local_14[2] >> 0x1f);
    for (uVar4 = uVar3; uVar4 != 0; uVar4 = uVar4 >> 1) {
      iVar2 = iVar2 + 1;
      iVar5 = iVar5 + (uVar4 & 1);
    }
    uVar4 = (-(uint)(iVar5 != 0) & iVar5 - 1U) + (-(uint)(iVar2 != 0) & iVar2 - 1U);
    if ((int)local_14[2] < 0) {
      uVar4 = uVar4 + param_5;
    }
    if (((*(byte *)(*(int *)(in_ECX + 8) + 0x6c) & 0x40) == 0) ||
       (uVar1 = param_5, (*(byte *)(in_ECX + 0x14) & 0x20) == 0)) {
      iVar2 = *(int *)(*(int *)(in_ECX + 8) + 100);
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      uVar1 = iVar2 * param_5 * 2;
    }
    if (uVar1 + 1 < uVar4) goto LAB_008f91d7;
    local_8 = operator_new(param_5 << 2);
    if (local_8 == (void *)0x0) goto LAB_008f92af;
    uVar4 = 0;
    if (param_5 != 0) {
      do {
        *(undefined4 *)((int)local_8 + uVar4 * 4) = *(undefined4 *)(in_ECX + 0x20);
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_5);
    }
    iVar2 = FUN_008f4c18(param_2,param_5);
    if (iVar2 < 0) goto LAB_008f92af;
    local_14[1] = param_5 & 0xfffff;
    param_4 = (int *)CONCAT13(0x10,(int3)local_14[1]);
    iVar2 = FUN_008f69da(param_1,param_4,param_2,local_8,0,0);
    if (iVar2 < 0) goto LAB_008f92af;
    if (uVar3 != 0) {
      uVar9 = FUN_008f4c18(local_8,param_5);
      iVar2 = (int)((ulonglong)uVar9 >> 0x20);
      if (iVar2 <= (int)uVar9) {
        iVar2 = FUN_008f69da(param_1,param_4,local_8,param_3,iVar2,iVar2);
        while ((-1 < iVar2 &&
               (((uVar3 & 1) == 0 ||
                (iVar2 = FUN_008f69da(param_1,local_14[1] | 0x20500000,param_2,param_2,local_8,0),
                -1 < iVar2))))) {
          uVar3 = uVar3 >> 1;
          if (uVar3 == 0) goto LAB_008f9135;
          iVar2 = FUN_008f69da(param_1,local_14[1] | 0x20500000,local_8,local_8,local_8,4);
        }
      }
      goto LAB_008f92af;
    }
LAB_008f9135:
    if (-1 < (int)local_14[2]) goto LAB_008f92af;
    uVar10 = 0;
    param_5 = local_14[1] | 0x10300000;
  }
  FUN_008f69da(param_1,param_5,param_2,uVar7,0,uVar10);
LAB_008f92af:
  _free(local_8);
  return;
}


// ==== FUN_008f92c1 @ 0x008f92c1 ====

void FUN_008f92c1(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  void *pvVar5;
  undefined8 uVar6;
  int local_14 [3];
  void *local_8;
  
  local_8 = operator_new(param_3 * 0xc);
  if (local_8 != (void *)0x0) {
    uVar3 = 0;
    pvVar5 = local_8;
    do {
      local_14[uVar3] = (int)pvVar5;
      uVar3 = uVar3 + 1;
      pvVar5 = (void *)((int)pvVar5 + param_3 * 4);
    } while (uVar3 < 3);
    uVar3 = 0;
    if (param_3 != 0) {
      do {
        *(undefined4 *)(local_14[0] + uVar3 * 4) = *(undefined4 *)(in_ECX + 0x2c);
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_3);
    }
    iVar4 = FUN_008f4c18(local_14[1],param_3);
    if (-1 < iVar4) {
      uVar6 = FUN_008f4c18(local_14[2],param_3);
      if (-1 < (int)uVar6) {
        iVar4 = FUN_008f69da(param_1,param_3 & 0xfffff | 0x20500000,local_14[1],param_2,
                             (int)((ulonglong)uVar6 >> 0x20),0);
        if ((-1 < iVar4) &&
           (iVar4 = FUN_008f69da(param_1,param_3 & 0xfffff | 0x11000000,local_14[2],local_14[1],0,0)
           , -1 < iVar4)) {
          uVar3 = 0;
          if (param_3 != 0) {
            do {
              iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                              *(int *)(local_14[2] + uVar3 * 4) * 4);
              *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(*(int *)(in_ECX + 8) + 0xa8);
              uVar2 = *(undefined4 *)
                       (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) +
                                *(int *)(*(int *)(in_ECX + 8) + 0xa8) * 4) + 8);
              *(uint *)(iVar4 + 0x10) = uVar3;
              uVar3 = uVar3 + 1;
              *(undefined4 *)(iVar4 + 0xc) = uVar2;
            } while (uVar3 < param_3);
          }
          piVar1 = (int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) +
                                   *(int *)(*(int *)(in_ECX + 8) + 0xa8) * 4) + 8);
          *piVar1 = *piVar1 + 1;
        }
      }
    }
  }
  _free(local_8);
  return;
}


// ==== FUN_008f93f6 @ 0x008f93f6 ====

void FUN_008f93f6(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4,
                 uint param_5)

{
  uint *puVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  void *local_1c [4];
  uint local_c;
  int local_8;
  
  local_8 = in_ECX;
  if ((*(byte *)(*(int *)(in_ECX + 8) + 0x71) & 0x10) == 0) {
    pvVar2 = operator_new(param_5 << 3);
    local_1c[3] = pvVar2;
    if (pvVar2 == (void *)0x0) goto LAB_008f9666;
    iVar3 = FUN_008f4c18(pvVar2,param_5 * 2);
    if (iVar3 < 0) goto LAB_008f9666;
    uVar4 = 0;
    do {
      local_1c[uVar4] = pvVar2;
      uVar4 = uVar4 + 1;
      pvVar2 = (void *)((int)pvVar2 + param_5 * 4);
    } while (uVar4 < 2);
    uVar4 = 0;
    local_c = 4;
    if (param_5 == 0) {
LAB_008f9493:
      uVar4 = param_5 & 0xfffff | 0x10000000;
      iVar3 = 0;
    }
    else {
      do {
        local_c = local_c & **(uint **)(*(int *)(*(int *)(local_8 + 8) + 0x14) +
                                       *(int *)(param_4 + uVar4 * 4) * 4) & 4;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_5);
      if (local_c != 0) goto LAB_008f9493;
      uVar4 = param_5 & 0xfffff | 0x20500000;
      iVar3 = param_4;
    }
    iVar3 = FUN_008f69da(param_1,uVar4,local_1c[0],param_4,iVar3,4);
    if (iVar3 < 0) goto LAB_008f9666;
    iVar3 = FUN_008f69da(param_1,param_5 & 0xfffff | 0x10100000,local_1c[1],local_1c[0],0,8);
    if (iVar3 < 0) goto LAB_008f9666;
    if (param_2 != (undefined4 *)0x0) {
      for (uVar4 = param_5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *param_2 = *(undefined4 *)local_1c[0];
        local_1c[0] = (undefined4 *)((int)local_1c[0] + 4);
        param_2 = param_2 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)param_2 = *(undefined1 *)local_1c[0];
        local_1c[0] = (undefined4 *)((int)local_1c[0] + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
    }
    if (param_3 == (undefined4 *)0x0) goto LAB_008f9666;
  }
  else {
    local_1c[3] = operator_new(param_5 * 0xc);
    if (local_1c[3] == (void *)0x0) goto LAB_008f9666;
    iVar3 = FUN_008f4c18(local_1c[3],param_5 * 3);
    if (iVar3 < 0) goto LAB_008f9666;
    uVar4 = 0;
    pvVar2 = local_1c[3];
    do {
      local_1c[uVar4] = pvVar2;
      uVar4 = uVar4 + 1;
      pvVar2 = (void *)((int)pvVar2 + param_5 * 4);
    } while (uVar4 < 3);
    local_c = param_5 & 0xfffff | 0x10100000;
    iVar3 = FUN_008f69da(param_1,local_c,local_1c[0],param_4,0,0);
    if (iVar3 < 0) goto LAB_008f9666;
    iVar3 = FUN_008f69da(param_1,param_5 & 0xfffff | 0x20100000,local_1c[1],param_4,local_1c[0],4);
    if (iVar3 < 0) goto LAB_008f9666;
    iVar3 = FUN_008f69da(param_1,local_c,local_1c[2],local_1c[1],0,8);
    if (iVar3 < 0) goto LAB_008f9666;
    uVar4 = 0;
    if (param_5 != 0) {
      do {
        if ((**(byte **)(*(int *)(*(int *)(local_8 + 8) + 0x14) + *(int *)(param_4 + uVar4 * 4) * 4)
            & 0x17) == 0) break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_5);
    }
    if ((uVar4 == param_5) && (uVar4 = 0, param_5 != 0)) {
      do {
        puVar1 = *(uint **)(*(int *)(*(int *)(local_8 + 8) + 0x14) +
                           *(int *)((int)local_1c[1] + uVar4 * 4) * 4);
        *puVar1 = *puVar1 | 0x17;
        uVar4 = uVar4 + 1;
      } while (uVar4 < param_5);
    }
    if (param_2 != (undefined4 *)0x0) {
      for (uVar4 = param_5 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
        *param_2 = *(undefined4 *)local_1c[1];
        local_1c[1] = (undefined4 *)((int)local_1c[1] + 4);
        param_2 = param_2 + 1;
      }
      for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
        *(undefined1 *)param_2 = *(undefined1 *)local_1c[1];
        local_1c[1] = (undefined4 *)((int)local_1c[1] + 1);
        param_2 = (undefined4 *)((int)param_2 + 1);
      }
    }
    if (param_3 == (undefined4 *)0x0) goto LAB_008f9666;
    local_1c[1] = local_1c[2];
  }
  for (param_5 = param_5 & 0x3fffffff; param_5 != 0; param_5 = param_5 - 1) {
    *param_3 = *(undefined4 *)local_1c[1];
    local_1c[1] = (undefined4 *)((int)local_1c[1] + 4);
    param_3 = param_3 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)param_3 = *(undefined1 *)local_1c[1];
    local_1c[1] = (undefined4 *)((int)local_1c[1] + 1);
    param_3 = (undefined4 *)((int)param_3 + 1);
  }
LAB_008f9666:
  _free(local_1c[3]);
  return;
}


// ==== FUN_008f9678 @ 0x008f9678 ====

undefined4
FUN_008f9678(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined4 local_8;
  
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    local_8 = 0;
    if (param_3 < *(uint *)(*(int *)(in_ECX + 8) + 4)) {
      iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + param_3 * 4);
    }
    else {
      iVar4 = 0;
    }
    if (iVar4 == 0) {
      uVar2 = 0x80004005;
    }
    else {
      uVar3 = FUN_009153cf(iVar4);
      if (uVar3 < *(uint *)(*(int *)(in_ECX + 8) + 4)) {
        iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + uVar3 * 4);
      }
      else {
        iVar4 = 0;
      }
      if (iVar4 == 0) {
        uVar2 = 0x8007000e;
      }
      else {
        *(uint *)(iVar4 + 4) = *(uint *)(iVar4 + 4) | 0x40;
        uVar1 = *(uint *)(iVar4 + 4);
        if (((uVar1 & 0x10) != 0) && (-1 < (char)uVar1)) {
          if (((uVar1 & 0x200) != 0) && ((*(uint *)(*(int *)(in_ECX + 8) + 0x70) & 0x200) != 0)) {
            *(uint *)(iVar4 + 4) = uVar1 | 0x400;
          }
          if (((*(uint *)(iVar4 + 4) & 0x200) == 0) &&
             ((*(uint *)(*(int *)(in_ECX + 8) + 0x70) & 0x400) != 0)) {
            *(uint *)(iVar4 + 4) = *(uint *)(iVar4 + 4) | 0x100400;
          }
        }
        uVar2 = FUN_008f7257(param_1,param_2,uVar3,param_4,param_5,param_6,&local_8,param_6,param_7,
                             0);
      }
    }
  }
  return uVar2;
}


// ==== FUN_008f974c @ 0x008f974c ====

int FUN_008f974c(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  uint uVar6;
  uint local_8;
  
  bVar2 = true;
  if (param_3 != 0) {
    local_8 = param_3;
    piVar5 = param_2;
    do {
      iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar5 * 4);
      iVar3 = *(int *)(iVar4 + 0x34);
      while ((iVar3 != -1 && (*(int *)(iVar4 + 8) == -1))) {
        iVar1 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *(int *)(iVar4 + 0x34) * 4);
        if (*(int *)(iVar1 + 0x60) == 0) {
          *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)(iVar4 + 0x60);
          *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(iVar4 + 100);
        }
        *piVar5 = *(int *)(iVar4 + 0x34);
        iVar3 = *(int *)(iVar1 + 0x34);
        iVar4 = iVar1;
      }
      if (((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(iVar4 + 4) * 4) + 5)
           & 1) == 0) || (*(int *)(iVar4 + 8) != -1)) {
        bVar2 = false;
      }
      piVar5 = piVar5 + 1;
      local_8 = local_8 - 1;
    } while (local_8 != 0);
  }
  uVar6 = 0;
  if ((param_1 != 0) && (bVar2)) {
    if (param_3 != 0) {
      do {
        iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + param_2[uVar6] * 4);
        iVar3 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,
                             *(undefined8 *)(iVar4 + 0x20));
        param_2[uVar6] = iVar3;
        if (iVar3 == -1) {
          return -0x7ff8fff2;
        }
        iVar3 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar3 * 4);
        *(undefined4 *)(iVar3 + 0x60) = *(undefined4 *)(iVar4 + 0x60);
        uVar6 = uVar6 + 1;
        *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(iVar4 + 100);
      } while (uVar6 < param_3);
    }
    iVar4 = FUN_008f9678(param_1,param_2,*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),1,1,0,0);
    if (iVar4 < 0) {
      return iVar4;
    }
  }
  return 0;
}


// ==== FUN_008f985a @ 0x008f985a ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_008f985a(uint param_1,int param_2,undefined4 *param_3,int *param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint *puVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  int *piVar8;
  int *piVar9;
  double local_28;
  undefined4 local_20;
  int iStack_1c;
  uint *local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  iVar5 = param_1;
  do {
    while( true ) {
      if (iVar5 == -1) {
        return false;
      }
      iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar5 * 4) + 0x48);
      if (iVar5 == -1) {
        return false;
      }
      piVar9 = *(int **)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + iVar5 * 4);
      if (*piVar9 != 0x10000001) break;
LAB_008f98ed:
      iVar5 = *(int *)piVar9[2];
    }
    if (*piVar9 != 0x20500001) {
      if (*piVar9 == 0x20200001) {
        iVar5 = FUN_008f683e(*(undefined4 *)piVar9[2],&local_20);
        if (iVar5 < 0) {
          return false;
        }
        dVar4 = (double)param_2;
        if (param_2 < 0) {
          dVar4 = dVar4 + _DAT_009c2f50;
        }
        if ((double)CONCAT44(iStack_1c,local_20) != dVar4) {
          return false;
        }
        param_1 = *(int *)(piVar9[2] + 4);
        iVar5 = FUN_008f974c(0,&param_1,1);
        if (iVar5 < 0) {
          return false;
        }
        if (*param_4 != -1) {
          return param_1 == *param_4;
        }
        iVar5 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
        pbVar1 = *(byte **)(iVar5 + param_1 * 4);
        if ((*pbVar1 & 2) == 0) {
          return false;
        }
        uVar2 = *(uint *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(pbVar1 + 4) * 4)
                         + 4);
        if ((uVar2 & 0x100) != 0) {
          return false;
        }
        if ((uVar2 & 0x10) == 0) {
          return false;
        }
        if ((uVar2 & 0x200) == 0) {
          return false;
        }
        if (param_3 == (undefined4 *)0x0) goto LAB_008f99c1;
        iVar5 = *(int *)(iVar5 + *(int *)piVar9[2] * 4);
        goto LAB_008f99bc;
      }
      if (*piVar9 != 0x30000001) {
        return false;
      }
      piVar9 = (int *)piVar9[2];
      iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + piVar9[1] * 4);
      if ((*(uint *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(iVar5 + 4) * 4) + 4)
          & 0x100) == 0) {
        return false;
      }
      if (*(int *)(iVar5 + 8) != -1) {
        return false;
      }
      if (_DAT_0099d098 != *(double *)(iVar5 + 0x20)) {
        return false;
      }
      iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + piVar9[2] * 4);
      if ((*(uint *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(iVar5 + 4) * 4) + 4)
          & 0x100) == 0) {
        return false;
      }
      if (*(int *)(iVar5 + 8) != -1) {
        return false;
      }
      if (_DAT_0099d0a0 != *(double *)(iVar5 + 0x20)) {
        return false;
      }
      iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar9 * 4);
      if ((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(iVar5 + 4) * 4) + 4)
          & 2) == 0) {
        return false;
      }
      if (*(int *)(iVar5 + 8) != -1) {
        return false;
      }
      local_18 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + *(int *)(iVar5 + 0x48) * 4);
      if ((*local_18 & 0xfff00000) != 0x20400000) {
        return false;
      }
      param_1 = 0;
      if (local_18[3] == 0) goto LAB_008f9abf;
      piVar8 = (int *)local_18[4];
      break;
    }
    iVar5 = FUN_008f683e(*(undefined4 *)piVar9[2],&local_20);
    if ((iVar5 < 0) || (_DAT_0099d0a0 != (double)CONCAT44(iStack_1c,local_20))) {
      iVar5 = FUN_008f683e(*(undefined4 *)(piVar9[2] + 4),&local_20);
      if (iVar5 < 0) {
        return false;
      }
      if (_DAT_0099d0a0 != (double)CONCAT44(iStack_1c,local_20)) {
        return false;
      }
      goto LAB_008f98ed;
    }
    iVar5 = *(int *)(piVar9[2] + 4);
  } while( true );
  while( true ) {
    param_1 = param_1 + 1;
    piVar8 = piVar8 + 1;
    if (local_18[3] <= param_1) break;
    if (*piVar8 == *piVar9) break;
  }
LAB_008f9abf:
  local_c = 0;
  local_14 = 1;
  do {
    iStack_1c = *(int *)(local_18[2] + (local_18[3] * local_c + param_1) * 4);
    iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iStack_1c * 4);
    if ((((*(byte *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(iVar5 + 4) * 4) + 4)
          & 2) != 0) && (*(int *)(iVar5 + 8) == -1)) &&
       (puVar3 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + *(int *)(iVar5 + 0x48) * 4),
       (*puVar3 & 0xfff00000) == 0x10100000)) {
      local_8 = 0;
      if (puVar3[3] != 0) {
        piVar9 = (int *)puVar3[4];
        do {
          if (*piVar9 == iStack_1c) break;
          local_8 = local_8 + 1;
          piVar9 = piVar9 + 1;
        } while (local_8 < puVar3[3]);
      }
      iVar5 = *(int *)(local_18[2] + (local_18[3] * local_14 + param_1) * 4);
      iVar7 = *(int *)(puVar3[2] + local_8 * 4);
      iVar6 = FUN_008f683e(iVar5,&local_28);
      if (-1 < iVar6) {
        dVar4 = (double)param_2;
        if (param_2 < 0) {
          dVar4 = dVar4 + _DAT_009c2f50;
        }
        if ((local_28 == dVar4) &&
           (local_10 = iVar7, iVar7 = FUN_008f974c(0,&local_10,1), -1 < iVar7)) {
          if (*param_4 == -1) {
            pbVar1 = *(byte **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + local_10 * 4);
            if ((((*pbVar1 & 2) != 0) &&
                (uVar2 = *(uint *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) +
                                           *(int *)(pbVar1 + 4) * 4) + 4), (uVar2 & 0x100) == 0)) &&
               (((uVar2 & 0x10) != 0 && ((uVar2 & 0x200) != 0)))) {
              param_1 = local_10;
              if (param_3 != (undefined4 *)0x0) {
                iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar5 * 4);
LAB_008f99bc:
                *param_3 = *(undefined4 *)(iVar5 + 0x30);
              }
LAB_008f99c1:
              *param_4 = param_1;
              return true;
            }
          }
          else if (local_10 == *param_4) {
            return true;
          }
        }
      }
    }
    local_c = local_c + 1;
    local_14 = local_14 + -1;
    if (1 < local_c) {
      return false;
    }
  } while( true );
}


// ==== FUN_008f9c0f @ 0x008f9c0f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008f9c0f(undefined4 param_1,int param_2,int *param_3,int *param_4)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  undefined4 uVar8;
  int in_ECX;
  byte *pbVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  void *pvVar13;
  uint uVar14;
  int local_80;
  int *local_7c;
  int local_78;
  int *piStack_74;
  double local_70;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  void *local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  byte *local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  local_48 = *(undefined4 *)(in_ECX + 0x2c);
  local_4c = *(undefined4 *)(in_ECX + 0x30);
  local_50 = *(undefined4 *)(in_ECX + 0x34);
  local_60 = *(undefined4 *)(in_ECX + 0x3c);
  local_64 = *(undefined4 *)(in_ECX + 0x40);
  local_10 = (int *)0x0;
  local_1c = (int *)0x0;
  local_20 = (int *)0x0;
  local_5c = (void *)0x0;
  local_58 = 0;
  local_3c = 0;
  local_44 = 0;
  local_40 = 0;
  iVar5 = FUN_008f4f7c(param_2,&local_78);
  if (-1 < iVar5) {
    if ((_DAT_0099d098 < (double)CONCAT44(piStack_74,local_78)) || (local_70 < _DAT_0099d098)) {
      piVar7 = param_3;
    }
    else {
      if (((double)CONCAT44(piStack_74,local_78) != _DAT_0099d098) || (local_70 != _DAT_0099d098))
      goto LAB_008f9cbc;
      piVar7 = param_4;
    }
    FUN_00902d04(piVar7,0);
    goto LAB_008fa904;
  }
LAB_008f9cbc:
  iVar5 = FUN_008f974c(0,&param_2,1);
  if (iVar5 < 0) goto LAB_008fa904;
  local_34 = -1;
  iVar5 = *(int *)(in_ECX + 8);
  pbVar9 = *(byte **)(*(int *)(iVar5 + 0x14) + param_2 * 4);
  local_14 = pbVar9;
  if ((*(int *)(pbVar9 + 0x48) == -1) ||
     (puVar1 = *(uint **)(*(int *)(iVar5 + 0x18) + *(int *)(pbVar9 + 0x48) * 4),
     (*puVar1 & 0xfff00000) != 0x20300000)) {
LAB_008f9e4f:
    if ((*pbVar9 & 1) == 0) {
      local_54 = 0xffffffff;
      local_38 = 0xffffffff;
      local_18 = -1;
      local_30 = -1;
      iVar5 = FUN_008f93f6(param_1,&local_54,&local_38,&param_2,1);
      if (((iVar5 < 0) ||
          (iVar5 = FUN_008f69da(param_1,0x20200001,&local_18,&local_38,&local_54,0x17), iVar5 < 0))
         || (iVar5 = FUN_008f69da(param_1,0x20300001,&local_30,&local_38,&local_54,0x17), iVar5 < 0)
         ) goto LAB_008fa904;
    }
    else {
      local_38 = 0xffffffff;
      local_18 = -1;
      local_30 = -1;
      iVar5 = FUN_008f69da(param_1,0x10100001,&local_38,&param_2,0,0x10);
      if (((iVar5 < 0) ||
          (iVar5 = FUN_008f69da(param_1,0x10000001,&local_18,&param_2,0,0x17), iVar5 < 0)) ||
         (iVar5 = FUN_008f69da(param_1,0x20300001,&local_30,&local_38,&param_2,0x17), iVar5 < 0))
      goto LAB_008fa904;
      uVar11 = *(uint *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(pbVar9 + 4) * 4)
                        + 4);
      local_28 = (int *)0x1;
      if ((((uVar11 & 0x10) != 0) && ((uVar11 & 0x200) != 0)) && (*(int *)(pbVar9 + 8) == -1)) {
LAB_008f9f09:
        local_24 = (int *)0x1;
        goto LAB_008f9f98;
      }
    }
    local_28 = (int *)0x1;
    local_24 = (int *)0x0;
  }
  else {
    local_2c = puVar1[3];
    uVar11 = 0;
    if (local_2c != 0) {
      piVar7 = (int *)puVar1[4];
      do {
        if (*piVar7 == param_2) break;
        uVar11 = uVar11 + 1;
        piVar7 = piVar7 + 1;
        local_28 = piVar7;
      } while (uVar11 < local_2c);
    }
    iVar2 = *(int *)(puVar1[2] + uVar11 * 4);
    local_24 = *(int **)(puVar1[2] + (local_2c + uVar11) * 4);
    iVar3 = *(int *)(*(int *)(*(int *)(iVar5 + 0x14) + iVar2 * 4) + 0x48);
    if (((iVar3 == -1) || ((**(byte **)(*(int *)(iVar5 + 0x14) + (int)local_24 * 4) & 1) == 0)) ||
       (puVar1 = *(uint **)(*(int *)(iVar5 + 0x18) + iVar3 * 4),
       (*puVar1 & 0xfff00000) != 0x10100000)) goto LAB_008f9e4f;
    local_2c = 0;
    if (puVar1[3] != 0) {
      piVar7 = (int *)puVar1[4];
      do {
        if (*piVar7 == iVar2) break;
        local_2c = local_2c + 1;
        piVar7 = piVar7 + 1;
      } while (local_2c < puVar1[3]);
    }
    if (*(int **)(puVar1[2] + local_2c * 4) != local_24) goto LAB_008f9e4f;
    iVar5 = FUN_008f974c(0,&local_24,1);
    if (iVar5 < 0) goto LAB_008fa904;
    local_18 = -1;
    local_30 = -1;
    iVar5 = FUN_008f69da(param_1,0x10000001,&local_18,&local_24,0,0x17);
    if ((iVar5 < 0) ||
       (iVar5 = FUN_008f69da(param_1,0x10000001,&local_30,&param_2,0,0x17), iVar5 < 0))
    goto LAB_008fa904;
    iVar5 = *(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)local_24 * 4);
    uVar11 = *(uint *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x10) + *(int *)(iVar5 + 4) * 4) + 4
                      );
    local_28 = (int *)0x0;
    if (((uVar11 & 0x10) != 0) && (((uVar11 & 0x200) != 0 && (*(int *)(iVar5 + 8) == -1))))
    goto LAB_008f9f09;
    local_24 = (int *)0x0;
  }
LAB_008f9f98:
  iVar5 = FUN_008f974c(0,&local_18,1);
  if (iVar5 < 0) goto LAB_008fa904;
  puVar10 = *(undefined4 **)
             (*(int *)(*(int *)(in_ECX + 8) + 0x10) +
             *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + local_18 * 4) + 4) * 4);
  local_2c = 0;
  local_14 = (byte *)0x1;
  if ((puVar10[1] & 0x800) == 0) {
LAB_008fa056:
    iVar5 = *(int *)(in_ECX + 8);
    if ((*(int *)(iVar5 + 0x58) != 0) ||
       (((*(int *)(iVar5 + 0x54) != 0 && (local_24 != (int *)0x0)) ||
        ((*(int *)(iVar5 + 0x34) != 0 && (*(int *)(in_ECX + 0x30) == -1)))))) {
      pbVar9 = (byte *)0x1;
LAB_008fa07b:
      local_2c = 1;
      local_14 = pbVar9;
    }
  }
  else {
    pcVar6 = _strchr((char *)*puVar10,0x62);
    if ((pcVar6 == (char *)0x0) && (pcVar6 = _strchr((char *)*puVar10,0x42), pcVar6 == (char *)0x0))
    {
      if (((puVar10[1] & 0x800) == 0) ||
         ((pcVar6 = _strchr((char *)*puVar10,99), pcVar6 == (char *)0x0 &&
          (pcVar6 = _strchr((char *)*puVar10,0x43), pcVar6 == (char *)0x0)))) goto LAB_008fa056;
      iVar5 = *(int *)(in_ECX + 8);
      if ((*(int *)(iVar5 + 0x58) != 0) ||
         ((*(int *)(iVar5 + 0x34) != 0 && (*(int *)(in_ECX + 0x30) == -1)))) {
        local_14 = (byte *)0x1;
        local_2c = 1;
      }
      local_24 = (int *)0x0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8);
      pbVar9 = (byte *)0x0;
      if ((*(int *)(iVar5 + 0x54) != 0) && (local_24 != (int *)0x0)) goto LAB_008fa07b;
    }
  }
  if (*(int *)(iVar5 + 0x34) == 0) {
    if (local_14 != (byte *)0x0) {
      if (local_2c != 0) {
        if (local_24 == (int *)0x0) {
          if (*(uint *)(iVar5 + 0x58) <= *(uint *)(in_ECX + 0x40)) goto LAB_008fa0a6;
        }
        else if (*(uint *)(iVar5 + 0x54) <= *(uint *)(in_ECX + 0x3c)) {
LAB_008fa0a6:
          local_2c = 0;
        }
      }
      goto LAB_008fa0a9;
    }
  }
  else {
LAB_008fa0a9:
    if ((local_14 != (byte *)0x0) && ((*(byte *)(in_ECX + 0x15) & 2) != 0)) {
      local_2c = 0;
    }
  }
  if ((local_2c != 0) && ((*(byte *)(in_ECX + 0x15) & 4) != 0)) {
    local_14 = (byte *)0x0;
  }
  local_8 = *(int **)(*(int *)(in_ECX + 4) + 0x18);
  local_c = 0;
  local_10 = operator_new((int)local_8 << 2);
  if (((local_10 == (int *)0x0) ||
      (local_1c = operator_new((int)local_8 << 2), local_1c == (int *)0x0)) ||
     (local_20 = operator_new((int)local_8 << 2), local_20 == (int *)0x0)) goto LAB_008fa904;
  piVar7 = *(int **)(in_ECX + 0x18);
  piVar12 = local_10;
  for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
    *piVar12 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar12 = piVar12 + 1;
  }
  for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(char *)piVar12 = (char)*piVar7;
    piVar7 = (int *)((int)piVar7 + 1);
    piVar12 = (int *)((int)piVar12 + 1);
  }
  if (local_2c == 0) {
LAB_008fa3fa:
    if (local_14 == (byte *)0x0) goto LAB_008fa62b;
    if (param_3 == (int *)0x0) {
      piVar7 = local_10;
      piVar12 = local_1c;
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
    }
    else {
      iVar5 = FUN_008f4c18(in_ECX + 0x2c,1);
      if (iVar5 < 0) goto LAB_008fa904;
      piVar7 = &local_18;
      if (local_28 == (int *)0x0) {
        piVar7 = &local_30;
      }
      iVar5 = FUN_008f69da(param_1,0x20500001,in_ECX + 0x2c,&local_48,piVar7,0x17);
      if ((iVar5 < 0) || (iVar5 = FUN_00902d04(param_3,local_10), iVar5 < 0)) goto LAB_008fa904;
      piVar7 = *(int **)(in_ECX + 0x18);
      piVar12 = local_1c;
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      piVar7 = local_10;
      piVar12 = *(int **)(in_ECX + 0x18);
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      *(undefined4 *)(in_ECX + 0x2c) = local_48;
      local_58 = *(int *)(in_ECX + 0x50);
      *(undefined4 *)(in_ECX + 0x50) = 0;
      local_44 = *(int *)(in_ECX + 0x54);
      *(undefined4 *)(in_ECX + 0x54) = 0;
    }
    if (param_4 == (int *)0x0) {
      piVar7 = local_10;
      piVar12 = local_20;
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
    }
    else {
      iVar5 = FUN_008f4c18(in_ECX + 0x2c,1);
      if (iVar5 < 0) goto LAB_008fa904;
      piVar7 = &local_30;
      if (local_28 == (int *)0x0) {
        piVar7 = &local_18;
      }
      iVar5 = FUN_008f69da(param_1,0x20500001,in_ECX + 0x2c,&local_48,piVar7,0x17);
      if ((iVar5 < 0) || (iVar5 = FUN_00902d04(param_4,local_10), iVar5 < 0)) goto LAB_008fa904;
      piVar7 = *(int **)(in_ECX + 0x18);
      piVar12 = local_20;
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      piVar7 = local_10;
      piVar12 = *(int **)(in_ECX + 0x18);
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      local_40 = *(int *)(in_ECX + 0x54);
      *(undefined4 *)(in_ECX + 0x2c) = local_48;
      local_3c = *(int *)(in_ECX + 0x50);
      *(undefined4 *)(in_ECX + 0x50) = 0;
      *(undefined4 *)(in_ECX + 0x54) = 0;
    }
    local_c = 0;
    param_3 = (int *)0x0;
    if (local_8 != (int *)0x0) {
      local_2c = (int)local_20 - (int)local_1c;
      param_4 = local_1c;
      do {
        iVar5 = *param_4;
        local_24 = (int *)((int)param_4 + local_2c);
        iVar2 = *local_24;
        if (iVar5 != iVar2) {
          if (iVar5 != -1) {
            iVar3 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
            iVar4 = *(int *)(*(int *)(in_ECX + 8) + 0x74);
            if (iVar4 != *(int *)(*(int *)(iVar3 + iVar5 * 4) + 4)) {
              if ((iVar2 == -1) || (iVar4 == *(int *)(*(int *)(iVar3 + iVar2 * 4) + 4))) {
                *local_24 = iVar5;
                *(int *)(*(int *)(in_ECX + 0x18) + (int)param_3 * 4) = iVar5;
              }
              else {
                local_c = local_c + 1;
              }
              goto LAB_008fa617;
            }
          }
          *param_4 = iVar2;
          *(int *)(*(int *)(in_ECX + 0x18) + (int)param_3 * 4) = iVar2;
        }
LAB_008fa617:
        param_3 = (int *)((int)param_3 + 1);
        param_4 = param_4 + 1;
      } while (param_3 < local_8);
      goto LAB_008fa62b;
    }
  }
  else {
    local_2c = *(uint *)(*(int *)(in_ECX + 8) + 0xc);
    if (*(int *)(*(int *)(in_ECX + 8) + 0x34) == 0) {
      if (local_24 == (int *)0x0) {
        *(int *)(in_ECX + 0x40) = *(int *)(in_ECX + 0x40) + 1;
      }
      else {
        *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + 1;
      }
    }
    local_34 = -1;
    iVar5 = FUN_008f69da(param_1,0x10f00001,&local_34,&local_18,0,0);
    if (iVar5 < 0) goto LAB_008fa904;
    iVar5 = *(int *)(in_ECX + 8);
    if (*(int *)(iVar5 + 0x34) == 0) {
      uVar8 = *(undefined4 *)(iVar5 + 0xa0);
    }
    else {
      uVar8 = *(undefined4 *)(iVar5 + 0x90);
    }
    *(undefined4 *)(*(int *)(*(int *)(iVar5 + 0x14) + local_34 * 4) + 4) = uVar8;
    if (param_3 == (int *)0x0) {
      piVar7 = local_10;
      piVar12 = local_1c;
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
    }
    else {
      *(int *)(in_ECX + 0x30) = local_34;
      *(int **)(in_ECX + 0x34) = local_28;
      iVar5 = FUN_00902d04(param_3,local_10);
      if (iVar5 < 0) goto LAB_008fa904;
      piVar7 = *(int **)(in_ECX + 0x18);
      piVar12 = local_1c;
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      piVar7 = local_10;
      piVar12 = *(int **)(in_ECX + 0x18);
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      *(undefined4 *)(in_ECX + 0x30) = local_4c;
      *(undefined4 *)(in_ECX + 0x34) = local_50;
      local_58 = *(int *)(in_ECX + 0x50);
      *(undefined4 *)(in_ECX + 0x50) = 0;
      local_44 = *(int *)(in_ECX + 0x54);
      *(undefined4 *)(in_ECX + 0x54) = 0;
    }
    if (param_4 == (int *)0x0) {
      piVar7 = local_10;
      piVar12 = local_20;
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
    }
    else {
      *(int *)(in_ECX + 0x30) = local_34;
      *(uint *)(in_ECX + 0x34) = (uint)(local_28 == (int *)0x0);
      iVar5 = FUN_00902d04(param_4,local_10);
      if (iVar5 < 0) goto LAB_008fa904;
      piVar7 = *(int **)(in_ECX + 0x18);
      piVar12 = local_20;
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      piVar7 = local_10;
      piVar12 = *(int **)(in_ECX + 0x18);
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      *(undefined4 *)(in_ECX + 0x30) = local_4c;
      *(undefined4 *)(in_ECX + 0x34) = local_50;
      local_3c = *(int *)(in_ECX + 0x50);
      *(undefined4 *)(in_ECX + 0x50) = 0;
      local_40 = *(int *)(in_ECX + 0x54);
      *(undefined4 *)(in_ECX + 0x54) = 0;
    }
    local_c = 0;
    if (local_8 != (int *)0x0) {
      piVar7 = local_1c;
      piVar12 = local_8;
      do {
        if (*piVar7 != *(int *)(((int)local_20 - (int)local_1c) + (int)piVar7)) {
          local_c = local_c + 1;
        }
        piVar7 = piVar7 + 1;
        piVar12 = (int *)((int)piVar12 - 1);
      } while (piVar12 != (int *)0x0);
    }
    *(undefined4 *)(in_ECX + 0x3c) = local_60;
    *(undefined4 *)(in_ECX + 0x40) = local_64;
    if (local_14 != (byte *)0x0) {
      if ((0x10 < local_c) || (0x20 < *(int *)(*(int *)(in_ECX + 8) + 0xc) - local_2c)) {
        local_14 = (byte *)0x0;
      }
      if (local_14 == (byte *)0x0) goto LAB_008fa366;
      if (local_2c < *(uint *)(*(int *)(in_ECX + 8) + 0xc)) {
        puVar10 = (undefined4 *)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + local_2c * 4);
        uVar11 = local_2c;
        do {
          if ((*(uint *)*puVar10 & 0xf0000000) == 0x60000000) {
            local_14 = (byte *)0x0;
            break;
          }
          uVar11 = uVar11 + 1;
          puVar10 = puVar10 + 1;
        } while (uVar11 < *(uint *)(*(int *)(in_ECX + 8) + 0xc));
      }
      if (local_14 == (byte *)0x0) goto LAB_008fa366;
LAB_008fa3a6:
      uVar11 = local_2c;
      uVar14 = local_2c;
      if (local_2c < *(uint *)(*(int *)(in_ECX + 8) + 0xc)) {
        do {
          if (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + uVar14 * 4) != 0) {
            FUN_008f4adb(1);
            uVar11 = local_2c;
          }
          *(undefined4 *)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + uVar14 * 4) = 0;
          uVar14 = uVar14 + 1;
        } while (uVar14 < *(uint *)(*(int *)(in_ECX + 8) + 0xc));
      }
      *(uint *)(*(int *)(in_ECX + 8) + 0xc) = uVar11;
      piVar7 = local_10;
      piVar12 = *(int **)(in_ECX + 0x18);
      for (uVar11 = (uint)local_8 & 0x3fffffff; uVar11 != 0; uVar11 = uVar11 - 1) {
        *piVar12 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar12 = piVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(char *)piVar12 = (char)*piVar7;
        piVar7 = (int *)((int)piVar7 + 1);
        piVar12 = (int *)((int)piVar12 + 1);
      }
      goto LAB_008fa3fa;
    }
LAB_008fa366:
    if ((local_24 == (int *)0x0) &&
       (uVar11 = local_2c, local_2c < *(uint *)(*(int *)(in_ECX + 8) + 0xc))) {
      do {
        iVar5 = FUN_0091494e();
        if (iVar5 != 0) {
          local_14 = (byte *)0x1;
          break;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < *(uint *)(*(int *)(in_ECX + 8) + 0xc));
    }
    if (local_14 != (byte *)0x0) goto LAB_008fa3a6;
LAB_008fa62b:
    uVar11 = local_c;
    if (local_c != 0) {
      local_5c = operator_new(local_c * 0x18);
      if (local_5c == (void *)0x0) goto LAB_008fa904;
      uVar14 = 0;
      pvVar13 = local_5c;
      do {
        (&local_80)[uVar14] = (int)pvVar13;
        uVar14 = uVar14 + 1;
        pvVar13 = (void *)((int)pvVar13 + uVar11 * 4);
      } while (uVar14 < 6);
      if (local_8 != (int *)0x0) {
        local_2c = local_80 - (int)local_7c;
        local_68 = (int)local_1c - (int)local_20;
        param_3 = (int *)(local_78 - (int)local_7c);
        param_4 = local_8;
        piVar7 = local_7c;
        piVar12 = local_20;
        do {
          local_24 = (int *)(local_68 + (int)piVar12);
          if (*local_24 != *piVar12) {
            iVar5 = local_18;
            if (local_28 == (int *)0x0) {
              iVar5 = local_30;
            }
            *(int *)(local_2c + (int)piVar7) = iVar5;
            iVar5 = *local_24;
            if ((iVar5 == -1) ||
               (*(int *)(*(int *)(in_ECX + 8) + 0x74) ==
                *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar5 * 4) + 4))) {
              iVar5 = *(int *)(in_ECX + 0x24);
            }
            *piVar7 = iVar5;
            iVar5 = *piVar12;
            if ((iVar5 == -1) ||
               (*(int *)(*(int *)(in_ECX + 8) + 0x74) ==
                *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar5 * 4) + 4))) {
              iVar5 = *(int *)(in_ECX + 0x24);
            }
            *(int *)((int)param_3 + (int)piVar7) = iVar5;
            piVar7 = piVar7 + 1;
            uVar11 = local_c;
          }
          piVar12 = piVar12 + 1;
          param_4 = (int *)((int)param_4 - 1);
        } while (param_4 != (int *)0x0);
      }
      if (local_14 == (byte *)0x0) {
        uVar11 = local_c & 0xfffff;
        param_3 = (int *)CONCAT13(0x10,(int3)uVar11);
        *(int *)(in_ECX + 0x30) = local_34;
        *(int **)(in_ECX + 0x34) = local_28;
        iVar5 = FUN_008f69da(param_1,param_3,local_7c,local_7c,0,0);
        if (iVar5 < 0) goto LAB_008fa904;
        uVar14 = 0;
        if (local_c != 0) {
          do {
            piVar7 = local_7c + uVar14;
            uVar14 = uVar14 + 1;
            *(undefined4 *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar7 * 4) + 4) =
                 *(undefined4 *)(*(int *)(in_ECX + 8) + 0x98);
          } while (uVar14 < local_c);
        }
        *(int *)(in_ECX + 0x30) = local_34;
        *(uint *)(in_ECX + 0x34) = (uint)(local_28 == (int *)0x0);
        iVar5 = FUN_008f69da(param_1,param_3,local_78,local_78,0,0);
        if (iVar5 < 0) goto LAB_008fa904;
        uVar14 = 0;
        if (local_c != 0) {
          do {
            iVar5 = uVar14 * 4;
            uVar14 = uVar14 + 1;
            *(undefined4 *)
             (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *(int *)(local_78 + iVar5) * 4) + 4)
                 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x98);
          } while (uVar14 < local_c);
        }
        *(undefined4 *)(in_ECX + 0x30) = local_4c;
        *(undefined4 *)(in_ECX + 0x34) = local_50;
        iVar5 = FUN_008f4c18(piStack_74,local_c);
        if (iVar5 < 0) goto LAB_008fa904;
        iVar5 = FUN_008f69da(param_1,uVar11 | 0x20700000,piStack_74,local_7c,local_78,0);
      }
      else {
        iVar5 = FUN_008f8aec(param_1,piStack_74,local_78,local_7c,local_80,uVar11);
      }
      if (iVar5 < 0) goto LAB_008fa904;
      param_3 = (int *)0x0;
      if (local_8 != (int *)0x0) {
        uVar11 = (int)local_20 - (int)local_1c;
        piVar7 = piStack_74;
        local_2c = uVar11;
        do {
          if (local_1c[(int)param_3] != *(int *)((int)(local_1c + (int)param_3) + uVar11)) {
            iVar5 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
            iVar2 = *(int *)(iVar5 + *piVar7 * 4);
            iVar3 = *(int *)(*(int *)(in_ECX + 0x18) + (int)param_3 * 4);
            if (iVar3 != -1) {
              FUN_00914f00(*(undefined4 *)(iVar5 + iVar3 * 4));
            }
            *(int *)(*(int *)(in_ECX + 0x18) + (int)param_3 * 4) = *piVar7;
            *(int **)(iVar2 + 0x30) = param_3;
            piVar7 = piVar7 + 1;
            uVar11 = local_2c;
          }
          param_3 = (int *)((int)param_3 + 1);
        } while (param_3 < local_8);
      }
    }
  }
  if ((local_44 == 0) || (local_40 == 0)) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  *(undefined4 *)(in_ECX + 0x54) = uVar8;
  if (((local_58 == 0) || ((local_3c == 0 && (local_40 == 0)))) &&
     ((local_3c == 0 || ((local_58 == 0 && (local_44 == 0)))))) {
    uVar8 = 0;
  }
  else {
    uVar8 = 1;
  }
  *(undefined4 *)(in_ECX + 0x50) = uVar8;
  if (local_58 == 0) {
LAB_008fa8d4:
    if (local_3c == 0) goto LAB_008fa904;
LAB_008fa8d9:
    if ((local_58 != 0) || (local_44 != 0)) goto LAB_008fa904;
  }
  else {
    if (local_3c != 0) goto LAB_008fa8d9;
    if (local_40 != 0) goto LAB_008fa8d4;
  }
  FUN_008f6353();
LAB_008fa904:
  _free(local_10);
  return;
}


// ==== FUN_008fa94e @ 0x008fa94e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008fa94e(undefined4 param_1,double *param_2,int param_3,double *param_4,uint param_5)

{
  double dVar1;
  double dVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar8;
  double *pdVar9;
  undefined4 *puVar10;
  double *pdVar11;
  undefined4 *puVar12;
  bool bVar13;
  undefined8 uVar14;
  double local_cc;
  double local_c4;
  double local_bc;
  double local_b4;
  double local_ac;
  double local_a4;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  double local_8c;
  void *local_84;
  int local_80 [3];
  undefined4 local_74;
  uint local_70;
  uint local_6c;
  int *local_68;
  int *local_64 [4];
  int local_54;
  int local_50;
  int *local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  double *local_34;
  double *local_30;
  undefined4 *local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 *local_20;
  double *local_1c;
  uint local_18;
  double *local_14;
  int local_10;
  double *local_c;
  double *local_8;
  
  local_80[2] = *(undefined4 *)(in_ECX + 0x30);
  local_74 = *(undefined4 *)(in_ECX + 0x34);
  local_9c = *(undefined4 *)(in_ECX + 0x68);
  local_98 = *(undefined4 *)(in_ECX + 0x6c);
  local_84 = (void *)0x0;
  local_3c = (uint)(param_2 != (double *)0x0);
  local_2c = (undefined4 *)0x0;
  local_20 = (undefined4 *)0x0;
  local_30 = (double *)0x0;
  local_34 = (double *)0x0;
  iVar5 = *(int *)(in_ECX + 8);
  if (*(uint *)(iVar5 + 0x5c) <= *(uint *)(in_ECX + 0x44)) {
    return 0x80004005;
  }
  *(uint *)(in_ECX + 0x44) = *(uint *)(in_ECX + 0x44) + 1;
  local_6c = *(uint *)(iVar5 + 8);
  local_1c = *(double **)(iVar5 + 0xc);
  local_8 = *(double **)(*(int *)(in_ECX + 4) + 0x18);
  local_68 = operator_new((int)local_8 << 2);
  if (((local_68 != (int *)0x0) &&
      (local_2c = operator_new((int)local_8 << 2), local_2c != (undefined4 *)0x0)) &&
     (local_20 = operator_new((int)local_8 << 2), local_20 != (undefined4 *)0x0)) {
    local_14 = (double *)((int)local_8 << 4);
    local_30 = operator_new((uint)local_14);
    if ((local_30 != (double *)0x0) &&
       (local_34 = operator_new((uint)local_14), local_34 != (double *)0x0)) {
      pdVar11 = (double *)0x0;
      if (local_8 != (double *)0x0) {
        param_2 = local_30;
        do {
          iVar5 = *(int *)((int)pdVar11 * 4 + *(int *)(in_ECX + 0x18));
          if ((iVar5 == -1) || (iVar5 = FUN_008f4f7c(iVar5,param_2), iVar5 < 0)) {
            *param_2 = *(double *)(in_ECX + 0xa0);
            param_2[1] = *(double *)(in_ECX + 0xa8);
          }
          iVar5 = *(int *)((int)pdVar11 * 4 + *(int *)(in_ECX + 0x18));
          if ((iVar5 == -1) ||
             (puVar3 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar5 * 4),
             *(uint *)(*(int *)(in_ECX + 8) + 0x74) == puVar3[1])) {
            local_2c[(int)pdVar11] = 0x1f;
          }
          else {
            local_2c[(int)pdVar11] = *puVar3 & 0x1f;
          }
          param_2 = param_2 + 2;
          pdVar11 = (double *)((int)pdVar11 + 1);
        } while (pdVar11 < local_8);
      }
      local_8c = 1.0;
      puVar10 = local_2c;
      puVar12 = local_20;
      for (uVar8 = (uint)local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      pdVar11 = local_30;
      pdVar9 = local_34;
      for (uVar8 = (uint)local_14 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pdVar9 = *(undefined4 *)pdVar11;
        pdVar11 = (double *)((int)pdVar11 + 4);
        pdVar9 = (double *)((int)pdVar9 + 4);
      }
      for (uVar8 = (uint)local_14 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)pdVar9 = *(undefined1 *)pdVar11;
        pdVar11 = (double *)((int)pdVar11 + 1);
        pdVar9 = (double *)((int)pdVar9 + 1);
      }
      local_24 = *(undefined4 *)(in_ECX + 0x20);
      local_80[0] = -1;
      local_80[1] = 0xffffffff;
      local_10 = 1;
      local_38 = 1;
      local_28 = *(uint *)(*(int *)(in_ECX + 8) + 0x68);
      if (local_28 == 0) {
        local_28 = 0xff;
      }
      local_18 = 0;
      if (local_28 != 0) {
        do {
          *(uint *)(in_ECX + 0x68) = local_18;
          local_70 = local_18 + 1;
          *(uint *)(in_ECX + 0x6c) = local_70;
          if ((param_4 != (double *)0x0) && (local_3c != 0)) {
            iVar5 = FUN_00902d04(param_4,0);
            if (iVar5 < 0) goto LAB_008fb72f;
            if (*(int *)(in_ECX + 0x5c) != 0) break;
            if ((*(int *)(in_ECX + 0x50) != 0) || (*(int *)(in_ECX + 0x54) != 0)) goto LAB_008fb72f;
          }
          piVar7 = *(int **)(in_ECX + 0x18);
          piVar6 = local_68;
          for (uVar8 = (uint)local_8 & 0x3fffffff; uVar8 != 0; uVar8 = uVar8 - 1) {
            *piVar6 = *piVar7;
            piVar7 = piVar7 + 1;
            piVar6 = piVar6 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(char *)piVar6 = (char)*piVar7;
            piVar7 = (int *)((int)piVar7 + 1);
            piVar6 = (int *)((int)piVar6 + 1);
          }
          param_2 = (double *)0xffffffff;
          if (param_3 != 0) {
            param_2 = (double *)0xffffffff;
            iVar5 = FUN_00903cbd(param_3,&param_2,0);
            if ((iVar5 < 0) ||
               (iVar5 = FUN_008f69da(param_3,0x20500001,&local_24,&local_24,&param_2,0x17),
               iVar5 < 0)) goto LAB_008fb72f;
            if (*(int *)(in_ECX + 0x5c) != 0) break;
            if ((*(int *)(in_ECX + 0x50) != 0) || (*(int *)(in_ECX + 0x54) != 0)) goto LAB_008fb72f;
          }
          iVar5 = FUN_008f683e(local_24,&local_8c);
          if ((iVar5 < 0) || (_DAT_0099d098 == local_8c)) {
            local_c = (double *)0x0;
            if (local_8 != (double *)0x0) {
              pdVar11 = (double *)(param_5 - (int)local_20);
              pdVar9 = local_34;
              local_14 = pdVar11;
              do {
                puVar3 = local_20 + (int)local_c;
                iVar5 = *(int *)(*(int *)(in_ECX + 0x18) + (int)local_c * 4);
                if (*(int *)((int)puVar3 + (int)pdVar11) != iVar5) {
                  if ((*(double *)(in_ECX + 0xa8) < *pdVar9) ||
                     (pdVar9[1] < *(double *)(in_ECX + 0xa0))) {
                    iVar5 = FUN_008f4f7c(iVar5,&local_bc);
                    if (iVar5 < 0) {
                      *pdVar9 = *(double *)(in_ECX + 0xa0);
                      dVar1 = *(double *)(in_ECX + 0xa8);
                    }
                    else {
                      if (local_bc < *pdVar9) {
                        *pdVar9 = local_bc;
                      }
                      if (local_b4 <= pdVar9[1]) goto LAB_008fad3c;
                      dVar1 = local_b4;
                    }
                    pdVar9[1] = dVar1;
                  }
LAB_008fad3c:
                  *puVar3 = *puVar3 & **(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                                                 *(int *)(*(int *)(in_ECX + 0x18) + (int)local_c * 4
                                                         ) * 4);
                  pdVar11 = local_14;
                }
                local_c = (double *)((int)local_c + 1);
                pdVar9 = pdVar9 + 2;
              } while (local_c < local_8);
            }
          }
          else {
            pdVar11 = (double *)0x0;
            if (local_8 != (double *)0x0) {
              pdVar9 = (double *)(param_5 - (int)local_20);
              local_c = local_34;
              local_14 = pdVar9;
              do {
                puVar10 = local_20 + (int)pdVar11;
                iVar5 = *(int *)(*(int *)(in_ECX + 0x18) + (int)pdVar11 * 4);
                if (*(int *)((int)puVar10 + (int)pdVar9) != iVar5) {
                  iVar5 = FUN_008f4f7c(iVar5,local_c);
                  if (iVar5 < 0) {
                    *local_c = *(double *)(in_ECX + 0xa0);
                    local_c[1] = *(double *)(in_ECX + 0xa8);
                  }
                  *puVar10 = **(undefined4 **)
                               (*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                               *(int *)(*(int *)(in_ECX + 0x18) + (int)pdVar11 * 4) * 4);
                  pdVar9 = local_14;
                }
                local_c = local_c + 2;
                pdVar11 = (double *)((int)pdVar11 + 1);
              } while (pdVar11 < local_8);
            }
          }
          if (param_2 != (double *)0xffffffff) {
            iVar5 = FUN_008f4f7c(param_2,&local_cc);
            if (-1 < iVar5) {
              if ((_DAT_0099d098 == local_cc) && (_DAT_0099d098 == local_c4)) break;
              if ((local_cc <= 0.0) && (!NAN(local_c4) && 0.0 < local_c4 != (local_c4 == 0.0))) {
                local_10 = 0;
              }
            }
            *(undefined8 *)
             (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)param_2 * 4) + 0x20) =
                 0x3ff0000000000000;
            *(undefined8 *)
             (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)param_2 * 4) + 0x28) =
                 0x3ff0000000000000;
          }
          if (local_8 != (double *)0x0) {
            iVar5 = param_5 - (int)local_68;
            local_c = (double *)((int)local_2c - (int)local_68);
            local_14 = local_8;
            pdVar11 = local_30;
            piVar7 = local_68;
            local_94 = iVar5;
            do {
              if (*(int *)(iVar5 + (int)piVar7) != *piVar7) {
                if ((*(double *)(in_ECX + 0xa8) < *pdVar11) ||
                   (pdVar11[1] < *(double *)(in_ECX + 0xa0))) {
                  iVar5 = FUN_008f4f7c(*piVar7,&local_ac);
                  if (iVar5 < 0) {
                    *pdVar11 = *(double *)(in_ECX + 0xa0);
                    dVar1 = *(double *)(in_ECX + 0xa8);
                  }
                  else {
                    if (local_ac < *pdVar11) {
                      *pdVar11 = local_ac;
                    }
                    if (local_a4 <= pdVar11[1]) goto LAB_008fae9f;
                    dVar1 = local_a4;
                  }
                  pdVar11[1] = dVar1;
                }
LAB_008fae9f:
                *(uint *)((int)local_c + (int)piVar7) =
                     *(uint *)((int)local_c + (int)piVar7) &
                     **(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar7 * 4);
                iVar5 = local_94;
              }
              pdVar11 = pdVar11 + 2;
              piVar7 = piVar7 + 1;
              local_14 = (double *)((int)local_14 + -1);
            } while (local_14 != (double *)0x0);
          }
          if (local_38 != 0) {
            if ((local_10 == 0) &&
               (iVar5 = FUN_008f985a(param_2,local_18,local_80,local_80 + 1), iVar5 != 0)) {
              local_38 = 1;
            }
            else {
              local_38 = 0;
            }
          }
          if ((param_4 != (double *)0x0) && (local_3c == 0)) {
            iVar5 = FUN_00902d04(param_4,0);
            if (iVar5 < 0) goto LAB_008fb72f;
            if (*(int *)(in_ECX + 0x5c) != 0) break;
            if ((*(int *)(in_ECX + 0x50) != 0) || (*(int *)(in_ECX + 0x54) != 0)) goto LAB_008fb72f;
          }
          local_18 = local_70;
        } while (local_70 < local_28);
        pdVar11 = local_1c;
        if (1 < local_18) {
          if (local_18 < local_28) {
            if ((*(int *)(in_ECX + 0x60) != 0) || ((*(byte *)(in_ECX + 0x15) & 2) != 0))
            goto LAB_008fb72f;
            if (*(int *)(in_ECX + 0x5c) == 0) {
              local_38 = 0;
            }
          }
          if ((local_10 == 0) && (local_38 == 0)) {
            if ((*(byte *)(*(int *)(in_ECX + 8) + 0x70) & 4) == 0) goto LAB_008fb72f;
            pdVar9 = local_1c;
            if (local_1c < *(double **)(*(int *)(in_ECX + 8) + 0xc)) {
              do {
                iVar5 = FUN_0091494e();
                if (iVar5 != 0) goto LAB_008fb72f;
                pdVar9 = (double *)((int)pdVar9 + 1);
              } while (pdVar9 < *(double **)(*(int *)(in_ECX + 8) + 0xc));
            }
          }
          if (*(int *)(in_ECX + 0x5c) != 0) {
            local_18 = local_28;
            *(undefined4 *)(in_ECX + 0x5c) = 0;
          }
          if (((local_18 != local_28) || (iVar5 = FUN_008f683e(local_24,&local_8c), iVar5 < 0)) ||
             (_DAT_0099d098 == local_8c)) {
            if (((local_18 < local_28) && (local_10 != 0)) && ((*(byte *)(in_ECX + 0x15) & 4) == 0))
            {
              pdVar9 = *(double **)(*(int *)(in_ECX + 8) + 0xc);
              if (pdVar11 < pdVar9) {
                puVar10 = (undefined4 *)(*(int *)(*(int *)(in_ECX + 8) + 0x18) + (int)pdVar11 * 4);
                do {
                  uVar8 = *(uint *)*puVar10 & 0xfff00000;
                  if (uVar8 < 0x20100001) {
                    if (((((uVar8 != 0x20100000) && (uVar8 != 0)) && (uVar8 != 0x10000000)) &&
                        ((uVar8 != 0x10100000 && (uVar8 != 0x10200000)))) && (uVar8 != 0x10400000))
                    {
                      bVar13 = uVar8 == 0x20000000;
LAB_008fb091:
                      if (!bVar13) break;
                    }
                  }
                  else if (((uVar8 != 0x20200000) && (uVar8 != 0x20300000)) &&
                          ((uVar8 != 0x20400000 && (uVar8 != 0x20500000)))) {
                    bVar13 = uVar8 == 0x30000000;
                    goto LAB_008fb091;
                  }
                  pdVar11 = (double *)((int)pdVar11 + 1);
                  puVar10 = puVar10 + 1;
                } while (pdVar11 < *(double **)(*(int *)(in_ECX + 8) + 0xc));
              }
              if (pdVar11 == pdVar9) goto LAB_008fb72f;
            }
            pdVar11 = (double *)0x0;
            iVar5 = 0;
            if (local_8 != (double *)0x0) {
              do {
                iVar4 = *(int *)(param_5 + (int)pdVar11 * 4);
                if ((iVar4 != -1) && (*(int *)(*(int *)(in_ECX + 0x18) + (int)pdVar11 * 4) != iVar4)
                   ) {
                  iVar5 = iVar5 + 1;
                }
                pdVar11 = (double *)((int)pdVar11 + 1);
              } while (pdVar11 < local_8);
            }
            local_84 = operator_new(iVar5 * 0x24);
            if (local_84 != (void *)0x0) {
              uVar14 = FUN_008f4c18(local_84,iVar5 * 9);
              piVar7 = (int *)((ulonglong)uVar14 >> 0x20);
              if (-1 < (int)uVar14) {
                uVar8 = 0;
                do {
                  local_64[uVar8] = piVar7;
                  uVar8 = uVar8 + 1;
                  piVar7 = piVar7 + iVar5;
                } while (uVar8 < 9);
                param_2 = (double *)0x0;
                local_c = (double *)0x0;
                if (local_8 != (double *)0x0) {
                  local_10 = (int)local_64[0] - (int)local_64[2];
                  local_14 = (double *)((int)local_64[2] - (int)local_64[1]);
                  piVar7 = local_64[1];
                  do {
                    piVar6 = (int *)(param_5 + (int)local_c * 4);
                    if ((*piVar6 != -1) &&
                       (*(int *)((int)local_c * 4 + *(int *)(in_ECX + 0x18)) != *piVar6)) {
                      *(double **)((int)local_14 + (int)piVar7 + local_10) = local_c;
                      *piVar7 = *piVar6;
                      *(int *)((int)local_14 + (int)piVar7) = *piVar6;
                      if ((*piVar6 == -1) ||
                         (*(int *)(*(int *)(in_ECX + 8) + 0x74) ==
                          *(int *)(*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar6 * 4) + 4
                                  ))) {
                        *piVar7 = *(int *)(in_ECX + 0x24);
                      }
                      param_2 = (double *)((int)param_2 + 1);
                      piVar7 = piVar7 + 1;
                    }
                    local_c = (double *)((int)local_c + 1);
                  } while (local_c < local_8);
                }
                FUN_008f693c(local_6c,local_1c,param_5);
                param_5 = local_18;
                dVar1 = (double)(int)local_18;
                *(undefined4 *)(in_ECX + 0x68) = 0;
                *(uint *)(in_ECX + 0x6c) = local_18;
                if ((int)local_18 < 0) {
                  dVar1 = dVar1 + _DAT_009c2f50;
                }
                local_90 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,dVar1);
                local_40 = -1;
                iVar5 = FUN_008f69da(param_1,0x11100001,&local_40,&local_90,0,0);
                if (-1 < iVar5) {
                  *(undefined4 *)
                   (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + local_40 * 4) + 4) =
                       *(undefined4 *)(*(int *)(in_ECX + 8) + 0xa4);
                  *(int *)(in_ECX + 0x30) = local_40;
                  param_5 = (uint)param_2 & 0xfffff;
                  *(undefined4 *)(in_ECX + 0x34) = 1;
                  iVar5 = FUN_008f69da(param_1,param_5 | 0x11200000,local_64[2],local_64[1],0,0);
                  if ((-1 < iVar5) &&
                     (iVar5 = FUN_008f69da(param_1,param_5 | 0x11300000,local_44,local_64[2],0,0),
                     -1 < iVar5)) {
                    if (param_2 != (double *)0x0) {
                      local_10 = (int)local_64[0] - (int)local_64[2];
                      local_70 = local_44 - (int)local_64[2];
                      local_1c = param_2;
                      piVar7 = local_64[2];
                      do {
                        puVar3 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar7 * 4);
                        pdVar11 = local_30 + *(int *)(local_10 + (int)piVar7) * 2;
                        dVar1 = *pdVar11;
                        dVar2 = pdVar11[1];
                        if ((!NAN(dVar1) && !NAN(dVar2)) && dVar1 < dVar2 != (dVar1 == dVar2)) {
                          *(double *)(puVar3 + 8) = *pdVar11;
                          dVar1 = pdVar11[1];
                          *(byte *)((int)puVar3 + 1) = *(byte *)((int)puVar3 + 1) | 1;
                          local_6c = *puVar3;
                          *(double *)(puVar3 + 10) = dVar1;
                          if (*pdVar11 == pdVar11[1]) {
                            *puVar3 = local_6c | 0x80;
                          }
                        }
                        *puVar3 = *puVar3 | local_2c[*(int *)(local_10 + (int)piVar7)];
                        *(undefined4 *)
                         (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar7 * 4) + 4) =
                             *(undefined4 *)(*(int *)(in_ECX + 8) + 0x98);
                        piVar6 = (int *)(local_70 + (int)piVar7);
                        piVar7 = piVar7 + 1;
                        local_1c = (double *)((int)local_1c + -1);
                        *(undefined4 *)
                         (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar6 * 4) + 4) =
                             *(undefined4 *)(*(int *)(in_ECX + 8) + 0xac);
                      } while (local_1c != (double *)0x0);
                    }
                    if (((param_4 == (double *)0x0) || (local_3c == 0)) ||
                       (iVar5 = FUN_00902d04(param_4,0), -1 < iVar5)) {
                      local_24 = 0xffffffff;
                      iVar5 = FUN_00903cbd(param_3,&local_24,0);
                      if (-1 < iVar5) {
                        if (param_2 != (double *)0x0) {
                          local_1c = param_2;
                          piVar7 = local_64[2];
                          do {
                            *piVar7 = *(int *)(*(int *)(in_ECX + 0x18) +
                                              *(int *)(((int)local_64[0] - (int)local_64[2]) +
                                                      (int)piVar7) * 4);
                            piVar7 = piVar7 + 1;
                            local_1c = (double *)((int)local_1c + -1);
                          } while (local_1c != (double *)0x0);
                        }
                        iVar5 = FUN_008f4f7c(local_24,&local_ac);
                        if ((iVar5 < 0) ||
                           ((local_ac <= _DAT_0099d098 && (_DAT_0099d098 <= local_a4)))) {
                          if ((local_18 < local_28) &&
                             ((*(byte *)(*(int *)(in_ECX + 8) + 0x70) & 4) == 0)) goto LAB_008fb72f;
                          local_10 = -1;
                          iVar5 = FUN_008f69da(param_1,0x11400001,&local_10,&local_24,0,0);
                          if (iVar5 < 0) goto LAB_008fb72f;
                          *(undefined4 *)
                           (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + local_10 * 4) + 4) =
                               *(undefined4 *)(*(int *)(in_ECX + 8) + 0xa0);
                          *(int *)(in_ECX + 0x30) = local_10;
                          *(undefined4 *)(in_ECX + 0x34) = 1;
                          if (((param_4 != (double *)0x0) && (local_3c == 0)) &&
                             (iVar5 = FUN_00902d04(param_4,0), iVar5 < 0)) goto LAB_008fb72f;
                          if (param_2 != (double *)0x0) {
                            param_4 = param_2;
                            piVar7 = local_64[3];
                            do {
                              *piVar7 = *(undefined4 *)
                                         (*(int *)(in_ECX + 0x18) +
                                         *(int *)(((int)local_64[0] - (int)local_64[3]) +
                                                 (int)piVar7) * 4);
                              piVar7 = piVar7 + 1;
                              param_4 = (double *)((int)param_4 + -1);
                            } while (param_4 != (double *)0x0);
                          }
                          param_4 = (double *)(param_5 | 0x10000000);
                          iVar5 = FUN_008f69da(param_1,param_4,local_54,local_64[3],0,0);
                          if (iVar5 < 0) goto LAB_008fb72f;
                          pdVar11 = (double *)0x0;
                          if (param_2 != (double *)0x0) {
                            do {
                              iVar5 = (int)pdVar11 * 4;
                              pdVar11 = (double *)((int)pdVar11 + 1);
                              *(undefined4 *)
                               (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                                        *(int *)(local_54 + iVar5) * 4) + 4) =
                                   *(undefined4 *)(*(int *)(in_ECX + 8) + 0x98);
                            } while (pdVar11 < param_2);
                          }
                          *(int *)(in_ECX + 0x30) = local_10;
                          *(undefined4 *)(in_ECX + 0x34) = 0;
                          iVar5 = FUN_008f69da(param_1,param_4,local_50,local_64[2],0,0);
                          if (iVar5 < 0) goto LAB_008fb72f;
                          pdVar11 = (double *)0x0;
                          if (param_2 != (double *)0x0) {
                            do {
                              iVar5 = (int)pdVar11 * 4;
                              pdVar11 = (double *)((int)pdVar11 + 1);
                              *(undefined4 *)
                               (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                                        *(int *)(local_50 + iVar5) * 4) + 4) =
                                   *(undefined4 *)(*(int *)(in_ECX + 8) + 0x98);
                            } while (pdVar11 < param_2);
                          }
                          *(int *)(in_ECX + 0x30) = local_40;
                          *(undefined4 *)(in_ECX + 0x34) = 1;
                          iVar5 = FUN_008f69da(param_1,param_5 | 0x20800000,local_4c,local_54,
                                               local_50,0);
                          if (iVar5 < 0) goto LAB_008fb72f;
                          pdVar11 = (double *)0x0;
                          if (param_2 != (double *)0x0) {
                            do {
                              piVar7 = local_4c + (int)pdVar11;
                              pdVar11 = (double *)((int)pdVar11 + 1);
                              *(undefined4 *)
                               (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar7 * 4) + 4) =
                                   *(undefined4 *)(*(int *)(in_ECX + 8) + 0x98);
                            } while (pdVar11 < param_2);
                          }
                        }
                        else {
                          if (((param_4 != (double *)0x0) && (local_3c == 0)) &&
                             (iVar5 = FUN_00902d04(param_4,0), iVar5 < 0)) goto LAB_008fb72f;
                          if (param_2 != (double *)0x0) {
                            param_4 = param_2;
                            piVar7 = local_4c;
                            do {
                              iVar5 = *(int *)(*(int *)(in_ECX + 0x18) +
                                              *(int *)(((int)local_64[0] - (int)local_4c) +
                                                      (int)piVar7) * 4);
                              *piVar7 = iVar5;
                              if (iVar5 == -1) {
                                *piVar7 = *(int *)(in_ECX + 0x24);
                              }
                              piVar7 = piVar7 + 1;
                              param_4 = (double *)((int)param_4 + -1);
                            } while (param_4 != (double *)0x0);
                            param_4 = (double *)0x0;
                          }
                        }
                        iVar5 = FUN_008f69da(param_1,param_5 | 0x10000000,local_4c,local_4c,0,0);
                        if (-1 < iVar5) {
                          pdVar11 = (double *)0x0;
                          if (param_2 != (double *)0x0) {
                            do {
                              piVar7 = local_4c + (int)pdVar11;
                              pdVar11 = (double *)((int)pdVar11 + 1);
                              *(undefined4 *)
                               (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar7 * 4) + 4) =
                                   *(undefined4 *)(*(int *)(in_ECX + 8) + 0x98);
                            } while (pdVar11 < param_2);
                          }
                          iVar5 = FUN_008f69da(param_1,param_5 | 0x20900000,local_48,local_4c,
                                               local_44,0);
                          if (-1 < iVar5) {
                            pdVar11 = (double *)0x0;
                            if (param_2 != (double *)0x0) {
                              do {
                                iVar5 = (int)pdVar11 * 4;
                                pdVar11 = (double *)((int)pdVar11 + 1);
                                *(undefined4 *)
                                 (*(int *)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                                          *(int *)(local_48 + iVar5) * 4) + 4) =
                                     *(undefined4 *)(*(int *)(in_ECX + 8) + 0x98);
                              } while (pdVar11 < param_2);
                            }
                            *(int *)(in_ECX + 0x30) = local_80[2];
                            *(undefined4 *)(in_ECX + 0x34) = local_74;
                            iVar5 = FUN_008f69da(param_1,param_5 | 0x11500000,local_64[2],local_48,0
                                                 ,0);
                            if (-1 < iVar5) {
                              if (param_2 != (double *)0x0) {
                                iVar5 = (int)local_64[2] - (int)local_64[0];
                                param_4 = param_2;
                                do {
                                  puVar3 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) +
                                                     *(int *)(iVar5 + (int)local_64[0]) * 4);
                                  pdVar11 = local_34 + *local_64[0] * 2;
                                  dVar1 = *pdVar11;
                                  dVar2 = pdVar11[1];
                                  if ((!NAN(dVar1) && !NAN(dVar2)) &&
                                      dVar1 < dVar2 != (dVar1 == dVar2)) {
                                    *(double *)(puVar3 + 8) = *pdVar11;
                                    dVar1 = pdVar11[1];
                                    *(byte *)((int)puVar3 + 1) = *(byte *)((int)puVar3 + 1) | 1;
                                    param_5 = *puVar3;
                                    *(double *)(puVar3 + 10) = dVar1;
                                    if (*pdVar11 == pdVar11[1]) {
                                      *puVar3 = param_5 | 0x80;
                                    }
                                  }
                                  *puVar3 = *puVar3 | local_20[*local_64[0]];
                                  local_64[0] = local_64[0] + 1;
                                  param_4 = (double *)((int)param_4 + -1);
                                } while (param_4 != (double *)0x0);
                              }
                              if (((local_18 != 0) && (local_38 != 0)) &&
                                 ((*(int *)(in_ECX + 0x50) == 0 && (*(int *)(in_ECX + 0x54) == 0))))
                              {
                                FUN_008f69da(param_3,0x10000001,
                                             *(int *)(in_ECX + 0x18) + local_80[0] * 4,local_80 + 1,
                                             0,0);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_008fb72f:
  _free(local_68);
  return extraout_EAX;
}


// ==== FUN_008fb78c @ 0x008fb78c ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008fb78c(undefined4 param_1,double *param_2,int param_3,int param_4,int *param_5)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  double *pdVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  double *pdVar9;
  undefined4 *puVar10;
  int *piVar11;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_54;
  int *local_50;
  int local_4c [2];
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  double *local_2c;
  undefined4 *local_28;
  double *local_24;
  int *local_20;
  uint local_1c;
  int *local_18;
  double *local_14;
  uint local_10;
  undefined4 *local_c;
  int *local_8;
  
  local_60 = *(undefined4 *)(in_ECX + 0x58);
  local_3c = *(undefined4 *)(in_ECX + 0x5c);
  local_50 = *(int **)(in_ECX + 0x18);
  piVar8 = *(int **)(*(int *)(in_ECX + 4) + 0x18);
  local_10 = (int)piVar8 << 2;
  local_20 = (int *)0x0;
  local_14 = (double *)0x0;
  local_24 = (double *)0x0;
  local_c = (undefined4 *)0x0;
  local_28 = (undefined4 *)0x0;
  local_18 = piVar8;
  local_8 = operator_new(local_10);
  if ((local_8 != (int *)0x0) && (local_20 = operator_new(local_10), local_20 != (int *)0x0)) {
    uVar6 = (int)piVar8 << 4;
    local_54 = uVar6;
    local_14 = operator_new(uVar6);
    if ((local_14 != (double *)0x0) &&
       (((local_24 = operator_new(uVar6), local_24 != (double *)0x0 &&
         (local_c = operator_new(local_10), local_c != (undefined4 *)0x0)) &&
        (local_28 = operator_new(local_10), local_28 != (undefined4 *)0x0)))) {
      *(undefined4 *)(in_ECX + 0x5c) = 0;
      if (param_2 != (double *)0x0) {
        iVar3 = FUN_00902d04(param_2,0);
        if (iVar3 < 0) goto LAB_008fbdd6;
        if (*(int *)(in_ECX + 0x5c) != 0) {
          local_3c = 1;
        }
        if ((*(int *)(in_ECX + 0x50) != 0) || (*(int *)(in_ECX + 0x54) != 0)) goto LAB_008fbdd6;
      }
      piVar8 = *(int **)(in_ECX + 0x18);
      piVar11 = local_8;
      for (uVar6 = local_10 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *piVar11 = *piVar8;
        piVar8 = piVar8 + 1;
        piVar11 = piVar11 + 1;
      }
      for (uVar6 = local_10 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)piVar11 = (char)*piVar8;
        piVar8 = (int *)((int)piVar8 + 1);
        piVar11 = (int *)((int)piVar11 + 1);
      }
      piVar8 = *(int **)(in_ECX + 0x18);
      piVar11 = param_5;
      for (uVar6 = local_10 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *piVar11 = *piVar8;
        piVar8 = piVar8 + 1;
        piVar11 = piVar11 + 1;
      }
      for (uVar6 = local_10 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(char *)piVar11 = (char)*piVar8;
        piVar8 = (int *)((int)piVar8 + 1);
        piVar11 = (int *)((int)piVar11 + 1);
      }
      piVar8 = (int *)0x0;
      if (local_18 != (int *)0x0) {
        param_2 = local_14;
        do {
          iVar3 = *(int *)((int)piVar8 * 4 + *(int *)(in_ECX + 0x18));
          if ((iVar3 == -1) || (iVar3 = FUN_008f4f7c(iVar3,param_2), iVar3 < 0)) {
            *param_2 = *(double *)(in_ECX + 0xa0);
            param_2[1] = *(double *)(in_ECX + 0xa8);
          }
          iVar3 = *(int *)((int)piVar8 * 4 + *(int *)(in_ECX + 0x18));
          if ((iVar3 == -1) ||
             (puVar1 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + iVar3 * 4),
             *(uint *)(*(int *)(in_ECX + 8) + 0x74) == puVar1[1])) {
            local_c[(int)piVar8] = 0x1f;
          }
          else {
            local_c[(int)piVar8] = *puVar1 & 0x1f;
          }
          param_2 = param_2 + 2;
          piVar8 = (int *)((int)piVar8 + 1);
        } while (piVar8 < local_18);
      }
      local_40 = *(undefined4 *)(in_ECX + 0x20);
      local_38 = 0;
      local_4c[0] = -1;
      local_4c[1] = 0xffffffff;
      local_1c = 0;
      local_34 = 1;
      local_30 = local_40;
      do {
        local_5c = *(undefined4 *)(*(int *)(in_ECX + 8) + 8);
        local_58 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0xc);
        piVar8 = local_8;
        piVar11 = local_20;
        for (uVar6 = local_10 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *piVar11 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar11 = piVar11 + 1;
        }
        for (uVar6 = local_10 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(char *)piVar11 = (char)*piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
          piVar11 = (int *)((int)piVar11 + 1);
        }
        pdVar5 = local_14;
        pdVar9 = local_24;
        for (uVar6 = local_54 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pdVar9 = *(undefined4 *)pdVar5;
          pdVar5 = (double *)((int)pdVar5 + 4);
          pdVar9 = (double *)((int)pdVar9 + 4);
        }
        param_2 = (double *)0xffffffff;
        for (uVar6 = local_54 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)pdVar9 = *(undefined1 *)pdVar5;
          pdVar5 = (double *)((int)pdVar5 + 1);
          pdVar9 = (double *)((int)pdVar9 + 1);
        }
        puVar7 = local_c;
        puVar10 = local_28;
        for (uVar6 = local_10 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *puVar10 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar10 = puVar10 + 1;
        }
        for (uVar6 = local_10 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined1 *)puVar10 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar10 = (undefined4 *)((int)puVar10 + 1);
        }
        if (param_3 != 0) {
          param_2 = (double *)0xffffffff;
          *(int **)(in_ECX + 0x18) = local_8;
          *(undefined4 *)(in_ECX + 0x50) = 0;
          *(undefined4 *)(in_ECX + 0x54) = 0;
          iVar3 = FUN_00903cbd(param_3,&param_2,0);
          if ((iVar3 < 0) ||
             (iVar3 = FUN_008f69da(param_3,0x20500001,&local_40,&local_40,&param_2,0x17), iVar3 < 0)
             ) goto LAB_008fbdd6;
          param_2 = (double *)0xffffffff;
          *(int **)(in_ECX + 0x18) = param_5;
          *(undefined4 *)(in_ECX + 0x50) = 0;
          *(undefined4 *)(in_ECX + 0x54) = 0;
          iVar3 = FUN_00903cbd(param_3,&param_2,0);
          if ((iVar3 < 0) ||
             (iVar3 = FUN_008f69da(param_3,0x20500001,&local_30,&local_30,&param_2,0x17), iVar3 < 0)
             ) goto LAB_008fbdd6;
          if ((*(int *)(in_ECX + 0x58) == 0) &&
             ((*(int *)(in_ECX + 0x50) != 0 || (*(int *)(in_ECX + 0x54) != 0)))) break;
          *(undefined4 *)(in_ECX + 0x50) = 0;
          *(undefined4 *)(in_ECX + 0x54) = 0;
        }
        iVar3 = FUN_008f4f7c(local_30,&local_70);
        if (iVar3 < 0) {
          local_70 = *(double *)(in_ECX + 0xa8);
          local_68 = *(double *)(in_ECX + 0xa0);
        }
        if ((_DAT_0099d098 < local_70) || (local_68 < _DAT_0099d098)) {
          local_38 = 1;
        }
        if (local_18 != (int *)0x0) {
          local_2c = local_14;
          iVar3 = (int)local_c - (int)param_5;
          local_44 = local_18;
          piVar8 = param_5;
          do {
            if (*piVar8 != -1) {
              iVar4 = FUN_008f4f7c(*piVar8,&local_80);
              if (iVar4 < 0) {
                local_80 = *(double *)(in_ECX + 0xa0);
                local_78 = *(double *)(in_ECX + 0xa8);
              }
              if (local_38 == 0) {
                if (local_80 < *local_2c) {
                  *local_2c = local_80;
                }
                if (local_2c[1] < local_78) {
                  local_2c[1] = local_78;
                }
                puVar1 = (uint *)(iVar3 + (int)piVar8);
                *puVar1 = *puVar1 & **(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar8 * 4)
                ;
              }
              else {
                *local_2c = local_80;
                local_2c[1] = local_78;
                *(uint *)(iVar3 + (int)piVar8) =
                     **(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar8 * 4) & 0x1f;
              }
            }
            local_2c = local_2c + 2;
            piVar8 = piVar8 + 1;
            local_44 = (int *)((int)local_44 + -1);
          } while (local_44 != (int *)0x0);
          local_44 = (int *)0x0;
        }
        if ((_DAT_0099d098 == local_70) && (_DAT_0099d098 == local_68)) break;
        if ((local_70 <= 0.0) && (!NAN(local_68) && 0.0 < local_68 != (local_68 == 0.0))) {
          *(undefined4 *)(in_ECX + 0x58) = 1;
        }
        if (local_34 != 0) {
          if (local_38 == 0) {
            iVar3 = FUN_008f985a(param_2,local_1c,local_4c,local_4c + 1);
            local_34 = 1;
            if (iVar3 != 0) goto LAB_008fbbe8;
          }
          local_34 = 0;
        }
LAB_008fbbe8:
        if (local_18 != (int *)0x0) {
          local_2c = (double *)((int)local_8 - (int)param_5);
          local_44 = local_18;
          piVar8 = param_5;
          do {
            if (*(int *)((int)local_2c + (int)piVar8) != *piVar8) {
              iVar3 = *(int *)(*(int *)(in_ECX + 8) + 0x14);
              puVar1 = *(uint **)(iVar3 + *(int *)((int)local_2c + (int)piVar8) * 4);
              puVar2 = *(uint **)(iVar3 + *piVar8 * 4);
              *(ushort *)puVar1 = (ushort)*puVar1 & 0xfe60;
              *puVar1 = *puVar2 & 0x19f | *puVar1;
              *(undefined8 *)(puVar1 + 8) = *(undefined8 *)(puVar2 + 8);
              *(undefined8 *)(puVar1 + 10) = *(undefined8 *)(puVar2 + 10);
            }
            piVar8 = piVar8 + 1;
            local_44 = (int *)((int)local_44 + -1);
          } while (local_44 != (int *)0x0);
        }
        if (param_4 != 0) {
          *(int **)(in_ECX + 0x18) = local_8;
          *(undefined4 *)(in_ECX + 0x50) = 0;
          *(undefined4 *)(in_ECX + 0x54) = 0;
          iVar3 = FUN_008f9c0f(param_3,local_30,param_4,0);
          if (iVar3 < 0) goto LAB_008fbdd6;
          *(int **)(in_ECX + 0x18) = param_5;
          *(undefined4 *)(in_ECX + 0x50) = 0;
          *(undefined4 *)(in_ECX + 0x54) = 0;
          iVar3 = FUN_00902d04(param_4,0);
          if (iVar3 < 0) goto LAB_008fbdd6;
          if ((*(int *)(in_ECX + 0x58) == 0) &&
             ((*(int *)(in_ECX + 0x50) != 0 || (*(int *)(in_ECX + 0x54) != 0)))) break;
          *(undefined4 *)(in_ECX + 0x50) = 0;
          *(undefined4 *)(in_ECX + 0x54) = 0;
        }
        puVar7 = local_c;
        pdVar5 = local_14;
        piVar8 = local_20;
        if (*(int *)(in_ECX + 0x5c) != 0) {
          local_20 = local_8;
          local_14 = local_24;
          local_24 = pdVar5;
          local_8 = piVar8;
          local_c = local_28;
          local_28 = puVar7;
          FUN_008f693c(local_5c,local_58,piVar8);
          *(undefined4 *)(in_ECX + 0x4c) = 0;
          *(undefined4 *)(in_ECX + 0x50) = 0;
          *(undefined4 *)(in_ECX + 0x54) = 0;
          if (local_1c == 0) {
            local_3c = 1;
          }
          break;
        }
        local_1c = local_1c + 1;
      } while (local_1c < 0x400);
      if (local_1c == 0x400) {
        FUN_008f6353();
      }
      else {
        if (local_18 != (int *)0x0) {
          param_5 = local_18;
          pdVar5 = local_14;
          piVar8 = local_8;
          do {
            if (*piVar8 != -1) {
              puVar1 = *(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + *piVar8 * 4);
              *(double *)(puVar1 + 8) = *pdVar5;
              *(double *)(puVar1 + 10) = pdVar5[1];
              *puVar1 = *(uint *)(((int)local_c - (int)local_8) + (int)piVar8) | 0x180;
            }
            pdVar5 = pdVar5 + 2;
            piVar8 = piVar8 + 1;
            param_5 = (int *)((int)param_5 + -1);
          } while (param_5 != (int *)0x0);
        }
        uVar6 = local_10 >> 2;
        *(int **)(in_ECX + 0x18) = local_50;
        piVar8 = local_8;
        piVar11 = local_50;
        for (; uVar6 != 0; uVar6 = uVar6 - 1) {
          *piVar11 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar11 = piVar11 + 1;
        }
        for (uVar6 = local_10 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(char *)piVar11 = (char)*piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
          piVar11 = (int *)((int)piVar11 + 1);
        }
        if ((((local_1c != 0) && (local_34 != 0)) && (*(int *)(in_ECX + 0x50) == 0)) &&
           (*(int *)(in_ECX + 0x54) == 0)) {
          FUN_008f69da(param_3,0x10000001,*(int *)(in_ECX + 0x18) + local_4c[0] * 4,local_4c + 1,0,0
                      );
        }
      }
    }
  }
LAB_008fbdd6:
  *(int **)(in_ECX + 0x18) = local_50;
  _free(local_8);
  return;
}


// ==== FUN_008fbe24 @ 0x008fbe24 ====

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008fbe24(uint *******param_1,uint *******param_2)

{
  int *piVar1;
  uint *****pppppuVar2;
  float10 fVar3;
  float10 fVar4;
  uint *******pppppppuVar5;
  int iVar6;
  uint ******ppppppuVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  uint *****pppppuVar11;
  uint ******ppppppuVar12;
  uint uVar13;
  undefined4 extraout_EAX;
  int in_ECX;
  uint uVar14;
  uint *******pppppppuVar15;
  uint *******pppppppuVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  ulonglong uVar19;
  longlong lVar20;
  undefined1 local_1f8 [12];
  undefined1 local_1ec [12];
  undefined1 local_1e0 [12];
  undefined1 local_1d4 [12];
  undefined1 local_1c8 [12];
  undefined1 local_1bc [12];
  undefined1 local_1b0 [12];
  undefined1 local_1a4 [12];
  undefined1 local_198 [12];
  undefined1 local_18c [12];
  undefined1 local_180 [12];
  undefined1 local_174 [12];
  int local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined1 local_15c [12];
  uint ******local_150;
  uint ******local_14c;
  uint ******local_148;
  uint ******local_144;
  uint ******local_140;
  uint ******local_13c;
  uint ******local_138;
  uint ******local_134;
  uint ******local_130;
  uint ******local_12c;
  uint ******local_128;
  uint ******local_124;
  uint ******local_120;
  uint ******local_11c;
  uint ******local_118;
  undefined1 local_114 [4];
  undefined1 local_110 [4];
  undefined1 local_10c [4];
  int local_108 [2];
  uint ******local_100 [3];
  uint *****local_f4 [3];
  uint *******local_e8;
  uint local_e4;
  int local_e0;
  undefined4 *local_dc;
  int local_d8;
  int local_d4;
  int local_d0;
  uint ******local_cc;
  uint *******local_c8;
  uint ******local_c4;
  uint ******local_c0;
  uint local_bc;
  uint ******local_b8;
  uint ******local_b4;
  uint ******local_b0;
  uint ******local_ac;
  uint ******local_a8 [10];
  int local_80;
  int local_7c;
  uint ******local_78;
  uint *******local_74;
  uint ******local_70;
  uint *******local_6c;
  uint *******local_68;
  uint *******local_64;
  uint *******local_60;
  uint *******local_5c;
  uint ******local_58;
  uint *******local_54;
  uint *******local_50;
  uint *******local_4c [4];
  uint ******local_3c;
  uint *******local_38;
  uint ******local_34 [2];
  uint *******local_2c;
  uint *******local_28;
  uint ******ppppppuStack_24;
  uint *******local_20;
  uint *puStack_1c;
  uint *******local_18;
  uint *******local_14;
  uint *******local_10;
  uint *******local_c;
  uint *******local_8;
  
  if (param_1 == (uint *******)0x0) {
    if (param_2 == (uint *******)0x0) {
      return 0;
    }
    return 0x80004005;
  }
  if (*(int *)((int)param_1 + 4) != 0xd) {
    return 0x80004005;
  }
  local_8 = (uint *******)(*(int *)((int)param_1 + 0x14) * *(int *)((int)param_1 + 0x18));
  local_168 = *(int *)((int)param_1 + 0x24);
  if (*(int *)((int)param_1 + 0x1c) != 0x1a) {
    return 0x80004005;
  }
  local_160 = *(undefined4 *)(in_ECX + 0x1c);
  local_28 = (uint *******)0x0;
  ppppppuStack_24 = (uint ******)0x0;
  local_20 = (uint *******)0x0;
  puStack_1c = (uint *)0x0;
  local_68 = *(uint ********)(local_168 + 8);
  local_c0 = (uint ******)0x0;
  local_bc = 0;
  local_b8 = (uint ******)0x0;
  local_b4 = (uint ******)0x0;
  local_4c[0] = (uint *******)0x0;
  local_4c[1] = (uint *******)0x0;
  local_4c[2] = (uint *******)0x0;
  local_4c[3] = (uint *******)0x0;
  local_164 = *(undefined4 *)(in_ECX + 100);
  local_60 = (uint *******)0xe000000;
  if (local_68 == (uint *******)0x0) {
LAB_008fbf54:
    local_60 = (uint *******)0x0;
  }
  else {
    local_10 = (uint *******)0x0;
    do {
      pppppppuVar15 = local_10;
      ppppppuVar12 = local_68[2];
      if (ppppppuVar12 != (uint ******)0x0) {
        pppppuVar11 = ppppppuVar12[6];
        pppppuVar2 = ppppppuVar12[5];
        *(int *)((int)&local_c0 + (int)local_10) = (int)pppppuVar11 * (int)pppppuVar2;
        piVar1 = (int *)((int)&local_28 + (int)pppppppuVar15);
        *piVar1 = (int)ppppppuVar12;
        pppppppuVar5 = operator_new((int)pppppuVar11 * (int)pppppuVar2 * 4);
        *(uint ********)((int)local_4c + (int)pppppppuVar15) = pppppppuVar5;
        local_18 = pppppppuVar5;
        if (pppppppuVar5 == (uint *******)0x0) goto LAB_00901a0e;
        iVar6 = FUN_00903cbd(*piVar1,pppppppuVar5,0);
        if (iVar6 < 0) goto LAB_00901a0e;
        if (*(int *)((int)&local_c0 + (int)local_10) != 0) {
          iVar6 = *(int *)((int)&local_c0 + (int)local_10);
          pppppppuVar15 = local_18;
          do {
            local_60 = (uint *******)
                       ((uint)local_60 &
                       **(uint **)(*(int *)(*(int *)(in_ECX + 8) + 0x14) + (int)*pppppppuVar15 * 4))
            ;
            pppppppuVar15 = pppppppuVar15 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
      local_68 = (uint *******)local_68[3];
      local_10 = local_10 + 1;
    } while (local_68 != (uint *******)0x0);
    if (local_60 == (uint *******)0xe000000) goto LAB_008fbf54;
  }
  pppppppuVar15 = local_8;
  ppppppuVar12 = local_c0;
  *(uint ********)(in_ECX + 100) = local_60;
  switch(*(undefined4 *)(*(int *)(*(int *)((int)param_1 + 0x20) + 8) + 0x18)) {
  case 0:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_14 = (uint *******)FUN_008f4afb();
      if (local_14 == (uint *******)0x0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_14,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,local_14,local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(4,local_14);
      pppppppuVar15 = (uint *******)((uint)local_c | 0x20100000);
LAB_008fc009:
      local_e8 = local_4c[0];
      goto LAB_008fc00c;
    }
    break;
  case 1:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      lVar20 = CONCAT44(local_8,param_2);
      param_2 = (uint *******)0x0;
LAB_008fc541:
      iVar6 = FUN_008f7d48(param_1,local_4c[0],param_2,lVar20);
      goto LAB_008fc01a;
    }
    break;
  case 2:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      if (local_c0 == (uint ******)0x1) {
        iVar6 = FUN_008f4c18(&local_18,1);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(&local_50,1);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(param_2,1);
        pppppppuVar15 = local_4c[0];
        if (iVar6 < 0) goto LAB_00901a0e;
      }
      else {
        if (local_c0 == (uint ******)0x2) {
          iVar6 = FUN_008f4c18(&local_18,1);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(&local_50,1);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(&local_6c,1);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(param_2,1);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20500001,&local_18,local_4c[0],local_4c[0] + 1,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f93f6(param_1,&local_50,&local_6c,&local_18);
          if (iVar6 < 0) goto LAB_00901a0e;
          uVar19 = CONCAT44(0x17,&local_50);
          local_e8 = (uint *******)&local_6c;
          goto LAB_008fc137;
        }
        if (local_c0 != (uint ******)0x3) {
          ppppppuVar7 = (uint ******)FUN_008f4afb();
          if (ppppppuVar7 == (uint ******)0x0) goto LAB_00901a0e;
          uVar13 = 0;
          do {
            (&local_5c)[uVar13] = (uint *******)ppppppuVar7;
            uVar13 = uVar13 + 1;
            ppppppuVar7 = ppppppuVar7 + (int)ppppppuVar12;
          } while (uVar13 < 3);
          iVar6 = FUN_008f4c18(local_5c,local_c0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(local_58,local_c0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(local_54,local_c0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(&local_10,1);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(&local_18,1);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(param_2,1);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_60 = (uint *******)((uint)local_c0 & 0xfffff);
          iVar6 = FUN_008f69da(param_1,(uint)local_60 | 0x20500000,local_5c,local_4c[0],local_4c[0],
                               4);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,(uint)local_60 | 0x10100000,local_58,local_5c,0,8);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,(uint)local_60 | 0x20300000,local_54,local_58,local_5c,0x17);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,(uint)local_60 | 0x50000000,&local_10,local_54,local_54,6);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x10100001,&local_18,&local_10,0,10);
          if (iVar6 < 0) goto LAB_00901a0e;
          uVar19 = CONCAT44(0x17,&local_10);
          local_e8 = (uint *******)&local_18;
          pppppppuVar15 = (uint *******)0x20300001;
          goto LAB_008fc010;
        }
        iVar6 = FUN_008f4c18(&local_58,2);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(&local_18,1);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(&local_50,1);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(param_2,1);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x20500001,&local_58,local_4c[0],local_4c[0] + 1,0);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x20500001,&local_54,&local_58,local_4c[0] + 2,0);
        if (iVar6 < 0) goto LAB_00901a0e;
        pppppppuVar15 = (uint *******)&local_54;
      }
      iVar6 = FUN_008f93f6(param_1,&local_18,&local_50,CONCAT44(1,pppppppuVar15));
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(0x17,&local_18);
      local_e8 = (uint *******)&local_50;
LAB_008fc137:
      pppppppuVar15 = (uint *******)0x20200001;
      goto LAB_008fc010;
    }
    break;
  case 3:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(&local_10,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_18,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c0 & 0xfffff | 0x50000000,&local_10,local_4c[0],
                           local_4c[0],4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10100001,&local_18,&local_10,0,8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(0x17,&local_10);
      local_e8 = (uint *******)&local_18;
      goto LAB_008fc137;
    }
    break;
  case 4:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      lVar20 = ZEXT48(local_8) << 0x20;
      goto LAB_008fc541;
    }
    break;
  case 5:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      pppppppuVar15 = (uint *******)0x0;
LAB_008fc5c4:
      iVar6 = FUN_008f82c6(param_1,local_4c[0],pppppppuVar15,CONCAT44(local_8,param_2));
      goto LAB_008fc01a;
    }
    break;
  case 6:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      pppppppuVar15 = local_4c[1];
      goto LAB_008fc5c4;
    }
    break;
  case 7:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_14 = (uint *******)FUN_008f4afb();
      if (local_14 == (uint *******)0x0) goto LAB_00901a0e;
      local_10 = local_14 + (int)local_8;
      uVar18 = FUN_008f4c18(local_14,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18((int)((ulonglong)uVar18 >> 0x20),local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,local_14,local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar9 = 0x14;
      uVar13 = (uint)local_c | 0x10400000;
LAB_008fc681:
      iVar6 = FUN_008f69da(param_1,uVar13,local_10,local_14,0,uVar9);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(2,local_10);
      local_e8 = local_4c[0];
LAB_008fc6a5:
      pppppppuVar15 = (uint *******)((uint)local_c | 0x20400000);
      goto LAB_008fc00c;
    }
    break;
  case 8:
    if (((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0)) ||
       (local_20 == (uint *******)0x0)) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_14 = (uint *******)FUN_008f4afb();
      if (local_14 == (uint *******)0x0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_14,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20100000,local_14,local_4c[0],local_4c[1],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[2]);
      local_e8 = local_14;
LAB_0090041e:
      pppppppuVar15 = (uint *******)((uint)local_c | 0x20000000);
      goto LAB_008fc00c;
    }
    break;
  case 9:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    iVar6 = FUN_008f92c1(param_1,local_4c[0]);
    goto LAB_008fc01a;
  case 10:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      lVar20 = CONCAT44(local_8,param_2);
      param_2 = (uint *******)0x0;
      goto LAB_0090062a;
    }
    break;
  case 0xb:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      fVar4 = (float10)log2((float10)_DAT_00a0b350);
      local_54 = (uint *******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,
                              (double)((float10)_DAT_0099d0a0 /
                                      ((float10)0.6931471805599453 * fVar4)));
      local_70 = (uint ******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a011c0);
      pppppppuVar15 = local_8;
      pppppuVar11 = (uint *****)FUN_008f4afb();
      if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_34[uVar13] = (uint ******)pppppuVar11;
        uVar13 = uVar13 + 1;
        pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
      } while (uVar13 < 7);
      if (pppppppuVar15 != (uint *******)0x0) {
        pppppppuVar5 = (uint *******)puStack_1c;
        do {
          *(uint ********)(((int)local_20 - (int)puStack_1c) + (int)pppppppuVar5) = local_54;
          *pppppppuVar5 = local_70;
          pppppppuVar5 = pppppppuVar5 + 1;
          pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1);
        } while (pppppppuVar15 != (uint *******)0x0);
      }
      iVar6 = FUN_008f4c18(local_34[0],local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_34[1],local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_2c,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_28,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      local_64 = (uint *******)((uint)local_c | 0x20500000);
      iVar6 = FUN_008f69da(param_1,local_64,local_34[0],local_4c[0],local_20,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_10 = (uint *******)((uint)local_c | 0x10500000);
      iVar6 = FUN_008f69da(param_1,local_10,local_34[1],local_34[0],0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,local_2c,local_34[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_10,local_28,local_2c,0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20400000,ppppppuStack_24,local_34[1],local_28,4
                          );
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar9 = 4;
LAB_008fc9a0:
      uVar19 = CONCAT44(uVar9,puStack_1c);
      local_e8 = (uint *******)ppppppuStack_24;
LAB_00900fb1:
      pppppppuVar15 = local_64;
      goto LAB_008fc010;
    }
    break;
  case 0xc:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_5c = (uint *******)local_4c[0][1];
      local_58 = local_4c[0][2];
      local_54 = (uint *******)*local_4c[0];
      local_cc = local_4c[1][2];
      local_c8 = (uint *******)*local_4c[1];
      local_c4 = local_4c[1][1];
      local_150 = local_4c[0][2];
      local_14c = *local_4c[0];
      local_148 = local_4c[0][1];
      local_78 = local_4c[1][1];
      local_74 = (uint *******)local_4c[1][2];
      local_70 = *local_4c[1];
      uVar18 = FUN_008f4c18(&ppppppuStack_24,3);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(local_15c,(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(&local_bc,(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,(int)((ulonglong)uVar18 >> 0x20));
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      local_64 = (uint *******)((uint)local_c | 0x20500000);
      iVar6 = FUN_008f69da(param_1,local_64,&ppppppuStack_24,&local_5c,&local_cc,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_64,local_15c,&local_150,&local_78,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,&local_bc,local_15c,0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(&local_bc);
      local_e8 = &ppppppuStack_24;
      goto LAB_008fc6a5;
    }
    break;
  case 0xd:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = 0;
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x10d00000);
      local_e8 = local_4c[0];
LAB_00900c41:
      goto LAB_008fc010;
    }
    break;
  case 0xe:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = 0;
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x10e00000);
      local_e8 = local_4c[0];
      goto LAB_00900c41;
    }
    break;
  case 0xf:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = _DAT_00a20250;
LAB_008ffafe:
      uVar9 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,uVar18);
      puVar10 = (undefined4 *)FUN_008f4afb();
      if (puVar10 == (undefined4 *)0x0) goto LAB_00901a0e;
      if (local_8 != (uint *******)0x0) {
        for (pppppppuVar15 = local_8; pppppppuVar15 != (uint *******)0x0;
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1)) {
          *puVar10 = uVar9;
          puVar10 = puVar10 + 1;
        }
      }
LAB_008ffb36:
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      local_e8 = local_4c[0];
      pppppppuVar15 = (uint *******)((ulonglong)uVar18 >> 0x20);
LAB_008ffb52:
      uVar19 = ZEXT48(pppppppuVar15);
      pppppppuVar15 = (uint *******)((uint)local_8 & 0xfffff);
      goto LAB_00900d31;
    }
    break;
  case 0x10:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      if (local_c0 != (uint ******)0x1) {
        ppppppuVar12 = local_28[5];
        if (ppppppuVar12 == (uint ******)0x2) {
          iVar6 = FUN_008f4c18(&local_cc,3);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(param_2,local_8);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_74 = (uint *******)*local_4c[0];
          local_58 = local_4c[0][3];
          local_70 = local_4c[0][1];
          local_54 = (uint *******)local_4c[0][2];
          iVar6 = FUN_008f69da(param_1,0x20500002,&local_cc,&local_74,&local_58,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x10100001,&local_c4,&local_c8,0,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          uVar19 = ZEXT48(&local_c4);
          local_e8 = &local_cc;
          goto LAB_008fccac;
        }
        if (ppppppuVar12 == (uint ******)0x3) {
          uVar18 = FUN_008f4c18(local_15c,3);
          if ((int)uVar18 < 0) goto LAB_00901a0e;
          uVar18 = FUN_008f4c18(&ppppppuStack_24,(int)((ulonglong)uVar18 >> 0x20));
          if ((int)uVar18 < 0) goto LAB_00901a0e;
          uVar18 = FUN_008f4c18(&local_bc,(int)((ulonglong)uVar18 >> 0x20));
          if ((int)uVar18 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(&local_150,(int)((ulonglong)uVar18 >> 0x20));
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(param_2,local_8);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_5c = (uint *******)local_4c[0][4];
          local_58 = local_4c[0][7];
          local_54 = (uint *******)local_4c[0][1];
          local_78 = local_4c[0][8];
          local_74 = (uint *******)local_4c[0][2];
          local_70 = local_4c[0][5];
          iVar6 = FUN_008f69da(param_1,0x20500003,local_15c,&local_5c,&local_78,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_5c = (uint *******)local_4c[0][7];
          local_58 = local_4c[0][1];
          local_54 = (uint *******)local_4c[0][4];
          local_78 = local_4c[0][5];
          local_74 = (uint *******)local_4c[0][8];
          local_70 = local_4c[0][2];
          iVar6 = FUN_008f69da(param_1,0x20500003,&ppppppuStack_24,&local_5c,&local_78,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x10100003,&local_bc,&ppppppuStack_24,0,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20400003,&local_150,local_15c,&local_bc,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_5c = (uint *******)*local_4c[0];
          local_58 = local_4c[0][3];
          local_54 = (uint *******)local_4c[0][6];
          uVar19 = ZEXT48(&local_5c);
          local_e8 = &local_150;
          pppppppuVar15 = (uint *******)0x50000003;
        }
        else {
          if (ppppppuVar12 != (uint ******)0x4) break;
          uVar18 = FUN_008f4c18(local_1c8,0xc);
          if ((int)uVar18 < 0) goto LAB_00901a0e;
          uVar18 = FUN_008f4c18(local_198,(int)((ulonglong)uVar18 >> 0x20));
          if ((int)uVar18 < 0) goto LAB_00901a0e;
          uVar18 = FUN_008f4c18(local_1f8,(int)((ulonglong)uVar18 >> 0x20));
          if ((int)uVar18 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(local_108 + 2,(int)((ulonglong)uVar18 >> 0x20));
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(&local_28,4);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f4c18(param_2,local_8);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_b0 = local_4c[0][10];
          local_ac = local_4c[0][0xe];
          local_a8[0] = local_4c[0][6];
          local_a8[1] = local_4c[0][0xe];
          local_a8[2] = local_4c[0][2];
          local_a8[3] = local_4c[0][10];
          local_a8[4] = local_4c[0][6];
          local_a8[5] = local_4c[0][0xe];
          local_a8[6] = local_4c[0][2];
          local_a8[7] = local_4c[0][10];
          local_a8[8] = local_4c[0][2];
          local_a8[9] = local_4c[0][6];
          local_144 = local_4c[0][0xf];
          local_140 = local_4c[0][7];
          local_13c = local_4c[0][0xb];
          local_138 = local_4c[0][0xb];
          local_134 = local_4c[0][0xf];
          local_130 = local_4c[0][3];
          local_12c = local_4c[0][0xf];
          local_128 = local_4c[0][3];
          local_124 = local_4c[0][7];
          local_120 = local_4c[0][7];
          local_11c = local_4c[0][0xb];
          local_118 = local_4c[0][3];
          iVar6 = FUN_008f69da(param_1,0x20500003,local_1c8,&local_b0,&local_144,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20500003,local_1bc,local_a8 + 1,&local_138,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20500003,local_1b0,local_a8 + 4,&local_12c,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20500003,local_1a4,local_a8 + 7,&local_120,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_b0 = local_4c[0][0xe];
          local_ac = local_4c[0][6];
          local_a8[0] = local_4c[0][10];
          local_a8[1] = local_4c[0][10];
          local_a8[2] = local_4c[0][0xe];
          local_a8[3] = local_4c[0][2];
          local_a8[4] = local_4c[0][0xe];
          local_a8[5] = local_4c[0][2];
          local_a8[6] = local_4c[0][6];
          local_a8[7] = local_4c[0][6];
          local_a8[8] = local_4c[0][10];
          local_a8[9] = local_4c[0][2];
          local_144 = local_4c[0][0xb];
          local_140 = local_4c[0][0xf];
          local_13c = local_4c[0][7];
          local_138 = local_4c[0][0xf];
          local_134 = local_4c[0][3];
          local_130 = local_4c[0][0xb];
          local_12c = local_4c[0][7];
          local_128 = local_4c[0][0xf];
          local_124 = local_4c[0][3];
          local_120 = local_4c[0][0xb];
          local_11c = local_4c[0][3];
          local_118 = local_4c[0][7];
          iVar6 = FUN_008f69da(param_1,0x20500003,local_198,&local_b0,&local_144,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20500003,local_18c,local_a8 + 1,&local_138,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20500003,local_180,local_a8 + 4,&local_12c,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20500003,local_174,local_a8 + 7,&local_120,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x10100003,local_1f8,local_198,0,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x10100003,local_1ec,local_18c,0,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x10100003,local_1e0,local_180,0,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x10100003,local_1d4,local_174,0,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20400003,local_108 + 2,local_1c8,local_1f8,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20400003,local_f4,local_1bc,local_1ec,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20400003,&local_e8,local_1b0,local_1e0,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x20400003,&local_dc,local_1a4,local_1d4,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_b0 = local_4c[0][5];
          local_ac = local_4c[0][9];
          local_a8[0] = local_4c[0][0xd];
          local_a8[1] = local_4c[0][1];
          local_a8[2] = local_4c[0][9];
          local_a8[3] = local_4c[0][0xd];
          local_a8[4] = local_4c[0][1];
          local_a8[5] = local_4c[0][5];
          local_a8[6] = local_4c[0][0xd];
          local_a8[7] = local_4c[0][1];
          local_a8[8] = local_4c[0][5];
          local_a8[9] = local_4c[0][9];
          iVar6 = FUN_008f69da(param_1,0x50000003,&local_28,local_108 + 2,&local_b0,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x50000003,&ppppppuStack_24,local_f4,local_a8 + 1,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x50000003,&local_20,&local_e8,local_a8 + 4,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          iVar6 = FUN_008f69da(param_1,0x50000003,&puStack_1c,&local_dc,local_a8 + 7,0);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_b0 = *local_4c[0];
          local_ac = local_4c[0][4];
          local_a8[0] = local_4c[0][8];
          local_a8[1] = local_4c[0][0xc];
          uVar19 = ZEXT48(&local_b0);
          local_e8 = (uint *******)&local_28;
          pppppppuVar15 = (uint *******)0x50000004;
        }
        goto LAB_008fc010;
      }
      *param_2 = *local_4c[0];
    }
    break;
  case 0x11:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      ppppppuVar7 = (uint ******)FUN_008f4afb();
      if (ppppppuVar7 == (uint ******)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_4c[uVar13 - 3] = (uint *******)ppppppuVar7;
        uVar13 = uVar13 + 1;
        ppppppuVar7 = ppppppuVar7 + (int)ppppppuVar12;
      } while (uVar13 < 2);
      iVar6 = FUN_008f4c18(local_58,local_c0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_54,local_c0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_18,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_50,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_60 = (uint *******)((uint)local_c0 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_60 | 0x10100000,local_58,local_4c[1],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_60 | 0x20400000,local_54,local_4c[0],local_58,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      pppppppuVar5 = local_54;
      pppppppuVar15 = local_60;
LAB_008fd607:
      iVar6 = FUN_008f69da(param_1,(uint)pppppppuVar15 | 0x50000000,&local_18,pppppppuVar5,
                           CONCAT44(4,pppppppuVar5));
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10700001,&local_50,&local_18,0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = 0x400000000;
      local_e8 = (uint *******)&local_50;
      pppppppuVar15 = (uint *******)0x10300001;
      goto LAB_008fc010;
    }
    break;
  case 0x12:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)((uint)local_c0 & 0xfffff | 0x50000000);
      goto LAB_008fc009;
    }
    break;
  case 0x13:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_38 = *(uint ********)(in_ECX + 0x20);
      local_34[0] = local_4c[0][1];
      local_34[1] = local_4c[0][2];
      ppppppuStack_24 = local_4c[1][1];
      puStack_1c = (uint *)local_4c[1][3];
      local_2c = local_38;
      local_28 = local_38;
      local_20 = local_38;
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(&local_28);
      local_e8 = (uint *******)&local_38;
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x20500000);
      goto LAB_00900c41;
    }
    break;
  case 0x14:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      fVar4 = (float10)log2((float10)_DAT_00a0b350);
      local_54 = (uint *******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,
                              (double)((float10)_DAT_0099d0a0 /
                                      ((float10)0.6931471805599453 * fVar4)));
      pppppppuVar15 = local_8;
      pppppuVar11 = (uint *****)FUN_008f4afb();
      if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        (&local_cc)[uVar13] = (uint ******)pppppuVar11;
        uVar13 = uVar13 + 1;
        pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
      } while (uVar13 < 3);
      if (pppppppuVar15 != (uint *******)0x0) {
        ppppppuVar12 = local_cc;
        for (pppppppuVar15 = local_8; pppppppuVar15 != (uint *******)0x0;
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1)) {
          *ppppppuVar12 = (uint *****)local_54;
          ppppppuVar12 = ppppppuVar12 + 1;
        }
      }
      iVar6 = FUN_008f4c18(local_c8,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20500000,local_c8,local_4c[0],local_cc,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = 0x400000000;
      pppppppuVar15 = (uint *******)((uint)local_c | 0x10500000);
      local_e8 = local_c8;
      goto LAB_008fc00c;
    }
    break;
  case 0x15:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = 0x400000000;
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x10500000);
      local_e8 = local_4c[0];
      goto LAB_00900c41;
    }
    break;
  case 0x16:
    if (((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0)) ||
       (local_20 == (uint *******)0x0)) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(&local_18,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_50,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x50000000,&local_18,local_4c[1],local_4c[2],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20300001,&local_50,&local_18,in_ECX + 0x24,0x17);
      pppppppuVar15 = local_8;
      if (iVar6 < 0) goto LAB_00901a0e;
      pppppuVar11 = (uint *****)FUN_008f4afb();
      if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = (uint ******)pppppuVar11;
        uVar13 = uVar13 + 1;
        pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
      } while (uVar13 < 4);
      pppppppuVar15 = (uint *******)0x0;
      if (local_8 != (uint *******)0x0) {
        do {
          puStack_1c[(int)pppppppuVar15] = (uint)local_50;
          pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
        } while (pppppppuVar15 < local_8);
      }
      iVar6 = FUN_008f4c18(local_28,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_20,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,local_28,local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_68 = (uint *******)((uint)local_c | 0x20400000);
      iVar6 = FUN_008f69da(param_1,local_68,ppppppuStack_24,local_28,local_28,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20500000,local_20,ppppppuStack_24,puStack_1c,0)
      ;
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_20);
LAB_008fda11:
      local_e8 = local_4c[0];
LAB_008fda14:
      pppppppuVar15 = local_68;
      goto LAB_008fc010;
    }
    break;
  case 0x17:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_14 = (uint *******)FUN_008f4afb();
      if (local_14 == (uint *******)0x0) goto LAB_00901a0e;
      local_10 = local_14 + (int)local_8;
      uVar18 = FUN_008f4c18(local_14,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18((int)((ulonglong)uVar18 >> 0x20),local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10400000,local_14,local_4c[0],0,0x14);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar9 = 0x18;
      uVar13 = (uint)local_c | 0x10100000;
      goto LAB_008fc681;
    }
    break;
  case 0x18:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      ppppppuVar12 = (uint ******)FUN_008f4afb();
      if (ppppppuVar12 == (uint ******)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_4c[uVar13 + 5] = (uint *******)ppppppuVar12;
        uVar13 = uVar13 + 1;
        ppppppuVar12 = ppppppuVar12 + (int)pppppppuVar15;
      } while (uVar13 < 8);
      uVar13 = 0;
      do {
        uVar18 = FUN_008f4c18(local_4c[uVar13 + 5],local_8);
        if ((int)uVar18 < 0) goto LAB_00901a0e;
        uVar13 = (int)((ulonglong)uVar18 >> 0x20) + 1;
      } while (uVar13 < 8);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10300000,local_38,local_4c[1],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_64 = (uint *******)((uint)local_c | 0x20500000);
      iVar6 = FUN_008f69da(param_1,local_64,local_34[0],local_4c[0],local_38,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_14 = (uint *******)((uint)local_c | 0x10100000);
      iVar6 = FUN_008f69da(param_1,local_14,local_34[1],local_34[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20100000,local_2c,local_34[0],local_34[1],4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10400000,local_28,local_2c,0,0x14);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20300000,ppppppuStack_24,local_34[0],
                           local_34[1],0x17);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_14,local_20,local_28,0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f8aec(param_1,puStack_1c,local_20,local_28,ppppppuStack_24);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      local_e8 = (uint *******)puStack_1c;
      goto LAB_00900fb1;
    }
    break;
  case 0x19:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = 0;
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x10400000);
      local_e8 = local_4c[0];
      goto LAB_00900c41;
    }
    break;
  case 0x1a:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    local_10 = (uint *******)((int)local_8 << 2);
    local_4c[1] = operator_new((uint)local_10);
    if (local_4c[1] == (uint *******)0x0) goto LAB_00901a0e;
    pppppuVar11 = (uint *****)FUN_008f4afb();
    if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
    uVar13 = 0;
    do {
      local_a8[uVar13] = (uint ******)pppppuVar11;
      pppppuVar11 = (uint *****)((int)pppppuVar11 + (int)local_10);
      uVar13 = uVar13 + 1;
    } while (uVar13 < 10);
    iVar6 = FUN_008f4c18(local_a8[0],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[1],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[2],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[3],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[4],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[5],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[6],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[7],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_4c[1],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    local_c = (uint *******)((uint)local_8 & 0xfffff);
    local_14 = (uint *******)((uint)local_c | 0x10100000);
    iVar6 = FUN_008f69da(param_1,local_14,local_a8[0],local_4c[0],0,0);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20100000,local_a8[1],local_a8[0],local_4c[0],4);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,local_14,local_a8[2],local_a8[1],0,8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20300000,local_a8[3],local_a8[2],local_a8[1],0x17
                        );
    if (iVar6 < 0) goto LAB_00901a0e;
    local_68 = (uint *******)((uint)local_c | 0x20400000);
    iVar6 = FUN_008f69da(param_1,local_68,local_a8[4],local_a8[3],local_a8[1],4);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10600000,local_a8[5],local_a8[4],0,0);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,local_14,local_a8[6],local_a8[5],0,0);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10400000,local_a8[7],local_a8[6],0,0x14);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,local_68,local_4c[1],local_a8[5],local_a8[7],2);
    if (iVar6 < 0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(local_a8[8],local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_a8[9],local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10500000,local_a8[8],local_4c[1],0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10300000,local_a8[9],local_a8[8],0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_a8[9]);
      goto LAB_008fe041;
    }
    break;
  case 0x1b:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      pppppuVar11 = (uint *****)FUN_008f4afb();
      if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_34[uVar13 + 1] = (uint ******)pppppuVar11;
        uVar13 = uVar13 + 1;
        pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
      } while (uVar13 < 6);
      iVar6 = FUN_008f4c18(local_34[1],local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_2c,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_28,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_20,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(puStack_1c,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10d00000,local_34[1],local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_14 = (uint *******)((uint)local_c | 0x10100000);
      iVar6 = FUN_008f69da(param_1,local_14,local_2c,local_34[1],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_54 = (uint *******)((uint)local_c | 0x20100000);
      iVar6 = FUN_008f69da(param_1,local_54,local_28,local_2c,local_34[1],4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10e00000,ppppppuStack_24,local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_14,local_20,ppppppuStack_24,0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_54,puStack_1c,local_20,ppppppuStack_24,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(4,puStack_1c);
      local_e8 = local_28;
      goto LAB_008fc6a5;
    }
    break;
  case 0x1c:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      if ((*(byte *)(*(int *)(in_ECX + 8) + 0x6e) & 0x10) == 0) {
        pppppuVar11 = (uint *****)FUN_008f4afb();
        if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
        uVar13 = 0;
        do {
          local_34[uVar13 + 3] = (uint ******)pppppuVar11;
          uVar13 = uVar13 + 1;
          pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
        } while (uVar13 < 4);
        iVar6 = FUN_008f4c18(local_28,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(local_20,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(puStack_1c,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(param_2,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_c = (uint *******)((uint)local_8 & 0xfffff);
        local_14 = (uint *******)((uint)local_c | 0x10100000);
        iVar6 = FUN_008f69da(param_1,local_14,local_28,local_4c[0],0,0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20400000,ppppppuStack_24,local_4c[0],local_28
                             ,0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20500000,local_20,ppppppuStack_24,
                             ppppppuStack_24,0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,local_14,puStack_1c,local_20,0,0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20300000,param_2,puStack_1c,local_20,0x57);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_10 = (uint *******)0x0;
        if (local_8 != (uint *******)0x0) {
          iVar6 = (int)local_4c[0] - (int)param_2;
          param_1 = param_2;
          do {
            iVar8 = FUN_008f4f7c(*(undefined4 *)(iVar6 + (int)param_1),&local_28);
            if (iVar8 < 0) goto LAB_00901a0e;
            if (((double)CONCAT44(ppppppuStack_24,local_28) <= *(double *)(in_ECX + 0xa8)) ||
               (*(double *)(in_ECX + 0xa0) <= (double)CONCAT44(puStack_1c,local_20))) {
              if (((double)CONCAT44(ppppppuStack_24,local_28) == *(double *)(in_ECX + 0xa0)) ||
                 ((double)CONCAT44(puStack_1c,local_20) == *(double *)(in_ECX + 0xa8))) {
                ppppppuVar12 = *(uint *******)(in_ECX + 0x24);
                goto LAB_008fe423;
              }
            }
            else {
              ppppppuVar12 = *(uint *******)(in_ECX + 0x20);
LAB_008fe423:
              *param_1 = ppppppuVar12;
            }
            local_10 = (uint *******)((int)local_10 + 1);
            param_1 = param_1 + 1;
          } while (local_10 < local_8);
        }
      }
      else {
        pppppppuVar15 = (uint *******)0x0;
        if (local_8 != (uint *******)0x0) {
          do {
            param_2[(int)pppppppuVar15] = *(uint *******)(in_ECX + 0x20);
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
          } while (pppppppuVar15 < local_8);
        }
      }
    }
    break;
  case 0x1d:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      if ((*(byte *)(*(int *)(in_ECX + 8) + 0x6e) & 0x10) == 0) {
        pppppuVar11 = (uint *****)FUN_008f4afb();
        if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
        uVar13 = 0;
        do {
          local_34[uVar13 + 3] = (uint ******)pppppuVar11;
          uVar13 = uVar13 + 1;
          pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
        } while (uVar13 < 4);
        iVar6 = FUN_008f4c18(local_28,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(local_20,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(puStack_1c,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(param_2,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_c = (uint *******)((uint)local_8 & 0xfffff);
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10300000,local_28,local_4c[0],0,0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20500000,ppppppuStack_24,local_28,local_28,
                             0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,local_20,ppppppuStack_24,0,0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20300000,param_2,local_20,ppppppuStack_24,
                             0x57);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_10 = (uint *******)0x0;
        if (local_8 != (uint *******)0x0) {
          iVar6 = (int)local_4c[0] - (int)param_2;
          param_1 = param_2;
          do {
            iVar8 = FUN_008f4f7c(*(undefined4 *)((int)param_1 + iVar6),&local_28);
            if (iVar8 < 0) goto LAB_00901a0e;
            if (((double)CONCAT44(ppppppuStack_24,local_28) <= *(double *)(in_ECX + 0xa8)) ||
               (*(double *)(in_ECX + 0xa0) <= (double)CONCAT44(puStack_1c,local_20))) {
              if (((double)CONCAT44(ppppppuStack_24,local_28) == *(double *)(in_ECX + 0xa0)) ||
                 ((double)CONCAT44(puStack_1c,local_20) == *(double *)(in_ECX + 0xa8))) {
                ppppppuVar12 = *(uint *******)(in_ECX + 0x20);
                goto LAB_008fe63a;
              }
            }
            else {
              ppppppuVar12 = *(uint *******)(in_ECX + 0x24);
LAB_008fe63a:
              *param_1 = ppppppuVar12;
            }
            local_10 = (uint *******)((int)local_10 + 1);
            param_1 = param_1 + 1;
          } while (local_10 < local_8);
        }
      }
      else {
        pppppppuVar15 = (uint *******)0x0;
        if (local_8 != (uint *******)0x0) {
          do {
            param_2[(int)pppppppuVar15] = *(uint *******)(in_ECX + 0x24);
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
          } while (pppppppuVar15 < local_8);
        }
      }
    }
    break;
  case 0x1e:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      if ((*(byte *)(*(int *)(in_ECX + 8) + 0x6e) & 0x10) == 0) {
        pppppuVar11 = (uint *****)FUN_008f4afb();
        if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
        uVar13 = 0;
        do {
          local_34[uVar13 + 3] = (uint ******)pppppuVar11;
          uVar13 = uVar13 + 1;
          pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
        } while (uVar13 < 4);
        iVar6 = FUN_008f4c18(local_28,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(local_20,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(puStack_1c,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(param_2,local_8);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_c = (uint *******)((uint)local_8 & 0xfffff);
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20500000,local_28,local_4c[0],local_4c[0],
                             0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_14 = (uint *******)((uint)local_c | 0x10100000);
        iVar6 = FUN_008f69da(param_1,local_14,ppppppuStack_24,local_28,0,0x40);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_54 = (uint *******)((uint)local_c | 0x20300000);
        iVar6 = FUN_008f69da(param_1,local_54,local_20,local_28,ppppppuStack_24,0x57);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,local_14,puStack_1c,local_20,0,0x5a);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,local_54,param_2,puStack_1c,local_20,0x57);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_10 = (uint *******)0x0;
        if (local_8 != (uint *******)0x0) {
          iVar6 = (int)local_4c[0] - (int)param_2;
          param_1 = param_2;
          do {
            iVar8 = FUN_008f4f7c(*(undefined4 *)((int)param_1 + iVar6),&local_28);
            if (iVar8 < 0) goto LAB_00901a0e;
            if (((*(double *)(in_ECX + 0xa8) < (double)CONCAT44(ppppppuStack_24,local_28)) ||
                ((double)CONCAT44(puStack_1c,local_20) < *(double *)(in_ECX + 0xa0))) ||
               (((double)CONCAT44(ppppppuStack_24,local_28) == *(double *)(in_ECX + 0xa0) ||
                ((double)CONCAT44(puStack_1c,local_20) == *(double *)(in_ECX + 0xa8))))) {
              *param_1 = *(uint *******)(in_ECX + 0x24);
            }
            local_10 = (uint *******)((int)local_10 + 1);
            param_1 = param_1 + 1;
          } while (local_10 < local_8);
        }
      }
      else {
        pppppppuVar15 = (uint *******)0x0;
        if (local_8 != (uint *******)0x0) {
          do {
            param_2[(int)pppppppuVar15] = *(uint *******)(in_ECX + 0x24);
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
          } while (pppppppuVar15 < local_8);
        }
      }
    }
    break;
  case 0x1f:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_14 = (uint *******)FUN_008f4afb();
      if (local_14 == (uint *******)0x0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_14,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10500000,local_14,local_4c[1],0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_14);
LAB_008fe041:
      local_e8 = local_4c[0];
      goto LAB_00900d2e;
    }
    break;
  case 0x20:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(&local_18,1);
      if ((int)((ulonglong)uVar18 >> 0x20) != 1) {
        if ((int)uVar18 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(&local_50,1);
        if (iVar6 < 0) goto LAB_00901a0e;
        uVar18 = FUN_008f4c18(param_2,local_8);
        if ((int)uVar18 < 0) goto LAB_00901a0e;
        pppppppuVar5 = local_4c[0];
        pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff);
        goto LAB_008fd607;
      }
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10100001,&local_18,local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(4,&local_18);
      pppppppuVar15 = (uint *******)0x20100001;
      local_e8 = local_4c[0];
      goto LAB_008fc010;
    }
    break;
  case 0x21:
    if (((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0)) ||
       (local_20 == (uint *******)0x0)) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f8aec(param_1,param_2,local_4c[0],local_4c[1],local_4c[2]);
      goto LAB_008fc01a;
    }
    break;
  case 0x22:
    if ((((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
        || (local_20 == (uint *******)0x0)) || (local_8 != (uint *******)0x4)) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      if ((*(byte *)(*(int *)(in_ECX + 8) + 0x6c) & 0x40) == 0) {
        iVar6 = FUN_008f4afb();
        if (iVar6 == 0) goto LAB_00901a0e;
        uVar13 = 0;
        do {
          local_34[uVar13 + 1] = (uint ******)(iVar6 + uVar13 * 4);
          uVar13 = uVar13 + 1;
        } while (uVar13 < 6);
        iVar6 = FUN_008f4c18(iVar6,6);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(param_2,4);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x10100001,local_34[1],local_4c[0],0,0);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x20200001,local_2c,local_34[1],local_4c[0],0x17);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x20500001,param_2 + 1,local_2c,local_4c[0],0);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x10100001,local_28,local_4c[1],0,0);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x20200001,ppppppuStack_24,local_28,local_4c[1],0x17);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x20500001,local_20,local_2c,ppppppuStack_24,0x17);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f8e95(param_1,puStack_1c,local_4c[1],local_4c[2]);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x20500001,param_2 + 2,local_20,puStack_1c,4);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x10000001,param_2,in_ECX + 0x20,0,0x17);
        if (iVar6 < 0) goto LAB_00901a0e;
        uVar19 = 0x1700000000;
        param_2 = param_2 + 3;
        pppppppuVar15 = (uint *******)0x10000001;
        local_e8 = (uint *******)(in_ECX + 0x20);
      }
      else {
        local_28 = (uint *******)*local_4c[0];
        ppppppuStack_24 = *local_4c[1];
        local_20 = (uint *******)*local_4c[2];
        puStack_1c = (uint *)*local_4c[2];
        iVar6 = FUN_008f4c18(param_2,4);
        if (iVar6 < 0) goto LAB_00901a0e;
        uVar19 = 0;
        pppppppuVar15 = (uint *******)0x50100004;
        local_e8 = (uint *******)&local_28;
      }
      goto LAB_008fc010;
    }
    break;
  case 0x23:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      fVar4 = (float10)log2((float10)_DAT_00a0b350);
      local_54 = (uint *******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,
                              (double)((float10)0.6931471805599453 * fVar4));
      pppppppuVar15 = local_8;
      ppppppuVar12 = (uint ******)FUN_008f4afb();
      if (ppppppuVar12 == (uint ******)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_4c[uVar13 - 10] = (uint *******)ppppppuVar12;
        uVar13 = uVar13 + 1;
        ppppppuVar12 = ppppppuVar12 + (int)pppppppuVar15;
      } while (uVar13 < 2);
LAB_008fecd1:
      if (pppppppuVar15 != (uint *******)0x0) {
        pppppppuVar5 = local_74;
        for (pppppppuVar15 = local_8; pppppppuVar15 != (uint *******)0x0;
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1)) {
          *pppppppuVar5 = (uint ******)local_54;
          pppppppuVar5 = pppppppuVar5 + 1;
        }
      }
      iVar6 = FUN_008f4c18(local_70,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10600000,local_70,local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_70);
      local_e8 = local_74;
      goto LAB_00900d2e;
    }
    break;
  case 0x24:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      fVar4 = (float10)log2((float10)_DAT_00a0b350);
      fVar3 = (float10)log2((float10)_DAT_009fdca8);
      local_54 = (uint *******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,
                              (double)(((float10)0.6931471805599453 * fVar4) /
                                      ((float10)0.6931471805599453 * fVar3)));
      pppppppuVar15 = local_8;
      ppppppuVar12 = (uint ******)FUN_008f4afb();
      if (ppppppuVar12 == (uint ******)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_4c[uVar13 - 10] = (uint *******)ppppppuVar12;
        uVar13 = uVar13 + 1;
        ppppppuVar12 = ppppppuVar12 + (int)pppppppuVar15;
      } while (uVar13 < 2);
      goto LAB_008fecd1;
    }
    break;
  case 0x25:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = 0;
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x10600000);
      local_e8 = local_4c[0];
      goto LAB_00900c41;
    }
    break;
  case 0x26:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x20100000);
      local_e8 = local_4c[0];
      goto LAB_00900c41;
    }
    break;
  case 0x27:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x20000000);
      local_e8 = local_4c[0];
      goto LAB_00900c41;
    }
    break;
  case 0x28:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    local_10 = (uint *******)((int)local_8 << 2);
    local_4c[1] = operator_new((uint)local_10);
    if (local_4c[1] == (uint *******)0x0) goto LAB_00901a0e;
    pppppuVar11 = (uint *****)FUN_008f4afb();
    if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
    uVar13 = 0;
    do {
      local_a8[uVar13] = (uint ******)pppppuVar11;
      pppppuVar11 = (uint *****)((int)pppppuVar11 + (int)local_10);
      uVar13 = uVar13 + 1;
    } while (uVar13 < 10);
    iVar6 = FUN_008f4c18(local_a8[0],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[1],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[2],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[3],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[4],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[5],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[6],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[7],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_a8[8],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_4c[1],local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    local_c = (uint *******)((uint)local_8 & 0xfffff);
    iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10200000,local_a8[0],local_4c[0],0,0);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10400000,local_a8[1],local_a8[0],0,0x14);
    if (iVar6 < 0) goto LAB_00901a0e;
    local_14 = (uint *******)((uint)local_c | 0x10100000);
    iVar6 = FUN_008f69da(param_1,local_14,local_a8[2],local_a8[1],0,0x18);
    if (iVar6 < 0) goto LAB_00901a0e;
    local_68 = (uint *******)((uint)local_c | 0x20400000);
    iVar6 = FUN_008f69da(param_1,local_68,local_a8[3],local_a8[2],local_a8[0],2);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,local_14,local_a8[4],local_4c[0],0,0);
    if (iVar6 < 0) goto LAB_00901a0e;
    local_18 = (uint *******)((uint)local_c | 0x20200000);
    iVar6 = FUN_008f69da(param_1,local_18,local_a8[5],local_4c[0],local_a8[4],0x17);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,local_14,local_a8[6],local_a8[1],0,0);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,local_18,local_a8[7],local_a8[6],local_a8[1],0x17);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20500000,local_a8[8],local_a8[5],local_a8[7],0x17
                        );
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f69da(param_1,local_68,local_4c[1],local_a8[3],local_a8[8],2);
    if (iVar6 < 0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(local_a8[9],local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_14,local_a8[9],local_4c[1],0,2);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(0x10,local_a8[9]);
      goto LAB_008fda11;
    }
    break;
  case 0x29:
  case 0x2a:
  case 0x2b:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4afb();
      if (iVar6 == 0) goto LAB_00901a0e;
      pppppppuVar15 = (uint *******)0x0;
      if (local_8 != (uint *******)0x0) {
        do {
          *(uint *******)(iVar6 + (int)pppppppuVar15 * 4) = *local_4c[0];
          pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
        } while (pppppppuVar15 < local_8);
      }
      uVar18 = FUN_008f4c18(param_2,local_8);
      local_e8 = (uint *******)((ulonglong)uVar18 >> 0x20);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      pppppppuVar15 = local_4c[1];
      goto LAB_008ffb52;
    }
    break;
  case 0x2c:
  case 0x2f:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4afb();
      if (iVar6 == 0) goto LAB_00901a0e;
      pppppppuVar15 = (uint *******)0x0;
      if (local_8 != (uint *******)0x0) {
        do {
          *(uint *******)(iVar6 + (int)pppppppuVar15 * 4) = *local_4c[1];
          pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
        } while (pppppppuVar15 < local_8);
      }
      goto LAB_008ffb36;
    }
    break;
  case 0x2d:
  case 0x2e:
  case 0x30:
  case 0x31:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      pppppppuVar15 = (uint *******)local_28[4];
      local_10 = pppppppuVar15;
      if ((pppppppuVar15 == (uint *******)0x0) || (pppppppuVar15[1] != (uint ******)0x9))
      goto LAB_00901a0e;
      if (pppppppuVar15[4] == (uint ******)0x1) {
        uVar18 = CONCAT44(local_c0,local_4c[0]);
      }
      else {
        FUN_008f3b3d(2,pppppppuVar15[5],pppppppuVar15[6],pppppppuVar15[7],0x400);
        pppppppuVar15 = &local_138;
        uVar18 = CONCAT44(local_c0,local_4c[0]);
      }
      iVar6 = FUN_008f974c(pppppppuVar15,uVar18);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_64 = (uint *******)local_10[6];
      local_68 = (uint *******)local_10[7];
      local_14 = (uint *******)ppppppuStack_24[4];
      if ((local_14 == (uint *******)0x0) || (local_14[1] != (uint ******)0x9)) goto LAB_00901a0e;
      if (local_14[4] == (uint ******)0x1) {
        iVar6 = FUN_008f974c(local_14,local_4c[1],local_bc);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_60 = (uint *******)local_14[7];
        local_c = (uint *******)local_14[6];
      }
      else {
        FUN_008f3b3d(2,local_14[5],local_14[6],local_14[7],0x800);
        iVar6 = FUN_008f974c(local_a8 + 1,local_4c[1],local_bc);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_60 = (uint *******)local_14[6];
        local_c = (uint *******)local_14[7];
      }
      pppppppuVar15 = local_64;
      if ((local_68 != local_60) || (local_8 != (uint *******)((int)local_c * (int)local_64)))
      goto LAB_00901a0e;
      iVar6 = FUN_008f5c8b(local_4c[0],local_10[4],local_64,local_68);
      pppppppuVar5 = local_c;
      if (iVar6 == 0) {
        pppppuVar11 = (uint *****)FUN_008f4afb();
        if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
        uVar13 = 0;
        do {
          local_34[uVar13 + 2] = (uint ******)pppppuVar11;
          uVar13 = uVar13 + 1;
          pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
        } while (uVar13 < 5);
        local_10 = (uint *******)0x0;
        if (local_c != (uint *******)0x0) {
          local_14 = param_2;
          do {
            param_2 = (uint *******)0x0;
            if (local_60 != (uint *******)0x0) {
              do {
                if (local_64 != (uint *******)0x0) {
                  local_18 = local_64;
                  local_54 = local_4c[1] + (int)((int)param_2 * (int)local_c + (int)local_10);
                  local_70 = (uint ******)((int)local_68 * 4);
                  pppppppuVar15 = local_4c[0] + (int)param_2;
                  pppppppuVar5 = local_28;
                  do {
                    ppppppuVar12 = *pppppppuVar15;
                    pppppppuVar15 = pppppppuVar15 + (int)local_68;
                    *(uint *******)(((int)local_2c - (int)local_28) + (int)pppppppuVar5) =
                         ppppppuVar12;
                    *pppppppuVar5 = *local_54;
                    pppppppuVar5 = pppppppuVar5 + 1;
                    local_18 = (uint *******)((int)local_18 + -1);
                  } while (local_18 != (uint *******)0x0);
                }
                iVar6 = FUN_008f4c18(local_20,local_64);
                if (iVar6 < 0) goto LAB_00901a0e;
                local_54 = (uint *******)((uint)local_64 & 0xfffff);
                iVar6 = FUN_008f69da(param_1,(uint)local_54 | 0x20500000,local_20,local_2c,local_28,
                                     0);
                if (iVar6 < 0) goto LAB_00901a0e;
                if (param_2 == (uint *******)0x0) {
                  pppppppuVar15 = local_20;
                }
                else {
                  iVar6 = FUN_008f4c18(puStack_1c,local_64);
                  if (iVar6 < 0) goto LAB_00901a0e;
                  iVar6 = FUN_008f69da(param_1,(uint)local_54 | 0x20400000,puStack_1c,
                                       ppppppuStack_24,local_20,0);
                  if (iVar6 < 0) goto LAB_00901a0e;
                  pppppppuVar15 = (uint *******)puStack_1c;
                }
                pppppppuVar5 = (uint *******)ppppppuStack_24;
                for (uVar13 = (uint)local_64 & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
                  *pppppppuVar5 = *pppppppuVar15;
                  pppppppuVar15 = pppppppuVar15 + 1;
                  pppppppuVar5 = pppppppuVar5 + 1;
                }
                param_2 = (uint *******)((int)param_2 + 1);
                for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                  *(undefined1 *)pppppppuVar5 = *(undefined1 *)pppppppuVar15;
                  pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
                  pppppppuVar5 = (uint *******)((int)pppppppuVar5 + 1);
                }
              } while (param_2 < local_60);
            }
            pppppppuVar15 = (uint *******)0x0;
            if (local_64 != (uint *******)0x0) {
              pppppppuVar5 = local_14;
              do {
                *pppppppuVar5 = (uint ******)ppppppuStack_24[(int)pppppppuVar15];
                pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
                pppppppuVar5 = pppppppuVar5 + (int)local_c;
              } while (pppppppuVar15 < local_64);
            }
            local_10 = (uint *******)((int)local_10 + 1);
            local_14 = local_14 + 1;
          } while (local_10 < local_c);
        }
      }
      else {
        iVar6 = FUN_008f5e1f(local_4c[1],local_14[4],local_60,local_c);
        if (iVar6 == 0) {
          pppppuVar11 = (uint *****)FUN_008f4afb();
          if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
          uVar13 = 0;
          do {
            local_34[uVar13 + 2] = (uint ******)pppppuVar11;
            uVar13 = uVar13 + 1;
            pppppuVar11 = pppppuVar11 + (int)local_c;
          } while (uVar13 < 5);
          local_6c = (uint *******)0x0;
          if (local_64 != (uint *******)0x0) {
            local_18 = (uint *******)0x0;
            local_50 = param_2;
            do {
              param_2 = (uint *******)0x0;
              if (local_68 != (uint *******)0x0) {
                do {
                  if (local_c != (uint *******)0x0) {
                    local_54 = local_4c[0] + (int)local_18 + (int)param_2;
                    pppppppuVar15 = local_4c[1] + (int)local_c * (int)param_2;
                    local_10 = local_c;
                    pppppppuVar5 = local_28;
                    do {
                      *(uint *******)(((int)local_2c - (int)local_28) + (int)pppppppuVar5) =
                           *local_54;
                      *pppppppuVar5 = *pppppppuVar15;
                      pppppppuVar15 = pppppppuVar15 + 1;
                      pppppppuVar5 = pppppppuVar5 + 1;
                      local_10 = (uint *******)((int)local_10 + -1);
                    } while (local_10 != (uint *******)0x0);
                  }
                  iVar6 = FUN_008f4c18(local_20,local_c);
                  if (iVar6 < 0) goto LAB_00901a0e;
                  local_54 = (uint *******)((uint)local_c & 0xfffff);
                  iVar6 = FUN_008f69da(param_1,(uint)local_54 | 0x20500000,local_20,local_2c,
                                       local_28,0);
                  if (iVar6 < 0) goto LAB_00901a0e;
                  if (param_2 == (uint *******)0x0) {
                    pppppppuVar15 = local_20;
                  }
                  else {
                    iVar6 = FUN_008f4c18(puStack_1c,local_c);
                    if (iVar6 < 0) goto LAB_00901a0e;
                    iVar6 = FUN_008f69da(param_1,(uint)local_54 | 0x20400000,puStack_1c,
                                         ppppppuStack_24,local_20,0);
                    if (iVar6 < 0) goto LAB_00901a0e;
                    pppppppuVar15 = (uint *******)puStack_1c;
                  }
                  pppppppuVar5 = (uint *******)ppppppuStack_24;
                  for (uVar13 = (uint)local_c & 0x3fffffff; uVar13 != 0; uVar13 = uVar13 - 1) {
                    *pppppppuVar5 = *pppppppuVar15;
                    pppppppuVar15 = pppppppuVar15 + 1;
                    pppppppuVar5 = pppppppuVar5 + 1;
                  }
                  param_2 = (uint *******)((int)param_2 + 1);
                  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
                    *(undefined1 *)pppppppuVar5 = *(undefined1 *)pppppppuVar15;
                    pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
                    pppppppuVar5 = (uint *******)((int)pppppppuVar5 + 1);
                  }
                } while (param_2 < local_68);
              }
              pppppppuVar15 = (uint *******)0x0;
              if (local_c != (uint *******)0x0) {
                pppppppuVar5 = local_50;
                do {
                  *pppppppuVar5 = (uint ******)ppppppuStack_24[(int)pppppppuVar15];
                  pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
                  pppppppuVar5 = pppppppuVar5 + 1;
                } while (pppppppuVar15 < local_c);
              }
              local_18 = (uint *******)((int)local_18 + (int)local_68);
              local_6c = (uint *******)((int)local_6c + 1);
              local_50 = local_50 + (int)local_c;
            } while (local_6c < local_64);
          }
        }
        else {
          local_14 = (uint *******)FUN_008f4afb();
          if (local_14 == (uint *******)0x0) goto LAB_00901a0e;
          if (local_60 != (uint *******)0x0) {
            local_10 = local_4c[1];
            local_50 = local_60;
            local_6c = local_14;
            do {
              if (pppppppuVar5 != (uint *******)0x0) {
                pppppppuVar15 = local_10;
                pppppppuVar16 = local_6c;
                local_18 = pppppppuVar5;
                do {
                  *pppppppuVar16 = *pppppppuVar15;
                  pppppppuVar15 = pppppppuVar15 + 1;
                  pppppppuVar16 = pppppppuVar16 + (int)local_60;
                  local_18 = (uint *******)((int)local_18 + -1);
                } while (local_18 != (uint *******)0x0);
                local_18 = (uint *******)0x0;
                pppppppuVar5 = local_c;
              }
              local_6c = local_6c + 1;
              local_10 = local_10 + (int)pppppppuVar5;
              local_50 = (uint *******)((int)local_50 + -1);
            } while (local_50 != (uint *******)0x0);
          }
          iVar6 = FUN_008f4c18(param_2,local_8);
          if (iVar6 < 0) goto LAB_00901a0e;
          local_18 = (uint *******)0x0;
          if (local_64 != (uint *******)0x0) {
            local_50 = param_2;
            local_8 = local_4c[0];
            do {
              local_10 = (uint *******)0x0;
              if (local_c != (uint *******)0x0) {
                local_54 = (uint *******)((uint)local_68 & 0xfffff | 0x50000000);
                param_2 = local_50;
                local_6c = local_14;
                do {
                  iVar6 = FUN_008f69da(param_1,local_54,param_2,local_8,local_6c,0);
                  if (iVar6 < 0) goto LAB_00901a0e;
                  local_10 = (uint *******)((int)local_10 + 1);
                  param_2 = param_2 + 1;
                  local_6c = local_6c + (int)local_60;
                } while (local_10 < local_c);
              }
              local_18 = (uint *******)((int)local_18 + 1);
              local_8 = local_8 + (int)local_68;
              local_50 = local_50 + (int)local_c;
            } while (local_18 < local_64);
          }
        }
      }
    }
    break;
  case 0x32:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(param_2,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = 0x1000000000;
      pppppppuVar15 = (uint *******)((uint)local_c0 & 0xfffff | 0x50200000);
      goto LAB_008fc009;
    }
    break;
  case 0x33:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      if (local_8 != (uint *******)0x1) {
        iVar6 = FUN_008f4c18(&local_18,1);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4c18(&local_50,1);
        if (iVar6 < 0) goto LAB_00901a0e;
        local_c = (uint *******)((uint)local_8 & 0xfffff);
        iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x50000000,&local_18,local_4c[0],local_4c[0],4)
        ;
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f69da(param_1,0x10700001,&local_50,&local_18,0,4);
        if (iVar6 < 0) goto LAB_00901a0e;
        iVar6 = FUN_008f4afb();
        if (iVar6 == 0) goto LAB_00901a0e;
        pppppppuVar15 = (uint *******)0x0;
        if (local_8 != (uint *******)0x0) {
          do {
            *(uint ********)(iVar6 + (int)pppppppuVar15 * 4) = local_50;
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
          } while (pppppppuVar15 < local_8);
        }
        uVar17 = FUN_008f4c18(param_2,local_8);
        uVar19 = uVar17 >> 0x20;
        if ((int)uVar17 < 0) goto LAB_00901a0e;
        goto LAB_008fe041;
      }
      iVar6 = FUN_008f4afb();
      if (iVar6 == 0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = (uint ******)(iVar6 + uVar13 * 4);
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(local_28,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(ppppppuStack_24,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_20,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(puStack_1c,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10100001,local_28,local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20200001,ppppppuStack_24,local_28,local_4c[0],0x17);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20200001,local_20,local_4c[0],local_28,0x17);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10100001,puStack_1c,local_20,0,0x1a);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(0x12,puStack_1c);
      local_e8 = (uint *******)ppppppuStack_24;
LAB_008fccac:
      pppppppuVar15 = (uint *******)0x20400001;
      goto LAB_008fc010;
    }
    break;
  case 0x34:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f8e95(param_1,param_2,local_4c[0],local_4c[1]);
      goto LAB_008fc01a;
    }
    break;
  case 0x35:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = _DAT_00a20218;
      goto LAB_008ffafe;
    }
    break;
  case 0x36:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(&local_18,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_50,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_6c,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x50000000,&local_18,local_4c[0],local_4c[1],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20400001,&local_50,&local_18,&local_18,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10100001,&local_6c,&local_50,0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      ppppppuVar12 = (uint ******)FUN_008f4afb();
      if (ppppppuVar12 == (uint ******)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_4c[uVar13 - 3] = (uint *******)ppppppuVar12;
        uVar13 = uVar13 + 1;
        ppppppuVar12 = ppppppuVar12 + (int)local_8;
      } while (uVar13 < 2);
      pppppppuVar15 = (uint *******)0x0;
      if (local_8 != (uint *******)0x0) {
        do {
          local_58[(int)pppppppuVar15] = (uint *****)local_6c;
          pppppppuVar15 = (uint *******)((int)pppppppuVar15 + 1);
        } while (pppppppuVar15 < local_8);
      }
      iVar6 = FUN_008f4c18(local_54,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20500000,local_54,local_4c[1],
                           (int)((ulonglong)uVar18 >> 0x20),0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[0]);
      local_e8 = local_54;
      goto LAB_008fc6a5;
    }
    break;
  case 0x37:
    if (((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0)) ||
       (local_20 == (uint *******)0x0)) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(&local_10,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_60,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_110,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_68,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_14,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_114,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_10c,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_18,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_50,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_d0,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_6c,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_70,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_80,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_7c,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(&local_54,1);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x50000000,&local_10,local_4c[0],local_4c[1],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20500001,&local_60,&local_10,&local_10,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20500001,local_110,local_4c[2],local_4c[2],4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10100001,&local_68,&local_60,0,8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20400001,&local_14,in_ECX + 0x20,&local_68,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20500001,local_114,local_110,&local_14,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10100001,local_10c,local_114,0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20400001,&local_18,in_ECX + 0x20,local_10c,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20300001,&local_50,&local_18,in_ECX + 0x24,0x17);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20500001,&local_d0,&local_18,&local_50,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20500001,&local_6c,local_4c[2],&local_50,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20500001,&local_70,&local_6c,&local_10,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10700001,&local_80,&local_d0,0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x10300001,&local_7c,&local_80,0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,0x20400001,&local_54,&local_70,&local_7c,0);
      pppppppuVar15 = local_8;
      if (iVar6 < 0) goto LAB_00901a0e;
      pppppuVar11 = (uint *****)FUN_008f4afb();
      if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_34[uVar13 + 2] = (uint ******)pppppuVar11;
        uVar13 = uVar13 + 1;
        pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
      } while (uVar13 < 5);
      if (pppppppuVar15 != (uint *******)0x0) {
        pppppppuVar5 = (uint *******)puStack_1c;
        do {
          *(uint ********)(((int)local_20 - (int)puStack_1c) + (int)pppppppuVar5) = local_6c;
          *pppppppuVar5 = (uint ******)local_54;
          pppppppuVar5 = pppppppuVar5 + 1;
          pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1);
        } while (pppppppuVar15 != (uint *******)0x0);
      }
      iVar6 = FUN_008f4c18(local_2c,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_28,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_64 = (uint *******)((uint)local_c | 0x20500000);
      iVar6 = FUN_008f69da(param_1,local_64,local_2c,local_20,local_4c[0],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_64,local_28,puStack_1c,local_4c[1],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,ppppppuStack_24,local_28,0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(ppppppuStack_24);
      local_e8 = local_2c;
      goto LAB_008fc6a5;
    }
    break;
  case 0x38:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_54 = (uint *******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a011c0);
      pppppppuVar15 = local_8;
      pppppuVar11 = (uint *****)FUN_008f4afb();
      if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = (uint ******)pppppuVar11;
        uVar13 = uVar13 + 1;
        pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
      } while (uVar13 < 4);
      if (local_8 != (uint *******)0x0) {
        pppppppuVar5 = (uint *******)puStack_1c;
        for (pppppppuVar15 = local_8; pppppppuVar15 != (uint *******)0x0;
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1)) {
          *pppppppuVar5 = (uint ******)local_54;
          pppppppuVar5 = pppppppuVar5 + 1;
        }
      }
      iVar6 = FUN_008f4c18(local_28,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_20,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      local_68 = (uint *******)((uint)local_c | 0x20400000);
      iVar6 = FUN_008f69da(param_1,local_68,local_28,local_4c[0],puStack_1c,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10400000,ppppppuStack_24,local_28,0,0x14);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,local_20,ppppppuStack_24,0,0x18);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(2,local_20);
      local_e8 = local_28;
      goto LAB_008fda14;
    }
    break;
  case 0x39:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = 0x400000000;
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x10700000);
      local_e8 = local_4c[0];
      goto LAB_00900c41;
    }
    break;
  case 0x3a:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      ppppppuVar12 = (uint ******)FUN_008f4afb();
      if (ppppppuVar12 == (uint ******)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        (&local_5c)[uVar13] = (uint *******)ppppppuVar12;
        uVar13 = uVar13 + 1;
        ppppppuVar12 = ppppppuVar12 + (int)pppppppuVar15;
      } while (uVar13 < 3);
      if (pppppppuVar15 != (uint *******)0x0) {
        ppppppuVar12 = local_58;
        do {
          *(undefined4 *)(((int)local_5c - (int)local_58) + (int)ppppppuVar12) =
               *(undefined4 *)(in_ECX + 0x24);
          *ppppppuVar12 = *(uint ******)(in_ECX + 0x20);
          ppppppuVar12 = ppppppuVar12 + 1;
          pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1);
        } while (pppppppuVar15 != (uint *******)0x0);
      }
      iVar6 = FUN_008f4c18(local_54,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20100000,local_54,local_4c[0],local_5c,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(0x14,local_58);
      local_e8 = local_54;
      goto LAB_0090041e;
    }
    break;
  case 0x3b:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      pppppuVar11 = (uint *****)FUN_008f4afb();
      if (pppppuVar11 == (uint *****)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = (uint ******)pppppuVar11;
        uVar13 = uVar13 + 1;
        pppppuVar11 = pppppuVar11 + (int)pppppppuVar15;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(local_28,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_20,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(puStack_1c,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      local_14 = (uint *******)((uint)local_c | 0x10100000);
      iVar6 = FUN_008f69da(param_1,local_14,local_28,local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_18 = (uint *******)((uint)local_c | 0x20200000);
      iVar6 = FUN_008f69da(param_1,local_18,ppppppuStack_24,local_28,local_4c[0],0x17);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_18,local_20,local_4c[0],local_28,0x17);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_14,puStack_1c,local_20,0,0x1a);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(0x12,puStack_1c);
      local_e8 = (uint *******)ppppppuStack_24;
      goto LAB_008fc6a5;
    }
    break;
  case 0x3c:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      lVar20 = ZEXT48(local_8) << 0x20;
      goto LAB_0090062a;
    }
    break;
  case 0x3d:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    uVar13 = (int)local_c0 << 2;
    local_4c[1] = operator_new(uVar13);
    if (local_4c[1] == (uint *******)0x0) goto LAB_00901a0e;
    local_4c[2] = operator_new(uVar13);
    if (local_4c[2] == (uint *******)0x0) goto LAB_00901a0e;
    uVar18 = FUN_008f4c18(local_4c[1],local_c0);
    if ((int)uVar18 < 0) goto LAB_00901a0e;
    uVar18 = FUN_008f4c18((int)((ulonglong)uVar18 >> 0x20),local_c0);
    if ((int)uVar18 < 0) goto LAB_00901a0e;
    lVar20 = CONCAT44(local_c0,(int)((ulonglong)uVar18 >> 0x20));
    param_2 = local_4c[1];
LAB_0090062a:
    iVar6 = FUN_008f74a6(param_1,local_4c[0],param_2,lVar20);
    goto LAB_008fc01a;
  case 0x3e:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      fVar4 = (float10)log2((float10)_DAT_00a0b350);
      local_54 = (uint *******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,
                              (double)((float10)_DAT_0099d0a0 /
                                      ((float10)0.6931471805599453 * fVar4)));
      local_70 = (uint ******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a011c0);
      pppppppuVar15 = local_8;
      ppppppuVar12 = (uint ******)FUN_008f4afb();
      if (ppppppuVar12 == (uint ******)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_4c[uVar13 + 5] = (uint *******)ppppppuVar12;
        uVar13 = uVar13 + 1;
        ppppppuVar12 = ppppppuVar12 + (int)pppppppuVar15;
      } while (uVar13 < 8);
      if (pppppppuVar15 != (uint *******)0x0) {
        pppppppuVar5 = (uint *******)puStack_1c;
        do {
          *(uint ********)(((int)local_20 - (int)puStack_1c) + (int)pppppppuVar5) = local_54;
          *pppppppuVar5 = local_70;
          pppppppuVar5 = pppppppuVar5 + 1;
          pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1);
        } while (pppppppuVar15 != (uint *******)0x0);
      }
      iVar6 = FUN_008f4c18(local_38,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_34[0],local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_34[1],local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_2c,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_28,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(ppppppuStack_24,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      local_64 = (uint *******)((uint)local_c | 0x20500000);
      iVar6 = FUN_008f69da(param_1,local_64,local_38,local_4c[0],local_20,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_10 = (uint *******)((uint)local_c | 0x10500000);
      iVar6 = FUN_008f69da(param_1,local_10,local_34[0],local_38,0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_14 = (uint *******)((uint)local_c | 0x10100000);
      iVar6 = FUN_008f69da(param_1,local_14,local_34[1],local_38,0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_10,local_2c,local_34[1],0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_14,local_28,local_2c,0,8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20400000,ppppppuStack_24,local_34[0],local_28,0
                          );
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar9 = 0;
      goto LAB_008fc9a0;
    }
    break;
  case 0x3f:
    if (((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0)) ||
       (local_20 == (uint *******)0x0)) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_70 = (uint ******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a255f0);
      local_80 = FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a201e0);
      pppppppuVar15 = local_8;
      iVar6 = FUN_008f4afb();
      if (iVar6 == 0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_108[uVar13] = iVar6;
        uVar13 = uVar13 + 1;
        iVar6 = iVar6 + (int)pppppppuVar15 * 4;
      } while (uVar13 < 0xe);
      uVar13 = 0;
      do {
        uVar18 = FUN_008f4c18(local_108[uVar13],local_8);
        if ((int)uVar18 < 0) goto LAB_00901a0e;
        uVar13 = (int)((ulonglong)uVar18 >> 0x20) + 1;
      } while (uVar13 < 10);
      if (local_8 != (uint *******)0x0) {
        local_7c = local_d8 - (int)local_dc;
        local_d0 = local_d4 - (int)local_dc;
        local_54 = local_8;
        puVar10 = local_dc;
        do {
          *(undefined4 *)((local_e0 - (int)local_dc) + (int)puVar10) =
               *(undefined4 *)(in_ECX + 0x24);
          *puVar10 = *(undefined4 *)(in_ECX + 0x20);
          *(uint *******)(local_7c + (int)puVar10) = local_70;
          *(int *)(local_d0 + (int)puVar10) = local_80;
          puVar10 = puVar10 + 1;
          local_54 = (uint *******)((int)local_54 + -1);
        } while (local_54 != (uint *******)0x0);
      }
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10100000,local_108[0],local_4c[0],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_68 = (uint *******)((uint)local_c | 0x20400000);
      iVar6 = FUN_008f69da(param_1,local_68,local_108[1],local_4c[1],local_108[0],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_68,local_100[0],local_4c[2],local_108[0],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10300000,local_100[1],local_108[1],0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_64 = (uint *******)((uint)local_c | 0x20500000);
      iVar6 = FUN_008f69da(param_1,local_64,local_100[2],local_100[0],local_100[1],0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20100000,local_f4[0],local_100[2],local_e0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x20000000,local_f4[1],local_f4[0],local_dc,0x14)
      ;
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_64,local_f4[2],local_f4[1],local_d8,8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_68,local_e8,local_f4[2],local_d4,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_64,local_e4,local_f4[1],local_f4[1],0x14);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = (ulonglong)local_e4;
      goto LAB_00900fb1;
    }
    break;
  case 0x40:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_14 = (uint *******)FUN_008f4afb();
      if (local_14 == (uint *******)0x0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(local_14,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)local_8 & 0xfffff);
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10700000,local_14,local_4c[0],0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = 0x400000000;
      pppppppuVar15 = (uint *******)((uint)local_c | 0x10300000);
      local_e8 = local_14;
      goto LAB_008fc00c;
    }
    break;
  case 0x41:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar18 = FUN_008f4c18(param_2,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(0x17,local_4c[0]);
      pppppppuVar15 = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff | 0x20300000);
      local_e8 = local_4c[1];
      goto LAB_00900c41;
    }
    break;
  case 0x42:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    ppppppuVar12 = (uint ******)FUN_008f4afb();
    if (ppppppuVar12 == (uint ******)0x0) goto LAB_00901a0e;
    uVar13 = 0;
    do {
      (&local_5c)[uVar13] = (uint *******)ppppppuVar12;
      uVar13 = uVar13 + 1;
      ppppppuVar12 = ppppppuVar12 + (int)pppppppuVar15;
    } while (uVar13 < 3);
    iVar6 = FUN_008f4c18(local_5c,local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_58,local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(local_54,local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f4c18(param_2,local_8);
    if (iVar6 < 0) goto LAB_00901a0e;
    iVar6 = FUN_008f74a6(param_1,local_4c[0],local_5c,local_58);
    if (iVar6 < 0) goto LAB_00901a0e;
    local_c = (uint *******)((uint)local_8 & 0xfffff);
    iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10300000,local_54,local_58,0,0);
    if (iVar6 < 0) goto LAB_00901a0e;
    uVar19 = ZEXT48(local_54);
    local_e8 = local_5c;
LAB_00900d2e:
    pppppppuVar15 = local_c;
LAB_00900d31:
    pppppppuVar15 = (uint *******)((uint)pppppppuVar15 | 0x20500000);
LAB_008fc00c:
LAB_008fc010:
    iVar6 = FUN_008f69da(param_1,pppppppuVar15,param_2,local_e8,uVar19);
LAB_008fc01a:
    if (iVar6 < 0) goto LAB_00901a0e;
    break;
  case 0x43:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      fVar4 = (float10)log2((float10)_DAT_00a0b350);
      local_54 = (uint *******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,
                              (double)((float10)_DAT_0099d0a0 /
                                      ((float10)0.6931471805599453 * fVar4)));
      pppppppuVar15 = local_8;
      ppppppuVar12 = (uint ******)FUN_008f4afb();
      if (ppppppuVar12 == (uint ******)0x0) goto LAB_00901a0e;
      uVar13 = 0;
      do {
        local_4c[uVar13 + 4] = (uint *******)ppppppuVar12;
        uVar13 = uVar13 + 1;
        ppppppuVar12 = ppppppuVar12 + (int)pppppppuVar15;
      } while (uVar13 < 9);
      if (pppppppuVar15 != (uint *******)0x0) {
        pppppppuVar5 = (uint *******)puStack_1c;
        for (pppppppuVar15 = local_8; pppppppuVar15 != (uint *******)0x0;
            pppppppuVar15 = (uint *******)((int)pppppppuVar15 + -1)) {
          *pppppppuVar5 = (uint ******)local_54;
          pppppppuVar5 = pppppppuVar5 + 1;
        }
      }
      uVar18 = FUN_008f4c18(local_3c,local_8);
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(local_38,(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(local_34[0],(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(local_34[1],(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(local_2c,(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(local_28,(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(ppppppuStack_24,(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(local_20,(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      uVar18 = FUN_008f4c18(param_2,(int)((ulonglong)uVar18 >> 0x20));
      if ((int)uVar18 < 0) goto LAB_00901a0e;
      local_c = (uint *******)((uint)((ulonglong)uVar18 >> 0x20) & 0xfffff);
      local_64 = (uint *******)((uint)local_c | 0x20500000);
      iVar6 = FUN_008f69da(param_1,local_64,local_3c,local_4c[0],puStack_1c,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_10 = (uint *******)((uint)local_c | 0x10500000);
      iVar6 = FUN_008f69da(param_1,local_10,local_38,local_3c,0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_14 = (uint *******)((uint)local_c | 0x10100000);
      iVar6 = FUN_008f69da(param_1,local_14,local_34[0],local_3c,0,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_10,local_34[1],local_34[0],0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_14,local_2c,local_34[1],0,8);
      if (iVar6 < 0) goto LAB_00901a0e;
      local_68 = (uint *******)((uint)local_c | 0x20400000);
      iVar6 = FUN_008f69da(param_1,local_68,local_28,local_38,local_2c,0);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,local_68,ppppppuStack_24,local_38,local_34[1],4);
      if (iVar6 < 0) goto LAB_00901a0e;
      iVar6 = FUN_008f69da(param_1,(uint)local_c | 0x10300000,local_20,ppppppuStack_24,0,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_20);
      local_e8 = local_28;
      goto LAB_00900fb1;
    }
    break;
  case 0x44:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        (&local_20)[uVar13] = (uint *******)*local_4c[1];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 2);
      local_54 = (uint *******)*local_4c[1];
      FUN_008f974c(0,&local_54,1);
      iVar6 = *(int *)(in_ECX + 8);
      iVar8 = *(int *)(*(int *)(iVar6 + 0x14) + (int)local_20 * 4);
      if (((*(byte *)(*(int *)(*(int *)(iVar6 + 0x10) + *(int *)(iVar8 + 4) * 4) + 4) & 0x10) != 0)
         && (*(int *)(iVar8 + 0x10) == 0)) {
        local_10 = (uint *******)0x0;
        if (*(int *)(iVar6 + 8) != 0) {
          local_18 = *(uint ********)(iVar6 + 0x14);
          do {
            ppppppuVar12 = *local_18;
            if ((((*(uint ******)(iVar8 + 4) == ppppppuVar12[1]) &&
                 (*(uint ******)(iVar8 + 8) == ppppppuVar12[2])) &&
                (*(uint ******)(iVar8 + 0xc) == ppppppuVar12[3])) &&
               (ppppppuVar12[4] == (uint *****)0x1)) {
              puStack_1c = (uint *)local_10;
              break;
            }
            local_10 = (uint *******)((int)local_10 + 1);
            local_18 = local_18 + 1;
          } while (local_10 < *(uint ********)(*(int *)(in_ECX + 8) + 8));
        }
        if (local_10 == *(uint ********)(iVar6 + 8)) {
          FUN_008f63c5();
        }
      }
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(&local_20);
      pppppppuVar15 = (uint *******)0x60000002;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x45:
    if ((((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
        || (local_20 == (uint *******)0x0)) || ((uint *******)puStack_1c == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_4c[uVar13 + 5] = (uint *******)*local_4c[0];
        local_34[uVar13 + 1] = *local_4c[1];
        local_34[uVar13 + 3] = *local_4c[2];
        uVar14 = uVar13 + 1;
        (&local_20)[uVar13] = (uint *******)*local_4c[3];
        uVar13 = uVar14;
      } while (uVar14 < 2);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_34 + 1);
      pppppppuVar15 = (uint *******)0x60100002;
      local_e8 = (uint *******)&local_38;
      goto LAB_008fc010;
    }
    break;
  case 0x46:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60200004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x47:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60300004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x48:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60400004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x49:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_4c[uVar13 - 3] = (uint *******)*local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 2);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60500002;
      local_e8 = &local_58;
      goto LAB_008fc010;
    }
    break;
  case 0x4a:
    if ((((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
        || (local_20 == (uint *******)0x0)) || ((uint *******)puStack_1c == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_70 = (uint ******)((int)local_34 + (4 - (int)local_4c[1]));
      local_10 = (uint *******)((int)local_4c[2] - (int)local_4c[1]);
      local_7c = (int)local_34 + (0xc - (int)local_4c[1]);
      local_60 = (uint *******)((int)local_4c[3] - (int)local_4c[1]);
      local_80 = (int)&local_20 - (int)local_4c[1];
      local_54 = (uint *******)0x2;
      pppppppuVar15 = local_4c[1];
      do {
        *(uint *******)((int)local_4c + (0x14 - (int)local_4c[1]) + (int)pppppppuVar15) =
             *local_4c[0];
        *(uint *******)((int)local_70 + (int)pppppppuVar15) = *pppppppuVar15;
        *(undefined4 *)(local_7c + (int)pppppppuVar15) =
             *(undefined4 *)((int)local_10 + (int)pppppppuVar15);
        *(undefined4 *)(local_80 + (int)pppppppuVar15) =
             *(undefined4 *)((int)local_60 + (int)pppppppuVar15);
        pppppppuVar15 = pppppppuVar15 + 1;
        local_54 = (uint *******)((int)local_54 + -1);
      } while (local_54 != (uint *******)0x0);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_34 + 1);
      pppppppuVar15 = (uint *******)0x60600002;
      local_e8 = (uint *******)&local_38;
      goto LAB_008fc010;
    }
    break;
  case 0x4b:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60700004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x4c:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60800004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x4d:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60900004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x4e:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        (&ppppppuStack_24)[uVar13] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 3);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60a00003;
      local_e8 = &ppppppuStack_24;
      goto LAB_008fc010;
    }
    break;
  case 0x4f:
    if ((((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
        || (local_20 == (uint *******)0x0)) || ((uint *******)puStack_1c == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_70 = (uint ******)((int)local_108 + (0x14 - (int)local_4c[1]));
      local_10 = (uint *******)((int)local_4c[2] - (int)local_4c[1]);
      local_7c = (int)local_f4 + (0xc - (int)local_4c[1]);
      local_60 = (uint *******)((int)local_4c[3] - (int)local_4c[1]);
      iVar6 = 8 - (int)local_4c[1];
      local_80 = (int)local_a8 + (-0x34 - (int)local_4c[1]);
      local_54 = (uint *******)0x3;
      pppppppuVar15 = local_4c[1];
      do {
        ppppppuVar12 = local_70;
        *(uint *******)((int)local_108 + iVar6 + (int)pppppppuVar15) = *local_4c[0];
        *(uint *******)((int)ppppppuVar12 + (int)pppppppuVar15) = *pppppppuVar15;
        *(undefined4 *)(local_7c + (int)pppppppuVar15) =
             *(undefined4 *)((int)pppppppuVar15 + (int)local_10);
        *(undefined4 *)(local_80 + (int)pppppppuVar15) =
             *(undefined4 *)((int)pppppppuVar15 + (int)local_60);
        pppppppuVar15 = pppppppuVar15 + 1;
        local_54 = (uint *******)((int)local_54 + -1);
      } while (local_54 != (uint *******)0x0);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_f4);
      pppppppuVar15 = (uint *******)0x60b00003;
      local_e8 = (uint *******)(local_108 + 2);
      goto LAB_008fc010;
    }
    break;
  case 0x50:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60c00004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x51:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60d00004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x52:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60e00004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x53:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        (&ppppppuStack_24)[uVar13] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 3);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x60f00003;
      local_e8 = &ppppppuStack_24;
      goto LAB_008fc010;
    }
    break;
  case 0x54:
    if ((((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
        || (local_20 == (uint *******)0x0)) || ((uint *******)puStack_1c == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_70 = (uint ******)((int)local_108 + (0x14 - (int)local_4c[1]));
      local_10 = (uint *******)((int)local_4c[2] - (int)local_4c[1]);
      local_7c = (int)local_f4 + (0xc - (int)local_4c[1]);
      local_60 = (uint *******)((int)local_4c[3] - (int)local_4c[1]);
      iVar6 = 8 - (int)local_4c[1];
      local_80 = (int)local_a8 + (-0x34 - (int)local_4c[1]);
      local_54 = (uint *******)0x3;
      pppppppuVar15 = local_4c[1];
      do {
        ppppppuVar12 = local_70;
        *(uint *******)((int)local_108 + iVar6 + (int)pppppppuVar15) = *local_4c[0];
        *(uint *******)((int)ppppppuVar12 + (int)pppppppuVar15) = *pppppppuVar15;
        *(undefined4 *)(local_7c + (int)pppppppuVar15) =
             *(undefined4 *)((int)pppppppuVar15 + (int)local_10);
        *(undefined4 *)(local_80 + (int)pppppppuVar15) =
             *(undefined4 *)((int)pppppppuVar15 + (int)local_60);
        pppppppuVar15 = pppppppuVar15 + 1;
        local_54 = (uint *******)((int)local_54 + -1);
      } while (local_54 != (uint *******)0x0);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_f4);
      pppppppuVar15 = (uint *******)0x61000003;
      local_e8 = (uint *******)(local_108 + 2);
      goto LAB_008fc010;
    }
    break;
  case 0x55:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x61100004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x56:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x61200004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x57:
    if ((local_28 == (uint *******)0x0) || ((uint *******)ppppppuStack_24 == (uint *******)0x0))
    goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      uVar13 = 0;
      do {
        local_34[uVar13 + 3] = *local_4c[0];
        uVar13 = uVar13 + 1;
      } while (uVar13 < 4);
      iVar6 = FUN_008f4c18(param_2,local_8);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = ZEXT48(local_4c[1]);
      pppppppuVar15 = (uint *******)0x61300004;
      local_e8 = (uint *******)&local_28;
      goto LAB_008fc010;
    }
    break;
  case 0x58:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if ((param_2 != (uint *******)0x0) &&
       (local_60 = (uint *******)0x0, local_28[6] != (uint ******)0x0)) {
      pppppppuVar15 = (uint *******)local_28[5];
      do {
        local_10 = (uint *******)0x0;
        if (pppppppuVar15 != (uint *******)0x0) {
          do {
            iVar6 = (int)local_28[6] * (int)local_10;
            pppppppuVar15 =
                 (uint *******)(*(int *)((int)param_1 + 0x18) * (int)local_60 + (int)local_10);
            local_10 = (uint *******)((int)local_10 + 1);
            param_2[(int)pppppppuVar15] = local_4c[0][(int)(iVar6 + (int)local_60)];
            pppppppuVar15 = (uint *******)local_28[5];
          } while (local_10 < pppppppuVar15);
        }
        local_60 = (uint *******)((int)local_60 + 1);
      } while (local_60 < local_28[6]);
    }
    break;
  case 0x59:
    if (local_28 == (uint *******)0x0) goto LAB_00901a0e;
    if (param_2 != (uint *******)0x0) {
      local_28 = (uint *******)
                 FUN_00915318(*(undefined4 *)(*(int *)(in_ECX + 8) + 0x78),0,0,_DAT_00a201d8);
      local_c0 = local_4c[0][2];
      local_bc = (uint)local_4c[0][1];
      local_b8 = *local_4c[0];
      local_b4 = local_4c[0][3];
      ppppppuStack_24 = (uint ******)local_28;
      local_20 = local_28;
      puStack_1c = (uint *)local_28;
      iVar6 = FUN_008f4c18(param_2,4);
      if (iVar6 < 0) goto LAB_00901a0e;
      uVar19 = CONCAT44(6,&local_28);
      pppppppuVar15 = (uint *******)0x20500004;
      local_e8 = &local_c0;
      goto LAB_008fc010;
    }
    break;
  default:
    FUN_008f6353();
    goto LAB_00901a0e;
  }
  param_2 = *(uint ********)(local_168 + 0xc);
  if (param_2 != (uint *******)0x0) {
    param_1 = (uint *******)local_4c;
    do {
      if (*(int *)((int)param_2 + 8) != 0) {
        *(uint *******)(in_ECX + 0x1c) = *param_1;
        iVar6 = FUN_00903cbd(*(undefined4 *)((int)param_2 + 8),0,0);
        if (iVar6 < 0) break;
      }
      param_2 = *(uint ********)((int)param_2 + 0xc);
      param_1 = param_1 + 1;
    } while (param_2 != (uint *******)0x0);
  }
LAB_00901a0e:
  *(undefined4 *)(in_ECX + 0x1c) = local_160;
  *(undefined4 *)(in_ECX + 100) = local_164;
  _free(local_4c[0]);
  return extraout_EAX;
}


