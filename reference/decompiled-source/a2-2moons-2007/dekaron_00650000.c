// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x650000-0x65ffff

// ==== FUN_006507e0 @ 0x006507e0 ====

void FUN_006507e0(uint param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 <= *(uint *)(in_ECX + 0x50c)) {
    param_1 = *(uint *)(in_ECX + 0x50c);
  }
  if (*(char *)(in_ECX + 0x512) == '\x01') {
    (**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x10) + 0x30))((undefined4 *)(in_ECX + 4));
    puVar2 = (undefined4 *)(in_ECX + 4);
    puVar3 = (undefined4 *)(in_ECX + 0x284);
    for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_0064fc70(param_1);
  }
  FUN_0064f950(param_1);
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_00650850 @ 0x00650850 ====

void FUN_00650850(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_retaddr;
  
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x10) + 0x30))((undefined4 *)(in_ECX + 4));
  puVar2 = (undefined4 *)(in_ECX + 4);
  puVar3 = (undefined4 *)(in_ECX + 0x284);
  for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_0064fc70(unaff_retaddr);
  FUN_0064f950(unaff_retaddr);
  *(undefined4 *)(in_ECX + 0x50c) = unaff_retaddr;
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_006508b0 @ 0x006508b0 ====

void FUN_006508b0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  uVar1 = FUN_00617e40();
  *(undefined4 *)(in_ECX + 0x508) = uVar1;
  FUN_00650850(param_1);
  return;
}


// ==== FUN_00650920 @ 0x00650920 ====

void FUN_00650920(byte param_1)

{
  void *in_ECX;
  
  FUN_0064f810();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00650940 @ 0x00650940 ====

undefined4 FUN_00650940(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x504);
}


// ==== FUN_00650950 @ 0x00650950 ====

undefined4 FUN_00650950(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50c);
}


// ==== FUN_00650960 @ 0x00650960 ====

void FUN_00650960(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_006509f0 @ 0x006509f0 ====

void FUN_006509f0(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_00650a20 @ 0x00650a20 ====

void FUN_00650a20(void)

{
  return;
}


// ==== FUN_00650a90 @ 0x00650a90 ====

undefined1 FUN_00650a90(void)

{
  return 0;
}


// ==== FUN_00650aa0 @ 0x00650aa0 ====

undefined1 FUN_00650aa0(void)

{
  return 0;
}


// ==== FUN_00650b30 @ 0x00650b30 ====

void FUN_00650b30(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bf58;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4f0c;
  in_ECX[0x141] = param_1;
  in_ECX[0x142] = 0;
  in_ECX[0x143] = 0;
  FUN_00797a50(in_ECX + 0x144,0,9);
  FUN_00797a50(in_ECX + 1,0,0x280);
  FUN_00797a50(in_ECX + 0xa1,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00650bd0 @ 0x00650bd0 ====

void FUN_00650bd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_00650be0 @ 0x00650be0 ====

void FUN_00650be0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x510) = 1;
  return;
}


// ==== FUN_00650bf0 @ 0x00650bf0 ====

void FUN_00650bf0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x511) = 1;
  return;
}


// ==== FUN_00650c00 @ 0x00650c00 ====

void FUN_00650c00(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x512) = 1;
  return;
}


// ==== FUN_00650c10 @ 0x00650c10 ====

void FUN_00650c10(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x513) = 1;
  return;
}


// ==== FUN_00650c20 @ 0x00650c20 ====

void FUN_00650c20(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x514) = 1;
  return;
}


// ==== FUN_00650c30 @ 0x00650c30 ====

void FUN_00650c30(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x515) = 1;
  return;
}


// ==== FUN_00650c40 @ 0x00650c40 ====

void FUN_00650c40(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x516) = 1;
  return;
}


// ==== FUN_00650c50 @ 0x00650c50 ====

void FUN_00650c50(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x517) = 1;
  return;
}


// ==== FUN_00650c70 @ 0x00650c70 ====

void FUN_00650c70(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = 0;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_00650cc0 @ 0x00650cc0 ====

void FUN_00650cc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_00650d10 @ 0x00650d10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00650d10(void)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  float unaff_EDI;
  float fVar5;
  float fVar6;
  float fStack_10;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  if (iVar2 == 0) {
    return;
  }
  iVar2 = (**(code **)(**(int **)(iVar2 + 0x50) + 0x24))();
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x24))();
  (**(code **)(*DAT_00b5a6b8 + 4))();
  iVar4 = (**(code **)(*piVar3 + 4))();
  fVar1 = (float)(*(int *)(in_ECX + 0x2a4) + *(int *)(iVar4 + 0x30));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x74))();
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x78))(0);
  fVar5 = (float)*(int *)(in_ECX + 0x2ac) * DAT_009a09b8 + (float)*(ushort *)(iVar4 + 0x34);
  if (*(int *)(iVar4 + 4) == 0) {
    iVar2 = *(int *)(iVar2 + 0x1a8);
  }
  else {
    if (*(int *)(iVar4 + 4) != 1) goto LAB_00650ddb;
    iVar2 = *(int *)(iVar2 + 0x208);
  }
  fVar5 = (float)iVar2 * DAT_009a09b8 + fVar5;
LAB_00650ddb:
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x7c))(fVar5);
  fVar5 = (float)*(int *)(in_ECX + 0x2b4) * DAT_009a09b8;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x84))(fVar5);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x88))(0);
  piVar3 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x44) + 0x14))();
  iVar2 = (**(code **)(*piVar3 + 0xc))();
  if (0.0 < *(float *)(iVar2 + 4)) {
    fVar6 = 0.0;
    if (*(int *)(in_ECX + 0x50c) + 500U < (uint)fStack_10) {
      iVar2 = (int)fStack_10 - *(int *)(in_ECX + 0x50c);
      fVar6 = (float)iVar2;
      if (iVar2 < 0) {
        fVar6 = fVar6 + _DAT_0099d104;
      }
      fVar6 = fVar6 * DAT_0099d0ec;
      *(float *)(in_ECX + 0x50c) = fStack_10;
    }
    iVar2 = (**(code **)(*piVar3 + 0xc))();
    fStack_10 = (fVar1 - unaff_EDI) * fVar6 + *(float *)(iVar2 + 4);
    if (fVar5 < fStack_10) {
      fStack_10 = fVar5;
    }
    if (fStack_10 <= DAT_0099d080) {
      fStack_10 = DAT_0099d080;
    }
    fVar5 = fStack_10;
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x6c))(fStack_10);
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x70))(0);
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x8c))(0);
    (**(code **)(*piVar3 + 0x14))(fStack_10);
    (**(code **)(*piVar3 + 0x20))(0);
    (**(code **)(*piVar3 + 0x1c))(fVar1);
    (**(code **)(*piVar3 + 0x18))(fVar5);
    (**(code **)(*piVar3 + 0x28))(0);
    (**(code **)(*piVar3 + 0x2c))(0);
    (**(code **)(*piVar3 + 0x34))(0);
    return;
  }
  *(float *)(in_ECX + 0x50c) = fStack_10;
  return;
}


// ==== FUN_00651070 @ 0x00651070 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00651070(undefined4 param_1)

{
  byte bVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int in_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  byte bVar9;
  undefined4 unaff_EBP;
  undefined4 unaff_EDI;
  float fVar10;
  float fVar11;
  uint uStack_118;
  uint uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  float fStack_ec;
  float fStack_e8;
  uint uStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  uint uStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  undefined1 *puStack_bc;
  float fStack_b8;
  uint *puStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  int iStack_90;
  undefined4 uStack_8c;
  int iStack_88;
  undefined4 uStack_84;
  int iStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  int iStack_74;
  int iStack_70;
  int *piStack_6c;
  undefined1 *puStack_68;
  uint *puStack_64;
  uint *puStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  int iStack_3c;
  undefined1 auStack_38 [4];
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  uint uStack_28;
  uint uStack_24;
  int iStack_20;
  int iStack_1c;
  
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  if (piVar3 == (int *)0x0) {
    return;
  }
  uStack_50 = param_1;
  uStack_54 = 0x65109a;
  (**(code **)(*piVar3 + 0x14))();
  uStack_54 = 0x6510a2;
  iVar4 = (**(code **)(*(int *)piVar3[0x14] + 0x24))();
  uStack_54 = 0x6510b3;
  iStack_3c = iVar4;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x24))();
  uStack_54 = 0x6510ba;
  iVar5 = (**(code **)(*piVar3 + 4))();
  uStack_54 = CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 0x2c));
  uStack_58 = 0x6510cc;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x54))();
  uStack_58._0_1_ = 0;
  uStack_58._1_3_ = 0;
  uStack_5c = 0x6510d9;
  uVar6 = (**(code **)(**(int **)(in_ECX + 0x508) + 0x58))();
  uStack_5c = CONCAT31((int3)((uint)uVar6 >> 8),*(undefined1 *)(iVar5 + 0x10c));
  puStack_60 = (uint *)0x6510ee;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xbc))();
  puStack_60 = (uint *)0x6510f9;
  iVar7 = (**(code **)(*DAT_00b5a6b8 + 4))();
  fVar11 = (float)(*(int *)(in_ECX + 0x30c) + 100);
  fVar10 = ((float)*(ushort *)(iVar5 + 0x104) + (float)*(int *)(in_ECX + 0x304)) * fVar11 *
           DAT_009a09b8 * *(float *)(iVar7 + 0x10);
  fVar11 = ((float)*(ushort *)(iVar5 + 0x106) + (float)*(int *)(in_ECX + 0x308)) * fVar11 *
           DAT_009a09b8 * *(float *)(iVar7 + 0x10);
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  if (fVar11 < 0.0) {
    fVar11 = 0.0;
  }
  iStack_20 = (int)fVar10;
  iStack_1c = iStack_20;
  if (iStack_20 <= (int)fVar11) {
    iStack_1c = (int)fVar11;
  }
  fVar11 = (float)(*(int *)(in_ECX + 0x30c) + 100);
  fVar10 = ((float)*(ushort *)(iVar5 + 0x1a0) + (float)*(int *)(in_ECX + 0x304)) * fVar11 *
           DAT_009a09b8 * *(float *)(iVar7 + 0x10);
  fVar11 = ((float)*(ushort *)(iVar5 + 0x1a2) + (float)*(int *)(in_ECX + 0x308)) * fVar11 *
           DAT_009a09b8 * *(float *)(iVar7 + 0x10);
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  if (fVar11 < 0.0) {
    fVar11 = 0.0;
  }
  iStack_30 = (int)fVar10;
  iStack_2c = iStack_30;
  if (iStack_30 <= (int)fVar11) {
    iStack_2c = (int)fVar11;
  }
  uStack_28 = (uint)*(ushort *)(iVar5 + 0x108);
  uStack_24 = uStack_28;
  if (uStack_28 <= *(ushort *)(iVar5 + 0x10a)) {
    uStack_24 = (uint)*(ushort *)(iVar5 + 0x10a);
  }
  puStack_60 = &uStack_28;
  puStack_64 = (uint *)0x651225;
  iStack_34 = iVar7;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))();
  puStack_64 = &uStack_24;
  puStack_68 = (undefined1 *)0x651238;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x9c))();
  puStack_68 = auStack_38;
  piStack_6c = (int *)0x65124b;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xa0))();
  piStack_6c = &iStack_3c;
  iStack_70 = 0x65125e;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xa4))();
  fVar10 = (float)(*(int *)(in_ECX + 0x3ac) + 100);
  iStack_70 = (int)(((float)*(ushort *)(iVar5 + 0x38) + (float)*(int *)(in_ECX + 0x3a8)) * fVar10 *
                    DAT_009a09b8 * *(float *)(iVar7 + 0x18));
  iStack_74 = (int)(((float)*(ushort *)(iVar5 + 0x36) + (float)*(int *)(in_ECX + 0x3a4)) * fVar10 *
                    DAT_009a09b8 * *(float *)(iVar7 + 0x18));
  uStack_78 = 0x6512cd;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc0))();
  iVar8 = (uint)*(byte *)(iVar5 + 0x3e) + *(int *)(in_ECX + 0x2e4) + *(int *)(in_ECX + 0x300);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x1fc) + *(int *)(iVar4 + 0x1e0);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x25c) + *(int *)(iVar4 + 0x240);
  }
  if (iVar8 < 0) {
    iVar8 = 0;
LAB_00651313:
    bVar1 = (byte)iVar8;
    if (0x4b < bVar1) goto LAB_00651317;
    uStack_24 = CONCAT31(uStack_24._1_3_,100);
    if (bVar1 < 0x65) goto LAB_00651324;
  }
  else {
    if ((byte)iVar8 < 0x65) goto LAB_00651313;
LAB_00651317:
    bVar1 = 0x4b;
LAB_00651324:
    uStack_24 = CONCAT31(uStack_24._1_3_,bVar1);
  }
  uStack_78 = uStack_24;
  uStack_7c = 0;
  iStack_80 = 0x65133d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar8 = (uint)*(byte *)(iVar5 + 0x3f) + *(int *)(in_ECX + 0x2e8) + *(int *)(in_ECX + 0x300);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x1fc) + *(int *)(iVar4 + 0x1e4);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x25c) + *(int *)(iVar4 + 0x244);
  }
  if (iVar8 < 0) {
    iVar8 = 0;
LAB_00651383:
    bVar1 = (byte)iVar8;
    if (0x4b < bVar1) goto LAB_00651387;
    iStack_2c = CONCAT31(iStack_2c._1_3_,100);
    if (bVar1 < 0x65) goto LAB_00651394;
  }
  else {
    if ((byte)iVar8 < 0x65) goto LAB_00651383;
LAB_00651387:
    bVar1 = 0x4b;
LAB_00651394:
    iStack_2c = CONCAT31(iStack_2c._1_3_,bVar1);
  }
  iStack_80 = iStack_2c;
  uStack_84 = 1;
  iStack_88 = 0x6513ad;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar8 = (uint)*(byte *)(iVar5 + 0x40) + *(int *)(in_ECX + 0x2ec) + *(int *)(in_ECX + 0x300);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x1fc) + *(int *)(iVar4 + 0x1e8);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x25c) + *(int *)(iVar4 + 0x248);
  }
  if (iVar8 < 0) {
    iVar8 = 0;
LAB_006513f3:
    bVar1 = (byte)iVar8;
    if (0x4b < bVar1) goto LAB_006513f7;
    iStack_34 = CONCAT31(iStack_34._1_3_,100);
    if (bVar1 < 0x65) goto LAB_00651404;
  }
  else {
    if ((byte)iVar8 < 0x65) goto LAB_006513f3;
LAB_006513f7:
    bVar1 = 0x4b;
LAB_00651404:
    iStack_34 = CONCAT31(iStack_34._1_3_,bVar1);
  }
  iStack_88 = iStack_34;
  uStack_8c = 2;
  iStack_90 = 0x65141d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar8 = (uint)*(byte *)(iVar5 + 0x41) + *(int *)(in_ECX + 0x2f0) + *(int *)(in_ECX + 0x300);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x1fc) + *(int *)(iVar4 + 0x1ec);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x25c) + *(int *)(iVar4 + 0x24c);
  }
  if (iVar8 < 0) {
    iVar8 = 0;
LAB_00651463:
    bVar1 = (byte)iVar8;
    if (0x4b < bVar1) goto LAB_00651467;
    iStack_3c = CONCAT31(iStack_3c._1_3_,100);
    if (bVar1 < 0x65) goto LAB_00651474;
  }
  else {
    if ((byte)iVar8 < 0x65) goto LAB_00651463;
LAB_00651467:
    bVar1 = 0x4b;
LAB_00651474:
    iStack_3c = CONCAT31(iStack_3c._1_3_,bVar1);
  }
  iStack_90 = iStack_3c;
  uStack_94 = 3;
  uStack_98 = 0x65148d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar8 = (uint)*(byte *)(iVar5 + 0x42) + *(int *)(in_ECX + 0x2f4) + *(int *)(in_ECX + 0x300);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x1fc) + *(int *)(iVar4 + 0x1f0);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x25c) + *(int *)(iVar4 + 0x250);
  }
  if (iVar8 < 0) {
    iVar8 = 0;
LAB_006514d3:
    bVar1 = (byte)iVar8;
    if (0x4b < bVar1) goto LAB_006514d7;
    unaff_EDI = CONCAT31((int3)((uint)unaff_EDI >> 8),100);
    uStack_98 = unaff_EDI;
    if (bVar1 < 0x65) goto LAB_006514e4;
  }
  else {
    if ((byte)iVar8 < 0x65) goto LAB_006514d3;
LAB_006514d7:
    bVar1 = 0x4b;
LAB_006514e4:
    uStack_98 = CONCAT31((int3)((uint)unaff_EDI >> 8),bVar1);
  }
  uStack_9c = 4;
  uStack_a0 = 0x6514fd;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar8 = (uint)*(byte *)(iVar5 + 0x3d) + *(int *)(in_ECX + 0x2f8);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar8 = iVar8 + *(int *)(iVar4 + 500);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar8 = iVar8 + *(int *)(iVar4 + 0x254);
  }
  if (iVar8 < 0) {
    iVar8 = 0;
LAB_0065152d:
    bVar1 = (byte)iVar8;
    if (0x4b < bVar1) goto LAB_00651531;
    unaff_EBP = CONCAT31((int3)((uint)unaff_EBP >> 8),100);
    uStack_a0 = unaff_EBP;
    if (bVar1 < 0x65) goto LAB_0065153e;
  }
  else {
    if ((byte)iVar8 < 0x65) goto LAB_0065152d;
LAB_00651531:
    bVar1 = 0x4b;
LAB_0065153e:
    uStack_a0 = CONCAT31((int3)((uint)unaff_EBP >> 8),bVar1);
  }
  uStack_a4 = 5;
  uStack_a8 = 0x651557;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  uStack_a8 = 0;
  uStack_ac = 0x651567;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x104))();
  iVar4 = *(int *)(in_ECX + 0x364);
  if (iVar4 < 0) {
    iVar4 = 0;
LAB_0065157e:
    uStack_58._0_1_ = (undefined1)iVar4;
  }
  else {
    uStack_58._0_1_ = 0xfa;
    if ((byte)iVar4 < 0xfb) goto LAB_0065157e;
  }
  uStack_ac._0_1_ = (undefined1)uStack_58;
  uStack_ac._1_3_ = uStack_58._1_3_;
  uStack_b0 = 0;
  puStack_b4 = (uint *)0x651597;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar4 = *(int *)(in_ECX + 0x368);
  if (iVar4 < 0) {
    iVar4 = 0;
LAB_006515ae:
    puStack_60 = (uint *)CONCAT31(puStack_60._1_3_,(char)iVar4);
  }
  else {
    puStack_60 = (uint *)CONCAT31(puStack_60._1_3_,0xfa);
    if ((byte)iVar4 < 0xfb) goto LAB_006515ae;
  }
  puStack_b4 = puStack_60;
  fStack_b8 = 1.4013e-45;
  puStack_bc = (undefined1 *)0x6515c7;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar4 = *(int *)(in_ECX + 0x36c);
  if (iVar4 < 0) {
    iVar4 = 0;
LAB_006515de:
    puStack_68 = (undefined1 *)CONCAT31(puStack_68._1_3_,(char)iVar4);
  }
  else {
    puStack_68 = (undefined1 *)CONCAT31(puStack_68._1_3_,0xfa);
    if ((byte)iVar4 < 0xfb) goto LAB_006515de;
  }
  puStack_bc = puStack_68;
  fStack_c0 = 2.8026e-45;
  fStack_c4 = 9.283265e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar4 = *(int *)(in_ECX + 0x370);
  if (iVar4 < 0) {
    iVar4 = 0;
LAB_0065160e:
    iStack_70 = CONCAT31(iStack_70._1_3_,(char)iVar4);
  }
  else {
    iStack_70 = CONCAT31(iStack_70._1_3_,0xfa);
    if ((byte)iVar4 < 0xfb) goto LAB_0065160e;
  }
  fStack_c4 = (float)iStack_70;
  fStack_c8 = 4.2039e-45;
  uStack_cc = 0x651627;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar4 = *(int *)(in_ECX + 0x374);
  if (iVar4 < 0) {
    iVar4 = 0;
LAB_0065163e:
    uStack_78 = CONCAT31(uStack_78._1_3_,(char)iVar4);
  }
  else {
    uStack_78 = CONCAT31(uStack_78._1_3_,0xfa);
    if ((byte)iVar4 < 0xfb) goto LAB_0065163e;
  }
  uStack_cc = uStack_78;
  uStack_d0 = 4;
  uStack_d4 = 0x651657;
  uVar6 = (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_d4._0_1_ = *(undefined1 *)(iVar7 + 0xd);
  uStack_d8._1_3_ = (undefined3)((uint)uVar6 >> 8);
  uStack_d8._0_1_ = *(undefined1 *)(iVar7 + 0xc);
  uStack_dc = 0x65166d;
  uStack_d4._1_3_ = uStack_d8._1_3_;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xcc))();
  uStack_dc = 0x96;
  fStack_e0 = 9.283457e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd4))();
  iVar4 = *(int *)(in_ECX + 0x324) + 100;
  if (iVar4 < 200) {
    if (-1 < iVar4) goto LAB_00651694;
    bVar1 = 0;
LAB_0065169c:
    uStack_cc = CONCAT31(uStack_cc._1_3_,bVar1);
  }
  else {
    iVar4 = 200;
LAB_00651694:
    bVar1 = (byte)iVar4;
    uStack_cc = CONCAT31(uStack_cc._1_3_,200);
    if (bVar1 < 0xc9) goto LAB_0065169c;
  }
  iVar4 = *(int *)(in_ECX + 0x330) + 100;
  if (iVar4 < 200) {
    if (-1 < iVar4) goto LAB_006516af;
    bVar1 = 0;
LAB_006516b3:
    bVar9 = bVar1;
  }
  else {
    iVar4 = 200;
LAB_006516af:
    bVar1 = (byte)iVar4;
    bVar9 = 200;
    if (bVar1 < 0xc9) goto LAB_006516b3;
  }
  fStack_e0 = 9.283552e-39;
  puStack_bc._0_1_ = bVar9;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 8))();
  fStack_e0 = 9.283562e-39;
  piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
  fVar10 = (float)(uStack_cc & 0xff);
  if ((uStack_cc & 0xff) < 100) {
    fVar10 = fVar10 * DAT_009a09b8;
    fVar11 = DAT_0099d0f8;
  }
  else {
    fVar10 = (fVar10 - DAT_0099de78) * _DAT_009b832c;
    fVar11 = DAT_0099d080;
  }
  fVar11 = fVar11 - fVar10;
  if (fVar11 <= DAT_0099d0f8) {
    fStack_c4 = DAT_009b8328;
    if (DAT_009b8328 <= fVar11) goto LAB_00651737;
  }
  else {
    fVar11 = DAT_0099d0f8;
LAB_00651737:
    fStack_c4 = fVar11;
  }
  fStack_e0 = 9.283735e-39;
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  fStack_b8 = *(float *)(iVar4 + 0x968) * *(float *)(iVar5 + 0x48);
  if (bVar9 < 100) {
    fVar10 = (float)bVar9 * _DAT_009b836c + DAT_009a09b8;
  }
  else {
    fVar10 = ((float)bVar9 - DAT_0099de78) * _DAT_009b836c + DAT_0099d080;
  }
  if (fVar10 <= DAT_009b8368) {
    fStack_c0 = DAT_009a09b8;
    if (fVar10 < DAT_009a09b8) goto LAB_006517b4;
  }
  else {
    fVar10 = DAT_009b8368;
  }
  fStack_c0 = fVar10;
LAB_006517b4:
  fStack_e0 = fStack_c4;
  uStack_e4 = uStack_cc;
  fStack_e8 = 9.283922e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe0))();
  fStack_e8 = fStack_c8 * fStack_c0;
  fStack_ec = fStack_c4;
  uStack_f0 = 0x6517f1;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe8))();
  uStack_f0 = 0x3f800000;
  uStack_f4 = 0x651804;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe4))();
  uStack_cc = (uint)*(ushort *)(in_ECX + 0x344);
  if ((int)(9999 - uStack_cc) < 1) {
    uStack_cc = 9999;
  }
  else {
    uStack_cc = (-1 < (int)-uStack_cc) - 1 & uStack_cc;
  }
  uStack_f4 = 0x651845;
  uVar2 = FUN_00802534();
  uStack_d0 = CONCAT22(uStack_d0._2_2_,9999);
  if (uVar2 < 10000) {
    uStack_d0 = CONCAT22(uStack_d0._2_2_,uVar2);
  }
  uStack_f4 = uStack_d0;
  uStack_f8 = 0x65186a;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xec))();
  fVar10 = fStack_e0;
  iVar4 = (uint)*(byte *)(iVar5 + 0x3c) + *(int *)(in_ECX + 0x34c);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar4 = iVar4 + *(int *)((int)fStack_e0 + 0x1c4);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar4 = iVar4 + *(int *)((int)fStack_e0 + 0x224);
  }
  uStack_f8._0_1_ = (iVar4 < 0) - 1U & (byte)iVar4;
  uStack_f8._1_3_ = uStack_cc._1_3_;
  uStack_fc = 0x6518b3;
  uStack_cc._0_1_ = (byte)uStack_f8;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xfc))();
  iVar4 = (uint)*(byte *)(iVar5 + 0x3a) + *(int *)(in_ECX + 0x350);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar4 = iVar4 + *(int *)((int)fVar10 + 0x1c8);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar4 = iVar4 + *(int *)((int)fVar10 + 0x228);
  }
  uStack_fc._0_1_ = *(undefined1 *)(iVar5 + 0x3b);
  uStack_fc._1_3_ = (undefined3)((uint)iVar4 >> 8);
  uStack_d0 = CONCAT31(uStack_d0._1_3_,(iVar4 < 0) - 1U & (byte)iVar4);
  uStack_100 = uStack_d0;
  uStack_104 = 0x6518fc;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x100))();
  iVar4 = *(int *)(in_ECX + 0x348);
  if (*(int *)(iVar5 + 4) == 0) {
    iVar4 = iVar4 + *(int *)((int)fVar10 + 0x1c0);
  }
  else if (*(int *)(iVar5 + 4) == 1) {
    iVar4 = iVar4 + *(int *)((int)fVar10 + 0x220);
  }
  uStack_d8 = CONCAT31(uStack_d8._1_3_,(iVar4 < 0) - 1U & (byte)iVar4);
  uVar6 = uStack_d8;
  uStack_104 = uStack_d8;
  uStack_108 = 0x65193d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf0))();
  uStack_108 = uVar6;
  uStack_10c = 0x65194c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf4))();
  uStack_10c = uVar6;
  uStack_110 = 0x65195b;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf8))();
  bVar1 = *(byte *)(in_ECX + 900);
  uStack_e4 = CONCAT31(uStack_e4._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    puStack_bc = (undefined1 *)CONCAT31(puStack_bc._1_3_,0xfa);
  }
  else {
    puStack_bc = (undefined1 *)CONCAT31(puStack_bc._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  uStack_110 = puStack_bc;
  uStack_114 = 0;
  uStack_118 = 0x65199f;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar1 = *(byte *)(in_ECX + 0x388);
  fStack_ec = (float)CONCAT31(fStack_ec._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    fStack_c4 = (float)CONCAT31(fStack_c4._1_3_,0xfa);
  }
  else {
    fStack_c4 = (float)CONCAT31(fStack_c4._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  uStack_118 = (uint)fStack_c4;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(1);
  bVar1 = *(byte *)(in_ECX + 0x38c);
  uStack_f4 = CONCAT31(uStack_f4._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_cc = CONCAT31(uStack_cc._1_3_,0xfa);
  }
  else {
    uStack_cc = CONCAT31(uStack_cc._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(2,uStack_cc);
  bVar1 = *(byte *)(in_ECX + 0x390);
  uStack_fc = CONCAT31(uStack_fc._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_d4 = CONCAT31(uStack_d4._1_3_,0xfa);
  }
  else {
    uStack_d4 = CONCAT31(uStack_d4._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(3,uStack_d4);
  bVar1 = *(byte *)(in_ECX + 0x394);
  uStack_104 = CONCAT31(uStack_104._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_dc = CONCAT31(uStack_dc._1_3_,0xfa);
  }
  else {
    uStack_dc = CONCAT31(uStack_dc._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(4,uStack_dc);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(0,*(undefined4 *)(in_ECX + 0x3e4));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(1,*(undefined4 *)(in_ECX + 1000));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(2,*(undefined4 *)(in_ECX + 0x3ec));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(3,*(undefined4 *)(in_ECX + 0x3f0));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(4,*(undefined4 *)(in_ECX + 0x3f4));
  uStack_118 = (uint)*(ushort *)(iVar5 + 0x108);
  uStack_114 = uStack_118;
  if (uStack_118 <= *(ushort *)(iVar5 + 0x10a)) {
    uStack_114 = (uint)*(ushort *)(iVar5 + 0x10a);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))(&uStack_118);
  iVar7 = (uint)*(byte *)(iVar5 + 0xfc) + *(int *)(in_ECX + 0x3b0);
  iVar4 = (uint)*(byte *)(iVar5 + 0xfd) + *(int *)(in_ECX + 0x3b0);
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (99 < iVar7) {
    iVar7 = 100;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  else if (99 < iVar4) {
    iVar4 = 100;
  }
  if (iVar4 <= iVar7) {
    iVar4 = iVar7 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xdc))(iVar7,iVar4);
  piVar3 = (int *)(**(code **)(*DAT_00b5abc4 + 8))
                            (CONCAT22(extraout_var_00,*(undefined2 *)(iVar5 + 0x24)));
  if (piVar3 == (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x128))(1);
    (**(code **)(**(int **)(in_ECX + 0x508) + 300))(0x3f800000);
    return;
  }
  iVar4 = **(int **)(in_ECX + 0x508);
  iVar5 = (**(code **)(*piVar3 + 4))();
  (**(code **)(iVar4 + 0x128))(*(undefined4 *)(iVar5 + 4));
  iVar4 = **(int **)(in_ECX + 0x508);
  iVar5 = (**(code **)(*piVar3 + 4))();
  (**(code **)(iVar4 + 300))(*(undefined4 *)(iVar5 + 8));
  return;
}


// ==== FUN_00651c40 @ 0x00651c40 ====

void FUN_00651c40(uint param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 <= *(uint *)(in_ECX + 0x50c)) {
    param_1 = *(uint *)(in_ECX + 0x50c);
  }
  if (*(char *)(in_ECX + 0x512) == '\x01') {
    (**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x10) + 0x30))((undefined4 *)(in_ECX + 4));
    puVar2 = (undefined4 *)(in_ECX + 4);
    puVar3 = (undefined4 *)(in_ECX + 0x284);
    for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_00651070(param_1);
  }
  FUN_00650d10(param_1);
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_00651cb0 @ 0x00651cb0 ====

void FUN_00651cb0(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_retaddr;
  
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x10) + 0x30))((undefined4 *)(in_ECX + 4));
  puVar2 = (undefined4 *)(in_ECX + 4);
  puVar3 = (undefined4 *)(in_ECX + 0x284);
  for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00651070(unaff_retaddr);
  FUN_00650d10(unaff_retaddr);
  *(undefined4 *)(in_ECX + 0x50c) = unaff_retaddr;
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_00651d10 @ 0x00651d10 ====

void FUN_00651d10(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  uVar1 = FUN_00618320();
  *(undefined4 *)(in_ECX + 0x508) = uVar1;
  FUN_00651cb0(param_1);
  return;
}


// ==== FUN_00651d80 @ 0x00651d80 ====

void FUN_00651d80(byte param_1)

{
  void *in_ECX;
  
  FUN_00650bd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00651da0 @ 0x00651da0 ====

undefined4 FUN_00651da0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x504);
}


// ==== FUN_00651db0 @ 0x00651db0 ====

undefined4 FUN_00651db0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50c);
}


// ==== FUN_00651dc0 @ 0x00651dc0 ====

void FUN_00651dc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_00651e50 @ 0x00651e50 ====

void FUN_00651e50(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_00651ee0 @ 0x00651ee0 ====

undefined1 FUN_00651ee0(void)

{
  return 0;
}


// ==== FUN_00651ef0 @ 0x00651ef0 ====

undefined1 FUN_00651ef0(void)

{
  return 0;
}


// ==== FUN_00651f80 @ 0x00651f80 ====

void FUN_00651f80(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bf78;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4f5c;
  in_ECX[0x141] = param_1;
  in_ECX[0x142] = 0;
  in_ECX[0x143] = 0;
  *(undefined1 *)((int)in_ECX + 0x519) = 0;
  FUN_00797a50(in_ECX + 0x144,0,9);
  FUN_00797a50(in_ECX + 1,0,0x280);
  FUN_00797a50(in_ECX + 0xa1,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00652010 @ 0x00652010 ====

void FUN_00652010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_00652020 @ 0x00652020 ====

void FUN_00652020(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x510) = 1;
  return;
}


// ==== FUN_00652030 @ 0x00652030 ====

void FUN_00652030(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x511) = 1;
  return;
}


// ==== FUN_00652040 @ 0x00652040 ====

void FUN_00652040(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x512) = 1;
  return;
}


// ==== FUN_00652050 @ 0x00652050 ====

void FUN_00652050(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x513) = 1;
  return;
}


// ==== FUN_00652060 @ 0x00652060 ====

void FUN_00652060(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x514) = 1;
  return;
}


// ==== FUN_00652070 @ 0x00652070 ====

void FUN_00652070(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x515) = 1;
  return;
}


// ==== FUN_00652080 @ 0x00652080 ====

void FUN_00652080(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x516) = 1;
  return;
}


// ==== FUN_00652090 @ 0x00652090 ====

void FUN_00652090(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x517) = 1;
  return;
}


// ==== FUN_006520b0 @ 0x006520b0 ====

void FUN_006520b0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = 0;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_00652100 @ 0x00652100 ====

