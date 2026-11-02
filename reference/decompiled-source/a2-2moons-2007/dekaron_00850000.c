// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x850000-0x85ffff

// ==== FUN_00850020 @ 0x00850020 ====

undefined4 FUN_00850020(uint param_1,int param_2)

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


// ==== FUN_008500b0 @ 0x008500b0 ====

void FUN_008500b0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined1 *)(in_ECX + 2) = *(undefined1 *)(param_1 + 2);
  *(undefined1 *)((int)in_ECX + 9) = *(undefined1 *)((int)param_1 + 9);
  *(undefined1 *)((int)in_ECX + 10) = *(undefined1 *)((int)param_1 + 10);
  *(undefined1 *)((int)in_ECX + 0xb) = *(undefined1 *)((int)param_1 + 0xb);
  *(undefined1 *)(in_ECX + 3) = *(undefined1 *)(param_1 + 3);
  FUN_00430ad0(param_1 + 4);
  FUN_00430ad0(param_1 + 8);
  FUN_0084fea0(param_1 + 0xc);
  in_ECX[0x10] = param_1[0x10];
  in_ECX[0x11] = param_1[0x11];
  in_ECX[0x12] = param_1[0x12];
  in_ECX[0x13] = param_1[0x13];
  in_ECX[0x14] = param_1[0x14];
  in_ECX[0x15] = param_1[0x15];
  return;
}


// ==== FUN_00850140 @ 0x00850140 ====

void FUN_00850140(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 6) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 6))) {
    FUN_0084f970(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0084f7e0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x40;
  return;
}


// ==== FUN_008501b0 @ 0x008501b0 ====

void * FUN_008501b0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x2c) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x2c) = *(int *)((int)param_2 + 0x2c) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1814);
  *(int *)(in_ECX + 0x180c) = *(int *)(in_ECX + 0x180c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x30);
    *(undefined4 *)((int)pvVar2 + 0x28) = *(undefined4 *)(in_ECX + 0x1810);
    *(void **)(in_ECX + 0x1810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1814) = *(undefined4 *)((int)pvVar2 + 0x24);
  }
  *(int *)((int)pvVar2 + 0x2c) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x24) = 0;
  FUN_00413110(0);
  *(undefined4 *)((int)pvVar2 + 0x20) = 1;
  return pvVar2;
}


// ==== FUN_00850280 @ 0x00850280 ====

void * FUN_00850280(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x2c) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x2c) = *(int *)((int)param_2 + 0x2c) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1814);
  *(int *)(in_ECX + 0x180c) = *(int *)(in_ECX + 0x180c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x30);
    *(undefined4 *)((int)pvVar2 + 0x28) = *(undefined4 *)(in_ECX + 0x1810);
    *(void **)(in_ECX + 0x1810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1814) = *(undefined4 *)((int)pvVar2 + 0x24);
  }
  *(int *)((int)pvVar2 + 0x2c) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x24) = 0;
  FUN_00850340(0);
  return pvVar2;
}


// ==== FUN_00850340 @ 0x00850340 ====

undefined4 FUN_00850340(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_1 < 0x38e38e4) {
    pvVar1 = operator_new(param_1 * 0x48);
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x48 + (int)pvVar1);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    return 1;
  }
  FUN_0085b3b0();
  return 1;
}


// ==== FUN_008503a0 @ 0x008503a0 ====

int FUN_008503a0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x44) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x44) = *(int *)(param_2 + 0x44) + param_1;
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
  iVar3 = FUN_00850460();
  return iVar3;
}


// ==== FUN_00850460 @ 0x00850460 ====

void FUN_00850460(void)

{
  int in_ECX;
  
  FUN_00413070(0);
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  return;
}


// ==== FUN_00850490 @ 0x00850490 ====

void FUN_00850490(byte param_1)

{
  void *in_ECX;
  
  FUN_0084e2a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008504b0 @ 0x008504b0 ====

int FUN_008504b0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x78) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x78) = *(int *)(param_2 + 0x78) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x3e14);
  *(int *)(in_ECX + 0x3e0c) = *(int *)(in_ECX + 0x3e0c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x7c);
    *(undefined4 *)((int)pvVar2 + 0x74) = *(undefined4 *)(in_ECX + 0x3e10);
    *(void **)(in_ECX + 0x3e10) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x3e14) = *(undefined4 *)((int)pvVar2 + 0x70);
  }
  *(undefined4 *)((int)pvVar2 + 0x70) = 0;
  *(int *)((int)pvVar2 + 0x78) = param_1;
  iVar3 = FUN_00850570();
  return iVar3;
}


// ==== FUN_00850570 @ 0x00850570 ====

void FUN_00850570(void)

{
  int in_ECX;
  
  FUN_00850600(0);
  FUN_008505a0(0);
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  return;
}


// ==== FUN_008505a0 @ 0x008505a0 ====

undefined4 FUN_008505a0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_1 < 0x2108422) {
    pvVar1 = operator_new(param_1 * 0x7c);
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x7c + (int)pvVar1);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    return 1;
  }
  FUN_0085b3b0();
  return 1;
}


// ==== FUN_00850600 @ 0x00850600 ====

undefined4 FUN_00850600(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_1 < 0x5d1745e) {
    pvVar1 = operator_new(param_1 * 0x2c);
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x2c + (int)pvVar1);
    *(void **)(in_ECX + 4) = pvVar1;
    *(void **)(in_ECX + 8) = pvVar1;
    return 1;
  }
  FUN_0085b3b0();
  return 1;
}


// ==== FUN_00850660 @ 0x00850660 ====

undefined4 FUN_00850660(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x78) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x78);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x78);
    }
    FUN_008506f0(0);
    *(undefined4 *)(param_2 + 0x70) = *(undefined4 *)(in_ECX + 0x3e14);
    *(int *)(in_ECX + 0x3e0c) = *(int *)(in_ECX + 0x3e0c) + -1;
    *(int *)(in_ECX + 0x3e14) = param_2;
  }
  return 0;
}


// ==== FUN_008506f0 @ 0x008506f0 ====

void FUN_008506f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00412dc0();
  FUN_00412dc0();
  FUN_00850730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00850730 @ 0x00850730 ====

void FUN_00850730(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00850780 @ 0x00850780 ====

int FUN_00850780(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x68) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x68) = *(int *)(param_2 + 0x68) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x6c14);
  *(int *)(in_ECX + 0x6c0c) = *(int *)(in_ECX + 0x6c0c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x6c);
    *(undefined4 *)((int)pvVar2 + 100) = *(undefined4 *)(in_ECX + 0x6c10);
    *(void **)(in_ECX + 0x6c10) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x6c14) = *(undefined4 *)((int)pvVar2 + 0x60);
  }
  *(undefined4 *)((int)pvVar2 + 0x60) = 0;
  *(int *)((int)pvVar2 + 0x68) = param_1;
  iVar3 = FUN_005d5090();
  return iVar3;
}


// ==== FUN_00850840 @ 0x00850840 ====

undefined4 FUN_00850840(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x68) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__00a11c08,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x68);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x68);
    }
    FUN_00412dc0();
    FUN_005d4fc0();
    *(undefined4 *)(param_2 + 0x60) = *(undefined4 *)(in_ECX + 0x6c14);
    *(int *)(in_ECX + 0x6c0c) = *(int *)(in_ECX + 0x6c0c) + -1;
    *(int *)(in_ECX + 0x6c14) = param_2;
  }
  return 0;
}


// ==== FUN_008508d0 @ 0x008508d0 ====

void FUN_008508d0(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  pvVar1 = operator_new(0x2c);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00880c60();
  }
  *in_ECX = piVar2;
  (**(code **)(*piVar2 + 4))();
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00880b70();
  }
  in_ECX[1] = uVar3;
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    return;
  }
  uVar3 = FUN_00880a40();
  in_ECX[2] = uVar3;
  return;
}


// ==== FUN_00850950 @ 0x00850950 ====

undefined4 FUN_00850950(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00850960 @ 0x00850960 ====

undefined4 FUN_00850960(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00850970 @ 0x00850970 ====

void FUN_00850970(void)

{
  int *piVar1;
  void *_Memory;
  int *in_ECX;
  
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
  }
  *in_ECX = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  piVar1 = *(int **)in_ECX[4];
  if (piVar1 == (int *)in_ECX[4]) {
    _Memory = *(void **)(in_ECX[4] + 4);
    if (*(char *)((int)_Memory + 0x19) == '\0') {
      FUN_00850b10(*(undefined4 *)((int)_Memory + 8));
      _free(_Memory);
      return;
    }
    *(int *)(in_ECX[4] + 4) = in_ECX[4];
    in_ECX[5] = 0;
    *(int *)in_ECX[4] = in_ECX[4];
    *(int *)(in_ECX[4] + 8) = in_ECX[4];
    return;
  }
  piVar1 = (int *)piVar1[5];
  if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*piVar1)(1);
  }
  if ((void *)piVar1[2] == (void *)0x0) {
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    _free(piVar1);
    return;
  }
  _free((void *)piVar1[2]);
  return;
}


// ==== FUN_00850a80 @ 0x00850a80 ====

void FUN_00850a80(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00850970();
  FUN_00850ea0(local_4,**(undefined4 **)(in_ECX + 0x10),*(undefined4 **)(in_ECX + 0x10));
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_00850ac0 @ 0x00850ac0 ====

void FUN_00850ac0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  iVar1 = FUN_00850b50();
  in_ECX[4] = iVar1;
  *(undefined1 *)(iVar1 + 0x19) = 1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  in_ECX[5] = 0;
  return;
}


// ==== FUN_00850b10 @ 0x00850b10 ====

void FUN_00850b10(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_00850b10(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00850b50 @ 0x00850b50 ====

void FUN_00850b50(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a130;
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


// ==== Catch@00850bda @ 0x00850bda ====

void Catch_00850bda(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00850bf0 @ 0x00850bf0 ====

/* WARNING: Removing unreachable block (ram,0x00850d0c) */
/* WARNING: Removing unreachable block (ram,0x00850d1c) */
/* WARNING: Removing unreachable block (ram,0x00850d25) */
/* WARNING: Removing unreachable block (ram,0x00850d28) */
/* WARNING: Removing unreachable block (ram,0x00850d18) */
/* WARNING: Removing unreachable block (ram,0x00850d36) */
/* WARNING: Removing unreachable block (ram,0x00850d43) */
/* WARNING: Removing unreachable block (ram,0x00850d4e) */
/* WARNING: Removing unreachable block (ram,0x00850d4a) */
/* WARNING: Removing unreachable block (ram,0x00850d3e) */
/* WARNING: Removing unreachable block (ram,0x00850d51) */

void FUN_00850bf0(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x19) != '\0') {
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
  FUN_00832d10();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x19) == '\0') {
    if (*(char *)(param_2[2] + 0x19) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x19) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x19) == '\0') {
      piVar3 = (int *)FUN_00894550(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x19) == '\0') {
      uVar4 = FUN_00832cf0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[6] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[6] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[6] == '\0') {
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(piVar3 + 6) = 0;
            FUN_0058b7a0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(*piVar5 + 0x18) == '\x01') && (*(char *)(piVar5[2] + 0x18) == '\x01'))
            goto LAB_00850e20;
            if (*(char *)(piVar5[2] + 0x18) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x18) = 1;
              *(undefined1 *)(piVar5 + 6) = 0;
              FUN_004b8340(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 6) = (char)piVar3[6];
            *(undefined1 *)(piVar3 + 6) = 1;
            *(undefined1 *)(piVar5[2] + 0x18) = 1;
            FUN_0058b7a0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[6] == '\0') {
            *(undefined1 *)(piVar5 + 6) = 1;
            *(undefined1 *)(piVar3 + 6) = 0;
            FUN_004b8340(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x19) == '\0') {
            if ((*(char *)(piVar5[2] + 0x18) != '\x01') || (*(char *)(*piVar5 + 0x18) != '\x01')) {
              if (*(char *)(*piVar5 + 0x18) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x18) = 1;
                *(undefined1 *)(piVar5 + 6) = 0;
                FUN_0058b7a0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 6) = (char)piVar3[6];
              *(undefined1 *)(piVar3 + 6) = 1;
              *(undefined1 *)(*piVar5 + 0x18) = 1;
              FUN_004b8340(piVar3);
              break;
            }
LAB_00850e20:
            *(undefined1 *)(piVar5 + 6) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 6) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_00850ea0 @ 0x00850ea0 ====

void FUN_00850ea0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00850b10(piVar6[1]);
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


// ==== FUN_00850f60 @ 0x00850f60 ====

void FUN_00850f60(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a140;
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


// ==== Catch@00850fea @ 0x00850fea ====

void Catch_00850fea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00851000 @ 0x00851000 ====

void FUN_00851000(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(in_ECX + 8);
  for (piVar2 = *(int **)(in_ECX + 4); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      FUN_008810c0();
    }
  }
  return;
}


// ==== FUN_00851030 @ 0x00851030 ====

void FUN_00851030(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(in_ECX + 8);
  for (piVar2 = *(int **)(in_ECX + 4); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if (*piVar2 != 0) {
      FUN_008810e0();
    }
  }
  return;
}


// ==== FUN_00851060 @ 0x00851060 ====

void FUN_00851060(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x14);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (puVar3[10] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(puVar3[10]);
    }
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_008510d0 @ 0x008510d0 ====

void FUN_008510d0(undefined4 param_1,char param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_diffuseTexture_00a11f94,0xe);
  FUN_008812b0(0x18,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_shadowTexture_00a11fa4,0xd);
  FUN_008812b0(0x19,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_coverTexture_00a11fb4,0xc);
  FUN_008812b0(0x1a,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_specularTexture_00a11fc4,0xf);
  FUN_008812b0(0x1b,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_envTexture_00a11fd4,10);
  FUN_008812b0(0x1c,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_bumpTexture_00a11fe0,0xb);
  FUN_008812b0(0x1d,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_modelViewProj_00a11fec,0xd);
  FUN_008812b0(0,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_matShadowVPTex_00a11ffc,0xe);
  FUN_008812b0(1,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_matCoverVPTex_00a1200c,0xd);
  FUN_008812b0(2,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_modelView_00a1201c,9);
  FUN_008812b0(3,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_fShininess_00a12028,0xc);
  FUN_008812b0(5,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3ambient_00a12038,0xb);
  FUN_008812b0(4,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3EyePos_00a12044,10);
  FUN_008812b0(6,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3LightDirection_00a12050,0x12);
  FUN_008812b0(7,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3ColorWithIntensity_00a12064,0x16);
  FUN_008812b0(8,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3ShadePos_00a1207c,0xc);
  FUN_008812b0(9,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_fShadeDistance_00a1208c,0x10);
  FUN_008812b0(10,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_fScale_00a120a0,8);
  FUN_008812b0(0x13,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_boneMatrix_00a120ac,0xc);
  FUN_008812b0(0xb,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_f4GlobalColor_00a120bc,0xd);
  FUN_008812b0(0xc,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_f4SpecularColor_00a120cc,0xf);
  FUN_008812b0(0xd,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f2UV_00a120dc,6);
  FUN_008812b0(0xe,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_fNoFog_00a120e4,8);
  FUN_008812b0(0xf,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f2FogValue_00a120f0,0xc);
  FUN_008812b0(0x10,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3FogCenterPos_00a12100,0x10);
  FUN_008812b0(0x11,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_bcovermap_00a12114,0xb);
  FUN_008812b0(0x14,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if (param_2 != '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_matLightVProj_00a12120,0xd);
    FUN_008812b0(0x15,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_g_fShadowColor_00a12130,0xe);
    FUN_008812b0(0x16,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_g_fShadowBias_00a12140,0xd);
    FUN_008812b0(0x17,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  return;
}


// ==== FUN_008517e0 @ 0x008517e0 ====

void FUN_008517e0(undefined4 param_1,char param_2)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_diffuseTexture_00a12150,0xe);
  FUN_008812b0(0x54,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_shadowTexture_00a12160,0xd);
  FUN_008812b0(0x55,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_coverTexture_00a12170,0xc);
  FUN_008812b0(0x56,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_matViewProj_00a12180,0xb);
  FUN_008812b0(0x3e,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_matShadowVPTex_00a1218c,0xe);
  FUN_008812b0(0x40,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_matCoverVPTex_00a1219c,0xd);
  FUN_008812b0(0x41,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_uvConst_00a121ac,7);
  FUN_008812b0(0x42,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_ambient_00a121b4,9);
  FUN_008812b0(0x43,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3ShadePos_00a121c0,0xc);
  FUN_008812b0(0x46,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_fShadeDistance_00a121d0,0x10);
  FUN_008812b0(0x47,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3LightDirection_00a121e4,0x12);
  FUN_008812b0(0x44,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3ColorWithIntensity_00a121f8,0x16);
  FUN_008812b0(0x45,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_bcovermap_00a12210,0xb);
  FUN_008812b0(0x52,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f2FogValue_00a1221c,0xc);
  FUN_008812b0(0x48,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3FogCenterPos_00a1222c,0x10);
  FUN_008812b0(0x49,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ColorIntensityPointLight_00a12240,0x18);
  FUN_008812b0(0x4a,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_PositionPointLight_00a1225c,0x12);
  FUN_008812b0(0x4b,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_IofDsqr_00a12270,7);
  FUN_008812b0(0x4c,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&DAT_00a12278,4);
  FUN_008812b0(0x4d,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_color_00a12280,7);
  FUN_008812b0(0x4e,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if (param_2 != '\0') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_g_fShininess_00a12288,0xc);
    FUN_008812b0(0x4f,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_g_f3EyePos_00a12298,10);
    FUN_008812b0(0x50,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_bumpTexture_00a122a4,0xb);
    FUN_008812b0(0x57,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_matLightVProj_00a122b0,0xd);
    FUN_008812b0(0x3f,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_g_fShadowColor_00a122c0,0xe);
    FUN_008812b0(0x51,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_g_fShadowBias_00a122d0,0xd);
    FUN_008812b0(0x53,local_1c);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
  }
  return;
}


// ==== FUN_00851e40 @ 0x00851e40 ====

void FUN_00851e40(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_boneMatrix_00a122e0,0xc);
  FUN_008812b0(0x5a,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_colorkeyTexture_00a122f0,0xf);
  FUN_008812b0(0x5b,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_m4ModelVProj_00a12300,0xe);
  FUN_008812b0(0x58,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_fShadowColor_00a12310,0xe);
  FUN_008812b0(0x59,local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00851f60 @ 0x00851f60 ====

void FUN_00851f60(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_diffuseTexture_00a12320,0xe);
  FUN_008812b0(0x65,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_matViewProj_00a12330,0xb);
  FUN_008812b0(100,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_modelViewProj_00a1233c,0xd);
  FUN_008812b0(0x66,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_f4GlobalColor_00a1234c,0xd);
  FUN_008812b0(0x67,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f2FogValue_00a1235c,0xc);
  FUN_008812b0(0x68,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3FogCenterPos_00a1236c,0x10);
  FUN_008812b0(0x69,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&PTR_LAB_00a12380,3);
  FUN_008812b0(0x6a,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3LightDirection_00a12384,0x12);
  FUN_008812b0(0x6b,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3ColorWithIntensity_00a12398,0x16);
  FUN_008812b0(0x6c,local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_008521b0 @ 0x008521b0 ====

void FUN_008521b0(void)

{
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_modelViewProj_00a123b0,0xd);
  FUN_008812b0(0x6d,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_fShininess_00a123c0,0xc);
  FUN_008812b0(0x6e,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3EyePos_00a123d0,10);
  FUN_008812b0(0x6f,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_f4GlobalColor_00a123dc,0xd);
  FUN_008812b0(0x70,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(&PTR_LAB_00a123ec,3);
  FUN_008812b0(0x71,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3LightDirection_00a123f0,0x12);
  FUN_008812b0(0x72,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3ColorWithIntensity_00a12404,0x16);
  FUN_008812b0(0x73,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_diffuseTex1_00a1241c,0xb);
  FUN_008812b0(0x74,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_diffuseTex2_00a12428,0xb);
  FUN_008812b0(0x75,local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00852400 @ 0x00852400 ====

void FUN_00852400(void)

{
  int iVar1;
  void *_Memory;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  
  uVar3 = 0;
  do {
    iVar1 = *(int *)(in_ECX + 4);
    if ((iVar1 == 0) || (uVar2 = *(int *)(in_ECX + 8) - iVar1 >> 2, uVar2 <= uVar3)) {
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(undefined4 *)(in_ECX + 4) = 0;
        *(undefined4 *)(in_ECX + 8) = 0;
        *(undefined4 *)(in_ECX + 0xc) = 0;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    if (uVar3 != 0) {
      if (uVar2 <= uVar3) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      _Memory = *(void **)(iVar1 + uVar3 * 4);
      FUN_00881100();
      if (_Memory != (void *)0x0) {
        FUN_00881130();
        _free(_Memory);
        return;
      }
    }
    uVar3 = uVar3 + 1;
  } while( true );
}


// ==== FUN_008524b0 @ 0x008524b0 ====

void FUN_008524b0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008510d0(*(undefined4 *)(iVar1 + 4),0);
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 3)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008510d0(*(undefined4 *)(iVar1 + 8),0);
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008510d0(*(undefined4 *)(iVar1 + 0xc),1);
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x12)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008510d0(*(undefined4 *)(iVar1 + 0x44),0);
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x13)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008510d0(*(undefined4 *)(iVar1 + 0x48),0);
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 5)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00851e40(*(undefined4 *)(iVar1 + 0x10));
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x14)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00851e40(*(undefined4 *)(iVar1 + 0x4c));
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0xc)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008521b0(*(undefined4 *)(iVar1 + 0x2c));
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x15)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008521b0(*(undefined4 *)(iVar1 + 0x50));
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0xd)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00851f60(*(undefined4 *)(iVar1 + 0x30));
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x16)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00851f60(*(undefined4 *)(iVar1 + 0x54));
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 6)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008517e0(*(undefined4 *)(iVar1 + 0x14),1);
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 7)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008517e0(*(undefined4 *)(iVar1 + 0x18),1);
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x17)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_008517e0(*(undefined4 *)(iVar1 + 0x58),0);
  if ((*(int *)(in_ECX + 4) == 0) || ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 8))
  {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_matProj_00a12434,7);
  FUN_008812b0(0x1e,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_baseColor_00a1243c,9);
  FUN_008812b0(0x1f,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_diffuseTex_00a12448,10);
  FUN_008812b0(0x20,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f2FogValue_00a12454,0xc);
  FUN_008812b0(0x21,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3FogCenterPos_00a12464,0x10);
  FUN_008812b0(0x22,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if ((*(int *)(in_ECX + 4) == 0) || ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 9))
  {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_reflectVPTex_00a12478,0xe);
  FUN_008812b0(0x24,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_refractVPTex_00a12488,0xe);
  FUN_008812b0(0x25,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_matProj_00a12498,9);
  FUN_008812b0(0x23,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_waterColor_00a124a4,0xc);
  FUN_008812b0(0x26,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3EyePos_00a124b4,10);
  FUN_008812b0(0x27,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3DirLight_00a124c0,0xc);
  FUN_008812b0(0x28,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3LightDirection_00a124d0,0x12);
  FUN_008812b0(0x29,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f2UV_00a124e4,6);
  FUN_008812b0(0x2a,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f2UV2_00a124ec,7);
  FUN_008812b0(0x2b,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3AmbientLight_00a124f4,0x10);
  FUN_008812b0(0x2c,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f2FogValue_00a12508,0xc);
  FUN_008812b0(0x2d,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_f3FogCenterPos_00a12518,0x10);
  FUN_008812b0(0x2e,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_attenuation_00a1252c,0xd);
  FUN_008812b0(0x2f,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_wave1_fST_00a1253c,0xb);
  FUN_008812b0(0x30,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_wave1_fA_00a12548,10);
  FUN_008812b0(0x31,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_wave1_fLover2PI_00a12554,0x11);
  FUN_008812b0(0x32,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_wave1_f2Direction_00a12568,0x13);
  FUN_008812b0(0x33,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_wave2_fST_00a1257c,0xb);
  FUN_008812b0(0x34,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_g_wave2_fA_00a12588,10);
  FUN_008812b0(0x35,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_wave2_fLover2PI_00a12594);
  FUN_008812b0(0x36,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_wave2_f2Direction_00a125a8);
  FUN_008812b0(0x37,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_diffuseTexture_00a125bc);
  FUN_008812b0(0x38,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_disortTexture_00a125cc);
  FUN_008812b0(0x3a,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_bumpTexture_00a125dc);
  FUN_008812b0(0x39,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_reflectTexture_00a125e8);
  FUN_008812b0(0x3c,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_refractTexture_00a125f8);
  FUN_008812b0(0x3b,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_envmapTexture_00a12608);
  FUN_008812b0(0x3d,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if ((*(int *)(in_ECX + 4) == 0) || ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 10)
     ) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00401830(s_diffuseTexture_00a12618);
  FUN_008812b0(0x5d,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_matViewProj_00a12628);
  FUN_008812b0(0x5c,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_f2FogValue_00a12634);
  FUN_008812b0(0x5e,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_f3FogCenterPos_00a12644);
  FUN_008812b0(0x5f,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if ((*(int *)(in_ECX + 4) == 0) ||
     ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 0xb)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00401830(s_matViewProj_00a12658);
  FUN_008812b0(0x60,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_globalColor_00a12664);
  FUN_008812b0(0x61,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_diffuseTexture1_00a12670);
  FUN_008812b0(0x62,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_diffuseTexture2_00a12680);
  FUN_008812b0(99,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if ((*(int *)(in_ECX + 4) == 0) ||
     ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 0xe)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00401830(s_matViewProj_00a12690);
  FUN_008812b0(0x76,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_baseColor_00a1269c);
  FUN_008812b0(0x77,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if ((*(int *)(in_ECX + 4) == 0) ||
     ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 0xf)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00401830(s_g_fPowValue_00a126a8);
  FUN_008812b0(0x78,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_fWidth_00a126b4);
  FUN_008812b0(0x79,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_fHeight_00a126c0);
  FUN_008812b0(0x7a,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_fWeightValue_00a126cc);
  FUN_008812b0(0x7b,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_OrgTex_00a126dc);
  FUN_008812b0(0x7c,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_PowTex_00a126e4);
  FUN_008812b0(0x7d,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_BlurTex_00a126ec);
  FUN_008812b0(0x7e,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_AddTex_00a126f4);
  FUN_008812b0(0x7f,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if ((*(int *)(in_ECX + 4) == 0) ||
     ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 0x10)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00401830(s_g_fPowValue_00a126fc);
  FUN_008812b0(0x80,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_fWidth_00a12708);
  FUN_008812b0(0x81,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_fHeight_00a12714);
  FUN_008812b0(0x82,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_g_fWeightValue_00a12720);
  FUN_008812b0(0x83,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_OrgTex_00a12730);
  FUN_008812b0(0x84,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if ((*(int *)(in_ECX + 4) == 0) ||
     ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 0x11)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  FUN_00401830(s_screenTex0_00a12738);
  FUN_008812b0(0x85,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_screenTex1_00a12744);
  FUN_008812b0(0x86,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_screenTex2_00a12750);
  FUN_008812b0(0x87,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_screenTex3_00a1275c);
  FUN_008812b0(0x88,local_1c);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401830(s_consts_00a12768);
  FUN_008812b0(0x8c,local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_008534b0 @ 0x008534b0 ====

undefined4 FUN_008534b0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 *puVar5;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined4 local_4;
  
  uVar2 = param_1;
  iVar1 = *(int *)(in_ECX + 0x14);
  piVar3 = (int *)FUN_0069a470(&param_1,param_1);
  if (*piVar3 != iVar1) {
    puVar5 = (undefined4 *)FUN_00855200(uVar2);
    return *puVar5;
  }
  uVar4 = FUN_008548d0();
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(uVar2,0,0xffffffff);
  local_4 = uVar4;
  FUN_00854e50(local_28,local_20);
  if (local_8 < 0x10) {
    return uVar4;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_00853550 @ 0x00853550 ====

void FUN_00853550(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined2 *puVar5;
  undefined1 local_bc [4];
  void *local_b8;
  undefined4 local_a8;
  uint local_a4;
  undefined2 local_a0;
  undefined2 local_9e;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined1 local_9a;
  undefined1 local_99;
  undefined2 local_98;
  undefined2 local_96;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92;
  undefined1 local_91;
  undefined2 local_90;
  undefined2 local_8e;
  undefined1 local_8c;
  undefined1 local_8b;
  undefined1 local_8a;
  undefined1 local_89;
  undefined2 local_88;
  undefined2 local_86;
  undefined1 local_84;
  undefined1 local_83;
  undefined1 local_82;
  undefined1 local_81;
  undefined2 local_80;
  undefined2 local_7e;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  undefined1 local_79;
  undefined2 local_78;
  undefined2 local_76;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined2 local_70;
  undefined2 local_6e;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined1 local_6a;
  undefined1 local_69;
  undefined2 local_68;
  undefined2 local_66;
  undefined1 local_64;
  undefined1 local_63;
  undefined1 local_62;
  undefined1 local_61;
  undefined2 local_60;
  undefined2 local_5e;
  undefined1 local_5c;
  undefined1 local_5b;
  undefined1 local_5a;
  undefined1 local_59;
  undefined2 local_58;
  undefined2 local_56;
  undefined1 local_54;
  undefined1 local_53;
  undefined1 local_52;
  undefined1 local_51;
  undefined2 local_50;
  undefined2 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined2 local_48;
  undefined2 local_46;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined2 local_38;
  undefined2 local_36;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined2 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  uVar2 = FUN_0049b670();
  local_88 = 0;
  local_86 = 0;
  local_84 = 2;
  local_83 = 0;
  local_82 = 0;
  local_81 = 0;
  local_80 = 0;
  local_7e = 0xc;
  local_7c = 1;
  local_7b = 0;
  local_7a = 5;
  local_79 = 0;
  local_78 = 0;
  local_76 = 0x14;
  local_74 = 4;
  local_73 = 0;
  local_72 = 10;
  local_71 = 0;
  local_70 = 0xff;
  local_6e = 0;
  local_6c = 0x11;
  local_6b = 0;
  local_6a = 0;
  local_69 = 0;
  uVar3 = FUN_00854850();
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  FUN_00401740(s_Billboard_fx_00a11e30,0xc);
  puVar5 = &local_88;
  uVar4 = FUN_008534b0(local_bc);
  FUN_008811a0(uVar2,uVar4,puVar5);
  if (0xf < local_a4) {
    _free(local_b8);
    return;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x1c) = uVar3;
  local_48 = 0;
  local_46 = 0;
  local_44 = 3;
  local_43 = 0;
  local_42 = 0;
  local_41 = 0;
  local_40 = 0;
  local_3e = 0x10;
  local_3c = 2;
  local_3b = 0;
  local_3a = 3;
  local_39 = 0;
  local_38 = 0;
  local_36 = 0x1c;
  local_34 = 1;
  local_33 = 0;
  local_32 = 5;
  local_31 = 0;
  local_30 = 0xff;
  local_2e = 0;
  local_2c = 0x11;
  local_2b = 0;
  local_2a = 0;
  local_29 = 0;
  uVar3 = FUN_00854850();
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  FUN_00401740(s_Water_fx_00a11e40,8);
  puVar5 = &local_48;
  uVar4 = FUN_008534b0(local_bc);
  FUN_008811a0(uVar2,uVar4,puVar5);
  if (0xf < local_a4) {
    _free(local_b8);
    return;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 9)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x20) = uVar3;
  local_68 = 0;
  local_66 = 0;
  local_64 = 2;
  local_63 = 0;
  local_62 = 0;
  local_61 = 0;
  local_60 = 0;
  local_5e = 0xc;
  local_5c = 3;
  local_5b = 0;
  local_5a = 10;
  local_59 = 0;
  local_58 = 0;
  local_56 = 0x1c;
  local_54 = 1;
  local_53 = 0;
  local_52 = 5;
  local_51 = 0;
  local_50 = 0xff;
  local_4e = 0;
  local_4c = 0x11;
  local_4b = 0;
  local_4a = 0;
  local_49 = 0;
  uVar3 = FUN_00854850();
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  FUN_00401740(s_Trace_fx_00a11e4c,8);
  puVar5 = &local_68;
  uVar4 = FUN_008534b0(local_bc);
  FUN_008811a0(uVar2,uVar4,puVar5);
  if (0xf < local_a4) {
    _free(local_b8);
    return;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 10)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x24) = uVar3;
  local_28 = 0;
  local_26 = 0;
  local_24 = 2;
  local_23 = 0;
  local_22 = 0;
  local_21 = 0;
  local_20 = 0;
  local_1e = 0xc;
  local_1c = 1;
  local_1b = 0;
  local_1a = 5;
  local_19 = 0;
  local_18 = 0;
  local_16 = 0x14;
  local_14 = 1;
  local_13 = 0;
  local_12 = 5;
  local_11 = 1;
  local_10 = 0;
  local_e = 0x1c;
  local_c = 4;
  local_b = 0;
  local_a = 10;
  local_9 = 0;
  local_8 = 0xff;
  local_6 = 0;
  local_4 = 0x11;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  uVar3 = FUN_00854850();
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  FUN_00401740(s_Skybox_fx_00a11e58,9);
  puVar5 = &local_28;
  uVar4 = FUN_008534b0(local_bc);
  FUN_008811a0(uVar2,uVar4,puVar5);
  if (0xf < local_a4) {
    _free(local_b8);
    return;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0xb)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x28) = uVar3;
  local_a0 = 0;
  local_9e = 0;
  local_9c = 2;
  local_9b = 0;
  local_9a = 0;
  local_99 = 0;
  local_98 = 0;
  local_96 = 0xc;
  local_94 = 2;
  local_93 = 0;
  local_92 = 3;
  local_91 = 0;
  local_90 = 0xff;
  local_8e = 0;
  local_8c = 0x11;
  local_8b = 0;
  local_8a = 0;
  local_89 = 0;
  uVar3 = FUN_00854850();
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  FUN_00401740(s_Obb_fx_00a11e64,6);
  puVar5 = &local_a0;
  uVar4 = FUN_008534b0(local_bc);
  FUN_008811a0(uVar2,uVar4,puVar5);
  if (0xf < local_a4) {
    _free(local_b8);
    return;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0xe)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x34) = uVar3;
  return;
}


// ==== FUN_00853ab0 @ 0x00853ab0 ====

undefined4 FUN_00853ab0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar5;
  int in_ECX;
  undefined2 *puVar6;
  undefined1 local_4c [4];
  void *local_48;
  undefined4 local_38;
  uint local_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined2 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  uVar2 = FUN_0049b670();
  local_30 = 0;
  local_2e = 0;
  local_2c = 2;
  local_2b = 0;
  local_2a = 0;
  local_29 = 0;
  local_28 = 0;
  local_26 = 0xc;
  local_24 = 2;
  local_23 = 0;
  local_22 = 3;
  local_21 = 0;
  local_20 = 0;
  local_1e = 0x18;
  local_1c = 2;
  local_1b = 0;
  local_1a = 5;
  local_19 = 0;
  local_18 = 0;
  local_16 = 0x24;
  local_14 = 1;
  local_13 = 0;
  local_12 = 5;
  local_11 = 1;
  local_10 = 0;
  local_e = 0x2c;
  local_c = 4;
  local_b = 0;
  local_a = 10;
  local_9 = 0;
  local_8 = 0xff;
  local_6 = 0;
  local_4 = 0x11;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  uVar3 = FUN_00854850();
  local_34 = 0xf;
  local_38 = 0;
  local_48 = (void *)((uint)local_48 & 0xffffff00);
  FUN_00401740(s_Geometry_fx_00a11e6c,0xb);
  puVar6 = &local_30;
  uVar4 = FUN_008534b0(local_4c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_34) {
    _free(local_48);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 6)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x14) = uVar3;
  uVar3 = FUN_00854850();
  local_34 = 0xf;
  local_38 = 0;
  local_48 = (void *)((uint)local_48 & 0xffffff00);
  FUN_00401740(s_GeometryShadow_fx_00a11e78,0x11);
  puVar6 = &local_30;
  uVar4 = FUN_008534b0(local_4c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_34) {
    _free(local_48);
    return extraout_EAX_00;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (iVar5 = *(int *)(in_ECX + 8) - iVar1, (uint)(iVar5 >> 2) < 7)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x18) = uVar3;
  return CONCAT31((int3)(iVar5 >> 10),1);
}


// ==== FUN_00853c70 @ 0x00853c70 ====

undefined4 FUN_00853c70(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int iVar5;
  int in_ECX;
  undefined2 *puVar6;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined2 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  uVar2 = FUN_0049b670();
  local_28 = 0;
  local_26 = 0;
  local_24 = 2;
  local_23 = 0;
  local_22 = 0;
  local_21 = 0;
  local_20 = 0;
  local_1e = 0xc;
  local_1c = 2;
  local_1b = 0;
  local_1a = 3;
  local_19 = 0;
  local_18 = 0;
  local_16 = 0x18;
  local_14 = 1;
  local_13 = 0;
  local_12 = 5;
  local_11 = 0;
  local_10 = 0;
  local_e = 0x20;
  local_c = 4;
  local_b = 0;
  local_a = 10;
  local_9 = 0;
  local_8 = 0xff;
  local_6 = 0;
  local_4 = 0x11;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  uVar3 = FUN_00854850();
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740(s_LowGeometry_fx_00a11e8c,0xe);
  puVar6 = &local_28;
  uVar4 = FUN_008534b0(local_44);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (iVar5 = *(int *)(in_ECX + 8) - iVar1, (uint)(iVar5 >> 2) < 0x17)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x58) = uVar3;
  return CONCAT31((int3)(iVar5 >> 10),1);
}


