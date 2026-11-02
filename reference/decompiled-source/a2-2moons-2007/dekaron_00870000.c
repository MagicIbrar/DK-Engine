// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x870000-0x87ffff

// ==== FUN_00870010 @ 0x00870010 ====

void FUN_00870010(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a440;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    if (0x3fffffff < param_1) {
      FUN_0085b3b0();
    }
    pvVar1 = operator_new(param_1 * 4);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
    local_8 = 0;
    uVar2 = FUN_0086f910(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008700a4 @ 0x008700a4 ====

void Catch_008700a4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008700c0 @ 0x008700c0 ====

void FUN_008700c0(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_0086fd30(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00870130 @ 0x00870130 ====

/* WARNING: Removing unreachable block (ram,0x0087024b) */
/* WARNING: Removing unreachable block (ram,0x0087043f) */

void FUN_00870130(int *param_1,int param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  bool bVar16;
  
  uVar5 = *(uint *)(in_ECX + 0x24);
  if (uVar5 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar5 < iVar4 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar5) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar4 * 2 + -3;
      FUN_008700c0(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar5 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar8 = *(undefined4 **)(uVar5 * 4 + *(int *)(in_ECX + 0x14));
    if (puVar8 != *(undefined4 **)(uVar5 * 4 + *(int *)(in_ECX + 0x14) + 4)) {
      do {
        uVar10 = puVar8[7];
        uVar9 = 0xdeadbeef;
        if (uVar10 != 0) {
          iVar4 = (uVar10 >> 4) + 1;
          uVar7 = 0;
          do {
            if ((uint)puVar8[8] < 0x10) {
              puVar12 = puVar8 + 3;
            }
            else {
              puVar12 = (undefined4 *)puVar8[3];
            }
            pcVar1 = (char *)((int)puVar12 + uVar7);
            uVar7 = uVar7 + iVar4;
            uVar9 = uVar9 + (int)*pcVar1;
          } while (uVar7 <= uVar10 - iVar4);
        }
        if ((uVar9 & *(uint *)(in_ECX + 0x20)) == uVar5) {
          puVar12 = (undefined4 *)*puVar8;
        }
        else {
          puVar12 = (undefined4 *)*puVar8;
          if (puVar12 != *(undefined4 **)(in_ECX + 8)) {
            iVar4 = uVar5 * 4;
            puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            uVar10 = uVar5;
            while ((puVar8 == puVar2 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4) = puVar12, uVar10 != 0))) {
              uVar10 = uVar10 - 1;
              iVar4 = uVar10 * 4;
              puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            }
            iVar4 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar8[1] = puVar12;
            *(int *)puVar12[1] = iVar4;
            **(undefined4 **)(iVar4 + 4) = puVar8;
            uVar3 = *(undefined4 *)(iVar4 + 4);
            *(undefined4 *)(iVar4 + 4) = puVar12[1];
            puVar12[1] = puVar8[1];
            puVar8[1] = uVar3;
            puVar8 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar10 = *(uint *)(in_ECX + 0x24);
              (uVar5 < uVar10 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar10 * 4) == *(int *)(in_ECX + 8)));
              uVar10 = uVar10 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar10 * 4) = puVar8;
          }
          if (puVar12 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar8 = puVar12;
      } while (puVar12 != *(undefined4 **)(uVar5 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar5 = *(uint *)(param_2 + 0x14);
  uVar10 = 0xdeadbeef;
  if (uVar5 != 0) {
    iVar4 = (uVar5 >> 4) + 1;
    uVar9 = 0;
    do {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        puVar8 = (undefined4 *)(param_2 + 4);
      }
      else {
        puVar8 = *(undefined4 **)(param_2 + 4);
      }
      pcVar1 = (char *)((int)puVar8 + uVar9);
      uVar9 = uVar9 + iVar4;
      uVar10 = uVar10 + (int)*pcVar1;
    } while (uVar9 <= uVar5 - iVar4);
  }
  uVar10 = *(uint *)(in_ECX + 0x20) & uVar10;
  if (*(uint *)(in_ECX + 0x24) <= uVar10) {
    uVar10 = uVar10 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar4 = uVar10 * 4;
  piVar11 = *(int **)(iVar4 + 4 + *(int *)(in_ECX + 0x14));
  if (piVar11 != *(int **)(iVar4 + *(int *)(in_ECX + 0x14))) {
    do {
      piVar11 = (int *)piVar11[1];
      if ((uint)piVar11[8] < 0x10) {
        pbVar14 = (byte *)(piVar11 + 3);
      }
      else {
        pbVar14 = (byte *)piVar11[3];
      }
      uVar9 = *(uint *)(param_2 + 0x14);
      if (uVar5 < *(uint *)(param_2 + 0x14)) {
        uVar9 = uVar5;
      }
      if (uVar9 == 0) {
LAB_00870394:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_008703a4;
        }
      }
      else {
        uVar7 = piVar11[7];
        if (uVar9 < (uint)piVar11[7]) {
          uVar7 = uVar9;
        }
        if (*(uint *)(param_2 + 0x18) < 0x10) {
          pbVar13 = (byte *)(param_2 + 4);
        }
        else {
          pbVar13 = *(byte **)(param_2 + 4);
        }
        bVar15 = false;
        iVar6 = 0;
        bVar16 = true;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar15 = *pbVar13 < *pbVar14;
          bVar16 = *pbVar13 == *pbVar14;
          pbVar13 = pbVar13 + 1;
          pbVar14 = pbVar14 + 1;
        } while (bVar16);
        if (!bVar16) {
          iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
        }
        bVar15 = iVar6 < 0;
        if (iVar6 == 0) goto LAB_00870394;
LAB_008703a4:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_0087046c;
          uVar7 = uVar5;
          if (uVar9 < uVar5) {
            uVar7 = uVar9;
          }
          if ((uint)piVar11[8] < 0x10) {
            pbVar13 = (byte *)(piVar11 + 3);
          }
          else {
            pbVar13 = (byte *)piVar11[3];
          }
          bVar15 = false;
          iVar6 = 0;
          bVar16 = true;
          goto code_r0x0087045f;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_008703b5;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x0087045f:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_0087046c:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_0087047d;
    }
  }
  else {
LAB_0087047d:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_008703b5:
  iVar6 = FUN_0086ff80(piVar11,piVar11[1],param_2);
  FUN_006b5060(1);
  piVar11[1] = iVar6;
  **(int **)(iVar6 + 4) = iVar6;
  iVar6 = piVar11[1];
  if (piVar11 == *(int **)(*(int *)(in_ECX + 0x14) + iVar4)) {
    do {
      *(int *)(*(int *)(in_ECX + 0x14) + iVar4) = iVar6;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      iVar4 = uVar10 * 4;
    } while (piVar11 == *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  *param_1 = iVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_008704a0 @ 0x008704a0 ====

int FUN_008704a0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  puVar1 = (undefined4 *)(param_2 + 8);
  puVar2 = (undefined4 *)(param_3 + 8);
  do {
    *(undefined4 *)(param_3 + -0x28) = *(undefined4 *)(param_2 + -0x28);
    param_2 = param_2 + -0x28;
    param_3 = param_3 + -0x28;
    puVar2[-0xb] = puVar1[-0xb];
    puVar2[-10] = puVar1[-10];
    puVar2[-9] = puVar1[-9];
    puVar2[-8] = puVar1[-8];
    puVar2[-7] = puVar1[-7];
    FUN_0043b3d0(puVar1 + -6);
    puVar1 = puVar1 + -10;
    puVar2 = puVar2 + -10;
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_00870520 @ 0x00870520 ====

void FUN_00870520(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    param_1[5] = param_2[5];
    FUN_00406600(param_2 + 6);
  }
  return;
}


// ==== FUN_00870570 @ 0x00870570 ====

void FUN_00870570(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = param_1 + 2;
    do {
      *param_1 = *param_3;
      puVar1[-1] = param_3[1];
      *puVar1 = param_3[2];
      puVar1[1] = param_3[3];
      puVar1[2] = param_3[4];
      puVar1[3] = param_3[5];
      FUN_0043b3d0(param_3 + 6);
      param_1 = param_1 + 10;
      puVar1 = puVar1 + 10;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_008705d0 @ 0x008705d0 ====

void FUN_008705d0(int param_1)

{
  if (*(int *)(param_1 + 0x1c) == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  FUN_00405de0(*(int *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),param_1 + 0x18,param_1);
  _free(*(void **)(param_1 + 0x1c));
  return;
}


// ==== FUN_00870620 @ 0x00870620 ====

int FUN_00870620(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a450;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x28) {
    FUN_00870520(param_3,param_1);
    param_3 = param_3 + 0x28;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0087068a @ 0x0087068a ====

void Catch_0087068a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x28) {
    FUN_008705d0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008706b0 @ 0x008706b0 ====

void FUN_008706b0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a460;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00870520(param_1,param_3);
    param_1 = param_1 + 0x28;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087071a @ 0x0087071a ====

void Catch_0087071a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x28) {
    FUN_008705d0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00870740 @ 0x00870740 ====

void FUN_00870740(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    piVar1 = (int *)(param_1 + 0x1c);
    iVar2 = param_1;
    do {
      if (*piVar1 != 0) {
        FUN_00405de0(*piVar1,piVar1[1],piVar1 + -1,param_1);
        _free((void *)*piVar1);
        return;
      }
      *piVar1 = 0;
      piVar1[1] = 0;
      piVar1[2] = 0;
      iVar2 = iVar2 + 0x28;
      piVar1 = piVar1 + 10;
    } while (iVar2 != param_2);
  }
  return;
}


// ==== FUN_00870790 @ 0x00870790 ====

void FUN_00870790(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00870620(param_1,param_2,param_3);
  return;
}


// ==== FUN_008707b0 @ 0x008707b0 ====

int FUN_008707b0(int param_1,int param_2,undefined4 param_3)

{
  FUN_008706b0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x28;
}


// ==== FUN_008707e0 @ 0x008707e0 ====

void FUN_008707e0(undefined4 param_1,undefined4 param_2)

{
  FUN_00870740(param_1,param_2);
  return;
}


// ==== FUN_00870800 @ 0x00870800 ====

void FUN_00870800(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_00870740(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00870840 @ 0x00870840 ====

void FUN_00870840(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_40;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  void *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a470;
  local_10 = ExceptionList;
  local_14 = local_54 + -0x24;
  local_6c = *param_3;
  local_68 = param_3[1];
  local_64 = param_3[2];
  local_60 = param_3[3];
  local_5c = param_3[4];
  local_58 = param_3[5];
  ExceptionList = &local_10;
  FUN_00406600(param_3 + 6);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x28;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (0x6666666U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x6666666 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_00436560();
        uVar4 = iVar2 + param_2;
      }
      local_24 = uVar4 * 0x28;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_18 = local_1c;
      local_18 = (void *)FUN_00870790(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_008707b0(local_18,param_2,&local_6c);
      FUN_00870790(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (iVar2 != 0) {
        FUN_00870740(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
      *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar1) * 0x28);
      *(void **)(in_ECX + 4) = local_1c;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x28) < param_2) {
        local_28 = param_2 * 0x28;
        FUN_00870620(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_008707b0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x28,
                     &local_6c);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_00870570(param_1,*(int *)(in_ECX + 8) - local_28,&local_6c);
      }
      else {
        local_30 = local_2c + param_2 * -0x28;
        uVar3 = FUN_00870620(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_008704a0(param_1,local_30,local_2c,local_40);
        FUN_00870570(param_1,param_2 * 0x28 + param_1,&local_6c);
      }
    }
  }
  if (local_50 == (void *)0x0) {
    ExceptionList = local_10;
    return;
  }
  FUN_00405de0(local_50,local_4c,local_54,local_44);
  _free(local_50);
  return;
}


// ==== Catch@00870a19 @ 0x00870a19 ====

void Catch_00870a19(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_008707e0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@00870acf @ 0x00870acf ====

void Catch_00870acf(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x28;
  FUN_008707e0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00870b70 @ 0x00870b70 ====

void FUN_00870b70(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x28 != 0) {
      iVar1 = (param_2 - iVar1) / 0x28;
      goto LAB_00870bb5;
    }
  }
  iVar1 = 0;
LAB_00870bb5:
  FUN_00870840(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x28;
  return;
}


// ==== FUN_00870be0 @ 0x00870be0 ====

void FUN_00870be0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a480;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x28;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_004df0d0(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_00870790(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00870c77 @ 0x00870c77 ====

void Catch_00870c77(void)

{
  FUN_00870800();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00870c90 @ 0x00870c90 ====

void FUN_00870c90(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x28) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x28))) {
    FUN_00870b70(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_008706b0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x28;
  return;
}


// ==== FUN_00870d20 @ 0x00870d20 ====

void FUN_00870d20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  FUN_00870be0(param_4 + 1);
  *(undefined1 *)(in_ECX + 8) = param_5;
  *(undefined1 *)((int)in_ECX + 0x21) = 0;
  return;
}


// ==== FUN_00870d60 @ 0x00870d60 ====

void * FUN_00870d60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a490;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x24);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00870d20(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00870dd5 @ 0x00870dd5 ====

void Catch_00870dd5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00870df0 @ 0x00870df0 ====

void FUN_00870df0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0xcccccca < *(uint *)(in_ECX + 8)) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c48c);
  }
  piVar4 = (int *)FUN_00870d60(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
                               param_4,0);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  if (param_3 == *(undefined4 **)(in_ECX + 4)) {
    (*(undefined4 **)(in_ECX + 4))[1] = piVar4;
    **(undefined4 **)(in_ECX + 4) = piVar4;
    *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
  }
  else if (param_2 == '\0') {
    param_3[2] = piVar4;
    if (param_3 == *(undefined4 **)(*(int *)(in_ECX + 4) + 8)) {
      *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
    }
  }
  else {
    *param_3 = piVar4;
    if (param_3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      **(int **)(in_ECX + 4) = (int)piVar4;
    }
  }
  cVar1 = *(char *)(piVar4[1] + 0x20);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x20) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[8] == '\0') {
LAB_00870ef5:
        *(undefined1 *)(*piVar5 + 0x20) = 1;
        *(undefined1 *)(piVar6 + 8) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x20) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004bdf70(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x20) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x20) = 0;
        FUN_004bdfc0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[8] == '\0') goto LAB_00870ef5;
      if (piVar7 == (int *)*piVar2) {
        FUN_004bdfc0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x20) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x20) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x21) == '\0') {
        *(int *)(*piVar2 + 4) = iVar3;
      }
      piVar2[1] = *(int *)(iVar3 + 4);
      if (iVar3 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
        *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
      }
      else {
        piVar6 = *(int **)(iVar3 + 4);
        if (iVar3 == *piVar6) {
          *piVar6 = (int)piVar2;
        }
        else {
          piVar6[2] = (int)piVar2;
        }
      }
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
    }
    cVar1 = *(char *)(piVar7[1] + 0x20);
  } while( true );
}


// ==== FUN_00870fd0 @ 0x00870fd0 ====

void FUN_00870fd0(undefined4 *param_1,float *param_2)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  bool bVar4;
  bool bVar5;
  undefined4 *puVar6;
  float *pfVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int in_ECX;
  bool bVar10;
  
  pfVar7 = param_2;
  puVar9 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar4 = true;
  bVar10 = true;
  cVar2 = *(char *)((int)puVar9 + 0x21);
  puVar6 = *(undefined4 **)(in_ECX + 4);
  while (cVar2 == '\0') {
    fVar1 = (float)puVar9[3];
    bVar4 = fVar1 == *param_2;
    bVar5 = fVar1 < *param_2;
    if (bVar5 || bVar4) {
      puVar8 = (undefined4 *)puVar9[2];
    }
    else {
      puVar8 = (undefined4 *)*puVar9;
    }
    bVar10 = !bVar5 && !bVar4;
    bVar4 = (!NAN(fVar1) && !NAN(*param_2)) && (!bVar5 && !bVar4);
    puVar6 = puVar9;
    puVar9 = puVar8;
    cVar2 = *(char *)((int)puVar8 + 0x21);
  }
  param_2 = (float *)puVar6;
  if (bVar4) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      bVar10 = true;
      goto LAB_00871050;
    }
    FUN_004ddea0();
  }
  fVar1 = *pfVar7;
  if (fVar1 < param_2[3] || fVar1 == param_2[3]) {
    *(undefined1 *)(param_1 + 1) = 0;
    *param_1 = param_2;
    return;
  }
LAB_00871050:
  puVar9 = (undefined4 *)FUN_00870df0(&param_2,bVar10,puVar6,pfVar7);
  uVar3 = *puVar9;
  *(undefined1 *)(param_1 + 1) = 1;
  *param_1 = uVar3;
  return;
}


// ==== FUN_00871080 @ 0x00871080 ====

/* WARNING: Removing unreachable block (ram,0x00871199) */
/* WARNING: Removing unreachable block (ram,0x008711aa) */
/* WARNING: Removing unreachable block (ram,0x008711b3) */
/* WARNING: Removing unreachable block (ram,0x008711b6) */
/* WARNING: Removing unreachable block (ram,0x008711a6) */
/* WARNING: Removing unreachable block (ram,0x008711c4) */
/* WARNING: Removing unreachable block (ram,0x008711d1) */
/* WARNING: Removing unreachable block (ram,0x008711dc) */
/* WARNING: Removing unreachable block (ram,0x008711d8) */
/* WARNING: Removing unreachable block (ram,0x008711cc) */
/* WARNING: Removing unreachable block (ram,0x008711df) */

void FUN_00871080(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x21) != '\0') {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c7c8);
  }
  FUN_004dde50();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x21) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      piVar3 = (int *)FUN_004128f0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x21) == '\0') {
      uVar4 = FUN_0057dff0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[8] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdf70(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(*piVar5 + 0x20) == '\x01') && (*(char *)(piVar5[2] + 0x20) == '\x01'))
            goto LAB_008712b4;
            if (*(char *)(piVar5[2] + 0x20) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x20) = 1;
              *(undefined1 *)(piVar5 + 8) = 0;
              FUN_004bdfc0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 8) = (char)piVar3[8];
            *(undefined1 *)(piVar3 + 8) = 1;
            *(undefined1 *)(piVar5[2] + 0x20) = 1;
            FUN_004bdf70(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdfc0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(piVar5[2] + 0x20) != '\x01') || (*(char *)(*piVar5 + 0x20) != '\x01')) {
              if (*(char *)(*piVar5 + 0x20) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x20) = 1;
                *(undefined1 *)(piVar5 + 8) = 0;
                FUN_004bdf70(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 8) = (char)piVar3[8];
              *(undefined1 *)(piVar3 + 8) = 1;
              *(undefined1 *)(*piVar5 + 0x20) = 1;
              FUN_004bdfc0(piVar3);
              break;
            }
LAB_008712b4:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
  if (param_2[5] == 0) {
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    _free(param_2);
    return;
  }
  FUN_00870740(param_2[5],param_2[6],param_2 + 4,param_2);
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_00871360 @ 0x00871360 ====

undefined4 * FUN_00871360(undefined4 *param_1,int *param_2,float *param_3)

{
  float *pfVar1;
  int *piVar2;
  char cVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00870df0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar2 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar2) {
    if (*param_3 <= (float)param_2[3] && (float)param_2[3] != *param_3) {
      FUN_00870df0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar2) {
    pfVar1 = (float *)(piVar2[2] + 0xc);
    if (*pfVar1 <= *param_3 && *param_3 != *pfVar1) {
      FUN_00870df0(param_1,0,piVar2[2],param_3);
      return param_1;
    }
  }
  else {
    if (*param_3 <= (float)param_2[3] && (float)param_2[3] != *param_3) {
      FUN_004ddea0();
      cVar3 = FUN_00519c20(param_2 + 3,param_3);
      if (cVar3 != '\0') {
        if (*(char *)(param_2[2] + 0x21) == '\0') {
          FUN_00870df0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00870df0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
    if ((float)param_2[3] <= *param_3 && *param_3 != (float)param_2[3]) {
      FUN_004dde50();
      if (param_2 != *(int **)(in_ECX + 4)) {
        cVar3 = FUN_00519c20(param_3,param_2 + 3);
        if (cVar3 == '\0') goto LAB_008714c9;
      }
      if (*(char *)(param_2[2] + 0x21) == '\0') {
        FUN_00870df0(param_1,1,param_2,param_3);
        return param_1;
      }
      FUN_00870df0(param_1,0,param_2,param_3);
      return param_1;
    }
  }
LAB_008714c9:
  puVar4 = (undefined4 *)FUN_00870fd0(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_008714f0 @ 0x008714f0 ====

void FUN_008714f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) != '\0') {
    return;
  }
  FUN_008714f0(*(undefined4 *)((int)param_1 + 8));
  if (*(int *)((int)param_1 + 0x14) == 0) {
    *(undefined4 *)((int)param_1 + 0x14) = 0;
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    _free(param_1);
    return;
  }
  FUN_00870740(*(int *)((int)param_1 + 0x14),*(undefined4 *)((int)param_1 + 0x18),
               (int)param_1 + 0x10,param_1);
  _free(*(void **)((int)param_1 + 0x14));
  return;
}


// ==== FUN_00871560 @ 0x00871560 ====

undefined4 * FUN_00871560(float *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined4 *puVar5;
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined4 local_8;
  
  puVar5 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x21);
  puVar2 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    if (*param_1 < (float)puVar5[3] || *param_1 == (float)puVar5[3]) {
      puVar3 = (undefined4 *)*puVar5;
    }
    else {
      puVar3 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    puVar2 = puVar5;
    puVar5 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x21);
  }
  if ((puVar2 != *(undefined4 **)(in_ECX + 4)) &&
     ((float)puVar2[3] < *param_1 || (float)puVar2[3] == *param_1)) {
    return puVar2 + 4;
  }
  local_14 = *param_1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  FUN_00870be0(local_24);
  piVar4 = (int *)FUN_00871360(&param_1,puVar2,&local_14);
  if (local_c == (void *)0x0) {
    return (undefined4 *)(*piVar4 + 0x10);
  }
  FUN_00870740(local_c,local_8,local_10,param_1);
  _free(local_c);
  return extraout_EAX;
}


// ==== FUN_00871630 @ 0x00871630 ====

void FUN_00871630(undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  
  piVar4 = param_3;
  piVar6 = *(int **)(in_ECX + 4);
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar6) && (param_3 == piVar6)) {
    FUN_008714f0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x21) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x21) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x21);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x21);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x21);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x21);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00871080(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_008716f0 @ 0x008716f0 ====

void FUN_008716f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0086f410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00871710 @ 0x00871710 ====

void FUN_00871710(void)

{
  return;
}


// ==== FUN_00871720 @ 0x00871720 ====

void FUN_00871720(void)

{
  return;
}


// ==== FUN_00871730 @ 0x00871730 ====

void FUN_00871730(float *param_1,int *param_2,float *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  float local_8;
  float local_4;
  
  iVar1 = *param_4;
  iVar2 = *param_2;
  local_8 = 0.0;
  local_4 = 0.0;
  if ((iVar2 <= iVar1) && (iVar1 < param_2[2])) {
    local_8 = ((param_3[2] - *param_3) * (float)(iVar1 - iVar2)) / (float)(param_2[2] - iVar2) +
              *param_3;
  }
  iVar2 = param_2[2];
  if ((iVar2 <= iVar1) && (iVar1 < param_2[4])) {
    local_8 = ((param_3[4] - param_3[2]) * (float)(iVar1 - iVar2)) / (float)(param_2[4] - iVar2) +
              param_3[2];
  }
  iVar2 = param_2[4];
  if ((iVar2 <= iVar1) && (iVar1 < param_2[6])) {
    local_8 = ((param_3[6] - param_3[4]) * (float)(iVar1 - iVar2)) / (float)(param_2[6] - iVar2) +
              param_3[4];
  }
  if (iVar1 == param_2[6]) {
    local_8 = param_3[6];
  }
  iVar1 = param_2[1];
  iVar2 = param_4[1];
  if ((iVar1 <= iVar2) && (iVar2 < param_2[3])) {
    local_4 = ((param_3[3] - param_3[1]) * (float)(iVar2 - iVar1)) / (float)(param_2[3] - iVar1) +
              param_3[1];
  }
  iVar1 = param_2[3];
  if ((iVar1 <= iVar2) && (iVar2 < param_2[5])) {
    local_4 = ((param_3[5] - param_3[3]) * (float)(iVar2 - iVar1)) / (float)(param_2[5] - iVar1) +
              param_3[3];
  }
  iVar1 = param_2[5];
  if ((iVar1 <= iVar2) && (iVar2 < param_2[7])) {
    local_4 = ((param_3[7] - param_3[5]) * (float)(iVar2 - iVar1)) / (float)(param_2[7] - iVar1) +
              param_3[5];
  }
  if (iVar2 == param_2[7]) {
    local_4 = param_3[7];
  }
  *param_1 = local_8;
  param_1[1] = local_4;
  return;
}


// ==== FUN_00871900 @ 0x00871900 ====

void FUN_00871900(float *param_1,int *param_2,float *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  float local_8;
  float local_4;
  
  iVar1 = *param_4;
  iVar2 = *param_2;
  local_8 = 0.0;
  local_4 = 0.0;
  if ((iVar2 <= iVar1) && (iVar1 < param_2[2])) {
    local_8 = ((param_3[2] - *param_3) * (float)(iVar1 - iVar2)) / (float)(param_2[2] - iVar2) +
              *param_3;
  }
  if (iVar1 == param_2[2]) {
    local_8 = param_3[2];
  }
  iVar1 = param_4[1];
  iVar2 = param_2[1];
  if ((iVar2 <= iVar1) && (iVar1 < param_2[3])) {
    local_4 = ((param_3[3] - param_3[1]) * (float)(iVar1 - iVar2)) / (float)(param_2[3] - iVar2) +
              param_3[1];
  }
  if (iVar1 == param_2[3]) {
    local_4 = param_3[3];
  }
  *param_1 = local_8;
  param_1[1] = local_4;
  return;
}


// ==== FUN_00871a80 @ 0x00871a80 ====

void FUN_00871a80(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = FUN_0084be00(param_1);
  if (cVar1 == '\0') {
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar2 + 0x114) == 2) && (*(int *)(iVar2 + 0x118) == 5)) &&
       (*(int *)(iVar2 + 0x11c) == 6)) {
      return;
    }
    if (*(int *)(iVar2 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x14,6);
    *(undefined4 *)(iVar2 + 0x11c) = 6;
  }
  else {
    iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar2 + 0x114) == 2) && (*(int *)(iVar2 + 0x118) == 5)) &&
       (*(int *)(iVar2 + 0x11c) == 2)) {
      return;
    }
    if (*(int *)(iVar2 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x14,2);
    *(undefined4 *)(iVar2 + 0x11c) = 2;
  }
  *(undefined4 *)(iVar2 + 0x114) = 2;
  *(undefined4 *)(iVar2 + 0x118) = 5;
  return;
}


// ==== FUN_00871c10 @ 0x00871c10 ====

undefined4 FUN_00871c10(uint param_1,int param_2,char param_3)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 *unaff_retaddr;
  undefined4 local_248;
  int *local_244;
  undefined4 local_230 [140];
  
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  local_244 = piVar1;
  if (param_3 == '\0') {
    iVar7 = param_1 * 0x1c;
    cVar3 = FUN_00881000(0x1c,iVar7);
    if (cVar3 == '\0') {
      (**(code **)(*piVar1 + 0xc))();
    }
    uVar5 = (**(code **)(*piVar1 + 0x1c))(0x1c,iVar7);
  }
  else {
    uVar8 = 0;
    if (3 < (int)param_1) {
      puVar6 = (undefined4 *)(param_2 + 0x14);
      iVar7 = (param_1 - 4 >> 2) + 1;
      puVar4 = local_230;
      uVar8 = iVar7 * 4;
      do {
        uVar5 = *puVar6;
        puVar4[-4] = puVar6[-5];
        puVar4[-3] = puVar6[-4];
        uVar2 = puVar6[-2];
        puVar4[-2] = puVar6[-3];
        puVar4[-1] = uVar2;
        *puVar4 = puVar6[-1];
        uVar2 = puVar6[1];
        puVar4[1] = uVar5;
        puVar4[3] = uVar5;
        uVar5 = puVar6[7];
        puVar4[2] = uVar2;
        puVar4[4] = uVar2;
        puVar4[5] = puVar6[2];
        puVar4[6] = puVar6[3];
        uVar2 = puVar6[5];
        puVar4[7] = puVar6[4];
        puVar4[8] = uVar2;
        puVar4[9] = puVar6[6];
        uVar2 = puVar6[8];
        puVar4[10] = uVar5;
        puVar4[0xc] = uVar5;
        uVar5 = puVar6[0xe];
        puVar4[0xb] = uVar2;
        puVar4[0xd] = uVar2;
        puVar4[0xe] = puVar6[9];
        puVar4[0xf] = puVar6[10];
        uVar2 = puVar6[0xc];
        puVar4[0x10] = puVar6[0xb];
        puVar4[0x11] = uVar2;
        puVar4[0x12] = puVar6[0xd];
        uVar2 = puVar6[0xf];
        puVar4[0x13] = uVar5;
        puVar4[0x15] = uVar5;
        uVar5 = puVar6[0x15];
        puVar4[0x14] = uVar2;
        puVar4[0x16] = uVar2;
        puVar4[0x17] = puVar6[0x10];
        puVar4[0x18] = puVar6[0x11];
        uVar2 = puVar6[0x13];
        puVar4[0x19] = puVar6[0x12];
        puVar4[0x1a] = uVar2;
        local_248 = puVar6[0x16];
        puVar4[0x1b] = puVar6[0x14];
        puVar4[0x1c] = uVar5;
        puVar4[0x1d] = local_248;
        puVar4[0x1e] = uVar5;
        puVar4[0x1f] = local_248;
        puVar6 = puVar6 + 0x1c;
        puVar4 = puVar4 + 0x24;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    if (uVar8 < param_1) {
      puVar4 = local_230 + uVar8 * 9;
      puVar6 = (undefined4 *)(param_2 + 0x14 + uVar8 * 0x1c);
      iVar7 = param_1 - uVar8;
      do {
        uVar5 = *puVar6;
        puVar4[-4] = puVar6[-5];
        puVar4[-3] = puVar6[-4];
        uVar2 = puVar6[-2];
        puVar4[-2] = puVar6[-3];
        puVar4[-1] = uVar2;
        local_248 = puVar6[1];
        *puVar4 = puVar6[-1];
        puVar4[1] = uVar5;
        puVar4[2] = local_248;
        puVar4[3] = uVar5;
        puVar4[4] = local_248;
        puVar6 = puVar6 + 7;
        puVar4 = puVar4 + 9;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    iVar7 = param_1 * 0x24;
    cVar3 = FUN_00881000(0x24,iVar7);
    if (cVar3 == '\0') {
      (**(code **)(*piVar1 + 0xc))();
    }
    uVar5 = (**(code **)(*piVar1 + 0x1c))(0x24,iVar7);
    unaff_retaddr = &local_248;
  }
  (**(code **)(*piVar1 + 0x14))(iVar7,unaff_retaddr);
  FUN_00881060();
  return uVar5;
}


// ==== FUN_00871f10 @ 0x00871f10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00871f10(int param_1,int param_2,int param_3)

{
  float fVar1;
  code *pcVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  int in_ECX;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  int *piVar18;
  float local_54;
  float local_50;
  float local_4c;
  int local_48;
  int *local_44;
  undefined4 local_40;
  float local_3c;
  void *local_38;
  float local_34;
  float local_30;
  float local_2c [2];
  int *local_24;
  float local_20;
  float local_1c;
  void *local_18;
  float local_14;
  float local_10;
  undefined4 local_8;
  uint local_4;
  
  iVar4 = param_1;
  local_4c = *(float *)(param_1 + 0x14);
  local_54 = (float)*(int *)(param_1 + 0x3c);
  local_48 = *(int *)(param_1 + 0x18);
  local_44 = *(int **)(param_1 + 0x1c);
  local_50 = (float)*(int *)(param_1 + 0x40);
  local_40 = *(undefined4 *)(param_1 + 0x20);
  local_3c = (float)*(int *)(param_1 + 0x34);
  local_38 = (void *)(float)*(int *)(param_1 + 0x38);
  local_34 = local_54;
  local_30 = local_50;
  if (*(char *)(param_1 + 2) == '\0') {
    iVar10 = *(int *)(param_1 + 0x24);
    iVar11 = 0;
    do {
      iVar7 = *(int *)((int)&local_4c + iVar11);
      piVar18 = (int *)((int)local_2c + iVar11);
      if (iVar7 < iVar10) {
        *piVar18 = iVar10;
      }
      else if (*(int *)(param_1 + 0x2c) < iVar7) {
        *piVar18 = *(int *)(param_1 + 0x2c);
      }
      else {
        *piVar18 = iVar7;
      }
      iVar7 = *(int *)((int)local_2c + iVar11 + -0x1c);
      if (iVar7 < *(int *)(param_1 + 0x28)) {
        *(int *)((int)local_2c + iVar11 + 4) = *(int *)(param_1 + 0x28);
      }
      else if (*(int *)(param_1 + 0x30) < iVar7) {
        *(int *)((int)local_2c + iVar11 + 4) = *(int *)(param_1 + 0x30);
      }
      else {
        *(int *)((int)local_2c + iVar11 + 4) = iVar7;
      }
      puVar5 = (undefined4 *)FUN_00871900(&local_54,&local_4c,&local_3c,piVar18);
      uVar9 = puVar5[1];
      *(undefined4 *)((int)&local_1c + iVar11) = *puVar5;
      *(undefined4 *)((int)&local_18 + iVar11) = uVar9;
      iVar11 = iVar11 + 8;
    } while (iVar11 < 0x10);
    local_3c = local_1c;
    local_38 = local_18;
    local_34 = local_14;
    local_30 = local_10;
    local_4c = local_2c[0];
    local_48 = (int)local_2c[1];
    local_44 = local_24;
    local_40 = local_20;
  }
  fVar17 = DAT_0099d080;
  fVar16 = (float)param_2;
  local_24 = (int *)0x0;
  local_20 = DAT_0099d080;
  if (param_2 < 0) {
    fVar16 = fVar16 + _DAT_0099d104;
  }
  fVar16 = DAT_0099d080 / fVar16;
  fVar14 = (float)param_3;
  if (param_3 < 0) {
    fVar14 = fVar14 + _DAT_0099d104;
  }
  fVar14 = DAT_0099d080 / fVar14;
  pfVar6 = (float *)(in_ECX + 0x5c);
  param_1 = 0;
  do {
    fVar3 = DAT_0099d0b4;
    local_2c[1] = (float)*(int *)((int)local_2c + param_1 + -0x1c) - DAT_0099d0b4;
    fVar15 = *(float *)((int)local_2c + param_1 + -0xc);
    iVar10 = 0;
    do {
      local_2c[0] = (float)*(int *)((int)&local_4c + iVar10) - fVar3;
      fVar1 = *(float *)((int)&local_3c + iVar10);
      pfVar6[-6] = local_2c[0];
      pfVar6[-5] = local_2c[1];
      pfVar6[-4] = 0.0;
      pfVar6[-1] = fVar1 * fVar16;
      *pfVar6 = fVar15 * fVar14;
      pfVar6[-3] = fVar17;
      pfVar6[-2] = *(float *)(iVar4 + 0x10);
      iVar10 = iVar10 + 8;
      pfVar6 = pfVar6 + 7;
    } while (iVar10 < 0x10);
    param_1 = param_1 + 8;
  } while (param_1 < 0x10);
  if (*(char *)(iVar4 + 2) != '\0') {
    fVar12 = (float10)FUN_0040d4c0(*(undefined4 *)(iVar4 + 8));
    fVar13 = (float10)FUN_0040d4d0(*(undefined4 *)(iVar4 + 8));
    fVar16 = (float)(*(int *)(iVar4 + 0x14) + *(int *)(iVar4 + 0x1c)) * DAT_0099d0b4;
    fVar17 = (float)(*(int *)(iVar4 + 0x18) + *(int *)(iVar4 + 0x20)) * DAT_0099d0b4;
    iVar10 = 4;
    pfVar6 = (float *)(in_ECX + 0x44);
    do {
      local_2c[0] = *pfVar6;
      local_2c[1] = pfVar6[1];
      local_34 = pfVar6[2];
      local_30 = pfVar6[3];
      fVar14 = local_2c[0] - fVar16;
      fVar15 = local_2c[1] - fVar17;
      local_3c = fVar14 * (float)fVar13 + fVar15 * (float)fVar12 + fVar16;
      local_38 = (void *)(fVar14 * -(float)fVar12 + fVar15 * (float)fVar13 + fVar17);
      *pfVar6 = local_3c;
      pfVar6[1] = (float)local_38;
      pfVar6[2] = local_34;
      iVar10 = iVar10 + -1;
      pfVar6[3] = local_30;
      pfVar6 = pfVar6 + 7;
      local_24 = (int *)local_34;
      local_20 = local_30;
    } while (iVar10 != 0);
  }
  iVar10 = **(int **)(DAT_00b5ac04 + 0x34);
  if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_m_pDevice_009ae948,9);
    FUN_00406880(&local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_18);
    return;
  }
  piVar18 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  iVar11 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(int *)(iVar4 + 4) == 1) {
    iVar7 = (**(code **)(*DAT_00b5af70 + 4))(4);
  }
  else if (*(int *)(iVar4 + 4) == 3) {
    iVar7 = (**(code **)(*DAT_00b5af70 + 4))(5);
  }
  else {
    iVar7 = 0;
    if (*(int *)(iVar4 + 0x74) != 0) {
      piVar8 = (int *)FUN_004af750();
      iVar7 = (**(code **)(*piVar8 + 4))();
    }
  }
  if (*(int *)(iVar11 + 0x134) != iVar7) {
    *(int *)(iVar11 + 0x134) = iVar7;
    (**(code **)(**(int **)(iVar11 + 0x90) + 0x104))(*(int **)(iVar11 + 0x90),0,iVar7);
  }
  if (*(int *)(iVar4 + 4) == 2) {
    FUN_0085a0d0();
    iVar11 = *(int *)(DAT_00b5ac04 + 0x28);
    iVar7 = (**(code **)(*DAT_00b5af70 + 4))(3);
    if (*(int *)(iVar11 + 0x138) != iVar7) {
      *(int *)(iVar11 + 0x138) = iVar7;
      (**(code **)(**(int **)(iVar11 + 0x90) + 0x104))(*(int **)(iVar11 + 0x90),1,iVar7);
    }
    (**(code **)(*piVar18 + 0x164))(piVar18,0x344);
    piVar8 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    iVar11 = 0x24;
    piVar18 = (int *)0x0;
    (**(code **)(*piVar8 + 400))(piVar8,0,*(undefined4 *)(iVar10 + 4),0,0x24);
    local_1c = (float)CONCAT31(local_1c._1_3_,1);
  }
  else {
    piVar18 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    iVar11 = 0;
    (**(code **)(*piVar18 + 400))(piVar18,0,*(undefined4 *)(iVar10 + 4),0,0x1c);
  }
  local_18 = (void *)FUN_00871c10(4,iVar11 + 0x44,local_1c);
  piVar8 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar8[7] <= piVar8[8] + 8U) {
    (**(code **)(*piVar8 + 0x10))();
  }
  uVar9 = (**(code **)(*piVar8 + 0x20))(8);
  (**(code **)(*piVar8 + 0x18))(4,piVar18 + 0xf);
  FUN_00881080();
  if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90) == 0) {
    local_30 = 2.10195e-44;
    local_34 = 0.0;
    local_44 = (int *)((uint)local_44 & 0xffffff00);
    FUN_00401740(s_m_pDevice_009ae948,9);
    FUN_00406880(&local_48);
    if ((uint)local_30 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_44);
    return;
  }
  piVar18 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar18 + 0x1a0))(piVar18,*(undefined4 *)(iVar10 + 0x18));
  piVar18 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar18 + 0x148))(piVar18,5,local_2c[0],0,4,uVar9,2);
  if (local_4c._0_1_ != '\0') {
    FUN_0085a1e0();
    FUN_00858a60();
    (**(code **)(*local_44 + 0x164))(local_44,0x144);
    iVar10 = *(int *)(DAT_00b5ac04 + 0x28);
    if (*(int *)(iVar10 + 0x138) != 0) {
      *(undefined4 *)(iVar10 + 0x138) = 0;
      (**(code **)(**(int **)(iVar10 + 0x90) + 0x104))(*(int **)(iVar10 + 0x90),1,0);
    }
  }
  if ((*(int *)(iVar4 + 4) == 1) || (*(int *)(iVar4 + 4) == 3)) {
    iVar10 = *(int *)(DAT_00b5ac04 + 0x28);
    iVar11 = 0;
    if (*(int *)(iVar4 + 0x74) != 0) {
      piVar18 = (int *)FUN_004af750();
      iVar11 = (**(code **)(*piVar18 + 4))();
    }
    if (*(int *)(iVar10 + 0x134) != iVar11) {
      *(int *)(iVar10 + 0x134) = iVar11;
      (**(code **)(**(int **)(iVar10 + 0x90) + 0x104))(*(int **)(iVar10 + 0x90),0,iVar11);
    }
  }
  return;
}