void FUN_00652100(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_00652260 @ 0x00652260 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00652260(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int in_ECX;
  byte bVar7;
  byte bVar8;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  float fVar9;
  float fVar10;
  uint uStack_114;
  uint uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  float fStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  float fStack_e8;
  undefined4 uStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  float fStack_c8;
  undefined4 uStack_c4;
  float fStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined1 uStack_b0;
  undefined3 uStack_af;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  int iStack_74;
  uint uStack_70;
  int *piStack_6c;
  int *piStack_68;
  uint *puStack_64;
  uint *puStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  uStack_54 = 0x652274;
  iVar1 = (**(code **)(*DAT_00b5a6b8 + 4))();
  uStack_54 = 0x652281;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  uStack_54 = 0x652288;
  iVar3 = (**(code **)(*piVar2 + 4))();
  uStack_54 = CONCAT22(extraout_var,*(undefined2 *)(iVar3 + 0x4c));
  uStack_58 = 0x65229a;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x54))();
  uStack_58 = 0;
  uStack_5c = 0x6522a7;
  uVar4 = (**(code **)(**(int **)(in_ECX + 0x508) + 0x58))();
  uStack_5c = CONCAT31((int3)((uint)uVar4 >> 8),*(undefined1 *)(iVar3 + 0x164));
  puStack_60 = (uint *)0x6522bc;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xbc))();
  fVar10 = (float)(*(int *)(in_ECX + 0x30c) + 100);
  fVar9 = ((float)*(ushort *)(iVar3 + 0x15c) + (float)*(int *)(in_ECX + 0x304)) * fVar10 *
          DAT_009a09b8 * *(float *)(iVar1 + 0x10);
  fVar10 = ((float)*(ushort *)(iVar3 + 0x15e) + (float)*(int *)(in_ECX + 0x308)) * fVar10 *
           DAT_009a09b8 * *(float *)(iVar1 + 0x10);
  if (fVar9 < 0.0) {
    fVar9 = 0.0;
  }
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  iStack_2c = (int)fVar9;
  iStack_28 = iStack_2c;
  if (iStack_2c <= (int)fVar10) {
    iStack_28 = (int)fVar10;
  }
  fVar10 = (float)(*(int *)(in_ECX + 0x30c) + 100);
  fVar9 = ((float)*(ushort *)(iVar3 + 0x1f8) + (float)*(int *)(in_ECX + 0x304)) * fVar10 *
          DAT_009a09b8 * *(float *)(iVar1 + 0x10);
  fVar10 = ((float)*(ushort *)(iVar3 + 0x1fa) + (float)*(int *)(in_ECX + 0x308)) * fVar10 *
           DAT_009a09b8 * *(float *)(iVar1 + 0x10);
  if (fVar9 < 0.0) {
    fVar9 = 0.0;
  }
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  iStack_24 = (int)fVar9;
  iStack_20 = iStack_24;
  if (iStack_24 <= (int)fVar10) {
    iStack_20 = (int)fVar10;
  }
  fVar10 = (float)(*(int *)(in_ECX + 0x318) + 100);
  fVar9 = ((float)*(int *)(in_ECX + 0x310) + (float)*(ushort *)(iVar3 + 0x1f8)) * fVar10 *
          DAT_009a09b8 * *(float *)(iVar1 + 0x10);
  fVar10 = ((float)*(int *)(in_ECX + 0x314) + (float)*(ushort *)(iVar3 + 0x1fa)) * fVar10 *
           DAT_009a09b8 * *(float *)(iVar1 + 0x10);
  if (fVar9 < 0.0) {
    fVar9 = 0.0;
  }
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  iStack_1c = (int)fVar9;
  iStack_18 = iStack_1c;
  if (iStack_1c <= (int)fVar10) {
    iStack_18 = (int)fVar10;
  }
  uStack_34 = (uint)*(ushort *)(iVar3 + 0x160);
  uStack_30 = uStack_34;
  if (uStack_34 <= *(ushort *)(iVar3 + 0x162)) {
    uStack_30 = (uint)*(ushort *)(iVar3 + 0x162);
  }
  puStack_60 = &uStack_34;
  puStack_64 = (uint *)0x65245f;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))();
  puStack_64 = &uStack_30;
  piStack_68 = (int *)0x652472;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x9c))();
  piStack_68 = &iStack_2c;
  piStack_6c = (int *)0x652485;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xa0))();
  piStack_6c = &iStack_28;
  uStack_70 = 0x652498;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xa4))();
  fVar9 = (float)(*(int *)(in_ECX + 0x3ac) + 100);
  uStack_70 = (uint)(((float)*(ushort *)(iVar3 + 0x58) + (float)*(int *)(in_ECX + 0x3a8)) * fVar9 *
                     DAT_009a09b8 * *(float *)(iVar1 + 0x18));
  iStack_74 = (int)(((float)*(ushort *)(iVar3 + 0x56) + (float)*(int *)(in_ECX + 0x3a4)) * fVar9 *
                    DAT_009a09b8 * *(float *)(iVar1 + 0x18));
  uStack_78 = 0x652507;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc0))();
  iVar1 = (uint)*(byte *)(iVar3 + 0x5e) + *(int *)(in_ECX + 0x2e4) + *(int *)(in_ECX + 0x300);
  if (iVar1 < 0) {
    iVar1 = 0;
    puStack_60 = (uint *)((uint)puStack_60 & 0xffffff00);
  }
  else if (100 < (byte)iVar1) {
    iVar1 = 100;
  }
  puStack_60 = (uint *)CONCAT31(puStack_60._1_3_,(char)iVar1);
  uStack_78 = (uint)puStack_60;
  uStack_7c = 0;
  uStack_80 = 0x652541;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar1 = (uint)*(byte *)(iVar3 + 0x5f) + *(int *)(in_ECX + 0x2e8) + *(int *)(in_ECX + 0x300);
  if (iVar1 < 0) {
    iVar1 = 0;
    piStack_68 = (int *)((uint)piStack_68 & 0xffffff00);
  }
  else if (100 < (byte)iVar1) {
    iVar1 = 100;
  }
  piStack_68 = (int *)CONCAT31(piStack_68._1_3_,(char)iVar1);
  uStack_80 = (uint)piStack_68;
  uStack_84 = 1;
  uStack_88 = 0x65257b;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar1 = (uint)*(byte *)(iVar3 + 0x60) + *(int *)(in_ECX + 0x2ec) + *(int *)(in_ECX + 0x300);
  if (iVar1 < 0) {
    iVar1 = 0;
    uStack_70 = uStack_70 & 0xffffff00;
  }
  else if (100 < (byte)iVar1) {
    iVar1 = 100;
  }
  uStack_70 = CONCAT31(uStack_70._1_3_,(char)iVar1);
  uStack_88 = uStack_70;
  uStack_8c = 2;
  uStack_90 = 0x6525b5;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar1 = (uint)*(byte *)(iVar3 + 0x61) + *(int *)(in_ECX + 0x2f0) + *(int *)(in_ECX + 0x300);
  if (iVar1 < 0) {
    iVar1 = 0;
    uStack_78 = uStack_78 & 0xffffff00;
  }
  else if (100 < (byte)iVar1) {
    iVar1 = 100;
  }
  uStack_78 = CONCAT31(uStack_78._1_3_,(char)iVar1);
  uStack_90 = uStack_78;
  uStack_94 = 3;
  uStack_98 = 0x6525ef;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar1 = (uint)*(byte *)(iVar3 + 0x62) + *(int *)(in_ECX + 0x2f4) + *(int *)(in_ECX + 0x300);
  if (iVar1 < 0) {
    iVar1 = 0;
    uStack_80 = uStack_80 & 0xffffff00;
  }
  else if (100 < (byte)iVar1) {
    iVar1 = 100;
  }
  uStack_98._0_1_ = (undefined1)iVar1;
  uStack_98._1_3_ = uStack_80._1_3_;
  uStack_9c = 4;
  uStack_a0 = 0x652629;
  uStack_80._0_1_ = (undefined1)uStack_98;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar1 = (uint)*(byte *)(iVar3 + 0x5d) + *(int *)(in_ECX + 0x2f8);
  if (iVar1 < 0) {
    iVar1 = 0;
    uStack_88 = uStack_88 & 0xffffff00;
  }
  else if (100 < (byte)iVar1) {
    iVar1 = 100;
  }
  uStack_a0._0_1_ = (undefined1)iVar1;
  uStack_a0._1_3_ = uStack_88._1_3_;
  uStack_a4 = 5;
  uStack_a8 = 0x65265d;
  uStack_88._0_1_ = (undefined1)uStack_a0;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  uStack_a8._0_1_ = 0;
  uStack_a8._1_3_ = 0;
  uStack_ac = 0x65266d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x104))();
  iVar1 = *(int *)(in_ECX + 0x364);
  if (iVar1 < 0) {
    iVar1 = 0;
LAB_006526e2:
    uStack_98._0_1_ = (undefined1)iVar1;
  }
  else {
    uStack_98._0_1_ = 0xfa;
    if ((byte)iVar1 < 0xfb) goto LAB_006526e2;
  }
  uStack_ac._0_1_ = (undefined1)uStack_98;
  uStack_ac._1_3_ = uStack_98._1_3_;
  uStack_b0 = 0;
  uStack_af = 0;
  uStack_b4 = 0x6526fb;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar1 = *(int *)(in_ECX + 0x368);
  if (iVar1 < 0) {
    iVar1 = 0;
LAB_00652711:
    uStack_a0._0_1_ = (undefined1)iVar1;
  }
  else {
    uStack_a0._0_1_ = 0xfa;
    if ((byte)iVar1 < 0xfb) goto LAB_00652711;
  }
  uStack_b4._0_1_ = (undefined1)uStack_a0;
  uStack_b4._1_3_ = uStack_a0._1_3_;
  uStack_b8._0_1_ = 1;
  uStack_b8._1_3_ = 0;
  uStack_bc = 0x65272a;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar1 = *(int *)(in_ECX + 0x36c);
  if (iVar1 < 0) {
    iVar1 = 0;
LAB_00652740:
    uStack_a8._0_1_ = (undefined1)iVar1;
  }
  else {
    uStack_a8._0_1_ = 0xfa;
    if ((byte)iVar1 < 0xfb) goto LAB_00652740;
  }
  uStack_bc._0_1_ = (undefined1)uStack_a8;
  uStack_bc._1_3_ = uStack_a8._1_3_;
  fStack_c0 = 2.8026e-45;
  uStack_c4 = 0x652759;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar1 = *(int *)(in_ECX + 0x370);
  if (iVar1 < 0) {
    iVar1 = 0;
LAB_0065276f:
    uStack_b0 = (undefined1)iVar1;
  }
  else {
    uStack_b0 = 0xfa;
    if ((byte)iVar1 < 0xfb) goto LAB_0065276f;
  }
  uStack_c4._0_1_ = uStack_b0;
  uStack_c4._1_3_ = uStack_af;
  fStack_c8 = 4.2039e-45;
  uStack_cc = 0x652788;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar1 = *(int *)(in_ECX + 0x374);
  if (iVar1 < 0) {
    iVar1 = 0;
LAB_0065279e:
    uStack_b8._0_1_ = (undefined1)iVar1;
  }
  else {
    uStack_b8._0_1_ = 0xfa;
    if ((byte)iVar1 < 0xfb) goto LAB_0065279e;
  }
  uStack_cc._0_1_ = (undefined1)uStack_b8;
  uStack_cc._1_3_ = uStack_b8._1_3_;
  uStack_d0 = 4;
  uStack_d4 = 0x6527b7;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_d4 = 100;
  uStack_d8 = 100;
  uStack_dc = 0x6527c9;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xcc))();
  uStack_dc = 0x96;
  fStack_e0 = 9.289684e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd4))();
  iVar1 = *(int *)(in_ECX + 0x324) + 100;
  if (iVar1 < 200) {
    if (-1 < iVar1) goto LAB_006527f1;
    bVar8 = 0;
LAB_006527f7:
    bVar7 = bVar8;
  }
  else {
    iVar1 = 200;
LAB_006527f1:
    bVar8 = (byte)iVar1;
    bVar7 = 200;
    if (bVar8 < 0xc9) goto LAB_006527f7;
  }
  iVar1 = *(int *)(in_ECX + 0x330) + 100;
  uStack_c4 = CONCAT31(uStack_c4._1_3_,bVar7);
  if (iVar1 < 200) {
    if (-1 < iVar1) goto LAB_00652812;
    bVar8 = 0;
LAB_00652818:
    bVar6 = bVar8;
  }
  else {
    iVar1 = 200;
LAB_00652812:
    bVar8 = (byte)iVar1;
    bVar6 = 200;
    if (bVar8 < 0xc9) goto LAB_00652818;
  }
  uStack_bc = CONCAT31(uStack_bc._1_3_,bVar6);
  if (bVar7 < 100) {
    fVar9 = DAT_0099d0f8 - (float)bVar7 * DAT_009a09b8;
  }
  else {
    fVar9 = DAT_0099d080 - ((float)bVar7 - DAT_0099de78) * _DAT_009b832c;
  }
  if (fVar9 <= DAT_0099d0f8) {
    fStack_c8 = DAT_009b8328;
    if (DAT_009b8328 <= fVar9) goto LAB_006528a3;
  }
  else {
    fVar9 = DAT_0099d0f8;
LAB_006528a3:
    fStack_c8 = fVar9;
  }
  uStack_b8 = *(undefined4 *)(iVar3 + 0x68);
  if (bVar6 < 100) {
    fVar9 = (float)bVar6 * _DAT_009b836c + DAT_009a09b8;
  }
  else {
    fVar9 = ((float)bVar6 - DAT_0099de78) * _DAT_009b836c + DAT_0099d080;
  }
  if (fVar9 <= DAT_009b8368) {
    fStack_c0 = DAT_009a09b8;
    if (DAT_009a09b8 <= fVar9) goto LAB_006528fb;
  }
  else {
    fVar9 = DAT_009b8368;
LAB_006528fb:
    fStack_c0 = fVar9;
  }
  fStack_e0 = fStack_c8;
  uStack_e4 = uStack_c4;
  fStack_e8 = 9.290128e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe0))();
  fStack_e8 = fStack_c8 * fStack_c0;
  uStack_ec = uStack_c4;
  uStack_f0 = 0x65293e;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe8))();
  uStack_f0 = 0x3f800000;
  uStack_f4 = 0x652951;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe4))();
  uStack_f4 = 0;
  fStack_f8 = 9.290229e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xec))();
  bVar8 = *(byte *)(iVar3 + 0x5c);
  if (100 < bVar8) {
    bVar8 = 100;
  }
  bVar7 = *(byte *)(in_ECX + 0x34c);
  if (*(int *)(in_ECX + 0x34c) < 1) {
    if (bVar8 < bVar7) {
      bVar8 = 0;
    }
    else {
      bVar8 = bVar8 - bVar7;
      fStack_e0 = (float)CONCAT31(fStack_e0._1_3_,100);
      if (100 < bVar8) goto LAB_006529be;
    }
  }
  else {
    if ((int)(100 - (uint)bVar7) <= (int)(uint)bVar8) {
      fStack_e0 = (float)CONCAT31(fStack_e0._1_3_,100);
      goto LAB_006529be;
    }
    if ((int)(uint)bVar8 <= (int)-(uint)bVar7) {
      fStack_e0 = (float)((uint)fStack_e0._1_3_ << 8);
      goto LAB_006529be;
    }
    bVar8 = bVar8 + bVar7;
  }
  fStack_e0 = (float)CONCAT31(fStack_e0._1_3_,bVar8);
LAB_006529be:
  fStack_f8 = fStack_e0;
  uStack_fc = 0x6529d1;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xfc))();
  iVar1 = (uint)*(byte *)(iVar3 + 0x5a) + *(int *)(in_ECX + 0x350);
  uStack_fc._0_1_ = *(undefined1 *)(iVar3 + 0x5b);
  uStack_fc._1_3_ = (undefined3)((uint)iVar1 >> 8);
  uStack_d4 = CONCAT31(uStack_d4._1_3_,(iVar1 < 0) - 1U & (byte)iVar1);
  uStack_100 = uStack_d4;
  uStack_104 = 0x6529fe;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x100))();
  bVar8 = *(byte *)(in_ECX + 0x348);
  uStack_dc = CONCAT31(uStack_dc._1_3_,bVar8);
  if ((int)(100 - (uint)bVar8) < 1) {
    uStack_ec = CONCAT31(uStack_ec._1_3_,100);
  }
  else {
    uStack_ec = CONCAT31(uStack_ec._1_3_,(-1 < (int)-(uint)bVar8) - 1U & bVar8);
  }
  uVar4 = uStack_ec;
  uStack_104 = uStack_ec;
  uStack_108 = 0x652a40;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf0))();
  uStack_108 = uVar4;
  uStack_10c = 0x652a4f;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf4))();
  uStack_10c = uVar4;
  uStack_110 = 0x652a5e;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf8))();
  bVar8 = *(byte *)(in_ECX + 900);
  fStack_e8 = (float)CONCAT31(fStack_e8._1_3_,bVar8);
  if ((int)(0xfa - (uint)bVar8) < 1) {
    uStack_fc = CONCAT31(uStack_fc._1_3_,0xfa);
  }
  else {
    uStack_fc = CONCAT31(uStack_fc._1_3_,(-1 < (int)-(uint)bVar8) - 1U & bVar8);
  }
  uStack_110 = uStack_fc;
  uStack_114 = 0;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar8 = *(byte *)(in_ECX + 0x388);
  uStack_f0 = CONCAT31(uStack_f0._1_3_,bVar8);
  if ((int)(0xfa - (uint)bVar8) < 1) {
    uStack_104 = CONCAT31(uStack_104._1_3_,0xfa);
  }
  else {
    uStack_104 = CONCAT31(uStack_104._1_3_,(-1 < (int)-(uint)bVar8) - 1U & bVar8);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(1,uStack_104);
  bVar8 = *(byte *)(in_ECX + 0x38c);
  fStack_f8 = (float)CONCAT31(fStack_f8._1_3_,bVar8);
  if ((int)(0xfa - (uint)bVar8) < 1) {
    uStack_10c = CONCAT31(uStack_10c._1_3_,0xfa);
  }
  else {
    uStack_10c = CONCAT31(uStack_10c._1_3_,(-1 < (int)-(uint)bVar8) - 1U & bVar8);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(2,uStack_10c);
  bVar8 = *(byte *)(in_ECX + 0x390);
  uStack_100 = CONCAT31(uStack_100._1_3_,bVar8);
  if ((int)(0xfa - (uint)bVar8) < 1) {
    uStack_114 = CONCAT31(uStack_114._1_3_,0xfa);
  }
  else {
    uStack_114 = CONCAT31(uStack_114._1_3_,(-1 < (int)-(uint)bVar8) - 1U & bVar8);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(3,uStack_114);
  bVar8 = *(byte *)(in_ECX + 0x394);
  uStack_108 = CONCAT31(uStack_108._1_3_,bVar8);
  if ((int)(0xfa - (uint)bVar8) < 1) {
    bVar8 = 0xfa;
  }
  else {
    bVar8 = (-1 < (int)-(uint)bVar8) - 1U & bVar8;
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(4,bVar8);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(0,*(undefined4 *)(in_ECX + 0x3e4));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(1,*(undefined4 *)(in_ECX + 1000));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(2,*(undefined4 *)(in_ECX + 0x3ec));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(3,*(undefined4 *)(in_ECX + 0x3f0));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(4,*(undefined4 *)(in_ECX + 0x3f4));
  uStack_114 = (uint)*(ushort *)(iVar3 + 0x160);
  uStack_110 = uStack_114;
  if (uStack_114 <= *(ushort *)(iVar3 + 0x162)) {
    uStack_110 = (uint)*(ushort *)(iVar3 + 0x162);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))(&uStack_114);
  iVar5 = (uint)*(byte *)(iVar3 + 0x154) + *(int *)(in_ECX + 0x3b0);
  iVar1 = (uint)*(byte *)(iVar3 + 0x155) + *(int *)(in_ECX + 0x3b0);
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (99 < iVar5) {
    iVar5 = 100;
  }
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (99 < iVar1) {
    iVar1 = 100;
  }
  if (iVar1 <= iVar5) {
    iVar1 = iVar5 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xdc))(iVar5,iVar1);
  piVar2 = (int *)(**(code **)(*DAT_00b5abc4 + 8))
                            (CONCAT22(extraout_var_00,*(undefined2 *)(iVar3 + 0x44)));
  if (piVar2 == (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x128))(1);
    (**(code **)(**(int **)(in_ECX + 0x508) + 300))(0x3f800000);
    return;
  }
  iVar1 = **(int **)(in_ECX + 0x508);
  iVar3 = (**(code **)(*piVar2 + 4))();
  (**(code **)(iVar1 + 0x128))(*(undefined4 *)(iVar3 + 4));
  iVar1 = **(int **)(in_ECX + 0x508);
  iVar3 = (**(code **)(*piVar2 + 4))();
  (**(code **)(iVar1 + 300))(*(undefined4 *)(iVar3 + 8));
  return;
}


// ==== FUN_00652d30 @ 0x00652d30 ====

bool FUN_00652d30(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x504) + 0x4c);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if ((iVar2 == 8) || (iVar2 == 9)) {
    return *(char *)(in_ECX + 0x519) != '\x01';
  }
  piVar1 = *(int **)(*(int *)(in_ECX + 0x504) + 0x44);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (*(float *)(iVar2 + 4) == DAT_0099cdc8) {
    return true;
  }
  return false;
}


// ==== FUN_00652da0 @ 0x00652da0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00652da0(void)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  float unaff_EBX;
  float unaff_ESI;
  float unaff_EDI;
  float fVar6;
  float fStack_c;
  
  iVar3 = (**(code **)(*DAT_00b5a6b8 + 4))();
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  iVar5 = (**(code **)(*piVar4 + 4))();
  fVar1 = (float)(*(int *)(in_ECX + 0x2a4) + *(int *)(iVar5 + 0x50)) * *(float *)(iVar3 + 0x58);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x74))(fVar1);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x78))(0);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x7c))
            (((float)*(ushort *)(iVar5 + 0x54) + (float)*(int *)(in_ECX + 0x2ac) * DAT_009a09b8) *
             *(float *)(iVar3 + 0x5c));
  fVar6 = (float)*(int *)(in_ECX + 0x2b4) * DAT_009a09b8 * *(float *)(iVar3 + 0x60);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x84))();
  piVar4 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x44) + 0x14))();
  cVar2 = FUN_00652d30();
  if (cVar2 == '\x01') {
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x6c))(0);
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x70))(0);
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x8c))(0);
    (**(code **)(*piVar4 + 0x14))(0);
    (**(code **)(*piVar4 + 0x18))(0);
    (**(code **)(*piVar4 + 0x20))(0);
    (**(code **)(*piVar4 + 0x24))(0);
    (**(code **)(*piVar4 + 0x2c))(0);
    (**(code **)(*piVar4 + 0x30))(0);
    (**(code **)(*piVar4 + 0x40))(0,fVar6);
    (**(code **)(*piVar4 + 0x44))(0,fVar6);
    *(float *)(in_ECX + 0x50c) = fVar6;
    return;
  }
  fVar6 = 0.0;
  if (*(int *)(in_ECX + 0x50c) + 500U < (uint)fStack_c) {
    iVar3 = (int)fStack_c - *(int *)(in_ECX + 0x50c);
    fVar6 = (float)iVar3;
    if (iVar3 < 0) {
      fVar6 = fVar6 + _DAT_0099d104;
    }
    fVar6 = fVar6 * DAT_0099d0ec;
    *(float *)(in_ECX + 0x50c) = fStack_c;
  }
  iVar3 = (**(code **)(*piVar4 + 0xc))();
  fStack_c = (unaff_EDI - unaff_ESI) * fVar6 + *(float *)(iVar3 + 4);
  if (unaff_EBX < fStack_c) {
    fStack_c = unaff_EBX;
  }
  if (fStack_c <= DAT_0099d080) {
    fStack_c = DAT_0099d080;
  }
  fVar6 = fStack_c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x6c))(fStack_c);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x70))(0);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x8c))(0);
  (**(code **)(*piVar4 + 0x14))(fStack_c);
  (**(code **)(*piVar4 + 0x20))(0);
  (**(code **)(*piVar4 + 0x1c))(fVar1);
  (**(code **)(*piVar4 + 0x18))(fVar6);
  (**(code **)(*piVar4 + 0x28))(0);
  (**(code **)(*piVar4 + 0x24))(0);
  (**(code **)(*piVar4 + 0x2c))(0);
  (**(code **)(*piVar4 + 0x30))(0);
  return;
}


// ==== FUN_00653020 @ 0x00653020 ====

void FUN_00653020(uint param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 <= *(uint *)(in_ECX + 0x50c)) {
    param_1 = *(uint *)(in_ECX + 0x50c);
  }
  if (*(char *)(in_ECX + 0x512) == '\x01') {
    (**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x10) + 0x30))((undefined4 *)(in_ECX + 4));
    puVar2 = (undefined4 *)(in_ECX + 4);
    puVar3 = (undefined4 *)(in_ECX + 0x284);
    for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_00652260(param_1);
  }
  FUN_00652da0(param_1);
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_00653090 @ 0x00653090 ====

void FUN_00653090(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_retaddr;
  
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x10) + 0x30))((undefined4 *)(in_ECX + 4));
  puVar2 = (undefined4 *)(in_ECX + 4);
  puVar3 = (undefined4 *)(in_ECX + 0x284);
  for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00652260(unaff_retaddr);
  FUN_00652da0(unaff_retaddr);
  *(undefined4 *)(in_ECX + 0x50c) = unaff_retaddr;
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_006530f0 @ 0x006530f0 ====

void FUN_006530f0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  *(undefined1 *)(in_ECX + 0x519) = 1;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  uVar1 = FUN_006189a0();
  *(undefined4 *)(in_ECX + 0x508) = uVar1;
  FUN_00653090(param_1);
  *(undefined1 *)(in_ECX + 0x519) = 0;
  return;
}


// ==== FUN_00653170 @ 0x00653170 ====

void FUN_00653170(byte param_1)

{
  void *in_ECX;
  
  FUN_00652010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00653190 @ 0x00653190 ====

undefined4 FUN_00653190(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa04);
}


// ==== FUN_006531a0 @ 0x006531a0 ====

void FUN_006531a0(void)

{
  return;
}


// ==== FUN_006531b0 @ 0x006531b0 ====

undefined4 FUN_006531b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_006531c0 @ 0x006531c0 ====

void FUN_006531c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_00653270 @ 0x00653270 ====

void FUN_00653270(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  FUN_00797a50(in_ECX + 0x504,0,0x280);
  FUN_00797a50(in_ECX + 0x784,0,0x280);
  return;
}


// ==== FUN_00653380 @ 0x00653380 ====

undefined1 FUN_00653380(void)

{
  return 0;
}


// ==== FUN_00653390 @ 0x00653390 ====

undefined1 FUN_00653390(void)

{
  return 0;
}


// ==== FUN_006533d0 @ 0x006533d0 ====

void FUN_006533d0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bf98;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4fac;
  in_ECX[0x281] = param_1;
  in_ECX[0x282] = 0;
  in_ECX[0x283] = 0;
  FUN_00797a50(in_ECX + 0x284,0,9);
  FUN_00653270();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00653440 @ 0x00653440 ====

void FUN_00653440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_00653450 @ 0x00653450 ====

void FUN_00653450(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa10) = 1;
  return;
}


// ==== FUN_00653460 @ 0x00653460 ====

void FUN_00653460(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa11) = 1;
  return;
}


// ==== FUN_00653470 @ 0x00653470 ====

void FUN_00653470(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa12) = 1;
  return;
}


// ==== FUN_00653480 @ 0x00653480 ====

void FUN_00653480(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa13) = 1;
  return;
}


// ==== FUN_00653490 @ 0x00653490 ====

void FUN_00653490(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa14) = 1;
  return;
}


// ==== FUN_006534a0 @ 0x006534a0 ====

void FUN_006534a0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa15) = 1;
  return;
}


// ==== FUN_006534b0 @ 0x006534b0 ====

void FUN_006534b0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa16) = 1;
  return;
}


// ==== FUN_006534c0 @ 0x006534c0 ====

void FUN_006534c0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa17) = 1;
  return;
}


// ==== FUN_006534e0 @ 0x006534e0 ====

void FUN_006534e0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_00653270();
  return;
}


// ==== FUN_00653510 @ 0x00653510 ====

void FUN_00653510(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_00653670 @ 0x00653670 ====

void FUN_00653670(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_00653270();
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_006536c0 @ 0x006536c0 ====

void FUN_006536c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00653440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006536e0 @ 0x006536e0 ====

undefined4 FUN_006536e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa04);
}


// ==== FUN_006536f0 @ 0x006536f0 ====

void FUN_006536f0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 0xa08);
  iVar2 = (**(code **)(**(int **)(in_ECX + 0xa04) + 0x1c))(param_1);
  (**(code **)(iVar1 + 0x58))(*(undefined1 *)(iVar2 + 0x46));
  return;
}


// ==== FUN_00653720 @ 0x00653720 ====

undefined4 FUN_00653720(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_00653730 @ 0x00653730 ====

void FUN_00653730(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_006537e0 @ 0x006537e0 ====

void FUN_006537e0(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  FUN_00797a50(in_ECX + 0x504,0,0x280);
  FUN_00797a50(in_ECX + 0x784,0,0x280);
  return;
}


// ==== FUN_00653900 @ 0x00653900 ====

undefined1 FUN_00653900(void)

{
  return 0;
}


// ==== FUN_00653910 @ 0x00653910 ====

undefined1 FUN_00653910(void)

{
  return 0;
}


// ==== FUN_00653950 @ 0x00653950 ====

void FUN_00653950(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bfb8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4ffc;
  in_ECX[0x281] = param_1;
  in_ECX[0x282] = 0;
  FUN_00797a50(in_ECX + 0x284,0,9);
  FUN_006537e0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_006539c0 @ 0x006539c0 ====

void FUN_006539c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_006539d0 @ 0x006539d0 ====

void FUN_006539d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa10) = 1;
  return;
}


// ==== FUN_006539e0 @ 0x006539e0 ====

void FUN_006539e0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa11) = 1;
  return;
}


// ==== FUN_006539f0 @ 0x006539f0 ====

void FUN_006539f0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa12) = 1;
  return;
}


// ==== FUN_00653a00 @ 0x00653a00 ====

void FUN_00653a00(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa13) = 1;
  return;
}


// ==== FUN_00653a10 @ 0x00653a10 ====

void FUN_00653a10(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa14) = 1;
  return;
}


// ==== FUN_00653a20 @ 0x00653a20 ====

void FUN_00653a20(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa15) = 1;
  return;
}


// ==== FUN_00653a30 @ 0x00653a30 ====

void FUN_00653a30(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa16) = 1;
  return;
}


// ==== FUN_00653a40 @ 0x00653a40 ====

void FUN_00653a40(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa17) = 1;
  return;
}


// ==== FUN_00653a60 @ 0x00653a60 ====

void FUN_00653a60(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_006537e0();
  return;
}


// ==== FUN_00653a90 @ 0x00653a90 ====

void FUN_00653a90(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_00653bf0 @ 0x00653bf0 ====

void FUN_00653bf0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  uVar1 = (**(code **)(**(int **)(*(int *)(in_ECX + 0xa04) + 0x50) + 0x14))(param_1);
  *(undefined4 *)(in_ECX + 0xa08) = uVar1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_006537e0();
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_00653c50 @ 0x00653c50 ====

void FUN_00653c50(byte param_1)

{
  void *in_ECX;
  
  FUN_006539c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00653c70 @ 0x00653c70 ====

undefined4 FUN_00653c70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa04);
}


// ==== FUN_00653c80 @ 0x00653c80 ====

void FUN_00653c80(void)

{
  return;
}


// ==== FUN_00653c90 @ 0x00653c90 ====

undefined4 FUN_00653c90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_00653ca0 @ 0x00653ca0 ====

void FUN_00653ca0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_00653d50 @ 0x00653d50 ====

void FUN_00653d50(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  FUN_00797a50(in_ECX + 0x504,0,0x280);
  FUN_00797a50(in_ECX + 0x784,0,0x280);
  return;
}


// ==== FUN_00653e60 @ 0x00653e60 ====

undefined1 FUN_00653e60(void)

{
  return 0;
}


// ==== FUN_00653e70 @ 0x00653e70 ====

undefined1 FUN_00653e70(void)

{
  return 0;
}


// ==== FUN_00653eb0 @ 0x00653eb0 ====

void FUN_00653eb0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bfd8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d504c;
  in_ECX[0x281] = param_1;
  in_ECX[0x282] = 0;
  in_ECX[0x283] = 0;
  FUN_00797a50(in_ECX + 0x284,0,9);
  FUN_00653d50();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00653f20 @ 0x00653f20 ====

void FUN_00653f20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_00653f30 @ 0x00653f30 ====

void FUN_00653f30(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa10) = 1;
  return;
}


// ==== FUN_00653f40 @ 0x00653f40 ====

void FUN_00653f40(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa11) = 1;
  return;
}


// ==== FUN_00653f50 @ 0x00653f50 ====

void FUN_00653f50(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa12) = 1;
  return;
}


// ==== FUN_00653f60 @ 0x00653f60 ====

void FUN_00653f60(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa13) = 1;
  return;
}


// ==== FUN_00653f70 @ 0x00653f70 ====

void FUN_00653f70(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa14) = 1;
  return;
}


// ==== FUN_00653f80 @ 0x00653f80 ====

void FUN_00653f80(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa15) = 1;
  return;
}


// ==== FUN_00653f90 @ 0x00653f90 ====

void FUN_00653f90(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa16) = 1;
  return;
}


// ==== FUN_00653fa0 @ 0x00653fa0 ====

void FUN_00653fa0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa17) = 1;
  return;
}


// ==== FUN_00653fc0 @ 0x00653fc0 ====

void FUN_00653fc0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_00653d50();
  return;
}


// ==== FUN_00653ff0 @ 0x00653ff0 ====

void FUN_00653ff0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_00654150 @ 0x00654150 ====

void FUN_00654150(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_00653d50();
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_006541a0 @ 0x006541a0 ====

void FUN_006541a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00653f20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006541c0 @ 0x006541c0 ====

void FUN_006541c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5098;
  return;
}


// ==== FUN_006541d0 @ 0x006541d0 ====

void FUN_006541d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5098;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006541f0 @ 0x006541f0 ====

undefined4 FUN_006541f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00654200 @ 0x00654200 ====

undefined1 FUN_00654200(void)

{
  return 0;
}


// ==== FUN_00654210 @ 0x00654210 ====

bool FUN_00654210(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x2c))();
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 8) == 0x50a;
}


// ==== FUN_00654240 @ 0x00654240 ====

