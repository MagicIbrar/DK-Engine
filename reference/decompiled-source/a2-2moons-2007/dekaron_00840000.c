// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x840000-0x84ffff

// ==== FUN_00840020 @ 0x00840020 ====

undefined4 FUN_00840020(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  undefined4 uVar5;
  float fVar6;
  
  if (*(char *)(in_ECX + 9) == '\0') {
    if ((((*(int **)(in_ECX + 0x50) == (int *)0x0) || (*(int *)(in_ECX + 0x54) == 0)) ||
        (cVar1 = (**(code **)(**(int **)(in_ECX + 0x50) + 0x2c))(), cVar1 == '\0')) ||
       (cVar1 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x2c))(), cVar1 == '\0')) {
      return 0;
    }
    *(undefined1 *)(in_ECX + 9) = 1;
    uVar2 = FUN_004b9c10();
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        iVar3 = FUN_004ba010(uVar4);
        if (iVar3 != 0) {
          if (*(float *)(iVar3 + 0x10) < *(float *)(in_ECX + 0x38) ||
              *(float *)(iVar3 + 0x10) == *(float *)(in_ECX + 0x38)) {
            uVar5 = *(undefined4 *)(iVar3 + 0x10);
          }
          else {
            uVar5 = *(undefined4 *)(in_ECX + 0x38);
          }
          *(undefined4 *)(in_ECX + 0x38) = uVar5;
          if (*(float *)(iVar3 + 0x14) < *(float *)(in_ECX + 0x3c) ||
              *(float *)(iVar3 + 0x14) == *(float *)(in_ECX + 0x3c)) {
            uVar5 = *(undefined4 *)(iVar3 + 0x14);
          }
          else {
            uVar5 = *(undefined4 *)(in_ECX + 0x3c);
          }
          *(undefined4 *)(in_ECX + 0x3c) = uVar5;
          if (*(float *)(iVar3 + 0x18) < *(float *)(in_ECX + 0x40) ||
              *(float *)(iVar3 + 0x18) == *(float *)(in_ECX + 0x40)) {
            uVar5 = *(undefined4 *)(iVar3 + 0x18);
          }
          else {
            uVar5 = *(undefined4 *)(in_ECX + 0x40);
          }
          *(undefined4 *)(in_ECX + 0x40) = uVar5;
          fVar6 = *(float *)(in_ECX + 0x44);
          if (fVar6 < *(float *)(iVar3 + 0x1c) || fVar6 == *(float *)(iVar3 + 0x1c)) {
            fVar6 = *(float *)(iVar3 + 0x1c);
          }
          *(float *)(in_ECX + 0x44) = fVar6;
          fVar6 = *(float *)(in_ECX + 0x48);
          if (fVar6 < *(float *)(iVar3 + 0x20) || fVar6 == *(float *)(iVar3 + 0x20)) {
            fVar6 = *(float *)(iVar3 + 0x20);
          }
          *(float *)(in_ECX + 0x48) = fVar6;
          fVar6 = *(float *)(in_ECX + 0x4c);
          if (fVar6 < *(float *)(iVar3 + 0x24) || fVar6 == *(float *)(iVar3 + 0x24)) {
            fVar6 = *(float *)(iVar3 + 0x24);
          }
          *(float *)(in_ECX + 0x4c) = fVar6;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
  }
  return 1;
}


// ==== FUN_00840130 @ 0x00840130 ====

void FUN_00840130(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_009b0318;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[3] = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  in_ECX[0xe] = uVar2;
  in_ECX[0xf] = uVar2;
  uVar1 = DAT_0099d0b4;
  in_ECX[0x10] = uVar2;
  in_ECX[0x11] = uVar1;
  in_ECX[0x12] = uVar1;
  *in_ECX = &PTR_FUN_00a0fdc0;
  in_ECX[0x13] = uVar1;
  return;
}


// ==== FUN_008401c0 @ 0x008401c0 ====

void FUN_008401c0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  if ((*(char *)(in_ECX + 8) == '\0') &&
     (iVar1 = (**(code **)(*DAT_00b5a6dc + 0x18))
                        (*(undefined4 *)(in_ECX + 0xc),*(undefined2 *)(in_ECX + 0x10)), iVar1 != 0))
  {
    uVar2 = FUN_005b1c00(iVar1 + 0xb4);
    *(undefined4 *)(in_ECX + 0x50) = uVar2;
    uVar2 = FUN_005aa220(iVar1 + 0xd0);
    *(undefined4 *)(in_ECX + 0x54) = uVar2;
    *(undefined1 *)(in_ECX + 0x14) = *(undefined1 *)(iVar1 + 0xec);
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(iVar1 + 0xf0);
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0xf4);
    *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(iVar1 + 0xf8);
    *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(iVar1 + 0xfc);
    *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(iVar1 + 0x100);
    *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(iVar1 + 0x104);
    *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(iVar1 + 0x108);
    *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(iVar1 + 0x10c);
    *(undefined1 *)(in_ECX + 9) = 0;
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00840270 @ 0x00840270 ====

void FUN_00840270(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fdc0;
  if (in_ECX[0x14] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x14]);
    in_ECX[0x14] = 0;
  }
  if (in_ECX[0x15] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x15]);
    in_ECX[0x15] = 0;
  }
  *in_ECX = &PTR_FUN_00a0fd9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008402d0 @ 0x008402d0 ====

void FUN_008402d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fe24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008402f0 @ 0x008402f0 ====

void FUN_008402f0(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x008402f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_00840300 @ 0x00840300 ====

int FUN_00840300(void)

{
  int in_ECX;
  
  return in_ECX + 0x34;
}


// ==== FUN_00840310 @ 0x00840310 ====

undefined4 FUN_00840310(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00840320 @ 0x00840320 ====

void FUN_00840320(undefined1 param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xca) == '\x01') {
    *(undefined1 *)(in_ECX + 0xc9) = param_1;
  }
  return;
}


// ==== FUN_00840340 @ 0x00840340 ====

uint FUN_00840340(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 in_EAX;
  uint3 uVar6;
  uint uVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24 [4];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar8 = param_1;
  uVar6 = (uint3)((uint)in_EAX >> 8);
  if (*(char *)(in_ECX + 200) != '\0') {
    return (uint)uVar6 << 8;
  }
  if ((*param_1 == 8) && (*(char *)(in_ECX + 0xca) != '\x02')) {
    return (uint)uVar6 << 8;
  }
  local_48 = *(undefined4 *)(in_ECX + -0x10);
  local_44 = *(undefined4 *)(in_ECX + -0xc);
  local_40 = *(undefined4 *)(in_ECX + -8);
  local_3c = *(undefined4 *)(in_ECX + -0x1c);
  local_38 = *(undefined4 *)(in_ECX + -0x18);
  local_34 = *(undefined4 *)(in_ECX + -0x14);
  local_30 = *(undefined4 *)(in_ECX + -0x10);
  local_2c = *(undefined4 *)(in_ECX + -0xc);
  local_28 = *(undefined4 *)(in_ECX + -8);
  piVar1 = param_1 + 3;
  uVar4 = FUN_0040dfb0(piVar1,&local_3c,&local_48,&param_1);
  if ((char)uVar4 != '\0') {
    piVar9 = local_24;
    for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
      *piVar9 = *piVar8;
      piVar8 = piVar8 + 1;
      piVar9 = piVar9 + 1;
    }
    puVar5 = (undefined4 *)FUN_0040e920(&local_3c,piVar1,in_ECX + 0x114);
    iVar7 = param_2;
    local_24[3] = *puVar5;
    local_14 = puVar5[1];
    local_10 = puVar5[2];
    local_c = puVar5[3];
    local_8 = puVar5[4];
    local_4 = puVar5[5];
    uVar4 = (**(code **)(**(int **)(in_ECX + 0x154) + 0x18))(local_24,param_2);
    if ((char)uVar4 != '\0') {
      iVar2 = iVar7 + 8;
      thunk_FUN_0079e5a0(iVar2,iVar2,in_ECX + 0xd4);
      puVar5 = (undefined4 *)(**(code **)(*(int *)(in_ECX + -0x24) + 8))();
      uVar3 = *puVar5;
      *(undefined4 *)(iVar7 + 4) = uVar3;
      return CONCAT31((int3)((uint)uVar3 >> 8),1);
    }
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_00840490 @ 0x00840490 ====

undefined1 FUN_00840490(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  undefined4 *unaff_retaddr;
  
  cVar1 = (**(code **)(*in_ECX + 0x1c))(param_1,&param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*(int *)in_ECX[0x55] + 8))();
  *unaff_retaddr = *(undefined4 *)(iVar2 + 8);
  return 1;
}


// ==== FUN_00840500 @ 0x00840500 ====

void FUN_00840500(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  *(undefined2 *)(in_ECX + 0xf0) = 0xff;
  *(undefined1 *)(in_ECX + 0x20) = 1;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined1 *)(in_ECX + 0xed) = 0;
  *(undefined1 *)(in_ECX + 0xee) = 0;
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  *(undefined4 *)(in_ECX + 0x178) = 0;
  *(undefined1 *)(in_ECX + 0xec) = 0;
  *(undefined4 *)(in_ECX + 0x170) = 0;
  *(undefined4 *)(in_ECX + 0x16c) = 0;
  *(undefined4 *)(in_ECX + 0x168) = 0;
  *(undefined4 *)(in_ECX + 0x164) = 0;
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  *(undefined4 *)(in_ECX + 0x158) = 0;
  *(undefined4 *)(in_ECX + 0x154) = 0;
  *(undefined4 *)(in_ECX + 0x150) = 0;
  *(undefined4 *)(in_ECX + 0x148) = 0;
  *(undefined4 *)(in_ECX + 0x144) = 0;
  *(undefined4 *)(in_ECX + 0x140) = 0;
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined4 *)(in_ECX + 0x174) = uVar1;
  *(undefined4 *)(in_ECX + 0x160) = uVar1;
  *(undefined4 *)(in_ECX + 0x14c) = uVar1;
  *(undefined4 *)(in_ECX + 0x138) = uVar1;
  *(undefined4 *)(in_ECX + 0x130) = 0;
  *(undefined4 *)(in_ECX + 300) = 0;
  *(undefined4 *)(in_ECX + 0x128) = 0;
  *(undefined4 *)(in_ECX + 0x124) = 0;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  *(undefined4 *)(in_ECX + 0x108) = 0;
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x100) = 0;
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  *(undefined4 *)(in_ECX + 0x134) = uVar1;
  *(undefined4 *)(in_ECX + 0x120) = uVar1;
  *(undefined4 *)(in_ECX + 0x10c) = uVar1;
  *(undefined4 *)(in_ECX + 0xf8) = uVar1;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  return;
}


// ==== FUN_00840690 @ 0x00840690 ====

void FUN_00840690(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) != '\0') {
    (**(code **)(*DAT_00b5afac + 8))(*(undefined4 *)(in_ECX + 0x34),2);
    (**(code **)(*DAT_00b5a720 + 8))(*(undefined4 *)(in_ECX + 0x34));
    if (*(undefined4 **)(in_ECX + 0xa8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0xa8))(1);
    }
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    *(undefined1 *)(in_ECX + 0x28) = 0;
    (**(code **)(*DAT_00b5ac10 + 8))(*(undefined4 *)(in_ECX + 0x178));
  }
  return;
}


// ==== FUN_008406f0 @ 0x008406f0 ====

void FUN_008406f0(float param_1)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if ((*(char *)(in_ECX + 0x20) == '\0') && (*(int *)(in_ECX + 0xa8) != 0)) {
    *(float *)(in_ECX + 0xa4) = param_1 + *(float *)(in_ECX + 0xa4);
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
    if (*(float *)(in_ECX + 0xa4) < *(float *)(iVar1 + 0xc) * DAT_0099d0f8) {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
      if (*(float *)(iVar1 + 0xc) <= *(float *)(in_ECX + 0xa4)) {
        iVar1 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
        *(float *)(in_ECX + 0xa4) = *(float *)(in_ECX + 0xa4) - *(float *)(iVar1 + 0xc);
      }
    }
    else {
      iVar1 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
      fVar2 = (float10)FUN_0040d0a0(0,*(undefined4 *)(iVar1 + 0xc));
      *(float *)(in_ECX + 0xa4) = (float)fVar2;
    }
    uVar4 = 0;
    uVar3 = 0x3f800000;
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))(0x3f800000,0);
    FUN_005ca8b0(*(float *)(in_ECX + 0xa4) / *(float *)(iVar1 + 0xc),uVar3,uVar4);
  }
  return;
}


// ==== FUN_008407d0 @ 0x008407d0 ====

undefined1 FUN_008407d0(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x154) == 0) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x154) + 4))();
  return *(undefined1 *)(iVar1 + 0x1c);
}


// ==== FUN_008407f0 @ 0x008407f0 ====

int * FUN_008407f0(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  
  fVar1 = *(float *)(in_ECX + -0x14);
  fVar2 = *(float *)(in_ECX + -0x10);
  fVar3 = *(float *)(in_ECX + -8);
  *param_1 = (int)*(float *)(in_ECX + -0x1c);
  param_1[1] = (int)fVar1;
  param_1[2] = (int)fVar2 + 1;
  param_1[3] = (int)fVar3 + 1;
  return param_1;
}


// ==== FUN_00840880 @ 0x00840880 ====

bool FUN_00840880(void)

{
  float fVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xec) != '\0') {
    iVar4 = (**(code **)(*DAT_00b5afb4 + 0x10))();
    piVar2 = DAT_00b5a988;
    if (*(char *)(iVar4 + 0xd8) == '\x02') {
      iVar4 = (**(code **)(*DAT_00b5afb4 + 0x10))();
      fVar1 = *(float *)(iVar4 + 0xd0);
      iVar4 = (**(code **)(*piVar2 + 0x14))();
      if (fVar1 < *(float *)(iVar4 + 0x2c)) {
        return true;
      }
    }
  }
  cVar3 = (**(code **)(*DAT_00b5a988 + 0x24))
                    (*(float *)(in_ECX + 0x30) + DAT_009b0120,in_ECX + 0x54);
  return cVar3 == '\x01';
}


// ==== FUN_00840910 @ 0x00840910 ====

void FUN_00840910(int param_1)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined4 uVar4;
  int in_ECX;
  
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  sVar2 = FUN_00802534();
  *(undefined4 *)(in_ECX + 0xf4) = uVar4;
  cVar1 = FUN_00840880();
  if (cVar1 != '\0') {
    sVar2 = *(short *)(in_ECX + 0xf0) - sVar2;
    if (0xff < sVar2) {
      *(undefined2 *)(in_ECX + 0xf0) = 0xff;
      *(undefined1 *)(param_1 + 0x23) = 1;
      *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(in_ECX + 0xf0);
      return;
    }
    if (sVar2 < 0) {
      sVar2 = 0;
    }
    *(short *)(in_ECX + 0xf0) = sVar2;
    *(undefined1 *)(param_1 + 0x23) = 1;
    *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(in_ECX + 0xf0);
    return;
  }
  if (*(char *)(in_ECX + 0xed) == '\0') {
    if (*(char *)(in_ECX + 0xee) == '\x01') {
      sVar2 = *(short *)(in_ECX + 0xf0) + sVar2;
      if (sVar2 < 0x100) {
        if (sVar2 < 0) {
          sVar2 = 0;
        }
      }
      else {
        sVar2 = 0xff;
      }
      *(short *)(in_ECX + 0xf0) = sVar2;
      if (0xfe < sVar2) {
        *(undefined1 *)(param_1 + 0x23) = 0;
        return;
      }
      *(undefined1 *)(param_1 + 0x23) = 1;
      *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(in_ECX + 0xf0);
    }
    return;
  }
  if (*(char *)(in_ECX + 0xee) != '\x01') {
    return;
  }
  sVar3 = *(short *)(in_ECX + 0xf0);
  if (sVar3 < 0x29) {
    sVar3 = sVar3 + sVar2;
    if (sVar3 < 0x29) {
      if (sVar3 < 0) {
        sVar3 = 0;
      }
      goto LAB_00840a0e;
    }
  }
  else {
    sVar3 = sVar3 - sVar2;
    if (0xff < sVar3) {
      sVar3 = 0xff;
      goto LAB_00840a0e;
    }
    if (0x27 < sVar3) goto LAB_00840a0e;
  }
  sVar3 = 0x28;
LAB_00840a0e:
  *(short *)(in_ECX + 0xf0) = sVar3;
  *(undefined1 *)(param_1 + 0x23) = 1;
  *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(in_ECX + 0xf0);
  return;
}


// ==== FUN_00840a90 @ 0x00840a90 ====

void FUN_00840a90(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0 [16];
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  uVar1 = *(undefined4 *)(in_ECX + 0x70);
  local_cc = *(undefined4 *)(in_ECX + 0x54);
  local_c8 = *(undefined4 *)(in_ECX + 0x2c);
  local_c4 = *(undefined4 *)(in_ECX + 0x58);
  thunk_FUN_0079f761(local_c0,uVar1,uVar1,uVar1);
  puVar2 = local_c0;
  puVar4 = local_80;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2 = (undefined4 *)FUN_005cd200(local_40,&local_cc,in_ECX + 0x5c,local_80);
  puVar4 = (undefined4 *)(in_ECX + 0xf8);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_0079f3a1(in_ECX + 0x138,0,(undefined4 *)(in_ECX + 0xf8));
  return;
}


// ==== FUN_00840b30 @ 0x00840b30 ====

void FUN_00840b30(void)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  int in_ECX;
  uint uVar6;
  float unaff_ESI;
  undefined4 uVar7;
  float fVar8;
  float local_30;
  float local_2c;
  float local_28;
  float afStack_24 [3];
  undefined1 auStack_18 [24];
  
  fVar8 = DAT_009b0318;
  local_30 = DAT_0099d0b4;
  pfVar1 = (float *)(in_ECX + 8);
  *pfVar1 = DAT_009b0318;
  *(float *)(in_ECX + 0xc) = fVar8;
  *(float *)(in_ECX + 0x10) = fVar8;
  pfVar2 = (float *)(in_ECX + 0x14);
  local_2c = local_30;
  *pfVar2 = local_30;
  local_28 = local_30;
  *(float *)(in_ECX + 0x18) = local_30;
  *(float *)(in_ECX + 0x1c) = local_30;
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x178) + 0xc))();
  if (iVar3 != 0) {
    uVar4 = FUN_004b9c10();
    uVar6 = 0;
    if (uVar4 != 0) {
      do {
        iVar3 = FUN_004ba010(uVar6);
        if (iVar3 != 0) {
          if (*(float *)(iVar3 + 0x10) < *pfVar1 || *(float *)(iVar3 + 0x10) == *pfVar1) {
            fVar8 = *(float *)(iVar3 + 0x10);
          }
          else {
            fVar8 = *pfVar1;
          }
          *pfVar1 = fVar8;
          if (*(float *)(iVar3 + 0x14) < *(float *)(in_ECX + 0xc) ||
              *(float *)(iVar3 + 0x14) == *(float *)(in_ECX + 0xc)) {
            uVar7 = *(undefined4 *)(iVar3 + 0x14);
          }
          else {
            uVar7 = *(undefined4 *)(in_ECX + 0xc);
          }
          *(undefined4 *)(in_ECX + 0xc) = uVar7;
          if (*(float *)(iVar3 + 0x18) < *(float *)(in_ECX + 0x10) ||
              *(float *)(iVar3 + 0x18) == *(float *)(in_ECX + 0x10)) {
            uVar7 = *(undefined4 *)(iVar3 + 0x18);
          }
          else {
            uVar7 = *(undefined4 *)(in_ECX + 0x10);
          }
          *(undefined4 *)(in_ECX + 0x10) = uVar7;
          fVar8 = *pfVar2;
          if (fVar8 < *(float *)(iVar3 + 0x1c) || fVar8 == *(float *)(iVar3 + 0x1c)) {
            fVar8 = *(float *)(iVar3 + 0x1c);
          }
          *pfVar2 = fVar8;
          fVar8 = *(float *)(in_ECX + 0x18);
          if (fVar8 < *(float *)(iVar3 + 0x20) || fVar8 == *(float *)(iVar3 + 0x20)) {
            fVar8 = *(float *)(iVar3 + 0x20);
          }
          *(float *)(in_ECX + 0x18) = fVar8;
          fVar8 = *(float *)(in_ECX + 0x1c);
          if (fVar8 < *(float *)(iVar3 + 0x24) || fVar8 == *(float *)(iVar3 + 0x24)) {
            fVar8 = *(float *)(iVar3 + 0x24);
          }
          *(float *)(in_ECX + 0x1c) = fVar8;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar4);
    }
    pfVar5 = (float *)FUN_0040f670(auStack_18,pfVar1,in_ECX + 0xf8);
    *pfVar1 = *pfVar5;
    *(float *)(in_ECX + 0xc) = pfVar5[1];
    *(float *)(in_ECX + 0x10) = pfVar5[2];
    *(float *)(in_ECX + 0x14) = pfVar5[3];
    *(float *)(in_ECX + 0x18) = pfVar5[4];
    *(float *)(in_ECX + 0x1c) = pfVar5[5];
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
    if (*(char *)(iVar3 + 3) == '\x01') {
      *(undefined4 *)(in_ECX + 0xe8) = 0x9090ff90;
    }
    else {
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
      if (*(char *)(iVar3 + 3) == '\x02') {
        *(undefined4 *)(in_ECX + 0xe8) = 0x90ff9090;
      }
      else {
        iVar3 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
        *(uint *)(in_ECX + 0xe8) = (-(uint)(*(char *)(iVar3 + 3) != '\x03') & 0x504fe1) + 0x909090ff
        ;
      }
    }
    fVar8 = DAT_0099d0b4;
    *(float *)(in_ECX + 0xac) = (*pfVar2 - *pfVar1) * DAT_0099d0b4 + *pfVar1;
    *(float *)(in_ECX + 0xb0) =
         (*(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc)) * fVar8 + *(float *)(in_ECX + 0xc);
    *(float *)(in_ECX + 0xb4) =
         (*(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10)) * fVar8 + *(float *)(in_ECX + 0x10)
    ;
    local_30 = *pfVar2 - *pfVar1;
    local_2c = *(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc);
    local_28 = *(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10);
    thunk_FUN_0079e1ba(afStack_24,&local_30);
    uVar7 = DAT_0099d080;
    *(float *)(in_ECX + 0xdc) = local_2c * unaff_ESI;
    *(float *)(in_ECX + 0xe0) = local_28 * unaff_ESI;
    *(float *)(in_ECX + 0xe4) = afStack_24[0] * unaff_ESI;
    *(undefined4 *)(in_ECX + 0xb8) = uVar7;
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    *(undefined4 *)(in_ECX + 0xc0) = 0;
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    *(undefined4 *)(in_ECX + 200) = uVar7;
    *(undefined4 *)(in_ECX + 0xcc) = 0;
    *(undefined4 *)(in_ECX + 0xd0) = 0;
    *(undefined4 *)(in_ECX + 0xd4) = 0;
    *(undefined4 *)(in_ECX + 0xd8) = uVar7;
  }
  return;
}


// ==== FUN_00840ea0 @ 0x00840ea0 ====

void FUN_00840ea0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  uint uStack_4;
  
  if (DAT_00b5afb4 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x30) = 0;
    return;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x178) + 4))();
  uStack_4 = (uint)*(byte *)(iVar1 + 0x1d);
  fVar2 = (float10)(**(code **)(*DAT_00b5afb4 + 0xc))(&uStack_4);
  *(float *)(in_ECX + 0x30) = (float)fVar2;
  return;
}


// ==== FUN_00840ef0 @ 0x00840ef0 ====

bool FUN_00840ef0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int iStack_18;
  undefined4 uStack_4;
  
  iStack_18 = in_ECX + 0x50;
  cVar1 = (**(code **)(*DAT_00b5a988 + 0x24))(*(undefined4 *)(in_ECX + 0x2c));
  if (cVar1 == '\x01') {
    return false;
  }
  iStack_18 = *(int *)(in_ECX + 0xa8);
  iVar2 = FUN_0040d570(&iStack_18,uStack_4);
  return iVar2 != 1;
}


// ==== FUN_00840f80 @ 0x00840f80 ====

void FUN_00840f80(void)

{
  char cVar1;
  int in_ECX;
  undefined1 *puStack_c;
  undefined1 local_4 [4];
  
  puStack_c = local_4;
  cVar1 = (**(code **)(*DAT_00b5af50 + 0xc))(in_ECX + 0x30);
  if (cVar1 == '\0') {
    puStack_c = (undefined1 *)0x0;
  }
  *(float *)(in_ECX + 8) = *(float *)(in_ECX + 0x48) + (float)puStack_c;
  FUN_00840a90();
  FUN_00840b30();
  return;
}


// ==== FUN_00840fd0 @ 0x00840fd0 ====

undefined4 FUN_00840fd0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  undefined4 *unaff_retaddr;
  undefined1 auStack_50 [4];
  undefined4 uStack_4c;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  float fStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (((char)in_ECX[0x32] == '\0') && (in_ECX[0x55] != 0)) {
    iVar2 = (**(code **)(*(int *)in_ECX[0x55] + 4))();
    if (*(char *)(iVar2 + 0x1c) != '\0') {
      iStack_3c = in_ECX[-7];
      iStack_38 = in_ECX[-6];
      iStack_34 = in_ECX[-5];
      iStack_30 = in_ECX[-4];
      fStack_2c = (float)in_ECX[-3];
      iStack_28 = in_ECX[-2];
      uStack_20 = 0;
      uStack_18 = *param_1;
      fStack_14 = fStack_2c + DAT_0099d080;
      uStack_10 = param_1[1];
      uStack_1c = 0;
      uStack_4 = 0;
      uStack_c = 0;
      uStack_8 = DAT_0099d0dc;
      uStack_24 = 2;
      cVar1 = (**(code **)(*in_ECX + 0x18))(&uStack_24,auStack_50);
      if (cVar1 != '\0') {
        *unaff_retaddr = uStack_4c;
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00841100 @ 0x00841100 ====

void FUN_00841100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fe7c;
  in_ECX[1] = &PTR_FUN_00a0fe64;
  in_ECX[9] = &PTR_FUN_00a0fe3c;
  (*(code *)PTR_FUN_00a0fe88)();
  if ((uint)in_ECX[0x14] < 0x10) {
    in_ECX[0x14] = 0xf;
    in_ECX[0x13] = 0;
    *(undefined1 *)(in_ECX + 0xf) = 0;
    in_ECX[9] = &PTR_FUN_00a0f398;
    in_ECX[1] = &PTR_FUN_009bf514;
    *in_ECX = &PTR_FUN_00a0fe24;
    return;
  }
  _free((void *)in_ECX[0xf]);
  return;
}


// ==== FUN_00841160 @ 0x00841160 ====

void FUN_00841160(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_009bf514;
  in_ECX[9] = &PTR_FUN_00a0f398;
  *in_ECX = &PTR_FUN_00a0fe7c;
  in_ECX[1] = &PTR_FUN_00a0fe64;
  in_ECX[9] = &PTR_FUN_00a0fe3c;
  in_ECX[0x14] = 0xf;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  FUN_00840500();
  return;
}


// ==== FUN_008411a0 @ 0x008411a0 ====

undefined4 FUN_008411a0(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  
  FUN_00841500(param_1);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  *(undefined4 *)(in_ECX + 0xf4) = uVar1;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac10 + 4))(in_ECX + 0x38);
  *(int **)(in_ECX + 0x178) = piVar2;
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 8))();
    if (iVar3 != 0) {
      *(bool *)(in_ECX + 0xec) = *(char *)(iVar3 + 3) == '\x03';
      FUN_00840ea0();
      (**(code **)(*(int *)(in_ECX + 0x24) + 0x10))();
      uVar1 = (**(code **)(**(int **)(in_ECX + 0x178) + 0x14))();
      *(undefined4 *)(in_ECX + 0xa8) = uVar1;
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
      fVar4 = (float10)FUN_0040d0a0(0,*(undefined4 *)(iVar3 + 0xc));
      *(float *)(in_ECX + 0xa4) = (float)fVar4;
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x178) + 8))();
      *(undefined1 *)(in_ECX + 0xee) = *(undefined1 *)(iVar3 + 5);
      (**(code **)(*DAT_00b5afac + 4))(*(undefined4 *)(in_ECX + 0x34),in_ECX + 4,2);
      (**(code **)(*DAT_00b5a720 + 4))(in_ECX + 0x24);
      *(undefined1 *)(in_ECX + 0x28) = 1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00841280 @ 0x00841280 ====

void FUN_00841280(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  if (*(int *)(param_1 + 0x40) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (*(int *)(param_1 + 0x44) - *(int *)(param_1 + 0x40)) / 0x58;
  }
  FUN_005c4ae0(iVar3 + 1,0);
  iVar3 = *(int *)(param_1 + 0x44);
  *(undefined4 *)(iVar3 + -0x14) = 3;
  *(undefined4 *)(iVar3 + -0x1c) = 0;
  *(undefined4 *)(iVar3 + -0x20) = 0;
  *(undefined4 *)(iVar3 + -0x24) = 0;
  *(undefined4 *)(iVar3 + -0x28) = 0;
  *(undefined4 *)(iVar3 + -0x30) = 0;
  *(undefined4 *)(iVar3 + -0x34) = 0;
  *(undefined4 *)(iVar3 + -0x38) = 0;
  *(undefined4 *)(iVar3 + -0x3c) = 0;
  *(undefined4 *)(iVar3 + -0x44) = 0;
  *(undefined4 *)(iVar3 + -0x48) = 0;
  *(undefined4 *)(iVar3 + -0x4c) = 0;
  *(undefined4 *)(iVar3 + -0x50) = 0;
  uVar1 = DAT_0099d080;
  *(undefined4 *)(iVar3 + -0x18) = DAT_0099d080;
  *(undefined4 *)(iVar3 + -0x2c) = uVar1;
  *(undefined4 *)(iVar3 + -0x40) = uVar1;
  *(undefined4 *)(iVar3 + -0x54) = uVar1;
  if (*(int *)(in_ECX + 0xa8) == 0) {
    *(undefined4 *)(iVar3 + -0x58) = 0;
  }
  else {
    uVar1 = FUN_005ca7a0();
    *(undefined4 *)(iVar3 + -0x58) = uVar1;
  }
  puVar2 = (undefined1 *)(**(code **)(**(int **)(in_ECX + 0x178) + 8))();
  uStack_4b = 0;
  uStack_7 = 0;
  uStack_60 = (**(code **)(**(int **)(in_ECX + 0x178) + 0xc))();
  uStack_5c = (**(code **)(**(int **)(in_ECX + 0x178) + 0x10))();
  uStack_58 = *puVar2;
  uStack_4c = puVar2[1];
  uStack_54 = 0xffffffff;
  uStack_50 = DAT_0099d080;
  uStack_8 = 0;
  FUN_005c1360(&uStack_60);
  FUN_00840910(param_1);
  return;
}


// ==== FUN_008413d0 @ 0x008413d0 ====

void FUN_008413d0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x1c) != '\x01') {
    puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x70))();
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x174) + 8))();
    *(bool *)(puVar1 + 9) = *(int *)(in_ECX + 0xa4) == 0;
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x174) + 4))();
    *(undefined1 *)((int)puVar1 + 0x21) = *(undefined1 *)(iVar3 + 0x1d);
    puVar1[0xc] = (float)*(byte *)(iVar2 + 4);
    puVar1[0xd] = *(undefined4 *)(iVar2 + 0x14);
    puVar1[0xe] = *(undefined4 *)(iVar2 + 0x18);
    puVar1[0xb] = *(undefined4 *)(iVar2 + 0x1c);
    if (*(char *)(in_ECX + 0xe8) == '\0') {
      *(undefined1 *)(puVar1 + 8) = *(undefined1 *)(iVar2 + 3);
    }
    else {
      *(undefined1 *)(puVar1 + 8) = 0;
    }
    *(undefined1 *)((int)puVar1 + 0x26) = *(undefined1 *)(iVar2 + 2);
    puVar1[10] = *(undefined4 *)(iVar2 + 0x10);
    *puVar1 = *(undefined4 *)(in_ECX + 0x50);
    puVar1[1] = *(undefined4 *)(in_ECX + 0x28);
    puVar1[2] = *(undefined4 *)(in_ECX + 0x54);
    puVar1[3] = *(undefined4 *)(in_ECX + 0x58);
    puVar1[4] = *(undefined4 *)(in_ECX + 0x5c);
    puVar1[5] = *(undefined4 *)(in_ECX + 0x60);
    puVar1[6] = *(undefined4 *)(in_ECX + 100);
    puVar1[7] = *(undefined4 *)(in_ECX + 0x6c);
    FUN_00841280(puVar1);
    (**(code **)(*param_1 + 0x98))(puVar1);
    (**(code **)(*param_1 + 0x94))(in_ECX + 0xa8);
  }
  return;
}


// ==== FUN_008414c0 @ 0x008414c0 ====

void FUN_008414c0(void)

{
  FUN_008414e0();
  return;
}


// ==== FUN_008414d0 @ 0x008414d0 ====

void FUN_008414d0(void)

{
  FUN_008414e0();
  return;
}


// ==== FUN_008414e0 @ 0x008414e0 ====

void FUN_008414e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00841100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00841500 @ 0x00841500 ====

void FUN_00841500(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  FUN_00401660(param_1 + 1,0,0xffffffff);
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = param_1[0xe];
  in_ECX[0xf] = param_1[0xf];
  return;
}


// ==== FUN_00841560 @ 0x00841560 ====

void FUN_00841560(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00841580 @ 0x00841580 ====

void FUN_00841580(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return;
}


// ==== FUN_00841590 @ 0x00841590 ====

undefined4 FUN_00841590(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + -1;
  }
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_008415b0 @ 0x008415b0 ====

int FUN_008415b0(void)

{
  int in_ECX;
  
  return in_ECX + 0x14;
}


// ==== FUN_008415c0 @ 0x008415c0 ====

undefined4 FUN_008415c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_008415d0 @ 0x008415d0 ====

undefined4 FUN_008415d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x34);
}


// ==== FUN_008415e0 @ 0x008415e0 ====

undefined4 FUN_008415e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_008415f0 @ 0x008415f0 ====

undefined4 FUN_008415f0(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x34);
  if (((iVar1 == 0) || (*(int *)(iVar1 + 0x88) == 0)) || (*(int *)(iVar1 + 0x6c) == 0)) {
    return 0;
  }
  pvVar2 = operator_new(0x40);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005caa30();
  }
  FUN_005ca810(*(int *)(in_ECX + 0x34) + 0x58,0);
  FUN_005cab40(*(int *)(in_ECX + 0x34) + 0x74);
  return uVar3;
}


// ==== FUN_00841650 @ 0x00841650 ====

undefined1 FUN_00841650(void)

{
  undefined1 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    return 0;
  }
  uVar1 = FUN_0089e410();
  return uVar1;
}


// ==== FUN_00841670 @ 0x00841670 ====

void FUN_00841670(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fef4;
  if (in_ECX[2] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[2]);
    in_ECX[2] = 0;
  }
  if (in_ECX[3] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[3]);
    in_ECX[3] = 0;
  }
  _Memory = (void *)in_ECX[4];
  if (_Memory != (void *)0x0) {
    FUN_0089df20();
    _free(_Memory);
    return;
  }
  in_ECX[4] = 0;
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[10] = 0;
    in_ECX[0xb] = 0xf;
    *(undefined1 *)(in_ECX + 6) = 0;
    *in_ECX = &PTR_FUN_00a0fed4;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_008416f0 @ 0x008416f0 ====