// ==== FUN_00872580 @ 0x00872580 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00872580(char *param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  float fVar7;
  float fVar8;
  undefined4 *puVar9;
  float *pfVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  uint unaff_EDI;
  int iVar14;
  code *pcStack_a8;
  float local_94;
  float local_90;
  int local_8c;
  float local_88 [9];
  int local_64 [8];
  float local_44 [8];
  float local_24;
  float local_20 [8];
  
  if (*param_1 != '\0') {
    if ((param_1[1] != '\0') && (param_1[2] == '\0')) {
      pcStack_a8 = FUN_00419fa0;
      FUN_0040d030(local_88 + 8,8,4);
      local_88[8] = *(float *)(param_1 + 0x14);
      local_64[0] = *(int *)(param_1 + 0x18);
      local_64[6] = *(int *)(param_1 + 0x20);
      local_64[1] = *(int *)(param_1 + 0x44) + (int)local_88[8];
      local_64[2] = *(int *)(param_1 + 0x48) + local_64[0];
      pcStack_a8 = FUN_00419fa0;
      local_64[5] = *(int *)(param_1 + 0x1c);
      local_64[4] = local_64[6] - *(int *)(param_1 + 0x50);
      local_64[3] = local_64[5] - *(int *)(param_1 + 0x4c);
      FUN_0040d030(local_44,8,4);
      local_44[0] = (float)*(int *)(param_1 + 0x34);
      local_44[1] = (float)*(int *)(param_1 + 0x38);
      local_44[2] = (float)(*(int *)(param_1 + 0x44) + *(int *)(param_1 + 0x34));
      local_44[3] = (float)(*(int *)(param_1 + 0x48) + *(int *)(param_1 + 0x38));
      local_44[4] = (float)(*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x4c));
      local_44[5] = (float)(*(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x50));
      local_94 = (float)*(int *)(param_1 + 0x3c);
      local_90 = (float)*(int *)(param_1 + 0x40);
      pcStack_a8 = FUN_00419fa0;
      local_44[6] = local_94;
      local_44[7] = local_90;
      FUN_0040d030(local_88,8,4);
      pcStack_a8 = FUN_00419fa0;
      FUN_0040d030(local_20,8,4);
      iVar13 = *(int *)(param_1 + 0x24);
      iVar3 = *(int *)(param_1 + 0x28);
      iVar14 = 0;
      do {
        iVar4 = *(int *)((int)local_88 + iVar14 + 0x20);
        pcStack_a8 = (code *)((int)local_88 + iVar14);
        if (iVar4 < iVar13) {
          *(int *)pcStack_a8 = iVar13;
        }
        else if (*(int *)(param_1 + 0x2c) < iVar4) {
          *(int *)pcStack_a8 = *(int *)(param_1 + 0x2c);
        }
        else {
          *(int *)pcStack_a8 = iVar4;
        }
        iVar4 = *(int *)((int)local_64 + iVar14);
        if (iVar4 < iVar3) {
          *(int *)((int)local_88 + iVar14 + 4) = iVar3;
        }
        else if (*(int *)(param_1 + 0x30) < iVar4) {
          *(int *)((int)local_88 + iVar14 + 4) = *(int *)(param_1 + 0x30);
        }
        else {
          *(int *)((int)local_88 + iVar14 + 4) = iVar4;
        }
        puVar9 = (undefined4 *)FUN_00871730(&local_94,local_88 + 8,local_44);
        fVar8 = DAT_0099d0b4;
        fVar7 = DAT_0099d080;
        *(undefined4 *)((int)local_20 + iVar14) = *puVar9;
        *(undefined4 *)((int)local_20 + iVar14 + 4) = puVar9[1];
        iVar14 = iVar14 + 8;
      } while (iVar14 < 0x20);
      local_24 = (float)param_2;
      local_44[1] = local_20[1];
      local_44[0] = local_20[0];
      local_44[4] = local_20[4];
      local_44[2] = local_20[2];
      local_44[3] = local_20[3];
      local_44[7] = local_20[7];
      local_44[5] = local_20[5];
      local_44[6] = local_20[6];
      local_64[1] = (int)local_88[2];
      local_88[8] = local_88[0];
      local_64[0] = (int)local_88[1];
      local_64[4] = (int)local_88[5];
      local_64[2] = (int)local_88[3];
      local_64[3] = (int)local_88[4];
      local_88[2] = 0.0;
      local_64[5] = (int)local_88[6];
      local_64[6] = (int)local_88[7];
      local_88[3] = DAT_0099d080;
      if (param_2 < 0) {
        local_24 = local_24 + _DAT_0099d104;
      }
      local_24 = DAT_0099d080 / local_24;
      local_94 = (float)param_3;
      if (param_3 < 0) {
        local_94 = local_94 + _DAT_0099d104;
      }
      local_94 = DAT_0099d080 / local_94;
      pfVar10 = (float *)(local_8c + 0x5c);
      local_64[7] = 0;
      do {
        local_88[1] = (float)*(int *)((int)local_64 + local_64[7]) - fVar8;
        fVar1 = *(float *)((int)local_44 + local_64[7] + 4);
        iVar13 = 0;
        do {
          local_88[0] = (float)*(int *)((int)local_88 + iVar13 + 0x20) - fVar8;
          fVar2 = *(float *)((int)local_44 + iVar13);
          pfVar10[-6] = local_88[0];
          pfVar10[-5] = local_88[1];
          pfVar10[-4] = 0.0;
          pfVar10[-1] = fVar2 * local_24;
          *pfVar10 = fVar1 * local_94;
          pfVar10[-3] = fVar7;
          pfVar10[-2] = *(float *)(param_1 + 0x10);
          iVar13 = iVar13 + 8;
          pfVar10 = pfVar10 + 7;
        } while (iVar13 < 0x20);
        local_64[7] = local_64[7] + 8;
      } while (local_64[7] < 0x20);
      pcStack_a8 = (code *)0x0;
      uVar11 = FUN_00871c10(0x10,local_8c + 0x44);
      piVar5 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
      if ((uint)piVar5[7] <= piVar5[8] + 0x2cU) {
        pcStack_a8 = (code *)0x87293c;
        (**(code **)(*piVar5 + 0x10))();
      }
      pcStack_a8 = (code *)0x2c;
      uVar12 = (**(code **)(*piVar5 + 0x20))();
      (**(code **)(*piVar5 + 0x18))(0x16,local_8c + 0x10);
      FUN_00881080();
      iVar13 = **(int **)(DAT_00b5ac04 + 0x34);
      piVar5 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar5 + 400))(piVar5,0,*(undefined4 *)(iVar13 + 4),0,0x1c);
      if (*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90) != 0) {
        piVar5 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar5 + 0x1a0))(piVar5,*(undefined4 *)(iVar13 + 0x18));
        piVar5 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar5 + 0x148))(piVar5,5,uVar11,0,0x10,uVar12,0x14);
        return;
      }
      local_90 = 2.10195e-44;
      local_94 = 0.0;
      FUN_00401740(s_m_pDevice_009ae948,9);
      FUN_00406880(&pcStack_a8);
      if ((uint)local_90 < 0x10) {
        pcVar6 = (code *)swi(3);
        (*pcVar6)();
        return;
      }
      _free((void *)(unaff_EDI & 0xffffff00));
      return;
    }
    pcStack_a8 = (code *)0x872a31;
    FUN_00871f10();
  }
  return;
}


// ==== FUN_00872a40 @ 0x00872a40 ====

void FUN_00872a40(void)

{
  int in_ECX;
  
  FUN_008741f0(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  FUN_0088b2d0();
  return;
}


// ==== FUN_00872a80 @ 0x00872a80 ====

/* WARNING: Removing unreachable block (ram,0x00872ab9) */
/* WARNING: Removing unreachable block (ram,0x00872ac0) */
/* WARNING: Removing unreachable block (ram,0x00872ace) */

void FUN_00872a80(void)

{
  int in_ECX;
  int iVar1;
  int *piVar2;
  int local_8;
  int local_4;
  
  piVar2 = (int *)(in_ECX + 0x18);
  iVar1 = 0xe;
  local_4 = in_ECX;
  do {
    FUN_0059c2f0();
    local_8 = piVar2[-4];
    if (piVar2[-1] != *piVar2) {
      *piVar2 = piVar2[-1];
    }
    FUN_00873800(piVar2[-1],9,&local_8);
    piVar2[2] = 1;
    piVar2[3] = 1;
    piVar2 = piVar2 + 10;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(local_4 + 0x230) = 0;
  return;
}


// ==== FUN_00872b10 @ 0x00872b10 ====

void FUN_00872b10(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_9;
  undefined4 local_8;
  int local_4;
  
  puVar1 = (undefined4 *)(in_ECX + 0xc);
  iVar2 = 0xe;
  local_4 = in_ECX;
  do {
    *(undefined1 *)(puVar1 + -3) = local_9;
    local_8 = FUN_00873560();
    puVar1[-1] = local_8;
    *puVar1 = 0;
    FUN_00873ae0(9,&local_8);
    puVar1[5] = 1;
    puVar1[6] = 1;
    puVar1 = puVar1 + 10;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(local_4 + 0x230) = 0;
  return;
}


// ==== FUN_00872b80 @ 0x00872b80 ====

void FUN_00872b80(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined1 local_2c [8];
  undefined1 local_24 [4];
  void *local_20;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar5 = param_2;
  iVar4 = param_1;
  iVar1 = param_1 * 0x28;
  FUN_0041ec50(&param_1,param_2);
  if (param_1 != *(int *)(in_ECX + iVar1 + 8)) {
    *param_3 = *(undefined4 *)(param_1 + 0x24);
    *param_4 = *(undefined4 *)(param_1 + 0x28);
    return;
  }
  if (300 < *(uint *)(in_ECX + 0x230)) {
    FUN_00872a80();
  }
  puVar6 = param_4;
  FUN_0086f570(iVar4,uVar5,param_3,param_4);
  uVar2 = *param_3;
  uVar3 = *puVar6;
  local_c = 0xf;
  local_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  FUN_00401660(uVar5,0,0xffffffff);
  local_8 = uVar2;
  local_4 = uVar3;
  FUN_008743b0(local_2c,local_24);
  if (local_c < 0x10) {
    *(int *)(in_ECX + 0x230) = *(int *)(in_ECX + 0x230) + 1;
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_00872c70 @ 0x00872c70 ====

void FUN_00872c70(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  undefined1 auStack_4 [4];
  
  pvVar1 = (void *)in_ECX[0x82];
  *in_ECX = &PTR_FUN_00a136ac;
  if (pvVar1 != (void *)0x0) {
    FUN_0088b440();
    _free(pvVar1);
    return;
  }
  pvVar1 = (void *)in_ECX[0x81];
  in_ECX[0x82] = 0;
  if (pvVar1 == (void *)0x0) {
    in_ECX[0x81] = 0;
    FUN_008747b0();
    FUN_00874240(auStack_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
    _free((void *)in_ECX[2]);
    return;
  }
  FUN_0088b950();
  _free(pvVar1);
  return;
}


// ==== FUN_00872d00 @ 0x00872d00 ====

void FUN_00872d00(uint param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_28;
  int *local_24;
  uint local_1c;
  int *local_18;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = param_1;
  if ((*(int *)(param_1 + 0x58) != 0) &&
     (uVar5 = *(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x58) >> 2, uVar5 != 0)) {
    local_1c = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x18);
    piVar3 = *(int **)(param_1 + 0x5c);
    uVar6 = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x14);
    local_24 = *(int **)(param_1 + 0x58);
    param_1 = uVar5;
    local_18 = piVar3;
    local_14 = uVar6;
    if (local_24 != piVar3) {
      do {
        iVar1 = *local_24;
        if (iVar1 != 0) {
          piVar3 = (int *)FUN_0086fb20(*(undefined4 *)(iVar1 + 0x24));
          FUN_00872b80(*(undefined4 *)(iVar1 + 0x24),iVar1,&param_1,&local_28);
          if (uVar6 < param_1) {
            param_1 = uVar6;
          }
          if (local_1c < local_28) {
            local_28 = local_1c;
          }
          local_10 = *(int *)(iVar2 + 0x14) + *(int *)(iVar1 + 0x1c);
          local_c = *(int *)(iVar2 + 0x18) + *(int *)(iVar1 + 0x20);
          local_8 = param_1 + local_10;
          local_4 = local_28 + local_c;
          if (*(uint *)(iVar1 + 0x18) < 0x10) {
            iVar4 = iVar1 + 4;
          }
          else {
            iVar4 = *(int *)(iVar1 + 4);
          }
          (**(code **)(*piVar3 + 0x38))
                    (piVar3,0,iVar4,0xffffffff,&local_10,0,*(undefined4 *)(iVar1 + 0x28));
          piVar3 = local_18;
          uVar6 = local_14;
        }
        local_24 = local_24 + 1;
      } while (local_24 != piVar3);
    }
  }
  return;
}


// ==== FUN_00872e20 @ 0x00872e20 ====

void FUN_00872e20(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a136ac;
  iVar1 = FUN_008734c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x25) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  FUN_00872b10();
  *(undefined2 *)(in_ECX + 4) = 0;
  *(undefined2 *)((int)in_ECX + 0x12) = 1;
  *(undefined2 *)(in_ECX + 5) = 4;
  *(undefined2 *)((int)in_ECX + 0x16) = 5;
  *(undefined2 *)(in_ECX + 6) = 8;
  *(undefined2 *)((int)in_ECX + 0x1a) = 9;
  *(undefined2 *)(in_ECX + 7) = 0xc;
  *(undefined2 *)((int)in_ECX + 0x1e) = 0xd;
  *(undefined2 *)(in_ECX + 8) = 0xe;
  *(undefined2 *)((int)in_ECX + 0x22) = 9;
  *(undefined2 *)(in_ECX + 9) = 10;
  *(undefined2 *)((int)in_ECX + 0x26) = 5;
  *(undefined2 *)(in_ECX + 10) = 6;
  *(undefined2 *)((int)in_ECX + 0x2a) = 1;
  *(undefined2 *)(in_ECX + 0xb) = 2;
  *(undefined2 *)((int)in_ECX + 0x2e) = 3;
  *(undefined2 *)(in_ECX + 0xc) = 6;
  *(undefined2 *)((int)in_ECX + 0x32) = 7;
  *(undefined2 *)(in_ECX + 0xd) = 10;
  *(undefined2 *)((int)in_ECX + 0x36) = 0xb;
  *(undefined2 *)(in_ECX + 0xe) = 0xe;
  *(undefined2 *)((int)in_ECX + 0x3a) = 0xf;
  *(undefined2 *)(in_ECX + 0xf) = 0;
  *(undefined2 *)((int)in_ECX + 0x3e) = 1;
  *(undefined2 *)(in_ECX + 0x10) = 2;
  *(undefined2 *)((int)in_ECX + 0x42) = 3;
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0088b9e0();
  }
  in_ECX[0x81] = uVar3;
  pvVar2 = operator_new(0x18);
  if (pvVar2 == (void *)0x0) {
    in_ECX[0x82] = 0;
    return;
  }
  uVar3 = FUN_00874350();
  in_ECX[0x82] = uVar3;
  return;
}


// ==== FUN_00872f50 @ 0x00872f50 ====

void FUN_00872f50(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  int in_ECX;
  int *unaff_ESI;
  int *piVar11;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x79) != '\0') {
    piVar8 = (int *)FUN_0049b670();
    puVar2 = *(undefined4 **)(in_ECX + 8);
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      piVar11 = (int *)puVar3[6];
      piVar4 = (int *)puVar3[7];
      if (puVar3[4] != 0) {
        piVar9 = (int *)FUN_004af750();
        (**(code **)(*piVar9 + 8))();
        (**(code **)(*piVar9 + 0xc))();
      }
      FUN_00871a80(puVar3[4]);
      iVar5 = *(int *)(DAT_00b5ac04 + 0x28);
      iVar10 = 0;
      if (puVar3[4] != 0) {
        piVar9 = (int *)FUN_004af750();
        iVar10 = (**(code **)(*piVar9 + 4))();
      }
      if (*(int *)(iVar5 + 0x134) != iVar10) {
        *(int *)(iVar5 + 0x134) = iVar10;
        (**(code **)(**(int **)(iVar5 + 0x90) + 0x104))(*(int **)(iVar5 + 0x90),0,iVar10);
      }
      FUN_00858a60();
      (**(code **)(*piVar8 + 0x164))(piVar8,0x144);
      for (; piVar11 != piVar4; piVar11 = piVar11 + 1) {
        FUN_00872580(*piVar11,in_ECX,unaff_ESI);
      }
      (**(code **)(*piVar8 + 0x164))(piVar8,0);
      FUN_00858b90();
      FUN_0085a220();
      FUN_0088b2d0();
      piVar11 = (int *)puVar3[6];
      piVar9 = piVar8;
      if (piVar11 != piVar4) {
        do {
          iVar5 = *piVar11;
          if (*(int *)(iVar5 + 0x78) != 0) {
            FUN_0088cbb0(iVar5);
          }
          FUN_0088b4f0(iVar5);
          piVar11 = piVar11 + 1;
        } while (piVar11 != piVar4);
        piVar9 = unaff_ESI;
      }
      FUN_00858c00();
      FUN_008597d0(0);
      iVar5 = *(int *)(DAT_00b5ac04 + 0x28);
      if (*(char *)(iVar5 + 0x112) != '\0') {
        (**(code **)(**(int **)(iVar5 + 0x90) + 0xe4))(*(int **)(iVar5 + 0x90),7,0);
        (**(code **)(**(int **)(iVar5 + 0x90) + 0xe4))(*(int **)(iVar5 + 0x90),0xe,0);
        (**(code **)(**(int **)(iVar5 + 0x90) + 0xe4))(*(int **)(iVar5 + 0x90),0x17,8);
        *(undefined1 *)(iVar5 + 0x112) = 0;
      }
      FUN_0088ac60();
      FUN_00859830(0);
      FUN_00858a60();
      (**(code **)(*piVar9 + 0x164))(piVar9,0x144);
      for (piVar11 = (int *)puVar3[6]; piVar11 != piVar4; piVar11 = piVar11 + 1) {
        FUN_00872d00(*piVar11);
      }
      (**(code **)(*piVar9 + 0x164))(piVar9,0);
      FUN_00858b90();
      if (*(char *)((int)puVar3 + 0x25) == '\0') {
        puVar6 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar6 + 0x25) == '\0') {
          cVar1 = *(char *)((int)*puVar6 + 0x25);
          puVar3 = puVar6;
          puVar6 = (undefined4 *)*puVar6;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar6 + 0x25);
            puVar3 = puVar6;
            puVar6 = (undefined4 *)*puVar6;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x25);
          puVar7 = (undefined4 *)puVar3[1];
          puVar6 = puVar3;
          while ((puVar3 = puVar7, cVar1 == '\0' && (puVar6 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x25);
            puVar7 = (undefined4 *)puVar3[1];
            puVar6 = puVar3;
          }
        }
      }
    }
  }
  return;
}


// ==== FUN_00873200 @ 0x00873200 ====

void FUN_00873200(int *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 *puVar7;
  int iStack_44;
  int iStack_40;
  undefined4 *apuStack_3c [2];
  undefined4 *puStack_34;
  int local_30;
  int iStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  uint uStack_14;
  void *pvStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x79) != '\0') {
    local_30 = in_ECX;
    iStack_2c = (**(code **)(*param_1 + 0x104))();
    iStack_44 = 0;
    if (0 < iStack_2c) {
      do {
        iStack_40 = (**(code **)(*param_1 + 0x108))(iStack_44);
        puVar7 = (undefined4 *)(*(undefined4 **)(in_ECX + 8))[1];
        iVar2 = *(int *)(iStack_40 + 0xc);
        uVar3 = *(uint *)(iStack_40 + 0x74);
        cVar1 = *(char *)((int)puVar7 + 0x25);
        apuStack_3c[0] = *(undefined4 **)(in_ECX + 8);
        while (cVar1 == '\0') {
          if (((int)puVar7[3] < iVar2) || (((int)puVar7[3] <= iVar2 && ((uint)puVar7[4] < uVar3))))
          {
            puVar5 = (undefined4 *)puVar7[2];
            puVar7 = apuStack_3c[0];
          }
          else {
            puVar5 = (undefined4 *)*puVar7;
          }
          apuStack_3c[0] = puVar7;
          puVar7 = puVar5;
          cVar1 = *(char *)((int)puVar5 + 0x25);
        }
        if (((apuStack_3c[0] == *(undefined4 **)(in_ECX + 8)) || (iVar2 < (int)apuStack_3c[0][3]))
           || ((iVar2 <= (int)apuStack_3c[0][3] && (uVar3 < (uint)apuStack_3c[0][4])))) {
          puStack_34 = *(undefined4 **)(in_ECX + 8);
          ppuVar6 = &puStack_34;
        }
        else {
          ppuVar6 = apuStack_3c;
        }
        puVar7 = *ppuVar6;
        if (puVar7 == *(undefined4 **)(local_30 + 8)) {
          pvStack_24 = (void *)0x0;
          uStack_20 = 0;
          uStack_1c = 0;
          FUN_00873c00(0,1,&iStack_40);
          iStack_18 = iVar2;
          uStack_14 = uVar3;
          FUN_00874120(auStack_28);
          FUN_008749e0(apuStack_3c,&iStack_18);
          if (pvStack_c != (void *)0x0) {
            _free(pvStack_c);
            return;
          }
          pvStack_c = (void *)0x0;
          uStack_8 = 0;
          uStack_4 = 0;
          if (pvStack_24 != (void *)0x0) {
            _free(pvStack_24);
            return;
          }
          pvStack_24 = (void *)0x0;
          uStack_20 = 0;
          uStack_1c = 0;
        }
        else {
          iVar2 = puVar7[6];
          if ((iVar2 == 0) || ((uint)(puVar7[8] - iVar2 >> 2) <= (uint)(puVar7[7] - iVar2 >> 2))) {
            FUN_00873c00(puVar7[7],1,&iStack_40);
          }
          else {
            piVar4 = (int *)puVar7[7];
            *piVar4 = iStack_40;
            puVar7[7] = piVar4 + 1;
          }
        }
        iStack_44 = iStack_44 + 1;
      } while (iStack_44 < iStack_2c);
    }
  }
  return;
}


// ==== FUN_008733b0 @ 0x008733b0 ====

int FUN_008733b0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a4e0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 4) {
    FUN_00897070(param_3,param_1);
    param_3 = param_3 + 4;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00873416 @ 0x00873416 ====

void Catch_00873416(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00873420 @ 0x00873420 ====

void FUN_00873420(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a4a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 6) = 1;
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@008734aa @ 0x008734aa ====

void Catch_008734aa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_008734c0 @ 0x008734c0 ====

void FUN_008734c0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a4b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 9) = 1;
  *(undefined1 *)((int)puVar1 + 0x25) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087354a @ 0x0087354a ====

void Catch_0087354a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00873560 @ 0x00873560 ====

void FUN_00873560(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a4c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x2c);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008735cf @ 0x008735cf ====

void Catch_008735cf(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008735f0 @ 0x008735f0 ====

void FUN_008735f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_008735f0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00873630 @ 0x00873630 ====

void FUN_00873630(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a4d0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00897070(param_1,param_3);
    param_1 = param_1 + 4;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00873696 @ 0x00873696 ====

void Catch_00873696(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008736a0 @ 0x008736a0 ====

void FUN_008736a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008733b0(param_1,param_2,param_3);
  return;
}


// ==== FUN_008736c0 @ 0x008736c0 ====

int FUN_008736c0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00873630(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_008736f0 @ 0x008736f0 ====

void FUN_008736f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_3,0,0xffffffff);
  in_ECX[9] = *(undefined4 *)(param_3 + 0x1c);
  in_ECX[10] = *(undefined4 *)(param_3 + 0x20);
  return;
}


// ==== FUN_00873740 @ 0x00873740 ====

void FUN_00873740(undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  
  piVar4 = param_3;
  piVar6 = *(int **)(in_ECX + 4);
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar6) && (param_3 == piVar6)) {
    FUN_008735f0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x19) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x19);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x19);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x19);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00850bf0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00873800 @ 0x00873800 ====

void FUN_00873800(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 auStack_32 [26];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a4f0;
  local_10 = ExceptionList;
  local_14 = auStack_32 + -0xe;
  local_18 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 2;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
    }
    uVar7 = param_2;
    ExceptionList = &local_10;
    puVar1 = auStack_32 + -0xe;
    if (0x3fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar8 = FUN_0085b3b0();
      uVar7 = (uint)((ulonglong)uVar8 >> 0x20);
      uVar2 = (uint)uVar8;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
    }
    if (uVar2 < iVar6 + uVar7) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
      }
      if (uVar2 < iVar6 + uVar7) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 2;
        }
        uVar2 = iVar3 + uVar7;
      }
      pvVar4 = operator_new(uVar2 * 4);
      local_8 = 0;
      uVar5 = FUN_008736a0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_008736c0(uVar5,param_2,&local_18);
      FUN_008736a0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 4);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)(iVar3 - param_1 >> 2) < uVar7) {
      FUN_008733b0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_008736c0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_008733b0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00873961 @ 0x00873961 ====

void Catch_00873961(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00873a50 @ 0x00873a50 ====

void * FUN_00873a50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a500;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x2c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008736f0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00873abd @ 0x00873abd ====

void Catch_00873abd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00873ae0 @ 0x00873ae0 ====

void FUN_00873ae0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a510;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 != 0) {
    if (0x3fffffff < param_1) {
      FUN_0085b3b0();
    }
    pvVar1 = operator_new(param_1 * 4);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 4 + (int)pvVar1);
    local_8 = 0;
    uVar2 = FUN_008736c0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00873b74 @ 0x00873b74 ====

void Catch_00873b74(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00873b90 @ 0x00873b90 ====

void FUN_00873b90(uint param_1,undefined1 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_00873800(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00873c00 @ 0x00873c00 ====

void FUN_00873c00(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 auStack_2a [18];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a520;
  local_10 = ExceptionList;
  local_14 = auStack_2a + -0xe;
  local_18 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 2;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
    }
    uVar7 = param_2;
    ExceptionList = &local_10;
    puVar1 = auStack_2a + -0xe;
    if (0x3fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar8 = FUN_0085b3b0();
      uVar7 = (uint)((ulonglong)uVar8 >> 0x20);
      uVar2 = (uint)uVar8;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
    }
    if (uVar2 < iVar6 + uVar7) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
      }
      if (uVar2 < iVar6 + uVar7) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 2;
        }
        uVar2 = iVar3 + uVar7;
      }
      pvVar4 = operator_new(uVar2 * 4);
      local_8 = 0;
      uVar5 = FUN_005a6d90(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00845740(uVar5,param_2,&local_18);
      FUN_005a6d90(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 4);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)(iVar3 - param_1 >> 2) < uVar7) {
      FUN_005a6d90(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00845740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005a6d90(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00822d20(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00873d61 @ 0x00873d61 ====

void Catch_00873d61(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00873e50 @ 0x00873e50 ====

/* WARNING: Removing unreachable block (ram,0x00873f69) */
/* WARNING: Removing unreachable block (ram,0x00873f7a) */
/* WARNING: Removing unreachable block (ram,0x00873f83) */
/* WARNING: Removing unreachable block (ram,0x00873f86) */
/* WARNING: Removing unreachable block (ram,0x00873f76) */
/* WARNING: Removing unreachable block (ram,0x00873f94) */
/* WARNING: Removing unreachable block (ram,0x00873fa1) */
/* WARNING: Removing unreachable block (ram,0x00873fac) */
/* WARNING: Removing unreachable block (ram,0x00873fa8) */
/* WARNING: Removing unreachable block (ram,0x00873f9c) */
/* WARNING: Removing unreachable block (ram,0x00873faf) */

void FUN_00873e50(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x25) != '\0') {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c7c8);
  }
  FUN_0051b6b0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
    if (*(char *)(param_2[2] + 0x25) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      piVar3 = (int *)FUN_00412870(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      uVar4 = FUN_004ae4e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[9] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[9] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_0058b7f0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(*piVar5 + 0x24) == '\x01') && (*(char *)(piVar5[2] + 0x24) == '\x01'))
            goto LAB_00874084;
            if (*(char *)(piVar5[2] + 0x24) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              *(undefined1 *)(piVar5 + 9) = 0;
              FUN_00412890(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 9) = (char)piVar3[9];
            *(undefined1 *)(piVar3 + 9) = 1;
            *(undefined1 *)(piVar5[2] + 0x24) = 1;
            FUN_0058b7f0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_00412890(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(piVar5[2] + 0x24) != '\x01') || (*(char *)(*piVar5 + 0x24) != '\x01')) {
              if (*(char *)(*piVar5 + 0x24) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x24) = 1;
                *(undefined1 *)(piVar5 + 9) = 0;
                FUN_0058b7f0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 9) = (char)piVar3[9];
              *(undefined1 *)(piVar3 + 9) = 1;
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              FUN_00412890(piVar3);
              break;
            }
LAB_00874084:
            *(undefined1 *)(piVar5 + 9) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 9) = 1;
  }
  if ((void *)param_2[6] == (void *)0x0) {
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[6]);
  return;
}