undefined4 FUN_00654240(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00654250 @ 0x00654250 ====

undefined1 FUN_00654250(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_00654260 @ 0x00654260 ====

void FUN_00654260(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00654270 @ 0x00654270 ====

void FUN_00654270(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d50c8;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_006542a0 @ 0x006542a0 ====

void FUN_006542a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bff8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d50c8;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00654300 @ 0x00654300 ====

byte FUN_00654300(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_00654340 @ 0x00654340 ====

undefined4 FUN_00654340(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_00654360 @ 0x00654360 ====

undefined4 FUN_00654360(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_00654370 @ 0x00654370 ====

undefined4 FUN_00654370(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_006543d0 @ 0x006543d0 ====

void FUN_006543d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006542a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006543f0 @ 0x006543f0 ====

undefined4 FUN_006543f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00654400 @ 0x00654400 ====

undefined1 FUN_00654400(void)

{
  return 0;
}


// ==== FUN_00654410 @ 0x00654410 ====

int FUN_00654410(int *param_1)

{
  int iVar1;
  uint3 uVar2;
  
  (**(code **)(*param_1 + 0x2c))();
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  iVar1 = *(int *)(iVar1 + 8);
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if (((((iVar1 == 1) || (iVar1 == 2)) || (iVar1 == 0x11)) || ((iVar1 == 0x12 || (iVar1 == 3)))) ||
     ((iVar1 == 0xc || ((iVar1 == 0x800 || (iVar1 == 0x900)))))) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


// ==== FUN_00654460 @ 0x00654460 ====

undefined1 FUN_00654460(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_00654470 @ 0x00654470 ====

void FUN_00654470(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00654480 @ 0x00654480 ====

void FUN_00654480(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d50f8;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_006544b0 @ 0x006544b0 ====

void FUN_006544b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c018;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d50f8;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00654510 @ 0x00654510 ====

byte FUN_00654510(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_00654550 @ 0x00654550 ====

undefined4 FUN_00654550(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_00654570 @ 0x00654570 ====

undefined4 FUN_00654570(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_00654580 @ 0x00654580 ====

undefined4 FUN_00654580(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00654590 @ 0x00654590 ====

undefined4 FUN_00654590(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_006545f0 @ 0x006545f0 ====

void FUN_006545f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006544b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00654610 @ 0x00654610 ====

undefined4 FUN_00654610(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00654620 @ 0x00654620 ====

undefined1 FUN_00654620(void)

{
  return 0;
}


// ==== FUN_00654630 @ 0x00654630 ====

bool FUN_00654630(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 4) == 4;
}


// ==== FUN_00654650 @ 0x00654650 ====

undefined4 FUN_00654650(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00654660 @ 0x00654660 ====

undefined1 FUN_00654660(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_00654670 @ 0x00654670 ====

void FUN_00654670(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00654680 @ 0x00654680 ====

void FUN_00654680(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5128;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_006546b0 @ 0x006546b0 ====

void FUN_006546b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c038;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5128;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00654710 @ 0x00654710 ====

byte FUN_00654710(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_00654750 @ 0x00654750 ====

undefined4 FUN_00654750(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_00654770 @ 0x00654770 ====

undefined4 FUN_00654770(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_00654780 @ 0x00654780 ====

undefined4 FUN_00654780(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_006548c0 @ 0x006548c0 ====

void FUN_006548c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006546b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006548e0 @ 0x006548e0 ====

undefined4 FUN_006548e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_006548f0 @ 0x006548f0 ====

undefined1 FUN_006548f0(void)

{
  return 1;
}


// ==== FUN_00654900 @ 0x00654900 ====

bool FUN_00654900(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 4) == 4;
}


// ==== FUN_00654920 @ 0x00654920 ====

undefined4 FUN_00654920(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00654930 @ 0x00654930 ====

undefined1 FUN_00654930(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_00654940 @ 0x00654940 ====

void FUN_00654940(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00654950 @ 0x00654950 ====

void FUN_00654950(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5158;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00654980 @ 0x00654980 ====

void FUN_00654980(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c058;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5158;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006549e0 @ 0x006549e0 ====

byte FUN_006549e0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  short *psVar5;
  short *psVar6;
  int *in_ECX;
  byte bVar7;
  uint uVar8;
  
  if (param_1 == (int *)0x0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x2c))();
  iVar2 = *(int *)(iVar2 + 8);
  iVar3 = (**(code **)(*in_ECX + 4))();
  iVar3 = (**(code **)(*(int *)in_ECX[3] + 0x1c))(5 - (uint)(iVar3 != 4));
  if (iVar3 == 0) {
    if (in_ECX[1] == 0) {
      if ((iVar2 == 0x40f) || (iVar2 == 0x410)) {
        return 0;
      }
      return 1;
    }
  }
  else {
    cVar1 = (**(code **)(*DAT_00b5a734 + 0xc))(param_1,iVar3);
    if (cVar1 == '\0') {
      return 0;
    }
    if (in_ECX[1] == 0) {
      return 1;
    }
    piVar4 = (int *)(**(code **)(*param_1 + 0x48))();
    iVar2 = (**(code **)(*piVar4 + 4))();
    if (*(int *)(iVar2 + 0xc) == 0x100) {
      uVar8 = 0;
      iVar2 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
      if (*(char *)(iVar2 + 0x1e) != '\0') {
        do {
          iVar2 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
          if (*(short *)(iVar2 + 4 + uVar8 * 2) == 0) {
            return 4;
          }
          bVar7 = (char)uVar8 + 1;
          uVar8 = (uint)bVar7;
          iVar2 = (**(code **)(*(int *)in_ECX[1] + 0x14))();
        } while (bVar7 < *(byte *)(iVar2 + 0x1e));
        return 3;
      }
    }
    else {
      psVar5 = (short *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
      psVar6 = (short *)(**(code **)(*param_1 + 0x14))();
      if (((*psVar5 == *psVar6) &&
          (iVar2 = (**(code **)(*(int *)in_ECX[1] + 0x14))(), *(char *)(iVar2 + 0x21) == '\x01')) &&
         (iVar2 = (**(code **)(*param_1 + 0x14))(), *(char *)(iVar2 + 0x21) == '\x01')) {
        return 5;
      }
    }
  }
  return 3;
}


// ==== FUN_00654b20 @ 0x00654b20 ====

undefined4 FUN_00654b20(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_00654b40 @ 0x00654b40 ====

undefined4 FUN_00654b40(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_00654b50 @ 0x00654b50 ====

undefined4 FUN_00654b50(int *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  short *psVar4;
  short *psVar5;
  int *piVar6;
  int iVar7;
  int in_ECX;
  undefined2 extraout_var;
  
  piVar3 = param_1;
  if ((param_1 == (int *)0x0) || (*(int *)(in_ECX + 4) == 0)) {
    return 0;
  }
  psVar4 = (short *)(**(code **)(*param_1 + 0x14))();
  psVar5 = (short *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  if (*psVar4 != *psVar5) {
    return 0;
  }
  piVar6 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar7 = (**(code **)(*piVar6 + 4))();
  if (*(ushort *)(iVar7 + 0x76) < 2) {
    return 0;
  }
  iVar7 = (**(code **)(*piVar6 + 4))();
  uVar1 = *(ushort *)(iVar7 + 0x76);
  uVar2 = psVar5[6];
  if (uVar2 < uVar1) {
    param_1 = (int *)CONCAT22((short)((uint)psVar5 >> 0x10),psVar4[6]);
    if ((int)(uint)(ushort)psVar4[6] <= (int)((uint)uVar1 - (uint)uVar2)) {
      (**(code **)(**(int **)(in_ECX + 4) + 0x20))((int)param_1 + CONCAT22(extraout_var,uVar2));
      (**(code **)(*piVar3 + 0x20))(0);
      return 1;
    }
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))(uVar1);
    (**(code **)(*piVar3 + 0x20))(psVar4[6] - (uVar1 - uVar2));
  }
  return 1;
}


// ==== FUN_00654c30 @ 0x00654c30 ====

undefined4 FUN_00654c30(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 0x1c))();
  piVar3 = (int *)FUN_00803725(iVar2,0,&Framework::IArticle::RTTI_Type_Descriptor,
                               &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar2 != 0) && (piVar3 == (int *)0x0)) {
    return 0;
  }
  cVar1 = FUN_00654b50(piVar3);
  if (cVar1 == '\x01') {
    iVar2 = (**(code **)(*piVar3 + 0x14))();
    if (*(short *)(iVar2 + 0xc) == 0) {
      (**(code **)(*param_1 + 0x18))();
      (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar3);
      return 1;
    }
  }
  else {
    (**(code **)(*param_1 + 0x18))();
    if (*(int *)(in_ECX + 4) != 0) {
      (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
    }
    *(int **)(in_ECX + 4) = piVar3;
  }
  return 1;
}


// ==== FUN_00654cd0 @ 0x00654cd0 ====

void FUN_00654cd0(byte param_1)

{
  void *in_ECX;
  
  FUN_00654980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00654cf0 @ 0x00654cf0 ====

undefined4 FUN_00654cf0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00654d00 @ 0x00654d00 ====

undefined1 FUN_00654d00(void)

{
  return 1;
}


// ==== FUN_00654d10 @ 0x00654d10 ====

bool FUN_00654d10(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  iVar1 = *(int *)(iVar1 + 4);
  (**(code **)(*param_1 + 0x2c))();
  return iVar1 == 6;
}


// ==== FUN_00654d40 @ 0x00654d40 ====

undefined4 FUN_00654d40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00654d50 @ 0x00654d50 ====

undefined1 FUN_00654d50(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_00654d60 @ 0x00654d60 ====

void FUN_00654d60(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00654d70 @ 0x00654d70 ====

void FUN_00654d70(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5188;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00654da0 @ 0x00654da0 ====

void FUN_00654da0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c078;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5188;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00654e00 @ 0x00654e00 ====

undefined4 FUN_00654e00(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_00654e20 @ 0x00654e20 ====

undefined4 FUN_00654e20(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_00654e30 @ 0x00654e30 ====

undefined4 FUN_00654e30(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_00654e90 @ 0x00654e90 ====

int FUN_00654e90(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint3 uVar3;
  int in_ECX;
  undefined1 unaff_BP;
  undefined4 unaff_EDI;
  bool bVar4;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  if (*(int *)(iVar1 + 8) != 0x601) {
    (**(code **)(*param_1 + 0x2c))();
  }
  bVar4 = false;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(6);
  if ((piVar2 != (int *)0x0) && (*(int *)(in_ECX + 8) != 6)) {
    iVar1 = (**(code **)(*piVar2 + 0x2c))();
    bVar4 = *(int *)(iVar1 + 8) == 0x601;
    (**(code **)(*piVar2 + 0x2c))();
  }
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(7);
  if ((piVar2 != (int *)0x0) && (*(int *)(in_ECX + 8) != 7)) {
    iVar1 = (**(code **)(*piVar2 + 0x2c))();
    if (*(int *)(iVar1 + 8) == 0x601) {
      bVar4 = true;
    }
    (**(code **)(*piVar2 + 0x2c))();
  }
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(0x13);
  if ((piVar2 != (int *)0x0) && (*(int *)(in_ECX + 8) != 0x13)) {
    iVar1 = (**(code **)(*piVar2 + 0x2c))();
    if (*(int *)(iVar1 + 8) == 0x601) {
      bVar4 = true;
    }
    (**(code **)(*piVar2 + 0x2c))();
  }
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(0x14);
  if ((piVar2 != (int *)0x0) && (*(int *)(in_ECX + 8) != 0x14)) {
    iVar1 = (**(code **)(*piVar2 + 0x2c))();
    if (*(int *)(iVar1 + 8) == 0x601) {
      bVar4 = true;
    }
    iVar1 = (**(code **)(*piVar2 + 0x2c))();
    piVar2 = (int *)CONCAT31((int3)((uint)iVar1 >> 8),1);
    if (*(int *)(iVar1 + 8) == 0x604) goto LAB_00654fbd;
  }
  piVar2 = (int *)CONCAT31((int3)((uint)piVar2 >> 8),unaff_BP);
LAB_00654fbd:
  uVar3 = (uint3)((uint)piVar2 >> 8);
  if ((((char)((uint)unaff_EDI >> 0x10) == '\x01') && (bVar4)) ||
     (((char)((uint)unaff_EDI >> 0x18) == '\x01' && ((char)piVar2 == '\x01')))) {
    return CONCAT31(uVar3,1);
  }
  return (uint)uVar3 << 8;
}


// ==== FUN_00654ff0 @ 0x00654ff0 ====

byte FUN_00654ff0(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 != '\0') {
    cVar1 = FUN_00654e90(param_1);
    if (cVar1 != '\x01') {
      return (in_ECX[1] != 0) * '\x02' + 1;
    }
  }
  return 0;
}


// ==== FUN_00655040 @ 0x00655040 ====

void FUN_00655040(byte param_1)

{
  void *in_ECX;
  
  FUN_00654da0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655060 @ 0x00655060 ====

undefined4 FUN_00655060(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00655070 @ 0x00655070 ====

undefined1 FUN_00655070(void)

{
  return 1;
}


// ==== FUN_00655080 @ 0x00655080 ====

bool FUN_00655080(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x2c))();
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 8) == 0x503;
}


// ==== FUN_006550b0 @ 0x006550b0 ====

undefined4 FUN_006550b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_006550c0 @ 0x006550c0 ====

undefined1 FUN_006550c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_006550d0 @ 0x006550d0 ====

void FUN_006550d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_006550e0 @ 0x006550e0 ====

void FUN_006550e0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d51b8;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00655110 @ 0x00655110 ====

void FUN_00655110(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c098;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d51b8;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00655170 @ 0x00655170 ====

byte FUN_00655170(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_006551b0 @ 0x006551b0 ====

undefined4 FUN_006551b0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_006551d0 @ 0x006551d0 ====

undefined4 FUN_006551d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_006551e0 @ 0x006551e0 ====

undefined4 FUN_006551e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_00655240 @ 0x00655240 ====

void FUN_00655240(byte param_1)

{
  void *in_ECX;
  
  FUN_00655110();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655260 @ 0x00655260 ====

undefined4 FUN_00655260(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00655270 @ 0x00655270 ====

undefined1 FUN_00655270(void)

{
  return 1;
}


// ==== FUN_00655280 @ 0x00655280 ====

bool FUN_00655280(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x2c))();
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 8) == 0x504;
}


// ==== FUN_006552b0 @ 0x006552b0 ====

undefined4 FUN_006552b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_006552c0 @ 0x006552c0 ====

undefined1 FUN_006552c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_006552d0 @ 0x006552d0 ====

void FUN_006552d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_006552e0 @ 0x006552e0 ====

void FUN_006552e0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d51e8;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00655310 @ 0x00655310 ====

void FUN_00655310(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c0b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d51e8;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00655370 @ 0x00655370 ====

byte FUN_00655370(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_006553b0 @ 0x006553b0 ====

undefined4 FUN_006553b0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_006553d0 @ 0x006553d0 ====

undefined4 FUN_006553d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_006553e0 @ 0x006553e0 ====

undefined4 FUN_006553e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_00655440 @ 0x00655440 ====

void FUN_00655440(byte param_1)

{
  void *in_ECX;
  
  FUN_00655310();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655460 @ 0x00655460 ====

undefined4 FUN_00655460(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00655470 @ 0x00655470 ====

undefined1 FUN_00655470(void)

{
  return 1;
}


// ==== FUN_00655480 @ 0x00655480 ====

bool FUN_00655480(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x2c))();
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 8) == 0x502;
}


// ==== FUN_006554b0 @ 0x006554b0 ====

undefined4 FUN_006554b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_006554c0 @ 0x006554c0 ====

undefined1 FUN_006554c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_006554d0 @ 0x006554d0 ====

void FUN_006554d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_006554e0 @ 0x006554e0 ====

void FUN_006554e0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5218;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00655510 @ 0x00655510 ====

void FUN_00655510(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c0d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5218;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00655570 @ 0x00655570 ====

byte FUN_00655570(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_006555b0 @ 0x006555b0 ====

undefined4 FUN_006555b0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_006555d0 @ 0x006555d0 ====

undefined4 FUN_006555d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_006555e0 @ 0x006555e0 ====

undefined4 FUN_006555e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_00655640 @ 0x00655640 ====

void FUN_00655640(byte param_1)

{
  void *in_ECX;
  
  FUN_00655510();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655660 @ 0x00655660 ====

undefined4 FUN_00655660(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00655670 @ 0x00655670 ====

undefined1 FUN_00655670(void)

{
  return 1;
}


// ==== FUN_00655680 @ 0x00655680 ====

bool FUN_00655680(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x2c))();
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 8) == 0x501;
}


// ==== FUN_006556b0 @ 0x006556b0 ====

undefined4 FUN_006556b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_006556c0 @ 0x006556c0 ====

undefined1 FUN_006556c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_006556d0 @ 0x006556d0 ====

void FUN_006556d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_006556e0 @ 0x006556e0 ====

void FUN_006556e0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5248;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00655710 @ 0x00655710 ====

void FUN_00655710(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c0f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5248;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00655770 @ 0x00655770 ====

byte FUN_00655770(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_006557b0 @ 0x006557b0 ====

undefined4 FUN_006557b0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_006557d0 @ 0x006557d0 ====

undefined4 FUN_006557d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_006557e0 @ 0x006557e0 ====

undefined4 FUN_006557e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_00655840 @ 0x00655840 ====

void FUN_00655840(byte param_1)

{
  void *in_ECX;
  
  FUN_00655710();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655860 @ 0x00655860 ====

undefined4 FUN_00655860(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00655870 @ 0x00655870 ====

undefined1 FUN_00655870(void)

{
  return 1;
}


// ==== FUN_00655880 @ 0x00655880 ====

bool FUN_00655880(int *param_1)

{
  int iVar1;
  
  (**(code **)(*param_1 + 0x2c))();
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 8) == 0x500;
}


// ==== FUN_006558b0 @ 0x006558b0 ====

undefined4 FUN_006558b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_006558c0 @ 0x006558c0 ====

undefined1 FUN_006558c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_006558d0 @ 0x006558d0 ====

void FUN_006558d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_006558e0 @ 0x006558e0 ====

void FUN_006558e0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5278;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00655910 @ 0x00655910 ====

void FUN_00655910(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c118;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5278;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00655970 @ 0x00655970 ====

byte FUN_00655970(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  if (param_1 == 0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_006559b0 @ 0x006559b0 ====

undefined4 FUN_006559b0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_006559d0 @ 0x006559d0 ====

undefined4 FUN_006559d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_006559e0 @ 0x006559e0 ====

undefined4 FUN_006559e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_00655a40 @ 0x00655a40 ====

void FUN_00655a40(byte param_1)

{
  void *in_ECX;
  
  FUN_00655910();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655a60 @ 0x00655a60 ====

undefined4 FUN_00655a60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00655a70 @ 0x00655a70 ====

undefined1 FUN_00655a70(void)

{
  return 1;
}


// ==== FUN_00655a80 @ 0x00655a80 ====

bool FUN_00655a80(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  iVar1 = *(int *)(iVar1 + 4);
  (**(code **)(*param_1 + 0x2c))();
  return iVar1 == 2;
}


// ==== FUN_00655ab0 @ 0x00655ab0 ====

undefined4 FUN_00655ab0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00655ac0 @ 0x00655ac0 ====

undefined1 FUN_00655ac0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_00655ad0 @ 0x00655ad0 ====

void FUN_00655ad0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00655ae0 @ 0x00655ae0 ====

void FUN_00655ae0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d52a8;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00655b10 @ 0x00655b10 ====

void FUN_00655b10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c138;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d52a8;
  local_4 = 0;
  if (in_ECX[1] != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,in_ECX[1]);
  }
  *in_ECX = &PTR_FUN_009d5098;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00655b70 @ 0x00655b70 ====

undefined4 FUN_00655b70(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_00655b90 @ 0x00655b90 ====

undefined4 FUN_00655b90(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 4) = 0;
  return uVar1;
}


// ==== FUN_00655ba0 @ 0x00655ba0 ====

undefined4 FUN_00655ba0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (iVar2 == 0)) {
    return 0;
  }
  (**(code **)(*param_1 + 0x18))();
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(*param_1 + 0x14))(*(int *)(in_ECX + 4));
  }
  *(int *)(in_ECX + 4) = iVar2;
  return 1;
}


// ==== FUN_00655c00 @ 0x00655c00 ====

bool FUN_00655c00(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(param_1);
  if (piVar1 == (int *)0x0) {
    return false;
  }
  iVar2 = (**(code **)(*piVar1 + 0x2c))();
  return *(int *)(iVar2 + 8) == 0x205;
}


// ==== FUN_00655c30 @ 0x00655c30 ====

byte FUN_00655c30(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  if (param_1 == (int *)0x0) {
    return -(in_ECX[1] != 0) & 2;
  }
  cVar1 = (**(code **)(*in_ECX + 8))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  (**(code **)(*param_1 + 0x2c))();
  iVar2 = (**(code **)(*param_1 + 0x2c))();
  if (*(int *)(iVar2 + 8) == 0x207) {
    piVar3 = (int *)(**(code **)(*param_1 + 0x48))();
    iVar2 = (**(code **)(*piVar3 + 4))();
    piVar3 = (int *)(**(code **)(*DAT_00b5ab68 + 8))(*(undefined2 *)(iVar2 + 0x24));
    cVar1 = (**(code **)(*piVar3 + 0xc))(param_1,in_ECX[3]);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  iVar2 = (**(code **)(*param_1 + 0x2c))();
  if (*(int *)(iVar2 + 8) == 0x205) {
    if ((in_ECX[2] != 0) && (cVar1 = FUN_00655c00(0), cVar1 == '\x01')) {
      return 0;
    }
    if ((in_ECX[2] != 1) && (cVar1 = FUN_00655c00(1), cVar1 == '\x01')) {
      return 0;
    }
    if ((in_ECX[2] != 2) && (cVar1 = FUN_00655c00(2), cVar1 == '\x01')) {
      return 0;
    }
    if ((in_ECX[2] != 3) && (cVar1 = FUN_00655c00(3), cVar1 == '\x01')) {
      return 0;
    }
  }
  return (in_ECX[1] != 0) * '\x02' + 1;
}


// ==== FUN_00655d20 @ 0x00655d20 ====

void FUN_00655d20(byte param_1)

{
  void *in_ECX;
  
  FUN_00655b10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655d40 @ 0x00655d40 ====

void FUN_00655d40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d52d8;
  return;
}


// ==== FUN_00655d50 @ 0x00655d50 ====

void FUN_00655d50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d52d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655d70 @ 0x00655d70 ====

void FUN_00655d70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d52fc;
  return;
}


// ==== FUN_00655d80 @ 0x00655d80 ====

void FUN_00655d80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5354;
  return;
}


// ==== FUN_00655d90 @ 0x00655d90 ====

void FUN_00655d90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d536c;
  return;
}


// ==== FUN_00655da0 @ 0x00655da0 ====

void FUN_00655da0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d52fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655dc0 @ 0x00655dc0 ====

void FUN_00655dc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5354;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655de0 @ 0x00655de0 ====

void FUN_00655de0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d536c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00655e00 @ 0x00655e00 ====

void FUN_00655e00(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c158;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d5384;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d52d8;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00655e70 @ 0x00655e70 ====

void FUN_00655e70(undefined2 param_1)

{
  int iVar1;
  int in_ECX;
  undefined2 local_8 [4];
  
  local_8[0] = param_1;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x40))(iVar1);
  }
  return;
}


// ==== FUN_00655eb0 @ 0x00655eb0 ====

undefined4 FUN_00655eb0(undefined2 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined2 local_8 [4];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00655ee0 @ 0x00655ee0 ====

void FUN_00655ee0(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar1)) {
    (**(code **)(*DAT_00b5abd8 + 8))(*(undefined4 *)(*piVar1 + 4));
  }
                    /* WARNING: Could not recover jumptable at 0x00655f19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_00655f20 @ 0x00655f20 ====

undefined4 FUN_00655f20(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00655f40 @ 0x00655f40 ====

undefined4 FUN_00655f40(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(undefined4 *)(in_ECX + 0xc));
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00655f60 @ 0x00655f60 ====

undefined4 FUN_00655f60(int *param_1)

{
  ushort uVar1;
  int *piVar2;
  ushort *puVar3;
  int iVar4;
  int in_ECX;
  ushort auStack_8 [4];
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
  puVar3 = (ushort *)(**(code **)(*piVar2 + 0xc))();
  uVar1 = *puVar3;
  auStack_8[0] = uVar1 >> 4;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(auStack_8);
  if (iVar4 == 0) {
    puVar3 = (ushort *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
    *puVar3 = uVar1 >> 4;
    *(int **)(puVar3 + 2) = param_1;
    (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
    return 1;
  }
  return 0;
}


// ==== FUN_00655fe0 @ 0x00655fe0 ====

void FUN_00655fe0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098c180;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5384;
  pvVar1 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006560e0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00656660(in_ECX[1]);
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00656080 @ 0x00656080 ====

void FUN_00656080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d53a4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_006560a0 @ 0x006560a0 ====

void FUN_006560a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00656080();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006560c0 @ 0x006560c0 ====

void FUN_006560c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00655e00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006560e0 @ 0x006560e0 ====

void FUN_006560e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c198;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d53ac;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d53a4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x80,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x282] = 0;
  in_ECX[0x282] = in_ECX[0x282] + 0x80;
  in_ECX[0x285] = in_ECX + 2;
  in_ECX[0x283] = 0;
  in_ECX[0x284] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x27f] = 0;
  in_ECX[0x280] = 0;
  in_ECX[0x281] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00656190 @ 0x00656190 ====

void FUN_00656190(byte param_1)

{
  void *in_ECX;
  
  FUN_006561b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006561b0 @ 0x006561b0 ====

void FUN_006561b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c1c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d53ac;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d53a4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d5354;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_00656230 @ 0x00656230 ====

void * FUN_00656230(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098c1db;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xa14);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xa0c) = *(int *)(in_ECX + 0xa0c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0xa10);
      *(void **)(in_ECX + 0xa10) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xa14) = *(undefined4 *)((int)param_2 + 8);
    }
    *(undefined4 *)((int)param_2 + 8) = 0;
    *(int *)((int)param_2 + 0x10) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d53c0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00656310 @ 0x00656310 ====

undefined4 FUN_00656310(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d53c0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0xa14);
    *(int *)(in_ECX + 0xa0c) = *(int *)(in_ECX + 0xa0c) + -1;
    *(int *)(in_ECX + 0xa14) = param_2;
  }
  return 0;
}


// ==== FUN_00656390 @ 0x00656390 ====

void FUN_00656390(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5434;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_006563b0 @ 0x006563b0 ====

void FUN_006563b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c203;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d543c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d5434;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d536c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_00656430 @ 0x00656430 ====

undefined4 FUN_00656430(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d53c0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x1014);
    *(int *)(in_ECX + 0x100c) = *(int *)(in_ECX + 0x100c) + -1;
    *(int *)(in_ECX + 0x1014) = param_2;
  }
  return 0;
}


// ==== FUN_006564b0 @ 0x006564b0 ====

undefined4 * FUN_006564b0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d53c0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1014);
  *(int *)(in_ECX + 0x100c) = *(int *)(in_ECX + 0x100c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x1010);
    *(undefined4 **)(in_ECX + 0x1010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00656570 @ 0x00656570 ====

void FUN_00656570(byte param_1)

{
  void *in_ECX;
  
  FUN_00656390();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00656590 @ 0x00656590 ====

void FUN_00656590(byte param_1)

{
  void *in_ECX;
  
  FUN_006563b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006565b0 @ 0x006565b0 ====

void FUN_006565b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c218;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d543c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d5434;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x80,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x402] = 0;
  in_ECX[0x402] = in_ECX[0x402] + 0x80;
  in_ECX[0x405] = in_ECX + 2;
  in_ECX[0x403] = 0;
  in_ECX[0x404] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x3ff] = 0;
  in_ECX[0x400] = 0;
  in_ECX[0x401] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00656660 @ 0x00656660 ====

void FUN_00656660(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c238;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5454;
  FUN_006565b0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006566c0 @ 0x006566c0 ====

void FUN_006566c0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return;
  }
  for (iVar1 = *(int *)(*(int *)(in_ECX + 4) + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
  }
  return;
}


// ==== FUN_006566e0 @ 0x006566e0 ====

void FUN_006566e0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return;
  }
  for (iVar1 = *(int *)(*(int *)(in_ECX + 4) + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
  }
  return;
}


// ==== FUN_00656700 @ 0x00656700 ====

void FUN_00656700(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00656720(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00656720 @ 0x00656720 ====

void FUN_00656720(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00656720(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00656720(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00656760 @ 0x00656760 ====

void FUN_00656760(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00656780(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00656780 @ 0x00656780 ====

void FUN_00656780(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00656780(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00656780(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_006567f0 @ 0x006567f0 ====

void FUN_006567f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00656810();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00656810 @ 0x00656810 ====

void FUN_00656810(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098c263;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5454;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00656780(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006563b0();
  *in_ECX = &PTR_FUN_009d52fc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00656880 @ 0x00656880 ====

void FUN_00656880(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d54ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006568a0 @ 0x006568a0 ====

void FUN_006568a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d54ac;
  return;
}


// ==== FUN_006568b0 @ 0x006568b0 ====

undefined1 FUN_006568b0(void)

{
  return 0;
}


// ==== FUN_006568c0 @ 0x006568c0 ====

undefined1 FUN_006568c0(void)

{
  return 0;
}


// ==== FUN_006568d0 @ 0x006568d0 ====

undefined1 FUN_006568d0(void)

{
  return 1;
}


// ==== FUN_006568e0 @ 0x006568e0 ====

int FUN_006568e0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  (**(code **)(*param_1 + 0x10))();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  iVar2 = *(int *)(iVar2 + 0x14);
  iVar3 = (**(code **)(*piVar1 + 0x10))();
  return iVar2 - *(int *)(iVar3 + 8);
}


// ==== FUN_00656920 @ 0x00656920 ====

undefined1 FUN_00656920(void)

{
  return 0;
}


// ==== FUN_00656930 @ 0x00656930 ====

undefined1 FUN_00656930(void)

{
  return 1;
}


// ==== FUN_00656940 @ 0x00656940 ====

void FUN_00656940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d54dc;
  return;
}


// ==== FUN_00656950 @ 0x00656950 ====

int FUN_00656950(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  iVar2 = (**(code **)(*piVar1 + 4))();
  return iVar2 + 0x2bac;
}


// ==== FUN_00656980 @ 0x00656980 ====

int FUN_00656980(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  iVar2 = (**(code **)(*piVar1 + 4))();
  return iVar2 + 0x860;
}


// ==== FUN_006569b0 @ 0x006569b0 ====

undefined4 FUN_006569b0(int *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
  (**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar2 + 0x10))();
  (**(code **)(*piVar2 + 0x10))();
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  if (param_2 <= *(uint *)(iVar3 + 0xc)) {
    return 0;
  }
  (**(code **)(*piVar2 + 0x3c))(param_2);
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  uVar1 = *(uint *)(iVar3 + 0x14);
  if (param_2 < uVar1) {
    return 1;
  }
  (**(code **)(*piVar2 + 0x34))(0);
  (**(code **)(*piVar2 + 0x40))(0);
  (**(code **)(*piVar2 + 0x44))(0);
  (**(code **)(*piVar2 + 0x48))(0);
  uVar4 = (**(code **)(*DAT_00b5acd0 + 4))(0);
  (**(code **)(*piVar2 + 0x3c))(uVar1);
  (**(code **)(*param_1 + 0x24))(uVar4,uVar1);
  return 0;
}


// ==== FUN_00656a60 @ 0x00656a60 ====

void FUN_00656a60(byte param_1)

{
  void *in_ECX;
  
  FUN_006568a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00656a80 @ 0x00656a80 ====

void FUN_00656a80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d54ac;
  return;
}


// ==== FUN_00656a90 @ 0x00656a90 ====

undefined1 FUN_00656a90(void)

{
  return 1;
}


// ==== FUN_00656aa0 @ 0x00656aa0 ====

int FUN_00656aa0(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))(param_1);
  return iVar1 + 0x30;
}


// ==== FUN_00656ab0 @ 0x00656ab0 ====

undefined1 FUN_00656ab0(void)

{
  return 1;
}


// ==== FUN_00656ac0 @ 0x00656ac0 ====

undefined1 FUN_00656ac0(void)

{
  return 0;
}


// ==== FUN_00656ad0 @ 0x00656ad0 ====

void FUN_00656ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d550c;
  return;
}


// ==== FUN_00656ae0 @ 0x00656ae0 ====

int FUN_00656ae0(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  iVar3 = (**(code **)(*piVar2 + 4))();
  iVar5 = (uint)*(byte *)(param_1 + 0xe) * 0x80;
  bVar1 = *(byte *)(iVar5 + 100 + iVar3);
  bVar4 = *(byte *)(param_1 + 0x13);
  if (*(byte *)(param_1 + 0x13) < bVar1) {
    bVar4 = bVar1;
  }
  bVar1 = *(byte *)(iVar5 + iVar3 + 0x65);
  if (bVar1 < *(byte *)(param_1 + 0x13)) {
    bVar4 = bVar1;
  }
  return iVar3 + 0x860 + (uint)bVar4 * 0x3c;
}


// ==== FUN_00656b40 @ 0x00656b40 ====

int FUN_00656b40(int param_1)

{
  int *piVar1;
  int iVar2;
  uint3 uVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  iVar2 = (**(code **)(*piVar1 + 4))();
  iVar2 = (uint)*(byte *)(param_1 + 0xe) * 0x80 + 4 + iVar2;
  uVar3 = (uint3)((uint)iVar2 >> 8);
  if (*(byte *)(param_1 + 0x13) < *(byte *)(iVar2 + 0x60)) {
    return (uint)uVar3 << 8;
  }
  return CONCAT31(uVar3,*(byte *)(param_1 + 0x13) <= *(byte *)(iVar2 + 0x61));
}


// ==== FUN_00656b80 @ 0x00656b80 ====

undefined4 FUN_00656b80(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  piVar2 = (int *)(**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar1 + 0xc))();
  iVar4 = (**(code **)(*piVar1 + 0x10))();
  return *(undefined4 *)(iVar3 + (uint)*(byte *)(iVar4 + 0x11) * 0x3c + 0x898);
}


// ==== FUN_00656bd0 @ 0x00656bd0 ====

undefined4 FUN_00656bd0(int *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  undefined4 uVar10;
  int unaff_ESI;
  int unaff_EDI;
  int unaff_retaddr;
  int iStack_8;
  
  piVar3 = param_1;
  piVar4 = (int *)(**(code **)(*param_1 + 0x18))();
  piVar5 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar4 + 0x10))();
  iVar6 = (**(code **)(*piVar4 + 0x10))();
  if (param_2 <= *(uint *)(iVar6 + 0xc)) {
    return 0;
  }
  (**(code **)(*piVar4 + 0x3c))(param_2);
  iVar7 = (**(code **)(*piVar5 + 4))();
  pbVar8 = (byte *)(**(code **)(*piVar4 + 0xc))();
  iVar6 = (*pbVar8 & 0xf) * 0x80 + 4 + iVar7;
  iVar9 = (**(code **)(*piVar4 + 0x10))();
  bVar1 = *(byte *)(iVar9 + 0x11);
  uVar2 = *(uint *)(iVar7 + 0x898 + (uint)bVar1 * 0x3c);
  if (uVar2 <= param_2 - unaff_retaddr) {
    if (*(byte *)(iVar6 + 0x61) <= bVar1) {
      (**(code **)(*piVar4 + 0x44))(0);
      (**(code **)(*piVar4 + 0x40))(0);
      uVar10 = (**(code **)(*DAT_00b5acd0 + 4))(3);
      iVar6 = unaff_EDI + uVar2;
      (**(code **)(*piVar4 + 0x3c))(iVar6);
      (**(code **)(*piVar4 + 0x48))(*(int *)(uVar2 + 100) + iVar6);
      (**(code **)(*param_1 + 0x24))(uVar10,iVar6);
      return 1;
    }
    iVar7 = (**(code **)(*piVar4 + 0x10))();
    param_1 = (int *)CONCAT31((int3)((uint)iVar6 >> 8),*(char *)(iVar7 + 0x10) + '\x01');
    (**(code **)(*piVar4 + 0x40))(param_1);
    (**(code **)(*piVar4 + 0x44))(bVar1 + 1);
    (**(code **)(*piVar4 + 0x3c))(unaff_ESI + iStack_8);
    (**(code **)(*piVar3 + 0x24))(unaff_ESI,unaff_ESI + iStack_8);
  }
  return 1;
}


// ==== FUN_00656d30 @ 0x00656d30 ====

undefined4 FUN_00656d30(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  piVar2 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar1 + 0x44))(0);
  (**(code **)(*piVar1 + 0x40))(0);
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar1 + 0x48))(unaff_retaddr);
  uVar3 = (**(code **)(*DAT_00b5acd0 + 4))(3);
  (**(code **)(*piVar1 + 0x3c))(unaff_retaddr);
  (**(code **)(*param_1 + 0x24))(uVar3,unaff_retaddr);
  return 1;
}


// ==== FUN_00656da0 @ 0x00656da0 ====

void FUN_00656da0(byte param_1)

{
  void *in_ECX;
  
  FUN_00656a80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00656dc0 @ 0x00656dc0 ====

void FUN_00656dc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d54ac;
  return;
}


// ==== FUN_00656dd0 @ 0x00656dd0 ====

undefined1 FUN_00656dd0(void)

{
  return 1;
}


// ==== FUN_00656de0 @ 0x00656de0 ====

undefined1 FUN_00656de0(void)

{
  return 0;
}


// ==== FUN_00656df0 @ 0x00656df0 ====

undefined1 FUN_00656df0(void)

{
  return 1;
}


// ==== FUN_00656e00 @ 0x00656e00 ====

undefined1 FUN_00656e00(void)

{
  return 0;
}


// ==== FUN_00656e10 @ 0x00656e10 ====

void FUN_00656e10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d553c;
  return;
}


// ==== FUN_00656e20 @ 0x00656e20 ====

int FUN_00656e20(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  bVar1 = *(byte *)(param_1 + 0xe);
  iVar3 = (**(code **)(*piVar2 + 4))();
  return iVar3 + 0x74 + (uint)bVar1 * 0x80;
}


// ==== FUN_00656e50 @ 0x00656e50 ====

int FUN_00656e50(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  iVar2 = (**(code **)(*piVar1 + 4))();
  return iVar2 + 0x860;
}


// ==== FUN_00656e80 @ 0x00656e80 ====

undefined4 FUN_00656e80(int *param_1)

{
  int *piVar1;
  int iVar2;
  byte *pbVar3;
  
  (**(code **)(*param_1 + 0x18))();
  piVar1 = (int *)(**(code **)(*param_1 + 0x10))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  pbVar3 = (byte *)(**(code **)(*piVar1 + 0xc))();
  return *(undefined4 *)((*pbVar3 & 0xf) * 0x80 + 0x7c + iVar2);
}


// ==== FUN_00656ec0 @ 0x00656ec0 ====

undefined4 FUN_00656ec0(int *param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  undefined4 unaff_EBX;
  int unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  piVar2 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar1 + 0x10))();
  iVar3 = (**(code **)(*piVar1 + 0x10))();
  if (param_2 <= *(uint *)(iVar3 + 0xc)) {
    return 0;
  }
  (**(code **)(*piVar1 + 0x3c))(param_2);
  iVar3 = (**(code **)(*piVar2 + 4))();
  pbVar4 = (byte *)(**(code **)(*piVar1 + 0xc))();
  if (*(uint *)((*pbVar4 & 0xf) * 0x80 + 0x7c + iVar3) <= param_2 - unaff_retaddr) {
    (**(code **)(*piVar1 + 0x40))(0);
    (**(code **)(*piVar1 + 0x44))(unaff_EBX);
    uVar5 = (**(code **)(*DAT_00b5acd0 + 4))(2);
    (**(code **)(*piVar1 + 0x3c))(param_2);
    (**(code **)(*param_1 + 0x24))(uVar5,param_2);
  }
  return 1;
}


// ==== FUN_00656f80 @ 0x00656f80 ====

undefined4 FUN_00656f80(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  piVar2 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar1 + 0x44))(0);
  (**(code **)(*piVar1 + 0x40))(0);
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar1 + 0x48))(unaff_retaddr);
  uVar3 = (**(code **)(*DAT_00b5acd0 + 4))(3);
  (**(code **)(*piVar1 + 0x3c))(unaff_retaddr);
  (**(code **)(*param_1 + 0x24))(uVar3,unaff_retaddr);
  return 1;
}


// ==== FUN_00656ff0 @ 0x00656ff0 ====

void FUN_00656ff0(byte param_1)

{
  void *in_ECX;
  
  FUN_00656dc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657010 @ 0x00657010 ====

void FUN_00657010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d54ac;
  return;
}


// ==== FUN_00657020 @ 0x00657020 ====

undefined1 FUN_00657020(void)

{
  return 0;
}


// ==== FUN_00657030 @ 0x00657030 ====

undefined1 FUN_00657030(void)

{
  return 0;
}


// ==== FUN_00657040 @ 0x00657040 ====

undefined1 FUN_00657040(void)

{
  return 1;
}


// ==== FUN_00657050 @ 0x00657050 ====

undefined4 FUN_00657050(void)

{
  return 0;
}


// ==== FUN_00657060 @ 0x00657060 ====

undefined4 FUN_00657060(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x18))();
  (**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar1 + 0x10))();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  if (param_2 < *(uint *)(iVar2 + 0xc)) {
    return 0;
  }
  (**(code **)(*piVar1 + 0x3c))(param_2);
  return 1;
}


// ==== FUN_006570b0 @ 0x006570b0 ====

undefined1 FUN_006570b0(void)

{
  return 1;
}


// ==== FUN_006570c0 @ 0x006570c0 ====

void FUN_006570c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d556c;
  return;
}


// ==== FUN_006570d0 @ 0x006570d0 ====

int FUN_006570d0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  iVar2 = (**(code **)(*piVar1 + 4))();
  return iVar2 + 0x2bac;
}


// ==== FUN_00657100 @ 0x00657100 ====

int FUN_00657100(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5aa30 + 8))(*(undefined2 *)(param_1 + 0xc));
  iVar2 = (**(code **)(*piVar1 + 4))();
  return iVar2 + 0x860;
}


// ==== FUN_00657130 @ 0x00657130 ====

undefined4 FUN_00657130(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 unaff_EBX;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x18))();
  piVar3 = (int *)(**(code **)(*param_1 + 0x10))();
  (**(code **)(*piVar2 + 0x3c))(param_2);
  (**(code **)(*piVar2 + 0x40))(0);
  pbVar4 = (byte *)(**(code **)(*piVar2 + 0xc))();
  bVar1 = *pbVar4;
  iVar5 = (**(code **)(*piVar3 + 4))();
  (**(code **)(*piVar2 + 0x44))(*(undefined1 *)((uint)(bVar1 & 0xf) * 0x80 + 100 + iVar5));
  (**(code **)(*piVar2 + 0x34))(unaff_EBX);
  iVar5 = (**(code **)(*piVar3 + 4))();
  if ((*(uint *)(iVar5 + 0x2bc4) & 0x20) != 0) {
    uVar6 = (**(code **)(*DAT_00b5acd0 + 4))(1);
    (**(code **)(*param_1 + 0x24))(uVar6,unaff_EBX);
    return 1;
  }
  if ((*(uint *)(iVar5 + 0x2bc4) & 0x10) == 0) {
    return 0;
  }
  uVar6 = (**(code **)(*DAT_00b5acd0 + 4))(2);
  (**(code **)(*param_1 + 0x24))(uVar6,unaff_EBX);
  return 1;
}


// ==== FUN_006571f0 @ 0x006571f0 ====

void FUN_006571f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00657010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657210 @ 0x00657210 ====

void FUN_00657210(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d559c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657230 @ 0x00657230 ====

void FUN_00657230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d559c;
  return;
}


// ==== FUN_00657240 @ 0x00657240 ====

int FUN_00657240(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00657250 @ 0x00657250 ====

int FUN_00657250(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00657260 @ 0x00657260 ====

undefined4 FUN_00657260(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}


// ==== __break @ 0x00657265 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x00657269 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x0065726f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00657270 @ 0x00657270 ====

void FUN_00657270(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = param_1;
  return;
}


// ==== FUN_00657280 @ 0x00657280 ====

undefined4 FUN_00657280(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_00657290 @ 0x00657290 ====

undefined1 FUN_00657290(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x24);
}


// ==== FUN_006572a0 @ 0x006572a0 ====

void FUN_006572a0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_006572b0 @ 0x006572b0 ====

void FUN_006572b0(byte param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  *(ushort *)(in_ECX + 4) = (ushort)(param_1 & 0xf) | *(ushort *)(in_ECX + 4) & 0xfff0;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x2c) + 0xc))();
    piVar2 = (int *)(**(code **)(*piVar2 + 0x10))();
    (**(code **)(*piVar2 + 0x14))();
  }
  return;
}


// ==== FUN_006572f0 @ 0x006572f0 ====

void FUN_006572f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00657300 @ 0x00657300 ====

void FUN_00657300(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00657310 @ 0x00657310 ====

void FUN_00657310(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00657320 @ 0x00657320 ====

void FUN_00657320(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_00657330 @ 0x00657330 ====

void FUN_00657330(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x18) = param_1;
  return;
}


// ==== FUN_00657340 @ 0x00657340 ====

void FUN_00657340(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x19) = param_1;
  return;
}


// ==== FUN_00657350 @ 0x00657350 ====

void FUN_00657350(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== __break @ 0x0065736e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00657370 @ 0x00657370 ====

void FUN_00657370(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d55f4;
  *(undefined2 *)(in_ECX + 1) = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  return;
}


// ==== FUN_00657390 @ 0x00657390 ====

undefined4 FUN_00657390(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  FUN_00797a50(in_ECX + 8,0,0x20);
  return 1;
}


// ==== FUN_006573c0 @ 0x006573c0 ====

void FUN_006573c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) != 0) {
    (**(code **)(*DAT_00b5a77c + 0x18))(*(int *)(in_ECX + 0x28));
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  return;
}


// ==== FUN_006573e0 @ 0x006573e0 ====

void FUN_006573e0(undefined4 param_1)

{
  int in_ECX;
  undefined4 unaff_retaddr;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    *(undefined4 *)(in_ECX + 0x28) = param_1;
    return;
  }
  (**(code **)(*DAT_00b5a77c + 0x18))(*(int *)(in_ECX + 0x28));
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x28) = unaff_retaddr;
  return;
}


// ==== FUN_00657420 @ 0x00657420 ====

void FUN_00657420(byte param_1)

{
  void *in_ECX;
  
  FUN_00657230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657440 @ 0x00657440 ====

void FUN_00657440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5648;
  return;
}


// ==== FUN_00657450 @ 0x00657450 ====

void FUN_00657450(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5648;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== __break @ 0x0065746f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00657470 @ 0x00657470 ====

int FUN_00657470(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== __break @ 0x00657474 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x00657475 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00657480 @ 0x00657480 ====

byte FUN_00657480(void)

{
  int in_ECX;
  
  return *(byte *)(in_ECX + 0x2bc8) & 1;
}


// ==== FUN_00657490 @ 0x00657490 ====

byte FUN_00657490(void)

{
  int in_ECX;
  
  return *(byte *)(in_ECX + 0x2bc8) >> 1 & 1;
}


// ==== FUN_006574a0 @ 0x006574a0 ====

uint FUN_006574a0(int *param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  byte bVar4;
  
  iVar1 = (**(code **)(*param_1 + 8))();
  uVar2 = CONCAT31((int3)((uint)iVar1 >> 8),*(byte *)(iVar1 + 4));
  bVar4 = 0;
  if (*(uint *)(in_ECX + 0x860) != 0) {
    uVar3 = 0;
    uVar2 = (uint)*(byte *)(iVar1 + 4);
    do {
      if (uVar2 == *(uint *)(in_ECX + 0x810 + uVar3 * 4)) {
        return 1;
      }
      bVar4 = bVar4 + 1;
      uVar3 = (uint)bVar4;
    } while (uVar3 < *(uint *)(in_ECX + 0x860));
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_006574f0 @ 0x006574f0 ====

bool FUN_006574f0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  int in_ECX;
  
  iVar1 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar1 == 0) {
    return false;
  }
  if (*(int **)(iVar1 + 4) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 4) + 0x18))();
  }
  pbVar3 = (byte *)(**(code **)(*piVar2 + 8))();
  return (*(uint *)(in_ECX + 0x2bcc) & 0x80000000U >> (*pbVar3 & 0x1f)) != 0;
}


// ==== FUN_00657550 @ 0x00657550 ====

void FUN_00657550(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c278;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5664;
  local_4 = 0;
  FUN_00480300();
  *in_ECX = &PTR_FUN_009d5648;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006575a0 @ 0x006575a0 ====

void FUN_006575a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c28a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5664;
  FUN_00480270();
  FUN_00657730(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00657600 @ 0x00657600 ====

void FUN_00657600(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined1 *)(in_ECX + 0x50) = *(undefined1 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined1 *)(in_ECX + 0x60) = *(undefined1 *)(param_1 + 0x60);
  *(undefined1 *)(in_ECX + 0x61) = *(undefined1 *)(param_1 + 0x61);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(param_1 + 0x78);
  *(undefined1 *)(in_ECX + 0x7c) = *(undefined1 *)(param_1 + 0x7c);
  return;
}


// ==== FUN_006576e0 @ 0x006576e0 ====

void FUN_006576e0(int param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  iVar2 = in_ECX + 4;
  iVar1 = 0x10;
  do {
    FUN_00657600((param_1 - in_ECX) + iVar2);
    iVar2 = iVar2 + 0x80;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(in_ECX + 0x804) = *(undefined4 *)(param_1 + 0x804);
  return;
}


// ==== FUN_00657730 @ 0x00657730 ====

void FUN_00657730(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_006576e0(param_1);
  puVar1 = (undefined4 *)(in_ECX + 0x80c);
  iVar2 = 0x14;
  do {
    *puVar1 = *(undefined4 *)(((param_1 + 0x808) - (in_ECX + 0x808)) + (int)puVar1);
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(in_ECX + 0x85c) = *(undefined4 *)(param_1 + 0x85c);
  puVar1 = (undefined4 *)(param_1 + 0x860);
  puVar3 = (undefined4 *)(in_ECX + 0x860);
  for (iVar2 = 0x8ca; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0x2b88) = *(undefined4 *)(param_1 + 0x2b88);
  *(undefined2 *)(in_ECX + 0x2b8c) = *(undefined2 *)(param_1 + 0x2b8c);
  *(undefined4 *)(in_ECX + 0x2b90) = *(undefined4 *)(param_1 + 0x2b90);
  *(undefined4 *)(in_ECX + 0x2b94) = *(undefined4 *)(param_1 + 0x2b94);
  *(undefined4 *)(in_ECX + 0x2b98) = *(undefined4 *)(param_1 + 0x2b98);
  *(undefined4 *)(in_ECX + 0x2b9c) = *(undefined4 *)(param_1 + 0x2b9c);
  *(undefined4 *)(in_ECX + 0x2ba0) = *(undefined4 *)(param_1 + 0x2ba0);
  *(undefined4 *)(in_ECX + 0x2ba4) = *(undefined4 *)(param_1 + 0x2ba4);
  *(undefined4 *)(in_ECX + 0x2ba8) = *(undefined4 *)(param_1 + 0x2ba8);
  *(undefined4 *)(in_ECX + 0x2bac) = *(undefined4 *)(param_1 + 0x2bac);
  *(undefined4 *)(in_ECX + 0x2bb0) = *(undefined4 *)(param_1 + 0x2bb0);
  *(undefined4 *)(in_ECX + 0x2bb4) = *(undefined4 *)(param_1 + 0x2bb4);
  *(undefined2 *)(in_ECX + 0x2bb8) = *(undefined2 *)(param_1 + 0x2bb8);
  *(undefined4 *)(in_ECX + 0x2bbc) = *(undefined4 *)(param_1 + 0x2bbc);
  *(undefined1 *)(in_ECX + 0x2bc0) = *(undefined1 *)(param_1 + 0x2bc0);
  *(undefined2 *)(in_ECX + 0x2bc2) = *(undefined2 *)(param_1 + 0x2bc2);
  *(undefined4 *)(in_ECX + 0x2bc4) = *(undefined4 *)(param_1 + 0x2bc4);
  *(undefined4 *)(in_ECX + 0x2bc8) = *(undefined4 *)(param_1 + 0x2bc8);
  return;
}


// ==== FUN_00657840 @ 0x00657840 ====

void FUN_00657840(byte param_1)

{
  void *in_ECX;
  
  FUN_00657550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657880 @ 0x00657880 ====

void FUN_00657880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_DAT_009d5680;
  return;
}


// ==== FUN_00657890 @ 0x00657890 ====

void FUN_00657890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d568c;
  return;
}


// ==== FUN_006578a0 @ 0x006578a0 ====

undefined4 FUN_006578a0(undefined4 param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  
  iVar1 = (**(code **)(*DAT_00b5abdc + 4))(param_2);
  iVar2 = (**(code **)(*DAT_00b5aa30 + 8))(*param_2 >> 4);
  if ((iVar1 == 0) || (iVar2 == 0)) {
    return 0;
  }
  uVar3 = (**(code **)(*DAT_00b5acd0 + 4))(0);
  (**(code **)(*unaff_ESI + 0x1c))(iVar1);
  (**(code **)(*unaff_ESI + 0x14))(iVar2);
  (**(code **)(*unaff_ESI + 0x24))(uVar3,0);
  return 1;
}


// ==== FUN_00657920 @ 0x00657920 ====

void FUN_00657920(byte param_1)

{
  void *in_ECX;
  
  FUN_00657880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657940 @ 0x00657940 ====

void FUN_00657940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5698;
  return;
}


// ==== FUN_00657950 @ 0x00657950 ====

void FUN_00657950(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5698;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657970 @ 0x00657970 ====

void FUN_00657970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d56a8;
  return;
}


// ==== FUN_00657980 @ 0x00657980 ====

void FUN_00657980(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d56a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006579b0 @ 0x006579b0 ====

void FUN_006579b0(void)

{
  FUN_0065a080();
  return;
}


// ==== FUN_006579c0 @ 0x006579c0 ====

void FUN_006579c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c2a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d56c8;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d5698;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00657a20 @ 0x00657a20 ====

undefined4 FUN_00657a20(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00803725(param_1,0,&Framework::Article::ISkill::RTTI_Type_Descriptor,
                       &Framework::Article::Skill::Provider::RTTI_Type_Descriptor,0);
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,uVar1);
  return 1;
}


// ==== FUN_00657a50 @ 0x00657a50 ====

void FUN_00657a50(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c2c5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d56c8;
  pvVar1 = operator_new(0x3c);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00657b00();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00657ad0 @ 0x00657ad0 ====

void FUN_00657ad0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_00657ae0 @ 0x00657ae0 ====

void FUN_00657ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d56c0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x24,1,(_func_void_void_ptr *)&LAB_006579a0);
  return;
}


// ==== FUN_00657b00 @ 0x00657b00 ====

void FUN_00657b00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c2d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d56d8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d56c0;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x24,1,FUN_006579b0,(_func_void_void_ptr *)&LAB_006579a0);
  in_ECX[0xb] = 0;
  in_ECX[0xb] = in_ECX[0xb] + 1;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = in_ECX + 2;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00657b80 @ 0x00657b80 ====

undefined4 FUN_00657b80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_00657b90 @ 0x00657b90 ====

void FUN_00657b90(byte param_1)

{
  void *in_ECX;
  
  FUN_00657ae0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657bb0 @ 0x00657bb0 ====

void FUN_00657bb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00657bd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657bd0 @ 0x00657bd0 ====

void FUN_00657bd0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c303;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d56d8;
  _Memory = (void *)in_ECX[0xd];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d56c0;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x24,1,(_func_void_void_ptr *)&LAB_006579a0);
    *in_ECX = &PTR_FUN_009d56a8;
    ExceptionList = local_c;
    return;
  }
  FUN_00659f60();
  _free(_Memory);
  return;
}


// ==== FUN_00657c60 @ 0x00657c60 ====

void FUN_00657c60(byte param_1)

{
  void *in_ECX;
  
  FUN_006579c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657c80 @ 0x00657c80 ====

void * FUN_00657c80(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098c329;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x38);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x24);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0065a080();
      }
      *(undefined4 *)((int)param_2 + 0x1c) = *(undefined4 *)(in_ECX + 0x34);
      *(void **)(in_ECX + 0x34) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)((int)param_2 + 0x18);
    }
    *(undefined4 *)((int)param_2 + 0x18) = 0;
    *(int *)((int)param_2 + 0x20) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x20) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d56f0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x20) = *(int *)((int)param_2 + 0x20) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00657d80 @ 0x00657d80 ====

undefined4 FUN_00657d80(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x20) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d56f0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x20);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x20);
    }
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(in_ECX + 0x38);
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + -1;
    *(int *)(in_ECX + 0x38) = param_2;
  }
  return 0;
}


// ==== FUN_00657e00 @ 0x00657e00 ====

void FUN_00657e00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5768;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00657e20 @ 0x00657e20 ====

void FUN_00657e20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5768;
  return;
}


// ==== FUN_00657e30 @ 0x00657e30 ====

int FUN_00657e30(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00657e40 @ 0x00657e40 ====

void FUN_00657e40(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  return;
}


// ==== FUN_00657e80 @ 0x00657e80 ====

void FUN_00657e80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d577c;
  return;
}


// ==== FUN_00657e90 @ 0x00657e90 ====

undefined4 FUN_00657e90(int *param_1,undefined1 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  switch(param_2) {
  case 1:
    piVar1 = (int *)(**(code **)(*param_1 + 0x1c))(0);
    break;
  case 2:
    uVar3 = 1;
    goto LAB_00657ec4;
  case 3:
    piVar1 = (int *)(**(code **)(*param_1 + 0x1c))(2);
    break;
  case 4:
    uVar3 = 3;
LAB_00657ec4:
    piVar1 = (int *)(**(code **)(*param_1 + 0x1c))(uVar3);
    break;
  default:
    goto switchD_00657e9d_default;
  }
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x48))();
    iVar2 = (**(code **)(*piVar1 + 4))();
    uVar3 = (**(code **)(*DAT_00b5ab68 + 8))(*(undefined2 *)(iVar2 + 0x24));
    return uVar3;
  }
switchD_00657e9d_default:
  return 0;
}


// ==== FUN_00657f10 @ 0x00657f10 ====

undefined4 FUN_00657f10(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  byte bVar5;
  
  bVar5 = 1;
  do {
    piVar1 = (int *)FUN_00657e90(param_1,bVar5);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 4))();
      if (*(char *)(iVar2 + 2) == '\x01') {
        psVar3 = (short *)(**(code **)(*piVar1 + 4))();
        psVar4 = (short *)(**(code **)(*param_2 + 4))();
        if (*psVar4 == *psVar3) {
          return 0;
        }
      }
    }
    bVar5 = bVar5 + 1;
  } while (bVar5 < 5);
  return 1;
}


// ==== FUN_00657f80 @ 0x00657f80 ====

undefined4 FUN_00657f80(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  
  bVar3 = 1;
  do {
    piVar1 = (int *)FUN_00657e90(param_2,bVar3);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 4))();
      if ((*(char *)(iVar2 + 2) == *(char *)(param_1 + 2)) &&
         (*(char *)(iVar2 + 3) == *(char *)(param_1 + 3))) {
        return 0;
      }
    }
    bVar3 = bVar3 + 1;
    if (4 < bVar3) {
      return 1;
    }
  } while( true );
}


// ==== FUN_00657fe0 @ 0x00657fe0 ====

undefined1 FUN_00657fe0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar3 = (**(code **)(*piVar2 + 4))();
  piVar2 = (int *)(**(code **)(*DAT_00b5ab68 + 8))(*(undefined2 *)(iVar3 + 0x24));
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  cVar1 = *(char *)(iVar3 + 2);
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      cVar1 = FUN_00657f10(param_1,piVar2);
      if (cVar1 == '\0') {
        return 0;
      }
    }
    else if ((cVar1 == '\x02') && (cVar1 = FUN_00657f80(iVar3,param_1), cVar1 == '\0')) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00658060 @ 0x00658060 ====

void FUN_00658060(byte param_1)

{
  void *in_ECX;
  
  FUN_00657e20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658080 @ 0x00658080 ====

void FUN_00658080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5790;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006580a0 @ 0x006580a0 ====

int FUN_006580a0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006580b0 @ 0x006580b0 ====

void FUN_006580b0(void)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = 0;
  *(undefined2 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  return;
}


// ==== FUN_006580d0 @ 0x006580d0 ====

void FUN_006580d0(void)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = 0;
  *(undefined2 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  return;
}


// ==== FUN_006580f0 @ 0x006580f0 ====

undefined2 FUN_006580f0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 6);
}


// ==== FUN_00658100 @ 0x00658100 ====

undefined4 FUN_00658100(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x110);
}


// ==== FUN_00658110 @ 0x00658110 ====

void FUN_00658110(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5790;
  return;
}


// ==== FUN_00658120 @ 0x00658120 ====

void FUN_00658120(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d57b0;
  *(undefined1 *)((int)in_ECX + 0xe) = 0;
  *(undefined1 *)(in_ECX + 0x49) = 0;
  return;
}


// ==== FUN_00658140 @ 0x00658140 ====

void FUN_00658140(void)

{
  FUN_00658170();
  return;
}


// ==== FUN_00658150 @ 0x00658150 ====

void FUN_00658150(byte param_1)

{
  void *in_ECX;
  
  FUN_00658110();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658170 @ 0x00658170 ====

void FUN_00658170(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined1 *)(in_ECX + 2) = *(undefined1 *)(param_1 + 2);
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 10);
    *(char *)(uVar2 + 10 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_006581bb;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 5) = 0;
LAB_006581bb:
  *(undefined4 *)(in_ECX + 0x86) = *(undefined4 *)(param_1 + 0x86);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(in_ECX + 0x8a) = *(undefined4 *)(param_1 + 0x8a);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(in_ECX + 0x8e) = *(undefined4 *)(param_1 + 0x8e);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x120);
    *(char *)(uVar2 + 0x120 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x90) = 0;
  return;
}


// ==== FUN_00658230 @ 0x00658230 ====

void FUN_00658230(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d57d0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658250 @ 0x00658250 ====

int FUN_00658250(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00658260 @ 0x00658260 ====

void FUN_00658260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d57d0;
  return;
}


// ==== FUN_00658270 @ 0x00658270 ====

void FUN_00658270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d57e0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_00658280 @ 0x00658280 ====

void FUN_00658280(void)

{
  FUN_006582b0();
  return;
}


// ==== FUN_00658290 @ 0x00658290 ====

void FUN_00658290(byte param_1)

{
  void *in_ECX;
  
  FUN_00658260();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006582b0 @ 0x006582b0 ====

void FUN_006582b0(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_006582d8;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_006582d8:
  *(undefined1 *)((int)in_ECX + 0x1b) = *(undefined1 *)((int)param_1 + 0x1b);
  in_ECX[0xe] = param_1[0xe];
  puVar4 = (undefined4 *)(param_1 + 0xf);
  puVar5 = (undefined4 *)(in_ECX + 0xf);
  for (iVar3 = 0x4b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return;
}


// ==== FUN_00658300 @ 0x00658300 ====

void FUN_00658300(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d57f0;
  return;
}


// ==== FUN_00658310 @ 0x00658310 ====

void FUN_00658310(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d57f0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658330 @ 0x00658330 ====

int FUN_00658330(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_00658340 @ 0x00658340 ====

void FUN_00658340(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x30))(&param_1);
                    /* WARNING: Could not recover jumptable at 0x00658362. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))();
  return;
}


// ==== FUN_00658370 @ 0x00658370 ====

void FUN_00658370(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c348;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d589c;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d57f0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006583e0 @ 0x006583e0 ====

bool FUN_006583e0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(&param_1);
  return iVar1 != 0;
}


// ==== FUN_00658400 @ 0x00658400 ====

void FUN_00658400(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar1 = unaff_ESI;
                    /* WARNING: Could not recover jumptable at 0x0065841f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  return;
}


// ==== FUN_00658430 @ 0x00658430 ====

void FUN_00658430(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xc) = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 0xe + in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x80);
  *(undefined1 *)(in_ECX + 0xe) = 0;
  return;
}


// ==== FUN_00658460 @ 0x00658460 ====

void FUN_00658460(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c365;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d589c;
  local_4 = 0;
  *(undefined1 *)((int)in_ECX + 0xe) = 0;
  puVar1 = operator_new(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009d58b8;
    puVar1[1] = &PTR_FUN_009d5894;
    puVar1[6] = 0;
    puVar1[6] = puVar1[6] + 1;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = puVar1 + 2;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
  }
  in_ECX[1] = puVar1;
  pvVar2 = operator_new(0x48);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_006589f0(in_ECX[1]);
  in_ECX[2] = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00658520 @ 0x00658520 ====

void FUN_00658520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d580c;
  return;
}


// ==== FUN_00658530 @ 0x00658530 ====

void FUN_00658530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5824;
  return;
}


// ==== FUN_00658540 @ 0x00658540 ====

void FUN_00658540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d587c;
  return;
}


// ==== FUN_00658550 @ 0x00658550 ====

void FUN_00658550(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d580c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658570 @ 0x00658570 ====

void FUN_00658570(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5824;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658590 @ 0x00658590 ====

void FUN_00658590(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d587c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006585b0 @ 0x006585b0 ====

void FUN_006585b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5894;
  return;
}


// ==== FUN_006585c0 @ 0x006585c0 ====

void FUN_006585c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5894;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006585e0 @ 0x006585e0 ====

void FUN_006585e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00658600();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658600 @ 0x00658600 ====

void FUN_00658600(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_0098c383;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d58b8;
  local_4 = 1;
  if ((void *)in_ECX[8] == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009d5894;
    *in_ECX = &PTR_FUN_009d580c;
    ExceptionList = pvVar1;
    return;
  }
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_00658670 @ 0x00658670 ====

void FUN_00658670(byte param_1)

{
  void *in_ECX;
  
  FUN_00658370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658690 @ 0x00658690 ====

void * FUN_00658690(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098c39b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x24);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x10);
      *(undefined4 *)((int)param_2 + 8) = *(undefined4 *)(in_ECX + 0x20);
      *(void **)(in_ECX + 0x20) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)((int)param_2 + 4);
    }
    *(undefined4 *)((int)param_2 + 4) = 0;
    *(int *)((int)param_2 + 0xc) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0xc) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ad8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xc) = *(int *)((int)param_2 + 0xc) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00658760 @ 0x00658760 ====

undefined4 FUN_00658760(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xc) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ad8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xc);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xc);
    }
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(in_ECX + 0x24);
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -1;
    *(int *)(in_ECX + 0x24) = param_2;
  }
  return 0;
}


// ==== FUN_006587e0 @ 0x006587e0 ====

void FUN_006587e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d58d0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,1,FUN_006ef6d0);
  return;
}


// ==== FUN_00658800 @ 0x00658800 ====

void FUN_00658800(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c3c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d58d8;
  local_4 = 1;
  if ((void *)in_ECX[0xc] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d58d0;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,1,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d587c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_00658880 @ 0x00658880 ====

undefined4 * FUN_00658880(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ad8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x34);
  *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x30);
    *(undefined4 **)(in_ECX + 0x30) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x34) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00658930 @ 0x00658930 ====

void FUN_00658930(byte param_1)

{
  void *in_ECX;
  
  FUN_006587e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658950 @ 0x00658950 ====

void FUN_00658950(byte param_1)

{
  void *in_ECX;
  
  FUN_00658800();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658970 @ 0x00658970 ====

void FUN_00658970(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c3d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d58d8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d58d0;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,1,FUN_00607500,FUN_006ef6d0);
  in_ECX[10] = 0;
  in_ECX[10] = in_ECX[10] + 1;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = in_ECX + 2;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006589f0 @ 0x006589f0 ====

void FUN_006589f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c3f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d58f4;
  FUN_00658970();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00658a50 @ 0x00658a50 ====

void FUN_00658a50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00658a70(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00658a70 @ 0x00658a70 ====

void FUN_00658a70(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00658a70(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00658a70(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00658ab0 @ 0x00658ab0 ====

void FUN_00658ab0(undefined4 *param_1)

{
  int *in_ECX;
  
  FUN_00658ad0(*param_1);
  (**(code **)(*in_ECX + 0x3c))(param_1);
  return;
}


// ==== FUN_00658ad0 @ 0x00658ad0 ====

void FUN_00658ad0(void *param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    _free(param_1);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00658b00 @ 0x00658b00 ====

void FUN_00658b00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00658b20(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00658b20 @ 0x00658b20 ====

void FUN_00658b20(undefined4 *param_1)

{
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00658b20(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00658b20(param_1[3]);
  }
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    _free((void *)*param_1);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1);
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00658b80 @ 0x00658b80 ====

void FUN_00658b80(byte param_1)

{
  void *in_ECX;
  
  FUN_00658ba0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658ba0 @ 0x00658ba0 ====

void FUN_00658ba0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098c423;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d58f4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00658b20(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00658800();
  *in_ECX = &PTR_FUN_009d5824;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00658c10 @ 0x00658c10 ====

void FUN_00658c10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5980;
  return;
}


// ==== FUN_00658c20 @ 0x00658c20 ====

void FUN_00658c20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5980;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658c40 @ 0x00658c40 ====

int FUN_00658c40(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00658c50 @ 0x00658c50 ====

void FUN_00658c50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5994;
  local_4 = 0;
  in_ECX[3] = &PTR_FUN_009a5784;
  _eh_vector_destructor_iterator_(in_ECX + 4,0x60,5,FUN_004815a0);
  *in_ECX = &PTR_FUN_009d5980;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00658cb0 @ 0x00658cb0 ====

undefined4 FUN_00658cb0(void)

{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_retaddr;
  byte local_101;
  undefined1 local_100 [256];
  
  local_101 = 0;
  if (*(int *)(in_ECX + 0x1f0) != 0) {
    uVar5 = 0;
    do {
      puVar1 = (uint *)(uVar5 * 0x60 + 0x6c + in_ECX);
      uVar4 = 0;
      if (*puVar1 != 0) {
        do {
          piVar3 = (int *)(**(code **)(*DAT_00b5a760 + 8))
                                    (*(undefined2 *)(in_ECX + (uVar4 + 4 + uVar5 * 8) * 0xc));
          cVar2 = (**(code **)(*piVar3 + 0x10))(unaff_retaddr);
          if (cVar2 == '\x01') {
            return 1;
          }
          uVar4 = (uint)(byte)((char)uVar4 + 1);
        } while (uVar4 < *puVar1);
      }
      local_101 = local_101 + 1;
      uVar5 = (uint)local_101;
    } while (uVar5 < *(uint *)(in_ECX + 0x1f0));
  }
  FUN_0044a580(local_100,&DAT_009d5978,s_Cannot_Find_This___________Item_i_009d594c);
  FUN_00797b80(local_100);
  return 0;
}


// ==== FUN_00658d70 @ 0x00658d70 ====

void FUN_00658d70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c44a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5994;
  local_4 = 0;
  in_ECX[3] = &PTR_FUN_009a5784;
  _eh_vector_constructor_iterator_
            (in_ECX + 4,0x60,5,(_func_void_void_ptr *)&LAB_00481580,FUN_004815a0);
  in_ECX[0x7c] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00658de0 @ 0x00658de0 ====

void FUN_00658de0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = *param_1;
  *(undefined2 *)(in_ECX + 6) = param_1[1];
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 2);
  FUN_00658ea0();
  return;
}


// ==== FUN_00658e10 @ 0x00658e10 ====

void FUN_00658e10(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  return;
}


// ==== FUN_00658ea0 @ 0x00658ea0 ====

void FUN_00658ea0(int param_1)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int local_8;
  
  pcVar5 = (char *)(in_ECX + 4);
  iVar4 = param_1 - in_ECX;
  local_8 = 5;
  do {
    uVar3 = 0;
    pcVar2 = pcVar5;
    do {
      cVar1 = pcVar2[iVar4];
      *pcVar2 = cVar1;
      if (cVar1 == '\0') goto LAB_00658ee7;
      uVar3 = uVar3 + 1;
      pcVar2 = pcVar2 + 1;
    } while (uVar3 < 0x19);
    *pcVar5 = '\0';
LAB_00658ee7:
    *(undefined2 *)(pcVar5 + 0x1a) = *(undefined2 *)(pcVar5 + iVar4 + 0x1a);
    FUN_00658e10(pcVar5 + iVar4 + 0x1c);
    pcVar5 = pcVar5 + 0x60;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      *(undefined4 *)(in_ECX + 0x1e4) = *(undefined4 *)(param_1 + 0x1e4);
      return;
    }
  } while( true );
}


// ==== FUN_00658f30 @ 0x00658f30 ====

void FUN_00658f30(byte param_1)

{
  void *in_ECX;
  
  FUN_00658c50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658f50 @ 0x00658f50 ====

void FUN_00658f50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a34;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00658f70 @ 0x00658f70 ====

int FUN_00658f70(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00658fb0 @ 0x00658fb0 ====

void FUN_00658fb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a34;
  return;
}


// ==== FUN_00658fc0 @ 0x00658fc0 ====

uint FUN_00658fc0(short param_1)

{
  uint uVar1;
  int in_ECX;
  short *psVar2;
  
  uVar1 = 0;
  if (*(ushort *)(in_ECX + 0x20) != 0) {
    psVar2 = (short *)(in_ECX + 0x28);
    do {
      if (param_1 == *psVar2) {
        return CONCAT31((int3)(uVar1 >> 8),1);
      }
      uVar1 = uVar1 + 1;
      psVar2 = psVar2 + 10;
    } while ((int)uVar1 < (int)(uint)*(ushort *)(in_ECX + 0x20));
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00658ff0 @ 0x00658ff0 ====

void FUN_00658ff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a4c;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_00659000 @ 0x00659000 ====

undefined4 FUN_00659000(short *param_1)

{
  int *piVar1;
  short *psVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  undefined1 auStack_fe [254];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a760 + 8))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  psVar2 = (short *)(**(code **)(*piVar1 + 4))();
  if (*psVar2 == 0) {
    uVar3 = FUN_0044a580(auStack_fe + -6,s___FAILED___NULL_SET__d_________G_009d59ac,
                         (uint)param_1 & 0xffff);
    FUN_00797b80(uVar3);
    return 0;
  }
  uVar4 = (**(code **)(*DAT_00b5b0a0 + 0xc))();
  uVar4 = uVar4 % 100000;
  if (uVar4 < *(uint *)(psVar2 + 0x10)) {
    uVar5 = 0;
    uVar7 = 0;
    do {
      uVar5 = uVar5 + *(int *)(psVar2 + (uVar7 + 2) * 10);
      if (uVar4 < uVar5) {
        *param_1 = psVar2[uVar7 * 10 + 0x12];
        uVar4 = (**(code **)(*DAT_00b5b0a0 + 0x10))(0,100000);
        if (*(uint *)(psVar2 + uVar7 * 10 + 0x16) < uVar4) {
          param_1[2] = 0;
          param_1[3] = 0;
          return 1;
        }
        uVar4 = (**(code **)(*DAT_00b5b0a0 + 0x10))(0,100000);
        if (*(uint *)(psVar2 + uVar7 * 10 + 0x18) < uVar4) {
          param_1[2] = 1;
          param_1[3] = 0;
          return 1;
        }
        uVar4 = (**(code **)(*DAT_00b5b0a0 + 0x10))(0,100000);
        if (*(uint *)(psVar2 + uVar7 * 10 + 0x1a) < uVar4) {
          param_1[2] = 2;
          param_1[3] = 0;
          return 1;
        }
        param_1[2] = 6;
        param_1[3] = 0;
        return 1;
      }
      bVar6 = (char)uVar7 + 1;
      uVar7 = (uint)bVar6;
    } while (bVar6 < 0x32);
    uVar3 = FUN_0044a580(auStack_fe + -6,s___FAILED___cannot_find_right_ite_009d59e0,uVar4,uVar5,
                         *(uint *)(psVar2 + 0x10));
    FUN_00797b80(uVar3);
  }
  return 0;
}


// ==== FUN_00659190 @ 0x00659190 ====

void FUN_00659190(void)

{
  FUN_006591c0();
  return;
}


// ==== FUN_006591a0 @ 0x006591a0 ====

void FUN_006591a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00658fb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006591c0 @ 0x006591c0 ====

void FUN_006591c0(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_006591e8;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_006591e8:
  in_ECX[0xe] = param_1[0xe];
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  puVar4 = (undefined4 *)(param_1 + 0x12);
  puVar5 = (undefined4 *)(in_ECX + 0x12);
  for (iVar3 = 0xfa; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return;
}


// ==== FUN_00659210 @ 0x00659210 ====

undefined2 FUN_00659210(int param_1)

{
  int in_ECX;
  
  return CONCAT11((char)(*(ushort *)(in_ECX + 4) >> 8),
                  *(ushort *)(in_ECX + 4) < *(ushort *)(param_1 + 4));
}


// ==== FUN_00659250 @ 0x00659250 ====

void FUN_00659250(undefined2 param_1)

{
  undefined4 *in_ECX;
  
  *(undefined2 *)(in_ECX + 1) = param_1;
  *in_ECX = &PTR_FUN_009d5a64;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_00659270 @ 0x00659270 ====

void FUN_00659270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a64;
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00659290 @ 0x00659290 ====

void FUN_00659290(undefined4 param_1)

{
  void *pvVar1;
  uint uVar2;
  int in_ECX;
  
  if (*(uint *)(in_ECX + 8) % 10 != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 8) * 4) = param_1;
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
    return;
  }
  pvVar1 = operator_new(*(uint *)(in_ECX + 8) * 4 + 0x28);
  uVar2 = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    do {
      *(undefined4 *)((int)pvVar1 + uVar2 * 4) = *(undefined4 *)(*(int *)(in_ECX + 0xc) + uVar2 * 4)
      ;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(in_ECX + 8));
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_00659300 @ 0x00659300 ====

undefined4 FUN_00659300(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8) + -1;
  if (iVar1 == 0) {
    return **(undefined4 **)(in_ECX + 0xc);
  }
  iVar1 = (**(code **)(*DAT_00b5b0a0 + 0x10))(0,iVar1);
  return *(undefined4 *)(*(int *)(in_ECX + 0xc) + iVar1 * 4);
}


// ==== FUN_00659330 @ 0x00659330 ====

void FUN_00659330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a64;
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00659370 @ 0x00659370 ====

void FUN_00659370(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a6c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00659390 @ 0x00659390 ====

int FUN_00659390(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006593a0 @ 0x006593a0 ====

void FUN_006593a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a6c;
  return;
}


// ==== FUN_006593b0 @ 0x006593b0 ====

void FUN_006593b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a7c;
  *(undefined1 *)(in_ECX + 3) = 0;
  return;
}


// ==== FUN_006593c0 @ 0x006593c0 ====

void FUN_006593c0(void)

{
  FUN_006593f0();
  return;
}


// ==== FUN_006593d0 @ 0x006593d0 ====

void FUN_006593d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006593a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006593f0 @ 0x006593f0 ====

void FUN_006593f0(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined4 *)(in_ECX + 2) = *(undefined4 *)(param_1 + 2);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 8);
    *(char *)(uVar2 + 8 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0065942b;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x80);
  *(undefined1 *)(in_ECX + 4) = 0;
LAB_0065942b:
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x46) = *(undefined4 *)(param_1 + 0x46);
  return;
}


// ==== FUN_00659450 @ 0x00659450 ====

void FUN_00659450(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5a8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00659470 @ 0x00659470 ====

int FUN_00659470(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00659480 @ 0x00659480 ====

undefined1 FUN_00659480(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 300);
}


// ==== FUN_00659490 @ 0x00659490 ====

bool FUN_00659490(void)

{
  char cVar1;
  int *in_ECX;
  
  if (in_ECX[0xb] == 0) {
    return false;
  }
  if (in_ECX[2] == 4) {
    return true;
  }
  cVar1 = (**(code **)(*in_ECX + 0x14))();
  return cVar1 == '\0';
}


// ==== FUN_006594b0 @ 0x006594b0 ====

undefined4 FUN_006594b0(void)

{
  int iVar1;
  int in_ECX;
  
  if (((((*(int *)(in_ECX + 0x2c) == 0) ||
        ((iVar1 = *(int *)(in_ECX + 0xc), iVar1 == 2 && (*(int *)(in_ECX + 0x10) == 0x206)))) ||
       ((iVar1 == 0 && (*(int *)(in_ECX + 0x10) == 4)))) || (*(int *)(in_ECX + 8) == 4)) ||
     ((iVar1 == 6 && ((*(int *)(in_ECX + 0x10) == 0x601 || (*(int *)(in_ECX + 0x10) == 0x604)))))) {
    return 1;
  }
  return 0;
}


// ==== FUN_00659500 @ 0x00659500 ====

undefined4 FUN_00659500(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 4) {
    iVar1 = *(int *)(in_ECX + 0x10);
    if (iVar1 < 0xd) {
      if ((iVar1 == 0xc) || ((0 < iVar1 && (iVar1 < 3)))) {
        return 0;
      }
    }
    else if ((0x40e < iVar1) && (iVar1 < 0x411)) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00659530 @ 0x00659530 ====

void FUN_00659530(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0x3b] = &PTR_FUN_009a5980;
  in_ECX[0x2d] = &PTR_FUN_009a5978;
  *in_ECX = &PTR_FUN_009d5a8c;
  return;
}


// ==== FUN_00659550 @ 0x00659550 ====

void FUN_00659550(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5aac;
  *(undefined1 *)((int)in_ECX + 0x3a) = 0;
  in_ECX[0x2d] = &PTR_FUN_009a5978;
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = &PTR_FUN_009a5980;
  in_ECX[0x3f] = 0;
  return;
}


// ==== FUN_00659580 @ 0x00659580 ====

void FUN_00659580(void)

{
  FUN_006597c0();
  return;
}


// ==== FUN_00659590 @ 0x00659590 ====

void FUN_00659590(undefined1 *param_1)

{
  undefined1 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x58);
  puVar2 = (undefined4 *)(param_1 + 0x5c);
  puVar3 = (undefined4 *)(in_ECX + 0x5c);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)(in_ECX + 0x78) = *(undefined2 *)(param_1 + 0x78);
  *(undefined2 *)(in_ECX + 0x7a) = *(undefined2 *)(param_1 + 0x7a);
  return;
}


// ==== FUN_00659680 @ 0x00659680 ====

void FUN_00659680(undefined4 *param_1)

{
  char cVar1;
  undefined4 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  *(undefined2 *)(in_ECX + 4) = *(undefined2 *)(param_1 + 4);
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  *(undefined2 *)(in_ECX + 8) = *(undefined2 *)(param_1 + 8);
  in_ECX[9] = param_1[9];
  *(undefined2 *)(in_ECX + 10) = *(undefined2 *)(param_1 + 10);
  in_ECX[0xb] = param_1[0xb];
  *(undefined1 *)(in_ECX + 0xc) = *(undefined1 *)(param_1 + 0xc);
  *(undefined1 *)((int)in_ECX + 0x31) = *(undefined1 *)((int)param_1 + 0x31);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x32);
    *(char *)(uVar2 + 0x32 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_006596fb;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x40);
  *(undefined1 *)((int)in_ECX + 0x32) = 0;
LAB_006596fb:
  *(undefined2 *)((int)in_ECX + 0x72) = *(undefined2 *)((int)param_1 + 0x72);
  *(undefined1 *)(in_ECX + 0x1d) = *(undefined1 *)(param_1 + 0x1d);
  *(undefined2 *)((int)in_ECX + 0x76) = *(undefined2 *)((int)param_1 + 0x76);
  *(undefined2 *)(in_ECX + 0x1e) = *(undefined2 *)(param_1 + 0x1e);
  *(undefined1 *)((int)in_ECX + 0x7a) = *(undefined1 *)((int)param_1 + 0x7a);
  *(undefined1 *)((int)in_ECX + 0x7b) = *(undefined1 *)((int)param_1 + 0x7b);
  *(undefined2 *)(in_ECX + 0x1f) = *(undefined2 *)(param_1 + 0x1f);
  *(undefined2 *)((int)in_ECX + 0x7e) = *(undefined2 *)((int)param_1 + 0x7e);
  *(undefined2 *)(in_ECX + 0x20) = *(undefined2 *)(param_1 + 0x20);
  in_ECX[0x21] = param_1[0x21];
  in_ECX[0x22] = param_1[0x22];
  in_ECX[0x23] = param_1[0x23];
  in_ECX[0x24] = param_1[0x24];
  in_ECX[0x25] = param_1[0x25];
  *(undefined2 *)(in_ECX + 0x26) = *(undefined2 *)(param_1 + 0x26);
  return;
}


// ==== FUN_006597a0 @ 0x006597a0 ====

void FUN_006597a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00659530();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006597c0 @ 0x006597c0 ====

void FUN_006597c0(undefined2 *param_1)

{
  undefined2 *in_ECX;
  
  *in_ECX = *param_1;
  FUN_00659680(param_1 + 2);
  FUN_00659590(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x8e) = *(undefined4 *)(param_1 + 0x8e);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(in_ECX + 0x92) = *(undefined4 *)(param_1 + 0x92);
  *(undefined1 *)(in_ECX + 0x94) = *(undefined1 *)(param_1 + 0x94);
  return;
}


// ==== FUN_00659820 @ 0x00659820 ====

void FUN_00659820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00659830 @ 0x00659830 ====

void FUN_00659830(void)

{
  return;
}


// ==== FUN_00659840 @ 0x00659840 ====

void FUN_00659840(void)

{
  return;
}


// ==== FUN_00659850 @ 0x00659850 ====

int FUN_00659850(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_00659860 @ 0x00659860 ====

void FUN_00659860(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00659870 @ 0x00659870 ====

undefined2 FUN_00659870(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xc);
}


// ==== FUN_00659880 @ 0x00659880 ====

void FUN_00659880(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xe) = param_1;
  return;
}


// ==== FUN_00659890 @ 0x00659890 ====

void FUN_00659890(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x2c) = param_1;
  return;
}


// ==== FUN_006598a0 @ 0x006598a0 ====

int FUN_006598a0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x30) + 4))();
  return iVar1 + 4;
}


// ==== FUN_006598b0 @ 0x006598b0 ====

void FUN_006598b0(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006598b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x2c))();
  return;
}


// ==== FUN_006598c0 @ 0x006598c0 ====

int FUN_006598c0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x30) + 4))();
  return iVar1 + 0xa0;
}


// ==== FUN_006598d0 @ 0x006598d0 ====

void FUN_006598d0(ushort param_1)

{
  int in_ECX;
  
  if (param_1 < *(byte *)(in_ECX + 0x2a)) {
    *(undefined2 *)(in_ECX + 0x10 + (uint)param_1 * 2) = 0;
  }
  return;
}


// ==== FUN_006598f0 @ 0x006598f0 ====

void FUN_006598f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = param_1;
  return;
}


// ==== FUN_00659900 @ 0x00659900 ====

undefined4 FUN_00659900(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_00659910 @ 0x00659910 ====

undefined1 FUN_00659910(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00659920 @ 0x00659920 ====

undefined1 FUN_00659920(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 9);
}


// ==== FUN_00659930 @ 0x00659930 ====

void FUN_00659930(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 9) = param_1;
  return;
}


// ==== FUN_00659940 @ 0x00659940 ====

void FUN_00659940(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 10) = param_1;
  return;
}


// ==== FUN_00659950 @ 0x00659950 ====

undefined1 FUN_00659950(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 10);
}


// ==== FUN_00659960 @ 0x00659960 ====

void FUN_00659960(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xb) = param_1;
  return;
}


// ==== FUN_00659970 @ 0x00659970 ====

undefined1 FUN_00659970(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xb);
}


// ==== FUN_00659980 @ 0x00659980 ====

void FUN_00659980(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = param_1;
  return;
}


// ==== FUN_00659990 @ 0x00659990 ====

undefined4 FUN_00659990(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x34);
}


// ==== FUN_006599a0 @ 0x006599a0 ====

undefined1 FUN_006599a0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x38);
}


// ==== FUN_006599b0 @ 0x006599b0 ====

void FUN_006599b0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3c) = *param_1;
  *(undefined4 *)(in_ECX + 0x40) = param_1[1];
  *(undefined4 *)(in_ECX + 0x44) = param_1[2];
  *(undefined4 *)(in_ECX + 0x48) = param_1[3];
  return;
}


// ==== FUN_006599d0 @ 0x006599d0 ====

int FUN_006599d0(void)

{
  int in_ECX;
  
  return in_ECX + 0x3c;
}


// ==== FUN_006599e0 @ 0x006599e0 ====

void FUN_006599e0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x4c) = *param_1;
  *(undefined4 *)(in_ECX + 0x50) = param_1[1];
  *(undefined4 *)(in_ECX + 0x54) = param_1[2];
  return;
}


// ==== FUN_00659a00 @ 0x00659a00 ====

int FUN_00659a00(void)

{
  int in_ECX;
  
  return in_ECX + 0x4c;
}


// ==== FUN_00659a10 @ 0x00659a10 ====

undefined4 FUN_00659a10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x58);
}


// ==== FUN_00659a20 @ 0x00659a20 ====

void FUN_00659a20(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x58) = param_1;
  return;
}


// ==== FUN_00659a60 @ 0x00659a60 ====

undefined4 FUN_00659a60(short *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  
  if (*param_1 != 0) {
    puVar1 = (undefined4 *)(in_ECX + 0xc);
    puVar5 = puVar1;
    for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *(undefined4 *)param_1;
      param_1 = param_1 + 2;
      puVar5 = puVar5 + 1;
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))
                              (CONCAT22((short)((uint)puVar1 >> 0x10),*(undefined2 *)puVar1));
    *(int **)(in_ECX + 0x30) = piVar2;
    if (piVar2 != (int *)0x0) {
      *(undefined1 *)(in_ECX + 8) = 1;
      *(undefined1 *)(in_ECX + 10) = 0;
      *(undefined1 *)(in_ECX + 0xb) = 0;
      iVar4 = (**(code **)(*piVar2 + 4))();
      *(bool *)(in_ECX + 0x38) = *(short *)(iVar4 + 0x11a) != 0;
      uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
      *(undefined4 *)(in_ECX + 0x58) = uVar3;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00659ad0 @ 0x00659ad0 ====

void FUN_00659ad0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  *(undefined1 *)(in_ECX + 0x38) = 0;
  FUN_00797a50(in_ECX + 0xc,0,0x24);
  FUN_00797a50(in_ECX + 0x3c,0,0x10);
  FUN_00797a50(in_ECX + 0x4c,0,0xc);
  return;
}


// ==== FUN_00659b10 @ 0x00659b10 ====

void FUN_00659b10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c468;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5c4c;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 0xb) = 0;
  in_ECX[0xd] = 10;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  FUN_00797a50(in_ECX + 3,0,0x24);
  FUN_00797a50(in_ECX + 0xf,0,0x10);
  FUN_00797a50(in_ECX + 0x13,0,0xc);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00659b90 @ 0x00659b90 ====

undefined4 FUN_00659b90(undefined4 param_1)

{
  undefined2 *puVar1;
  char cVar2;
  undefined4 uVar3;
  undefined2 extraout_var;
  int *piVar4;
  int iVar5;
  int in_ECX;
  undefined2 *puStack_114;
  undefined4 uStack_110;
  
  uStack_110 = param_1;
  puStack_114 = (undefined2 *)0x659bab;
  uVar3 = (**(code **)(*DAT_00b5a69c + 4))();
  puVar1 = (undefined2 *)(in_ECX + 0xc);
  puStack_114 = puVar1;
  cVar2 = (**(code **)(*DAT_00b5aa10 + 8))(uVar3);
  if (cVar2 == '\0') {
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  (**(code **)(*DAT_00b5a69c + 8))(uVar3);
  piVar4 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(CONCAT22(extraout_var,*puVar1));
  *(int **)(in_ECX + 0x30) = piVar4;
  if (piVar4 == (int *)0x0) {
    puStack_114 = (undefined2 *)((uint)puStack_114 & 0xffffff00);
    uVar3 = FUN_0044a580(&puStack_114,s_Index___d_009d5acc,*puVar1);
    FUN_00797b80(uVar3);
    return 0;
  }
  *(undefined1 *)(in_ECX + 8) = 1;
  *(undefined1 *)(in_ECX + 10) = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  iVar5 = (**(code **)(*piVar4 + 4))();
  *(bool *)(in_ECX + 0x38) = *(short *)(iVar5 + 0x11a) != 0;
  uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
  *(undefined4 *)(in_ECX + 0x58) = uVar3;
  return 1;
}


// ==== FUN_00659c70 @ 0x00659c70 ====

uint FUN_00659c70(ushort param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  undefined1 auStack_100 [256];
  
  iVar2 = (**(code **)(*in_ECX + 0x2c))();
  uVar1 = *(ushort *)(iVar2 + 0x72);
  if (uVar1 < param_1) {
    *(ushort *)(in_ECX + 6) = uVar1;
    FUN_0044a580(auStack_100,&DAT_009d5c40,s__ASSERT__StackCount_is_Larger_Th_009d5ad8);
    uVar3 = FUN_00797b80(auStack_100);
    return uVar3 & 0xffffff00;
  }
  *(ushort *)(in_ECX + 6) = param_1;
  return CONCAT31((int3)(CONCAT22((short)((uint)iVar2 >> 0x10),uVar1) >> 8),1);
}


// ==== FUN_00659cd0 @ 0x00659cd0 ====

uint FUN_00659cd0(ushort param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  uint uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(byte *)(in_ECX + 0x2a) <= param_1) {
    FUN_0044a580(local_100,&DAT_009d5c40,s_Set_Item_SetSocket_FAil___Invali_009d5b0c);
    uVar2 = FUN_00797b80(local_100);
    return uVar2 & 0xffffff00;
  }
  puVar1 = (undefined2 *)(in_ECX + 0x10 + (uint)param_1 * 2);
  if (*(short *)(in_ECX + 0x10 + (uint)param_1 * 2) == 0) {
    *puVar1 = param_2;
    return CONCAT31((int3)((uint)puVar1 >> 8),1);
  }
  FUN_0044a580(local_100,&DAT_009d5c40,s_Item_SetSocket_FAil___Exist_Sock_009d5b44);
  uVar2 = FUN_00797b80(local_100);
  return uVar2 & 0xffffff00;
}


// ==== FUN_00659d70 @ 0x00659d70 ====

undefined4 FUN_00659d70(undefined1 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  undefined1 auStack_500 [256];
  undefined1 auStack_400 [256];
  undefined1 auStack_300 [256];
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x48))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0xc))();
    if (cVar1 != '\0') {
      switch(param_1) {
      case 0:
        break;
      case 1:
        iVar3 = (**(code **)(*piVar2 + 4))();
        if (*(char *)(iVar3 + 0xa5) == '\0') {
          FUN_0044a670(s_CAN_T_ADD_SOCKET___MAX_COUNT_OVE_009d5b8c);
          FUN_00797b80(auStack_500);
          return 0;
        }
        break;
      case 2:
        iVar3 = (**(code **)(*piVar2 + 4))();
        if (*(char *)(iVar3 + 0xa6) == '\0') {
          FUN_0044a670(s_CAN_T_ADD_SOCKET___MAX_COUNT_OVE_009d5bb0);
          FUN_00797b80(auStack_200);
          return 0;
        }
        break;
      case 3:
        iVar3 = (**(code **)(*piVar2 + 4))();
        if (*(char *)(iVar3 + 0xa7) == '\0') {
          FUN_0044a670(s_CAN_T_ADD_SOCKET___MAX_COUNT_OVE_009d5bd4);
          FUN_00797b80(auStack_400);
          return 0;
        }
        break;
      case 4:
        iVar3 = (**(code **)(*piVar2 + 4))();
        if (*(char *)(iVar3 + 0xa8) == '\0') {
          FUN_0044a670(s_CAN_T_ADD_SOCKET___MAX_COUNT_OVE_009d5bf8);
          FUN_00797b80(auStack_300);
          return 0;
        }
        break;
      default:
        FUN_0044a580(auStack_100,&DAT_009d5c40,s_CAN_T_ADD_SOCKET___MAX_COUNT_OVE_009d5c1c);
        FUN_00797b80(auStack_100);
        return 0;
      }
      *(undefined1 *)((int)in_ECX + 0x2a) = param_1;
      return 1;
    }
    FUN_0044a580(auStack_500,&DAT_009d5c40,s_Oh_____My_God__________009d5b70);
    FUN_00797b80(auStack_500);
  }
  return 0;
}


// ==== FUN_00659f40 @ 0x00659f40 ====

void FUN_00659f40(byte param_1)

{
  void *in_ECX;
  
  FUN_00659820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00659f60 @ 0x00659f60 ====

void FUN_00659f60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00659f70 @ 0x00659f70 ====

undefined1 FUN_00659f70(void)

{
  return 0;
}


// ==== FUN_00659f80 @ 0x00659f80 ====

undefined4 FUN_00659f80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00659f90 @ 0x00659f90 ====

void FUN_00659f90(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00659fa0 @ 0x00659fa0 ====

undefined4 FUN_00659fa0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00659fb0 @ 0x00659fb0 ====

void FUN_00659fb0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00659fc0 @ 0x00659fc0 ====

undefined4 FUN_00659fc0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00659fe0 @ 0x00659fe0 ====

void FUN_00659fe0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  (**(code **)(*DAT_00b5abdc + 8))(*(undefined4 *)(in_ECX + 0xc));
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_0065a010 @ 0x0065a010 ====

void FUN_0065a010(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *unaff_retaddr;
  
  if (*(int **)(in_ECX + 0x10) == (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x4c))(0);
  }
  else {
    iVar1 = **(int **)(in_ECX + 0xc);
    uVar2 = (**(code **)(**(int **)(in_ECX + 0x10) + 4))();
    (**(code **)(iVar1 + 0x4c))(uVar2);
  }
  iVar1 = **(int **)(in_ECX + 0xc);
  uVar2 = (**(code **)(*unaff_retaddr + 4))();
  (**(code **)(iVar1 + 0x30))(uVar2);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x38))(unaff_retaddr);
  *(int **)(in_ECX + 0x10) = unaff_retaddr;
  *(undefined1 *)(in_ECX + 0x14) = 1;
  return;
}


// ==== FUN_0065a080 @ 0x0065a080 ====

void FUN_0065a080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5cdc;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  return;
}


// ==== FUN_0065a0a0 @ 0x0065a0a0 ====

void FUN_0065a0a0(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  iVar1 = in_ECX[5];
  *(undefined1 *)(in_ECX + 5) = 0;
  if ((char)iVar1 != '\0') {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x18))();
    (**(code **)(*piVar2 + 0x10))();
    (**(code **)(*DAT_00b5accc + 0xc))();
  }
  return;
}


// ==== FUN_0065a0d0 @ 0x0065a0d0 ====

undefined4 FUN_0065a0d0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined3 uVar4;
  int *piVar3;
  undefined3 extraout_var;
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  uVar2 = (**(code **)(*(int *)in_ECX[4] + 0x20))();
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  uVar2 = (**(code **)(*(int *)in_ECX[3] + 0x20))(unaff_retaddr);
  iVar1 = in_ECX[5];
  uVar4 = (undefined3)((uint)uVar2 >> 8);
  *(undefined1 *)(in_ECX + 5) = 0;
  if ((char)iVar1 != '\0') {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x18))();
    (**(code **)(*piVar3 + 0x10))();
    (**(code **)(*DAT_00b5accc + 0xc))();
    uVar4 = extraout_var;
  }
  return CONCAT31(uVar4,1);
}


// ==== FUN_0065a130 @ 0x0065a130 ====

undefined4 FUN_0065a130(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined3 uVar4;
  int *piVar3;
  undefined3 extraout_var;
  int *in_ECX;
  
  uVar2 = (**(code **)(*(int *)in_ECX[4] + 0x24))();
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  iVar1 = in_ECX[5];
  uVar4 = (undefined3)((uint)uVar2 >> 8);
  *(undefined1 *)(in_ECX + 5) = 0;
  if ((char)iVar1 != '\0') {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x18))();
    (**(code **)(*piVar3 + 0x10))();
    (**(code **)(*DAT_00b5accc + 0xc))();
    uVar4 = extraout_var;
  }
  return CONCAT31(uVar4,1);
}


// ==== FUN_0065a180 @ 0x0065a180 ====

undefined4 FUN_0065a180(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined3 uVar4;
  int *piVar3;
  undefined3 extraout_var;
  int *in_ECX;
  
  uVar2 = (**(code **)(*(int *)in_ECX[4] + 0x28))();
  if ((char)uVar2 == '\0') {
    return uVar2;
  }
  iVar1 = in_ECX[5];
  uVar4 = (undefined3)((uint)uVar2 >> 8);
  *(undefined1 *)(in_ECX + 5) = 0;
  if ((char)iVar1 != '\0') {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x18))();
    (**(code **)(*piVar3 + 0x10))();
    (**(code **)(*DAT_00b5accc + 0xc))();
    uVar4 = extraout_var;
  }
  return CONCAT31(uVar4,1);
}


// ==== FUN_0065a1d0 @ 0x0065a1d0 ====

undefined4 FUN_0065a1d0(void)

{
  return 7;
}


// ==== FUN_0065a1e0 @ 0x0065a1e0 ====

void FUN_0065a1e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00659f60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065a200 @ 0x0065a200 ====

void FUN_0065a200(void)

{
  if (DAT_00b5b0b4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b0b4)(1);
  }
  if (DAT_00b5b0b8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b0b8)(1);
  }
  if (DAT_00b5af80 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af80)(1);
  }
  if (DAT_00b5b0bc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b0bc)(1);
  }
  if (DAT_00b5ad28 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad28)(1);
  }
  return;
}


// ==== FUN_0065a260 @ 0x0065a260 ====

int FUN_0065a260(void)

{
  int in_ECX;
  
  return in_ECX + 0x34;
}


// ==== FUN_0065a270 @ 0x0065a270 ====

undefined4 * FUN_0065a270(undefined4 *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  *param_1 = *(undefined4 *)(iVar1 + 0x14);
  param_1[1] = *(undefined4 *)(iVar1 + 0x18);
  return param_1;
}


// ==== FUN_0065a290 @ 0x0065a290 ====

void FUN_0065a290(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x8c) = param_1;
  return;
}


// ==== FUN_0065a2a0 @ 0x0065a2a0 ====

undefined4 FUN_0065a2a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x8c);
}


// ==== FUN_0065a2b0 @ 0x0065a2b0 ====

void FUN_0065a2b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0065a2b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x88) + 0x48))();
  return;
}


// ==== FUN_0065a2c0 @ 0x0065a2c0 ====

void FUN_0065a2c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0065a2c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x88) + 0x4c))();
  return;
}


// ==== FUN_0065a2d0 @ 0x0065a2d0 ====

int FUN_0065a2d0(void)

{
  int iVar1;
  undefined1 *puVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x88) + 0x10))();
  *(undefined1 *)(in_ECX + 0x71) = *(undefined1 *)(iVar1 + 1);
  puVar2 = (undefined1 *)(**(code **)(**(int **)(in_ECX + 0x88) + 0x10))();
  *(undefined1 *)(in_ECX + 0x70) = *puVar2;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x88) + 0x10))();
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(iVar1 + 0x14);
  return in_ECX + 100;
}


// ==== FUN_0065a330 @ 0x0065a330 ====

void FUN_0065a330(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [5];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(*in_ECX + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  iStack_8 = iStack_8 - iStack_10;
  iStack_10 = param_1;
  iStack_8 = param_1 + iStack_8;
  iStack_4 = (iStack_4 - iStack_c) + param_2;
  iStack_c = param_2;
  (**(code **)(*in_ECX + 0x18))(auStack_24);
  return;
}


// ==== FUN_0065a390 @ 0x0065a390 ====

void FUN_0065a390(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [5];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(*in_ECX + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  (**(code **)(*in_ECX + 0x54))
            (param_1 - (iStack_8 - iStack_10) / 2,param_2 - (iStack_4 - iStack_c) / 2,1);
  return;
}


// ==== FUN_0065a3f0 @ 0x0065a3f0 ====

uint FUN_0065a3f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 in_EAX;
  int iVar4;
  uint uVar5;
  int *in_ECX;
  int iVar6;
  
  uVar5 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)((int)in_ECX + 0x29));
  if (*(char *)((int)in_ECX + 0x29) != '\0') {
    iVar6 = *(int *)(param_1 + 0x30);
    iVar1 = *(int *)(param_1 + 0x34);
    iVar2 = *(int *)(param_1 + 0x38);
    iVar3 = *(int *)(param_1 + 0x3c);
    iVar4 = (**(code **)(*in_ECX + 0x14))();
    uVar5 = *(int *)(iVar4 + 0x14) + (iVar2 - iVar6);
    iVar6 = *(int *)(iVar4 + 0x18) + (iVar3 - iVar1);
    if ((int)uVar5 < 0) {
      uVar5 = 0;
    }
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if ((*(int *)(param_1 + 8) == 0) && (*(int *)(param_1 + 0x18) == 1)) {
      iVar1 = in_ECX[0x1e];
      iVar2 = in_ECX[0x1f];
      in_ECX[0x1e] = uVar5;
      in_ECX[0x1f] = iVar6;
      in_ECX[0x20] = uVar5 + (in_ECX[0x20] - iVar1);
      in_ECX[0x21] = in_ECX[0x1f] + (in_ECX[0x21] - iVar2);
      uVar5 = (**(code **)(*in_ECX + 0x18))(in_ECX + 0x19);
      return uVar5 & 0xffffff00;
    }
    if ((*(int *)(param_1 + 8) == 1) && (*(int *)(param_1 + 0x18) == 1)) {
      iVar1 = in_ECX[0x1e];
      iVar2 = in_ECX[0x1f];
      in_ECX[0x1f] = iVar6;
      in_ECX[0x1e] = uVar5;
      *(undefined1 *)((int)in_ECX + 0x29) = 0;
      in_ECX[0x20] = uVar5 + (in_ECX[0x20] - iVar1);
      in_ECX[0x21] = in_ECX[0x1f] + (in_ECX[0x21] - iVar2);
      uVar5 = (**(code **)(*in_ECX + 0x18))(in_ECX + 0x19);
    }
  }
  return uVar5 & 0xffffff00;
}


// ==== FUN_0065a4e0 @ 0x0065a4e0 ====

undefined4 FUN_0065a4e0(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x88);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  cVar2 = (**(code **)(*param_1 + 0x74))(piVar1);
  if (cVar2 != '\0') {
    cVar2 = (**(code **)(*piVar1 + 0x78))(param_1);
    if (cVar2 == '\0') {
      (**(code **)(*param_1 + 0x74))(0);
      return 1;
    }
    iVar3 = (**(code **)(*piVar1 + 0x38))();
    param_1[1] = iVar3;
  }
  return 1;
}


// ==== FUN_0065a530 @ 0x0065a530 ====

uint FUN_0065a530(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0x88) != 0) &&
     (uVar1 = (**(code **)(*param_1 + 0x3c))(), *(uint *)(in_ECX + 0x88) == uVar1)) {
    iVar2 = (**(code **)(*param_1 + 0x3c))();
    uVar1 = 0;
    if (iVar2 != 0) {
      piVar3 = (int *)(**(code **)(*param_1 + 0x3c))();
      uVar1 = (**(code **)(*piVar3 + 0x7c))(param_1);
      if ((char)uVar1 != '\0') {
        uVar1 = (**(code **)(*DAT_00b5a7ac + 0xc))(param_1);
      }
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0065a590 @ 0x0065a590 ====

int FUN_0065a590(void)

{
  char extraout_AL;
  char extraout_AL_00;
  undefined4 in_EAX;
  uint3 uVar1;
  uint3 extraout_var;
  uint3 extraout_var_00;
  int in_ECX;
  
  uVar1 = (uint3)((uint)in_EAX >> 8);
  if (*(char *)(in_ECX + 0x28) != '\0') {
    if (DAT_00b5a7a0 != (int *)0x0) {
      (**(code **)(*DAT_00b5a7a0 + 8))();
      uVar1 = extraout_var;
      if (extraout_AL == '\0') goto LAB_0065a5c4;
    }
    (**(code **)(*DAT_00b5a7ac + 0xc))(*(undefined4 *)(in_ECX + 0x88));
    uVar1 = extraout_var_00;
    if (extraout_AL_00 != '\0') {
      *(undefined4 *)(in_ECX + 0x88) = 0;
      *(undefined1 *)(in_ECX + 0x28) = 0;
      return CONCAT31(extraout_var_00,1);
    }
  }
LAB_0065a5c4:
  return (uint)uVar1 << 8;
}


// ==== FUN_0065a5e0 @ 0x0065a5e0 ====

void FUN_0065a5e0(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int *unaff_ESI;
  
  iVar1 = (**(code **)(*in_ECX + 0x30))(&param_2);
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7a0 + 0x10))(in_ECX + 9);
    iVar1 = (**(code **)(*in_ECX + 0x14))();
    iVar2 = *unaff_ESI - *(int *)(iVar1 + 0x14);
    iVar1 = unaff_ESI[1] - *(int *)(iVar1 + 0x18);
    if ((((in_ECX[0x14] <= iVar2) && (in_ECX[0x15] <= iVar1)) && (iVar2 < in_ECX[0x16])) &&
       (iVar1 < in_ECX[0x17])) {
      *(undefined1 *)((int)in_ECX + 0x29) = 1;
      in_ECX[0xb] = iVar2;
      in_ECX[0xc] = iVar1;
    }
  }
  return;
}


// ==== FUN_0065a650 @ 0x0065a650 ====

void FUN_0065a650(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c49e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d5d60;
  local_4 = 2;
  if (*(char *)(in_ECX + 10) != '\0') {
    FUN_0065a590();
  }
  (**(code **)(*DAT_00b5b0b8 + 8))(in_ECX[8]);
  if (0xf < (uint)in_ECX[0x13]) {
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0x13] = 0xf;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009be6f4;
    ExceptionList = in_ECX;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0065a6f0 @ 0x0065a6f0 ====

undefined4 FUN_0065a6f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x88);
}


// ==== FUN_0065a700 @ 0x0065a700 ====

undefined1 FUN_0065a700(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x60);
}


// ==== FUN_0065a710 @ 0x0065a710 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0065a710(undefined4 *param_1)

{
  char cVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c518;
  local_c = ExceptionList;
  local_10 = DAT_00b49670 ^ (uint)&local_4c;
  if (*(char *)(in_ECX + 0x28) != '\0') {
    ExceptionList = &local_c;
    *(undefined4 *)(in_ECX + 100) = *param_1;
    *(undefined4 *)(in_ECX + 0x68) = param_1[1];
    *(undefined4 *)(in_ECX + 0x6c) = param_1[2];
    *(undefined1 *)(in_ECX + 0x70) = *(undefined1 *)(param_1 + 3);
    *(undefined1 *)(in_ECX + 0x71) = *(undefined1 *)((int)param_1 + 0xd);
    *(undefined4 *)(in_ECX + 0x74) = param_1[4];
    *(undefined4 *)(in_ECX + 0x78) = param_1[5];
    *(undefined4 *)(in_ECX + 0x7c) = param_1[6];
    local_3c = param_1[7];
    *(undefined4 *)(in_ECX + 0x80) = local_3c;
    *(undefined4 *)(in_ECX + 0x84) = param_1[8];
    if (*(int *)(in_ECX + 0x88) != 0) {
      local_48 = *(int *)(in_ECX + 0x74) + *(int *)(in_ECX + 100);
      local_4a = 1;
      local_14 = 0xf;
      local_18 = 0;
      local_28 = (void *)((uint)local_28 & 0xffffff00);
      local_4 = 0;
      local_4c = *(undefined1 *)(in_ECX + 0x70);
      local_34 = *(undefined4 *)(in_ECX + 0x68);
      local_4b = *(undefined1 *)(in_ECX + 0x71);
      local_44 = *(undefined4 *)(in_ECX + 0x78);
      local_30 = *(undefined4 *)(in_ECX + 0x6c);
      local_40 = *(undefined4 *)(in_ECX + 0x7c);
      local_38 = *(undefined4 *)(in_ECX + 0x84);
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x88) + 0xc))(&local_4c);
      if (cVar1 != '\0') {
        if (local_14 < 0x10) {
          ExceptionList = local_c;
          return 1;
        }
        _free(local_28);
        return extraout_EAX_00;
      }
      if (0xf < local_14) {
        _free(local_28);
        return extraout_EAX;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0065a860 @ 0x0065a860 ====

void FUN_0065a860(byte param_1)

{
  void *in_ECX;
  
  FUN_0065a650();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065a880 @ 0x0065a880 ====

void FUN_0065a880(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c49e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d5d60;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 1;
  in_ECX[9] = param_1;
  *(undefined1 *)(in_ECX + 10) = 0;
  *(undefined1 *)((int)in_ECX + 0x29) = 0;
  FUN_0056a840();
  local_4 = CONCAT31(local_4._1_3_,2);
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  FUN_00401740(&DAT_0099cf70,0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0065a910 @ 0x0065a910 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0065a910(void)

{
  int iVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint uVar2;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint extraout_EAX_07;
  uint extraout_EAX_08;
  uint extraout_EAX_09;
  uint extraout_EAX_10;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_1b8 [4];
  undefined1 uStack_1b4;
  undefined1 uStack_1b1;
  undefined4 uStack_1ac;
  undefined4 *puStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined1 auStack_19c [4];
  undefined1 uStack_198;
  undefined4 uStack_190;
  undefined1 **ppuStack_18c;
  undefined1 *puStack_188;
  undefined4 uStack_184;
  undefined1 auStack_180 [4];
  undefined1 uStack_17c;
  undefined4 uStack_174;
  undefined4 *puStack_170;
  undefined1 *puStack_16c;
  undefined4 uStack_168;
  undefined1 auStack_164 [4];
  undefined1 uStack_160;
  undefined4 uStack_158;
  undefined4 *puStack_154;
  undefined1 *puStack_150;
  undefined4 uStack_14c;
  undefined1 auStack_148 [4];
  undefined1 uStack_144;
  undefined4 uStack_13c;
  undefined4 *puStack_138;
  undefined1 *puStack_134;
  undefined4 uStack_130;
  undefined1 auStack_12c [4];
  undefined1 uStack_128;
  undefined4 uStack_11c;
  char *pcStack_118;
  undefined4 auStack_114 [2];
  undefined1 uStack_10c;
  undefined4 uStack_100;
  undefined1 *puStack_fc;
  undefined4 uStack_f8;
  char *pcStack_f4;
  undefined1 *puStack_dc;
  undefined1 *puStack_d8;
  undefined1 *puStack_d4;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined1 local_b8 [4];
  void *local_b4;
  undefined4 local_a4;
  uint local_a0;
  void *local_98;
  undefined4 local_88;
  uint local_84;
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 local_6c;
  uint local_68;
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  void *local_28;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c4e6;
  pvStack_c = ExceptionList;
  local_10 = DAT_00b49670 ^ (uint)&uStack_c0;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  local_84 = 0xf;
  local_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  local_a0 = 0xf;
  local_a4 = 0;
  local_b4 = (void *)((uint)local_b4 & 0xffffff00);
  local_68 = 0xf;
  local_6c = 0;
  local_7c = (void *)((uint)local_7c & 0xffffff00);
  puStack_d4 = local_80;
  puStack_d8 = local_b8;
  puStack_dc = local_48;
  local_4 = 5;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5b0bc + 0xc))();
  pcStack_f4 = s_EMPTY_009d5dd4;
  uStack_f8 = local_34;
  puStack_fc = (undefined1 *)0x0;
  uStack_100 = 0x65aa03;
  iVar1 = FUN_00403620();
  if (iVar1 == 0) {
    if (0xf < local_84) {
      pcStack_f4 = (char *)0x65aa22;
      _free(local_98);
      return extraout_EAX;
    }
    local_84 = 0xf;
    local_88 = 0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    if (0xf < uStack_bc) {
      pcStack_f4 = (char *)0x65aa41;
      _free(unaff_EDI);
      return extraout_EAX_00;
    }
    uStack_bc = 0xf;
    uStack_c0 = 0;
    if (0xf < local_4c) {
      pcStack_f4 = (char *)0x65aa66;
      _free(local_60);
      return extraout_EAX_01;
    }
    local_4c = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    if (0xf < local_a0) {
      pcStack_f4 = (char *)0x65aa8e;
      _free(local_b4);
      return extraout_EAX_02;
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = (void *)((uint)local_b4 & 0xffffff00);
    if (0xf < local_68) {
      pcStack_f4 = (char *)0x65aab0;
      _free(local_7c);
      return extraout_EAX_03;
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    if (0xf < local_30) {
      pcStack_f4 = (char *)0x65aadb;
      _free(local_44);
      return extraout_EAX_04;
    }
    uVar2 = 0;
  }
  else {
    pcStack_f4 = (char *)0x65aaf1;
    (**(code **)(*DAT_00b5af80 + 4))();
    pcStack_f4 = *(char **)(in_ECX + 0x20);
    uStack_f8 = 0x65ab00;
    (**(code **)(*DAT_00b5b0b8 + 0xc))();
    auStack_114[0] = 0xe;
    uStack_f8 = 0xf;
    puStack_fc = (undefined1 *)0x0;
    pcStack_118 = s_ProcessMessage_009d5dc4;
    uStack_10c = 0;
    uStack_11c = 0x65ab1e;
    FUN_00401740();
    auStack_114[0] = 0x65ab29;
    (**(code **)(*DAT_00b5b0b8 + 0x40))();
    puStack_fc = auStack_12c;
    uStack_130 = 0xffffffff;
    puStack_134 = (undefined1 *)0x0;
    puStack_138 = &local_6c;
    auStack_114[0] = 0xf;
    pcStack_118 = (char *)0x0;
    uStack_128 = 0;
    uStack_13c = 0x65ab4b;
    FUN_00401660();
    uStack_130 = 0x65ab56;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    pcStack_118 = auStack_148;
    uStack_14c = 0xffffffff;
    puStack_150 = (undefined1 *)0x0;
    puStack_154 = &uStack_c0;
    uStack_130 = 0xf;
    puStack_134 = (undefined1 *)0x0;
    uStack_144 = 0;
    uStack_158 = 0x65ab78;
    FUN_00401660();
    uStack_14c = 0x65ab83;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    puStack_134 = auStack_164;
    uStack_168 = 0xffffffff;
    puStack_16c = (undefined1 *)0x0;
    puStack_170 = auStack_114;
    uStack_14c = 0xf;
    puStack_150 = (undefined1 *)0x0;
    uStack_160 = 0;
    uStack_174 = 0x65aba2;
    FUN_00401660();
    uStack_168 = 0x65abad;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    puStack_150 = auStack_180;
    uStack_184 = 0xffffffff;
    puStack_188 = (undefined1 *)0x0;
    ppuStack_18c = &puStack_dc;
    uStack_168 = 0xf;
    puStack_16c = (undefined1 *)0x0;
    uStack_17c = 0;
    uStack_190 = 0x65abcf;
    FUN_00401660();
    uStack_184 = 0x65abda;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    puStack_16c = auStack_19c;
    uStack_184 = 0xf;
    uStack_1a0 = 0xffffffff;
    uStack_1a4 = 0;
    puStack_1a8 = &uStack_168;
    puStack_188 = (undefined1 *)0x0;
    uStack_198 = 0;
    uStack_1ac = 0x65abf9;
    FUN_00401660();
    uStack_1a0 = 0x65ac04;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    puStack_188 = auStack_1b8;
    uStack_1a0 = 0xf;
    uStack_1a4 = 0;
    uStack_1b4 = 0;
    FUN_00401660(&uStack_14c,0,0xffffffff);
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    (**(code **)(*DAT_00b5b0b8 + 0x34))(6,1,0);
    uStack_1b1 = (**(code **)(*DAT_00b5b0b8 + 0x4c))();
    (**(code **)(*DAT_00b5b0b8 + 0x10))();
    if (0xf < local_84) {
      pcStack_f4 = (char *)0x65ac6f;
      _free(local_98);
      return extraout_EAX_05;
    }
    local_84 = 0xf;
    local_88 = 0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    if (0xf < uStack_bc) {
      pcStack_f4 = (char *)0x65ac8e;
      _free(unaff_EDI);
      return extraout_EAX_06;
    }
    uStack_bc = 0xf;
    uStack_c0 = 0;
    if (0xf < local_4c) {
      pcStack_f4 = (char *)0x65acb3;
      _free(local_60);
      return extraout_EAX_07;
    }
    local_4c = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    if (0xf < local_a0) {
      pcStack_f4 = (char *)0x65acdb;
      _free(local_b4);
      return extraout_EAX_08;
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = (void *)((uint)local_b4 & 0xffffff00);
    if (0xf < local_68) {
      pcStack_f4 = (char *)0x65acfd;
      _free(local_7c);
      return extraout_EAX_09;
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    if (0xf < local_30) {
      pcStack_f4 = (char *)0x65ad28;
      _free(local_44);
      return extraout_EAX_10;
    }
    uVar2 = (uint)puStack_dc >> 0x18;
  }
  ExceptionList = local_28;
  return uVar2;
}


// ==== FUN_0065ad60 @ 0x0065ad60 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0065ad60(void)

{
  int iVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint uVar2;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint extraout_EAX_07;
  uint extraout_EAX_08;
  uint extraout_EAX_09;
  uint extraout_EAX_10;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_1b8 [4];
  undefined1 uStack_1b4;
  undefined1 uStack_1b1;
  undefined4 uStack_1ac;
  undefined4 *puStack_1a8;
  undefined4 uStack_1a4;
  undefined4 uStack_1a0;
  undefined1 auStack_19c [4];
  undefined1 uStack_198;
  undefined4 uStack_190;
  undefined1 **ppuStack_18c;
  undefined1 *puStack_188;
  undefined4 uStack_184;
  undefined1 auStack_180 [4];
  undefined1 uStack_17c;
  undefined4 uStack_174;
  undefined4 *puStack_170;
  undefined1 *puStack_16c;
  undefined4 uStack_168;
  undefined1 auStack_164 [4];
  undefined1 uStack_160;
  undefined4 uStack_158;
  undefined4 *puStack_154;
  undefined1 *puStack_150;
  undefined4 uStack_14c;
  undefined1 auStack_148 [4];
  undefined1 uStack_144;
  undefined4 uStack_13c;
  undefined4 *puStack_138;
  undefined1 *puStack_134;
  undefined4 uStack_130;
  undefined1 auStack_12c [4];
  undefined1 uStack_128;
  undefined4 uStack_11c;
  char *pcStack_118;
  undefined4 auStack_114 [2];
  undefined1 uStack_10c;
  undefined4 uStack_100;
  undefined1 *puStack_fc;
  undefined4 uStack_f8;
  char *pcStack_f4;
  undefined1 *puStack_dc;
  undefined1 *puStack_d8;
  undefined1 *puStack_d4;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined1 local_b8 [4];
  void *local_b4;
  undefined4 local_a4;
  uint local_a0;
  void *local_98;
  undefined4 local_88;
  uint local_84;
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 local_6c;
  uint local_68;
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  void *local_28;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098c4e6;
  pvStack_c = ExceptionList;
  local_10 = DAT_00b49670 ^ (uint)&uStack_c0;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  local_84 = 0xf;
  local_88 = 0;
  local_98 = (void *)((uint)local_98 & 0xffffff00);
  local_30 = 0xf;
  local_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  local_a0 = 0xf;
  local_a4 = 0;
  local_b4 = (void *)((uint)local_b4 & 0xffffff00);
  local_68 = 0xf;
  local_6c = 0;
  local_7c = (void *)((uint)local_7c & 0xffffff00);
  puStack_d4 = local_80;
  puStack_d8 = local_b8;
  puStack_dc = local_48;
  local_4 = 5;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5b0bc + 0x10))();
  pcStack_f4 = s_EMPTY_009d5dd4;
  uStack_f8 = local_34;
  puStack_fc = (undefined1 *)0x0;
  uStack_100 = 0x65ae53;
  iVar1 = FUN_00403620();
  if (iVar1 == 0) {
    if (0xf < local_84) {
      pcStack_f4 = (char *)0x65ae72;
      _free(local_98);
      return extraout_EAX;
    }
    local_84 = 0xf;
    local_88 = 0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    if (0xf < uStack_bc) {
      pcStack_f4 = (char *)0x65ae91;
      _free(unaff_EDI);
      return extraout_EAX_00;
    }
    uStack_bc = 0xf;
    uStack_c0 = 0;
    if (0xf < local_4c) {
      pcStack_f4 = (char *)0x65aeb6;
      _free(local_60);
      return extraout_EAX_01;
    }
    local_4c = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    if (0xf < local_a0) {
      pcStack_f4 = (char *)0x65aede;
      _free(local_b4);
      return extraout_EAX_02;
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = (void *)((uint)local_b4 & 0xffffff00);
    if (0xf < local_68) {
      pcStack_f4 = (char *)0x65af00;
      _free(local_7c);
      return extraout_EAX_03;
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    if (0xf < local_30) {
      pcStack_f4 = (char *)0x65af2b;
      _free(local_44);
      return extraout_EAX_04;
    }
    uVar2 = 0;
  }
  else {
    pcStack_f4 = (char *)0x65af41;
    (**(code **)(*DAT_00b5af80 + 4))();
    pcStack_f4 = *(char **)(in_ECX + 0x20);
    uStack_f8 = 0x65af50;
    (**(code **)(*DAT_00b5b0b8 + 0xc))();
    auStack_114[0] = 0xe;
    uStack_f8 = 0xf;
    puStack_fc = (undefined1 *)0x0;
    pcStack_118 = s_ProcessMessage_009d5dc4;
    uStack_10c = 0;
    uStack_11c = 0x65af6e;
    FUN_00401740();
    auStack_114[0] = 0x65af79;
    (**(code **)(*DAT_00b5b0b8 + 0x40))();
    puStack_fc = auStack_12c;
    uStack_130 = 0xffffffff;
    puStack_134 = (undefined1 *)0x0;
    puStack_138 = &local_6c;
    auStack_114[0] = 0xf;
    pcStack_118 = (char *)0x0;
    uStack_128 = 0;
    uStack_13c = 0x65af9b;
    FUN_00401660();
    uStack_130 = 0x65afa6;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    pcStack_118 = auStack_148;
    uStack_14c = 0xffffffff;
    puStack_150 = (undefined1 *)0x0;
    puStack_154 = &uStack_c0;
    uStack_130 = 0xf;
    puStack_134 = (undefined1 *)0x0;
    uStack_144 = 0;
    uStack_158 = 0x65afc8;
    FUN_00401660();
    uStack_14c = 0x65afd3;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    puStack_134 = auStack_164;
    uStack_168 = 0xffffffff;
    puStack_16c = (undefined1 *)0x0;
    puStack_170 = auStack_114;
    uStack_14c = 0xf;
    puStack_150 = (undefined1 *)0x0;
    uStack_160 = 0;
    uStack_174 = 0x65aff2;
    FUN_00401660();
    uStack_168 = 0x65affd;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    puStack_150 = auStack_180;
    uStack_184 = 0xffffffff;
    puStack_188 = (undefined1 *)0x0;
    ppuStack_18c = &puStack_dc;
    uStack_168 = 0xf;
    puStack_16c = (undefined1 *)0x0;
    uStack_17c = 0;
    uStack_190 = 0x65b01f;
    FUN_00401660();
    uStack_184 = 0x65b02a;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    puStack_16c = auStack_19c;
    uStack_184 = 0xf;
    uStack_1a0 = 0xffffffff;
    uStack_1a4 = 0;
    puStack_1a8 = &uStack_168;
    puStack_188 = (undefined1 *)0x0;
    uStack_198 = 0;
    uStack_1ac = 0x65b049;
    FUN_00401660();
    uStack_1a0 = 0x65b054;
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    puStack_188 = auStack_1b8;
    uStack_1a0 = 0xf;
    uStack_1a4 = 0;
    uStack_1b4 = 0;
    FUN_00401660(&uStack_14c,0,0xffffffff);
    (**(code **)(*DAT_00b5b0b8 + 0x54))();
    (**(code **)(*DAT_00b5b0b8 + 0x34))(6,1,0);
    uStack_1b1 = (**(code **)(*DAT_00b5b0b8 + 0x4c))();
    (**(code **)(*DAT_00b5b0b8 + 0x10))();
    if (0xf < local_84) {
      pcStack_f4 = (char *)0x65b0bf;
      _free(local_98);
      return extraout_EAX_05;
    }
    local_84 = 0xf;
    local_88 = 0;
    local_98 = (void *)((uint)local_98 & 0xffffff00);
    if (0xf < uStack_bc) {
      pcStack_f4 = (char *)0x65b0de;
      _free(unaff_EDI);
      return extraout_EAX_06;
    }
    uStack_bc = 0xf;
    uStack_c0 = 0;
    if (0xf < local_4c) {
      pcStack_f4 = (char *)0x65b103;
      _free(local_60);
      return extraout_EAX_07;
    }
    local_4c = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    if (0xf < local_a0) {
      pcStack_f4 = (char *)0x65b12b;
      _free(local_b4);
      return extraout_EAX_08;
    }
    local_a0 = 0xf;
    local_a4 = 0;
    local_b4 = (void *)((uint)local_b4 & 0xffffff00);
    if (0xf < local_68) {
      pcStack_f4 = (char *)0x65b14d;
      _free(local_7c);
      return extraout_EAX_09;
    }
    local_68 = 0xf;
    local_6c = 0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    if (0xf < local_30) {
      pcStack_f4 = (char *)0x65b178;
      _free(local_44);
      return extraout_EAX_10;
    }
    uVar2 = (uint)puStack_dc >> 0x18;
  }
  ExceptionList = local_28;
  return uVar2;
}


// ==== FUN_0065b1b0 @ 0x0065b1b0 ====

undefined4 FUN_0065b1b0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  cVar1 = FUN_0065a910(param_1);
  if (cVar1 != '\x01') {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar2 == 0x10001) {
      if (param_1[2] == 1) {
        uVar3 = (**(code **)(*param_1 + 0x10))();
        FUN_0065a5e0(param_1 + 7,uVar3);
      }
    }
    else if ((iVar2 == 0x10003) && (cVar1 = FUN_0065a3f0(param_1), cVar1 != '\0')) {
      return 1;
    }
    cVar1 = (**(code **)(*(int *)in_ECX[0x22] + 0x1c))(param_1);
    if (cVar1 != '\x01') {
      cVar1 = (**(code **)(*in_ECX + 0x50))();
      if (cVar1 != '\0') {
        iVar2 = (**(code **)(*param_1 + 4))();
        if (iVar2 == 0x10001) {
          return 1;
        }
        if (iVar2 == 0x10003) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0065b240 @ 0x0065b240 ====

char FUN_0065b240(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = FUN_0065ad60(param_1);
  return '\x01' - (cVar1 != '\x01');
}


// ==== FUN_0065b260 @ 0x0065b260 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_0065b260(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  uint extraout_EAX;
  uint extraout_EAX_00;
  int in_ECX;
  undefined1 auStack_e4 [4];
  undefined1 uStack_e0;
  void *pvStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  uint uStack_c8;
  undefined1 uStack_c4;
  void *pvStack_c0;
  undefined4 uStack_bc;
  undefined4 *puStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  uint uStack_ac;
  undefined1 uStack_a8;
  void *pvStack_a4;
  undefined1 *puStack_9c;
  char *pcStack_98;
  undefined4 uStack_94;
  undefined1 auStack_90 [4];
  undefined1 uStack_8c;
  undefined1 *puStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 *puStack_6c;
  undefined4 uStack_68;
  undefined1 *puStack_64;
  undefined4 uStack_60;
  undefined1 auStack_50 [36];
  undefined1 local_2c [24];
  undefined1 uStack_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098c500;
  pvStack_c = ExceptionList;
  local_10 = DAT_00b49670 ^ (uint)auStack_50;
  uStack_60 = param_1;
  puStack_64 = local_2c;
  uStack_68 = 0x65b2a1;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5b0bc + 4))();
  uStack_68 = param_1;
  puStack_6c = auStack_50;
  pvStack_c = (void *)0x0;
  uStack_70 = 0x65b2bc;
  (**(code **)(*DAT_00b5b0bc + 8))();
  uStack_14 = 1;
  uStack_74 = 0x65b2cd;
  (**(code **)(*DAT_00b5af80 + 4))();
  uStack_74 = *(undefined4 *)(in_ECX + 0x20);
  uStack_78 = 0x65b2dc;
  (**(code **)(*DAT_00b5b0b8 + 0xc))();
  puStack_64 = auStack_90;
  uStack_94 = 0xc;
  uStack_78 = 0xf;
  uStack_7c = 0;
  pcStack_98 = s_ProcessEvent_009d5ddc;
  uStack_8c = 0;
  puStack_9c = (undefined1 *)0x65b2ff;
  FUN_00401740();
  uStack_94 = 0x65b30a;
  (**(code **)(*DAT_00b5b0b8 + 0x40))();
  puStack_80 = (undefined1 *)&uStack_ac;
  uStack_b0 = 0xffffffff;
  uStack_b4 = 0;
  puStack_b8 = &uStack_60;
  uStack_94 = 0xf;
  pcStack_98 = (char *)0x0;
  uStack_a8 = 0;
  uStack_bc = 0x65b329;
  FUN_00401660();
  uStack_b0 = 0x65b334;
  (**(code **)(*DAT_00b5b0b8 + 0x54))();
  puStack_9c = (undefined1 *)&uStack_c8;
  uStack_cc = 0xffffffff;
  uStack_d0 = 0;
  uStack_b0 = 0xf;
  uStack_b4 = 0;
  uStack_d4 = param_2;
  uStack_c4 = 0;
  uStack_d8 = 0x65b34f;
  FUN_00401660();
  uStack_cc = 0x65b35a;
  (**(code **)(*DAT_00b5b0b8 + 0x54))();
  puStack_b8 = (undefined4 *)auStack_e4;
  uStack_cc = 0xf;
  uStack_d0 = 0;
  uStack_e0 = 0;
  FUN_00401660(&uStack_b4,0,0xffffffff);
  (**(code **)(*DAT_00b5b0b8 + 0x54))();
  (**(code **)(*DAT_00b5b0b8 + 0x50))();
  (**(code **)(*DAT_00b5b0b8 + 0x34))(4,1,0);
  bVar1 = (**(code **)(*DAT_00b5b0b8 + 0x4c))();
  (**(code **)(*DAT_00b5b0b8 + 0x10))();
  if (0xf < uStack_c8) {
    _free(pvStack_dc);
    return extraout_EAX;
  }
  uStack_c8 = 0xf;
  uStack_cc = 0;
  pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
  if (uStack_ac < 0x10) {
    ExceptionList = pvStack_a4;
    return (uint)bVar1;
  }
  _free(pvStack_c0);
  return extraout_EAX_00;
}


// ==== FUN_0065b420 @ 0x0065b420 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0065b420(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int *in_ECX;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0098c518;
  local_c = ExceptionList;
  local_10 = DAT_00b49670 ^ (uint)&uStack_4c;
  if ((char)in_ECX[10] == '\0') {
    ExceptionList = &local_c;
    FUN_005896d0(param_1);
    piVar2 = (int *)(**(code **)(*DAT_00b5a7ac + 4))();
    uStack_4a = 1;
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    uStack_48 = *(undefined4 *)(param_1 + 0x40);
    uStack_4c = *(undefined1 *)(param_1 + 0x3c);
    uStack_4b = *(undefined1 *)(param_1 + 0x3d);
    uStack_44 = *(undefined4 *)(param_1 + 0x44);
    uStack_34 = *(undefined4 *)(param_1 + 0x34);
    uStack_30 = *(undefined4 *)(param_1 + 0x38);
    uStack_38 = *(undefined4 *)(param_1 + 0x50);
    uStack_40 = *(undefined4 *)(param_1 + 0x48);
    uStack_3c = *(undefined4 *)(param_1 + 0x4c);
    uStack_4 = 0;
    cVar1 = (**(code **)(*piVar2 + 8))(&uStack_4c);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5a7ac + 0xc))(piVar2);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return extraout_EAX;
      }
    }
    else {
      cVar1 = (**(code **)(*DAT_00b5a7a0 + 4))();
      if (cVar1 != '\0') {
        in_ECX[0x22] = (int)piVar2;
        (**(code **)(*piVar2 + 0x34))();
        *(undefined1 *)(in_ECX + 10) = 1;
        (**(code **)(*in_ECX + 0x18))(in_ECX + 0x19);
        (**(code **)(*DAT_00b5a7a0 + 0x10))(in_ECX + 9);
        if (uStack_14 < 0x10) {
          ExceptionList = local_c;
          return 1;
        }
        _free(pvStack_28);
        return extraout_EAX_01;
      }
      (**(code **)(*DAT_00b5a7ac + 0xc))(piVar2);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return extraout_EAX_00;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0065b5a0 @ 0x0065b5a0 ====

undefined4 FUN_0065b5a0(void)

{
  return 0x30030118;
}


// ==== FUN_0065b5b0 @ 0x0065b5b0 ====

void FUN_0065b5b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6470;
  *(undefined1 *)(in_ECX + 2) = 0xff;
  *(undefined1 *)((int)in_ECX + 9) = 0xff;
  in_ECX[1] = 0;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  return;
}


// ==== FUN_0065b5e0 @ 0x0065b5e0 ====

undefined4 FUN_0065b5e0(void)

{
  return 0x50000000;
}


// ==== FUN_0065b5f0 @ 0x0065b5f0 ====

void FUN_0065b5f0(byte param_1)

{
  FUN_0065b620();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_0065b620 @ 0x0065b620 ====

void FUN_0065b620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6470;
  if (0xf < (uint)in_ECX[0x10]) {
    _free((void *)in_ECX[0xb]);
    return;
  }
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[8] = 0;
    in_ECX[9] = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0065b680 @ 0x0065b680 ====

void FUN_0065b680(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined1 *)(in_ECX + 8) = *(undefined1 *)(param_1 + 1);
  *(undefined1 *)(in_ECX + 9) = *(undefined1 *)((int)param_1 + 5);
  FUN_00401660(param_1 + 2,0,0xffffffff);
  FUN_00401660(param_1 + 9,0,0xffffffff);
  return;
}


// ==== FUN_0065b6c0 @ 0x0065b6c0 ====

void FUN_0065b6c0(void)

{
  void *pvVar1;
  
  if (DAT_00b5a750 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00664a10();
    }
  }
  if (DAT_00b5a74c == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_00664620();
    }
  }
  if (DAT_00b5a748 == 0) {
    pvVar1 = operator_new(0x468);
    if (pvVar1 != (void *)0x0) {
      FUN_0065f450();
      return;
    }
  }
  return;
}


// ==== FUN_0065b720 @ 0x0065b720 ====

void FUN_0065b720(void)

{
  if (DAT_00b5a74c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a74c)(1);
  }
  if (DAT_00b5a748 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a748)(1);
  }
  if (DAT_00b5a750 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a750)(1);
  }
  return;
}


// ==== FUN_0065b760 @ 0x0065b760 ====

void FUN_0065b760(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5ec0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065b780 @ 0x0065b780 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065b780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5ec8;
  FUN_00665e40();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b0c4 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b0c4 = in_ECX;
  return;
}


// ==== FUN_0065b7b0 @ 0x0065b7b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065b7b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5ec8;
  _DAT_00b5b0c4 = 0;
  FUN_00665e60();
  *in_ECX = &PTR_FUN_009d5ec0;
  return;
}


// ==== FUN_0065b7d0 @ 0x0065b7d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065b7d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5ec8;
  _DAT_00b5b0c4 = 0;
  FUN_00665e60();
  *in_ECX = &PTR_FUN_009d5ec0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065b810 @ 0x0065b810 ====

undefined1 FUN_0065b810(void)

{
  return 0;
}


// ==== FUN_0065b820 @ 0x0065b820 ====

void FUN_0065b820(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0065b82c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0065b830 @ 0x0065b830 ====

undefined1 FUN_0065b830(void)

{
  return 0;
}


// ==== FUN_0065b840 @ 0x0065b840 ====

void FUN_0065b840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5f3c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0065b860 @ 0x0065b860 ====

void FUN_0065b860(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_loginmessage_txt_009d5f08,0x1c);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  return;
}


// ==== FUN_0065b8f0 @ 0x0065b8f0 ====

void FUN_0065b8f0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_message_009d5f28,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    puVar2 = operator_new(8);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b1798;
    }
    uVar3 = (**(code **)(*piVar1 + 4))();
    puVar2[1] = uVar3;
    FUN_00797a20(puVar2);
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(unaff_retaddr);
  }
  return;
}


// ==== FUN_0065b9a0 @ 0x0065b9a0 ====

void FUN_0065b9a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d5f3c;
  FUN_0065b860();
  return;
}


// ==== FUN_0065b9c0 @ 0x0065b9c0 ====

undefined4 FUN_0065b9c0(void)

{
  return 0x16;
}


// ==== FUN_0065b9d0 @ 0x0065b9d0 ====

void FUN_0065b9d0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d5f3c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065ba10 @ 0x0065ba10 ====

undefined1 FUN_0065ba10(void)

{
  return 0;
}


// ==== FUN_0065ba20 @ 0x0065ba20 ====

undefined1 FUN_0065ba20(void)

{
  return 0;
}


// ==== FUN_0065ba30 @ 0x0065ba30 ====

void FUN_0065ba30(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0065ba40 @ 0x0065ba40 ====

void FUN_0065ba40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6010;
  (**(code **)(*DAT_00b5a750 + 0xc))(0x1f);
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0065ba70 @ 0x0065ba70 ====

void FUN_0065ba70(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_loadwnd_txt_009d5fa8,0x17);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  (**(code **)(*DAT_00b5a750 + 8))(0x1f);
  return;
}


// ==== FUN_0065bb00 @ 0x0065bb00 ====

void FUN_0065bb00(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_26 [10];
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_map_009d5fc0,7);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00587d40(auStack_26 + -6);
      iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x1f);
      if (iVar2 == 0) {
        (**(code **)(*DAT_00b5a750 + 8))(0x1f);
      }
      FUN_006662a0(unaff_retaddr);
      *(undefined1 *)(in_ECX + 0xc) = 1;
    }
  }
  return;
}


// ==== FUN_0065bbd0 @ 0x0065bbd0 ====

void FUN_0065bbd0(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_retaddr;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_barend_009d5ff8,10);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(unaff_retaddr);
  }
  return;
}


// ==== FUN_0065bc50 @ 0x0065bc50 ====

void FUN_0065bc50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d6010;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[1] = 0;
  FUN_0065ba70();
  return;
}


// ==== FUN_0065bc70 @ 0x0065bc70 ====

void FUN_0065bc70(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  (**(code **)(*piVar1 + 0x24))(param_1);
  if (((char)param_1 != '\0') || (*(char *)(in_ECX + 0xc) != '\x01')) {
    return;
  }
  FUN_0065bbd0(0);
  piVar1 = (int *)(**(code **)(*DAT_00b5a74c + 0xc))(0x1f);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a750 + 8))(0x1f);
  }
                    /* WARNING: Could not recover jumptable at 0x0065bcc7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0xc))(1);
  return;
}


// ==== FUN_0065bcd0 @ 0x0065bcd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065bcd0(void)

{
  code *pcVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int unaff_retaddr;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  fVar2 = (float)*(int *)(in_ECX + 8);
  if (*(int *)(in_ECX + 8) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  if (_DAT_009d6004 <= fVar2) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = 0;
    FUN_00401740(s_pro_loading_009d5fc8,0xb);
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
    if (0xf < local_24) {
      _free(local_38);
      return;
    }
    local_24 = 0xf;
    uStack_28 = 0;
    local_38 = (void *)((uint)local_38 & 0xffffff00);
    if (piVar4 == (int *)0x0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pComposite____NULL_009d5fd4,0x12);
      FUN_00406880(&local_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    iVar5 = (**(code **)(*piVar4 + 0x30))();
    if (iVar5 == 0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pBar____NULL_009d5fe8,0xc);
      FUN_00406880(&local_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    fVar2 = (float)unaff_retaddr;
    if (unaff_retaddr < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar3 = (float)*(int *)(in_ECX + 8);
    if (*(int *)(in_ECX + 8) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    FUN_00587ba0((fVar2 / fVar3) * DAT_0099de78);
    if (unaff_retaddr == *(int *)(in_ECX + 8)) {
      FUN_0065bbd0(1);
    }
  }
  return;
}


// ==== FUN_0065be30 @ 0x0065be30 ====

undefined4 FUN_0065be30(void)

{
  return 0x18;
}


// ==== FUN_0065be40 @ 0x0065be40 ====

void FUN_0065be40(void)

{
  undefined4 *in_ECX;
  uint unaff_ESI;
  
  *in_ECX = &PTR_FUN_009d6010;
  (**(code **)(*DAT_00b5a750 + 0xc))(0x1f);
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_ESI & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065be90 @ 0x0065be90 ====

void FUN_0065be90(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0065be9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0065bea0 @ 0x0065bea0 ====

undefined1 FUN_0065bea0(void)

{
  return 0;
}


// ==== FUN_0065beb0 @ 0x0065beb0 ====

undefined1 FUN_0065beb0(void)

{
  return 0;
}


// ==== FUN_0065bec0 @ 0x0065bec0 ====

void FUN_0065bec0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0065bee0 @ 0x0065bee0 ====

void FUN_0065bee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d60e8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0065bf00 @ 0x0065bf00 ====

void FUN_0065bf00(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_preloadwnd_txt_009d607c,0x1a);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(int **)(in_ECX + 4) = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  return;
}


// ==== FUN_0065bf90 @ 0x0065bf90 ====

/* WARNING: Removing unreachable block (ram,0x0065c03d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065bf90(void)

{
  code *pcVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_3c;
  void *local_38 [5];
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  fVar2 = (float)*(int *)(in_ECX + 8);
  if (*(int *)(in_ECX + 8) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  if (_DAT_009d60dc <= fVar2) {
    FUN_00401740(s_LOADING_____2_1f____009d6098,0x13);
    FUN_00404230(local_38);
    local_3c = 0xf;
    FUN_00401740(s_lbl_count_009d60ac,9);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    if (piVar3 == (int *)0x0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pComposite____NULL_009d60b8,0x12);
      FUN_00406880(auStack_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    iVar4 = (**(code **)(*piVar3 + 0x30))();
    if (iVar4 == 0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pLabel____NULL_009d60cc,0xe);
      FUN_00406880(auStack_20);
      if (uStack_8 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_1c);
      return;
    }
    FUN_0055a260(&local_3c);
    if (0xf < uStack_24) {
      _free(local_38[0]);
      return;
    }
  }
  return;
}


// ==== FUN_0065c120 @ 0x0065c120 ====

void FUN_0065c120(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d60e8;
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  FUN_0065bf00();
  return;
}


// ==== FUN_0065c140 @ 0x0065c140 ====

undefined4 FUN_0065c140(void)

{
  return 0x19;
}


// ==== FUN_0065c150 @ 0x0065c150 ====

void FUN_0065c150(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d60e8;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065c190 @ 0x0065c190 ====

bool FUN_0065c190(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  return param_1 == iVar1;
}


// ==== FUN_0065c1a0 @ 0x0065c1a0 ====

void FUN_0065c1a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d643c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0065c200 @ 0x0065c200 ====

void FUN_0065c200(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(param_1);
  }
  return;
}


// ==== FUN_0065c260 @ 0x0065c260 ====

uint FUN_0065c260(void)

{
  byte bVar1;
  code *pcVar2;
  int *piVar3;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint uVar4;
  undefined4 uVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 ****ppppuVar8;
  int iVar9;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  int in_ECX;
  uint uVar10;
  undefined1 auStack_3c [4];
  undefined4 ****local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_list_serverlist_009d6330,0xf);
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return extraout_EAX;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  uVar4 = (uint)local_38 >> 8;
  local_38 = (undefined4 ****)(uVar4 << 8);
  if (piVar3 == (int *)0x0) {
    local_24 = 0xf;
    uStack_28 = 0;
    local_38 = (undefined4 ****)(uVar4 << 8);
    FUN_00401740(s_FALSE_009d6340,5);
    FUN_00406880(auStack_3c);
    if (local_24 < 0x10) {
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    _free(local_38);
    return extraout_EAX_00;
  }
  (**(code **)(*piVar3 + 0x30))();
  uVar5 = FUN_00575790();
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  FUN_00401660(uVar5,0,0xffffffff);
  uVar4 = (**(code **)(*DAT_00b5ac80 + 0x18))();
  uVar10 = 0;
  if (uVar4 != 0) {
    do {
      pbVar6 = (byte *)(**(code **)(*DAT_00b5ac80 + 8))(uVar10);
      if (pbVar6 != (byte *)0x0) {
        local_24 = 0xf;
        uStack_28 = 0;
        local_38 = (undefined4 ****)((uint)local_38 & 0xffffff00);
        pbVar7 = pbVar6 + 1;
        do {
          bVar1 = *pbVar7;
          pbVar7 = pbVar7 + 1;
        } while (bVar1 != 0);
        FUN_00401740(pbVar6 + 1,(int)pbVar7 - (int)(pbVar6 + 2));
        ppppuVar8 = local_38;
        if (local_24 < 0x10) {
          ppppuVar8 = &local_38;
        }
        iVar9 = FUN_00403620(0,uStack_c,ppppuVar8,uStack_28);
        if (iVar9 == 0) {
          if (0xf < local_24) {
            _free(local_38);
            return extraout_EAX_03;
          }
          local_24 = 0xf;
          uStack_28 = 0;
          local_38 = (undefined4 ****)((uint)local_38._1_3_ << 8);
          if (uStack_8 < 0x10) {
            return (uint)*pbVar6;
          }
          _free(pvStack_1c);
          return extraout_EAX_04;
        }
        if (0xf < local_24) {
          _free(local_38);
          return extraout_EAX_01;
        }
        local_24 = 0xf;
        uStack_28 = 0;
        local_38 = (undefined4 ****)((uint)local_38._1_3_ << 8);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar4);
  }
  if (uStack_8 < 0x10) {
    return 0xff;
  }
  _free(pvStack_1c);
  return extraout_EAX_02;
}


// ==== FUN_0065c460 @ 0x0065c460 ====

/* WARNING: Removing unreachable block (ram,0x0065c4ad) */

void FUN_0065c460(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s_pLabelComp____NULL_009d6390,0x12);
    FUN_00406880(auStack_1a + -6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  (**(code **)(*piVar2 + 0x30))();
  FUN_0055a260(param_1);
  return;
}


// ==== FUN_0065c4e0 @ 0x0065c4e0 ====

void FUN_0065c4e0(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x14) = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_pan_message_009d63bc,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(unaff_ESI);
  }
  if (local_8 < 0x10) {
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0065c550 @ 0x0065c550 ====

void FUN_0065c550(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puVar5;
  void *local_38;
  undefined1 local_34;
  undefined4 uStack_28;
  uint local_24;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_edt_account_009d63c8,0xb);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_38);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  uStack_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  cVar1 = (**(code **)(*piVar2 + 100))();
  if (cVar1 != '\0') {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_edt_password_009d63d4,0xc);
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_20);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  }
  puVar3 = operator_new(8);
  puVar5 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = &PTR_FUN_009b1798;
    puVar5 = puVar3;
  }
  uVar4 = (**(code **)(*piVar2 + 4))();
  puVar5[1] = uVar4;
  FUN_00797a20(puVar5);
  return;
}


// ==== FUN_0065c640 @ 0x0065c640 ====

void FUN_0065c640(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *unaff_EBX;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_edt_account_009d63e4,0xb);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_005514b0();
      local_8 = 0xf;
      uStack_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
      FUN_00401740(s_edt_password_009d63f0,0xc);
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
      if (0xf < uStack_c) {
        _free(unaff_EBX);
        return;
      }
      uStack_c = 0xf;
      uStack_10 = 0;
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0x30))();
        if (iVar2 != 0) {
          FUN_005514b0();
        }
      }
    }
  }
  return;
}


// ==== FUN_0065c720 @ 0x0065c720 ====

/* WARNING: Removing unreachable block (ram,0x0065c7b0) */

void FUN_0065c720(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  int in_ECX;
  char *pcVar5;
  undefined1 auStack_36 [18];
  undefined4 uStack_24;
  void *pvStack_20;
  undefined1 uStack_1c;
  uint uStack_c;
  undefined4 uStack_8;
  
  iVar2 = (**(code **)(*DAT_00b5ac80 + 8))(*(undefined1 *)(in_ECX + 0xc));
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = 0;
  if (iVar2 == 0) {
    iVar2 = 5;
    pcVar5 = s_EMPTY_009d6400;
  }
  else {
    pcVar5 = (char *)(iVar2 + 1);
    pcVar3 = pcVar5;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    iVar2 = (int)pcVar3 - (iVar2 + 2);
  }
  FUN_00401740(pcVar5,iVar2);
  uStack_24 = 0xf;
  FUN_00401740(s_pan_pantheon_009d6408,0xc);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(auStack_36 + -6);
  if (piVar4 == (int *)0x0) {
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  else {
    (**(code **)(*piVar4 + 0x30))();
    FUN_0055a260(&uStack_24);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
  }
  return;
}


// ==== FUN_0065c850 @ 0x0065c850 ====

void FUN_0065c850(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  cVar1 = (**(code **)(*DAT_00b5a6d4 + 0xc))();
  if (cVar1 != '\0') {
    PostQuitMessage(0);
    return;
  }
  FUN_0065c640();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_pan_login_009d62b8,9);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_1c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(1);
  }
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  *(undefined1 *)(in_ECX + 0x1c) = 1;
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = (void *)((uint)uStack_1c & 0xffffff00);
  FUN_00401740(s_pan_selectgroup_009d62c4,0xf);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x20);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(0);
  }
  if (uStack_c < 0x10) {
    iVar3 = (**(code **)(*DAT_00b5ac1c + 8))();
    *(undefined1 *)(in_ECX + 0xc) = *(undefined1 *)(iVar3 + 4);
    FUN_0065c720();
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
    (**(code **)(*piVar2 + 0x24))(1);
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_0065c950 @ 0x0065c950 ====

void FUN_0065c950(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  if ((char)param_1 == '\0') {
    FUN_0065c640();
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  (**(code **)(*piVar1 + 0x24))(param_1);
  return;
}


// ==== FUN_0065c980 @ 0x0065c980 ====

/* WARNING: Removing unreachable block (ram,0x0065caa8) */

void FUN_0065c980(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 *puVar4;
  void **ppvStack_74;
  undefined1 auStack_5e [2];
  undefined4 uStack_5c;
  void *local_58;
  uint local_54 [2];
  int iStack_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  ppvStack_74 = (void **)0xb;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 1;
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = local_54[0] & 0xffffff00;
  FUN_00401740(s_pan_message_009d63a4);
  ppvStack_74 = &local_58;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))();
  if (0xf < local_44) {
    _free(local_58);
    return;
  }
  local_44 = 0xf;
  uStack_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    iVar2 = CONCAT31((int3)((uint)piVar1 >> 8),*(undefined1 *)(in_ECX + 0x14));
    (**(code **)(*piVar1 + 0x24))(iVar2);
    local_44._0_3_ = CONCAT12(1,(undefined2)local_44);
    local_40 = 0;
    uStack_3c = 0;
    pvStack_38 = (void *)0x0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_c = 0xf;
    uStack_10 = 0;
    uStack_20 = 0;
    uVar3 = (**(code **)(*piVar1 + 0x10))();
    FUN_004fed70(uVar3);
    puVar4 = auStack_5e + -10;
    (**(code **)(*DAT_00b5a688 + 0x34))(2,uStack_4,puVar4,auStack_5e + -6);
    iStack_4c = -(iVar2 + 0x28U >> 1);
    local_44 = iStack_4c + iVar2 + 0x28U;
    (**(code **)(*piVar1 + 0xc))(local_54);
    uStack_5c = 0xf;
    FUN_00401740(s_lbl_message_009d63b0,0xb);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&ppvStack_74);
    ppvStack_74 = (void **)((uint)ppvStack_74 & 0xffffff00);
    if (piVar1 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar1 + 0x10))();
      FUN_004fed70(uVar3);
      local_54[0] = -((uint)(puVar4 + 10) >> 1);
      iStack_4c = local_54[0] + (int)(puVar4 + 10);
      (**(code **)(*piVar1 + 0xc))(&uStack_5c);
      (**(code **)(*piVar1 + 0x30))();
      FUN_0055a260(uStack_1c);
    }
    if (0xf < uStack_24) {
      _free(pvStack_38);
      return;
    }
  }
  return;
}


// ==== FUN_0065cb30 @ 0x0065cb30 ====

undefined4 FUN_0065cb30(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 uVar4;
  undefined4 extraout_EAX_01;
  int in_ECX;
  void *pvStack_54;
  undefined1 uStack_50;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  uint uStack_24;
  undefined4 uStack_18;
  uint uStack_14;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    if (*(char *)(in_ECX + 0x14) != '\0') {
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + param_1[1];
      if (3000 < *(uint *)(in_ECX + 0x18)) {
        FUN_0065c4e0();
      }
    }
  }
  else if (iVar2 == 0x70030002) {
    uStack_3c = 0xf;
    uStack_40 = 0;
    uStack_50 = 0;
    FUN_00401740(s_pan_15_009d629c,6);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_54);
    if (0xf < uStack_40) {
      _free(pvStack_54);
      return extraout_EAX;
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    if (piVar3 == (int *)0x0) {
      FUN_00401830(s_pComposite____NULL_009d62a4);
      FUN_00406880(&uStack_3c);
      if (uStack_24 < 0x10) {
        uStack_24 = 0xf;
        pvStack_28 = (void *)0x0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      _free(pvStack_38);
      return extraout_EAX_00;
    }
    (**(code **)(*piVar3 + 0x24))(0);
    uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x640007);
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    FUN_00401660(uVar4,0,0xffffffff);
    FUN_0065c980(auStack_2c);
    if (uStack_14 < 0x10) {
      return 1;
    }
    _free(pvStack_28);
    return extraout_EAX_01;
  }
  return 0;
}


// ==== FUN_0065cc80 @ 0x0065cc80 ====

void FUN_0065cc80(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *local_94;
  uint local_90;
  uint uStack_8c;
  undefined4 uStack_88;
  void *pvStack_84;
  void *local_80;
  undefined4 local_7c;
  uint local_74;
  uint uStack_70;
  uint uStack_6c;
  void *pvStack_68;
  void *local_64;
  undefined4 local_60 [2];
  undefined1 local_58;
  uint uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 uStack_40;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  if (*(char *)(in_ECX + 0x1c) != '\0') {
    local_44 = 0xf;
    local_48 = 0;
    local_58 = 0;
    local_60[0] = 0xf;
    local_64 = (void *)0x0;
    local_74 = local_74 & 0xffffff00;
    local_7c = 0xf;
    local_80 = (void *)0x0;
    local_90 = local_90 & 0xffffff00;
    FUN_00401740(s_edt_account_009d6418,0xb);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_94);
    if (0xf < local_80) {
      _free(local_94);
      return;
    }
    local_80 = (void *)0xf;
    pvStack_84 = (void *)0x0;
    local_94 = (void *)((uint)local_94 & 0xffffff00);
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      FUN_00550970(local_60);
    }
    local_80 = (void *)0xf;
    pvStack_84 = (void *)0x0;
    local_94 = (void *)((uint)local_94 & 0xffffff00);
    FUN_00401740(s_edt_password_009d6424,0xc);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(local_60 + -0xe);
    if ((void *)0xf < pvStack_84) {
      _free(unaff_EBX);
      return;
    }
    pvStack_84 = (void *)0xf;
    uStack_88 = 0;
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 != 0) {
      uVar3 = FUN_00550150();
      FUN_00401660(uVar3,0,0xffffffff);
    }
    if (uStack_50 == 0) {
      uVar3 = 0x2580001;
    }
    else {
      if (uStack_6c != 0) {
        iVar2 = (**(code **)(*DAT_00b5ac80 + 8))(*(undefined1 *)(in_ECX + 0xc));
        uStack_4c = 0;
        uStack_2c = 0xf;
        uStack_30 = 0;
        uStack_40 = 0;
        uStack_10 = 0xf;
        uStack_14 = 0;
        uStack_24 = 0;
        local_48._0_2_ = CONCAT11(*(undefined1 *)(iVar2 + 0x101),*(undefined1 *)(in_ECX + 0xc));
        FUN_00401660(&pvStack_68,0,0xffffffff);
        FUN_00401660(&pvStack_84,0,0xffffffff);
        iVar2 = (**(code **)(*DAT_00b5a6a8 + 4))();
        if (iVar2 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_0065b5b0();
        }
        FUN_0065b680(&uStack_4c);
        FUN_00797a20(uVar3);
        iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
        if (iVar2 == 0) {
          FUN_004f44a0(&pvStack_68);
        }
        FUN_00844200();
        if (0xf < uStack_6c) {
          _free(local_80);
          return;
        }
        uStack_6c = 0xf;
        uStack_70 = 0;
        local_80 = (void *)((uint)local_80 & 0xffffff00);
        if (uStack_50 < 0x10) {
          return;
        }
        _free(local_64);
        return;
      }
      uVar3 = 0x2580002;
    }
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(5,uVar3);
    local_90 = 0;
    uStack_8c = 0xf;
    FUN_00401660(uVar3,0,0xffffffff);
    FUN_0065c980(local_60 + -0x11);
    if (0xf < uStack_8c) {
      _free((void *)(unaff_EBP & 0xffffff00));
      return;
    }
    if (0xf < uStack_70) {
      _free(pvStack_84);
      return;
    }
    uStack_70 = 0xf;
    local_74 = 0;
    pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
  }
  return;
}


// ==== FUN_0065cf40 @ 0x0065cf40 ====

void FUN_0065cf40(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  void *unaff_EBP;
  undefined1 auStack_76 [10];
  uint uStack_6c;
  undefined4 uStack_68;
  void *pvStack_64;
  undefined1 auStack_60 [4];
  undefined1 uStack_5c;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_8;
  
  iVar1 = (**(code **)(*DAT_00b5ac80 + 8))(*(undefined1 *)(in_ECX + 0xc));
  uStack_48 = 0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  pvStack_64 = (void *)0xf;
  uStack_68 = 0;
  (**(code **)(*DAT_00b5a6d4 + 0x10))(auStack_60,auStack_76 + -6);
  uStack_4c = 0;
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  uStack_48._0_2_ = CONCAT11(*(undefined1 *)(iVar1 + 0x101),*(undefined1 *)(in_ECX + 0xc));
  FUN_00401660(&uStack_68,0,0xffffffff);
  FUN_00401660(auStack_76 + -0xe,0,0xffffffff);
  uStack_4c = uStack_8;
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009d6470;
    puVar2[1] = 0;
    *(undefined1 *)(puVar2 + 2) = 0xff;
    *(undefined1 *)((int)puVar2 + 9) = 0xff;
    puVar2[9] = 0xf;
    puVar2[8] = 0;
    *(undefined1 *)(puVar2 + 4) = 0;
    puVar2[0x10] = 0xf;
    puVar2[0xf] = 0;
    *(undefined1 *)(puVar2 + 0xb) = 0;
  }
  puVar2[1] = uStack_4c;
  *(undefined1 *)(puVar2 + 2) = (undefined1)uStack_48;
  *(undefined1 *)((int)puVar2 + 9) = uStack_48._1_1_;
  FUN_00401660(auStack_44,0,0xffffffff);
  FUN_00401660(auStack_28,0,0xffffffff);
  FUN_00797a20(puVar2);
  iVar1 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar1 == 0) {
    FUN_004f44a0(&uStack_68);
  }
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  if (0xf < uStack_2c) {
    _free(pvStack_40);
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  if (0xf < uStack_6c) {
    _free(unaff_EBP);
    return;
  }
  if (uStack_50 < 0x10) {
    return;
  }
  _free(pvStack_64);
  return;
}


// ==== FUN_0065d110 @ 0x0065d110 ====

void FUN_0065d110(void)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined4 *puVar7;
  void *unaff_ESI;
  undefined4 uStack_24;
  void *pvStack_20;
  void *pvStack_1c;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5a6d4 + 0xc))();
  uStack_24 = (void *)CONCAT13(uVar1,(undefined3)uStack_24);
  cVar2 = FUN_0065c260();
  *(char *)(in_ECX + 0xc) = cVar2;
  if (cVar2 != -1) {
    uStack_18 = uStack_18 & 0xffffff00;
    uStack_8 = 0;
    uStack_4 = 0xf;
    if (uStack_24._3_1_ != '\0') {
      FUN_00401740(s_pan_selectgroup_009d6348,0xf);
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x24))(0);
      }
      if (uStack_8 < 0x10) {
        uVar4 = (**(code **)(*DAT_00b5a6d4 + 8))();
        FUN_0065cf40(uVar4);
        return;
      }
      _free(pvStack_1c);
      return;
    }
    FUN_00401740(s_pan_login_009d6358,9);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_1c);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(1);
    }
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return;
    }
    *(undefined1 *)(in_ECX + 0x1c) = 1;
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(s_pan_selectgroup_009d6364,0xf);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_20);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x24))(0);
    }
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    FUN_00401740(s_btn_pantheon_009d6374,0xc);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&uStack_24);
    if (piVar3 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar3 + 0x30))();
      if (iVar5 != 0) {
        FUN_005582f0((int)register0x00000010 + -0x2c);
      }
    }
    if (0xf < uStack_10) {
      _free(uStack_24);
      return;
    }
    FUN_0065c4e0();
    uStack_10 = 0xf;
    uStack_14 = 0;
    uStack_24 = (void *)((uint)uStack_24 & 0xffffff00);
    FUN_00401740(s_edt_account_009d6384,0xb);
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))((int)register0x00000010 + -0x28);
    if (0xf < uStack_14) {
      _free(unaff_ESI);
      return;
    }
    uStack_14 = 0xf;
    uStack_18 = 0;
    puVar6 = operator_new(8);
    puVar7 = (undefined4 *)0x0;
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = &PTR_FUN_009b1798;
      puVar7 = puVar6;
    }
    uVar4 = (**(code **)(*piVar3 + 4))();
    puVar7[1] = uVar4;
    FUN_00797a20(puVar7);
    FUN_0065c720();
  }
  return;
}