void FUN_008416f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0fef4;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[0xd] = 0;
  return;
}


// ==== FUN_00841720 @ 0x00841720 ====

undefined4 FUN_00841720(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int in_ECX;
  
  iVar2 = (**(code **)(*DAT_00b5a6d8 + 0xc))(param_1);
  *(int *)(in_ECX + 0x34) = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = FUN_004236c0(iVar2 + 0x20);
  *(undefined4 *)(in_ECX + 8) = uVar3;
  uVar3 = FUN_00839580(*(int *)(in_ECX + 0x34) + 0x3c);
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  *(undefined4 *)(in_ECX + 4) = 0;
  pvVar4 = operator_new(0x44);
  if (pvVar4 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0089dfc0();
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  FUN_0089dec0(*(undefined4 *)(in_ECX + 8));
  FUN_00401660(param_1,0,0xffffffff);
  uVar1 = FUN_0089deb0();
  *(undefined1 *)(in_ECX + 0x30) = uVar1;
  *(undefined1 *)(in_ECX + 0x31) = *(undefined1 *)(*(int *)(in_ECX + 0x34) + 6);
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 0x34) >> 8),1);
}


// ==== FUN_008417c0 @ 0x008417c0 ====

void FUN_008417c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00841670();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008417e0 @ 0x008417e0 ====

void FUN_008417e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a0ffec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00841800 @ 0x00841800 ====

void FUN_00841800(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00841802. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_00841810 @ 0x00841810 ====

int FUN_00841810(void)

{
  int in_ECX;
  
  return in_ECX + 0x38;
}


// ==== FUN_00841820 @ 0x00841820 ====

int FUN_00841820(void)

{
  int in_ECX;
  
  return in_ECX + 0x80;
}


// ==== FUN_00841830 @ 0x00841830 ====

void FUN_00841830(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_8 = *(float *)(in_ECX + 0x7c) - *(float *)(in_ECX + 0x28);
  local_4 = *(float *)(in_ECX + 0x84) - *(float *)(in_ECX + 0x28);
  local_10 = *(float *)(in_ECX + 0x28) + *(float *)(in_ECX + 0x7c);
  local_c = *(float *)(in_ECX + 0x28) + *(float *)(in_ECX + 0x84);
  FUN_004a8890(&local_8,&local_10,param_2);
  return;
}


// ==== FUN_008418a0 @ 0x008418a0 ====

void FUN_008418a0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  *(undefined4 *)(in_ECX + 0x160) = 0;
  *(undefined4 *)(in_ECX + 0x164) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  return;
}


// ==== FUN_008418d0 @ 0x008418d0 ====

void FUN_008418d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_58;
  undefined4 local_54 [2];
  undefined1 local_4c [12];
  undefined1 local_40 [28];
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x3c);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(in_ECX + 0x34);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(in_ECX + 0x40);
  local_58 = 0;
  local_54[0] = 0;
  local_54[1] = DAT_0099d0dc;
  uVar1 = FUN_0081d830(local_40);
  thunk_FUN_0079e5a0(local_4c,&local_58,uVar1);
  *(undefined4 *)(in_ECX + 0x8c) = local_58;
  *(undefined4 *)(in_ECX + 0x90) = local_54[1];
  uVar1 = FUN_0081d6a0();
  thunk_FUN_0079fb96(local_4c,uVar1);
  uStack_24 = *(undefined4 *)(in_ECX + 0x80);
  uStack_20 = *(undefined4 *)(in_ECX + 0x84);
  uStack_1c = *(undefined4 *)(in_ECX + 0x88);
  puVar3 = local_54;
  puVar4 = (undefined4 *)(in_ECX + 0x94);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}


// ==== FUN_00841a10 @ 0x00841a10 ====

void FUN_00841a10(void)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float *pfVar4;
  int in_ECX;
  float unaff_ESI;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float fStack_14;
  float fStack_10;
  float local_c [3];
  
  fVar3 = DAT_009b0318;
  local_30 = DAT_0099d0b4;
  pfVar1 = (float *)(in_ECX + 8);
  *pfVar1 = DAT_009b0318;
  *(float *)(in_ECX + 0xc) = fVar3;
  *(float *)(in_ECX + 0x10) = fVar3;
  pfVar2 = (float *)(in_ECX + 0x14);
  local_2c = local_30;
  *pfVar2 = local_30;
  *(float *)(in_ECX + 0x18) = local_30;
  local_28 = local_30;
  *(float *)(in_ECX + 0x1c) = local_30;
  pfVar4 = (float *)FUN_0040f670(&local_24,pfVar1,in_ECX + 0x94);
  *pfVar1 = *pfVar4;
  *(float *)(in_ECX + 0xc) = pfVar4[1];
  *(float *)(in_ECX + 0x10) = pfVar4[2];
  *(float *)(in_ECX + 0x14) = pfVar4[3];
  *(float *)(in_ECX + 0x18) = pfVar4[4];
  *(float *)(in_ECX + 0x1c) = pfVar4[5];
  local_30 = *pfVar2 - *pfVar1;
  local_24 = (*pfVar2 - *pfVar1) * DAT_0099d0b4 + *pfVar1;
  local_2c = *(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc);
  local_20 = (*(float *)(in_ECX + 0x18) - *(float *)(in_ECX + 0xc)) * DAT_0099d0b4 +
             *(float *)(in_ECX + 0xc);
  local_28 = *(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10);
  local_1c = (*(float *)(in_ECX + 0x1c) - *(float *)(in_ECX + 0x10)) * DAT_0099d0b4 +
             *(float *)(in_ECX + 0x10);
  thunk_FUN_0079e1ba(local_c,&local_30);
  *(float *)(in_ECX + 0x150) = fStack_14 * unaff_ESI;
  *(float *)(in_ECX + 0x154) = fStack_10 * unaff_ESI;
  *(float *)(in_ECX + 0x120) = local_2c;
  *(float *)(in_ECX + 0x158) = local_c[0] * unaff_ESI;
  *(float *)(in_ECX + 0x124) = local_28;
  *(float *)(in_ECX + 0x128) = local_24;
  return;
}


// ==== FUN_00841bd0 @ 0x00841bd0 ====

void FUN_00841bd0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x28) != '\0') {
    if (DAT_00b5afc8 != (int *)0x0) {
      (**(code **)(*DAT_00b5afc8 + 0x34))(*(undefined4 *)(in_ECX + 0x38));
    }
    (**(code **)(*DAT_00b5afac + 8))(*(undefined4 *)(in_ECX + 0x38),5);
    (**(code **)(*DAT_00b5b010 + 0x18))(*(undefined4 *)(in_ECX + 0x160));
    *(undefined4 *)(in_ECX + 0x160) = 0;
    (**(code **)(*DAT_00b5a728 + 8))(*(undefined4 *)(in_ECX + 0x38));
    if (*(int *)(in_ECX + 0xd4) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0xd4));
      *(undefined4 *)(in_ECX + 0xd4) = 0;
    }
    *(undefined1 *)(in_ECX + 0x28) = 0;
  }
  return;
}


// ==== FUN_00841c50 @ 0x00841c50 ====

uint FUN_00841c50(int param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  uint uVar7;
  int in_ECX;
  float10 extraout_ST0;
  
  piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  piVar6 = (int *)(**(code **)(*piVar6 + 0x1c))();
  if (*piVar6 != 1) {
    piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    piVar6 = (int *)(**(code **)(*piVar6 + 0x1c))();
    if ((*piVar6 != 2) || (*(char *)(in_ECX + 6) != '\0')) {
      piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      piVar6 = (int *)(**(code **)(*piVar6 + 0x1c))();
      if ((*piVar6 != 3) || (*(char *)(in_ECX + 6) != '\x01')) {
        uVar7 = FUN_0040e4a0((float *)(param_1 + 0xc),in_ECX + 0x5c,0x3f800000);
        fVar5 = (float)extraout_ST0;
        if (extraout_ST0 < (float10)DAT_0099cdc8) {
          *(undefined4 *)(in_ECX + 0x138) = 0x9060ffff;
          return uVar7 & 0xffffff00;
        }
        param_2[1] = *(undefined4 *)(in_ECX + 0x14);
        *param_2 = 1;
        fVar1 = *(float *)(param_1 + 0x1c);
        fVar2 = *(float *)(param_1 + 0x20);
        fVar3 = *(float *)(param_1 + 0x10);
        fVar4 = *(float *)(param_1 + 0x14);
        param_2[2] = *(float *)(param_1 + 0xc) + *(float *)(param_1 + 0x18) * fVar5;
        param_2[3] = fVar3 + fVar1 * fVar5;
        param_2[4] = fVar4 + fVar2 * fVar5;
        *(undefined4 *)(in_ECX + 0x138) = 0xe0a0ffff;
        return CONCAT31((int3)((uint)(param_2 + 2) >> 8),1);
      }
    }
  }
  return (uint)piVar6 & 0xffffff00;
}


// ==== FUN_00841d80 @ 0x00841d80 ====

void FUN_00841d80(void)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(char *)(in_ECX + 0x29) == '\0') {
    local_10 = 0;
    if (SQRT(*(float *)(in_ECX + 0x78) * *(float *)(in_ECX + 0x78) +
             *(float *)(in_ECX + 0x74) * *(float *)(in_ECX + 0x74) +
             *(float *)(in_ECX + 0x70) * *(float *)(in_ECX + 0x70)) <= DAT_0099cdc8) {
      (**(code **)(*DAT_00b5afc8 + 8))
                (in_ECX + 0x38,in_ECX + 0x60,in_ECX + 0x6c,&local_10,in_ECX + 100);
    }
    else {
      local_c = *(float *)(in_ECX + 0x80) + *(float *)(in_ECX + 0x70);
      local_8 = *(float *)(in_ECX + 0x74) + *(float *)(in_ECX + 0x84);
      local_4 = *(float *)(in_ECX + 0x78) + *(float *)(in_ECX + 0x88);
      (**(code **)(*DAT_00b5afc8 + 0x20))
                (in_ECX + 0x38,in_ECX + 0x60,&local_c,in_ECX + 0x38,&local_10,in_ECX + 100,
                 in_ECX + 0x68);
    }
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    piVar1 = (int *)(**(code **)(*piVar1 + 0x1c))();
    if ((*piVar1 == 2) && (*(char *)(in_ECX + 0x2a) == '\x01')) {
      *(undefined4 *)(in_ECX + 0xd8) = 0xffd0d0ff;
    }
    *(undefined1 *)(in_ECX + 0x29) = 1;
  }
  return;
}


// ==== FUN_00841e80 @ 0x00841e80 ====

void FUN_00841e80(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x29) != '\0') {
    (**(code **)(*DAT_00b5afc8 + 0x14))(in_ECX + 0x38);
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    piVar1 = (int *)(**(code **)(*piVar1 + 0x1c))();
    if ((*piVar1 == 2) && (*(char *)(in_ECX + 0x2a) == '\x01')) {
      *(undefined4 *)(in_ECX + 0xd8) = 0xff9090ff;
    }
    *(undefined1 *)(in_ECX + 0x29) = 0;
  }
  return;
}


// ==== FUN_00841ed0 @ 0x00841ed0 ====

undefined1 FUN_00841ed0(undefined4 param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined1 uVar5;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = *(undefined4 *)(in_ECX + 0x28);
  local_10 = *(undefined4 *)(in_ECX + 0x7c);
  local_c = *(undefined4 *)(in_ECX + 0x80);
  local_8 = *(undefined4 *)(in_ECX + 0x84);
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x1c))();
  if (*piVar3 != 2) {
    if (((((*(char *)(in_ECX + 0x26) != '\0') || (*(char *)(in_ECX + 0x27) != '\0')) ||
         (DAT_009b0120 < *(float *)(in_ECX + 0x28))) ||
        (cVar2 = (**(code **)(*DAT_00b5a988 + 0x24))(*(undefined4 *)(in_ECX + 0x2c),in_ECX + 0x38),
        cVar2 != '\x01')) && (iVar4 = FUN_0040d570(&local_10,param_1), iVar4 != 1)) {
      FUN_00841d80();
      return 1;
    }
    FUN_00841e80();
    return 0;
  }
  bVar1 = true;
  uVar5 = 1;
  if (((*(char *)(in_ECX + 0x26) == '\0') && (*(char *)(in_ECX + 0x27) == '\0')) &&
     ((*(float *)(in_ECX + 0x28) <= DAT_009b0120 &&
      (cVar2 = (**(code **)(*DAT_00b5a988 + 0x24))(*(undefined4 *)(in_ECX + 0x2c),in_ECX + 0x38),
      cVar2 == '\x01')))) {
    bVar1 = false;
  }
  iVar4 = FUN_0040d570(&local_10,param_1);
  if ((((iVar4 != 1) || (uVar5 = 0, *(char *)(in_ECX + 0x26) == '\x01')) ||
      (*(char *)(in_ECX + 0x27) == '\x01')) && (bVar1)) {
    FUN_00841d80();
    return uVar5;
  }
  FUN_00841e80();
  return uVar5;
}


// ==== FUN_00842050 @ 0x00842050 ====

void FUN_00842050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10044;
  in_ECX[1] = &PTR_FUN_00a1002c;
  in_ECX[9] = &PTR_FUN_00a1000c;
  (*(code *)PTR_FUN_00a10050)();
  if (0xf < (uint)in_ECX[0x47]) {
    _free((void *)in_ECX[0x42]);
    return;
  }
  in_ECX[0x47] = 0xf;
  in_ECX[0x46] = 0;
  *(undefined1 *)(in_ECX + 0x42) = 0;
  if ((uint)in_ECX[0x40] < 0x10) {
    in_ECX[0x40] = 0xf;
    in_ECX[0x3f] = 0;
    *(undefined1 *)(in_ECX + 0x3b) = 0;
    FUN_0081d670();
    in_ECX[9] = &PTR_FUN_009c2eb0;
    in_ECX[1] = &PTR_FUN_009bf514;
    *in_ECX = &PTR_FUN_00a0ffec;
    return;
  }
  _free((void *)in_ECX[0x3b]);
  return;
}


// ==== FUN_008420f0 @ 0x008420f0 ====

void FUN_008420f0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_009bf514;
  in_ECX[9] = &PTR_FUN_009c2eb0;
  *in_ECX = &PTR_FUN_00a10044;
  in_ECX[1] = &PTR_FUN_00a1002c;
  in_ECX[9] = &PTR_FUN_00a1000c;
  FUN_0081d760();
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0xf;
  *(undefined1 *)(in_ECX + 0x3b) = 0;
  in_ECX[0x46] = 0;
  in_ECX[0x47] = 0xf;
  *(undefined1 *)(in_ECX + 0x42) = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 8) = 1;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  return;
}


// ==== FUN_00842180 @ 0x00842180 ====

void FUN_00842180(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  if (*(char *)(in_ECX + 0x2a) == '\0') {
    if (*(char *)(in_ECX + 0x2b) == '\0') {
      FUN_00401740(s_EFFECT_00a0ffb4,6);
      *(undefined4 *)(in_ECX + 0xd8) = 0xffcfcfcf;
    }
    else {
      *(undefined4 *)(in_ECX + 0xd8) = 0xffffff50;
      FUN_00401740(s_LIGHT_00a0ffac,5);
    }
  }
  else {
    FUN_00401740(s_SOUND_00a0ffa4,5);
    *(undefined4 *)(in_ECX + 0xd8) = 0xff9090ff;
  }
  if (*(int *)(in_ECX + 0x164) == 0) {
    FUN_00401740(s__d__d_T__d___00a0ffbc,0xc);
    uVar1 = FUN_00404230(local_1c);
  }
  else {
    FUN_00401740(s__s_T__d_00a0ffcc,7);
    uVar1 = FUN_00404230(local_1c);
  }
  FUN_00401660(uVar1,0,0xffffffff);
  uVar1 = DAT_0099d080;
  if (local_4 < 0x10) {
    *(undefined4 *)(in_ECX + 300) = DAT_0099d080;
    *(undefined4 *)(in_ECX + 0x130) = 0;
    *(undefined4 *)(in_ECX + 0x134) = 0;
    *(undefined4 *)(in_ECX + 0x138) = 0;
    *(undefined4 *)(in_ECX + 0x13c) = uVar1;
    *(undefined4 *)(in_ECX + 0x140) = 0;
    *(undefined4 *)(in_ECX + 0x144) = 0;
    *(undefined4 *)(in_ECX + 0x148) = 0;
    *(undefined4 *)(in_ECX + 0x14c) = uVar1;
    *(undefined4 *)(in_ECX + 0x15c) = 0x9060ffff;
    FUN_00841a10();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00842330 @ 0x00842330 ====

void FUN_00842330(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0xd0) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_mapeffect_dds_00a0ffd4,0xd);
    uVar2 = FUN_004b4e70(local_1c);
    *(undefined4 *)(in_ECX + 0xd0) = uVar2;
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x1c))();
  if (*piVar3 != 1) {
    piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    piVar3 = (int *)(**(code **)(*piVar3 + 0x1c))();
    if ((*piVar3 != 2) || (*(char *)(in_ECX + 0x26) != '\0')) {
      piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
      piVar3 = (int *)(**(code **)(*piVar3 + 0x1c))();
      if ((*piVar3 != 3) || (*(char *)(in_ECX + 0x26) != '\x01')) {
        puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x70))();
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        *(undefined4 *)(in_ECX + 0xd8) = *(undefined4 *)(in_ECX + 0x7c);
        *(undefined4 *)(in_ECX + 0xdc) = *(undefined4 *)(in_ECX + 0x80);
        *(undefined4 *)(in_ECX + 0xe0) = *(undefined4 *)(in_ECX + 0x84);
        *(float *)(in_ECX + 0xdc) = *(float *)(in_ECX + 0xdc) + DAT_0099d080;
        puVar4[0x13] = in_ECX + 0xd4;
        (**(code **)(*param_1 + 0x98))(puVar4);
        puVar4 = (undefined4 *)(**(code **)(*param_1 + 0xc0))();
        fVar1 = DAT_0099d080;
        puVar4[8] = 3;
        puVar4[9] = 1;
        puVar4[3] = *(undefined4 *)(in_ECX + 0xd0);
        *puVar4 = *(undefined4 *)(in_ECX + 0x7c);
        puVar4[1] = *(undefined4 *)(in_ECX + 0x80);
        puVar4[2] = *(undefined4 *)(in_ECX + 0x84);
        puVar4[5] = fVar1;
        puVar4[4] = fVar1;
        puVar4[6] = 0xffffffff;
        puVar4[7] = 0;
        (**(code **)(*param_1 + 0x88))(puVar4);
        (**(code **)(*param_1 + 0x94))(in_ECX + 0x11c);
      }
    }
  }
  return;
}


// ==== FUN_008424f0 @ 0x008424f0 ====

undefined4 FUN_008424f0(undefined4 *param_1)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float10 fVar9;
  undefined8 uVar10;
  undefined4 uStack_1c;
  uint uStack_8;
  
  if (*(char *)(in_ECX + 0x28) != '\0') {
    return 0;
  }
  puVar1 = (undefined4 *)(in_ECX + 0x38);
  *(undefined1 *)(in_ECX + 0x2a) = 0;
  *(undefined1 *)(in_ECX + 0x2b) = 0;
  puVar7 = param_1;
  puVar8 = puVar1;
  for (iVar6 = 0x12; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  if (DAT_00b5afb4 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x30) = 0;
  }
  else {
    param_1 = (undefined4 *)0xff;
    fVar9 = (float10)(**(code **)(*DAT_00b5afb4 + 0xc))(&param_1);
    *(float *)(in_ECX + 0x30) = (float)fVar9;
  }
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0x44);
  FUN_008418d0();
  iVar6 = (**(code **)(*DAT_00b5acf4 + 4))(*(undefined4 *)(in_ECX + 0x5c));
  *(int *)(in_ECX + 0x164) = iVar6;
  if (iVar6 == 0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar6 = (**(code **)(*piVar4 + 0x1c))();
    if (*(int *)(iVar6 + 4) == 1) {
      FUN_00401830(&DAT_00a0ff50);
      uVar5 = FUN_00404230((int)register0x00000010 + -0x20);
      FUN_00403e50(uVar5);
      if (uStack_8 < 0x10) {
        return 0;
      }
      _free(uStack_1c);
      return extraout_EAX;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(iVar6 + 0x1c);
  }
  if (*(float *)(in_ECX + 0x2c) == DAT_0099cdc8) {
    *(undefined4 *)(in_ECX + 0x2c) = DAT_009b0120;
  }
  uVar3 = DAT_009c2848;
  uVar5 = DAT_009bac80;
  sVar2 = *(short *)(in_ECX + 0x5e);
  if ((sVar2 == 3) || (sVar2 == 4)) {
    *(undefined1 *)(in_ECX + 0x2a) = 1;
  }
  else {
    if (sVar2 != 9) goto LAB_0084264e;
    *(undefined1 *)(in_ECX + 0x2b) = 1;
    uVar5 = uVar3;
  }
  *(undefined4 *)(in_ECX + 0x2c) = uVar5;
LAB_0084264e:
  uVar10 = CONCAT44(5,in_ECX + 4);
  uVar5 = *puVar1;
  (**(code **)(*DAT_00b5afac + 4))();
  (**(code **)(*DAT_00b5a728 + 4))(in_ECX + 0x24,uVar5,uVar10);
  uVar5 = (**(code **)(*DAT_00b5b010 + 4))();
  *(undefined4 *)(in_ECX + 0x160) = uVar5;
  *(undefined1 *)(in_ECX + 0x28) = 1;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  (**(code **)(*DAT_00b5afc4 + 8))(puVar1,puVar1,in_ECX + 0x5c,1);
  FUN_00842180();
  return 1;
}


// ==== FUN_008426b0 @ 0x008426b0 ====

void FUN_008426b0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x18);
  param_1[1] = *(undefined4 *)(in_ECX + 0x1c);
  return;
}


// ==== FUN_008426d0 @ 0x008426d0 ====

float10 FUN_008426d0(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x20);
}


// ==== FUN_008426e0 @ 0x008426e0 ====

void FUN_008426e0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x5c);
  param_1[1] = *(undefined4 *)(in_ECX + 0x60);
  param_1[2] = *(undefined4 *)(in_ECX + 100);
  return;
}


// ==== FUN_00842700 @ 0x00842700 ====

undefined4 FUN_00842700(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_00842710 @ 0x00842710 ====

undefined1 FUN_00842710(void)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x2a) == '\0') && (DAT_009b0120 < *(float *)(in_ECX + 0x2c))) {
    return 1;
  }
  return 0;
}


// ==== FUN_00842730 @ 0x00842730 ====

void FUN_00842730(void)

{
  FUN_00842750();
  return;
}


// ==== FUN_00842740 @ 0x00842740 ====

void FUN_00842740(void)

{
  FUN_00842750();
  return;
}


// ==== FUN_00842750 @ 0x00842750 ====

void FUN_00842750(byte param_1)

{
  void *in_ECX;
  
  FUN_00842050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00842770 @ 0x00842770 ====

void FUN_00842770(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a100a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00842790 @ 0x00842790 ====

void FUN_00842790(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_008427a0 @ 0x008427a0 ====

void FUN_008427a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a100bc;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_008427c0 @ 0x008427c0 ====

undefined4 FUN_008427c0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x008427cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return uVar1;
}


// ==== FUN_008427e0 @ 0x008427e0 ====

void FUN_008427e0(int param_1)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  float10 fVar3;
  undefined1 auStack_8 [8];
  
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x34))();
    *(undefined1 *)(param_1 + 0xc) = uVar1;
    puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x2c))(auStack_8);
    *(undefined4 *)(param_1 + 0x10) = *puVar2;
    *(undefined4 *)(param_1 + 0x14) = puVar2[1];
    fVar3 = (float10)(**(code **)(**(int **)(in_ECX + 4) + 0x24))();
    *(float *)(param_1 + 0x18) = (float)fVar3;
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))(param_1 + 0x1c);
  }
  return;
}


// ==== FUN_00842840 @ 0x00842840 ====

void FUN_00842840(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x1c))(param_2,param_1);
  }
  return;
}


// ==== FUN_00842860 @ 0x00842860 ====

uint FUN_00842860(void)

{
  uint in_EAX;
  uint uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return in_EAX & 0xffffff00;
  }
                    /* WARNING: Could not recover jumptable at 0x00842870. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  return uVar1;
}


// ==== FUN_00842890 @ 0x00842890 ====

void FUN_00842890(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_008428a0 @ 0x008428a0 ====

void FUN_008428a0(void)

{
  return;
}


// ==== FUN_008428b0 @ 0x008428b0 ====

undefined1 FUN_008428b0(void)

{
  return 0;
}


// ==== FUN_008428c0 @ 0x008428c0 ====

void FUN_008428c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10114;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_008428e0 @ 0x008428e0 ====

undefined4 FUN_008428e0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0xffffffff;
  }
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return *puVar1;
}


// ==== FUN_00842900 @ 0x00842900 ====

void FUN_00842900(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined1 auStack_8 [8];
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    *(undefined1 *)(param_1 + 0xc) = 1;
    puVar2 = (undefined4 *)FUN_0040d600(auStack_8,*(undefined4 *)(iVar1 + 8));
    *(undefined4 *)(param_1 + 0x10) = *puVar2;
    *(undefined4 *)(param_1 + 0x14) = puVar2[1];
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar1 + 0x10);
    puVar2 = (undefined4 *)(iVar1 + 0x14);
    puVar4 = (undefined4 *)(param_1 + 0x1c);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_00842970 @ 0x00842970 ====

void FUN_00842970(byte param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_00a100a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008429a0 @ 0x008429a0 ====

void FUN_008429a0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_008429b0 @ 0x008429b0 ====

void FUN_008429b0(void)

{
  return;
}


// ==== FUN_008429c0 @ 0x008429c0 ====

undefined1 FUN_008429c0(void)

{
  return 0;
}


// ==== FUN_008429d0 @ 0x008429d0 ====

void FUN_008429d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1016c;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_008429f0 @ 0x008429f0 ====

undefined4 FUN_008429f0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0xffffffff;
  }
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return *puVar1;
}


// ==== FUN_00842a10 @ 0x00842a10 ====

void FUN_00842a10(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar2 = DAT_0099d0dc;
  uVar1 = DAT_0099d0b4;
  if (*(int *)(in_ECX + 4) != 0) {
    *(undefined1 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    puVar5 = (undefined4 *)(iVar3 + 0x1c);
    puVar6 = (undefined4 *)(param_1 + 0x1c);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  return;
}


// ==== FUN_00842a90 @ 0x00842a90 ====

void FUN_00842a90(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00842aa0 @ 0x00842aa0 ====

void FUN_00842aa0(void)

{
  return;
}


// ==== FUN_00842ab0 @ 0x00842ab0 ====

undefined1 FUN_00842ab0(void)

{
  return 0;
}


// ==== FUN_00842ac0 @ 0x00842ac0 ====

void FUN_00842ac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a101c4;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00842ae0 @ 0x00842ae0 ====

undefined4 FUN_00842ae0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0xffffffff;
  }
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return *puVar1;
}


// ==== FUN_00842b00 @ 0x00842b00 ====

void FUN_00842b00(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar2 = DAT_0099d0dc;
  uVar1 = DAT_0099d0b4;
  if (*(int *)(in_ECX + 4) != 0) {
    *(undefined1 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    *(undefined4 *)(param_1 + 0x18) = uVar1;
    iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    puVar5 = (undefined4 *)(iVar3 + 0x1c);
    puVar6 = (undefined4 *)(param_1 + 0x1c);
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  return;
}


// ==== FUN_00842b80 @ 0x00842b80 ====

void FUN_00842b80(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00842b90 @ 0x00842b90 ====

void FUN_00842b90(void)

{
  return;
}


// ==== FUN_00842ba0 @ 0x00842ba0 ====

undefined1 FUN_00842ba0(void)

{
  return 0;
}


// ==== FUN_00842bb0 @ 0x00842bb0 ====

void FUN_00842bb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1021c;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00842bd0 @ 0x00842bd0 ====

undefined4 FUN_00842bd0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0xffffffff;
  }
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
  return *puVar1;
}


// ==== FUN_00842bf0 @ 0x00842bf0 ====

void FUN_00842bf0(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x18))();
    *(undefined1 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(param_1 + 0x18) = 0;
    puVar3 = (undefined4 *)(iVar1 + 0x14);
    puVar4 = (undefined4 *)(param_1 + 0x1c);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_00842c40 @ 0x00842c40 ====

void FUN_00842c40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10274;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00842c60 @ 0x00842c60 ====

void FUN_00842c60(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  return;
}


// ==== FUN_00842c70 @ 0x00842c70 ====

void FUN_00842c70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -1;
  }
  return;
}


// ==== FUN_00842c80 @ 0x00842c80 ====

void FUN_00842c80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10284;
  if ((undefined4 *)in_ECX[0x18] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x18])(1);
  }
  in_ECX[0x18] = 0;
  *in_ECX = &PTR_FUN_00a10274;
  return;
}


// ==== FUN_00842cb0 @ 0x00842cb0 ====

undefined4 FUN_00842cb0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x60);
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  return uVar1;
}


// ==== FUN_00842cc0 @ 0x00842cc0 ====

void FUN_00842cc0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x60) + 8))(in_ECX + 4);
  }
  return;
}


// ==== FUN_00842ce0 @ 0x00842ce0 ====

void FUN_00842ce0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00842ceb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x60) + 0xc))();
  return;
}


// ==== FUN_00842d00 @ 0x00842d00 ====

uint FUN_00842d00(void)

{
  uint in_EAX;
  uint uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) == 0) {
    return in_EAX & 0xffffff00;
  }
                    /* WARNING: Could not recover jumptable at 0x00842d10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 0x60) + 0x10))();
  return uVar1;
}


// ==== FUN_00842d20 @ 0x00842d20 ====

void FUN_00842d20(int *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(int **)(in_ECX + 0x60) = param_1;
  uVar1 = (**(code **)(*param_1 + 4))();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  *(undefined1 *)(in_ECX + 8) = 1;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x5c) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x48) = uVar1;
  *(undefined4 *)(in_ECX + 0x34) = uVar1;
  *(undefined4 *)(in_ECX + 0x20) = uVar1;
  if (*(int **)(in_ECX + 0x60) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x60) + 8))((undefined4 *)(in_ECX + 4));
  }
  return;
}


// ==== FUN_00842db0 @ 0x00842db0 ====

void FUN_00842db0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_0099d0dc;
  *in_ECX = &PTR_FUN_00a10284;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 1;
  in_ECX[5] = 0;
  uVar1 = DAT_0099d0b4;
  in_ECX[6] = uVar2;
  in_ECX[7] = uVar1;
  in_ECX[0x16] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xb] = 0;
  in_ECX[10] = 0;
  in_ECX[9] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[0x17] = DAT_0099d080;
  in_ECX[0x12] = uVar1;
  in_ECX[0xd] = uVar1;
  in_ECX[8] = uVar1;
  return;
}


// ==== FUN_00842e60 @ 0x00842e60 ====

void FUN_00842e60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10284;
  if ((undefined4 *)in_ECX[0x18] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x18])(1);
  }
  in_ECX[0x18] = 0;
  *in_ECX = &PTR_FUN_00a10274;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00842ea0 @ 0x00842ea0 ====

void FUN_00842ea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a102d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00842ec0 @ 0x00842ec0 ====

int FUN_00842ec0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00842ed0 @ 0x00842ed0 ====

int FUN_00842ed0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2c) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x2c) >> 5;
}


// ==== FUN_00842ef0 @ 0x00842ef0 ====

undefined4 FUN_00842ef0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
    return 0;
  }
  uVar1 = FUN_008473e0();
  return uVar1;
}


// ==== FUN_00842f00 @ 0x00842f00 ====

undefined4 FUN_00842f00(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x44)) {
    *(undefined4 *)(in_ECX + 0x38) = 0;
    return 0;
  }
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(local_4 + 0xc);
  uVar1 = FUN_008473b0();
  return uVar1;
}


// ==== FUN_00842f40 @ 0x00842f40 ====

int FUN_00842f40(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x2c) == 0) ||
     ((uint)(*(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x2c) >> 5) <= param_1)) {
    return 0;
  }
  iVar1 = *(int *)(in_ECX + 0x2c);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x30) - iVar1 >> 5) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return param_1 * 0x20 + iVar1;
}


// ==== FUN_00842f90 @ 0x00842f90 ====

void FUN_00842f90(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a102f0;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 0xf) = local_5;
  uVar1 = FUN_00843340();
  in_ECX[0x11] = uVar1;
  in_ECX[0x12] = 0;
  local_4 = in_ECX[0x11];
  FUN_00843770(9,&local_4);
  in_ECX[0x17] = 1;
  in_ECX[0x18] = 1;
  return;
}


// ==== FUN_00843000 @ 0x00843000 ====

void FUN_00843000(void)

{
  int *piVar1;
  undefined4 *puVar2;
  void *_Memory;
  undefined4 *in_ECX;
  int *piVar3;
  
  piVar1 = (int *)in_ECX[0x11];
  *in_ECX = &PTR_FUN_00a102f0;
  piVar3 = (int *)*piVar1;
  if (piVar3 != piVar1) {
    do {
      if ((undefined4 *)piVar3[3] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar3[3])(1);
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != piVar1);
  }
  FUN_00843c90();
  in_ECX[0xe] = 0;
  if ((void *)in_ECX[0x14] != (void *)0x0) {
    _free((void *)in_ECX[0x14]);
    return;
  }
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  puVar2 = (undefined4 *)in_ECX[0x11];
  _Memory = (void *)*puVar2;
  *puVar2 = puVar2;
  *(undefined4 *)(in_ECX[0x11] + 4) = in_ECX[0x11];
  in_ECX[0x12] = 0;
  if (_Memory == (void *)in_ECX[0x11]) {
    _free((void *)in_ECX[0x11]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_008430f0 @ 0x008430f0 ====

void FUN_008430f0(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  void *pvVar7;
  undefined4 uVar8;
  int in_ECX;
  int *piVar9;
  undefined4 *puVar10;
  int local_30;
  undefined4 local_2c;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined4 local_4;
  
  *(short *)(in_ECX + 8) = (short)((uint)param_1 >> 0x10);
  *(undefined4 *)(in_ECX + 4) = param_1;
  *(short *)(in_ECX + 10) = (short)param_1;
  FUN_00401660(param_2,0,0xffffffff);
  puVar2 = *(undefined4 **)(param_2 + 0x28);
  puVar10 = *(undefined4 **)(param_2 + 0x24);
  if (puVar10 != puVar2) {
    do {
      local_8 = 0xf;
      local_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
      FUN_00401660(puVar10 + 1,0,0xffffffff);
      iVar3 = *(int *)(in_ECX + 0x2c);
      local_4 = *puVar10;
      if ((iVar3 == 0) ||
         ((uint)(*(int *)(in_ECX + 0x34) - iVar3 >> 5) <=
          (uint)(*(int *)(in_ECX + 0x30) - iVar3 >> 5))) {
        FUN_00843d20(*(undefined4 *)(in_ECX + 0x30),1,local_20);
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x30);
        FUN_008439b0(iVar3,1,local_20,in_ECX + 0x28,param_2);
        *(int *)(in_ECX + 0x30) = iVar3 + 0x20;
      }
      if (0xf < local_8) {
        _free(local_1c);
        return;
      }
      puVar10 = puVar10 + 8;
      local_8 = 0xf;
      local_c = 0;
      local_1c = (void *)((uint)local_1c & 0xffffff00);
    } while (puVar10 != puVar2);
  }
  piVar4 = *(int **)(param_2 + 0x34);
  piVar9 = (int *)*piVar4;
  if (piVar9 == piVar4) {
    *(undefined4 *)(in_ECX + 0x38) = 0;
    return;
  }
  do {
    iVar3 = piVar9[3];
    pvVar7 = operator_new(0x38);
    if (pvVar7 == (void *)0x0) {
      uVar8 = 0;
    }
    else {
      uVar8 = FUN_00847480();
    }
    FUN_008474b0(iVar3,piVar9 + 4);
    local_30 = iVar3;
    local_2c = uVar8;
    FUN_00843a60(local_28,&local_30);
    if (*(char *)((int)piVar9 + 0x3d) == '\0') {
      piVar5 = (int *)piVar9[2];
      if (*(char *)((int)piVar5 + 0x3d) == '\0') {
        cVar1 = *(char *)(*piVar5 + 0x3d);
        piVar9 = piVar5;
        piVar5 = (int *)*piVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar5 + 0x3d);
          piVar9 = piVar5;
          piVar5 = (int *)*piVar5;
        }
      }
      else {
        cVar1 = *(char *)(piVar9[1] + 0x3d);
        piVar6 = (int *)piVar9[1];
        piVar5 = piVar9;
        while ((piVar9 = piVar6, cVar1 == '\0' && (piVar5 == (int *)piVar9[2]))) {
          cVar1 = *(char *)(piVar9[1] + 0x3d);
          piVar6 = (int *)piVar9[1];
          piVar5 = piVar9;
        }
      }
    }
  } while (piVar9 != piVar4);
  *(undefined4 *)(in_ECX + 0x38) = 0;
  return;
}


// ==== FUN_008432d0 @ 0x008432d0 ====

int FUN_008432d0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999f90;
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


// ==== Catch@00843336 @ 0x00843336 ====

void Catch_00843336(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00843340 @ 0x00843340 ====

void FUN_00843340(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999fa0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008433af @ 0x008433af ====

void Catch_008433af(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008433d0 @ 0x008433d0 ====

void * FUN_008433d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999fb0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008335c0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0084343d @ 0x0084343d ====

void Catch_0084343d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00843460 @ 0x00843460 ====

void FUN_00843460(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999fc0;
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


// ==== Catch@008434c6 @ 0x008434c6 ====

void Catch_008434c6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008434d0 @ 0x008434d0 ====

void FUN_008434d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_008432d0(param_1,param_2,param_3);
  return;
}


// ==== FUN_008434f0 @ 0x008434f0 ====

int FUN_008434f0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00843460(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00843520 @ 0x00843520 ====

void FUN_00843520(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00999fd0;
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
      uVar5 = FUN_008434d0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_008434f0(uVar5,param_2,&local_18);
      FUN_008434d0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_008432d0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_008434f0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_008432d0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00843681 @ 0x00843681 ====

void Catch_00843681(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00843770 @ 0x00843770 ====

void FUN_00843770(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999fe0;
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
    uVar2 = FUN_008434f0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00843804 @ 0x00843804 ====

void Catch_00843804(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00843820 @ 0x00843820 ====

void FUN_00843820(int param_1,int param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  }
  return;
}


// ==== FUN_00843860 @ 0x00843860 ====

int FUN_00843860(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00999ff0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_00843820(param_3,param_1);
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@008438ca @ 0x008438ca ====

void Catch_008438ca(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008438f0 @ 0x008438f0 ====

void FUN_008438f0(uint param_1,undefined1 param_2)

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
    FUN_00843520(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00843960 @ 0x00843960 ====

/* WARNING: Removing unreachable block (ram,0x0084397b) */
/* WARNING: Removing unreachable block (ram,0x00843980) */
/* WARNING: Removing unreachable block (ram,0x0084398e) */

