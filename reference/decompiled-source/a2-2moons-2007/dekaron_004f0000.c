// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x4f0000-0x4fffff

// ==== FUN_004f0030 @ 0x004f0030 ====

bool FUN_004f0030(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 auStack_c [2];
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  piVar6 = DAT_00b5a6ac;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x74) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x74) + 0x14))();
  }
  iVar3 = (**(code **)(*piVar4 + 8))();
  uVar1 = *(undefined1 *)(iVar3 + 4);
  uVar5 = (**(code **)(*piVar6 + 0x20))();
  FUN_00797a50(auStack_c,0,0xc);
  uStack_1 = 1;
  auStack_c[0] = uVar5;
  uStack_2 = uVar1;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  cVar2 = (**(code **)(*piVar6 + 0x20))(auStack_c);
  if (cVar2 == '\0') {
    return false;
  }
  iVar3 = (**(code **)(*piVar6 + 0x10))();
  return *(char *)(iVar3 + 0xb) != '\x01';
}


// ==== FUN_004f00d0 @ 0x004f00d0 ====

void FUN_004f00d0(void)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 auStack_24 [2];
  undefined1 auStack_22 [10];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x28))();
  uStack_18 = *puVar3;
  uStack_14 = puVar3[1];
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x2c))();
  uStack_10 = *puVar3;
  uStack_c = puVar3[1];
  uStack_8 = uVar1;
  iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar4 + 0x74) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar4 + 0x74) + 0x14))();
  }
  iVar4 = (**(code **)(*piVar2 + 8))();
  uStack_4 = *(undefined1 *)(iVar4 + 4);
  FUN_005077f0(&uStack_18,auStack_24);
  iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar2 + 0x24))(auStack_24);
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b2d88;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
  uVar1 = (**(code **)(*piVar2 + 8))();
  puVar3[1] = uVar1;
  FUN_00403e60(puVar3 + 2,auStack_24 + -4,0x19);
  FUN_00797a20(puVar3);
  return;
}


// ==== FUN_004f01e0 @ 0x004f01e0 ====

void FUN_004f01e0(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  cVar2 = FUN_004f0030();
  if (cVar2 == '\0') {
    iVar1 = *DAT_00b5acdc;
    uVar3 = FUN_004e5df0();
    (**(code **)(iVar1 + 8))(uVar3);
    return;
  }
  FUN_004f00d0();
  return;
}


// ==== FUN_004f0220 @ 0x004f0220 ====

void FUN_004f0220(void)

{
  return;
}


// ==== FUN_004f0230 @ 0x004f0230 ====

undefined1 FUN_004f0230(void)

{
  return 1;
}


// ==== FUN_004f0240 @ 0x004f0240 ====

undefined1 FUN_004f0240(void)

{
  return 1;
}


// ==== FUN_004f0250 @ 0x004f0250 ====

void FUN_004f0250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2e50;
  return;
}


// ==== FUN_004f0270 @ 0x004f0270 ====

undefined1 FUN_004f0270(void)

{
  return 1;
}


// ==== FUN_004f02c0 @ 0x004f02c0 ====

void FUN_004f02c0(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2f70;
  in_ECX[1] = *param_1;
  in_ECX[2] = param_1[1];
  in_ECX[3] = param_2;
  *(undefined1 *)(in_ECX + 5) = param_3;
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_2);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    in_ECX[4] = *(undefined4 *)(iVar2 + 0x38);
  }
  return;
}


// ==== FUN_004f0310 @ 0x004f0310 ====

byte FUN_004f0310(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  
  bVar2 = 0;
  iVar4 = (**(code **)(*DAT_00b5a97c + 0x24))();
  if (iVar4 != 0) {
    (**(code **)(*DAT_00b5a97c + 0x24))(param_3);
    cVar1 = FUN_00508320(param_3);
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5a97c + 0x24))();
      bVar2 = FUN_00508340();
    }
  }
  switch(param_2) {
  case 1:
  case 0xe:
  case 0x16:
  case 0x17:
    bVar3 = 4;
    break;
  case 2:
  case 9:
  case 0xb:
  case 0xf:
    bVar3 = 2;
    break;
  default:
    bVar3 = 5;
    break;
  case 7:
  case 8:
    bVar3 = 1;
  }
  if (bVar2 < bVar3) {
    return bVar2;
  }
  return 0;
}


// ==== FUN_004f0460 @ 0x004f0460 ====

void FUN_004f0460(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *param_1;
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = uVar3;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x50d0000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x30;
  iVar2 = FUN_004244d0();
  uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  FUN_00403e60(iVar2 + 0x14,param_1,0x13);
  FUN_004d8570(iVar2);
  return;
}


// ==== FUN_004f04c0 @ 0x004f04c0 ====

float10 FUN_004f04c0(float *param_1)

{
  int *piVar1;
  float *pfVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar2 = (float *)(**(code **)(*piVar1 + 0x28))();
  if (SQRT((*param_1 - *pfVar2) * (*param_1 - *pfVar2) +
           (param_1[1] - pfVar2[1]) * (param_1[1] - pfVar2[1])) -
      (*(float *)(in_ECX + 0x10) + DAT_009b2dbc) < DAT_0099cdc8) {
    return (float10)0.0;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar2 = (float *)(**(code **)(*piVar1 + 0x28))();
  return SQRT(((float10)*param_1 - (float10)*pfVar2) * ((float10)*param_1 - (float10)*pfVar2) +
              ((float10)param_1[1] - (float10)pfVar2[1]) *
              ((float10)param_1[1] - (float10)pfVar2[1])) -
         ((float10)*(float *)(in_ECX + 0x10) + (float10)DAT_009b2dbc);
}


// ==== FUN_004f0590 @ 0x004f0590 ====

undefined4 FUN_004f0590(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar1 + 0x74) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x74) + 0x14))();
  }
  iVar1 = (**(code **)(*piVar2 + 8))();
  if (*(char *)(iVar1 + 4) != '\0') {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar1 + 0x74) == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x74) + 0x14))();
    }
    iVar1 = (**(code **)(*piVar2 + 8))();
    if (*(char *)(iVar1 + 4) != '\x17') {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_004f05f0 @ 0x004f05f0 ====

void FUN_004f05f0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_a [10];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  piVar1 = (int *)(**(code **)(*DAT_00b5a780 + 8))(iVar2 + 0x14);
  if (piVar1 == (int *)0x0) {
    return;
  }
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar2 + 0x74) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x74) + 0x14))();
  }
  (**(code **)(*piVar3 + 8))();
  (**(code **)(*piVar1 + 0xc))(auStack_a + -6);
  return;
}


// ==== FUN_004f0680 @ 0x004f0680 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f0680(undefined4 *param_1,float *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float fStack_8;
  float fStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
  fStack_4 = param_2[1] - pfVar3[1];
  fStack_8 = *param_2 - *pfVar3;
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
  if (_DAT_009b2f68 <
      SQRT((param_2[1] - pfVar3[1]) * (param_2[1] - pfVar3[1]) +
           (*param_2 - *pfVar3) * (*param_2 - *pfVar3))) {
    thunk_FUN_0079de77();
    *(float **)fStack_4 = &fStack_8;
    *(float **)((int)fStack_4 + 4) = &fStack_8;
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x2c))();
  uVar1 = puVar4[1];
  *param_1 = *puVar4;
  param_1[1] = uVar1;
  return;
}


// ==== FUN_004f0750 @ 0x004f0750 ====

void FUN_004f0750(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b2d88;
  }
  uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  puVar1[1] = uVar2;
  FUN_00403e60(puVar1 + 2,param_1,0x19);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004f07a0 @ 0x004f07a0 ====

void FUN_004f07a0(undefined4 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  float10 fVar8;
  float afStack_30 [2];
  undefined1 auStack_28 [8];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined2 uStack_8;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined2 uStack_4;
  undefined1 uStack_2;
  
  piVar5 = DAT_00b5a6ac;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar2 + 0x74) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x74) + 0x14))();
  }
  iVar2 = (**(code **)(*piVar3 + 8))();
  uVar1 = *(undefined1 *)(iVar2 + 4);
  uVar4 = (**(code **)(*piVar5 + 0x20))();
  FUN_00797a50(&uStack_14,0,0x13);
  piVar5 = DAT_00b5a6ac;
  uStack_c = CONCAT13(6,CONCAT12(uVar1,(undefined2)uStack_c));
  uStack_14 = uVar4;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar2 + 0x74) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x74) + 0x14))();
  }
  iVar2 = (**(code **)(*piVar3 + 8))();
  uVar1 = *(undefined1 *)(iVar2 + 4);
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x18) + 0x14))();
  iVar2 = (**(code **)(*piVar3 + 8))();
  afStack_30[0] = (float)CONCAT31(afStack_30[0]._1_3_,*(undefined1 *)(iVar2 + 0x2a));
  uVar4 = (**(code **)(*piVar5 + 0x20))();
  uVar4 = FUN_004f0310(afStack_30[0],uVar1,uVar4);
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
  uStack_20 = *puVar6;
  uStack_1c = puVar6[1];
  uVar7 = FUN_004f0680(auStack_28,param_2);
  fVar8 = (float10)FUN_0040d5f0(uVar7);
  fStack_18 = (float)fVar8;
  iVar2 = FUN_004f05f0(uVar4);
  puVar6 = (undefined4 *)FUN_004ef0e0(afStack_30);
  piVar5 = DAT_00b5a6ac;
  uStack_10 = *puVar6;
  uStack_c = CONCAT22(uStack_c._2_2_,*(undefined2 *)(puVar6 + 1));
  uStack_6 = (undefined1)uVar4;
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iVar2 = iVar2 + 1000;
    uStack_5 = (undefined1)iVar2;
    uStack_4 = (undefined2)((uint)iVar2 >> 8);
    uStack_2 = (undefined1)((uint)iVar2 >> 0x18);
  }
  else {
    afStack_30[0] = *(float *)(iVar2 + 0x114);
    fVar8 = (float10)(**(code **)(*DAT_00b5ad1c + 0x18))();
    iVar2 = (**(code **)(*piVar5 + 0x20))();
    afStack_30[0] = (float)(int)ROUND((float)fVar8 * afStack_30[0]);
    iVar2 = iVar2 + (int)afStack_30[0];
    uStack_5 = (undefined1)iVar2;
    uStack_4 = (undefined2)((uint)iVar2 >> 8);
    uStack_2 = (undefined1)((uint)iVar2 >> 0x18);
  }
  fVar8 = (float10)FUN_004f04c0(param_2);
  if ((float10)DAT_0099cdc8 <= fVar8) {
    uStack_8 = 0xffff;
    if ((uint)(int)ROUND((float10)DAT_009b2d78 * fVar8) < 0x10000) {
      uStack_8 = (undefined2)(int)ROUND((float10)DAT_009b2d78 * fVar8);
    }
  }
  else {
    uStack_8 = 0;
  }
  *param_1 = uStack_14;
  param_1[1] = uStack_10;
  param_1[2] = uStack_c;
  param_1[3] = CONCAT13(uStack_5,CONCAT12(uStack_6,uStack_8));
  *(undefined2 *)(param_1 + 4) = uStack_4;
  *(undefined1 *)((int)param_1 + 0x12) = uStack_2;
  return;
}


// ==== FUN_004f09f0 @ 0x004f09f0 ====

undefined4 FUN_004f09f0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar1 + 0x74) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x74) + 0x14))();
  }
  iVar1 = (**(code **)(*piVar2 + 8))();
  if (*(char *)(iVar1 + 4) != '\a') {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar1 + 0x74) == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x74) + 0x14))();
    }
    iVar1 = (**(code **)(*piVar2 + 8))();
    if (*(char *)(iVar1 + 4) != '\b') {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_004f0a50 @ 0x004f0a50 ====

undefined4 FUN_004f0a50(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_a4 [40];
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x18) + 0x14))();
  iVar1 = (**(code **)(*piVar2 + 8))();
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(*(undefined2 *)(iVar1 + param_1 * 2));
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 4))();
  puVar4 = auStack_a4 + -2;
  for (iVar1 = 0x27; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar4 = puVar4 + 1;
  }
  return auStack_a4[3];
}


// ==== FUN_004f0ac0 @ 0x004f0ac0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_004f0ac0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    cVar1 = (**(code **)(_DAT_00000000 + 0x20))(param_1);
    return cVar1 != '\0';
  }
  piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  cVar1 = (**(code **)(*piVar3 + 0x20))(param_1);
  return cVar1 != '\0';
}


// ==== FUN_004f0b10 @ 0x004f0b10 ====

bool FUN_004f0b10(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  piVar3 = DAT_00b5a6ac;
  iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar4 + 0x74) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x74) + 0x14))();
  }
  iVar4 = (**(code **)(*piVar5 + 8))();
  uVar1 = *(undefined1 *)(iVar4 + 4);
  iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x18) + 0x14))();
  iVar4 = (**(code **)(*piVar5 + 8))();
  uVar2 = *(undefined1 *)(iVar4 + 0x2a);
  uVar6 = (**(code **)(*piVar3 + 0x20))();
  iVar4 = FUN_004f0310(uVar2,uVar1,uVar6);
  return iVar4 == 0;
}


// ==== FUN_004f0b90 @ 0x004f0b90 ====

bool FUN_004f0b90(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined1 local_14 [20];
  
  cVar1 = FUN_004f0590();
  if (cVar1 != '\0') {
    return false;
  }
  FUN_004f07a0(local_14,in_ECX + 4);
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  cVar1 = (**(code **)(*piVar3 + 0x20))(local_14);
  return cVar1 != '\0';
}


// ==== FUN_004f0bf0 @ 0x004f0bf0 ====

float10 FUN_004f0bf0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  float fVar5;
  
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  iVar2 = **(int **)(iVar2 + 0x50);
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar4 = (int *)(**(code **)(iVar2 + 0x14))(uVar3);
  iVar2 = (**(code **)(*piVar4 + 8))();
  fVar5 = (float)*(byte *)(iVar2 + 0xa0);
  cVar1 = FUN_004f0b10();
  if (cVar1 == '\0') {
    fVar5 = fVar5 * DAT_0099d0f8;
  }
  return (float10)fVar5 + (float10)*(float *)(in_ECX + 0x10);
}


// ==== FUN_004f0c70 @ 0x004f0c70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f0c70(undefined4 *param_1)

{
  float fVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  float fVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  void *pvVar10;
  int *piVar11;
  undefined4 *puVar12;
  int in_ECX;
  float10 fVar13;
  undefined4 uStack_48;
  undefined4 auStack_40 [2];
  undefined1 auStack_38 [8];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  float fStack_4;
  
  piVar11 = DAT_00b5a6ac;
  iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar6 + 0x74) == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)(**(code **)(**(int **)(iVar6 + 0x74) + 0x14))();
  }
  iVar6 = (**(code **)(*piVar7 + 8))();
  uVar2 = *(undefined1 *)(iVar6 + 4);
  iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar7 = (int *)(**(code **)(**(int **)(iVar6 + 0x18) + 0x14))();
  iVar6 = (**(code **)(*piVar7 + 8))();
  uVar3 = *(undefined1 *)(iVar6 + 0x2a);
  uVar8 = (**(code **)(*piVar11 + 0x20))();
  auStack_40[0] = FUN_004f0310(uVar3,uVar2,uVar8);
  iVar9 = FUN_004f05f0(auStack_40[0]);
  fVar4 = *(float *)(iVar9 + 0x114);
  fVar13 = (float10)(**(code **)(*DAT_00b5ad1c + 0x18))();
  iVar6 = (int)ROUND(fVar13 * (float10)fVar4);
  FUN_004f0680(auStack_38,param_1);
  fVar4 = (float)iVar6;
  if (iVar6 < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  fVar1 = *(float *)(iVar9 + 0x11c);
  pvVar10 = operator_new(0x28);
  if (pvVar10 == (void *)0x0) {
    uStack_48 = 0;
  }
  else {
    uStack_48 = FUN_005083b0();
  }
  piVar11 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar12 = (undefined4 *)(**(code **)(*piVar11 + 0x28))();
  uStack_30 = *puVar12;
  uStack_2c = puVar12[1];
  fVar13 = (float10)FUN_0040d5f0(auStack_38);
  fStack_28 = (float)fVar13;
  uStack_c = 0;
  uStack_b = 0;
  uStack_a = 0;
  uStack_18 = 0;
  iStack_1c = 0;
  uStack_24 = 0;
  iStack_20 = 0;
  uStack_24 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iStack_20 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iStack_20 = iStack_20 + iVar6;
  iStack_1c = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iStack_1c = iStack_1c + (int)ROUND(fVar4 * fVar1);
  uStack_18 = *(undefined4 *)(in_ECX + 0xc);
  uStack_c = *(undefined1 *)(in_ECX + 0x14);
  uStack_9 = *(undefined1 *)(iVar9 + 0x118);
  uStack_8 = *(undefined1 *)(iVar9 + 0x119);
  uStack_b = uStack_c;
  iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar6 + 0x74) == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = (int *)(**(code **)(**(int **)(iVar6 + 0x74) + 0x14))();
  }
  iVar6 = (**(code **)(*piVar11 + 8))();
  uStack_7 = *(undefined1 *)(iVar6 + 4);
  uStack_14 = *param_1;
  uStack_10 = param_1[1];
  uStack_6 = (undefined1)auStack_40[0];
  iVar6 = FUN_004ef0e0(auStack_40);
  uStack_5 = *(undefined1 *)(iVar6 + 4);
  fVar13 = (float10)FUN_004f0bf0();
  fStack_4 = (float)(fVar13 * (float10)DAT_009b2dc0);
  cVar5 = FUN_004f09f0();
  uStack_a = cVar5 == '\0';
  FUN_00508260(&uStack_24);
  (**(code **)(*DAT_00b5a97c + 0x28))(uStack_48);
  iVar6 = *DAT_00b5a97c;
  uVar8 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar6 + 0x2c))(uVar8);
  return;
}


// ==== FUN_004f0f00 @ 0x004f0f00 ====

void FUN_004f0f00(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  undefined1 auStack_2e [14];
  undefined1 auStack_20 [32];
  
  cVar1 = FUN_004f0590();
  if (cVar1 != '\0') {
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a980 + 0x20))(0);
  uVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar4 + 0x74) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x74) + 0x14))();
  }
  iVar4 = (**(code **)(*piVar5 + 8))();
  if (*(char *)(iVar4 + 4) != '\a') {
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar4 + 0x74) == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x74) + 0x14))();
    }
    iVar4 = (**(code **)(*piVar5 + 8))();
    if (*(char *)(iVar4 + 4) != '\b') goto LAB_004f0fa6;
  }
  cVar1 = FUN_00826020(uVar3);
  if (cVar1 == '\0') {
    FUN_004dd240(0x16,0,uVar2,0,0);
    return;
  }
LAB_004f0fa6:
  FUN_004f07a0(auStack_2e + -6,in_ECX + 4);
  cVar1 = FUN_004f0ac0(auStack_2e + -6);
  if (cVar1 != '\0') {
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar4 == 0) {
      FUN_00401830(s___Model2_GameUser_Command_Direct_009b2e78);
      FUN_00796d50(auStack_20);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    if ((*(int **)(iVar4 + 0x4c) == (int *)0x0) ||
       (piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))(), piVar5 == (int *)0x0)) {
      FUN_00401830(s___Model2_GameUser_Command_Direct_009b2ed8);
      FUN_00796d50(auStack_20);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    (**(code **)(*piVar5 + 0x24))(auStack_2e + -6);
    FUN_004f0460(auStack_2e + -10);
    FUN_004f0750(auStack_2e + -10);
    FUN_004f0c70(in_ECX + 4);
  }
  return;
}


// ==== FUN_004f1090 @ 0x004f1090 ====

undefined1 FUN_004f1090(void)

{
  return 1;
}


// ==== FUN_004f10a0 @ 0x004f10a0 ====

void FUN_004f10a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2fa4;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004f10f0 @ 0x004f10f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f10f0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_2c [16];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 local_8;
  undefined1 local_4;
  
  local_4 = *(undefined1 *)(in_ECX + 4);
  local_8 = 0;
  uStack_c = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
  uStack_1c = *puVar2;
  uStack_18 = puVar2[1];
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x2c))();
  uStack_14 = *puVar2;
  uStack_10 = puVar2[1];
  FUN_00508010(&uStack_1c,auStack_2c);
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    (**(code **)(_DAT_00000000 + 0x20))(auStack_2c);
    return;
  }
  piVar1 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  (**(code **)(*piVar1 + 0x20))(auStack_2c);
  return;
}


// ==== FUN_004f11a0 @ 0x004f11a0 ====

void FUN_004f11a0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 auStack_38 [28];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined1 local_4;
  
  cVar1 = FUN_004f10f0();
  if (cVar1 != '\0') {
    local_4 = *(undefined1 *)(in_ECX + 4);
    piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x28))();
    uStack_1c = *puVar3;
    uStack_18 = puVar3[1];
    piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x2c))();
    uStack_14 = *puVar3;
    uStack_10 = puVar3[1];
    uStack_c = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_8 = 0;
    FUN_00508010(&uStack_1c,auStack_38);
    FUN_00508450(auStack_38);
    FUN_005083e0(auStack_38);
  }
  return;
}


// ==== FUN_004f1270 @ 0x004f1270 ====

undefined1 FUN_004f1270(void)

{
  return 0;
}


// ==== FUN_004f1280 @ 0x004f1280 ====

undefined1 FUN_004f1280(void)

{
  return 1;
}


// ==== FUN_004f1290 @ 0x004f1290 ====

void FUN_004f1290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2fd8;
  return;
}


// ==== FUN_004f12a0 @ 0x004f12a0 ====

void FUN_004f12a0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  float10 fVar6;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
    uStack_38 = *puVar2;
    uStack_34 = puVar2[1];
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x2c))();
    uStack_30 = *puVar2;
    uStack_2c = puVar2[1];
    uStack_28 = uStack_38;
    uStack_24 = uStack_34;
    fVar6 = (float10)FUN_0040d5f0(&uStack_30);
    fStack_20 = (float)fVar6;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00797a50(&uStack_1c,0,0xd);
    uStack_11 = 0x1f;
    uStack_12 = 0;
    uStack_1c = uVar3;
    puVar2 = (undefined4 *)FUN_004ef0e0(&uStack_38);
    uStack_18 = *puVar2;
    uStack_14 = *(undefined2 *)(puVar2 + 1);
    uStack_10 = 0;
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar1 + 0x24))(&uStack_1c);
    FUN_00508450(&fStack_20);
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar5 = operator_new(0x400);
    *(undefined4 *)((int)pvVar5 + 8) = uVar3;
    *(undefined4 *)((int)pvVar5 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar5 + 6) = 0x30;
    iVar4 = FUN_004244d0();
    uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
    *(undefined4 *)(iVar4 + 0x10) = uVar3;
    FUN_00403e60(iVar4 + 0x14,&fStack_20,0xd);
    FUN_004d8570(iVar4);
  }
  return;
}


// ==== FUN_004f1410 @ 0x004f1410 ====

undefined1 FUN_004f1410(void)

{
  return 1;
}


// ==== FUN_004f1440 @ 0x004f1440 ====

void FUN_004f1440(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b300c;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004f1460 @ 0x004f1460 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004f1460(void)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int in_ECX;
  float fVar8;
  undefined1 auStack_6 [6];
  
  piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  piVar4 = (int *)(**(code **)(*piVar3 + 0x14))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x24))();
  cVar2 = (**(code **)(*piVar4 + 0x24))(auStack_6 + -6);
  if (cVar2 == '\x01') {
    pfVar5 = (float *)(**(code **)(*piVar3 + 0x28))();
    piVar3 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    pfVar6 = (float *)(**(code **)(*piVar3 + 0x28))();
    fVar8 = SQRT((pfVar6[1] - pfVar5[1]) * (pfVar6[1] - pfVar5[1]) +
                 (*pfVar6 - *pfVar5) * (*pfVar6 - *pfVar5));
    iVar7 = (**(code **)(*DAT_00b5adb4 + 4))();
    fVar1 = (float)*(int *)(iVar7 + 0x40);
    if (*(int *)(iVar7 + 0x40) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    if (fVar1 < fVar8) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_004f1540 @ 0x004f1540 ====

undefined4 FUN_004f1540(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 4) {
      cVar1 = FUN_004f1460();
      if (cVar1 != '\0') {
        piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
        pfVar4 = (float *)(**(code **)(*piVar2 + 0x28))();
        piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
        pfVar5 = (float *)(**(code **)(*piVar2 + 0x28))();
        if (SQRT((pfVar5[1] - pfVar4[1]) * (pfVar5[1] - pfVar4[1]) +
                 (*pfVar5 - *pfVar4) * (*pfVar5 - *pfVar4)) <= DAT_009b0300) {
          return 1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_004f1610 @ 0x004f1610 ====

void FUN_004f1610(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined1 auStack_1e [2];
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  piVar6 = DAT_00b5a6ac;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x74) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x74) + 0x14))();
  }
  iVar3 = (**(code **)(*piVar4 + 8))();
  uVar1 = *(undefined1 *)(iVar3 + 4);
  uVar5 = (**(code **)(*piVar6 + 0x20))();
  FUN_00797a50(&uStack_18,0,0xc);
  uStack_d = 1;
  uStack_18 = uVar5;
  uStack_e = uVar1;
  piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x28))();
  uStack_c = *puVar7;
  uStack_8 = puVar7[1];
  piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  uVar5 = (**(code **)(*piVar6 + 0x2c))();
  fVar8 = (float10)FUN_0040d5f0(uVar5);
  fStack_4 = (float)fVar8;
  puVar7 = (undefined4 *)FUN_004ef0e0(auStack_1e);
  uStack_14 = *puVar7;
  uStack_10 = *(undefined2 *)(puVar7 + 1);
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  cVar2 = (**(code **)(*piVar6 + 0x20))(&uStack_18);
  if (cVar2 != '\0') {
    puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      *puVar7 = &PTR_FUN_009b2d88;
    }
    uVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    puVar7[1] = uVar5;
    FUN_00403e60(puVar7 + 2,auStack_1c,0x19);
    FUN_00797a20(puVar7);
  }
  return;
}


// ==== FUN_004f1740 @ 0x004f1740 ====

void FUN_004f1740(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 4) {
      cVar1 = FUN_004f1540();
      if (cVar1 == '\0') {
        iVar3 = *DAT_00b5acdc;
        uVar4 = FUN_004e5ea0(*(undefined4 *)(in_ECX + 4));
        (**(code **)(iVar3 + 8))(uVar4);
        iVar3 = *DAT_00b5acdc;
        uVar4 = FUN_004e5cb0(*(undefined4 *)(in_ECX + 4));
        (**(code **)(iVar3 + 8))(uVar4);
        return;
      }
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar5 = operator_new(0x400);
      *(undefined4 *)((int)pvVar5 + 8) = uVar4;
      *(undefined4 *)((int)pvVar5 + 0xc) = 0x5050001;
      *(undefined2 *)((int)pvVar5 + 6) = 0x14;
      iVar3 = FUN_004244d0();
      *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(in_ECX + 4);
      FUN_004d8570(iVar3);
      FUN_004f1610();
      return;
    }
  }
  iVar3 = *DAT_00b5acdc;
  uVar4 = FUN_004e5e10();
  (**(code **)(iVar3 + 8))(uVar4);
  return;
}


// ==== FUN_004f1810 @ 0x004f1810 ====

undefined1 FUN_004f1810(void)

{
  return 0;
}


// ==== FUN_004f1820 @ 0x004f1820 ====

undefined1 FUN_004f1820(void)

{
  return 1;
}


// ==== FUN_004f1830 @ 0x004f1830 ====

void FUN_004f1830(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int in_ECX;
  float10 fVar6;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  undefined1 auStack_20 [32];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
    uStack_54 = *puVar2;
    uStack_50 = puVar2[1];
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x2c))();
    uStack_4c = *puVar2;
    uStack_48 = puVar2[1];
    uStack_44 = uStack_54;
    uStack_40 = uStack_50;
    fVar6 = (float10)FUN_0040d5f0(&uStack_4c);
    fStack_3c = (float)fVar6;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00797a50(&uStack_38,0,0xd);
    uStack_2d = 0x11;
    uStack_2e = 0;
    uStack_38 = uVar3;
    puVar2 = (undefined4 *)FUN_004ef0e0(&uStack_54);
    uStack_34 = *puVar2;
    uStack_30 = *(undefined2 *)(puVar2 + 1);
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar1 + 0x24))(&uStack_38);
    FUN_00508450(&fStack_3c);
    if (*(uint *)(in_ECX + 0x1c) < 0x10) {
      iVar4 = in_ECX + 8;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8);
    }
    FUN_0047aa30(auStack_20,&DAT_009b302c,iVar4);
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar5 = operator_new(0x400);
    *(undefined4 *)((int)pvVar5 + 8) = uVar3;
    *(undefined4 *)((int)pvVar5 + 0xc) = 0x50d0000;
    *(undefined2 *)((int)pvVar5 + 6) = 0x30;
    iVar4 = FUN_004244d0();
    uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
    *(undefined4 *)(iVar4 + 0x10) = uVar3;
    FUN_00403e60(iVar4 + 0x14,&fStack_3c,0xd);
    FUN_004f1a30(auStack_20);
    FUN_004d8570(iVar4);
  }
  return;
}


// ==== FUN_004f19b0 @ 0x004f19b0 ====

void FUN_004f19b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3044;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009b2c08;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004f1a00 @ 0x004f1a00 ====

void FUN_004f1a00(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3044;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  return;
}


// ==== FUN_004f1a30 @ 0x004f1a30 ====

void FUN_004f1a30(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    FUN_0047aa00(param_1);
    uVar1 = 0;
    do {
      if (*(char *)(uVar1 + in_ECX + 0x30) == '\0') goto LAB_004f1a60;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x19);
    uVar1 = 0;
LAB_004f1a60:
    *(short *)(in_ECX + 6) = (short)uVar1 + 0x31;
  }
  return;
}


// ==== FUN_004f1a70 @ 0x004f1a70 ====

void FUN_004f1a70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3044;
  if (0xf < (uint)in_ECX[7]) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = &PTR_FUN_009b2c08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f1ad0 @ 0x004f1ad0 ====

undefined1 FUN_004f1ad0(void)

{
  return 0;
}


// ==== FUN_004f1ae0 @ 0x004f1ae0 ====

undefined1 FUN_004f1ae0(void)

{
  return 1;
}


// ==== FUN_004f1af0 @ 0x004f1af0 ====

void FUN_004f1af0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3064;
  return;
}


// ==== FUN_004f1b00 @ 0x004f1b00 ====

void FUN_004f1b00(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
    uStack_38 = *puVar2;
    uStack_34 = puVar2[1];
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x2c))();
    uStack_30 = *puVar2;
    uStack_2c = puVar2[1];
    uStack_28 = uStack_38;
    uStack_24 = uStack_34;
    fVar5 = (float10)FUN_0040d5f0(&uStack_30);
    fStack_20 = (float)fVar5;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00797a50(&uStack_1c,0,0xc);
    uStack_11 = 0x12;
    uStack_12 = 0;
    uStack_1c = uVar3;
    puVar2 = (undefined4 *)FUN_004ef0e0(&uStack_38);
    uStack_18 = *puVar2;
    uStack_14 = *(undefined2 *)(puVar2 + 1);
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar1 + 0x24))(&uStack_1c);
    FUN_005083e0(&fStack_20);
    FUN_00508450(&fStack_20);
  }
  return;
}


// ==== FUN_004f1c20 @ 0x004f1c20 ====

undefined1 FUN_004f1c20(void)

{
  return 1;
}


// ==== FUN_004f1c30 @ 0x004f1c30 ====