// ==== FUN_00853da0 @ 0x00853da0 ====

undefined4 FUN_00853da0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  int iVar5;
  int in_ECX;
  undefined2 *puVar6;
  undefined1 local_5c [4];
  void *local_58;
  undefined4 local_48;
  uint local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined2 local_38;
  undefined2 local_36;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined2 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  uVar2 = FUN_0049b670();
  local_40 = 0;
  local_3e = 0;
  local_3c = 2;
  local_3b = 0;
  local_3a = 0;
  local_39 = 0;
  local_38 = 0;
  local_36 = 0xc;
  local_34 = 2;
  local_33 = 0;
  local_32 = 3;
  local_31 = 0;
  local_30 = 0;
  local_2e = 0x18;
  local_2c = 3;
  local_2b = 0;
  local_2a = 5;
  local_29 = 0;
  local_28 = 0;
  local_26 = 0x28;
  local_24 = 1;
  local_23 = 0;
  local_22 = 5;
  local_21 = 1;
  local_20 = 0;
  local_1e = 0x30;
  local_1c = 1;
  local_1b = 0;
  local_1a = 5;
  local_19 = 2;
  local_18 = 0;
  local_16 = 0x38;
  local_14 = 1;
  local_13 = 0;
  local_12 = 2;
  local_11 = 0;
  local_10 = 0;
  local_e = 0x40;
  local_c = 1;
  local_b = 0;
  local_a = 1;
  local_9 = 0;
  local_8 = 0xff;
  local_6 = 0;
  local_4 = 0x11;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  uVar3 = FUN_00854850();
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401740(s_BoneAnimation_fx_00a11e9c,0x10);
  puVar6 = &local_40;
  uVar4 = FUN_008534b0(local_5c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_44) {
    _free(local_58);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 4) = uVar3;
  uVar3 = FUN_00854850();
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401740(s_BoneCoverAnimation_fx_00a11eb0,0x15);
  puVar6 = &local_40;
  uVar4 = FUN_008534b0(local_5c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_44) {
    _free(local_58);
    return extraout_EAX_00;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 3)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 8) = uVar3;
  uVar3 = FUN_00854850();
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401740(s_BoneShadowAnimation_fx_00a11ec8,0x16);
  puVar6 = &local_40;
  uVar4 = FUN_008534b0(local_5c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_44) {
    _free(local_58);
    return extraout_EAX_01;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 4)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0xc) = uVar3;
  uVar3 = FUN_00854850();
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401740(s_ShadowObject_fx_00a11ee0,0xf);
  puVar6 = &local_40;
  uVar4 = FUN_008534b0(local_5c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_44) {
    _free(local_58);
    return extraout_EAX_02;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 5)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x10) = uVar3;
  uVar3 = FUN_00854850();
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401740(s_traceMesh_fx_00a11ef0,0xc);
  puVar6 = &local_40;
  uVar4 = FUN_008534b0(local_5c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_44) {
    _free(local_58);
    return extraout_EAX_03;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0xd)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x30) = uVar3;
  uVar3 = FUN_00854850();
  local_44 = 0xf;
  local_48 = 0;
  local_58 = (void *)((uint)local_58 & 0xffffff00);
  FUN_00401740(s_ItemMesh_fx_00a11f00,0xb);
  puVar6 = &local_40;
  uVar4 = FUN_008534b0(local_5c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_44) {
    _free(local_58);
    return extraout_EAX_04;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (iVar5 = *(int *)(in_ECX + 8) - iVar1, (uint)(iVar5 >> 2) < 0xc)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x2c) = uVar3;
  return CONCAT31((int3)(iVar5 >> 10),1);
}


// ==== FUN_00854170 @ 0x00854170 ====

undefined4 FUN_00854170(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  int iVar5;
  int in_ECX;
  undefined2 *puVar6;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined2 local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined2 local_20;
  undefined2 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined2 local_18;
  undefined2 local_16;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined2 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined2 local_8;
  undefined2 local_6;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  undefined1 local_1;
  
  uVar2 = FUN_0049b670();
  local_38 = 0;
  local_36 = 0;
  local_34 = 2;
  local_33 = 0;
  local_32 = 0;
  local_31 = 0;
  local_30 = 0;
  local_2e = 0xc;
  local_2c = 2;
  local_2b = 0;
  local_2a = 3;
  local_29 = 0;
  local_28 = 0;
  local_26 = 0x18;
  local_24 = 1;
  local_23 = 0;
  local_22 = 5;
  local_21 = 0;
  local_20 = 0;
  local_1e = 0x20;
  local_1c = 1;
  local_1b = 0;
  local_1a = 5;
  local_19 = 1;
  local_18 = 0;
  local_16 = 0x28;
  local_14 = 1;
  local_13 = 0;
  local_12 = 2;
  local_11 = 0;
  local_10 = 0;
  local_e = 0x30;
  local_c = 1;
  local_b = 0;
  local_a = 1;
  local_9 = 0;
  local_8 = 0xff;
  local_6 = 0;
  local_4 = 0x11;
  local_3 = 0;
  local_2 = 0;
  local_1 = 0;
  uVar3 = FUN_00854850();
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_LowBoneAnimation_fx_00a11f0c,0x13);
  puVar6 = &local_38;
  uVar4 = FUN_008534b0(local_54);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_3c) {
    _free(local_50);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x12)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x44) = uVar3;
  uVar3 = FUN_00854850();
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_LowBoneCoverAnimation_fx_00a11f20,0x18);
  puVar6 = &local_38;
  uVar4 = FUN_008534b0(local_54);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_3c) {
    _free(local_50);
    return extraout_EAX_00;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x13)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x48) = uVar3;
  uVar3 = FUN_00854850();
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_LowShadowObject_fx_00a11f3c,0x12);
  puVar6 = &local_38;
  uVar4 = FUN_008534b0(local_54);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_3c) {
    _free(local_50);
    return extraout_EAX_01;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x14)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x4c) = uVar3;
  uVar3 = FUN_00854850();
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_LowTraceMesh_fx_00a11f50,0xf);
  puVar6 = &local_38;
  uVar4 = FUN_008534b0(local_54);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_3c) {
    _free(local_50);
    return extraout_EAX_02;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0x16)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x54) = uVar3;
  uVar3 = FUN_00854850();
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  FUN_00401740(s_LowItemMesh_fx_00a11f60,0xe);
  puVar6 = &local_38;
  uVar4 = FUN_008534b0(local_54);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_3c) {
    _free(local_50);
    return extraout_EAX_03;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (iVar5 = *(int *)(in_ECX + 8) - iVar1, (uint)(iVar5 >> 2) < 0x15)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x50) = uVar3;
  return CONCAT31((int3)(iVar5 >> 10),1);
}


// ==== FUN_008544b0 @ 0x008544b0 ====

undefined4 FUN_008544b0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar5;
  int in_ECX;
  undefined2 *puVar6;
  undefined2 local_4c;
  undefined2 local_4a;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined2 local_44;
  undefined2 local_42;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined2 local_34;
  undefined2 local_32;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined2 local_24;
  undefined2 local_22;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  uVar2 = FUN_0049b670();
  local_4c = 0;
  local_4a = 0;
  local_48 = 3;
  local_47 = 0;
  local_46 = 9;
  local_45 = 0;
  local_44 = 0;
  local_42 = 0x10;
  local_40 = 1;
  local_3f = 0;
  local_3e = 5;
  local_3d = 0;
  local_3c = 0xff;
  local_3a = 0;
  local_38 = 0x11;
  local_37 = 0;
  local_36 = 0;
  local_35 = 0;
  uVar3 = FUN_00854850();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_BloomEffect_fx_00a11f70,0xe);
  puVar6 = &local_4c;
  uVar4 = FUN_008534b0(local_1c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar1 >> 2) < 0xf)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x38) = uVar3;
  local_34 = 0;
  local_32 = 0;
  local_30 = 2;
  local_2f = 0;
  local_2e = 0;
  local_2d = 0;
  local_2c = 0;
  local_2a = 0xc;
  local_28 = 1;
  local_27 = 0;
  local_26 = 5;
  local_25 = 0;
  local_24 = 0xff;
  local_22 = 0;
  local_20 = 0x11;
  local_1f = 0;
  local_1e = 0;
  local_1d = 0;
  uVar3 = FUN_00854850();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_BloomLow_fx_00a11f80,0xb);
  puVar6 = &local_34;
  uVar4 = FUN_008534b0(local_1c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX_00;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (iVar5 = *(int *)(in_ECX + 8) - iVar1, (uint)(iVar5 >> 2) < 0x10)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x3c) = uVar3;
  return CONCAT31((int3)(iVar5 >> 10),1);
}


// ==== FUN_00854670 @ 0x00854670 ====

undefined4 FUN_00854670(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int iVar5;
  int in_ECX;
  undefined2 *puVar6;
  undefined2 local_34;
  undefined2 local_32;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined2 local_24;
  undefined2 local_22;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  uVar2 = FUN_0049b670();
  local_34 = 0;
  local_32 = 0;
  local_30 = 3;
  local_2f = 0;
  local_2e = 9;
  local_2d = 0;
  local_2c = 0;
  local_2a = 0x10;
  local_28 = 1;
  local_27 = 0;
  local_26 = 5;
  local_25 = 0;
  local_24 = 0xff;
  local_22 = 0;
  local_20 = 0x11;
  local_1f = 0;
  local_1e = 0;
  local_1d = 0;
  uVar3 = FUN_00854850();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_bink_fx_00a11f8c,7);
  puVar6 = &local_34;
  uVar4 = FUN_008534b0(local_1c);
  FUN_008811a0(uVar2,uVar4,puVar6);
  if (0xf < local_4) {
    _free(local_18);
    return extraout_EAX;
  }
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (iVar5 = *(int *)(in_ECX + 8) - iVar1, (uint)(iVar5 >> 2) < 0x11)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  *(undefined4 *)(iVar1 + 0x40) = uVar3;
  return CONCAT31((int3)(iVar5 >> 10),1);
}


// ==== FUN_00854760 @ 0x00854760 ====

void FUN_00854760(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00852400();
  FUN_00851060();
  FUN_008552a0(local_4,**(undefined4 **)(in_ECX + 0x14),*(undefined4 **)(in_ECX + 0x14));
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_008547c0 @ 0x008547c0 ====

undefined1 FUN_008547c0(void)

{
  FUN_00853ab0();
  FUN_00853c70();
  FUN_00853da0();
  FUN_00854170();
  FUN_008544b0();
  FUN_00854670();
  FUN_00853550();
  FUN_008524b0();
  return 1;
}


// ==== FUN_00854800 @ 0x00854800 ====

void FUN_00854800(void)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  iVar1 = FUN_00850f60();
  *(int *)(in_ECX + 0x14) = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 0x14) + 4) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x14);
  *(int *)(*(int *)(in_ECX + 0x14) + 8) = *(int *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  FUN_00854fc0(0x17,0);
  return;
}


// ==== FUN_00854850 @ 0x00854850 ====

int FUN_00854850(void)

{
  code *pcVar1;
  void *pvVar2;
  int iVar3;
  int extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(0x34);
  if ((pvVar2 != (void *)0x0) && (iVar3 = FUN_00881350(), iVar3 != 0)) {
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


// ==== FUN_008548d0 @ 0x008548d0 ====

undefined4 FUN_008548d0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *local_20;
  undefined1 local_1c;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = DAT_00b5a7cc;
  local_c = 0;
  local_1c = 0;
  local_8 = 0xf;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 10;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_00854930 @ 0x00854930 ====

void * FUN_00854930(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a150;
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


// ==== Catch@008549a5 @ 0x008549a5 ====

void Catch_008549a5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_008549c0 @ 0x008549c0 ====

void FUN_008549c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00854930(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00854ac5:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_00854ac5;
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


// ==== FUN_00854ba0 @ 0x00854ba0 ====

void FUN_00854ba0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a160;
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


// ==== Catch@00854d01 @ 0x00854d01 ====

void Catch_00854d01(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00854df0 @ 0x00854df0 ====

void FUN_00854df0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_00854df0(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_00854e50 @ 0x00854e50 ====

/* WARNING: Removing unreachable block (ram,0x00854eaf) */

void FUN_00854e50(undefined4 *param_1,undefined4 *param_2)

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
LAB_00854ee0:
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
        if (uVar5 == 0) goto LAB_00854ee0;
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
      puVar6 = (undefined4 *)FUN_008549c0(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_008549c0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00854fc0 @ 0x00854fc0 ====

void FUN_00854fc0(uint param_1,undefined1 param_2)

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
    FUN_00854ba0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if (((iVar2 != 0) && (pvVar3 = *(void **)(in_ECX + 8), param_1 < (uint)((int)pvVar3 - iVar2 >> 2))
      ) && (_Dst = (void *)(iVar2 + param_1 * 4), _Dst != pvVar3)) {
    pvVar3 = _memmove(_Dst,pvVar3,0);
    *(void **)(in_ECX + 8) = pvVar3;
  }
  return;
}


// ==== FUN_00855050 @ 0x00855050 ====

undefined4 * FUN_00855050(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_008549c0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
    if (cVar2 != '\0') {
      FUN_008549c0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    cVar2 = FUN_0040a6d0(piVar1[2] + 0xc,param_3);
    if (cVar2 != '\0') {
      FUN_008549c0(param_1,0,*(undefined4 *)(*(int *)(in_ECX + 4) + 8),param_3);
      return param_1;
    }
  }
  else {
    cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
    if (cVar2 != '\0') {
      FUN_0079c420();
      cVar2 = FUN_0040a6d0(param_2 + 3,param_3);
      if (cVar2 != '\0') {
        if (*(char *)(param_2[2] + 0x2d) == '\0') {
          FUN_008549c0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_008549c0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
    cVar2 = FUN_0040a6d0(param_2 + 3,param_3);
    if (cVar2 != '\0') {
      FUN_00699bf0();
      if (param_2 != *(int **)(in_ECX + 4)) {
        cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
        if (cVar2 == '\0') goto LAB_008551d3;
      }
      if (*(char *)(param_2[2] + 0x2d) == '\0') {
        FUN_008549c0(param_1,1,param_2,param_3);
        return param_1;
      }
      FUN_008549c0(param_1,0,param_2,param_3);
      return param_1;
    }
  }
LAB_008551d3:
  puVar3 = (undefined4 *)FUN_00854e50(local_8,param_3);
  *param_1 = *puVar3;
  return param_1;
}


// ==== FUN_00855200 @ 0x00855200 ====

int FUN_00855200(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  iVar2 = FUN_004bb4d0(param_1);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar2 + 0x24) < 0x10) {
      iVar3 = iVar2 + 0x10;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x10);
    }
    iVar3 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),iVar3,*(undefined4 *)(iVar2 + 0x20));
    if (-1 < iVar3) goto LAB_00855290;
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = 0;
  piVar4 = (int *)FUN_00855050(&param_1,iVar2,local_20);
  iVar2 = *piVar4;
  if (0xf < local_8) {
    _free(local_1c);
    return extraout_EAX;
  }
LAB_00855290:
  return iVar2 + 0x28;
}


// ==== FUN_008552a0 @ 0x008552a0 ====

void FUN_008552a0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00854df0(piVar6[1]);
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


// ==== FUN_00855360 @ 0x00855360 ====

void FUN_00855360(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),param_1,1,param_2);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),param_1,2,param_2);
  return;
}


// ==== FUN_008553a0 @ 0x008553a0 ====

void FUN_008553a0(void)

{
  int in_ECX;
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  
  (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x89,0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))
            (*(int **)(in_ECX + 0x90),0,8,*(undefined4 *)(in_ECX + 0x68));
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),0,9,0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,9,0);
  uVar2 = 2;
  if (2 < *(uint *)(in_ECX + 0xdc)) {
    uVar2 = 3;
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),3,1,3);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),3,2,3);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),3,3,3);
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    puVar1 = (undefined4 *)(in_ECX + 0x120);
    do {
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),uVar3,6,2);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),uVar3,5,2);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),uVar3,7,1);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x10c))(*(int **)(in_ECX + 0x90),uVar3,1,*puVar1);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x10c))(*(int **)(in_ECX + 0x90),uVar3,2,2);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x10c))(*(int **)(in_ECX + 0x90),uVar3,4,1);
      uVar3 = uVar3 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar3 < uVar2);
  }
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x10c))(*(int **)(in_ECX + 0x90),0,4,4);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x10c))(*(int **)(in_ECX + 0x90),0,5,2);
  if ((*(char *)(in_ECX + 0xa9) != '\0') && (*(char *)(in_ECX + 0xeb) != '\0')) {
    uVar2 = 4;
    if (*(uint *)(in_ECX + 0xf4) < 4) {
      uVar2 = *(uint *)(in_ECX + 0xf4);
    }
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),0,6,3);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),0,10,uVar2);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,6,3);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,10,uVar2);
  }
  return;
}


// ==== FUN_00855590 @ 0x00855590 ====

void FUN_00855590(char param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x111) != param_1) {
    piVar2 = *(int **)(in_ECX + 0x90);
    if (param_1 == '\0') {
      (**(code **)(*piVar2 + 0x114))(piVar2,0,8,0);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,8,0);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),2,8,0);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),3,8,0);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),0,7,0);
    }
    else {
      uVar1 = *(undefined4 *)(in_ECX + 0x68);
      (**(code **)(*piVar2 + 0x114))(piVar2,0,8,uVar1);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,8,uVar1);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),2,8,uVar1);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),3,8,uVar1);
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),0,7,1);
    }
    (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,7,param_1 != '\0');
    *(char *)(in_ECX + 0x111) = param_1;
  }
  return;
}


// ==== FUN_008556b0 @ 0x008556b0 ====

uint FUN_008556b0(void)

{
  int in_ECX;
  undefined1 local_130 [12];
  uint uStack_124;
  uint uStack_7c;
  
  (**(code **)(**(int **)(in_ECX + 0x8c) + 0x38))
            (*(int **)(in_ECX + 0x8c),*(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0x10c)
             ,local_130);
  if (uStack_7c < 0xfffe0101) {
    return 0x20;
  }
  return (uStack_124 & 0x100000 | 0x400000) >> 0x10;
}


// ==== FUN_00855710 @ 0x00855710 ====

undefined4 FUN_00855710(int param_1,int *param_2)

{
  uint uVar1;
  int in_ECX;
  int unaff_EBX;
  int unaff_EBP;
  uint uVar2;
  int unaff_EDI;
  int unaff_retaddr;
  undefined4 uStack_10;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x18))(*(int **)(in_ECX + 0x8c),param_1,param_2);
  if (uVar1 == 0) {
    return 0;
  }
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      (**(code **)(**(int **)(in_ECX + 0x8c) + 0x1c))
                (*(int **)(in_ECX + 0x8c),param_1,param_2,uVar2,(int)register0x00000010 + -0x1c);
      if ((unaff_EDI == unaff_retaddr) && (unaff_EBP == param_1)) {
        *param_2 = unaff_EDI;
        param_2[1] = unaff_EBP;
        param_2[2] = unaff_EBX;
        param_2[3] = uStack_10;
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return 0;
}


// ==== FUN_008557e0 @ 0x008557e0 ====

int FUN_008557e0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  puVar2 = (undefined4 *)(in_ECX + 0x168);
  do {
    iVar1 = (**(code **)(*(int *)*puVar2 + 0x44))((int *)*puVar2);
    if (iVar1 < 0) {
      return iVar1;
    }
    uVar3 = uVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar3 < 0xe);
  return 0;
}


// ==== FUN_00855810 @ 0x00855810 ====

undefined4 FUN_00855810(int param_1)

{
  int in_ECX;
  
  if (param_1 == 3) {
    GetWindowRect(*(HWND *)(in_ECX + 0xb4),(LPRECT)(in_ECX + 4));
    GetClientRect(*(HWND *)(in_ECX + 0xb4),(LPRECT)(in_ECX + 0x14));
    return 1;
  }
  return 0;
}


// ==== FUN_00855850 @ 0x00855850 ====

void FUN_00855850(int param_1)

{
  int in_ECX;
  
  if (param_1 == 0) {
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),8,3);
    *(undefined4 *)(in_ECX + 100) = 0;
    return;
  }
  if ((((*(int *)(in_ECX + 0x114) != 0) || (*(int *)(in_ECX + 0x118) != 5)) ||
      (*(int *)(in_ECX + 0x11c) != 6)) && (*(int *)(in_ECX + 100) == 0)) {
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x1b,0);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0xf,0);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x13,5);
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),0x14,6);
    *(undefined4 *)(in_ECX + 0x114) = 0;
    *(undefined4 *)(in_ECX + 0x118) = 5;
    *(undefined4 *)(in_ECX + 0x11c) = 6;
  }
  (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90),8,2);
  *(int *)(in_ECX + 100) = param_1;
  return;
}


// ==== FUN_00855980 @ 0x00855980 ====