// ==== FUN_00874120 @ 0x00874120 ====

void FUN_00874120(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a530;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x3fffffff < uVar1) {
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 4);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 4 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_008736a0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008741d9 @ 0x008741d9 ====

void Catch_008741d9(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008741f0 @ 0x008741f0 ====

void FUN_008741f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x25) != '\0') {
    return;
  }
  FUN_008741f0(*(undefined4 *)((int)param_1 + 8));
  if (*(void **)((int)param_1 + 0x18) == (void *)0x0) {
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x18));
  return;
}


// ==== FUN_00874240 @ 0x00874240 ====

void FUN_00874240(undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  
  piVar4 = param_3;
  piVar6 = *(int **)(in_ECX + 4);
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar6) && (param_3 == piVar6)) {
    FUN_008741f0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x25) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x25) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x25);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x25);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x25);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x25);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00873e50(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00874300 @ 0x00874300 ====

void FUN_00874300(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  FUN_00874120(param_4 + 2);
  *(undefined1 *)(in_ECX + 9) = param_5;
  *(undefined1 *)((int)in_ECX + 0x25) = 0;
  return;
}


// ==== FUN_00874350 @ 0x00874350 ====

void FUN_00874350(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00873420();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  iVar1 = FUN_00873420();
  *(int *)(in_ECX + 0x10) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x10);
  *(int *)(*(int *)(in_ECX + 0x10) + 8) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  return;
}


// ==== FUN_008743b0 @ 0x008743b0 ====

/* WARNING: Removing unreachable block (ram,0x008744cb) */
/* WARNING: Removing unreachable block (ram,0x008746bf) */

void FUN_008743b0(int *param_1,int param_2)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  bool bVar16;
  
  uVar5 = *(uint *)(in_ECX + 0x24);
  if (uVar5 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar5 < iVar4 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar5) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar4 * 2 + -3;
      FUN_00873b90(iVar4 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar5 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar8 = *(undefined4 **)(uVar5 * 4 + *(int *)(in_ECX + 0x14));
    if (puVar8 != *(undefined4 **)(uVar5 * 4 + *(int *)(in_ECX + 0x14) + 4)) {
      do {
        uVar10 = puVar8[7];
        uVar9 = 0xdeadbeef;
        if (uVar10 != 0) {
          iVar4 = (uVar10 >> 4) + 1;
          uVar7 = 0;
          do {
            if ((uint)puVar8[8] < 0x10) {
              puVar12 = puVar8 + 3;
            }
            else {
              puVar12 = (undefined4 *)puVar8[3];
            }
            pcVar1 = (char *)((int)puVar12 + uVar7);
            uVar7 = uVar7 + iVar4;
            uVar9 = uVar9 + (int)*pcVar1;
          } while (uVar7 <= uVar10 - iVar4);
        }
        if ((uVar9 & *(uint *)(in_ECX + 0x20)) == uVar5) {
          puVar12 = (undefined4 *)*puVar8;
        }
        else {
          puVar12 = (undefined4 *)*puVar8;
          if (puVar12 != *(undefined4 **)(in_ECX + 8)) {
            iVar4 = uVar5 * 4;
            puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            uVar10 = uVar5;
            while ((puVar8 == puVar2 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4) = puVar12, uVar10 != 0))) {
              uVar10 = uVar10 - 1;
              iVar4 = uVar10 * 4;
              puVar2 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar4);
            }
            iVar4 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar8[1] = puVar12;
            *(int *)puVar12[1] = iVar4;
            **(undefined4 **)(iVar4 + 4) = puVar8;
            uVar3 = *(undefined4 *)(iVar4 + 4);
            *(undefined4 *)(iVar4 + 4) = puVar12[1];
            puVar12[1] = puVar8[1];
            puVar8[1] = uVar3;
            puVar8 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar10 = *(uint *)(in_ECX + 0x24);
              (uVar5 < uVar10 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar10 * 4) == *(int *)(in_ECX + 8)));
              uVar10 = uVar10 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar10 * 4) = puVar8;
          }
          if (puVar12 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar8 = puVar12;
      } while (puVar12 != *(undefined4 **)(uVar5 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar5 = *(uint *)(param_2 + 0x14);
  uVar10 = 0xdeadbeef;
  if (uVar5 != 0) {
    iVar4 = (uVar5 >> 4) + 1;
    uVar9 = 0;
    do {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        puVar8 = (undefined4 *)(param_2 + 4);
      }
      else {
        puVar8 = *(undefined4 **)(param_2 + 4);
      }
      pcVar1 = (char *)((int)puVar8 + uVar9);
      uVar9 = uVar9 + iVar4;
      uVar10 = uVar10 + (int)*pcVar1;
    } while (uVar9 <= uVar5 - iVar4);
  }
  uVar10 = *(uint *)(in_ECX + 0x20) & uVar10;
  if (*(uint *)(in_ECX + 0x24) <= uVar10) {
    uVar10 = uVar10 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar4 = uVar10 * 4;
  piVar11 = *(int **)(iVar4 + 4 + *(int *)(in_ECX + 0x14));
  if (piVar11 != *(int **)(iVar4 + *(int *)(in_ECX + 0x14))) {
    do {
      piVar11 = (int *)piVar11[1];
      if ((uint)piVar11[8] < 0x10) {
        pbVar14 = (byte *)(piVar11 + 3);
      }
      else {
        pbVar14 = (byte *)piVar11[3];
      }
      uVar9 = *(uint *)(param_2 + 0x14);
      if (uVar5 < *(uint *)(param_2 + 0x14)) {
        uVar9 = uVar5;
      }
      if (uVar9 == 0) {
LAB_00874614:
        if ((uint)piVar11[7] <= uVar9) {
          bVar15 = false;
          goto LAB_00874624;
        }
      }
      else {
        uVar7 = piVar11[7];
        if (uVar9 < (uint)piVar11[7]) {
          uVar7 = uVar9;
        }
        if (*(uint *)(param_2 + 0x18) < 0x10) {
          pbVar13 = (byte *)(param_2 + 4);
        }
        else {
          pbVar13 = *(byte **)(param_2 + 4);
        }
        bVar15 = false;
        iVar6 = 0;
        bVar16 = true;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          bVar15 = *pbVar13 < *pbVar14;
          bVar16 = *pbVar13 == *pbVar14;
          pbVar13 = pbVar13 + 1;
          pbVar14 = pbVar14 + 1;
        } while (bVar16);
        if (!bVar16) {
          iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
        }
        bVar15 = iVar6 < 0;
        if (iVar6 == 0) goto LAB_00874614;
LAB_00874624:
        if (!bVar15) {
          if (*(uint *)(param_2 + 0x18) < 0x10) {
            pbVar14 = (byte *)(param_2 + 4);
          }
          else {
            pbVar14 = *(byte **)(param_2 + 4);
          }
          uVar9 = piVar11[7];
          if (uVar9 == 0) goto LAB_008746ec;
          uVar7 = uVar5;
          if (uVar9 < uVar5) {
            uVar7 = uVar9;
          }
          if ((uint)piVar11[8] < 0x10) {
            pbVar13 = (byte *)(piVar11 + 3);
          }
          else {
            pbVar13 = (byte *)piVar11[3];
          }
          bVar15 = false;
          iVar6 = 0;
          bVar16 = true;
          goto code_r0x008746df;
        }
      }
    } while (piVar11 != *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  goto LAB_00874635;
  while( true ) {
    uVar7 = uVar7 - 1;
    bVar15 = *pbVar13 < *pbVar14;
    bVar16 = *pbVar13 == *pbVar14;
    pbVar13 = pbVar13 + 1;
    pbVar14 = pbVar14 + 1;
    if (!bVar16) break;
code_r0x008746df:
    if (uVar7 == 0) break;
  }
  if (!bVar16) {
    iVar6 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
  }
  bVar15 = iVar6 < 0;
  if (iVar6 == 0) {
LAB_008746ec:
    if (uVar5 <= uVar9) {
      bVar15 = false;
      goto LAB_008746fd;
    }
  }
  else {
LAB_008746fd:
    if (!bVar15) {
      *param_1 = (int)piVar11;
      *(undefined1 *)(param_1 + 1) = 0;
      return;
    }
  }
  piVar11 = (int *)*piVar11;
LAB_00874635:
  iVar6 = FUN_00873a50(piVar11,piVar11[1],param_2);
  FUN_006b5060(1);
  piVar11[1] = iVar6;
  **(int **)(iVar6 + 4) = iVar6;
  iVar6 = piVar11[1];
  if (piVar11 == *(int **)(*(int *)(in_ECX + 0x14) + iVar4)) {
    do {
      *(int *)(*(int *)(in_ECX + 0x14) + iVar4) = iVar6;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      iVar4 = uVar10 * 4;
    } while (piVar11 == *(int **)(*(int *)(in_ECX + 0x14) + iVar4));
  }
  *param_1 = iVar6;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00874720 @ 0x00874720 ====

void * FUN_00874720(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a540;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00874300(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00874795 @ 0x00874795 ====

void Catch_00874795(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008747b0 @ 0x008747b0 ====

void FUN_008747b0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x21c) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x21c) = 0;
    *(undefined4 *)(in_ECX + 0x220) = 0;
    *(undefined4 *)(in_ECX + 0x224) = 0;
    FUN_0059c2f0();
    _free(*(void **)(in_ECX + 0x210));
    return;
  }
  _free(*(void **)(in_ECX + 0x21c));
  return;
}


// ==== FUN_00874800 @ 0x00874800 ====

void FUN_00874800(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0xaaaaaa8 < *(uint *)(in_ECX + 8)) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c48c);
  }
  piVar4 = (int *)FUN_00874720(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
                               param_4,0);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  if (param_3 == *(undefined4 **)(in_ECX + 4)) {
    (*(undefined4 **)(in_ECX + 4))[1] = piVar4;
    **(undefined4 **)(in_ECX + 4) = piVar4;
    *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
  }
  else if (param_2 == '\0') {
    param_3[2] = piVar4;
    if (param_3 == *(undefined4 **)(*(int *)(in_ECX + 4) + 8)) {
      *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
    }
  }
  else {
    *param_3 = piVar4;
    if (param_3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      **(int **)(in_ECX + 4) = (int)piVar4;
    }
  }
  cVar1 = *(char *)(piVar4[1] + 0x24);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x24) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[9] == '\0') {
LAB_00874905:
        *(undefined1 *)(*piVar5 + 0x24) = 1;
        *(undefined1 *)(piVar6 + 9) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x24) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0058b7f0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
        FUN_00412890(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[9] == '\0') goto LAB_00874905;
      if (piVar7 == (int *)*piVar2) {
        FUN_00412890(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x24) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x25) == '\0') {
        *(int *)(*piVar2 + 4) = iVar3;
      }
      piVar2[1] = *(int *)(iVar3 + 4);
      if (iVar3 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
        *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
      }
      else {
        piVar6 = *(int **)(iVar3 + 4);
        if (iVar3 == *piVar6) {
          *piVar6 = (int)piVar2;
        }
        else {
          piVar6[2] = (int)piVar2;
        }
      }
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
    }
    cVar1 = *(char *)(piVar7[1] + 0x24);
  } while( true );
}


// ==== FUN_008749e0 @ 0x008749e0 ====

void FUN_008749e0(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  piVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x25) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < (int)puVar4[3]) ||
         ((*param_2 <= (int)puVar4[3] && ((uint)param_2[1] < (uint)puVar4[4])))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x25) == '\0');
  }
  param_2 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_00874a35;
    }
    FUN_0058aca0();
  }
  if ((*piVar2 <= param_2[3]) && ((*piVar2 < param_2[3] || ((uint)piVar2[1] <= (uint)param_2[4]))))
  {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_00874a35:
  puVar4 = (undefined4 *)FUN_00874800(&param_2,local_4,puVar4,piVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00874ab0 @ 0x00874ab0 ====

void FUN_00874ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_00872c70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00874ad0 @ 0x00874ad0 ====

void FUN_00874ad0(void)

{
  return;
}


// ==== FUN_00874ae0 @ 0x00874ae0 ====

void FUN_00874ae0(void)

{
  return;
}


// ==== FUN_00874b20 @ 0x00874b20 ====

undefined4 FUN_00874b20(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(in_ECX + 0x18) + 0x80458) * *(int *)(in_ECX + 0x20);
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  cVar2 = FUN_00881000(*(int *)(in_ECX + 0x20),iVar4);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(*(undefined4 *)(in_ECX + 0x20),iVar4);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x1c))(*(undefined4 *)(in_ECX + 0x20),iVar4);
  (**(code **)(*piVar1 + 0x14))(iVar4,*(undefined4 *)(in_ECX + 0x18));
  FUN_00881060();
  return uVar3;
}


// ==== FUN_00874ba0 @ 0x00874ba0 ====

undefined4 FUN_00874ba0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + 0x8045c);
  piVar2 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar1 * 2;
  if ((uint)piVar2[7] <= (uint)(piVar2[8] + iVar3)) {
    (**(code **)(*piVar2 + 0x10))();
  }
  if ((uint)(piVar2[8] + iVar3) < (uint)piVar2[7]) {
    uVar4 = (**(code **)(*piVar2 + 0x20))(iVar3);
    (**(code **)(*piVar2 + 0x18))(iVar1,*(int *)(in_ECX + 0x18) + 0x765c0);
    FUN_00881080();
    return uVar4;
  }
  return 0;
}


// ==== FUN_00874c10 @ 0x00874c10 ====

undefined4 FUN_00874c10(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x62ae8) * *(int *)(in_ECX + 0x20);
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  cVar2 = FUN_00881000(*(int *)(in_ECX + 0x20),iVar4);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(*(undefined4 *)(in_ECX + 0x20),iVar4);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x1c))(*(undefined4 *)(in_ECX + 0x20),iVar4);
  (**(code **)(*piVar1 + 0x14))(iVar4,*(undefined4 *)(in_ECX + 0x1c));
  FUN_00881060();
  return uVar3;
}


// ==== FUN_00874c90 @ 0x00874c90 ====

undefined4 FUN_00874c90(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x62aec);
  piVar2 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar1 * 2;
  if ((uint)piVar2[7] <= (uint)(piVar2[8] + iVar3)) {
    (**(code **)(*piVar2 + 0x10))();
  }
  if ((uint)(piVar2[8] + iVar3) < (uint)piVar2[7]) {
    uVar4 = (**(code **)(*piVar2 + 0x20))(iVar3);
    (**(code **)(*piVar2 + 0x18))(iVar1,*(int *)(in_ECX + 0x1c) + 0x58c50);
    FUN_00881080();
    return uVar4;
  }
  return 0;
}


// ==== FUN_00874d00 @ 0x00874d00 ====

void FUN_00874d00(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar1 + 0x114) == 2) && (*(int *)(iVar1 + 0x118) == 5)) &&
       (*(int *)(iVar1 + 0x11c) == 6)) {
      return;
    }
    if (*(int *)(iVar1 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  else {
    if (param_1 != 0) {
      return;
    }
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if (((*(int *)(iVar1 + 0x114) == 2) && (*(int *)(iVar1 + 0x118) == 5)) &&
       (*(int *)(iVar1 + 0x11c) == 2)) {
      return;
    }
    if (*(int *)(iVar1 + 100) != 0) {
      return;
    }
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  *(undefined4 *)(iVar1 + 0x114) = 2;
  *(undefined4 *)(iVar1 + 0x118) = 5;
  return;
}


// ==== FUN_00874e90 @ 0x00874e90 ====

void FUN_00874e90(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar3 = (**(code **)(*piVar2 + 0x1c))();
  if (*(int *)(iVar3 + 8) == 0) {
    if (*(uint *)(*(int *)(in_ECX + 0x1c) + 0x62aec) < 4) {
      return;
    }
    uVar4 = FUN_00874c10();
    FUN_00874c90();
    iVar3 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x62aec);
  }
  else {
    if (*(uint *)(*(int *)(in_ECX + 0x18) + 0x8045c) < 4) {
      return;
    }
    uVar4 = FUN_00874b20();
    FUN_00874ba0();
    iVar3 = *(int *)(*(int *)(in_ECX + 0x18) + 0x8045c);
  }
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  iVar1 = **(int **)(DAT_00b5ac04 + 0x34);
  uVar6 = *(undefined4 *)(in_ECX + 0x20);
  uVar5 = 0;
  (**(code **)(*piVar2 + 400))(piVar2,0,*(undefined4 *)(iVar1 + 4),0,uVar6);
  FUN_0084b7f0(*(undefined4 *)(iVar1 + 0x18));
  piVar2 = *(int **)(*(int *)(in_ECX + 0x14) + 0x1c);
  (**(code **)(*piVar2 + 0x10c))(piVar2);
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0x148))(piVar2,5,uVar4,0,uVar6,uVar5,iVar3 + -3);
  return;
}


// ==== FUN_00874fa0 @ 0x00874fa0 ====

void FUN_00874fa0(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_24;
  float local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  param_2[0xc] = (int)*param_1;
  param_2[0xd] = (int)param_1[1];
  fVar3 = (float10)FUN_0040d4c0(param_1[4]);
  param_2[7] = (int)(float)fVar3;
  fVar3 = (float10)FUN_0040d4d0(param_1[4]);
  param_2[8] = (int)(float)fVar3;
  param_2[9] = (int)(param_1[2] * DAT_0099d0f8);
  param_2[6] = (int)param_1[5];
  fVar4 = DAT_0099d0b4;
  fVar8 = 0.0;
  if (0.0 <= *param_1 - param_1[2]) {
    fVar8 = *param_1 - param_1[2];
  }
  fVar7 = 0.0;
  if (0.0 <= param_1[1] - param_1[2]) {
    fVar7 = param_1[1] - param_1[2];
  }
  fVar6 = param_1[2] + *param_1;
  if (fVar6 < 0.0) {
    fVar6 = 0.0;
  }
  fVar5 = param_1[2] + param_1[1];
  if (fVar5 < 0.0) {
    fVar5 = 0.0;
  }
  iVar2 = (int)(fVar5 + DAT_0099d0b4) + 1;
  fVar6 = fVar6 + DAT_0099d0b4;
  param_2[3] = iVar2;
  iVar1 = (int)fVar6 + 1;
  param_2[2] = iVar1;
  param_2[1] = (int)fVar7;
  param_2[5] = (iVar2 - (int)fVar7) + 1;
  *param_2 = (int)fVar8;
  param_2[4] = (iVar1 - (int)fVar8) + 1;
  iVar1 = (int)(*param_1 + fVar4);
  iVar2 = (int)(param_1[1] + fVar4);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_GetVertexHeight_00a13720,0xf);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_24 = (float)iVar1;
  local_20 = (float)iVar2;
  fVar3 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(&local_24);
  param_2[10] = (int)(float)fVar3;
  *(undefined1 *)(param_2 + 0xb) = 0;
  fVar3 = (float10)FUN_005cbf00(iVar1,iVar2);
  if (fVar3 < (float10)(float)param_2[10]) {
    fVar4 = (float)param_2[10] + DAT_009b02b0;
    *(undefined1 *)(param_2 + 0xb) = 1;
    param_2[10] = (int)fVar4;
  }
  return;
}


// ==== FUN_00875130 @ 0x00875130 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00875130(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  uint uVar10;
  float *pfVar11;
  short *psVar12;
  short *psVar13;
  int in_ECX;
  uint uVar14;
  short sVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  uint local_44;
  uint local_40;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  FUN_00401740(s_Fill_Vertex____d_X__d_00a1375c,0x15);
  FUN_00797530(local_1c);
  fVar8 = DAT_0099d0b4;
  fVar7 = DAT_0099d080;
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  iVar2 = *(int *)(*(int *)(in_ECX + 0x18) + 0x80458);
  uVar10 = param_1[4];
  fVar18 = 0.0;
  if (uVar10 * param_1[5] + iVar2 < 0x2775) {
    if ((char)param_1[0xb] != '\0') {
      fVar18 = (float)param_1[10];
    }
    local_44 = 0;
    if (param_1[5] != 0) {
      do {
        local_40 = 0;
        if (uVar10 != 0) {
          do {
            fVar16 = (float)(int)(*param_1 + local_40);
            if ((int)(*param_1 + local_40) < 0) {
              fVar16 = fVar16 + _DAT_0099d104;
            }
            fVar17 = (float)(int)(param_1[1] + local_44);
            if ((int)(param_1[1] + local_44) < 0) {
              fVar17 = fVar17 + _DAT_0099d104;
            }
            if ((char)param_1[0xb] == '\0') {
              iVar3 = *(int *)(*(int *)(in_ECX + 4) + 0xc0);
              uVar10 = *(int *)(iVar3 + 0xc) - 1;
              if ((uint)(int)ROUND(fVar16) <= uVar10) {
                uVar10 = (int)ROUND(fVar16);
              }
              uVar9 = *(int *)(iVar3 + 0x10) - 1;
              uVar14 = (int)ROUND(fVar17);
              if (uVar9 < (uint)(int)ROUND(fVar17)) {
                uVar14 = uVar9;
              }
              iVar4 = *(int *)(iVar3 + 0x2c);
              uVar10 = (*(int *)(iVar3 + 0xc) + 1) * uVar14 + uVar10;
              if ((iVar4 == 0) || ((uint)(*(int *)(iVar3 + 0x30) - iVar4 >> 2) <= uVar10)) {
                    /* WARNING: Subroutine does not return */
                FUN_0042f370();
              }
              fVar18 = *(float *)(iVar4 + uVar10 * 4);
            }
            pfVar11 = (float *)(*(int *)(*(int *)(in_ECX + 0x18) + 0x80458) * 0x30 +
                               *(int *)(in_ECX + 0x18));
            *pfVar11 = fVar16;
            pfVar11[1] = fVar18;
            pfVar11[2] = fVar17;
            fVar16 = (fVar16 - (float)param_1[0xc]) * (fVar7 / (float)param_1[9]);
            fVar17 = (fVar17 - (float)param_1[0xd]) * (fVar7 / (float)param_1[9]);
            pfVar11[9] = ((float)param_1[8] * fVar16 + fVar8) - (float)param_1[7] * fVar17;
            pfVar11[10] = (float)param_1[7] * fVar16 + (float)param_1[8] * fVar17 + fVar8;
            pfVar11[0xb] = (float)param_1[6];
            piVar1 = (int *)(*(int *)(in_ECX + 0x18) + 0x80458);
            *piVar1 = *piVar1 + 1;
            uVar10 = param_1[4];
            local_40 = local_40 + 1;
          } while (local_40 < uVar10);
        }
        local_44 = local_44 + 1;
      } while (local_44 < (uint)param_1[5]);
    }
    iVar3 = param_1[4];
    iVar4 = param_1[5];
    iVar5 = *(int *)(in_ECX + 0x18);
    psVar13 = (short *)(iVar5 + 0x765c0);
    sVar15 = (short)iVar2;
    if (*(int *)(iVar5 + 0x8045c) != 0) {
      psVar13 = psVar13 + *(int *)(iVar5 + 0x8045c);
      psVar13[-1] = (short)param_1[4] + sVar15;
    }
    uVar10 = 0;
    if (param_1[5] != 1) {
      do {
        uVar14 = 0;
        sVar6 = (short)uVar10;
        if (param_1[4] != 0) {
          psVar12 = psVar13;
          do {
            psVar13 = psVar12 + 2;
            *psVar12 = (short)param_1[4] * (sVar6 + 1) + (short)uVar14 + sVar15;
            psVar12[1] = (short)param_1[4] * sVar6 + (short)uVar14 + sVar15;
            uVar14 = uVar14 + 1;
            psVar12 = psVar13;
          } while (uVar14 < (uint)param_1[4]);
        }
        *psVar13 = psVar13[-1];
        uVar10 = uVar10 + 1;
        psVar13[1] = (sVar6 + 2) * (short)param_1[4] + sVar15;
        psVar13 = psVar13 + 2;
      } while (uVar10 < param_1[5] - 1U);
    }
    piVar1 = (int *)(*(int *)(in_ECX + 0x18) + 0x8045c);
    *piVar1 = *piVar1 + (iVar3 + 1) * (iVar4 + -1) * 2;
  }
  return;
}


// ==== FUN_00875470 @ 0x00875470 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00875470(int *param_1)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short sVar7;
  float fVar8;
  float fVar9;
  uint uVar10;
  uint uVar11;
  short *psVar12;
  short *psVar13;
  int in_ECX;
  uint uVar14;
  short sVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  uint local_44;
  uint local_40;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  FUN_00401740(s_Fill_Vertex____d_X__d_00a13774,0x15);
  FUN_00797530(local_1c);
  fVar9 = DAT_0099d0b4;
  fVar8 = DAT_0099d080;
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  iVar3 = *(int *)(*(int *)(in_ECX + 0x1c) + 0x62ae8);
  uVar11 = param_1[4];
  fVar18 = 0.0;
  if (uVar11 * param_1[5] + iVar3 < 0x2775) {
    if ((char)param_1[0xb] != '\0') {
      fVar18 = (float)param_1[10];
    }
    local_44 = 0;
    if (param_1[5] != 0) {
      do {
        local_40 = 0;
        if (uVar11 != 0) {
          do {
            fVar16 = (float)(int)(*param_1 + local_40);
            if ((int)(*param_1 + local_40) < 0) {
              fVar16 = fVar16 + _DAT_0099d104;
            }
            fVar17 = (float)(int)(param_1[1] + local_44);
            if ((int)(param_1[1] + local_44) < 0) {
              fVar17 = fVar17 + _DAT_0099d104;
            }
            if ((char)param_1[0xb] == '\0') {
              iVar4 = *(int *)(*(int *)(in_ECX + 4) + 0xc0);
              uVar11 = *(int *)(iVar4 + 0xc) - 1;
              if ((uint)(int)ROUND(fVar16) <= uVar11) {
                uVar11 = (int)ROUND(fVar16);
              }
              uVar10 = *(int *)(iVar4 + 0x10) - 1;
              uVar14 = (int)ROUND(fVar17);
              if (uVar10 < (uint)(int)ROUND(fVar17)) {
                uVar14 = uVar10;
              }
              iVar5 = *(int *)(iVar4 + 0x2c);
              uVar11 = (*(int *)(iVar4 + 0xc) + 1) * uVar14 + uVar11;
              if ((iVar5 == 0) || ((uint)(*(int *)(iVar4 + 0x30) - iVar5 >> 2) <= uVar11)) {
                    /* WARNING: Subroutine does not return */
                FUN_0042f370();
              }
              fVar18 = *(float *)(iVar5 + uVar11 * 4);
            }
            pfVar2 = (float *)(*(int *)(in_ECX + 0x1c) +
                              *(int *)(*(int *)(in_ECX + 0x1c) + 0x62ae8) * 0x24);
            *pfVar2 = fVar16;
            pfVar2[1] = fVar18;
            pfVar2[2] = fVar17;
            fVar16 = (fVar16 - (float)param_1[0xc]) * (fVar8 / (float)param_1[9]);
            fVar17 = (fVar17 - (float)param_1[0xd]) * (fVar8 / (float)param_1[9]);
            pfVar2[6] = ((float)param_1[8] * fVar16 + fVar9) - (float)param_1[7] * fVar17;
            pfVar2[7] = (float)param_1[7] * fVar16 + (float)param_1[8] * fVar17 + fVar9;
            pfVar2[8] = (float)param_1[6];
            piVar1 = (int *)(*(int *)(in_ECX + 0x1c) + 0x62ae8);
            *piVar1 = *piVar1 + 1;
            uVar11 = param_1[4];
            local_40 = local_40 + 1;
          } while (local_40 < uVar11);
        }
        local_44 = local_44 + 1;
      } while (local_44 < (uint)param_1[5]);
    }
    iVar4 = param_1[4];
    iVar5 = param_1[5];
    iVar6 = *(int *)(in_ECX + 0x1c);
    psVar13 = (short *)(iVar6 + 0x58c50);
    sVar15 = (short)iVar3;
    if (*(int *)(iVar6 + 0x62aec) != 0) {
      psVar13 = psVar13 + *(int *)(iVar6 + 0x62aec);
      psVar13[-1] = (short)param_1[4] + sVar15;
    }
    uVar11 = 0;
    if (param_1[5] != 1) {
      do {
        sVar7 = (short)uVar11;
        if (param_1[4] != 0) {
          uVar14 = 0;
          psVar12 = psVar13;
          do {
            psVar13 = psVar12 + 2;
            *psVar12 = (short)param_1[4] * (sVar7 + 1) + (short)uVar14 + sVar15;
            psVar12[1] = (short)param_1[4] * sVar7 + (short)uVar14 + sVar15;
            uVar14 = uVar14 + 1;
            psVar12 = psVar13;
          } while (uVar14 < (uint)param_1[4]);
        }
        *psVar13 = psVar13[-1];
        uVar11 = uVar11 + 1;
        psVar13[1] = (sVar7 + 2) * (short)param_1[4] + sVar15;
        psVar13 = psVar13 + 2;
      } while (uVar11 < param_1[5] - 1U);
    }
    piVar1 = (int *)(*(int *)(in_ECX + 0x1c) + 0x62aec);
    *piVar1 = *piVar1 + (iVar4 + 1) * (iVar5 + -1) * 2;
  }
  return;
}


// ==== FUN_008757b0 @ 0x008757b0 ====

void FUN_008757b0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  iVar1 = *(int *)(in_ECX + 0x14);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x3f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_20 = *(undefined4 *)(iVar2 + 0xf8);
  piStack_24 = *(int **)(iVar1 + 0x1c);
  uStack_1c = *(int *)(DAT_00b5ac04 + 0x78) + 200;
  uStack_28 = 0x8757f9;
  (**(code **)(*piStack_24 + 0x98))();
  iVar1 = *(int *)(in_ECX + 0x14);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x49)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_28 = 2;
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x80))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x120),(int)register0x00000010 + -0x18)
  ;
  uVar3 = FUN_00862b50(&uStack_28);
  iVar1 = *(int *)(in_ECX + 0x14);
  iVar2 = *(int *)(iVar1 + 0x28);
  if ((iVar2 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar2 >> 2) < 0x4a)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0x80))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar2 + 0x124),uVar3,3);
  return;
}


// ==== FUN_008758a0 @ 0x008758a0 ====

void FUN_008758a0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  char *pcVar8;
  int in_ECX;
  int *piVar9;
  bool bVar10;
  int *piStack_6c;
  char *pcStack_68;
  int *piStack_64;
  uint uStack_60;
  void *pvStack_4c;
  undefined1 auStack_48 [12];
  undefined4 uStack_3c;
  uint uStack_38;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    uStack_60 = *(uint *)(*(int *)(in_ECX + 0x14) + 0x20);
    piStack_64 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piStack_64 + 0x15c))();
    piStack_6c = *(int **)(*(int *)(in_ECX + 0x14) + 0x1c);
    pcStack_68 = s_MapEffect_00a13730;
    (**(code **)(*piStack_6c + 0xf0))();
    FUN_008757b0();
    FUN_00859160();
    piVar9 = *(int **)(*(int *)(in_ECX + 0x14) + 0x1c);
    (**(code **)(*piVar9 + 0x104))(piVar9,&pvStack_4c,0);
    piVar9 = *(int **)(*(int *)(in_ECX + 0x14) + 0x1c);
    (**(code **)(*piVar9 + 0x108))(piVar9,0);
    piStack_64 = *(int **)(in_ECX + 0xc);
    bVar10 = (int *)*piStack_64 == piStack_64;
    piVar9 = (int *)*piStack_64;
    while (!bVar10) {
      piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      iVar4 = (**(code **)(*piVar3 + 0x1c))();
      if (*(int *)(iVar4 + 8) == 0) {
        iVar4 = *(int *)(in_ECX + 0x1c);
        *(undefined4 *)(iVar4 + 0x62ae8) = 0;
        *(undefined4 *)(iVar4 + 0x62aec) = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x18);
        *(undefined4 *)(iVar4 + 0x80458) = 0;
        *(undefined4 *)(iVar4 + 0x8045c) = 0;
      }
      iVar2 = piVar9[9];
      for (iVar4 = piVar9[8]; iVar4 != iVar2; iVar4 = iVar4 + 0x38) {
        piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
        iVar5 = (**(code **)(*piVar3 + 0x1c))();
        if (*(int *)(iVar5 + 8) == 0) {
          FUN_00875470(iVar4);
        }
        else {
          FUN_00875130(iVar4);
        }
      }
      piVar3 = (int *)piVar9[5];
      if (piStack_6c != piVar3) {
        iVar4 = *(int *)(in_ECX + 0x14);
        uVar6 = 0;
        if (piVar3 != (int *)0x0) {
          piVar7 = (int *)FUN_004af750();
          uVar6 = (**(code **)(*piVar7 + 4))();
        }
        iVar2 = *(int *)(iVar4 + 0x28);
        if ((iVar2 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar2 >> 2) < 0x55)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        (**(code **)(**(int **)(iVar4 + 0x1c) + 0xd0))
                  (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar2 + 0x150),uVar6);
        piStack_6c = piVar3;
      }
      if (pcStack_68 != (char *)piVar9[6]) {
        pcStack_68 = (char *)piVar9[6];
        FUN_00874d00(pcStack_68);
      }
      FUN_00874e90();
      piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      (**(code **)(*piVar3 + 0x1c))();
      piVar3 = piVar9;
      if (*(char *)((int)piVar9 + 0x2d) == '\0') {
        piVar3 = (int *)piVar9[2];
        if (*(char *)((int)piVar3 + 0x2d) != '\0') {
          cVar1 = *(char *)(piVar9[1] + 0x2d);
          piVar7 = (int *)piVar9[1];
          while ((piVar3 = piVar7, cVar1 == '\0' && (piVar9 == (int *)piVar3[2]))) {
            cVar1 = *(char *)(piVar3[1] + 0x2d);
            piVar7 = (int *)piVar3[1];
            piVar9 = piVar3;
          }
          goto LAB_00875ab4;
        }
        piVar7 = (int *)*piVar3;
        if (*(char *)(*piVar3 + 0x2d) != '\0') goto LAB_00875ab4;
        do {
          piVar9 = piVar7;
          piVar7 = (int *)*piVar9;
        } while (*(char *)(*piVar9 + 0x2d) == '\0');
        bVar10 = piVar9 == piStack_64;
      }
      else {
LAB_00875ab4:
        bVar10 = piVar3 == piStack_64;
        piVar9 = piVar3;
      }
    }
    piVar9 = *(int **)(*(int *)(in_ECX + 0x14) + 0x1c);
    (**(code **)(*piVar9 + 0x110))(piVar9);
    piVar9 = *(int **)(*(int *)(in_ECX + 0x14) + 0x1c);
    (**(code **)(*piVar9 + 0x114))(piVar9);
    FUN_00859250();
    pcVar8 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
    if (*pcVar8 != '\0') {
      pvStack_4c = (void *)0xf;
      uStack_60 = uStack_60 & 0xffffff00;
      FUN_00401740(s__R_GeoDecal_triangle_count_00a13740,0x1a);
      FUN_00401740(&DAT_00a1373c,2);
      uVar6 = FUN_00404230(auStack_48);
      (**(code **)(*DAT_00b5a688 + 8))(&piStack_64,uVar6);
      if (uStack_38 < 0x10) {
        uStack_38 = 0xf;
        uStack_3c = 0;
        pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
        _free(pcStack_68);
        return;
      }
      _free(pvStack_4c);
      return;
    }
  }
  return;
}