void FUN_004f1c30(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3098;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004f1c80 @ 0x004f1c80 ====

undefined4 FUN_004f1c80(void)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 0) {
      piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
      pfVar3 = (float *)(**(code **)(*piVar1 + 0x28))();
      piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      pfVar4 = (float *)(**(code **)(*piVar1 + 0x28))();
      if (SQRT((pfVar4[1] - pfVar3[1]) * (pfVar4[1] - pfVar3[1]) +
               (*pfVar4 - *pfVar3) * (*pfVar4 - *pfVar3)) <= DAT_009b0300) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_004f1d40 @ 0x004f1d40 ====

void FUN_004f1d40(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined1 auStack_1e [2];
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  piVar6 = DAT_00b5a6ac;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x74) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x74) + 0x14))();
  }
  iVar3 = (**(code **)(*piVar4 + 8))();
  uVar1 = *(undefined1 *)(iVar3 + 4);
  uVar5 = (**(code **)(*piVar6 + 0x20))();
  FUN_00797a50(&uStack_18,0,0xc);
  uStack_d = 1;
  uStack_18 = uVar5;
  uStack_e = uVar1;
  piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x28))();
  uStack_c = *puVar7;
  uStack_8 = puVar7[1];
  piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  uVar5 = (**(code **)(*piVar6 + 0x2c))();
  fVar8 = (float10)FUN_0040d5f0(uVar5);
  fStack_4 = (float)fVar8;
  puVar7 = (undefined4 *)FUN_004ef0e0(auStack_1e);
  uStack_14 = *puVar7;
  uStack_10 = *(undefined2 *)(puVar7 + 1);
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  cVar2 = (**(code **)(*piVar6 + 0x20))(&uStack_18);
  if (cVar2 != '\0') {
    puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      *puVar7 = &PTR_FUN_009b2d88;
    }
    uVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    puVar7[1] = uVar5;
    FUN_00403e60(puVar7 + 2,auStack_1c,0x19);
    FUN_00797a20(puVar7);
  }
  return;
}


// ==== FUN_004f1e70 @ 0x004f1e70 ====

void FUN_004f1e70(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 0) {
      cVar1 = FUN_004f1c80();
      if (cVar1 == '\0') {
        iVar3 = *DAT_00b5acdc;
        uVar4 = FUN_004e5f00(*(undefined4 *)(in_ECX + 4));
        (**(code **)(iVar3 + 8))(uVar4);
        iVar3 = *DAT_00b5acdc;
        uVar4 = FUN_004e5cb0(*(undefined4 *)(in_ECX + 4));
        (**(code **)(iVar3 + 8))(uVar4);
        return;
      }
      (**(code **)(*DAT_00b5adc4 + 0xc))(*(undefined4 *)(in_ECX + 4));
      FUN_004f1d40();
      return;
    }
  }
  iVar3 = *DAT_00b5acdc;
  uVar4 = FUN_004e5e10();
  (**(code **)(iVar3 + 8))(uVar4);
  return;
}


// ==== FUN_004f1f20 @ 0x004f1f20 ====

undefined1 FUN_004f1f20(void)

{
  return 1;
}


// ==== FUN_004f1f50 @ 0x004f1f50 ====

void FUN_004f1f50(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b30b8;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004f1f70 @ 0x004f1f70 ====

void FUN_004f1f70(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *DAT_00b5ad98;
  uVar2 = FUN_006ea720(*(undefined4 *)(in_ECX + 4));
  (**(code **)(iVar1 + 4))(uVar2);
  return;
}


// ==== FUN_004f1f90 @ 0x004f1f90 ====

bool FUN_004f1f90(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 0) {
      piVar1 = (int *)(**(code **)(*DAT_00b5ad98 + 8))();
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 0xc))();
        return iVar2 == 1;
      }
    }
  }
  return false;
}


// ==== FUN_004f1fd0 @ 0x004f1fd0 ====

undefined4 FUN_004f1fd0(void)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int in_ECX;
  float fVar5;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if ((((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 == 0)) &&
      (piVar1 = (int *)(**(code **)(*DAT_00b5ad98 + 8))(), piVar1 != (int *)0x0)) &&
     (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 == 1)) {
    piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
    pfVar3 = (float *)(**(code **)(*piVar1 + 0x28))();
    piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    pfVar4 = (float *)(**(code **)(*piVar1 + 0x28))();
    fVar5 = SQRT((pfVar4[1] - pfVar3[1]) * (pfVar4[1] - pfVar3[1]) +
                 (*pfVar4 - *pfVar3) * (*pfVar4 - *pfVar3));
    if (fVar5 <= DAT_0099cdc8) {
      fVar5 = 0.0 - fVar5;
    }
    if (fVar5 <= DAT_009b30d4) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004f20e0 @ 0x004f20e0 ====

void FUN_004f20e0(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined1 auStack_1e [2];
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  piVar6 = DAT_00b5a6ac;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x74) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x74) + 0x14))();
  }
  iVar3 = (**(code **)(*piVar4 + 8))();
  uVar1 = *(undefined1 *)(iVar3 + 4);
  uVar5 = (**(code **)(*piVar6 + 0x20))();
  FUN_00797a50(&uStack_18,0,0xc);
  uStack_d = 1;
  uStack_18 = uVar5;
  uStack_e = uVar1;
  piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x28))();
  uStack_c = *puVar7;
  uStack_8 = puVar7[1];
  piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  uVar5 = (**(code **)(*piVar6 + 0x2c))();
  fVar8 = (float10)FUN_0040d5f0(uVar5);
  fStack_4 = (float)fVar8;
  puVar7 = (undefined4 *)FUN_004ef0e0(auStack_1e);
  uStack_14 = *puVar7;
  uStack_10 = *(undefined2 *)(puVar7 + 1);
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  cVar2 = (**(code **)(*piVar6 + 0x20))(&uStack_18);
  if (cVar2 != '\0') {
    puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      *puVar7 = &PTR_FUN_009b2d88;
    }
    uVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    puVar7[1] = uVar5;
    FUN_00403e60(puVar7 + 2,auStack_1c,0x19);
    FUN_00797a20(puVar7);
  }
  return;
}


// ==== FUN_004f2210 @ 0x004f2210 ====

void FUN_004f2210(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  uint uVar5;
  undefined1 auStack_1a [26];
  
  iVar3 = *DAT_00b5add0;
  uVar2 = (**(code **)(*DAT_00b5ac1c + 0x38))();
  cVar1 = (**(code **)(iVar3 + 0x44))(uVar2);
  if (cVar1 == '\0') {
    iVar3 = (**(code **)(*DAT_00b5ad88 + 4))();
    if (iVar3 == 0) {
      cVar1 = FUN_004f1f90();
      if (cVar1 == '\0') {
        iVar3 = *DAT_00b5acdc;
        uVar2 = FUN_004e5e10();
        (**(code **)(iVar3 + 8))(uVar2);
        return;
      }
      cVar1 = FUN_004f1fd0();
      if (cVar1 == '\0') {
        iVar3 = *DAT_00b5acdc;
        uVar2 = FUN_004e5f20(*(undefined4 *)(in_ECX + 4));
        (**(code **)(iVar3 + 8))(uVar2);
        iVar3 = *DAT_00b5acdc;
        uVar2 = FUN_004e5cb0(*(undefined4 *)(in_ECX + 4));
        (**(code **)(iVar3 + 8))(uVar2);
        return;
      }
      piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
      iVar3 = (**(code **)(*piVar4 + 0xc))();
      if (iVar3 == 0) {
        FUN_004f1f70();
      }
      FUN_004f20e0();
    }
    else {
      uVar5 = 0x7d50012;
      uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
      FUN_00401660(uVar2,0,0xffffffff);
      piVar4 = DAT_00b5ad0c;
      FUN_00401660(auStack_1a + -0xe,0,0xffffffff);
      (**(code **)(*piVar4 + 0x28))(2);
      if (0xf < uVar5) {
        _free((void *)0x4f2279);
        return;
      }
    }
  }
  return;
}


// ==== FUN_004f2370 @ 0x004f2370 ====

undefined1 FUN_004f2370(void)

{
  return 1;
}


// ==== FUN_004f2380 @ 0x004f2380 ====

undefined1 FUN_004f2380(void)

{
  return 1;
}


// ==== FUN_004f2390 @ 0x004f2390 ====

void FUN_004f2390(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b30dc;
  in_ECX[1] = *param_1;
  in_ECX[2] = param_1[1];
  return;
}


// ==== FUN_004f23b0 @ 0x004f23b0 ====

void FUN_004f23b0(void)

{
  int *piVar1;
  float *pfVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  float *pfStack_40;
  float fStack_30;
  float fStack_2c;
  undefined1 auStack_28 [4];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  
  pfStack_40 = (float *)0x4f23c1;
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  if (piVar1 != (int *)0x0) {
    pfStack_40 = (float *)0x4f23d0;
    pfVar2 = (float *)(**(code **)(*piVar1 + 0x28))();
    fStack_30 = *(float *)(in_ECX + 4) - *pfVar2;
    pfStack_40 = &fStack_30;
    fStack_2c = *(float *)(in_ECX + 8) - pfVar2[1];
    thunk_FUN_0079de77(&uStack_24);
    fVar6 = (float10)FUN_0040d5f0(&fStack_2c);
    fStack_30 = (float)fVar6;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00797a50(&uStack_24,0,0xc);
    uStack_19 = 0x16;
    uStack_1a = 0x17;
    uStack_24 = uVar3;
    puVar4 = (undefined4 *)FUN_004ef0e0(&pfStack_40);
    uStack_20 = *puVar4;
    uStack_1c = *(undefined2 *)(puVar4 + 1);
    iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar1 + 0x24))(&uStack_24);
    FUN_005083e0(auStack_28);
    FUN_00508450(auStack_28);
  }
  return;
}


// ==== FUN_004f24f0 @ 0x004f24f0 ====

undefined1 FUN_004f24f0(void)

{
  return 1;
}


// ==== FUN_004f2500 @ 0x004f2500 ====

undefined1 FUN_004f2500(void)

{
  return 1;
}


// ==== FUN_004f2510 @ 0x004f2510 ====

void FUN_004f2510(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3110;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004f2530 @ 0x004f2530 ====

void FUN_004f2530(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  if (piVar2 != (int *)0x0) {
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x28))();
    uStack_38 = *puVar3;
    uStack_34 = puVar3[1];
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x2c))();
    uStack_30 = *puVar3;
    uStack_2c = puVar3[1];
    uStack_28 = uStack_38;
    uStack_24 = uStack_34;
    fVar6 = (float10)FUN_0040d5f0(&uStack_30);
    fStack_20 = (float)fVar6;
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00797a50(&uStack_1c,0,0xd);
    uStack_11 = 0x15;
    uStack_12 = 0x17;
    uStack_1c = uVar4;
    puVar3 = (undefined4 *)FUN_004ef0e0(&uStack_38);
    uStack_18 = *puVar3;
    uStack_10 = *(undefined1 *)(in_ECX + 4);
    uStack_14 = *(undefined2 *)(puVar3 + 1);
    iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar5 + 0x4c) != (int *)0x0) {
      piVar2 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
      if (piVar2 != (int *)0x0) {
        cVar1 = (**(code **)(*piVar2 + 0x20))(&uStack_1c);
        if (cVar1 != '\0') {
          iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
          if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
            piVar2 = (int *)0x0;
          }
          else {
            piVar2 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
          }
          (**(code **)(*piVar2 + 0x24))(&fStack_20);
          FUN_00508450(&uStack_24);
        }
      }
    }
  }
  return;
}


// ==== FUN_004f2680 @ 0x004f2680 ====

undefined1 FUN_004f2680(void)

{
  return 1;
}


// ==== FUN_004f2690 @ 0x004f2690 ====

undefined1 FUN_004f2690(void)

{
  return 1;
}


// ==== FUN_004f26a0 @ 0x004f26a0 ====

void FUN_004f26a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3144;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004f26c0 @ 0x004f26c0 ====

int FUN_004f26c0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar3 = DAT_00b5a780;
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  piVar3 = (int *)(**(code **)(*piVar3 + 8))(iVar2 + 0x14);
  if (piVar3 != (int *)0x0) {
    auStack_10[0] = 0x17;
    uStack_c = 0x17;
    iVar2 = (**(code **)(*piVar3 + 0xc))(auStack_10);
    if (iVar2 != 0) {
      return (int)ROUND(*(float *)(iVar2 + 0x114) * DAT_009b012c);
    }
  }
  return 1000;
}


// ==== FUN_004f2750 @ 0x004f2750 ====

void FUN_004f2750(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  undefined1 uStack_11;
  int iStack_10;
  undefined1 uStack_c;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
    uStack_38 = *puVar2;
    uStack_34 = puVar2[1];
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x2c))();
    uStack_30 = *puVar2;
    uStack_2c = puVar2[1];
    uStack_28 = uStack_38;
    uStack_24 = uStack_34;
    fVar4 = (float10)FUN_0040d5f0(&uStack_30);
    fStack_20 = (float)fVar4;
    iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00797a50(&iStack_1c,0,0x11);
    uStack_11 = 0x17;
    uStack_12 = 0x17;
    iStack_1c = iVar3;
    puVar2 = (undefined4 *)FUN_004ef0e0(&uStack_38);
    uStack_18 = *puVar2;
    uStack_14 = *(undefined2 *)(puVar2 + 1);
    uStack_c = (undefined1)*(undefined4 *)(in_ECX + 4);
    iStack_10 = FUN_004f26c0(*(undefined4 *)(in_ECX + 4));
    iStack_10 = iStack_10 + iVar3;
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar1 + 0x24))(&iStack_1c);
    FUN_005083e0(&fStack_20);
    FUN_004de2a0(1,0x3e9);
    FUN_00508450(&fStack_20);
  }
  return;
}


// ==== FUN_004f2890 @ 0x004f2890 ====

void FUN_004f2890(undefined4 param_1,undefined4 param_2)

{
  FUN_004de2a0(param_1,param_2);
  return;
}


// ==== FUN_004f28c0 @ 0x004f28c0 ====

undefined1 FUN_004f28c0(void)

{
  return 1;
}


// ==== FUN_004f28d0 @ 0x004f28d0 ====

undefined1 FUN_004f28d0(void)

{
  return 1;
}


// ==== FUN_004f28e0 @ 0x004f28e0 ====

void FUN_004f28e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3178;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004f2900 @ 0x004f2900 ====

void FUN_004f2900(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  float10 fVar5;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 uStack_10;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  if (piVar1 != (int *)0x0) {
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
    uStack_38 = *puVar2;
    uStack_34 = puVar2[1];
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x2c))();
    uStack_30 = *puVar2;
    uStack_2c = puVar2[1];
    uStack_28 = uStack_38;
    uStack_24 = uStack_34;
    fVar5 = (float10)FUN_0040d5f0(&uStack_30);
    fStack_20 = (float)fVar5;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00797a50(&uStack_1c,0,0xd);
    uStack_11 = 0x1e;
    uStack_12 = 0;
    uStack_1c = uVar3;
    puVar2 = (undefined4 *)FUN_004ef0e0(&uStack_38);
    uStack_18 = *puVar2;
    uStack_10 = *(undefined1 *)(in_ECX + 4);
    uStack_14 = *(undefined2 *)(puVar2 + 1);
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar1 + 0x24))(&uStack_1c);
    FUN_005083e0(&fStack_20);
    FUN_00508450(&fStack_20);
  }
  return;
}


// ==== FUN_004f2a20 @ 0x004f2a20 ====

undefined1 FUN_004f2a20(void)

{
  return 1;
}


// ==== FUN_004f2a60 @ 0x004f2a60 ====

undefined4 FUN_004f2a60(void)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 0) {
      piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
      pfVar3 = (float *)(**(code **)(*piVar1 + 0x28))();
      piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      pfVar4 = (float *)(**(code **)(*piVar1 + 0x28))();
      if (SQRT((pfVar4[1] - pfVar3[1]) * (pfVar4[1] - pfVar3[1]) +
               (*pfVar4 - *pfVar3) * (*pfVar4 - *pfVar3)) <= DAT_0099d0f8) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_004f2b10 @ 0x004f2b10 ====

void FUN_004f2b10(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  char acStack_19 [25];
  
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0x50e0000;
  *(undefined2 *)((int)pvVar4 + 6) = 0x34;
  iVar5 = FUN_004244d0();
  uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
  *(undefined4 *)(iVar5 + 0x10) = uVar3;
  *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    iVar8 = in_ECX + 0xc;
  }
  else {
    iVar8 = *(int *)(in_ECX + 0xc);
  }
  FUN_0047aa30(acStack_19,&DAT_009b3198,iVar8);
  pcVar1 = (char *)(iVar5 + 0x18);
  uVar7 = 0;
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)(acStack_19 + -(int)pcVar1)];
    *pcVar6 = cVar2;
    if (cVar2 == '\0') goto LAB_004f2ba7;
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 < 0x19);
  *pcVar1 = '\0';
LAB_004f2ba7:
  FUN_004d8570(iVar5);
  return;
}


// ==== FUN_004f2bd0 @ 0x004f2bd0 ====

void FUN_004f2bd0(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined1 auStack_1e [2];
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  piVar6 = DAT_00b5a6ac;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x74) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x74) + 0x14))();
  }
  iVar3 = (**(code **)(*piVar4 + 8))();
  uVar1 = *(undefined1 *)(iVar3 + 4);
  uVar5 = (**(code **)(*piVar6 + 0x20))();
  FUN_00797a50(&uStack_18,0,0xc);
  uStack_d = 1;
  uStack_18 = uVar5;
  uStack_e = uVar1;
  piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x28))();
  uStack_c = *puVar7;
  uStack_8 = puVar7[1];
  piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  uVar5 = (**(code **)(*piVar6 + 0x2c))();
  fVar8 = (float10)FUN_0040d5f0(uVar5);
  fStack_4 = (float)fVar8;
  puVar7 = (undefined4 *)FUN_004ef0e0(auStack_1e);
  uStack_14 = *puVar7;
  uStack_10 = *(undefined2 *)(puVar7 + 1);
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  cVar2 = (**(code **)(*piVar6 + 0x20))(&uStack_18);
  if (cVar2 != '\0') {
    puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      *puVar7 = &PTR_FUN_009b2d88;
    }
    uVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    puVar7[1] = uVar5;
    FUN_00403e60(puVar7 + 2,auStack_1c,0x19);
    FUN_00797a20(puVar7);
  }
  return;
}


// ==== FUN_004f2d00 @ 0x004f2d00 ====

void FUN_004f2d00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b31b0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b2c08;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004f2d40 @ 0x004f2d40 ====

void FUN_004f2d40(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined4 *in_ECX;
  uint in_stack_00000020;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b31b0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(&param_2,0,0xffffffff);
  if (in_stack_00000020 < 0x10) {
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_004f2d90 @ 0x004f2d90 ====

void FUN_004f2d90(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 0) {
      cVar1 = FUN_004f2a60();
      piVar2 = DAT_00b5acdc;
      if (cVar1 == '\0') {
        FUN_00401660(in_ECX + 8,0,0xffffffff);
        uVar4 = FUN_004e5fc0(*(undefined4 *)(in_ECX + 4));
        (**(code **)(*piVar2 + 8))(uVar4);
        iVar3 = *DAT_00b5acdc;
        uVar4 = FUN_004e5cb0(*(undefined4 *)(in_ECX + 4));
        (**(code **)(iVar3 + 8))(uVar4);
        return;
      }
      piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
      iVar3 = (**(code **)(*piVar2 + 0xc))();
      if (iVar3 == 0) {
        FUN_004f2b10();
      }
      FUN_004f2bd0();
      return;
    }
  }
  iVar3 = *DAT_00b5acdc;
  uVar4 = FUN_004e5e10();
  (**(code **)(iVar3 + 8))(uVar4);
  return;
}


// ==== FUN_004f2e60 @ 0x004f2e60 ====

void FUN_004f2e60(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x50e0000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x34;
  FUN_004244d0();
  return;
}


// ==== FUN_004f2e90 @ 0x004f2e90 ====

void FUN_004f2e90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b31b0;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_009b2c08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f2ee0 @ 0x004f2ee0 ====

void FUN_004f2ee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b31d0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f2f00 @ 0x004f2f00 ====

int FUN_004f2f00(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_004f2f10 @ 0x004f2f10 ====

int FUN_004f2f10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28)) / 0x24;
}


// ==== FUN_004f2f30 @ 0x004f2f30 ====

undefined4 FUN_004f2f30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) != 0) {
    if ((*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28)) / 0x24 != 0) {
      *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0x28);
      return *(undefined4 *)(in_ECX + 0x28);
    }
  }
  return 0;
}


// ==== FUN_004f2f60 @ 0x004f2f60 ====

uint FUN_004f2f60(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) != 0) {
    if (((*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28)) / 0x24 != 0) &&
       (*(int *)(in_ECX + 0x34) != *(int *)(in_ECX + 0x2c))) {
      *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 0x24;
      return -(uint)(*(uint *)(in_ECX + 0x34) != *(uint *)(in_ECX + 0x2c)) &
             *(uint *)(in_ECX + 0x34);
    }
  }
  return 0;
}


// ==== FUN_004f2fb0 @ 0x004f2fb0 ====

void FUN_004f2fb0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = *param_1;
  FUN_00401660(param_1 + 2,0,0xffffffff);
  return;
}


// ==== FUN_004f2fd0 @ 0x004f2fd0 ====

int FUN_004f2fd0(uint param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  uVar2 = (**(code **)(*in_ECX + 8))();
  if (uVar2 <= param_1) {
    return 0;
  }
  iVar1 = in_ECX[10];
  if ((iVar1 == 0) || ((uint)((in_ECX[0xb] - iVar1) / 0x24) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return iVar1 + param_1 * 0x24;
}


// ==== FUN_004f3020 @ 0x004f3020 ====

void FUN_004f3020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b31ec;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xd] = in_ECX[0xb];
  return;
}


// ==== FUN_004f3050 @ 0x004f3050 ====

void FUN_004f3050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b31ec;
  if (in_ECX[10] != 0) {
    FUN_006d8e10(in_ECX[10],in_ECX[0xb],in_ECX + 9);
    _free((void *)in_ECX[10]);
    return;
  }
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009b31d0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004f30c0 @ 0x004f30c0 ====

void FUN_004f30c0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_004f36d0(param_1);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0x2c);
  return;
}


// ==== FUN_004f30e0 @ 0x004f30e0 ====

int FUN_004f30e0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x24;
    iVar2 = param_3 + -0x24;
    FUN_00401660(iVar1,0,0xffffffff);
    *(undefined4 *)(param_3 + -8) = *(undefined4 *)(param_2 + -8);
    *(undefined2 *)(param_3 + -4) = *(undefined2 *)(param_2 + -4);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_004f3130 @ 0x004f3130 ====

void FUN_004f3130(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_2 + 0x20);
  }
  return;
}


// ==== FUN_004f3170 @ 0x004f3170 ====

int FUN_004f3170(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981500;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_004f3130(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004f31da @ 0x004f31da ====

void Catch_004f31da(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004f3200 @ 0x004f3200 ====

void FUN_004f3200(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_00401660(param_3,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
    *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(param_3 + 0x20);
  }
  return;
}


// ==== FUN_004f3240 @ 0x004f3240 ====

void FUN_004f3240(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981510;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004f3130(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004f32aa @ 0x004f32aa ====

void Catch_004f32aa(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x24) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004f32d0 @ 0x004f32d0 ====

void FUN_004f32d0(undefined4 param_1,undefined4 param_2)

{
  FUN_006d8e10(param_1,param_2);
  return;
}


// ==== FUN_004f32f0 @ 0x004f32f0 ====

void FUN_004f32f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004f3170(param_1,param_2,param_3);
  return;
}


// ==== FUN_004f3310 @ 0x004f3310 ====

int FUN_004f3310(int param_1,int param_2,undefined4 param_3)

{
  FUN_004f3240(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_004f3340 @ 0x004f3340 ====

void FUN_004f3340(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_64 [2];
  undefined1 auStack_62 [2];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_48;
  undefined2 local_44;
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
  puStack_c = &LAB_00981520;
  local_10 = ExceptionList;
  local_14 = local_64 + -0xc;
  local_4c = 0xf;
  local_50 = 0;
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_48 = *(undefined4 *)(param_3 + 0x1c);
  local_44 = *(undefined2 *)(param_3 + 0x20);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x24;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    if (0x71c71c7U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x71c71c7 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_0066e7e0();
        uVar4 = iVar2 + param_2;
      }
      local_24 = uVar4 * 0x24;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_18 = local_1c;
      local_18 = (void *)FUN_004f32f0(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_004f3310(local_18,param_2,local_64);
      FUN_004f32f0(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x24;
      }
      if (iVar2 != 0) {
        FUN_006d8e10(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
      *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar1) * 0x24);
      *(void **)(in_ECX + 4) = local_1c;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x24) < param_2) {
        local_28 = param_2 * 0x24;
        FUN_004f3170(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_004f3310(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,local_64
                    );
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_004f3200(param_1,*(int *)(in_ECX + 8) - local_28,local_64);
      }
      else {
        local_30 = local_2c + param_2 * -0x24;
        uVar3 = FUN_004f3170(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_004f30e0(param_1,local_30,local_2c,local_40);
        FUN_004f3200(param_1,param_2 * 0x24 + param_1,local_64);
      }
    }
  }
  if (local_4c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_60);
  return;
}


// ==== Catch@004f3513 @ 0x004f3513 ====

void Catch_004f3513(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_004f32d0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@004f35c7 @ 0x004f35c7 ====

void Catch_004f35c7(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x24;
  FUN_004f32d0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004f3660 @ 0x004f3660 ====

void FUN_004f3660(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_004f36a5;
    }
  }
  iVar1 = 0;
LAB_004f36a5:
  FUN_004f3340(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_004f36d0 @ 0x004f36d0 ====

void FUN_004f36d0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_004f3660(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004f3240(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_004f3760 @ 0x004f3760 ====

void FUN_004f3760(byte param_1)

{
  void *in_ECX;
  
  FUN_004f3050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f3780 @ 0x004f3780 ====

void FUN_004f3780(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3414;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f37b0 @ 0x004f37b0 ====

undefined1 FUN_004f37b0(void)

{
  return 0;
}


// ==== FUN_004f37d0 @ 0x004f37d0 ====

void FUN_004f37d0(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xc))(1);
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  return;
}


// ==== FUN_004f37f0 @ 0x004f37f0 ====

void FUN_004f37f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    return;
  }
  FUN_0065c980();
  return;
}


// ==== FUN_004f3800 @ 0x004f3800 ====

void FUN_004f3800(int param_1)

{
  float fVar1;
  int in_ECX;
  float10 fVar2;
  float fVar3;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + *(int *)(param_1 + 4);
  fVar1 = DAT_009b341c;
  if (*(uint *)(in_ECX + 0x40) <= *(uint *)(in_ECX + 0x3c)) {
    fVar3 = *(float *)(in_ECX + 0x48) + *(float *)(in_ECX + 0x34);
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    *(float *)(in_ECX + 0x34) = fVar3;
    if (fVar1 < fVar3) {
      *(float *)(in_ECX + 0x34) = fVar3 - fVar1;
    }
    local_c = *(undefined4 *)(in_ECX + 0x20);
    local_8 = *(float *)(in_ECX + 0x24);
    local_4 = *(undefined4 *)(in_ECX + 0x28);
    fVar2 = (float10)FUN_0040d4c0(DAT_00ae9a60 * *(float *)(in_ECX + 0x34));
    local_8 = (float)((float10)local_8 + fVar2 * (float10)*(float *)(in_ECX + 0x44));
    (**(code **)(*DAT_00b5ad14 + 0x10))(&local_c);
  }
  return;
}


// ==== FUN_004f38a0 @ 0x004f38a0 ====

void FUN_004f38a0(void)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  undefined1 auStack_44 [4];
  undefined1 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  void *pvStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  uint uStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  *in_ECX = &PTR_FUN_009b3428;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar3 = (**(code **)(*piVar2 + 4))(0,s___SceneModel_Game_LoginScene_cpp_009b32a8,0x2c);
  uVar1 = DAT_009b3420;
  in_ECX[1] = uVar3;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  uVar3 = DAT_0099d080;
  in_ECX[8] = 0;
  in_ECX[0xe] = uVar3;
  uVar3 = DAT_0099d0b4;
  in_ECX[9] = 0;
  in_ECX[0x11] = uVar3;
  uVar3 = DAT_0099d100;
  in_ECX[10] = 0;
  in_ECX[0xc] = uVar1;
  in_ECX[0x13] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 300;
  in_ECX[0x12] = uVar3;
  uStack_10 = 0xf;
  uStack_14 = 0;
  uStack_24 = 0;
  FUN_00401740(s__delaytime___addratio___addangle_009b32cc,0x21);
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  uStack_40 = 0;
  FUN_00401740(s_shakecam_009b32f0,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_44,3,auStack_28);
  if (0xf < uStack_38) {
    _free((void *)0x0);
    return;
  }
  uStack_38 = 0xf;
  uStack_3c = 0;
  if (uStack_1c < 0x10) {
    return;
  }
  _free(pvStack_30);
  return;
}


// ==== FUN_004f3a10 @ 0x004f3a10 ====

/* WARNING: Removing unreachable block (ram,0x004f3a8b) */

void FUN_004f3a10(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  *in_ECX = &PTR_FUN_009b3428;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    uStack_24 = 1;
    uStack_28 = 0x4f3a29;
    (*(code *)**(undefined4 **)in_ECX[3])();
    in_ECX[3] = 0;
  }
  uStack_24 = 0x4f3a3b;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uStack_24 = in_ECX[1];
  uStack_28 = 0;
  uStack_2c = 0x43;
  (**(code **)(*piVar1 + 8))(s___SceneModel_Game_LoginScene_cpp_009b32fc);
  uStack_28 = uStack_28 & 0xffffff00;
  FUN_00401740(s_shakecam_009b3320,8);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&uStack_2c);
  *in_ECX = &PTR_FUN_009b3414;
  return;
}


// ==== FUN_004f3ab0 @ 0x004f3ab0 ====

void FUN_004f3ab0(void)

{
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xc))(1);
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_3dcamera_zangle_0_009b3344,0x11);
  (**(code **)(*DAT_00b5a688 + 4))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  if (*(undefined4 **)(in_ECX + 0x4c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x4c))(1);
  }
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  if (*(undefined4 **)(in_ECX + 0x10) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x10))(1);
    *(undefined4 *)(in_ECX + 0x10) = 0;
  }
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_004de2a0(1,9999);
  return;
}


