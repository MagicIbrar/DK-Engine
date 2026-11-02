// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x4e0000-0x4effff

// ==== FUN_004e00e0 @ 0x004e00e0 ====

undefined4 * FUN_004e00e0(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *extraout_EAX;
  int in_ECX;
  undefined4 *puVar4;
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined4 local_8;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar4[1];
    do {
      if ((uint)puVar1[3] < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar4 != *(undefined4 **)(in_ECX + 4)) && ((uint)puVar4[3] <= *param_1)) {
    return puVar4 + 4;
  }
  local_14 = *param_1;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  FUN_004df280(local_24);
  piVar3 = (int *)FUN_004dfc90(&param_1,puVar4,&local_14);
  if (local_c == (void *)0x0) {
    return (undefined4 *)(*piVar3 + 0x10);
  }
  FUN_004def50(local_c,local_8,local_10,param_1);
  _free(local_c);
  return extraout_EAX;
}


// ==== FUN_004e01a0 @ 0x004e01a0 ====

void FUN_004e01a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) != '\0') {
    return;
  }
  FUN_004e01a0(*(undefined4 *)((int)param_1 + 8));
  if (*(int *)((int)param_1 + 0x14) == 0) {
    *(undefined4 *)((int)param_1 + 0x14) = 0;
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    _free(param_1);
    return;
  }
  FUN_004def50(*(int *)((int)param_1 + 0x14),*(undefined4 *)((int)param_1 + 0x18),
               (int)param_1 + 0x10,param_1);
  _free(*(void **)((int)param_1 + 0x14));
  return;
}


// ==== FUN_004e0210 @ 0x004e0210 ====

void FUN_004e0210(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004e01a0(piVar6[1]);
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
    FUN_004dfe00(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004e02d0 @ 0x004e02d0 ====

void FUN_004e02d0(void)

{
  FUN_004e02e0();
  return;
}


// ==== FUN_004e02e0 @ 0x004e02e0 ====

void FUN_004e02e0(byte param_1)

{
  void *in_ECX;
  
  FUN_004ded00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e0330 @ 0x004e0330 ====

void FUN_004e0330(void)

{
  FUN_0081d1e0();
  FUN_0081d170();
  FUN_0081d100();
  FUN_0081d090();
  FUN_0081d020();
  return;
}


// ==== FUN_004e0380 @ 0x004e0380 ====

void FUN_004e0380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1d48;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_004e03d0 @ 0x004e03d0 ====

void FUN_004e03d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1d48;
  FUN_0081d070();
  FUN_0081d000();
  FUN_0081d0e0();
  FUN_0081d150();
  FUN_0081d230();
  FUN_0081d1c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e0410 @ 0x004e0410 ====

void FUN_004e0410(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1d68;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e0430 @ 0x004e0430 ====

void FUN_004e0430(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x11d);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x11d);
  }
  return;
}


// ==== FUN_004e0450 @ 0x004e0450 ====

void FUN_004e0450(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x11d);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x11d);
  }
  return;
}


// ==== FUN_004e0470 @ 0x004e0470 ====

void FUN_004e0470(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x11d) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x11d) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x11d);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x11d);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x11d);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x11d);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004e04d0 @ 0x004e04d0 ====

undefined4 * FUN_004e04d0(byte *param_1)

{
  int in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x11d) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((*(byte *)(puVar1 + 3) < *param_1) ||
         ((*(byte *)(puVar1 + 3) <= *param_1 && (*(byte *)((int)puVar1 + 0xd) < param_1[1])))) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x11d) == '\0');
  }
  return puVar3;
}


// ==== FUN_004e0520 @ 0x004e0520 ====

void FUN_004e0520(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x11d) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}


// ==== FUN_004e0580 @ 0x004e0580 ====

void FUN_004e0580(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x11d) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)(in_ECX + 4) + 4)) {
    *(int *)(*(int *)(in_ECX + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}


// ==== FUN_004e05e0 @ 0x004e05e0 ====

void FUN_004e05e0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x11d) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x11d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x11d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x11d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x11d) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x11d) == '\0');
    if (*(char *)((int)piVar4 + 0x11d) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004e0650 @ 0x004e0650 ====

void FUN_004e0650(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[1] = param_2;
  puVar2 = in_ECX + 3;
  for (iVar1 = 0x44; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(in_ECX + 0x47) = param_5;
  *(undefined1 *)((int)in_ECX + 0x11d) = 0;
  return;
}


// ==== FUN_004e0690 @ 0x004e0690 ====

void * FUN_004e0690(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009813a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x120);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004e0650(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004e0708 @ 0x004e0708 ====

void Catch_004e0708(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004e0720 @ 0x004e0720 ====

void FUN_004e0720(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009813b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x120);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x47) = 1;
  *(undefined1 *)((int)puVar1 + 0x11d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@004e07b3 @ 0x004e07b3 ====

void Catch_004e07b3(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004e07d0 @ 0x004e07d0 ====

void FUN_004e07d0(int *param_1,byte *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004e04d0(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if ((*(byte *)(iVar1 + 0xc) <= *param_2) &&
       ((*(byte *)(iVar1 + 0xc) < *param_2 || (*(byte *)(iVar1 + 0xd) <= param_2[1])))) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_004e0830 @ 0x004e0830 ====

int FUN_004e0830(int param_1)

{
  int in_ECX;
  
  FUN_004e07d0(&param_1,param_1);
  if (param_1 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  return param_1 + 0x10;
}


// ==== FUN_004e0860 @ 0x004e0860 ====

void FUN_004e0860(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  byte bVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  int unaff_EDI;
  undefined4 *puVar11;
  char *apcStack_444 [5];
  char local_430 [248];
  ulong uStack_338;
  undefined4 auStack_334 [2];
  undefined1 local_32c;
  undefined1 local_32b;
  char local_32a [262];
  char acStack_224 [12];
  char local_218 [244];
  undefined2 auStack_124 [2];
  undefined4 auStack_120 [71];
  
  local_430[0] = '\0';
  FUN_0044a580(local_218,&DAT_009b1d60,s_ChannelList_009b1d50);
  uVar5 = 0;
  do {
    local_430[uVar5] = local_218[uVar5];
    if (local_218[uVar5] == '\0') goto LAB_004e08be;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  local_430[0] = '\0';
LAB_004e08be:
  auStack_334[1] = param_1;
  local_32c = 10;
  local_32b = 0x2c;
  local_32a[0] = '\x01';
  piVar6 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_430);
  uVar5 = (**(code **)(*piVar6 + 8))();
  if (uVar5 < 2) {
LAB_004e0a5a:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar6);
    return;
  }
  uVar5 = 1;
LAB_004e0910:
  pcVar7 = (char *)(**(code **)(*piVar6 + 0x10))(uVar5,0);
  FUN_0044a580(acStack_224,&DAT_009b1d60,&DAT_009b1d5c);
  uVar9 = 0;
  apcStack_444[0] = acStack_224 + -(int)pcVar7;
  do {
    if (*pcVar7 != pcVar7[(int)apcStack_444[0]]) {
      uVar2 = FUN_004753b0(uVar5,0);
      uVar3 = FUN_004753b0(uVar5,1);
      local_32a[0] = '\0';
      auStack_334[0]._0_2_ = CONCAT11(uVar3,uVar2);
      pcVar7 = (char *)(**(code **)(*piVar6 + 0x10))(uVar5,2);
      uStack_338 = inet_addr(pcVar7);
      auStack_334[0]._0_2_ = FUN_00475a90(uVar5,3);
      iVar8 = (**(code **)(*piVar6 + 0x10))(uVar5,4);
      uVar5 = 0;
      goto LAB_004e09e0;
    }
    if (*pcVar7 == '\0') break;
    uVar9 = uVar9 + 1;
    pcVar7 = pcVar7 + 1;
  } while (uVar9 < 0x100);
  goto LAB_004e0a3e;
  while (uVar5 = uVar5 + 1, uVar5 < 0x100) {
LAB_004e09e0:
    cVar1 = (local_32a + uVar5)[iVar8 - (int)local_32a];
    local_32a[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_004e0a03;
  }
  local_32a[0] = '\0';
LAB_004e0a03:
  auStack_124[0] = CONCAT11(uVar3,uVar2);
  puVar10 = auStack_334;
  puVar11 = auStack_120;
  for (iVar8 = 0x43; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar11 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar11 = puVar11 + 1;
  }
  FUN_004e10a0(apcStack_444,auStack_124);
LAB_004e0a3e:
  bVar4 = (char)((uint)unaff_EDI >> 0x18) + 1;
  unaff_EDI = (uint)bVar4 << 0x18;
  uVar5 = (uint)bVar4;
  uVar9 = (**(code **)(*piVar6 + 8))();
  if (uVar9 <= uVar5) goto LAB_004e0a5a;
  goto LAB_004e0910;
}


// ==== FUN_004e0a70 @ 0x004e0a70 ====

void FUN_004e0a70(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b1d78;
  DAT_00b5ac78 = 0;
  FUN_004e1170(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004e0ac0 @ 0x004e0ac0 ====

void FUN_004e0ac0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1d78;
  iVar1 = FUN_004e0720();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x11d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac78 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac78 = in_ECX;
  return;
}


// ==== FUN_004e0b10 @ 0x004e0b10 ====

void FUN_004e0b10(void *param_1)

{
  if (*(char *)((int)param_1 + 0x11d) == '\0') {
    FUN_004e0b10(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004e0b50 @ 0x004e0b50 ====

void FUN_004e0b50(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xf0f0ee < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004e0690(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x11c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x11c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x47] == '\0') {
LAB_004e0c58:
        *(undefined1 *)(*piVar5 + 0x11c) = 1;
        *(undefined1 *)(piVar6 + 0x47) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x11c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004e0520(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x11c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x11c) = 0;
        FUN_004e0580(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x47] == '\0') goto LAB_004e0c58;
      if (piVar7 == (int *)*piVar2) {
        FUN_004e0580(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x11c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x11c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x11d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x11c);
  } while( true );
}


// ==== FUN_004e0d60 @ 0x004e0d60 ====

/* WARNING: Removing unreachable block (ram,0x004e0e92) */
/* WARNING: Removing unreachable block (ram,0x004e0ea2) */
/* WARNING: Removing unreachable block (ram,0x004e0eae) */
/* WARNING: Removing unreachable block (ram,0x004e0eb1) */
/* WARNING: Removing unreachable block (ram,0x004e0e9e) */
/* WARNING: Removing unreachable block (ram,0x004e0ebf) */
/* WARNING: Removing unreachable block (ram,0x004e0ecc) */
/* WARNING: Removing unreachable block (ram,0x004e0ed7) */
/* WARNING: Removing unreachable block (ram,0x004e0ed3) */
/* WARNING: Removing unreachable block (ram,0x004e0ec7) */
/* WARNING: Removing unreachable block (ram,0x004e0eda) */

void FUN_004e0d60(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x11d) != '\0') {
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
  FUN_004e0470();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x11d) == '\0') {
    if (*(char *)(param_2[2] + 0x11d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x11d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x11d) == '\0') {
      piVar3 = (int *)FUN_004e0450(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x11d) == '\0') {
      uVar4 = FUN_004e0430(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x47] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x47] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x47] == '\0') {
            *(undefined1 *)(piVar5 + 0x47) = 1;
            *(undefined1 *)(piVar3 + 0x47) = 0;
            FUN_004e0520(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x11d) == '\0') {
            if ((*(char *)(*piVar5 + 0x11c) == '\x01') && (*(char *)(piVar5[2] + 0x11c) == '\x01'))
            goto LAB_004e100b;
            if (*(char *)(piVar5[2] + 0x11c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x11c) = 1;
              *(undefined1 *)(piVar5 + 0x47) = 0;
              FUN_004e0580(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x47) = (char)piVar3[0x47];
            *(undefined1 *)(piVar3 + 0x47) = 1;
            *(undefined1 *)(piVar5[2] + 0x11c) = 1;
            FUN_004e0520(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x47] == '\0') {
            *(undefined1 *)(piVar5 + 0x47) = 1;
            *(undefined1 *)(piVar3 + 0x47) = 0;
            FUN_004e0580(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x11d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x11c) != '\x01') || (*(char *)(*piVar5 + 0x11c) != '\x01'))
            {
              if (*(char *)(*piVar5 + 0x11c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x11c) = 1;
                *(undefined1 *)(piVar5 + 0x47) = 0;
                FUN_004e0520(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x47) = (char)piVar3[0x47];
              *(undefined1 *)(piVar3 + 0x47) = 1;
              *(undefined1 *)(*piVar5 + 0x11c) = 1;
              FUN_004e0580(piVar3);
              break;
            }
LAB_004e100b:
            *(undefined1 *)(piVar5 + 0x47) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x47) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004e10a0 @ 0x004e10a0 ====

void FUN_004e10a0(undefined4 *param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  pbVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x11d) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < *(byte *)(puVar4 + 3)) ||
         ((*param_2 <= *(byte *)(puVar4 + 3) && (param_2[1] < *(byte *)((int)puVar4 + 0xd))))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x11d) == '\0');
  }
  param_2 = (byte *)puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_004e10fb;
    }
    FUN_004e05e0();
  }
  if ((*pbVar2 <= *(byte *)((int)param_2 + 0xc)) &&
     ((*pbVar2 < *(byte *)((int)param_2 + 0xc) || (pbVar2[1] <= *(byte *)((int)param_2 + 0xd))))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_004e10fb:
  puVar4 = (undefined4 *)FUN_004e0b50(&param_2,local_4,puVar4,pbVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_004e1170 @ 0x004e1170 ====

void FUN_004e1170(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = param_3;
  piVar1 = *(int **)(in_ECX + 4);
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_004e0b10(piVar1[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (param_2 != piVar2) {
    FUN_004e0470();
    FUN_004e0d60(&param_3,param_2);
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004e11f0 @ 0x004e11f0 ====

void FUN_004e11f0(byte param_1)

{
  void *in_ECX;
  
  FUN_004e0a70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e1210 @ 0x004e1210 ====

void FUN_004e1210(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1db4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e1230 @ 0x004e1230 ====

undefined4 * FUN_004e1230(byte *param_1)

{
  int in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x1d) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((*(byte *)(puVar1 + 3) < *param_1) ||
         ((*(byte *)(puVar1 + 3) <= *param_1 && (*(byte *)((int)puVar1 + 0xd) < param_1[1])))) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x1d) == '\0');
  }
  return puVar3;
}


// ==== FUN_004e1270 @ 0x004e1270 ====

void FUN_004e1270(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x1d) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)(in_ECX + 4) + 4)) {
    *(int *)(*(int *)(in_ECX + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}


// ==== FUN_004e12d0 @ 0x004e12d0 ====

void * FUN_004e12d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009813c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x20);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005bb0c0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004e1345 @ 0x004e1345 ====

void Catch_004e1345(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004e1360 @ 0x004e1360 ====

void FUN_004e1360(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009813d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 7) = 1;
  *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@004e13ea @ 0x004e13ea ====

void Catch_004e13ea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004e1400 @ 0x004e1400 ====

void FUN_004e1400(void *param_1)

{
  if (*(char *)((int)param_1 + 0x1d) == '\0') {
    FUN_004e1400(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004e14d0 @ 0x004e14d0 ====

void FUN_004e14d0(undefined4 param_1)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  uint uVar5;
  int *piVar6;
  char *pcVar7;
  ulong uVar8;
  undefined4 in_ECX;
  uint uVar9;
  int unaff_EBX;
  undefined4 unaff_ESI;
  char cVar10;
  undefined4 uStack_238;
  undefined4 local_230;
  undefined2 auStack_22c [2];
  undefined4 uStack_228;
  ulong uStack_224;
  undefined4 uStack_220;
  undefined1 auStack_21c [20];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  local_208[0] = '\0';
  FUN_0044a580(local_100,&DAT_009b1dac,s_LoginList_009b1d88);
  uVar5 = 0;
  do {
    local_208[uVar5] = local_100[uVar5];
    if (local_100[uVar5] == '\0') goto LAB_004e151e;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  local_208[0] = '\0';
LAB_004e151e:
  local_108 = param_1;
  pcVar7 = local_208;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar6 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(pcVar7);
  uVar5 = (**(code **)(*piVar6 + 8))(pcVar7,CONCAT13(1,(int3)unaff_ESI));
  if (1 < uVar5) {
    uVar5 = 1;
    local_230 = in_ECX;
    do {
      cVar10 = (char)((uint)unaff_EBX >> 0x18);
      pcVar7 = (char *)(**(code **)(*piVar6 + 0x10))(uVar5,0);
      FUN_0044a580(local_208 + 0xfc,&DAT_009b1dac,s_LoginList_009b1d88 + 10);
      uVar9 = 0;
      iVar1 = 0xfc - (int)pcVar7;
      do {
        if (*pcVar7 != pcVar7[(int)(local_208 + iVar1)]) {
          uVar2 = FUN_004753b0(uVar5,0);
          uVar3 = FUN_004753b0(uVar5,1);
          uStack_238 = CONCAT22(uStack_238._2_2_,CONCAT11(uVar3,uVar2));
          pcVar7 = (char *)(**(code **)(*piVar6 + 0x10))(uVar5,2);
          uVar8 = inet_addr(pcVar7);
          uVar4 = FUN_00475a90(uVar5,3);
          local_230 = CONCAT22(local_230._2_2_,uVar4);
          uStack_220 = local_230;
          uStack_228 = uStack_238;
          auStack_22c[0] = CONCAT11(uVar3,uVar2);
          uStack_224 = uVar8;
          FUN_004e1d70(auStack_21c,auStack_22c);
          break;
        }
        if (*pcVar7 == '\0') break;
        uVar9 = uVar9 + 1;
        pcVar7 = pcVar7 + 1;
      } while (uVar9 < 0x100);
      unaff_EBX = (uint)(byte)(cVar10 + 1U) << 0x18;
      uVar5 = (uint)(byte)(cVar10 + 1U);
      uVar9 = (**(code **)(*piVar6 + 8))();
    } while (uVar5 < uVar9);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar6);
  return;
}


// ==== FUN_004e1680 @ 0x004e1680 ====

void FUN_004e1680(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b1dc4;
  DAT_00b5ac7c = 0;
  FUN_004e1e40(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004e16d0 @ 0x004e16d0 ====

undefined4 FUN_004e16d0(byte param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint uVar4;
  undefined4 extraout_EAX_01;
  int in_ECX;
  void *_Memory;
  int *piVar5;
  uint uVar6;
  undefined1 *puVar7;
  byte local_24;
  undefined1 local_23;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined1 *local_14;
  int local_10;
  undefined4 local_8;
  uint local_4;
  
  puVar7 = (undefined1 *)0x0;
  if (*(int *)(in_ECX + 0xc) == 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_Empty_Login_ServerList_009b1d94,0x16);
    FUN_00796d50(local_1c);
    if (local_4 < 0x10) {
      return 0;
    }
    _free(local_18);
    return extraout_EAX;
  }
  piVar5 = (int *)**(int **)(in_ECX + 8);
  _Memory = (void *)0x0;
  local_18 = (void *)0x0;
  local_14 = (undefined1 *)0x0;
  local_10 = 0;
  if (piVar5 != *(int **)(in_ECX + 8)) {
    do {
      if (*(byte *)(piVar5 + 3) == param_1) {
        if ((_Memory == (void *)0x0) ||
           ((uint)(local_10 - (int)_Memory) <= (uint)((int)puVar7 - (int)_Memory))) {
          FUN_00469780(puVar7,1,(undefined1 *)((int)piVar5 + 0xd));
          _Memory = local_18;
          puVar7 = local_14;
        }
        else {
          *puVar7 = *(undefined1 *)((int)piVar5 + 0xd);
          local_14 = puVar7 + 1;
          puVar7 = local_14;
        }
      }
      if (*(char *)((int)piVar5 + 0x1d) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x1d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x1d);
          piVar5 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x1d);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x1d);
          piVar3 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x1d);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar5 != *(int **)(in_ECX + 8));
    if (_Memory != (void *)0x0) {
      uVar6 = (int)puVar7 - (int)_Memory;
      if (uVar6 == 0) {
        _free(_Memory);
        return extraout_EAX_00;
      }
      uVar4 = FUN_00797ac0(uVar6);
      local_24 = param_1;
      if (uVar6 <= uVar4) {
        uVar4 = FUN_004d4b70();
      }
      local_23 = *(undefined1 *)(uVar4 + (int)_Memory);
      local_20 = FUN_004e1230(&local_24);
      _free(_Memory);
      return extraout_EAX_01;
    }
  }
  return 0;
}


// ==== FUN_004e1890 @ 0x004e1890 ====

void FUN_004e1890(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1dc4;
  iVar1 = FUN_004e1360();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac7c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac7c = in_ECX;
  return;
}


// ==== FUN_004e18e0 @ 0x004e18e0 ====

void FUN_004e18e0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004e12d0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x1c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x1c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[7] == '\0') {
LAB_004e19e5:
        *(undefined1 *)(*piVar5 + 0x1c) = 1;
        *(undefined1 *)(piVar6 + 7) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x1c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0046a370(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x1c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
        FUN_004e1270(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[7] == '\0') goto LAB_004e19e5;
      if (piVar7 == (int *)*piVar2) {
        FUN_004e1270(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x1c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x1d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x1c);
  } while( true );
}


// ==== FUN_004e1ac0 @ 0x004e1ac0 ====

/* WARNING: Removing unreachable block (ram,0x004e1bdc) */
/* WARNING: Removing unreachable block (ram,0x004e1bec) */
/* WARNING: Removing unreachable block (ram,0x004e1bf5) */
/* WARNING: Removing unreachable block (ram,0x004e1bf8) */
/* WARNING: Removing unreachable block (ram,0x004e1be8) */
/* WARNING: Removing unreachable block (ram,0x004e1c06) */
/* WARNING: Removing unreachable block (ram,0x004e1c13) */
/* WARNING: Removing unreachable block (ram,0x004e1c1e) */
/* WARNING: Removing unreachable block (ram,0x004e1c1a) */
/* WARNING: Removing unreachable block (ram,0x004e1c0e) */
/* WARNING: Removing unreachable block (ram,0x004e1c21) */

void FUN_004e1ac0(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x1d) != '\0') {
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
  FUN_005038e0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x1d) == '\0') {
    if (*(char *)(param_2[2] + 0x1d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x1d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      piVar3 = (int *)FUN_004af910(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x1d) == '\0') {
      uVar4 = FUN_0088f320(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[7] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[7] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[7] == '\0') {
            *(undefined1 *)(piVar5 + 7) = 1;
            *(undefined1 *)(piVar3 + 7) = 0;
            FUN_0046a370(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x1d) == '\0') {
            if ((*(char *)(*piVar5 + 0x1c) == '\x01') && (*(char *)(piVar5[2] + 0x1c) == '\x01'))
            goto LAB_004e1cf0;
            if (*(char *)(piVar5[2] + 0x1c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x1c) = 1;
              *(undefined1 *)(piVar5 + 7) = 0;
              FUN_004e1270(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 7) = (char)piVar3[7];
            *(undefined1 *)(piVar3 + 7) = 1;
            *(undefined1 *)(piVar5[2] + 0x1c) = 1;
            FUN_0046a370(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[7] == '\0') {
            *(undefined1 *)(piVar5 + 7) = 1;
            *(undefined1 *)(piVar3 + 7) = 0;
            FUN_004e1270(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x1d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x1c) != '\x01') || (*(char *)(*piVar5 + 0x1c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x1c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x1c) = 1;
                *(undefined1 *)(piVar5 + 7) = 0;
                FUN_0046a370(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 7) = (char)piVar3[7];
              *(undefined1 *)(piVar3 + 7) = 1;
              *(undefined1 *)(*piVar5 + 0x1c) = 1;
              FUN_004e1270(piVar3);
              break;
            }
LAB_004e1cf0:
            *(undefined1 *)(piVar5 + 7) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 7) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004e1d70 @ 0x004e1d70 ====

void FUN_004e1d70(undefined4 *param_1,byte *param_2)

{
  bool bVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_4;
  
  pbVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_2 < *(byte *)(puVar4 + 3)) ||
         ((*param_2 <= *(byte *)(puVar4 + 3) && (param_2[1] < *(byte *)((int)puVar4 + 0xd))))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x1d) == '\0');
  }
  param_2 = (byte *)puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      local_4 = 1;
      goto LAB_004e1dc5;
    }
    FUN_0046a3c0();
  }
  if ((*pbVar2 <= *(byte *)((int)param_2 + 0xc)) &&
     ((*pbVar2 < *(byte *)((int)param_2 + 0xc) || (pbVar2[1] <= *(byte *)((int)param_2 + 0xd))))) {
    *param_1 = param_2;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
LAB_004e1dc5:
  puVar4 = (undefined4 *)FUN_004e18e0(&param_2,local_4,puVar4,pbVar2);
  *param_1 = *puVar4;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_004e1e40 @ 0x004e1e40 ====

void FUN_004e1e40(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004e1400(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x1d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x1d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x1d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x1d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x1d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004e1ac0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004e1f00 @ 0x004e1f00 ====

void FUN_004e1f00(undefined1 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1) <= (uint)(*(int *)(in_ECX + 8) - iVar1))) {
    FUN_00469780(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined1 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined1 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_004e1f50 @ 0x004e1f50 ====

void FUN_004e1f50(byte param_1)

{
  void *in_ECX;
  
  FUN_004e1680();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e1f70 @ 0x004e1f70 ====

void FUN_004e1f70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1e10;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e1f90 @ 0x004e1f90 ====

void FUN_004e1f90(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  cVar1 = *(char *)(iVar2 + 0x111);
  while (cVar1 == '\0') {
    iVar2 = *(int *)(iVar2 + 8);
    cVar1 = *(char *)(iVar2 + 0x111);
  }
  return;
}


// ==== FUN_004e1fb0 @ 0x004e1fb0 ====

void FUN_004e1fb0(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x111);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x111);
  }
  return;
}


// ==== FUN_004e1fd0 @ 0x004e1fd0 ====

void FUN_004e1fd0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x111) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x111) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x111);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x111);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x111);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x111);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_004e2030 @ 0x004e2030 ====

void FUN_004e2030(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x111) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}


// ==== FUN_004e2090 @ 0x004e2090 ====

void FUN_004e2090(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x111) == '\0') {
    *(int **)(*(int *)(iVar1 + 8) + 4) = param_1;
  }
  *(int *)(iVar1 + 4) = param_1[1];
  if (param_1 == *(int **)(*(int *)(in_ECX + 4) + 4)) {
    *(int *)(*(int *)(in_ECX + 4) + 4) = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  piVar2 = (int *)param_1[1];
  if (param_1 == (int *)piVar2[2]) {
    piVar2[2] = iVar1;
    *(int **)(iVar1 + 8) = param_1;
    param_1[1] = iVar1;
    return;
  }
  *piVar2 = iVar1;
  *(int **)(iVar1 + 8) = param_1;
  param_1[1] = iVar1;
  return;
}


// ==== FUN_004e20f0 @ 0x004e20f0 ====

void FUN_004e20f0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x111) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x111) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x111);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x111);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x111) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x111) == '\0');
    if (*(char *)((int)piVar4 + 0x111) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_004e2160 @ 0x004e2160 ====

void FUN_004e2160(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[1] = param_2;
  puVar2 = in_ECX + 3;
  for (iVar1 = 0x41; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(in_ECX + 0x44) = param_5;
  *(undefined1 *)((int)in_ECX + 0x111) = 0;
  return;
}


// ==== FUN_004e21a0 @ 0x004e21a0 ====

void * FUN_004e21a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009813e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x114);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004e2160(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004e2218 @ 0x004e2218 ====

void Catch_004e2218(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004e2230 @ 0x004e2230 ====

void FUN_004e2230(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009813f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x114);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x44) = 1;
  *(undefined1 *)((int)puVar1 + 0x111) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@004e22c3 @ 0x004e22c3 ====

void Catch_004e22c3(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004e22e0 @ 0x004e22e0 ====

char FUN_004e22e0(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    return '\x02';
  }
  iVar1 = FUN_00403620(0,*(int *)(param_1 + 0x14),s_NORTH_009b1df8,5);
  if (iVar1 == 0) {
    return '\0';
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),s_SOUTH_009b1e00,5);
  return (iVar1 != 0) + '\x01';
}


// ==== FUN_004e2330 @ 0x004e2330 ====

int FUN_004e2330(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_004e27d0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return local_4 + 0xd;
}


// ==== FUN_004e2360 @ 0x004e2360 ====

void FUN_004e2360(undefined4 param_1)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint unaff_EBX;
  int unaff_ESI;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 uStack_854;
  uint auStack_850 [2];
  undefined1 local_848 [4];
  void *pvStack_844;
  undefined4 uStack_834;
  uint uStack_830;
  undefined4 uStack_82c;
  undefined1 uStack_73b;
  undefined1 uStack_72a;
  char local_718 [256];
  undefined4 local_618;
  undefined1 local_614;
  undefined1 local_613;
  undefined1 local_612;
  char local_60c [245];
  undefined4 uStack_517;
  char acStack_414 [240];
  undefined1 auStack_324 [272];
  char acStack_214 [256];
  undefined1 auStack_114 [272];
  
  local_718[0] = '\0';
  FUN_0044a580(local_60c,&DAT_009b1e08,s_ServerGroup_009b1dd4);
  uVar4 = 0;
  do {
    local_718[uVar4] = local_60c[uVar4];
    if (local_60c[uVar4] == '\0') goto LAB_004e23c4;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  local_718[0] = '\0';
LAB_004e23c4:
  local_618 = param_1;
  local_614 = 10;
  local_613 = 0x2c;
  local_612 = 1;
  piVar5 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_718);
  uStack_854 = CONCAT13(1,(undefined3)uStack_854);
  uVar4 = (**(code **)(*piVar5 + 8))();
  if (uVar4 < 2) {
LAB_004e26f8:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar5);
    return;
  }
  auStack_850[0] = 1;