void FUN_00855980(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*DAT_00b5a6e4 + 8))();
  uVar1 = DAT_009b0318;
  *(undefined1 *)(in_ECX + 0x7c) = *(undefined1 *)(iVar2 + 2);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(iVar2 + 0x1c);
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined1 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined1 *)(in_ECX + 0x75) = 0;
  *(undefined1 *)(in_ECX + 0x76) = 0;
  *(undefined4 *)(in_ECX + 0x68) = uVar1;
  *(undefined1 *)(in_ECX + 0x78) = 1;
  *(undefined1 *)(in_ECX + 0x77) = 1;
  *(undefined1 *)(in_ECX + 0x79) = 1;
  *(undefined1 *)(in_ECX + 0x7a) = 1;
  *(undefined1 *)(in_ECX + 0x7b) = 0;
  *(undefined1 *)(in_ECX + 0x7d) = 0;
  *(undefined1 *)(in_ECX + 0x7e) = 1;
  *(undefined1 *)(in_ECX + 0x7f) = 0;
  return;
}


// ==== FUN_008559e0 @ 0x008559e0 ====

void FUN_008559e0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x9c))(*(int **)(in_ECX + 0x90),0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x1a0))(*(int **)(in_ECX + 0x90),0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x170))(*(int **)(in_ECX + 0x90),0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x1ac))(*(int **)(in_ECX + 0x90),0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 400))(*(int **)(in_ECX + 0x90),0,0,0,0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x104))(*(int **)(in_ECX + 0x90),0,0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x104))(*(int **)(in_ECX + 0x90),1,0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x104))(*(int **)(in_ECX + 0x90),2,0);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x104))(*(int **)(in_ECX + 0x90),3,0);
  return;
}


// ==== FUN_00855a90 @ 0x00855a90 ====

void FUN_00855a90(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),0,4,0xffffffff);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,4,0xffffffff);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),2,4,0xffffffff);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),0,1,1);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),0,2,1);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,1,1);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),1,2,1);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),2,1,1);
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x114))(*(int **)(in_ECX + 0x90),2,2,1);
  pcVar2 = (char *)(**(code **)(*DAT_00b5af74 + 4))();
  if (*pcVar2 == '\0') {
    FUN_00855590(0);
    return;
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  iVar3 = (**(code **)(*DAT_00b5af74 + 4))();
  *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(iVar3 + 4);
  FUN_00855590(1);
  return;
}


// ==== FUN_00855ba0 @ 0x00855ba0 ====

void FUN_00855ba0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x3c))();
  if (!(DAT_00a12e2c < *(float *)(iVar1 + 0x14) || DAT_00a12e2c == *(float *)(iVar1 + 0x14))) {
    param_1 = *(undefined4 *)(DAT_00b5ac04 + 0xa4);
  }
  if (*(char *)(in_ECX + 0xc0) == '\0') {
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xac))(*(int **)(in_ECX + 0x90),0,0,2,0,0x3f800000,0);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 0x90) + 0xac))(*(int **)(in_ECX + 0x90),0,0,3,param_1);
  return;
}


// ==== FUN_00855c20 @ 0x00855c20 ====

void FUN_00855c20(void)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x90) + 0x44))(*(int **)(in_ECX + 0x90),0,0,0,0);
  if (iVar1 == -0x7789f798) {
    *(undefined1 *)(in_ECX + 0x60) = 1;
    puVar2 = (undefined4 *)(in_ECX + 0x168);
    iVar1 = 0xe;
    do {
      (**(code **)(*(int *)*puVar2 + 0x40))((int *)*puVar2);
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== FUN_00855c70 @ 0x00855c70 ====

void FUN_00855c70(char param_1)

{
  HCURSOR pHVar1;
  int in_ECX;
  
  if (param_1 == '\0') {
    if (*(int *)(in_ECX + 0x70) == 0) {
      pHVar1 = SetCursor((HCURSOR)0x0);
      *(HCURSOR *)(in_ECX + 0x70) = pHVar1;
    }
  }
  else if (*(HCURSOR *)(in_ECX + 0x70) != (HCURSOR)0x0) {
    SetCursor(*(HCURSOR *)(in_ECX + 0x70));
    *(undefined4 *)(in_ECX + 0x70) = 0;
    return;
  }
  return;
}


// ==== FUN_00855cb0 @ 0x00855cb0 ====

void FUN_00855cb0(void)

{
  int in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(in_ECX + 0x4e8);
  iVar2 = 0xe;
  do {
    (**(code **)(*(int *)puVar1[-0xe0] + 8))((int *)puVar1[-0xe0]);
    puVar1[-0xe0] = 0;
    if ((HGDIOBJ)*puVar1 != (HGDIOBJ)0x0) {
      DeleteObject((HGDIOBJ)*puVar1);
      *puVar1 = 0;
    }
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_00855e70 @ 0x00855e70 ====

void FUN_00855e70(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_194;
  void *pvStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  int *piStack_184;
  undefined4 uStack_180;
  uint uStack_17c;
  undefined4 uStack_178;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined4 uStack_16c;
  int *piStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined1 *puStack_15c;
  byte bStack_144;
  uint uStack_13c;
  undefined1 local_130 [12];
  uint uStack_124;
  uint uStack_11c;
  uint uStack_104;
  byte bStack_f4;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_dc;
  undefined4 uStack_d4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_7c;
  uint uStack_74;
  
  piStack_168 = *(int **)(in_ECX + 0x8c);
  puStack_15c = local_130;
  uStack_160 = *(undefined4 *)(in_ECX + 0x10c);
  uStack_164 = *(undefined4 *)(in_ECX + 0xac);
  uStack_16c = 0x855e9a;
  (**(code **)(*piStack_168 + 0x38))();
  *(byte *)(in_ECX + 0xc4) = (byte)(uStack_124 >> 0x13) & 1;
  *(byte *)(in_ECX + 0xc5) = (byte)(uStack_11c >> 0xd) & 1;
  *(byte *)(in_ECX + 0xeb) = (byte)(uStack_11c >> 0x11) & 1;
  *(undefined4 *)(in_ECX + 0xec) = uStack_b0;
  *(byte *)(in_ECX + 0xc6) = (byte)(uStack_124 >> 0x10) & 1;
  *(undefined4 *)(in_ECX + 0xf0) = uStack_dc;
  *(byte *)(in_ECX + 199) = (byte)(uStack_124 >> 0x14) & 1;
  *(undefined4 *)(in_ECX + 0xf4) = uStack_d4;
  *(byte *)(in_ECX + 0x104) = bStack_f4 >> 3 & 1;
  *(undefined4 *)(in_ECX + 0xf8) = uStack_8c;
  *(byte *)(in_ECX + 200) = (byte)(uStack_104 >> 0xe) & 1;
  *(undefined4 *)(in_ECX + 0xd8) = uStack_ac;
  *(uint *)(in_ECX + 0xcc) = uStack_7c;
  *(undefined4 *)(in_ECX + 0xfc) = uStack_88;
  *(undefined4 *)(in_ECX + 0xdc) = uStack_a8;
  *(undefined4 *)(in_ECX + 0x100) = uStack_84;
  *(undefined4 *)(in_ECX + 0xe0) = uStack_e8;
  *(bool *)(in_ECX + 0xe8) = 0xfffe0100 < uStack_7c;
  *(uint *)(in_ECX + 0xd0) = uStack_74;
  piStack_184 = *(int **)(in_ECX + 0x8c);
  uStack_16c = 0x17;
  *(undefined4 *)(in_ECX + 0xe4) = uStack_e4;
  *(bool *)(in_ECX + 0xe9) = 0xffff0100 < uStack_74;
  *(bool *)(in_ECX + 0xea) = 0xffff01ff < uStack_74;
  uStack_170 = 3;
  uStack_178 = *(undefined4 *)(in_ECX + 0x30);
  uStack_174 = 0;
  uStack_17c = *(undefined4 *)(in_ECX + 0x10c);
  uStack_180 = *(undefined4 *)(in_ECX + 0xac);
  uStack_188 = 0x855fee;
  iVar1 = (**(code **)(*piStack_184 + 0x28))();
  *(bool *)(in_ECX + 0xd4) = -1 < iVar1;
  if ((uStack_13c & 0x800) == 0) {
    *(undefined1 *)(in_ECX + 0x105) = 0;
  }
  else {
    *(undefined1 *)(in_ECX + 0x105) = 1;
  }
  uStack_188 = 0x1c;
  uStack_18c = 3;
  *(byte *)(in_ECX + 0x106) = bStack_144 & 1;
  uStack_194 = *(undefined4 *)(in_ECX + 0x30);
  pvStack_190 = (void *)0x200;
  *(byte *)(in_ECX + 0x107) = (byte)(uStack_13c >> 7) & 1;
  *(undefined1 *)(in_ECX + 0x105) = 0;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x28))
                    (*(int **)(in_ECX + 0x8c),*(undefined4 *)(in_ECX + 0xac),
                     *(undefined4 *)(in_ECX + 0x10c));
  if (iVar1 < 0) {
    *(undefined1 *)(in_ECX + 0x108) = 0;
    return;
  }
  uStack_17c = 0xf;
  uStack_180 = 0;
  pvStack_190 = (void *)((uint)pvStack_190 & 0xffffff00);
  FUN_00401740(s_8bit_alpha_texture_enabled_00a128ac,0x1a);
  FUN_00796d20(&uStack_194);
  if (uStack_17c < 0x10) {
    *(undefined1 *)(in_ECX + 0x108) = 1;
    return;
  }
  _free(pvStack_190);
  return;
}


// ==== FUN_008560c0 @ 0x008560c0 ====

void FUN_008560c0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  char *pcStack_74;
  uint uStack_4c;
  int *piStack_48;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 local_2c;
  undefined4 *puStack_28;
  int *local_20;
  uint local_1c;
  void *local_18;
  undefined4 *local_8;
  uint local_4;
  
  if (*(char *)(in_ECX + 0xa8) == '\0') {
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    local_8 = (undefined4 *)0x0;
    local_4 = 0xf;
    if (*(int *)(in_ECX + 0xa4) == 0x10) {
      FUN_00401740();
      FUN_00796d20();
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      cVar1 = FUN_00855710();
      if (cVar1 == '\0') {
        FUN_00401830();
        FUN_00796d20();
        if (0xf < local_4) {
          _free(local_18);
          return;
        }
        cVar1 = FUN_00855710();
        if (cVar1 != '\0') {
          FUN_00401830();
          FUN_00796d20();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
      else {
        FUN_00401830();
        FUN_00796d20();
joined_r0x00856269:
        if (0xf < local_4) {
          _free(local_18);
          return;
        }
      }
    }
    else {
      FUN_00401740();
      FUN_00796d20();
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
      cVar1 = FUN_00855710();
      if (cVar1 != '\0') {
        FUN_00401830();
        FUN_00796d20();
        goto joined_r0x00856269;
      }
    }
    puVar3 = (undefined4 *)0x0;
    piStack_48 = local_20;
    *param_1 = local_20;
    uStack_4c = *(uint *)(in_ECX + 0x10c);
    (**(code **)(**(int **)(in_ECX + 0x8c) + 0x24))();
    local_1c = 0xf;
    local_20 = (int *)0x0;
    unaff_EBX = (void *)((uint)unaff_EBX & 0xffffff00);
    FUN_00401740();
    FUN_00796d20();
    if (0xf < local_1c) {
      _free(unaff_EBX);
      return;
    }
  }
  else {
    piStack_48 = *(int **)(in_ECX + 0x8c);
    puVar3 = &local_2c;
    (**(code **)(*piStack_48 + 0x20))();
    param_1 = local_8;
    uStack_4c = 1;
    *local_8 = local_2c;
    (**(code **)(**(int **)(in_ECX + 0x8c) + 0x24))();
  }
  local_1c = 0xf;
  local_20 = (int *)0x0;
  pvVar4 = (void *)((uint)unaff_EBX & 0xffffff00);
  if (*(char *)(in_ECX + 0xa8) == '\0') {
    if (*(int *)(in_ECX + 0x94) == 0x10) {
      FUN_00401740();
      FUN_00796d20();
      if (0xf < local_1c) {
        _free(pvVar4);
        return;
      }
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x30))();
      if (iVar2 == 0) {
        pcStack_74 = (char *)0x8563a5;
        FUN_00401830();
        goto LAB_00856622;
      }
      uStack_78 = *param_1;
      uStack_7c = *(undefined4 *)(in_ECX + 0x10c);
      pcStack_74 = (char *)uStack_78;
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x30))();
      if (iVar2 == 0) {
        uStack_8c = 0x8563e0;
        FUN_00401830();
        uStack_8c = 0x8563ea;
        FUN_00796d20();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      FUN_00401740();
      FUN_00796d20();
      if (0xf < local_1c) {
        _free(pvVar4);
        return;
      }
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x30))();
      if (iVar2 == 0) {
        pcStack_74 = (char *)0x856466;
        FUN_00401830();
        pcStack_74 = (char *)0x856470;
        FUN_00796d20();
        if (unaff_EBP < 0x10) {
          *puStack_28 = 0x47;
          return;
        }
        pcStack_74 = (char *)0x856483;
        _free(piStack_48);
        return;
      }
      uStack_78 = *param_1;
      uStack_7c = *(undefined4 *)(in_ECX + 0x10c);
      pcStack_74 = (char *)uStack_78;
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x30))();
      if (iVar2 == 0) {
        uStack_8c = 0x8564cc;
        FUN_00401830();
        uStack_8c = 0x8564d6;
        FUN_00796d20();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uStack_90 = *param_1;
      uStack_94 = *(undefined4 *)(in_ECX + 0x10c);
      uStack_8c = uStack_90;
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x30))
                        (*(int **)(in_ECX + 0x8c),*(undefined4 *)(in_ECX + 0xac));
      if (iVar2 == 0) {
        FUN_00401830(s_D3DFMT_D24X8_format_ok_00a12a48);
        FUN_00796d20(&uStack_7c);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x30))
                        (*(int **)(in_ECX + 0x8c),*(undefined4 *)(in_ECX + 0xac),
                         *(undefined4 *)(in_ECX + 0x10c),*param_1,*param_1,0x4f);
      if (iVar2 == 0) {
        FUN_00401830(s_D3DFMT_D24X4S4_format_ok_00a12a60);
        FUN_00796d20(&uStack_94);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  else {
    FUN_00401740();
    FUN_00796d20();
    if (0xf < local_1c) {
      _free(pvVar4);
      return;
    }
    pvVar4 = (void *)*param_1;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x30))();
    if (iVar2 == 0) {
      pcStack_74 = s_D3DFMT_D16_format_ok_00a12aac;
      unaff_EBP = 0xf;
      piStack_48 = (int *)((uint)piStack_48 & 0xffffff00);
      uStack_78 = 0x856622;
      FUN_00401740();
LAB_00856622:
      pcStack_74 = (char *)0x85662c;
      FUN_00796d20();
      if (unaff_EBP < 0x10) {
        *puStack_28 = 0x50;
        return;
      }
      pcStack_74 = (char *)0x85663f;
      _free(piStack_48);
      return;
    }
    uStack_78 = *param_1;
    uStack_7c = *(undefined4 *)(in_ECX + 0x10c);
    pcStack_74 = (char *)uStack_78;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x30))();
    if (iVar2 == 0) {
      uStack_8c = 0x856688;
      FUN_00401830();
      uStack_8c = 0x856692;
      FUN_00796d20();
      if (0xf < uStack_4c) {
        uStack_8c = 0x8566a5;
        _free(pvVar4);
        return;
      }
      *puVar3 = 0x49;
    }
  }
  return;
}


// ==== FUN_008566c0 @ 0x008566c0 ====

void FUN_008566c0(undefined4 *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iStack_4;
  
  iStack_4 = in_ECX;
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if ((*(char *)(in_ECX + 0x106) != '\0') || (*(char *)(in_ECX + 0xa8) != '\0')) {
    puVar6 = param_1 + 2;
    FUN_00857e00(&param_1,puVar6);
    puVar5 = param_1;
    if (param_1 == *(undefined4 **)(in_ECX + 0x140)) {
      return;
    }
    if ((int)param_1[0x11] < 2) {
      cVar2 = FUN_00857ed0(puVar6,0);
      if (cVar2 == '\0') {
        (**(code **)(**(int **)(in_ECX + 0x90) + 0x28))(*(int **)(in_ECX + 0x90),0,0,puVar5[0xe]);
        return;
      }
      return;
    }
    if (200 < (uint)(iVar3 - *(int *)(in_ECX + 0x88))) {
      if (*(int *)(in_ECX + 0x84) == 0) {
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + -1;
      }
      else {
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + 1;
      }
      *(int *)(in_ECX + 0x88) = iVar3;
    }
    iVar3 = *(int *)(in_ECX + 0x80);
    iVar1 = param_1[0x11];
    if (iVar3 < iVar1) {
      if (-1 < iVar3) goto LAB_0085689c;
      if (iVar1 <= iVar3) goto LAB_0085686f;
    }
    else {
LAB_0085686f:
      *(int *)(in_ECX + 0x80) = iVar1 + -1;
    }
    if (*(int *)(in_ECX + 0x80) < 0) {
      *(undefined4 *)(in_ECX + 0x80) = 0;
    }
    *(uint *)(in_ECX + 0x84) = (uint)(*(int *)(in_ECX + 0x84) == 0);
LAB_0085689c:
    cVar2 = FUN_00857ed0(puVar6,*(undefined4 *)(in_ECX + 0x80));
    if (cVar2 == '\0') {
      (**(code **)(**(int **)(in_ECX + 0x90) + 0x28))
                (*(int **)(in_ECX + 0x90),0,0,puVar5[*(int *)(in_ECX + 0x80) + 0xe]);
      return;
    }
    return;
  }
  puVar5 = param_1 + 2;
  FUN_00857e00(&iStack_4,puVar5);
  if (iStack_4 == *(int *)(in_ECX + 0x140)) goto LAB_008567d5;
  if (*(int *)(iStack_4 + 0x44) < 2) {
    cVar2 = FUN_00857ed0(puVar5,0);
    if (cVar2 != '\0') goto LAB_008567d5;
    uVar4 = *(undefined4 *)(iStack_4 + 0x38);
  }
  else {
    if (200 < (uint)(iVar3 - *(int *)(in_ECX + 0x88))) {
      if (*(int *)(in_ECX + 0x84) == 0) {
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + -1;
      }
      else {
        *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + 1;
      }
      *(int *)(in_ECX + 0x88) = iVar3;
    }
    iVar3 = *(int *)(in_ECX + 0x80);
    iVar1 = *(int *)(iStack_4 + 0x44);
    if (iVar3 < iVar1) {
      if (iVar3 < 0) {
        if (iVar1 <= iVar3) goto LAB_00856767;
        goto LAB_00856770;
      }
    }
    else {
LAB_00856767:
      *(int *)(in_ECX + 0x80) = iVar1 + -1;
LAB_00856770:
      if (*(int *)(in_ECX + 0x80) < 0) {
        *(undefined4 *)(in_ECX + 0x80) = 0;
      }
      *(uint *)(in_ECX + 0x84) = (uint)(*(int *)(in_ECX + 0x84) == 0);
    }
    cVar2 = FUN_00857ed0(puVar5,*(undefined4 *)(in_ECX + 0x80));
    if (cVar2 != '\0') goto LAB_008567d5;
    uVar4 = *(undefined4 *)(iStack_4 + 0x38 + *(int *)(in_ECX + 0x80) * 4);
  }
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x28))(*(int **)(in_ECX + 0x90),0,0,uVar4);
LAB_008567d5:
  (**(code **)(**(int **)(in_ECX + 0x90) + 0x2c))(*(int **)(in_ECX + 0x90),*param_1,param_1[1],1);
  return;
}


// ==== FUN_00856900 @ 0x00856900 ====

void FUN_00856900(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  HFONT pHVar5;
  int in_ECX;
  CHAR *pCVar6;
  LOGFONTA *pLVar7;
  int iVar8;
  LONG *pLVar9;
  float10 fVar10;
  int iStack_94;
  LONG *pLStack_8c;
  undefined4 *puStack_88;
  LOGFONTA LStack_80;
  int local_44;
  int local_40;
  void *local_3c;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  uint local_28 [9];
  
  local_28[0] = 0xf;
  local_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  FUN_00401740(s_fontdescription_lua_00a12b28,0x13);
  iVar2 = FUN_0059a1e0();
  local_44 = iVar2;
  if (0xf < local_28[0]) {
    _free(local_3c);
    return;
  }
  local_28[0] = 0xf;
  local_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  uVar3 = (**(code **)(*DAT_00b5a6bc + 8))();
  if (*(uint *)(iVar2 + 0x54) < 0x10) {
    iVar8 = iVar2 + 0x40;
  }
  else {
    iVar8 = *(int *)(iVar2 + 0x40);
  }
  FUN_007bb860(uVar3,iVar8,*(undefined4 *)(iVar2 + 0x50),&DAT_00a12b3c);
  FUN_007bca30(uVar3,0,0,0);
  FUN_007bc470(uVar3,s_font_description_00a12b44);
  FUN_007bc620(uVar3,0xffffd8ef);
  LStack_80.lfFaceName[0] = s_Web_UlleungDo_nw10_00a12b58[0];
  LStack_80.lfFaceName[1] = s_Web_UlleungDo_nw10_00a12b58[1];
  LStack_80.lfFaceName[2] = s_Web_UlleungDo_nw10_00a12b58[2];
  LStack_80.lfFaceName[3] = s_Web_UlleungDo_nw10_00a12b58[3];
  LStack_80.lfFaceName[0xc] = s_Web_UlleungDo_nw10_00a12b58[0xc];
  LStack_80.lfFaceName[0xd] = s_Web_UlleungDo_nw10_00a12b58[0xd];
  LStack_80.lfFaceName[0xe] = s_Web_UlleungDo_nw10_00a12b58[0xe];
  LStack_80.lfFaceName[0xf] = s_Web_UlleungDo_nw10_00a12b58[0xf];
  LStack_80.lfFaceName[4] = s_Web_UlleungDo_nw10_00a12b58[4];
  LStack_80.lfFaceName[5] = s_Web_UlleungDo_nw10_00a12b58[5];
  LStack_80.lfFaceName[6] = s_Web_UlleungDo_nw10_00a12b58[6];
  LStack_80.lfFaceName[7] = s_Web_UlleungDo_nw10_00a12b58[7];
  LStack_80.lfFaceName[8] = s_Web_UlleungDo_nw10_00a12b58[8];
  LStack_80.lfFaceName[9] = s_Web_UlleungDo_nw10_00a12b58[9];
  LStack_80.lfFaceName[10] = s_Web_UlleungDo_nw10_00a12b58[10];
  LStack_80.lfFaceName[0xb] = s_Web_UlleungDo_nw10_00a12b58[0xb];
  LStack_80.lfFaceName[0x13] = '\0';
  LStack_80.lfFaceName[0x14] = '\0';
  LStack_80.lfFaceName[0x15] = '\0';
  LStack_80.lfFaceName[0x16] = '\0';
  LStack_80.lfFaceName[0x17] = '\0';
  LStack_80.lfFaceName[0x18] = '\0';
  LStack_80.lfFaceName[0x19] = '\0';
  LStack_80.lfFaceName[0x1a] = '\0';
  LStack_80.lfWidth = 0;
  LStack_80.lfEscapement = 0;
  LStack_80.lfOrientation = 0;
  LStack_80.lfFaceName[0x10] = s_Web_UlleungDo_nw10_00a12b58[0x10];
  LStack_80.lfFaceName[0x11] = s_Web_UlleungDo_nw10_00a12b58[0x11];
  LStack_80.lfFaceName[0x12] = s_Web_UlleungDo_nw10_00a12b58[0x12];
  LStack_80.lfFaceName[0x1b] = '\0';
  LStack_80.lfFaceName[0x1c] = '\0';
  LStack_80.lfFaceName[0x1d] = '\0';
  LStack_80.lfFaceName[0x1e] = '\0';
  puStack_88 = (undefined4 *)(in_ECX + 0x4e8);
  pLStack_8c = (LONG *)(in_ECX + 0x1a0);
  LStack_80.lfHeight = 0xd;
  LStack_80.lfWeight = 700;
  LStack_80.lfItalic = '\0';
  LStack_80.lfUnderline = '\0';
  LStack_80.lfStrikeOut = '\0';
  LStack_80.lfCharSet = '\x01';
  LStack_80.lfOutPrecision = '\0';
  LStack_80.lfClipPrecision = '\0';
  LStack_80.lfQuality = '\0';
  LStack_80.lfPitchAndFamily = '\0';
  LStack_80.lfFaceName[0x1f] = '\0';
  iStack_94 = 1;
  do {
    FUN_007bc400(uVar3,(double)iStack_94);
    FUN_007bc620(uVar3,0xfffffffe);
    FUN_007bc470(uVar3,s_height_00a12b6c);
    FUN_007bc620(uVar3,0xfffffffe);
    fVar10 = (float10)FUN_007bc1a0(uVar3,0xffffffff);
    LStack_80.lfHeight = (LONG)ROUND(fVar10);
    FUN_007bbdf0(uVar3,0xfffffffe);
    FUN_007bc470(uVar3,s_width_00a12b74);
    FUN_007bc620(uVar3,0xfffffffe);
    fVar10 = (float10)FUN_007bc1a0(uVar3);
    LStack_80.lfWidth = (LONG)ROUND(fVar10);
    FUN_007bbdf0(uVar3,0xfffffffe);
    FUN_007bc470(uVar3,s_weight_00a12b7c);
    FUN_007bc620(uVar3,0xfffffffe);
    fVar10 = (float10)FUN_007bc1a0(uVar3,0xffffffff);
    LStack_80.lfWeight = (LONG)ROUND(fVar10);
    FUN_007bbdf0(uVar3,0xfffffffe);
    FUN_007bc470(uVar3,s_shadow_00a12b84);
    FUN_007bc620(uVar3,0xfffffffe);
    iVar2 = FUN_007bc1f0(uVar3);
    *(bool *)(in_ECX + 0x51f + iStack_94) = iVar2 != 0;
    FUN_007bbdf0(uVar3,0xfffffffe);
    FUN_007bc470(uVar3,s_facename_00a12b8c);
    FUN_007bc620(uVar3,0xfffffffe);
    pcVar4 = (char *)FUN_007bc230(uVar3,0xffffffff);
    pCVar6 = LStack_80.lfFaceName;
    do {
      cVar1 = *pcVar4;
      *pCVar6 = cVar1;
      pcVar4 = pcVar4 + 1;
      pCVar6 = pCVar6 + 1;
    } while (cVar1 != '\0');
    FUN_007bbdf0(uVar3);
    FUN_007bbdf0(uVar3,0xfffffffe);
    pLVar7 = &LStack_80;
    pLVar9 = pLStack_8c;
    for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pLVar9 = pLVar7->lfHeight;
      pLVar7 = (LOGFONTA *)&pLVar7->lfWidth;
      pLVar9 = pLVar9 + 1;
    }
    local_40 = LStack_80.lfHeight;
    local_3c = (void *)LStack_80.lfWidth;
    iStack_38 = LStack_80.lfWeight;
    iVar2 = 0;
    uStack_34 = 1;
    uStack_30 = 0;
    local_2c = CONCAT13(LStack_80.lfPitchAndFamily,
                        CONCAT12(LStack_80.lfQuality,
                                 CONCAT11(LStack_80.lfOutPrecision,LStack_80.lfCharSet)));
    do {
      cVar1 = LStack_80.lfFaceName[iVar2];
      *(char *)((int)local_28 + iVar2) = cVar1;
      iVar2 = iVar2 + 1;
    } while (cVar1 != '\0');
    FUN_008a1669(*(undefined4 *)(in_ECX + 0x90),&local_40,puStack_88 + -0xe0);
    pHVar5 = CreateFontIndirectA(&LStack_80);
    pLStack_8c = pLStack_8c + 0xf;
    iStack_94 = iStack_94 + 1;
    *puStack_88 = pHVar5;
    puStack_88 = puStack_88 + 1;
  } while (iStack_94 < 0xf);
  FUN_007bbdf0(uVar3,0xfffffffe);
  (**(code **)(*DAT_00b5a7cc + 0x14))();
  return;
}


// ==== FUN_00856cb0 @ 0x00856cb0 ====

/* WARNING: Removing unreachable block (ram,0x00856d6e) */
/* WARNING: Removing unreachable block (ram,0x00856ef6) */
/* WARNING: Removing unreachable block (ram,0x00856d03) */
/* WARNING: Removing unreachable block (ram,0x00856e8b) */