// ==== FUN_004f3b50 @ 0x004f3b50 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_004f3b50(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 local_10a4 [4];
  void *pvStack_10a0;
  undefined4 uStack_1090;
  uint uStack_108c;
  undefined1 auStack_1088 [4];
  void *pvStack_1084;
  undefined4 uStack_1074;
  uint uStack_1070;
  void *pvStack_1068;
  undefined4 uStack_1058;
  uint uStack_1054;
  void *pvStack_104c;
  undefined4 uStack_103c;
  uint uStack_1038;
  undefined1 auStack_1034 [4];
  void *pvStack_1030;
  undefined4 uStack_1020;
  uint uStack_101c;
  undefined1 auStack_1018 [4];
  void *pvStack_1014;
  uint uStack_1000;
  undefined4 auStack_ffc [64];
  char acStack_efa [256];
  char acStack_dfa [256];
  char acStack_cfa [256];
  char acStack_bfa [1074];
  char acStack_7c8 [1980];
  undefined4 uStack_c;
  
  uStack_c = 0x4f3b60;
  piVar2 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s__s__u_009b3368,5);
    uVar3 = FUN_00404230(auStack_1018);
    FUN_00796d50(uVar3);
    if (0xf < uStack_1000) {
      _free(pvStack_1014);
      return;
    }
  }
  else {
    puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
    puVar7 = auStack_ffc;
    for (iVar6 = 0x3fb; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    }
    pcVar5 = acStack_efa;
    uStack_101c = 0xf;
    uStack_1020 = 0;
    pvStack_1030 = (void *)((uint)pvStack_1030 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_efa,(int)pcVar5 - (int)(acStack_efa + 1));
    pcVar5 = acStack_dfa;
    uStack_1070 = 0xf;
    uStack_1074 = 0;
    pvStack_1084 = (void *)((uint)pvStack_1084 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_dfa,(int)pcVar5 - (int)(acStack_dfa + 1));
    pcVar5 = acStack_cfa;
    uStack_1038 = 0xf;
    uStack_103c = 0;
    pvStack_104c = (void *)((uint)pvStack_104c & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_cfa,(int)pcVar5 - (int)(acStack_cfa + 1));
    pcVar5 = acStack_bfa;
    uStack_1054 = 0xf;
    uStack_1058 = 0;
    pvStack_1068 = (void *)((uint)pvStack_1068 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_bfa,(int)pcVar5 - (int)(acStack_bfa + 1));
    pcVar5 = acStack_7c8;
    uStack_108c = 0xf;
    uStack_1090 = 0;
    pvStack_10a0 = (void *)((uint)pvStack_10a0 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_7c8,(int)pcVar5 - (int)(acStack_7c8 + 1));
    FUN_004b5bf0(1,auStack_1034);
    FUN_004b5bf0(2,auStack_1088);
    FUN_004b5bf0(0x15,local_10a4);
    if (0xf < uStack_108c) {
      _free(pvStack_10a0);
      return;
    }
    uStack_108c = 0xf;
    uStack_1090 = 0;
    pvStack_10a0 = (void *)((uint)pvStack_10a0 & 0xffffff00);
    if (0xf < uStack_1054) {
      _free(pvStack_1068);
      return;
    }
    uStack_1054 = 0xf;
    uStack_1058 = 0;
    pvStack_1068 = (void *)((uint)pvStack_1068 & 0xffffff00);
    if (0xf < uStack_1038) {
      _free(pvStack_104c);
      return;
    }
    uStack_1038 = 0xf;
    uStack_103c = 0;
    pvStack_104c = (void *)((uint)pvStack_104c & 0xffffff00);
    if (0xf < uStack_1070) {
      _free(pvStack_1084);
      return;
    }
    uStack_1070 = 0xf;
    uStack_1074 = 0;
    pvStack_1084 = (void *)((uint)pvStack_1084 & 0xffffff00);
    if (0xf < uStack_101c) {
      _free(pvStack_1030);
      return;
    }
  }
  return;
}


// ==== FUN_004f3df0 @ 0x004f3df0 ====

void FUN_004f3df0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 auStack_1a [10];
  uint uStack_10;
  uint uStack_c;
  
  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005084a0();
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  FUN_00508750(param_1);
  (**(code **)(*DAT_00b5ad14 + 0x10))(in_ECX + 0x20);
  uVar5 = 0;
  FUN_00401740(s_3dcamera_zangle__f_009b3370,0x12);
  puVar3 = auStack_1a + -6;
  uVar2 = FUN_00404230(puVar3);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uVar4 = 0;
  FUN_00401740(s_camera_vertical__f_009b3384,0x12);
  uVar2 = FUN_00404230(auStack_1a + -10,puVar3,uVar4,uVar5);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if (uStack_10 < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_004f3ee0 @ 0x004f3ee0 ====

void FUN_004f3ee0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) != 0) {
    if (*(char *)(in_ECX + 9) == '\x01') {
      FUN_004f3800(param_1);
      return;
    }
    do {
      cVar1 = FUN_004b59a0();
    } while (cVar1 == '\0');
    *(undefined1 *)(in_ECX + 9) = 1;
    FUN_004f3df0(0x69);
  }
  return;
}


// ==== FUN_004f3f20 @ 0x004f3f20 ====

/* WARNING: Removing unreachable block (ram,0x004f4054) */

void FUN_004f3f20(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  float10 fVar5;
  
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 != 0) {
    iVar4 = *(int *)(param_2 + 8) - iVar2;
    iVar1 = iVar4 >> 0x1f;
    iVar4 = iVar4 / 0x1c + iVar1;
    if (9 < (uint)(iVar4 - iVar1)) {
      if (iVar4 == iVar1) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660(iVar2,0,0xffffffff);
      iVar2 = FUN_00403620(0,0,s_setcamtargetpos_009b33b0,0xf);
      if (iVar2 == 0) {
        uVar3 = FUN_00405d30(2);
        fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
        *(float *)(in_ECX + 0x20) = (float)fVar5;
        uVar3 = FUN_00405d30(3);
        fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
        *(float *)(in_ECX + 0x24) = (float)fVar5;
        uVar3 = FUN_00405d30(4);
        fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
        *(float *)(in_ECX + 0x28) = (float)fVar5;
        uVar3 = FUN_00405d30(5);
        fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
        *(float *)(in_ECX + 0x2c) = (float)fVar5;
        uVar3 = FUN_00405d30(6);
        fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
        *(float *)(in_ECX + 0x30) = (float)fVar5;
        uVar3 = FUN_00405d30(7);
        uVar3 = thunk_FUN_00796fb0(uVar3);
        *(undefined4 *)(in_ECX + 0x40) = uVar3;
        uVar3 = FUN_00405d30(8);
        fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
        *(float *)(in_ECX + 0x44) = (float)fVar5;
        uVar3 = FUN_00405d30(9);
        fVar5 = (float10)thunk_FUN_00796ec0(uVar3);
        *(float *)(in_ECX + 0x48) = (float)fVar5;
      }
    }
  }
  return;
}


// ==== FUN_004f4070 @ 0x004f4070 ====

undefined4 FUN_004f4070(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  float10 fVar3;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_shakecam_009b3398,8);
  if (iVar1 != 0) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x28) != 0) &&
     ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 3)) {
    uVar2 = FUN_00459160(local_1c,0);
    uVar2 = thunk_FUN_00796fb0(uVar2);
    *(undefined4 *)(in_ECX + 0x40) = uVar2;
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX;
    }
    uVar2 = FUN_00459160(local_1c,1);
    fVar3 = (float10)thunk_FUN_00796ec0(uVar2);
    *(float *)(in_ECX + 0x44) = (float)fVar3;
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX_00;
    }
    uVar2 = FUN_00459160(local_1c,2);
    fVar3 = (float10)thunk_FUN_00796ec0(uVar2);
    *(float *)(in_ECX + 0x48) = (float)fVar3;
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX_01;
    }
  }
  return 1;
}


// ==== FUN_004f4170 @ 0x004f4170 ====

undefined4 FUN_004f4170(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xc) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 8))(param_1), cVar1 != '\0')) {
    return 1;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_004f3ee0(param_1);
  }
  else if ((iVar2 == 0x70004) && (iVar2 = FUN_004f4070(param_1), iVar2 != 0)) {
    return 1;
  }
  if ((*(int *)(in_ECX + 0x10) == 0) || (cVar1 = FUN_005084d0(param_1), cVar1 == '\0')) {
    return 0;
  }
  return 1;
}


// ==== FUN_004f41e0 @ 0x004f41e0 ====

void FUN_004f41e0(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int local_58;
  undefined1 local_54 [4];
  void *local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_Producer_login_info_txt_009b33c0,0x17);
  iVar3 = FUN_00410500(local_38);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (iVar3 == 0) {
    local_3c = 0xf;
    local_40 = 0;
    local_50 = (void *)((uint)local_50 & 0xffffff00);
    FUN_00401740(s_pScriptRes____NULL_009b33d8,0x12);
    FUN_00406880(local_54);
    if (local_3c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_50);
    return;
  }
  *(undefined4 *)(*(int *)(iVar3 + 0x4c) + 4) = 0;
  cVar2 = FUN_0049d7c0();
  while( true ) {
    if (cVar2 != '\0') {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
      return;
    }
    puVar5 = local_54;
    local_50 = (void *)0x0;
    local_4c = 0;
    local_48 = 0;
    uVar4 = FUN_0049d800(local_1c);
    FUN_00405670(uVar4,puVar5);
    if (0xf < local_4) break;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if ((local_50 != (void *)0x0) && (local_58 = (local_4c - (int)local_50) / 0x1c, local_58 != 0))
    {
      FUN_004f3f20(iVar3,local_54);
    }
    FUN_0049d780();
    if (local_50 != (void *)0x0) {
      FUN_00405de0(local_50,local_4c,local_54,local_58);
      _free(local_50);
      return;
    }
    local_50 = (void *)0x0;
    local_4c = 0;
    local_48 = 0;
    cVar2 = FUN_0049d7c0();
  }
  _free(local_18);
  return;
}


// ==== FUN_004f4370 @ 0x004f4370 ====

void FUN_004f4370(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_20;
  undefined1 uStack_1c;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  local_20 = (void *)0x0;
  (**(code **)(*DAT_00b5add8 + 4))(1);
  FUN_004f41e0();
  FUN_004de2a0(0,9999);
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = 0;
  FUN_00401740(s_ds_zfar_1000_009b332c,0xc);
  (**(code **)(*DAT_00b5a688 + 4))(&local_20);
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  if (*(int *)(in_ECX + 0xc) == 0) {
    pvVar1 = operator_new(0x20);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0065d900(in_ECX);
    }
    *(undefined4 *)(in_ECX + 0xc) = uVar2;
  }
  iVar3 = (**(code **)(*DAT_00b5ac1c + 8))();
  if (*(char *)(iVar3 + 5) != -1) {
    FUN_0065c850();
  }
  *(undefined1 *)(in_ECX + 9) = 0;
  pvVar1 = operator_new(0x84);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uStack_c = 0xf;
    uStack_10 = 0;
    local_20 = (void *)((uint)local_20 & 0xffffff00);
    FUN_00401740(s_Empty_009b333c,5);
    uVar2 = FUN_004b5800((int)register0x00000010 + -0x24);
  }
  *(undefined4 *)(in_ECX + 0x4c) = uVar2;
  if ((pvVar1 == (void *)0x0) || (uStack_c < 0x10)) {
    FUN_004f3b50(0x69);
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_004f44a0 @ 0x004f44a0 ====

void FUN_004f44a0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined **local_70 [4];
  undefined4 local_60;
  undefined4 local_5c;
  void *local_58;
  undefined1 local_54 [12];
  undefined4 uStack_48;
  uint uStack_44;
  void *pvStack_3c;
  undefined1 local_38 [16];
  uint uStack_28;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  uVar1 = FUN_00404890(local_1c);
  FUN_004045b0(local_38,uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar1 = FUN_004046f0(local_1c,local_38,s_user_config_009b33a4);
  FUN_00402220(local_54,uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_70[0] = &PTR_FUN_0099d55c;
  local_60 = 0;
  local_5c = 0;
  local_58 = (void *)0x0;
  FUN_00411630(param_1);
  (**(code **)(*DAT_00b5a740 + 0xc))(local_54,local_70);
  FUN_004137c0();
  if (0xf < uStack_44) {
    _free(local_58);
    return;
  }
  uStack_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  uStack_44 = 0xf;
  if (uStack_28 < 0x10) {
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_004f4590 @ 0x004f4590 ====

undefined1 FUN_004f4590(void)

{
  return 1;
}


// ==== FUN_004f45a0 @ 0x004f45a0 ====

int FUN_004f45a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x28) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28)) / 0x1c;
}


// ==== FUN_004f45d0 @ 0x004f45d0 ====

int FUN_004f45d0(int param_1)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  
  puVar2 = PTR_s_SceneLogin_00ae9a38;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar3 = puVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(puVar2,(int)pcVar3 - (int)(puVar2 + 1));
  return param_1;
}


// ==== FUN_004f4610 @ 0x004f4610 ====

void FUN_004f4610(byte param_1)

{
  void *in_ECX;
  
  FUN_004f3a10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f4630 @ 0x004f4630 ====

void FUN_004f4630(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_004f4640 @ 0x004f4640 ====

void FUN_004f4640(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_004f4690 @ 0x004f4690 ====

void FUN_004f4690(void)

{
  int in_ECX;
  
  FUN_004f4a10(in_ECX + 0x14);
  return;
}


// ==== FUN_004f46a0 @ 0x004f46a0 ====

void FUN_004f46a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3468;
  FUN_004f4a10(in_ECX + 5);
  *(undefined1 *)(in_ECX + 1) = 0;
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_004f46e0 @ 0x004f46e0 ====

void FUN_004f46e0(void)

{
  undefined4 *_Dst;
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  void *pvStack_3c;
  undefined1 local_38 [4];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [12];
  undefined4 uStack_10;
  uint uStack_c;
  
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s_Packet_Queueing_009b3454,0xf);
  FUN_00401740(s__u__u__u__009b3448,9);
  uVar1 = FUN_00404230(local_1c);
  (**(code **)(*DAT_00b5a688 + 8))(local_38,uVar1);
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(char *)(in_ECX + 4) == '\x01') {
    if (*(int *)(in_ECX + 0x18) == 0) {
      *(undefined4 *)(in_ECX + 0x10) = 0;
      return;
    }
    *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 2;
  }
  else {
    if ((*(int *)(in_ECX + 0x18) == 0) ||
       (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 2 == 0)) {
      *(undefined4 *)(in_ECX + 0x10) = 0;
      *(undefined4 *)(in_ECX + 0xc) = 2000;
      return;
    }
    if (*(int *)(in_ECX + 0x18) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 2;
    }
    if (*(uint *)(in_ECX + 0x10) <= uVar2) {
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 5;
    }
    if (*(int *)(in_ECX + 0x18) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 2;
    }
    *(int *)(in_ECX + 0x10) = iVar3;
    uVar2 = 0;
    while ((_Dst = *(undefined4 **)(in_ECX + 0x18), _Dst != (undefined4 *)0x0 &&
           (*(int *)(in_ECX + 0x1c) - (int)_Dst >> 2 != 0))) {
      uVar1 = *_Dst;
      uVar4 = FUN_00424500();
      if (uVar4 < 0x5080001) {
        if ((uVar4 == 0x5080000) ||
           (((uVar4 == 0x5040000 || (uVar4 == 0x5050000)) || (uVar4 == 0x5070000)))) {
LAB_004f4882:
          uVar2 = uVar2 + 1;
          if (*(uint *)(in_ECX + 0xc) < uVar2) {
            return;
          }
        }
      }
      else if ((uVar4 == 0x5090000) || (uVar4 == 0x5190000)) goto LAB_004f4882;
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        *puVar5 = &PTR_FUN_009a0f78;
        *(undefined1 *)(puVar5 + 1) = 0;
        uVar6 = FUN_00424500();
        puVar5[2] = uVar6;
        puVar5[3] = uVar1;
      }
      *(undefined1 *)(puVar5 + 1) = 1;
      FUN_00797a20(puVar5);
      _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0x1c) - (int)(_Dst + 1) >> 2) * 4);
      *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -4;
    }
  }
  return;
}


// ==== FUN_004f4900 @ 0x004f4900 ====

void FUN_004f4900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3468;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 2000;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_004f4930 @ 0x004f4930 ====

undefined4 FUN_004f4930(int param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = param_1;
  if (*(char *)(param_1 + 4) != '\0') {
    return 0;
  }
  uVar2 = FUN_00424500();
  if (uVar2 < 0x5080001) {
    if ((uVar2 != 0x5080000) &&
       (((uVar2 != 0x5040000 && (uVar2 != 0x5050000)) && (uVar2 != 0x5070000)))) goto LAB_004f4978;
  }
  else if ((uVar2 != 0x5090000) && (uVar2 != 0x5190000)) goto LAB_004f4978;
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
LAB_004f4978:
  if (((*(char *)(in_ECX + 4) == '\0') &&
      ((*(int *)(in_ECX + 0x18) == 0 ||
       (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 2 == 0)))) &&
     (*(uint *)(in_ECX + 8) < 0x7d1)) {
    return 0;
  }
  param_1 = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0xc) = 0;
  FUN_004f4d10(&param_1);
  return 1;
}


// ==== FUN_004f49d0 @ 0x004f49d0 ====

uint FUN_004f49d0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_004f46e0(param_1);
  }
  else if (uVar1 == 0x50011) {
    uVar1 = FUN_004f4930(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004f4a10 @ 0x004f4a10 ====

void FUN_004f4a10(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  if ((puVar1 != (undefined4 *)0x0) && ((int)*(undefined4 **)(param_1 + 8) - (int)puVar1 >> 2 != 0))
  {
    if (puVar1 != *(undefined4 **)(param_1 + 8)) {
      _free((void *)*puVar1);
      return;
    }
    if (*(void **)(param_1 + 4) != (void *)0x0) {
      _free(*(void **)(param_1 + 4));
      return;
    }
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


// ==== FUN_004f4a70 @ 0x004f4a70 ====

void FUN_004f4a70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3468;
  FUN_004f4a10(in_ECX + 5);
  *(undefined1 *)(in_ECX + 1) = 0;
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f4ac0 @ 0x004f4ac0 ====

void FUN_004f4ac0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981530;
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


// ==== Catch@004f4c21 @ 0x004f4c21 ====

void Catch_004f4c21(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_004f4d10 @ 0x004f4d10 ====

void FUN_004f4d10(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_004f4ac0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004f4d60 @ 0x004f4d60 ====

undefined4 FUN_004f4d60(void)

{
  int in_ECX;
  
  switch(*(undefined1 *)(in_ECX + 0xb)) {
  case 0:
  case 9:
  case 0xb:
  case 0x14:
  case 0x17:
    return 0x11;
  case 1:
  case 0x12:
  case 0x13:
  case 0x16:
  case 0x18:
  case 0x19:
    return 0xc;
  case 2:
    return 0x10;
  case 3:
  case 7:
    return 0x15;
  case 4:
    return 0x1c;
  case 5:
    return 0x16;
  case 6:
  case 0xc:
  case 0xd:
  case 0xe:
    return 0x13;
  case 8:
  case 10:
  case 0x10:
    return 0x14;
  case 0xf:
  case 0x11:
  case 0x15:
  case 0x1e:
    return 0xd;
  default:
    return 0;
  }
}


// ==== FUN_004f4e30 @ 0x004f4e30 ====

void FUN_004f4e30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b34b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f4e50 @ 0x004f4e50 ====

void FUN_004f4e50(void)

{
  return;
}


// ==== FUN_004f4e60 @ 0x004f4e60 ====

void FUN_004f4e60(void)

{
  int in_ECX;
  
  FUN_00826020(*(undefined4 *)(in_ECX + 4));
  return;
}


// ==== FUN_004f4e70 @ 0x004f4e70 ====

undefined4 FUN_004f4e70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004f4e80 @ 0x004f4e80 ====

undefined4 FUN_004f4e80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_004f4e90 @ 0x004f4e90 ====

undefined4 FUN_004f4e90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 0xac);
}


// ==== FUN_004f4ea0 @ 0x004f4ea0 ====

undefined1 FUN_004f4ea0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x18) + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  return *(undefined1 *)(iVar2 + 0x2a);
}


// ==== FUN_004f4ec0 @ 0x004f4ec0 ====

bool FUN_004f4ec0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) == 0) ||
     (piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x1c), piVar1 == (int *)0x0)) {
    return false;
  }
  uVar2 = (**(code **)(*piVar1 + 0x1c))();
  iVar3 = FUN_00803725(uVar2,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  return iVar3 != 0;
}


// ==== FUN_004f4f00 @ 0x004f4f00 ====

uint FUN_004f4f00(undefined1 param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x48) + 0x1c))(&param_1);
  if ((short)uVar1 != 0) {
    FUN_00826100(*(undefined4 *)(in_ECX + 4),uVar1);
  }
  return uVar1 & 0xffff;
}


// ==== FUN_004f4f30 @ 0x004f4f30 ====

void FUN_004f4f30(void)

{
  if (DAT_00b5a980 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a980)(1);
  }
  return;
}


// ==== FUN_004f4f50 @ 0x004f4f50 ====

void FUN_004f4f50(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_009b3514;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a980 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a980 = in_ECX;
  }
  uVar5 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  *puVar1 = uVar5;
  cVar4 = FUN_005c8e90();
  piVar3 = DAT_00b5a6ac;
  if (cVar4 == '\x01') {
    piVar6 = (int *)(**(code **)(*(int *)*puVar1 + 0x10))();
    iVar2 = *piVar6;
    uVar5 = (**(code **)(*piVar3 + 0x20))();
    (**(code **)(iVar2 + 0x28))(uVar5);
  }
  uVar5 = (**(code **)(*DAT_00b5a984 + 0xc))(1,0);
  in_ECX[2] = uVar5;
  return;
}


// ==== FUN_004f4fd0 @ 0x004f4fd0 ====

void FUN_004f4fd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3514;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 4))();
    (**(code **)(*DAT_00b5a984 + 0x10))(1,in_ECX[2]);
    in_ECX[2] = 0;
  }
  DAT_00b5a980 = 0;
  *in_ECX = &PTR_FUN_009b34b4;
  return;
}


// ==== FUN_004f5010 @ 0x004f5010 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004f5010(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = *(int **)(*(int *)(in_ECX + 4) + 0x74);
  if (piVar2 == (int *)0x0) {
    iVar1 = (**(code **)(_DAT_00000000 + 8))();
    return *(undefined1 *)(iVar1 + 4);
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
  iVar1 = (**(code **)(*piVar2 + 8))();
  return *(undefined1 *)(iVar1 + 4);
}


// ==== FUN_004f5040 @ 0x004f5040 ====

undefined4 FUN_004f5040(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x18) + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  piVar1 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(*(undefined2 *)(iVar2 + param_1 * 2));
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  return *(undefined4 *)(iVar2 + 0x18);
}


// ==== FUN_004f5080 @ 0x004f5080 ====

float10 FUN_004f5080(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_c [12];
  
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x4c);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
  }
  (**(code **)(*piVar1 + 0x10))();
  iVar2 = FUN_004f5730(auStack_c);
  return (float10)*(float *)(iVar2 + 8);
}


// ==== FUN_004f50d0 @ 0x004f50d0 ====

bool FUN_004f50d0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  piVar3 = *(int **)(*(int *)(in_ECX + 4) + 0x4c);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(*piVar3 + 0x18))();
  }
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(*piVar3 + 8))(uVar1);
  iVar2 = (**(code **)(*piVar3 + 0x10))();
  return *(char *)(iVar2 + 0xb) == '\b';
}


// ==== FUN_004f5110 @ 0x004f5110 ====

uint FUN_004f5110(undefined1 param_1)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x48);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x28))();
  }
  uVar2 = (**(code **)(*piVar1 + 0x18))(&param_1);
  if ((short)uVar2 != 0) {
    FUN_00826100(*(undefined4 *)(in_ECX + 4),uVar2);
  }
  return uVar2 & 0xffff;
}


// ==== FUN_004f5150 @ 0x004f5150 ====

void FUN_004f5150(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))(param_1,param_2,param_3);
  FUN_00826370(*(undefined4 *)(in_ECX + 4),uVar1);
  return;
}


// ==== FUN_004f5180 @ 0x004f5180 ====

void FUN_004f5180(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *piVar3;
  undefined1 local_1c [2];
  undefined1 auStack_1a [26];
  
  piVar3 = *(int **)(*(int *)(in_ECX + 4) + 0x4c);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(*piVar3 + 0x18))();
  }
  uVar2 = FUN_004f4d60();
  FUN_00403e60(local_1c,param_1,uVar2);
  iVar1 = *piVar3;
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar1 + 0x30))(local_1c,uVar2);
  (**(code **)(*piVar3 + 0x24))(local_1c + -8);
  return;
}


// ==== FUN_004f51e0 @ 0x004f51e0 ====

void FUN_004f51e0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x4c);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
  }
                    /* WARNING: Could not recover jumptable at 0x004f51f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x24))();
  return;
}


// ==== FUN_004f5200 @ 0x004f5200 ====

void FUN_004f5200(void)

{
  void *pvVar1;
  
  if (DAT_00b5a980 == 0) {
    pvVar1 = operator_new(0xc);
    if (pvVar1 != (void *)0x0) {
      FUN_004f4f50();
      return;
    }
  }
  return;
}


// ==== FUN_004f5220 @ 0x004f5220 ====

int FUN_004f5220(int param_1)

{
  char cVar1;
  char *pcVar2;
  int extraout_EAX;
  int in_ECX;
  char *pcVar3;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  pcVar2 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0x70))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(auStack_1c,0,0xffffffff);
  if (uStack_4 < 0x10) {
    return param_1;
  }
  _free(pvStack_18);
  return extraout_EAX;
}


// ==== FUN_004f52a0 @ 0x004f52a0 ====

int * FUN_004f52a0(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int *extraout_EAX;
  int in_ECX;
  uint uVar7;
  int *unaff_EBP;
  undefined4 *puVar8;
  int *piStack_a4;
  void *pvStack_a0;
  int *piStack_9c;
  undefined4 uStack_98;
  int iStack_90;
  uint uStack_8c;
  undefined1 auStack_88 [12];
  char acStack_7c [26];
  undefined4 auStack_62 [11];
  undefined1 uStack_36;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [7];
  undefined1 uStack_6;
  
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_98 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x18) + 0x14))();
  piVar3 = *(int **)(*(int *)(in_ECX + 4) + 0x74);
  if (piVar3 == (int *)0x0) {
    piStack_a4 = (int *)0x0;
  }
  else {
    piStack_a4 = (int *)(**(code **)(*piVar3 + 0x14))();
  }
  piVar3 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x50) + 0x14))(uVar2);
  piStack_a4 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x4c) + 0x14))();
  pvStack_a0 = (void *)(**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x7c) + 0x14))();
  acStack_7c[0] = '\0';
  uStack_6 = (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0x98) + 0x24))();
  iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x70))();
  uVar7 = 0;
  do {
    cVar1 = (acStack_7c + uVar7)[iVar4 - (int)acStack_7c];
    acStack_7c[uVar7] = cVar1;
    if (cVar1 == '\0') goto LAB_004f535a;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0x19);
  acStack_7c[0] = '\0';
LAB_004f535a:
  puVar5 = (undefined4 *)(**(code **)(*piStack_9c + 8))();
  puVar8 = auStack_62;
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar4 = (**(code **)(*unaff_EBP + 8))();
  uStack_36 = *(undefined1 *)(iVar4 + 4);
  puVar5 = (undefined4 *)(**(code **)(*unaff_EBP + 8))();
  uStack_34 = *puVar5;
  pfVar6 = (float *)(**(code **)(*piVar3 + 0x18))();
  iStack_30 = (int)*pfVar6;
  iVar4 = (**(code **)(*piVar3 + 0x18))();
  iStack_2c = (int)*(float *)(iVar4 + 4);
  iVar4 = (**(code **)(*piVar3 + 0x18))();
  uStack_28 = (uint)*(float *)(iVar4 + 8);
  iVar4 = *piStack_a4;
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  puVar5 = (undefined4 *)(**(code **)(iVar4 + 0x18))(uVar2);
  puVar8 = auStack_24;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar8 = puVar8 + 1;
  }
  *(undefined1 *)puVar8 = *(undefined1 *)puVar5;
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  piVar3 = piStack_a4;
  if (cVar1 == '\x01') {
    iVar4 = (**(code **)(*piStack_a4 + 8))();
    uStack_28._0_3_ = CONCAT12(*(undefined1 *)(iVar4 + 10),(undefined2)uStack_28);
    iVar4 = (**(code **)(*piVar3 + 8))();
    uStack_28 = CONCAT22(uStack_28._2_2_,*(undefined2 *)(iVar4 + 8));
  }
  else {
    uStack_28 = uStack_28 & 0xff000000;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a754 + 0xc))(1,0);
  piVar3[0x2b] = *(int *)(*(int *)(in_ECX + 4) + 0xac);
  iVar4 = (**(code **)(*DAT_00b5ac1c + 0x3c))();
  if (iVar4 == 0) {
    uStack_8c = 0xf;
    pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
    iStack_90 = iVar4;
    FUN_00401740(&DAT_009b3470,0xd);
    FUN_00403e50(&piStack_a4);
    if (0xf < uStack_8c) {
      _free(pvStack_a0);
      return extraout_EAX;
    }
  }
  (**(code **)(*piVar3 + 0x18))(iVar4,auStack_88);
  return piVar3;
}


// ==== FUN_004f54d0 @ 0x004f54d0 ====

void FUN_004f54d0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = *DAT_00b5adf8;
  uVar2 = FUN_004f52a0();
  uVar2 = (**(code **)(*in_ECX + 0x10))(uVar2);
  (**(code **)(iVar1 + 4))(uVar2);
  return;
}


// ==== FUN_004f5500 @ 0x004f5500 ====

void FUN_004f5500(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined4 uStack_1c;
  uint uStack_8;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x44);
  piVar2 = (int *)(**(code **)(*piVar1 + 0x18))();
  iVar4 = *piVar1;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar4 + 0x1c))(uVar3);
  FUN_00401740(s_Update_HP_MP_SD____f__f__f_009b3480,0x1a);
  uVar3 = FUN_00404230((int)register0x00000010 + -0x20);
  FUN_00796d50(uVar3);
  if (0xf < uStack_8) {
    _free(uStack_1c);
    return;
  }
  iVar4 = (**(code **)(*piVar2 + 0xc))();
  if (*(float *)(iVar4 + 0x2c) == DAT_0099cdc8) {
    iVar4 = *piVar2;
    (**(code **)(*DAT_00b5a6ac + 0x20))();
    (**(code **)(iVar4 + 0x38))();
  }
  (**(code **)(*piVar2 + 0x14))();
  (**(code **)(*piVar2 + 0x20))(unaff_retaddr);
  (**(code **)(*piVar2 + 0x2c))();
  return;
}


// ==== FUN_004f55e0 @ 0x004f55e0 ====

undefined4 FUN_004f55e0(undefined4 param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 extraout_EAX_00;
  int in_ECX;
  void *_Memory;
  undefined1 *puVar6;
  undefined1 auStack_2c [4];
  void *local_28;
  undefined1 *local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  int *local_8;
  uint local_4;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x10);
  puVar6 = (undefined1 *)0x0;
  _Memory = (void *)0x0;
  local_28 = (void *)0x0;
  local_24 = (undefined1 *)0x0;
  local_20 = 0;
  if (piVar1 == (int *)0x0) {
    local_4 = 0xf;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    local_8 = piVar1;
    FUN_00401740(s_pBufferList____NULL_009b349c,0x13);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    _free(local_18);
    return extraout_EAX;
  }
  piVar4 = (int *)(**(code **)(*piVar1 + 0x18))();
  while (piVar4 != (int *)0x0) {
    piVar4 = (int *)(**(code **)(*piVar4 + 0xc))();
    iVar5 = (**(code **)(*piVar4 + 4))();
    if ((_Memory == (void *)0x0) ||
       ((uint)(local_20 - (int)_Memory) <= (uint)((int)puVar6 - (int)_Memory))) {
      FUN_00469780(puVar6,1,(undefined1 *)(iVar5 + 0x102));
      _Memory = local_28;
    }
    else {
      *puVar6 = *(undefined1 *)(iVar5 + 0x102);
      local_24 = puVar6 + 1;
    }
    puVar6 = local_24;
    piVar4 = (int *)(**(code **)(*piVar1 + 0x1c))();
  }
  FUN_004b39c0(auStack_2c);
  if (_Memory == (void *)0x0) {
    return param_1;
  }
  _free(_Memory);
  return extraout_EAX_00;
}


// ==== FUN_004f56d0 @ 0x004f56d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004f56d0(byte param_1)

{
  if ((DAT_00b5ade8 & 1) == 0) {
    DAT_00b5ade8 = DAT_00b5ade8 | 1;
    _DAT_00b5ade4 = DAT_009b0eb8;
  }
  if ((DAT_00b5ade8 & 2) == 0) {
    DAT_00b5ade8 = DAT_00b5ade8 | 2;
    _DAT_00b5ade0 = DAT_009b2d7c;
  }
  return (float10)param_1 * (float10)_DAT_00b5ade0 * (float10)_DAT_009ae954;
}


// ==== FUN_004f5730 @ 0x004f5730 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f5730(float *param_1)

{
  ushort *in_ECX;
  float fVar1;
  float fVar2;
  
  if ((DAT_00b5adf4 & 1) == 0) {
    DAT_00b5adf4 = DAT_00b5adf4 | 1;
    _DAT_00b5adf0 = DAT_009b0eb8;
  }
  if ((DAT_00b5adf4 & 2) == 0) {
    DAT_00b5adf4 = DAT_00b5adf4 | 2;
    _DAT_00b5adec = DAT_009b2d7c;
  }
  fVar2 = (float)in_ECX[1] * DAT_009b3508;
  if ((DAT_00b5ade8 & 1) == 0) {
    DAT_00b5ade8 = DAT_00b5ade8 | 1;
    _DAT_00b5ade4 = DAT_009b0eb8;
  }
  if ((DAT_00b5ade8 & 2) == 0) {
    DAT_00b5ade8 = DAT_00b5ade8 | 2;
    _DAT_00b5ade0 = DAT_009b2d7c;
  }
  fVar1 = (float)(byte)in_ECX[2] * _DAT_00b5ade0 * _DAT_009ae954;
  *param_1 = (float)*in_ECX * DAT_009b3508;
  param_1[1] = fVar2;
  param_1[2] = fVar1;
  return;
}


// ==== FUN_004f5810 @ 0x004f5810 ====

void FUN_004f5810(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3514;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 4))();
    (**(code **)(*DAT_00b5a984 + 0x10))(1,in_ECX[2]);
    in_ECX[2] = 0;
  }
  DAT_00b5a980 = 0;
  *in_ECX = &PTR_FUN_009b34b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f5870 @ 0x004f5870 ====

void FUN_004f5870(undefined2 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


// ==== FUN_004f58a0 @ 0x004f58a0 ====

undefined1 FUN_004f58a0(void)

{
  return 0;
}


// ==== FUN_004f58b0 @ 0x004f58b0 ====

undefined4 FUN_004f58b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_004f58c0 @ 0x004f58c0 ====

void FUN_004f58c0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b35a4;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_004f58e0 @ 0x004f58e0 ====

void FUN_004f58e0(void)

{
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_>>_CHANGESTATECMD_Start_009b356c,0x1b);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    FUN_004e9b80(*(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = 1;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f5960 @ 0x004f5960 ====

undefined4 FUN_004f5960(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004f5970 @ 0x004f5970 ====

void FUN_004f5970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3628;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_004f5980 @ 0x004f5980 ====

uint FUN_004f5980(int param_1)

{
  uint extraout_EAX;
  uint uVar1;
  uint extraout_EAX_00;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_8 = 0;
  local_4 = 0xf;
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00401740(s_>>_DISCONNECTCMD_Start_009b35dc,0x1a);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      *(undefined4 *)(in_ECX + 4) = 0;
      uVar1 = FUN_004d8610();
      return uVar1 & 0xffffff00;
    }
    _free(local_18);
    return extraout_EAX_00;
  }
  FUN_00401740(s_>>_DISCONNECTCMD_Start_Fail_009b35bc,0x1f);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    uVar1 = FUN_004ea450();
    *(undefined4 *)(in_ECX + 4) = 1;
    return uVar1 & 0xffffff00;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_004f5a40 @ 0x004f5a40 ====

void FUN_004f5a40(undefined4 param_1,int param_2)

{
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_>>_DISCONNECTCMD_End_009b35f8,0x18);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    *(undefined4 *)(in_ECX + 4) = 1;
    *(undefined4 *)(param_2 + 8) = 0;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f5ac0 @ 0x004f5ac0 ====

undefined4 FUN_004f5ac0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == -0x7ffffffd) {
    FUN_004f5a40(param_1,param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_004f5b10 @ 0x004f5b10 ====

undefined1 FUN_004f5b10(void)

{
  return 0;
}


// ==== FUN_004f5b20 @ 0x004f5b20 ====

undefined4 FUN_004f5b20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004f5b30 @ 0x004f5b30 ====

void FUN_004f5b30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3660;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_004f5b40 @ 0x004f5b40 ====

void FUN_004f5b40(void)

{
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_>>_QUITPROGRAMCMD_Start_009b3640,0x1b);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    PostQuitMessage(0);
    *(undefined4 *)(in_ECX + 4) = 1;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f5bc0 @ 0x004f5bc0 ====

undefined4 FUN_004f5bc0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_004f5bd0 @ 0x004f5bd0 ====

void FUN_004f5bd0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b36a0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_004f5c20 @ 0x004f5c20 ====

uint FUN_004f5c20(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if ((uVar1 == 0x40001) && (uVar1 = *(uint *)(in_ECX + 8), uVar1 != 0)) {
    if (uVar1 <= (uint)param_1[1]) {
      *(undefined4 *)(in_ECX + 8) = 0;
      *(undefined4 *)(in_ECX + 0xc) = 1;
      return uVar1 & 0xffffff00;
    }
    uVar1 = uVar1 - param_1[1];
    *(uint *)(in_ECX + 8) = uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004f5c70 @ 0x004f5c70 ====

uint FUN_004f5c70(void)

{
  uint uVar1;
  uint extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 0xc) = 1;
    return 1;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_>>_WAIT_Start_009b3678,0x11);
  uVar1 = FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
    return uVar1 & 0xffffff00;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_004f5d00 @ 0x004f5d00 ====

undefined1 FUN_004f5d00(void)

{
  return 0;
}


// ==== FUN_004f5d10 @ 0x004f5d10 ====

undefined4 FUN_004f5d10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_004f5d20 @ 0x004f5d20 ====

void FUN_004f5d20(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b36cc;
  in_ECX[1] = *param_1;
  in_ECX[2] = param_2;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_004f5d50 @ 0x004f5d50 ====

/* WARNING: Removing unreachable block (ram,0x004f5dce) */