// ==== FUN_00875bb0 @ 0x00875bb0 ====

void FUN_00875bb0(void)

{
  int in_ECX;
  
  FUN_008769d0(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
  *(int *)(*(int *)(in_ECX + 0xc) + 4) = *(int *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0xc);
  *(int *)(*(int *)(in_ECX + 0xc) + 8) = *(int *)(in_ECX + 0xc);
  return;
}


// ==== FUN_00875be0 @ 0x00875be0 ====

void FUN_00875be0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a137a4;
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00875c40 @ 0x00875c40 ====

void FUN_00875c40(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  void **ppvVar6;
  undefined4 uVar7;
  int in_ECX;
  uint uStack_a4;
  void *pvStack_9c;
  void *pvStack_98;
  uint uStack_94;
  uint uStack_90;
  undefined1 auStack_8c [4];
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  int iStack_78;
  void *pvStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  void *pvStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  uint uStack_4c;
  void *pvStack_48;
  char cStack_44;
  undefined1 auStack_40 [60];
  
  iVar4 = (**(code **)(*param_1 + 0xb8))();
  if (iVar4 != 0) {
    iStack_78 = iVar4;
    piVar5 = (int *)(**(code **)(*param_1 + 0x68))();
    iVar1 = *piVar5;
    *(int *)(in_ECX + 4) = iVar1;
    if (iVar1 != 0) {
      uStack_a4 = 0;
      pvStack_98 = (void *)0x0;
      if (0 < iVar4) {
        do {
          iVar4 = (**(code **)(*param_1 + 0xbc))(pvStack_98);
          uVar2 = *(uint *)(iVar4 + 0xc);
          uVar3 = *(uint *)(iVar4 + 0x18);
          uStack_50 = uVar2;
          uStack_4c = uVar3;
          pvStack_9c = (void *)FUN_00875fd0(&uStack_50);
          if (((pvStack_9c == *(void **)(in_ECX + 0xc)) ||
              (uVar2 < *(uint *)((int)pvStack_9c + 0xc))) ||
             ((uVar2 <= *(uint *)((int)pvStack_9c + 0xc) &&
              ((int)uVar3 < *(int *)((int)pvStack_9c + 0x10))))) {
            pvStack_74 = *(void **)(in_ECX + 0xc);
            ppvVar6 = &pvStack_74;
          }
          else {
            ppvVar6 = &pvStack_9c;
          }
          pvStack_9c = *ppvVar6;
          if (pvStack_9c == *(void **)(in_ECX + 0xc)) {
            uStack_88 = 0;
            uStack_84 = 0;
            uStack_80 = 0;
            uStack_94 = uVar2;
            uStack_90 = uVar3;
            uStack_70 = uVar2;
            uStack_6c = uVar3;
            uStack_68 = uVar2;
            uStack_64 = uVar3;
            FUN_00876540(auStack_8c);
            FUN_00876da0(&pvStack_48,&uStack_70);
            if (pvStack_5c != (void *)0x0) {
              _free(pvStack_5c);
              return;
            }
            pvStack_5c = (void *)0x0;
            uStack_58 = 0;
            uStack_54 = 0;
            uStack_80 = 0;
            uStack_84 = 0;
            uStack_88 = 0;
            if (cStack_44 != '\0') {
              pvStack_9c = pvStack_48;
              goto LAB_00875d95;
            }
          }
          else {
LAB_00875d95:
            FUN_00874fa0(iVar4,auStack_40);
            FUN_00876670(auStack_40);
            uStack_a4 = uStack_a4 + 1;
          }
          pvStack_98 = (void *)((int)pvStack_98 + 1);
        } while ((int)pvStack_98 < iStack_78);
        if (DAT_00b5da94 < uStack_a4) {
          DAT_00b5da94 = uStack_a4;
        }
      }
      uStack_7c = 0xf;
      uStack_80 = 0;
      uStack_90 = uStack_90 & 0xffffff00;
      FUN_00401740(s__RENDERER__Decal_Real_Count_00a13704,0x1b);
      FUN_00401740(s__u__u_00a136fc,5);
      uVar7 = FUN_00797530(&uStack_70);
      (**(code **)(*DAT_00b5a688 + 8))(&uStack_94,uVar7);
      if (0xf < uStack_60) {
        _free(pvStack_74);
        return;
      }
      uStack_60 = 0xf;
      uStack_64 = 0;
      pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
      if (0xf < uStack_84) {
        _free(pvStack_98);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00875e90 @ 0x00875e90 ====

void FUN_00875e90(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  undefined4 *puVar5;
  
  *in_ECX = &PTR_FUN_00a137a4;
  iVar1 = FUN_008760a0();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar1 = (**(code **)(*piVar2 + 0x1c))();
  if (*(int *)(iVar1 + 8) == 0) {
    in_ECX[8] = 0x24;
    puVar3 = operator_new(0x62af0);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar5 = puVar3;
      for (iVar1 = 0x16314; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      puVar5 = puVar3 + 0x16314;
      for (iVar1 = 0x27a6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
    }
    in_ECX[7] = puVar3;
    uVar4 = FUN_0085e3a0(0x16);
    in_ECX[5] = uVar4;
    return;
  }
  in_ECX[8] = 0x30;
  puVar3 = operator_new(0x80460);
  if (puVar3 == (undefined4 *)0x0) {
    in_ECX[6] = 0;
    uVar4 = FUN_0085e3a0(5);
    in_ECX[5] = uVar4;
    return;
  }
  puVar5 = puVar3;
  for (iVar1 = 0x1d970; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = puVar3 + 0x1d970;
  for (iVar1 = 0x27a6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  in_ECX[6] = puVar3;
  uVar4 = FUN_0085e3a0(5);
  in_ECX[5] = uVar4;
  return;
}


// ==== FUN_00875fa0 @ 0x00875fa0 ====

int FUN_00875fa0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x38;
}


// ==== FUN_00875fd0 @ 0x00875fd0 ====

undefined4 * FUN_00875fd0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x2d) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((uint)puVar2[3] < *param_1) ||
         (((uint)puVar2[3] <= *param_1 && ((int)puVar2[4] < (int)param_1[1])))) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  return puVar2;
}


// ==== FUN_00876010 @ 0x00876010 ====

void FUN_00876010(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 0xe; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_00876030 @ 0x00876030 ====

int FUN_00876030(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a550;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x38) {
    FUN_00876010(param_3,param_1);
    param_3 = param_3 + 0x38;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00876096 @ 0x00876096 ====

void Catch_00876096(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008760a0 @ 0x008760a0 ====

void FUN_008760a0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a560;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x30);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xb) = 1;
  *(undefined1 *)((int)puVar1 + 0x2d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087612a @ 0x0087612a ====

void Catch_0087612a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00876140 @ 0x00876140 ====

void FUN_00876140(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a570;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00876010(param_1,param_3);
    param_1 = param_1 + 0x38;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008761a6 @ 0x008761a6 ====

void Catch_008761a6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008761b0 @ 0x008761b0 ====

void FUN_008761b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00876030(param_1,param_2,param_3);
  return;
}


// ==== FUN_008761d0 @ 0x008761d0 ====

int FUN_008761d0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00876140(param_1,param_2,param_3);
  return param_1 + param_2 * 0x38;
}


// ==== FUN_00876200 @ 0x00876200 ====

undefined4 FUN_00876200(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x4924924 < param_1) {
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x38);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x38 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_00876260 @ 0x00876260 ====

void FUN_00876260(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  uint extraout_ECX;
  undefined4 *puVar3;
  undefined4 local_6c;
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a580;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x78);
  puVar3 = &local_6c;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x38;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x38;
    }
    ExceptionList = &local_10;
    if (0x4924924U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_24 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x38;
    }
    if (local_24 < iVar2 + param_2) {
      if (0x4924924 - (local_24 >> 1) < local_24) {
        local_24 = 0;
      }
      else {
        local_24 = local_24 + (local_24 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x38;
      }
      if (local_24 < iVar2 + param_2) {
        iVar2 = FUN_00875fa0();
        local_24 = iVar2 + param_2;
      }
      local_24 = local_24 * 0x38;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_20 = FUN_008761b0(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_20 = FUN_008761d0(local_20,param_2,&local_6c);
      FUN_008761b0(param_1,*(undefined4 *)(in_ECX + 8),local_20);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x38;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
        *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar2) * 0x38);
        *(void **)(in_ECX + 4) = local_1c;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_2c = *(int *)(in_ECX + 8);
    local_28 = local_2c - param_1;
    if ((uint)(local_28 / 0x38) < param_2) {
      local_18 = param_2 * 0x38;
      FUN_00876030(param_1,local_2c,local_18 + param_1);
      local_8 = 2;
      FUN_008761d0(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x38,
                   &local_6c);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_004365a0(param_1,*(int *)(in_ECX + 8) - local_18,&local_6c);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x38;
    iVar2 = local_2c + param_2 * -0x38;
    uVar1 = FUN_00876030(iVar2,local_2c,local_2c);
    *(undefined4 *)(in_ECX + 8) = uVar1;
    FUN_00438610(param_1,iVar2,local_2c);
    FUN_004365a0(param_1,local_18 + param_1,&local_6c);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00876425 @ 0x00876425 ====

void Catch_00876425(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00876540 @ 0x00876540 ====

void FUN_00876540(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a590;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_00876200(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_008761b0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008765d9 @ 0x008765d9 ====

void Catch_008765d9(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008765f0 @ 0x008765f0 ====

void FUN_008765f0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x38 != 0) {
      iVar1 = (param_2 - iVar1) / 0x38;
      goto LAB_00876639;
    }
  }
  iVar1 = 0;
LAB_00876639:
  FUN_00876260(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x38;
  return;
}


// ==== FUN_00876670 @ 0x00876670 ====

void FUN_00876670(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x38) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x38))) {
    FUN_008765f0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00876140(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x38;
  return;
}


// ==== FUN_00876700 @ 0x00876700 ====

/* WARNING: Removing unreachable block (ram,0x00876819) */
/* WARNING: Removing unreachable block (ram,0x0087682a) */
/* WARNING: Removing unreachable block (ram,0x00876833) */
/* WARNING: Removing unreachable block (ram,0x00876836) */
/* WARNING: Removing unreachable block (ram,0x00876826) */
/* WARNING: Removing unreachable block (ram,0x00876844) */
/* WARNING: Removing unreachable block (ram,0x00876851) */
/* WARNING: Removing unreachable block (ram,0x0087685c) */
/* WARNING: Removing unreachable block (ram,0x00876858) */
/* WARNING: Removing unreachable block (ram,0x0087684c) */
/* WARNING: Removing unreachable block (ram,0x0087685f) */

void FUN_00876700(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c7c8);
  }
  FUN_00699bf0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
    if (*(char *)(param_2[2] + 0x2d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      piVar3 = (int *)FUN_0079c400(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      uVar4 = FUN_00578a40(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xb] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xb] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_004eb7a0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(*piVar5 + 0x2c) == '\x01') && (*(char *)(piVar5[2] + 0x2c) == '\x01'))
            goto LAB_00876934;
            if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x2c) = 1;
              *(undefined1 *)(piVar5 + 0xb) = 0;
              FUN_005a3430(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
            *(undefined1 *)(piVar3 + 0xb) = 1;
            *(undefined1 *)(piVar5[2] + 0x2c) = 1;
            FUN_004eb7a0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_005a3430(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x2c) != '\x01') || (*(char *)(*piVar5 + 0x2c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x2c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x2c) = 1;
                *(undefined1 *)(piVar5 + 0xb) = 0;
                FUN_004eb7a0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
              *(undefined1 *)(piVar3 + 0xb) = 1;
              *(undefined1 *)(*piVar5 + 0x2c) = 1;
              FUN_005a3430(piVar3);
              break;
            }
LAB_00876934:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
  if ((void *)param_2[8] == (void *)0x0) {
    param_2[8] = 0;
    param_2[9] = 0;
    param_2[10] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[8]);
  return;
}


// ==== FUN_008769d0 @ 0x008769d0 ====

void FUN_008769d0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_008769d0(*(undefined4 *)((int)param_1 + 8));
  if (*(void **)((int)param_1 + 0x20) == (void *)0x0) {
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    *(undefined4 *)((int)param_1 + 0x24) = 0;
    *(undefined4 *)((int)param_1 + 0x28) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x20));
  return;
}


// ==== FUN_00876a20 @ 0x00876a20 ====

void FUN_00876a20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  in_ECX[5] = param_4[2];
  in_ECX[6] = param_4[3];
  FUN_00876540(param_4 + 4);
  *(undefined1 *)(in_ECX + 0xb) = param_5;
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
  return;
}


// ==== FUN_00876b30 @ 0x00876b30 ====

void * FUN_00876b30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a5a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00876a20(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00876ba5 @ 0x00876ba5 ====

void Catch_00876ba5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00876bc0 @ 0x00876bc0 ====

void FUN_00876bc0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0x7fffffd < *(uint *)(in_ECX + 8)) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c48c);
  }
  piVar4 = (int *)FUN_00876b30(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
                               param_4,0);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  if (param_3 == *(undefined4 **)(in_ECX + 4)) {
    (*(undefined4 **)(in_ECX + 4))[1] = piVar4;
    **(undefined4 **)(in_ECX + 4) = piVar4;
    *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
  }
  else if (param_2 == '\0') {
    param_3[2] = piVar4;
    if (param_3 == *(undefined4 **)(*(int *)(in_ECX + 4) + 8)) {
      *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
    }
  }
  else {
    *param_3 = piVar4;
    if (param_3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      **(int **)(in_ECX + 4) = (int)piVar4;
    }
  }
  cVar1 = *(char *)(piVar4[1] + 0x2c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x2c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xb] == '\0') {
LAB_00876cc5:
        *(undefined1 *)(*piVar5 + 0x2c) = 1;
        *(undefined1 *)(piVar6 + 0xb) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x2c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004eb7a0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x2c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x2c) = 0;
        FUN_005a3430(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xb] == '\0') goto LAB_00876cc5;
      if (piVar7 == (int *)*piVar2) {
        FUN_005a3430(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x2c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x2c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x2d) == '\0') {
        *(int *)(*piVar2 + 4) = iVar3;
      }
      piVar2[1] = *(int *)(iVar3 + 4);
      if (iVar3 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
        *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
      }
      else {
        piVar6 = *(int **)(iVar3 + 4);
        if (iVar3 == *piVar6) {
          *piVar6 = (int)piVar2;
        }
        else {
          piVar6[2] = (int)piVar2;
        }
      }
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
    }
    cVar1 = *(char *)(piVar7[1] + 0x2c);
  } while( true );
}


// ==== FUN_00876da0 @ 0x00876da0 ====

void FUN_00876da0(undefined4 *param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x2d) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < (uint)puVar4[3]) ||
         ((*param_2 <= (uint)puVar4[3] && ((int)param_2[1] < (int)puVar4[4])))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  param_2 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_00876df5;
    }
    FUN_0079c420();
  }
  if ((*puVar2 <= param_2[3]) && ((*puVar2 < param_2[3] || ((int)puVar2[1] <= (int)param_2[4])))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_00876df5:
  puVar4 = (undefined4 *)FUN_00876bc0(&param_2,local_4,puVar4,puVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00876e70 @ 0x00876e70 ====

void FUN_00876e70(byte param_1)

{
  void *in_ECX;
  
  FUN_00875be0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00876e90 @ 0x00876e90 ====

void FUN_00876e90(float *param_1,float *param_2,float param_3,float param_4)

{
  float10 fVar1;
  float10 fVar2;
  float fVar3;
  
  if (param_3 == 0.0) {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    return;
  }
  fVar3 = *param_2 * param_3 * param_4;
  param_4 = param_2[1] * param_3 * param_4;
  fVar1 = (float10)FUN_008044f0((double)fVar3);
  fVar2 = (float10)FUN_008044f0((double)param_4);
  *param_1 = (float)((float10)fVar3 - fVar1);
  param_1[1] = (float)((float10)param_4 - fVar2);
  return;
}


// ==== FUN_00876f30 @ 0x00876f30 ====

void FUN_00876f30(void)

{
  FUN_0088da60();
  return;
}


// ==== FUN_00876f60 @ 0x00876f60 ====

void FUN_00876f60(int param_1,int param_2)

{
  if (*(char *)(DAT_00b5ac04 + 0xcc) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x00876f83. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
    return;
  }
  if (*(int *)(param_2 + 0x6c) == 2) {
                    /* WARNING: Could not recover jumptable at 0x00876faa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
    return;
  }
  if (*(int *)(param_2 + 0x6c) == 3) {
                    /* WARNING: Could not recover jumptable at 0x00876fca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00876fe5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
  return;
}


// ==== FUN_00876ff0 @ 0x00876ff0 ====

void FUN_00876ff0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x6c);
  if ((*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) != '\0') && (iVar1 != 0)) {
    iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar2 + 8) != '\0') {
      if (iVar1 == -1) {
                    /* WARNING: Could not recover jumptable at 0x0087703b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
        return;
      }
      if (*(int *)(param_2 + 0x6c) == 1) {
                    /* WARNING: Could not recover jumptable at 0x0087705e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x00877070. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
      return;
    }
  }
  if (*(int *)(param_2 + 0x6c) == 1) {
                    /* WARNING: Could not recover jumptable at 0x00877093. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x008770a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x1c) + 0xf0))();
  return;
}


// ==== FUN_008770b0 @ 0x008770b0 ====

uint FUN_008770b0(int param_1,int param_2,short *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  short *psVar10;
  int *piVar11;
  int in_ECX;
  short sVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  short *psVar16;
  int local_34;
  int *local_28;
  uint local_24;
  
  param_2 = param_1 * 0x10 + param_2;
  if ((*(int *)(param_2 + 4) == 0) || (*(int *)(param_2 + 8) - *(int *)(param_2 + 4) >> 2 == 0)) {
    return CONCAT31((int3)((uint)param_2 >> 8),1);
  }
  local_28 = *(int **)(param_2 + 4);
  piVar2 = *(int **)(param_2 + 8);
  iVar15 = *(int *)(in_ECX + 0x28);
  piVar11 = piVar2;
  if (local_28 != piVar2) {
    do {
      iVar3 = *local_28;
      iVar14 = *(int *)(iVar3 + 0xc4);
      cVar1 = *(char *)(iVar14 + 0xbc);
      uVar7 = CONCAT31((int3)((uint)iVar3 >> 8),cVar1);
      if (cVar1 == '\0') {
        iVar5 = param_1 * 0x3c;
        iVar6 = *(int *)(iVar5 + 0x60 + iVar14);
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(iVar5 + 100 + iVar14) - iVar6 >> 1;
        }
        uVar7 = iVar6 + iVar15;
        if (0x20000 < uVar7) goto LAB_008773c6;
        psVar10 = *(short **)(iVar5 + 0x60 + iVar14);
        psVar4 = *(short **)(iVar5 + 100 + iVar14);
        if (psVar10 != psVar4) {
          psVar16 = (short *)(in_ECX + 0x2c + iVar15 * 2);
          do {
            sVar12 = *psVar10;
            psVar10 = psVar10 + 1;
            *psVar16 = *param_3 + sVar12;
            iVar15 = iVar15 + 1;
            psVar16 = psVar16 + 1;
          } while (psVar10 != psVar4);
        }
        iVar14 = *(int *)(iVar5 + 0x50 + *(int *)(iVar3 + 0xc4));
        piVar11 = (int *)0x0;
        if (iVar14 != 0) {
          piVar11 = (int *)((*(int *)(iVar5 + *(int *)(iVar3 + 0xc4) + 0x54) - iVar14) / 0x24);
        }
LAB_0087739e:
        *param_3 = *param_3 + (short)piVar11;
      }
      else {
        if (cVar1 != '\x04') {
          uVar8 = FUN_008789b0(2,cVar1);
          uVar9 = (*(int *)(iVar3 + 0x48) - *(int *)(iVar3 + 0x40)) + 1;
          iVar14 = (uVar9 & 0xffff) - 1;
          uVar7 = iVar14 / (int)(uVar8 & 0xffff) & 0xffff;
          uVar7 = iVar15 + uVar7 * uVar7 * 6;
          if (0x20000 < uVar7) goto LAB_008773c6;
          local_24 = 0;
          if (0 < iVar14) {
            param_2 = 0;
            iVar6 = uVar9 * uVar8;
            local_34 = iVar6;
            do {
              uVar7 = 0;
              if (0 < iVar14) {
                psVar10 = (short *)(in_ECX + 0x2c + iVar15 * 2);
                do {
                  sVar12 = *param_3;
                  sVar13 = (short)param_2 + sVar12 + (short)uVar7;
                  *psVar10 = sVar13;
                  sVar13 = sVar13 + (short)uVar8;
                  sVar12 = (short)uVar7 + (short)local_34 + sVar12;
                  psVar10[1] = sVar12;
                  psVar10[2] = sVar13;
                  psVar10[3] = sVar13;
                  psVar10[4] = sVar12;
                  uVar7 = uVar7 + uVar8;
                  psVar10[5] = sVar12 + (short)uVar8;
                  iVar15 = iVar15 + 6;
                  psVar10 = psVar10 + 6;
                } while ((int)(uVar7 & 0xffff) < iVar14);
              }
              param_2 = param_2 + iVar6;
              local_34 = local_34 + iVar6;
              local_24 = local_24 + uVar8;
            } while ((int)(local_24 & 0xffff) < iVar14);
          }
          iVar3 = *(int *)(iVar3 + 0xc4) + 0x4c + param_1 * 0x3c;
          iVar14 = *(int *)(iVar3 + 4);
          if (iVar14 == 0) {
            piVar11 = (int *)0x0;
          }
          else {
            piVar11 = (int *)((*(int *)(iVar3 + 8) - iVar14) / 0x24);
          }
          goto LAB_0087739e;
        }
        if (0x20000 < iVar15 + 6U) {
LAB_008773c6:
          return uVar7 & 0xffffff00;
        }
        *(short *)(in_ECX + 0x2c + iVar15 * 2) = *param_3;
        *(short *)(in_ECX + 0x2c + (iVar15 + 1) * 2) = *param_3 + 2;
        *(short *)(in_ECX + 0x2c + (iVar15 + 2) * 2) = *param_3 + 1;
        *(short *)(in_ECX + 0x2c + (iVar15 + 3) * 2) = *param_3 + 1;
        piVar11 = (int *)(uint)(ushort)(*param_3 + 2U);
        *(ushort *)(in_ECX + 0x2c + (iVar15 + 4) * 2) = *param_3 + 2U;
        *(short *)(in_ECX + 0x2c + (iVar15 + 5) * 2) = *param_3 + 3;
        iVar15 = iVar15 + 6;
        *param_3 = *param_3 + 4;
      }
      local_28 = local_28 + 1;
    } while (local_28 != piVar2);
  }
  *(int *)(in_ECX + 0x28) = iVar15;
  return CONCAT31((int3)((uint)piVar11 >> 8),1);
}


// ==== FUN_008773e0 @ 0x008773e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_008773e0(int *param_1,uint param_2,float param_3)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  byte bVar11;
  uint uVar12;
  int in_ECX;
  int iVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  
  iVar2 = *(int *)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
  fVar3 = *(float *)(iVar2 + 0xc);
  fVar4 = *(float *)(iVar2 + 0x10);
  fVar5 = *(float *)(iVar2 + 0x14);
  piVar1 = (int *)((int)param_1 + 4);
  piVar6 = *(int **)((int)param_1 + 8);
  param_1 = piVar6;
  if ((int *)*piVar1 != piVar6) {
    iVar2 = param_2 * 0x3c;
    param_1 = (int *)*piVar1;
    do {
      iVar14 = *param_1;
      fVar8 = *(float *)(iVar14 + 0xb8) - fVar3;
      fVar10 = *(float *)(iVar14 + 0xbc) - fVar4;
      bVar11 = 0;
      fVar9 = *(float *)(iVar14 + 0xc0) - fVar5;
      if ((_DAT_00a137f4 < SQRT(fVar8 * fVar8 + fVar10 * fVar10 + fVar9 * fVar9) - param_3) &&
         (bVar11 = FUN_00802534(), 3 < bVar11)) {
        bVar11 = 4;
      }
      param_2 = 0x5e2;
      if (param_3 == DAT_0099cdc8) {
        param_2 = 0x588;
      }
      iVar13 = *(int *)(iVar14 + 0xc4);
      iVar7 = *(int *)(iVar2 + 0x60 + iVar13);
      if (iVar7 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = *(int *)(iVar2 + 100 + iVar13) - iVar7 >> 1;
      }
      if (uVar12 < param_2) {
        bVar11 = 0;
      }
      *(byte *)(iVar13 + 0xbc) = bVar11;
      iVar14 = *(int *)(iVar14 + 0xc4) + 0x4c + iVar2;
      if (bVar11 == 4) {
        uVar12 = *(uint *)(in_ECX + 0x24);
        if (0x19000 < uVar12 + 4) {
LAB_0087762c:
          return uVar12 & 0xffffff00;
        }
        puVar15 = *(undefined4 **)(iVar14 + 4);
        puVar17 = (undefined4 *)(in_ECX + (uVar12 * 9 + 0x1000b) * 4);
        for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar17 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar17 = puVar17 + 1;
        }
        *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
        puVar15 = (undefined4 *)(*(int *)(iVar14 + 4) + 0x240);
        puVar17 = (undefined4 *)(in_ECX + (*(int *)(in_ECX + 0x24) * 9 + 0x1000b) * 4);
        for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar17 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar17 = puVar17 + 1;
        }
        *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
        puVar15 = (undefined4 *)(*(int *)(iVar14 + 4) + 0x2640);
        puVar17 = (undefined4 *)(in_ECX + (*(int *)(in_ECX + 0x24) * 9 + 0x1000b) * 4);
        for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar17 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar17 = puVar17 + 1;
        }
        *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
        puVar15 = (undefined4 *)(*(int *)(iVar14 + 4) + 0x2880);
        puVar17 = (undefined4 *)(in_ECX + (*(int *)(in_ECX + 0x24) * 9 + 0x1000b) * 4);
        for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar17 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar17 = puVar17 + 1;
        }
        *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
      }
      else {
        puVar15 = *(undefined4 **)(iVar14 + 4);
        if (puVar15 == (undefined4 *)0x0) {
          uVar12 = 0;
        }
        else {
          uVar12 = (*(int *)(iVar14 + 8) - (int)puVar15) / 0x24;
        }
        if (0x19000 < *(int *)(in_ECX + 0x24) + uVar12) goto LAB_0087762c;
        puVar17 = *(undefined4 **)(iVar14 + 8);
        for (; puVar15 < puVar17; puVar15 = puVar15 + 9) {
          puVar16 = puVar15;
          puVar18 = (undefined4 *)(in_ECX + (*(int *)(in_ECX + 0x24) + 0x1c73) * 0x24);
          for (iVar14 = 9; iVar14 != 0; iVar14 = iVar14 + -1) {
            *puVar18 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar18 = puVar18 + 1;
          }
          *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
        }
      }
      param_1 = param_1 + 1;
    } while (param_1 != piVar6);
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}


// ==== FUN_00877640 @ 0x00877640 ====

void FUN_00877640(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13904;
  if (in_ECX[6] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[6]);
    in_ECX[6] = 0;
  }
  if (in_ECX[5] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[5]);
    in_ECX[5] = 0;
  }
  if ((undefined4 *)in_ECX[0xf100c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xf100c])(1);
  }
  in_ECX[0xf100c] = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_00a10a18;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_008776b0 @ 0x008776b0 ====

void FUN_008776b0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 8) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    FUN_0088d730();
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_008776f0 @ 0x008776f0 ====

undefined4 FUN_008776f0(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 *unaff_retaddr;
  undefined4 local_4;
  
  local_4 = DAT_009bac84;
  if (*(int *)(param_3 + 0x6c) == 1) {
    local_4 = 0;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  cVar4 = FUN_008773e0(param_1,0,local_4);
  if (cVar4 != '\0') {
    cVar4 = FUN_008773e0(param_1 + 0x10,1,local_4);
    if (cVar4 != '\0') {
      uVar3 = *(int *)(in_ECX + 0x24) * 0x24;
      if (uVar3 < 0x80001) {
        piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
        cVar4 = FUN_00881000(0x24,uVar3);
        if (cVar4 == '\0') {
          (**(code **)(*piVar1 + 0xc))();
        }
        uVar5 = (**(code **)(*piVar1 + 0x1c))(0x24,uVar3);
        *unaff_retaddr = uVar5;
        (**(code **)(*piVar1 + 0x14))(uVar3,in_ECX + 0x4002c);
        FUN_00881060();
        piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar2 + 400))(piVar2,0,piVar1[1],0,0x24);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_008777e0 @ 0x008777e0 ====

undefined4 FUN_008777e0(void)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x18) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_water_bump01_dds_00a1380c,0x10);
    uVar1 = FUN_004b4e70(local_1c);
    *(undefined4 *)(in_ECX + 0x18) = uVar1;
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_00877840 @ 0x00877840 ====

void FUN_00877840(uint param_1)

{
  code *pcVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 < *(uint *)(in_ECX + 0x20)) {
    FUN_004b3ff0(param_1);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_uiIndex_<_m_dwBumpMax_00a13820,0x15);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_008778b0 @ 0x008778b0 ====

undefined4 FUN_008778b0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 local_4;
  
  local_4 = 0;
  cVar3 = FUN_008770b0(0,param_1,&local_4);
  if (cVar3 != '\0') {
    cVar3 = FUN_008770b0(1,param_1,&local_4);
    if (cVar3 != '\0') {
      piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
      iVar2 = *(int *)(in_ECX + 0x28) * 2;
      if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
        (**(code **)(*piVar1 + 0x10))();
      }
      uVar4 = (**(code **)(*piVar1 + 0x20))(iVar2);
      *param_1 = uVar4;
      (**(code **)(*piVar1 + 0x18))(*(undefined4 *)(in_ECX + 0x28),in_ECX + 0x2c);
      FUN_00881080();
      FUN_0084b7f0(piVar1[6]);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00877950 @ 0x00877950 ====

void FUN_00877950(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  cVar2 = FUN_008776f0(param_2,&local_4,param_3);
  if (cVar2 != '\0') {
    cVar2 = FUN_008778b0(param_2,&local_8);
    if ((cVar2 != '\0') && (3 < *(uint *)(in_ECX + 0x28))) {
      uVar4 = 0;
      puVar3 = &param_3;
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x104))(*(int **)(param_1 + 0x1c),puVar3,0);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x108))(*(int **)(param_1 + 0x1c),0);
      piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar1 + 0x148))
                (piVar1,4,uVar4,0,*(undefined4 *)(in_ECX + 0x24),puVar3,*(uint *)(in_ECX + 0x28) / 3
                );
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x110))(*(int **)(param_1 + 0x1c));
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x114))(*(int **)(param_1 + 0x1c));
    }
  }
  return;
}


// ==== FUN_00877a20 @ 0x00877a20 ====

void FUN_00877a20(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_00a13904;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[6] = 0;
  in_ECX[0xf100b] = 0;
  in_ECX[0xf100c] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Aeffect_water_tpack_00a137f7 + 1,0x12);
  uVar1 = FUN_00839580(local_1c);
  in_ECX[5] = uVar1;
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar1 = FUN_004b3b40();
  in_ECX[8] = uVar1;
  in_ECX[7] = 0x5a;
  pvVar2 = operator_new(0x28);
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0088d960();
  }
  in_ECX[0xf100c] = uVar1;
  puVar4 = in_ECX + 0xb;
  for (iVar3 = 0x10000; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ==== FUN_00877ae0 @ 0x00877ae0 ====

void FUN_00877ae0(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((*(char *)((int)param_1 + 10) != '\0') &&
     (iVar1 = *param_1, *(int *)(in_ECX + 0x3c402c) = iVar1, iVar1 != 0)) {
    FUN_00430ad0(param_1 + 8);
    FUN_0088dc40(param_1);
  }
  return;
}


// ==== FUN_00877b20 @ 0x00877b20 ====

void FUN_00877b20(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int unaff_EBP;
  uint uVar5;
  undefined8 uVar6;
  
  if (*(int *)(param_1 + 0x40) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40) >> 2;
  }
  uVar5 = (uint)(((ulonglong)param_3 / (ulonglong)*(uint *)(param_1 + 0x4c)) % (ulonglong)uVar5);
  iVar4 = *(int *)(param_1 + 0x40);
  uVar6 = CONCAT44(uVar5,iVar4);
  if ((iVar4 == 0) || ((uint)(*(int *)(param_1 + 0x44) - iVar4 >> 2) <= uVar5)) {
    uVar6 = FUN_004b4d10();
  }
  iVar4 = *(int *)((int)uVar6 + (int)((ulonglong)uVar6 >> 0x20) * 4);
  iVar1 = FUN_0085e3a0(8);
  uVar2 = 0;
  if (iVar4 != 0) {
    piVar3 = (int *)FUN_004af750();
    uVar2 = (**(code **)(*piVar3 + 4))();
  }
  iVar4 = *(int *)(iVar1 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x39)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0xe0),uVar2);
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) != '\0') {
    iVar4 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar4 + 8) != '\0') {
      if (0 < *(int *)(unaff_EBP + 0x6c)) {
        iVar4 = FUN_00877840((int)(((ulonglong)param_3 / (ulonglong)*(uint *)(in_ECX + 0x1c)) %
                                  (ulonglong)*(uint *)(in_ECX + 0x20)));
        iVar1 = FUN_0085e3a0(8);
        uVar2 = 0;
        if (iVar4 != 0) {
          piVar3 = (int *)FUN_004af750();
          uVar2 = (**(code **)(*piVar3 + 4))();
        }
        iVar4 = *(int *)(iVar1 + 0x28);
        if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x3a)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
                  (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0xe4),uVar2);
      }
      iVar4 = (**(code **)(*DAT_00b5d98c + 4))();
      iVar1 = FUN_0085e3a0(8);
      uVar2 = 0;
      if (iVar4 != 0) {
        piVar3 = (int *)FUN_004af750();
        uVar2 = (**(code **)(*piVar3 + 4))();
      }
      iVar4 = *(int *)(iVar1 + 0x28);
      if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x3e)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
                (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0xf4),uVar2);
      return;
    }
  }
  iVar1 = FUN_0085e3a0(8);
  iVar4 = *(int *)(iVar1 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x3e)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0xf4),0);
  iVar1 = FUN_0085e3a0(8);
  iVar4 = *(int *)(iVar1 + 0x28);
  if ((iVar4 == 0) || ((uint)(*(int *)(iVar1 + 0x2c) - iVar4 >> 2) < 0x3a)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
                    /* WARNING: Could not recover jumptable at 0x00877d57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(iVar1 + 0x1c) + 0xd0))
            (*(int **)(iVar1 + 0x1c),*(undefined4 *)(iVar4 + 0xe4),0);
  return;
}


// ==== FUN_00877d60 @ 0x00877d60 ====

void FUN_00877d60(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  int *piStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 *puStack_88;
  undefined4 uStack_84;
  int *piStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int *piStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_14;
  int iStack_8;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  uStack_58 = 8;
  uStack_5c = 0x877d77;
  iVar2 = FUN_0085e3a0();
  uStack_58 = 0;
  if (iVar1 != 0) {
    uStack_58 = 0x877d86;
    piVar3 = (int *)FUN_004af750();
    uStack_58 = 0x877d8d;
    uStack_58 = (**(code **)(*piVar3 + 4))();
  }
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x3a)) {
                    /* WARNING: Subroutine does not return */
    uStack_58 = 0x877da9;
    FUN_0085b340();
  }
  piStack_60 = *(int **)(iVar2 + 0x1c);
  uStack_5c = *(undefined4 *)(iVar1 + 0xe4);
  uStack_64 = 0x877dbd;
  (**(code **)(*piStack_60 + 0xd0))();
  iVar1 = *(int *)(iStack_8 + 0xb0);
  uStack_64 = 8;
  uStack_68 = 0x877dd7;
  iVar2 = FUN_0085e3a0();
  uStack_64 = 0;
  if (iVar1 != 0) {
    uStack_64 = 0x877de6;
    piVar3 = (int *)FUN_004af750();
    uStack_64 = 0x877ded;
    uStack_64 = (**(code **)(*piVar3 + 4))();
  }
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x3b)) {
                    /* WARNING: Subroutine does not return */
    uStack_64 = 0x877e09;
    FUN_0085b340();
  }
  uStack_68 = *(undefined4 *)(iVar1 + 0xe8);
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))();
  uStack_78 = (**(code **)(*DAT_00b5af70 + 4))();
  iVar1 = *(int *)(iStack_14 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iStack_14 + 0x2c) - iVar1 >> 2) < 0x3d)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  piStack_80 = *(int **)(iStack_14 + 0x1c);
  uStack_7c = *(undefined4 *)(iVar1 + 0xf0);
  uStack_84 = 0x877e61;
  (**(code **)(*piStack_80 + 0xd0))();
  uStack_84 = 6;
  puStack_88 = &uStack_68;
  uStack_8c = 0x877e73;
  uStack_8c = (**(code **)(*DAT_00b5af70 + 0x20))();
  iVar1 = *(int *)(iStack_14 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iStack_14 + 0x2c) - iVar1 >> 2) < 0x25)) {
                    /* WARNING: Subroutine does not return */
    uStack_8c = 0x877e8e;
    FUN_0085b340();
  }
  uStack_90 = *(undefined4 *)(iVar1 + 0x90);
  piStack_94 = *(int **)(iStack_14 + 0x1c);
  uStack_98 = 0x877ea2;
  (**(code **)(*piStack_94 + 0x98))();
  uStack_98 = 7;
  uStack_9c = 0x877eaf;
  uStack_9c = (**(code **)(*DAT_00b5af70 + 4))();
  iVar1 = *(int *)(iStack_14 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iStack_14 + 0x2c) - iVar1 >> 2) < 0x3c)) {
                    /* WARNING: Subroutine does not return */
    uStack_9c = 0x877eca;
    FUN_0085b340();
  }
  piStack_a4 = *(int **)(iStack_14 + 0x1c);
  uStack_a0 = *(undefined4 *)(iVar1 + 0xec);
  uStack_a8 = 0x877ede;
  (**(code **)(*piStack_a4 + 0xd0))();
  uStack_a8 = 7;
  puStack_ac = &uStack_8c;
  uVar4 = (**(code **)(*DAT_00b5af70 + 0x20))();
  iVar1 = *(int *)(iStack_14 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iStack_14 + 0x2c) - iVar1 >> 2) < 0x26)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iStack_14 + 0x1c) + 0x98))
            (*(int **)(iStack_14 + 0x1c),*(undefined4 *)(iVar1 + 0x94),uVar4);
  iVar1 = *(int *)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
  puStack_ac = *(undefined4 **)(iVar1 + 0xc);
  uStack_a8 = *(undefined4 *)(iVar1 + 0x10);
  piStack_a4 = *(int **)(iVar1 + 0x14);
  iVar1 = *(int *)(iStack_14 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iStack_14 + 0x2c) - iVar1 >> 2) < 0x28)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iStack_14 + 0x1c) + 0x80))
            (*(int **)(iStack_14 + 0x1c),*(undefined4 *)(iVar1 + 0x9c),&puStack_ac,3);
  return;
}