void FUN_00843960(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_00843520(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_008439b0 @ 0x008439b0 ====

void FUN_008439b0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a000;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00843820(param_1,param_3);
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00843a1a @ 0x00843a1a ====

void Catch_00843a1a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_00405c70(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00843a40 @ 0x00843a40 ====

void FUN_00843a40(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00843860(param_1,param_2,param_3);
  return;
}


// ==== FUN_00843a60 @ 0x00843a60 ====

/* WARNING: Removing unreachable block (ram,0x00843b48) */

void FUN_00843a60(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar3 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar3 * 2 + -3;
      FUN_008438f0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar3 = uVar6 * 4;
        if (((puVar7[2] ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar8 = (undefined4 *)*puVar7;
        }
        else {
          puVar8 = (undefined4 *)*puVar7;
          if (puVar8 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            uVar4 = uVar6;
            while ((puVar7 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3) = puVar8, uVar4 != 0))) {
              uVar4 = uVar4 - 1;
              iVar3 = uVar4 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            }
            iVar3 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar7[1] = puVar8;
            *(int *)puVar8[1] = iVar3;
            **(undefined4 **)(iVar3 + 4) = puVar7;
            uVar2 = *(undefined4 *)(iVar3 + 4);
            *(undefined4 *)(iVar3 + 4) = puVar8[1];
            puVar8[1] = puVar7[1];
            puVar7[1] = uVar2;
            puVar7 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar4 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar4 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4) == *(int *)(in_ECX + 8)));
              uVar4 = uVar4 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar4 * 4) = puVar7;
          }
          if (puVar8 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar7 = puVar8;
      } while (puVar8 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar6 = *param_2;
  uVar4 = (uVar6 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = uVar4 * 4;
  puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar3);
  if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3)) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      if ((uint)puVar7[2] <= uVar6) {
        if (uVar6 <= (uint)puVar7[2]) {
          *param_1 = (int)puVar7;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar7 = (undefined4 *)*puVar7;
        break;
      }
    } while (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3));
  }
  iVar5 = FUN_008433d0(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
  puVar7[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar7[1];
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  while ((puVar7 == puVar8 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar3) = iVar5, uVar4 != 0))) {
    uVar4 = uVar4 - 1;
    iVar3 = uVar4 * 4;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00843c90 @ 0x00843c90 ====

void FUN_00843c90(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (_Memory == *(void **)(in_ECX + 8)) {
    local_4 = *(undefined4 *)(in_ECX + 8);
    FUN_00843960(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00843cf0 @ 0x00843cf0 ====

int FUN_00843cf0(int param_1,int param_2,undefined4 param_3)

{
  FUN_008439b0(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_00843d20 @ 0x00843d20 ====

void FUN_00843d20(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  int iVar5;
  undefined1 local_5c [2];
  undefined1 auStack_5a [2];
  void *local_58;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_2c;
  void *local_28;
  uint local_24;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a010;
  local_10 = ExceptionList;
  local_14 = local_5c + -0xc;
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_40 = *(undefined4 *)(param_3 + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 0xc) - iVar2 >> 5;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    if (0x7ffffffU - iVar5 < param_2) {
      uVar1 = FUN_0085b3b0();
      iVar2 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    if (uVar1 < iVar5 + param_2) {
      if (0x7ffffff - (uVar1 >> 1) < uVar1) {
        local_24 = 0;
      }
      else {
        local_24 = uVar1 + (uVar1 >> 1);
      }
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (local_24 < iVar5 + param_2) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 5;
        }
        local_24 = iVar2 + param_2;
      }
      local_24 = local_24 << 5;
      pvVar3 = operator_new(local_24);
      local_8 = 0;
      local_28 = pvVar3;
      local_18 = pvVar3;
      local_18 = (void *)FUN_00843a40(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      local_18 = (void *)FUN_00843cf0(local_18,param_2,local_5c);
      FUN_00843a40(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (iVar2 != 0) {
        FUN_0068e630(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)pvVar3;
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar5) * 0x20 + (int)pvVar3);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)(local_2c - param_1 >> 5) < param_2) {
        local_1c = param_2 * 0x20;
        FUN_00843860(param_1,local_2c,local_1c + param_1);
        local_8 = 2;
        FUN_00843cf0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),local_5c);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_1c;
        FUN_00793c20(param_1,*(int *)(in_ECX + 8) - local_1c,local_5c);
      }
      else {
        local_1c = param_2 * 0x20;
        iVar2 = local_2c + param_2 * -0x20;
        uVar4 = FUN_00843860(iVar2,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0068e670(param_1,iVar2,local_2c,local_3c);
        FUN_00793c20(param_1,local_1c + param_1,local_5c);
      }
    }
  }
  if (local_44 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_58);
  return;
}


// ==== Catch@00843ea5 @ 0x00843ea5 ====

void Catch_00843ea5(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x24);
  FUN_0068e800(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@00843f37 @ 0x00843f37 ====

void Catch_00843f37(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x20;
  FUN_0068e800(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00843fc0 @ 0x00843fc0 ====

void FUN_00843fc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00843000();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00843fe0 @ 0x00843fe0 ====

void FUN_00843fe0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1034c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00844000 @ 0x00844000 ====

int FUN_00844000(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00844010 @ 0x00844010 ====

int FUN_00844010(void)

{
  int in_ECX;
  
  return in_ECX + 0x44;
}


// ==== FUN_00844020 @ 0x00844020 ====

int FUN_00844020(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_00844030 @ 0x00844030 ====

undefined4 FUN_00844030(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4c);
}


// ==== FUN_00844040 @ 0x00844040 ====

void FUN_00844040(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1035c;
  if ((undefined4 *)in_ECX[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x13])(1);
  }
  in_ECX[0x13] = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_00a1034c;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00844090 @ 0x00844090 ====

void FUN_00844090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1035c;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0x13] = 0;
  return;
}


// ==== FUN_008440b0 @ 0x008440b0 ====

undefined4 FUN_008440b0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_3c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_20;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  if ((*(int *)(param_2 + 0xc) == 0) || (*(int *)(param_2 + 0x20) == 0)) {
    return 0;
  }
  *(undefined4 *)(in_ECX + 4) = 0xb;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x24) = *(undefined1 *)(*(int *)(param_2 + 0xc) + 0x1c);
  puVar1 = *(undefined4 **)(param_2 + 0xc);
  *(undefined4 *)(in_ECX + 0x28) = *puVar1;
  *(undefined4 *)(in_ECX + 0x2c) = puVar1[1];
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x18);
  iVar2 = *(int *)(param_2 + 0xc);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(iVar2 + 8);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(iVar2 + 0xc);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(iVar2 + 0x10);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(*(int *)(param_2 + 0xc) + 0x14);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_2 + 8);
  if (*(undefined4 **)(in_ECX + 0x4c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x4c))(1);
  }
  local_28 = 0xf;
  local_c = 0xf;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  puVar1 = *(undefined4 **)(param_2 + 0x20);
  local_2c = 0;
  local_3c = 0;
  local_10 = 0;
  local_20 = 0;
  local_8 = 0;
  local_4 = 0;
  local_48 = *puVar1;
  local_44 = puVar1[1];
  FUN_00401660(puVar1 + 2,0,0xffffffff);
  FUN_00401660(*(int *)(param_2 + 0x20) + 0x24,0,0xffffffff);
  local_8 = *(undefined4 *)(*(int *)(param_2 + 0x20) + 0x40);
  local_4 = *(undefined1 *)(*(int *)(param_2 + 0x20) + 0x44);
  pvVar3 = operator_new(0x6c);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_008464d0();
  }
  *(undefined4 *)(in_ECX + 0x4c) = uVar4;
  FUN_00846570(&local_48);
  FUN_00844200();
  return 1;
}


// ==== FUN_00844200 @ 0x00844200 ====

void FUN_00844200(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x3c)) {
    _free(*(void **)(in_ECX + 0x28));
    return;
  }
  *(undefined4 *)(in_ECX + 0x3c) = 0xf;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0xf;
    *(undefined1 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0xc));
  return;
}


// ==== FUN_00844250 @ 0x00844250 ====

void FUN_00844250(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1035c;
  if ((undefined4 *)in_ECX[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x13])(1);
  }
  in_ECX[0x13] = 0;
  if (0xf < (uint)in_ECX[8]) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  *in_ECX = &PTR_FUN_00a1034c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008442b0 @ 0x008442b0 ====

int FUN_008442b0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_008442c0 @ 0x008442c0 ====

int FUN_008442c0(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_008442d0 @ 0x008442d0 ====

undefined4 FUN_008442d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}


// ==== FUN_008442e0 @ 0x008442e0 ====

undefined4 FUN_008442e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_008442f0 @ 0x008442f0 ====

void FUN_008442f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a103d0;
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_00844350 @ 0x00844350 ====

void FUN_00844350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a103d0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_00844370 @ 0x00844370 ====

uint FUN_00844370(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint extraout_EAX;
  void *pvVar4;
  uint extraout_EAX_00;
  int in_ECX;
  undefined1 local_64 [4];
  void *local_60;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_3c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_20;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  *(undefined4 *)(in_ECX + 4) = 1;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_2 + 8);
  if (*(int *)(param_2 + 0x20) != 0) {
    if (*(undefined4 **)(in_ECX + 0x2c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x2c))(1);
    }
    local_28 = 0xf;
    local_c = 0xf;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    puVar1 = *(undefined4 **)(param_2 + 0x20);
    local_2c = 0;
    local_3c = 0;
    local_10 = 0;
    local_20 = 0;
    local_8 = 0;
    local_4 = 0;
    local_48 = *puVar1;
    local_44 = puVar1[1];
    FUN_00401660(puVar1 + 2,0,0xffffffff);
    FUN_00401660(*(int *)(param_2 + 0x20) + 0x24,0,0xffffffff);
    local_8 = *(undefined4 *)(*(int *)(param_2 + 0x20) + 0x40);
    local_4 = *(undefined1 *)(*(int *)(param_2 + 0x20) + 0x44);
    pvVar4 = operator_new(0x6c);
    if (pvVar4 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_008464d0();
    }
    *(undefined4 *)(in_ECX + 0x2c) = uVar2;
    FUN_00846570(&local_48);
    _free(*(void **)(in_ECX + 0x30));
    return extraout_EAX_00;
  }
  uVar2 = FUN_004022a0(local_64,s_Cannot_find_Texture_Info___00a103ac,param_1);
  uVar3 = FUN_00796d50(uVar2);
  if (local_4c < 0x10) {
    return uVar3 & 0xffffff00;
  }
  _free(local_60);
  return extraout_EAX;
}


// ==== FUN_00844500 @ 0x00844500 ====

void FUN_00844500(byte param_1)

{
  void *in_ECX;
  
  FUN_008442f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00844520 @ 0x00844520 ====

int FUN_00844520(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00844530 @ 0x00844530 ====

int FUN_00844530(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_00844540 @ 0x00844540 ====

int FUN_00844540(void)

{
  int in_ECX;
  
  return in_ECX + 0x2c;
}


// ==== FUN_00844550 @ 0x00844550 ====

void FUN_00844550(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10428;
  if (0xf < (uint)in_ECX[0x11]) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_00a1034c;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_008445b0 @ 0x008445b0 ====

void FUN_008445b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10428;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_008445e0 @ 0x008445e0 ====

undefined4 FUN_008445e0(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 6;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_2 + 8);
  if (*(int *)(param_2 + 0x28) == 0) {
    return 0;
  }
  FUN_00401660(*(int *)(param_2 + 0x28),0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(*(int *)(param_2 + 0x28) + 0x1c);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(*(int *)(param_2 + 0x28) + 0x20);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(*(int *)(param_2 + 0x28) + 0x24);
  iVar1 = *(int *)(param_2 + 0x28);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(iVar1 + 0x28);
  *(undefined1 *)(in_ECX + 0x58) = *(undefined1 *)(*(int *)(param_2 + 0x28) + 0x2c);
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== FUN_00844660 @ 0x00844660 ====

void FUN_00844660(byte param_1)

{
  void *in_ECX;
  
  FUN_00844550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00844680 @ 0x00844680 ====

int FUN_00844680(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00844690 @ 0x00844690 ====

int FUN_00844690(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_008446a0 @ 0x008446a0 ====

int FUN_008446a0(void)

{
  int in_ECX;
  
  return in_ECX + 0x2c;
}


// ==== FUN_008446b0 @ 0x008446b0 ====

undefined4 FUN_008446b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x90);
}


// ==== FUN_008446c0 @ 0x008446c0 ====

void FUN_008446c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a104b8;
  if ((undefined4 *)in_ECX[0x24] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x24])(1);
  }
  in_ECX[0x24] = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_00a1034c;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00844710 @ 0x00844710 ====

void FUN_00844710(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a104b8;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[0x24] = 0;
  return;
}


// ==== FUN_00844730 @ 0x00844730 ====

undefined4 FUN_00844730(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  void *pvVar4;
  int in_ECX;
  undefined1 local_64 [4];
  void *local_60;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_3c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_20;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  *(undefined4 *)(in_ECX + 4) = 7;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_2 + 8);
  if (*(int *)(param_2 + 0x20) == 0) {
    uVar3 = FUN_004022a0(local_64,s_Cannot_find_Texture_Info___00a10474,param_1);
    FUN_00796d50(uVar3);
    if (0xf < local_4c) {
      _free(local_60);
      return extraout_EAX;
    }
  }
  else {
    if (*(int *)(param_2 + 0x24) != 0) {
      if (*(undefined4 **)(in_ECX + 0x90) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 0x90))(1);
      }
      local_28 = 0xf;
      local_c = 0xf;
      *(undefined4 *)(in_ECX + 0x90) = 0;
      puVar1 = *(undefined4 **)(param_2 + 0x20);
      local_2c = 0;
      local_3c = 0;
      local_10 = 0;
      local_20 = 0;
      local_8 = 0;
      local_4 = 0;
      local_48 = *puVar1;
      local_44 = puVar1[1];
      FUN_00401660(puVar1 + 2,0,0xffffffff);
      FUN_00401660(*(int *)(param_2 + 0x20) + 0x24,0,0xffffffff);
      local_8 = *(undefined4 *)(*(int *)(param_2 + 0x20) + 0x40);
      local_4 = *(undefined1 *)(*(int *)(param_2 + 0x20) + 0x44);
      pvVar4 = operator_new(0x6c);
      if (pvVar4 == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_008464d0();
      }
      *(undefined4 *)(in_ECX + 0x90) = uVar3;
      FUN_00846570(&local_48);
      *(undefined4 *)(in_ECX + 0x2c) = **(undefined4 **)(param_2 + 0x24);
      *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 4);
      *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x18);
      *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x14);
      *(undefined1 *)(in_ECX + 0x3c) = *(undefined1 *)(*(int *)(param_2 + 0x24) + 9);
      *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x20);
      *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x1c);
      *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x34);
      *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x3c);
      *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x38);
      *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x28);
      *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x24);
      *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x30);
      *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x2c);
      *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x10);
      *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0xc);
      iVar2 = *(int *)(param_2 + 0x24);
      *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(iVar2 + 0x40);
      *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(iVar2 + 0x44);
      *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(iVar2 + 0x48);
      iVar2 = *(int *)(param_2 + 0x24);
      *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(iVar2 + 0x4c);
      *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(iVar2 + 0x50);
      *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(iVar2 + 0x54);
      iVar2 = *(int *)(param_2 + 0x24);
      *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(iVar2 + 0x58);
      *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(iVar2 + 0x5c);
      *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(iVar2 + 0x60);
      FUN_00844200();
      return 1;
    }
    uVar3 = FUN_004022a0(local_64,s_Cannot_find_Particle_Info___00a10490,param_1);
    FUN_00796d50(uVar3);
    if (0xf < local_4c) {
      _free(local_60);
      return extraout_EAX_00;
    }
  }
  return 0;
}


// ==== FUN_00844990 @ 0x00844990 ====

void FUN_00844990(byte param_1)

{
  void *in_ECX;
  
  FUN_008446c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008449b0 @ 0x008449b0 ====

void FUN_008449b0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = 0;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x1c));
    *(undefined4 *)(in_ECX + 0x1c) = 0;
  }
  return;
}


// ==== FUN_008449e0 @ 0x008449e0 ====

undefined4 FUN_008449e0(byte *param_1,undefined4 *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  char cVar9;
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar8 = param_2;
  pbVar7 = param_1;
  if ((*param_1 & 1) == 0) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x20) == 0) {
    iVar6 = *(int *)(in_ECX + 0x1c);
    local_c = *(undefined4 *)(iVar6 + 0x70);
    local_8 = *(undefined4 *)(iVar6 + 0x74);
    local_4 = *(undefined4 *)(iVar6 + 0x78);
    local_18 = *(undefined4 *)(iVar6 + 0x7c);
    local_14 = *(undefined4 *)(iVar6 + 0x80);
    local_10 = *(undefined4 *)(iVar6 + 0x84);
    pfVar1 = (float *)(param_1 + 0xc);
    cVar9 = FUN_0040dfb0(pfVar1,&local_c,&local_18,&param_1);
    if (cVar9 != '\0') {
      fVar2 = *(float *)(pbVar7 + 0x1c);
      fVar3 = *(float *)(pbVar7 + 0x20);
      fVar4 = *(float *)(pbVar7 + 0x10);
      fVar5 = *(float *)(pbVar7 + 0x14);
      param_2[2] = *pfVar1 + *(float *)(pbVar7 + 0x18) * (float)param_1;
      param_2[3] = fVar4 + fVar2 * (float)param_1;
      *param_2 = 1;
      param_2[4] = fVar5 + fVar3 * (float)param_1;
      return 1;
    }
  }
  else {
    cVar9 = FUN_00844be0(*(int *)(in_ECX + 0x20),param_1 + 0xc,param_2 + 2);
    if (cVar9 != '\0') {
      *puVar8 = 1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00844b10 @ 0x00844b10 ====

void FUN_00844b10(int *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 != (int *)0x0) {
    if (*(int *)(in_ECX + 0x1c) != 0) {
      *(undefined4 *)(in_ECX + 0x20) = 0;
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x1c));
      *(undefined4 *)(in_ECX + 0x1c) = 0;
    }
    *(int **)(in_ECX + 0x1c) = param_1;
    (**(code **)(*param_1 + 0x1c))();
    uVar1 = FUN_004b9df0(in_ECX);
    *(undefined4 *)(in_ECX + 0x20) = uVar1;
  }
  return;
}


// ==== FUN_00844b60 @ 0x00844b60 ====

void FUN_00844b60(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = 0;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x1c));
    *(undefined4 *)(in_ECX + 0x1c) = 0;
  }
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00844bb0 @ 0x00844bb0 ====

void FUN_00844bb0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401740(s_picking_00a10508,7);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_00844be0 @ 0x00844be0 ====

uint FUN_00844be0(int param_1,float *param_2,float *param_3)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  uint uVar9;
  ushort *puVar10;
  uint extraout_EAX;
  uint extraout_EAX_00;
  ushort *puVar11;
  ushort *puVar12;
  undefined1 local_20 [4];
  undefined1 local_1c [16];
  float *local_c;
  float *local_8;
  undefined4 local_4;
  
  uVar9 = FUN_0040dfb0(param_2,param_1 + 0x1c,param_1 + 0x28,local_20);
  if ((char)uVar9 == '\0') {
    return uVar9;
  }
  puVar2 = *(ushort **)(param_1 + 0x4c);
  puVar11 = *(ushort **)(param_1 + 0x48);
  local_c = (float *)0x0;
  local_8 = (float *)0x0;
  local_4 = 0;
  puVar10 = puVar2;
  if (puVar11 != puVar2) {
    do {
      iVar3 = *(int *)(param_1 + 0x38);
      uVar1 = *puVar11;
      puVar10 = puVar11 + 1;
      if ((iVar3 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar3) / 0x28) <= (uint)uVar1)) {
LAB_00844d41:
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      puVar12 = puVar11 + 2;
      if ((iVar3 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar3) / 0x28) <= (uint)*puVar10))
      goto LAB_00844d41;
      iVar4 = *(int *)(param_1 + 0x38);
      puVar11 = puVar11 + 3;
      if ((iVar4 == 0) || ((uint)((*(int *)(param_1 + 0x3c) - iVar4) / 0x28) <= (uint)*puVar12))
      goto LAB_00844d41;
      puVar10 = (ushort *)
                FUN_0040e5f0(param_2,iVar3 + (uint)uVar1 * 0x28,iVar3 + (uint)*puVar10 * 0x28,
                             iVar4 + (uint)*puVar12 * 0x28,local_1c);
      if ((char)puVar10 != '\0') {
        puVar10 = (ushort *)FUN_005c2400(local_1c);
      }
    } while (puVar11 != puVar2);
    if (local_c != (float *)0x0) {
      if (((int)local_8 - (int)local_c) / 0xc == 0) {
        _free(local_c);
        return extraout_EAX;
      }
      *param_3 = *local_c;
      param_3[1] = local_c[1];
      param_3[2] = local_c[2];
      fVar6 = SQRT((*param_3 - *param_2) * (*param_3 - *param_2) +
                   (param_3[1] - param_2[1]) * (param_3[1] - param_2[1]) +
                   (param_3[2] - param_2[2]) * (param_3[2] - param_2[2]));
      pfVar8 = local_c;
      while (pfVar7 = pfVar8, pfVar8 = pfVar7 + 3, pfVar8 != local_8) {
        fVar5 = SQRT((*pfVar8 - *param_2) * (*pfVar8 - *param_2) +
                     (pfVar7[4] - param_2[1]) * (pfVar7[4] - param_2[1]) +
                     (pfVar7[5] - param_2[2]) * (pfVar7[5] - param_2[2]));
        if (fVar5 < fVar6) {
          *param_3 = *pfVar8;
          param_3[1] = pfVar7[4];
          param_3[2] = pfVar7[5];
          fVar6 = fVar5;
        }
      }
      _free(local_c);
      return extraout_EAX_00;
    }
  }
  return (uint)puVar10 & 0xffffff00;
}


// ==== FUN_00844e10 @ 0x00844e10 ====

void FUN_00844e10(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50) = param_1;
  return;
}


// ==== FUN_00844e20 @ 0x00844e20 ====

void FUN_00844e20(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x4c) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x38) = uVar1;
  *(undefined4 *)(in_ECX + 0x24) = uVar1;
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  return;
}


// ==== FUN_00844ea0 @ 0x00844ea0 ====

void FUN_00844ea0(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x54) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x54))(1);
  }
  *(undefined4 *)(in_ECX + 0x54) = 0;
  if (*(undefined4 **)(in_ECX + 0x58) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x58))(1);
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  if (*(undefined4 **)(in_ECX + 0x5c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x5c))(1);
  }
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  if (*(undefined4 **)(in_ECX + 0x60) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x60))(1);
  }
  *(undefined4 *)(in_ECX + 0x60) = 0;
  if (*(undefined4 **)(in_ECX + 100) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 100))(1);
  }
  *(undefined4 *)(in_ECX + 100) = 0;
  if (*(undefined4 **)(in_ECX + 0x68) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x68))(1);
  }
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  return;
}


// ==== FUN_00844f10 @ 0x00844f10 ====

undefined4 FUN_00844f10(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) == 0) {
    pvVar1 = operator_new(0xe8);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0083d2e0();
      *(undefined4 *)(in_ECX + 0x54) = uVar2;
      return uVar2;
    }
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  return *(undefined4 *)(in_ECX + 0x54);
}


// ==== FUN_00844f40 @ 0x00844f40 ====

void FUN_00844f40(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x54) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x54))(1);
  }
  *(undefined4 *)(in_ECX + 0x54) = 0;
  return;
}


// ==== FUN_00844f60 @ 0x00844f60 ====

undefined4 FUN_00844f60(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x58) == 0) {
    pvVar1 = operator_new(0x38);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_008479a0();
      *(undefined4 *)(in_ECX + 0x58) = uVar2;
      return uVar2;
    }
    *(undefined4 *)(in_ECX + 0x58) = 0;
  }
  return *(undefined4 *)(in_ECX + 0x58);
}


// ==== FUN_00844f90 @ 0x00844f90 ====

void FUN_00844f90(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x58) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x58))(1);
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  return;
}


// ==== FUN_00844fb0 @ 0x00844fb0 ====

undefined4 FUN_00844fb0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x5c) == 0) {
    pvVar1 = operator_new(0x38);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_008479a0();
      *(undefined4 *)(in_ECX + 0x5c) = uVar2;
      return uVar2;
    }
    *(undefined4 *)(in_ECX + 0x5c) = 0;
  }
  return *(undefined4 *)(in_ECX + 0x5c);
}


// ==== FUN_00844fe0 @ 0x00844fe0 ====

void FUN_00844fe0(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x5c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x5c))(1);
  }
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  return;
}


// ==== FUN_00845000 @ 0x00845000 ====

undefined4 FUN_00845000(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x60) == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00845fe0();
      *(undefined4 *)(in_ECX + 0x60) = uVar2;
      return uVar2;
    }
    *(undefined4 *)(in_ECX + 0x60) = 0;
  }
  return *(undefined4 *)(in_ECX + 0x60);
}


// ==== FUN_00845030 @ 0x00845030 ====

void FUN_00845030(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x60) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x60))(1);
  }
  *(undefined4 *)(in_ECX + 0x60) = 0;
  return;
}


// ==== FUN_00845050 @ 0x00845050 ====

undefined4 FUN_00845050(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) == 0) {
    pvVar1 = operator_new(0x2c);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00845440();
      *(undefined4 *)(in_ECX + 100) = uVar2;
      FUN_008451c0(*(undefined4 *)(in_ECX + 0x50));
      return *(undefined4 *)(in_ECX + 100);
    }
    *(undefined4 *)(in_ECX + 100) = 0;
    FUN_008451c0(*(undefined4 *)(in_ECX + 0x50));
  }
  return *(undefined4 *)(in_ECX + 100);
}


// ==== FUN_008450a0 @ 0x008450a0 ====

void FUN_008450a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) != 0) {
    FUN_008451e0();
    if (*(undefined4 **)(in_ECX + 100) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 100))(1);
    }
    *(undefined4 *)(in_ECX + 100) = 0;
  }
  return;
}


// ==== FUN_008450d0 @ 0x008450d0 ====

undefined4 FUN_008450d0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x68) == 0) {
    pvVar1 = operator_new(0x50);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00847ce0();
      *(undefined4 *)(in_ECX + 0x68) = uVar2;
      FUN_00847b80(in_ECX);
      return *(undefined4 *)(in_ECX + 0x68);
    }
    *(undefined4 *)(in_ECX + 0x68) = 0;
    FUN_00847b80(in_ECX);
  }
  return *(undefined4 *)(in_ECX + 0x68);
}


// ==== FUN_00845110 @ 0x00845110 ====

void FUN_00845110(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x68) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x68))(1);
    *(undefined4 *)(in_ECX + 0x68) = 0;
  }
  return;
}


// ==== FUN_00845130 @ 0x00845130 ====

int FUN_00845130(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x54);
  if (((iVar1 == 0) || (*(char *)(iVar1 + 4) == '\0')) || (iVar1 == -0x6c)) {
    return in_ECX + 0x10;
  }
  iVar1 = FUN_0083cfe0();
  return iVar1;
}


// ==== FUN_00845150 @ 0x00845150 ====

void FUN_00845150(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  *in_ECX = 0;
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[0x14] + 0x14))();
  in_ECX[2] = piVar1[2] - *piVar1;
  iVar2 = (**(code **)(*(int *)in_ECX[0x14] + 0x14))();
  in_ECX[3] = *(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 4);
  return;
}


// ==== FUN_008451a0 @ 0x008451a0 ====

void FUN_008451a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a105d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008451c0 @ 0x008451c0 ====

void FUN_008451c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_008451e0 @ 0x008451e0 ====

void FUN_008451e0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_008451f0 @ 0x008451f0 ====

void FUN_008451f0(undefined1 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  
  if (((param_1 != (undefined1 *)0x0) && (*param_1 = 0, *(int *)(in_ECX + 4) != 0)) &&
     (puVar1 = *(undefined4 **)(param_1 + 0x1c), puVar1 != (undefined4 *)0x0)) {
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    iVar2 = piVar5[1];
    iVar3 = piVar5[1];
    iVar4 = *piVar5;
    if ((-1 < *(int *)(param_1 + 4) + *piVar5) && (-1 < *(int *)(param_1 + 8) + iVar3)) {
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 4) + *piVar5;
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 8) + iVar3;
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0xc) + iVar4;
      *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x10) + iVar2;
      FUN_004e9a10(piVar5 + 4);
      *(undefined4 *)(param_1 + 0x98) = *puVar1;
      FUN_004e9a10(puVar1 + 1);
      param_1[0x25] = *(undefined1 *)(puVar1 + 5);
      FUN_004e9a10(puVar1 + 6);
      param_1[0x24] = 1;
      *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
      param_1[0x26] = 0;
      *(undefined4 *)(param_1 + 0x9c) = 0;
      *param_1 = 1;
    }
  }
  return;
}


// ==== FUN_008452b0 @ 0x008452b0 ====

void FUN_008452b0(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  if (((param_1 != (undefined1 *)0x0) && (*param_1 = 0, *(int *)(in_ECX + 4) != 0)) &&
     (*(int *)(param_1 + 0x40) != 0)) {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    iVar1 = piVar4[1];
    iVar2 = piVar4[1];
    iVar3 = *piVar4;
    if ((-1 < *(int *)(param_1 + 4) + *piVar4) && (-1 < *(int *)(param_1 + 8) + iVar2)) {
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 4) + *piVar4;
      *(int *)(param_1 + 0x60) = *(int *)(param_1 + 8) + iVar2;
      *(int *)(param_1 + 100) = *(int *)(param_1 + 0xc) + iVar3;
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x10) + iVar1;
      FUN_004e9a10(piVar4 + 4);
      *(undefined4 *)(param_1 + 0xbc) = *(undefined4 *)(param_1 + 0x40);
      FUN_004e9a10(param_1 + 0x30);
      param_1[0x49] = 0;
      param_1[0x48] = 1;
      *(undefined4 *)(param_1 + 0x58) = 0xffffffff;
      param_1[0x4a] = 0;
      *(undefined4 *)(param_1 + 0xc0) = 0;
      *param_1 = 1;
    }
  }
  return;
}


// ==== FUN_00845350 @ 0x00845350 ====

void FUN_00845350(void)

{
  int in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x10);
  for (puVar1 = *(undefined4 **)(in_ECX + 0xc); puVar1 != puVar2; puVar1 = puVar1 + 1) {
    FUN_008451f0(*puVar1);
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x20);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x1c); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    FUN_008452b0(*puVar2);
  }
  return;
}


// ==== FUN_008453a0 @ 0x008453a0 ====

void FUN_008453a0(int *param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  for (puVar4 = *(undefined4 **)(in_ECX + 0xc); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    pcVar2 = (char *)*puVar4;
    if (*pcVar2 != '\0') {
      iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
      *(int *)(pcVar2 + 0x30) = *(int *)(iVar3 + 0x20) + *(int *)(pcVar2 + 0x20);
      (**(code **)(*param_1 + 0x74))(pcVar2 + 0x24);
    }
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x20);
  for (puVar4 = *(undefined4 **)(in_ECX + 0x1c); puVar4 != puVar1; puVar4 = puVar4 + 1) {
    pcVar2 = (char *)*puVar4;
    if (*pcVar2 != '\0') {
      iVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))();
      *(int *)(pcVar2 + 0x54) = *(int *)(iVar3 + 0x20) + *(int *)(pcVar2 + 0x44);
      (**(code **)(*param_1 + 0x74))(pcVar2 + 0x48);
    }
  }
  return;
}


// ==== FUN_00845440 @ 0x00845440 ====

void FUN_00845440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a105ec;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  return;
}


// ==== FUN_00845470 @ 0x00845470 ====