// ==== FUN_0065d320 @ 0x0065d320 ====

undefined4 FUN_0065d320(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined1 local_1c [28];
  
  if ((param_1 == 1) && (param_3 == 1)) {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_login_009d62d4,9);
    if (iVar2 == 0) {
      FUN_0065cc80();
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_quit_009d62e0);
    if (cVar1 != '\0') {
      PostQuitMessage(0);
      return 1;
    }
    cVar1 = FUN_004036a0(param_2,s_btn_pantheon_009d62ec);
    if (cVar1 != '\0') {
      FUN_00401830(s_pan_login_009d62fc);
      FUN_0065c200(local_1c,0);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    cVar1 = FUN_004036a0(param_2,s_select_ok_009d6324);
    if (cVar1 != '\0') {
      FUN_0065d110();
    }
  }
  return 0;
}


// ==== FUN_0065d450 @ 0x0065d450 ====

void FUN_0065d450(void)

{
  char cVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 unaff_EBX;
  uint uVar7;
  int local_30;
  void *pvStack_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *pvStack_1c;
  void *pvStack_18;
  undefined4 uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  uVar3 = (**(code **)(*DAT_00b5ac80 + 0x18))();
  uVar7 = 0;
  if (uVar3 != 0) {
    do {
      iVar4 = (**(code **)(*DAT_00b5ac80 + 8))(uVar7);
      if (iVar4 != 0) {
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        pcVar5 = (char *)(iVar4 + 1);
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00401740((char *)(iVar4 + 1),(int)pcVar5 - (iVar4 + 2));
        FUN_00406720(&pvStack_1c);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return;
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar3);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_list_serverlist_009d6284,0xf);
  piVar6 = (int *)(**(code **)(**(int **)(local_30 + 4) + 0x34))(&pvStack_1c);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  uVar3 = (uint)pvStack_1c >> 8;
  pvStack_1c = (void *)(uVar3 << 8);
  if (piVar6 == (int *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)(uVar3 << 8);
    FUN_00401740(s_FALSE_009d6294,5);
    FUN_00406880(&local_20);
    if (uStack_8 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_1c);
    return;
  }
  (**(code **)(*piVar6 + 0x30))();
  FUN_00576750(&local_30);
  if (pvStack_2c == (void *)0x0) {
    return;
  }
  FUN_00405de0(pvStack_2c,local_28,&local_30,unaff_EBX);
  _free(pvStack_2c);
  return;
}


// ==== FUN_0065d610 @ 0x0065d610 ====

/* WARNING: Removing unreachable block (ram,0x0065d8e1) */

void FUN_0065d610(void)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  undefined4 uStack_70;
  char *pcStack_6c;
  void *pvStack_54;
  void *pvStack_50;
  void *pvStack_4c;
  undefined1 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_3c;
  void *local_38;
  void *local_34;
  void *pvStack_30;
  uint local_24;
  uint local_20;
  uint uStack_1c;
  
  pcStack_6c = (char *)0x65d620;
  pvVar2 = operator_new(8);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    pcStack_6c = (char *)0x65d631;
    uVar3 = FUN_006669a0();
  }
  pcStack_6c = s_UI_Game2_ui_loginwnd_txt_009d61f4;
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  uStack_70 = 0x65d659;
  FUN_00401740();
  pcStack_6c = (char *)0x65d663;
  iVar4 = FUN_00410500();
  if (0xf < local_20) {
    pcStack_6c = (char *)0x65d679;
    _free(local_34);
    return;
  }
  if (iVar4 == 0) {
    pcStack_6c = s______login_ui_file_load_error____009d6210;
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    uStack_70 = 0x65d6a0;
    FUN_00401740();
    pcStack_6c = (char *)0x65d6aa;
    FUN_00403e50();
    if (0xf < local_20) {
      pcStack_6c = (char *)0x65d6c2;
      _free(local_34);
      return;
    }
    pcStack_6c = s_FALSE_009d6234;
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    uStack_70 = 0x65d6e1;
    FUN_00401740();
    pcStack_6c = (char *)0x65d6eb;
    FUN_00406880();
    if (local_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    pcStack_6c = (char *)0x65d6fe;
    _free(local_34);
    return;
  }
  pcStack_6c = (char *)(iVar4 + 0x3c);
  uStack_70 = 0x65d71a;
  piVar5 = (int *)(**(code **)(*DAT_00b5a798 + 4))();
  *(int **)(in_ECX + 4) = piVar5;
  (**(code **)(*piVar5 + 0x40))();
  (**(code **)(**(int **)(in_ECX + 4) + 0x48))(*(undefined4 *)(in_ECX + 0x10));
  (**(code **)(*DAT_00b5a7cc + 0x14))(iVar4);
  FUN_0065d450();
  iVar4 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar4 != 0) {
    local_34 = (void *)0xf;
    local_38 = (void *)0x0;
    uStack_48 = 0;
    FUN_00401740(s_pan_15_009d623c,6);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_4c);
    if (0xf < local_38) {
      _free(pvStack_4c);
      return;
    }
    local_38 = (void *)0xf;
    uStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    if (piVar5 == (int *)0x0) {
      FUN_00401830(s_pComposite____NULL_009d6244);
      FUN_00406880(&local_34);
      if (uStack_1c < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_30);
      return;
    }
    (**(code **)(*piVar5 + 0x24))(0);
    uStack_3c = 0xf;
    uStack_40 = 0;
    pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
    FUN_00401740(s_pan_18_009d6258,6);
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&pvStack_54);
    if (0xf < uStack_40) {
      _free(pvStack_54);
      return;
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    if (piVar5 == (int *)0x0) {
      FUN_00401830(s_pComposite____NULL_009d6260);
      FUN_00406880(&uStack_3c);
      if (local_24 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(local_38);
      return;
    }
    (**(code **)(*piVar5 + 0x24))(0);
  }
  FUN_0065c4e0();
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x2580009);
  pcStack_6c = (char *)((uint)pcStack_6c & 0xffffff00);
  FUN_00401660(uVar3,0,0xffffffff);
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  FUN_00401740(s_lbl_loginwaring_009d6274,0xf);
  FUN_0065c460(&pvStack_54,&uStack_70);
  if (uStack_3c < 0x10) {
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_0065d900 @ 0x0065d900 ====

void FUN_0065d900(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = param_1;
  *in_ECX = &PTR_FUN_009d643c;
  *(undefined1 *)(in_ECX + 3) = 0xff;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  FUN_0065d610();
  return;
}


// ==== FUN_0065d930 @ 0x0065d930 ====

undefined4 FUN_0065d930(void)

{
  return 0x15;
}


// ==== FUN_0065d940 @ 0x0065d940 ====

void FUN_0065d940(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d643c;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065d990 @ 0x0065d990 ====

undefined1 FUN_0065d990(void)

{
  return 0;
}


// ==== FUN_0065d9a0 @ 0x0065d9a0 ====

undefined1 FUN_0065d9a0(void)

{
  return 0;
}


// ==== FUN_0065d9b0 @ 0x0065d9b0 ====

void FUN_0065d9b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d64e0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0065d9d0 @ 0x0065d9d0 ====

void FUN_0065d9d0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d64e0;
  in_ECX[1] = 0;
  iVar1 = FUN_00410500(param_1);
  piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  in_ECX[1] = piVar2;
  (**(code **)(*piVar2 + 0x40))();
  return;
}


// ==== FUN_0065da10 @ 0x0065da10 ====

void FUN_0065da10(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_creditwnd_txt_009d64bc,0x19);
  iVar1 = FUN_00410500(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
  *(undefined4 *)(in_ECX + 4) = uVar2;
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))();
  return;
}