LAB_004e2418:
  pcVar6 = (char *)(**(code **)(*piVar5 + 0x10))(auStack_850[0],0);
  FUN_0044a580(&local_618,&DAT_009b1e08,&DAT_009b1de0);
  iVar10 = -(int)pcVar6;
  auStack_850[0] = 0;
  pcVar7 = pcVar6;
  do {
    if (*pcVar7 != pcVar7[(int)(local_718 + iVar10 + 0x100)]) {
      FUN_0044a580(acStack_414,&DAT_009b1e08,s_TESTSERVER_009b1de4);
      auStack_850[0] = 0;
      pcVar7 = pcVar6;
      goto LAB_004e24b0;
    }
    if (*pcVar7 == '\0') break;
    auStack_850[0] = auStack_850[0] + 1;
    pcVar7 = pcVar7 + 1;
  } while (auStack_850[0] < 0x100);
  goto LAB_004e26d8;
  while( true ) {
    auStack_850[0] = auStack_850[0] + 1;
    pcVar7 = pcVar7 + 1;
    if (0xff < auStack_850[0]) break;
LAB_004e24b0:
    if (*pcVar7 != pcVar7[(int)(acStack_414 + iVar10)]) {
      FUN_0044a580(acStack_214,&DAT_009b1e08,&DAT_009b1df0);
      uVar4 = 0;
      goto LAB_004e2501;
    }
    if (*pcVar7 == '\0') break;
  }
  *(undefined1 *)(uStack_854 + 4) = 1;
  goto LAB_004e26d8;
  while( true ) {
    uVar4 = uVar4 + 1;
    pcVar6 = pcVar6 + 1;
    if (0xff < uVar4) break;
LAB_004e2501:
    if (*pcVar6 != pcVar6[(int)(acStack_214 + iVar10)]) {
      uStack_82c._1_1_ = 0;
      uStack_82c._0_1_ = FUN_004753b0(unaff_EBX,0);
      iVar10 = (**(code **)(*piVar5 + 0x10))(unaff_EBX,1);
      uVar4 = 0;
      goto LAB_004e25e0;
    }
    if (*pcVar6 == '\0') break;
  }
  pcVar6 = (char *)(**(code **)(*piVar5 + 0x10))(unaff_EBX,1);
  uStack_830 = 0xf;
  uStack_834 = 0;
  pvStack_844 = (void *)((uint)pvStack_844 & 0xffffff00);
  pcVar7 = pcVar6;
  do {
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(pcVar6,(int)pcVar7 - (int)(pcVar6 + 1));
  uVar8 = FUN_004e22e0(local_848);
  *(undefined4 *)(uStack_854 + 0x18) = uVar8;
  uVar1 = FUN_004753b0(unaff_EBX,2);
  *(undefined1 *)(uStack_854 + 0x14) = uVar1;
  if (0xf < uStack_830) {
    _free(pvStack_844);
    return;
  }
  uStack_830 = 0xf;
  uStack_834 = 0;
  pvStack_844 = (void *)((uint)pvStack_844 & 0xffffff00);
  goto LAB_004e26d8;
  while (uVar4 = uVar4 + 1, uVar4 < 0x100) {
LAB_004e25e0:
    pcVar7 = (char *)((int)&uStack_834 + uVar4 + 1);
    cVar2 = pcVar7[iVar10 - ((int)&uStack_834 + 1)];
    *pcVar7 = cVar2;
    if (cVar2 == '\0') goto LAB_004e25fd;
  }
  uStack_834._0_2_ = (ushort)(byte)uStack_834;
LAB_004e25fd:
  (**(code **)(*piVar5 + 0x10))(unaff_EBX,2);
  FUN_0044a580(auStack_324,&DAT_009b1e08,&DAT_009b1df5);
  cVar2 = FUN_0044a440(auStack_324);
  if (cVar2 == '\0') {
    uVar8 = 2;
  }
  else {
    uVar8 = 0;
  }
  uStack_73b = FUN_004753b0(unaff_EBX,uVar8);
  (**(code **)(*piVar5 + 0x10))(unaff_EBX,3);
  FUN_0044a580(auStack_114,&DAT_009b1e08,&DAT_0099cf70);
  cVar2 = FUN_0044a440(auStack_114);
  if (cVar2 == '\0') {
    uStack_72a = FUN_004774b0(unaff_EBX,3);
  }
  else {
    uStack_72a = 0;
  }
  local_60c[0xf4] = (undefined1)uStack_82c;
  puVar9 = &uStack_82c;
  puVar11 = &uStack_517;
  for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  *(undefined2 *)puVar11 = *(undefined2 *)puVar9;
  *(undefined1 *)((int)puVar11 + 2) = *(undefined1 *)((int)puVar9 + 2);
  FUN_004e2de0(auStack_850,local_60c + 0xf4);
LAB_004e26d8:
  bVar3 = (char)((uint)unaff_ESI >> 0x18) + 1;
  unaff_EBX = (uint)bVar3;
  unaff_ESI = (uint)bVar3 << 0x18;
  uVar4 = (**(code **)(*piVar5 + 8))();
  if (uVar4 <= unaff_EBX) goto LAB_004e26f8;
  goto LAB_004e2418;
}


// ==== FUN_004e2710 @ 0x004e2710 ====

void FUN_004e2710(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b1e30;
  DAT_00b5ac80 = 0;
  FUN_004e2ea0(local_4,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_004e2760 @ 0x004e2760 ====

void FUN_004e2760(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1e30;
  *(undefined1 *)(in_ECX + 1) = 0;
  iVar1 = FUN_004e2230();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x111) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[6] = 2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac80 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac80 = in_ECX;
  return;
}


// ==== FUN_004e27d0 @ 0x004e27d0 ====

void FUN_004e27d0(undefined4 *param_1,byte *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x111) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x111) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(byte *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_004e2850 @ 0x004e2850 ====

void FUN_004e2850(void *param_1)

{
  if (*(char *)((int)param_1 + 0x111) == '\0') {
    FUN_004e2850(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004e2890 @ 0x004e2890 ====

void FUN_004e2890(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xfc0fbe < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004e21a0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x110);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x110) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x44] == '\0') {
LAB_004e2998:
        *(undefined1 *)(*piVar5 + 0x110) = 1;
        *(undefined1 *)(piVar6 + 0x44) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x110) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004e2030(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x110) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x110) = 0;
        FUN_004e2090(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x44] == '\0') goto LAB_004e2998;
      if (piVar7 == (int *)*piVar2) {
        FUN_004e2090(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x110) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x110) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x111) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x110);
  } while( true );
}


// ==== FUN_004e2aa0 @ 0x004e2aa0 ====

/* WARNING: Removing unreachable block (ram,0x004e2bd2) */
/* WARNING: Removing unreachable block (ram,0x004e2be2) */
/* WARNING: Removing unreachable block (ram,0x004e2bee) */
/* WARNING: Removing unreachable block (ram,0x004e2bf1) */
/* WARNING: Removing unreachable block (ram,0x004e2bde) */
/* WARNING: Removing unreachable block (ram,0x004e2bff) */
/* WARNING: Removing unreachable block (ram,0x004e2c0c) */
/* WARNING: Removing unreachable block (ram,0x004e2c17) */
/* WARNING: Removing unreachable block (ram,0x004e2c13) */
/* WARNING: Removing unreachable block (ram,0x004e2c07) */
/* WARNING: Removing unreachable block (ram,0x004e2c1a) */

void FUN_004e2aa0(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x111) != '\0') {
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
  FUN_004e1fd0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x111) == '\0') {
    if (*(char *)(param_2[2] + 0x111) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x111) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x111) == '\0') {
      piVar3 = (int *)FUN_004e1fb0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x111) == '\0') {
      uVar4 = FUN_004e1f90(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x44] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x44] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x44] == '\0') {
            *(undefined1 *)(piVar5 + 0x44) = 1;
            *(undefined1 *)(piVar3 + 0x44) = 0;
            FUN_004e2030(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x111) == '\0') {
            if ((*(char *)(*piVar5 + 0x110) == '\x01') && (*(char *)(piVar5[2] + 0x110) == '\x01'))
            goto LAB_004e2d4b;
            if (*(char *)(piVar5[2] + 0x110) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x110) = 1;
              *(undefined1 *)(piVar5 + 0x44) = 0;
              FUN_004e2090(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x44) = (char)piVar3[0x44];
            *(undefined1 *)(piVar3 + 0x44) = 1;
            *(undefined1 *)(piVar5[2] + 0x110) = 1;
            FUN_004e2030(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x44] == '\0') {
            *(undefined1 *)(piVar5 + 0x44) = 1;
            *(undefined1 *)(piVar3 + 0x44) = 0;
            FUN_004e2090(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x111) == '\0') {
            if ((*(char *)(piVar5[2] + 0x110) != '\x01') || (*(char *)(*piVar5 + 0x110) != '\x01'))
            {
              if (*(char *)(*piVar5 + 0x110) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x110) = 1;
                *(undefined1 *)(piVar5 + 0x44) = 0;
                FUN_004e2030(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x44) = (char)piVar3[0x44];
              *(undefined1 *)(piVar3 + 0x44) = 1;
              *(undefined1 *)(*piVar5 + 0x110) = 1;
              FUN_004e2090(piVar3);
              break;
            }
LAB_004e2d4b:
            *(undefined1 *)(piVar5 + 0x44) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x44) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004e2de0 @ 0x004e2de0 ====

void FUN_004e2de0(undefined4 *param_1,byte *param_2)

{
  undefined4 uVar1;
  byte *pbVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  bool bVar5;
  
  pbVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x111) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      bVar5 = *param_2 < *(byte *)(puVar4 + 3);
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x111) == '\0');
  }
  param_2 = (byte *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004e2890(&param_2,1,puVar4,pbVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004e20f0();
  }
  if (*(byte *)((int)param_2 + 0xc) < *pbVar2) {
    puVar4 = (undefined4 *)FUN_004e2890(&param_2,bVar5,puVar4,pbVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004e2ea0 @ 0x004e2ea0 ====

void FUN_004e2ea0(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = param_3;
  piVar1 = *(int **)(in_ECX + 4);
  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {
    FUN_004e2850(piVar1[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (param_2 != piVar2) {
    FUN_004e1fd0();
    FUN_004e2aa0(&param_3,param_2);
  }
  *param_1 = param_2;
  return;
}


// ==== FUN_004e2f20 @ 0x004e2f20 ====

void FUN_004e2f20(byte param_1)

{
  void *in_ECX;
  
  FUN_004e2710();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e2f40 @ 0x004e2f40 ====

void FUN_004e2f40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1e50;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e2f60 @ 0x004e2f60 ====

void FUN_004e2f60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  *(undefined1 *)(in_ECX + 4) = param_5;
  *(undefined1 *)((int)in_ECX + 0x11) = 0;
  return;
}


// ==== FUN_004e2f90 @ 0x004e2f90 ====

void FUN_004e2f90(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x11) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}


// ==== FUN_004e2fe0 @ 0x004e2fe0 ====

void FUN_004e2fe0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x11) == '\0') {
    FUN_004e2fe0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_004e3020 @ 0x004e3020 ====

void * FUN_004e3020(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981400;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x14);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004e2f60(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004e3095 @ 0x004e3095 ====

void Catch_004e3095(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004e30b0 @ 0x004e30b0 ====

void FUN_004e30b0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981410;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 4) = 1;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@004e313a @ 0x004e313a ====

void Catch_004e313a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004e3150 @ 0x004e3150 ====

undefined4 FUN_004e3150(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    cVar5 = (**(code **)(*(int *)puVar2[3] + 4))(param_1);
    if (cVar5 == '\x01') break;
    if (*(char *)((int)puVar2 + 0x11) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x11) == '\0') {
        cVar5 = *(char *)((int)*puVar3 + 0x11);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar5 == '\0') {
          cVar5 = *(char *)((int)*puVar3 + 0x11);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar5 = *(char *)((int)puVar2[1] + 0x11);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar5 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar5 = *(char *)((int)puVar2[1] + 0x11);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  return 1;
}


// ==== FUN_004e31d0 @ 0x004e31d0 ====

undefined4 FUN_004e31d0(undefined1 param_1)

{
  uint in_ECX;
  uint local_4;
  
  local_4 = in_ECX;
  FUN_004e3300(&local_4,&param_1);
  if (local_4 == *(uint *)(in_ECX + 8)) {
    return 0;
  }
  FUN_004e3370(&param_1,local_4);
  return 1;
}


// ==== FUN_004e3210 @ 0x004e3210 ====

undefined4 FUN_004e3210(undefined1 param_1)

{
  int in_ECX;
  int local_8 [2];
  
  FUN_004e3300(local_8,&param_1);
  if (local_8[0] == *(int *)(in_ECX + 8)) {
    FUN_004e38c0(local_8,&param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_004e3260 @ 0x004e3260 ====

void FUN_004e3260(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b1e64;
  DAT_00b5ac18 = 0;
  FUN_004e3800(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004e32b0 @ 0x004e32b0 ====

void FUN_004e32b0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1e64;
  iVar1 = FUN_004e30b0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac18 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac18 = in_ECX;
  return;
}


// ==== FUN_004e3300 @ 0x004e3300 ====

void FUN_004e3300(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x11) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x11) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_004e3370 @ 0x004e3370 ====

/* WARNING: Removing unreachable block (ram,0x004e348c) */
/* WARNING: Removing unreachable block (ram,0x004e349c) */
/* WARNING: Removing unreachable block (ram,0x004e34a5) */
/* WARNING: Removing unreachable block (ram,0x004e34a8) */
/* WARNING: Removing unreachable block (ram,0x004e3498) */
/* WARNING: Removing unreachable block (ram,0x004e34b6) */
/* WARNING: Removing unreachable block (ram,0x004e34c3) */
/* WARNING: Removing unreachable block (ram,0x004e34ce) */
/* WARNING: Removing unreachable block (ram,0x004e34ca) */
/* WARNING: Removing unreachable block (ram,0x004e34be) */
/* WARNING: Removing unreachable block (ram,0x004e34d1) */

void FUN_004e3370(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x11) != '\0') {
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
  FUN_007519c0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x11) == '\0') {
    if (*(char *)(param_2[2] + 0x11) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x11) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x11) == '\0') {
      piVar3 = (int *)FUN_004670e0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x11) == '\0') {
      uVar4 = FUN_00751930(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[4] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[4] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[4] == '\0') {
            *(undefined1 *)(piVar5 + 4) = 1;
            *(undefined1 *)(piVar3 + 4) = 0;
            FUN_004e2f90(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x11) == '\0') {
            if ((*(char *)(*piVar5 + 0x10) == '\x01') && (*(char *)(piVar5[2] + 0x10) == '\x01'))
            goto LAB_004e35a0;
            if (*(char *)(piVar5[2] + 0x10) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x10) = 1;
              *(undefined1 *)(piVar5 + 4) = 0;
              FUN_00467140(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 4) = (char)piVar3[4];
            *(undefined1 *)(piVar3 + 4) = 1;
            *(undefined1 *)(piVar5[2] + 0x10) = 1;
            FUN_004e2f90(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[4] == '\0') {
            *(undefined1 *)(piVar5 + 4) = 1;
            *(undefined1 *)(piVar3 + 4) = 0;
            FUN_00467140(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x11) == '\0') {
            if ((*(char *)(piVar5[2] + 0x10) != '\x01') || (*(char *)(*piVar5 + 0x10) != '\x01')) {
              if (*(char *)(*piVar5 + 0x10) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x10) = 1;
                *(undefined1 *)(piVar5 + 4) = 0;
                FUN_004e2f90(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 4) = (char)piVar3[4];
              *(undefined1 *)(piVar3 + 4) = 1;
              *(undefined1 *)(*piVar5 + 0x10) = 1;
              FUN_00467140(piVar3);
              break;
            }
LAB_004e35a0:
            *(undefined1 *)(piVar5 + 4) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 4) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_004e3620 @ 0x004e3620 ====

void FUN_004e3620(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x3ffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004e3020(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x10);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x10) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[4] == '\0') {
LAB_004e3725:
        *(undefined1 *)(*piVar5 + 0x10) = 1;
        *(undefined1 *)(piVar6 + 4) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x10) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004e2f90(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x10) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x10) = 0;
        FUN_00467140(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[4] == '\0') goto LAB_004e3725;
      if (piVar7 == (int *)*piVar2) {
        FUN_00467140(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x10) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x10) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x11) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x10);
  } while( true );
}


// ==== FUN_004e3800 @ 0x004e3800 ====

void FUN_004e3800(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004e2fe0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x11) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x11) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x11);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x11);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x11);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x11);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_004e3370(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004e38c0 @ 0x004e38c0 ====

void FUN_004e38c0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x11) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x11) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004e3620(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00751950();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004e3620(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004e3980 @ 0x004e3980 ====

void FUN_004e3980(byte param_1)

{
  void *in_ECX;
  
  FUN_004e3260();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e39a0 @ 0x004e39a0 ====

void FUN_004e39a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1e78;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e39c0 @ 0x004e39c0 ====

void FUN_004e39c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1ea0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a808 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a808 = in_ECX;
  return;
}


// ==== FUN_004e39f0 @ 0x004e39f0 ====

void FUN_004e39f0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 4));
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))(param_1);
    }
  }
  return;
}


// ==== FUN_004e3a20 @ 0x004e3a20 ====

void FUN_004e3a20(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 4));
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x18))(param_1);
    }
  }
  return;
}


// ==== FUN_004e3a50 @ 0x004e3a50 ====

void FUN_004e3a50(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 4));
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x20))(param_1);
    }
  }
  return;
}


// ==== FUN_004e3a80 @ 0x004e3a80 ====

void FUN_004e3a80(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 4));
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(param_1);
    }
  }
  return;
}


// ==== FUN_004e3ab0 @ 0x004e3ab0 ====

void FUN_004e3ab0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 4));
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x24))(param_1);
    }
  }
  return;
}


// ==== FUN_004e3ae0 @ 0x004e3ae0 ====

void FUN_004e3ae0(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 4));
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x28))(param_1);
    }
  }
  return;
}


// ==== FUN_004e3b10 @ 0x004e3b10 ====

void FUN_004e3b10(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 4));
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x2c))();
    }
  }
  return;
}


// ==== FUN_004e3b60 @ 0x004e3b60 ====

void FUN_004e3b60(undefined4 param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined1 auStack_1a [26];
  
  if ((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) {
    piVar4 = (int *)(**(code **)(*param_3 + 0x14))();
    iVar5 = (**(code **)(*piVar4 + 0x24))();
    if (iVar5 != 0) {
      puVar6 = (undefined4 *)(**(code **)(*param_2 + 4))();
      uVar1 = *puVar6;
      iVar2 = *param_2;
      uVar7 = (**(code **)(*DAT_00b5ad04 + 8))(uVar1);
      (**(code **)(iVar2 + 0x78))(uVar7);
      piVar4 = (int *)FUN_00803725(iVar5,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                   &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
      if (piVar4 != (int *)0x0) {
        uVar7 = (**(code **)(*piVar4 + 0x1c))(0);
        FUN_00401830(uVar7);
        if (DAT_00b5a7b4 == (int *)0x0) {
          (**(code **)(*param_2 + 0x80))(uVar1);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        uVar7 = (**(code **)(*DAT_00b5a97c + 0xc))();
        cVar3 = (**(code **)(*DAT_00b5a7b4 + 0x28))(auStack_1a + -0xe);
        if (cVar3 == '\0') {
          (**(code **)(*param_2 + 0x80))(uVar1);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        (**(code **)(*param_2 + 0x80))(uVar7);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  return;
}


// ==== FUN_004e3c70 @ 0x004e3c70 ====

void FUN_004e3c70(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  float unaff_EDI;
  undefined4 *puVar6;
  undefined4 unaff_retaddr;
  undefined4 auStack_2c [11];
  
  if (param_2 != (int *)0x0) {
    puVar1 = (undefined4 *)(**(code **)(*param_2 + 4))();
    uVar4 = *puVar1;
    piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(uVar4);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0xc))();
      if (iVar3 == 0) {
        FUN_004e3b60(unaff_retaddr,param_2,piVar2);
        return;
      }
      piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
      iVar3 = (**(code **)(*piVar2 + 0x24))();
      if (((iVar3 != 0) && (*(int *)(iVar3 + 0x50) != 0)) &&
         (piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 0x50) + 0x14))(0), piVar2 != (int *)0x0))
      {
        puVar1 = (undefined4 *)(**(code **)(*piVar2 + 0x18))();
        iVar3 = *param_2;
        puVar6 = auStack_2c + -3;
        for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar6 = *puVar1;
          puVar1 = puVar1 + 1;
          puVar6 = puVar6 + 1;
        }
        (**(code **)(iVar3 + 0x2c))((int)unaff_EDI);
        iVar3 = *param_2;
        uVar4 = (**(code **)(*DAT_00b5ad04 + 8))(uVar4);
        (**(code **)(iVar3 + 0x78))(uVar4);
      }
    }
  }
  return;
}


// ==== FUN_004e3d30 @ 0x004e3d30 ====

void FUN_004e3d30(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5a808 = 0;
  *in_ECX = &PTR_FUN_009b1e78;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e3d60 @ 0x004e3d60 ====

void FUN_004e3d60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1f24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e3d80 @ 0x004e3d80 ====

void FUN_004e3d80(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
  }
  return;
}


// ==== FUN_004e3da0 @ 0x004e3da0 ====

int FUN_004e3da0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981420;
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


// ==== Catch@004e3e06 @ 0x004e3e06 ====

void Catch_004e3e06(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004e3e10 @ 0x004e3e10 ====

void FUN_004e3e10(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981430;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 8) = 1;
  *(undefined1 *)((int)puVar1 + 0x21) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@004e3e9a @ 0x004e3e9a ====

void Catch_004e3e9a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004e3eb0 @ 0x004e3eb0 ====

void FUN_004e3eb0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981440;
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


// ==== Catch@004e3f16 @ 0x004e3f16 ====

void Catch_004e3f16(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004e3f20 @ 0x004e3f20 ====

void FUN_004e3f20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004e3da0(param_1,param_2,param_3);
  return;
}


// ==== FUN_004e3f40 @ 0x004e3f40 ====

void FUN_004e3f40(undefined1 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00558e70(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 8)) {
    puVar1 = *(undefined4 **)(local_4 + 0x18);
    for (puVar2 = *(undefined4 **)(local_4 + 0x14); puVar2 != puVar1; puVar2 = puVar2 + 3) {
      (**(code **)(*(int *)*puVar2 + 0x24))();
      *(undefined1 *)(puVar2 + 2) = 0;
    }
  }
  return;
}


// ==== FUN_004e3f90 @ 0x004e3f90 ====

undefined4 FUN_004e3f90(uint param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  undefined4 *puVar5;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00558e70(&local_4,&param_1);
  iVar2 = param_2;
  if (local_4 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  puVar5 = *(undefined4 **)(local_4 + 0x14);
  param_1 = 0;
  if ((puVar5 == (undefined4 *)0x0) ||
     (uVar4 = param_3, (uint)((*(int *)(local_4 + 0x18) - (int)puVar5) / 0xc) <= param_3)) {
    uVar4 = 0;
  }
  puVar1 = *(undefined4 **)(local_4 + 0x18);
  do {
    if (puVar5 == puVar1) {
      return 0;
    }
    iVar3 = (**(code **)(*(int *)*puVar5 + 0x20))();
    if (iVar3 == iVar2) {
      if (uVar4 == param_1) {
        return *puVar5;
      }
      param_1 = param_1 + 1;
    }
    puVar5 = puVar5 + 3;
  } while( true );
}


// ==== FUN_004e4030 @ 0x004e4030 ====

undefined4 * FUN_004e4030(uint param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  undefined4 *puVar5;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00558e70(&local_4,&param_1);
  iVar2 = param_2;
  if (local_4 == *(int *)(in_ECX + 8)) {
    return (undefined4 *)0x0;
  }
  puVar5 = *(undefined4 **)(local_4 + 0x14);
  param_1 = 0;
  if ((puVar5 == (undefined4 *)0x0) ||
     (uVar4 = param_3, (uint)((*(int *)(local_4 + 0x18) - (int)puVar5) / 0xc) <= param_3)) {
    uVar4 = 0;
  }
  puVar1 = *(undefined4 **)(local_4 + 0x18);
  do {
    if (puVar5 == puVar1) {
      return (undefined4 *)0x0;
    }
    iVar3 = (**(code **)(*(int *)*puVar5 + 0x20))();
    if (iVar3 == iVar2) {
      if (uVar4 == param_1) {
        return puVar5;
      }
      param_1 = param_1 + 1;
    }
    puVar5 = puVar5 + 3;
  } while( true );
}


// ==== FUN_004e40d0 @ 0x004e40d0 ====

undefined4 * FUN_004e40d0(undefined1 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00558e70(&local_4,&param_1);
  iVar2 = param_2;
  if (local_4 == *(int *)(in_ECX + 8)) {
    return (undefined4 *)0x0;
  }
  puVar4 = *(undefined4 **)(local_4 + 0x14);
  puVar1 = *(undefined4 **)(local_4 + 0x18);
  while( true ) {
    if (puVar4 == puVar1) {
      return (undefined4 *)0x0;
    }
    iVar3 = (**(code **)(*(int *)*puVar4 + 0x1c))();
    if (iVar3 == iVar2) break;
    puVar4 = puVar4 + 3;
  }
  return puVar4;
}


// ==== FUN_004e4130 @ 0x004e4130 ====

void FUN_004e4130(undefined1 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00558e70(&local_4,&param_1);
  iVar2 = param_2;
  if (local_4 != *(int *)(in_ECX + 8)) {
    puVar1 = *(undefined4 **)(local_4 + 0x18);
    for (puVar4 = *(undefined4 **)(local_4 + 0x14); puVar4 != puVar1; puVar4 = puVar4 + 3) {
      iVar3 = (**(code **)(*(int *)*puVar4 + 0x20))();
      if (iVar3 == iVar2) {
        (**(code **)(*(int *)*puVar4 + 0x18))();
        *(undefined1 *)(puVar4 + 2) = 0;
      }
    }
  }
  return;
}


// ==== FUN_004e4190 @ 0x004e4190 ====

void FUN_004e4190(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  void *local_3c;
  undefined1 local_38 [4];
  void *local_34;
  uint uStack_28;
  undefined4 uStack_24;
  void *local_20;
  undefined1 local_1c [16];
  uint uStack_c;
  
  FUN_00558e70(&local_3c,&param_1);
  if (local_3c == *(void **)(in_ECX + 8)) {
    FUN_00401740(s_Not_Find___x__Effect_009b1edc,0x15);
    uVar3 = FUN_00404230(local_38);
    FUN_00403e50(uVar3);
    if ((void *)0xf < local_20) {
      _free(local_34);
      return;
    }
  }
  else {
    uVar5 = 0;
    FUN_00401740(s___x__Total__d___009b1ef4,0xf);
    FUN_00404230(local_1c);
    puVar4 = *(undefined4 **)((int)local_3c + 0x14);
    puVar1 = *(undefined4 **)((int)local_3c + 0x18);
    local_3c = (void *)0x0;
    for (; puVar4 != puVar1; puVar4 = puVar4 + 3) {
      uVar2 = (**(code **)(*(int *)*puVar4 + 0x20))();
      (**(code **)(*(int *)*puVar4 + 0x1c))(uVar2);
      uVar5 = 0;
      FUN_00401740(s___x__d__009b1f04,9);
      uVar3 = FUN_00404230(local_38);
      FUN_00401ff0(uVar3,0,0xffffffff);
      if ((void *)0xf < local_20) {
        _free(local_34);
        return;
      }
      local_20 = (void *)0xf;
      uStack_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      if (((uint)local_3c & 3) == 0) {
        FUN_004020e0(&DAT_009b1f10,1);
      }
      local_3c = (void *)((int)local_3c + 1);
    }
    uVar6 = 0;
    FUN_00401740(s_MEffect__d__009b1f14,0xb);
    uVar3 = FUN_00404230(local_38,uVar5,uVar6);
    (**(code **)(*DAT_00b5a688 + 8))(uVar3,local_1c);
    if (0xf < uStack_28) {
      _free(local_3c);
      return;
    }
    if (0xf < uStack_c) {
      _free(local_20);
      return;
    }
  }
  return;
}


// ==== FUN_004e4380 @ 0x004e4380 ====

void FUN_004e4380(undefined1 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  int *piVar3;
  int local_24;
  void *local_20 [5];
  uint uStack_c;
  
  local_20[0] = (void *)(in_ECX + 4);
  FUN_00558e70(&local_24,&param_1);
  if (local_24 != *(int *)(in_ECX + 8)) {
    piVar1 = *(int **)(local_24 + 0x18);
    for (piVar3 = *(int **)(local_24 + 0x14); piVar3 != piVar1; piVar3 = piVar3 + 3) {
      if ((undefined4 *)*piVar3 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar3)(1);
      }
    }
    if (*(void **)(local_24 + 0x14) != (void *)0x0) {
      _free(*(void **)(local_24 + 0x14));
      return;
    }
    *(undefined4 *)(local_24 + 0x14) = 0;
    *(undefined4 *)(local_24 + 0x18) = 0;
    *(undefined4 *)(local_24 + 0x1c) = 0;
    FUN_004e4e50(local_20,local_24);
    FUN_00401740(s__Effect__x__Clear_009b1ec8,0x12);
    uVar2 = FUN_00404230(&local_24);
    FUN_00403e50(uVar2);
    if (0xf < uStack_c) {
      _free(local_20[0]);
      return;
    }
  }
  return;
}


// ==== FUN_004e4450 @ 0x004e4450 ====

void FUN_004e4450(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int local_8;
  int local_4;
  
  local_4 = in_ECX + 4;
  FUN_00558e70(&local_8,&param_1);
  if (local_8 != *(int *)(in_ECX + 8)) {
    puVar8 = *(undefined4 **)(local_8 + 0x14);
    iVar7 = local_8;
    if (puVar8 != *(undefined4 **)(local_8 + 0x18)) {
      do {
        piVar2 = (int *)*puVar8;
        iVar4 = (**(code **)(*piVar2 + 0x20))();
        if (iVar4 == param_2) {
          (**(code **)(*piVar2 + 0x28))();
          (**(code **)*piVar2)(1);
          puVar3 = *(undefined4 **)(iVar7 + 0x18);
          puVar5 = puVar8 + 3;
          if (puVar5 != puVar3) {
            puVar6 = puVar8;
            do {
              *puVar6 = *puVar5;
              puVar6[1] = puVar5[1];
              puVar1 = puVar5 + 2;
              puVar5 = puVar5 + 3;
              puVar6[2] = *puVar1;
              puVar6 = puVar6 + 3;
            } while (puVar5 != puVar3);
            iVar7 = local_8;
          }
          *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + -0xc;
        }
        else {
          puVar8 = puVar8 + 3;
        }
      } while (puVar8 != *(undefined4 **)(iVar7 + 0x18));
    }
    if ((*(int *)(iVar7 + 0x14) == 0) ||
       (param_1 = (*(int *)(iVar7 + 0x18) - *(int *)(iVar7 + 0x14)) / 0xc, param_1 == 0)) {
      FUN_004e4e50(&param_1,iVar7);
    }
  }
  return;
}


// ==== FUN_004e4520 @ 0x004e4520 ====

int FUN_004e4520(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_8;
  int local_4;
  
  local_4 = in_ECX + 4;
  iVar4 = FUN_00558e70(&local_8,&param_1);
  if (local_8 != *(int *)(in_ECX + 8)) {
    puVar8 = *(undefined4 **)(local_8 + 0x14);
    iVar4 = local_8;
    if (puVar8 != *(undefined4 **)(local_8 + 0x18)) {
      do {
        piVar2 = (int *)*puVar8;
        if (*(char *)((int)puVar8 + 9) == '\0') {
          puVar8 = puVar8 + 3;
        }
        else {
          (**(code **)(*piVar2 + 0x28))();
          (**(code **)*piVar2)(1);
          puVar3 = *(undefined4 **)(iVar4 + 0x18);
          puVar5 = puVar8 + 3;
          if (puVar5 != puVar3) {
            puVar7 = puVar8;
            do {
              *puVar7 = *puVar5;
              puVar7[1] = puVar5[1];
              puVar1 = puVar5 + 2;
              puVar5 = puVar5 + 3;
              puVar7[2] = *puVar1;
              puVar7 = puVar7 + 3;
            } while (puVar5 != puVar3);
            iVar4 = local_8;
          }
          *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -0xc;
        }
      } while (puVar8 != *(undefined4 **)(iVar4 + 0x18));
    }
    if (*(int *)(iVar4 + 0x14) != 0) {
      iVar6 = *(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 0x14);
      param_1 = iVar6 / 0xc;
      if (param_1 != 0) {
        return iVar6 * 0x2aaaaaab;
      }
    }
    iVar4 = FUN_004e4e50(&param_1,iVar4);
  }
  return iVar4;
}