void FUN_00845470(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined1 uStack00000000;
  undefined4 local_8;
  undefined4 local_4;
  
  pvVar3 = operator_new(0xa0);
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00845ab0(param_1);
  }
  local_8 = *(undefined4 *)(iVar4 + 0x14);
  local_4 = *(undefined4 *)(iVar4 + 0x18);
  uVar5 = (**(code **)*DAT_00b5a7c4)(&local_8);
  *(undefined4 *)(iVar4 + 0x1c) = uVar5;
  iVar1 = *(int *)(in_ECX + 0xc);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2)))
  {
    FUN_008457e0(*(undefined4 *)(in_ECX + 0x10),1,&uStack00000000);
  }
  else {
    piVar2 = *(int **)(in_ECX + 0x10);
    *piVar2 = iVar4;
    *(int **)(in_ECX + 0x10) = piVar2 + 1;
  }
  FUN_008451f0(iVar4);
  *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + 1;
  *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(in_ECX + 0x28);
  return;
}


// ==== FUN_00845520 @ 0x00845520 ====

void FUN_00845520(int param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  pvVar3 = operator_new(0xc4);
  iVar1 = param_1;
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00845b30(param_1);
  }
  param_1 = iVar4;
  uVar5 = FUN_004b4e70(iVar1 + 0x10);
  *(undefined4 *)(iVar4 + 0x40) = uVar5;
  iVar1 = *(int *)(in_ECX + 0x1c);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x24) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x20) - iVar1 >> 2)))
  {
    FUN_008457e0(*(undefined4 *)(in_ECX + 0x20),1,&param_1);
  }
  else {
    piVar2 = *(int **)(in_ECX + 0x20);
    *piVar2 = iVar4;
    *(int **)(in_ECX + 0x20) = piVar2 + 1;
  }
  FUN_008452b0(iVar4);
  *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + 1;
  *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(in_ECX + 0x28);
  return;
}


// ==== FUN_008455c0 @ 0x008455c0 ====

void FUN_008455c0(void)

{
  int iVar1;
  void *_Memory;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  int local_8;
  undefined4 local_4;
  
  piVar5 = *(int **)(in_ECX + 0x10);
  for (piVar4 = *(int **)(in_ECX + 0xc); piVar4 != piVar5; piVar4 = piVar4 + 1) {
    iVar1 = *piVar4;
    local_8 = *(int *)(iVar1 + 0x14);
    local_4 = *(undefined4 *)(iVar1 + 0x18);
    (**(code **)(*DAT_00b5a7c4 + 4))(&local_8);
    *(undefined4 *)(iVar1 + 0x1c) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 != 0) {
    iVar2 = *(int *)(in_ECX + 0x10) - iVar1;
    local_8 = iVar2 >> 2;
    if (local_8 != 0) {
      local_8._1_3_ = (uint3)(iVar2 >> 10);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00845b90(iVar1,*(int *)(in_ECX + 0x10),local_8);
      if (*(void **)(in_ECX + 0xc) != (void *)0x0) {
        _free(*(void **)(in_ECX + 0xc));
        return;
      }
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)(in_ECX + 0x10) = 0;
      *(undefined4 *)(in_ECX + 0x14) = 0;
    }
  }
  piVar4 = *(int **)(in_ECX + 0x20);
  for (piVar5 = *(int **)(in_ECX + 0x1c); piVar5 != piVar4; piVar5 = piVar5 + 1) {
    iVar1 = *piVar5;
    iVar2 = *(int *)(iVar1 + 0x40);
    if (iVar2 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
      *(undefined4 *)(iVar1 + 0x40) = 0;
    }
  }
  puVar3 = *(undefined4 **)(in_ECX + 0x1c);
  if (puVar3 != (undefined4 *)0x0) {
    local_8 = (int)*(undefined4 **)(in_ECX + 0x20) - (int)puVar3 >> 2;
    if (local_8 != 0) {
      for (; puVar3 != *(undefined4 **)(in_ECX + 0x20); puVar3 = puVar3 + 1) {
        _Memory = (void *)*puVar3;
        if (_Memory != (void *)0x0) {
          FUN_00845a30();
          _free(_Memory);
          return;
        }
      }
      if (*(void **)(in_ECX + 0x1c) == (void *)0x0) {
        *(undefined4 *)(in_ECX + 0x1c) = 0;
        *(undefined4 *)(in_ECX + 0x20) = 0;
        *(undefined4 *)(in_ECX + 0x24) = 0;
        *(undefined4 *)(in_ECX + 0x28) = 0;
        return;
      }
      _free(*(void **)(in_ECX + 0x1c));
      return;
    }
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  return;
}


// ==== FUN_008456f0 @ 0x008456f0 ====

void FUN_008456f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a105ec;
  FUN_008455c0();
  if ((void *)in_ECX[7] != (void *)0x0) {
    _free((void *)in_ECX[7]);
    return;
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_00a105d8;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00845740 @ 0x00845740 ====

undefined4 * FUN_00845740(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_2 != 0) {
    puVar1 = param_1;
    iVar2 = param_2;
    do {
      *puVar1 = *param_3;
      puVar1 = puVar1 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return param_1 + param_2;
}


// ==== FUN_00845770 @ 0x00845770 ====

void FUN_00845770(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_00401660(param_1 + 4,0,0xffffffff);
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = param_1[0xe];
  return;
}


// ==== FUN_008457e0 @ 0x008457e0 ====

void FUN_008457e0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a020;
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


// ==== Catch@00845941 @ 0x00845941 ====

void Catch_00845941(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00845a30 @ 0x00845a30 ====

void FUN_00845a30(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0xb0) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xb0));
    return;
  }
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  if (*(void **)(in_ECX + 0xa0) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xa0));
    return;
  }
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  if (*(uint *)(in_ECX + 0x2c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0xf;
    *(undefined1 *)(in_ECX + 0x18) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_00845ab0 @ 0x00845ab0 ====

void FUN_00845ab0(undefined4 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = 0;
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  *(undefined4 *)(in_ECX + 0x14) = param_1[4];
  *(undefined4 *)(in_ECX + 0x18) = param_1[5];
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  return;
}


// ==== FUN_00845b30 @ 0x00845b30 ====

void FUN_00845b30(undefined4 param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = 0;
  FUN_00845770(param_1);
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x4a] = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = 0;
  return;
}


// ==== FUN_00845b90 @ 0x00845b90 ====

uint FUN_00845b90(undefined4 *param_1,undefined4 *param_2,byte param_3)

{
  void *_Memory;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  
  while( true ) {
    if (param_1 == param_2) {
      return (uint)param_3;
    }
    _Memory = (void *)*param_1;
    if (_Memory != (void *)0x0) break;
    param_1 = param_1 + 1;
  }
  if (*(void **)((int)_Memory + 0x8c) != (void *)0x0) {
    _free(*(void **)((int)_Memory + 0x8c));
    return extraout_EAX;
  }
  *(undefined4 *)((int)_Memory + 0x8c) = 0;
  *(undefined4 *)((int)_Memory + 0x90) = 0;
  *(undefined4 *)((int)_Memory + 0x94) = 0;
  if (*(void **)((int)_Memory + 0x7c) == (void *)0x0) {
    *(undefined4 *)((int)_Memory + 0x7c) = 0;
    *(undefined4 *)((int)_Memory + 0x80) = 0;
    *(undefined4 *)((int)_Memory + 0x84) = 0;
    _free(_Memory);
    return extraout_EAX_01;
  }
  _free(*(void **)((int)_Memory + 0x7c));
  return extraout_EAX_00;
}


// ==== FUN_00845c10 @ 0x00845c10 ====

void FUN_00845c10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a105ec;
  FUN_008455c0();
  if ((void *)in_ECX[7] != (void *)0x0) {
    _free((void *)in_ECX[7]);
    return;
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  if ((void *)in_ECX[3] != (void *)0x0) {
    _free((void *)in_ECX[3]);
    return;
  }
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *in_ECX = &PTR_FUN_00a105d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00845c70 @ 0x00845c70 ====

void FUN_00845c70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10640;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00845c90 @ 0x00845c90 ====

void FUN_00845c90(void *param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (param_1 == (void *)0x0) {
    return;
  }
  puVar1 = (undefined4 *)((int)param_1 + 4);
  if (*(uint *)((int)param_1 + 0x18) < 0x10) {
    puVar3 = puVar1;
  }
  else {
    puVar3 = (undefined4 *)*puVar1;
  }
  puVar2 = (undefined1 *)(*(int *)((int)param_1 + 0x14) + (int)puVar3);
  if (*(uint *)((int)param_1 + 0x18) < 0x10) {
    puVar5 = puVar1;
    puVar3 = puVar1;
  }
  else {
    puVar5 = (undefined4 *)*puVar1;
    puVar3 = (undefined4 *)*puVar1;
  }
  if (puVar3 == (undefined4 *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (int)puVar3 - (int)puVar5;
  }
  if (puVar2 != (undefined1 *)0x0) {
    puVar2 = puVar2 + -(int)puVar3;
  }
  FUN_00401390(iVar4,puVar2);
  if (*(uint *)((int)param_1 + 0x18) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x18) = 0xf;
    *(undefined4 *)((int)param_1 + 0x14) = 0;
    *(undefined1 *)puVar1 = 0;
    _free(param_1);
    return;
  }
  _free((void *)*puVar1);
  return;
}


// ==== FUN_00845d20 @ 0x00845d20 ====

void FUN_00845d20(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a030;
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


// ==== Catch@00845e81 @ 0x00845e81 ====

void Catch_00845e81(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00845f70 @ 0x00845f70 ====

void FUN_00845f70(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  if ((puVar2 != (undefined4 *)0x0) &&
     (puVar1 = *(undefined4 **)(param_1 + 8), (int)puVar1 - (int)puVar2 >> 2 != 0)) {
    for (; puVar2 != puVar1; puVar2 = puVar2 + 1) {
      FUN_00845c90(*puVar2);
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


// ==== FUN_00845fd0 @ 0x00845fd0 ====

void FUN_00845fd0(void)

{
  int in_ECX;
  
  FUN_00845f70(in_ECX + 4);
  return;
}


// ==== FUN_00845fe0 @ 0x00845fe0 ====

void FUN_00845fe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10650;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_00846000 @ 0x00846000 ====

void FUN_00846000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10650;
  FUN_00845f70(in_ECX + 1);
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_00a10640;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00846050 @ 0x00846050 ====

void FUN_00846050(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2)))
  {
    FUN_00845d20(*(undefined4 *)(in_ECX + 0xc),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0xc) = puVar2 + 1;
  return;
}


// ==== FUN_008460a0 @ 0x008460a0 ====

void FUN_008460a0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  iVar4 = param_1;
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar5 = *(undefined4 **)(in_ECX + 8); puVar5 != puVar1; puVar5 = puVar5 + 1) {
    iVar2 = *(int *)(iVar4 + 0x58);
    param_1 = *puVar5;
    if ((iVar2 == 0) ||
       ((uint)(*(int *)(iVar4 + 0x60) - iVar2 >> 2) <= (uint)(*(int *)(iVar4 + 0x5c) - iVar2 >> 2)))
    {
      FUN_00845d20(*(undefined4 *)(iVar4 + 0x5c),1,&param_1);
    }
    else {
      puVar3 = *(undefined4 **)(iVar4 + 0x5c);
      *puVar3 = param_1;
      *(undefined4 **)(iVar4 + 0x5c) = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_00846110 @ 0x00846110 ====

void FUN_00846110(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10650;
  FUN_00845f70(in_ECX + 1);
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_00a10640;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008461d0 @ 0x008461d0 ====

void FUN_008461d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[1] = param_2;
  if (param_4 < 2) {
    param_4 = 1;
  }
  in_ECX[3] = param_4;
  return;
}


// ==== FUN_00846200 @ 0x00846200 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00846200(uint param_1)

{
  int iVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  int *in_ECX;
  float fVar5;
  
  iVar4 = *in_ECX;
  if (iVar4 == 5) {
    return in_ECX[1];
  }
  if (iVar4 == 3) {
    if ((uint)in_ECX[3] <= param_1) {
      return in_ECX[2];
    }
LAB_00846276:
    bVar3 = false;
  }
  else {
    if (iVar4 == 4) {
      if ((uint)in_ECX[3] <= param_1) {
LAB_00846234:
        return in_ECX[1];
      }
    }
    else {
      if (iVar4 == 0) {
        bVar3 = false;
        param_1 = param_1 % (uint)in_ECX[3];
        goto LAB_00846282;
      }
      if (iVar4 == 1) {
        param_1 = param_1 % (uint)in_ECX[3];
      }
      else {
        if (iVar4 != 2) goto LAB_00846234;
        param_1 = param_1 % (uint)(in_ECX[3] * 2);
        if (param_1 < (uint)in_ECX[3]) goto LAB_00846276;
        param_1 = param_1 - in_ECX[3];
      }
    }
    bVar3 = true;
  }
LAB_00846282:
  if ((uint)in_ECX[3] < param_1) {
    param_1 = in_ECX[3];
  }
  fVar5 = (float)(int)param_1;
  if ((int)param_1 < 0) {
    fVar5 = fVar5 + _DAT_0099d104;
  }
  fVar2 = (float)in_ECX[3];
  if (in_ECX[3] < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar5 = fVar5 / fVar2;
  if (bVar3) {
    fVar5 = DAT_0099d080 - fVar5;
  }
  iVar1 = in_ECX[1];
  if (iVar4 == 2) {
    iVar4 = (int)((float)(in_ECX[2] - iVar1) * fVar5 + (float)iVar1 + DAT_0099d0b4);
    if (in_ECX[2] < iVar4) {
      iVar4 = in_ECX[2];
    }
    if (iVar4 < in_ECX[1]) {
      return in_ECX[1];
    }
  }
  else {
    iVar4 = (int)((float)((in_ECX[2] - iVar1) + 1) * fVar5 + (float)iVar1);
    if (in_ECX[2] < iVar4) {
      iVar4 = in_ECX[2];
    }
    if (iVar4 < in_ECX[1]) {
      return in_ECX[1];
    }
  }
  return iVar4;
}


// ==== FUN_00846350 @ 0x00846350 ====

void FUN_00846350(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 0) &&
     (iVar1 = *(int *)(in_ECX + 4) + -1, *(int *)(in_ECX + 4) = iVar1, iVar1 == 0)) {
    if (*(int *)(in_ECX + 0x54) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x54));
      *(undefined4 *)(in_ECX + 0x54) = 0;
    }
    if (*(int *)(in_ECX + 0x58) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x58));
      *(undefined4 *)(in_ECX + 0x58) = 0;
    }
    *(undefined1 *)(in_ECX + 0x51) = 0;
    *(undefined1 *)(in_ECX + 0x50) = 0;
  }
  return;
}


// ==== FUN_008463a0 @ 0x008463a0 ====

undefined4 FUN_008463a0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x51) == '\0') {
    if (*(int **)(in_ECX + 0x54) == (int *)0x0) {
      if (*(int **)(in_ECX + 0x58) == (int *)0x0) {
        return 0;
      }
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x58) + 0x2c))();
      if (cVar1 == '\0') {
        return 0;
      }
      if (*(int *)(in_ECX + 8) == 0) {
        cVar1 = '\0';
      }
      else {
        cVar1 = (*(int *)(in_ECX + 8) != 1) + '\x01';
      }
      iVar2 = FUN_004b3b40();
      FUN_008461d0(cVar1,0,iVar2 + -1,*(undefined4 *)(in_ECX + 0x48));
    }
    else {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x2c))();
      if (cVar1 == '\0') {
        return 0;
      }
    }
    *(undefined1 *)(in_ECX + 0x51) = 1;
  }
  return 1;
}


// ==== FUN_00846410 @ 0x00846410 ====

int FUN_00846410(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  cVar1 = FUN_008463a0();
  if (cVar1 == '\0') {
    return 0;
  }
  iVar3 = *(int *)(in_ECX + 0x54);
  if (iVar3 == 0) {
    uVar2 = FUN_00846200(param_1);
    iVar3 = FUN_004b3ff0(uVar2);
  }
  return iVar3;
}


// ==== FUN_00846450 @ 0x00846450 ====

void FUN_00846450(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a106a0;
  if (in_ECX[0x15] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x15]);
    in_ECX[0x15] = 0;
  }
  if (in_ECX[0x16] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x16]);
    in_ECX[0x16] = 0;
  }
  if (0xf < (uint)in_ECX[0x11]) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[9] = 0;
    in_ECX[10] = 0xf;
    *(undefined1 *)(in_ECX + 5) = 0;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_008464d0 @ 0x008464d0 ====

void FUN_008464d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a106a0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 1;
  in_ECX[9] = 0;
  in_ECX[10] = 0xf;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0x13) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)((int)in_ECX + 0x51) = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  return;
}


// ==== FUN_00846520 @ 0x00846520 ====

void FUN_00846520(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  if (*(char *)(in_ECX + 0x50) == '\0') {
    if (*(int *)(in_ECX + 0x24) != 0) {
      uVar1 = FUN_005aa1b0(in_ECX + 0x10);
      *(undefined4 *)(in_ECX + 0x54) = uVar1;
      *(undefined1 *)(in_ECX + 0x51) = 0;
      *(undefined1 *)(in_ECX + 0x50) = 1;
      return;
    }
    if (*(int *)(in_ECX + 0x40) != 0) {
      uVar1 = FUN_005aa220(in_ECX + 0x2c);
      *(undefined4 *)(in_ECX + 0x58) = uVar1;
    }
    *(undefined1 *)(in_ECX + 0x51) = 0;
    *(undefined1 *)(in_ECX + 0x50) = 1;
  }
  return;
}


// ==== FUN_00846570 @ 0x00846570 ====

void FUN_00846570(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_1[1];
  FUN_00401660(param_1 + 2,0,0xffffffff);
  FUN_00401660(param_1 + 9,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x48) = param_1[0x10];
  *(undefined1 *)(in_ECX + 0x4c) = *(undefined1 *)(param_1 + 0x11);
  return;
}


// ==== FUN_008465c0 @ 0x008465c0 ====

void FUN_008465c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00846450();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008465e0 @ 0x008465e0 ====

void FUN_008465e0(void)

{
  void *_Memory;
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  
  FUN_004f4a10(in_ECX + 0x30);
  if (*(int *)(in_ECX + 0x50) == 0) {
    return;
  }
  uVar1 = (*(int *)(in_ECX + 0x50) + *(int *)(in_ECX + 0x4c)) - 1;
  uVar2 = uVar1 >> 2;
  iVar3 = uVar2 * -4;
  if (*(uint *)(in_ECX + 0x48) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(in_ECX + 0x48);
  }
  _Memory = *(void **)(*(int *)(*(int *)(in_ECX + 0x44) + uVar2 * 4) + (uVar1 + iVar3) * 4);
  if ((*(int *)(in_ECX + 0x50) != 0) &&
     (iVar3 = *(int *)(in_ECX + 0x50) + -1, *(int *)(in_ECX + 0x50) = iVar3, iVar3 == 0)) {
    *(undefined4 *)(in_ECX + 0x4c) = 0;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00846660 @ 0x00846660 ====

void FUN_00846660(void)

{
  int in_ECX;
  
  FUN_008465e0();
  FUN_0046cfc0();
  if (*(void **)(in_ECX + 0x34) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x34));
  return;
}


// ==== FUN_008466a0 @ 0x008466a0 ====

void FUN_008466a0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  FUN_008465e0();
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  return;
}


// ==== FUN_008466d0 @ 0x008466d0 ====

void FUN_008466d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[5] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  return;
}


// ==== FUN_00846700 @ 0x00846700 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00846700(uint *param_1)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  int in_ECX;
  undefined4 *_Src;
  int iVar11;
  undefined4 *_Dst;
  float fVar12;
  int local_10;
  int local_c;
  int local_8;
  float local_4;
  
  uVar8 = (uint)param_1;
  _Dst = *(undefined4 **)(in_ECX + 0x34);
  if (_Dst != *(undefined4 **)(in_ECX + 0x38)) {
    _Src = _Dst + 1;
    do {
      param_1 = (uint *)*_Dst;
      if (uVar8 < *param_1) {
        _Dst = _Dst + 1;
        *param_1 = *param_1 - uVar8;
        _Src = _Src + 1;
      }
      else {
        FUN_00846af0(&param_1);
        _memmove(_Dst,_Src,(*(int *)(in_ECX + 0x38) - (int)_Src >> 2) * 4);
        *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + -4;
      }
    } while (_Dst != *(undefined4 **)(in_ECX + 0x38));
  }
  iVar1 = *(int *)(in_ECX + 0x34);
  for (iVar11 = *(int *)(in_ECX + 0x38); iVar11 != iVar1; iVar11 = iVar11 + -4) {
    piVar2 = *(int **)(iVar11 + -4);
    fVar3 = (float)*piVar2;
    if (*piVar2 < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar4 = (float)*(int *)(in_ECX + 0xc);
    if (*(int *)(in_ECX + 0xc) < 0) {
      fVar4 = fVar4 + _DAT_0099d104;
    }
    param_1 = (uint *)(fVar3 / fVar4);
    local_10 = piVar2[1];
    local_c = piVar2[2];
    local_8 = piVar2[3];
    local_4 = (float)piVar2[4] * (float)param_1;
    iVar9 = FUN_0040ead0(&local_10);
    piVar2[0xd] = iVar9;
    if (*(char *)(in_ECX + 0x10) != '\0') {
      piVar2[0xb] = (int)((float)piVar2[5] * (float)param_1);
      piVar2[0xc] = (int)((float)piVar2[6] * (float)param_1);
    }
  }
  if (DAT_00a106e0 < *(float *)(in_ECX + 8) || DAT_00a106e0 == *(float *)(in_ECX + 8)) {
    iVar1 = *(int *)(in_ECX + 0x34);
    fVar3 = *(float *)(in_ECX + 0x24);
    fVar4 = *(float *)(in_ECX + 0x28);
    fVar5 = *(float *)(in_ECX + 0x2c);
    for (iVar11 = *(int *)(in_ECX + 0x38); iVar11 != iVar1; iVar11 = iVar11 + -4) {
      iVar9 = *(int *)(iVar11 + -4);
      pfVar10 = (float *)(iVar9 + 0x1c);
      fVar12 = *(float *)(iVar9 + 0x1c) - fVar3;
      fVar7 = *(float *)(iVar9 + 0x20) - fVar4;
      fVar6 = *(float *)(iVar9 + 0x24) - fVar5;
      fVar12 = SQRT(fVar12 * fVar12 + fVar7 * fVar7 + fVar6 * fVar6);
      if (*(float *)(in_ECX + 8) < fVar12) {
        fVar12 = *(float *)(in_ECX + 8) / fVar12;
        *pfVar10 = (*pfVar10 - fVar3) * fVar12 + fVar3;
        *(float *)(iVar9 + 0x20) = (*(float *)(iVar9 + 0x20) - fVar4) * fVar12 + fVar4;
        *(float *)(iVar9 + 0x24) = (*(float *)(iVar9 + 0x24) - fVar5) * fVar12 + fVar5;
      }
      fVar3 = *pfVar10;
      fVar4 = *(float *)(iVar9 + 0x20);
      fVar5 = *(float *)(iVar9 + 0x24);
    }
  }
  return;
}


// ==== FUN_00846940 @ 0x00846940 ====

void FUN_00846940(void *param_1,float *param_2)

{
  float *pfVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint *in_ECX;
  int iVar6;
  float *pfVar7;
  
  pfVar1 = (float *)(in_ECX + 9);
  *pfVar1 = *param_2;
  in_ECX[10] = (uint)param_2[1];
  in_ECX[0xb] = (uint)param_2[2];
  in_ECX[5] = in_ECX[5] + (int)param_1;
  if (in_ECX[1] <= in_ECX[5]) {
    if (in_ECX[0x14] == 0) {
      if (in_ECX[0xd] == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (int)(in_ECX[0xe] - in_ECX[0xd]) >> 2;
      }
      if (*in_ECX <= uVar4) {
        return;
      }
      param_1 = operator_new(0x98);
      uVar3 = DAT_0099d080;
      if (param_1 == (void *)0x0) {
        param_1 = (void *)0x0;
      }
      else {
        *(undefined4 *)((int)param_1 + 0x2c) = DAT_0099d080;
        *(undefined4 *)((int)param_1 + 0x30) = uVar3;
        *(undefined4 *)((int)param_1 + 0x34) = 0xffffffff;
        *(undefined4 *)((int)param_1 + 0x38) = 0;
        *(undefined1 *)((int)param_1 + 0x44) = 0;
        *(undefined1 *)((int)param_1 + 0x45) = 0;
      }
      FUN_00846af0(&param_1);
    }
    if (((float)in_ECX[2] <= DAT_00a106e0) ||
       ((float)in_ECX[2] <=
        SQRT((*pfVar1 - (float)in_ECX[6]) * (*pfVar1 - (float)in_ECX[6]) +
             ((float)in_ECX[10] - (float)in_ECX[7]) * ((float)in_ECX[10] - (float)in_ECX[7]) +
             ((float)in_ECX[0xb] - (float)in_ECX[8]) * ((float)in_ECX[0xb] - (float)in_ECX[8])))) {
      uVar4 = (in_ECX[0x14] + in_ECX[0x13]) - 1;
      uVar5 = uVar4 >> 2;
      iVar6 = uVar5 * -4;
      if (in_ECX[0x12] <= uVar5) {
        uVar5 = uVar5 - in_ECX[0x12];
      }
      puVar2 = *(uint **)(*(int *)(in_ECX[0x11] + uVar5 * 4) + (uVar4 + iVar6) * 4);
      if ((in_ECX[0x14] != 0) && (uVar4 = in_ECX[0x14] - 1, in_ECX[0x14] = uVar4, uVar4 == 0)) {
        in_ECX[0x13] = 0;
      }
      *puVar2 = in_ECX[3];
      pfVar7 = (float *)(puVar2 + 7);
      for (iVar6 = 0x1f; iVar6 != 0; iVar6 = iVar6 + -1) {
        *pfVar7 = *param_2;
        param_2 = param_2 + 1;
        pfVar7 = pfVar7 + 1;
      }
      in_ECX[6] = (uint)*pfVar1;
      in_ECX[7] = in_ECX[10];
      in_ECX[8] = in_ECX[0xb];
      in_ECX[5] = 0;
    }
  }
  return;
}


// ==== FUN_00846aa0 @ 0x00846aa0 ====

void FUN_00846aa0(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = *(int **)(in_ECX + 0x34);
  if ((piVar2 != (int *)0x0) && (*(int *)(in_ECX + 0x38) - (int)piVar2 >> 2 != 0)) {
    piVar1 = *(int **)(in_ECX + 0x38);
    for (; piVar2 != piVar1; piVar2 = piVar2 + 1) {
      FUN_005aaba0(*piVar2 + 0x1c);
    }
  }
  return;
}


// ==== FUN_00846af0 @ 0x00846af0 ====

void FUN_00846af0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  
  if (((*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10) & 3U) == 0) &&
     (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 4U >> 2)) {
    FUN_006ea220(1);
  }
  uVar3 = *(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x10);
  uVar4 = uVar3 >> 2;
  if (*(uint *)(in_ECX + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)(in_ECX + 8);
  }
  if (*(int *)(*(int *)(in_ECX + 4) + uVar4 * 4) == 0) {
    pvVar2 = operator_new(0x10);
    *(void **)(*(int *)(in_ECX + 4) + uVar4 * 4) = pvVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + uVar4 * 4) + (uVar3 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  return;
}


// ==== FUN_00846bd0 @ 0x00846bd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00846bd0(int *param_1,undefined4 *param_2)

{
  uint in_EAX;
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *in_ECX;
  float10 fVar7;
  float fVar8;
  float fVar9;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (param_1 == (int *)0x0) {
    return in_EAX & 0xffffff00;
  }
  *in_ECX = param_1;
  in_ECX[1] = *param_2;
  in_ECX[2] = param_2[1];
  in_ECX[3] = param_2[2];
  in_ECX[5] = *param_2;
  in_ECX[6] = param_2[1];
  in_ECX[7] = param_2[2];
  iVar1 = (**(code **)(*param_1 + 0x10))();
  uVar2 = (**(code **)(*(int *)*in_ECX + 0xc))();
  uVar3 = uVar2;
  if (iVar1 == 0) {
switchD_00846c3e_default:
    return uVar3 & 0xffffff00;
  }
  uVar3 = *(int *)(uVar2 + 4) - 1;
  switch(uVar3) {
  case 0:
  case 1:
  case 4:
  case 5:
  case 6:
    in_ECX[4] = DAT_00b5d97c;
    break;
  case 2:
    in_ECX[4] = DAT_00b5d978;
    break;
  case 3:
    in_ECX[4] = DAT_00b5d974;
    break;
  default:
    goto switchD_00846c3e_default;
  }
  in_ECX[0x14] = *(undefined4 *)(iVar1 + 0xc);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*in_ECX + 8))();
  fStack_1c = DAT_0099d080;
  in_ECX[0x13] = *puVar4;
  fStack_18 = fStack_1c;
  fStack_14 = fStack_1c;
  if (*(float *)(uVar2 + 0x14) <= _DAT_00a1076c) goto LAB_00846d1b;
  fVar7 = (float10)FUN_0040d0a0(0.0 - *(float *)(uVar2 + 0x14),*(undefined4 *)(uVar2 + 0x14));
  fVar9 = (float)fVar7 + DAT_0099d080;
  if (DAT_0099d080 <= fVar9) {
    fVar8 = DAT_0099d080;
LAB_00846ce3:
    fStack_1c = fVar8;
  }
  else {
    fStack_1c = 0.0;
    fVar8 = fVar9;
    if (0.0 <= fVar9) goto LAB_00846ce3;
  }
  if (DAT_0099d080 <= fVar9) {
    fVar8 = DAT_0099d080;
LAB_00846cfc:
    fStack_18 = fVar8;
  }
  else {
    fStack_18 = 0.0;
    fVar8 = fVar9;
    if (0.0 <= fVar9) goto LAB_00846cfc;
  }
  fVar8 = DAT_0099d080;
  if ((DAT_0099d080 <= fVar9) || (fStack_14 = 0.0, fVar8 = fVar9, 0.0 <= fVar9)) {
    fStack_14 = fVar8;
  }
LAB_00846d1b:
  if ((*(float *)(uVar2 + 0x20) <= _DAT_00a1076c) ||
     (*(float *)(uVar2 + 0x24) < *(float *)(uVar2 + 0x20))) {
    iVar5 = (**(code **)(*(int *)*in_ECX + 8))();
    param_1 = *(int **)(iVar5 + 4);
  }
  else {
    fVar7 = (float10)FUN_0040d0a0(*(undefined4 *)(uVar2 + 0x20),*(undefined4 *)(uVar2 + 0x24));
    param_1 = (int *)(float)fVar7;
  }
  fStack_10 = fStack_1c;
  fStack_c = fStack_18;
  fStack_8 = fStack_14;
  fStack_4 = DAT_0099d080;
  uVar6 = FUN_0040ead0(&fStack_10);
  in_ECX[0x12] = 0;
  in_ECX[0xf] = param_1;
  in_ECX[0x11] = uVar6;
  in_ECX[0x10] = param_1;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 0x15) = *(undefined1 *)(iVar1 + 0x4c);
  iVar1 = (**(code **)(*(int *)*in_ECX + 0xc))();
  *(undefined1 *)((int)in_ECX + 0x55) = *(undefined1 *)(iVar1 + 0x10);
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x17] = 0;
  fVar9 = DAT_0099d080;
  in_ECX[0x25] = DAT_0099d080;
  in_ECX[0x20] = fVar9;
  in_ECX[0x1b] = fVar9;
  in_ECX[0x16] = fVar9;
  in_ECX[0x26] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x29] = 0;
  return 1;
}


// ==== FUN_00846ef0 @ 0x00846ef0 ====

void FUN_00846ef0(undefined4 param_1)

{
  int *_Memory;
  int *in_ECX;
  int *piVar1;
  
  piVar1 = *(int **)in_ECX[0x2b];
  if (piVar1 != (int *)in_ECX[0x2b]) {
    do {
      _Memory = (int *)piVar1[2];
      if (_Memory[10] == *_Memory) {
        _free(_Memory);
        return;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)in_ECX[0x2b]);
  }
  if ((*in_ECX != 0) && (in_ECX[4] != 0)) {
    (**(code **)(*(int *)in_ECX[4] + 8))(param_1);
  }
  return;
}


// ==== FUN_00846f70 @ 0x00846f70 ====

void FUN_00846f70(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb0) == 0) {
    return;
  }
  piVar1 = (int *)**(int **)(in_ECX + 0xac);
  if (piVar1 == *(int **)(in_ECX + 0xac)) {
    FUN_00510b80();
    return;
  }
  _free((void *)piVar1[2]);
  return;
}


// ==== FUN_00846fb0 @ 0x00846fb0 ====

void FUN_00846fb0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xf] = uVar1;
  in_ECX[0x10] = uVar1;
  in_ECX[0x11] = 0xffffffff;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0x15) = 0;
  *(undefined1 *)((int)in_ECX + 0x55) = 0;
  uVar1 = FUN_00847260();
  in_ECX[0x2b] = uVar1;
  in_ECX[0x2c] = 0;
  return;
}


// ==== FUN_00847030 @ 0x00847030 ====

void FUN_00847030(void)

{
  undefined4 *in_ECX;
  
  FUN_00846f70();
  *in_ECX = 0;
  return;
}


// ==== FUN_00847040 @ 0x00847040 ====

void FUN_00847040(void)

{
  undefined4 *in_ECX;
  
  FUN_00846f70();
  *in_ECX = 0;
  FUN_008984a0();
  return;
}


// ==== FUN_00847060 @ 0x00847060 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00847060(undefined4 param_1,undefined4 param_2,int *param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  int *in_ECX;
  float10 fVar5;
  int iStack_18;
  int iStack_14;
  int iStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  if ((*in_ECX != 0) && (param_3 != (int *)0x0)) {
    iVar3 = (**(code **)(*param_3 + 4))();
    if (*(int *)(iVar3 + 0x50) != 0) {
      fVar5 = (float10)FUN_005aa2a0(param_1,param_2);
      FUN_0040d600(&iStack_18,(float)(fVar5 * (float10)_DAT_00b50ae4));
      iStack_c = iStack_18;
      uStack_8 = 0;
      in_ECX[8] = iStack_18;
      iStack_4 = iStack_14;
      in_ECX[9] = 0;
      in_ECX[10] = iStack_14;
    }
    if (*(int *)(iVar3 + 0x30) == 0) {
      in_ECX[5] = in_ECX[1];
      in_ECX[6] = in_ECX[2];
      in_ECX[7] = in_ECX[3];
      return;
    }
    pfVar4 = (float *)FUN_005aa3a0(&iStack_18,param_1,param_2);
    fVar1 = pfVar4[1];
    fVar2 = pfVar4[2];
    in_ECX[5] = (int)((float)in_ECX[1] + *pfVar4);
    in_ECX[6] = (int)(fVar1 + (float)in_ECX[2]);
    in_ECX[7] = (int)(fVar2 + (float)in_ECX[3]);
  }
  return;
}


// ==== FUN_00847180 @ 0x00847180 ====

void FUN_00847180(int param_1)

{
  void *pvVar1;
  int iVar2;
  int *in_ECX;
  undefined1 auStack_10 [4];
  
  if (((*in_ECX != 0) && (in_ECX[4] != 0)) && (param_1 != 0)) {
    pvVar1 = operator_new(0xc0);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00848860(in_ECX + 0xb);
    }
    *(int *)(iVar2 + 0x24) = param_1;
    (**(code **)(*(int *)in_ECX[4] + 4))();
    FUN_00847370(auStack_10 + 0xc);
  }
  return;
}


// ==== FUN_008471e0 @ 0x008471e0 ====