int FUN_00856cb0(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int extraout_EAX;
  int extraout_EAX_00;
  int in_ECX;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  
  FUN_00855e70();
  if (*(int *)(in_ECX + 0x98) == 0x10) {
    FUN_00401740();
    FUN_00796d20();
    uVar1 = *(uint *)(in_ECX + 0x10c);
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x28))();
    if (-1 < iVar3) {
      FUN_00401740();
      FUN_00796d20();
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x28))();
      if (-1 < iVar3) {
        uStack_68 = 0x856db4;
        FUN_00401830();
        uStack_68 = 0x856dbe;
        FUN_00796d20();
        if (0xf < uVar1) {
          uStack_68 = 0x856dd1;
          _free((void *)0x0);
          return extraout_EAX;
        }
        piVar2 = *(int **)(in_ECX + 0x8c);
        if (*(char *)(in_ECX + 0xd4) == '\0') {
          uStack_70 = *(undefined4 *)(in_ECX + 0x30);
          uStack_68 = 3;
          uStack_6c = 0;
          iVar3 = (**(code **)(*piVar2 + 0x28))
                            (piVar2,*(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0x10c));
          if (-1 < iVar3) {
            FUN_00401830(s_X1A5B5G5_ok_00a12860);
LAB_00856e1a:
            FUN_00796d20(&uStack_70);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
        }
        else {
          uStack_70 = *(undefined4 *)(in_ECX + 0x30);
          uStack_68 = 3;
          uStack_6c = 0;
          iVar3 = (**(code **)(*piVar2 + 0x28))
                            (piVar2,*(undefined4 *)(in_ECX + 0xac),*(undefined4 *)(in_ECX + 0x10c));
          if (-1 < iVar3) {
            FUN_00401830(s_A5B6G5_ok_00a1286c);
            goto LAB_00856e1a;
          }
        }
      }
    }
  }
  else {
    FUN_00401740();
    FUN_00796d20();
    uVar1 = *(uint *)(in_ECX + 0x10c);
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x28))();
    if (-1 < iVar3) {
      FUN_00401740();
      FUN_00796d20();
      iVar3 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x28))();
      if (-1 < iVar3) {
        uStack_68 = 0x856f38;
        FUN_00401830();
        uStack_68 = 0x856f42;
        FUN_00796d20();
        if (0xf < uVar1) {
          uStack_68 = 0x856f55;
          _free((void *)0x0);
          return extraout_EAX_00;
        }
        iVar3 = 0;
      }
    }
  }
  return iVar3;
}


// ==== FUN_00856f70 @ 0x00856f70 ====

void FUN_00856f70(void)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int local_8;
  undefined1 local_4 [4];
  
  piVar1 = (int *)(in_ECX + 0x28);
  piVar4 = piVar1;
  for (iVar2 = 0xe; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
  }
  *(uint *)(in_ECX + 0x48) = (uint)*(byte *)(in_ECX + 0xa8);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0xbc);
  *(undefined4 *)(in_ECX + 0x40) = 1;
  *(undefined4 *)(in_ECX + 0x4c) = 1;
  if (*(byte *)(in_ECX + 0xa8) == 0) {
    *(undefined4 *)(in_ECX + 0x58) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5c) = 0x80000000;
  }
  FUN_008560c0(&local_8,local_4);
  uVar3 = (uint)*(byte *)(in_ECX + 0xa8);
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x2c))
                    (*(int **)(in_ECX + 0x8c),*(undefined4 *)(in_ECX + 0xac),
                     *(undefined4 *)(in_ECX + 0x10c),local_8,uVar3,*(undefined4 *)(in_ECX + 0xb8),0)
  ;
  if (iVar2 < 0) {
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0xb8);
  }
  *(int *)(in_ECX + 0x30) = local_8;
  if (*(char *)(in_ECX + 0xa8) == '\0') {
    *piVar1 = *(int *)(in_ECX + 0xa0);
    *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x9c);
  }
  else {
    *piVar1 = *(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x14);
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x20) - *(int *)(in_ECX + 0x18);
    if (local_8 == 0x16) {
      *(undefined4 *)(in_ECX + 0xa4) = 0x20;
    }
    else if (((local_8 == 0x1e) || (local_8 == 0x18)) || (local_8 == 0x17)) {
      *(undefined4 *)(in_ECX + 0xa4) = 0x10;
    }
  }
  *(uint *)(in_ECX + 0x50) = uVar3;
  *(undefined4 *)(in_ECX + 0x54) = 2;
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(in_ECX + 0xb4);
  return;
}


// ==== FUN_00857090 @ 0x00857090 ====

void FUN_00857090(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x140);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if (puVar3[10] != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(puVar3[10]);
      puVar3[10] = 0;
    }
    piVar8 = puVar3 + 0xb;
    iVar7 = 3;
    do {
      piVar4 = (int *)piVar8[3];
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 8))(piVar4);
        piVar8[3] = 0;
      }
      piVar4 = (int *)*piVar8;
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 8))(piVar4);
        *piVar8 = 0;
      }
      piVar8 = piVar8 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (*(char *)((int)puVar3 + 0x49) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x49) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x49);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x49);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x49);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x49);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  FUN_008582b0(*(undefined4 *)(*(int *)(in_ECX + 0x140) + 4));
  *(int *)(*(int *)(in_ECX + 0x140) + 4) = *(int *)(in_ECX + 0x140);
  *(undefined4 *)(in_ECX + 0x144) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x140) = *(undefined4 *)(in_ECX + 0x140);
  *(int *)(*(int *)(in_ECX + 0x140) + 8) = *(int *)(in_ECX + 0x140);
  return;
}


// ==== FUN_00857180 @ 0x00857180 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00857180(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  int in_ECX;
  char *pcVar6;
  undefined4 unaff_EBX;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uStack_f8;
  int iStack_f4;
  int iStack_f0;
  int *piStack_e8;
  undefined1 local_e4 [4];
  void *local_e0;
  undefined4 local_d0;
  uint local_cc;
  undefined1 auStack_c8 [4];
  void *pvStack_c4;
  undefined4 uStack_b4;
  uint uStack_b0;
  int iStack_ac;
  uint auStack_a8 [3];
  void *pvStack_9c;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined4 uStack_84;
  int aiStack_80 [8];
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  int aiStack_44 [8];
  undefined1 auStack_24 [32];
  
  FUN_00857090();
  local_cc = 0xf;
  local_d0 = 0;
  local_e0 = (void *)((uint)local_e0 & 0xffffff00);
  FUN_00401740(s_mouse_shape_lua_00a12af0,0xf);
  iVar2 = FUN_0059a1e0();
  if (0xf < local_cc) {
    _free(local_e0);
    return;
  }
  local_cc = 0xf;
  local_d0 = 0;
  local_e0 = (void *)((uint)local_e0 & 0xffffff00);
  uVar3 = (**(code **)(*DAT_00b5a6bc + 8))();
  if (*(uint *)(iVar2 + 0x54) < 0x10) {
    iVar7 = iVar2 + 0x40;
  }
  else {
    iVar7 = *(int *)(iVar2 + 0x40);
  }
  iVar2 = FUN_007bb860(uVar3,iVar7,*(undefined4 *)(iVar2 + 0x50));
  if (iVar2 != 0) {
    pcVar4 = (char *)FUN_007bc230(uVar3);
    uStack_b0 = 0xf;
    uStack_b4 = 0;
    pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
    pcVar6 = pcVar4;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar4,(int)pcVar6 - (int)(pcVar4 + 1));
    if (0xf < uStack_b0) {
      _free(pvStack_c4);
      return;
    }
  }
  FUN_007bca30(uVar3,0,0,0);
  FUN_007bc470(uVar3,s_mouse_shape_00a12b08);
  FUN_007bc620(uVar3,0xffffd8ef);
  iStack_f4 = 1;
  FUN_007bc400(uVar3,_DAT_0099d0a0);
  FUN_007bc620(uVar3,0xfffffffe);
  iVar2 = FUN_007bbfa0(uVar3,0xffffffff);
  while( true ) {
    if (iVar2 != 5) {
      FUN_007bbdf0(uVar3,0xfffffffe);
      FUN_007bbdf0(uVar3,0xfffffffe);
      return;
    }
    iVar2 = 0;
    do {
      aiStack_80[iVar2 + 4] = 0;
      aiStack_80[iVar2 + 1] = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    FUN_007bc470(uVar3);
    FUN_007bc620(uVar3,0xfffffffe);
    pcVar4 = (char *)FUN_007bc230(uVar3,0xffffffff);
    uStack_b0 = 0xf;
    uStack_b4 = 0;
    pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
    pcVar6 = pcVar4;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar4,(int)pcVar6 - (int)(pcVar4 + 1));
    FUN_007bbdf0(uVar3);
    FUN_007bc470(uVar3,s_mouseres_00a12b1c);
    FUN_007bc620(uVar3,0xfffffffe);
    pcVar4 = (char *)FUN_007bc230(uVar3,0xffffffff);
    local_cc = 0xf;
    local_d0 = 0;
    local_e0 = (void *)((uint)local_e0 & 0xffffff00);
    pcVar6 = pcVar4;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar4,(int)pcVar6 - (int)(pcVar4 + 1));
    FUN_007bbdf0(uVar3);
    piVar8 = DAT_00b5a7cc;
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    FUN_00401660(local_e4,0,0xffffffff);
    uStack_84 = 0x11;
    iStack_ac = (**(code **)(*piVar8 + 8))();
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return;
    }
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    aiStack_80[0] = iStack_ac;
    auStack_a8[0] = FUN_004b2e50();
    iVar2 = 0;
    uStack_f8 = 0;
    if (auStack_a8[0] != 0) {
      do {
        iVar5 = FUN_004b2e70();
        iVar7 = *(int *)(iVar5 + 4);
        if ((iVar7 != 0) && (iVar5 = *(int *)(iVar5 + 8) - iVar7, iVar5 != 0)) {
          FUN_008a14d8(*(undefined4 *)(in_ECX + 0x90),iVar7,iVar5,0x20,0x20,1,0,0x15,1,0xffffffff,4,
                       0,auStack_24,0,&piStack_e8);
          (**(code **)(*piStack_e8 + 0x48))(piStack_e8,0);
          (**(code **)(**(int **)(in_ECX + 0x90) + 0x28))(*(int **)(in_ECX + 0x90),0,0,unaff_EBX);
          aiStack_80[iVar2 + 1] = (int)piStack_e8;
          aiStack_80[iVar2 + 4] = iStack_f0;
          iVar2 = iVar2 + 1;
        }
        uStack_f8 = uStack_f8 + 1;
      } while (uStack_f8 < auStack_a8[0]);
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    aiStack_80[7] = iVar2;
    FUN_00401660(auStack_c8,0,0xffffffff);
    piVar8 = aiStack_80;
    piVar9 = aiStack_44;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar9 = *piVar8;
      piVar8 = piVar8 + 1;
      piVar9 = piVar9 + 1;
    }
    FUN_008584f0(auStack_a8,auStack_60);
    if (0xf < uStack_48) {
      _free(pvStack_5c);
      return;
    }
    uStack_48 = 0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    FUN_007bbdf0(uVar3);
    if (0xf < local_cc) {
      _free(local_e0);
      return;
    }
    local_cc = 0xf;
    local_d0 = 0;
    local_e0 = (void *)((uint)local_e0 & 0xffffff00);
    if (0xf < uStack_b0) break;
    iStack_f4 = iStack_f4 + 1;
    uStack_b0 = 0xf;
    uStack_b4 = 0;
    pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
    FUN_007bc400(uVar3,(double)iStack_f4);
    FUN_007bc620(uVar3,0xfffffffe);
    iVar2 = FUN_007bbfa0(uVar3,0xffffffff);
  }
  _free(pvStack_c4);
  return;
}


// ==== FUN_008575f0 @ 0x008575f0 ====

/* WARNING: Removing unreachable block (ram,0x00857931) */

void FUN_008575f0(void)

{
  char cVar1;
  int iVar2;
  HWND pHVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  LPCSTR ***lpText;
  CHAR *lpText_00;
  int in_ECX;
  uint unaff_EBP;
  undefined4 *puVar7;
  undefined4 *puVar8;
  bool bVar9;
  undefined4 *unaff_retaddr;
  char *pcVar10;
  char *pcVar11;
  CHAR *_Memory;
  UINT UVar12;
  CHAR aCStack_b02 [2];
  undefined1 auStack_ad8 [4];
  LPCSTR ***appppCStack_ad4 [5];
  uint uStack_ac0;
  char acStack_a9c [480];
  undefined1 auStack_8bc [496];
  char acStack_6cc [1144];
  char acStack_254 [596];
  
  iVar2 = Direct3DCreate9();
  *(int *)(in_ECX + 0x8c) = iVar2;
  if (iVar2 == 0) {
    _sprintf(acStack_a9c,s_Could_not_initialize_Direct3D__Y_00a12b98);
    UVar12 = 0x10;
    pcVar11 = s_Dekaron_Client_00a12e08;
    pcVar10 = acStack_a9c;
    pHVar3 = (HWND)(**(code **)(*DAT_00b5a688 + 0x40))();
    MessageBoxA(pHVar3,pcVar10,pcVar11,UVar12);
    PostQuitMessage(0);
    return;
  }
  if ((DAT_00b5b144 == 0) && (pvVar4 = operator_new(0x28), pvVar4 != (void *)0x0)) {
    FUN_008817d0();
  }
  puVar7 = unaff_retaddr;
  puVar8 = (undefined4 *)(in_ECX + 0x94);
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  GetWindowRect((HWND)unaff_retaddr[8],(LPRECT)(in_ECX + 4));
  GetClientRect((HWND)unaff_retaddr[8],(LPRECT)(in_ECX + 0x14));
  FUN_00855980();
  FUN_00856f70();
  uVar5 = FUN_008556b0();
  *(undefined4 *)(in_ECX + 0x24) = uVar5;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x10))();
  if (iVar2 != 0) {
    do {
      (**(code **)(**(int **)(in_ECX + 0x8c) + 0x14))(*(int **)(in_ECX + 0x8c),unaff_EBP);
      iVar2 = 0x11;
      bVar9 = true;
      pcVar10 = acStack_254;
      pcVar11 = s_NVIDIA_NVPerfHUD_00a127c4;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar9 = *pcVar10 == *pcVar11;
        pcVar10 = pcVar10 + 1;
        pcVar11 = pcVar11 + 1;
      } while (bVar9);
      if (bVar9) {
        unaff_retaddr[6] = unaff_EBP;
        *(undefined4 *)(in_ECX + 0x10c) = 2;
        *(undefined4 *)(in_ECX + 0x24) = 0x40;
        break;
      }
      unaff_EBP = unaff_EBP + 1;
      uVar6 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x10))();
    } while (unaff_EBP < uVar6);
  }
  _Memory = (CHAR *)(in_ECX + 0x90);
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x8c) + 0x40))
                    (*(int **)(in_ECX + 0x8c),unaff_retaddr[6],*(undefined4 *)(in_ECX + 0x10c),
                     unaff_retaddr[8],*(undefined4 *)(in_ECX + 0x24));
  if (iVar2 < 0) {
    FUN_00401740(s_<<_error_>>_Can_t_Create_Device___00a127d8,0x26);
    FUN_00404230(auStack_ad8);
    lpText = appppCStack_ad4[0];
    if (uStack_ac0 < 0x10) {
      lpText = (LPCSTR ***)appppCStack_ad4;
    }
    UVar12 = 0x30;
    pcVar10 = s_Fatal_Error_00a12800;
    pHVar3 = GetForegroundWindow();
    MessageBoxA(pHVar3,(LPCSTR)lpText,pcVar10,UVar12);
    FUN_00401740(s__u__x__x_00a1280c,8);
    FUN_00404230(aCStack_b02 + -0xe);
    lpText_00 = _Memory;
    if (unaff_EBP < 0x10) {
      lpText_00 = aCStack_b02 + -10;
    }
    UVar12 = 0x30;
    pcVar10 = s_Fatal_Error_00a12818;
    pHVar3 = GetForegroundWindow();
    MessageBoxA(pHVar3,lpText_00,pcVar10,UVar12);
    if (0xf < unaff_EBP) {
      _free(_Memory);
      return;
    }
    if (0xf < uStack_ac0) {
      _free(appppCStack_ad4[0]);
      return;
    }
  }
  FUN_00856cb0();
  (**(code **)(**(int **)(in_ECX + 0x8c) + 0x14))
            (*(int **)(in_ECX + 0x8c),unaff_retaddr[6],0,auStack_8bc);
  pcVar10 = acStack_6cc;
  do {
    cVar1 = *pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_6cc,(int)pcVar10 - (int)(acStack_6cc + 1));
  iVar2 = FUN_00405850(s_NVIDIA_00a12824,0,6);
  if (iVar2 != -1) {
    *(undefined1 *)(in_ECX + 0x7f) = 1;
  }
  FUN_008553a0();
  FUN_00855a90();
  FUN_00856900();
  FUN_00857180();
  if (DAT_00b5a6c4 != (int *)0x0) {
    (**(code **)(*DAT_00b5a6c4 + 4))
              (CONCAT31((int3)((uint)*(undefined4 *)(in_ECX + 0x6c) >> 8),
                        *(undefined1 *)(in_ECX + 0xa8)),*(undefined4 *)(in_ECX + 0x6c));
  }
  return;
}


// ==== FUN_00857950 @ 0x00857950 ====

undefined4 FUN_00857950(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  int *piStack_410;
  
  puVar3 = (undefined4 *)(in_ECX + 0x168);
  iVar2 = 0xe;
  do {
    piStack_410 = (int *)*puVar3;
    (**(code **)(*piStack_410 + 0x40))();
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piStack_410 = (int *)0x85797d;
  FUN_008559e0();
  piStack_410 = (int *)(in_ECX + 0x28);
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x90) + 0x40))(*(int **)(in_ECX + 0x90));
  if (iVar2 == -0x7789f798) {
    uVar1 = FUN_00973e6b(0x88760868);
    uVar1 = FUN_0096231f(0x88760868,uVar1);
    _sprintf((char *)&piStack_410,s__DXError___s____s_00a12adc,uVar1);
    OutputDebugStringA((LPCSTR)&piStack_410);
    return 0;
  }
  FUN_008557e0();
  FUN_008553a0();
  FUN_00857180();
  FUN_00401740(&DAT_00a12aee,0);
  *(undefined4 *)(in_ECX + 0x164) = 0;
  (**(code **)(*DAT_00b5d984 + 0xc))();
  (**(code **)(*DAT_00b5d980 + 0x14))();
  return 1;
}


// ==== FUN_00857a30 @ 0x00857a30 ====

void FUN_00857a30(void)

{
  int in_ECX;
  int *piStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_10 = 0;
  uStack_14 = 0;
  piStack_20 = *(int **)(in_ECX + 0x90);
  uStack_18 = 0;
  uStack_1c = 0;
  uStack_24 = 0x857a4a;
  (**(code **)(*piStack_20 + 400))();
  piStack_28 = *(int **)(in_ECX + 0x90);
  uStack_24 = 0;
  (**(code **)(*piStack_28 + 0x1a0))();
  FUN_00857090();
  FUN_00855cb0();
  (**(code **)(**(int **)(in_ECX + 0x90) + 8))(*(int **)(in_ECX + 0x90));
  (**(code **)(**(int **)(in_ECX + 0x8c) + 8))(*(int **)(in_ECX + 0x8c));
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  if (DAT_00b5b144 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b144)(1);
  }
  if (*(uint *)(in_ECX + 0x160) < 0x10) {
    *(undefined4 *)(in_ECX + 0x160) = 0xf;
    *(undefined4 *)(in_ECX + 0x15c) = 0;
    *(undefined1 *)(in_ECX + 0x14c) = 0;
    FUN_00858660(&piStack_28,**(undefined4 **)(in_ECX + 0x140),*(undefined4 **)(in_ECX + 0x140));
    _free(*(void **)(in_ECX + 0x140));
    return;
  }
  _free(*(void **)(in_ECX + 0x14c));
  return;
}


// ==== FUN_00857b00 @ 0x00857b00 ====

void FUN_00857b00(void)

{
  int iVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 1;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined1 *)(in_ECX + 0x110) = 1;
  *(undefined1 *)(in_ECX + 0x111) = 0;
  *(undefined1 *)(in_ECX + 0x112) = 1;
  *(undefined1 *)(in_ECX + 0x113) = 1;
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 2;
  *(undefined4 *)(in_ECX + 0x11c) = 1;
  *(undefined4 *)(in_ECX + 0x130) = 1;
  iVar1 = FUN_00857ca0();
  *(int *)(in_ECX + 0x140) = iVar1;
  *(undefined1 *)(iVar1 + 0x49) = 1;
  *(int *)(*(int *)(in_ECX + 0x140) + 4) = *(int *)(in_ECX + 0x140);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x140) = *(undefined4 *)(in_ECX + 0x140);
  *(int *)(*(int *)(in_ECX + 0x140) + 8) = *(int *)(in_ECX + 0x140);
  *(undefined4 *)(in_ECX + 0x144) = 0;
  *(undefined4 *)(in_ECX + 0x160) = 0xf;
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  *(undefined1 *)(in_ECX + 0x14c) = 0;
  FUN_00401740(&DAT_00a127c2,0);
  *(undefined4 *)(in_ECX + 0x120) = 4;
  *(undefined4 *)(in_ECX + 0x124) = 4;
  *(undefined4 *)(in_ECX + 0x128) = 4;
  *(undefined4 *)(in_ECX + 300) = 4;
  *(undefined4 *)(in_ECX + 0x164) = 0;
  *(undefined4 *)(in_ECX + 0x134) = 0;
  *(undefined4 *)(in_ECX + 0x138) = 0;
  *(undefined4 *)(in_ECX + 0x10c) = 1;
  return;
}


// ==== FUN_00857bf0 @ 0x00857bf0 ====

void FUN_00857bf0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x49) == '\0') {
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


// ==== FUN_00857c40 @ 0x00857c40 ====

void FUN_00857c40(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x49) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x49) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x49);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x49);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x49) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x49) == '\0');
    if (*(char *)((int)piVar4 + 0x49) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_00857ca0 @ 0x00857ca0 ====

void FUN_00857ca0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a170;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x4c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x12) = 1;
  *(undefined1 *)((int)puVar1 + 0x49) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@00857d2a @ 0x00857d2a ====

void Catch_00857d2a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00857d40 @ 0x00857d40 ====

/* WARNING: Removing unreachable block (ram,0x00857d98) */

undefined4 * FUN_00857d40(int param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)local_8[1] + 0x49) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x14);
    puVar5 = (undefined4 *)local_8[1];
    do {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar8 = (byte *)(param_1 + 4);
      }
      else {
        pbVar8 = *(byte **)(param_1 + 4);
      }
      uVar2 = puVar5[8];
      if (uVar2 == 0) {
LAB_00857dc3:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_00857dd0;
        }
LAB_00857dd2:
        puVar6 = (undefined4 *)puVar5[2];
      }
      else {
        uVar3 = uVar2;
        if (uVar1 <= uVar2) {
          uVar3 = uVar1;
        }
        if ((uint)puVar5[9] < 0x10) {
          pbVar7 = (byte *)(puVar5 + 4);
        }
        else {
          pbVar7 = (byte *)puVar5[4];
        }
        bVar9 = false;
        iVar4 = 0;
        bVar10 = true;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          bVar9 = *pbVar7 < *pbVar8;
          bVar10 = *pbVar7 == *pbVar8;
          pbVar7 = pbVar7 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar10);
        if (!bVar10) {
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        bVar9 = iVar4 < 0;
        if (iVar4 == 0) goto LAB_00857dc3;
LAB_00857dd0:
        if (bVar9) goto LAB_00857dd2;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x49) == '\0');
  }
  return local_8;
}


// ==== FUN_00857e00 @ 0x00857e00 ====

void FUN_00857e00(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_00857d40(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar1 + 0x24) < 0x10) {
      iVar2 = iVar1 + 0x10;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x10);
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),iVar2,*(undefined4 *)(iVar1 + 0x20));
    if (-1 < iVar2) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_00857e70 @ 0x00857e70 ====

void FUN_00857e70(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  in_ECX[1] = param_2;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_4,0,0xffffffff);
  puVar2 = (undefined4 *)(param_4 + 0x1c);
  puVar3 = in_ECX + 10;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)(in_ECX + 0x12) = param_5;
  *(undefined1 *)((int)in_ECX + 0x49) = 0;
  return;
}


// ==== FUN_00857ed0 @ 0x00857ed0 ====

uint FUN_00857ed0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    iVar1 = param_1 + 4;
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(in_ECX + 0x15c),iVar1,*(undefined4 *)(param_1 + 0x14));
  if ((iVar1 == 0) && (*(int *)(in_ECX + 0x164) == param_2)) {
    return 1;
  }
  uVar2 = FUN_00401660(param_1,0,0xffffffff);
  *(int *)(in_ECX + 0x164) = param_2;
  return uVar2 & 0xffffff00;
}


// ==== FUN_00857f40 @ 0x00857f40 ====

void * FUN_00857f40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a180;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x4c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00857e70(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00857fb5 @ 0x00857fb5 ====

void Catch_00857fb5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00857fd0 @ 0x00857fd0 ====

/* WARNING: Removing unreachable block (ram,0x008580e9) */
/* WARNING: Removing unreachable block (ram,0x008580fa) */
/* WARNING: Removing unreachable block (ram,0x00858103) */
/* WARNING: Removing unreachable block (ram,0x00858106) */
/* WARNING: Removing unreachable block (ram,0x008580f6) */
/* WARNING: Removing unreachable block (ram,0x00858114) */
/* WARNING: Removing unreachable block (ram,0x00858121) */
/* WARNING: Removing unreachable block (ram,0x0085812c) */
/* WARNING: Removing unreachable block (ram,0x00858128) */
/* WARNING: Removing unreachable block (ram,0x0085811c) */
/* WARNING: Removing unreachable block (ram,0x0085812f) */

void FUN_00857fd0(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x49) != '\0') {
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
  FUN_00700ad0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x49) == '\0') {
    if (*(char *)(param_2[2] + 0x49) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x49) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x49) == '\0') {
      piVar3 = (int *)FUN_006830e0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x49) == '\0') {
      uVar4 = FUN_00700ab0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0x12] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x12] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x12] == '\0') {
            *(undefined1 *)(piVar5 + 0x12) = 1;
            *(undefined1 *)(piVar3 + 0x12) = 0;
            FUN_00857bf0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x49) == '\0') {
            if ((*(char *)(*piVar5 + 0x48) == '\x01') && (*(char *)(piVar5[2] + 0x48) == '\x01'))
            goto LAB_00858204;
            if (*(char *)(piVar5[2] + 0x48) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x48) = 1;
              *(undefined1 *)(piVar5 + 0x12) = 0;
              FUN_00700b30(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0x12) = (char)piVar3[0x12];
            *(undefined1 *)(piVar3 + 0x12) = 1;
            *(undefined1 *)(piVar5[2] + 0x48) = 1;
            FUN_00857bf0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0x12] == '\0') {
            *(undefined1 *)(piVar5 + 0x12) = 1;
            *(undefined1 *)(piVar3 + 0x12) = 0;
            FUN_00700b30(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x49) == '\0') {
            if ((*(char *)(piVar5[2] + 0x48) != '\x01') || (*(char *)(*piVar5 + 0x48) != '\x01')) {
              if (*(char *)(*piVar5 + 0x48) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x48) = 1;
                *(undefined1 *)(piVar5 + 0x12) = 0;
                FUN_00857bf0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0x12) = (char)piVar3[0x12];
              *(undefined1 *)(piVar3 + 0x12) = 1;
              *(undefined1 *)(*piVar5 + 0x48) = 1;
              FUN_00700b30(piVar3);
              break;
            }
LAB_00858204:
            *(undefined1 *)(piVar5 + 0x12) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x12) = 1;
  }
  if ((uint)param_2[9] < 0x10) {
    param_2[9] = 0xf;
    param_2[8] = 0;
    *(undefined1 *)(param_2 + 4) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[4]);
  return;
}


// ==== FUN_008582b0 @ 0x008582b0 ====

void FUN_008582b0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x49) != '\0') {
    return;
  }
  FUN_008582b0(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_00858310 @ 0x00858310 ====

void FUN_00858310(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x4444442 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00857f40(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x48);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x48) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x12] == '\0') {
LAB_00858415:
        *(undefined1 *)(*piVar5 + 0x48) = 1;
        *(undefined1 *)(piVar6 + 0x12) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x48) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_00857bf0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x48) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x48) = 0;
        FUN_00700b30(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x12] == '\0') goto LAB_00858415;
      if (piVar7 == (int *)*piVar2) {
        FUN_00700b30(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x48) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x48) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x49) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x48);
  } while( true );
}


// ==== FUN_008584f0 @ 0x008584f0 ====

/* WARNING: Removing unreachable block (ram,0x0085854f) */

void FUN_008584f0(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x49) == '\0') {
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
LAB_00858580:
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
        if (uVar5 == 0) goto LAB_00858580;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x49) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_00858310(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00857c40();
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
    puVar6 = (undefined4 *)FUN_00858310(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00858660 @ 0x00858660 ====

void FUN_00858660(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_008582b0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x49) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x49) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x49);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x49);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x49);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x49);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00857fd0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00858720 @ 0x00858720 ====

void FUN_00858720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  return;
}


// ==== FUN_00858730 @ 0x00858730 ====

void FUN_00858730(void)

{
  return;
}


// ==== FUN_00858740 @ 0x00858740 ====

void FUN_00858740(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,8);
    *(undefined1 *)(iVar1 + 0x112) = 0;
  }
  FUN_00855590(0);
  return;
}


// ==== FUN_00858870 @ 0x00858870 ====

void FUN_00858870(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  FUN_00855590(1);
  return;
}


// ==== FUN_008588e0 @ 0x008588e0 ====

void FUN_008588e0(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,8);
    *(undefined1 *)(iVar1 + 0x112) = 0;
  }
  return;
}


// ==== FUN_00858a00 @ 0x00858a00 ====

void FUN_00858a00(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  return;
}


// ==== FUN_00858a60 @ 0x00858a60 ====

void FUN_00858a60(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,8);
    *(undefined1 *)(iVar1 + 0x112) = 0;
  }
  FUN_00855590(0);
  return;
}


// ==== FUN_00858b90 @ 0x00858b90 ====

void FUN_00858b90(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  FUN_00855590(1);
  return;
}


// ==== FUN_00858c00 @ 0x00858c00 ====

void FUN_00858c00(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  FUN_00855590(1);
  return;
}