// ==== FUN_0065daa0 @ 0x0065daa0 ====

void FUN_0065daa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d64e0;
  in_ECX[1] = 0;
  FUN_0065da10();
  return;
}


// ==== FUN_0065dac0 @ 0x0065dac0 ====

undefined4 FUN_0065dac0(void)

{
  return 0x1e;
}


// ==== FUN_0065dad0 @ 0x0065dad0 ====

void FUN_0065dad0(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d64e0;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065db10 @ 0x0065db10 ====

undefined4 FUN_0065db10(void)

{
  return 0x70250001;
}


// ==== FUN_0065db20 @ 0x0065db20 ====

void FUN_0065db20(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
                    /* WARNING: Could not recover jumptable at 0x0065db2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_0065db30 @ 0x0065db30 ====

undefined1 FUN_0065db30(void)

{
  return 0;
}


// ==== FUN_0065db40 @ 0x0065db40 ====

void FUN_0065db40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d65ac;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  return;
}


// ==== FUN_0065db60 @ 0x0065db60 ====

undefined4 FUN_0065db60(int param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_3 != 1) || (param_1 != 1)) {
    return 0;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_btn_exit_009d6578,8);
  if ((iVar2 != 0) && (cVar1 = FUN_004036a0(param_2,s_btn_cancel_009d6584), cVar1 == '\0')) {
    return 0;
  }
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar3 = &PTR_FUN_009d6598;
  FUN_00797a20(puVar3);
  return 1;
}


// ==== FUN_0065dbe0 @ 0x0065dbe0 ====

void FUN_0065dbe0(void *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 uStack00000000;
  uint in_stack_00000018;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_lbl_text_009d656c,8);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))();
    FUN_0055a260(&uStack00000000);
  }
  if (in_stack_00000018 < 0x10) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_0065dc70 @ 0x0065dc70 ====

void FUN_0065dc70(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_UI_Game2_ui_testManagewnd_txt_009d654c,0x1d);
  iVar1 = FUN_00410500(local_1c);
  if (local_4 < 0x10) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a798 + 4))(iVar1 + 0x3c,0);
    *(int **)(in_ECX + 4) = piVar2;
    (**(code **)(*piVar2 + 0x40))();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0065dcf0 @ 0x0065dcf0 ====

void FUN_0065dcf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d65ac;
  FUN_0065dc70();
  return;
}


// ==== FUN_0065dd10 @ 0x0065dd10 ====

undefined4 FUN_0065dd10(void)

{
  return 0x25;
}


// ==== FUN_0065dd20 @ 0x0065dd20 ====

void FUN_0065dd20(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009d65ac;
  (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[1]);
  *in_ECX = &PTR_FUN_009b1764;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065dd60 @ 0x0065dd60 ====

void FUN_0065dd60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d69d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0065dd80 @ 0x0065dd80 ====

void FUN_0065dd80(ushort param_1,ushort param_2)

{
  int in_ECX;
  ushort uVar1;
  
  uVar1 = 0xff;
  if (param_2 < 0x100) {
    uVar1 = param_2;
  }
  if (0xff < param_1) {
    param_1 = 0xff;
  }
  *(ushort *)(in_ECX + 0x20) = param_1 << 8 | uVar1;
  return;
}


// ==== FUN_0065ddc0 @ 0x0065ddc0 ====

void FUN_0065ddc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
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
  in_ECX[7] = param_4[4];
  *(undefined1 *)(in_ECX + 8) = param_5;
  *(undefined1 *)((int)in_ECX + 0x21) = 0;
  return;
}


// ==== FUN_0065de10 @ 0x0065de10 ====

void FUN_0065de10(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [5];
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if (in_ECX[1] != 0) {
    puVar1 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
    puVar3 = auStack_24;
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    param_1 = param_1 - (iStack_8 - iStack_10) / 2;
    param_2 = param_2 - (iStack_4 - iStack_c) / 2;
    if (in_ECX[1] != 0) {
      iVar2 = (**(code **)(*in_ECX + 0x14))();
      if ((iVar2 != 10) && (iVar2 = (**(code **)(*in_ECX + 0x14))(), iVar2 != 0x7b)) {
        (**(code **)(*(int *)in_ECX[1] + 0x54))(param_1,param_2,1);
        return;
      }
      (**(code **)(*(int *)in_ECX[1] + 0x54))(param_1,param_2,0);
    }
  }
  return;
}


// ==== FUN_0065deb0 @ 0x0065deb0 ====

undefined4 * FUN_0065deb0(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    return param_1;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  *param_1 = *(undefined4 *)(iVar1 + 0x14);
  param_1[1] = *(undefined4 *)(iVar1 + 0x18);
  return param_1;
}


// ==== FUN_0065def0 @ 0x0065def0 ====

undefined4 FUN_0065def0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a74c + 0xc))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a750 + 0xc))(0x7b);
  }
  (**(code **)(*DAT_00b5a750 + 8))(0x7b);
  FUN_00666dd0(uRam0000007f,uRam00000083,uRam00000087,uRam0000008b);
  return 1;
}


// ==== FUN_0065df40 @ 0x0065df40 ====

undefined4 FUN_0065df40(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x20);
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  switch(*(undefined1 *)(param_1 + 0x21)) {
  case 1:
    if (cVar1 == '\x05') {
      (**(code **)(*DAT_00b5a9dc + 8))(uVar2);
      return 1;
    }
    break;
  case 2:
    if (cVar1 == '\x01') {
      (**(code **)(*DAT_00b5a9dc + 8))(uVar2);
      return 1;
    }
    goto LAB_0065df8b;
  case 10:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5a9dc + 8))(uVar2);
      return 1;
    }
    break;
  case 0xf:
    if ((cVar1 == '\0') || (cVar1 == '\x01')) goto LAB_0065df91;
LAB_0065df8b:
    if (cVar1 == '\x02') {
LAB_0065df91:
      (**(code **)(*DAT_00b5a9dc + 8))(uVar2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0065e010 @ 0x0065e010 ====

void FUN_0065e010(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  uint local_4;
  
  local_4 = 0;
  piVar5 = (int *)(in_ECX + 4);
  do {
    if ((*piVar5 != 0) || (piVar5[1] != 0)) {
      piVar3 = (int *)(**(code **)(*DAT_00b5a74c + 0xc))(local_4);
      if (piVar3 != (int *)0x0) {
        iVar1 = *piVar5;
        iVar2 = piVar5[1];
        if (piVar3[1] != 0) {
          iVar4 = (**(code **)(*piVar3 + 0x14))();
          if (iVar4 != 10) {
            iVar4 = (**(code **)(*piVar3 + 0x14))();
            if (iVar4 != 0x7b) {
              (**(code **)(*(int *)piVar3[1] + 0x54))(iVar1,iVar2,1);
              goto LAB_0065e07c;
            }
          }
          (**(code **)(*(int *)piVar3[1] + 0x54))(iVar1,iVar2,0);
        }
      }
    }
LAB_0065e07c:
    local_4 = local_4 + 1;
    piVar5 = piVar5 + 2;
    if (0x8a < local_4) {
      return;
    }
  } while( true );
}


// ==== FUN_0065e0a0 @ 0x0065e0a0 ====

void FUN_0065e0a0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int unaff_EBX;
  undefined1 uStack00000000;
  undefined1 auStack_12 [18];
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a750 + 8))(param_1);
  FUN_00558e70(auStack_12 + -6,&uStack00000000);
  uVar1 = *(undefined4 *)(unaff_EBX + 0x14);
  uVar2 = *(undefined4 *)(unaff_EBX + 0x18);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x24))(*(undefined4 *)(unaff_EBX + 0x1c));
    uStack00000000 = (char)param_1;
    if (uStack00000000 == '\x01') {
      FUN_0050a850(uVar1,uVar2);
    }
  }
  return;
}


// ==== FUN_0065e110 @ 0x0065e110 ====

uint FUN_0065e110(undefined4 param_1)

{
  int in_ECX;
  uint local_14 [5];
  
  FUN_00558e70(local_14,&param_1);
  if (local_14[0] == *(uint *)(in_ECX + 0x460)) {
    return local_14[0] & 0xffffff00;
  }
  return *(uint *)(local_14[0] + 0x10);
}


// ==== FUN_0065e170 @ 0x0065e170 ====

/* WARNING: Removing unreachable block (ram,0x0065e223) */

undefined4 FUN_0065e170(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_1e [26];
  int iStack_4;
  
  iVar3 = (**(code **)(*DAT_00b5a74c + 0xc))();
  if (iVar3 != 0) {
    (**(code **)(*DAT_00b5a750 + 0xc))();
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a750 + 8))(10);
  uVar1 = *(undefined4 *)(iStack_4 + 4);
  uVar2 = *(undefined4 *)(iStack_4 + 8);
  if (piVar4[1] != 0) {
    iVar3 = (**(code **)(*piVar4 + 0x14))();
    if ((iVar3 == 10) || (iVar3 = (**(code **)(*piVar4 + 0x14))(), iVar3 == 0x7b)) {
      (**(code **)(*(int *)piVar4[1] + 0x54))(uVar1,uVar2,0);
    }
    else {
      (**(code **)(*(int *)piVar4[1] + 0x54))(uVar1,uVar2,1);
    }
  }
  FUN_00401660(iStack_4 + 0xc,0,0xffffffff);
  FUN_00667200(auStack_1e + -6);
  return 1;
}


// ==== FUN_0065e240 @ 0x0065e240 ====

void FUN_0065e240(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined1 *_Memory;
  undefined1 auStack_1a [2];
  uint uStack_18;
  
  cVar1 = FUN_0065df40(param_1);
  if ((cVar1 != '\x01') &&
     (piVar2 = (int *)(**(code **)(*DAT_00b5a74c + 0xc))(*(undefined4 *)(param_1 + 0x24)),
     piVar2 != (int *)0x0)) {
    FUN_00401660(param_1 + 4,0,0xffffffff);
    _Memory = auStack_1a + -6;
    (**(code **)(*piVar2 + 0x18))
              (*(undefined4 *)(param_1 + 0x24),*(undefined1 *)(param_1 + 0x20),
               *(undefined4 *)(param_1 + 0x28));
    if (0xf < uStack_18) {
      _free(_Memory);
      return;
    }
  }
  return;
}


// ==== FUN_0065e2d0 @ 0x0065e2d0 ====

undefined4 FUN_0065e2d0(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  undefined2 uStack_c;
  undefined4 uStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a9dc + 0x14))();
  if (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar2 + 8))();
    switch(uVar3) {
    case 0:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x100;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 1:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0xf00;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 2:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1d00;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 3:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1e00;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 4:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0xf01;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 5:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      break;
    case 6:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1000;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 7:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1100;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 8:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1200;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 9:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1300;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 10:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1400;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0xb:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1500;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0xc:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1600;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0xd:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1700;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0xe:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1800;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0xf:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1900;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0x10:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1c00;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0x11:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1a00;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0x12:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x1b00;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0x13:
      FUN_00663a10();
      uStack_c = 0x202;
      uStack_4 = 2;
      FUN_0065e240(auStack_2c);
      (**(code **)(*DAT_00b5a750 + 0xc))(4);
      FUN_00663a50();
      return 1;
    case 0x14:
      FUN_00663a10();
      uStack_c = 0x201;
      uStack_4 = 2;
      FUN_0065e240(auStack_2c);
      (**(code **)(*DAT_00b5a750 + 0xc))(4);
      FUN_00663a50();
      return 1;
    default:
      return 0;
    case 0x16:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0xa00;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0x18:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x2200;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0x19:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x2201;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    case 0x1a:
      pvVar4 = operator_new(0x2c);
      if (pvVar4 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_00663a10();
      }
      *(undefined2 *)(iVar5 + 0x20) = 0x2202;
      *(undefined4 *)(iVar5 + 0x28) = 0;
      FUN_00797a20(iVar5);
      return 1;
    }
    *(undefined2 *)(iVar5 + 0x20) = 0xf02;
    *(undefined4 *)(iVar5 + 0x28) = 0;
    FUN_00797a20(iVar5);
    return 1;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401740(s_pModal_009d69b8,6);
  FUN_00406880(auStack_2c);
  if (uStack_14 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_28);
  return extraout_EAX;
}