void FUN_008471e0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb0) != 0) {
    puVar1 = *(undefined4 **)(in_ECX + 0xac);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      iVar3 = puVar2[2];
      if (*(int *)(iVar3 + 0x50) != 0) {
        thunk_FUN_0079e5a0(iVar3 + 0x44,iVar3 + 0x38,param_2);
        iVar4 = param_3[2];
        iVar5 = *param_3;
        *(undefined4 *)(iVar3 + 0xb0) = 0;
        *(int *)(iVar3 + 0xb4) = iVar4 - iVar5;
        iVar4 = param_3[3];
        iVar5 = param_3[1];
        *(undefined4 *)(iVar3 + 0xb8) = 0;
        *(int *)(iVar3 + 0xbc) = iVar4 - iVar5;
        FUN_005aaba0(iVar3 + 0x44);
      }
    }
  }
  return;
}


// ==== FUN_00847260 @ 0x00847260 ====

void FUN_00847260(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a040;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0xc);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@008472cf @ 0x008472cf ====

void Catch_008472cf(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008472f0 @ 0x008472f0 ====

void FUN_008472f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a050;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00847359 @ 0x00847359 ====

void Catch_00847359(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00847370 @ 0x00847370 ====

void FUN_00847370(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  iVar2 = FUN_008472f0(iVar1,*(undefined4 *)(iVar1 + 4),param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_008473b0 @ 0x008473b0 ====

undefined4 FUN_008473b0(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x2c) == 0) ||
     (*(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x2c) >> 2 == 0)) {
    return 0;
  }
  *(undefined4 **)(in_ECX + 0x24) = *(undefined4 **)(in_ECX + 0x2c);
  return **(undefined4 **)(in_ECX + 0x2c);
}


// ==== FUN_008473e0 @ 0x008473e0 ====

undefined4 FUN_008473e0(void)

{
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x2c) != 0) &&
      (*(int *)(in_ECX + 0x30) - *(int *)(in_ECX + 0x2c) >> 2 != 0)) &&
     (*(int *)(in_ECX + 0x24) != *(int *)(in_ECX + 0x30))) {
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 4;
    if (*(undefined4 **)(in_ECX + 0x24) != *(undefined4 **)(in_ECX + 0x30)) {
      return **(undefined4 **)(in_ECX + 0x24);
    }
  }
  return 0;
}


// ==== FUN_00847420 @ 0x00847420 ====

void FUN_00847420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a107b8;
  FUN_004eb890(in_ECX + 10);
  if ((void *)in_ECX[0xb] != (void *)0x0) {
    _free((void *)in_ECX[0xb]);
    return;
  }
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00847480 @ 0x00847480 ====

void FUN_00847480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a107b8;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[9] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[9] = 0;
  return;
}


// ==== FUN_008474b0 @ 0x008474b0 ====

void FUN_008474b0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 *puVar6;
  
  iVar2 = (int)param_2;
  *(undefined4 *)(in_ECX + 4) = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  puVar6 = *(undefined4 **)(iVar2 + 0x20);
  param_2 = *(undefined4 **)(iVar2 + 0x24);
  if (puVar6 == param_2) {
    *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x30);
    return;
  }
  do {
    uVar1 = *puVar6;
    pvVar4 = operator_new(0xbc);
    if (pvVar4 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_008489d0();
    }
    param_1 = uVar5;
    FUN_008488d0(uVar1);
    iVar2 = *(int *)(in_ECX + 0x2c);
    if ((iVar2 == 0) ||
       ((uint)(*(int *)(in_ECX + 0x34) - iVar2 >> 2) <= (uint)(*(int *)(in_ECX + 0x30) - iVar2 >> 2)
       )) {
      FUN_008475b0(*(undefined4 *)(in_ECX + 0x30),1,&param_1);
    }
    else {
      puVar3 = *(undefined4 **)(in_ECX + 0x30);
      *puVar3 = uVar5;
      *(undefined4 **)(in_ECX + 0x30) = puVar3 + 1;
    }
    puVar6 = puVar6 + 1;
  } while (puVar6 != param_2);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(in_ECX + 0x30);
  return;
}


// ==== FUN_00847590 @ 0x00847590 ====

void FUN_00847590(byte param_1)

{
  void *in_ECX;
  
  FUN_00847420();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008475b0 @ 0x008475b0 ====

void FUN_008475b0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a060;
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


// ==== Catch@00847711 @ 0x00847711 ====

void Catch_00847711(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00847800 @ 0x00847800 ====

void FUN_00847800(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10800;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00847820 @ 0x00847820 ====

void FUN_00847820(int param_1)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 4) != '\0') &&
     (*(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1, 499 < *(uint *)(in_ECX + 8))) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(bool *)(in_ECX + 5) = *(char *)(in_ECX + 5) == '\0';
  }
  return;
}


// ==== FUN_008478a0 @ 0x008478a0 ====

void FUN_008478a0(int *param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_10 [16];
  
  if (*(int *)(in_ECX + 0x34) == 0) {
    iVar2 = (**(code **)(*param_1 + 0x100))();
    iVar1 = *(int *)(in_ECX + 0xc);
    *(int *)(in_ECX + 0x34) = iVar2;
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined4 *)(iVar2 + 0x20) = 0;
    *(int *)(iVar2 + 0x14) = iVar1 + 2;
    iVar1 = *(int *)(in_ECX + 0x34);
    *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x14) + *(int *)(in_ECX + 0x14);
    *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x18) + *(int *)(in_ECX + 0x18);
    iVar1 = *(int *)(in_ECX + 0x34);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(in_ECX + 0x30);
    *(int *)(*(int *)(in_ECX + 0x34) + 0xc) = *(int *)(in_ECX + 0x20) + 1;
    *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x74) = 0;
    *(undefined1 *)(*(int *)(in_ECX + 0x34) + 1) = 0;
    **(undefined1 **)(in_ECX + 0x34) = 1;
    uVar4 = *(undefined4 *)(in_ECX + 0x1c);
    if (4 < *(int *)(in_ECX + 0x14)) {
      pfVar3 = (float *)FUN_0040ec60(auStack_10,uVar4);
      uVar4 = 0x40ffffff;
      if (pfVar3[2] + pfVar3[1] + *pfVar3 <= DAT_009a000c) {
        uVar4 = 0x40000000;
      }
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x10) = uVar4;
    *(undefined1 *)(*(int *)(in_ECX + 0x34) + 2) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x78) = 0;
  }
  if ((*(char *)(in_ECX + 4) != '\0') && (*(char *)(in_ECX + 5) != '\0')) {
    (**(code **)(*param_1 + 0x74))(*(undefined4 *)(in_ECX + 0x34));
  }
  return;
}


// ==== FUN_008479a0 @ 0x008479a0 ====

void FUN_008479a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10818;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  in_ECX[0xd] = 0;
  return;
}


// ==== FUN_008479c0 @ 0x008479c0 ====

void FUN_008479c0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_10 [16];
  
  *(undefined4 *)(in_ECX + 0xc) = *param_1;
  *(undefined4 *)(in_ECX + 0x10) = param_1[1];
  *(undefined4 *)(in_ECX + 0x14) = param_1[2];
  *(undefined4 *)(in_ECX + 0x18) = param_1[3];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[4];
  *(undefined4 *)(in_ECX + 0x20) = param_1[5];
  *(undefined4 *)(in_ECX + 0x24) = param_1[6];
  *(undefined4 *)(in_ECX + 0x28) = param_1[7];
  *(undefined4 *)(in_ECX + 0x2c) = param_1[8];
  *(undefined4 *)(in_ECX + 0x30) = param_1[9];
  iVar1 = *(int *)(in_ECX + 0x34);
  if (iVar1 != 0) {
    iVar2 = *(int *)(in_ECX + 0xc);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(int *)(iVar1 + 0x14) = iVar2 + 2;
    iVar1 = *(int *)(in_ECX + 0x34);
    *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x14) + *(int *)(in_ECX + 0x14);
    *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x18) + *(int *)(in_ECX + 0x18);
    *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0xc) = *(undefined4 *)(in_ECX + 0x20);
    iVar1 = *(int *)(in_ECX + 0x34);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(in_ECX + 0x30);
    uVar4 = *(undefined4 *)(in_ECX + 0x1c);
    if (4 < *(int *)(in_ECX + 0x14)) {
      pfVar3 = (float *)FUN_0040ec60(local_10,uVar4);
      uVar4 = 0x40ffffff;
      if (pfVar3[2] + pfVar3[1] + *pfVar3 <= DAT_009a000c) {
        uVar4 = 0x40000000;
      }
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x10) = uVar4;
  }
  *(undefined1 *)(in_ECX + 5) = 1;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00847ad0 @ 0x00847ad0 ====

void FUN_00847ad0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[0xd];
  *in_ECX = &PTR_FUN_00a10818;
  if (_Memory == (void *)0x0) {
    in_ECX[0xd] = 0;
    *in_ECX = &PTR_FUN_00a10800;
    return;
  }
  if (*(void **)((int)_Memory + 0x68) != (void *)0x0) {
    _free(*(void **)((int)_Memory + 0x68));
    return;
  }
  *(undefined4 *)((int)_Memory + 0x68) = 0;
  *(undefined4 *)((int)_Memory + 0x6c) = 0;
  *(undefined4 *)((int)_Memory + 0x70) = 0;
  if (*(void **)((int)_Memory + 0x58) == (void *)0x0) {
    *(undefined4 *)((int)_Memory + 0x58) = 0;
    *(undefined4 *)((int)_Memory + 0x5c) = 0;
    *(undefined4 *)((int)_Memory + 0x60) = 0;
    _free(_Memory);
    return;
  }
  _free(*(void **)((int)_Memory + 0x58));
  return;
}


// ==== FUN_00847b30 @ 0x00847b30 ====

void FUN_00847b30(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_00847b40 @ 0x00847b40 ====

void FUN_00847b40(byte param_1)

{
  void *in_ECX;
  
  FUN_00847ad0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00847b60 @ 0x00847b60 ====

void FUN_00847b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10870;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00847b80 @ 0x00847b80 ====

void FUN_00847b80(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00847ba0 @ 0x00847ba0 ====

void FUN_00847ba0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  *(undefined1 *)(in_ECX + 8) = 0;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0xc))();
  }
  return;
}


// ==== FUN_00847bd0 @ 0x00847bd0 ====

void FUN_00847bd0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    puVar1 = *(undefined4 **)(in_ECX + 0x30);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      (**(code **)(*(int *)puVar2[3] + 0x14))(param_1);
    }
  }
  return;
}


// ==== FUN_00847c30 @ 0x00847c30 ====

void FUN_00847c30(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  char cVar7;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + param_1;
    puVar1 = *(undefined4 **)(in_ECX + 0x30);
    bVar6 = true;
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      piVar3 = (int *)puVar2[3];
      (**(code **)(*piVar3 + 0x10))(param_1);
      cVar7 = (**(code **)(*piVar3 + 0x18))();
      if (cVar7 == '\0') {
        bVar6 = false;
      }
    }
    uVar4 = *(uint *)(in_ECX + 0x1c);
    uVar5 = *(uint *)(in_ECX + 0x18);
    if (uVar5 < uVar4) {
      *(char *)(in_ECX + 0x20) = *(char *)(in_ECX + 0x20) + (char)(uVar4 / uVar5);
      *(uint *)(in_ECX + 0x1c) = uVar4 % uVar5;
      if ((*(byte *)(in_ECX + 0x14) == 0) || (*(byte *)(in_ECX + 0x20) < *(byte *)(in_ECX + 0x14)))
      {
        puVar1 = *(undefined4 **)(in_ECX + 0x30);
        for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
          (**(code **)(*(int *)puVar2[3] + 8))(uVar4 % uVar5);
        }
      }
    }
    if (((*(byte *)(in_ECX + 0x14) != 0) && (*(byte *)(in_ECX + 0x14) <= *(byte *)(in_ECX + 0x20)))
       && (bVar6)) {
      *(undefined1 *)(in_ECX + 8) = 0;
    }
  }
  return;
}


// ==== FUN_00847ce0 @ 0x00847ce0 ====

void FUN_00847ce0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_00a10888;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 10) = local_5;
  uVar1 = FUN_00847fd0();
  in_ECX[0xc] = uVar1;
  in_ECX[0xd] = 0;
  local_4 = in_ECX[0xc];
  FUN_00848400(9,&local_4);
  in_ECX[0x12] = 1;
  in_ECX[0x13] = 1;
  return;
}


// ==== FUN_00847d40 @ 0x00847d40 ====

undefined4 FUN_00847d40(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint unaff_ESI;
  uint uVar4;
  undefined1 auStack_1a [2];
  undefined1 auStack_18 [20];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5d970 + 4))(param_1);
  *(int **)(in_ECX + 0x24) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uVar4 = 0;
  iVar2 = (**(code **)(*piVar1 + 8))();
  if (iVar2 != 0) {
    do {
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 0xc))(uVar4);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*DAT_00b5d96c + 4))(iVar2);
        if (iVar2 != 0) {
          iVar2 = (**(code **)(*DAT_00b5d940 + 4))(iVar2,*(undefined4 *)(in_ECX + 4));
          if (iVar2 != 0) {
            FUN_00848570(auStack_18,auStack_1a + -6);
          }
        }
      }
      uVar4 = unaff_ESI + 1;
      uVar3 = (**(code **)(**(int **)(in_ECX + 0x24) + 8))();
      unaff_ESI = uVar4;
    } while (uVar4 < uVar3);
  }
  return 1;
}


// ==== FUN_00847e00 @ 0x00847e00 ====

void FUN_00847e00(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x30);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*DAT_00b5d940 + 8))(puVar2[3]);
  }
  FUN_008487a0();
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00847e40 @ 0x00847e40 ====

void FUN_00847e40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10888;
  FUN_00847e00();
  if ((void *)in_ECX[0xf] == (void *)0x0) {
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    FUN_008984a0();
    *in_ECX = &PTR_FUN_00a10870;
    return;
  }
  _free((void *)in_ECX[0xf]);
  return;
}


// ==== FUN_00847e90 @ 0x00847e90 ====

void FUN_00847e90(int *param_1,uint param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  undefined1 uStack00000000;
  int iVar5;
  
  if (*(int *)(in_ECX + 0x24) == 0) {
LAB_00847eb6:
    iVar5 = *param_1;
  }
  else {
    if (*(int *)(in_ECX + 0xc) == *param_1) {
      if (*(int *)(in_ECX + 0x24) != 0) goto LAB_00847ec8;
      goto LAB_00847eb6;
    }
    FUN_00847e00();
    iVar5 = *param_1;
  }
  cVar1 = FUN_00847d40(iVar5);
  if (cVar1 == '\0') {
    return;
  }
LAB_00847ec8:
  *(int *)(in_ECX + 0xc) = *param_1;
  *(int *)(in_ECX + 0x10) = param_1[1];
  *(int *)(in_ECX + 0x14) = param_1[2];
  *(int *)(in_ECX + 0x18) = param_1[3];
  uVar4 = *(uint *)(in_ECX + 0x18);
  if (uVar4 == 0) {
    uVar4 = 1;
  }
  *(uint *)(in_ECX + 0x18) = uVar4;
  *(uint *)(in_ECX + 0x1c) = param_2 % uVar4;
  *(char *)(in_ECX + 0x20) = (char)(param_2 / uVar4);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x24) + 0x10))(param_1[1]);
  while (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar2 + 4))();
    FUN_00897340(&uStack00000000,uVar3);
    if (_uStack00000000 != *(int *)(in_ECX + 0x30)) {
      (**(code **)(**(int **)(_uStack00000000 + 0xc) + 4))
                (piVar2,*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c));
    }
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x24) + 0x14))();
  }
  *(undefined1 *)(in_ECX + 8) = 1;
  return;
}


// ==== FUN_00847f60 @ 0x00847f60 ====

int FUN_00847f60(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a070;
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


// ==== Catch@00847fc6 @ 0x00847fc6 ====

void Catch_00847fc6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00847fd0 @ 0x00847fd0 ====

void FUN_00847fd0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a080;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0084803f @ 0x0084803f ====

void Catch_0084803f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00848060 @ 0x00848060 ====

void * FUN_00848060(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a090;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x10);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_008335c0(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@008480cd @ 0x008480cd ====

void Catch_008480cd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008480f0 @ 0x008480f0 ====

void FUN_008480f0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a0a0;
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


// ==== Catch@00848156 @ 0x00848156 ====

void Catch_00848156(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00848160 @ 0x00848160 ====

void FUN_00848160(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00847f60(param_1,param_2,param_3);
  return;
}


// ==== FUN_00848180 @ 0x00848180 ====

int FUN_00848180(int param_1,int param_2,undefined4 param_3)

{
  FUN_008480f0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_008481b0 @ 0x008481b0 ====

void FUN_008481b0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a0b0;
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
      uVar5 = FUN_00848160(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00848180(uVar5,param_2,&local_18);
      FUN_00848160(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_00847f60(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00848180(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_00847f60(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00848311 @ 0x00848311 ====

void Catch_00848311(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00848400 @ 0x00848400 ====

void FUN_00848400(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a0c0;
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
    uVar2 = FUN_00848180(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00848494 @ 0x00848494 ====

void Catch_00848494(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_008484b0 @ 0x008484b0 ====

void FUN_008484b0(uint param_1,undefined1 param_2)

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
    FUN_008481b0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_00848520 @ 0x00848520 ====

/* WARNING: Removing unreachable block (ram,0x0084853b) */
/* WARNING: Removing unreachable block (ram,0x00848540) */
/* WARNING: Removing unreachable block (ram,0x0084854e) */

void FUN_00848520(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_008481b0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_00848570 @ 0x00848570 ====

/* WARNING: Removing unreachable block (ram,0x00848658) */

void FUN_00848570(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar6 = *(uint *)(in_ECX + 0x24);
  if (uVar6 <= *(uint *)(in_ECX + 0xc) >> 2) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    if (uVar6 < iVar3 - 1U) {
      if (*(uint *)(in_ECX + 0x20) < uVar6) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) * 2 + 1;
      }
    }
    else {
      if (*(int *)(in_ECX + 0x14) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
      }
      *(int *)(in_ECX + 0x20) = iVar3 * 2 + -3;
      FUN_008484b0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
    }
    uVar6 = (*(int *)(in_ECX + 0x24) - (*(uint *)(in_ECX + 0x20) >> 1)) - 1;
    puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4);
    if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar6 * 4 + 4)) {
      do {
        iVar3 = uVar6 * 4;
        if (((puVar7[2] ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20)) == uVar6) {
          puVar8 = (undefined4 *)*puVar7;
        }
        else {
          puVar8 = (undefined4 *)*puVar7;
          if (puVar8 != *(undefined4 **)(in_ECX + 8)) {
            puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            uVar4 = uVar6;
            while ((puVar7 == puVar1 &&
                   (*(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3) = puVar8, uVar4 != 0))) {
              uVar4 = uVar4 - 1;
              iVar3 = uVar4 * 4;
              puVar1 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
            }
            iVar3 = *(int *)(in_ECX + 8);
            *(undefined4 **)puVar7[1] = puVar8;
            *(int *)puVar8[1] = iVar3;
            **(undefined4 **)(iVar3 + 4) = puVar7;
            uVar2 = *(undefined4 *)(iVar3 + 4);
            *(undefined4 *)(iVar3 + 4) = puVar8[1];
            puVar8[1] = puVar7[1];
            puVar7[1] = uVar2;
            puVar7 = *(undefined4 **)(*(int *)(in_ECX + 8) + 4);
            *(int *)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x24) * 4) =
                 *(int *)(in_ECX + 8);
          }
          for (uVar4 = *(uint *)(in_ECX + 0x24);
              (uVar6 < uVar4 &&
              (*(int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4) == *(int *)(in_ECX + 8)));
              uVar4 = uVar4 - 1) {
            *(undefined4 **)(*(int *)(in_ECX + 0x14) + uVar4 * 4) = puVar7;
          }
          if (puVar8 == *(undefined4 **)(in_ECX + 8)) break;
        }
        puVar7 = puVar8;
      } while (puVar8 != *(undefined4 **)(uVar6 * 4 + 4 + *(int *)(in_ECX + 0x14)));
    }
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
  }
  uVar6 = *param_2;
  uVar4 = (uVar6 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = uVar4 * 4;
  puVar7 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + 4 + iVar3);
  if (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3)) {
    do {
      puVar7 = (undefined4 *)puVar7[1];
      if ((uint)puVar7[2] <= uVar6) {
        if (uVar6 <= (uint)puVar7[2]) {
          *param_1 = (int)puVar7;
          *(undefined1 *)(param_1 + 1) = 0;
          return;
        }
        puVar7 = (undefined4 *)*puVar7;
        break;
      }
    } while (puVar7 != *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3));
  }
  iVar5 = FUN_00848060(puVar7,puVar7[1],param_2);
  FUN_00833ae0(1);
  puVar7[1] = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  iVar5 = puVar7[1];
  puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  while ((puVar7 == puVar8 && (*(int *)(*(int *)(in_ECX + 0x14) + iVar3) = iVar5, uVar4 != 0))) {
    uVar4 = uVar4 - 1;
    iVar3 = uVar4 * 4;
    puVar8 = *(undefined4 **)(*(int *)(in_ECX + 0x14) + iVar3);
  }
  *param_1 = iVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_008487a0 @ 0x008487a0 ====

void FUN_008487a0(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  undefined4 local_4;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (_Memory == *(void **)(in_ECX + 8)) {
    local_4 = *(undefined4 *)(in_ECX + 8);
    FUN_00848520(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00848800 @ 0x00848800 ====

void FUN_00848800(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10888;
  FUN_00847e00();
  if ((void *)in_ECX[0xf] != (void *)0x0) {
    _free((void *)in_ECX[0xf]);
    return;
  }
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  FUN_008984a0();
  *in_ECX = &PTR_FUN_00a10870;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00848860 @ 0x00848860 ====

void FUN_00848860(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(in_ECX + 0x24) = 0;
  puVar2 = (undefined4 *)(in_ECX + 0x44);
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_00848880 @ 0x00848880 ====

void FUN_00848880(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10920;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008488a0 @ 0x008488a0 ====

int FUN_008488a0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_008488b0 @ 0x008488b0 ====

void FUN_008488b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1092c;
  FUN_00848c50();
  *in_ECX = &PTR_FUN_00a10920;
  return;
}


// ==== FUN_008488d0 @ 0x008488d0 ====

void FUN_008488d0(undefined1 *param_1)

{
  undefined1 *puVar1;
  int in_ECX;
  
  puVar1 = param_1;
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined1 *)(in_ECX + 8) = *param_1;
  *(undefined1 *)(in_ECX + 9) = param_1[0x32];
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x2c);
  FUN_00848d40(param_1 + 0xa8);
  if ((undefined1 *)(in_ECX + 0x4c) != puVar1 + 0x38) {
    FUN_004b9680(&param_1,**(undefined4 **)(in_ECX + 0x50),*(undefined4 **)(in_ECX + 0x50));
    FUN_00848bd0(puVar1 + 0x38);
  }
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(puVar1 + 0x44);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(puVar1 + 0x48);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(puVar1 + 0x4c);
  FUN_00848d40(puVar1 + 0x68);
  FUN_00848d40(puVar1 + 0x88);
  if ((undefined1 *)(in_ECX + 0xa4) != puVar1 + 0x50) {
    FUN_004b9680(&param_1,**(undefined4 **)(in_ECX + 0xa8),*(undefined4 **)(in_ECX + 0xa8));
    FUN_00848bd0(puVar1 + 0x50);
  }
  *(undefined4 *)(in_ECX + 0xb0) = *(undefined4 *)(puVar1 + 0x5c);
  *(undefined4 *)(in_ECX + 0xb4) = *(undefined4 *)(puVar1 + 0x60);
  *(undefined4 *)(in_ECX + 0xb8) = *(undefined4 *)(puVar1 + 100);
  return;
}


// ==== FUN_008489d0 @ 0x008489d0 ====

void FUN_008489d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1092c;
  FUN_00848dc0();
  return;
}


// ==== FUN_008489f0 @ 0x008489f0 ====

undefined4 * FUN_008489f0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a0d0;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_004be2c0(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 8));
    if (*(char *)((int)local_18 + 0x21) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_008489f0(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_008489f0(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@00848a88 @ 0x00848a88 ====

void Catch_00848a88(void)

{
  int unaff_EBP;
  
  FUN_004be460(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00848aa0 @ 0x00848aa0 ====

undefined4 * FUN_00848aa0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 *local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a0e0;
  local_10 = ExceptionList;
  local_18 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    ExceptionList = &local_10;
    puVar1 = (undefined4 *)
             FUN_0058b8c0(local_18,param_2,local_18,param_1 + 3,*(undefined1 *)(param_1 + 6));
    if (*(char *)((int)local_18 + 0x19) != '\0') {
      local_18 = puVar1;
    }
    local_8 = 0;
    uVar2 = FUN_00848aa0(*param_1,puVar1);
    *puVar1 = uVar2;
    uVar2 = FUN_00848aa0(param_1[2],puVar1);
    puVar1[2] = uVar2;
  }
  ExceptionList = local_10;
  return local_18;
}


// ==== Catch@00848b38 @ 0x00848b38 ====

void Catch_00848b38(void)

{
  int unaff_EBP;
  
  FUN_004b8400(*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00848b50 @ 0x00848b50 ====

void FUN_00848b50(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar7 = FUN_008489f0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x21) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x21);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x21);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x21);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x21);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_00848bd0 @ 0x00848bd0 ====

void FUN_00848bd0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  uVar7 = FUN_00848aa0(*(undefined4 *)(*(int *)(param_1 + 4) + 4),iVar2);
  *(undefined4 *)(iVar2 + 4) = uVar7;
  piVar3 = *(int **)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  piVar4 = (int *)piVar3[1];
  if (*(char *)((int)piVar4 + 0x19) != '\0') {
    *piVar3 = (int)piVar3;
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    return;
  }
  cVar1 = *(char *)(*piVar4 + 0x19);
  piVar6 = (int *)*piVar4;
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*piVar6 + 0x19);
    piVar4 = piVar6;
    piVar6 = (int *)*piVar6;
  }
  *piVar3 = (int)piVar4;
  iVar2 = *(int *)(*(int *)(in_ECX + 4) + 4);
  iVar5 = *(int *)(iVar2 + 8);
  cVar1 = *(char *)(iVar5 + 0x19);
  while (cVar1 == '\0') {
    cVar1 = *(char *)(*(int *)(iVar5 + 8) + 0x19);
    iVar2 = iVar5;
    iVar5 = *(int *)(iVar5 + 8);
  }
  *(int *)(*(int *)(in_ECX + 4) + 8) = iVar2;
  return;
}


// ==== FUN_00848c50 @ 0x00848c50 ====

void FUN_00848c50(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_004b9680(local_4,**(undefined4 **)(in_ECX + 0xa4),*(undefined4 **)(in_ECX + 0xa4));
  _free(*(void **)(in_ECX + 0xa4));
  return;
}


// ==== FUN_00848d40 @ 0x00848d40 ====

void FUN_00848d40(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  if (in_ECX != param_1) {
    FUN_004c0f00(&param_1,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
    FUN_00848b50(iVar1);
  }
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
  return;
}


// ==== FUN_00848d90 @ 0x00848d90 ====

void FUN_00848d90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a1092c;
  FUN_00848c50();
  *in_ECX = &PTR_FUN_00a10920;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00848dc0 @ 0x00848dc0 ====

void FUN_00848dc0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004be360();
  *(int *)(in_ECX + 0x2c) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 0x2c) + 4) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  *(int *)(*(int *)(in_ECX + 0x2c) + 8) = *(int *)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 0x4c) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0x4c) + 4) = *(int *)(in_ECX + 0x4c);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(in_ECX + 0x4c);
  *(int *)(*(int *)(in_ECX + 0x4c) + 8) = *(int *)(in_ECX + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = 0;
  iVar1 = FUN_004be360();
  *(int *)(in_ECX + 100) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 100) + 4) = *(int *)(in_ECX + 100);
  *(undefined4 *)*(undefined4 *)(in_ECX + 100) = *(undefined4 *)(in_ECX + 100);
  *(int *)(*(int *)(in_ECX + 100) + 8) = *(int *)(in_ECX + 100);
  *(undefined4 *)(in_ECX + 0x68) = 0;
  iVar1 = FUN_004be360();
  *(int *)(in_ECX + 0x84) = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(int *)(*(int *)(in_ECX + 0x84) + 4) = *(int *)(in_ECX + 0x84);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(in_ECX + 0x84);
  *(int *)(*(int *)(in_ECX + 0x84) + 8) = *(int *)(in_ECX + 0x84);
  *(undefined4 *)(in_ECX + 0x88) = 0;
  iVar1 = FUN_0058b910();
  *(int *)(in_ECX + 0xa4) = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(int *)(*(int *)(in_ECX + 0xa4) + 4) = *(int *)(in_ECX + 0xa4);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(in_ECX + 0xa4);
  *(int *)(*(int *)(in_ECX + 0xa4) + 8) = *(int *)(in_ECX + 0xa4);
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  return;
}


// ==== FUN_00848e90 @ 0x00848e90 ====

void FUN_00848e90(int param_1,int param_2,int param_3)

{
  int in_ECX;
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (((*(int *)(in_ECX + 0x114) == param_1) && (param_2 == *(int *)(in_ECX + 0x118))) &&
     (param_3 == *(int *)(in_ECX + 0x11c))) {
    return;
  }
  if (*(int *)(in_ECX + 100) != 0) {
    return;
  }
  if (param_1 == 0) {
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x1b,0);
    uVar2 = 0;
    uVar1 = 0xf;
  }
  else if (param_1 == 1) {
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x1b,0);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0xf,1);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x19,5);
    uVar2 = 0xf0;
    uVar1 = 0x18;
  }
  else {
    if (param_1 != 2) goto LAB_00848fac;
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x1b,1);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0xf,1);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x19,5);
    uVar2 = 1;
    uVar1 = 0x18;
  }
  (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),uVar1,uVar2);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x13,param_2);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x14,param_3);
LAB_00848fac:
  *(int *)(in_ECX + 0x114) = param_1;
  *(int *)(in_ECX + 0x118) = param_2;
  *(int *)(in_ECX + 0x11c) = param_3;
  return;
}


// ==== FUN_00848fd0 @ 0x00848fd0 ====

void FUN_00848fd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10a18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00848ff0 @ 0x00848ff0 ====