// ==== FUN_00858ca0 @ 0x00858ca0 ====

void FUN_00858ca0(void)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  FUN_00855590(1);
  return;
}


// ==== FUN_00858d10 @ 0x00858d10 ====

void FUN_00858d10(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,1);
  *(undefined1 *)(iVar1 + 0x74) = 1;
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,8);
    *(undefined1 *)(iVar1 + 0x112) = 0;
  }
  FUN_00855590(0);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
      (*(int *)(iVar1 + 0x11c) != 2)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 5;
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  return;
}


// ==== FUN_00858e60 @ 0x00858e60 ====

void FUN_00858e60(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  FUN_00855590(1);
  return;
}


// ==== FUN_00858f00 @ 0x00858f00 ====

void FUN_00858f00(void)

{
  FUN_00855590(0);
  return;
}


// ==== FUN_00858f10 @ 0x00858f10 ====

void FUN_00858f10(void)

{
  FUN_00855590(1);
  return;
}


// ==== FUN_00858f20 @ 0x00858f20 ====

void FUN_00858f20(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *in_ECX;
  bool bVar4;
  
  *in_ECX = *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x68);
  iVar1 = (**(code **)(*DAT_00b5af74 + 4))();
  bVar4 = *(char *)(iVar1 + 8) != '\0';
  if (bVar4) {
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    iVar2 = (**(code **)(*DAT_00b5af74 + 4))();
    *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(iVar2 + 0xc);
  }
  FUN_00855590(bVar4);
  FUN_0085a370(1,0xffffffff);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar3 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar3 + 0xe4))(piVar3,0x16,2);
  }
  else {
    (**(code **)(*piVar3 + 0xe4))(piVar3,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar3 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar3 + 0x114))(piVar3,1,1,3);
  piVar3 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar3 + 0x114))(piVar3,1,2,3);
  piVar3 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar3 + 0xe4))(piVar3,0xe,1);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  piVar3 = (int *)FUN_0049b670();
  (**(code **)(*piVar3 + 0x114))(piVar3,0,6,1);
  return;
}


// ==== FUN_008590c0 @ 0x008590c0 ====

void FUN_008590c0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *in_ECX;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,1,1,1);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,1,2,1);
  FUN_0085a370(0,0xffffffff);
  *(undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x68) = *in_ECX;
  FUN_00855590(1);
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x1d,0);
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x114))(piVar2,0,6,2);
  return;
}


// ==== FUN_00859160 @ 0x00859160 ====

void FUN_00859160(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,1);
  *(undefined1 *)(iVar1 + 0x74) = 1;
  FUN_0085a370(1,0xffffffff);
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,0);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x104) == '\0') {
    (**(code **)(*piVar2 + 0x114))(piVar2,0,1,3);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0x114))(*(int **)(iVar1 + 0x90),0,2,3);
    FUN_00855590(0);
    return;
  }
  (**(code **)(*piVar2 + 0x114))(piVar2,0,1,4);
  (**(code **)(**(int **)(iVar1 + 0x90) + 0x114))(*(int **)(iVar1 + 0x90),0,2,4);
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x114))(piVar2,0,4,0);
  FUN_00855590(0);
  return;
}


// ==== FUN_00859250 @ 0x00859250 ====

void FUN_00859250(void)

{
  int iVar1;
  int *piVar2;
  
  FUN_00855590(1);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  FUN_0085a370(0,0xffffffff);
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,1);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,0,1,1);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,0,2,1);
  return;
}


// ==== FUN_00859300 @ 0x00859300 ====

void FUN_00859300(void)

{
  int *piVar1;
  int iVar2;
  
  FUN_0085a370(1,0xffffffff);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,0);
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
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
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar1 = *(int **)(iVar2 + 0x90);
  if (*(char *)(iVar2 + 0x7e) == '\0') {
    (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,2);
    *(undefined1 *)(iVar2 + 0x74) = 0;
    return;
  }
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,3);
  *(undefined1 *)(iVar2 + 0x74) = 0;
  return;
}


// ==== FUN_00859430 @ 0x00859430 ====

void FUN_00859430(void)

{
  int *piVar1;
  
  FUN_0085a370(0,0xffffffff);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,1);
  return;
}


// ==== FUN_00859460 @ 0x00859460 ====

void FUN_00859460(void)

{
  int iVar1;
  int *piVar2;
  
  FUN_0085a370(1,0xffffffff);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,1);
  *(undefined1 *)(iVar1 + 0x74) = 1;
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,0);
  FUN_00855590(0);
  return;
}


// ==== FUN_00859590 @ 0x00859590 ====

void FUN_00859590(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,0,1,1);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,0,2,1);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,1,1,1);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,1,2,1);
  FUN_0085a370(0,0xffffffff);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,1);
  FUN_00855590(1);
  return;
}


// ==== FUN_00859670 @ 0x00859670 ====

void FUN_00859670(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,1);
  *(undefined1 *)(iVar1 + 0x74) = 1;
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,2,0);
  return;
}


// ==== FUN_00859770 @ 0x00859770 ====

void FUN_00859770(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,2,2);
  return;
}


// ==== FUN_008597d0 @ 0x008597d0 ====

void FUN_008597d0(char param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == '\0') {
    FUN_0085a370(1,0xffffffff);
  }
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,0);
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar1 = *(int **)(iVar2 + 0x90);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,1);
  *(undefined1 *)(iVar2 + 0x74) = 1;
  return;
}


// ==== FUN_00859830 @ 0x00859830 ====

void FUN_00859830(void)

{
  int *piVar1;
  int iVar2;
  
  FUN_0085a370(0,0xffffffff);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,1);
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar1 = *(int **)(iVar2 + 0x90);
  if (*(char *)(iVar2 + 0x7e) == '\0') {
    (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,2);
    *(undefined1 *)(iVar2 + 0x74) = 0;
    return;
  }
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,3);
  *(undefined1 *)(iVar2 + 0x74) = 0;
  return;
}


// ==== FUN_008598a0 @ 0x008598a0 ====

void FUN_008598a0(char param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != '\0') {
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,0);
  }
  iVar2 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar1 = *(int **)(iVar2 + 0x90);
  if (*(char *)(iVar2 + 0x7e) == '\0') {
    (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,2);
  }
  else {
    (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,3);
  }
  *(undefined1 *)(iVar2 + 0x74) = 0;
  FUN_0085a370(1,0xffffffff);
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x1d,1);
  return;
}


// ==== FUN_00859930 @ 0x00859930 ====

void FUN_00859930(void)

{
  int iVar1;
  int *piVar2;
  
  FUN_0085a370(0,0xffffffff);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,1);
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0x1d,0);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,0,1,1);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,0,2,1);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,1,1,1);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,1,2,1);
  return;
}


// ==== FUN_00859a20 @ 0x00859a20 ====

void FUN_00859a20(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,0);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
      (*(int *)(iVar1 + 0x11c) != 2)) && (*(int *)(iVar1 + 100) == 0)) {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
    *(undefined4 *)(iVar1 + 0x114) = 2;
    *(undefined4 *)(iVar1 + 0x118) = 5;
    *(undefined4 *)(iVar1 + 0x11c) = 2;
  }
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,2,0);
  return;
}


// ==== FUN_00859b20 @ 0x00859b20 ====

void FUN_00859b20(void)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,1);
  piVar1 = (int *)FUN_0049b670();
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,2,2);
  return;
}


// ==== FUN_00859b60 @ 0x00859b60 ====

void FUN_00859b60(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x105) == '\0') {
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
  }
  else {
    if ((((*(int *)(iVar1 + 0x114) != 2) || (*(int *)(iVar1 + 0x118) != 5)) ||
        (*(int *)(iVar1 + 0x11c) != 2)) && (*(int *)(iVar1 + 100) == 0)) {
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x1b,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xf,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x19,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x18,1);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x13,5);
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x14,2);
      *(undefined4 *)(iVar1 + 0x114) = 2;
      *(undefined4 *)(iVar1 + 0x118) = 5;
      *(undefined4 *)(iVar1 + 0x11c) = 2;
    }
    iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
    if ((*(char *)(iVar1 + 0x105) != '\0') && (*(int *)(iVar1 + 0x130) != 4)) {
      *(undefined4 *)(iVar1 + 0x130) = 4;
      (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xab,4);
    }
  }
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,2,0);
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,1,2);
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,4,2);
  return;
}


// ==== FUN_00859e10 @ 0x00859e10 ====

void FUN_00859e10(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if ((*(char *)(iVar1 + 0x105) != '\0') && (*(int *)(iVar1 + 0x130) != 1)) {
    *(undefined4 *)(iVar1 + 0x130) = 1;
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xab,1);
  }
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,2,2);
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,1,4);
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,4,4);
  return;
}


// ==== FUN_00859ee0 @ 0x00859ee0 ====

void FUN_00859ee0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  if (*(char *)(iVar1 + 0x7e) == '\0') {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,2);
  }
  else {
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x16,3);
  }
  *(undefined1 *)(iVar1 + 0x74) = 0;
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,8);
    *(undefined1 *)(iVar1 + 0x112) = 0;
  }
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,1,1,8);
  return;
}


// ==== FUN_0085a050 @ 0x0085a050 ====

void FUN_0085a050(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,1,1,4);
  return;
}


// ==== FUN_0085a0d0 @ 0x0085a0d0 ====

void FUN_0085a0d0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
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
  FUN_00855590(0);
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,1,1,4);
  (**(code **)(*piVar2 + 0x10c))(piVar2,1,4,7);
  return;
}


// ==== FUN_0085a1e0 @ 0x0085a1e0 ====

void FUN_0085a1e0(void)

{
  int *piVar1;
  
  FUN_00855590(1);
  piVar1 = (int *)FUN_0049b670();
  (**(code **)(*piVar1 + 0x10c))(piVar1,1,1,4);
  (**(code **)(*piVar1 + 0x10c))(piVar1,1,4,1);
  return;
}


// ==== FUN_0085a220 @ 0x0085a220 ====

void FUN_0085a220(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\x01') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,1);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,4);
    *(undefined1 *)(iVar1 + 0x112) = 1;
  }
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0xac))(piVar2,0,0,2,0,0x3f800000,0);
  FUN_00855590(0);
  return;
}


// ==== FUN_0085a2b0 @ 0x0085a2b0 ====

void FUN_0085a2b0(void)

{
  int iVar1;
  int *piVar2;
  
  FUN_00855590(0);
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  if (*(char *)(iVar1 + 0x112) != '\0') {
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),7,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0xe,0);
    (**(code **)(**(int **)(iVar1 + 0x90) + 0xe4))(*(int **)(iVar1 + 0x90),0x17,8);
    *(undefined1 *)(iVar1 + 0x112) = 0;
  }
  iVar1 = *(int *)(DAT_00b5ac04 + 0x28);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,0,1,1);
  piVar2 = *(int **)(iVar1 + 0x90);
  (**(code **)(*piVar2 + 0x114))(piVar2,0,2,1);
  piVar2 = (int *)FUN_0049b670();
  (**(code **)(*piVar2 + 0x10c))(piVar2,0,4,4);
  return;
}


// ==== FUN_0085a370 @ 0x0085a370 ====

void FUN_0085a370(char param_1)

{
  char *pcVar1;
  int *piVar2;
  int in_ECX;
  uint unaff_ESI;
  void *pvStack_5c;
  undefined4 uStack_58;
  int *piStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_3c [16];
  uint uStack_2c;
  
  if ((param_1 == '\0') || (*(char *)(in_ECX + 0x7a) == '\0')) {
    piStack_54 = *(int **)(in_ECX + 0x90);
    uStack_4c = 0;
    uStack_50 = 0x1c;
    uStack_58 = 0x85a3ce;
    (**(code **)(*piStack_54 + 0xe4))();
  }
  else {
    piStack_54 = *(int **)(in_ECX + 0x90);
    uStack_4c = 1;
    uStack_50 = 0x1c;
    uStack_58 = 0x85a39c;
    (**(code **)(*piStack_54 + 0xe4))();
    uStack_58 = *(undefined4 *)(DAT_00b5ac04 + 0xa4);
    pvStack_5c = (void *)0x22;
    (**(code **)(**(int **)(in_ECX + 0x90) + 0xe4))(*(int **)(in_ECX + 0x90));
  }
  pcVar1 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
  if (*pcVar1 != '\0') {
    (**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x3c))();
    FUN_00401740(s_Dist____3f___3f__Color____3f___3_00a12e88,0x27);
    FUN_00404230(auStack_3c);
    piStack_54 = (int *)((uint)piStack_54 & 0xffffff00);
    FUN_00401740(s___Fog___00a12e80,7);
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x18))();
    (**(code **)(*piVar2 + 4))(&uStack_58,auStack_3c);
    if (0xf < unaff_ESI) {
      _free(pvStack_5c);
      return;
    }
    if (0xf < uStack_2c) {
      _free((void *)0xf);
      return;
    }
  }
  return;
}


// ==== FUN_0085a4b0 @ 0x0085a4b0 ====

void FUN_0085a4b0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x10))(0);
  (**(code **)(**(int **)(in_ECX + 0x18) + 0x10))(1);
  return;
}


// ==== FUN_0085a4d0 @ 0x0085a4d0 ====

void FUN_0085a4d0(void)

{
  int iVar1;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x77) != '\0') {
    iVar1 = (**(code **)(*DAT_00b5ac00 + 8))();
    if (*(char *)(iVar1 + 9) != '\0') {
      FUN_00882f00();
      return;
    }
  }
  return;
}


// ==== FUN_0085a500 @ 0x0085a500 ====

void FUN_0085a500(void)

{
  int in_ECX;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x77) != '\0') {
    (**(code **)(**(int **)(in_ECX + 4) + 0x10))(0);
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(0);
  }
  return;
}


// ==== FUN_0085a530 @ 0x0085a530 ====

void FUN_0085a530(void)

{
  int in_ECX;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x77) != '\0') {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(0);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x10))(0);
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))(1);
  }
  return;
}


// ==== FUN_0085a570 @ 0x0085a570 ====

void FUN_0085a570(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_00a12f38;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  pvVar1 = operator_new(0xbc);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00883280();
  }
  in_ECX[0x15] = uVar2;
  uVar2 = FUN_008874e0(0);
  in_ECX[1] = uVar2;
  uVar2 = FUN_008874e0(1);
  in_ECX[2] = uVar2;
  uVar2 = FUN_008874e0(2);
  in_ECX[3] = uVar2;
  uVar2 = FUN_008874e0(2);
  in_ECX[4] = uVar2;
  uVar2 = FUN_008874e0(3);
  in_ECX[5] = uVar2;
  uVar2 = FUN_008874e0(3);
  in_ECX[6] = uVar2;
  uVar2 = FUN_00884f10();
  in_ECX[7] = uVar2;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_shadow_mesh_00a12eec,0xb);
  uVar2 = FUN_005b1c00(local_1c);
  in_ECX[0x16] = uVar2;
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0085a650 @ 0x0085a650 ====

undefined4 * FUN_0085a650(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *local_c;
  undefined1 local_8 [8];
  
  puVar1 = (undefined4 *)FUN_0085afb0();
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  puVar1[4] = param_1[4];
  puVar1[5] = param_1[5];
  puVar1[6] = param_1[6];
  puVar1[7] = param_1[7];
  *(undefined1 *)(puVar1 + 0x33) = *(undefined1 *)(param_1 + 9);
  puVar4 = puVar1 + 0x35;
  puVar2 = param_2;
  for (iVar3 = 0x10; puVar2 = puVar2 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar4 = puVar4 + 1;
  }
  puVar1[0x34] = *param_2;
  local_c = puVar1;
  puVar2 = (undefined4 *)FUN_008822f0(local_8,param_1 + 0xd,param_1[0xb]);
  puVar1[0x45] = *puVar2;
  puVar1[0x46] = puVar2[1];
  FUN_00881ee0(puVar1);
  FUN_008820a0();
  iVar3 = *(int *)(in_ECX + 0x44);
  if ((iVar3 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x4c) - iVar3 >> 2) <= (uint)(*(int *)(in_ECX + 0x48) - iVar3 >> 2)))
  {
    FUN_0085b420(*(undefined4 *)(in_ECX + 0x48),1,&local_c);
    return puVar1;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x48);
  *puVar2 = puVar1;
  *(undefined4 **)(in_ECX + 0x48) = puVar2 + 1;
  return puVar1;
}


// ==== FUN_0085a760 @ 0x0085a760 ====

int * FUN_0085a760(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  int *local_14;
  undefined1 local_10 [16];
  
  piVar3 = (int *)FUN_0085b000(0x78);
  iVar1 = *(int *)(in_ECX + 0x24);
  local_14 = piVar3;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x2c) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x28) - iVar1 >> 2)))
  {
    FUN_0085b420(*(undefined4 *)(in_ECX + 0x28),1,&local_14);
  }
  else {
    puVar2 = *(undefined4 **)(in_ECX + 0x28);
    *puVar2 = piVar3;
    *(undefined4 **)(in_ECX + 0x28) = puVar2 + 1;
  }
  *(undefined1 *)(piVar3 + 2) = *(undefined1 *)(param_1 + 8);
  piVar3[1] = *(int *)(param_1 + 0xc);
  piVar4 = (int *)FUN_00881ea0(local_10,*(undefined1 *)(param_2 + 0x25));
  piVar3[4] = *piVar4;
  piVar3[5] = piVar4[1];
  piVar3[6] = piVar4[2];
  piVar3[7] = piVar4[3];
  piVar3[8] = *(int *)(param_1 + 0x10);
  *(undefined1 *)((int)piVar3 + 9) = *(undefined1 *)(param_1 + 0x14);
  piVar3[0x1d] = param_3;
  *(undefined1 *)((int)piVar3 + 10) = *(undefined1 *)(param_2 + 0x23);
  *(undefined1 *)(piVar3 + 3) = *(undefined1 *)(param_2 + 0x22);
  piVar3[9] = *(int *)(param_2 + 0x30);
  *(undefined1 *)((int)piVar3 + 0xb) = *(undefined1 *)(param_2 + 0x26);
  piVar3[10] = *(int *)(param_2 + 0x28);
  piVar3[0xb] = param_4;
  if (*(char *)(param_1 + 0x15) == '\0') {
    *piVar3 = 0;
    FUN_008822a0();
    return piVar3;
  }
  *piVar3 = param_1 + 0x18;
  FUN_008822a0();
  return piVar3;
}


// ==== FUN_0085a870 @ 0x0085a870 ====

undefined4 FUN_0085a870(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
  iVar2 = (int)param_1;
  if (*(char *)(iVar3 + 9) == '\0') {
    return 0;
  }
  if ((*(char *)((int)param_1 + 0x20) == '\x01') &&
     ((*(int *)(param_2 + 0x44) == 1 || (*(int *)(param_2 + 0x44) == 3)))) {
    iVar3 = (**(code **)(*DAT_00b5ac00 + 8))();
    if ((1 < *(byte *)(iVar3 + 9)) || (*(char *)(iVar2 + 0x21) != -0x10)) {
      return 1;
    }
    if (*(int *)(in_ECX + 0x5c) != iVar2) {
      puVar4 = (undefined4 *)FUN_0085b000(0x78);
      param_1 = puVar4;
      FUN_0085b670(&param_1);
      uVar1 = DAT_0099d080;
      *(undefined1 *)(puVar4 + 2) = 0;
      puVar4[1] = 0xffffffff;
      puVar4[8] = uVar1;
      *(undefined1 *)((int)puVar4 + 9) = 0;
      puVar4[0x1d] = param_3;
      *(undefined1 *)((int)puVar4 + 10) = 0;
      *(undefined1 *)(puVar4 + 3) = 0xff;
      *(undefined1 *)((int)puVar4 + 0xb) = 0;
      puVar4[0xb] = 0;
      *puVar4 = 0;
      FUN_008822a0();
      uStack_8 = *(undefined4 *)(in_ECX + 0x58);
      uStack_c = 0;
      uStack_4 = 0;
      FUN_008833c0(0,0,&uStack_c,puVar4);
      *(int *)(in_ECX + 0x5c) = iVar2;
    }
  }
  return 0;
}


// ==== FUN_0085a970 @ 0x0085a970 ====

void FUN_0085a970(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4;
  
  iVar1 = (int)param_2;
  if ((*(char *)((int)param_2 + 0x58) != '\0') &&
     (*(undefined1 **)((int)param_2 + 0x5c) != (undefined1 *)0x0)) {
    local_14 = *param_1;
    local_10 = param_1[1];
    local_c = param_1[3];
    local_8 = param_1[4];
    local_4 = **(undefined1 **)((int)param_2 + 0x5c);
    puVar2 = (undefined4 *)FUN_0085b060(0x20);
    param_2 = puVar2;
    FUN_0085b670(&param_2);
    *puVar2 = param_3;
    puVar2[3] = *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0xc);
    puVar2[2] = *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 4);
    *(undefined1 *)(puVar2 + 1) = *(undefined1 *)(*(int *)(iVar1 + 0x5c) + 8);
    puVar2[4] = *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0x10);
    puVar3 = (undefined4 *)
             FUN_008822f0(local_1c,*(int *)(iVar1 + 0x5c) + 0x14,
                          *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0x1c));
    puVar2[5] = *puVar3;
    puVar2[6] = puVar3[1];
    puVar2[7] = *(undefined4 *)(*(int *)(iVar1 + 0x5c) + 0x20);
    (**(code **)(**(int **)(in_ECX + 0x1c) + 4))(param_4,&local_14,puVar2);
  }
  return;
}


// ==== FUN_0085aa50 @ 0x0085aa50 ====

void FUN_0085aa50(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,char param_5
                 )

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined1 uVar4;
  char cVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int in_ECX;
  int *piVar9;
  undefined4 *puStack_40;
  uint uStack_3c;
  uint auStack_38 [2];
  undefined4 *puStack_30;
  int local_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  undefined1 auStack_18 [8];
  int iStack_10;
  undefined4 uStack_8;
  int iStack_4;
  
  iVar1 = param_4[1];
  piVar9 = (int *)*param_4;
  if (((piVar9 != (int *)0x0) &&
      (local_2c = iVar1, cVar5 = (**(code **)(*piVar9 + 0x2c))(), cVar5 != '\0')) &&
     (cVar5 = FUN_0085b0c0(iVar1), cVar5 != '\0')) {
    puStack_40 = (undefined4 *)piVar9[0x19];
    puStack_28 = (undefined4 *)piVar9[0x1a];
    if (puStack_40 != puStack_28) {
      do {
        puVar2 = (undefined4 *)*puStack_40;
        auStack_38[0] = auStack_38[0] & 0xffffff00;
        uStack_3c = uStack_3c & 0xffffff00;
        uVar4 = 0;
        puStack_30 = puVar2;
        FUN_0085b130(param_4,puVar2,param_1,auStack_18,auStack_38,&uStack_3c);
        uVar6 = FUN_0085af60(param_3,puVar2);
        uVar7 = (**(code **)(*DAT_00b5d990 + 0xc))
                          (uVar6,auStack_38[0],iStack_4,(char)param_4[5],uStack_3c);
        uVar8 = FUN_0085a760(param_4,iStack_10,uStack_8,uVar6);
        if (*(char *)(iStack_10 + 0x23) == '\0') {
          uVar3 = *(uint *)(iStack_4 + 0xc);
          cVar5 = FUN_00881e60(local_2c,puStack_28);
          if ((cVar5 == '\0') && ((uVar3 & 0xff000000) == 0xff000000)) {
            cVar5 = FUN_00881e80(local_2c,puStack_28);
            if (cVar5 == '\0') {
              piVar9 = *(int **)(in_ECX + 4);
            }
            else {
              piVar9 = *(int **)(in_ECX + 8);
            }
            (**(code **)(*piVar9 + 8))(uVar6,uVar7,&local_2c,uVar8);
          }
          else {
            cVar5 = FUN_0084be00(local_2c);
            if (cVar5 == '\0') {
              (**(code **)(**(int **)(in_ECX + 0xc) + 8))(uVar6,uVar7,&local_2c,uVar8);
              uVar4 = 1;
            }
            else {
              (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
              uVar4 = 1;
            }
          }
          FUN_0085a970(auStack_18,param_4,uVar8,uVar6);
        }
        else {
          cVar5 = FUN_0084be00(local_2c);
          if (cVar5 == '\0') {
            (**(code **)(**(int **)(in_ECX + 0x14) + 8))(uVar6,uVar7,&local_2c,uVar8);
          }
          else {
            (**(code **)(**(int **)(in_ECX + 0x18) + 8))();
          }
        }
        puVar2 = puStack_30;
        if (param_5 != '\0') {
          uStack_24 = FUN_00882040(local_2c,puStack_30[1]);
          uStack_1c = *puVar2;
          iStack_20 = *param_4;
          FUN_008833c0(uVar6,uVar4,&uStack_24,uVar8);
        }
        puStack_40 = puStack_40 + 1;
      } while (puStack_40 != puStack_28);
    }
  }
  return;
}


// ==== FUN_0085ac80 @ 0x0085ac80 ====

void FUN_0085ac80(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_0085a650(param_1,param_2);
  uVar2 = FUN_0085a870(param_1,param_2,uVar3);
  iVar1 = *(int *)(param_2 + 0x50);
  for (iVar4 = *(int *)(param_2 + 0x4c); iVar4 != iVar1; iVar4 = iVar4 + 0x60) {
    FUN_0085aa50(param_1,param_2,uVar3,iVar4,uVar2);
  }
  return;
}


// ==== FUN_0085ace0 @ 0x0085ace0 ====

void FUN_0085ace0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int in_ECX;
  int local_8;
  uint local_4;
  
  if (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x77) != '\0') {
    *(undefined4 *)(in_ECX + 0x5c) = 0;
    if (*(int *)(param_1 + 4) == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
    }
    local_4 = 0;
    if (0 < local_8) {
      do {
        iVar2 = *(int *)(param_1 + 4);
        if ((iVar2 == 0) || ((uint)(*(int *)(param_1 + 8) - iVar2 >> 2) <= local_4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        iVar3 = *(int *)(iVar2 + local_4 * 4);
        iVar2 = *(int *)(iVar3 + 0x44);
        iVar4 = *(int *)(iVar3 + 0x40);
        while (iVar2 != iVar4) {
          iVar2 = iVar2 + -0x58;
          FUN_0085ac80(iVar3,iVar2);
        }
        local_4 = local_4 + 1;
      } while ((int)local_4 < local_8);
    }
    puVar5 = (undefined1 *)(**(code **)(**(int **)(DAT_00b5ac04 + 0xd0) + 0x54))();
    uVar1 = *puVar5;
    (**(code **)(**(int **)(in_ECX + 4) + 0x14))(uVar1);
    (**(code **)(**(int **)(in_ECX + 8) + 0x14))(uVar1);
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x14))(uVar1);
  }
  return;
}


// ==== FUN_0085add0 @ 0x0085add0 ====

void FUN_0085add0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0x10) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0x14) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0x18) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0xc))();
  FUN_00882e40();
  FUN_0085b840(in_ECX + 0x40);
  FUN_0085b890(in_ECX + 0x20);
  FUN_0085b8e0(in_ECX + 0x30);
  return;
}


// ==== FUN_0085ae40 @ 0x0085ae40 ====

void FUN_0085ae40(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a12f38;
  FUN_0085add0();
  _Memory = (void *)in_ECX[0x15];
  if (_Memory != (void *)0x0) {
    FUN_008831e0();
    _free(_Memory);
    return;
  }
  in_ECX[0x15] = 0;
  if (in_ECX[0x14] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x14]);
    in_ECX[0x14] = 0;
  }
  if (in_ECX[0x16] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x16]);
    in_ECX[0x16] = 0;
  }
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
  if ((void *)in_ECX[0x11] != (void *)0x0) {
    _free((void *)in_ECX[0x11]);
    return;
  }
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  if ((void *)in_ECX[0xd] != (void *)0x0) {
    _free((void *)in_ECX[0xd]);
    return;
  }
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  if ((void *)in_ECX[9] == (void *)0x0) {
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
    *in_ECX = &PTR_FUN_00a10a18;
    return;
  }
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_0085af60 @ 0x0085af60 ====

int FUN_0085af60(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((*(char *)(param_1 + 0xcc) != '\0') || (*(int *)(param_1 + 0xd0) == 0)) {
    return 0;
  }
  iVar1 = 0;
  for (piVar2 = *(int **)(param_2 + 0x2c); piVar2 != *(int **)(param_2 + 0x30); piVar2 = piVar2 + 9)
  {
    if (iVar1 < *piVar2) {
      iVar1 = *piVar2;
    }
  }
  return iVar1;
}


// ==== FUN_0085afb0 @ 0x0085afb0 ====

void * FUN_0085afb0(void)

{
  void *pvVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) == 0) || (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2 == 0)) {
    pvVar1 = _malloc(0x11c);
    return pvVar1;
  }
  pvVar1 = *(void **)(*(int *)(in_ECX + 0xc) + -4);
  if ((*(int *)(in_ECX + 8) != 0) && (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2 != 0)) {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + -4;
  }
  return pvVar1;
}


// ==== FUN_0085b000 @ 0x0085b000 ====

void * FUN_0085b000(void)