// ==== FUN_00877f80 @ 0x00877f80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00877f80(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piStack_12c;
  int *piStack_128;
  int *piStack_124;
  undefined4 uStack_120;
  int *piStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  int *piStack_110;
  undefined4 uStack_10c;
  float fStack_108;
  int *piStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  int *piStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  int *piStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  int *piStack_e0;
  undefined4 uStack_dc;
  float fStack_d8;
  int *piStack_d4;
  undefined4 uStack_d0;
  int **ppiStack_cc;
  undefined4 uStack_c8;
  int *piStack_c4;
  int *piStack_c0;
  undefined4 uStack_bc;
  int **ppiStack_b8;
  int *piStack_b4;
  undefined4 uStack_b0;
  float **ppfStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  undefined4 uStack_a0;
  undefined1 *puStack_9c;
  undefined4 uStack_98;
  float *pfStack_94;
  int iStack_90;
  float *pfStack_8c;
  float fStack_88;
  int *piStack_84;
  undefined4 uStack_80;
  undefined4 *puStack_7c;
  undefined1 auStack_64 [4];
  undefined4 uStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 local_40 [15];
  int iStack_4;
  
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x24)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_80 = *(undefined4 *)(iVar1 + 0x8c);
  piStack_84 = *(int **)(param_1 + 0x1c);
  puStack_7c = local_40;
  fStack_88 = 1.2443718e-38;
  (**(code **)(*piStack_84 + 0x98))();
  fStack_88 = 1.2443738e-38;
  FUN_0087a970();
  pfStack_8c = *(float **)(iStack_4 + 0x70);
  iStack_90 = iStack_4 + 0x7c;
  pfStack_94 = &fStack_5c;
  uStack_98 = 0x878034;
  FUN_00876e90();
  pfStack_8c = *(float **)(iStack_4 + 0x84);
  iStack_90 = iStack_4 + 0x90;
  pfStack_94 = &fStack_54;
  uStack_98 = 0x878053;
  FUN_00876e90();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x2b)) {
                    /* WARNING: Subroutine does not return */
    fStack_88 = 1.2443864e-38;
    FUN_0085b340();
  }
  iStack_90 = *(undefined4 *)(iVar1 + 0xa8);
  pfStack_94 = *(float **)(param_1 + 0x1c);
  fStack_88 = 2.8026e-45;
  pfStack_8c = &fStack_5c;
  uStack_98 = 0x878088;
  (**(code **)((int)*pfStack_94 + 0x80))();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x2c)) {
                    /* WARNING: Subroutine does not return */
    uStack_98 = 0x8780a3;
    FUN_0085b340();
  }
  uStack_a0 = *(undefined4 *)(iVar1 + 0xac);
  piStack_a4 = *(int **)(param_1 + 0x1c);
  uStack_98 = 2;
  puStack_9c = auStack_64;
  uStack_a8 = 0x8780bd;
  (**(code **)(*piStack_a4 + 0x80))();
  pfStack_94 = *(float **)(DAT_00b5ac04 + 0x9c);
  iStack_90 = *(undefined4 *)(DAT_00b5ac04 + 0xa0);
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x2e)) {
                    /* WARNING: Subroutine does not return */
    uStack_a8 = 0x8780f1;
    FUN_0085b340();
  }
  uStack_b0 = *(undefined4 *)(iVar1 + 0xb4);
  piStack_b4 = *(int **)(param_1 + 0x1c);
  uStack_a8 = 2;
  ppfStack_ac = &pfStack_94;
  ppiStack_b8 = (int **)0x87810b;
  (**(code **)(*piStack_b4 + 0x80))();
  ppiStack_b8 = &piStack_a4;
  uStack_bc = 0x87811e;
  local_40[2] = FUN_00862b50();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x2f)) {
                    /* WARNING: Subroutine does not return */
    ppiStack_b8 = (int **)0x87813d;
    FUN_0085b340();
  }
  piStack_c0 = *(int **)(iVar1 + 0xb8);
  piStack_c4 = *(int **)(param_1 + 0x1c);
  ppiStack_b8 = (int **)0x3;
  uStack_c8 = 0x878159;
  uStack_bc = local_40[2];
  (**(code **)(*piStack_c4 + 0x80))();
  piStack_b4 = *(int **)(iStack_4 + 0x50);
  uStack_b0 = *(undefined4 *)(iStack_4 + 0x54);
  ppfStack_ac = *(float ***)(iStack_4 + 0x58);
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x30)) {
                    /* WARNING: Subroutine does not return */
    uStack_c8 = 0x87818b;
    FUN_0085b340();
  }
  uStack_d0 = *(undefined4 *)(iVar1 + 0xbc);
  piStack_d4 = *(int **)(param_1 + 0x1c);
  uStack_c8 = 3;
  ppiStack_cc = &piStack_b4;
  fStack_d8 = 1.24443e-38;
  (**(code **)(*piStack_d4 + 0x80))();
  iVar1 = *(int *)(param_1 + 0x28);
  fStack_58 = *(float *)(iStack_4 + 0x70) * fStack_50;
  fStack_54 = *(float *)(iStack_4 + 0x84) * fStack_50;
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x31)) {
                    /* WARNING: Subroutine does not return */
    fStack_d8 = 1.24444e-38;
    FUN_0085b340();
  }
  uStack_dc = *(undefined4 *)(iVar1 + 0xc0);
  piStack_e0 = *(int **)(param_1 + 0x1c);
  uStack_e4 = 0x878202;
  fStack_d8 = fStack_58;
  (**(code **)(*piStack_e0 + 0x78))();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x35)) {
                    /* WARNING: Subroutine does not return */
    uStack_e4 = 0x87821d;
    FUN_0085b340();
  }
  uStack_e8 = *(undefined4 *)(iVar1 + 0xd0);
  piStack_ec = *(int **)(param_1 + 0x1c);
  uStack_e4 = uStack_60;
  uStack_f0 = 0x878235;
  (**(code **)(*piStack_ec + 0x78))();
  iVar1 = *(int *)(param_1 + 0x28);
  uStack_f0 = *(undefined4 *)(iStack_4 + 0x74);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x32)) {
                    /* WARNING: Subroutine does not return */
    uStack_f0 = 0x87825b;
    FUN_0085b340();
  }
  uStack_f4 = *(undefined4 *)(iVar1 + 0xc4);
  piStack_f8 = *(int **)(param_1 + 0x1c);
  uStack_fc = 0x878270;
  (**(code **)(*piStack_f8 + 0x78))();
  iVar1 = *(int *)(param_1 + 0x28);
  puStack_7c = *(undefined4 **)(iStack_4 + 0x88);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x36)) {
                    /* WARNING: Subroutine does not return */
    uStack_fc = 0x878299;
    FUN_0085b340();
  }
  uStack_100 = *(undefined4 *)(iVar1 + 0xd4);
  piStack_104 = *(int **)(param_1 + 0x1c);
  fStack_108 = 1.2444671e-38;
  uStack_fc = puStack_7c;
  (**(code **)(*piStack_104 + 0x78))();
  iVar1 = *(int *)(param_1 + 0x28);
  fStack_88 = DAT_00b52018 / *(float *)(iStack_4 + 0x78);
  piStack_84 = (int *)(DAT_00b52018 / *(float *)(iStack_4 + 0x8c));
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x33)) {
                    /* WARNING: Subroutine does not return */
    fStack_108 = 1.2444764e-38;
    FUN_0085b340();
  }
  uStack_10c = *(undefined4 *)(iVar1 + 200);
  piStack_110 = *(int **)(param_1 + 0x1c);
  uStack_114 = 0x878305;
  fStack_108 = fStack_88;
  (**(code **)(*piStack_110 + 0x78))();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x37)) {
                    /* WARNING: Subroutine does not return */
    uStack_114 = 0x878320;
    FUN_0085b340();
  }
  uStack_118 = *(undefined4 *)(iVar1 + 0xd8);
  piStack_11c = *(int **)(param_1 + 0x1c);
  uStack_114 = iStack_90;
  uStack_120 = 0x878338;
  (**(code **)(*piStack_11c + 0x78))();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x34)) {
                    /* WARNING: Subroutine does not return */
    uStack_120 = 0x878353;
    FUN_0085b340();
  }
  piStack_128 = *(int **)(iVar1 + 0xcc);
  piStack_12c = *(int **)(param_1 + 0x1c);
  uStack_120 = 2;
  piStack_124 = (int *)(iStack_4 + 0x7c);
  (**(code **)(*piStack_12c + 0x80))();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x38)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0xdc),iStack_4 + 0x90,2);
  piStack_c0 = DAT_0099d080;
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) == '\x01') {
    if ((0 < *(int *)(iStack_4 + 0x6c)) &&
       (iVar1 = (**(code **)(*DAT_00b5ac00 + 8))(), *(char *)(iVar1 + 8) == '\x01')) {
      piStack_12c = DAT_0099d080;
      piStack_128 = DAT_0099d080;
      piStack_124 = DAT_0099d080;
      uStack_120 = DAT_009c16c0;
      FUN_00869060(0x26,&piStack_12c);
      return;
    }
  }
  else if (*(char *)(DAT_00b5ac04 + 0xcc) != '\0') {
    piStack_12c = DAT_0099d080;
    piStack_128 = DAT_0099d080;
    piStack_124 = DAT_0099d080;
    iVar1 = *(int *)(param_1 + 0x28);
    uStack_120 = DAT_009be92c;
    if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x27)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x88))
              (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x98),&piStack_12c);
    return;
  }
  FUN_00878b50(iStack_4 + 0x98);
  piStack_11c = *(int **)(iStack_4 + 0xa8);
  uStack_120 = *(undefined4 *)(iStack_4 + 0xa4);
  uStack_118 = *(undefined4 *)(iStack_4 + 0xac);
  FUN_004b9680(&uStack_bc,*piStack_128,piStack_128);
  _free(piStack_128);
  return;
}


// ==== FUN_008785c0 @ 0x008785c0 ====

void FUN_008785c0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined4 unaff_EBX;
  int *piVar8;
  float10 fVar9;
  int *piStack_5c;
  undefined4 uStack_58;
  int *local_54;
  int iStack_50;
  int iStack_4c;
  int *piStack_48;
  undefined1 auStack_44 [4];
  int iStack_40;
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  if ((*(int *)(in_ECX + 8) == 0) ||
     (local_54 = (int *)(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2), local_54 == (int *)0x0
     )) {
    return;
  }
  uStack_58 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  iStack_40 = FUN_00878a40();
  *(undefined1 *)(iStack_40 + 0x41) = 1;
  *(int *)(iStack_40 + 4) = iStack_40;
  *(int *)iStack_40 = iStack_40;
  *(int *)(iStack_40 + 8) = iStack_40;
  pvStack_3c = (void *)0x0;
  iStack_4c = FUN_00878a40();
  *(undefined1 *)(iStack_4c + 0x41) = 1;
  *(int *)(iStack_4c + 4) = iStack_4c;
  *(int *)iStack_4c = iStack_4c;
  *(int *)(iStack_4c + 8) = iStack_4c;
  piStack_48 = (int *)0x0;
  piStack_5c = (int *)((uint)piStack_5c & 0xffffff00);
  iVar5 = (**(code **)(*DAT_00b5ac00 + 8))();
  if ((1 < *(byte *)(iVar5 + 8)) && (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xea) != '\0')) {
    piStack_5c = (int *)CONCAT31(piStack_5c._1_3_,1);
  }
  piVar8 = piStack_5c;
  fVar9 = (float10)(**(code **)(*DAT_00b5af70 + 0x10))(piStack_5c);
  FUN_004cefb0(auStack_44,&iStack_50,(float)fVar9,piVar8);
  iVar5 = FUN_0085e3a0(8);
  piVar8 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar8 + 0x15c))(piVar8,*(undefined4 *)(iVar5 + 0x20));
  FUN_00859460();
  piVar8 = (int *)*piStack_48;
  piStack_5c = piStack_48;
  if (piVar8 != piStack_48) {
    do {
      *(undefined4 *)(in_ECX + 0x24) = 0;
      *(undefined4 *)(in_ECX + 0x28) = 0;
      iVar2 = piVar8[3];
      if (*(int *)(iVar2 + 0x6c) != 3) {
        FUN_00876ff0(iVar5,iVar2);
        FUN_00877f80(iVar5,iVar2,unaff_EBX,0);
        FUN_00877b20(iVar2,iVar5,unaff_EBX);
        FUN_00877950(iVar5,piVar8 + 4,iVar2);
      }
      if (*(char *)((int)piVar8 + 0x41) == '\0') {
        piVar3 = (int *)piVar8[2];
        if (*(char *)((int)piVar3 + 0x41) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x41);
          piVar8 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x41);
            piVar8 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x41);
          piVar4 = (int *)piVar8[1];
          piVar3 = piVar8;
          while ((piVar8 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x41);
            piVar4 = (int *)piVar8[1];
            piVar3 = piVar8;
          }
        }
      }
    } while (piVar8 != piStack_5c);
  }
  if (iStack_50 != 0) {
    piVar8 = (int *)*local_54;
    piStack_5c = local_54;
    if (piVar8 != local_54) {
      do {
        *(undefined4 *)(in_ECX + 0x24) = 0;
        *(undefined4 *)(in_ECX + 0x28) = 0;
        iVar2 = piVar8[3];
        piVar3 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        if (*(int *)(iVar2 + 0x6c) == 3) {
          (**(code **)(*piVar3 + 0xe4))(piVar3,0xe,0);
        }
        else {
          (**(code **)(*piVar3 + 0xe4))(piVar3,0xe,1);
        }
        FUN_00876f60(iVar5,iVar2);
        FUN_00877f80(iVar5,iVar2,unaff_EBX,1);
        FUN_00877d60(iVar2,iVar5);
        FUN_00877950(iVar5,piVar8 + 4,iVar2);
        if (*(char *)((int)piVar8 + 0x41) == '\0') {
          piVar3 = (int *)piVar8[2];
          if (*(char *)((int)piVar3 + 0x41) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x41);
            piVar8 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x41);
              piVar8 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar8[1] + 0x41);
            piVar4 = (int *)piVar8[1];
            piVar3 = piVar8;
            while ((piVar8 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar8[2]))) {
              cVar1 = *(char *)(piVar8[1] + 0x41);
              piVar4 = (int *)piVar8[1];
              piVar3 = piVar8;
            }
          }
        }
      } while (piVar8 != piStack_5c);
    }
  }
  pcVar6 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
  if (*pcVar6 != '\0') {
    uStack_28 = 0xf;
    uStack_2c = 0;
    pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
    FUN_00401740(s__R_Water_triangle_count_00a1383c,0x17);
    FUN_00401740(&DAT_00a13838,2);
    uVar7 = FUN_00404230(auStack_24);
    (**(code **)(*DAT_00b5a688 + 8))(&iStack_40,uVar7);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    if (0xf < uStack_28) {
      _free(pvStack_3c);
      return;
    }
  }
  FUN_00859590();
  FUN_0088da60();
  FUN_00878f50(&piStack_5c,*local_54,local_54);
  _free(local_54);
  return;
}


// ==== FUN_00878990 @ 0x00878990 ====

void FUN_00878990(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x41);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x41);
  }
  return;
}


// ==== FUN_008789b0 @ 0x008789b0 ====

int FUN_008789b0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2;
  if ((int)param_2 < 0) {
    uVar1 = -param_2;
  }
  iVar2 = 1;
  while( true ) {
    if ((uVar1 & 1) != 0) {
      iVar2 = iVar2 * param_1;
    }
    uVar1 = uVar1 >> 1;
    if (uVar1 == 0) break;
    param_1 = param_1 * param_1;
  }
  if ((int)param_2 < 0) {
    return (int)(1 / (longlong)iVar2);
  }
  return iVar2;
}


// ==== FUN_008789f0 @ 0x008789f0 ====

void FUN_008789f0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x41) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x41) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x41);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x41);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x41);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x41);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00878a40 @ 0x00878a40 ====

void FUN_00878a40(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a5b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x44);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x10) = 1;
  *(undefined1 *)((int)puVar1 + 0x41) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@00878aca @ 0x00878aca ====

void Catch_00878aca(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00878ae0 @ 0x00878ae0 ====

undefined4 FUN_00878ae0(void)

{
  return 8;
}


// ==== FUN_00878af0 @ 0x00878af0 ====

void FUN_00878af0(byte param_1)

{
  void *in_ECX;
  
  FUN_00877640();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00878b10 @ 0x00878b10 ====

void FUN_00878b10(uint param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x2c) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0xd0))
            (*(int **)(in_ECX + 0x1c),*(undefined4 *)(iVar1 + param_1 * 4),param_2);
  return;
}


// ==== FUN_00878b50 @ 0x00878b50 ====

void FUN_00878b50(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a5c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 4) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_00848bd0(param_1);
  ExceptionList = local_10;
  return;
}


// ==== Catch@00878bc8 @ 0x00878bc8 ====

void Catch_00878bc8(void)

{
  FUN_004b9a50();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00878be0 @ 0x00878be0 ====

/* WARNING: Removing unreachable block (ram,0x00878d00) */
/* WARNING: Removing unreachable block (ram,0x00878d11) */
/* WARNING: Removing unreachable block (ram,0x00878d1a) */
/* WARNING: Removing unreachable block (ram,0x00878d1d) */
/* WARNING: Removing unreachable block (ram,0x00878d0d) */
/* WARNING: Removing unreachable block (ram,0x00878d2b) */
/* WARNING: Removing unreachable block (ram,0x00878d3c) */
/* WARNING: Removing unreachable block (ram,0x00878d47) */
/* WARNING: Removing unreachable block (ram,0x00878d43) */
/* WARNING: Removing unreachable block (ram,0x00878d37) */
/* WARNING: Removing unreachable block (ram,0x00878d4a) */

void FUN_00878be0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  int *piVar5;
  int iVar6;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x41) != '\0') {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c7c8);
  }
  FUN_008789f0();
  piVar5 = (int *)*param_2;
  if (*(char *)((int)piVar5 + 0x41) == '\0') {
    if (*(char *)(param_2[2] + 0x41) == '\0') {
      piVar5 = (int *)param_2[2];
    }
  }
  else {
    piVar5 = (int *)param_2[2];
  }
  piVar4 = (int *)param_2[1];
  if (*(char *)((int)piVar5 + 0x41) == '\0') {
    piVar5[1] = (int)piVar4;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar5;
  }
  else if ((int *)*piVar4 == param_2) {
    *piVar4 = (int)piVar5;
  }
  else {
    piVar4[2] = (int)piVar5;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar5 + 0x41) == '\0') {
      piVar2 = (int *)FUN_00878990(piVar5);
    }
    else {
      piVar2 = piVar4;
    }
    *puVar1 = piVar2;
  }
  iVar6 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar6 + 8) == param_2) {
    if (*(char *)((int)piVar5 + 0x41) == '\0') {
      uVar3 = FUN_004cf3d0(piVar5);
      *(undefined4 *)(iVar6 + 8) = uVar3;
    }
    else {
      *(int **)(iVar6 + 8) = piVar4;
    }
  }
  if ((char)param_2[0x10] == '\x01') {
    if (piVar5 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar2 = piVar4;
        if ((char)piVar5[0x10] != '\x01') break;
        piVar4 = (int *)*piVar2;
        if (piVar5 == piVar4) {
          piVar4 = (int *)piVar2[2];
          if ((char)piVar4[0x10] == '\0') {
            *(undefined1 *)(piVar4 + 0x10) = 1;
            *(undefined1 *)(piVar2 + 0x10) = 0;
            FUN_004cf450(piVar2);
            piVar4 = (int *)piVar2[2];
          }
          if (*(char *)((int)piVar4 + 0x41) == '\0') {
            if ((*(char *)(*piVar4 + 0x40) == '\x01') && (*(char *)(piVar4[2] + 0x40) == '\x01'))
            goto LAB_00878e2c;
            if (*(char *)(piVar4[2] + 0x40) == '\x01') {
              *(undefined1 *)(*piVar4 + 0x40) = 1;
              *(undefined1 *)(piVar4 + 0x10) = 0;
              FUN_004cf4a0(piVar4);
              piVar4 = (int *)piVar2[2];
            }
            *(char *)(piVar4 + 0x10) = (char)piVar2[0x10];
            *(undefined1 *)(piVar2 + 0x10) = 1;
            *(undefined1 *)(piVar4[2] + 0x40) = 1;
            FUN_004cf450(piVar2);
            break;
          }
        }
        else {
          if ((char)piVar4[0x10] == '\0') {
            *(undefined1 *)(piVar4 + 0x10) = 1;
            *(undefined1 *)(piVar2 + 0x10) = 0;
            FUN_004cf4a0(piVar2);
            piVar4 = (int *)*piVar2;
          }
          if (*(char *)((int)piVar4 + 0x41) == '\0') {
            if ((*(char *)(piVar4[2] + 0x40) != '\x01') || (*(char *)(*piVar4 + 0x40) != '\x01')) {
              if (*(char *)(*piVar4 + 0x40) == '\x01') {
                *(undefined1 *)(piVar4[2] + 0x40) = 1;
                *(undefined1 *)(piVar4 + 0x10) = 0;
                FUN_004cf450(piVar4);
                piVar4 = (int *)*piVar2;
              }
              *(char *)(piVar4 + 0x10) = (char)piVar2[0x10];
              *(undefined1 *)(piVar2 + 0x10) = 1;
              *(undefined1 *)(*piVar4 + 0x40) = 1;
              FUN_004cf4a0(piVar2);
              break;
            }
LAB_00878e2c:
            *(undefined1 *)(piVar4 + 0x10) = 0;
          }
        }
        piVar4 = (int *)piVar2[1];
        piVar5 = piVar2;
      } while (piVar2 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar5 + 0x10) = 1;
  }
  iVar6 = 2;
  piVar5 = param_2 + 0xd;
  do {
    if ((void *)piVar5[-4] != (void *)0x0) {
      _free((void *)piVar5[-4]);
      return;
    }
    iVar6 = iVar6 + -1;
    piVar5[-4] = 0;
    piVar5[-3] = 0;
    piVar5[-2] = 0;
    piVar5 = piVar5 + -4;
  } while (iVar6 != 0);
  _free(param_2);
  return;
}


// ==== FUN_00878ee0 @ 0x00878ee0 ====

void FUN_00878ee0(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(char *)((int)param_1 + 0x41) != '\0') {
    return;
  }
  FUN_00878ee0(*(undefined4 *)((int)param_1 + 8));
  iVar1 = 2;
  puVar2 = (undefined4 *)((int)param_1 + 0x34);
  do {
    if ((void *)puVar2[-4] != (void *)0x0) {
      _free((void *)puVar2[-4]);
      return;
    }
    iVar1 = iVar1 + -1;
    puVar2[-4] = 0;
    puVar2[-3] = 0;
    puVar2[-2] = 0;
    puVar2 = puVar2 + -4;
  } while (iVar1 != 0);
  _free(param_1);
  return;
}


// ==== FUN_00878f50 @ 0x00878f50 ====

void FUN_00878f50(undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  
  piVar4 = param_3;
  piVar6 = *(int **)(in_ECX + 4);
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar6) && (param_3 == piVar6)) {
    FUN_00878ee0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x41) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x41) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x41);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x41);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x41);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x41);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00878be0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00879010 @ 0x00879010 ====

void FUN_00879010(void)

{
  int *piVar1;
  int in_ECX;
  uint uVar2;
  undefined4 *unaff_EBX;
  undefined4 unaff_ESI;
  uint unaff_EDI;
  uint uVar3;
  undefined1 local_4 [4];
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
  (**(code **)(*piVar1 + 0x104))(piVar1,local_4,0);
  uVar3 = 0;
  if (unaff_EDI != 0) {
    do {
      piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
      (**(code **)(*piVar1 + 0x108))(piVar1,uVar3);
      if (unaff_EBX[3] == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = (int)(unaff_EBX[4] - unaff_EBX[3]) >> 1;
      }
      piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar1 + 0x148))(piVar1,4,unaff_ESI,*unaff_EBX,unaff_EBX[1],unaff_EBX,uVar2 / 3)
      ;
      piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
      (**(code **)(*piVar1 + 0x110))(piVar1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < unaff_EDI);
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
  (**(code **)(*piVar1 + 0x114))(piVar1);
  if (unaff_EBX[3] == 0) {
    *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0x38);
    return;
  }
  *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + ((int)(unaff_EBX[4] - unaff_EBX[3]) >> 1);
  return;
}


// ==== FUN_008790e0 @ 0x008790e0 ====

void FUN_008790e0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x24) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    FUN_0088f0b0();
    return;
  }
  _free(*(void **)(in_ECX + 0x24));
  return;
}


// ==== FUN_00879120 @ 0x00879120 ====

void FUN_00879120(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[0x10];
  *in_ECX = &PTR_FUN_00a13a14;
  if (_Memory != (void *)0x0) {
    FUN_0088f140();
    _free(_Memory);
    return;
  }
  in_ECX[0x10] = 0;
  if ((void *)in_ECX[9] != (void *)0x0) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_00a10a18;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00879190 @ 0x00879190 ====

void FUN_00879190(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13a14;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 1;
  *(undefined1 *)((int)in_ECX + 0x31) = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  *(undefined1 *)((int)in_ECX + 0x32) = 0;
  pvVar1 = operator_new(0x48);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0088f200();
  }
  in_ECX[0x10] = uVar2;
  *(undefined1 *)((int)in_ECX + 0x33) = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar4 = (**(code **)(*piVar3 + 0x1c))();
  if (*(int *)(iVar4 + 8) == 0) {
    uVar2 = FUN_0085e3a0(0x16);
    in_ECX[0x11] = uVar2;
  }
  return;
}


// ==== FUN_00879220 @ 0x00879220 ====

void FUN_00879220(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined1 *puVar5;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x68))();
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x78) == '\0') {
    return;
  }
  piVar4 = (int *)*piVar2;
  if (piVar4 == (int *)0x0) {
    piVar2 = (int *)FUN_00850960();
    (**(code **)(*piVar2 + 0xc))();
    return;
  }
  if (*(int **)(in_ECX + 0x3c) == piVar4) {
    uVar3 = (**(code **)(*piVar4 + 4))();
    cVar1 = FUN_004a1f80(in_ECX + 4,uVar3);
    if (cVar1 == '\0') goto LAB_008792a8;
  }
  *(int *)(in_ECX + 0x3c) = *piVar2;
  uVar3 = (**(code **)(*(int *)*piVar2 + 4))();
  FUN_00401660(uVar3,0,0xffffffff);
  piVar4 = (int *)FUN_00850960();
  (**(code **)(*piVar4 + 0xc))();
LAB_008792a8:
  FUN_00430ad0(piVar2 + 8);
  *(undefined1 *)(in_ECX + 0x30) = *(undefined1 *)((int)piVar2 + 9);
  FUN_0088f060(piVar2);
  puVar5 = (undefined1 *)(**(code **)(*param_1 + 0x54))();
  *(undefined1 *)(in_ECX + 0x34) = *puVar5;
  return;
}


// ==== FUN_008792e0 @ 0x008792e0 ====

void FUN_008792e0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uVar5;
  
  *(undefined1 *)(in_ECX + 0x32) = 0;
  *(undefined1 *)(in_ECX + 0x33) = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar3 = (**(code **)(*piVar2 + 0x1c))();
  if (*(int *)(iVar3 + 8) != 0) {
    iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar3 + 2) != '\0') {
      if (*(char *)(DAT_00b5ac04 + 0xcc) == '\0') {
        if (*(char *)(in_ECX + 0x34) != '\0') {
          *(char *)(in_ECX + 0x33) = *(char *)(in_ECX + 0x34);
        }
      }
      else {
        *(undefined1 *)(in_ECX + 0x33) = 1;
      }
    }
    iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar3 + 3) != '\0') {
      *(undefined1 *)(in_ECX + 0x32) = 1;
    }
    iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(byte *)(iVar3 + 9) < 3) {
      uVar5 = 5;
    }
    else {
      uVar5 = 6;
    }
    uVar5 = FUN_0085e3a0(uVar5);
    *(undefined4 *)(in_ECX + 0x44) = uVar5;
  }
  iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (*(char *)(iVar3 + 9) == '\0') {
    if (*(char *)(in_ECX + 0x33) != '\0') {
      iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
      if (*(char *)(iVar3 + 3) == '\0') {
        uVar5 = (**(code **)(*DAT_00b5d98c + 0x10))();
        FUN_0085e340(0x55,uVar5);
        goto LAB_00879425;
      }
    }
    iVar3 = *(int *)(in_ECX + 0x44);
    iVar1 = *(int *)(iVar3 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar1 >> 2) < 0x56)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    uVar5 = *(undefined4 *)(iVar1 + 0x154);
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(*DAT_00b5af70 + 4))(0);
    iVar3 = *(int *)(in_ECX + 0x44);
    iVar1 = *(int *)(iVar3 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar1 >> 2) < 0x56)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    uVar5 = *(undefined4 *)(iVar1 + 0x154);
  }
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0xd0))(*(int **)(iVar3 + 0x1c),uVar5,uVar4);
LAB_00879425:
  if (*(char *)(in_ECX + 0x33) != '\0') {
    iVar3 = *(int *)(in_ECX + 0x44);
    iVar1 = *(int *)(iVar3 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar1 >> 2) < 0x53)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar3 + 0x1c) + 0x58))
              (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar1 + 0x148),1);
    if (*(char *)(in_ECX + 0x33) == '\x01') {
      uVar5 = (**(code **)(*DAT_00b5af70 + 4))(1);
    }
    else {
      uVar5 = (**(code **)(*DAT_00b5af70 + 4))(2);
    }
    iVar3 = *(int *)(in_ECX + 0x44);
    iVar1 = *(int *)(iVar3 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar1 >> 2) < 0x57)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar3 + 0x1c) + 0xd0))
              (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar1 + 0x158),uVar5);
    return;
  }
  iVar3 = *(int *)(in_ECX + 0x44);
  iVar1 = *(int *)(iVar3 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar1 >> 2) < 0x53)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0x58))
            (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar1 + 0x148),0);
  iVar3 = *(int *)(in_ECX + 0x44);
  iVar1 = *(int *)(iVar3 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar1 >> 2) < 0x57)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar3 + 0x1c) + 0xd0))
            (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar1 + 0x158),0);
  return;
}


// ==== FUN_00879520 @ 0x00879520 ====