void FUN_00848ff0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar3 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0xc4))();
  FUN_0085ff80(uVar3);
  uVar3 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0xcc))();
  FUN_0085d2f0(uVar3);
  FUN_00861a60(*(undefined4 *)(in_ECX + 0xd0),1);
  if (*(char *)(in_ECX + 0xcc) == '\0') {
    *(undefined1 *)(*(int *)(in_ECX + 0x28) + 0x7e) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  (**(code **)(**(int **)(in_ECX + 0x6c) + 4))();
  FUN_008614e0(1);
  (**(code **)(**(int **)(in_ECX + 0x60) + 4))();
  (**(code **)(**(int **)(in_ECX + 0x3c) + 4))();
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
      (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 5;
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  (**(code **)(**(int **)(in_ECX + 0x54) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x3c) + 8))();
  FUN_0085fd10();
  FUN_0085d080();
  FUN_0085a4b0();
  *(undefined1 *)(*(int *)(in_ECX + 0x28) + 0x7e) = 1;
  (**(code **)(**(int **)(in_ECX + 0x54) + 0xc))();
                    /* WARNING: Could not recover jumptable at 0x00849192. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x58) + 0xc))();
  return;
}


// ==== FUN_008491b0 @ 0x008491b0 ====

undefined4 FUN_008491b0(void)

{
  undefined4 extraout_EAX;
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  
  pvVar2 = *(void **)(in_ECX + 0x34);
  if (pvVar2 != (void *)0x0) {
    FUN_00850a80();
    _free(pvVar2);
    return extraout_EAX;
  }
  if (*(int *)(in_ECX + 0x2c) != 0) {
    FUN_00851000();
  }
  if (*(int *)(in_ECX + 0x68) != 0) {
    FUN_00861f40();
  }
  (**(code **)(*DAT_00b5af70 + 0x18))();
  uVar1 = FUN_00857950();
  if ((char)uVar1 == '\0') {
    return uVar1;
  }
  if (*(int *)(in_ECX + 0x34) == 0) {
    pvVar2 = operator_new(0x18);
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_00850ac0();
    }
    *(undefined4 *)(in_ECX + 0x34) = uVar1;
    FUN_008508d0();
  }
  if (*(int *)(in_ECX + 0x2c) != 0) {
    FUN_00851030();
  }
  if (*(int *)(in_ECX + 0x68) != 0) {
    FUN_00861d20();
  }
  (**(code **)(*DAT_00b5af70 + 0xc))();
  return 1;
}


// ==== FUN_00849260 @ 0x00849260 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00849260(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 uVar6;
  
  *(undefined1 *)(in_ECX + 0xce) = 1;
  (**(code **)(*DAT_00b5ac00 + 8))();
  (**(code **)(*DAT_00b5ac00 + 8))();
  (**(code **)(*DAT_00b5ac00 + 8))();
  uVar6 = 0;
  (**(code **)(*DAT_00b5ac00 + 0xc))(0);
  (**(code **)(*DAT_00b5ac00 + 0x10))(0);
  (**(code **)(*DAT_00b5ac00 + 0x14))(0);
  uVar5 = 0x3f800000;
  uVar4 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0x110))(0x3f800000);
  FUN_00863f70(uVar4,uVar5);
  uVar4 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0x120))();
  FUN_0085ace0(uVar4);
  uVar4 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0x124))();
  FUN_0085ff80(uVar4);
  uVar4 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0x130))();
  FUN_0085d2f0(uVar4);
  FUN_00861dd0(0x43bf0000,0x43bf0000,0x43800000);
  *(undefined1 *)(*(int *)(in_ECX + 0x68) + 8) = 1;
  FUN_00858f00();
  (**(code **)(**(int **)(in_ECX + 0x3c) + 4))();
  (**(code **)(**(int **)(in_ECX + 0x54) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x58) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x3c) + 8))();
  FUN_0085fd10();
  FUN_0085d080();
  FUN_00858f10();
  (**(code **)(**(int **)(in_ECX + 0x68) + 4))();
  (**(code **)(**(int **)(in_ECX + 0x3c) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0x54) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0x58) + 0xc))();
  (**(code **)(*DAT_00b5ac00 + 0xc))(uVar6);
  (**(code **)(*DAT_00b5ac00 + 0x10))(uVar6);
  (**(code **)(*DAT_00b5ac00 + 0x14))(uVar6);
  *(undefined1 *)(*(int *)(in_ECX + 0x68) + 8) = 0;
  iVar1 = *(int *)(in_ECX + 0x28);
  fVar2 = (float)*(int *)(iVar1 + 0x9c);
  if (*(int *)(iVar1 + 0x9c) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar3 = (float)*(int *)(iVar1 + 0xa0);
  if (*(int *)(iVar1 + 0xa0) < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  FUN_00861dd0(fVar3,fVar2,0x43800000);
  uVar4 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0x44))();
  FUN_00861d30(uVar4);
  *(undefined1 *)(in_ECX + 0xce) = 0;
  return;
}


// ==== FUN_00849460 @ 0x00849460 ====

undefined4 FUN_00849460(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  float10 fVar3;
  undefined4 uVar4;
  char cStack_11;
  float fStack_10;
  undefined1 uStack_c;
  undefined1 uStack_8;
  undefined1 uStack_4;
  
  if (*(char *)(*(int *)(in_ECX + 0x28) + 0xea) != '\0') {
    iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (1 < *(byte *)(iVar1 + 8)) {
      cStack_11 = '\0';
      fVar3 = (float10)(**(code **)(*DAT_00b5af70 + 0x10))();
      fStack_10 = (float)fVar3;
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0x68))();
      if (*piVar2 != 0) {
        (**(code **)(**(int **)(in_ECX + 0xd0) + 0x68))();
        FUN_004cd160(fStack_10,&cStack_11);
      }
      if (cStack_11 != '\0') {
        iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
        uStack_8 = *(undefined1 *)(iVar1 + 5);
        iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
        uStack_c = *(undefined1 *)(iVar1 + 2);
        iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
        uStack_4 = *(undefined1 *)(iVar1 + 3);
        uVar4 = 0;
        (**(code **)(*DAT_00b5ac00 + 0x10))(0);
        (**(code **)(*DAT_00b5ac00 + 0x18))(0);
        (**(code **)(*DAT_00b5ac00 + 0x14))();
        (**(code **)(*DAT_00b5af70 + 0x1c))(6);
        (**(code **)(*DAT_00b5ac00 + 0x10))(uVar4);
        if (DAT_009a09b8 != 0.0) {
          (**(code **)(*DAT_00b5af70 + 0x1c))(1);
          (**(code **)(*DAT_00b5af70 + 0x1c))(7);
        }
        (**(code **)(*DAT_00b5ac00 + 0x18))(uVar4);
        (**(code **)(*DAT_00b5ac00 + 0x14))(uVar4);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_008495b0 @ 0x008495b0 ====

void FUN_008495b0(void)

{
  int iVar1;
  char *pcVar2;
  byte *pbVar3;
  int in_ECX;
  
  FUN_00849460();
  iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (*(char *)(iVar1 + 2) != '\0') {
    pcVar2 = (char *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0x54))();
    if ((*pcVar2 == '\x01') || (*(char *)(in_ECX + 0xcc) != '\0')) {
      (**(code **)(*DAT_00b5af70 + 0x1c))(1);
    }
    else {
      pbVar3 = (byte *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0x54))();
      if (1 < *pbVar3) {
        (**(code **)(*DAT_00b5af70 + 0x1c))(2);
      }
    }
  }
  (**(code **)(*DAT_00b5af70 + 0x1c))(0);
  iVar1 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0x5c))();
  if (*(char *)(iVar1 + 8) == '\0') {
    (**(code **)(*DAT_00b5af70 + 0x2c))(3);
  }
  else {
    (**(code **)(*DAT_00b5af70 + 0x1c))();
  }
  iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (*(char *)(iVar1 + 6) != '\0') {
    (**(code **)(*DAT_00b5af70 + 0x1c))(5);
  }
  return;
}


// ==== FUN_00849660 @ 0x00849660 ====

void FUN_00849660(int *param_1)

{
  float fVar1;
  int iVar2;
  char cVar3;
  float *pfVar4;
  int in_ECX;
  float10 fVar5;
  float fVar6;
  float fVar7;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar4 = (float *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0x3c))();
  *(undefined1 *)(in_ECX + 0xcc) = 0;
  if (*param_1 != 0) {
    iVar2 = *(int *)(*(int *)(in_ECX + 0x78) + 4);
    fStack_14 = *(float *)(iVar2 + 0xc);
    fStack_8 = *(float *)(iVar2 + 0x10);
    fStack_10 = *(float *)(iVar2 + 0x14);
    param_1 = (int *)DAT_0099d0e8;
    fStack_c = fStack_14;
    fStack_4 = fStack_10;
    cVar3 = FUN_00592240(&fStack_14);
    if (cVar3 != '\0') {
      fStack_14 = (float)(int)ROUND(fStack_c);
      fVar5 = (float10)FUN_004a9180(fStack_14,(int)ROUND(fStack_4));
      param_1 = (int *)(float)fVar5;
    }
    fVar1 = DAT_009b18dc;
    fVar7 = DAT_0099d080;
    if (fStack_8 < (float)param_1) {
      fVar6 = DAT_009bfa74 - ((float)param_1 - fStack_8) * DAT_0099d100;
      if (fVar6 < DAT_00a10a30) {
        fVar6 = DAT_00a10a30;
      }
      fVar6 = DAT_009b18dc - fVar6;
      *(float *)(in_ECX + 0xa8) = fVar6;
      fVar7 = fVar7 / fVar6;
      fVar6 = fVar7 * DAT_0099d0dc;
      *(float *)(in_ECX + 0x9c) = fVar7 * fVar1;
      *(float *)(in_ECX + 0xa0) = fVar6;
      *(undefined4 *)(in_ECX + 0xa4) = 0xff4050a0;
      *(undefined1 *)(in_ECX + 0xcc) = 1;
      return;
    }
  }
  fVar6 = DAT_0099d080;
  fVar7 = pfVar4[5];
  fVar1 = pfVar4[4];
  *(float *)(in_ECX + 0xa8) = fVar7 - fVar1;
  fVar6 = fVar6 / (fVar7 - fVar1);
  fVar7 = pfVar4[5];
  *(float *)(in_ECX + 0xa0) = fVar6 * DAT_0099d0dc;
  *(float *)(in_ECX + 0x9c) = fVar7 * fVar6;
  *(uint *)(in_ECX + 0xa4) =
       (((int)ROUND(*pfVar4 * DAT_0099d0b8) | 0xffffff00U) << 8 |
       (int)ROUND(pfVar4[1] * DAT_0099d0b8) & 0xffU) << 8 |
       (int)ROUND(pfVar4[2] * DAT_0099d0b8) & 0xffU;
  return;
}


// ==== FUN_008498e0 @ 0x008498e0 ====

void FUN_008498e0(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  bool bVar6;
  
  if (*(char *)(*(int *)(in_ECX + 0x28) + 0x60) == '\0') {
    cVar1 = (**(code **)(*DAT_00b5a688 + 0x44))();
    if (cVar1 == '\0') {
      piVar2 = (int *)(**(code **)(*param_1 + 0x68))();
      if (*piVar2 != 0) {
        Sleep(0x32);
      }
    }
    *(int **)(in_ECX + 0xd0) = param_1;
    uVar3 = (**(code **)(*param_1 + 0x68))();
    FUN_00849660(uVar3);
    uVar3 = (**(code **)(*param_1 + 0x1c))();
    FUN_008566c0(uVar3);
    uVar3 = (**(code **)(*param_1 + 0x14))();
    FUN_00862250(uVar3);
    uVar3 = (**(code **)(*param_1 + 0x24))();
    FUN_0087a2f0(uVar3);
    uVar3 = (**(code **)(*param_1 + 0x34))();
    FUN_0087a0c0(uVar3);
    uVar3 = (**(code **)(*param_1 + 0x2c))();
    FUN_0087a3a0(uVar3);
    FUN_00879220(param_1);
    uVar3 = (**(code **)(*param_1 + 0x68))();
    FUN_00877ae0(uVar3);
    FUN_00875c40(param_1);
    FUN_00873200(param_1);
    FUN_0086f390(param_1);
    FUN_0086b4b0(param_1);
    FUN_00868340(param_1);
    uVar3 = (**(code **)(*param_1 + 0x44))();
    FUN_00861d30(uVar3);
    piVar2 = (int *)(**(code **)(*param_1 + 0x68))();
    if (*piVar2 == 0) {
      *(undefined1 *)(*(int *)(in_ECX + 0x28) + 0x75) = 0;
      *(undefined1 *)(*(int *)(in_ECX + 0x28) + 0x7d) = 0;
    }
    else {
      iVar4 = (**(code **)(*param_1 + 0x4c))();
      bVar6 = *(char *)(iVar4 + 1) != '\0';
      *(bool *)(*(int *)(in_ECX + 0x28) + 0x75) = bVar6;
      *(bool *)(*(int *)(in_ECX + 0x28) + 0x7d) = bVar6;
    }
    iVar4 = **(int **)(in_ECX + 0x6c);
    iVar5 = (**(code **)(*param_1 + 0x4c))();
    (**(code **)(iVar4 + 0x18))(*(undefined1 *)(iVar5 + 1));
    FUN_00865550(param_1);
  }
  else {
    piVar2 = (int *)(**(code **)(*param_1 + 0x68))();
    if (*piVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00849909. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      Sleep(100);
      return;
    }
  }
  return;
}


// ==== FUN_00849ac0 @ 0x00849ac0 ====

bool FUN_00849ac0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)FUN_0049b670();
  iVar3 = (**(code **)(*piVar2 + 0xc))(piVar2);
  if (iVar3 == -0x7789f798) {
    *(undefined1 *)(*(int *)(in_ECX + 0x28) + 0x60) = 1;
    return true;
  }
  if (iVar3 != -0x7789f797) {
    return iVar3 != 0;
  }
  cVar1 = FUN_008491b0();
  if (cVar1 == '\0') {
    return true;
  }
  *(undefined1 *)(*(int *)(in_ECX + 0x28) + 0x60) = 0;
  return false;
}


// ==== FUN_00849b10 @ 0x00849b10 ====

void FUN_00849b10(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 0) || (*(int *)(iVar1 + 0x118) != 5)) ||
      (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x114) = 0;
    *(undefined4 *)(iVar1 + 0x118) = 5;
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  iVar1 = *(int *)(in_ECX + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x89,0);
  if (*(char *)(in_ECX + 0xcc) == '\0') {
    (**(code **)(**(int **)(in_ECX + 0x6c) + 4))();
    FUN_008614e0(1);
  }
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x89,1);
  (**(code **)(**(int **)(in_ECX + 0x60) + 4))();
                    /* WARNING: Could not recover jumptable at 0x00849c2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x3c) + 4))();
  return;
}


// ==== FUN_00849c30 @ 0x00849c30 ====

void FUN_00849c30(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
      (*(int *)(iVar1 + 0x11c) != 6)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,6);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 5;
    *(undefined4 *)(iVar1 + 0x11c) = 6;
  }
  (**(code **)(**(int **)(in_ECX + 0x38) + 8))();
  (**(code **)(**(int **)(in_ECX + 100) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x54) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x58) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x3c) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x4c) + 8))();
  FUN_0085fd10();
  FUN_0085d080();
  FUN_0085a4b0();
  (**(code **)(**(int **)(in_ECX + 0x68) + 4))();
  (**(code **)(**(int **)(in_ECX + 0x50) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x40) + 8))();
  if (*(char *)(in_ECX + 0xcc) == '\0') {
    FUN_008614e0(0);
  }
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0xe4))(piVar2,8,3);
  (**(code **)(**(int **)(in_ECX + 0x44) + 4))();
  (**(code **)(**(int **)(in_ECX + 0x48) + 4))();
  FUN_00855850(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 100));
  return;
}


// ==== FUN_00849da0 @ 0x00849da0 ====

void FUN_00849da0(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int *piVar5;
  int in_ECX;
  
  uVar3 = (**(code **)(**(int **)(in_ECX + 0xd0) + 0xc4))();
  FUN_0085ff80(uVar3);
  iVar2 = *(int *)(in_ECX + 0x28);
  if ((((*(int *)(iVar2 + 0x114) != 0) || (*(int *)(iVar2 + 0x118) != 5)) ||
      (*(int *)(iVar2 + 0x11c) != 6)) && (*(int *)(iVar2 + 100) == 0)) {
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x1b,0);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0xf,0);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x14,6);
    *(undefined4 *)(iVar2 + 0x114) = 0;
    *(undefined4 *)(iVar2 + 0x118) = 5;
    *(undefined4 *)(iVar2 + 0x11c) = 6;
  }
  uVar1 = *(undefined1 *)(in_ECX + 0xcc);
  *(undefined1 *)(in_ECX + 0xcc) = 1;
  pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0x4c))();
  if (*pcVar4 == '\0') {
    piVar5 = (int *)FUN_0049b670();
    (**(code **)(*piVar5 + 0x10c))(piVar5,2,1,5);
  }
  (**(code **)(**(int **)(in_ECX + 0x60) + 4))();
  (**(code **)(**(int **)(in_ECX + 0x3c) + 4))();
  iVar2 = *(int *)(in_ECX + 0x28);
  if ((((*(int *)(iVar2 + 0x114) != 2) || (*(int *)(iVar2 + 0x118) != 5)) ||
      (*(int *)(iVar2 + 0x11c) != 6)) && (*(int *)(iVar2 + 100) == 0)) {
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar2 + 0x90) + 0xe4))(*(int **)(iVar2 + 0x90),0x14,6);
    *(undefined4 *)(iVar2 + 0x114) = 2;
    *(undefined4 *)(iVar2 + 0x118) = 5;
    *(undefined4 *)(iVar2 + 0x11c) = 6;
  }
  FUN_00876f30();
  (**(code **)(**(int **)(in_ECX + 0x54) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x3c) + 8))();
  FUN_0085fd10();
  *(undefined1 *)(in_ECX + 0xcc) = uVar1;
  piVar5 = (int *)FUN_0049b670();
  (**(code **)(*piVar5 + 0x10c))(piVar5,2,1,4);
  *(undefined1 *)(in_ECX + 0xcd) = 1;
  return;
}


// ==== FUN_00849fa0 @ 0x00849fa0 ====

void FUN_00849fa0(void)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  void *_Memory;
  undefined4 uVar6;
  int in_ECX;
  uint unaff_EBP;
  void *unaff_ESI;
  uint unaff_EDI;
  uint *puStack_58;
  int *piStack_54;
  int *piStack_50;
  int *piStack_4c;
  uint uStack_38;
  uint uStack_34;
  void *pvStack_30;
  uint uStack_2c;
  void *pvStack_28;
  uint auStack_24 [9];
  
  piStack_4c = (int *)0x849fb1;
  piStack_4c = (int *)FUN_0049b670();
  piStack_50 = (int *)0x849fb7;
  iVar3 = (**(code **)(*piStack_4c + 0xc))();
  if (iVar3 == -0x7789f798) {
    *(undefined1 *)(*(int *)(in_ECX + 0x28) + 0x60) = 1;
  }
  else if (iVar3 == -0x7789f797) {
    piStack_50 = (int *)0x849fdc;
    cVar2 = FUN_008491b0();
    if (cVar2 != '\0') {
      *(undefined1 *)(*(int *)(in_ECX + 0x28) + 0x60) = 0;
LAB_00849fec:
      *(undefined1 *)(in_ECX + 0xcd) = 0;
      piStack_50 = (int *)0x849ffa;
      FUN_0087ba60();
      puVar1 = *(undefined4 **)(in_ECX + 0x94);
      for (puVar5 = *(undefined4 **)(in_ECX + 0x90); puVar5 != puVar1; puVar5 = puVar5 + 1) {
        piStack_50 = (int *)0x84a016;
        (*(code *)**(undefined4 **)*puVar5)();
      }
      piStack_50 = (int *)0x84a028;
      pcVar4 = (char *)(**(code **)(**(int **)(in_ECX + 0xd0) + 100))();
      if (*pcVar4 != '\0') {
        piStack_50 = (int *)0x4;
        piStack_54 = (int *)0x84a039;
        (**(code **)(*DAT_00b5af70 + 0x1c))();
      }
      piStack_50 = (int *)0x0;
      piStack_54 = (int *)0x84a048;
      piStack_54 = (int *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0xc))();
      puStack_58 = (uint *)0x84a050;
      FUN_00863f70();
      piStack_50 = (int *)0x84a061;
      piStack_50 = (int *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0x9c))();
      piStack_54 = (int *)0x84a069;
      FUN_0085ace0();
      piStack_50 = (int *)0x84a070;
      FUN_008495b0();
      piStack_54 = *(int **)(in_ECX + 0xd0);
      piStack_50 = (int *)0x0;
      puStack_58 = (uint *)0x84a080;
      FUN_00861a60();
      piStack_50 = (int *)0x84a091;
      piStack_50 = (int *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0xcc))();
      piStack_54 = (int *)0x84a099;
      FUN_0085d2f0();
      if (*(char *)(in_ECX + 0xcd) == '\0') {
        piStack_50 = (int *)0x84a0b2;
        piStack_50 = (int *)(**(code **)(**(int **)(in_ECX + 0xd0) + 0xc4))();
        piStack_54 = (int *)0x84a0ba;
        FUN_0085ff80();
      }
      piStack_50 = (int *)0x84a0c2;
      piStack_50 = (int *)FUN_0049b670();
      piStack_54 = (int *)0x84a0cb;
      iVar3 = (**(code **)(*piStack_50 + 0xa4))();
      if (-1 < iVar3) {
        piStack_54 = (int *)0xff000000;
        puStack_58 = (uint *)0x84a0dc;
        FUN_00855ba0();
        piStack_54 = (int *)0x84a0e3;
        FUN_00849b10();
        piStack_54 = (int *)0x84a0ea;
        FUN_00849c30();
        piStack_54 = (int *)0x84a0f2;
        piStack_54 = (int *)FUN_0049b670();
        puStack_58 = (uint *)0x84a0fb;
        (**(code **)(*piStack_54 + 0xa8))();
      }
      puVar1 = *(undefined4 **)(in_ECX + 0x94);
      for (puVar5 = *(undefined4 **)(in_ECX + 0x90); puVar5 != puVar1; puVar5 = puVar5 + 1) {
        piStack_54 = (int *)0x84a117;
        (**(code **)(*(int *)*puVar5 + 0xc))();
      }
      piStack_54 = (int *)0x84a128;
      FUN_0087ba80();
      piStack_54 = (int *)0x84a130;
      FUN_00855c20();
      piStack_54 = (int *)0x84a13b;
      pcVar4 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
      if (*pcVar4 == '\0') {
        return;
      }
      piStack_54 = (int *)0x84a14a;
      puVar5 = (undefined4 *)FUN_0087baa0();
      piStack_54 = (int *)0x11;
      puStack_58 = (uint *)s__R_triangle_count_00a10974;
      pvStack_28 = (void *)0xf;
      uStack_2c = 0;
      FUN_00401740();
      piStack_54 = (int *)*puVar5;
      puStack_58 = (uint *)0xf;
      FUN_00401740(&DAT_00a10970,2);
      piStack_54 = (int *)FUN_00404230(auStack_24);
      puStack_58 = auStack_24 + -7;
      (**(code **)(*DAT_00b5a688 + 8))();
      if (0xf < auStack_24[4]) {
        _free(pvStack_28);
        return;
      }
      auStack_24[4] = 0xf;
      auStack_24[3] = 0;
      pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
      if (0xf < pvStack_30) {
        _free(unaff_ESI);
        return;
      }
      pvStack_30 = (void *)0xf;
      uStack_34 = 0;
      FUN_00401740(s__R_texture_switch_count_00a1098c,0x17);
      FUN_00401740(&DAT_00a10988,2);
      _Memory = (void *)FUN_00404230(&uStack_2c);
      (**(code **)(*DAT_00b5a688 + 8))(auStack_24 + -9);
      if (0xf < auStack_24[2]) {
        _free(pvStack_30);
        return;
      }
      auStack_24[2] = 0xf;
      auStack_24[1] = 0;
      pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
      if (0xf < uStack_38) {
        _free(piStack_4c);
        return;
      }
      piStack_4c = (int *)((uint)piStack_4c & 0xffffff00);
      FUN_00401740(s__R_VertexShaderSwitchingCount_00a109a8,0x1d);
      FUN_00401740(&DAT_00a109a4,2);
      uVar6 = FUN_00404230(&uStack_34);
      (**(code **)(*DAT_00b5a688 + 8))(&piStack_50,uVar6);
      if (0xf < auStack_24[0]) {
        _free((void *)0xf);
        return;
      }
      auStack_24[0] = 0xf;
      pvStack_28 = (void *)0x0;
      if (0xf < unaff_EBP) {
        _free(piStack_54);
        return;
      }
      piStack_54 = (int *)((uint)piStack_54 & 0xffffff00);
      FUN_00401740(s__R_VertexBufferLockCount_00a109cc,0x18);
      FUN_00401740(&DAT_00a109c8,2);
      uVar6 = FUN_00404230(auStack_24 + -6);
      (**(code **)(*DAT_00b5a688 + 8))(&puStack_58,uVar6);
      if (0xf < uStack_2c) {
        _free((void *)0xf);
        return;
      }
      uStack_2c = 0xf;
      pvStack_30 = (void *)0x0;
      if (unaff_EDI < 0x10) {
        return;
      }
      _free(_Memory);
      return;
    }
  }
  else if (iVar3 == 0) goto LAB_00849fec;
  puVar5 = *(undefined4 **)(in_ECX + 0x90);
  puVar1 = *(undefined4 **)(in_ECX + 0x94);
  if (puVar5 == puVar1) {
    return;
  }
  do {
    piStack_50 = (int *)0x84a3a7;
    (**(code **)(*(int *)*puVar5 + 0xc))();
    puVar5 = puVar5 + 1;
  } while (puVar5 != puVar1);
  return;
}


// ==== FUN_0084a3c0 @ 0x0084a3c0 ====

void FUN_0084a3c0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_1c [28];
  
  iVar1 = FUN_004b4e70(param_1);
  piVar2 = (int *)FUN_004af750();
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x14))(local_1c);
  for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(iVar1);
  }
  return;
}


// ==== FUN_0084a410 @ 0x0084a410 ====

void FUN_0084a410(void)

{
  int *piVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  if (DAT_00b5a7c8 != (int *)0x0) {
    (**(code **)(*DAT_00b5a7c8 + 8))();
  }
  (**(code **)(*DAT_00b5a688 + 0x30))();
  FUN_0084b7f0(0);
  piVar1 = *(int **)(*(int *)(in_ECX + 0x28) + 0x90);
  (**(code **)(*piVar1 + 400))(piVar1,0,0,0,0);
  FUN_0087d720();
  FUN_0084ad50(in_ECX + 0x8c);
  FUN_0087c960();
  FUN_0087bd20();
  pvVar2 = *(void **)(in_ECX + 0x34);
  if (pvVar2 != (void *)0x0) {
    FUN_00850a80();
    _free(pvVar2);
    return;
  }
  pvVar2 = *(void **)(in_ECX + 0x2c);
  *(undefined4 *)(in_ECX + 0x34) = 0;
  if (pvVar2 != (void *)0x0) {
    FUN_00854760();
    _free(pvVar2);
    return;
  }
  pvVar2 = *(void **)(in_ECX + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  if (pvVar2 != (void *)0x0) {
    FUN_00857a30();
    _free(pvVar2);
    return;
  }
  pvVar2 = *(void **)(in_ECX + 0x30);
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if (pvVar2 != (void *)0x0) {
    FUN_00858730();
    _free(pvVar2);
    return;
  }
  *(undefined4 *)(in_ECX + 0x30) = 0;
  if (*(undefined4 **)(in_ECX + 0x78) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x78))(1);
  }
  pvVar2 = *(void **)(in_ECX + 0x74);
  *(undefined4 *)(in_ECX + 0x78) = 0;
  if (pvVar2 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x74) = 0;
    FUN_0087bb30();
    return;
  }
  if (*(void **)((int)pvVar2 + 0x68) != (void *)0x0) {
    _free(*(void **)((int)pvVar2 + 0x68));
    return;
  }
  *(undefined4 *)((int)pvVar2 + 0x68) = 0;
  *(undefined4 *)((int)pvVar2 + 0x6c) = 0;
  *(undefined4 *)((int)pvVar2 + 0x70) = 0;
  puVar4 = *(undefined4 **)((int)pvVar2 + 0x58);
  if (puVar4 == (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar2 + 0x58) = 0;
    *(undefined4 *)((int)pvVar2 + 0x5c) = 0;
    *(undefined4 *)((int)pvVar2 + 0x60) = 0;
    FUN_0087a090();
    _free(pvVar2);
    return;
  }
  puVar3 = *(undefined4 **)((int)pvVar2 + 0x5c);
  for (; puVar4 != puVar3; puVar4 = puVar4 + 9) {
    (**(code **)*puVar4)(0);
  }
  _free(*(void **)((int)pvVar2 + 0x58));
  return;
}


// ==== FUN_0084a560 @ 0x0084a560 ====

void FUN_0084a560(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  FUN_0084adf0();
  *in_ECX = &PTR_FUN_00a10a40;
  FUN_0087ba20();
  uVar1 = DAT_0099d080;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  *(undefined1 *)(in_ECX + 0x33) = 0;
  *(undefined1 *)((int)in_ECX + 0xce) = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x2b] = uVar1;
  in_ECX[0x2c] = 0;
  uVar2 = DAT_009c16c0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = uVar1;
  in_ECX[0x2f] = uVar2;
  in_ECX[0x30] = uVar2;
  in_ECX[0x31] = uVar2;
  in_ECX[0x32] = uVar2;
  return;
}


// ==== FUN_0084a690 @ 0x0084a690 ====

void FUN_0084a690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10a40;
  FUN_0084a410();
  if ((void *)in_ECX[0x24] == (void *)0x0) {
    in_ECX[0x24] = 0;
    in_ECX[0x25] = 0;
    in_ECX[0x26] = 0;
    FUN_0087ba50();
    FUN_0084ae60();
    return;
  }
  _free((void *)in_ECX[0x24]);
  return;
}


// ==== FUN_0084a6e0 @ 0x0084a6e0 ====

uint FUN_0084a6e0(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint extraout_EAX;
  int in_ECX;
  void *apvStack_10 [4];
  
  if (*(char *)(*(uint *)(in_ECX + 0x28) + 0x60) != '\0') {
    return *(uint *)(in_ECX + 0x28) & 0xffffff00;
  }
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0xc0002) {
    uVar2 = (**(code **)(*DAT_00b5ac00 + 4))(param_1);
    return uVar2 & 0xffffff00;
  }
  iVar1 = FUN_00850950();
  if (iVar1 != 0) {
    piVar3 = (int *)FUN_00850950();
    FUN_00430c20(param_1 + 1);
    (**(code **)(*piVar3 + 0xc))(apvStack_10);
    if (apvStack_10[0] != (void *)0x0) {
      _free(apvStack_10[0]);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_0084a770 @ 0x0084a770 ====

void FUN_0084a770(undefined4 *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_30 [12];
  
  puVar4 = param_1;
  puVar5 = local_30;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  uVar1 = FUN_0084aed0();
  *(undefined4 *)(in_ECX + 0x28) = uVar1;
  FUN_008575f0(local_30);
  uVar1 = FUN_0049b670();
  FUN_0087bc80(uVar1);
  if (*(char *)(*(int *)(in_ECX + 0x28) + 0xea) != '\0') {
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar3 = (**(code **)(*piVar2 + 0x1c))();
    *(undefined4 *)(iVar3 + 8) = 1;
  }
  uVar1 = FUN_0084af50();
  *(undefined4 *)(in_ECX + 0x30) = uVar1;
  uVar1 = FUN_0084afd0();
  *(undefined4 *)(in_ECX + 0x34) = uVar1;
  FUN_008508d0();
  uVar1 = FUN_0084b050();
  *(undefined4 *)(in_ECX + 0x78) = uVar1;
  uVar1 = FUN_0084bab0();
  *(undefined4 *)(in_ECX + 0x74) = uVar1;
  uVar1 = FUN_0084b0d0();
  *(undefined4 *)(in_ECX + 0x2c) = uVar1;
  FUN_008547c0();
  FUN_0087c400();
  FUN_0087cc90();
  FUN_0087db90();
  (**(code **)(*DAT_00b5d990 + 4))();
  param_1 = (undefined4 *)FUN_0084b150();
  *(undefined4 **)(in_ECX + 0x3c) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084bcb0();
  *(undefined4 **)(in_ECX + 0x40) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b1d0();
  *(undefined4 **)(in_ECX + 0x44) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b250();
  *(undefined4 **)(in_ECX + 0x48) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b2d0();
  *(undefined4 **)(in_ECX + 0x4c) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b350();
  *(undefined4 **)(in_ECX + 0x50) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b3d0();
  *(undefined4 **)(in_ECX + 0x54) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b450();
  *(undefined4 **)(in_ECX + 0x58) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b4d0();
  *(undefined4 **)(in_ECX + 0x5c) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b550();
  *(undefined4 **)(in_ECX + 0x68) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b5d0();
  *(undefined4 **)(in_ECX + 0x38) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b650();
  *(undefined4 **)(in_ECX + 0x60) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b6d0();
  *(undefined4 **)(in_ECX + 100) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0087e290();
  *(undefined4 **)(in_ECX + 0x6c) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  param_1 = (undefined4 *)FUN_0084b750();
  *(undefined4 **)(in_ECX + 0x70) = param_1;
  iVar3 = *(int *)(in_ECX + 0x90);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x98) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x94) - iVar3 >> 2)))
  {
    FUN_0084b860(*(undefined4 *)(in_ECX + 0x94),1,&param_1);
  }
  else {
    puVar4 = *(undefined4 **)(in_ECX + 0x94);
    *puVar4 = param_1;
    *(undefined4 **)(in_ECX + 0x94) = puVar4 + 1;
  }
  (**(code **)(*DAT_00b5a688 + 0x2c))(DAT_00b5d984);
  return;
}


// ==== FUN_0084acf0 @ 0x0084acf0 ====

undefined1 FUN_0084acf0(int *param_1,int *param_2,undefined1 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if ((int *)*param_1 != (int *)0x0) {
      (**(code **)(*(int *)*param_1 + 0x10))(1);
    }
  }
  return param_3;
}


// ==== FUN_0084ad20 @ 0x0084ad20 ====

void FUN_0084ad20(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 9) {
    (**(code **)*param_1)(0);
  }
  return;
}


// ==== FUN_0084ad50 @ 0x0084ad50 ====

void FUN_0084ad50(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1;
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    piVar1 = (int *)(param_1 + 8);
    iVar4 = *piVar1 - iVar2;
    if (iVar4 >> 2 != 0) {
      param_1._1_3_ = (uint3)(iVar4 >> 10);
      param_1 = (uint)param_1._1_3_ << 8;
      FUN_0084acf0(iVar2,*piVar1,param_1);
      if (*(void **)(iVar3 + 4) != (void *)0x0) {
        _free(*(void **)(iVar3 + 4));
        return;
      }
      *(undefined4 *)(iVar3 + 4) = 0;
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
    }
  }
  return;
}


// ==== FUN_0084ada0 @ 0x0084ada0 ====

void FUN_0084ada0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 8);
  for (; puVar2 != puVar1; puVar2 = puVar2 + 9) {
    (**(code **)*puVar2)(0);
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0084adf0 @ 0x0084adf0 ====

void FUN_0084adf0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_00a10a38;
  if (DAT_00b5ac04 == (undefined4 *)0x0) {
    DAT_00b5ac04 = in_ECX;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_00a109e8,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0084ae60 @ 0x0084ae60 ====

void FUN_0084ae60(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_00a10a38;
  if (DAT_00b5ac04 != 0) {
    DAT_00b5ac04 = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_00a10a00,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0084aed0 @ 0x0084aed0 ====

int FUN_0084aed0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x530);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00857b00(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084af50 @ 0x0084af50 ====

int FUN_0084af50(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(4);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00858720(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084afd0 @ 0x0084afd0 ====

int FUN_0084afd0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x18);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00850ac0(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b050 @ 0x0084b050 ====

int FUN_0084b050(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x308);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_008623e0(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b0d0 @ 0x0084b0d0 ====

int FUN_0084b0d0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x1c);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00854800(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b150 @ 0x0084b150 ====

int FUN_0084b150(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x60);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_0085a570(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b1d0 @ 0x0084b1d0 ====

int FUN_0084b1d0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x254);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_0086f490(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b250 @ 0x0084b250 ====

int FUN_0084b250(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x440);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00872e20(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b2d0 @ 0x0084b2d0 ====

int FUN_0084b2d0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x28);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_008682d0(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b350 @ 0x0084b350 ====

int FUN_0084b350(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x1814);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00865d50(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b3d0 @ 0x0084b3d0 ====

int FUN_0084b3d0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x38);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_0085fa50(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b450 @ 0x0084b450 ====

int FUN_0084b450(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x38);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_0085cdc0(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b4d0 @ 0x0084b4d0 ====

int FUN_0084b4d0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0xcc);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00861760(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b550 @ 0x0084b550 ====

int FUN_0084b550(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x20);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00861f70(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b5d0 @ 0x0084b5d0 ====

int FUN_0084b5d0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x24);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00875e90(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b650 @ 0x0084b650 ====

int FUN_0084b650(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x48);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00879190(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b6d0 @ 0x0084b6d0 ====

int FUN_0084b6d0(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x3c4034);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00877a20(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b750 @ 0x0084b750 ====

int FUN_0084b750(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x14);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_0087b8a0(), iVar3 != 0)) {
    return iVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar3 = (*pcVar1)();
    return iVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084b7d0 @ 0x0084b7d0 ====

void FUN_0084b7d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0084ae60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084b7f0 @ 0x0084b7f0 ====

void FUN_0084b7f0(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x90) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x1a0))(*(int **)(in_ECX + 0x90),param_1);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_m_pDevice_009ae948,9);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0084b860 @ 0x0084b860 ====

void FUN_0084b860(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a0f0;
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


// ==== Catch@0084b9c1 @ 0x0084b9c1 ====

void Catch_0084b9c1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0084bab0 @ 0x0084bab0 ====

void * FUN_0084bab0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  void *pvVar3;
  void *extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar3 = operator_new(0x74);
  if (pvVar3 != (void *)0x0) {
    FUN_0087a060();
    uVar2 = DAT_0099d080;
    *(undefined4 *)((int)pvVar3 + 0x20) = DAT_0099d080;
    *(undefined4 *)((int)pvVar3 + 0x1c) = 0;
    *(undefined4 *)((int)pvVar3 + 0x24) = 0;
    *(undefined4 *)((int)pvVar3 + 0x28) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0x2c) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0x30) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0x34) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0x44) = DAT_00a10a2c;
    *(undefined4 *)((int)pvVar3 + 0x4c) = DAT_009b0128;
    uVar2 = DAT_0099d100;
    *(undefined4 *)((int)pvVar3 + 0x48) = 0;
    *(undefined4 *)((int)pvVar3 + 0x50) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0x58) = 0;
    *(undefined4 *)((int)pvVar3 + 0x5c) = 0;
    *(undefined4 *)((int)pvVar3 + 0x60) = 0;
    *(undefined4 *)((int)pvVar3 + 0x68) = 0;
    *(undefined4 *)((int)pvVar3 + 0x6c) = 0;
    *(undefined4 *)((int)pvVar3 + 0x70) = 0;
    return pvVar3;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    pvVar3 = (void *)(*pcVar1)();
    return pvVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0084bb90 @ 0x0084bb90 ====

void FUN_0084bb90(int param_1)

{
  if (*(void **)(param_1 + 0x14) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x14));
    return;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (*(void **)(param_1 + 4) == (void *)0x0) {
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return;
  }
  _free(*(void **)(param_1 + 4));
  return;
}


// ==== FUN_0084bbd0 @ 0x0084bbd0 ====

void FUN_0084bbd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0084a690();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084bbf0 @ 0x0084bbf0 ====

void FUN_0084bbf0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_1 + 0x14);
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      if ((void *)puVar1[-4] != (void *)0x0) {
        _free((void *)puVar1[-4]);
        return;
      }
      puVar1[-4] = 0;
      puVar1[-3] = 0;
      puVar1[-2] = 0;
      param_1 = param_1 + 0x70;
      puVar1 = puVar1 + 0x1c;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0084bc50 @ 0x0084bc50 ====

void FUN_0084bc50(undefined4 param_1,undefined4 param_2)

{
  FUN_0084bbf0(param_1,param_2);
  return;
}


// ==== FUN_0084bc70 @ 0x0084bc70 ====

void FUN_0084bc70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_0084bbf0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0084bcb0 @ 0x0084bcb0 ====

void FUN_0084bcb0(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  puVar2 = operator_new(0x14);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = &PTR_FUN_00a10a48;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    return;
  }
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_4 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0084bd30 @ 0x0084bd30 ====

void FUN_0084bd30(byte param_1)

{
  undefined4 *in_ECX;
  
  FUN_0084bc70();
  *in_ECX = &PTR_FUN_00a10a18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084bd60 @ 0x0084bd60 ====

void FUN_0084bd60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10b98;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084bd80 @ 0x0084bd80 ====

undefined4 FUN_0084bd80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0084bd90 @ 0x0084bd90 ====

undefined4 FUN_0084bd90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0084bda0 @ 0x0084bda0 ====

undefined4 FUN_0084bda0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0084bdb0 @ 0x0084bdb0 ====

undefined4 FUN_0084bdb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4c);
}


// ==== FUN_0084bdd0 @ 0x0084bdd0 ====

void FUN_0084bdd0(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x2c);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0084be00 @ 0x0084be00 ====

undefined4 FUN_0084be00(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    param_1 = (int *)CONCAT31(param_1._1_3_,0x23);
    (**(code **)(iVar1 + 8))();
    iVar1 = FUN_00405850(&param_1,0,1);
    if (iVar1 != -1) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0084be60 @ 0x0084be60 ====

void FUN_0084be60(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  piVar1 = (int *)in_ECX[1];
  *in_ECX = &PTR_FUN_00a10bb4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[1] = 0;
  }
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[10] = 0xf;
    in_ECX[9] = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    *in_ECX = &PTR_FUN_00a10b98;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_0084bed0 @ 0x0084bed0 ====

void FUN_0084bed0(void)

{
  int *piVar1;
  char cVar2;
  int in_ECX;
  
  piVar1 = DAT_00b5a6cc;
  FUN_00401660(in_ECX + 0x10,0,0xffffffff);
  cVar2 = (**(code **)(*piVar1 + 8))();
  *(uint *)(in_ECX + 0x4c) = (uint)(cVar2 == '\0');
  return;
}


// ==== FUN_0084bf20 @ 0x0084bf20 ====

void FUN_0084bf20(int *param_1)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *in_ECX;
  int *piVar7;
  int iVar8;
  int *piVar9;
  bool bVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  int **ppiVar24;
  int *piStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  int aiStack_58 [7];
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 local_20;
  void *local_1c;
  int local_c;
  uint local_8;
  undefined4 uStack_4;
  
  piVar7 = param_1;
  *in_ECX = &PTR_FUN_00a10bb4;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  if (param_1 == (int *)0x0) {
    local_8 = 0xf;
    local_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_pTextureRes____NULL_00a10a98,0x13);
    FUN_00406880(&local_20);
    if (local_8 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_1c);
    return;
  }
  iVar3 = (**(code **)(*param_1 + 8))();
  if (*(int *)(iVar3 + 0x30) != 2) {
    local_8 = 0xf;
    local_c = 0;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_pTextureRes_>GetStock___m_eBuild_00a10aac,0x3b);
    FUN_00406880(&local_20);
    if (local_8 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_1c);
    return;
  }
  uVar4 = (**(code **)(*param_1 + 8))();
  uVar4 = FUN_004022a0(&local_20,s_Texture__00a10ae8,uVar4);
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401660(uVar4,0,0xffffffff);
  FUN_00796e00(auStack_3c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  uStack_5c = FUN_0049b670();
  piStack_64 = (int *)0x0;
  iVar3 = param_1[10];
  iVar8 = (-(uint)(*(int *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x98) != 0x10) & 0xfffffffb) + 0x1a;
  local_c = FUN_004af6c0();
  if (local_c == 0) {
    local_8 = 0xf;
    local_1c = (void *)((uint)local_1c & 0xffffff00);
    FUN_00401740(s_pTextureRes_>GetContents______NU_00a10af4,0x22);
    FUN_00406880(&local_20);
    if (local_8 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_1c);
    return;
  }
  piVar9 = aiStack_58;
  iVar5 = iVar3;
  uVar4 = FUN_004af6c0(iVar3,piVar9);
  iVar5 = FUN_0089ff92(uVar4,iVar5,piVar9);
  if (iVar5 != 0) {
    uVar4 = (**(code **)(*param_1 + 8))();
    uVar4 = FUN_004022a0(&local_20,s_warning__can_t_get_iamge_info_00a10b18,uVar4);
    FUN_00796d50(uVar4);
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  pcVar1 = (char *)((int)param_1 + 0x4d);
  param_1 = (int *)aiStack_58[3];
  if (*pcVar1 == '\0') {
    if (aiStack_58[3] == 1) {
      param_1 = (int *)0x0;
    }
  }
  else {
    param_1 = (int *)0x1;
    uVar4 = (**(code **)(*piVar7 + 8))();
    uVar4 = FUN_004022a0(&local_20,s_ui_texture__00a10b38,uVar4);
    FUN_00796d50(uVar4);
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
  }
  if (aiStack_58[5] == 5) {
    ppiVar24 = &piStack_64;
    uVar23 = 0;
    uVar22 = 0;
    uVar21 = 0;
    uVar20 = 4;
    uVar19 = 4;
    uVar18 = 1;
    uVar16 = 0xfffffffd;
    uVar15 = 0;
    uVar14 = 0xffffffff;
    uVar12 = 0xffffffff;
    iVar8 = iVar3;
    uVar6 = FUN_004af6c0(iVar3,0xffffffff,0xffffffff,0,0xfffffffd,1,4,4,0,0,0,ppiVar24);
    uVar4 = uStack_5c;
    iVar8 = FUN_008a1517(uStack_5c,uVar6,iVar8,uVar12,uVar14,uVar15,uVar16,uVar18,uVar19,uVar20,
                         uVar21,uVar22,uVar23,ppiVar24);
    if (iVar8 < 0) {
      ppiVar24 = &piStack_64;
      uVar23 = 0;
      uVar22 = 0;
      uVar21 = 0;
      uVar20 = 4;
      uVar19 = 4;
      uVar18 = 1;
      uVar16 = 0;
      uVar15 = 0;
      uVar14 = 0xffffffff;
      uVar12 = 0xffffffff;
      uVar6 = FUN_004af6c0(iVar3,0xffffffff,0xffffffff,0,0,1,4,4,0,0,0,ppiVar24);
      FUN_008a1517(uVar4,uVar6,iVar3,uVar12,uVar14,uVar15,uVar16,uVar18,uVar19,uVar20,uVar21,uVar22,
                   uVar23,ppiVar24);
    }
  }
  else {
    uStack_60 = 1;
    if (param_1 == (int *)0x0) {
      uStack_60 = 0xffffffff;
    }
    ppiVar24 = &piStack_64;
    uVar19 = 0;
    uVar18 = 0;
    uVar16 = 0;
    uVar15 = 1;
    uVar14 = 1;
    uVar12 = 0;
    iVar5 = iVar3;
    iVar11 = aiStack_58[0];
    iVar13 = aiStack_58[1];
    uVar17 = aiStack_58[4];
    uVar4 = uStack_60;
    uVar6 = FUN_004af6c0(iVar3,aiStack_58[0],aiStack_58[1],param_1,0,aiStack_58[4],1,1,uStack_60,0,0
                         ,0,ppiVar24);
    iVar5 = FUN_008a14d8(uStack_5c,uVar6,iVar5,iVar11,iVar13,param_1,uVar12,uVar17,uVar14,uVar15,
                         uVar4,uVar16,uVar18,uVar19,ppiVar24);
    if (iVar5 < 0) {
      (**(code **)(*piVar7 + 8))();
      uVar17 = uVar17 & 0xffffff00;
      FUN_00401740(s_Texture_creation_Failed___s__err_00a10b48,0x26);
      FUN_00404230(&local_20,uVar12,uVar17);
      FUN_00796d50(&local_20);
      if (0xf < local_8) {
        _free(local_1c);
        return;
      }
      ppiVar24 = &piStack_64;
      uVar19 = 0;
      piVar9 = aiStack_58;
      uVar18 = 0;
      uVar16 = 1;
      uVar15 = 1;
      uVar14 = 0;
      uVar12 = 0;
      iVar5 = aiStack_58[0];
      iVar11 = aiStack_58[1];
      uVar4 = uStack_60;
      uVar6 = FUN_004af6c0(iVar3,aiStack_58[0],aiStack_58[1],0,0,iVar8,1,1,uStack_60,0,piVar9,0,
                           ppiVar24);
      iVar3 = FUN_008a14d8(uStack_5c,uVar6,iVar3,iVar5,iVar11,uVar12,uVar14,iVar8,uVar15,uVar16,
                           uVar4,uVar18,piVar9,uVar19,ppiVar24);
      if (iVar3 < 0) {
        local_8 = 0xf;
        local_c = 0;
        local_1c = (void *)((uint)local_1c & 0xffffff00);
        FUN_00401740(s_SUCCEEDED_hr__00a10b70,0xd);
        FUN_00406880(&local_20);
        if (local_8 < 0x10) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        _free(local_1c);
        return;
      }
    }
  }
  uVar4 = (**(code **)(*piVar7 + 8))();
  FUN_00401660(uVar4,0,0xffffffff);
  in_ECX[1] = piStack_64;
  if (piStack_64 == (int *)0x0) {
    uStack_4 = 1;
    aiStack_58[0] = 1;
    aiStack_58[1] = 1;
    aiStack_58[2] = 0x10;
    aiStack_58[3] = 1;
    aiStack_58[4] = 0x15;
    aiStack_58[5] = 3;
    aiStack_58[6] = 4;
    in_ECX[2] = 1;
    in_ECX[0x12] = 0x15;
  }
  else {
    (**(code **)(*piStack_64 + 0x44))(piStack_64,0,&local_20);
    in_ECX[2] = local_8;
    in_ECX[0x12] = local_20;
  }
  in_ECX[3] = uStack_4;
  piVar7 = aiStack_58;
  piVar9 = in_ECX + 0xb;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar9 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar9 = piVar9 + 1;
  }
  iVar3 = in_ECX[0xf];
  if (iVar3 < 0x31545845) {
    if (iVar3 != 0x31545844) {
      if (iVar3 == 0x15) goto LAB_0084c3ca;
      if (iVar3 != 0x19) {
        bVar10 = iVar3 == 0x1a;
        goto LAB_0084c3bf;
      }
    }
    FUN_0084bed0();
  }
  else {
    if (iVar3 != 0x33545844) {
      bVar10 = iVar3 == 0x35545844;
LAB_0084c3bf:
      if (!bVar10) {
        in_ECX[0x13] = 0;
        goto LAB_0084c3d1;
      }
    }
LAB_0084c3ca:
    in_ECX[0x13] = 2;
  }
LAB_0084c3d1:
  FUN_00796d40();
  if (uStack_24 < 0x10) {
    return;
  }
  _free(pvStack_38);
  return;
}


// ==== FUN_0084c400 @ 0x0084c400 ====

undefined4 FUN_0084c400(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x50);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_0084bf20(param_1);
  return uVar2;
}


// ==== FUN_0084c420 @ 0x0084c420 ====

void FUN_0084c420(byte param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  piVar1 = (int *)in_ECX[1];
  *in_ECX = &PTR_FUN_00a10bb4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[1] = 0;
  }
  if (0xf < (uint)in_ECX[10]) {
    _free((void *)in_ECX[5]);
    return;
  }
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *in_ECX = &PTR_FUN_00a10b98;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084c480 @ 0x0084c480 ====

void FUN_0084c480(void)

{
  void *pvVar1;
  
  if (DAT_00b5a6c4 == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_0049b270();
      return;
    }
  }
  return;
}


// ==== FUN_0084c4a0 @ 0x0084c4a0 ====

void FUN_0084c4a0(void)

{
  if (DAT_00b5a6c4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6c4)(1);
  }
  return;
}


// ==== FUN_0084c4c0 @ 0x0084c4c0 ====

void FUN_0084c4c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10be8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084c4e0 @ 0x0084c4e0 ====

int FUN_0084c4e0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0084c4f0 @ 0x0084c4f0 ====

int FUN_0084c4f0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0084c500 @ 0x0084c500 ====

void FUN_0084c500(void)

{
  if (DAT_00b5af74 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af74)(1);
  }
  return;
}


// ==== FUN_0084c520 @ 0x0084c520 ====

void FUN_0084c520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10bf8;
  DAT_00b5af74 = 0;
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[0xb] = 0xf;
    in_ECX[10] = 0;
    *(undefined1 *)(in_ECX + 6) = 0;
    *in_ECX = &PTR_FUN_00a10be8;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_0084c560 @ 0x0084c560 ====

void FUN_0084c560(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10bf8;
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  DAT_00b5af74 = (undefined4 *)0x0;
  if (in_ECX + 1 != (undefined4 *)0x0) {
    DAT_00b5af74 = in_ECX;
  }
  in_ECX[4] = DAT_009b0318;
  uVar1 = DAT_0099d0dc;
  *(undefined1 *)(in_ECX + 3) = 1;
  *(undefined1 *)(in_ECX + 1) = 1;
  in_ECX[2] = uVar1;
  FUN_00401740(s_Water_SkyCube__dds_00a10bd0,0x12);
  return;
}


// ==== FUN_0084c5c0 @ 0x0084c5c0 ====

void FUN_0084c5c0(void)

{
  void *pvVar1;
  
  if (DAT_00b5af74 == 0) {
    pvVar1 = operator_new(0x30);
    if (pvVar1 != (void *)0x0) {
      FUN_0084c560();
      return;
    }
  }
  return;
}


// ==== FUN_0084c5e0 @ 0x0084c5e0 ====

void FUN_0084c5e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10bf8;
  DAT_00b5af74 = 0;
  if (0xf < (uint)in_ECX[0xb]) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *in_ECX = &PTR_FUN_00a10be8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084c640 @ 0x0084c640 ====

undefined1 FUN_0084c640(void)

{
  return 1;
}


// ==== FUN_0084c650 @ 0x0084c650 ====

void FUN_0084c650(void)

{
  FUN_00849fa0();
  return;
}


// ==== FUN_0084c660 @ 0x0084c660 ====

void FUN_0084c660(void)

{
  FUN_008498e0();
  return;
}


// ==== FUN_0084c670 @ 0x0084c670 ====

void FUN_0084c670(void)

{
  FUN_0084a3c0();
  return;
}


// ==== FUN_0084c680 @ 0x0084c680 ====

void FUN_0084c680(void)

{
  FUN_0084a6e0();
  return;
}


// ==== FUN_0084c690 @ 0x0084c690 ====

void FUN_0084c690(void)

{
  FUN_00855810();
  return;
}


// ==== FUN_0084c6a0 @ 0x0084c6a0 ====

void FUN_0084c6a0(void)

{
  int *in_ECX;
  
  FUN_0084c4a0();
  (**(code **)(*in_ECX + 0x14))();
  FUN_008809e0();
  FUN_008809a0();
  FUN_0087e380();
  if (DAT_00b5ac04 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac04)(1);
  }
  if (DAT_00b5d99c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d99c)(1);
  }
  if (DAT_00b5d998 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d998)(1);
  }
  if (DAT_00b5d994 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5d994)(1);
  }
  return;
}


// ==== FUN_0084c700 @ 0x0084c700 ====

void FUN_0084c700(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb1e0;
  FUN_0084c6a0();
  *in_ECX = &PTR_FUN_009bb1b4;
  FUN_0054b950();
  return;
}


// ==== FUN_0084c720 @ 0x0084c720 ====

void FUN_0084c720(void)

{
  FUN_0049b670();
  return;
}


// ==== FUN_0084c730 @ 0x0084c730 ====

void FUN_0084c730(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *pvVar7;
  void *unaff_EBX;
  uint unaff_EBP;
  uint unaff_ESI;
  void *unaff_EDI;
  uint *_Memory;
  uint *puStack_88;
  uint *_Memory_00;
  uint *puStack_80;
  void **ppvStack_7c;
  void *pvStack_68;
  uint uStack_64;
  void *pvStack_60;
  uint uStack_5c;
  void *pvStack_58;
  uint uStack_54;
  void *pvStack_50;
  uint auStack_4c [2];
  undefined1 uStack_44;
  bool bStack_43;
  undefined2 uStack_42;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  bool bStack_24;
  undefined1 uStack_23;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
  pvStack_50 = (void *)0xf;
  uStack_54 = 0;
  uStack_64 = uStack_64 & 0xffffff00;
  pcVar3 = PTR_s_WindowHandle_00b50f1c;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  ppvStack_7c = (void **)((int)pcVar3 - (int)(PTR_s_WindowHandle_00b50f1c + 1));
  puStack_80 = (uint *)PTR_s_WindowHandle_00b50f1c;
  FUN_00401740();
  ppvStack_7c = (void **)0x84c782;
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  ppvStack_7c = &pvStack_68;
  puStack_80 = auStack_4c;
  (**(code **)(*piVar4 + 8))();
  puStack_88 = (uint *)0x84c799;
  uStack_18 = thunk_FUN_00796e90();
  if (0xf < uStack_3c) {
    puStack_88 = (uint *)0x84c7b3;
    _free(pvStack_50);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  if ((void *)0xf < pvStack_58) {
    puStack_88 = (uint *)0x84c7d6;
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0;
  uStack_20 = 0;
  uVar5 = (**(code **)(*DAT_00b5a6b0 + 8))();
  switch(uVar5) {
  case 1:
  case 2:
  case 4:
  case 5:
    bStack_24 = true;
    break;
  default:
    bStack_24 = *(char *)(iVar2 + 5) == '\0';
  }
  puStack_88 = (uint *)s_buffer_count_00a10c40;
  pvStack_58 = (void *)0xf;
  uStack_5c = 0;
  FUN_00401740();
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  _Memory_00 = auStack_4c + -9;
  puStack_88 = &uStack_54;
  uVar5 = (**(code **)(*piVar4 + 8))();
  uStack_18 = thunk_FUN_00796e60(uVar5);
  if (0xf < _uStack_44) {
    _free(pvStack_58);
    return;
  }
  _uStack_44 = 0xf;
  auStack_4c[1] = 0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  if (0xf < pvStack_60) {
    _free(unaff_EDI);
    return;
  }
  uStack_38 = *(undefined4 *)(iVar2 + 0x54);
  uStack_34 = *(undefined4 *)(iVar2 + 0x50);
  uStack_30 = (uint)*(byte *)(iVar2 + 0x5c);
  pvStack_60 = (void *)0xf;
  uStack_64 = 0;
  FUN_00401740(s_texture_depth_00a10c50,0xd);
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  _Memory = auStack_4c + -0xb;
  uVar5 = (**(code **)(*piVar4 + 8))(&uStack_5c);
  _uStack_44 = thunk_FUN_00796e60(uVar5);
  if (0xf < auStack_4c[0]) {
    _free(pvStack_60);
    return;
  }
  auStack_4c[0] = 0xf;
  pvStack_50 = (void *)0x0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if ((void *)0xf < pvStack_68) {
    _free(ppvStack_7c);
    return;
  }
  pvStack_68 = (void *)0xf;
  ppvStack_7c = (void **)((uint)ppvStack_7c & 0xffffff00);
  FUN_00401740(s_z_depth_00a10c60,7);
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar5 = (**(code **)(*piVar4 + 8))(&uStack_64,&puStack_80);
  pvStack_50 = (void *)thunk_FUN_00796e60(uVar5);
  if (0xf < uStack_54) {
    _free(pvStack_68);
    return;
  }
  uStack_54 = 0xf;
  pvStack_58 = (void *)0x0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  if (0xf < unaff_ESI) {
    _free(_Memory_00);
    return;
  }
  uStack_23 = *(undefined1 *)(iVar2 + 6);
  uStack_2c = 0;
  FUN_00401740(s_anisotropy_filtering_00a10c68,0x14);
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar5 = (**(code **)(*piVar4 + 8))(auStack_4c + -8,&puStack_88);
  iVar2 = thunk_FUN_00796e60(uVar5);
  _uStack_44 = CONCAT11(iVar2 == 1,uStack_44);
  if (0xf < uStack_5c) {
    _free((void *)0xf);
    return;
  }
  uStack_5c = 0xf;
  pvStack_60 = (void *)0x0;
  if (0xf < unaff_EBP) {
    _free(_Memory);
    return;
  }
  uStack_2c = CONCAT31(uStack_2c._1_3_,1);
  FUN_008809c0();
  if ((DAT_00b5d998 == (undefined4 *)0x0) &&
     (puVar6 = operator_new(0x14), puVar6 != (undefined4 *)0x0)) {
    *puVar6 = &PTR_FUN_00a10cc0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    if (puVar6 == (undefined4 *)0xfffffffc) {
      DAT_00b5d998 = (undefined4 *)0x0;
    }
    else {
      DAT_00b5d998 = puVar6;
    }
  }
  if ((DAT_00b5d99c == (undefined4 *)0x0) &&
     (puVar6 = operator_new(0x14), puVar6 != (undefined4 *)0x0)) {
    *puVar6 = &PTR_FUN_00a10cb8;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    if (puVar6 == (undefined4 *)0xfffffffc) {
      DAT_00b5d99c = (undefined4 *)0x0;
    }
    else {
      DAT_00b5d99c = puVar6;
    }
  }
  if ((DAT_00b5d994 == (undefined4 *)0x0) &&
     (puVar6 = operator_new(0x14), puVar6 != (undefined4 *)0x0)) {
    *puVar6 = &PTR_FUN_00a10cc8;
    puVar6[2] = 0;
    puVar6[3] = 0;
    puVar6[4] = 0;
    if (puVar6 == (undefined4 *)0xfffffffc) {
      DAT_00b5d994 = (undefined4 *)0x0;
    }
    else {
      DAT_00b5d994 = puVar6;
    }
  }
  if (DAT_00b5ac04 == 0) {
    pvVar7 = operator_new(0xd4);
    if (pvVar7 != (void *)0x0) {
      FUN_0084a560();
    }
    FUN_0084a770(&pvStack_58);
  }
  FUN_0087f6d0();
  FUN_00880980();
  (**(code **)(*DAT_00b5af70 + 0xc))();
  FUN_0084c480();
  return;
}


// ==== FUN_0084cb40 @ 0x0084cb40 ====

void FUN_0084cb40(byte param_1)

{
  void *in_ECX;
  
  FUN_0084cb60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084cb60 @ 0x0084cb60 ====

void FUN_0084cb60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10cb8;
  DAT_00b5d99c = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)in_ECX[3]) {
    _free(*(void **)in_ECX[2]);
    return;
  }
  FUN_00412dc0();
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0084cbc0 @ 0x0084cbc0 ====

void FUN_0084cbc0(byte param_1)

{
  void *in_ECX;
  
  FUN_0084cbe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084cbe0 @ 0x0084cbe0 ====

void FUN_0084cbe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10cc0;
  DAT_00b5d998 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)in_ECX[3]) {
    _free(*(void **)in_ECX[2]);
    return;
  }
  FUN_00412dc0();
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0084cc40 @ 0x0084cc40 ====

void FUN_0084cc40(byte param_1)

{
  void *in_ECX;
  
  FUN_0084cc60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084cc60 @ 0x0084cc60 ====

void FUN_0084cc60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a10cc8;
  DAT_00b5d994 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)in_ECX[3]) {
    _free(*(void **)in_ECX[2]);
    return;
  }
  FUN_00412dc0();
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0084ccc0 @ 0x0084ccc0 ====

void FUN_0084ccc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11914;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084cce0 @ 0x0084cce0 ====

int FUN_0084cce0(void)

{
  int in_ECX;
  
  return in_ECX + 0x208;
}


// ==== FUN_0084ccf0 @ 0x0084ccf0 ====

void FUN_0084ccf0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2fc) = *param_1;
  *(undefined4 *)(in_ECX + 0x300) = param_1[1];
  *(undefined4 *)(in_ECX + 0x304) = param_1[2];
  *(undefined4 *)(in_ECX + 0x308) = param_1[3];
  return;
}


// ==== FUN_0084cd20 @ 0x0084cd20 ====

int FUN_0084cd20(void)

{
  int in_ECX;
  
  return in_ECX + 0x2fc;
}


// ==== FUN_0084cd30 @ 0x0084cd30 ====

int FUN_0084cd30(void)

{
  int in_ECX;
  
  return in_ECX + 0x30c;
}


// ==== FUN_0084cd40 @ 0x0084cd40 ====

void FUN_0084cd40(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x330) = *param_1;
  *(undefined4 *)(in_ECX + 0x334) = param_1[1];
  *(undefined4 *)(in_ECX + 0x338) = param_1[2];
  *(undefined4 *)(in_ECX + 0x33c) = param_1[3];
  return;
}


// ==== FUN_0084cd70 @ 0x0084cd70 ====

int FUN_0084cd70(void)

{
  int in_ECX;
  
  return in_ECX + 0x330;
}


// ==== FUN_0084cd80 @ 0x0084cd80 ====

void FUN_0084cd80(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x340);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_0084cda0 @ 0x0084cda0 ====

int FUN_0084cda0(void)

{
  int in_ECX;
  
  return in_ECX + 0x340;
}


// ==== FUN_0084cdb0 @ 0x0084cdb0 ====

void FUN_0084cdb0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x35c) = *param_1;
  *(undefined4 *)(in_ECX + 0x360) = param_1[1];
  *(undefined4 *)(in_ECX + 0x364) = param_1[2];
  *(undefined4 *)(in_ECX + 0x368) = param_1[3];
  return;
}


// ==== FUN_0084cde0 @ 0x0084cde0 ====

int FUN_0084cde0(void)

{
  int in_ECX;
  
  return in_ECX + 0x35c;
}


// ==== FUN_0084cdf0 @ 0x0084cdf0 ====

void FUN_0084cdf0(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x36c);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_0084ce10 @ 0x0084ce10 ====

int FUN_0084ce10(void)

{
  int in_ECX;
  
  return in_ECX + 0x36c;
}


// ==== FUN_0084ce20 @ 0x0084ce20 ====

void FUN_0084ce20(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x388) = *param_1;
  *(undefined4 *)(in_ECX + 0x38c) = param_1[1];
  *(undefined4 *)(in_ECX + 0x390) = param_1[2];
  *(undefined4 *)(in_ECX + 0x394) = param_1[3];
  *(undefined4 *)(in_ECX + 0x398) = param_1[4];
  return;
}


// ==== FUN_0084ce50 @ 0x0084ce50 ====

int FUN_0084ce50(void)

{
  int in_ECX;
  
  return in_ECX + 0x388;
}


// ==== FUN_0084ce60 @ 0x0084ce60 ====

void FUN_0084ce60(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x39c) = *param_1;
  return;
}


// ==== FUN_0084ce80 @ 0x0084ce80 ====

int FUN_0084ce80(void)

{
  int in_ECX;
  
  return in_ECX + 0x39c;
}


// ==== FUN_0084ce90 @ 0x0084ce90 ====

void FUN_0084ce90(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3fc) = *param_1;
  *(undefined4 *)(in_ECX + 0x400) = param_1[1];
  *(undefined4 *)(in_ECX + 0x404) = param_1[2];
  return;
}


// ==== FUN_0084ceb0 @ 0x0084ceb0 ====

int FUN_0084ceb0(void)

{
  int in_ECX;
  
  return in_ECX + 0x3fc;
}


// ==== FUN_0084cec0 @ 0x0084cec0 ====

void FUN_0084cec0(undefined1 *param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x408) = *param_1;
  return;
}


// ==== FUN_0084ced0 @ 0x0084ced0 ====

int FUN_0084ced0(void)

{
  int in_ECX;
  
  return in_ECX + 0x408;
}


// ==== FUN_0084cee0 @ 0x0084cee0 ====

void FUN_0084cee0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x39e) = *param_1;
  *(undefined1 *)(in_ECX + 0x3a2) = *(undefined1 *)(param_1 + 1);
  return;
}


// ==== FUN_0084cf00 @ 0x0084cf00 ====

int FUN_0084cf00(void)

{
  int in_ECX;
  
  return in_ECX + 0x39e;
}


// ==== FUN_0084cf10 @ 0x0084cf10 ====

int FUN_0084cf10(void)

{
  int in_ECX;
  
  return in_ECX + 0x3a4;
}


// ==== FUN_0084cf20 @ 0x0084cf20 ====

int FUN_0084cf20(void)

{
  int in_ECX;
  
  return in_ECX + 0x3a4;
}


// ==== FUN_0084cf30 @ 0x0084cf30 ====

int FUN_0084cf30(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_0084cf40 @ 0x0084cf40 ====

int FUN_0084cf40(void)

{
  int in_ECX;
  
  return in_ECX + 0x54;
}


// ==== FUN_0084cf50 @ 0x0084cf50 ====

int FUN_0084cf50(void)

{
  int in_ECX;
  
  return in_ECX + 100;
}


// ==== FUN_0084cf60 @ 0x0084cf60 ====

int FUN_0084cf60(void)

{
  int in_ECX;
  
  return in_ECX + 0xd4;
}


// ==== FUN_0084cf70 @ 0x0084cf70 ====

int FUN_0084cf70(void)

{
  int in_ECX;
  
  return in_ECX + 0x1c8;
}


// ==== FUN_0084cf80 @ 0x0084cf80 ====

int FUN_0084cf80(void)

{
  int in_ECX;
  
  return in_ECX + 0x1d8;
}


// ==== FUN_0084cf90 @ 0x0084cf90 ====

int FUN_0084cf90(void)

{
  int in_ECX;
  
  return in_ECX + 0x1e8;
}


// ==== FUN_0084cfa0 @ 0x0084cfa0 ====

int FUN_0084cfa0(void)

{
  int in_ECX;
  
  return in_ECX + 0x1f8;
}


// ==== FUN_0084cfb0 @ 0x0084cfb0 ====

int FUN_0084cfb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 200) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xcc) - *(int *)(in_ECX + 200) >> 6;
}


// ==== FUN_0084cfd0 @ 0x0084cfd0 ====

int FUN_0084cfd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x3c) - *(int *)(in_ECX + 0x38) >> 2;
}


// ==== FUN_0084cff0 @ 0x0084cff0 ====

int FUN_0084cff0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x4c) - *(int *)(in_ECX + 0x48) >> 2;
}


// ==== FUN_0084d010 @ 0x0084d010 ====

int FUN_0084d010(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x78) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x7c) - *(int *)(in_ECX + 0x78) >> 2;
}


// ==== FUN_0084d030 @ 0x0084d030 ====

int FUN_0084d030(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x88) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x8c) - *(int *)(in_ECX + 0x88) >> 2;
}


// ==== FUN_0084d050 @ 0x0084d050 ====

int FUN_0084d050(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x98) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x9c) - *(int *)(in_ECX + 0x98) >> 2;
}


// ==== FUN_0084d070 @ 0x0084d070 ====

int FUN_0084d070(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xa8) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xac) - *(int *)(in_ECX + 0xa8) >> 2;
}


// ==== FUN_0084d090 @ 0x0084d090 ====

int FUN_0084d090(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb8) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xbc) - *(int *)(in_ECX + 0xb8) >> 2;
}


// ==== FUN_0084d0b0 @ 0x0084d0b0 ====

void FUN_0084d0b0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_0084d0c0 @ 0x0084d0c0 ====

void FUN_0084d0c0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))(1,0);
  return;
}


// ==== FUN_0084d0d0 @ 0x0084d0d0 ====

void FUN_0084d0d0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(1,0);
  return;
}


// ==== FUN_0084d0e0 @ 0x0084d0e0 ====

void FUN_0084d0e0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x10) + 0xc))(1,0);
  return;
}


// ==== FUN_0084d0f0 @ 0x0084d0f0 ====

void FUN_0084d0f0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x14) + 0xc))(1,0);
  return;
}


// ==== FUN_0084d100 @ 0x0084d100 ====

void FUN_0084d100(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x18) + 0xc))(1,0);
  return;
}


// ==== FUN_0084d110 @ 0x0084d110 ====

void FUN_0084d110(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0xc))(1,0);
  return;
}


// ==== FUN_0084d120 @ 0x0084d120 ====

void FUN_0084d120(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x20) + 0xc))(1,0);
  return;
}


// ==== FUN_0084d130 @ 0x0084d130 ====

/* WARNING: Removing unreachable block (ram,0x0084d238) */
/* WARNING: Removing unreachable block (ram,0x0084d1e2) */
/* WARNING: Removing unreachable block (ram,0x0084d18c) */

void FUN_0084d130(float *param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  float *pfVar3;
  
  iVar2 = __isnan((double)*param_1);
  if (iVar2 != 0) {
    FUN_00401740(s___isnan_cameraInfo_v3From_x__00a10d0c,0x1c);
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar2 = __isnan((double)param_1[1]);
  if (iVar2 != 0) {
    FUN_00401740(s___isnan_cameraInfo_v3From_y__00a10d2c,0x1c);
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar2 = __isnan((double)param_1[2]);
  if (iVar2 != 0) {
    FUN_00401740(s___isnan_cameraInfo_v3From_z__00a10d4c,0x1c);
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pfVar3 = (float *)(in_ECX + 0x208);
  for (iVar2 = 0x3d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = *param_1;
    param_1 = param_1 + 1;
    pfVar3 = pfVar3 + 1;
  }
  return;
}


// ==== FUN_0084d260 @ 0x0084d260 ====

/* WARNING: Removing unreachable block (ram,0x0084d368) */
/* WARNING: Removing unreachable block (ram,0x0084d312) */
/* WARNING: Removing unreachable block (ram,0x0084d2bc) */

void FUN_0084d260(float *param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  float *pfVar3;
  
  iVar2 = __isnan((double)*param_1);
  if (iVar2 != 0) {
    FUN_00401740(s___isnan_cameraInfo_v3From_x__00a10d6c,0x1c);
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar2 = __isnan((double)param_1[1]);
  if (iVar2 != 0) {
    FUN_00401740(s___isnan_cameraInfo_v3From_y__00a10d8c,0x1c);
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar2 = __isnan((double)param_1[2]);
  if (iVar2 != 0) {
    FUN_00401740(s___isnan_cameraInfo_v3From_z__00a10dac,0x1c);
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pfVar3 = (float *)(in_ECX + 0xd4);
  for (iVar2 = 0x3d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar3 = *param_1;
    param_1 = param_1 + 1;
    pfVar3 = pfVar3 + 1;
  }
  return;
}


// ==== FUN_0084d390 @ 0x0084d390 ====

void FUN_0084d390(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30c) = *param_1;
  *(undefined4 *)(in_ECX + 0x310) = param_1[1];
  FUN_00401660(param_1 + 2,0,0xffffffff);
  return;
}


// ==== FUN_0084d3c0 @ 0x0084d3c0 ====

int FUN_0084d3c0(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 200);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xcc) - iVar1 >> 6) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return param_1 * 0x40 + iVar1;
}


// ==== FUN_0084d3f0 @ 0x0084d3f0 ====

undefined4 FUN_0084d3f0(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x38);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x3c) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_0084d420 @ 0x0084d420 ====

undefined4 FUN_0084d420(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x48);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x4c) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_0084d450 @ 0x0084d450 ====

undefined4 FUN_0084d450(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x78);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x7c) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_0084d480 @ 0x0084d480 ====