{
  void *pvVar1;
  
  if ((*(int *)(DAT_00b5d998 + 8) == 0) ||
     (*(int *)(DAT_00b5d998 + 0xc) - *(int *)(DAT_00b5d998 + 8) >> 2 == 0)) {
    pvVar1 = _malloc(0x78);
    return pvVar1;
  }
  pvVar1 = *(void **)(*(int *)(DAT_00b5d998 + 0xc) + -4);
  if ((*(int *)(DAT_00b5d998 + 8) != 0) &&
     (*(int *)(DAT_00b5d998 + 0xc) - *(int *)(DAT_00b5d998 + 8) >> 2 != 0)) {
    *(int *)(DAT_00b5d998 + 0xc) = *(int *)(DAT_00b5d998 + 0xc) + -4;
  }
  return pvVar1;
}


// ==== FUN_0085b060 @ 0x0085b060 ====

void * FUN_0085b060(void)

{
  void *pvVar1;
  
  if ((*(int *)(DAT_00b5d994 + 8) == 0) ||
     (*(int *)(DAT_00b5d994 + 0xc) - *(int *)(DAT_00b5d994 + 8) >> 2 == 0)) {
    pvVar1 = _malloc(0x20);
    return pvVar1;
  }
  pvVar1 = *(void **)(*(int *)(DAT_00b5d994 + 0xc) + -4);
  if ((*(int *)(DAT_00b5d994 + 8) != 0) &&
     (*(int *)(DAT_00b5d994 + 0xc) - *(int *)(DAT_00b5d994 + 8) >> 2 != 0)) {
    *(int *)(DAT_00b5d994 + 0xc) = *(int *)(DAT_00b5d994 + 0xc) + -4;
  }
  return pvVar1;
}


// ==== FUN_0085b0c0 @ 0x0085b0c0 ====

uint FUN_0085b0c0(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  if (param_1 != (int *)0x0) {
    cVar1 = (**(code **)(*param_1 + 0x2c))();
    return (uint)(cVar1 != '\0');
  }
  FUN_00401740(s_I_Empty_Unknown_TexturePack_00a12f0a + 2,0x19);
  uVar2 = FUN_00404230(local_1c);
  FUN_00403e50(uVar2);
  if (local_4 < 0x10) {
    return 0;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0085b130 @ 0x0085b130 ====

void FUN_0085b130(int *param_1,int *param_2,int param_3,int *param_4,undefined1 *param_5,
                 undefined1 *param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  void *unaff_EBX;
  undefined1 local_38 [4];
  undefined1 local_34;
  uint uStack_28;
  undefined4 local_24;
  void *local_20;
  undefined1 auStack_1c [12];
  undefined4 uStack_10;
  uint uStack_c;
  
  param_4[3] = *param_1;
  iVar2 = FUN_00882040(param_1[1],param_2[1]);
  *param_4 = iVar2;
  if (iVar2 == 0) {
    local_20 = (void *)0xf;
    local_24 = 0;
    local_34 = 0;
    FUN_00401740(s__Texture__00a12f28,9);
    (**(code **)(*(int *)param_1[1] + 4))();
    FUN_00401740(&DAT_009d5e14,2);
    uVar3 = FUN_00404230(auStack_1c);
    (**(code **)(*DAT_00b5a688 + 8))(local_38,uVar3);
    if (0xf < uStack_c) {
      _free(local_20);
      return;
    }
    uStack_c = 0xf;
    uStack_10 = 0;
    local_20 = (void *)((uint)local_20 & 0xffffff00);
    if (0xf < uStack_28) {
      _free(unaff_EBX);
      return;
    }
    iVar2 = (**(code **)(*DAT_00b5d98c + 0xc))();
    *param_4 = iVar2;
  }
  iVar2 = (**(code **)(*DAT_00b5ac00 + 8))();
  if (*(byte *)(iVar2 + 9) < 3) {
    *(bool *)(param_4 + 5) = 1 < *(byte *)(param_3 + 0x20);
  }
  else {
    if ((*(byte *)(param_3 + 0x20) == 0) || (2 < *(byte *)(param_3 + 0x20))) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    *(undefined1 *)(param_4 + 5) = uVar1;
    if (DAT_009bfa74 < ABS((float)param_2[8] - (float)param_2[5])) {
      *(undefined1 *)(param_4 + 5) = 0;
    }
  }
  param_4[4] = *param_2;
  param_4[1] = 0;
  param_4[2] = 0;
  if (*(char *)(param_3 + 0x26) != '\0') {
    piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
    iVar2 = (**(code **)(*piVar4 + 0x1c))();
    if ((*(int *)(iVar2 + 8) != 0) &&
       (iVar2 = (**(code **)(*DAT_00b5ac00 + 8))(), *(char *)(iVar2 + 3) != '\0')) {
      iVar2 = FUN_00882080(param_1[1],param_2[1]);
      param_4[2] = iVar2;
      if (iVar2 == 0) {
        return;
      }
      *param_6 = 1;
      return;
    }
  }
  if (*(char *)((int)param_1 + 0x59) != '\0') {
    *param_5 = 0;
    iVar2 = (**(code **)(*DAT_00b5d98c + 0x10))();
    param_4[1] = iVar2;
    return;
  }
  iVar2 = FUN_00882060(param_1[1],param_2[1]);
  param_4[1] = iVar2;
  if (((iVar2 != 0) && (iVar2 = (**(code **)(*DAT_00b5ac00 + 8))(), *(char *)(iVar2 + 5) != '\0'))
     && (*(char *)(*(int *)(DAT_00b5ac04 + 0x28) + 0xe9) != '\0')) {
    *param_5 = 1;
  }
  return;
}


// ==== FUN_0085b340 @ 0x0085b340 ====

void FUN_0085b340(void)

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
  FUN_00401740(s_invalid_vector<T>_subscript_0099ca88,0x1b);
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


// ==== FUN_0085b3b0 @ 0x0085b3b0 ====

void FUN_0085b3b0(void)

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
  FUN_00401740(s_vector<T>_too_long_0099c99c,0x12);
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


// ==== FUN_0085b420 @ 0x0085b420 ====

void FUN_0085b420(int param_1,uint param_2,undefined4 *param_3)

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
  undefined4 *unaff_FS_OFFSET;
  undefined8 uVar8;
  undefined1 auStack_2a [18];
  undefined4 local_18;
  undefined1 *local_14;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a190;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_10;
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
    puVar1 = auStack_2a + -0xe;
    if (0x3fffffffU - iVar6 < param_2) {
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
        *unaff_FS_OFFSET = local_10;
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
      *unaff_FS_OFFSET = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005a6d90(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00822d20(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== Catch@0085b581 @ 0x0085b581 ====

void Catch_0085b581(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0085b670 @ 0x0085b670 ====

void FUN_0085b670(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_0085b420(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_0085b6c0 @ 0x0085b6c0 ====

undefined1 FUN_0085b6c0(int *param_1,int *param_2,undefined1 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = param_2;
  iVar3 = DAT_00b5d99c;
  for (piVar5 = param_1; piVar5 != piVar4; piVar5 = piVar5 + 1) {
    param_1 = (int *)*piVar5;
    DAT_00b5d99c = iVar3;
    if (param_1 != (int *)0x0) {
      iVar1 = *(int *)(iVar3 + 8);
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iVar3 + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(iVar3 + 0xc) - iVar1 >> 2))
         ) {
        FUN_0085b420(*(undefined4 *)(iVar3 + 0xc),1,&param_1);
      }
      else {
        piVar2 = *(int **)(iVar3 + 0xc);
        *piVar2 = (int)param_1;
        *(int **)(iVar3 + 0xc) = piVar2 + 1;
      }
    }
    iVar3 = DAT_00b5d99c;
  }
  DAT_00b5d99c = iVar3;
  return param_3;
}


// ==== FUN_0085b740 @ 0x0085b740 ====

undefined1 FUN_0085b740(int *param_1,int *param_2,undefined1 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = param_2;
  iVar3 = DAT_00b5d998;
  for (piVar5 = param_1; piVar5 != piVar4; piVar5 = piVar5 + 1) {
    param_1 = (int *)*piVar5;
    DAT_00b5d998 = iVar3;
    if (param_1 != (int *)0x0) {
      iVar1 = *(int *)(iVar3 + 8);
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iVar3 + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(iVar3 + 0xc) - iVar1 >> 2))
         ) {
        FUN_0085b420(*(undefined4 *)(iVar3 + 0xc),1,&param_1);
      }
      else {
        piVar2 = *(int **)(iVar3 + 0xc);
        *piVar2 = (int)param_1;
        *(int **)(iVar3 + 0xc) = piVar2 + 1;
      }
    }
    iVar3 = DAT_00b5d998;
  }
  DAT_00b5d998 = iVar3;
  return param_3;
}


// ==== FUN_0085b7c0 @ 0x0085b7c0 ====

undefined1 FUN_0085b7c0(int *param_1,int *param_2,undefined1 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = param_2;
  iVar3 = DAT_00b5d994;
  for (piVar5 = param_1; piVar5 != piVar4; piVar5 = piVar5 + 1) {
    param_1 = (int *)*piVar5;
    DAT_00b5d994 = iVar3;
    if (param_1 != (int *)0x0) {
      iVar1 = *(int *)(iVar3 + 8);
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(iVar3 + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(iVar3 + 0xc) - iVar1 >> 2))
         ) {
        FUN_0085b420(*(undefined4 *)(iVar3 + 0xc),1,&param_1);
      }
      else {
        piVar2 = *(int **)(iVar3 + 0xc);
        *piVar2 = (int)param_1;
        *(int **)(iVar3 + 0xc) = piVar2 + 1;
      }
    }
    iVar3 = DAT_00b5d994;
  }
  DAT_00b5d994 = iVar3;
  return param_3;
}


// ==== FUN_0085b840 @ 0x0085b840 ====

void FUN_0085b840(int param_1)

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
      FUN_0085b6c0(iVar2,*piVar1,param_1);
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


// ==== FUN_0085b890 @ 0x0085b890 ====

void FUN_0085b890(int param_1)

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
      FUN_0085b740(iVar2,*piVar1,param_1);
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


// ==== FUN_0085b8e0 @ 0x0085b8e0 ====

void FUN_0085b8e0(int param_1)

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
      FUN_0085b7c0(iVar2,*piVar1,param_1);
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


// ==== FUN_0085b930 @ 0x0085b930 ====

void FUN_0085b930(byte param_1)

{
  void *in_ECX;
  
  FUN_0085ae40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0085b950 @ 0x0085b950 ====

void FUN_0085b950(void)

{
  return;
}


// ==== FUN_0085b960 @ 0x0085b960 ====

void FUN_0085b960(void)

{
  return;
}


// ==== FUN_0085b970 @ 0x0085b970 ====

void FUN_0085b970(float *param_1,float param_2)

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
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  pfVar1 = param_1 + 3;
  fVar15 = DAT_0099d0b4 - param_2 * DAT_0099d0b4;
  fVar2 = *pfVar1;
  fVar14 = param_2 * DAT_0099d0b4 + DAT_0099d0b4;
  fVar3 = *pfVar1;
  fVar4 = param_1[4];
  fVar5 = param_1[4];
  fVar6 = param_1[5];
  fVar7 = param_1[5];
  fVar8 = *param_1;
  fVar9 = *param_1;
  fVar10 = param_1[1];
  fVar11 = param_1[1];
  fVar12 = param_1[2];
  fVar13 = param_1[2];
  *param_1 = (param_1[9] - *param_1) * fVar15 + *param_1;
  param_1[1] = (param_1[10] - param_1[1]) * fVar15 + param_1[1];
  param_1[2] = (param_1[0xb] - param_1[2]) * fVar15 + param_1[2];
  *pfVar1 = (param_1[6] - param_1[3]) * fVar15 + *pfVar1;
  param_1[4] = (param_1[7] - param_1[4]) * fVar15 + param_1[4];
  param_1[5] = (param_1[8] - param_1[5]) * fVar15 + param_1[5];
  param_1[6] = (param_1[6] - fVar2) * fVar14 + fVar3;
  param_1[7] = (param_1[7] - fVar4) * fVar14 + fVar5;
  param_1[8] = (param_1[8] - fVar6) * fVar14 + fVar7;
  param_1[9] = (param_1[9] - fVar8) * fVar14 + fVar9;
  param_1[10] = (param_1[10] - fVar10) * fVar14 + fVar11;
  param_1[0xb] = (param_1[0xb] - fVar12) * fVar14 + fVar13;
  return;
}


// ==== FUN_0085bb20 @ 0x0085bb20 ====

void FUN_0085bb20(int param_1)

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


// ==== FUN_0085bcb0 @ 0x0085bcb0 ====

undefined4 FUN_0085bcb0(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x18;
  }
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar3 * 0x18;
  cVar2 = FUN_00881000(0x18,iVar3);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(0x18,iVar3);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar4 = (**(code **)(*piVar1 + 0x1c))(0x18,iVar3);
  (**(code **)(*piVar1 + 0x14))(iVar3,*(undefined4 *)(param_1 + 4));
  FUN_00881060();
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x18)
  ;
  return uVar4;
}


// ==== FUN_0085bd70 @ 0x0085bd70 ====

undefined4 FUN_0085bd70(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 1;
  }
  iVar2 = iVar2 * 2;
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    (**(code **)(*piVar1 + 0x10))();
  }
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x20))(iVar2);
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x18) - iVar2 >> 1;
  }
  (**(code **)(*piVar1 + 0x18))(iVar4,iVar2);
  FUN_00881080();
  return uVar3;
}


// ==== FUN_0085be30 @ 0x0085be30 ====

void FUN_0085be30(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EDI;
  uint uVar5;
  
  uVar2 = FUN_0085bcb0(param_2);
  uVar3 = FUN_0085bd70(param_2);
  if ((*(int *)(param_2 + 0x14) != 0) &&
     (2 < (uint)(*(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 1))) {
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 400))
              (piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x18);
    FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
    (**(code **)(**(int **)(unaff_EDI + 0x1c) + 0x10c))(*(int **)(unaff_EDI + 0x1c));
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 1;
    }
    if (*(int *)(param_2 + 4) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x18;
    }
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 0x148))(piVar1,4,uVar2,0,iVar4,uVar3,uVar5 / 3);
  }
  return;
}


// ==== FUN_0085bf20 @ 0x0085bf20 ====

void FUN_0085bf20(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 0x48);
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x1f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x98))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x78),local_40);
  return;
}


// ==== FUN_0085bf80 @ 0x0085bf80 ====

void FUN_0085bf80(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x1f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x98))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x78),local_40);
  return;
}


// ==== FUN_0085bfe0 @ 0x0085bfe0 ====

void FUN_0085bfe0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uStack_84;
  undefined4 *puStack_80;
  float fStack_7c;
  undefined4 local_68;
  float local_64;
  undefined1 auStack_60 [16];
  undefined4 auStack_50 [20];
  
  iVar1 = *(int *)(param_1 + 0x28);
  local_64 = DAT_0099d0dc / (*(float *)(DAT_00b5ac04 + 0xa8) * DAT_009b6df8);
  local_68 = *(undefined4 *)(DAT_00b5ac04 + 0x9c);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x22)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_84 = *(undefined4 *)(iVar1 + 0x84);
  fStack_7c = 2.8026e-45;
  puStack_80 = &local_68;
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))(*(int **)(param_1 + 0x1c));
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar3 = auStack_50;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00862b50(auStack_60 + -0xc);
  thunk_FUN_0079e43e(auStack_60,auStack_60 + -0xc,auStack_50);
  iVar1 = *(int *)(param_1 + 0x28);
  puStack_80 = (undefined4 *)local_68;
  fStack_7c = local_64;
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x23)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x88),&uStack_84,3);
  return;
}


// ==== FUN_0085c100 @ 0x0085c100 ====

void FUN_0085c100(float *param_1,int param_2)

{
  short *psVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  undefined4 ***unaff_ESI;
  float *pfVar5;
  undefined4 ***pppuVar6;
  short sVar7;
  undefined4 *****pppppuVar8;
  float10 fVar9;
  float fVar10;
  float fVar11;
  undefined4 *****pppppuVar12;
  undefined4 *****pppppuStack_128;
  undefined4 ***pppuStack_124;
  undefined4 *****pppppuStack_120;
  undefined4 *****local_11c;
  undefined4 local_108;
  undefined4 *****local_104;
  undefined4 *****local_100;
  undefined4 *****local_fc;
  undefined4 ***local_f8;
  undefined4 *****local_f4;
  undefined4 *****local_f0;
  undefined4 ****local_ec;
  undefined4 ****ppppuStack_e8;
  float fStack_e4;
  undefined4 ***local_e0;
  undefined4 *****local_dc;
  undefined4 *****local_d8;
  undefined4 *****local_d4;
  undefined4 ****ppppuStack_d0;
  float local_cc;
  undefined4 ***local_c8;
  undefined4 *****local_c4;
  undefined4 *****local_c0;
  undefined4 ***local_bc;
  undefined4 *****local_b8;
  undefined4 *****local_b4;
  undefined4 ***local_b0;
  undefined4 *****local_ac;
  undefined4 *****local_a8;
  undefined4 ***local_a4;
  undefined4 *****local_a0;
  undefined4 *****local_9c;
  undefined4 *****local_98;
  float local_94;
  undefined4 **local_90;
  undefined4 *****apppppuStack_8c [16];
  float afStack_4c [3];
  undefined4 ***local_40 [16];
  
  local_94 = param_1[4] * (float)DAT_0099d0b4;
  local_fc = (undefined4 *****)(param_1[5] * (float)DAT_0099d0b4);
  local_98 = local_fc;
  local_cc = 0.0;
  if (param_1[7] != 0.0) {
    local_11c = (undefined4 *****)param_1[7];
    pppppuStack_120 = (undefined4 *****)0x85c167;
    fVar9 = (float10)FUN_0040d4d0();
    pppppuStack_120 = (undefined4 *****)param_1[7];
    local_98 = (undefined4 *****)(float)(fVar9 * (float10)(float)local_fc);
    pppuStack_124 = (undefined4 ***)0x85c17b;
    fVar9 = (float10)FUN_0040d4c0();
    local_cc = (float)(fVar9 * (float10)(float)local_fc);
  }
  fVar10 = param_1[8];
  pppuVar6 = (undefined4 ***)*param_1;
  pppppuVar8 = (undefined4 *****)param_1[1];
  pppppuVar12 = (undefined4 *****)param_1[2];
  local_e0 = pppuVar6;
  local_dc = pppppuVar8;
  local_d8 = pppppuVar12;
  if (fVar10 == 2.8026e-45) {
    local_c8 = (undefined4 ***)(((float)pppuVar6 - (float)local_98) + local_cc);
    local_c4 = pppppuVar8;
    local_c0 = (undefined4 *****)(((float)pppppuVar12 - local_cc) - (float)local_98);
    local_bc = (undefined4 ***)(((float)pppuVar6 - (float)local_98) - local_cc);
    local_b8 = pppppuVar8;
    local_b4 = (undefined4 *****)(((float)pppppuVar12 - local_cc) + (float)local_98);
    local_108 = (undefined4 ***)((float)pppuVar6 + local_cc + (float)local_98);
    local_100 = (undefined4 *****)(((float)pppppuVar12 + local_cc) - (float)local_98);
    local_b0 = (undefined4 ***)(((float)pppuVar6 + (float)local_98) - local_cc);
    local_ac = pppppuVar8;
    local_a8 = (undefined4 *****)((float)pppppuVar12 + local_cc + (float)local_98);
    local_104 = pppppuVar8;
    local_a4 = local_108;
    local_a0 = pppppuVar8;
    local_9c = local_100;
  }
  else {
    if (fVar10 == 0.0) {
      iVar2 = *(int *)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
      local_f8 = *(undefined4 ****)(iVar2 + 0xc);
      local_f4 = *(undefined4 ******)(iVar2 + 0x10);
      local_f0 = *(undefined4 ******)(iVar2 + 0x14);
      local_108 = (undefined4 ***)((float)local_f0 - (float)pppppuVar12);
      pppppuStack_120 = (undefined4 *****)&local_108;
      local_104 = (undefined4 *****)0x0;
      local_100 = (undefined4 *****)((float)pppuVar6 - (float)local_f8);
      pppuStack_124 = (undefined4 ***)0x85c323;
      local_11c = pppppuStack_120;
      thunk_FUN_0079e1ba();
      fVar10 = (float)local_108 * local_94;
      local_f4 = (undefined4 *****)((float)local_104 * local_94);
      fVar11 = (float)local_100 * local_94;
      local_f8 = (undefined4 ***)(fVar10 + (float)local_e0);
      local_f0 = (undefined4 *****)(fVar11 + (float)local_d8);
      local_c8 = (undefined4 ***)(fVar10 + (float)local_e0);
      local_c4 = (undefined4 *****)(((float)local_f4 + (float)local_dc) - (float)local_fc);
      local_c0 = (undefined4 *****)(fVar11 + (float)local_d8);
      local_bc = local_f8;
      local_b8 = (undefined4 *****)((float)local_f4 + (float)local_dc + (float)local_fc);
      local_b4 = local_f0;
      local_a8 = (undefined4 *****)((float)local_d8 - fVar11);
      local_ac = (undefined4 *****)(((float)local_dc - (float)local_f4) + (float)local_fc);
      local_100 = (undefined4 *****)((float)local_d8 - fVar11);
      local_108 = (undefined4 ***)((float)local_e0 - fVar10);
      local_104 = (undefined4 *****)(((float)local_dc - (float)local_f4) - (float)local_fc);
    }
    else {
      if (fVar10 != 1.4013e-45) goto LAB_0085c59d;
      local_c4 = (undefined4 *****)(((float)pppppuVar8 - local_cc) - (float)local_98);
      local_ac = (undefined4 *****)((float)pppppuVar8 + local_cc + (float)local_98);
      local_c8 = pppuVar6;
      local_c0 = (undefined4 *****)(((float)pppppuVar12 - (float)local_98) + local_cc);
      local_a8 = (undefined4 *****)(((float)pppppuVar12 + (float)local_98) - local_cc);
      local_bc = pppuVar6;
      local_b8 = (undefined4 *****)(((float)pppppuVar8 - local_cc) + (float)local_98);
      local_b4 = (undefined4 *****)(((float)pppppuVar12 - (float)local_98) - local_cc);
      local_100 = (undefined4 *****)((float)pppppuVar12 + local_cc + (float)local_98);
      local_108 = pppuVar6;
      local_104 = (undefined4 *****)(((float)pppppuVar8 + local_cc) - (float)local_98);
    }
    local_b0 = local_108;
    local_a4 = local_108;
    local_a0 = local_104;
    local_9c = local_100;
    local_c8 = local_bc;
  }
LAB_0085c59d:
  if (param_1[8] == 4.2039e-45) {
    if (*(char *)(param_1 + 10) == '\0') {
      local_f8 = local_e0;
      local_f0 = local_d8;
      local_ec = DAT_0099d080;
      local_11c = (undefined4 *****)(*(int *)(DAT_00b5ac04 + 0x78) + 8);
      pppppuStack_120 = (undefined4 *****)&local_f8;
      pppuStack_124 = &local_90;
      pppppuStack_128 = (undefined4 *****)0x85c731;
      local_f4 = local_dc;
      thunk_FUN_0079ebf5();
      local_c8 = (undefined4 ***)(((float)local_90 - (float)local_98) + local_cc);
      local_bc = (undefined4 ***)(((float)local_90 - (float)local_98) - local_cc);
      local_c4 = (undefined4 *****)(((float)apppppuStack_8c[0] - local_cc) - (float)local_98);
      local_b0 = (undefined4 ***)(((float)local_90 + (float)local_98) - local_cc);
      local_b8 = (undefined4 *****)(((float)apppppuStack_8c[0] - local_cc) + (float)local_98);
      local_c0 = apppppuStack_8c[1];
      local_b4 = apppppuStack_8c[1];
      local_ac = (undefined4 *****)((float)apppppuStack_8c[0] + local_cc + (float)local_98);
      local_108 = (undefined4 ***)((float)local_90 + local_cc + (float)local_98);
      local_104 = (undefined4 *****)(((float)apppppuStack_8c[0] + local_cc) - (float)local_98);
      local_a8 = apppppuStack_8c[1];
      local_100 = apppppuStack_8c[1];
      local_9c = apppppuStack_8c[1];
      local_a4 = local_108;
      local_a0 = local_104;
    }
    else {
      pppppuStack_128 = (undefined4 *****)(afStack_4c + 3);
      pppuStack_124 = pppuVar6;
      pppppuStack_120 = pppppuVar8;
      local_11c = pppppuVar12;
      thunk_FUN_0079f7f5();
      local_11c = apppppuStack_8c + 3;
      pppppuStack_120 = (undefined4 *****)(param_1 + 0xb);
      pfVar5 = afStack_4c + 3;
      pppppuVar8 = apppppuStack_8c + 3;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pppppuVar8 = (undefined4 ****)*pfVar5;
        pfVar5 = pfVar5 + 1;
        pppppuVar8 = pppppuVar8 + 1;
      }
      pppuStack_124 = (undefined4 ***)(afStack_4c + 3);
      pppppuStack_128 = (undefined4 *****)0x85c5ef;
      thunk_FUN_0079ee7b();
      pppppuStack_128 = apppppuStack_8c;
      pppppuVar12 = &local_104;
      pfVar5 = afStack_4c;
      pppppuVar8 = apppppuStack_8c;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pppppuVar8 = (undefined4 ****)*pfVar5;
        pfVar5 = pfVar5 + 1;
        pppppuVar8 = pppppuVar8 + 1;
      }
      local_104 = (undefined4 *****)(0.0 - (float)local_108);
      local_100 = (undefined4 *****)0x0;
      local_fc = local_104;
      local_d8 = local_104;
      thunk_FUN_0079e5a0(&local_d4,pppppuVar12);
      local_108 = unaff_ESI;
      thunk_FUN_0079e5a0(&local_d4,(int)register0x00000010 + -0x110,&local_98);
      local_11c = pppppuStack_120;
      thunk_FUN_0079e5a0(&local_d4,&local_11c,&local_a4);
      pppuStack_124 = (undefined4 ***)0x0;
      pppppuStack_120 = local_fc;
      pppppuStack_128 = pppppuVar12;
      thunk_FUN_0079e5a0(&local_d4,&pppppuStack_128,&local_b0);
    }
  }
  else if (*(char *)(param_1 + 10) != '\0') {
    iVar2 = 4;
    pppuVar6 = &local_c8;
    while( true ) {
      local_108 = (undefined4 ***)((float)*pppuVar6 - (float)local_e0);
      local_104 = (undefined4 *****)((float)pppuVar6[1] - (float)local_dc);
      local_100 = (undefined4 *****)((float)pppuVar6[2] - (float)local_d8);
      *pppuVar6 = (undefined4 ***)((float)*pppuVar6 - (float)local_e0);
      pppuVar6[1] = (undefined4 *****)((float)pppuVar6[1] - (float)local_dc);
      pppuVar6[2] = local_100;
      pppppuStack_128 = (undefined4 *****)0x85c8be;
      pppuStack_124 = pppuVar6;
      pppppuStack_120 = (undefined4 *****)pppuVar6;
      local_11c = (undefined4 *****)(param_1 + 0xb);
      thunk_FUN_0079e5a0();
      local_f8 = (undefined4 ***)((float)*pppuVar6 + (float)local_e0);
      local_f4 = (undefined4 *****)((float)pppuVar6[1] + (float)local_dc);
      local_f0 = (undefined4 *****)((float)pppuVar6[2] + (float)local_d8);
      *pppuVar6 = local_f8;
      pppuVar6[1] = local_f4;
      iVar2 = iVar2 + -1;
      pppuVar6[2] = local_f0;
      pppppuVar8 = (undefined4 *****)0x0;
      if (iVar2 == 0) break;
      pppuVar6 = pppuVar6 + 3;
    }
  }
  if ((local_94 != (float)local_fc) && (param_1[8] != 0.0)) {
    local_11c = (undefined4 *****)(local_94 / (float)local_fc);
    pppppuStack_120 = (undefined4 *****)&local_c8;
    pppuStack_124 = (undefined4 ***)0x85c948;
    FUN_0085b970();
  }
  if (*(int *)(param_2 + 4) == 0) {
    sVar3 = 0;
  }
  else {
    sVar3 = (short)((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x18);
  }
  fStack_e4 = param_1[6];
  local_d4 = (undefined4 *****)0x0;
  local_f4 = local_c4;
  ppppuStack_d0 = DAT_0099d080;
  local_f0 = local_c0;
  local_f8 = local_c8;
  local_11c = (undefined4 *****)&local_f8;
  ppppuStack_e8 = DAT_0099d080;
  local_ec = (undefined4 ****)0x0;
  pppppuStack_120 = (undefined4 *****)0x85c9c2;
  FUN_0085e470();
  local_f8 = (undefined4 ***)
             (((float)local_b0 - (float)local_bc) * (float)DAT_0099d0b4 + (float)local_bc);
  local_f4 = (undefined4 *****)
             (((float)local_ac - (float)local_b8) * (float)DAT_0099d0b4 + (float)local_b8);
  local_d4 = (undefined4 *****)DAT_0099d0b4;
  ppppuStack_d0 = (undefined4 ****)0x0;
  local_11c = (undefined4 *****)&local_f8;
  ppppuStack_e8 = (undefined4 ****)0x0;
  local_f0 = (undefined4 *****)
             (((float)local_a8 - (float)local_b4) * (float)DAT_0099d0b4 + (float)local_b4);
  local_ec = DAT_0099d0b4;
  pppppuStack_120 = (undefined4 *****)0x85ca4f;
  FUN_0085e470();
  local_f4 = local_a0;
  ppppuStack_d0 = DAT_0099d080;
  local_f0 = local_9c;
  local_f8 = local_a4;
  local_d4 = (undefined4 *****)DAT_0099d080;
  local_11c = (undefined4 *****)&local_f8;
  ppppuStack_e8 = DAT_0099d080;
  local_ec = DAT_0099d080;
  pppppuStack_120 = (undefined4 *****)0x85ca97;
  FUN_0085e470();
  uVar4 = 0;
  local_108 = (undefined4 ***)0x10000;
  local_104 = (undefined4 *****)0x20002;
  local_100 = (undefined4 *****)0x1;
  do {
    iVar2 = *(int *)(param_2 + 0x14);
    sVar7 = *(short *)((int)&local_108 + uVar4 * 2) + sVar3;
    pppppuVar8 = (undefined4 *****)CONCAT22((short)((uint)pppppuVar8 >> 0x10),sVar7);
    if ((iVar2 == 0) ||
       ((uint)(*(int *)(param_2 + 0x1c) - iVar2 >> 1) <=
        (uint)(*(int *)(param_2 + 0x18) - iVar2 >> 1))) {
      pppuStack_124 = *(undefined4 ****)(param_2 + 0x18);
      local_11c = &local_d4;
      pppppuStack_120 = (undefined4 *****)0x1;
      pppppuStack_128 = (undefined4 *****)0x85cb11;
      local_d4 = pppppuVar8;
      FUN_00427290();
    }
    else {
      psVar1 = *(short **)(param_2 + 0x18);
      *psVar1 = sVar7;
      *(short **)(param_2 + 0x18) = psVar1 + 1;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 3);
  return;
}


// ==== FUN_0085cb30 @ 0x0085cb30 ====

void FUN_0085cb30(undefined4 param_1,int param_2,char param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int *piVar11;
  int iVar12;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  int local_8;
  uint local_4;
  
  if (param_3 == '\0') {
    FUN_0085bf20(param_1);
  }
  else {
    FUN_0085bf80(param_1);
  }
  puVar2 = *(undefined4 **)(param_2 + 4);
  puVar3 = (undefined4 *)*puVar2;
  _param_3 = 0;
  do {
    if (puVar3 == puVar2) {
      return;
    }
    iVar12 = puVar3[3];
    iVar4 = puVar3[4];
    if (_param_3 != iVar12) {
      iVar5 = *(int *)(*(int *)(DAT_00b5ac04 + 0x2c) + 4);
      if ((iVar5 == 0) || ((uint)(*(int *)(*(int *)(DAT_00b5ac04 + 0x2c) + 8) - iVar5 >> 2) < 8)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      iVar5 = *(int *)(iVar5 + 0x1c);
      if (iVar5 == 0) {
        local_4 = 0xf;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        local_8 = iVar5;
        FUN_00401740(s_I_pFxShader_00a12fe6 + 2,9);
        FUN_00406880(local_1c);
        if (local_4 < 0x10) {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          pcVar8 = (code *)swi(3);
          (*pcVar8)();
          return;
        }
        _free(local_18);
        return;
      }
      uVar10 = 0;
      if (iVar12 != 0) {
        piVar11 = (int *)FUN_004af750();
        uVar10 = (**(code **)(*piVar11 + 4))();
      }
      iVar6 = *(int *)(iVar5 + 0x28);
      if ((iVar6 == 0) || ((uint)(*(int *)(iVar5 + 0x2c) - iVar6 >> 2) < 0x21)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0xd0))
                (*(int **)(iVar5 + 0x1c),*(undefined4 *)(iVar6 + 0x80),uVar10);
      _param_3 = iVar12;
    }
    FUN_0085be30(param_1,iVar4);
    if (*(int *)(iVar4 + 0x14) == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = *(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 0x14) >> 1;
    }
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + iVar12;
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar7 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar7 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar7 + 0x15);
        puVar3 = puVar7;
        puVar7 = (undefined4 *)*puVar7;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x15);
          puVar3 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar9 = (undefined4 *)puVar3[1];
        puVar7 = puVar3;
        while ((puVar3 = puVar9, cVar1 == '\0' && (puVar7 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar9 = (undefined4 *)puVar3[1];
          puVar7 = puVar3;
        }
      }
    }
  } while( true );
}