undefined4 FUN_004f5d50(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  undefined1 auStack_1a [26];
  
  if (*(int *)(in_ECX + 8) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    iVar2 = iVar2 + *(int *)(in_ECX + 8);
  }
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))
                    (5,CONCAT22(*(undefined2 *)(in_ECX + 4),*(undefined2 *)(in_ECX + 6)));
  FUN_00401660(uVar1,0,0xffffffff);
  FUN_004ea120(auStack_1a + -10,iVar2);
  *(undefined4 *)(in_ECX + 0xc) = 1;
  return 1;
}


// ==== FUN_004f5df0 @ 0x004f5df0 ====

void FUN_004f5df0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b36fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f5e10 @ 0x004f5e10 ====

undefined1 FUN_004f5e10(void)

{
  return 0;
}


// ==== FUN_004f5e20 @ 0x004f5e20 ====

void FUN_004f5e20(void)

{
  return;
}


// ==== FUN_004f5e30 @ 0x004f5e30 ====

void FUN_004f5e30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3710;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad30 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad30 = in_ECX;
  return;
}


// ==== FUN_004f5e80 @ 0x004f5e80 ====

void FUN_004f5e80(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s____TOOL____Start_009b36e4,0x10);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f5ed0 @ 0x004f5ed0 ====

void FUN_004f5ed0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad30 = 0;
  *in_ECX = &PTR_FUN_009b36fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f5f00 @ 0x004f5f00 ====

void FUN_004f5f00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b37f8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad34 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad34 = in_ECX;
  return;
}


// ==== FUN_004f5f50 @ 0x004f5f50 ====

void FUN_004f5f50(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s____TOOL____Start_009b37c4,0x10);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f5fa0 @ 0x004f5fa0 ====

void FUN_004f5fa0(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_004e9d50();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009b37d8,0x1a);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f6000 @ 0x004f6000 ====

void FUN_004f6000(undefined4 param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *pcVar4;
  bool bVar5;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  bVar5 = false;
  FUN_004e9d50();
  pvVar2 = operator_new(0xc);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004f58c0(DAT_00b5ad48);
  }
  FUN_004ea750(uVar3);
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    local_8 = 0;
    local_4 = 0xf;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar4 = PTR_s_SceneInit_00ae9ea0;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneInit_00ae9ea0,(int)pcVar4 - (int)(PTR_s_SceneInit_00ae9ea0 + 1));
    bVar5 = true;
    uVar3 = FUN_004f8810(local_1c);
  }
  FUN_004ea750(uVar3);
  if ((bVar5) && (0xf < local_4)) {
    _free(local_18);
    return;
  }
  *(undefined4 *)(param_2 + 4) = 0;
  return;
}


// ==== FUN_004f60d0 @ 0x004f60d0 ====

undefined4 FUN_004f60d0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x50000100) {
    FUN_004f6000(param_1,param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_004f6110 @ 0x004f6110 ====

void FUN_004f6110(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad34 = 0;
  *in_ECX = &PTR_FUN_009b36fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f6170 @ 0x004f6170 ====

void FUN_004f6170(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3934;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad38 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad38 = in_ECX;
  return;
}


// ==== FUN_004f61f0 @ 0x004f61f0 ====

void FUN_004f61f0(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s____PLAYING____Start_009b38ac,0x13);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f6240 @ 0x004f6240 ====

void FUN_004f6240(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_004e9d50();
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 1) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(&DAT_009b38c0,0x1a);
    FUN_00796d50(local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      FUN_00797a20(0);
      return;
    }
    *puVar2 = &PTR_FUN_009b3920;
    FUN_00797a20(puVar2);
    return;
  }
  if (iVar1 == 2) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(&DAT_009b38dc,0x1f);
    FUN_00796d50(local_38);
    if (local_20 < 0x10) {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      FUN_004ea770(0);
      return;
    }
    _free(local_34);
    return;
  }
  if (iVar1 == 3) {
    FUN_004ea9d0(0);
    return;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(&DAT_009b38fc,0x1a);
  FUN_00796d50(local_54);
  if (local_3c < 0x10) {
    local_3c = 0xf;
    local_40 = 0;
    local_50 = (void *)((uint)local_50 & 0xffffff00);
    FUN_004ea770(0);
    return;
  }
  _free(local_50);
  return;
}


// ==== FUN_004f63d0 @ 0x004f63d0 ====

void FUN_004f63d0(int param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  bool bVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  void *pvVar12;
  char *pcVar13;
  ushort uStack_34;
  undefined4 uStack_28;
  undefined4 uStack_24;
  ushort uStack_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  sVar3 = *(short *)(param_2 + 0xb4);
  sVar4 = *(short *)(param_1 + 4);
  FUN_004e9fe0(sVar4);
  piVar9 = (int *)(**(code **)(**(int **)(*(int *)(param_2 + 0xbc) + 0x4c) + 0x18))();
  piVar8 = DAT_00b5a6ac;
  sVar5 = *(short *)(param_1 + 8);
  iVar6 = *(int *)(param_1 + 6);
  if (*(char *)(param_1 + 10) != '\0') {
    iVar10 = (**(code **)(*piVar9 + 0x10))();
    uVar1 = *(undefined1 *)(iVar10 + 10);
    uVar11 = (**(code **)(*piVar8 + 0x20))();
    FUN_00797a50(&uStack_28,0,0xc);
    uStack_24 = CONCAT22(sVar5 << 7,(short)(iVar6 << 7));
    uStack_1d = 1;
    uStack_20 = uStack_34 & 0xff00;
    uStack_28 = uVar11;
    uStack_1e = uVar1;
    (**(code **)(*piVar9 + 0x24))(&uStack_28);
  }
  pvVar12 = operator_new(8);
  if (pvVar12 == (void *)0x0) {
    uVar11 = 0;
  }
  else {
    uVar11 = FUN_00509580();
  }
  FUN_004ea750(uVar11);
  pvVar12 = operator_new(0x24);
  uVar11 = 0;
  if (pvVar12 != (void *)0x0) {
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(&DAT_009b3917,0);
    uVar11 = FUN_004f8810(auStack_1c);
  }
  FUN_004ea750(uVar11);
  if ((pvVar12 != (void *)0x0) && (0xf < uStack_4)) {
    _free(pvStack_18);
    return;
  }
  bVar7 = false;
  pvVar12 = operator_new(8);
  if (pvVar12 == (void *)0x0) {
    uVar11 = 0;
  }
  else {
    uVar11 = FUN_00509520();
  }
  FUN_004ea750(uVar11);
  if (sVar4 != sVar3) {
    pvVar12 = operator_new(8);
    if (pvVar12 == (void *)0x0) {
      uVar11 = 0;
    }
    else {
      uVar11 = FUN_00509480();
    }
    FUN_004ea750(uVar11);
    pvVar12 = operator_new(0xc);
    if (pvVar12 == (void *)0x0) {
      uVar11 = 0;
    }
    else {
      uVar11 = FUN_00508e60();
    }
    FUN_004ea750(uVar11);
  }
  pvVar12 = operator_new(0xc);
  if (pvVar12 == (void *)0x0) {
    uVar11 = 0;
  }
  else {
    uVar11 = FUN_004f58c0(DAT_00b5ad38);
  }
  FUN_004ea750(uVar11);
  pvVar12 = operator_new(0x24);
  uVar11 = 0;
  if (pvVar12 != (void *)0x0) {
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    uStack_4 = 0xf;
    pcVar13 = PTR_s_SceneGame2_00ae9f78;
    do {
      cVar2 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar2 != '\0');
    FUN_00401740(PTR_s_SceneGame2_00ae9f78,(int)pcVar13 - (int)(PTR_s_SceneGame2_00ae9f78 + 1));
    bVar7 = true;
    uVar11 = FUN_004f8810(auStack_1c);
  }
  FUN_004ea750(uVar11);
  if ((bVar7) && (0xf < uStack_4)) {
    _free(pvStack_18);
    return;
  }
  pvVar12 = operator_new(8);
  if (pvVar12 == (void *)0x0) {
    uVar11 = 0;
  }
  else {
    uVar11 = FUN_00509580();
  }
  FUN_004ea750(uVar11);
  if (DAT_00b5acd4 != (int *)0x0) {
    (**(code **)(*DAT_00b5acd4 + 4))(0);
  }
  return;
}


// ==== FUN_004f6680 @ 0x004f6680 ====

void FUN_004f6680(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar1 = param_2;
  local_20 = 0;
  iVar2 = (**(code **)(*DAT_00b5ac7c + 8))(*(undefined1 *)(param_2 + 0x19));
  FUN_004e9d50();
  if (iVar2 == 0) {
    FUN_004ea770(0);
    pvVar3 = operator_new(0x10);
    if (pvVar3 == (void *)0x0) {
      FUN_004ea750(0);
      return;
    }
    param_1._0_2_ = 200;
    param_1._2_2_ = 0x65;
    uVar4 = FUN_004f5d20(&param_1,3000);
    FUN_004ea750(uVar4);
    return;
  }
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00509580();
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00509480();
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0x24);
  uVar4 = 0;
  if (pvVar3 != (void *)0x0) {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(&DAT_009b3918,0);
    uVar4 = FUN_004f8810(&local_20);
  }
  FUN_004ea750(uVar4);
  if ((pvVar3 != (void *)0x0) && (0xf < uStack_8)) {
    _free(pvStack_1c);
    return;
  }
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0050a0c0();
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0xc);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f58c0(DAT_00b5ad3c);
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f5970();
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0x1c);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00509df0(1,*(undefined4 *)(iVar2 + 4),
                         CONCAT22(extraout_var,*(undefined2 *)(iVar2 + 8)));
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005098f0();
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0xc);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f58c0(DAT_00b5ad40);
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005095b0();
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0xc);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f58c0(DAT_00b5ad44);
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f5970();
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    param_1._0_2_ = 100;
    param_1._2_2_ = 6;
    uVar4 = FUN_004f5d20(&param_1,0);
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f5b30();
  }
  FUN_004ea750(uVar4);
  *(undefined4 *)(iVar1 + 4) = 3;
  return;
}


// ==== FUN_004f6960 @ 0x004f6960 ====

void FUN_004f6960(undefined2 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined2 extraout_var;
  uint unaff_EBX;
  undefined2 uStack00000006;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar2 = param_2;
  local_20 = 0;
  iVar3 = (**(code **)(*DAT_00b5ac7c + 8))(*(undefined1 *)(param_2 + 0x19));
  FUN_004e9d50();
  if (iVar3 == 0) {
    FUN_004ea770(0);
    pvVar4 = operator_new(0x10);
    if (pvVar4 == (void *)0x0) {
      FUN_004ea750(0);
      return;
    }
    param_1 = 200;
    uStack00000006 = 0x65;
    uVar5 = FUN_004f5d20(&param_1,3000);
    FUN_004ea750(uVar5);
    return;
  }
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00509580();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00509480();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x24);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(&DAT_009b3919,0);
    unaff_EBX = 1;
    uVar5 = FUN_004f8810(&local_20);
  }
  FUN_004ea750(uVar5);
  if (((unaff_EBX & 1) != 0) && (unaff_EBX = unaff_EBX & 0xfffffffe, 0xf < uStack_8)) {
    _free(pvStack_1c);
    return;
  }
  pvVar4 = operator_new(0x10);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_0050a0c0();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0xc);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f58c0(DAT_00b5ad3c);
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f5970();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x1c);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00509df0(1,*(undefined4 *)(iVar3 + 4),
                         CONCAT22(extraout_var,*(undefined2 *)(iVar3 + 8)));
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x10);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005098f0();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0xc);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f58c0(DAT_00b5ad40);
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x10);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005095b0();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0xc);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f58c0(DAT_00b5ad44);
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_0050a420();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f5970();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0xc);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f58c0(DAT_00b5ad48);
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x24);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    pcVar6 = PTR_s_SceneLogin_00ae9f64;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneLogin_00ae9f64,(int)pcVar6 - (int)(PTR_s_SceneLogin_00ae9f64 + 1));
    unaff_EBX = unaff_EBX | 2;
    uVar5 = FUN_004f8810(&local_20);
  }
  FUN_004ea750(uVar5);
  if (((unaff_EBX & 2) == 0) || (uStack_8 < 0x10)) {
    *(undefined4 *)(iVar2 + 4) = 2;
    FUN_0065b720();
    FUN_0065b6c0();
    FUN_006ea710();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_004f6cd0 @ 0x004f6cd0 ====

void FUN_004f6cd0(undefined2 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined2 extraout_var;
  uint unaff_EBX;
  undefined2 uStack00000006;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar2 = param_2;
  local_20 = 0;
  iVar3 = (**(code **)(*DAT_00b5ac7c + 8))(*(undefined1 *)(param_2 + 0x19));
  FUN_004e9d50();
  if (iVar3 == 0) {
    FUN_004ea770(0);
    pvVar4 = operator_new(0x10);
    if (pvVar4 == (void *)0x0) {
      FUN_004ea750(0);
      return;
    }
    param_1 = 200;
    uStack00000006 = 0x65;
    uVar5 = FUN_004f5d20(&param_1,3000);
    FUN_004ea750(uVar5);
    return;
  }
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00509580();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00509480();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x24);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(&DAT_009b391a,0);
    unaff_EBX = 1;
    uVar5 = FUN_004f8810(&local_20);
  }
  FUN_004ea750(uVar5);
  if (((unaff_EBX & 1) != 0) && (unaff_EBX = unaff_EBX & 0xfffffffe, 0xf < uStack_8)) {
    _free(pvStack_1c);
    return;
  }
  pvVar4 = operator_new(0x10);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_0050a0c0();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0xc);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f58c0(DAT_00b5ad3c);
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f5970();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x1c);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_00509df0(1,*(undefined4 *)(iVar3 + 4),
                         CONCAT22(extraout_var,*(undefined2 *)(iVar3 + 8)));
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x10);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005098f0();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0xc);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_004f58c0(DAT_00b5ad40);
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(8);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_0050a420();
  }
  FUN_004ea750(uVar5);
  pvVar4 = operator_new(0x24);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    pcVar6 = PTR_s_SceneCharSelect_00ae9f6c;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneCharSelect_00ae9f6c,
                 (int)pcVar6 - (int)(PTR_s_SceneCharSelect_00ae9f6c + 1));
    unaff_EBX = unaff_EBX | 2;
    uVar5 = FUN_004f8810(&local_20);
  }
  FUN_004ea750(uVar5);
  if (((unaff_EBX & 2) == 0) || (uStack_8 < 0x10)) {
    *(undefined4 *)(iVar2 + 4) = 2;
    FUN_0065b720();
    FUN_0065b6c0();
    FUN_006ea710();
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_004f6fa0 @ 0x004f6fa0 ====

undefined4 FUN_004f6fa0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x50000006) {
    if (uVar1 == 0x50000005) {
      FUN_004f6cd0(param_1,param_2);
      return 1;
    }
    if (uVar1 == 0x50000003) {
      FUN_004f6680(param_1,param_2);
      return 1;
    }
    if (uVar1 == 0x50000004) {
      FUN_004f6960(param_1,param_2);
      return 1;
    }
  }
  else {
    if (uVar1 == 0x50000006) {
      FUN_004f63d0(param_1,param_2);
      return 1;
    }
    if (uVar1 == 0x80000003) {
      FUN_004ea8c0(1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004f7040 @ 0x004f7040 ====

undefined4 FUN_004f7040(void)

{
  return 0x50000005;
}


// ==== FUN_004f7050 @ 0x004f7050 ====

void FUN_004f7050(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad38 = 0;
  *in_ECX = &PTR_FUN_009b36fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f70a0 @ 0x004f70a0 ====

void FUN_004f70a0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  FUN_004ea770(0);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    FUN_004ea750(0);
    return;
  }
  uVar2 = FUN_004f5d20(param_1,3000);
  FUN_004ea750(uVar2);
  return;
}


// ==== FUN_004f70f0 @ 0x004f70f0 ====

void FUN_004f70f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3a44;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad3c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad3c = in_ECX;
  return;
}


// ==== FUN_004f7120 @ 0x004f7120 ====

undefined4 FUN_004f7120(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == -0x7ffffffd) {
    *(undefined4 *)(param_2 + 8) = 0;
    FUN_004ea770(1);
    return 1;
  }
  return 0;
}


// ==== FUN_004f7170 @ 0x004f7170 ====

void FUN_004f7170(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s____CHECKOUTED____Start_009b39e8,0x16);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f71c0 @ 0x004f71c0 ====

void FUN_004f71c0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined2 extraout_var;
  bool bVar7;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  bVar7 = false;
  local_20 = 0;
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00509580();
  }
  iVar2 = param_2;
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f5d20(param_1,3000);
  }
  FUN_004ea750(uVar4);
  iVar5 = (**(code **)(*DAT_00b5ac7c + 8))(*(undefined1 *)(iVar2 + 0x19));
  if (iVar5 == 0) {
    FUN_004ea770(0);
    pvVar3 = operator_new(0x10);
    if (pvVar3 == (void *)0x0) {
      FUN_004ea750(0);
      return;
    }
    param_1 = 0x6500c8;
    uVar4 = FUN_004f5d20(&param_1,3000);
    FUN_004ea750(uVar4);
    return;
  }
  if (*(int *)(iVar2 + 8) == 2) {
    pvVar3 = operator_new(8);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_004f5970();
    }
    FUN_004ea750(uVar4);
  }
  else if (*(int *)(iVar2 + 8) != 0) goto LAB_004f72e5;
  pvVar3 = operator_new(0x1c);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00509df0(1,*(undefined4 *)(iVar5 + 4),
                         CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 8)));
  }
  FUN_004ea750(uVar4);
LAB_004f72e5:
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005098f0();
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0xc);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f58c0(DAT_00b5ad40);
  }
  FUN_004ea750(uVar4);
  pvVar3 = operator_new(0x24);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    pcVar6 = PTR_s_SceneCharSelect_00aea06c;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneCharSelect_00aea06c,
                 (int)pcVar6 - (int)(PTR_s_SceneCharSelect_00aea06c + 1));
    bVar7 = true;
    uVar4 = FUN_004f8810(&local_20);
  }
  FUN_004ea750(uVar4);
  if ((bVar7) && (0xf < uStack_8)) {
    _free(pvStack_1c);
    return;
  }
  *(undefined4 *)(iVar2 + 4) = 2;
  return;
}


// ==== FUN_004f73c0 @ 0x004f73c0 ====

void FUN_004f73c0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar2 = param_2;
  FUN_004e9d50();
  iVar1 = *(int *)(iVar2 + 4);
  if (iVar1 == 1) {
    puVar5 = local_3c;
    uVar3 = (**(code **)(*param_1 + 0x10))(puVar5,iVar2);
    FUN_004f71c0(uVar3,puVar5);
    return;
  }
  if (iVar1 == 2) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(&DAT_009b3a00,0x23);
    FUN_00796d50(local_38);
    if (local_20 < 0x10) {
      puVar4 = &param_2;
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      uVar3 = (**(code **)(*param_1 + 0x10))(puVar4,iVar2);
      FUN_004f70a0(uVar3,puVar4);
      return;
    }
    _free(local_34);
    return;
  }
  if (iVar1 == 3) {
    FUN_004ea9d0(0);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009b3a24,0x1a);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f74e0 @ 0x004f74e0 ====

void FUN_004f74e0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad3c = 0;
  *in_ECX = &PTR_FUN_009b36fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f7510 @ 0x004f7510 ====

void FUN_004f7510(undefined4 param_1,int param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 8) = 0;
  FUN_004ea770(1);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    FUN_004ea750(0);
    return;
  }
  param_2 = 0xc800c8;
  uVar2 = FUN_004f5d20(&param_2,3000);
  FUN_004ea750(uVar2);
  return;
}


// ==== FUN_004f7570 @ 0x004f7570 ====

void FUN_004f7570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3b70;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad40 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad40 = in_ECX;
  return;
}


// ==== FUN_004f75c0 @ 0x004f75c0 ====

void FUN_004f75c0(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s____LOGINED____Start_009b3af8,0x13);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f7610 @ 0x004f7610 ====

void FUN_004f7610(int *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_74 [4];
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_004e9d50();
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 1) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(&DAT_009b3b0c,0x21);
    FUN_00796d50(local_38);
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_004e9d50();
    pvVar2 = operator_new(0x24);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      FUN_00401830(PTR_s_SceneCharSelect_00aea13c);
      uVar3 = FUN_004f8810(local_1c);
    }
    FUN_004ea750(uVar3);
    if (pvVar2 != (void *)0x0) {
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
    }
    pvVar2 = operator_new(0x10);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar4 = 3000;
      uVar3 = (**(code **)(*param_1 + 0x10))(local_74,3000);
      uVar3 = FUN_004f5d20(uVar3,uVar4);
    }
    FUN_004ea750(uVar3);
    *(undefined4 *)(param_2 + 4) = 0;
    return;
  }
  if (iVar1 == 2) {
    local_3c = 0xf;
    local_40 = 0;
    local_50 = (void *)((uint)local_50 & 0xffffff00);
    FUN_00401740(&DAT_009b3b30,0x1f);
    FUN_00796d50(local_54);
    if (local_3c < 0x10) {
      local_3c = 0xf;
      local_40 = 0;
      local_50 = (void *)((uint)local_50 & 0xffffff00);
      FUN_004ea770(0);
      return;
    }
    _free(local_50);
    return;
  }
  if (iVar1 == 3) {
    FUN_004ea9d0(0);
    return;
  }
  local_58 = 0xf;
  local_5c = 0;
  local_6c = (void *)((uint)local_6c & 0xffffff00);
  FUN_00401740(&DAT_009b3b50,0x1a);
  FUN_00796d50(local_70);
  if (local_58 < 0x10) {
    local_58 = 0xf;
    local_5c = 0;
    local_6c = (void *)((uint)local_6c & 0xffffff00);
    FUN_004ea770(0);
    return;
  }
  _free(local_6c);
  return;
}


// ==== FUN_004f7820 @ 0x004f7820 ====

void FUN_004f7820(undefined4 param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  bVar5 = false;
  FUN_004e9d50();
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    local_8 = 0;
    local_4 = 0xf;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar3 = PTR_s_SceneCharCreate_00aea140;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneCharCreate_00aea140,
                 (int)pcVar3 - (int)(PTR_s_SceneCharCreate_00aea140 + 1));
    bVar5 = true;
    uVar4 = FUN_004f8810(local_1c);
  }
  FUN_004ea750(uVar4);
  if ((bVar5) && (0xf < local_4)) {
    _free(local_18);
    return;
  }
  *(undefined4 *)(param_2 + 4) = 0;
  return;
}


// ==== FUN_004f78c0 @ 0x004f78c0 ====

void FUN_004f78c0(undefined4 param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  bVar5 = false;
  FUN_004e9d50();
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    local_8 = 0;
    local_4 = 0xf;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar3 = PTR_s_SceneCharSelect_00aea13c;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneCharSelect_00aea13c,
                 (int)pcVar3 - (int)(PTR_s_SceneCharSelect_00aea13c + 1));
    bVar5 = true;
    uVar4 = FUN_004f8810(local_1c);
  }
  FUN_004ea750(uVar4);
  if ((bVar5) && (0xf < local_4)) {
    _free(local_18);
    return;
  }
  *(undefined4 *)(param_2 + 4) = 0;
  return;
}


// ==== FUN_004f7960 @ 0x004f7960 ====

void FUN_004f7960(int param_1,int param_2)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined2 extraout_var;
  uint unaff_EBX;
  undefined1 uStack00000000;
  undefined4 local_20;
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar3 = param_2;
  puVar1 = (undefined1 *)(param_2 + 0x19);
  param_2._0_2_ = CONCAT11(*(undefined1 *)(param_1 + 4),*puVar1);
  local_20 = 0;
  iVar4 = (**(code **)(*DAT_00b5ac78 + 8))(&param_2);
  FUN_004e9d50();
  if (iVar4 == 0) {
    pvVar5 = operator_new(0x10);
    if (pvVar5 == (void *)0x0) {
      FUN_004ea750(0);
      *(undefined4 *)(iVar3 + 4) = 0;
      return;
    }
    uVar6 = FUN_004f5d20(&uStack00000000,3000);
    FUN_004ea750(uVar6);
    *(undefined4 *)(iVar3 + 4) = 0;
    return;
  }
  *(undefined1 *)(iVar3 + 0x7d) = *(undefined1 *)(param_1 + 4);
  pvVar5 = operator_new(0x2c);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0050bc20(param_1 + 8);
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(0xc);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_004f58c0(DAT_00b5ad3c);
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(8);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_004f5970();
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(0x24);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    FUN_00401740(&DAT_009b3b6b,0);
    unaff_EBX = 1;
    uVar6 = FUN_004f8810(&local_20);
  }
  FUN_004ea750(uVar6);
  if (((unaff_EBX & 1) != 0) && (unaff_EBX = unaff_EBX & 0xfffffffe, 0xf < uStack_8)) {
    _free(pvStack_1c);
    return;
  }
  pvVar5 = operator_new(0x1c);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00509df0(2,*(undefined4 *)(iVar4 + 4),
                         CONCAT22(extraout_var,*(undefined2 *)(iVar4 + 8)));
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(8);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0050a420();
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(8);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00509520();
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(0x10);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0050a900();
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(0xc);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_004f58c0(DAT_00b5ad38);
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(0xc);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0050a4d0();
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(0xc);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00508e60();
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(0x24);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uStack_8 = 0xf;
    uStack_c = 0;
    pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
    pcVar7 = PTR_s_SceneGame2_00aea148;
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    FUN_00401740(PTR_s_SceneGame2_00aea148,(int)pcVar7 - (int)(PTR_s_SceneGame2_00aea148 + 1));
    unaff_EBX = unaff_EBX | 2;
    uVar6 = FUN_004f8810(&local_20);
  }
  FUN_004ea750(uVar6);
  if (((unaff_EBX & 2) != 0) && (0xf < uStack_8)) {
    _free(pvStack_1c);
    return;
  }
  pvVar5 = operator_new(8);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00509580();
  }
  FUN_004ea750(uVar6);
  pvVar5 = operator_new(8);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0050a460();
  }
  FUN_004ea750(uVar6);
  *(undefined4 *)(iVar3 + 4) = 1;
  return;
}