// ==== FUN_004e45f0 @ 0x004e45f0 ====

void FUN_004e45f0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  int *piVar7;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while( true ) {
    if (puVar3 == puVar2) {
      FUN_004e5120(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
      *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
      *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
      return;
    }
    piVar4 = (int *)puVar3[6];
    for (piVar7 = (int *)puVar3[5]; piVar7 != piVar4; piVar7 = piVar7 + 3) {
      if ((undefined4 *)*piVar7 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar7)(1);
      }
    }
    if ((void *)puVar3[5] != (void *)0x0) break;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    if (*(char *)((int)puVar3 + 0x21) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x21);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x21);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x21);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  _free((void *)puVar3[5]);
  return;
}


// ==== FUN_004e46c0 @ 0x004e46c0 ====

void FUN_004e46c0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b1f60;
  FUN_004e45f0();
  DAT_00b5ac6c = 0;
  FUN_004e51b0(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004e4720 @ 0x004e4720 ====

void FUN_004e4720(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  int local_2c [2];
  undefined1 local_24 [4];
  void *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14 [2];
  void *local_c;
  
  FUN_00558e70(local_2c,&param_1);
  if (local_2c[0] == *(int *)(in_ECX + 8)) {
    local_20 = (void *)0x0;
    local_1c = 0;
    local_18 = 0;
    FUN_004e4dd0(param_2);
    local_14[0] = param_1;
    FUN_004e4c80(local_24);
    FUN_004e54e0(local_2c,local_14);
    if (local_c != (void *)0x0) {
      _free(local_c);
      return;
    }
    if (local_20 != (void *)0x0) {
      _free(local_20);
      return;
    }
  }
  else {
    FUN_004e4dd0(param_2);
  }
  return;
}


// ==== FUN_004e47d0 @ 0x004e47d0 ====

void FUN_004e47d0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b1f60;
  iVar1 = FUN_004e3e10();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac6c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac6c = in_ECX;
  return;
}


// ==== FUN_004e4820 @ 0x004e4820 ====

void FUN_004e4820(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  void *pvVar2;
  int *in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_a [10];
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(param_2,param_1,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))();
    return;
  }
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_004ec0d0(param_1,param_2,unaff_retaddr);
  }
  FUN_004e4720(param_2,auStack_a + -0xe);
  (**(code **)(*piVar1 + 0x1c))();
  return;
}


// ==== FUN_004e48b0 @ 0x004e48b0 ====

void FUN_004e48b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  void *pvVar2;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(param_3,param_2,param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))();
    return;
  }
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)FUN_004ec0d0(param_2,param_3,param_1);
  }
  FUN_004e4720(param_3,auStack_a + -0xe);
  (**(code **)(*piVar1 + 0x1c))();
  return;
}


// ==== FUN_004e4940 @ 0x004e4940 ====

undefined4 FUN_004e4940(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  undefined1 local_3;
  
  local_8 = 0;
  local_4 = 0;
  local_3 = 1;
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004ec410(param_1,param_2,param_3);
  }
  local_c = uVar2;
  FUN_004e4720(param_2,&local_c);
  return uVar2;
}


// ==== FUN_004e49a0 @ 0x004e49a0 ====

int FUN_004e49a0(int param_1,int param_2,undefined4 param_3)

{
  FUN_004e3eb0(param_1,param_2,param_3);
  return param_1 + param_2 * 0xc;
}


// ==== FUN_004e49d0 @ 0x004e49d0 ====

void FUN_004e49d0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981450;
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
      local_1c = FUN_004e3f20(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_004e49a0(local_1c,param_2,&local_44);
      FUN_004e3f20(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
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
      FUN_004e3da0(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_004e49a0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0xc,&local_44);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_006d89e0(param_1,*(int *)(in_ECX + 8) - local_24,&local_44);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0xc;
    uVar4 = FUN_004e3da0(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_004ab780(param_1,local_2c,local_28,local_38);
    FUN_006d89e0(param_1,param_2 * 0xc + param_1,&local_44);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004e4b78 @ 0x004e4b78 ====

void Catch_004e4b78(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004e4c80 @ 0x004e4c80 ====

void FUN_004e4c80(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981460;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x15555555 < uVar1) {
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 0xc);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0xc + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_004e3f20(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004e4d46 @ 0x004e4d46 ====

void Catch_004e4d46(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004e4d60 @ 0x004e4d60 ====

void FUN_004e4d60(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_004e4da3;
    }
  }
  iVar1 = 0;
LAB_004e4da3:
  FUN_004e49d0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_004e4dd0 @ 0x004e4dd0 ====

void FUN_004e4dd0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_004e4d60(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004e3eb0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== __break @ 0x004e4e4f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_004e4e50 @ 0x004e4e50 ====

/* WARNING: Removing unreachable block (ram,0x004e4f69) */
/* WARNING: Removing unreachable block (ram,0x004e4f7a) */
/* WARNING: Removing unreachable block (ram,0x004e4f83) */
/* WARNING: Removing unreachable block (ram,0x004e4f86) */
/* WARNING: Removing unreachable block (ram,0x004e4f76) */
/* WARNING: Removing unreachable block (ram,0x004e4f94) */
/* WARNING: Removing unreachable block (ram,0x004e4fa1) */
/* WARNING: Removing unreachable block (ram,0x004e4fac) */
/* WARNING: Removing unreachable block (ram,0x004e4fa8) */
/* WARNING: Removing unreachable block (ram,0x004e4f9c) */
/* WARNING: Removing unreachable block (ram,0x004e4faf) */

void FUN_004e4e50(undefined4 param_1,int *param_2)

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
            goto LAB_004e5084;
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
LAB_004e5084:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 8) = 1;
  }
  if ((void *)param_2[5] == (void *)0x0) {
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_004e5120 @ 0x004e5120 ====

void FUN_004e5120(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) != '\0') {
    return;
  }
  FUN_004e5120(*(undefined4 *)((int)param_1 + 8));
  if (*(void **)((int)param_1 + 0x14) == (void *)0x0) {
    *(undefined4 *)((int)param_1 + 0x14) = 0;
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x14));
  return;
}


// ==== FUN_004e5170 @ 0x004e5170 ====

void FUN_004e5170(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  FUN_004e4c80(param_4 + 1);
  *(undefined1 *)(in_ECX + 8) = param_5;
  *(undefined1 *)((int)in_ECX + 0x21) = 0;
  return;
}


// ==== FUN_004e51b0 @ 0x004e51b0 ====

void FUN_004e51b0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004e5120(piVar6[1]);
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
    FUN_004e4e50(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004e5270 @ 0x004e5270 ====

void * FUN_004e5270(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981470;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x24);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004e5170(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004e52e5 @ 0x004e52e5 ====

void Catch_004e52e5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004e5300 @ 0x004e5300 ====

void FUN_004e5300(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_004e5270(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004e5405:
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
      if ((char)piVar6[8] == '\0') goto LAB_004e5405;
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


// ==== FUN_004e54e0 @ 0x004e54e0 ====

void FUN_004e54e0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x21) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_004e5300(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_004e5300(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_004e55a0 @ 0x004e55a0 ====

void FUN_004e55a0(byte param_1)

{
  void *in_ECX;
  
  FUN_004e46c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e55c0 @ 0x004e55c0 ====

void FUN_004e55c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2270;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e55e0 @ 0x004e55e0 ====

void FUN_004e55e0(void)

{
  return;
}


// ==== FUN_004e55f0 @ 0x004e55f0 ====

void FUN_004e55f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b229c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac70 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac70 = in_ECX;
  return;
}


// ==== FUN_004e5620 @ 0x004e5620 ====

void FUN_004e5620(int param_1,int param_2)

{
  if ((param_2 != 0) && (param_1 != 0)) {
    (**(code **)(*DAT_00b5ac6c + 0x30))(param_1,param_2);
  }
  return;
}


// ==== FUN_004e5670 @ 0x004e5670 ====

void FUN_004e5670(void *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 unaff_retaddr;
  int iStack_34;
  void *pvStack_30;
  undefined4 uStack_2c;
  uint uStack_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    uStack_2c = 0;
    pvStack_30 = param_1;
    iStack_34 = param_2;
    (**(code **)(*DAT_00b5ac6c + 8))();
    piVar1 = (int *)(**(code **)(*DAT_00b5ac6c + 0x28))(param_1,param_2,0);
    if (piVar1 == (int *)0x0) {
      FUN_00401830(s___Effect_Handler_cpp_33____pEffe_009b1f9c);
      FUN_00796d50(&iStack_34);
      if (0xf < uStack_1c) {
        _free(pvStack_30);
        return;
      }
    }
    else {
      if ((int *)*piVar1 == (int *)0x0) {
        FUN_00401830(s___Effect_Handler_cpp_39____pEffe_009b1fcc);
        FUN_00796d50(&iStack_34);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*(int *)*piVar1 + 4))(param_3,uStack_8,uStack_4,unaff_retaddr);
      *(undefined1 *)(piVar1 + 2) = 1;
    }
  }
  return;
}


// ==== __break @ 0x004e574f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_004e5750 @ 0x004e5750 ====

void FUN_004e5750(void *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 unaff_retaddr;
  int iStack_34;
  void *pvStack_30;
  undefined4 uStack_2c;
  uint uStack_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    uStack_2c = 0;
    pvStack_30 = param_1;
    iStack_34 = param_2;
    (**(code **)(*DAT_00b5ac6c + 8))();
    piVar1 = (int *)(**(code **)(*DAT_00b5ac6c + 0x28))(param_1,param_2,0);
    if (piVar1 == (int *)0x0) {
      FUN_00401830(s___Effect_Handler_cpp_60____pEffe_009b2008);
      FUN_00796d50(&iStack_34);
      if (0xf < uStack_1c) {
        _free(pvStack_30);
        return;
      }
    }
    else {
      if ((int *)*piVar1 == (int *)0x0) {
        FUN_00401830(s___Effect_Handler_cpp_66____pEffe_009b2038);
        FUN_00796d50(&iStack_34);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*(int *)*piVar1 + 8))(param_3,uStack_8,uStack_4,unaff_retaddr);
      *(undefined1 *)(piVar1 + 2) = 1;
    }
  }
  return;
}


// ==== FUN_004e5830 @ 0x004e5830 ====

void FUN_004e5830(undefined4 param_1,void *param_2,int param_3,int param_4)

{
  int *piVar1;
  uint unaff_ESI;
  undefined4 unaff_retaddr;
  int iStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    uStack_30 = 0;
    pvStack_34 = param_2;
    iStack_38 = param_3;
    (**(code **)(*DAT_00b5ac6c + 0xc))(param_1);
    piVar1 = (int *)(**(code **)(*DAT_00b5ac6c + 0x28))(param_2,param_3,param_1);
    if (piVar1 == (int *)0x0) {
      FUN_00401830(s___Effect_Handler_cpp_94____pEffe_009b2074);
      FUN_00796d50(&iStack_38);
      if (0xf < unaff_ESI) {
        _free(pvStack_34);
        return;
      }
    }
    else {
      if ((int *)*piVar1 == (int *)0x0) {
        FUN_00401830(s___Effect_Handler_cpp_100____pEff_009b20a4);
        FUN_00796d50(&iStack_38);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*(int *)*piVar1 + 0x10))(param_4,uStack_8,uStack_4,unaff_retaddr,param_1,param_2)
      ;
      *(undefined1 *)(piVar1 + 2) = 1;
    }
  }
  return;
}


// ==== FUN_004e5920 @ 0x004e5920 ====

void FUN_004e5920(undefined4 param_1,void *param_2,int param_3,int param_4)

{
  int *piVar1;
  uint unaff_ESI;
  undefined4 unaff_retaddr;
  int iStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    uStack_30 = 0;
    pvStack_34 = param_2;
    iStack_38 = param_3;
    (**(code **)(*DAT_00b5ac6c + 0xc))(param_1);
    piVar1 = (int *)(**(code **)(*DAT_00b5ac6c + 0x28))(param_2,param_3,param_1);
    if (piVar1 == (int *)0x0) {
      FUN_00401830(s___Effect_Handler_cpp_128____pEff_009b20e0);
      FUN_00796d50(&iStack_38);
      if (0xf < unaff_ESI) {
        _free(pvStack_34);
        return;
      }
    }
    else {
      if ((int *)*piVar1 == (int *)0x0) {
        FUN_00401830(s___Effect_Handler_cpp_134____pEff_009b2114);
        FUN_00796d50(&iStack_38);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*(int *)*piVar1 + 0x14))(param_4,uStack_8,uStack_4,unaff_retaddr,param_1,param_2)
      ;
      *(undefined1 *)(piVar1 + 2) = 1;
    }
  }
  return;
}


// ==== FUN_004e5a10 @ 0x004e5a10 ====

void FUN_004e5a10(undefined4 param_1,void *param_2,int param_3,int param_4)

{
  int *piVar1;
  uint unaff_ESI;
  undefined4 unaff_retaddr;
  int iStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    uStack_30 = 0;
    pvStack_34 = param_2;
    iStack_38 = param_3;
    (**(code **)(*DAT_00b5ac6c + 0xc))(param_1);
    piVar1 = (int *)(**(code **)(*DAT_00b5ac6c + 0x28))(param_2,param_3,param_1);
    if (piVar1 == (int *)0x0) {
      FUN_00401830(s___Effect_Handler_cpp_155____pEff_009b2150);
      FUN_00796d50(&iStack_38);
      if (0xf < unaff_ESI) {
        _free(pvStack_34);
        return;
      }
    }
    else {
      if ((int *)*piVar1 == (int *)0x0) {
        FUN_00401830(s___Effect_Handler_cpp_161____pEff_009b2184);
        FUN_00796d50(&iStack_38);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*(int *)*piVar1 + 0xc))(param_4,uStack_8,uStack_4,unaff_retaddr);
      *(undefined1 *)(piVar1 + 2) = 1;
    }
  }
  return;
}


// ==== FUN_004e5af0 @ 0x004e5af0 ====

void FUN_004e5af0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  void *unaff_EDI;
  undefined4 uStack_28;
  uint uStack_10;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    uStack_28 = param_5;
    piVar1 = (int *)(**(code **)(*DAT_00b5ac6c + 0x10))(param_2,param_1);
    if (piVar1 == (int *)0x0) {
      FUN_00401830(s___Effect_Handler_cpp_186____pEff_009b21c0);
      FUN_00796d50(&uStack_28);
      if (0xf < uStack_10) {
        _free(unaff_EDI);
        return;
      }
    }
    else {
      (**(code **)(*piVar1 + 4))(param_3,param_1,0,0);
    }
  }
  return;
}


// ==== FUN_004e5b70 @ 0x004e5b70 ====

/* WARNING: Removing unreachable block (ram,0x004e5bc8) */
/* WARNING: Removing unreachable block (ram,0x004e5c17) */

void FUN_004e5b70(int param_1)

{
  int *piVar1;
  undefined1 auStack_1a [26];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac6c + 0x2c))
                            (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
  if (piVar1 == (int *)0x0) {
    FUN_00401740(s___Effect_Handler_cpp_210____pEff_009b21fc,0x30);
    FUN_00796d50(auStack_1a + -10);
  }
  else if ((int *)*piVar1 == (int *)0x0) {
    FUN_00401740(s___Effect_Handler_cpp_216____pEff_009b2230,0x39);
    FUN_00796d50(auStack_1a + -10);
  }
  else {
    (**(code **)(*(int *)*piVar1 + 0x18))();
    *(undefined1 *)(piVar1 + 2) = 0;
  }
  return;
}


// ==== FUN_004e5c40 @ 0x004e5c40 ====

void FUN_004e5c40(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac70 = 0;
  *in_ECX = &PTR_FUN_009b2270;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e5c70 @ 0x004e5c70 ====

undefined4 FUN_004e5c70(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004ec690();
      return uVar2;
    }
  }
  else if (param_1 == 1) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_004ec6c0();
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_004e5cb0 @ 0x004e5cb0 ====

undefined4 FUN_004e5cb0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004ec700(param_1);
  return uVar2;
}


// ==== FUN_004e5cd0 @ 0x004e5cd0 ====

undefined4 FUN_004e5cd0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004ecd00(param_1);
  return uVar2;
}


// ==== FUN_004e5cf0 @ 0x004e5cf0 ====

undefined4 FUN_004e5cf0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004ed380(param_1,param_2,param_3);
  return uVar2;
}


// ==== FUN_004e5d20 @ 0x004e5d20 ====

undefined4 FUN_004e5d20(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004ed830(param_1,param_2,param_3);
  return uVar2;
}


// ==== FUN_004e5d50 @ 0x004e5d50 ====

undefined4 FUN_004e5d50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004edbc0(param_1,param_2,param_3);
  return uVar2;
}


// ==== FUN_004e5d80 @ 0x004e5d80 ====

undefined4 FUN_004e5d80(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004ef250(param_1);
  return uVar2;
}


// ==== FUN_004e5da0 @ 0x004e5da0 ====

undefined4 FUN_004e5da0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004ef720(param_1,param_2,param_3);
  return uVar2;
}


// ==== FUN_004e5dd0 @ 0x004e5dd0 ====

undefined4 FUN_004e5dd0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004efce0(param_1);
  return uVar2;
}


// ==== FUN_004e5df0 @ 0x004e5df0 ====

undefined4 FUN_004e5df0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004efff0();
  return uVar2;
}


// ==== FUN_004e5e10 @ 0x004e5e10 ====

undefined4 FUN_004e5e10(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f0250();
  return uVar2;
}


// ==== FUN_004e5e30 @ 0x004e5e30 ====

undefined4 FUN_004e5e30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f02c0(param_1,param_2,param_3);
  return uVar2;
}


// ==== FUN_004e5e60 @ 0x004e5e60 ====

undefined4 FUN_004e5e60(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f10a0(param_1);
  return uVar2;
}


// ==== FUN_004e5e80 @ 0x004e5e80 ====

undefined4 FUN_004e5e80(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f1290(param_1);
  return uVar2;
}


// ==== FUN_004e5ea0 @ 0x004e5ea0 ====

undefined4 FUN_004e5ea0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f1440(param_1);
  return uVar2;
}


// ==== FUN_004e5ec0 @ 0x004e5ec0 ====

undefined4 FUN_004e5ec0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x20);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f1a00(param_1);
  return uVar2;
}


// ==== FUN_004e5ee0 @ 0x004e5ee0 ====

undefined4 FUN_004e5ee0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f1af0();
  return uVar2;
}


// ==== FUN_004e5f00 @ 0x004e5f00 ====

undefined4 FUN_004e5f00(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f1c30(param_1);
  return uVar2;
}


// ==== FUN_004e5f20 @ 0x004e5f20 ====

undefined4 FUN_004e5f20(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f1f50(param_1);
  return uVar2;
}


// ==== FUN_004e5f40 @ 0x004e5f40 ====

undefined4 FUN_004e5f40(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f2390(param_1);
  return uVar2;
}


// ==== FUN_004e5f60 @ 0x004e5f60 ====

undefined4 FUN_004e5f60(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f2510(param_1);
  return uVar2;
}


// ==== FUN_004e5f80 @ 0x004e5f80 ====

undefined4 FUN_004e5f80(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f26a0(param_1);
  return uVar2;
}


// ==== FUN_004e5fa0 @ 0x004e5fa0 ====

undefined4 FUN_004e5fa0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_004f28e0(param_1);
  return uVar2;
}


// ==== FUN_004e5fc0 @ 0x004e5fc0 ====

undefined4 FUN_004e5fc0(undefined4 param_1,undefined1 param_2,void *param_3)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  uint in_stack_00000020;
  
  pvVar1 = operator_new(0x24);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    FUN_00401660(&param_2,0,0xffffffff);
    uVar2 = FUN_004f2d40(param_1);
  }
  if (in_stack_00000020 < 0x10) {
    return uVar2;
  }
  _free(param_3);
  return extraout_EAX;
}


// ==== FUN_004e6020 @ 0x004e6020 ====

void FUN_004e6020(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2314;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e6040 @ 0x004e6040 ====

void FUN_004e6040(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 0x1d) = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  return;
}


// ==== FUN_004e6060 @ 0x004e6060 ====

void FUN_004e6060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2324;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ace4 = (undefined4 *)0x0;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 7) = 0;
    *(undefined1 *)((int)in_ECX + 0x1d) = 0;
    *(undefined1 *)((int)in_ECX + 0x1e) = 0;
    *(undefined1 *)((int)in_ECX + 0x1f) = 0;
    return;
  }
  DAT_00b5ace4 = in_ECX;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  *(undefined1 *)((int)in_ECX + 0x1e) = 0;
  *(undefined1 *)((int)in_ECX + 0x1f) = 0;
  return;
}


// ==== FUN_004e60d0 @ 0x004e60d0 ====

void FUN_004e60d0(void)

{
  int *piVar1;
  int in_ECX;
  uint unaff_ESI;
  undefined *puStack_140;
  void *pvStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined1 *puStack_12c;
  undefined4 uStack_128;
  char *pcStack_124;
  void **ppvStack_120;
  void *local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  uint local_fc;
  void *pvStack_f4;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  uint local_e0;
  undefined4 uStack_dc;
  undefined1 auStack_d8 [8];
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 local_c8 [116];
  undefined1 local_54 [28];
  undefined1 local_38 [28];
  undefined1 local_1c [28];
  
  pcStack_124 = (char *)0x0;
  local_10c = 0;
  local_108 = 0;
  local_104 = 0;
  local_e8 = 0xf;
  local_ec = 0;
  local_fc = local_fc & 0xffffff00;
  local_cc = 0xf;
  local_d0 = 0;
  local_e0 = local_e0 & 0xffffff00;
  switch(*(undefined4 *)(in_ECX + 0x18)) {
  case 0:
    ppvStack_120 = (void **)0x4e6124;
    FUN_0040a7d0();
    ppvStack_120 = (void **)0x4e612d;
    FUN_004e67a0();
    return;
  case 1:
    pcStack_124 = (char *)0x4b00005;
    break;
  case 2:
    ppvStack_120 = (void **)0x5;
    pcStack_124 = s_<MIN>_009b2304;
    uStack_128 = 0x4e6317;
    FUN_00401740();
    ppvStack_120 = *(void ***)(in_ECX + 0x10);
    puStack_140 = &DAT_009b230c;
    FUN_00401830();
    puStack_140 = local_54;
    uStack_128 = FUN_00404230();
    ppvStack_120 = (void **)0xffffffff;
    pcStack_124 = (char *)0x0;
    puStack_12c = (undefined1 *)0x4e6347;
    FUN_00401660();
                    /* WARNING: Subroutine does not return */
    ppvStack_120 = (void **)0x4e6353;
    FUN_00446f10();
  case 3:
    ppvStack_120 = (void **)0x6;
    pcStack_124 = s_<HOUR>_009b22ec;
    uStack_128 = 0x4e625c;
    FUN_00401740();
    ppvStack_120 = *(void ***)(in_ECX + 0xc);
    puStack_140 = &DAT_009b22f4;
    FUN_00401830();
    puStack_140 = local_38;
    uStack_128 = FUN_00404230();
    ppvStack_120 = (void **)0xffffffff;
    pcStack_124 = (char *)0x0;
    puStack_12c = (undefined1 *)0x4e628c;
    FUN_00401660();
                    /* WARNING: Subroutine does not return */
    ppvStack_120 = (void **)0x4e6298;
    FUN_00446f10();
  case 4:
    ppvStack_120 = (void **)0x5;
    pcStack_124 = s_<DAY>_009b22c8;
    uStack_128 = 0x4e6147;
    FUN_00401740();
    ppvStack_120 = *(void ***)(in_ECX + 8);
    puStack_140 = &DAT_009b22d0;
    FUN_00401830();
    puStack_140 = local_1c;
    uStack_128 = FUN_00404230();
    ppvStack_120 = (void **)0xffffffff;
    pcStack_124 = (char *)0x0;
    puStack_12c = (undefined1 *)0x4e6177;
    FUN_00401660();
                    /* WARNING: Subroutine does not return */
    ppvStack_120 = (void **)0x4e6183;
    FUN_00446f10();
  }
  ppvStack_120 = &local_110;
  uStack_128 = 5;
  puStack_12c = local_c8;
  uStack_130 = 0x4e6385;
  (**(code **)(*DAT_00b5a794 + 8))();
  piVar1 = DAT_00b5ad0c;
  uStack_130 = 0xf;
  uStack_134 = 0;
  FUN_00401660(auStack_d8,0,0xffffffff);
  (**(code **)(*piVar1 + 0x28))(2);
  if (0xf < local_e0) {
    _free(pvStack_f4);
    return;
  }
  local_e0 = 0xf;
  local_e4 = 0;
  pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
  if (0xf < local_fc) {
    _free(local_110);
    return;
  }
  local_fc = 0xf;
  local_100 = 0;
  local_110 = (void *)((uint)local_110 & 0xffffff00);
  if (0xf < unaff_ESI) {
    _free(puStack_12c);
    return;
  }
  puStack_12c = (undefined1 *)((uint)puStack_12c & 0xffffff00);
  if (pvStack_13c == (void *)0x0) {
    return;
  }
  FUN_004e65b0(pvStack_13c,uStack_138,&puStack_140,uStack_dc);
  _free(pvStack_13c);
  return;
}


// ==== FUN_004e6460 @ 0x004e6460 ====

void FUN_004e6460(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_4;
  
  local_14 = *(undefined4 *)(in_ECX + 4);
  local_10 = *(undefined4 *)(in_ECX + 8);
  iVar1 = *(int *)(in_ECX + 0xc);
  uVar2 = *(uint *)(in_ECX + 0x10);
  local_4 = *(undefined4 *)(in_ECX + 0x14);
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5ac30 + 0x10))(&local_14);
  *(undefined4 *)(in_ECX + 4) = *puVar4;
  *(undefined4 *)(in_ECX + 8) = puVar4[1];
  *(undefined4 *)(in_ECX + 0xc) = puVar4[2];
  *(undefined4 *)(in_ECX + 0x10) = puVar4[3];
  *(undefined4 *)(in_ECX + 0x14) = puVar4[4];
  uVar3 = *(uint *)(in_ECX + 0x10);
  if (uVar3 != 0) {
    if (*(int *)(in_ECX + 8) == 0) {
      if (*(int *)(in_ECX + 0xc) == 0) {
        if (uVar3 == 0x1e) {
          if (*(char *)(in_ECX + 0x1f) == '\0') {
            *(undefined1 *)(in_ECX + 0x1f) = 1;
            *(undefined4 *)(in_ECX + 0x18) = 2;
            FUN_004e60d0();
            return;
          }
        }
        else if (uVar3 < 6) {
          if (uVar3 != uVar2) {
            *(undefined4 *)(in_ECX + 0x18) = 1;
            FUN_004e60d0();
          }
        }
        else if ((*(char *)(in_ECX + 0x1e) == '\0') && (*(char *)(in_ECX + 0x1d) == '\0')) {
          *(undefined1 *)(in_ECX + 0x1e) = 1;
          *(undefined4 *)(in_ECX + 0x18) = 2;
          FUN_004e60d0();
          return;
        }
      }
      else {
        *(undefined1 *)(in_ECX + 0x1d) = 1;
        if (*(int *)(in_ECX + 0xc) != iVar1) {
          *(undefined4 *)(in_ECX + 0x18) = 3;
          FUN_004e60d0();
          return;
        }
      }
    }
    else if (*(char *)(in_ECX + 0x1c) == '\0') {
      *(undefined1 *)(in_ECX + 0x1c) = 1;
      *(undefined4 *)(in_ECX + 0x18) = 4;
      FUN_004e60d0();
      return;
    }
  }
  return;
}


// ==== FUN_004e6580 @ 0x004e6580 ====