void FUN_00879520(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puStack_ac;
  int *piStack_a8;
  undefined4 uStack_a4;
  undefined1 **ppuStack_a0;
  undefined4 uStack_9c;
  int *piStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined1 *puStack_8c;
  undefined4 uStack_88;
  int *piStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 *puStack_78;
  undefined4 uStack_74;
  int *piStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 auStack_4c [76];
  
  iVar4 = *(int *)(in_ECX + 0x44);
  iVar1 = *(int *)(iVar4 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x3f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_6c = *(undefined4 *)(iVar1 + 0xf8);
  piStack_70 = *(int **)(iVar4 + 0x1c);
  uStack_68 = *(int *)(DAT_00b5ac04 + 0x78) + 200;
  uStack_74 = 0x879569;
  (**(code **)(*piStack_70 + 0x98))();
  uStack_74 = 0;
  puStack_78 = auStack_4c;
  uStack_7c = 0x87957b;
  uVar2 = (**(code **)(*DAT_00b5af70 + 0x20))();
  iVar4 = *(int *)(in_ECX + 0x44);
  iVar1 = *(int *)(iVar4 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x41)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_80 = *(undefined4 *)(iVar1 + 0x100);
  piStack_84 = *(int **)(iVar4 + 0x1c);
  uStack_88 = 0x8795ae;
  uStack_7c = uVar2;
  (**(code **)(*piStack_84 + 0x98))();
  puStack_8c = auStack_4c + -0x14;
  if (*(char *)(in_ECX + 0x33) == '\x01') {
    uStack_88 = 1;
  }
  else {
    uStack_88 = 2;
  }
  uStack_90 = 0x8795ca;
  uVar2 = (**(code **)(*DAT_00b5af70 + 0x20))();
  iVar4 = *(int *)(in_ECX + 0x44);
  iVar1 = *(int *)(iVar4 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x42)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_94 = *(undefined4 *)(iVar1 + 0x104);
  piStack_98 = *(int **)(iVar4 + 0x1c);
  uStack_9c = 0x8795fd;
  uStack_90 = uVar2;
  (**(code **)(*piStack_98 + 0x98))();
  puStack_8c = *(undefined1 **)(DAT_00b5ac04 + 0x9c);
  uStack_88 = *(undefined4 *)(DAT_00b5ac04 + 0xa0);
  iVar4 = *(int *)(in_ECX + 0x44);
  iVar1 = *(int *)(iVar4 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x49)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_a4 = *(undefined4 *)(iVar1 + 0x120);
  piStack_a8 = *(int **)(iVar4 + 0x1c);
  uStack_9c = 2;
  ppuStack_a0 = &puStack_8c;
  puStack_ac = (undefined4 *)0x87964f;
  (**(code **)(*piStack_a8 + 0x80))();
  puStack_ac = &uStack_90;
  uVar2 = FUN_00862b50();
  iVar4 = *(int *)(in_ECX + 0x44);
  iVar1 = *(int *)(iVar4 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x4a)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  puStack_ac = (undefined4 *)0x3;
  (**(code **)(**(int **)(iVar4 + 0x1c) + 0x80))
            (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar1 + 0x124),uVar2);
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar4 = (**(code **)(*piVar3 + 0x1c))();
  if (*(int *)(iVar4 + 8) != 0) {
    if (*(char *)(in_ECX + 0x32) != '\0') {
      iVar4 = *(int *)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
      puStack_ac = *(undefined4 **)(iVar4 + 0xc);
      piStack_a8 = *(int **)(iVar4 + 0x10);
      uStack_a4 = *(undefined4 *)(iVar4 + 0x14);
      thunk_FUN_0079e1ba(&ppuStack_a0,&puStack_ac);
      iVar4 = *(int *)(in_ECX + 0x44);
      iVar1 = *(int *)(iVar4 + 0x28);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x51)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x80))
                (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar1 + 0x140),&piStack_a8,3);
      iVar4 = *(int *)(in_ECX + 0x44);
      iVar1 = *(int *)(iVar4 + 0x28);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x50)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x78))
                (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar1 + 0x13c),0x41200000);
    }
    iVar4 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (2 < *(byte *)(iVar4 + 9)) {
      uVar2 = (**(code **)(*DAT_00b5af70 + 0x28))(&uStack_94,0);
      iVar4 = *(int *)(in_ECX + 0x44);
      iVar1 = *(int *)(iVar4 + 0x28);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x40)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x98))
                (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar1 + 0xfc),uVar2);
      iVar4 = *(int *)(in_ECX + 0x44);
      iVar1 = *(int *)(iVar4 + 0x28);
      if ((iVar1 == 0) || ((uint)(*(int *)(iVar4 + 0x2c) - iVar1 >> 2) < 0x54)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar4 + 0x1c) + 0x78))
                (*(int **)(iVar4 + 0x1c),*(undefined4 *)(iVar1 + 0x14c),0x3b800000);
    }
  }
  return;
}


// ==== FUN_008798c0 @ 0x008798c0 ====

void FUN_008798c0(undefined4 param_1,char param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  char *pcVar5;
  
  iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (2 < *(byte *)(iVar3 + 9)) {
    fVar4 = (float10)FUN_0087a480();
    iVar3 = *(int *)(in_ECX + 0x44);
    iVar1 = *(int *)(iVar3 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(iVar3 + 0x2c) - iVar1 >> 2) < 0x52)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    (**(code **)(**(int **)(iVar3 + 0x1c) + 0x78))
              (*(int **)(iVar3 + 0x1c),*(undefined4 *)(iVar1 + 0x144),(float)fVar4);
  }
  if (*(char *)(in_ECX + 0x33) == '\0') {
    iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar3 + 9) == '\0') {
      piVar2 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
      (**(code **)(*piVar2 + 0xf0))(piVar2,s_MapLightNoShadow_00a139ac);
      goto LAB_00879a17;
    }
    if ((*(char *)(in_ECX + 0x32) != '\0') && (param_2 != '\0')) {
      piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
      (**(code **)(*piVar2 + 0xe4))(piVar2,0x1d,1);
      piVar2 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
                    /* WARNING: Could not recover jumptable at 0x00879974. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar2 + 0xf0))(piVar2,s_MapBumpLight_00a13990);
      return;
    }
    pcVar5 = s_MapLight_00a139a0;
  }
  else {
    iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar3 + 9) != '\0') {
      if ((*(char *)(in_ECX + 0x32) != '\0') && (param_2 != '\0')) {
        piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
        (**(code **)(*piVar2 + 0xe4))(piVar2,0x1d,1);
        piVar2 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
                    /* WARNING: Could not recover jumptable at 0x008799e7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*piVar2 + 0xf0))(piVar2,s_MapBumpLightCover_00a139c0);
        return;
      }
      piVar2 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
      (**(code **)(*piVar2 + 0xf0))(piVar2,s_MapLightCover_00a139d4);
      goto LAB_00879a17;
    }
    pcVar5 = s_MapLightNoShadowCover_00a139e4;
  }
  piVar2 = *(int **)(*(int *)(in_ECX + 0x44) + 0x1c);
  (**(code **)(*piVar2 + 0xf0))(piVar2,pcVar5);
LAB_00879a17:
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x1d,0);
  return;
}


// ==== FUN_00879a40 @ 0x00879a40 ====

void FUN_00879a40(char param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int in_ECX;
  undefined4 unaff_EBX;
  int iVar8;
  int *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  void *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)(in_ECX + 0x30) != '\0') {
    local_34 = *(undefined4 *)(param_2 + 0x6c);
    local_38 = *(undefined4 *)(param_2 + 100);
    local_30 = *(void **)(param_2 + 0x58);
    local_2c = *(undefined4 *)(param_2 + 0x5c);
    local_3c = *(undefined4 *)(param_2 + 0x60);
    local_24 = *(undefined4 *)(param_2 + 100);
    local_20 = *(undefined4 *)(param_2 + 0x68);
    local_1c = *(undefined4 *)(param_2 + 0x6c);
    local_40 = *(int **)(param_2 + 0x58);
    local_10 = *(undefined4 *)(param_2 + 0x60);
    local_14 = *(undefined4 *)(param_2 + 0x5c);
    local_8 = *(undefined4 *)(param_2 + 0x68);
    local_c = *(undefined4 *)(param_2 + 100);
    local_4 = *(undefined4 *)(param_2 + 0x6c);
    local_28 = local_3c;
    local_18 = local_40;
    local_40 = (int *)FUN_0087ab40(*(undefined4 *)(in_ECX + 0x44),&local_40,&local_38);
    piVar5 = (int *)FUN_00850960();
    (**(code **)(*piVar5 + 8))(&local_30,param_2);
    local_40 = *(int **)(*(int *)(param_2 + 0xc4) + 0x30);
    piVar5 = (int *)*local_40;
    if (piVar5 != local_40) {
      iVar8 = 0;
      do {
        iVar2 = *(int *)(in_ECX + 0x44);
        uVar6 = 0;
        if (piVar5[3] != 0) {
          piVar7 = (int *)FUN_004af750();
          uVar6 = (**(code **)(*piVar7 + 4))();
        }
        iVar3 = *(int *)(iVar2 + 0x28);
        if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0x55)) {
LAB_00879cd7:
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))
                  (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x150),uVar6);
        uVar6 = 0;
        if (param_1 != '\0') {
          if (*(char *)(piVar5[4] + 0x4c) == '\0') {
            uVar6 = 1;
            FUN_0085e340(0x57,piVar5[4]);
          }
          else {
            iVar2 = *(int *)(in_ECX + 0x44);
            iVar3 = *(int *)(iVar2 + 0x28);
            if ((iVar3 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar3 >> 2) < 0x58))
            goto LAB_00879cd7;
            (**(code **)(**(int **)(iVar2 + 0x1c) + 0xd0))
                      (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar3 + 0x15c),0);
          }
        }
        FUN_008798c0(unaff_EBX,uVar6);
        FUN_00879010(piVar5 + 5,local_38,*(undefined4 *)(iVar8 + (int)local_30));
        iVar8 = iVar8 + 4;
        if (*(char *)((int)piVar5 + 0x2d) == '\0') {
          piVar7 = (int *)piVar5[2];
          if (*(char *)((int)piVar7 + 0x2d) == '\0') {
            cVar1 = *(char *)(*piVar7 + 0x2d);
            piVar5 = piVar7;
            piVar7 = (int *)*piVar7;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar7 + 0x2d);
              piVar5 = piVar7;
              piVar7 = (int *)*piVar7;
            }
          }
          else {
            cVar1 = *(char *)(piVar5[1] + 0x2d);
            piVar4 = (int *)piVar5[1];
            piVar7 = piVar5;
            while ((piVar5 = piVar4, cVar1 == '\0' && (piVar7 == (int *)piVar5[2]))) {
              cVar1 = *(char *)(piVar5[1] + 0x2d);
              piVar4 = (int *)piVar5[1];
              piVar7 = piVar5;
            }
          }
        }
      } while (piVar5 != local_40);
    }
    if (local_30 != (void *)0x0) {
      _free(local_30);
      return;
    }
  }
  return;
}


// ==== FUN_00879ce0 @ 0x00879ce0 ====

void FUN_00879ce0(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  char cVar6;
  int *piVar7;
  char *pcVar8;
  undefined4 uVar9;
  int in_ECX;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined1 auStack_60 [4];
  int *piStack_5c;
  int *piStack_58;
  undefined4 uStack_54;
  undefined1 auStack_50 [8];
  undefined1 local_48 [4];
  void *pvStack_44;
  undefined1 auStack_40 [4];
  void *pvStack_3c;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  
  if (((*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x78) != '\0') && (*(int *)(in_ECX + 0x24) != 0))
     && (*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 2 != 0)) {
    FUN_008792e0();
    FUN_00862cc0(local_48);
    piVar7 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar7 + 0x15c))(piVar7,*(undefined4 *)(*(int *)(in_ECX + 0x44) + 0x20));
    piVar7 = (int *)FUN_00850960();
    (**(code **)(*piVar7 + 4))();
    if (*(char *)(in_ECX + 0x31) != '\0') {
      piVar7 = (int *)FUN_00850960();
      (**(code **)(*piVar7 + 0xc))();
    }
    FUN_00879520();
    piStack_5c = (int *)0x0;
    piStack_58 = (int *)0x0;
    uStack_54 = 0;
    FUN_004ce0f0(auStack_60);
    iVar1 = *(int *)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
    fVar2 = *(float *)(iVar1 + 0xc);
    fVar3 = *(float *)(iVar1 + 0x10);
    fVar4 = *(float *)(iVar1 + 0x14);
    FUN_00858f20();
    piVar5 = piStack_58;
    for (piVar7 = piStack_5c; piVar7 != piVar5; piVar7 = piVar7 + 1) {
      iVar1 = *piVar7;
      fVar12 = *(float *)(iVar1 + 0xb8) - fVar2;
      fVar11 = *(float *)(iVar1 + 0xbc) - fVar3;
      fVar10 = *(float *)(iVar1 + 0xc0) - fVar4;
      if (DAT_009b0300 <= SQRT(fVar12 * fVar12 + fVar11 * fVar11 + fVar10 * fVar10) - DAT_0099de80)
      {
        uVar9 = 0;
      }
      else {
        uVar9 = CONCAT31((int3)((uint)*(float *)(iVar1 + 0xbc) >> 8),*(undefined1 *)(in_ECX + 0x32))
        ;
      }
      FUN_00879a40(auStack_50,iVar1,uVar9);
    }
    cVar6 = FUN_0088e2b0();
    piVar5 = piStack_58;
    piVar7 = piStack_5c;
    if (cVar6 != '\0') {
      for (; piVar7 != piVar5; piVar7 = piVar7 + 1) {
        FUN_0088eae0(*piVar7);
      }
    }
    FUN_008590c0();
    pcVar8 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
    if (*pcVar8 != '\0') {
      pvStack_28 = (void *)0xf;
      uStack_2c = 0;
      pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
      FUN_00401740(s__R_Geometry_triangle_count_00a1395c,0x1a);
      FUN_00401740(&DAT_00a13958,2);
      uVar9 = FUN_00404230(auStack_24);
      (**(code **)(*DAT_00b5a688 + 8))(auStack_40,uVar9);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return;
      }
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return;
      }
      uStack_30 = 0xf;
      uStack_34 = 0;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
      FUN_00401740(s__R_GeoNode_Count_00a1397c,0x10);
      FUN_00401740(&DAT_00a13978,2);
      uVar9 = FUN_00404230(&uStack_2c);
      (**(code **)(*DAT_00b5a688 + 8))(local_48,uVar9);
      if (0xf < uStack_c) {
        _free(pvStack_20);
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      if (0xf < pvStack_28) {
        _free(pvStack_3c);
        return;
      }
    }
    if (piStack_5c != (int *)0x0) {
      _free(piStack_5c);
      return;
    }
  }
  return;
}


// ==== FUN_0087a040 @ 0x0087a040 ====

void FUN_0087a040(byte param_1)

{
  void *in_ECX;
  
  FUN_00879120();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087a060 @ 0x0087a060 ====

void FUN_0087a060(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = DAT_0099d080;
  in_ECX[1] = uVar1;
  in_ECX[2] = uVar1;
  in_ECX[3] = DAT_009c3038;
  return;
}


// ==== FUN_0087a090 @ 0x0087a090 ====

void FUN_0087a090(void)

{
  return;
}


// ==== FUN_0087a0c0 @ 0x0087a0c0 ====

void FUN_0087a0c0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x44) = *param_1;
  *(undefined4 *)(in_ECX + 0x48) = param_1[1];
  *(undefined4 *)(in_ECX + 0x4c) = param_1[2];
  *(undefined4 *)(in_ECX + 0x50) = param_1[3];
  return;
}


// ==== FUN_0087a170 @ 0x0087a170 ====

void FUN_0087a170(float param_1)

{
  float *in_ECX;
  
  in_ECX[3] = param_1;
  in_ECX[4] = *in_ECX * param_1;
  in_ECX[5] = in_ECX[1] * param_1;
  in_ECX[6] = in_ECX[2] * param_1;
  return;
}


// ==== FUN_0087a1d0 @ 0x0087a1d0 ====

void FUN_0087a1d0(float *param_1)

{
  float fVar1;
  int in_ECX;
  
  fVar1 = *(float *)(in_ECX + 0x18);
  *(float *)(in_ECX + 0xc) = *param_1;
  *(float *)(in_ECX + 0x10) = param_1[1];
  *(float *)(in_ECX + 0x14) = param_1[2];
  *(float *)(in_ECX + 0x1c) = *(float *)(in_ECX + 0xc) * fVar1;
  *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 0x10) * fVar1;
  *(float *)(in_ECX + 0x24) = *(float *)(in_ECX + 0x14) * fVar1;
  return;
}


// ==== FUN_0087a240 @ 0x0087a240 ====

void FUN_0087a240(float param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 0x18) = param_1;
  *(float *)(in_ECX + 0x1c) = *(float *)(in_ECX + 0xc) * param_1;
  *(float *)(in_ECX + 0x20) = *(float *)(in_ECX + 0x10) * param_1;
  *(float *)(in_ECX + 0x24) = *(float *)(in_ECX + 0x14) * param_1;
  return;
}


// ==== FUN_0087a2f0 @ 0x0087a2f0 ====

void FUN_0087a2f0(float *param_1)

{
  float fVar1;
  float *in_ECX;
  
  fVar1 = in_ECX[3];
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[4] = *in_ECX * fVar1;
  in_ECX[5] = fVar1 * in_ECX[1];
  in_ECX[6] = fVar1 * in_ECX[2];
  fVar1 = param_1[3];
  in_ECX[3] = fVar1;
  in_ECX[4] = *in_ECX * fVar1;
  in_ECX[5] = fVar1 * in_ECX[1];
  in_ECX[6] = fVar1 * in_ECX[2];
  return;
}


// ==== FUN_0087a3a0 @ 0x0087a3a0 ====

void FUN_0087a3a0(float *param_1)

{
  float fVar1;
  int in_ECX;
  
  fVar1 = *(float *)(in_ECX + 0x34);
  *(float *)(in_ECX + 0x28) = *param_1;
  *(float *)(in_ECX + 0x2c) = param_1[1];
  *(float *)(in_ECX + 0x30) = param_1[2];
  *(float *)(in_ECX + 0x38) = *(float *)(in_ECX + 0x28) * fVar1;
  *(float *)(in_ECX + 0x3c) = *(float *)(in_ECX + 0x2c) * fVar1;
  *(float *)(in_ECX + 0x40) = *(float *)(in_ECX + 0x30) * fVar1;
  *(float *)(in_ECX + 0x1c) = param_1[3];
  *(float *)(in_ECX + 0x20) = param_1[4];
  *(float *)(in_ECX + 0x24) = param_1[5];
  fVar1 = param_1[6];
  *(float *)(in_ECX + 0x34) = fVar1;
  *(float *)(in_ECX + 0x38) = *(float *)(in_ECX + 0x28) * fVar1;
  *(float *)(in_ECX + 0x3c) = *(float *)(in_ECX + 0x2c) * fVar1;
  *(float *)(in_ECX + 0x40) = *(float *)(in_ECX + 0x30) * fVar1;
  return;
}


// ==== FUN_0087a480 @ 0x0087a480 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0087a480(void)

{
  int in_ECX;
  float fVar1;
  float fVar2;
  float local_10;
  
  fVar1 = (*(float *)(in_ECX + 0x24) + *(float *)(in_ECX + 0x1c)) * 0.0 + *(float *)(in_ECX + 0x20);
  fVar2 = 0.0;
  if (0.0 <= fVar1) {
    fVar2 = fVar1;
  }
  local_10 = DAT_0099d080 - *(float *)(in_ECX + 0x34);
  if (local_10 < DAT_009c16c0) {
    local_10 = DAT_009c16c0;
  }
  local_10 = (DAT_0099d080 - fVar2) * DAT_009b2dbc + local_10;
  if (_DAT_00a13a80 < local_10) {
    local_10 = DAT_009b2dbc;
  }
  return (float10)local_10;
}


// ==== FUN_0087a510 @ 0x0087a510 ====

void FUN_0087a510(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  float fVar4;
  int in_ECX;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar4 = DAT_0099d080;
  fVar5 = *(float *)(in_ECX + 0x10);
  fVar6 = *(float *)(in_ECX + 0x14);
  fVar7 = *(float *)(in_ECX + 0x18);
  for (puVar3 = (undefined4 *)**(undefined4 **)(param_2 + 4);
      puVar3 != *(undefined4 **)(param_2 + 4); puVar3 = (undefined4 *)*puVar3) {
    fVar1 = (float)puVar3[8];
    fVar2 = (float)puVar3[0xb];
    fVar5 = (float)puVar3[5] * fVar1 * fVar2 * DAT_0099d0b4 + fVar5;
    fVar6 = (float)puVar3[6] * fVar1 * fVar2 * DAT_0099d0b4 + fVar6;
    fVar7 = (float)puVar3[7] * fVar1 * fVar2 * DAT_0099d0b4 + fVar7;
  }
  *param_1 = fVar5;
  param_1[1] = fVar6;
  param_1[2] = fVar7;
  param_1[3] = fVar4;
  return;
}


// ==== FUN_0087a5d0 @ 0x0087a5d0 ====

void FUN_0087a5d0(undefined4 *param_1,int param_2)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int *_Memory;
  int *piVar6;
  int *piVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int local_28 [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  fVar3 = DAT_0099d0dc;
  fVar2 = DAT_0099d080;
  if (*(int *)(param_2 + 8) == 0) {
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    fVar2 = DAT_0099d080;
    param_1[5] = 0;
    param_1[7] = fVar2;
    uVar4 = DAT_009a09bc;
    param_1[6] = 0;
    *param_1 = &PTR_FUN_00a13a7c;
    param_1[8] = uVar4;
    return;
  }
  piVar1 = *(int **)(param_2 + 4);
  _Memory = (int *)0x0;
  fVar10 = DAT_0099d0dc;
  for (piVar6 = (int *)*piVar1; piVar6 != piVar1; piVar6 = (int *)*piVar6) {
    fVar9 = (fVar3 / (float)piVar6[9]) * (float)piVar6[10] + fVar2;
    fVar8 = ((float)piVar6[7] + (float)piVar6[6] + (float)piVar6[5]) * (float)piVar6[8] * fVar9;
    piVar6[0xb] = (int)fVar9;
    if (fVar10 < fVar8) {
      _Memory = piVar6;
      fVar10 = fVar8;
    }
  }
  piVar1 = *(int **)(param_2 + 4);
  piVar6 = _Memory + 2;
  piVar7 = local_28;
  for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar7 = piVar7 + 1;
  }
  if (_Memory == piVar1) {
    param_1[1] = local_28[0];
    param_1[2] = local_28[1];
    param_1[3] = local_28[2];
    param_1[4] = local_28[3];
    param_1[5] = local_18;
    param_1[7] = local_10;
    param_1[6] = local_14;
    *param_1 = &PTR_FUN_00a13a7c;
    param_1[8] = local_c;
    return;
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return;
}


// ==== FUN_0087a760 @ 0x0087a760 ====

void FUN_0087a760(int param_1)

{
  int iVar1;
  int in_ECX;
  int **ppiVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piStack_2c;
  int *piStack_28;
  int *piStack_24;
  undefined4 uStack_20;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (*(char *)(DAT_00b5ac04 + 0xce) == '\0') {
    if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 5)) {
                    /* WARNING: Subroutine does not return */
      uStack_20 = 0x87a882;
      FUN_0085b340();
    }
    piStack_28 = *(int **)(iVar1 + 0x10);
    piStack_2c = *(int **)(param_1 + 0x1c);
    uStack_20 = 3;
    piStack_24 = (int *)(in_ECX + 0x10);
    (**(code **)(*piStack_2c + 0x80))();
    iVar1 = *(int *)(param_1 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 8)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    uVar4 = 3;
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
              (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x1c),local_8,3);
    iVar1 = *(int *)(param_1 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 9)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    ppiVar2 = (int **)(in_ECX + 0x38);
  }
  else {
    local_c = DAT_0099de84;
    local_8 = DAT_0099de84;
    local_4 = DAT_0099de84;
    if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 5)) {
                    /* WARNING: Subroutine does not return */
      uStack_20 = 0x87a7b7;
      FUN_0085b340();
    }
    piStack_28 = *(int **)(iVar1 + 0x10);
    piStack_2c = *(int **)(param_1 + 0x1c);
    uStack_20 = 3;
    piStack_24 = &local_c;
    (**(code **)(*piStack_2c + 0x80))();
    iVar1 = *(int *)(param_1 + 0x28);
    if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 8)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    uVar4 = 3;
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
              (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x1c),
               (int)register0x00000010 + -0x1c,3);
    iVar1 = *(int *)(param_1 + 0x28);
    piStack_2c = DAT_0099d080;
    piStack_28 = DAT_0099d080;
    piStack_24 = DAT_0099d080;
    if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 9)) {
                    /* WARNING: Subroutine does not return */
      FUN_0085b340();
    }
    ppiVar2 = &piStack_2c;
  }
  puVar3 = (undefined4 *)(param_1 + 0x1c);
  (**(code **)(*(int *)*puVar3 + 0x80))((int *)*puVar3,*(undefined4 *)(iVar1 + 0x20),ppiVar2,3);
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 10)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(*(int *)*puVar3 + 0x80))((int *)*puVar3,*(undefined4 *)(iVar1 + 0x24),piStack_24,3);
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0xb)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(*(int *)*puVar3 + 0x78))((int *)*puVar3,*(undefined4 *)(iVar1 + 0x28),uVar4);
  return;
}


// ==== FUN_0087a970 @ 0x0087a970 ====

void FUN_0087a970(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_a [10];
  
  iVar2 = FUN_0085e3a0();
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x29)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x80))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0xa0),in_ECX + 0x38,3);
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x2a)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x80))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0xa4),auStack_a + -0x12,3);
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x2d)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x80))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0xb0),in_ECX + 0x10,3);
  return;
}


// ==== FUN_0087aa50 @ 0x0087aa50 ====

void FUN_0087aa50(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_16 [10];
  undefined4 uStack_c;
  
  iVar2 = FUN_0085e3a0();
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x6b)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x80))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x1a8),in_ECX + 0x10,3);
  thunk_FUN_0079e6b3(auStack_16 + -6,auStack_16 + -0x12,uStack_c);
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x6c)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x80))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x1ac),auStack_16 + -0x12,3);
  iVar1 = *(int *)(iVar2 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(iVar2 + 0x2c) - iVar1 >> 2) < 0x6d)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(iVar2 + 0x1c) + 0x80))
            (*(int **)(iVar2 + 0x1c),*(undefined4 *)(iVar1 + 0x1b0),in_ECX + 0x38,3);
  return;
}


// ==== FUN_0087ab40 @ 0x0087ab40 ====

undefined4 FUN_0087ab40(int param_1)

{
  int iVar1;
  int in_ECX;
  int *piStack_54;
  undefined4 uStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  int *piStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int *piStack_38;
  undefined4 uStack_34;
  undefined4 *puStack_30;
  undefined4 uStack_2c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *(undefined4 *)(in_ECX + 0x44);
  local_14 = *(undefined4 *)(in_ECX + 0x48);
  local_10 = *(undefined4 *)(in_ECX + 0x4c);
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x47)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_34 = *(undefined4 *)(iVar1 + 0x118);
  piStack_38 = *(int **)(param_1 + 0x1c);
  uStack_2c = 3;
  puStack_30 = &local_18;
  uStack_3c = 0x87ab9c;
  (**(code **)(*piStack_38 + 0x80))();
  iVar1 = *(int *)(param_1 + 0x28);
  uStack_c = *(undefined4 *)(in_ECX + 0x50);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x48)) {
                    /* WARNING: Subroutine does not return */
    uStack_3c = 0x87abc2;
    FUN_0085b340();
  }
  uStack_40 = *(undefined4 *)(iVar1 + 0x11c);
  piStack_44 = *(int **)(param_1 + 0x1c);
  uStack_48 = 0x87abd7;
  uStack_3c = uStack_c;
  (**(code **)(*piStack_44 + 0x78))();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x44)) {
                    /* WARNING: Subroutine does not return */
    uStack_48 = 0x87abf2;
    FUN_0085b340();
  }
  uStack_50 = *(undefined4 *)(iVar1 + 0x10c);
  piStack_54 = *(int **)(param_1 + 0x1c);
  uStack_48 = 3;
  iStack_4c = in_ECX + 0x10;
  (**(code **)(*piStack_54 + 0x80))();
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x46)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x114),in_ECX + 0x38,3);
  piStack_54 = *(int **)(in_ECX + 0x1c);
  uStack_50 = *(undefined4 *)(in_ECX + 0x20);
  iStack_4c = *(undefined4 *)(in_ECX + 0x24);
  thunk_FUN_0079e1ba(&uStack_48,&piStack_54);
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x45)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x110),&uStack_50,3);
  return 0;
}


// ==== FUN_0087ada0 @ 0x0087ada0 ====

void FUN_0087ada0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int in_ECX;
  undefined4 *puVar6;
  int local_48;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = param_3;
  iVar1 = *(int *)(in_ECX + 0x5c);
  local_48 = *(int *)(in_ECX + 0x58);
  if (local_48 != iVar1) {
    puVar6 = (undefined4 *)(local_48 + 4);
    do {
      param_3 = puVar6[7];
      local_2c = *puVar6;
      local_28 = puVar6[1];
      local_3c = puVar6[2];
      local_40 = *puVar6;
      local_34 = puVar6[1];
      local_30 = puVar6[2];
      local_38 = local_40;
      local_24 = local_3c;
      cVar4 = FUN_0040e9f0(param_1,param_2,&local_40,&param_3);
      if (cVar4 != '\0') {
        iVar2 = *(int *)(iVar3 + 4);
        local_4 = puVar6[7];
        local_20 = *puVar6;
        local_1c = puVar6[1];
        local_18 = puVar6[2];
        local_14 = puVar6[3];
        local_10 = puVar6[4];
        local_c = puVar6[5];
        local_8 = puVar6[6];
        iVar5 = FUN_0087b220(iVar2,*(undefined4 *)(iVar2 + 4),&local_20);
        FUN_0059c010(1);
        *(int *)(iVar2 + 4) = iVar5;
        **(int **)(iVar5 + 4) = iVar5;
      }
      local_48 = local_48 + 0x24;
      puVar6 = puVar6 + 9;
    } while (local_48 != iVar1);
  }
  return;
}


// ==== FUN_0087aed0 @ 0x0087aed0 ====

void FUN_0087aed0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined **local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_20 = *param_1;
  local_1c = param_1[1];
  local_18 = param_1[2];
  local_14 = *param_2;
  local_10 = param_2[1];
  local_c = param_2[2];
  local_8 = param_3;
  local_24 = &PTR_FUN_00a13a7c;
  local_4 = param_4;
  FUN_0087b7d0(&local_24);
  return;
}


// ==== FUN_0087af40 @ 0x0087af40 ====

void FUN_0087af40(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  puVar2 = in_ECX + 2;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_0087af70 @ 0x0087af70 ====

void FUN_0087af70(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  puVar2 = in_ECX + 2;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_0087afa0 @ 0x0087afa0 ====

int FUN_0087afa0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_2 + 0x10);
    puVar2 = (undefined4 *)(param_3 + 0x10);
    do {
      puVar2[-0xc] = puVar1[-0xc];
      puVar2[-0xb] = puVar1[-0xb];
      puVar2[-10] = puVar1[-10];
      puVar2[-9] = puVar1[-9];
      puVar2[-8] = puVar1[-8];
      puVar2[-7] = puVar1[-7];
      param_2 = param_2 + -0x24;
      puVar2[-6] = puVar1[-6];
      param_3 = param_3 + -0x24;
      puVar2[-5] = puVar1[-5];
      puVar1 = puVar1 + -9;
      puVar2 = puVar2 + -9;
    } while (param_2 != param_1);
  }
  return param_3;
}


// ==== FUN_0087b010 @ 0x0087b010 ====

void FUN_0087b010(undefined4 *param_1,int param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = &PTR_FUN_00a13a7c;
    param_1[1] = *(undefined4 *)(param_2 + 4);
    param_1[2] = *(undefined4 *)(param_2 + 8);
    param_1[3] = *(undefined4 *)(param_2 + 0xc);
    param_1[4] = *(undefined4 *)(param_2 + 0x10);
    param_1[5] = *(undefined4 *)(param_2 + 0x14);
    param_1[6] = *(undefined4 *)(param_2 + 0x18);
    param_1[7] = *(undefined4 *)(param_2 + 0x1c);
    param_1[8] = *(undefined4 *)(param_2 + 0x20);
  }
  return;
}


// ==== FUN_0087b060 @ 0x0087b060 ====

void FUN_0087b060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13a7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087b080 @ 0x0087b080 ====