// ==== FUN_004f7cb0 @ 0x004f7cb0 ====

void FUN_004f7cb0(undefined4 param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  bVar5 = false;
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar3 = PTR_s_SceneLogin_00aea134;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneLogin_00aea134,(int)pcVar3 - (int)(PTR_s_SceneLogin_00aea134 + 1));
    bVar5 = true;
    uVar4 = FUN_004f8810(local_1c);
  }
  FUN_004ea750(uVar4);
  if ((bVar5) && (0xf < local_4)) {
    _free(local_18);
    return;
  }
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005095b0();
  }
  FUN_004ea750(uVar4);
  pvVar2 = operator_new(0xc);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f58c0(DAT_00b5ad44);
  }
  FUN_004ea750(uVar4);
  pvVar2 = operator_new(8);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f5970();
  }
  FUN_004ea750(uVar4);
  pvVar2 = operator_new(0xc);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f58c0(DAT_00b5ad48);
  }
  FUN_004ea750(uVar4);
  *(undefined4 *)(param_2 + 4) = 2;
  return;
}


// ==== FUN_004f7de0 @ 0x004f7de0 ====

undefined4 FUN_004f7de0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x50010001) {
    if (uVar1 == 0x50010000) {
      FUN_004f7820(param_1,param_2);
      return 1;
    }
    if (uVar1 == 0x50000001) {
      FUN_004f7960(param_1,param_2);
      return 1;
    }
    if (uVar1 == 0x50000004) {
      FUN_004f7cb0(param_1,param_2);
      return 1;
    }
  }
  else {
    if (uVar1 == 0x50010001) {
      FUN_004f78c0(param_1,param_2);
      return 1;
    }
    if (uVar1 == 0x80000003) {
      FUN_004f7510(param_1,param_2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004f7e80 @ 0x004f7e80 ====

void FUN_004f7e80(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad40 = 0;
  *in_ECX = &PTR_FUN_009b36fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f7eb0 @ 0x004f7eb0 ====

void FUN_004f7eb0(undefined4 param_1,int param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_2 + 8) = 0;
  FUN_004ea770(1);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    FUN_004ea750(0);
    return;
  }
  param_2 = 0xc800c8;
  uVar2 = FUN_004f5d20(&param_2,3000);
  FUN_004ea750(uVar2);
  return;
}


// ==== FUN_004f7f10 @ 0x004f7f10 ====

void FUN_004f7f10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3c80;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad44 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad44 = in_ECX;
  return;
}


// ==== FUN_004f7f40 @ 0x004f7f40 ====

undefined4 FUN_004f7f40(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == -0x7ffffffd) {
    FUN_004f7eb0(param_1,param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_004f7f80 @ 0x004f7f80 ====

void FUN_004f7f80(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004f5d20(param_1,3000);
  }
  FUN_004ea750(uVar2);
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004f5970();
  }
  FUN_004ea750(uVar2);
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    FUN_004ea750(0);
    return;
  }
  uVar2 = FUN_004f58c0(DAT_00b5ad48);
  FUN_004ea750(uVar2);
  return;
}


// ==== FUN_004f8030 @ 0x004f8030 ====

void FUN_004f8030(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s____NOTLOGINED____Start_009b3c24,0x16);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f8080 @ 0x004f8080 ====

void FUN_004f8080(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar2 = param_2;
  FUN_004e9d50();
  iVar1 = *(int *)(iVar2 + 4);
  if (iVar1 == 1) {
    puVar4 = &param_2;
    uVar3 = (**(code **)(*param_1 + 0x10))(puVar4,iVar2);
    FUN_004f7f80(uVar3,puVar4);
    return;
  }
  if (iVar1 == 2) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(&DAT_009b3c3c,0x23);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_004ea770(1);
      return;
    }
    _free(local_18);
    return;
  }
  if (iVar1 == 3) {
    FUN_004ea9d0(0);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(&DAT_009b3c60,0x1a);
  FUN_00796d50(local_38);
  if (local_20 < 0x10) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_004ea770(1);
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_004f81a0 @ 0x004f81a0 ====

void FUN_004f81a0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad44 = 0;
  *in_ECX = &PTR_FUN_009b36fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f81d0 @ 0x004f81d0 ====

void FUN_004f81d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3d94;
  *(undefined1 *)(in_ECX + 1) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad48 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad48 = in_ECX;
  return;
}


// ==== FUN_004f8220 @ 0x004f8220 ====

void FUN_004f8220(int param_1)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  bool bVar5;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  bVar5 = false;
  *(undefined1 *)(in_ECX + 4) = 0;
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar3 = PTR_s_SceneLogin_00aea2cc;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneLogin_00aea2cc,(int)pcVar3 - (int)(PTR_s_SceneLogin_00aea2cc + 1));
    bVar5 = true;
    uVar4 = FUN_004f8810(local_1c);
  }
  FUN_004ea750(uVar4);
  if ((bVar5) && (0xf < local_4)) {
    _free(local_18);
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s____NOTCONNECTED____Start_009b3d34,0x18);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f8310 @ 0x004f8310 ====

void FUN_004f8310(int *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = param_2;
  FUN_004e9d50();
  if (*(int *)(iVar1 + 4) == 1) {
    *(undefined1 *)(in_ECX + 4) = 0;
    pvVar2 = operator_new(0x10);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar4 = 3000;
      uVar3 = (**(code **)(*param_1 + 0x10))(&param_2,3000);
      uVar3 = FUN_004f5d20(uVar3,uVar4);
    }
    FUN_004ea750(uVar3);
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(&DAT_009b3d50,0x22);
    FUN_00796d50(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  else {
    if (*(int *)(iVar1 + 4) == 3) {
      FUN_004ea9d0(0);
      return;
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(&DAT_009b3d74,0x1a);
    FUN_00796d50(local_38);
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
  }
  return;
}


// ==== FUN_004f8420 @ 0x004f8420 ====

void FUN_004f8420(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined2 extraout_var;
  undefined1 uStack00000000;
  byte bStack_24;
  undefined4 local_20;
  void *pvStack_1c;
  uint uStack_8;
  
  local_20 = 0;
  if (*(char *)(in_ECX + 4) == '\0') {
    iVar1 = (**(code **)(*DAT_00b5ac7c + 8))(*(undefined1 *)(param_1 + 9));
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 4);
    *(undefined1 *)(param_1 + 0x18) = *(undefined1 *)(param_1 + 8);
    *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_1 + 9);
    FUN_00401660(param_1 + 0xc,0,0xffffffff);
    FUN_00401660(param_1 + 0x28,0,0xffffffff);
    FUN_004e9d50();
    if (iVar1 == 0) {
      FUN_004ea770(0);
      pvVar2 = operator_new(0x10);
      if (pvVar2 == (void *)0x0) {
        FUN_004ea750(0);
        return;
      }
      uVar3 = FUN_004f5d20(&uStack00000000,3000);
      FUN_004ea750(uVar3);
      return;
    }
    iVar4 = _rand();
    *(undefined1 *)(in_ECX + 4) = 1;
    pvVar2 = operator_new(0x10);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004f5d20(&uStack00000000,0);
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0x10);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004f5bd0(iVar4 % 1000);
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0x1c);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_00509df0(1,*(undefined4 *)(iVar1 + 4),
                           CONCAT22(extraout_var,*(undefined2 *)(iVar1 + 8)));
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0xc);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004f58c0(DAT_00b5ad44);
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0x10);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004f5d20(&uStack00000000,0);
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0x4c);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_0050c4d0(param_1 + 0xc,param_1 + 0x28,*(undefined4 *)(param_1 + 4));
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0x10);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004f5d20(&uStack00000000,0);
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0x14);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_0050c2f0(&uStack00000000,2000);
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0xc);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004f58c0(DAT_00b5ad40);
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(8);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_0050a420();
    }
    FUN_004ea750(uVar3);
    pvVar2 = operator_new(0x24);
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      FUN_00401830(PTR_s_SceneCharSelect_00aea2d4);
      bStack_24 = 1;
      uVar3 = FUN_004f8810(&local_20);
    }
    FUN_004ea750(uVar3);
    if (((bStack_24 & 1) != 0) && (0xf < uStack_8)) {
      _free(pvStack_1c);
      return;
    }
    *(undefined4 *)(param_1 + 4) = 1;
  }
  return;
}


// ==== FUN_004f8740 @ 0x004f8740 ====

undefined4 FUN_004f8740(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x50000000) {
    FUN_004f8420(param_1,param_2);
    return 1;
  }
  return 0;
}


// ==== FUN_004f8780 @ 0x004f8780 ====

void FUN_004f8780(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad48 = 0;
  *in_ECX = &PTR_FUN_009b36fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f87b0 @ 0x004f87b0 ====

undefined1 FUN_004f87b0(void)

{
  return 0;
}


// ==== FUN_004f87c0 @ 0x004f87c0 ====

undefined4 FUN_004f87c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x20);
}


// ==== FUN_004f87d0 @ 0x004f87d0 ====

void FUN_004f87d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3de0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009b358c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004f8810 @ 0x004f8810 ====

void FUN_004f8810(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3de0;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[8] = 0;
  return;
}


// ==== FUN_004f8850 @ 0x004f8850 ====

void FUN_004f8850(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  FUN_00401740(s_>>_SELECTSCENECMD____s_Start_009b3da8,0x20);
  uVar1 = FUN_00404230(local_1c);
  FUN_00796d50(uVar1);
  if (local_4 < 0x10) {
    FUN_004ea350(in_ECX + 4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004f88d0 @ 0x004f88d0 ====

void FUN_004f88d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b3de0;
  if (0xf < (uint)in_ECX[7]) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = &PTR_FUN_009b358c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004f8920 @ 0x004f8920 ====

undefined4 FUN_004f8920(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_004f8970 @ 0x004f8970 ====

void FUN_004f8970(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_64 [24];
  char cStack_1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar4 = auStack_64;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar4 = puVar4 + 1;
  }
  if (cStack_1 != '\0') {
    (**(code **)(*DAT_00b5a838 + 0xc))(0);
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 0x20) = uVar2;
  }
  return;
}


// ==== FUN_004f89c0 @ 0x004f89c0 ====

void FUN_004f89c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b42ec;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((void *)in_ECX[4] == (void *)0x0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    *in_ECX = &PTR_FUN_009b358c;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_004f8a00 @ 0x004f8a00 ====

void FUN_004f8a00(undefined4 param_1,int param_2)

{
  void *_Src;
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  
  piVar6 = DAT_00b5a6ac;
  if ((*(int *)(in_ECX + 0x10) == 0) ||
     (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10) >> 2 == 0)) {
    (**(code **)(**(int **)(param_2 + 0xac) + 0xc))(0);
    *(undefined4 *)(in_ECX + 4) = 1;
    (**(code **)(*DAT_00b5a838 + 0x10))();
    return;
  }
  if (*(int *)(in_ECX + 0x20) != 0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a838 + 4))(0);
    iVar3 = (**(code **)(*piVar6 + 0x18))();
    iVar5 = *(int *)(in_ECX + 0x20);
    uVar4 = (**(code **)(*piVar2 + 0xc))();
    if (uVar4 < (uint)(iVar3 - iVar5)) {
      (**(code **)(*DAT_00b5a838 + 0x10))();
      *(undefined4 *)(in_ECX + 0x20) = 0;
    }
  }
  iVar5 = (**(code **)(*DAT_00b5a6ac + 0x24))();
  piVar6 = (int *)**(undefined4 **)(in_ECX + 0x10);
  cVar1 = (**(code **)(*piVar6 + 4))();
  if (cVar1 != '\0') {
    while( true ) {
      (**(code **)*piVar6)(1);
      _Src = (void *)((int)*(void **)(in_ECX + 0x10) + 4);
      _memmove(*(void **)(in_ECX + 0x10),_Src,(*(int *)(in_ECX + 0x14) - (int)_Src >> 2) * 4);
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + -4;
      if (((*(int *)(in_ECX + 0x10) == 0) ||
          (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10) >> 2 == 0)) ||
         (iVar3 = (**(code **)(*DAT_00b5a6ac + 0x24))(), 0x1e < (uint)(iVar3 - iVar5))) break;
      piVar6 = (int *)**(undefined4 **)(in_ECX + 0x10);
      cVar1 = (**(code **)(*piVar6 + 4))();
      if (cVar1 == '\0') {
        return;
      }
    }
    if (*(int *)(in_ECX + 0x10) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10) >> 2;
    }
    if (uVar4 <= *(uint *)(in_ECX + 8)) {
      FUN_0065bf90(*(uint *)(in_ECX + 8) - uVar4);
    }
  }
  return;
}


// ==== FUN_004f8b50 @ 0x004f8b50 ====

uint FUN_004f8b50(int *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_004f8a00(param_1,param_2);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004f8b80 @ 0x004f8b80 ====

void FUN_004f8b80(undefined4 param_1,undefined1 param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *unaff_ESI;
  undefined1 local_1c [2];
  undefined1 auStack_1a [2];
  void *local_18;
  uint uStack_c;
  uint local_4;
  
  uVar1 = FUN_00402220(local_1c,param_1,s_Loading____009b4214);
  FUN_00796d50(uVar1);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)FUN_0081d3a0(param_1);
  }
  (**(code **)(*DAT_00b5a9fc + 4))(&param_2,puVar3);
  uVar1 = FUN_00402220(local_1c + -8,param_1,s_Loading_OK_009b4220);
  FUN_00796d50(uVar1);
  if (0xf < uStack_c) {
    _free(unaff_ESI);
    return;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  return;
}


// ==== FUN_004f8c30 @ 0x004f8c30 ====

void FUN_004f8c30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b42ec;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  return;
}


// ==== FUN_004f8c50 @ 0x004f8c50 ====

void FUN_004f8c50(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_Action_list_csv_009b422c,0xf);
  FUN_004f8b80(local_38,2);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  uVar2 = FUN_0048ae60();
  iVar5 = 0;
  local_3c = uVar2;
  if ((short)uVar2 != 0) {
    do {
      iVar3 = FUN_0048ae70(iVar5);
      if (iVar3 != 0) {
        local_20 = 0xf;
        local_24 = 0;
        local_34 = (void *)((uint)local_34 & 0xffffff00);
        FUN_00401740(s_Action__009b423c,7);
        FUN_00402220(local_1c,local_38,iVar3);
        if (0xf < local_20) {
          _free(local_34);
          return;
        }
        local_20 = 0xf;
        local_24 = 0;
        local_34 = (void *)((uint)local_34 & 0xffffff00);
        pvVar4 = operator_new(0x28);
        if (pvVar4 == (void *)0x0) {
          local_44 = 0;
        }
        else {
          local_44 = FUN_0050cdf0(0x10,local_1c,1);
        }
        iVar3 = *(int *)(local_40 + 0x10);
        if ((iVar3 == 0) ||
           ((uint)(*(int *)(local_40 + 0x18) - iVar3 >> 2) <=
            (uint)(*(int *)(local_40 + 0x14) - iVar3 >> 2))) {
          FUN_004fb070(*(undefined4 *)(local_40 + 0x14),1,&local_44);
        }
        else {
          puVar1 = *(undefined4 **)(local_40 + 0x14);
          *puVar1 = local_44;
          *(undefined4 **)(local_40 + 0x14) = puVar1 + 1;
        }
        if (0xf < local_4) {
          _free(local_18);
          return;
        }
        local_4 = 0xf;
        local_8 = 0;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        uVar2 = local_3c;
      }
      iVar5 = iVar5 + 1;
    } while ((ushort)iVar5 < (ushort)uVar2);
  }
  return;
}


// ==== FUN_004f8de0 @ 0x004f8de0 ====

void FUN_004f8de0(void)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  int iVar4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_Quest_QuestFileList_csv_009b4244,0x17);
  FUN_004f8b80(local_38,0);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_3c = FUN_0048b0d0();
  iVar4 = 0;
  if ((short)local_3c != 0) {
    do {
      iVar2 = FUN_0048b0e0(iVar4);
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      FUN_00401740(s_Quest__009b425c,6);
      FUN_00402220(local_1c,local_38,iVar2 + 2);
      if (0xf < local_20) {
        _free(local_34);
        return;
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      pvVar3 = operator_new(0x28);
      if (pvVar3 == (void *)0x0) {
        local_40 = 0;
      }
      else {
        local_40 = FUN_0050cdf0(0xc,local_1c,1);
      }
      iVar2 = *(int *)(in_ECX + 0x10);
      if ((iVar2 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x18) - iVar2 >> 2) <=
          (uint)(*(int *)(in_ECX + 0x14) - iVar2 >> 2))) {
        FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_40);
      }
      else {
        puVar1 = *(undefined4 **)(in_ECX + 0x14);
        *puVar1 = local_40;
        *(undefined4 **)(in_ECX + 0x14) = puVar1 + 1;
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      iVar4 = iVar4 + 1;
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
    } while ((ushort)iVar4 < (ushort)local_3c);
  }
  return;
}


// ==== FUN_004f8f60 @ 0x004f8f60 ====

void FUN_004f8f60(void)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  int in_ECX;
  int iVar4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  FUN_00401740(s_Dungeon_DungeonFileList_csv_009b4264,0x1b);
  FUN_004f8b80(local_38,3);
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_3c = FUN_0048aa40();
  iVar4 = 0;
  if ((short)local_3c != 0) {
    do {
      iVar2 = FUN_0048aa50(iVar4);
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      FUN_00401740(s_Dungeon__009b4280,8);
      FUN_00402220(local_1c,local_38,iVar2 + 2);
      if (0xf < local_20) {
        _free(local_34);
        return;
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      pvVar3 = operator_new(0x28);
      if (pvVar3 == (void *)0x0) {
        local_40 = 0;
      }
      else {
        local_40 = FUN_0050cdf0(0x1c,local_1c,1);
      }
      iVar2 = *(int *)(in_ECX + 0x10);
      if ((iVar2 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x18) - iVar2 >> 2) <=
          (uint)(*(int *)(in_ECX + 0x14) - iVar2 >> 2))) {
        FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_40);
      }
      else {
        puVar1 = *(undefined4 **)(in_ECX + 0x14);
        *puVar1 = local_40;
        *(undefined4 **)(in_ECX + 0x14) = puVar1 + 1;
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      iVar4 = iVar4 + 1;
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
    } while ((ushort)iVar4 < (ushort)local_3c);
  }
  return;
}


// ==== FUN_004f90e0 @ 0x004f90e0 ====

void FUN_004f90e0(void)

{
  char cVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  undefined1 auStack_130 [4];
  undefined1 auStack_128 [4];
  void *pvStack_124;
  undefined4 uStack_114;
  uint uStack_110;
  undefined4 auStack_10c [66];
  
  (**(code **)(*DAT_00b5a6b0 + 0x10))(0);
  uStack_110 = 0xf;
  uStack_114 = 0;
  pvStack_124 = (void *)((uint)pvStack_124 & 0xffffff00);
  FUN_00401740(s_Skill_SkillTable_csv_009b428c,0x14);
  FUN_004f8b80(auStack_128,1);
  if (0xf < uStack_110) {
    _free(pvStack_124);
    return;
  }
  (**(code **)(*DAT_00b5a688 + 0x48))();
  cVar1 = (**(code **)(*DAT_00b5aa30 + 0x18))();
  while( true ) {
    if (cVar1 != '\x01') {
      (**(code **)(*DAT_00b5a6b0 + 0x14))();
      (**(code **)(*DAT_00b5a688 + 0x48))();
      return;
    }
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5aa30 + 0x20))();
    puVar6 = auStack_10c;
    for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar6 = puVar6 + 1;
    }
    FUN_00401740(&DAT_009b42ac,4);
    FUN_00404230(auStack_128);
    pvVar3 = operator_new(0x28);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_0050cdf0(9,auStack_128,1);
    }
    iVar5 = *(int *)(in_ECX + 0x10);
    if ((iVar5 == 0) ||
       ((uint)(*(int *)(in_ECX + 0x18) - iVar5 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar5 >> 2)
       )) {
      FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,auStack_130 + 4);
    }
    else {
      puVar2 = *(undefined4 **)(in_ECX + 0x14);
      *puVar2 = uVar4;
      *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
    }
    cVar1 = (**(code **)(*DAT_00b5aa30 + 0x1c))();
    if (0xf < uStack_110) break;
    uStack_110 = 0xf;
    uStack_114 = 0;
    pvStack_124 = (void *)((uint)pvStack_124 & 0xffffff00);
  }
  _free(pvStack_124);
  return;
}


// ==== FUN_004f9290 @ 0x004f9290 ====

void FUN_004f9290(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  int in_ECX;
  char *pcVar10;
  uint unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int iVar11;
  byte ****ppppbVar12;
  byte *pbVar13;
  bool bVar14;
  bool bVar15;
  undefined4 local_b0;
  byte ****ppppbStack_a4;
  byte ***local_a0;
  int iStack_94;
  uint uStack_90;
  undefined1 auStack_8c [4];
  void *pvStack_88;
  void *pvStack_84;
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 uStack_78;
  uint uStack_74;
  uint uStack_70;
  void *pvStack_6c;
  uint local_68;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined1 local_48 [12];
  undefined4 uStack_3c;
  uint uStack_38;
  byte ***local_2c;
  undefined1 local_28 [4];
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(&DAT_009b42b4,3);
  FUN_00402220(local_48,local_1c,s_PatternInfo_csv_009b42b8);
  uVar4 = FUN_00402220(local_80,local_48,s_Loading____009b42c8);
  FUN_00796d50(uVar4);
  if (0xf < local_68) {
    _free(local_7c);
    return;
  }
  pvVar5 = operator_new(0x10);
  if (pvVar5 == (void *)0x0) {
    local_a0 = (byte ***)0x0;
  }
  else {
    local_a0 = (byte ***)FUN_0081d3a0(local_48);
  }
  ppppbVar12 = (byte ****)local_a0;
  local_2c = local_a0;
  local_28[0] = 0x2c;
  local_24 = 0xff;
  local_20 = (void *)0x0;
  piVar6 = (int *)(**(code **)(*DAT_00b5a6f0 + 4))(&local_2c);
  iVar11 = 1;
  iVar7 = (**(code **)(*piVar6 + 4))();
  local_b0 = in_ECX;
  if (1 < iVar7) {
    do {
      pcVar8 = (char *)(**(code **)(*piVar6 + 0xc))(iVar11,0);
      uStack_90 = 0xf;
      iStack_94 = 0;
      ppppbStack_a4 = (byte ****)((uint)ppppbStack_a4 & 0xffffff00);
      pcVar10 = pcVar8;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar8,(int)pcVar10 - (int)(pcVar8 + 1));
      if (iStack_94 == 0) {
LAB_004f93f9:
        if (iStack_94 != 0) goto LAB_004f942b;
        if (0xf < uStack_90) {
          _free(ppppbStack_a4);
          return;
        }
      }
      else {
        ppppbVar12 = ppppbStack_a4;
        if (uStack_90 < 0x10) {
          ppppbVar12 = (byte ****)&ppppbStack_a4;
        }
        iVar7 = 0;
        bVar14 = false;
        iVar11 = 0;
        bVar15 = true;
        pbVar13 = &DAT_009b42d4;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar14 = *(byte *)ppppbVar12 < *pbVar13;
          bVar15 = *(byte *)ppppbVar12 == *pbVar13;
          ppppbVar12 = (byte ****)((int)ppppbVar12 + 1);
          pbVar13 = pbVar13 + 1;
        } while (bVar15);
        if (!bVar15) {
          iVar11 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
        }
        if (iVar11 == 0) goto LAB_004f93f9;
LAB_004f942b:
        uVar4 = FUN_0044ab50(local_b0,0);
        pcVar8 = (char *)(**(code **)(*piVar6 + 0xc))(local_b0,1);
        uStack_58 = 0xf;
        uStack_5c = 0;
        pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
        pcVar10 = pcVar8;
        do {
          cVar1 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar1 != '\0');
        FUN_00401740(pcVar8,(int)pcVar10 - (int)(pcVar8 + 1));
        pvVar5 = operator_new(0x24);
        if (pvVar5 == (void *)0x0) {
          unaff_ESI = 0;
        }
        else {
          unaff_EBX = unaff_EBX | 1;
          uVar9 = FUN_00405bd0(auStack_8c,local_28,&uStack_70);
          unaff_ESI = FUN_0050d230(uVar4,uVar9);
        }
        iVar7 = *(int *)(unaff_EBP + 0x10);
        if ((iVar7 == 0) ||
           ((uint)(*(int *)(unaff_EBP + 0x18) - iVar7 >> 2) <=
            (uint)(*(int *)(unaff_EBP + 0x14) - iVar7 >> 2))) {
          FUN_004fb070(*(undefined4 *)(unaff_EBP + 0x14),1,auStack_8c + -0x2c);
        }
        else {
          piVar2 = *(int **)(unaff_EBP + 0x14);
          *piVar2 = unaff_ESI;
          *(int **)(unaff_EBP + 0x14) = piVar2 + 1;
        }
        if ((unaff_EBX & 1) != 0) {
          unaff_EBX = 0;
          if (0xf < uStack_74) {
            _free(pvStack_88);
            return;
          }
          uStack_74 = 0xf;
          uStack_78 = 0;
          pvStack_88 = (void *)((uint)pvStack_88 & 0xffffff00);
        }
        if (0xf < uStack_58) {
          _free(pvStack_6c);
          return;
        }
        uStack_58 = 0xf;
        uStack_5c = 0;
        pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
        if (0xf < uStack_90) {
          _free(ppppbStack_a4);
          return;
        }
      }
      uStack_90 = 0xf;
      iStack_94 = 0;
      iVar11 = local_b0 + 1;
      ppppbStack_a4 = (byte ****)((uint)ppppbStack_a4 & 0xffffff00);
      iVar7 = (**(code **)(*piVar6 + 4))();
      local_b0 = iVar11;
    } while (iVar11 < iVar7);
    ppppbVar12 = ppppbStack_a4;
  }
  (**(code **)(*DAT_00b5a6f0 + 8))(piVar6);
  if (ppppbVar12 != (byte ****)0x0) {
    (*(code *)**ppppbVar12)(1);
  }
  uVar4 = FUN_00402220(&pvStack_88,auStack_50,s_Loading_OK_009b42d8);
  FUN_00796d50(uVar4);
  if (0xf < uStack_70) {
    _free(pvStack_84);
    return;
  }
  pvVar5 = operator_new(4);
  if (pvVar5 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0050d0c0();
  }
  iVar7 = *(int *)(unaff_ESI + 0x10);
  if ((iVar7 == 0) ||
     ((uint)(*(int *)(unaff_ESI + 0x18) - iVar7 >> 2) <=
      (uint)(*(int *)(unaff_ESI + 0x14) - iVar7 >> 2))) {
    FUN_004fb070(*(undefined4 *)(unaff_ESI + 0x14),1,auStack_8c + -0x28);
  }
  else {
    puVar3 = *(undefined4 **)(unaff_ESI + 0x14);
    *puVar3 = uVar4;
    *(undefined4 **)(unaff_ESI + 0x14) = puVar3 + 1;
  }
  pvVar5 = operator_new(4);
  if (pvVar5 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0050cf80();
  }
  iVar7 = *(int *)(unaff_ESI + 0x10);
  if ((iVar7 == 0) ||
     ((uint)(*(int *)(unaff_ESI + 0x18) - iVar7 >> 2) <=
      (uint)(*(int *)(unaff_ESI + 0x14) - iVar7 >> 2))) {
    FUN_004fb070(*(undefined4 *)(unaff_ESI + 0x14),1,auStack_8c + -0x2c);
  }
  else {
    puVar3 = *(undefined4 **)(unaff_ESI + 0x14);
    *puVar3 = uVar4;
    *(undefined4 **)(unaff_ESI + 0x14) = puVar3 + 1;
  }
  if (0xf < uStack_38) {
    _free(pvStack_4c);
    return;
  }
  uStack_3c = 0;
  uStack_38 = 0xf;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  if (uStack_c < 0x10) {
    return;
  }
  _free(local_20);
  return;
}


// ==== FUN_004f9710 @ 0x004f9710 ====