void FUN_004e6580(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ace4 = 0;
  *in_ECX = &PTR_FUN_009b2314;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e65b0 @ 0x004e65b0 ====

void FUN_004e65b0(int param_1,int param_2)

{
  uint *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (uint *)(param_1 + 0x34);
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
      param_1 = param_1 + 0x38;
      puVar1 = puVar1 + 0xe;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_004e6610 @ 0x004e6610 ====

int FUN_004e6610(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x38;
    param_3 = param_3 + -0x38;
    FUN_00401660(iVar1,0,0xffffffff);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
  } while (iVar1 != param_1);
  return param_3;
}


// ==== FUN_004e6660 @ 0x004e6660 ====

int FUN_004e6660(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981480;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x38) {
    FUN_0089d7a0(param_3,param_1);
    param_3 = param_3 + 0x38;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@004e66ca @ 0x004e66ca ====

void Catch_004e66ca(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x38) {
    FUN_0089d750(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004e66f0 @ 0x004e66f0 ====

void FUN_004e66f0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981490;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0089d7a0(param_1,param_3);
    param_1 = param_1 + 0x38;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@004e675a @ 0x004e675a ====

void Catch_004e675a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x38) {
    FUN_0089d750(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004e6780 @ 0x004e6780 ====

void FUN_004e6780(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_004e6660(param_1,param_2,param_3);
  return;
}


// ==== FUN_004e67a0 @ 0x004e67a0 ====

void FUN_004e67a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_004e65b0(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_004e67e0 @ 0x004e67e0 ====

int FUN_004e67e0(int param_1,int param_2,undefined4 param_3)

{
  FUN_004e66f0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x38;
}


// ==== FUN_004e6810 @ 0x004e6810 ====

void FUN_004e6810(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_84 [2];
  undefined1 auStack_82 [2];
  void *local_80;
  undefined4 local_70;
  uint local_6c;
  void *local_64;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  int local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  void *local_20;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009814a0;
  local_10 = ExceptionList;
  local_14 = local_84 + -0xc;
  local_6c = 0xf;
  local_70 = 0;
  local_80 = (void *)((uint)local_80 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_50 = 0xf;
  local_54 = 0;
  local_64 = (void *)((uint)local_64 & 0xffffff00);
  FUN_00401660(param_3 + 0x1c,0,0xffffffff);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x38;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      local_28 = *(int *)(in_ECX + 8) - iVar2;
      iVar1 = local_28 / 0x38;
    }
    if (0x4924924U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      local_2c = *(int *)(in_ECX + 8) - iVar2;
      iVar1 = local_2c / 0x38;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x4924924 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        local_30 = *(int *)(in_ECX + 8) - iVar2;
        iVar2 = local_30 / 0x38;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_00875fa0();
        uVar4 = iVar2 + param_2;
      }
      local_34 = uVar4 * 0x38;
      local_20 = operator_new(local_34);
      local_8 = 0;
      local_18 = local_20;
      local_18 = (void *)FUN_004e6780(*(undefined4 *)(in_ECX + 4),param_1,local_20);
      local_18 = (void *)FUN_004e67e0(local_18,param_2,local_84);
      FUN_004e6780(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x38;
      }
      if (iVar2 != 0) {
        FUN_004e65b0(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_34 + (int)local_20;
      *(void **)(in_ECX + 8) = (void *)((int)local_20 + (param_2 + iVar1) * 0x38);
      *(void **)(in_ECX + 4) = local_20;
    }
    else {
      local_3c = *(int *)(in_ECX + 8);
      local_38 = local_3c - param_1;
      if ((uint)(local_38 / 0x38) < param_2) {
        local_1c = param_2 * 0x38;
        FUN_004e6660(param_1,local_3c,local_1c + param_1);
        local_8 = 2;
        FUN_004e67e0(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x38,
                     local_84);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_1c;
        FUN_0089d880(param_1,*(int *)(in_ECX + 8) - local_1c,local_84);
      }
      else {
        local_1c = param_2 * 0x38;
        iVar2 = local_3c + param_2 * -0x38;
        uVar3 = FUN_004e6660(iVar2,local_3c,local_3c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_004e6610(param_1,iVar2,local_3c,local_4c);
        FUN_0089d880(param_1,local_1c + param_1,local_84);
      }
    }
  }
  if (0xf < local_50) {
    _free(local_64);
    return;
  }
  local_50 = 0xf;
  local_54 = 0;
  local_64 = (void *)((uint)local_64 & 0xffffff00);
  if (local_6c < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_80);
  return;
}


// ==== Catch@004e6a13 @ 0x004e6a13 ====

void Catch_004e6a13(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x1c);
  FUN_0089d950(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@004e6ad8 @ 0x004e6ad8 ====

void Catch_004e6ad8(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x38;
  FUN_0089d950(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x20) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_004e6ba0 @ 0x004e6ba0 ====

void FUN_004e6ba0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x38 != 0) {
      iVar1 = (param_2 - iVar1) / 0x38;
      goto LAB_004e6be9;
    }
  }
  iVar1 = 0;
LAB_004e6be9:
  FUN_004e6810(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x38;
  return;
}


// ==== FUN_004e6c20 @ 0x004e6c20 ====

void FUN_004e6c20(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x38) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x38))) {
    FUN_004e6ba0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_004e66f0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x38;
  return;
}


// ==== FUN_004e6cb0 @ 0x004e6cb0 ====

void FUN_004e6cb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2338;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e6cd0 @ 0x004e6cd0 ====

int FUN_004e6cd0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_004e6ce0 @ 0x004e6ce0 ====

undefined4 FUN_004e6ce0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_004e6cf0 @ 0x004e6cf0 ====

uint * FUN_004e6cf0(uint *param_1)

{
  ulonglong uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  uint uVar5;
  uint uVar6;
  
  iVar3 = (**(code **)(*in_ECX + 0xc))();
  piVar2 = DAT_00b5a6ac;
  uVar6 = *(uint *)(iVar3 + 0x1c);
  iVar3 = (**(code **)(*in_ECX + 0xc))();
  iVar4 = (**(code **)(*piVar2 + 0x20))();
  uVar5 = (uint)(iVar4 - *(int *)(iVar3 + 0x20)) / 1000;
  if (uVar5 < uVar6) {
    uVar6 = uVar6 - uVar5;
    uVar1 = ((ulonglong)uVar6 / 0x3c) / 0x3c;
    *param_1 = uVar6;
    param_1[1] = (uint)(uVar1 / 0x18);
    param_1[2] = (uint)(uVar1 % 0x18);
    param_1[3] = (uint)(((ulonglong)uVar6 / 0x3c) % 0x3c);
    param_1[4] = uVar6 % 0x3c;
    return param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}


// ==== FUN_004e6d90 @ 0x004e6d90 ====

void FUN_004e6d90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2354;
  DAT_00b5ac30 = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009b2338;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004e6dd0 @ 0x004e6dd0 ====

void FUN_004e6dd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2354;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac30 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac30 = in_ECX;
  return;
}


// ==== FUN_004e6e20 @ 0x004e6e20 ====

void FUN_004e6e20(void)

{
  int in_ECX;
  
  FUN_00401740(&DAT_009b2332,0);
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  return;
}


// ==== FUN_004e6e50 @ 0x004e6e50 ====

void FUN_004e6e50(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x20);
  uVar1 = (**(code **)(*DAT_00b5ace0 + 8))(in_ECX + 4);
  *(undefined4 *)(in_ECX + 0x28) = uVar1;
  return;
}


// ==== FUN_004e6e90 @ 0x004e6e90 ====

void FUN_004e6e90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2354;
  DAT_00b5ac30 = 0;
  if (0xf < (uint)in_ECX[7]) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = &PTR_FUN_009b2338;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e6ef0 @ 0x004e6ef0 ====

void FUN_004e6ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2394;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e6f10 @ 0x004e6f10 ====

void FUN_004e6f10(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009814b0;
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


// ==== Catch@004e6f9a @ 0x004e6f9a ====

void Catch_004e6f9a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004e6fb0 @ 0x004e6fb0 ====

undefined4 FUN_004e6fb0(int param_1)

{
  int in_ECX;
  
  FUN_0069a470(&param_1,param_1);
  if (param_1 == *(int *)(in_ECX + 0x14)) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x28);
}


// ==== FUN_004e7040 @ 0x004e7040 ====

/* WARNING: Removing unreachable block (ram,0x004e7473) */

void FUN_004e7040(undefined4 param_1)

{
  char cVar1;
  byte ****ppppbVar2;
  uint uVar3;
  byte bVar4;
  undefined2 uVar5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  char *pcVar9;
  byte *****pppppbVar10;
  void *pvVar11;
  undefined4 uVar12;
  int iVar13;
  byte *pbVar14;
  int *piVar15;
  byte ******ppppppbVar16;
  byte ****ppppbVar17;
  uint uVar18;
  byte ******ppppppbVar19;
  undefined3 unaff_EBP;
  byte *pbVar20;
  int iVar21;
  bool bVar22;
  bool bVar23;
  undefined4 uVar24;
  byte *****pppppbStack_4c8;
  int iStack_4c4;
  int local_4c0;
  byte ******appppppbStack_4bc [2];
  undefined2 uStack_4b4;
  byte ****ppppbStack_4ac;
  uint uStack_4a8;
  undefined1 auStack_4a0 [4];
  undefined4 uStack_49c;
  uint uStack_498;
  int iStack_494;
  int iStack_490;
  undefined1 auStack_488 [4];
  void *pvStack_484;
  undefined1 auStack_47c [4];
  void *pvStack_478;
  undefined4 uStack_474;
  uint uStack_470;
  undefined4 uStack_468;
  uint uStack_464;
  undefined4 uStack_460;
  undefined1 uStack_458;
  undefined1 auStack_44c [4];
  void *pvStack_448;
  undefined4 uStack_444;
  undefined4 uStack_438;
  uint uStack_434;
  undefined4 uStack_430;
  undefined2 uStack_42c;
  undefined1 auStack_428 [4];
  void *pvStack_424;
  undefined4 uStack_414;
  uint uStack_410;
  char local_408 [20];
  byte *****pppppbStack_3f4;
  undefined4 local_308;
  char local_304 [4];
  char local_300 [500];
  char acStack_10c [8];
  undefined1 auStack_104 [260];
  
  local_408[0] = '\0';
  FUN_0044a580(local_300);
  uVar6 = 0;
  do {
    local_408[uVar6] = local_300[uVar6];
    if (local_300[uVar6] == '\0') goto LAB_004e70a4;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x100);
  local_408[0] = '\0';
LAB_004e70a4:
  local_308 = param_1;
  local_304[0] = '\n';
  local_304[1] = 0x2c;
  local_304[2] = 1;
  piVar7 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  uStack_498 = 0xf;
  uStack_49c = 0;
  ppppbStack_4ac = (byte ****)((uint)ppppbStack_4ac & 0xffffff00);
  uStack_4b4 = 0;
  FUN_00401740(&DAT_009b2387);
  uVar24 = CONCAT13(3,unaff_EBP);
  uVar6 = (**(code **)(*piVar7 + 8))();
  if (uVar6 < 4) {
LAB_004e75af:
    if (uStack_498 < 0x10) {
      return;
    }
    _free(ppppbStack_4ac);
    return;
  }
  ppppppbVar19 = (byte ******)0x3;
  appppppbStack_4bc[0] = (byte ******)0x3;
LAB_004e7130:
  iVar21 = 0;
  do {
    FUN_0044a580(local_304,&DAT_009b238c,&DAT_009b2388);
    pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))(ppppppbVar19,iVar21);
    uVar6 = 0;
    iVar13 = -(int)pcVar8;
LAB_004e7161:
    if (*pcVar8 != pcVar8[(int)(local_304 + iVar13)]) goto LAB_004e717e;
    if (*pcVar8 != '\0') goto code_r0x004e7170;
    iVar21 = iVar21 + 1;
  } while (iVar21 < 6);
  goto LAB_004e758c;
code_r0x004e7170:
  uVar6 = uVar6 + 1;
  pcVar8 = pcVar8 + 1;
  if (0xff < uVar6) {
LAB_004e717e:
    FUN_0044a580(auStack_104,&DAT_009b238c,&DAT_009b2389);
    pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))(ppppppbVar19,0);
    uVar6 = 0;
    iVar21 = -(int)pcVar8;
    goto LAB_004e71b0;
  }
  goto LAB_004e7161;
  while( true ) {
    if (*pcVar8 == '\0') goto LAB_004e71d8;
    uVar6 = uVar6 + 1;
    pcVar8 = pcVar8 + 1;
    if (0xff < uVar6) break;
LAB_004e71b0:
    if (*pcVar8 != pcVar8[(int)(acStack_10c + iVar21)]) break;
  }
  uVar5 = FUN_00475a90(ppppppbVar19,0);
  appppppbStack_4bc[0] = (byte ******)CONCAT22(appppppbStack_4bc[0]._2_2_,uVar5);
LAB_004e71d8:
  FUN_0044a580(local_300 + 0xf4,&DAT_009b238c,&DAT_009b238a);
  pcVar8 = (char *)(**(code **)(*piVar7 + 0x10))(ppppppbVar19,1);
  uVar6 = 0;
  iVar21 = 0xec - (int)pcVar8;
  do {
    if (*pcVar8 != pcVar8[(int)(local_300 + iVar21)]) break;
    if (*pcVar8 == '\0') goto LAB_004e7247;
    uVar6 = uVar6 + 1;
    pcVar8 = pcVar8 + 1;
  } while (uVar6 < 0x100);
  pcVar9 = (char *)(**(code **)(*piVar7 + 0x10))(ppppppbVar19,1);
  pcVar8 = pcVar9;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
LAB_004e7247:
  pppppbVar10 = (byte *****)FUN_004bb4d0(&local_4c0);
  if (pppppbVar10 == pppppbStack_3f4) {
LAB_004e72d2:
    pppppbStack_4c8 = pppppbStack_3f4;
    ppppppbVar19 = &pppppbStack_4c8;
  }
  else {
    ppppbVar2 = pppppbVar10[8];
    if (pppppbVar10[9] < (byte ****)0x10) {
      pppppbVar10 = pppppbVar10 + 4;
    }
    else {
      pppppbVar10 = (byte *****)pppppbVar10[4];
    }
    if (ppppbStack_4ac == (byte ****)0x0) {
LAB_004e72bd:
      if (ppppbStack_4ac < ppppbVar2) goto LAB_004e72d2;
      bVar22 = false;
    }
    else {
      ppppbVar17 = ppppbStack_4ac;
      if (ppppbVar2 <= ppppbStack_4ac) {
        ppppbVar17 = ppppbVar2;
      }
      ppppppbVar19 = appppppbStack_4bc[0];
      if (uStack_4a8 < 0x10) {
        ppppppbVar19 = (byte ******)appppppbStack_4bc;
      }
      bVar22 = false;
      iVar21 = 0;
      bVar23 = true;
      do {
        if (ppppbVar17 == (byte ****)0x0) break;
        ppppbVar17 = (byte ****)((int)ppppbVar17 - 1);
        bVar22 = *(byte *)ppppppbVar19 < *(byte *)pppppbVar10;
        bVar23 = *(byte *)ppppppbVar19 == *(byte *)pppppbVar10;
        ppppppbVar19 = (byte ******)((int)ppppppbVar19 + 1);
        pppppbVar10 = (byte *****)((int)pppppbVar10 + 1);
      } while (bVar23);
      if (!bVar23) {
        iVar21 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
      }
      bVar22 = iVar21 < 0;
      if (iVar21 == 0) goto LAB_004e72bd;
    }
    if (bVar22) goto LAB_004e72d2;
    ppppppbVar19 = (byte ******)(appppppbStack_4bc + -7);
  }
  if (*ppppppbVar19 == pppppbStack_3f4) {
    pvVar11 = operator_new(0x38);
    if (pvVar11 == (void *)0x0) {
      uVar12 = 0;
    }
    else {
      uVar12 = FUN_004f3020();
    }
    FUN_004f2fb0(&iStack_4c4);
    uStack_464 = 0xf;
    uStack_468 = 0;
    pvStack_478 = (void *)((uint)pvStack_478 & 0xffffff00);
    FUN_00401660(&local_4c0,0,0xffffffff);
    uStack_460 = uVar12;
    FUN_004e7b40(auStack_4a0,auStack_47c);
    if (0xf < uStack_464) {
      _free(pvStack_478);
      return;
    }
    uStack_464 = 0xf;
    uStack_468 = 0;
    pvStack_478 = (void *)((uint)pvStack_478 & 0xffffff00);
  }
  pvStack_448 = (void *)0x0;
  uStack_444 = 0xf;
  uStack_458 = 0;
  pcVar9 = (char *)(**(code **)(*piVar7 + 0x10))(uVar24,3);
  pcVar8 = pcVar9;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
  pcVar9 = (char *)(**(code **)(*piVar7 + 0x10))(uVar24,4);
  uStack_470 = 0xf;
  uStack_474 = 0;
  pvStack_484 = (void *)((uint)pvStack_484 & 0xffffff00);
  pcVar8 = pcVar9;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar9,(int)pcVar8 - (int)(pcVar9 + 1));
  iVar13 = FUN_00797110(auStack_428,auStack_488);
  iVar21 = iStack_4c4;
  local_4c0 = FUN_004bb4d0(iVar13);
  iStack_490 = *(int *)(iVar21 + 8);
  if (local_4c0 != iStack_490) {
    uVar6 = *(uint *)(local_4c0 + 0x20);
    if (*(uint *)(local_4c0 + 0x24) < 0x10) {
      pbVar14 = (byte *)(local_4c0 + 0x10);
    }
    else {
      pbVar14 = *(byte **)(local_4c0 + 0x10);
    }
    uVar3 = *(uint *)(iVar13 + 0x14);
    if (uVar3 == 0) {
LAB_004e74a1:
      if (uVar3 < uVar6) goto LAB_004e74b6;
      bVar22 = false;
    }
    else {
      uVar18 = uVar3;
      if (uVar6 <= uVar3) {
        uVar18 = uVar6;
      }
      if (*(uint *)(iVar13 + 0x18) < 0x10) {
        pbVar20 = (byte *)(iVar13 + 4);
      }
      else {
        pbVar20 = *(byte **)(iVar13 + 4);
      }
      bVar22 = false;
      iVar21 = 0;
      bVar23 = true;
      do {
        if (uVar18 == 0) break;
        uVar18 = uVar18 - 1;
        bVar22 = *pbVar20 < *pbVar14;
        bVar23 = *pbVar20 == *pbVar14;
        pbVar20 = pbVar20 + 1;
        pbVar14 = pbVar14 + 1;
      } while (bVar23);
      if (!bVar23) {
        iVar21 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
      }
      bVar22 = iVar21 < 0;
      if (iVar21 == 0) goto LAB_004e74a1;
    }
    if (!bVar22) {
      piVar15 = &local_4c0;
      goto LAB_004e74c2;
    }
  }
LAB_004e74b6:
  iStack_494 = iStack_490;
  piVar15 = &iStack_494;
LAB_004e74c2:
  if (0xf < uStack_410) {
    _free(pvStack_424);
    return;
  }
  uStack_410 = 0xf;
  uStack_414 = 0;
  pvStack_424 = (void *)((uint)pvStack_424 & 0xffffff00);
  if (*piVar15 == *(int *)(iStack_4c4 + 8)) {
    uStack_430 = 0;
  }
  else {
    uStack_430 = *(undefined4 *)(*piVar15 + 0x28);
  }
  uStack_42c = FUN_00475a90(appppppbStack_4bc[0],5);
  FUN_004f30c0(auStack_44c);
  if (0xf < uStack_470) {
    _free(pvStack_484);
    return;
  }
  uStack_470 = 0xf;
  uStack_474 = 0;
  pvStack_484 = (void *)((uint)pvStack_484 & 0xffffff00);
  if (0xf < uStack_434) {
    _free(pvStack_448);
    return;
  }
  uStack_434 = 0xf;
  uStack_438 = 0;
  pvStack_448 = (void *)((uint)pvStack_448 & 0xffffff00);
LAB_004e758c:
  bVar4 = (char)((uint)uVar24 >> 0x18) + 1;
  ppppppbVar19 = (byte ******)(uint)bVar4;
  uVar24 = CONCAT13(bVar4,(int3)uVar24);
  appppppbStack_4bc[0] = ppppppbVar19;
  ppppppbVar16 = (byte ******)(**(code **)(*piVar7 + 8))();
  if (ppppppbVar16 <= ppppppbVar19) goto LAB_004e75af;
  goto LAB_004e7130;
}


// ==== FUN_004e75d0 @ 0x004e75d0 ====

void FUN_004e75d0(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009b23a4;
  DAT_00b5ace0 = 0;
  local_4 = in_ECX;
  if (in_ECX[6] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_0082c4f0(*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5],local_4);
    FUN_004e78a0(*(undefined4 *)(in_ECX[5] + 4));
    *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
    in_ECX[6] = 0;
    *(undefined4 *)in_ECX[5] = in_ECX[5];
    *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  }
  FUN_004e7cb0(&local_4,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_004e7680 @ 0x004e7680 ====

void FUN_004e7680(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined1 local_44 [8];
  undefined1 local_3c [4];
  void *local_38;
  undefined4 local_28;
  uint local_24;
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b23a4;
  iVar1 = FUN_004e6f10();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  iVar1 = FUN_004e6f10();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ace0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ace0 = in_ECX;
  }
  local_24 = 0xf;
  local_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(s_CONNECTION_009b2370,10);
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(local_3c,0,0xffffffff);
  local_4 = 1;
  FUN_004e7b40(local_44,local_20);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (0xf < local_24) {
    _free(local_38);
    return;
  }
  local_24 = 0xf;
  local_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  FUN_00401740(&PTR___break_009b237c,3);
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(local_3c,0,0xffffffff);
  local_4 = 2;
  FUN_004e7b40(local_44,local_20);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  if (local_24 < 0x10) {
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_004e7810 @ 0x004e7810 ====

void * FUN_004e7810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009814c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004bbcf0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@004e7885 @ 0x004e7885 ====

void Catch_004e7885(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004e78a0 @ 0x004e78a0 ====

void FUN_004e78a0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_004e78a0(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x24) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x24) = 0xf;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    *(undefined1 *)((int)param_1 + 0x10) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x10));
  return;
}


// ==== FUN_004e7900 @ 0x004e7900 ====

void FUN_004e7900(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_004e7900(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x24) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x24) = 0xf;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    *(undefined1 *)((int)param_1 + 0x10) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x10));
  return;
}


// ==== FUN_004e7960 @ 0x004e7960 ====

void FUN_004e7960(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_004e7810(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004e7a65:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_004e7a65;
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


// ==== FUN_004e7b40 @ 0x004e7b40 ====

/* WARNING: Removing unreachable block (ram,0x004e7b9f) */

void FUN_004e7b40(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  
  iVar3 = (int)param_2;
  puVar6 = *(undefined4 **)(in_ECX + 4);
  bVar11 = true;
  if (*(char *)((int)puVar6[1] + 0x2d) == '\0') {
    uVar1 = *(uint *)((int)param_2 + 0x14);
    puVar9 = (undefined4 *)puVar6[1];
    do {
      puVar6 = puVar9;
      uVar2 = puVar6[8];
      if ((uint)puVar6[9] < 0x10) {
        pbVar4 = (byte *)(puVar6 + 4);
      }
      else {
        pbVar4 = (byte *)puVar6[4];
      }
      if (uVar1 == 0) {
LAB_004e7bd0:
        if (uVar1 < uVar2) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar1 != uVar2);
        }
      }
      else {
        uVar8 = uVar1;
        if (uVar2 <= uVar1) {
          uVar8 = uVar2;
        }
        if (*(uint *)((int)param_2 + 0x18) < 0x10) {
          pbVar10 = (byte *)((int)param_2 + 4);
        }
        else {
          pbVar10 = *(byte **)((int)param_2 + 4);
        }
        bVar11 = false;
        uVar5 = 0;
        bVar12 = true;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          bVar11 = *pbVar10 < *pbVar4;
          bVar12 = *pbVar10 == *pbVar4;
          pbVar10 = pbVar10 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar12);
        if (!bVar12) {
          uVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (uVar5 == 0) goto LAB_004e7bd0;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x2d) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_004e7960(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_0079c420();
  }
  puVar9 = param_2;
  if (*(uint *)(iVar3 + 0x18) < 0x10) {
    iVar7 = iVar3 + 4;
  }
  else {
    iVar7 = *(int *)(iVar3 + 4);
  }
  iVar7 = FUN_00403620(0,param_2[8],iVar7,*(undefined4 *)(iVar3 + 0x14));
  if (iVar7 < 0) {
    puVar6 = (undefined4 *)FUN_004e7960(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_004e7cb0 @ 0x004e7cb0 ====

void FUN_004e7cb0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004e78a0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x2d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x2d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x2d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_005a4100(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004e7e30 @ 0x004e7e30 ====

void FUN_004e7e30(byte param_1)

{
  void *in_ECX;
  
  FUN_004e75d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e7e50 @ 0x004e7e50 ====

void FUN_004e7e50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b23b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e7e80 @ 0x004e7e80 ====

void FUN_004e7e80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b23f4;
  return;
}


// ==== FUN_004e7e90 @ 0x004e7e90 ====

void FUN_004e7e90(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b23cc;
    puVar1[1] = 0;
    *(undefined2 *)(puVar1 + 2) = 0;
  }
  puVar1[1] = param_1;
  *(undefined2 *)(puVar1 + 2) = param_2;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004e7ed0 @ 0x004e7ed0 ====

void FUN_004e7ed0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009b23e0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004e7f00 @ 0x004e7f00 ====

void FUN_004e7f00(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_0099d3f4;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004e7f40 @ 0x004e7f40 ====

undefined4 FUN_004e7f40(void)

{
  return 0x80000000;
}


// ==== FUN_004e7f50 @ 0x004e7f50 ====

undefined4 FUN_004e7f50(void)

{
  return 0x80000002;
}


// ==== FUN_004e7f70 @ 0x004e7f70 ====

void FUN_004e7f70(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2418;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004e7f90 @ 0x004e7f90 ====

undefined4 FUN_004e7f90(int param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  if (*(int *)(param_1 + 4) == 8) {
    iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if ((iVar2 == 1) || (iVar2 == 2)) goto LAB_004e7fbd;
    bVar3 = iVar2 == 4;
  }
  else {
    if (*(int *)(param_1 + 4) != 0x10) {
      return 0;
    }
    iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if ((iVar2 == 0) || (iVar2 == 3)) goto LAB_004e7fbd;
    bVar3 = iVar2 == 5;
  }
  if (!bVar3) {
    return 0;
  }
LAB_004e7fbd:
  cVar1 = (**(code **)(*DAT_00b5a994 + 0x10))(0x11);
  if (cVar1 == '\0') {
    return 0;
  }
  FUN_004d9010();
  return 1;
}


// ==== FUN_004e8000 @ 0x004e8000 ====

uint FUN_004e8000(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x20001) {
    uVar1 = FUN_004e7f90(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004e8040 @ 0x004e8040 ====

void FUN_004e8040(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2430;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004e8060 @ 0x004e8060 ====

undefined4 FUN_004e8060(int param_1)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 8:
    iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if ((iVar2 != 1) && (iVar2 != 2)) {
      bVar3 = iVar2 == 4;
LAB_004e80e3:
      if (!bVar3) {
        return 0;
      }
    }
    break;
  case 9:
    FUN_004d94a0();
    return 1;
  default:
    goto switchD_004e807d_caseD_a;
  case 0x10:
    iVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if ((iVar2 != 0) && (iVar2 != 3)) {
      bVar3 = iVar2 == 5;
      goto LAB_004e80e3;
    }
    break;
  case 0x26:
    FUN_004d9210(1);
    return 1;
  case 0x28:
    FUN_004d9210(0);
    return 1;
  }
  cVar1 = (**(code **)(*DAT_00b5a994 + 0x10))(0x11);
  if (cVar1 != '\0') {
    FUN_004d9010();
    return 1;
  }
switchD_004e807d_caseD_a:
  return 0;
}


// ==== FUN_004e8150 @ 0x004e8150 ====

uint FUN_004e8150(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x20001) {
    uVar1 = FUN_004e8060(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_004e8180 @ 0x004e8180 ====

void FUN_004e8180(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b26d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e81c0 @ 0x004e81c0 ====

void FUN_004e81c0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar2 = DAT_00b5ac5c;
  iVar1 = *(int *)(in_ECX + 8);
  fVar3 = (float10)thunk_FUN_00796ec0(iVar1 + 0x38);
  fVar4 = (float10)thunk_FUN_00796ec0(iVar1 + 0x1c);
  fVar5 = (float10)thunk_FUN_00796ec0(iVar1);
  fStack_c = (float)fVar5;
  fStack_8 = (float)fVar4;
  fStack_4 = (float)fVar3;
  (**(code **)(*piVar2 + 0x28))(&fStack_c);
  return;
}


// ==== FUN_004e8220 @ 0x004e8220 ====

void FUN_004e8220(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar2 = DAT_00b5ac5c;
  iVar1 = *(int *)(in_ECX + 8);
  fVar3 = (float10)thunk_FUN_00796ec0(iVar1 + 0x38);
  fVar4 = (float10)thunk_FUN_00796ec0(iVar1 + 0x1c);
  fVar5 = (float10)thunk_FUN_00796ec0(iVar1);
  fStack_c = (float)fVar5;
  fStack_8 = (float)fVar4;
  fStack_4 = (float)fVar3;
  (**(code **)(*piVar2 + 0x1c))(&fStack_c);
  return;
}


// ==== FUN_004e8280 @ 0x004e8280 ====

void FUN_004e8280(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar2 = DAT_00b5ac5c;
  iVar1 = *(int *)(in_ECX + 8);
  fVar3 = (float10)thunk_FUN_00796ec0(iVar1 + 0x38);
  fVar4 = (float10)thunk_FUN_00796ec0(iVar1 + 0x1c);
  fVar5 = (float10)thunk_FUN_00796ec0(iVar1);
  fStack_c = (float)fVar5;
  fStack_8 = (float)fVar4;
  fStack_4 = (float)fVar3;
  (**(code **)(*piVar2 + 0x20))(&fStack_c);
  return;
}


// ==== FUN_004e82e0 @ 0x004e82e0 ====

void FUN_004e82e0(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  
  iVar1 = *DAT_00b5ac5c;
  fVar2 = (float10)thunk_FUN_00796ec0(*(undefined4 *)(in_ECX + 8));
  (**(code **)(iVar1 + 0x24))((float)fVar2);
  return;
}


// ==== FUN_004e8300 @ 0x004e8300 ====

void FUN_004e8300(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar2 = DAT_00b5ac5c;
  iVar1 = *(int *)(in_ECX + 8);
  fVar3 = (float10)thunk_FUN_00796ec0(iVar1 + 0x38);
  fVar4 = (float10)thunk_FUN_00796ec0(iVar1 + 0x1c);
  fVar5 = (float10)thunk_FUN_00796ec0(iVar1);
  fStack_c = (float)fVar5;
  fStack_8 = (float)fVar4;
  fStack_4 = (float)fVar3;
  (**(code **)(*piVar2 + 0x14))(&fStack_c);
  return;
}


// ==== FUN_004e8360 @ 0x004e8360 ====

void FUN_004e8360(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  
  iVar1 = *DAT_00b5ac5c;
  fVar2 = (float10)thunk_FUN_00796ec0(*(undefined4 *)(in_ECX + 8));
  (**(code **)(iVar1 + 0x18))((float)fVar2);
  return;
}


// ==== FUN_004e8380 @ 0x004e8380 ====

void FUN_004e8380(void)

{
  void *unaff_EBX;
  uint unaff_ESI;
  void *unaff_EDI;
  undefined1 *_Memory;
  undefined1 auStack_5e [2];
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uStack_2c;
  uint local_1c;
  uint local_18;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uStack_2c = 0x15;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  uStack_2c = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740();
  uVar5 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_14) {
    _free(unaff_EDI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  uVar4 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < local_1c) {
    _free(&local_1c);
    return;
  }
  local_1c = 0xf;
  FUN_00401740();
  uVar3 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < unaff_ESI) {
    _free(auStack_5e + 0x3a);
    return;
  }
  FUN_00401740();
  uVar2 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uStack_2c) {
    _free(&uStack_2c);
    return;
  }
  uStack_2c = 0xf;
  FUN_00401740();
  uVar1 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar5) {
    _free(auStack_5e + 0x2a);
    return;
  }
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar4) {
    _free(auStack_5e + 0x22);
    return;
  }
  FUN_00401740(s_dirbacklight_intensity_009b24dc);
  _Memory = auStack_5e + 10;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar3) {
    _free(auStack_5e + 0x1a);
    return;
  }
  FUN_00401740(s_shadelight_pos_009b24f4,0xe);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_5e + 2,3);
  if (0xf < uVar2) {
    _free(auStack_5e + 0x12);
    return;
  }
  FUN_00401740(s_shadelight_distance_009b2504,0x13);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_5e + -6,1);
  if (uVar1 < 0x10) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_004e8630 @ 0x004e8630 ====

/* WARNING: Removing unreachable block (ram,0x004e882c) */
/* WARNING: Removing unreachable block (ram,0x004e886b) */
/* WARNING: Removing unreachable block (ram,0x004e87ed) */
/* WARNING: Removing unreachable block (ram,0x004e88ad) */

void FUN_004e8630(void)

{
  void *unaff_EBX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 *_Memory;
  undefined1 auStack_2a [2];
  undefined4 local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740();
  _Memory = auStack_2a + 10;
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
    _free(unaff_ESI);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_14) {
    _free(unaff_EDI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_18) {
    _free(&local_1c);
    return;
  }
  local_18 = 0xf;
  local_1c = (void *)0x0;
  FUN_00401740(s_dirbacklight_dir_009b2590);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (local_1c < 0x10) {
    local_1c = (void *)0xf;
    FUN_00401740(s_dirbacklight_color_009b25a4,0x12);
    (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -10);
    FUN_00401740(s_dirbacklight_intensity_009b25b8,0x16);
    (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0xe);
    FUN_00401740(s_shadelight_pos_009b25d0,0xe);
    (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x12);
    FUN_00401740(s_shadelight_distance_009b25e0,0x13);
    (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x16);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_004e88d0 @ 0x004e88d0 ====

void FUN_004e88d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b26e4;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_004e8940 @ 0x004e8940 ====

void FUN_004e8940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b26e4;
  if (in_ECX[2] != 0) {
    FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1);
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  FUN_004e8630();
  if (in_ECX[2] == 0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009b26d4;
    return;
  }
  FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1,in_ECX);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004e89c0 @ 0x004e89c0 ====

undefined4 FUN_004e89c0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  float10 fVar3;
  void *local_1c;
  void *local_18;
  uint local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401660(param_1 + 8,0,0xffffffff);
  FUN_0043b3d0(param_1 + 0x24);
  iVar2 = FUN_00403620(0,local_8,s_ambientlightint_ensity_009b25f4,0x16);
  if (iVar2 == 0) {
    iVar2 = *DAT_00b5ac5c;
    fVar3 = (float10)thunk_FUN_00796ec0(*(undefined4 *)(in_ECX + 8));
    (**(code **)(iVar2 + 0x2c))((float)fVar3);
    if (0xf < local_8) {
      _free(local_1c);
      return extraout_EAX;
    }
  }
  else {
    iVar2 = FUN_00403620(0,local_8,s_ambientlight_color_009b260c,0x12);
    if (iVar2 == 0) {
      FUN_004e81c0();
      if (0xf < local_4) {
        _free(local_18);
        return extraout_EAX_00;
      }
    }
    else {
      iVar2 = FUN_00403620(0,local_8,s_directionallight_dir_009b2620,0x14);
      if (iVar2 != 0) {
        cVar1 = FUN_004036a0(&local_1c,s_directionallight_color_009b2638);
        if (cVar1 != '\0') {
          FUN_004e8280();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(&local_1c,s_directionallight_intensity_009b2650);
        if (cVar1 != '\0') {
          FUN_004e82e0();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = FUN_004036a0(&local_1c,s_dirbacklight_dir_009b266c);
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0(&local_1c,s_dirbacklight_color_009b2680);
          if (cVar1 == '\0') {
            cVar1 = FUN_004036a0(&local_1c,s_dirbacklight_intensity_009b2694);
            if (cVar1 == '\0') {
              cVar1 = FUN_004036a0(&local_1c,s_shadelight_pos_009b26ac);
              if (cVar1 != '\0') {
                FUN_004e8300();
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              cVar1 = FUN_004036a0(&local_1c,s_shadelight_distance_009b26bc);
              if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
                FUN_00446f10();
              }
              FUN_004e8360();
            }
          }
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_004e8220();
      if (0xf < local_4) {
        _free(local_18);
        return extraout_EAX_01;
      }
    }
  }
  return 1;
}


// ==== FUN_004e8bf0 @ 0x004e8bf0 ====

undefined4 FUN_004e8bf0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_004e89c0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004e8c20 @ 0x004e8c20 ====

void FUN_004e8c20(byte param_1)

{
  void *in_ECX;
  
  FUN_004e8940();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e8c60 @ 0x004e8c60 ====

void FUN_004e8c60(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  float fVar3;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  fVar2 = (float10)thunk_FUN_00796ec0(*(undefined4 *)(in_ECX + 8));
  fVar3 = (float)fVar2;
  iVar1 = (**(code **)(*DAT_00b5a988 + 0xc))(fVar3);
  uStack_10 = *(undefined4 *)(iVar1 + 4);
  uStack_c = *(undefined4 *)(iVar1 + 8);
  uStack_8 = *(undefined4 *)(iVar1 + 0xc);
  uStack_4 = *(undefined4 *)(iVar1 + 0x10);
  fStack_14 = fVar3;
  (**(code **)(*DAT_00b5a988 + 0x10))(&fStack_14);
  return;
}


// ==== FUN_004e8cc0 @ 0x004e8cc0 ====

void FUN_004e8cc0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  float10 fVar2;
  float fVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  fVar2 = (float10)thunk_FUN_00796ec0(*(undefined4 *)(in_ECX + 8));
  fVar3 = (float)fVar2;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0xc))(fVar3);
  uStack_14 = *puVar1;
  uStack_10 = puVar1[1];
  uStack_8 = puVar1[3];
  uStack_4 = puVar1[4];
  fStack_c = fVar3;
  (**(code **)(*DAT_00b5a988 + 0x10))(&uStack_14);
  return;
}


// ==== FUN_004e8d20 @ 0x004e8d20 ====

void FUN_004e8d20(void)

{
  undefined4 *puVar1;
  int in_ECX;
  float10 fVar2;
  float fVar3;
  undefined4 uStack_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  fVar2 = (float10)thunk_FUN_00796ec0(*(undefined4 *)(in_ECX + 8));
  fVar3 = (float)fVar2;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0xc))(fVar3);
  uStack_14 = *puVar1;
  uStack_c = puVar1[2];
  uStack_8 = puVar1[3];
  uStack_4 = puVar1[4];
  fStack_10 = fVar3;
  (**(code **)(*DAT_00b5a988 + 0x10))(&uStack_14);
  return;
}


// ==== FUN_004e8d80 @ 0x004e8d80 ====

void FUN_004e8d80(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar1 = *(int *)(in_ECX + 8);
  fVar2 = (float10)thunk_FUN_00796ec0(iVar1 + 0x38);
  fVar3 = (float10)thunk_FUN_00796ec0(iVar1 + 0x1c);
  fVar4 = (float10)thunk_FUN_00796ec0(iVar1);
  fStack_c = (float)fVar4;
  fStack_8 = (float)fVar3;
  fStack_4 = (float)fVar2;
  (**(code **)(*DAT_00b5ad14 + 0x10))(&fStack_c);
  return;
}


// ==== FUN_004e8de0 @ 0x004e8de0 ====

void FUN_004e8de0(void)

{
  void *unaff_ESI;
  uint unaff_EDI;
  void *_Memory;
  int iStack_5c;
  char *pcStack_58;
  uint *puStack_50;
  char *pcStack_4c;
  undefined4 uStack_48;
  uint local_38;
  uint local_34;
  void *pvStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *local_24;
  undefined4 local_20;
  uint local_1c;
  undefined1 local_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 local_8;
  undefined4 local_4;
  
  uStack_48 = (uint *)0x16;
  pcStack_4c = s_camera_zoom__distance__009b26f4;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  puStack_50 = (uint *)0x4e8e09;
  FUN_00401740();
  uStack_48 = (uint *)0xb;
  pcStack_4c = s_camera_zoom_009b270c;
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = local_34 & 0xffffff00;
  puStack_50 = (uint *)0x4e8e25;
  FUN_00401740();
  uStack_48 = &local_1c;
  pcStack_4c = (void *)0x1;
  puStack_50 = &local_38;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_2c) {
    pcStack_58 = (char *)0x4e8e51;
    _free(unaff_ESI);
    return;
  }
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  if (0xf < uStack_10) {
    pcStack_58 = (char *)0x4e8e70;
    _free(local_24);
    return;
  }
  pcStack_58 = s_camera_horizontal__value__009b2718;
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  iStack_5c = 0x4e8e8f;
  FUN_00401740();
  pcStack_58 = s_camera_horizontal_009b2734;
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  iStack_5c = 0x4e8eab;
  FUN_00401740();
  pcStack_58 = (void *)0x1;
  iStack_5c = (int)register0x00000010 + -0x44;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_38) {
    _free(pcStack_4c);
    return;
  }
  local_38 = 0xf;
  pcStack_4c = (char *)((uint)pcStack_4c & 0xffffff00);
  if (0xf < local_1c) {
    _free(pvStack_30);
    return;
  }
  local_1c = 0xf;
  local_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  FUN_00401740(s_camera_vertical__value__009b2748,0x17);
  local_38 = 0xf;
  pcStack_4c = (char *)((uint)pcStack_4c & 0xffffff00);
  FUN_00401740(s_camera_vertical_009b2760,0xf);
  _Memory = (void *)0x1;
  (**(code **)(*DAT_00b5a6c8 + 8))(&puStack_50,1,&local_34);
  if (0xf < unaff_EDI) {
    _free(pcStack_58);
    return;
  }
  uStack_48 = (uint *)0x0;
  pcStack_58 = (char *)((uint)pcStack_58 & 0xffffff00);
  if (0xf < uStack_28) {
    _free((void *)0x0);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  FUN_00401740(s_camera_target__x___y___z__009b2770,0x19);
  uStack_48 = (void *)0x0;
  pcStack_58 = (char *)((uint)pcStack_58 & 0xffffff00);
  FUN_00401740(s_camera_target_009b278c,0xd);
  (**(code **)(*DAT_00b5a6c8 + 8))(&iStack_5c,3,(int)register0x00000010 + -0x40);
  if ((uint *)0xf < puStack_50) {
    _free(_Memory);
    return;
  }
  puStack_50 = (uint *)0xf;
  if (local_34 < 0x10) {
    return;
  }
  _free(uStack_48);
  return;
}


// ==== FUN_004e9000 @ 0x004e9000 ====

void FUN_004e9000(void)

{
  void *unaff_EBX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined4 local_1c;
  undefined1 local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_camera_zoom_009b279c,0xb);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_camera_horizontal_009b27a8,0x11);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x20);
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740(s_camera_vertical_009b27bc,0xf);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x24);
  if (0xf < uStack_10) {
    _free(unaff_ESI);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740(s_camera_target_009b27cc,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x28);
  if (uStack_14 < 0x10) {
    return;
  }
  _free(unaff_EDI);
  return;
}