undefined4 FUN_0084d480(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x88);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x8c) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_0084d4b0 @ 0x0084d4b0 ====

undefined4 FUN_0084d4b0(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x98);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x9c) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_0084d4e0 @ 0x0084d4e0 ====

undefined4 FUN_0084d4e0(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xa8);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xac) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_0084d510 @ 0x0084d510 ====

undefined4 FUN_0084d510(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb8);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xbc) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  return *(undefined4 *)(iVar1 + param_1 * 4);
}


// ==== FUN_0084d540 @ 0x0084d540 ====

void FUN_0084d540(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11c6c;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x73] = 0;
  in_ECX[0x74] = 0;
  in_ECX[0x75] = 0;
  in_ECX[0x77] = 0;
  in_ECX[0x78] = 0;
  in_ECX[0x79] = 0;
  in_ECX[0x7b] = 0;
  in_ECX[0x7c] = 0;
  in_ECX[0x7d] = 0;
  in_ECX[0x7f] = 0;
  in_ECX[0x80] = 0;
  in_ECX[0x81] = 0;
  in_ECX[0xcb] = 0xf;
  in_ECX[0xca] = 0;
  *(undefined1 *)(in_ECX + 0xc6) = 0;
  in_ECX[0xcc] = 0;
  in_ECX[0xcd] = 0;
  in_ECX[0xce] = 0;
  in_ECX[0xcf] = 0;
  in_ECX[0xd7] = 0;
  in_ECX[0xd8] = 0;
  in_ECX[0xd9] = 0;
  in_ECX[0xda] = 0;
  *(undefined1 *)(in_ECX + 0xe2) = 0;
  in_ECX[0xe3] = 0;
  in_ECX[0xe4] = 0;
  in_ECX[0xe5] = 0;
  *(undefined1 *)(in_ECX + 0xe7) = 0;
  *(undefined1 *)((int)in_ECX + 0x39d) = 0;
  *(undefined1 *)((int)in_ECX + 0x39e) = 0;
  *(undefined1 *)(in_ECX + 0xe8) = 0;
  *(undefined1 *)((int)in_ECX + 0x3a1) = 0xff;
  *(undefined1 *)((int)in_ECX + 0x39f) = 1;
  *(undefined1 *)((int)in_ECX + 0x3a2) = 1;
  in_ECX[0xe9] = 0;
  *(undefined1 *)(in_ECX + 0xeb) = 0;
  *(undefined1 *)((int)in_ECX + 0x3ad) = 0;
  *(undefined1 *)((int)in_ECX + 0x3ae) = 0;
  *(undefined1 *)((int)in_ECX + 0x3af) = 0;
  *(undefined1 *)(in_ECX + 0xec) = 0;
  in_ECX[0xee] = 0;
  in_ECX[0xef] = 0;
  in_ECX[0xf0] = 0;
  in_ECX[0xf2] = 0;
  in_ECX[0xf3] = 0;
  in_ECX[0xf4] = 0;
  in_ECX[0xf6] = 0;
  in_ECX[0xf7] = 0;
  in_ECX[0xf8] = 0;
  *(undefined1 *)(in_ECX + 0x101) = 0;
  *(undefined1 *)(in_ECX + 0x102) = 0;
  pvVar1 = operator_new(0x6c18);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0084e790();
  }
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x3e18);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0084e810();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x1418);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0084e890();
  }
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0xf018);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0084e900();
  }
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x2418);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0084e980();
  }
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0x1818);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0084e9f0();
  }
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(0x1818);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0084ea60();
  }
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(0x2418);
  if (pvVar1 == (void *)0x0) {
    in_ECX[8] = 0;
    return;
  }
  uVar2 = FUN_0084ead0();
  in_ECX[8] = uVar2;
  return;
}