void FUN_0087b080(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_1 + 0x10);
    do {
      puVar1[-3] = *(undefined4 *)(param_3 + 4);
      puVar1[-2] = *(undefined4 *)(param_3 + 8);
      puVar1[-1] = *(undefined4 *)(param_3 + 0xc);
      *puVar1 = *(undefined4 *)(param_3 + 0x10);
      puVar1[1] = *(undefined4 *)(param_3 + 0x14);
      puVar1[2] = *(undefined4 *)(param_3 + 0x18);
      puVar1[3] = *(undefined4 *)(param_3 + 0x1c);
      puVar1[4] = *(undefined4 *)(param_3 + 0x20);
      param_1 = param_1 + 0x24;
      puVar1 = puVar1 + 9;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0087b0e0 @ 0x0087b0e0 ====

void FUN_0087b0e0(undefined4 param_1,undefined4 param_2)

{
  FUN_0087b010(param_1,param_2);
  return;
}


// ==== FUN_0087b100 @ 0x0087b100 ====

int FUN_0087b100(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a5d0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_0087b0e0(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0087b16a @ 0x0087b16a ====

void Catch_0087b16a(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  for (puVar2 = *(undefined4 **)(unaff_EBP + -0x14); puVar2 != puVar1; puVar2 = puVar2 + 9) {
    (**(code **)*puVar2)(0);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0087b190 @ 0x0087b190 ====

void * FUN_0087b190(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a5e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0087af40(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0087b1fd @ 0x0087b1fd ====

void Catch_0087b1fd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0087b220 @ 0x0087b220 ====

void * FUN_0087b220(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a5f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0087af70(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0087b28d @ 0x0087b28d ====

void Catch_0087b28d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0087b2b0 @ 0x0087b2b0 ====

void FUN_0087b2b0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a600;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0087b0e0(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087b31a @ 0x0087b31a ====

void Catch_0087b31a(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  for (puVar2 = *(undefined4 **)(unaff_EBP + -0x14); puVar2 != puVar1; puVar2 = puVar2 + 9) {
    (**(code **)*puVar2)(0);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0087b340 @ 0x0087b340 ====

void FUN_0087b340(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0087b100(param_1,param_2,param_3);
  return;
}


// ==== FUN_0087b360 @ 0x0087b360 ====

int FUN_0087b360(int param_1,int param_2,undefined4 param_3)

{
  FUN_0087b2b0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_0087b420 @ 0x0087b420 ====

void FUN_0087b420(int param_1,uint param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  void *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a610;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x6c);
  local_60 = &PTR_FUN_00a13a7c;
  local_5c = *(undefined4 *)(param_3 + 4);
  local_58 = *(undefined4 *)(param_3 + 8);
  local_54 = *(undefined4 *)(param_3 + 0xc);
  local_50 = *(undefined4 *)(param_3 + 0x10);
  local_4c = *(undefined4 *)(param_3 + 0x14);
  local_48 = *(undefined4 *)(param_3 + 0x18);
  local_44 = *(undefined4 *)(param_3 + 0x1c);
  local_40 = *(undefined4 *)(param_3 + 0x20);
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x24;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x6c);
    if (0x71c71c7U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_24 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
    }
    if (local_24 < iVar2 + param_2) {
      if (0x71c71c7 - (local_24 >> 1) < local_24) {
        local_24 = 0;
      }
      else {
        local_24 = local_24 + (local_24 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
      }
      if (local_24 < iVar3 + param_2) {
        iVar3 = FUN_0066e7e0();
        local_24 = iVar3 + param_2;
      }
      local_24 = local_24 * 0x24;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_18 = local_1c;
      local_18 = (void *)FUN_0087b340(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_0087b360(local_18,param_2,&local_60);
      FUN_0087b340(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar3 = *(int *)(in_ECX + 4);
      if (iVar3 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
      }
      if (iVar3 == 0) {
        *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
        *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar2) * 0x24);
        *(void **)(in_ECX + 4) = local_1c;
        ExceptionList = local_10;
        return;
      }
      FUN_0084ad20(iVar3,*(undefined4 *)(in_ECX + 8));
      _free(*(void **)(in_ECX + 4));
      return;
    }
    local_2c = *(int *)(in_ECX + 8);
    if ((uint)((local_2c - param_1) / 0x24) < param_2) {
      local_28 = param_2 * 0x24;
      FUN_0087b100(param_1,local_2c,local_28 + param_1);
      local_8 = 2;
      FUN_0087b360(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,&local_60)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
      FUN_0087b080(param_1,*(int *)(in_ECX + 8) - local_28,&local_60);
      ExceptionList = local_10;
      return;
    }
    local_30 = local_2c + param_2 * -0x24;
    uVar4 = FUN_0087b100(local_30,local_2c,local_2c);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0087afa0(param_1,local_30,local_2c,local_3c);
    FUN_0087b080(param_1,param_2 * 0x24 + param_1,&local_60);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087b614 @ 0x0087b614 ====

void Catch_0087b614(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0084ad20(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@0087b6d9 @ 0x0087b6d9 ====

void Catch_0087b6d9(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_0084ad20(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0087b760 @ 0x0087b760 ====

void FUN_0087b760(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_0087b7a5;
    }
  }
  iVar1 = 0;
LAB_0087b7a5:
  FUN_0087b420(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_0087b7d0 @ 0x0087b7d0 ====

void FUN_0087b7d0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_0087b760(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0087b2b0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_0087b860 @ 0x0087b860 ====

void FUN_0087b860(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
  *(undefined1 *)(in_ECX + 0xd) = 0;
  return;
}


// ==== FUN_0087b890 @ 0x0087b890 ====

void FUN_0087b890(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xd) == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0087b89b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x10) + 0xc))();
  return;
}


// ==== FUN_0087b8a0 @ 0x0087b8a0 ====

void FUN_0087b8a0(void)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13ae4;
  in_ECX[1] = 0x200;
  in_ECX[2] = 0x200;
  *(undefined1 *)((int)in_ECX + 0xd) = 0;
  in_ECX[4] = 0;
  cVar1 = *(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xea);
  *(char *)(in_ECX + 3) = cVar1;
  if (cVar1 == '\0') {
    pvVar2 = operator_new(0x48);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_0088fa40(in_ECX);
      in_ECX[4] = uVar3;
      return;
    }
  }
  else {
    pvVar2 = operator_new(0x70);
    if (pvVar2 != (void *)0x0) {
      uVar3 = FUN_00890060(in_ECX);
      in_ECX[4] = uVar3;
      return;
    }
  }
  in_ECX[4] = 0;
  return;
}


// ==== FUN_0087b920 @ 0x0087b920 ====

void FUN_0087b920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13ae4;
  (**(code **)(*(int *)in_ECX[4] + 8))();
  *(undefined1 *)((int)in_ECX + 0xd) = 0;
  *in_ECX = &PTR_FUN_00a10a18;
  return;
}


// ==== FUN_0087b940 @ 0x0087b940 ====

undefined4 FUN_0087b940(undefined1 param_1,void *param_2)

{
  char cVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  uint unaff_retaddr;
  uint in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  void *pvStack_14;
  
  if (*(char *)(in_ECX + 0xd) != '\x01') {
    *(undefined4 *)(in_ECX + 4) = in_stack_00000020;
    *(undefined4 *)(in_ECX + 8) = in_stack_00000024;
    FUN_00401660(&param_1,0,0xffffffff);
    cVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
    if (cVar1 == '\0') {
      (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
      *(undefined1 *)(in_ECX + 0xd) = 0;
      if (unaff_retaddr < 0x10) {
        return 0;
      }
      _free(pvStack_14);
      return extraout_EAX;
    }
    *(undefined1 *)(in_ECX + 0xd) = 1;
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))(0x31e0);
  }
  if (in_stack_0000001c < 0x10) {
    return 1;
  }
  _free(param_2);
  return extraout_EAX_00;
}


// ==== FUN_0087b9e0 @ 0x0087b9e0 ====

void FUN_0087b9e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13ae4;
  (**(code **)(*(int *)in_ECX[4] + 8))();
  *(undefined1 *)((int)in_ECX + 0xd) = 0;
  *in_ECX = &PTR_FUN_00a10a18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087ba20 @ 0x0087ba20 ====

void FUN_0087ba20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  return;
}


// ==== FUN_0087ba50 @ 0x0087ba50 ====

void FUN_0087ba50(void)

{
  return;
}


// ==== FUN_0087ba60 @ 0x0087ba60 ====

void FUN_0087ba60(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_0087ba80 @ 0x0087ba80 ====

void FUN_0087ba80(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x1c);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x20);
  return;
}


// ==== FUN_0087baa0 @ 0x0087baa0 ====

int FUN_0087baa0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0087baf0 @ 0x0087baf0 ====

void FUN_0087baf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13b38;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087bb10 @ 0x0087bb10 ====

undefined4 FUN_0087bb10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0087bb20 @ 0x0087bb20 ====

undefined4 FUN_0087bb20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0087bb30 @ 0x0087bb30 ====

void FUN_0087bb30(void)

{
  if (DAT_00b5ae34 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae34)(1);
  }
  return;
}


// ==== FUN_0087bb70 @ 0x0087bb70 ====

void FUN_0087bb70(int *param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 uStack_58;
  uint uStack_44;
  undefined1 auStack_40 [4];
  void *pvStack_3c;
  uint uStack_28;
  _MEMORYSTATUS _Stack_24;
  
  *in_ECX = &PTR_FUN_00a13b48;
  uVar1 = (**(code **)(*param_1 + 0x10))(param_1);
  in_ECX[1] = uVar1 >> 0x14;
  GlobalMemoryStatus(&_Stack_24);
  in_ECX[2] = _Stack_24.dwTotalPhys >> 0x14;
  FUN_00401740(s_Total_Video_Memory___u_MB_00a13afc,0x19);
  FUN_00404230(auStack_40);
  FUN_00796d20(auStack_40);
  FUN_00401740(s_Total_System_Memory___u_MB_00a13b18,0x1a);
  FUN_00404230(auStack_40 + -0x1c);
  FUN_00796d20(auStack_40 + -0x1c);
  if (in_ECX + 1 == (uint *)0x0) {
    DAT_00b5ae34 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae34 = in_ECX;
  }
  if (0xf < uStack_44) {
    _free(uStack_58);
    return;
  }
  if (uStack_28 < 0x10) {
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_0087bc80 @ 0x0087bc80 ====

void FUN_0087bc80(undefined4 param_1)

{
  void *pvVar1;
  
  if (DAT_00b5ae34 == 0) {
    pvVar1 = operator_new(0xc);
    if (pvVar1 != (void *)0x0) {
      FUN_0087bb70(param_1);
    }
  }
  return;
}


// ==== FUN_0087bcb0 @ 0x0087bcb0 ====

void FUN_0087bcb0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae34 = 0;
  *in_ECX = &PTR_FUN_00a13b38;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087bce0 @ 0x0087bce0 ====

void FUN_0087bce0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13c94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087bd00 @ 0x0087bd00 ====

int FUN_0087bd00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x58) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58)) / 0xc;
}


// ==== FUN_0087bd20 @ 0x0087bd20 ====

void FUN_0087bd20(void)

{
  if (DAT_00b5d980 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d980)(1);
  }
  return;
}


// ==== FUN_0087bd40 @ 0x0087bd40 ====

void FUN_0087bd40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13cb0;
  DAT_00b5d980 = 0;
  if ((void *)in_ECX[0x16] != (void *)0x0) {
    _free((void *)in_ECX[0x16]);
    return;
  }
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  if (0xf < (uint)in_ECX[0x11]) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_00a13c94;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0087bdc0 @ 0x0087bdc0 ====

void FUN_0087bdc0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int in_ECX;
  char *pcVar5;
  float10 fVar6;
  
  uVar2 = (**(code **)(*DAT_00b5a6bc + 8))();
  if (*(uint *)(param_1 + 0x54) < 0x10) {
    iVar3 = param_1 + 0x40;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x40);
  }
  FUN_007bb860(uVar2,iVar3,*(undefined4 *)(param_1 + 0x50),s_font_header_00a13bb8);
  FUN_007bca30(uVar2,0,0,0);
  FUN_007bc470(uVar2,s_han_font_name_00a13bc4);
  FUN_007bc620(uVar2,0xffffd8ef);
  pcVar4 = (char *)FUN_007bc230(uVar2,0xffffffff);
  pcVar5 = pcVar4;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar5 - (int)(pcVar4 + 1));
  FUN_007bbdf0(uVar2,0xfffffffe);
  FUN_007bc470(uVar2,s_han_font_size_00a13bd4);
  FUN_007bc620(uVar2,0xffffd8ef);
  fVar6 = (float10)FUN_007bc1a0(uVar2,0xffffffff);
  *(int *)(in_ECX + 0x20) = (int)ROUND(fVar6);
  FUN_007bbdf0(uVar2,0xfffffffe);
  FUN_007bc470(uVar2,s_han_font_dpi_00a13be4);
  FUN_007bc620(uVar2,0xffffd8ef);
  fVar6 = (float10)FUN_007bc1a0(uVar2,0xffffffff);
  *(int *)(in_ECX + 0x24) = (int)ROUND(fVar6);
  FUN_007bbdf0(uVar2,0xfffffffe);
  FUN_007bc470(uVar2,s_font_advance_00a13bf4);
  FUN_007bc620(uVar2,0xffffd8ef);
  fVar6 = (float10)FUN_007bc1a0(uVar2,0xffffffff);
  *(int *)(in_ECX + 0x28) = (int)ROUND(fVar6);
  FUN_007bbdf0(uVar2,0xfffffffe);
  return;
}


// ==== FUN_0087bf20 @ 0x0087bf20 ====

void FUN_0087bf20(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int in_ECX;
  char *pcVar5;
  float10 fVar6;
  
  uVar2 = (**(code **)(*DAT_00b5a6bc + 8))();
  if (*(uint *)(param_1 + 0x54) < 0x10) {
    iVar3 = param_1 + 0x40;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x40);
  }
  FUN_007bb860(uVar2,iVar3,*(undefined4 *)(param_1 + 0x50),s_font_header_00a13c04);
  FUN_007bca30(uVar2,0,0,0);
  FUN_007bc470(uVar2,s_other_font_name_00a13c10);
  FUN_007bc620(uVar2,0xffffd8ef);
  pcVar4 = (char *)FUN_007bc230(uVar2,0xffffffff);
  pcVar5 = pcVar4;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar5 - (int)(pcVar4 + 1));
  FUN_007bbdf0(uVar2,0xfffffffe);
  FUN_007bc470(uVar2,s_other_font_size_00a13c20);
  FUN_007bc620(uVar2,0xffffd8ef);
  fVar6 = (float10)FUN_007bc1a0(uVar2,0xffffffff);
  *(int *)(in_ECX + 0x48) = (int)ROUND(fVar6);
  FUN_007bbdf0(uVar2,0xfffffffe);
  FUN_007bc470(uVar2,s_other_font_dpi_00a13c30);
  FUN_007bc620(uVar2,0xffffd8ef);
  fVar6 = (float10)FUN_007bc1a0(uVar2,0xffffffff);
  *(int *)(in_ECX + 0x4c) = (int)ROUND(fVar6);
  FUN_007bbdf0(uVar2,0xfffffffe);
  FUN_007bc470(uVar2,s_font_advance_00a13c40);
  FUN_007bc620(uVar2,0xffffd8ef);
  fVar6 = (float10)FUN_007bc1a0(uVar2,0xffffffff);
  *(int *)(in_ECX + 0x50) = (int)ROUND(fVar6);
  FUN_007bbdf0(uVar2,0xfffffffe);
  return;
}


// ==== FUN_0087c080 @ 0x0087c080 ====

int FUN_0087c080(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x58);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 0x5c) - iVar1) / 0xc)) {
      return iVar1 + param_1 * 0xc;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0085b340();
}


// ==== FUN_0087c0c0 @ 0x0087c0c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0087c0c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x58) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x58));
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  uVar1 = (**(code **)(*DAT_00b5a6bc + 8))();
  if (*(uint *)(param_1 + 0x54) < 0x10) {
    iVar2 = param_1 + 0x40;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x40);
  }
  FUN_007bb860(uVar1,iVar2,*(undefined4 *)(param_1 + 0x50),s_font_newtype_00a13c50);
  FUN_007bca30(uVar1,0,0,0);
  FUN_007bc470(uVar1,s_font_description_00a13c60);
  FUN_007bc620(uVar1,0xffffd8ef);
  FUN_007bc400(uVar1,_DAT_0099d0a0);
  FUN_007bc620(uVar1,0xfffffffe);
  iVar2 = FUN_007bbfa0(uVar1,0xffffffff);
  while (iVar2 == 5) {
    FUN_007bc470(uVar1,s_height_00a13c74);
    FUN_007bc620(uVar1,0xfffffffe);
    FUN_007bc1a0(uVar1,0xffffffff);
    FUN_007bbdf0(uVar1,0xfffffffe);
    FUN_007bc470(uVar1,s_width_00a13c7c);
    FUN_007bc620(uVar1,0xfffffffe);
    FUN_007bc1a0(uVar1,0xffffffff);
    FUN_007bbdf0(uVar1,0xfffffffe);
    FUN_007bc470(uVar1,s_shadow_00a13c84);
    FUN_007bc620(uVar1,0xfffffffe);
    FUN_007bc1a0(uVar1,0xffffffff);
    FUN_007bbdf0(uVar1,0xfffffffe);
    FUN_007bbdf0(uVar1,0xfffffffe);
    FUN_0087c8a0();
    FUN_007bc400(uVar1);
    FUN_007bc620(uVar1,0xfffffffe);
    iVar2 = FUN_007bbfa0(uVar1,0xffffffff);
  }
  FUN_007bbdf0(uVar1,0xfffffffe);
  FUN_007bbdf0(uVar1,0xfffffffe);
  return;
}


// ==== FUN_0087c2b0 @ 0x0087c2b0 ====

void FUN_0087c2b0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 local_1c;
  void *local_18;
  undefined4 uStack_c;
  uint local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_font_newtype_lua_00a13b90,0x10);
  piVar1 = (int *)FUN_0059a1e0(&local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    *(undefined4 *)(iVar2 + 0x28) = 0;
    (**(code **)(*DAT_00b5a7cc + 0x2c))(piVar1);
    local_8 = 0xf;
    uStack_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_font_newtype_lua_00a13ba4,0x10);
    iVar2 = FUN_0059a1e0((int)register0x00000010 + -0x20);
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
    FUN_0087bdc0(iVar2);
    FUN_0087bf20(iVar2);
    FUN_0087c0c0(iVar2);
    if (iVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(iVar2);
    }
  }
  return;
}


// ==== FUN_0087c3a0 @ 0x0087c3a0 ====

void FUN_0087c3a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13cb0;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d980 = (undefined4 *)0x0;
    FUN_0087c2b0();
    return;
  }
  DAT_00b5d980 = in_ECX;
  FUN_0087c2b0();
  return;
}


// ==== FUN_0087c400 @ 0x0087c400 ====

void FUN_0087c400(void)

{
  void *pvVar1;
  
  if (DAT_00b5d980 == 0) {
    pvVar1 = operator_new(100);
    if (pvVar1 != (void *)0x0) {
      FUN_0087c3a0();
      return;
    }
  }
  return;
}


// ==== FUN_0087c420 @ 0x0087c420 ====

int FUN_0087c420(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a620;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xc) {
    FUN_004e3d80(param_3,param_1);
    param_3 = param_3 + 0xc;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0087c486 @ 0x0087c486 ====

void Catch_0087c486(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0087c490 @ 0x0087c490 ====

void FUN_0087c490(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a630;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004e3d80(param_1,param_3);
    param_1 = param_1 + 0xc;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087c4f6 @ 0x0087c4f6 ====

void Catch_0087c4f6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0087c500 @ 0x0087c500 ====

void FUN_0087c500(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0087c420(param_1,param_2,param_3);
  return;
}


// ==== FUN_0087c520 @ 0x0087c520 ====

int FUN_0087c520(int param_1,int param_2,undefined4 param_3)

{
  FUN_0087c490(param_1,param_2,param_3);
  return param_1 + param_2 * 0xc;
}


// ==== FUN_0087c550 @ 0x0087c550 ====

int FUN_0087c550(void)

{
  int in_ECX;
  
  return in_ECX + 0x2c;
}


// ==== FUN_0087c560 @ 0x0087c560 ====

void FUN_0087c560(byte param_1)

{
  void *in_ECX;
  
  FUN_0087bd40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087c580 @ 0x0087c580 ====

void FUN_0087c580(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a640;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
  local_44 = *param_3;
  local_40 = param_3[1];
  local_3c = param_3[2];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0xc;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x50);
    if (0x15555555U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_20 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    if (local_20 < iVar2 + param_2) {
      if (0x15555555 - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_004a3750();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0xc;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_0087c500(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_0087c520(local_1c,param_2,&local_44);
      FUN_0087c500(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0xc;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0xc);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0xc) < param_2) {
      local_24 = param_2 * 0xc;
      FUN_0087c420(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_0087c520(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0xc,&local_44);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_006d89e0(param_1,*(int *)(in_ECX + 8) - local_24,&local_44);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0xc;
    uVar4 = FUN_0087c420(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_004ab780(param_1,local_2c,local_28,local_38);
    FUN_006d89e0(param_1,param_2 * 0xc + param_1,&local_44);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087c728 @ 0x0087c728 ====

void Catch_0087c728(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0087c830 @ 0x0087c830 ====

void FUN_0087c830(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_0087c873;
    }
  }
  iVar1 = 0;
LAB_0087c873:
  FUN_0087c580(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_0087c8a0 @ 0x0087c8a0 ====

void FUN_0087c8a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_0087c830(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0087c490(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_0087c920 @ 0x0087c920 ====

void FUN_0087c920(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13d1c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087c940 @ 0x0087c940 ====

void FUN_0087c940(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x35);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x35);
  }
  return;
}


// ==== FUN_0087c960 @ 0x0087c960 ====

void FUN_0087c960(void)

{
  if (DAT_00b5d984 != (int *)0x0) {
    (**(code **)(*DAT_00b5d984 + 4))(1);
  }
  return;
}


// ==== FUN_0087c980 @ 0x0087c980 ====

void FUN_0087c980(void)

{
  FUN_0086f570();
  return;
}


// ==== FUN_0087c990 @ 0x0087c990 ====

void FUN_0087c990(void)

{
  uint in_ECX;
  uint local_4;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    local_4 = in_ECX & 0xffffff00;
    FUN_0087cd50(**(undefined4 **)(in_ECX + 8),*(undefined4 **)(in_ECX + 8),local_4);
    FUN_0087d2d0(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
    *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
    *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  }
  return;
}


// ==== FUN_0087c9e0 @ 0x0087c9e0 ====

undefined4 FUN_0087c9e0(int param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  int in_ECX;
  undefined1 local_54 [8];
  int local_4c;
  void *local_48;
  void *local_44;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  char local_2c;
  undefined4 local_28;
  int local_24;
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  char local_4;
  
  uVar3 = param_2;
  local_34 = 0xf;
  local_38 = 0;
  local_48 = (void *)((uint)local_48 & 0xffffff00);
  FUN_00401660(param_2,0,0xffffffff);
  iVar1 = param_1;
  local_24 = param_1;
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(&local_4c,0,0xffffffff);
  local_4 = param_3;
  if (0xf < local_34) {
    _free(local_48);
    return extraout_EAX;
  }
  param_2 = in_ECX + 4;
  FUN_0087ce80(&param_1,&local_24);
  if (param_1 == *(int *)(in_ECX + 8)) {
    pvVar2 = operator_new(0x1c);
    if (param_3 == '\0') {
      if (pvVar2 == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_00891180(iVar1,uVar3);
      }
      local_4c = local_24;
      local_30 = 0xf;
      local_34 = 0;
      local_44 = (void *)((uint)local_44 & 0xffffff00);
      FUN_00401660(local_20,0,0xffffffff);
      local_2c = local_4;
      local_28 = uVar3;
      FUN_0087d510(local_54,&local_4c);
      if (0xf < local_30) {
        _free(local_44);
        return extraout_EAX_03;
      }
      if (0xf < local_8) {
        _free(local_1c);
        return extraout_EAX_04;
      }
    }
    else {
      if (pvVar2 == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_00891c50(iVar1,uVar3);
      }
      local_4c = local_24;
      local_30 = 0xf;
      local_34 = 0;
      local_44 = (void *)((uint)local_44 & 0xffffff00);
      FUN_00401660(local_20,0,0xffffffff);
      local_2c = local_4;
      local_28 = uVar3;
      FUN_0087d510(local_54,&local_4c);
      if (0xf < local_30) {
        _free(local_44);
        return extraout_EAX_01;
      }
      if (0xf < local_8) {
        _free(local_1c);
        return extraout_EAX_02;
      }
    }
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x30);
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX_00;
    }
  }
  return uVar3;
}


// ==== FUN_0087cbe0 @ 0x0087cbe0 ====

void FUN_0087cbe0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a13d30;
  FUN_0087c990();
  DAT_00b5d984 = 0;
  FUN_0087d620(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0087cc40 @ 0x0087cc40 ====

void FUN_0087cc40(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13d30;
  iVar1 = FUN_0087ccb0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x35) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d984 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d984 = in_ECX;
  return;
}


// ==== FUN_0087cc90 @ 0x0087cc90 ====

void FUN_0087cc90(void)

{
  void *pvVar1;
  
  if (DAT_00b5d984 == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_0087cc40();
      return;
    }
  }
  return;
}


// ==== FUN_0087ccb0 @ 0x0087ccb0 ====

void FUN_0087ccb0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a650;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x38);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xd) = 1;
  *(undefined1 *)((int)puVar1 + 0x35) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087cd3a @ 0x0087cd3a ====

void Catch_0087cd3a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0087cd50 @ 0x0087cd50 ====

undefined1 FUN_0087cd50(int *param_1,int *param_2,undefined1 param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    if ((undefined4 *)param_1[0xc] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[0xc])(1);
    }
    if (*(char *)((int)param_1 + 0x35) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x35) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x35);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x35);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x35);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x35);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  return param_3;
}


// ==== FUN_0087cdc0 @ 0x0087cdc0 ====

bool FUN_0087cdc0(int *param_1,int *param_2)

{
  char cVar1;
  
  if (*param_1 < *param_2) {
    return true;
  }
  if (*param_1 <= *param_2) {
    if (*(byte *)(param_1 + 8) < *(byte *)(param_2 + 8)) {
      return true;
    }
    if (*(byte *)(param_1 + 8) <= *(byte *)(param_2 + 8)) {
      cVar1 = FUN_0040a6a0(param_1 + 1,param_2 + 1);
      return cVar1 != '\0';
    }
  }
  return false;
}


// ==== FUN_0087ce10 @ 0x0087ce10 ====

undefined4 * FUN_0087ce10(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x35);
  puVar2 = *(undefined4 **)(in_ECX + 4);
  do {
    if (cVar1 != '\0') {
      return puVar2;
    }
    if ((int)puVar5[3] < *param_1) {
LAB_0087ce61:
      puVar6 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    else {
      if ((int)puVar5[3] <= *param_1) {
        if (*(byte *)(puVar5 + 0xb) < *(byte *)(param_1 + 8)) goto LAB_0087ce61;
        if (*(byte *)(puVar5 + 0xb) <= *(byte *)(param_1 + 8)) {
          if ((uint)param_1[7] < 0x10) {
            piVar3 = param_1 + 2;
          }
          else {
            piVar3 = (int *)param_1[2];
          }
          iVar4 = FUN_00403620(0,puVar5[9],piVar3,param_1[6]);
          if (iVar4 < 0) goto LAB_0087ce61;
        }
      }
      puVar6 = (undefined4 *)*puVar5;
    }
    cVar1 = *(char *)((int)puVar6 + 0x35);
    puVar2 = puVar5;
    puVar5 = puVar6;
  } while( true );
}


// ==== FUN_0087ce80 @ 0x0087ce80 ====

void FUN_0087ce80(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_0087ce10(param_2);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    if (*(int *)(iVar2 + 0xc) <= *param_2) {
      if (*param_2 <= *(int *)(iVar2 + 0xc)) {
        if (*(byte *)(param_2 + 8) < *(byte *)(iVar2 + 0x2c)) goto LAB_0087ced5;
        if (*(byte *)(param_2 + 8) <= *(byte *)(iVar2 + 0x2c)) {
          cVar1 = FUN_0040a6a0(param_2 + 1,iVar2 + 0x10);
          if (cVar1 != '\0') goto LAB_0087ced5;
        }
      }
      *param_1 = iVar2;
      return;
    }
  }
LAB_0087ced5:
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0087cef0 @ 0x0087cef0 ====

void FUN_0087cef0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  *in_ECX = param_1;
  in_ECX[3] = *param_4;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_00401660(param_4 + 1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0xb) = *(undefined1 *)(param_4 + 8);
  in_ECX[0xc] = param_4[9];
  *(undefined1 *)(in_ECX + 0xd) = param_5;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  return;
}


// ==== FUN_0087cf60 @ 0x0087cf60 ====

void * FUN_0087cf60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a660;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x38);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0087cef0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0087cfd5 @ 0x0087cfd5 ====

void Catch_0087cfd5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0087cff0 @ 0x0087cff0 ====

/* WARNING: Removing unreachable block (ram,0x0087d109) */
/* WARNING: Removing unreachable block (ram,0x0087d11a) */
/* WARNING: Removing unreachable block (ram,0x0087d123) */
/* WARNING: Removing unreachable block (ram,0x0087d126) */
/* WARNING: Removing unreachable block (ram,0x0087d116) */
/* WARNING: Removing unreachable block (ram,0x0087d134) */
/* WARNING: Removing unreachable block (ram,0x0087d141) */
/* WARNING: Removing unreachable block (ram,0x0087d14c) */
/* WARNING: Removing unreachable block (ram,0x0087d148) */
/* WARNING: Removing unreachable block (ram,0x0087d13c) */
/* WARNING: Removing unreachable block (ram,0x0087d14f) */

void FUN_0087cff0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(char *)((int)param_2 + 0x35) != '\0') {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c7c8);
  }
  FUN_00411640();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x35) == '\0') {
    if (*(char *)(param_2[2] + 0x35) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x35) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar6 + 0x35) == '\0') {
      piVar3 = (int *)FUN_0087c940(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x35) == '\0') {
      uVar4 = FUN_00868480(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xd] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xd] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xd] == '\0') {
            *(undefined1 *)(piVar5 + 0xd) = 1;
            *(undefined1 *)(piVar3 + 0xd) = 0;
            FUN_008685b0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x35) == '\0') {
            if ((*(char *)(*piVar5 + 0x34) == '\x01') && (*(char *)(piVar5[2] + 0x34) == '\x01'))
            goto LAB_0087d224;
            if (*(char *)(piVar5[2] + 0x34) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x34) = 1;
              *(undefined1 *)(piVar5 + 0xd) = 0;
              FUN_00868600(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xd) = (char)piVar3[0xd];
            *(undefined1 *)(piVar3 + 0xd) = 1;
            *(undefined1 *)(piVar5[2] + 0x34) = 1;
            FUN_008685b0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xd] == '\0') {
            *(undefined1 *)(piVar5 + 0xd) = 1;
            *(undefined1 *)(piVar3 + 0xd) = 0;
            FUN_00868600(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x35) == '\0') {
            if ((*(char *)(piVar5[2] + 0x34) != '\x01') || (*(char *)(*piVar5 + 0x34) != '\x01')) {
              if (*(char *)(*piVar5 + 0x34) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x34) = 1;
                *(undefined1 *)(piVar5 + 0xd) = 0;
                FUN_008685b0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xd) = (char)piVar3[0xd];
              *(undefined1 *)(piVar3 + 0xd) = 1;
              *(undefined1 *)(*piVar5 + 0x34) = 1;
              FUN_00868600(piVar3);
              break;
            }
LAB_0087d224:
            *(undefined1 *)(piVar5 + 0xd) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xd) = 1;
  }
  if ((uint)param_2[10] < 0x10) {
    param_2[10] = 0xf;
    param_2[9] = 0;
    *(undefined1 *)(param_2 + 5) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_0087d2d0 @ 0x0087d2d0 ====

void FUN_0087d2d0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x35) != '\0') {
    return;
  }
  FUN_0087d2d0(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x28) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x28) = 0xf;
    *(undefined4 *)((int)param_1 + 0x24) = 0;
    *(undefined1 *)((int)param_1 + 0x14) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x14));
  return;
}


// ==== FUN_0087d330 @ 0x0087d330 ====

void FUN_0087d330(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0x6666664 < *(uint *)(in_ECX + 8)) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    FUN_00801756();
    local_28[0] = &PTR_FUN_0099c980;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    local_28[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_28,&DAT_00a9c48c);
  }
  piVar4 = (int *)FUN_0087cf60(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
                               param_4,0);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  if (param_3 == *(undefined4 **)(in_ECX + 4)) {
    (*(undefined4 **)(in_ECX + 4))[1] = piVar4;
    **(undefined4 **)(in_ECX + 4) = piVar4;
    *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
  }
  else if (param_2 == '\0') {
    param_3[2] = piVar4;
    if (param_3 == *(undefined4 **)(*(int *)(in_ECX + 4) + 8)) {
      *(int **)(*(int *)(in_ECX + 4) + 8) = piVar4;
    }
  }
  else {
    *param_3 = piVar4;
    if (param_3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      **(int **)(in_ECX + 4) = (int)piVar4;
    }
  }
  cVar1 = *(char *)(piVar4[1] + 0x34);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x34) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xd] == '\0') {
LAB_0087d435:
        *(undefined1 *)(*piVar5 + 0x34) = 1;
        *(undefined1 *)(piVar6 + 0xd) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x34) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_008685b0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x34) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x34) = 0;
        FUN_00868600(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xd] == '\0') goto LAB_0087d435;
      if (piVar7 == (int *)*piVar2) {
        FUN_00868600(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x34) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x34) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x35) == '\0') {
        *(int *)(*piVar2 + 4) = iVar3;
      }
      piVar2[1] = *(int *)(iVar3 + 4);
      if (iVar3 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
        *(int **)(*(int *)(in_ECX + 4) + 4) = piVar2;
      }
      else {
        piVar6 = *(int **)(iVar3 + 4);
        if (iVar3 == *piVar6) {
          *piVar6 = (int)piVar2;
        }
        else {
          piVar6[2] = (int)piVar2;
        }
      }
      *piVar2 = iVar3;
      *(int **)(iVar3 + 4) = piVar2;
    }
    cVar1 = *(char *)(piVar7[1] + 0x34);
  } while( true );
}


// ==== FUN_0087d510 @ 0x0087d510 ====

void FUN_0087d510(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  bool bVar7;
  
  piVar1 = param_2;
  puVar5 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar7 = true;
  cVar2 = *(char *)((int)puVar5 + 0x35);
  puVar3 = *(undefined4 **)(in_ECX + 4);
  while (cVar2 == '\0') {
    if (*piVar1 < (int)puVar5[3]) {
      bVar7 = true;
    }
    else if ((int)puVar5[3] < *piVar1) {
      bVar7 = false;
    }
    else if (*(byte *)(piVar1 + 8) < *(byte *)(puVar5 + 0xb)) {
      bVar7 = true;
    }
    else if (*(byte *)(puVar5 + 0xb) < *(byte *)(piVar1 + 8)) {
      bVar7 = false;
    }
    else {
      if ((uint)puVar5[10] < 0x10) {
        puVar3 = puVar5 + 5;
      }
      else {
        puVar3 = (undefined4 *)puVar5[5];
      }
      iVar4 = FUN_00403620(0,piVar1[6],puVar3,puVar5[9]);
      bVar7 = iVar4 < 0;
    }
    if (bVar7) {
      puVar6 = (undefined4 *)*puVar5;
    }
    else {
      puVar6 = (undefined4 *)puVar5[2];
    }
    puVar3 = puVar5;
    puVar5 = puVar6;
    cVar2 = *(char *)((int)puVar6 + 0x35);
  }
  param_2 = puVar3;
  if (bVar7) {
    if (puVar3 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_0087d330(&param_2,1,puVar3,piVar1);
      *param_1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00885cd0();
  }
  puVar5 = param_2;
  cVar2 = FUN_0087cdc0(param_2 + 3,piVar1);
  if (cVar2 == '\0') {
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  puVar5 = (undefined4 *)FUN_0087d330(&param_2,bVar7,puVar3,piVar1);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_0087d620 @ 0x0087d620 ====

void FUN_0087d620(undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  
  piVar4 = param_3;
  piVar6 = *(int **)(in_ECX + 4);
  piVar3 = param_2;
  if ((param_2 == (int *)*piVar6) && (param_3 == piVar6)) {
    FUN_0087d2d0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x35) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x35) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x35);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x35);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x35);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x35);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0087cff0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0087d6e0 @ 0x0087d6e0 ====

void FUN_0087d6e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0087cbe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087d700 @ 0x0087d700 ====

void FUN_0087d700(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13ec0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087d720 @ 0x0087d720 ====

void FUN_0087d720(void)

{
  if (DAT_00b5d990 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d990)(1);
  }
  return;
}


// ==== FUN_0087d740 @ 0x0087d740 ====

undefined4 FUN_0087d740(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      return *(undefined4 *)(in_ECX + 8);
    }
    if (param_1 == 2) {
      return *(undefined4 *)(in_ECX + 0xc);
    }
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a13e48,
                         s___RenderCore_RenderContext_Bone__00a13e10,0x87);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0087d7b0 @ 0x0087d7b0 ====

uint FUN_0087d7b0(undefined4 param_1,char param_2,char param_3,char param_4,char param_5)