// ==== FUN_004e9130 @ 0x004e9130 ====

void FUN_004e9130(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2820;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_004e91a0 @ 0x004e91a0 ====

void FUN_004e91a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2820;
  if (in_ECX[2] != 0) {
    FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1);
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  FUN_004e9000();
  if (in_ECX[2] == 0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009b26d4;
    return;
  }
  FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1,in_ECX);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_004e9220 @ 0x004e9220 ====

undefined4 FUN_004e9220(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401660(param_1 + 8,0,0xffffffff);
  FUN_0043b3d0(param_1 + 0x24);
  iVar2 = FUN_00403620(0,local_8,s_camera_zoom_009b27dc,0xb);
  if (iVar2 == 0) {
    FUN_004e8c60();
    if (0xf < local_4) {
      _free(local_18);
      return extraout_EAX;
    }
  }
  else {
    iVar2 = FUN_00403620(0,local_8,s_camera_horizontal_009b27e8,0x11);
    if (iVar2 == 0) {
      FUN_004e8cc0();
      if (0xf < local_4) {
        _free(local_18);
        return extraout_EAX_00;
      }
    }
    else {
      iVar2 = FUN_00403620(0,local_8,s_camera_vertical_009b27fc,0xf);
      if (iVar2 != 0) {
        cVar1 = FUN_004036a0(local_1c,s_camera_target_009b280c);
        if (cVar1 == '\0') {
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        FUN_004e8d80();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_004e8d20();
      if (0xf < local_4) {
        _free(local_18);
        return extraout_EAX_01;
      }
    }
  }
  return 1;
}


// ==== FUN_004e9370 @ 0x004e9370 ====

undefined4 FUN_004e9370(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_004e9220(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004e93a0 @ 0x004e93a0 ====

void FUN_004e93a0(byte param_1)

{
  void *in_ECX;
  
  FUN_004e91a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e93c0 @ 0x004e93c0 ====

undefined4 FUN_004e93c0(void)

{
  return 8;
}


// ==== FUN_004e93e0 @ 0x004e93e0 ====

void FUN_004e93e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2864;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_004e9400 @ 0x004e9400 ====

void FUN_004e9400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2864;
  (**(code **)(*DAT_00b5ad24 + 0xc))(in_ECX[3]);
  in_ECX[3] = 0;
  (**(code **)(*DAT_00b5ad24 + 0xc))(in_ECX[4]);
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009b1834;
  return;
}


// ==== FUN_004e9440 @ 0x004e9440 ====

void FUN_004e9440(int param_1)

{
  uint *puVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint auStack_34 [4];
  uint uStack_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  
  iVar2 = *(int *)(param_1 + 8);
  if ((*(int *)(param_1 + 4) != *(int *)(in_ECX + 4)) || (iVar2 != *(int *)(in_ECX + 8))) {
    *(int *)(in_ECX + 4) = *(int *)(param_1 + 4);
    *(int *)(in_ECX + 8) = iVar2;
    if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
      puVar1 = (uint *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x14))();
      puVar4 = auStack_34;
      for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = auStack_34[2] - auStack_34[0];
      iVar3 = auStack_34[3] - auStack_34[1];
      auStack_34[0] = *(int *)(in_ECX + 4) - iVar2 / 2;
      auStack_34[0] = ((int)auStack_34[0] < 1) - 1 & auStack_34[0];
      auStack_34[1] = *(int *)(in_ECX + 8) - iVar3 / 2;
      auStack_34[2] = iVar2 + auStack_34[0];
      auStack_34[1] = ((int)auStack_34[1] < 1) - 1 & auStack_34[1];
      auStack_34[3] = iVar3 + auStack_34[1];
      uStack_24 = auStack_34[0];
      uStack_20 = auStack_34[1];
      iStack_1c = auStack_34[2];
      iStack_18 = auStack_34[3];
      (**(code **)(**(int **)(in_ECX + 0xc) + 0x20))(auStack_34);
    }
    if (*(int **)(in_ECX + 0x10) != (int *)0x0) {
      puVar1 = (uint *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x14))();
      puVar4 = auStack_34;
      for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar1;
        puVar1 = puVar1 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = auStack_34[2] - auStack_34[0];
      iVar3 = auStack_34[3] - auStack_34[1];
      auStack_34[0] = *(int *)(in_ECX + 4) - iVar2 / 2;
      auStack_34[0] = ((int)auStack_34[0] < 1) - 1 & auStack_34[0];
      auStack_34[1] = *(int *)(in_ECX + 8) - iVar3 / 2;
      auStack_34[2] = iVar2 + auStack_34[0];
      auStack_34[1] = ((int)auStack_34[1] < 1) - 1 & auStack_34[1];
      auStack_34[3] = iVar3 + auStack_34[1];
      uStack_24 = auStack_34[0];
      uStack_20 = auStack_34[1];
      iStack_1c = auStack_34[2];
      iStack_18 = auStack_34[3];
      (**(code **)(**(int **)(in_ECX + 0x10) + 0x20))(auStack_34);
    }
  }
  return;
}


// ==== FUN_004e95a0 @ 0x004e95a0 ====

void FUN_004e95a0(void)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_5e [10];
  int iStack_54;
  int iStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined1 uStack_40;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a78c + 0x48))();
  if (piVar2 == (int *)0x0) {
    (**(code **)(*DAT_00b5ad24 + 0xc))(*(undefined4 *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(int *)(in_ECX + 0xc) == 0) {
    iVar3 = (**(code **)(*DAT_00b5ad24 + 8))(0xd);
    *(int *)(in_ECX + 0xc) = iVar3;
    if (iVar3 == 0) {
      return;
    }
  }
  iVar3 = (**(code **)(*piVar2 + 0x2c))();
  uVar5 = (uint)*(byte *)(iVar3 + 0x30) * 0x20;
  uStack_34 = *(int *)(in_ECX + 4) - uVar5 / 2;
  uVar6 = (uint)*(byte *)(iVar3 + 0x31) * 0x20;
  uStack_14 = 0x3fffffff;
  uStack_8 = 0xffffff;
  uStack_34 = ((int)uStack_34 < 1) - 1 & uStack_34;
  uStack_30 = *(int *)(in_ECX + 8) - uVar6 / 2;
  uStack_30 = uStack_30 & ((int)uStack_30 < 1) - 1;
  iStack_54 = uStack_34 + uVar5;
  iStack_50 = uStack_30 + uVar6;
  uStack_10 = 0;
  uStack_c = 0;
  iStack_2c = iStack_54;
  iStack_28 = iStack_50;
  uStack_24 = uStack_34;
  uStack_20 = uStack_30;
  iStack_1c = iStack_54;
  iStack_18 = iStack_50;
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x20))(&uStack_34);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x1c))(auStack_5e + -6);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x2c))();
  uVar1 = (**(code **)(*piVar2 + 0x1c))();
  iStack_54 = CONCAT22(iStack_54._2_2_,uVar1);
  iStack_50 = 0;
  uStack_4c = 0;
  uStack_40 = 0;
  uStack_48 = uVar5;
  uStack_44 = uVar6;
  (**(code **)(*piVar4 + 4))(&iStack_54);
  FUN_004dd240(0xc,0,0,0,0);
  return;
}


// ==== FUN_004e9710 @ 0x004e9710 ====

void FUN_004e9710(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_52 [2];
  void *apvStack_50 [5];
  uint uStack_3c;
  undefined1 auStack_38 [4];
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acb8 + 0x1c))();
  if (piVar1 == (int *)0x0) {
    (**(code **)(*DAT_00b5ad24 + 0xc))();
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return;
  }
  piVar1 = (int *)(**(code **)(*piVar1 + 0x10))();
  if (piVar1 == (int *)0x0) {
    (**(code **)(*DAT_00b5ad24 + 0xc))();
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(int *)(in_ECX + 0x10) == 0) {
    iVar3 = (**(code **)(*DAT_00b5ad24 + 8))(0xc);
    *(int *)(in_ECX + 0x10) = iVar3;
    if (iVar3 == 0) {
      return;
    }
  }
  uStack_34 = *(int *)(in_ECX + 4) - 0x14;
  uStack_14 = 0x3fffffff;
  uStack_34 = ((int)uStack_34 < 1) - 1 & uStack_34;
  uStack_30 = *(int *)(in_ECX + 8) - 0x14;
  uStack_30 = uStack_30 & ((int)uStack_30 < 1) - 1;
  iStack_2c = uStack_34 + 0x28;
  iStack_28 = uStack_30 + 0x28;
  uStack_24 = uStack_34;
  uStack_20 = uStack_30;
  iStack_1c = iStack_2c;
  iStack_18 = iStack_28;
  FUN_00401830(s_skill_icon_009b2830);
  uStack_10 = (**(code **)(*DAT_00b5a7c0 + 8))(apvStack_50);
  if (uStack_3c < 0x10) {
    uStack_14 = (uint)*(ushort *)(iVar2 + 0x2bb8);
    uStack_c = 0xffffffff;
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x20))(auStack_38);
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x1c))(auStack_52 + -10);
    return;
  }
  _free(apvStack_50[0]);
  return;
}


// ==== FUN_004e9860 @ 0x004e9860 ====

void FUN_004e9860(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  
  if (param_1[2] != 8) {
    if (param_1[2] == 7) {
      uVar4 = (**(code **)(*param_1 + 0x10))();
      iVar1 = param_1[7];
      iVar2 = param_1[8];
      if (((param_1[3] == 3) &&
          (piVar5 = (int *)(**(code **)(*DAT_00b5a7a8 + 0x10))(uVar4), piVar5 != (int *)0x0)) &&
         ((((iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 0xf ||
            ((((iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 1 ||
               (iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 0x13)) ||
              (iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 0xd)) ||
             ((iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 0 ||
              (iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 0x12)))))) ||
           (iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 0x14)) ||
          ((iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 0x17 ||
           (iVar6 = (**(code **)(*piVar5 + 0x18))(), iVar6 == 8)))))) {
        iVar6 = (**(code **)(*piVar5 + 0x40))();
        if (*(int *)(iVar6 + 0x14) != 0) {
          puVar7 = operator_new(0x28);
          puVar3 = (undefined4 *)0x0;
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = &PTR_FUN_009b2874;
            puVar7[8] = 0;
            puVar7[9] = 0xf;
            *(undefined1 *)(puVar7 + 4) = 0;
            puVar3 = puVar7;
          }
          FUN_004e9ae0(iVar6);
          puVar3[1] = iVar1;
          puVar3[2] = iVar2;
          FUN_00797a20(puVar3);
        }
      }
    }
    return;
  }
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar3 = &PTR_FUN_009b2850;
  FUN_00797a20(puVar3);
  return;
}


// ==== FUN_004e99a0 @ 0x004e99a0 ====

undefined4 FUN_004e99a0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x70080006) {
    if (uVar1 == 0x70080005) {
      FUN_004e95a0(param_1);
      return 1;
    }
    if (uVar1 == 0x10001) {
      FUN_004e9860(param_1);
      return 0;
    }
    if (uVar1 == 0x10021) {
      FUN_004e9440(param_1);
      return 1;
    }
  }
  else if (uVar1 == 0x70140004) {
    FUN_004e9710(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_004e9a10 @ 0x004e9a10 ====

void FUN_004e9a10(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  return;
}


// ==== FUN_004e9a30 @ 0x004e9a30 ====

undefined4 FUN_004e9a30(void)

{
  return 0x70120001;
}


// ==== FUN_004e9a40 @ 0x004e9a40 ====

void FUN_004e9a40(void)

{
  undefined4 *in_ECX;
  uint unaff_ESI;
  
  *in_ECX = &PTR_FUN_009b2864;
  (**(code **)(*DAT_00b5ad24 + 0xc))(in_ECX[3]);
  in_ECX[3] = 0;
  (**(code **)(*DAT_00b5ad24 + 0xc))(in_ECX[4]);
  in_ECX[4] = 0;
  *in_ECX = &PTR_FUN_009b1834;
  if ((unaff_ESI & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004e9aa0 @ 0x004e9aa0 ====

undefined4 FUN_004e9aa0(void)

{
  return 0x70120000;
}


// ==== FUN_004e9ab0 @ 0x004e9ab0 ====

void FUN_004e9ab0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2874;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_004e9ae0 @ 0x004e9ae0 ====

void FUN_004e9ae0(undefined4 param_1)

{
  FUN_00401660(param_1,0,0xffffffff);
  return;
}


// ==== FUN_004e9b00 @ 0x004e9b00 ====

void FUN_004e9b00(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xa4) + 0xc))(0);
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  return;
}


// ==== FUN_004e9b20 @ 0x004e9b20 ====

void FUN_004e9b20(uint param_1)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0xf4) != 0) && (*(uint *)(in_ECX + 0xf4) <= param_1)) {
    *(undefined4 *)(in_ECX + 0xf4) = 0;
    (**(code **)(**(int **)(in_ECX + 0xa4) + 0xc))(0);
    *(undefined4 *)(in_ECX + 0xf4) = 0;
  }
  return;
}


// ==== FUN_004e9b60 @ 0x004e9b60 ====

undefined4 FUN_004e9b60(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xbc) == 0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x004e9b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 0xbc) + 8))();
  return uVar1;
}


// ==== FUN_004e9b80 @ 0x004e9b80 ====

void FUN_004e9b80(int *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  if (param_1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004e9b92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 8))();
  return;
}


// ==== FUN_004e9ba0 @ 0x004e9ba0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e9ba0(void)

{
  void *pvVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xa4) == 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      piVar2 = (int *)FUN_0065b9a0();
      *(int **)(in_ECX + 0xa4) = piVar2;
      (**(code **)(*piVar2 + 0xc))(0);
      return;
    }
    *(undefined4 *)(in_ECX + 0xa4) = 0;
    (**(code **)(_DAT_00000000 + 0xc))(0);
  }
  return;
}


// ==== FUN_004e9bf0 @ 0x004e9bf0 ====

void FUN_004e9bf0(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0xa4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xa4))(1);
  }
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  return;
}


// ==== FUN_004e9c10 @ 0x004e9c10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e9c10(void)

{
  void *pvVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xa8) == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      piVar2 = (int *)FUN_0065bc50();
      *(int **)(in_ECX + 0xa8) = piVar2;
      (**(code **)(*piVar2 + 0xc))(0);
      return;
    }
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    (**(code **)(_DAT_00000000 + 0xc))(0);
  }
  return;
}


// ==== FUN_004e9c60 @ 0x004e9c60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e9c60(void)

{
  void *pvVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xac) == 0) {
    pvVar1 = operator_new(0xc);
    if (pvVar1 != (void *)0x0) {
      piVar2 = (int *)FUN_0065c120();
      *(int **)(in_ECX + 0xac) = piVar2;
      (**(code **)(*piVar2 + 0xc))(0);
      return;
    }
    *(undefined4 *)(in_ECX + 0xac) = 0;
    (**(code **)(_DAT_00000000 + 0xc))(0);
  }
  return;
}


// ==== FUN_004e9cb0 @ 0x004e9cb0 ====

void FUN_004e9cb0(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0xa8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xa8))(1);
  }
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  if (*(undefined4 **)(in_ECX + 0xac) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xac))(1);
  }
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_004e9cf0 @ 0x004e9cf0 ====

void FUN_004e9cf0(int param_1)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0xf4) != 0) && (*(uint *)(in_ECX + 0xf4) <= *(uint *)(param_1 + 8))) {
    *(undefined4 *)(in_ECX + 0xf4) = 0;
    (**(code **)(**(int **)(in_ECX + 0xa4) + 0xc))(0);
    *(undefined4 *)(in_ECX + 0xf4) = 0;
  }
  (**(code **)(*DAT_00b5ad4c + 4))();
  (**(code **)(*DAT_00b5ace4 + 4))();
  return;
}


// ==== FUN_004e9d50 @ 0x004e9d50 ====

void FUN_004e9d50(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = *(int *)(in_ECX + 0xf0);
  while (iVar3 != 0) {
    uVar2 = *(uint *)(in_ECX + 0xec) >> 2;
    iVar3 = uVar2 * -4;
    if (*(uint *)(in_ECX + 0xe8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(in_ECX + 0xe8);
    }
    puVar1 = *(undefined4 **)
              (*(int *)(*(int *)(in_ECX + 0xe4) + uVar2 * 4) +
              (*(uint *)(in_ECX + 0xec) + iVar3) * 4);
    if (*(int *)(in_ECX + 0xf0) != 0) {
      *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 1;
      if ((uint)(*(int *)(in_ECX + 0xe8) * 4) <= *(uint *)(in_ECX + 0xec)) {
        *(undefined4 *)(in_ECX + 0xec) = 0;
      }
      iVar3 = *(int *)(in_ECX + 0xf0) + -1;
      *(int *)(in_ECX + 0xf0) = iVar3;
      if (iVar3 == 0) {
        *(undefined4 *)(in_ECX + 0xec) = 0;
      }
    }
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    iVar3 = *(int *)(in_ECX + 0xf0);
  }
  return;
}


// ==== FUN_004e9de0 @ 0x004e9de0 ====

void FUN_004e9de0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0xdc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xdc))(1);
  }
  iVar3 = *(int *)(in_ECX + 0xf0);
  *(undefined4 *)(in_ECX + 0xdc) = 0;
  while( true ) {
    if (iVar3 == 0) {
      return;
    }
    uVar2 = *(uint *)(in_ECX + 0xec) >> 2;
    iVar3 = uVar2 * -4;
    if (*(uint *)(in_ECX + 0xe8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(in_ECX + 0xe8);
    }
    *(undefined4 *)(in_ECX + 0xdc) =
         *(undefined4 *)
          (*(int *)(*(int *)(in_ECX + 0xe4) + uVar2 * 4) + (*(uint *)(in_ECX + 0xec) + iVar3) * 4);
    if (*(int *)(in_ECX + 0xf0) != 0) {
      *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 1;
      if ((uint)(*(int *)(in_ECX + 0xe8) * 4) <= *(uint *)(in_ECX + 0xec)) {
        *(undefined4 *)(in_ECX + 0xec) = 0;
      }
      iVar3 = *(int *)(in_ECX + 0xf0) + -1;
      *(int *)(in_ECX + 0xf0) = iVar3;
      if (iVar3 == 0) {
        *(undefined4 *)(in_ECX + 0xec) = 0;
      }
    }
    cVar1 = (**(code **)(**(int **)(in_ECX + 0xdc) + 4))();
    if (cVar1 == '\0') break;
    if (*(undefined4 **)(in_ECX + 0xdc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0xdc))(1);
    }
    *(undefined4 *)(in_ECX + 0xdc) = 0;
    iVar3 = *(int *)(in_ECX + 0xf0);
  }
  return;
}


// ==== FUN_004e9ec0 @ 0x004e9ec0 ====

void FUN_004e9ec0(void)

{
  int iVar1;
  int in_ECX;
  undefined2 extraout_var;
  undefined4 uStack_20;
  void *pvStack_1c;
  int iStack_c;
  uint uStack_8;
  
  if (*(int *)(in_ECX + 0xbc) != 0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xbc) + 0x74))();
    uStack_20 = CONCAT22(extraout_var,*(undefined2 *)(iVar1 + 0x30));
    iStack_c = (**(code **)(*DAT_00b5ad2c + 4))(&uStack_20);
    if (iStack_c == 0) {
      uStack_8 = 0xf;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(&DAT_009b2940,0x17);
      FUN_00796d50(&uStack_20);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0xbc) + 0xc))(iStack_c);
    }
  }
  return;
}


// ==== FUN_004e9f50 @ 0x004e9f50 ====

void FUN_004e9f50(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((*(int *)(in_ECX + 0xbc) != 0) &&
     (iVar1 = (**(code **)(**(int **)(in_ECX + 0xbc) + 8))(), iVar1 != 0)) {
    (**(code **)(*DAT_00b5ad2c + 8))(iVar1);
    (**(code **)(**(int **)(in_ECX + 0xbc) + 0xc))(0);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009b2958,0x17);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004e9fe0 @ 0x004e9fe0 ====

/* WARNING: Removing unreachable block (ram,0x004ea05f) */

void FUN_004e9fe0(undefined1 param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_1a [26];
  
  if ((*(int *)(in_ECX + 0xbc) != 0) &&
     (iVar1 = (**(code **)(**(int **)(in_ECX + 0xbc) + 8))(), iVar1 != 0)) {
    (**(code **)(*DAT_00b5ad2c + 8))(iVar1);
    (**(code **)(**(int **)(in_ECX + 0xbc) + 0xc))(0);
  }
  iVar1 = (**(code **)(*DAT_00b5ad2c + 4))(&param_1);
  if (iVar1 == 0) {
    FUN_00401740(&DAT_009b2970,0x17);
    FUN_00796d50(auStack_1a + -6);
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xbc) + 0xc))(iVar1);
  }
  return;
}


// ==== FUN_004ea090 @ 0x004ea090 ====

void FUN_004ea090(void)

{
  int *piVar1;
  undefined2 *puVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if ((*(int **)(in_ECX + 0xbc) != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xbc) + 8))(), piVar1 != (int *)0x0)) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
    puVar2 = (undefined2 *)(**(code **)(*piVar1 + 0x10))();
    *(undefined2 *)(in_ECX + 0xb4) = *puVar2;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_009b2988,0x17);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_004ea120 @ 0x004ea120 ====