// ==== FUN_0065e8f0 @ 0x0065e8f0 ====

/* WARNING: Removing unreachable block (ram,0x0065e985) */

int FUN_0065e8f0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 unaff_retaddr;
  undefined1 auStack_1a [26];
  
  iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(4);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*DAT_00b5a750 + 8))(4);
    FUN_00668730(unaff_retaddr);
  }
  iVar3 = (**(code **)(*DAT_00b5a6e4 + 8))();
  iVar1 = *(int *)(iVar3 + 0x54);
  *(int *)(in_ECX + 0x24) = *(int *)(iVar3 + 0x50) / 2;
  *(int *)(in_ECX + 0x28) = iVar1 / 2;
  FUN_00401740(s_edit_text_009d69c0,9);
  piVar4 = (int *)(**(code **)(**(int **)(iVar2 + 4) + 0x34))(auStack_1a + -6);
  if (piVar4 != (int *)0x0) {
    puVar5 = operator_new(8);
    puVar7 = (undefined4 *)0x0;
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = &PTR_FUN_009b1798;
      puVar7 = puVar5;
    }
    uVar6 = (**(code **)(*piVar4 + 4))();
    puVar7[1] = uVar6;
    FUN_00797a20(puVar7);
  }
  return iVar2;
}


// ==== FUN_0065e9e0 @ 0x0065e9e0 ====