uint FUN_004f9710(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  uint extraout_EAX_02;
  uint extraout_EAX_03;
  uint extraout_EAX_04;
  uint extraout_EAX_05;
  uint extraout_EAX_06;
  uint extraout_EAX_07;
  uint extraout_EAX_08;
  uint extraout_EAX_09;
  uint extraout_EAX_10;
  uint extraout_EAX_11;
  uint extraout_EAX_12;
  uint extraout_EAX_13;
  uint extraout_EAX_14;
  uint extraout_EAX_15;
  uint extraout_EAX_16;
  uint extraout_EAX_17;
  uint extraout_EAX_18;
  uint extraout_EAX_19;
  uint extraout_EAX_20;
  uint extraout_EAX_21;
  uint extraout_EAX_22;
  uint extraout_EAX_23;
  uint extraout_EAX_24;
  uint extraout_EAX_25;
  uint extraout_EAX_26;
  uint extraout_EAX_27;
  uint extraout_EAX_28;
  uint extraout_EAX_29;
  uint extraout_EAX_30;
  uint extraout_EAX_31;
  uint extraout_EAX_32;
  uint extraout_EAX_33;
  uint extraout_EAX_34;
  uint extraout_EAX_35;
  uint extraout_EAX_36;
  uint extraout_EAX_37;
  uint extraout_EAX_38;
  uint extraout_EAX_39;
  uint extraout_EAX_40;
  uint extraout_EAX_41;
  uint extraout_EAX_42;
  uint extraout_EAX_43;
  uint extraout_EAX_44;
  uint extraout_EAX_45;
  uint extraout_EAX_46;
  int in_ECX;
  byte bVar7;
  uint uVar6;
  int iVar8;
  undefined4 local_28;
  int local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_20 = 0;
  local_24 = in_ECX;
  pvVar4 = operator_new(0x14);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_0050f0d0();
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar5;
  FUN_0050f180(1000);
  *(undefined4 *)(in_ECX + 4) = 0;
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_28 = FUN_0050ef40();
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  FUN_004f8c50();
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_String_SkillName_csv_009b3df8,0x14);
    local_28 = FUN_0050ee10(0,local_1c);
  }
  bVar3 = pvVar4 != (void *)0x0;
  uVar6 = (uint)bVar3;
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if ((bVar3) && (uVar6 = 0, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_String_SkillDesc_csv_009b3e10,0x14);
    uVar6 = uVar6 | 2;
    local_28 = FUN_0050ee10(1,local_1c);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 2) != 0) && (uVar6 = uVar6 & 0xfffffffd, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_00;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Fishing_Fish_csv_009b3e28,0x10);
    uVar6 = uVar6 | 4;
    local_28 = FUN_0050cdf0(0x17,local_1c,1);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 4) != 0) && (uVar6 = uVar6 & 0xfffffffb, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_01;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Fishing_FishingRod_csv_009b3e3c,0x16);
    uVar6 = uVar6 | 8;
    local_28 = FUN_0050cdf0(0x18,local_1c,1);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 8) != 0) && (uVar6 = uVar6 & 0xfffffff7, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_02;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Fishing_FishingSkill_csv_009b3e54,0x18);
    uVar6 = uVar6 | 0x10;
    local_28 = FUN_0050cdf0(0x19,local_1c,1);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 0x10) != 0) && (uVar6 = uVar6 & 0xffffffef, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_03;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Item_ItemArmor_csv_009b3e70,0x12);
    uVar6 = uVar6 | 0x20;
    local_28 = FUN_0050cdf0(1,local_1c,0);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 0x20) != 0) && (uVar6 = uVar6 & 0xffffffdf, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_04;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Item_ItemCash_csv_009b3e84,0x11);
    uVar6 = uVar6 | 0x40;
    local_28 = FUN_0050cdf0(1,local_1c,0);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 0x40) != 0) && (uVar6 = uVar6 & 0xffffffbf, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_05;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Item_ItemEtc_csv_009b3e98,0x10);
    uVar6 = uVar6 | 0x80;
    local_28 = FUN_0050cdf0(1,local_1c,0);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((char)uVar6 < '\0') && (uVar6 = uVar6 & 0xffffff7f, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_06;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Item_ItemWeapon_csv_009b3eac,0x13);
    uVar6 = uVar6 | 0x100;
    local_28 = FUN_0050cdf0(1,local_1c,0);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 0x100) != 0) && (uVar6 = uVar6 & 0xfffffeff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_07;
  }
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_28 = FUN_0050ed10();
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Item_ItemStatus_csv_009b3ec0,0x13);
    uVar6 = uVar6 | 0x200;
    local_28 = FUN_0050cdf0(0x15,local_1c,0);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 0x200) != 0) && (uVar6 = uVar6 & 0xfffffdff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_08;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Item_ItemOption_Etc_csv_009b3ed4,0x17);
    uVar6 = uVar6 | 0x400;
    local_28 = FUN_0050cdf0(3,local_1c,0);
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x18) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2)))
  {
    FUN_004fb070(*(undefined4 *)(in_ECX + 0x14),1,&local_28);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x14);
    *puVar2 = local_28;
    *(undefined4 **)(in_ECX + 0x14) = puVar2 + 1;
  }
  if (((uVar6 & 0x400) != 0) && (uVar6 = uVar6 & 0xfffffbff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_09;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Item_ItemOption_Armor_csv_009b3eec);
    uVar6 = uVar6 | 0x800;
    local_28 = FUN_0050cdf0(3,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x800) != 0) && (uVar6 = uVar6 & 0xfffff7ff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_10;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Item_ItemOption_Weapon_csv_009b3f08);
    uVar6 = uVar6 | 0x1000;
    local_28 = FUN_0050cdf0(3,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x1000) != 0) && (uVar6 = uVar6 & 0xffffefff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_11;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Item_itemset_csv_009b3f24);
    uVar6 = uVar6 | 0x2000;
    local_28 = FUN_0050cdf0(4,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x2000) != 0) && (uVar6 = uVar6 & 0xffffdfff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_12;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Item_itemsocket_csv_009b3f38);
    uVar6 = uVar6 | 0x4000;
    local_28 = FUN_0050cdf0(5,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x4000) != 0) && (uVar6 = uVar6 & 0xffffbfff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_13;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_item_slotitem_csv_009b3f4c);
    uVar6 = uVar6 | 0x8000;
    local_28 = FUN_0050cdf0(0x16,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((char)(uVar6 >> 8) < '\0') && (uVar6 = uVar6 & 0xffff7fff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_14;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Item_shopset_csv_009b3f60);
    uVar6 = uVar6 | 0x10000;
    local_28 = FUN_0050cdf0(0x11,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x10000) != 0) && (uVar6 = uVar6 & 0xfffeffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_15;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Item_Shop_csv_009b3f74);
    uVar6 = uVar6 | 0x20000;
    local_28 = FUN_0050cdf0(10,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x20000) != 0) && (uVar6 = uVar6 & 0xfffdffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_16;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_PC_exp_csv_009b3f84);
    uVar6 = uVar6 | 0x40000;
    local_28 = FUN_0050cdf0(6,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x40000) != 0) && (uVar6 = uVar6 & 0xfffbffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_17;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_PC_Chaotic_csv_009b3f90);
    uVar6 = uVar6 | 0x80000;
    local_28 = FUN_0050cdf0(0x12,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x80000) != 0) && (uVar6 = uVar6 & 0xfff7ffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_18;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Quest_questtable_csv_009b3fa0);
    uVar6 = uVar6 | 0x100000;
    local_28 = FUN_0050cdf0(0xb,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x100000) != 0) && (uVar6 = uVar6 & 0xffefffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_19;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_PC_PCClass_csv_009b3fb8);
    uVar6 = uVar6 | 0x200000;
    local_28 = FUN_0050cdf0(7,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x200000) != 0) && (uVar6 = uVar6 & 0xffdfffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_20;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Skill_statuseffect_csv_009b3fc8);
    uVar6 = uVar6 | 0x400000;
    local_28 = FUN_0050cdf0(0xe,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x400000) != 0) && (uVar6 = uVar6 & 0xffbfffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_21;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Skill_status_csv_009b3fe0);
    uVar6 = uVar6 | 0x800000;
    local_28 = FUN_0050cdf0(0xd,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x800000) != 0) && (uVar6 = uVar6 & 0xff7fffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_22;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Request_Quest_Quest_Office_csv_009b3ff4);
    uVar6 = uVar6 | 0x1000000;
    local_28 = FUN_0050cdf0(0x1a,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x1000000) != 0) && (uVar6 = uVar6 & 0xfeffffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_23;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Request_Quest_Office_Set_csv_009b4014);
    uVar6 = uVar6 | 0x2000000;
    local_28 = FUN_0050cdf0(0x1b,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x2000000) != 0) && (uVar6 = uVar6 & 0xfdffffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_24;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Vehicle_Vehicle_csv_009b4034);
    uVar6 = uVar6 | 0x4000000;
    local_28 = FUN_0050cdf0(0x1d,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x4000000) != 0) && (uVar6 = uVar6 & 0xfbffffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_25;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Observer_Info_csv_009b4048);
    uVar6 = uVar6 | 0x8000000;
    local_28 = FUN_0050cdf0(0x1e,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x8000000) != 0) && (uVar6 = uVar6 & 0xf7ffffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_26;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Creature_monster_csv_009b405c);
    uVar6 = uVar6 | 0x10000000;
    local_28 = FUN_0050eb50(0,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x10000000) != 0) && (uVar6 = uVar6 & 0xefffffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_27;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Creature_Servant_csv_009b4074);
    uVar6 = uVar6 | 0x20000000;
    local_28 = FUN_0050eb50(3,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x20000000) != 0) && (uVar6 = uVar6 & 0xdfffffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_28;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Creature_Guard_csv_009b408c);
    uVar6 = uVar6 | 0x40000000;
    local_28 = FUN_0050eb50(4,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 0x40000000) != 0) && (uVar6 = uVar6 & 0xbfffffff, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_29;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Creature_npc_csv_009b40a0);
    uVar6 = uVar6 | 0x80000000;
    local_28 = FUN_0050eb50(1,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((int)uVar6 < 0) && (0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_30;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
    uVar6 = local_20;
  }
  else {
    FUN_00401830(s_Creature_remote_csv_009b40b4);
    local_28 = FUN_0050eb50(2,local_1c,1);
    uVar6 = 1;
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 1) != 0) && (uVar6 = uVar6 & 0xfffffffe, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_31;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Creature_portal_csv_009b40c8);
    uVar6 = uVar6 | 2;
    local_28 = FUN_0050eb50(5,local_1c,1);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 2) != 0) && (uVar6 = uVar6 & 0xfffffffd, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_32;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Creature_Brick_csv_009b40dc);
    uVar6 = uVar6 | 4;
    local_28 = FUN_0050eb50(6,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 4) != 0) && (uVar6 = uVar6 & 0xfffffffb, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_33;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Creature_Sentry_csv_009b40f0);
    uVar6 = uVar6 | 8;
    local_28 = FUN_0050eb50(8,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  if (((uVar6 & 8) != 0) && (uVar6 = uVar6 & 0xfffffff7, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_34;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_28 = 0;
  }
  else {
    FUN_00401830(s_Creature_Ornament_csv_009b4104);
    uVar6 = uVar6 | 0x10;
    local_28 = FUN_0050eb50(9,local_1c,0);
  }
  FUN_004fb2c0(&local_28);
  iVar1 = local_24;
  if (((uVar6 & 0x10) != 0) && (uVar6 = uVar6 & 0xffffffef, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_35;
  }
  FUN_004f8de0();
  FUN_004f8f60();
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Arrange_Cell_csv_009b411c);
    uVar6 = uVar6 | 0x20;
    local_24 = FUN_0050e980(1,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((uVar6 & 0x20) != 0) && (uVar6 = uVar6 & 0xffffffdf, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_36;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Arrange_warp_csv_009b4130);
    uVar6 = uVar6 | 0x40;
    local_24 = FUN_0050e980(0,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((uVar6 & 0x40) != 0) && (uVar6 = uVar6 & 0xffffffbf, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_37;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Arrange_Location_csv_009b4144);
    uVar6 = uVar6 | 0x80;
    local_24 = FUN_0050e780(4,local_1c,0);
  }
  FUN_004fb2c0(&local_24);
  if (((char)uVar6 < '\0') && (uVar6 = uVar6 & 0xffffff00, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_38;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Arrange_ChaoticLocation_csv_009b415c);
    uVar6 = (uint)(byte)((byte)(uVar6 >> 8) | 1) << 8;
    local_24 = FUN_0050e780(7,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((uVar6 & 0x100) != 0) && (uVar6 = (uint)((byte)(uVar6 >> 8) & 0xfe) << 8, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_39;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Item_ItemSellPrice_csv_009b4178);
    uVar6 = (uint)(byte)((byte)(uVar6 >> 8) | 2) << 8;
    local_24 = FUN_0050e780(9,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((uVar6 & 0x200) != 0) && (uVar6 = (uint)((byte)(uVar6 >> 8) & 0xfd) << 8, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_40;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_PC_LevelCap_csv_009b4190);
    uVar6 = (uint)(byte)((byte)(uVar6 >> 8) | 4) << 8;
    local_24 = FUN_0050e780(5,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((uVar6 & 0x400) != 0) && (uVar6 = (uint)((byte)(uVar6 >> 8) & 0xfb) << 8, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_41;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Item_ItemUpgrade_csv_009b41a0);
    uVar6 = (uint)(byte)((byte)(uVar6 >> 8) | 8) << 8;
    local_24 = FUN_0050e780(6,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((uVar6 & 0x800) != 0) && (uVar6 = (uint)((byte)(uVar6 >> 8) & 0xf7) << 8, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_42;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Item_ItemAddSocket_csv_009b41b8);
    uVar6 = (uint)(byte)((byte)(uVar6 >> 8) | 0x10) << 8;
    local_24 = FUN_0050e780(8,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((uVar6 & 0x1000) != 0) && (uVar6 = (uint)((byte)(uVar6 >> 8) & 0xef) << 8, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_43;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Item_itemdelstone_csv_009b41d0);
    uVar6 = (uint)(byte)((byte)(uVar6 >> 8) | 0x20) << 8;
    local_24 = FUN_0050e780(0xc,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((uVar6 & 0x2000) != 0) && (uVar6 = (uint)((byte)(uVar6 >> 8) & 0xdf) << 8, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_44;
  }
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Item_Exchange_csv_009b41e8);
    uVar6 = (uint)(byte)((byte)(uVar6 >> 8) | 0x40) << 8;
    local_24 = FUN_0050e780(0xb,local_1c,0);
  }
  FUN_004fb2c0(&local_24);
  bVar7 = (byte)(uVar6 >> 8);
  if (((uVar6 & 0x4000) != 0) && (bVar7 = bVar7 & 0xbf, 0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_45;
  }
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_0050e140();
  }
  FUN_004fb2c0(&local_24);
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_0050de10();
  }
  FUN_004fb2c0(&local_24);
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_0050d7e0();
  }
  FUN_004fb2c0(&local_24);
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_0050d6d0();
  }
  FUN_004fb2c0(&local_24);
  pvVar4 = operator_new(0x28);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    FUN_00401830(s_Arrange_Teleport_csv_009b41fc);
    bVar7 = bVar7 | 0x80;
    local_24 = FUN_0050e780(2,local_1c,1);
  }
  FUN_004fb2c0(&local_24);
  if (((char)bVar7 < '\0') && (0xf < local_4)) {
    _free(local_18);
    return extraout_EAX_46;
  }
  FUN_004f90e0();
  FUN_004f9290();
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_0050d540();
  }
  FUN_004fb2c0(&local_24);
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_0050d420();
  }
  FUN_004fb2c0(&local_24);
  pvVar4 = operator_new(4);
  if (pvVar4 == (void *)0x0) {
    local_24 = 0;
  }
  else {
    local_24 = FUN_0050d380();
  }
  FUN_004fb2c0(&local_24);
  if (*(int *)(in_ECX + 0x10) == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10) >> 2;
  }
  *(int *)(iVar1 + 8) = iVar8;
  (**(code **)(**(int **)(param_1 + 0xac) + 0xc))(1);
  FUN_0065bec0(*(undefined4 *)(iVar1 + 8));
  FUN_0065bf90(0);
  uVar6 = FUN_004f8970();
  return uVar6 & 0xffffff00;
}


// ==== FUN_004fb010 @ 0x004fb010 ====

void FUN_004fb010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b42ec;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((void *)in_ECX[4] != (void *)0x0) {
    _free((void *)in_ECX[4]);
    return;
  }
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *in_ECX = &PTR_FUN_009b358c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004fb070 @ 0x004fb070 ====

void FUN_004fb070(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981540;
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


// ==== Catch@004fb1d1 @ 0x004fb1d1 ====

void Catch_004fb1d1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_004fb2c0 @ 0x004fb2c0 ====

void FUN_004fb2c0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_004fb070(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004fb310 @ 0x004fb310 ====

undefined4 FUN_004fb310(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_004fb320 @ 0x004fb320 ====

void FUN_004fb320(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b4340;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  return;
}


// ==== FUN_004fb340 @ 0x004fb340 ====

void FUN_004fb340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b4340;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009b358c;
  return;
}


// ==== FUN_004fb380 @ 0x004fb380 ====

void FUN_004fb380(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  if (*(int *)(in_ECX + 0x14) != 0) {
    if (*(int *)(in_ECX + 0xc) + 5000U < *(uint *)(param_1 + 8)) {
      FUN_0050f200(1000);
    }
    if (*(char *)(*(int *)(in_ECX + 0x14) + 0xc) != '\0') {
      param_1 = *(undefined4 *)(iVar1 + 4);
      FUN_0050f0f0(&param_1);
      return;
    }
    if (*(int *)(*(int *)(in_ECX + 0x14) + 0x10) == 2) {
      *(undefined4 *)(in_ECX + 8) = 1;
    }
  }
  return;
}


// ==== FUN_004fb430 @ 0x004fb430 ====

uint FUN_004fb430(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x10001) {
    uVar1 = 0;
    if (param_1[2] == 1) {
LAB_004fb47a:
      *(undefined4 *)(in_ECX + 8) = 1;
      return 1;
    }
  }
  else if (uVar1 == 0x20001) {
    if ((param_1[1] == 0xd) || (param_1[1] == 0x1b)) goto LAB_004fb47a;
  }
  else if (uVar1 == 0x40001) {
    uVar1 = FUN_004fb380(param_1,param_2);
    return uVar1 & 0xffffff00;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004fb4a0 @ 0x004fb4a0 ====

uint FUN_004fb4a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  uint uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(int *)(in_ECX + 0x14) == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0050f0d0();
    }
    *(undefined4 *)(in_ECX + 0x14) = uVar2;
    FUN_0050f180(1000);
  }
  if (*(int *)(in_ECX + 0x10) == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401740(s_UI_Game2_CreditWnd_ui_testserver_009b4304,0x27);
      uVar2 = FUN_0065d9d0(local_1c);
    }
    *(undefined4 *)(in_ECX + 0x10) = uVar2;
    if ((pvVar1 != (void *)0x0) && (0xf < local_4)) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(uint *)(in_ECX + 0xc) = uVar3;
  return uVar3 & 0xffffff00;
}


// ==== FUN_004fb560 @ 0x004fb560 ====

void FUN_004fb560(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b4340;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009b358c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004fb5b0 @ 0x004fb5b0 ====

undefined4 FUN_004fb5b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_004fb5c0 @ 0x004fb5c0 ====

void FUN_004fb5c0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  if (*(int *)(in_ECX + 0x30) != 0) {
    if (*(uint *)(param_1 + 8) <= *(int *)(in_ECX + 0x28) + 5000U) {
      if (*(int *)(in_ECX + 0x28) + 4000U < *(uint *)(param_1 + 8)) {
        FUN_0050f200(1000);
      }
      if (*(char *)(*(int *)(in_ECX + 0x30) + 0xc) != '\0') {
        param_1 = *(undefined4 *)(iVar1 + 4);
        FUN_0050f0f0(&param_1);
        return;
      }
      if (*(int *)(*(int *)(in_ECX + 0x30) + 0x10) != 2) {
        return;
      }
    }
    *(undefined4 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_004fb690 @ 0x004fb690 ====

uint FUN_004fb690(void)

{
  void *pvVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(int *)(in_ECX + 0x30) == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0050f0d0();
    }
    *(undefined4 *)(in_ECX + 0x30) = uVar2;
    FUN_0050f180(1000);
  }
  if (*(int *)(in_ECX + 0x2c) == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0065d9d0(in_ECX + 0xc);
    }
    *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  }
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(uint *)(in_ECX + 0x28) = uVar3;
  return uVar3 & 0xffffff00;
}


// ==== FUN_004fb710 @ 0x004fb710 ====

undefined4 FUN_004fb710(int *param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x10001) {
    bVar2 = param_1[2] == 1;
  }
  else {
    if (iVar1 != 0x20001) {
      if (iVar1 == 0x40001) {
        FUN_004fb5c0(param_1,param_2);
        return 0;
      }
      return 0;
    }
    if (param_1[1] == 0xd) goto LAB_004fb75d;
    bVar2 = param_1[1] == 0x1b;
  }
  if (!bVar2) {
    return 0;
  }
LAB_004fb75d:
  FUN_0050f200(500);
  return 1;
}


// ==== FUN_004fb780 @ 0x004fb780 ====

void FUN_004fb780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b4440;
  if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xc])(1);
  }
  in_ECX[0xc] = 0;
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[8] = 0;
    in_ECX[9] = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_009b358c;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_004fb7e0 @ 0x004fb7e0 ====

void FUN_004fb7e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b4440;
  in_ECX[2] = 0;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_004fb820 @ 0x004fb820 ====

void FUN_004fb820(byte param_1)

{
  void *in_ECX;
  
  FUN_004fb780();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004fb850 @ 0x004fb850 ====

undefined4 FUN_004fb850(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 8))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  if ((*(int *)(in_ECX + 0xc) == 0) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 4))(param_1), cVar1 != '\x01')) {
    return 0;
  }
  return 1;
}


// ==== FUN_004fb8c0 @ 0x004fb8c0 ====

void FUN_004fb8c0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b45f0;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b45dc;
  }
  FUN_00797a20(puVar1);
  if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xc])(1);
  }
  in_ECX[0xc] = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  (**(code **)(*piVar2 + 8))(s___SceneModel_Game_GameScene2_cpp_009b451c,0x4b,0,in_ECX[1]);
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((void *)in_ECX[9] == (void *)0x0) {
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    *in_ECX = &PTR_FUN_009b3414;
    return;
  }
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_004fb960 @ 0x004fb960 ====

void FUN_004fb960(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  bool bVar5;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  FUN_004de2a0(1,0);
  if (*(undefined4 **)(in_ECX + 0x30) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x30))(1);
  }
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_rc_skybox_0_009b458c,0xb);
  (**(code **)(*DAT_00b5a688 + 4))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  piVar2 = *(int **)(in_ECX + 0x28);
  for (piVar4 = *(int **)(in_ECX + 0x24); piVar4 != piVar2; piVar4 = piVar4 + 1) {
    puVar1 = (undefined4 *)*piVar4;
    (**(code **)(*DAT_00b5a79c + 0xc))(puVar1);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
  }
  if (*(void **)(in_ECX + 0x24) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a74c + 0xc))(0x1f);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(0);
  }
  iVar3 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar3 == 1) {
    iVar3 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if (iVar3 != 2) {
      iVar3 = (**(code **)(*DAT_00b5ac1c + 0x20))();
      bVar5 = iVar3 == 1;
      goto LAB_004fba6e;
    }
  }
  else {
    iVar3 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    bVar5 = iVar3 == 2;
LAB_004fba6e:
    if (!bVar5) goto LAB_004fba75;
  }
  FUN_006eabe0();
LAB_004fba75:
  iVar3 = (**(code **)(*DAT_00b5ac1c + 0x20))();
  if (iVar3 == 3) {
    FUN_006eab70();
  }
  iVar3 = (**(code **)(*DAT_00b5ac1c + 0x20))();
  if (iVar3 == 4) {
    FUN_006eab00();
  }
  (**(code **)(*DAT_00b5a790 + 8))();
  FUN_0050f640();
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xc))(1);
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  (**(code **)(*DAT_00b5ac18 + 8))(*(undefined4 *)(in_ECX + 0x14));
  (**(code **)(*DAT_00b5ac18 + 8))(*(undefined4 *)(in_ECX + 0x18));
  (**(code **)(*DAT_00b5ac18 + 8))(*(undefined4 *)(in_ECX + 0x1c));
  if (*(undefined4 **)(in_ECX + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x14))(1);
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (*(undefined4 **)(in_ECX + 0x18) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x18))(1);
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  if (*(undefined4 **)(in_ECX + 0x1c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x1c))(1);
  }
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}


// ==== FUN_004fbb40 @ 0x004fbb40 ====

void FUN_004fbb40(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b45f0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 4))(0,s___SceneModel_Game_GameScene2_cpp_009b44f8,0x3f);
  in_ECX[1] = uVar2;
  return;
}


// ==== FUN_004fbb90 @ 0x004fbb90 ====

/* WARNING: Removing unreachable block (ram,0x004fc039) */
/* WARNING: Removing unreachable block (ram,0x004fbcb0) */

void FUN_004fbb90(void)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  int in_ECX;
  void *unaff_EDI;
  bool bVar9;
  void *_Memory;
  uint *puStack_64;
  uint uStack_60;
  undefined4 uStack_5c;
  uint auStack_38 [14];
  
  (**(code **)(*DAT_00b5add8 + 4))();
  (**(code **)(*DAT_00b5ac84 + 8))();
  uStack_5c = 0x4fbbbb;
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005117b0();
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar4;
  uStack_5c = 0x4fbbd7;
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00511500();
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar4;
  uStack_5c = 0x4fbbf3;
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00511410();
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar4;
  uStack_5c = 0x4fbc17;
  (**(code **)(*DAT_00b5ac18 + 4))();
  uStack_5c = *(undefined4 *)(in_ECX + 0x18);
  uStack_60 = 0x4fbc26;
  (**(code **)(*DAT_00b5ac18 + 4))();
  uStack_60 = *(uint *)(in_ECX + 0x1c);
  puStack_64 = (uint *)0x4fbc35;
  (**(code **)(*DAT_00b5ac18 + 4))();
  puStack_64 = (uint *)0xa;
  auStack_38[1] = 0xf;
  auStack_38[0] = 0;
  FUN_00401740();
  puStack_64 = auStack_38 + -5;
  (**(code **)(*DAT_00b5a688 + 4))();
  if (0xf < auStack_38[0]) {
    _free(unaff_EDI);
    return;
  }
  auStack_38[0] = 0xf;
  FUN_00401740();
  (**(code **)(*DAT_00b5a688 + 4))();
  pvVar3 = operator_new(0xc);
  if (pvVar3 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_00510e40();
  }
  *(int **)(in_ECX + 8) = piVar5;
  (**(code **)(*piVar5 + 4))();
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00510cd0();
  }
  *(undefined4 *)(in_ECX + 0xc) = uVar4;
  FUN_00401740(s_create_script__d_Producer_shortk_009b4558,0x26);
  FUN_00404230(auStack_38);
  (**(code **)(*DAT_00b5a688 + 4))();
  iVar6 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar6 == 1) {
    iVar6 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    if (iVar6 != 2) {
      iVar6 = (**(code **)(*DAT_00b5ac1c + 0x20))();
      bVar9 = iVar6 == 1;
      goto LAB_004fbd6a;
    }
  }
  else {
    iVar6 = (**(code **)(*DAT_00b5ac1c + 0x20))();
    bVar9 = iVar6 == 2;
LAB_004fbd6a:
    if (!bVar9) goto LAB_004fbd71;
  }
  FUN_006eab90();
LAB_004fbd71:
  iVar6 = (**(code **)(*DAT_00b5ac1c + 0x20))();
  if (iVar6 == 3) {
    FUN_006eab20();
  }
  iVar6 = (**(code **)(*DAT_00b5ac1c + 0x20))();
  if (iVar6 == 4) {
    FUN_006eaab0();
  }
  pvVar3 = operator_new(0x1c);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0050f8d0();
  }
  uStack_5c = uVar4;
  (**(code **)(*DAT_00b5a79c + 4))();
  iVar6 = *(int *)(in_ECX + 0x24);
  if ((iVar6 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x2c) - iVar6 >> 2) <= (uint)(*(int *)(in_ECX + 0x28) - iVar6 >> 2)))
  {
    FUN_004fc0c0(*(undefined4 *)(in_ECX + 0x28),1,&uStack_60);
  }
  else {
    puVar1 = *(undefined4 **)(in_ECX + 0x28);
    *puVar1 = uVar4;
    *(undefined4 **)(in_ECX + 0x28) = puVar1 + 1;
  }
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    uVar7 = 0;
  }
  else {
    uVar7 = FUN_006eaf60();
  }
  uStack_60 = uVar7;
  (**(code **)(*DAT_00b5a79c + 4))(uVar7);
  iVar6 = *(int *)(in_ECX + 0x24);
  if ((iVar6 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x2c) - iVar6 >> 2) <= (uint)(*(int *)(in_ECX + 0x28) - iVar6 >> 2)))
  {
    FUN_004fc0c0(*(undefined4 *)(in_ECX + 0x28),1,&puStack_64);
  }
  else {
    puVar8 = *(uint **)(in_ECX + 0x28);
    *puVar8 = uVar7;
    *(uint **)(in_ECX + 0x28) = puVar8 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    puVar8 = (uint *)0x0;
  }
  else {
    puVar8 = (uint *)FUN_006eade0();
  }
  puStack_64 = puVar8;
  (**(code **)(*DAT_00b5a79c + 4))(puVar8);
  iVar6 = *(int *)(in_ECX + 0x24);
  if ((iVar6 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x2c) - iVar6 >> 2) <= (uint)(*(int *)(in_ECX + 0x28) - iVar6 >> 2)))
  {
    FUN_004fc0c0(*(undefined4 *)(in_ECX + 0x28),1,auStack_38 + -0xc);
  }
  else {
    puVar1 = *(undefined4 **)(in_ECX + 0x28);
    *puVar1 = puVar8;
    *(undefined4 **)(in_ECX + 0x28) = puVar1 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_006eacb0();
  }
  (**(code **)(*DAT_00b5a79c + 4))(uVar4);
  iVar6 = *(int *)(in_ECX + 0x24);
  if ((iVar6 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x2c) - iVar6 >> 2) <= (uint)(*(int *)(in_ECX + 0x28) - iVar6 >> 2)))
  {
    FUN_004fc0c0(*(undefined4 *)(in_ECX + 0x28),1,auStack_38 + -0xd);
  }
  else {
    puVar1 = *(undefined4 **)(in_ECX + 0x28);
    *puVar1 = uVar4;
    *(undefined4 **)(in_ECX + 0x28) = puVar1 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = (void *)FUN_006eac10();
  }
  _Memory = pvVar3;
  (**(code **)(*DAT_00b5a79c + 4))(pvVar3);
  iVar6 = *(int *)(in_ECX + 0x24);
  if ((iVar6 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x2c) - iVar6 >> 2) <= (uint)(*(int *)(in_ECX + 0x28) - iVar6 >> 2)))
  {
    FUN_004fc0c0(*(undefined4 *)(in_ECX + 0x28),1,auStack_38 + -0xe);
  }
  else {
    puVar1 = *(undefined4 **)(in_ECX + 0x28);
    *puVar1 = pvVar3;
    *(undefined4 **)(in_ECX + 0x28) = puVar1 + 1;
  }
  uVar7 = 0;
  FUN_00401740(s_rc_skybox_1_009b4580,0xb);
  (**(code **)(*DAT_00b5a688 + 4))(auStack_38 + -0xd);
  if (uVar7 < 0x10) {
    uVar2 = (**(code **)(*DAT_00b5ae14 + 0x18))();
    FUN_004de2a0(0,uVar2);
    FUN_0050f430();
    FUN_0050f370();
    (**(code **)(*DAT_00b5ad84 + 0x18))();
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_004fc050 @ 0x004fc050 ====

undefined4 FUN_004fc050(void)

{
  return 0x70800001;
}


// ==== FUN_004fc060 @ 0x004fc060 ====

void FUN_004fc060(byte param_1)

{
  void *in_ECX;
  
  FUN_004fb8c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004fc080 @ 0x004fc080 ====

int FUN_004fc080(int param_1)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  
  puVar2 = PTR_s_SceneGame2_00aea558;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar3 = puVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(puVar2,(int)pcVar3 - (int)(puVar2 + 1));
  return param_1;
}


// ==== FUN_004fc0c0 @ 0x004fc0c0 ====

void FUN_004fc0c0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981550;
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


// ==== Catch@004fc221 @ 0x004fc221 ====

void Catch_004fc221(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_004fc310 @ 0x004fc310 ====

void FUN_004fc310(void)

{
  return;
}


// ==== FUN_004fc320 @ 0x004fc320 ====

void FUN_004fc320(void)

{
  return;
}


// ==== FUN_004fc330 @ 0x004fc330 ====

undefined1 FUN_004fc330(void)

{
  return 0;
}


// ==== FUN_004fc340 @ 0x004fc340 ====

void FUN_004fc340(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b470c;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 4))(0,s___SceneModel_Game_PreGameScene_c_009b46b0,0xc);
  in_ECX[1] = uVar2;
  return;
}


// ==== FUN_004fc370 @ 0x004fc370 ====

void FUN_004fc370(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b470c;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  (**(code **)(*piVar1 + 8))(s___SceneModel_Game_PreGameScene_c_009b46d4,0x11,0,in_ECX[1]);
  *in_ECX = &PTR_FUN_009b3414;
  return;
}


// ==== FUN_004fc3a0 @ 0x004fc3a0 ====

void FUN_004fc3a0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  uint uVar2;
  
  *in_ECX = &PTR_FUN_009b470c;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar2 = 0;
  (**(code **)(*piVar1 + 8))(s___SceneModel_Game_PreGameScene_c_009b46d4,0x11,0,in_ECX[1]);
  *in_ECX = &PTR_FUN_009b3414;
  if ((uVar2 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004fc3f0 @ 0x004fc3f0 ====

undefined4 FUN_004fc3f0(undefined4 param_1)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  
  puVar2 = PTR_s_ScenePregame_00aea5dc;
  FUN_00401330(0,0);
  pcVar3 = puVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(puVar2,(int)pcVar3 - (int)(puVar2 + 1));
  return param_1;
}


// ==== FUN_004fc430 @ 0x004fc430 ====

undefined1 FUN_004fc430(void)

{
  return 0;
}


// ==== FUN_004fc590 @ 0x004fc590 ====

void FUN_004fc590(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x20) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x20))(1);
    *(undefined4 *)(in_ECX + 0x20) = 0;
  }
  if (*(int **)(in_ECX + 0x30) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x30) + 4))();
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar2 + 8))(s___SceneModel_Game_CharCreateScen_009b4ab0,0x3a2,0,uVar1);
    if (*(undefined4 **)(in_ECX + 0x30) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x30))(1);
    }
    *(undefined4 *)(in_ECX + 0x30) = 0;
  }
  return;
}


// ==== FUN_004fc5f0 @ 0x004fc5f0 ====

void FUN_004fc5f0(byte *param_1)