void FUN_004ea120(undefined4 param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  int iVar6;
  int in_ECX;
  undefined4 ******ppppppuVar7;
  undefined4 unaff_retaddr;
  undefined4 ******local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 uStack_8;
  uint local_4;
  
  bVar4 = false;
  bVar3 = false;
  if (*(int *)(in_ECX + 0xa4) == 0) {
    return;
  }
  if (*(int *)(in_ECX + 0xa0) != 0) {
    bVar4 = true;
    bVar3 = true;
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = (undefined4 ******)((uint)local_34[0] & 0xffffff00);
    pcVar5 = PTR_s_SceneLogin_00ae927c;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_s_SceneLogin_00ae927c,(int)pcVar5 - (int)(PTR_s_SceneLogin_00ae927c + 1));
    iVar6 = (**(code **)(**(int **)(in_ECX + 0xa0) + 8))(local_1c);
    ppppppuVar7 = local_34[0];
    if (local_20 < 0x10) {
      ppppppuVar7 = local_34;
    }
    iVar6 = FUN_00403620(0,*(undefined4 *)(iVar6 + 0x14),ppppppuVar7,local_24);
    if (iVar6 == 0) {
      bVar2 = true;
      goto LAB_004ea1cd;
    }
  }
  bVar2 = false;
LAB_004ea1cd:
  if (bVar3) {
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    uStack_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
  }
  if ((bVar4) && (0xf < local_20)) {
    _free(local_34[0]);
    return;
  }
  if (bVar2) {
    FUN_004f37f0(param_1);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 0xa4) + 0xc))(1);
  FUN_0065b8f0(unaff_retaddr);
  *(undefined4 *)(in_ECX + 0xf4) = param_1;
  return;
}


// ==== FUN_004ea270 @ 0x004ea270 ====

void FUN_004ea270(int param_1)

{
  char cVar1;
  char *pcVar2;
  void *local_24;
  undefined1 local_20;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0xf;
  local_10 = 0;
  local_20 = 0;
  FUN_00401740(&DAT_0099cf70,0);
  local_8 = 0;
  local_4 = 0;
  pcVar2 = (char *)(param_1 + 0x10);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(param_1 + 0x10),(int)pcVar2 - (param_1 + 0x11));
  local_4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  local_8 = *(undefined4 *)(param_1 + 0x18);
  (**(code **)(*DAT_00b5ac30 + 8))(&local_24);
  if (local_10 < 0x10) {
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_004ea310 @ 0x004ea310 ====

void FUN_004ea310(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xbc) != 0) {
    FUN_004e9f50();
    (**(code **)(**(int **)(in_ECX + 0xbc) + 4))();
    (**(code **)(*DAT_00b5a6e0 + 0x10))(1,*(undefined4 *)(in_ECX + 0xbc));
    *(undefined4 *)(in_ECX + 0xbc) = 0;
  }
  return;
}


// ==== FUN_004ea350 @ 0x004ea350 ====

void FUN_004ea350(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    if (*(int **)(in_ECX + 0xa0) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0xa0) + 0x10))();
      *(undefined4 *)(in_ECX + 0xa0) = 0;
      return;
    }
  }
  else {
    FUN_0069a470(&param_1,param_1);
    iVar2 = param_1;
    if (param_1 == *(int *)(in_ECX + 0xc4)) {
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      FUN_00401740(s_____Connect_Memento_cpp_368__009b29a0,0x1d);
      uVar3 = FUN_004022a0(local_1c,s_Select_Invalid_Scene_009b29c0,local_38);
      FUN_00796d50(uVar3);
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      if (0xf < local_20) {
        _free(local_34);
        return;
      }
    }
    else {
      if (*(int **)(in_ECX + 0xa0) != (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 0xa0) + 0x10))();
      }
      piVar1 = *(int **)(iVar2 + 0x28);
      *(int **)(in_ECX + 0xa0) = piVar1;
      (**(code **)(*piVar1 + 0xc))();
    }
  }
  return;
}


// ==== FUN_004ea450 @ 0x004ea450 ====

void FUN_004ea450(void)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  undefined4 uVar3;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 8);
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (iVar1 == 0) {
    uVar3 = 4;
    pcVar2 = &DAT_009b29d8;
  }
  else if (iVar1 == 1) {
    uVar3 = 5;
    pcVar2 = s_LOGIN_009b29e0;
  }
  else if (iVar1 == 2) {
    uVar3 = 4;
    pcVar2 = &DAT_009b29e8;
  }
  else {
    uVar3 = 7;
    pcVar2 = s_Invalid_009b29f0;
  }
  FUN_00401740(pcVar2,uVar3);
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s____Status____009b29f8,0x10);
  FUN_00796d50(local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar3 = FUN_004022a0(local_1c,s_Connect___009b2a0c,local_38);
  FUN_00796d50(uVar3);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401740(s_SerialKey___0x_08X_009b2a1c,0x16);
  uVar3 = FUN_00404230(local_1c);
  FUN_00796d50(uVar3);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401740(s_SessionServer_ID___0x_08X_009b2a34,0x1d);
  uVar3 = FUN_00404230(local_1c);
  FUN_00796d50(uVar3);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  uVar3 = FUN_004022a0(local_1c,s_CharacterName___009b2a54,in_ECX + 0x80);
  FUN_00796d50(uVar3);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if (local_20 < 0x10) {
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_004ea5f0 @ 0x004ea5f0 ====

void FUN_004ea5f0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 auStack_38 [56];
  
  if ((int *)in_ECX[0x37] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)in_ECX[0x37] + 0xc))();
    if (iVar1 == 0) {
      return;
    }
    if (iVar1 != 1) {
      if (iVar1 == 2) {
        if ((int *)*in_ECX != (int *)0x0) {
          (**(code **)(*(int *)*in_ECX + 0xc))(in_ECX[0x37]);
        }
        if ((undefined4 *)in_ECX[0x37] != (undefined4 *)0x0) {
          (*(code *)**(undefined4 **)in_ECX[0x37])(1);
        }
        in_ECX[0x37] = 0;
        return;
      }
      if (iVar1 != 3) {
        uVar2 = FUN_00401830(s_____Connect_Memento_cpp_682__009b2a6c);
        uVar2 = FUN_004022a0(auStack_38,s_Invalid_Result_009b2a8c,uVar2);
        FUN_00796d50(uVar2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if ((int *)*in_ECX != (int *)0x0) {
        (**(code **)(*(int *)*in_ECX + 0xc))(in_ECX[0x37]);
      }
      if ((undefined4 *)in_ECX[0x37] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[0x37])(1);
      }
      in_ECX[0x37] = 0;
      return;
    }
  }
  FUN_004e9de0();
  return;
}


// ==== FUN_004ea700 @ 0x004ea700 ====

void FUN_004ea700(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xbc) != 0) {
    FUN_004e9f50();
    (**(code **)(**(int **)(in_ECX + 0xbc) + 4))();
    (**(code **)(*DAT_00b5a6e0 + 0x10))(1,*(undefined4 *)(in_ECX + 0xbc));
    *(undefined4 *)(in_ECX + 0xbc) = 0;
  }
  *(undefined4 *)(in_ECX + 0xbc) = param_1;
  FUN_004e9ec0();
  return;
}


// ==== FUN_004ea750 @ 0x004ea750 ====

void FUN_004ea750(undefined1 param_1)

{
  FUN_00846af0(&param_1);
  return;
}


// ==== FUN_004ea770 @ 0x004ea770 ====

/* WARNING: Removing unreachable block (ram,0x004ea859) */

void FUN_004ea770(void)

{
  void *pvVar1;
  int in_ECX;
  undefined1 uStack00000000;
  undefined1 auStack_1a [26];
  
  (**(code **)(**(int **)(in_ECX + 0xa4) + 0xc))(0);
  *(undefined4 *)(in_ECX + 0xf4) = 0;
  FUN_004e9d50();
  if (uStack00000000 != '\0') {
    if (*(undefined4 **)(in_ECX + 0xdc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0xdc))(1);
    }
    *(undefined4 *)(in_ECX + 0xdc) = 0;
  }
  if (*(int *)(in_ECX + 8) != 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      FUN_004f5970();
    }
    FUN_00846af0(&uStack00000000);
  }
  pvVar1 = operator_new(0xc);
  if (pvVar1 != (void *)0x0) {
    FUN_004f58c0(DAT_00b5ad48);
  }
  FUN_00846af0(&uStack00000000);
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 0x78) = 0;
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  FUN_00401740(&DAT_009b2a69,0);
  FUN_004ea350(auStack_1a + -6);
  FUN_004f4f30();
  if (*(int *)(in_ECX + 0xbc) != 0) {
    FUN_004e9f50();
    (**(code **)(**(int **)(in_ECX + 0xbc) + 4))();
    (**(code **)(*DAT_00b5a6e0 + 0x10))(1,*(undefined4 *)(in_ECX + 0xbc));
    *(undefined4 *)(in_ECX + 0xbc) = 0;
  }
  FUN_004f4640();
  FUN_004f4690();
  return;
}


// ==== FUN_004ea8c0 @ 0x004ea8c0 ====

void FUN_004ea8c0(undefined4 param_1)

{
  void *pvVar1;
  int in_ECX;
  undefined4 uStack_4;
  
  FUN_004e9d50();
  if ((char)param_1 != '\0') {
    if (*(undefined4 **)(in_ECX + 0xdc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0xdc))(1);
    }
    *(undefined4 *)(in_ECX + 0xdc) = 0;
  }
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_004f58c0(DAT_00b5ad30);
  }
  FUN_00846af0(&param_1);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    uStack_4 = 0;
  }
  else {
    param_1 = 0xc800c8;
    uStack_4 = FUN_004f5d20(&param_1,3000);
  }
  FUN_00846af0(&uStack_4);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_004f5bd0(3000);
  }
  FUN_00846af0(&param_1);
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_004f5b30();
  }
  FUN_00846af0(&param_1);
  *(undefined4 *)(in_ECX + 4) = 3;
  return;
}


// ==== FUN_004ea9d0 @ 0x004ea9d0 ====

void FUN_004ea9d0(undefined4 param_1)

{
  void *pvVar1;
  int in_ECX;
  
  FUN_004e9d50();
  if ((char)param_1 != '\0') {
    if (*(undefined4 **)(in_ECX + 0xdc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0xdc))(1);
    }
    *(undefined4 *)(in_ECX + 0xdc) = 0;
  }
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_004f5b30();
  }
  FUN_00846af0(&param_1);
  *(undefined4 *)(in_ECX + 4) = 3;
  return;
}


// ==== FUN_004eaa40 @ 0x004eaa40 ====

void FUN_004eaa40(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int in_ECX;
  undefined4 local_4;
  
  pvVar3 = operator_new(8);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004f81d0();
  }
  iVar1 = *(int *)(in_ECX + 0xd0);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xd8) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xd4) - iVar1 >> 2)))
  {
    FUN_004eb9e0(*(undefined4 *)(in_ECX + 0xd4),1,&local_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0xd4);
    *puVar2 = local_4;
    *(undefined4 **)(in_ECX + 0xd4) = puVar2 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004f7f10();
  }
  iVar1 = *(int *)(in_ECX + 0xd0);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xd8) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xd4) - iVar1 >> 2)))
  {
    FUN_004eb9e0(*(undefined4 *)(in_ECX + 0xd4),1,&local_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0xd4);
    *puVar2 = local_4;
    *(undefined4 **)(in_ECX + 0xd4) = puVar2 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004f7570();
  }
  iVar1 = *(int *)(in_ECX + 0xd0);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xd8) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xd4) - iVar1 >> 2)))
  {
    FUN_004eb9e0(*(undefined4 *)(in_ECX + 0xd4),1,&local_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0xd4);
    *puVar2 = local_4;
    *(undefined4 **)(in_ECX + 0xd4) = puVar2 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004f70f0();
  }
  iVar1 = *(int *)(in_ECX + 0xd0);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xd8) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xd4) - iVar1 >> 2)))
  {
    FUN_004eb9e0(*(undefined4 *)(in_ECX + 0xd4),1,&local_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0xd4);
    *puVar2 = local_4;
    *(undefined4 **)(in_ECX + 0xd4) = puVar2 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004f6170();
  }
  iVar1 = *(int *)(in_ECX + 0xd0);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xd8) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xd4) - iVar1 >> 2)))
  {
    FUN_004eb9e0(*(undefined4 *)(in_ECX + 0xd4),1,&local_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0xd4);
    *puVar2 = local_4;
    *(undefined4 **)(in_ECX + 0xd4) = puVar2 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004f5f00();
  }
  iVar1 = *(int *)(in_ECX + 0xd0);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xd8) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xd4) - iVar1 >> 2)))
  {
    FUN_004eb9e0(*(undefined4 *)(in_ECX + 0xd4),1,&local_4);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0xd4);
    *puVar2 = local_4;
    *(undefined4 **)(in_ECX + 0xd4) = puVar2 + 1;
  }
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_004f5e30();
  }
  iVar1 = *(int *)(in_ECX + 0xd0);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xd8) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xd4) - iVar1 >> 2)))
  {
    FUN_004eb9e0(*(undefined4 *)(in_ECX + 0xd4),1,&local_4);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xd4);
  *puVar2 = local_4;
  *(undefined4 **)(in_ECX + 0xd4) = puVar2 + 1;
  return;
}


// ==== FUN_004eacf0 @ 0x004eacf0 ====

void FUN_004eacf0(int *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_42 [6];
  void *local_3c [5];
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  int *piStack_8;
  
  uVar1 = (**(code **)(*param_1 + 8))(local_3c);
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  FUN_00401660(uVar1,0,0xffffffff);
  piStack_8 = param_1;
  FUN_004ebe70(auStack_42 + -6,auStack_24);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  uStack_c = 0xf;
  if (uStack_28 < 0x10) {
    return;
  }
  _free(local_3c[0]);
  return;
}


// ==== FUN_004ead90 @ 0x004ead90 ====

void FUN_004ead90(int param_1)

{
  void *pvVar1;
  int in_ECX;
  int iStack_4;
  
  iStack_4 = in_ECX;
  FUN_004e9d50();
  if (*(undefined4 **)(in_ECX + 0xdc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xdc))(1);
  }
  *(undefined4 *)(in_ECX + 0xdc) = 0;
  if (*(int *)(in_ECX + 8) != 0) {
    pvVar1 = operator_new(8);
    if (pvVar1 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004f5970();
    }
    FUN_00846af0(&iStack_4);
  }
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    iStack_4 = 0;
  }
  else {
    iStack_4 = FUN_004f58c0(DAT_00b5ad34);
  }
  FUN_00846af0(&iStack_4);
  pvVar1 = operator_new(0x24);
  if (pvVar1 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_004f8810(param_1 + 4);
  }
  FUN_00846af0(&param_1);
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_004eae60 @ 0x004eae60 ====

void FUN_004eae60(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int in_ECX;
  int iStack_4;
  
  iStack_4 = in_ECX;
  uVar2 = (**(code **)(*DAT_00b5a6b0 + 8))();
  switch(uVar2) {
  case 0:
    cVar1 = (**(code **)(*DAT_00b5ac80 + 0xc))();
    if (cVar1 == '\x01') {
      pvVar4 = operator_new(0x18);
      if (pvVar4 == (void *)0x0) goto LAB_004eb043;
      iStack_4 = FUN_004fb320();
      goto LAB_004eb047;
    }
    pvVar4 = operator_new(0x34);
    if (pvVar4 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004fb7e0(&DAT_00aea4b4);
    }
    break;
  case 1:
  case 4:
    pvVar4 = operator_new(0x34);
    if (pvVar4 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004fb7e0(&DAT_00aea4d0);
    }
    FUN_00846af0(&iStack_4);
    pvVar4 = operator_new(0x34);
    if (pvVar4 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004fb7e0(&DAT_00aea4b4);
    }
    break;
  case 2:
    pvVar4 = operator_new(0x34);
    if (pvVar4 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004fb7e0(&DAT_00aea4d0);
    }
    FUN_00846af0(&iStack_4);
    pvVar4 = operator_new(0x34);
    if (pvVar4 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004fb7e0(&DAT_00aea508);
    }
    FUN_00846af0(&iStack_4);
    pvVar4 = operator_new(0x34);
    if (pvVar4 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004fb7e0(&DAT_00aea4b4);
    }
    FUN_00846af0(&iStack_4);
    iVar3 = (**(code **)(*DAT_00b5a6b0 + 8))();
    if ((iVar3 == 2) && (cVar1 = (**(code **)(*DAT_00b5a6d4 + 0xc))(), cVar1 == '\0')) {
      pvVar4 = operator_new(0x34);
      if (pvVar4 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_004fb7e0(&DAT_00aea524);
      }
      FUN_004ea750(uVar2);
      pvVar4 = operator_new(8);
      if (pvVar4 == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = FUN_004f5b30();
      }
      FUN_004ea750(uVar2);
      pvVar4 = operator_new(0x10);
      if (pvVar4 == (void *)0x0) {
        FUN_004ea750(0);
      }
      else {
        uVar2 = FUN_004f5bd0(5000);
        FUN_004ea750(uVar2);
      }
    }
    goto switchD_004eae7c_default;
  case 3:
    pvVar4 = operator_new(0x34);
    if (pvVar4 == (void *)0x0) {
LAB_004eb043:
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004fb7e0(&DAT_00aea4ec);
    }
LAB_004eb047:
    FUN_00846af0(&iStack_4);
    pvVar4 = operator_new(0x34);
    if (pvVar4 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004fb7e0(&DAT_00aea4b4);
    }
    break;
  default:
    goto switchD_004eae7c_default;
  }
  FUN_00846af0(&iStack_4);
switchD_004eae7c_default:
  if (*(char *)(in_ECX + 0xf8) == '\0') {
    pvVar4 = operator_new(0x24);
    if (pvVar4 == (void *)0x0) {
      iStack_4 = 0;
    }
    else {
      iStack_4 = FUN_004f8c30();
    }
    FUN_00846af0(&iStack_4);
    *(undefined1 *)(in_ECX + 0xf8) = 1;
  }
  pvVar4 = operator_new(0xc);
  if (pvVar4 == (void *)0x0) {
    iStack_4 = 0;
    FUN_00846af0(&iStack_4);
    return;
  }
  iStack_4 = FUN_004f58c0(DAT_00b5ad48);
  FUN_00846af0(&iStack_4);
  return;
}


// ==== FUN_004eb190 @ 0x004eb190 ====

undefined4 FUN_004eb190(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_004ea5f0();
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_004e9cf0(param_1);
  }
  else if (iVar2 == 0x50011) {
    iVar2 = FUN_00424500();
    if (iVar2 == 0xd000004) {
      FUN_004ea270(param_1[3]);
      return 1;
    }
  }
  else if (iVar2 == 0x50000101) {
    FUN_004ead90(param_1);
    return 1;
  }
  if ((in_ECX[0x37] != 0) &&
     (cVar1 = (**(code **)(*(int *)in_ECX[0x37] + 8))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  if (((int *)*in_ECX != (int *)0x0) &&
     (cVar1 = (**(code **)(*(int *)*in_ECX + 4))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  cVar1 = FUN_004f49d0(param_1);
  if (cVar1 == '\x01') {
    return 1;
  }
  if ((in_ECX[0x28] != 0) &&
     (cVar1 = (**(code **)(*(int *)in_ECX[0x28] + 0x14))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  if ((in_ECX[0x2a] != 0) &&
     (cVar1 = (**(code **)(*(int *)in_ECX[0x2a] + 8))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  if ((in_ECX[0x2b] == 0) ||
     (cVar1 = (**(code **)(*(int *)in_ECX[0x2b] + 8))(param_1), cVar1 != '\x01')) {
    return 0;
  }
  return 1;
}


// ==== FUN_004eb290 @ 0x004eb290 ====

void FUN_004eb290(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x50);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004f38a0();
  }
  FUN_004eacf0(uVar2);
  pvVar1 = operator_new(0x78);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00501b00();
  }
  FUN_004eacf0(uVar2);
  pvVar1 = operator_new(0x60);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004fd5a0();
  }
  FUN_004eacf0(uVar2);
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004fc340();
  }
  FUN_004eacf0(uVar2);
  pvVar1 = operator_new(0x34);
  if (pvVar1 == (void *)0x0) {
    FUN_004eacf0(0);
    return;
  }
  uVar2 = FUN_004fbb40();
  FUN_004eacf0(uVar2);
  return;
}


// ==== FUN_004eb350 @ 0x004eb350 ====

void FUN_004eb350(void)

{
  undefined4 *in_ECX;
  uint unaff_EBX;
  undefined1 auStack_1e [2];
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_cancel_wait_009b2934,0xb);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_1c);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  if ((int *)in_ECX[0x28] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x28] + 0x10))();
    in_ECX[0x28] = 0;
  }
  FUN_004f4f30();
  if (in_ECX[0x2f] != 0) {
    FUN_004e9f50();
    (**(code **)(*(int *)in_ECX[0x2f] + 4))();
    (**(code **)(*DAT_00b5a6e0 + 0x10))(1,in_ECX[0x2f]);
    in_ECX[0x2f] = 0;
  }
  if ((undefined4 *)in_ECX[0x2a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2a])(1);
  }
  in_ECX[0x2a] = 0;
  if ((undefined4 *)in_ECX[0x2b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2b])(1);
  }
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  if ((undefined4 *)in_ECX[0x29] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x29])(1);
  }
  in_ECX[0x29] = 0;
  if (in_ECX[0x32] != 0) {
    FUN_0082c4f0(*(undefined4 *)in_ECX[0x31],(undefined4 *)in_ECX[0x31],unaff_EBX & 0xffffff00);
    FUN_004ebc30(*(undefined4 *)(in_ECX[0x31] + 4));
    *(undefined4 *)(in_ECX[0x31] + 4) = in_ECX[0x31];
    in_ECX[0x32] = 0;
    *(undefined4 *)in_ECX[0x31] = in_ECX[0x31];
    *(undefined4 *)(in_ECX[0x31] + 8) = in_ECX[0x31];
  }
  *in_ECX = 0;
  FUN_004eb890(in_ECX + 0x33);
  if ((undefined4 *)in_ECX[0x2c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2c])(1);
  }
  in_ECX[0x2c] = 0;
  FUN_00506200();
  if ((undefined4 *)in_ECX[0x2e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2e])(1);
  }
  in_ECX[0x2e] = 0;
  FUN_0046cfc0();
  if ((void *)in_ECX[0x34] == (void *)0x0) {
    in_ECX[0x34] = 0;
    in_ECX[0x35] = 0;
    in_ECX[0x36] = 0;
    FUN_004ebfe0(auStack_1e + -6,*(undefined4 *)in_ECX[0x31],(undefined4 *)in_ECX[0x31]);
    _free((void *)in_ECX[0x31]);
    return;
  }
  _free((void *)in_ECX[0x34]);
  return;
}


// ==== FUN_004eb590 @ 0x004eb590 ====

void FUN_004eb590(void)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  void *unaff_EBX;
  undefined1 auStack_1c [4];
  undefined1 uStack_18;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 6) = 0xff;
  *(undefined1 *)((int)in_ECX + 0x19) = 0xff;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0xf;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[0x14] = 0xf;
  in_ECX[0x13] = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x1d] = 0xf;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x18) = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  in_ECX[0x26] = 0xf;
  in_ECX[0x25] = 0;
  *(undefined1 *)(in_ECX + 0x21) = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  *(undefined2 *)(in_ECX + 0x2d) = 0xffff;
  in_ECX[0x2f] = 0;
  iVar1 = FUN_004eb7f0();
  in_ECX[0x31] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[0x31] + 4) = in_ECX[0x31];
  *(undefined4 *)in_ECX[0x31] = in_ECX[0x31];
  *(undefined4 *)(in_ECX[0x31] + 8) = in_ECX[0x31];
  in_ECX[0x32] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  FUN_005065a0();
  FUN_004eaa40();
  FUN_004eb290();
  if (in_ECX[0x29] == 0) {
    pvVar2 = operator_new(8);
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_0065b9a0();
    }
    in_ECX[0x29] = piVar3;
    (**(code **)(*piVar3 + 0xc))(0);
  }
  if (in_ECX[0x2a] == 0) {
    pvVar2 = operator_new(0x10);
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_0065bc50();
    }
    in_ECX[0x2a] = piVar3;
    (**(code **)(*piVar3 + 0xc))(0);
  }
  if (in_ECX[0x2b] == 0) {
    pvVar2 = operator_new(0xc);
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_0065c120();
    }
    in_ECX[0x2b] = piVar3;
    (**(code **)(*piVar3 + 0xc))(0);
  }
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004f4900();
  }
  in_ECX[0x2c] = uVar4;
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_cancel_wait_009b2928,0xb);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_1c,0);
  if (uStack_c < 0x10) {
    *(undefined1 *)(in_ECX + 0x3e) = 0;
    in_ECX[0x2e] = 0;
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_004eb7a0 @ 0x004eb7a0 ====

void FUN_004eb7a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x2d) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}


// ==== FUN_004eb7f0 @ 0x004eb7f0 ====

void FUN_004eb7f0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009814d0;
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


// ==== Catch@004eb87a @ 0x004eb87a ====

void Catch_004eb87a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_004eb890 @ 0x004eb890 ====

void FUN_004eb890(int param_1)

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
      FUN_005126d0(iVar2,*piVar1,param_1);
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


// ==== FUN_004eb8e0 @ 0x004eb8e0 ====

void FUN_004eb8e0(void)

{
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  local_2c = 0xf;
  local_30 = 0;
  local_40 = 0;
  FUN_00401740(s_deque<T>_too_long_0099d358,0x11);
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


// ==== FUN_004eb950 @ 0x004eb950 ====

void * FUN_004eb950(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009814e0;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004bbcf0(param_1,param_2,param_3,param_4,param_5);
  }
  *unaff_FS_OFFSET = local_10;
  return pvVar1;
}


// ==== Catch@004eb9c5 @ 0x004eb9c5 ====

void Catch_004eb9c5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004eb9e0 @ 0x004eb9e0 ====

void FUN_004eb9e0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009814f0;
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


// ==== Catch@004ebb41 @ 0x004ebb41 ====