{
  int *piVar1;
  int iVar2;
  
  if (param_4 != '\0') {
    return 3 - (param_3 != '\0');
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  if (*(int *)(iVar2 + 8) != 0) {
    iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
    if ((*(char *)(iVar2 + 3) != '\0') && (param_5 != '\0')) {
      return (param_3 != '\0') + 5;
    }
  }
  if (param_2 == '\0') {
    return (uint)(param_3 != '\0');
  }
  return 4;
}


// ==== FUN_0087d820 @ 0x0087d820 ====

void FUN_0087d820(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 == 0) {
    piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x1c);
    (**(code **)(*piVar1 + 0xf0))(piVar1,*(undefined4 *)(*(int *)(in_ECX + 0x14) + param_2 * 4));
    return;
  }
  if (param_1 == 1) {
    piVar1 = *(int **)(*(int *)(in_ECX + 8) + 0x1c);
    (**(code **)(*piVar1 + 0xf0))(piVar1,*(undefined4 *)(*(int *)(in_ECX + 0x24) + param_2 * 4));
    return;
  }
  if (param_1 == 2) {
    piVar1 = *(int **)(*(int *)(in_ECX + 0xc) + 0x1c);
    (**(code **)(*piVar1 + 0xf0))(piVar1,*(undefined4 *)(*(int *)(in_ECX + 0x34) + param_2 * 4));
    return;
  }
  local_100[0] = 0;
  uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_00a13e94,
                       s___RenderCore_RenderContext_Bone__00a13e5c,0x9d);
  FUN_00797b80(uVar2);
  FUN_00797a40();
  return;
}


// ==== FUN_0087d8f0 @ 0x0087d8f0 ====

void FUN_0087d8f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13ed8;
  DAT_00b5d990 = 0;
  if ((void *)in_ECX[0xd] != (void *)0x0) {
    _free((void *)in_ECX[0xd]);
    return;
  }
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  if ((void *)in_ECX[9] != (void *)0x0) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  if ((void *)in_ECX[5] == (void *)0x0) {
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    *in_ECX = &PTR_FUN_00a13ec0;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_0087d960 @ 0x0087d960 ====

int FUN_0087d960(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int extraout_EAX;
  undefined1 local_fc [4];
  void *local_f8;
  undefined4 local_e8;
  uint local_e4;
  
  local_e4 = 0xf;
  local_e8 = 0;
  local_f8 = (void *)((uint)local_f8 & 0xffffff00);
  switch(param_2) {
  case 0:
    uVar1 = FUN_00401830(s_BoneAnimDiffuse_00a13d94);
    FUN_00401660(uVar1,0,0xffffffff);
    break;
  case 1:
    uVar1 = FUN_00401830(s_BoneAnimBacklightShadow_00a13d7c);
    FUN_00401660(uVar1,0,0xffffffff);
    break;
  case 2:
    uVar1 = FUN_00401830(s_BoneAnimMaxShadow_00a13da4);
    FUN_00401660(uVar1,0,0xffffffff);
    break;
  case 3:
    uVar1 = FUN_00401830(s_BoneAnimMaxDirection_00a13db8);
    FUN_00401660(uVar1,0,0xffffffff);
    break;
  case 4:
    if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) == '\0') {
      uVar1 = FUN_00401830(s_BoneAnimBlinn_00a13ddc);
      FUN_00401660(uVar1,0,0xffffffff);
    }
    else {
      uVar1 = FUN_00401830(s_BoneAnimEnv_00a13dd0);
      FUN_00401660(uVar1,0,0xffffffff);
    }
    break;
  case 5:
    uVar1 = FUN_00401830(s_BoneAnimBump_00a13dec);
    FUN_00401660(uVar1,0,0xffffffff);
    break;
  case 6:
    uVar1 = FUN_00401830(s_BoneAnimBumpShadow_00a13dfc);
    FUN_00401660(uVar1,0,0xffffffff);
    break;
  default:
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(local_fc,0,0xffffffff);
    if (local_e4 < 0x10) {
      return param_1;
    }
    _free(local_f8);
    return extraout_EAX;
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0087db40 @ 0x0087db40 ====

void FUN_0087db40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13ed8;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5d990 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5d990 = in_ECX;
  return;
}


// ==== FUN_0087db90 @ 0x0087db90 ====

void FUN_0087db90(void)

{
  void *pvVar1;
  
  if (DAT_00b5d990 == 0) {
    pvVar1 = operator_new(0x40);
    if (pvVar1 != (void *)0x0) {
      FUN_0087db40();
      return;
    }
  }
  return;
}


// ==== FUN_0087dbb0 @ 0x0087dbb0 ====

void FUN_0087dbb0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_24;
  uint uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  iVar3 = (**(code **)(*piVar2 + 0x1c))();
  iVar5 = 0;
  if (*(int *)(iVar3 + 8) == 0) {
    uVar4 = FUN_0085e3a0(0x11);
    *(undefined4 *)(in_ECX + 4) = uVar4;
    uVar4 = 0x12;
  }
  else {
    uVar4 = FUN_0085e3a0(1);
    *(undefined4 *)(in_ECX + 4) = uVar4;
    uVar4 = 2;
  }
  uVar4 = FUN_0085e3a0(uVar4);
  *(undefined4 *)(in_ECX + 8) = uVar4;
  uVar4 = FUN_0085e3a0(3);
  *(undefined4 *)(in_ECX + 0xc) = uVar4;
  FUN_0087e010(7,0);
  FUN_0087e010(7,0);
  FUN_0087e010(7,0);
  uStack_20 = 0xf;
  uStack_24 = 0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  do {
    uVar4 = FUN_0087d960(auStack_1c,iVar5);
    FUN_00401660(uVar4,0,0xffffffff);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    iVar1 = *(int *)(in_ECX + 0x14);
    iVar3 = iVar5 * 4;
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    uVar4 = FUN_0087dd40(auStack_38);
    *(undefined4 *)(iVar1 + iVar3) = uVar4;
    iVar1 = *(int *)(in_ECX + 0x24);
    uVar4 = FUN_0087dd40(auStack_38);
    *(undefined4 *)(iVar1 + iVar3) = uVar4;
    iVar1 = *(int *)(in_ECX + 0x34);
    uVar4 = FUN_0087dd40(auStack_38);
    iVar5 = iVar5 + 1;
    *(undefined4 *)(iVar1 + iVar3) = uVar4;
  } while (iVar5 < 7);
  if (uStack_20 < 0x10) {
    return;
  }
  _free(pvStack_34);
  return;
}


// ==== FUN_0087dd20 @ 0x0087dd20 ====

void FUN_0087dd20(byte param_1)

{
  void *in_ECX;
  
  FUN_0087d8f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087dd40 @ 0x0087dd40 ====

/* WARNING: Removing unreachable block (ram,0x0087dd9c) */

int FUN_0087dd40(int param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int iStack_24;
  
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    iStack_24 = param_1 + 4;
  }
  else {
    iStack_24 = *(int *)(param_1 + 4);
  }
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x1c) + 0x34))(*(int **)(in_ECX + 0x1c));
  if (iVar2 == 0) {
    FUN_00401740(s_handle____NULL_00a13eec,0xe);
    FUN_00406880(&iStack_24);
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  return iVar2;
}


// ==== FUN_0087ddc0 @ 0x0087ddc0 ====

void FUN_0087ddc0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined1 auStack_2a [18];
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a670;
  local_10 = ExceptionList;
  local_14 = auStack_2a + -0xe;
  local_18 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 2;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
    }
    uVar7 = param_2;
    ExceptionList = &local_10;
    puVar1 = auStack_2a + -0xe;
    if (0x3fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar8 = FUN_0085b3b0();
      uVar7 = (uint)((ulonglong)uVar8 >> 0x20);
      uVar2 = (uint)uVar8;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
    }
    if (uVar2 < iVar6 + uVar7) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 2;
      }
      if (uVar2 < iVar6 + uVar7) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 2;
        }
        uVar2 = iVar3 + uVar7;
      }
      pvVar4 = operator_new(uVar2 * 4);
      local_8 = 0;
      uVar5 = FUN_005a6d90(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00845740(uVar5,param_2,&local_18);
      FUN_005a6d90(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 4);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)(iVar3 - param_1 >> 2) < uVar7) {
      FUN_005a6d90(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00845740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005a6d90(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00822d20(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0087df21 @ 0x0087df21 ====

void Catch_0087df21(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0087e010 @ 0x0087e010 ====

void FUN_0087e010(uint param_1,undefined1 param_2)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 8) - iVar2 >> 2;
  }
  if (uVar1 < param_1) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 2;
    }
    FUN_0087ddc0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 2))
      ) && (_Dst = (void *)(iVar2 + param_1 * 4), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_0087e0a0 @ 0x0087e0a0 ====

void FUN_0087e0a0(void)

{
  return;
}


// ==== FUN_0087e0b0 @ 0x0087e0b0 ====

void FUN_0087e0b0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 4))(param_1);
  }
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 4))(param_1);
  }
  return;
}


// ==== FUN_0087e0e0 @ 0x0087e0e0 ====

void FUN_0087e0e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0087e0e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 4))();
  return;
}


// ==== FUN_0087e0f0 @ 0x0087e0f0 ====

void FUN_0087e0f0(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 4))(1);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xc))(1);
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== __break @ 0x0087e12a ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_0087e130 @ 0x0087e130 ====

void FUN_0087e130(void)

{
  int in_ECX;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x75) == '\0') {
    return;
  }
  FUN_0085a2b0();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 8))();
  }
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 8))();
  }
  FUN_00858ca0();
  return;
}


// ==== FUN_0087e180 @ 0x0087e180 ====

void FUN_0087e180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13f6c;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_00a10a18;
  return;
}


// ==== FUN_0087e1d0 @ 0x0087e1d0 ====

void FUN_0087e1d0(char param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  if (param_1 == '\0') {
    puVar3 = operator_new(0x34);
    uVar2 = DAT_0099d080;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_00a13f90;
      *(undefined1 *)(puVar3 + 0xb) = 0;
      *(undefined1 *)((int)puVar3 + 0x2d) = 0;
      puVar3[0xc] = uVar2;
      *(undefined4 **)(in_ECX + 4) = puVar3;
      return;
    }
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  else if (param_1 == '\x01') {
    pvVar1 = operator_new(0x60);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00894050();
    }
    *(undefined4 *)(in_ECX + 4) = uVar2;
    pvVar1 = operator_new(0x5c);
    if (pvVar1 == (void *)0x0) {
      *(undefined4 *)(in_ECX + 8) = 0;
      return;
    }
    uVar2 = FUN_008921a0();
    *(undefined4 *)(in_ECX + 8) = uVar2;
    return;
  }
  return;
}


// ==== FUN_0087e260 @ 0x0087e260 ====

void FUN_0087e260(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13f6c;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  uVar1 = FUN_00894530();
  in_ECX[3] = uVar1;
  FUN_0087e1d0(1);
  return;
}


// ==== FUN_0087e290 @ 0x0087e290 ====

undefined4 * FUN_0087e290(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar1 = operator_new(0x10);
  puVar3 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_00a13f6c;
    puVar1[1] = 0;
    puVar1[2] = 0;
    uVar2 = FUN_00894530();
    puVar1[3] = uVar2;
    FUN_0087e1d0(1);
    puVar3 = puVar1;
  }
  return puVar3;
}


// ==== FUN_0087e2d0 @ 0x0087e2d0 ====

void FUN_0087e2d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13f50;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087e2f0 @ 0x0087e2f0 ====

void FUN_0087e2f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a13f6c;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_00a10a18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087e360 @ 0x0087e360 ====

void FUN_0087e360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a146d0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0087e380 @ 0x0087e380 ====

void FUN_0087e380(void)

{
  if (DAT_00b5ac00 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac00)(1);
  }
  return;
}


// ==== FUN_0087e3a0 @ 0x0087e3a0 ====

int FUN_0087e3a0(void)

{
  byte bVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int extraout_EAX_05;
  int extraout_EAX_06;
  int extraout_EAX_07;
  int extraout_EAX_08;
  int extraout_EAX_09;
  int extraout_EAX_10;
  int extraout_EAX_11;
  int extraout_EAX_12;
  int extraout_EAX_13;
  int extraout_EAX_14;
  int extraout_EAX_15;
  int extraout_EAX_16;
  int extraout_EAX_17;
  int extraout_EAX_18;
  int extraout_EAX_19;
  int extraout_EAX_20;
  int extraout_EAX_21;
  int extraout_EAX_22;
  int extraout_EAX_23;
  int extraout_EAX_24;
  int extraout_EAX_25;
  int extraout_EAX_26;
  int extraout_EAX_27;
  int extraout_EAX_28;
  int extraout_EAX_29;
  int extraout_EAX_30;
  int extraout_EAX_31;
  int extraout_EAX_32;
  int extraout_EAX_33;
  int extraout_EAX_34;
  int extraout_EAX_35;
  int extraout_EAX_36;
  int extraout_EAX_37;
  int iVar2;
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  uint unaff_ESI;
  void *unaff_EDI;
  int iVar3;
  undefined4 uStack_140;
  undefined4 *_Memory;
  int iStack_138;
  uint **ppuStack_130;
  undefined4 uStack_12c;
  uint uVar4;
  undefined4 uStack_124;
  uint uVar5;
  char **ppcStack_f4;
  char **ppcStack_ec;
  uint *puStack_e4;
  void *_Memory_00;
  char *pcStack_dc;
  void *_Memory_01;
  void *_Memory_02;
  char *pcStack_cc;
  void *_Memory_03;
  char *pcStack_bc;
  char *pcStack_b4;
  uint uStack_ac;
  undefined4 uStack_a8;
  uint **ppuVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStack_88;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puStack_70;
  void *pvVar13;
  uint *puStack_68;
  void *pvVar14;
  uint *puStack_60;
  void *pvVar15;
  uint *puStack_58;
  char *pcStack_54;
  undefined4 uStack_50;
  uint local_38;
  void *local_34;
  uint uStack_30;
  void *pvStack_2c;
  uint uStack_28;
  void *local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a146f0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac00 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac00 = in_ECX;
  }
  uStack_50 = (undefined4 *)0xe;
  pcStack_54 = s_fov_near_scale_00a13fe4;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  puStack_58 = (uint *)0x87e3eb;
  FUN_00401740();
  uStack_50 = (undefined4 *)0xe;
  pcStack_54 = s_rc_shadowvalue_00a13ff4;
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  puStack_58 = (uint *)0x87e407;
  FUN_00401740();
  uStack_50 = &local_1c;
  pcStack_54 = (void *)0x3;
  puStack_58 = &local_38;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < pvStack_2c) {
    puStack_60 = (uint *)0x87e433;
    _free(unaff_EBX);
    return extraout_EAX;
  }
  pvStack_2c = (void *)0xf;
  uStack_30 = 0;
  if (0xf < uStack_10) {
    puStack_60 = (uint *)0x87e452;
    _free(local_24);
    return extraout_EAX_00;
  }
  puStack_60 = (uint *)s_rc_wireframe_00a14004;
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740();
  pvVar15 = (void *)0x1;
  puStack_60 = &uStack_28;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < local_18) {
    puStack_68 = (uint *)0x87e493;
    _free(pvStack_2c);
    return extraout_EAX_01;
  }
  puStack_68 = (uint *)s_rc_windowmouse_00a14014;
  local_18 = 0xf;
  local_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401740();
  pvVar14 = (void *)0x1;
  puStack_68 = &uStack_30;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < local_20) {
    puStack_70 = (uint *)0x87e4d4;
    _free(local_34);
    return extraout_EAX_02;
  }
  puStack_70 = (uint *)s_rc_skybox_00a14024;
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740();
  pvVar13 = (void *)0x1;
  puStack_70 = &local_38;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_28) {
    _free(in_ECX);
    return extraout_EAX_03;
  }
  uStack_28 = 0xf;
  pvStack_2c = (void *)0x0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_30) {
    _free(unaff_EBP);
    return extraout_EAX_04;
  }
  uStack_30 = 0xf;
  local_34 = (void *)0x0;
  FUN_00401740();
  uVar11 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < local_38) {
    _free(unaff_EDI);
    return extraout_EAX_05;
  }
  local_38 = 0xf;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < ((uint)unaff_EBX & 0xffffff00)) {
    _free(pcStack_54);
    return extraout_EAX_06;
  }
  pcStack_54 = (char *)((uint)pcStack_54 & 0xffffff00);
  FUN_00401740();
  uVar9 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < unaff_ESI) {
    _free(pvVar15);
    return extraout_EAX_07;
  }
  FUN_00401740();
  pvVar15 = (void *)0x2;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((undefined4 *)0xf < uStack_50) {
    _free(pvVar14);
    return extraout_EAX_08;
  }
  uStack_50 = (undefined4 *)0xf;
  pcStack_54 = (char *)0x0;
  uVar5 = (uint)pvVar14 & 0xffffff00;
  FUN_00401740();
  uVar7 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((uint *)0xf < puStack_58) {
    uStack_a8 = (char *)0x87e69b;
    _free(pvVar13);
    return extraout_EAX_09;
  }
  uStack_a8 = s__1_shadow_2_cover_3_cloud_4_warf_00a1407c;
  puStack_58 = (uint *)0xf;
  uVar4 = (uint)pvVar13 & 0xffffff00;
  uStack_ac = 0x87e6ba;
  FUN_00401740();
  uStack_a8 = s_rc_rendertexture_00a140b4;
  uVar12 = 0xf;
  uStack_88 = (void *)((int)register0x00000010 + -0x100);
  uStack_ac = 0x87e6d5;
  FUN_00401740();
  ppuVar6 = &puStack_70;
  uStack_a8 = (void *)0x1;
  uStack_ac = (int)register0x00000010 - 0x8c;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < (int)register0x00000010 - 0x48U) {
    pcStack_b4 = (char *)0x87e6fc;
    _free(pvVar15);
    return extraout_EAX_10;
  }
  uVar10 = 0;
  uVar8 = (uint)pvVar15 & 0xffffff00;
  if (0xf < uVar5) {
    pcStack_b4 = (char *)0x87e71b;
    _free((void *)0x0);
    return extraout_EAX_11;
  }
  pcStack_b4 = s_rc_glowtexture_00a140c8;
  puStack_68 = (uint *)0x0;
  FUN_00401740();
  pvVar15 = (void *)0x1;
  pcStack_b4 = (char *)((int)register0x00000010 - 0x7c);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar4) {
    pcStack_bc = (char *)0x87e75c;
    _free((void *)0xf);
    return extraout_EAX_12;
  }
  pcStack_bc = s_rc_renderobj_00a140d8;
  puStack_70 = (uint *)0x0;
  FUN_00401740();
  pvVar14 = (void *)0x1;
  pcStack_bc = (char *)((int)register0x00000010 - 0x84);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar12) {
    _free(uStack_88);
    return extraout_EAX_13;
  }
  FUN_00401740();
  pvVar13 = (void *)0x1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar11) {
    pcStack_cc = (char *)0x87e7de;
    _free(&puStack_58);
    return extraout_EAX_14;
  }
  pcStack_cc = s_rc_rendergui_00a140f8;
  FUN_00401740();
  _Memory_03 = (void *)0x1;
  pcStack_cc = (char *)((int)register0x00000010 - 0x94);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar10) {
    _free(&puStack_60);
    return extraout_EAX_15;
  }
  FUN_00401740();
  _Memory_02 = (void *)0x1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar9) {
    pcStack_dc = (char *)0x87e860;
    _free(&puStack_68);
    return extraout_EAX_16;
  }
  pcStack_dc = s_rc_usemipmap_00a1411c;
  FUN_00401740();
  _Memory_01 = (void *)0x1;
  pcStack_dc = (char *)((int)register0x00000010 - 0xa4);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar8) {
    puStack_e4 = (uint *)0x87e8a1;
    _free(uStack_a8);
    return extraout_EAX_17;
  }
  puStack_e4 = (uint *)s_rc_capture_00a1412c;
  uStack_a8 = (char *)((uint)uStack_a8 & 0xffffff00);
  FUN_00401740();
  _Memory_00 = (void *)0x0;
  puStack_e4 = &uStack_ac;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar7) {
    ppcStack_ec = (char **)0x87e8e1;
    _free(pvVar15);
    return extraout_EAX_18;
  }
  ppcStack_ec = (char **)s_rc_specularmap_00a14138;
  FUN_00401740();
  pvVar15 = (void *)0x1;
  ppcStack_ec = &pcStack_b4;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((uint **)0xf < ppuVar6) {
    ppcStack_f4 = (char **)0x87e922;
    _free(pvVar14);
    return extraout_EAX_19;
  }
  ppcStack_f4 = (char **)s_rc_fog_00a14148;
  uStack_a8 = (char *)0x0;
  FUN_00401740();
  pvVar14 = (void *)0x1;
  ppcStack_f4 = &pcStack_bc;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_ac) {
    _free(pvVar13);
    return extraout_EAX_20;
  }
  uStack_ac = 0xf;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((char *)0xf < pcStack_b4) {
    _free(_Memory_03);
    return extraout_EAX_21;
  }
  pcStack_b4 = (char *)0xf;
  FUN_00401740();
  uVar11 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((char *)0xf < pcStack_bc) {
    _free(_Memory_02);
    return extraout_EAX_22;
  }
  pcStack_bc = (char *)0xf;
  FUN_00401740();
  uVar9 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < (int)register0x00000010 - 0x8cU) {
    _free(_Memory_01);
    return extraout_EAX_23;
  }
  FUN_00401740();
  uVar7 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((char *)0xf < pcStack_cc) {
    _free(_Memory_00);
    return extraout_EAX_24;
  }
  pcStack_cc = (char *)0xf;
  FUN_00401740();
  pvVar13 = (void *)0x2;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < (int)register0x00000010 - 0x9cU) {
    uStack_124 = (char *)0x87eaa8;
    _free(pvVar15);
    return extraout_EAX_25;
  }
  uStack_124 = s_rc_renderinfo_00a14184;
  uVar12 = (uint)pvVar15 & 0xffffff00;
  FUN_00401740();
  uVar5 = 1;
  uStack_124 = (char *)&ppcStack_ec;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((char *)0xf < pcStack_dc) {
    uStack_12c = (char *)0x87eae9;
    _free(pvVar14);
    return extraout_EAX_26;
  }
  uStack_12c = s_0_no_1_1_1_2_2_0_00a14194;
  ppuStack_130 = (undefined4 **)0x87eb08;
  FUN_00401740();
  uStack_12c = (char *)0x87eb16;
  FUN_00401830();
  uVar4 = (int)register0x00000010 - 0x110;
  uStack_12c = (void *)0x1;
  ppuStack_130 = (uint **)&ppcStack_f4;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uVar12) {
    iStack_138 = 0x87eb3d;
    _free((void *)0x0);
    return extraout_EAX_27;
  }
  ppcStack_ec = (char **)0x0;
  if ((char **)0xf < &pcStack_cc) {
    iStack_138 = 0x87eb5c;
    _free(pvVar13);
    return extraout_EAX_28;
  }
  iStack_138 = 0x87eb6d;
  FUN_00401830();
  pvVar15 = (void *)0x0;
  iStack_138 = (int)register0x00000010 + -0x100;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if ((void *)0xf < pvVar14) {
    uStack_140 = 0x87eb8e;
    _free(&pcStack_cc);
    return extraout_EAX_29;
  }
  uStack_140 = 0x87eb9f;
  FUN_00401830();
  uStack_140 = 0x87ebad;
  FUN_00401830();
  _Memory = &uStack_124;
  uStack_140 = 1;
  (**(code **)(*DAT_00b5a6c8 + 4))((int)register0x00000010 + -0x108);
  if (0xf < uVar11) {
    _free(&pcStack_dc);
    return extraout_EAX_30;
  }
  if ((uint **)0xf < &puStack_e4) {
    _free(ppuStack_130);
    return extraout_EAX_31;
  }
  FUN_00401830(s_rc_refresh_flare_00a14204);
  (**(code **)(*DAT_00b5a6c8 + 0xc))((int)register0x00000010 + -0x118,1);
  if (0xf < uVar9) {
    _free(&puStack_e4);
    return extraout_EAX_32;
  }
  FUN_00401830(s_rc_waterlevel_00a14218);
  (**(code **)(*DAT_00b5a6c8 + 0xc))((int)register0x00000010 + -0x120,1);
  if (0xf < uVar7) {
    _free(uStack_124);
    return extraout_EAX_33;
  }
  FUN_00401830(s_rc_bumpmap_00a14228);
  (**(code **)(*DAT_00b5a6c8 + 0xc))((int)register0x00000010 + -0x128,1);
  if ((void *)0xf < pvVar13) {
    _free(uStack_12c);
    return extraout_EAX_34;
  }
  FUN_00401830(s_rc_waterheight_00a14234);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&ppuStack_130,1);
  if (0xf < uVar5) {
    _free(pvVar15);
    return extraout_EAX_35;
  }
  FUN_00401830(s_rc_shadowlevel_00a14244);
  iVar3 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&iStack_138);
  if (0xf < uVar4) {
    _free(_Memory);
    return extraout_EAX_36;
  }
  FUN_00401830(s_rc_covermap_00a14254);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&uStack_140,1);
  if ((uint **)0xf < ppuStack_130) {
    _free((void *)0x1);
    return extraout_EAX_37;
  }
  in_ECX[5] = DAT_0099d0f4;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  *(undefined1 *)((int)in_ECX + 7) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 0xb) = 0;
  *(undefined1 *)(in_ECX + 3) = 1;
  *(undefined1 *)((int)in_ECX + 0xd) = 1;
  in_ECX[4] = 60000;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
  *(undefined1 *)(iVar3 + 0xc) = *(undefined1 *)(iVar2 + 0x5e);
  iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
  *(undefined1 *)(iVar3 + 0xd) = *(undefined1 *)(iVar2 + 0x5f);
  iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
  *(undefined1 *)(iVar3 + 6) = *(undefined1 *)(iVar2 + 0x61);
  iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
  *(undefined1 *)(iVar3 + 7) = *(undefined1 *)(iVar2 + 0x62);
  iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
  *(undefined1 *)(iVar3 + 9) = *(undefined1 *)(iVar2 + 3);
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xea) == '\0') {
    bVar1 = *(byte *)(iVar3 + 0xd);
    if (2 < bVar1) {
      bVar1 = 2;
    }
    *(byte *)(iVar3 + 0xd) = bVar1;
    bVar1 = *(byte *)(iVar3 + 0xc);
    *(undefined1 *)(iVar3 + 7) = 0;
    if (1 < bVar1) {
      bVar1 = 1;
    }
    *(byte *)(iVar3 + 0xc) = bVar1;
  }
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) == '\0') {
    *(undefined1 *)(iVar3 + 6) = 0;
    if (*(char *)(iVar3 + 0xc) != '\0') {
      *(undefined1 *)(iVar3 + 0xc) = 0;
      *(undefined1 *)(iVar3 + 9) = 0;
      return iVar3;
    }
    *(undefined1 *)(iVar3 + 0xc) = 0;
    *(undefined1 *)(iVar3 + 9) = 0;
  }
  return iVar3;
}


// ==== FUN_0087ee50 @ 0x0087ee50 ====

/* WARNING: Removing unreachable block (ram,0x0087f096) */
/* WARNING: Removing unreachable block (ram,0x0087f057) */
/* WARNING: Removing unreachable block (ram,0x0087f0d5) */
/* WARNING: Removing unreachable block (ram,0x0087f018) */

void FUN_0087ee50(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 auStackY_13c [128];
  undefined1 *_Memory;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  void *_Memory_00;
  void *_Memory_01;
  undefined4 *_Memory_02;
  uint uVar11;
  undefined4 uStack_30;
  void *local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  uStack_30 = (void **)0xe;
  *in_ECX = &PTR_FUN_00a146f0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  uStack_30 = &local_1c;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_10) {
    _free(unaff_EBP);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_14) {
    _free(unaff_ESI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_18) {
    _free(unaff_EDI);
    return;
  }
  local_18 = 0xf;
  local_1c = (void *)0x0;
  FUN_00401740();
  _Memory_02 = &uStack_30;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if ((void *)0xf < local_1c) {
    _free(uStack_30);
    return;
  }
  local_1c = (void *)0xf;
  uStack_30 = (void **)((uint)uStack_30 & 0xffffff00);
  FUN_00401740();
  _Memory_01 = (void *)((int)register0x00000010 + -0x34);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  _Memory_00 = (void *)((int)register0x00000010 + -0x38);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  puVar3 = auStackY_13c + 0x100;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  puVar2 = auStackY_13c + 0xfc;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_30 = (void **)0x0;
  FUN_00401740();
  puVar1 = auStackY_13c + 0xf8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_30) {
    _free(_Memory_02);
    return;
  }
  uStack_30 = (void **)0xf;
  uVar11 = 0;
  FUN_00401740();
  puVar6 = auStackY_13c + 0xf4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(_Memory_01);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar5 = auStackY_13c + 0xf0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(_Memory_00);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar4 = auStackY_13c + 0xec;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar3);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar3 = auStackY_13c + 0xe8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar2);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar2 = auStackY_13c + 0xe4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar1);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar1 = auStackY_13c + 0xe0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar6);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar6 = auStackY_13c + 0xdc;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar5);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar5 = auStackY_13c + 0xd8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar4);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar4 = auStackY_13c + 0xd4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar3);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar3 = auStackY_13c + 0xd0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar2);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar2 = auStackY_13c + 0xcc;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar1);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar1 = auStackY_13c + 200;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar6);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar6 = auStackY_13c + 0xc4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar5);
    return;
  }
  uVar11 = 0;
  FUN_00401740();
  puVar5 = auStackY_13c + 0xc0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar4);
    return;
  }
  uVar10 = 0;
  uVar11 = (uint)puVar4 & 0xffffff00;
  FUN_00401740();
  puVar4 = auStackY_13c + 0xbc;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar10) {
    _free(puVar3);
    return;
  }
  uVar9 = 0;
  uVar10 = (uint)puVar3 & 0xffffff00;
  FUN_00401740();
  puVar3 = auStackY_13c + 0xb8;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar9) {
    _free(puVar2);
    return;
  }
  uVar8 = 0;
  uVar9 = (uint)puVar2 & 0xffffff00;
  FUN_00401740();
  puVar2 = auStackY_13c + 0xb4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar8) {
    _free(puVar1);
    return;
  }
  uVar7 = 0;
  uVar8 = (uint)puVar1 & 0xffffff00;
  FUN_00401740();
  puVar1 = auStackY_13c + 0xb0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar7) {
    _free(puVar6);
    return;
  }
  FUN_00401830();
  _Memory = auStackY_13c + 0xac;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uVar11) {
    _free(puVar5);
    return;
  }
  FUN_00401830(s_rc_waterlevel_00a14408);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_13c + 0xa8);
  if (0xf < uVar10) {
    _free(puVar4);
    return;
  }
  FUN_00401830(s_rc_bumpmap_00a14418);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_13c + 0xa4);
  if (0xf < uVar9) {
    _free(puVar3);
    return;
  }
  FUN_00401830(s_rc_waterheight_00a14424);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_13c + 0xa0);
  if (0xf < uVar8) {
    _free(puVar2);
    return;
  }
  FUN_00401830(s_rc_shadowlevel_00a14434);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_13c + 0x9c);
  if ((undefined1 *)0xf < puVar6) {
    _free(puVar1);
    return;
  }
  FUN_00401830(s_rc_covermap_00a14444);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_13c + 0x98);
  if (puVar5 < (undefined1 *)0x10) {
    DAT_00b5ac00 = 0;
    *in_ECX = &PTR_FUN_00a146d0;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0087f6d0 @ 0x0087f6d0 ====

void FUN_0087f6d0(void)

{
  void *pvVar1;
  
  if (DAT_00b5ac00 == 0) {
    pvVar1 = operator_new(0x24);
    if (pvVar1 != (void *)0x0) {
      FUN_0087e3a0();
      return;
    }
  }
  return;
}


// ==== FUN_0087f6f0 @ 0x0087f6f0 ====

undefined4 FUN_0087f6f0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 ****ppppuVar4;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  int in_ECX;
  float10 fVar5;
  float10 extraout_ST0;
  undefined1 local_ac [36];
  undefined4 ****local_88 [4];
  undefined4 local_78;
  uint local_74;
  undefined1 local_70 [4];
  void *local_6c;
  uint local_58;
  
  local_74 = 0xf;
  local_78 = 0;
  local_88[0] = (undefined4 ****)((uint)local_88[0] & 0xffffff00);
  FUN_00401740(s_rc_wireframe_00a14450,0xc);
  ppppuVar4 = local_88[0];
  if (local_74 < 0x10) {
    ppppuVar4 = local_88;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),ppppuVar4,local_78);
  if (0xf < local_74) {
    _free(local_88[0]);
    return extraout_EAX;
  }
  if (iVar2 == 0) {
    uVar3 = FUN_00459160(local_70,0);
    uVar3 = thunk_FUN_00796e60(uVar3);
    if (local_58 < 0x10) {
      FUN_00855850(uVar3);
      return 1;
    }
    _free(local_6c);
    return extraout_EAX_00;
  }
  local_74 = 0xf;
  local_78 = 0;
  local_88[0] = (undefined4 ****)((uint)local_88[0] & 0xffffff00);
  FUN_00401740(s_rc_shadowvalue_00a14460,0xe);
  ppppuVar4 = local_88[0];
  if (local_74 < 0x10) {
    ppppuVar4 = local_88;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),ppppuVar4,local_78);
  if (0xf < local_74) {
    _free(local_88[0]);
    return extraout_EAX_01;
  }
  if (iVar2 == 0) {
    uVar3 = FUN_00459160(local_70,0);
    fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
    *(float *)(in_ECX + 0x18) = (float)fVar5;
    if (0xf < local_58) {
      _free(local_6c);
      return extraout_EAX_02;
    }
    uVar3 = FUN_00459160(local_70,1);
    fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
    *(float *)(in_ECX + 0x20) = (float)fVar5;
    if (0xf < local_58) {
      _free(local_6c);
      return extraout_EAX_03;
    }
    uVar3 = FUN_00459160(local_70,2);
    thunk_FUN_00796ec0(uVar3);
    *(float *)(in_ECX + 0x1c) = (float)extraout_ST0;
    if (local_58 < 0x10) {
      return 1;
    }
    _free(local_6c);
    return extraout_EAX_04;
  }
  local_74 = 0xf;
  local_78 = 0;
  local_88[0] = (undefined4 ****)((uint)local_88[0] & 0xffffff00);
  FUN_00401740(s_rc_windowmouse_00a14470,0xe);
  ppppuVar4 = local_88[0];
  if (local_74 < 0x10) {
    ppppuVar4 = local_88;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),ppppuVar4,local_78);
  if (0xf < local_74) {
    _free(local_88[0]);
    return extraout_EAX_05;
  }
  if (iVar2 == 0) {
    uVar3 = FUN_00459160(local_70,0);
    iVar2 = thunk_FUN_00796e60(uVar3);
    if (local_58 < 0x10) {
      FUN_00855c70(iVar2 != 0);
      return 1;
    }
    _free(local_6c);
    return extraout_EAX_06;
  }
  uVar3 = FUN_00401830(s_rc_skybox_00a14480);
  cVar1 = FUN_00423420(param_1 + 8,uVar3);
  if (0xf < local_58) {
    _free(local_6c);
    return extraout_EAX_07;
  }
  if (cVar1 == '\0') {
    uVar3 = FUN_00401830(s_rc_changesky_00a1448c);
    FUN_00423420(param_1 + 8,uVar3);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  uVar3 = FUN_00459160(local_ac,0);
  thunk_FUN_00796e60(uVar3);
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