{
  ushort uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar5;
  int local_4;
  
  param_1 = (byte *)(uint)*param_1;
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x28)) {
    iVar2 = *(int *)(local_4 + 0x10);
    (**(code **)(*DAT_00b5ad14 + 0x10))(iVar2 + 0x18);
    pvVar3 = operator_new(0x18);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
      uVar5 = extraout_var;
    }
    else {
      uVar4 = FUN_005084a0();
      uVar5 = extraout_var_00;
    }
    *(undefined4 *)(in_ECX + 0x20) = uVar4;
    FUN_00508750(CONCAT22(uVar5,*(undefined2 *)(iVar2 + 0x14)));
    if (-1 < *(int *)(in_ECX + 0x54)) {
      FUN_004de2a0(1,*(int *)(in_ECX + 0x54));
    }
    uVar1 = *(ushort *)(iVar2 + 0x14);
    *(uint *)(in_ECX + 0x54) = (uint)uVar1;
    FUN_004de2a0(0,(uint)uVar1);
  }
  return;
}


// ==== FUN_004fc6b0 @ 0x004fc6b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fc6b0(undefined4 param_1,int param_2)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    local_24 = *(undefined4 *)(in_ECX + 0x34);
    FUN_0079bba0(&local_20,&local_24);
    if (local_20 != *(int *)(in_ECX + 0x28)) {
      puVar2 = *(undefined4 **)(local_20 + 0x10);
      local_8 = param_1;
      local_c = 0;
      local_4 = param_2;
      if (param_2 == 3) {
        uVar1 = puVar2[1];
      }
      else {
        uVar1 = *puVar2;
      }
      local_1c = puVar2[3];
      local_18 = puVar2[4];
      FUN_0040d600(local_14,(float)puVar2[9] * _DAT_00aea644 +
                            *(float *)(in_ECX + 0x40) * _DAT_00aea640);
      uVar4 = 0;
      puVar3 = local_14;
      puVar2 = &local_1c;
      FUN_00511d20(puVar2,puVar3,0);
      FUN_005118f0(puVar2,puVar3,uVar4);
      uVar5 = 0;
      uVar4 = 0;
      puVar3 = local_14;
      puVar2 = &local_c;
      FUN_00511d20(puVar2,puVar3,uVar1,0,0);
      FUN_00511c00(puVar2,puVar3,uVar1,uVar4,uVar5);
    }
  }
  return;
}


// ==== FUN_004fc7c0 @ 0x004fc7c0 ====

void FUN_004fc7c0(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x3c) < 6) {
    FUN_004fc6b0(1,2);
    return;
  }
  FUN_004fc6b0(1,3);
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  return;
}


// ==== FUN_004fc7f0 @ 0x004fc7f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fc7f0(int *param_1)

{
  int iVar1;
  float fVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x48);
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 == 1) {
    fVar2 = (float)*param_1;
    if (*param_1 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar2 = fVar2 * *(float *)(in_ECX + 0x44) + *(float *)(in_ECX + 0x40);
  }
  else {
    if (iVar1 != 2) goto LAB_004fc839;
    fVar2 = (float)*param_1;
    if (*param_1 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar2 = *(float *)(in_ECX + 0x40) - fVar2 * *(float *)(in_ECX + 0x44);
  }
  *(float *)(in_ECX + 0x40) = fVar2;
LAB_004fc839:
  if (*(uint *)(in_ECX + 0x3c) < 6) {
    FUN_004fc6b0(1,2);
    return;
  }
  FUN_004fc6b0(1,3);
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  return;
}


// ==== FUN_004fc870 @ 0x004fc870 ====

uint FUN_004fc870(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + 1;
    if (5 < *(uint *)(in_ECX + 0x3c)) {
      uVar1 = FUN_004fc6b0(1,3);
      *(undefined4 *)(in_ECX + 0x3c) = 0;
      return uVar1 & 0xffffff00;
    }
    param_1 = FUN_004fc6b0(1,2);
  }
  return param_1 & 0xffffff00;
}


// ==== FUN_004fc8b0 @ 0x004fc8b0 ====

/* WARNING: Removing unreachable block (ram,0x004fc92b) */
/* WARNING: Removing unreachable block (ram,0x004fca43) */
/* WARNING: Removing unreachable block (ram,0x004fca98) */
/* WARNING: Removing unreachable block (ram,0x004fc8f8) */

void FUN_004fc8b0(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_36 [6];
  uint uStack_30;
  
  if (*(char *)(in_ECX + 0x38) == '\0') {
    FUN_00401740(s_Not_Wait_For_Creating_Character__009b49f4);
    FUN_00796d20();
    FUN_00401740(s_Not_Wait_For_Creating_Character__009b4a18);
    return;
  }
  *(undefined1 *)(in_ECX + 0x38) = 0;
  if (-1 < *(int *)(param_1 + 0x10)) {
    FUN_00401740(s_Create_Character_OK___009b4a3c);
    FUN_00796d20();
    FUN_0050f200();
    return;
  }
  FUN_00401740(&DAT_009b4a3a);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xfffffff4:
    break;
  case 0xfffffff5:
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
    goto LAB_004fc9c7;
  default:
    goto switchD_004fc97b_caseD_fffffff6;
  case 0xfffffffd:
    break;
  case 0xfffffffe:
    uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
    goto LAB_004fc9c7;
  case 0xffffffff:
  }
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
LAB_004fc9c7:
  FUN_00401660(uVar1,0);
switchD_004fc97b_caseD_fffffff6:
  piVar2 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
  (**(code **)*piVar2)(0x17);
  (**(code **)(*piVar2 + 4))(0);
  (**(code **)(*DAT_00b5a9e0 + 0x20))(1);
  (**(code **)(*DAT_00b5a9dc + 0xc))();
  FUN_00796d20(auStack_36 + -0x12);
  FUN_00401660(auStack_36 + -0x12,0,0xffffffff);
  if (uStack_30 < 0x10) {
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_004fcae0 @ 0x004fcae0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_004fcae0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 local_10a4 [4];
  void *pvStack_10a0;
  undefined4 uStack_1090;
  uint uStack_108c;
  undefined1 auStack_1088 [4];
  void *pvStack_1084;
  undefined4 uStack_1074;
  uint uStack_1070;
  void *pvStack_1068;
  undefined4 uStack_1058;
  uint uStack_1054;
  void *pvStack_104c;
  undefined4 uStack_103c;
  uint uStack_1038;
  undefined1 auStack_1034 [4];
  void *pvStack_1030;
  undefined4 uStack_1020;
  uint uStack_101c;
  undefined1 auStack_1018 [4];
  void *pvStack_1014;
  uint uStack_1000;
  undefined4 auStack_ffc [64];
  char acStack_efa [256];
  char acStack_dfa [256];
  char acStack_cfa [256];
  char acStack_bfa [1074];
  char acStack_7c8 [1980];
  undefined4 uStack_c;
  
  uStack_c = 0x4fcaf0;
  piVar2 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s__s__u_009b4b20,5);
    uVar3 = FUN_00404230(auStack_1018);
    FUN_00796d50(uVar3);
    if (0xf < uStack_1000) {
      _free(pvStack_1014);
      return;
    }
  }
  else {
    puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
    puVar7 = auStack_ffc;
    for (iVar6 = 0x3fb; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    }
    pcVar5 = acStack_efa;
    uStack_101c = 0xf;
    uStack_1020 = 0;
    pvStack_1030 = (void *)((uint)pvStack_1030 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_efa,(int)pcVar5 - (int)(acStack_efa + 1));
    pcVar5 = acStack_dfa;
    uStack_1070 = 0xf;
    uStack_1074 = 0;
    pvStack_1084 = (void *)((uint)pvStack_1084 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_dfa,(int)pcVar5 - (int)(acStack_dfa + 1));
    pcVar5 = acStack_cfa;
    uStack_1038 = 0xf;
    uStack_103c = 0;
    pvStack_104c = (void *)((uint)pvStack_104c & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_cfa,(int)pcVar5 - (int)(acStack_cfa + 1));
    pcVar5 = acStack_bfa;
    uStack_1054 = 0xf;
    uStack_1058 = 0;
    pvStack_1068 = (void *)((uint)pvStack_1068 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_bfa,(int)pcVar5 - (int)(acStack_bfa + 1));
    pcVar5 = acStack_7c8;
    uStack_108c = 0xf;
    uStack_1090 = 0;
    pvStack_10a0 = (void *)((uint)pvStack_10a0 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_7c8,(int)pcVar5 - (int)(acStack_7c8 + 1));
    FUN_004b5bf0(1,auStack_1034);
    FUN_004b5bf0(2,auStack_1088);
    FUN_004b5bf0(0x15,local_10a4);
    if (0xf < uStack_108c) {
      _free(pvStack_10a0);
      return;
    }
    uStack_108c = 0xf;
    uStack_1090 = 0;
    pvStack_10a0 = (void *)((uint)pvStack_10a0 & 0xffffff00);
    if (0xf < uStack_1054) {
      _free(pvStack_1068);
      return;
    }
    uStack_1054 = 0xf;
    uStack_1058 = 0;
    pvStack_1068 = (void *)((uint)pvStack_1068 & 0xffffff00);
    if (0xf < uStack_1038) {
      _free(pvStack_104c);
      return;
    }
    uStack_1038 = 0xf;
    uStack_103c = 0;
    pvStack_104c = (void *)((uint)pvStack_104c & 0xffffff00);
    if (0xf < uStack_1070) {
      _free(pvStack_1084);
      return;
    }
    uStack_1070 = 0xf;
    uStack_1074 = 0;
    pvStack_1084 = (void *)((uint)pvStack_1084 & 0xffffff00);
    if (0xf < uStack_101c) {
      _free(pvStack_1030);
      return;
    }
  }
  return;
}


// ==== FUN_004fcd80 @ 0x004fcd80 ====

/* WARNING: Removing unreachable block (ram,0x004fd09a) */
/* WARNING: Removing unreachable block (ram,0x004fce1f) */
/* WARNING: Removing unreachable block (ram,0x004fcfc1) */
/* WARNING: Removing unreachable block (ram,0x004fcdd7) */

void FUN_004fcd80(void)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined1 auStack_ba [22];
  uint uStack_a4;
  int *piStack_a0;
  int iStack_9c;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined1 auStack_80 [4];
  void *pvStack_7c;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  void *pvStack_48;
  undefined4 uStack_44;
  undefined1 uStack_3c;
  uint uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  iVar5 = (**(code **)(*DAT_00b5a74c + 0xc))(0xf);
  if (iVar5 == 0) {
    FUN_00401740(s_pUIHandler____NULL_009b493c,0x12);
    FUN_00406880(auStack_ba + -6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  piStack_a0 = *(int **)(iVar5 + 4);
  if (piStack_a0 == (int *)0x0) {
    FUN_00401740(s_pWindow____NULL_009b4950,0xf);
    FUN_00406880(auStack_ba + -6);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  uStack_5e = 1;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  pvStack_48 = (void *)0x0;
  uStack_44 = 0;
  uStack_28 = 0xf;
  uStack_2c = 0;
  uStack_3c = 0;
  uStack_a4 = 0;
  do {
    piVar6 = piStack_a0;
    uStack_8 = uStack_a4 + 1;
    FUN_00401740(s_btn_list__d_009b4960,0xb);
    FUN_00404230(auStack_24);
    piVar6 = (int *)(**(code **)(*piVar6 + 0x34))(auStack_24);
    if (piVar6 == (int *)0x0) {
      uStack_68 = 0xf;
      uStack_6c = 0;
      pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
      FUN_00401740(s_pComposite____NULL_009b496c,0x12);
      FUN_00406880(auStack_80);
      if (uStack_68 < 0x10) {
        uStack_68 = 0xf;
        uStack_6c = 0;
        pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_7c);
      return;
    }
    iVar5 = (**(code **)(*piVar6 + 0x30))();
    puVar7 = (undefined1 *)(**(code **)(*piVar6 + 0x10))();
    uStack_60 = *puVar7;
    uStack_5f = puVar7[1];
    uStack_5e = puVar7[2];
    uStack_5c = *(undefined4 *)(puVar7 + 4);
    uStack_58 = *(undefined4 *)(puVar7 + 8);
    uStack_54 = *(undefined4 *)(puVar7 + 0xc);
    uStack_50 = *(undefined4 *)(puVar7 + 0x10);
    uStack_4c = *(undefined4 *)(puVar7 + 0x14);
    pvStack_48 = *(void **)(puVar7 + 0x18);
    uStack_44 = *(undefined4 *)(puVar7 + 0x1c);
    FUN_00401660(puVar7 + 0x20,0,0xffffffff);
    if (iVar5 == 0) {
      FUN_00401740(s_pButton____NULL_009b4980,0xf);
      FUN_00406880(auStack_ba + -6);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(byte *)(iStack_9c + 4) == uStack_a4) {
      uVar8 = 1;
LAB_004fd00d:
      FUN_00558730(uVar8);
      (**(code **)(*piVar6 + 0xc))(&uStack_60);
      uVar2 = uStack_a4;
      uVar3 = uStack_8;
    }
    else {
      cVar4 = (**(code **)(*piVar6 + 0x40))();
      uVar2 = uStack_a4;
      uVar3 = uStack_8;
      if (cVar4 != '\0') {
        uVar8 = 0;
        goto LAB_004fd00d;
      }
    }
    uStack_a4 = uVar3;
    uStack_8 = uStack_a4;
    if (0xf < uStack_c) {
      uStack_a4 = uVar2;
      _free(pvStack_20);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    if (5 < uStack_a4) {
      FUN_00401740(s_pan_class_desc_009b4990,0xe);
      piVar6 = (int *)(**(code **)(*piStack_a0 + 0x34))(auStack_ba + -6);
      if (piVar6 == (int *)0x0) {
        uStack_68 = 0xf;
        uStack_6c = 0;
        pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
        FUN_00401740(s_pComposite____NULL_009b49a0,0x12);
        FUN_00406880(auStack_80);
        if (uStack_68 < 0x10) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        _free(pvStack_7c);
        return;
      }
      (**(code **)(*piVar6 + 0x30))();
      uVar8 = (**(code **)(*DAT_00b5a794 + 0xc))(0,*(byte *)(piStack_a0 + 1) + 1 | 0x3ef0000);
      uStack_8c = 0xf;
      uStack_90 = 0;
      piStack_a0 = (int *)((uint)piStack_a0 & 0xffffff00);
      FUN_00401660(uVar8,0,0xffffffff);
      FUN_005569f0(&uStack_a4,1);
      if (0xf < uStack_8c) {
        _free(piStack_a0);
        return;
      }
      uStack_8c = 0xf;
      uStack_90 = 0;
      piStack_a0 = (int *)((uint)piStack_a0 & 0xffffff00);
      if (uStack_34 < 0x10) {
        return;
      }
      _free(pvStack_48);
      return;
    }
  } while( true );
}


// ==== FUN_004fd190 @ 0x004fd190 ====

undefined4 FUN_004fd190(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x3020001) {
    FUN_004fc8b0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_004fd1c0 @ 0x004fd1c0 ====

void FUN_004fd1c0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int in_ECX;
  int unaff_ESI;
  undefined1 local_70 [4];
  void *local_6c;
  undefined1 auStack_60 [4];
  undefined4 local_5c;
  uint local_58;
  void *local_50;
  undefined1 auStack_44 [4];
  undefined4 local_40;
  uint local_3c [2];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  piVar1 = DAT_00b5ae18;
  if (-1 < *(int *)(in_ECX + 0x34)) {
    if (*(char *)(in_ECX + 0x38) == '\x01') {
      local_58 = 0xf;
      local_5c = 0;
      local_6c = (void *)((uint)local_6c & 0xffffff00);
      FUN_00401740();
      FUN_00796d20();
      if (0xf < local_58) {
        _free(local_6c);
        return;
      }
    }
    else {
      if (*(char *)(in_ECX + 0x4d) == '\x01') {
        FUN_00401660(param_1 + 4,0,0xffffffff);
        (**(code **)*piVar1)(local_70);
        if (unaff_ESI == 0) {
          iVar5 = *DAT_00b5ae18;
          FUN_00765c50(param_1 + 4);
          uVar3 = (**(code **)(iVar5 + 4))(local_3c);
          FUN_00401660(uVar3,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
        uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x1e0002);
        FUN_00765c50(uVar3);
        puVar2 = (undefined4 *)*puVar2;
        FUN_00765c50(auStack_60);
        uVar3 = FUN_00404230(auStack_44);
        (*(code *)*puVar2)(0x17,uVar3);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00401830(&PTR_LAB_009b49dc);
      FUN_00404230(local_1c);
      FUN_00401830();
      FUN_00405bd0();
      FUN_00405bd0();
      FUN_00796d50();
      if (0xf < local_58) {
        _free(local_6c);
        return;
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c = (void *)((uint)local_6c & 0xffffff00);
      if (0xf < local_3c[0]) {
        _free(local_50);
        return;
      }
      local_3c[0] = 0xf;
      local_40 = 0;
      local_50 = (void *)((uint)local_50 & 0xffffff00);
      if (0xf < local_20) {
        _free(local_34);
        return;
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = 0;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x3020000;
      *(undefined2 *)((int)pvVar4 + 6) = 0x2c;
      iVar5 = FUN_004244d0();
      FUN_0047aa30();
      *(undefined1 *)(iVar5 + 0x2a) = *(undefined1 *)(in_ECX + 0x34);
      *(undefined1 *)(iVar5 + 0x29) = *(undefined1 *)(in_ECX + 8);
      FUN_004d8570();
      *(undefined1 *)(in_ECX + 0x38) = 1;
    }
  }
  return;
}


// ==== FUN_004fd5a0 @ 0x004fd5a0 ====

void FUN_004fd5a0(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b4bcc;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  iVar2 = FUN_004feaf0();
  in_ECX[10] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(in_ECX[10] + 4) = in_ECX[10];
  *(undefined4 *)in_ECX[10] = in_ECX[10];
  *(undefined4 *)(in_ECX[10] + 8) = in_ECX[10];
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 0x13) = 1;
  *(undefined1 *)((int)in_ECX + 0x4d) = 1;
  in_ECX[0x14] = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar4 = (**(code **)(*piVar3 + 4))(0,s___SceneModel_Game_CharCreateScen_009b47cc,0x2f);
  uVar1 = DAT_009b4bc4;
  in_ECX[3] = uVar4;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x11] = uVar1;
  return;
}


// ==== FUN_004fd630 @ 0x004fd630 ====

void FUN_004fd630(undefined4 param_1,uint param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined2 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int in_ECX;
  int iVar9;
  float10 fVar10;
  undefined1 auStack_20 [4];
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar3 = param_2;
  iVar7 = *(int *)(param_2 + 4);
  if (iVar7 != 0) {
    iVar9 = *(int *)(param_2 + 8) - iVar7;
    iVar2 = iVar9 >> 0x1f;
    iVar9 = iVar9 / 0x1c + iVar2;
    if (2 < (uint)(iVar9 - iVar2)) {
      if (iVar9 == iVar2) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(iVar7,0,0xffffffff);
      iVar7 = *(int *)(iVar3 + 4);
      if ((iVar7 == 0) || ((uint)((*(int *)(iVar3 + 8) - iVar7) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      param_2 = thunk_FUN_00796f50(iVar7 + 0x1c);
      param_2 = param_2 & 0xff;
      piVar6 = (int *)FUN_0079bba0(auStack_20,&param_2);
      if (*piVar6 != *(int *)(in_ECX + 0x28)) {
        pfVar1 = *(float **)(*piVar6 + 0x10);
        iVar7 = FUN_00403620(0,local_8,s_stand_009b4a54,5);
        if (iVar7 == 0) {
          uVar8 = FUN_00405d30(2);
          fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
          *pfVar1 = (float)fVar10;
        }
        else {
          cVar4 = FUN_004036a0(local_1c,s_stand_special_009b4a5c);
          if (cVar4 == '\0') {
            cVar4 = FUN_004036a0(local_1c,s_scale_009b4a6c);
            if (cVar4 == '\0') {
              cVar4 = FUN_004036a0(local_1c,s_position_009b4a74);
              if (cVar4 == '\0') {
                cVar4 = FUN_004036a0(local_1c,s_mapindex_009b4a80);
                if (cVar4 == '\0') {
                  cVar4 = FUN_004036a0(local_1c,s_cameratarget_009b4a8c);
                  if (cVar4 == '\0') {
                    cVar4 = FUN_004036a0(local_1c,&DAT_009b4a9c);
                    if (cVar4 == '\0') {
                      cVar4 = FUN_004036a0(local_1c,s_direction_009b4aa4);
                      if (cVar4 != '\0') {
                        uVar8 = FUN_00405d30(2);
                        fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                        pfVar1[9] = (float)fVar10;
                      }
                    }
                    else {
                      uVar8 = FUN_00405d30(2);
                      FUN_00406720(uVar8);
                    }
                  }
                  else {
                    uVar8 = FUN_00405d30(2);
                    fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                    pfVar1[6] = (float)fVar10;
                    uVar8 = FUN_00405d30(3);
                    fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                    pfVar1[7] = (float)fVar10;
                    uVar8 = FUN_00405d30(4);
                    fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                    pfVar1[8] = (float)fVar10;
                  }
                }
                else {
                  uVar8 = FUN_00405d30(2);
                  uVar5 = thunk_FUN_00796f80(uVar8);
                  *(undefined2 *)(pfVar1 + 5) = uVar5;
                }
              }
              else {
                uVar8 = FUN_00405d30(2);
                fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                pfVar1[3] = (float)fVar10;
                uVar8 = FUN_00405d30(3);
                fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
                pfVar1[4] = (float)fVar10;
              }
            }
            else {
              uVar8 = FUN_00405d30(2);
              fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
              pfVar1[2] = (float)fVar10;
            }
          }
          else {
            uVar8 = FUN_00405d30(2);
            fVar10 = (float10)thunk_FUN_00796ec0(uVar8);
            pfVar1[1] = (float)fVar10;
          }
        }
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
  }
  return;
}


// ==== FUN_004fd8c0 @ 0x004fd8c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fd8c0(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int in_ECX;
  undefined1 *puVar7;
  undefined4 *puVar8;
  undefined4 local_b8;
  int local_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined2 uStack_a8;
  undefined1 auStack_94 [148];
  
  FUN_004fcd80();
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  if (((*(int *)(in_ECX + 0x58) != 0) && (cVar2 = FUN_004b59a0(), cVar2 != '\0')) &&
     (*(int *)(in_ECX + 0x34) != *param_1)) {
    if (*(uint *)(in_ECX + 0x3c) < 6) {
      FUN_004fc6b0(1,2);
    }
    else {
      FUN_004fc6b0(1,3);
      *(undefined4 *)(in_ECX + 0x3c) = 0;
    }
    FUN_004fc590();
    FUN_004fc5f0(param_1);
    local_b4 = *param_1;
    *(int *)(in_ECX + 0x34) = local_b4;
    FUN_0079bba0(&local_b8,&local_b4);
    if (local_b8 != *(int *)(in_ECX + 0x28)) {
      iVar1 = *(int *)(local_b8 + 0x10);
      piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
      uVar4 = (**(code **)(*piVar3 + 4))(0,s___SceneModel_Game_CharCreateScen_009b4ad8,0x3cb);
      local_b4 = *(int *)(iVar1 + 0xc);
      uStack_b0 = *(undefined4 *)(iVar1 + 0x10);
      FUN_0040d600(auStack_94 + -0x28,*(float *)(iVar1 + 0x24) * _DAT_00aea644);
      pvVar5 = operator_new(0x40);
      if (pvVar5 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_005121e0();
      }
      uStack_a8 = *(undefined2 *)(in_ECX + 0x34);
      *(int *)(in_ECX + 0x30) = iVar6;
      uStack_ac = 0;
      *(undefined1 *)(iVar6 + 0xf) = 1;
      FUN_00512130(uVar4,&local_b4,auStack_94 + -0x28,0,*(undefined4 *)(iVar1 + 8),&uStack_ac,
                   auStack_94 + -0x30,1,1,1);
      FUN_00401830(PTR_s_M_Body_00aea63c);
      puVar8 = &uStack_ac;
      puVar7 = auStack_94;
      FUN_00511d10(puVar7,puVar8);
      FUN_00512e40(puVar7,puVar8);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return;
}


// ==== FUN_004fdbc0 @ 0x004fdbc0 ====

void FUN_004fdbc0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined4 *puVar8;
  int local_78;
  uint uStack_6c;
  undefined4 *puStack_68;
  undefined1 auStack_64 [8];
  undefined4 uStack_5c;
  void *pvStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 auStack_40 [4];
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5abac + 8))();
  while (piVar4 != (int *)0x0) {
    pbVar5 = (byte *)(**(code **)(*piVar4 + 4))();
    puStack_68 = operator_new(0x38);
    uVar2 = DAT_009b0120;
    uVar7 = DAT_0099d080;
    if (puStack_68 == (undefined4 *)0x0) {
      puStack_68 = (undefined4 *)0x0;
    }
    else {
      puStack_68[0xb] = 0;
      puStack_68[0xc] = 0;
      puStack_68[0xd] = 0;
      *puStack_68 = uVar7;
      puStack_68[2] = uVar7;
      puStack_68[3] = 0;
      puStack_68[4] = 0;
      uStack_5c = 0;
      puStack_68[6] = 0;
      pvStack_58 = (void *)0x0;
      puStack_68[7] = 0;
      iStack_54 = 0;
      puStack_68[1] = uVar2;
      *(undefined2 *)(puStack_68 + 5) = 100;
      puStack_68[8] = 0;
      puStack_68[9] = 0;
    }
    uStack_6c = (uint)*pbVar5;
    FUN_004ff1a0(auStack_64,&uStack_6c);
    piVar4 = (int *)(**(code **)(*DAT_00b5abac + 0xc))();
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(s_Producer_char_createinfo_txt_009b4b28,0x1c);
  iVar6 = FUN_00410500(auStack_40);
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (iVar6 == 0) {
    uStack_44 = 0xf;
    uStack_48 = 0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    FUN_00401740(s_pScriptRes____NULL_009b4b48,0x12);
    FUN_00406880(&uStack_5c);
    if (uStack_44 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_58);
    return;
  }
  *(undefined4 *)(*(int *)(iVar6 + 0x4c) + 4) = 0;
  cVar3 = FUN_0049d7c0();
  local_78 = in_ECX;
  while( true ) {
    if (cVar3 != '\0') {
      (**(code **)(*DAT_00b5a7cc + 0x1c))(iVar6);
      return;
    }
    puVar8 = &uStack_5c;
    pvStack_58 = (void *)0x0;
    iStack_54 = 0;
    uStack_50 = 0;
    uVar7 = FUN_0049d800(auStack_24);
    FUN_00405670(uVar7,puVar8);
    if (0xf < uStack_c) break;
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    if ((pvStack_58 != (void *)0x0) &&
       (local_78 = (iStack_54 - (int)pvStack_58) / 0x1c, local_78 != 0)) {
      FUN_004fd630(iVar6,&uStack_5c);
    }
    FUN_0049d780();
    if (pvStack_58 != (void *)0x0) {
      FUN_00405de0(pvStack_58,iStack_54,&uStack_5c,local_78);
      _free(pvStack_58);
      return;
    }
    pvStack_58 = (void *)0x0;
    iStack_54 = 0;
    uStack_50 = 0;
    cVar3 = FUN_0049d7c0();
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_004fde40 @ 0x004fde40 ====

/* WARNING: Removing unreachable block (ram,0x004fe0fa) */
/* WARNING: Removing unreachable block (ram,0x004fe139) */
/* WARNING: Removing unreachable block (ram,0x004fe0bb) */

void FUN_004fde40(void)

{
  char cVar1;
  undefined4 *_Memory;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 uVar6;
  int in_ECX;
  void *unaff_EBP;
  char *pcStack_48;
  uint *puStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  char acStack_22 [2];
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_38 = 1;
  uStack_3c = 0x4fde5c;
  (**(code **)(*DAT_00b5add8 + 4))();
  uStack_3c = 0x4fde63;
  FUN_004fdbc0();
  uStack_3c = 6;
  puStack_40 = (uint *)s_filter_009b481c;
  uStack_8 = 0xf;
  uStack_c = 0;
  uStack_1c = uStack_1c & 0xffffff00;
  FUN_00401740();
  uStack_3c = 1;
  puStack_40 = &uStack_20;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_10) {
    pcStack_48 = (char *)0x4fdeab;
    _free((void *)0x0);
    return;
  }
  pcStack_48 = s_recreateinfo_009b4824;
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740();
  pcStack_48 = acStack_22 + -6;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_18) {
    _free(unaff_EBP);
    return;
  }
  *(undefined1 *)(in_ECX + 0x4d) = 1;
  uStack_18 = 0xf;
  uStack_1c = 0;
  FUN_00401740(s_Producer_char_createinfo_txt_009b4834,0x1c);
  if (0xf < uStack_18) {
    _free((void *)(((uint)unaff_EBP >> 8) << 8));
    return;
  }
  _Memory = *(undefined4 **)(in_ECX + 0x28);
  puVar2 = (undefined4 *)*_Memory;
  pvVar5 = operator_new(0x84);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uStack_18 = 0xf;
    uStack_1c = 0;
    FUN_00401740(s_Empty_009b4854,5);
    uStack_38 = 1;
    uVar6 = FUN_004b5800(acStack_22 + -0xe);
  }
  *(undefined4 *)(in_ECX + 0x58) = uVar6;
  if (((uStack_38 & 1) != 0) && (0xf < uStack_18)) {
    _free((void *)(((uint)unaff_EBP >> 8) << 8));
    return;
  }
  while (puVar2 != _Memory) {
    FUN_004fcae0(*(undefined2 *)(puVar2[4] + 0x14));
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  (**(code **)(*DAT_00b5a750 + 8))(0xf);
  pvVar5 = operator_new(0x14);
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0050f0d0();
  }
  *(undefined4 *)(in_ECX + 0x50) = uVar6;
  FUN_0050f180(1000);
  *(undefined4 *)(in_ECX + 0x34) = 0xffffffff;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined1 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0xffffffff;
  uStack_1c = 0xf;
  uStack_20 = 0;
  FUN_00401740(s_ds_zfar_120_009b485c,0xb);
  (**(code **)(*DAT_00b5a688 + 4))(acStack_22 + -0x12);
  if (uStack_20 < 0x10) {
    uStack_20 = 0xf;
    FUN_00401740(s_rc_waterlevel_2_009b4868,0xf);
    (**(code **)(*DAT_00b5a688 + 4))(&uStack_38);
    uStack_38 = uStack_38 & 0xffffff00;
    FUN_00401740(s_rc_mipmap__10_009b4878,0xd);
    (**(code **)(*DAT_00b5a688 + 4))(&uStack_3c);
    uStack_3c = uStack_3c & 0xffffff00;
    FUN_00401740(s_ds_lod_0_009b4888,8);
    (**(code **)(*DAT_00b5a688 + 4))(&puStack_40);
    pcStack_48 = (char *)(uint)*(byte *)(in_ECX + 4);
    FUN_004fd8c0(&pcStack_48);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_004fe170 @ 0x004fe170 ====

undefined4 FUN_004fe170(int param_1)

{
  int iVar1;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_filter_009b48cc,6);
  if (iVar1 != 0) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_recreateinfo_009b48d8,0xc);
    if (iVar1 == 0) {
      FUN_004fdbc0();
    }
    return 0;
  }
  iVar1 = FUN_00459160(local_1c,0);
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),&DAT_009b48d4,1);
  if (local_4 < 0x10) {
    *(bool *)(in_ECX + 0x4d) = iVar1 != 0;
    return 1;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_004fe210 @ 0x004fe210 ====

void FUN_004fe210(uint param_1)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x58) != 0) && (*(char *)(in_ECX + 0x4c) != '\0')) {
    do {
      cVar2 = FUN_004b59a0();
    } while (cVar2 == '\0');
    param_1 = (uint)*(byte *)(in_ECX + 4);
    *(undefined1 *)(in_ECX + 0x4c) = 0;
    FUN_004fd8c0(&param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 0x50);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0xc) != '\0') {
      param_1 = *(undefined4 *)(param_1 + 4);
      FUN_0050f0f0(&param_1);
      return;
    }
    if (*(int *)(iVar1 + 0x10) == 2) {
      puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = &PTR_FUN_009b4ba0;
        FUN_00797a20(puVar3);
        return;
      }
      FUN_00797a20(0);
    }
  }
  return;
}