void Catch_004ebb41(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_004ebc30 @ 0x004ebc30 ====

void FUN_004ebc30(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_004ebc30(*(undefined4 *)((int)param_1 + 8));
  if (*(uint *)((int)param_1 + 0x24) < 0x10) {
    *(undefined4 *)((int)param_1 + 0x24) = 0xf;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    *(undefined1 *)((int)param_1 + 0x10) = 0;
    _free(param_1);
    return;
  }
  _free(*(void **)((int)param_1 + 0x10));
  return;
}


// ==== FUN_004ebc90 @ 0x004ebc90 ====

void FUN_004ebc90(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_004eb950(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_004ebd95:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_004ebd95;
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


// ==== FUN_004ebe70 @ 0x004ebe70 ====

/* WARNING: Removing unreachable block (ram,0x004ebecf) */

void FUN_004ebe70(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  bool bVar11;
  bool bVar12;
  
  iVar3 = (int)param_2;
  puVar6 = *(undefined4 **)(in_ECX + 4);
  bVar11 = true;
  if (*(char *)((int)puVar6[1] + 0x2d) == '\0') {
    uVar1 = *(uint *)((int)param_2 + 0x14);
    puVar9 = (undefined4 *)puVar6[1];
    do {
      puVar6 = puVar9;
      uVar2 = puVar6[8];
      if ((uint)puVar6[9] < 0x10) {
        pbVar4 = (byte *)(puVar6 + 4);
      }
      else {
        pbVar4 = (byte *)puVar6[4];
      }
      if (uVar1 == 0) {
LAB_004ebf00:
        if (uVar1 < uVar2) {
          uVar5 = 0xffffffff;
        }
        else {
          uVar5 = (uint)(uVar1 != uVar2);
        }
      }
      else {
        uVar8 = uVar1;
        if (uVar2 <= uVar1) {
          uVar8 = uVar2;
        }
        if (*(uint *)((int)param_2 + 0x18) < 0x10) {
          pbVar10 = (byte *)((int)param_2 + 4);
        }
        else {
          pbVar10 = *(byte **)((int)param_2 + 4);
        }
        bVar11 = false;
        uVar5 = 0;
        bVar12 = true;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          bVar11 = *pbVar10 < *pbVar4;
          bVar12 = *pbVar10 == *pbVar4;
          pbVar10 = pbVar10 + 1;
          pbVar4 = pbVar4 + 1;
        } while (bVar12);
        if (!bVar12) {
          uVar5 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        }
        if (uVar5 == 0) goto LAB_004ebf00;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x2d) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_004ebc90(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_0079c420();
  }
  puVar9 = param_2;
  if (*(uint *)(iVar3 + 0x18) < 0x10) {
    iVar7 = iVar3 + 4;
  }
  else {
    iVar7 = *(int *)(iVar3 + 4);
  }
  iVar7 = FUN_00403620(0,param_2[8],iVar7,*(undefined4 *)(iVar3 + 0x14));
  if (iVar7 < 0) {
    puVar6 = (undefined4 *)FUN_004ebc90(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_004ebfe0 @ 0x004ebfe0 ====

void FUN_004ebfe0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_004ebc30(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x2d) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x2d);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x2d);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_005a4100(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_004ec0a0 @ 0x004ec0a0 ====

void FUN_004ec0a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2b04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ec0c0 @ 0x004ec0c0 ====

void FUN_004ec0c0(void)

{
  int *in_ECX;
  
  if ((char)in_ECX[4] == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004ec0c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x18))();
  return;
}


// ==== FUN_004ec0d0 @ 0x004ec0d0 ====

void FUN_004ec0d0(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2b98;
  in_ECX[1] = param_2;
  in_ECX[3] = param_1;
  *(undefined1 *)(in_ECX + 4) = param_3;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 4))(0,s___Effect_Provider_Provier_cpp_009b2aa0,0xe);
  in_ECX[2] = uVar2;
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  uVar2 = in_ECX[2];
  *puVar3 = &PTR_FUN_009b1860;
  puVar3[1] = param_1;
  puVar3[2] = param_2;
  puVar3[3] = uVar2;
  *(undefined1 *)(puVar3 + 4) = 0;
  FUN_00797a20(puVar3);
  return;
}


// ==== FUN_004ec160 @ 0x004ec160 ====

void FUN_004ec160(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2b98;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  (**(code **)(*piVar1 + 8))(s___Effect_Provider_Provier_cpp_009b2ae0,0x22,0,in_ECX[2]);
  *in_ECX = &PTR_FUN_009b2b04;
  return;
}


// ==== FUN_004ec190 @ 0x004ec190 ====

void FUN_004ec190(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  uVar1 = *(undefined4 *)(in_ECX + 8);
  *puVar2 = &PTR_FUN_009b1874;
  puVar2[1] = uVar1;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_004ec1d0 @ 0x004ec1d0 ====

void FUN_004ec1d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  puVar1[1] = *(undefined4 *)(in_ECX + 8);
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  *puVar1 = &PTR_FUN_009b1888;
  puVar1[4] = param_4;
  puVar1[5] = param_3;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004ec230 @ 0x004ec230 ====

void FUN_004ec230(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  puVar1[1] = *(undefined4 *)(in_ECX + 8);
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  *puVar1 = &PTR_FUN_009b2b34;
  puVar1[4] = param_4;
  puVar1[5] = param_3;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004ec290 @ 0x004ec290 ====

void FUN_004ec290(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  puVar1[1] = *(undefined4 *)(in_ECX + 8);
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  *puVar1 = &PTR_FUN_009b2b48;
  puVar1[4] = param_4;
  puVar1[5] = param_3;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004ec2f0 @ 0x004ec2f0 ====

void FUN_004ec2f0(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  puVar1[1] = *(undefined4 *)(in_ECX + 8);
  puVar1[2] = param_1;
  *puVar1 = &PTR_FUN_009b2b70;
  puVar1[3] = *param_2;
  puVar1[4] = param_2[1];
  puVar1[5] = param_2[2];
  puVar1[6] = param_3;
  puVar1[7] = param_5;
  puVar1[8] = param_4;
  puVar1[9] = param_6;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_004ec370 @ 0x004ec370 ====

void FUN_004ec370(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
  if (iVar1 == 0) {
    FUN_00797a20(0);
    return;
  }
  uVar2 = FUN_004ec4e0(*(undefined4 *)(in_ECX + 8),param_1,param_2,param_3,param_5,param_4,param_6);
  FUN_00797a20(uVar2);
  return;
}


// ==== FUN_004ec3d0 @ 0x004ec3d0 ====

void FUN_004ec3d0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  uVar1 = *(undefined4 *)(in_ECX + 8);
  *puVar2 = &PTR_FUN_009b2b84;
  puVar2[1] = uVar1;
  FUN_00797a20(puVar2);
  return;
}


// ==== FUN_004ec410 @ 0x004ec410 ====

void FUN_004ec410(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  undefined4 unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009b2b98;
  in_ECX[1] = param_2;
  in_ECX[3] = param_1;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 4))(0,s___Effect_Provider_Provier_cpp_009b2ac0,0x1a);
  in_ECX[2] = uVar2;
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  uVar2 = in_ECX[2];
  *puVar3 = &PTR_FUN_009b2bc8;
  puVar3[1] = param_1;
  puVar3[2] = param_2;
  puVar3[3] = uVar2;
  puVar3[10] = 0xf;
  puVar3[9] = 0;
  *(undefined1 *)(puVar3 + 5) = 0;
  FUN_00401660(unaff_retaddr,0,0xffffffff);
  FUN_00797a20(puVar3);
  return;
}


// ==== FUN_004ec4c0 @ 0x004ec4c0 ====

undefined4 FUN_004ec4c0(void)

{
  return 0x6001000a;
}


// ==== FUN_004ec4d0 @ 0x004ec4d0 ====

undefined4 FUN_004ec4d0(void)

{
  return 0x60010008;
}


// ==== FUN_004ec4e0 @ 0x004ec4e0 ====

void FUN_004ec4e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  in_ECX[2] = param_2;
  *in_ECX = &PTR_FUN_009b2b5c;
  in_ECX[3] = *param_3;
  in_ECX[4] = param_3[1];
  in_ECX[5] = param_3[2];
  in_ECX[6] = *param_4;
  in_ECX[7] = param_4[1];
  in_ECX[8] = param_4[2];
  in_ECX[9] = param_5;
  in_ECX[10] = param_6;
  in_ECX[0xb] = param_7;
  return;
}


// ==== FUN_004ec540 @ 0x004ec540 ====

undefined4 FUN_004ec540(void)

{
  return 0x60010004;
}


// ==== FUN_004ec5a0 @ 0x004ec5a0 ====

undefined4 FUN_004ec5a0(void)

{
  return 0x60010005;
}


// ==== FUN_004ec5b0 @ 0x004ec5b0 ====

undefined4 FUN_004ec5b0(void)

{
  return 0x60010006;
}


// ==== FUN_004ec5c0 @ 0x004ec5c0 ====

void FUN_004ec5c0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  uint uVar2;
  
  *in_ECX = &PTR_FUN_009b2b98;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uVar2 = 0;
  (**(code **)(*piVar1 + 8))(s___Effect_Provider_Provier_cpp_009b2ae0,0x22,0,in_ECX[2]);
  *in_ECX = &PTR_FUN_009b2b04;
  if ((uVar2 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ec610 @ 0x004ec610 ====

undefined4 FUN_004ec610(void)

{
  return 0x60010007;
}


// ==== FUN_004ec620 @ 0x004ec620 ====

void FUN_004ec620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2bc8;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_004ec650 @ 0x004ec650 ====

void FUN_004ec650(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2bdc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ec680 @ 0x004ec680 ====

undefined1 FUN_004ec680(void)

{
  return 1;
}


// ==== FUN_004ec690 @ 0x004ec690 ====

void FUN_004ec690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2be8;
  return;
}


// ==== FUN_004ec6b0 @ 0x004ec6b0 ====

undefined1 FUN_004ec6b0(void)

{
  return 0;
}


// ==== FUN_004ec6c0 @ 0x004ec6c0 ====

void FUN_004ec6c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2bf4;
  return;
}


// ==== FUN_004ec6d0 @ 0x004ec6d0 ====

void FUN_004ec6d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2c08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004ec700 @ 0x004ec700 ====

void FUN_004ec700(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2c40;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004ec7c0 @ 0x004ec7c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ec7c0(undefined4 *param_1,float *param_2)

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
  if (_DAT_009b2c00 <
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


// ==== FUN_004ec8e0 @ 0x004ec8e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004ec8e0(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int in_ECX;
  float10 fVar7;
  undefined1 auStack_3e [2];
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  char cStack_c;
  float fStack_8;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x38))();
    if ((char)uVar2 != '\0') {
      piVar3 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x28))();
      uStack_2c = *puVar4;
      uStack_28 = puVar4[1];
      uVar5 = (**(code **)(*piVar1 + 0x28))();
      puVar4 = (undefined4 *)FUN_004ec7c0(auStack_3e + -6,uVar5);
      uStack_24 = *puVar4;
      uStack_20 = puVar4[1];
      uStack_1c = (**(code **)(*DAT_00b5a6ac + 0x20))();
      iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
      if (*(int **)(iVar6 + 0x74) == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)(**(code **)(**(int **)(iVar6 + 0x74) + 0x14))();
      }
      iVar6 = (**(code **)(*piVar3 + 8))();
      uStack_18 = *(undefined1 *)(iVar6 + 4);
      uVar5 = (**(code **)(*piVar1 + 0x28))();
      puVar4 = (undefined4 *)FUN_004ec7c0(auStack_3e + -6,uVar5);
      uStack_14 = *puVar4;
      uStack_10 = puVar4[1];
      cStack_c = (**(code **)(*DAT_00b5ad54 + 0x68))();
      if (cStack_c == '\0') {
        fVar7 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
      }
      else {
        fVar7 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
      }
      fStack_8 = (float)fVar7;
      FUN_00507870(&uStack_2c,auStack_3c);
      iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
      if (*(int **)(iVar6 + 0x4c) == (int *)0x0) {
        uVar2 = (**(code **)(_DAT_00000000 + 0x20))(auStack_3c);
        return uVar2;
      }
      piVar1 = (int *)(**(code **)(**(int **)(iVar6 + 0x4c) + 0x18))();
      uVar2 = (**(code **)(*piVar1 + 0x20))(auStack_3c);
      return uVar2;
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_004eca30 @ 0x004eca30 ====

void FUN_004eca30(undefined4 *param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  undefined4 uStack_4c;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  float fStack_4;
  
  cVar2 = FUN_004ec8e0();
  if (cVar2 != '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    cVar2 = (**(code **)(*DAT_00b5ad54 + 0x68))();
    uStack_4c = CONCAT13(cVar2,(undefined3)uStack_4c);
    if (cVar2 == '\0') {
      fVar10 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
    }
    else {
      fVar10 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x28))();
    uStack_28 = *puVar5;
    uStack_24 = puVar5[1];
    puVar5 = (undefined4 *)FUN_004ec7c0(auStack_40,param_1);
    uStack_20 = *puVar5;
    uStack_1c = puVar5[1];
    uStack_18 = uVar3;
    iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar6 + 0x74) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(iVar6 + 0x74) + 0x14))();
    }
    iVar6 = (**(code **)(*piVar4 + 8))();
    uStack_14 = *(undefined1 *)(iVar6 + 4);
    puVar5 = (undefined4 *)FUN_004ec7c0(auStack_40,param_1);
    uStack_10 = *puVar5;
    uStack_c = puVar5[1];
    uStack_8 = (**(code **)(*DAT_00b5ad54 + 0x68))();
    cVar2 = (**(code **)(*DAT_00b5ad54 + 0x68))();
    if (cVar2 == '\0') {
      fVar11 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
    }
    else {
      fVar11 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
    }
    fStack_4 = (float)fVar11;
    FUN_00507870(&uStack_28,auStack_38);
    iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar6 + 0x4c) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(iVar6 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar4 + 0x24))(auStack_38);
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 != (undefined4 *)0x0) {
      piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      piVar7 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      piVar7 = (int *)(**(code **)(*piVar7 + 0x14))();
      iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
      if (*(int **)(iVar6 + 0x74) == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)(**(code **)(**(int **)(iVar6 + 0x74) + 0x14))();
      }
      iVar6 = (**(code **)(*piVar8 + 8))();
      bVar1 = *(byte *)(iVar6 + 4);
      puVar9 = (undefined4 *)(**(code **)(*piVar4 + 0x28))();
      uVar3 = (**(code **)(*piVar7 + 8))();
      puVar5[1] = uVar3;
      *puVar5 = &PTR_FUN_009b2c28;
      puVar5[2] = *puVar9;
      puVar5[3] = puVar9[1];
      puVar5[4] = *param_1;
      puVar5[5] = param_1[1];
      puVar5[6] = uStack_4c;
      puVar5[7] = (uint)bVar1;
      puVar5[8] = (float)fVar10;
      *(char *)(puVar5 + 9) = (char)((uint)unaff_EDI >> 0x18);
      *(undefined1 *)((int)puVar5 + 0x25) = 1;
      FUN_00797a20(puVar5);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_004ecc60 @ 0x004ecc60 ====

void FUN_004ecc60(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x28))();
    FUN_004eca30(uVar2);
  }
  return;
}


// ==== FUN_004ecc90 @ 0x004ecc90 ====

bool FUN_004ecc90(void)

{
  char cVar1;
  
  cVar1 = FUN_004ec8e0();
  return cVar1 != '\0';
}


// ==== FUN_004ecca0 @ 0x004ecca0 ====

uint FUN_004ecca0(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  uVar2 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x38))();
    if ((char)uVar2 != '\0') {
      uVar3 = (**(code **)(*piVar1 + 0x28))();
      uVar2 = FUN_004eca30(uVar3);
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_004ecce0 @ 0x004ecce0 ====

undefined4 FUN_004ecce0(void)

{
  return 0x30060003;
}


// ==== FUN_004ecd00 @ 0x004ecd00 ====

void FUN_004ecd00(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2c68;
  in_ECX[1] = param_1;
  *(undefined1 *)(in_ECX + 2) = 0;
  return;
}


// ==== FUN_004ecd20 @ 0x004ecd20 ====

bool FUN_004ecd20(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  return iVar1 != 0;
}


// ==== FUN_004ecde0 @ 0x004ecde0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ecde0(undefined4 *param_1,float *param_2)

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
  if (_DAT_009b2c60 <
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


// ==== FUN_004ecf00 @ 0x004ecf00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ecf00(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  undefined1 auStack_3e [2];
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  char cStack_c;
  float fStack_8;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x28))();
  uStack_2c = *puVar3;
  uStack_28 = puVar3[1];
  uVar4 = (**(code **)(*piVar1 + 0x28))();
  puVar3 = (undefined4 *)FUN_004ecde0(auStack_3e + -6,uVar4);
  uStack_24 = *puVar3;
  uStack_20 = puVar3[1];
  uStack_1c = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar5 + 0x74) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar5 + 0x74) + 0x14))();
  }
  iVar5 = (**(code **)(*piVar2 + 8))();
  uStack_18 = *(undefined1 *)(iVar5 + 4);
  uVar4 = (**(code **)(*piVar1 + 0x28))();
  puVar3 = (undefined4 *)FUN_004ecde0(auStack_3e + -6,uVar4);
  uStack_14 = *puVar3;
  uStack_10 = puVar3[1];
  cStack_c = (**(code **)(*DAT_00b5ad54 + 0x68))();
  if (cStack_c == '\0') {
    fVar6 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
  }
  else {
    fVar6 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
  }
  fStack_8 = (float)fVar6;
  FUN_00507870(&uStack_2c,auStack_3c);
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    uVar4 = (**(code **)(_DAT_00000000 + 0x20))(auStack_3c);
    return uVar4;
  }
  piVar1 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  uVar4 = (**(code **)(*piVar1 + 0x20))(auStack_3c);
  return uVar4;
}


// ==== FUN_004ed050 @ 0x004ed050 ====

void FUN_004ed050(undefined4 *param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  undefined4 uStack_4c;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  float fStack_4;
  
  cVar2 = FUN_004ecf00();
  if (cVar2 != '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    cVar2 = (**(code **)(*DAT_00b5ad54 + 0x68))();
    uStack_4c = CONCAT13(cVar2,(undefined3)uStack_4c);
    if (cVar2 == '\0') {
      fVar10 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
    }
    else {
      fVar10 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x28))();
    uStack_28 = *puVar5;
    uStack_24 = puVar5[1];
    puVar5 = (undefined4 *)FUN_004ecde0(auStack_40,param_1);
    uStack_20 = *puVar5;
    uStack_1c = puVar5[1];
    uStack_18 = uVar3;
    iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar6 + 0x74) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(iVar6 + 0x74) + 0x14))();
    }
    iVar6 = (**(code **)(*piVar4 + 8))();
    uStack_14 = *(undefined1 *)(iVar6 + 4);
    puVar5 = (undefined4 *)FUN_004ecde0(auStack_40,param_1);
    uStack_10 = *puVar5;
    uStack_c = puVar5[1];
    uStack_8 = (**(code **)(*DAT_00b5ad54 + 0x68))();
    cVar2 = (**(code **)(*DAT_00b5ad54 + 0x68))();
    if (cVar2 == '\0') {
      fVar11 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
    }
    else {
      fVar11 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
    }
    fStack_4 = (float)fVar11;
    FUN_00507870(&uStack_28,auStack_38);
    iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar6 + 0x4c) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(iVar6 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar4 + 0x24))(auStack_38);
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 != (undefined4 *)0x0) {
      piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      piVar7 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      piVar7 = (int *)(**(code **)(*piVar7 + 0x14))();
      iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
      if (*(int **)(iVar6 + 0x74) == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)(**(code **)(**(int **)(iVar6 + 0x74) + 0x14))();
      }
      iVar6 = (**(code **)(*piVar8 + 8))();
      bVar1 = *(byte *)(iVar6 + 4);
      puVar9 = (undefined4 *)(**(code **)(*piVar4 + 0x28))();
      uVar3 = (**(code **)(*piVar7 + 8))();
      puVar5[1] = uVar3;
      *puVar5 = &PTR_FUN_009b2c28;
      puVar5[2] = *puVar9;
      puVar5[3] = puVar9[1];
      puVar5[4] = *param_1;
      puVar5[5] = param_1[1];
      puVar5[6] = uStack_4c;
      puVar5[7] = (uint)bVar1;
      puVar5[8] = (float)fVar10;
      *(char *)(puVar5 + 9) = (char)((uint)unaff_EDI >> 0x18);
      *(undefined1 *)((int)puVar5 + 0x25) = 1;
      FUN_00797a20(puVar5);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_004ed280 @ 0x004ed280 ====

void FUN_004ed280(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = 1;
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x28))();
    FUN_004ed050(uVar2);
  }
  return;
}


// ==== FUN_004ed2b0 @ 0x004ed2b0 ====

undefined4 FUN_004ed2b0(void)

{
  int *piVar1;
  int *piVar2;
  float *pfVar3;
  float *pfVar4;
  undefined4 uVar5;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
  pfVar4 = (float *)(**(code **)(*piVar1 + 0x28))();
  if (DAT_0099d080 <
      SQRT((pfVar3[1] - pfVar4[1]) * (pfVar3[1] - pfVar4[1]) +
           (*pfVar3 - *pfVar4) * (*pfVar3 - *pfVar4))) {
    uVar5 = (**(code **)(*piVar1 + 0x28))();
    FUN_004ed050(uVar5);
  }
  return 1;
}


// ==== FUN_004ed340 @ 0x004ed340 ====

undefined1 FUN_004ed340(void)

{
  return 1;
}


// ==== FUN_004ed350 @ 0x004ed350 ====

undefined4 FUN_004ed350(float param_1)

{
  int in_ECX;
  float10 extraout_ST0;
  
  FUN_005080a0(*(undefined4 *)(in_ECX + 8));
  FUN_005080d0();
  if ((float10)param_1 < extraout_ST0) {
    return 1;
  }
  return 0;
}


// ==== FUN_004ed380 @ 0x004ed380 ====

void FUN_004ed380(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *in_ECX;
  
  *(undefined1 *)(in_ECX + 1) = param_3;
  *in_ECX = &PTR_FUN_009b2ca0;
  in_ECX[2] = param_2;
  in_ECX[3] = param_1;
  return;
}


// ==== FUN_004ed3a0 @ 0x004ed3a0 ====

uint FUN_004ed3a0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  return CONCAT31((int3)((uint)iVar2 >> 8),*(byte *)(iVar2 + 0x2bbc) >> 5) & 0xffffff01;
}


// ==== FUN_004ed3d0 @ 0x004ed3d0 ====

bool FUN_004ed3d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  float10 fVar6;
  
  iVar2 = (**(code **)(*DAT_00b5acc0 + 0xc))(*(undefined4 *)(in_ECX + 8));
  if (iVar2 != 0) {
    return false;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 0xc));
  if (piVar3 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar3 + 0x38))();
    if (cVar1 != '\0') {
      piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      iVar2 = *piVar3;
      uVar5 = (**(code **)(*piVar4 + 0x28))();
      fVar6 = (float10)(**(code **)(iVar2 + 0x48))(uVar5);
      cVar1 = FUN_004ed350((float)fVar6);
      return cVar1 != '\0';
    }
  }
  return false;
}


// ==== FUN_004ed490 @ 0x004ed490 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ed490(undefined4 *param_1,float *param_2)

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
  if (_DAT_009b2c98 <
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


// ==== FUN_004ed560 @ 0x004ed560 ====

void FUN_004ed560(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  int unaff_EBP;
  bool bVar6;
  float10 fVar7;
  undefined1 auStack_3e [18];
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar2 = (**(code **)(*DAT_00b5acc0 + 0xc))(*(undefined4 *)(in_ECX + 8));
  if ((iVar2 == 0) || (iVar2 == 5)) {
    piVar3 = (int *)(**(code **)(*DAT_00b5ad5c + 0xc))(*(undefined4 *)(in_ECX + 0xc));
    if (piVar3 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*piVar3 + 4))();
      if (piVar4 != (int *)0x0) {
        cVar1 = (**(code **)(*piVar3 + 0x2c))();
        if (cVar1 == '\0') {
          iVar2 = (**(code **)(*piVar4 + 0x40))();
          uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,(-(uint)(iVar2 != 8) & 0x27ffc0) + 0x1180069)
          ;
          uStack_14 = 0xf;
          uStack_18 = 0;
          uStack_28 = 0;
          FUN_00401660(uVar5,0,0xffffffff);
          piVar3 = DAT_00b5ad0c;
          FUN_00401660(&uStack_2c,0,0xffffffff);
          (**(code **)(*piVar3 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = (**(code **)(*piVar4 + 0x38))();
        if (cVar1 == '\x01') {
          cVar1 = FUN_004ed3a0();
          bVar6 = cVar1 == '\x01';
        }
        else {
          cVar1 = FUN_004ed3a0();
          bVar6 = cVar1 == '\0';
        }
        if (!bVar6) {
          if (unaff_EBP != 0) {
            iVar2 = *DAT_00b5acdc;
            uVar5 = FUN_004e5cf0(*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 8),
                                 *(undefined1 *)(in_ECX + 4));
            (**(code **)(iVar2 + 8))(uVar5);
            return;
          }
          piVar3 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
          iVar2 = *piVar4;
          uVar5 = (**(code **)(*piVar3 + 0x28))();
          fVar7 = (float10)(**(code **)(iVar2 + 0x48))(uVar5);
          cVar1 = FUN_004ed350((float)fVar7);
          if (cVar1 == '\0') {
            iVar2 = *DAT_00b5acdc;
            uVar5 = FUN_004e5cf0(*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 8),
                                 *(undefined1 *)(in_ECX + 4));
            (**(code **)(iVar2 + 8))(uVar5);
            iVar2 = *DAT_00b5acdc;
            uVar5 = FUN_004e5cb0(*(undefined4 *)(in_ECX + 0xc));
            (**(code **)(iVar2 + 8))(uVar5);
            return;
          }
          FUN_004ed790();
          uVar5 = (**(code **)(*piVar4 + 0x28))();
          iVar2 = FUN_004ed490(auStack_3e + -0xe,uVar5);
          uStack_2c = *(undefined4 *)(iVar2 + 4);
          (**(code **)(*DAT_00b5acc0 + 0x10))(auStack_3e + -6,*(undefined4 *)(in_ECX + 8));
          iVar2 = *DAT_00b5acdc;
          uVar5 = (**(code **)(*DAT_00b5acdc + 0x14))();
          (**(code **)(iVar2 + 0x10))(uVar5);
        }
      }
    }
  }
  return;
}


// ==== FUN_004ed790 @ 0x004ed790 ====

void FUN_004ed790(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *in_ECX = 2;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_004ed7f0 @ 0x004ed7f0 ====

undefined1 FUN_004ed7f0(void)

{
  return 1;
}


// ==== FUN_004ed830 @ 0x004ed830 ====

void FUN_004ed830(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *in_ECX;
  
  *(undefined1 *)(in_ECX + 1) = param_3;
  *in_ECX = &PTR_FUN_009b2ccc;
  in_ECX[2] = *param_1;
  in_ECX[3] = param_1[1];
  in_ECX[4] = param_2;
  return;
}


// ==== FUN_004ed8a0 @ 0x004ed8a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ed8a0(undefined4 *param_1,float *param_2)

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
  if (_DAT_009b2cc4 <
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


// ==== FUN_004ed970 @ 0x004ed970 ====

void FUN_004ed970(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  float *pfVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int in_ECX;
  float10 extraout_ST0;
  undefined1 uVar10;
  undefined1 auStack_2a [10];
  undefined4 uStack_20;
  int iStack_1c;
  undefined1 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iStack_1c = (**(code **)(*DAT_00b5acc0 + 0xc))(*(undefined4 *)(in_ECX + 0x10));
  if ((iStack_1c == 0) || (iStack_1c == 5)) {
    pfVar1 = (float *)(in_ECX + 8);
    piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    pfVar7 = (float *)(**(code **)(*piVar6 + 0x28))();
    fVar2 = *pfVar1;
    fVar3 = *pfVar7;
    fVar5 = *(float *)(in_ECX + 0xc) - pfVar7[1];
    FUN_005080a0(*(undefined4 *)(in_ECX + 0x10));
    FUN_005080d0();
    if (extraout_ST0 <=
        SQRT((float10)(fVar2 - fVar3) * (float10)(fVar2 - fVar3) + (float10)fVar5 * (float10)fVar5))
    {
      iVar4 = *DAT_00b5acdc;
      uVar9 = FUN_004e5da0(pfVar1,0,1);
      (**(code **)(iVar4 + 8))(uVar9);
      uVar10 = *(undefined1 *)(in_ECX + 4);
      uVar9 = *(undefined4 *)(in_ECX + 0x10);
    }
    else {
      if (iStack_1c == 0) {
        fStack_14 = *pfVar1;
        uStack_c = 0;
        uStack_10 = *(undefined4 *)(in_ECX + 0xc);
        uStack_8 = 0;
        uStack_18 = *(undefined1 *)(in_ECX + 4);
        uStack_20 = 1;
        puVar8 = (undefined4 *)FUN_004ed8a0(auStack_2a + -6,pfVar1);
        uStack_c = *puVar8;
        uStack_8 = puVar8[1];
        (**(code **)(*DAT_00b5acc0 + 0x10))(&uStack_20,*(undefined4 *)(in_ECX + 0x10));
        iVar4 = *DAT_00b5acdc;
        uVar9 = (**(code **)(*DAT_00b5acdc + 0x14))();
        (**(code **)(iVar4 + 0x10))(uVar9);
        return;
      }
      uVar10 = *(undefined1 *)(in_ECX + 4);
      uVar9 = *(undefined4 *)(in_ECX + 0x10);
    }
    iVar4 = *DAT_00b5acdc;
    uVar9 = FUN_004e5d20(pfVar1,uVar9,uVar10);
    (**(code **)(iVar4 + 8))(uVar9);
  }
  return;
}


// ==== FUN_004edae0 @ 0x004edae0 ====

undefined4 FUN_004edae0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  float *pfVar5;
  int in_ECX;
  float10 extraout_ST0;
  
  iVar3 = (**(code **)(*DAT_00b5acc0 + 0xc))(*(undefined4 *)(in_ECX + 0x10));
  if (iVar3 == 0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    pfVar5 = (float *)(**(code **)(*piVar4 + 0x28))();
    fVar1 = *(float *)(in_ECX + 8) - *pfVar5;
    fVar2 = *(float *)(in_ECX + 0xc) - pfVar5[1];
    FUN_005080a0(*(undefined4 *)(in_ECX + 0x10));
    FUN_005080d0();
    if (SQRT((float10)fVar1 * (float10)fVar1 + (float10)fVar2 * (float10)fVar2) < extraout_ST0) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004edbc0 @ 0x004edbc0 ====

void FUN_004edbc0(undefined4 param_1,undefined1 param_2,undefined1 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *(undefined1 *)(in_ECX + 1) = param_2;
  *in_ECX = &PTR_FUN_009b2da0;
  *(undefined1 *)((int)in_ECX + 5) = param_3;
  in_ECX[2] = param_1;
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    in_ECX[3] = *(undefined4 *)(iVar2 + 0x38);
  }
  return;
}


// ==== FUN_004edc10 @ 0x004edc10 ====

undefined4 * FUN_004edc10(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int in_ECX;
  
  puVar4 = operator_new(0x10);
  if (puVar4 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  uVar1 = *(undefined1 *)(in_ECX + 5);
  uVar2 = *(undefined1 *)(in_ECX + 4);
  uVar3 = *(undefined4 *)(in_ECX + 8);
  *puVar4 = &PTR_FUN_009b2da0;
  *(undefined1 *)(puVar4 + 1) = uVar2;
  *(undefined1 *)((int)puVar4 + 5) = uVar1;
  puVar4[2] = uVar3;
  piVar5 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(uVar3);
  if (piVar5 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar5 + 0x10))();
    puVar4[3] = *(undefined4 *)(iVar6 + 0x38);
  }
  return puVar4;
}


// ==== FUN_004edc70 @ 0x004edc70 ====

bool FUN_004edc70(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ad9c + 8))();
  if (cVar1 == '\x01') {
    return true;
  }
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if (cVar1 == '\0') {
    return false;
  }
  cVar1 = (**(code **)(*DAT_00b5ad04 + 4))();
  if ((cVar1 == '\x01') && (cVar1 = (**(code **)(*DAT_00b5ada8 + 0x20))(), cVar1 == '\0')) {
    return false;
  }
  cVar1 = (**(code **)(*DAT_00b5ad04 + 0x10))(*(undefined4 *)(in_ECX + 8));
  return cVar1 != '\0';
}


// ==== FUN_004edd30 @ 0x004edd30 ====

byte FUN_004edd30(char param_1,char param_2,undefined4 param_3)

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
  if ((param_1 == '\x01') && (param_2 == '\x02')) {
switchD_004edd9a_caseD_1:
    bVar3 = 4;
  }
  else {
    switch(param_2) {
    case '\x01':
    case '\x0e':
    case '\x16':
    case '\x17':
      goto switchD_004edd9a_caseD_1;
    case '\x02':
    case '\t':
    case '\v':
    case '\x0f':
      bVar3 = 2;
      break;
    default:
      bVar3 = 5;
      break;
    case '\a':
    case '\b':
      bVar3 = 1;
    }
  }
  if (bVar2 < bVar3) {
    return bVar2;
  }
  return 0;
}


// ==== FUN_004ede40 @ 0x004ede40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ede40(undefined4 *param_1,float *param_2)

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
  if (_DAT_009b2d74 <
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


// ==== FUN_004edf10 @ 0x004edf10 ====

float10 FUN_004edf10(float *param_1)

{
  int *piVar1;
  float *pfVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar2 = (float *)(**(code **)(*piVar1 + 0x28))();
  if (SQRT((*param_1 - *pfVar2) * (*param_1 - *pfVar2) +
           (param_1[1] - pfVar2[1]) * (param_1[1] - pfVar2[1])) -
      (*(float *)(in_ECX + 0xc) + DAT_009b2dbc) < DAT_0099cdc8) {
    return (float10)0.0;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar2 = (float *)(**(code **)(*piVar1 + 0x28))();
  return SQRT(((float10)*param_1 - (float10)*pfVar2) * ((float10)*param_1 - (float10)*pfVar2) +
              ((float10)param_1[1] - (float10)pfVar2[1]) *
              ((float10)param_1[1] - (float10)pfVar2[1])) -
         ((float10)*(float *)(in_ECX + 0xc) + (float10)DAT_009b2dbc);
}


// ==== FUN_004edfb0 @ 0x004edfb0 ====

void FUN_004edfb0(undefined4 *param_1)

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


// ==== FUN_004ee040 @ 0x004ee040 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_004ee040(undefined4 param_1)

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


// ==== FUN_004ee090 @ 0x004ee090 ====

undefined4 FUN_004ee090(void)

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


// ==== FUN_004ee0f0 @ 0x004ee0f0 ====

void FUN_004ee0f0(void)

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


// ==== FUN_004ee180 @ 0x004ee180 ====

void FUN_004ee180(undefined4 param_1)

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


// ==== FUN_004ee1d0 @ 0x004ee1d0 ====

undefined4 FUN_004ee1d0(int param_1)

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


// ==== FUN_004ee240 @ 0x004ee240 ====

bool FUN_004ee240(void)

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
  iVar4 = FUN_004edd30(uVar2,uVar1,uVar6);
  return iVar4 == 0;
}


// ==== FUN_004ee2c0 @ 0x004ee2c0 ====

undefined4 FUN_004ee2c0(void)

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


// ==== FUN_004ee320 @ 0x004ee320 ====

float10 FUN_004ee320(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  float fVar5;
  
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  iVar2 = **(int **)(iVar2 + 0x50);
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar4 = (int *)(**(code **)(iVar2 + 0x14))(uVar3);
  iVar2 = (**(code **)(*piVar4 + 8))();
  fVar5 = (float)*(byte *)(iVar2 + 0xa0);
  cVar1 = FUN_004ee240();
  if (cVar1 == '\0') {
    fVar5 = fVar5 * DAT_0099d0f8;
  }
  return (float10)fVar5;
}


// ==== FUN_004ee390 @ 0x004ee390 ====

bool FUN_004ee390(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 8));
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x38))();
    if (cVar1 != '\0') {
      cVar1 = FUN_004ee2c0();
      return cVar1 != '\x01';
    }
  }
  return false;
}