bool FUN_0065e9e0(int *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x111) {
    if (uVar2 == 0x110) {
      (**(code **)(*DAT_00b5a750 + 0xc))(0x82);
      return true;
    }
    switch(uVar2) {
    case 0x100:
      (**(code **)(*DAT_00b5a750 + 8))(0x7d);
      return true;
    case 0x101:
      (**(code **)(*DAT_00b5a750 + 0xc))(0x7d);
      return true;
    case 0x102:
      (**(code **)(*DAT_00b5a750 + 8))(0x7e);
      return true;
    case 0x103:
      (**(code **)(*DAT_00b5a750 + 0xc))(0x7e);
      return true;
    case 0x105:
      (**(code **)(*DAT_00b5a750 + 4))(0x80,param_1[1]);
      return true;
    case 0x106:
      (**(code **)(*DAT_00b5a750 + 0xc))(0x80);
      return true;
    case 0x107:
      (**(code **)(*DAT_00b5a750 + 8))(0x81);
      return true;
    case 0x108:
      (**(code **)(*DAT_00b5a750 + 8))(0x82);
      return true;
    case 0x109:
      (**(code **)(*DAT_00b5a750 + 0xc))(0x81);
      return true;
    }
  }
  else if (uVar2 < 0x70030001) {
    if (uVar2 == 0x70030000) {
      iVar3 = FUN_0065e8f0(param_1);
      if (iVar3 == 0) {
        return true;
      }
      FUN_0065de10(*(undefined4 *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0x28));
      return true;
    }
    if (uVar2 < 0x50050002) {
      if (uVar2 == 0x50050001) {
        (**(code **)(*DAT_00b5a750 + 8))(0x37);
        return true;
      }
      if (uVar2 == 400) {
        (**(code **)(*DAT_00b5a750 + 8))(0x7f);
        return true;
      }
      if (uVar2 == 0x191) {
        (**(code **)(*DAT_00b5a750 + 0xc))(0x7f);
        return true;
      }
    }
    else if (uVar2 == 0x50050002) {
      (**(code **)(*DAT_00b5a750 + 0xc))(0x37);
      return true;
    }
  }
  else {
    if (uVar2 == 0x70030001) {
      FUN_0065e240(param_1);
      (**(code **)(*DAT_00b5a750 + 0xc))(4);
      return true;
    }
    if (uVar2 == 0x70900000) {
      (**(code **)(*DAT_00b5a750 + 8))(0x51);
      return true;
    }
    if (uVar2 == 0x70900001) {
      (**(code **)(*DAT_00b5a750 + 0xc))(0x51);
      return true;
    }
  }
  cVar1 = (**(code **)(*DAT_00b5a74c + 0x14))(param_1);
  return cVar1 == '\x01';
}