// ==== FUN_0084d840 @ 0x0084d840 ====

undefined1 * FUN_0084d840(void)

{
  undefined1 *puVar1;
  
  puVar1 = operator_new(0x7c);
  if (puVar1 == (undefined1 *)0x0) {
    return (undefined1 *)0x0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 0x58) = 0;
  *(undefined4 *)(puVar1 + 0x5c) = 0;
  *(undefined4 *)(puVar1 + 0x60) = 0;
  *(undefined4 *)(puVar1 + 0x68) = 0;
  *(undefined4 *)(puVar1 + 0x6c) = 0;
  *(undefined4 *)(puVar1 + 0x70) = 0;
  *(undefined4 *)(puVar1 + 0x74) = 0;
  *(undefined4 *)(puVar1 + 0x78) = 0;
  return puVar1;
}


// ==== FUN_0084d880 @ 0x0084d880 ====

undefined4 FUN_0084d880(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x40c);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_0084d540();
  return uVar2;
}


// ==== FUN_0084d8a0 @ 0x0084d8a0 ====

void FUN_0084d8a0(void)

{
  int in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uStack_5c;
  undefined4 auStack_58 [2];
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x2c);
  for (puVar1 = *(undefined4 **)(in_ECX + 0x28); puVar1 != puVar2; puVar1 = puVar1 + 1) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,*puVar1);
  }
  if (*(void **)(in_ECX + 0x28) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x28));
    return;
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0x3c);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x38); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0x4c);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x48); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0x48) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x48));
    return;
  }
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  puVar2 = *(undefined4 **)(in_ECX + 0x58);
  puVar1 = *(undefined4 **)(in_ECX + 0x5c);
  if (puVar2 != puVar1) {
    do {
      (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))(1,*puVar2);
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar1);
  }
  if (*(void **)(in_ECX + 0x58) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x58));
    return;
  }
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0x6c);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x68); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0x68) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x68));
    return;
  }
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  puVar2 = *(undefined4 **)(in_ECX + 0x78);
  puVar1 = *(undefined4 **)(in_ECX + 0x7c);
  if (puVar2 != puVar1) {
    do {
      (**(code **)(**(int **)(in_ECX + 0x14) + 0x10))(1,*puVar2);
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar1);
  }
  if (*(void **)(in_ECX + 0x78) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x78));
    return;
  }
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0x8c);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x88); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 0x18) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0x88) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x88));
    return;
  }
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0x9c);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x98); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0x98) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x98));
    return;
  }
  *(undefined4 *)(in_ECX + 0x98) = 0;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0xac);
  for (puVar2 = *(undefined4 **)(in_ECX + 0xa8); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 0x20) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0xa8) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xa8));
    return;
  }
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  if (*(void **)(in_ECX + 0xb8) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xb8));
    return;
  }
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = 0;
  puVar2 = *(undefined4 **)(in_ECX + 0x1cc);
  puVar1 = *(undefined4 **)(in_ECX + 0x1d0);
  if (puVar2 != puVar1) {
    do {
      (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,*puVar2);
      puVar2 = puVar2 + 1;
    } while (puVar2 != puVar1);
  }
  if (*(void **)(in_ECX + 0x1cc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x1cc));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1cc) = 0;
  *(undefined4 *)(in_ECX + 0x1d0) = 0;
  *(undefined4 *)(in_ECX + 0x1d4) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0x1e0);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x1dc); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0x1dc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x1dc));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1dc) = 0;
  *(undefined4 *)(in_ECX + 0x1e0) = 0;
  *(undefined4 *)(in_ECX + 0x1e4) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0x1f0);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x1ec); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0x1ec) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x1ec));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1ec) = 0;
  *(undefined4 *)(in_ECX + 0x1f0) = 0;
  *(undefined4 *)(in_ECX + 500) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 0x200);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x1fc); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))(1,*puVar2);
  }
  if (*(void **)(in_ECX + 0x1fc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x1fc));
    return;
  }
  *(undefined4 *)(in_ECX + 0x1fc) = 0;
  *(undefined4 *)(in_ECX + 0x200) = 0;
  *(undefined4 *)(in_ECX + 0x204) = 0;
  if (*(void **)(in_ECX + 200) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 200) = 0;
    *(undefined4 *)(in_ECX + 0xcc) = 0;
    *(undefined4 *)(in_ECX + 0xd0) = 0;
    *(undefined4 *)(in_ECX + 0x330) = 0;
    *(undefined4 *)(in_ECX + 0x334) = 0;
    *(undefined4 *)(in_ECX + 0x338) = 0;
    *(undefined4 *)(in_ECX + 0x33c) = 0;
    *(undefined4 *)(in_ECX + 0x35c) = 0;
    *(undefined4 *)(in_ECX + 0x360) = 0;
    *(undefined4 *)(in_ECX + 0x364) = 0;
    *(undefined4 *)(in_ECX + 0x368) = 0;
    *(undefined4 *)(in_ECX + 0x388) = 0;
    *(undefined4 *)(in_ECX + 0x38c) = 0;
    *(undefined4 *)(in_ECX + 0x390) = 0;
    *(undefined4 *)(in_ECX + 0x394) = 0;
    *(undefined4 *)(in_ECX + 0x398) = uStack_5c;
    *(undefined2 *)(in_ECX + 0x39c) = 0;
    auStack_58[0] = 0;
    uStack_50 = 0;
    uStack_4f = 0;
    uStack_4e = 0;
    uStack_4d = 0;
    uStack_4c = 0;
    uStack_44 = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    FUN_008500b0(auStack_58);
    *(undefined4 *)(in_ECX + 0x39e) = 0xff000100;
    *(undefined1 *)(in_ECX + 0x3a2) = 1;
    return;
  }
  _free(*(void **)(in_ECX + 200));
  return;
}


// ==== FUN_0084ddb0 @ 0x0084ddb0 ====

void FUN_0084ddb0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x30) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x2c) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x2c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x2c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x2c) = puVar2 + 1;
  return;
}


// ==== FUN_0084de00 @ 0x0084de00 ====

void FUN_0084de00(void)

{
  FUN_00850140();
  return;
}


// ==== FUN_0084de10 @ 0x0084de10 ====

void FUN_0084de10(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x38);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x40) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x3c) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x3c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x3c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x3c) = puVar2 + 1;
  return;
}


// ==== FUN_0084de60 @ 0x0084de60 ====

void FUN_0084de60(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x48);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x50) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x4c) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x4c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x4c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x4c) = puVar2 + 1;
  return;
}


// ==== FUN_0084deb0 @ 0x0084deb0 ====

void FUN_0084deb0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x58);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x60) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x5c) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x5c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x5c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x5c) = puVar2 + 1;
  return;
}


// ==== FUN_0084df00 @ 0x0084df00 ====

void FUN_0084df00(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x68);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x70) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x6c) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x6c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x6c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x6c) = puVar2 + 1;
  return;
}


// ==== FUN_0084df50 @ 0x0084df50 ====

void FUN_0084df50(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x78);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x80) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x7c) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x7c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x7c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x7c) = puVar2 + 1;
  return;
}


// ==== FUN_0084dfa0 @ 0x0084dfa0 ====

void FUN_0084dfa0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x88);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x90) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x8c) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x8c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x8c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x8c) = puVar2 + 1;
  return;
}


// ==== FUN_0084e000 @ 0x0084e000 ====

void FUN_0084e000(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x98);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xa0) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x9c) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x9c),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x9c);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x9c) = puVar2 + 1;
  return;
}


// ==== FUN_0084e060 @ 0x0084e060 ====

void FUN_0084e060(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xa8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xb0) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xac) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0xac),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xac);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0xac) = puVar2 + 1;
  return;
}


// ==== FUN_0084e0c0 @ 0x0084e0c0 ====

void FUN_0084e0c0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xb8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc0) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xbc) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0xbc),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xbc);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0xbc) = puVar2 + 1;
  return;
}


// ==== FUN_0084e120 @ 0x0084e120 ====

void FUN_0084e120(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1cc);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x1d4) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x1d0) - iVar1 >> 2)
     )) {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x1d0),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1d0);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x1d0) = puVar2 + 1;
  return;
}


// ==== FUN_0084e180 @ 0x0084e180 ====

void FUN_0084e180(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1dc);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x1e4) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x1e0) - iVar1 >> 2)
     )) {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x1e0),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1e0);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x1e0) = puVar2 + 1;
  return;
}


// ==== FUN_0084e1e0 @ 0x0084e1e0 ====

void FUN_0084e1e0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1ec);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 500) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x1f0) - iVar1 >> 2)))
  {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x1f0),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1f0);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x1f0) = puVar2 + 1;
  return;
}


// ==== FUN_0084e240 @ 0x0084e240 ====

void FUN_0084e240(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1fc);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x204) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x200) - iVar1 >> 2)
     )) {
    FUN_0084fbc0(*(undefined4 *)(in_ECX + 0x200),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x200);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x200) = puVar2 + 1;
  return;
}


// ==== FUN_0084e2a0 @ 0x0084e2a0 ====

void FUN_0084e2a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11c6c;
  FUN_0084d8a0();
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
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  FUN_0084f880();
  if (0xf < (uint)in_ECX[0xcb]) {
    _free((void *)in_ECX[0xc6]);
    return;
  }
  in_ECX[0xcb] = 0xf;
  in_ECX[0xca] = 0;
  *(undefined1 *)(in_ECX + 0xc6) = 0;
  if ((void *)in_ECX[0x7f] != (void *)0x0) {
    _free((void *)in_ECX[0x7f]);
    return;
  }
  in_ECX[0x7f] = 0;
  in_ECX[0x80] = 0;
  in_ECX[0x81] = 0;
  if ((void *)in_ECX[0x7b] != (void *)0x0) {
    _free((void *)in_ECX[0x7b]);
    return;
  }
  in_ECX[0x7b] = 0;
  in_ECX[0x7c] = 0;
  in_ECX[0x7d] = 0;
  if ((void *)in_ECX[0x77] != (void *)0x0) {
    _free((void *)in_ECX[0x77]);
    return;
  }
  in_ECX[0x77] = 0;
  in_ECX[0x78] = 0;
  in_ECX[0x79] = 0;
  if ((void *)in_ECX[0x73] != (void *)0x0) {
    _free((void *)in_ECX[0x73]);
    return;
  }
  in_ECX[0x73] = 0;
  in_ECX[0x74] = 0;
  in_ECX[0x75] = 0;
  if ((void *)in_ECX[0x32] != (void *)0x0) {
    _free((void *)in_ECX[0x32]);
    return;
  }
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  if ((void *)in_ECX[0x2e] != (void *)0x0) {
    _free((void *)in_ECX[0x2e]);
    return;
  }
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  if ((void *)in_ECX[0x2a] != (void *)0x0) {
    _free((void *)in_ECX[0x2a]);
    return;
  }
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  if ((void *)in_ECX[0x26] != (void *)0x0) {
    _free((void *)in_ECX[0x26]);
    return;
  }
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  if ((void *)in_ECX[0x22] != (void *)0x0) {
    _free((void *)in_ECX[0x22]);
    return;
  }
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  if ((void *)in_ECX[0x1e] != (void *)0x0) {
    _free((void *)in_ECX[0x1e]);
    return;
  }
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  if ((void *)in_ECX[0x1a] != (void *)0x0) {
    _free((void *)in_ECX[0x1a]);
    return;
  }
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  if ((void *)in_ECX[0x16] != (void *)0x0) {
    _free((void *)in_ECX[0x16]);
    return;
  }
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  if ((void *)in_ECX[0x12] != (void *)0x0) {
    _free((void *)in_ECX[0x12]);
    return;
  }
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  if ((void *)in_ECX[0xe] != (void *)0x0) {
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  if ((void *)in_ECX[10] == (void *)0x0) {
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    in_ECX[0xc] = 0;
    *in_ECX = &PTR_FUN_00a11914;
    return;
  }
  _free((void *)in_ECX[10]);
  return;
}


// ==== FUN_0084e560 @ 0x0084e560 ====

void FUN_0084e560(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11a4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e580 @ 0x0084e580 ====

void FUN_0084e580(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11a64;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e5a0 @ 0x0084e5a0 ====

void FUN_0084e5a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11a7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e5c0 @ 0x0084e5c0 ====

void FUN_0084e5c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11a94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e5e0 @ 0x0084e5e0 ====

void FUN_0084e5e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11aac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e600 @ 0x0084e600 ====

void FUN_0084e600(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11ac4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e620 @ 0x0084e620 ====

void FUN_0084e620(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11adc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e640 @ 0x0084e640 ====

void FUN_0084e640(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11af4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e660 @ 0x0084e660 ====

void FUN_0084e660(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0x10;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0x10; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_0084e690 @ 0x0084e690 ====

void FUN_0084e690(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11b0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e6b0 @ 0x0084e6b0 ====

void FUN_0084e6b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11b14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e6d0 @ 0x0084e6d0 ====

void FUN_0084e6d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11b1c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e6f0 @ 0x0084e6f0 ====

void FUN_0084e6f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11b24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e710 @ 0x0084e710 ====

void FUN_0084e710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11b2c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e730 @ 0x0084e730 ====

void FUN_0084e730(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11b34;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e750 @ 0x0084e750 ====

void FUN_0084e750(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11b3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e770 @ 0x0084e770 ====

void FUN_0084e770(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a11b44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084e790 @ 0x0084e790 ====

void FUN_0084e790(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a11b4c;
  in_ECX[1] = &PTR_FUN_00a11b0c;
  in_ECX[0x1b02] = 0;
  in_ECX[0x1b02] = in_ECX[0x1b02] + 0x100;
  in_ECX[0x1b05] = in_ECX + 2;
  in_ECX[0x1b03] = 0;
  in_ECX[0x1b04] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[0x1a] = puVar1 + 0x1d;
    puVar1[0x1b] = 0;
    puVar1[0x1c] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x1b;
  } while (iVar2 != 0);
  in_ECX[0x1aff] = 0;
  in_ECX[0x1b00] = 0;
  in_ECX[0x1b01] = 0;
  return;
}


// ==== FUN_0084e800 @ 0x0084e800 ====

undefined4 FUN_0084e800(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x6c0c);
}


// ==== FUN_0084e810 @ 0x0084e810 ====

void FUN_0084e810(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a11b64;
  in_ECX[1] = &PTR_FUN_00a11b14;
  in_ECX[0xf82] = 0;
  in_ECX[0xf82] = in_ECX[0xf82] + 0x80;
  in_ECX[0xf85] = in_ECX + 2;
  in_ECX[0xf83] = 0;
  in_ECX[0xf84] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0x1e] = puVar1 + 0x21;
    puVar1[0x1f] = 0;
    puVar1[0x20] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x1f;
  } while (iVar2 != 0);
  in_ECX[0xf7f] = 0;
  in_ECX[0xf80] = 0;
  in_ECX[0xf81] = 0;
  return;
}


// ==== FUN_0084e880 @ 0x0084e880 ====

undefined4 FUN_0084e880(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3e0c);
}


// ==== FUN_0084e890 @ 0x0084e890 ====

void FUN_0084e890(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a11b7c;
  in_ECX[1] = &PTR_FUN_00a11b1c;
  in_ECX[0x502] = 0;
  in_ECX[0x502] = in_ECX[0x502] + 0x80;
  in_ECX[0x505] = in_ECX + 2;
  in_ECX[0x503] = 0;
  in_ECX[0x504] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[9] = puVar1 + 0xc;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 10;
  } while (iVar2 != 0);
  in_ECX[0x4ff] = 0;
  in_ECX[0x500] = 0;
  in_ECX[0x501] = 0;
  return;
}


// ==== FUN_0084e900 @ 0x0084e900 ====

void FUN_0084e900(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a11b94;
  in_ECX[1] = &PTR_FUN_00a11b24;
  in_ECX[0x3c02] = 0;
  in_ECX[0x3c02] = in_ECX[0x3c02] + 0x200;
  in_ECX[0x3c05] = in_ECX + 2;
  in_ECX[0x3c03] = 0;
  in_ECX[0x3c04] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x1d] = puVar1 + 0x20;
    puVar1[0x1e] = 0;
    puVar1[0x1f] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x1e;
  } while (iVar2 != 0);
  in_ECX[0x3bff] = 0;
  in_ECX[0x3c00] = 0;
  in_ECX[0x3c01] = 0;
  return;
}


// ==== FUN_0084e970 @ 0x0084e970 ====

undefined4 FUN_0084e970(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xf00c);
}


// ==== FUN_0084e980 @ 0x0084e980 ====

void FUN_0084e980(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a11bac;
  in_ECX[1] = &PTR_FUN_00a11b2c;
  in_ECX[0x902] = 0;
  in_ECX[0x902] = in_ECX[0x902] + 0x80;
  in_ECX[0x905] = in_ECX + 2;
  in_ECX[0x903] = 0;
  in_ECX[0x904] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0x11] = puVar1 + 0x14;
    puVar1[0x12] = 0;
    puVar1[0x13] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x12;
  } while (iVar2 != 0);
  in_ECX[0x8ff] = 0;
  in_ECX[0x900] = 0;
  in_ECX[0x901] = 0;
  return;
}


// ==== FUN_0084e9f0 @ 0x0084e9f0 ====

void FUN_0084e9f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a11bc4;
  in_ECX[1] = &PTR_FUN_00a11b34;
  in_ECX[0x602] = 0;
  in_ECX[0x602] = in_ECX[0x602] + 0x80;
  in_ECX[0x605] = in_ECX + 2;
  in_ECX[0x603] = 0;
  in_ECX[0x604] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0xb] = puVar1 + 0xe;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0xc;
  } while (iVar2 != 0);
  in_ECX[0x5ff] = 0;
  in_ECX[0x600] = 0;
  in_ECX[0x601] = 0;
  return;
}


// ==== FUN_0084ea60 @ 0x0084ea60 ====

void FUN_0084ea60(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a11bdc;
  in_ECX[1] = &PTR_FUN_00a11b3c;
  in_ECX[0x602] = 0;
  in_ECX[0x602] = in_ECX[0x602] + 0x80;
  in_ECX[0x605] = in_ECX + 2;
  in_ECX[0x603] = 0;
  in_ECX[0x604] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0xb] = puVar1 + 0xe;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0xc;
  } while (iVar2 != 0);
  in_ECX[0x5ff] = 0;
  in_ECX[0x600] = 0;
  in_ECX[0x601] = 0;
  return;
}


// ==== FUN_0084ead0 @ 0x0084ead0 ====

void FUN_0084ead0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_00a11bf4;
  in_ECX[1] = &PTR_FUN_00a11b44;
  in_ECX[0x902] = 0;
  in_ECX[0x902] = in_ECX[0x902] + 0x80;
  in_ECX[0x905] = in_ECX + 2;
  in_ECX[0x903] = 0;
  in_ECX[0x904] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0x11] = puVar1 + 0x14;
    puVar1[0x12] = 0;
    puVar1[0x13] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x12;
  } while (iVar2 != 0);
  in_ECX[0x8ff] = 0;
  in_ECX[0x900] = 0;
  in_ECX[0x901] = 0;
  return;
}


// ==== FUN_0084eb40 @ 0x0084eb40 ====

void FUN_0084eb40(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0x10;
    param_3 = param_3 + -0x10;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_0084eb70 @ 0x0084eb70 ====

void * FUN_0084eb70(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x24) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x24) = *(int *)((int)param_2 + 0x24) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1414);
  *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x28);
    *(undefined4 *)((int)pvVar2 + 0x20) = *(undefined4 *)(in_ECX + 0x1410);
    *(void **)(in_ECX + 0x1410) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1414) = *(undefined4 *)((int)pvVar2 + 0x1c);
  }
  *(undefined4 *)((int)pvVar2 + 0x1c) = 0;
  *(int *)((int)pvVar2 + 0x24) = param_1;
  return pvVar2;
}


// ==== FUN_0084ec20 @ 0x0084ec20 ====

undefined4 FUN_0084ec20(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x24) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x24);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x24);
    }
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(in_ECX + 0x1414);
    *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + -1;
    *(int *)(in_ECX + 0x1414) = param_2;
  }
  return 0;
}


// ==== FUN_0084eca0 @ 0x0084eca0 ====

int FUN_0084eca0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x74) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x74) = *(int *)(param_2 + 0x74) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0xf014);
  *(int *)(in_ECX + 0xf00c) = *(int *)(in_ECX + 0xf00c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x78);
    *(undefined4 *)((int)pvVar2 + 0x70) = *(undefined4 *)(in_ECX + 0xf010);
    *(void **)(in_ECX + 0xf010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xf014) = *(undefined4 *)((int)pvVar2 + 0x6c);
  }
  *(undefined4 *)((int)pvVar2 + 0x6c) = 0;
  *(int *)((int)pvVar2 + 0x74) = param_1;
  iVar3 = FUN_0084ed60();
  return iVar3;
}


// ==== FUN_0084ed60 @ 0x0084ed60 ====

void FUN_0084ed60(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x10) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  *(undefined4 *)(in_ECX + 0x18) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  *(undefined1 *)(in_ECX + 0x29) = 0;
  return;
}


// ==== FUN_0084ed90 @ 0x0084ed90 ====

undefined4 FUN_0084ed90(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x74) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x74);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x74);
    }
    *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(in_ECX + 0xf014);
    *(int *)(in_ECX + 0xf00c) = *(int *)(in_ECX + 0xf00c) + -1;
    *(int *)(in_ECX + 0xf014) = param_2;
  }
  return 0;
}


// ==== FUN_0084ee10 @ 0x0084ee10 ====

void * FUN_0084ee10(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x44) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x44) = *(int *)((int)param_2 + 0x44) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x2414);
  *(int *)(in_ECX + 0x240c) = *(int *)(in_ECX + 0x240c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x48);
    *(undefined4 *)((int)pvVar2 + 0x40) = *(undefined4 *)(in_ECX + 0x2410);
    *(void **)(in_ECX + 0x2410) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2414) = *(undefined4 *)((int)pvVar2 + 0x3c);
  }
  *(undefined4 *)((int)pvVar2 + 0x3c) = 0;
  *(int *)((int)pvVar2 + 0x44) = param_1;
  FUN_0040d030(pvVar2,0xc,4,FUN_00419fa0);
  *(undefined4 *)((int)pvVar2 + 0x38) = 1;
  return pvVar2;
}


// ==== FUN_0084eee0 @ 0x0084eee0 ====

undefined4 FUN_0084eee0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x44) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x44);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x44);
    }
    *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(in_ECX + 0x2414);
    *(int *)(in_ECX + 0x240c) = *(int *)(in_ECX + 0x240c) + -1;
    *(int *)(in_ECX + 0x2414) = param_2;
  }
  return 0;
}


// ==== FUN_0084ef60 @ 0x0084ef60 ====

void FUN_0084ef60(byte param_1)

{
  void *in_ECX;
  
  FUN_0084ef80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084ef80 @ 0x0084ef80 ====

void FUN_0084ef80(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a11b4c;
  if (in_ECX[0x1b03] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a10e30,
                         s_d__usa_24_0_1_2__develop_module__00a10dd0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x1c;
  iVar3 = 0x100;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a10ea8,
                           s_d__usa_24_0_1_2__develop_module__00a10e48,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x1b;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x1b04];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a11b0c;
    *in_ECX = &PTR_FUN_00a11a4c;
    return;
  }
  if (*(int *)((int)_Memory + 0x68) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a10f20,
                         s_d__usa_24_0_1_2__develop_module__00a10ec0,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0084f070 @ 0x0084f070 ====

void FUN_0084f070(byte param_1)

{
  void *in_ECX;
  
  FUN_0084f090();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084f090 @ 0x0084f090 ====

void FUN_0084f090(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a11b64;
  if (in_ECX[0xf83] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a10f98,
                         s_d__usa_24_0_1_2__develop_module__00a10f38,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x20;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11010,
                           s_d__usa_24_0_1_2__develop_module__00a10fb0,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x1f;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0xf84];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a11b14;
    *in_ECX = &PTR_FUN_00a11a64;
    return;
  }
  if (*(int *)((int)_Memory + 0x78) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11088,
                         s_d__usa_24_0_1_2__develop_module__00a11028,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0084f180 @ 0x0084f180 ====

void FUN_0084f180(byte param_1)

{
  void *in_ECX;
  
  FUN_0084f1a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084f1a0 @ 0x0084f1a0 ====

void FUN_0084f1a0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a11b7c;
  if (in_ECX[0x503] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11100,
                         s_d__usa_24_0_1_2__develop_module__00a110a0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0xb;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11178,
                           s_d__usa_24_0_1_2__develop_module__00a11118,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x504];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a11b1c;
    *in_ECX = &PTR_FUN_00a11a7c;
    return;
  }
  if (*(int *)((int)_Memory + 0x24) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a111f0,
                         s_d__usa_24_0_1_2__develop_module__00a11190,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0084f290 @ 0x0084f290 ====

void FUN_0084f290(byte param_1)

{
  void *in_ECX;
  
  FUN_0084f2b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084f2b0 @ 0x0084f2b0 ====

void FUN_0084f2b0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a11b94;
  if (in_ECX[0x3c03] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11268,
                         s_d__usa_24_0_1_2__develop_module__00a11208,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x1f;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a112e0,
                           s_d__usa_24_0_1_2__develop_module__00a11280,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x1e;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x3c04];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a11b24;
    *in_ECX = &PTR_FUN_00a11a94;
    return;
  }
  if (*(int *)((int)_Memory + 0x74) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11358,
                         s_d__usa_24_0_1_2__develop_module__00a112f8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0084f3a0 @ 0x0084f3a0 ====

void FUN_0084f3a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0084f3c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084f3c0 @ 0x0084f3c0 ====

void FUN_0084f3c0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a11bac;
  if (in_ECX[0x903] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a113d0,
                         s_d__usa_24_0_1_2__develop_module__00a11370,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x13;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11448,
                           s_d__usa_24_0_1_2__develop_module__00a113e8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x12;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x904];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a11b2c;
    *in_ECX = &PTR_FUN_00a11aac;
    return;
  }
  if (*(int *)((int)_Memory + 0x44) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a114c0,
                         s_d__usa_24_0_1_2__develop_module__00a11460,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0084f4b0 @ 0x0084f4b0 ====

void FUN_0084f4b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0084f4d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084f4d0 @ 0x0084f4d0 ====

void FUN_0084f4d0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a11bc4;
  if (in_ECX[0x603] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11538,
                         s_d__usa_24_0_1_2__develop_module__00a114d8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0xd;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a115b0,
                           s_d__usa_24_0_1_2__develop_module__00a11550,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0xc;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x604];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a11b34;
    *in_ECX = &PTR_FUN_00a11ac4;
    return;
  }
  if (*(int *)((int)_Memory + 0x2c) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11628,
                         s_d__usa_24_0_1_2__develop_module__00a115c8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0084f5c0 @ 0x0084f5c0 ====

void FUN_0084f5c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0084f5e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084f5e0 @ 0x0084f5e0 ====

void FUN_0084f5e0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a11bdc;
  if (in_ECX[0x603] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a116a0,
                         s_d__usa_24_0_1_2__develop_module__00a11640,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0xd;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11718,
                           s_d__usa_24_0_1_2__develop_module__00a116b8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0xc;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x604];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a11b3c;
    *in_ECX = &PTR_FUN_00a11adc;
    return;
  }
  if (*(int *)((int)_Memory + 0x2c) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11790,
                         s_d__usa_24_0_1_2__develop_module__00a11730,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0084f6d0 @ 0x0084f6d0 ====

void FUN_0084f6d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0084f6f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0084f6f0 @ 0x0084f6f0 ====

void FUN_0084f6f0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_00a11bf4;
  if (in_ECX[0x903] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11808,
                         s_d__usa_24_0_1_2__develop_module__00a117a8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x13;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a11880,
                           s_d__usa_24_0_1_2__develop_module__00a11820,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x12;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x904];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_00a11b44;
    *in_ECX = &PTR_FUN_00a11af4;
    return;
  }
  if (*(int *)((int)_Memory + 0x44) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_00a118f8,
                         s_d__usa_24_0_1_2__develop_module__00a11898,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_0084f7e0 @ 0x0084f7e0 ====

void FUN_0084f7e0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a100;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005d4600(param_1,param_3);
    param_1 = param_1 + 0x40;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0084f846 @ 0x0084f846 ====

void Catch_0084f846(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0084f850 @ 0x0084f850 ====

int FUN_0084f850(int param_1,int param_2,undefined4 param_3)

{
  FUN_0084f7e0(param_1,param_2,param_3);
  return param_2 * 0x40 + param_1;
}


// ==== FUN_0084f880 @ 0x0084f880 ====

void FUN_0084f880(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x34) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x34));
    return;
  }
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  if (*(void **)(in_ECX + 0x24) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_0084f8e0 @ 0x0084f8e0 ====

undefined4 FUN_0084f8e0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x44) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x44);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x44);
    }
    FUN_00412dc0();
    FUN_00412dc0();
    *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(in_ECX + 0x2414);
    *(int *)(in_ECX + 0x240c) = *(int *)(in_ECX + 0x240c) + -1;
    *(int *)(in_ECX + 0x2414) = param_2;
  }
  return 0;
}


// ==== FUN_0084f970 @ 0x0084f970 ====

void FUN_0084f970(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 local_70;
  int local_28;
  void *local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a110;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x7c);
  puVar5 = &local_70;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar4 >> 6;
  }
  uVar6 = CONCAT44(iVar4,iVar1);
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 6;
    }
    ExceptionList = &local_10;
    if (0x3ffffffU - iVar4 < param_2) {
      ExceptionList = &local_10;
      uVar6 = FUN_0085b3b0();
    }
    iVar4 = (int)((ulonglong)uVar6 >> 0x20);
    local_20 = (uint)uVar6;
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 6;
    }
    if (local_20 < iVar1 + param_2) {
      if (0x3ffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar4 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 6;
      }
      if (local_20 < iVar1 + param_2) {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 6;
        }
        local_20 = iVar4 + param_2;
      }
      local_20 = local_20 << 6;
      pvVar2 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar2;
      local_1c = FUN_005d4700(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      local_1c = FUN_0084f850(local_1c,param_2,&local_70);
      FUN_005d4700(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - (int)_Memory >> 6;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar2;
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar4) * 0x40 + (int)pvVar2);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)(local_28 - param_1 >> 6) < param_2) {
      local_18 = param_2 * 0x40;
      FUN_005d4690(param_1,local_28,local_18 + param_1);
      local_8 = 2;
      FUN_0084f850(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 6),&local_70);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_0084e660(param_1,*(int *)(in_ECX + 8) - local_18,&local_70);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x40;
    iVar4 = local_28 + param_2 * -0x40;
    uVar3 = FUN_005d4690(iVar4,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_0084eb40(param_1,iVar4,local_28);
    FUN_0084e660(param_1,local_18 + param_1,&local_70);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0084fad4 @ 0x0084fad4 ====

void Catch_0084fad4(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_0084fbc0 @ 0x0084fbc0 ====

void FUN_0084fbc0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a120;
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


// ==== Catch@0084fd21 @ 0x0084fd21 ====

void Catch_0084fd21(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0084fe10 @ 0x0084fe10 ====

undefined4 FUN_0084fe10(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x2c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x2c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x2c);
    }
    FUN_00412dc0();
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(in_ECX + 0x1814);
    *(int *)(in_ECX + 0x180c) = *(int *)(in_ECX + 0x180c) + -1;
    *(int *)(in_ECX + 0x1814) = param_2;
  }
  return 0;
}


// ==== FUN_0084fea0 @ 0x0084fea0 ====

void FUN_0084fea0(int param_1)

{
  int iVar1;
  void *_Memory;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar6 = *(int *)(param_1 + 8) - iVar1;
    iVar4 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0x18 + iVar4;
    uVar7 = iVar6 - iVar4;
    if (iVar6 != iVar4) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x18;
      }
      if (uVar7 <= uVar3) {
        FUN_0085d550(iVar1,*(undefined4 *)(param_1 + 8),_Memory,param_1);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x18) * 0x18;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0x18;
      }
      if (uVar7 <= uVar3) {
        iVar4 = FUN_0057dfd0();
        iVar1 = iVar1 + iVar4 * 0x18;
        FUN_0085d550(*(undefined4 *)(param_1 + 4),iVar1,_Memory,param_1);
        uVar5 = FUN_005cf5d0(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar5 = FUN_0057dfd0();
      cVar2 = FUN_0086c190(uVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar5 = FUN_005cf790(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