// ==== FUN_0085cd10 @ 0x0085cd10 ====

void FUN_0085cd10(void)

{
  int in_ECX;
  
  FUN_0085e500();
  DAT_00b5d9a0 = 0;
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0085cd50 @ 0x0085cd50 ====

void * FUN_0085cd50(void)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  int iVar3;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = *(int *)(in_ECX + 8);
    iVar3 = iVar1 - *(int *)(in_ECX + 4) >> 2;
    if (iVar3 != 0) {
      pvVar2 = *(void **)(iVar1 + -4);
      if (iVar3 != 0) {
        *(int *)(in_ECX + 8) = iVar1 + -4;
      }
      return pvVar2;
    }
  }
  pvVar2 = operator_new(0x20);
  if (pvVar2 == (void *)0x0) {
    return (void *)0x0;
  }
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  *(undefined4 *)((int)pvVar2 + 0x14) = 0;
  *(undefined4 *)((int)pvVar2 + 0x18) = 0;
  *(undefined4 *)((int)pvVar2 + 0x1c) = 0;
  FUN_0085de00(0x80);
  FUN_004271c0(0x100);
  return pvVar2;
}


// ==== FUN_0085cdc0 @ 0x0085cdc0 ====

undefined4 * FUN_0085cdc0(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined4 *puVar3;
  int iVar4;
  
  *in_ECX = &PTR_FUN_00a13008;
  puVar3 = in_ECX + 1;
  iVar4 = 2;
  do {
    iVar1 = FUN_0085d730();
    puVar3[1] = iVar1;
    *(undefined1 *)(iVar1 + 0x15) = 1;
    *(undefined4 *)(puVar3[1] + 4) = puVar3[1];
    *(undefined4 *)puVar3[1] = puVar3[1];
    *(undefined4 *)(puVar3[1] + 8) = puVar3[1];
    puVar3[2] = 0;
    puVar3 = puVar3 + 3;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar3 = in_ECX + 7;
  iVar4 = 2;
  do {
    iVar1 = FUN_0085d730();
    puVar3[1] = iVar1;
    *(undefined1 *)(iVar1 + 0x15) = 1;
    *(undefined4 *)(puVar3[1] + 4) = puVar3[1];
    *(undefined4 *)puVar3[1] = puVar3[1];
    *(undefined4 *)(puVar3[1] + 8) = puVar3[1];
    puVar3[2] = 0;
    puVar3 = puVar3 + 3;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (DAT_00b5d9a0 == (void *)0x0) {
    pvVar2 = operator_new(0x10);
    if (pvVar2 != (void *)0x0) {
      *(undefined4 *)((int)pvVar2 + 4) = 0;
      *(undefined4 *)((int)pvVar2 + 8) = 0;
      *(undefined4 *)((int)pvVar2 + 0xc) = 0;
      DAT_00b5d9a0 = pvVar2;
    }
  }
  return in_ECX;
}


// ==== FUN_0085ce70 @ 0x0085ce70 ====

void FUN_0085ce70(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  iVar1 = param_2;
  FUN_0079bba0(&param_2,(undefined4 *)(param_1 + 0xc));
  if (param_2 == *(int *)(iVar1 + 4)) {
    uVar2 = FUN_0085cd50();
    local_10 = *(undefined4 *)(param_1 + 0xc);
    local_c = uVar2;
    FUN_0085df10(local_8,&local_10);
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0x10);
  }
  FUN_0085c100(param_1,uVar2);
  return;
}


// ==== FUN_0085cee0 @ 0x0085cee0 ====

void FUN_0085cee0(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piStack_64;
  undefined4 *puStack_60;
  int iStack_5c;
  int *piStack_58;
  char *pcStack_54;
  int *piStack_50;
  undefined4 uStack_4c;
  uint uStack_38;
  
  if ((*(int *)(in_ECX + 0x30) != 0) || (*(int *)(in_ECX + 0x18) != 0)) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    uStack_4c = (void *)0x0;
    piStack_50 = (int *)0x85cf0b;
    FUN_008597d0();
    uStack_4c = (void *)0x7;
    piStack_50 = (int *)0x85cf1b;
    iVar1 = FUN_0085e3a0();
    uStack_4c = *(void **)(iVar1 + 0x20);
    piStack_50 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    pcStack_54 = (char *)0x85cf39;
    (**(code **)(*piStack_50 + 0x15c))();
    piStack_58 = *(int **)(iVar1 + 0x1c);
    pcStack_54 = s_Billboard_00a12f88;
    iStack_5c = 0x85cf4a;
    (**(code **)(*piStack_58 + 0xf0))();
    puStack_60 = (undefined4 *)0x85cf52;
    iStack_5c = iVar1;
    FUN_0085bfe0();
    piStack_64 = *(int **)(iVar1 + 0x1c);
    iStack_5c = 0;
    puStack_60 = &uStack_4c;
    (**(code **)(*piStack_64 + 0x104))();
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x108))(*(int **)(iVar1 + 0x1c));
    if ((*(int *)(in_ECX + 0x30) != 0) || (*(int *)(in_ECX + 0x18) != 0)) {
      FUN_0085bb20(1);
      FUN_0085cb30(iVar1,in_ECX + 0x28,0);
      FUN_0085cb30(iVar1,in_ECX + 0x10,1);
    }
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x110))(*(int **)(iVar1 + 0x1c));
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x114))(*(int **)(iVar1 + 0x1c));
    FUN_00859830(0);
    pcVar2 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
    if (*pcVar2 != '\0') {
      uStack_4c = (void *)0xf;
      piStack_50 = (int *)0x0;
      puStack_60 = (undefined4 *)((uint)puStack_60 & 0xffffff00);
      FUN_00401740(s__R_Sprite_Tri_count_00a12f98,0x13);
      FUN_00401740(&DAT_00a12f94,2);
      uVar3 = FUN_00404230((int)register0x00000010 + -0x48);
      (**(code **)(*DAT_00b5a688 + 8))(&piStack_64,uVar3);
      if (0xf < uStack_38) {
        _free(uStack_4c);
        return;
      }
      uStack_4c = (void *)((uint)uStack_4c & 0xffffff00);
      if ((char *)0xf < pcStack_54) {
        _free((void *)0x0);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0085d080 @ 0x0085d080 ====

void FUN_0085d080(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piStack_64;
  undefined4 *puStack_60;
  int iStack_5c;
  int *piStack_58;
  char *pcStack_54;
  int *piStack_50;
  undefined4 uStack_4c;
  uint uStack_38;
  
  if ((*(int *)(in_ECX + 0x24) != 0) || (*(int *)(in_ECX + 0xc) != 0)) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    uStack_4c = (void *)0x1;
    piStack_50 = (int *)0x85d0ac;
    FUN_008597d0();
    uStack_4c = (void *)0x7;
    piStack_50 = (int *)0x85d0bc;
    iVar1 = FUN_0085e3a0();
    uStack_4c = *(void **)(iVar1 + 0x20);
    piStack_50 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    pcStack_54 = (char *)0x85d0da;
    (**(code **)(*piStack_50 + 0x15c))();
    piStack_58 = *(int **)(iVar1 + 0x1c);
    pcStack_54 = s_Billboard_00a12fac;
    iStack_5c = 0x85d0eb;
    (**(code **)(*piStack_58 + 0xf0))();
    puStack_60 = (undefined4 *)0x85d0f3;
    iStack_5c = iVar1;
    FUN_0085bfe0();
    piStack_64 = *(int **)(iVar1 + 0x1c);
    iStack_5c = 0;
    puStack_60 = &uStack_4c;
    (**(code **)(*piStack_64 + 0x104))();
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x108))(*(int **)(iVar1 + 0x1c));
    if ((*(int *)(in_ECX + 0x24) != 0) || (*(int *)(in_ECX + 0xc) != 0)) {
      FUN_0085bb20(0);
      FUN_0085cb30(iVar1,in_ECX + 0x1c,0);
      FUN_0085cb30(iVar1,in_ECX + 4,1);
    }
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x110))(*(int **)(iVar1 + 0x1c));
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x114))(*(int **)(iVar1 + 0x1c));
    FUN_00859830(1);
    pcVar2 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
    if (*pcVar2 != '\0') {
      uStack_4c = (void *)0xf;
      piStack_50 = (int *)0x0;
      puStack_60 = (undefined4 *)((uint)puStack_60 & 0xffffff00);
      FUN_00401740(s__R_Sprite_Tri_add_count_00a12fbc,0x17);
      FUN_00401740(&DAT_00a12fb8,2);
      uVar3 = FUN_00404230((int)register0x00000010 + -0x48);
      (**(code **)(*DAT_00b5a688 + 8))(&piStack_64,uVar3);
      if (0xf < uStack_38) {
        _free(uStack_4c);
        return;
      }
      uStack_4c = (void *)((uint)uStack_4c & 0xffffff00);
      if ((char *)0xf < pcStack_54) {
        _free((void *)0x0);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0085d220 @ 0x0085d220 ====

void FUN_0085d220(void *param_1)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(in_ECX + 4) == 0) ||
     ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 0x65)) {
    FUN_00427520(0,0);
    FUN_0085dfd0(0,local_18,local_14,local_10,local_c,local_8,local_4);
    FUN_0085e550(&param_1);
  }
  else if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 0x14) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x14));
      return;
    }
    *(undefined4 *)((int)param_1 + 0x14) = 0;
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    if (*(void **)((int)param_1 + 4) == (void *)0x0) {
      *(undefined4 *)((int)param_1 + 4) = 0;
      *(undefined4 *)((int)param_1 + 8) = 0;
      *(undefined4 *)((int)param_1 + 0xc) = 0;
      _free(param_1);
      return;
    }
    _free(*(void **)((int)param_1 + 4));
    return;
  }
  return;
}


// ==== FUN_0085d2f0 @ 0x0085d2f0 ====

void FUN_0085d2f0(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  }
  uVar3 = 0;
  if (0 < iVar2) {
    do {
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 8) - iVar1 >> 2) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      iVar1 = *(int *)(iVar1 + uVar3 * 4);
      if ((*(int *)(iVar1 + 0x20) == 3) && (*(char *)(iVar1 + 0x28) == '\0')) {
        if (*(int *)(iVar1 + 0x24) == 0) {
          iVar4 = in_ECX + 0x1c;
        }
        else {
          iVar4 = in_ECX + 0x28;
        }
      }
      else if (*(int *)(iVar1 + 0x24) == 0) {
        iVar4 = in_ECX + 4;
      }
      else {
        iVar4 = in_ECX + 0x10;
      }
      FUN_0085ce70(iVar1,iVar4);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < iVar2);
  }
  return;
}


// ==== FUN_0085d380 @ 0x0085d380 ====

void FUN_0085d380(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *_Memory;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar5 = puVar3;
          if (puVar5 == puVar2) {
            _Memory = *(void **)(*(int *)(param_1 + 4) + 4);
            if (*(char *)((int)_Memory + 0x15) == '\0') {
              FUN_0085d660(*(undefined4 *)((int)_Memory + 8));
              _free(_Memory);
              return;
            }
            *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
            *(undefined4 *)(param_1 + 8) = 0;
            *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
            *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
            return;
          }
          FUN_0085d220(puVar5[4]);
          puVar3 = puVar5;
        } while (*(char *)((int)puVar5 + 0x15) != '\0');
        puVar3 = (undefined4 *)puVar5[2];
        if (*(char *)((int)puVar3 + 0x15) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar5 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      puVar3 = (undefined4 *)puVar5[1];
    } while (*(char *)((int)puVar3 + 0x15) != '\0');
    do {
      puVar4 = puVar3;
      puVar3 = puVar4;
      if (puVar5 != (undefined4 *)puVar4[2]) break;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar4;
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  } while( true );
}


// ==== FUN_0085d430 @ 0x0085d430 ====

void FUN_0085d430(void)

{
  int in_ECX;
  
  FUN_0085d380(in_ECX + 0x1c);
  FUN_0085d380(in_ECX + 0x28);
  FUN_0085d380(in_ECX + 4);
  FUN_0085d380(in_ECX + 0x10);
  return;
}


// ==== FUN_0085d460 @ 0x0085d460 ====

void FUN_0085d460(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_00a13008;
  FUN_0085d380(in_ECX + 7);
  FUN_0085d380(in_ECX + 10);
  FUN_0085d380(in_ECX + 1);
  FUN_0085d380(in_ECX + 4);
  _Memory = DAT_00b5d9a0;
  if (DAT_00b5d9a0 == (void *)0x0) {
    FUN_0085dd40(local_4,*(undefined4 *)in_ECX[0xb],(undefined4 *)in_ECX[0xb]);
    _free((void *)in_ECX[0xb]);
    return;
  }
  FUN_0085e500(DAT_00b5d9a0);
  DAT_00b5d9a0 = (void *)0x0;
  if (*(void **)((int)_Memory + 4) == (void *)0x0) {
    *(undefined4 *)((int)_Memory + 4) = 0;
    *(undefined4 *)((int)_Memory + 8) = 0;
    *(undefined4 *)((int)_Memory + 0xc) = 0;
    _free(_Memory);
    return;
  }
  _free(*(void **)((int)_Memory + 4));
  return;
}


// ==== FUN_0085d550 @ 0x0085d550 ====

void FUN_0085d550(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 6) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3[4] = param_1[4];
    param_3[5] = param_1[5];
    param_3 = param_3 + 6;
  }
  return;
}


// ==== FUN_0085d5a0 @ 0x0085d5a0 ====

void FUN_0085d5a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  while (param_1 != param_2) {
    param_3[-6] = param_2[-6];
    param_3[-5] = param_2[-5];
    param_3[-4] = param_2[-4];
    param_3[-3] = param_2[-3];
    param_3[-2] = param_2[-2];
    param_3[-1] = param_2[-1];
    param_2 = param_2 + -6;
    param_3 = param_3 + -6;
  }
  return;
}


// ==== FUN_0085d5f0 @ 0x0085d5f0 ====

int FUN_0085d5f0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a1a0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x18) {
    FUN_0057e010(param_3,param_1);
    param_3 = param_3 + 0x18;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0085d656 @ 0x0085d656 ====

void Catch_0085d656(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0085d660 @ 0x0085d660 ====

void FUN_0085d660(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0085d660(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0085d6a0 @ 0x0085d6a0 ====

void * FUN_0085d6a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a1b0;
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


// ==== Catch@0085d715 @ 0x0085d715 ====

void Catch_0085d715(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0085d730 @ 0x0085d730 ====

void FUN_0085d730(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a1c0;
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


// ==== Catch@0085d7ba @ 0x0085d7ba ====

void Catch_0085d7ba(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0085d7d0 @ 0x0085d7d0 ====

void FUN_0085d7d0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0099a1d0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_0057e010(param_1,param_3);
    param_1 = param_1 + 0x18;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0085d836 @ 0x0085d836 ====

void Catch_0085d836(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0085d840 @ 0x0085d840 ====

void FUN_0085d840(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0085d5f0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0085d860 @ 0x0085d860 ====

int FUN_0085d860(int param_1,int param_2,undefined4 param_3)

{
  FUN_0085d7d0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x18;
}


// ==== FUN_0085d890 @ 0x0085d890 ====

void FUN_0085d890(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_0085d6a0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0085d995:
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
      if ((char)piVar6[5] == '\0') goto LAB_0085d995;
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


// ==== FUN_0085da70 @ 0x0085da70 ====

void FUN_0085da70(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint extraout_ECX;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
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
  puStack_c = &LAB_0099a1e0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  local_50 = *param_3;
  local_4c = param_3[1];
  local_48 = param_3[2];
  local_44 = param_3[3];
  local_40 = param_3[4];
  local_3c = param_3[5];
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x18;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x5c);
    if (0xaaaaaaaU - iVar2 < param_2) {
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
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    if (local_20 < iVar2 + param_2) {
      if (0xaaaaaaa - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_0057dfd0();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x18;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_0085d840(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_0085d860(local_1c,param_2,&local_50);
      FUN_0085d840(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x18;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x18);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x18) < param_2) {
      local_24 = param_2 * 0x18;
      FUN_0085d5f0(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_0085d860(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x18,&local_50)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_004dcf10(param_1,*(int *)(in_ECX + 8) - local_24,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x18;
    uVar4 = FUN_0085d5f0(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_0085d5a0(param_1,local_2c,local_28,local_38);
    FUN_004dcf10(param_1,param_2 * 0x18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0085dc31 @ 0x0085dc31 ====

void Catch_0085dc31(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0085dd40 @ 0x0085dd40 ====

void FUN_0085dd40(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0085d660(piVar6[1]);
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


// ==== FUN_0085de00 @ 0x0085de00 ====

void FUN_0085de00(uint param_1)

{
  uint uVar1;
  void *pvVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0099a1f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0xaaaaaaa < param_1) {
    ExceptionList = &local_10;
    FUN_0085b3b0();
  }
  uVar1 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    uVar1 = (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 4)) / 0x18;
  }
  if (uVar1 < param_1) {
    pvVar2 = operator_new(param_1 * 0x18);
    local_8 = 0;
    FUN_0085d840(*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8),pvVar2);
    local_8 = 0xffffffff;
    if (*(void **)(in_ECX + 4) != (void *)0x0) {
      _free(*(void **)(in_ECX + 4));
      return;
    }
    *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x18 + (int)pvVar2);
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 4) = pvVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0085def4 @ 0x0085def4 ====

void Catch_0085def4(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0085df10 @ 0x0085df10 ====

void FUN_0085df10(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_0085d890(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0085d890(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0085dfd0 @ 0x0085dfd0 ====

void FUN_0085dfd0(uint param_1,undefined1 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
  }
  if (uVar2 < param_1) {
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x18;
    }
    FUN_0085da70(*(undefined4 *)(in_ECX + 8),param_1 - iVar3,&param_2);
    return;
  }
  if (((iVar3 != 0) && (iVar1 = *(int *)(in_ECX + 8), param_1 < (uint)((iVar1 - iVar3) / 0x18))) &&
     (iVar3 = iVar3 + param_1 * 0x18, iVar3 != iVar1)) {
    uVar4 = FUN_0085d550(iVar1,iVar1,iVar3,param_1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
  }
  return;
}


// ==== FUN_0085e080 @ 0x0085e080 ====

void FUN_0085e080(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x18 != 0) {
      iVar1 = (param_2 - iVar1) / 0x18;
      goto LAB_0085e0c5;
    }
  }
  iVar1 = 0;
LAB_0085e0c5:
  FUN_0085da70(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x18;
  return;
}


// ==== FUN_0085e0f0 @ 0x0085e0f0 ====

void FUN_0085e0f0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_0099a200;
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


// ==== Catch@0085e251 @ 0x0085e251 ====

void Catch_0085e251(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0085e340 @ 0x0085e340 ====

void FUN_0085e340(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  
  uVar2 = 0;
  if (param_2 != 0) {
    piVar3 = (int *)FUN_004af750();
    uVar2 = (**(code **)(*piVar3 + 4))();
  }
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x2c) - iVar1 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(in_ECX + 0x1c) + 0xd0))
            (*(int **)(in_ECX + 0x1c),*(undefined4 *)(iVar1 + param_1 * 4),uVar2);
  return;
}


// ==== FUN_0085e3a0 @ 0x0085e3a0 ====

int FUN_0085e3a0(uint param_1)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int extraout_EAX_00;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (0x16 < param_1) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_uiID_<___MAX___00a12ff4,0xe);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      iVar2 = (*pcVar1)();
      return iVar2;
    }
    _free(local_18);
    return extraout_EAX;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if ((iVar2 == 0) || ((uint)(*(int *)(in_ECX + 8) - iVar2 >> 2) <= param_1)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar2 = *(int *)(iVar2 + param_1 * 4);
  if (iVar2 != 0) {
    return iVar2;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_I_pFxShader_00a12fe6 + 2,9);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  _free(local_18);
  return extraout_EAX_00;
}


// ==== FUN_0085e470 @ 0x0085e470 ====

void FUN_0085e470(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x18) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x18))) {
    FUN_0085e080(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0085d7d0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x18;
  return;
}


// ==== FUN_0085e500 @ 0x0085e500 ====

void FUN_0085e500(int param_1)

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
      FUN_00860900(iVar2,*piVar1,param_1);
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


// ==== FUN_0085e550 @ 0x0085e550 ====

void FUN_0085e550(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_0085e0f0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_0085e5a0 @ 0x0085e5a0 ====

void FUN_0085e5a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0085d460();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0085e5c0 @ 0x0085e5c0 ====

void FUN_0085e5c0(void)

{
  return;
}


// ==== FUN_0085e5d0 @ 0x0085e5d0 ====

void FUN_0085e5d0(void)

{
  return;
}


// ==== FUN_0085e5e0 @ 0x0085e5e0 ====

void FUN_0085e5e0(float *param_1,float param_2)

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
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  pfVar1 = param_1 + 3;
  fVar15 = DAT_0099d0b4 - param_2 * DAT_0099d0b4;
  fVar2 = *pfVar1;
  fVar14 = param_2 * DAT_0099d0b4 + DAT_0099d0b4;
  fVar3 = *pfVar1;
  fVar4 = param_1[4];
  fVar5 = param_1[4];
  fVar6 = param_1[5];
  fVar7 = param_1[5];
  fVar8 = *param_1;
  fVar9 = *param_1;
  fVar10 = param_1[1];
  fVar11 = param_1[1];
  fVar12 = param_1[2];
  fVar13 = param_1[2];
  *param_1 = (param_1[9] - *param_1) * fVar15 + *param_1;
  param_1[1] = (param_1[10] - param_1[1]) * fVar15 + param_1[1];
  param_1[2] = (param_1[0xb] - param_1[2]) * fVar15 + param_1[2];
  *pfVar1 = (param_1[6] - param_1[3]) * fVar15 + *pfVar1;
  param_1[4] = (param_1[7] - param_1[4]) * fVar15 + param_1[4];
  param_1[5] = (param_1[8] - param_1[5]) * fVar15 + param_1[5];
  param_1[6] = (param_1[6] - fVar2) * fVar14 + fVar3;
  param_1[7] = (param_1[7] - fVar4) * fVar14 + fVar5;
  param_1[8] = (param_1[8] - fVar6) * fVar14 + fVar7;
  param_1[9] = (param_1[9] - fVar8) * fVar14 + fVar9;
  param_1[10] = (param_1[10] - fVar10) * fVar14 + fVar11;
  param_1[0xb] = (param_1[0xb] - fVar12) * fVar14 + fVar13;
  return;
}


// ==== FUN_0085e790 @ 0x0085e790 ====

void FUN_0085e790(int param_1)

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


// ==== FUN_0085e920 @ 0x0085e920 ====

undefined4 FUN_0085e920(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar3 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x18;
  }
  piVar1 = (int *)**(undefined4 **)(DAT_00b5ac04 + 0x34);
  iVar3 = iVar3 * 0x18;
  cVar2 = FUN_00881000(0x18,iVar3);
  if (cVar2 == '\0') {
    (**(code **)(*piVar1 + 0xc))();
  }
  cVar2 = FUN_00881000(0x18,iVar3);
  if (cVar2 == '\0') {
    return 0;
  }
  uVar4 = (**(code **)(*piVar1 + 0x1c))(0x18,iVar3);
  (**(code **)(*piVar1 + 0x14))(iVar3,*(undefined4 *)(param_1 + 4));
  FUN_00881060();
  piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
  (**(code **)(*piVar1 + 400))(piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x18)
  ;
  return uVar4;
}


// ==== FUN_0085e9e0 @ 0x0085e9e0 ====

undefined4 FUN_0085e9e0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 1;
  }
  iVar2 = iVar2 * 2;
  piVar1 = (int *)**(int **)(DAT_00b5ac04 + 0x34);
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    (**(code **)(*piVar1 + 0x10))();
  }
  if ((uint)piVar1[7] <= (uint)(piVar1[8] + iVar2)) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar1 + 0x20))(iVar2);
  iVar2 = *(int *)(param_1 + 0x14);
  if (iVar2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0x18) - iVar2 >> 1;
  }
  (**(code **)(*piVar1 + 0x18))(iVar4,iVar2);
  FUN_00881080();
  return uVar3;
}


// ==== FUN_0085eaa0 @ 0x0085eaa0 ====

void FUN_0085eaa0(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EDI;
  uint uVar5;
  
  uVar2 = FUN_0085e920(param_2);
  uVar3 = FUN_0085e9e0(param_2);
  if ((*(int *)(param_2 + 0x14) != 0) &&
     (2 < (uint)(*(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 1))) {
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 400))
              (piVar1,0,*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 4),0,0x18);
    FUN_0084b7f0(*(undefined4 *)(**(int **)(DAT_00b5ac04 + 0x34) + 0x18));
    (**(code **)(**(int **)(unaff_EDI + 0x1c) + 0x10c))(*(int **)(unaff_EDI + 0x1c));
    if (*(int *)(param_2 + 0x14) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 1;
    }
    if (*(int *)(param_2 + 4) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x18;
    }
    piVar1 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    (**(code **)(*piVar1 + 0x148))(piVar1,4,uVar2,0,iVar4,uVar3,uVar5 / 3);
  }
  return;
}


// ==== FUN_0085eb90 @ 0x0085eb90 ====

void FUN_0085eb90(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 0x48);
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x1f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x98))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x78),local_40);
  return;
}