// ==== FUN_0065ec30 @ 0x0065ec30 ====

void FUN_0065ec30(undefined1 param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_10;
  
  piVar2 = param_2;
  if (param_2 != (int *)0x0) {
    FUN_00558e70(&param_2,&param_1);
    iVar1 = param_2[4];
    uVar4 = (**(code **)(*piVar2 + 0x28))();
    if (piVar2[1] == 0) {
      uVar8 = 0;
      uVar7 = 0;
    }
    else {
      iVar5 = (**(code **)(*(int *)piVar2[1] + 0x14))();
      uVar8 = *(undefined4 *)(iVar5 + 0x14);
      uVar7 = *(undefined4 *)(iVar5 + 0x18);
    }
    uVar3 = (**(code **)(*piVar2 + 0x2c))();
    local_10 = CONCAT31((int3)((uint)iVar1 >> 8),uVar3);
    puVar6 = (undefined4 *)FUN_00664060(&param_1);
    *puVar6 = local_10;
    puVar6[1] = uVar8;
    puVar6[2] = uVar7;
    puVar6[3] = uVar4;
  }
  return;
}


// ==== FUN_0065ece0 @ 0x0065ece0 ====

void FUN_0065ece0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  int local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00558e70(&local_28,&param_1);
  uVar3 = param_2;
  if (local_28 == *(int *)(in_ECX + 0x460)) {
    local_8 = param_3;
    local_24 = local_24 & 0xffffff00;
    local_4 = 0;
    local_14 = param_1;
    local_c = param_2;
    local_10 = local_24;
    FUN_00663d70(&param_2,&local_14);
    return;
  }
  uVar1 = *(undefined4 *)(local_28 + 0x10);
  local_20 = *(undefined4 *)(local_28 + 0x14);
  local_1c = *(undefined4 *)(local_28 + 0x18);
  uVar2 = *(undefined4 *)(local_28 + 0x1c);
  puVar4 = (undefined4 *)FUN_00664060(&param_1);
  *puVar4 = uVar1;
  puVar4[1] = uVar3;
  puVar4[2] = param_3;
  puVar4[3] = uVar2;
  return;
}


// ==== FUN_0065ed90 @ 0x0065ed90 ====

void FUN_0065ed90(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a74c + 0xc))(param_1);
  FUN_0065ec30(param_1,uVar1);
  (**(code **)(*DAT_00b5a750 + 0xc))(param_1);
  return;
}


// ==== FUN_0065edc0 @ 0x0065edc0 ====

void FUN_0065edc0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009d6a04;
  FUN_006638a0(*(undefined4 *)(in_ECX[0x118] + 4));
  *(undefined4 *)(in_ECX[0x118] + 4) = in_ECX[0x118];
  in_ECX[0x119] = 0;
  *(undefined4 *)in_ECX[0x118] = in_ECX[0x118];
  *(undefined4 *)(in_ECX[0x118] + 8) = in_ECX[0x118];
  if (DAT_00b5b0c0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b0c0)(1);
  }
  DAT_00b5a748 = 0;
  FUN_00663fa0(local_4,*(undefined4 *)in_ECX[0x118],(undefined4 *)in_ECX[0x118]);
  _free((void *)in_ECX[0x118]);
  return;
}


// ==== FUN_0065ee40 @ 0x0065ee40 ====

void FUN_0065ee40(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  
  FUN_0065ece0(0x1c,0x339,0);
  FUN_0065ece0(0x7f,0x14f,0xa5);
  FUN_0065ece0(9,0x14f,0xa5);
  FUN_0065ece0(0x2b,0x14f,0xa5);
  FUN_0065ece0(0x3c,0x146,0xa5);
  FUN_0065ece0(0x2a,0x14f,0xa5);
  FUN_0065ece0(7,0x2b4,0xa5);
  FUN_0065ece0(0xb,0,0xa5);
  FUN_0065ece0(0xe,0,0xa5);
  FUN_0065ece0(0xd,0x14f,0xa5);
  FUN_0065ece0(8,0x14f,0xa5);
  FUN_0065ece0(2,0x17f,0x105);
  FUN_0065ece0(3,0x19f,0x143);
  FUN_0065ece0(0,100,0x32);
  FUN_0065ece0(0x6c,200,0x104);
  FUN_0065ece0(0x6d,100,0xa0);
  FUN_0065ece0(0x74,10,100);
  FUN_0065ece0(0x71,10,100);
  FUN_0065ece0(0x14,100,0x32);
  FUN_0065ece0(0x1d,0x100,100);
  FUN_0065ece0(0x29,0,0xa5);
  FUN_0065ece0(0x2c,0x172,0x12f);
  FUN_0065ece0(0x41,0x172,0x12f);
  FUN_0065ece0(0x2d,0x172,0x12f);
  FUN_0065ece0(0x2e,0x15e,0x92);
  FUN_0065ece0(0x34,0x100,0xdf);
  FUN_0065ece0(0x35,0x172,0x12f);
  FUN_0065ece0(0x38,0,0x19);
  FUN_0065ece0(0x3a,0x172,0x12f);
  FUN_0065ece0(0x4e,8,0x29);
  FUN_0065ece0(0x4f,0x15e,0x92);
  FUN_0065ece0(0x4c,0x15e,0x92);
  FUN_0065ece0(0x52,200,0x92);
  FUN_0065ece0(0x53,600,0x92);
  FUN_0065ece0(0x7d,0,0);
  FUN_0065ece0(0x3e,0x85,0xa7);
  FUN_0065ece0(0x3b,0,0);
  FUN_0065ece0(0x57,0,0);
  *(undefined4 *)(in_ECX + 0x4c) = 0x14f;
  *(undefined4 *)(in_ECX + 0x15c) = 0x14f;
  *(undefined4 *)(in_ECX + 0x1e4) = 0x146;
  *(undefined4 *)(in_ECX + 0x50) = 0xa5;
  *(undefined4 *)(in_ECX + 0x160) = 0xa5;
  *(undefined4 *)(in_ECX + 0x1e8) = 0xa5;
  *(undefined4 *)(in_ECX + 0x154) = 0x14f;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x158) = 0xa5;
  *(undefined4 *)(in_ECX + 0x60) = 0xa5;
  *(undefined4 *)(in_ECX + 4) = 100;
  piVar6 = (int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0x32;
  *(undefined4 *)(in_ECX + 0x364) = 10;
  *(undefined4 *)(in_ECX + 0x36c) = 10;
  *(undefined4 *)(in_ECX + 0x368) = 0x3c;
  *(undefined4 *)(in_ECX + 0x370) = 0x3c;
  *(undefined4 *)(in_ECX + 0x44) = 0x14f;
  *(undefined4 *)(in_ECX + 0x48) = 0xa5;
  *(undefined4 *)(in_ECX + 0x3a4) = 10;
  *(undefined4 *)(in_ECX + 0x38c) = 10;
  *(undefined4 *)(in_ECX + 0x3a8) = 100;
  *(undefined4 *)(in_ECX + 0x390) = 100;
  *(undefined4 *)(in_ECX + 0xa4) = 100;
  *(undefined4 *)(in_ECX + 0xa8) = 0x32;
  *(undefined4 *)(in_ECX + 0xd4) = 0x17e;
  *(undefined4 *)(in_ECX + 0xd8) = 0x268;
  *(undefined4 *)(in_ECX + 0xe4) = 0x339;
  *(undefined4 *)(in_ECX + 0xe8) = 0;
  *(undefined4 *)(in_ECX + 0xec) = 0x100;
  *(undefined4 *)(in_ECX + 0xf0) = 100;
  *(undefined4 *)(in_ECX + 0x14c) = 0;
  *(undefined4 *)(in_ECX + 0x164) = 0x172;
  *(undefined4 *)(in_ECX + 0x20c) = 0x172;
  *(undefined4 *)(in_ECX + 0x16c) = 0x172;
  *(undefined4 *)(in_ECX + 0x150) = 0xa5;
  *(undefined4 *)(in_ECX + 0x1a4) = 0x100;
  *(undefined4 *)(in_ECX + 0x168) = 0x12f;
  *(undefined4 *)(in_ECX + 0x210) = 0x12f;
  *(undefined4 *)(in_ECX + 0x170) = 0x12f;
  *(undefined4 *)(in_ECX + 0x1ac) = 0x172;
  *(undefined4 *)(in_ECX + 0x1c4) = 0;
  *(undefined4 *)(in_ECX + 0x1a8) = 0xdf;
  *(undefined4 *)(in_ECX + 0x1b0) = 0x12f;
  *(undefined4 *)(in_ECX + 0x1d4) = 0x172;
  *(undefined4 *)(in_ECX + 0x1c8) = 0x19;
  *(undefined4 *)(in_ECX + 0x274) = 8;
  *(undefined4 *)(in_ECX + 0x1d8) = 0x12f;
  *(undefined4 *)(in_ECX + 0x27c) = 0x15e;
  *(undefined4 *)(in_ECX + 0x278) = 0x29;
  *(undefined4 *)(in_ECX + 0x280) = 0x92;
  *(undefined4 *)(in_ECX + 0x264) = 300;
  *(undefined4 *)(in_ECX + 0x268) = 0x92;
  *(undefined4 *)(in_ECX + 0x298) = 0x92;
  *(undefined4 *)(in_ECX + 0x2a0) = 0x92;
  *(undefined4 *)(in_ECX + 0x294) = 200;
  *(undefined4 *)(in_ECX + 0x3f0) = 0;
  *(undefined4 *)(in_ECX + 0x29c) = 600;
  *(undefined4 *)(in_ECX + 0x3ec) = 0;
  *(undefined4 *)(in_ECX + 0x1f8) = 0xa7;
  *(undefined4 *)(in_ECX + 500) = 0x85;
  *(undefined4 *)(in_ECX + 0x1e0) = 0;
  *(undefined4 *)(in_ECX + 0x1dc) = 0;
  *(undefined4 *)(in_ECX + 0x3c4) = 0;
  *(undefined4 *)(in_ECX + 0x3c8) = 0x96;
  iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
  *(undefined4 *)(in_ECX + 0x22c) = *(undefined4 *)(iVar2 + 0x24);
  *(undefined4 *)(in_ECX + 0x230) = *(undefined4 *)(iVar2 + 0x28);
  *(undefined4 *)(in_ECX + 0x234) = *(undefined4 *)(iVar2 + 0x2c);
  *(undefined4 *)(in_ECX + 0x238) = *(undefined4 *)(iVar2 + 0x30);
  *(undefined4 *)(in_ECX + 0x23c) = *(undefined4 *)(iVar2 + 0x34);
  *(undefined4 *)(in_ECX + 0x240) = *(undefined4 *)(iVar2 + 0x38);
  uVar5 = 0;
  do {
    if ((*piVar6 != 0) || (piVar6[1] != 0)) {
      piVar3 = (int *)(**(code **)(*DAT_00b5a74c + 0xc))(uVar5);
      if (piVar3 != (int *)0x0) {
        iVar2 = piVar6[1];
        iVar1 = *piVar6;
        if (piVar3[1] != 0) {
          iVar4 = (**(code **)(*piVar3 + 0x14))();
          if (iVar4 == 10) {
LAB_0065f40c:
            uVar7 = 0;
          }
          else {
            iVar4 = (**(code **)(*piVar3 + 0x14))();
            if (iVar4 == 0x7b) goto LAB_0065f40c;
            uVar7 = 1;
          }
          (**(code **)(*(int *)piVar3[1] + 0x54))(iVar1,iVar2,uVar7);
        }
      }
    }
    uVar5 = uVar5 + 1;
    piVar6 = piVar6 + 2;
    if (0x8a < uVar5) {
      iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0x47);
      if (iVar2 == 0) {
        return;
      }
      FUN_00668970();
      return;
    }
  } while( true );
}


// ==== FUN_0065f450 @ 0x0065f450 ====

void FUN_0065f450(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  
  *in_ECX = &PTR_FUN_009d6a04;
  iVar1 = FUN_00663970();
  in_ECX[0x118] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[0x118] + 4) = in_ECX[0x118];
  *(undefined4 *)in_ECX[0x118] = in_ECX[0x118];
  puVar4 = in_ECX + 1;
  *(undefined4 *)(in_ECX[0x118] + 8) = in_ECX[0x118];
  in_ECX[0x119] = 0;
  if (puVar4 == (undefined4 *)0x0) {
    DAT_00b5a748 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a748 = in_ECX;
  }
  FUN_006638a0(*(undefined4 *)(in_ECX[0x118] + 4));
  *(undefined4 *)(in_ECX[0x118] + 4) = in_ECX[0x118];
  in_ECX[0x119] = 0;
  *(undefined4 *)in_ECX[0x118] = in_ECX[0x118];
  *(undefined4 *)(in_ECX[0x118] + 8) = in_ECX[0x118];
  uVar3 = 0;
  do {
    *puVar4 = 0;
    puVar4[1] = 0;
    FUN_0065ece0(uVar3,0,0);
    uVar3 = uVar3 + 1;
    puVar4 = puVar4 + 2;
  } while (uVar3 < 0x8b);
  FUN_0065ee40();
  if (DAT_00b5b0c0 == 0) {
    pvVar2 = operator_new(0xc);
    if (pvVar2 != (void *)0x0) {
      FUN_00669670();
    }
  }
  return;
}


// ==== FUN_0065f510 @ 0x0065f510 ====

uint FUN_0065f510(void)

{
  code *pcVar1;
  uint extraout_EAX;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined1 auStack_2d8 [4];
  void *pvStack_2d4;
  int *piStack_2c4;
  uint uStack_2c0;
  undefined1 auStack_2bc [28];
  undefined1 auStack_2a0 [28];
  undefined1 auStack_284 [28];
  undefined1 auStack_268 [28];
  undefined1 auStack_24c [28];
  undefined1 auStack_230 [28];
  undefined1 auStack_214 [28];
  undefined1 auStack_1f8 [28];
  undefined1 auStack_1dc [28];
  undefined1 auStack_1c0 [28];
  undefined1 auStack_1a4 [28];
  undefined1 auStack_188 [28];
  undefined1 auStack_16c [28];
  undefined1 auStack_150 [28];
  undefined1 auStack_134 [28];
  undefined1 auStack_118 [28];
  undefined1 auStack_fc [28];
  undefined1 auStack_e0 [28];
  undefined1 auStack_c4 [28];
  undefined1 auStack_a8 [28];
  undefined1 auStack_8c [28];
  undefined1 auStack_70 [28];
  undefined1 auStack_54 [28];
  undefined1 auStack_38 [28];
  undefined1 auStack_1c [28];
  
  piStack_2c4 = (int *)(**(code **)(*DAT_00b5a9dc + 0x14))();
  if (piStack_2c4 != (int *)0x0) {
    uVar2 = (**(code **)(*piStack_2c4 + 8))();
    switch(uVar2) {
    case 0:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_partyinvitation_txt_009d6720);
      FUN_00401660(auStack_2d8,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 1:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_joinguild_txt_009d6738);
      FUN_00401660(auStack_70,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 2:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_adornmentguildmark_t_009d6948);
      FUN_00401660(auStack_fc,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 3:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_addfriend_txt_009d674c);
      FUN_00401660(auStack_150,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 4:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_disbandguild_txt_009d6760);
      FUN_00401660(auStack_268,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 5:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_changegradeguild_txt_009d6774);
      FUN_00401660(auStack_a8,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 6:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_dropcashItem_txt_009d67c8);
      FUN_00401660(auStack_38,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 7:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_waringbuycashItem_tx_009d67e8);
      FUN_00401660(auStack_1c0,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 8:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      break;
    case 9:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_errmastermistake_txt_009d682c);
      FUN_00401660(auStack_188,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 10:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_powerreset_txt_009d686c);
      FUN_00401660(auStack_2a0,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0xb:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_energyreset_txt_009d6850);
      FUN_00401660(auStack_2bc,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0xc:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_speedreset_txt_009d6888);
      FUN_00401660(auStack_284,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0xd:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_spiritreset_txt_009d68a4);
      FUN_00401660(auStack_24c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0xe:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_addbag_txt_009d68c0);
      FUN_00401660(auStack_214,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0xf:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_erraddbag_txt_009d68d8);
      FUN_00401660(auStack_1dc,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x10:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_delguildmarkeffect_txt_009d692c);
      FUN_00401660(auStack_134,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x11:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_potalorder_txt_009d68f4);
      FUN_00401660(auStack_1a4,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x12:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_cashItem_ui_potaluse_txt_009d6910);
      FUN_00401660(auStack_16c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x13:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_tradeask_txt_009d678c);
      FUN_00401660(auStack_230,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x14:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_tradeinvitation_txt_009d679c);
      FUN_00401660(auStack_118,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    default:
      return uVar2 & 0xffffff00;
    case 0x16:
      pvVar3 = operator_new(0x58);
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00505380();
      }
      *(undefined4 *)(iVar4 + 0x50) = 0x10;
      FUN_00401830(s_ui_chardelete_txt_009d67b4);
      FUN_00401660(auStack_1f8,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x17:
      pvVar3 = operator_new(0x58);
      if (pvVar3 != (void *)0x0) {
        FUN_00505380();
      }
      FUN_00401830(s_ui_errorbox_txt_009d696c);
      FUN_00401660(auStack_c4,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x18:
      pvVar3 = operator_new(0x58);
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00505380();
      }
      *(undefined4 *)(iVar4 + 0x50) = 0x23;
      FUN_00401830(s_ui_exitwaittime_txt_009d697c);
      FUN_00401660(auStack_8c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x19:
      pvVar3 = operator_new(0x58);
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00505380();
      }
      *(undefined4 *)(iVar4 + 0x50) = 0x23;
      FUN_00401830(s_ui_exitwaittime_txt_009d6990);
      FUN_00401660(auStack_54,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 0x1a:
      pvVar3 = operator_new(0x58);
      if (pvVar3 == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = FUN_00505380();
      }
      *(undefined4 *)(iVar4 + 0x50) = 0x23;
      FUN_00401830(s_ui_exitwaittime_txt_009d69a4);
      FUN_00401660(auStack_1c,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00401830(s_cashItem_ui_mastermistake_txt_009d680c);
    FUN_00401660(auStack_e0,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  uStack_2c0 = 0xf;
  pvStack_2d4 = (void *)((uint)pvStack_2d4 & 0xffffff00);
  FUN_00401740(s_pModal_009d6718,6);
  FUN_00406880(auStack_2d8);
  if (uStack_2c0 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(pvStack_2d4);
  return extraout_EAX;
}