// ==== FUN_004ee3d0 @ 0x004ee3d0 ====

float10 FUN_004ee3d0(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)FUN_004ee320();
  return fVar1 + (float10)*(float *)(in_ECX + 0xc);
}


// ==== FUN_004ee3e0 @ 0x004ee3e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ee3e0(undefined4 param_1,undefined4 *param_2)

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
  undefined4 uVar13;
  int in_ECX;
  float10 fVar14;
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
  auStack_40[0] = FUN_004edd30(uVar3,uVar2,uVar8);
  iVar9 = FUN_004ee0f0(auStack_40[0]);
  fVar4 = *(float *)(iVar9 + 0x114);
  fVar14 = (float10)(**(code **)(*DAT_00b5ad1c + 0x14))();
  iVar6 = (int)ROUND(fVar14 * (float10)fVar4);
  FUN_004ede40(auStack_38,param_2);
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
  fVar14 = (float10)FUN_0040d5f0(auStack_38);
  fStack_28 = (float)fVar14;
  uStack_c = *(undefined1 *)(in_ECX + 4);
  uStack_b = *(undefined1 *)(in_ECX + 5);
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
  uStack_18 = param_1;
  uStack_9 = *(undefined1 *)(iVar9 + 0x118);
  uStack_8 = *(undefined1 *)(iVar9 + 0x119);
  iVar6 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar6 + 0x74) == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = (int *)(**(code **)(**(int **)(iVar6 + 0x74) + 0x14))();
  }
  iVar6 = (**(code **)(*piVar11 + 8))();
  uStack_7 = *(undefined1 *)(iVar6 + 4);
  uStack_14 = *param_2;
  uStack_10 = param_2[1];
  uStack_6 = (undefined1)auStack_40[0];
  iVar6 = FUN_004ef0e0(auStack_40);
  uStack_5 = *(undefined1 *)(iVar6 + 4);
  fVar14 = (float10)FUN_004ee320();
  fStack_4 = (float)((fVar14 + (float10)*(float *)(in_ECX + 0xc)) * (float10)DAT_009b2dc0);
  cVar5 = FUN_004ee090();
  uStack_18 = param_1;
  if (cVar5 == '\0') {
    uStack_a = 1;
  }
  else {
    uStack_a = 0;
    uVar8 = (**(code **)(*DAT_00b5a980 + 0x20))(0);
    uVar13 = (**(code **)(*DAT_00b5a980 + 8))();
    cVar5 = FUN_00826020(uVar13);
    if (cVar5 == '\0') {
      FUN_004dd240(0x16,0,uVar8,0,0);
      return;
    }
  }
  FUN_00508260(&uStack_24);
  (**(code **)(*DAT_00b5a97c + 0x28))(uStack_48);
  iVar6 = *DAT_00b5a97c;
  uVar8 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar6 + 0x2c))(uVar8);
  return;
}


// ==== FUN_004ee6c0 @ 0x004ee6c0 ====

undefined4 FUN_004ee6c0(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 8));
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x38))();
    if (cVar1 != '\0') {
      cVar1 = FUN_004ee2c0();
      if (cVar1 != '\x01') {
        return 0;
      }
    }
  }
  return 1;
}


// ==== FUN_004ee700 @ 0x004ee700 ====

bool FUN_004ee700(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 8));
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x38))();
    if (cVar1 != '\0') {
      cVar1 = FUN_004ee2c0();
      return cVar1 != '\x01';
    }
  }
  return false;
}


// ==== FUN_004ee740 @ 0x004ee740 ====

void FUN_004ee740(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  float10 fVar8;
  float afStack_68 [2];
  undefined1 auStack_60 [8];
  undefined4 uStack_58;
  undefined4 uStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined1 uStack_3e;
  int iStack_3d;
  undefined1 uStack_39;
  undefined1 auStack_38 [4];
  undefined1 uStack_34;
  uint uStack_28;
  undefined4 uStack_24;
  void *pvStack_20;
  undefined1 auStack_1c [12];
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 *puStack_4;
  
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
  FUN_00797a50(&uStack_4c,0,0x13);
  piVar5 = DAT_00b5a6ac;
  uStack_41 = 6;
  uStack_4c = uVar4;
  uStack_42 = uVar1;
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
  afStack_68[0] = (float)CONCAT31(afStack_68[0]._1_3_,*(undefined1 *)(iVar2 + 0x2a));
  uVar4 = (**(code **)(*piVar5 + 0x20))();
  uVar4 = FUN_004edd30(afStack_68[0],uVar1,uVar4);
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
  uStack_58 = *puVar6;
  uStack_54 = puVar6[1];
  uVar7 = FUN_004ede40(auStack_60,param_2);
  fVar8 = (float10)FUN_0040d5f0(uVar7);
  fStack_50 = (float)fVar8;
  iVar2 = FUN_004ee0f0(uVar4);
  puVar6 = (undefined4 *)FUN_004ef0e0(afStack_68);
  piVar5 = DAT_00b5a6ac;
  uStack_48 = *puVar6;
  uStack_44 = *(undefined2 *)(puVar6 + 1);
  uStack_3e = (undefined1)uVar4;
  if (iVar2 == 0) {
    iStack_3d = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iStack_3d = iStack_3d + 1000;
  }
  else {
    afStack_68[0] = *(float *)(iVar2 + 0x114);
    fVar8 = (float10)(**(code **)(*DAT_00b5ad1c + 0x14))();
    iStack_3d = (**(code **)(*piVar5 + 0x20))();
    afStack_68[0] = (float)(int)ROUND((float)fVar8 * afStack_68[0]);
    iStack_3d = iStack_3d + (int)afStack_68[0];
  }
  pvStack_20 = (void *)0xf;
  uStack_24 = 0;
  uStack_34 = 0;
  FUN_00401740(s__Action_End_Tick__009b2cf0,0x12);
  FUN_00401740(&DAT_009b2cec,2);
  uVar4 = FUN_00404230(auStack_1c);
  (**(code **)(*DAT_00b5a688 + 8))(auStack_38,uVar4);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (0xf < uStack_28) {
    _free((void *)CONCAT13(uStack_39,iStack_3d._1_3_));
    return;
  }
  fVar8 = (float10)FUN_004edf10(param_2);
  if ((float10)DAT_0099cdc8 <= fVar8) {
    uStack_48 = CONCAT22(uStack_48._2_2_,0xffff);
    if ((uint)(int)ROUND((float10)DAT_009b2d78 * fVar8) < 0x10000) {
      uStack_48 = CONCAT22(uStack_48._2_2_,(short)(int)ROUND((float10)DAT_009b2d78 * fVar8));
    }
  }
  else {
    uStack_48 = (uint)uStack_48._2_2_ << 0x10;
  }
  *puStack_4 = uStack_54;
  puStack_4[1] = fStack_50;
  puStack_4[2] = uStack_4c;
  puStack_4[3] = uStack_48;
  *(undefined2 *)(puStack_4 + 4) = uStack_44;
  *(undefined1 *)((int)puStack_4 + 0x12) = uStack_42;
  return;
}


// ==== FUN_004eea40 @ 0x004eea40 ====

undefined4 FUN_004eea40(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  float unaff_ESI;
  float10 fVar3;
  undefined1 local_38 [4];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 local_1c [12];
  undefined4 uStack_10;
  uint uStack_c;
  float fStack_4;
  
  fVar3 = (float10)FUN_004ee320();
  fVar1 = *(float *)(in_ECX + 0xc);
  local_20 = (void *)0xf;
  local_24 = 0;
  local_34 = 0;
  FUN_00401740(s___Target_Distance___009b2d1c,0x14);
  FUN_00401740(s__f____AttakRange______f_009b2d04,0x17);
  uVar2 = FUN_00404230(local_1c);
  (**(code **)(*DAT_00b5a688 + 8))(local_38,uVar2);
  if (0xf < uStack_c) {
    _free(local_20);
    return extraout_EAX;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  local_20 = (void *)((uint)local_20 & 0xffffff00);
  if (0xf < uStack_28) {
    _free((void *)(float)(fVar3 + (float10)fVar1));
    return extraout_EAX_00;
  }
  if (unaff_ESI < fStack_4) {
    return 1;
  }
  return 0;
}


// ==== FUN_004eeb20 @ 0x004eeb20 ====

void FUN_004eeb20(void)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int in_ECX;
  float10 fVar8;
  float10 fVar9;
  undefined4 uStack_88;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  void *apvStack_44 [3];
  undefined1 auStack_38 [8];
  uint uStack_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_88 = *(undefined4 *)(in_ECX + 8);
  piVar3 = (int *)(**(code **)(*DAT_00b5ad5c + 0xc))();
  if (piVar3 == (int *)0x0) {
    return;
  }
  cVar2 = (**(code **)(*piVar3 + 0x34))();
  if ((cVar2 == '\0') || (cVar2 = (**(code **)(*piVar3 + 0x2c))(), cVar2 == '\0')) {
    piVar3 = (int *)(**(code **)(*piVar3 + 4))();
    if (piVar3 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar3 + 0x40))();
      uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,(-(uint)(iVar4 != 8) & 0x27ffc0) + 0x1180069);
      uStack_10 = 0xf;
      uStack_14 = 0;
      uStack_24 = 0;
      FUN_00401660(uVar7,0,0xffffffff);
      piVar3 = DAT_00b5ad0c;
      FUN_00401660(auStack_28,0,0xffffffff);
      (**(code **)(*piVar3 + 0x28))(2);
      if (0xf < uStack_30) {
        _free(apvStack_44[0]);
        return;
      }
    }
    return;
  }
  cVar2 = FUN_004ee2c0();
  if (cVar2 != '\0') {
    return;
  }
  if ((*(char *)(in_ECX + 4) == '\x01') && (cVar2 = FUN_004edc70(), cVar2 == '\0')) {
    return;
  }
  iVar4 = (**(code **)(*DAT_00b5ad88 + 4))();
  if (iVar4 == 2) {
    return;
  }
  (**(code **)(*piVar3 + 0x10))(&uStack_68);
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
  uVar7 = *puVar6;
  uVar1 = puVar6[1];
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x2c))();
  uStack_64 = *puVar6;
  uStack_60 = puVar6[1];
  iVar4 = (**(code **)(*piVar3 + 0x38))();
  if (iVar4 == 0) {
    uStack_50 = FUN_00802534();
    uStack_4e = FUN_00802534();
    uStack_4c = uVar7;
    uStack_48 = uVar1;
    uStack_5c = FUN_00802534();
    uStack_5a = FUN_00802534();
    uStack_58 = uStack_6c;
    uStack_54 = uStack_68;
    cVar2 = (**(code **)(*DAT_00b5a800 + 0xc))(&uStack_50,&uStack_5c,apvStack_44,1);
    if (cVar2 != '\0') {
      uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x280005);
      FUN_00765c50(uVar7);
      iVar4 = *DAT_00b5ad0c;
      FUN_00765c50(auStack_2c);
      (**(code **)(iVar4 + 0x28))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  FUN_004ee740(auStack_38,&uStack_6c);
  cVar2 = FUN_004ee040(auStack_38);
  if (cVar2 == '\0') {
    iVar4 = *DAT_00b5acdc;
    uVar7 = FUN_004e5d50(*(undefined4 *)(in_ECX + 8),*(undefined1 *)(in_ECX + 4),
                         *(undefined1 *)(in_ECX + 5));
    (**(code **)(iVar4 + 8))(uVar7);
    return;
  }
  fVar8 = (float10)FUN_004ee320();
  fVar9 = (float10)FUN_0040d5f0(&uStack_64);
  cVar2 = (**(code **)(*piVar3 + 0xc))(uVar7,uVar1,(float)fVar9,(float)fVar8);
  if (cVar2 == '\0') {
    iVar4 = *DAT_00b5acdc;
    uVar7 = FUN_004e5d50(*(undefined4 *)(in_ECX + 8),*(undefined1 *)(in_ECX + 4),
                         *(undefined1 *)(in_ECX + 5));
    (**(code **)(iVar4 + 8))(uVar7);
    iVar4 = *DAT_00b5acdc;
    uVar7 = FUN_004e5cb0(*(undefined4 *)(in_ECX + 8));
    (**(code **)(iVar4 + 8))(uVar7);
    return;
  }
  iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar3 + 0x24))(&uStack_48);
  FUN_004edfb0(&uStack_4c);
  FUN_004ee180(&uStack_4c);
  FUN_004ee3e0(*(undefined4 *)(in_ECX + 8),&uStack_88);
  iVar4 = *DAT_00b5acdc;
  uVar7 = FUN_004e5d50(*(undefined4 *)(in_ECX + 8),*(undefined1 *)(in_ECX + 4),
                       *(undefined1 *)(in_ECX + 5));
  (**(code **)(iVar4 + 8))(uVar7);
  return;
}


// ==== FUN_004eeeb0 @ 0x004eeeb0 ====

bool FUN_004eeeb0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 uStack_1c;
  
  uStack_1c = *(undefined4 *)(in_ECX + 8);
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x38))();
    if (cVar1 != '\0') {
      cVar1 = FUN_004ee2c0();
      if (cVar1 != '\x01') {
        piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 8));
        uVar3 = (**(code **)(*piVar2 + 0x28))();
        FUN_004ee740(&uStack_1c,uVar3);
        iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
        if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
        }
        cVar1 = (**(code **)(*piVar2 + 0x20))(&uStack_1c);
        return cVar1 != '\0';
      }
    }
  }
  return false;
}


// ==== FUN_004eef40 @ 0x004eef40 ====

undefined4 FUN_004eef40(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x13);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 6;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_004eef70 @ 0x004eef70 ====

void FUN_004eef70(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x50d0000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x30;
  FUN_004244d0();
  return;
}


// ==== FUN_004eefa0 @ 0x004eefa0 ====

uint FUN_004eefa0(float param_1)

{
  uint in_EAX;
  uint uVar1;
  
  if (param_1 < 0.0) {
    return in_EAX & 0xffff0000;
  }
  uVar1 = (uint)ROUND(param_1 * DAT_009b2d78);
  if (0xffff < uVar1) {
    uVar1 = CONCAT22((short)(uVar1 >> 0x10),0xffff);
  }
  return uVar1;
}


// ==== FUN_004eeff0 @ 0x004eeff0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004eeff0(float param_1)

{
  if ((DAT_00b5ad68 & 1) == 0) {
    DAT_00b5ad68 = DAT_00b5ad68 | 1;
    _DAT_00b5ad64 = DAT_009b0eb8;
  }
  if ((DAT_00b5ad68 & 2) == 0) {
    DAT_00b5ad68 = DAT_00b5ad68 | 2;
    DAT_00b5ad60 = DAT_009b2d7c;
  }
  param_1 = param_1 - (float)(int)(param_1 / DAT_00b5ad60) * DAT_00b5ad60;
  if (0.0 <= param_1) {
    return (float10)param_1;
  }
  return (float10)DAT_00b5ad60 + (float10)param_1;
}


// ==== FUN_004ef070 @ 0x004ef070 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_004ef070(float param_1)

{
  undefined2 in_FPUControlWord;
  undefined1 local_4;
  
  if ((DAT_00b5ad74 & 1) == 0) {
    DAT_00b5ad74 = DAT_00b5ad74 | 1;
    _DAT_00b5ad70 = DAT_009b0eb8;
  }
  if ((DAT_00b5ad74 & 2) == 0) {
    DAT_00b5ad74 = DAT_00b5ad74 | 2;
    _DAT_00b5ad6c = DAT_009b2d7c;
  }
  local_4 = (undefined1)(int)ROUND((param_1 / _DAT_00b5ad6c) * DAT_009b2d80);
  return CONCAT11((char)((ushort)in_FPUControlWord >> 8),local_4) | 0xc00;
}


// ==== FUN_004ef0e0 @ 0x004ef0e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ef0e0(uint *param_1)

{
  uint uVar1;
  float fVar2;
  undefined1 uVar3;
  float *in_ECX;
  undefined2 in_FPUControlWord;
  float10 fVar4;
  float fVar5;
  undefined4 local_8;
  undefined2 local_4;
  
  if ((DAT_00b5ad80 & 1) == 0) {
    DAT_00b5ad80 = DAT_00b5ad80 | 1;
    _DAT_00b5ad7c = DAT_009b0eb8;
  }
  if ((DAT_00b5ad80 & 2) == 0) {
    DAT_00b5ad80 = DAT_00b5ad80 | 2;
    _DAT_00b5ad78 = DAT_009b2d7c;
  }
  fVar5 = *in_ECX;
  if (0.0 <= fVar5) {
    local_8 = 0xffff;
    fVar2 = fVar5 * DAT_009b2d78;
    fVar5 = (float)CONCAT22((short)((uint)fVar5 >> 0x10),in_FPUControlWord);
    if ((uint)(int)ROUND(fVar2) < 0x10000) {
      local_8 = (int)ROUND(fVar2) & 0xffff;
    }
  }
  else {
    local_8 = 0;
  }
  if (0.0 <= in_ECX[1]) {
    local_8 = CONCAT22(0xffff,(undefined2)local_8);
    fVar5 = (float)CONCAT22((short)((uint)fVar5 >> 0x10),in_FPUControlWord);
    uVar1 = (uint)ROUND(in_ECX[1] * DAT_009b2d78);
    if (uVar1 < 0x10000) {
      local_8 = CONCAT22((short)uVar1,(undefined2)local_8);
    }
  }
  fVar4 = (float10)FUN_004eeff0(in_ECX[2],fVar5);
  uVar3 = FUN_004ef070((float)fVar4);
  local_4 = CONCAT11(local_4._1_1_,uVar3);
  *param_1 = local_8;
  *(undefined2 *)(param_1 + 1) = local_4;
  return;
}


// ==== FUN_004ef200 @ 0x004ef200 ====

undefined4 FUN_004ef200(void)

{
  return 0x50070002;
}


// ==== FUN_004ef210 @ 0x004ef210 ====

void FUN_004ef210(undefined4 param_1)

{
  FUN_004d8570(param_1);
  return;
}


// ==== FUN_004ef240 @ 0x004ef240 ====

undefined1 FUN_004ef240(void)

{
  return 1;
}


// ==== FUN_004ef250 @ 0x004ef250 ====

void FUN_004ef250(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2dc8;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_004ef2c0 @ 0x004ef2c0 ====

void FUN_004ef2c0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 10) {
      (**(code **)(*DAT_00b5a78c + 0x2c))(*(undefined4 *)(in_ECX + 4));
    }
  }
  return;
}


// ==== FUN_004ef300 @ 0x004ef300 ====

void FUN_004ef300(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 9) {
      cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
      (**(code **)(*DAT_00b5a78c + 0x18))(cVar1 != '\x01',*(undefined4 *)(in_ECX + 4));
    }
  }
  return;
}


// ==== FUN_004ef350 @ 0x004ef350 ====

void FUN_004ef350(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 0xe) {
      (**(code **)(*DAT_00b5a9e4 + 0x30))(*(undefined4 *)(in_ECX + 4));
      (**(code **)(*DAT_00b5a9e4 + 0x24))(10,(uint)DAT_00b5a9e4 & 0xff000000);
    }
  }
  return;
}


// ==== FUN_004ef3b0 @ 0x004ef3b0 ====

undefined4 FUN_004ef3b0(void)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (((iVar2 != 9) && (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 != 10)) &&
       (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 != 0xe)) {
      return 0;
    }
    piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
    pfVar3 = (float *)(**(code **)(*piVar1 + 0x28))();
    piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    pfVar4 = (float *)(**(code **)(*piVar1 + 0x28))();
    if (SQRT((pfVar4[1] - pfVar3[1]) * (pfVar4[1] - pfVar3[1]) +
             (*pfVar4 - *pfVar3) * (*pfVar4 - *pfVar3)) <= DAT_0099d0f8) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_004ef490 @ 0x004ef490 ====

void FUN_004ef490(void)

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


// ==== FUN_004ef5c0 @ 0x004ef5c0 ====

void FUN_004ef5c0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar2 == (int *)0x0) {
LAB_004ef5fd:
    iVar3 = *DAT_00b5acdc;
    uVar4 = FUN_004e5e10();
    (**(code **)(iVar3 + 8))(uVar4);
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  if (iVar3 != 9) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 != 10) {
      iVar3 = (**(code **)(*piVar2 + 0xc))();
      if (iVar3 != 0xe) goto LAB_004ef5fd;
    }
  }
  cVar1 = FUN_004ef3b0();
  if (cVar1 == '\0') {
    iVar3 = *DAT_00b5acdc;
    uVar4 = FUN_004e5d80(*(undefined4 *)(in_ECX + 4));
    (**(code **)(iVar3 + 8))(uVar4);
    iVar3 = *DAT_00b5acdc;
    uVar4 = FUN_004e5cb0(*(undefined4 *)(in_ECX + 4));
    (**(code **)(iVar3 + 8))(uVar4);
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  if (iVar3 == 10) {
    FUN_004ef2c0();
    FUN_004ef490();
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  if (iVar3 == 9) {
    FUN_004ef300();
    FUN_004ef490();
    return;
  }
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  if (iVar3 == 0xe) {
    FUN_004ef350();
  }
  FUN_004ef490();
  return;
}


// ==== FUN_004ef6c0 @ 0x004ef6c0 ====

void FUN_004ef6c0(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0xc);
  *(undefined1 *)((int)param_1 + 0xb) = 1;
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return;
}


// ==== FUN_004ef700 @ 0x004ef700 ====

undefined1 FUN_004ef700(void)

{
  return 1;
}


// ==== FUN_004ef710 @ 0x004ef710 ====

undefined1 FUN_004ef710(void)

{
  return 1;
}


// ==== FUN_004ef720 @ 0x004ef720 ====

void FUN_004ef720(undefined4 *param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2df0;
  in_ECX[1] = *param_1;
  in_ECX[2] = param_1[1];
  *(undefined1 *)(in_ECX + 3) = param_2;
  *(undefined1 *)((int)in_ECX + 0xd) = param_3;
  return;
}


// ==== FUN_004ef840 @ 0x004ef840 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ef840(undefined4 *param_1,float *param_2)

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
  if (_DAT_009b2de8 <
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


// ==== FUN_004ef910 @ 0x004ef910 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ef910(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  float afStack_40 [2];
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  char cStack_8;
  float fStack_4;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
  uStack_28 = *puVar2;
  uStack_24 = puVar2[1];
  puVar2 = (undefined4 *)FUN_004ef840(afStack_40,in_ECX + 4);
  uStack_20 = *puVar2;
  uStack_1c = puVar2[1];
  uStack_18 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x74) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar3 + 0x74) + 0x14))();
  }
  iVar3 = (**(code **)(*piVar1 + 8))();
  uStack_14 = *(undefined1 *)(iVar3 + 4);
  puVar2 = (undefined4 *)FUN_004ef840(afStack_40,in_ECX + 4);
  uStack_10 = *puVar2;
  uStack_c = puVar2[1];
  cStack_8 = (**(code **)(*DAT_00b5ad54 + 0x68))();
  if (cStack_8 == '\0') {
    fVar4 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
  }
  else {
    fVar4 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
  }
  afStack_40[0] = (float)fVar4;
  fStack_4 = afStack_40[0];
  FUN_00507870(&uStack_28,auStack_38);
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    (**(code **)(_DAT_00000000 + 0x20))(auStack_38);
    return;
  }
  piVar1 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  (**(code **)(*piVar1 + 0x20))(auStack_38);
  return;
}


// ==== FUN_004efa30 @ 0x004efa30 ====

void FUN_004efa30(undefined4 *param_1)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 in_ECX;
  undefined4 unaff_EBX;
  float10 fVar11;
  float10 fVar12;
  undefined4 uStack_50;
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  float fStack_4;
  
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  cVar3 = (**(code **)(*DAT_00b5ad54 + 0x68))();
  if (cVar3 == '\0') {
    fVar11 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
  }
  else {
    fVar11 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
  uStack_28 = *puVar6;
  uStack_24 = puVar6[1];
  puVar6 = (undefined4 *)FUN_004ef840(auStack_40,param_1);
  uStack_20 = *puVar6;
  uStack_1c = puVar6[1];
  uStack_18 = uVar4;
  iVar7 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar7 + 0x74) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(iVar7 + 0x74) + 0x14))();
  }
  iVar7 = (**(code **)(*piVar5 + 8))();
  uStack_14 = *(undefined1 *)(iVar7 + 4);
  puVar6 = (undefined4 *)FUN_004ef840(auStack_40,param_1);
  uStack_10 = *puVar6;
  uStack_c = puVar6[1];
  uStack_8 = (**(code **)(*DAT_00b5ad54 + 0x68))();
  cVar3 = (**(code **)(*DAT_00b5ad54 + 0x68))();
  if (cVar3 == '\0') {
    fVar12 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
  }
  else {
    fVar12 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
  }
  fStack_4 = (float)fVar12;
  FUN_00507870(&uStack_28,auStack_38);
  iVar7 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar7 + 0x4c) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(iVar7 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar5 + 0x24))(auStack_38);
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar6 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar8 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar8 = (int *)(**(code **)(*piVar8 + 0x14))();
  iVar7 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar7 + 0x74) == (int *)0x0) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)(**(code **)(**(int **)(iVar7 + 0x74) + 0x14))();
  }
  iVar7 = (**(code **)(*piVar9 + 8))();
  bVar1 = *(byte *)(iVar7 + 4);
  uVar2 = *(undefined1 *)((int)(float)fVar11 + 0xd);
  puVar10 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
  uVar4 = (**(code **)(*piVar8 + 8))();
  puVar6[1] = uVar4;
  *puVar6 = &PTR_FUN_009b2c28;
  puVar6[2] = *puVar10;
  puVar6[3] = puVar10[1];
  puVar6[4] = *param_1;
  puVar6[5] = param_1[1];
  puVar6[7] = (uint)bVar1;
  puVar6[6] = uStack_50;
  puVar6[8] = in_ECX;
  *(char *)(puVar6 + 9) = (char)((uint)unaff_EBX >> 0x18);
  *(undefined1 *)((int)puVar6 + 0x25) = uVar2;
  FUN_00797a20(puVar6);
  return;
}


// ==== FUN_004efc60 @ 0x004efc60 ====

void FUN_004efc60(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  
  cVar2 = FUN_004ef910();
  if (cVar2 != '\0') {
    FUN_004efa30(in_ECX + 4);
    return;
  }
  if (*(char *)(in_ECX + 0xc) != '\0') {
    iVar1 = *DAT_00b5acdc;
    uVar3 = FUN_004e5da0(in_ECX + 4,*(char *)(in_ECX + 0xc),0);
    (**(code **)(iVar1 + 8))(uVar3);
  }
  return;
}


// ==== FUN_004efcc0 @ 0x004efcc0 ====

undefined1 FUN_004efcc0(void)

{
  return 1;
}


// ==== FUN_004efcd0 @ 0x004efcd0 ====

undefined1 FUN_004efcd0(void)

{
  return 1;
}


// ==== FUN_004efce0 @ 0x004efce0 ====

void FUN_004efce0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2e10;
  in_ECX[1] = *param_1;
  in_ECX[2] = param_1[1];
  return;
}


// ==== FUN_004efd60 @ 0x004efd60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_004efd60(void)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 auStack_10 [2];
  undefined1 uStack_6;
  undefined1 uStack_5;
  
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
  FUN_00797a50(auStack_10,0,0x10);
  uStack_5 = 2;
  auStack_10[0] = uVar5;
  uStack_6 = uVar1;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    cVar2 = (**(code **)(_DAT_00000000 + 0x20))(auStack_10);
    return cVar2 != '\0';
  }
  piVar6 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  cVar2 = (**(code **)(*piVar6 + 0x20))(auStack_10);
  return cVar2 != '\0';
}


// ==== FUN_004efe00 @ 0x004efe00 ====

void FUN_004efe00(undefined4 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  float10 fVar6;
  undefined1 auStack_38 [2];
  undefined1 auStack_36 [14];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  float fStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar3 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x28))();
  uStack_28 = *puVar4;
  uStack_24 = puVar4[1];
  uStack_1c = param_1[1];
  uStack_20 = *param_1;
  uStack_18 = uVar2;
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar5 + 0x74) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar5 + 0x74) + 0x14))();
  }
  iVar5 = (**(code **)(*piVar3 + 8))();
  uStack_14 = *(undefined1 *)(iVar5 + 4);
  uStack_10 = *param_1;
  uStack_c = param_1[1];
  uStack_8 = (**(code **)(*DAT_00b5ad54 + 0x68))();
  cVar1 = (**(code **)(*DAT_00b5ad54 + 0x68))();
  if (cVar1 == '\0') {
    fVar6 = (float10)(**(code **)(*DAT_00b5ad1c + 0xc))();
  }
  else {
    fVar6 = (float10)(**(code **)(*DAT_00b5ad1c + 0x10))();
  }
  fStack_4 = (float)fVar6;
  FUN_00507870(&uStack_28,auStack_38);
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar3 + 0x24))(auStack_38);
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = &PTR_FUN_009b2d88;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  uVar2 = (**(code **)(*piVar3 + 8))();
  puVar4[1] = uVar2;
  FUN_00403e60(puVar4 + 2,auStack_38 + -4,0x19);
  FUN_00797a20(puVar4);
  return;
}


// ==== FUN_004eff50 @ 0x004eff50 ====

void FUN_004eff50(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  
  cVar2 = FUN_004efd60();
  if (cVar2 == '\0') {
    iVar1 = *DAT_00b5acdc;
    uVar3 = FUN_004e5dd0(in_ECX + 4);
    (**(code **)(iVar1 + 8))(uVar3);
    return;
  }
  FUN_004efe00(in_ECX + 4);
  return;
}


// ==== FUN_004eff90 @ 0x004eff90 ====

undefined4 FUN_004eff90(undefined4 *param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_00797a50(param_1,0,0x10);
  *param_1 = param_2;
  *(undefined1 *)((int)param_1 + 0xb) = 2;
  *(undefined1 *)((int)param_1 + 10) = param_3;
  return 1;
}


// ==== FUN_004effd0 @ 0x004effd0 ====

undefined1 FUN_004effd0(void)

{
  return 1;
}


// ==== FUN_004effe0 @ 0x004effe0 ====

undefined1 FUN_004effe0(void)

{
  return 1;
}


// ==== FUN_004efff0 @ 0x004efff0 ====

void FUN_004efff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b2e30;
  return;
}