// ==== FUN_0085ebf0 @ 0x0085ebf0 ====

void FUN_0085ebf0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x1f)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x98))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x78),local_40);
  return;
}


// ==== FUN_0085ec50 @ 0x0085ec50 ====

void FUN_0085ec50(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uStack_84;
  undefined4 *puStack_80;
  float fStack_7c;
  undefined4 local_68;
  float local_64;
  undefined1 auStack_60 [16];
  undefined4 auStack_50 [20];
  
  iVar1 = *(int *)(param_1 + 0x28);
  local_64 = DAT_0099d0dc / (*(float *)(DAT_00b5ac04 + 0xa8) * DAT_009b6df8);
  local_68 = *(undefined4 *)(DAT_00b5ac04 + 0x9c);
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x22)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uStack_84 = *(undefined4 *)(iVar1 + 0x84);
  fStack_7c = 2.8026e-45;
  puStack_80 = &local_68;
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))(*(int **)(param_1 + 0x1c));
  puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x78) + 200);
  puVar3 = auStack_50;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_00862b50(auStack_60 + -0xc);
  thunk_FUN_0079e43e(auStack_60,auStack_60 + -0xc,auStack_50);
  iVar1 = *(int *)(param_1 + 0x28);
  puStack_80 = (undefined4 *)local_68;
  fStack_7c = local_64;
  if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2) < 0x23)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  (**(code **)(**(int **)(param_1 + 0x1c) + 0x80))
            (*(int **)(param_1 + 0x1c),*(undefined4 *)(iVar1 + 0x88),&uStack_84,3);
  return;
}


// ==== FUN_0085ed70 @ 0x0085ed70 ====

void FUN_0085ed70(undefined4 *param_1,int param_2)

{
  float ***pppfVar1;
  float ****ppppfVar2;
  ushort *puVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  float *pfVar7;
  float ****ppppfVar8;
  ushort uVar9;
  float *pfVar10;
  float10 fVar11;
  float fVar12;
  float fVar13;
  float ****ppppfStack_12c;
  float *pfStack_128;
  float ****ppppfStack_124;
  float ****ppppfStack_120;
  undefined4 local_11c;
  float ****local_108;
  float ***local_104;
  float ****local_100;
  float ****local_fc;
  float ***local_f8;
  float ****local_f4;
  float local_f0;
  float fStack_ec;
  undefined4 uStack_e8;
  float ***local_e4;
  float local_e0;
  float fStack_dc;
  float ****local_d8;
  float ***local_d4;
  float ****local_d0;
  float local_cc;
  float ****local_c8;
  float ***local_c4;
  float ****local_c0;
  float ****local_bc;
  float ***local_b8;
  float ****local_b4;
  float ****local_b0;
  float ***local_ac;
  float ****local_a8;
  float ****local_a4;
  float ***local_a0;
  float ****local_9c;
  float ***local_98;
  float local_94;
  float ***local_90;
  float fStack_8c;
  float ****ppppfStack_88;
  float local_80 [13];
  float afStack_4c [19];
  
  local_94 = (float)param_1[4] * DAT_0099d0b4;
  local_e4 = (float ***)((float)param_1[5] * DAT_0099d0b4);
  local_98 = local_e4;
  local_cc = 0.0;
  if ((float)param_1[7] != 0.0) {
    local_11c = (float ****)param_1[7];
    ppppfStack_120 = (float ****)0x85edd7;
    fVar11 = (float10)FUN_0040d4d0();
    ppppfStack_120 = (float ****)param_1[7];
    local_98 = (float ***)(float)(fVar11 * (float10)(float)local_e4);
    ppppfStack_124 = (float ****)0x85edeb;
    fVar11 = (float10)FUN_0040d4c0();
    local_cc = (float)(fVar11 * (float10)(float)local_e4);
  }
  iVar4 = param_1[8];
  ppppfVar8 = (float ****)*param_1;
  pppfVar1 = (float ***)param_1[1];
  ppppfVar2 = (float ****)param_1[2];
  local_d8 = ppppfVar8;
  local_d4 = pppfVar1;
  local_d0 = ppppfVar2;
  if (iVar4 == 2) {
    local_c8 = (float ****)(((float)ppppfVar8 - (float)local_98) + local_cc);
    local_c4 = pppfVar1;
    local_c0 = (float ****)(((float)ppppfVar2 - local_cc) - (float)local_98);
    local_bc = (float ****)(((float)ppppfVar8 - (float)local_98) - local_cc);
    local_b8 = pppfVar1;
    local_b4 = (float ****)(((float)ppppfVar2 - local_cc) + (float)local_98);
    local_108 = (float ****)((float)ppppfVar8 + local_cc + (float)local_98);
    local_100 = (float ****)(((float)ppppfVar2 + local_cc) - (float)local_98);
    local_b0 = (float ****)(((float)ppppfVar8 + (float)local_98) - local_cc);
    local_ac = pppfVar1;
    local_a8 = (float ****)((float)ppppfVar2 + local_cc + (float)local_98);
    local_a4 = local_108;
    local_a0 = pppfVar1;
    local_9c = local_100;
    local_104 = pppfVar1;
  }
  else {
    if (iVar4 == 0) {
      iVar4 = *(int *)(*(int *)(DAT_00b5ac04 + 0x78) + 4);
      local_fc = *(float *****)(iVar4 + 0xc);
      local_f8 = *(float ****)(iVar4 + 0x10);
      local_f4 = *(float *****)(iVar4 + 0x14);
      local_108 = (float ****)((float)local_f4 - (float)ppppfVar2);
      ppppfStack_120 = (float ****)&local_108;
      local_104 = (float ***)0x0;
      local_100 = (float ****)((float)ppppfVar8 - (float)local_fc);
      ppppfStack_124 = (float ****)0x85ef93;
      local_11c = ppppfStack_120;
      thunk_FUN_0079e1ba();
      fVar12 = (float)local_108 * local_94;
      local_f8 = (float ***)((float)local_104 * local_94);
      fVar13 = (float)local_100 * local_94;
      local_fc = (float ****)(fVar12 + (float)local_d8);
      local_f4 = (float ****)(fVar13 + (float)local_d0);
      local_c8 = (float ****)(fVar12 + (float)local_d8);
      local_c4 = (float ***)(((float)local_f8 + (float)local_d4) - (float)local_e4);
      local_c0 = (float ****)(fVar13 + (float)local_d0);
      local_bc = (float ****)(fVar12 + (float)local_d8);
      local_b8 = (float ***)((float)local_f8 + (float)local_d4 + (float)local_e4);
      local_b4 = (float ****)(fVar13 + (float)local_d0);
      local_a8 = (float ****)((float)local_d0 - fVar13);
      local_ac = (float ***)(((float)local_d4 - (float)local_f8) + (float)local_e4);
      local_100 = (float ****)((float)local_d0 - fVar13);
      local_104 = (float ***)(((float)local_d4 - (float)local_f8) - (float)local_e4);
      local_108 = (float ****)((float)local_d8 - fVar12);
    }
    else {
      if (iVar4 != 1) goto LAB_0085f20d;
      local_c4 = (float ***)(((float)pppfVar1 - local_cc) - (float)local_98);
      local_ac = (float ***)((float)pppfVar1 + local_cc + (float)local_98);
      local_c8 = ppppfVar8;
      local_c0 = (float ****)(((float)ppppfVar2 - (float)local_98) + local_cc);
      local_a8 = (float ****)(((float)ppppfVar2 + (float)local_98) - local_cc);
      local_bc = ppppfVar8;
      local_b8 = (float ***)(((float)pppfVar1 - local_cc) + (float)local_98);
      local_b4 = (float ****)(((float)ppppfVar2 - (float)local_98) - local_cc);
      local_104 = (float ***)(((float)pppfVar1 + local_cc) - (float)local_98);
      local_100 = (float ****)((float)ppppfVar2 + local_cc + (float)local_98);
      local_108 = ppppfVar8;
    }
    local_b0 = local_108;
    local_a4 = local_108;
    local_a0 = local_104;
    local_9c = local_100;
    local_c8 = local_bc;
  }
LAB_0085f20d:
  if (param_1[8] == 3) {
    if (*(char *)(param_1 + 10) == '\0') {
      local_fc = local_d8;
      local_f4 = local_d0;
      local_f0 = DAT_0099d080;
      local_11c = (float ****)(*(int *)(DAT_00b5ac04 + 0x78) + 8);
      ppppfStack_120 = (float ****)&local_fc;
      ppppfStack_124 = &local_90;
      pfStack_128 = (float *)0x85f3a1;
      local_f8 = local_d4;
      thunk_FUN_0079ebf5();
      local_c8 = (float ****)(((float)local_90 - (float)local_98) + local_cc);
      local_bc = (float ****)(((float)local_90 - (float)local_98) - local_cc);
      local_c4 = (float ***)((fStack_8c - local_cc) - (float)local_98);
      local_b0 = (float ****)(((float)local_90 + (float)local_98) - local_cc);
      local_b8 = (float ***)((fStack_8c - local_cc) + (float)local_98);
      local_c0 = ppppfStack_88;
      local_b4 = ppppfStack_88;
      local_ac = (float ***)(fStack_8c + local_cc + (float)local_98);
      local_108 = (float ****)((float)local_90 + local_cc + (float)local_98);
      local_104 = (float ***)((fStack_8c + local_cc) - (float)local_98);
      local_a8 = ppppfStack_88;
      local_100 = ppppfStack_88;
      local_9c = ppppfStack_88;
      local_a4 = local_108;
      local_a0 = local_104;
    }
    else {
      pfStack_128 = afStack_4c + 3;
      ppppfStack_12c = (float ****)0x85f231;
      ppppfStack_124 = ppppfVar8;
      ppppfStack_120 = (float ****)pppfVar1;
      local_11c = ppppfVar2;
      thunk_FUN_0079f7f5();
      local_11c = (float ****)local_80;
      ppppfStack_120 = (float ****)(param_1 + 0xb);
      pfVar7 = afStack_4c + 3;
      pfVar10 = local_80;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar10 = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pfVar10 = pfVar10 + 1;
      }
      ppppfStack_124 = (float ****)(afStack_4c + 3);
      pfStack_128 = (float *)0x85f25f;
      thunk_FUN_0079ee7b();
      pfStack_128 = &fStack_8c;
      ppppfStack_12c = (float ****)&local_108;
      pfVar7 = afStack_4c;
      pfVar10 = &fStack_8c;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar10 = *pfVar7;
        pfVar7 = pfVar7 + 1;
        pfVar10 = pfVar10 + 1;
      }
      local_108 = (float ****)(0.0 - local_f0);
      local_104 = (float ***)0x0;
      local_100 = local_108;
      local_d8 = local_108;
      thunk_FUN_0079e5a0(&local_d4);
      pppfVar1 = local_e4;
      thunk_FUN_0079e5a0(&local_d4,(int)register0x00000010 + -0x114,&local_98);
      ppppfStack_120 = local_108;
      local_11c = (float ****)0x0;
      thunk_FUN_0079e5a0(&local_d4,&ppppfStack_120,&local_a4);
      ppppfStack_12c = (float ****)pppfVar1;
      pfStack_128 = (float *)0x0;
      ppppfStack_124 = local_fc;
      thunk_FUN_0079e5a0(&local_d4,&ppppfStack_12c,&local_b0);
    }
  }
  else if (*(char *)(param_1 + 10) != '\0') {
    iVar4 = 4;
    ppppfVar8 = (float ****)&local_c8;
    while( true ) {
      local_108 = (float ****)((float)*ppppfVar8 - (float)local_d8);
      local_104 = (float ***)((float)ppppfVar8[1] - (float)local_d4);
      local_100 = (float ****)((float)ppppfVar8[2] - (float)local_d0);
      *ppppfVar8 = (float ***)local_108;
      ppppfVar8[1] = local_104;
      ppppfVar8[2] = (float ***)local_100;
      pfStack_128 = (float *)0x85f52e;
      ppppfStack_124 = ppppfVar8;
      ppppfStack_120 = ppppfVar8;
      local_11c = (float ****)(param_1 + 0xb);
      thunk_FUN_0079e5a0();
      local_fc = (float ****)((float)*ppppfVar8 + (float)local_d8);
      local_f8 = (float ***)((float)local_d4 + (float)ppppfVar8[1]);
      *ppppfVar8 = (float ***)((float)*ppppfVar8 + (float)local_d8);
      local_f4 = (float ****)((float)local_d0 + (float)ppppfVar8[2]);
      ppppfVar8[1] = (float ***)((float)local_d4 + (float)ppppfVar8[1]);
      iVar4 = iVar4 + -1;
      ppppfVar8[2] = (float ***)((float)local_d0 + (float)ppppfVar8[2]);
      if (iVar4 == 0) break;
      ppppfVar8 = ppppfVar8 + 3;
    }
  }
  if ((local_94 != (float)local_e4) && (param_1[8] != 0)) {
    local_11c = (float ****)(local_94 / (float)local_e4);
    ppppfStack_120 = (float ****)&local_c8;
    ppppfStack_124 = (float ****)0x85f5b8;
    FUN_0085e5e0();
  }
  if (*(int *)(param_2 + 4) == 0) {
    sVar5 = 0;
  }
  else {
    sVar5 = (short)((*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x18);
  }
  uStack_e8 = param_1[6];
  local_e0 = 0.0;
  local_f8 = local_c4;
  fStack_dc = DAT_0099d080;
  local_f4 = local_c0;
  local_fc = local_c8;
  local_11c = (float ****)&local_fc;
  fStack_ec = DAT_0099d080;
  local_f0 = 0.0;
  ppppfStack_120 = (float ****)0x85f632;
  FUN_0085e470();
  local_f8 = local_b8;
  fStack_dc = 0.0;
  local_f4 = local_b4;
  local_fc = local_bc;
  local_e0 = 0.0;
  local_11c = (float ****)&local_fc;
  fStack_ec = 0.0;
  local_f0 = 0.0;
  ppppfStack_120 = (float ****)0x85f675;
  FUN_0085e470();
  local_e0 = DAT_0099d080;
  local_f8 = local_ac;
  fStack_dc = 0.0;
  local_f4 = local_a8;
  local_fc = local_b0;
  local_11c = (float ****)&local_fc;
  fStack_ec = 0.0;
  local_f0 = DAT_0099d080;
  ppppfStack_120 = (float ****)0x85f6c0;
  FUN_0085e470();
  local_f8 = local_a0;
  fStack_dc = DAT_0099d080;
  local_f4 = local_9c;
  local_fc = local_a4;
  local_e0 = DAT_0099d080;
  local_11c = (float ****)&local_fc;
  fStack_ec = DAT_0099d080;
  local_f0 = DAT_0099d080;
  ppppfStack_120 = (float ****)0x85f708;
  FUN_0085e470();
  local_fc = (float ****)0x10000;
  local_f8 = (float ***)0x2;
  uVar6 = 0;
  local_f4 = (float ****)0x30002;
  local_f0 = 1.83675e-40;
  fStack_ec = 1.83671e-40;
  uStack_e8 = 1;
  do {
    iVar4 = *(int *)(param_2 + 0x14);
    uVar9 = *(short *)((int)local_80 + uVar6 * 2 + -0x7c) + sVar5;
    local_e0 = (float)(uint)uVar9;
    if ((iVar4 == 0) ||
       ((uint)(*(int *)(param_2 + 0x1c) - iVar4 >> 1) <=
        (uint)(*(int *)(param_2 + 0x18) - iVar4 >> 1))) {
      ppppfStack_124 = *(float *****)(param_2 + 0x18);
      local_11c = (float ****)&local_e0;
      ppppfStack_120 = (float ****)0x1;
      pfStack_128 = (float *)0x85f7a9;
      FUN_00427290();
    }
    else {
      puVar3 = *(ushort **)(param_2 + 0x18);
      *puVar3 = uVar9;
      *(ushort **)(param_2 + 0x18) = puVar3 + 1;
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 6);
  return;
}


// ==== FUN_0085f7c0 @ 0x0085f7c0 ====

void FUN_0085f7c0(undefined4 param_1,int param_2,char param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int *piVar11;
  int iVar12;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  int local_8;
  uint local_4;
  
  if (param_3 == '\0') {
    FUN_0085eb90(param_1);
  }
  else {
    FUN_0085ebf0(param_1);
  }
  puVar2 = *(undefined4 **)(param_2 + 4);
  puVar3 = (undefined4 *)*puVar2;
  _param_3 = 0;
  do {
    if (puVar3 == puVar2) {
      return;
    }
    iVar12 = puVar3[3];
    iVar4 = puVar3[4];
    if (_param_3 != iVar12) {
      iVar5 = *(int *)(*(int *)(DAT_00b5ac04 + 0x2c) + 4);
      if ((iVar5 == 0) || ((uint)(*(int *)(*(int *)(DAT_00b5ac04 + 0x2c) + 8) - iVar5 >> 2) < 8)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      iVar5 = *(int *)(iVar5 + 0x1c);
      if (iVar5 == 0) {
        local_4 = 0xf;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        local_8 = iVar5;
        FUN_00401740(s_I_pFxShader_00a12fe6 + 2,9);
        FUN_00406880(local_1c);
        if (local_4 < 0x10) {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          pcVar8 = (code *)swi(3);
          (*pcVar8)();
          return;
        }
        _free(local_18);
        return;
      }
      uVar10 = 0;
      if (iVar12 != 0) {
        piVar11 = (int *)FUN_004af750();
        uVar10 = (**(code **)(*piVar11 + 4))();
      }
      iVar6 = *(int *)(iVar5 + 0x28);
      if ((iVar6 == 0) || ((uint)(*(int *)(iVar5 + 0x2c) - iVar6 >> 2) < 0x21)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      (**(code **)(**(int **)(iVar5 + 0x1c) + 0xd0))
                (*(int **)(iVar5 + 0x1c),*(undefined4 *)(iVar6 + 0x80),uVar10);
      _param_3 = iVar12;
    }
    FUN_0085eaa0(param_1,iVar4);
    if (*(int *)(iVar4 + 0x14) == 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = *(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 0x14) >> 1;
    }
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + iVar12;
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar7 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar7 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar7 + 0x15);
        puVar3 = puVar7;
        puVar7 = (undefined4 *)*puVar7;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x15);
          puVar3 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar9 = (undefined4 *)puVar3[1];
        puVar7 = puVar3;
        while ((puVar3 = puVar9, cVar1 == '\0' && (puVar7 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar9 = (undefined4 *)puVar3[1];
          puVar7 = puVar3;
        }
      }
    }
  } while( true );
}


// ==== FUN_0085f9a0 @ 0x0085f9a0 ====

void FUN_0085f9a0(void)

{
  int in_ECX;
  
  FUN_0085e500();
  DAT_00b5d9a4 = 0;
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0085f9e0 @ 0x0085f9e0 ====

void * FUN_0085f9e0(void)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  int iVar3;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar1 = *(int *)(in_ECX + 8);
    iVar3 = iVar1 - *(int *)(in_ECX + 4) >> 2;
    if (iVar3 != 0) {
      pvVar2 = *(void **)(iVar1 + -4);
      if (iVar3 != 0) {
        *(int *)(in_ECX + 8) = iVar1 + -4;
      }
      return pvVar2;
    }
  }
  pvVar2 = operator_new(0x20);
  if (pvVar2 == (void *)0x0) {
    return (void *)0x0;
  }
  *(undefined4 *)((int)pvVar2 + 4) = 0;
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  *(undefined4 *)((int)pvVar2 + 0x14) = 0;
  *(undefined4 *)((int)pvVar2 + 0x18) = 0;
  *(undefined4 *)((int)pvVar2 + 0x1c) = 0;
  FUN_0085de00(0x80);
  FUN_004271c0(0x100);
  return pvVar2;
}


// ==== FUN_0085fa50 @ 0x0085fa50 ====

undefined4 * FUN_0085fa50(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined4 *puVar3;
  int iVar4;
  
  *in_ECX = &PTR_FUN_00a130b4;
  puVar3 = in_ECX + 1;
  iVar4 = 2;
  do {
    iVar1 = FUN_008602b0();
    puVar3[1] = iVar1;
    *(undefined1 *)(iVar1 + 0x15) = 1;
    *(undefined4 *)(puVar3[1] + 4) = puVar3[1];
    *(undefined4 *)puVar3[1] = puVar3[1];
    *(undefined4 *)(puVar3[1] + 8) = puVar3[1];
    puVar3[2] = 0;
    puVar3 = puVar3 + 3;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar3 = in_ECX + 7;
  iVar4 = 2;
  do {
    iVar1 = FUN_008602b0();
    puVar3[1] = iVar1;
    *(undefined1 *)(iVar1 + 0x15) = 1;
    *(undefined4 *)(puVar3[1] + 4) = puVar3[1];
    *(undefined4 *)puVar3[1] = puVar3[1];
    *(undefined4 *)(puVar3[1] + 8) = puVar3[1];
    puVar3[2] = 0;
    puVar3 = puVar3 + 3;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (DAT_00b5d9a4 == (void *)0x0) {
    pvVar2 = operator_new(0x10);
    if (pvVar2 != (void *)0x0) {
      *(undefined4 *)((int)pvVar2 + 4) = 0;
      *(undefined4 *)((int)pvVar2 + 8) = 0;
      *(undefined4 *)((int)pvVar2 + 0xc) = 0;
      DAT_00b5d9a4 = pvVar2;
    }
  }
  return in_ECX;
}


// ==== FUN_0085fb00 @ 0x0085fb00 ====

void FUN_0085fb00(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  iVar1 = param_2;
  FUN_0079bba0(&param_2,(undefined4 *)(param_1 + 0xc));
  if (param_2 == *(int *)(iVar1 + 4)) {
    uVar2 = FUN_0085f9e0();
    local_10 = *(undefined4 *)(param_1 + 0xc);
    local_c = uVar2;
    FUN_008605f0(local_8,&local_10);
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0x10);
  }
  FUN_0085ed70(param_1,uVar2);
  return;
}


// ==== FUN_0085fb70 @ 0x0085fb70 ====

void FUN_0085fb70(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piStack_64;
  undefined4 *puStack_60;
  int iStack_5c;
  int *piStack_58;
  char *pcStack_54;
  int *piStack_50;
  undefined4 uStack_4c;
  uint uStack_38;
  
  if ((*(int *)(in_ECX + 0x30) != 0) || (*(int *)(in_ECX + 0x18) != 0)) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    uStack_4c = (void *)0x0;
    piStack_50 = (int *)0x85fb9b;
    FUN_008597d0();
    uStack_4c = (void *)0x7;
    piStack_50 = (int *)0x85fbab;
    iVar1 = FUN_0085e3a0();
    uStack_4c = *(void **)(iVar1 + 0x20);
    piStack_50 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    pcStack_54 = (char *)0x85fbc9;
    (**(code **)(*piStack_50 + 0x15c))();
    piStack_58 = *(int **)(iVar1 + 0x1c);
    pcStack_54 = s_Billboard_00a13058;
    iStack_5c = 0x85fbda;
    (**(code **)(*piStack_58 + 0xf0))();
    puStack_60 = (undefined4 *)0x85fbe2;
    iStack_5c = iVar1;
    FUN_0085ec50();
    piStack_64 = *(int **)(iVar1 + 0x1c);
    iStack_5c = 0;
    puStack_60 = &uStack_4c;
    (**(code **)(*piStack_64 + 0x104))();
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x108))(*(int **)(iVar1 + 0x1c));
    if ((*(int *)(in_ECX + 0x30) != 0) || (*(int *)(in_ECX + 0x18) != 0)) {
      FUN_0085e790(1);
      FUN_0085f7c0(iVar1,in_ECX + 0x28,0);
      FUN_0085f7c0(iVar1,in_ECX + 0x10,1);
    }
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x110))(*(int **)(iVar1 + 0x1c));
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x114))(*(int **)(iVar1 + 0x1c));
    FUN_00859830(0);
    pcVar2 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
    if (*pcVar2 != '\0') {
      uStack_4c = (void *)0xf;
      piStack_50 = (int *)0x0;
      puStack_60 = (undefined4 *)((uint)puStack_60 & 0xffffff00);
      FUN_00401740(s__R_Sprite_count_00a13068,0xf);
      FUN_00401740(&DAT_00a13064,2);
      uVar3 = FUN_00404230((int)register0x00000010 + -0x48);
      (**(code **)(*DAT_00b5a688 + 8))(&piStack_64,uVar3);
      if (0xf < uStack_38) {
        _free(uStack_4c);
        return;
      }
      uStack_4c = (void *)((uint)uStack_4c & 0xffffff00);
      if ((char *)0xf < pcStack_54) {
        _free((void *)0x0);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0085fd10 @ 0x0085fd10 ====

void FUN_0085fd10(void)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piStack_64;
  undefined4 *puStack_60;
  int iStack_5c;
  int *piStack_58;
  char *pcStack_54;
  int *piStack_50;
  undefined4 uStack_4c;
  uint uStack_38;
  
  if ((*(int *)(in_ECX + 0x24) != 0) || (*(int *)(in_ECX + 0xc) != 0)) {
    *(undefined4 *)(in_ECX + 0x34) = 0;
    uStack_4c = (void *)0x1;
    piStack_50 = (int *)0x85fd3c;
    FUN_008597d0();
    uStack_4c = (void *)0x7;
    piStack_50 = (int *)0x85fd4c;
    iVar1 = FUN_0085e3a0();
    uStack_4c = *(void **)(iVar1 + 0x20);
    piStack_50 = *(int **)(*(int *)(DAT_00b5ac04 + 0x28) + 0x90);
    pcStack_54 = (char *)0x85fd6a;
    (**(code **)(*piStack_50 + 0x15c))();
    piStack_58 = *(int **)(iVar1 + 0x1c);
    pcStack_54 = s_Billboard_00a13078;
    iStack_5c = 0x85fd7b;
    (**(code **)(*piStack_58 + 0xf0))();
    puStack_60 = (undefined4 *)0x85fd83;
    iStack_5c = iVar1;
    FUN_0085ec50();
    piStack_64 = *(int **)(iVar1 + 0x1c);
    iStack_5c = 0;
    puStack_60 = &uStack_4c;
    (**(code **)(*piStack_64 + 0x104))();
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x108))(*(int **)(iVar1 + 0x1c));
    if ((*(int *)(in_ECX + 0x24) != 0) || (*(int *)(in_ECX + 0xc) != 0)) {
      FUN_0085e790(0);
      FUN_0085f7c0(iVar1,in_ECX + 0x1c,0);
      FUN_0085f7c0(iVar1,in_ECX + 4,1);
    }
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x110))(*(int **)(iVar1 + 0x1c));
    (**(code **)(**(int **)(iVar1 + 0x1c) + 0x114))(*(int **)(iVar1 + 0x1c));
    FUN_00859830(1);
    pcVar2 = (char *)(**(code **)(*DAT_00b5ac00 + 8))();
    if (*pcVar2 != '\0') {
      uStack_4c = (void *)0xf;
      piStack_50 = (int *)0x0;
      puStack_60 = (undefined4 *)((uint)puStack_60 & 0xffffff00);
      FUN_00401740(s__R_Sprite_add_count_00a13088,0x13);
      FUN_00401740(&DAT_00a13084,2);
      uVar3 = FUN_00404230((int)register0x00000010 + -0x48);
      (**(code **)(*DAT_00b5a688 + 8))(&piStack_64,uVar3);
      if (0xf < uStack_38) {
        _free(uStack_4c);
        return;
      }
      uStack_4c = (void *)((uint)uStack_4c & 0xffffff00);
      if ((char *)0xf < pcStack_54) {
        _free((void *)0x0);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0085feb0 @ 0x0085feb0 ====

void FUN_0085feb0(void *param_1)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(in_ECX + 4) == 0) ||
     ((uint)(*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2) < 0x65)) {
    FUN_00427520(0,0);
    FUN_0085dfd0(0,local_18,local_14,local_10,local_c,local_8,local_4);
    FUN_00860970(&param_1);
  }
  else if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 0x14) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x14));
      return;
    }
    *(undefined4 *)((int)param_1 + 0x14) = 0;
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = 0;
    if (*(void **)((int)param_1 + 4) == (void *)0x0) {
      *(undefined4 *)((int)param_1 + 4) = 0;
      *(undefined4 *)((int)param_1 + 8) = 0;
      *(undefined4 *)((int)param_1 + 0xc) = 0;
      _free(param_1);
      return;
    }
    _free(*(void **)((int)param_1 + 4));
    return;
  }
  return;
}


// ==== FUN_0085ff80 @ 0x0085ff80 ====

void FUN_0085ff80(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  }
  uVar3 = 0;
  if (0 < iVar2) {
    do {
      iVar1 = *(int *)(param_1 + 4);
      if ((iVar1 == 0) || ((uint)(*(int *)(param_1 + 8) - iVar1 >> 2) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      iVar1 = *(int *)(iVar1 + uVar3 * 4);
      if ((*(int *)(iVar1 + 0x20) == 3) && (*(char *)(iVar1 + 0x28) == '\0')) {
        if (*(int *)(iVar1 + 0x24) == 0) {
          iVar4 = in_ECX + 0x1c;
        }
        else {
          iVar4 = in_ECX + 0x28;
        }
      }
      else if (*(int *)(iVar1 + 0x24) == 0) {
        iVar4 = in_ECX + 4;
      }
      else {
        iVar4 = in_ECX + 0x10;
      }
      FUN_0085fb00(iVar1,iVar4);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < iVar2);
  }
  return;
}