// ==== FUN_004fe2b0 @ 0x004fe2b0 ====

undefined4 FUN_004fe2b0(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_e4 [7];
  undefined1 auStack_c8 [28];
  undefined1 auStack_ac [28];
  undefined1 auStack_90 [144];
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 0:
    FUN_0050f200(500);
    return 1;
  case 1:
    iVar2 = (**(code **)(*DAT_00b5a74c + 0xc))(0xf);
    if (iVar2 == 0) {
      FUN_00401830(s_pUIHandler____NULL_009b48e8);
      FUN_00406880(auStack_90);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piVar1 = *(int **)(iVar2 + 4);
    if (piVar1 == (int *)0x0) {
      FUN_00401830(s_pWindow____NULL_009b48fc);
      FUN_00406880(auStack_ac);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00401830(s_edit_text_009b490c);
    (**(code **)(*piVar1 + 0x34))(auStack_c8);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 2:
    *(undefined4 *)(in_ECX + 0x48) = 1;
    return 1;
  case 3:
    *(undefined4 *)(in_ECX + 0x48) = 2;
    return 1;
  case 4:
    *(undefined1 *)(in_ECX + 4) = 0;
    local_e4[0] = 0;
    FUN_004fd8c0(local_e4);
    return 1;
  case 5:
    *(undefined1 *)(in_ECX + 4) = 1;
    local_e4[0] = 1;
    FUN_004fd8c0(local_e4);
    return 1;
  case 6:
    *(undefined1 *)(in_ECX + 4) = 2;
    local_e4[0] = 2;
    FUN_004fd8c0(local_e4);
    return 1;
  case 7:
    local_e4[0] = 3;
    break;
  case 8:
    *(undefined1 *)(in_ECX + 4) = 4;
    local_e4[0] = 4;
    FUN_004fd8c0(local_e4);
    return 1;
  case 9:
    local_e4[0] = 5;
    break;
  case 10:
    *(undefined4 *)(in_ECX + 8) = 0;
    return 1;
  case 0xb:
    *(undefined4 *)(in_ECX + 8) = 7;
    return 1;
  case 0xc:
    *(undefined4 *)(in_ECX + 0x48) = 0;
    return 0;
  case 0xd:
    local_e4[0] = *(undefined4 *)(param_1 + 8);
    FUN_004fc7f0(local_e4);
  default:
    return 0;
  }
  *(char *)(in_ECX + 4) = (char)local_e4[0];
  FUN_004fd8c0(local_e4);
  return 1;
}


// ==== FUN_004fe670 @ 0x004fe670 ====

void FUN_004fe670(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  uint uStack_14;
  
  *in_ECX = &PTR_FUN_009b4bcc;
  uStack_14 = 0x4fe687;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uStack_14 = in_ECX[3];
  (**(code **)(*piVar1 + 8))(s___SceneModel_Game_CharCreateScen_009b47f4,0x38,0);
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  FUN_004fc590();
  if (in_ECX[0xb] != 0) {
    uStack_14 = uStack_14 & 0xffffff00;
    FUN_004ff8d0(*(undefined4 *)in_ECX[10],(undefined4 *)in_ECX[10],uStack_14);
    FUN_004feb90(*(undefined4 *)(in_ECX[10] + 4));
    *(undefined4 *)(in_ECX[10] + 4) = in_ECX[10];
    in_ECX[0xb] = 0;
    *(undefined4 *)in_ECX[10] = in_ECX[10];
    *(undefined4 *)(in_ECX[10] + 8) = in_ECX[10];
  }
  if ((undefined4 *)in_ECX[0x14] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x14])(1);
  }
  in_ECX[0x14] = 0;
  if ((undefined4 *)in_ECX[0x17] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x17])(1);
  }
  in_ECX[0x17] = 0;
  FUN_004ff260(&uStack_14,*(undefined4 *)in_ECX[10],(undefined4 *)in_ECX[10]);
  _free((void *)in_ECX[10]);
  return;
}


// ==== FUN_004fe780 @ 0x004fe780 ====

void FUN_004fe780(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *pvStack_20;
  void *apvStack_1c [2];
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint uStack_8;
  
  (**(code **)(*DAT_00b5a6e4 + 8))();
  FUN_00401740(s_rc_waterlevel__d_009b4894,0x10);
  uVar2 = FUN_00404230(apvStack_1c);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  FUN_00401740(s_rc_mipmap_0_009b48a8,0xb);
  (**(code **)(*DAT_00b5a688 + 4))(&pvStack_20);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  FUN_00401740(s_filter_009b48b4,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(apvStack_1c + -2);
  if (0xf < uStack_10) {
    _free(unaff_EBX);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_recreateinfo_009b48bc,0xc);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(apvStack_1c + -3);
  if (0xf < uStack_14) {
    _free(unaff_EBP);
    return;
  }
  (**(code **)(*DAT_00b5a750 + 0xc))(0xf);
  FUN_004fc590();
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 0xc);
    *puVar3 = &PTR_FUN_009b4b8c;
    puVar3[1] = uVar1;
  }
  FUN_00797a20(puVar3);
  if (*(undefined4 **)(in_ECX + 0x58) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x58))(1);
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  if (*(undefined4 **)(in_ECX + 0x50) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x50))(1);
  }
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined1 *)(in_ECX + 0x4c) = 1;
  FUN_004de2a0(1,*(undefined4 *)(in_ECX + 0x54));
  if (*(int *)(in_ECX + 0x2c) != 0) {
    FUN_004ff8d0(**(undefined4 **)(in_ECX + 0x28),*(undefined4 **)(in_ECX + 0x28),uVar2 & 0xffffff00
                );
    FUN_004feb90(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 4));
    *(int *)(*(int *)(in_ECX + 0x28) + 4) = *(int *)(in_ECX + 0x28);
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x28);
    *(int *)(*(int *)(in_ECX + 0x28) + 8) = *(int *)(in_ECX + 0x28);
  }
  return;
}


// ==== FUN_004fe970 @ 0x004fe970 ====

undefined4 FUN_004fe970(int *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x20010023) {
    if (uVar2 == 0x20010022) {
      cVar1 = FUN_004fc870(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if (uVar2 == 0x40001) {
      FUN_004fe210(param_1);
    }
    else if (uVar2 == 0x50011) {
      cVar1 = FUN_004fd190(param_1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else if ((uVar2 == 0x70004) && (cVar1 = FUN_004fe170(param_1), cVar1 != '\0')) {
      return 1;
    }
  }
  else {
    if (uVar2 == 0x30030100) {
      FUN_004fd1c0(param_1);
      return 1;
    }
    if ((uVar2 == 0x30030119) && (cVar1 = FUN_004fe2b0(param_1), cVar1 != '\0')) {
      return 1;
    }
  }
  if ((*(int *)(in_ECX + 0x5c) != 0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 0x5c) + 4))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  if ((*(int *)(in_ECX + 0x20) == 0) || (cVar1 = FUN_005084d0(param_1), cVar1 == '\0')) {
    return 0;
  }
  return 1;
}


// ==== FUN_004fea40 @ 0x004fea40 ====

undefined4 FUN_004fea40(void)

{
  return 0x2001ffff;
}


// ==== FUN_004fea50 @ 0x004fea50 ====

undefined4 FUN_004fea50(void)

{
  return 0x50010001;
}


// ==== FUN_004fea60 @ 0x004fea60 ====

void * FUN_004fea60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981560;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x18);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00535310(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004fead5 @ 0x004fead5 ====

void Catch_004fead5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004feaf0 @ 0x004feaf0 ====

void FUN_004feaf0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981570;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 5) = 1;
  *(undefined1 *)((int)puVar1 + 0x15) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@004feb7a @ 0x004feb7a ====

void Catch_004feb7a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004feb90 @ 0x004feb90 ====

void FUN_004feb90(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_004feb90(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004febd0 @ 0x004febd0 ====

undefined4 FUN_004febd0(void)

{
  return 0x30030100;
}


// ==== FUN_004febe0 @ 0x004febe0 ====

void FUN_004febe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b4bb4;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_004fec10 @ 0x004fec10 ====

void FUN_004fec10(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 2) = 1;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  return;
}


// ==== FUN_004fec40 @ 0x004fec40 ====

void FUN_004fec40(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x24) = 0xf;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  in_ECX[0x10] = 0;
  FUN_00401660(param_1 + 0xc,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x40) = 0xf;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  in_ECX[0x2c] = 0;
  FUN_00401660(param_1 + 0x28,0,0xffffffff);
  return;
}


// ==== FUN_004fecb0 @ 0x004fecb0 ====

void FUN_004fecb0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = 0xf;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  in_ECX[0x10] = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x40) = 0xf;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  in_ECX[0x2c] = 0;
  FUN_00401660(param_2,0,0xffffffff);
  uVar1 = DAT_0099d080;
  in_ECX[3] = 0;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  return;
}


// ==== FUN_004fed20 @ 0x004fed20 ====

void FUN_004fed20(int param_1)

{
  if (0xf < *(uint *)(param_1 + 0x40)) {
    _free(*(void **)(param_1 + 0x2c));
    return;
  }
  *(undefined4 *)(param_1 + 0x40) = 0xf;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  if (*(uint *)(param_1 + 0x24) < 0x10) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0xf;
    *(undefined1 *)(param_1 + 0x10) = 0;
    return;
  }
  _free(*(void **)(param_1 + 0x10));
  return;
}


// ==== FUN_004fed70 @ 0x004fed70 ====

void FUN_004fed70(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  FUN_00401660(param_1 + 0x20,0,0xffffffff);
  return;
}


// ==== FUN_004fedd0 @ 0x004fedd0 ====

void FUN_004fedd0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x1ffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004fea60(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x14);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x14) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[5] == '\0') {
LAB_004feed5:
        *(undefined1 *)(*piVar5 + 0x14) = 1;
        *(undefined1 *)(piVar6 + 5) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x14) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00448a00(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x14) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x14) = 0;
        FUN_00519c40(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[5] == '\0') goto LAB_004feed5;
      if (piVar7 == (int *)*piVar2) {
        FUN_00519c40(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x14) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x14) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x15) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x14);
  } while( true );
}


// ==== FUN_004fefb0 @ 0x004fefb0 ====

undefined1 * FUN_004fefb0(int param_1,int param_2,undefined1 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x44;
    puVar2 = param_3 + -0x44;
    *puVar2 = *(undefined1 *)(param_2 + -0x44);
    param_3[-0x43] = *(undefined1 *)(param_2 + -0x43);
    param_3[-0x42] = *(undefined1 *)(param_2 + -0x42);
    param_3[-0x41] = *(undefined1 *)(param_2 + -0x41);
    *(undefined4 *)(param_3 + -0x40) = *(undefined4 *)(param_2 + -0x40);
    *(undefined4 *)(param_3 + -0x3c) = *(undefined4 *)(param_2 + -0x3c);
    FUN_00401660(param_2 + -0x38,0,0xffffffff);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_004ff020 @ 0x004ff020 ====

void FUN_004ff020(int param_1,int param_2)

{
  uint *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (uint *)(param_1 + 0x40);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      if (0xf < puVar1[-7]) {
        _free((void *)puVar1[-0xc]);
        return;
      }
      puVar1[-7] = 0xf;
      puVar1[-8] = 0;
      *(undefined1 *)(puVar1 + -0xc) = 0;
      param_1 = param_1 + 0x44;
      puVar1 = puVar1 + 0x11;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_004ff080 @ 0x004ff080 ====

void FUN_004ff080(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    FUN_004fec40(param_2);
  }
  return;
}


// ==== FUN_004ff0a0 @ 0x004ff0a0 ====

int FUN_004ff0a0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981580;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x44) {
    FUN_004ff080(param_3,param_1);
    param_3 = param_3 + 0x44;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004ff10a @ 0x004ff10a ====

void Catch_004ff10a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_004fed20(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004ff130 @ 0x004ff130 ====

void FUN_004ff130(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[3] = param_3[3];
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 4);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
      FUN_00401660(param_3 + 0xc,0,0xffffffff);
      FUN_00401660(param_3 + 0x28,0,0xffffffff);
      param_1 = param_1 + 0x44;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_004ff1a0 @ 0x004ff1a0 ====

void FUN_004ff1a0(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  bool bVar5;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      bVar5 = *param_2 < (uint)puVar4[3];
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004fedd0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004fedd0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004ff260 @ 0x004ff260 ====

void FUN_004ff260(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004feb90(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x15) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x15);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x15);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0051a2a0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004ff320 @ 0x004ff320 ====

void FUN_004ff320(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981590;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_004ff080(param_1,param_3);
    param_1 = param_1 + 0x44;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004ff38a @ 0x004ff38a ====

void Catch_004ff38a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_004fed20(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004ff3b0 @ 0x004ff3b0 ====

void FUN_004ff3b0(undefined4 param_1,undefined4 param_2)

{
  FUN_004ff020(param_1,param_2);
  return;
}


// ==== FUN_004ff3d0 @ 0x004ff3d0 ====

void FUN_004ff3d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004ff0a0(param_1,param_2,param_3);
  return;
}


// ==== FUN_004ff3f0 @ 0x004ff3f0 ====

int FUN_004ff3f0(int param_1,int param_2,undefined4 param_3)

{
  FUN_004ff320(param_1,param_2,param_3);
  return param_1 + param_2 * 0x44;
}


// ==== FUN_004ff420 @ 0x004ff420 ====

void FUN_004ff420(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_80 [2];
  undefined1 auStack_7e [14];
  void *local_70;
  uint local_5c;
  void *local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  int local_2c;
  uint local_28;
  void *local_20;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009815a0;
  local_10 = ExceptionList;
  local_14 = local_80 + -0xc;
  ExceptionList = &local_10;
  FUN_004fec40(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x44;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    if (0x3c3c3c3U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x3c3c3c3 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_005d0c90();
        uVar4 = iVar2 + param_2;
      }
      local_28 = uVar4 * 0x44;
      local_20 = operator_new(local_28);
      local_8 = 0;
      local_18 = local_20;
      local_18 = (void *)FUN_004ff3d0(*(undefined4 *)(in_ECX + 4),param_1,local_20);
      local_18 = (void *)FUN_004ff3f0(local_18,param_2,local_80);
      FUN_004ff3d0(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
      }
      if (iVar2 != 0) {
        FUN_004ff020(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_28 + (int)local_20;
      *(void **)(in_ECX + 8) = (void *)((int)local_20 + (param_2 + iVar1) * 0x44);
      *(void **)(in_ECX + 4) = local_20;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x44) < param_2) {
        local_1c = param_2 * 0x44;
        FUN_004ff0a0(param_1,local_2c,local_1c + param_1);
        local_8 = 2;
        FUN_004ff3f0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x44,local_80
                    );
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_1c;
        FUN_004ff130(param_1,*(int *)(in_ECX + 8) - local_1c,local_80);
      }
      else {
        local_1c = param_2 * 0x44;
        iVar2 = local_2c + param_2 * -0x44;
        uVar3 = FUN_004ff0a0(iVar2,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_004fefb0(param_1,iVar2,local_2c,local_3c);
        FUN_004ff130(param_1,local_1c + param_1,local_80);
      }
    }
  }
  if (0xf < local_40) {
    _free(local_54);
    return;
  }
  local_40 = 0xf;
  local_44 = 0;
  local_54 = (void *)((uint)local_54 & 0xffffff00);
  if (local_5c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_70);
  return;
}


// ==== Catch@004ff5d7 @ 0x004ff5d7 ====

void Catch_004ff5d7(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x1c);
  FUN_004ff3b0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@004ff68f @ 0x004ff68f ====

void Catch_004ff68f(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x44;
  FUN_004ff3b0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x20) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004ff750 @ 0x004ff750 ====

void FUN_004ff750(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_004ff020(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004ff790 @ 0x004ff790 ====

void FUN_004ff790(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x44 != 0) {
      iVar1 = (param_2 - iVar1) / 0x44;
      goto LAB_004ff7d5;
    }
  }
  iVar1 = 0;
LAB_004ff7d5:
  FUN_004ff420(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x44;
  return;
}


// ==== FUN_004ff800 @ 0x004ff800 ====

void FUN_004ff800(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x44) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x44))) {
    FUN_004ff790(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004ff320(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x44;
  return;
}


// ==== FUN_004ff890 @ 0x004ff890 ====

int FUN_004ff890(int param_1)

{
  char cVar1;
  undefined *puVar2;
  char *pcVar3;
  
  puVar2 = PTR_s_SceneCharCreate_00aea620;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar3 = puVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(puVar2,(int)pcVar3 - (int)(puVar2 + 1));
  return param_1;
}


// ==== FUN_004ff8d0 @ 0x004ff8d0 ====

uint FUN_004ff8d0(int *param_1,int *param_2,byte param_3)

{
  char cVar1;
  void *_Memory;
  int iVar2;
  int *piVar3;
  int *piVar4;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  int iVar5;
  
  while( true ) {
    if (param_1 == param_2) {
      return (uint)param_3;
    }
    _Memory = (void *)param_1[4];
    if (_Memory != (void *)0x0) break;
    if (*(char *)((int)param_1 + 0x15) == '\0') {
      piVar3 = (int *)param_1[2];
      if (*(char *)((int)piVar3 + 0x15) == '\0') {
        cVar1 = *(char *)(*piVar3 + 0x15);
        param_1 = piVar3;
        piVar3 = (int *)*piVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          param_1 = piVar3;
          piVar3 = (int *)*piVar3;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x15);
        piVar4 = (int *)param_1[1];
        piVar3 = param_1;
        while ((param_1 = piVar4, cVar1 == '\0' && (piVar3 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x15);
          piVar4 = (int *)param_1[1];
          piVar3 = param_1;
        }
      }
    }
  }
  iVar5 = *(int *)((int)_Memory + 0x2c);
  if (iVar5 == 0) {
    *(undefined4 *)((int)_Memory + 0x2c) = 0;
    *(undefined4 *)((int)_Memory + 0x30) = 0;
    *(undefined4 *)((int)_Memory + 0x34) = 0;
    _free(_Memory);
    return extraout_EAX_01;
  }
  iVar2 = *(int *)((int)_Memory + 0x30);
  while( true ) {
    if (iVar5 == iVar2) {
      _free(*(void **)((int)_Memory + 0x2c));
      return extraout_EAX_00;
    }
    if (0xf < *(uint *)(iVar5 + 0x18)) break;
    *(undefined4 *)(iVar5 + 0x18) = 0xf;
    *(undefined4 *)(iVar5 + 0x14) = 0;
    *(undefined1 *)(iVar5 + 4) = 0;
    iVar5 = iVar5 + 0x1c;
  }
  _free(*(void **)(iVar5 + 4));
  return extraout_EAX;
}


// ==== FUN_004ff9a0 @ 0x004ff9a0 ====

void FUN_004ff9a0(byte param_1)

{
  void *in_ECX;
  
  FUN_004fe670();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ff9d0 @ 0x004ff9d0 ====

undefined1 FUN_004ff9d0(void)

{
  return 0;
}


// ==== FUN_004ff9f0 @ 0x004ff9f0 ====

uint FUN_004ff9f0(int param_1)

{
  uint in_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x74) != 0) {
    if (*(int *)(param_1 + 4) == 0x26) {
      *(undefined4 *)(in_ECX + 0x70) = 0;
      in_EAX = 0;
    }
    else {
      in_EAX = *(int *)(param_1 + 4) - 0x28;
      if (in_EAX == 0) {
        *(undefined4 *)(in_ECX + 0x70) = 2;
        return 0;
      }
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_004ffa20 @ 0x004ffa20 ====

uint FUN_004ffa20(int param_1)

{
  uint in_EAX;
  int in_ECX;
  bool bVar1;
  
  if (*(int *)(in_ECX + 0x74) != 0) {
    if (*(int *)(param_1 + 4) == 0x26) {
      bVar1 = *(int *)(in_ECX + 0x70) == 0;
      in_EAX = 0;
    }
    else {
      in_EAX = *(int *)(param_1 + 4) - 0x28;
      if (in_EAX != 0) goto LAB_004ffa4a;
      bVar1 = *(int *)(in_ECX + 0x70) == 2;
    }
    if (bVar1) {
      *(undefined4 *)(in_ECX + 0x70) = 1;
    }
  }
LAB_004ffa4a:
  return in_EAX & 0xffffff00;
}


// ==== FUN_004ffa50 @ 0x004ffa50 ====

void FUN_004ffa50(void)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x24) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x24))(1);
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  if (*(int **)(in_ECX + 0x20) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 4))();
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar2 + 8))(s___SceneModel_Game_CharSelectScen_009b4cdc,0x6c,0,uVar1);
    if (*(undefined4 **)(in_ECX + 0x20) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x20))(1);
    }
    *(undefined4 *)(in_ECX + 0x20) = 0;
  }
  return;
}


// ==== FUN_004ffab0 @ 0x004ffab0 ====

char FUN_004ffab0(undefined4 param_1,char param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 4))();
    bVar1 = *(byte *)(iVar3 + 0x108);
    if (bVar1 != 0) {
      if ((bVar1 == 0) || (3 < bVar1)) {
        if ((bVar1 < 4) || (cVar4 = '\x02', 6 < bVar1)) {
          cVar4 = '\x03';
        }
      }
      else {
        cVar4 = '\x01';
      }
      if (param_2 != '\0') {
        cVar4 = cVar4 + '\n';
      }
      if (*(char *)(in_ECX + 0x3a) == '\0') {
        uVar7 = 3000;
        uVar6 = 1;
        uVar5 = 0x7000a;
        FUN_00511d10(0x7000a,1,3000);
        FUN_00512cd0();
        FUN_005127a0(uVar5,uVar6,uVar7);
        *(undefined1 *)(in_ECX + 0x3a) = 1;
      }
      return cVar4;
    }
  }
  return '\0';
}


// ==== FUN_004ffb70 @ 0x004ffb70 ====

undefined4 FUN_004ffb70(undefined4 param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  bVar1 = *(byte *)(iVar3 + 0x108);
  if (bVar1 == 0) {
    return 0;
  }
  if (*(char *)(in_ECX + 0x39) == '\0') {
    uVar6 = 3000;
    uVar5 = 1;
    uVar4 = 0x7000a;
    FUN_00511d10(0x7000a,1,3000);
    FUN_00512cd0();
    FUN_005127a0(uVar4,uVar5,uVar6);
    *(undefined1 *)(in_ECX + 0x39) = 1;
  }
  if ((bVar1 != 0) && (bVar1 < 4)) {
    return 1;
  }
  if ((bVar1 < 4) || (uVar4 = 2, 6 < bVar1)) {
    uVar4 = 3;
  }
  return uVar4;
}


// ==== FUN_004ffc00 @ 0x004ffc00 ====

void FUN_004ffc00(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined2 *puVar4;
  
  puVar2 = *(undefined2 **)(in_ECX + 0x44);
  for (puVar4 = *(undefined2 **)(in_ECX + 0x40); puVar4 != puVar2; puVar4 = puVar4 + 1) {
    uVar1 = *puVar4;
    uVar3 = (**(code **)(**(int **)(in_ECX + 0x20) + 4))();
    FUN_004dd240(0x1f,1,uVar1,0,uVar3);
  }
  return;
}


// ==== FUN_004ffc40 @ 0x004ffc40 ====

void FUN_004ffc40(byte *param_1)

{
  ushort uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 uVar5;
  int local_4;
  
  param_1 = (byte *)(uint)*param_1;
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x14)) {
    iVar2 = *(int *)(local_4 + 0x10);
    (**(code **)(*DAT_00b5ad14 + 0x10))(iVar2 + 0x18);
    pvVar3 = operator_new(0x18);
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
      uVar5 = extraout_var;
    }
    else {
      uVar4 = FUN_005084a0();
      uVar5 = extraout_var_00;
    }
    *(undefined4 *)(in_ECX + 0x24) = uVar4;
    FUN_00508750(CONCAT22(uVar5,*(undefined2 *)(iVar2 + 0x14)));
    if (-1 < *(int *)(in_ECX + 100)) {
      FUN_004de2a0(1,*(int *)(in_ECX + 100));
    }
    uVar1 = *(ushort *)(iVar2 + 0x14);
    *(uint *)(in_ECX + 100) = (uint)uVar1;
    FUN_004de2a0(0,(uint)uVar1);
  }
  return;
}


// ==== FUN_004ffce0 @ 0x004ffce0 ====

void FUN_004ffce0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar3 = *(undefined4 **)(in_ECX + 0x50); puVar3 != puVar1; puVar3 = puVar3 + 1) {
    piVar2 = (int *)*puVar3;
    (**(code **)(*piVar2 + 4))();
    (**(code **)(*DAT_00b5a6e0 + 0x10))(1,piVar2);
  }
  if (*(void **)(in_ECX + 0x50) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(undefined4 *)(in_ECX + 0x54) = 0;
    *(undefined4 *)(in_ECX + 0x58) = 0;
    *(undefined4 *)(in_ECX + 0x5c) = 0;
    *(undefined4 *)(in_ECX + 0x60) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x50));
  return;
}


// ==== FUN_004ffd40 @ 0x004ffd40 ====

void FUN_004ffd40(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_004ffce0();
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x2060000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x18;
  iVar2 = FUN_004244d0();
  uVar3 = (**(code **)(*DAT_00b5ac1c + 0x10))();
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  FUN_004d8570(iVar2);
  return;
}


// ==== FUN_004ffd90 @ 0x004ffd90 ====

void FUN_004ffd90(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint unaff_ESI;
  void *pvStack_20;
  void *apvStack_1c [4];
  uint uStack_c;
  uint uStack_8;
  
  (**(code **)(*DAT_00b5a6e4 + 8))();
  FUN_00401740(s_rc_waterlevel__d_009b4d48,0x10);
  uVar2 = FUN_00404230(apvStack_1c);
  (**(code **)(*DAT_00b5a688 + 4))(uVar2);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return;
  }
  uStack_8 = 0xf;
  uStack_c = 0;
  apvStack_1c[0] = (void *)((uint)apvStack_1c[0] & 0xffffff00);
  FUN_00401740(s_rc_mipmap_0_009b4d5c,0xb);
  (**(code **)(*DAT_00b5a688 + 4))(&pvStack_20);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  if (*(int **)(in_ECX + 0x20) != (int *)0x0) {
    iVar1 = *DAT_00b5ac6c;
    uVar2 = (**(code **)(**(int **)(in_ECX + 0x20) + 4))();
    (**(code **)(iVar1 + 0x18))(uVar2);
  }
  (**(code **)(*DAT_00b5ae30 + 0xc))();
  FUN_004ffa50();
  if (*(undefined4 **)(in_ECX + 0x28) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x28))(1);
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    uVar2 = *(undefined4 *)(in_ECX + 4);
    *puVar3 = &PTR_FUN_009b4b8c;
    puVar3[1] = uVar2;
  }
  FUN_00797a20(puVar3);
  (**(code **)(*DAT_00b5a750 + 0xc))(0x10);
  if (*(undefined4 **)(in_ECX + 0x6c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x6c))(1);
  }
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined1 *)(in_ECX + 0x38) = 1;
  FUN_004de2a0(1,*(undefined4 *)(in_ECX + 100));
  FUN_004ffce0();
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_005354c0(**(undefined4 **)(in_ECX + 0x14),*(undefined4 **)(in_ECX + 0x14),
                 unaff_ESI & 0xffffff00);
    FUN_00503e00(*(undefined4 *)(*(int *)(in_ECX + 0x14) + 4));
    *(int *)(*(int *)(in_ECX + 0x14) + 4) = *(int *)(in_ECX + 0x14);
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x14);
  }
  return;
}


// ==== FUN_004fff20 @ 0x004fff20 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_004fff20(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined1 local_10a4 [4];
  void *pvStack_10a0;
  undefined4 uStack_1090;
  uint uStack_108c;
  undefined1 auStack_1088 [4];
  void *pvStack_1084;
  undefined4 uStack_1074;
  uint uStack_1070;
  void *pvStack_1068;
  undefined4 uStack_1058;
  uint uStack_1054;
  void *pvStack_104c;
  undefined4 uStack_103c;
  uint uStack_1038;
  undefined1 auStack_1034 [4];
  void *pvStack_1030;
  undefined4 uStack_1020;
  uint uStack_101c;
  undefined1 auStack_1018 [4];
  void *pvStack_1014;
  uint uStack_1000;
  undefined4 auStack_ffc [64];
  char acStack_efa [256];
  char acStack_dfa [256];
  char acStack_cfa [256];
  char acStack_bfa [1074];
  char acStack_7c8 [1980];
  undefined4 uStack_c;
  
  uStack_c = 0x4fff30;
  piVar2 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s__s__u_009b4d78,5);
    uVar3 = FUN_00404230(auStack_1018);
    FUN_00796d50(uVar3);
    if (0xf < uStack_1000) {
      _free(pvStack_1014);
      return;
    }
  }
  else {
    puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
    puVar7 = auStack_ffc;
    for (iVar6 = 0x3fb; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    }
    pcVar5 = acStack_efa;
    uStack_101c = 0xf;
    uStack_1020 = 0;
    pvStack_1030 = (void *)((uint)pvStack_1030 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_efa,(int)pcVar5 - (int)(acStack_efa + 1));
    pcVar5 = acStack_dfa;
    uStack_1070 = 0xf;
    uStack_1074 = 0;
    pvStack_1084 = (void *)((uint)pvStack_1084 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_dfa,(int)pcVar5 - (int)(acStack_dfa + 1));
    pcVar5 = acStack_cfa;
    uStack_1038 = 0xf;
    uStack_103c = 0;
    pvStack_104c = (void *)((uint)pvStack_104c & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_cfa,(int)pcVar5 - (int)(acStack_cfa + 1));
    pcVar5 = acStack_bfa;
    uStack_1054 = 0xf;
    uStack_1058 = 0;
    pvStack_1068 = (void *)((uint)pvStack_1068 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_bfa,(int)pcVar5 - (int)(acStack_bfa + 1));
    pcVar5 = acStack_7c8;
    uStack_108c = 0xf;
    uStack_1090 = 0;
    pvStack_10a0 = (void *)((uint)pvStack_10a0 & 0xffffff00);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(acStack_7c8,(int)pcVar5 - (int)(acStack_7c8 + 1));
    FUN_004b5bf0(1,auStack_1034);
    FUN_004b5bf0(2,auStack_1088);
    FUN_004b5bf0(0x15,local_10a4);
    if (0xf < uStack_108c) {
      _free(pvStack_10a0);
      return;
    }
    uStack_108c = 0xf;
    uStack_1090 = 0;
    pvStack_10a0 = (void *)((uint)pvStack_10a0 & 0xffffff00);
    if (0xf < uStack_1054) {
      _free(pvStack_1068);
      return;
    }
    uStack_1054 = 0xf;
    uStack_1058 = 0;
    pvStack_1068 = (void *)((uint)pvStack_1068 & 0xffffff00);
    if (0xf < uStack_1038) {
      _free(pvStack_104c);
      return;
    }
    uStack_1038 = 0xf;
    uStack_103c = 0;
    pvStack_104c = (void *)((uint)pvStack_104c & 0xffffff00);
    if (0xf < uStack_1070) {
      _free(pvStack_1084);
      return;
    }
    uStack_1070 = 0xf;
    uStack_1074 = 0;
    pvStack_1084 = (void *)((uint)pvStack_1084 & 0xffffff00);
    if (0xf < uStack_101c) {
      _free(pvStack_1030);
      return;
    }
  }
  return;
}


